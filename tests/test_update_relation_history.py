"""Source-level regressions for UpdateRelationHistory (FUN_0040d7e0)."""

from pathlib import Path
import sys

import numpy as np

_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_senders = __import__(
    f"{_PKG}.communications.senders",
    fromlist=["_update_relation_history"],
)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

_update_relation_history = _senders._update_relation_history
InnerGameState = _state.InnerGameState


def test_floor_exponent_comes_from_relation_score_not_trust_value():
    state = InnerGameState()
    state.g_ally_trust_score[1, 2] = 1
    state.g_relation_score[1, 2] = 50

    _update_relation_history(state)

    # Albert.exe 0x40d82f loads DAT_00634e90 (relation score), divides by
    # ten, and computes int(pow(1.8, 5)).
    assert int(state.g_ally_trust_score[1, 2]) == 18
    assert int(state.g_ally_trust_score_hi[1, 2]) == 0


def test_floor_compares_the_low_trust_word_as_unsigned():
    state = InnerGameState()
    state.g_ally_trust_score[1, 2] = np.int32(-1)
    state.g_ally_trust_score_hi[1, 2] = 0
    state.g_relation_score[1, 2] = 50

    _update_relation_history(state)

    # 0xffffffff is above 18 in C's unsigned low-word comparison.
    assert int(state.g_ally_trust_score[1, 2]) == -1
    assert int(state.g_ally_trust_score_hi[1, 2]) == 0


def test_runtime_power_count_bounds_both_loops():
    state = InnerGameState()
    state.g_num_powers = 2
    state.g_ally_trust_score[1, 1] = 1
    state.g_relation_score[1, 1] = 50
    state.g_ally_trust_score[2, 2] = 1
    state.g_relation_score[2, 2] = 50

    _update_relation_history(state)

    assert int(state.g_ally_trust_score[1, 1]) == 18
    assert int(state.g_ally_trust_score[2, 2]) == 1
