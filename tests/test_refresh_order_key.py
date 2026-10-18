"""RefreshOrderTable keys candidates by int(f32(f32(output_score) * 10)).

Albert.exe 0x424573: fld dword [node+0x1c4] (slot 0x71 = the ranker's running
output_score, written at 0x4256ac); fmul 10.0; FloatToInt64 (truncate).
"""
import os
import sys

_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)
_pkg = os.path.basename(_pkg_root)

_refresh_order_key = getattr(__import__(f'{_pkg}.monte_carlo.trial', fromlist=['_refresh_order_key']), '_refresh_order_key')


def test_key_is_output_score_times_ten_truncated():
    assert _refresh_order_key({'output_score': 37.46, 'weight': 99.0}) == 374
    assert _refresh_order_key({'output_score': 5.0, 'weight': 0.0}) == 50


def test_key_ignores_weight_field():
    assert _refresh_order_key({'weight': 80.0}) == 0


def test_key_truncates_toward_zero_and_is_not_clamped():
    assert _refresh_order_key({'output_score': -2.57}) == -25
    assert _refresh_order_key({'output_score': 150.0}) == 1500
