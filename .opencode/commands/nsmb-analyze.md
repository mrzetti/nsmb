---
description: Analyse an NSMB symbol - objdiff target disassembly plus Ghidra context - and report a matching-oriented brief.
argument-hint: SYMBOL
---

# /nsmb-analyze SYMBOL

Build a focused, actionable brief for one symbol. Evidence only; **make no source edits**.

Load the skills `nsmb-project`, `nsmb-objdiff`, and `nsmb-arm-matching`. Add
`nsmb-ghidra` if the Ghidra MCP server is connected.

## 1. Resolve the symbol to a unit and a mangled name

objdiff keys functions by **mangled** name, so the demangled form the user typed will be
rejected. Convert it, then confirm it exists:

```js
const units = await tools.objdiff.list_units({ filter: "<hint>" });
return units;
```

- Itanium ABI mangling: `_ZN` + length-prefixed components, `_` for `::`, `$` for `.`.
- `echo _ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE | c++filt` demangles.
- Get the exact mangled name from `diff_overview` if the conversion is uncertain.

If the symbol is not found, say so and show the closest candidates. Do not guess a unit.

## 2. Establish the current state

```js
const o = await tools.objdiff.diff_overview({ unit: "<unit>", only_mismatches: true, limit: 25 });
return o;
```

Note the unit's position in the worst-first ordering, and whether neighbours are already
matched. A symbol next to several 100% functions has strong local idiom to copy.

If a base object already exists, get the exact number:

```js
const d = await tools.objdiff.diff_function({ symbol: "<mangled>", unit: "<unit>" });
return d;
```

If `mwccarm` is absent no base object exists. Say that plainly and continue with target-side
analysis, which is still useful.

## 3. Read the target disassembly - the specification

From the `diff_function` output, take the **target** column as the specification.

- `match` is the current percentage. Record it exactly.
- `legend`: `' '` equal, `~` replace, `o` opcode mismatch, `a` argument mismatch,
  `+` insert, `-` delete.

Read the whole function, not only the mismatch rows: a diff hides what already matches, and
you need the full shape to reason about the function.

Classify each part:

- **prologue/epilogue** - the push/pop register list is a direct read of register allocation
- **argument reads** - which of `r0`-`r3` are touched before the first branch constrains the
  signature
- **branches** - the first branch is the first condition in the source; order is a real signal
- **loads/stores** - `LDRB` vs `LDR` vs `LDRSB` is the field's width and signedness
- **shifts** - a shift in an operand came from the source text
- **literal pool loads** - a constant, a string, or a hardware register address
- **calls** - direct `BL`, indirect `BLX`, a tail-call thunk, or an unresolved runtime helper
  (on ARMv5T, division and some maths are calls, not instructions)
- **stack frame size** - locals, and any struct return area

State explicitly whether the function is **ARM or Thumb**. With `-interworking` this varies
per function and cannot be inferred from neighbours.

## 4. ARM/MWCC interpretation

Apply the `nsmb-arm-matching` skill. Name the patterns rather than describing them
loosely. "Two `LDRB` reads at consecutive offsets, each followed by `CMP #0` and `BEQ`" is
useful; "some byte checks" is not.

Where a construct could have two plausible source forms, say what each would predict and
which is more likely. That is what lets the matcher choose.

## 5. Semantic context from Ghidra - when it helps

Reach for Ghidra when objdiff leaves a question open. Not every analysis needs it.

- **argument count and types** - pseudocode, or a caller's use of the function
- **struct layout** - field offsets and widths, and how they are used across functions
- **callers and callees** - especially an unresolved callee, which is often a runtime helper
- **globals** - a `LDR [pc, ...]` into a literal; identify whether it is a `REG_*` hardware
  register already named in `src/`
- **switch/jump tables** - a `LDR pc, [pc, ...]` is a table; find the table and read the
  case range
- **neighbouring functions** - often a variant, and can settle a signature immediately

If the Ghidra MCP is unavailable, do not pretend to have used it. Continue from objdiff, the
headers, and `config/<release>/arm9/*/{symbols,delinks}.txt`, and note what stayed unknown.

## 6. Cross-check the source

Read the current implementation and its headers:

- the field types in `src/**/*.hpp`
- whether a neighbouring matched function uses the same idiom
- `tools/Ghidra/nsmb.h` for the Ghidra-side struct shapes
- `src/base_types.hpp` for the type vocabulary

Point out any **conflict between what the target does and what the declared type allows**.
That is often the actual bug, and it means the header needs the change rather than the
function body.

## 7. Report

Keep it tight. This is a brief for someone about to edit code, not a tutorial.

```
symbol        : _ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE
demangled     : System::uploadSubBGState(System::VBlankBGInfo&)
unit          : src/system/vblank
source        : src/system/vblank.cpp
mode          : ARM (confirmed by 4-byte LDR pc-relative literal loads)
current match : 63.20%   (0.00% if no base object exists yet)

signature     : void f(VBlankBGInfo&) - r0 used as a struct base pointer
                 (r0-r2 read before the first branch; no stack args)
control flow  : 4 sequential `if (dirty[n])` blocks, n = 0..3
                 each block: set BG offset register, then clear the flag
loads         : [r0,#0x20] ldrb  -> dirty[] is byte-sized
                 [r0,#0x00] ldr   -> vtable (not dereferenced in this function)
                 [r0,#0x10] ldr   -> x[]/y[] words
                 [pc,#..]  ldr   -> REG_BG0OFS_SUB etc.
callers       : System::subEngineVBlankHandler
callees       : leaf
globals       : REG_BG0OFS_SUB, REG_BG1OFS_SUB, REG_BG2OFS_SUB, REG_BG3OFS_SUB
types         : VBlankBGInfo { unknown_vtable* vtable; s32 x[4]; s32 y[4]; u8 dirty[4]; }

observations
  1. `cmp r1,#0x0` on a byte load => the source tests a byte flag against 0.
     Current source compares against 1: this is a real mismatch, not noise.
  2. The 0x1ff / <<16 masking is done as two separate loads and an
     `and r2, r2, r3, lsl #0x10`, i.e. the register is assigned once from a
     combined value rather than built up in two statements.
  3. No callee-saved registers are pushed => the function is a leaf and needs no
     frame. If the current source spills anything, that is a divergence.

next useful actions (ordered)
  1. Change the dirty-flag test from `== true` to a plain truth test on a u8 field.
  2. Assign the BG offset register once from a combined expression.
  3. Only then re-diff; expect the flag tests to clear before anything else moves.

unknowns
  - whether `x`/`y` are fx16 packed or two s32 arrays: load width suggests s32,
    but no scaling shift is present, which argues against fx16.
```

End with unknowns stated as unknowns. Do not pad the report to look thorough, and do not
propose a specific edit beyond naming the likely hypotheses - the matcher makes the change.
