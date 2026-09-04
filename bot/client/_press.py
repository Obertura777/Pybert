"""Press/DM/draw-vote mixin half of AlbertClient.

Split from bot/client.py during the 2026-04 refactor.

Holds the outbound-press and draw-vote submission methods:

  * ``_send_dm``               — send a direct-message press.
  * ``_build_and_send_sub``    — build and submit the SUB (orders)
    message.
  * ``_submit_draw_vote``      — submit a draw-vote on the current
    game.

Composed with ``_LifecycleMixin`` and ``_OrdersMixin`` to form
``AlbertClient``; cross-mixin method calls resolve through MRO at
call time.
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
    update_score_state,
    _refresh_order_table,
    check_time_limit,
    restore_order_entry,
    _F_ORDER_TYPE, _F_DEST_PROV, _F_DEST_COAST,
)
from ...communications import (
    parse_message,
    dispatch_scheduled_press,
    cancel_prior_press,
    _send_ally_press_by_power,
)
from ...heuristics import (
    score_provinces,
    score_order_candidates_all_powers,
    score_order_candidates_own_power,
    populate_build_candidates,
    populate_remove_candidates,
    compute_win_builds,
    compute_win_removes,
    _WIN_BUILD_WEIGHTS,
    _WIN_REMOVE_WEIGHTS,
    _SPR_FAL_WEIGHTS,
)
from ...dispatch import validate_and_dispatch_order

from .._shared import _POWER_NAMES, _DAIDE_POWER_NAMES
from ..orders import (
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
)

logger = logging.getLogger(__name__)


def _set_round_value(values: list, index: int, value: int) -> None:
    """Store into a C-style fixed round array represented by a Python list."""
    while len(values) <= index:
        values.append(0)
    values[index] = int(value)


def _advance_broadcast_proposal_trials(
        state: InnerGameState,
        entry: dict,
        trial_cap: int,
        dispatch_fn: Callable[[], None] | None = None,
) -> bool:
    """Run BuildAndSendSUB's inner proposal-trial loop for one broadcast node.

    Returns ``True`` when the node reaches ``trial_cap`` and ``False`` when an
    MTL check interrupts it.  This is C ``004579f3–00457d71``: the node owns its
    completed-trial counter, which is copied to ``DAT_0062cc64`` at the start
    of every iteration and incremented only after score/history snapshots and
    scheduled-press dispatch.
    """
    trial_cap = max(int(trial_cap), 0)
    completed = max(int(entry.get('trial_count', 0)), 0)
    num_powers = len(state.g_unit_count)

    while completed < trial_cap:
        if check_time_limit(state):
            return False

        state.g_n_trials_completed = completed

        # C's round-zero block ranks/refreshes each active, stale power before
        # the first UpdateScoreState call and adds its accepted-proposal count
        # to g_CumScore. Subsequent rounds use the flag=1 ranker tail invoked by
        # UpdateAllyOrderScore.
        if completed == 0:
            for power in range(num_powers):
                if int(state.g_unit_count[power]) <= 0:
                    continue
                if state.g_power_round_record.get(power, 0) == state.g_current_round:
                    continue
                _rank_candidates_for_power(state, power, flag=0)
                _refresh_order_table(state, power)
                state.g_cum_score += int(state.g_power_call_count[power])

        _set_round_value(
            state.g_trial_score_a,
            completed,
            int(state.g_cum_score) - int(state.g_score_baseline),
        )

        update_score_state(state)

        previous_alt = int(getattr(state, 'g_trial_prev_score_alt', 0))
        previous_baseline = int(
            getattr(state, 'g_trial_prev_score_baseline', 0))
        _set_round_value(
            state.g_trial_score_b,
            completed,
            int(state.g_score_alt) - previous_alt,
        )
        _set_round_value(
            state.g_trial_score_c,
            completed,
            int(state.g_score_baseline) - previous_baseline,
        )
        state.g_trial_prev_score_alt = int(state.g_score_alt)
        state.g_trial_prev_score_baseline = int(state.g_score_baseline)

        # candidate[0x17 + round] = candidate[0x71]
        for candidate in state.g_candidate_record_list:
            history = candidate.setdefault('output_score_history', [])
            while len(history) <= completed:
                history.append(0.0)
            history[completed] = float(candidate.get('output_score', 0.0))

        if dispatch_fn is not None:
            dispatch_fn()

        completed += 1
        state.g_n_trials_completed = completed
        entry['trial_count'] = completed

    return True


class _PressMixin:
    # Declared for type checkers — assigned in _LifecycleMixin.__init__
    state: InnerGameState
    power_name: str
    game: Any
    current_phase: str | None

    # Cross-mixin method (provided by _OrdersMixin)
    _validate_orders: Callable[..., None]

    @staticmethod
    def _track_request_future(future: Any, operation: str, phase: str = "") -> None:
        """Consume the result of a fire-and-forget NetworkGame request.

        python-diplomacy returns a Tornado/asyncio Future, not necessarily a
        coroutine.  Leaving that Future unobserved makes an ordinary rejected
        request surface later as ``Exception in Future ... after timeout``.
        """
        if future is None:
            return

        if asyncio.iscoroutine(future):
            try:
                future = asyncio.get_running_loop().create_task(future)
            except RuntimeError:
                future.close()
                logger.warning("%s not sent: no running event loop", operation)
                return

        if not hasattr(future, "add_done_callback"):
            return

        def _consume_result(done_future):
            try:
                done_future.result()
            except asyncio.CancelledError:
                return
            except Exception as exc:
                # Phase-dependent requests can legitimately lose a race with
                # phase processing or reconnect synchronization.  The next
                # GameProcessed notification will generate fresh orders.
                logger.warning(
                    "%s rejected%s: %s: %s",
                    operation,
                    f" for phase {phase}" if phase else "",
                    type(exc).__name__,
                    exc,
                )

        future.add_done_callback(_consume_result)

    def _schedule_set_orders(self, orders: list[str]) -> None:
        """Submit orders to the game, handling async NetworkGame properly.

        NetworkGame.set_orders() returns a coroutine that must be awaited.
        Since we're called from a synchronous notification callback, we
        schedule the coroutine on the running event loop via create_task().
        For local Game objects (tests), set_orders is synchronous (returns None).
        """
        # generate_and_submit_orders() runs in a worker so the WebSocket loop
        # remains responsive. NetworkGame itself must only be touched here on
        # the loop that owns the connection.
        if self._marshal_to_network_loop(self._schedule_set_orders, list(orders)):
            return
        if self.game is None:
            return
        phase = getattr(self.game, "current_short_phase", "") or ""
        try:
            future = self.game.set_orders(
                power_name=self.power_name, orders=orders, wait=True)
        except TypeError:
            future = self.game.set_orders(
                power_name=self.power_name, orders=orders)
        self._track_request_future(
            future, f"set_orders for {self.power_name}", phase
        )
        if future is not None and hasattr(future, "add_done_callback"):
            self._pending_orders_future = future

    def _send_dm(self, msg: object) -> None:
        """
        Send DAIDE direct-message using python-diplomacy NetworkGame API.

        Per-power fan-out — Albert never broadcasts to ``GLOBAL``.  Even when
        the underlying DAIDE press is logically a broadcast (BCC or an XDO PRP
        intended for everyone), python-diplomacy treats GLOBAL as a
        "system / all observers" channel that bypasses the per-power inbox
        and shows up untargeted in the message log.  The C original always
        addressed press to a specific recipient power; reproducing that here
        means iterating ``self.game.powers`` and emitting one Message per
        non-self power.

        GOF and NOT(GOF) are not press.  They map exclusively to the server's
        per-power wait flag via ``game.no_wait()`` and ``game.wait()``.

        Three further things to get right:

        * ``Message`` requires a ``phase`` field — python-diplomacy's
          validator raises ``TypeException: Expected type <class 'str'>,
          got type <class 'NoneType'>`` if it's omitted, and the per-phase
          server log gives no hint which key was missing.

        * On a NetworkGame the wire path is the async
          ``game.send_game_message(message=...)`` — ``add_message`` is
          a server-only API and asserts ``self.is_server_game()`` on a
          client-side game.  ``send_game_message`` returns a tornado-wrapped
          Future that's already in-flight on the connection's IO loop, so
          we just attach an error callback rather than awaiting.

        * Re-checking the phase before dispatch dodges the common race
          where the server has already advanced past ``phase`` while
          Albert was scoring trials.
        """
        if self._marshal_to_network_loop(self._send_dm, copy.deepcopy(msg)):
            return
        logger.debug("SendDM: %r", msg)
        if self.game is None:
            return

        # Directed-message dict: {'message': str, 'recipient': power_name}.
        # respond() produces this format so YES/REJ responses go only to
        # the original proposer rather than being broadcast to all powers.
        _explicit_recipient: str | None = None
        if isinstance(msg, dict):
            _explicit_recipient = msg.get('recipient')
            msg = msg.get('message', '')

        # GOF and NOT(GOF) are server-readiness controls, never press messages.
        # Canonicalize whitespace so both token-list and string callers hit the
        # control path and can never fall through to per-power fan-out.
        body_str = ' '.join(str(t) for t in msg) if isinstance(msg, list) else str(msg)
        control_body = ''.join(body_str.upper().split())

        if control_body == 'NOT(GOF)':
            phase = getattr(self.game, "current_short_phase", "") or ""
            try:
                if hasattr(self.game, 'wait'):
                    future = self.game.wait()
                    self._track_request_future(
                        future, f"wait for {self.power_name}", phase)
                elif hasattr(self.game, 'set_wait'):
                    # Offline/server Game fallback.  NetworkGame always uses
                    # wait() above so the change is sent to the server.
                    self.game.set_wait(self.power_name, True)
                else:
                    logger.warning(
                        "NOT(GOF) ignored: game has no wait-control API")
                    return
            except Exception as exc:
                logger.warning(
                    "wait for %s rejected for phase %s: %s: %s",
                    self.power_name, phase, type(exc).__name__, exc,
                )
                return
            logger.info(
                "_send_dm: NOT(GOF) → wait() (wait=True) for %s",
                self.power_name,
            )
            return

        if control_body == 'GOF':
            phase = getattr(self.game, "current_short_phase", "") or ""

            # generate_and_submit_orders() calls _send_gof() from its worker
            # before the event-loop-side inbound press queue has had its final
            # response pass.  Releasing wait here can advance a deadline-0
            # game and discard those proposals.  _run_game_update_async flushes
            # this deferred GOF after it drains and answers current-turn press.
            if getattr(self, '_generation_in_progress', False):
                self._deferred_gof_phase = phase
                logger.info(
                    "_send_dm: GOF deferred until inbound press drains for %s",
                    self.power_name,
                )
                return

            def _send_no_wait() -> None:
                # Never release the wait flag for orders computed in a phase
                # that has already moved on.
                if phase != (getattr(self.game, "current_short_phase", "") or ""):
                    return
                future = self.game.no_wait()
                self._track_request_future(
                    future, f"no_wait for {self.power_name}", phase
                )
                logger.info(
                    "_send_dm: GOF → no_wait() (wait=False) for %s",
                    self.power_name,
                )

            pending_orders = getattr(self, "_pending_orders_future", None)
            if pending_orders is not None:
                def _after_orders(done_future) -> None:
                    try:
                        done_future.result()
                    except asyncio.CancelledError:
                        return
                    except Exception:
                        return
                    _send_no_wait()

                if pending_orders.done():
                    _after_orders(pending_orders)
                    return
                pending_orders.add_done_callback(_after_orders)
                logger.info(
                    "_send_dm: GOF queued behind set_orders for %s",
                    self.power_name,
                )
            else:
                _send_no_wait()
            return

        # Skip all outbound press in no-press mode.
        if getattr(self.state, 'g_minimal_press_mode', 0) == 1:
            return
        try:
            from diplomacy import Message
        except ImportError:
            logger.warning("diplomacy.Message not available; cannot send DAIDE press.")
            return

        # Determine recipient set.  An explicit per-power recipient on the
        # message object wins; otherwise fan out to every other power.
        msg_recipient = _explicit_recipient or getattr(msg, 'recipient', None)
        powers_attr = getattr(self.game, 'powers', None) or {}
        try:
            all_powers = list(powers_attr.keys())
        except AttributeError:
            all_powers = list(powers_attr)
        if msg_recipient and msg_recipient not in ('GLOBAL', 'ALL', None):
            recipients = [msg_recipient]
        else:
            recipients = [p for p in all_powers if p != self.power_name]
        if not recipients:
            logger.debug("_send_dm: no recipients (powers=%r); dropping", all_powers)
            return

        # Game-not-playing guard: the server rejects send_game_message when the
        # game hasn't reached 'active' status yet (e.g. not all powers have
        # joined).  Drop the fan-out silently rather than generating N ERROR
        # log lines from the diplomacy library for each failed round-trip.
        game_status = getattr(self.game, 'status', '') or ''
        if game_status and game_status != 'active':
            logger.debug(
                "_send_dm: game not active (status=%r) — dropping press",
                game_status,
            )
            return

        # Phase-staleness guard: compare the phase Albert was scoring for
        # (captured by play() into self.current_phase before on_game_update
        # ran) against the server's now-current phase.  If the server has
        # advanced — common when MC scoring takes longer than the deadline —
        # drop the entire fan-out instead of paying N round-trip
        # GamePhaseException rejections.
        scoring_phase = getattr(self, 'current_phase', None) or ''
        server_phase  = getattr(self.game, 'current_short_phase', None) or ''
        if scoring_phase and server_phase and scoring_phase != server_phase:
            logger.debug(
                "_send_dm: skipping stale message (built for %s, server is"
                " now at %s)", scoring_phase, server_phase,
            )
            return
        # Use the server's current phase on the wire — Message validates
        # phase against the live game state, so an off-by-one would be
        # rejected even if scoring_phase == server_phase a moment ago.
        phase = server_phase or scoring_phase

        body = ' '.join(str(tok) for tok in msg) if isinstance(msg, list) else str(msg)
        is_network = hasattr(self.game, 'send_game_message')
        import asyncio as _asyncio

        for recipient in recipients:
            try:
                message_obj = Message(
                    sender=self.power_name,
                    recipient=recipient,
                    phase=phase,
                    message=body,
                )
            except Exception as exc:
                logger.warning(
                    "_send_dm: Message validation failed (recipient=%r,"
                    " phase=%r): %s: %s",
                    recipient, phase, type(exc).__name__, exc,
                )
                continue

            if is_network:
                try:
                    fut = self.game.send_game_message(message=message_obj)
                    if _asyncio.iscoroutine(fut):
                        try:
                            loop = _asyncio.get_running_loop()
                            fut = loop.create_task(fut)
                        except RuntimeError:
                            _asyncio.run(fut)
                            continue
                    if hasattr(fut, 'add_done_callback'):
                        def _log_send_error(f, _r=recipient, _p=phase):
                            try:
                                f.result()
                            except Exception as exc:
                                logger.debug(
                                    "_send_dm: send rejected"
                                    " (recipient=%r, phase=%r): %s: %s",
                                    _r, _p, type(exc).__name__, exc,
                                )
                        fut.add_done_callback(_log_send_error)
                except Exception as exc:
                    logger.debug(
                        "_send_dm: send_game_message raised synchronously"
                        " (recipient=%r, phase=%r): %s: %s",
                        recipient, phase, type(exc).__name__, exc,
                    )
            else:
                # Server-game / offline path (kept for unit tests).
                try:
                    self.game.add_message(message_obj)
                except Exception as exc:
                    logger.warning(
                        "_send_dm: add_message rejected (recipient=%r,"
                        " phase=%r): %s: %s",
                        recipient, phase, type(exc).__name__, exc,
                    )


    def _press_response_key(self, entry: dict) -> tuple:
        """Identify duplicate two-pass records for one phase/proposal."""
        phase = (
            getattr(self.game, 'current_short_phase', '')
            or self.current_phase
            or (getattr(self.state, 'g_year', 0),
                getattr(self.state, 'g_season', ''))
        )
        sender = int(entry.get('from_power_tok', 0)) & 0xff
        content = repr(entry.get('sublist3', entry.get('press_content', [])))
        return phase, sender, content


    def _respond_to_received_press_entry(self, entry: dict) -> bool:
        """Evaluate and queue one received proposal without regenerating orders."""
        if not entry.get('received_flag') or entry.get('type_flag', 0) != 0:
            return False

        response_key = self._press_response_key(entry)
        if response_key in self._responded_press_keys:
            return False

        from ...communications import (
            receive_proposal as _receive_proposal,
            respond as _respond,
            evaluate_press as _evaluate_press,
        )

        from_tok = entry.get('from_power_tok', 0)
        from_idx = from_tok & 0xff
        proposal_tokens = entry.get(
            'sublist3', entry.get('press_content', []))
        response_type = _evaluate_press(self.state, entry)
        participants = [
            int(tok) & 0x7f
            for tok in entry.get('sublist2', [])
            if isinstance(tok, int)
        ]
        _receive_proposal(
            self.state,
            from_idx,
            proposal_tokens,
            participant_powers=participants,
            send_fn=self._send_dm,
        )
        scheduled_time = entry.get('sched_time', 0)
        _respond(
            self.state,
            press_list=entry,
            response_type=response_type,
            elapsed_lo=scheduled_time & 0xFFFFFFFF,
            elapsed_hi=(scheduled_time >> 32) & 0xFFFFFFFF,
            send_fn=self._send_dm,
        )
        # Mark only after RESPOND has successfully queued the answer.  If an
        # evaluator or response builder raises, the duplicate registration
        # record remains available for a later retry instead of being silently
        # suppressed.
        self._responded_press_keys.add(response_key)
        _evaluate_order_proposals_and_send_gof(self.state, self._send_dm)
        return True


    def _respond_to_pending_press_entries(self) -> int:
        """Answer all newly registered proposals and flush due replies."""
        responded = sum(
            self._respond_to_received_press_entry(entry)
            for entry in list(self.state.g_broadcast_list)
        )
        if responded:
            dispatch_scheduled_press(self.state, self._send_dm)
            logger.info(
                "Responded to %d inbound proposal(s) for %s in %s",
                responded,
                self.power_name,
                getattr(self.game, 'current_short_phase', '') or self.current_phase,
            )
        return responded


    def _build_and_send_sub(self, best_orders: list) -> None:
        """
        Port of BuildAndSendSUB (FUN_00457890).

        In the C bot this is a multi-trial proposal-scoring loop over
        g_broadcast_list; Monte Carlo (process_turn) plays that role in Python,
        so only the surrounding press/submission scaffold is ported here.

        Structure (mirroring FUN_00457890 at each labelled site):
          1. ScheduledPressDispatch     — pre-loop flush (line 252).
          2. CheckTimeLimit             — abort if MTL already fired (line 291).
          3. Candidate ranking/refresh  — RankCandidatesForPower followed by
                                         UpdateScoreState, before slot zero is read.
          4. Order submission           — consume refreshed slot zero and call
                                         game.set_orders (MC already ran).
          Outer broadcast-list loop (LAB_004579a9, do{}while(true)):
            per-node CheckTimeLimit (line 207);
            per-node ScheduledPressDispatch inside inner trial sub-loop (line 342);
            per-node RECEIVE_PROPOSAL + EvaluatePress + RESPOND for received
              entries (lines 490–570), EvaluateOrderProposalsAndSendGOF after each;
            per-node SendAllyPressByPower for own entries (lines 575–582);
            after all nodes: proposal-history map pass (g_deal_list proxy,
              lines 648–1211) with time-shortcut (line 654) and restart
              (goto LAB_004579a9, lines 1204–1211) when new entries added.
          7. CancelPriorPress           — withdraw stale prior-press token (line 693).

        FUN_00411740 absorbed: synchronous "all g_broadcast_list entries dispatched?" predicate;
          only called from AwaitPressAndSendGOF Sleep loop → both absorbed by async model.
        FUN_00466480 absorbed: alias-safe RAII wrapper — copies param_2, calls FUN_00466330(this, result, copy).
        FUN_00465aa0 absorbed: in-place parenthesize — wraps token seq as ( toks ) [0x5FFF];
          used to build convoy-SUP MTO route: (support_pos) MTO convoy_seg [TERM].
        ScoreOrderCandidates phases 1–5 handled by process_turn (monte_carlo/).
        ScoreOrderCandidates phase 6 filter ported as apply_press_corroboration_penalty
          (heuristics/scoring.py); called from _orders.py with has_real_press guard.
          Proposal sets built by score_order_candidates_from_broadcast (communications/senders.py)
          from ALL g_broadcast_list entries (sent + received); C trees local_3fc/local_204 → gen_xdo,
          local_300 → sup_mto, local_108 (inverted) → sup_hld.
        FUN_00419300 absorbed: MSVC STL RB-tree _Insert — Python dict/set.
        FUN_00466ed0 absorbed: RAII wrapper (copy this→temp, call FUN_00466e10).
        FUN_00466e10 absorbed: RAII wrapper (copy param_2→temp, call FUN_00466c40).
        FUN_00466c40 absorbed: convoy token-seq join (left+[0x4000]+right+[0x4001]+[0x5FFF]);
          0x4001=DAIDE ')', 0x5FFF=end-sentinel, 0x4000='(' (unconfirmed, adjacent slot).
          Branch-2 delegates to FUN_00466330 (plain concat: left++right++[0x5FFF]).
        FUN_00466330 absorbed: plain convoy token-seq concat (no parens); counter=sum of both.
        FUN_00466f80 absorbed: alias-safe RAII wrapper — copies this, then calls FUN_00466c40(copy, param_1, param_2).
        FUN_00465930 absorbed: convoy-seq counter accessor — return 0 if seq[3]==0xFFFFFFFF else seq[3].
        FUN_00410cf0 absorbed: MSVC STL BST _Erase (postorder node dealloc) — Python GC handles this.
        FUN_00443ed0 = AwaitPressAndSendGOF: ported as async one-shot in step 7b above;
          Sleep loop superseded; 25s hold-back and g_cancel_press_sent (DAT_00baed47) wired.
          g_gof_sent reset at turn start (_orders.py step 2); set in _send_gof (gof.py).
        FUN_00465cf0 absorbed: convoy token-seq lexicographic less-than (BST key comparator) — Python list <.
        FUN_00465d90 absorbed: convoy token-seq equality — False if lengths differ, else element-wise compare.
        FUN_00465df0 absorbed: logical NOT of FUN_00465d90 (inequality check).
        FUN_00422a90 ported as validate_and_dispatch_order (dispatch.py).
        RECEIVE_PROPOSAL, RESPOND ported in communications/inbound/respond.py.
        SendAlliancePress ported in communications/senders.py.
        FUN_00457520 (EvaluateOrderProposalsAndSendGOF) ported in bot/client/gof.py.
        """
        own_power_idx = getattr(self.state, 'albert_power_idx', 0)
        n_powers = int(getattr(self.state, 'n_powers', 7))

        # ── 1. ScheduledPressDispatch — pre-loop press flush (line 252) ──────
        dispatch_scheduled_press(self.state, self._send_dm)

        # ── 2. CheckTimeLimit (line 291) — MTL guard ─────────────────────────
        if check_time_limit(self.state):
            logger.warning("MTL expired before BuildAndSendSUB — skipping SUB")
            return

        # send_GOF.c resets these after its ten ProcessTurn passes and before
        # entering BuildAndSendSUB. They are proposal-round diagnostics, not
        # movement-phase lifetime accumulators.
        self.state.g_score_alt = 0
        self.state.g_score_group_duplicates = 0
        self.state.g_score_baseline = 0
        self.state.g_trial_score_a.clear()
        self.state.g_trial_score_b.clear()
        self.state.g_trial_score_c.clear()
        self.state.g_trial_prev_score_alt = 0
        self.state.g_trial_prev_score_baseline = 0

        # ── 3. First proposal node's complete inner trial loop ─────────
        # C submits after the first unprocessed broadcast node reaches its
        # cap. Standalone/no-press Python runs do not materialise the implicit
        # base SUB node, so use an ephemeral node with the same counter.
        press_cap = int(getattr(self.state, 'g_press_proposals_cap', 30))
        _trial_entries = [
            entry for entry in self.state.g_broadcast_list
            if not entry.get('sent', False)
        ]
        _primary_trial_entry = (
            _trial_entries[0] if _trial_entries else {'trial_count': 0}
        )
        if not _advance_broadcast_proposal_trials(
            self.state,
            _primary_trial_entry,
            press_cap,
            dispatch_fn=lambda: dispatch_scheduled_press(
                self.state, self._send_dm),
        ):
            logger.warning("MTL expired during BuildAndSendSUB trials — skipping SUB")
            return
        if _trial_entries:
            _primary_trial_entry['sent'] = True

        # C submits the complete order list referenced by slot zero in
        # DAT_00bbf690/694.  The rank/refresh immediately above populated the
        # Python equivalent.  Choosing max(candidate.score) here bypasses
        # RefreshOrderTable's stochastic selection and is not a C path.
        refreshed_slots = self.state.g_current_best_order.get(own_power_idx, [])
        if refreshed_slots:
            best = None
            order_pairs = refreshed_slots[0]
        else:
            # Defensive fallback for callers that invoke this method without
            # the normal GenerateAndSubmitOrders/update_score_state prelude.
            own_candidates = [
                c for c in best_orders if c.get('power') == own_power_idx
            ]
            if own_candidates:
                best = max(
                    own_candidates, key=lambda c: float(c.get('score', 0.0))
                )
                order_pairs = best.get('orders', [])
            else:
                best = None
                order_pairs = []

        self.state.g_submitted_orders = []
        # Restore g_order_table from the candidate snapshot for our own provinces.
        # process_turn resets g_order_table per-trial and per-power, so by the
        # time we read it here it reflects the *last* trial of the *last*
        # power — not the trial that produced the chosen own-power candidate.
        # The candidate carries the per-order field snapshot (see
        # evaluate_order_proposal in monte_carlo.py); rehydrate the relevant
        # rows before calling _build_order_seq_from_table.
        _diag_dispatch_ok = 0
        _diag_dispatch_fail = 0
        _diag_seq_none = 0
        for entry in order_pairs:
            prov = restore_order_entry(
                self.state.g_order_table, entry, full_row=True)
            seq = _build_order_seq_from_table(self.state, prov)
            if seq is not None:
                rc = validate_and_dispatch_order(
                    self.state, own_power_idx, seq, format_existing=True
                )
                if rc == 0:
                    _diag_dispatch_ok += 1
                else:
                    _diag_dispatch_fail += 1
                    logger.warning(
                        "DIAG[%s] validate_and_dispatch REJECTED rc=%d seq=%s",
                        self.power_name, rc, seq,
                    )
            else:
                _diag_seq_none += 1
                logger.warning(
                    "DIAG[%s] _build_order_seq_from_table returned None for prov=%d",
                    self.power_name, prov,
                )
        logger.info(
            "DIAG[%s] dispatch results: ok=%d fail=%d seq_none=%d "
            "order_pairs=%d",
            self.power_name, _diag_dispatch_ok, _diag_dispatch_fail,
            _diag_seq_none, len(order_pairs),
        )

        formatted = list(getattr(self.state, 'g_submitted_orders', []))

        # Safety net: if MC still produced no usable orders for our units,
        # default every own unit to a HOLD. process_turn now seeds
        # g_order_table[prov, _F_ORDER_TYPE] = _ORDER_HLD for every own unit
        # at trial start (Phase 1b'), so MC normally returns a non-empty
        # candidate even on a fresh / no-press game. This branch only
        # triggers if a trial bug or upstream reset clears the table after
        # seeding — submitting HOLDs is strictly better than nothing
        # (which would be civil disorder) and keeps the test harness alive.
        if not formatted:
            try:
                state = self.game.get_state() if self.game is not None else {}
                units = list(state.get('units', {}).get(self.power_name, []))
            except Exception:
                units = []
            formatted = [f"{u} H" for u in units]
            if formatted:
                logger.info(
                    "MC produced no orders for %s — defaulting %d units to HOLD",
                    self.power_name, len(formatted),
                )
        logger.info("SUB — %d orders for %s: %s",
                    len(formatted), self.power_name, formatted)

        if self.game is not None:
            self._validate_orders(formatted)
            self._schedule_set_orders(formatted)

        # ── Outer broadcast-list loop (LAB_004579a9) ─────────────────────────
        # C: do { } while(true) — iterates g_broadcast_list with a per-node
        # CheckTimeLimit (line 207), ScheduledPressDispatch inside the inner
        # trial sub-loop (line 342), per-node proposal processing for received
        # entries (lines 490–570), per-node SendAllyPressByPower for own
        # entries (lines 575–582), and a restart (goto LAB_004579a9, lines
        # 1204–1211) after proposal-history processing when g_history_counter>19.
        # Python mirrors both the inner trial loop and outer press handling.
        _processed_ids: set = set()
        _time_expired = False
        submitted_provs = {e[0] for e in order_pairs if e}

        from ...communications import (
            send_alliance_press as _send_alliance_press,
        )

        _restart = True
        while _restart:
            _restart = False

            for _entry in list(self.state.g_broadcast_list):
                if id(_entry) in _processed_ids:
                    continue

                # C line 207: CheckTimeLimit at each outer-loop iteration
                if check_time_limit(self.state):
                    _time_expired = True
                    break

                _processed_ids.add(id(_entry))

                # C lines 217–373: each unsent node owns an independent trial
                # counter and runs the complete score/update/history loop.
                if not _entry.get('sent', False):
                    if not _advance_broadcast_proposal_trials(
                        self.state,
                        _entry,
                        press_cap,
                        dispatch_fn=lambda: dispatch_scheduled_press(
                            self.state, self._send_dm),
                    ):
                        _time_expired = True
                        break
                    _entry['sent'] = True

                # C lines 490–570: RECEIVE_PROPOSAL + EvaluatePress + RESPOND
                # Only for received entries (received_flag==1, type_flag==0).
                if _entry.get('received_flag') and _entry.get('type_flag', 0) == 0:
                    self._respond_to_received_press_entry(_entry)

                # C lines 575–582: SendAllyPressByPower for own-entry nodes
                # Condition: not a received entry AND g_history_counter > 0
                if not _entry.get('received_flag') and self.state.g_history_counter > 0:
                    for power_i in range(n_powers):
                        _send_ally_press_by_power(self.state, power_i)

            if _time_expired:
                break

            # C lines 648–1211: after all nodes done, if g_history_counter > 19,
            # process proposal-history map (proxied by g_deal_list) then restart
            # the outer loop (goto LAB_004579a9) to pick up newly added entries.
            if self.state.g_history_counter > 19:
                # C line 654: time-shortcut — skip remaining proposal work if
                # nearly out of time, fall through to AwaitPressAndSendGOF.
                if check_time_limit(self.state):
                    break
                _any_new = False
                for deal in list(getattr(self.state, 'g_deal_list', [])):
                    other = deal.get('power', -1)
                    if other < 0:
                        continue
                    trust = int(self.state.g_ally_trust_score[own_power_idx, other])
                    if trust < 3:
                        continue
                    deal_provs = deal.get('province_set', set())
                    overlap = deal_provs & submitted_provs
                    if overlap:
                        own_tok   = _DAIDE_POWER_NAMES[own_power_idx] if 0 <= own_power_idx < len(_DAIDE_POWER_NAMES) else str(own_power_idx)
                        other_tok = _DAIDE_POWER_NAMES[other]         if 0 <= other         < len(_DAIDE_POWER_NAMES) else str(other)
                        press_seq = f"PRP ( PCE ( {own_tok} {other_tok} ) )"
                        _send_alliance_press(
                            self.state,
                            key=other,
                            entry_data={
                                'power':        other,
                                'province_set': overlap,
                                'press_seq':    press_seq,
                            },
                        )
                        _any_new = True
                        logger.debug(
                            "Deal match: queued alliance press to power %d "
                            "(trust=%d, overlap=%s)",
                            other, trust, overlap,
                        )
                # Restart outer loop if alliance press may have enqueued new
                # broadcast_list entries (C lines 1204–1211 reset list pointers).
                if _any_new:
                    _restart = True

        # ── 7. CancelPriorPress — DM send with TokenSeq_Count guard (line 693)
        cancel_prior_press(self.state, own_power_idx, self._send_dm)

        # ── 7b. Async-adapted AwaitPressAndSendGOF (FUN_00443ed0) ────────────
        # C: after CancelPriorPress arms DAT_00baed47=1, AwaitPressAndSendGOF
        # polls (Sleep loop) until elapsed > g_base_wait_time + 25 s, then
        # sends a bare GOF.  In Python we do a single one-shot check instead
        # of blocking: only fire if GOF has not already been sent this turn
        # and the 25-second hold-back has elapsed since turn start.
        if (getattr(self.state, 'g_cancel_press_sent', 0) == 1
                and not getattr(self.state, 'g_gof_sent', False)):
            _turn_start = float(getattr(self.state, 'g_turn_start_time', 0.0))
            _base_wait  = float(getattr(self.state, 'g_base_wait_time',  0.0))
            _elapsed    = time.time() - _turn_start
            if _elapsed > _base_wait + 25.0 or check_time_limit(self.state):
                logger.debug(
                    "Fallback GOF: elapsed=%.1fs > hold-back=%.1fs — sending",
                    _elapsed, _base_wait + 25.0,
                )
                _send_gof(self.state, self._send_dm)
            else:
                logger.debug(
                    "Fallback GOF: %.1fs remaining in hold-back window — skipped",
                    (_base_wait + 25.0) - _elapsed,
                )

        # ── 8. Final dispatch — flush any THN/SND entries scheduled during
        # steps 5–7.  In the C binary these fire via the real-time scheduler;
        # in Python everything is synchronous so we need an explicit final
        # pass to deliver press that was enqueued after the initial step-1
        # dispatch.
        dispatch_scheduled_press(self.state, self._send_dm)


    def _submit_draw_vote(self) -> None:
        """Submit a YES draw vote to the server/game.

        Only called when Albert actually wants a draw (g_draw_sent == 1).
        The server defaults to neutral each phase, so we never need to
        explicitly send NO or NEUTRAL — only YES when we want it.
        """
        if self._marshal_to_network_loop(self._submit_draw_vote):
            return
        if self.game is None:
            return
        try:
            # NetworkGame (server): async vote request — schedule coroutine
            if hasattr(self.game, 'vote') and callable(self.game.vote):
                future = self.game.vote(vote='yes')
                self._track_request_future(
                    future,
                    f"draw vote for {self.power_name}",
                    getattr(self.game, "current_short_phase", "") or "",
                )
            else:
                # Local Game: set directly on the power object
                power = self.game.powers.get(self.power_name)
                if power is not None:
                    power.vote = 'yes'
            logger.info("Draw vote: submitted YES to server")
        except Exception as exc:
            logger.warning("Draw vote: failed to submit YES: %s", exc)
