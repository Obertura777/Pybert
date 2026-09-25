#!/usr/bin/env python3
"""Sample Pybert order sets for all seven powers from one offline process.

This is the Albert/Pybert move recommender for the collusion experiment
(``diplomacy/steganography.md`` Section 3).  It needs no server and no
per-power bot connections.  For each active power it builds a fresh
offline ``AlbertClient`` on a copy of the game, seeds the process-global
CRT stream, and runs the standard board-only order generation.

Recommendations are board-only and role-blind:

* The input game is copied through the saved-game format with every message
  removed, so press never reaches the bot.  Pybert still reads
  ``order_history`` and ``result_history`` (the last movement and retreat
  phase), as it does in live play.
* Each sample's seed comes from ``(namespace, phase, power, "albert",
  sample index)`` only.  The same inputs always give the same orders.
* Samples are deduplicated within the power in sample order.  Duplicates
  are recorded, not dropped.

Python use (from the experiment runner)::

    from Pybert.sample_moves import sample_all_powers
    rec = sample_all_powers(game, k=3, namespace="block3/ep5")
    rec["powers"]["FRANCE"]["unique"]      # list[list[str]]

CLI::

    uv run sample_moves.py --new-game -k 3 --namespace demo
    uv run sample_moves.py --game saved.json --phase F1903M -k 3 --workers 7 \\
        --out recs.json
"""
from __future__ import annotations

import argparse
import copy
import hashlib
import json
import logging
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

# Make the Pybert package importable when this file runs as a script.
_THIS = Path(__file__).resolve().parent
if str(_THIS.parent) not in sys.path:
    sys.path.insert(0, str(_THIS.parent))

from diplomacy import Game
from diplomacy.utils.export import from_saved_game_format, to_saved_game_format

POWERS = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]
RECOMMENDER = "albert"

log = logging.getLogger("sample_moves")


# ── Seeds ───────────────────────────────────────────────────────────────

def derive_seed(namespace: str, phase: str, power: str, index: int) -> int:
    """Return the 32-bit CRT seed for one sample.

    Roles are deliberately not an input: the seed depends only on the
    episode namespace, phase, power, recommender, and sample index.
    """
    key = f"{namespace}|{phase}|{power}|{RECOMMENDER}|{index}".encode()
    return int.from_bytes(hashlib.sha256(key).digest()[:4], "big")


# ── Game copies ─────────────────────────────────────────────────────────

def board_only_saved_game(game: Game) -> dict:
    """Return ``game`` in saved-game format with all press removed."""
    saved = to_saved_game_format(game)
    for phase in saved.get("phases", []):
        phase["messages"] = []
    return saved


def load_saved_game(saved: dict, phase: str | None = None) -> Game:
    """Rebuild a Game from saved-game data, optionally cut at ``phase``.

    With ``phase`` the game is truncated so ``phase`` is the current,
    unprocessed phase: its board is kept and its orders are discarded.
    """
    saved = copy.deepcopy(saved)
    phases = saved.get("phases", [])
    if phase is not None:
        names = [p.get("name") for p in phases]
        if phase not in names:
            raise ValueError(f"phase {phase!r} not in game (have {names})")
        phases = phases[: names.index(phase) + 1]
        phases[-1]["orders"] = {}
        phases[-1]["results"] = {}
    for p in phases:
        p["messages"] = []
    saved["phases"] = phases
    # Extra keys written by some servers (annotated_messages, stances, ...)
    # are not part of the saved-game format.
    saved.pop("annotated_messages", None)
    return from_saved_game_format(saved)


def _orderable(game: Game, power: str) -> bool:
    """Whether ``power`` has anything to order in the current phase."""
    return bool(game.get_orderable_locations(power))


# ── One sample ──────────────────────────────────────────────────────────

def _quiet_logging() -> None:
    logging.getLogger("Pybert").setLevel(logging.WARNING)


def _run_one(saved: dict, power: str, seed: int,
             proposal_round_cap: int | None) -> list[str]:
    """Generate one order set for ``power`` on a fresh copy of the game."""
    from Pybert import rng
    from Pybert.bot.client import AlbertClient

    _quiet_logging()
    game = from_saved_game_format(copy.deepcopy(saved))
    phase = game.get_current_phase()

    rng.seed(seed)
    client = AlbertClient(power_name=power, host="offline", port=0)
    client.game = game
    client.current_phase = phase
    client.state.g_minimal_press_mode = 1          # no-press bot
    if proposal_round_cap is not None:
        # Fast mode only: fewer BuildAndSendSUB rounds than Albert's 30
        # changes the final ranking, so it is not the standard bot.
        client.state.g_press_proposals_cap = int(proposal_round_cap)
    client._send_dm = lambda _msg: None            # no outbound traffic
    client.state.synchronize_from_game(game)
    client.generate_and_submit_orders()

    if phase.endswith("M"):
        orders = list(getattr(client.state, "g_submitted_orders", []) or [])
    else:
        # Retreat and adjustment orders go straight to game.set_orders.
        orders = list(game.get_orders(power))
    return sorted(" ".join(o.upper().split()) for o in orders)


def _job(args: tuple) -> tuple[str, int, int, list[str] | None, str | None, float]:
    saved, power, index, seed, cap = args
    start = time.monotonic()
    try:
        orders = _run_one(saved, power, seed, cap)
        err = None
    except Exception as exc:  # recorded, never silently replaced
        orders, err = None, f"{type(exc).__name__}: {exc}"
    return power, index, seed, orders, err, time.monotonic() - start


# ── All powers ──────────────────────────────────────────────────────────

def pybert_build() -> str:
    """Git commit of this Pybert checkout, with ``-dirty`` if modified."""
    try:
        sha = subprocess.run(["git", "rev-parse", "HEAD"], cwd=_THIS,
                             capture_output=True, text=True, check=True).stdout.strip()
        dirty = subprocess.run(["git", "status", "--porcelain"], cwd=_THIS,
                               capture_output=True, text=True, check=True).stdout.strip()
        return sha + ("-dirty" if dirty else "")
    except Exception:
        return "unknown"


def sample_all_powers(game: Game | dict, k: int = 3, namespace: str = "default",
                      *, powers: list[str] | None = None, phase: str | None = None,
                      workers: int = 1, proposal_round_cap: int | None = None) -> dict:
    """Sample ``k`` Pybert order sets for every power with orders to give.

    ``game`` is a ``diplomacy.Game`` or saved-game dict.  ``phase`` (dict
    input only) cuts the saved game at that phase.  Returns a JSON-ready
    record::

        {"recommender": "albert", "phase": ..., "namespace": ..., "k": ...,
         "powers": {POWER: {"samples": [{"index", "seed", "orders",
                                          "duplicate_of", "error", "seconds"}],
                            "unique": [[order, ...], ...],
                            "duplicates": int}}}

    Powers with nothing to order get empty ``samples`` and ``unique``.
    A failed sample has ``orders: null`` and an ``error`` string; it is
    excluded from ``unique``.
    """
    if isinstance(game, Game):
        if phase is not None:
            raise ValueError("phase= applies only to saved-game input")
        saved = board_only_saved_game(game)
        live = load_saved_game(saved)
    else:
        live = load_saved_game(game, phase)
        saved = board_only_saved_game(live)
    current = live.get_current_phase()
    wanted = powers or POWERS

    jobs = []
    record = {
        "recommender": RECOMMENDER,
        "build": pybert_build(),
        "phase": current,
        "namespace": namespace,
        "k": k,
        "proposal_round_cap": proposal_round_cap,
        "powers": {},
    }
    for power in wanted:
        record["powers"][power] = {"samples": [], "unique": [], "duplicates": 0}
        if not _orderable(live, power):
            continue
        for i in range(k):
            jobs.append((saved, power, i, derive_seed(namespace, current, power, i),
                         proposal_round_cap))

    if workers > 1 and len(jobs) > 1:
        with ProcessPoolExecutor(max_workers=workers) as pool:
            results = list(pool.map(_job, jobs))
    else:
        results = [_job(j) for j in jobs]

    for power, index, seed, orders, err, secs in sorted(results, key=lambda r: (POWERS.index(r[0]), r[1])):
        entry = record["powers"][power]
        sample = {"index": index, "seed": seed, "orders": orders,
                  "duplicate_of": None, "error": err, "seconds": round(secs, 2)}
        if orders is not None:
            key = frozenset(orders)
            prior = [s["index"] for s in entry["samples"]
                     if s["orders"] is not None and frozenset(s["orders"]) == key]
            if prior:
                sample["duplicate_of"] = prior[0]
                entry["duplicates"] += 1
            else:
                entry["unique"].append(orders)
        else:
            log.warning("%s %s sample %d failed: %s", current, power, index, err)
        entry["samples"].append(sample)
    return record


def sample(game: Game, power: str, k: int, namespace: str, **kw) -> list[list[str]]:
    """Recommender interface: deduplicated order sets for one power."""
    rec = sample_all_powers(game, k, namespace, powers=[power], **kw)
    return rec["powers"][power]["unique"]


# ── CLI ─────────────────────────────────────────────────────────────────

def main(argv: list[str] | None = None) -> int:
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    src = p.add_mutually_exclusive_group(required=True)
    src.add_argument("--game", type=Path, help="Saved-game JSON (to_saved_game_format).")
    src.add_argument("--new-game", action="store_true", help="Use the S1901M start position.")
    p.add_argument("--phase", help="Cut the saved game at this phase (default: its last phase).")
    p.add_argument("-k", type=int, default=3, help="Samples per power (default 3).")
    p.add_argument("--namespace", default="default", help="Episode seed namespace.")
    p.add_argument("--powers", nargs="+", choices=POWERS, help="Restrict to these powers.")
    p.add_argument("--workers", type=int, default=1, help="Parallel processes (default 1).")
    p.add_argument("--proposal-rounds", type=int, default=None,
                   help="Fast mode: cap BuildAndSendSUB rounds (not the standard bot).")
    p.add_argument("--out", type=Path, help="Write JSON here (default: stdout).")
    args = p.parse_args(argv)

    logging.basicConfig(level=logging.WARNING, format="%(levelname)s %(name)s: %(message)s")
    _quiet_logging()

    if args.new_game:
        if args.phase:
            p.error("--phase needs --game")
        game_input: Game | dict = Game(map_name="standard")
    else:
        game_input = json.loads(args.game.read_text())

    rec = sample_all_powers(game_input, args.k, args.namespace, powers=args.powers,
                            phase=args.phase, workers=args.workers,
                            proposal_round_cap=args.proposal_rounds)
    text = json.dumps(rec, indent=2)
    if args.out:
        args.out.write_text(text + "\n")
    else:
        print(text)

    for power, entry in rec["powers"].items():
        ok = [s for s in entry["samples"] if s["orders"] is not None]
        print(f"{rec['phase']} {power:8s} samples={len(entry['samples'])} "
              f"unique={len(entry['unique'])} failed={len(entry['samples']) - len(ok)}",
              file=sys.stderr)
    failed = any(s["error"] for e in rec["powers"].values() for s in e["samples"])
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
