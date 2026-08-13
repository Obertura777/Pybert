"""Regression tests for Albert's process-global MSVC CRT random stream."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
rng = __import__(f'{_pkg_name}.rng', fromlist=['raw_rand'])


def test_msvc_rand_known_seed_one_sequence():
    rng.seed(1)
    assert [rng.raw_rand() for _ in range(5)] == [41, 18467, 6334, 26500, 19169]


def test_randrange_applies_alberts_divide_then_modulo():
    rng.seed(1)
    assert rng.randrange(100) == (41 // 0x17) % 100
    assert rng.randrange(7) == (18467 // 0x17) % 7


def test_state_round_trip_replays_next_value():
    rng.seed(42)
    rng.raw_rand()
    saved = rng.getstate()
    expected = rng.raw_rand()
    rng.setstate(saved)
    assert rng.raw_rand() == expected
