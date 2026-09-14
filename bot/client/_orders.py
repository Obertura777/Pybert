"""Order-generation mixin half of AlbertClient.

Split from bot/client.py during the 2026-04 refactor.

Holds the per-turn order-generation pipeline methods:

  * ``generate_and_submit_orders`` — the main 450-line routine that runs
    Monte-Carlo order search, scoring, filtering, and submission for
    the current phase.
  * ``_validate_orders``           — cross-checks submitted orders
    against ``game.get_all_possible_orders()``.
  * ``_submit_adjustment_orders``  — builds/removes phase submission.

Composed with ``_LifecycleMixin`` and ``_PressMixin`` to form
``AlbertClient``; cross-mixin method calls resolve through MRO at
call time.  Imports are minimised here (the mixin only uses
``self.X`` — the heavy imports are already pulled in by
``_lifecycle.py``), but a small set of names needed *at definition*
time (type hints, decorators, module-level references inside method
bodies) still live here.
"""

from __future__ import annotations

import asyncio
import copy
import logging
import time
from typing import Any, Callable

import numpy as np

from ...state import InnerGameState
from ...monte_carlo import (
    process_turn,
    check_time_limit,
    _F_ORDER_TYPE, _F_DEST_PROV, _F_DEST_COAST,
)
from ...communications import (
    parse_message,
    dispatch_scheduled_press,
    cancel_prior_press,
)
from ...heuristics import (
    score_provinces,
    score_order_candidates_all_powers,
    score_order_candidates_own_power,
    compute_build_delta,
    populate_build_candidates,
    populate_remove_candidates,
    compute_win_builds,
    compute_win_removes,
    _WIN_BUILD_WEIGHTS,
    _WIN_REMOVE_WEIGHTS,
    snapshot_province_state,
)
from ...dispatch import validate_and_dispatch_order
from ...moves import compute_safe_reach, enumerate_hold_orders

from .._shared import _POWER_NAMES
from ..orders import (
    _init_position_for_orders,
    _populate_retreat_orders,
    _format_retreat_commands,
    _build_order_seq_from_table,
)
from ..gof import _send_gof, _evaluate_order_proposals_and_send_gof
from ..analysis import (
    _phase_handler, _analyze_position, _move_analysis,
    _post_process_orders, _compute_press,
    _cleanup_turn, _prepare_draw_vote_set,
    _rank_candidates_for_power,
    _game_phase, _game_status,
)
from ..strategy import (
    _stabbed, _deviate_move, _friendly, _hostility, _post_friendly_update,
    _destroy_candidate_tree,
)

logger = logging.getLogger(__name__)


def _begin_turn_timing(state: InnerGameState, now: float | None = None) -> None:
    """Reset the C move-timer state and establish this phase's deadline."""
    if now is None:
        now = time.time()
    state.g_turn_start_time = float(now)
    state.mtl_expired = 0
    move_limit = int(getattr(state, 'g_move_time_limit_sec', 0))
    state.g_turn_deadline = (
        float(now) + move_limit if move_limit > 0 else 0.0
    )


def _refresh_opening_turn_flag(state: InnerGameState) -> None:
    """GenerateAndSubmitOrders.c:125-131 (0x0045953f-0x0045955e).

    DAT_00baed68 is cleared when set, then set from DAT_004c6bdc, which is
    cleared in turn.  Neither has another writer and DAT_004c6bdc starts at 1,
    so the flag is 1 for the first call only, whatever the press level.
    """
    if int(state.g_press_flag) == 1:
        state.g_press_flag = 0
    if int(getattr(state, 'g_opening_turn_pending', 0)) == 1:
        state.g_press_flag = 1
        state.g_opening_turn_pending = 0


def _insert_base_broadcast_node(state: InnerGameState) -> dict:
    """GenerateAndSubmitOrders.c:130-149, 405-460 — the base SUB record.

    C seeds both best-order tables (DAT_00bbf690/694 and the DAT_00bc0a40/44
    snapshot) and, for a movement phase, inserts the key-zero SUB record:
    every power a participant, content ``SUB ( turn )``, no reference key,
    and — when Albert has no units — already done at the trial cap.
    """
    cap = max(int(getattr(state, 'g_press_proposals_cap', 30)), 0)
    own = int(getattr(state, 'albert_power_idx', 0))
    own_units = int(state.g_unit_count[own]) if own < len(state.g_unit_count) else 0
    state.g_current_best_order = {}
    state.g_current_best_order_records = {}
    state.g_best_order_backup = {}
    n_powers = len(state.g_unit_count)
    from ...communications import send_alliance_press
    return send_alliance_press(state, key=0, entry_data={
        'base_sub': True,
        'sent': own_units == 0,
        'type_flag': 0,
        'trial_count': cap if own_units == 0 else 0,
        'score_vector': [0] * 7,
        'history_flag': 0,
        'watermark': None,
        'received_flag': False,
        'sublist3': ['SUB'],
        'order_candidates': [{'tokens': ['SUB'], 'type_flag': 0}],
        'participant_powers': set(range(n_powers)),
    })


def _normalize_broadcast_nodes(state: InnerGameState) -> None:
    """send_GOF.c:170-282 — re-arm the broadcast records before BuildAndSendSUB.

    After the ten ProcessTurn rounds, every key-zero record is rebuilt as an
    unfinished base SUB at trial zero (set A cleared, type 0, flag byte 0,
    zero scores); every self-generated record (type 1) is retired as type -1,
    done at the cap; every unfinished received record (type 0) is rewound to
    trial zero.
    """
    cap = max(int(getattr(state, 'g_press_proposals_cap', 30)), 0)
    for entry in getattr(state, 'g_broadcast_list', None) or []:
        if int(entry.get('key', 0)) == 0:
            entry['trial_count'] = 0
            entry['type_flag'] = 0
            entry['sent'] = False
            entry['received_flag'] = False
            entry['score_vector'] = [0] * 7
            entry['history_flag'] = 0
            entry['flag'] = 0
            entry['sublist3'] = ['SUB']
            entry.pop('clause_set_a', None)
            entry['order_candidates'] = [
                {'tokens': ['SUB'], 'type_flag': 0}
            ]
        elif int(entry.get('type_flag', 0)) == 1:
            entry['type_flag'] = -1
            entry['trial_count'] = cap
            entry['sent'] = True
        elif (int(entry.get('type_flag', 0)) == 0
              and not entry.get('sent', False)):
            entry['trial_count'] = 0


def _prepare_broadcast_nodes_for_movement(state: InnerGameState) -> dict:
    """Insert the base SUB record and apply send_GOF's normalisation."""
    base = _insert_base_broadcast_node(state)
    _normalize_broadcast_nodes(state)
    return base


def _prepare_proposal_orders_for_turn(state: InnerGameState) -> None:
    """send_GOF.c:101-112 — clear the general-order trees before ProcessTurn.

    After ComputeSafeReach and EnumerateHoldOrders, C zeroes DAT_00b9fe88[p]
    and destroys DAT_00bb6cf8[p] (``g_general_orders``) for every power, so
    the ten ProcessTurn rounds see no general orders at all.  The alliance
    orders (DAT_00bb65f8) keep the XDOs agreed this turn: XDO() writes them
    and GenerateAndSubmitOrders clears them.  BuildAndSendSUB fills the
    general orders per node, from that node's set A, on its round zero.
    """
    for power in range(7):
        _destroy_candidate_tree(state.g_general_orders.get(power))
    state.g_general_orders = {}
    state.g_power_call_count.fill(0)


def _reset_send_gof_order_state(state: InnerGameState) -> None:
    """ResetPerTrialState call at send_GOF.c:54."""
    for province in state.unit_info:
        state.g_order_table[province, _F_ORDER_TYPE] = 0.0
    for unit in getattr(state, 'dislodged_unit_info', {}).values():
        unit['order_type'] = 0
    state.g_build_order_list.clear()
    state.g_build_order_list_size = 0
    state.g_waive_count = 0


def _run_send_gof_candidate_pass(
    state: InnerGameState,
    phase: str,
    own_power_idx: int,
    num_powers: int,
) -> list:
    """Run send_GOF's snapshot/scoring/ProcessTurn block.

    GenerateAndSubmitOrders calls this only after PostProcessOrders, alliance
    updates, HOSTILITY/SetGamePhase(3), and NormalizeInfluenceMatrix. That is
    the ordering of the call to send_GOF in the executable.
    """
    movement_phase = phase in ('SPR', 'FAL')

    # send_GOF.c:23-27 destroys g_CandidateRecordList (DAT_00bbf60c) first,
    # and :50 (0x00456c03) zeroes DAT_00baed34, the count of committed
    # retreats/adjustments.
    state.g_order_commit_count = 0
    state.g_candidate_record_list = []
    state.__dict__.pop('_candidate_key_map', None)
    state.__dict__.pop('_candidate_keys', None)

    snapshot_province_state(state)
    _reset_send_gof_order_state(state)
    # send_GOF.c:31-38 destroys and reinitialises DAT_00baed98 before any
    # ProcessTurn calls.  BuildSupportProposals then repopulates it during the
    # ten rounds, allowing later powers/rounds to consume fresh support
    # requests without leaking requests from an earlier phase.
    deal_list = getattr(state, 'g_deal_list', None)
    if deal_list is None:
        deal_list = []
        state.g_deal_list = deal_list
    else:
        deal_list.clear()
    state.g_proposal_history_map = deal_list
    proposal_keys = getattr(state, 'g_proposal_history', None)
    if proposal_keys is None:
        state.g_proposal_history = set()
    else:
        proposal_keys.clear()

    # send_GOF.c:56-69 scores SUM like SPR and AUT like FAL. WIN uses the
    # spring weights too, but its own-power candidate scoring must happen only
    # after build/remove candidates have been populated by the caller.
    if phase in ('SPR', 'SUM', 'FAL', 'AUT'):
        fall_weights = phase in ('FAL', 'AUT')
        move_weight = (state.g_fal_move_weight if fall_weights
                       else state.g_spr_move_weight)
        build_weight = (state.g_fal_build_weight if fall_weights
                        else state.g_spr_build_weight)
        round_weights = (state.g_fal_round_weights if fall_weights
                         else state.g_spr_round_weights)
        try:
            score_provinces(state, move_weight, build_weight, own_power_idx)
        except Exception:
            logger.exception(
                "score_provinces raised; continuing with default scores"
            )
        try:
            score_order_candidates_all_powers(
                state, round_weights, own_power_idx
            )
        except Exception:
            logger.exception(
                "score_order_candidates_all_powers raised; continuing"
                " with empty final_score_set"
            )

    # Retreat and WIN branches never enter send_GOF's ten-round ProcessTurn
    # arm; they select RTO/DSB or BLD/REM directly from the scored key trees.
    if not movement_phase:
        return []

    # send_GOF.c:97-98: both routines consume the final score trees populated
    # immediately above.  Running them from GenerateOrders meant they observed
    # the prior turn's scores (or construction-time zeroes).
    compute_safe_reach(state)
    for power in range(num_powers):
        enumerate_hold_orders(state, power)

    _prepare_proposal_orders_for_turn(state)
    trial_scale = int(getattr(state, 'g_trial_scale', 260))
    press_cap = int(getattr(state, 'g_press_proposals_cap', 30))
    unit_count = getattr(
        state, 'g_unit_count', np.zeros(num_powers, dtype=np.int32)
    )

    mtl_fired = False
    for _mc_round in range(10):
        if mtl_fired:
            break
        for power in range(num_powers):
            if check_time_limit(state):
                mtl_fired = True
                break
            if int(unit_count[power]) <= 0:
                continue
            if press_cap == 0 and power != own_power_idx:
                n_trials = 1
            else:
                n_trials = (
                    int(unit_count[power]) * trial_scale + 10
                ) // 10

            state.g_ring_convoy_enabled = 0
            process_turn(state, power, num_trials=n_trials)

            support_opportunities = getattr(
                state, 'g_support_opportunities_set', None
            )
            if not support_opportunities:
                continue
            for opportunity in support_opportunities:
                if check_time_limit(state):
                    mtl_fired = True
                    break
                if int(opportunity.get('power', -1)) != power:
                    continue
                state.g_ring_prov_a = int(
                    opportunity.get('mover_prov', -1)
                )
                state.g_ring_prov_b = int(
                    opportunity.get('target_prov', -1)
                )
                state.g_ring_prov_c = int(
                    opportunity.get('supporter_prov', -1)
                )
                # The seven-word C record also carries one coast token after
                # each source province: A→B, B→C, and C→A respectively.
                state.g_ring_coast_a = int(
                    opportunity.get('mover_coast', 0)
                )
                state.g_ring_coast_b = int(
                    opportunity.get('target_coast', 0)
                )
                state.g_ring_coast_c = int(
                    opportunity.get('supporter_coast', 0)
                )
                state.g_ring_convoy_enabled = 1
                # send_GOF.c:145 uses the same DAT_0062e460 unit-count row as
                # the outer trial calculation: (unit_count * 10) / 10.  Supply
                # centres are unrelated and diverge after captures/disbands.
                re_trials = max(int(unit_count[power]), 1)
                if press_cap == 0 and power != own_power_idx:
                    re_trials = 1
                process_turn(state, power, num_trials=re_trials)

    _normalize_broadcast_nodes(state)
    return state.g_candidate_record_list


class _OrdersMixin:
    # Declared for type checkers — assigned in _LifecycleMixin.__init__
    state: InnerGameState
    power_name: str
    game: Any
    current_phase: str | None

    # Cross-mixin methods (provided by _PressMixin)
    _send_dm: Callable[..., None]
    _build_and_send_sub: Callable[..., None]
    _submit_draw_vote: Callable[..., None]
    _validate_orders: Callable[..., None]

    def _initialize_press_session(self) -> None:
        """The HLO handler's press setup, once per game (ParseHSTResponse).

        python-diplomacy sends no HLO, so the client supplies the variant: a
        press game is LVL 100 and a no-press game LVL 0 with DAT_00baed40
        set.  process_hst also seeds the CRT stream from the clock, as the
        HLO handler does.  In a press game press is scheduled for immediate
        dispatch (DAT_00baed32): python-diplomacy games may run without a
        deadline, so the 5–21 s response windows would never elapse.
        """
        if getattr(self.state, 'g_press_session_initialized', False):
            return
        if self.power_name in _POWER_NAMES:
            self.state.albert_power_idx = _POWER_NAMES.index(self.power_name)
        from ...communications.inbound.history import process_hst
        if getattr(self.state, 'g_minimal_press_mode', 0) == 1:
            process_hst(self.state, 'LVL 0')
        else:
            process_hst(self.state, 'LVL 100')
            self.state.g_press_instant = 1
        self.state.g_press_session_initialized = True

    def generate_and_submit_orders(self) -> None:
        """
        Port of FUN_004592a0 = GenerateAndSubmitOrders.

        Called from on_game_update after board state is synchronized.
        Mirrors the full C++ execution flow documented in research.md
        §GenerateAndSubmitOrders — FUN_004592a0 ⭐.

        Execution flow (matching research.md §Execution flow):
          Step 1  Record turn-start timestamp.
          Step 2  Reset per-turn scalar flags.
          Step 3  Cancel stale orders if reconnecting.
          Step 4  Opening-turn pulse (DAT_00baed68).
          Step 5  Main AI block (skipped when game_over):
            5a  Reset press candidate tables.
            5b  PhaseHandler(0).
            5c  Per-power reset loop (trust counters, score matrices).
            5d  Phase checks: increment g_deceit_level (SPR), AnalyzePosition,
                MOVE_ANALYSIS (year-1 FAL, not the opening turn, allied).
            5e  Clear g_baed6d sentinel.
            5f  GenerateOrders.
            5g  PostProcessOrders (SPR/FAL).
            5h  ComputePress (opening turn only).
            5i  Alliance block (STABBED / DEVIATE_MOVE / FRIENDLY / HOSTILITY /
                PhaseHandler 1–3).
            5j  HOSTILITY / PhaseHandler(3), NormalizeInfluenceMatrix, then
                send_GOF's SnapshotProvinceState + scoring + ProcessTurn or
                retreat/adjustment selection.
          Step 6  BuildAndSendSUB / phase-specific orders + GOF.
        """
        own_power_idx = (
            _POWER_NAMES.index(self.power_name)
            if self.power_name in _POWER_NAMES else 0
        )
        self.state.albert_power_idx = own_power_idx
        # Keep the C-faithful name (DAT_00624124) in sync with the Python
        # canonical albert_power_idx.  Consumers:
        #   * monte_carlo/trial.py:849 — "skip iteration-delta term for self"
        #     branch in ScoreOrderCandidates_AllPowers.
        #   * communications/inbound/gate.py fallback chain.
        # Previously read but never written → the branch silently defaulted
        # to albert_power_idx via getattr, which was correct by accident.
        self.state.g_albert_power = own_power_idx

        # Albert's callback table places InitPositionForOrders alongside
        # GenerateAndSubmitOrders. Its topology/history resets are position
        # initialization, not per-turn work, so run it once after the first
        # synchronized board has supplied SC control and map metadata.
        if not getattr(self.state, 'g_position_orders_initialized', False):
            _init_position_for_orders(self.state)
            self.state.g_position_orders_initialized = True

        # Step 1 — record turn start timestamp and arm the MTL timer.  HST
        # supplies a duration, not a once-per-connection absolute deadline.
        _begin_turn_timing(self.state)

        # Step 2 — reset per-turn scalar flags
        # Mirrors: DAT_0062cc64 / ba2858 / ba285c / baed46 / baed5e / baed47 = 0
        self.state.g_n_trials_completed = 0  # DAT_0062cc64
        self.state.g_cum_score = 0            # g_CumScore
        self.state.g_trial_score_a.clear()
        self.state.g_trial_score_b.clear()
        self.state.g_trial_score_c.clear()
        self.state.g_trial_prev_score_alt = 0
        self.state.g_trial_prev_score_baseline = 0
        # send_GOF.c:104 resets DAT_00b9fe88 once per power immediately before
        # the movement proposal passes begin.
        self.state.g_power_call_count.fill(0)
        self.state.g_gof_sent = False           # clear server-GOF-pending flag
        self.state.g_cancel_press_sent = 0      # disarm fallback-GOF guard (DAT_00baed47)
        if not hasattr(self.state, 'g_pending_orders_A'):
            self.state.g_pending_orders_A = 0
        if not hasattr(self.state, 'g_pending_orders_B'):
            self.state.g_pending_orders_B = 0

        game_over: bool = getattr(self.state, 'g_game_over', False)

        # Step 3 — cancel stale pending orders if reconnecting
        # Condition: !game_over AND (pending_A != 0 OR pending_B != 0)
        if not game_over and (
            self.state.g_pending_orders_A != 0
            or self.state.g_pending_orders_B != 0
        ):
            logger.info("Stale pending orders found — cancelling (reconnect path)")
            self.state.g_pending_orders_A = 0
            self.state.g_pending_orders_B = 0

        # GenerateAndSubmitOrders.c:118-123: with DAT_00baed47 cleared, a power
        # that still has units (inner +0x24bc) or centres (+0x24e0) withdraws
        # its readiness until AwaitPressAndSendGOF gives it back.
        if not game_over and (
            int(self.state.g_unit_count[own_power_idx]) != 0
            or int(self.state.sc_count[own_power_idx]) != 0
        ):
            cancel_prior_press(self.state, own_power_idx, self._send_dm)

        # play() runs the HLO-equivalent press setup on joining; a caller
        # that drives generation directly gets it here on the first turn.
        if getattr(self.state, 'g_minimal_press_mode', 0) == 0:
            self._initialize_press_session()

        # Step 4 — GenerateAndSubmitOrders.c:125-131: DAT_00baed68 is a
        # one-call pulse armed by DAT_004c6bdc's initial 1.
        _refresh_opening_turn_flag(self.state)

        if game_over:
            logger.info("Game-over flag set — skipping order generation")
            _cleanup_turn(self.state)
            self._await_press_and_send_gof()
            return

        # ── Step 5 — main AI block ──────────────────────────────────────────
        phase: str = self.state.g_season          # 'SPR'|'SUM'|'FAL'|'AUT'|'WIN'
        movement_phase: bool = phase in ('SPR', 'FAL')
        num_powers = 7

        # 5a — reset press candidate tables
        # DAT_00bbf690[power][30] and DAT_00bc0a40[power][30] — cleared to sentinel
        self.state.g_press_candidate_a = [[None] * 30 for _ in range(num_powers)]
        self.state.g_press_candidate_b = [[None] * 30 for _ in range(num_powers)]

        # 5b — PhaseHandler step 0
        _phase_handler(self.state, 0)

        # 5c — per-power reset loop (GenerateAndSubmitOrders.c:236-300).
        # For Albert and every power still holding centres, a negative
        # g_AllyMatrix entry (DAT_00ba2888[p*21+j], e.g. FUN_004325a0's -4
        # ALY/VSS cool-down) moves one step toward 0 in SPR/FAL.  For an
        # eliminated power C zeroes its g_AllyMatrix row, its trust row and
        # column, and its promise and counter lists (DAT_00bb6f2c/702c).
        for p in range(num_powers):
            alive = p == own_power_idx or int(self.state.sc_count[p]) != 0
            for j in range(num_powers):
                if alive:
                    if self.state.g_ally_matrix[p, j] < 0 and movement_phase:
                        self.state.g_ally_matrix[p, j] += 1
                else:
                    self.state.g_ally_trust_score[p, j] = 0
                    self.state.g_ally_trust_score_hi[p, j] = 0
                    self.state.g_ally_trust_score[j, p] = 0
                    self.state.g_ally_trust_score_hi[j, p] = 0
                    self.state.g_ally_matrix[p, j] = 0
            if not alive:
                self.state.g_ally_promise_list.pop(p, None)
                self.state.g_ally_counter_list.pop(p, None)

        # 5d — phase-specific pre-processing

        # g_deceit_level (DAT_00baed64) = Spring-year counter; 0=pre-game, 1=year 1, …
        # Incremented each SPR. Also labelled "Deceit Level" in Albert's internal log.
        if phase == 'SPR':
            self.state.g_deceit_level += 1
            logger.debug(
                f"DeceitLevel = {self.state.g_deceit_level} "
                f"(Spring of year {self.state.g_deceit_level})"
            )

        if movement_phase:
            _analyze_position(self.state)

        # C gate: curr_sc_cnt[own_power] != 0 (own power not eliminated).
        # Previously checked g_ally_matrix[own, own] which is never set → always False.
        ally_own: bool = int(self.state.sc_count[own_power_idx]) != 0
        if (
            self.state.g_deceit_level == 1
            and self.state.g_press_flag == 0
            and phase == 'FAL'
            and ally_own
        ):
            _move_analysis(self.state)

        # DAT_00baed6d = 0  (deviation/retry sentinel cleared before GenerateOrders)
        self.state.g_baed6d = 0

        # 5f — GenerateOrders (FUN_004466e0). ProcessTurn belongs to the later
        # send_GOF call, after diplomatic state and influence normalization.
        from ...monte_carlo import generate_orders
        generate_orders(self.state, own_power_idx)

        # 5g — PostProcessOrders (SPR/FAL only; runs after GenerateOrders, before SUB)
        if movement_phase:
            _post_process_orders(self.state)

        # 5h — ComputePress (neutral centres next to each power's units) on
        # the opening turn only (GenerateAndSubmitOrders.c:324).
        if self.state.g_press_flag == 1:
            _compute_press(self.state)

        # BuildSupportProposals has already populated its persistent proposal
        # records.  C keeps those in g_ProposalHistoryMap; it does not insert
        # them into the inbound/outbound broadcast-score tree. THN dispatch
        # consumes the records directly in _execute_xdo.

        # 5i — alliance-active block
        # Gate: curr_sc_cnt[own_power] != 0 AND DAT_00baed33 == 0 (alliance debug flag off)
        alliance_debug: bool = getattr(self.state, 'g_alliance_debug', False)
        if ally_own and not alliance_debug:
            logger.debug("Alliance block active")

            # Year-1 non-SPR non-retreat: STABBED check.
            # Year >= 2 or retreat phase: DEVIATE_MOVE.
            if self.state.g_deceit_level < 2 and phase not in ('AUT', 'WIN'):
                if self.state.g_deceit_level == 1 and phase != 'SPR':
                    _stabbed(self.state)
            else:
                _deviate_move(self.state)

            _phase_handler(self.state, 1)
            _friendly(self.state)
            _phase_handler(self.state, 2)
            _post_friendly_update(self.state)

        # 5j — finish GenerateAndSubmitOrders before entering send_GOF.
        if movement_phase:
            _insert_base_broadcast_node(self.state)
            _hostility(self.state)
            _phase_handler(self.state, 3)
            _prepare_draw_vote_set(self.state)
            # GenerateAndSubmitOrders.c:483-505 sends DRW, or NOT ( DRW ), here:
            # before NormalizeInfluenceMatrix and send_GOF, so the vote reaches
            # the server ahead of GOF.  python-diplomacy clears every vote when
            # it processes a phase, which stands in for NOT ( DRW ).
            if self.state.g_draw_sent and self.game is not None:
                self._submit_draw_vote()
        else:
            if phase == 'WIN':
                compute_build_delta(self.state)
                _hostility(self.state)
            _phase_handler(self.state, 3)

        # GenerateAndSubmitOrders calls NormalizeInfluenceMatrix immediately
        # before send_GOF. The old port ran it after ProcessTurn and selection.
        _cleanup_turn(self.state)

        self._send_gof_pass(phase, own_power_idx, num_powers)

    def _send_gof_pass(self, phase: str, own_power_idx: int, num_powers: int) -> None:
        """Port of send_GOF (0x00456b50) from its candidate pass onwards.

        GenerateAndSubmitOrders calls it once per phase, and
        EvaluateOrderProposalsAndSendGOF calls it again whenever CAL_MOVE has
        applied an agreement.  Movement phases run the ProcessTurn rounds,
        reset the proposal-round diagnostics, set DAT_00baed46 and clear
        DAT_00baed6d, then BuildAndSendSUB; retreats and adjustments select
        and submit their orders; every phase ends in AwaitPressAndSendGOF.
        """
        movement_phase = phase in ('SPR', 'FAL')
        best_orders = _run_send_gof_candidate_pass(
            self.state, phase, own_power_idx, num_powers
        )

        if movement_phase:
            if int(self.state.g_unit_count[own_power_idx]) == 0:
                # send_GOF.c:70-76: no units — straight to AwaitPressAndSendGOF.
                self._await_press_and_send_gof()
                return
            # send_GOF.c:285-380 resets the proposal-round diagnostics.
            self.state.g_score_alt = 0
            self.state.g_score_group_duplicates = 0
            self.state.g_score_baseline = 0
            self.state.g_trial_score_a.clear()
            self.state.g_trial_score_b.clear()
            self.state.g_trial_score_c.clear()
            self.state.g_trial_prev_score_alt = 0
            self.state.g_trial_prev_score_baseline = 0
            self.state.g_baed46 = 1
            self.state.g_baed6d = 0
            self._build_and_send_sub(best_orders)
            return

        if phase == 'WIN':
            # WIN build/remove candidate pipeline — send_GOF.c:69-80,398-403.
            self.state.g_adjustment_build_candidates.clear()
            self.state.g_adjustment_candidate_scores.clear()
            self.state.g_adjustment_candidate_provinces.clear()

            # ParseNOW has already established the adjustment delta and legal
            # site/unit keys before send_GOF enters ScoreProvinces in C. In
            # particular, ComputeWinterBuilds runs *inside* ScoreProvinces and
            # must see the legal build-token set at that point.
            own_delta = self.state.g_build_delta[own_power_idx]
            if own_delta['flag'] == 1:
                populate_build_candidates(self.state, own_power_idx)
            elif own_delta['delta'] > 0:
                populate_remove_candidates(self.state, own_power_idx)

            score_provinces(
                self.state, self.state.g_spr_move_weight,
                self.state.g_spr_build_weight, own_power_idx,
            )

            if own_delta['flag'] == 1:
                score_order_candidates_own_power(
                    self.state, _WIN_BUILD_WEIGHTS, own_power_idx,
                    self.state.g_win_build_attack_weight,
                )
                compute_win_builds(self.state, own_delta['delta'])
            elif own_delta['delta'] > 0:
                score_order_candidates_own_power(
                    self.state, _WIN_REMOVE_WEIGHTS, own_power_idx,
                    self.state.g_win_remove_attack_weight,
                )
                compute_win_removes(self.state, own_delta['delta'])

        retreat_cmds: list[str] = []
        if phase in ('SUM', 'AUT') and self.game is not None:
            self.state.g_retreat_order_list = _populate_retreat_orders(
                self.state, self.game, self.power_name, own_power_idx)
            # CommitMoveCandidatesPostPress increments DAT_00baed34 per unit
            # (0x00441f73), whether it retreats or disbands.
            self.state.g_order_commit_count += len(self.state.g_retreat_order_list)
            retreat_cmds = _format_retreat_commands(self.state)

        # send_GOF.c:388-409 (0x0045745e-0x004574c6): after committing
        # retreats or adjustments, Albert without DAT_00baed32 sleeps
        # (count+2)*2000 ms (retreats) or count*2000+5000 ms (adjustments)
        # plus (rand()/23)%6000 before FUN_0045aa40 sends SUB.  The port takes
        # the draw and skips the pause.
        if (phase in ('SUM', 'AUT', 'WIN')
                and self.state.g_order_commit_count > 0
                and not int(getattr(self.state, 'g_press_instant', 0))):
            from ... import rng as _rng
            _rng.randrange(6000)

        if phase == 'WIN':
            self._submit_adjustment_orders()
        elif retreat_cmds:
            logger.info("Retreat orders for %s: %s",
                        self.power_name, retreat_cmds)
            self._validate_orders(retreat_cmds)
            try:
                self._schedule_set_orders(retreat_cmds)
            except Exception:
                logger.exception(
                    "Failed to submit retreat orders to game engine")

        self._await_press_and_send_gof()

    def _rerun_send_gof(self) -> None:
        """EvaluateOrderProposalsAndSendGOF's send_GOF call for the live phase."""
        if self.game is None:
            return
        live_phase = _game_phase(self.game)
        if self.current_phase and live_phase and live_phase != self.current_phase:
            return
        own_power_idx = int(getattr(self.state, 'albert_power_idx', 0))
        self._send_gof_pass(self.state.g_season, own_power_idx, 7)


    def _validate_orders(self, orders: list[str]) -> None:
        """Check submitted orders against game.get_all_possible_orders().

        Logs warnings for any illegal orders.  Does not block submission —
        the server will void illegal orders anyway, but the log helps catch
        bugs in the MC pipeline.
        """
        if self.game is None:
            return
        try:
            possible = self.game.get_all_possible_orders()
        except Exception:
            return  # can't validate without the legal-orders map

        for order in orders:
            if order == 'WAIVE':
                continue
            # Extract the location from the order (first unit+loc token)
            parts = order.split()
            if len(parts) < 2:
                continue
            loc = parts[1]  # e.g. 'PAR' from 'A PAR H'
            # Handle coasted locs like 'STP/NC'
            legal = possible.get(loc, set())
            if not legal:
                # Try without coast for retreat/build orders
                base = loc.split('/')[0]
                legal = possible.get(base, set())
            if legal and order not in legal:
                logger.warning(
                    "ORDER VALIDATION: %r not in legal orders for %s "
                    "(sample legal: %s)",
                    order, loc, list(legal)[:3],
                )


    def _submit_adjustment_orders(self) -> None:
        """Translate g_build_order_list + g_waive_count into diplomacy-format
        orders and submit them to the game.

        g_build_order_list entries are DAIDE-style strings:
            '( FRA AMY PAR ) BLD'  →  'A PAR B'
            '( FRA FLT BRE ) BLD'  →  'F BRE B'
            '( FRA AMY MAR ) REM'  →  'A MAR D'
            '( FRA FLT NAP ) REM'  →  'F NAP D'
        g_waive_count waives       →  'WAIVE' per waive
        """
        if self.game is None:
            return

        orders: list[str] = []
        for entry in self.state.g_build_order_list:
            # Parse '( POWER UNIT_TYPE PROV ) BLD|REM'
            parts = entry.replace('(', '').replace(')', '').split()
            # Expected: [POWER, AMY|FLT, PROV, BLD|REM]
            if len(parts) < 4:
                logger.warning("Adjustment: unparseable entry %r", entry)
                continue
            _power, unit_daide, prov, action = parts[0], parts[1], parts[2], parts[-1]
            unit_letter = 'F' if unit_daide == 'FLT' else 'A'
            if action == 'BLD':
                orders.append(f"{unit_letter} {prov} B")
            elif action == 'REM':
                orders.append(f"{unit_letter} {prov} D")
            else:
                logger.warning("Adjustment: unknown action %r in %r", action, entry)

        for _ in range(self.state.g_waive_count):
            orders.append("WAIVE")

        if orders:
            logger.info("Adjustment orders for %s: %s", self.power_name, orders)
            self._validate_orders(orders)
            self._schedule_set_orders(orders)
        else:
            logger.info("Adjustment: no builds/removes/waives for %s", self.power_name)
