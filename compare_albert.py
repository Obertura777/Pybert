"""Compare Pybert (Python rewrite) order generation against the C-coded Albert.

For each phase in `all_games_albert/`, the C bot's "what would Albert do given
this board state" orders are stored per power.  This script loads each phase
state from the matching `all_games/` JSON, runs the Python port for every
power, and compares the resulting orders against Albert's record.

Reports per-power match rate and per-game / global aggregates.

Usage::

    cd ~/Downloads/work/Pybert
    uv run compare_albert.py                       # all games, default seed
    uv run compare_albert.py --max-games 5         # smoke test
    uv run compare_albert.py --phase-types M       # movement only
    uv run compare_albert.py --game game_10.json   # single game
"""
from __future__ import annotations

import argparse
import json
import logging
import os
import random
import sys
import time
from collections import Counter, defaultdict
from pathlib import Path

# Make the Pybert package importable when running from the repo dir.
_THIS = Path(__file__).resolve().parent
_PARENT = _THIS.parent
if str(_PARENT) not in sys.path:
    sys.path.insert(0, str(_PARENT))

from diplomacy import Game

from Pybert.bot.client import AlbertClient


POWERS = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]


def _build_game(state_data: dict, phase_name: str) -> Game:
    """Construct an offline diplomacy.Game in the given board state."""
    g = Game(map_name="standard", rules=["NO_PRESS"])
    g.set_current_phase(phase_name)
    g.clear_units()
    g.clear_centers()
    for power, units in state_data["units"].items():
        g.set_units(power, list(units))
    for power, centers in state_data["centers"].items():
        g.set_centers(power, list(centers))
    # Some phases (R / A) need retreat info on the game.
    retreats = state_data.get("retreats") or {}
    for power, retreat_map in retreats.items():
        if not retreat_map:
            continue
        try:
            pwr = g.get_power(power)
            pwr.retreats = dict(retreat_map)
        except Exception:
            pass
    return g


def _capture_orders_for_power(state_data: dict, phase_name: str,
                              power: str, seed: int) -> list[str] | None:
    """Run Pybert as `power` on the given state, return submitted orders.

    Returns None on bot failure.  An empty list is a valid result (e.g.
    adjustment phase with nothing to do).
    """
    random.seed(seed)
    g = _build_game(state_data, phase_name)
    client = AlbertClient(power_name=power, host="x", port=0)
    client.game = g
    client.current_phase = g.get_current_phase()
    # Force NO_PRESS mode so the bot doesn't try to send DAIDE messages.
    client.state.g_minimal_press_mode = 1

    try:
        client.state.synchronize_from_game(g)
        client.generate_and_submit_orders()
    except Exception:
        return None

    submitted = list(getattr(client.state, "g_submitted_orders", []) or [])
    # Adjustment phase: orders may have been pushed via _submit_adjustment_orders;
    # those go directly to game.set_orders.  Recover them from the game object.
    if phase_name.endswith("A"):
        try:
            submitted = list(g.get_orders(power))
        except Exception:
            pass
    # Retreat phase: orders submitted via _format_retreat_commands.
    if phase_name.endswith("R"):
        try:
            submitted = list(g.get_orders(power))
        except Exception:
            pass
    return submitted


def _norm_order(o: str) -> str:
    """Normalize an order string for set comparison (collapse whitespace)."""
    return " ".join(o.upper().split())


def _order_unit(o: str) -> str | None:
    """Extract the source unit ('A PAR', 'F STP/SC', ...) from an order."""
    parts = o.upper().split()
    if len(parts) < 2:
        return None
    return f"{parts[0]} {parts[1]}"


def _compare_orders(albert: list[str], pybert: list[str]) -> dict:
    """Return diff metrics for one (phase, power) pair."""
    a_norm = {_norm_order(o) for o in albert}
    p_norm = {_norm_order(o) for o in pybert}

    # Per-unit alignment: same source unit, same full order?
    a_by_unit: dict[str, str] = {}
    for o in albert:
        u = _order_unit(o)
        if u is not None:
            a_by_unit[u] = _norm_order(o)
    p_by_unit: dict[str, str] = {}
    for o in pybert:
        u = _order_unit(o)
        if u is not None:
            p_by_unit[u] = _norm_order(o)

    units = set(a_by_unit) | set(p_by_unit)
    matches = sum(1 for u in units if a_by_unit.get(u) == p_by_unit.get(u))
    return {
        "albert_count": len(albert),
        "pybert_count": len(pybert),
        "exact_set_match": a_norm == p_norm,
        "unit_match": matches,
        "unit_total": len(units),
        "albert_only": sorted(a_norm - p_norm),
        "pybert_only": sorted(p_norm - a_norm),
    }


def _phase_state(game_full: dict, phase_name: str) -> dict | None:
    for ph in game_full.get("phases", []):
        if ph.get("name") == phase_name:
            return ph.get("state")
    return None


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--all-games", default="all_games",
                        help="Directory of full game JSONs.")
    parser.add_argument("--albert-dir", default="all_games_albert",
                        help="Directory of Albert reference orders.")
    parser.add_argument("--game", default=None,
                        help="Restrict to one game JSON filename.")
    parser.add_argument("--max-games", type=int, default=None,
                        help="Stop after N games.")
    parser.add_argument("--phase-types", default="M",
                        help="Phase suffixes to compare (e.g. 'M', 'MR', 'MAR'). "
                             "Default 'M' (movement only).")
    parser.add_argument("--seed", type=int, default=42,
                        help="Random seed (passed to random.seed before each run).")
    parser.add_argument("--verbose", action="store_true",
                        help="Print each phase/power result.")
    parser.add_argument("--out", default=None,
                        help="Optional path for per-(game,phase,power) JSON dump.")
    args = parser.parse_args()

    # Silence the bot's noisy loggers; we only care about returned orders.
    logging.basicConfig(level=logging.CRITICAL)

    albert_dir = Path(args.albert_dir)
    games_dir = Path(args.all_games)
    albert_files = sorted(albert_dir.glob("game_*.json"))
    if args.game:
        albert_files = [albert_dir / args.game]
    if args.max_games is not None:
        albert_files = albert_files[: args.max_games]

    phase_suffixes = set(args.phase_types.upper())

    # Aggregates
    n_games = 0
    n_phase_powers = 0
    n_exact_match = 0
    n_pybert_failed = 0
    unit_match_total = 0
    unit_total = 0
    by_phase_type: dict[str, dict] = defaultdict(
        lambda: {"phase_powers": 0, "exact": 0, "unit_match": 0, "unit_total": 0,
                 "failed": 0}
    )
    per_record: list[dict] = []

    t0 = time.time()
    for albert_path in albert_files:
        full_path = games_dir / albert_path.name
        if not full_path.exists():
            print(f"[skip] no full-game JSON for {albert_path.name}", file=sys.stderr)
            continue
        try:
            albert_game = json.loads(albert_path.read_text())
            full_game = json.loads(full_path.read_text())
        except Exception as exc:
            print(f"[skip] {albert_path.name} JSON load failed: {exc}", file=sys.stderr)
            continue
        n_games += 1
        if args.verbose:
            print(f"\n=== {albert_path.name} ===")

        for phase_name, albert_orders_per_power in albert_game.items():
            if not phase_name or phase_name == "COMPLETED":
                continue
            if phase_name[-1] not in phase_suffixes:
                continue
            state = _phase_state(full_game, phase_name)
            if state is None:
                if args.verbose:
                    print(f"  [{phase_name}] no state in full game; skip")
                continue
            if not isinstance(albert_orders_per_power, dict):
                continue

            for power, albert_orders in albert_orders_per_power.items():
                if power not in POWERS:
                    continue
                albert_orders = list(albert_orders or [])
                pybert_orders = _capture_orders_for_power(
                    state, phase_name, power, seed=args.seed)
                if pybert_orders is None:
                    n_pybert_failed += 1
                    by_phase_type[phase_name[-1]]["failed"] += 1
                    if args.verbose:
                        print(f"  [{phase_name}] {power}: PYBERT FAILED")
                    continue
                diff = _compare_orders(albert_orders, pybert_orders)
                n_phase_powers += 1
                by_phase_type[phase_name[-1]]["phase_powers"] += 1
                if diff["exact_set_match"]:
                    n_exact_match += 1
                    by_phase_type[phase_name[-1]]["exact"] += 1
                unit_match_total += diff["unit_match"]
                unit_total += diff["unit_total"]
                by_phase_type[phase_name[-1]]["unit_match"] += diff["unit_match"]
                by_phase_type[phase_name[-1]]["unit_total"] += diff["unit_total"]

                if args.verbose:
                    flag = "✓" if diff["exact_set_match"] else "✗"
                    print(f"  [{phase_name}] {power}: {flag} "
                          f"unit_match={diff['unit_match']}/{diff['unit_total']}"
                          f" albert={diff['albert_count']} pybert={diff['pybert_count']}")
                    if not diff["exact_set_match"]:
                        for o in diff["albert_only"]:
                            print(f"       albert-only: {o}")
                        for o in diff["pybert_only"]:
                            print(f"       pybert-only: {o}")

                if args.out:
                    per_record.append({
                        "game": albert_path.name,
                        "phase": phase_name,
                        "power": power,
                        "albert": albert_orders,
                        "pybert": pybert_orders,
                        **{k: v for k, v in diff.items()
                           if k not in ("albert_only", "pybert_only")},
                    })

    dt = time.time() - t0

    # ── Summary ───────────────────────────────────────────────────────────
    print()
    print("=" * 60)
    print(f"Compared {n_games} games, {n_phase_powers} (phase, power) pairs"
          f" in {dt:.1f}s")
    if n_pybert_failed:
        print(f"  Pybert errors: {n_pybert_failed}")
    if n_phase_powers:
        print(f"  Exact-set match: {n_exact_match}/{n_phase_powers}"
              f" = {100*n_exact_match/n_phase_powers:.1f}%")
    if unit_total:
        print(f"  Per-unit match: {unit_match_total}/{unit_total}"
              f" = {100*unit_match_total/unit_total:.1f}%")
    print()
    print("Breakdown by phase type:")
    for suf in sorted(by_phase_type):
        s = by_phase_type[suf]
        if not s["phase_powers"]:
            continue
        ex_pct = 100 * s["exact"] / s["phase_powers"]
        un_pct = 100 * s["unit_match"] / s["unit_total"] if s["unit_total"] else 0.0
        print(f"  {suf}: {s['phase_powers']} pairs"
              f", exact-set {s['exact']}/{s['phase_powers']} ({ex_pct:.1f}%)"
              f", per-unit {s['unit_match']}/{s['unit_total']} ({un_pct:.1f}%)"
              f", failed {s['failed']}")

    if args.out:
        Path(args.out).write_text(json.dumps(per_record, indent=2))
        print(f"\nPer-record dump written to {args.out}")


if __name__ == "__main__":
    main()
