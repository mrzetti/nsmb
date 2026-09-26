---
description: Run the full objdiff matching loop for an NSMB symbol - baseline, hypothesise, edit one thing, rebuild the single unit, diff, keep or revert, and iterate to review.
argument-hint: SYMBOL
---

# /nsmb-match SYMBOL

Run the matching loop for one symbol and report measured progress at every iteration.

Load `nsmb-project`, `nsmb-objdiff`, `nsmb-arm-matching`, and `nsmb-build`.

You coordinate. Delegate the binary reading to `nsmb-binary-analyst`, the editing and
building to `nsmb-matcher`, and the final check to `nsmb-reviewer`. You do not write
decompilation source yourself.

## Preconditions

If `mwccarm` is missing, **stop and say so**. Without the proprietary compiler no base
object can be produced, so no change can be measured, and the loop would be guesswork
dressed up as progress. Report the gap and what the user needs to supply.

If `objdiff.json` is missing, generate it first with
`./.opencode/bin/limited-build zig build objdiff`.

## Step 0 - resolve

Get the unit, the owning source file, and the **mangled** symbol name. objdiff rejects the
demangled form.

## Step 1 - baseline

Build the unit and read the percentage. Without a baseline, no later claim of improvement
means anything.

```sh
# compile only that unit. Note: `single` wants the unit's base_path, not its name.
./.opencode/bin/limited-build zig build single -DRelease=A2DE -- \
  "$(./.opencode/bin/resolve-unit "<unit>" base_path)"
# or just let the resolver print the whole thing:
./.opencode/bin/resolve-unit "<unit>" command
```

```js
const d = await tools.objdiff.diff_function({ symbol: "<mangled>", unit: "<unit>" });
return d;
```

Record it:

```sh
./.opencode/bin/decomp-state begin "<SYMBOL>" --unit "<unit>" --source "<file>" --percent <N>
```

## Step 2 - gather only what the first hypothesis needs

Launch `nsmb-binary-analyst` for the target read. If you also need a second independent
thing, launch it in the background and proceed - these genuinely run in parallel.

Do not preload the whole unit. Ask for what the hypothesis needs.

## Step 3 - iterate

Each iteration is exactly one of these. Delegate to `nsmb-matcher` with the hypothesis
stated explicitly.

1. **ONE hypothesis**, written as a sentence tying a specific instruction difference to a
   specific source construct.
2. **ONE coherent edit.**
3. **Rebuild that one unit** - never the project. Always through `limited-build`, or via
   the objdiff MCP `build` tool which is capped by construction.
4. **Re-diff the function.**
5. **Measure** and record:
   ```sh
   ./.opencode/bin/decomp-state record "<SYMBOL>" --percent <N> --hypothesis "<text>"
   ```
6. **Keep or revert.** On a regression, revert immediately with
   `./.opencode/bin/decomp-state revert "<SYMBOL>"` **before** the next attempt. Never stack
   an experiment on top of a regression - you lose attribution.

Keep a running ledger:

```
Attempt 0: 63.20%  baseline
Attempt 1: 71.80%  +8.60   dirty flag tested against 0, not 1
Attempt 2: 70.40%  -1.40   regression (reordered branches) -> reverted
Attempt 3: 84.10%  +12.70  BG offset register assigned once from a combined expression
```

## Step 4 - the reassessment rule

**After 5 consecutive attempts that do not improve the best percentage, stop iterating.**

Non-improving means the approach is exhausted, not that a sixth guess will land. Reassess:

- Re-read the target disassembly in full, not just the diff hunks already seen.
- Question the assumptions everything else rests on: the signature, the struct layout, a
  field width, the caller's calling convention. A wrong assumption invalidates every
  attempt built on it.
- Ask `nsmb-binary-analyst` for a fresh read with different questions.
- Consider that the current shape is a dead end and a rewrite beats another edit.

Then report the stall with the numbers, rather than continuing to mutate.

## Step 5 - check for collateral damage

A change in a shared header can move other units:

```js
const o = await tools.objdiff.diff_overview({ unit: "<unit>", only_mismatches: true, limit: 50 });
return o;
```

Confirm no neighbouring function regressed. If a header changed, say which other units
could be affected.

## Step 6 - independent review

Hand off to `nsmb-reviewer`. It rebuilds, re-diffs, and checks the diff for unrelated
changes, contribution rules, the NitroSDK prohibition, and any source trick that games the
match.

**Do not trust the matcher's own report.** The reviewer exists because a confident wrong
claim of 100% is the failure mode that matters.

## Step 7 - report

Numbers, deltas, and the best percentage. Then state plainly what is left, if anything.

```
SYMBOL     : System::uploadSubBGState
unit       : src/system/vblank
source     : src/system/vblank.cpp
baseline   : 63.20%
current    : 84.10%
best       : 84.10%   (best source preserved in .decomp-ai/best/, rev 9c7c0b3)
attempts   : 3   (1 regression, reverted)

attempt 0  63.20%   baseline
attempt 1  71.80%   +8.60   byte dirty flag tested against 0
attempt 2  70.40%   -1.40   regression: reordered branches -> reverted
attempt 3  84.10%  +12.70   BG offset assigned once from a combined expression

review     : independently re-measured at 84.10%; diff touches one file; no
             NitroSDK-derived reasoning; no optimiser-gaming; no regressions
             among the other 16 functions in the unit.

remaining  : the two `and`/shift sequences still differ in operand order.
next       : try the mask applied to y[] before the shift, rather than after.

NOT DONE   : not committed, not pushed, no PR. Requires human review.
```

**Never claim success on appearance.** 100% means objdiff printed 100%. Anything less is
reported as a percentage, with the remaining differences named.

## Step 8 - deliver to the fork

Once `/nsmb-review` comes back clean, ship it:

1. Work on a **feature branch**, not `main`.
2. `git status --short` - only the intended decomp source file. No ROM, `.nds`, object,
   `build/`, `extracted/`, or `mwccarm` path may appear.
3. Commit using the project's convention, which records the measured delta:
   `decomp: match <symbol> (report +N, OLD->NEW)`.
4. `git push origin <branch>`, and open a PR with `gh pr create` if you want it tracked.

`origin` is `mrzetti/nsmb`, the user's fork, and pushing there is authorised. A pull
request against `upstream` (`NSMB-Decomp/nsmb`) is a different act: it is public, NSMB
maintainers review it, and `contributing.md` applies as the contribution gate. That needs
explicit instruction for that specific PR - do not infer it from fork authorisation.

Never force-push, never `git push --all`/`--mirror`, never rewrite published history.

## Non-negotiables

- Never a bare `zig build`. Always `limited-build` or the MCP `build` tool.
- Never more than one change per measured attempt.
- Never leave a regression in the tree, and never use destructive git operations to clear
  one - `decomp-state revert` exists for this.
- Never `git push` to `upstream`, never force-push, never `git reset --hard`,
  `git clean -fd`, `git checkout --`, `git restore`, or `git branch -D`.
- Never download a ROM or `mwccarm`.
- Never weaken `.gitignore`.
- Never use NitroSDK-derived knowledge - see the `nsmb-contribution` skill.
