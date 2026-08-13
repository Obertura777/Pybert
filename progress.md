# Python-port move-fidelity progress

Last updated: 2026-08-13

## Goal and oracle

Make the Python port produce the same orders as the original Albert C bot.
The authoritative behavioral oracle is `all_games_albert/`, paired with board
states in `all_games/`. Existing decompiles in `Source/` are used to diagnose
logic. Additional x87 assembly for the candidate ranker has resolved its
probability operand order and zero-completed-trials threshold. Exact selection
parity still has the narrower assembly gaps described below.

Exact parity is not yet achieved. Keep this work active until broad reference
comparison proves exact move equality rather than merely legal/similar orders.

## Current verified checkpoint

- `.venv/bin/python -m pytest -q` passes: **86 tests**.
- `py_compile` passes for the changed evaluator/state/trial/test modules.
- `git diff --check` passes.
- The offline oracle harness now suppresses only the NetworkGame-only GOF
  signal. It no longer reports every successful local `diplomacy.Game` run as
  `PYBERT FAILED` because local games lack `no_wait()`.
- Reference smoke test `game_10.json`, `S1901M`, seed 42: **8/22 exact unit
  orders**, **0/7 exact power order sets**, **0 Python failures**. Albert's
  complete set occurs in Python's legal candidate pool for **7/7 powers**.
  This is a checkpoint, not evidence of full fidelity.

## Port bugs fixed in this checkpoint

1. ProcessTurn Step 3 (`C:1987–2085`)

   - `DAT_00bb7124` is the reachable/history set built at ProcessTurn entry,
     not an enemy-unit occupancy test.
   - The C block does not delete candidates. It records `ScoreSupportOpp`, or
     updates the score threshold and exits when the class-1 gate succeeds.
   - The Python comparison direction was reversed; C updates on
     `candidate_score >= threshold`, not `<`.
   - Designation slots now use C's C→A→B precedence and slot-A gates.

2. ProcessTurn Step 4 (`C:2086–2182`) / XDO

   - Added the actual per-power accepted-XDO move and hold containers.
   - XDO SUP-MTO and SUP-HLD populate those containers.
   - Step 4 now constrains candidates in the same direction as C and retains
     the own-destination-HLD exception.

3. ProcessTurn Step 5 (`C:2184–2234`)

   - `piStack_70c` is a fresh temporary set for the current fleet's candidate
     tree. It de-duplicates destinations within that list.
   - The old Python code incorrectly removed destinations already selected by
     other fleets.

4. ProcessTurn Step 6 (`C:2235–2391`)

   - Implemented both target classes 1 and 2 and the `DAT_005ee8ec == 0`
     companion-marker gate.
   - Removed the unrelated order-table/province-score substitutions.
   - Empty filtered results stay empty; Python previously restored the old
     list when every candidate was removed.
   - Implemented the registered-convoy/adjacency exception.

5. ProcessTurn convoy-swap path (`C:2757–2865`)

   - Ported the strict `(rand()/0x17)%100 > 60` gate.
   - Uses the existing `g_convoy_source_prov` binding for
     `g_SupportAssignmentMap` and stamps the C convoy-complete sentinel (`5`),
     scores, cleared leg fields, and incoming-move markers.

6. Convoy BFS gate and emission (`C:1669–1940`, `C:2715–2747`)

   - Corrected a prior audit error: the three-byte literal is `AMY`; the gate
     selects army units, not one hard-coded province.
   - Phase 2 now adds precomputed convoy-route destinations to army candidates
     and emits CTO+CVY when such a destination wins.
   - Route enumeration now admits sea neighbors when finding the first convoy
     fleet, restricts chains to fleets owned by the army's power, and excludes
     empty water from landing destinations.
   - Final CVY dispatch dictionaries now include the convoyed `target_unit`;
     without it the validator emitted malformed orders such as `F BRE C  - SPA`.

7. Comparison harness

   - Offline comparison no longer calls NetworkGame-only `no_wait()` after
     successful order generation.

8. Convoy candidate score and eligibility

   - Convoy landings now use `final_score_set` directly. The C BFS does not add
     the registered-fleet bonus used by ordinary adjacent army candidates.
   - Convoy candidates are inserted after the source/hold candidate, matching
     C control flow.
   - Convoy BFS admits only fleets occupying sea provinces. Coastal fleets can
     move at sea but cannot convoy; the old Python route enumerator admitted
     them and generated impossible chains.

9. Candidate record snapshots and refresh semantics

   - Candidate orders retain a full 30-field row snapshot, so CTO legs and
     other serializer state survive later trial/power resets.
   - Duplicate candidate identity still compares only semantic order fields;
     transient score columns cannot create duplicate move sets.
   - `RefreshOrderTable` now selects complete candidate order sets rather than
     independently sampling unit orders into impossible hybrids.
   - Its sampling weight is the `RankCandidatesForPower` probability field
     (`candidate[0x16]`), not `pressure_cost`.
   - Final submission consumes refreshed slot zero, matching
     `BuildAndSendSUB.c`, rather than bypassing it with `max(score)`.

10. Order-table layout and late evaluator pass

   - Columns 8/9 are the selected `final_score_set` int64 pair, not convoy
     legs. `EvaluateOrderScore.c:610-660` conditionally clears that pair and
     C:698 adds it to the cumulative score.
   - The CTO route layout is column 23 = leg count and columns 26/27/28 = the
     three fleet provinces. `BuildConvoyOrders` now writes the count as well
     as the legs, and full candidate snapshots retain all four fields.
   - Replaced the old movement-season reset, which erased convoy legs, with
     the C selected-score validity/history gate. Regression tests cover the
     high-history Spring clear and low-history keep paths.
   - Removed the invented CTO depth/support bonus from the final score pass;
     C instead adds destination conflict/incoming values for SUP-HLD/SUP-MTO.

11. Complete and legal candidate emission

   - A rejected convoy route can no longer leave an own unit with order type
     zero before proposal capture; it falls back to HLD.
   - Convoy-only army destinations are no longer reused as SUP-MTO targets
     unless the supporter has ordinary type-filtered adjacency. This removed
     incomplete submissions caused by validator rejection.
   - `_safe_pow` now saturates positive overflow to infinity, matching C
     floating-point behavior instead of aborting candidate ranking.

12. Candidate-coverage oracle

   - `compare_albert.py --candidate-coverage` now restores every complete
     candidate snapshot through the production serializer and validator.
   - It reports exact Albert-set coverage, best same-unit set coverage, and
     individual Albert-order coverage, separating generation failures from
     ranking/refresh failures.
   - Exact `--phase` and `--power` filters make expensive late-game traces
     bounded and reproducible.

13. BuildAndSendSUB chronology

   - The final `RankCandidatesForPower(flag=0)` and `UpdateScoreState` pass now
     runs before slot zero is read and submitted, matching
     `BuildAndSendSUB.c:287-317` before C:593-614.
   - Removed an extra pre-submit refresh and an invented reciprocal-MTO-to-HLD
     swap breaker with no C counterpart.

14. UpdateAllyOrderScore slot grouping

   - `DAT_0062cc64`, not the DAIDE press/history level, controls the 4-to-30
     selected-slot window and the candidate per-round score slots.
   - Slots are grouped by their C heat-score sum; equal sums share a
     representative slot and multiplicity instead of collapsing everything
     into slot zero.

15. RefreshOrderTable rejection walk

   - Replaced conventional weighted sampling with the C complement-threshold
     walk, including its 1-to-3 `rand()` calls and slot-zero look-ahead gates.
   - Selection retains complete candidate sets and falls back to the first tree
     record at the same C exits. Deterministic tests cover the threshold and
     fallback branches.

16. Selected-score supply-centre and support-demand gates

   - Province byte `+3` in `EvaluateOrderScore.c` is the supply-centre flag.
     Direct writer evidence is `InitPositionForOrders.c:190-210`, which counts
     nonzero byte-3 records and derives the victory threshold as `count/2+1`.
     It is neither occupancy nor terrain.
   - `DAT_00baeddc` binds to order-table field 15 (`g_support_demand`), not
     field 14. Spring SC/non-SC and the narrow Fall path now have fixtures.

17. Accepted-proposal count

   - Added `g_power_call_count` for `DAT_00b9fe88`. `send_GOF.c:104` resets it
     at the movement-turn boundary, and `EvaluateOrderProposal.c:885`
     increments it only inside the unique, non-deviating proposal gate.
   - `RankCandidatesForPower` now consumes the real per-power count instead of
     a silent all-zero fallback. A regression test proves duplicates do not
     increment it.

18. Evaluator table aliases and source-faithful passes

   - `DAT_00baedb0`, `DAT_00baedb8/bc`, `DAT_00baeddc`,
     `DAT_00baedf4`, `DAT_00baedf8`, and `DAT_00baee00` are fields
     4, 6/7, 15, 21, 22, and 24 of the same 30-field order table. Python now
     uses live views instead of detached arrays that silently diverged.
   - Field 4 is the Pass-A move probability; Pass C writes field 21. The old
     port overwrote field 4 and cleared builder-written field 24 on evaluator
     entry even though C clears the table once at trial start.
   - `DAT_0058f8e8/ec` is one signed int64 own-reach value; the old port treated
     its high dword as the unrelated ally-reach array. The fallback comparison
     and negated per-power maximum score now match C.
   - Replaced Pass A's invented attack-vs-defense heuristic with the decompiled
     C:143-258 formulas. `FUN_0040e890` at this site is the x87 power helper;
     its visible exponent dword is double `0.3`, applied after integer-dividing
     field 17's move history by ten.
   - Ported the missing three-round destination-probability relaxation and
     corrected the following fleet propagation to use sea rows, fleet-valid
     adjacency, and the adjacent province's home-power membership.
   - Corrected the cut-support pass: it is gated by field 13, is not clamped,
     uses the evaluated power's enemy-reach row, and writes positive own excess
     versus negative enemy excess with the C field-13/14/15 gates.
   - The final score pass now walks all province rows, adds field 24 whenever
     positive, uses home-centre membership for Fall's +100, preserves signed
     field-18 contributions, and applies the 0.4 bonus to the C fields.

19. `FUN_00424850` candidate ranker body supplied and mapped

   - Replaced the inferred Pareto pass with the decompiled iterator/erase
     behavior: candidate field `0x13` selects the `100/50/0` dominance margin,
     field `0x51` means dominated, and dominated temporary-tree nodes are
     removed before probability scoring.
   - Probability scoring now starts its cumulative pool at zero and reads the
     adjusted-score key from up to three following surviving tree nodes. The
     otherwise-unused `1.8/(unit_count+1)+1.75` local is the x87 power curve.
     Assembly at `0042502d`, `00425108`, and `004251e2` proves that each call
     loads the adjusted-score difference first and the curve second. The same
     calling convention as the proven `FILD(score); FLD(0.5)` square-root
     sites yields `(current_key - following_key) ** curve`.
   - Corrected record layout from `TrialEvaluateOrders`: field `0x13` is
     `g_other_score`, field `0x15` is the combined rank penalty, field `0x16`
     is the ranker weight, and field `0x71` is the smoothed output score.
     New records now receive the C defaults `min_rank=10000`,
     `running_avg=10000.0`, and zeroed flags/weights.
   - `UpdateAllyOrderScore` now writes its new alliance result to live field 9
     while preserving the base evaluator score in field 8. The three 30-slot
     arrays now begin zeroed, as constructed by `EvaluateOrderProposal`; the
     previous port incorrectly seeded Pareto slot zero with the base score.
   - Helper evidence for `FUN_00419fa0` retains descending traversal: its
     `_Addleft = node.key < new_key` descent is the `std::greater` ordering.
   - The reused `local_b8` stack slot is initialized with raw dword `1` for
     the Pareto rank pass; Ghidra's function-wide float type rendered that as
     `1.4013e-45`. Candidate min/max ranks therefore begin at one.
   - Assembly `0042496e–00424992` recovers the `n_trials == 0`, `flag == 1`
     cutoff as `int(1 + call_count * (1 - call_count/(call_count+3000)))`.
   - Added focused regression fixtures for dominance erasure, field-19 margin
     selection, following-key probability, raw rank initialization, and the
     recovered threshold schedule. Full suite: **86 passed**.
   - Seed-42 oracle after the source-backed ranker rewrite: game 10 `S1901M`
     is **8/22** per-unit, **0/7** exact, with Albert's complete set generated
     for **7/7** powers; Turkey `S1907M` remains **2/3**, with the exact Albert
     set present among all 66 candidates. This is a behavioral regression from
     the old inferred opening ranker (9/22), but the removed behaviors directly
     contradicted the supplied C body.

## Remaining exact-parity blockers

- The supplied x87 assembly and constant bytes now prove the complete ranker
  threshold schedule. `004afd98` is double `0.6`, `004afda0` is `0.078`, and
  `004afdb0` is `0.05`; rounds 1–7 use
  `int(base + call_count*integer_gate*(0.6 - trials*0.078))` and rounds 8+
  retain `base = int(0.05*call_count + 5)`.
- Python collapses `BuildAndSendSUB.c`'s proposal/broadcast outer loop to one
  pass. Consequently `g_n_trials_completed` (`DAT_0062cc64`) stays at zero,
  while C increments it after every completed proposal round. Restoring that
  loop is required for round-indexed EMA, score history, and RNG parity.
- No Albert binary, assembly listing, Ghidra project, or RNG trace is present
  in the repository. Final exact slot selection remains seed/trace-sensitive
  even where the exact Albert order set is already generated.

## Reference evidence after convoy repair

Seed 42, selected movement positions from `all_games_albert/game_10.json`:

- `S1902M FRANCE`: Python now emits a coherent convoy pair
  `F MAO C A POR - SPA` + `A POR - SPA VIA`; Albert chose NAF instead. Unit
  equality remains 2/5.
- `S1907M TURKEY`: the exact Albert set is generated as a coherent candidate,
  including `F BLA C A CON - SEV`, `A CON - SEV VIA`, and ARM's support.
  After the evaluator fixes, refreshed slot zero selects the same CON→SEV
  convoy and BLA convoy order but chooses `A ARM - SMY` instead of Albert's
  `A ARM S A CON - SEV`, so final equality is **2/3**.
- `S1902M RUSSIA`: remains 1/6 and does not select Albert's SEV→BUL convoy.
  The closest of 997 legal Python candidates matches 5/6 units; all six Albert
  unit orders appear individually, but their exact combination does not.

All three positions now submit one legal order per unit. These results prove
that convoy paths are reachable and serialized; they do not prove ranking
fidelity.

Bounded candidate-coverage runs, seed 42:

- `game_10.json`, `S1901M`: Albert set generated **7/7**; submitted result
  was **0/7 exact sets**, **9/22 unit orders** after the evaluator rewrite;
  after the supplied ranker body it is **0/7**, **8/22**. The unchanged 7/7
  coverage isolates selection/ranking and missing proposal/RNG context.
- First three lexicographic games, `S1901M`: Albert set generated **19/21**;
  submitted result **1/21 exact sets**, **21/66 unit orders**. The two missing
  sets still have complete individual-order coverage and differ from the
  closest Python candidate by one unit.

Oracle limitation: these three files contain the same standard opening board,
but their Albert opening orders differ. The harness reconstructs phase board
state and runs NO_PRESS; it does not replay message history, C's prior RNG call
sequence, or an observed C seed. Therefore a fixed Python seed cannot make
those varying rows a deterministic exact-output oracle. Candidate coverage is
still useful, and exact final-order comparison becomes meaningful only after
the original run context/RNG state is reproduced or captured.

## Next work, in priority order

1. Restore `BuildAndSendSUB`'s proposal/broadcast outer loop so
   `g_n_trials_completed` advances at the C site and round-indexed ranker/ally
   state is actually exercised.
2. Recover the Albert reference-generation procedure: C RNG seed/call sequence,
   press/history replay, and any persistent-game state used when producing
   `all_games_albert/`. Without that metadata, varying expected outputs for an
   identical opening board cannot be reproduced by a stateless fixed-seed run.
3. Trace the two opening exact-set coverage misses and
   Russia `S1902M` as candidate-combination bugs; their individual orders are
   already reachable.
4. Validate the remaining signed-int64 edge cases in
   `EvaluateOrderScore.c:610-660`; focused SC/non-SC, Spring/Fall, history, and
   attack-count fixtures cover the normal values, but unusual negative/high
   dword states have no corpus oracle.
