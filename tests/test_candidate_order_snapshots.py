"""Regression tests for complete Monte-Carlo candidate snapshots."""

import os
import sys

import math
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_evaluation = __import__(
    f'{_pkg_name}.monte_carlo.evaluation',
    fromlist=[
        'snapshot_order_entry', 'restore_order_entry', 'candidate_orders_key',
        'evaluate_order_score', 'evaluate_order_proposal',
    ],
)
_trial = __import__(
    f'{_pkg_name}.monte_carlo.trial', fromlist=['_refresh_order_table'])
_analysis = __import__(
    f'{_pkg_name}.bot.analysis',
    fromlist=['_candidate_rank_threshold', '_rank_candidates_for_power'],
)
_primitives = __import__(
    f'{_pkg_name}.heuristics._primitives', fromlist=['_safe_pow'])
_flags = __import__(
    f'{_pkg_name}.monte_carlo._flags', fromlist=['_F_ORDER_TYPE'])

InnerGameState = _state.InnerGameState
snapshot_order_entry = _evaluation.snapshot_order_entry
restore_order_entry = _evaluation.restore_order_entry
candidate_orders_key = _evaluation.candidate_orders_key
evaluate_order_score = _evaluation.evaluate_order_score
evaluate_order_proposal = _evaluation.evaluate_order_proposal
_refresh_order_table = _trial._refresh_order_table
_rank_candidates_for_power = _analysis._rank_candidates_for_power
_candidate_rank_threshold = _analysis._candidate_rank_threshold
_safe_pow = _primitives._safe_pow

_F_ORDER_TYPE = _flags._F_ORDER_TYPE
_F_DEST_PROV = _flags._F_DEST_PROV
_F_SELECTED_SCORE_LO = _flags._F_SELECTED_SCORE_LO
_F_SELECTED_SCORE_HI = _flags._F_SELECTED_SCORE_HI
_F_TARGET_PROV = _flags._F_TARGET_PROV
_F_INCOMING_MOVE = _flags._F_INCOMING_MOVE
_F_MOVE_PROB = _flags._F_MOVE_PROB
_F_UNIT_REACH_SCORE = _flags._F_UNIT_REACH_SCORE
_F_CONVOY_LO = _flags._F_CONVOY_LO
_F_CONVOY_HI = _flags._F_CONVOY_HI
_F_MOVE_HISTORY = _flags._F_MOVE_HISTORY
_F_ORDER_ASGN = _flags._F_ORDER_ASGN
_F_SUP_TARGET = _flags._F_SUP_TARGET
_F_CONVOY_DEPTH = _flags._F_CONVOY_DEPTH
_F_CONVOY_LEG0 = _flags._F_CONVOY_LEG0
_F_CONVOY_LEG1 = _flags._F_CONVOY_LEG1
_F_CONVOY_LEG2 = _flags._F_CONVOY_LEG2
_ORDER_HLD = _flags._ORDER_HLD
_ORDER_MTO = _flags._ORDER_MTO
_ORDER_CTO = _flags._ORDER_CTO


def _rank_record(score, trial_score, final_score, **overrides):
    record = {
        'power': 0,
        'orders': [(score, _ORDER_HLD)],
        'score': score,
        'base_score': score,
        'trial_scores': [trial_score],
        'final_dim_score': final_score,
        'other_score': 0,
        'rank_penalty': 0,
        'min_rank': 10000,
        'max_rank': 0,
        'running_avg': 10000.0,
        'processed': 0,
        'pareto_flag': 0,
        'weight': 0.0,
        'output_score': 0.0,
    }
    record.update(overrides)
    return record


def test_ranker_erases_dominated_node_before_probability_scoring():
    state = InnerGameState()
    state.g_n_trials_completed = 0
    state.g_power_call_count[0] = 1000
    state.g_unit_count[0] = 3
    best = _rank_record(1000, 500, 500)
    dominated = _rank_record(900, 300, 300)
    survivor = _rank_record(800, 450, 450)
    state.g_candidate_record_list = [best, dominated, survivor]

    _rank_candidates_for_power(state, 0)

    assert dominated['pareto_flag'] == 1
    assert dominated['weight'] == 0.0
    assert best['weight'] > 0.0
    assert survivor['weight'] >= 0.0


def test_ranker_other_score_selects_zero_margin_after_one():
    state = InnerGameState()
    state.g_n_trials_completed = 0
    state.g_power_call_count[0] = 1000
    high = _rank_record(1000, 500, 500)
    within_fifty = _rank_record(900, 480, 480, other_score=1)
    zero_margin = _rank_record(800, 480, 470, other_score=2)
    state.g_candidate_record_list = [high, within_fifty, zero_margin]

    _rank_candidates_for_power(state, 0)

    assert within_fifty['pareto_flag'] == 0
    assert zero_margin['pareto_flag'] == 1


def test_ranker_probability_uses_following_adjusted_scores():
    state = InnerGameState()
    state.g_n_trials_completed = 0
    state.g_power_call_count[0] = 1000
    state.g_unit_count[0] = 3
    first = _rank_record(1000, 500, 500)
    second = _rank_record(900, 450, 500)
    state.g_candidate_record_list = [first, second]

    _rank_candidates_for_power(state, 0)

    exponent = 1.8 / 4.0 + 1.75
    neighbour_share = 2400.0 / (_safe_pow(100.0, exponent) + 2500.0 + 2400.0)
    assert math.isclose(first['weight'], 100.0 * (1.0 - neighbour_share))
    assert math.isclose(second['weight'], 100.0 - first['weight'])


def test_ranker_raw_rank_slot_starts_at_one():
    state = InnerGameState()
    state.g_n_trials_completed = 0
    candidate = _rank_record(1000, 500, 500)
    state.g_candidate_record_list = [candidate]

    _rank_candidates_for_power(state, 0)

    assert candidate['min_rank'] == 1
    assert candidate['max_rank'] == 1


def test_ranker_flag_one_zero_trial_threshold_uses_x87_expression():
    state = InnerGameState()
    state.g_n_trials_completed = 0
    state.g_power_call_count[0] = 0
    # Equal final_dim_score values prevent the Pareto inequality from erasing
    # later nodes, leaving the tenth record eligible for Phase 6 retirement.
    candidates = [
        _rank_record(1000 - i, 500 - i, 500)
        for i in range(10)
    ]
    state.g_candidate_record_list = candidates

    _rank_candidates_for_power(state, 0, flag=1)

    # int(1 + 0*(1 - 0/3000)) == 1. The old decompiler approximation
    # (call_count + 3000) incorrectly kept this record unprocessed.
    assert candidates[-1]['processed'] == 1


def test_ranker_flag_one_round_eight_uses_linear_threshold():
    state = InnerGameState()
    state.g_n_trials_completed = 8
    state.g_power_call_count[0] = 100
    candidates = [
        _rank_record(
            1000 - i, 500 - i, 500,
            trial_scores=[500 - i] * 9,
            running_avg=20.0,
        )
        for i in range(10)
    ]
    state.g_candidate_record_list = candidates

    _rank_candidates_for_power(state, 0, flag=1)

    # int(100*0.05 + 5) == 10; after the round-8 EMA the tenth record's
    # running rank is 18, so it retires. The old 500 cutoff did not.
    assert candidates[-1]['processed'] == 1


def test_ranker_flag_one_early_round_threshold_constants():
    # base = int(0.05*1000 + 5) = 55.
    assert _candidate_rank_threshold(1000, 1, 1) == 577
    # Binary-double evaluation lands just below 109 before truncation.
    assert _candidate_rank_threshold(1000, 7, 1) == 108
    assert _candidate_rank_threshold(1000, 8, 1) == 55
    assert _candidate_rank_threshold(1000, 7, 0) == 1001


def test_order_table_layout_keeps_selected_scores_separate_from_convoy_route():
    assert (_F_MOVE_PROB, _F_UNIT_REACH_SCORE) == (4, 21)
    assert (_F_SELECTED_SCORE_LO, _F_SELECTED_SCORE_HI) == (8, 9)
    assert _F_CONVOY_DEPTH == 23
    assert (_F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2) == (26, 27, 28)


def _selected_score_state(history):
    state = InnerGameState()
    province, destination = 10, 11
    state.unit_info = {
        province: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {province: []}
    state.sc_provinces = set()
    state.g_season = 'SPR'
    state.g_attack_history[0, province] = history
    state.g_order_table[province, _F_ORDER_TYPE] = _ORDER_MTO
    state.g_order_table[province, _F_DEST_PROV] = destination
    state.g_order_table[province, _F_SELECTED_SCORE_LO] = 100
    state.g_order_table[province, 18] = -1
    state.g_order_table[province, 19] = -1
    return state, province


def test_spring_high_history_move_clears_selected_score():
    state, province = _selected_score_state(11)
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 0


def test_spring_low_history_move_keeps_selected_score():
    state, province = _selected_score_state(10)
    # Province-record byte +3 is the SC flag. A non-SC source reaches C's
    # history gate even in Spring.
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 100


def test_negative_signed_history_keeps_selected_score():
    state, province = _selected_score_state(-1)
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 100


def test_positive_high_dword_history_clears_selected_score():
    state, province = _selected_score_state(1 << 32)
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 0


def test_spring_sc_source_clears_selected_score_even_with_low_history():
    state, province = _selected_score_state(10)
    state.sc_provinces.add(province)
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 0


def test_fall_sc_move_keeps_selected_score_on_narrow_validity_path():
    state, province = _selected_score_state(10)
    destination = int(state.g_order_table[province, _F_DEST_PROV])
    state.g_season = 'FAL'
    state.sc_provinces.update({province, destination})
    state.g_order_table[province, _F_TARGET_PROV] = 1
    state.g_order_table[destination, _F_TARGET_PROV] = 2
    state.g_order_table[destination, _F_INCOMING_MOVE] = 1
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 100


def test_fall_sc_move_treats_negative_signed_attack_count_as_unopposed():
    state, province = _selected_score_state(11)
    destination = int(state.g_order_table[province, _F_DEST_PROV])
    state.g_season = 'FAL'
    state.sc_provinces.add(destination)
    state.g_attack_count[0, destination] = -1
    evaluate_order_score(0, state)
    assert state.g_order_table[province, _F_SELECTED_SCORE_LO] == 100


def test_support_demand_is_live_order_table_field_15_view():
    state = InnerGameState()
    state.g_support_demand[11] = 3
    assert state.g_order_table[11, _F_TARGET_PROV] == 3
    state.g_order_table[12, _F_TARGET_PROV] = 4
    assert state.g_support_demand[12] == 4


def test_move_probability_and_unit_reach_are_live_table_views():
    state = InnerGameState()
    state.g_unit_move_prob[7] = 0.25
    state.g_unit_reach_score[8] = 0.5
    state.g_convoy_chain_score[9] = 12
    state.g_order_score_hi[9] = 1
    state.g_cut_support_risk[10] = -0.5
    state.g_fleet_support_score[11] = 7
    assert state.g_order_table[7, _F_MOVE_PROB] == 0.25
    assert state.g_order_table[8, _F_UNIT_REACH_SCORE] == 0.5
    assert tuple(state.g_order_table[9, 6:8]) == (12, 1)
    assert state.g_order_table[10, 22] == -0.5
    assert state.g_order_table[11, 24] == 7


def test_pass_a_fallback_compares_own_reach_to_field_15_not_ally_reach():
    state = InnerGameState()
    province = 10
    state.g_own_reach_score[0, province] = 2
    state.g_ally_reach_score[0, province] = 100
    state.g_order_table[province, _F_INCOMING_MOVE] = 0
    state.g_order_table[province, _F_TARGET_PROV] = 3
    state.g_order_table[province, _F_SUP_TARGET] = -1
    state.g_order_table[province, _F_SUP_TARGET + 1] = -1

    evaluate_order_score(0, state)

    # own reach 2 < field15 3, unoccupied/no enemy: C's fallback is 0.25.
    assert state.g_order_table[province, _F_MOVE_PROB] == 0.25


def test_pass_a_fallback_negates_per_power_max_score_pair():
    state = InnerGameState()
    province = 10
    state.g_own_reach_score[0, province] = 4
    state.g_order_table[province, _F_INCOMING_MOVE] = 0
    state.g_order_table[province, _F_TARGET_PROV] = 3
    state.g_order_table[province, _F_SUP_TARGET] = -1
    state.g_order_table[province, _F_SUP_TARGET + 1] = -1
    state.g_max_province_score[province] = 999
    state.g_max_prov_score_per_power[0, province] = 37

    evaluate_order_score(0, state)

    assert state.g_order_table[province, _F_MOVE_PROB] == 1.0
    assert state.g_order_table[province, _F_CONVOY_LO] == -37
    assert state.g_order_table[province, _F_CONVOY_HI] == 0


def test_pass_a_main_complex_path_matches_decompiled_formula():
    state = InnerGameState()
    province = 10
    state.sc_provinces.add(province)
    state.g_own_reach_score[0, province] = 1
    state.g_order_table[province, _F_ORDER_TYPE] = 2
    state.g_order_table[province, _F_DEST_PROV] = 11
    state.g_order_table[province, _F_INCOMING_MOVE] = 1
    state.g_order_table[province, _F_INCOMING_MOVE + 1] = 2
    state.g_order_table[province, _F_TARGET_PROV] = 3
    state.g_order_table[province, _F_MOVE_HISTORY] = 10
    state.g_order_table[11, _F_TARGET_PROV] = 1

    evaluate_order_score(0, state)

    # pow(10 / 10, 0.3)*0.1 + (1-1)*0.25 + 2*0.15
    assert math.isclose(state.g_order_table[province, _F_MOVE_PROB], 0.4)


def test_pass_a_main_simple_path_uses_supply_center_offset():
    state = InnerGameState()
    province = 10
    state.sc_provinces.add(province)
    state.g_own_reach_score[0, province] = 1
    state.g_order_table[province, _F_ORDER_TYPE] = 1  # excluded from complex path
    state.g_order_table[province, _F_INCOMING_MOVE] = 1
    state.g_order_table[province, _F_TARGET_PROV] = 3

    evaluate_order_score(0, state)

    # (incoming-1)*0.3 + SC offset .15 + field14(0)*.25
    assert math.isclose(state.g_order_table[province, _F_MOVE_PROB], 0.15)


def test_pass_a_main_non_sc_complex_path_includes_field_14_term():
    state = InnerGameState()
    province = 10
    state.g_own_reach_score[0, province] = 1
    state.g_order_table[province, _F_ORDER_TYPE] = 2
    state.g_order_table[province, _F_DEST_PROV] = 11
    state.g_order_table[province, _F_INCOMING_MOVE] = 1
    state.g_order_table[province, _F_INCOMING_MOVE + 1] = 2
    state.g_order_table[province, _F_TARGET_PROV] = 3
    state.g_order_table[province, _F_MOVE_HISTORY] = 10
    state.g_order_table[11, _F_TARGET_PROV] = 1

    evaluate_order_score(0, state)

    # pow(10/10,.3)*.15 + .1 + (1-1)*.25 + field14(2)*.15
    assert math.isclose(state.g_order_table[province, _F_MOVE_PROB], 0.55)


def test_pass_b_relaxes_move_probability_to_destination_probability():
    state = InnerGameState()
    source, destination = 10, 11
    state.g_order_table[source, _F_ORDER_TYPE] = 2
    state.g_order_table[source, _F_DEST_PROV] = destination
    state.g_order_table[source, _F_INCOMING_MOVE] = 1
    state.g_order_table[source, _F_ORDER_ASGN] = 0
    state.g_order_table[source, _F_MOVE_PROB] = 0.8
    state.g_order_table[source, _F_SUP_TARGET + 1] = 0
    state.g_order_table[destination, _F_INCOMING_MOVE] = 1
    state.g_order_table[destination, _F_TARGET_PROV] = 1
    state.g_order_table[destination, _F_MOVE_PROB] = 0.4

    evaluate_order_score(0, state)

    assert state.g_order_table[source, _F_MOVE_PROB] == 0.4


def test_pass_b_negative_score_fallback_copies_destination_probability():
    state = InnerGameState()
    source, destination = 10, 11
    state.g_order_table[source, _F_ORDER_TYPE] = 2
    state.g_order_table[source, _F_DEST_PROV] = destination
    state.g_order_table[source, _F_INCOMING_MOVE] = 0
    state.g_order_table[source, _F_TARGET_PROV] = 1
    state.g_order_table[source, _F_CONVOY_LO] = -10
    state.g_order_table[source, _F_MOVE_PROB] = 0.8
    state.g_order_table[destination, _F_INCOMING_MOVE] = 1
    state.g_order_table[destination, _F_TARGET_PROV] = 1
    state.g_order_table[destination, _F_MOVE_PROB] = 0.25

    evaluate_order_score(0, state)

    assert state.g_order_table[source, _F_MOVE_PROB] == 0.25


def test_fleet_score_pass_uses_sea_incoming_rows_and_home_center_discount():
    state = InnerGameState()
    sea, neutral_adj, home_adj = 10, 11, 12
    state.water_provinces = frozenset({sea})
    state.fleet_adj_matrix = {sea: [neutral_adj, home_adj]}
    state.home_centers = {0: frozenset({home_adj})}
    state.g_order_table[sea, _F_INCOMING_MOVE] = 1
    state.g_order_table[sea, _F_MOVE_PROB] = 0.8
    state.g_order_table[sea, _F_CONVOY_LO] = 100

    evaluate_order_score(0, state)

    # 0.8 is capped to 0.5: 100*.5*.2 = 10, with 0.75 home discount.
    assert state.g_fleet_support_score[neutral_adj] == 10
    assert state.g_fleet_support_score[home_adj] == 7.5


def test_cut_support_pass_keeps_own_sum_above_one_positive():
    state = InnerGameState()
    province, adj_a, adj_b = 10, 11, 12
    state.unit_info[province] = {'power': 0, 'type': 'A', 'coast': ''}
    state.adj_matrix = {province: [adj_a, adj_b]}
    state.g_order_table[province, _F_INCOMING_MOVE] = 1
    state.g_order_table[province, _F_TARGET_PROV] = 3
    state.g_order_table[adj_a, _F_UNIT_REACH_SCORE] = 1
    state.g_order_table[adj_b, _F_UNIT_REACH_SCORE] = 1

    evaluate_order_score(0, state)

    assert state.g_cut_support_risk[province] == 1


def test_cut_support_pass_uses_evaluated_power_enemy_reach_row():
    state = InnerGameState()
    province, adjacent = 10, 11
    state.unit_info[province] = {'power': 1, 'type': 'A', 'coast': ''}
    state.adj_matrix = {province: [adjacent]}
    state.g_order_table[province, _F_INCOMING_MOVE] = 2
    state.g_enemy_reach_score[0, adjacent] = 1
    state.g_enemy_reach_score[1, adjacent] = 0

    evaluate_order_score(0, state)

    # The direct +1 reaches the threshold but produces no excess contribution.
    assert state.g_cut_support_risk[province] == 0


def test_pass_c_writes_field_21_without_overwriting_move_probability():
    state = InnerGameState()
    province = 10
    state.g_order_table[province, _F_MOVE_PROB] = 0.75
    state.g_threat_level[0, province] = 2
    state.g_enemy_presence[0, province] = 1
    state.g_order_table[province, _F_INCOMING_MOVE] = 0

    evaluate_order_score(0, state)

    assert state.g_order_table[province, _F_MOVE_PROB] == 0.75
    assert state.g_order_table[province, _F_UNIT_REACH_SCORE] == 0.1


def test_safe_pow_saturates_positive_overflow_like_c_float_math():
    assert math.isinf(_safe_pow(100.0, 1000.0))


def test_accepted_proposal_counter_increments_inside_duplicate_gate():
    state = InnerGameState()

    evaluate_order_proposal(state, 0)
    evaluate_order_proposal(state, 0)

    assert state.g_power_call_count.tolist() == [1, 0, 0, 0, 0, 0, 0]
    assert len(state.g_candidate_record_list) == 1
    candidate = state.g_candidate_record_list[0]
    assert candidate['trial_scores'] == [0.0] * 30
    assert candidate['final_dim_score'] == 0
    assert candidate['min_rank'] == 10000
    assert candidate['running_avg'] == 10000.0


def _entry(prov, order_type, dest=0):
    row = [0.0] * 30
    row[_F_ORDER_TYPE] = order_type
    row[_F_DEST_PROV] = dest
    return (prov, order_type, dest, 0, 0, tuple(row))


def test_refresh_slots_preserve_complete_candidate_sets():
    state = InnerGameState()
    first_set = [_entry(10, _ORDER_MTO, 11), _entry(20, _ORDER_HLD, 20)]
    second_set = [_entry(10, _ORDER_HLD, 10), _entry(20, _ORDER_MTO, 21)]
    state.g_candidate_record_list = [
        {'power': 0, 'orders': first_set, 'weight': 100},
        {'power': 0, 'orders': second_set, 'weight': 0},
    ]

    _refresh_order_table(state, 0)

    assert len(state.g_current_best_order[0]) == 30
    assert all(slot == first_set for slot in state.g_current_best_order[0])
    assert all(len(slot) == 2 for slot in state.g_current_best_order[0])


def test_refresh_uses_c_complement_threshold_and_final_rand_draw():
    state = InnerGameState()
    high_set = [_entry(10, _ORDER_MTO, 11)]
    low_set = [_entry(10, _ORDER_HLD, 10)]
    state.g_candidate_record_list = [
        {'power': 0, 'orders': high_set, 'weight': 700},
        {'power': 0, 'orders': low_set, 'weight': 200},
    ]

    # First rand gives draw_count=1; second gives roll=400.  C computes
    # complement=1000-700=300 and selects the current (700) record because
    # 300 <= 400.  A conventional weighted sampler is not this control flow.
    with patch(f'{_pkg_name}.monte_carlo.trial.random.randint',
               side_effect=[0, 9200] * 30):
        _refresh_order_table(state, 0)

    assert all(slot == high_set for slot in state.g_current_best_order[0])


def test_refresh_first_slot_gate_falls_back_to_first_tree_record():
    state = InnerGameState()
    first_set = [_entry(10, _ORDER_MTO, 11)]
    second_set = [_entry(10, _ORDER_HLD, 10)]
    state.g_candidate_record_list = [
        {'power': 0, 'orders': first_set, 'weight': 40},
        {'power': 0, 'orders': second_set, 'weight': 10},
    ]
    state.sc_count[0] = 3
    state.g_press_flag = 0

    # complement=960 and roll=0 continues to the SC gate; the look-ahead
    # weight 10 fails, and C's common fallback selects the first tree record.
    with patch(f'{_pkg_name}.monte_carlo.trial.random.randint',
               side_effect=[0, 0] + [0, 9200] * 29):
        _refresh_order_table(state, 0)

    assert state.g_current_best_order[0][0] == first_set


def test_full_snapshot_restores_cto_convoy_legs():
    state = InnerGameState()
    army, destination = 10, 50
    state.g_order_table[army, _F_ORDER_TYPE] = _ORDER_CTO
    state.g_order_table[army, _F_DEST_PROV] = destination
    state.g_order_table[army, _F_CONVOY_LEG0] = 20
    state.g_order_table[army, _F_CONVOY_LEG1] = 30
    state.g_order_table[army, _F_CONVOY_LEG2] = 40
    entry = snapshot_order_entry(state.g_order_table, army)

    state.g_order_table[army, :] = 0.0
    restore_order_entry(state.g_order_table, entry, full_row=True)

    assert state.g_order_table[army, _F_ORDER_TYPE] == _ORDER_CTO
    assert state.g_order_table[army, _F_DEST_PROV] == destination
    assert state.g_order_table[army, _F_CONVOY_LEG0] == 20
    assert state.g_order_table[army, _F_CONVOY_LEG1] == 30
    assert state.g_order_table[army, _F_CONVOY_LEG2] == 40


def test_candidate_identity_ignores_snapshot_bookkeeping_fields():
    first = list(_entry(10, _ORDER_MTO, 11))
    second = list(_entry(10, _ORDER_MTO, 11))
    first_row = list(first[5])
    second_row = list(second[5])
    first_row[20] = 1.0
    second_row[20] = 5.0
    first[5] = tuple(first_row)
    second[5] = tuple(second_row)

    assert candidate_orders_key(0, [tuple(first)]) == candidate_orders_key(
        0, [tuple(second)]
    )
