---
description: Inspect the NSMB workspace and report exactly what is present, missing, and blocked.
---

# /nsmb-setup

Determine the current, exact state of this NSMB matching workspace. Report facts, not
optimism. **Download nothing proprietary** - if a ROM or `mwccarm` is missing, that is the
finding.

Work through the checks in order and report each as OK / MISSING / BLOCKED.

## 1. Repository

```sh
git -C . rev-parse --short HEAD
git -C . status --short
git -C . remote -v
```

Confirm this is an NSMB checkout and note the fork remote.

## 2. Release detection

`build.zig` resolves the release as `-DRelease`, else `$NSMB_RELEASE`, else `A2DE`. The
release determines every path. Check which is in effect, and confirm `config/<release>/`
exists.

Only `A2DE` has real progress; the other releases in `readme.md` are near-empty. If the
detected release is not `A2DE`, say so plainly, because it changes what objdiff.json
contains and what the baseline even is.

## 3. Zig

```sh
./.tools/zig-0.16.0/zig version
```

`contributing.md` requires **0.16.x**. This `build.zig` uses the Zig 0.16 `std.Build` /
`std.Io` API, so an older or newer Zig will fail to parse it. A version mismatch is a hard
stop for building, and `zig build --help` failing is the symptom.

## 4. dsd

```sh
./.tools/dsd --version
```

`contributing.md` requires **0.12.x** (0.12.0 documented; 0.12.1 current). dsd performs
`extract`, `delink`, and `objdiff`.

## 5. Wine

```sh
wine --version
```

Required because `build.zig` prepends `wine` to the `mwccarm` invocation on non-Windows
hosts. Not proprietary, so installing it is in scope - but do not change global Wine
configuration. The one recommended change is `wineserver -p` for a persistent wineserver,
which `contributing.md` suggests for compile speed.

## 6. mwccarm presence - report presence only, never contents

The expected path, from `Release.compilerPath()` in `build.zig`:

```
build/compiler/mwccarm/1.2/sp3/mwccarm.exe     # all releases except Y7QJ
build/compiler/mwccarm/2.0/sp2p4/mwccarm.exe   # Y7QJ only
```

Check existence and report present or missing. **Do not read, copy, list in detail, or
otherwise expose the compiler files.** Do not search for or download it. This is a
proprietary binary the user supplies.

## 7. ROM presence - existence only

Expected: `<release>.nds` in the repository root, e.g. `A2DE.nds`.

```sh
ls -la *.nds 2>/dev/null
```

If present, confirm `.gitignore` still covers it:

```sh
git check-ignore -v A2DE.nds
```

Read only the 12-byte title and 4-byte game code from the header to confirm the release
matches. **Do not dump, extract, upload, or transmit the ROM.** Do not download one. If it
is missing, say so - the user supplies it.

## 8. Generated data

```sh
ls -d extracted/<release>/ 2>/dev/null   # zig build extract output
ls -d build/<release>/delinks/ 2>/dev/null # zig build delink output
ls objdiff.json 2>/dev/null              # zig build objdiff output
```

`objdiff.json` is generated and gitignored, so it is absent on a fresh clone. If it is
missing, report that the objdiff MCP can list nothing and must be regenerated before
matching.

## 9. objdiff stable CLI

```sh
./.tools/objdiff-stable/objdiff-cli --version
```

This is what `zig build report` uses. It must stay separate from the experimental MCP build.

## 10. objdiff experimental MCP (PR #400)

```sh
./.tools/objdiff-mcp/objdiff-cli --version
./.tools/objdiff-mcp/objdiff-cli mcp --help
```

Confirm the `mcp` subcommand exists. Record the pinned commit SHA and the build date; both
are in `DECOMP_AI.md`. **Re-verify the pin against the upstream PR head if in doubt** - the
PR may have moved, and an unpinned moving branch must not be used in production.

Then actually test the server, do not just check the binary exists:

```sh
./.opencode/bin/objdiff-mcp --project . # must speak MCP on stdio
```

Verify via `opencode mcp list` and, if `objdiff.json` exists, that `list_units` returns
units.

## 11. Ghidra and Ghidra MCP

```sh
ls -d .tools/ghidra* 2>/dev/null
java -version 2>&1 | head -1
mvn -version 2>&1 | head -1
```

Ghidra is optional. Report it as a clearly-scoped prerequisite gap: Ghidra 12.0.4 (the
version the MCP plugin pins), Java 21, Maven, and the Ghidra JARs in `~/.m2`. State plainly
that matching works without it, and that Ghidra is for semantic context only.

## 12. Test the CPU-limited build path

```sh
./.opencode/bin/build-info
./.opencode/bin/build-info --selftest
```

This must show the resolved policy, the enforcement mechanism, and - with `--selftest` - an
actual measurement that the cap slows a workload. Report:

- logical CPUs
- `DECOMP_BUILD_JOBS`
- `DECOMP_CPU_QUOTA`
- nice level
- mechanism (cgroup v2 quota / taskset / off)
- whether enforcement is actually active, not merely configured

If enforcement is not active, that is a finding. Do not report the policy as enforced when
it is only configured.

## 13. Proprietary-data boundary

```sh
git check-ignore -v A2DE.nds extracted build objdiff.json .tools .decomp-ai
git status --short
```

Confirm nothing proprietary is tracked and `.gitignore` was not weakened. `git diff
.gitignore` should show only additive entries for `.tools/` and `.decomp-ai/`.

## 14. OpenCode configuration

```sh
opencode mcp list
```

Confirm the agents, skills, and commands are all discovered, and that `objdiff` connects.

## Report format

A status table, then a short list of what is blocked and what it unblocks. End with the
single next command the user should run.

Be explicit about the difference between **missing** and **broken**. A missing
`mwccarm` means matching cannot be measured yet; a broken Zig means nothing works at all.
