#!/usr/bin/env python3
"""Albert/Pybert move recommender for all seven powers from one connection.

One process joins a game as an omniscient observer.  At the start of every
phase that needs orders it samples ``k`` Pybert order sets for each active
power (``sample_moves.sample_all_powers``) and sends each power its unique
sets as private ``SUGGESTED_MOVE_FULL`` advice.  diplobench's
``collect_recommendations`` reads them as ``ALBERT-1..k``
(``diplomacy/steganography.md`` Section 3).

Advice body (one message per unique order set, in sample order)::

    {"recipient": "FRANCE", "advisor": "ALBERT",
     "payload": {"suggested_orders": [...]},
     "sample_index": 0, "num_samples": 3}

``num_samples`` is the number of unique sets sent to that power this phase,
so a seat can wait until all have arrived.  A power whose samples all
failed gets one message with empty orders and ``num_samples: 0``.  Seeds,
duplicates, and errors never go on the wire; they are appended to the
``--log`` JSONL file.

``--set-orders POWER`` also joins as POWER and submits its first sample as
the server orders.  That is the Albert control seat: run its diplobench
process with ``--role control --recommender ALBERT``.

Advice needs an omniscient token (an admin, or a user promoted to
omniscient for the game), and the server rejects every message in a
NO_PRESS game, so the no-press arm cannot receive advice this way.

Usage::

    uv run albert_advisor.py --host localhost --game-id demo_game -k 3 \\
        --workers 7 --set-orders ITALY --log demo_game_albert.jsonl
"""
from __future__ import annotations

import argparse
import asyncio
import json
import logging
import sys
from pathlib import Path

_THIS = Path(__file__).resolve().parent
if str(_THIS.parent) not in sys.path:
    sys.path.insert(0, str(_THIS.parent))

from diplomacy.client.connection import connect
from diplomacy.engine.message import GLOBAL, Message
from diplomacy.utils import strings
from diplomacy.utils.export import to_saved_game_format

from Pybert.sample_moves import POWERS, _quiet_logging, sample_all_powers

ADVISOR = "ALBERT"
SUGGESTED_MOVE_FULL = getattr(strings, "SUGGESTED_MOVE_FULL", "suggested_move_full")
OMNISCIENT_TYPE = strings.OMNISCIENT_TYPE

log = logging.getLogger("albert_advisor")


def advice_body(power: str, orders: list[str], index: int, count: int) -> str:
    return json.dumps({
        "recipient": power,
        "advisor": ADVISOR,
        "payload": {"suggested_orders": orders},
        "sample_index": index,
        "num_samples": count,
    })


def already_advised(game, phase: str) -> set[str]:
    """Powers that already have Albert advice for ``phase`` (after a restart)."""
    done = set()
    for msg in game.messages.values():
        if msg.phase != phase or msg.type != SUGGESTED_MOVE_FULL:
            continue
        try:
            body = json.loads(msg.message)
        except (TypeError, ValueError):
            continue
        if isinstance(body, dict) and str(body.get("advisor", "")).upper() == ADVISOR:
            done.add(body.get("recipient"))
    return done


async def send_advice(game, phase: str, power: str, unique: list[list[str]]) -> None:
    sets = unique or [[]]
    for index, orders in enumerate(sets):
        await game.send_game_message(message=Message(
            sender=OMNISCIENT_TYPE,
            recipient=GLOBAL,
            type=SUGGESTED_MOVE_FULL,
            phase=phase,
            message=advice_body(power, orders, index, len(unique)),
        ))


def is_over(game, last_year: int | None) -> bool:
    if game.is_game_completed or game.is_game_canceled:
        return True
    phase = game.get_current_phase()
    try:
        return last_year is not None and int(phase[1:5]) > last_year
    except ValueError:
        return False


async def run(args) -> None:
    connection = await connect(args.host, args.port, use_ssl=args.use_ssl)
    channel = await connection.authenticate(args.username, args.password)
    game = await channel.join_game(game_id=args.game_id)
    if game.role != OMNISCIENT_TYPE:
        raise SystemExit(f"{args.username} joined as {game.role}; advice needs an omniscient token.")

    control_games = {}
    for power in args.set_orders or []:
        user = args.order_username.format(power=power)
        ch = await connection.authenticate(user, args.order_password)
        control_games[power] = await ch.join_game(game_id=args.game_id, power_name=power)
        log.info("Joined as %s (%s) to set its orders.", power, user)

    namespace = args.namespace or args.game_id
    while game.is_game_forming:
        await asyncio.sleep(1)

    done_phase = None
    while not is_over(game, args.last_year):
        phase = game.get_current_phase()
        if phase == done_phase:
            await asyncio.sleep(1)
            continue

        advised = already_advised(game, phase)
        powers = [p for p in (args.powers or POWERS) if p not in advised]
        if not powers:
            done_phase = phase
            continue
        # Cut at the current phase: drops this phase's orders (visible to an
        # omniscient token) and all press before Pybert sees the board.
        saved = to_saved_game_format(game)
        rec = await asyncio.to_thread(
            sample_all_powers, saved, args.k, namespace, powers=powers, phase=phase,
            workers=args.workers, proposal_round_cap=args.proposal_rounds)

        if game.get_current_phase() != phase:
            log.warning("%s ended before sampling finished; advice not sent.", phase)
            rec["stale"] = True
        else:
            for power, entry in rec["powers"].items():
                if not entry["samples"]:
                    continue                      # nothing to order
                await send_advice(game, phase, power, entry["unique"])
                if power in control_games and entry["unique"]:
                    await control_games[power].set_orders(
                        power_name=power, orders=entry["unique"][0], wait=False)
                log.info("%s %s: %d unique of %d (%d failed)", phase, power,
                         len(entry["unique"]), len(entry["samples"]),
                         sum(s["error"] is not None for s in entry["samples"]))
        if args.log:
            with args.log.open("a") as f:
                f.write(json.dumps(rec) + "\n")
        done_phase = phase

    log.info("Game over at %s.", game.get_current_phase())


def main(argv: list[str] | None = None) -> int:
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("--host", default="localhost")
    p.add_argument("--port", type=int, default=8433)
    p.add_argument("--use-ssl", action="store_true")
    p.add_argument("--game-id", required=True)
    p.add_argument("--username", default="admin", help="Omniscient user (default admin).")
    p.add_argument("--password", default="password")
    p.add_argument("-k", type=int, default=3, help="Samples per power (default 3).")
    p.add_argument("--namespace", help="Episode seed namespace (default: game id).")
    p.add_argument("--powers", nargs="+", choices=POWERS, help="Advise only these powers.")
    p.add_argument("--workers", type=int, default=7, help="Sampling processes (default 7).")
    p.add_argument("--proposal-rounds", type=int, default=None,
                   help="Fast mode: cap BuildAndSendSUB rounds (not the standard bot).")
    p.add_argument("--set-orders", nargs="+", choices=POWERS, metavar="POWER",
                   help="Albert control seat(s): submit the first sample as server orders.")
    p.add_argument("--order-username", default="cicero_{power}",
                   help="User that controls a --set-orders power (default cicero_{power}, "
                        "the name diplobench authenticates with).")
    p.add_argument("--order-password", default="password")
    p.add_argument("--last-year", type=int, default=1908,
                   help="Stop after this year's adjustment (default 1908).")
    p.add_argument("--log", type=Path, help="Append each phase's full record (seeds, "
                                            "duplicates, errors) to this JSONL file.")
    args = p.parse_args(argv)

    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(name)s: %(message)s")
    _quiet_logging()
    asyncio.run(run(args))
    return 0


if __name__ == "__main__":
    sys.exit(main())
