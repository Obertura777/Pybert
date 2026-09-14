"""Albert's SCO hook FUN_0040e700: the static-map DRW counter."""

from pathlib import Path
import sys


_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_board = __import__(f"{_PKG}.heuristics.board", fromlist=["cal_board"])
InnerGameState = _state.InnerGameState


class _Game:
    def __init__(self):
        self.phase = "S1901M"
        self.centers = {"FRANCE": ["BRE", "MAR", "PAR"], "ENGLAND": ["LON"]}

    def get_current_phase(self):
        return self.phase

    def get_centers(self):
        return self.centers

    def get_units(self):
        return {}


def _sync(state, game, phase, centers=None):
    game.phase = phase
    if centers is not None:
        game.centers = centers
    state.synchronize_from_game(game)
    return state.g_sco_repeat_count, state.g_static_map_flag


def test_flag_rises_only_after_the_third_identical_sco():
    state = InnerGameState()
    state.prov_to_id = {"BRE": 0, "MAR": 1, "PAR": 2, "LON": 3}
    game = _Game()

    # The first SCO is compared with the empty list and never matches.
    assert _sync(state, game, "S1901M") == (0, 0)
    assert _sync(state, game, "F1901M") == (1, 0)
    assert _sync(state, game, "W1901A") == (2, 0)
    assert _sync(state, game, "S1902M") == (3, 1)
    assert _sync(state, game, "F1902M") == (4, 1)


def test_any_ownership_change_resets_counter_and_flag():
    state = InnerGameState()
    state.prov_to_id = {"BRE": 0, "MAR": 1, "PAR": 2, "LON": 3, "BEL": 4}
    game = _Game()
    for phase in ("S1901M", "F1901M", "W1901A", "S1902M"):
        _sync(state, game, phase)
    assert state.g_static_map_flag == 1

    changed = {"FRANCE": ["BEL", "BRE", "MAR", "PAR"], "ENGLAND": ["LON"]}
    assert _sync(state, game, "W1902A", changed) == (0, 0)


def test_resynchronising_the_same_phase_does_not_count_twice():
    state = InnerGameState()
    state.prov_to_id = {"BRE": 0, "MAR": 1, "PAR": 2, "LON": 3}
    game = _Game()
    _sync(state, game, "S1901M")
    _sync(state, game, "F1901M")
    assert _sync(state, game, "F1901M") == (1, 0)


def test_cal_board_static_map_does_not_raise_request_draw_flag():
    state = InnerGameState()
    state.g_static_map_flag = 1
    _board.cal_board(state, 0)
    assert state.g_request_draw_flag == 0
