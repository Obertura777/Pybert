# Python-port move-fidelity progress

Last updated: 2026-09-01

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

- `python -m pytest -q` passes: **394 tests**.
- `python -m compileall -q` passes for the repository's Python source and
  tests.
- `git diff --check` passes.
- The offline oracle harness now suppresses only the NetworkGame-only GOF
  signal. It no longer reports every successful local `diplomacy.Game` run as
  `PYBERT FAILED` because local games lack `no_wait()`.
- Latest bounded generation oracle, `game_10.json`, `S1901M`, primary seed 1
  plus seeds 0–9 for misses:
  Albert's complete set occurs in the legal candidate pool for **7/7 powers**
  (502 distinct complete legal candidates total), with **0 Python failures**.
  Every reference set is present at primary seed 1; no seed union is needed.
  Submitted selection remains diagnostic at **0/7 exact sets** and **10/22
  unit orders**.
- Current hard combination test `game_10.json`, `S1902M`, Russia: the exact
  **6/6** reference set appears at seed 6 among 3,196 distinct legal candidates
  unioned from seeds 1, 0, and 2–6, with **0 Python failures**. The earlier
  5/6 ceiling was a compensated scoring defect and is retired.
- First-Fall no-press checkpoint, `game_10.json`, `F1901M`: primary seed 1
  reaches **5/7** complete Albert sets across 600 candidates; the bounded
  seeds 0–9 sweep reaches **7/7** across 639 candidates. France appears by
  seed 5 and Germany by seed 2. Diagnostic selection is **1/7 exact sets** and
  **6/22 unit orders**, with no Python failures.
- Current bounded opening sample across games 10, 100, and 1000, using primary
  seed 1: **21/21** Albert complete sets occur among 1,560 distinct legal
  candidates, with **0 Python failures**. Every game is 7/7 covered without a
  fallback seed sweep. Diagnostic submitted selection is **0/21 exact sets**
  and **25/66 unit orders**.
- The first three reference games' complete retreat/adjustment sweep reaches
  **155/156** sets across 156 phase/power pairs. The sole miss is the known
  inconsistent game 10 `S1904R` pair (`A ROM R VEN` in the reference while
  the paired NOW state permits only `APU`).
- `python compare_albert.py --audit-press-inputs` proves that the 63 paired
  games contain 13,291 messages in reference phases but **zero** structured
  DAIDE press messages. Their human free text cannot reconstruct received
  XDO/ALY/DMZ state.

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

25. Deterministic press-port fidelity

   - Re-audited the recovered press functions against the C bodies without
     changing PRNG-based decisions. Token-sequence helpers now implement exact
     ordered equality; evaluator dispatch preserves nested DAIDE sublists and
     NOT-XDO polarity; the PRP token is the recovered `0x4a13` value.
   - PCE, DMZ, ALY, SLO, DRW, AND, CAL_VALUE, cancellation, scheduled dispatch,
     and response timing now follow the recovered control flow and hidden
     participant context.
   - Reconstructed the proposal-analysis record correctly: `+0xc` is the
     participant-power map, `+0xf` the affirmative map, and `+0x12` the
     rejection/deviation map. Proposal dedup includes participant identity,
     acknowledgements update the proper set, and GOF processing waits until
     every participant has affirmed.
   - Fifteen focused source-backed press regressions plus the integrated Albert
     harness pass. No diff touches a recovered `_rand()` call site.

26. Bounded movement candidate-coverage expansion

   - Used the production candidate generator, full-row snapshot restorer,
     serializer, and validator while bypassing only the selection rounds that
     cannot affect candidate reachability.
   - At that checkpoint, games 10, 100, and 1000 `S1901M` reached **21/21** complete Albert sets
     under the bounded seed order `{1,0,2}`. Most are present at seed 1;
     game 100 Italy and Austria and game 1000 Russia and Austria require the
     seed-0 follow-up pool.
   - Game 10 `S1902M` then reached **7/7** complete sets under the same bounded
     sweep. France, Italy, and Turkey are present at seed 1; England, Austria,
     and Russia appear by seed 0; Germany appears by seed 2. There were no
     generation failures.
   - These are historical results, not the current verification baseline. The
     token-key and source-ordered convoy corrections changed the finite
     candidate pools; section 36 records the current game-10 evidence.

27. Expanded retreat and adjustment coverage

   - Swept every retreat and adjustment reference pair in the first three
     lexicographic games: 102 adjustment pairs and 54 retreat pairs.
   - The reference format omits forced disbands for units with no legal retreat
     destination. The oracle now follows that convention rather than inventing
     an explicit `D`, raising complete-set coverage from **151/156** to
     **155/156**.
   - All **102/102** adjustment sets and **53/54** retreat sets are reachable.
     The remaining retreat miss is the previously documented inconsistent
     game 10 `S1904R` state/reference pair, not a legal generation gap.

28. Full-press replay input audit

   - Added `--audit-press-inputs` with a strict DAIDE syntax recognizer. It
     requires protocol structure such as `FRM (...)` or `YES (...)`, so English
     messages beginning with “Yes”, “Not”, “Try”, or “Huh” are never fed into
     the DAIDE parser accidentally.
   - Across all 63 paired references, 50 games are marked full press and 13 no
     press. Their reference phases contain 13,291 messages, but none is a DAIDE
     envelope or structured DAIDE body; every message is human free text.
   - Consequently the current artifacts cannot reproduce Albert's received
     XDO/ALY/DMZ constraints or historical press state. Board-only NO_PRESS
     candidate coverage remains the only evidence-backed oracle until a DAIDE
     history, Albert state snapshot, or deterministic human-to-DAIDE translator
     is supplied.

29. Long-turn WebSocket and reconnect resilience

   - NetworkGame phase synchronization stays on the owning asyncio loop, while
     CPU-heavy Monte Carlo/order generation runs in a worker thread. This lets
     Tornado service WebSocket ping/pong traffic even when a turn takes longer
     than the server's 60-second ping timeout.
   - `set_orders`, GOF/`no_wait`, press messages, and draw votes are marshalled
     back to the connection's owning loop; inbound phase and press callbacks
     are serialized so the worker cannot race the next turn's state update.
   - Stale queued phase notifications are discarded before synchronization and
     generation, preventing an old scoring task from submitting into a newer
     phase.
   - The adjacent diplomacy server now atomically transfers a reconnecting
     bearer token from its old WebSocket handler to the new one. A delayed
     `on_close` for the old handler can no longer detach the replacement or
     trigger the former `attach_connection_handler` assertion.
   - Focused client and server concurrency regressions pass; the full Pybert
     suite passes **129 tests**.

30. Candidate alliance-score return path

   - `EvaluateAllianceScore.c` returns the evaluated candidate's aggregate
     score through its own-power accumulator; the per-opponent score array is
     separate and deliberately does not write its own-power cell. Python
     discarded the return value and read that zero cell, flattening every
     candidate's alliance score to zero.
   - The flattening made `RefreshOrderTable` fall back to candidate insertion
     order. Germany's early KIE-hold candidate consequently won every movement
     phase in game `ccBIQmLtvm9Gdz5m`, even though higher-scoring complete
     candidates moved the unit.
   - The evaluator now returns the aggregate score, and
     `UpdateAllyOrderScore` combines it with the preserved field-8
     `EvaluateOrderScore` component. On the standard-opening seed-1 regression,
     Germany changes from `F KIE H` to `F KIE - BAL`; all three submitted
     German orders are moves.

31. In-turn press response lifecycle

   - Inbound `GameMessageReceived` notifications that arrive during Monte Carlo
     can no longer miss `BuildAndSendSUB` and then disappear when the next phase
     clears `g_broadcast_list`. The client drains the live NetworkGame message
     history after generation and runs a response-only pass before phase-ready.
   - GOF/`no_wait()` is deferred while generation owns the bot state and is
     released only after current-turn proposals have been parsed and answered.
     Messages arriving while the bot is otherwise idle use the same serialized
     response-only path immediately.
   - `GOF` and `NOT(GOF)` are terminal server readiness controls in the client
     adapter: `GOF` calls `NetworkGame.no_wait()` and `NOT(GOF)` calls
     `NetworkGame.wait()`. Neither token can fall through to power-to-power
     `send_game_message()` fan-out.
   - Callback and history copies share a four-field message identity including
     the body, while the two registration records for one proposal share a
     phase-scoped response key. Each valid proposal is therefore answered once,
     without losing distinct same-timestamp messages.
   - `run_7bots.py` now records inbound parser, gate, scheduling, and outbound
     press DEBUG events in `games/debug.log` while keeping console output at
     INFO or above.
   - Regression coverage proves a PRP received during generation is answered
     before `no_wait()`, duplicate delivery is ignored, two-pass registration
     produces one reply, and `PRP ( PCE ( ENG FRA ) )` produces a directed
     `YES ( PRP ( PCE ( ENG FRA ) ) )` response.

32. C-faithful outbound press reachability

   - Audited every recovered outbound `SendDM`/`PROPOSE` call site. Server
     controls remain server controls: SUB maps to `set_orders`, DRW maps to a
     draw vote, and GOF/`NOT(GOF)` map to `no_wait()`/`wait()`. They are never
     power-to-power communication messages.
   - The negotiable outbound forms are `PRP(PCE)`, `PRP(ALY ... VSS ...)`,
     `PRP(DMZ)`, and `PRP(XDO)`, plus directed YES/REJ/BWX/HUH replies. XDO is
     a proposal body inside PRP, not a raw top-level wire message.
   - Fixed the XDO producer/consumer disconnect. BuildSupportProposals records
     now persist in the C-equivalent proposal-history map, THN dispatch selects
     records for Albert's own proposed move and the recipient's supporting
     unit, validates the order as that recipient power, and sends a directed,
     tracked `PRP(XDO)`. The invented broadcast-record conversion is now a
     compatibility no-op instead of manufacturing zero-score AllianceRecords.
   - Fixed the DMZ record layout and gates: `g_order_list` now writes C's
     node[5] power field, the three packed flags use their recovered meanings,
     threshold comparison is strict, and `GameBoard_GetPowerRec` checks the
     per-power counter-designation map rather than supply-center ownership.
     DMZ sends now go through `PROPOSE`, so YES/REJ acknowledgements match the
     same in-flight proposal ledger as PCE/ALY/XDO.
   - A real standard-opening generation produces valid directed XDO requests
     from Austria to Germany and Italy (`... MUN SUP VIE MTO TYR ...` and
     `... VEN SUP VIE MTO TYR ...`) with no mocked score or serializer path.
     Focused reachability and acknowledgement regressions pass; the complete
     suite passes **135 tests**.

33. Token-keyed province-score tree fidelity

   - Replaced the admitted `g_candidate_scores` iteration shortcut in
     `ScoreOrderCandidates_AllPowers` with the recovered round-zero key-tree
     domain. `GenerateOrders`' top-N table is a separate global and cannot
     suppress scores for valid province/token keys.
   - Modelled the C tree's `(province, token)` identity as AMY and fleet score
     channels, but normalised both channels together per power. The C object
     has one `+0x4000` tree per power, so separate channel maxima and thresholds
     were incorrect. Zero/minimum-key handling and the AMY shortfall pass now
     follow the same shared population.
   - Removed the invented fleet-only `g_MaxProvinceScore`. C collapses every
     token key into the one per-power/per-province maximum consumed by convoy
     fleets. Restored Spring round-9 weight `1000`; the constructor dump already
     proved this constant, so the temporary corpus-tuned value `1` was not a
     valid porting change.
   - Army BFS diffusion now applies AMY terrain filtering rather than crossing
     water through generic adjacency. Support, safe-reach, alliance scoring,
     enemy prediction, and late support conversion select destination scores
     using the moving unit's token, never the destination occupant's type.
   - Added focused regressions for shared army/fleet normalisation, round-zero
     tree membership independent of the top-N table, the shared convoy-fleet
     maximum, and source-token support lookups. Full suite: **141 tests**.
   - On `game_10.json` `S1901M`, bounded seed coverage returned to **7/7**
     complete Albert order sets after the tree-domain correction (the prior
     partially keyed implementation reached only 5/7). Exact submitted orders
     remain selection/RNG diagnostics, not the structural oracle.

34. Token-keyed candidate weights and alliance evaluation

   - Recovered the second half of the `DAT_00baed7c` record. Each
     `(province, unit/coast token)` node holds the base per-power score in slots
     `0..6` and the live candidate weights in slots `21..27`; the old
     one-dimensional `g_hold_weight` approximation had no C reader.
   - `EnumerateHoldOrders` now clears the live AMY/FLT weight channels once,
     preserves the reach matrices, and seeds each occupied unit key's owner
     with C's weight `30`. `UpdateAllyOrderScore` clears and rebuilds those
     channels for every candidate from committed source/destination/expansion
     keys, then projects their type-filtered adjacency into the primary and
     fleet pressure arrays using the recovered supply-center/army-occupant
     gate.
   - `EvaluateAllianceScore` now totals the live key weights, applies each
     key's weighted base score and sustained-attack premium, and performs the
     recovered sea-record fleet-chain pass. That pass follows fleet adjacency
     but requires a positive adjacent AMY-key weight; it no longer substitutes
     the static own-reach matrix or merely scans current fleet units.
   - The follow-on `BuildSupportOpportunities` audit found two province-only
     adjacency walks after the correctly filtered first leg. Both later legs
     now retain the moving unit's AMY/FLT filter, matching C's repeated
     `AdjacencyList_FilterByUnitType` calls. Province identity remains adequate
     for Python consumers because the actual supporter's type/coast is checked
     again immediately before order emission.
   - The threat-path pass was also still treating the province-record SC flag
     as unit occupancy and reading only the AMY score channel. It now scans
     threatened supply centres, applies C's adjacent reach and own-army gates,
     and consumes the shared maximum across token keys.
   - Candidate staging now restores the common semantic order fields for both
     ally and own snapshots. Support destinations are no longer overwritten by
     the secondary-unit field or left at province zero before key weighting.
   - Eight focused regressions cover hold seeding and reach preservation,
     evaluator consumption, source-key writes, primary-versus-fleet pressure
     routing, support-destination reconstruction, and rejection of a land-only
     fleet triangle, plus the positive and blocked threat-path cases. Full
     suite: **149 tests**.
   - The bounded `game_10.json` `S1901M` seed sweep still reaches **7/7**
     complete Albert sets after these changes, across 796 legal candidates.
     Submitted selection is **0/7 exact**, **6/22** unit orders, as expected for
     the still-unreconstructed RNG/press context; it is not the structural
     oracle.

35. ProcessTurn support-opportunity / `g_other_score` lifecycle

   - Corrected the historical interpretation of `DAT_00bbf644/648`: these are
     the object and tree head of the same `std::map<int, int>`, populated by
     ProcessTurn Step 3 through `ScoreSupportOpp(source, destination)` and read
     again by the late C:3695–3746 scoring pass. The Python-only,
     never-populated `g_trial_list2` container has been removed.
   - ParseNOWUnit.c:155–159 proves the late pass iterates Albert's own
     standard-form units. It no longer filters for other powers or changes the
     scanned unit set with the currently simulated power.
   - Restored the exact destination gates: target class 1 with a zero companion
     marker, plus `g_province_score_trial[dest] == 0` for armies (fleets retain
     C's exception). A matched map value contributes only when its destination
     has no incoming move.
   - Three focused regressions cover the complete Step-3-to-late-scan map
     lifecycle, the army/fleet registered-convoy distinction, and rejection of
     companion-marked or non-Albert units. Full suite: **152 tests**.
   - The bounded `game_10.json` `S1901M` sweep remains structurally unchanged:
     **7/7** complete Albert sets across 796 legal candidates, with zero Python
     failures. Submitted selection remains **0/7 exact** and **6/22** per-unit.

36. Source-ordered convoy routes and constructor-weight regression

   - Replaced the generic graph-frontier convoy helper with ProcessTurn's
     actual depth-1..3 walk. Each depth scans the live
     `g_convoy_fleet_candidates` tree in iterator order, takes the first
     adjacent route at the preceding depth, and exposes that fleet's land
     neighbours. This preserves C's deterministic same-depth tie breaking.
   - Route membership now comes from the current trial's unordered-unit tree,
     so a fleet absent from that tree cannot convoy. The per-army route entry
     is replaced immediately before candidate construction and the same route
     is consumed by final dispatch; stale generation/pre-trial routes cannot
     select already-committed fleets.
   - C's landing gate checks terrain, not occupancy. Python now retains attacks
     on coastal provinces occupied by fleets, while preserving depth-zero
     direct army destinations as ordinary MTO candidates.
   - Oracle verification exposed a separate live worktree regression:
     `g_spr_round_weights[9]` had been corpus-tuned from `1000` to `1`, despite
     the recovered constructor stores proving that SPR and FAL both use EAX =
     `0x3e8` in round 9. Restored `1000` and added a constant regression test;
     empirical output improvements are not substitutes for source fidelity.
   - Four convoy regressions cover occupied coastal landings, depth-zero direct
     moves, live-tree order/membership, and stale-route replacement. Together
     with the constructor fixture, full suite: **157 tests**.
   - The corrected full `game_10.json` `S1901M` run reaches **7/7** Albert sets
     across 740 distinct legal candidates with zero Python failures; submitted
     selection is **0/7 exact**, **6/22** per-unit. The current Russia
     `S1902M` seed union `{0,1,2}` has 3,127 distinct candidates, 6/6 individual
     order coverage, and a best complete candidate of 4/6; this remains an
     explicit combination/ranking gap.

37. Descending stable candidate-tree iteration

   - `ScoreConvoyFleet.c` proves that Albert+`0x4cfc` uses
     `std::greater<int>`: a larger score descends left and a smaller or equal
     score descends right. Walking from the tree head's leftmost node therefore
     visits scores in descending order, while equal-score nodes retain insertion
     order. Python's former `bisect.insort((score, province))` reversed priority
     and invented a province-id tie break; `score_convoy_fleet` now reproduces
     the source comparator and duplicate ordering.
   - `InsertOrderCandidate.c` uses the identical comparator for the Phase-1e
     exploit/proposal tree. Its Python helper is now a module-level descending,
     stable insertion routine, and the consumption loop documents the recovered
     traversal order.
   - `MoveCandidate.c` erases the concrete iterator passed by its caller. The
     ProcessTurn rescore helper now removes only the first iterator-order match,
     rather than deleting every node that shares a province payload. The own-
     province score lookup likewise stops at the first iterator match.
   - Regressions cover descending priority, stable equal-key insertion, payload
     copy semantics, and single-node erase. Full suite: **160 tests**;
     `py_compile` and `git diff --check` pass.
   - The refreshed `game_10.json` `S1901M` oracle reaches **7/7** complete
     Albert sets across 790 distinct legal candidates with zero Python failures
     (primary seed 1, seeds 0–7 for misses). Submitted selection remains **0/7
     exact**, **6/22** per-unit. Russia `S1902M` seeds `{0,1,2}` now produce
     3,143 candidates with 6/6 individual coverage and a best complete set of
     4/6; the closest set still misses `GAL-BUD` and `WAR-SIL`, so this remains
     a combination/ranking gap rather than a missing-order defect.

38. Candidate-record tree order and duplicate semantics

   - `InsertCandidateRecord.c` is a unique BST keyed by the serialized SUB
     token sequence. Its comparator performs the usual two-way
     `FUN_00465cf0` less-than checks: new keys are inserted in lexicographic
     order, while an equivalent key returns the existing node with
     `is_new=0`.
   - Python previously kept a key map for duplicate detection but appended new
     records in trial-discovery order. C consumers walk the candidate tree in
     key order before inserting records into stable score trees, so equal-score
     ties inherited the wrong order. `insert_candidate_record` now maintains a
     parallel ordered-key index and inserts the public record list at the
     source-equivalent position. Both turn-reset paths clear that index.
   - The former duplicate branch also overwrote one `trial_scores` slot. C
     constructs `TrialEvaluateOrders` before attempting insertion and never
     copies it over the existing node when insertion reports a duplicate; the
     Python branch now returns the existing record unchanged.
   - Two focused regressions cover reverse-discovery/key-order insertion and
     immutable duplicate return. Full suite: **162 tests**; `py_compile` and
     `git diff --check` pass.
   - Behavioral coverage is unchanged: the bounded `game_10.json` `S1901M`
     run reaches **7/7** Albert sets across 790 candidates (seed 1 plus 0–7
     for Germany), with submitted selection **0/7 exact**, **6/22** per-unit.
     Russia `S1902M` seeds `{0,1,2}` remain at 3,143 candidates, 6/6
     individual coverage, and best complete coverage 4/6.

39. CAL_BOARD enemy-exclusion matrix and distressed-ally rescue

   - `CAL_BOARD.c:476–598` proves `DAT_00633780` is not the 1-indexed
     influence-rank matrix. C first counts each row's live enemies, then writes
     that count to non-enemy cells and `count - 1` to each enemy cell. Python
     initialized `g_rank_matrix` but never populated it, substituting
     `g_influence_rank_flag` at downstream reads. The port now constructs the
     exact enemy-count-with-column-excluded matrix and uses it for ally-
     distress and gang-up gates.
   - The gang-up check at C:1931/2016 is `< 3`; Python's old influence-rank
     proxy used the stricter `< 2`. The source matrix and threshold are now
     both preserved.
   - `DAT_00633f18` in the distressed-ally block is not an unavailable map-
     initialization "proximity rank." `ComputeInfluenceMatrix.c:237–238`
     proves it is the inverse of `DAT_006340c0`, already represented by
     `g_ally_pref_ranking`. Rescue now compares the distressed ally's rank-1
     and rank-2 powers with our rank-3 and rank-4 powers exactly as
     C:2087–2128 does; the invented optional proxy state was removed.
   - The rescue threshold at C:2085–2086 reads `DAT_00634e90`, the relation-
     score matrix, not the trust high word. The port now reads the correct
     channel and also implements C's reverse one-point-trust cleanup.
   - Three focused regressions cover exact matrix values, ally-distress with a
     deliberately contradictory influence rank, inverse-rank rescue,
     relation-channel selection, the `<3` boundary, and reverse-trust cleanup.
     Full suite: **165 tests**; `py_compile` and `git diff --check` pass.
   - Behavioral coverage is unchanged: `game_10.json` `S1901M` reaches **7/7**
     complete Albert sets across 790 candidates with submitted selection
     **0/7 exact**, **6/22** per-unit. Russia `S1902M` seeds `{0,1,2}` remain
     at 3,143 candidates, 6/6 individual coverage, and best complete coverage
     4/6.

40. CAL_BOARD normal-selection and late gang-up control flow

   - The generic post-selection gang-up loop did not represent either source
     site. `CAL_BOARD.c:1925–2076` is a symmetric two-branch block: feared #1
     can be the ally only while feared #2 is hostile (or vice versa), the
     trust threshold is low-word `>3`, and candidates are strictly feared #3
     then inverse-rank slot #4. Its matrix read is
     `DAT_00633780[own, opposing_top] < 3`, and its pressure gate is
     `raw[target, own] / (raw[own, target] + 1) > 1`. Python now preserves
     those operands, order, and thresholds, including the source's lack of an
     opening-ally exclusion.
   - The separate `CAL_BOARD.c:1493–1557` site only runs after feared #3 is
     validated. It can add feared #2 through a strong feared-#1 ally, or add
     feared #1 through a strong feared-#2 ally. This now has its own helper
     with the source's asymmetric `<2`/`<=1` enemy-exclusion gates, `>6`
     trust threshold, directional hostility checks, and raw-pressure ratios.
   - The normal validation branch's feared-#3 ratios and gang-up continuation
     were first restored here. The later executable-backed control-flow audit
     in checkpoint 42 corrected the direction of C:1296: a true condition
     inspects #3, while a false condition validates current enemy #2. The two
     C random draws are reused after reselection instead of being consumed a
     second time.
   - Six new regressions cover direct #3 validation, both immediate gang-up
     directions, the later block's low-word trust boundary, exact matrix
     orientation and `<3` boundary, raw ratio, and rank-four fallback. Full
     suite: **171 tests**; `py_compile` and `git diff --check` pass.
   - The bounded no-press opening oracle remains **7/7** complete Albert sets,
     **0/7** exact submitted sets, **6/22** per-unit, and zero failures. The
     Russia `S1902M` diagnostic remains 0/1 complete-set coverage and 1/6
     submitted per-unit; its established three-seed structural detail remains
     3,143 candidates, 6/6 individual orders, and best complete coverage 4/6.
     These CAL_BOARD alliance branches cannot fire in the oracle's NO_PRESS
     state because every alliance-trust value is zero.

41. CAL_BOARD directional weak-power and SC-grab passes

   - Both C:1878–1882's near-victory cleanup and C:2178–2181's normal weak-
     elimination branch use the same directional predicate:
     `raw[target, own] / (raw[own, target] + 1) > 4.5`, together with positive
     own-to-target adjusted influence and target-to-own adjusted influence
     above 10. Python reversed the normal ratio and used
     `raw[own,target] / (raw[target,target] + 1)` in the near-victory branch.
     Both sites now share the exact predicate.
   - C has two independent vulnerable-SC branches. The first fires whenever
     own projected SCs are below four; the second fires at any own size when
     `g_influence_rank_flag[own,target] > 3`. Python omitted the second branch
     and added unsupported `target_sc > 3` and `target != own` restrictions to
     the first. The port now preserves the common three contact-array gates
     and the source's two alternative conditions.
   - Enemy designation in all three cases now also performs C's reverse
     one-point-trust cleanup. Two focused regressions cover ratio orientation,
     low-SC targets, the rank-gated branch at larger own size, and reverse
     trust cleanup. Full suite: **173 tests**; `py_compile` and
     `git diff --check` pass.
   - Refreshed bounded oracles confirm unchanged structural behavior. Opening
     `game_10.json` `S1901M` reaches **7/7** complete sets across **790**
     candidates, with **0/7** exact submitted sets, **6/22** per-unit, and zero
     failures. Russia `S1902M` seeds `{1,0,2}` produce **3,143** candidates,
     **6/6** individual coverage, and a best complete match of **4/6**; its
     submitted diagnostic remains **1/6**.

42. CAL_BOARD enemy-desired gate and trust-weighted ranked selection

   - `CAL_BOARD.c:1093` jumps to function end when `DAT_00baed5f` is zero.
     Its writers and `HOSTILITY.c` log text identify this byte as the
     enemy-desired flag. Python read the value but ignored the gate, running
     ranked selection and every later gang-up/rescue/weak/alliance pass even
     while Albert would return. The exact early exit is now restored.
     Conversely, C's near-victory keep-alliance path still reaches normal
     selection; Python incorrectly skipped that block whenever the local
     `bVar26` flag was true.
   - The decompile lost the x87 expression behind `FloatToInt64` in the two
     random ranked-selection sites. Disassembly of the published 32-bit
     Albert executable at `0x429a25–0x429a58` and
     `0x42a827–0x42a865` proves the threshold is
     `int(100*a/(a+b))`, where `a = influence1/trust_divisor1` and
     `b = influence2/trust_divisor2`. Branch 4 uses divisors 1/3; the rechoose
     branch uses 1/3/4. Python ignored those divisors, added an unsupported
     `+1` denominator, and rounded Branch 4 instead of truncating. A shared
     helper now preserves the exact arithmetic. The two-front-war fallback at
     `0x429626–0x429669` is likewise confirmed as the unadjusted
     `int(100*influence1/(influence1+influence2))`.
   - C:1256–1590 can enter validation when feared #3 alone has exact-zero
     trust. Within validation, C:1296's condition means "inspect #3"; when it
     is false C validates feared #2 at 1559. Python ignored #3 at entry and
     treated the inspection condition as an immediate rechoose predicate,
     reversing the #2/#3 outcome. Both transitions now follow source control
     flow. The two-front-war branch also restores C's second peace/neutral
     marker arm before its random fallback.
   - Peace selection now enforces all C:1586–1590 entry gates, including all
     three trust pairs and the `enemy_count > 2 && deceit > 2` suppression.
     Coalition-count orientation and opening-ally count adjustments were
     confirmed already correct. The opening preservation ratio now always
     uses `influence1 + 1`, including zero influence, and every Branch 4 exit
     performs C:1804–1809's reverse one-point-trust cleanup.
   - Six new regressions cover top-3-only validation, the exact weighted
     threshold and trust tiers, the enemy-desired early return, Branch 4's
     selected side and reverse cleanup, negative-high-word peace suppression,
     and the second two-front peace-marker arm. Full suite: **179 tests**;
     `py_compile` and `git diff --check` pass.
   - Refreshed bounded oracles remain unchanged. Opening `game_10.json`
     `S1901M` reaches **7/7** complete sets across **790** candidates, with
     **0/7** exact submitted sets, **6/22** per-unit, and zero failures. Russia
     `S1902M` seeds `{1,0,2}` produce **3,143** candidates, **6/6** individual
     coverage, and a best complete match of **4/6**; submitted selection
     remains **1/6**.

43. CAL_BOARD dominance and alliance-agreement terminal passes

   - `CAL_BOARD.c:2284–2328` marks every other power as an enemy when own SC
     percentage is above 75 and leads the strongest rival by at least two.
     The port had the main threshold and forward trust clearing, but omitted
     the enemy int64 high-word write and C's conditional reverse `(lo=1,
     hi=0)` trust cleanup. The exact terminal dominance sweep is now isolated
     in a focused helper and preserves all source writes.
   - The first loop at C:2329–2345 does not maintain "one enforced enemy per
     declaring ally" state. Both the decompile and Albert.exe
     `0x42ba61–0x42ba91` show it repeatedly overwrites `auStack_dc[1..N]`,
     leaving the final power's ally-matrix row. Python omitted that surviving
     row gate and invented a mutable `pow_a_enforced` flag that stopped after
     the first target. The terminal pass now uses the exact final-row snapshot
     and can honor multiple eligible targets from one declaring power.
   - C tests both words of the declaring power's and target's enemy flags,
     reads alliance and trust from `[declaring,target]`, compares the low trust
     word as unsigned when the high word is zero, excludes the opening ally,
     then clears `[own,target]` trust and a reverse one-point marker. Python
     checked only low enemy words, used a signed low-trust comparison, and
     omitted the reverse cleanup. All operands and writes now match
     C:2353–2397 and executable addresses `0x42bae3–0x42bc2a`.
   - Four focused regressions cover dominance high-word/reverse cleanup, the
     final-power row snapshot, multiple targets from one declaration, both
     enemy words, unsigned low trust, and alliance reverse cleanup. Full
     suite: **183 tests**; `py_compile` and `git diff --check` pass.
   - The refreshed bounded opening oracle remains **7/7** complete Albert sets
     across **790** candidates, with **0/7** exact submitted sets, **6/22**
     per-unit, and zero failures.

44. HOSTILITY controlling state, split-word gates, and peace formation

   - `HOSTILITY.c:129–137` allows an otherwise high-ranked mutual enemy only
     when its enemy flag is exactly `(lo=1, hi=0)`, CAL_BOARD's
     `DAT_00baed69` near-victory flag is one, and the candidate equals
     `DAT_0062480c`. Python instead gated this exception on the enemy-desired
     byte and a duplicate committed-enemy attribute. The exact near-victory
     operands and both enemy words are now used.
   - `DAT_00b9fdd8` is shared storage: CAL_BOARD stamps the near-victory power
     across it at C:946–948, and HOSTILITY later rebuilds the same array as
     the mutual-enemy table. Python invented a nonexistent
     `g_near_victory_by_power` attribute and consequently dropped CAL_BOARD's
     writes. Both call orders now operate on `g_mutual_enemy_table`, matching
     the alias.
   - The press-on trust snapshot at C:308–323 compares the low word as
     unsigned when high is zero. Block 5's peace counter iterates all powers,
     including Albert's own slot, and tests both enemy words. Python used a
     signed snapshot comparison, skipped own, ignored enemy high words in the
     counter, changed-minds, and peace-overture loops, and reduced the int64
     counter gates to signed scalar comparisons. A common word splitter and
     exact unsigned-low/signed-high predicates now preserve C semantics.
   - C:450–458 always writes bilateral `(lo=1, hi=0)` trust after a successful
     peace overture. Python contained an oracle-oriented NO_PRESS exception
     that suppressed those writes, changing persistent hostility state. The
     unsupported exception is removed; relation clearing remains conditional
     on the prior outbound relation not being 50, exactly as in C.
   - The remaining PCE history ambiguity was resolved from Albert.exe
     `0x42f928–0x42f959`: HOSTILITY searches the fixed first tree at
     `0x00bb6e10` on every target iteration. It does not add the per-power
     stride used by `ExecuteThennAction`. Python's per-target PCE lookup is now
     the executable's fixed slot-zero lookup.
   - Seven focused regressions cover the near-victory mutual exception,
     CAL_BOARD's aliased table write, NO_PRESS bilateral trust, own-slot peace
     counting, enemy high-word suppression, peace-counter high-word behavior,
     unsigned snapshot trust, and the fixed PCE tree. Full suite: **190
     tests**; `py_compile` and `git diff --check` pass.
   - The refreshed bounded opening oracle remains **7/7** complete Albert sets
     across **790** candidates, with **0/7** exact submitted sets, **6/22**
     per-unit, and zero failures. The offline snapshot harness generates the
     current turn before HOSTILITY updates persistent diplomatic state, so
     this check protects generation from regressions but cannot validate the
     corrected next-turn trust history.

45. ComputeOrderDipFlags initial token decoding and split-word comparisons

   - Historical correction: this checkpoint initially interpreted province
     `+0x20` as an AMY/FLT occupant token. The later cross-routine audit in
     checkpoint 97 proves that it is the category-`0x41` province power token,
     carrying supply-centre control in this path. The occupant-specific claims
     below are superseded; the split-word comparison findings remain valid.

   - The initial reading of `ComputeOrderDipFlags.c:69–115` preserved an
     occupant's power only when
     the unit token is `AMY`; every other present unit type, including a
     fleet, is represented as neutral power `0x14`. Python used the owning
     power for every unit, incorrectly clearing `flag1` and changing both
     `flag2` and `flag3`. Same-province and adjacent-unit handling now share
     the source's exact token-to-power mapping.
   - Both enemy checks require the exact split value `(lo=1, hi=0)`. Python
     tested only the low word, so a nonzero high word could spuriously block
     bilateral coordination. The implementation now uses both words and the
     runtime power count for all real-power matrix accesses.
   - The press-on adjacent-unit gate compares the low words of ally trust and
     the diplomacy snapshot as unsigned when their signed high words are
     zero. Python compared signed scalar lows, making `0xffffffff` appear
     below two. A shared split-word predicate now reproduces the C int64
     comparison for both state channels.
   - The controller-focused regressions replace the old fleet-as-neutral case;
     the exact-enemy, unsigned trust, and unsigned diplomacy-state checks
     remain. At this historical checkpoint the full suite had **195 tests**.
   - The bounded generation oracle is not rerun for this checkpoint because
     HOSTILITY invokes this routine only after current-turn order generation;
     the offline oracle neither serializes nor replays these press flags.

46. UpdateRelationHistory exponent source and trust-floor comparison

   - The decompile omits `_safe_pow`'s x87 operands, which led the Python port
     to compute `pow(1.8, trust_lo // 10)`. Albert.exe `0x40d82f–0x40d850`
     instead loads `DAT_00634e90[row,col]` (`g_relation_score`), performs a
     signed division by ten with truncation toward zero, loads the `1.8`
     constant at `0x004afa10`, and passes those values to `_safe_pow`. The
     trust floor now derives from the actual relation score.
   - Executable addresses `0x40d85a–0x40d867` compare the converted floor to
     the stored trust pair with a signed high word and unsigned low word.
     Python compared the low values as signed, so a stored `0xffffffff` could
     be incorrectly replaced by a small floor. The exact split-word ordering
     is now preserved.
   - Both nested loops read the live power count at inner-state offset
     `+0x2404`; the hard-coded seven-power bounds are replaced with
     `g_num_powers`. The routine's address annotation is also corrected to
     its executable entry point, `FUN_0040d7e0`.
   - Three focused regressions distinguish relation-vs-trust exponent input,
     unsigned low-word comparison, and runtime loop bounds. Full suite:
     **198 tests**; `py_compile` and `git diff --check` pass.
   - No candidate oracle was rerun: this routine applies a persistent trust
     floor after the current turn's candidate generation, and the offline
     snapshots do not reconstruct the preceding relation/trust history needed
     to observe its corrected next-turn effect.

47. FRIENDLY press independence, runtime bounds, and alliance transitions

   - FRIENDLY.c's Block C at `0x42dea5–0x42deca` creates tentative
     `(lo=1, hi=0)` trust for non-Albert rows whenever its relation/trust
     gates succeed. Python added a `g_minimal_press_mode` exception and
     suppressed this persistent state update in NO_PRESS games. The
     unsupported exception is removed; like HOSTILITY's peace write, this
     relationship bookkeeping is independent of press availability.
   - All three FRIENDLY phases read the live power count at inner-state
     offset `+0x2404`. Python hard-coded seven for both pairwise relation
     updates and final alliance transitions. Both loops now honor
     `g_num_powers`.
   - The final trust-to-alliance pass intentionally visits diagonal entries;
     Albert.exe `0x42e073–0x42e0db` contains no self-skip. Python skipped the
     diagonal. It also compared the low trust word to five as signed, while
     executable `0x42e089–0x42e08c` uses unsigned `jb`. The complete matrix
     pass and split-word threshold now match the executable.
   - The alliance-gain path now carries its updated relation value through
     the shared tail, matching the global value read by C. A proposed event
     regression proved this alignment is behavior-neutral today because that
     event requires exact-zero trust while the gain branch requires positive
     trust; the invalid test was discarded rather than encoding an impossible
     state.
   - Four focused regressions cover NO_PRESS tentative trust, diagonal
     promotion, unsigned low-word promotion, and runtime bounds. Full suite:
     **202 tests**; `py_compile` and `git diff --check` pass.
   - The candidate oracle is not rerun because FRIENDLY executes after the
     current generation snapshot and only changes persistent relationship
     state for later turns, which the stateless harness cannot replay.

48. STABBED protected-province polarity and consequence fidelity

   - STABBED.c's first per-pair scan does not read alliance-designation
     arrays. It walks the active unit list, gates on province byte `+3` (the SC
     flag), and compares the unit's power with the controller token at `+0x20`.
     A foreign unit occupying another power's controlled SC marks the pair.
     Python substituted `g_ally_designation_a/b` and could manufacture stabs
     from unrelated designation state; that proxy is removed.
   - For MTO/CTO and SUP-MTO history records, equality with the per-power tree
     sentinel means the destination is absent and therefore safe. A found
     destination in `DAT_00bb7028` or `DAT_00bb6f28` is the protected-province
     violation that marks a stab. Python inverted this polarity and marked
     every unlisted destination instead. Both the foreign-attacker counter
     tree and Albert-attacker promise tree now flag only lookup hits.
   - The Python lookup additionally recognized only raw integer sets, while
     the real DMZ handlers populate lists of `{'dest_prov': province}` records.
     STABBED now accepts the production record shape as well as legacy scalar
     containers, making the corrected C branch reachable in normal execution.
   - When Albert is stabbed, C inserts alliance-event keys 10 and 30 before
     clearing the stabber's promise/counter trees. Python set the stab byte but
     omitted both event records. The events and original mutation order are
     restored.
   - Best-ally-slot removal is asymmetric at slot 1: when Albert is the stabber,
     slot 2 is promoted; when Albert is the victim, slot 1 is merely cleared.
     One shared Python helper used the victim behavior for both arms. The
     helper now exposes and applies the source's stabber-side promotion.
   - The initialization pass now clears only the live
     `g_num_powers × g_num_powers` prefix rather than all seven Python rows.
     Five regressions cover protected and unprotected foreign moves, removal
     of the designation proxy, SUP-MTO promise detection plus slot promotion,
     event/list/trust consequences, and runtime reset bounds. Full suite:
     **207 tests**; `py_compile` and `git diff --check` pass.
   - The candidate oracle is not rerun because STABBED updates relationship
     state after current-turn generation. The later NOW audit separated active
     and dislodged sets and confirmed that the province record here represents
     SC control, not a second unit-occupant container.

49. DEVIATE_MOVE expected-order, snapshot, and consequence fidelity

   - The peace-signal scan now matches `AdjacencyList_FilterByUnitType`: any
     unit-reachable province adjacent to the submitted order's source can
     signal peace when one of the three SPR snapshots exactly contains the
     victim power. The submitted destination is not part of this test. All
     snapshot comparisons now require both the power low word and a zero high
     word, rather than consulting current alliance designations.
   - XDO ingestion previously discarded the mapped words in
     `DAT_00bb67f8` and `DAT_00bb68f8`. It now preserves
     `source -> destination` move contracts and
     `supporter -> (supported source, supported destination)` support
     contracts. DEVIATE_MOVE probes those per-victim maps before its fallback
     territory rules and treats exact MTO/CTO, SUP-MTO, and SUP-HLD fulfillment
     as safe.
   - The no-contract movement paths now use the three exact SPR snapshots,
     the correct counter/promise protected-province hit polarity, the
     source-specific SUP-MTO and SUP-HLD designation rules, and the exact
     AttackMap pressure predicates. Near-end state creates a deviation but no
     longer forces its classification to stab; the disrupted-order-into-a-
     victim-controlled-SC `flag_c` relation override is restored separately.
   - Final classification now uses positive split-word trust in both
     directions and writes `g_stab_flag[victim, attacker]`. Retreat detection
     uses the two SUM/AUT snapshot pairs, including their high words. Own-power
     movement and retreat events 10/11 and 12/13 are restored.
   - The shared movement consequence tail now clears the appropriate
     promise/counter trees and ally-matrix row for either Albert-as-victim or
     Albert-as-attacker, preserves the source's asymmetric three-slot enemy
     queue behavior, and resets mutual-enemy peace counters under the original
     trust/SC gates. Retreat deviations correctly stop after flags, events,
     cooperation flags, and bilateral trust clearing instead of applying the
     movement-only tree/matrix/best-ally-slot mutations.
   - Thirteen focused regressions cover adjacency-only peace signals, exact
     snapshot words, fulfilled and broken XDO move/support contracts, reverse
     high-word trust, neutral consequences, cease-fire pressure, near-end and
     relation overrides, retreat-only effects, own-attacker slot promotion,
     XDO ingestion, and runtime reset bounds. Full suite: **220 tests**;
     `py_compile` and `git diff --check` pass.
   - The candidate oracle is not rerun because DEVIATE_MOVE consumes submitted
     order history and updates persistent diplomatic state after current-turn
     generation; the stateless harness cannot exercise that history-dependent
     transition faithfully.

50. NOW active/dislodged unit representation fidelity

   - `ParseNOWUnit.c` writes ordinary units to the set at `+0x2450` and
     five-element `MRT` records to the distinct dislodged set at `+0x245c`.
     The Python parser incorrectly described those as non-coasted/coasted
     variants and collapsed both into `unit_info`.
   - This was a reachable state bug: `diplomacy.Game.get_units()` includes
     dislodged units with a leading `*`. During retreats, an active attacker
     and its dislodged victim can share one province key, so the old dictionary
     silently kept whichever power happened to be iterated last. Active unit
     counts, designations, and occupancy tests could consequently depend on
     canonical power order.
   - State now has two explicit views: `unit_info` for active `+0x2450`
     records and `dislodged_unit_info` for `+0x245c` records plus retreat
     options. Both raw NOW parsing and `synchronize_from_game` populate them
     without collisions.
   - The raw parser now accepts the canonical DAIDE header
     `NOW ( season year )`; the prior implementation expected separate season
     and year groups and could not parse a standard message. Nested coast
     locations and `MRT` destination lists are decoded as distinct structures.
   - The province-record bytes initially suspected to hold an occupant are now
     proven to be the SC flag (`+3`) and SC controller (`+0x20`). STABBED and
     DEVIATE_MOVE combine those fields with the active-unit/order lists; there
     is no third board-unit view to maintain.
   - Four regressions cover canonical NOW plus colliding active/dislodged
     units, coast parsing, synchronization from a real retreat-phase
     `diplomacy.Game`, and active-unit-versus-SC-control behavior in snapshot
     and STABBED. Full suite: **224 tests**; `py_compile` and
     `git diff --check` pass.

51. SnapshotProvinceState SC-control, target, and scheduling fidelity

   - Province byte `+3` and token `+0x20` are the SC flag and controller.
     Snapshot designation B now records a controlled SC's owner, C starts at
     `-2`/`-1` for every SC, and designation A is populated only by active
     units. Dislodged units no longer overwrite the active view.
   - Snapshot initialization and all matrix walks now honor the live province
     and power counts. Target trust comparisons use unsigned low words, the
     final non-ally clear reads trust as `[victim, active-unit owner]`, and
     adjacency checks use the active unit's type/coast filter.
   - Alliance sharing now follows the two source passes: all type-reachable
     adjacent provinces receive reach class 0, own units on or adjacent to SCs
     promote that class to 1, and the best ally's units mark class-1 targets
     plus event key 3. Target companion flags are cleared with target writes.
   - The three `DAT_004c6bc4/c8/cc` scalars are the best-ally queue. STABBED
     and DEVIATE_MOVE consequences now mutate those authoritative scalars;
     `g_enemy_slot` remains only a compatibility mirror.
   - `send_GOF.c` calls SnapshotProvinceState after GenerateOrders and after
     PostProcessOrders, alliance transitions, HOSTILITY/SetGamePhase(3), and
     NormalizeInfluenceMatrix. The next chronology audit moved the complete
     snapshot/scoring/ProcessTurn block to that exact boundary; candidate
     initialization can no longer clear the target snapshot before scoring.
   - Four focused regressions cover unsigned target promotion, trust
     orientation, occupied-SC alliance sharing/event 3, and runtime bounds.
     Full suite: **228 tests**; `py_compile` and `git diff --check` pass.
   - The bounded `game_10.json` `S1901M` candidate oracle was rerun after the
     scheduling change: Albert's complete order set remains reachable for
     **7/7 powers**, with **0 Python failures** (submitted selection remains
     diagnostic at 0/7 exact sets and 6/22 unit orders).

52. send_GOF chronology and retreat selection

   - `GenerateAndSubmitOrders.c` performs GenerateOrders, PostProcessOrders,
     ComputePress, STABBED/DEVIATE_MOVE/FRIENDLY/HOSTILITY, phase snapshot 3,
     and NormalizeInfluenceMatrix before calling `send_GOF`. Python previously
     ran SnapshotProvinceState, ScoreProvinces, and all ProcessTurn rounds
     immediately after GenerateOrders, so current-turn diplomatic changes
     could not affect candidate scoring.
   - The complete send_GOF candidate pass now runs at the source boundary:
     SnapshotProvinceState, ResetPerTrialState, seasonal province/key scoring,
     ComputeSafeReach, EnumerateHoldOrders, then the movement-only ten-round
     ProcessTurn loop. The normalizer also moved ahead of this pass instead of
     running after candidate selection. GenerateOrders no longer computes safe
     reach or hold weights against stale/zero final-score trees, and its
     duplicate BuildSupportOpportunities call is gone because
     ScoreOrderCandidates_AllPowers owns that call in the source.
   - SUM and AUT now execute ScoreProvinces plus
     ScoreOrderCandidates_AllPowers with the SPR and FAL weight families,
     respectively. They no longer run an invented one-round movement
     ProcessTurn pass.
   - Albert.exe `0x4418e0` selects retreats by random source priority and the
     highest token-specific scored destination. The port instead used the
     cross-power `g_global_province_score`, allowed two own units to choose the
     same destination, and ignored DMZ/trusted-ally claims. The source selector,
     including disband fallback and CRT call order, is now represented.
   - Five focused regressions cover fleet-key scoring, source priority plus
     destination collision, DMZ/trusted-ally exclusions, SUM/AUT scoring
     without ProcessTurn, and final-score-before-safe/hold chronology. Full
     suite: **233 tests**; `py_compile` and `git diff --check` pass.
   - The refreshed bounded `game_10.json` `S1901M` oracle reaches **7/7**
     complete Albert sets with **0 Python failures** and 789 distinct complete
     legal candidates. The prior Germany 2/3 combination miss is restored at
     seed 2 (142 candidates); submitted selection remains diagnostic at 0/7
     exact sets and 8/22 unit orders.

53. InitPositionForOrders ownership-channel split

   - Binary callback data at `0x4afd50` identifies `0x44d7b0` as the distinct
     InitPositionForOrders routine and `0x4592a0` as GenerateAndSubmitOrders.
     The initializer's history resets establish a one-time position lifetime;
     the client now invokes it once after its first synchronized board.
     EnumerateConvoyReach moved into that one-time callback as at source line
     370 instead of being repeated after every GenerateOrders pass.
   - Python had aliased `DAT_00ba2f70` to `g_sc_owner` and the dormant
     initializer consequently erased live SC controllers, then replaced them
     with active-unit ownership. The source keeps these channels separate:
     province token `+0x20` is current SC control, while `DAT_00ba2f70` is a
     home-controller adjacency spread used by ApplyInfluenceScores and
     ComputeOrderDipFlags. The port now has an independent
     `g_order_dip_owner` table with the source `-1`/`-2` sentinels.
   - Three regressions prove initialization preserves SC control, colliding
     home-controller spreads produce `-2` while foreign captures are excluded,
     and diplomatic flags read the spread rather than the live SC controller.
     Full suite: **236 tests**; `py_compile` and `git diff --check` pass.
   - The refreshed bounded `game_10.json` `S1901M` oracle is unchanged at
     **7/7** complete Albert sets, 789 distinct legal candidates, and **0
     Python failures**. Submitted selection remains diagnostic at 0/7 exact
     sets and 8/22 unit orders.

54. ApplyInfluenceScores contact-matrix province walk

   - The upstream `g_influence_ratio` writer was also keyed to the wrong board
     view. `ApplyInfluenceScores.c:330-379` computes ratios only at controlled
     SCs: non-controller rows use `outer_heat / (controller_heat + 1)`, while
     the controller row uses the strongest other-power heat over the same
     denominator. Python instead iterated army-occupied provinces, compared
     against Albert's own power rather than each outer row, and used a global
     heat maximum for one branch. The ratio table now follows the two source
     formulas and leaves non-SCs at zero.
   - `ApplyInfluenceScores.c:746-782` loops every province for each outer
     power, accepts only SC records with a concrete controller different from
     that outer power, gates on `g_influence_ratio > 1.0`, and increments the
     three contact channels exactly once per qualifying SC. Python instead
     walked active units and their adjacency lists, duplicating a center when
     multiple units touched it and omitting qualifying centers with no adjacent
     unit in that invented traversal.
   - The port now uses the source province/controller loop and preserves the
     separate count, outer-power adjacency-weight, and controller adjacency-
     weight channels. A focused regression uses duplicate unit adjacency to
     prove one-hit-per-SC behavior and verifies all three matrix values.
     A second regression verifies controller/non-controller ratio numerators
     and proves an army outside the SC set cannot create an entry. Full suite:
     **238 tests**; `py_compile` and `git diff --check` pass.
   - The refreshed bounded `game_10.json` `S1901M` oracle remains **7/7**
     complete Albert sets with 789 distinct legal candidates and **0 Python
     failures**; diagnostic submitted selection remains 0/7 exact and 8/22
     per-unit.

55. ApplyInfluenceScores heat ownership and topology fidelity

   - `GenerateOrders.c:457-460` writes each per-power movement score into both
     `DAT_004ec2f0` and `DAT_005af0e8`. ApplyInfluenceScores does not replace
     those arrays with its private diffusion: it normalizes the first with
     integer `value*100/(max+1)` and the second with `value*100/max`. Python
     previously cleared both arrays, installed an unrelated ten-round result,
     and normalized both by `max`. The two source-owned copies and their
     distinct integer denominators are now preserved.
   - ApplyInfluenceScores' private heat uses six unit-token key sets, seeds set
     zero at 5000, and advances five rounds with
     `(self + sum(max adjacent token score per province))/5`, without re-pinning
     live units. Binary code at `0x436996` aggregates set two into
     `g_heat_score` while walking the set-zero keys. The port now retains army
     versus fleet/coast topology, applies the source recurrence, and writes
     only the private `g_heat_score` channel.
   - The source clears `g_AttackHistory` at entry and derives
     `g_unit_adjacency_count` from each active unit's type-filtered adjacency
     list. Python now does both; armies no longer reach water and fleets use
     coast-aware adjacency. GenerateOrders' invented accumulation into
     `g_global_province_score` was also removed because the source clears that
     table and builds it only from normalized movement heat inside
     ApplyInfluenceScores.
   - Pair support normalization now follows `C:602-634`: the maximum excludes
     provinces in either power's home-center set. Five focused regressions
     cover the two movement denominators, set-two private heat and coast
     topology, type-filtered unit reach, and the home-center exclusion. Full
     suite: **243 tests**; `py_compile` and `git diff --check` pass.
   - The refreshed bounded `game_10.json` `S1901M` oracle reaches **7/7**
     complete Albert sets with **818** distinct legal candidates and **0 Python
     failures**. Germany's reference set is recovered at seed 6; diagnostic
     submitted selection remains 0/7 exact and 8/22 per-unit.

56. ApplyInfluenceScores AppendOrder eligibility and tail arithmetic

   - The unit-set lookup at `ApplyInfluenceScores.c:676-684` must return its
     end sentinel before the append path runs. The following board-record gate
     appends an ordinary province directly and rejects an empty supply center
     through the `0x14` empty-unit sentinel. On a synchronized board this is
     exactly an **unoccupied non-supply province** gate. Python had inverted
     it by requiring `prov in unit_info`, producing proposal records only for
     occupied provinces. The port now follows the source eligibility and an
     end-to-end regression proves that an empty contested non-center is added
     while an empty center and occupied provinces are not.
   - `C:507-549` sums normalized primary movement heat into
     `g_GlobalProvinceScore` and performs 64-bit integer `value*100/max`
     normalization. Python retained fractional scores; it now truncates with
     the source integer semantics. The pair pass and both movement
     normalizers also use the board's runtime power/province bounds rather
     than treating unused 7x256 backing-array tails as live records.
   - AppendOrder's reversed tree comparator was rechecked: larger numeric keys
     are routed left, so begin()/iterator order is descending priority; the
     Python list's reverse score sort and duplicate-key retention are already
     consistent with that container behavior.
   - Three focused regressions cover append eligibility directly and through
     the full ApplyInfluenceScores pass, integer global-score normalization,
     and inactive movement-tail isolation. Full suite: **246 tests**;
     `py_compile` and `git diff --check` pass.
   - The refreshed bounded `game_10.json` `S1901M` oracle is unchanged at
     **7/7** complete Albert sets, **818** distinct legal candidates, and **0
     Python failures**. Germany's set remains reachable at seed 6; diagnostic
     submitted selection is now 0/7 exact and 10/22 per-unit.

57. Evaluator and convoy/support source-fidelity corrections

   - Removed a Python-only 2,030-point projected supply-centre occupation
     bonus from `EvaluateOrderScore`. The recovered function returns directly
     after the field-22 cut-risk contribution; it has no projected-ownership
     pass or equivalent constant.
   - Restored `ConvoyList_Insert`'s single-map invariant for CTO orders.
     `DAT_00bb65a4` is the head of `DAT_00bb65a0`, not an independent
     destination container, so `BuildConvoyOrders` now updates both Python
     views used to represent the C map. This makes convoy destinations visible
     to the later support sweep.
   - Corrected convoy score-pair writes: the numeric value is stored in order
     row field 6 and field 7 remains zero, matching the signed 64-bit C pair
     and every other order builder. Python previously duplicated the value
     into both fields.
   - Ported ProcessTurn's two post-move support passes. Equality between
     incoming strength and support demand is eligible, and pass two admits the
     positive secondary-attack marker. In the Russia `S1902M` seed `{0,1,2}`
     pool, the complete `RUM` support plus `SEV/BLA` convoy trio now occurs in
     eight candidates instead of one.
   - Candidate follow-up seeds now inherit `--proposal-round-cap`; diagnostic
     sweeps no longer mix the requested cap on the primary seed with the
     production cap on later seeds and therefore a different RNG chronology.
   - Corrected the Phase 2 army hold-candidate score. After the adjacency
     iterator ends, the C routine resets its pointer to the current unit
     record before indexing `DAT_00ba3b70`; Python instead added the first
     adjacent province's marker to the source score. Army source candidates
     now use their own province marker, while fleet scoring remains unchanged.
   - Full suite: **260 tests**; `compileall` and `git diff --check` pass. The
     bounded `game_10.json` opening sweep still reaches **7/7** complete
     Albert sets across 778 candidates; a cap-zero run also remains 7/7.
     Russia `S1902M` remains a combination gap, but a seed `0..59` sweep
     improves the closest complete candidate from 4/6 to **5/6**.

58. Signed-int64 candidate-score arithmetic

   - Restored the two five-round `GenerateOrders` heat diffusions to signed
     int64 arithmetic. The C routine accumulates integer adjacency values and
     calls `__alldiv(..., 5)` after every round; Python divided by `5.0` and
     carried invented fractions into movement heat and influence scoring.
   - Restored the army and fleet candidate BFS passes in `ScoreProvinces` to
     the same signed, truncation-toward-zero division. This matters in WIN as
     well as movement phases because occupied-centre penalties can make a
     seed negative; Python `//` would floor that case instead of matching C.
   - `ScoreOrderCandidates_AllPowers` now keeps its weighted raw score,
     `max/100` threshold, and `raw*1000/max` normalization in integer space,
     promotes a zero minimum to one, and packs the sub-threshold power result
     back to int64. Python previously retained fractional normalized values
     even though every recovered tree value is a lo/hi signed-int64 pair.
   - The Python arrays representing the candidate BFS and token-keyed final
     score trees now use `numpy.int64`, preventing later code from silently
     reintroducing non-source fractional values. Four focused regressions
     cover signed negative division, exact normalization truncation, the
     zero-minimum branch, and build-heat ownership seeding.
   - Full suite: **264 tests**. The production-cap opening oracle remains
     **7/7** across 767 complete candidates with seeds `0..9`; Germany moves
     from seed 6 to seed 9 under the corrected RNG chronology. Russia
     `S1902M` seeds `{0,1,2}` produce 2,461 candidates with 6/6 individual
     coverage and a 4/6 best; a complete seed `0..59` sweep still reaches
     **5/6** at seed 28 and misses only `GAL-BUD`.

59. ProcessTurn persistent province retry counters

   - Added the missing `g_ProvinceBase[province]` state. `ScoreProvinces.c`
     clears this int32 array once per scoring pass, while
     `ProcessTurn.c:2687` increments the current unit's source when selection
     defers it back into the fleet-candidate tree. It therefore persists
     across Monte Carlo trials and calls; it is not per-trial scratch state.
   - Restored both consumers. The source/hold candidate is removed for a
     convoy-rescore-map member only while its counter is below 500, and the
     two class-2 target-pruning branches stop removing below-threshold nodes
     once the source counter reaches 5000. Class-1 pruning remains independent
     of that counter, matching the separate C branch.
   - Three regressions cover the 499/500 boundary, the class-2 5000 boundary
     and class-1 asymmetry, and the `ScoreProvinces` reset. The stale state
     comment claiming game-end handlers were unported was also corrected;
     OFF/DRW/SLO writers already exist in the inbound dispatcher.
   - Full suite: **267 tests**. The production opening oracle is unchanged at
     **7/7** across 767 candidates with seeds `0..9`; Russia seeds `{0,1,2}`
     remain 2,461 candidates, 6/6 individual coverage, and 4/6 best. Seed 28
     still produces the wider **5/6** candidate missing only `GAL-BUD`.

60. DAIDE coast normalization and token fidelity

   - NOW unit and retreat locations now translate DAIDE coast names such as
     `NCS` and `SCS` to the internal diplomacy suffixes `NC` and `SC`.
     Python previously retained `SCS` with a leading slash in active units,
     which bypassed coast-specific fleet adjacency, and retained raw DAIDE
     names in retreat records, which the retreat serializer could not map
     back to a numeric token.
   - The same shared normalization now covers XDO MTO and SUP-MTO
     destinations, including embedded `PROV/COAST` forms. Coasted unit groups
     such as `( RUS FLT ( STP SCS ) )` also resolve to their base province
     instead of treating the nested token list as a province name.
   - Corrected the numeric coast tables against the DAIDE token catalog:
     `0x4606` is `SEC`, while south coast `SCS` is `0x4608`. Both generated
     movement destinations and retreat records now store `SC` as `0x4608`;
     southeast and southwest retain their distinct `SE`/`SW` mappings.
     The general DipNet-to-DAIDE translator now also uses an explicit inverse
     table, so diagonal coasts produce `NEC`/`SEC`/`SWC`/`NWC` rather than
     invalid names formed by blindly appending `S`.
   - Seven focused regressions cover NOW reachability, coasted retreat
     preservation, XDO coast parsing, nested coasted XDO units, and numeric
     and textual coast round-tripping. Full suite: **274 tests**. The
     rerun opening oracle remains **7/7** with 8/22 diagnostic submitted
     orders; Russia `S1902M` seeds `{0,1,2}` remain a complete-set miss.

61. Static movement/convoy reach index and winter pressure

   - Replaced the per-power occupied-unit approximation of
     `EnumerateConvoyReach` with the source routine's persistent all-board
     topology index at `DAT_00bc1e1c`. The C function has no power-index
     parameter: it walks every legal source province plus AMY/FLT/coast token,
     records ordinary movement BFS distances, and adds possible convoy
     landings and post-landing army reach. On the Standard map the corrected index contains
     75 base-province groups and 7,226 source-reach records; the old port left
     the index completely empty.
   - Preserved multi-coast identity in both source and destination records.
     Direct neighbours now use distance wave one (rather than the old
     off-by-one wave zero), fleet paths keep STP/SPA/BUL coast reach distinct,
     and convoy/post-landing records use the recovered `300 * 1.5**distance`
     score.
   - `InitScoringState` now consumes those records as C does: only an occupied
     army destination opens the inner walk, only a currently present source
     unit with the exact unit/coast token contributes, and the contribution is
     `10000 / distance_score`. Python previously treated every direct adjacent
     unit as an unweighted 10,000-point contributor and could not represent
     longer movement or convoy pressure.
   - Wired the previously dead `ComputeWinterBuilds` port into WIN
     `ScoreProvinces` and corrected its inner-tree condition. The first channel
     now checks the actual legal build-token set instead of comparing source
     and destination province numbers, and the friendly/established/enemy
     channel uses the source-backed 2-D flags and exact source coast token.
   - Four focused regressions cover the complete static index, direct and
     convoy weights, multi-coast routes, live-token urgency, and both winter
     score channels. Full suite: **278 tests**. The opening oracle remains
     **7/7** with 8/22 diagnostic submitted orders; Russia `S1902M` seeds
     `{0,1,2}` remain 4/6 best with 6/6 individual coverage. Game 10's complete
     adjustment sweep remains **23/23** candidate-covered with zero failures.

62. Token-keyed signed WIN candidate scoring

   - Re-audited `ScoreOrderCandidates_OwnPower.c`. Its first pass walks the
     full `(province, unit/coast token)` key, multiplies ten signed-int64 BFS
     slots, and then adds a separate `g_AttackCount * attack_weight` term.
     Python collapsed every build token to the army province channel, omitted
     the attack term, iterated only the nine recovered vector constants, and
     normalized through binary floats.
   - Build scoring now reads the army or fleet BFS channel carried by each
     candidate token. Remove scoring synthesizes the same key from the live
     unit, so a fleet removal no longer receives an army-path score. Both
     paths walk ten slots, preserve the known weight prefix, apply the
     separately configured attack multiplier, and use truncation-toward-zero
     signed division for normalization. Multi-coast fleet candidates read
     their individual coast-key BFS rather than the folded base-province
     maximum.
   - The recovered per-province maximum is shared across AMY and FLT keys,
     while the third-pass difference remains army-only. Full token identity is
     preserved in `g_adjustment_candidate_scores` through final build choice.
     The all-powers scorer now excludes coast-variant ids from its AMY domain
     and excludes the invented plain-FLT key at multi-coast bases; normalized
     coast-key maxima are folded back to the base id used by downstream move
     and support code.
   - The supplied source proves the two attack-weight fields at Albert
     `+0x4df8` and `+0x4e50`, but does not include their constructor stores;
     they remain explicit zero-valued state parameters instead of guessed
     constants. Six regressions cover the attack term, army/fleet key
     separation, shared-max dithering, large-int normalization, and live fleet
     removal and multi-coast scoring. Full suite: **284 tests**. Game 10's adjustment sweep
     remains **23/23** candidate-covered and improves diagnostic exact
     selection from 15/23 to **16/23**, with zero failures.

63. Complete DispatchSingleOrder state projection

   - Re-audited `DispatchSingleOrder.c` and every recovered `BuildOrder_*`
     callee. The Python function claimed to project complete order state but
     HLD wrote only its type, MTO omitted its coast, score, history, convoy
     map, and builder calls, CTO omitted its map/score/route depth, and CVY
     omitted the conveyed-army source and AMY token. Those omissions left
     press-agreed orders structurally different from Monte Carlo-built orders.
   - HLD, MTO, CTO, and CVY now populate the recovered destination/coast,
     signed score pair, incoming marker, move-history, convoy-route, route-leg,
     source-unit, and registration fields. Embedded coast destinations such as
     `STP/NC` are parsed before province lookup, and CTO lists of four or more
     fleets take the recovered no-commit branch instead of being truncated.
   - SUP dispatch now calls the existing source-backed
     `build_order_sup_hld`/`build_order_sup_mto` routines, preserving their
     trust-tier, convoy-active, chain-robustness, conflict, and proximity side
     effects instead of duplicating only the first three table writes.
   - Restored the C duplicate-unit-order no-op guard. The Python selection and
     oracle layers intentionally start from already-built candidate rows, so
     they now request a formatting-only path that serializes those rows without
     rerunning builder mutations; fresh inbound dispatch retains the C guard.
   - Five focused regressions cover complete HLD, coasted MTO, CTO, CVY, SUP,
     oversized convoy, and duplicate-order behavior. Full suite: **289 tests**;
     compileall and `git diff --check` pass. The production opening oracle
     remains **7/7** candidate-covered with 8/22 diagnostic submitted orders.

64. Unified source-backed support builders

   - `ProcessTurn` retained private copies of both SUP builders even after the
     recovered implementations were added to `moves/support.py`. The copies
     had already diverged: their shared SUP-MTO tail treated adjacency to the
     supported mover as the safety condition, while
     `BuildOrder_SUP_MTO.c:120-125` checks adjacency to the attack target (or a
     hostile unit already standing at that target).
   - Every ProcessTurn support call now uses the same source-backed
     `build_order_sup_hld` and `build_order_sup_mto` functions as inbound
     dispatch. This also restores the top-level implementation's target-power
     proximity update and prevents future dispatch/trial drift.
   - A regression distinguishes mover adjacency from target adjacency and
     verifies that the former alone produces the recovered chain-conflict
     marker. Full suite: **290 tests**. The production opening oracle remains
     **7/7** candidate-covered with 8/22 diagnostic submitted orders.

65. Exact unit/coast legality gates

   - Removed the obsolete private SUP_HLD/SUP_MTO implementations from
     `ProcessTurn` after switching all callers to the shared recovered
     builders. This deletes the known-wrong mover-adjacency branch rather than
     leaving it available for accidental reuse.
   - Re-audited `IsLegalMove.c` and the direct-move first branch of
     `FUN_004619f0`. Both select the adjacency sub-list with the moving unit's
     exact type/coast token. `IsLegalMove` then searches with
     `(destination province, coast=0)` and accepts a province match without
     comparing the requested destination coast. Python's
     convoy predicate instead called province-only `can_reach`, admitting
     fleets across army-only borders, while ordinary MTO validation omitted
     the source coast.
   - The shared reach predicate now carries the live source coast for MTO,
     direct convoy-legality, supported-unit reach, and supporter reach. The
     destination remains province-only in every recovered legality helper;
     coast syntax is preserved for serialization but is not an extra rejection
     gate. This rejects fleet support across land-only province borders without
     making Python stricter than Albert for STP/SPA/BUL destinations.
   - Validator destination parsing now accepts the same string, tuple/list,
     and compound-dict forms as dispatch, and rejects missing supported units,
     unit-type mismatches, and unresolved convoy endpoints instead of silently
     committing them.
   - Seven focused regressions cover fleet terrain, source coast,
     destination-coast insensitivity, direct army movement, supporter terrain,
     structured destination parsing, and unresolved-unit rejection. Full suite: **297 tests**;
     compileall and `git diff --check`
   pass. The production opening oracle remains **7/7** candidate-covered
   with 8/22 diagnostic submitted orders.

66. Province-only destination legality and alliance guard words

   - Corrected the preceding coast audit after re-reading the recovered
     `IsLegalMove.c`: its outer lookup is keyed by the moving unit's exact
     type/source-coast token, but its inner search constructs
     `(destination province, coast=0)` and checks only the resulting province.
     Python therefore retains exact source-coast and terrain filtering while
     preserving destination coasts solely for serialization, matching Albert
     instead of rejecting a coast choice that this helper never examines.
   - Fixed all three `check_order_alliance` designation slots to use their
     signed high word as the activity guard. The port's comments and recovered
     control flow said `hi >= 0`, but the implementation tested the low power
     value; a stale low word paired with `hi == -1` could incorrectly trigger
     an ally-trust rejection.
   - Two additional regressions exercise inactive stale low words and active
     trust enforcement across slots A, B, and C. Full suite: **299 tests**;
     focused dispatch tests, compileall, and `git diff --check` pass.

67. ProcessTurn negotiated-map wiring

   - Recovered the identities of three containers that the trial port had
     modelled as unwritten `g_order_history`, `g_ally_order_history`, and
     `g_alt_order_list` aliases. `DAT_00bb6f28` and `DAT_00bb7028` are the
     existing DMZ promise/counter maps; `DAT_00bb69f8` is the accepted-XDO
     source→destination map already populated by the XDO handler.
   - `ProcessTurn` now builds Albert's reachable negotiated-province set from
     all non-enemy promise maps for own-power trials, or the trusted power's
     counter map for foreign trials. Its per-power snapshot and ring/exploit
     membership checks now use the canonical accepted-XDO map, without
     clearing or rewriting that persistent press state during the exploit
     pass.
   - `EvaluateOrderProposal` now reads that same canonical map for the recovered
     750-point alternate-order penalty. Three regressions cover both DMZ
     branches, XDO snapshot identity, and matching-versus-mismatching penalty
     behavior. Full suite: **302 tests**; compileall and `git diff --check`
     pass. The no-press opening oracle remains **7/7** candidate-covered with
     8/22 diagnostic submitted orders.

68. Shared own-occupied destination tail

   - Removed the remaining simplified branch in `ProcessTurn`'s accepted
     proposal path. It previously assigned a constant convoy-fleet score and
     suppressed every candidate entering an own-occupied province, omitting
     Albert's recovered `2579-2694` control flow.
   - Both proposal-derived and ordinary candidates now share one source-backed
     resolver. A pressured stationary occupant receives SUP-HLD, an unordered
     occupant requeues the mover with the destination candidate's decremented
     score and increments `g_ProvinceBase`, a vacating occupant admits the
     move, and terminal/unscored cases reject it.
   - Three regressions cover support generation, score-based deferral, and the
     rejection path. Full suite: **305 tests**; compileall and
     `git diff --check` pass. The opening oracle remains **7/7**
     candidate-covered with 8/22 diagnostic submitted orders.

69. Unified negotiated-order dispatch and exact VIA preservation

   - Removed `ProcessTurn`'s second, partial `DispatchSingleOrder`
     implementation. It omitted recovered HLD/MTO/support side effects and
     reconstructed press-agreed CTO chains from a deterministic board-order
     convoy prepass instead of using the VIA provinces carried by the parsed
     order itself.
   - Negotiated alliance/general orders now use the shared source-backed
     dispatcher. A `record_submission=False` mode preserves its order-table
     mutations while preventing Monte Carlo trials from appending the same
     negotiated order to the final submission queue on every iteration.
   - Removed the generation-time convoy prepass from production flow. Ordinary
     trial candidates still rebuild convoy routes from the live ordered fleet
     candidate tree, while negotiated CTOs retain their explicit parsed chain,
     matching the two distinct recovered C paths.
   - A regression verifies exact VIA depth/legs and an untouched submission
     queue. Full suite: **306 tests**; compileall and `git diff --check` pass.
     The opening oracle remains **7/7** candidate-covered with 8/22 diagnostic
     submitted orders.

70. Per-power proposal heat gates and support-marker identity

   - Recovered `EvaluateOrderProposal.c:687-748` advances its reach-array
     offsets by one 0x800 power block on every heat-score iteration. The port
     instead indexed every SUP-MTO, SUP-HLD, HLD, and CVY gate with the
     evaluated power, flattening each result across all seven heat slots.
   - SUP-MTO now tests Albert's five exact channels per loop power: own reach
     at the supporter source; the signed `DAT_005cf0e8/ec` support-candidate
     marker, convoy reach, and support reach at the attack destination; and
     support reach at the source. SUP-HLD now reads its supported province from
     the order destination field written by `BuildOrder_SUP_HLD`, rather than
     an unused secondary slot.
   - Removed the unwritten `g_convoy_support` duplicate. The recovered low/high
     words are one signed support-candidate value, already modelled and written
     as `g_support_candidate_mark`.
   - Three regressions distinguish the powers and source/destination channels
     for SUP-MTO, SUP-HLD, and HLD. Full suite: **309 tests**; compileall and
     `git diff --check` pass. The opening oracle remains **7/7**
     candidate-covered with 8/22 diagnostic submitted orders.

71. Exact MTO/CTO heat contribution and conviction gate

   - Replaced `EvaluateOrderProposal`'s simplified move-heat proxy with the
     recovered `C:531-659` decision tree. Albert checks each loop power's own
     reach at both endpoints first, then destination support marker plus
     source/destination convoy and support reach, rather than comparing a
     proximity row against the evaluated power's source reach.
   - Direct own reach now adds the moving power's token-specific destination
     score plus source, destination, and 250. Indirect support/convoy reach adds
     the same score and provinces plus 1000. A zero-reach move contributes only
     through the recovered third-party designation-A adjacency/net-reach test.
   - The near-victory +50 conviction shortcut now uses designation B at the
     source and compares threat against own-plus-ally reach. The old branch
     substituted SC occupancy and proximity, changing both its eligibility and
     result.
   - Two regressions distinguish direct/indirect score formulas and verify the
     designation/threat shortcut. Full suite: **311 tests**; compileall and
     `git diff --check` pass. The opening oracle remains **7/7**
     candidate-covered with 8/22 diagnostic submitted orders.

72. Canonical near-victory flag and secondary exploit walk

   - Removed the unwritten `g_stab_mode` duplicate. Both recovered
     `ProcessTurn` gates read `DAT_00baed69`, the near-victory state already
     populated by `CAL_BOARD` and modelled as `g_other_power_lead_flag`; the
     duplicate was initialized to zero locally and could never enable the
     secondary-target branch.
   - Recovered the subsequent target walk instead of scanning trust alone. It
     now checks the evaluated power's negotiated/press-sent row, takes Albert's
     random one- or two-power steps, skips a zero-trust candidate, wraps exactly
     as the C loop does, and aborts if it returns to the primary exploit power.
   - Two regressions cover the canonical flag/threshold and prove that a
     trusted but unnegotiated power is skipped for the next press-sent target.
     Full suite after this slice: **313 tests**.

73. Deceit adjustment supply-center and signed trust gates

   - Corrected `EvaluateOrderProposal`'s conviction/deceit adjustment to match
     the recovered province-record byte. Albert applies it only to an MTO whose
     destination is a supply center occupied by another power's army; the port
     treated that byte as generic occupancy and scored attacks on non-SCs.
   - Restored both signed lo/hi trust comparisons. Forward trust 0 or 1 belongs
     to the 50-point tier; larger forward trust selects 150 only when reverse
     trust is greater than 1, otherwise 110. The prior float-only `< 1` test
     misclassified forward trust 1.
   - Two regressions cover the non-SC exclusion and the trust-1 boundary. Full
     suite: **315 tests**; compileall and `git diff --check` pass.

74. Unified reach pairs and unit-anchored propagation

   - Removed `g_direct_reach_flag` and `g_extended_reach_flag`, which exposed
     the high words of `DAT_005c48e8/ec` and `DAT_005ba0e8/ec` as independent
     state. Each address pair is one signed reach value, now represented only
     by `g_convoy_reach` or `g_support_reach`.
   - Restored exact unit-type/source-coast filtering for the initial reach
     insertion. Armies no longer mark sea provinces merely because they appear
     in the province-only adjacency map.
   - Replaced the generic three-round graph flood with Albert's recovered
     unit-list loop. Each round expands only from a reached province currently
     containing that power's unit; an empty reached province is not promoted to
     a frontier. The second-leg SC support marker and its unfiltered final
     neighbor expansion remain in their source lifecycle slot.
   - Two regressions cover terrain filtering/empty-frontier suppression and SC
     support-neighbor expansion. Full suite: **317 tests**; compileall and
     `git diff --check` pass. The opening oracle remains **7/7**
     candidate-covered with 8/22 diagnostic submitted orders.

75. Paired score-state identities and exact target classification

   - Corrected the two target-classification pairs: `g_prov_target_flag` /
     `g_target_flag2` model `DAT_005ee8e8/ec`, while `g_target_flag` /
     `g_attack_count2` model `DAT_005e40e8/ec`. The stale state documentation
     had incorrectly attached `g_attack_count2` to the total-reach address.
   - Restored the recovered province-classification walk. Albert evaluates
     every real non-SC and only the evaluated power's controlled SCs; the port
     incorrectly required an occupying unit. The decision tree now reads own
     reach (`DAT_0058f8e8/ec`), unit presence, total reach, and enemy reach in
     their source-proven roles instead of substituting enemy reach for own
     reach.
   - Fixed ProcessTurn's second support pass to read positive total reach at
     `DAT_0052b4e8/ec`. It previously read `g_attack_count2`, the unrelated
     high word of `g_target_flag`. Total reach is now stored as one signed
     int64.
   - Unified `g_needs_rescore` and `g_top_reach_flag`: both names refer to the
     single `DAT_005b98e8/ec` sentinel initialized to -1, selectively cleared
     to 0, and promoted to 1. The split port reset one array but ran a duplicate
     scoring pass over a second zero-filled array, opening the support/threshold
     gate for every province. The duplicate pass was removed.
   - Removed `g_enemy_pressure_secondary`, an unwritten independent binding of
     the high word already represented by the combined signed int64
     `g_enemy_reach_score`.
   - Five regressions cover empty-province classification, class-2 own reach,
     contested reach, total-reach support gating, and sentinel object identity.
     Full suite: **322 tests**; compileall and `git diff --check` pass. The
     bounded opening oracle is now **6/7** candidate-covered with the same
     **8/22** diagnostic submitted orders; Germany's bounded pool reaches 2/3
     reference unit orders and misses `A MUN - RUH`. This replaces the earlier
     7/7 claim, which depended on the source-inaccurate always-zero alias.

76. Source-ordered support rings and retry counts

   - Removed a same-power occupancy/swap gate that Python had inserted inside
     `BuildOrder_MTO`. The recovered builder commits its fields unconditionally;
     ordinary-candidate self-occupancy handling lives later in ProcessTurn.
     The early gate made the first edge of `A→B, B→C, C→A` see B as unordered
     and turn the entire precommitted ring into holds.
   - Corrected Albert's accepted-XDO test around that ring. The three recovered
     `find(...) == end()` checks are nested: the builder runs only when none of
     the three sources is constrained. Python required all three sources to be
     present, simultaneously disabling ordinary rings and permitting conflicts
     with negotiated orders.
   - Corrected the support-opportunity rerun count in `send_GOF`. C reuses the
     power's unit count (`unit_count * 10 / 10`); the port used supply-center
     count, which diverges after captures and disbands.
   - Three regressions capture the exact three-MTO snapshot, prove that any
     accepted-XDO source blocks Albert's ring, and distinguish five units from
     two supply centers in the rerun count. Full suite: **325 tests**;
     compileall and `git diff --check` pass. The bounded opening oracle remains
     **6/7** candidate-covered and **8/22** diagnostic submitted orders, with
     602 complete legal candidates and no Python failures.

77. Per-power and per-unit support-opportunity records

   - Corrected the score stored in each `BuildSupportOpportunities` record.
     Recovered C indexes `g_MaxProvinceScore` with `(power, target)`; Python
     used a 1-D compatibility maximum across all powers, changing the retry
     tree's ordering whenever another power valued the province more highly.
   - Restored the three actual unit-token walks. The unit at P filters P→Q,
     the own unit occupying Q filters Q→R, and the own unit occupying R filters
     R→P. Python reused P's type for all three edges and accepted Q/R from
     scratch presence flags without requiring real unit nodes. That rejected
     valid mixed army/fleet cycles and could invent cycles whose later units
     could not traverse their assigned edges.
   - Two regressions distinguish the per-power record score from the global
     maximum and exercise a valid mixed A/F/F ring. Full suite: **327 tests**;
     compileall and `git diff --check` pass. The bounded opening oracle remains
     **6/7** candidate-covered and **8/22** diagnostic submitted orders, with
     597 complete legal candidates and no Python failures.

78. Coast-complete support-opportunity ring records

   - Restored the three coast tokens carried by each recovered seven-word
     `BuildSupportOpportunities` record: P→Q, Q→R, and R→P. Python retained
     only the three provinces, so the later retry path reused default or stale
     ring-coast state when a fleet leg entered a multi-coast province.
   - The GOF retry loader now installs those three recorded coast values into
     `g_ring_coast_a`, `g_ring_coast_b`, and `g_ring_coast_c` before rebuilding
     the ring. One focused regression exercises distinct coast tokens on two
     legs, while the existing rerun regression verifies all three state
     channels are restored.
   - Full suite: **328 tests**; compileall and `git diff --check` pass. The
     bounded opening oracle remains **6/7** candidate-covered and **8/22**
     diagnostic submitted orders, with 597 complete legal candidates and no
     Python failures.

79. Germany opening gap classified as missing press context

   - Traced Germany's absent `A MUN - RUH` through the complete recovered
     filter chain. MUN's AMY score and shared per-province maximum are both
     614, so the source-backed sentinel stays -1 and supplies a threshold of
     599. RUH is an empty, uncontested class-1 target with score 364, so
     `ProcessTurn.c:2235–2391` removes it exactly as recovered.
   - The paired game is explicitly full-press and its S1901M log contains a
     human-language agreement to demilitarize BUR. The offline oracle cannot
     reconstruct sender-tagged DAIDE DMZ/XDO/designation state from those
     free-text messages, and intentionally begins with those containers
     empty. That missing strategic input can redirect MUN away from BUR/SIL;
     weakening the score filter would be a source-inaccurate workaround.
   - The bounded no-press replay therefore remains **6/7** candidate-covered,
     with this pair retained as a context-limited oracle miss rather than an
     open sentinel implementation defect.

80. Token-specific winter occupied-centre penalty

   - Corrected the final `ScoreProvinces` BFS reseed for WIN phases. Recovered
     C subtracts 2500 only when the current `(province, unit token)` key
     matches the unit occupying that power's centre. Python applied the
     penalty before splitting AMY and FLT channels, so either occupant
     incorrectly reduced both possible build-token scores.
   - The fleet path now also preserves coast-key identity: a fleet on one
     coast of a multi-coast centre penalizes only that coast key, while the
     compatibility base remains the maximum of the two legal fleet keys.
   - Two regressions cover army-versus-fleet separation and a distinct
     north/south-coast case. Full suite: **330 tests**; compileall and
     `git diff --check` pass. The game 10 W1901A adjustment oracle generates
     all **4/4** Albert complete order sets across 33 legal complete
     candidates, with no Python failures.

81. Board-ownership and supply-count channel separation

   - Corrected `EvaluateProvinceScore`'s adjacent-threat strength. Recovered C
     reads `curr_sc_cnt[adjacent_unit_power]`; Python summed that power's
     `g_sc_ownership` row, which is the unit-presence scratch table after
     `ScoreProvinces`. Captures, waives, and disbands therefore substituted
     unit count for supply-centre count. The reader now uses board-derived
     `sc_count` directly.
   - WIN build eligibility now reads `g_board_sc_ownership`, matching
     `GameBoard_GetPowerRec`, and no longer relies on saving and restoring the
     dual-purpose scratch table around scoring. The generic `get_power_rec`
     adapter was aligned to the same board channel.
   - Two regressions distinguish 12 centres from one unit and real centre
     ownership from a stale unit-presence hit. Full suite: **332 tests**;
     compileall and `git diff --check` pass. Opening remains **6/7** covered
     with 597 candidates, W1901A remains **4/4** covered with 33 candidates,
     and the divergent-count F1902M checkpoint generates 2,692 legal
     candidates with **3/7** Albert sets complete and no Python failures;
     England (3 centres, 2 units) is candidate-covered.

82. Live source-coast filtering for threatening fleets

   - Corrected `EvaluateProvinceScore`'s adjacent-unit reach gate to pass the
     threatening fleet's live coast into `can_reach_by_type`. Recovered C
     filters the actual unit token; Python passed only FLT and therefore used
     the union of both source coasts, allowing a fleet on SPA/NC, BUL/EC, or
     STP/NC to threaten destinations reachable only from the other coast.
   - A focused regression proves the same fleet is excluded from an SC-only
     edge while on the north coast and included after moving its token to the
     south coast. Full suite: **333 tests**; compileall and `git diff --check`
     pass. The bounded opening oracle remains **6/7** candidate-covered and
     **8/22** diagnostic submitted orders, with 597 complete legal candidates
     and no Python failures.

83. Refreshed bounded opening baseline

   - Reran the same candidate oracle on S1901M for games 10, 100, and 1000 at
     primary seed 1, then unioned seeds 0–9 only for misses. The current port
     generates **18/21** Albert complete sets among 1,866 distinct legal
     candidates; every game reaches 6/7 and no Python run fails.
   - The three remaining misses are Germany's `A MUN - RUH` in games 10 and
     100, which share the full-press/unserialized-context limitation, and
     Russia's `A WAR - UKR` component in game 1000. France's previously
     absent `MAR-SPA`/`PAR-PIC` combinations appear by seed 8, and game 1000
     Germany's `BER-KIE`/`MUN-BUR` combination appears by seed 4.
   - Diagnostic selection across the sample is **2/21 exact sets** and
     **26/66 unit orders**. This replaces, rather than extends, the obsolete
     pre-token-key 21/21 claim.

84. Home-centre membership versus current-controller scoring

   - Corrected four `ScoreProvinces.c:950–1228` branches after separating two
     province-record channels. `GameBoard_GetPowerRec(province+0x14)` queries
     the static set of powers for which the province is a home centre; the
     power token at `province+0x20` is the current SCO controller. Python used
     current ownership for the first and occupying-unit ownership for the
     second.
   - Lost-home detection, the controller/trust gate into
     `EvaluateProvinceScore`, the home-centre 80/150 clamps, and the final
     retained-home 90 versus lost-home 150 override now use the recovered
     channels. A fleet occupying a retained home therefore scores 90 just
     like an army; its token-specific WIN penalty still applies only to FLT.
   - Corrected the adjacent build-pending reseed as part of the same channel
     split. C writes 600 to every static home only when the power currently
     controls none of its homes; Python tested whether an army occupied a
     currently owned centre. One regression covers an empty retained home and
     a completely lost home set.
   - Full suite passes **334 tests**; compileall and `git diff --check` pass.
     The refreshed bounded openings remain **18/21** covered with no failures,
     now across 1,866 candidates: 583 for game 10, 615 for game 100, and 668
     for game 1000. W1901A remains **4/4** candidate-covered. The deterministic
     misses remain Germany `MUN-RUH` (current 599/364 threshold/target scores)
     and no-press game-1000 Russia `WAR-UKR` (539/481).

85. Controlled-centre effective-power scoring

   - Completed the fallback-side controller/designation split in
     `ScoreProvinces.c:980–1228`. A foreign-controlled centre now keeps its
     SCO controller even when it is empty or fleet-occupied; only an
     uncontrolled centre enters the neutral/opening-target branch. Python had
     treated those controlled centres as neutral and assigned 75 instead of
     the controller/trust score of 10 or 1.
   - Restored the distinct own-controller exception: when designation A names
     a foreign power, that designation becomes the effective power even if no
     live-unit lookup supplies it. The entry gate itself now follows C's
     matching designation-A/designation-B conditions.
   - Corrected the controller-count adjustment's decompiled jump direction.
     The +5 applies when `controller_centres * 100 / win_threshold <= 12`, not
     when it is above 12; the under-two-centre +20 branch is unchanged. Two
     regressions separate foreign control from UNO and designation state from
     live unit presence.
   - Full suite passes **336 tests**; compileall and `git diff --check` pass.
     The refreshed openings remain **18/21** covered with no failures across
     1,856 candidates: 597 for game 10, 608 for game 100, and 651 for game
     1000. Diagnostic selection is **1/21** exact and **23/66** per-unit.
     W1901A remains **4/4** covered across 32 candidates. Current deterministic
     score gaps are Germany `MUN-RUH` at 691/433 and no-press game-1000 Russia
     `WAR-UKR` at 664/595.

86. Split early and main candidate-BFS epochs

   - Restored the two distinct tree epochs in `ScoreProvinces.c:440–638` and
     `1538–1738`. C first seeds all ten token-keyed slots from 1/5 on static
     home centres. After main province scoring it overwrites round 0, clears
     and recomputes only rounds 1–8, and deliberately preserves round 9 from
     that early home-only diffusion. Python ran both epochs after main scoring
     and recomputed round 9, collapsing two different source channels.
   - Implemented C's intervening movement-phase clear of an early round-9 key
     when its province has no enemy reach and every adjacent centre is own or
     highly trusted. UNO/uncontrolled centres retain the key through their
     default-zero trust slot. A regression proves the main-score round 8,
     cleared home round 9, and retained neutral-frontier round 9 coexist.
   - Corrected the adjacent fallback boundary at C:1049/1230. Provinces that
     enter `EvaluateProvinceScore` jump directly to the loop tail and skip
     fallback Adjustments 4–9; in particular, the 90/150 home override is not
     unconditional. Keeping evaluated own centres at their computed score
     restores the intended relation between source thresholds and frontier
     targets.
   - Full suite passes **337 tests**; compileall and `git diff --check` pass.
     W1901A remains **4/4** candidate-covered across 32 candidates. The
     opening sample now reaches **21/21** at primary seed 1 with no failures,
     across exactly 520 candidates per game (1,560 total). This closes Germany
     `MUN-RUH`, Italy `NAP-ION`, Russia `MOS-UKR`, and no-press game-1000
     Russia `WAR-UKR` without weakening any target filter.

87. S1902M Russia combination revalidation

   - Re-ran the former hard game-10 Russia checkpoint after the split-BFS and
     fallback-boundary corrections. The complete six-order Albert set now
     appears at seed 6; the union through that seed contains 3,196 distinct
     legal candidates and all six component orders, with no Python failures.
   - This closes the previously documented 5/6 ceiling without any special
     convoy or order-set exception. The remaining submitted-order difference
     is selection-only and still depends on unavailable process PRNG history.

88. Proposal-support lifetimes and complete late support sweep

   - Corrected the no-press proposal record contract from
     `BuildSupportProposals.c`. Record fields 4–8 are supporter power,
     supporter province, mover power, mover province, and destination;
     `g_xdo_press_sent` is indexed by prospective supporter then requester.
     `ProcessTurn` consumes those records as `SUP_HLD` when mover equals
     destination and `SUP_MTO` otherwise. Python had transposed the matrix,
     reversed the parties, and emitted movement orders instead. The outer
     random gate is now the recovered 15%/late-game 35% test, while the 65%
     draw remains confined to secondary-target selection. `send_GOF` now
     clears the shared proposal-history/deal container at its source lifetime
     boundary.
   - Restored `ProcessTurn.c:588–624`'s per-trial proximity reset: every runtime
     cell starts at signed -1 and only active units' owner/province cells are
     zeroed. The live support-demand refresh now computes the recovered peak
     and total hostile reach from `g_ThreatScore - g_ProximityScore` before
     each candidate unit and after the late support passes; the implementation
     uses an equivalent vectorized reduction to avoid a large Python runtime
     penalty.
   - Completed `ProcessTurn.c:3033–3640`'s two-pass HLD conversion. The port had
     implemented only destinations present in the move map (`SUP_MTO`) and
     omitted own occupied non-moving destinations (`SUP_HLD`). The move branch
     admits incoming strength equal to demand; the hold branch requires it to
     be strictly lower; both receive the source's positive-total-reach override
     on pass two. Removed two immediate synthetic support-emission passes after
     `AssignHoldSupports`; that routine only ranks the shared candidate tree.
     Support emission belongs to the recovered resolver and late sweep.
   - The formerly impossible game-1000 orders `F BAL S A DEN` (F1902 Germany)
     and `A RUM S A UKR` (S1903 Russia) are now generated. Bounded seeds 0–9
     cover every individual reference order in those two cases and S1903
     Italy; exact later-game combinations remain context/selection diagnostics.
     The production-cap game-10 S1901 oracle remains **7/7** complete sets at
     primary seed 1 across 528 legal candidates, and the production-cap game-10
     S1902 Russia six-order set remains generated at seed 6 across 961
     candidates. Full suite: **345 tests**; compileall and `git diff --check`
     pass.

89. Supported-unit coast serialization

   - Corrected `_build_order_seq_from_table` to serialize every referenced live
     unit through one coast-aware formatter. The recovered
     `SerializeOrderToDAIDE.c` support cases resolve the supported unit record
     and pass it to the complete unit serializer; Python instead rebuilt
     `target_unit` as only type plus base province. Consequently legal orders
     such as `A POR S F SPA/SC` and `F BOT S F STP/NC` were emitted as support
     for nonexistent plain-coast fleets and failed exact oracle comparison.
     The correction applies to both `SUP_HLD` and `SUP_MTO`; the same helper is
     also used by the CTO/CVY compatibility sequences that name a live unit.
   - Added direct support-hold and support-move regressions, including a full
     builder → validator → existing-order formatter round trip proving that
     the supported fleet's source coast survives independently of the move
     destination coast. Game-1000 F1903 France now matches Albert's exact
     three-order set at seed 0. F1903 Russia's former hard atom is also closed:
     all six atoms and the complete reference set occur in the candidate pool.
   - Across all 125 game-1000 movement phase/power pairs, bounded seeds 0–9 at
     the diagnostic proposal cap 0 now cover **63/125** complete Albert sets,
     up from **46/125** before the serializer correction, with no generation
   failures. The earliest remaining hard examples are context-limited:
   Austria's absent `A VIE S A TYR - BOH` supports an Italian unit, while the
   saved logs contain only human free-text press and cannot reconstruct the
   necessary XDO state. Full suite: **347 tests**; compileall and
   `git diff --check` pass.

90. Order-record unit/coast token fidelity

   - Restored `DAT_00baedac` (order-table column 3) from the recovered builder
     contract. `ParseDestinationWithCoast.c` proves that a plain destination
     inherits the moving unit token (`AMY` = `0x4200`, `FLT` = `0x4201`), while
     a compound destination stores its explicit `0x46xx` coast token.
     `BuildOrder_HLD.c` likewise copies the live unit record's token, and
     `BuildConvoyOrders.c` propagates the convoyed army token to the CTO and
     every CVY row. Python instead left holds at the reset sentinel and wrote
     zero for plain moves and convoy rows.
   - Added one canonical unit/location-token mapper and applied it to direct
     dispatch, Monte Carlo hold/move builders, and convoy assembly. This field
     is not merely textual metadata: `snapshot_order_entry` includes it in the
     five-field candidate identity, so wrong tokens can alter duplicate
     collapse and stable BST ranking. Regression coverage now checks army
     holds, plain fleet moves, and both army/fleet rows of a convoy.
   - The diagnostic-cap game-10 opening remains **7/7** candidate-covered, as
     do the corrected game-1000 F1903 France and Russia cases. The production
     game-10 opening also remains **7/7** at primary seed 1 and contains exactly
     **528** candidates; their internal identities now carry the source-faithful
     tokens. Full suite: **349 tests**; compileall and `git diff --check` pass.

91. Late support-sweep convoy promotion

   - Restored `ProcessTurn.c:3247–3318`'s second entry into the shared
     `LAB_00453cac` convoy-assignment promotion. During either late HLD support
     pass, a destination with a pending assignment can consume the held source
     as an `MTO` instead of emitting `SUP_MTO`. This entry uses the same strict
     `(rand() / 0x17) % 100 > 60` gate as the earlier Phase-2 path, then adds
     late-only requirements that the source have exactly one incoming move and
     no support-chain conflict. The implementation preserves the recovered RNG
     chronology by testing those source fields only after consuming the draw.
   - Added the source-specific late MTO writer rather than calling the ordinary
     `BuildOrder_MTO` equivalent. The recovered branch calls
     `BuildOrder_CTO_Ring` and manually updates only the move map, order fields,
     incoming marker, and destination score; it does not execute the ordinary
     builder's move-history, convoy-registration, or support-assignment tail.
     Regressions cover both late-only rejection gates, the complete assignment
     promotion to depth 5, the plain-fleet token, move-map insertion, and the
     absence of the ordinary move-history side effect.
   - The production-cap game-10 `S1901M` oracle remains **7/7** complete Albert
     sets at primary seed 1 across exactly **528** legal candidates, with 9/22
     diagnostic submitted orders and no failures. Full suite: **352 tests**;
     compileall and `git diff --check` pass.

92. Late versus public support-writer contracts

   - Separated the late `ProcessTurn.c:3319–3635` support setup from the public
     `BuildOrder_SUP_MTO` / `BuildOrder_SUP_HLD` builders. The late block calls
     only the low-level support ring writers, manually writes the order and
     score fields, and then performs the same chain-robustness scan. Python had
     routed it through the complete public builders, which additionally clear
     army score fields, register convoy-fleet state, and apply foreign-unit
     trust and `g_convoy_active_flag` side effects. Those extra tails can alter
     subsequent candidate filtering even though they are absent from this C
     path. The shared builders now expose an explicit late-sweep mode that
     retains the common chain logic without those ordinary-builder effects.
   - Restored the separate `BuildOrder_SUP_MTO.c:216–219` tail for ordinary
     support-move construction. After either chain outcome, a target whose
     assignment state is pending (`1`) is reset to zero and its
     `g_SupportAssignmentMap` entry returns to the `-1` sentinel. The Python
     public builder previously left both stale. This cleanup is intentionally
     excluded from late-sweep mode because the manual ProcessTurn path does not
     execute it.
   - Regressions prove that foreign late support leaves the global trust
     adjustment and convoy-active flag unchanged, while a public support-move
     order clears its pending target assignment. The production-cap game-10
     `S1901M` oracle remains **7/7** complete sets across exactly **528** legal
     candidates, with 9/22 diagnostic submitted orders and no failures. Full
     suite: **354 tests**; compileall and `git diff --check` pass.

93. Proposal-exploit support writer

   - Restored `ProcessTurn.c:1151–1203`'s proposal-history support writer as a
     distinct path. After the proposal trust and negotiated-province gates, C
     calls only the low-level `SUP_HLD`/`SUP_MTO` ring writer and manually sets
     the order record, source score, requester trust tier, and destination
     convoy-active flag. Python instead called the complete public support
     builders, which additionally registered convoy-fleet state and ran the
     chain-robustness scan, potentially increasing the supported destination's
     live strength or conflict counter. Those effects do not occur in this
     proposal-exploitation branch.
   - Added a source-specific proposal writer keyed by the requester power stored
     in the recovered ProposalHistory record. The regression now proves that a
     foreign `SUP_MTO` proposal still applies the expected trust tier and
     convoy-active marker while leaving convoy registration and both destination
     chain counters untouched. `EvaluateOrderProposal`'s superficially similar
     low-level calls were audited separately and need no table mutation: they
     rebuild C's separate unit-node order state after `ResetPerTrialState`, which
     the Python port intentionally elides.
   - The production-cap game-10 `S1901M` oracle remains **7/7** complete Albert
     sets across exactly **528** legal candidates, with 9/22 diagnostic
     submitted orders and no failures. Full suite: **354 tests**; compileall and
     `git diff --check` pass.

94. Typed `AssignSupportOrder` reach

   - Corrected both `AdjacencyList_FilterByUnitType` uses in
     `AssignSupportOrder.c`. For the initial confirmation gate, C resolves the
     unit at the destination, filters adjacency by that unit's type/coast, and
     tests whether it can reach the source. Python instead tested the source's
     raw province adjacency in the reverse direction. The same inversion was
     present in the routine's final proximity update, which walked every raw
     neighbor of the destination rather than only neighbors reachable by the
     destination unit. This could let a coastal army confirm and project
     proximity onto a fleet's sea province, or let fleets cross land-only
     coastal borders.
   - Both checks now use destination-to-source typed/coast-aware reach. The
     regression constructs an enemy army adjacent at the province graph level
     to a sea source and proves that neither the support score nor the army's
     proximity at sea is changed. Assignment-map cleanup in the same routine
     now stores Python's signed `-1` representation of C's `0xffffffff`
     sentinel instead of the unsigned floating value `4294967295`.
   - The production-cap game-10 `S1901M` oracle remains **7/7** complete Albert
     sets across exactly **528** legal candidates, with 9/22 diagnostic
     submitted orders and no failures. Full suite: **355 tests**; compileall and
     `git diff --check` pass.

95. Typed support-proposal reach

   - Corrected both supporter scans in `BuildSupportProposals` to match
     `BuildSupportProposals.c:194` and `:346`. The recovered routine resolves
     each prospective supporter's live unit token and uses
     `AdjacencyList_FilterByUnitType` before admitting a support-to-destination
     proposal. Python used `get_unit_adjacencies`, whose name/comment imply a
     typed unit view but whose implementation intentionally returns raw province
     neighbors. That allowed terrain-invalid proposals such as an army offering
     support into a sea zone. The two call sites now explicitly apply the
     supporter's type and coast without changing raw-neighbor consumers in
     scoring code.
   - Added a regression with a prospective army supporter and a sea destination;
     raw graph adjacency is present, but no ProposalHistory record or press-sent
     matrix flag is created. The production game-10 `S1901M` candidate pool
     changes from 528 to **524** legal sets, confirming that the invalid proposal
     state was reachable even in offline generation, while all **7/7** Albert
     reference sets remain covered and the submitted diagnostic stays 9/22.
     Full suite: **356 tests**; compileall and `git diff --check` pass.

96. Projected early-game order adjacency

   - Restored `EvaluateOrderProposal.c:781–877`'s ordered-position adjacency
     calculation. For `MTO` and `CTO`, C starts from the order destination and
     filters neighbors with the order's destination unit/coast token; every
     other order starts from the unit's current province and live token. Python
     instead counted every own unit from its current province and applied only
     broad army-water/fleet-land terrain checks. This missed formations created
     by the proposed moves and could include land-only fleet borders or the
     wrong coast of a multi-coast destination.
   - Extracted a source-shaped projected-adjacency helper with DAIDE coast-token
     decoding. Also restored the subsequent province-record `+3` gate: the
     trusted foreign unit reached by more than one projected own unit must be
     on a supply center before contributing the 160-point early-game bonus.
     The regression proves that two moves converging around a trusted foreign
     SC earn 160 even when neither source was adjacent, and that removing the
     SC flag removes the bonus.
   - The production-cap game-10 `S1901M` oracle remains **7/7** complete Albert
     sets across the current **524** legal candidates, with 9/22 diagnostic
     submitted orders and no failures. Full suite: **357 tests**; compileall and
     `git diff --check` pass.

97. Province power-token and controlled-centre audit

   - Re-audited the category-`0x41` token stored at province record `+0x20`
     across the recovered routines. `ComputeOrderDipFlags`, support assignment,
     opening targets, position urgency, scoring seeds and threat paths, press
     pressure, proposal evaluation, convoy exceptions, and Monte Carlo ally
     pressure now read supply-centre control instead of inferring an AMY
     occupant from the token's high byte. Live unit type and coast continue to
     come only from the active UnitList / `unit_info` view.
   - Restored the source lifecycle at winter adjustment: `ComputeBuildDelta`
     overlays active-unit power tokens without first clearing the province
     table, so occupied centres change hands while empty centres retain their
     previous controller. It then derives each build/remove delta by recounting
     controlled supply centres from that updated table. `ParseNOW` now performs
     this winter calculation independently of whether HLO has arrived.
   - Corrected two related control-flow ports. `MOVE_ANALYSIS` now begins
     strategic reach at each defending power's controlled centres, uses typed
     attacker reach, and applies the recovered designation gates. `ComputeDrawVote`
     now floods from friendly units through passable empty/friendly provinces
     and rejects only a reachable centre controlled outside the proposed draw;
     it no longer expands only into hostile units or rejects any disconnected
     foreign unit. `EvaluateAllianceScore` also requires a unit to control the
     centre it occupies before awarding its favourable-move bonus, in both the
     scalar and batched evaluators. The same evaluators now cancel ordinary key
     value on a foreign-controlled centre when its controller is trusted, and
     the final province-scoring pass clears or marks controller-indexed stale
     ally-B designations exactly where the recovered tail does.
   - The refreshed production `game_10.json` `S1901M` oracle still reaches
     **7/7** complete Albert sets at primary seed 1. The corrected legal pool is
     **518** candidates, with **10/22** diagnostic submitted orders and no
     failures. Full suite: **378 tests**; compileall and `git diff --check`
     pass. The sole warning is the existing `diplomacy` dependency's deprecated
     `datetime.utcfromtimestamp` call.

98. Source-faithful no-press `MOVE_ANALYSIS`

   - Removed two deliberate gameplay substitutions from `MOVE_ANALYSIS` that
     contradicted the recovered routine. Albert performs its first-Fall
     pressure-derived trust updates with `DAT_00baed68 == 0` even in NO_PRESS;
     Python had suppressed both the pre-ratio trust reset and every ratio
     update whenever `g_minimal_press_mode` was set. The routine now follows
     the source gate exactly: first year, Fall, transient press flag clear.
   - Restored the recovered one-level three-slot ally shift. If slots zero and
     one are invalid while slot two survives, Albert leaves
     `[-1, slot2, -1]`; Python had intentionally full-packed that state to
     `[slot2, -1, -1]`. Slot invalidation, original-low-trust restoration,
     exact trust-1 enemy detection, and triple-front demotion now also consult
     the signed high word and unsigned low word like the C comparisons.
   - The `game_10.json` `F1901M` primary pool covers **5/7** complete reference
     sets; a bounded seed 0–9 union reaches **7/7** (France by seed 5, Germany
     by seed 2) across **647** candidates. Diagnostic selection is **1/7**
     exact sets and **11/22** unit orders. Full suite: **380 tests**;
     compileall and `git diff --check` pass.

99. Typed/coast adjacency and draw-frontier audit

   - Restored `ComputeDrawVote`'s complete `(province, unit/coast token)` reach
     map. Armies no longer flood through sea, fleets no longer enter land or
     leave a split-coast province through the coast opposite their arrival,
     and the source's non-water AMY companion key is retained. The subsequent
     commitment pass now counts reachable typed frontier provinces against
     units outside the proposed draw set; Python previously reversed that
     relation and initialized the solver on draw-member units.
   - Replaced several other live-unit base-adjacency substitutions with the
     recovered `AdjacencyList_FilterByUnitType` behavior. This includes
     `ComputePress`, `ScoreProvinces`' core reach/threat matrix and its
     mobility/weight passes, and both scalar and batched alliance-candidate
     staging. Added a canonical C-style edge iterator that carries the
     destination coast into chained flank-denial and support-reach walks.
   - Preserved the source coast on completed movement-history records and use
     it in `DEVIATE_MOVE`'s peace-signal scan. Result reconciliation now maps a
     coasted unit result back to the base province used by the order-history
     record, so bounce/cut/dislodged flags for STP/SPA/BUL fleets are no longer
     silently lost.
   - Investigated `DAT_00baed68`'s lifecycle rather than inventing a writer:
     `GenerateAndSubmitOrders.c` proves it is a one-turn pulse copied from
     `DAT_004c6bdc`, but the recovered corpus contains no write to that pending
     global. The Python full-press lifecycle therefore remains an explicit
     unresolved adaptation until the arming event can be recovered.
   - The refreshed `game_10.json` `S1901M` primary oracle remains **7/7** at
     **502** candidates and **10/22** diagnostic unit orders. `F1901M` remains
     **5/7** at primary seed 1 across **600** candidates; seeds 0–9 reach
     **7/7** across **639** candidates (France at seed 5, Germany at seed 2),
     with **1/7** exact sets and **6/22** diagnostic unit orders. Full suite:
     **391 tests**; compileall and `git diff --check` pass.

100. `EvaluateAllianceScore` supply-centre pressure audit

   - Corrected the phase-2 input ownership: Albert always reads the
     candidate-local province and fleet pressure matrices. The Python port's
     fallback to static reach scores had no recovered source counterpart and
     could make a zero-pressure candidate inherit unrelated board pressure.
   - Decoded province-record byte `+3` as the static supply-centre marker.
     Python had treated the following source loop as current unit-occupancy
     scoring and invented a `-10/+5` affinity adjustment. The recovered loop
     instead compares each centre's controller, candidate-local pressure, and
     threat score. It now ports the controller-owned defense deductions and
     their signed truncation-toward-zero divisions, plus the Spring opening
     bonus using `g_threat_path_score` and the per-power province maximum.
     A defense deduction suppresses that bonus exactly as in the source.
   - Corrected the preceding non-centre adjustment to iterate non-SCs rather
     than empty provinces and to affect only the evaluated power when the
     transient press flag is clear. Scalar and batched candidate evaluation
     share the new centre-controller implementation, retaining exact parity.
   - The refreshed `game_10.json` `S1901M` primary oracle remains **7/7** at
     **502** candidates and **10/22** diagnostic unit orders. The bounded
     `F1901M` seed 0–9 oracle remains **7/7** across **639** candidates, with
     **1/7** exact sets and **6/22** diagnostic unit orders. Full suite:
     **394 tests**; compileall and `git diff --check` pass.

101. Assembly-backed `EvaluateAllianceScore` completion pass

   - Restored the candidate-record cost fields, persistent maximum-base
     penalty, signed token-key arithmetic, foreign-key deductions, second
     influence-matrix scaling, whole-board minimum/history terms, and the
     Spring/Fall scratch scaling shared by scalar and batched evaluation.
     The maximum penalty's `1/8` versus `1/16` divisor and the seasonal
     `100/300/10` constants were verified directly against `Albert.exe`.
   - Ported the second owned-supply-centre pressure pass. With press disabled,
     eligible other-power pressure now builds Albert's `20 + delta*10/trial`
     cost and adds the centre's visit deficit before subtraction. The later
     seasonal home-centre bonus now uses the board's static home-power set:
     Spring adds the unmoved `10` term, while Fall consumes the positive
     `counter_b` accumulator through two signed integer divisions.
   - Corrected the water fleet-chain branch: `GameBoard_GetPowerRec` tests
     static home-centre membership, not current ownership, and Albert assigns
     the larger 10% contribution with a 20 cap to non-home provinces. Per-unit
     reach bonuses and deductions now truncate each signed division at the C
     boundary instead of combining fractional Python values.
   - The refreshed `game_10.json` `S1901M` primary oracle remains **7/7** at
     **502** candidates and records **8/22** diagnostic unit orders. The
     bounded `F1901M` seed 0–9 oracle remains **7/7** across **639** candidates
     and records **3/22** diagnostic unit orders; neither phase has an exact
     submitted set at this checkpoint. Candidate coverage is intact, but the
     ranking gap remains substantial. Full suite: **409 tests**; compileall
     and `git diff --check` pass.

102. `EvaluateOrderScore` numeric-storage audit

   - Restored the final `PackScoreU64` boundary. Albert returns an integer
     candidate base score by truncating the x87 accumulator toward zero;
     Python previously retained a fractional score and allowed it to enter
     duplicate-candidate and rank calculations.
   - Restored the intermediate pack in the fleet-adjacency propagation pass.
     The home-centre-discounted threshold `100*0.5*0.2*0.75`, for example,
     is stored as `7`, not `7.5`. Integer-pair order fields are now consumed
     as integers in the final score pass.
   - Added explicit float32 store boundaries for Albert's move-probability,
     unit-reach, cut-risk, and cumulative-score fields. Python's float64 order
     table remains the compatibility container, but no longer postpones the
     single-precision rounding that the C locals and record fields impose.
   - The refreshed `game_10.json` oracles are unchanged: `S1901M` is **7/7**
     candidate coverage at **502** candidates and **8/22** diagnostic unit
     orders; bounded seed 0–9 `F1901M` is **7/7** across **639** candidates
     and **3/22** diagnostic unit orders. Both remain **0/7** exact submitted
     sets. Full suite: **411 tests**; compileall and `git diff --check` pass.

103. Canonical `NormalizeInfluenceMatrix` call path

   - Removed `_cleanup_turn`'s stale duplicate of the influence normalizer and
     routed the production pre-`send_GOF` call through the canonical port.
     The duplicate divided only by the low trust word and used a column sum
     for noise; the recovered function reconstructs the full signed split-word
     trust value and uses the current row's packed sum.
   - Added a regression with a positive high trust word that distinguishes the
     two paths after normalization. Full suite: **412 tests**; compileall and
     `git diff --check` pass. The movement oracle was not rerun for this item:
     this normalization occurs after the offline candidate-ranking checkpoint
     measured in item 102.

104. Proposal scoring and support-history field audit

   - Corrected `EvaluateOrderProposal`'s near-end conviction interval. Albert
     awards the per-unit `+50` when threat lies between own reach and combined
     own-plus-allied reach, with a strict lower bound in the designated
     year-5-to-6 arm and an inclusive lower bound after year 6. Python had the
     principal inequality reversed and rewarded only threat above the combined
     defense. Conviction continues to skip that unit's heat pass as in C.
   - Restored the fallback move-heat branch's complete signed-int64 ally-A
     comparison. A nonzero high word can no longer be mistaken for a small
     power merely because its low word matches. The analogous ally-A/ally-B
     filters and priority test in `BuildSupportProposals` now compare both
     words as well.
   - Corrected the one-threat support handshake gate from field-0 order type
     `CVY` to field-20 convoy state `5`. The recovered `ProcessTurn` writes that
     completion value explicitly. Proposal deduplication now consults the
     authoritative history map, so a key created by the handshake branch is
     accumulated rather than duplicated when a later multi-threat branch sees
     it; the map is bound to its backing deal list at state construction.
   - Corrected secondary proposal consumption: even when a history record is
     admitted through the secondary-target arm, Albert retains the primary
     cyclic proposal partner for the `30/10/-10` support-trust adjustment.
     Python had substituted the record's secondary requester.
   - Full suite: **417 tests**; compileall and `git diff --check` pass. The
     movement oracle was not rerun for this item.

105. Support/convoy construction and safe-reach audit

   - Removed invented existing-order guards from the public SUP-HLD/SUP-MTO
     builders; their dispatcher retains its separate upstream guard. Restored
     `RegisterConvoyFleet`'s province-terrain gate (water only), and removed
     nonexistent field-20 assignment writes from `BuildConvoyOrders`' CTO/CVY
     setup.
   - Corrected `AssignSupportOrder`'s build-centre commitment block. Source
     demand 1 now bypasses the centre test; other sources require demand 0,
     static home-centre membership, and current control. The port no longer
     invents source/destination adjacency or substitutes own-unit occupancy
     for the recovered enemy-presence gate.
   - Restored `ComputeSafeReach`'s province-record pass: supply centres, not
     fleet unit types, are contested for every power other than their current
     controller, with neutral centres contested universally. Both safe-reach
     unit walks and `EnumerateHoldOrders`' non-ally reach walk now use typed,
     coast-aware adjacency. Restored the latter routine's C→B→A designation
     read order, which gives slot A final precedence.
   - Restored the destination-unit iterator cache written before every
     `BuildOrder_MTO` call in both negotiated-order dispatch and ProcessTurn.
     `AssignSupportOrder` can now observe an occupant's existing MTO and clear
     its conflicting downstream support commitment; the Python cache had
     previously been defined but never populated.
   - Full suite: **429 tests**; compileall and `git diff --check` pass. The
     bounded `game_10.json` `S1901M` oracle remains **7/7** candidate-covered
     at seed sweep 0–9, with **1/7** exact sets and **9/22** diagnostic unit
     orders.

106. WIN removal ordered-multiset tie fidelity

   - Disassembly of `FUN_00442040` confirms that removal candidates are
     inserted while walking the own-unit map, with **200** added to the signed
     score, and selected by repeatedly decrementing the ordered multiset's end
     iterator. `BuildOrderSpec` orders equal keys to the right, so equal-score
     units are consumed in reverse insertion order: the higher province key is
     removed first.
   - `compute_win_removes` now reproduces that secondary ordering, with a
     focused equal-score regression. The refreshed `game_10.json` `W1903A`
     oracle remains **4/4** candidate-covered and is **2/4** exact (**5/9**
     diagnostic unit orders). Russia's current `ARM 141`, `BLA 213`, and
     `BOH 394` candidate scores are distinct, confirming its `ARM/BLA` versus
     Albert `ARM/BOH` difference is an independent scoring issue rather than
     a tie-order regression. Full suite: **430 tests**.

107. Press-evaluator set-membership and verdict fidelity

   - Re-derived the `std::set` idiom shared by the `_eval_*` family.
     `_eval_drw.c` pins the argument order of
     `StdMap_FindOrInsert(set_object, ret_slot, key)`: its two sets are
     constructed at unwind levels 3 and 4, and the epilogue destroys the
     object at `local_48` with head `local_44` and the object at `local_54`
     with head `local_50`, so the first argument is the container and the
     second a scratch return slot. `_eval_aly.c:127` pins the polarity of the
     `find` comparison — `piVar10[1] == head` is `end()`, i.e. **not** found.
   - `_eval_slo`: the tested size `local_4c` belongs to the set fed by the SLO
     power sublist (`local_1c`), not the participant set, whose size
     `local_40` is never read. Albert answers YES only when the SLO names
     exactly one distinct power and that power is himself; the port had been
     counting unique message participants and so rejected `SLO (FRA)` sent to
     Albert-as-France.
   - `_eval_not_dmz` sub-check B: `bVar4` clears when the participant is
     **absent** from the DMZ power set. The port had the membership test
     inverted.
   - `_eval_not_dmz` verdict: the two sender-membership gates are driven by
     `uVar10 = local_90 = len(DMZ power sublist)`, not by the doubled
     participant count. Only the `>= 3` early BWX reads `uVar9`. The port used
     the participant count for all three and inverted the `> 1` arm.
   - `_eval_single_xdo` SUB/PRP `NOT` arm (`_eval_single_xdo.c:238-243`):
     unlike the top-level `NOT` arm at line 131, it never runs
     `GetSubList(input, 1)` before re-testing element 0, so that element is
     still `NOT`, the `XDO` test always jumps to `LAB_0042c5e4`, and
     `CAL_VALUE` is unreachable. Albert scores a bare `NOT (XDO ...)` but
     HUHs the identical clause wrapped in `PRP`. Reproduced rather than
     repaired.
   - Full suite: **435 tests** at this checkpoint.

108. `DAT_00bc1e00` is a participant power set, not a round record

   - `state.py` bound `DAT_00bc1e04` as "current round number" and
     `DAT_00bc1e00` as a per-power round record, and both `UpdateScoreState`
     and `BuildAndSendSUB`'s round-zero block tested
     `record[p] != g_current_round`. The disassembly does not support that
     reading:
     * `BuildAndSendSUB.c:231-234` destroys the container with
       `SerializeOrders(&DAT_00bc1e00, ..., *DAT_00bc1e04, ..., DAT_00bc1e04)`
       — the tree-destroy call shape every `_eval_*` epilogue uses, whose last
       argument is the head sentinel.
     * `BuildAndSendSUB.c:285` types `DAT_00bc1e04` as `int **` and compares
       it against an iterator's node pointer, so `puVar31[1] != ppiVar30` is
       `find(power) != end()`. `UpdateScoreState.c` runs the identical test in
       both of its passes.
     * `BuildAndSendSUB.c:230-236` clears the container and re-copies the
       current broadcast node's own set into it (`RegisterProposalOrders`) at
       the top of every trial iteration.
     * `register_received_press.c:64-75` builds that set from the sender plus
       every recipient, and it is the only set of power indices on the record;
       the other two are fed token lists through `FUN_00419300`.
   - Bound as `g_proposal_order_powers`, reloaded per trial iteration, and
     recorded on each entry by `register_received_press`. The no-press path is
     unchanged: C always has a node here and Python does not materialise the
     implicit base SUB node, so an entry carrying no participant information
     still covers every live power — which is what the round model degenerated
     to in practice, since every power stamped during the MC loop compared
     unequal to the post-loop `g_current_round`.

109. `ProposeDMZ` proposal tracking rebound to `g_active_dmz_list`

   - `ProposeDMZ.c:110-111` tests
     `*(char *)(Iterator_GetData(&iter) + 0x12)`. `Iterator_GetData` returns
     `node + 0xc`, so `+0x12` is `node + 0x1e` — the same `flag3` byte the two
     single-province arms read directly at `:216` and `:243`. The port read it
     as a lookup in a `g_active_dmz_map` that nothing ever wrote.
   - The `(power, province)` scan at `:112-140` walks `DAT_00bb7130/34`, whose
     records are `{power (+0), province (+4), send count (+8)}`:
     `FUN_00419df0` inserts them with count 1 at `:252-256`, `:337-340` and
     `:430-433`, and the single-province arms increment to a cap of 2. The
     port kept that count in a separate `g_sent_proposals` dict, so it never
     met `_apply_dmz`, which erases from the same list — an accepted DMZ could
     not re-open a province for proposing.
   - Also restored the marking loop's whole-list re-walk (every order entry
     sharing `(power, province)` is marked done, `:257-283`) and the
     capped-record abort: `if (bVar2) goto LAB_004334b0` leaves the success
     byte unset and returns instead of trying the next order entry.
   - Full suite: **443 tests**; `compileall` and `git diff --check` pass.

110. Audit coverage and confirmed-faithful routines

   - Verified faithful against their sources with no change required:
     `_eval_pce`, `_eval_not_pce`, `_eval_dmz`, `_eval_aly`, `_eval_drw`,
     `_eval_sub_xdo`, `EvaluatePress`, `RECEIVE_PROPOSAL`, `REMOVE_DMZ`,
     `CAL_MOVE`, `ParseHSTResponse`, `InboundDAIDEDispatcher`,
     `NOTDispatcher`, `YESDispatcher`, `CCD_Handler`, `NOT_CCD_Handler`,
     `OUT_Handler`, `UpdateRelationHistory`, `CancelPriorPress`,
     `BuildAllianceMsg`, `BuildHostilityRecord`, and `CAL_VALUE`'s
     broadcast-node matching walk.
   - `CAL_VALUE.c:206-330` reads the matched node's positive clauses from the
     set at `node+0x30` and its negative clauses from `node+0x3c`, in that
     fixed order. `register_received_press` writes its two entries with those
     two sets **swapped** relative to each other, so in C only the pass-1
     entry can ever match a well-formed proposal. The Python collapses both
     entries onto one polarity-tagged candidate list and always matches the
     pass-1 entry first, which coincides with C — but the two entries are no
     longer distinguishable, so the coincidence would break if the pass-1
     entry were ever removed from `g_broadcast_list` while pass-2 survived.
     No current code path removes it.
   - Swept every global container head in the recovered sources
     (`DAT_00baed74/80/98`, `bb65a4/c0/cc/e4/f0`, `bb6df8`, `bb6e04`,
     `bb6f20`, `bb7128/34/40`, `bbf60c/18/48/60`, `bc1e04`, `bc1e20`) for the
     `DAT_00bc1e04` misbinding class. All are documented as head/sentinel
     pointers on the Python side; `bc1e04` was the only remaining offender.
   - Swept the 275 `g_*` fields on `InnerGameState` for containers that no
     production path ever writes. Two were phantoms and are gone
     (`g_active_dmz_map`, `g_sent_proposals`). The rest are inert but
     harmless: `g_hold_weight`, `g_xdo_sup_mto_score` and `g_xdo_sup_hld_map`
     are self-documented legacy aliases with no reader, and `g_peace_zone`
     and `g_defense_zone` are placeholders for logic marked "port pending".
   - The following C files are inlined MSVC container mechanics with no
     Albert semantics and are correctly absorbed into Python data structures
     rather than ported: `RemoveOrderCandidate`, `InsertCandidateRecord`,
     `InsertOrderCandidate`, `Container_Destroy`, `ClearOrderList`,
     `ConcatTokenList`, `TokenList_BuildOffsets`, `UnitList_FindOrInsert`.
   - **Open gap found, not closed.** `BuildAndSendSUB.c:243-282` runs, once
     per proposal node whose history flag `puVar18[4]` is set, a full
     `ScoreOrderCandidates` pass followed by a restore of the
     `[n_powers][30]` best-order table from `DAT_00bc0a40/44` into
     `DAT_00bbf690/694` (`g_current_best_order`). Python models only
     `ScoreOrderCandidates`' writer loop, from `GenerateAndSubmitOrders`, and
     never performs the per-proposal rescore or the restore. Closing it needs
     `DAT_00bc0a40`'s writer, which does not appear in any recovered source,
     so the step is left unimplemented rather than invented.
   - The oracle corpora (`all_games`, `all_games_albert`) are absent from this
     working tree, so no item in 107-110 was measured against the movement or
     winter oracles.

111. `ComputeWinBuilds_Populate` versus `compute_win_builds` — unresolved

   - `BuildOrderSpec`'s insert descent is unambiguous: a new key goes **right**
     when `new_hi < node_hi`, or when `new_hi <= node_hi && new_lo <= node_lo`,
     and left otherwise. Smaller keys therefore sit to the right, in-order
     traversal is descending, `begin()` is the maximum and the rightmost
     element is the minimum. This is the premise item 106 already relies on.
   - `ComputeWinBuilds_Populate` builds its multiset once, keyed on the
     `this + pow*0xc + 0x4000` final score **plus 0x32 (50)**, then repeats
     `param_1` times: seed an iterator with `{container, header}` (that is,
     `end()`), step it with `FUN_0040f660`, commit via
     `FUN_00461010(this+8, prov, prov)`, and erase with `RemoveOrderCandidate`.
     `FUN_0040f660` is distinct from `TreeIterator_Advance` and
     `std_Tree_IteratorIncrement`, both of which the same file uses for forward
     iteration, so it is the decrement — the loop consumes the **minimum** key,
     exactly as `FUN_00442040` does for removals.
   - It is almost certainly `FUN_0044bd40`: it takes the same `(this, count)`
     shape send_GOF.c:402 passes, and it is the only recovered routine that
     increments `DAT_00baed34`, which send_GOF reads immediately after the WIN
     branch to size its sleep.
   - The port's `compute_win_builds` disagrees on two points. It selects
     `begin()` (the maximum), and it re-runs `score_provinces` plus
     `score_order_candidates_own_power` inside the selection loop so that
     `ScoreProvinces`' `+/-0x9c4` adjustments apply as each build is committed.
     Neither the per-iteration rescore nor a `begin()` consume appears in
     `ComputeWinBuilds_Populate`, whose multiset is built once, outside the
     loop.
   - Both readings are internally coherent: "build where the final score is
     lowest" is a defensible weakest-home-centre heuristic and would mirror the
     removal path exactly, while the port's per-iteration rescore is grounded
     in a real `ScoreProvinces` constant. They cannot both be `FUN_0044bd40`,
     so one of the two recoveries is partial.
   - **Left unchanged.** Flipping the selection end rewrites which centre gets
     built and cannot be validated while the oracle corpora are absent from the
     tree. Resolve it against `W1903A` first — that phase is already
     4/4 candidate-covered and 2/4 exact, so a build-side inversion should show
     up immediately.

112. `int_8` and `trial_count` are one record dword

   - `BuildHostilityRecord`'s copy constructor fixes the alliance record's
     layout exactly, and it matches `register_received_press`'s stack
     reconstruction field for field: byte at `+0x00`, dwords at `+0x04`/`+0x08`,
     three 12-byte containers at `+0x0c`/`+0x18`/`+0x24`, a 21-dword array at
     `+0x30`, a dword at `+0x84`, token lists at `+0x88`/`+0xa8`/`+0xbc`, a byte
     at `+0x98`, a time64 at `+0xa0`, and a word at `+0xb8`.
   - `local_1cc` is that record's `+0x08` dword, and `+0x08` is the field
     `BuildAndSendSUB` uses as the node's completed-trial counter:
     `BuildAndSendSUB.c:220` breaks the trial loop on
     `DAT_004c6bbc <= puVar18[8]`, `:226` copies it into `DAT_0062cc64`,
     `:373` writes it back after the round, and `:380-386` marks the node
     processed once it equals the cap.
   - `register_received_press.c:150-158` sets that dword to `DAT_004c6bbc`
     whenever `FUN_00426140`'s legitimacy gate returns non-null, so a gated
     proposal is enqueued **already at the cap** and skips the MC trial loop
     entirely — the gate has already decided, and the node goes straight to
     the post-loop handling.
   - The port wrote two Python keys for that one dword with conflicting
     values: `int_8` (the cap, which no reader consulted) and
     `trial_count: 0`. Every gated proposal therefore received a full run of
     trials. Unified onto `trial_count`; `int_8` is gone and
     `alliance.py`'s layout table now names the field for what it is.
   - The base SUB node still sorts first in `g_broadcast_list` (key 0, inserted
     by `_reset_broadcast_for_turn` ahead of every key >= 0), so the primary
     trial entry is unaffected and the movement path still runs its trials.
   - Full suite: **445 tests**; `compileall` and `git diff --check` pass.
   - Related divergence, left as-is: `GenerateAndSubmitOrders.c:102-106`
     destroys the whole broadcast tree each turn and rebuilds only the base SUB
     node, whereas `_reset_broadcast_for_turn` keeps a persistent tree and
     rewinds/retires its entries. That is a deliberate, load-bearing choice in
     the port, not an oversight.

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

## Open work, in priority order

0. Restore the oracle corpora (`all_games`, `all_games_albert`) to this
   working tree. They are Git-ignored and currently absent, so items 107-110
   were verified only against the source and the regression suite.

1. Expand candidate coverage beyond the bounded opening/S1902 checkpoints and
   trace any remaining movement-phase misses against their recovered source
   paths.
2. Obtain a structured DAIDE message history, serialized Albert press state,
   or a captured PRNG-state trace for at least one reference run. Human free
   text cannot reconstruct XDO/ALY/DMZ constraints, and a fixed seed cannot
   reproduce an unknown process-wide call history.
3. Correct or replace the inconsistent game 10 `S1904R` state/reference pair
   before treating 100% retreat coverage as a meaningful target.

4. Recover the writer of `DAT_00bc0a40/44` so `BuildAndSendSUB`'s
   per-proposal `ScoreOrderCandidates` pass and best-order-table restore
   (item 110) can be ported instead of skipped.

5. Settle item 111 against the `W1903A` oracle: `ComputeWinBuilds_Populate`
   consumes the ordered multiset's minimum, while `compute_win_builds`
   consumes its maximum and rescores per iteration. One of the two
   recoveries of `FUN_0044bd40` is partial.
