"""InitScoringState averages the largest 70% of urgency ratios (Albert.exe 0x445a0f).

FUN_0041a180 inserts into a descending RB-tree; k = max(1, trunc(0.7 n));
the first k are summed in float32 and divided by k.
"""
import os
import sys

_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)
_pkg = os.path.basename(_pkg_root)

import numpy as np

_top_share_mean = getattr(__import__(f'{_pkg}.bot.orders', fromlist=['_top_share_mean']), '_top_share_mean')


def test_largest_seventy_percent_are_averaged():
    ratios = [1.0, 5.0, 2.0, 4.0, 3.0, 10.0, 0.5, 6.0, 7.0, 8.0]   # n=10 -> k=7
    want = np.float32(sum([10.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0])) / np.float32(7)
    assert _top_share_mean(ratios) == float(np.float32(want))


def test_small_counts_keep_at_least_one():
    assert _top_share_mean([2.0]) == 2.0                    # trunc(0.7) = 0 -> 1
    assert _top_share_mean([1.0, 9.0]) == 9.0              # trunc(1.4) = 1, largest
    assert _top_share_mean([1.0, 9.0, 3.0]) == 6.0          # trunc(2.1) = 2 -> (9+3)/2
