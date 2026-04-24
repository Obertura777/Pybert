#!/usr/bin/env python3
"""
Run the Python Albert bot on game states from all_games/ and compare
orders against the C reference output in all_games_albert/.

Usage:
    python3 run_comparison.py [--games N] [--phases N] [--verbose]
"""
import json
import os
import sys
import time
import logging
import collections
import argparse
import traceback

import numpy as np

# Ensure the package is importable
_THIS_DIR = os.path.dirname(os.path.abspath(__file__))
_PARENT = os.path.dirname(_THIS_DIR)
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)
if _THIS_DIR not in sys.path:
    sys.path.insert(0, _THIS_DIR)

_PKG = os.path.basename(_THIS_DIR)

from diplomacy import Game

_state_mod = __import__(f'{_PKG}.state', fromlist=['InnerGameState'])
_shared_mod = __import__(f'{_PKG}.bot._shared', fromlist=['_POWER_NAMES'])
_analysis_mod = __import__(f'{_PKG}.bot.analysis', fromlist=['_phase_handler'])
_orders_mod = __import__(f'{_PKG}.bot.orders', fromlist=['_build_order_seq_from_table'])
_mc_mod = __import__(f'{_PKG}.monte_carlo', fromlist=['process_turn'])
_mc_flags = __import__(f'{_PKG}.monte_carlo._flags', fromlist=['_F_SECONDARY'])
_mc_gen = __import__(f'{_PKG}.monte_carlo.generation', fromlist=['generate_orders'])
_heur_mod = __import__(f'{_PKG}.heuristics', fromlist=['score_provinces'])
_dispatch_mod = __import__(f'{_PKG}.dispatch', fromlist=['validate_and_dispatch_order'])

InnerGameState = _state_mod.InnerGameState
_POWER_NAMES = _shared_mod._POWER_NAMES
_phase_handler = _analysis_mod._phase_handler
_analyze_position = _analysis_mod._analyze_position
_build_order_seq_from_table = _orders_mod._build_order_seq_from_table
process_turn = _mc_mod.process_turn
_F_ORDER_TYPE = _mc_flags._F_ORDER_TYPE
_F_DEST_PROV = _mc_flags._F_DEST_PROV
_F_DEST_COAST = _mc_flags._F_DEST_COAST
_F_SECONDARY = _mc_flags._F_SECONDARY
generate_orders = _mc_gen.generate_orders
score_provinces = _heur_mod.score_provinces
score_order_candidates_all_powers = _heur_mod.score_order_candidates_all_powers
generate_self_proposals = _heur_mod.generate_self_proposals
_SPR_FAL_WEIGHTS = _heur_mod._SPR_FAL_WEIGHTS
_WIN_BUILD_WEIGHTS = _heur_mod._WIN_BUILD_WEIGHTS
_WIN_REMOVE_WEIGHTS = _heur_mod._WIN_REMOVE_WEIGHTS
score_order_candidates_own_power = _heur_mod.score_order_candidates_own_power
populate_build_candidates = _heur_mod.populate_build_candidates
populate_remove_candidates = _heur_mod.populate_remove_candidates
compute_win_builds = _heur_mod.compute_win_builds
compute_win_removes = _heur_mod.compute_win_removes
validate_and_dispatch_order = _dispatch_mod.validate_and_dispatch_order

logger = logging.getLogger('run_comparison')


def extract_orders_for_power(state, power_idx):
    """Pick best candidate from g_CandidateRecordList, dispatch to order strings."""
    candidates = [c for c in getattr(state, 'g_CandidateRecordList', [])
                  if c.get('power') == power_idx]

    if not candidates:
        return _fallback_orders(state, power_idx)

    best = max(candidates, key=lambda c: float(c.get('score', 0.0)))
    order_pairs = best.get('orders', [])
    if not order_pairs:
        return _fallback_orders(state, power_idx)

    state.g_SubmittedOrders = []
    for entry in order_pairs:
        if len(entry) >= 5:
            prov, order_type, dest_prov, dest_coast, secondary = entry[:5]
            state.g_OrderTable[prov, _F_ORDER_TYPE] = float(order_type)
            state.g_OrderTable[prov, _F_DEST_PROV] = float(dest_prov)
            state.g_OrderTable[prov, _F_DEST_COAST] = float(dest_coast)
            state.g_OrderTable[prov, _F_SECONDARY] = float(secondary)
        else:
            prov = entry[0]
        seq = _build_order_seq_from_table(state, prov)
        if seq is not None:
            try:
                validate_and_dispatch_order(state, power_idx, seq)
            except Exception:
                pass
    return list(state.g_SubmittedOrders)


def _fallback_orders(state, power_idx):
    """If no candidates, read g_OrderTable directly for this power's units."""
    orders = []
    id_to_prov = getattr(state, '_id_to_prov', {})
    for prov, info in state.unit_info.items():
        if info.get('power') != power_idx:
            continue
        ot = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
        if ot == 0:
            unit_chr = 'A' if info.get('type', 'A') in ('A', 'AMY') else 'F'
            pname = id_to_prov.get(prov, str(prov))
            coast = info.get('coast', '')
            loc = f"{pname}/{coast}" if coast else pname
            orders.append(f"{unit_chr} {loc} H")
            continue
        state.g_SubmittedOrders = []
        seq = _build_order_seq_from_table(state, prov)
        if seq is not None:
            try:
                validate_and_dispatch_order(state, power_idx, seq)
                orders.extend(state.g_SubmittedOrders)
            except Exception:
                pass
    return orders


def _extract_winter_orders(state, power_idx):
    """Extract build/remove orders from g_build_order_list for the given power."""
    orders = []
    for entry in getattr(state, 'g_build_order_list', []):
        # Parse '( POWER AMY|FLT PROV ) BLD|REM'
        parts = entry.replace('(', '').replace(')', '').split()
        if len(parts) < 4:
            continue
        _power, unit_daide, prov, action = parts[0], parts[1], parts[2], parts[-1]
        unit_letter = 'F' if unit_daide == 'FLT' else 'A'
        if action == 'BLD':
            orders.append(f"{unit_letter} {prov} B")
        elif action == 'REM':
            orders.append(f"{unit_letter} {prov} D")
    for _ in range(getattr(state, 'g_waive_count', 0)):
        orders.append("WAIVE")
    return orders


def run_phase_all_powers(phase_info):
    """
    Run order generation for ALL 7 powers on one phase.
    Returns dict: power_name -> [order_strings]
    """
    game = Game()
    game.set_state(phase_info['state'])
    state = InnerGameState()
    state.synchronize_from_game(game)

    num_powers = 7
    # We run the pipeline once with power_idx=0 as the "perspective" power
    # (matching the C bot's no-press approach where each power runs independently).
    # But since the MC loop iterates all powers, we can extract for all.

    results = {}
    for own_power in range(num_powers):
        # Fresh state per power (matching C behavior: each power instance is independent)
        game2 = Game()
        game2.set_state(phase_info['state'])
        state = InnerGameState()
        state.synchronize_from_game(game2)

        state.albert_power_idx = own_power
        state.g_AlbertPower = own_power
        state.g_turn_start_time = time.time()
        state.g_PressFlag = 0
        state.g_PressCandidateA = [[None] * 30 for _ in range(num_powers)]
        state.g_PressCandidateB = [[None] * 30 for _ in range(num_powers)]

        if not hasattr(state, 'g_trust_counter'):
            state.g_trust_counter = np.zeros(num_powers, dtype=np.int32)

        _phase_handler(state, 0)

        phase = state.g_season
        movement_phase = phase in ('SPR', 'FAL')

        if phase == 'SPR':
            state.g_DeceitLevel += 1
        if movement_phase:
            _analyze_position(state)

        state.g_baed6d = 0

        # GenerateOrders
        generate_orders(state, own_power)

        if movement_phase:
            try:
                score_provinces(state, 0, 0, own_power)
            except Exception:
                pass
            try:
                score_order_candidates_all_powers(state, _SPR_FAL_WEIGHTS, own_power)
            except Exception:
                pass

        # Clear and build self-proposals
        state.g_GeneralOrders = {}
        state.g_AllianceOrders = {}
        state.g_CandidateRecordList = []

        if movement_phase:
            try:
                generate_self_proposals(state, own_power)
            except Exception:
                pass

        # Winter build/remove pipeline (WIN phase)
        if phase == 'WIN':
            state.g_build_order_list = []
            state.g_waive_count = 0

            saved_sc = state.g_SCOwnership.copy()
            try:
                score_provinces(state, 0, 0, own_power)
            except Exception:
                pass
            state.g_SCOwnership[:] = saved_sc

            sc = int(state.sc_count[own_power])
            units = sum(1 for u in state.unit_info.values()
                        if u.get('power') == own_power)
            if units < sc:
                try:
                    populate_build_candidates(state, own_power)
                    score_order_candidates_own_power(
                        state, _WIN_BUILD_WEIGHTS, own_power)
                    compute_win_builds(state, sc - units)
                except Exception:
                    pass
            elif sc < units:
                try:
                    populate_remove_candidates(state, own_power)
                    score_order_candidates_own_power(
                        state, _WIN_REMOVE_WEIGHTS, own_power)
                    compute_win_removes(state, units - sc)
                except Exception:
                    pass

        # MC trial loop (movement phases only)
        if movement_phase:
            trial_scale = getattr(state, 'g_TrialScale', 260)
            unit_count = getattr(state, 'g_UnitCount', np.zeros(num_powers, dtype=np.int32))

            MC_ROUNDS = 10
            for _ in range(MC_ROUNDS):
                for p in range(num_powers):
                    if int(unit_count[p]) <= 0:
                        continue
                    if p == own_power:
                        n_trials = (int(unit_count[p]) * trial_scale + 10) // 10
                    else:
                        n_trials = 1
                    try:
                        process_turn(state, p, n_trials)
                    except Exception:
                        pass

        # Extract orders for own power
        if phase == 'WIN':
            orders = _extract_winter_orders(state, own_power)
        else:
            orders = extract_orders_for_power(state, own_power)
        results[_POWER_NAMES[own_power]] = orders

    return results


def normalize_order(order_str):
    return ' '.join(order_str.upper().split())


def run_game(game_file, albert_file, max_phases=None):
    with open(game_file) as f:
        game_data = json.load(f)
    with open(albert_file) as f:
        albert_data = json.load(f)

    total_pp = 0
    match_pp = 0
    total_ord = 0
    match_ord = 0
    diffs = []
    phase_stats = collections.Counter()
    phase_match = collections.Counter()

    phases = game_data.get('phases', [])
    if max_phases:
        phases = phases[:max_phases]

    for phase_info in phases:
        phase_name = phase_info.get('name', '')
        if phase_name not in albert_data:
            continue
        c_phase = albert_data[phase_name]
        if not c_phase:
            continue

        ptype = phase_name[-1] if phase_name else '?'

        try:
            py_phase = run_phase_all_powers(phase_info)
        except Exception as e:
            logger.warning(f"Error on {phase_name}: {e}")
            traceback.print_exc()
            continue

        for power_name in _POWER_NAMES:
            c_orders = c_phase.get(power_name, [])
            if not c_orders:
                continue

            py_orders = py_phase.get(power_name, [])
            c_norm = sorted(normalize_order(o) for o in c_orders)
            py_norm = sorted(normalize_order(o) for o in py_orders)

            total_pp += 1
            phase_stats[ptype] += 1
            total_ord += max(len(c_norm), len(py_norm))

            if c_norm == py_norm:
                match_pp += 1
                match_ord += len(c_norm)
                phase_match[ptype] += 1
            else:
                py_rem = list(py_norm)
                for o in c_norm:
                    if o in py_rem:
                        match_ord += 1
                        py_rem.remove(o)
                if len(diffs) < 30:
                    diffs.append((phase_name, power_name, c_norm, py_norm))

    return total_pp, match_pp, total_ord, match_ord, diffs, phase_stats, phase_match


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--games', type=int, default=3, help='Number of games')
    parser.add_argument('--phases', type=int, default=3, help='Max phases per game')
    parser.add_argument('--verbose', action='store_true')
    args = parser.parse_args()

    logging.basicConfig(level=logging.DEBUG if args.verbose else logging.WARNING)

    base = os.path.dirname(os.path.abspath(__file__))
    orig_dir = os.path.join(base, 'all_games')
    albert_dir = os.path.join(base, 'all_games_albert')

    common = sorted(set(os.listdir(orig_dir)) & set(os.listdir(albert_dir)))
    common = common[:args.games]

    print(f"Processing {len(common)} games, up to {args.phases} phases each...")

    grand_pp = grand_match_pp = grand_ord = grand_match_ord = 0
    all_diffs = []
    grand_phase_stats = collections.Counter()
    grand_phase_match = collections.Counter()

    for fname in common:
        t0 = time.time()
        try:
            pp, mpp, ordt, mord, diffs, pstats, pmatch = run_game(
                os.path.join(orig_dir, fname),
                os.path.join(albert_dir, fname),
                max_phases=args.phases,
            )
        except Exception as e:
            print(f"  {fname}: ERROR - {e}")
            traceback.print_exc()
            continue

        grand_pp += pp
        grand_match_pp += mpp
        grand_ord += ordt
        grand_match_ord += mord
        all_diffs.extend(diffs)
        grand_phase_stats += pstats
        grand_phase_match += pmatch

        elapsed = time.time() - t0
        pct = 100 * mord / max(ordt, 1)
        print(f"  {fname}: {mpp}/{pp} power-phases, "
              f"{mord}/{ordt} orders ({pct:.1f}%) [{elapsed:.1f}s]")

    print(f"\n{'='*60}")
    print(f"Power-phases: {grand_match_pp}/{grand_pp} "
          f"({100*grand_match_pp/max(grand_pp,1):.1f}%)")
    print(f"Orders:       {grand_match_ord}/{grand_ord} "
          f"({100*grand_match_ord/max(grand_ord,1):.1f}%)")

    print(f"\nBy phase type:")
    for pt in sorted(grand_phase_stats.keys()):
        m = grand_phase_match[pt]
        t = grand_phase_stats[pt]
        print(f"  {pt}: {m}/{t} ({100*m/max(t,1):.1f}%)")

    if all_diffs:
        print(f"\nFirst {min(len(all_diffs), 30)} differences:")
        for pname, power, c_ord, py_ord in all_diffs[:30]:
            print(f"  {pname} {power}:")
            print(f"    C:  {c_ord}")
            print(f"    Py: {py_ord}")


if __name__ == '__main__':
    main()
