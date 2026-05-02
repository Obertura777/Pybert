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

from ._primitives import _safe_pow, _float_to_int64


def apply_influence_scores(state: InnerGameState, own_power: int):
    """
    Port of ApplyInfluenceScores (sole caller of AppendOrder / FUN_00419d80).

    Builds the press-proposal candidate slate in state.g_order_list that
    ProposeDMZ later consumes.  Also computes g_heat_score, g_influence_ratio,
    g_unit_adjacency_count, g_attack_history (move-bonus accumulation), and
    inter-power contact statistics.

    Resolved (see ApplyInfluenceScores.md for formulas):
      Q-AIS-1  g_PerPowerMoveBonus = g_attack_history (DAT_005a48e8)
      Q-AIS-2  Gate array address = DAT_004DA2F0 — later superseded by Q-AIS-NEW-1
               (DAT_004DA2F0 is the tail of g_heat_score, not a separate gate array)
      Q-AIS-4  g_MoveScore = round(pow(heat_B,8)*pow(heat_A,9)/1e22); deterministic
      Q-AIS-5  g_SupportScore = round((heat_B*heat_A)^4/1e8); FloatToInt64 = converter
      Q-AIS-8  Contact matrix stride = 0x3f confirmed

    Resolved:
      Q-AIS-NEW-1  Gate is g_unit_adjacency_count (DAT_004e1af0), NOT DAT_004DA2F0
                    (which was end of g_heat_score). Written by Pass 4 above.
      Q-AIS-NEW-2a g_attack_history += FloatToInt64(heat_a) per province when
                    best_move > 0; ST0 = heat_a = g_heat_movement_b[power_a][prov].

    Resolved:
      Q-AIS-NEW-2b sort_key = FloatToInt64(g_SupportScore[prov]
                    * g_InfluenceMatrix_B[power_a*21+power_b] / best_support).
                    Assembly (LAB_0043726c): FILD g_SupportScore[ESI*8], FMUL
                    g_InfluenceMatrix_B[local_84], FDIV local_68, CALL FloatToInt64.
                    local_68 set pre-loop via FILD best_support + FSTP (int→double).
                    g_influence_matrix_b populated in generate_orders Phase 3 as a
                    copy of g_influence_matrix_raw (same gate/heat as Phase 1h,
                    GenerateOrders.c:352-383).
    """
    NUM_POWERS = 7
    NUM_PROVINCES = 256

    # ── Pass 1: Zero accumulators + 10-round BFS influence propagation ────────
    #
    # For each power:
    #   • All provinces in adjacency lists initialised to score 0 in ordered set
    #   • Own-power units seeded at base score 5000
    #   • 10 rounds: each province = sum(adjacent scores) / 5
    #   • Own-unit provinces re-pinned to 5000 each round (source stays "on")
    # Result written to g_heat_score and to g_heat_movement / g_heat_movement_b
    # (the two arrays consumed by Pass 5's score formula).
    # Updated 2026-04-21: 10 rounds to match C (ScoreProvinces.c:492-638).
    state.g_heat_score.fill(0)
    state.g_heat_movement.fill(0)
    state.g_heat_movement_b.fill(0)

    for power in range(NUM_POWERS):
        scores = np.zeros(NUM_PROVINCES, dtype=np.int64)

        for prov_id, info in state.unit_info.items():
            if info['power'] == power:
                scores[prov_id] = 5000

        for _ in range(10):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.int64)
            for prov in range(NUM_PROVINCES):
                adj = state.get_unit_adjacencies(prov)
                if adj:
                    nxt[prov] = sum(scores[q] for q in adj) // 5
            for prov_id, info in state.unit_info.items():
                if info['power'] == power:
                    nxt[prov_id] = 5000
            scores = nxt

        # ── Pass 2: Accumulate g_heat_score ───────────────────────────────────
        for prov in range(NUM_PROVINCES):
            state.g_heat_score[power, prov] = int(scores[prov])

        # Mirror into the two movement-heat arrays consumed by Pass 5.
        # DAT_004ec2f0 (g_heat_movement) is power_b's input; DAT_005af0e8
        # (g_heat_movement_b) is power_a's input. Both are filled identically
        # here and normalised to 100-scale in Pass 6 before Pass 5 reads them.
        state.g_heat_movement[power] = scores.astype(np.float64)
        state.g_heat_movement_b[power] = scores.astype(np.float64)

    # ── Pass 3: g_influence_ratio normalisation ────────────────────────────────
    #
    # For army-occupied provinces:
    #   owner == own_power → ratio = heat_a / global_max(g_heat_score)
    #   otherwise          → ratio = heat_a / heat_owner   (may exceed 1.0)
    state.g_influence_ratio.fill(0.0)
    global_heat_max = float(np.max(state.g_heat_score)) or 1.0

    for power_a in range(NUM_POWERS):
        for prov in range(NUM_PROVINCES):
            info = state.unit_info.get(prov)
            if info is None or info['type'] != 'A':
                continue
            owner = info['power']
            heat_a = float(state.g_heat_score[power_a, prov])
            if owner == own_power:
                state.g_influence_ratio[power_a, prov] = heat_a / global_heat_max
            else:
                heat_owner = float(state.g_heat_score[owner, prov])
                state.g_influence_ratio[power_a, prov] = (
                    heat_a / heat_owner if heat_owner > 0.0 else 0.0
                )

    # ── Pass 4: g_unit_adjacency_count ─────────────────────────────────────────
    #
    # g_unit_adjacency_count[power][province] = count of power's units that can
    # reach province (each unit counts its own province + all adjacencies).
    state.g_unit_adjacency_count.fill(0)
    for prov_id, info in state.unit_info.items():
        pw = info['power']
        for adj in state.get_unit_adjacencies(prov_id):
            state.g_unit_adjacency_count[pw, adj] += 1
        state.g_unit_adjacency_count[pw, prov_id] += 1

    # ── Pass 6 (early): Normalise g_heat_movement / g_heat_movement_b to 100 ───
    #
    # Must run before Pass 5 so the score formula has normalised inputs.
    # spec: DAT_004ec2f0[power][province] = value * 100 / max  (__allmul+__alldiv)
    for power in range(NUM_POWERS):
        max_mv = float(np.max(state.g_heat_movement[power]))
        if max_mv > 0.0:
            state.g_heat_movement[power] *= 100.0 / max_mv
        max_mv_b = float(np.max(state.g_heat_movement_b[power]))
        if max_mv_b > 0.0:
            state.g_heat_movement_b[power] *= 100.0 / max_mv_b

    # ── Pass 5: Per-pair scores + AppendOrder ─────────────────────────────────
    #
    # g_MoveScore[prov] = round(pow(heat_B, 8) * pow(heat_A, 9) / 1e22)
    #   heat_B = g_heat_movement[power_b][prov]   exponent 8.0  (DAT_004b0a50)
    #   heat_A = g_heat_movement_b[power_a][prov] exponent 9.0  (DAT_004b0f18)
    #   denom  = pow(100, 6) * pow(100, 5) = 1e12 * 1e10 = 1e22
    #
    # g_SupportScore[prov] = round((heat_B * heat_A)^4 / 1e8)
    #   exponent 4.0 (DAT_004b0f10) applied to both; denom = pow(100,2)^2 = 1e8
    #
    # Gate: zero both scores if g_unit_adjacency_count[power_a/b][prov] == 0
    #   (Q-AIS-NEW-1 RESOLVED: DAT_004DA2F0 was a misidentified address — it's
    #    the end of g_heat_score. The actual gate is g_unit_adjacency_count, which
    #    is written by Pass 4 above. See GlobalDataRefs.md for confirmation.)
    #
    # g_attack_history[power_a][prov] += FloatToInt64(heat_a) when best_move > 0
    #   (Q-AIS-NEW-2a resolved: ST0 = heat_a = g_heat_movement_b[power_a][prov])
    #
    # sort_key = FloatToInt64(g_SupportScore[prov] * g_InfluenceMatrix_B[pa*21+pb]
    #              / best_support)  — Q-AIS-NEW-2b resolved from assembly.
    # g_influence_matrix_b[power_a, power_b] = g_influence_matrix_raw snapshot
    # (GenerateOrders.c:352-383, same gate as Phase 1h).
    DENOM_MOVE    = 1e22   # pow(100,6) * pow(100,5)
    DENOM_SUPPORT = 1e8    # pow(100,2) ** 2
    EXP_MOVE_B    = 8.0    # DAT_004b0a50
    EXP_MOVE_A    = 9.0    # DAT_004b0f18
    EXP_SUPPORT   = 4.0    # DAT_004b0f10

    state.g_order_list.clear()

    for power_a in range(NUM_POWERS):
        for power_b in range(NUM_POWERS):
            if power_a == power_b:
                continue

            move_scores    = np.zeros(NUM_PROVINCES, dtype=np.int64)
            support_scores = np.zeros(NUM_PROVINCES, dtype=np.int64)

            for prov in range(NUM_PROVINCES):
                # Gate on g_unit_adjacency_count (was misidentified as DAT_004DA2F0
                # "g_history_gate" — actually the tail of g_heat_score; real gate is
                # g_unit_adjacency_count at DAT_004e1af0, written by Pass 4 above).
                if (state.g_unit_adjacency_count[power_a, prov] == 0 or
                        state.g_unit_adjacency_count[power_b, prov] == 0):
                    continue

                heat_b = float(state.g_heat_movement[power_b, prov])
                heat_a = float(state.g_heat_movement_b[power_a, prov])

                mv = _safe_pow(heat_b, EXP_MOVE_B) * _safe_pow(heat_a, EXP_MOVE_A)
                move_scores[prov] = int(mv / DENOM_MOVE) if DENOM_MOVE > 0 else 0

                sp = _safe_pow(heat_b, EXP_SUPPORT) * _safe_pow(heat_a, EXP_SUPPORT)
                support_scores[prov] = int(sp / DENOM_SUPPORT) if DENOM_SUPPORT > 0 else 0

            best_move    = int(np.max(move_scores))
            best_support = int(np.max(support_scores))

            # g_attack_history accumulation (= g_PerPowerMoveBonus, DAT_005a48e8)
            # C: g_attack_history[power_a, prov] += FloatToInt64(heat_a)
            # Q-AIS-NEW-2 resolved: the FPU ST0 source is heat_a (the
            # heat_movement_b value for power_a at this province).
            if best_move > 0:
                for prov in range(NUM_PROVINCES):
                    heat_a = float(state.g_heat_movement_b[power_a, prov])
                    state.g_attack_history[power_a, prov] += _float_to_int64(heat_a)

            # Build g_order_list press-proposal slate (own power only)
            if best_support > 0 and power_a == own_power:
                inf_b = float(state.g_influence_matrix_b[power_a, power_b])
                for prov in range(NUM_PROVINCES):
                    sort_key = _float_to_int64(
                        float(support_scores[prov]) * inf_b / float(best_support)
                    )
                    if sort_key == 0:
                        continue
                    if prov not in state.unit_info:
                        continue

                    flag1 = True
                    flag2 = True
                    flag3 = False

                    owner = int(state.g_sc_owner[prov])
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
                    state.g_order_list.append({
                        'flag1': flag1,
                        'flag2': flag2,
                        'flag3': flag3,
                        'province': prov,
                        'ally_power': power_b,
                        'score': sort_key,
                        'done': False,
                    })

    # g_order_list mirrors std::map sort (ascending key = lowest score first in map;
    # ProposeDMZ iterates in order — descending score = highest priority first)
    state.g_order_list.sort(key=lambda e: e['score'], reverse=True)

    # ── Pass 6 (cont.): g_global_province_score + inter-power contact matrices ──
    state.g_global_province_score.fill(0.0)
    for prov in range(NUM_PROVINCES):
        for power in range(NUM_POWERS):
            state.g_global_province_score[prov] += state.g_heat_movement[power, prov]
    global_prov_max = float(np.max(state.g_global_province_score)) or 1.0
    state.g_global_province_score *= 100.0 / global_prov_max

    # Contact matrices: C layout is a single flat BSS region, stride 63
    # (= 3×21 slots/row): g_contact_count at base−21 int32s, g_contact_weighted
    # at base, g_contact_owner_count at base+21 int32s.  Each 21-slot block
    # holds 7 values (other_power 0..6) + 14 padding.  Python (7,7) arrays
    # capture this correctly; reads must use the three separate arrays.
    state.g_contact_count.fill(0)
    state.g_contact_weighted.fill(0)
    state.g_contact_owner_count.fill(0)
    for prov_id, info in state.unit_info.items():
        pw = info['power']
        for adj in state.get_unit_adjacencies(prov_id):
            owner_r = int(state.g_sc_owner[adj])
            if owner_r < 0 or owner_r >= NUM_POWERS or owner_r == pw:
                continue
            if state.g_influence_ratio[pw, adj] > 1.0:
                state.g_contact_count[pw, owner_r] += 1
                state.g_contact_weighted[pw, owner_r] += int(
                    state.g_unit_adjacency_count[pw, adj]
                )
                state.g_contact_owner_count[pw, owner_r] += int(
                    state.g_unit_adjacency_count[owner_r, adj]
                )


def compute_alliance_score(state: InnerGameState) -> None:
    """
    Port of g_AllianceScore computation (GenerateOrders.c lines 567-618).

    Called after compute_influence_matrix (which populates g_influence_matrix_raw).
    For each ordered power pair (row, col) where row != col:

      col_sum = Σ_k g_influence_matrix_raw[k][row]   (column sum of column `row`)
      raw_rc  = g_influence_matrix_raw[row][col]
      raw_cr  = g_influence_matrix_raw[col][row]

      sc_count[row|col] == 0  →  0.0
      raw_rc > raw_cr         →  (raw_rc/(raw_cr+1)) * raw_cr / col_sum * -3.0
      else                    →  (raw_cr/(raw_rc+1)) * raw_cr / col_sum * +3.0
    """
    NUM_POWERS = 7
    state.g_alliance_score.fill(0.0)

    col_sums = np.sum(state.g_influence_matrix_raw, axis=0)  # shape (7,)
    for row in range(NUM_POWERS):
        col_sum = float(col_sums[row])
        for col in range(NUM_POWERS):
            if row == col:
                continue
            if state.sc_count[row] == 0 or state.sc_count[col] == 0:
                continue
            raw_rc = float(state.g_influence_matrix_raw[row, col])
            raw_cr = float(state.g_influence_matrix_raw[col, row])
            if col_sum == 0.0:
                continue
            if raw_rc > raw_cr:
                state.g_alliance_score[row, col] = (
                    (raw_rc / (raw_cr + 1.0)) * raw_cr / col_sum * -3.0
                )
            else:
                state.g_alliance_score[row, col] = (
                    (raw_cr / (raw_rc + 1.0)) * raw_cr / col_sum * 3.0
                )


def set_opening_targets(state: InnerGameState) -> None:
    """
    Port of g_OpeningTarget computation (GenerateOrders.c lines 620-652).

    Active only when g_deceit_level == 1 and g_season == 'SPR'.
    For each power, finds the province that maximises
        2.0 * _safe_pow(g_heat_movement_b[power, prov], 2.5) / g_global_province_score[prov]
    among provinces occupied by a non-army unit.

    Verified from listing at 00447359-0044737c:
      FILD [EDX*8 + DAT_005af0e8]  → base = g_heat_movement_b[power*256+prov] (int64)
      FLD  [DAT_004b1330]          → exponent = 0x4004000000000000 = 2.5
      FADD ST0,ST0                 → factor = 2.0
      FILD [ESI*8 + g_GlobalProvinceScore] → denominator
    """
    NUM_POWERS = 7
    NUM_PROVINCES = 256

    state.g_opening_target.fill(-1)

    if state.g_deceit_level != 1 or state.g_season != 'SPR':
        return

    for power in range(NUM_POWERS):
        best_int = 0
        best_prov = -1

        for prov in range(NUM_PROVINCES):
            if prov not in state.unit_info:
                continue
            if state.unit_info[prov]['type'] == 'A':
                # C filter: unit_type != 'A' OR secondary_byte == 0x14
                # 0x14 (army-coast secondary) not tracked in Python — skip armies
                continue
            g_prov = float(state.g_global_province_score[prov])
            if g_prov == 0.0:
                continue
            ratio = float(state.g_heat_movement_b[power, prov])
            score = 2.0 * _safe_pow(ratio, 2.5) / g_prov
            score_int = _float_to_int64(score)
            if score_int > best_int:
                best_int = score_int
                best_prov = prov

        state.g_opening_target[power] = best_prov


def update_relation_history(state) -> None:
    """
    Deprecated shim — delegates to ``communications._update_relation_history``.

    Removed 2026-04-14: the prior sqrt-based implementation had a dead-code bug
    (``if current < floor`` where ``floor = sqrt(current)`` is always ≤ current
    for current ≥ 1, so the floor was never applied). The canonical port lives
    in ``communications._update_relation_history`` and is called from
    ``friendly()`` Phase 2; HOSTILITY Block 6 also calls it (wired 2026-04-14).
    """
    from ..communications import _update_relation_history
    _update_relation_history(state)


def compute_influence_matrix(state: InnerGameState, own_power: int = 0) -> None:
    """
    Port of ComputeInfluenceMatrix (FUN_0040d8c0).

    All 6 phases from the decompile (decompiled.txt):
      Phase 1 — trust-adjust g_influence_matrix_raw → g_influence_matrix
      Phase 2 — per-power row-sum via PackScoreU64 (banker's-round int64)
      Phase 3 — add _safe_pow noise: cell += pow(cell/(col_sum+1), 0.3) * 500
      Phase 4 — row-normalise each row to sum = 100
      Phase 5 — initialise g_ally_pref_ranking / g_influence_rank_flag
      Phase 6 — selection-sort to build ranked alliance preference list
    """
    num_powers = 7

    # Phase 1 — trust-adjust raw matrix
    # own_power row/col: copy raw directly (no scaling)
    # other pairs: trust_hi<0 OR (trust_hi<1 AND trust_lo<6) → divide by (trust_lo+1)
    #              otherwise (confirmed ally) → divide by 6.0
    for row in range(num_powers):
        for col in range(num_powers):
            raw = float(state.g_influence_matrix_raw[row, col])
            if row == own_power or col == own_power:
                state.g_influence_matrix[row, col] = raw
            else:
                trust_hi = int(state.g_ally_trust_score_hi[row, col])
                trust_lo = int(state.g_ally_trust_score[row, col])
                if trust_hi < 0 or (trust_hi < 1 and trust_lo < 6):
                    divisor = trust_lo + 1
                    state.g_influence_matrix[row, col] = raw / divisor if divisor != 0 else raw
                else:
                    state.g_influence_matrix[row, col] = raw / 6.0

    # Phase 2 — per-power row sum via PackScoreU64 (FRNDINT + truncation correction)
    power_sum = np.array(
        [_float_to_int64(float(np.sum(state.g_influence_matrix[p]))) for p in range(num_powers)],
        dtype=np.int64,
    )

    # Phase 3 — noise injection: cell += _safe_pow(cell / (row_sum+1), 0.3) * 500
    # Divisor is DAT_004f6af0[iVar12] where iVar12 is the outer (row) loop — not col.
    for row in range(num_powers):
        row_sum = float(power_sum[row])
        for col in range(num_powers):
            base = float(state.g_influence_matrix[row, col]) / (row_sum + 1.0)
            state.g_influence_matrix[row, col] += _safe_pow(base, 0.3) * 500.0

    # Phase 4 — row-normalise to 100
    for row in range(num_powers):
        row_sum = float(np.sum(state.g_influence_matrix[row]))
        if row_sum != 0.0:
            state.g_influence_matrix[row] = (state.g_influence_matrix[row] * 100.0) / row_sum

    # Phase 5 — init ranking arrays
    # All g_ally_pref_ranking slots initialised to own_power sentinel (per decompile)
    state.g_ally_pref_ranking.fill(own_power)
    state.g_influence_rank_flag.fill(-1)
    np.fill_diagonal(state.g_influence_rank_flag, -2)  # self = skip

    # Phase 6 — selection-sort to build ranked list (1-indexed ranks 1..numPowers-1)
    for p in range(num_powers):
        for rank in range(1, num_powers):
            best_col = -1
            best_val = -1.0
            for col in range(num_powers):
                if state.g_influence_rank_flag[p, col] == -1:  # unranked
                    val = float(state.g_influence_matrix[p, col])
                    if val > best_val:
                        best_val = val
                        best_col = col
            if best_col == -1:
                break
            state.g_influence_rank_flag[p, best_col] = rank
            if rank < 5:
                state.g_ally_pref_ranking[p, rank] = best_col


def normalize_influence_matrix(state: InnerGameState) -> None:
    """
    Port of the row-normalisation step (Phase 4 of ComputeInfluenceMatrix).

    Normalises each row of g_influence_matrix so it sums to 100.0.
    Research.md §4292 Phase 4.
    """
    num_powers = 7
    for row in range(num_powers):
        row_sum = float(np.sum(state.g_influence_matrix[row]))
        if row_sum != 0.0:
            state.g_influence_matrix[row] = (state.g_influence_matrix[row] * 100.0) / row_sum
