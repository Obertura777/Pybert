"""Source-backed regressions for STABBED's detection and consequence paths."""

from pathlib import Path
import sys

import numpy as np

_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_strategy = __import__(f"{_PKG}.bot.strategy", fromlist=["_stabbed"])
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

_stabbed = _strategy._stabbed
InnerGameState = _state.InnerGameState


def _state3() -> InnerGameState:
    state = InnerGameState()
    state.g_num_powers = 3
    state.albert_power_idx = 0
    state.g_season = 'SPR'
    return state


def test_foreign_move_into_counter_protected_province_is_a_stab():
    state = _state3()
    state.g_order_hist_list = [
        {'power': 1, 'order_type': 2, 'dst_province': 10},
    ]
    state.g_ally_counter_list = {1: [{'dest_prov': 10}, {'dest_prov': 11}]}
    state.g_ally_promise_list = {1: [{'dest_prov': 12}]}
    state.g_ally_trust_score[0, 1] = 9
    state.g_ally_trust_score[1, 0] = 8
    state.g_best_ally_slot0, state.g_best_ally_slot1 = 1, 2

    _stabbed(state)

    assert int(state.g_stab_flag[0, 1]) == 1
    assert int(state.g_stabbed_flag) == 1
    assert state.g_alliance_msg_tree.issuperset({10, 30})
    assert state.g_ally_counter_list[1] == []
    assert state.g_ally_promise_list[1] == []
    assert tuple(map(int, state.g_enemy_slot)) == (2, -1, -1)
    assert (
        state.g_best_ally_slot0,
        state.g_best_ally_slot1,
        state.g_best_ally_slot2,
    ) == (2, -1, -1)
    assert int(state.g_ally_trust_score[0, 1]) == 0
    assert int(state.g_ally_trust_score[1, 0]) == 0


def test_foreign_move_outside_counter_tree_is_not_a_stab():
    state = _state3()
    state.g_order_hist_list = [
        {'power': 1, 'order_type': 2, 'dst_province': 10},
    ]
    state.g_ally_counter_list = {1: [{'dest_prov': 11}]}

    _stabbed(state)

    assert int(state.g_stab_flag[0, 1]) == 0
    assert int(state.g_stabbed_flag) == 0


def test_unit_phase_does_not_treat_alliance_designations_as_occupants():
    state = _state3()
    state.unit_info[5] = {'power': 1, 'type': 'A', 'coast': ''}
    state.g_ally_designation_a[5] = 0
    state.g_ally_designation_a_hi[5] = 0

    _stabbed(state)

    assert not np.any(state.g_stab_flag[:3, :3])


def test_own_stab_at_second_enemy_slot_promotes_third_slot():
    state = _state3()
    state.g_num_powers = 4
    state.g_order_hist_list = [
        {'power': 0, 'order_type': 4, 'sup_dst': 10},
    ]
    state.g_ally_promise_list = {1: [{'dest_prov': 10}], 2: []}
    state.g_ally_counter_list = {1: [{'dest_prov': 20}]}
    state.g_best_ally_slot0 = 2
    state.g_best_ally_slot1 = 1
    state.g_best_ally_slot2 = 3

    _stabbed(state)

    assert int(state.g_stab_flag[1, 0]) == 1
    assert tuple(map(int, state.g_enemy_slot)) == (2, 3, -1)
    assert state.g_ally_promise_list[1] == []
    assert state.g_ally_counter_list[1] == []
    assert int(state.g_stabbed_flag) == 0


def test_initial_reset_is_bounded_by_runtime_power_count():
    state = _state3()
    state.g_num_powers = 2
    state.g_stab_flag.fill(9)
    state.g_neutral_flag.fill(9)
    state.g_cease_fire.fill(9)
    state.g_peace_signal.fill(9)
    state.g_coop_score_flag_a.fill(9)

    _stabbed(state)

    assert not np.any(state.g_stab_flag[:2, :2])
    assert not np.any(state.g_neutral_flag[:2, :2])
    assert not np.any(state.g_cease_fire[:2, :2])
    assert not np.any(state.g_peace_signal[:2, :2])
    assert not np.any(state.g_coop_score_flag_a[:2, :2])
    assert int(state.g_stab_flag[2, 2]) == 9
    assert int(state.g_coop_score_flag_a[2, 2]) == 9
