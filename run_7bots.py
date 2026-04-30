#!/usr/bin/env python3
"""Launch 7 no-press Pybert bots in a single game on a remote server.

Usage:
    cd ~/Downloads/work/Pybert
    uv run run_7bots.py --host diplomacy-api.feng-gu.com --port 443 --deadline 0
"""
from __future__ import annotations

import argparse
import asyncio
import json
import logging
import os
import sys
from pathlib import Path

# ── Make Pybert importable as a package ─────────────────────────────────
# When invoked via `uv run run_7bots.py`, Python treats this file as a
# top-level script.  We need the *parent* of Pybert/ on sys.path so that
# `import Pybert.bot.client` (and all internal relative imports like
# `from ..state`) resolve correctly.
_THIS_DIR = os.path.dirname(os.path.abspath(__file__))
_PARENT = os.path.dirname(_THIS_DIR)
_PKG = os.path.basename(_THIS_DIR)  # "Pybert"
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)

# Force the package to be imported so relative imports inside it work.
import importlib
_pkg_mod = importlib.import_module(_PKG)

import diplomacy.client.connection as _conn_mod
from diplomacy.client.connection import Connection

POWERS = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]

GAMES_DIR = Path(__file__).resolve().parent / "games"

logging.basicConfig(
    level=logging.WARNING,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
)
# Enable scoring debug output for Germany diagnostics
logging.getLogger("pybert.scoring_dbg").setLevel(logging.DEBUG)
# Keep SUB order output and DIAG visible (package name is "Pybert")
logging.getLogger("Pybert.bot.client._press").setLevel(logging.INFO)
logging.getLogger("Pybert.bot.client._orders").setLevel(logging.INFO)
logging.getLogger("Pybert.bot.client._lifecycle").setLevel(logging.INFO)
log = logging.getLogger("run_7bots")
log.setLevel(logging.INFO)

# ── File handler: capture ALL debug output to games/debug.log ──────────
GAMES_DIR.mkdir(parents=True, exist_ok=True)
_log_path = GAMES_DIR / "debug.log"
if _log_path.exists():
    _log_path.unlink()
_fh = logging.FileHandler(_log_path, mode="w", encoding="utf-8")
_fh.setLevel(logging.DEBUG)
_fh.setFormatter(logging.Formatter("%(asctime)s [%(levelname)s] %(name)s: %(message)s"))
logging.getLogger().addHandler(_fh)  # attach to root so it captures everything


async def _connect_ssl(hostname: str, port: int) -> Connection:
    """Like diplomacy.client.connection.connect, but with use_ssl=True."""
    conn = Connection(hostname, port, use_ssl=True)
    await conn._connect("Connecting (SSL) …")
    return conn


def _patch_connect_for_ssl():
    """Monkey-patch diplomacy's connect() so every caller (including
    AlbertClient._lifecycle) transparently uses WSS."""
    async def connect_with_ssl(hostname, port):
        conn = Connection(hostname, port, use_ssl=True)
        await conn._connect("Connecting (SSL) …")
        return conn

    _conn_mod.connect = connect_with_ssl  # type: ignore[assignment]

    # _lifecycle.py already did `from diplomacy.client.connection import connect`
    # at module level, so we must also patch its local binding.
    try:
        _lc = importlib.import_module(f"{_PKG}.bot.client._lifecycle")
        _lc.connect = connect_with_ssl  # type: ignore[assignment]
        log.info("Patched _lifecycle.connect for SSL.")
    except Exception as exc:
        log.warning("Could not patch _lifecycle.connect: %s", exc)


def _mark(msg: str) -> None:
    """Print a watcher-state marker that bypasses logging so it survives the
    scoring_dbg flood in debug.log and the WARNING-only stderr handler."""
    print(f"[run_7bots] {msg}", file=sys.stderr, flush=True)


async def _pause_and_save(game, game_id: str, pause_phase: str) -> None:
    """Pause the running game on the server and dump its saved state to games/."""
    _mark(f"Reached {pause_phase} — pausing game on server")
    try:
        await game.pause()
        _mark(f"Game {game_id} paused.")
    except Exception as exc:
        log.exception("pause() failed: %s", exc)

    try:
        saved = await game.save()
    except Exception as exc:
        log.exception("save() failed: %s", exc)
        return

    GAMES_DIR.mkdir(parents=True, exist_ok=True)
    out_path = GAMES_DIR / f"{game_id}_{pause_phase}.json"
    out_path.write_text(json.dumps(saved, indent=2, default=str))
    _mark(f"Saved game state to {out_path}")

    # Flush debug log and report path
    for h in logging.getLogger().handlers:
        h.flush()
    log_file = GAMES_DIR / "debug.log"
    if log_file.exists():
        _mark(f"Debug log saved to {log_file} ({log_file.stat().st_size} bytes)")


async def main(host: str, port: int, deadline: int, pause_phase: str) -> None:
    use_ssl = port == 443
    if use_ssl:
        _patch_connect_for_ssl()

    # ── 1. Create game via an admin/observer connection ─────────────────
    if use_ssl:
        connection = await _connect_ssl(host, port)
    else:
        from diplomacy.client.connection import connect
        connection = await connect(host, port)

    admin_channel = await connection.authenticate(
        username="admin_observer", password="password"
    )

    game = await admin_channel.create_game(
        n_controls=7,
        deadline=deadline,
        rules=["NO_PRESS", "POWER_CHOICE"],
    )
    game_id = game.game_id
    log.info("Created game %s  (deadline=%ds, NO_PRESS)", game_id, deadline)

    # ── 2. Watch the admin/omniscient game for the pause phase ──────────
    # Belt-and-suspenders: register the GameProcessed callback AND poll
    # current_short_phase. Notifications can be missed when the event loop
    # is blocked by a bot's Monte Carlo, and a poll catches it on the next
    # tick regardless.
    pause_event = asyncio.Event()
    POLL_SECONDS = 5.0

    def _on_phase_processed(g, _notification):
        cur = getattr(g, "current_short_phase", "") or ""
        if cur == pause_phase:
            pause_event.set()

    if hasattr(game, "add_on_game_processed"):
        game.add_on_game_processed(_on_phase_processed)

    async def _phase_watcher() -> None:
        last_seen = ""
        while not pause_event.is_set():
            cur = (getattr(game, "current_short_phase", "") or "")
            if cur != last_seen:
                _mark(f"phase poll: current={cur!r} target={pause_phase!r}")
                last_seen = cur
            if cur == pause_phase:
                pause_event.set()
                break
            try:
                await asyncio.wait_for(pause_event.wait(), timeout=POLL_SECONDS)
            except asyncio.TimeoutError:
                pass
        await _pause_and_save(game, game_id, pause_phase)

    watcher_task = asyncio.create_task(_phase_watcher(), name="pause_watcher")

    # ── 3. Import AlbertClient via absolute package path ────────────────
    _client_mod = importlib.import_module(f"{_PKG}.bot.client")
    AlbertClient = _client_mod.AlbertClient

    clients: list = []
    tasks: list[asyncio.Task] = []
    for power in POWERS:
        client = AlbertClient(
            power_name=power,
            host=host,
            port=port,
            username=f"Albert_{power}",
            password="password",
            game_id=game_id,
        )
        client.state.g_minimal_press_mode = 1  # no press
        clients.append(client)
        tasks.append(asyncio.create_task(client.play(), name=power))
        log.info("Queued %s", power)

    _mark(f"All 7 bots queued — will pause+save at {pause_phase}")

    # Wait for either the watcher (pause+save complete) or any bot to finish.
    # If any bot finishes/crashes early at deadline=0 the game will stall,
    # so we treat any bot completion before the watcher fires as fatal and
    # tear everything down — no point waiting for a stalled game.
    done, _pending = await asyncio.wait(
        [watcher_task, *tasks],
        return_when=asyncio.FIRST_COMPLETED,
    )

    if watcher_task in done:
        _mark("pause+save complete — cancelling bot tasks")
    else:
        for power, t in zip(POWERS, tasks):
            if t in done:
                exc = t.exception() if not t.cancelled() else None
                _mark(f"bot {power} exited before pause phase (exc={exc!r}); aborting")
        if not watcher_task.done():
            watcher_task.cancel()

    for t in tasks:
        if not t.done():
            t.cancel()

    # Bound the wait so a bot stuck in synchronous Monte Carlo can't pin us.
    try:
        results = await asyncio.wait_for(
            asyncio.gather(*tasks, return_exceptions=True),
            timeout=120.0,
        )
        for power, result in zip(POWERS, results):
            if isinstance(result, asyncio.CancelledError):
                continue
            if isinstance(result, Exception):
                log.error("%s crashed: %s", power, result)
    except asyncio.TimeoutError:
        _mark("bot cancellation timed out after 120s — forcing exit")

    # Close all connections so asyncio.run can actually exit.
    for c in clients:
        conn = getattr(c, "connection", None)
        if conn is not None:
            try:
                conn.close()
            except Exception:
                pass
    try:
        connection.close()
    except Exception:
        pass

    _mark(f"Game {game_id} complete.")


if __name__ == "__main__":
    p = argparse.ArgumentParser()
    p.add_argument("--host", default="diplomacy-api.feng-gu.com")
    p.add_argument("--port", type=int, default=443)
    p.add_argument("--deadline", type=int, default=0,
                   help="Seconds per phase (0 = wait for all orders). "
                        "Must be 0 when running 7 bots in one process, "
                        "since each bot blocks the event loop during MC.")
    p.add_argument("--pause-phase", default="W1902A",
                   help="Short phase name (e.g. 'W1902A') at which to pause "
                        "the game and dump its state to games/. Default: W1902A.")
    args = p.parse_args()
    asyncio.run(main(args.host, args.port, args.deadline, args.pause_phase))
