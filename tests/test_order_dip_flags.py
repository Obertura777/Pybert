"""Source-parity tests for ComputeOrderDipFlags."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_flags = __import__(
    f"{_pkg_name}.communications.evaluators.flags",
    fromlist=["compute_order_dip_flags"],
)
_orders = __import__(
    f"{_pkg_name}.bot.orders",
    fromlist=["_init_position_for_orders", "_refresh_order_dip_owner"],
)

InnerGameState = _state.InnerGameState
compute_order_dip_flags = _flags.compute_order_dip_flags
_init_position_for_orders = _orders._init_position_for_orders
_refresh_order_dip_owner = _orders._refresh_order_dip_owner


def _entry(state, *, province=10, ordering_power=1):
    state.g_order_dip_owner[province] = -1
    record = {
        'province': province,
        'ally_power': ordering_power,
        'flag1': False,
        'flag2': False,
        'flag3': False,
    }
    state.g_order_list[:] = [record]
    return record


def test_fleet_occupant_is_neutral_for_diplomatic_flags():
    state = InnerGameState()
    state.albert_power_idx = 0
    record = _entry(state)
    state.unit_info[10] = {'power': 0, 'type': 'F', 'coast': ''}

    compute_order_dip_flags(state)

    # C only preserves the occupant power when the board token is AMY. A fleet
    # becomes neutral 0x14: it does not clear flag1 and does set flag3.
    assert record['flag1'] is True
    assert record['flag2'] is False
    assert record['flag3'] is True


def test_same_province_enemy_requires_exact_low_and_high_words():
    state = InnerGameState()
    state.albert_power_idx = 0
    record = _entry(state)
    state.unit_info[10] = {'power': 2, 'type': 'A', 'coast': ''}
    state.g_enemy_flag[2] = 1
    state.g_enemy_flag_hi[2] = 1
    state.g_ally_trust_score[0, 2] = 5
    state.g_ally_trust_score[1, 2] = 5

    compute_order_dip_flags(state)

    assert record['flag2'] is True
    assert record['flag3'] is False


def test_adjacent_enemy_requires_exact_low_and_high_words():
    state = InnerGameState()
    state.albert_power_idx = 0
    record = _entry(state)
    state.adj_matrix[10] = [11]
    state.unit_info[11] = {'power': 2, 'type': 'A', 'coast': ''}
    state.g_enemy_flag[2] = 1
    state.g_enemy_flag_hi[2] = 1
    state.g_ally_trust_score[1, 2] = 5

    compute_order_dip_flags(state)

    assert record['flag2'] is True
    assert record['flag3'] is False


def test_adjacent_trust_low_word_is_compared_as_unsigned():
    state = InnerGameState()
    state.albert_power_idx = 0
    state.g_press_flag = 1
    record = _entry(state)
    state.adj_matrix[10] = [11]
    state.unit_info[11] = {'power': 2, 'type': 'A', 'coast': ''}
    state.g_ally_trust_score[0, 2] = -1
    state.g_diplomacy_state_a[2] = 5
    state.g_ally_trust_score[1, 2] = 5

    compute_order_dip_flags(state)

    assert record['flag2'] is True
    assert record['flag3'] is False


def test_adjacent_diplomacy_low_word_is_compared_as_unsigned():
    state = InnerGameState()
    state.albert_power_idx = 0
    state.g_press_flag = 1
    record = _entry(state)
    state.adj_matrix[10] = [11]
    state.unit_info[11] = {'power': 2, 'type': 'A', 'coast': ''}
    state.g_ally_trust_score[0, 2] = 5
    state.g_diplomacy_state_a[2] = -1
    state.g_ally_trust_score[1, 2] = 5

    compute_order_dip_flags(state)

    assert record['flag2'] is True
    assert record['flag3'] is False


def test_position_init_preserves_sc_control_and_builds_separate_spread():
    state = InnerGameState()
    state.sc_provinces = {10, 12}
    state.home_centers = {0: frozenset({10}), 1: frozenset({12})}
    state.g_sc_owner[10] = 0
    state.g_sc_owner[12] = 1
    state.adj_matrix[10] = [11]
    state.adj_matrix[12] = [11]

    _init_position_for_orders(state)

    assert state.g_sc_owner[10] == 0
    assert state.g_sc_owner[12] == 1
    assert state.g_order_dip_owner[10] == 0
    assert state.g_order_dip_owner[12] == 1
    assert state.g_order_dip_owner[11] == -2


def test_order_dip_spread_excludes_foreign_controller_of_home_center():
    state = InnerGameState()
    state.sc_provinces = {10}
    state.home_centers = {0: frozenset({10})}
    state.g_sc_owner[10] = 1
    state.adj_matrix[10] = [11]

    _refresh_order_dip_owner(state)

    assert state.g_order_dip_owner[10] == -1
    assert state.g_order_dip_owner[11] == -1


def test_compute_flags_uses_spread_not_live_sc_controller():
    state = InnerGameState()
    state.albert_power_idx = 0
    record = _entry(state, ordering_power=1)
    state.g_sc_owner[10] = 1
    state.g_order_dip_owner[10] = 0

    compute_order_dip_flags(state)

    assert record['flag1'] is True
    assert record['flag2'] is False
