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

import asyncio
import copy
import logging
import random
import time

import numpy as np

from ...state import InnerGameState
from ...monte_carlo import (
    process_turn,
    update_score_state,
    check_time_limit,
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

from .._shared import _POWER_NAMES
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


class _PressMixin:
    def _send_dm(self, msg: object) -> None:
        """
        Send DAIDE direct-message using python-diplomacy NetworkGame API.

        Per-power fan-out — Albert never broadcasts to ``GLOBAL``.  Even when
        the underlying DAIDE press is logically a broadcast (GOF, BCC, an
        XDO PRP intended for everyone), python-diplomacy treats GLOBAL as a
        "system / all observers" channel that bypasses the per-power inbox
        and shows up untargeted in the message log.  The C original always
        addressed press to a specific recipient power; reproducing that here
        means iterating ``self.game.powers`` and emitting one Message per
        non-self power.

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
        logger.debug("SendDM: %r", msg)
        if self.game is None:
            return
        try:
            from diplomacy import Message
        except ImportError:
            logger.warning("diplomacy.Message not available; cannot send DAIDE press.")
            return

        # Determine recipient set.  An explicit per-power recipient on the
        # message object wins; otherwise fan out to every other power.
        msg_recipient = getattr(msg, 'recipient', None)
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

        body = str(msg)
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
                _SEND_RETRIES = 3
                for _attempt in range(_SEND_RETRIES):
                    try:
                        fut = self.game.send_game_message(message=message_obj)
                        if _asyncio.iscoroutine(fut):
                            try:
                                loop = _asyncio.get_running_loop()
                                fut = loop.create_task(fut)
                            except RuntimeError:
                                _asyncio.run(fut)
                                break
                        if hasattr(fut, 'add_done_callback'):
                            def _log_send_error(f, _r=recipient, _p=phase):
                                try:
                                    f.result()
                                except Exception as exc:
                                    logger.warning(
                                        "_send_dm: send_game_message rejected"
                                        " (recipient=%r, phase=%r): %s: %s",
                                        _r, _p, type(exc).__name__, exc,
                                    )
                            fut.add_done_callback(_log_send_error)
                        break  # dispatch succeeded
                    except Exception as exc:
                        if _attempt < _SEND_RETRIES - 1:
                            _delay = 0.5 * (2 ** _attempt)
                            logger.info(
                                "_send_dm: send_game_message attempt %d/%d"
                                " failed (recipient=%r, phase=%r): %s —"
                                " retrying in %.1fs",
                                _attempt + 1, _SEND_RETRIES,
                                recipient, phase, exc, _delay,
                            )
                            import time as _time
                            _time.sleep(_delay)
                        else:
                            logger.warning(
                                "_send_dm: send_game_message failed after"
                                " %d attempts (recipient=%r, phase=%r):"
                                " %s: %s",
                                _SEND_RETRIES, recipient, phase,
                                type(exc).__name__, exc,
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


    def _build_and_send_sub(self, best_orders: list) -> None:
        """
        Port of BuildAndSendSUB (FUN_00457890).

        In the C bot this is a multi-trial proposal-scoring loop over
        g_BroadcastList; Monte Carlo (process_turn) plays that role in Python,
        so only the surrounding press/submission scaffold is ported here.

        Structure (mirroring FUN_00457890 at each labelled site):
          1. ScheduledPressDispatch     — pre-loop flush (line 252).
          2. CheckTimeLimit             — abort if MTL already fired (line 291).
          3. Order submission           — RegisterProposalOrders / ScoreOrderCandidates
                                         collapsed to game.set_orders (MC already ran).
          4. UpdateScoreState           — refresh ally order tables after commit
                                         (line 395 inside inner loop, post-submission).
          5. SendAllyPressByPower loop  — for each power when g_HistoryCounter > 0
                                         (lines 659–666).
          6. g_ProposalHistoryMap press — iterate received/sent proposals, check
                                         province overlap and trust, send DM press
                                         (lines 847–1271; STUB — awaits RECEIVE_PROPOSAL
                                         / RESPOND / g_ProposalHistoryMap port).
          7. CancelPriorPress           — withdraw stale prior-press token (line 693).

        Callees still unported: ScoreOrderCandidates (FUN_004559c0),
        RECEIVE_PROPOSAL, RESPOND, SendAlliancePress,
        FUN_00419300, FUN_00466ed0, FUN_00466f80, FUN_00465df0,
        FUN_00465930, FUN_00465d90, FUN_00465cf0, FUN_00410cf0,
        FUN_00443ed0.
        FUN_00422a90 ported as validate_and_dispatch_order (dispatch.py).
        """
        own_power_idx = getattr(self.state, 'albert_power_idx', 0)
        n_powers = int(getattr(self.state, 'n_powers', 7))

        # ── 1. ScheduledPressDispatch — pre-loop press flush (line 252) ──────
        dispatch_scheduled_press(self.state, self._send_dm)

        # ── 2. CheckTimeLimit (line 291) — MTL guard ─────────────────────────
        if check_time_limit(self.state):
            logger.warning("MTL expired before BuildAndSendSUB — skipping SUB")
            return

        # Pick the highest-scoring candidate for OUR power. process_turn
        # appends one candidate record per (power, trial), so best_orders
        # holds candidates for all 7 powers — we want our own.
        own_candidates = [c for c in best_orders if c.get('power') == own_power_idx]
        if own_candidates:
            best = max(own_candidates, key=lambda c: float(c.get('score', 0.0)))
            order_pairs = best.get('orders', [])
        else:
            best = None
            order_pairs = []

        self.state.g_SubmittedOrders = []
        # Restore g_OrderTable from the candidate snapshot for our own provinces.
        # process_turn resets g_OrderTable per-trial and per-power, so by the
        # time we read it here it reflects the *last* trial of the *last*
        # power — not the trial that produced the chosen own-power candidate.
        # The candidate carries the per-order field snapshot (see
        # evaluate_order_proposal in monte_carlo.py); rehydrate the relevant
        # rows before calling _build_order_seq_from_table.
        from ..monte_carlo import _F_SECONDARY as _MC_F_SECONDARY  # local import
        for entry in order_pairs:
            if len(entry) >= 5:
                prov, order_type, dest_prov, dest_coast, secondary = entry[:5]
                self.state.g_OrderTable[prov, _F_ORDER_TYPE] = float(order_type)
                self.state.g_OrderTable[prov, _F_DEST_PROV]  = float(dest_prov)
                self.state.g_OrderTable[prov, _F_DEST_COAST] = float(dest_coast)
                self.state.g_OrderTable[prov, _MC_F_SECONDARY] = float(secondary)
            else:
                prov = entry[0]
            seq = _build_order_seq_from_table(self.state, prov)
            if seq is not None:
                validate_and_dispatch_order(self.state, own_power_idx, seq)

        formatted = list(getattr(self.state, 'g_SubmittedOrders', []))

        # Safety net: if MC still produced no usable orders for our units,
        # default every own unit to a HOLD. process_turn now seeds
        # g_OrderTable[prov, _F_ORDER_TYPE] = _ORDER_HLD for every own unit
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
            try:
                self.game.set_orders(power_name=self.power_name, orders=formatted, wait=False)
            except TypeError:
                # Older diplomacy lib doesn't support wait kwarg
                self.game.set_orders(power_name=self.power_name, orders=formatted)

        # ── 3b. RankCandidatesForPower — inner-loop candidate selection ─────
        # C: FUN_00424850(piVar10, '\0') called per-power in BuildAndSendSUB
        # inner loop after ScoreOrderCandidates.  In Python, MC has already
        # run; call once per power to rank g_CandidateRecordList entries.
        for power_i in range(n_powers):
            _rank_candidates_for_power(self.state, power_i)

        # ── 4. UpdateScoreState — post-commit refresh (line 395) ─────────────
        update_score_state(self.state)

        # ── 5. SendAllyPressByPower loop (lines 659–666) ─────────────────────
        # C: if puVar18[4] == DAT_00baed60 AND g_HistoryCounter > 0:
        #      for i in range(n_powers): SendAllyPressByPower(i)
        # The g_BroadcastList node condition collapses to "own proposal processed"
        # which is always true here after order submission.
        if self.state.g_HistoryCounter > 0:
            for power_i in range(n_powers):
                _send_ally_press_by_power(self.state, power_i)

        # ── 6a. RECEIVE_PROPOSAL + EvaluatePress + RESPOND pass ───────────────
        # C: BuildAndSendSUB outer loop (lines 490–569) processes g_BroadcastList
        #    entries where received_flag==1 AND type_flag==0 AND
        #    trial_count == g_PressProposalsCap.
        # Python: MC already ran; treat all received entries as fully scored.
        # After RESPOND, C calls FUN_00457520 (EvaluateOrderProposalsAndSendGOF).
        from ..communications import (
            receive_proposal as _receive_proposal,
            evaluate_press   as _evaluate_press,
            respond          as _respond,
        )
        press_cap = getattr(self.state, 'g_PressProposalsCap', 30)
        for _entry in list(self.state.g_BroadcastList):
            if not _entry.get('received_flag'):
                continue
            if _entry.get('type_flag', 0) != 0:
                continue
            # Python MC already ran; treat trial_count as complete.
            _entry['trial_count'] = press_cap

            _from_tok  = _entry.get('from_power_tok', 0)
            _from_idx  = _from_tok & 0xff
            _prop_toks = _entry.get('sublist3', _entry.get('press_content', []))

            # RECEIVE_PROPOSAL — dedup + log + PrepareAllyPressEntry
            _receive_proposal(self.state, _from_idx, _prop_toks, self._send_dm)

            # EvaluatePress = FUN_0042fc40 → YES (0x481C) or REJ (0x4814)
            _sVar2 = _evaluate_press(self.state, _entry)

            # RESPOND = albert/Source/RESPOND.c
            _st = _entry.get('sched_time', 0)
            _respond(
                self.state,
                press_list=_entry,
                response_type=_sVar2,
                elapsed_lo=_st & 0xFFFFFFFF,
                elapsed_hi=(_st >> 32) & 0xFFFFFFFF,
                send_fn=self._send_dm,
            )
            # C line 569: FUN_00457520 = EvaluateOrderProposalsAndSendGOF
            _evaluate_order_proposals_and_send_gof(self.state, self._send_dm)

        # ── 6b. g_DealList press deal matching (lines 847–1271, g_HistoryCounter>19)
        # C iterates g_BroadcastList for own-proposal entries; for each entry
        #   with trust ≥ 1/2 and province overlap, sends SUB press via
        #   SendAlliancePress.  Proxy: iterate g_DealList (trust ≥ 3, overlap).
        if self.state.g_HistoryCounter > 19:
            from ..communications import send_alliance_press
            submitted_provs = {prov for prov, _ in order_pairs}
            for deal in list(getattr(self.state, 'g_DealList', [])):
                other = deal.get('power', -1)
                if other < 0:
                    continue
                trust = int(self.state.g_AllyTrustScore[own_power_idx, other])
                if trust < 3:
                    continue
                deal_provs = deal.get('province_set', set())
                overlap = deal_provs & submitted_provs
                if overlap:
                    press_seq = f"PRP ( PCE ( {own_power_idx} {other} ) )"
                    send_alliance_press(
                        self.state,
                        key=other,
                        entry_data={
                            'power':        other,
                            'province_set': overlap,
                            'press_seq':    press_seq,
                        },
                    )
                    logger.debug(
                        "Deal match: queued alliance press to power %d "
                        "(trust=%d, overlap=%s)",
                        other, trust, overlap,
                    )

        # ── 7. CancelPriorPress — DM send with TokenSeq_Count guard (line 693)
        cancel_prior_press(self.state, own_power_idx, self._send_dm)


    def _submit_draw_vote(self) -> None:
        """Submit a YES draw vote to the server/game.

        Only called when Albert actually wants a draw (g_draw_sent == 1).
        The server defaults to neutral each phase, so we never need to
        explicitly send NO or NEUTRAL — only YES when we want it.
        """
        if self.game is None:
            return
        try:
            # NetworkGame (server): async vote request
            if hasattr(self.game, 'vote') and callable(self.game.vote):
                self.game.vote(vote='yes')
            else:
                # Local Game: set directly on the power object
                power = self.game.powers.get(self.power_name)
                if power is not None:
                    power.vote = 'yes'
            logger.info("Draw vote: submitted YES to server")
        except Exception as exc:
            logger.warning("Draw vote: failed to submit YES: %s", exc)
