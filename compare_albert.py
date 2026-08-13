"""Compare Pybert (Python rewrite) order generation against the C-coded Albert.

For each phase in `all_games_albert/`, the C bot's "what would Albert do given
this board state" orders are stored per power.  This script loads each phase
state from the matching `all_games/` JSON, runs the Python port for every
power, and compares the resulting orders against Albert's record.

Reports per-power match rate and per-game / global aggregates.

Usage::

    cd ~/Downloads/work/Pybert
    uv run compare_albert.py                       # all games, CRT seed 1
    uv run compare_albert.py --max-games 5         # smoke test
    uv run compare_albert.py --phase-types M       # movement only
    uv run compare_albert.py --game game_10.json   # single game
"""
from __future__ import annotations

import argparse
import copy
import json
import logging
import os
import sys
import time
from collections import Counter, defaultdict
from itertools import combinations
from pathlib import Path

# Make the Pybert package importable when running from the repo dir.
_THIS = Path(__file__).resolve().parent
_PARENT = _THIS.parent
if str(_PARENT) not in sys.path:
    sys.path.insert(0, str(_PARENT))

from diplomacy import Game

from Pybert.bot.client import AlbertClient
from Pybert import rng as random
from Pybert.monte_carlo import restore_order_entry
from Pybert.bot.orders import _build_order_seq_from_table
from Pybert.dispatch import validate_and_dispatch_order


POWERS = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]


def _adjustment_candidate_sets(state, power: str) -> list[list[str]]:
    """Enumerate complete legal WIN sets from the generated candidate keys."""
    own_idx = POWERS.index(power)
    delta_record = state.g_build_delta.get(own_idx, {'flag': 0, 'delta': 0})
    delta = max(int(delta_record.get('delta', 0)), 0)
    if delta == 0:
        return [[]]

    if int(delta_record.get('flag', 0)) == 1:
        atomic: list[tuple[int, str]] = []
        for candidate in state.g_adjustment_build_candidates:
            prov = int(candidate['province'])
            name = state._id_to_prov.get(prov, str(prov))
            unit_type = str(candidate['unit_type'])
            coast = str(candidate.get('coast', ''))
            if unit_type == 'FLT':
                name += coast
            letter = 'F' if unit_type == 'FLT' else 'A'
            atomic.append((prov, f"{letter} {name} B"))

        distinct_provinces = {prov for prov, _ in atomic}
        build_count = min(delta, len(distinct_provinces))
        result: list[list[str]] = []
        for choice in combinations(atomic, build_count):
            if len({prov for prov, _ in choice}) != build_count:
                continue
            # The reference JSONs omit implicit WAIVE orders, so candidate
            # identity contains only explicit builds.
            result.append([order for _, order in choice])
        return result

    atomic = []
    for prov, unit in state.unit_info.items():
        if int(unit.get('power', -1)) != own_idx:
            continue
        name = state._id_to_prov.get(prov, str(prov))
        coast = str(unit.get('coast', ''))
        if coast and not name.endswith(coast):
            name += coast if coast.startswith('/') else '/' + coast
        letter = 'F' if unit.get('type') == 'F' else 'A'
        atomic.append(f"{letter} {name} D")
    return [list(choice) for choice in combinations(atomic, min(delta, len(atomic)))]


def _retreat_candidate_sets(state_data: dict, power: str) -> list[list[str]]:
    """Enumerate complete legal RTO/DSB combinations from NOW retreat data."""
    retreat_map = (state_data.get('retreats') or {}).get(power, {}) or {}
    if not retreat_map:
        return [[]]

    per_unit: list[list[tuple[str, str | None]]] = []
    for unit, destinations in retreat_map.items():
        unit = _norm_order(unit)
        choices = [(f"{unit} R {_norm_order(dst)}", _norm_order(dst))
                   for dst in (destinations or [])]
        choices.append((f"{unit} D", None))
        per_unit.append(choices)

    complete: list[list[str]] = [[]]
    complete_dests: list[set[str]] = [set()]
    for choices in per_unit:
        next_complete: list[list[str]] = []
        next_dests: list[set[str]] = []
        for orders, used in zip(complete, complete_dests):
            for order, dest in choices:
                if dest is not None and dest in used:
                    continue
                next_complete.append(orders + [order])
                next_dests.append(used | ({dest} if dest is not None else set()))
        complete, complete_dests = next_complete, next_dests
    return complete


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
                              power: str, seed: int,
                              capture_candidates: bool = False,
                              run_submission: bool = True,
                              ) -> list[str] | tuple[list[str], list[list[str]]] | None:
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
    # This is an offline ``diplomacy.Game``, not a NetworkGame.  Submission
    # still goes through ``Game.set_orders``, but GOF is a network readiness
    # signal (``NetworkGame.no_wait``) and has no local equivalent.  Suppress
    # outbound protocol traffic so a successful order-generation run is not
    # misreported as a Pybert failure after its orders have been produced.
    client._send_dm = lambda _msg: None
    if not run_submission:
        # Coverage-only seed sweeps need the ProcessTurn snapshots, not
        # BuildAndSendSUB's 30 ranking/update rounds.  The candidate records
        # are complete before that call, so bypassing submission changes no
        # coverage evidence and cuts a six-unit seed from ~130s to ~2s.
        client._build_and_send_sub = lambda _best_orders: None

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
    if not capture_candidates:
        return submitted

    if phase_name.endswith("A"):
        return submitted, _adjustment_candidate_sets(client.state, power)
    if phase_name.endswith("R"):
        return submitted, _retreat_candidate_sets(state_data, power)
    if not phase_name.endswith("M"):
        return submitted

    # Keep candidate coverage separate from final selection.  A candidate is
    # useful oracle evidence only if its complete snapshot can pass the same
    # serializer/validator path as a submitted set.  The validator mutates the
    # order table and submitted list, so use a deep copy per record.
    candidate_sets: list[list[str]] = []
    own_idx = POWERS.index(power)
    # One isolated state is sufficient: every complete candidate snapshot
    # overwrites all own-unit rows before validation.  Deep-copying the full
    # 7×256 analysis state for every record made six-unit pools spend minutes
    # in diagnostics after generation itself had finished in seconds.
    candidate_state = copy.deepcopy(client.state)
    own_provinces = [
        prov for prov, unit in candidate_state.unit_info.items()
        if int(unit.get('power', -1)) == own_idx
    ]
    for candidate in client.state.g_candidate_record_list:
        if int(candidate.get("power", -1)) != own_idx:
            continue
        candidate_state.g_submitted_orders = []
        candidate_state.g_order_table[own_provinces, :] = 0.0
        valid = True
        for entry in candidate.get("orders", []):
            prov = restore_order_entry(
                candidate_state.g_order_table, entry, full_row=True)
            seq = _build_order_seq_from_table(candidate_state, prov)
            if (seq is None or validate_and_dispatch_order(
                    candidate_state, own_idx, seq) != 0):
                valid = False
                break
        if valid:
            candidate_sets.append(list(candidate_state.g_submitted_orders))
    return submitted, candidate_sets


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


def _candidate_set_key(orders: list[str]) -> frozenset[str]:
    """Return the normalized, order-insensitive identity of one candidate."""
    return frozenset(_norm_order(order) for order in orders)


def _extend_candidate_seed_coverage(
        candidate_sets: list[list[str]], albert_orders: list[str],
        state_data: dict, phase_name: str, power: str, primary_seed: int,
        seed_count: int, capture_fn=None,
        ) -> tuple[bool, list[int]]:
    """Optionally union candidate pools from a deterministic seed range.

    The caller has already captured ``primary_seed``; additional pools are
    evaluated only until the reference set is found.  Submitted orders are
    intentionally not returned or changed by this diagnostic helper.
    """
    if capture_fn is None:
        capture_fn = _capture_orders_for_power
    target = _candidate_set_key(albert_orders)
    seen = {_candidate_set_key(orders) for orders in candidate_sets}
    seeds_tried = [primary_seed]
    if target in seen:
        return True, seeds_tried

    for candidate_seed in range(seed_count):
        if candidate_seed == primary_seed:
            continue
        extra_capture = capture_fn(
            state_data, phase_name, power, seed=candidate_seed,
            capture_candidates=True, run_submission=False)
        seeds_tried.append(candidate_seed)
        if extra_capture is None:
            continue
        _extra_orders, extra_sets = extra_capture
        for orders in extra_sets:
            key = _candidate_set_key(orders)
            if key not in seen:
                seen.add(key)
                candidate_sets.append(orders)
        if target in seen:
            return True, seeds_tried
    return False, seeds_tried


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
    parser.add_argument("--phase", default=None,
                        help="Restrict to one exact phase name (for example S1907M).")
    parser.add_argument("--power", choices=POWERS, default=None,
                        help="Restrict to one power.")
    parser.add_argument("--max-games", type=int, default=None,
                        help="Stop after N games.")
    parser.add_argument("--phase-types", default="M",
                        help="Phase suffixes to compare (e.g. 'M', 'MR', 'MAR'). "
                             "Default 'M' (movement only).")
    parser.add_argument(
        "--seed", type=int, default=1,
        help="MSVC CRT srand state reset before each run. The recovered source "
             "contains no srand call, so the CRT default is 1.",
    )
    parser.add_argument("--verbose", action="store_true",
                        help="Print each phase/power result.")
    parser.add_argument(
        "--candidate-coverage", action="store_true",
        help="For movement, retreat, and adjustment phases, report whether Albert's "
             "complete order set exists among Pybert's generated legal candidates.",
    )
    parser.add_argument(
        "--candidate-seed-count", type=int, default=0, metavar="N",
        help="When candidate coverage misses at --seed, additionally union "
             "candidate pools from seeds 0 through N-1. This does not change "
             "the submitted-order comparison. Default: 0 (no sweep).",
    )
    parser.add_argument("--out", default=None,
                        help="Optional path for per-(game,phase,power) JSON dump.")
    args = parser.parse_args()
    if args.candidate_seed_count < 0:
        parser.error("--candidate-seed-count must be non-negative")

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
    n_candidate_pairs = 0
    n_candidate_covered = 0
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
            if args.phase and phase_name != args.phase:
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
                if args.power and power != args.power:
                    continue
                albert_orders = list(albert_orders or [])
                capture = _capture_orders_for_power(
                    state, phase_name, power, seed=args.seed,
                    capture_candidates=args.candidate_coverage)
                if capture is None:
                    n_pybert_failed += 1
                    by_phase_type[phase_name[-1]]["failed"] += 1
                    if args.verbose:
                        print(f"  [{phase_name}] {power}: PYBERT FAILED")
                    continue
                if (args.candidate_coverage
                        and phase_name.endswith(("M", "R", "A"))):
                    pybert_orders, candidate_sets = capture
                else:
                    pybert_orders = capture
                    candidate_sets = []
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

                candidate_covered = None
                candidate_best_unit_match = None
                candidate_unit_coverage = None
                closest_candidate = None
                candidate_seeds_tried: list[int] = []
                if (args.candidate_coverage
                        and phase_name.endswith(("M", "R", "A"))):
                    albert_norm = {_norm_order(o) for o in albert_orders}
                    # A single finite Monte-Carlo pool is not a structural
                    # generation oracle.  If requested, union additional
                    # deterministic pools while leaving ``pybert_orders``
                    # tied exclusively to --seed.
                    if phase_name.endswith("M"):
                        candidate_covered, candidate_seeds_tried = (
                            _extend_candidate_seed_coverage(
                                candidate_sets, albert_orders, state, phase_name,
                                power, args.seed, args.candidate_seed_count)
                        )
                    else:
                        target = _candidate_set_key(albert_orders)
                        candidate_covered = any(
                            _candidate_set_key(orders) == target
                            for orders in candidate_sets
                        )
                        candidate_seeds_tried = [args.seed]
                    candidate_diffs = [
                        _compare_orders(albert_orders, orders)
                        for orders in candidate_sets
                    ]
                    if candidate_diffs:
                        closest_idx = max(
                            range(len(candidate_diffs)),
                            key=lambda i: candidate_diffs[i]["unit_match"],
                        )
                        candidate_best_unit_match = candidate_diffs[
                            closest_idx]["unit_match"]
                        closest_candidate = candidate_sets[closest_idx]
                        covered_orders = {
                            _norm_order(order)
                            for orders in candidate_sets for order in orders
                        }
                        candidate_unit_coverage = sum(
                            _norm_order(order) in covered_orders
                            for order in albert_orders
                        )
                    n_candidate_pairs += 1
                    n_candidate_covered += int(candidate_covered)

                if args.verbose:
                    flag = "✓" if diff["exact_set_match"] else "✗"
                    print(f"  [{phase_name}] {power}: {flag} "
                          f"unit_match={diff['unit_match']}/{diff['unit_total']}"
                          f" albert={diff['albert_count']} pybert={diff['pybert_count']}"
                          + (f" candidate={'yes' if candidate_covered else 'no'}"
                             f"/{len(candidate_sets)}"
                             f" seeds={','.join(map(str, candidate_seeds_tried))}"
                             f" best={candidate_best_unit_match}/{diff['unit_total']}"
                             f" unit-coverage={candidate_unit_coverage}/{len(albert_orders)}"
                             if candidate_covered is not None else ""))
                    if not diff["exact_set_match"]:
                        for o in diff["albert_only"]:
                            print(f"       albert-only: {o}")
                        for o in diff["pybert_only"]:
                            print(f"       pybert-only: {o}")
                    if (candidate_covered is False
                            and closest_candidate is not None):
                        closest_diff = _compare_orders(
                            albert_orders, closest_candidate)
                        for o in closest_diff["albert_only"]:
                            print(f"       closest misses: {o}")
                        for o in closest_diff["pybert_only"]:
                            print(f"       closest has:    {o}")

                if args.out:
                    per_record.append({
                        "game": albert_path.name,
                        "phase": phase_name,
                        "power": power,
                        "albert": albert_orders,
                        "pybert": pybert_orders,
                        "candidate_covered": candidate_covered,
                        "candidate_count": len(candidate_sets),
                        "candidate_seeds_tried": candidate_seeds_tried,
                        "candidate_best_unit_match": candidate_best_unit_match,
                        "candidate_unit_coverage": candidate_unit_coverage,
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
    if n_candidate_pairs:
        print(f"  Albert set generated: {n_candidate_covered}/{n_candidate_pairs}"
              f" = {100*n_candidate_covered/n_candidate_pairs:.1f}%")
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
