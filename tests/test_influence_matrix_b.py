"""g_influence_matrix_b is GenerateOrders' noised, row-normalised matrix (DAT_00b84948).

Albert.exe 0x447020 copies B to raw first, then noises (0x4470e0) and normalises
(0x447156) B in place, so B != raw and B's non-empty rows sum to 100.
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


def test_matrix_b_is_post_noise_and_normalised(monkeypatch):
    state = InnerGameState()
    heat = np.arange(1.0, 50.0).reshape(7, 7)

    def fake_sum(state_, p, col, *a, **k):
        return float(heat[col, p])

    monkeypatch.setattr(generation, "_sum_influence_heat", fake_sum)
    generation.generate_orders(state, 0)
    b, raw = state.g_influence_matrix_b, state.g_influence_matrix_raw
    assert raw.any()
    assert not np.allclose(b, raw)
    for r in range(7):
        if raw[r].any():
            assert abs(b[r].sum() - 100.0) < 1e-9
