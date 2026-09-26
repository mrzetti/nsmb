---
name: NSMB contribution rules
description: The rules that constrain any NSMB matching work - the NitroSDK prohibition, the proprietary-data boundary, AI work stays subject to human review, and what must never be committed or pushed. Load before finalising, committing, or proposing work upstream.
---

# NSMB contribution rules

These are not style preferences. Violating them gets work rejected, and some of them are
legal boundaries rather than project taste.

## The NitroSDK prohibition

`contributing.md`, first line, marked CAUTION:

> Do not use NitroSDK libraries when contributing to this project. If it is suspected you
> relied on the NitroSDK in a pull request it will be rejected.

What this rules out:

- Using NitroSDK source, headers, libraries, or documentation.
- Using knowledge that could **only** have come from the NitroSDK. This is the part that
  matters for AI-assisted work: an explanation that happens to be right but is sourced from
  a proprietary SDK is still a rejection risk.
- Inferring Nintendo SDK implementation details from proprietary SDK sources.

What is allowed:

- This repository, including `lib/Nitro/` - which is the project's **own** minimal shim,
  not the SDK.
- The target binary, via objdiff and Ghidra.
- The compiler's observable behaviour: compile a snippet, look at the output.
- Public, non-proprietary material about ARMv5T and CodeWarrior codegen in general.

### How to stay clean

Derive everything from evidence you can point at in this repository or in the target
object. If you catch yourself reasoning "the SDK does X", stop: find out what this
repository's headers declare, or what the instructions do, instead.

When writing a report or a commit message, do not cite SDK documentation. State the
observation and the source of the evidence.

## The proprietary-data boundary

**Never commit, stage, or upload:**

- ROMs, `.nds` files
- extracted ROM data (`extracted/`)
- delinked objects, build output (`build/`)
- the proprietary `mwccarm` compiler binaries
- Nintendo SDKs
- proprietary game assets

`.gitignore` already covers all of it:

```
objdiff.json          # generated
objdiff_report.json   # generated
*.nds  *.ids  *.sav  *.mch  *.ml*  *.bin
.zig-cache
extracted/*
build/*
```

**Do not weaken these rules.** If your workflow appears to need a `.gitignore` change, the
workflow is wrong. There is no legitimate reason to track a `.nds` file or an object file.

Never `git add -f` a gitignored path. Never commit `.tools/` or `.decomp-ai/`.

### Never download proprietary prerequisites

`mwccarm` and the ROM are the user's to supply. Do not search for, fetch, or suggest
sources for them. If one is missing, report it as a missing prerequisite and continue with
everything else.

## AI-produced work and delivery

The user has authorised committing, pushing, and opening pull requests **on their own
fork**, `origin` = `mrzetti/nsmb`. `gh` is authenticated as `mrzetti` with `repo` scope.

That authorisation is scoped to the fork, and the distinction is real rather than
pedantic:

| | Fork (`mrzetti/nsmb`) | Upstream (`NSMB-Decomp/nsmb`) |
| --- | --- | --- |
| Visibility | the user's own space | **public** |
| Who reviews it | the user | NSMB maintainers |
| `contributing.md` applies | as good practice | **as the contribution gate** |
| Automated action | **allowed** | **needs explicit per-PR instruction** |

Do not treat "you may push to my fork" as "you may contribute upstream". Preparing and
staging work on the fork is the expected delivery mechanism; opening a PR against upstream
is a separate decision that the user makes per PR.

When you do ship:

- Push a **feature branch**, not `main`.
- Use the project's commit convention, which records the measured delta:

  ```
  decomp: match System::subEngineVBlankHandler (report +20, 79912->79932)
  ```

  That is: what was matched, and the report-score change. If objdiff does not confirm the
  number in the subject, the message is a finding against itself.
- Verify `git status --short` before staging. No ROM, `.nds`, object, `build/`,
  `extracted/`, or `mwccarm` path may appear.
- Never force-push, never `git push --all` or `--mirror`, never rewrite published history.

## Never destructive git operations

Without an explicit instruction, never:

```
git push upstream           # the public contribution gate
git push --force            # and -f, --all, --mirror
git reset --hard
git clean -fd               # and -fdx
git checkout --
git restore
git branch -D
```

And never delete unrelated work. The repository may have a contributor's in-progress
changes in it at any time.

Note what is **not** in that list: `git add`, `git commit`, `git push origin`,
`git checkout -b`, `git switch`, and `gh pr create` are permitted, because they ship work
rather than destroy it. Best-version preservation uses **file copies** in
`.decomp-ai/best/`, managed by `.opencode/bin/decomp-state`; it is not git, and it never
needs a destructive operation.

## What a good change looks like

- Touches **one** unit's source file, for **one** function.
- One coherent change per commit, with the reason and the measured delta. The project's
  existing history shows the convention in its commit subjects:

  ```
  decomp: match System::subEngineVBlankHandler (report +20, 79912->79932)
  decomp: match System::uploadSubBGState (report +252, 79660->79912)
  decomp: match Manhole rollForward/rollBackward via in-place compound assignment (report +644, 80534->81178)
  ```

  That is: what was matched, and the report-score change. Follow it.
- Keeps the file's existing style and idiom.
- No reformatting, no renames, no reordered declarations, no drive-by cleanups. These
  destroy the ability to attribute a score change and inflate the review diff.
- The match percentage is stated and was actually read from objdiff.

## Things that get a change rejected

- Unrelated changes bundled into a matching commit.
- Code that games the optimiser: opaque barriers, dead code, `volatile` abuse, inline asm,
  hand-placed padding.
- Undefined behaviour that happens to compile correctly.
- Anything traceable to the NitroSDK.
- A claimed match percentage that objdiff does not confirm.
- Tracked proprietary data.
