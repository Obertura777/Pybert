"""Control-flow regressions for FRIENDLY (FUN_0042dc40)."""

from pathlib import Path
import sys

import numpy as np

_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_senders = __import__(
    f"{_PKG}.communications.senders",
    fromlist=["friendly"],
)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

friendly = _senders.friendly
InnerGameState = _state.InnerGameState


def _live_state() -> InnerGameState:
    state = InnerGameState()
    state.sc_count.fill(1)
    state.g_season = 'SPR'
    return state


def test_no_press_does_not_suppress_tentative_trust_write():
    state = _live_state()
    state.g_season = 'FAL'
    state.g_minimal_press_mode = 1
    state.g_deceit_level = 2

    friendly(state)

    # FRIENDLY.c's Block C has no press-mode gate.
    assert int(state.g_ally_trust_score[1, 2]) == 1
    assert int(state.g_ally_trust_score_hi[1, 2]) == 0


def test_final_alliance_pass_includes_diagonal_entries():
    state = _live_state()
    state.g_ally_trust_score[1, 1] = 5
    state.g_ally_matrix[1, 1] = 1

    friendly(state)

    assert int(state.g_ally_matrix[1, 1]) == 2


def test_final_alliance_threshold_uses_unsigned_low_word():
    state = _live_state()
    state.g_ally_trust_score[1, 2] = np.int32(-1)
    state.g_ally_trust_score_hi[1, 2] = 0
    state.g_ally_matrix[1, 2] = 1

    friendly(state)

    assert int(state.g_ally_trust_score[1, 2]) == -1
    assert int(state.g_ally_matrix[1, 2]) == 2


def test_runtime_power_count_bounds_pair_updates_and_alliance_pass():
    state = _live_state()
    state.g_num_powers = 2
    state.g_ally_trust_score[1, 1] = 5
    state.g_ally_matrix[1, 1] = 1
    state.g_ally_trust_score[2, 2] = 5
    state.g_ally_matrix[2, 2] = 1

    friendly(state)

    assert int(state.g_ally_matrix[1, 1]) == 2
    assert int(state.g_ally_matrix[2, 2]) == 1
