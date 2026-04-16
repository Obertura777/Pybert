"""Monte-Carlo candidate order-generation pipeline.

Split from monte_carlo.py during the 2026-04 refactor.

``generate_orders`` runs the province-scoring + candidate-enumeration pre-pass
that produces the hold/move/support/convoy order-candidate lists the MC
trial loop consumes.  Calls into ``..moves`` enumerators and defers an
``apply_influence_scores`` call into ``..heuristics`` (kept deferred to
avoid the heuristics→monte_carlo import cycle).

Module-level deps: ``numpy``, ``random``, ``..state.InnerGameState``, and
the four enumerators from ``..moves``.
"""

import random

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
    populates g_CandidateScores, g_AllianceScore, and g_OpeningTarget, then
    triggers the order-enumeration pipeline.

    Phases (research.md §GenerateOrders — FUN_004466e0 / §generate_orders):
      Phase 0  — Zero all scoring tables and influence matrices.
      Phase 1  — Per-power loop: urgency seed → 5-round BFS heat diffusion →
                 candidate scores → g_HeatMovement → g_InfluenceMatrix accumulation.
      Phase 3  — Snapshot g_InfluenceMatrix → g_InfluenceMatrix_Raw.
      Phase 4  — Per-power noise injection (_safe_pow approx).
      Phase 5  — Row-normalize g_InfluenceMatrix to row-sums of 100.
      Phase 6  — Asymmetric g_AllianceScore from Raw matrix.
      Phase 7  — g_OpeningTarget per power (SPR + g_DeceitLevel==1 only).
      Finally  — enumerate_hold_orders, enumerate_convoy_reach, compute_safe_reach,
                 build_support_opportunities (mirrors post-loop calls in binary).
    """
    NUM_POWERS   = 7
    NUM_PROVINCES = 256

    # Record own power so that downstream MC functions can resolve Albert's index.
    state.albert_power_idx = own_power

    # ── Phase 0 — Init ───────────────────────────────────────────────────────
    state.g_CandidateScores.fill(0)
    state.g_HeatMovement.fill(0)
    state.g_TargetFlag.fill(0)
    state.g_InfluenceMatrix.fill(0)
    state.g_InfluenceMatrix_Raw.fill(0)
    state.g_AllianceScore.fill(0)
    state.g_GlobalProvinceScore.fill(0)
    state.g_NeedsRescore.fill(-1)   # 0xffffffff sentinel

    # ── Phase 1 — Per-power heat diffusion + candidate scoring ───────────────
    for p in range(NUM_POWERS):
        curr_sc  = int(np.sum(state.g_SCOwnership[p]))
        target_sc = 18  # standard Diplomacy win threshold

        # 1a — Province urgency scoring → heat_build seed (aiStack_6018 equivalent)
        # research.md §5440–5451: g_StickyModeActive → 5000; SC-need formula otherwise.
        heat_build_seed = np.zeros(NUM_PROVINCES, dtype=np.float64)
        for prov in range(NUM_PROVINCES):
            if state.get_unit_power(prov) != p:
                heat_build_seed[prov] = 0.0
            elif state.g_UniformMode == 1:          # g_StickyModeActive / g_UniformMode
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
            for prov in range(NUM_PROVINCES):
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
            for prov in range(NUM_PROVINCES):
                adjs = state.get_unit_adjacencies(prov)
                if adjs:
                    nxt[prov] = sum(heat_move[q] for q in adjs) / 5.0
            heat_move = nxt

        # 1e — Accumulate g_GlobalProvinceScore
        for prov in range(NUM_PROVINCES):
            state.g_GlobalProvinceScore[prov] += heat_build[prov] + heat_move[prov]

        # 1f — Build ordered set, populate g_CandidateScores (top-N by heat_move)
        # OrderedSet_FindOrInsert_64bit: sorted ascending; copy into g_CandidateScores.
        # Albert+0x3ff8 (unit limit) approximated by the power's actual unit count.
        own_units = sorted(
            (heat_move[prov], prov)
            for prov in range(NUM_PROVINCES)
            if state.get_unit_power(prov) == p
        )
        for count, (score, prov) in enumerate(own_units):
            if count >= len(own_units):
                break
            state.g_CandidateScores[p, prov] = score

        # 1g — Copy heat_move → g_HeatMovement[p]
        state.g_HeatMovement[p] = heat_move

        # 1h — Accumulate g_InfluenceMatrix[col, p]
        # research.md §5516–5522: g_InfluenceMatrix_B[col*21+p] =
        #   Σ(heat_build + heat_move) for provinces where unit.power != col AND col != p.
        # Empty provinces (unit_power == -1) contribute; -1 != col for all valid col.
        for col in range(NUM_POWERS):
            if col == p:
                continue
            total = 0.0
            for prov in range(NUM_PROVINCES):
                if state.get_unit_power(prov) != col:
                    total += heat_build[prov] + heat_move[prov]
            state.g_InfluenceMatrix[col, p] = total

    # ── Phase 3–4 — Snapshot Raw, inject noise ────────────────────────────────
    # Phase 3: copy g_InfluenceMatrix → g_InfluenceMatrix_Raw
    state.g_InfluenceMatrix_Raw = state.g_InfluenceMatrix.copy()

    # Phase 4: per-cell noise via _safe_pow (FUN_0047b370).
    # Formula: B[i][j] += pow(B[i][j] / (sum[j] + 1), 0.3) * 500.0
    # where sum[j] = column sum of Raw for power j (g_PowerInfluenceSum[col]).
    # ST1=base=B[i][j]/(sum[j]+1), ST0=exponent=0.3 (DAT_004af9f8).
    col_sums = np.sum(state.g_InfluenceMatrix_Raw, axis=0).astype(float)  # shape (NUM_POWERS,)
    for i in range(NUM_POWERS):
        for j in range(NUM_POWERS):
            base = state.g_InfluenceMatrix[i, j] / (col_sums[j] + 1.0)
            state.g_InfluenceMatrix[i, j] += (base ** 0.3) * 500.0

    # ── Phase 5 — Row-normalize g_InfluenceMatrix to row-sums of 100 ─────────
    for i in range(NUM_POWERS):
        row_sum = float(np.sum(state.g_InfluenceMatrix[i]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[i] *= 100.0 / row_sum

    # ── Phase 6 — Compute asymmetric g_AllianceScore ─────────────────────────
    # research.md §5568–5584:
    #   col_sum[row] = column sum of Raw over all rows (= total influence directed at row)
    #   A = Raw[row][col], B = Raw[col][row]
    #   A < B → col threatens row more → g_AllianceScore[row][col] = -3*(A/(B+1))*(B/col_sum)
    #   else  → row dominates col      → g_AllianceScore[row][col] = +3*(B/(A+1))*(B/col_sum)
    for row in range(NUM_POWERS):
        col_sum = float(np.sum(state.g_InfluenceMatrix_Raw[:, row]))
        curr_sc_row = int(np.sum(state.g_SCOwnership[row]))
        for col in range(NUM_POWERS):
            if col == row:
                continue
            curr_sc_col = int(np.sum(state.g_SCOwnership[col]))
            if curr_sc_row == 0 or curr_sc_col == 0:
                state.g_AllianceScore[row, col] = 0.0
            else:
                A = float(state.g_InfluenceMatrix_Raw[row, col])
                B = float(state.g_InfluenceMatrix_Raw[col, row])
                denom = col_sum if col_sum != 0.0 else 1.0
                if A < B:
                    state.g_AllianceScore[row, col] = -3.0 * (A / (B + 1.0)) * (B / denom)
                else:
                    state.g_AllianceScore[row, col] =  3.0 * (B / (A + 1.0)) * (B / denom)

    # ── Phase 7 — Compute g_OpeningTarget ────────────────────────────────────
    # research.md §5594–5607: only when g_DeceitLevel==1 AND season==SPR.
    # Lowest-g_GlobalProvinceScore non-own-unit province wins (inverse weighting).
    state.g_OpeningTarget.fill(-1)
    if state.g_DeceitLevel == 1 and state.g_season == 'SPR':
        for p in range(NUM_POWERS):
            best_score = float('-inf')
            for prov in range(NUM_PROVINCES):
                unit_power = state.get_unit_power(prov)
                if unit_power != -1 and unit_power != p:
                    gps = float(state.g_GlobalProvinceScore[prov])
                    if gps > 0.0:
                        sc = random.uniform(0.0, 1.0) * 2.0 / gps
                        if sc > best_score:
                            best_score = sc
                            state.g_OpeningTarget[p] = prov

    # ── ApplyInfluenceScores ────────────────────────────────────────────────
    # C binary: GenerateOrders.c L619 calls ApplyInfluenceScores after the
    # per-power heat/influence loop.  This populates g_UnitAdjacencyCount
    # (Pass 4), g_HeatMovement_B (Pass 1), and — crucially — g_OrderList
    # (Pass 5), which downstream feeds g_GeneralOrders via the press
    # translator pipeline.  Without this call g_OrderList stays empty and
    # the MC trial loop (ProcessTurn Phase 1c) has no orders to dispatch.
    from ..heuristics import apply_influence_scores
    apply_influence_scores(state, own_power)

    # ── Order enumeration pipeline ───────────────────────────────────────────
    # Mirrors the post-loop calls in the binary (EnumerateHoldOrders,
    # EnumerateConvoyReach, ComputeSafeReach, BuildSupportOpportunities).
    for p in range(NUM_POWERS):
        enumerate_hold_orders(state, p)
        enumerate_convoy_reach(state, p)
        # Populates state.g_ConvoyRoute[army_src] for each army of p with a
        # shortest fleet chain (option-1 narrow port of ProcessTurn's convoy
        # route BFS — see moves/convoy.py:populate_convoy_routes).  Without
        # this, the CTO branches in trial.py:553 and :1046 silently fall
        # back to direct moves and no CVY orders are ever emitted.
        populate_convoy_routes(state, p)
    compute_safe_reach(state)
    build_support_opportunities(state)
