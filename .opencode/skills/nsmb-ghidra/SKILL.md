---
name: NSMB Ghidra
description: Use headless Ghidra for ARM9/ARMv5T semantic context on NSMB - decompilation, callers, xrefs, types, globals - and how the repository's nsmb.h type import is meant to work. Load when objdiff needs more context than a diff can give.
---

# Ghidra for NSMB

Ghidra answers **"what is this thing"**. objdiff answers **"what does this instruction
say"**. For matching, objdiff is the oracle and Ghidra is the evidence.

Use Ghidra when the diff tells you an instruction is wrong but not what the code means:
unknown struct layouts, unclear argument counts, unidentified jump tables, unnamed globals,
or a caller whose use of the function reveals the signature.

**Do not open Ghidra for every iteration.** A per-iteration objdiff loop is faster and
cheaper. Reach for Ghidra when you are stuck, when you need types, or when you are
establishing context for a new area of the codebase.

## Ghidra is not required

The matching loop works fully without it. If the Ghidra MCP server is unavailable, say so
and continue with objdiff plus the repository's own material:

- `objdiff.json` - units, source paths, `scratch.c_flags`, `preset_id`
- `config/A2DE/arm9/*/symbols.txt` - the module's symbol set
- `config/A2DE/arm9/*/delinks.txt` - function boundaries
- `build/A2DE/delinks/**/*.o` - the target objects, readable with objdiff
- `src/**/*.hpp` - the project's own type definitions

That is often enough. Report the missing prerequisite rather than working around it
silently.

## The repository's intended Ghidra workflow

The repository already ships `tools/Ghidra/nsmb.h`, a header of `typedef`s and `struct`
definitions for the game's types. `contributing.md` documents importing it via Ghidra's
**File > Parse C Source...** with the profile set to:

> **ARM v5t little**

That is the architecture setting the project intends. Do not contradict it, and do not
re-import as ARMv4 or Thumb-only. Ghidra's `ParseCSourceScript` also asks for a language;
it must be the same ARM v5t little profile, otherwise struct offsets come out wrong and
every field access is misread.

`contributing.md` also notes that this manual step is expected to be replaced by
`dsd-ghidra` typesync. Until that lands, the import is a manual, one-time prerequisite.

### The smallest manual prerequisite

There is currently **no automated type-sync** in this repository. Do not invent one. The
honest workflow is:

1. Open (or create) a Ghidra project for the ARM9 binary.
2. Once, manually: **File > Parse C Source...**, clear the profile, add
   `tools/Ghidra/nsmb.h`, set Program Architecture to **ARM v5t little**, save the
   profile, **Parse to Program**, Continue, Use Open Archives.
3. Save the project. Later sessions reuse it.

`tools/Ghidra/nsmb.h` uses the same type vocabulary as `src/base_types.hpp`
(`u8`/`s16`/`s32`/`fx16`, `unknown1`/`unknown2`/`unknown4` placeholders), so a struct that
Ghidra shows and a struct the source declares should be reconcilable by eye.

## Which binary to import

The ARM9 code lives in the extracted ROM, not in the delinked objects:

- `extracted/A2DE/arm9/` - the ARM9 binary
- `build/A2DE/delinks/**/*.o` - per-module delinked objects, which is what objdiff reads

For objdiff-oriented work the delinked objects are the relevant material. For a whole-binary
view of the ARM9 module, import the ARM9 binary. Overlays (`arm9_ovNNN`) hold most gameplay
code and correspond 1:1 to objdiff units named by module path - `src/system/vblank` lives
in one of them. `config/A2DE/arm9/config.yaml` lists every module with its object path and
a hash, and is the map between the two.

Note that overlay `a3051d1c98d2647d` appears for many overlays in `config.yaml`: those are
empty/placeholder entries, not real distinct code.

## Which Ghidra MCP implementation, and why

Two candidates were evaluated. **`hacr-lab/ghidra-mcp`** (upstream `bethington/ghidra-mcp`)
was chosen.

| | hacr-lab/ghidra-mcp | jaenster/ghidra-mcp |
| --- | --- | --- |
| Headless | yes - `GhidraMCPHeadlessServer`, no GUI needed | headless daemon |
| Transport | **stdio** bridge, plus localhost HTTP | Streamable-HTTP / SSE with OAuth 2.1 |
| Tool surface | ~231 tools: decompile, disassemble, callers/callees, xrefs, types, globals, project lifecycle, batch ops | narrower |
| Scriptable project load | yes - create/open project, load program, run analysis | yes |
| Fits "stdio or localhost only" | stdio default; HTTP binds 127.0.0.1 | HTTP-first, OAuth-oriented |

`jaenster/ghidra-mcp` is HTTP/SSE-first with an OAuth 2.1 flow. That is a network service to
stand up, authenticate, and keep bound - more moving parts than this task needs, and a
weaker fit for the "prefer stdio or localhost-only" requirement. The hacr-lab project
gives stdio by default and still covers every required capability.

Both are young, low-adoption projects. Treat the integration as experimental and verify
before relying on it.

### Architecture

```
OpenCode  --stdio-->  bridge_mcp_ghidra.py   (Python, MCP server)
                          |  HTTP on 127.0.0.1
                          v
                   GhidraMCPHeadlessServer   (Java, holds the Ghidra program)
```

The MCP side is stdio, so nothing is exposed off the machine. The Java side listens on
loopback only, which is where the analysis program actually lives.

### Wrapper

`opencode.jsonc` invokes `./.opencode/bin/ghidra-mcp`, not the bridge directly, because the
Java headless server has to be started and have a program loaded before the bridge is
useful. The wrapper:

1. checks Ghidra is installed at `.tools/ghidra`,
2. starts the headless server on `127.0.0.1` if it is not already up,
3. loads the ARM9 program and lets analysis run if needed,
4. execs the Python bridge in stdio mode,
5. tears the server down when the bridge exits.

CPU limits apply here too: the headless server is a long-lived JVM and can be genuinely
expensive, so it is started under the same cgroup cap as builds. Ghidra's auto-analysis is
multi-threaded and would otherwise use every core.

### Prerequisite status

`/nsmb-setup` reports this explicitly:

| Requirement | Status |
| --- | --- |
| Java 21 | needed |
| Ghidra 12.0.4 (the version the MCP plugin pins) | needed |
| Maven 3.9+ | needed to build the plugin JAR |
| Ghidra JARs installed into `~/.m2` | needed, one-time per Ghidra version |

Ghidra analysis is slow to warm up. Budget for it once per session, not per iteration.

## Using it

Under Code Mode the tools are in the `ghidra` namespace. The catalog is large, so use
`search(...)` rather than assuming names:

```js
return await search({ namespace: "ghidra", query: "decompile function", limit: 5 });
```

Then call the exact path. Typical shape:

```js
const r = await tools.ghidra["decompile_function"]({ address: "0x0206b80c" });
return typeof r === "string" ? r.slice(0, 4000) : r;
```

Filter aggressively. Ghidra responses are large and a full program listing will consume
the context budget for no benefit. Return slices.

## Getting value out of it, in order of usefulness

1. **`decompile_function`** - the pseudocode. Read it for semantics, then verify every
   concrete claim against objdiff's disassembly. Ghidra's ARM9 output is imperfect, and
   its `undefined4` placeholders are exactly the fields whose width you are trying to
   determine.
2. **Field access patterns** - how a struct field is used across many functions is often
   the fastest way to infer its type. If a field is always loaded with `LDRB` and compared
   against 0, it is a byte flag.
3. **Callers** - how a caller passes arguments constrains the callee's signature, and
   the callee may be a stub. Cheap and often decisive.
4. **Callees** - an unresolved call in the target is often a runtime helper (division,
   `memcpy`, `sqrt`). Recognising it tells you what the source expression was.
5. **Xrefs to a global** - a hardware register used in one function is usually a `REG_*`
   macro in `src/`, already defined in the project headers. Find the real name in the
   source rather than inventing one.
6. **Neighbouring functions** - often a variant of the target, and can disambiguate a
   signature immediately.
7. **Strings** - a referenced string frequently names the subsystem and the function's role.

## Boundaries

- **Ghidra pseudocode is a hypothesis.** Never quote it as the specification. objdiff's
  disassembly is the specification.
- **Never invent a type** Ghidra did not show. If a field is `undefined4`, say it is
  unknown width and go find out from the load instruction.
- **Never use Ghidra to write into the Ghidra project** as part of matching analysis.
  Renaming and retyping in the project is a documentation activity, not matching work, and
  it creates a divergence between the project and the source. Treat Ghidra as read-only
  here.
- **Never let Ghidra analysis bypass the CPU cap**, and do not raise the cap to make Ghidra
  faster.
