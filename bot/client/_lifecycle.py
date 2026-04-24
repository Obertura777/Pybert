"""Lifecycle-mixin half of AlbertClient.

Split from bot/client.py during the 2026-04 refactor.

Holds the connection / asyncio-loop / inbound-press-draining methods
that make up the client's lifecycle half:

  * ``__init__``                 — instance-state construction.
  * ``play``                     — top-level asyncio turn loop.
  * ``on_game_update``           — GameProcessed / GameStatusUpdate hook.
  * ``_drain_incoming_press``    — pulls queued inbound press into state.
  * ``on_message_received``      — GameMessageReceived hook.

Composed with ``_OrdersMixin`` and ``_PressMixin`` to form ``AlbertClient``;
cross-mixin method calls resolve through normal MRO at call time.
"""

import asyncio
import copy
import logging
import random
import time

import numpy as np
from diplomacy.client.connection import connect

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


class _LifecycleMixin:
    # DONE(api): #4 — play() uses NetworkGame notification callbacks
    #   (GameProcessed, GameStatusUpdate, GameMessageReceived) with a 30s
    #   heartbeat safety-net poll instead of 2s blind polling.
    # DONE(api): #5 — _validate_orders() checks submitted orders against
    #   game.get_all_possible_orders() before every set_orders() call.
    #   Logs warnings for illegal orders without blocking submission.
    # DONE(api): #6 — send_is_bot() and set_comm_status() called after join.
    def __init__(self, power_name: str, host: str, port: int, *,
                 username: str | None = None, password: str = 'password',
                 game_id: str | None = None):
        self.power_name = power_name
        self.host = host
        self.port = port
        self.username = username or f'Albert_{power_name}'
        self.password = password
        self.target_game_id = game_id   # None = auto-pick first available
        self.state = InnerGameState()
        self.connection = None
        self.game = None
        self.current_phase = None


    async def play(self):
        """
        Main event loop connecting to the diplomacy server.

        Uses NetworkGame notification callbacks (GameProcessed,
        GameStatusUpdate, GameMessageReceived) for reactive phase handling
        instead of a fixed-interval poll loop.  A lightweight 30s heartbeat
        poll remains as a safety net (catches missed notifications or
        server reconnects).
        """
        self.connection = await connect(self.host, self.port)
        channel = await self.connection.authenticate(
            username=self.username,
            password=self.password,
        )

        logger.info(f"Albert successfully authenticated as {self.power_name}"
                     f" (user={self.username!r})")

        if self.target_game_id:
            target_game_id = self.target_game_id
        else:
            games = await channel.list_games()
            if not games:
                logger.warning("No active games found on the server.")
                return
            # `list_games()` returns DataGameInfo records (attribute access),
            # but older builds returned plain dicts. Support both.
            first = games[0]
            target_game_id = first['game_id'] if isinstance(first, dict) else first.game_id

        logger.info(f"Joining game: {target_game_id}")

        self.game = await channel.join_game(game_id=target_game_id, power_name=self.power_name)

        # ── Announce bot metadata to server ──────────────────────────────
        try:
            if hasattr(self.game, 'send_is_bot'):
                self.game.send_is_bot(is_bot=True)
            if hasattr(self.game, 'set_comm_status'):
                self.game.set_comm_status(comm_status='ready')
            logger.info("Announced bot metadata to server.")
        except Exception as exc:
            logger.debug("Bot metadata announcement failed (non-fatal): %s", exc)

        # ── Register notification callbacks ──────────────────────────────
        done_event = asyncio.Event()

        def _on_game_processed(game, notification):
            """Called by the diplomacy lib after each phase processes."""
            phase = _game_phase(game)
            if phase == self.current_phase:
                return  # duplicate notification
            self.current_phase = phase
            logger.info(f"[notification] New phase: {phase}")
            try:
                self.on_game_update(game)
            except Exception as exc:
                logger.exception(f"on_game_update raised: {exc}")

        def _on_game_status_update(game, notification):
            """Called when game status changes (completed, canceled, etc.)."""
            status = getattr(notification, 'status', '') or ''
            logger.info(f"[notification] Game status: {status}")
            if status in ('completed', 'canceled'):
                done_event.set()

        def _on_message_received(game, notification):
            """Called when a press message arrives between phases."""
            msg = getattr(notification, 'message', None)
            if msg is None:
                return
            sender = getattr(msg, 'sender', '') or ''
            if sender == self.power_name:
                return  # skip own messages
            body = getattr(msg, 'message', '') or ''
            logger.debug("[notification] press from %s: %r", sender, body)
            try:
                self.on_message_received(sender, body)
            except Exception:
                logger.exception("on_message_received raised for %r", body)

        if hasattr(self.game, 'add_on_game_processed'):
            self.game.add_on_game_processed(_on_game_processed)
            self.game.add_on_game_status_update(_on_game_status_update)
            self.game.add_on_game_message_received(_on_message_received)
            logger.info("Registered notification callbacks (reactive mode).")
        else:
            logger.info("NetworkGame notifications not available; using poll mode.")

        # ── Process the initial phase (game may already be in progress) ──
        phase = _game_phase(self.game)
        status = _game_status(self.game)
        if status in ('completed', 'canceled'):
            logger.info("Game already finished — exiting.")
            return
        if phase and phase != 'FORMING':
            self.current_phase = phase
            logger.info(f"Initial phase: {phase}")
            try:
                self.on_game_update(self.game)
            except Exception as exc:
                logger.exception(f"on_game_update raised on initial phase: {exc}")

        # ── Wait for game end, with a heartbeat safety-net poll ──────────
        HEARTBEAT = 30  # seconds between fallback polls
        while not done_event.is_set():
            try:
                await asyncio.wait_for(done_event.wait(), timeout=HEARTBEAT)
            except asyncio.TimeoutError:
                pass  # heartbeat tick — check for missed phase changes

            # Safety-net: detect phase changes the notification may have missed
            try:
                phase = _game_phase(self.game)
                status = _game_status(self.game)
            except Exception as exc:
                logger.exception(f"Albert heartbeat: error reading state: {exc}")
                continue

            if status in ('completed', 'canceled'):
                logger.info("Game finished (heartbeat) — exiting Albert loop")
                return

            if phase and phase != self.current_phase:
                self.current_phase = phase
                logger.info(f"Missed-notification catch-up: {phase}")
                try:
                    self.on_game_update(self.game)
                except Exception as exc:
                    logger.exception(f"on_game_update raised: {exc}")

        logger.info("Game finished — exiting Albert loop")


    def on_game_update(self, game_object):
        """
        Triggered when NOW or SCO received (or state polled).
        Mirrors the NOW handler → vtable+0xe8 → GenerateAndSubmitOrders call chain.

        Also drains inbound game.messages and feeds each new one to
        on_message_received between synchronize_from_game and order generation.
        synchronize_from_game intentionally does NOT clear g_BroadcastList
        (matching the C binary's accumulate-forever semantics), so press
        registered here survives into the translator/corroboration pass.
        """
        self.game = game_object
        self.state.synchronize_from_game(game_object)
        self._drain_incoming_press(game_object)

        if _game_phase(game_object) != 'COMPLETED' and _game_status(game_object) != 'completed':
            self.generate_and_submit_orders()


    def _drain_incoming_press(self, game_object) -> None:
        """Walk new game.messages and dispatch each through on_message_received.

        Tracks (time_sent, sender, recipient) tuples to dedupe across polls.
        Skips messages we sent ourselves.
        """
        if not hasattr(self, '_seen_msg_ids') or self._seen_msg_ids is None:
            self._seen_msg_ids = set()
        msgs = getattr(game_object, 'messages', None)
        if msgs is None:
            return
        try:
            seq = list(msgs.values()) if hasattr(msgs, 'values') else list(msgs)
        except Exception:
            return
        for m in seq:
            msg_id = (
                getattr(m, 'time_sent', None),
                getattr(m, 'sender', None),
                getattr(m, 'recipient', None),
            )
            if msg_id in self._seen_msg_ids:
                continue
            self._seen_msg_ids.add(msg_id)
            sender = getattr(m, 'sender', '') or ''
            if sender == self.power_name:
                continue
            body = getattr(m, 'message', '') or ''
            logger.debug("[albert<-press] from %s: %r", sender, body)
            try:
                self.on_message_received(sender, body)
            except Exception:
                logger.exception("on_message_received raised for %r", body)


    def on_message_received(self, sender: str, msg: str) -> None:
        """Triggered when a press message (FRM) arrives."""
        parse_message(self.state, sender, msg)
