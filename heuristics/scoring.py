"""Candidate scoring and province evaluation pipeline.

Split from heuristics.py during the 2026-04 refactor.

- ``score_order_candidates_all_powers`` — ScoreOrderCandidates outer loop
- ``score_provinces``                   — ScoreProvinces (strategy-wide province scoring)
- ``apply_press_corroboration_penalty`` — per-candidate penalty based on press corroboration
- ``score_order_candidates_own_power``  — inner loop specialised for own power

Module-level deps: ``numpy``, ``..state.InnerGameState``,
``._primitives.evaluate_province_score``.  Owns the module-level constant
``_PRESS_DISAGREE_PENALTY`` consumed by ``apply_press_corroboration_penalty``.
"""

import logging
import numpy as np

from ..state import InnerGameState

from ._primitives import evaluate_province_score

_dbg_log = logging.getLogger("pybert.scoring_dbg")

# M2: ScoreProvinces normalization exponent — the C binary's _safe_pow call
# uses an FPU-stack argument not recoverable from Ghidra decompile.
# Default 0.5 (sqrt); empirical sweep shows no measurable effect while PRNG
# divergence dominates.  Will become relevant once PRNG is aligned.
# Sweep [0.3, 1.0] after PRNG fix for final calibration.
SCORE_NORM_EXPONENT = 0.5


def score_order_candidates_all_powers(state: InnerGameState, round_weights: list, dominant_power_idx: int):
    """
    Port of ScoreOrderCandidates_AllPowers / FUN_0044a040.
    Per-power per-province influence dot-product scoring pass.
    """
    dominance_weight = state.score_current - state.score_baseline
    
    for power in range(7):
        for province in range(256):
            if not state.candidate_set_contains(power, province):
                continue
                
            total = 0.0
            for i in range(min(10, len(round_weights))):
                score = state.get_candidate_score(power, province, i)
                total += score * round_weights[i]
                
            # C (ScoreOrderCandidates_AllPowers.c:106): war-mode bonus fires when
            # DAT_00baed6c == 1 AND DAT_00624124 != local_f4.  The canonical Python
            # name for DAT_00baed6c is g_war_mode_flag (written by heuristics/board.py).
            # g_DominantPowerMode is the legacy alias per GlobalDataRefs.md:135 and
            # research.md:3531 — kept as a fallback for any transitional callers.
            war_mode = int(getattr(state, 'g_war_mode_flag',
                           getattr(state, 'g_dominant_power_mode', 0)))
            if war_mode == 1 and power != dominant_power_idx:
                main_candidate_score = state.get_candidate_score(power, province, 0)
                total += main_candidate_score * dominance_weight
                
            state.g_max_province_score[province] = max(state.g_max_province_score[province], total)
            state.g_min_score[province] = min(state.g_min_score[province], total)
            
            state.final_score_set[power, province] = total
            
    # Pass 2 - Score normalization (C Phase 1b, lines 131-211)
    # Rewritten 2026-04-14: per-power max/min now tracked via
    # g_max_prov_score_per_power / g_min_prov_score_per_power (was only global).
    # Sub-threshold nonzero/non-min branch now uses _safe_pow proxy
    # with configurable SCORE_NORM_EXPONENT (default 0.5).
    import random as _rnd
    global_max = np.max(state.g_max_province_score)
    threshold = global_max / 100.0
    # Off-by-one guard — C: if min == threshold → threshold = min+1
    global_min = float(np.min(state.g_min_score))
    if global_min == threshold:
        threshold = global_min + 1.0

    for power in range(7):
        for province in range(256):
            raw_score = state.final_score_set[power, province]
            if raw_score <= 0:
                continue
            if raw_score >= threshold and global_max > 0:
                score = (raw_score * 1000.0 / global_max) + 15.0
            else:
                if raw_score == 0:
                    score = 1.0
                elif raw_score == state.g_min_score[province]:
                    score = float(_rnd.randint(1, 10))
                else:
                    # _safe_pow proxy — C applies pow(score/min, exponent).
                    # The exponent is an FPU-stack argument in the Ghidra
                    # decompile (ScoreOrderCandidates_AllPowers.c:178) and
                    # cannot be recovered from the binary.  Candidate values:
                    #   0.5  (sqrt) — diminishing returns, conservative
                    #   0.75       — moderate compression
                    #   1.0        — linear (no compression)
                    # Using 0.5 as default; tune via SCORE_NORM_EXPONENT.
                    # M2: If game output parity testing reveals systematic
                    # divergence in province scoring, sweep [0.3, 1.0].
                    denom = max(float(state.g_min_score[province]), 1.0)
                    ratio = max(raw_score / denom, 0.0)
                    score = pow(ratio, SCORE_NORM_EXPONENT)
                if score > 10.0:
                    score = 10.0

            state.final_score_set[power, province] = score

            # Per-power max/min pair updates (C Phase 1b tail, lines 193-209)
            if hasattr(state, 'g_max_prov_score_per_power'):
                if score > state.g_max_prov_score_per_power[power, province]:
                    state.g_max_prov_score_per_power[power, province] = score
                if score < state.g_min_prov_score_per_power[power, province]:
                    state.g_min_prov_score_per_power[power, province] = score

            # Pass 3 - AMY shortfall-pull toward max (C Phase 1c, lines 214-248)
            # Replaces former random 0.9-1.1 jitter with deterministic
            # "delta to per-power max" — pulls under-performing armies
            # toward the best-scoring province.
            if state.get_unit_type(province) == "AMY":
                per_pow_max = (state.g_max_prov_score_per_power[power, province]
                               if hasattr(state, 'g_max_prov_score_per_power')
                               else state.g_max_province_score[province])
                if score < per_pow_max:
                    state.final_score_set[power, province] = float(per_pow_max) - score

    # Pass 3b - Recompute g_max_province_score from normalized final_score_set.
    # In C (lines 192-201), g_max_province_score is updated DURING the
    # normalization loop, so it holds post-normalization values.  The Python
    # Pass 1 sets it from raw dot-product totals; we must refresh it here so
    # that downstream consumers (TopReachFlag, BuildSupportOpportunities)
    # see the correct normalized maxima.
    state.g_max_province_score[:] = 0
    for power in range(7):
        for province in range(256):
            v = float(state.final_score_set[power, province])
            if v > state.g_max_province_score[province]:
                state.g_max_province_score[province] = v

    # Pass 3c - SC ownership override on final_score_set (mirrors
    # ScoreProvinces Adjustment 9, C lines 1209-1228).
    # In C the BFS that seeds candidates uses g_attack_count (which has the
    # Adj 9 cap of 90/150 for own SCs), so final_score_set inherits low
    # values for own SCs.  Python's BFS seeds with a flat 5000.0, so own
    # SCs get inflated scores (760-1011 instead of 90/150).  Apply the same
    # cap here so Phase 2 ranks expansion targets above own SCs.
    for power in range(7):
        for province in range(256):
            if state.g_sc_ownership[power, province] != 1:
                continue
            if state.final_score_set[power, province] <= 0:
                continue
            unit_power = state.get_unit_power(province)
            if unit_power == power:
                state.final_score_set[power, province] = 90.0
            else:
                state.final_score_set[power, province] = 150.0

    # Pass 4 - g_prov_target_flag classification (C Phase 3, lines 265-316)
    # Ported 2026-04-14 — fixes dead-code bug (enemy_reach==0 duplicate branch)
    # and adds g_attack_count < 1 gate.
    for power in range(7):
        for province in range(256):
            if not state.has_unit(province):
                continue
            # C check: if province has no home-unit OR owner == this power
            unit_owner = getattr(state, 'get_unit_owner', lambda p: None)(province)
            if unit_owner is not None and unit_owner != power:
                continue
            # C: (g_attack_count[key] < 1) AND (g_target_flag != 2 OR g_attack_count2 != 0)
            attack_cnt = getattr(state, 'g_attack_count', None)
            attack_cnt_val = attack_cnt[power, province] if attack_cnt is not None else 0
            tflag = state.g_target_flag[power, province] if hasattr(state, 'g_target_flag') else 0
            attack_cnt2 = getattr(state, 'g_attack_count2', None)
            ac2_val = attack_cnt2[power, province] if attack_cnt2 is not None else 0
            if not (attack_cnt_val < 1 and (tflag != 2 or ac2_val != 0)):
                continue
            enemy_reach = state.get_enemy_reach(power, province)
            sc_own = state.g_sc_ownership[power, province]
            total_reach = state.g_total_reach_score[power, province] if hasattr(state, 'g_total_reach_score') else 0
            enemy_reach_score = state.g_enemy_reach_score[power, province] if hasattr(state, 'g_enemy_reach_score') else 0
            d535 = getattr(state, 'g_enemy_pressure_secondary', None)
            d535_val = d535[power, province] if d535 is not None else 0

            if enemy_reach < 0:
                # Fully safe — enemy cannot reach
                state.g_prov_target_flag[power, province] = 1
            elif enemy_reach == 0 and sc_own == 1 and enemy_reach_score == 0 and d535_val == 0:
                # Own SC, no enemy near
                state.g_prov_target_flag[power, province] = 1
            elif (enemy_reach == 1 and sc_own == 1 and total_reach == 0
                  and enemy_reach_score == 0 and d535_val == 0):
                # Own SC, 1-hop enemy — secondary priority
                state.g_prov_target_flag[power, province] = 2
            else:
                continue
            # C: (&DAT_005ee8ec)[iVar10 * 2] = 0 — clear the "classified" marker
            if hasattr(state, 'g_target_flag2'):
                state.g_target_flag2[power, province] = 0

    # Pass 5 - Enemy-adjacency denial (C Phase 4, lines 317-407)
    # For each own unit: if a 2-hop-reachable province is occupied by a
    # non-allied enemy, mark the 1-hop province as flanked (flag = -10).
    for power in range(7):
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            for adj1 in (state.get_adjacent_provinces(unit_prov)
                         if hasattr(state, 'get_adjacent_provinces') else []):
                for adj2 in (state.get_adjacent_provinces(adj1)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    adj2_owner = (state.get_unit_owner(adj2)
                                  if hasattr(state, 'get_unit_owner') else None)
                    if adj2_owner is None or adj2_owner == power:
                        continue
                    # C: g_relation_score[local_f4*21+owner] < 10 — not trusted ally.
                    # Fixed 2026-04-14 — was reading g_ally_history_count (unpopulated);
                    # correct global is g_relation_score (DAT_00634e90).
                    rel = getattr(state, 'g_relation_score', None)
                    rel_val = rel[power, adj2_owner] if rel is not None else 0
                    if rel_val >= 10:
                        continue
                    if (state.g_prov_target_flag[power, adj1] == 1
                        and state.g_target_flag2[power, adj1] == 0):
                        state.g_prov_target_flag[power, adj1] = -10
                        state.g_target_flag2[power, adj1] = -1

    # Pass 6 - Multi-flanked restoration (C Phase 5, lines 408-480)
    # If a province has >1 neighbor also flagged -10, the local front is
    # contested everywhere — lift the flag back to 1.
    for power in range(7):
        for province in range(256):
            if state.g_prov_target_flag[power, province] != -10:
                continue
            flanked_neighbors = 0
            for adj in (state.get_adjacent_provinces(province)
                        if hasattr(state, 'get_adjacent_provinces') else []):
                if state.g_prov_target_flag[power, adj] == -10:
                    flanked_neighbors += 1
            if flanked_neighbors > 1:
                state.g_prov_target_flag[power, province] = 1
                if hasattr(state, 'g_target_flag2'):
                    state.g_target_flag2[power, province] = 0

    # Pass 7 - Direct-reach + extended-reach flagging (C Phase 10, lines 682-791)
    # For each own unit: mark adjacency as DirectReach=1 and 2-hop as ExtendedReach=1.
    direct_reach = getattr(state, 'g_direct_reach_flag', None)
    ext_reach = getattr(state, 'g_extended_reach_flag', None)
    if direct_reach is not None and ext_reach is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    direct_reach[power, adj1] = 1
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        if state.has_unit(adj2):
                            ext_reach[power, adj2] = 1

        # Pass 7b - 3-round BFS flood-fill of DirectReach (C Phase 10b, lines 792-845)
        for power in range(7):
            for _ in range(3):
                frontier = [p for p in range(256) if direct_reach[power, p] == 1]
                for prov in frontier:
                    for adj in (state.get_adjacent_provinces(prov)
                                if hasattr(state, 'get_adjacent_provinces') else []):
                        direct_reach[power, adj] = 1

    # Pass 8 - Own-SC rescore reset (C Phase 6, lines 481-517)
    # For each own unit, if its final score is below per-power max → mark
    # g_needs_rescore = 0 (needs support-score reconsideration).
    if hasattr(state, 'g_needs_rescore') and hasattr(state, 'g_max_prov_score_per_power'):
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                if (state.final_score_set[power, unit_prov]
                    < state.g_max_prov_score_per_power[power, unit_prov]):
                    state.g_needs_rescore[unit_prov] = 0

        # Pass 9 - Support-assignment gate (C Phase 7, lines 518-589)
        # For each own unit adjacency: if pending-rescore AND own SC AND
        # no enemy pressure AND score hits per-power max → finalize.
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj in (state.get_adjacent_provinces(unit_prov)
                            if hasattr(state, 'get_adjacent_provinces') else []):
                    if state.g_needs_rescore[adj] != 0:
                        continue
                    if (state.g_sc_ownership[power, adj] == 1
                        and state.g_enemy_reach_score[power, adj] == 0):
                        score = state.final_score_set[power, adj]
                        if score == state.g_max_prov_score_per_power[power, adj]:
                            state.g_needs_rescore[adj] = 1

    # Pass 9b - TopReachFlag population (C lines 481-589, Phase 7b)
    # Two sub-passes mirror the C unit walks:
    #   Sub-pass A (C lines 481-517): for each own unit, look up its
    #       final_score_set entry against g_max_province_score.  If the unit's
    #       province score is BELOW the global max for that province, clear
    #       g_top_reach_flag[prov] = 0  (province is not a top-reach target).
    #   Sub-pass B (C lines 518-589): for each own unit, walk adjacency q.
    #       If g_top_reach_flag[q] == 0 AND g_sc_ownership[power, q] == 1 AND
    #       final_score_set[power, q] == g_max_province_score[q], set
    #       g_top_reach_flag[q] = 1  (reachable top-scored own-SC province).
    # This populates the gate used by build_support_opportunities.
    for power in range(7):
        # Sub-pass A: clear TopReachFlag for under-performing unit provinces
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            fs_val = float(state.final_score_set[power, unit_prov])
            mx_val = float(state.g_max_province_score[unit_prov])
            if fs_val < mx_val:
                state.g_top_reach_flag[unit_prov] = 0

    for power in range(7):
        # Sub-pass B: mark reachable own-SC provinces that hit max score
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            for q in (state.get_adjacent_provinces(unit_prov)
                      if hasattr(state, 'get_adjacent_provinces') else []):
                if int(state.g_top_reach_flag[q]) != 0:
                    continue  # already set or cleared with non-zero marker
                if int(state.g_sc_ownership[power, q]) != 1:
                    continue
                fs_q = float(state.final_score_set[power, q])
                mx_q = float(state.g_max_province_score[q])
                if fs_q > 0 and fs_q == mx_q:
                    state.g_top_reach_flag[q] = 1

    # Pass 10 - BuildSupportOpportunities call (C Phase 8, line 590)
    try:
        from ..moves import build_support_opportunities
        build_support_opportunities(state)
    except Exception:
        # build_support_opportunities may require richer state than a
        # stub; don't block the scoring pass for test harnesses.
        pass

    # Pass 11 - g_support_candidate_mark via enemy-reachable ally-designated
    # adjacencies (C Phase 9, lines 591-681).
    sup_mark = getattr(state, 'g_support_candidate_mark', None)
    ally_e = getattr(state, 'g_ally_designation_e', None)
    if sup_mark is not None and ally_e is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    if ally_e[adj1] < 0:
                        continue
                    # C: (&DAT_004d2e10)[adj*2] != local_f4 → designated for
                    # a different power. Without dual-orientation mirror we
                    # approximate via AllyDesignation_A ≠ own power.
                    if (hasattr(state, 'g_ally_designation_a')
                        and state.g_ally_designation_a[adj1] == power):
                        continue
                    if state.g_enemy_reach_score[power, adj1] <= 0:
                        continue
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        sup_mark[power, adj2] = 1

    # Pass 12 - g_threat_path_score (C Phase 11, lines 846-952)
    # For each non-own province with enemy unit and own-reach > 0: iterate
    # its adjacencies and record the max final_score_set reachable via it.
    threat = getattr(state, 'g_threat_path_score', None)
    if threat is not None:
        for power in range(7):
            for province in range(256):
                if state.g_own_reach_score[power, province] <= 0:
                    continue
                owner = (state.get_unit_owner(province)
                         if hasattr(state, 'get_unit_owner') else None)
                if owner is None or owner == power:
                    continue
                for adj in (state.get_adjacent_provinces(province)
                            if hasattr(state, 'get_adjacent_provinces') else []):
                    score = state.final_score_set[power, adj]
                    if score > threat[power, province]:
                        threat[power, province] = score


# ── ScoreProvinces ────────────────────────────────────────────────────────────

def score_provinces(state: InnerGameState,
                    move_weight: float,   # noqa: ARG001 – reserved for future weighting
                    build_weight: float,  # noqa: ARG001 – reserved for future weighting
                    own_power: int) -> None:
    """
    Port of ScoreProvinces (FUN_00447460).

    Per-trial Monte Carlo scoring kernel.  Iterates all powers, builds a
    reachability matrix from the unit list, applies trust-gated scoring, and
    fills the per-power candidate ordered sets used by order selection.

    Parameters mirror the C signature:
        (Albert *this, uint64 move_weight, uint64 build_weight)

    Research.md §2597.
    """
    num_powers = 7
    num_provinces = 256
    # C iterates only provinces with a non-zero "alive" flag (offset +3,
    # stride 0x24).  Invalid province IDs (> map size) have flag == '\0'
    # and are skipped.  Iterating all 256 gives bogus 75-scores to ~170
    # non-existent provinces, flooding normalization.
    valid_provs = getattr(state, 'valid_provinces', None)

    # Section 1 — zero 11 per-power-province tables
    state.g_own_reach_score.fill(0)       # g_own_reach_score   DAT_0058f8e8
    state.g_ally_reach_score.fill(0)      # g_ally_reach_score  DAT_005658e8
    state.g_enemy_reach_score.fill(0)     # g_enemy_reach_score DAT_00535ce8
    state.g_total_reach_score.fill(0)     # g_total_reach_score DAT_0052b4e8
    state.g_threat_level.fill(0)         # g_ThreatScore     DAT_005460e8
    state.g_convoy_reach_count.fill(0)    # g_convoy_reach_count DAT_005850e8
    state.g_enemy_mobility_count.fill(0)  # g_enemy_mobility_count DAT_0057a8e8
    state.g_sc_ownership.fill(0)         # g_sc_ownership     DAT_00520ce8
    state.g_coverage_flag.fill(0)        # g_coverage_flag
    state.g_max_province_score.fill(0)
    state.g_min_score.fill(1_000_000)    # g_min_score sentinel

    # Friendly/unit-presence flags.
    # g_friendly_unit_flag and g_established_ally_flag are *persisted* to state
    # (ScoreProvinces.c:813-826, DAT_005164e8 / DAT_0050bce8) because
    # heuristics/_primitives.py:compute_winter_builds consumes them via
    # `state.g_friendly_unit_flag[own_power, target]` / `state.g_established_ally_flag[own_power, target]`.
    # The C code indexes them as [outer_power * 0x100 + prov], making them 2D.
    # Updated 2026-04-21: now populated per outer_power inside Section 4 loop.
    # Reset each trial; re-filled below.
    state.g_friendly_unit_flag.fill(0)
    state.g_established_ally_flag.fill(0)
    # g_unit_presence stays local — only consumed below inside Section 4g.
    g_unit_presence        = np.zeros(num_provinces, dtype=np.int32)

    # Section 2 — build reachability matrix from unit list
    # reachability[province][power] = units of power that can reach province
    reachability = np.zeros((num_provinces, num_powers), dtype=np.int32)

    for prov, info in state.unit_info.items():
        power = info['power']
        adj = state.get_unit_adjacencies(prov)
        seen = set()
        for a in adj:
            if a not in seen:
                reachability[a, power] += 1
                state.g_coverage_flag[power, a] += 1
                seen.add(a)
        reachability[prov, power] += 1
        state.g_coverage_flag[power, prov] += 1

    # Section 3 — per-unit presence flags.
    #
    # g_sc_ownership fix 2026-04-14: C populates g_sc_ownership[unit.power, prov]
    # for every unit across all powers (ScoreProvinces.c:781-787, inside the
    # outer-power loop, each iteration only writes its own power's row but
    # over the full outer-loop sweep every power gets its units marked).
    # The previous port only set own_power's row, leaving other powers' rows
    # at zero after Section 1's fill(0).  This broke any consumer that reads
    # `np.sum(g_sc_ownership[p])` for p != own_power — most visibly
    # Adjustment 8's owner_scs check and any SC-count-based heuristic.
    for prov, info in state.unit_info.items():
        power = info['power']
        state.g_sc_ownership[power, prov] = 1

    # Section 4 — per-power outer loop: alliance-gated reach → scored tables
    for outer_power in range(num_powers):
        for prov in range(num_provinces):
            for inner_power in range(num_powers):
                reach = int(reachability[prov, inner_power])
                if reach == 0:
                    continue

                trust_lo = float(state.g_ally_trust_score[outer_power, inner_power])
                # g_ally_history_count = g_relation_score (DAT_00634e90);
                # fixed 2026-04-14 — previously hardcoded to 0.
                history = int(state.g_relation_score[outer_power, inner_power])

                if inner_power == outer_power:
                    if trust_lo == 0:
                        state.g_own_reach_score[outer_power, prov] = reach
                else:
                    # Threat (best enemy reach)
                    if reach > state.g_threat_level[outer_power, prov]:
                        if (trust_lo == 0 and history == 0) or history < 10 or trust_lo >= 0:
                            state.g_threat_level[outer_power, prov] = reach

                    # Ally reach (trust > 0 or established history)
                    if trust_lo > 0 or history > 3:
                        state.g_ally_reach_score[outer_power, prov] += reach

                    # Enemy reach (uncertain trust)
                    if trust_lo <= 0:
                        state.g_enemy_reach_score[outer_power, prov] += reach

                    state.g_total_reach_score[outer_power, prov] += reach

        # Section 4a — friendly/established-ally unit flags (updated 2026-04-21)
        # C indexes these as [outer_power * 0x100 + prov], making them 2D.
        # For each unit: if trust >= 0, set g_friendly_unit_flag[outer_power, prov] = 1.
        # If relation <= 9 (established ally), also set g_established_ally_flag[outer_power, prov] = 1.
        for prov, info in state.unit_info.items():
            unit_power = info['power']
            if unit_power == outer_power:
                continue  # own units don't get friendly/ally flags
            trust = float(state.g_ally_trust_score[outer_power, unit_power])
            if trust < 0:
                # Hostile unit — no flags set
                continue
            # Non-hostile unit (trust >= 0) → set friendly flag
            state.g_friendly_unit_flag[outer_power, prov] = 1
            # Check established ally flag (relation <= 9)
            try:
                relation = int(state.g_relation_score[outer_power, unit_power])
            except (AttributeError, IndexError, TypeError):
                relation = 0
            if relation <= 9:
                state.g_established_ally_flag[outer_power, prov] = 1

        # Section 4b — occupation scoring init
        for prov, info in state.unit_info.items():
            if info['power'] == outer_power:
                weight = 1 if state.g_other_power_lead_flag else 5
                # g_ProvinceScore2 approximated via g_attack_count
                state.g_attack_count[outer_power, prov] = float(weight)

        # Section 4e — convoy/mobility counts (C: uncertain-trust fleet gate)
        # Updated 2026-04-14: adds the `g_ally_trust_score < 1 AND < 0` test
        # (uncertain-trust fleet) that gates the 2-hop expansion in C. Prior
        # port expanded through every adjacency, over-counting by ~4x.
        for prov, info in state.unit_info.items():
            for adj in state.get_unit_adjacencies(prov):
                adj_power = state.get_unit_power(adj)
                if adj_power == -1:
                    continue
                # C gate: the unit at `adj` must be a fleet of uncertain trust.
                # Uncertain ≈ trust score unknown (< 1) AND hi-word < 0.
                trust_lo = float(state.g_ally_trust_score[outer_power, adj_power])
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, adj_power])
                if not (trust_lo < 1 and trust_hi < 0):
                    continue
                # Filter to fleet units only (C calls AdjacencyList_FilterByUnitType)
                if state.get_unit_type(adj) != 'F':
                    continue
                for adj2 in state.get_unit_adjacencies(adj):
                    if (g_unit_presence[prov] == 1
                        and state.g_sc_ownership[own_power, adj2] == 0):
                        state.g_convoy_reach_count[own_power, adj2] += 1
                    if info['power'] != own_power:
                        state.g_enemy_mobility_count[own_power, adj2] += 1

        # Section 4h — province score assignment (main scoring pass)
        # Updated 2026-04-14: now runs for every `outer_power` (not just
        # `own_power`), mirroring C's per-power iteration. This populates
        # g_attack_count[power, prov] for all powers, giving Albert a
        # per-opponent view of province priorities.
        #
        # Extended 2026-04-14 (pass 3): all 8 Section 4h post-adjustments
        # from ScoreProvinces.c lines 1000-1228 now ported:
        #   (1) home-center + has_adj_enemy clamp          → 80 / 150
        #   (2) ally territory /3 or zero                   → 0 or score/3
        #   (3) influence ratio boost (>0.95, near_end<3)   → 10
        #   (4) opening target match (score==0)             → 150
        #   (5) non-home-center unit-owner score            → 10 or 1
        #   (6) late-game trusted-ally suppression          → 0
        #   (7) free-province neighbor-SC heuristic         → 75 / 75·trust⁻¹
        #   (8) WIN sticky + SC-count bump                  → 5 ± 20/5
        # Symbol mappings (from GlobalDataRefs.md):
        #   DAT_00b85768 → g_press_matrix, DAT_00b85710 → g_press_count,
        #   DAT_004d2e14 → g_ally_designation_a hi-word,
        #   g_opening_sticky_mode already in state.
        # Remaining divergence: 10-round BFS propagation (C 492-638)
        # seeds +0x361c with AttackCount * DAT_006040ec and smooths 10
        # rounds.  Python populates g_candidate_scores from a 5-round
        # BFS on own-unit presence (apply_influence_scores, Phase 1f) —
        # different seed, rounds, and kernel.  Impact is low: WIN
        # phases overwrite g_candidate_scores, and non-WIN consumers
        # only use it as a boolean membership gate.  Re-audit
        # 2026-04-14 confirmed no value-level consumer in non-WIN
        # paths, so porting the C BFS would change boolean membership
        # at the edges but not any currently-read score value.

        # Precompute once per outer_power: does outer_power own any SC
        # where the unit on that SC is NOT outer_power's?  (C local_5581
        # flag, ScoreProvinces.c:953-977.)
        # C logic: iterate alive provinces; for each, look up outer_power
        # in the province power-record (GameBoard_GetPowerRec).  If found
        # (outer_power owns the SC) AND the unit there is not outer_power
        # → set flag.  An empty province counts (unit_power defaults to
        # 0x14 in C, which != any valid outer_power).
        # Fixed 2026-04-28: was checking home_power != sc_owner; must
        # check outer_power SC ownership instead.
        local_5581_flag = False
        for alive_prov in range(num_provinces):
            if state.g_sc_ownership[outer_power, alive_prov] == 1:
                uowner_a = (state.get_unit_power(alive_prov)
                            if alive_prov in state.unit_info else -1)
                if uowner_a != outer_power:
                    local_5581_flag = True
                    break

        near_end = float(state.g_near_end_game_factor)

        # Debug: log flag and state for Germany (power 3)
        _is_dbg = _dbg_log.isEnabledFor(logging.DEBUG) and outer_power == 3
        if _is_dbg:
            id2n = getattr(state, '_id_to_prov', {})
            _dbg_log.debug(
                "SCORE_DBG[GER] local_5581_flag=%s  near_end=%.1f  "
                "sc_ownership_GER=%s",
                local_5581_flag, near_end,
                [id2n.get(p, str(p)) for p in range(num_provinces)
                 if state.g_sc_ownership[3, p] == 1],
            )

        # Broadened 2026-04-14 (pass 2) to all 256 provinces — matches C's
        # per-alive-province iteration (ScoreProvinces.c:982-991) so that
        # Adjustments 4 (opening target) and 5/6 (unit-owner branch) can
        # fire on provinces that are neither SC-owned nor unit-occupied
        # by outer_power.
        # C only enters the scoring body when the province "alive" flag
        # is non-zero (*(char*)(board + 3 + prov*0x24) != '\0').  Non-map
        # provinces (IDs > ~81 on standard map) stay at g_attack_count = 0.
        prov_iter = valid_provs if valid_provs else range(num_provinces)
        for prov in prov_iter:
            uowner_here = (state.get_unit_power(prov)
                           if prov in state.unit_info else -1)

            # Determine if EvaluateProvinceScore is called (C logic)
            is_own_or_ally = False
            if uowner_here == outer_power:
                is_own_or_ally = True
            elif uowner_here != -1:
                trust_lo = float(state.g_ally_trust_score[outer_power, uowner_here])
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, uowner_here])
                if trust_hi >= 0 and (trust_hi > 0 or trust_lo >= 2):
                    is_own_or_ally = True

            if is_own_or_ally:
                score = float(evaluate_province_score(state, prov, outer_power))
                
                # Adjustment 1 — SC ownership / non-SC clamp (C 1006-1021).
                # C: GameBoard_GetPowerRec checks if outer_power is in the
                # province's SC-ownership set.
                #   found (outer_power owns SC) → score > 15 & flag → 150
                #   not found                   → score != 0 & flag → 80
                # Fixed 2026-04-28: was using home_power == sc_owner; must
                # use outer_power SC ownership.
                outer_owns_this_sc = (state.g_sc_ownership[outer_power, prov] == 1)

                if outer_owns_this_sc:
                    if score > 15.0 and local_5581_flag:
                        score = 150.0
                else:
                    if score != 0.0 and local_5581_flag:
                        score = 80.0

                # Adjustment 2 — ally territory /3 or zero (C 1022-1042).
                # C gates this with: unit_power != outer_power AND
                #   trust_hi >= 0 AND (trust_hi > 0 OR trust_lo > 4) AND
                #   ally_designation_b[prov] == unit_power (with hi == 0).
                # Inside that gate, C further checks a threat-level field:
                #   if threat <= 0 → score = 0; else → score /= 3.
                # Fixed 2026-04-28: was unconditional; now gated.
                if uowner_here != -1 and uowner_here != outer_power:
                    trust_lo_a2 = float(state.g_ally_trust_score[outer_power, uowner_here])
                    trust_hi_a2 = int(state.g_ally_trust_score_hi[outer_power, uowner_here])
                    desig_b = int(state.g_ally_designation_b[prov])
                    desig_b_hi = int(state.g_ally_designation_b_hi[prov])
                    if (trust_hi_a2 >= 0
                            and (trust_hi_a2 > 0 or trust_lo_a2 > 4)
                            and desig_b == uowner_here
                            and desig_b_hi == 0):
                        # Sub-condition: check threat level at [uowner, prov].
                        thr = int(state.g_threat_level[uowner_here, prov])
                        if thr <= 0:
                            score = 0.0
                        else:
                            score /= 3.0

                # Adjustment 3 — influence ratio boost.
                if near_end < 3.0:
                    cov = int(state.g_coverage_flag[outer_power, prov])
                    tot = 0
                    for p in range(num_powers):
                        tot += int(state.g_coverage_flag[p, prov])
                    if tot > 0 and (cov / tot) > 0.95:
                        score += 10.0
            else:
                score = 2.0  # Base score for untrusted or unoccupied (C 1061)

            # Adjustment 4 — opening target match (applies to unoccupied / untrusted).
            if score == 0.0 or uowner_here == -1:
                ot = getattr(state, 'g_opening_target', None)
                if ot is not None and ot[outer_power] == prov:
                    score = 150.0

            # Adjustment 7 — unoccupied province match / default (C 1071-1149).
            # Fixed 2026-04-28: Removed `not is_home_center` gating which broke S1902 unoccupied SC logic.
            if (uowner_here == -1
                    and hasattr(state, 'g_press_matrix')
                    and hasattr(state, 'g_press_count')
                    and score != 150.0):
                # Check if any non-outer power has presence here.
                any_presence = any(
                    p != outer_power and int(state.g_press_matrix[p, prov]) > 0
                    for p in range(num_powers)
                )
                if not any_presence:
                    score = 75.0  # 0x4b — default
                else:
                    own_here = int(state.g_press_matrix[outer_power, prov]) > 0
                    best = 0.0
                    capped = False
                    for p in range(num_powers):
                        if p == outer_power:
                            continue
                        if int(state.g_press_matrix[p, prov]) <= 0:
                            continue
                        tlo = float(state.g_ally_trust_score[outer_power, p])
                        thi = int(state.g_ally_trust_score_hi[outer_power, p])
                        uncertain_p = (thi < 1 and (thi < 0 or tlo < 2))
                        if uncertain_p:
                            capped = True
                            break
                        if own_here and int(state.g_press_count[p]) > 1:
                            capped = True
                            continue
                        if tlo <= 0:
                            capped = True
                            continue
                        ratio = 100.0 / tlo
                        if ratio > best:
                            best = 75.0 / tlo
                    score = 75.0 if capped else best

            # Adjustment 5 — non-SC-owned unit owner score (C 1150-1161).
            # Occupied-by-other-power path: trust-uncertain → 10, ally → 1.
            is_owned_sc = (state.g_sc_ownership[outer_power, prov] == 1)
            if (not is_owned_sc and uowner_here != -1
                    and uowner_here != outer_power):
                trust_lo = float(state.g_ally_trust_score[outer_power, uowner_here])
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, uowner_here])
                uncertain = (trust_hi < 0
                             or (trust_hi < 1 and trust_lo < 2))
                score = 10.0 if uncertain else 1.0

                # Adjustment 8 — WIN sticky + SC-count bump (C 1162-1199).
                # Fires when outer_power owns > 2 supply centres.
                own_scs = int(np.sum(state.g_sc_ownership[outer_power]))
                if own_scs > 2:
                    deceit = int(getattr(state, 'g_deceit_level', 0))
                    sticky = int(getattr(state, 'g_opening_sticky_mode', 0))
                    season = getattr(state, 'g_season', 'SPR')
                    if (deceit < 2 and outer_power == own_power
                            and season == 'WIN' and sticky == 1
                            and not uncertain):
                        score = 5.0
                    # (else branch would call PackScoreU64 — left as current
                    #  `score` per user filter on RNG/FP parity.)
                    # Neighbor SC-count bump.
                    owner_scs = int(np.sum(state.g_sc_ownership[uowner_here]))
                    wt = int(getattr(state, 'win_threshold', 18)) or 18
                    if owner_scs < 2:
                        score += 20.0
                    elif (owner_scs * 100) // wt > 12:
                        score += 5.0

                # Adjustment 6 — late-game trusted-ally suppression
                # (C 1203-1207).  Nested inside Adjustment 5's branch.
                if (near_end > 5.0 and trust_hi >= 0
                        and (trust_hi > 0 or trust_lo > 10)):
                    score = 0.0

            # Adjustment 9 — SC ownership override (C 1209-1228).
            # FINAL adjustment: if outer_power owns this SC, override:
            #   own unit present → 90; other/empty → 150.
            # C: GameBoard_GetPowerRec; if found (outer_power in power-
            # record), check unit type at province.
            if state.g_sc_ownership[outer_power, prov] == 1:
                if uowner_here == outer_power:
                    score = 90.0
                else:
                    score = 150.0

            # Debug: log non-zero scores for Germany
            if _is_dbg and score > 0:
                _pn = id2n.get(prov, str(prov))
                _dbg_log.debug(
                    "SCORE_DBG[GER] prov=%-4s score=%6.1f  uowner=%d  "
                    "is_own_ally=%s  owns_sc=%d  adj9_fired=%s",
                    _pn, score, uowner_here,
                    is_own_or_ally if 'is_own_or_ally' in dir() else '?',
                    int(state.g_sc_ownership[outer_power, prov]),
                    state.g_sc_ownership[outer_power, prov] == 1,
                )

            state.g_attack_count[outer_power, prov] = score
            # max-accumulate — only track global max from own_power's
            # perspective (C mirrors this via the Albert-specific max
            # tracker in Phase 5).
            if outer_power == own_power and score > state.g_max_province_score[prov]:
                state.g_max_province_score[prov] = score


# ── ScoreOrderCandidates: candidate-vs-press corroboration penalty ───────────
#
# Port of Source/ScoreOrderCandidates.c lines 342–630 — the matching/penalty
# pass that runs AFTER ProcessTurn has populated g_candidate_record_list and
# AFTER score_order_candidates_from_broadcast has populated g_general_orders /
# g_alliance_orders from the inbound DAIDE press.
#
# Semantics (collapsed from the four nested loops in C):
#   For each candidate at province V where V holds a unit AND that unit's
#   power has any received-press orders (i.e. local_3fc[power] non-empty in
#   C, equivalently state.g_general_orders[power] non-empty in Python):
#     scan received-press orders for that power; if NONE references V as
#     either the unit-province or the support/convoy target, the candidate
#     is considered to disagree with announced press → mark
#       record['type_flag'] = 1
#       record['score']     = -2.5e36  (C: 0xff676980 = -2.5e36 as float)
#     This makes MC's downstream selector skip the candidate.
#
# The full C version distinguishes local_3fc (general XDO), local_204 (own
# alliance XDO), local_300 (SUP-MTO), local_108 (SUP-HLD) and routes the
# match through GameBoard_GetPowerRec to skip already-committed orders.
# That granularity is collapsed here because:
#   (a) g_general_orders is the union local_3fc∪local_300∪local_108 keyed by
#       proposer power — already populated by score_order_candidates_from_broadcast.
#   (b) g_alliance_orders is the local_204 analogue — same writer.
#   (c) The "already on board" gate (puVar8[1] != iVar18) is implicit in
#       Python because g_board_orders is consulted separately by the MC
#       dispatch path; double-penalising committed orders is harmless since
#       MC doesn't re-pick them.

_PRESS_DISAGREE_PENALTY: float = -2.5e36   # C: 0xff676980 reinterpreted as f32


def apply_press_corroboration_penalty(state: InnerGameState) -> int:
    """
    Penalise g_candidate_record_list entries whose orders disagree with
    received-press orders for the same province/unit-power.  Returns the
    number of candidates penalised.

    Mirrors the post-ProcessTurn matching pass in
    Source/ScoreOrderCandidates.c (lines 342–630), collapsed to operate
    over the already-populated g_general_orders / g_alliance_orders maps
    rather than re-staging them into per-province RB-trees.
    """
    received_general: dict = getattr(state, 'g_general_orders', {}) or {}
    received_alliance: dict = getattr(state, 'g_alliance_orders', {}) or {}
    candidates: list = getattr(state, 'g_candidate_record_list', []) or []
    if not candidates or (not received_general and not received_alliance):
        return 0

    # Build per-power province-mention sets from received press orders.
    # An order "mentions" a province if the province appears as either the
    # unit's source, an MTO/CTO destination, a SUP/CVY target unit, or a
    # SUP/CVY destination.  This is the union of the four staging trees in C.
    #
    # _parse_xdo_body_to_order stores province NAMES (e.g. "LON") in the
    # 'unit'/'target'/'target_unit'/'target_dest' fields, while candidate
    # records use integer province IDs.  Translate via state.prov_to_id so
    # both halves speak the same vocabulary.
    prov_to_id: dict = getattr(state, 'prov_to_id', {}) or {}

    def _name_to_id(s):
        # Accepts either an int (already an ID), a "U PROV" unit string, or
        # a bare province name.  Returns int or None.
        if isinstance(s, int):
            return s
        if not isinstance(s, str):
            return None
        # Unit strings carry the unit type prefix: "A LON" / "F NTH".
        if len(s) >= 3 and s[1] == ' ':
            s = s[2:]
        return prov_to_id.get(s)

    def _mentioned_provs(order_seq: dict) -> set:
        out = set()
        for k in ('source', 'unit_prov', 'province', 'unit'):
            pid = _name_to_id(order_seq.get(k))
            if pid is not None:
                out.add(pid)
        for k in ('dest', 'target', 'target_unit', 'target_dest',
                  'convoy_leg0', 'convoy_leg1', 'convoy_leg2'):
            pid = _name_to_id(order_seq.get(k))
            if pid is not None:
                out.add(pid)
        return out

    press_by_power: dict = {}
    for source in (received_general, received_alliance):
        for power_idx, order_list in source.items():
            bucket = press_by_power.setdefault(int(power_idx), set())
            for entry in order_list or []:
                if not isinstance(entry, dict):
                    continue
                # order_seq is stored either nested under 'order_seq' (if the
                # caller wrapped it) or flat (the score_order_candidates_from_
                # broadcast writer appends the order dict directly).
                seq = entry.get('order_seq', entry)
                if isinstance(seq, dict):
                    bucket |= _mentioned_provs(seq)

    if not press_by_power:
        return 0

    penalised = 0

    # Python's g_candidate_record_list differs structurally from C's: the C list
    # is one record per (power, province, ordered-action), whereas Python
    # collapses each ProcessTurn trial into a single whole-power candidate
    # `{'power': p, 'orders': [(prov, order_type, dest, dest_coast, secondary), ...]}`.
    # To preserve C's "candidate at V disagrees with announced press" semantics
    # under that collapse, walk each candidate's orders and penalise the whole
    # trial if ANY of its unit-provinces falls outside the press-mentioned set
    # for the candidate's own power.  Press from OTHER powers can never trigger
    # the penalty because a candidate of P only carries P's own orders.
    for record in candidates:
        # Already penalised on a prior pass — don't double-count.
        if record.get('type_flag', 0) == 1:
            continue
        power_idx = record.get('power')
        if power_idx is None:
            continue
        bucket = press_by_power.get(int(power_idx))
        if not bucket:
            # No press from this power → C's local_3fc[power] empty branch:
            # corroboration is vacuously satisfied; do not penalise.
            continue
        orders = record.get('orders') or []
        # Each entry is (prov, order_type, dest_prov, dest_coast, secondary).
        # The unit's province is the first element.
        disagrees = False
        for o in orders:
            try:
                prov = int(o[0]) if not isinstance(o, int) else int(o)
            except (TypeError, IndexError, ValueError):
                continue
            if prov not in bucket:
                disagrees = True
                break
        if disagrees:
            record['type_flag'] = 1
            record['score'] = _PRESS_DISAGREE_PENALTY
            penalised += 1

    return penalised


# ── ScoreOrderCandidates_OwnPower ─────────────────────────────────────────────

def score_order_candidates_own_power(state: InnerGameState,
                                     weight_vector: list,
                                     own_power: int) -> None:
    """
    Port of ScoreOrderCandidates_OwnPower (FUN_004498d0).

    Scores order candidates for own power only (lighter than the all-powers
    version).  Three passes: dot-product, normalise + max-accumulate,
    army dithering.

    Research.md §1624.
    """
    import random as _random

    num_provinces = 256

    # Pass 1 — dot product of weight_vector × candidate ordered sets
    local_max = 0.0
    scores: dict = {}

    for prov in range(num_provinces):
        if not state.candidate_set_contains(own_power, prov):
            continue
        score = 0.0
        for i, w in enumerate(weight_vector[:10]):
            score += w * state.get_candidate_score(own_power, prov, i)
        # add base province score
        score += float(state.g_attack_count[own_power, prov]) * float(weight_vector[0]) \
                 if weight_vector else 0.0
        scores[prov] = score
        if score > local_max:
            local_max = score

    if local_max <= 0.0:
        local_max = 1.0

    # Pass 2 — normalise to [0, 1000] + max-accumulate into g_max_province_score
    for prov, score in scores.items():
        normalized = int(score * 1000 / local_max)
        scores[prov] = normalized
        if normalized > state.g_max_province_score[prov]:
            state.g_max_province_score[prov] = float(normalized)

    # Pass 3 — army dithering: armies below global max get randomized
    for prov, normalized in scores.items():
        if state.get_unit_type(prov) == 'A':
            if normalized < state.g_max_province_score[prov]:
                scores[prov] = _random.randint(0, 2 ** 32 - 1)

    # Write back into g_candidate_scores for own power
    for prov, val in scores.items():
        state.g_candidate_scores[own_power, prov] = float(val)
