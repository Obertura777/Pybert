"""Source-backed control-flow regressions for SnapshotProvinceState."""

from pathlib import Path
import sys

import numpy as np

_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_snapshot = __import__(
    f"{_PKG}.heuristics.snapshot", fromlist=["snapshot_province_state"]
)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

snapshot_province_state = _snapshot.snapshot_province_state
InnerGameState = _state.InnerGameState


def _state3() -> InnerGameState:
    state = InnerGameState()
    state.g_num_powers = 3
    state.num_valid_provinces = 12
    state.albert_power_idx = 0
    state.g_season = "SPR"
    return state


def _army(power: int) -> dict:
    return {"power": power, "type": "A", "coast": ""}


def test_unsigned_low_word_promotes_coordinated_target():
    state = _state3()
    state.unit_info = {4: _army(0), 5: _army(1)}
    state.sc_provinces = {4, 5}
    state.g_sc_owner[4] = 0
    state.g_sc_owner[5] = 1
    state.adj_matrix = {4: [6], 5: [6]}
    state.g_ally_trust_score[0, 1] = -1
    state.g_ally_trust_score_hi[0, 1] = 0

    snapshot_province_state(state)

    assert int(state.g_target_flag[0, 6]) == 2


def test_nonally_clear_uses_victim_to_owner_trust_orientation():
    state = _state3()
    state.unit_info = {4: _army(0), 5: _army(1)}
    state.sc_provinces = {4, 5}
    state.g_sc_owner[4] = 0
    state.g_sc_owner[5] = 1
    state.adj_matrix = {4: [6], 5: [6]}
    state.g_ally_trust_score[0, 1] = 2
    state.g_ally_trust_score[1, 0] = 0

    snapshot_province_state(state)

    assert int(state.g_target_flag[0, 6]) == 2


def test_alliance_sharing_marks_occupied_reach_and_emits_event_three():
    state = _state3()
    state.g_other_power_lead_flag = 1
    state.g_deceit_level = 0
    state.g_ally_under_attack = 1
    state.g_best_ally_slot0 = 1
    state.unit_info = {
        4: _army(0),
        5: _army(1),
        6: _army(2),
    }
    state.sc_provinces = {4, 6}
    state.g_sc_owner[4] = 0
    state.g_sc_owner[6] = 2
    state.adj_matrix = {4: [6], 5: [6], 6: []}

    snapshot_province_state(state)

    assert int(state.g_ally_designation_c[6]) == 1
    assert int(state.g_ally_designation_c_hi[6]) == 0
    assert 3 in state.g_alliance_msg_tree


def test_resets_and_season_copy_are_bounded_by_runtime_province_count():
    state = _state3()
    state.g_num_powers = 2
    state.num_valid_provinces = 3
    for name in (
        "g_ally_designation_b",
        "g_ally_designation_b_hi",
        "g_ally_designation_a",
        "g_ally_designation_a_hi",
        "g_ally_designation_c",
        "g_ally_designation_c_hi",
        "g_assault_flag",
        "g_assault_flag_hi",
        "g_spr_desig_b",
        "g_spr_desig_b_hi",
        "g_spr_desig_a",
        "g_spr_desig_a_hi",
        "g_spr_desig_c",
        "g_spr_desig_c_hi",
    ):
        getattr(state, name).fill(9)
    state.g_AttackMap.fill(9)
    state.g_target_flag.fill(4)
    state.g_other_power_lead_flag = 1

    snapshot_province_state(state)

    assert np.all(state.g_ally_designation_a[:3] == -1)
    assert np.all(state.g_spr_desig_a[:3] == -1)
    assert np.all(state.g_AttackMap[:2, :3] == 4)
    assert int(state.g_ally_designation_a[3]) == 9
    assert int(state.g_spr_desig_a[3]) == 9
    assert int(state.g_AttackMap[2, 3]) == 9
