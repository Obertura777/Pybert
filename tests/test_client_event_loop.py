"""Concurrency regressions for the NetworkGame client adapter."""

import asyncio
import os
import sys
import threading
import time
from types import SimpleNamespace
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_client_mod = __import__(f"{_pkg_name}.bot.client", fromlist=["AlbertClient"])
AlbertClient = _client_mod.AlbertClient
_press_mod = __import__(
    f"{_pkg_name}.bot.client._press", fromlist=["_PressMixin"])
_communications_mod = __import__(
    f"{_pkg_name}.communications", fromlist=["evaluate_press"])
_senders_mod = __import__(
    f"{_pkg_name}.communications.senders", fromlist=["cancel_prior_press"])


class _FakeNetworkGame:
    current_short_phase = "S1902M"
    status = "active"
    messages = {}

    def __init__(self, owner_thread: int, order_sent: asyncio.Event) -> None:
        self.owner_thread = owner_thread
        self.order_sent = order_sent
        self.set_orders_threads: list[int] = []
        self.no_wait_threads: list[int] = []
        self.wait_threads: list[int] = []
        self.sent_messages: list[object] = []
        self.powers = {"FRANCE": object(), "ENGLAND": object()}

    def set_orders(self, *, power_name, orders, wait=True):
        assert power_name == "FRANCE"
        assert orders == ["A PAR H"]
        assert wait is True
        self.set_orders_threads.append(threading.get_ident())
        self.order_sent.set()
        return None

    def no_wait(self):
        self.no_wait_threads.append(threading.get_ident())
        return None

    def wait(self):
        self.wait_threads.append(threading.get_ident())
        return None

    def send_game_message(self, *, message):
        self.sent_messages.append(message)
        return None


def test_order_generation_keeps_loop_responsive_and_marshals_requests():
    async def scenario() -> None:
        loop = asyncio.get_running_loop()
        owner_thread = threading.get_ident()
        order_sent = asyncio.Event()
        tick = asyncio.Event()
        release_worker = threading.Event()
        worker_started = threading.Event()

        client = AlbertClient("FRANCE", "example.invalid", 8432)
        client._network_loop = loop
        client._client_event_lock = asyncio.Lock()
        game = _FakeNetworkGame(owner_thread, order_sent)
        client.game = game
        client.state.synchronize_from_game = lambda _game: None

        def generate() -> None:
            assert threading.get_ident() != owner_thread
            worker_started.set()
            client._schedule_set_orders(["A PAR H"])
            client._send_dm("GOF")
            assert release_worker.wait(timeout=1.0)

        client.generate_and_submit_orders = generate
        update = asyncio.create_task(
            client._run_game_update_async(game, "S1902M")
        )

        # This callback can only run while generation is blocked if the
        # networking event loop itself remains free.
        loop.call_later(0.01, tick.set)
        await asyncio.wait_for(tick.wait(), timeout=0.5)
        assert worker_started.is_set()
        await asyncio.wait_for(order_sent.wait(), timeout=0.5)

        release_worker.set()
        await asyncio.wait_for(update, timeout=0.5)
        assert game.set_orders_threads == [owner_thread]
        assert game.no_wait_threads == [owner_thread]

    asyncio.run(scenario())


def test_stale_queued_phase_does_not_generate_orders():
    async def scenario() -> None:
        client = AlbertClient("FRANCE", "example.invalid", 8432)
        client._network_loop = asyncio.get_running_loop()
        client._client_event_lock = asyncio.Lock()
        game = _FakeNetworkGame(threading.get_ident(), asyncio.Event())
        game.current_short_phase = "F1902M"
        client.state.synchronize_from_game = lambda _game: None
        generated = False

        def generate() -> None:
            nonlocal generated
            generated = True

        client.generate_and_submit_orders = generate
        await client._run_game_update_async(game, "S1902M")
        assert generated is False

    asyncio.run(scenario())


def test_not_gof_sets_server_wait_without_sending_press():
    async def scenario() -> None:
        loop = asyncio.get_running_loop()
        owner_thread = threading.get_ident()
        client = AlbertClient("FRANCE", "example.invalid", 8432)
        client._network_loop = loop
        game = _FakeNetworkGame(owner_thread, asyncio.Event())
        client.game = game
        client.state.sc_count[2] = 1

        # Exercise the production CancelPriorPress path from the scoring
        # worker, then give the owning loop one turn to run the marshalled
        # server-control callback.
        await asyncio.to_thread(
            _senders_mod.cancel_prior_press,
            client.state,
            2,
            client._send_dm,
        )
        await asyncio.sleep(0)

        assert client.state.g_cancel_press_sent == 1
        assert game.wait_threads == [owner_thread]
        assert game.no_wait_threads == []
        assert game.sent_messages == []

    asyncio.run(scenario())


def test_press_arriving_during_generation_is_answered_before_no_wait():
    async def scenario() -> None:
        loop = asyncio.get_running_loop()
        events: list[str] = []
        worker_started = threading.Event()
        release_worker = threading.Event()

        client = AlbertClient("FRANCE", "example.invalid", 8432)
        client._network_loop = loop
        client._client_event_lock = asyncio.Lock()
        game = _FakeNetworkGame(threading.get_ident(), asyncio.Event())
        client.game = game
        client.current_phase = game.current_short_phase
        client.state.synchronize_from_game = lambda _game: None

        original_set_orders = game.set_orders
        original_no_wait = game.no_wait

        def set_orders(**kwargs):
            events.append("set_orders")
            return original_set_orders(**kwargs)

        def no_wait():
            events.append("no_wait")
            return original_no_wait()

        game.set_orders = set_orders
        game.no_wait = no_wait

        def generate() -> None:
            client._schedule_set_orders(["A PAR H"])
            client._send_dm("GOF")
            worker_started.set()
            assert release_worker.wait(timeout=1.0)

        client.generate_and_submit_orders = generate
        client.on_message_received = (
            lambda sender, body: events.append(f"ingest:{sender}:{body}"))
        client._respond_to_pending_press_entries = (
            lambda: events.append("respond") or 1)

        update = asyncio.create_task(
            client._run_game_update_async(game, "S1902M")
        )
        assert await asyncio.to_thread(worker_started.wait, 1.0)

        # NetworkGame stores the notification in its message history while the
        # worker is still scoring.  The final lifecycle drain must consume it
        # before the deferred GOF calls no_wait().
        game.messages = {
            1: SimpleNamespace(
                time_sent=123,
                sender="ENGLAND",
                recipient="FRANCE",
                message="PRP ( PCE ( ENG FRA ) )",
            )
        }
        release_worker.set()
        await asyncio.wait_for(update, timeout=1.0)

        assert events.index(
            "ingest:ENGLAND:PRP ( PCE ( ENG FRA ) )"
        ) < events.index("respond") < events.index("no_wait")
        assert game.no_wait_threads == [threading.get_ident()]

    asyncio.run(scenario())


def test_notification_copy_is_not_reparsed_after_history_drain():
    async def scenario() -> None:
        client = AlbertClient("FRANCE", "example.invalid", 8432)
        client._network_loop = asyncio.get_running_loop()
        client._client_event_lock = asyncio.Lock()
        observed: list[tuple[str, str]] = []
        responses: list[str] = []
        client.on_message_received = (
            lambda sender, body: observed.append((sender, body)))
        client._respond_to_pending_press_entries = (
            lambda: responses.append("respond") or 0)

        message = SimpleNamespace(
            time_sent=456,
            sender="GERMANY",
            recipient="FRANCE",
            message="PRP ( PCE ( GER FRA ) )",
        )
        game = SimpleNamespace(messages={1: message})
        assert client._drain_incoming_press(game) == 1
        await client._run_message_async(
            message.sender,
            message.message,
            client._message_identity(message),
        )

        assert observed == [("GERMANY", "PRP ( PCE ( GER FRA ) )")]
        assert responses == []

    asyncio.run(scenario())


def test_response_only_pass_deduplicates_two_registration_records():
    client = AlbertClient("FRANCE", "example.invalid", 8432)
    client.current_phase = "S1902M"
    client.game = SimpleNamespace(current_short_phase="S1902M")
    entry = {
        "received_flag": True,
        "type_flag": 0,
        "from_power_tok": 0x4101,
        "sublist1": [0x4101],
        "sublist2": [0x4102],
        "sublist3": ["PCE", "(", "ENG", "FRA", ")"],
        "sched_time": 123,
    }
    duplicate = dict(entry, watermark=0)
    client.state.g_broadcast_list[:] = [entry, duplicate]
    calls: list[str] = []

    with (
        patch.object(
            _communications_mod,
            "evaluate_press",
            side_effect=lambda _state, _entry: calls.append("evaluate") or 0x481C,
        ),
        patch.object(
            _communications_mod,
            "receive_proposal",
            side_effect=lambda *_args, **_kwargs: calls.append("receive"),
        ),
        patch.object(
            _communications_mod,
            "respond",
            side_effect=lambda *_args, **_kwargs: calls.append("respond"),
        ),
        patch.object(
            _press_mod,
            "_evaluate_order_proposals_and_send_gof",
            side_effect=lambda *_args, **_kwargs: calls.append("gof_eval"),
        ),
        patch.object(_press_mod, "dispatch_scheduled_press"),
    ):
        assert client._respond_to_pending_press_entries() == 1
        assert client._respond_to_pending_press_entries() == 0

    assert calls == ["evaluate", "receive", "respond", "gof_eval"]


def test_serialized_message_path_emits_directed_yes_for_valid_prp():
    async def scenario() -> None:
        client = AlbertClient("FRANCE", "example.invalid", 8432)
        client._network_loop = asyncio.get_running_loop()
        client._client_event_lock = asyncio.Lock()
        client.current_phase = "S1902M"
        client.game = SimpleNamespace(current_short_phase="S1902M")
        client.state.albert_power_idx = 2
        client.state.g_season = "SPR"
        client.state.g_year = 1902
        client.state.g_press_instant = 1
        client.state.g_turn_start_time = time.time()
        sent: list[object] = []
        client._send_dm = sent.append

        body = "PRP ( PCE ( ENG FRA ) )"
        await client._run_message_async(
            "ENGLAND",
            body,
            (789, "ENGLAND", "FRANCE", body),
        )

        assert sent == [{
            "message": "YES ( PRP ( PCE ( ENG FRA ) ) )",
            "recipient": "ENGLAND",
        }]

    asyncio.run(scenario())
