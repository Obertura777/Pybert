"""Small scoring primitives used throughout heuristics.

Split from heuristics.py during the 2026-04 refactor.

- ``BuildOrderSpec``           — one build-order candidate node (C tree node)
- ``build_candidate_list_find`` — g_BuildCandidateList lower-bound lookup
- ``evaluate_province_score`` — EvaluateProvinceScore (FUN_00433ce0)
- ``compute_winter_builds``   — ComputeWinterBuilds (FUN_00445be0)
- ``_safe_pow``                — pow with base<=0 guard (FUN_0047b370 proxy)
- ``evaluate_alliance_score`` — EvaluateAllianceScore (FUN_0043bd20)

These are leaf primitives — they depend only on ``numpy`` and
``InnerGameState``.  ``_safe_pow`` is re-imported by sibling modules
(``influence``) that need the base<=0 guard.
"""

from dataclasses import dataclass

import numpy as np

from ..state import InnerGameState


@dataclass
class BuildOrderSpec:
    """One build-order candidate node in g_build_candidate_list.

    Mirrors the C order-node layout at DAT_00bc1e1c:
      +0x10  target_province  (int)
      +0x14  coast_short      (ushort)
      +0x20  score            (double, capped at 30.0 in ComputeWinterBuilds)
    """
    target_province: int
    coast_short: int
    score: float


def build_candidate_list_find(state: InnerGameState, province_id: int) -> list:
    """Python port of g_BuildCandidateList (FUN_00…, Source/heuristics/g_BuildCandidateList.c).

    C: lower-bound lookup on the (province_id, coast_short)-keyed BST at
    DAT_00bc1e1c; inserts an empty sub-list node when the key is absent.

    Python: the BST is a dict[province_id, list[BuildOrderSpec]]; lower-bound
    collapses to setdefault because outer iteration in compute_winter_builds
    does not require sorted-province traversal.  coast_short is implicit in
    the sub-list ordering (entries appended in insertion order).
    """
    return state.g_build_candidate_list.setdefault(province_id, [])

def evaluate_province_score(state: InnerGameState, province_id: int, power_id: int) -> int:
    """
    Port of FUN_00433ce0 / EvaluateProvinceScore.
    
    A granular scoring heuristic to evaluate the strategic desirability of acquiring 
    or holding a specific province for a given power. It acts as an input scalar to 
    the Monte Carlo system.
    """
    max_threatening_adj_scs = state.get_max_threatening_adj_scs(province_id, power_id)
    turn_counter = state.g_near_end_game_factor
    score = 0
    
    if max_threatening_adj_scs == 0:
        convoy_reach = state.g_convoy_reach_count[power_id, province_id]
        if convoy_reach > 0:
            own_reach = state.g_own_reach_score[power_id, province_id]
            if own_reach == 0:
                score = 50 if turn_counter <= 6.0 else 100
            else:
                score = 2 if turn_counter <= 6.0 else 15
        else:
            score = 0
    else:
        win_threshold = state.win_threshold 
        pct = (max_threatening_adj_scs * 100) // win_threshold
        
        if pct > 50:
            total_reach = state.g_total_reach_score[power_id, province_id]
            own_reach = state.g_own_reach_score[power_id, province_id]

            # C (EvaluateProvinceScore.c:149-160): formula fires when own_reach
            # <= total_reach + 1 (province contested — not dominated by us).
            # own_reach > total_reach + 1 → we dominate → score = 50.
            if own_reach <= total_reach + 1:
                score = ((pct - 50) * 150) // 100 + 50
            else:
                score = 50
        else:
            score = 50

    # C gate (line 163-170): fires on local_38 == 0 (max_threatening_adj_scs == 0),
    # NOT on score == 0 — the convoy-reach branch can set score != 0 before this.
    #
    # Fixed 2026-08-18: was `state.g_uniform_mode`, a phantom attribute that
    # nothing in the port ever writes, so this branch was dead.  C's test here
    # (EvaluateProvinceScore.c:163) is `DAT_00baed68 == '\x01' && NearEndGame
    # < 3.0`, and DAT_00baed68 is the press flag — bound as g_press_flag at
    # 20-odd other sites in this port.
    if int(getattr(state, 'g_press_flag', 0)) == 1 and state.g_near_end_game_factor < 3.0:
        if max_threatening_adj_scs == 0 and state.g_enemy_mobility_count[power_id, province_id] > 0:
            score = 2
            
    return score


def compute_winter_builds(state: InnerGameState, own_power: int):
    """
    Port of FUN_00445be0 / ComputeWinterBuilds.
    Scores winter build-order candidates.

    C algorithm:
      For each province_id (outer tree iterator on g_BuildCandidateList):
        Read unit descriptor at province_id:
          uVar2 = *(ushort*)(gamestate + province_id * 0x24 + 0x20)
          high byte = unit type char ('A' → local_3c = power_idx, else local_3c = 0x14)
          Armies use the low byte (power index, 0-6) for comparisons;
          Fleets use sentinel 0x14 (never equals any real power index).

        For each order in the province's sub-list (inner tree walk):
          order_score = min(*(double*)(iVar6 + 0x20), 30.0)  — capped to 30.0

          Section 1 (iVar3 != local_c): target != province_id
            local_4c += 10000.0 / order_score

          Section 2 (g_SCOwnership check):
            if g_SCOwnership[own_power, target] == 1:
              UnitList_FindOrInsert → get unit record at target
              if order.coast_short == unit_record.coast_short:
                local_4c += 10000.0 / order_score

          Section 3 (g_friendly_unit_flag / g_established_ally_flag):
            if friendly_flag[target] == 1 OR established_ally_flag[target] == 1:
              → jump to LAB_00445f2e
            elif g_stab_flag[target] == 1 OR g_retreat_flag[target] == 1:
              → jump to LAB_00445f2e  (same ally-unit-bonus path)
            else: skip

            LAB_00445f2e:
              UnitList_FindOrInsert → get unit record at target
              if order.coast_short == unit_record.coast_short:
                if (unit_record.power == local_3c) OR
                   (local_3c == 0x14 AND unit_record.power != own_power):
                  local_48 += 10000.0 / order_score

                if local_3c == own_power:
                  if NOT (stab_flag[target] == 1 OR retreat_flag[target] == 1):
                    → skip trust check  (friendly/ally entry does NOT open the trust path)
                  ally_idx = own_power * 21 + unit_record.power
                  if trust_hi[ally_idx] < 1 AND (trust_hi < 0 OR trust_lo < 3):
                    local_48 += 10000.0 / order_score

    Fix 2026-04-21 (H-1): Previously read non-existent order.coast attribute.
    Now extracts unit type from state.unit_info and uses coast comparison from
    order.target_coast vs unit record's coast (matching C's *(short*)(iVar6+0x14)
    == *(short*)(ppiVar10+1) pattern).
    """
    for province_id, sub_list in state.g_build_candidate_list.items():
        local_4c = 0.0  # position score A — own unit fitness
        local_48 = 0.0  # position score B — ally unit fitness

        # C: uVar2 = *(ushort*)(gamestate + province_id * 0x24 + 0x20)
        # high byte = type char; low byte = unit's power index (0-6).
        # If type == 'A': local_3c = power of the army at province_id.
        # Else (FLT): local_3c = 0x14 (sentinel — never equals own_power 0-6).
        unit_at_prov = state.unit_info.get(province_id)
        if unit_at_prov is not None and unit_at_prov.get('type', 'A') == 'A':
            local_3c = unit_at_prov.get('power', 0)   # army power index
        else:
            local_3c = 0x14  # fleet sentinel

        for order in sub_list:
            target = order.target_province
            order_score = min(order.score, 30.0)
            if order_score <= 0.001:
                order_score = 0.001

            # Section 1: target != province_id
            # C: if (iVar3 != local_c) → local_4c += 10000.0 / fVar12
            if target != province_id:
                local_4c += 10000.0 / order_score

            # Section 2: g_SCOwnership[own_power, target] == 1
            # C: UnitList_FindOrInsert → compare coast shorts
            iVar11 = own_power * 0x100
            if int(state.g_sc_ownership[own_power, target]) == 1:
                target_unit = state.unit_info.get(target)
                unit_coast = target_unit.get('coast', 0) if target_unit else -1
                if order.coast_short == unit_coast:
                    local_4c += 10000.0 / order_score

            # Section 3: friendly/ally unit bonus (local_48)
            # C checks 4 flag arrays; any hit → LAB_00445f2e
            # Updated 2026-04-21: g_friendly_unit_flag and g_established_ally_flag
            # are now 2D [outer_power, prov]; index via own_power.
            f_flag = getattr(state, 'g_friendly_unit_flag', np.zeros((7, 256)))
            e_flag = getattr(state, 'g_established_ally_flag', np.zeros((7, 256)))
            if f_flag.ndim == 2:
                friendly_flag = int(f_flag[own_power, target])
                ally_flag = int(e_flag[own_power, target])
            else:
                # Fallback for 1D (shouldn't happen after this fix)
                friendly_flag = int(f_flag[target]) if f_flag.ndim == 1 else 0
                ally_flag = int(e_flag[target]) if e_flag.ndim == 1 else 0
            stab_flag = int(getattr(state, 'g_stab_unit_flag', np.zeros(256))[target])
            retreat_flag = int(getattr(state, 'g_retreat_unit_flag', np.zeros(256))[target])

            enter_ally_bonus = (friendly_flag == 1 or ally_flag == 1 or
                                stab_flag == 1 or retreat_flag == 1)
            if enter_ally_bonus:
                # LAB_00445f2e: UnitList_FindOrInsert → compare coast shorts
                target_unit = state.unit_info.get(target)
                unit_coast = target_unit.get('coast', 0) if target_unit else -1
                if order.coast_short == unit_coast:
                    # C: if (ppiVar10[2] == local_3c) OR
                    #       (local_3c == 0x14 AND ppiVar10[2] != piVar5)
                    unit_power = target_unit.get('power', -1) if target_unit else -1
                    if (unit_power == local_3c) or (local_3c == 0x14 and unit_power != own_power):
                        local_48 += 10000.0 / order_score

                    # C: if (local_3c == piVar5) — i.e. local_3c == own_power
                    if local_3c == own_power:
                        # C lines 195-201: trust check runs only when stab OR retreat is set;
                        # friendly/ally entry does NOT open this path.
                        if stab_flag == 1 or retreat_flag == 1:
                            # Trust gate: C uses stride 21, but Python arrays are (7,7).
                            # Fixed 2026-04-21: use correct flat index for (7,7): own_power * 7 + unit_power
                            try:
                                t_hi = int(state.g_ally_trust_score_hi[own_power, unit_power])
                                t_lo = int(state.g_ally_trust_score[own_power, unit_power])
                            except (IndexError, AttributeError):
                                t_hi = 0
                                t_lo = 0
                            if t_hi < 1 and (t_hi < 0 or t_lo < 3):
                                local_48 += 10000.0 / order_score

        state.g_winter_score_a[province_id] = local_4c
        state.g_winter_score_b[province_id] = local_48


def _safe_pow(base: float, exp: float) -> float:
    """FUN_0047b370 proxy. Returns base**exp; returns 0.0 if base <= 0."""
    if base <= 0.0:
        return 0.0
    try:
        return base ** exp
    except OverflowError:
        # The C floating-point helper saturates to +inf for an overflowing
        # positive power; Python raises instead.  Callers use the result in a
        # denominator, where +inf correctly contributes a zero share.
        return float('inf')


def _float_to_int64(value: float) -> int:
    """Port of FloatToInt64 / PackScoreU64 (Source/utils/FloatToInt64.c).

    The C sequence (x87 FISTP + remainder check) is truncation toward zero
    for ALL inputs, not just half-integer boundaries.  Trace:
      ROUND(v) → nearest integer r (banker's mode)
      frac = v - r
      positive branch: if frac < 0 (rounded up), r -= 1
      negative branch: if -frac < 0 (rounded away from zero), r += 1
    Both branches undo any round-away-from-zero step, giving int(v) exactly.
    """
    return int(value)


def evaluate_alliance_score(state: InnerGameState, own_power: int,
                            trial_weight: int = 30) -> int:
    """
    Port of EvaluateAllianceScore (FUN_0043bd20).

    Complex per-power desirability scoring using unit positions, trust levels,
    threat assessment, and alliance history. Returns the evaluated candidate's
    aggregate score and writes its per-opponent components to
    ``state.g_alliance_desirability`` for diagnostics.

    Algorithm phases:
      0. Setup: initialize accumulators and weights based on NearEndGameFactor
      1. Unit-list walk: populate province_visit and per-unit scoring arrays
      2. Province threat scoring: compute threat_score from reach arrays
      3. Per-province occupation scoring: apply trust-gated penalties/bonuses
      4. Fleet adjacency scoring: score uncertain-trust fleet interactions
      5. Final accumulation: trust-weighted per-power scoring
    """
    num_powers = 7
    num_provinces = 256
    state.g_alliance_desirability.fill(0.0)

    # --- Phase 0: Setup ---
    win_threshold = state.win_threshold  # typically 18
    near_end_factor = float(state.g_near_end_game_factor)

    # Weight factors based on NearEndGameFactor
    enemy_weight = 50
    ally_weight = 50
    if near_end_factor >= 3.0 and int(state.sc_count[own_power]) > 2:
        if near_end_factor < 5.0:
            enemy_weight = 80
            ally_weight = 70
        elif near_end_factor >= 6.0:
            enemy_weight = 120
            ally_weight = 100
        else:  # 5.0 <= near_end_factor < 6.0
            enemy_weight = 100
            ally_weight = 90

    # Initialize per-power accumulators
    main_score = np.full(num_powers, 5000.0, dtype=np.float64)
    deduction = np.zeros(num_powers, dtype=np.float64)
    enemy_penalty = np.zeros(num_powers, dtype=np.float64)
    ally_affinity = np.zeros(num_powers, dtype=np.float64)
    threat_a = np.zeros(num_powers, dtype=np.float64)
    threat_b = np.zeros(num_powers, dtype=np.float64)
    opening_bonus = np.zeros(num_powers, dtype=np.float64)

    # Initialize per-power × province arrays
    province_visit = np.zeros((num_powers, num_provinces), dtype=np.float64)
    threat_score = np.zeros((num_powers, num_provinces), dtype=np.float64)
    fleet_adj_score = np.zeros((num_powers, num_provinces), dtype=np.float64)
    prov_move_count = np.zeros(num_provinces, dtype=np.float64)

    # --- Phase 1: token-key record walk ---
    # EvaluateAllianceScore.c:182-219 walks DAT_00baed7c, not the unit list.
    # record[0x1a+p] is the live candidate weight written by
    # UpdateAllyOrderScore.  Sum both material token channels by province.
    key_weights = (
        state.g_key_weight[:, :num_provinces].astype(np.float64, copy=False)
        + state.g_key_weight_flt[:, :num_provinces].astype(
            np.float64, copy=False)
    )
    province_visit[:] = key_weights
    prov_move_count[:] = np.sum(key_weights, axis=0)

    # --- Phase 2: Province threat scoring ---
    # C: EvaluateAllianceScore.c lines 229–262.
    # Reads DAT_00b9a980[inner*256+prov] + DAT_00b95580[inner*256+prov] (MC pressure
    # accumulated by UpdateAllyOrderScore per candidate) not the static reach arrays.
    # Python: use g_mc_province_pressure + g_mc_fleet_pressure when present and non-zero;
    # fall back to g_own_reach_score + g_enemy_reach_score before first MC run.
    have_mc = (hasattr(state, 'g_mc_province_pressure') and
               state.g_mc_province_pressure.any())
    # C (EvaluateAllianceScore.c:238-254) applies the near-end-game rule to each
    # INNER power's contribution individually — the <= 5.0 arm keeps a running
    # maximum over single inner values, it does not max against their sum.  It
    # also skips any inner power whose relation with outer is >= 10.
    # Corrected 2026-08-12: both the relation gate and the max-vs-sum shape.
    if have_mc:
        pressure_rows = (
            state.g_mc_province_pressure[:, :num_provinces].astype(
                np.float64, copy=False)
            + state.g_mc_fleet_pressure[:, :num_provinces].astype(
                np.float64, copy=False)
        )
    else:
        pressure_rows = (
            state.g_own_reach_score[:, :num_provinces].astype(
                np.float64, copy=False)
            + state.g_enemy_reach_score[:, :num_provinces].astype(
                np.float64, copy=False)
        )

    # C's inner contribution depends only on inner_power/province; the outer
    # loop merely selects eligible rows via relation<10 and inner!=outer.
    # Apply that fixed 7-row selection in NumPy. Max is bit-identical; sums are
    # exact for these bounded integer-valued pressure arrays in float64.
    for outer_power in range(num_powers):
        eligible = [
            inner_power for inner_power in range(num_powers)
            if inner_power != outer_power
            and int(state.g_relation_score[outer_power, inner_power]) < 10
        ]
        if not eligible:
            continue
        selected = pressure_rows[eligible]
        if near_end_factor <= 5.0:
            threat_score[outer_power] = np.maximum(
                np.max(selected, axis=0), 0.0)
        else:
            threat_score[outer_power] = np.sum(selected, axis=0)

    # --- Phase 3a: empty-province pressure penalty (C:264-289) ---
    # C runs this over provinces with NO unit (province_record+3 == '\0'; the
    # '\x01' branch at :290 is the occupied case handled in 3b below), reads
    # own_power's row only, and accumulates into a single scalar.  It compares
    # threat_score[own][prov] against the MC province pressure at the same
    # slot, and gates the band on the caller's trial weight (param_2 —
    # UpdateAllyOrderScore.c:1069 passes local_b08, the per-candidate weight),
    # not on the win threshold.
    # Corrected 2026-08-12: the port iterated occupied provinces, looped every
    # power instead of own_power, compared against province_visit, and used
    # win_threshold as the band cutoff.
    occupied = np.zeros(num_provinces, dtype=bool)
    occupied_provinces = [
        int(prov) for prov in state.unit_info
        if 0 <= int(prov) < num_provinces
    ]
    if occupied_provinces:
        occupied[occupied_provinces] = True
    own_threat = threat_score[own_power, :num_provinces]
    own_pressure = (
        state.g_mc_province_pressure[own_power, :num_provinces]
        if hasattr(state, 'g_mc_province_pressure')
        else np.zeros(num_provinces, dtype=np.float64)
    )
    eligible_empty = (~occupied) & (own_threat > 0.0) & (own_pressure > 0.0)
    near_band = eligible_empty & (
        (own_pressure - own_threat) < float(trial_weight)
    )
    strong_pressure = near_band & (own_threat * 3 < own_pressure * 2)
    weaker_pressure = near_band & ~strong_pressure & (own_threat < own_pressure)
    unequal_pressure = (
        near_band & ~strong_pressure & ~weaker_pressure
        & (own_pressure != own_threat)
    )
    far_band = eligible_empty & ~near_band
    enemy_penalty[own_power] += (
        int(np.count_nonzero(strong_pressure)) * 10
        + int(np.count_nonzero(weaker_pressure)) * 5
        - int(np.count_nonzero(unequal_pressure)) * 10
        + int(np.count_nonzero(far_band)) * 20
    )

    # --- Phase 3b: same-power token-key contribution ---
    # C:574-637 adds base_score[key,power] * live_weight / trial_weight to the
    # evaluated power before occupation/trust adjustments.  This contribution
    # was entirely absent when Python substituted static reach arrays.
    _tw_int = max(int(trial_weight), 1)
    for score_table, weight_table in (
            (state.final_score_set, state.g_key_weight),
            (state.final_score_set_flt, state.g_key_weight_flt)):
        weights = weight_table[:num_powers, :num_provinces].astype(
            np.int64, copy=False
        )
        # C reads integer score records.  Python stores the same integral
        # values in float64 tables, so this vectorized cast is identical to
        # the former per-cell ``int(...)`` conversion.
        base_scores = score_table[:num_powers, :num_provinces].astype(
            np.int64, copy=False
        )
        weighted_scores = base_scores * weights
        main_score += np.sum(
            weighted_scores // _tw_int, axis=1, dtype=np.int64
        )

        # C:623-637 applies the sustained-attack premium to the same weighted
        # keys.  Batch the fixed 7x256 record pass instead of entering Python
        # once for every nonzero key.
        premium_mask = (
            (state.g_attack_history[:num_powers, :num_provinces] > 10)
            & (state.g_sc_ownership[:num_powers, :num_provinces] == 0)
            & (state.g_threat_level[:num_powers, :num_provinces] > 0)
        )
        premium = ((weighted_scores * 7) // 20) // _tw_int
        main_score += np.sum(
            np.where(premium_mask, premium, 0), axis=1, dtype=np.int64
        )

    # --- Phase 3c: occupied-province scoring ---
    for prov, unit_data in state.unit_info.items():
        unit_power = unit_data.get('power', -1)
        unit_type = unit_data.get('type', 'A')
        if unit_power < 0:
            continue

        for outer_power in range(num_powers):
            if outer_power != unit_power:
                # Other power's unit: check trust and threat levels
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, unit_power]) if hasattr(state, 'g_ally_trust_score_hi') else 0
                trust_lo = int(state.g_ally_trust_score[outer_power, unit_power]) if hasattr(state, 'g_ally_trust_score') else 0
                own_reach = float(state.g_own_reach_score[outer_power, prov])
                threat_val = threat_score[outer_power, prov]

                # Apply trust-weighted scoring
                if own_reach > 0:
                    if trust_hi < 1 and (trust_hi < 0 or trust_lo < 3):
                        ally_affinity[outer_power] -= 10
                    elif threat_val > 0:
                        ally_affinity[outer_power] += 5

    # --- Phase 4: water-record fleet-chain scoring (C lines 748-862) ---
    # C walks every DAT_00baed7c key whose province has the water marker, then
    # follows FLT adjacency.  The adjacent lookup explicitly constructs an
    # AMY key and requires its live weight to be positive.
    local_a808 = np.zeros((num_powers, num_provinces), dtype=np.float64)
    for prov in sorted(getattr(state, 'water_provinces', ())):
        for score_table, source_weights in (
                (state.final_score_set, state.g_key_weight),
                (state.final_score_set_flt, state.g_key_weight_flt)):
            for eval_power in range(num_powers):
                source_weight = int(source_weights[eval_power, prov])
                if source_weight <= 0:
                    continue
                base_score = (
                    (int(score_table[eval_power, prov]) + 50) * source_weight
                ) // _tw_int
                for adj_prov in state.fleet_adj_matrix.get(prov, []):
                    adjacent_weight = int(
                        state.g_key_weight[eval_power, adj_prov]
                    )
                    if adjacent_weight <= 0:
                        continue
                    owns_adjacent_sc = (
                        int(state.g_board_sc_ownership[eval_power, adj_prov]) == 1
                    )
                    factor = 0.1 if owns_adjacent_sc else 0.05
                    cap = 20.0 if owns_adjacent_sc else 10.0
                    new_val = (
                        adjacent_weight * base_score * factor
                    ) / _tw_int
                    if new_val > local_a808[eval_power, adj_prov]:
                        local_a808[eval_power, adj_prov] = min(new_val, cap)

    # Transfer local_a808 into fleet_adj_score (used by Phase 5)
    fleet_adj_score[:] = local_a808

    # --- Phase 5a: per-unit reach accumulation (C:1105-1210) ---
    # This loop was missing entirely, which left main_score pinned at its 5000
    # seed and made every non-own power score exactly (2000-5000)*50 = -150000.
    # Ported 2026-08-12 once FUN_0041c270 was decoded: it is
    # std::map<pair<province,coast>, int[42]>::operator[], returning node+5, so
    # value[p] is that (province, unit/coast token)'s per-power score.  Select
    # the current unit's AMY/FLT channel through state.fss below.
    #
    # Two arms, keyed on whether the unit belongs to the power being scored:
    #   own unit  (C:1115) — subtract its reach, then add a move bonus when the
    #                        destination scores better than 0.85x the source
    #                        and press is off.
    #   other's   (C:1168) — add its reach, then subtract a trial-weight-scaled
    #                        term when the friendly-unit flag is clear.
    _tw = float(trial_weight) if trial_weight else 1.0
    press_flag = int(getattr(state, 'g_press_flag', 0))   # C: DAT_00baed68
    for prov, unit_data in state.unit_info.items():
        unit_power = unit_data.get('power', -1)
        unit_type = unit_data.get('type', 'A')
        if not (0 <= prov < num_provinces):
            continue
        for power in range(num_powers):
            reach_at = float(state.g_unit_province_reach[power, prov])
            moved = float(prov_move_count[prov])

            if unit_power == power:
                # C:1119 gate — int64 g_enemy_reach_score at (power, prov) > 0.
                if float(state.g_enemy_reach_score[power, prov]) <= 0:
                    continue
                threat_b[power]   -= reach_at
                main_score[power] -= reach_at

                # C:1131-1142 — a unit standing here that belongs to someone
                # else disqualifies the move bonus.
                occupant = state.unit_info.get(prov, {}).get('power', power)
                if occupant != power:
                    continue
                if int(state.g_order_table[prov, 0]) not in (2, 6):  # MTO / CTO
                    continue
                dest = int(state.g_order_table[prov, 2])
                if not (0 <= dest < num_provinces):
                    continue
                score_dest = state.fss(power, dest, unit_type)
                score_src = state.fss(power, prov, unit_type)
                if score_src * 0.85 < score_dest and press_flag == 0:
                    main_score[power] += ((_tw - moved) * reach_at) / _tw
            else:
                # C:1172 gate — int64 g_own_reach_score at (power, prov) > 0.
                if float(state.g_own_reach_score[power, prov]) <= 0:
                    continue
                main_score[power] += reach_at
                if int(state.g_friendly_unit_flag[power, prov]) == 0:
                    d = ((_tw - moved) * reach_at) / _tw
                    threat_b[power]   -= d
                    main_score[power] -= d

    # --- Phase 5: Final accumulation ---
    # EvaluateAllianceScore.c keeps ``piVar5`` pointed at
    # aiStack_10278[own_power].  That value is the function result consumed by
    # UpdateAllyOrderScore; DAT_0062db58/g_alliance_desirability is separate
    # per-opponent state.  The old port wrote only those opponent components,
    # returned None, and its caller read the deliberately untouched own-power
    # component (always zero), flattening every candidate score to zero.
    aggregate_score = float(main_score[own_power])
    for power in range(num_powers):
        if power == own_power:
            continue

        # Accumulate fleet adjacency scores
        main_score[power] += float(np.sum(fleet_adj_score[power]))

        # Apply penalties
        main_score[power] -= enemy_penalty[power]
        main_score[power] += ally_affinity[power]

        # Retrieve trust and relation scores
        trust_score = int(state.g_ally_trust_score[own_power, power]) if hasattr(state, 'g_ally_trust_score') else 0
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power]) if hasattr(state, 'g_ally_trust_score_hi') else 0
        relation_score = int(state.g_relation_score[own_power, power]) if hasattr(state, 'g_relation_score') else 0
        deceit_level = int(getattr(state, 'g_deceit_level', 0))

        # Final trust-weighted scoring (C lines 1068-1098)
        # Branch 1: untrusted / unknown → enemy weight
        # C: (trust==0 && trust_hi==0) || (trust==1 && trust_hi==0 && relation<0xb)
        if (trust_score == 0 and trust_hi == 0) or \
           (trust_score == 1 and trust_hi == 0 and relation_score < 11):
            # Enemy scoring: pull toward 2000 baseline
            score_adj = (2000.0 - main_score[power]) * enemy_weight
            aggregate_score += score_adj
        # Branch 2: trusted ally → ally weight
        # C: (trust_hi>=0 && (trust_hi>0 || trust!=0) && relation>0x13) ||
        #    (trust_hi>=0 && (trust_hi>0 || trust>2) && deceit_level>1)
        elif ((trust_hi >= 0 and (trust_hi > 0 or trust_score != 0) and relation_score > 19) or
              (trust_hi >= 0 and (trust_hi > 0 or trust_score > 2) and deceit_level > 1)):
            # Ally scoring: reward above 2000 baseline
            # C 1079-1095: boost weight when own_power==albert (piStack_1027c),
            # ally_weight<51 (default non-endgame), power==best_ally (DAT_004c6bc4),
            # and press flag (DAT_00baed68) is off.
            best_ally = int(getattr(state, 'g_best_ally_slot0', -1))
            albert_power = int(getattr(state, 'albert_power_idx', -1))
            press_flag = int(getattr(state, 'g_press_flag', 0))
            if (own_power == albert_power and ally_weight < 51
                    and power == best_ally and press_flag == 0 and best_ally >= 0):
                # +20 if best_ally has strictly more SCs, else +30
                if int(state.sc_count[own_power]) + 1 < int(state.sc_count[best_ally]):
                    effective_weight = ally_weight + 20
                else:
                    effective_weight = ally_weight + 30
            else:
                effective_weight = ally_weight
            score_adj = (main_score[power] - 2000.0) * effective_weight
            # C assigns through *piVar5 in the trusted-ally arm, rather than
            # adding as it does for the enemy arm.
            aggregate_score = score_adj
        else:
            score_adj = 0.0

        state.g_alliance_desirability[power] = score_adj

    return int(aggregate_score)


def evaluate_alliance_scores_batch(
    state: InnerGameState,
    own_power: int,
    trial_weight: int,
    key_weight_batch: np.ndarray,
    key_weight_flt_batch: np.ndarray,
    mc_pressure_batch: np.ndarray,
    mc_fleet_pressure_batch: np.ndarray,
    order_type_batch: np.ndarray,
    order_dest_batch: np.ndarray,
) -> np.ndarray:
    """Batch ``EvaluateAllianceScore`` across one power's candidate records.

    ``UpdateAllyOrderScore`` evaluates every candidate against the same board,
    relations, selected-slot groups, and trial weight.  Only six compact
    candidate snapshots vary.  The scalar port rebuilt fixed 7x256 scratch
    arrays and crossed the Python/NumPy boundary once per candidate; this
    implementation adds a leading candidate axis and performs the same phases
    in 7x256 batches.  Integer division order and candidate iteration order are
    retained so the returned scores are parity-compatible with the scalar
    evaluator.
    """
    batch_size = int(key_weight_batch.shape[0])
    if batch_size == 0:
        return np.empty(0, dtype=np.int64)

    num_powers = 7
    num_provinces = 256
    _tw_int = max(int(trial_weight), 1)
    _tw = float(trial_weight) if trial_weight else 1.0
    near_end_factor = float(state.g_near_end_game_factor)

    enemy_weight = 50
    ally_weight = 50
    if near_end_factor >= 3.0 and int(state.sc_count[own_power]) > 2:
        if near_end_factor < 5.0:
            enemy_weight, ally_weight = 80, 70
        elif near_end_factor >= 6.0:
            enemy_weight, ally_weight = 120, 100
        else:
            enemy_weight, ally_weight = 100, 90

    main_score = np.full((batch_size, num_powers), 5000.0, dtype=np.float64)
    enemy_penalty = np.zeros((batch_size, num_powers), dtype=np.float64)
    ally_affinity = np.zeros((batch_size, num_powers), dtype=np.float64)

    key_weights = (
        key_weight_batch[:, :num_powers, :num_provinces].astype(
            np.float64, copy=False
        )
        + key_weight_flt_batch[:, :num_powers, :num_provinces].astype(
            np.float64, copy=False
        )
    )
    prov_move_count = np.sum(key_weights, axis=1)
    pressure_rows = (
        mc_pressure_batch[:, :num_powers, :num_provinces].astype(
            np.float64, copy=False
        )
        + mc_fleet_pressure_batch[:, :num_powers, :num_provinces].astype(
            np.float64, copy=False
        )
    )
    threat_score = np.zeros(
        (batch_size, num_powers, num_provinces), dtype=np.float64
    )
    for outer_power in range(num_powers):
        eligible = [
            inner_power for inner_power in range(num_powers)
            if inner_power != outer_power
            and int(state.g_relation_score[outer_power, inner_power]) < 10
        ]
        if not eligible:
            continue
        selected = pressure_rows[:, eligible, :]
        if near_end_factor <= 5.0:
            threat_score[:, outer_power, :] = np.maximum(
                np.max(selected, axis=1), 0.0
            )
        else:
            threat_score[:, outer_power, :] = np.sum(selected, axis=1)

    occupied = np.zeros(num_provinces, dtype=bool)
    occupied_provinces = [
        int(prov) for prov in state.unit_info
        if 0 <= int(prov) < num_provinces
    ]
    if occupied_provinces:
        occupied[occupied_provinces] = True
    own_threat = threat_score[:, own_power, :]
    own_pressure = mc_pressure_batch[:, own_power, :num_provinces]
    eligible_empty = (
        (~occupied)[None, :] & (own_threat > 0.0) & (own_pressure > 0.0)
    )
    near_band = eligible_empty & (
        (own_pressure - own_threat) < float(trial_weight)
    )
    strong_pressure = near_band & (own_threat * 3 < own_pressure * 2)
    weaker_pressure = near_band & ~strong_pressure & (own_threat < own_pressure)
    unequal_pressure = (
        near_band & ~strong_pressure & ~weaker_pressure
        & (own_pressure != own_threat)
    )
    far_band = eligible_empty & ~near_band
    enemy_penalty[:, own_power] += (
        np.count_nonzero(strong_pressure, axis=1) * 10
        + np.count_nonzero(weaker_pressure, axis=1) * 5
        - np.count_nonzero(unequal_pressure, axis=1) * 10
        + np.count_nonzero(far_band, axis=1) * 20
    )

    premium_mask = (
        (state.g_attack_history[:num_powers, :num_provinces] > 10)
        & (state.g_sc_ownership[:num_powers, :num_provinces] == 0)
        & (state.g_threat_level[:num_powers, :num_provinces] > 0)
    )
    for score_table, weight_batch in (
            (state.final_score_set, key_weight_batch),
            (state.final_score_set_flt, key_weight_flt_batch)):
        base_scores = score_table[:num_powers, :num_provinces].astype(
            np.int64, copy=False
        )
        weights = weight_batch[:, :num_powers, :num_provinces].astype(
            np.int64, copy=False
        )
        weighted_scores = weights * base_scores[None, :, :]
        main_score += np.sum(
            weighted_scores // _tw_int, axis=2, dtype=np.int64
        )
        premium = ((weighted_scores * 7) // 20) // _tw_int
        main_score += np.sum(
            np.where(premium_mask[None, :, :], premium, 0),
            axis=2,
            dtype=np.int64,
        )

    for prov, unit_data in state.unit_info.items():
        unit_power = int(unit_data.get('power', -1))
        if unit_power < 0 or not 0 <= int(prov) < num_provinces:
            continue
        for outer_power in range(num_powers):
            if outer_power == unit_power:
                continue
            if float(state.g_own_reach_score[outer_power, prov]) <= 0:
                continue
            trust_hi = int(state.g_ally_trust_score_hi[outer_power, unit_power])
            trust_lo = int(state.g_ally_trust_score[outer_power, unit_power])
            if trust_hi < 1 and (trust_hi < 0 or trust_lo < 3):
                ally_affinity[:, outer_power] -= 10
            else:
                ally_affinity[
                    threat_score[:, outer_power, prov] > 0,
                    outer_power,
                ] += 5

    local_a808 = np.zeros(
        (batch_size, num_powers, num_provinces), dtype=np.float64
    )
    for prov in sorted(getattr(state, 'water_provinces', ())):
        for score_table, source_weights in (
                (state.final_score_set, key_weight_batch),
                (state.final_score_set_flt, key_weight_flt_batch)):
            for eval_power in range(num_powers):
                source_weight = source_weights[:, eval_power, prov].astype(
                    np.int64, copy=False
                )
                source_active = source_weight > 0
                if not np.any(source_active):
                    continue
                base_score = (
                    (int(score_table[eval_power, prov]) + 50) * source_weight
                ) // _tw_int
                for adj_prov in state.fleet_adj_matrix.get(prov, []):
                    adjacent_weight = key_weight_batch[
                        :, eval_power, adj_prov
                    ].astype(np.int64, copy=False)
                    active = source_active & (adjacent_weight > 0)
                    if not np.any(active):
                        continue
                    owns_adjacent_sc = (
                        int(state.g_board_sc_ownership[
                            eval_power, adj_prov
                        ]) == 1
                    )
                    factor = 0.1 if owns_adjacent_sc else 0.05
                    cap = 20.0 if owns_adjacent_sc else 10.0
                    new_value = (
                        adjacent_weight * base_score * factor
                    ) / _tw_int
                    destination = local_a808[:, eval_power, adj_prov]
                    destination[active] = np.maximum(
                        destination[active],
                        np.minimum(new_value[active], cap),
                    )

    press_flag = int(getattr(state, 'g_press_flag', 0))
    for prov, unit_data in state.unit_info.items():
        prov = int(prov)
        unit_power = int(unit_data.get('power', -1))
        unit_type = unit_data.get('type', 'A')
        if not 0 <= prov < num_provinces:
            continue
        moved = prov_move_count[:, prov]
        for power in range(num_powers):
            reach_at = float(state.g_unit_province_reach[power, prov])
            if unit_power == power:
                if float(state.g_enemy_reach_score[power, prov]) <= 0:
                    continue
                main_score[:, power] -= reach_at
                moving = np.isin(order_type_batch[:, prov], (2, 6))
                if not np.any(moving):
                    continue
                destinations = order_dest_batch[:, prov].astype(
                    np.int64, copy=False
                )
                valid_dest = moving & (destinations >= 0) & (
                    destinations < num_provinces
                )
                if not np.any(valid_dest) or press_flag != 0:
                    continue
                score_table = (
                    state.final_score_set_flt
                    if unit_type in ('F', 'FLT')
                    else state.final_score_set
                )
                score_dest = np.zeros(batch_size, dtype=np.float64)
                score_dest[valid_dest] = score_table[
                    power, destinations[valid_dest]
                ]
                score_src = float(score_table[power, prov])
                rewarded = valid_dest & (score_src * 0.85 < score_dest)
                main_score[rewarded, power] += (
                    ((_tw - moved[rewarded]) * reach_at) / _tw
                )
            else:
                if float(state.g_own_reach_score[power, prov]) <= 0:
                    continue
                main_score[:, power] += reach_at
                if int(state.g_friendly_unit_flag[power, prov]) == 0:
                    delta = ((_tw - moved) * reach_at) / _tw
                    main_score[:, power] -= delta

    aggregate_score = main_score[:, own_power].copy()
    desirability = np.zeros((batch_size, num_powers), dtype=np.float64)
    fleet_totals = np.sum(local_a808, axis=2)
    deceit_level = int(getattr(state, 'g_deceit_level', 0))
    best_ally = int(getattr(state, 'g_best_ally_slot0', -1))
    albert_power = int(getattr(state, 'albert_power_idx', -1))
    for power in range(num_powers):
        if power == own_power:
            continue
        main_score[:, power] += fleet_totals[:, power]
        main_score[:, power] -= enemy_penalty[:, power]
        main_score[:, power] += ally_affinity[:, power]

        trust_score = int(state.g_ally_trust_score[own_power, power])
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power])
        relation_score = int(state.g_relation_score[own_power, power])
        if ((trust_score == 0 and trust_hi == 0)
                or (trust_score == 1 and trust_hi == 0
                    and relation_score < 11)):
            score_adj = (2000.0 - main_score[:, power]) * enemy_weight
            aggregate_score += score_adj
        elif (
            (trust_hi >= 0 and (trust_hi > 0 or trust_score != 0)
             and relation_score > 19)
            or (trust_hi >= 0 and (trust_hi > 0 or trust_score > 2)
                and deceit_level > 1)
        ):
            if (own_power == albert_power and ally_weight < 51
                    and power == best_ally and press_flag == 0
                    and best_ally >= 0):
                if (int(state.sc_count[own_power]) + 1
                        < int(state.sc_count[best_ally])):
                    effective_weight = ally_weight + 20
                else:
                    effective_weight = ally_weight + 30
            else:
                effective_weight = ally_weight
            score_adj = (main_score[:, power] - 2000.0) * effective_weight
            aggregate_score = score_adj
        else:
            score_adj = np.zeros(batch_size, dtype=np.float64)
        desirability[:, power] = score_adj

    state.g_alliance_desirability[:] = desirability[-1]
    return aggregate_score.astype(np.int64)
