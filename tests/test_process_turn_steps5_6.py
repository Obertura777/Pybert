"""Regression tests for ProcessTurn post-processing steps 5 and 6."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_trial = __import__(
    f"{_pkg_name}.monte_carlo.trial",
    fromlist=[
        "_dedupe_step5_fleet_candidates",
        "_apply_step6_target_filter",
        "_post_phase_move_support_allowed",
        "_post_phase_hold_support_allowed",
        "_apply_post_phase_support_sweep",
        "_recompute_trial_support_demand",
        "_candidate_tree_score",
        "_apply_step1_source_dedup",
        "_resolve_own_occupied_destination",
    ],
)

InnerGameState = _state.InnerGameState
_dedupe_step5_fleet_candidates = _trial._dedupe_step5_fleet_candidates
_apply_step6_target_filter = _trial._apply_step6_target_filter
_post_phase_move_support_allowed = _trial._post_phase_move_support_allowed
_post_phase_hold_support_allowed = _trial._post_phase_hold_support_allowed
_apply_post_phase_support_sweep = _trial._apply_post_phase_support_sweep
_recompute_trial_support_demand = _trial._recompute_trial_support_demand
_candidate_tree_score = _trial._candidate_tree_score
_apply_step1_source_dedup = _trial._apply_step1_source_dedup
_resolve_own_occupied_destination = (
    _trial._resolve_own_occupied_destination
)


POWER = 2
SOURCE = 10
DEST = 20


def test_step5_stably_deduplicates_current_fleets_destinations():
    candidates = [(100.0, DEST), (90.0, 30), (80.0, DEST), (70.0, 30)]

    assert _dedupe_step5_fleet_candidates(candidates) == [
        (100.0, DEST),
        (90.0, 30),
    ]


def test_step6_removes_class1_candidate_below_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(99.0, DEST)], 100.0
    ) == []


def test_step6_removes_class2_candidate_below_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 2

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(99.0, DEST)], 100.0
    ) == []


def test_step6_keeps_candidate_at_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(100.0, DEST)], 100.0
    ) == [(100.0, DEST)]


def test_step6_nonzero_companion_marker_bypasses_filter():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1
    state.g_target_flag2[POWER, DEST] = -1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == [(1.0, DEST)]


def test_step6_registered_convoy_adjacent_destination_is_exception():
    state = InnerGameState()
    state.adj_matrix[SOURCE] = [DEST]
    state.g_prov_target_flag[POWER, DEST] = 2
    state.g_province_score_trial[DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == [(1.0, DEST)]


def test_step6_registered_nonadjacent_destination_is_removed():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1
    state.g_province_score_trial[DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == []


def test_post_phase_support_accepts_incoming_equal_to_demand():
    state = InnerGameState()
    state.g_order_table[DEST, 13] = 1
    state.g_support_demand[DEST] = 1

    assert _post_phase_move_support_allowed(state, POWER, DEST, 0)


def test_post_phase_support_second_pass_uses_total_reach_pair():
    state = InnerGameState()
    state.g_order_table[DEST, 13] = 2
    state.g_support_demand[DEST] = 1
    state.g_total_reach_score[POWER, DEST] = 1

    assert not _post_phase_move_support_allowed(state, POWER, DEST, 0)
    assert _post_phase_move_support_allowed(state, POWER, DEST, 1)


def test_post_phase_support_does_not_alias_target_flag_high_word():
    state = InnerGameState()
    state.g_order_table[DEST, 13] = 2
    state.g_support_demand[DEST] = 1
    state.g_attack_count2[POWER, DEST] = 1

    assert not _post_phase_move_support_allowed(state, POWER, DEST, 1)


def test_post_phase_support_rejects_terminal_assignment():
    state = InnerGameState()
    state.g_order_table[DEST, 20] = 2
    state.g_support_demand[DEST] = 1

    assert not _post_phase_move_support_allowed(state, POWER, DEST, 0)


def test_post_phase_hold_support_requires_strictly_unmet_demand():
    state = InnerGameState()
    state.g_order_table[DEST, 13] = 1
    state.g_support_demand[DEST] = 1

    assert not _post_phase_hold_support_allowed(state, POWER, DEST, 0)

    state.g_support_demand[DEST] = 2
    assert _post_phase_hold_support_allowed(state, POWER, DEST, 0)


def test_post_phase_hold_support_second_pass_uses_total_reach_pair():
    state = InnerGameState()
    state.g_order_table[DEST, 13] = 1
    state.g_support_demand[DEST] = 1
    state.g_total_reach_score[POWER, DEST] = 1

    assert not _post_phase_hold_support_allowed(state, POWER, DEST, 0)
    assert _post_phase_hold_support_allowed(state, POWER, DEST, 1)


def test_post_phase_sweep_emits_support_to_own_nonmoving_unit():
    state = InnerGameState()
    state.unit_info = {
        SOURCE: {'power': POWER, 'type': 'F', 'coast': ''},
        DEST: {'power': POWER, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {SOURCE: [DEST], DEST: []}
    state.fleet_adj_matrix = {SOURCE: [DEST]}
    state.g_sc_ownership[POWER, SOURCE] = 1
    state.g_sc_ownership[POWER, DEST] = 1
    state.g_order_table[SOURCE, 0] = 1
    state.g_order_table[DEST, 0] = 1
    state.g_order_table[DEST, 13] = 1
    state.g_support_demand[DEST] = 1
    state.g_total_reach_score[POWER, DEST] = 1
    state.final_score_set_flt[POWER, DEST] = 100

    _apply_post_phase_support_sweep(state, POWER)

    assert int(state.g_order_table[SOURCE, 0]) == 3
    assert int(state.g_order_table[SOURCE, 2]) == DEST


def test_post_phase_sweep_can_promote_pending_support_assignment_to_move():
    state = InnerGameState()
    mover = 30
    assigned = 40
    state.unit_info = {
        SOURCE: {'power': POWER, 'type': 'F', 'coast': ''},
    }
    state.adj_matrix = {SOURCE: [DEST]}
    state.fleet_adj_matrix = {SOURCE: [DEST]}
    state.g_order_table[SOURCE, 0] = 1
    state.g_order_table[SOURCE, 13] = 1
    state.g_order_table[DEST, 20] = 1
    state.g_support_demand[SOURCE] = 1
    state.g_support_demand[DEST] = 1
    state.g_convoy_source_prov[DEST] = assigned
    state.g_convoy_dst_to_src[DEST] = mover
    state.final_score_set_flt[POWER, DEST] = 100
    state.g_move_history_matrix[POWER, SOURCE, DEST] = 77
    original_randint = _trial.random.randint
    _trial.random.randint = lambda _lo, _hi: 61 * 0x17
    try:
        _apply_post_phase_support_sweep(state, POWER)
    finally:
        _trial.random.randint = original_randint

    assert int(state.g_order_table[SOURCE, 0]) == 2
    assert int(state.g_order_table[SOURCE, 2]) == DEST
    assert int(state.g_order_table[SOURCE, 3]) == 0x4201
    assert int(state.g_order_table[DEST, 20]) == 2
    assert int(state.g_order_table[SOURCE, 20]) == 5
    assert int(state.g_order_table[assigned, 20]) == 5
    # This source path does not execute BuildOrder_MTO's move-history tail.
    assert int(state.g_order_table[DEST, 17]) == 0
    assert state.g_convoy_dst_to_src[DEST] == SOURCE
    assert DEST in state.g_convoy_dst_list


def test_post_phase_move_support_does_not_apply_public_builder_trust_tail():
    state = InnerGameState()
    mover = 30
    state.unit_info = {
        SOURCE: {'power': POWER, 'type': 'F', 'coast': ''},
        mover: {'power': POWER + 1, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {SOURCE: [DEST], mover: []}
    state.fleet_adj_matrix = {SOURCE: [DEST]}
    state.g_order_table[SOURCE, 0] = 1
    state.g_order_table[SOURCE, 13] = 1
    state.g_support_demand[DEST] = 1
    state.g_convoy_dst_to_src[DEST] = mover
    state.final_score_set_flt[POWER, DEST] = 100
    state.g_support_trust_adj = 77

    _apply_post_phase_support_sweep(state, POWER)

    assert int(state.g_order_table[SOURCE, 0]) == 4
    assert int(state.g_order_table[SOURCE, 1]) == mover
    assert int(state.g_order_table[SOURCE, 2]) == DEST
    assert state.g_support_trust_adj == 77
    assert int(state.g_convoy_active_flag[DEST]) == 0


def test_trial_support_demand_uses_live_proximity_and_hostility_gate():
    state = InnerGameState()
    state.g_coverage_flag[0, DEST] = 3
    state.g_proximity_score[0, DEST] = 1
    state.g_coverage_flag[1, DEST] = 4
    state.g_proximity_score[1, DEST] = -1
    state.g_coverage_flag[POWER, DEST] = 9  # evaluated power is excluded

    # This trusted power is designated at the province, suppressing the third
    # hostility clause once its relation is no longer in the low tier.
    state.g_ally_trust_score[POWER, 1] = 5
    state.g_relation_score[POWER, 1] = 10
    state.g_ally_designation_a[DEST] = POWER
    state.g_ally_designation_a_hi[DEST] = 0

    _recompute_trial_support_demand(state, POWER, 4, DEST + 1)

    assert int(state.g_support_demand[DEST]) == 2
    assert int(state.g_order_table[DEST, 16]) == 2


def test_army_source_candidate_score_uses_sources_trial_marker():
    state = InnerGameState()
    state.final_score_set[POWER, SOURCE] = 100
    state.g_province_score_trial[SOURCE] = 7
    state.g_province_score_trial[DEST] = 99

    assert _candidate_tree_score(state, POWER, SOURCE, 'A') == 107


def test_fleet_candidate_score_does_not_add_army_trial_marker():
    state = InnerGameState()
    state.final_score_set_flt[POWER, SOURCE] = 100
    state.g_province_score_trial[SOURCE] = 7

    assert _candidate_tree_score(state, POWER, SOURCE, 'F') == 100


def test_step1_source_dedup_stops_after_retry_counter_threshold():
    state = InnerGameState()
    state.g_sub_order_map.add(SOURCE)
    candidates = [(100, SOURCE), (90, DEST)]

    state.g_province_base[SOURCE] = 499
    assert _apply_step1_source_dedup(state, SOURCE, candidates) == [
        (90, DEST),
    ]

    state.g_province_base[SOURCE] = 500
    assert _apply_step1_source_dedup(state, SOURCE, candidates) == candidates


def test_step6_class2_pruning_stops_at_retry_counter_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 2
    state.g_province_base[SOURCE] = 5000

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == [(1.0, DEST)]

    # The counter exception is exclusive to the two class-2 source-match
    # branches; class 1 still removes a below-threshold candidate.
    state.g_prov_target_flag[POWER, DEST] = 1
    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == []


def test_own_occupied_tail_supports_pressured_stationary_unit():
    state = InnerGameState()
    state.unit_info = {
        SOURCE: {'power': POWER, 'type': 'A', 'coast': ''},
        DEST: {'power': POWER, 'type': 'A', 'coast': ''},
    }
    state.g_sc_ownership[POWER, DEST] = 1
    state.g_order_table[DEST, 0] = 1
    state.g_order_table[DEST, 13] = 1
    state.g_support_demand[DEST] = 2

    emit, rejected = _resolve_own_occupied_destination(
        state, POWER, SOURCE, DEST
    )

    assert (emit, rejected) == (False, False)
    assert state.g_order_table[SOURCE, 0] == 3
    assert state.g_order_table[SOURCE, 2] == DEST


def test_own_occupied_tail_requeues_unordered_destination_score():
    state = InnerGameState()
    state.g_sc_ownership[POWER, DEST] = 1
    state.g_convoy_fleet_candidates = [(100, DEST)]

    emit, rejected = _resolve_own_occupied_destination(
        state, POWER, SOURCE, DEST
    )

    assert (emit, rejected) == (False, False)
    assert (99, SOURCE) in state.g_convoy_fleet_candidates
    assert state.g_province_base[SOURCE] == 1


def test_own_occupied_tail_rejects_unscored_unordered_destination():
    state = InnerGameState()
    state.g_sc_ownership[POWER, DEST] = 1

    assert _resolve_own_occupied_destination(
        state, POWER, SOURCE, DEST
    ) == (False, True)
