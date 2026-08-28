"""Source-backed send_GOF chronology and retreat-selection regressions."""

from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch
import sys


_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_orders = __import__(f"{_PKG}.bot.orders", fromlist=["_populate_retreat_orders"])
_client_orders = __import__(
    f"{_PKG}.bot.client._orders", fromlist=["_run_send_gof_candidate_pass"]
)
_rng = __import__(f"{_PKG}.rng", fromlist=["seed"])
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

_populate_retreat_orders = _orders._populate_retreat_orders
_run_send_gof_candidate_pass = _client_orders._run_send_gof_candidate_pass
InnerGameState = _state.InnerGameState


def _retreat_state() -> InnerGameState:
    state = InnerGameState()
    state.albert_power_idx = 0
    state.g_num_powers = 3
    state.num_valid_provinces = 12
    state.prov_to_id = {
        "SRC1": 1, "SRC2": 2, "DST1": 3, "DST2": 4, "DST3": 5,
    }
    return state


def test_retreat_uses_token_specific_scored_key_not_global_heat():
    state = _retreat_state()
    state.dislodged_unit_info[1] = {
        "power": 0,
        "type": "F",
        "coast": "",
        "retreats": ["DST1", "DST2"],
    }
    state.final_score_set_flt[0, 3] = 10
    state.final_score_set_flt[0, 4] = 100
    state.g_global_province_score[3] = 1000
    state.g_global_province_score[4] = 0

    _rng.seed(1)
    orders = _populate_retreat_orders(
        state, SimpleNamespace(powers={}), "AUSTRIA", 0
    )

    assert orders[0]["dest_province"] == 4


def test_retreat_random_source_priority_prevents_shared_destination():
    state = _retreat_state()
    state.dislodged_unit_info = {
        1: {
            "power": 0, "type": "A", "coast": "",
            "retreats": ["DST1", "DST2"],
        },
        2: {
            "power": 0, "type": "A", "coast": "",
            "retreats": ["DST1", "DST3"],
        },
    }
    state.final_score_set[0, 3] = 100
    state.final_score_set[0, 4] = 20
    state.final_score_set[0, 5] = 10

    # Seed 1 gives SRC2 the larger of the first two source-priority draws.
    _rng.seed(1)
    orders = _populate_retreat_orders(
        state, SimpleNamespace(powers={}), "AUSTRIA", 0
    )
    selected = {
        order["province"]: order["dest_province"] for order in orders
    }

    assert selected == {2: 3, 1: 4}
    assert len(set(selected.values())) == 2


def test_retreat_avoids_non_enemy_dmz_promise_and_trusted_ally_claim():
    state = _retreat_state()
    state.dislodged_unit_info[1] = {
        "power": 0,
        "type": "A",
        "coast": "",
        "retreats": ["DST1", "DST2", "DST3"],
    }
    state.final_score_set[0, 3:6] = [300, 200, 100]
    state.g_ally_promise_list = {1: [{"dest_prov": 3}]}

    # An own-controlled SC with A-designation unset enables the source's
    # trusted-designation exclusion. DST2 is claimed by trusted power 2.
    state.sc_provinces = frozenset({9})
    state.g_sc_owner[9] = 0
    state.g_ally_designation_a[4] = 2
    state.g_ally_designation_a_hi[4] = 0
    state.g_ally_trust_score[0, 2] = 1
    state.g_ally_trust_score_hi[0, 2] = 0

    _rng.seed(1)
    orders = _populate_retreat_orders(
        state, SimpleNamespace(powers={}), "AUSTRIA", 0
    )

    assert orders[0]["dest_province"] == 5


def test_send_gof_scores_sum_and_aut_but_never_runs_process_turn():
    state = SimpleNamespace(
        g_spr_move_weight=11,
        g_spr_build_weight=12,
        g_spr_round_weights=[13],
        g_fal_move_weight=21,
        g_fal_build_weight=22,
        g_fal_round_weights=[23],
    )
    events = []

    def score_provinces(_state, move, build, own):
        events.append(("provinces", move, build, own))

    def score_candidates(_state, rounds, own):
        events.append(("candidates", list(rounds), own))

    patches = (
        patch.object(_client_orders, "snapshot_province_state",
                     side_effect=lambda _state: events.append(("snapshot",))),
        patch.object(_client_orders, "_reset_send_gof_order_state",
                     side_effect=lambda _state: events.append(("reset",))),
        patch.object(_client_orders, "score_provinces",
                     side_effect=score_provinces),
        patch.object(_client_orders, "score_order_candidates_all_powers",
                     side_effect=score_candidates),
        patch.object(_client_orders, "process_turn",
                     side_effect=AssertionError("retreat must not run ProcessTurn")),
        patch.object(_client_orders, "compute_safe_reach",
                     side_effect=AssertionError("retreat must not compute safe reach")),
        patch.object(_client_orders, "enumerate_hold_orders",
                     side_effect=AssertionError("retreat must not enumerate holds")),
    )

    with (patches[0], patches[1], patches[2], patches[3], patches[4],
          patches[5], patches[6]):
        assert _run_send_gof_candidate_pass(state, "SUM", 0, 3) == []
        assert _run_send_gof_candidate_pass(state, "AUT", 0, 3) == []

    assert events == [
        ("snapshot",), ("reset",),
        ("provinces", 11, 12, 0), ("candidates", [13], 0),
        ("snapshot",), ("reset",),
        ("provinces", 21, 22, 0), ("candidates", [23], 0),
    ]


def test_send_gof_builds_safe_reach_and_holds_after_final_scoring():
    state = SimpleNamespace(
        g_spr_move_weight=11,
        g_spr_build_weight=12,
        g_spr_round_weights=[13],
        g_fal_move_weight=21,
        g_fal_build_weight=22,
        g_fal_round_weights=[23],
        g_trial_scale=260,
        g_press_proposals_cap=30,
        g_unit_count=[0, 0, 0],
        g_current_round=0,
        g_candidate_record_list=[],
    )
    events = []

    with (
        patch.object(_client_orders, "snapshot_province_state",
                     side_effect=lambda _state: events.append("snapshot")),
        patch.object(_client_orders, "_reset_send_gof_order_state",
                     side_effect=lambda _state: events.append("reset")),
        patch.object(_client_orders, "score_provinces",
                     side_effect=lambda *_args: events.append("score-provinces")),
        patch.object(_client_orders, "score_order_candidates_all_powers",
                     side_effect=lambda *_args: events.append("score-candidates")),
        patch.object(_client_orders, "compute_safe_reach",
                     side_effect=lambda _state: events.append("safe-reach")),
        patch.object(_client_orders, "enumerate_hold_orders",
                     side_effect=lambda _state, power: events.append(f"holds-{power}")),
        patch.object(_client_orders, "_prepare_proposal_orders_for_turn",
                     side_effect=lambda _state: events.append("proposals")),
        patch.object(_client_orders, "check_time_limit", return_value=False),
    ):
        assert _run_send_gof_candidate_pass(state, "SPR", 0, 3) == []

    assert events == [
        "snapshot", "reset", "score-provinces", "score-candidates",
        "safe-reach", "holds-0", "holds-1", "holds-2", "proposals",
    ]
