# Python-port move-fidelity progress

Last updated: 2026-08-13

## Goal and oracle

Make the Python port reproduce Albert's order-generation logic. Exact selected
orders are not required when the difference is caused by an unavailable PRNG
seed/call offset. The structural behavioral oracle is therefore complete legal
candidate-set reachability in `all_games_albert/`, paired with board states in
`all_games/`; submitted-order equality remains diagnostic only.

Existing decompiles in `Source/` are authoritative for control flow, writers,
and data ownership. Candidate coverage must prove that Albert's complete order
combination can be produced, not merely that every component order appears in
some unrelated candidate.

## Current verified checkpoint

- `python -m pytest -q` passes: **104 tests**.
- `py_compile` passes for the changed evaluator/state/trial/test modules.
- `git diff --check` passes.
- The offline oracle harness now suppresses only the NetworkGame-only GOF
  signal. It no longer reports every successful local `diplomacy.Game` run as
  `PYBERT FAILED` because local games lack `no_wait()`.
- Generation smoke test `game_10.json`, `S1901M`, after removing invented
  self-proposals: Albert's complete set occurs in the seed-1 legal candidate
  pool for **7/7 powers** (699 complete legal candidates total), with **0
  Python failures**.
- Hard combination test `game_10.json`, `S1902M`, Russia: the complete Albert
  six-order set, including `SEV-BUL VIA`, `BLA C SEV-BUL`, and
  `RUM S SEV-BUL`, occurs at seed 0. The union of seeds 1 and 0 contains 1,868
  legal candidates and reaches **6/6 as one complete candidate**.

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
   - `--candidate-seed-count N` can now union legal candidate pools from CRT
     seeds `0..N-1` only after the primary seed misses. Submitted-order output
     remains tied to `--seed`; the report records every tried seed. This
     separates a structural generation failure from finite Monte-Carlo sample
     coverage instead of conflating the two.
   - Coverage-only follow-up seeds bypass BuildAndSendSUB's 30 scoring rounds
     because ProcessTurn has already materialized the complete candidate
     snapshots. The serializer reuses one isolated state and clears all own
     order rows between records rather than deep-copying the full analysis
     state per candidate. On Russia `S1902M`, generation now takes about 2.2s
     per seed instead of roughly 130s for the former end-to-end diagnostic.

13. BuildAndSendSUB chronology

   - Restored the complete per-broadcast proposal loop. Each node resumes its
     own `trial_count`; each iteration sets `g_n_trials_completed`, executes
     round-zero `RankCandidatesForPower(flag=0)`/refresh exactly once, runs
     `UpdateScoreState`, snapshots candidate field `0x71` into `0x17+round`,
     dispatches scheduled press, and only then increments the counter.
   - Slot zero is read and submitted after the primary node reaches the trial
     cap, matching `BuildAndSendSUB.c:217-373` before C:593-614. Empty
     no-press Python broadcast lists use an ephemeral equivalent of C's base
     SUB node without persisting stale press state.
   - MTL interruption leaves a node at its last completed round so a later
     call resumes rather than restarting. Regression tests cover chronology,
     history writes, resume behavior, and timeout.
   - Removed an extra pre-submit refresh and an invented reciprocal-MTO-to-HLD
     swap breaker with no C counterpart.

14. UpdateAllyOrderScore slot grouping

   - `DAT_0062cc64`, not the DAIDE press/history level, controls the 4-to-30
     selected-slot window and the candidate per-round score slots.
   - Slots are grouped by their C heat-score sum; equal sums share a
     representative slot and multiplicity instead of collapsing everything
     into slot zero.
   - Ported `DAT_0062e4b4`'s selected-slot accumulator and `DAT_0062e45c`'s
     duplicate-group accumulator, plus the three BuildAndSendSUB per-round
     diagnostic arrays and their previous-value snapshots.
   - Vectorized the fixed 7×7×256 threat aggregation in
     `EvaluateAllianceScore`. This preserves C's eligible-row max/sum while
     reducing a bounded opening-power run from 32.1 seconds under profiling
     to 3.7 seconds in the normal harness.

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
     recovered threshold schedule.
   - Pre-CRT seed-42 oracle after the source-backed ranker rewrite: game 10 `S1901M`
     is **8/22** per-unit, **0/7** exact, with Albert's complete set generated
     for **7/7** powers; Turkey `S1907M` remains **2/3**, with the exact Albert
     set present among all 66 candidates. This is a behavioral regression from
     the old inferred opening ranker (9/22), but the removed behaviors directly
     contradicted the supplied C body.

20. Process-global MSVC CRT random stream

   - Replaced Python's Mersenne Twister at every recovered C `_rand()` site
     with the shared MSVC recurrence
     `state = state*214013 + 2531011 (mod 2^32)`, returning
     `(state >> 16) & 0x7fff`.
   - Direct C expressions retain their exact `(rand()/0x17) % N`
     transformation. The `RandUpTo(n)` call in `RESPOND.c` is half-open
     `0..n-1`, not Python's former inclusive `randint(0,n)`.
   - The recovered source set has no `srand` call. The compatibility stream
     therefore defaults to the MSVC CRT's seed 1, with explicit
     seed/getstate/setstate hooks for captured-trace replay and the oracle.
   - All board, Monte-Carlo, refresh, hold-support, hostility, and reconstructed
     press call sites consume one process-global stream. Known CRT outputs for
     seed 1 (`41, 18467, 6334, 26500, 19169`) and state replay have regression
     tests.

21. Signed-int64 evaluator edges

   - `g_attack_count` (`DAT_006040e8/ec`) and `g_attack_history`
     (`DAT_005a48e8/ec`) are now stored as `np.int64`, matching their C
     two-dword representation. Their writers already produce integer weights
     or `FloatToInt64` results; the former float64 arrays could not preserve
     arbitrary low dwords once values exceeded `2^53`.
   - `EvaluateOrderScore.c:610-660`'s high/low-word history test reduces
     exactly to signed-int64 `history < 11`; the Fall destination test reduces
     to signed-int64 `attack_count <= 0`. Python now compares integers without
     a float conversion.
   - Boundary fixtures cover history `-1`, `10`, `11`, and `2^32`, plus a
     negative destination attack count on the narrow Fall MTO/CTO keep path.
     Full suite: **96 passed** at that checkpoint.

22. Movement-turn broadcast lifecycle

   - `GenerateAndSubmitOrders.c:92-101` destroys and reinitializes the
     `DAT_00bb65ec/f0/f4` broadcast tree at function entry. This disproves the
     earlier accumulate-forever assumption. Python now clears prior-phase
     nodes during `synchronize_from_game`, before `_drain_incoming_press`
     registers the current phase's messages.
   - The C routine explicitly inserts a fresh key-zero base SUB record before
     hostility. Python now creates that real node instead of relying on an
     ephemeral BuildAndSendSUB substitute.
   - `send_GOF.c:170-267` normalization is ported: every key-zero record is
     rebuilt as unsent SUB at trial zero (including clearing its received
     byte and score/history payload); type-1 self proposals retire as
     `type_flag=-1`, `trial_count=cap`, `sent=true`; unsent received type-0
     records rewind to trial zero.
   - A regression fixture covers all node classes. The production seed-1
     opening remains **8/22** unit matches with no Python failures and runs in
     21.7 seconds. Full suite: **97 passed**.

23. Removed synthetic no-press proposal injection

   - Writer tracing proves `GenerateOrders.c` only initializes and finally
     serializes its local order tree; it never inserts into that tree or the
     per-power proposal globals. `ScoreOrderCandidates.c` clears those globals
     and repopulates them only from its press order-list inputs.
   - The Python-only `generate_self_proposals` path greedily preassigned moves
     to other powers in NO_PRESS games. That changed the simulated board and
     could suppress combinations that C's ProcessTurn Phase 2 would otherwise
     generate. Production no longer calls or exports it.
   - Proposal preparation is now a tested boundary: it destroys stale general,
     alliance, and candidate records, translates current received press when
     enabled, and leaves both proposal trees empty in NO_PRESS mode.
   - Source-backed generation checks pass: standard opening complete-set
     reachability is **7/7** at seed 1, and Russia `S1902M`'s previously rare
     six-order convoy/support combination is complete at seed 0. Full suite:
     **98 passed**.

24. WIN adjustment candidate identity and coverage

   - `ScoreOrderCandidates_OwnPower.c` iterates candidate keys containing a
     province at `+0x10` and an AMY/FLT coast token at `+0x14`. Python had
     collapsed this to province only and then forced every coastal build to a
     fleet, making Albert army builds at TRI, SEV, PAR, and MAR unreachable.
   - Build generation now preserves the full `(province, unit type, coast)`
     identity: every eligible home centre admits an army, coastal centres also
     admit fleets, and multi-coast fleet variants remain distinct. Complete
     sets still prohibit two builds in one province.
   - WIN candidate membership is now separate from its signed strategic score.
     The old `score > 0` proxy silently dropped valid zero/negative build or
     removal nodes even though C's ordered-set node exists independently of its
     score payload.
   - Corrected reversed symbol attribution: `send_GOF.c` calls
     `FUN_0044bd40` for builds and `FUN_00442040` for removals.
   - `compare_albert.py --candidate-coverage` now enumerates complete legal
     adjustment and retreat sets as well as movement snapshots. On game 10 `W1901A`, all
     four reference power sets are reachable (**4/4**) despite selected-build
     differences; Russia `W1903A` removal generation and selection are exact
     (**2/2 orders**). Retreat smoke `S1902R` is also exact.
   - Across every game 10 retreat/adjustment reference, **30/31** complete sets
     are generated. The sole miss is an inconsistent input pair: the supplied
     `S1904R` state restricts `A ROM` to `APU`, while the Albert output is
     `A ROM R VEN`; a generator correctly consuming that NOW state cannot emit
     VEN. Full suite: **104 passed**.

## Selection-context limitations (not generation blockers)

- The supplied x87 assembly and constant bytes now prove the complete ranker
  threshold schedule. `004afd98` is double `0.6`, `004afda0` is `0.078`, and
  `004afdb0` is `0.05`; rounds 1–7 use
  `int(base + call_count*integer_gate*(0.6 - trials*0.078))` and rounds 8+
  retain `base = int(0.05*call_count + 5)`.
- No Albert binary, assembly listing, Ghidra project, reference-generation
  script, or RNG-state trace is present in the repository. The 63 external
  `all_games_albert` files are ignored by Git and contain only phase/power
  order lists. Their paired source games contain board states and human press,
  but no Albert seed or serialized bot state.
- The PRNG algorithm is now source-faithful, but final slot selection still
  depends on the reference process's call history. `send_GOF.c` also consumes
  a sleep-jitter draw only on positive-time-limit phase branches; that draw
  must be replayed from actual TME/timing state, not burned unconditionally by
  the stateless offline harness.

## Reference evidence after convoy repair

Pre-CRT seed 42, selected movement positions from
`all_games_albert/game_10.json`:

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

Historical single-pool candidate-coverage runs, pre-CRT seed 42:

- `game_10.json`, `S1901M`: Albert set generated **7/7**; submitted result
  was **0/7 exact sets**, **9/22 unit orders** after the evaluator rewrite;
  after the supplied ranker body and restored 30-round proposal loop it is
  **0/7**, **8/22**. The unchanged 7/7 coverage isolates selection/RNG and
  missing reference context. The full opening checkpoint runs in 23.0 seconds.
- First three lexicographic games, `S1901M`: Albert set generated **19/21**;
  submitted result **1/21 exact sets**, **21/66 unit orders**. The two missing
  sets still had complete individual-order coverage and differed from the
  closest Python candidate by one unit. A controlled follow-up disproved these
  as structural gaps: `game_100` Italy's complete set occurs at seed 0 and
  `game_1000` Russia's at seed 2. The new multi-seed coverage mode reports both
  as generated while leaving primary-seed submission unchanged.

Oracle limitation: these three files contain the same standard opening board,
but their Albert opening orders differ. The harness reconstructs phase board
state and runs NO_PRESS; it does not replay message history, C's prior RNG call
sequence, or an observed C seed. Therefore a fixed Python seed cannot make
those varying rows a deterministic exact-output oracle. Candidate coverage is
still useful, and exact final-order comparison becomes meaningful only after
the original run context/RNG state is reproduced or captured.

## Next generation-logic work, in priority order

1. Expand complete-candidate coverage across a bounded sample of opening and
   midgame movement positions, sweeping seeds only after a primary-pool miss.
2. Expand retreat and adjustment coverage beyond the verified game 10 smoke
   cases; adjustment candidate enumeration now supports this directly.
3. Audit full-press replay inputs independently of PRNG selection. Received
   XDO/ALY/DMZ state may intentionally constrain generated movement candidates,
   so coverage needs the matching message history rather than board-only
   NO_PRESS reconstruction.
