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


def _runtime_province_count(state: InnerGameState) -> int:
    """Return the active board-array bound used by the C runtime loops."""
    count = int(getattr(state, 'num_valid_provinces', 0))
    if count > 0:
        return count
    valid = getattr(state, 'valid_provinces', ())
    if valid:
        return max(int(province) for province in valid) + 1
    return int(state.g_heat_movement.shape[1])


def _populate_contact_matrices(state: InnerGameState) -> None:
    """Port ApplyInfluenceScores.c:746-782's SC-controller pass."""
    num_powers = int(getattr(state, 'g_num_powers', 7))
    state.g_contact_count.fill(0)
    state.g_contact_weighted.fill(0)
    state.g_contact_owner_count.fill(0)

    for power in range(num_powers):
        for province in getattr(state, 'sc_provinces', ()):
            province = int(province)
            owner = int(state.g_sc_owner[province])
            if not 0 <= owner < num_powers or owner == power:
                continue
            if float(state.g_influence_ratio[power, province]) <= 1.0:
                continue
            state.g_contact_count[power, owner] += 1
            state.g_contact_weighted[power, owner] += int(
                state.g_unit_adjacency_count[power, province]
            )
            state.g_contact_owner_count[power, owner] += int(
                state.g_unit_adjacency_count[owner, province]
            )


def _populate_influence_ratio(state: InnerGameState) -> None:
    """Port ApplyInfluenceScores.c:330-379's controlled-SC heat ratios."""
    num_powers = int(getattr(state, 'g_num_powers', 7))
    state.g_influence_ratio.fill(0.0)

    for outer_power in range(num_powers):
        for province in getattr(state, 'sc_provinces', ()):
            province = int(province)
            owner = int(state.g_sc_owner[province])
            if not 0 <= owner < num_powers:
                continue
            denominator = float(state.g_heat_score[owner, province]) + 1.0
            if owner == outer_power:
                numerator = max(
                    (float(state.g_heat_score[power, province])
                     for power in range(num_powers)
                     if power != outer_power),
                    default=0.0,
                )
            else:
                numerator = float(state.g_heat_score[outer_power, province])
            state.g_influence_ratio[outer_power, province] = (
                numerator / denominator
            )


def _apply_heat_nodes(state: InnerGameState) -> dict[int, list[tuple[int, str, str]]]:
    """Build ApplyInfluenceScores' province/unit-token key domain."""
    valid = sorted(getattr(state, 'valid_provinces', ()) or state.adj_matrix)
    nodes_by_province: dict[int, list[tuple[int, str, str]]] = {}
    coast_map: dict[int, list[str]] = {}
    for (province, coast), _adj in getattr(state, 'fleet_coast_adj', {}).items():
        coast_map.setdefault(int(province), []).append(str(coast).upper())

    for province in valid:
        nodes: list[tuple[int, str, str]] = []
        if province not in getattr(state, 'water_provinces', set()):
            nodes.append((province, 'A', ''))
        if province not in getattr(state, 'land_provinces', set()):
            coasts = sorted(set(coast_map.get(province, ())))
            if coasts:
                nodes.extend((province, 'F', coast) for coast in coasts)
            else:
                nodes.append((province, 'F', ''))
        if nodes:
            nodes_by_province[province] = nodes
    return nodes_by_province


def _compute_apply_heat_score(state: InnerGameState) -> None:
    """Port ApplyInfluenceScores.c:68-305's six token-key score sets.

    Set zero is seeded from live units; sets one through five use
    ``(self + sum(max score per adjacent province)) / 5``. Fleet coast keys
    remain separate, while duplicate coast variants of one destination use the
    source's maximum-before-add rule.
    """
    num_powers = int(getattr(state, 'g_num_powers', 7))
    nodes_by_province = _apply_heat_nodes(state)
    all_nodes = [node for nodes in nodes_by_province.values() for node in nodes]
    state.g_heat_score.fill(0)

    reverse_fleet_coasts: dict[tuple[int, int], list[str]] = {}
    for (destination, coast), adjacencies in getattr(
        state, 'fleet_coast_adj', {}
    ).items():
        for source in adjacencies:
            reverse_fleet_coasts.setdefault(
                (int(source), int(destination)), []
            ).append(str(coast).upper())

    for power in range(num_powers):
        scores = {node: 0 for node in all_nodes}
        for province, unit in state.unit_info.items():
            if int(unit.get('power', -1)) != power:
                continue
            unit_type = str(unit.get('type', 'A')).upper()
            if unit_type in ('A', 'AMY', 'ARMY'):
                key = (int(province), 'A', '')
            else:
                coast = str(unit.get('coast', '')).upper()
                if coast and not coast.startswith('/'):
                    coast = '/' + coast
                key = (int(province), 'F', coast)
                if key not in scores:
                    fleet_nodes = [
                        node for node in nodes_by_province.get(int(province), ())
                        if node[1] == 'F'
                    ]
                    if len(fleet_nodes) == 1:
                        key = fleet_nodes[0]
            if key in scores:
                scores[key] = 5000

        aggregate_scores = scores
        for _round in range(5):
            next_scores: dict[tuple[int, str, str], int] = {}
            for node in all_nodes:
                province, unit_type, coast = node
                if unit_type == 'A':
                    adjacent_provinces = [
                        adj for adj in state.get_unit_adjacencies(province)
                        if adj not in getattr(state, 'water_provinces', set())
                    ]
                elif coast:
                    adjacent_provinces = list(
                        state.fleet_coast_adj.get((province, coast), ())
                    )
                else:
                    adjacent_provinces = list(
                        state.fleet_adj_matrix.get(province, ())
                    )

                total = int(scores[node])
                for adjacent in adjacent_provinces:
                    candidates = []
                    if unit_type == 'A':
                        candidates.append((int(adjacent), 'A', ''))
                    else:
                        destination_coasts = reverse_fleet_coasts.get(
                            (province, int(adjacent)), ()
                        )
                        if destination_coasts:
                            candidates.extend(
                                (int(adjacent), 'F', dst_coast)
                                for dst_coast in destination_coasts
                            )
                        else:
                            candidates.append((int(adjacent), 'F', ''))
                    total += max(
                        (int(scores[candidate]) for candidate in candidates
                         if candidate in scores),
                        default=0,
                    )
                next_scores[node] = total // 5
            scores = next_scores
            if _round == 1:
                # Binary 0x436996 looks up +0x3634 (set two) while walking
                # +0x361c (set-zero) keys for the g_HeatScore accumulation.
                aggregate_scores = scores

        for province, nodes in nodes_by_province.items():
            state.g_heat_score[power, province] = sum(
                int(aggregate_scores[node]) for node in nodes
            )


def _normalize_movement_heat(state: InnerGameState) -> None:
    """Normalize GenerateOrders' two heat copies as C:448-505."""
    num_powers = int(getattr(state, 'g_num_powers', 7))
    num_provinces = _runtime_province_count(state)
    for power in range(num_powers):
        primary = state.g_heat_movement[power, :num_provinces]
        primary_max = float(np.max(primary))
        state.g_heat_movement[power, :num_provinces] = np.floor(
            primary * 100.0 / (primary_max + 1.0)
        )
        secondary = state.g_heat_movement_b[power, :num_provinces]
        secondary_max = float(np.max(secondary))
        if secondary_max > 0.0:
            state.g_heat_movement_b[power, :num_provinces] = np.floor(
                secondary * 100.0 / secondary_max
            )


def _populate_unit_adjacency_count(state: InnerGameState) -> None:
    """Port C:389-447's active-unit, type-filtered reach counter."""
    state.g_unit_adjacency_count.fill(0)
    for province, unit in state.unit_info.items():
        province = int(province)
        power = int(unit.get('power', -1))
        if not 0 <= power < int(getattr(state, 'g_num_powers', 7)):
            continue
        unit_type = str(unit.get('type', 'A')).upper()
        if unit_type in ('F', 'FLT', 'FLEET'):
            coast = str(unit.get('coast', '')).upper()
            if coast and not coast.startswith('/'):
                coast = '/' + coast
            if coast and (province, coast) in state.fleet_coast_adj:
                adjacencies = state.fleet_coast_adj[(province, coast)]
            else:
                adjacencies = state.fleet_adj_matrix.get(province, ())
        else:
            adjacencies = [
                adjacent for adjacent in state.get_unit_adjacencies(province)
                if adjacent not in getattr(state, 'water_provinces', set())
            ]
        for adjacent in adjacencies:
            state.g_unit_adjacency_count[power, int(adjacent)] += 1
        state.g_unit_adjacency_count[power, province] += 1


def _max_pair_support_score(
    state: InnerGameState,
    support_scores: np.ndarray,
    power_a: int,
    power_b: int,
) -> int:
    """Return C:602-634's max outside both powers' home-SC sets."""
    excluded = set(getattr(state, 'home_centers', {}).get(power_a, ()))
    excluded.update(getattr(state, 'home_centers', {}).get(power_b, ()))
    valid = getattr(state, 'valid_provinces', ()) or range(len(support_scores))
    return max(
        (int(support_scores[province]) for province in valid
         if int(province) not in excluded),
        default=0,
    )


def _is_append_order_province(state: InnerGameState, province: int) -> bool:
    """Return ApplyInfluenceScores.c:676-713's normal append eligibility.

    The source first requires the unit-set lookup to return ``end``. It then
    appends a non-supply province directly; an empty supply centre takes the
    board-token branch and is rejected by its ``0x14`` empty-unit sentinel.
    Python has one synchronized unit view, so the observable gate is exactly
    "unoccupied non-supply province".
    """
    province = int(province)
    return (
        province not in state.unit_info
        and province not in getattr(state, 'sc_provinces', ())
    )


def _populate_global_province_score(state: InnerGameState) -> None:
    """Port C:507-549's int64 sum and integer normalization."""
    num_powers = int(getattr(state, 'g_num_powers', 7))
    num_provinces = _runtime_province_count(state)
    totals = np.sum(
        state.g_heat_movement[:num_powers, :num_provinces],
        axis=0,
        dtype=np.float64,
    )
    maximum = float(np.max(totals))
    state.g_global_province_score.fill(0.0)
    if maximum > 0.0:
        state.g_global_province_score[:num_provinces] = np.floor(
            totals * 100.0 / maximum
        )


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
    NUM_POWERS = int(getattr(state, 'g_num_powers', 7))
    NUM_PROVINCES = _runtime_province_count(state)

    # ── Pass 1-2: private token-key, five-round heat diffusion ───────
    # GenerateOrders owns the two movement-heat inputs. ApplyInfluenceScores'
    # six ordered sets independently produce g_heat_score and clear the
    # per-call attack-history accumulator.
    state.g_attack_history.fill(0)
    _compute_apply_heat_score(state)

    # ── Pass 3: g_influence_ratio normalisation ────────────────────────────────
    #
    # For each controlled SC, compare every outer power's heat against the
    # controller heat + 1. The controller's own row uses the strongest other
    # power as its numerator (ApplyInfluenceScores.c:330-379).
    _populate_influence_ratio(state)

    # ── Pass 4: g_unit_adjacency_count ─────────────────────────────────────────
    #
    # g_unit_adjacency_count[power][province] = count of power's units that can
    # reach province (each unit counts its own province + all adjacencies).
    _populate_unit_adjacency_count(state)

    # ── Pass 6 (early): Normalise g_heat_movement / g_heat_movement_b to 100 ───
    #
    # Must run before Pass 5 so the score formula has normalised inputs.
    # DAT_004ec2f0 divides by max+1; DAT_005af0e8 divides by max. Both use
    # integer division in the binary.
    _normalize_movement_heat(state)

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
            best_support = _max_pair_support_score(
                state, support_scores, power_a, power_b
            )

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
                    if not _is_append_order_province(state, prov):
                        continue

                    flag1 = True
                    flag2 = True
                    flag3 = False

                    owner = int(state.g_order_dip_owner[prov])
                    # ApplyInfluenceScores.c packs these into node+0x1c:
                    # byte 0 (flag1) is cleared when the other power owns the
                    # province; byte 1 (flag2) is cleared when Albert owns it.
                    if owner == power_b:
                        flag1 = False
                    elif owner == own_power:
                        flag2 = False

                    # AppendOrder = std::map<int,OrderEntry>::insert keyed by sort_key
                    state.g_order_list.append({
                        'flag1': flag1,
                        'flag2': flag2,
                        'flag3': flag3,
                        'province': prov,
                        'power': power_b,
                        # Compatibility alias retained for older snapshots.
                        'ally_power': power_b,
                        'score': sort_key,
                        'done': False,
                    })

    # AppendOrder's comparator routes a larger numeric key to the left subtree;
    # the tree's begin()/iterator walk therefore visits scores in descending
    # numeric order. Keep that priority order for the Python list consumers.
    state.g_order_list.sort(key=lambda e: e['score'], reverse=True)

    # ── Pass 6 (cont.): g_global_province_score + inter-power contact matrices ──
    _populate_global_province_score(state)

    # Contact matrices: C layout is a single flat BSS region, stride 63
    # (= 3×21 slots/row): g_contact_count at base−21 int32s, g_contact_weighted
    # at base, g_contact_owner_count at base+21 int32s.  Each 21-slot block
    # holds 7 values (other_power 0..6) + 14 padding.  Python (7,7) arrays
    # capture this correctly; reads must use the three separate arrays.
    _populate_contact_matrices(state)


def compute_alliance_score(state: InnerGameState) -> None:
    """
    Port of g_AllianceScore computation (GenerateOrders.c lines 567-618).

    Called from generate_orders Phase 6, after Phase 3 snapshots
    g_influence_matrix → g_influence_matrix_raw.  NOTE: g_AllianceScore has no
    read sites in the C binary; this write is faithful to C but currently dead.
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

        # C gate (GenerateOrders.c:626-628):
        #     if ((board[3 + prov*0x24] != '\0')                     <- SC flag
        #         && (((unit_field >> 8) != 'A')                     <- not an army
        #             || ((unit_field & 0xff) == 0x14)))             <- OR no unit
        #
        # Fixed 2026-08-18: the port required a unit to be present
        # (`if prov not in state.unit_info: continue`) and never checked the
        # supply-centre flag.  C's `(unit_field & 0xff) == 0x14` branch is
        # precisely the "province is EMPTY" case, and byte +3 is the
        # supply-centre flag (see §1.1).  So the eligible set is
        # "supply centres not occupied by an army", which is exactly the
        # empty neutral centres — SPA, POR, BEL, TUN — that the port could
        # never select.  Adjustment 4 in score_provinces gives the opening
        # target 150 instead of the 75 default, doubling its BFS seed.
        # Sorted: C walks the province array in index order, and the `>`
        # comparison below keeps the FIRST maximum, so iteration order is
        # part of the result.
        sc_provs = sorted(getattr(state, 'sc_provinces', None) or ())
        for prov in sc_provs:
            unit = state.unit_info.get(prov)
            if unit is not None and unit.get('type') in ('A', 'AMY'):
                # An army sitting here disqualifies the province; a fleet or
                # an empty province does not.
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
    Port of NormalizeInfluenceMatrix (standalone C function).

    Runs all four phases that the C version runs:
      Phase 1 — trust-adjust: g_influence_matrix[r,c] = raw[r,c] / (trust[r,c] + 1)
                No own_power exemption and no divide-by-6 branch (contrast with
                compute_influence_matrix Phase 1).  Divisor is the full 64-bit
                (trust_hi:trust_lo) + 1, matching CONCAT44 carry propagation in C.
      Phase 2 — per-row sum via PackScoreU64 (_float_to_int64 of row sum).
      Phase 3 — noise injection: cell += _safe_pow(cell / (row_sum+1), 0.3) * 500.
      Phase 4 — row-normalise each row to sum 100 (skip if row_sum == 0).
    """
    num_powers = 7

    # Phase 1 — unconditional trust-adjust (no own_power special-casing)
    # Divisor mirrors CONCAT44(trust_hi + carry, trust_lo + 1): reconstruct the
    # full 64-bit trust value so carry from lo→hi is handled correctly.
    for row in range(num_powers):
        for col in range(num_powers):
            raw = float(state.g_influence_matrix_raw[row, col])
            trust_lo = int(np.uint32(state.g_ally_trust_score[row, col]))
            trust_hi = int(state.g_ally_trust_score_hi[row, col])
            divisor = ((trust_hi << 32) | trust_lo) + 1
            state.g_influence_matrix[row, col] = raw / divisor if divisor != 0 else raw

    # Phase 2 — per-row sum via PackScoreU64
    power_sum = np.array(
        [_float_to_int64(float(np.sum(state.g_influence_matrix[p]))) for p in range(num_powers)],
        dtype=np.int64,
    )

    # Phase 3 — noise injection
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
