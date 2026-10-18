"""Each C influence matrix has exactly one writer (Albert.exe xref scan, 0xb81228-0xb85710).

    DAT_00b81228 raw   GenerateOrders 0x44688e/0x447029
    DAT_00b81ff0 M     ComputeInfluenceMatrix 0x40d94e-0x40db57; read by CAL_BOARD
    DAT_00b82db8 norm  NormalizeInfluenceMatrix 0x40ce1a-0x40d012
    DAT_00b84948 B     GenerateOrders 0x446885-0x4471a3

The port used to run all three computations in g_influence_matrix, so CAL_BOARD
read whichever ran last.
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
generation = __import__(f'{_pkg}.monte_carlo.generation', fromlist=['generate_orders'])
_influence = __import__(f'{_pkg}.heuristics.influence', fromlist=['compute_influence_matrix'])

SENTINEL = 123.0


def _seeded_state():
    s = InnerGameState()
    s.g_influence_matrix_raw[:] = np.arange(1.0, 50.0).reshape(7, 7)
    return s


def test_generate_orders_leaves_compute_influence_matrix_output_alone(monkeypatch):
    s = InnerGameState()
    s.g_influence_matrix.fill(SENTINEL)
    heat = np.arange(1.0, 50.0).reshape(7, 7)
    monkeypatch.setattr(generation, "_sum_influence_heat", lambda st, p, col, *a, **k: float(heat[col, p]))
    generation.generate_orders(s, 0)
    assert np.all(s.g_influence_matrix == SENTINEL)
    np.testing.assert_allclose(s.g_influence_matrix_raw, heat)
    assert s.g_influence_matrix_b.any()


def test_normalize_writes_only_matrix_a():
    s = _seeded_state()
    s.g_influence_matrix.fill(SENTINEL)
    s.g_influence_matrix_b.fill(SENTINEL)
    _influence.normalize_influence_matrix(s)
    assert np.all(s.g_influence_matrix == SENTINEL)
    assert np.all(s.g_influence_matrix_b == SENTINEL)
    assert abs(s.g_influence_matrix_norm[3].sum() - 100.0) < 1e-9


def test_compute_writes_only_g_influence_matrix():
    s = _seeded_state()
    s.g_influence_matrix_norm.fill(SENTINEL)
    s.g_influence_matrix_b.fill(SENTINEL)
    _influence.compute_influence_matrix(s, 0)
    assert np.all(s.g_influence_matrix_norm == SENTINEL)
    assert np.all(s.g_influence_matrix_b == SENTINEL)
    assert abs(s.g_influence_matrix[3].sum() - 100.0) < 1e-9


def test_cal_board_input_survives_later_normalize():
    s = _seeded_state()
    _influence.compute_influence_matrix(s, 0)
    m = s.g_influence_matrix.copy()
    s.g_ally_trust_score[:] = 3
    _influence.normalize_influence_matrix(s)
    np.testing.assert_array_equal(s.g_influence_matrix, m)
