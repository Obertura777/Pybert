"""EvaluateOrderScore history factor = float32(0.85 ** trunc(field17 / 10)).

Albert.exe 0x437786: base 0.85 (DAT_004b0f70) and int exponent are passed to
FUN_0040e890, an integer-power routine (reciprocal for a negative exponent).
"""
import os
import sys

_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)
_pkg = os.path.basename(_pkg_root)

import numpy as np

_history_term = getattr(__import__(f'{_pkg}.monte_carlo.evaluation', fromlist=['_history_term']), '_history_term')


def test_history_term_is_point85_to_the_tenths():
    for hist, n in [(0, 0), (9, 0), (10, 1), (37, 3), (100, 10)]:
        assert _history_term(hist) == float(np.float32(0.85 ** n))


def test_history_term_negative_truncates_toward_zero_and_inverts():
    assert _history_term(-9) == 1.0
    assert _history_term(-25) == float(np.float32(0.85 ** -2))


def test_history_term_decreases_with_history():
    assert _history_term(50) < _history_term(10) < _history_term(0) == 1.0
