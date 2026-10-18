"""ScoreProvinces rounds pending + A*6/7 + B/7 (Albert.exe 0x448fe2-0x449011).

A = DAT_00b82db8 (NormalizeInfluenceMatrix output), B = DAT_00b84948.
"""
import os
import sys

_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)
_pkg = os.path.basename(_pkg_root)

import numpy as np

InnerGameState = getattr(__import__(f'{_pkg}.state', fromlist=['InnerGameState']), 'InnerGameState')
_scoring = __import__(f'{_pkg}.heuristics.scoring', fromlist=['_influence_blend'])
_influence = __import__(f'{_pkg}.heuristics.influence', fromlist=['normalize_influence_matrix'])


def test_blend_weights_a_six_sevenths_and_b_one_seventh():
    s = InnerGameState()
    s.g_influence_matrix_norm[2, 5] = 35.0
    s.g_influence_matrix_b[2, 5] = 14.0
    assert abs(_scoring._influence_blend(s, 2, 5) - (30.0 + 2.0)) < 1e-12
    assert _scoring._influence_blend(s, 5, 2) == 0.0


def test_normalize_influence_matrix_fills_matrix_a():
    s = InnerGameState()
    s.g_influence_matrix_raw[:] = np.arange(49.0).reshape(7, 7)
    _influence.normalize_influence_matrix(s)
    assert not s.g_influence_matrix.any()  # DAT_00b81ff0 is not NormalizeInfluenceMatrix's
    assert abs(s.g_influence_matrix_norm[1].sum() - 100.0) < 1e-9
