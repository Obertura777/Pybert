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
import random
import time
from typing import Any, Callable

import numpy as np

from ...state import InnerGameState
from ...monte_carlo import (
    process_turn,
    update_score_state,
    check_time_limit,
    _F_ORDER_TYPE, _F_DEST_PROV, _F_DEST_COAST,
    _ORDER_HLD, _ORDER_MTO,
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
    # Declared for type checkers — assigned in _LifecycleMixin.__init__
    state: InnerGameState
    power_name: str
    game: Any
    current_phase: str | None

    # Cross-mixin method (provided by _OrdersMixin)
    _validate_orders: Callable[..., None]

    def _schedule_set_orders(self, orders: list[str]) -> None:
        """Submit orders to the game, handling async NetworkGame properly.

        NetworkGame.set_orders() returns a coroutine that must be awaited.
        Since we're called from a synchronous notification callback, we
        schedule the coroutine on the running event loop via create_task().
        For local Game objects (tests), set_orders is synchronous (returns None).
        """
        if self.game is None:
            return
        try:
            coro = self.game.set_orders(
                power_name=self.power_name, orders=orders, wait=False)
        except TypeError:
            coro = self.game.set_orders(
                power_name=self.power_name, orders=orders)
        if coro is not None and asyncio.iscoroutine(coro):
            try:
                loop = asyncio.get_running_loop()
                loop.create_task(coro)
            except RuntimeError:
                logger.warning(
                    "No running event loop — set_orders for %s not sent",
                    self.power_name)

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
                _SEND_RETRIES = 3
                for _attempt in range(_SEND_RETRIES):
                    try:
                        fut = self.game.send_game_message(message=message_obj)
                        if _asyncio.iscoroutine(fut):
                            coro = fut
                            try:
                                loop = _asyncio.get_running_loop()
                                fut = loop.create_task(coro)
                            except RuntimeError:
                                _asyncio.run(coro)
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
        g_broadcast_list; Monte Carlo (process_turn) plays that role in Python,
        so only the surrounding press/submission scaffold is ported here.

        Structure (mirroring FUN_00457890 at each labelled site):
          1. ScheduledPressDispatch     — pre-loop flush (line 252).
          2. CheckTimeLimit             — abort if MTL already fired (line 291).
          3. Order submission           — RegisterProposalOrders / ScoreOrderCandidates
                                         collapsed to game.set_orders (MC already ran).
          4. UpdateScoreState           — refresh ally order tables after commit
                                         (line 395 inside inner loop, post-submission).
          5. SendAllyPressByPower loop  — for each power when g_history_counter > 0
                                         (lines 659–666).
          6a. RECEIVE_PROPOSAL + EvaluatePress + RESPOND pass — process
                                         g_broadcast_list received entries
                                         (lines 490–569); calls
                                         EvaluateOrderProposalsAndSendGOF
                                         (FUN_00457520) after each RESPOND.
          6b. g_deal_list press — trust+overlap check, SendAlliancePress
                                         (lines 847–1271; g_proposal_history_map
                                         proxied by g_deal_list).
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

        # ── Swap breaker: detect same-power reciprocal moves (A→B + B→A) ──
        # In Diplomacy, two units from the same power cannot swap provinces;
        # they bounce and both hold.  The MC trial loop assigns unit orders
        # independently and never checks for intra-power swaps, so we break
        # them here by converting the lower-province unit to HLD.
        if order_pairs:
            _mto_map = {}  # prov → dest_prov for MTO orders
            for entry in order_pairs:
                if len(entry) >= 3 and int(entry[1]) == _ORDER_MTO:
                    _mto_map[int(entry[0])] = int(entry[2])
            _swap_victims = set()
            for prov_a, dest_a in _mto_map.items():
                if dest_a in _mto_map and _mto_map[dest_a] == prov_a:
                    # Swap detected — mark the lower-province unit as victim
                    victim = min(prov_a, dest_a)
                    _swap_victims.add(victim)
            if _swap_victims:
                new_pairs = []
                for entry in order_pairs:
                    prov = int(entry[0])
                    if prov in _swap_victims:
                        # Convert to HLD: (prov, ORDER_HLD, prov, 0, 0)
                        new_pairs.append(
                            (entry[0], _ORDER_HLD, entry[0], 0, 0)
                        )
                        logger.warning(
                            "DIAG[%s] broke same-power swap: prov %d was "
                            "MTO→%d, converted to HLD",
                            self.power_name, prov, int(entry[2]),
                        )
                    else:
                        new_pairs.append(entry)
                order_pairs = new_pairs

        self.state.g_submitted_orders = []
        # Restore g_order_table from the candidate snapshot for our own provinces.
        # process_turn resets g_order_table per-trial and per-power, so by the
        # time we read it here it reflects the *last* trial of the *last*
        # power — not the trial that produced the chosen own-power candidate.
        # The candidate carries the per-order field snapshot (see
        # evaluate_order_proposal in monte_carlo.py); rehydrate the relevant
        # rows before calling _build_order_seq_from_table.
        from ...monte_carlo import _F_SECONDARY as _MC_F_SECONDARY  # local import
        _diag_dispatch_ok = 0
        _diag_dispatch_fail = 0
        _diag_seq_none = 0
        for entry in order_pairs:
            if len(entry) >= 5:
                prov, order_type, dest_prov, dest_coast, secondary = entry[:5]
                self.state.g_order_table[prov, _F_ORDER_TYPE] = float(order_type)
                self.state.g_order_table[prov, _F_DEST_PROV]  = float(dest_prov)
                self.state.g_order_table[prov, _F_DEST_COAST] = float(dest_coast)
                self.state.g_order_table[prov, _MC_F_SECONDARY] = float(secondary)
            else:
                prov = entry[0]
            seq = _build_order_seq_from_table(self.state, prov)
            if seq is not None:
                rc = validate_and_dispatch_order(self.state, own_power_idx, seq)
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

        # ── 3b. RankCandidatesForPower — inner-loop candidate selection ─────
        # C: FUN_00424850(piVar10, '\0') called per-power in BuildAndSendSUB
        # inner loop after ScoreOrderCandidates.  In Python, MC has already
        # run; call once per power to rank g_candidate_record_list entries.
        for power_i in range(n_powers):
            _rank_candidates_for_power(self.state, power_i)

        # ── 4. UpdateScoreState — post-commit refresh (line 395) ─────────────
        update_score_state(self.state)

        # ── 5. SendAllyPressByPower loop (lines 659–666) ─────────────────────
        # C: if puVar18[4] == DAT_00baed60 AND g_history_counter > 0:
        #      for i in range(n_powers): SendAllyPressByPower(i)
        # The g_broadcast_list node condition collapses to "own proposal processed"
        # which is always true here after order submission.
        if self.state.g_history_counter > 0:
            for power_i in range(n_powers):
                _send_ally_press_by_power(self.state, power_i)

        # ── 6a. RECEIVE_PROPOSAL + EvaluatePress + RESPOND pass ───────────────
        # C: BuildAndSendSUB outer loop (lines 490–569) processes g_broadcast_list
        #    entries where received_flag==1 AND type_flag==0 AND
        #    trial_count == g_press_proposals_cap.
        # Python: MC already ran; treat all received entries as fully scored.
        # After RESPOND, C calls FUN_00457520 (EvaluateOrderProposalsAndSendGOF).
        from ...communications import (
            receive_proposal as _receive_proposal,
            evaluate_press   as _evaluate_press,
            respond          as _respond,
        )
        press_cap = getattr(self.state, 'g_press_proposals_cap', 30)
        for _entry in list(self.state.g_broadcast_list):
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

        # ── 6b. g_deal_list press deal matching (lines 847–1271, g_history_counter>19)
        # C iterates g_broadcast_list for own-proposal entries; for each entry
        #   with trust ≥ 1/2 and province overlap, sends SUB press via
        #   SendAlliancePress.  Proxy: iterate g_deal_list (trust ≥ 3, overlap).
        if self.state.g_history_counter > 19:
            from ...communications import send_alliance_press
            submitted_provs = {entry[0] for entry in order_pairs if entry}
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
        if self.game is None:
            return
        try:
            # NetworkGame (server): async vote request — schedule coroutine
            if hasattr(self.game, 'vote') and callable(self.game.vote):
                coro = self.game.vote(vote='yes')
                if coro is not None and asyncio.iscoroutine(coro):
                    try:
                        asyncio.get_running_loop().create_task(coro)
                    except RuntimeError:
                        pass
            else:
                # Local Game: set directly on the power object
                power = self.game.powers.get(self.power_name)
                if power is not None:
                    power.vote = 'yes'
            logger.info("Draw vote: submitted YES to server")
        except Exception as exc:
            logger.warning("Draw vote: failed to submit YES: %s", exc)
