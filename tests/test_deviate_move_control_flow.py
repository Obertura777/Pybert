"""Source-backed regressions for DEVIATE_MOVE's order and consequence paths."""

from pathlib import Path
import sys

import numpy as np

_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_strategy = __import__(f"{_PKG}.bot.strategy", fromlist=["_deviate_move"])
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

_deviate_move = _strategy._deviate_move
InnerGameState = _state.InnerGameState


def _state3() -> InnerGameState:
    state = InnerGameState()
    state.g_num_powers = 3
    state.albert_power_idx = 0
    state.g_season = "SPR"
    return state


def test_peace_signal_uses_reachable_adjacent_snapshot_not_order_destination():
    state = _state3()
    state.g_order_hist_list = [
        {
            "power": 1,
            "unit_type": 0,
            "src_province": 5,
            "dst_province": 20,
            "order_type": 1,
        }
    ]
    state.adj_matrix[5] = [6]
    state.can_reach_by_type = lambda _src, _dst, _unit: True
    state.g_spr_desig_c[6] = 0
    state.g_spr_desig_c_hi[6] = 0

    _deviate_move(state)

    assert int(state.g_peace_signal[0, 1]) == 1
    assert not np.any(state.g_stab_flag[:3, :3])
    assert not np.any(state.g_neutral_flag[:3, :3])


def test_snapshot_designation_requires_exact_zero_high_word():
    state = _state3()
    state.g_order_hist_list = [
        {
            "power": 1,
            "unit_type": 0,
            "src_province": 5,
            "dst_province": 6,
            "order_type": 2,
        }
    ]
    state.adj_matrix[5] = [6]
    state.can_reach_by_type = lambda _src, _dst, _unit: True
    state.g_spr_desig_a[6] = 0
    state.g_spr_desig_a_hi[6] = 1
    state.g_ally_trust_score[0, 1] = 9

    _deviate_move(state)

    assert int(state.g_peace_signal[0, 1]) == 0
    assert int(state.g_stab_flag[0, 1]) == 0


def test_fulfilled_xdo_move_contract_is_not_a_deviation():
    state = _state3()
    state.g_order_hist_list = [
        {"power": 1, "src_province": 5, "dst_province": 10, "order_type": 2}
    ]
    state.g_xdo_mto_opp_score = {0: {5: 10}}
    state.g_ally_trust_score[0, 1] = 7

    _deviate_move(state)

    assert int(state.g_stab_flag[0, 1]) == 0
    assert int(state.g_neutral_flag[0, 1]) == 0
    assert int(state.g_ally_trust_score[0, 1]) == 7


def test_broken_xdo_move_uses_reverse_high_word_trust_and_victim_row():
    state = _state3()
    state.g_order_hist_list = [
        {"power": 1, "src_province": 5, "dst_province": 10, "order_type": 2}
    ]
    state.g_xdo_mto_opp_score = {0: {5: 11}}
    state.g_ally_trust_score_hi[1, 0] = 1

    _deviate_move(state)

    assert int(state.g_stab_flag[0, 1]) == 1
    assert int(state.g_stab_flag[1, 0]) == 0
    assert 10 in state.g_alliance_msg_tree
    assert int(state.g_ally_trust_score_hi[1, 0]) == 0


def test_broken_xdo_support_contract_is_a_neutral_attack_without_trust():
    state = _state3()
    state.g_order_hist_list = [
        {
            "power": 1,
            "src_province": 5,
            "order_type": 4,
            "sup_src": 6,
            "sup_dst": 8,
        }
    ]
    state.g_xdo_sup_attacker_score = {0: {5: (6, 7)}}
    state.g_ally_promise_list = {1: [{"dest_prov": 8}]}
    state.g_ally_counter_list = {1: [{"dest_prov": 8}]}
    state.g_ally_matrix[1, :3] = 4

    _deviate_move(state)

    assert int(state.g_neutral_flag[0, 1]) == 1
    assert int(state.g_stab_flag[0, 1]) == 0
    assert 11 in state.g_alliance_msg_tree
    assert state.g_ally_promise_list[1] == []
    assert state.g_ally_counter_list[1] == []
    assert not np.any(state.g_ally_matrix[1, :3])
    assert not np.any(state.g_coop_score_flag_b[:3, :3])


def test_unprotected_mutual_pressure_sets_cease_fire_without_clearing_trust():
    state = _state3()
    state.g_order_hist_list = [
        {"power": 1, "src_province": 5, "dst_province": 10, "order_type": 2}
    ]
    state.g_AttackMap[1, 10] = 2
    state.g_AttackMap[0, 10] = 1
    state.g_ally_trust_score[0, 1] = 4

    _deviate_move(state)

    assert int(state.g_cease_fire[0, 1]) == 1
    assert int(state.g_stab_flag[0, 1]) == 0
    assert int(state.g_neutral_flag[0, 1]) == 0
    assert int(state.g_ally_trust_score[0, 1]) == 4
    assert 10 in state.g_alliance_msg_tree


def test_near_end_gate_creates_deviation_but_does_not_force_stab():
    state = _state3()
    state.g_order_hist_list = [
        {"power": 1, "src_province": 5, "dst_province": 10, "order_type": 2}
    ]
    state.g_near_end_game_factor = 4.0
    state.sc_count[0] = 3

    _deviate_move(state)

    assert int(state.g_neutral_flag[0, 1]) == 1
    assert int(state.g_stab_flag[0, 1]) == 0


def test_dislodged_army_relation_override_can_classify_stab_without_trust():
    state = _state3()
    state.g_order_hist_list = [
        {
            "power": 1,
            "src_province": 5,
            "dst_province": 10,
            "order_type": 2,
            "flag_c": 1,
        }
    ]
    state.g_spr_desig_a[10] = 0
    state.g_spr_desig_a_hi[10] = 0
    state.sc_provinces = {10}
    state.g_sc_owner[10] = 0
    state.g_relation_score[0, 1] = -9

    _deviate_move(state)

    assert int(state.g_stab_flag[0, 1]) == 1
    assert int(state.g_neutral_flag[0, 1]) == 0


def test_retreat_uses_sum_snapshot_and_stops_before_movement_consequences():
    state = _state3()
    state.g_season = "SUM"
    state.g_retreat_list = [
        {"power": 1, "order_type": 7, "dst_province": 9}
    ]
    state.g_sum_desig_b[9] = 0
    state.g_sum_desig_b_hi[9] = 0
    state.g_ally_trust_score_hi[0, 1] = 1
    state.g_ally_promise_list = {1: [{"dest_prov": 9}]}
    state.g_ally_counter_list = {1: [{"dest_prov": 9}]}
    state.g_ally_matrix[1, :3] = 5
    state.g_best_ally_slot0, state.g_best_ally_slot1 = 1, 2

    _deviate_move(state)

    assert int(state.g_stab_flag[0, 1]) == 1
    assert 12 in state.g_alliance_msg_tree
    assert int(state.g_ally_trust_score_hi[0, 1]) == 0
    assert state.g_ally_promise_list[1] == [{"dest_prov": 9}]
    assert state.g_ally_counter_list[1] == [{"dest_prov": 9}]
    assert np.all(state.g_ally_matrix[1, :3] == 5)
    assert (
        state.g_best_ally_slot0,
        state.g_best_ally_slot1,
        state.g_best_ally_slot2,
    ) == (1, 2, -1)


def test_own_move_into_promise_tree_promotes_second_enemy_slot():
    state = _state3()
    state.g_num_powers = 4
    state.g_order_hist_list = [
        {"power": 0, "src_province": 5, "dst_province": 10, "order_type": 2}
    ]
    state.g_ally_promise_list = {1: [{"dest_prov": 10}]}
    state.g_ally_counter_list = {1: [{"dest_prov": 11}]}
    state.g_ally_trust_score[1, 0] = 3
    state.g_best_ally_slot0 = 2
    state.g_best_ally_slot1 = 1
    state.g_best_ally_slot2 = 3

    _deviate_move(state)

    assert int(state.g_stab_flag[1, 0]) == 1
    assert tuple(map(int, state.g_enemy_slot)) == (2, 3, -1)
    assert state.g_ally_promise_list[1] == []
    assert state.g_ally_counter_list[1] == []


def test_initial_reset_is_bounded_by_runtime_power_count():
    state = _state3()
    state.g_num_powers = 2
    state.g_stab_flag.fill(9)
    state.g_neutral_flag.fill(9)
    state.g_cease_fire.fill(9)
    state.g_peace_signal.fill(9)
    state.g_coop_score_flag_a.fill(9)

    _deviate_move(state)

    assert not np.any(state.g_stab_flag[:2, :2])
    assert not np.any(state.g_neutral_flag[:2, :2])
    assert not np.any(state.g_cease_fire[:2, :2])
    assert not np.any(state.g_peace_signal[:2, :2])
    assert not np.any(state.g_coop_score_flag_a[:2, :2])
    assert int(state.g_stab_flag[2, 2]) == 9
    assert int(state.g_coop_score_flag_a[2, 2]) == 9
