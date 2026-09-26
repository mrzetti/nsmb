---
description: Independently verify NSMB matching work for a symbol - rebuild, re-diff, inspect the diff for unrelated changes, and check contribution rules and NitroSDK compliance.
argument-hint: SYMBOL
---

# /nsmb-review SYMBOL

Verify matching work independently. Load `nsmb-project`, `nsmb-objdiff`,
`nsmb-build`, and `nsmb-contribution`.

Delegate the verification itself to `nsmb-reviewer`, which is read-only by design. Your job
is to make sure it re-derives everything rather than restating the matcher's claims.

**Do not trust the matcher's report.** A confident, wrong "100%" is the single failure this
command exists to catch, and restating a claim is how it survives.

## Preconditions

If `mwccarm` is missing, the review cannot be completed. Say so, report what *can* be
checked without a rebuild, and stop. Do not estimate a percentage.

## 1. Re-derive the match percentage yourself

Not the matcher's number. Yours.

```sh
# the single step wants the unit's base_path, not its name
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- \
  "$(./.opencode/bin/resolve-unit <unit> base_path)"
```

```js
const d = await tools.objdiff.diff_function({ symbol: "<mangled>", unit: "<unit>" });
return d;
```

If your number differs from the reported one, that is the **headline finding**. State it
first.

## 2. Inspect what is actually in the diff

```sh
git status --short
git diff
```

- Only the intended file(s) changed?
- Any change outside the target function - reindentation, renames, reordered declarations,
  drive-by cleanups? These destroy attribution and inflate review. Flag them.
- Any leftover experiment, commented-out code, debug output, or stray `TODO`?
- Any change to `build.zig`, `.gitignore`, `opencode.json*`, or `config/`? Those are not
  matcher territory unless the task genuinely required it.

## 3. Check contribution-rule compliance

Read `contributing.md`, then check the work against it.

- **The NitroSDK prohibition** is the one that matters most. Look for reasoning that could
  only have come from a proprietary Nintendo SDK rather than from this repository and the
  target binary: invented SDK function semantics, SDK struct layouts, SDK-documented
  behaviour. **If the hypothesis referenced the NitroSDK, that is a blocking finding**,
  because `contributing.md` says such PRs get rejected.
- Is the change to decompilation source, in the existing style?
- No reformatting or unrelated churn?

## 4. Look for tricks that fake a match

A high score obtained dishonestly is not a match. Flag:

- **Undefined behaviour** the compiler happened to exploit: strict aliasing, out-of-bounds
  access, uninitialised reads, signed overflow, unsequenced side effects.
- **Optimiser-directed hacks**: bogus `volatile`, empty loops, `#pragma`s, inline asm,
  `__attribute__((used))`, deliberate dead code.
- **Hardcoding** offsets, sizes, or addresses that only work for this one function.
- **Reinterpret casts** that launder a type purely to change codegen, where the correct
  type would have matched honestly.
- **Silicon-dependent behaviour**: writing a wrong value and patching it later, relying on
  register clobbering or specific garbage.

If the match is honest, say so plainly. Do not manufacture suspicion to look rigorous.

## 5. Check for collateral damage

The matcher worked on one unit, but units share headers.

```js
const o = await tools.objdiff.diff_overview({ unit: "<unit>", only_mismatches: true, limit: 50 });
return o;
```

- Did any *other* function in the same object regress?
- If a shared header changed, which other units are affected, and did you check them?

## 6. Verify the proprietary-data boundary

```sh
git check-ignore -v A2DE.nds extracted build objdiff.json .tools .decomp-ai
git diff .gitignore
```

- No ROM, `.nds` file, extracted data, delinked object, or `mwccarm` binary tracked.
- `.gitignore` **not weakened**. Only additive entries for `.tools/` and `.decomp-ai/` are
  acceptable.
- Nothing under `build/`, `extracted/`, `.tools/`, or `.decomp-ai/` newly tracked.
- Delivery was to the fork on a **feature branch**, with only the intended source change,
  no force-push, and **no push to `upstream`**.

A push to the user's fork is authorised and expected for finished work, so do not flag it.
A push to `NSMB-Decomp/nsmb` is a public contribution that needs explicit per-PR
instruction, and finding one is a blocking finding.

## 7. Confirm the recorded state is honest

```sh
./.opencode/bin/decomp-state show "<SYMBOL>"
```

Does `best_percent` match what you measured? Is a best source snapshot actually preserved?
Is `non_improving_count` consistent with the hypothesis history? A state file that claims
more progress than objdiff reports is itself a finding.

## Report format

Findings in severity order, each with a file and line reference. Then a verified list.

```
BLOCKING
  - src/system/vblank.cpp:31 - hypothesis relies on NitroSDK's documented layout
    for REG_BG0OFS_SUB, which is not derivable from this repo or the target
    binary. contributing.md rejects this.

MAJOR
  - Match percentage is 84.10%, not the 100% reported. Remaining: operand order
    in two `and`/shift pairs.
  - src/system/vblank.cpp:18-24 - four unrelated functions reindented.

MINOR
  - src/system/vblank.cpp:12 - leftover commented-out variant.

VERIFIED
  - re-measured independently at 84.10% via limited-build + diff_function
  - diff touches only src/system/vblank.cpp
  - no regressions among the other 16 functions in the unit
  - no UB, no optimiser-gaming, no hardcoded offsets
  - .gitignore unchanged, no proprietary data tracked
  - nothing committed or pushed
```

If the work is clean, say it is clean. Do not invent problems, and do not rubber-stamp a
bad result. The value of this command is that it is trusted - a review that cries wolf is
worse than no review.

## Reminder

Reviewing is not fixing. You do not edit source. Report findings; the matcher or the user
acts on them.
