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
    """One source-position reach record in ``g_build_candidate_list``.

    ``DAT_00bc1e1c`` is an outer tree keyed by the reachable destination's
    ``(province, unit/coast token)``.  Each outer node owns an inner tree whose
    key is the possible source position's ``(province, unit/coast token)`` and
    whose payload contains the distance score read at node ``+0x20``.

    Python collapses outer coast keys into one province list, so the
    destination token is retained explicitly on every record.
    """
    source_province: int
    source_unit_type: str
    source_coast: str
    destination_unit_type: str
    destination_coast: str
    score: float

    @property
    def target_province(self) -> int:
        """Compatibility alias for the former, misnamed source field."""
        return self.source_province

    @property
    def coast_short(self) -> str:
        """Compatibility alias for the source unit/coast token."""
        return self.source_coast


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

    # C gate (line 163-170).  The comment that used to sit here claimed this
    # fires on `max_threatening_adj_scs == 0`, "NOT on score == 0".  The
    # disassembly says the opposite:
    #     00434057 CMP  byte [DAT_00baed68],0x1      ; press flag
    #     00434060 FCOMP float [DAT_004afb1c]        ; NearEndGame vs 3.0
    #     0043406b JP   ret
    #     00434071 OR   EAX,[ESP + local_34]         ; local_38 | local_34
    #     00434075 JNZ  ret                           ; i.e. skip unless SCORE == 0
    #     00434080 CMP  [EAX*8 + DAT_0057a8ec],ECX   ; g_enemy_mobility_count
    # `local_38`/`local_34` are the lo/hi dwords of the running SCORE (they are
    # what 00434032/0043403c/00434045/0043404f write as 100/50/15/2), not the
    # threat accumulator.  So the gate is `score == 0`: the convoy-reach branch
    # having set 50/100/2/15 must SUPPRESS this clobber, and the old reading
    # forced those back down to 2.
    #
    # Fixed 2026-08-18: was `state.g_uniform_mode`, a phantom attribute that
    # nothing in the port ever writes, so this branch was dead.  C's test here
    # (EvaluateProvinceScore.c:163) is `DAT_00baed68 == '\x01' && NearEndGame
    # < 3.0`, and DAT_00baed68 is the press flag — bound as g_press_flag at
    # 20-odd other sites in this port.
    if int(getattr(state, 'g_press_flag', 0)) == 1 and state.g_near_end_game_factor < 3.0:
        if score == 0 and state.g_enemy_mobility_count[power_id, province_id] > 0:
            score = 2
            
    return score


def compute_winter_builds(state: InnerGameState, own_power: int) -> None:
    """Port ComputeWinterBuilds (FUN_00445be0).

    For each supply-centre destination in the static DAT_00bc1e1c reach index,
    aggregate two inverse-distance channels over its possible source
    unit/coast tokens:

    * channel A covers currently legal build tokens and own-controlled,
      currently occupied matching source tokens;
    * channel B covers matching friendly, established-ally, or enemy-presence
      source units under the source's power/trust gates.

    The first channel caps only the legal-build contribution's distance score
    at 30.0. All other contributions use the record's raw distance score.
    """
    state.g_winter_score_a.fill(0.0)
    state.g_winter_score_b.fill(0.0)

    def normalize_type(value: object) -> str:
        return 'AMY' if str(value).upper() in ('A', 'AMY') else 'FLT'

    def normalize_coast(value: object) -> str:
        return str(value or '').upper().lstrip('/')

    def unit_matches(record: BuildOrderSpec, unit: dict | None) -> bool:
        if unit is None:
            return False
        return (
            normalize_type(unit.get('type')) == record.source_unit_type
            and normalize_coast(unit.get('coast')) == record.source_coast
        )

    # C reads the current adjustment-candidate BST at this+0x2478. The normal
    # Python WIN pipeline materializes the same legal token set before
    # ScoreProvinces. Keep a board-derived fallback for direct unit callers.
    available_build_keys = {
        (
            int(candidate['province']),
            str(candidate['unit_type']).upper(),
            normalize_coast(candidate.get('coast', '')),
        )
        for candidate in getattr(
            state, 'g_adjustment_build_candidates', ()
        )
    }
    delta = getattr(state, 'g_build_delta', {}).get(own_power, {})
    if (not available_build_keys
            and int(delta.get('flag', 0)) == 1
            and int(delta.get('delta', 0)) > 0):
        for province in state.home_centers.get(own_power, frozenset()):
            if (int(state.g_board_sc_ownership[own_power, province]) != 1
                    or province in state.unit_info):
                continue
            available_build_keys.add((province, 'AMY', ''))
            coast_tokens = sorted(
                normalize_coast(coast)
                for pid, coast in state.fleet_coast_adj
                if pid == province
            )
            if coast_tokens:
                available_build_keys.update(
                    (province, 'FLT', coast) for coast in coast_tokens
                )
            elif state.fleet_adj_matrix.get(province):
                available_build_keys.add((province, 'FLT', ''))

    sc_provinces = set(getattr(state, 'sc_provinces', ()))
    friendly = state.g_friendly_unit_flag
    established = state.g_established_ally_flag
    enemy_presence = state.g_enemy_presence

    for destination, records in state.g_build_candidate_list.items():
        # Province-record byte +3 is the supply-centre flag.
        if destination not in sc_provinces:
            continue

        destination_controller = int(state.g_sc_owner[destination])
        if not 0 <= destination_controller < int(state.g_num_powers):
            destination_controller = 0x14

        score_a = 0.0
        score_b = 0.0
        for record in records:
            source = int(record.source_province)
            raw_score = float(record.score)
            if raw_score <= 0.0:
                continue

            source_key = (
                source,
                record.source_unit_type,
                record.source_coast,
            )
            if source_key in available_build_keys:
                score_a += 10_000.0 / min(raw_score, 30.0)

            source_unit = state.unit_info.get(source)
            matches_source = unit_matches(record, source_unit)
            if (int(state.g_sc_ownership[own_power, source]) == 1
                    and matches_source):
                score_a += 10_000.0 / raw_score

            friendly_flag = int(friendly[own_power, source]) == 1
            established_flag = int(established[own_power, source]) == 1
            enemy_flag = int(enemy_presence[own_power, source]) == 1
            if not (friendly_flag or established_flag or enemy_flag):
                continue
            if not matches_source:
                continue

            source_power = int(source_unit.get('power', -1))
            if (source_power == destination_controller
                    or (destination_controller == 0x14
                        and source_power != own_power)):
                score_b += 10_000.0 / raw_score

            if (destination_controller == own_power
                    and (established_flag or enemy_flag)
                    and 0 <= source_power < state.g_ally_trust_score.shape[1]):
                trust_hi = int(
                    state.g_ally_trust_score_hi[own_power, source_power]
                )
                trust_lo = int(
                    state.g_ally_trust_score[own_power, source_power]
                )
                if trust_hi < 1 and (trust_hi < 0 or trust_lo < 3):
                    score_b += 10_000.0 / raw_score

        state.g_winter_score_a[destination] = score_a
        state.g_winter_score_b[destination] = score_b

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


def _signed_int_div(numerator: int, denominator: int) -> int:
    """Return C signed-integer division, truncating toward zero.

    Python's ``//`` floors negative results, while Albert's ``__alldiv``
    truncates them toward zero.  Keeping this arithmetic integer-only also
    avoids introducing binary-float fractions into the recovered int64 score
    trees.
    """
    numerator = int(numerator)
    denominator = int(denominator)
    if denominator == 0:
        raise ZeroDivisionError("integer division by zero")
    quotient = abs(numerator) // abs(denominator)
    return -quotient if (numerator < 0) != (denominator < 0) else quotient


def _signed_divide_array(numerator: np.ndarray, denominator: int) -> np.ndarray:
    """Vectorized C signed division for an integer NumPy array."""
    denominator = int(denominator)
    if denominator <= 0:
        raise ValueError("denominator must be positive")
    values = np.asarray(numerator, dtype=np.int64)
    return np.where(
        values < 0,
        -((-values) // denominator),
        values // denominator,
    )


def _trusted_foreign_sc_mask(state, num_powers: int,
                             num_provinces: int) -> np.ndarray:
    """Identify C's controller-trust cancellation cells.

    EvaluateAllianceScore.c:587-619 cancels a power's ordinary token-key
    contribution when the key is on a supply centre controlled by another
    sufficiently trusted power. Invalid/UNO controllers remain hostile and
    therefore do not cancel the contribution.
    """
    mask = np.zeros((num_powers, num_provinces), dtype=bool)
    for province in state.sc_provinces:
        province = int(province)
        if not 0 <= province < num_provinces:
            continue
        controller = int(state.g_sc_owner[province])
        if not 0 <= controller < num_powers:
            continue
        for power in range(num_powers):
            if controller == power:
                continue
            trust_lo = int(state.g_ally_trust_score[power, controller])
            trust_hi = int(state.g_ally_trust_score_hi[power, controller])
            hostile = trust_hi < 1 and (trust_hi < 0 or trust_lo < 3)
            if not hostile:
                mask[power, province] = True
    return mask


def _apply_sc_controller_phase(
    state: InnerGameState,
    main_score: np.ndarray,
    threat_score: np.ndarray,
    province_visit: np.ndarray,
    prov_move_count: np.ndarray,
    mc_pressure: np.ndarray,
    mc_fleet_pressure: np.ndarray,
    trial_weight: int,
) -> tuple[np.ndarray, np.ndarray]:
    """Port EvaluateAllianceScore.c:290-441 supply-centre pass.

    The recovered loop is keyed by province-record byte ``+3`` (the static
    supply-centre marker) and province-record ``+0x20`` (the controller), not
    by current unit occupancy.  Its only live contribution to ``main_score``
    is an early-game opening bonus.  A per-power defensive deduction scratch
    value gates that bonus; the separate hostile-pressure accumulator written
    by the C function is never read again.

    All candidate-varying arguments carry a leading batch dimension.  The
    scalar evaluator calls this helper with a one-candidate view so scalar and
    batched evaluation share the exact same signed-integer decisions.
    """
    batch_size, num_powers, num_provinces = threat_score.shape
    tw = max(int(trial_weight), 1)
    deduction = np.zeros((batch_size, num_powers), dtype=np.int64)
    hostile_pressure = np.zeros((batch_size, num_powers), dtype=np.int64)
    opening_bonus = np.zeros((batch_size, num_powers), dtype=np.int64)

    for province_value in sorted(getattr(state, 'sc_provinces', ())):
        province = int(province_value)
        if not 0 <= province < num_provinces:
            continue
        controller = int(state.g_sc_owner[province])
        controller_valid = 0 <= controller < num_powers

        for power in range(num_powers):
            for candidate in range(batch_size):
                threat = int(threat_score[candidate, power, province])
                visit = int(province_visit[candidate, power, province])
                moved = int(prov_move_count[candidate, province])

                if controller_valid and controller == power:
                    combined = (
                        int(mc_pressure[candidate, power, province])
                        + int(mc_fleet_pressure[candidate, power, province])
                    )
                    if float(state.g_near_end_game_factor) > 5.0:
                        for other in range(num_powers):
                            if (other != power and int(
                                    state.g_relation_score[power, other]) > 35):
                                combined += int(
                                    mc_pressure[candidate, other, province]
                                )

                    if threat <= 0:
                        continue
                    if threat < combined:
                        if combined < threat * 2 and moved == 0:
                            adjustment = _signed_int_div(
                                threat - combined + 1 + tw, 8
                            )
                        else:
                            adjustment = _signed_int_div(tw, 16)
                    else:
                        difference = threat - combined
                        if difference < tw:
                            if combined != 0:
                                if moved != 0:
                                    if threat != combined:
                                        adjustment = _signed_int_div(
                                            difference, 4
                                        )
                                    else:
                                        adjustment = _signed_int_div(tw, 16)
                                else:
                                    adjustment = _signed_int_div(
                                        difference + 1 + tw, 8
                                    )
                            else:
                                adjustment = threat
                        else:
                            adjustment = tw
                    deduction[candidate, power] -= adjustment
                    continue

                primary = int(mc_pressure[candidate, power, province])
                if primary <= 0:
                    continue
                fleet = int(mc_fleet_pressure[candidate, power, province])
                combined = primary * 2 if primary < fleet else primary + fleet
                if combined <= 0:
                    continue

                if combined < threat:
                    if visit > 0:
                        difference = threat - combined
                        adjustment = (
                            _signed_int_div(difference, 4)
                            if difference < tw else tw
                        )
                        deduction[candidate, power] -= adjustment
                    continue

                # Invalid/UNO controllers occupy the zero-initialized trust
                # slot in Albert's 21-power tables and therefore take this
                # same hostile (0/0) arm.
                if controller_valid:
                    trust_hi = int(
                        state.g_ally_trust_score_hi[power, controller]
                    )
                    trust_lo = int(state.g_ally_trust_score[power, controller])
                    hostile = (
                        trust_hi < 1 and (trust_hi < 0 or trust_lo < 2)
                    )
                else:
                    hostile = True
                if not hostile:
                    continue

                if visit < 1 or threat != 0:
                    difference = combined - threat
                    if difference < tw:
                        if threat == 0:
                            hostile_pressure[candidate, power] += combined
                        else:
                            if moved == 0:
                                difference += tw
                            elif visit > 0:
                                hostile_pressure[
                                    candidate, power
                                ] += visit
                                difference = None
                            if difference is not None:
                                hostile_pressure[
                                    candidate, power
                                ] += _signed_int_div(difference, 4)
                    else:
                        hostile_pressure[candidate, power] += tw

                # The opening-bonus test follows the hostile-pressure
                # accumulation via LAB_0043c25b.
                threat_path = int(
                    state.g_threat_path_score[power, province]
                )
                if (
                    visit == 0
                    and int(state.g_enemy_mobility_count[power, province]) == 0
                    and str(getattr(state, 'g_season', '')) == 'SPR'
                    and combined >= tw
                    and threat_path > 0
                ):
                    opening_bonus[candidate, power] += (
                        int(state.g_max_prov_score_per_power[power, province])
                        - threat_path
                    )

    active = (opening_bonus > 0) & (deduction == 0)
    main_score += np.where(active, opening_bonus, 0)
    return deduction, hostile_pressure


def _apply_controlled_sc_pressure_phase(
    state: InnerGameState,
    main_score: np.ndarray,
    province_visit: np.ndarray,
    mc_pressure: np.ndarray,
    trial_weight: int,
) -> None:
    """Port Albert.exe 0x43c478-0x43c637 owned-centre pressure pass.

    With press disabled, Albert revisits every supply centre controlled by the
    power being scored.  During the opening (NearEndGameFactor < 6), or when
    scoring Albert's own power, eligible other-power pressure builds a local
    cost.  The visit deficit for that centre is then added before the cost is
    subtracted from the power's score.

    Each floating-point expression is converted separately in the executable,
    so additions use ``_float_to_int64`` at the same boundaries rather than
    algebraically combining the terms.
    """
    if int(getattr(state, 'g_press_flag', 0)) != 0:
        return

    batch_size, num_powers, num_provinces = province_visit.shape
    near_end = float(state.g_near_end_game_factor)
    albert_power = int(getattr(state, 'g_albert_power', -1))
    tw = max(int(trial_weight), 1)

    for province_value in sorted(getattr(state, 'sc_provinces', ())):
        province = int(province_value)
        if not 0 <= province < num_provinces:
            continue
        controller = int(state.g_sc_owner[province])
        if not 0 <= controller < num_powers:
            continue
        if near_end >= 6.0 and albert_power != controller:
            continue

        power = controller
        own_reach = int(state.g_ally_reach_score[power, province])
        for candidate in range(batch_size):
            own_pressure = int(mc_pressure[candidate, power, province])
            accumulated = 0
            for other in range(num_powers):
                if other == power:
                    continue

                relation = int(state.g_relation_score[power, other])
                trust_hi = int(state.g_ally_trust_score_hi[power, other])
                trust_lo = int(state.g_ally_trust_score[power, other])
                trusted = trust_hi >= 0 and (trust_hi > 0 or trust_lo > 1)
                if relation < 10 and not trusted:
                    continue

                other_pressure = int(
                    mc_pressure[candidate, other, province]
                )
                if other_pressure <= 0 and own_reach <= 0:
                    continue

                if other_pressure > own_pressure:
                    accumulated = _float_to_int64(
                        accumulated
                        + 20.0
                        + (other_pressure - own_pressure) * 10.0 / tw
                    )
                elif own_pressure > tw:
                    accumulated += 1
                else:
                    accumulated = _float_to_int64(
                        accumulated
                        + 20.0
                        + (tw - own_pressure) * 10.0 / tw
                    )

            if accumulated <= 0:
                continue
            visit_deficit = tw - int(
                province_visit[candidate, power, province]
            )
            cost = _float_to_int64(
                accumulated + visit_deficit * 10.0 / tw
            )
            main_score[candidate, power] -= cost


def _apply_alliance_province_phase(
    state: InnerGameState,
    main_score: np.ndarray,
    fleet_adj_score: np.ndarray,
    prov_move_count: np.ndarray,
    counter_b: np.ndarray,
    own_power: int,
    trial_weight: int,
) -> None:
    """Port Albert.exe 0x43d1f0-0x43d475 whole-board score pass."""
    batch_size, num_powers = main_score.shape
    num_provinces = fleet_adj_score.shape[2]
    tw = max(int(trial_weight), 1)
    season = str(getattr(state, 'g_season', ''))
    spring = season == 'SPR'
    supply_centres = {
        int(province) for province in getattr(state, 'sc_provinces', ())
        if 0 <= int(province) < num_provinces
    }

    for power in range(num_powers):
        for province in range(num_provinces):
            main_score[:, power] += fleet_adj_score[:, power, province]

            designation_unset = (
                int(state.g_ally_designation_a[province])
                & int(state.g_ally_designation_a_hi[province])
            ) == -1
            own_reach = int(state.g_own_reach_score[power, province])
            threat = int(state.g_threat_level[power, province])
            minimum = int(
                state.g_min_prov_score_per_power[power, province]
            )

            if own_reach > 0 and threat > 0 and designation_unset:
                main_score[:, power] += minimum

            attack_count = int(state.g_attack_count[power, province])
            if attack_count > 0 and designation_unset:
                for candidate in range(batch_size):
                    main_score[candidate, power] += _signed_int_div(
                        (tw - int(prov_move_count[candidate, province]))
                        * minimum,
                        tw,
                    )
            elif (
                int(state.g_attack_history[power, province]) > 10
                and designation_unset
                and own_reach > 0
                and threat > 0
                and (province not in supply_centres or spring)
            ):
                for candidate in range(batch_size):
                    weighted = (
                        (tw - int(prov_move_count[candidate, province]))
                        * minimum
                        * 0.75
                        / tw
                    )
                    main_score[candidate, power] = _float_to_int64(
                        float(main_score[candidate, power]) + weighted
                    )

            # Albert.exe 0x43d3df-0x43d475 calls GameBoard_GetPowerRec on
            # province_record+0x14.  That set stores static home-centre
            # powers, so the bonus is unrelated to current SC control.
            if province not in state.home_centers.get(power, frozenset()):
                continue
            designated_to_own = (
                int(state.g_ally_designation_b[province]) == int(own_power)
                and int(state.g_ally_designation_b_hi[province]) == 0
            )
            if not designated_to_own:
                continue
            for candidate in range(batch_size):
                unmoved = tw - int(prov_move_count[candidate, province])
                if spring:
                    main_score[candidate, power] += _signed_int_div(
                        unmoved * 10, tw
                    )
                elif (season == 'FAL'
                      and int(counter_b[candidate, power]) > 0):
                    weighted = _signed_int_div(
                        unmoved * int(counter_b[candidate, power]) * 20,
                        tw,
                    )
                    main_score[candidate, power] += _signed_int_div(
                        weighted, tw
                    )


def _apply_alliance_seasonal_phase(
    state: InnerGameState,
    main_score: np.ndarray,
    deduction: np.ndarray,
    hostile_pressure: np.ndarray,
    counter_a: np.ndarray,
    trial_weight: int,
) -> None:
    """Port Albert.exe 0x43d4a0-0x43d5e0 seasonal scratch scaling."""
    season = str(getattr(state, 'g_season', ''))
    if season not in ('SPR', 'FAL'):
        return
    near_end = float(state.g_near_end_game_factor)
    tw = float(max(int(trial_weight), 1))
    batch_size, num_powers = main_score.shape

    counter_factor = near_end * (100.0 if season == 'SPR' else 300.0)
    pressure_factor = near_end * (100.0 if season == 'SPR' else 10.0)
    for candidate in range(batch_size):
        for power in range(num_powers):
            counter_delta = _float_to_int64(
                int(counter_a[candidate, power]) * counter_factor / tw
            )
            main_score[candidate, power] += counter_delta
            main_score[candidate, power] = _float_to_int64(
                float(main_score[candidate, power])
                + int(hostile_pressure[candidate, power])
                * pressure_factor
                / tw
            )
            deduction_delta = _float_to_int64(
                int(deduction[candidate, power]) * pressure_factor / tw
            )
            main_score[candidate, power] += deduction_delta


def evaluate_alliance_score(
    state: InnerGameState,
    own_power: int,
    trial_weight: int = 30,
    *,
    ring_convoy_score: int | None = None,
    early_game_bonus: int | None = None,
    rank_penalty: int | None = None,
    other_score: int | None = None,
    conviction_bonus: int | None = None,
    previous_maximum_base: int = 0,
) -> int:
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
    threat_b = np.zeros(num_powers, dtype=np.float64)

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
    # Python uses the two candidate-local pressure matrices populated by
    # UpdateAllyOrderScore.  The recovered function has no static-reach
    # fallback when those matrices happen to contain all zeroes.
    # C (EvaluateAllianceScore.c:238-254) applies the near-end-game rule to each
    # INNER power's contribution individually — the <= 5.0 arm keeps a running
    # maximum over single inner values, it does not max against their sum.  It
    # also skips any inner power whose relation with outer is >= 10.
    # Corrected 2026-08-12: both the relation gate and the max-vs-sum shape.
    pressure_rows = (
        state.g_mc_province_pressure[:, :num_provinces].astype(
            np.float64, copy=False)
        + state.g_mc_fleet_pressure[:, :num_provinces].astype(
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

    # --- Phase 3a: non-SC pressure adjustment (C:264-289) ---
    # C runs this over provinces whose province-record +3 SUPPLY-CENTRE byte
    # is zero.  Unit occupancy does not participate.  It reads
    # own_power's row only, and accumulates into a single scalar.  It compares
    # threat_score[own][prov] against the MC province pressure at the same
    # slot, and gates the band on the caller's trial weight (param_2 —
    # UpdateAllyOrderScore.c:1069 passes local_b08, the per-candidate weight),
    # not on the win threshold.
    # Corrected 2026-08-12: the port iterated occupied provinces, looped every
    # power instead of own_power, compared against province_visit, and used
    # win_threshold as the band cutoff.
    supply_centres = np.zeros(num_provinces, dtype=bool)
    valid_supply_centres = [
        int(prov) for prov in state.sc_provinces
        if 0 <= int(prov) < num_provinces
    ]
    if valid_supply_centres:
        supply_centres[valid_supply_centres] = True
    own_threat = threat_score[own_power, :num_provinces]
    own_pressure = (
        state.g_mc_province_pressure[own_power, :num_provinces]
        if hasattr(state, 'g_mc_province_pressure')
        else np.zeros(num_provinces, dtype=np.float64)
    )
    eligible_non_sc = (
        (~supply_centres) & (own_threat > 0.0) & (own_pressure > 0.0)
    )
    near_band = eligible_non_sc & (
        (own_pressure - own_threat) < float(trial_weight)
    )
    strong_pressure = near_band & (own_threat * 3 < own_pressure * 2)
    weaker_pressure = near_band & ~strong_pressure & (own_threat < own_pressure)
    unequal_pressure = (
        near_band & ~strong_pressure & ~weaker_pressure
        & (own_pressure != own_threat)
    )
    far_band = eligible_non_sc & ~near_band
    non_sc_adjustment = (
        int(np.count_nonzero(strong_pressure)) * 10
        + int(np.count_nonzero(weaker_pressure)) * 5
        - int(np.count_nonzero(unequal_pressure)) * 10
        + int(np.count_nonzero(far_band)) * 20
    )

    # --- Phase 3b: supply-centre controller pressure (C:290-441) ---
    deduction, hostile_pressure = _apply_sc_controller_phase(
        state,
        main_score[None, :],
        threat_score[None, :, :],
        province_visit[None, :, :],
        prov_move_count[None, :],
        state.g_mc_province_pressure[None, :, :],
        state.g_mc_fleet_pressure[None, :, :],
        trial_weight,
    )
    _apply_controlled_sc_pressure_phase(
        state,
        main_score[None, :],
        province_visit[None, :, :],
        state.g_mc_province_pressure[None, :, :],
        trial_weight,
    )

    # --- Phase 3c: same-power token-key contribution ---
    # C:574-637 adds base_score[key,power] * live_weight / trial_weight to the
    # evaluated power before occupation/trust adjustments.  This contribution
    # was entirely absent when Python substituted static reach arrays.
    _tw_int = max(int(trial_weight), 1)
    trusted_foreign_sc = _trusted_foreign_sc_mask(
        state, num_powers, num_provinces
    )
    sc_marker = np.zeros(num_provinces, dtype=bool)
    sc_controller = np.full(num_provinces, -1, dtype=np.int16)
    for province in valid_supply_centres:
        sc_marker[province] = True
        sc_controller[province] = int(state.g_sc_owner[province])
    counter_a = np.zeros((1, num_powers), dtype=np.int64)
    counter_b = np.zeros((1, num_powers), dtype=np.int64)
    province_maximum = np.zeros(num_provinces, dtype=np.int64)
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
        positive_weights = weights > 0
        weighted_scores = base_scores * weights
        normalized_scores = _signed_divide_array(
            weighted_scores, _tw_int
        )
        main_score += np.sum(
            np.where(
                positive_weights & ~trusted_foreign_sc,
                normalized_scores,
                0,
            ),
            axis=1,
            dtype=np.int64,
        )
        for evaluated_power in range(num_powers):
            hostile_sc = (
                sc_marker
                & (sc_controller != evaluated_power)
                & ~trusted_foreign_sc[evaluated_power]
                & positive_weights[evaluated_power]
            )
            hostile_weight = int(np.sum(
                np.where(hostile_sc, weights[evaluated_power], 0),
                dtype=np.int64,
            ))
            counter_a[0, evaluated_power] += hostile_weight
            counter_b[0, evaluated_power] += hostile_weight

        # C:623-637 applies the sustained-attack premium to the same weighted
        # keys.  Batch the fixed 7x256 record pass instead of entering Python
        # once for every nonzero key.
        premium_mask = (
            (state.g_attack_history[:num_powers, :num_provinces] > 10)
            & (state.g_sc_ownership[:num_powers, :num_provinces] == 0)
            & (state.g_threat_level[:num_powers, :num_provinces] > 0)
        )
        premium = _signed_divide_array(
            _signed_divide_array(weighted_scores * 7, 20), _tw_int
        )
        main_score += np.sum(
            np.where(positive_weights & premium_mask, premium, 0),
            axis=1,
            dtype=np.int64,
        )

        # C:640-714. A positive key weight belonging to another power
        # subtracts this evaluated power's token score whenever the evaluated
        # power can reach the province. Defensive mode suppresses relations
        # >=30; outside that mode all relations take the branch.
        defensive_mode = int(
            getattr(state, 'g_other_power_lead_flag', 0)
        ) == 1
        for evaluated_power in range(num_powers):
            reachable = (
                state.g_own_reach_score[
                    evaluated_power, :num_provinces
                ] > 0
            )
            for key_power in range(num_powers):
                if key_power == evaluated_power:
                    continue
                if (defensive_mode and int(state.g_relation_score[
                        evaluated_power, key_power]) >= 30):
                    continue
                foreign_weights = weights[key_power]
                positive_foreign = foreign_weights > 0
                if not np.any(positive_foreign):
                    continue
                controlled_sc = (
                    positive_foreign & sc_marker
                    & (sc_controller == evaluated_power)
                )
                attacked_foreign_sc = (
                    positive_foreign & sc_marker
                    & (sc_controller != evaluated_power)
                    & (state.g_attack_count[
                        evaluated_power, :num_provinces
                    ] > 0)
                )
                controlled_weight = int(np.sum(
                    np.where(controlled_sc, foreign_weights, 0),
                    dtype=np.int64,
                ))
                counter_a[0, evaluated_power] -= controlled_weight
                counter_b[0, evaluated_power] -= controlled_weight
                counter_a[0, evaluated_power] -= int(np.sum(
                    np.where(attacked_foreign_sc, foreign_weights, 0),
                    dtype=np.int64,
                ))

                active = reachable & positive_foreign
                if not np.any(active):
                    continue
                deductions = _signed_divide_array(
                    base_scores[evaluated_power] * foreign_weights,
                    _tw_int,
                )
                main_score[evaluated_power] -= int(np.sum(
                    np.where(active, deductions, 0), dtype=np.int64
                ))

                if evaluated_power == own_power:
                    designation = (
                        (state.g_ally_designation_b[:num_provinces]
                         == own_power)
                        & (state.g_ally_designation_b_hi[:num_provinces]
                           == 0)
                    )
                    eligible_maximum = active & (
                        (state.g_sc_ownership[
                            own_power, :num_provinces
                        ] == 1)
                        | designation
                    )
                    if np.any(eligible_maximum):
                        maximum_values = base_scores[own_power].copy()
                        if (near_end_factor > 6.0 and int(getattr(
                                state, 'g_albert_power', own_power
                        )) != own_power):
                            maximum_values = maximum_values + np.where(
                                designation, 1000, 0
                            )
                        province_maximum = np.maximum(
                            province_maximum,
                            np.where(eligible_maximum, maximum_values, 0),
                        )

    # --- Phase 4: water-record fleet-chain scoring (C lines 748-862) ---
    # C walks every DAT_00baed7c key whose province has the water marker, then
    # follows FLT adjacency.  The adjacent lookup explicitly constructs an
    # AMY key and requires its live weight to be positive.
    local_a808 = np.zeros((num_powers, num_provinces), dtype=np.int64)
    for prov in sorted(getattr(state, 'water_provinces', ())):
        for score_table, source_weights in (
                (state.final_score_set, state.g_key_weight),
                (state.final_score_set_flt, state.g_key_weight_flt)):
            for eval_power in range(num_powers):
                source_weight = int(source_weights[eval_power, prov])
                if source_weight <= 0:
                    continue
                base_score = _signed_int_div(
                    (int(score_table[eval_power, prov]) + 50) * source_weight,
                    _tw_int,
                )
                for adj_prov in state.fleet_adj_matrix.get(prov, []):
                    adjacent_weight = int(
                        state.g_key_weight[eval_power, adj_prov]
                    )
                    if adjacent_weight <= 0:
                        continue
                    is_home_center = adj_prov in state.home_centers.get(
                        eval_power, frozenset()
                    )
                    factor = 0.05 if is_home_center else 0.1
                    cap = 10.0 if is_home_center else 20.0
                    new_val = _float_to_int64(
                        adjacent_weight * base_score * factor / _tw_int
                    )
                    if new_val > local_a808[eval_power, adj_prov]:
                        local_a808[eval_power, adj_prov] = min(new_val, cap)

    # Transfer local_a808 into fleet_adj_score (used by the whole-board pass)
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
    _tw = max(int(trial_weight), 1)
    press_flag = int(getattr(state, 'g_press_flag', 0))   # C: DAT_00baed68
    for prov, unit_data in state.unit_info.items():
        unit_power = unit_data.get('power', -1)
        unit_type = unit_data.get('type', 'A')
        if not (0 <= prov < num_provinces):
            continue
        for power in range(num_powers):
            reach_at = int(state.g_unit_province_reach[power, prov])
            moved = int(prov_move_count[prov])

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
                # EvaluateAllianceScore.c:1131-1142: on a supply centre the
                # province +0x20 controller must also be this unit's power.
                # A live unit occupying someone else's centre does not earn
                # the favourable-move bonus until winter control changes.
                if (prov in state.sc_provinces
                        and int(state.g_sc_owner[prov]) != power):
                    continue
                if int(state.g_order_table[prov, 0]) not in (2, 6):  # MTO / CTO
                    continue
                dest = int(state.g_order_table[prov, 2])
                if not (0 <= dest < num_provinces):
                    continue
                score_dest = state.fss(power, dest, unit_type)
                score_src = state.fss(power, prov, unit_type)
                if score_src * 0.85 < score_dest and press_flag == 0:
                    main_score[power] += _signed_int_div(
                        (_tw - moved) * reach_at, _tw
                    )
            else:
                # C:1172 gate — int64 g_own_reach_score at (power, prov) > 0.
                if float(state.g_own_reach_score[power, prov]) <= 0:
                    continue
                main_score[power] += reach_at
                if int(state.g_friendly_unit_flag[power, prov]) == 0:
                    d = _signed_int_div((_tw - moved) * reach_at, _tw)
                    threat_b[power]   -= d
                    main_score[power] -= d

    _apply_alliance_province_phase(
        state,
        main_score[None, :],
        fleet_adj_score[None, :, :],
        prov_move_count[None, :],
        counter_b,
        own_power,
        trial_weight,
    )
    _apply_alliance_seasonal_phase(
        state,
        main_score[None, :],
        deduction,
        hostile_pressure,
        counter_a,
        trial_weight,
    )

    # --- Phase 5: Final accumulation ---
    # EvaluateAllianceScore.c keeps ``piVar5`` pointed at
    # aiStack_10278[own_power].  That value is the function result consumed by
    # UpdateAllyOrderScore; DAT_0062db58/g_alliance_desirability is separate
    # per-opponent state.  The old port wrote only those opponent components,
    # returned None, and its caller read the deliberately untouched own-power
    # component (always zero), flattening every candidate score to zero.
    aggregate_score = float(main_score[own_power])
    # Candidate node fields restored by UpdateAllyOrderScore.c:1042-1068.
    # They are candidate-local, so production callers pass them explicitly;
    # state fallbacks preserve the focused scalar diagnostic API.
    if ring_convoy_score is None:
        ring_convoy_score = int(getattr(state, 'g_ring_convoy_score', 0))
    if early_game_bonus is None:
        early_game_bonus = int(getattr(state, 'g_early_game_bonus', 0))
    if rank_penalty is None:
        rank_penalty = int(getattr(state, 'g_support_trust_adj', 0))
    if other_score is None:
        other_score = int(getattr(state, 'g_other_score', 0))
    if conviction_bonus is None:
        conviction_bonus = int(getattr(state, 'g_conviction_bonus', 0))
    aggregate_score -= (
        int(ring_convoy_score)
        + int(early_game_bonus)
        + int(rank_penalty)
        + int(other_score) * 50
    )
    current_maximum_base = (
        int(conviction_bonus)
        + int(np.sum(province_maximum, dtype=np.int64))
    )
    maximum_base = max(int(previous_maximum_base), current_maximum_base)
    # Albert.exe 0x43d738-0x43d75d: FPU stack holds NearEndGameFactor;
    # add 3.0, multiply by the signed 64-bit running maximum, then multiply
    # by 1/16 when DAT_00baed6a is one or 1/8 otherwise before FloatToInt64.
    maximum_scale = 1.0 / (
        16.0 if int(getattr(state, 'g_leading_flag', 0)) == 1 else 8.0
    )
    aggregate_score -= _float_to_int64(
        maximum_base * (near_end_factor + 3.0) * maximum_scale
    )
    state.g_last_alliance_maximum_base = maximum_base
    if press_flag == 0:
        aggregate_score += float(non_sc_adjustment)
    for power in range(num_powers):
        if power == own_power:
            continue

        # Retrieve trust and relation scores
        trust_score = int(state.g_ally_trust_score[own_power, power]) if hasattr(state, 'g_ally_trust_score') else 0
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power]) if hasattr(state, 'g_ally_trust_score_hi') else 0
        relation_score = int(state.g_relation_score[own_power, power]) if hasattr(state, 'g_relation_score') else 0
        deceit_level = int(getattr(state, 'g_deceit_level', 0))
        influence = float(state.g_influence_matrix_b[own_power, power])

        # Final trust-weighted scoring (C lines 1068-1098)
        # Branch 1: untrusted / unknown → enemy weight
        # C: (trust==0 && trust_hi==0) || (trust==1 && trust_hi==0 && relation<0xb)
        if (trust_score == 0 and trust_hi == 0) or \
           (trust_score == 1 and trust_hi == 0 and relation_score < 11):
            # Enemy scoring: pull toward 2000 baseline
            score_adj = _float_to_int64(
                (2000.0 - main_score[power])
                * enemy_weight
                * influence
                / 10_000.0
            )
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
            score_adj = _float_to_int64(
                (main_score[power] - 2000.0)
                * effective_weight
                * influence
                / 10_000.0
            )
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
    *,
    ring_convoy_scores: np.ndarray | None = None,
    early_game_bonuses: np.ndarray | None = None,
    rank_penalties: np.ndarray | None = None,
    other_scores: np.ndarray | None = None,
    conviction_bonuses: np.ndarray | None = None,
    previous_maximum_bases: np.ndarray | None = None,
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

    supply_centres = np.zeros(num_provinces, dtype=bool)
    valid_supply_centres = [
        int(prov) for prov in state.sc_provinces
        if 0 <= int(prov) < num_provinces
    ]
    if valid_supply_centres:
        supply_centres[valid_supply_centres] = True
    own_threat = threat_score[:, own_power, :]
    own_pressure = mc_pressure_batch[:, own_power, :num_provinces]
    eligible_non_sc = (
        (~supply_centres)[None, :]
        & (own_threat > 0.0) & (own_pressure > 0.0)
    )
    near_band = eligible_non_sc & (
        (own_pressure - own_threat) < float(trial_weight)
    )
    strong_pressure = near_band & (own_threat * 3 < own_pressure * 2)
    weaker_pressure = near_band & ~strong_pressure & (own_threat < own_pressure)
    unequal_pressure = (
        near_band & ~strong_pressure & ~weaker_pressure
        & (own_pressure != own_threat)
    )
    far_band = eligible_non_sc & ~near_band
    non_sc_adjustment = (
        np.count_nonzero(strong_pressure, axis=1) * 10
        + np.count_nonzero(weaker_pressure, axis=1) * 5
        - np.count_nonzero(unequal_pressure, axis=1) * 10
        + np.count_nonzero(far_band, axis=1) * 20
    )

    deduction, hostile_pressure = _apply_sc_controller_phase(
        state,
        main_score,
        threat_score,
        key_weights,
        prov_move_count,
        mc_pressure_batch,
        mc_fleet_pressure_batch,
        trial_weight,
    )
    _apply_controlled_sc_pressure_phase(
        state,
        main_score,
        key_weights,
        mc_pressure_batch,
        trial_weight,
    )

    premium_mask = (
        (state.g_attack_history[:num_powers, :num_provinces] > 10)
        & (state.g_sc_ownership[:num_powers, :num_provinces] == 0)
        & (state.g_threat_level[:num_powers, :num_provinces] > 0)
    )
    trusted_foreign_sc = _trusted_foreign_sc_mask(
        state, num_powers, num_provinces
    )
    sc_marker = np.zeros(num_provinces, dtype=bool)
    sc_controller = np.full(num_provinces, -1, dtype=np.int16)
    for province in valid_supply_centres:
        sc_marker[province] = True
        sc_controller[province] = int(state.g_sc_owner[province])
    counter_a = np.zeros((batch_size, num_powers), dtype=np.int64)
    counter_b = np.zeros((batch_size, num_powers), dtype=np.int64)
    province_maximum = np.zeros(
        (batch_size, num_provinces), dtype=np.int64
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
        positive_weights = weights > 0
        weighted_scores = weights * base_scores[None, :, :]
        normalized_scores = _signed_divide_array(
            weighted_scores, _tw_int
        )
        main_score += np.sum(
            np.where(
                positive_weights & ~trusted_foreign_sc[None, :, :],
                normalized_scores,
                0,
            ),
            axis=2,
            dtype=np.int64,
        )
        for evaluated_power in range(num_powers):
            hostile_sc = (
                sc_marker[None, :]
                & (sc_controller != evaluated_power)[None, :]
                & ~trusted_foreign_sc[
                    evaluated_power, :num_provinces
                ][None, :]
                & positive_weights[:, evaluated_power, :]
            )
            hostile_weight = np.sum(
                np.where(
                    hostile_sc, weights[:, evaluated_power, :], 0
                ),
                axis=1,
                dtype=np.int64,
            )
            counter_a[:, evaluated_power] += hostile_weight
            counter_b[:, evaluated_power] += hostile_weight
        premium = _signed_divide_array(
            _signed_divide_array(weighted_scores * 7, 20), _tw_int
        )
        main_score += np.sum(
            np.where(
                positive_weights & premium_mask[None, :, :], premium, 0
            ),
            axis=2,
            dtype=np.int64,
        )

        defensive_mode = int(
            getattr(state, 'g_other_power_lead_flag', 0)
        ) == 1
        for evaluated_power in range(num_powers):
            reachable = (
                state.g_own_reach_score[
                    evaluated_power, :num_provinces
                ] > 0
            )
            evaluated_scores = base_scores[evaluated_power][None, :]
            for key_power in range(num_powers):
                if key_power == evaluated_power:
                    continue
                if (defensive_mode and int(state.g_relation_score[
                        evaluated_power, key_power]) >= 30):
                    continue
                foreign_weights = weights[:, key_power, :]
                positive_foreign = foreign_weights > 0
                if not np.any(positive_foreign):
                    continue
                controlled_sc = (
                    positive_foreign & sc_marker[None, :]
                    & (sc_controller == evaluated_power)[None, :]
                )
                attacked_foreign_sc = (
                    positive_foreign & sc_marker[None, :]
                    & (sc_controller != evaluated_power)[None, :]
                    & (state.g_attack_count[
                        evaluated_power, :num_provinces
                    ] > 0)[None, :]
                )
                controlled_weight = np.sum(
                    np.where(controlled_sc, foreign_weights, 0),
                    axis=1,
                    dtype=np.int64,
                )
                counter_a[:, evaluated_power] -= controlled_weight
                counter_b[:, evaluated_power] -= controlled_weight
                counter_a[:, evaluated_power] -= np.sum(
                    np.where(attacked_foreign_sc, foreign_weights, 0),
                    axis=1,
                    dtype=np.int64,
                )

                active = reachable[None, :] & positive_foreign
                if not np.any(active):
                    continue
                deductions = _signed_divide_array(
                    evaluated_scores * foreign_weights, _tw_int
                )
                main_score[:, evaluated_power] -= np.sum(
                    np.where(active, deductions, 0),
                    axis=1,
                    dtype=np.int64,
                )

                if evaluated_power == own_power:
                    designation = (
                        (state.g_ally_designation_b[:num_provinces]
                         == own_power)
                        & (state.g_ally_designation_b_hi[:num_provinces]
                           == 0)
                    )
                    eligible_maximum = active & (
                        (state.g_sc_ownership[
                            own_power, :num_provinces
                        ] == 1)[None, :]
                        | designation[None, :]
                    )
                    if np.any(eligible_maximum):
                        maximum_values = base_scores[own_power].copy()
                        if (near_end_factor > 6.0 and int(getattr(
                                state, 'g_albert_power', own_power
                        )) != own_power):
                            maximum_values = maximum_values + np.where(
                                designation, 1000, 0
                            )
                        province_maximum = np.maximum(
                            province_maximum,
                            np.where(
                                eligible_maximum,
                                maximum_values[None, :],
                                0,
                            ),
                        )

    local_a808 = np.zeros(
        (batch_size, num_powers, num_provinces), dtype=np.int64
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
                base_score = _signed_divide_array(
                    (int(score_table[eval_power, prov]) + 50) * source_weight,
                    _tw_int,
                )
                for adj_prov in state.fleet_adj_matrix.get(prov, []):
                    adjacent_weight = key_weight_batch[
                        :, eval_power, adj_prov
                    ].astype(np.int64, copy=False)
                    active = source_active & (adjacent_weight > 0)
                    if not np.any(active):
                        continue
                    is_home_center = adj_prov in state.home_centers.get(
                        eval_power, frozenset()
                    )
                    factor = 0.05 if is_home_center else 0.1
                    cap = 10.0 if is_home_center else 20.0
                    new_value = np.trunc(
                        adjacent_weight * base_score * factor / _tw_int
                    ).astype(np.int64)
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
            reach_at = int(state.g_unit_province_reach[power, prov])
            if unit_power == power:
                if float(state.g_enemy_reach_score[power, prov]) <= 0:
                    continue
                main_score[:, power] -= reach_at
                if (prov in state.sc_provinces
                        and int(state.g_sc_owner[prov]) != power):
                    continue
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
                bonuses = _signed_divide_array(
                    (_tw_int - moved.astype(np.int64, copy=False)) * reach_at,
                    _tw_int,
                )
                main_score[rewarded, power] += bonuses[rewarded]
            else:
                if float(state.g_own_reach_score[power, prov]) <= 0:
                    continue
                main_score[:, power] += reach_at
                if int(state.g_friendly_unit_flag[power, prov]) == 0:
                    delta = _signed_divide_array(
                        (_tw_int - moved.astype(np.int64, copy=False))
                        * reach_at,
                        _tw_int,
                    )
                    main_score[:, power] -= delta

    _apply_alliance_province_phase(
        state,
        main_score,
        local_a808,
        prov_move_count,
        counter_b,
        own_power,
        trial_weight,
    )
    _apply_alliance_seasonal_phase(
        state,
        main_score,
        deduction,
        hostile_pressure,
        counter_a,
        trial_weight,
    )

    aggregate_score = main_score[:, own_power].copy()
    def _candidate_vector(
        values: np.ndarray | None, fallback: int
    ) -> np.ndarray:
        if values is None:
            return np.full(batch_size, fallback, dtype=np.int64)
        result = np.asarray(values, dtype=np.int64)
        if result.shape != (batch_size,):
            raise ValueError(
                f"candidate field must have shape ({batch_size},), "
                f"got {result.shape}"
            )
        return result

    aggregate_score -= _candidate_vector(
        ring_convoy_scores, int(getattr(state, 'g_ring_convoy_score', 0))
    )
    aggregate_score -= _candidate_vector(
        early_game_bonuses, int(getattr(state, 'g_early_game_bonus', 0))
    )
    aggregate_score -= _candidate_vector(
        rank_penalties, int(getattr(state, 'g_support_trust_adj', 0))
    )
    aggregate_score -= _candidate_vector(
        other_scores, int(getattr(state, 'g_other_score', 0))
    ) * 50
    current_maximum_bases = _candidate_vector(
        conviction_bonuses, int(getattr(state, 'g_conviction_bonus', 0))
    ) + np.sum(province_maximum, axis=1, dtype=np.int64)
    maximum_bases = np.maximum(
        _candidate_vector(previous_maximum_bases, 0),
        current_maximum_bases,
    )
    maximum_scale = 1.0 / (
        16.0 if int(getattr(state, 'g_leading_flag', 0)) == 1 else 8.0
    )
    aggregate_score -= np.trunc(
        maximum_bases.astype(np.float64)
        * (near_end_factor + 3.0)
        * maximum_scale
    ).astype(np.int64)
    state.g_last_alliance_maximum_bases = maximum_bases.copy()
    if press_flag == 0:
        aggregate_score += non_sc_adjustment
    desirability = np.zeros((batch_size, num_powers), dtype=np.float64)
    deceit_level = int(getattr(state, 'g_deceit_level', 0))
    best_ally = int(getattr(state, 'g_best_ally_slot0', -1))
    albert_power = int(getattr(state, 'albert_power_idx', -1))
    for power in range(num_powers):
        if power == own_power:
            continue
        trust_score = int(state.g_ally_trust_score[own_power, power])
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power])
        relation_score = int(state.g_relation_score[own_power, power])
        influence = float(state.g_influence_matrix_b[own_power, power])
        if ((trust_score == 0 and trust_hi == 0)
                or (trust_score == 1 and trust_hi == 0
                    and relation_score < 11)):
            score_adj = np.trunc(
                (2000.0 - main_score[:, power])
                * enemy_weight
                * influence
                / 10_000.0
            )
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
            score_adj = np.trunc(
                (main_score[:, power] - 2000.0)
                * effective_weight
                * influence
                / 10_000.0
            )
            aggregate_score = score_adj
        else:
            score_adj = np.zeros(batch_size, dtype=np.float64)
        desirability[:, power] = score_adj

    state.g_alliance_desirability[:] = desirability[-1]
    return aggregate_score.astype(np.int64)
