---
name: NSMB objdiff
description: Use the objdiff MCP server (encounter/objdiff PR #400) as the matching oracle for NSMB - open_project, list_units, build, diff_function, diff_overview, and how to read the diff output. Load when measuring match percentage or choosing what to work on.
---

# objdiff: the matching oracle

objdiff is the only authority on whether a function matches. It compares the **target
object** (what the ROM shipped, produced by `zig build delink`) against the **base object**
(what our source compiles to). Ghidra can be wrong; objdiff's instruction comparison cannot.

## Which binary is which

Two separate installs, deliberately kept apart:

| Path | What | Used by |
| --- | --- | --- |
| `.tools/objdiff-stable/objdiff-cli` | official stable **v3.8.1** | `zig build report` |
| `.tools/objdiff-mcp/objdiff-cli` | experimental **PR #400** build | the `objdiff` MCP server |

Do not overwrite the stable CLI with the experimental build. `build.zig` calls a bare
`objdiff-cli` for the `report` step, and a half-finished experimental build would silently
break reporting.

The experimental build is pinned to a reviewed PR head, not a moving branch. See
`DECOMP_AI.md` for the exact SHA and the date it was verified.

## The server

Configured in `opencode.jsonc` as a **local stdio** server. It is not exposed on any port.

The command is a wrapper, not the raw binary:

```sh
./.opencode/bin/objdiff-mcp --project .
```

The wrapper moves the server process into a cgroup v2 CPU-quota cgroup before it accepts
any request. Every `build()` it starts (zig, wine, wineserver, mwccarm) inherits the cap.
That is why an MCP-triggered build cannot bypass the CPU policy - and it is also why the
wrapper must not be replaced by a direct `objdiff-cli mcp` invocation.

Under Code Mode, the tools live in the `objdiff` namespace:

```js
await tools.objdiff.diff_function({ symbol: "...", unit: "..." })
```

## The nine tools

| Tool | Required args | Optional | Use for |
| --- | --- | --- | --- |
| `version` | - | - | confirm which binary is answering |
| `open_project` | `dir` | - | load an `objdiff.json` explicitly |
| `list_units` | - | `filter` | enumerate units; the `filter` is a substring match |
| `build` | `unit` | `target` (bool, default false) | compile that unit's base object |
| `diff_function` | `symbol` | `unit` or `target`+`base`, `config` | **the main tool** |
| `diff_overview` | `unit` or `target`+`base` | `only_mismatches`, `limit`, `config` | rank functions worst-first |
| `list_symbol_mappings` | `unit` | - | manual target=base symbol pairs |
| `set_symbol_mapping` | `unit` | `target_symbol`, `base_symbol` | pair/clear a symbol |
| `set_config` | `key`, `value` | - | persistent diff/disassembly config |

`open_project` takes **`dir`**, not `path`. The project is also auto-opened at startup from
`--project`, so you usually do not need to call it - but it is useful after switching
releases.

`build` with `target: true` builds the *target* side. You almost always want the default
`false`, which builds the base object from our source.

## Symbols are mangled

This is the single most common failure. objdiff keys functions by **mangled** name:

```js
// rejected
await tools.objdiff.diff_function({ symbol: "System::uploadSubBGState", unit: "src/system/vblank" })
// -> "Symbol `System::uploadSubBGState` not found in base (current) or target object"

// accepted
await tools.objdiff.diff_function({
  symbol: "_ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE",
  unit: "src/system/vblank"
})
```

Get the mangled name from `diff_overview`, or demangle with
`echo _ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE | c++filt`. The mangling is Itanium
ABI: `_ZN` + length-prefixed name components, with `_` standing in for `::` and `$` for
`.`.

## The main loop

```js
// 1. Which units exist, and which one holds the symbol?
const units = await tools.objdiff.list_units({ filter: "vblank" });

// 2. Compile just that unit. The MCP server is inside a CPU-quota cgroup, so this
//    is already resource limited.
await tools.objdiff.build({ unit: "src/system/vblank" });

// 3. The measurement.
const d = await tools.objdiff.diff_function({
  symbol: "_ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE",
  unit: "src/system/vblank"
});
return d;
```

Outside MCP, the equivalent is:

```sh
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- <base_path>
```

**The argument is the unit's `base_path`, not the unit name.** `build.zig` compares it for
exact equality, and dsd writes those as long relative paths, so
`-- src/system/vblank` panics with `Could not find the source`. Let the resolver write the
command:

```sh
./.opencode/bin/resolve-unit src/system/vblank command
```

Both routes produce the same object. Never use a bare `zig build`.

## Reading the output

```
symbol : _ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE
demangled: System::uploadSubBGState(System::VBlankBGInfo&)
match  : 63.20%
legend : ' '=equal ~=replace o=opcode-mismatch a=arg-mismatch +=insert -=delete

  addr         target (expected)                       current (yours)
  000000cc     ldrb r1, [r0, #0x20]                    ldrb r1, [r0, #0x20]
  000000d0     cmp r1, #0x0                            cmp r1, #0x1
  000000d4     beq 0x104                               beq 0x100
```

- `match` is the percentage. **This number is the progress metric.** Nothing else counts.
- `target (expected)` is fixed. `current (yours)` is what your source produced.
- The `legend` markers: `o` means the same position holds a different opcode; `a` means the
  opcode is right but an argument is wrong; `+` is an extra instruction in your build; `-`
  is one you are missing. `~` is the general "replace" case.

Read the target column as the specification. A `cmp r1, #0x0` against your `#0x1` is
telling you the field is a byte-sized flag tested for zero, i.e. `bool`/`u8` compared
against `0`, not a boolean tested against `1`.

Because the output is a *diff*, it hides the parts that already match. When you need the
whole function rather than the mismatch, that is what Ghidra is for.

## Choosing what to work on

```js
const o = await tools.objdiff.diff_overview({
  unit: "src/system/vblank",
  only_mismatches: true,
  limit: 20
});
return o;
```

Worst match first, so the first entries are where the work is. `limit` keeps the response
small. Use this to pick a target and to check for regressions after a change - a
neighbouring function that dropped is as important as the one you were improving.

### Expect `$a` and `$d` rows at 0.00%

`diff_overview` on an ARM9 object also lists **assembler data directives** from the
data/rodata sections, not just functions:

```
    0.00%       0  $a
    0.00%       0  $d
```

`$a` is a data-region directive and `$d` a data pool entry. They are **not functions** and
cannot be matched, and because they sort worst-first they will bury the real functions at
the top of the list. Filter them out:

```js
const o = await tools.objdiff.diff_overview({ unit: "src/system/vblank", only_mismatches: true, limit: 40 });
const real = String(o).split("\n").filter(l => !/\s\$[ad]\s*$/.test(l));
return real.slice(0, 15).join("\n");
```

The same applies when you scan for work: filter the `$a`/`$d` rows before deciding what to
match, or you will waste an attempt trying to match a jump table.

## Diffing explicit paths

`diff_function` and `diff_overview` also accept `target` and `base` file paths instead of
a `unit`. Useful for:

- diffing a target object against a copy of itself to sanity-check the tooling (should be
  100%)
- diffing two arbitrary objects while diagnosing
- working when `objdiff.json` does not exist yet

```js
const d = await tools.objdiff.diff_function({
  symbol: "_ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE",
  target: "build/A2DE/delinks/src/system/vblank.o",
  base:   "build/A2DE/src/system/vblank.o"
});
```

## Code Mode: keep the response small

objdiff responses are large. Filter inside `execute` and return only what you need, or you
will spend the whole context budget on a disassembly you only partly read.

```js
// Just the headline numbers for a unit.
const o = await tools.objdiff.diff_overview({ unit: "src/system/vblank", only_mismatches: true, limit: 10 });
return typeof o === "string" ? o.slice(0, 2000) : o;
```

Useful filters:

- Pass `limit` to `diff_overview` - always.
- `only_mismatches: true` to skip functions already at 100%.
- Return a slice, or map to just the lines containing a mismatch marker.
- Never return a full `list_units` dump; pass `filter` or slice it.

Combine independent calls in one `execute` with `Promise.all` to save round trips:

```js
const [units, ov] = await Promise.all([
  tools.objdiff.list_units({ filter: "system" }),
  tools.objdiff.diff_overview({ unit: "src/system/vblank", only_mismatches: true, limit: 5 })
]);
return { units: String(units).slice(0, 800), overview: ov };
```

## Config

Prefer the **per-call `config` object** on `diff_function` / `diff_overview`. It is scoped
to one call, needs no cleanup, and is schema-validated - a bad key fails loudly with the
offending field named, instead of silently doing nothing:

```js
const d = await tools.objdiff.diff_function({
  symbol: "_ZN6System15sleepGameThreadEv",
  unit: "src/system/vblank",
  config: { demangler: "none" }
});
```

### `set_config` is not the way to change a diff

`set_config(key, value)` is per-server-process state that does not survive a restart, and
in this build (objdiff-cli 3.8.1 + PR #400) its accepted key set is **much narrower than it
looks**. Measured, not assumed - every one of these is rejected with
`Unknown config property`:

```
strip_diffs  ignore_symbols  algorithm  demangler
autoDemangle  show_addresses  no_addresses  synthData
```

An earlier revision of this skill listed `strip_diffs`, `ignore_symbols` and `algorithm` as
`set_config` examples. All three are rejected. Do not cite them.

`demangler` is a valid key for the **per-call** `config` but not for `set_config`, and even
per-call it does not change how a *literal pool operand* is rendered or scored - see below.
Reach for `set_config` only when you have confirmed the key works by calling it, and probe
with a throwaway name first, because it throws on an unknown key and will abort a
surrounding loop:

```js
// it throws, so isolate each probe
const settled = await Promise.allSettled(
  ["key1", "key2"].map(k => tools.objdiff.set_config({ key: k, value: "0" }))
);
```

### How the percentage is actually computed

Useful when deciding whether a mismatch is worth chasing. objdiff credits an arg-mismatch
**0.95** of a full match, not 0. Verified against six functions in `src/system/vblank`,
which all fit exactly:

| diff items | arg-mismatches | computed | objdiff reports |
| --- | --- | --- | --- |
| 5 | 1 | (4 + 0.95) / 5 = 99.00% | 99.00% |
| 5 | 2 | (3 + 1.90) / 5 = 98.00% | 98.00% |
| 4 | 1 | (3 + 0.95) / 4 = 98.75% | 98.75% |

So the percentage is a function of the **item count** and the mismatch count, not of
instruction bytes. A function with one wrong literal in five items is 99%, and no amount of
source work changes that if the literal's operand is not source-addressable. Count the
items before estimating what a fix is worth.

### Literal-pool operands are compared as raw name strings

This is the single most misleading thing about reading an ARM9 diff. objdiff compares the
**raw ELF symbol name string** on each side of a `.word` literal; it does not resolve
symbol identity, and no display option changes that. Proof, from one unit:

```
target: .word Nitro::_MultiThread::Sleep
base  : .word _ZN5Nitro12_MultiThread5SleepEP11ThreadQueue        marked 'a'
```

Same function, same ROM address, otherwise byte-identical - still a mismatch, because one
side is a readable name and the other is mangled. `demangler: "none"` per-call changes
neither the rendering nor the score.

This matters enormously when the target came from `dsd delink`. If the ROM's bss was never
delinked, dsd synthesises labels like `data_020859b8` from raw addresses, and **no source
change can make mwccarm emit that name**. Expect a hard ceiling, and do not burn attempts
on it. The only mechanical route is `set_symbol_mapping` / an `objdiff.json`
`symbol_mappings` entry - which is project configuration, not a match, and belongs to the
maintainers rather than to a matching session.

## Prerequisites and troubleshooting

The MCP server starts and `list_units` works as soon as `objdiff.json` exists. To *build*
you additionally need:

1. `zig` (vendored at `.tools/zig-0.16.0/zig`)
2. `dsd` (vendored at `.tools/dsd`)
3. Wine (`apt-get install -y wine wine64`)
4. **`mwccarm` 1.2sp3** at `build/compiler/mwccarm/1.2/sp3/mwccarm.exe`

Item 4 is proprietary. The user supplies it. Never download it. Without it, `build` fails
and `diff_function` can only compare objects that already exist - which still works for
reading the target side, and is enough for analysis but not for measuring a change.

If `build` fails with a missing compiler, that is a prerequisite gap, not a bug. Report it.

Check status with:

```sh
./.opencode/bin/build-info
```
