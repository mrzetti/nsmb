# AGENTS.md - NSMB matching decompilation

Guidance for OpenCode in this repository. Read `contributing.md` for the project's own
rules; this file adds the operational context.

## What this project is

**Matching decompilation of New Super Mario Bros. for Nintendo DS.** Not GameCube, not Wii,
not PowerPC.

| | |
| --- | --- |
| Target | ARM9, **ARM946E**, **ARMv5T**, little-endian |
| Language | C++ |
| Compiler | Metrowerks CodeWarrior `mwccarm` **1.2sp3** (2.0/sp2p4 for Y7QJ) |
| Compiler host | **Wine** on Linux |
| Build | Zig build, Zig **0.16.x** |
| Config/delink | **dsd 0.12.x** |
| Oracle | **objdiff** |
| Full ROM build | **not possible** - matching individual functions is the goal |

Re-read `build.zig` rather than trusting this table.

Actual compiler invocation (`BuildMWCC.make` in `build.zig`):

```
wine ./build/compiler/mwccarm/1.2/sp3/mwccarm.exe <src> -o <out>
  -O4,p -interworking -proc=arm946e -lang=C++ -Cpp_exceptions=off
  -w=off -gccinc -nolink -c -sym=on -RTTI=off -once -i lib/Nitro/ -d VER_A2DE
```

## The one rule that matters most

**objdiff's match percentage is the only measure of progress.** Target object
(`build/A2DE/delinks/<unit>.o`) vs base object (`build/A2DE/<unit>.o`).

Ghidra pseudocode is **evidence, not ground truth**. A tidy decompilation that compiles to
different instructions is a failure. Never claim a match you have not read out of objdiff.

## Build commands

```sh
# Setup (once, after a fresh clone or release change)
./.opencode/bin/limited-build zig build extract     # needs the ROM
./.opencode/bin/limited-build zig build delink
./.opencode/bin/limited-build zig build objdiff     # writes the gitignored objdiff.json

# The normal loop: compile ONE unit, not the project.
# The argument is the unit's base_path from objdiff.json, NOT the unit name.
# Let resolve-unit construct the command for you:
./.opencode/bin/resolve-unit src/system/vblank command
# ...which prints, and which you then run:
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o
```

**Never run a bare `zig build`.** This host runs other services; Zig defaults to all cores.
Always go through `./.opencode/bin/limited-build`, or use the objdiff MCP `build` tool,
which is CPU-capped by construction. See `./.opencode/bin/build-info`.

The `zig build single` argument is the objdiff unit's **`base_path`, verbatim** - dsd writes
those as long relative paths like
`config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o`.

Passing the unit *name* (`src/system/vblank`) makes `build.zig` panic with
`Could not find the source`, because `getSourceByDest()` compares the argument against
`base_path` exactly. Use `./.opencode/bin/resolve-unit <name> command` to produce the
command. The objdiff MCP `build` tool does not have this hazard: it reads `base_path`
straight out of `objdiff.json`.

`objdiff.json` is generated and gitignored. A fresh checkout has none.

## objdiff facts worth memorising

- objdiff wants **mangled** symbols (`_ZN6System16uploadSubBGStateERNS_12VBlankBGInfoE`).
  The demangled form is rejected.
- 689 units, 353 with a `base_path`. `_dsd_gap@main_NN` units are dsd stubs with no source
  and are not matchable.
- `metadata.complete` is a flag, not a percentage. Ignore it.
- The diff legend: `' '` equal, `~` replace, `o` opcode mismatch, `a` argument mismatch,
  `+` insert, `-` delete.

## Workflow

```
symbol -> unit + source file -> baseline % -> read target disassembly
  -> ONE hypothesis -> ONE edit -> rebuild that ONE unit -> diff again
  -> keep or revert -> record the number -> repeat
  -> after 5 non-improving attempts: reassess, do not keep guessing
  -> independent review -> a human decides
```

Work one hypothesis per attempt. A number is the only honest record of progress.

## Architecture notes that affect matching

- **ARM and Thumb coexist** because of `-interworking`. A function's mode is independent of
  its neighbours. Never infer it.
- `r0`-`r3` carry arguments; `r4`-`r11` are callee-saved. **The push/pop register list is a
  direct read of register allocation.**
- `LDRB` vs `LDR` vs `LDRSB` on a field is its width and signedness. `CMP #0` after a byte
  load means the source tests a byte flag against zero, not against `1`.
- A shift in an operand position (`AND r2, r2, r3, LSL #16`) came from the source text.
- Scaled-index addressing (`[r1, r2, LSL #2]`) reads out the array element size.
- On ARMv5T there is **no `SDIV`/`UDIV`**; a division is a call to a runtime helper. A `BL`
  in the target is often division, `memcpy`, or `sqrt`.
- `LDR pc, [pc, ...]` is a switch jump table.
- `LDR rN, [pc, #imm]` loads from the literal pool - usually a constant, a string, or a
  hardware register address.
- `-RTTI=off -Cpp_exceptions=off`: a `throw` or `dynamic_cast` will never match.
- `-O4,p` inlines aggressively, so small helpers vanish into their callers.

## Type conventions

`src/base_types.hpp`: `u8`/`s8`, `u16`/`s16`, `u32`/`s32`, `u64`/`s64`, `fx16` (16.16 in
32 bits), `fx32`, `vu*` volatile variants, and `NITRO_SIZE_ASSERT` for compile-time struct
size checks. `tools/Ghidra/nsmb.h` mirrors this vocabulary for Ghidra.

## Rules

- **NitroSDK prohibition.** `contributing.md`: work that relied on the NitroSDK will be
  rejected. Do not use NitroSDK sources or knowledge that could only come from them. Derive
  from this repository, the target binary, and observable compiler behaviour. `lib/Nitro/`
  is the project's own shim and is fine.
- **Never commit** ROMs, `.nds` files, extracted data, delinked objects, `build/` output, or
  the proprietary `mwccarm` binaries. `.gitignore` covers all of it - **do not weaken it**.
- **Never download** a ROM or `mwccarm`. Those are the user's to supply. Report them as
  missing prerequisites and do everything else.
- **Delivery: allowed to the fork, gated at upstream.** Committing, pushing, and opening
  PRs on `origin` (`mrzetti/nsmb`) are authorised. A PR against `upstream`
  (`NSMB-Decomp/nsmb`) is the public contribution gate and needs explicit per-PR
  instruction.
- **Never** `git push upstream`, force-push, `git push --all`/`--mirror`, `git reset --hard`,
  `git clean -fd`, `git checkout --`, `git restore`, or `git branch -D`, and never delete
  unrelated in-progress work. Ship with `git add` / `git commit` / `git push origin` on a
  **feature branch**.
- Preserve the best source with `./.opencode/bin/decomp-state`, which snapshots on every
  improvement. It uses file copies, not destructive git.

## Local tooling

Everything is vendored under `.tools/` and gitignored. `AGENTS.md` documents intent;
`DECOMP_AI.md` documents the AI setup in detail.

| Helper | Purpose |
| --- | --- |
| `./.opencode/bin/limited-build` | the only supported way to build; injects `-j`, applies the CPU cap |
| `./.opencode/bin/resolve-unit` | unit name -> `base_path` / source / target / ready-to-run build command |
| `./.opencode/bin/build-info` | show the live CPU policy; `--selftest` proves enforcement |
| `./.opencode/bin/decomp-state` | track per-symbol progress, snapshot and restore the best source |
| `./.opencode/bin/objdiff-mcp` | start the objdiff MCP server inside a CPU-capped cgroup |
| `./.opencode/bin/ghidra-mcp` | start headless Ghidra + its MCP bridge (optional) |
| `./.opencode/bin/build-ghidra-runtime` | rebuild the Ghidra runtime with uv (optional) |
| `./.opencode/bin/selftest` | verify the whole setup end to end |
| `./.opencode/bin/decomp-env` | resolve and print the resource policy |

## Commands

`/nsmb-setup` · `/nsmb-analyze SYMBOL` · `/nsmb-match SYMBOL` · `/nsmb-review SYMBOL` ·
`/nsmb-status`

## Agents

`nsmb-orchestrator` (default, coordinates) → `nsmb-binary-analyst` (read-only RE) →
`nsmb-matcher` (edits + builds) → `nsmb-reviewer` (independent verification).

## Skills

`nsmb-project` · `nsmb-arm-matching` · `nsmb-objdiff` · `nsmb-build` · `nsmb-ghidra` ·
`nsmb-contribution`

## Conventions for changes to decompilation source

- One unit, one file, one function per change.
- Keep the file's existing style and idiom. Matched neighbours are the reference.
- No reformatting, no renames, no reordered declarations, no drive-by cleanups.
- The project uses a tab indent (see `.clang-format` and `.editorconfig`).
- Report the measured delta. The existing commit convention is:
  `decomp: match <symbol> (report +N, OLD->NEW)`.
