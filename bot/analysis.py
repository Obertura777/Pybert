"""Phase, position, and draw-vote analysis helpers.

Split from bot.py during the 2026-04 refactor.

Groups the decompile's analysis/ranking pipeline:

- ``_phase_handler``            — SetGamePhase snapshots (FUN_0040df20)
- ``_analyze_position``         — AnalyzePosition unit-count update (FUN_004119d0)
- ``_move_analysis``            — MOVE_ANALYSIS pressure/trust update (FUN_~0x435400)
- ``_post_process_orders``      — PostProcessOrders heuristics wrapper (FUN_00411120)
- ``_compute_press``            — ComputePress heuristics wrapper (FUN_004401f0)
- ``_cleanup_turn``             — NormalizeInfluenceMatrix trust-adjusted copy
- ``_prepare_draw_vote_set``    — PrepareDrawVoteSet (FUN_0044c9d0)
- ``_rank_candidates_for_power``— RankCandidatesForPower pipeline (FUN_00424850)
- ``_game_phase`` / ``_game_status`` — short-phase/status accessors

Cluster boundaries: module-level deps on ``..monte_carlo`` (order/field flags)
and ``..heuristics`` (post_process_orders, compute_press, compute_draw_vote,
_safe_pow).  No calls into other bot submodules.
"""

import logging

import numpy as np

from ..state import InnerGameState
from ..monte_carlo import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV,
    _ORDER_MTO, _ORDER_CTO, _ORDER_SUP_MTO,
)
from ..heuristics import (
    post_process_orders, compute_press, compute_draw_vote, _safe_pow,
)

logger = logging.getLogger(__name__)


def _phase_handler(state: InnerGameState, phase: int) -> None:
    """PhaseHandler (FUN_0040df20 / SetGamePhase).

    Snapshots g_ally_trust_score and g_relation_score (DAT_00634e90) into
    phase-indexed arrays at each sub-phase boundary (phase 0–3).

    research.md §6534:
      idx = power + phase * 21
      g_influence_snapshot[idx, j] ← g_relation_score[power, j]
      g_trust_snapshot[idx, j]     ← g_ally_trust_score[power, j]  (lo + hi word)
    """
    num_powers = 7

    if not hasattr(state, 'g_trust_snapshot'):
        # 4 phases × up to 21 powers; each entry holds one row of 7 values
        state.g_trust_snapshot    = np.zeros((4 * 21, 7), dtype=np.float64)
        state.g_trust_snapshot_hi = np.zeros((4 * 21, 7), dtype=np.int32)
        state.g_influence_snapshot = np.zeros((4 * 21, 7), dtype=np.int32)

    for power in range(num_powers):
        idx = power + phase * 21
        for j in range(num_powers):
            state.g_influence_snapshot[idx, j] = int(state.g_relation_score[power, j])
            state.g_trust_snapshot[idx, j]     = float(state.g_ally_trust_score[power, j])
            state.g_trust_snapshot_hi[idx, j]  = int(state.g_ally_trust_score_hi[power, j])


def _analyze_position(state: InnerGameState) -> None:
    """AnalyzePosition (FUN_004119d0).

    Counts live units per power and writes the result into g_unit_count
    (DAT_0062e460).  research.md §6560 corrects the prior "has-alliance flag"
    label: this array is a plain unit-count; non-zero ↔ power has units.
    """
    state.g_unit_count.fill(0)
    for unit in state.unit_info.values():
        power = unit.get('power', -1)
        if 0 <= power < 7:
            state.g_unit_count[power] += 1


def _move_analysis(state: InnerGameState) -> None:
    """MOVE_ANALYSIS (FUN_~0x435400).

    Evaluates inter-power pressure from the current order table and updates
    g_ally_trust_score based on observed aggression ratios.  On exactly one
    hostile power detected, sets g_opening_sticky_mode and g_opening_enemy.

    Decompile-verified structure (decompiled.txt):
      1. Per-(a,b) reach table: reach[a][adj]=1 for adj-of-a-units not occupied by b;
         upgrade to 2 where b-unit is adjacent; b5e8[a][b] = b-units adj to reach≥2 zones;
         bcd0[a][b] = b's MTO/CTO moving into a-reachable (reach 2→3), SUP_MTO similarly.
      2. Pre-ratio trust reset: non-own-power pairs with trust < 3 → force to 1.
      3. Ratio trust updates for all (a,b) pairs.
      4. Pre-compaction restore: if no current trust<2, restore first original low-trust ally.
      5. Slot invalidation (trust < 2 → drop), compact, best-ally check, sticky-enemy detect.
    """
    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)

    trust = state.g_ally_trust_score  # (7,7) float64; updated in-place

    # Save own_power's trust row before any modifications (for pre-compaction restore)
    orig_own_trust = trust[own_power, :].copy()

    bcd0 = np.zeros((num_powers, num_powers), dtype=np.int32)  # b's aggressive moves toward a
    af00 = np.zeros((num_powers, num_powers), dtype=np.int32)  # allied (a) units near contested dest
    b5e8 = np.zeros((num_powers, num_powers), dtype=np.int32)  # b-units pressuring a

    # Build province→power map and per-power province lists
    prov_power = np.full(256, -1, dtype=np.int32)
    power_provs: list[list[int]] = [[] for _ in range(num_powers)]
    for prov, unit in state.unit_info.items():
        p = unit.get('power', -1)
        if 0 <= p < num_powers:
            prov_power[prov] = p
            power_provs[p].append(prov)

    # --- Phases 1 & 2: per-(a,b) reach table ---------------------------------
    # For each attacking power a and defending power b:
    #   reach[adj]=1  ← adj province of an a-unit, not occupied by b
    #   reach[adj]=2  ← upgrade if also adjacent to a b-unit
    #   b5e8[a][b]    ← count b-units that have at least one reach≥2 adjacent province
    #   bcd0[a][b]    ← b's MTO/CTO moves into reach-2 zones (upgrade to 3); SUP_MTO similarly
    reach = np.zeros(256, dtype=np.int32)  # per-(a,b) scratch table

    for a in range(num_powers):
        for b in range(num_powers):
            if a == b:
                continue

            reach[:] = 0

            # Pass 1: mark adj-of-a-units that are NOT b-occupied as reach=1
            for prov in power_provs[a]:
                for adj in state.adj_matrix.get(prov, []):
                    if prov_power[adj] != b and reach[adj] == 0:
                        reach[adj] = 1

            # Pass 2: for each b-unit, upgrade reach-1 adjacent provinces to reach-2
            for b_prov in power_provs[b]:
                for adj in state.adj_matrix.get(b_prov, []):
                    if reach[adj] == 1:
                        reach[adj] = 2

            # Pass 3: count b5e8 and apply order effects for bcd0/af00
            for b_prov in power_provs[b]:
                # b5e8: b-unit counts if ANY adjacent province has reach≥2
                for adj in state.adj_matrix.get(b_prov, []):
                    if reach[adj] >= 2:
                        b5e8[a, b] += 1
                        break

                # Order effects (C types 2=MTO, 6=CTO, 4=SUP_MTO)
                order_type = int(state.g_order_table[b_prov, _F_ORDER_TYPE])
                dest       = int(state.g_order_table[b_prov, _F_DEST_PROV])

                if order_type in (_ORDER_MTO, _ORDER_CTO):      # C types 2 and 6
                    if 0 <= dest < 256:
                        # B-gate (C lines 287-296): bcd0 bump is gated on
                        # `g_ally_designation_b[dest] != b` — i.e. the move is
                        # NOT a consolidation into a province already
                        # B-designated for the attacker at start-of-season.
                        # Before 2026-04-14 this gate was missing → consolidation
                        # moves were over-counted as aggressive.
                        desig_b = (int(state.g_ally_designation_b[dest])
                                   if hasattr(state, 'g_ally_designation_b') else -1)
                        b_gate_open = (desig_b != b)  # B.lo != attacker
                        if reach[dest] == 2:
                            # b moves into a-reachable contested province → aggressive
                            if b_gate_open:
                                bcd0[a, b] += 1
                                for adj2 in state.adj_matrix.get(dest, []):
                                    if prov_power[adj2] == a:
                                        af00[a, b] += 1
                            reach[dest] = 3
                        elif reach[dest] == 3:
                            # b was moving to already-upgraded province → un-count
                            if b_gate_open:
                                bcd0[a, b] -= 1
                            reach[dest] = 2
                elif order_type == _ORDER_SUP_MTO:              # C type 4
                    # Only count if b is NOT supporting an a-unit
                    secondary = int(state.g_order_table[b_prov, _F_SECONDARY])
                    if (0 <= dest < 256
                            and not (0 <= secondary < 256 and prov_power[secondary] == a)
                            and reach[dest] >= 2):
                        bcd0[a, b] += 1

    # --- Pre-ratio trust reset -----------------------------------------------
    # Other powers' inter-trust: if not strongly allied (trust<3) → set to 1 (suspicious)
    for a in range(num_powers):
        if a == own_power:
            continue
        for b in range(num_powers):
            if a != b and trust[a, b] < 3:
                trust[a, b] = 1

    # --- Phase 3 — ratio-based trust updates (all (a,b) pairs) ---------------
    # ratio_ab = bcd0[a][b] / b5e8[a][b]: fraction of b's pressure that is aggressive toward a
    # High ratio_ab → b is hostile to a → trust[a][b] decreases
    for a in range(num_powers):
        for b in range(num_powers):
            if a == b:
                continue
            ratio_ab = float(bcd0[a, b]) / b5e8[a, b] if b5e8[a, b] > 0 else -1.0
            ratio_ba = float(bcd0[b, a]) / b5e8[b, a] if b5e8[b, a] > 0 else -1.0

            if ratio_ab < 0:
                continue  # no pressure from b toward a; skip

            if ratio_ab == 0.0:
                # b not aggressive → increment trust; if mutually non-aggressive: allies
                trust[a, b] += 1
                if ratio_ba == 0.0:
                    trust[a, b] = 5  # override: mutual non-aggression
                    logger.debug(
                        "Seems (%d) and (%d) have applied no pressure to each other", a, b)
            elif (ratio_ab == 1.0 and b5e8[a, b] == 1
                  and af00[a, b] == 0 and af00[b, a] == 0
                  and trust[a, b] > 1):
                trust[a, b] = 2  # single-unit bounce; may still ally
                logger.debug(
                    "Seems (%d) and (%d) have bounced and still may have a viable alliance",
                    a, b)
            elif ratio_ab >= 0.55:
                if trust[a, b] < 5:
                    trust[a, b] = 1  # high aggression → hostile
            else:  # 0 < ratio_ab < 0.55
                trust[a, b] += 1
                if ratio_ba == 0.0:
                    trust[a, b] += 1
                    logger.debug(
                        "Seems (%d) and (%d) have applied little pressure to each other", a, b)

    # --- Pre-compaction: restore original hostility if trust inflated --------
    # If no power currently has trust<2 but originally some did, restore the first such ally.
    # (C: cStack_bd79 / LAB_00435fe6 guard; prevents false trust upgrades.)
    has_low_trust_now = any(
        trust[own_power, p] < 2 for p in range(num_powers) if p != own_power
    )
    if not has_low_trust_now:
        for p in range(num_powers):
            if p != own_power and orig_own_trust[p] < 2:
                trust[own_power, p] = orig_own_trust[p]
                break

    # --- Phase 4 — opening ally selection ------------------------------------
    # Invalidate ally slots where trust dropped below 2 (distrusted)
    for attr in ('g_best_ally_slot0', 'g_best_ally_slot1', 'g_best_ally_slot2'):
        slot = getattr(state, attr, -1)
        if 0 <= slot < num_powers and trust[own_power, slot] < 2:
            setattr(state, attr, -1)

    # Compact: shift valid slots to front (left-pack)
    slots = [getattr(state, f'g_BestAllySlot{i}', -1) for i in range(3)]
    valid = [s for s in slots if s >= 0]
    while len(valid) < 3:
        valid.append(-1)
    state.g_best_ally_slot0, state.g_best_ally_slot1, state.g_best_ally_slot2 = (
        valid[0], valid[1], valid[2])

    # Best ally (after compaction) fully pressured by one power → g_ally_under_attack
    best_ally = getattr(state, 'g_best_ally_slot0', -1)
    if 0 <= best_ally < num_powers:
        for c in range(num_powers):
            if (c != best_ally
                    and bcd0[best_ally, c] > 1
                    and bcd0[best_ally, c] == b5e8[best_ally, c]):
                state.g_ally_under_attack = 1
                logger.debug(
                    "Best ally (%d) severely pressured by power (%d)", best_ally, c)
                break

    # Detect single hostile (trust==1) power → sticky enemy mode
    hostile = [p for p in range(num_powers) if trust[own_power, p] == 1]
    if len(hostile) == 1:
        p = hostile[0]
        state.g_opening_sticky_mode = 1
        state.g_opening_enemy      = p
        trust[own_power, p]       = 0
        state.g_stabbed_flag       = 1   # DAT_00baed5f = g_EnemyDesired
        logger.debug("Enemy set to single original enemy: power %d", p)
        return  # goto LAB_00436427 (skip triple-front check)

    # Triple-front mode: demote trust-3 entries to trust-1 for own_power
    if getattr(state, 'g_triple_front_flag', 0) == 1:
        for p in range(num_powers):
            if trust[own_power, p] == 3:
                trust[own_power, p] = 1


def _post_process_orders(state: InnerGameState) -> None:
    """PostProcessOrders (FUN_00411120). Decays g_move_history_matrix and
    updates it from submitted-order outcomes. research.md §2039."""
    post_process_orders(state)


def _compute_press(state: InnerGameState) -> None:
    """ComputePress (FUN_004401f0). Builds g_press_matrix / g_press_count.
    research.md §1295."""
    compute_press(state)


def _cleanup_turn(state: InnerGameState) -> None:
    """NormalizeInfluenceMatrix. Trust-adjusts g_influence_matrix_raw by
    (g_ally_trust_score + 1), injects _safe_pow noise, and row-normalises to 100.

    Was mislabelled 'Per-turn cleanup'; corrected per _index.md.
    Writes g_influence_matrix (consumed by compute_influence_matrix ranking).

    Decompile: decompiled.txt lines 460-593.
    Phases match GenerateOrders Phase 4-5 but operate on Raw/trust-adjusted copy.
    """
    n = 7  # numPowers

    # Phase 1 — trust-adjust: g_influence_matrix[row,col] = Raw[row,col] / (trust+1)
    # C: DAT_00b82db8 = g_influence_matrix_raw / CONCAT44(trust_hi+carry, trust_lo+1)
    for row in range(n):
        for col in range(n):
            raw   = float(state.g_influence_matrix_raw[row, col])
            trust = float(state.g_ally_trust_score[row, col])
            state.g_influence_matrix[row, col] = raw / (trust + 1.0)

    # Phase 2 — per-power row sum via PackScoreU64 (trunc toward zero, not banker's round;
    # FRNDINT+correction always restores truncation)
    # C: DAT_004f6b98[power*2] = PackScoreU64() after FPU row-sum accumulation
    power_sum = np.array(
        [int(float(np.sum(state.g_influence_matrix[p]))) for p in range(n)],
        dtype=np.int64,
    )

    # Phase 3 — per-cell noise: cell += _safe_pow(cell / (col_sum+1), 0.3) * 500
    # C: fVar8 = _safe_pow(); *pdVar6 = fVar8 * 500.0 + *pdVar6
    # base exponent 0.3 = DAT_004af9f8 (33 33 33 33 33 33 d3 3f)
    for row in range(n):
        for col in range(n):
            col_total = float(power_sum[col])
            base = float(state.g_influence_matrix[row, col]) / (col_total + 1.0)
            state.g_influence_matrix[row, col] += _safe_pow(base, 0.3) * 500.0

    # Phase 4 — row-normalise to 100
    # C: cell = (cell * 100.0) / row_sum  (skipped when row_sum == 0)
    for row in range(n):
        row_sum = float(np.sum(state.g_influence_matrix[row]))
        if row_sum != 0.0:
            state.g_influence_matrix[row] = (state.g_influence_matrix[row] * 100.0) / row_sum


def _prepare_draw_vote_set(state: InnerGameState) -> None:
    """Port of PrepareDrawVoteSet (FUN_0044c9d0).

    Builds the friendly-powers set (own power ∪ {p : sc_count[p]>0 AND
    trust(own,p)>1}), calls ComputeDrawVote, and stores the result in
    state.g_draw_sent.

    C trust condition: Hi >= 0 AND (Hi > 0 OR Lo > 1)
      where Hi = g_ally_trust_score_hi[own,p], Lo = g_ally_trust_score[own,p].

    The C function also manages a std::map allocator and C++ ref-counts on
    an intermediate proposal-context object (SerializeOrders + _free); those
    are absorbed as Python GC.

    Decompile: decompiled.txt lines 42–123.
    """
    own = int(state.albert_power_idx)
    num_powers = state.sc_count.shape[0]

    friendly_powers: set = {own}
    for p in range(num_powers):
        if p == own:
            continue
        if int(state.sc_count[p]) > 0:
            hi = int(state.g_ally_trust_score_hi[own, p])
            lo = int(state.g_ally_trust_score[own, p])
            # C: trust > 1  ⟺  Hi >= 0 AND (Hi > 0 OR Lo > 1)
            if hi >= 0 and (hi > 0 or lo > 1):
                friendly_powers.add(p)

    draw_vote = compute_draw_vote(state, friendly_powers)

    # C (GenerateAndSubmitOrders.c:482): send DRW when any of four flags is set:
    #   DAT_00baed29 | DAT_00baed2a | DAT_00baed2b | DAT_00baed30
    # Mapping:
    #   DAT_00baed29 — unknown (possibly external draw-request signal); left in
    #                  g_draw_flags pass-through bucket.
    #   DAT_00baed2a — g_request_draw_flag   (set by CAL_BOARD phase 4a: big lead).
    #   DAT_00baed2b — g_DrawVoteFlag      (result of ComputeDrawVote → draw_vote).
    #   DAT_00baed30 — g_static_map_flag     (set when the map hasn't moved in many turns).
    request_draw  = int(getattr(state, 'g_request_draw_flag', 0)) == 1
    static_map    = int(getattr(state, 'g_static_map_flag',  0)) == 1
    extra_draw_flags = getattr(state, 'g_draw_flags', [])
    if draw_vote or request_draw or static_map or any(extra_draw_flags):
        logger.info(
            "Draw vote: will accept DRW proposals (voting YES) "
            "[draw_vote=%s, request_draw=%s, static_map=%s]",
            draw_vote, request_draw, static_map,
        )
        state.g_draw_sent = 1
    else:
        logger.debug("Draw vote: will reject DRW proposals (no vote sent)")
        state.g_draw_sent = 0


def _rank_candidates_for_power(state: InnerGameState, power_idx: int) -> None:
    """FUN_00424850 — RankCandidatesForPower.

    Called from BuildAndSendSUB (inner loop) as FUN_00424850(power_idx, '\\0').
    Selects the best order candidates for *power_idx* from
    g_candidate_record_list via a 7-phase pipeline:

      Phase 1  Find max score among this power's candidates.
      Phase 2  Build sorted list (ascending adjusted score; offset = 2500 - max).
      Phase 3  Pareto-dominance filter across all completed MC-trial dimensions
               (penalty 100 if n_allies==0, else 50).  Pareto-selected
               candidates accumulate an accepted frontier; dominated ones get
               a rank number and update min/max_rank.
      Phase 4  Probability scoring: each non-processed candidate's share of
               "remaining probability space" based on SC counts vs. up to
               three left-neighbours; write to rec['weight'] and update EMA
               of rec['running_avg'].
      Phase 5  Re-sort (same offset; order unchanged in practice).
      Phase 6  Rank/select: promote candidates whose running_avg ≥ threshold
               (call_count + 1) subject to rank/near-end-game guards.
               Promoted → processed=1, score = −1 000 000 − rank,
               output_score same, g_score_baseline += 1.
      Phase 7  Normalize output_score: redistribute remaining probability
               budget (capped at 90) among non-promoted candidates.

    Only the param_2=='\\0' path is implemented (used by BuildAndSendSUB).

    Callees (C++, absorbed into Python list ops / math):
      FUN_00410330  — allocate list/tree node (absorbed into local list)
      FUN_00465870  — init empty token list (absorbed)
      FUN_0040fb70  — free list internals (absorbed)
      FUN_0040f260  — advance g_candidate_record_list iterator (absorbed)
      FUN_00419fa0  — sorted-list insert (absorbed into sort())
      FUN_00412540  — advance accepted-frontier pointer (absorbed)
      FUN_0040e680  — basic iterator advance (absorbed)
      FUN_00414e10  — sorted-list destructor (absorbed)
    """
    # ── globals ───────────────────────────────────────────────────────────
    # DAT_0062cc64 — number of completed MC trials at call time
    n_trials: int = getattr(state, 'g_n_trials_completed', 0)
    # DAT_0062e460[power] — unit count (non-zero = active)
    unit_count_arr = state.g_unit_count
    # DAT_00b9fe88[power] — ProcessTurn call count
    call_count_arr = getattr(state, 'g_PowerCallCount',
                             np.zeros(7, dtype=np.int32))
    near_end: float = state.g_near_end_game_factor

    sc_count_local: int = int(unit_count_arr[power_idx]) + 1   # local_90 init
    alpha: float = (n_trials / (n_trials + 2)) if n_trials >= 0 else 0.0  # local_7c
    threshold: float = float(int(call_count_arr[power_idx]) + 1)  # local_80 (param_2=='\0' path)

    # ── Phase 1: find max score ──────────────────────────────────────────
    SENTINEL = -(1 << 20)
    max_score: int = SENTINEL
    for rec in state.g_candidate_record_list:
        if rec.get('power_idx', rec.get('power', -1)) == power_idx:
            s = int(rec.get('score', 0))
            if max_score == SENTINEL or s > max_score:
                max_score = s
    if max_score == SENTINEL:
        return  # no candidates for this power

    score_offset: int = 0x9C4 - max_score   # local_78 = 2500 - max_score

    # ── Phase 2: sorted list by adjusted score ───────────────────────────
    power_recs = [
        rec for rec in state.g_candidate_record_list
        if rec.get('power_idx', rec.get('power', -1)) == power_idx
    ]
    power_recs.sort(key=lambda r: int(r.get('score', 0)) + score_offset)

    # ── Phase 3: Pareto-dominance filter ────────────────────────────────
    # accepted_frontier holds the "not yet dominated" prefix of the sorted list.
    # A candidate is dominated if any frontier member beats it on ALL
    # trial dims by ≥ penalty AND their final-dim scores differ.
    accepted_frontier: list = []
    rank_counter: int = 0   # local_b8 (integer rank for non-Pareto items)

    for cand in power_recs:
        if cand.get('processed', 0):
            continue

        n_allies: int = int(cand.get('n_allies', 0))
        penalty: int = 100 if n_allies == 0 else 50
        trial_scores_c = cand.get('trial_scores', [])
        final_dim_c: int = cand.get('final_dim_score', 0)

        dominated = False
        for prev in accepted_frontier:
            trial_scores_p = prev.get('trial_scores', [])
            final_dim_p: int = prev.get('final_dim_score', 0)
            # Skip dim 0 if n_trials > 7 (start at 2); check dims 0..n_trials
            start_dim = 2 if n_trials > 7 else 0
            prev_dominates_all = True
            for t in range(start_dim, n_trials + 1):
                ps = trial_scores_p[t] if t < len(trial_scores_p) else 0
                cs = trial_scores_c[t] if t < len(trial_scores_c) else 0
                if ps < cs + penalty:
                    prev_dominates_all = False
                    break
            if prev_dominates_all and final_dim_p != final_dim_c:
                dominated = True
                break

        if not dominated:
            cand['pareto_flag'] = 1
            cand['running_avg'] = (
                (1.0 - alpha) * rank_counter
                + alpha * float(cand.get('running_avg', 0.0))
            )
            accepted_frontier.append(cand)
        else:
            cand['pareto_flag'] = 0
            ri = rank_counter
            if ri < int(cand.get('min_rank', 10001)):
                cand['min_rank'] = ri
            if int(cand.get('max_rank', 0)) < ri:
                cand['max_rank'] = ri
            rank_counter += 1

    # ── Phase 4: probability scoring ────────────────────────────────────
    # Walk non-processed records in sorted order; for each compute a
    # "share of remaining territory" using up to 3 left-neighbours'
    # SC counts via _safe_pow-based Elo-like formulas.
    # local_90 accumulates (starts at sc_count_local).
    non_proc = [r for r in power_recs if not r.get('processed', 0)]
    running_pool: float = float(sc_count_local)  # local_90

    for i, cand in enumerate(non_proc):
        sc_i: float = float(max(int(cand.get('sc_count', 0)), 0))
        share_a = 0.0   # local_b4
        share_b = 0.0   # local_48 low word
        share_c = 0.0   # local_68 low word

        if sc_i > 0:
            # Neighbour 1 (i-1): share_a = sc_j / (pow(sc_i-sc_j, sc_j) + sc_i + sc_j)
            if i >= 1:
                sc_j = float(max(int(non_proc[i - 1].get('sc_count', 0)), 0))
                if sc_j > 0:
                    diff_a = sc_i - sc_j
                    powered_a = _safe_pow(diff_a, sc_j) if diff_a != 0 else 1.0
                    denom_a = powered_a + sc_i + sc_j
                    share_a = sc_j / denom_a if denom_a else 0.0

            # Neighbour 2 (i-2): share_b = sc_k*0.666 / (pow(sc_i-sc_k,sc_k*0.666) + sc_i + sc_k)
            if i >= 2:
                sc_k = float(max(int(non_proc[i - 2].get('sc_count', 0)), 0))
                if sc_k > 0:
                    exp_b = sc_k * 0.666
                    diff_b = sc_i - sc_k
                    powered_b = _safe_pow(diff_b, exp_b) if diff_b != 0 else 1.0
                    denom_b = powered_b + sc_i + sc_k
                    share_b = exp_b / denom_b if denom_b else 0.0

            # Neighbour 3 (i-3): share_c = sc_l*0.5 / (pow(sc_i-sc_l,sc_l*0.5) + sc_i + sc_l)
            if i >= 3:
                sc_l = float(max(int(non_proc[i - 3].get('sc_count', 0)), 0))
                if sc_l > 0:
                    exp_c = sc_l * 0.5
                    diff_c = sc_i - sc_l
                    powered_c = _safe_pow(diff_c, exp_c) if diff_c != 0 else 1.0
                    denom_c = powered_c + sc_i + sc_l
                    share_c = exp_c / denom_c if denom_c else 0.0

        # fVar1 = (1.0 - share_b) * (100.0 - running_pool) * (1.0 - share_a) * (1.0 - share_c)
        fVar1 = (1.0 - share_b) * (100.0 - running_pool) * (1.0 - share_a) * (1.0 - share_c)
        cand['weight'] = fVar1          # ppiVar6[5][0x16]
        running_pool += fVar1           # local_90 accumulates

        # EMA update: running_avg = (1-alpha)*rank_position + alpha*old_avg
        rank_pos = float(i)             # local_b8 at this point (count of processed so far)
        cand['running_avg'] = (
            (1.0 - alpha) * rank_pos
            + alpha * float(cand.get('running_avg', 0.0))
        )

    # ── Phase 5: re-sort with same offset (already sorted; no-op) ───────

    # ── Phase 6: rank/select ─────────────────────────────────────────────
    rank_b: float = 0.0
    near_end_count: float = 0.0

    for cand in power_recs:
        # Count near-end-game non-processed candidates with move orders
        if int(cand.get('has_moves', 0)) and not cand.get('processed', 0) and near_end < 7.0:
            near_end_count += 1.0

        running_avg_f = float(cand.get('running_avg', 0.0))
        rank_i = int(rank_b)
        min_rank_v = int(cand.get('min_rank', 10001))
        pareto_f = int(cand.get('pareto_flag', 0))

        # Conditions that force "skip/demote" (goto LAB_00425626):
        # (a) running_avg < threshold, OR
        # (b) min_rank >= 6 AND rank >= 10, OR
        # (c) has_moves AND near_end_count < 10, OR
        # (d) already processed
        skip = (
            running_avg_f < threshold
            or (min_rank_v >= 6 and rank_i >= 10)
            or (bool(cand.get('has_moves', 0)) and near_end_count < 10.0)
            or bool(cand.get('processed', 0))
        )

        if not skip:
            # Promote: mark as selected, assign negative rank score
            final_s = -1000000 - rank_i
            cand['processed'] = 1
            cand['weight'] = 0.0
            cand['score'] = final_s
            cand['output_score'] = float(final_s)
            state.g_score_baseline += 1
        else:
            # Demoted: clear pareto-selected weight, blend output_score
            if pareto_f == 1:
                cand['weight'] = 0.0
                cand['output_score'] = 0.0
            if n_trials >= 1:
                w = float(cand.get('weight', 0.0))
                os_old = float(cand.get('output_score', 0.0))
                cand['output_score'] = (1.0 - alpha) * w + os_old * alpha
            else:
                cand['output_score'] = float(cand.get('weight', 0.0))
            # Update rank bounds
            if rank_i < int(cand.get('min_rank', 10001)):
                cand['min_rank'] = rank_i
            if int(cand.get('max_rank', 0)) < rank_i:
                cand['max_rank'] = rank_i

        rank_b += 1.0

    # ── Phase 7: normalize output_score ─────────────────────────────────
    # Sum output_score for non-processed candidates → remaining = 100 - sum.
    # Cap remaining at 90.  Redistribute proportionally.
    total_os: float = sum(
        float(r.get('output_score', 0.0))
        for r in power_recs if not r.get('processed', 0)
    )
    remaining = 100.0 - total_os
    if remaining > 90.0:
        remaining = 90.0
    denom_n = 100.0 - remaining
    if denom_n and remaining > 0.0:
        for cand in power_recs:
            if not cand.get('processed', 0):
                os = float(cand.get('output_score', 0.0))
                cand['output_score'] = os + remaining * os / denom_n


def _game_phase(game) -> str:
    """Return the current short-phase string for either an engine.Game or NetworkGame."""
    if hasattr(game, 'get_phase'):
        return game.get_phase()
    # diplomacy library: use the property `current_short_phase` (e.g. 'S1901M')
    return getattr(game, 'current_short_phase', '') or ''


def _game_status(game) -> str:
    """Return game status ('forming'|'active'|'paused'|'completed'|'canceled')."""
    return getattr(game, 'status', '') or ''
