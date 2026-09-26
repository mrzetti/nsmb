---
name: NSMB ARM matching
description: Matching techniques for mwccarm on Nintendo DS ARM9/ARM946E/ARMv5T, covering ABI, codegen idioms, and the source-level constructs that produce each instruction pattern. Load before forming a hypothesis about a target instruction.
---

# ARM / mwccarm matching for NSMB

This skill is about **ARM9 / ARM946E / ARMv5T with Metrowerks CodeWarrior `mwccarm`**. It
is not PowerPC material and not GameCube/Wii material. If a reference you read is about
PowerPC codegen, register conventions, or the GameCube/Wii Metrowerks ABI, it does not
transfer - the ABIs are different.

## Verify the current flags before assuming

`build.zig` is the source of truth. Read the `BuildMWCC.make` argv:

```
wine ./build/compiler/mwccarm/1.2/sp3/mwccarm.exe <src> -o <out>
  -O4,p -interworking -proc=arm946e -lang=C++ -Cpp_exceptions=off
  -w=off -gccinc -nolink -c -sym=on -RTTI=off -once
  -i lib/Nitro/ -d VER_A2DE
```

These, and what each one changes about codegen:

| Flag | Matching consequence |
| --- | --- |
| `-O4,p` | aggressive inlining; small helpers disappear; locals get coalesced |
| `-interworking` | ARM and Thumb coexist; `BL`/`BLX` may cross modes; the callee's mode is independent of the caller's |
| `-proc=arm946e` | ARMv5T base; no NEON on ARM9; 4K/16K caches |
| `-RTTI=off` | no vtables for RTTI, no typeinfo; `dynamic_cast` will not match |
| `-Cpp_exceptions=off` | no unwind tables; `throw` will not match |
| `-gccinc` | GCC-style include search; that is why `lib/Nitro/` works |
| `-sym=on` | symbols emitted, so objdiff can name functions |
| `-lang=C++` | C++ semantics: name mangling, overloading, implicit conversions |

`-O4,p` is the flag to reason from most. It is why a function that "should" need a callee
does not, and why two identical-looking source expressions can compile differently.

## The ABI

**Argument and result registers.** `r0`-`r3` carry the first four words of arguments; a
fifth and beyond go on the stack. Return value in `r0`, with `r1` for a second word
(64-bit results, or a struct returned in registers).

Consequences for matching:

- A function reading `r0`-`r3` before its first branch takes up to four arguments.
- Changing a parameter from a pointer to a reference usually does *not* change the
  registers, but does change how the callee dereferences and how null checks appear.
- `const T&` and `T&` take the same register. A `const` difference shows up in
  dereference type, not in calling convention.

**Register classes.**

| Register | Role |
| --- | --- |
| `r0`-`r3` | arguments, and `r0` the return value |
| `r4`-`r11` | callee-saved: must be pushed if used |
| `r12` (IP) | intra-procedure scratch, used freely around calls |
| `r13` (SP) | stack pointer |
| `r14` (LR) | return address |
| `r15` (PC) | program counter; reads are PC-relative |

The push/pop register list is a **direct read of the register allocation**. A function that
pushes `r4, r5, r6, lr` needs three callee-saved registers, which means three values
survive a call. If your source produces only two, something is being kept in a temporary
that the original kept in a register - or vice versa.

## Instruction patterns and their source

Work from the target column of the objdiff diff. These are the patterns that come up
constantly in this codebase.

### Loads and stores

| Target instruction | Usual source cause |
| --- | --- |
| `LDRB r1, [r0, #0x20]` | field is `u8` or `bool` |
| `LDRSB r1, [r0, #0x20]` | field is **signed** 8-bit (`s8`) |
| `LDRH` / `LDRSH` | 16-bit field, signed or not |
| `LDR r1, [r0, #0x10]` | 32-bit field |
| `STRB r0, [r1, #n]` | byte store: `bool`/flag writeback |
| `CMP r1, #0x0` + `BEQ` | `if (byteField)` where the field is tested against zero |
| `CMP r1, #0x1` | the source compared against `1`, e.g. `if (x == 1)` |

A `CMP #0` on a byte field almost always means the source is `if (flag)` with `flag` a
`bool`/`u8`, **not** `if (flag == true)`. mwccarm tests the raw byte.

### Shifts

Shifts in operand position come from the source, not the optimiser:

| Target instruction | Usual source cause |
| --- | --- |
| `AND r2, r2, r3, LSL #0x10` | `x = (a & 0x1ff) \| (b << 16)` - a shift written in the source |
| `ORR r0, r0, r1, LSL #16` | `a \| (b << 16)` |
| `MOV r0, r1, LSL #2` | `x * 4`, or `x << 2` |
| `ASR #2` | signed division by 4, or `>> 2` on a signed value |
| `LSL #1` | `x * 2` or `x << 1` |
| `RSB` + shift | negation |

A scaled-index addressing mode (`[r1, r2, LSL #2]`) is the compiler's array indexing for a
4-byte element type. Element size 1 or 2 gives no shift or a `#1`. **This is a direct
readout of the element type.**

### Arithmetic and its traps

- `ADD r0, r0, #1` after a `LDRB`: a `u8` increment.
- `SUB` on a pointer: pointer arithmetic, not index arithmetic.
- `RSB r0, r1, #0`: unary negation.
- `MUL` / `MLA`: multiplication written inline. If the target calls a helper instead, the
  source used a wider or differently-typed multiply, or the optimiser chose differently.
- A division in ARMv5T is **not** a single instruction. `SDIV`/`UDIV` are ARMv7+. On
  ARM946E a division is a call to a runtime helper, so a division in the target appears as
  a `BL` to an unresolved symbol, and the divide-by-power-of-two form must be a shift in
  the source. If you see a `BL` in a matching candidate, check whether the source has an
  actual `/` or `%`.

### Branches and control flow

- `BEQ`/`BNE` from `CMP`: a normal `if`.
- `B` to a literal pool then `LDMFD pc, {..., pc}`: a **switch jump table**. The target of
  the `LDR pc` is the table. In source, that is a `switch` with a dense integer range.
- A `switch` over sparse values becomes a compare chain, not a table. So *table vs compare
  chain* is a direct observation about your `switch`.
- `BEQ` skipping one instruction = an early `return` in a short function.
- A branch that skips a `MOV r0, #0` = `return false` / a zero-initialised return.

Branch *ordering* is a real signal: the first branch in the target is the first condition
in the source. If your branches are in a different order, the diff will show it.

### Literals and constants

- `LDR r1, [pc, #0xcc] (->0x1b0)` - a PC-relative load from the literal pool at `0x1b0`.
  For a game this is usually a **hardware register address** (a `REG_*` macro) or a
  constant. The pool entry's value disambiguates.
- `MOVW`/`MOVT` pairs: a 32-bit constant being materialised, typical for a large magic
  value or a pointer.
- Pool *placement* follows from the code around it, so pool position mismatches are
  usually a symptom, not the cause. Fix the code first.

### Stack frames

- `STMFD sp!, {r4-r6, lr}` - the prologue. The register list is the allocation.
- `ADD sp, sp, #0x10` / `SUB sp, sp, #0x10` - a frame. Size tells you about locals and any
  struct return area.
- A frame size that is not a multiple of 4, or an odd `ADD sp, sp, #r` with a register
  offset, is characteristic of mwccarm's argument/return area handling. A function
  returning a struct by value frequently shows this.
- `LDMFD sp!, {..., pc}` - the epilogue; also the tail of a `switch` table dispatch.

### Calls and interworking

- `BL addr` - direct call.
- `BLX r0` - indirect call through a register (virtual dispatch, or a function pointer).
- `BX lr` - return.
- `BX r3` where `r3` had bit 0 set - tail call into Thumb.
- With `-interworking`, the low bit of a `BL`/`BLX` target distinguishes the callee's mode.
  Never assume a function's mode from its neighbours.

## ARM versus Thumb

Both are in this binary. Differences that matter when reading a target:

| | ARM | Thumb |
| --- | --- | --- |
| instruction width | 4 bytes | 2 bytes |
| literal/PC loads | `LDR rN, [pc, #imm]` | separate literal pool semantics |
| branch range | full 32-bit | limited, via `B.W`/`BL` |
| conditional execution | all instructions | most, via IT block |
| multiply | `MUL`/`MLA` | `MULS` only |

If your diff shows a size mismatch near zero, suspect a mode or width difference rather than
a logic difference.

## Source-level constructs that decide codegen

The mapping from C++ to these instructions is not one-to-one. These are the constructs that
most often account for an objdiff mismatch:

**Types**
- signed vs unsigned on the same width changes `LDR`/`LDRSB`, `ASR`/`LSR`, and comparisons
- `u8`/`s16`/`s32`/`fx16` widths are visible in every load and in the compare
- `bool` is byte-sized and tested against `0`
- enum width follows its underlying type; a `u8` enum loads a byte
- `const` on a pointee changes nothing in the load; `volatile` adds ordering

**Expression shape**
- `a && b` short-circuits and produces a test of a combined value; two `if`s produce two
  branches. If the target has one branch where you have two, look for `&&`/`||`.
- `x |= y` and `x = x | y` usually compile identically, but can differ in when the old
  value is re-read. Test both.
- `a++` vs `++a` differ only in what the expression yields; in a discarded context they are
  usually the same. Check whether the value is used.
- `while (x)` and `for (; x;)` are the same loop; the difference is only in whether an
  initialiser exists.
- Ternary vs `if`/`else` assignment: the ternary may produce a conditional move or a branch.
  Check for `MOV` + conditional branch vs a single `AND`/`ORR` chain.
- A bare `return;` vs `return expr;` vs falling off the end: different `r0` writes.

**Declarations and lifetime**
- Declaration order of locals affects stack slot order, which affects the frame and the
  push/pop order.
- Reusing one variable instead of two changes whether a register must be spilled across a
  call.
- Introducing a named temporary where the original inlined an expression can change
  register pressure. `-O4,p` may coalesce them again, so test both directions.

**Control flow**
- `switch` with a dense range -> jump table; sparse -> compare chain
- the order of `case` labels is the order of the chain
- early `return` vs wrapping the body in `if` - different branch shapes
- `do`/`while` vs `while`: check the initial test

**Structures**
- Struct layout: field order, width, and alignment all change offsets. `NITRO_SIZE_ASSERT`
  in `src/base_types.hpp` is the in-repo way to check a size against a known-good value.
- A member access through a base pointer vs a copied struct changes load counts.
- Array indexing vs pointer arithmetic: often identical output. If your diff shows a
  difference, the element type or the bounds handling is what differs.

## Method

1. Read the target column for the function. Not the diff markers - the instructions.
2. Name the pattern. "Two `LDRB` on offsets differing by 1, then `CMP #0`, `BEQ`" is a
   two-element byte-flag test.
3. Map it to a construct using the tables above.
4. Check the headers for the field's declared type. If the declared type does not produce
   that instruction, the header is what needs changing, not the function body.
5. Check a matched neighbour for the project's idiom.
6. Change **one** thing, rebuild that one unit, re-diff.
7. Keep or revert on the measured number.

If step 3 gives two equally plausible constructs, pick the one consistent with the matched
neighbour, and test the other if the first does not move the percentage.

## Sources worth consulting

- **This repository's already-matched functions.** The single most reliable reference, and
  it is guaranteed consistent with the toolchain. When a 100% function uses a struct with
  `u8` flags, that is the idiom to copy.
- **The compiler flags in `build.zig`.** Never reason from a flag you have not read.
- **The target binary via objdiff.** The only ground truth.
- **Other legitimate ARM/mwcc decomp projects.** Useful for general CodeWarrior idiom.
  Ensure the architecture and compiler actually match before transferring anything; PPC
  decomp knowledge does not transfer to ARM9.

Do **not** use NitroSDK sources or knowledge. See `contributing.md`; work that relied on it
gets rejected.
