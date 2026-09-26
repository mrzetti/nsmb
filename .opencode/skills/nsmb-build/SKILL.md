---
name: NSMB build
description: How to build NSMB units under the CPU resource policy on this shared server - the single-unit fast path, the limited-build wrapper, cgroup enforcement, and troubleshooting Zig, dsd, Wine and mwccarm. Load before running any build.
---

# Building NSMB, and not taking the whole server with you

## The rule

**Never run a bare `zig build`.** Zig defaults to using every logical CPU, and this host
runs other services. Build only through the wrapper:

```sh
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- \
  "$(./.opencode/bin/resolve-unit src/system/vblank base_path)"
```

The wrapper:

1. injects `-j<jobs>` right after `zig build` (Zig reads `-j` as a top-level option, so it
   must precede the step name and the `--` separator),
2. creates a cgroup v2 CPU-quota cgroup and moves the launched process into it before
   exec, so every descendant inherits the cap,
3. applies `nice` as scheduling priority (a nicety, **not** a cap).

Or let the objdiff MCP server do it, which is the preferred path inside a session:

```js
await tools.objdiff.build({ unit: "src/system/vblank" });
```

The MCP server runs inside its own capped cgroup, so its builds are limited too.

## The policy

| Logical CPUs (`nproc`) | `DECOMP_BUILD_JOBS` | `DECOMP_CPU_QUOTA` |
| --- | --- | --- |
| 1 | 1 | 100% |
| 2 | 1 | 100% |
| 3 or more | 2 | 200% |

`100%` is one core's worth of aggregate CPU time. `200%` is two. On a 2-vCPU host a 200%
quota would consume the whole machine, so small hosts stay at 100% and one job. This
host has 8 logical CPUs, so it runs 2 jobs behind a 200% quota.

Defaults are chosen conservatively **on purpose**. Do not "optimise" them away, and do not
decide that more CPU is faster. If the user wants a different limit, they will say so.

### Changing the limits

```sh
DECOMP_BUILD_JOBS=4 DECOMP_CPU_QUOTA=400% ./.opencode/bin/build-info
```

Override for one command, or export for a session. `DECOMP_CPU_CORES`, `DECOMP_NICE`,
`DECOMP_CPUSET` and `DECOMP_ENFORCE` are also read. See the header of
`.opencode/bin/decomp-env` for the full list.

### Inspecting the live policy

```sh
./.opencode/bin/build-info              # configuration and mechanism
./.opencode/bin/build-info --selftest   # plus a measurement proving the cap works
```

The self-test runs identical busy-loop workloads capped and uncapped and reports the
effective core count, so it distinguishes a real cap from a number in a config file.

## Which enforcement mechanism is used, and why

On this host: **cgroup v2 CPU quota.**

`systemd-run --user --scope` would be tidier, but there is no user session bus here
(`systemctl --user` fails with "No medium found"), so the scripts drive cgroup v2 directly.

Getting a *working* cgroup took two non-obvious steps, both handled in `decomp-env`:

1. **`cpu.max` takes raw microseconds, not systemd percent.** `CPUQuota=200%` is systemd
   syntax; the cgroup file wants `200000 100000`. Writing `"200% 100000"` fails with
   `EINVAL`.
2. **The session scope is a threaded domain, where a quota silently does nothing.**
   `/user.slice/user-1002.slice/session-*.scope` reports `cgroup.type` as
   `domain threaded`. There, `cpu.max` accepts a value and `cgroup.controllers` lists
   `cpu`, but `cgroup.procs` is **not writable** (`EOPNOTSUPP`) and per-process bandwidth
   control does not apply. A naive probe concludes the cap works. It does not.

   A child of the **cgroup mount root** is a plain `domain`, where `cgroup.procs` is
   writable and `cpu.max` genuinely throttles. So the working cgroup is
   `/sys/fs/cgroup/decomp-ai-build` (and `.../decomp-ai-mcp` for the server), not a child
   of the session scope.

   `decomp-env` verifies a candidate by creating a probe cgroup, requiring
   `cgroup.type` to be exactly `domain`, requiring `cpu` in `cgroup.controllers`, writing
   `cpu.max`, and finally **writing its own PID to `cgroup.procs`**. Only a candidate that
   passes all four is used. This is why `build-info` can honestly say whether enforcement
   is active.

Verified enforcement on this host, `cpu.max = 200000 100000`, 4 spinners for 3s:

```
uncapped wall 2.23s
capped   wall 3.02s
usage_usec 6070117   / 3.02s wall  =  2.0 cores
nr_throttled 30
throttled_usec 5975164
```

### Fallbacks, in descending strength

1. **cgroup v2 quota** - real aggregate CPU cap, inherited by all descendants. Preferred.
2. **`taskset` affinity + `nice`** - used when no usable cgroup base exists. Affinity
   bounds *where* work runs, not *how much* CPU time it gets.
3. **zig `-j` only** - bounds Zig's own concurrency. Independently multithreaded children
   (wine, wineserver) are not bounded by it.

`nice` alone is not a cap. `taskset` is not a quota. Only the cgroup is both.

## Build the single unit, not the project

353 of the 689 units have a `base_path` and can be compiled. Compiling all of them to test
a one-line change costs minutes and CPU for no benefit. `build.zig` provides a `single`
step for exactly this.

**Prefer the objdiff MCP `build` tool**, which reads `base_path` out of `objdiff.json` for
you and is CPU-capped by construction:

```js
await tools.objdiff.build({ unit: "src/system/vblank" });
```

### The argument is `base_path`, not the unit name

This is the single easiest thing to get wrong, and `build.zig` panics rather than
explaining itself.

`objdiff.json` stores the invocation as:

```jsonc
"custom_make": "zig",
"custom_args": ["build", "single", "-DRelease=A2DE", "--"]
```

objdiff appends the unit's `base_path`, and dsd writes those as **long relative paths**:

```
config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o
```

`build.zig`'s `getSourceByDest()` compares your argument against `base_path` for exact
equality. So:

```sh
# WRONG - panics with "Could not find the source"
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- src/system/vblank

# RIGHT - the base_path, verbatim
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- \
  config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o
```

Do not memorise the path. Let the resolver produce the command:

```sh
./.opencode/bin/resolve-unit <unit-name> command
```

`resolve-unit` also answers `base_path`, `base`, `target_path`, `target`, `source`, `ctx`,
`flags`, and `json`, and takes `--filter <substring>` for discovery:

```sh
./.opencode/bin/resolve-unit --filter vblank
```

It refuses `_dsd_gap@*` units explicitly, since those have no `base_path` and no source -
they cannot be built or matched.

Use a full build only when checking for cross-unit regressions, and still route it through
`limited-build`:

```sh
./.opencode/bin/limited-build zig build all -DRelease=A2DE
```

### Scratch/ctx files

Some units have a `scratch.ctx_path` ending in `.ctx.cpp`. Passing one of those to
`single` produces a preprocessed context file instead of an object, via `BuildCTX` in
`build.zig`. `resolve-unit <name> ctx` prints it. Rare; only relevant when objdiff points
you at a ctx path.

## Setting up from scratch

```sh
# 1. The ROM, placed in the repo root, named for the release. Gitignored.
#    (The user supplies this. Never download it.)
ls A2DE.nds

# 2. Extract, delink, generate objdiff config.
./.opencode/bin/limited-build zig build extract
./.opencode/bin/limited-build zig build delink
./.opencode/bin/limited-build zig build objdiff
```

`extract` needs the ROM. `delink` and `objdiff` need `extract`'s output. `objdiff.json` is
gitignored and must be regenerated after a fresh clone or a release change.

Verify: `ls objdiff.json` and `.tools/objdiff-stable/objdiff-cli report generate`.

## Prerequisites

| Tool | Where | How |
| --- | --- | --- |
| Zig 0.16.x | `.tools/zig-0.16.0/zig` | vendored; `contributing.md` requires 0.16.x |
| dsd 0.12.x | `.tools/dsd` | vendored; `contributing.md` requires 0.12.0 |
| objdiff | `.tools/objdiff-stable`, `.tools/objdiff-mcp` | vendored |
| Wine | system | `apt-get install -y wine wine64` |
| **mwccarm 1.2sp3** | `build/compiler/mwccarm/1.2/sp3/mwccarm.exe` | **user-supplied, proprietary** |
| ROM | `A2DE.nds` in the repo root | **user-supplied, proprietary** |

`mwccarm` and the ROM must never be downloaded by an agent. Report them as missing and stop
that line of work; everything else - analysis, reading target disassembly, objdiff
inspection - still works without them.

`.tools/bin` is on `PATH` via `decomp-env`, which is how `build.zig`'s bare `dsd` and bare
`objdiff-cli` calls resolve.

## Wine notes

`build.zig` prepends `wine` to the compiler invocation on non-Windows hosts.

- `contributing.md` recommends `wineserver -p` after each reboot to start a persistent
  wineserver, avoiding per-compile startup cost. That is a large speedup when iterating.
- Do not change global Wine configuration without a reason. A persistent wineserver is
  recommended by the project and is the only change to make.
- Wine initialisation can be slow the first time. That is a one-off cost per prefix.
- The wineserver is a separate long-lived process. It stays in whatever cgroup it was
  started in, so if you start it yourself, consider starting it under `limited-build` so
  it is also capped.

## Troubleshooting

**`zig: command not found`** - use the wrapper, or source `decomp-env` to put
`.tools/bin` on `PATH`.

**`zig build` fails with a version or API error in `build.zig`** - wrong Zig. This
`build.zig` uses the Zig 0.16 `std.Build`/`std.Io` API; an older or newer Zig will not
parse it. Use `.tools/zig-0.16.0/zig`.

**`single` panics with "Could not find the source"** - `objdiff.json` is missing or stale,
or the argument is not a unit `base_path`. Regenerate with `zig build objdiff`.

**Build fails on a missing compiler** - `mwccarm` is absent. Expected, and not fixable by
an agent. Report it.

**Wine errors on first compile** - initialise once, then retry: `wineboot -u` or just run
a trivial invocation. If `wineserver -p` was run, wait for it to settle.

**Build is slow** - expected under a 2-core quota, and the intended trade. Check
`./.opencode/bin/build-info` to confirm the cap is the cause rather than a stuck
`wineserver`.

**Everything is slow and CPU shows near-zero usage** - the process is blocked on I/O or a
lock, not CPU-bound. A stale `wineserver` holding a lock is the usual cause.

**`nproc` reports more cores than the cgroup allows** - `cpu.max` is an aggregate quota
across all processes in the cgroup, not a per-process limit. Two concurrent builds share
one budget; that is intended.
