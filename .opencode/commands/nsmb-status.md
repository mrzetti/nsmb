---
description: Show concise NSMB matching status - release, MCP, Ghidra, CPU policy, and the current symbol's baseline, current, best, and last hypothesis.
---

# /nsmb-status

One screen. No preamble, no advice unless something is actually wrong.

## 1. Release and toolchain

```sh
./.opencode/bin/decomp-env print
```

Report the detected release. If it is not `A2DE`, flag it - only `A2DE` has real progress,
so any baseline or objdiff.json belongs to a different (near-empty) set of units.

## 2. Build CPU policy

```sh
./.opencode/bin/build-info
```

Report, exactly:

```
NSMB release:      A2DE
logical CPUs:      8
build jobs (-j):   2
CPU quota:         200%  (cpu.max 200000 100000)
nice:              10
enforcement:       cgroup v2 CPU quota
enforcement active: yes
cgroup:            /sys/fs/cgroup/decomp-ai-build
systemd --user:    unavailable (no user bus)
```

Distinguish **configured** from **active**. If `build-info --selftest` has not been run,
say enforcement is configured but unverified rather than claiming it is working.

## 3. MCP and Ghidra

```sh
opencode mcp list
```

- objdiff MCP: connected? Which binary and version?
- Ghidra MCP: connected, or disabled with a stated prerequisite?

Note the pinned experimental SHA from `DECOMP_AI.md`.

## 4. Current symbol progress

```sh
./.opencode/bin/decomp-state show
```

If a symbol is being tracked, report it in this shape. **The values below are an
illustration, not state** - every one of them is invented. Fill each from the command
above it; do not copy a line forward from this block:

```
NSMB release:      A2DE
MCP:               objdiff connected (PR #400 @ 6ce7392), ghidra connected
Ghidra:            ghidra_12.0.4_PUBLIC + ghidra-mcp v5.7.0-headless, 172 tools
Build CPU policy:  2 jobs, 200% quota, cgroup v2, active
Current symbol:    System::uploadSubBGState
Unit:              src/system/vblank
Source:            src/system/vblank.cpp
Baseline:          63.20%
Current:           84.10%
Best:              84.10%   (rev 9c7c0b3)
Attempts:          3        (1 regression reverted, 1 non-improving streak)
Last hypothesis:   BG offset register assigned once from a combined expression
Next useful action: mask y[] before the shift rather than after
```

The `Ghidra:` line must state what `opencode mcp list` **just** returned. If it is
genuinely absent, write `not installed - optional, matching works without it`; if it is
connected, name the version. Never report a remembered state: an earlier revision of this
file carried a stale "not installed" example that outlived the installation and read like
a live finding.

`Next useful action` must be concrete. Either the next specific hypothesis, or
**"reassess - 5 consecutive non-improving attempts"** when that threshold is hit. Never
write "continue matching" or "keep iterating"; if you cannot name the next experiment, say
what is unknown instead, because that is the real blocker.

## 5. Blockers

Only if something is actually missing. One line each, with what it unblocks:

```
BLOCKER  mwccarm 1.2sp3 absent  -> cannot build base objects, cannot measure any change
BLOCKER  A2DE.nds absent        -> cannot extract/delink, no objdiff.json
```

If nothing is blocked, omit the section entirely rather than padding it.

## 6. Repo cleanliness

```sh
git status --short
```

If matching work is uncommitted, note it. If anything proprietary is tracked, say so
immediately and loudly - that is the one finding that must never be buried.
