"""Albert bot — CLI entry point.

Usage examples::

    # Minimal: connect to localhost, auto-pick first available game
    python -m albert.main --power FRANCE

    # Full: specify server, game, and press options
    python -m albert.main \\
        --host 192.168.1.10 --port 8433 \\
        --power ENGLAND \\
        --game-id game_123 \\
        --username MyBot --password s3cret \\
        --minimal-press \\
        --log-level DEBUG
"""

from __future__ import annotations

import argparse
import asyncio
import logging
import sys

_VALID_POWERS = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]


def _build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="albert",
        description="Albert Diplomacy bot — connects to a diplomacy server and plays a game.",
    )

    # ── Server connection ────────────────────────────────────────────────
    p.add_argument(
        "--host",
        default="localhost",
        help="Server hostname or IP address (default: localhost).",
    )
    p.add_argument(
        "--port",
        type=int,
        default=8432,
        help="Server port (default: 8432).",
    )

    # ── Game selection ───────────────────────────────────────────────────
    p.add_argument(
        "--power",
        required=True,
        choices=_VALID_POWERS,
        help="Power to play as (e.g. FRANCE, ENGLAND).",
    )
    p.add_argument(
        "--game-id",
        default=None,
        help="Game ID to join. If omitted, the bot joins the first available game.",
    )

    # ── Authentication ───────────────────────────────────────────────────
    p.add_argument(
        "--username",
        default=None,
        help="Account username. Defaults to 'Albert_<POWER>' if not specified.",
    )
    p.add_argument(
        "--password",
        default="password",
        help="Account password (default: 'password').",
    )

    # ── Press / communication options ────────────────────────────────────
    p.add_argument(
        "--press",
        choices=["none", "max"],
        default="max",
        help=(
            "Press (diplomacy messaging) mode. "
            "'none' disables all press (equivalent to C binary's -G flag). "
            "'max' enables full press including PCE, ALY, VSS, DMZ, XDO, AND, ORR "
            "(default: max)."
        ),
    )

    # ── Logging ──────────────────────────────────────────────────────────
    p.add_argument(
        "--log-level",
        default="INFO",
        choices=["DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"],
        help="Logging verbosity (default: INFO).",
    )

    return p


def main(argv: list[str] | None = None) -> None:
    args = _build_parser().parse_args(argv)

    logging.basicConfig(
        level=getattr(logging, args.log_level),
        format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    )

    # Lazy import so --help is fast and doesn't require numpy/diplomacy.
    from bot.client import AlbertClient

    client = AlbertClient(
        power_name=args.power,
        host=args.host,
        port=args.port,
        username=args.username,
        password=args.password,
        game_id=args.game_id,
    )

    # Apply press option before the game loop starts.
    if args.press == "none":
        client.state.g_minimal_press_mode = 1

    asyncio.run(client.play())


if __name__ == "__main__":
    main()
