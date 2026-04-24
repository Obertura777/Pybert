"""Integration tests for build_convoy_orders (moves/convoy.py).

Verifies that the simplified Python convoy-order assembly correctly sets
g_order_table fields, scores, and fleet registration for 1-, 2-, and 3-fleet
convoy chains.  These scenarios exercise the code path that diverges most
from the C original (BuildConvoyOrders.c), which used BuildOrder_CTO,
BuildOrder_CVY, ConvoyList_Insert, and MoveCandidate helpers.

Compares against expected g_order_table state derived from the C decompile.
"""

import numpy as np
import pytest
import sys, os

# Ensure the *parent* of the Pybert package is on sys.path so that
# ``import Pybert.moves`` etc. resolve correctly with relative imports.
_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent   = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

# Now use the package's own name — the Pybert directory is the package.
_pkg_name = os.path.basename(_pkg_root)
_state     = __import__(f'{_pkg_name}.state',       fromlist=['InnerGameState'])
_constants = __import__(f'{_pkg_name}.moves._constants', fromlist=['_F_ORDER_TYPE'])
_convoy    = __import__(f'{_pkg_name}.moves.convoy', fromlist=['build_convoy_orders'])

InnerGameState      = _state.InnerGameState
build_convoy_orders = _convoy.build_convoy_orders
register_convoy_fleet = _convoy.register_convoy_fleet

_F_ORDER_TYPE    = _constants._F_ORDER_TYPE
_F_DEST_PROV     = _constants._F_DEST_PROV
_F_INCOMING_MOVE = _constants._F_INCOMING_MOVE
_F_ORDER_ASGN    = _constants._F_ORDER_ASGN
_F_CONVOY_LEG0   = _constants._F_CONVOY_LEG0
_F_CONVOY_LEG1   = _constants._F_CONVOY_LEG1
_F_CONVOY_LEG2   = _constants._F_CONVOY_LEG2
_F_SOURCE_PROV   = _constants._F_SOURCE_PROV
_ORDER_CVY       = _constants._ORDER_CVY
_ORDER_CTO       = _constants._ORDER_CTO


# ── Diplomacy province IDs (arbitrary but consistent for tests) ──────────────
LON = 10   # London (coastal, army start)
NTH = 20   # North Sea (water, fleet 1)
NWG = 30   # Norwegian Sea (water, fleet 2)
BAR = 40   # Barents Sea (water, fleet 3)
STP = 50   # St. Petersburg (coastal, army destination)
ENG = 60   # English Channel (water, unused fleet)

POWER_ENG = 0  # England


def _make_state(army_src, army_dst, fleet_provs, adj_map):
    """Build a minimal InnerGameState for convoy testing."""
    state = InnerGameState()

    # Adjacency matrix — only the edges needed for the convoy chain.
    state.adj_matrix = {k: list(v) for k, v in adj_map.items()}

    # Unit placement: army at src, fleets along the chain.
    state.unit_info = {
        army_src: {'power': POWER_ENG, 'type': 'A', 'coast': ''},
    }
    for fp in fleet_provs:
        state.unit_info[fp] = {'power': POWER_ENG, 'type': 'F', 'coast': ''}

    # Water / land classification.
    state.water_provinces = frozenset(fleet_provs)
    state.land_provinces = frozenset()  # treat src/dst as coastal (not land-only)

    # Pre-populate convoy route (normally done by populate_convoy_routes).
    state.g_convoy_route = {
        army_src: {
            army_dst: {
                'fleet_count': len(fleet_provs),
                'fleets': list(fleet_provs),
            }
        }
    }

    # Seed scores so we can verify they propagate.
    state.g_candidate_scores = np.zeros((7, 256), dtype=np.float64)
    state.g_candidate_scores[POWER_ENG, army_dst] = 42.0  # army inherits this

    for fp in fleet_provs:
        state.g_max_province_score[fp] = 10.0 + fp  # distinct per fleet

    # register_convoy_fleet needs these:
    state.g_army_adj_count = np.zeros(256, dtype=np.int32)
    state.g_province_access_flag = np.zeros((7, 256), dtype=np.int32)
    state.g_province_score_trial = np.zeros(256, dtype=np.int32)
    state.g_convoy_fleet_registered = set()

    # assign_support_order reads several arrays — stub them to avoid crashes.
    # (We're testing the order-table writes, not the full support pipeline.)
    state.g_supportable_flag = np.zeros(256, dtype=np.int32)
    state.g_enemy_reach_score = np.zeros((7, 256), dtype=np.float64)

    return state


# ═════════════════════════════════════════════════════════════════════════════
#  1-fleet convoy:  LON → NTH → STP
# ═════════════════════════════════════════════════════════════════════════════

class TestSingleFleetConvoy:
    """A LON → (NTH) → STP convoy with one fleet."""

    @pytest.fixture
    def state(self):
        adj = {
            LON: [NTH],
            NTH: [LON, STP],
            STP: [NTH],
        }
        return _make_state(LON, STP, [NTH], adj)

    def test_army_order_type_is_cto(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_ORDER_TYPE] == _ORDER_CTO

    def test_army_destination(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_DEST_PROV] == STP

    def test_army_committed(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_ORDER_ASGN] == 1

    def test_convoy_leg0_set(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_CONVOY_LEG0] == NTH

    def test_convoy_leg1_unset(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        # Only 1 fleet — leg1 should remain at initial value (0).
        assert state.g_order_table[LON, _F_CONVOY_LEG1] == 0

    def test_fleet_order_type_is_cvy(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[NTH, _F_ORDER_TYPE] == _ORDER_CVY

    def test_fleet_source_prov(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[NTH, _F_SOURCE_PROV] == LON

    def test_fleet_dest_prov(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[NTH, _F_DEST_PROV] == STP

    def test_fleet_committed(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[NTH, _F_ORDER_ASGN] == 1

    def test_army_score_propagated(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_convoy_chain_score[LON] == 42.0
        assert state.g_order_score_hi[LON] == 42.0

    def test_fleet_score_from_max_province(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        expected = 10.0 + NTH  # g_max_province_score[NTH]
        assert state.g_convoy_chain_score[NTH] == expected
        assert state.g_order_score_hi[NTH] == expected

    def test_convoy_dst_to_src(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_convoy_dst_to_src[STP] == LON


# ═════════════════════════════════════════════════════════════════════════════
#  2-fleet convoy:  LON → NTH → NWG → STP
# ═════════════════════════════════════════════════════════════════════════════

class TestTwoFleetConvoy:
    """LON → (NTH, NWG) → STP with two fleets."""

    @pytest.fixture
    def state(self):
        adj = {
            LON: [NTH],
            NTH: [LON, NWG],
            NWG: [NTH, STP],
            STP: [NWG],
        }
        return _make_state(LON, STP, [NTH, NWG], adj)

    def test_army_cto_with_two_legs(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_ORDER_TYPE] == _ORDER_CTO
        assert state.g_order_table[LON, _F_CONVOY_LEG0] == NTH
        assert state.g_order_table[LON, _F_CONVOY_LEG1] == NWG
        assert state.g_order_table[LON, _F_CONVOY_LEG2] == 0  # unused

    def test_both_fleets_get_cvy_orders(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        for fleet_prov in [NTH, NWG]:
            assert state.g_order_table[fleet_prov, _F_ORDER_TYPE] == _ORDER_CVY
            assert state.g_order_table[fleet_prov, _F_SOURCE_PROV] == LON
            assert state.g_order_table[fleet_prov, _F_DEST_PROV] == STP
            assert state.g_order_table[fleet_prov, _F_ORDER_ASGN] == 1

    def test_fleet_scores_distinct(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_convoy_chain_score[NTH] == 10.0 + NTH
        assert state.g_convoy_chain_score[NWG] == 10.0 + NWG


# ═════════════════════════════════════════════════════════════════════════════
#  3-fleet convoy:  LON → NTH → NWG → BAR → STP
# ═════════════════════════════════════════════════════════════════════════════

class TestThreeFleetConvoy:
    """LON → (NTH, NWG, BAR) → STP with three fleets (max chain)."""

    @pytest.fixture
    def state(self):
        adj = {
            LON: [NTH],
            NTH: [LON, NWG],
            NWG: [NTH, BAR],
            BAR: [NWG, STP],
            STP: [BAR],
        }
        return _make_state(LON, STP, [NTH, NWG, BAR], adj)

    def test_army_cto_with_three_legs(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_ORDER_TYPE] == _ORDER_CTO
        assert state.g_order_table[LON, _F_CONVOY_LEG0] == NTH
        assert state.g_order_table[LON, _F_CONVOY_LEG1] == NWG
        assert state.g_order_table[LON, _F_CONVOY_LEG2] == BAR

    def test_all_three_fleets_get_cvy(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        for fp in [NTH, NWG, BAR]:
            assert state.g_order_table[fp, _F_ORDER_TYPE] == _ORDER_CVY
            assert state.g_order_table[fp, _F_ORDER_ASGN] == 1

    def test_all_fleet_scores(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        for fp in [NTH, NWG, BAR]:
            assert state.g_convoy_chain_score[fp] == 10.0 + fp

    def test_army_score(self, state):
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_convoy_chain_score[LON] == 42.0


# ═════════════════════════════════════════════════════════════════════════════
#  Edge cases
# ═════════════════════════════════════════════════════════════════════════════

class TestConvoyEdgeCases:
    """No route, empty route, etc."""

    def test_no_route_is_noop(self):
        """build_convoy_orders with no g_convoy_route entry should be a no-op."""
        state = InnerGameState()
        state.g_convoy_route = {}
        state.g_candidate_scores = np.zeros((7, 256), dtype=np.float64)
        # Should not raise or modify order table.
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_ORDER_TYPE] == 0  # untouched

    def test_zero_fleet_count_is_noop(self):
        """Route registered but fleet_count == 0 → no-op."""
        state = InnerGameState()
        state.g_convoy_route = {
            LON: {STP: {'fleet_count': 0, 'fleets': []}}
        }
        state.g_candidate_scores = np.zeros((7, 256), dtype=np.float64)
        build_convoy_orders(state, POWER_ENG, LON, STP)
        assert state.g_order_table[LON, _F_ORDER_TYPE] == 0
