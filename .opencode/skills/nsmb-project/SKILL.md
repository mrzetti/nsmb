---
name: NSMB Project
description: Ground truth about the NSMB Nintendo DS matching-decompilation repository - architecture, build pipeline, objdiff units, and the rules that constrain all work here. Load this first when working in this repository.
---

# NSMB project: what this repository actually is

Load this before doing anything else in this workspace. Everything else assumes it.

## The one-line version

Matching decompilation of **New Super Mario Bros. for Nintendo DS**. Not a GameCube/Wii
project, not PowerPC. ARM9 / ARM946E / ARMv5T, little-endian, C++.

## Hard facts

| Property | Value | Where it comes from |
| --- | --- | --- |
| Platform | Nintendo DS | `readme.md` |
| Primary release | `A2DE` (USA/Australia) | only release with real progress |
| CPU | ARM946E in ARM9, ARMv5T, **little-endian** | `-proc=arm946e` in `build.zig` |
| Instruction set | ARMv5T, with Thumb interworking | `-interworking` |
| Language | C++ | `-lang=C++`, `-RTTI=off` |
| Compiler | Metrowerks CodeWarrior **mwccarm 1.2sp3** | `build/compiler/mwccarm/1.2/sp3/mwccarm.exe` |
| Compiler exception | Y7QJ uses mwccarm **2.0/sp2p4** | `build.zig` `Release.compilerPath()` |
| Compiler host | Wine, on Linux | `build.zig` prepends `wine` |
| Build system | Zig build, Zig **0.16.x** | `build.zig` uses `std.Io`, new `std.Build` API |
| Delink/config tool | **dsd 0.12.x** | `contributing.md` says 0.12.0; 0.12.1 current |
| Match oracle | objdiff | `zig build objdiff` generates `objdiff.json` |
| Ghidra | ARM **v5t little** | `contributing.md` import instructions |
| Full ROM build | **not possible** | `readme.md` states it explicitly |

**Re-read `build.zig` rather than trusting this table.** It is a snapshot. The compiler
flags below are the ones that matter, and they come from `BuildMWCC.make`.

## The actual compiler invocation

From `build.zig`, `BuildMWCC.make`, for A2DE:

```
wine ./build/compiler/mwccarm/1.2/sp3/mwccarm.exe <source> -o <dest>
  -O4,p -interworking -proc=arm946e -lang=C++ -Cpp_exceptions=off -w=off
  -gccinc -nolink -c -sym=on -RTTI=off -once
  -i lib/Nitro/ -d VER_A2DE
```

What each flag means for matching:

- `-O4,p` - optimise for performance with the `p` (speed/space preference) code model.
  Heavy inlining. Small helpers vanish into their callers.
- `-interworking` - ARM and Thumb code coexist; calls cross the boundary via `BL`/`BLX`
  with bit 0 of the target set. A function can be ARM or Thumb independently of its
  neighbours.
- `-proc=arm946e` - ARM946E core: ARMv5T plus DSP-style extensions, unified 4K/16K caches.
  No NEON on ARM9.
- `-RTTI=off -Cpp_exceptions=off` - no typeinfo, no exception tables. A `throw` or
  `dynamic_cast` in the source will never match.
- `-gccinc` - GCC-style include search, which is why `lib/Nitro/` is on the include path.
- `-once` - single-pass compilation.
- `-sym=on` - emit symbols, which is what makes objdiff able to match functions by name.
- `-d VER_A2DE` - release macro. Source is `#if`-ed per release in places.

The same flags appear in `objdiff.json` under each unit's `scratch.c_flags`, plus
`preset_id: 201` and `platform: nds_arm9`. That matters because objdiff uses them to
disassemble the target correctly.

## Build pipeline

`contributing.md`, in order:

```sh
zig build extract     # dsd rom extract -r <release>.nds -o extracted/
zig build delink      # dsd delink -c config/<release>/arm9/config.yaml
zig build objdiff     # dsd objdiff ... -> writes objdiff.json (gitignored)
zig build all         # compile every unit with a base_path
zig build report      # objdiff-cli report generate
```

`zig build single -DRelease=A2DE -- <base_path>` compiles ONE unit. The argument is the
unit's `base_path` **verbatim** (`config/A2DE/arm9/../../../build/A2DE/src/system/vblank.o`),
not the unit name - `getSourceByDest()` matches on exact equality. Use
`./.opencode/bin/resolve-unit <unit-name> command` to produce it.

`objdiff.json` is **generated and gitignored**. A fresh checkout has none, which is why
`build.zig` guards the `all` step with a null check and comments it out.

## objdiff unit anatomy

`objdiff.json` top level:

```jsonc
{
  "min_version": "2.3.2",
  "custom_make": "zig",
  "custom_args": ["build", "single", "-DRelease=A2DE", "--"],
  "target_dir": ".../build/A2DE",
  "base_dir":   ".../build/A2DE/delinks",
  "units": [ ... 689 units, 353 with a base_path ... ],
  "progress_categories": ["Minigames", "NitroSDK"]
}
```

A unit that can be compiled and diffed:

```jsonc
{
  "name": "src/system/vblank",           // module path, this is the unit id
  "target_path": "build/A2DE/delinks/src/system/vblank.o",   // from the ROM
  "base_path":   "build/A2DE/src/system/vblank.o",           // from our source
  "scratch": {
    "platform": "nds_arm9",
    "compiler": "mwcc_20_84",            // objdiff's name for this CodeWarrior
    "preset_id": 201,
    "ctx_path": "build/A2DE/src/system/vblank.ctx.cpp",
    "build_ctx": true
  },
  "metadata": {
    "complete": false,
    "source_path": "src/system/vblank.cpp",
    "auto_generated": false
  }
}
```

Key points:

- **target object** (`target_path`, under `delinks/`) is what the original ROM shipped.
  It is produced by `zig build delink` and is the fixed side of every comparison.
- **base object** (`base_path`) is what our source compiles to right now. This is the
  side we change.
- Units named `_dsd_gap@main_NN` are dsd-inserted gap stubs with no `base_path` and no
  source. They are not matchable work. `build.zig` skips them.
- `metadata.complete: false` is a flag, not a percentage. Ignore it; objdiff's own
  per-function match% is the measure.

## The matching loop, in full

```
pick symbol
  -> find its unit and source file (objdiff.json metadata)
  -> baseline: build the unit, diff_function, read the percentage
  -> read the target column of the diff
  -> form ONE hypothesis
  -> edit ONE thing
  -> rebuild that ONE unit
  -> diff_function again
  -> keep if better, revert if worse
  -> record the number
  -> after 5 non-improving attempts: reassess, do not keep guessing
  -> independent review
  -> a human decides what happens to it
```

## The rules that constrain everything

Read `contributing.md` before doing substantive work. The binding constraints:

### The NitroSDK prohibition

> Do not use NitroSDK libraries when contributing to this project. If it is suspected you
> relied on the NitroSDK in a pull request it will be rejected.

This means: do not use NitroSDK source, and do not use knowledge that could only have come
from the NitroSDK. Do not reason about Nintendo SDK internals from proprietary SDK sources.
Derive everything from this repository, the target binary, and observable compiler
behaviour.

`lib/Nitro/` in this repository is the project's own minimal shim, not the SDK. It is a
legitimate part of the tree.

Note `progress_categories` includes `"NitroSDK"` as a progress category. That is a
project progress grouping for Nitro-calling code; it is not permission to consult the SDK.

### Proprietary data must never be committed

Never commit, stage, or upload:

- ROMs and `.nds` files
- extracted ROM data (`extracted/`)
- delinked objects and build output (`build/`)
- the proprietary `mwccarm` compiler binaries
- Nintendo SDKs
- proprietary game assets

`.gitignore` already covers all of this. **Do not weaken it.** If your workflow seems to
need a gitignore change, the workflow is wrong.

Never download a ROM or a `mwccarm` build. Those are the user's to supply. If a
prerequisite is missing, report it.

### AI work stays subject to human review

Do not open pull requests. Do not push. Do not commit without being asked. Matching output
is a proposal for a human maintainer to evaluate, not a contribution.

### Never destructive git operations without explicit instruction

No `git push`, `git reset --hard`, `git clean -fd`, `git checkout --`, `git restore`. Do not
delete unrelated in-progress work. Best-version preservation uses file copies in
`.decomp-ai/best/`, not git.

## Resources on this host

The build host runs other services. Builds are CPU-capped by policy:

- `./.opencode/bin/limited-build` - the only supported way to build. Injects `-j<jobs>`
  and applies a cgroup v2 CPU quota.
- `./.opencode/bin/build-info` - show the live policy and prove enforcement.
- Never invoke a bare `zig build` from automation.
- "More CPU would be faster" does not justify raising the cap.

## Type conventions

From `src/base_types.hpp`, and mirrored in `tools/Ghidra/nsmb.h`:

```c
typedef unsigned char  u8;    typedef signed char  s8;
typedef unsigned short u16;   typedef signed short s16;
typedef unsigned long  u32;   typedef signed long  s32;   // 32-bit on this target
typedef unsigned long long u64; typedef signed long long s64;
typedef s16 fx16;   // 16.16 fixed point stored in 32 bits
typedef s32 fx32;
```

Also `vu8`/`vu16`/`vu32` volatile variants for hardware registers, and
`NITRO_SIZE_ASSERT(what, size)` which is a compile-time struct size check that
`src/base_types.hpp` documents as a check against known-good sizes. It is a legitimate
in-repo tool for verifying a struct layout - use it rather than guessing offsets.

## Release macro

Each source file is compiled with `-d VER_<RELEASE>`, e.g. `VER_A2DE`. `Release.macroName()`
in `build.zig` produces it. When matching, make sure you are not reading a branch that only
exists for a different release.
