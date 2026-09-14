"""ORD result decoding (FUN_0045fe30) and its PostProcessOrders consumer."""

from pathlib import Path
import sys

import numpy as np


_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_strategy = __import__(f"{_PKG}.heuristics.strategy", fromlist=["post_process_orders"])
InnerGameState = _state.InnerGameState
_order_result_flags = _state._order_result_flags
post_process_orders = _strategy.post_process_orders


def test_successful_move_sets_only_moved():
    assert _order_result_flags(2, []) == {
        "moved": 1, "bounced": 0, "cut": 0, "disrupted": 0, "void": 0,
        "dislodged": 0,
    }


def test_success_on_non_move_orders_never_sets_moved():
    for order_type in (1, 3, 4, 5):
        assert _order_result_flags(order_type, [])["moved"] == 0


def test_bounced_and_dislodged_move_sets_both_flags_but_not_moved():
    flags = _order_result_flags(2, ["bounce", "dislodged"])
    assert (flags["moved"], flags["bounced"], flags["dislodged"]) == (0, 1, 1)


def test_dislodged_hold_is_still_a_successful_order_without_movement():
    flags = _order_result_flags(1, ["dislodged"])
    assert (flags["moved"], flags["dislodged"]) == (0, 1)


def test_cut_support_sets_cut_and_void_convoy_sets_void():
    assert _order_result_flags(3, ["cut"])["cut"] == 1
    assert _order_result_flags(5, ["void"])["void"] == 1
    assert _order_result_flags(6, ["no convoy"])["moved"] == 0


def _record(**flags):
    rec = {"power": 1, "src_province": 5, "dst_province": 9, "order_type": 2}
    rec.update(flags)
    return rec


def test_bounced_move_accumulates_history_unless_dislodged():
    state = InnerGameState()
    state.g_order_hist_list = [_record(bounced=1)]
    post_process_orders(state)
    assert int(state.g_move_history_matrix[1, 5, 9]) == 10

    state.g_order_hist_list = [_record(bounced=1, dislodged=1)]
    state.g_move_history_matrix[1, 5, 9] = 40
    post_process_orders(state)
    assert int(state.g_move_history_matrix[1, 5, 9]) == 0


def test_moved_clears_source_row_destination_row_and_destination_column():
    state = InnerGameState()
    state.g_move_history_matrix[1, 5, 3] = 50
    state.g_move_history_matrix[1, 9, 4] = 50
    state.g_move_history_matrix[1, 7, 9] = 50
    state.g_move_history_matrix[1, 7, 8] = 50
    state.g_order_hist_list = [_record(moved=1)]

    post_process_orders(state)

    assert not np.any(state.g_move_history_matrix[1, 5, :])
    assert not np.any(state.g_move_history_matrix[1, 9, :])
    assert not np.any(state.g_move_history_matrix[1, :, 9])
    assert int(state.g_move_history_matrix[1, 7, 8]) == 47


def test_cut_support_no_longer_scores_as_successful_support():
    state = InnerGameState()
    state.g_order_hist_list = [
        {"power": 1, "src_province": 5, "dst_province": 9, "order_type": 4}
    ]
    post_process_orders(state)
    assert not np.any(state.g_move_history_matrix)


class _HistoryGame:
    def __init__(self, order_history, result_history):
        from diplomacy import Game
        base = Game()
        self.map = base.map
        self.powers = base.powers
        self.order_history = order_history
        self.result_history = result_history
        self._base = base

    def get_centers(self):
        return self._base.get_centers()

    def get_units(self):
        return self._base.get_units()

    def get_current_phase(self):
        return "F1902M"


def test_retreat_list_does_not_survive_a_later_movement_phase():
    game = _HistoryGame(
        {
            "F1901M": {"FRANCE": ["A PAR - BUR"]},
            "F1901R": {"FRANCE": ["A BUR R PAR"]},
            "W1901A": {"FRANCE": []},
            "S1902M": {"FRANCE": ["A PAR - BUR"]},
        },
        {"S1902M": {"A PAR": []}},
    )
    state = InnerGameState()
    state.synchronize_from_game(game)

    assert state.g_retreat_list == []
    assert [r["order_type"] for r in state.g_order_hist_list] == [2]
    assert state.g_order_hist_list[0]["moved"] == 1


def test_retreat_list_keeps_the_retreat_after_the_last_movement_phase():
    game = _HistoryGame(
        {
            "F1901M": {"FRANCE": ["A PAR - BUR"]},
            "F1901R": {"FRANCE": ["A BUR R PAR"]},
        },
        {"F1901M": {"A PAR": ["bounce"]}, "F1901R": {"A BUR": []}},
    )
    state = InnerGameState()
    state.synchronize_from_game(game)

    assert [r["order_type"] for r in state.g_retreat_list] == [7]
    assert state.g_retreat_list[0]["moved"] == 1
    assert state.g_order_hist_list[0]["bounced"] == 1
