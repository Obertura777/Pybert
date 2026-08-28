# Python-port move-fidelity progress

Last updated: 2026-08-28

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

- `python -m pytest -q` passes: **256 tests**.
- `python -m compileall -q` passes for the repository's Python source and
  tests.
- `git diff --check` passes.
- The offline oracle harness now suppresses only the NetworkGame-only GOF
  signal. It no longer reports every successful local `diplomacy.Game` run as
  `PYBERT FAILED` because local games lack `no_wait()`.
- Latest bounded generation oracle, `game_10.json`, `S1901M`, primary seed 1
  plus seeds 0–7 for misses:
  Albert's complete set occurs in the legal candidate pool for **7/7 powers**
  (818 distinct complete legal candidates total), with **0 Python failures**.
  Submitted selection remains diagnostic at **0/7 exact sets** and **10/22
  unit orders**.
- Current hard combination test `game_10.json`, `S1902M`, Russia: seeds
  `{0,1,2}` produce 3,143 distinct legal candidates and cover all **6/6**
  reference orders individually, but the best complete candidate is **4/6**.
  The older seed-0 6/6 result is not reproducible after the source-backed
  token-key and convoy-route corrections and is no longer a verified claim.
- A historical pre-token-key sweep reached **21/21** complete opening sets
  across games 10, 100, and 1000. That broader sample has not yet been rerun
  after the latest source corrections; the current game-10 opening and Russia
  midgame evidence is reported above rather than inferred from that old sweep.
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

45. ComputeOrderDipFlags occupant decoding and split-word comparisons

   - `ComputeOrderDipFlags.c:69–115` preserves an occupant's power only when
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
   - Five focused regressions cover fleet-as-neutral behavior at the target,
     both same-province and adjacent exact-enemy gates, unsigned adjacent
     trust, and unsigned diplomacy state. The existing DMZ/press consumer
     tests also pass. Full suite: **195 tests**; `py_compile` and
     `git diff --check` pass.
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

1. Investigate the game 10 `S1902M` Russia combination gap. Seeds `{0,1,2}`
   cover all six reference orders individually, but the best complete legal
   candidate currently matches four of six.
2. Obtain a structured DAIDE message history, serialized Albert press state,
   or a captured PRNG-state trace for at least one reference run. Human free
   text cannot reconstruct XDO/ALY/DMZ constraints, and a fixed seed cannot
   reproduce an unknown process-wide call history.
3. Correct or replace the inconsistent game 10 `S1904R` state/reference pair
   before treating 100% retreat coverage as a meaningful target.
4. Rerun the broader opening and midgame bounded-seed sample after the latest
   token-key, convoy-route, chronology, and influence corrections. Historical
   results from older candidate pools must not be promoted to the current
   verification baseline.
