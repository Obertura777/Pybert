"""Influence-matrix lifecycle.

Split from heuristics.py during the 2026-04 refactor.

- ``apply_influence_scores``       — ApplyInfluenceScores (feeds AppendOrder chain)
- ``update_relation_history``      — deprecated shim (delegates to communications)
- ``compute_influence_matrix``     — ComputeInfluenceMatrix (FUN_0040d8c0)
- ``normalize_influence_matrix``   — NormalizeInfluenceMatrix

Module-level deps: ``numpy``, ``..state.InnerGameState``,
``._primitives._safe_pow``.  ``update_relation_history`` keeps its
deferred in-body import from ``albert.communications`` unchanged.
"""

import numpy as np

from ..state import InnerGameState

from ._primitives import _safe_pow


def apply_influence_scores(state: InnerGameState, own_power: int):
    """
    Port of ApplyInfluenceScores (sole caller of AppendOrder / FUN_00419d80).

    Builds the press-proposal candidate slate in state.g_OrderList that
    ProposeDMZ later consumes.  Also computes g_HeatScore, g_InfluenceRatio,
    g_UnitAdjacencyCount, g_AttackHistory (move-bonus accumulation), and
    inter-power contact statistics.

    Resolved (see ApplyInfluenceScores.md for formulas):
      Q-AIS-1  g_PerPowerMoveBonus = g_AttackHistory (DAT_005a48e8)
      Q-AIS-2  Gate array = DAT_004DA2F0 (g_HistoryGate), pure 2D, NOT g_MoveHistoryMatrix
      Q-AIS-4  g_MoveScore = round(pow(heat_B,8)*pow(heat_A,9)/1e22); deterministic
      Q-AIS-5  g_SupportScore = round((heat_B*heat_A)^4/1e8); FloatToInt64 = converter
      Q-AIS-8  Contact matrix stride = 0x3f confirmed

    Resolved:
      Q-AIS-NEW-1  Gate is g_UnitAdjacencyCount (DAT_004e1af0), NOT DAT_004DA2F0
                    (which was end of g_HeatScore). Written by Pass 4 above.

    Still open:
      Q-AIS-NEW-2  sort_key FloatToInt64 arg unknown → using g_SupportScore[prov]
    """
    NUM_POWERS = 7
    NUM_PROVINCES = 256

    # ── Pass 1: Zero accumulators + 5-round BFS influence propagation ────────
    #
    # For each power:
    #   • All provinces in adjacency lists initialised to score 0 in ordered set
    #   • Own-power units seeded at base score 5000
    #   • 5 rounds: each province = sum(adjacent scores) / 5
    #   • Own-unit provinces re-pinned to 5000 each round (source stays "on")
    # Result written to g_HeatScore and to g_HeatMovement / g_HeatMovement_B
    # (the two arrays consumed by Pass 5's score formula).
    state.g_HeatScore.fill(0)
    state.g_HeatMovement.fill(0)
    state.g_HeatMovement_B.fill(0)

    for power in range(NUM_POWERS):
        scores = np.zeros(NUM_PROVINCES, dtype=np.int64)

        for prov_id, info in state.unit_info.items():
            if info['power'] == power:
                scores[prov_id] = 5000

        for _ in range(5):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.int64)
            for prov in range(NUM_PROVINCES):
                adj = state.get_unit_adjacencies(prov)
                if adj:
                    nxt[prov] = sum(scores[q] for q in adj) // 5
            for prov_id, info in state.unit_info.items():
                if info['power'] == power:
                    nxt[prov_id] = max(nxt[prov_id], 5000)
            scores = nxt

        # ── Pass 2: Accumulate g_HeatScore ───────────────────────────────────
        for prov in range(NUM_PROVINCES):
            state.g_HeatScore[power, prov] = int(scores[prov])

        # Mirror into the two movement-heat arrays consumed by Pass 5.
        # DAT_004ec2f0 (g_HeatMovement) is power_b's input; DAT_005af0e8
        # (g_HeatMovement_B) is power_a's input. Both are filled identically
        # here and normalised to 100-scale in Pass 6 before Pass 5 reads them.
        state.g_HeatMovement[power] = scores.astype(np.float64)
        state.g_HeatMovement_B[power] = scores.astype(np.float64)

    # ── Pass 3: g_InfluenceRatio normalisation ────────────────────────────────
    #
    # For army-occupied provinces:
    #   owner == own_power → ratio = heat_a / global_max(g_HeatScore)
    #   otherwise          → ratio = heat_a / heat_owner   (may exceed 1.0)
    state.g_InfluenceRatio.fill(0.0)
    global_heat_max = float(np.max(state.g_HeatScore)) or 1.0

    for power_a in range(NUM_POWERS):
        for prov in range(NUM_PROVINCES):
            info = state.unit_info.get(prov)
            if info is None or info['type'] != 'A':
                continue
            owner = info['power']
            heat_a = float(state.g_HeatScore[power_a, prov])
            if owner == own_power:
                state.g_InfluenceRatio[power_a, prov] = heat_a / global_heat_max
            else:
                heat_owner = float(state.g_HeatScore[owner, prov])
                state.g_InfluenceRatio[power_a, prov] = (
                    heat_a / heat_owner if heat_owner > 0.0 else 0.0
                )

    # ── Pass 4: g_UnitAdjacencyCount ─────────────────────────────────────────
    #
    # g_UnitAdjacencyCount[power][province] = count of power's units that can
    # reach province (each unit counts its own province + all adjacencies).
    state.g_UnitAdjacencyCount.fill(0)
    for prov_id, info in state.unit_info.items():
        pw = info['power']
        for adj in state.get_unit_adjacencies(prov_id):
            state.g_UnitAdjacencyCount[pw, adj] += 1
        state.g_UnitAdjacencyCount[pw, prov_id] += 1

    # ── Pass 6 (early): Normalise g_HeatMovement / g_HeatMovement_B to 100 ───
    #
    # Must run before Pass 5 so the score formula has normalised inputs.
    # spec: DAT_004ec2f0[power][province] = value * 100 / max  (__allmul+__alldiv)
    for power in range(NUM_POWERS):
        max_mv = float(np.max(state.g_HeatMovement[power]))
        if max_mv > 0.0:
            state.g_HeatMovement[power] *= 100.0 / max_mv
        max_mv_b = float(np.max(state.g_HeatMovement_B[power]))
        if max_mv_b > 0.0:
            state.g_HeatMovement_B[power] *= 100.0 / max_mv_b

    # ── Pass 5: Per-pair scores + AppendOrder ─────────────────────────────────
    #
    # g_MoveScore[prov] = round(pow(heat_B, 8) * pow(heat_A, 9) / 1e22)
    #   heat_B = g_HeatMovement[power_b][prov]   exponent 8.0  (DAT_004b0a50)
    #   heat_A = g_HeatMovement_B[power_a][prov] exponent 9.0  (DAT_004b0f18)
    #   denom  = pow(100, 6) * pow(100, 5) = 1e12 * 1e10 = 1e22
    #
    # g_SupportScore[prov] = round((heat_B * heat_A)^4 / 1e8)
    #   exponent 4.0 (DAT_004b0f10) applied to both; denom = pow(100,2)^2 = 1e8
    #
    # Gate: zero both scores if g_UnitAdjacencyCount[power_a/b][prov] == 0
    #   (Q-AIS-NEW-1 RESOLVED: DAT_004DA2F0 was a misidentified address — it's
    #    the end of g_HeatScore. The actual gate is g_UnitAdjacencyCount, which
    #    is written by Pass 4 above. See GlobalDataRefs.md for confirmation.)
    #
    # g_AttackHistory[power_a][prov] += FloatToInt64(...) when best_move > 0
    #   (exact FloatToInt64 arg TBD — Q-AIS-NEW-2; using heat_a as placeholder)
    #
    # sort_key = FloatToInt64(ST0) — exact ST0 source TBD (Q-AIS-NEW-2)
    #   placeholder: g_SupportScore[prov]
    DENOM_MOVE    = 1e22   # pow(100,6) * pow(100,5)
    DENOM_SUPPORT = 1e8    # pow(100,2) ** 2
    EXP_MOVE_B    = 8.0    # DAT_004b0a50
    EXP_MOVE_A    = 9.0    # DAT_004b0f18
    EXP_SUPPORT   = 4.0    # DAT_004b0f10

    state.g_OrderList.clear()

    for power_a in range(NUM_POWERS):
        for power_b in range(NUM_POWERS):
            if power_a == power_b:
                continue

            move_scores    = np.zeros(NUM_PROVINCES, dtype=np.int64)
            support_scores = np.zeros(NUM_PROVINCES, dtype=np.int64)

            for prov in range(NUM_PROVINCES):
                # Gate on g_UnitAdjacencyCount (was misidentified as DAT_004DA2F0
                # "g_HistoryGate" — actually the tail of g_HeatScore; real gate is
                # g_UnitAdjacencyCount at DAT_004e1af0, written by Pass 4 above).
                if (state.g_UnitAdjacencyCount[power_a, prov] == 0 or
                        state.g_UnitAdjacencyCount[power_b, prov] == 0):
                    continue

                heat_b = float(state.g_HeatMovement[power_b, prov])
                heat_a = float(state.g_HeatMovement_B[power_a, prov])

                mv = _safe_pow(heat_b, EXP_MOVE_B) * _safe_pow(heat_a, EXP_MOVE_A)
                move_scores[prov] = int(mv / DENOM_MOVE) if DENOM_MOVE > 0 else 0

                sp = _safe_pow(heat_b, EXP_SUPPORT) * _safe_pow(heat_a, EXP_SUPPORT)
                support_scores[prov] = int(sp / DENOM_SUPPORT) if DENOM_SUPPORT > 0 else 0

            best_move    = int(np.max(move_scores))
            best_support = int(np.max(support_scores))

            # g_AttackHistory accumulation (= g_PerPowerMoveBonus, DAT_005a48e8)
            # FloatToInt64 arg TBD (Q-AIS-NEW-2); placeholder: heat_a value
            if best_move > 0:
                for prov in range(NUM_PROVINCES):
                    heat_a = float(state.g_HeatMovement_B[power_a, prov])
                    state.g_AttackHistory[power_a, prov] += int(heat_a)

            # Build g_OrderList press-proposal slate (own power only)
            if best_support > 0 and power_a == own_power:
                for prov in range(NUM_PROVINCES):
                    # sort_key = FloatToInt64(ST0); placeholder = support score
                    sort_key = int(support_scores[prov])
                    if sort_key == 0:
                        continue
                    if prov not in state.unit_info:
                        continue

                    flag1 = True
                    flag2 = True
                    flag3 = False

                    owner = int(state.g_ScOwner[prov])
                    if owner == own_power:
                        flag2 = False   # Albert owns province → unilateral
                    # owner == power_b: flag3 stays False (contested, bilateral)

                    unit = state.unit_info[prov]
                    if unit['type'] == 'A':
                        unit_power = unit['power']
                        if unit_power == own_power:
                            flag2 = False            # Albert's unit → unilateral
                        elif unit_power == power_b:
                            flag2 = True             # ally's unit → bilateral

                    # AppendOrder = std::map<int,OrderEntry>::insert keyed by sort_key
                    state.g_OrderList.append({
                        'flag1': flag1,
                        'flag2': flag2,
                        'flag3': flag3,
                        'province': prov,
                        'ally_power': power_b,
                        'score': sort_key,
                        'done': False,
                    })

    # g_OrderList mirrors std::map sort (ascending key = lowest score first in map;
    # ProposeDMZ iterates in order — descending score = highest priority first)
    state.g_OrderList.sort(key=lambda e: e['score'], reverse=True)

    # ── Pass 6 (cont.): g_GlobalProvinceScore + inter-power contact matrices ──
    state.g_GlobalProvinceScore.fill(0.0)
    for prov in range(NUM_PROVINCES):
        for power in range(NUM_POWERS):
            state.g_GlobalProvinceScore[prov] += state.g_HeatMovement[power, prov]
    global_prov_max = float(np.max(state.g_GlobalProvinceScore)) or 1.0
    state.g_GlobalProvinceScore *= 100.0 / global_prov_max

    # Contact matrices: stride 0x3f confirmed (Q-AIS-8 resolved)
    # Python (7,7) ndarray is equivalent to C [pow*0x3f+other] for 7 powers.
    state.g_ContactCount.fill(0)
    state.g_ContactWeighted.fill(0)
    state.g_ContactOwnerCount.fill(0)
    for prov_id, info in state.unit_info.items():
        pw = info['power']
        for adj in state.get_unit_adjacencies(prov_id):
            owner_r = int(state.g_ScOwner[adj])
            if owner_r < 0 or owner_r >= NUM_POWERS or owner_r == pw:
                continue
            if state.g_InfluenceRatio[pw, adj] > 1.0:
                state.g_ContactCount[pw, owner_r] += 1
                state.g_ContactWeighted[pw, owner_r] += int(
                    state.g_UnitAdjacencyCount[pw, adj]
                )
                state.g_ContactOwnerCount[pw, owner_r] += int(
                    state.g_UnitAdjacencyCount[owner_r, adj]
                )


def update_relation_history(state) -> None:
    """
    Deprecated shim — delegates to ``communications._update_relation_history``.

    Removed 2026-04-14: the prior sqrt-based implementation had a dead-code bug
    (``if current < floor`` where ``floor = sqrt(current)`` is always ≤ current
    for current ≥ 1, so the floor was never applied). The canonical port lives
    in ``communications._update_relation_history`` and is called from
    ``friendly()`` Phase 2; HOSTILITY Block 6 also calls it (wired 2026-04-14).
    """
    from albert.communications import _update_relation_history
    _update_relation_history(state)


def compute_influence_matrix(state: InnerGameState, own_power: int = 0) -> None:
    """
    Port of ComputeInfluenceMatrix (FUN_0040d8c0).

    All 6 phases from the decompile (decompiled.txt):
      Phase 1 — trust-adjust g_InfluenceMatrix_Raw → g_InfluenceMatrix
      Phase 2 — per-power row-sum via PackScoreU64 (banker's-round int64)
      Phase 3 — add _safe_pow noise: cell += pow(cell/(col_sum+1), 0.3) * 500
      Phase 4 — row-normalise each row to sum = 100
      Phase 5 — initialise g_AllyPrefRanking / g_InfluenceRankFlag
      Phase 6 — selection-sort to build ranked alliance preference list
    """
    num_powers = 7

    # Phase 1 — trust-adjust raw matrix
    # own_power row/col: copy raw directly (no scaling)
    # other pairs: trust_hi<0 OR (trust_hi<1 AND trust_lo<6) → divide by (trust_lo+1)
    #              otherwise (confirmed ally) → divide by 6.0
    for row in range(num_powers):
        for col in range(num_powers):
            raw = float(state.g_InfluenceMatrix_Raw[row, col])
            if row == own_power or col == own_power:
                state.g_InfluenceMatrix[row, col] = raw
            else:
                trust_hi = int(state.g_AllyTrustScore_Hi[row, col])
                trust_lo = int(state.g_AllyTrustScore[row, col])
                if trust_hi < 0 or (trust_hi < 1 and trust_lo < 6):
                    divisor = trust_lo + 1
                    state.g_InfluenceMatrix[row, col] = raw / divisor if divisor != 0 else raw
                else:
                    state.g_InfluenceMatrix[row, col] = raw / 6.0

    # Phase 2 — per-power row sum (PackScoreU64 = trunc toward zero, not banker's round;
    # FRNDINT is intermediate, correction code always restores truncation)
    power_sum = np.array(
        [int(float(np.sum(state.g_InfluenceMatrix[p]))) for p in range(num_powers)],
        dtype=np.int64,
    )

    # Phase 3 — noise injection: cell += _safe_pow(cell / (col_sum+1), 0.3) * 500
    for row in range(num_powers):
        for col in range(num_powers):
            col_sum = float(power_sum[col])
            base = float(state.g_InfluenceMatrix[row, col]) / (col_sum + 1.0)
            state.g_InfluenceMatrix[row, col] += _safe_pow(base, 0.3) * 500.0

    # Phase 4 — row-normalise to 100
    for row in range(num_powers):
        row_sum = float(np.sum(state.g_InfluenceMatrix[row]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[row] = (state.g_InfluenceMatrix[row] * 100.0) / row_sum

    # Phase 5 — init ranking arrays
    # All g_AllyPrefRanking slots initialised to own_power sentinel (per decompile)
    state.g_AllyPrefRanking.fill(own_power)
    state.g_InfluenceRankFlag.fill(-1)
    np.fill_diagonal(state.g_InfluenceRankFlag, -2)  # self = skip

    # Phase 6 — selection-sort to build ranked list (1-indexed ranks 1..numPowers-1)
    for p in range(num_powers):
        for rank in range(1, num_powers):
            best_col = -1
            best_val = -1.0
            for col in range(num_powers):
                if state.g_InfluenceRankFlag[p, col] == -1:  # unranked
                    val = float(state.g_InfluenceMatrix[p, col])
                    if val > best_val:
                        best_val = val
                        best_col = col
            if best_col == -1:
                break
            state.g_InfluenceRankFlag[p, best_col] = rank
            if rank < 5:
                state.g_AllyPrefRanking[p, rank] = best_col


def normalize_influence_matrix(state: InnerGameState) -> None:
    """
    Port of the row-normalisation step (Phase 4 of ComputeInfluenceMatrix).

    Normalises each row of g_InfluenceMatrix so it sums to 100.0.
    Research.md §4292 Phase 4.
    """
    num_powers = 7
    for row in range(num_powers):
        row_sum = float(np.sum(state.g_InfluenceMatrix[row]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[row] = (state.g_InfluenceMatrix[row] * 100.0) / row_sum
