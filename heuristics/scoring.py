"""Candidate scoring and province evaluation pipeline.

Split from heuristics.py during the 2026-04 refactor.

- ``score_order_candidates_all_powers`` — ScoreOrderCandidates outer loop
- ``score_provinces``                   — ScoreProvinces (strategy-wide province scoring)
- ``apply_press_corroboration_penalty`` — per-candidate penalty based on press corroboration
- ``score_order_candidates_own_power``  — inner loop specialised for own power

Module-level deps: ``numpy``, ``..state.InnerGameState``,
``._primitives.evaluate_province_score``.  Owns the module-level constant
``_PRESS_DISAGREE_PENALTY`` consumed by ``apply_press_corroboration_penalty``.
"""

import numpy as np

from ..state import InnerGameState

from ._primitives import (
    compute_winter_builds,
    evaluate_province_score,
    _float_to_int64,
    _signed_int_div,
)

# M2: ScoreProvinces normalization exponent — the C binary's _safe_pow call
# uses an FPU-stack argument not recoverable from Ghidra decompile.
# Default 0.5 (sqrt); empirical sweep shows no measurable effect while PRNG
# divergence dominates.  Will become relevant once PRNG is aligned.
# Sweep [0.3, 1.0] after PRNG fix for final calibration.
# ScoreOrderCandidates_AllPowers sub-threshold formula (recovered from binary):
#   score = sqrt(raw / threshold) * 10 + 1
# DAT_004afd88 = 0.5 (exponent), PTR_004afd70 = 10.0 (scale), DAT_004afa28 = 1.0 (offset)
# Denominator is threshold = global_max/100 (local_98 in decompile), NOT g_min_score.
_SCORE_NORM_EXPONENT = 0.5
_SCORE_NORM_SCALE    = 10.0
_SCORE_NORM_OFFSET   = 1.0


def _seed_and_fold_coasts(state, bfs, power: int, rnd: int) -> None:
    """Reconcile the fleet BFS with C's (province, TOKEN) key model.

    ``ScoreProvinces.c:489-506`` seeds round 0 by walking each province's key
    list and writing ``g_AttackCount[province] * build_weight`` into EVERY key
    at that province.  A coastal supply centre such as SPA therefore carries
    one FLT key per coast — ``(SPA, FLT/NCS)`` and ``(SPA, FLT/SCS)`` — and
    both are seeded with SPA's supply-centre score.  There is no plain-FLT key
    at a multi-coast province: ``AdjacencyList_FilterByUnitType`` resolves a
    fleet's adjacency to the coast tokens.  When the propagation loop
    (``ScoreProvinces.c:537-631``) then walks a neighbour's adjacency and hits
    the same province twice under two coast tokens, ``local_5580`` keeps the
    LARGER of the two values (C:1560-1584).

    The port keys its arrays by province id alone, modelling the coast tokens
    as separate ids.  That left the coast ids seeded at 0 and unreachable —
    nothing in ``fleet_adj_matrix`` points at them — while the base id held a
    fleet node with an EMPTY fleet adjacency, so ``final_score_set_flt`` for
    SPA, BUL and STP decayed to noise.  Those are the three coastal supply
    centres a fleet can only enter through a coast, and their destination
    scores were being read off that dead node.

    This restores both halves of C's behaviour, once per BFS round:
      * every coast id inherits its base province's value (round 0: the seed);
      * the base id becomes the MAX over its coast tokens, which is what a
        neighbour's deduplicated adjacency walk sees and what ``fss()`` must
        return for "fleet moves into this province".
    """
    variants = getattr(state, 'coast_variants', None)
    if not variants:
        return
    row = bfs[power, rnd]
    if rnd == 0:
        for base, coasts in variants.items():
            for coast in coasts:
                row[coast] = row[base]
    for base, coasts in variants.items():
        row[base] = max(row[coast] for coast in coasts)


def _populate_threat_path_scores(state: InnerGameState) -> None:
    """Port ScoreOrderCandidates_AllPowers.c Phase 11 (lines 846-952)."""
    threat = state.g_threat_path_score
    for power in range(7):
        for province in getattr(state, 'valid_provinces', range(256)):
            if province not in state.sc_provinces:
                continue
            if state.g_own_reach_score[power, province] <= 0:
                continue
            if int(state.g_sc_owner[province]) == power:
                continue
            for adj in state.get_adjacent_provinces(province):
                if int(state.g_sc_ownership[power, adj]) <= 0:
                    continue
                if adj in state.sc_provinces:
                    if int(state.g_sc_owner[adj]) != power:
                        continue
                # The C inner loop has no iteration when this province has no
                # adjacency token records.
                if not state.get_adjacent_provinces(adj):
                    continue
                score = state.g_max_prov_score_per_power[power, adj]
                if score > threat[power, province]:
                    threat[power, province] = score


def _apply_enemy_sc_flank_denial(state: InnerGameState) -> None:
    """Port ScoreOrderCandidates_AllPowers.c:317-407's two-hop pass."""
    for power in range(7):
        for unit_prov in state.get_power_units(power):
            unit = state.unit_info.get(unit_prov, {})
            unit_type = unit.get('type', 'A')
            unit_coast = unit.get('coast', '')
            for adjacent, edge_type, edge_coast in state.get_reachable_edges(
                unit_prov, unit_type, unit_coast,
            ):
                for second, _second_type, _second_coast in state.get_reachable_edges(
                    adjacent, edge_type, edge_coast,
                ):
                    if second not in state.sc_provinces:
                        continue
                    controller = int(state.g_sc_owner[second])
                    if (not 0 <= controller < 7
                            or controller == power
                            or int(state.g_relation_score[power, controller]) >= 10):
                        continue
                    if (state.g_prov_target_flag[power, adjacent] == 1
                            and state.g_target_flag2[power, adjacent] == 0):
                        state.g_prov_target_flag[power, adjacent] = -10
                        state.g_target_flag2[power, adjacent] = -1


def _cleanup_sc_designations(state: InnerGameState) -> None:
    """Port ScoreProvinces.c:1743-1792's controller-indexed cleanup."""
    near_end = float(getattr(state, 'g_near_end_game_factor', 0.0))
    for province in state.sc_provinces:
        province = int(province)
        if not 0 <= province < 256:
            continue
        controller = int(state.g_sc_owner[province])
        if not 0 <= controller < 7:
            # C has a wider token-indexed table including UNO; the Python
            # scoring arrays intentionally contain only the seven powers.
            continue

        b_hi = int(state.g_ally_designation_b_hi[province])
        a_hi = int(state.g_ally_designation_a_hi[province])
        if (b_hi >= 0 and a_hi >= 0
                and (int(state.g_ally_designation_b[province])
                     != int(state.g_ally_designation_a[province])
                     or b_hi != a_hi)
                and int(state.g_own_reach_score[controller, province]) == 0):
            state.g_ally_designation_b[province] = -1
            state.g_ally_designation_b_hi[province] = -1

        if (near_end > 5.0
                and int(state.g_own_reach_score[controller, province]) == 0
                and int(state.g_enemy_reach_score[controller, province]) > 0):
            state.g_ally_designation_b[province] = -2
            state.g_ally_designation_b_hi[province] = -1
            state.g_spr_desig_b[province] = -2
            state.g_spr_desig_b_hi[province] = -1


def score_order_candidates_all_powers(state: InnerGameState, round_weights: list, dominant_power_idx: int):
    """
    Port of ScoreOrderCandidates_AllPowers / FUN_0044a040.
    Per-power per-province influence dot-product scoring pass.
    """
    # C lines 67-69: 64-bit subtraction with borrow correction.
    #   local_80 = FAL_lo − SPR_lo  (uint32)
    #   local_7c = (FAL_hi − SPR_hi) − borrow  (uint32), borrow = 1 if FAL_lo < SPR_lo
    #   dominance_weight = (local_7c << 32) | local_80  (uint64)
    _fal0 = state.g_fal_round_weights[0]
    _spr0 = state.g_spr_round_weights[0]
    _fal_lo, _fal_hi = _fal0 & 0xFFFFFFFF, (_fal0 >> 32) & 0xFFFFFFFF
    _spr_lo, _spr_hi = _spr0 & 0xFFFFFFFF, (_spr0 >> 32) & 0xFFFFFFFF
    _borrow = 1 if _fal_lo < _spr_lo else 0
    dominance_weight = (((_fal_hi - _spr_hi - _borrow) & 0xFFFFFFFF) << 32) | ((_fal_lo - _spr_lo) & 0xFFFFFFFF)

    # C's trees are keyed by (province, unit/coast token).  The Python state
    # represents the two material movement channels separately: the existing
    # array is AMY-space and ``final_score_set_flt`` is fleet-space.
    state.final_score_set.fill(0)
    state.final_score_set_flt.fill(0)

    _fb = getattr(state, '_bfs_flt', None)
    if _fb is None:
        _fb = state.g_candidate_bfs

    valid = sorted(getattr(state, 'valid_provinces', None) or range(256))
    water = set(getattr(state, 'water_provinces', ()))
    land_only = set(getattr(state, 'land_provinces', ()))
    coast_variants = {
        coast
        for coasts in getattr(state, 'coast_variants', {}).values()
        for coast in coasts
    }
    multi_coast_bases = set(getattr(state, 'coast_variants', {}))
    army_domain = [
        province for province in valid
        if province not in water and province not in coast_variants
    ]
    fleet_domain = [
        province for province in valid
        if province not in land_only and province not in multi_coast_bases
    ]
    channels = (
        (state.g_candidate_bfs, state.final_score_set, army_domain),
        (_fb, state.final_score_set_flt, fleet_domain),
    )
    war_mode = int(getattr(state, 'g_war_mode_flag',
                   getattr(state, 'g_dominant_power_mode', 0)))
    n_rounds = min(10, len(round_weights))

    # C normalises each power's complete key tree as one population.  Army and
    # fleet keys at the same province therefore share the same max/min and the
    # same threshold; normalising the channels independently is observably
    # different and contradicts the single +0x4000 tree in the C object.
    for power in range(7):
        keyed_raw = []
        max_raw = 1                 # local_a8 initialiser
        min_raw = 100_000_000_000_000_000  # local_b0 initialiser
        for bfs, output, domain in channels:
            for province in domain:
                raw = sum(
                    int(bfs[power, rnd, province]) * int(round_weights[rnd])
                    for rnd in range(n_rounds)
                )
                if war_mode == 1 and power != dominant_power_idx:
                    raw += int(bfs[power, 0, province]) * dominance_weight
                keyed_raw.append((output, province, raw))
                max_raw = max(max_raw, raw)
                min_raw = min(min_raw, raw)

        # All of these values are signed int64 pairs in C.  In particular,
        # both normalization divisions truncate and the low-score floating
        # branch is packed back to int64 before it is stored in the tree.
        if min_raw == 0:
            min_raw = 1
        threshold = _signed_int_div(max_raw, 100)
        if min_raw == threshold:
            threshold = min_raw + 1

        for output, province, raw in keyed_raw:
            if raw >= threshold:
                normalized = _signed_int_div(raw * 1000, max_raw) + 15
            elif raw == 0 or raw == min_raw:
                normalized = 1
            else:
                ratio = max(raw / max(threshold, 1), 0.0)
                normalized = _float_to_int64(
                    pow(ratio, _SCORE_NORM_EXPONENT) * _SCORE_NORM_SCALE
                    + _SCORE_NORM_OFFSET
                )
                normalized = min(normalized, 10)
            output[power, province] = normalized
            state.g_max_prov_score_per_power[power, province] = max(
                state.g_max_prov_score_per_power[power, province], normalized
            )
            state.g_min_prov_score_per_power[power, province] = min(
                state.g_min_prov_score_per_power[power, province], normalized
            )

        # C has one FLT key per legal coast and no additional plain-FLT key at
        # a multi-coast province. Python stores those coast keys at variant
        # ids; fold their normalized maximum back to the base id used by move
        # and support consumers, then share it with the base AMY maximum.
        for base, coasts in getattr(state, 'coast_variants', {}).items():
            fleet_score = max(
                int(state.final_score_set_flt[power, coast])
                for coast in coasts
            )
            state.final_score_set_flt[power, base] = fleet_score
            state.g_max_prov_score_per_power[power, base] = max(
                state.g_max_prov_score_per_power[power, base], fleet_score
            )
            state.g_min_prov_score_per_power[power, base] = min(
                state.g_min_prov_score_per_power[power, base], fleet_score
            )

        # Phase 1c applies to every AMY key, not merely provinces currently
        # occupied by an army.  It pulls that key down to the difference from
        # the best token-specific value at the same province.
        for province in army_domain:
            army_score = int(state.final_score_set[power, province])
            province_max = int(state.g_max_prov_score_per_power[power, province])
            if army_score < province_max:
                state.final_score_set[power, province] = province_max - army_score

    # This 1-D compatibility view has no separate C storage; retain it as the
    # cross-power/key maximum expected by the existing support helpers.
    state.g_max_province_score[:] = np.maximum(
        state.final_score_set.max(axis=0),
        state.final_score_set_flt.max(axis=0),
    )
    state.g_min_score[:] = np.minimum(
        state.final_score_set.min(axis=0),
        state.final_score_set_flt.min(axis=0),
    )

    # Pass 4 - g_prov_target_flag classification (C Phase 3, lines 265-316).
    # C walks every real province. Non-SCs are always eligible; SCs are
    # eligible only for their board controller. DAT_0058f8e8/ec is own reach,
    # not enemy reach, and DAT_0052b4e8/ec is the combined total-reach value.
    for power in range(7):
        for province in getattr(state, 'valid_provinces', range(256)):
            if (province in state.sc_provinces
                    and int(state.g_sc_owner[province]) != power):
                continue
            # Signed pair tests from C:265-272.
            attack_cnt_val = int(state.g_attack_count[power, province])
            tflag = int(state.g_target_flag[power, province])
            ac2_val = int(state.g_attack_count2[power, province])
            if not (attack_cnt_val < 1 and (tflag != 2 or ac2_val != 0)):
                continue

            own_reach = int(state.g_own_reach_score[power, province])
            unit_presence = int(state.g_sc_ownership[power, province])
            total_reach = int(state.g_total_reach_score[power, province])
            enemy_reach = int(state.g_enemy_reach_score[power, province])

            target_class = 0
            if (own_reach <= 0
                    or unit_presence != 0
                    or total_reach != 0):
                if own_reach == 1 and unit_presence == 1 and enemy_reach == 0:
                    target_class = 1
                elif (own_reach > 0
                      and unit_presence == 1
                      and enemy_reach == 0):
                    target_class = 2
            else:
                # Positive own reach into an empty province with no reach from
                # another power takes the simple class-1 path at C:307.
                target_class = 1

            if target_class == 0:
                continue
            state.g_prov_target_flag[power, province] = target_class
            state.g_target_flag2[power, province] = 0

    # Pass 5 - Enemy-SC adjacency denial (C Phase 4, lines 317-407).
    _apply_enemy_sc_flank_denial(state)

    # Pass 6 - Multi-flanked restoration (C Phase 5, lines 408-480)
    # If a province has >1 neighbor also flagged -10, the local front is
    # contested everywhere — lift the flag back to 1.
    for power in range(7):
        for province in range(256):
            if state.g_prov_target_flag[power, province] != -10:
                continue
            flanked_neighbors = 0
            for adj in (state.get_adjacent_provinces(province)
                        if hasattr(state, 'get_adjacent_provinces') else []):
                if state.g_prov_target_flag[power, adj] == -10:
                    flanked_neighbors += 1
            if flanked_neighbors > 1:
                state.g_prov_target_flag[power, province] = 1
                if hasattr(state, 'g_target_flag2'):
                    state.g_target_flag2[power, province] = 0

    # Pass 7 - convoy/support reach (C Phase 10, lines 682-845).
    # DAT_005c48e8/ec and DAT_005ba0e8/ec are each one signed int64. The old
    # port split their high words into phantom direct/extended arrays and then
    # performed a generic graph flood through empty provinces. C instead
    # revisits the current unit list on every one of its three expansion rounds.
    for power in range(7):
        power_units = state.get_power_units(power)
        for unit_prov in power_units:
            unit = state.unit_info.get(unit_prov, {})
            unit_type = unit.get('type', 'A')
            unit_coast = unit.get('coast', '')
            for first, edge_type, edge_coast in state.get_reachable_edges(
                unit_prov, unit_type, unit_coast,
            ):
                state.g_convoy_reach[power, first] = 1

                # The second filtered adjacency keeps the unit token carried
                # by the first edge, including a split-coast destination.
                for second, _second_type, _second_coast in state.get_reachable_edges(
                    first, edge_type, edge_coast,
                ):
                    if second not in state.sc_provinces:
                        continue
                    state.g_support_reach[power, second] = 1
                    # C uses the province's unfiltered +0x2a1c adjacency set
                    # for this final neighbour expansion.
                    for neighbour in state.get_adjacent_provinces(second):
                        state.g_support_reach[power, neighbour] = 1

        # Three passes, each anchored to an actual unit belonging to power.
        # Reached empty provinces never become graph frontiers in C.
        for _ in range(3):
            for unit_prov in power_units:
                if state.g_convoy_reach[power, unit_prov] != 1:
                    continue
                unit = state.unit_info.get(unit_prov, {})
                unit_type = unit.get('type', 'A')
                unit_coast = unit.get('coast', '')
                for adjacent in state.get_unit_adjacencies(unit_prov):
                    if state.can_reach_by_type(
                        unit_prov, adjacent, unit_type, unit_coast
                    ):
                        state.g_convoy_reach[power, adjacent] = 1

    # Passes 8-9 - DAT_005b98e8/ec sentinel transition (C:481-589).
    # GenerateOrders seeded one shared province table with -1.  The first unit
    # walk clears under-performing occupied provinces to 0; the second can
    # promote only those zero entries to 1.  The old port split the semantic
    # names g_needs_rescore and g_top_reach_flag into separate arrays, making
    # the latter start at 0 everywhere and opening the support gate globally.
    for power in range(7):
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            unit_type = state.unit_info.get(unit_prov, {}).get('type', 'A')
            fs_val = state.fss(power, unit_prov, unit_type)
            mx_val = float(state.g_max_prov_score_per_power[power, unit_prov])
            if fs_val < mx_val:
                state.g_needs_rescore[unit_prov] = 0

    for power in range(7):
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            unit = state.unit_info.get(unit_prov, {})
            unit_type = unit.get('type', 'A')
            unit_coast = unit.get('coast', '')
            for q in state.get_unit_adjacencies(unit_prov):
                if not state.can_reach_by_type(
                        unit_prov, q, unit_type, unit_coast):
                    continue
                if int(state.g_needs_rescore[q]) != 0:
                    continue
                if int(state.g_sc_ownership[power, q]) != 1:
                    continue
                fs_q = state.fss(power, q, unit_type)
                mx_q = float(state.g_max_prov_score_per_power[power, q])
                if fs_q == mx_q:
                    state.g_needs_rescore[q] = 1

    # Pass 10 - BuildSupportOpportunities call (C Phase 8, line 590)
    try:
        from ..moves import build_support_opportunities
    except ImportError:
        pass
    else:
        build_support_opportunities(state)

    # Pass 11 - g_support_candidate_mark via enemy-reachable ally-designated
    # adjacencies (C ScoreOrderCandidates_AllPowers, lines ~631-674).
    sup_mark = getattr(state, 'g_support_candidate_mark', None)
    ally_a_hi = getattr(state, 'g_ally_designation_a_hi', None)
    ally_a = getattr(state, 'g_ally_designation_a', None)
    if sup_mark is not None and ally_a_hi is not None and ally_a is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    # C: guard is DAT_004d2e14[adj*2] >= 0 (g_ally_designation_a_hi)
                    if ally_a_hi[adj1] < 0:
                        continue
                    # C: skip when g_AllyDesignation_A[adj]==power AND hi==0
                    # (64-bit match against {hi=0, lo=power}; hi = power>>31 = 0)
                    if ally_a[adj1] == power and ally_a_hi[adj1] == 0:
                        continue
                    if state.g_enemy_reach_score[power, adj1] <= 0:
                        continue
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        sup_mark[power, adj2] = 1

    # Pass 12 - g_threat_path_score (C Phase 11, lines 846-952)
    # C's province byte +3 gate is the supply-centre flag, not occupancy.  For
    # each threatened SC (not own-controlled and own-reach > 0), scan adjacent
    # reachable provinces. An adjacent SC is usable only when controlled by the
    # evaluated power; non-SCs have no controller gate. C then walks all
    # adjacency token keys for that province and retains their greatest score,
    # which is the shared per-power/province maximum in the split Python model.
    _populate_threat_path_scores(state)


# ── ScoreProvinces ────────────────────────────────────────────────────────────

def score_provinces(state: InnerGameState,
                    move_weight: float,
                    build_weight: float,
                    own_power: int) -> None:
    """
    Port of ScoreProvinces (FUN_00447460).

    Per-trial Monte Carlo scoring kernel.  Iterates all powers, builds a
    reachability matrix from the unit list, applies trust-gated scoring, and
    fills the per-power candidate ordered sets used by order selection.

    Parameters mirror the C signature:
        (Albert *this, uint64 move_weight, uint64 build_weight)

    Research.md §2597.
    """
    num_powers = 7
    num_provinces = 256
    # C has an explicit board province count. Python arrays are fixed at 256,
    # so use adjacency keys to avoid scoring non-existent array slots.
    valid_provs = getattr(state, 'valid_provinces', None)

    # Section 1 — zero 11 per-power-province tables
    state.g_own_reach_score.fill(0)       # g_own_reach_score   DAT_0058f8e8
    state.g_ally_reach_score.fill(0)      # g_ally_reach_score  DAT_005658e8
    state.g_enemy_reach_score.fill(0)     # g_enemy_reach_score DAT_00535ce8
    state.g_total_reach_score.fill(0)     # g_total_reach_score DAT_0052b4e8
    # C zeroes DAT_005460e8/ec (ScoreProvinces.c:197).  This used to fill -1,
    # attributing the sentinel from ScoreProvinces.c:162 — but that line
    # initialises the pair-indexed region of g_ThreatScore (bound here as
    # g_coverage_flag), a different array.  The -1 made every "no threat"
    # province read as -1, inverting the `threat == 0` gates in
    # moves/support.py's two SUP builders.
    state.g_threat_level.fill(0)         # g_threat_level     DAT_005460e8
    state.g_convoy_reach_count.fill(0)    # g_convoy_reach_count DAT_005850e8
    state.g_enemy_mobility_count.fill(0)  # g_enemy_mobility_count DAT_0057a8e8
    state.g_sc_ownership.fill(0)         # g_sc_ownership     DAT_00520ce8
    state.g_coverage_flag.fill(0)        # g_coverage_flag
    state.g_province_weight.fill(0)      # g_province_weight  DAT_00540ce8
    state.g_max_province_score.fill(0)
    state.g_min_score.fill(1_000_000)    # g_min_score sentinel
    state.g_province_base.fill(0)        # g_ProvinceBase
    # C zeroes g_MaxProvinceScore (DAT_0055b0e8/ec) and seeds the paired min
    # (DAT_005508e8) with 1000000 on every call — ScoreProvinces.c:125,126.
    # These were left at their construction-time ±2^62 sentinels, which leaks
    # into every consumer of the per-power maxima.
    state.g_max_prov_score_per_power.fill(0)
    state.g_min_prov_score_per_power.fill(1_000_000)
    # C's first reset block (ScoreProvinces.c:118-137) also clears these four
    # every call.  Nothing in the port reset them, so they accumulated for the
    # whole game — most visibly g_enemy_presence, which never went back to 0
    # once any enemy unit had touched a province.
    state.g_attack_count.fill(0)         # g_attack_count      DAT_006040e8
    state.g_enemy_presence.fill(0)       # g_enemy_presence    DAT_004f6ce8
    state.g_build_order_pending.fill(0)  # g_build_order_pending DAT_006190e8
    state.g_threat_path_score.fill(0)    # g_threat_path_score DAT_005700e8

    # Friendly/unit-presence flags.
    # g_friendly_unit_flag and g_established_ally_flag are *persisted* to state
    # (ScoreProvinces.c:813-826, DAT_005164e8 / DAT_0050bce8) because
    # heuristics/_primitives.py:compute_winter_builds consumes them via
    # `state.g_friendly_unit_flag[own_power, target]` / `state.g_established_ally_flag[own_power, target]`.
    # The C code indexes them as [outer_power * 0x100 + prov], making them 2D.
    # Updated 2026-04-21: now populated per outer_power inside Section 4 loop.
    # Reset each trial; re-filled below.
    state.g_friendly_unit_flag.fill(0)
    state.g_established_ally_flag.fill(0)
    # (A local g_unit_presence array used to be allocated here with a comment
    # claiming Section 4g consumed it.  Section 4g reads g_own_reach_score --
    # ScoreProvinces.c:678 gates on DAT_0058f8e8/ec -- and never touched it.)

    # Section 2 — build reachability matrix from unit list
    # reachability[province][power] = units of power that can reach province
    reachability = np.zeros((num_provinces, num_powers), dtype=np.int32)

    for prov, info in state.unit_info.items():
        power = info['power']
        unit_type = str(info.get('type', 'A')).upper()
        unit_coast = str(info.get('coast', '') or '')
        # C:230 calls AdjacencyList_FilterByUnitType with the live unit's
        # complete token.  This matrix feeds own/enemy reach, threats, and
        # nearly every downstream province score, so base-province adjacency
        # is not an acceptable substitute for armies, fleets, or split coasts.
        adj = [
            candidate for candidate in state.get_unit_adjacencies(prov)
            if state.can_reach_by_type(
                prov, candidate, unit_type, unit_coast,
            )
        ]
        seen = set()
        for a in adj:
            if a not in seen:
                reachability[a, power] += 1
                state.g_coverage_flag[power, a] += 1
                seen.add(a)
        reachability[prov, power] += 1
        state.g_coverage_flag[power, prov] += 1
        # C:293 — g_ProximityScore[unit.power][unit.prov] = 0 once per unit,
        # per call.  Omitting it let the counter grow without bound, since
        # moves/support.py and BuildOrder_SUP_MTO only ever add to it.
        state.g_proximity_score[power, prov] = 0

    # Section 3 — per-unit presence flags.
    #
    # g_sc_ownership fix 2026-04-14: C populates g_sc_ownership[unit.power, prov]
    # for every unit across all powers (ScoreProvinces.c:781-787, inside the
    # outer-power loop, each iteration only writes its own power's row but
    # over the full outer-loop sweep every power gets its units marked).
    # The previous port only set own_power's row, leaving other powers' rows
    # at zero after Section 1's fill(0).  This broke any consumer that reads
    # `np.sum(g_sc_ownership[p])` for p != own_power — most visibly
    # Adjustment 8's owner_scs check and any SC-count-based heuristic.
    for prov, info in state.unit_info.items():
        power = info['power']
        state.g_sc_ownership[power, prov] = 1

    # Section 4 — per-power outer loop: alliance-gated reach → scored tables
    # C: ScoreProvinces.c:302-432.  Loop nesting matches the decompile —
    # local_559c = outer_power, local_5598 = prov, local_557c = inner_power.
    press_flag = int(getattr(state, 'g_press_flag', 0))
    near_end   = float(getattr(state, 'g_near_end_game_factor', 0.0))

    for outer_power in range(num_powers):
        for prov in range(num_provinces):
            # ── Designation-derived trust (C:314-355) ─────────────────────
            # Each province carries three ally-designation slots.  The trust
            # used by the own-reach gate below is taken from the LAST slot
            # whose hi word is non-negative, evaluated c → b → a, so slot a
            # wins when present.  This is trust(outer_power, designee) — NOT
            # the trust-matrix diagonal the port previously used.
            desig_trust_lo = 0.0
            desig_trust_hi = 0
            d_c = int(state.g_ally_designation_c[prov])
            d_b = int(state.g_ally_designation_b[prov])
            d_a = int(state.g_ally_designation_a[prov])
            c_hi = int(state.g_ally_designation_c_hi[prov])
            b_hi = int(state.g_ally_designation_b_hi[prov])
            a_hi = int(state.g_ally_designation_a_hi[prov])
            if c_hi >= 0 and 0 <= d_c < num_powers:
                desig_trust_lo = float(state.g_ally_trust_score[outer_power, d_c])
                desig_trust_hi = int(state.g_ally_trust_score_hi[outer_power, d_c])
            if b_hi >= 0 and 0 <= d_b < num_powers:
                desig_trust_lo = float(state.g_ally_trust_score[outer_power, d_b])
                desig_trust_hi = int(state.g_ally_trust_score_hi[outer_power, d_b])
            if a_hi >= 0 and 0 <= d_a < num_powers:
                desig_trust_lo = float(state.g_ally_trust_score[outer_power, d_a])
                desig_trust_hi = int(state.g_ally_trust_score_hi[outer_power, d_a])

            # outer_power itself designated as this province's ally?
            is_ally_desig = (
                (d_a == outer_power and a_hi == 0)
                or (d_b == outer_power and b_hi == 0)
                or (d_c == outer_power and c_hi == 0)
            )

            # Early-game press suppression (C:342-355): with press on and
            # near_end_game < 2.0, slot B's designation trust survives only
            # if outer and the designee trust each other mutually (both > 1).
            if press_flag == 1 and near_end < 2.0 and b_hi >= 0 and 0 <= d_b < num_powers:
                fwd_lo = float(state.g_ally_trust_score[outer_power, d_b])
                fwd_hi = int(state.g_ally_trust_score_hi[outer_power, d_b])
                rev_lo = float(state.g_ally_trust_score[d_b, outer_power])
                rev_hi = int(state.g_ally_trust_score_hi[d_b, outer_power])
                mutual = (
                    (fwd_hi >= 0 and (fwd_hi > 0 or fwd_lo > 1))
                    and (rev_hi > 0 or (rev_hi >= 0 and rev_lo > 1))
                )
                if not mutual:
                    desig_trust_lo = 0.0
                    desig_trust_hi = 0

            for inner_power in range(num_powers):
                reach = int(reachability[prov, inner_power])
                if reach == 0:
                    continue

                trust_lo = float(state.g_ally_trust_score[outer_power, inner_power])
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, inner_power])
                # g_ally_history_count = g_relation_score (DAT_00634e90);
                # fixed 2026-04-14 — previously hardcoded to 0.
                history = int(state.g_relation_score[outer_power, inner_power])

                # Three-clause hostility gate, shared by the threat update and
                # the enemy-reach accumulator (C:381-383 and C:401-403).
                hostile_gate = (
                    (trust_lo == 0 and trust_hi == 0)
                    or history < 10
                    or (trust_hi >= 0 and (trust_hi > 0 or trust_lo > 1)
                        and not is_ally_desig)
                )

                if inner_power == outer_power:
                    # C:357-366 — own reach is recorded only when the
                    # designation-derived trust is zero in both words.
                    if desig_trust_lo == 0.0 and desig_trust_hi == 0:
                        state.g_own_reach_score[outer_power, prov] = reach
                else:
                    # Threat (best enemy reach) — C:375-388.
                    threat_fired = False
                    if reach > state.g_threat_level[outer_power, prov]:
                        if hostile_gate:
                            state.g_threat_level[outer_power, prov] = reach
                            threat_fired = True

                    # Ally reach — C:389-397: int64 trust > 3.  C jumps over
                    # this block (goto LAB_00447c0c) when the threat update
                    # above fired, so the two are mutually exclusive.
                    if (not threat_fired
                            and trust_hi >= 0 and (trust_hi > 0 or trust_lo > 3)):
                        state.g_ally_reach_score[outer_power, prov] += reach

                    # Enemy reach — C:399-410 reuses the hostility gate.
                    if hostile_gate:
                        state.g_enemy_reach_score[outer_power, prov] += reach

                    state.g_total_reach_score[outer_power, prov] += reach

        # Section 4a — friendly/established-ally unit flags (updated 2026-04-21)
        # C indexes these as [outer_power * 0x100 + prov], making them 2D.
        # ScoreProvinces.c:796-803: set g_enemy_presence when trust is zero/unknown
        # (hi < 0 OR (hi == 0 AND lo == 0)); set friendly flags otherwise.
        for prov, info in state.unit_info.items():
            unit_power = info['power']
            if unit_power == outer_power:
                continue  # own units don't get friendly/ally flags
            trust_lo = float(state.g_ally_trust_score[outer_power, unit_power])
            try:
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, unit_power])
            except (AttributeError, IndexError):
                trust_hi = 0
            # Unknown/enemy trust → enemy_presence (ScoreProvinces.c:803)
            if trust_hi < 0 or (trust_hi == 0 and trust_lo == 0):
                state.g_enemy_presence[outer_power, prov] = 1
                continue
            # Known trust → friendly flag
            state.g_friendly_unit_flag[outer_power, prov] = 1
            # Check established ally flag (relation <= 9)
            try:
                relation = int(state.g_relation_score[outer_power, unit_power])
            except (AttributeError, IndexError, TypeError):
                relation = 0
            if relation <= 9:
                state.g_established_ally_flag[outer_power, prov] = 1

        # Section 4b — occupation scoring init (C:440-461).
        # C writes g_AttackCount (DAT_006040e8) = 1 or 5 directly; this IS
        # g_attack_count.  No approximation — the field is correct.
        # A separate pass (C:1243-1260) writes DAT_006190e8 (g_build_order_pending)
        # = 600; see post-loop block below.
        # C (ScoreProvinces.c:441-461) calls GameBoard_GetPowerRec on the
        # province's home-SC power set (province_record + 0x14) and writes the
        # weight when outer_power is found there — i.e. the gate is "prov is
        # one of outer_power's HOME supply centres", not "outer_power has a
        # unit standing on prov".  Since g_attack_count * build_weight seeds
        # BFS round 0, the old gate reshaped the entire candidate ranking.
        # Section 4h below overwrites g_attack_count for every province it
        # scores, so this pre-seed only survives on provinces 4h skips — the
        # same as in C, where line 644 re-zeroes the row before 4h runs.
        weight = 1.0 if state.g_other_power_lead_flag else 5.0
        for prov in state.home_centers.get(outer_power, frozenset()):
            if 0 <= prov < num_provinces:
                state.g_attack_count[outer_power, prov] = weight

        # Section 4e — convoy/mobility counts (C: ScoreProvinces.c:831-925).
        #
        # Re-derived 2026-08-24.  The previous port read this block as an
        # "uncertain-trust fleet" gate and produced an ALL-ZERO
        # g_convoy_reach_count, which silently killed the entire
        # `convoy_reach > 0` branch of EvaluateProvinceScore
        # (heuristics/_primitives.py:63-72) — every uncontested province
        # scored 0 there instead of 2/15/50/100.  Three separate divergences:
        #
        #  1. `DAT_004d2e14` is NOT a trust score.  It is the HI word of
        #     g_AllyDesignation_A (paired with it as an int64 `== -1` test at
        #     EvaluateAllianceScore.c:898), and C indexes it by the ADJACENT
        #     PROVINCE (`[piVar11[3] * 2]`), not by a power.  C:874-875 is
        #     therefore "adj carries no A-designation", i.e. hi word < 0.
        #     There is no fleet-type test and no "adj must hold a unit" test.
        #  2. C:897 gates on g_enemy_presence[outer_power, UNIT_PROV]
        #     (DAT_004f6ce8, int64 == 1), not on a unit-presence table.
        #  3. C indexes every table in this block with the OUTER power
        #     (`iVar16 = local_559c * 0x100`), not own_power; C:918 likewise
        #     compares the unit's owner (node+0x18) against outer_power.
        for prov, info in state.unit_info.items():
            _utype = info.get('type', 'A')
            _coast = str(info.get('coast', '') or '')
            _adj1 = [
                adjacent
                for adjacent in state.get_unit_adjacencies(prov)
                if state.can_reach_by_type(
                    prov, adjacent, _utype, _coast,
                )
            ]
            _enemy_here = int(state.g_enemy_presence[outer_power, prov]) == 1
            _prev = -1
            for adj in _adj1:
                # C:872 skips consecutive duplicate adjacency entries
                # (local_5594 holds the previous province).
                if adj == _prev:
                    continue
                _prev = adj
                if int(state.g_ally_designation_a_hi[adj]) >= 0:
                    continue
                for adj2 in state.get_unit_adjacencies(adj):
                    if (_enemy_here
                            and int(state.g_sc_ownership[outer_power, adj2]) == 0):
                        state.g_convoy_reach_count[outer_power, adj2] += 1
                    if info['power'] != outer_power:
                        state.g_enemy_mobility_count[outer_power, adj2] += 1
        #
        # MEASURED 2026-08-24: neutral on the F1901M corpus (140 vs 141 of
        # 550; convoys, exact-set and neutral-SC counts all identical).
        # Applied for fidelity: g_convoy_reach_count was ALWAYS EMPTY
        # before this, and g_enemy_mobility_count only feeds a branch
        # gated on g_press_flag, which compare_albert disables -- so that
        # half of the fix is untestable by this harness but live in real
        # games.

        # ScoreProvinces.c:948-950 computes the WIN-only inverse-distance
        # channels after the own-power friendly/enemy reach flags above have
        # been populated.  The old Python port defined this routine but never
        # called it.
        if (outer_power == own_power
                and str(getattr(state, 'g_season', '')).upper() == 'WIN'):
            compute_winter_builds(state, own_power)

        # Section 4g — per-power province weight (C: ScoreProvinces.c:651-762,
        # writing DAT_00540ce8[outer_power*0x100 + prov]).
        #
        # For every unit, count the adjacencies that (a) outer_power can reach
        # (g_own_reach_score > 0) and (b) belong to a foreign unit that is not
        # shielded by a trusted-ally designation; then spread 1/count evenly
        # across *all* of that unit's adjacencies.  The second walk in C does
        # not re-apply the gate.
        #
        # This pass had no Python port before 2026-08-12, so g_province_weight
        # stayed all-zero and every consumer in monte_carlo/evaluation.py took
        # its fallback branch.
        #
        # Note: C indexes the relation-score lookup with a stale local
        # (local_557c); by analogy with ScoreProvinces.c:819 it is the unit's
        # power, which is what is used here.
        for prov, info in state.unit_info.items():
            unit_power = info['power']
            unit_type = info.get('type', 'A')
            unit_coast = str(info.get('coast', '') or '')
            adj_list = [a for a in state.get_unit_adjacencies(prov)
                        if state.can_reach_by_type(
                            prov, a, unit_type, unit_coast,
                        )]

            count = 0
            for adj in adj_list:
                if int(state.g_own_reach_score[outer_power, adj]) <= 0:
                    continue
                if unit_power == outer_power:
                    continue
                is_designated = (
                    int(state.g_ally_designation_a[adj]) == outer_power
                    or int(state.g_ally_designation_b[adj]) == outer_power
                    or int(state.g_ally_designation_c[adj]) == outer_power
                )
                trust_lo = float(state.g_ally_trust_score[outer_power, unit_power])
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, unit_power])
                relation = int(state.g_relation_score[outer_power, unit_power])
                if (trust_lo != 0 or trust_hi != 0) and relation > 9:
                    if (trust_hi < 0
                            or (trust_hi < 1 and trust_lo < 2)
                            or is_designated):
                        continue
                count += 1

            if count > 0:
                share = 1.0 / float(count)
                for adj in adj_list:
                    state.g_province_weight[outer_power, adj] += share

        # Section 4h — province score assignment (main scoring pass)
        # Updated 2026-04-14: now runs for every `outer_power` (not just
        # `own_power`), mirroring C's per-power iteration. This populates
        # g_attack_count[power, prov] for all powers, giving Albert a
        # per-opponent view of province priorities.
        #
        # Extended 2026-04-14 (pass 3): all 8 Section 4h post-adjustments
        # from ScoreProvinces.c lines 1000-1228 now ported:
        #   (1) home-center + has_adj_enemy clamp          → 80 / 150
        #   (2) ally territory /3 or zero                   → 0 or score/3
        #   (3) influence ratio boost (>0.95, near_end<3)   → 10
        #   (4) opening target match (score==0)             → 150
        #   (5) non-home-center unit-owner score            → 10 or 1
        #   (6) late-game trusted-ally suppression          → 0
        #   (7) free-province neighbor-SC heuristic         → 75 / 75·trust⁻¹
        #   (8) WIN sticky + SC-count bump                  → 5 ± 20/5
        # Symbol mappings (from GlobalDataRefs.md):
        #   DAT_00b85768 → g_press_matrix, DAT_00b85710 → g_press_count,
        #   DAT_004d2e14 → g_ally_designation_a hi-word,
        #   g_opening_sticky_mode already in state.
        # The 10-round BFS candidate sets are seeded and propagated at the
        # bottom of score_provinces (ScoreProvinces.c:466-638) into
        # g_candidate_bfs[power, round, province] for ALL 7 powers.
        # get_candidate_score returns per-round values so the weighted
        # dot-product across all rounds correctly ranks province candidates.

        # Precompute once per outer_power (C:952-977). Province +0x20 is a
        # DAIDE power token (category 0x41), so the high-byte 'A' test validates
        # a controller; it does not identify an army occupant. The flag means
        # one of the power's home centres is not currently controlled by it.
        local_5581_flag = False
        for home_prov in state.home_centers.get(outer_power, frozenset()):
            if int(state.g_sc_owner[home_prov]) != outer_power:
                local_5581_flag = True
                break

        near_end = float(state.g_near_end_game_factor)

        # C:983 gates the scoring body on province-record byte +3
        # (*(char *)(board + 3 + prov*0x24) != '\0').  That byte is the
        # SUPPLY-CENTRE flag, not a map-validity flag: ComputeBuildDelta
        # walks the same records and uses the identical test
        # (`pbVar5[-0x1d] != 0`, pbVar5 = record + 0x20) to decide whether a
        # province contributes to a power's supply-centre tally.
        #
        # Fixed 2026-08-17: this loop previously ran over `valid_provinces`
        # (every province on the map).  That gave every empty non-centre the
        # same 75 as every empty neutral centre, erasing the whole
        # supply-centre gradient — SPA and GAS were worth exactly the same to
        # France, so armies wandered instead of taking centres.  Non-centres
        # must stay at g_attack_count = 0; they still receive value through
        # the BFS diffusion below, which does iterate every province.
        # Sorted so the sweep runs in province-index order like C's, and so a
        # set's iteration order can never leak into the results.
        _sc_provs = getattr(state, 'sc_provinces', None)
        prov_iter = sorted(_sc_provs) if _sc_provs else (
            sorted(valid_provs) if valid_provs else range(num_provinces)
        )
        for prov in prov_iter:
            controller = int(state.g_sc_owner[prov])
            if not 0 <= controller < num_powers:
                controller = -1

            # Determine if EvaluateProvinceScore is called (C logic)
            is_own_or_ally = False
            if controller == outer_power:
                unit_owner = int(state.g_ally_designation_a[prov])
                unit_owner_hi = int(state.g_ally_designation_a_hi[prov])
                is_own_or_ally = (
                    (unit_owner == -1 and unit_owner_hi == -1)
                    or (unit_owner == outer_power and unit_owner_hi == 0)
                )
            elif controller != -1:
                trust_lo = float(state.g_ally_trust_score[outer_power, controller])
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, controller])
                if (trust_hi >= 0
                        and (trust_hi > 0 or trust_lo > 4)
                        and int(state.g_ally_designation_b[prov]) == controller
                        and int(state.g_ally_designation_b_hi[prov]) == 0):
                    is_own_or_ally = True

            if is_own_or_ally:
                score = float(evaluate_province_score(state, prov, outer_power))
                
                # Adjustment 1 — SC ownership / non-SC clamp (C 1006-1021).
                # C: GameBoard_GetPowerRec checks if outer_power is in the
                # province's SC-ownership set.
                #   found (outer_power owns SC) → score > 15 & flag → 150
                #   not found                   → score != 0 & flag → 80
                # Fixed 2026-04-28: was using home_power == sc_owner; must
                # use outer_power SC ownership.
                # Fixed 2026-08-17: g_sc_ownership → g_board_sc_ownership.
                # C:1002-1019 queries the board (GameBoard_GetPowerRec); the
                # scratch table read here holds unit presence by this point.
                outer_owns_this_sc = (
                    prov in state.home_centers.get(outer_power, frozenset())
                )

                if outer_owns_this_sc:
                    if score > 15.0 and local_5581_flag:
                        score = 150.0
                else:
                    if score != 0.0 and local_5581_flag:
                        score = 80.0

                # Adjustment 2 — ally territory /3 or zero (C 1022-1042).
                # C gates this with: unit_power != outer_power AND
                #   trust_hi >= 0 AND (trust_hi > 0 OR trust_lo > 4) AND
                #   ally_designation_b[prov] == unit_power (with hi == 0).
                # Inside that gate, C further checks a threat-level field:
                #   if threat <= 0 → score = 0; else → score /= 3.
                # Fixed 2026-04-28: was unconditional; now gated.
                if controller != -1 and controller != outer_power:
                    trust_lo_a2 = float(state.g_ally_trust_score[outer_power, controller])
                    trust_hi_a2 = int(state.g_ally_trust_score_hi[outer_power, controller])
                    desig_b = int(state.g_ally_designation_b[prov])
                    desig_b_hi = int(state.g_ally_designation_b_hi[prov])
                    if (trust_hi_a2 >= 0
                            and (trust_hi_a2 > 0 or trust_lo_a2 > 4)
                            and desig_b == controller
                            and desig_b_hi == 0):
                        # Sub-condition: check threat level at [uowner, prov].
                        thr = int(state.g_threat_level[controller, prov])
                        if thr <= 0:
                            score = 0.0
                        else:
                            score /= 3.0

                # Adjustment 3 — influence ratio boost (C 1043-1048).
                #
                # C:  if (0.95 < ratio && g_AttackCount[pow][prov] == 0
                #         && NearEndGame < 3.0)  g_AttackCount[pow][prov] = 10;
                # g_AttackCount is C's running score for this province (it is
                # written by EvaluateProvinceScore at C:999 and by Adjustments
                # 1 and 2), so the gate is `score == 0` and the action is an
                # ASSIGNMENT of 10 -- not an unconditional `+= 10`.  Without
                # the gate every evaluated province picked up a spurious +10.
                if near_end < 3.0 and score == 0.0:
                    cov = int(state.g_coverage_flag[outer_power, prov])
                    tot = 0
                    for p in range(num_powers):
                        tot += int(state.g_coverage_flag[p, prov])
                    if tot > 0 and (cov / tot) > 0.95:
                        score = 10.0
            else:
                # C:00448d04 writes 2 into DAT_006190e8 (g_build_order_pending),
                # NOT into g_AttackCount (DAT_006040e8).  Every write on this
                # non-EvaluateProvinceScore path targets the SAME second array;
                # see the header note above.
                pending = 2.0

            # After the EvaluateProvinceScore path fails, C's ppiVar10 is the
            # current SCO controller. The only exception is a centre still
            # controlled by outer_power but occupied by a foreign unit, where
            # g_AllyDesignation_A supplies that unit's power. Unit type is not
            # tested; UNO/uncontrolled is the 0x14 sentinel.
            effective_power = controller
            designation_a = int(state.g_ally_designation_a[prov])
            designation_a_hi = int(state.g_ally_designation_a_hi[prov])
            if (controller == outer_power
                    and designation_a_hi == 0
                    and 0 <= designation_a < num_powers
                    and designation_a != outer_power):
                effective_power = designation_a

            # Adjustments 4 and 7 — opening target or neutral/default pending.
            if (not is_own_or_ally and effective_power == -1):
                # 00448d80  CMP  [EDI*4 + g_OpeningTarget], prov
                # 00448d89  MOV  EAX, [ESI + DAT_0058f8e8]   ; g_own_reach_score
                # 00448d8f  OR   EAX, [ESI + DAT_0058f8ec]
                # 00448d95  JNZ  ...                          ; skip unless == 0
                # The decompile rendered the second gate as an unidentified
                # array (ppiVar17[0x163e3a]); it is g_own_reach_score, and the
                # port had dropped the test entirely.
                ot = getattr(state, 'g_opening_target', None)
                if (ot is not None and ot[outer_power] == prov
                        and int(state.g_own_reach_score[outer_power, prov]) == 0):
                    pending = 150.0
                elif (hasattr(state, 'g_press_matrix')
                      and hasattr(state, 'g_press_count')):
                # Check if any non-outer power has presence here.
                    any_presence = any(
                        p != outer_power
                        and int(state.g_press_matrix[p, prov]) > 0
                        for p in range(num_powers)
                    )
                    if not any_presence:
                        pending = 75.0  # 0x4b — default
                    else:
                        own_here = (
                            int(state.g_press_matrix[outer_power, prov]) > 0
                        )
                        best = 0.0
                        capped = False
                        for p in range(num_powers):
                            if p == outer_power:
                                continue
                            if int(state.g_press_matrix[p, prov]) <= 0:
                                continue
                            tlo = float(
                                state.g_ally_trust_score[outer_power, p]
                            )
                            thi = int(
                                state.g_ally_trust_score_hi[outer_power, p]
                            )
                            uncertain_p = (
                                thi < 1 and (thi < 0 or tlo < 2)
                            )
                            if uncertain_p:
                                capped = True
                                break
                            if own_here and int(state.g_press_count[p]) > 1:
                                capped = True
                                continue
                            if tlo <= 0:
                                capped = True
                                continue
                            ratio = 100.0 / tlo
                            if ratio > best:
                                best = 75.0 / tlo
                        pending = 75.0 if capped else best

            # Adjustments 5, 8 and 6 — pending a controlled foreign centre by
            # its effective power, independent of occupying unit type.
            if (not is_own_or_ally
                    and effective_power != -1
                    and effective_power != outer_power):
                trust_lo = float(
                    state.g_ally_trust_score[outer_power, effective_power]
                )
                trust_hi = int(
                    state.g_ally_trust_score_hi[outer_power, effective_power]
                )
                uncertain = (trust_hi < 0
                             or (trust_hi < 1 and trust_lo < 2))
                pending = 10.0 if uncertain else 1.0

                # Adjustment 8 — WIN sticky + SC-count bump (C 1162-1199).
                # Fires when outer_power owns > 2 supply centres.
                # Fixed 2026-08-17: C reads curr_sc_cnt[power] (C:1160), the
                # board-derived centre tally = state.sc_count.  Summing
                # g_sc_ownership counted units, not centres.
                own_scs = int(state.sc_count[outer_power])
                if own_scs > 2:
                    deceit = int(getattr(state, 'g_deceit_level', 0))
                    sticky = int(getattr(state, 'g_opening_sticky_mode', 0))
                    season = getattr(state, 'g_season', 'SPR')
                    if (deceit < 2 and outer_power == own_power
                            and season == 'WIN' and sticky == 1
                            and not uncertain):
                        pending = 5.0
                    else:
                        # C: PackScoreU64 rounds ST0 (= current pending float)
                        # to int64 via banker's rounding (ScoreProvinces.c:1174-1176).
                        pending = float(_float_to_int64(pending))
                    # C:1188/1194 re-reads the +0x20 SCO controller token.
                    owner_scs = int(state.sc_count[controller])
                    wt = int(getattr(state, 'win_threshold', 18)) or 18
                    if owner_scs < 2:
                        pending += 80.0   # 0044905c: ADD ...,0x50
                    elif (owner_scs * 100) // wt <= 12:
                        pending += 20.0   # 0044906a: ADD ...,0x14

                # Adjustment 6 — late-game trusted-ally suppression
                # (C 1203-1207).  Nested inside Adjustment 5's branch.
                if (near_end > 5.0 and trust_hi >= 0
                        and (trust_hi > 0 or trust_lo > 10)):
                    pending = 0.0

            # Adjustment 9 — home-centre override (C 1209-1228).
            #
            # C reaches this block ONLY on the non-EvaluateProvinceScore path.
            # ScoreProvinces.c:1049 is `goto LAB_00449139;` and LAB_00449139 is
            # at C:1230 — so a province that took the EvaluateProvinceScore
            # branch at LAB_00448b2b (C:996) skips lines 1050-1229 entirely:
            # Adjustments 4, 5, 6, 7, 8 *and* 9.  Running Adjustment 9 for every
            # province overwrote every evaluated own-centre score with a flat
            # 90/150, which is what made an empty own centre outrank a
            # supply centre the power was standing on.
            if (not is_own_or_ally
                    and prov in state.home_centers.get(
                        outer_power, frozenset()
                    )):
                pending = 90.0 if controller == outer_power else 150.0

            # Two distinct destination arrays (disassembly):
            #   evaluate path      -> g_AttackCount        (DAT_006040e8)
            #   non-evaluate path  -> g_BuildOrderPending  (DAT_006190e8)
            # The BFS seed at 00449973-004499ac is
            #   DAT_006190e8 * move_weight + g_AttackCount * build_weight,
            # so these are two summed channels, not one score.
            if is_own_or_ally:
                state.g_attack_count[outer_power, prov] = score
            else:
                state.g_build_order_pending[outer_power, prov] = pending
            # max-accumulate — only track global max from own_power's
            # perspective (C mirrors this via the Albert-specific max
            # tracker in Phase 5).
            _written = score if is_own_or_ally else pending
            if outer_power == own_power and _written > state.g_max_province_score[prov]:
                state.g_max_province_score[prov] = _written

    all_provs = valid_provs if valid_provs else range(num_provinces)

    # ── g_build_order_pending seed pass (C:1240-1285) ────────────────────────
    # Both GameBoard_GetPowerRec calls query static home-centre membership.
    # If a power currently controls NONE of its home centres (+0x20 SCO
    # controller token), seed all of those homes with 600. Unit presence and
    # unit type do not participate.
    for seed_power in range(num_powers):
        home_provs = state.home_centers.get(seed_power, frozenset())
        if any(int(state.g_sc_owner[prov]) == seed_power
               for prov in home_provs):
            continue
        for prov in home_provs:
            state.g_build_order_pending[seed_power, prov] = 600

    # ── Early home-centre BFS, preserving round 9 (C:440-638, 1288-1351) ────
    # Albert has two distinct scoring epochs. Before the main province scores
    # above are assigned, g_AttackCount contains only 1/5 on each power's
    # static home centres. C diffuses that seed through all ten tree slots.
    # Much later it overwrites slots 0-8 from the main attack scores but leaves
    # slot 9 from this early epoch in place. The previous port ran both epochs
    # after main scoring, making them identical and incorrectly recomputing
    # round 9 from the later values.
    seed_w = int(build_weight)
    move_w = int(move_weight)

    if getattr(state, '_bfs_flt', None) is None or state._bfs_flt.shape != state.g_candidate_bfs.shape:
        state._bfs_flt = np.zeros_like(state.g_candidate_bfs)

    phase1_army_round9 = np.zeros((num_powers, num_provinces), dtype=np.int64)
    phase1_fleet_round9 = np.zeros((num_powers, num_provinces), dtype=np.int64)
    phase1_weight = 1 if state.g_other_power_lead_flag else 5
    for bfs_power in range(num_powers):
        army_prev = np.zeros(num_provinces, dtype=np.int64)
        for prov in state.home_centers.get(bfs_power, frozenset()):
            army_prev[prov] = phase1_weight * seed_w
        for rnd in range(1, 10):
            army_next = np.zeros(num_provinces, dtype=np.int64)
            for prov in all_provs:
                prev_self = int(army_prev[prov])
                adj_sum = 0
                for adj in set(state.adj_matrix.get(prov, [])):
                    if adj in state.water_provinces:
                        continue
                    adj_sum += int(army_prev[adj])
                army_next[prov] = _signed_int_div(
                    prev_self + adj_sum, 5
                )
            army_prev = army_next
        phase1_army_round9[bfs_power] = army_prev

        fleet_prev = np.zeros(num_provinces, dtype=np.int64)
        for prov in state.home_centers.get(bfs_power, frozenset()):
            fleet_prev[prov] = phase1_weight * seed_w
        fleet_seed = np.zeros((1, 1, num_provinces), dtype=np.int64)
        fleet_seed[0, 0] = fleet_prev
        _seed_and_fold_coasts(state, fleet_seed, 0, 0)
        fleet_prev = fleet_seed[0, 0].copy()
        for rnd in range(1, 10):
            fleet_next = np.zeros(num_provinces, dtype=np.int64)
            for prov in all_provs:
                prev_self = int(fleet_prev[prov])
                adj_sum = 0
                for adj in set(state.fleet_adj_matrix.get(prov, [])):
                    adj_sum += int(fleet_prev[adj])
                fleet_next[prov] = _signed_int_div(
                    prev_self + adj_sum, 5
                )
            fleet_seed[0, 0] = fleet_next
            _seed_and_fold_coasts(state, fleet_seed, 0, 0)
            fleet_prev = fleet_seed[0, 0].copy()
        phase1_fleet_round9[bfs_power] = fleet_prev

    # In movement/retreat phases C selectively clears early round-9 keys whose
    # province has no enemy reach and whose adjacent centres are all own or
    # highly trusted. An uncontrolled centre uses the UNO trust slot, whose
    # default 0 keeps the key; Python's seven-power trust matrix has no UNO
    # column, so controller == -1 is handled explicitly as untrusted.
    if not str(getattr(state, 'g_season', '')).upper().startswith('WIN'):
        for bfs_power in range(num_powers):
            for prov in all_provs:
                if int(state.g_enemy_reach_score[bfs_power, prov]) != 0:
                    continue

                def keeps_round9(adjacencies):
                    for adj in set(adjacencies):
                        if adj not in state.sc_provinces:
                            continue
                        controller = int(state.g_sc_owner[adj])
                        if controller == bfs_power:
                            continue
                        if not 0 <= controller < num_powers:
                            return True
                        trust_lo = float(
                            state.g_ally_trust_score[bfs_power, controller]
                        )
                        trust_hi = int(
                            state.g_ally_trust_score_hi[bfs_power, controller]
                        )
                        if trust_hi < 1 and (trust_hi < 0 or trust_lo < 15):
                            return True
                    return False

                army_adj = [
                    adj for adj in state.adj_matrix.get(prov, ())
                    if adj not in state.water_provinces
                ]
                if not keeps_round9(army_adj):
                    phase1_army_round9[bfs_power, prov] = 0
                if not keeps_round9(state.fleet_adj_matrix.get(prov, ())):
                    phase1_fleet_round9[bfs_power, prov] = 0

    # ── Phase-5 candidate BFS re-seed (ScoreProvinces.c:1538-1544) ───────────
    # Re-seeds slot[0] for all powers with
    #   g_attack_count * build_weight + g_build_order_pending[own_power] * move_weight
    # then re-propagates 9 BFS rounds.  g_build_order_pending is non-zero only
    # in the WIN phase (own_power has no units), so this is a no-op in movement
    # phases where the seed is identical to the Phase-1 pass above.
    is_win_season = str(getattr(state, 'g_season', '')).upper().startswith('WIN')
    selected_builds = list(getattr(state, 'g_selected_build_candidates', ()))
    selected_army_provinces = {
        int(candidate['province'])
        for candidate in selected_builds
        if str(candidate.get('unit_type', '')).upper() in ('A', 'AMY')
    }
    selected_fleet_keys: list[tuple[int, str]] = [
        (int(candidate['province']), str(candidate.get('coast', '')))
        for candidate in selected_builds
        if str(candidate.get('unit_type', '')).upper() in ('F', 'FLT')
    ]
    for bfs_power in range(num_powers):
        base_seeds = np.zeros(num_provinces, dtype=np.int64)
        state.g_candidate_bfs[bfs_power, 0].fill(0.0)
        for prov in all_provs:
            # C indexes g_build_order_pending with the SAME (power, prov) pair
            # as g_attack_count (ScoreProvinces.c:1538-1541) — the BFS power's
            # row, not own_power's.
            seed = (
                int(state.g_attack_count[bfs_power, prov]) * seed_w
                + int(state.g_build_order_pending[bfs_power, prov]) * move_w
            )
            # WIN-phase occupied-own-SC penalty (C:1545-1554): −0x9c4.
            # C applies it to the current (province, unit-token) tree key only.
            # Keep the AMY and FLT channels distinct; applying it before the
            # split incorrectly penalises both possible build types.
            base_seeds[prov] = seed
            unit = state.unit_info.get(prov)
            if (is_win_season
                    and int(state.g_sc_ownership[bfs_power, prov]) == 1
                    and unit is not None
                    and unit.get('type', 'A') in ('A', 'AMY')):
                seed -= 2500
            # ScoreProvinces.c:1574-1616 walks the WIN order tree after the
            # ordinary occupied-unit pass. In a build phase every selected
            # exact token receives another -0x9c4 before propagation.
            if (is_win_season and bfs_power == own_power
                    and prov in selected_army_provinces):
                seed -= 2500
            state.g_candidate_bfs[bfs_power, 0, prov] = seed

        # C clears and recomputes only slots 1-8 here. Slot 9 retains the
        # selectively cleared value from the early home-centre epoch.
        for rnd in range(1, 9):
            state.g_candidate_bfs[bfs_power, rnd].fill(0.0)
            for prov in all_provs:
                prev_self = int(state.g_candidate_bfs[bfs_power, rnd - 1, prov])
                adj_sum = 0
                for adj in set(state.adj_matrix.get(prov, [])):
                    if adj in state.water_provinces:
                        continue
                    adj_sum += int(state.g_candidate_bfs[bfs_power, rnd - 1, adj])
                state.g_candidate_bfs[bfs_power, rnd, prov] = _signed_int_div(
                    prev_self + adj_sum, 5
                )
        state.g_candidate_bfs[bfs_power, 9] = phase1_army_round9[bfs_power]
        # FLEET channel: same seed, but diffused over fleet-reachable adjacency
        # only (C filters each key's adjacency by that key's own token,
        # ScoreProvinces.c:537-539).
        _fb = state._bfs_flt
        _fb[bfs_power, 0].fill(0.0)
        for prov in all_provs:
            _fb[bfs_power, 0, prov] = base_seeds[prov]
        _seed_and_fold_coasts(state, _fb, bfs_power, 0)
        if is_win_season:
            for prov in all_provs:
                unit = state.unit_info.get(prov)
                if (unit is None
                        or int(state.g_sc_ownership[bfs_power, prov]) != 1
                        or unit.get('type', 'A') not in ('F', 'FLT')):
                    continue
                fleet_key = prov
                coast = str(unit.get('coast', ''))
                if prov in getattr(state, 'coast_variants', {}) and coast:
                    if not state._id_to_prov:
                        state._id_to_prov = {
                            pid: name for name, pid in state.prov_to_id.items()
                        }
                    base_name = state._id_to_prov.get(prov, '').split('/')[0]
                    coast_suffix = '/' + coast.upper().lstrip('/')
                    fleet_key = int(state.prov_to_id.get(
                        base_name + coast_suffix, prov
                    ))
                _fb[bfs_power, 0, fleet_key] -= 2500
            if bfs_power == own_power:
                for selected_prov, selected_coast in selected_fleet_keys:
                    fleet_key = selected_prov
                    if (selected_prov in getattr(state, 'coast_variants', {})
                            and selected_coast):
                        if not state._id_to_prov:
                            state._id_to_prov = {
                                pid: name for name, pid in state.prov_to_id.items()
                            }
                        base_name = state._id_to_prov.get(
                            selected_prov, ''
                        ).split('/')[0]
                        coast_suffix = '/' + selected_coast.upper().lstrip('/')
                        fleet_key = int(state.prov_to_id.get(
                            base_name + coast_suffix, selected_prov
                        ))
                    _fb[bfs_power, 0, fleet_key] -= 2500
            # A multi-coast base is the compatibility maximum of its legal
            # coast keys, not an additional plain-FLT key.
            for base, coasts in getattr(state, 'coast_variants', {}).items():
                _fb[bfs_power, 0, base] = max(
                    _fb[bfs_power, 0, coast] for coast in coasts
                )
        for rnd in range(1, 9):
            _fb[bfs_power, rnd].fill(0.0)
            for prov in all_provs:
                prev_self = int(_fb[bfs_power, rnd - 1, prov])
                adj_sum = 0
                for adj in set(state.fleet_adj_matrix.get(prov, [])):
                    adj_sum += int(_fb[bfs_power, rnd - 1, adj])
                _fb[bfs_power, rnd, prov] = _signed_int_div(
                    prev_self + adj_sum, 5
                )
            _seed_and_fold_coasts(state, _fb, bfs_power, rnd)
        _fb[bfs_power, 9] = phase1_fleet_round9[bfs_power]

    _cleanup_sc_designations(state)


# ── ScoreOrderCandidates: candidate-vs-press corroboration penalty ───────────
#
# Port of Source/ScoreOrderCandidates.c lines 215–630.
#
# Before the ProcessTurn loop, C builds 4 per-power sorted-set trees from
# inbound DAIDE press (param_2 = general XDO list, param_5 = alliance XDO
# list):
#   local_3fc — general XDO orders, keyed by proposing power
#   local_204 — alliance XDO orders, keyed by proposing power
#   local_300 — SUP-MTO orders, keyed by SUPPORTED unit's power
#   local_108 — SUP-HLD orders, keyed by SUPPORTED unit's power
#
# After ProcessTurn, for each candidate record C checks every tree node
# (one press order) via subset function FUN_00465d90:
#   trees 1–3: press_order_province_set ⊆ candidate_unit_province_set?
#              EVERY node must match → pass
#   tree 4:    same subset test AND candidate has MTO/CTO → FAIL (inverted)
# Candidates that fail receive type_flag=1, score=0xff676980 (≈ -2.5e36).
#
# The "already on board" gate (puVar8[1] != iVar18) is left implicit:
# g_board_orders is consulted separately by the MC dispatch path so
# committed orders are not re-picked regardless.

_PRESS_DISAGREE_PENALTY: float = -2.5e36   # C: 0xff676980 reinterpreted as f32


def apply_press_corroboration_penalty(state: InnerGameState) -> int:
    """
    Penalise g_candidate_record_list entries whose orders disagree with
    received-press orders for the same province/unit-power.  Returns the
    number of candidates penalised.

    Mirrors Source/ScoreOrderCandidates.c lines 215–630.

    The C code builds 4 per-power RB-trees from inbound press before the
    ProcessTurn loop, then for each candidate record checks all 4 trees:

      Tree 1 (local_3fc)  general XDO press, keyed by proposing power.
      Tree 2 (local_204)  alliance XDO press, keyed by proposing power.
      Tree 3 (local_300)  SUP-MTO press, keyed by SUPPORTED unit's power.
      Tree 4 (local_108)  SUP-HLD press, keyed by SUPPORTED unit's power.

    For each tree node (one press order), the C subset-function
    FUN_00465d90 asks: press_order_province_set ⊆ candidate_unit_province_set?
    A candidate passes trees 1–3 if EVERY tree node is matched by at least
    one candidate unit's province set.  Tree 4 is inverted: the candidate
    FAILS if any SUP-HLD tree node is matched by a candidate unit that is
    also a move (MTO/CTO), because the support would be wasted.

    A candidate that fails any check receives type_flag=1, score=-2.5e36.
    """
    received_general: dict = getattr(state, 'g_general_orders', {}) or {}
    received_alliance: dict = getattr(state, 'g_alliance_orders', {}) or {}
    candidates: list = getattr(state, 'g_candidate_record_list', []) or []
    if not candidates or (not received_general and not received_alliance):
        return 0

    prov_to_id: dict = getattr(state, 'prov_to_id', {}) or {}

    def _name_to_id(s):
        if isinstance(s, int):
            return s
        if not isinstance(s, str):
            return None
        if len(s) >= 3 and s[1] == ' ':
            s = s[2:]
        return prov_to_id.get(s)

    def _parse_press_order(seq: dict):
        """Return (prov_set, category, extra).

        category is 'xdo', 'sup_mto', or 'sup_hld'.
        extra for sup_mto: (supported_unit_prov_id, dest_prov_id)
        extra for sup_hld: supported_unit_prov_id
        extra for xdo:     None
        """
        prov_set = set()
        for k in ('source', 'unit_prov', 'province', 'unit'):
            pid = _name_to_id(seq.get(k))
            if pid is not None:
                prov_set.add(pid)
        for k in ('dest', 'target', 'target_unit', 'target_dest',
                  'convoy_leg0', 'convoy_leg1', 'convoy_leg2'):
            pid = _name_to_id(seq.get(k))
            if pid is not None:
                prov_set.add(pid)

        sup_unit_raw = seq.get('target_unit') or seq.get('target')
        if sup_unit_raw:
            sup_unit_id = _name_to_id(sup_unit_raw)
            dest_raw = seq.get('target_dest')
            if dest_raw:
                return prov_set, 'sup_mto', (sup_unit_id, _name_to_id(dest_raw))
            return prov_set, 'sup_hld', sup_unit_id
        return prov_set, 'xdo', None

    # Tree 1 (general XDO) and Tree 2 (alliance XDO):
    #   gen_xdo[power]   = [frozenset of province IDs per press order]
    #   ally_xdo[power]  = [frozenset of province IDs per press order]
    # Tree 3 (SUP-MTO) and Tree 4 (SUP-HLD):
    #   sup_mto[sup_power] = [(prov_set, dest_id)]
    #   sup_hld[sup_power] = [prov_set]
    gen_xdo:  dict = {}
    ally_xdo: dict = {}
    sup_mto:  dict = {}
    sup_hld:  dict = {}

    def _bucket(d, key):
        return d.setdefault(key, [])

    def _ingest(order_map: dict, xdo_tree: dict) -> None:
        for power_idx, order_list in order_map.items():
            p = int(power_idx)
            for entry in order_list or []:
                if not isinstance(entry, dict):
                    continue
                seq = entry.get('order_seq', entry)
                if not isinstance(seq, dict):
                    continue
                prov_set, cat, extra = _parse_press_order(seq)
                if not prov_set:
                    continue
                fs = frozenset(prov_set)
                if cat == 'xdo':
                    _bucket(xdo_tree, p).append(fs)
                elif cat == 'sup_mto':
                    sup_unit_id, dest_id = extra
                    if sup_unit_id is not None:
                        sp = (state.get_unit_power(sup_unit_id)
                              if hasattr(state, 'get_unit_power') else -1)
                        if sp >= 0:
                            _bucket(sup_mto, sp).append((fs, dest_id))
                elif cat == 'sup_hld':
                    sup_unit_id = extra
                    if sup_unit_id is not None:
                        sp = (state.get_unit_power(sup_unit_id)
                              if hasattr(state, 'get_unit_power') else -1)
                        if sp >= 0:
                            _bucket(sup_hld, sp).append(fs)

    _ingest(received_general, gen_xdo)
    _ingest(received_alliance, ally_xdo)

    if not gen_xdo and not ally_xdo and not sup_mto and not sup_hld:
        return 0

    _MTO_CTO = {'MTO', 'CTO', 2, 3}

    penalised = 0

    for record in candidates:
        if record.get('type_flag', 0) == 1:
            continue
        power_idx = record.get('power')
        if power_idx is None:
            continue
        p = int(power_idx)

        # Skip if no press trees touch this power.
        if (p not in gen_xdo and p not in ally_xdo
                and p not in sup_mto and p not in sup_hld):
            continue

        # Build per-unit province sets from the candidate's order list.
        # Each order is (prov, order_type, dest, dest_coast, secondary).
        unit_prov_sets: list = []   # one frozenset per unit order
        aggregate_provs: set = set()
        has_mto_cto = False

        for o in record.get('orders') or []:
            try:
                prov = int(o[0]) if not isinstance(o, int) else int(o)
                otype = o[1] if len(o) > 1 else None
                dest = int(o[2]) if len(o) > 2 and o[2] else None
            except (TypeError, IndexError, ValueError):
                continue
            us = {prov}
            if dest:
                us.add(dest)
            unit_prov_sets.append(frozenset(us))
            aggregate_provs |= us
            if otype in _MTO_CTO:
                has_mto_cto = True

        pass_flag = True

        # Tree 1: general XDO — every press order's province set must be ⊆
        # at least one candidate unit's province set (C local_3fc check).
        for press_ps in gen_xdo.get(p, []):
            if not any(press_ps <= us for us in unit_prov_sets):
                pass_flag = False
                break

        # Tree 2: alliance XDO — same logic (C local_204 check).
        if pass_flag:
            for press_ps in ally_xdo.get(p, []):
                if not any(press_ps <= us for us in unit_prov_sets):
                    pass_flag = False
                    break

        # Tree 3: SUP-MTO — press announced a support-move for one of this
        # power's units.  Candidate must have some unit whose aggregate
        # province set covers the press provinces AND a unit moving
        # (MTO/CTO) to the press-announced destination (C local_300 check).
        if pass_flag:
            for press_ps, press_dest in sup_mto.get(p, []):
                if press_ps <= aggregate_provs:
                    if not has_mto_cto:
                        pass_flag = False
                        break
                    # Secondary destination match: at least one MTO/CTO unit
                    # in the candidate moves to the press-announced dest.
                    dest_matched = False
                    for o in record.get('orders') or []:
                        try:
                            otype = o[1] if len(o) > 1 else None
                            dest = int(o[2]) if len(o) > 2 and o[2] else None
                        except (TypeError, IndexError, ValueError):
                            continue
                        if otype in _MTO_CTO and dest == press_dest:
                            dest_matched = True
                            break
                    if not dest_matched:
                        pass_flag = False
                        break

        # Tree 4: SUP-HLD — press announced a support-hold for one of this
        # power's units.  If any candidate unit is moving (MTO/CTO) AND the
        # press provinces are covered by the aggregate, the announced support
        # is contradicted → CLEAR pass flag (C local_108 inverted check).
        if pass_flag:
            for press_ps in sup_hld.get(p, []):
                if press_ps <= aggregate_provs and has_mto_cto:
                    pass_flag = False
                    break

        if not pass_flag:
            record['type_flag'] = 1
            record['score'] = _PRESS_DISAGREE_PENALTY
            penalised += 1

    return penalised


# ── ScoreOrderCandidates_OwnPower ─────────────────────────────────────────────

def score_order_candidates_own_power(state: InnerGameState,
                                     weight_vector: list,
                                     own_power: int,
                                     attack_weight: int = 0) -> None:
    """
    Port of ScoreOrderCandidates_OwnPower (FUN_004498d0).

    Scores token-keyed order candidates for own power. Three passes:
    signed-int64 dot product and attack term, signed normalization plus a
    shared per-province maximum, then army dithering.

    Research.md §1624.
    """
    num_provinces = 256

    state.g_candidate_scores[own_power].fill(0)

    is_win = str(getattr(state, 'g_season', '')).upper().startswith('WIN')
    candidates: list[tuple[int, str, str]] = []
    if is_win and getattr(state, 'g_adjustment_build_candidates', None):
        candidates = [
            (
                int(candidate['province']),
                str(candidate['unit_type']).upper(),
                str(candidate.get('coast', '')),
            )
            for candidate in state.g_adjustment_build_candidates
        ]
    elif is_win:
        # Remove candidates are the current own units. Their C keys retain
        # the live unit/coast token even though Python's removal selector only
        # needs the province after scoring.
        for prov in sorted(state.g_adjustment_candidate_provinces):
            unit = state.unit_info.get(prov, {})
            unit_type = (
                'FLT' if str(unit.get('type', '')).upper() in ('F', 'FLT')
                else 'AMY'
            )
            candidates.append((prov, unit_type, str(unit.get('coast', ''))))
    else:
        candidates = [
            (prov, 'AMY', '')
            for prov in range(num_provinces)
            if state.candidate_set_contains(own_power, prov)
        ]

    # C always walks ten int64 weight/tree pairs. Preserve the known prefix
    # and use zero for any unavailable tail store in the recovered corpus.
    weights = [int(value) for value in weight_vector[:10]]
    weights.extend([0] * (10 - len(weights)))
    fleet_bfs = getattr(state, '_bfs_flt', state.g_candidate_bfs)

    def bfs_province_for_token(
        province: int,
        unit_type: str,
        coast: str,
    ) -> int:
        if unit_type != 'FLT' or not coast:
            return province
        if not state._id_to_prov:
            state._id_to_prov = {
                pid: name for name, pid in state.prov_to_id.items()
            }
        base_name = state._id_to_prov.get(province, '').split('/')[0]
        coast_suffix = '/' + str(coast).upper().lstrip('/')
        return int(state.prov_to_id.get(base_name + coast_suffix, province))

    raw_scores: dict[tuple[int, str, str], int] = {}
    local_max = 1
    for key in candidates:
        prov, unit_type, coast = key
        bfs = fleet_bfs if unit_type == 'FLT' else state.g_candidate_bfs
        bfs_province = bfs_province_for_token(prov, unit_type, coast)
        raw = sum(
            int(bfs[own_power, rnd, bfs_province]) * weights[rnd]
            for rnd in range(10)
        )
        raw += int(state.g_attack_count[own_power, prov]) * int(attack_weight)
        raw_scores[key] = raw
        local_max = max(local_max, raw)

    normalized_scores = {
        key: _signed_int_div(raw * 1000, local_max)
        for key, raw in raw_scores.items()
    }

    # The C maximum is shared by every token at a province.
    for (prov, _, _), normalized in normalized_scores.items():
        if normalized > state.g_max_prov_score_per_power[own_power, prov]:
            state.g_max_prov_score_per_power[own_power, prov] = normalized

    for key, normalized in list(normalized_scores.items()):
        prov, unit_type, _ = key
        maximum = int(state.g_max_prov_score_per_power[own_power, prov])
        if unit_type == 'AMY' and normalized < maximum:
            normalized_scores[key] = maximum - normalized

    adjustment_scores: dict[tuple, float] = {}
    for key, value in normalized_scores.items():
        prov, _, _ = key
        state.g_candidate_scores[own_power, prov] = int(value)
        adjustment_scores[key] = float(value)
    state.g_adjustment_candidate_scores = adjustment_scores
