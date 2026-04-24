"""CAL_BOARD: per-power board calibration pass.

Split from heuristics.py during the 2026-04 refactor.

Single mega-function ``cal_board`` (port of CAL_BOARD) that refreshes
``state.g_InfluenceMatrix_Raw`` and the per-power reach/mobility/ownership
scores at the start of each turn.  Includes two nested helpers
(``_peace_signal_from``, ``_neutral``) defined inside the function body.

Module-level deps: ``numpy``, ``..state.InnerGameState`` only.  No calls
into other heuristics submodules.
"""

import numpy as np

from ..state import InnerGameState


def cal_board(state: InnerGameState, own_power: int) -> None:
    """
    Port of CAL_BOARD (FUN_00427960).

    Strategic board evaluation engine, called once per turn before order
    generation.  Computes:
      - _g_NearEndGameFactor
      - g_PowerExpScore  (super-exponential power score)
      - g_SCPercent      (SC percentage per power, relative to win_threshold)
      - g_EnemyCount     (genuine enemy count per power)
      - g_RankMatrix / g_AllyPrefRanking  (influence ranking)
      - g_EnemyFlag      (designated enemies for this turn)
      - g_LeadingFlag / g_OtherPowerLeadFlag / g_NearVictoryPower
      - g_RequestDrawFlag / g_StaticMapFlag
      - g_OneScFromWin
    """
    num_powers = 7
    win_threshold = int(state.win_threshold)
    if win_threshold == 0:
        win_threshold = 1  # guard against divide-by-zero

    trust_hi_mat = getattr(state, 'g_AllyTrustScore_Hi', np.zeros((7, 7), dtype=np.int64))

    # ── Phase 1a: per-power exponential score (Loop A in decompile) ──────────
    # g_PowerExpScore[k] = pow(min(sc_k, win_threshold), min(sc_k, win_threshold)) * 100 + 1
    for k in range(num_powers):
        sc = max(0, min(int(state.sc_count[k]), win_threshold))
        state.g_PowerExpScore[k] = (sc ** sc) * 100.0 + 1.0 if sc > 0 else 1.0

    # ── Phase 1b: NearEndGameFactor + g_SCPercent (Loop B in decompile) ──────
    # g_SCPercent[k] = sc[k] * 100 / win_threshold  (divisor = win threshold, NOT total SCs)
    # g_WarModeFlag reset to 0 before this loop (decompile line 121)
    state.g_WarModeFlag = 0
    near_end = 1.0

    own_sc = int(state.sc_count[own_power])
    # g_OneScFromWin checked before second loop (decompile line 118).
    # NOTE: log-only flag — no C read sites outside the archive-event write here
    # (CAL_BOARD event 0x28 family).  Kept for parity; do not remove.
    state.g_OneScFromWin = 1 if (win_threshold - own_sc == 1) else 0

    # Leader tracking (decompile lines 125-147): DAT_00624124 = index of lone
    # leader (unique max-SC power); -1 if two or more powers tie for most SCs.
    lead_pow = -1
    lead_sc = -1
    lead_tied = 0
    for k in range(num_powers):
        sc = int(state.sc_count[k])
        pct = sc * 100.0 / win_threshold
        state.g_SCPercent[k] = pct
        if pct > 80.0:
            state.g_WarModeFlag = 1

        # NearEndGameFactor: running max of (sc[k] - win_threshold + 9)
        factor = float(sc - win_threshold + 9)
        if factor > near_end:
            near_end = factor

        # Track lone leader
        if sc > lead_sc:
            lead_sc = sc
            lead_pow = k
            lead_tied = 1
        elif sc == lead_sc:
            lead_tied += 1

        # Zero g_EnemyFlag in this loop (decompile lines 126-127)
        state.g_EnemyFlag[k] = 0

    # Lone-lead-power: only set if unique; archive "The lone lead power is (%s)"
    # event (DAT_00bbf638 key 0x28) when applicable (decompile lines 157-195).
    # NOTE: g_LoneLeadPower is log-only — no C reads outside this archive event;
    # the value exists purely so the AllianceMsgTree-key-0x28 record is
    # reproducible.  Kept for parity; do not remove.
    if lead_tied < 2:
        state.g_LoneLeadPower = lead_pow
        try:
            state.g_AllianceMsgTree.add(0x28)  # lone-lead-power event code
        except Exception:
            pass
    else:
        state.g_LoneLeadPower = -1

    # Opening-ally-slot promotion (decompile lines 148-156): if slot 0's
    # power has been reduced below 2 SCs, promote slot 1 → 0, slot 2 → 1.
    try:
        s0 = int(getattr(state, 'g_BestAllySlot0', -1))
        s1 = int(getattr(state, 'g_BestAllySlot1', -1))
        s2 = int(getattr(state, 'g_BestAllySlot2', -1))
        if 0 <= s0 < num_powers and int(state.sc_count[s0]) < 2:
            state.g_BestAllySlot0 = s1
            state.g_BestAllySlot1 = s2 if s2 >= 0 else -1
            state.g_BestAllySlot2 = -1
    except Exception:
        pass

    # ── Phase 1c: NearEndGameFactor clamping ──────────────────────────────────
    # C logic (decompile lines 314-388):
    #   if (own_sc > 1 OR near_end >= 7.0):      ← outer TRUE → keep or set 5.0
    #       if (own_sc > 2 OR near_end >= 5.0):  ← inner TRUE → keep
    #       else:                                 ← inner FALSE → 5.0 (close to elimination)
    #   else:                                     ← outer FALSE → 8.0 (about to be eliminated)
    if own_sc > 1 or near_end >= 7.0:
        if not (own_sc > 2 or near_end >= 5.0):
            near_end = 5.0  # close to elimination
        # else: keep computed near_end
    else:
        near_end = 8.0  # about to be eliminated
    state.g_NearEndGameFactor = near_end

    # ── Phase 2: g_EnemyCount + g_RankMatrix init ────────────────────────────
    state.g_EnemyCount.fill(0)
    state.g_AllyDistressFlag.fill(0)
    state.g_RankMatrix.fill(-1)
    np.fill_diagonal(state.g_RankMatrix, -2)

    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = int(state.g_AllyTrustScore[row, col])
            trust_hi = int(trust_hi_mat[row, col])
            influence = float(state.g_InfluenceMatrix[row, col])
            col_sc = int(state.sc_count[col])
            if (trust_hi < 1
                    and (trust_hi < 0 or trust_lo < 2)
                    and influence > 0.0
                    and col_sc > 2):
                state.g_EnemyCount[row] += 1

    # ── Phase 3: top feared powers from influence matrix ─────────────────────
    own_influence_row = state.g_InfluenceMatrix[own_power].copy()
    own_influence_row[own_power] = -1.0  # exclude self
    top3 = sorted(range(num_powers), key=lambda k: own_influence_row[k], reverse=True)[:3]
    top_enemy_1 = top3[0] if len(top3) > 0 else own_power
    top_enemy_2 = top3[1] if len(top3) > 1 else own_power
    top_enemy_3 = top3[2] if len(top3) > 2 else own_power

    # ── Phase 4: find leading non-own power → local_fc / local_128 ───────────
    # local_fc  = int(g_SCPercent[leading_power]) — int-cast, like C FloatToInt64
    # local_128 = index of the non-own power with the highest SC%
    # (decompile lines 729-820; tie-breaking omitted — C uses trust/history)
    local_fc: int = -1
    local_128: int = own_power  # sentinel (own_power used when no rival found)
    for k in range(num_powers):
        if k == own_power:
            continue
        pct_int = int(state.g_SCPercent[k])   # FloatToInt64 truncates toward 0
        if pct_int > local_fc:
            local_fc = pct_int
            local_128 = k

    own_pct = float(state.g_SCPercent[own_power])

    # ── Phase 4a: draw / static-map request flags ─────────────────────────────
    # Decompile lines 821-876:
    #   local_fc >= 0x50(80) AND g_SCPercent[leading] > own_pct + 15  → draw
    #   local_fc >= 0x3c(60) AND g_SCPercent[leading] > own_pct + 25  → draw
    state.g_RequestDrawFlag = 0
    if local_128 != own_power:
        lead_pct = float(state.g_SCPercent[local_128])
        if local_fc >= 80 and lead_pct > own_pct + 15.0:
            state.g_RequestDrawFlag = 1
        elif local_fc >= 60 and lead_pct > own_pct + 25.0:
            state.g_RequestDrawFlag = 1
    if state.g_StaticMapFlag:
        state.g_RequestDrawFlag = 1

    # ── Phase 4b: near-victory enemy designation (local_fc > 0x3b = 59) ──────
    # Decompile lines 878-1090
    # NOTE: g_LeadingFlag is log-only — no C reads outside the archive-event
    # writes below; it exists so AllianceMsgTree leading-power events are
    # reproducible.  Kept for parity; do not remove.
    state.g_LeadingFlag = 0
    state.g_OtherPowerLeadFlag = 0
    # Reset DAT_0062480c under both aliases: CAL_BOARD.c:99 writes -1 (0xffffffff)
    # at the top of the function, so both views of the same global must agree.
    state.g_NearVictoryPower = -1
    state.g_CommittedEnemy   = -1

    bVar26 = False  # keep-alliance override
    if local_fc > 59 and local_128 != own_power:
        lead_pct = float(state.g_SCPercent[local_128])
        # Keep-alliance condition (bVar26):
        #   trust_hi >= 0 AND (trust_hi > 0 OR trust_lo > 11)
        #   AND g_PowerExpScore[own] - g_PowerExpScore[leading] * 1.7 + 69 > 0
        #   AND g_InfluenceRankFlag[own][leading] in {1, 2}
        trust_hi_val = int(trust_hi_mat[own_power, local_128])
        trust_lo_val = int(state.g_AllyTrustScore[own_power, local_128])
        rank_flag = int(state.g_InfluenceRankFlag[own_power, local_128])
        exp_own = float(state.g_PowerExpScore[own_power])
        exp_lead = float(state.g_PowerExpScore[local_128])
        if (trust_hi_val >= 0
                and (trust_hi_val > 0 or trust_lo_val > 11)
                and (exp_own - exp_lead * 1.7 + 69.0) > 0.0
                and rank_flag in (1, 2)):
            bVar26 = True

        # Declare near-victory only if leading is actually ahead and no keep-alliance
        if lead_pct > own_pct and not bVar26:
            state.g_OtherPowerLeadFlag = 1
            # DAT_0062480c is aliased in research.md as both g_NearVictoryPower
            # (CAL_BOARD write-site name) and g_CommittedEnemy (HOSTILITY read-site
            # name).  Mirror to both so HOSTILITY's committed-enemy check (strategy.py
            # :674 inside the mutual-enemy scan) sees the near-victory designation
            # that CAL_BOARD just made — matches single-address C semantics.
            state.g_NearVictoryPower = local_128
            state.g_CommittedEnemy   = local_128
            # Set leading power as enemy; zero trust toward them
            state.g_EnemyFlag[local_128] = 1
            state.g_AllyTrustScore[own_power, local_128] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, local_128] = 0
            # When local_fc >= 80: additionally zero trust *from* local_128 to all
            if local_fc >= 80:
                for p in range(num_powers):
                    if p != local_128:
                        state.g_AllyTrustScore[local_128, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[local_128, p] = 0
            bVar26 = True  # signal "near-victory enemy selected"

    # ── LAB_0042ac27: post-enemy-selection routing ────────────────────────────
    # When g_OtherPowerLeadFlag==1: run near-victory weak-elim then JUMP TO END
    # (skips gang-up, distressed-ally, weak-elim, dominance, alliance-agreement)
    # When g_OtherPowerLeadFlag==0: run all remaining passes

    if state.g_OtherPowerLeadFlag:
        # ── Near-victory post-pass (decompile lines 1815–1924) ───────────────
        # When local_fc > 75 OR leading_pct <= own_pct OR own_pct > 20:
        #   If local_fc < 86 AND own_pct < leading_pct AND own_pct > 20:
        #     mark powers with sc < 2 as enemy ("1 SC even though power close to victory")
        # Else (local_fc <= 75 AND leading_pct > own_pct):
        #   mark powers with sc < 2 OR weak influence as enemy
        if local_128 != own_power:
            lead_pct = float(state.g_SCPercent[local_128])
            if local_fc > 75 or lead_pct <= own_pct or own_pct > 20.0:
                if local_fc < 86 and lead_pct > own_pct and own_pct > 20.0:
                    for p in range(num_powers):
                        if int(state.sc_count[p]) < 2:
                            state.g_EnemyFlag[p] = 1
                            state.g_AllyTrustScore[own_power, p] = 0
                            if hasattr(trust_hi_mat, '__setitem__'):
                                trust_hi_mat[own_power, p] = 0
            else:
                # local_fc <= 75 AND leading_pct > own_pct
                for p in range(num_powers):
                    sc_p = int(state.sc_count[p])
                    infl_own_p = float(state.g_InfluenceMatrix[own_power, p])
                    infl_p_own = float(state.g_InfluenceMatrix[p, own_power])
                    infl_raw_own_p = float(getattr(state, 'g_InfluenceMatrix_Raw',
                                                    state.g_InfluenceMatrix)[own_power, p])
                    infl_raw_p_p = float(getattr(state, 'g_InfluenceMatrix_Raw',
                                                  state.g_InfluenceMatrix)[p, p])
                    if (sc_p < 2
                            or (infl_own_p > 0.0 and p != own_power
                                and infl_raw_own_p / (infl_raw_p_p + 1.0) > 4.5
                                and infl_p_own > 10.0)):
                        state.g_EnemyFlag[p] = 1
                        state.g_AllyTrustScore[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
        # goto LAB_0042bff2 — skip all remaining passes
        return  # early exit; function writes are complete

    # ── Phase 4c: normal enemy selection (LAB_00429317 branch) ───────────────
    # Simplified port; full decision tree has ~600 C lines.
    # Key paths implemented: opening-sticky, both-top-2-at-war, peacetime.
    if not bVar26:
        g_stabbed = int(getattr(state, 'g_StabbedFlag', 0))
        g_opening_sticky = int(getattr(state, 'g_OpeningStickyMode', 0))
        g_deceit = int(getattr(state, 'g_DeceitLevel', 0))
        g_opening_enemy = int(getattr(state, 'g_OpeningEnemy', -1))

        enemy_selected = False

        # Opening-sticky mode: keep fighting the designated opening enemy
        if g_opening_sticky == 1 and g_deceit < 3 and 0 <= g_opening_enemy < num_powers:
            state.g_EnemyFlag[g_opening_enemy] = 1
            state.g_AllyTrustScore[own_power, g_opening_enemy] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, g_opening_enemy] = 0
            enemy_selected = True

        # Both top-2 at war with us (zero trust both ways) — peace-signal /
        # trust-history / random selection per decompile lines 1101-1223.
        t_hi_1 = int(trust_hi_mat[own_power, top_enemy_1])
        t_lo_1 = int(state.g_AllyTrustScore[own_power, top_enemy_1])
        t_hi_2 = int(trust_hi_mat[own_power, top_enemy_2])
        t_lo_2 = int(state.g_AllyTrustScore[own_power, top_enemy_2])
        both_zero = (t_hi_1 == 0 and t_lo_1 == 0
                     and t_hi_2 == 0 and t_lo_2 == 0
                     and top_enemy_2 != own_power)

        # g_RelationHistory (DAT_00634e90) is the "trust by history" score;
        # C tests DAT_00634e90[top_enemy_2] <= DAT_00634e90[top_enemy_1].
        rel_hist = getattr(state, 'g_RelationHistory', None)
        if rel_hist is not None:
            hist_1 = int(rel_hist[own_power, top_enemy_1])
            hist_2 = int(rel_hist[own_power, top_enemy_2])
        else:
            hist_1 = hist_2 = 0

        # Peace-channel state — prefer to fight the one NOT sending peace signals.
        # C reads DAT_004cf4c0/c4[p*2] as int64 pair; Python uses g_PeaceSignal
        # (per-pair) as a proxy — "peace signal received from other".
        peace_sig = getattr(state, 'g_PeaceSignal', None)
        def _peace_signal_from(p):
            if peace_sig is None or not (0 <= p < num_powers):
                return False
            return int(peace_sig[own_power, p]) != 0

        # C's "neutral-flag" pair check (DAT_0062b7b0[pow*21+other])
        neutral_flag = getattr(state, 'g_NeutralFlag', None)
        def _neutral(p):
            if neutral_flag is None or not (0 <= p < num_powers):
                return False
            return int(neutral_flag[own_power, p]) != 0

        if not enemy_selected and both_zero:
            # Decompile branch at line 1105: "We are at war with our top 2 enemies"
            if top_enemy_2 == own_power:
                state.g_EnemyFlag[top_enemy_1] = 1
                enemy_selected = True
            elif hist_2 <= hist_1:
                # Lines 1125-1196: peace-signal / random
                p1_peace = _peace_signal_from(top_enemy_1) and not _neutral(top_enemy_2)
                p2_peace = _peace_signal_from(top_enemy_2) and not _neutral(top_enemy_1)
                if p1_peace and not p2_peace:
                    # Target #1 sending peace signal → prefer #2 (avoid #1),
                    # but C's branch picks top_enemy_1 here (it's the one we
                    # just confirmed is "sending" so we fight it anyway).
                    # Reading the C carefully (line 1125-1137): if peace
                    # channel from #2 closed AND neutral on #1 → pick #1
                    # as enemy "because peace signal from enemy 2".
                    state.g_EnemyFlag[top_enemy_1] = 1
                elif p2_peace and not p1_peace:
                    state.g_EnemyFlag[top_enemy_2] = 1
                else:
                    # Random weighted selection (line 1163): rand()/0x17 % 100
                    import random as _random
                    r = _random.randint(0, 99)
                    if r < 50:
                        state.g_EnemyFlag[top_enemy_1] = 1
                    else:
                        state.g_EnemyFlag[top_enemy_2] = 1
                enemy_selected = True
            else:
                # hist_2 > hist_1 (we trust #2 less by history)
                state.g_EnemyFlag[top_enemy_1] = 1
                enemy_selected = True

        if not enemy_selected and (t_hi_1 == 0 and t_lo_1 == 0):
            state.g_EnemyFlag[top_enemy_1] = 1
            enemy_selected = True
        if not enemy_selected and (t_hi_2 == 0 and t_lo_2 == 0):
            state.g_EnemyFlag[top_enemy_2] = 1
            enemy_selected = True

        # Peace with top 3 — random weighted selection by alliance score
        # (decompile lines 1591-1714). Simplified: weight by (g_RelationHistory+
        # bias) across top_enemy_1..3 and pick via cumulative random draw.
        if not enemy_selected:
            import random as _random
            pool = [p for p in (top_enemy_1, top_enemy_2, top_enemy_3)
                    if p != own_power]
            if pool:
                weights = []
                for p in pool:
                    # Lower relation history / lower trust → higher weight as enemy
                    hist = int(rel_hist[own_power, p]) if rel_hist is not None else 0
                    t_lo = int(state.g_AllyTrustScore[own_power, p])
                    t_hi = int(trust_hi_mat[own_power, p])
                    # Baseline weight 100, penalty for positive trust/history
                    w = max(1, 100 - hist - (t_hi * 10 + t_lo))
                    weights.append(w)
                total_w = sum(weights)
                r = _random.randint(1, total_w)
                acc = 0
                for p, w in zip(pool, weights):
                    acc += w
                    if r <= acc:
                        state.g_EnemyFlag[p] = 1
                        enemy_selected = True
                        break

    # Opening best ally lookup (also used by gang-up and alliance-agreement)
    opening_best_ally = int(getattr(state, 'g_BestAllySlot0',
                                    getattr(state, 'g_OpeningBestAlly', -1)))

    # ── Gang-up logic (decompile lines 1470-1557, 1950-2060) ─────────────────
    # When we've committed to an enemy, check if a high-trust ally also has a
    # remaining top-feared power as *their* enemy — coordinate by redirecting
    # to the shared enemy.  C checks:
    #   - trust_hi[own, ally] > 0 OR trust_lo > 6   (high-trust ally)
    #   - ally != opening_best_ally                 (not a pass-through)
    #   - g_RankMatrix[target, own] < 2             (we're in their top-2 fear)
    #   - trust[ally, target] == 0                  (ally hostile to target)
    #   - g_InfluenceMatrix_Raw[target, own] / (raw[ally] + 1) > 1.0
    #
    # Simplified port: look for a high-trust ally among top3_feared whose own
    # relation with another top3_feared is hostile, then switch enemy to that
    # other power.
    g_infl_raw_gu = getattr(state, 'g_InfluenceMatrix_Raw', state.g_InfluenceMatrix)
    for ally in (top_enemy_1, top_enemy_2, top_enemy_3):
        if ally == own_power:
            continue
        ally_t_hi = int(trust_hi_mat[own_power, ally])
        ally_t_lo = int(state.g_AllyTrustScore[own_power, ally])
        # High-trust gate (hi>0 OR lo>6)
        if not (ally_t_hi > 0 or (ally_t_hi == 0 and ally_t_lo > 6)):
            continue
        if ally == opening_best_ally:
            # Don't redirect via opening ally (would burn opening selection)
            continue
        for target in (top_enemy_1, top_enemy_2, top_enemy_3):
            if target == own_power or target == ally:
                continue
            if state.g_EnemyFlag[target] != 0:
                continue  # already enemy
            # ally hostile to target (both trust words zero)
            ally_target_hi = int(trust_hi_mat[ally, target])
            ally_target_lo = int(state.g_AllyTrustScore[ally, target])
            if ally_target_hi != 0 or ally_target_lo != 0:
                continue
            # influence ratio gate: raw[target, own] / (raw[ally, ally] + 1) > 1
            try:
                ratio = (float(g_infl_raw_gu[target, own_power])
                         / (float(g_infl_raw_gu[ally, ally]) + 1.0))
            except (IndexError, ValueError):
                ratio = 0.0
            if ratio <= 1.0:
                continue
            # Rank-matrix gate: own is in target's top-2 feared
            if int(state.g_RankMatrix[target, own_power]) >= 2:
                continue
            # Gang-up fires: mark target enemy, clear ally trust toward target
            state.g_EnemyFlag[target] = 1
            state.g_AllyTrustScore[own_power, target] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, target] = 0
            break  # one target per ally

    # ── LAB_0042b203: distressed-ally rescue (decompile lines 2077–2166) ──────
    # For each ally with g_AllyDistressFlag==1 that is not already an enemy:
    # If own trust toward top-1 or top-2 feared > 30 (in Hi word), look up
    # g_PowerProximityRank[ally][0] and [1]; if in own top-2/3 feared AND
    # g_RankMatrix[own][rank_neighbor] < 3 → set that neighbor as enemy.
    # NOTE: g_PowerProximityRank stride=0x14(20 bytes per power, 5 int32s per row).
    # Simplified: use own top3 as proxy for proximity rank.
    trust_threshold_hi = (
        int(trust_hi_mat[own_power, top_enemy_1]) > 30
        or int(trust_hi_mat[own_power, top_enemy_2]) > 30
    )
    for ally in range(num_powers):
        if (int(state.g_AllyDistressFlag[ally]) != 1
                or state.g_EnemyFlag[ally] != 0
                or not trust_threshold_hi):
            continue
        # Use g_PowerProximityRank[ally] — proxy via own top3 if unavailable
        prox_rank = getattr(state, 'g_PowerProximityRank', None)
        candidates = []
        if prox_rank is not None:
            # Access g_PowerProximityRank[ally][0] and [1] (stride 5 int32s per power)
            candidates = [int(prox_rank[ally, 0]), int(prox_rank[ally, 1])]
        else:
            candidates = [top_enemy_1, top_enemy_2]
        for neighbor in candidates:
            if not (0 <= neighbor < num_powers) or neighbor == own_power:
                continue
            if (neighbor in (top_enemy_2, top_enemy_3)  # in own top-2/3 feared
                    and int(state.g_RankMatrix[own_power, neighbor]) < 3):
                state.g_EnemyFlag[neighbor] = 1
                state.g_AllyTrustScore[own_power, neighbor] = 0
                if hasattr(trust_hi_mat, '__setitem__'):
                    trust_hi_mat[own_power, neighbor] = 0

    # ── Weak-elimination + SC-grab pass (decompile lines 2168–2283) ──────────
    g_deceit = int(getattr(state, 'g_DeceitLevel', 0))
    g_infl_raw = getattr(state, 'g_InfluenceMatrix_Raw', state.g_InfluenceMatrix)
    for p in range(num_powers):
        sc_p = int(state.sc_count[p])
        infl_own_p = float(state.g_InfluenceMatrix[own_power, p])
        infl_p_own = float(state.g_InfluenceMatrix[p, own_power])
        raw_own_p  = float(g_infl_raw[own_power, p])
        raw_p_own  = float(g_infl_raw[p, own_power])

        # Weak-elimination: g_DeceitLevel > 2 AND (sc < 3 OR high influence dominance)
        if g_deceit > 2 and (
                sc_p < 3 or (
                    infl_own_p > 0.0 and p != own_power
                    and raw_own_p / (raw_p_own + 1.0) > 4.5
                    and infl_p_own > 10.0
                )):
            state.g_EnemyFlag[p] = 1
            state.g_AllyTrustScore[own_power, p] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, p] = 0

        # SC-grab: own_sc < 4 AND vulnerable unguarded SC (decompile lines
        # 2200-2276). C reads g_ContactWeighted (DAT_00b755cc) with ±21-int32
        # strides — interpretation as [own, p-1], [own, p], [own, p+1]
        # (adjacent-power contact counts). Proxy: use g_ContactWeighted row for
        # own_power, require prev/cur positive and next zero + target_sc > 3.
        if own_sc < 4 and p != own_power and sc_p > 3:
            cw = getattr(state, 'g_ContactWeighted', None)
            if cw is not None:
                p_prev = (p - 1) % num_powers
                p_next = (p + 1) % num_powers
                try:
                    if (int(cw[own_power, p_prev]) > 0
                            and int(cw[own_power, p]) > 0
                            and int(cw[own_power, p_next]) == 0):
                        state.g_EnemyFlag[p] = 1
                        state.g_AllyTrustScore[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
                except (IndexError, ValueError):
                    pass

    # ── Dominance sweep (decompile lines 2284–2328) ───────────────────────────
    # MUST come after all per-power passes above.
    # DAT_00baed6a = 0 first (reset), then check condition.
    # Condition: g_SCPercent[own] > 75.0 AND own_pct - g_SCPercent[local_128] >= 2.0
    # (Note: uses local_128 not max_pct; uses >= not >)
    # NOTE: second write of log-only g_LeadingFlag — see note at first write
    # above; no downstream C reads.  Kept for parity.
    state.g_LeadingFlag = 0
    if local_128 != own_power:
        lead_pct_dominate = float(state.g_SCPercent[local_128])
        if own_pct > 75.0 and (own_pct - lead_pct_dominate) >= 2.0:
            state.g_LeadingFlag = 1
            for k in range(num_powers):
                if k != own_power:
                    state.g_EnemyFlag[k] = 1
                    state.g_AllyTrustScore[own_power, k] = 0
                    if hasattr(trust_hi_mat, '__setitem__'):
                        trust_hi_mat[own_power, k] = 0

    # ── Alliance-agreement → enemy (decompile lines 2329–2403) ──────────────
    # Honor ally's declared enemies; conditions (decompile lines 2356–2363):
    #   g_EnemyFlag[pow_b] == 0 (not yet enemy)
    #   auStack_dc[pow_a + 1] == 0  (pow_a has no prior alliance enforcement)
    #   g_AllyMatrix[own][pow_b] == 1  (own allied with pow_b)
    #   DAT_004c6bc4 != pow_b  (pow_b is not opening best ally)
    #   g_AllyTrustScore_Hi[own][pow_b] < 1 AND (Hi<0 OR Lo<2)  (low trust)
    # opening_best_ally defined above (shared with gang-up)
    # Track which pow_a rows have already set an enemy (auStack_dc equivalent)
    pow_a_enforced = [False] * num_powers
    for pow_a in range(num_powers):
        for pow_b in range(num_powers):
            if pow_a_enforced[pow_a]:
                continue
            t_hi_b = int(trust_hi_mat[own_power, pow_b])
            t_lo_b = int(state.g_AllyTrustScore[own_power, pow_b])
            if (state.g_EnemyFlag[pow_b] == 0
                    and int(state.g_AllyMatrix[pow_a, pow_b]) == 1
                    and int(state.g_AllyMatrix[own_power, pow_b]) == 1
                    and pow_b != opening_best_ally
                    and t_hi_b < 1 and (t_hi_b < 0 or t_lo_b < 2)):
                state.g_EnemyFlag[pow_b] = 1
                state.g_AllyTrustScore[own_power, pow_b] = 0
                if hasattr(trust_hi_mat, '__setitem__'):
                    trust_hi_mat[own_power, pow_b] = 0
                pow_a_enforced[pow_a] = True
