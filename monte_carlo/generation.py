"""Monte-Carlo candidate order-generation pipeline.

Split from monte_carlo.py during the 2026-04 refactor.

``generate_orders`` runs the province-scoring + candidate-enumeration pre-pass
that produces the hold/move/support/convoy order-candidate lists the MC
trial loop consumes.  Calls into ``..moves`` enumerators and defers an
``apply_influence_scores`` call into ``..heuristics`` (kept deferred to
avoid the heuristics→monte_carlo import cycle).

Module-level deps: ``numpy``, ``..state.InnerGameState``, and
the four enumerators from ``..moves``.
"""


import numpy as np

from ..state import InnerGameState
from ..moves import (
    enumerate_hold_orders,
    enumerate_convoy_reach,
    populate_convoy_routes,
    compute_safe_reach,
    build_support_opportunities,
)


def generate_orders(state: InnerGameState, own_power: int) -> None:
    """
    Port of FUN_004466e0 = GenerateOrders(Albert *this).

    Master turn-evaluation driver.  Computes the full influence-matrix pipeline,
    populates g_candidate_scores, g_alliance_score, and g_opening_target, then
    triggers the order-enumeration pipeline.

    Phases (research.md §GenerateOrders — FUN_004466e0 / §generate_orders):
      Phase 0  — Zero all scoring tables and influence matrices.
      Phase 1  — Per-power loop: urgency seed → 5-round BFS heat diffusion →
                 candidate scores → g_heat_movement → g_influence_matrix accumulation.
      Phase 3  — Snapshot g_influence_matrix → g_influence_matrix_raw.
      Phase 4  — Per-power noise injection (_safe_pow approx).
      Phase 5  — Row-normalize g_influence_matrix to row-sums of 100.
      Phase 6  — Asymmetric g_alliance_score from Raw matrix.
      Phase 7  — g_opening_target per power (SPR + g_deceit_level==1 only).
      Finally  — enumerate_hold_orders, enumerate_convoy_reach, compute_safe_reach,
                 build_support_opportunities (mirrors post-loop calls in binary).
    """
    NUM_POWERS   = 7
    NUM_PROVINCES = 256
    # Valid province IDs (C checks "alive" flag, skips non-existent ones).
    valid_provs = getattr(state, 'valid_provinces', None) or range(NUM_PROVINCES)

    # Record own power so that downstream MC functions can resolve Albert's index.
    state.albert_power_idx = own_power

    # ── InitScoringState ─────────────────────────────────────────────────────
    # C: InitScoringState is called first thing in GenerateOrders (line 100).
    # Lazy import avoids the bot.orders→monte_carlo→generation circular dep.
    from ..bot.orders import _init_scoring_state
    _init_scoring_state(state)

    # ── Phase 0 — Init ───────────────────────────────────────────────────────
    # Note: g_candidate_scores, g_target_flag, and several reach arrays are
    # already zeroed by _init_scoring_state above (GenerateOrders.c:102-130).
    state.g_heat_movement.fill(0)
    state.g_influence_matrix.fill(0)
    state.g_influence_matrix_raw.fill(0)
    state.g_influence_matrix_b.fill(0)
    state.g_alliance_score.fill(0)
    state.g_global_province_score.fill(0)
    state.g_needs_rescore.fill(-1)   # 0xffffffff sentinel

    # ── Phase 1 — Per-power heat diffusion + candidate scoring ───────────────
    for p in range(NUM_POWERS):
        curr_sc  = int(state.sc_count[p])
        # C: target_sc_cnt[p] from InitScoringState (was hardcoded to 18)
        target_sc = int(state.g_target_sc_cnt[p])

        # 1a — Province urgency scoring → heat_build seed (aiStack_6018 equivalent)
        # research.md §5440–5451: g_StickyModeActive → 5000; SC-need formula otherwise.
        heat_build_seed = np.zeros(NUM_PROVINCES, dtype=np.float64)
        for prov in valid_provs:
            if state.get_unit_power(prov) != p:
                heat_build_seed[prov] = 0.0
            elif state.g_uniform_mode == 1:          # g_StickyModeActive / g_uniform_mode
                heat_build_seed[prov] = 5000.0
            elif target_sc > curr_sc:
                heat_build_seed[prov] = float((target_sc - curr_sc + 2) * 500)
            else:
                heat_build_seed[prov] = 1000.0

        # 1b — 5-round BFS → heat_build (auStack_3818 equivalent)
        # Each round: cur[p] = sum(prev[q] for q in adj[p]) / 5
        heat_build = heat_build_seed.copy()
        for _ in range(5):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.float64)
            for prov in valid_provs:
                adjs = state.get_unit_adjacencies(prov)
                if adjs:
                    nxt[prov] = sum(heat_build[q] for q in adjs) / 5.0
            heat_build = nxt

        # 1c — Home-unit seed → heat_move seed (local_3018 equivalent, +5000 per own unit)
        heat_move_seed = np.zeros(NUM_PROVINCES, dtype=np.float64)
        for prov, info in state.unit_info.items():
            if info['power'] == p:
                heat_move_seed[prov] = 5000.0

        # 1d — 5-round BFS → heat_move (auStack_818 equivalent)
        heat_move = heat_move_seed.copy()
        for _ in range(5):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.float64)
            for prov in valid_provs:
                adjs = state.get_unit_adjacencies(prov)
                if adjs:
                    nxt[prov] = sum(heat_move[q] for q in adjs) / 5.0
            heat_move = nxt

        # 1e — Accumulate g_global_province_score
        for prov in valid_provs:
            state.g_global_province_score[prov] += heat_build[prov] + heat_move[prov]

        # 1f — Build ordered set, populate g_candidate_scores (top-N by heat_move)
        # C (GenerateOrders.c:400–468): provinces sorted descending by heat_move
        # are inserted into an ordered set; the iterator takes at most win_threshold
        # entries, skipping any province where own army sits (puVar12 == local_60b4).
        # Albert+0x3ff8 = the limit field (= win_threshold, set at Albert+0x3ffc by
        # InitPositionForOrders).  Own-fleet and empty provinces are included
        # (C encodes fleets/empty as power=0x14, which never equals a real power).
        top_n = int(getattr(state, 'win_threshold', 18))
        _scored = sorted(
            ((heat_move[prov], prov) for prov in valid_provs if heat_move[prov] > 0),
            reverse=True,
        )
        _count = 0
        for _score, prov in _scored:
            if _count >= top_n:
                break
            u = state.unit_info.get(prov)
            if u is not None and u.get('power') == p and u.get('type', '') in ('A', 'AMY'):
                continue
            state.g_candidate_scores[p, prov] = _score
            _count += 1

        # 1g — Copy heat_move → g_heat_movement[p]
        state.g_heat_movement[p] = heat_move

        # 1h — Accumulate g_influence_matrix[col, p]
        # GenerateOrders.c L366: two-condition gate:
        #   (puVar11[1] != local_6054) && (local_60b4 != local_60bc)
        # Ghidra conflates the outer loop counter with GameBoard_GetPowerRec's
        # output param (same stack slot reuse).  Resolved semantics:
        #   condition 1: unit_power_at_prov != col
        #   condition 2: p != unit_power_at_prov  (excludes own-power provinces)
        # Empty provinces (unit_power == -1) pass both gates (−1 != any 0..6).
        for col in range(NUM_POWERS):
            if col == p:
                continue
            total = 0.0
            for prov in valid_provs:
                unit_power = state.get_unit_power(prov)
                if unit_power != col and p != unit_power:
                    total += heat_build[prov] + heat_move[prov]
            state.g_influence_matrix[col, p] = total

    # ── Phase 3–4 — Snapshot Raw, inject noise ────────────────────────────────
    # Phase 3: copy g_influence_matrix → g_influence_matrix_raw
    state.g_influence_matrix_raw = state.g_influence_matrix.copy()
    # g_InfluenceMatrix_B (GenerateOrders.c:352-383) uses the same per-power gate
    # and heat arrays as Phase 1h; it equals the pre-normalization raw matrix.
    state.g_influence_matrix_b[:] = state.g_influence_matrix_raw

    # Phase 4: per-cell noise via _safe_pow (FUN_0047b370).
    # Formula: B[i][j] += pow(B[i][j] / (sum[j] + 1), 0.3) * 500.0
    # where sum[j] = column sum of Raw for power j (g_PowerInfluenceSum[col]).
    # ST1=base=B[i][j]/(sum[j]+1), ST0=exponent=0.3 (DAT_004af9f8).
    col_sums = np.sum(state.g_influence_matrix_raw, axis=0).astype(float)  # shape (NUM_POWERS,)
    for i in range(NUM_POWERS):
        for j in range(NUM_POWERS):
            base = state.g_influence_matrix[i, j] / (col_sums[j] + 1.0)
            state.g_influence_matrix[i, j] += (base ** 0.3) * 500.0

    # ── Phase 5 — Row-normalize g_influence_matrix to row-sums of 100 ─────────
    for i in range(NUM_POWERS):
        row_sum = float(np.sum(state.g_influence_matrix[i]))
        if row_sum != 0.0:
            state.g_influence_matrix[i] *= 100.0 / row_sum

    # ── Phase 6 — Compute asymmetric g_alliance_score ─────────────────────────
    # research.md §5568–5584:
    #   col_sum[row] = column sum of Raw over all rows (= total influence directed at row)
    #   A = Raw[row][col], B = Raw[col][row]
    #   A < B → col threatens row more → g_alliance_score[row][col] = -3*(A/(B+1))*(B/col_sum)
    #   else  → row dominates col      → g_alliance_score[row][col] = +3*(B/(A+1))*(B/col_sum)
    for row in range(NUM_POWERS):
        col_sum = float(np.sum(state.g_influence_matrix_raw[:, row]))
        curr_sc_row = int(np.sum(state.g_sc_ownership[row]))
        for col in range(NUM_POWERS):
            if col == row:
                continue
            curr_sc_col = int(np.sum(state.g_sc_ownership[col]))
            if curr_sc_row == 0 or curr_sc_col == 0:
                state.g_alliance_score[row, col] = 0.0
            else:
                A = float(state.g_influence_matrix_raw[row, col])
                B = float(state.g_influence_matrix_raw[col, row])
                denom = col_sum if col_sum != 0.0 else 1.0
                if A < B:
                    state.g_alliance_score[row, col] = -3.0 * (A / (B + 1.0)) * (B / denom)
                else:
                    state.g_alliance_score[row, col] =  3.0 * (B / (A + 1.0)) * (B / denom)

    # ── ApplyInfluenceScores ────────────────────────────────────────────────
    # C binary: GenerateOrders.c L619 calls ApplyInfluenceScores after the
    # per-power heat/influence loop.  This populates g_unit_adjacency_count
    # (Pass 4), g_heat_movement_b (Pass 1), and — crucially — g_order_list
    # (Pass 5), which downstream feeds g_general_orders via the press
    # translator pipeline.  Without this call g_order_list stays empty and
    # the MC trial loop (ProcessTurn Phase 1c) has no orders to dispatch.
    from ..heuristics import apply_influence_scores, set_opening_targets
    apply_influence_scores(state, own_power)
    set_opening_targets(state)

    # ── Order enumeration pipeline ───────────────────────────────────────────
    # Mirrors the post-loop calls in the binary (EnumerateHoldOrders,
    # EnumerateConvoyReach, ComputeSafeReach, BuildSupportOpportunities).
    for p in range(NUM_POWERS):
        enumerate_hold_orders(state, p)
        enumerate_convoy_reach(state, p)
        # Populates state.g_convoy_route[army_src] for each army of p with a
        # shortest fleet chain (option-1 narrow port of ProcessTurn's convoy
        # route BFS — see moves/convoy.py:populate_convoy_routes).  Without
        # this, the CTO branches in trial.py:553 and :1046 silently fall
        # back to direct moves and no CVY orders are ever emitted.
        populate_convoy_routes(state, p)
    compute_safe_reach(state)
    build_support_opportunities(state)
