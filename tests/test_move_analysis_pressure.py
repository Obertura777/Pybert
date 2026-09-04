"""Source-parity regressions for MOVE_ANALYSIS pressure construction."""

from pathlib import Path
import sys


_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_analysis = __import__(
    f"{_PKG}.bot.analysis",
    fromlist=["_build_move_pressure_matrices", "_move_analysis"],
)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_flags = __import__(
    f"{_PKG}.monte_carlo._flags",
    fromlist=["_F_ORDER_TYPE", "_F_DEST_PROV", "_ORDER_MTO"],
)

_build_move_pressure_matrices = _analysis._build_move_pressure_matrices
_move_analysis = _analysis._move_analysis
InnerGameState = _state.InnerGameState
_F_ORDER_TYPE = _flags._F_ORDER_TYPE
_F_DEST_PROV = _flags._F_DEST_PROV
_ORDER_MTO = _flags._ORDER_MTO


def _pressure_state() -> InnerGameState:
    state = InnerGameState()
    defending_sc, boundary, attacker = 10, 20, 30
    state.sc_provinces = {defending_sc}
    state.g_sc_owner[defending_sc] = 0
    state.unit_info[attacker] = {
        'power': 1, 'type': 'A', 'coast': '',
    }
    state.adj_matrix = {
        defending_sc: [boundary],
        boundary: [defending_sc, attacker],
        attacker: [boundary],
    }
    state.g_order_table[attacker, _F_ORDER_TYPE] = _ORDER_MTO
    state.g_order_table[attacker, _F_DEST_PROV] = boundary
    return state


def test_move_pressure_starts_from_controlled_sc_not_defending_unit():
    state = _pressure_state()

    bcd0, af00, b5e8 = _build_move_pressure_matrices(state, 3)

    assert b5e8[0, 1] == 1
    assert bcd0[0, 1] == 1
    assert af00[0, 1] == 0


def test_move_pressure_source_token_read_keeps_attacker_controlled_boundary():
    state = _pressure_state()
    boundary = 20
    state.sc_provinces.add(boundary)
    state.g_sc_owner[boundary] = 1

    bcd0, _af00, b5e8 = _build_move_pressure_matrices(state, 3)

    # C checks boundary's SC marker but reuses the source centre's controller
    # token; for an off-diagonal pair the boundary is still marked.
    assert b5e8[0, 1] == 1
    assert bcd0[0, 1] == 1


def test_move_pressure_filters_attacker_reach_by_unit_terrain():
    state = _pressure_state()
    boundary = 20
    state.water_provinces = frozenset({boundary})

    bcd0, _af00, b5e8 = _build_move_pressure_matrices(state, 3)

    assert b5e8[0, 1] == 0
    assert bcd0[0, 1] == 0


def test_no_press_mode_does_not_suppress_move_analysis_trust_updates():
    state = InnerGameState()
    defending_sc, boundary, attacker = 10, 20, 30
    state.albert_power_idx = 0
    state.g_minimal_press_mode = 1
    state.g_deceit_level = 1
    state.g_season = 'FAL'
    state.sc_provinces = {defending_sc}
    state.g_sc_owner[defending_sc] = 0
    state.unit_info[attacker] = {
        'power': 1, 'type': 'A', 'coast': '',
    }
    state.adj_matrix = {
        defending_sc: [boundary],
        boundary: [defending_sc, attacker],
        attacker: [boundary],
    }

    _move_analysis(state)

    # With one non-aggressive pressure relationship, C raises trust to one
    # and promotes that sole exact trust-1 power to the opening enemy.
    assert state.g_opening_sticky_mode == 1
    assert state.g_opening_enemy == 1
    assert state.g_stabbed_flag == 1


def test_move_analysis_preserves_source_partial_ally_slot_shift():
    state = InnerGameState()
    state.albert_power_idx = 0
    state.g_deceit_level = 1
    state.g_season = 'FAL'
    state.g_best_ally_slot0 = 1
    state.g_best_ally_slot1 = 2
    state.g_best_ally_slot2 = 3
    state.g_ally_trust_score[0, 1] = 0
    state.g_ally_trust_score[0, 2] = 0
    state.g_ally_trust_score[0, 3] = 3

    _move_analysis(state)

    assert (
        state.g_best_ally_slot0,
        state.g_best_ally_slot1,
        state.g_best_ally_slot2,
    ) == (-1, 3, -1)
