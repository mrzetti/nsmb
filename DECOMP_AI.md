# DECOMP_AI.md

How this workspace is configured for AI-assisted matching decompilation of
**New Super Mario Bros. (Nintendo DS)**, and what you need to know to drive it.

Read `AGENTS.md` for the operational rules that apply to every agent session. This file
covers the setup itself: what was installed, what is pinned, how the CPU limit is enforced,
and how to fix things when they break.

---

## Why this setup is NSMB-specific

This is not a generic decompilation framework. Almost every decision below follows from
one fact: the target is **Nintendo DS ARM9 / ARM946E / ARMv5T**, compiled by **Metrowerks
CodeWarrior `mwccarm`**, hosted on **Linux under Wine**, orchestrated by **Zig build** and
**dsd**, and measured by **objdiff**.

That rules out the material that most generic decompilation advice is built on:

- **Not PowerPC.** No GameCube/Wii register conventions, no `r3`-as-first-argument, no
  PowerPC branch-delay slots, no `stwu`/`stw` frame idioms, no PPC jump-table forms.
- **Not a full-ROM project.** `readme.md` states the repository cannot produce a complete
  ROM. Progress is per-function match percentage, not "the ROM builds".
- **Thumb matters.** `-interworking` means ARM and Thumb functions coexist. A function's
  mode cannot be inferred from its neighbours.
- **ARMv5T has no `SDIV`/`UDIV`.** A division in the target is a `BL` to a runtime helper.
  A `/` in the source becomes a call, and a `/ 4` must be a shift.
- **Wine.** mwccarm is a Windows binary. Every compile spawns wine, and wine startup cost
  dominates a short build.

Generic decompilation skills are useful for *process* (hypothesis, measure, revert, verify)
and actively misleading for *code*. The ARM/CodeWarrior specifics in
`.opencode/skills/nsmb-arm-matching/SKILL.md` are the ones that matter here.

---

## Architecture and toolchain

Read `build.zig` rather than trusting any table, including this one.

| Property | Value |
| --- | --- |
| Platform | Nintendo DS |
| Active release | `A2DE` (the only one with real progress) |
| CPU | ARM946E in ARM9, ARMv5T, little-endian |
| Language | C++ |
| Compiler | `mwccarm` **1.2sp3**; Y7QJ uses 2.0/sp2p4 |
| Compiler host | Wine (Linux) |
| Build | Zig build, Zig **0.16.x** (`std.Build` / `std.Io` API) |
| Extract/delink/config | **dsd 0.12.x** |
| Oracle | **objdiff** |
| Ghidra | ARM **v5t little** |

Actual compiler invocation, from `BuildMWCC.make` in `build.zig`:

```
wine ./build/compiler/mwccarm/1.2/sp3/mwccarm.exe <src> -o <out>
  -O4,p -interworking -proc=arm946e -lang=C++ -Cpp_exceptions=off
  -w=off -gccinc -nolink -c -sym=on -RTTI=off -once
  -i lib/Nitro/ -d VER_A2DE
```

### Build pipeline

```sh
./.opencode/bin/limited-build zig build extract     # needs the ROM
./.opencode/bin/limited-build zig build delink      # -> build/A2DE/delinks/**.o
./.opencode/bin/limited-build zig build objdiff     # -> objdiff.json (gitignored)
```

`objdiff.json` is generated and gitignored, so it is absent on a fresh clone. It contains
689 units, 353 of which have a `base_path` and are therefore compilable and matchable.
Units named `_dsd_gap@main_NN` are dsd gap stubs with no source.

The stored per-unit build command is:

```jsonc
"custom_make": "zig",
"custom_args": ["build", "single", "-DRelease=A2DE", "--"]
```

objdiff appends the unit's `base_path`, so the full command is:

```sh
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- <base_path>
```

### The `single` argument is `base_path`, not the unit name

This is the easiest thing in the whole workflow to get wrong, and `build.zig` panics
instead of explaining itself. dsd writes `base_path` as a **long relative path**:

```
config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o
```

and `build.zig`'s `getSourceByDest()` compares the argument against it for exact
equality. So `-- src/system/vblank` panics with `Could not find the source`, while
`-- config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o` works.

Do not memorise it. Use the resolver:

```sh
./.opencode/bin/resolve-unit <unit-name> command   # prints the whole build command
```

`resolve-unit` also answers `base_path`, `base`, `target_path`, `target`, `source`, `ctx`,
`flags`, and `json`, and accepts `--filter <substring>` for discovery. It refuses
`_dsd_gap@*` units explicitly, since those have no `base_path` and no source.

The objdiff MCP `build` tool does not have this hazard - it reads `base_path` straight out
of `objdiff.json`, so **inside a session, prefer `tools.objdiff.build({ unit })`**.

---

## What is installed

Everything lives under `.tools/`, which is gitignored. Nothing is installed system-wide
except the apt packages listed at the end.

```
.tools/
  zig-0.16.0/zig              Zig, the version contributing.md requires
  dsd                         dsd 0.12.1
  objdiff-stable/objdiff-cli  official stable release, used by `zig build report`
  objdiff-mcp/objdiff-cli     experimental MCP build (PR #400), pinned - see below
  ghidra/ghidra_12.0.4_PUBLIC/ Ghidra 12.0.4
  ghidra-mcp-src/             vendored checkout of the Ghidra MCP server
  ghidra-runtime/
    classpath.txt             Ghidra module classpath for the headless server
    venv/                     bridge Python environment, created with uv
  bin/{zig,dsd,objdiff-cli}   symlinks, so build.zig's bare calls resolve
  downloads/                  cached installers (can be deleted)
```

### objdiff: two installs, deliberately separate

| | Version | Used by |
| --- | --- | --- |
| `.tools/objdiff-stable/objdiff-cli` | **3.8.1** (official release) | `zig build report` |
| `.tools/objdiff-mcp/objdiff-cli` | **3.8.1 + PR #400** | the `objdiff` MCP server |

`build.zig` calls a bare `objdiff-cli` for the `report` step, resolved through `.tools/bin`.
That symlink points at the **stable** build. Do not repoint it at the experimental binary -
a half-finished experimental build would silently break reporting.

### The objdiff MCP pin

The MCP server comes from **[encounter/objdiff PR #400](https://github.com/encounter/objdiff/pull/400)**,
"Objdiff CLI MCP Server".

| | |
| --- | --- |
| PR state | **open, not merged** (verified 2026-09-26) |
| PR branch | `objdiff-mcp` |
| **Pinned commit** | **`6ce739249b97856e104f6ebd1a71b7927a25ef7b`** (`6ce7392`, "Honor symbol mappings in CLI MCP diffs") |
| Built from | a local clone, `cargo build --release -p objdiff-cli` |
| Build date | 2026-09-26 |
| Reports version | `objdiff-cli mcp 3.8.1 (objdiff-core embedded)` |
| Install path | `.tools/objdiff-mcp/objdiff-cli` |

The commit is pinned in a checkout, not tracked as a moving branch. **Re-verify the PR head
before rebuilding**, and update this table if it moved:

```sh
git ls-remote https://github.com/encounter/objdiff refs/pull/400/head
```

To rebuild the experimental binary from a specific commit:

```sh
git clone --filter=blob:none https://github.com/encounter/objdiff.git
cd objdiff && git checkout <SHA> && cargo build --release -p objdiff-cli
cp target/release/objdiff-cli <nsmb>/.tools/objdiff-mcp/objdiff-cli
```

### MCP tools exposed

`objdiff` (9 tools): `open_project`, `list_units`, `build`, `diff_function`,
`diff_overview`, `list_symbol_mappings`, `set_symbol_mapping`, `set_config`, `version`.

The normal loop leans on `diff_function`; `diff_overview` is for choosing work and spotting
regressions. Symbols are **mangled** - `System::foo` is rejected, `_ZN6System3fooEv` is
accepted. See `.opencode/skills/nsmb-objdiff/SKILL.md`.

---

## MCP startup

`opencode.jsonc` defines two local stdio servers, both with `codemode: true`.

### objdiff

The command is a **wrapper**, not the raw binary:

```jsonc
"objdiff": {
  "type": "local",
  "command": ["./.opencode/bin/objdiff-mcp", "--project", "."],
  "cwd": ".",
  "codemode": true
}
```

The wrapper exists for the CPU cap. It moves the MCP server process into a cgroup v2
CPU-quota cgroup *before it accepts any request*, so every `build()` it starts
(`zig` -> `wine` -> `wineserver` -> `mwccarm`) inherits the cap through normal cgroup
inheritance. This is why an MCP-triggered build cannot bypass the resource policy, and why
the wrapper must not be replaced by a direct `objdiff-cli mcp` invocation.

Consequences of this design:

- `objdiff.json`'s build command needs no rewriting.
- Upstream `build.zig` is untouched.
- The cap is a single containment point, not per-build bookkeeping.

Transport is **stdio**. No port is bound, nothing is exposed off the machine.

### ghidra

```jsonc
"ghidra": {
  "type": "local",
  "command": ["./.opencode/bin/ghidra-mcp"],
  "cwd": ".",
  "codemode": true,
  "timeout": { "startup": 180000 }
}
```

Architecture:

```
OpenCode --stdio--> bridge_mcp_ghidra.py   (Python MCP server, 172 tools)
                         |  HTTP on 127.0.0.1:8089
                         v
                   GhidraMCPHeadlessServer (Java, owns the Ghidra program)
```

The wrapper starts the headless JVM inside the CPU-capped cgroup, waits for
`/check_connection` to answer, then execs the bridge on stdio and tears the JVM down on
exit. If a prerequisite is missing it exits with a specific message rather than hanging, so
a gap is reported instead of stalling a session.

Transport is **stdio** for MCP; the Java side binds **127.0.0.1 only**.

Tool groups are selected explicitly. The bridge ships 171 endpoints across 13 lazy groups
and advertises only a subset by default - `decompile_function` and the other tools matching
needs are missing from a bare startup. The wrapper requests:

```
headless, function, listing, xref, symbol, datatype, program, project, analysis
```

which yields **172 advertised tools** and covers every promised capability: decompile,
disassemble, callers, callees, xrefs, struct layout, globals, strings, function search,
control-flow analysis, type import, project lifecycle, and program loading.

`malware` is deliberately excluded - it is irrelevant to a Nintendo game and not something
to advertise in this workspace.

### Which Ghidra MCP implementation, and why

`hacr-lab/ghidra-mcp` (upstream `bethington/ghidra-mcp`, commit `e6c325e`, v5.7.0) was chosen
over `jaenster/ghidra-mcp`.

| | hacr-lab | jaenster |
| --- | --- | --- |
| Headless | yes, `GhidraMCPHeadlessServer` | headless daemon |
| Transport | **stdio** default, plus localhost HTTP | Streamable-HTTP / SSE with OAuth 2.1 |
| Tool surface | 231 endpoints, 13 groups | narrower |
| Fits "stdio or localhost only" | yes | HTTP-first, needs a daemon + auth |

`jaenster/ghidra-mcp` is an HTTP/SSE service with an OAuth 2.1 flow: more moving parts to
stand up and keep bound, and a weaker fit for the transport requirement.

Both are young, low-adoption projects. Treat the integration as experimental.

**One local patch was required** to make the headless server start at all. Upstream
registers `/create_folder` and `/delete_file` twice - once via `@McpTool` and once in the
manual headless set - and `HttpServer.createContext` throws on a duplicate path, aborting
startup with `IllegalArgumentException: cannot add context to list`. The fix makes the later
(headless-capable) registration win. Full diagnosis, rationale, and the diff are in
`.opencode/patches/ghidra-mcp-5.7.0-headless-duplicate-context.patch`.

Verified before / after:

```
before:  Failed to launch headless server: cannot add context to list
after :  Registered 202 REST API endpoints
         HTTP server started on 127.0.0.1:8089
         GET /check_connection -> Connection OK - GhidraMCP Headless Server v5.7.0-headless
```

The patch is applied to the vendored checkout under `.tools/`, which is gitignored. It is
not an NSMB change and is not committed upstream. `.opencode/bin/build-ghidra-runtime`
re-applies it.

### Rebuild the Ghidra runtime

```sh
./.opencode/bin/build-ghidra-runtime
```

Installs the Ghidra JARs into `~/.m2`, builds the plugin with Maven, deploys it as a user
extension, creates the bridge environment with **uv**, regenerates the classpath, and
verifies. Requires Java 21, Maven 3.9+, Ghidra **12.0.4** (the version the plugin pins -
the installer refuses a mismatch), and `uv`.

> Ghidra 12.0.4 is required, not "latest". `pom.xml` pins `ghidra.version` to `12.0.4` and
> `build-ghidra-runtime` fails fast on a mismatch. Ghidra 12.1.4 is also cached in
> `.tools/downloads/` if you need it for something else.

### Ghidra is optional

Matching works without it. Ghidra adds semantic context objdiff cannot provide:
pseudocode, callers, callees, xrefs, struct layout, globals. The repository's own
`tools/Ghidra/nsmb.h` is imported manually per `contributing.md` (**ARM v5t little**), and
`contributing.md` notes this is expected to be replaced by `dsd-ghidra` typesync. There is
**no automated type sync today** - do not invent one.

---

## CPU limiting

This repository is worked on inside a server that hosts other services. Builds are
CPU-capped **by design**, and the limit is enforced, not merely configured.

### Policy

| Logical CPUs (`nproc`) | `DECOMP_BUILD_JOBS` | `DECOMP_CPU_QUOTA` |
| --- | --- | --- |
| 1 | 1 | 100% |
| 2 | 1 | 100% |
| 3 or more | 2 | 200% |

`100%` is one core's worth of aggregate CPU time; `200%` is two. A 2-vCPU host stays at
100% and one job, because a 200% quota there would consume the whole machine. This host has
8 logical CPUs, so it runs **2 jobs behind a 200% quota**.

Defaults are deliberately conservative. **"More CPU would be faster" is not a reason to
raise the limit.** If you want a different limit, set it explicitly.

### Changing the limits

Read by `.opencode/bin/decomp-env`, which every build path sources:

| Variable | Default | Meaning |
| --- | --- | --- |
| `DECOMP_BUILD_JOBS` | auto per table | Zig concurrency, passed as `-jN` |
| `DECOMP_CPU_QUOTA` | auto per table | aggregate CPU quota, e.g. `200%` |
| `DECOMP_CPU_CORES` | `nproc` | assume a different CPU count |
| `DECOMP_NICE` | `10` | scheduling priority (not a cap) |
| `DECOMP_CPUSET` | `0-<cores-1>` | affinity for the `taskset` fallback |
| `DECOMP_ENFORCE` | auto | `cgroup` \| `taskset` \| `off` |
| `DECOMP_CGROUP_ROOT` | `/sys/fs/cgroup` | cgroup v2 mount point |

```sh
# one command
DECOMP_BUILD_JOBS=4 DECOMP_CPU_QUOTA=400% ./.opencode/bin/limited-build zig build all

# a whole session
export DECOMP_BUILD_JOBS=3 DECOMP_CPU_QUOTA=300%
```

A full `zig build all` stays limited too. There is no "unrestricted" path in the tooling,
which is intentional.

### Inspecting and proving it

```sh
./.opencode/bin/build-info              # policy, mechanism, toolchain
./.opencode/bin/build-info --selftest   # plus a measurement that the cap bites
```

The self-test runs identical busy-loop workloads capped and uncapped and reports the
effective core count, so it distinguishes a real cap from a number in a config file.
`/nsmb-status` includes the same information.

### Enforcement mechanism, and why it is cgroup

`systemd-run --user --scope` would be tidier, but there is no user session bus on this host
(`systemctl --user` fails with `Failed to connect to bus: No medium found`). The scripts
therefore drive **cgroup v2 directly**.

Two traps make a naive "is `cpu.max` writable?" probe report a false positive. Both are
handled in `decomp-env`:

1. **`cpu.max` takes raw microseconds, not systemd percent.** `CPUQuota=200%` is systemd
   syntax; the file wants `200000 100000`. Writing `"200% 100000"` fails with `EINVAL`.

2. **The session scope is a threaded domain, where a quota silently does nothing.**
   `/user.slice/user-1002.slice/session-*.scope` reports `cgroup.type` as
   `domain threaded`. There, `cpu.max` accepts a value and `cgroup.controllers` lists `cpu`,
   but `cgroup.procs` is **not writable** (`EOPNOTSUPP`) and per-process bandwidth control
   does not apply. A probe that only writes `cpu.max` concludes the cap works. It does not -
   `cpu.stat` shows `nr_throttled 0` while the workload runs flat out.

   A child of the **cgroup mount root** is a plain `domain`, where `cgroup.procs` is
   writable and `cpu.max` genuinely throttles. That is why the working cgroups are
   `/sys/fs/cgroup/decomp-ai-build` and `/sys/fs/cgroup/decomp-ai-mcp`, and not children of
   the session scope.

`decomp-env` therefore accepts a candidate base only when **all four** checks pass:
`cgroup.type` is exactly `domain`; `cpu` is in `cgroup.controllers`; `cpu.max` accepts a
write; and the process can write **its own PID** to `cgroup.procs`.

Verified enforcement, `cpu.max = 200000 100000`, four spinners for three seconds:

```
uncapped wall 2.23s
capped   wall 3.02s
usage_usec     6070117   / 3.02s wall  =  2.0 cores
nr_throttled   30
throttled_usec 5975164
```

### Fallbacks, in descending strength

| Mechanism | Is it a real cap? |
| --- | --- |
| cgroup v2 `cpu.max` | **yes** - aggregate CPU time, inherited by all descendants |
| `taskset` affinity + `nice` | no - affinity bounds *where*, `nice` only prioritises |
| Zig `-jN` | partially - bounds Zig's scheduler, not independently threaded children |

`nice` alone is not a cap. `taskset` is not a quota. Only the cgroup is both, which is why
the MCP server is contained rather than relying on per-build wrapping.

### Where the cap applies

| Path | Capped by |
| --- | --- |
| `./.opencode/bin/limited-build zig build ...` | cgroup, plus `-jN` injection |
| objdiff MCP `build` tool | the server's own cgroup, inherited by all descendants |
| `.opencode/bin/ghidra-mcp` headless JVM | cgroup |
| A bare `zig build` | **nothing** - do not do this |

`limited-build` inserts `-jN` immediately after the `zig build` subcommand, which is where
Zig reads it - before the step name and before the `--` separator that introduces the unit's
own arguments.

---

## Working state and best-version preservation

Matching regresses, so progress is tracked numerically and the best-scoring source is kept
verbatim.

```
.decomp-ai/                 gitignored
  state.json                per-symbol progress
  best/<symbol>.best        best-scoring source snapshot
  logs/
  state/mcp-policy.json     what the running MCP server is enforcing
  snapshots/
```

Tracked per symbol: `release`, `unit`, `symbol`, `source_file`, `baseline_percent`,
`current_percent`, `best_percent`, `attempt_count`, `non_improving_count`, `hypotheses`,
`best_source_snapshot`, `best_source_revision`, `last_objdiff_summary`, `timestamp`.

```sh
.opencode/bin/decomp-state begin  "System::foo" --unit "src/x" --source "src/x.cpp" --percent 63.2
.opencode/bin/decomp-state record "System::foo" --percent 71.8 --hypothesis "u8 dirty flag"
.opencode/bin/decomp-state revert "System::foo"   # on a regression
.opencode/bin/decomp-state show   "System::foo"
```

`record` snapshots the source file **every time a new best is reached**, so an experiment can
never destroy the best result. `revert` copies the snapshot back.

This uses file copies, never `git`. There is no `git reset --hard`, no `git checkout --`, and
no `git clean` anywhere in the workflow.

---

## Agents

| Agent | Mode | Model | Can | Cannot |
| --- | --- | --- | --- | --- |
| `nsmb-orchestrator` | primary, **default** | `space-bunny-free#max` | delegate to the three below, read state, commit/push/PR to the fork | edit source, build, push to upstream |
| `nsmb-binary-analyst` | subagent | `space-bunny-free#max` | read, objdiff diff, Ghidra | edit anything, build, any git write |
| `nsmb-matcher` | subagent | `space-bunny-free#max` | edit decomp source, limited builds, objdiff, commit/push/PR to the fork | edit `build.zig` / config, push to upstream |
| `nsmb-reviewer` | subagent | `space-bunny-free#max` | rebuild, re-diff, inspect diff and rules | edit anything, any git write |

### Delivery: the fork is open, upstream is gated

The user has authorised committing, pushing branches, and opening pull requests **on their
own fork**. `origin` = `mrzetti/nsmb`, and `gh` is authenticated as `mrzetti` with the
`repo` scope, so this is actually possible from this host.

That authorisation is deliberately scoped, because the two targets are not equivalent:

| | Fork (`mrzetti/nsmb`) | Upstream (`NSMB-Decomp/nsmb`) |
| --- | --- | --- |
| Visibility | the user's own space | **public** |
| Who reviews it | the user | NSMB maintainers |
| `contributing.md` | good practice | **the contribution gate** |
| Automated action | **allowed** | **needs explicit per-PR instruction** |

Do not treat "you may push to my fork" as "you may contribute upstream". Staging work on
the fork is the delivery mechanism; opening a PR upstream is a separate decision the user
makes per PR.

`git push origin` / `git push mrzetti` and `gh pr create` are allowed. Denied in
configuration, for every agent:

```
git push upstream          the public contribution gate
git push --force  -f  --all  --mirror
git reset --hard           destroys unrelated in-progress work
git clean -fd  -fdx
git checkout --            ditto
git restore
git branch -D
gh release  gh repo delete  gh secret
gh api repos/NSMB-Decomp/*
```

Also denied: `edit` on `build.zig`, `opencode.json*`, and `.gitignore` for the matcher, and
`edit` entirely for the analyst and the reviewer.

A workspace-wide permission floor applies to every agent; individual agents may only narrow
it. The orchestrator is denied `subagent` for everything except the three NSMB specialists,
and denied the objdiff `build` tool - the matcher owns building.

## Skills

| Skill | ID | Load when |
| --- | --- | --- |
| NSMB Project | `nsmb-project` | anything at all; the ground truth for this repo |
| NSMB ARM matching | `nsmb-arm-matching` | forming a hypothesis about an instruction |
| NSMB objdiff | `nsmb-objdiff` | measuring, or choosing what to work on |
| NSMB build | `nsmb-build` | before any build |
| NSMB Ghidra | `nsmb-ghidra` | objdiff needs semantic context |
| NSMB contribution rules | `nsmb-contribution` | before finalising or proposing work |

## Commands

```
/nsmb-setup                 inspect the workspace and report what is present/missing/blocked
/nsmb-analyze SYMBOL        focused evidence brief, no edits
/nsmb-match SYMBOL          baseline -> hypothesise -> edit -> build -> diff -> keep/revert
/nsmb-review SYMBOL         independent verification
/nsmb-status                one-screen status
```

---

## Normal matching workflow

```
1. /nsmb-setup                      confirm prerequisites
2. /nsmb-analyze System::foo         read the target, form candidate hypotheses
3. /nsmb-match System::foo           run the measured loop
4. /nsmb-review System::foo          verify independently
5. human decides                    commit / push / PR, or discard
```

The loop inside step 3, once per iteration:

```
read the target column of the objdiff diff  (this is the specification)
  -> state ONE hypothesis
  -> make ONE coherent edit
  -> ./.opencode/bin/limited-build zig build single -DRelease=A2DE -- \
       "$(./.opencode/bin/resolve-unit <unit> base_path)"
  -> objdiff diff_function, read the percentage
  -> better: keep (snapshot taken automatically)
     worse:  decomp-state revert, then try something else
  -> after 5 consecutive non-improving attempts: STOP and reassess
```

`/nsmb-match` prints the running ledger:

```
Attempt 0: 63.20%  baseline
Attempt 1: 71.80%  +8.60   byte dirty flag tested against 0, not 1
Attempt 2: 70.40%  -1.40   regression (reordered branches) -> reverted
Attempt 3: 84.10%  +12.70  BG offset register assigned once from a combined expression
```

**100% means objdiff printed 100%.** Never report a match on the basis of appearance.

### Code Mode

Both MCP servers use `codemode: true`, so their tools live in Code Mode namespaces and you
filter responses before they reach the model:

```js
const [units, ov] = await Promise.all([
  tools.objdiff.list_units({ filter: "system" }),
  tools.objdiff.diff_overview({ unit: "src/system/vblank", only_mismatches: true, limit: 10 })
]);
return { units: String(units).slice(0, 800), overview: ov };
```

Always pass `limit` to `diff_overview`. Never return a full `list_units` dump or a whole
object disassembly. Ghidra's catalog is large, so discover with `search({ namespace: "ghidra", ... })`
rather than assuming tool names.

---

## Prerequisites

| Requirement | Status | Source |
| --- | --- | --- |
| Zig 0.16.x | vendored, `.tools/zig-0.16.0/zig` | ziglang.org |
| dsd 0.12.x | vendored, `.tools/dsd` (0.12.1) | GitHub releases |
| objdiff stable 3.8.1 | vendored | GitHub releases |
| objdiff MCP (PR #400) | vendored, pinned to `6ce7392` | built from source |
| Wine 9.0 | installed via apt | Ubuntu archive |
| `mwccarm` **1.2sp3** | **user-supplied, proprietary** | you |
| `A2DE.nds` ROM | **user-supplied, proprietary** | you |
| Java 21 | installed via apt | Ubuntu archive |
| Maven 3.8.7 | installed via apt | Ubuntu archive |
| Ghidra 12.0.4 | vendored | NSA releases |
| uv 0.12.19 | `~/.local/bin/uv` | astral.sh |
| Python 3.12 | system | Ubuntu archive |

The two proprietary items are **yours to supply**. An agent must never download, search for,
or suggest a source for a ROM or `mwccarm`. If one is missing, the correct behaviour is to
report the gap and do everything else - analysis, target-side reading, and objdiff
inspection all still work.

With the ROM and `objdiff.json` present, objdiff can read the **target** objects and
self-diff them, which is enough for analysis. Producing a **base** object - and therefore
measuring any change - needs `mwccarm`.

---

## Troubleshooting

### Wine

```sh
wine --version
wineserver -p          # persistent wineserver; contributing.md recommends this after reboot
```

- First compile is slow: one-off prefix initialisation. Retrying is usually enough.
- `wineserver -p` cuts per-compile startup cost substantially, which matters when iterating
  on one unit at a time. It is the only Wine change recommended - do not alter global Wine
  configuration.
- A stale `wineserver` holding a lock makes builds hang with near-zero CPU. Kill it.
- The wineserver is a separate long-lived process. It stays in whatever cgroup it was
  started in, so start it under `limited-build` if you want it capped too.

### objdiff

- **`Symbol ... not found`** - you passed a demangled name. objdiff wants the mangled form.
  Get it from `diff_overview` or `echo _ZN... | c++filt`.
- **`Failed to read base object`** - expected until `mwccarm` is installed. It means the
  target exists but nothing has been compiled from source.
- **`Could not find the source`** from `zig build single` - you passed the unit *name*
  instead of its `base_path`. The step matches `base_path` for exact equality, and those
  are long relative paths. Use `./.opencode/bin/resolve-unit <unit> command`.
- **Server will not start** - check `.tools/objdiff-mcp/objdiff-cli --version` and that
  `objdiff.json` exists. `opencode mcp list` shows connection state.
- **MCP `build` fails** - almost always the missing compiler, not objdiff.

### Ghidra

- **`ghidra-mcp: Ghidra not installed`** - run `.opencode/bin/build-ghidra-runtime`.
- **`VERSION MISMATCH`** - the plugin pins Ghidra 12.0.4. Install that version and point
  `GHIDRA_INSTALL_DIR` at it.
- **`could not find or load main class`** - the classpath file holds relative paths. It must
  be absolute; `build-ghidra-runtime` regenerates it.
- **`cannot add context to list`** - the unpatched upstream bug. Re-apply the patch with
  `build-ghidra-runtime`; see the patch file for the full diagnosis.
- **`decompile_function` missing from the catalog** - the bridge loaded its default lazy
  groups. The wrapper already requests the correct set; if you invoke the bridge by hand,
  pass `--lazy --default-groups headless,function,listing,xref,symbol,datatype,program,project,analysis`.
- **First analysis is slow** - Ghidra's auto-analysis is multi-threaded and runs inside the
  CPU cap. Budget for it once per session, not per iteration.
- **Wrong struct offsets** - the program was not imported as **ARM v5t little**. Re-import
  `tools/Ghidra/nsmb.h` with that architecture.
- **Headless server log** - `.tools/ghidra-runtime/headless.log`.

### CPU limiting

- **`build-info` says `enforcement: off`** - no usable cgroup base was found. Re-run
  `--selftest` to see whether the cap is real. If cgroup is genuinely unavailable the
  fallback is `taskset` + `nice`, which is weaker and will say so.
- **Self-test reports INCONCLUSIVE** - the workload was not slowed. Re-run it; the machine
  may have been idle enough that the quota never bound.
- **Builds feel slow** - expected under a 2-core quota, and the intended trade.

### OpenCode

```sh
opencode debug config     # which config documents were loaded
opencode debug agents     # recognised agents and their models
opencode mcp list         # MCP connection state
```

If `opencode.jsonc` is not in the `debug config` list, the session's working directory is
not the repository root. Config is discovered from the working directory upward; agents,
skills, and commands are discovered from `.opencode/` directories. Move the session
(`session_move`) or start OpenCode in the repository.

---

## Privacy, copyright, and contribution constraints

- **Never commit, stage, or upload** ROMs, `.nds` files, extracted ROM data, delinked
  objects, `build/` output, the proprietary `mwccarm` binaries, Nintendo SDKs, or
  proprietary game assets. `.gitignore` covers all of it. **Do not weaken `.gitignore`.**
- **Never download** a ROM or `mwccarm`. Report them as missing prerequisites.
- **The NitroSDK prohibition.** `contributing.md`: *"If it is suspected you relied on the
  NitroSDK in a pull request it will be rejected."* Do not use NitroSDK sources, and do not
  use knowledge that could only have come from a proprietary Nintendo SDK. Derive from this
  repository, the target binary, and observable compiler behaviour. `lib/Nitro/` is the
  project's own shim and is fine.
- **AI work stays subject to human review.** No push, no PR, no commit without an explicit
  instruction. Matching output is a proposal for a maintainer to evaluate.
- **No destructive git operations** without an explicit instruction. `decomp-state revert`
  is the mechanism for undoing an experiment.

---

## File map

```
AGENTS.md                    operational rules, loaded every session
DECOMP_AI.md                 this file
opencode.jsonc               agents, permissions, MCP servers, skills
.opencode/
  agents/                    nsmb-orchestrator, -binary-analyst, -matcher, -reviewer
  skills/                    nsmb-project, -arm-matching, -objdiff, -build, -ghidra, -contribution
  commands/                  nsmb-setup, -analyze, -match, -review, -status
  bin/
    decomp-env               resolves and prints the resource policy (source this)
    limited-build            the only supported way to build
    resolve-unit             unit name -> base_path / source / target / build command
    objdiff-mcp              objdiff MCP inside a CPU-capped cgroup
    ghidra-mcp               headless Ghidra + MCP bridge (optional)
    build-ghidra-runtime     rebuild the Ghidra runtime with uv
    build-info               show/verify the CPU policy
    decomp-state             per-symbol progress, best-source snapshots
    selftest                 verify the whole setup end to end
  patches/                   local fix for the ghidra-mcp headless startup bug
.decomp-ai/                  gitignored working state
.tools/                      gitignored toolchain (see layout above)
```

An external research checkout lives at `../decomp-research-ai` (outside this repository so
its content is never tracked). Register it in `opencode.jsonc` under `skills`. Read it with
targeted `grep`/`read` calls - do not load it wholesale. **Much of it is PowerPC-oriented and
does not transfer to ARM9**; only the generic process advice applies, and architecture
specific claims from it should be treated as wrong until confirmed against `build.zig` and
the target binary.
