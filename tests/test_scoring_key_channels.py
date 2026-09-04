"""Token-keyed province-score regressions from the recovered C tree layout."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_scoring_mod = __import__(
    f'{_pkg_name}.heuristics.scoring',
    fromlist=[
        'score_provinces',
        'score_order_candidates_all_powers',
        'score_order_candidates_own_power',
        '_apply_enemy_sc_flank_denial',
        '_cleanup_sc_designations',
    ],
)
_support_mod = __import__(
    f'{_pkg_name}.moves.support',
    fromlist=['assign_support_order', 'build_support_opportunities'],
)

InnerGameState = _state_mod.InnerGameState
score_provinces = _scoring_mod.score_provinces
score_order_candidates_all_powers = _scoring_mod.score_order_candidates_all_powers
score_order_candidates_own_power = _scoring_mod.score_order_candidates_own_power
_apply_enemy_sc_flank_denial = _scoring_mod._apply_enemy_sc_flank_denial
_cleanup_sc_designations = _scoring_mod._cleanup_sc_designations
assign_support_order = _support_mod.assign_support_order
build_support_opportunities = _support_mod.build_support_opportunities


def test_phase_round_weights_match_recovered_constructor_stores():
    state = InnerGameState()

    assert state.g_spr_round_weights == [
        500, 1000, 30, 10, 6, 5, 4, 3, 2, 1000,
    ]
    assert state.g_fal_round_weights == [
        1000, 500, 30, 10, 6, 5, 4, 3, 2, 1000,
    ]


def test_score_province_reach_uses_live_fleet_source_coast():
    state = InnerGameState()
    split_coast, north_target, south_target = 10, 20, 30
    state.valid_provinces = frozenset({
        split_coast, north_target, south_target,
    })
    state.adj_matrix = {
        split_coast: [north_target, south_target],
        north_target: [split_coast],
        south_target: [split_coast],
    }
    state.fleet_adj_matrix = {
        split_coast: [north_target, south_target],
        north_target: [split_coast],
        south_target: [split_coast],
    }
    state.fleet_coast_adj = {
        (split_coast, '/NC'): [north_target],
        (split_coast, '/SC'): [south_target],
    }
    state.unit_info = {
        split_coast: {'power': 0, 'type': 'F', 'coast': 'NC'},
    }

    score_provinces(state, move_weight=1, build_weight=1, own_power=0)

    assert state.g_coverage_flag[0, split_coast] == 1
    assert state.g_coverage_flag[0, north_target] == 1
    assert state.g_coverage_flag[0, south_target] == 0


def test_enemy_flank_denial_uses_sc_controller_without_live_unit():
    state = InnerGameState()
    source, frontier, enemy_sc = 10, 11, 12
    state.unit_info[source] = {'power': 0, 'type': 'A', 'coast': ''}
    state.adj_matrix = {
        source: [frontier], frontier: [source, enemy_sc], enemy_sc: [frontier],
    }
    state.sc_provinces = {enemy_sc}
    state.g_sc_owner[enemy_sc] = 1
    state.g_prov_target_flag[0, frontier] = 1
    state.g_target_flag2[0, frontier] = 0

    _apply_enemy_sc_flank_denial(state)

    assert state.g_prov_target_flag[0, frontier] == -10
    assert state.g_target_flag2[0, frontier] == -1


def test_enemy_flank_denial_carries_fleet_arrival_coast():
    state = InnerGameState()
    source, split_coast, enemy_sc = 10, 11, 12
    state.unit_info[source] = {
        'power': 0, 'type': 'F', 'coast': '',
    }
    state.adj_matrix = {
        source: [split_coast],
        split_coast: [source, enemy_sc],
        enemy_sc: [split_coast],
    }
    state.fleet_adj_matrix = {
        source: [split_coast],
        split_coast: [source, enemy_sc],
        enemy_sc: [split_coast],
    }
    state.fleet_coast_adj = {
        (split_coast, '/NC'): [source],
        (split_coast, '/SC'): [enemy_sc],
    }
    state.sc_provinces = {enemy_sc}
    state.g_sc_owner[enemy_sc] = 1
    state.g_prov_target_flag[0, split_coast] = 1

    _apply_enemy_sc_flank_denial(state)

    # The fleet arrives on /NC and cannot continue to the centre through /SC.
    assert state.g_prov_target_flag[0, split_coast] == 1
    assert state.g_target_flag2[0, split_coast] == 0


def test_sc_designation_cleanup_uses_controller_reach():
    state = InnerGameState()
    province = 10
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 1
    state.g_ally_designation_a[province] = 2
    state.g_ally_designation_a_hi[province] = 0
    state.g_ally_designation_b[province] = 3
    state.g_ally_designation_b_hi[province] = 0

    _cleanup_sc_designations(state)

    assert state.g_ally_designation_b[province] == -1
    assert state.g_ally_designation_b_hi[province] == -1


def test_late_sc_designation_cleanup_marks_threatened_controller():
    state = InnerGameState()
    province = 10
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 1
    state.g_near_end_game_factor = 6.0
    state.g_enemy_reach_score[1, province] = 1

    _cleanup_sc_designations(state)

    assert state.g_ally_designation_b[province] == -2
    assert state.g_ally_designation_b_hi[province] == -1
    assert state.g_spr_desig_b[province] == -2
    assert state.g_spr_desig_b_hi[province] == -1


def test_top_reach_and_rescore_names_share_the_c_sentinel_storage():
    state = InnerGameState()

    assert state.g_top_reach_flag is state.g_needs_rescore
    assert state.g_top_reach_flag[10] == -1
    state.g_needs_rescore[10] = 1
    assert state.g_top_reach_flag[10] == 1


def test_army_and_fleet_keys_share_one_power_normalization_and_province_max():
    state = InnerGameState()
    coast = 10
    state.valid_provinces = frozenset({coast})
    state.land_provinces = frozenset()
    state.water_provinces = frozenset()
    state.adj_matrix = {coast: []}
    state.fleet_adj_matrix = {coast: []}
    state.g_candidate_bfs[0, 0, coast] = 50
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, coast] = 100

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    # Both keys are normalised against the fleet key's maximum of 100.
    # AMY first becomes 515, then Phase 1c replaces it with 1015 - 515.
    assert state.final_score_set[0, coast] == 500
    assert state.final_score_set_flt[0, coast] == 1015
    assert state.g_max_prov_score_per_power[0, coast] == 1015


def test_all_power_scoring_excludes_bogus_multi_coast_base_and_army_keys():
    state = InnerGameState()
    base, north_coast, south_coast = 10, 110, 111
    state.valid_provinces = frozenset({base, north_coast, south_coast})
    state.land_provinces = frozenset()
    state.water_provinces = frozenset()
    state.coast_variants = {base: (north_coast, south_coast)}
    state.g_candidate_bfs[0, 0, base] = 10
    # Coast-variant ids do not represent legal AMY keys.
    state.g_candidate_bfs[0, 0, north_coast] = 10_000
    state.g_candidate_bfs[0, 0, south_coast] = 10_000
    state._bfs_flt = state.g_candidate_bfs.copy()
    # A multi-coast province has two coasted FLT keys, not a plain base key.
    state._bfs_flt[0, 0, base] = 9_999
    state._bfs_flt[0, 0, north_coast] = 20
    state._bfs_flt[0, 0, south_coast] = 40

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    assert state.final_score_set_flt[0, north_coast] == 515
    assert state.final_score_set_flt[0, south_coast] == 1015
    assert state.final_score_set_flt[0, base] == 1015
    # Base AMY normalizes to 265, then becomes 1015 - 265.
    assert state.final_score_set[0, base] == 750


def test_round_zero_tree_domain_is_not_the_top_n_candidate_filter():
    state = InnerGameState()
    province = 12
    state.valid_provinces = frozenset({province})
    state.land_provinces = frozenset({province})
    state.water_provinces = frozenset()
    state.adj_matrix = {province: []}
    state.g_candidate_scores[0, province] = 0
    state.g_candidate_bfs[0, 0, province] = 25

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    # ScoreOrderCandidates_AllPowers iterates the +0x361c round-zero tree,
    # which is distinct from GenerateOrders' g_candidate_scores top-N table.
    assert state.final_score_set[0, province] == 1015


def test_reach_flood_is_type_filtered_and_does_not_expand_empty_frontier():
    state = InnerGameState()
    source, sea, land, empty_tail = 1, 2, 3, 4
    state.valid_provinces = frozenset({source, sea, land, empty_tail})
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.water_provinces = frozenset({sea})
    state.land_provinces = frozenset({source, land, empty_tail})
    state.adj_matrix = {
        source: [sea, land],
        sea: [source],
        land: [source, empty_tail],
        empty_tail: [land],
    }

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    assert state.g_convoy_reach[0, land] == 1
    assert state.g_convoy_reach[0, sea] == 0
    # Albert's three rounds revisit actual units; the empty land province is
    # not a generic BFS frontier leading to empty_tail.
    assert state.g_convoy_reach[0, empty_tail] == 0


def test_support_reach_marks_second_leg_supply_center_and_neighbours():
    state = InnerGameState()
    source, first, supply_center, neighbour = 1, 2, 3, 4
    state.valid_provinces = frozenset(
        {source, first, supply_center, neighbour}
    )
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.land_provinces = state.valid_provinces
    state.sc_provinces = {supply_center}
    state.adj_matrix = {
        source: [first],
        first: [source, supply_center],
        supply_center: [first, neighbour],
        neighbour: [supply_center],
    }

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    assert state.g_support_reach[0, supply_center] == 1
    assert state.g_support_reach[0, first] == 1
    assert state.g_support_reach[0, neighbour] == 1


def test_target_classification_walks_empty_non_supply_provinces():
    state = InnerGameState()
    province = 10
    state.valid_provinces = frozenset({province})
    state.land_provinces = state.valid_provinces
    state.adj_matrix = {province: []}
    state.g_own_reach_score[0, province] = 1

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    assert state.g_prov_target_flag[0, province] == 1


def test_target_classification_uses_own_reach_and_unit_presence():
    state = InnerGameState()
    province = 10
    state.valid_provinces = frozenset({province})
    state.land_provinces = state.valid_provinces
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 0
    state.adj_matrix = {province: []}
    state.g_sc_ownership[0, province] = 1
    state.g_own_reach_score[0, province] = 2

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    assert state.g_prov_target_flag[0, province] == 2


def test_target_classification_rejects_contested_empty_province():
    state = InnerGameState()
    province = 10
    state.valid_provinces = frozenset({province})
    state.land_provinces = state.valid_provinces
    state.adj_matrix = {province: []}
    state.g_own_reach_score[0, province] = 1
    state.g_total_reach_score[0, province] = 1

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    assert state.g_prov_target_flag[0, province] == 0


def test_threatening_power_score_uses_supply_centres_not_unit_count():
    state = InnerGameState()
    target, enemy_source = 10, 11
    state.adj_matrix = {
        target: [enemy_source],
        enemy_source: [target],
    }
    state.unit_info = {
        enemy_source: {'power': 1, 'type': 'A', 'coast': ''},
    }
    state.g_enemy_presence[0, enemy_source] = 1
    state.g_sc_ownership[1, enemy_source] = 1
    state.sc_count[1] = 12

    assert state.get_max_threatening_adj_scs(target, 0) == 12
    assert _scoring_mod.evaluate_province_score(state, target, 0) == 74


def test_threatening_fleet_reach_uses_its_live_source_coast():
    target, fleet_source, north_only = 10, 11, 12
    state = InnerGameState()
    state.adj_matrix = {
        target: [fleet_source],
        fleet_source: [target, north_only],
        north_only: [fleet_source],
    }
    state.fleet_adj_matrix = {
        fleet_source: [target, north_only],
    }
    state.fleet_coast_adj = {
        (fleet_source, '/NC'): [north_only],
        (fleet_source, '/SC'): [target],
    }
    state.unit_info = {
        fleet_source: {'power': 1, 'type': 'F', 'coast': '/NC'},
    }
    state.g_enemy_presence[0, fleet_source] = 1
    state.sc_count[1] = 12

    assert state.get_max_threatening_adj_scs(target, 0) == 0

    state.unit_info[fleet_source]['coast'] = '/SC'
    assert state.get_max_threatening_adj_scs(target, 0) == 12


def test_own_power_scoring_uses_token_channel_attack_term_and_int_division():
    state = InnerGameState()
    army_province, fleet_province = 10, 11
    state.g_season = 'WIN'
    state.g_adjustment_candidate_provinces = {
        army_province, fleet_province,
    }
    state.g_adjustment_build_candidates = [
        {'province': army_province, 'unit_type': 'AMY', 'coast': ''},
        {'province': fleet_province, 'unit_type': 'FLT', 'coast': ''},
    ]
    state.g_candidate_bfs[0, 0, army_province] = 10
    state.g_candidate_bfs[0, 0, fleet_province] = 99
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, fleet_province] = 20
    state.g_attack_count[0, army_province] = 3

    score_order_candidates_own_power(
        state,
        [2] + [0] * 9,
        0,
        attack_weight=4,
    )

    # Raw AMY = 10*2 + 3*4 = 32; raw FLT = 20*2 = 40. Signed C
    # normalization produces 800 and 1000 respectively. The provinces differ,
    # so the army dithering pass does not alter either value.
    assert state.g_adjustment_candidate_scores == {
        (army_province, 'AMY', ''): 800.0,
        (fleet_province, 'FLT', ''): 1000.0,
    }


def test_own_power_scoring_shares_province_max_across_army_and_fleet_keys():
    state = InnerGameState()
    province = 10
    state.g_season = 'WIN'
    state.g_adjustment_candidate_provinces = {province}
    state.g_adjustment_build_candidates = [
        {'province': province, 'unit_type': 'AMY', 'coast': ''},
        {'province': province, 'unit_type': 'FLT', 'coast': ''},
    ]
    state.g_candidate_bfs[0, 0, province] = 5
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, province] = 20

    score_order_candidates_own_power(state, [1], 0)

    # AMY normalizes to 250, FLT to 1000, then C's army-only third pass
    # replaces the army value with the difference from the shared maximum.
    assert state.g_adjustment_candidate_scores == {
        (province, 'AMY', ''): 750.0,
        (province, 'FLT', ''): 1000.0,
    }


def test_own_power_scoring_keeps_large_normalization_in_integer_space():
    state = InnerGameState()
    lower, higher = 10, 11
    state.g_season = 'WIN'
    state.g_adjustment_candidate_provinces = {lower, higher}
    state.g_adjustment_build_candidates = [
        {'province': lower, 'unit_type': 'FLT', 'coast': ''},
        {'province': higher, 'unit_type': 'FLT', 'coast': ''},
    ]
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, lower] = 2**60 + 1
    state._bfs_flt[0, 0, higher] = 2**60 + 3

    score_order_candidates_own_power(state, [1], 0)

    # A binary-float quotient rounds both operands to the same value and
    # incorrectly yields 1000. C's __alldiv result is exactly 999.
    assert state.g_adjustment_candidate_scores[
        (lower, 'FLT', '')
    ] == 999.0


def test_own_power_remove_scoring_uses_live_unit_token_channel():
    state = InnerGameState()
    army_province, fleet_province = 10, 11
    state.g_season = 'WIN'
    state.g_adjustment_candidate_provinces = {
        army_province, fleet_province,
    }
    state.unit_info = {
        army_province: {'power': 0, 'type': 'A', 'coast': ''},
        fleet_province: {'power': 0, 'type': 'F', 'coast': ''},
    }
    state.g_candidate_bfs[0, 0, army_province] = 10
    state.g_candidate_bfs[0, 0, fleet_province] = 1
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, fleet_province] = 20

    score_order_candidates_own_power(state, [1], 0)

    assert state.g_candidate_scores[0, army_province] == 500
    assert state.g_candidate_scores[0, fleet_province] == 1000


def test_own_power_scoring_keeps_multi_coast_keys_distinct():
    state = InnerGameState()
    base, north_coast, south_coast = 10, 110, 111
    state.g_season = 'WIN'
    state.prov_to_id = {
        'STP': base,
        'STP/NC': north_coast,
        'STP/SC': south_coast,
    }
    state.g_adjustment_candidate_provinces = {base}
    state.g_adjustment_build_candidates = [
        {'province': base, 'unit_type': 'FLT', 'coast': '/NC'},
        {'province': base, 'unit_type': 'FLT', 'coast': '/SC'},
    ]
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, north_coast] = 10
    state._bfs_flt[0, 0, south_coast] = 20

    score_order_candidates_own_power(state, [1], 0)

    assert state.g_adjustment_candidate_scores == {
        (base, 'FLT', '/NC'): 500.0,
        (base, 'FLT', '/SC'): 1000.0,
    }


def test_winter_occupied_center_penalty_matches_unit_token_channel():
    province = 10

    def scored_state(unit_type):
        state = InnerGameState()
        state.valid_provinces = frozenset({province})
        state.sc_provinces = {province}
        state.land_provinces = frozenset()
        state.water_provinces = frozenset()
        state.adj_matrix = {province: []}
        state.fleet_adj_matrix = {province: []}
        state.g_board_sc_ownership[0, province] = 1
        state.g_sc_owner[province] = 0
        state.home_centers = {0: frozenset({province})}
        state.sc_count[0] = 1
        state.g_season = 'WIN'
        state.unit_info = {
            province: {
                'power': 0,
                'type': unit_type,
                'coast': '',
            },
        }
        score_provinces(
            state, move_weight=0, build_weight=100, own_power=0
        )
        return state

    army_state = scored_state('A')
    # An evaluated own centre skips fallback Adjustment 9. Its uncontested
    # influence score is 10, and only the live AMY key receives -2500.
    assert army_state.g_candidate_bfs[0, 0, province] == -1500
    assert army_state._bfs_flt[0, 0, province] == 1000

    fleet_state = scored_state('F')
    # The same score applies to an evaluated fleet-held centre; only the live
    # FLT key is reduced.
    assert fleet_state.g_candidate_bfs[0, 0, province] == 1000
    assert fleet_state._bfs_flt[0, 0, province] == -1500


def test_winter_penalty_only_touches_occupying_fleet_coast_key():
    base, north_coast, south_coast = 10, 110, 111
    state = InnerGameState()
    state.valid_provinces = frozenset({base, north_coast, south_coast})
    state.sc_provinces = {base}
    state.land_provinces = frozenset()
    state.water_provinces = frozenset()
    state.coast_variants = {base: (north_coast, south_coast)}
    state.prov_to_id = {
        'STP': base,
        'STP/NC': north_coast,
        'STP/SC': south_coast,
    }
    state.adj_matrix = {base: [], north_coast: [], south_coast: []}
    state.fleet_adj_matrix = {
        base: [], north_coast: [], south_coast: [],
    }
    state.g_board_sc_ownership[0, base] = 1
    state.g_sc_owner[base] = 0
    state.home_centers = {0: frozenset({base})}
    state.sc_count[0] = 1
    state.g_season = 'WIN'
    state.unit_info = {
        base: {'power': 0, 'type': 'F', 'coast': '/SC'},
    }

    score_provinces(state, move_weight=0, build_weight=100, own_power=0)

    assert state._bfs_flt[0, 0, north_coast] == 1000
    assert state._bfs_flt[0, 0, south_coast] == -1500
    assert state._bfs_flt[0, 0, base] == 1000


def test_build_pending_seed_uses_home_control_not_occupying_unit():
    province = 10

    def scored_state(controller):
        state = InnerGameState()
        state.valid_provinces = frozenset({province})
        state.sc_provinces = {province}
        state.land_provinces = frozenset({province})
        state.adj_matrix = {province: []}
        state.home_centers = {0: frozenset({province})}
        state.g_sc_owner[province] = controller
        state.g_board_sc_ownership[max(controller, 0), province] = 1
        score_provinces(
            state, move_weight=1, build_weight=1, own_power=0
        )
        return state

    # Retaining any home centre blocks the seed even when no unit occupies it.
    assert scored_state(0).g_build_order_pending[0, province] == 0
    # Losing every home centre seeds the static home, not the current holding.
    assert scored_state(1).g_build_order_pending[0, province] == 600


def test_foreign_controlled_center_is_not_scored_as_neutral_when_empty():
    province = 10
    def scored(controller_centers):
        state = InnerGameState()
        state.valid_provinces = frozenset({province})
        state.sc_provinces = {province}
        state.land_provinces = frozenset({province})
        state.adj_matrix = {province: []}
        state.g_sc_owner[province] = 1
        state.g_board_sc_ownership[1, province] = 1
        state.sc_count[0] = 3
        state.sc_count[1] = controller_centers
        score_provinces(state, move_weight=1, build_weight=1, own_power=0)
        # Adjustments 4-9 write g_BuildOrderPending (DAT_006190e8), not
        # g_AttackCount (DAT_006040e8) -- see the disassembly note in
        # score_provinces.  Only the EvaluateProvinceScore path writes
        # g_AttackCount.
        return state.g_build_order_pending[0, province]

    # C carries the SCO controller (power 1) through this branch. With zero
    # trust it scores 10; treating the empty center as UNO would yield 75.
    # The bump applies only when the controller's center ratio is at most 12%,
    # and 0044906a shows it is ADD ...,0x14 (+20), not +5.
    assert scored(3) == 10
    assert scored(2) == 30


def test_own_controlled_center_uses_foreign_designation_as_effective_power():
    province = 10
    state = InnerGameState()
    state.valid_provinces = frozenset({province})
    state.sc_provinces = {province}
    state.land_provinces = frozenset({province})
    state.g_sc_owner[province] = 0
    state.sc_count[:2] = [3, 3]
    state.g_ally_designation_a[province] = 1
    state.g_ally_designation_a_hi[province] = 0

    score_provinces(state, move_weight=1, build_weight=1, own_power=0)

    # The recovered fallback keeps designation A when the SCO controller is
    # own but the designation names a foreign power. No live unit is needed
    # to exercise that distinct source channel.  Adjustment 5 writes
    # g_BuildOrderPending, not g_AttackCount.
    assert state.g_build_order_pending[0, province] == 10


def test_round_nine_preserves_the_early_home_seed_and_selective_clear():
    home, frontier, neutral_center = 10, 11, 12
    state = InnerGameState()
    state.valid_provinces = frozenset({home, frontier, neutral_center})
    state.land_provinces = state.valid_provinces
    state.sc_provinces = {home, neutral_center}
    state.home_centers = {0: frozenset({home})}
    state.g_sc_owner[home] = 0
    state.g_board_sc_ownership[0, home] = 1
    state.adj_matrix = {
        home: [frontier],
        frontier: [home, neutral_center],
        neutral_center: [frontier],
    }

    # An empty own home takes the non-EvaluateProvinceScore path, so its
    # Adjustment 9 value lands in g_BuildOrderPending, which the BFS seed
    # multiplies by move_weight (00449973-004499ac).  Weight that channel.
    # Rounds 0-8 are reseeded from the main scores; an empty own home's
    # Adjustment 9 value rides move_weight.  Round 9 is preserved from the
    # early home-centre epoch, which is seeded from g_AttackCount and rides
    # build_weight.  Both channels must be weighted to exercise both.
    score_provinces(
        state, move_weight=100_000, build_weight=100_000, own_power=0
    )

    # Phase 5 recomputes rounds 0-8 from the main attack scores but preserves
    # round 9 from the early home-only epoch. The safe home key is cleared;
    # the frontier key remains because it borders an uncontrolled centre.
    assert state.g_candidate_bfs[0, 8, home] > 0
    assert state.g_candidate_bfs[0, 9, home] == 0
    assert state.g_candidate_bfs[0, 9, frontier] > 0


def test_support_destination_lookup_uses_moving_units_key_channel():
    state = InnerGameState()
    source, destination = 20, 21
    state.unit_info = {
        source: {'power': 0, 'type': 'F', 'coast': ''},
    }
    state.adj_matrix = {source: [destination], destination: [source]}
    state.fleet_adj_matrix = {source: [destination]}
    state.sc_provinces = set()
    state.final_score_set[0, destination] = 100
    state.final_score_set_flt[0, source] = 20
    state.final_score_set_flt[0, destination] = 10

    assign_support_order(state, 0, source, destination, 0)

    # 20 * .85 is not below the fleet destination score 10, so the support
    # score remains unset. Selecting the empty destination's default AMY
    # channel (100) would incorrectly take this branch.
    assert state.g_order_table[source, 18] == 0


def test_support_opportunity_filters_every_triangle_leg_by_unit_type():
    state = InnerGameState()
    source, target, supporter = 10, 11, 12
    state.unit_info = {
        source: {'power': 0, 'type': 'F', 'coast': ''},
    }
    # Province adjacency closes a triangle, but its target-supporter and
    # supporter-source edges are land-only and therefore unavailable to the
    # fleet token carried through the C adjacency walk.
    state.adj_matrix = {
        source: [target, supporter],
        target: [source, supporter],
        supporter: [source, target],
    }
    state.fleet_adj_matrix = {
        source: [target],
        target: [source],
        supporter: [],
    }
    state.g_top_reach_flag[target] = 1
    state.g_sc_ownership[0, target] = 1
    state.g_sc_ownership[0, supporter] = 1
    state.final_score_set_flt[0, target] = 75
    state.g_max_prov_score_per_power[0, target] = 75
    state.g_max_province_score[target] = 75

    build_support_opportunities(state)

    assert state.g_support_opportunities_set == []


def test_support_opportunity_record_uses_current_powers_province_maximum():
    state = InnerGameState()
    source, target, supporter = 10, 11, 12
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
        target: {'power': 0, 'type': 'A', 'coast': ''},
        supporter: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.land_provinces = frozenset({source, target, supporter})
    state.adj_matrix = {
        source: [target, supporter],
        target: [source, supporter],
        supporter: [source, target],
    }
    state.g_top_reach_flag[target] = 1
    state.g_sc_ownership[0, target] = 1
    state.g_sc_ownership[0, supporter] = 1
    state.final_score_set[0, target] = 75
    state.g_max_prov_score_per_power[0, target] = 75
    # A different power can make the 1-D compatibility maximum much larger;
    # that value is not stored in this power's C support-ring record.
    state.g_max_province_score[target] = 999

    build_support_opportunities(state)

    assert state.g_support_opportunities_set
    assert {
        opportunity['score']
        for opportunity in state.g_support_opportunities_set
    } == {75.0}


def test_support_opportunity_uses_each_ring_units_movement_type():
    state = InnerGameState()
    source, target, sea = 10, 11, 12
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
        target: {'power': 0, 'type': 'F', 'coast': ''},
        sea: {'power': 0, 'type': 'F', 'coast': ''},
    }
    # A source→coastal target, F target→sea, F sea→coastal source.
    state.adj_matrix = {
        source: [target, sea],
        target: [source, sea],
        sea: [source, target],
    }
    state.fleet_adj_matrix = {
        source: [],
        target: [sea],
        sea: [source],
    }
    state.water_provinces = frozenset({sea})
    state.g_top_reach_flag[target] = 1
    state.g_sc_ownership[0, target] = 1
    state.g_sc_ownership[0, sea] = 1
    state.final_score_set[0, target] = 75
    state.g_max_prov_score_per_power[0, target] = 75

    build_support_opportunities(state)

    assert any(
        opportunity['mover_prov'] == source
        and opportunity['target_prov'] == target
        and opportunity['supporter_prov'] == sea
        for opportunity in state.g_support_opportunities_set
    )


def test_support_opportunity_preserves_each_ring_edge_coast_token():
    state = InnerGameState()
    source, target, third = 10, 11, 12
    state.unit_info = {
        source: {'power': 0, 'type': 'F', 'coast': ''},
        target: {'power': 0, 'type': 'F', 'coast': '/NC'},
        third: {'power': 0, 'type': 'F', 'coast': ''},
    }
    state.adj_matrix = {
        source: [target, third],
        target: [source, third],
        third: [source, target],
    }
    state.fleet_adj_matrix = {
        source: [target],
        target: [third],
        third: [source],
    }
    # The destinations of P→Q and Q→R are multi-coast provinces. Reverse
    # coast lookup supplies the DAIDE coast tokens retained by the C record.
    state.fleet_coast_adj = {
        (target, '/NC'): [source, third],
        (third, '/SC'): [target],
    }
    state.g_top_reach_flag[target] = 1
    state.g_sc_ownership[0, target] = 1
    state.g_sc_ownership[0, third] = 1
    state.final_score_set_flt[0, target] = 75
    state.g_max_prov_score_per_power[0, target] = 75

    build_support_opportunities(state)

    record = next(
        opportunity
        for opportunity in state.g_support_opportunities_set
        if opportunity['mover_prov'] == source
        and opportunity['target_prov'] == target
        and opportunity['supporter_prov'] == third
    )
    assert record['mover_coast'] == 0x4600
    assert record['target_coast'] == 0x4608
    assert record['supporter_coast'] == 0


def test_threat_path_scans_empty_supply_center_and_uses_shared_key_maximum():
    state = InnerGameState()
    threatened_sc, reachable, tail = 10, 11, 12
    state.valid_provinces = frozenset({threatened_sc, reachable, tail})
    state.sc_provinces = {threatened_sc}
    state.adj_matrix = {
        threatened_sc: [reachable],
        reachable: [threatened_sc, tail],
        tail: [reachable],
    }
    state.g_own_reach_score[0, threatened_sc] = 1
    state.g_sc_ownership[0, reachable] = 1
    state.final_score_set[0, reachable] = 5
    state.final_score_set_flt[0, reachable] = 20
    state.g_max_prov_score_per_power[0, reachable] = 20

    _scoring_mod._populate_threat_path_scores(state)

    # C enters on the SC flag even though the threatened centre is empty, and
    # its token-key loop sees the fleet-channel maximum.
    assert state.g_threat_path_score[0, threatened_sc] == 20


def test_threat_path_rejects_foreign_controlled_adjacent_supply_center():
    state = InnerGameState()
    threatened_sc, adjacent_sc, tail = 10, 11, 12
    state.valid_provinces = frozenset({threatened_sc, adjacent_sc, tail})
    state.sc_provinces = {threatened_sc, adjacent_sc}
    state.g_sc_owner[adjacent_sc] = 1
    state.adj_matrix = {
        threatened_sc: [adjacent_sc],
        adjacent_sc: [threatened_sc, tail],
        tail: [adjacent_sc],
    }
    state.g_own_reach_score[0, threatened_sc] = 1
    state.g_sc_ownership[0, adjacent_sc] = 1
    state.g_max_prov_score_per_power[0, adjacent_sc] = 99

    _scoring_mod._populate_threat_path_scores(state)

    assert state.g_threat_path_score[0, threatened_sc] == 0
