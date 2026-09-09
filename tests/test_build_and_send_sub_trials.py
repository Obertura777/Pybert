"""Focused chronology tests for BuildAndSendSUB's proposal-round loop."""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_press_mod = __import__(
    f'{_pkg_name}.bot.client._press',
    fromlist=['_advance_broadcast_proposal_trials'],
)

_trial_mod = __import__(
    f'{_pkg_name}.monte_carlo.trial',
    fromlist=['update_score_state'],
)

InnerGameState = _state_mod.InnerGameState
_advance_trials = _press_mod._advance_broadcast_proposal_trials


def test_broadcast_trials_run_round_zero_rank_then_all_score_updates():
    state = InnerGameState()
    state.g_unit_count[0] = 1
    state.g_power_call_count[0] = 3
    state.g_cum_score = 10
    state.g_score_baseline = 2
    state.g_score_alt = 7
    candidate = {'power': 0, 'output_score': 12.5}
    state.g_candidate_record_list = [candidate]
    entry = {'trial_count': 0}

    rank_calls = []
    refresh_calls = []
    update_rounds = []
    dispatch_rounds = []

    def fake_rank(_state, power, flag=0):
        rank_calls.append((power, flag, _state.g_n_trials_completed))

    def fake_refresh(_state, power):
        refresh_calls.append((power, _state.g_n_trials_completed))

    def fake_update(_state):
        update_rounds.append(_state.g_n_trials_completed)
        _state.g_score_alt += 2
        _state.g_score_baseline += 1
        candidate['output_score'] += 0.5

    with (
        patch.object(_press_mod, '_rank_candidates_for_power', fake_rank),
        patch.object(_press_mod, '_refresh_order_table', fake_refresh),
        patch.object(_press_mod, 'update_score_state', fake_update),
        patch.object(_press_mod, 'check_time_limit', return_value=False),
    ):
        completed = _advance_trials(
            state, entry, 3,
            dispatch_fn=lambda: dispatch_rounds.append(
                state.g_n_trials_completed),
        )

    assert completed is True
    assert rank_calls == [(0, 0, 0)]
    assert refresh_calls == [(0, 0)]
    assert update_rounds == [0, 1, 2]
    assert dispatch_rounds == [0, 1, 2]
    assert entry['trial_count'] == 3
    assert state.g_n_trials_completed == 3
    assert state.g_cum_score == 13
    assert state.g_trial_score_a == [11, 10, 9]
    assert state.g_trial_score_b == [9, 2, 2]
    assert state.g_trial_score_c == [3, 1, 1]
    assert candidate['output_score_history'] == [13.0, 13.5, 14.0]


def test_broadcast_trials_resume_node_counter_and_stop_on_timeout():
    state = InnerGameState()
    candidate = {'power': 0, 'output_score': 4.0}
    state.g_candidate_record_list = [candidate]
    entry = {'trial_count': 1}
    update_rounds = []

    timeout_checks = iter((False, True))

    def fake_update(_state):
        update_rounds.append(_state.g_n_trials_completed)

    with (
        patch.object(_press_mod, 'update_score_state', fake_update),
        patch.object(
            _press_mod, 'check_time_limit',
            side_effect=lambda _state: next(timeout_checks),
        ),
    ):
        completed = _advance_trials(state, entry, 4)

    assert completed is False
    assert update_rounds == [1]
    assert entry['trial_count'] == 2
    assert state.g_n_trials_completed == 2
    assert candidate['output_score_history'] == [0.0, 4.0]


def test_round_zero_rank_is_gated_on_the_node_participant_set():
    """BuildAndSendSUB.c:283-305 gates on find(power) != end() in DAT_00bc1e00.

    DAT_00bc1e00 is re-copied from the node's own participant set on every
    trial iteration (BuildAndSendSUB.c:230-236), so a live-unit power that
    does not take part in this proposal is skipped entirely.
    """
    def _run(entry):
        state = InnerGameState()
        for power in (0, 1, 2):
            state.g_unit_count[power] = 1
        state.g_candidate_record_list = []
        rank_calls = []
        with (
            patch.object(
                _press_mod, '_rank_candidates_for_power',
                lambda _s, power, flag=0: rank_calls.append(power),
            ),
            patch.object(_press_mod, '_refresh_order_table',
                         lambda _s, power: None),
            patch.object(_press_mod, 'update_score_state', lambda _s: None),
            patch.object(_press_mod, 'check_time_limit', return_value=False),
        ):
            _advance_trials(state, entry, 1)
        return rank_calls, state

    # Only the node's participants are ranked, even though 0/1/2 are all live.
    ranked, state = _run({'trial_count': 0, 'participant_powers': {0, 2}})
    assert ranked == [0, 2]
    # The set stays loaded for UpdateScoreState to read.
    assert state.g_proposal_order_powers == {0, 2}

    # A node carrying no participant information stands in for C's implicit
    # base SUB node and covers every live power.
    ranked, state = _run({'trial_count': 0})
    assert ranked == [0, 1, 2]
    assert state.g_proposal_order_powers == {0, 1, 2}


def test_update_score_state_follows_the_participant_set():
    """UpdateScoreState.c gates both of its passes on the same membership."""
    state = InnerGameState()
    for power in (0, 1, 2):
        state.g_unit_count[power] = 1
    state.g_proposal_order_powers = {1}

    ally_calls, refresh_calls = [], []
    with (
        patch.object(_trial_mod, '_update_ally_order_score',
                     lambda _s, power: ally_calls.append(power)),
        patch.object(_trial_mod, '_refresh_order_table',
                     lambda _s, power: refresh_calls.append(power)),
    ):
        _trial_mod.update_score_state(state)

    assert ally_calls == [1]
    assert refresh_calls == [1]

    # An empty set does no per-power work at all.
    state.g_proposal_order_powers = set()
    ally_calls.clear()
    refresh_calls.clear()
    with (
        patch.object(_trial_mod, '_update_ally_order_score',
                     lambda _s, power: ally_calls.append(power)),
        patch.object(_trial_mod, '_refresh_order_table',
                     lambda _s, power: refresh_calls.append(power)),
    ):
        _trial_mod.update_score_state(state)

    assert ally_calls == []
    assert refresh_calls == []
