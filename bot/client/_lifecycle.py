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

from __future__ import annotations

import asyncio
import copy
import logging
import time
from typing import Any, Callable

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
    # Cross-mixin method (provided by _OrdersMixin)
    generate_and_submit_orders: Callable[[], None]

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
        # NetworkGame and Connection are owned by play()'s event-loop thread.
        # CPU-heavy order generation runs in a worker thread, so outbound API
        # calls must be handed back to this loop (see _marshal_to_network_loop).
        self._network_loop: asyncio.AbstractEventLoop | None = None
        self._client_event_lock: asyncio.Lock | None = None
        self._client_tasks: set[asyncio.Task] = set()
        # Inbound notifications may arrive while the worker owns mutable bot
        # state.  They are deduplicated against NetworkGame.messages and
        # drained on the loop before GOF releases the phase.
        self._seen_msg_ids: set[tuple] = set()
        self._generation_in_progress = False
        self._deferred_gof_phase: str | None = None
        self._responded_press_keys: set[tuple] = set()


    def _marshal_to_network_loop(
        self, callback: Callable[..., None], *args: Any,
    ) -> bool:
        """Run ``callback`` on play()'s loop when called from a worker.

        Returns True when the call was queued and False when the caller is
        already on the owning loop (or play() has not established one).  This
        keeps all python-diplomacy objects confined to their event-loop thread.
        """
        loop = self._network_loop
        if loop is None or loop.is_closed():
            return False
        try:
            running_loop = asyncio.get_running_loop()
        except RuntimeError:
            running_loop = None
        if running_loop is loop:
            return False
        loop.call_soon_threadsafe(callback, *args)
        return True


    def _queue_client_task(self, coroutine: Any, description: str) -> None:
        """Schedule and observe a serialized notification task."""
        loop = self._network_loop
        if loop is None or loop.is_closed():
            logger.warning("Cannot schedule %s: client loop is unavailable", description)
            if asyncio.iscoroutine(coroutine):
                coroutine.close()
            return
        task = loop.create_task(coroutine, name=f"albert:{description}")
        self._client_tasks.add(task)

        def _task_done(done_task: asyncio.Task) -> None:
            self._client_tasks.discard(done_task)
            try:
                done_task.result()
            except asyncio.CancelledError:
                return
            except Exception:
                logger.exception("%s failed", description)

        task.add_done_callback(_task_done)


    async def _run_game_update_async(
        self, game_object: Any, expected_phase: str | None = None,
    ) -> None:
        """Synchronize a phase, then generate orders without blocking I/O."""
        if self._client_event_lock is None:
            self._client_event_lock = asyncio.Lock()
        async with self._client_event_lock:
            live_phase = _game_phase(game_object)
            if expected_phase and live_phase != expected_phase:
                logger.info(
                    "Skipping stale phase update: queued=%s current=%s",
                    expected_phase,
                    live_phase,
                )
                return

            self.game = game_object
            self.state.synchronize_from_game(game_object)
            self._drain_incoming_press(game_object)

            if live_phase != 'COMPLETED' and _game_status(game_object) != 'completed':
                # Monte Carlo regularly takes longer than the server's ping
                # timeout.  A worker keeps Tornado/asyncio servicing WebSocket
                # pings, notifications, and request responses in the meantime.
                self._generation_in_progress = True
                try:
                    await asyncio.to_thread(self.generate_and_submit_orders)

                    # NetworkGame is updated by its notification callbacks
                    # while the worker is running.  Pull those messages into
                    # Albert's state before releasing GOF: parsing them only in
                    # the separately queued message task is too late because
                    # BuildAndSendSUB has already returned and the next phase
                    # synchronization clears g_broadcast_list.
                    await asyncio.sleep(0)
                    self._drain_incoming_press(game_object)
                    self._respond_to_pending_press_entries()
                finally:
                    self._generation_in_progress = False

                # _send_gof() runs in the worker.  _send_dm() records that GOF
                # while generation is active instead of calling no_wait(), so
                # all press received during the turn gets one response pass
                # before this power declares itself ready.
                if self._deferred_gof_phase is not None:
                    deferred_phase = self._deferred_gof_phase
                    self._deferred_gof_phase = None
                    if deferred_phase == _game_phase(game_object):
                        self._send_dm('GOF')


    async def _run_message_async(
        self, sender: str, body: str, msg_id: tuple | None = None,
    ) -> None:
        """Serialize inbound press, then run its response path immediately."""
        if self._client_event_lock is None:
            self._client_event_lock = asyncio.Lock()
        async with self._client_event_lock:
            if not self._ingest_message_once(sender, body, msg_id):
                return
            self._respond_to_pending_press_entries()


    async def play(self):
        """
        Main event loop connecting to the diplomacy server.

        Uses NetworkGame notification callbacks (GameProcessed,
        GameStatusUpdate, GameMessageReceived) for reactive phase handling
        instead of a fixed-interval poll loop.  A lightweight 30s heartbeat
        poll remains as a safety net (catches missed notifications or
        server reconnects).
        """
        self._network_loop = asyncio.get_running_loop()
        self._client_event_lock = asyncio.Lock()
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


        # ── Register notification callbacks ──────────────────────────────
        done_event = asyncio.Event()

        def _on_game_processed(game, notification):
            """Called by the diplomacy lib after each phase processes."""
            phase = _game_phase(game)
            if phase == self.current_phase:
                return  # duplicate notification
            self.current_phase = phase
            logger.info(f"[notification] New phase: {phase}")
            self._queue_client_task(
                self._run_game_update_async(game, phase),
                f"phase update {phase}",
            )

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
            self._queue_client_task(
                self._run_message_async(
                    sender, body, self._message_identity(msg)),
                f"press from {sender}",
            )

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
                await self._run_game_update_async(self.game, phase)
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
                self._queue_client_task(
                    self._run_game_update_async(self.game, phase),
                    f"heartbeat phase update {phase}",
                )

        logger.info("Game finished — exiting Albert loop")


    def on_game_update(self, game_object):
        """
        Triggered when NOW or SCO received (or state polled).
        Mirrors the NOW handler → vtable+0xe8 → GenerateAndSubmitOrders call chain.

        Also drains inbound game.messages and feeds each new one to
        on_message_received between synchronize_from_game and order generation.
        synchronize_from_game clears the prior turn's g_broadcast_list like
        GenerateAndSubmitOrders.c, then this method drains the new phase's
        queued messages so current-turn press survives into translation.
        """
        self.game = game_object
        self.state.synchronize_from_game(game_object)
        self._drain_incoming_press(game_object)

        if _game_phase(game_object) != 'COMPLETED' and _game_status(game_object) != 'completed':
            self.generate_and_submit_orders()


    @staticmethod
    def _message_identity(message: Any) -> tuple:
        """Return the same stable identity for callback and history drains."""
        return (
            getattr(message, 'time_sent', None),
            getattr(message, 'sender', None),
            getattr(message, 'recipient', None),
            getattr(message, 'message', None),
        )


    def _ingest_message_once(
        self, sender: str, body: str, msg_id: tuple | None = None,
    ) -> bool:
        """Parse one press message unless its callback/history copy was seen."""
        if msg_id is not None:
            if msg_id in self._seen_msg_ids:
                return False
            self._seen_msg_ids.add(msg_id)
        self.on_message_received(sender, body)
        return True


    def _drain_incoming_press(self, game_object) -> int:
        """Walk new game.messages and dispatch each through on_message_received.

        Tracks message identities to dedupe callback and poll/history copies.
        Skips messages we sent ourselves.
        """
        msgs = getattr(game_object, 'messages', None)
        if msgs is None:
            return 0
        try:
            seq = list(msgs.values()) if hasattr(msgs, 'values') else list(msgs)
        except Exception:
            return 0
        ingested = 0
        for m in seq:
            msg_id = self._message_identity(m)
            if msg_id in self._seen_msg_ids:
                continue
            sender = getattr(m, 'sender', '') or ''
            if sender == self.power_name:
                self._seen_msg_ids.add(msg_id)
                continue
            body = getattr(m, 'message', '') or ''
            logger.debug("[albert<-press] from %s: %r", sender, body)
            try:
                if self._ingest_message_once(sender, body, msg_id):
                    ingested += 1
            except Exception:
                logger.exception("on_message_received raised for %r", body)
        return ingested


    def on_message_received(self, sender: str, msg: str) -> None:
        """Triggered when a press message (FRM) arrives."""
        parse_message(self.state, sender, msg)
