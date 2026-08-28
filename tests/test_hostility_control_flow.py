"""Source-parity regressions for HOSTILITY's controlling state."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_strategy = __import__(f"{_pkg_name}.bot.strategy", fromlist=["_hostility"])
_communications = __import__(
    f"{_pkg_name}.communications",
    fromlist=["compute_order_dip_flags", "_update_relation_history"],
)
_tokens = __import__(f"{_pkg_name}.communications.tokens", fromlist=["_TOK_PCE"])

InnerGameState = _state.InnerGameState
_hostility = _strategy._hostility


def _isolate_hostility(monkeypatch, *, roll=99, cal_board=None):
    monkeypatch.setattr(_strategy, "_rand_stride", lambda: roll)
    monkeypatch.setattr(_strategy, "build_alliance_msg", lambda *_args: None)
    monkeypatch.setattr(
        _strategy, "cal_board",
        cal_board if cal_board is not None else (lambda *_args: None),
    )
    monkeypatch.setattr(
        _communications, "compute_order_dip_flags", lambda *_args: None,
    )
    monkeypatch.setattr(
        _communications, "_update_relation_history", lambda *_args: None,
    )


def test_mutual_enemy_exception_uses_near_victory_state_not_enemy_desired(
        monkeypatch):
    state = InnerGameState()
    state.g_season = "WIN"
    state.g_press_flag = 0
    state.g_stabbed_flag = 1
    state.g_committed_enemy = -1  # deliberately contradict the source alias
    state.sc_count[:] = 0
    state.sc_count[3] = 1
    state.g_influence_rank_flag[0, 3] = 5
    state.g_influence_rank_flag[1, 3] = 1

    def _cal_board_sets_near_victory(board_state, _own):
        board_state.g_other_power_lead_flag = 1
        board_state.g_near_victory_power = 3
        board_state.g_enemy_flag[3] = 1
        board_state.g_enemy_flag_hi[3] = 0

    _isolate_hostility(
        monkeypatch, cal_board=_cal_board_sets_near_victory,
    )

    _hostility(state)

    assert state.g_mutual_enemy_table[1] == 3


def test_no_press_peace_still_sets_bilateral_trust_and_counts_own_slot(
        monkeypatch):
    state = InnerGameState()
    state.g_season = "SPR"
    state.g_press_flag = 0
    state.g_minimal_press_mode = 1
    state.g_stabbed_flag = 1
    state.sc_count[:] = 0
    state.sc_count[1] = 3
    _isolate_hostility(monkeypatch, roll=99)

    _hostility(state)

    assert state.g_peace_counter[0] == 1
    assert state.g_ally_trust_score[0, 1] == 1
    assert state.g_ally_trust_score_hi[0, 1] == 0
    assert state.g_ally_trust_score[1, 0] == 1
    assert state.g_ally_trust_score_hi[1, 0] == 0


def test_enemy_high_word_blocks_peace_counter_and_overture(monkeypatch):
    state = InnerGameState()
    state.g_season = "SPR"
    state.g_press_flag = 0
    state.g_stabbed_flag = 1
    state.sc_count[1] = 3
    state.g_enemy_flag_hi[1] = 1
    _isolate_hostility(monkeypatch, roll=0)

    _hostility(state)

    assert state.g_peace_counter[1] == 0
    assert state.g_ally_trust_score[0, 1] == 0
    assert state.g_ally_trust_score[1, 0] == 0


def test_peace_overture_uses_counter_high_word(monkeypatch):
    state = InnerGameState()
    state.g_season = "FAL"
    state.g_press_flag = 0
    state.g_stabbed_flag = 1
    state.sc_count[1] = 3
    state.g_peace_counter[1] = 1 << 32
    _isolate_hostility(monkeypatch, roll=99)

    _hostility(state)

    assert state.g_peace_counter[1] == (1 << 32) + 1
    assert state.g_ally_trust_score[0, 1] == 0
    assert state.g_ally_trust_score[1, 0] == 0


def test_press_snapshot_compares_low_trust_as_unsigned(monkeypatch):
    state = InnerGameState()
    state.g_season = "SPR"
    state.g_press_flag = 1
    state.g_history_counter = 1
    state.g_stabbed_flag = 0
    state.g_ally_trust_score[0, 0] = -1
    for power in range(7):
        state.g_ally_pref_ranking[power, 1:4] = [
            (power + 1) % 7,
            (power + 2) % 7,
            (power + 3) % 7,
        ]
    _isolate_hostility(monkeypatch, roll=99)
    monkeypatch.setattr(
        _strategy, "_send_ally_press_by_power", lambda *_args: None,
    )

    _hostility(state)

    assert state.g_diplomacy_state_a[0] == -1
    assert state.g_diplomacy_state_b[0] == 0
    assert state.g_ally_trust_score[0, 0] == -1


def test_hostility_pce_gate_uses_fixed_first_history_tree(monkeypatch):
    state = InnerGameState()
    state.g_season = "SPR"
    state.g_press_flag = 0
    state.g_stabbed_flag = 1
    state.g_history_counter = 1
    state.g_deceit_level = 2
    state.sc_count[1] = 3
    state.g_press_history = {0: set(), 1: {_tokens._TOK_PCE}}
    _isolate_hostility(monkeypatch, roll=0)

    _hostility(state)

    assert state.g_ally_trust_score[0, 1] == 0

    state.g_press_history[0].add(_tokens._TOK_PCE)
    _hostility(state)

    assert state.g_ally_trust_score[0, 1] == 1
    assert state.g_ally_trust_score[1, 0] == 1


def test_cal_board_near_victory_writes_hostility_mutual_enemy_storage():
    state = InnerGameState()
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_target_sc_cnt[1] = 11
    state.sc_count[1] = 11

    _strategy.cal_board(state, own_power=0)

    assert state.g_other_power_lead_flag == 1
    assert state.g_mutual_enemy_table.tolist() == [1] * 7
