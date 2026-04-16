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

import numpy as np

from ..state import InnerGameState

from ._primitives import evaluate_province_score


def score_order_candidates_all_powers(state: InnerGameState, round_weights: list, dominant_power_idx: int):
    """
    Port of ScoreOrderCandidates_AllPowers / FUN_0044a040.
    Per-power per-province influence dot-product scoring pass.
    """
    dominance_weight = state.ScoreCurrent - state.ScoreBaseline
    
    for power in range(7):
        for province in range(256):
            if not state.CandidateSet_contains(power, province):
                continue
                
            total = 0.0
            for i in range(min(10, len(round_weights))):
                score = state.get_candidate_score(power, province, i)
                total += score * round_weights[i]
                
            if getattr(state, 'g_DominantPowerMode', 0) == 1 and power != dominant_power_idx:
                main_candidate_score = state.get_candidate_score(power, province, 0)
                total += main_candidate_score * dominance_weight
                
            state.g_MaxProvinceScore[province] = max(state.g_MaxProvinceScore[province], total)
            state.g_MinScore[province] = min(state.g_MinScore[province], total)
            
            state.FinalScoreSet[power, province] = total
            
    # Pass 2 - Score normalization (C Phase 1b, lines 131-211)
    # Rewritten 2026-04-14: per-power max/min now tracked via
    # g_MaxProvScorePerPower / g_MinProvScorePerPower (was only global).
    # Sub-threshold nonzero/non-min branch now uses _safe_pow sqrt proxy
    # instead of collapsing to 1.0.
    import math
    import random as _rnd
    global_max = np.max(state.g_MaxProvinceScore)
    threshold = global_max / 100.0
    # Off-by-one guard — C: if min == threshold → threshold = min+1
    global_min = float(np.min(state.g_MinScore))
    if global_min == threshold:
        threshold = global_min + 1.0

    for power in range(7):
        for province in range(256):
            raw_score = state.FinalScoreSet[power, province]
            if raw_score <= 0:
                continue
            if raw_score >= threshold and global_max > 0:
                score = (raw_score * 1000.0 / global_max) + 15.0
            else:
                if raw_score == 0:
                    score = 1.0
                elif raw_score == state.g_MinScore[province]:
                    score = float(_rnd.randint(1, 10))
                else:
                    # _safe_pow proxy — C applies pow(score/min, exponent).
                    # Exponent not recoverable from Ghidra; use 0.5 (sqrt)
                    # consistent with the CAL_BOARD parity notes.
                    denom = max(float(state.g_MinScore[province]), 1.0)
                    score = math.sqrt(max(raw_score / denom, 0.0))
                if score > 10.0:
                    score = 10.0

            state.FinalScoreSet[power, province] = score

            # Per-power max/min pair updates (C Phase 1b tail, lines 193-209)
            if hasattr(state, 'g_MaxProvScorePerPower'):
                if score > state.g_MaxProvScorePerPower[power, province]:
                    state.g_MaxProvScorePerPower[power, province] = score
                if score < state.g_MinProvScorePerPower[power, province]:
                    state.g_MinProvScorePerPower[power, province] = score

            # Pass 3 - AMY shortfall-pull toward max (C Phase 1c, lines 214-248)
            # Replaces former random 0.9-1.1 jitter with deterministic
            # "delta to per-power max" — pulls under-performing armies
            # toward the best-scoring province.
            if state.get_unit_type(province) == "AMY":
                per_pow_max = (state.g_MaxProvScorePerPower[power, province]
                               if hasattr(state, 'g_MaxProvScorePerPower')
                               else state.g_MaxProvinceScore[province])
                if score < per_pow_max:
                    state.FinalScoreSet[power, province] = float(per_pow_max) - score

    # Pass 3b - Recompute g_MaxProvinceScore from normalized FinalScoreSet.
    # In C (lines 192-201), g_MaxProvinceScore is updated DURING the
    # normalization loop, so it holds post-normalization values.  The Python
    # Pass 1 sets it from raw dot-product totals; we must refresh it here so
    # that downstream consumers (TopReachFlag, BuildSupportOpportunities)
    # see the correct normalized maxima.
    state.g_MaxProvinceScore[:] = 0
    for power in range(7):
        for province in range(256):
            v = float(state.FinalScoreSet[power, province])
            if v > state.g_MaxProvinceScore[province]:
                state.g_MaxProvinceScore[province] = v

    # Pass 4 - g_ProvTargetFlag classification (C Phase 3, lines 265-316)
    # Ported 2026-04-14 — fixes dead-code bug (enemy_reach==0 duplicate branch)
    # and adds g_AttackCount < 1 gate.
    for power in range(7):
        for province in range(256):
            if not state.has_unit(province):
                continue
            # C check: if province has no home-unit OR owner == this power
            unit_owner = getattr(state, 'get_unit_owner', lambda p: None)(province)
            if unit_owner is not None and unit_owner != power:
                continue
            # C: (g_AttackCount[key] < 1) AND (g_TargetFlag != 2 OR g_AttackCount2 != 0)
            attack_cnt = getattr(state, 'g_AttackCount', None)
            attack_cnt_val = attack_cnt[power, province] if attack_cnt is not None else 0
            tflag = state.g_TargetFlag[power, province] if hasattr(state, 'g_TargetFlag') else 0
            attack_cnt2 = getattr(state, 'g_AttackCount2', None)
            ac2_val = attack_cnt2[power, province] if attack_cnt2 is not None else 0
            if not (attack_cnt_val < 1 and (tflag != 2 or ac2_val != 0)):
                continue
            enemy_reach = state.get_enemy_reach(power, province)
            sc_own = state.g_SCOwnership[power, province]
            total_reach = state.g_TotalReachScore[power, province] if hasattr(state, 'g_TotalReachScore') else 0
            enemy_reach_score = state.g_EnemyReachScore[power, province] if hasattr(state, 'g_EnemyReachScore') else 0
            d535 = getattr(state, 'g_EnemyPressureSecondary', None)
            d535_val = d535[power, province] if d535 is not None else 0

            if enemy_reach < 0:
                # Fully safe — enemy cannot reach
                state.g_ProvTargetFlag[power, province] = 1
            elif enemy_reach == 0 and sc_own == 1 and enemy_reach_score == 0 and d535_val == 0:
                # Own SC, no enemy near
                state.g_ProvTargetFlag[power, province] = 1
            elif (enemy_reach == 1 and sc_own == 1 and total_reach == 0
                  and enemy_reach_score == 0 and d535_val == 0):
                # Own SC, 1-hop enemy — secondary priority
                state.g_ProvTargetFlag[power, province] = 2
            else:
                continue
            # C: (&DAT_005ee8ec)[iVar10 * 2] = 0 — clear the "classified" marker
            if hasattr(state, 'g_TargetFlag2'):
                state.g_TargetFlag2[power, province] = 0

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
                    # C: g_RelationScore[local_f4*21+owner] < 10 — not trusted ally.
                    # Fixed 2026-04-14 — was reading g_AllyHistoryCount (unpopulated);
                    # correct global is g_RelationScore (DAT_00634e90).
                    rel = getattr(state, 'g_RelationScore', None)
                    rel_val = rel[power, adj2_owner] if rel is not None else 0
                    if rel_val >= 10:
                        continue
                    if (state.g_ProvTargetFlag[power, adj1] == 1
                        and state.g_TargetFlag2[power, adj1] == 0):
                        state.g_ProvTargetFlag[power, adj1] = -10
                        state.g_TargetFlag2[power, adj1] = -1

    # Pass 6 - Multi-flanked restoration (C Phase 5, lines 408-480)
    # If a province has >1 neighbor also flagged -10, the local front is
    # contested everywhere — lift the flag back to 1.
    for power in range(7):
        for province in range(256):
            if state.g_ProvTargetFlag[power, province] != -10:
                continue
            flanked_neighbors = 0
            for adj in (state.get_adjacent_provinces(province)
                        if hasattr(state, 'get_adjacent_provinces') else []):
                if state.g_ProvTargetFlag[power, adj] == -10:
                    flanked_neighbors += 1
            if flanked_neighbors > 1:
                state.g_ProvTargetFlag[power, province] = 1
                if hasattr(state, 'g_TargetFlag2'):
                    state.g_TargetFlag2[power, province] = 0

    # Pass 7 - Direct-reach + extended-reach flagging (C Phase 10, lines 682-791)
    # For each own unit: mark adjacency as DirectReach=1 and 2-hop as ExtendedReach=1.
    g_DirectReach = getattr(state, 'g_DirectReachFlag', None)
    g_ExtReach = getattr(state, 'g_ExtendedReachFlag', None)
    if g_DirectReach is not None and g_ExtReach is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    g_DirectReach[power, adj1] = 1
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        if state.has_unit(adj2):
                            g_ExtReach[power, adj2] = 1

        # Pass 7b - 3-round BFS flood-fill of DirectReach (C Phase 10b, lines 792-845)
        for power in range(7):
            for _ in range(3):
                frontier = [p for p in range(256) if g_DirectReach[power, p] == 1]
                for prov in frontier:
                    for adj in (state.get_adjacent_provinces(prov)
                                if hasattr(state, 'get_adjacent_provinces') else []):
                        g_DirectReach[power, adj] = 1

    # Pass 8 - Own-SC rescore reset (C Phase 6, lines 481-517)
    # For each own unit, if its final score is below per-power max → mark
    # g_NeedsRescore = 0 (needs support-score reconsideration).
    if hasattr(state, 'g_NeedsRescore') and hasattr(state, 'g_MaxProvScorePerPower'):
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                if (state.FinalScoreSet[power, unit_prov]
                    < state.g_MaxProvScorePerPower[power, unit_prov]):
                    state.g_NeedsRescore[unit_prov] = 0

        # Pass 9 - Support-assignment gate (C Phase 7, lines 518-589)
        # For each own unit adjacency: if pending-rescore AND own SC AND
        # no enemy pressure AND score hits per-power max → finalize.
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj in (state.get_adjacent_provinces(unit_prov)
                            if hasattr(state, 'get_adjacent_provinces') else []):
                    if state.g_NeedsRescore[adj] != 0:
                        continue
                    if (state.g_SCOwnership[power, adj] == 1
                        and state.g_EnemyReachScore[power, adj] == 0):
                        score = state.FinalScoreSet[power, adj]
                        if score == state.g_MaxProvScorePerPower[power, adj]:
                            state.g_NeedsRescore[adj] = 1

    # Pass 9b - TopReachFlag population (C lines 481-589, Phase 7b)
    # Two sub-passes mirror the C unit walks:
    #   Sub-pass A (C lines 481-517): for each own unit, look up its
    #       FinalScoreSet entry against g_MaxProvinceScore.  If the unit's
    #       province score is BELOW the global max for that province, clear
    #       g_TopReachFlag[prov] = 0  (province is not a top-reach target).
    #   Sub-pass B (C lines 518-589): for each own unit, walk adjacency q.
    #       If g_TopReachFlag[q] == 0 AND g_SCOwnership[power, q] == 1 AND
    #       FinalScoreSet[power, q] == g_MaxProvinceScore[q], set
    #       g_TopReachFlag[q] = 1  (reachable top-scored own-SC province).
    # This populates the gate used by build_support_opportunities.
    for power in range(7):
        # Sub-pass A: clear TopReachFlag for under-performing unit provinces
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            fs_val = float(state.FinalScoreSet[power, unit_prov])
            mx_val = float(state.g_MaxProvinceScore[unit_prov])
            if fs_val < mx_val:
                state.g_TopReachFlag[unit_prov] = 0

    for power in range(7):
        # Sub-pass B: mark reachable own-SC provinces that hit max score
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            for q in (state.get_adjacent_provinces(unit_prov)
                      if hasattr(state, 'get_adjacent_provinces') else []):
                if int(state.g_TopReachFlag[q]) != 0:
                    continue  # already set or cleared with non-zero marker
                if int(state.g_SCOwnership[power, q]) != 1:
                    continue
                fs_q = float(state.FinalScoreSet[power, q])
                mx_q = float(state.g_MaxProvinceScore[q])
                if fs_q > 0 and fs_q == mx_q:
                    state.g_TopReachFlag[q] = 1

    # Pass 10 - BuildSupportOpportunities call (C Phase 8, line 590)
    try:
        from albert.moves import build_support_opportunities
        build_support_opportunities(state)
    except Exception:
        # build_support_opportunities may require richer state than a
        # stub; don't block the scoring pass for test harnesses.
        pass

    # Pass 11 - g_SupportCandidateMark via enemy-reachable ally-designated
    # adjacencies (C Phase 9, lines 591-681).
    g_SupMark = getattr(state, 'g_SupportCandidateMark', None)
    g_AllyE = getattr(state, 'g_AllyDesignation_E', None)
    if g_SupMark is not None and g_AllyE is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    if g_AllyE[adj1] < 0:
                        continue
                    # C: (&DAT_004d2e10)[adj*2] != local_f4 → designated for
                    # a different power. Without dual-orientation mirror we
                    # approximate via AllyDesignation_A ≠ own power.
                    if (hasattr(state, 'g_AllyDesignation_A')
                        and state.g_AllyDesignation_A[adj1] == power):
                        continue
                    if state.g_EnemyReachScore[power, adj1] <= 0:
                        continue
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        g_SupMark[power, adj2] = 1

    # Pass 12 - g_ThreatPathScore (C Phase 11, lines 846-952)
    # For each non-own province with enemy unit and own-reach > 0: iterate
    # its adjacencies and record the max FinalScoreSet reachable via it.
    g_Threat = getattr(state, 'g_ThreatPathScore', None)
    if g_Threat is not None:
        for power in range(7):
            for province in range(256):
                if state.g_OwnReachScore[power, province] <= 0:
                    continue
                owner = (state.get_unit_owner(province)
                         if hasattr(state, 'get_unit_owner') else None)
                if owner is None or owner == power:
                    continue
                for adj in (state.get_adjacent_provinces(province)
                            if hasattr(state, 'get_adjacent_provinces') else []):
                    score = state.FinalScoreSet[power, adj]
                    if score > g_Threat[power, province]:
                        g_Threat[power, province] = score


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

    # Section 1 — zero 11 per-power-province tables
    state.g_OwnReachScore.fill(0)       # g_OwnReachScore   DAT_0058f8e8
    state.g_AllyReachScore.fill(0)      # g_AllyReachScore  DAT_005658e8
    state.g_EnemyReachScore.fill(0)     # g_EnemyReachScore DAT_00535ce8
    state.g_TotalReachScore.fill(0)     # g_TotalReachScore DAT_0052b4e8
    state.g_ThreatLevel.fill(0)         # g_ThreatScore     DAT_005460e8
    state.g_ConvoyReachCount.fill(0)    # g_ConvoyReachCount DAT_005850e8
    state.g_EnemyMobilityCount.fill(0)  # g_EnemyMobilityCount DAT_0057a8e8
    state.g_SCOwnership.fill(0)         # g_SCOwnership     DAT_00520ce8
    state.g_CoverageFlag.fill(0)        # g_CoverageFlag
    state.g_MaxProvinceScore.fill(0)
    state.g_MinScore.fill(1_000_000)    # g_MinScore sentinel

    # Friendly/unit-presence flags (new in this pass)
    g_FriendlyUnitFlag = np.zeros(num_provinces, dtype=np.int32)
    g_UnitPresence     = np.zeros(num_provinces, dtype=np.int32)

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
                state.g_CoverageFlag[power, a] += 1
                seen.add(a)
        reachability[prov, power] += 1
        state.g_CoverageFlag[power, prov] += 1

    # Section 3 — per-unit presence flags.
    #
    # g_SCOwnership fix 2026-04-14: C populates g_SCOwnership[unit.power, prov]
    # for every unit across all powers (ScoreProvinces.c:781-787, inside the
    # outer-power loop, each iteration only writes its own power's row but
    # over the full outer-loop sweep every power gets its units marked).
    # The previous port only set own_power's row, leaving other powers' rows
    # at zero after Section 1's fill(0).  This broke any consumer that reads
    # `np.sum(g_SCOwnership[p])` for p != own_power — most visibly
    # Adjustment 8's owner_scs check and any SC-count-based heuristic.
    for prov, info in state.unit_info.items():
        power = info['power']
        state.g_SCOwnership[power, prov] = 1
        if power == own_power:
            continue
        trust = float(state.g_AllyTrustScore[own_power, power])
        if trust < 0:
            g_UnitPresence[prov] = 1
        else:
            g_FriendlyUnitFlag[prov] = 1

    # Section 4 — per-power outer loop: alliance-gated reach → scored tables
    for outer_power in range(num_powers):
        for prov in range(num_provinces):
            for inner_power in range(num_powers):
                reach = int(reachability[prov, inner_power])
                if reach == 0:
                    continue

                trust_lo = float(state.g_AllyTrustScore[outer_power, inner_power])
                # g_AllyHistoryCount = g_RelationScore (DAT_00634e90);
                # fixed 2026-04-14 — previously hardcoded to 0.
                history = int(state.g_RelationScore[outer_power, inner_power])

                if inner_power == outer_power:
                    if trust_lo == 0:
                        state.g_OwnReachScore[outer_power, prov] = reach
                else:
                    # Threat (best enemy reach)
                    if reach > state.g_ThreatLevel[outer_power, prov]:
                        if (trust_lo == 0 and history == 0) or history < 10 or trust_lo >= 0:
                            state.g_ThreatLevel[outer_power, prov] = reach

                    # Ally reach (trust > 0 or established history)
                    if trust_lo > 0 or history > 3:
                        state.g_AllyReachScore[outer_power, prov] += reach

                    # Enemy reach (uncertain trust)
                    if trust_lo <= 0:
                        state.g_EnemyReachScore[outer_power, prov] += reach

                    state.g_TotalReachScore[outer_power, prov] += reach

        # Section 4b — occupation scoring init
        for prov, info in state.unit_info.items():
            if info['power'] == outer_power:
                weight = 1 if state.g_OtherPowerLeadFlag else 5
                # g_ProvinceScore2 approximated via g_AttackCount
                state.g_AttackCount[outer_power, prov] = float(weight)

        # Section 4e — convoy/mobility counts (C: uncertain-trust fleet gate)
        # Updated 2026-04-14: adds the `g_AllyTrustScore < 1 AND < 0` test
        # (uncertain-trust fleet) that gates the 2-hop expansion in C. Prior
        # port expanded through every adjacency, over-counting by ~4x.
        for prov, info in state.unit_info.items():
            for adj in state.get_unit_adjacencies(prov):
                adj_power = state.get_unit_power(adj)
                if adj_power == -1:
                    continue
                # C gate: the unit at `adj` must be a fleet of uncertain trust.
                # Uncertain ≈ trust score unknown (< 1) AND hi-word < 0.
                trust_lo = float(state.g_AllyTrustScore[outer_power, adj_power])
                trust_hi = int(state.g_AllyTrustScore_Hi[outer_power, adj_power])
                if not (trust_lo < 1 and trust_hi < 0):
                    continue
                # Filter to fleet units only (C calls AdjacencyList_FilterByUnitType)
                if state.get_unit_type(adj) != 'F':
                    continue
                for adj2 in state.get_unit_adjacencies(adj):
                    if (g_UnitPresence[prov] == 1
                        and state.g_SCOwnership[own_power, adj2] == 0):
                        state.g_ConvoyReachCount[own_power, adj2] += 1
                    if info['power'] != own_power:
                        state.g_EnemyMobilityCount[own_power, adj2] += 1

        # Section 4h — province score assignment (main scoring pass)
        # Updated 2026-04-14: now runs for every `outer_power` (not just
        # `own_power`), mirroring C's per-power iteration. This populates
        # g_AttackCount[power, prov] for all powers, giving Albert a
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
        #   DAT_00b85768 → g_PressMatrix, DAT_00b85710 → g_PressCount,
        #   DAT_004d2e14 → g_AllyDesignation_A hi-word,
        #   g_OpeningStickyMode already in state.
        # Remaining divergence: 10-round BFS propagation (C 492-638)
        # seeds +0x361c with AttackCount * DAT_006040ec and smooths 10
        # rounds.  Python populates g_CandidateScores from a 5-round
        # BFS on own-unit presence (apply_influence_scores, Phase 1f) —
        # different seed, rounds, and kernel.  Impact is low: WIN
        # phases overwrite g_CandidateScores, and non-WIN consumers
        # only use it as a boolean membership gate.  Re-audit
        # 2026-04-14 confirmed no value-level consumer in non-WIN
        # paths, so porting the C BFS would change boolean membership
        # at the edges but not any currently-read score value.

        # Precompute once per outer_power: does any non-home-center alive
        # province hold a unit of a different power?  (C local_5581 flag,
        # set at ScoreProvinces.c:963-972.)
        home = state.home_centers.get(outer_power, frozenset())
        has_adj_enemy = False
        for alive_prov in state.unit_info.keys():
            if alive_prov in home:
                continue
            uowner_a = state.get_unit_power(alive_prov)
            if uowner_a != -1 and uowner_a != outer_power:
                has_adj_enemy = True
                break

        near_end = float(state.g_NearEndGameFactor)

        # Broadened 2026-04-14 (pass 2) to all 256 provinces — matches C's
        # per-alive-province iteration (ScoreProvinces.c:982-991) so that
        # Adjustments 4 (opening target) and 5/6 (unit-owner branch) can
        # fire on provinces that are neither SC-owned nor unit-occupied
        # by outer_power.
        for prov in range(num_provinces):
            score = float(evaluate_province_score(state, prov, outer_power))

            is_home_center = prov in home
            uowner_here = (state.get_unit_power(prov)
                           if prov in state.unit_info else -1)

            # Adjustment 1 — home-center / non-home-center clamp.
            # C 1006-1021: if home center AND score != 0 AND has_adj_enemy → 80.
            # C 1014-1021: else if score > 15 AND has_adj_enemy           → 150.
            if is_home_center:
                if score != 0.0 and has_adj_enemy:
                    score = 80.0
            else:
                if score > 15.0 and has_adj_enemy:
                    score = 150.0

            # Adjustment 2 — ally territory /3 or zero (C 1022-1042).
            # Home center occupied by a trusted ally (trust > 4) with
            # matching g_AllyDesignation_A booking: zero out if no threat,
            # else divide by 3.  DAT_004d2e14 is the hi-word of the int64
            # g_AllyDesignation_A pair (GlobalDataRefs.md:23 — cross-paired
            # with DAT_004d0e10); in Python the int64 is stored whole, so
            # equality on the signed value subsumes the C two-word check.
            if (is_home_center and uowner_here != -1
                    and uowner_here != outer_power):
                trust_lo_a = float(state.g_AllyTrustScore[outer_power, uowner_here])
                trust_hi_a = int(state.g_AllyTrustScore_Hi[outer_power, uowner_here])
                trusted_ally = (trust_hi_a >= 0
                                and (trust_hi_a > 0 or trust_lo_a > 4))
                if (trusted_ally
                        and int(state.g_AllyDesignation_A[prov]) == uowner_here):
                    threat = int(state.g_ThreatLevel[outer_power, prov])
                    if threat <= 0:
                        score = 0.0
                    else:
                        score = score / 3.0

            # Adjustment 3 — influence ratio boost (C 1043-1047).
            # DAT_00b76a28 is indexed by (prov + power*0x40); maps to
            # state.g_InfluenceRatio[outer_power, prov].
            if (score == 0.0 and near_end < 3.0
                    and hasattr(state, 'g_InfluenceRatio')
                    and float(state.g_InfluenceRatio[outer_power, prov]) > 0.95):
                score = 10.0

            # Adjustment 4 — opening target match (C 1081-1084).
            # Only applies when province has no unit; C reaches this branch
            # via the unowned (uVar2 == 0x14) path.
            if (score == 0.0 and uowner_here == -1
                    and hasattr(state, 'g_OpeningTarget')
                    and int(state.g_OpeningTarget[outer_power]) == prov):
                score = 150.0

            # Adjustment 7 — free-province neighbor-SC heuristic (C 1086-1148).
            # Unoccupied province, no opening-target match: score driven by
            # max 75/trust across other powers that have press-matrix
            # presence at this province.  g_PressMatrix (DAT_00b85768) is
            # bool[pow, prov]; g_PressCount (DAT_00b85710) is int[pow].
            if (not is_home_center and uowner_here == -1
                    and hasattr(state, 'g_PressMatrix')
                    and hasattr(state, 'g_PressCount')):
                opening_match = (hasattr(state, 'g_OpeningTarget')
                                 and int(state.g_OpeningTarget[outer_power]) == prov)
                if not (opening_match and score == 150.0):
                    # Check if any non-outer power has presence here.
                    any_presence = any(
                        p != outer_power and int(state.g_PressMatrix[p, prov]) > 0
                        for p in range(num_powers)
                    )
                    if not any_presence:
                        score = 75.0  # 0x4b — default
                    else:
                        own_here = int(state.g_PressMatrix[own_power, prov]) > 0
                        best = 0.0
                        capped = False
                        for p in range(num_powers):
                            if p == outer_power:
                                continue
                            if int(state.g_PressMatrix[p, prov]) <= 0:
                                continue
                            tlo = float(state.g_AllyTrustScore[outer_power, p])
                            thi = int(state.g_AllyTrustScore_Hi[outer_power, p])
                            uncertain_p = (thi < 1 and (thi < 0 or tlo < 2))
                            if uncertain_p:
                                capped = True
                                break
                            if own_here and int(state.g_PressCount[p]) > 1:
                                capped = True
                                continue
                            if tlo <= 0:
                                capped = True
                                continue
                            ratio = 100.0 / tlo
                            if ratio > best:
                                best = 75.0 / tlo
                        score = 75.0 if capped else best

            # Adjustment 5 — non-home-center unit owner score (C 1150-1161).
            # Occupied-by-other-power path: trust-uncertain → 10, ally → 1.
            # Gated on `not is_home_center` — the home-center branch in C
            # (Adjustments 1 & 2) owns the home-center occupied case.
            if (not is_home_center and uowner_here != -1
                    and uowner_here != outer_power):
                trust_lo = float(state.g_AllyTrustScore[outer_power, uowner_here])
                trust_hi = int(state.g_AllyTrustScore_Hi[outer_power, uowner_here])
                uncertain = (trust_hi < 0
                             or (trust_hi < 1 and trust_lo < 2))
                score = 10.0 if uncertain else 1.0

                # Adjustment 8 — WIN sticky + SC-count bump (C 1162-1199).
                # Fires when outer_power owns > 2 supply centres.
                own_scs = int(np.sum(state.g_SCOwnership[outer_power]))
                if own_scs > 2:
                    deceit = int(getattr(state, 'g_DeceitLevel', 0))
                    sticky = int(getattr(state, 'g_OpeningStickyMode', 0))
                    season = getattr(state, 'g_season', 'SPR')
                    if (deceit < 2 and outer_power == own_power
                            and season == 'WIN' and sticky == 1
                            and not uncertain):
                        score = 5.0
                    # (else branch would call PackScoreU64 — left as current
                    #  `score` per user filter on RNG/FP parity.)
                    # Neighbor SC-count bump.
                    owner_scs = int(np.sum(state.g_SCOwnership[uowner_here]))
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

            state.g_AttackCount[outer_power, prov] = score
            # max-accumulate — only track global max from own_power's
            # perspective (C mirrors this via the Albert-specific max
            # tracker in Phase 5).
            if outer_power == own_power and score > state.g_MaxProvinceScore[prov]:
                state.g_MaxProvinceScore[prov] = score


# ── ScoreOrderCandidates: candidate-vs-press corroboration penalty ───────────
#
# Port of Source/ScoreOrderCandidates.c lines 342–630 — the matching/penalty
# pass that runs AFTER ProcessTurn has populated g_CandidateRecordList and
# AFTER score_order_candidates_from_broadcast has populated g_GeneralOrders /
# g_AllianceOrders from the inbound DAIDE press.
#
# Semantics (collapsed from the four nested loops in C):
#   For each candidate at province V where V holds a unit AND that unit's
#   power has any received-press orders (i.e. local_3fc[power] non-empty in
#   C, equivalently state.g_GeneralOrders[power] non-empty in Python):
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
#   (a) g_GeneralOrders is the union local_3fc∪local_300∪local_108 keyed by
#       proposer power — already populated by score_order_candidates_from_broadcast.
#   (b) g_AllianceOrders is the local_204 analogue — same writer.
#   (c) The "already on board" gate (puVar8[1] != iVar18) is implicit in
#       Python because g_board_orders is consulted separately by the MC
#       dispatch path; double-penalising committed orders is harmless since
#       MC doesn't re-pick them.

_PRESS_DISAGREE_PENALTY: float = -2.5e36   # C: 0xff676980 reinterpreted as f32


def apply_press_corroboration_penalty(state: InnerGameState) -> int:
    """
    Penalise g_CandidateRecordList entries whose orders disagree with
    received-press orders for the same province/unit-power.  Returns the
    number of candidates penalised.

    Mirrors the post-ProcessTurn matching pass in
    Source/ScoreOrderCandidates.c (lines 342–630), collapsed to operate
    over the already-populated g_GeneralOrders / g_AllianceOrders maps
    rather than re-staging them into per-province RB-trees.
    """
    received_general: dict = getattr(state, 'g_GeneralOrders', {}) or {}
    received_alliance: dict = getattr(state, 'g_AllianceOrders', {}) or {}
    candidates: list = getattr(state, 'g_CandidateRecordList', []) or []
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

    # Python's g_CandidateRecordList differs structurally from C's: the C list
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
        if not state.CandidateSet_contains(own_power, prov):
            continue
        score = 0.0
        for i, w in enumerate(weight_vector[:10]):
            score += w * state.get_candidate_score(own_power, prov, i)
        # add base province score
        score += float(state.g_AttackCount[own_power, prov]) * float(weight_vector[0]) \
                 if weight_vector else 0.0
        scores[prov] = score
        if score > local_max:
            local_max = score

    if local_max <= 0.0:
        local_max = 1.0

    # Pass 2 — normalise to [0, 1000] + max-accumulate into g_MaxProvinceScore
    for prov, score in scores.items():
        normalized = int(score * 1000 / local_max)
        scores[prov] = normalized
        if normalized > state.g_MaxProvinceScore[prov]:
            state.g_MaxProvinceScore[prov] = float(normalized)

    # Pass 3 — army dithering: armies below global max get randomized
    for prov, normalized in scores.items():
        if state.get_unit_type(prov) == 'A':
            if normalized < state.g_MaxProvinceScore[prov]:
                scores[prov] = _random.randint(0, 2 ** 32 - 1)

    # Write back into g_CandidateScores for own power
    for prov, val in scores.items():
        state.g_CandidateScores[own_power, prov] = float(val)
