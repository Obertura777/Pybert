"""Influence-matrix noise must match Albert.exe 0x40da50-0x40da97 (and 0x40cf10, 0x4470e0).

    sum[r] = FloatToInt64(sum(row r))
    m[r, c] += 500 * pow(100 * m[r, c] / (sum[c] + 1), 1.2)

Constants read from .rdata: 0x4afa00 = 100.0, 0x4af9f8 = 1.2, 0x4af9f0 = 500.0.
"""
import os
import sys

_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)
_pkg = os.path.basename(_pkg_root)

import numpy as np

_inject_influence_noise = getattr(__import__(f'{_pkg}.heuristics._primitives', fromlist=['_inject_influence_noise']), '_inject_influence_noise')


def _expected(m):
    n = m.shape[0]
    s = [int(np.sum(m[r])) for r in range(n)]
    out = m.copy()
    for r in range(n):
        for c in range(n):
            out[r, c] += 500.0 * (100.0 * m[r, c] / (s[c] + 1)) ** 1.2
    return out


def test_noise_uses_binary_constants_and_column_indexed_row_sum():
    rng = np.random.default_rng(7)
    m = rng.uniform(0.0, 40.0, size=(7, 7))
    m[0, :] *= 5.0  # rows with very different sums make row-vs-column indexing observable
    want = _expected(m)
    got = m.copy()
    _inject_influence_noise(got, 7)
    np.testing.assert_allclose(got, want, rtol=1e-12)


def test_noise_is_not_the_old_exponent_0_3_form():
    m = np.full((7, 7), 3.0)
    got = m.copy()
    _inject_influence_noise(got, 7)
    old = m + 500.0 * (m / (21 + 1)) ** 0.3
    assert not np.allclose(got, old)


def test_zero_cell_gets_no_noise():
    m = np.zeros((7, 7))
    _inject_influence_noise(m, 7)
    assert np.all(m == 0.0)
