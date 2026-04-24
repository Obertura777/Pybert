"""CAL_BOARD: per-power board calibration pass.

Split from heuristics.py during the 2026-04 refactor.

Single mega-function ``cal_board`` (port of CAL_BOARD) that refreshes
``state.g_influence_matrix_raw`` and the per-power reach/mobility/ownership
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
      - g_power_exp_score  (quadratic power score)
      - g_sc_percent      (SC percentage per power, relative to win_threshold)
      - g_enemy_count     (genuine enemy count per power)
      - g_rank_matrix / g_ally_pref_ranking  (influence ranking)
      - g_enemy_flag      (designated enemies for this turn)
      - g_leading_flag / g_other_power_lead_flag / g_near_victory_power
      - g_request_draw_flag / g_static_map_flag
      - g_one_sc_from_win
    """
    num_powers = 7
    win_threshold = int(state.win_threshold)
    if win_threshold == 0:
        win_threshold = 1  # guard against divide-by-zero

    trust_hi_mat = getattr(state, 'g_ally_trust_score_hi', np.zeros((7, 7), dtype=np.int64))

    # ── Phase 1a: per-power quadratic score (Loop A in decompile) ────────────
    # g_power_exp_score[k] = pow(min(sc_k, win_threshold), 2) * 100 + 1
    #
    # The Ghidra decompile shows _safe_pow() with no visible arguments (x87
    # FPU stack args lost).  The sole downstream consumer is the keep-alliance
    # gate:  exp_own − exp_lead × 1.7 + 69 > 0.  Scale analysis proves the
    # exponent is 2 (quadratic), not sc (super-exponential):
    #   • pow(sc, 2): the +69 offset is ~4% of a typical score (meaningful
    #     tuning constant that shifts the alliance boundary by ~0.5 SC).
    #   • pow(sc, sc): +69 is <0.003% at sc=4 and vanishes above — no
    #     programmer would include a meaningless constant.
    # Fixed 2026-04-20 (audit finding C5).
    for k in range(num_powers):
        sc = max(0, min(int(state.sc_count[k]), win_threshold))
        state.g_power_exp_score[k] = (sc ** 2) * 100.0 + 1.0

    # ── Phase 1b: NearEndGameFactor + g_sc_percent (Loop B in decompile) ──────
    # g_sc_percent[k] = sc[k] * 100 / win_threshold  (divisor = win threshold, NOT total SCs)
    # g_war_mode_flag reset to 0 before this loop (decompile line 121)
    state.g_war_mode_flag = 0
    near_end = 1.0

    own_sc = int(state.sc_count[own_power])
    # g_one_sc_from_win checked before second loop (decompile line 118).
    # NOTE: log-only flag — no C read sites outside the archive-event write here
    # (CAL_BOARD event 0x28 family).  Kept for parity; do not remove.
    state.g_one_sc_from_win = 1 if (win_threshold - own_sc == 1) else 0

    # Leader tracking (decompile lines 125-147): DAT_00624124 = index of lone
    # leader (unique max-SC power); -1 if two or more powers tie for most SCs.
    lead_pow = -1
    lead_sc = -1
    lead_tied = 0
    for k in range(num_powers):
        sc = int(state.sc_count[k])
        pct = sc * 100.0 / win_threshold
        state.g_sc_percent[k] = pct
        if pct > 80.0:
            state.g_war_mode_flag = 1

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

        # Zero g_enemy_flag in this loop (decompile lines 126-127)
        state.g_enemy_flag[k] = 0

    # Lone-lead-power: only set if unique; archive "The lone lead power is (%s)"
    # event (DAT_00bbf638 key 0x28) when applicable (decompile lines 157-195).
    # NOTE: g_lone_lead_power is log-only — no C reads outside this archive event;
    # the value exists purely so the AllianceMsgTree-key-0x28 record is
    # reproducible.  Kept for parity; do not remove.
    if lead_tied < 2:
        state.g_lone_lead_power = lead_pow
        try:
            state.g_alliance_msg_tree.add(0x28)  # lone-lead-power event code
        except Exception:
            pass
    else:
        state.g_lone_lead_power = -1

    # Opening-ally-slot promotion (decompile lines 148-156): if slot 0's
    # power has been reduced below 2 SCs, promote slot 1 → 0, slot 2 → 1.
    try:
        s0 = int(getattr(state, 'g_best_ally_slot0', -1))
        s1 = int(getattr(state, 'g_best_ally_slot1', -1))
        s2 = int(getattr(state, 'g_best_ally_slot2', -1))
        if 0 <= s0 < num_powers and int(state.sc_count[s0]) < 2:
            state.g_best_ally_slot0 = s1
            state.g_best_ally_slot1 = s2 if s2 >= 0 else -1
            state.g_best_ally_slot2 = -1
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
    state.g_near_end_game_factor = near_end

    # ── Phase 2: g_enemy_count + g_rank_matrix init ────────────────────────────
    state.g_enemy_count.fill(0)
    state.g_ally_distress_flag.fill(0)
    state.g_rank_matrix.fill(-1)
    np.fill_diagonal(state.g_rank_matrix, -2)

    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = int(state.g_ally_trust_score[row, col])
            trust_hi = int(trust_hi_mat[row, col])
            influence = float(state.g_influence_matrix[row, col])
            col_sc = int(state.sc_count[col])
            if (trust_hi < 1
                    and (trust_hi < 0 or trust_lo < 2)
                    and influence > 0.0
                    and col_sc > 2):
                state.g_enemy_count[row] += 1

    # ── Phase 3: top feared powers from influence matrix ─────────────────────
    own_influence_row = state.g_influence_matrix[own_power].copy()
    own_influence_row[own_power] = -1.0  # exclude self
    top3 = sorted(range(num_powers), key=lambda k: own_influence_row[k], reverse=True)[:3]
    top_enemy_1 = top3[0] if len(top3) > 0 else own_power
    top_enemy_2 = top3[1] if len(top3) > 1 else own_power
    top_enemy_3 = top3[2] if len(top3) > 2 else own_power

    # ── Phase 4: find leading non-own power → local_fc / local_128 ───────────
    # local_fc  = int(g_sc_percent[leading_power]) — int-cast, like C FloatToInt64
    # local_128 = index of the non-own power with the highest SC%
    # (decompile lines 729-820; tie-breaking omitted — C uses trust/history)
    local_fc: int = -1
    local_128: int = own_power  # sentinel (own_power used when no rival found)
    for k in range(num_powers):
        if k == own_power:
            continue
        pct_int = int(state.g_sc_percent[k])   # FloatToInt64 truncates toward 0
        if pct_int > local_fc:
            local_fc = pct_int
            local_128 = k

    own_pct = float(state.g_sc_percent[own_power])

    # ── Phase 4a: draw / static-map request flags ─────────────────────────────
    # Decompile lines 821-876:
    #   local_fc >= 0x50(80) AND g_sc_percent[leading] > own_pct + 15  → draw
    #   local_fc >= 0x3c(60) AND g_sc_percent[leading] > own_pct + 25  → draw
    state.g_request_draw_flag = 0
    if local_128 != own_power:
        lead_pct = float(state.g_sc_percent[local_128])
        if local_fc >= 80 and lead_pct > own_pct + 15.0:
            state.g_request_draw_flag = 1
        elif local_fc >= 60 and lead_pct > own_pct + 25.0:
            state.g_request_draw_flag = 1
    if state.g_static_map_flag:
        state.g_request_draw_flag = 1

    # ── Phase 4b: near-victory enemy designation (local_fc > 0x3b = 59) ──────
    # Decompile lines 878-1090
    # NOTE: g_leading_flag is log-only — no C reads outside the archive-event
    # writes below; it exists so AllianceMsgTree leading-power events are
    # reproducible.  Kept for parity; do not remove.
    state.g_leading_flag = 0
    state.g_other_power_lead_flag = 0
    # Reset DAT_0062480c under both aliases: CAL_BOARD.c:99 writes -1 (0xffffffff)
    # at the top of the function, so both views of the same global must agree.
    state.g_near_victory_power = -1
    state.g_committed_enemy   = -1

    bVar26 = False  # keep-alliance override
    if local_fc > 59 and local_128 != own_power:
        lead_pct = float(state.g_sc_percent[local_128])
        # Keep-alliance condition (bVar26):
        #   trust_hi >= 0 AND (trust_hi > 0 OR trust_lo > 11)
        #   AND g_power_exp_score[own] - g_power_exp_score[leading] * 1.7 + 69 > 0
        #   AND g_influence_rank_flag[own][leading] in {1, 2}
        trust_hi_val = int(trust_hi_mat[own_power, local_128])
        trust_lo_val = int(state.g_ally_trust_score[own_power, local_128])
        rank_flag = int(state.g_influence_rank_flag[own_power, local_128])
        exp_own = float(state.g_power_exp_score[own_power])
        exp_lead = float(state.g_power_exp_score[local_128])
        if (trust_hi_val >= 0
                and (trust_hi_val > 0 or trust_lo_val > 11)
                and (exp_own - exp_lead * 1.7 + 69.0) > 0.0
                and rank_flag in (1, 2)):
            bVar26 = True

        # Declare near-victory only if leading is actually ahead and no keep-alliance
        if lead_pct > own_pct and not bVar26:
            state.g_other_power_lead_flag = 1
            # DAT_0062480c is aliased in research.md as both g_near_victory_power
            # (CAL_BOARD write-site name) and g_committed_enemy (HOSTILITY read-site
            # name).  Mirror to both so HOSTILITY's committed-enemy check (strategy.py
            # :674 inside the mutual-enemy scan) sees the near-victory designation
            # that CAL_BOARD just made — matches single-address C semantics.
            state.g_near_victory_power = local_128
            state.g_committed_enemy   = local_128
            # Set leading power as enemy; zero trust toward them
            state.g_enemy_flag[local_128] = 1
            state.g_ally_trust_score[own_power, local_128] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, local_128] = 0
            # When local_fc >= 80: additionally zero trust *from* local_128 to all
            if local_fc >= 80:
                for p in range(num_powers):
                    if p != local_128:
                        state.g_ally_trust_score[local_128, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[local_128, p] = 0
            bVar26 = True  # signal "near-victory enemy selected"

    # ── LAB_0042ac27: post-enemy-selection routing ────────────────────────────
    # When g_other_power_lead_flag==1: run near-victory weak-elim then JUMP TO END
    # (skips gang-up, distressed-ally, weak-elim, dominance, alliance-agreement)
    # When g_other_power_lead_flag==0: run all remaining passes

    if state.g_other_power_lead_flag:
        # ── Near-victory post-pass (decompile lines 1815–1924) ───────────────
        # When local_fc > 75 OR leading_pct <= own_pct OR own_pct > 20:
        #   If local_fc < 86 AND own_pct < leading_pct AND own_pct > 20:
        #     mark powers with sc < 2 as enemy ("1 SC even though power close to victory")
        # Else (local_fc <= 75 AND leading_pct > own_pct):
        #   mark powers with sc < 2 OR weak influence as enemy
        if local_128 != own_power:
            lead_pct = float(state.g_sc_percent[local_128])
            if local_fc > 75 or lead_pct <= own_pct or own_pct > 20.0:
                if local_fc < 86 and lead_pct > own_pct and own_pct > 20.0:
                    for p in range(num_powers):
                        if int(state.sc_count[p]) < 2:
                            state.g_enemy_flag[p] = 1
                            state.g_ally_trust_score[own_power, p] = 0
                            if hasattr(trust_hi_mat, '__setitem__'):
                                trust_hi_mat[own_power, p] = 0
            else:
                # local_fc <= 75 AND leading_pct > own_pct
                for p in range(num_powers):
                    sc_p = int(state.sc_count[p])
                    infl_own_p = float(state.g_influence_matrix[own_power, p])
                    infl_p_own = float(state.g_influence_matrix[p, own_power])
                    infl_raw_own_p = float(getattr(state, 'g_influence_matrix_raw',
                                                    state.g_influence_matrix)[own_power, p])
                    infl_raw_p_p = float(getattr(state, 'g_influence_matrix_raw',
                                                  state.g_influence_matrix)[p, p])
                    if (sc_p < 2
                            or (infl_own_p > 0.0 and p != own_power
                                and infl_raw_own_p / (infl_raw_p_p + 1.0) > 4.5
                                and infl_p_own > 10.0)):
                        state.g_enemy_flag[p] = 1
                        state.g_ally_trust_score[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
        # goto LAB_0042bff2 — skip all remaining passes
        return  # early exit; function writes are complete

    # ── Phase 4c: normal enemy selection (LAB_00429317, lines 1091-1455) ──────
    # Full decision tree ported from C decompile.
    if not bVar26:
        import random as _random
        g_stabbed = int(getattr(state, 'g_stabbed_flag', 0))
        g_opening_sticky = int(getattr(state, 'g_opening_sticky_mode', 0))
        g_deceit = int(getattr(state, 'g_deceit_level', 0))
        g_opening_enemy = int(getattr(state, 'g_opening_enemy', -1))

        enemy_selected = False

        t_hi_1 = int(trust_hi_mat[own_power, top_enemy_1])
        t_lo_1 = int(state.g_ally_trust_score[own_power, top_enemy_1])
        t_hi_2 = int(trust_hi_mat[own_power, top_enemy_2])
        t_lo_2 = int(state.g_ally_trust_score[own_power, top_enemy_2])

        rel_hist = getattr(state, 'g_relation_history', None)
        if rel_hist is not None:
            hist_1 = int(rel_hist[own_power, top_enemy_1])
            hist_2 = int(rel_hist[own_power, top_enemy_2])
        else:
            hist_1 = hist_2 = 0

        peace_sig = getattr(state, 'g_peace_signal', None)
        def _peace_signal_from(p):
            if peace_sig is None or not (0 <= p < num_powers):
                return False
            return int(peace_sig[own_power, p]) != 0

        neutral_flag = getattr(state, 'g_neutral_flag', None)
        def _neutral(p):
            if neutral_flag is None or not (0 <= p < num_powers):
                return False
            return int(neutral_flag[own_power, p]) != 0

        # Branch 1 (C line 1226): Opening-sticky mode
        if g_opening_sticky == 1 and g_deceit < 3 and 0 <= g_opening_enemy < num_powers:
            state.g_enemy_flag[g_opening_enemy] = 1
            state.g_ally_trust_score[own_power, g_opening_enemy] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, g_opening_enemy] = 0
            enemy_selected = True

        # Branch 2 (C line 1256): at war with at least one of top-2?
        # Guard: not sticky and (trust[#1]==0 OR trust[#2]==0)
        at_war_1 = (t_hi_1 == 0 and t_lo_1 == 0)
        at_war_2 = (t_hi_2 == 0 and t_lo_2 == 0)
        both_zero = at_war_1 and at_war_2 and top_enemy_2 != own_power

        if not enemy_selected and both_zero:
            # C line 1105: "We are at war with our top 2 enemies"
            if top_enemy_2 == own_power:
                state.g_enemy_flag[top_enemy_1] = 1
                enemy_selected = True
            elif hist_2 <= hist_1:
                # Lines 1125-1196: peace-signal / neutral / random
                # C: DAT_004cf4c0[enemy2*2]==0 && DAT_004cf4c4[enemy2*2]==0
                #    && DAT_0062b7b0[enemy1]==0  → pick enemy1 "peace signal from enemy 2"
                p2_closed = not _peace_signal_from(top_enemy_2) or _peace_signal_from(top_enemy_2)
                n1 = _neutral(top_enemy_1)
                n2 = _neutral(top_enemy_2)
                ps1 = _peace_signal_from(top_enemy_1)
                ps2 = _peace_signal_from(top_enemy_2)

                if (not ps2) and (not n1):
                    # "peace signal from enemy 2" → select enemy 1
                    state.g_enemy_flag[top_enemy_1] = 1
                elif (not ps1) and (not n2):
                    # "peace signal from enemy 1" → select enemy 2
                    state.g_enemy_flag[top_enemy_2] = 1
                else:
                    # Random weighted selection (C line 1163)
                    # C: FloatToInt64(100, ...) yields influence-ratio-based threshold
                    inf_alt = getattr(state, 'g_influence_matrix_alt', None)
                    if inf_alt is not None:
                        inf1 = float(inf_alt[own_power * num_powers + top_enemy_1]) if hasattr(inf_alt, '__getitem__') else 0.0
                        inf2 = float(inf_alt[own_power * num_powers + top_enemy_2]) if hasattr(inf_alt, '__getitem__') else 0.0
                    else:
                        inf1 = inf2 = 50.0
                    threshold = int((inf1 * 100.0) / (inf1 + inf2 + 1.0))
                    r = (_random.randint(0, 32767) // 0x17) % 100
                    if r < threshold:
                        state.g_enemy_flag[top_enemy_1] = 1
                    else:
                        state.g_enemy_flag[top_enemy_2] = 1
                enemy_selected = True
            else:
                # hist_2 > hist_1: "trust him less" → pick enemy1
                state.g_enemy_flag[top_enemy_1] = 1
                enemy_selected = True

        # Branch 3 (C line 1256-1259): at war with exactly one
        if not enemy_selected and (at_war_1 or at_war_2):
            # "at war with at least one of our Top 3 enemies — validate"
            if at_war_1:
                # Trust[#1]==0: validate #1 as enemy
                state.g_enemy_flag[top_enemy_1] = 1
                enemy_selected = True
            else:
                # Trust[#2]==0 but #1 has trust: need to check whether to
                # re-target. C lines 1293-1455: check influence ratio,
                # power exp score, opening alliance preservation.
                # Get trust tier for #1 and #2
                def _trust_tier(t_lo, t_hi):
                    if t_hi < 0 or (t_hi == 0 and t_lo < 3):
                        return 1
                    if t_hi < 1 and t_lo < 5:
                        return 3
                    return 4

                tier_1 = _trust_tier(t_lo_1, t_hi_1)
                tier_2 = _trust_tier(t_lo_2, t_hi_2)

                # Top-3 enemy (local_f0) trust check
                top_e3_trust_lo = int(state.g_ally_trust_score[own_power, top_enemy_3]) if top_enemy_3 < num_powers else 0
                top_e3_trust_hi = int(trust_hi_mat[own_power, top_enemy_3]) if top_enemy_3 < num_powers else 0

                # Influence matrix alt check (C lines 1296-1302)
                inf_alt = getattr(state, 'g_influence_matrix_alt', None)
                power_exp = getattr(state, 'g_power_exp_score', None)
                dac_4c6bc4 = int(getattr(state, 'g_opening_best_ally',
                                          getattr(state, 'g_best_ally_slot0', -1)))

                # Check if enemy2 should be replaced (C condition lines 1296-1302)
                should_rechoose = False
                if (t_lo_2 != 0 or t_hi_2 != 0) and top_enemy_2 != own_power:
                    # enemy2 has nonzero trust — check influence ratio
                    if inf_alt is not None:
                        inf_1_idx = own_power * num_powers + top_enemy_1
                        inf_2_idx = own_power * num_powers + top_enemy_2
                        inf_1_val = float(inf_alt[inf_1_idx]) if hasattr(inf_alt, '__getitem__') else 0.0
                        inf_2_val = float(inf_alt[inf_2_idx]) if hasattr(inf_alt, '__getitem__') else 0.0
                        ratio = (inf_2_val * 100.0) / (inf_1_val + 1.0) if inf_1_val > 0 else 100.0
                        if ratio > 20.0:
                            if ratio > 70.0:
                                should_rechoose = True
                            elif power_exp is not None:
                                pe_own = float(power_exp[own_power]) if hasattr(power_exp, '__getitem__') else 0.0
                                pe_1 = float(power_exp[top_enemy_1]) if hasattr(power_exp, '__getitem__') else 0.0
                                if (pe_own - pe_1 * 1.7) + 69.0 <= 0.0:
                                    should_rechoose = True

                # Check enemy3 viability
                e3_viable = (top_e3_trust_lo != 0 or top_e3_trust_hi != 0) or \
                    (inf_alt is not None and top_enemy_3 < num_powers and
                     float(inf_alt[own_power * num_powers + top_enemy_3]
                           if hasattr(inf_alt, '__getitem__') else 0) <= 15.0) or \
                    (top_enemy_3 == own_power)

                if should_rechoose or e3_viable:
                    # C LAB_0042a6ef: "rechoose a new one"
                    r1 = (_random.randint(0, 32767) // 0x17) % 50
                    r2 = (_random.randint(0, 32767) // 0x17) % 50

                    # Opening alliance preservation (C lines 1400-1427)
                    if dac_4c6bc4 >= 0 and top_enemy_1 != dac_4c6bc4 and top_enemy_2 == dac_4c6bc4:
                        # enemy2 is our opening best ally — try to preserve
                        if inf_alt is not None and top_enemy_2 != own_power:
                            inf_2_idx = own_power * num_powers + top_enemy_2
                            inf_1_idx = own_power * num_powers + top_enemy_1
                            inf_2_val = float(inf_alt[inf_2_idx]) if hasattr(inf_alt, '__getitem__') else 0.0
                            inf_1_val = float(inf_alt[inf_1_idx]) if hasattr(inf_alt, '__getitem__') else 0.0
                            ratio = (inf_2_val * 100.0) / (inf_1_val + 1.0)
                            if ratio > 20.0:
                                pe_check = True
                                if ratio <= 70.0 and power_exp is not None:
                                    pe_own = float(power_exp[own_power]) if hasattr(power_exp, '__getitem__') else 0.0
                                    pe_1 = float(power_exp[top_enemy_1]) if hasattr(power_exp, '__getitem__') else 0.0
                                    if (pe_own - pe_1 * 1.45) + 41.0 <= 0.0:
                                        pe_check = False
                                if pe_check:
                                    state.g_enemy_flag[top_enemy_1] = 1
                                    state.g_ally_trust_score[own_power, top_enemy_1] = 0
                                    trust_hi_mat[own_power, top_enemy_1] = 0
                                    enemy_selected = True
                        if not enemy_selected:
                            # Keep opening alliance: pick enemy2
                            state.g_enemy_flag[top_enemy_2] = 1
                            state.g_ally_trust_score[own_power, top_enemy_2] = 0
                            trust_hi_mat[own_power, top_enemy_2] = 0
                            enemy_selected = True
                    elif dac_4c6bc4 >= 0 and top_enemy_1 == dac_4c6bc4:
                        # enemy1 is our opening best ally — pick enemy2
                        state.g_enemy_flag[top_enemy_2] = 1
                        state.g_ally_trust_score[own_power, top_enemy_2] = 0
                        trust_hi_mat[own_power, top_enemy_2] = 0
                        enemy_selected = True

                if not enemy_selected:
                    # C LAB_0042aa75: random threshold selection
                    # FloatToInt64 computes influence-ratio-based threshold
                    threshold = 50  # default
                    if inf_alt is not None:
                        inf_1_idx = own_power * num_powers + top_enemy_1
                        inf_2_idx = own_power * num_powers + top_enemy_2
                        inf_1_val = float(inf_alt[inf_1_idx]) if hasattr(inf_alt, '__getitem__') else 0.0
                        inf_2_val = float(inf_alt[inf_2_idx]) if hasattr(inf_alt, '__getitem__') else 0.0
                        threshold = int((inf_1_val * 100.0) / (inf_1_val + inf_2_val + 1.0))

                    r1 = (_random.randint(0, 32767) // 0x17) % 50
                    r2 = (_random.randint(0, 32767) // 0x17) % 50
                    if (r2 + r1 < threshold) or (top_enemy_2 == own_power):
                        state.g_enemy_flag[top_enemy_1] = 1
                        state.g_ally_trust_score[own_power, top_enemy_1] = 0
                        trust_hi_mat[own_power, top_enemy_1] = 0
                    else:
                        state.g_enemy_flag[top_enemy_2] = 1
                        state.g_ally_trust_score[own_power, top_enemy_2] = 0
                        trust_hi_mat[own_power, top_enemy_2] = 0
                    enemy_selected = True

        # Branch 4 (C lines 1591-1729): peace with all top enemies — random
        # weighted selection with trust tiers and opening-alliance preservation.
        if not enemy_selected:
            r1 = (_random.randint(0, 32767) // 0x17) % 50
            r2 = (_random.randint(0, 32767) // 0x17) % 50
            rand_sum = r1 + r2  # pdStack_134

            # Trust tier for enemy1: hi>0 OR lo>2 → tier 3, else tier 1
            tier_1 = 1
            if t_hi_1 >= 0 and (t_hi_1 > 0 or t_lo_1 > 2):
                tier_1 = 3
            # Trust tier for enemy2
            tier_2 = 1
            if t_hi_2 >= 0 and (t_hi_2 > 0 or t_lo_2 > 2):
                tier_2 = 3

            # Influence-ratio threshold (C: FloatToInt64(0x32, pdStack_134))
            # FloatToInt64 here computes: round(inf1 * 100 / (inf1 + inf2 + 1))
            inf_alt = getattr(state, 'g_influence_matrix_alt', None)
            if inf_alt is not None:
                inf1 = float(inf_alt[own_power * num_powers + top_enemy_1]) \
                    if hasattr(inf_alt, '__getitem__') else 0.0
                inf2 = float(inf_alt[own_power * num_powers + top_enemy_2]) \
                    if hasattr(inf_alt, '__getitem__') else 0.0
            else:
                inf1 = inf2 = 50.0
            threshold = round((inf1 * 100.0) / (inf1 + inf2 + 1.0))

            history_counter = int(getattr(state, 'g_history_counter', 0))
            dac_4c6bc4_b4 = int(getattr(state, 'g_best_ally_slot0',
                                         getattr(state, 'g_opening_best_ally', -1)))
            power_exp = getattr(state, 'g_power_exp_score', None)

            # Opening-alliance preservation (C lines 1626-1686)
            b4_done = False
            if history_counter < 10 or True:  # C: g_HistoryCounter < 10 → LAB_00429d0f
                if dac_4c6bc4_b4 >= 0:
                    if top_enemy_1 == dac_4c6bc4_b4:
                        # enemy1 IS opening ally → pick enemy2, keep alliance
                        state.g_enemy_flag[top_enemy_2] = 1
                        state.g_ally_trust_score[own_power, top_enemy_2] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, top_enemy_2] = 0
                        b4_done = True
                    elif (top_enemy_2 != dac_4c6bc4_b4
                          or top_enemy_2 == own_power):
                        pass  # fall to LAB_00429efb (random selection)
                    else:
                        # enemy2 IS opening ally — check if enemy1 is viable
                        if inf_alt is not None and top_enemy_1 != own_power:
                            inf_1_val = float(inf_alt[own_power * num_powers + top_enemy_1]) \
                                if hasattr(inf_alt, '__getitem__') else 0.0
                            inf_2_val = float(inf_alt[own_power * num_powers + top_enemy_2]) \
                                if hasattr(inf_alt, '__getitem__') else 0.0
                            ratio_b4 = (inf_2_val * 100.0) / (inf_1_val + 1.0) \
                                if inf_1_val > 0 else 100.0
                            if ratio_b4 > 20.0:
                                pe_ok = True
                                if ratio_b4 <= 70.0 and power_exp is not None:
                                    pe_own = float(power_exp[own_power]) \
                                        if hasattr(power_exp, '__getitem__') else 0.0
                                    pe_1 = float(power_exp[top_enemy_1]) \
                                        if hasattr(power_exp, '__getitem__') else 0.0
                                    if (pe_own - pe_1 * 1.7) + 69.0 <= 0.0:
                                        pe_ok = False
                                if pe_ok:
                                    # Pick enemy1 — keep opening alliance with enemy2
                                    state.g_enemy_flag[top_enemy_1] = 1
                                    state.g_ally_trust_score[own_power, top_enemy_1] = 0
                                    if hasattr(trust_hi_mat, '__setitem__'):
                                        trust_hi_mat[own_power, top_enemy_1] = 0
                                    b4_done = True

            # LAB_00429efb: random threshold selection
            if not b4_done:
                if rand_sum < threshold or top_enemy_2 == own_power:
                    state.g_enemy_flag[top_enemy_1] = 1
                    state.g_ally_trust_score[own_power, top_enemy_1] = 0
                    if hasattr(trust_hi_mat, '__setitem__'):
                        trust_hi_mat[own_power, top_enemy_1] = 0
                else:
                    state.g_enemy_flag[top_enemy_2] = 1
                    state.g_ally_trust_score[own_power, top_enemy_2] = 0
                    if hasattr(trust_hi_mat, '__setitem__'):
                        trust_hi_mat[own_power, top_enemy_2] = 0
            enemy_selected = True

    # Opening best ally lookup (also used by gang-up and alliance-agreement)
    opening_best_ally = int(getattr(state, 'g_best_ally_slot0',
                                    getattr(state, 'g_opening_best_ally', -1)))

    # ── Gang-up logic (decompile lines 1470-1557, 1950-2060) ─────────────────
    # When we've committed to an enemy, check if a high-trust ally also has a
    # remaining top-feared power as *their* enemy — coordinate by redirecting
    # to the shared enemy.  C checks:
    #   - trust_hi[own, ally] > 0 OR trust_lo > 6   (high-trust ally)
    #   - ally != opening_best_ally                 (not a pass-through)
    #   - g_rank_matrix[target, own] < 2             (we're in their top-2 fear)
    #   - trust[ally, target] == 0                  (ally hostile to target)
    #   - g_influence_matrix_raw[target, own] / (raw[ally] + 1) > 1.0
    #
    # Simplified port: look for a high-trust ally among top3_feared whose own
    # relation with another top3_feared is hostile, then switch enemy to that
    # other power.
    g_infl_raw_gu = getattr(state, 'g_influence_matrix_raw', state.g_influence_matrix)
    for ally in (top_enemy_1, top_enemy_2, top_enemy_3):
        if ally == own_power:
            continue
        ally_t_hi = int(trust_hi_mat[own_power, ally])
        ally_t_lo = int(state.g_ally_trust_score[own_power, ally])
        # High-trust gate (hi>0 OR lo>6)
        if not (ally_t_hi > 0 or (ally_t_hi == 0 and ally_t_lo > 6)):
            continue
        if ally == opening_best_ally:
            # Don't redirect via opening ally (would burn opening selection)
            continue
        for target in (top_enemy_1, top_enemy_2, top_enemy_3):
            if target == own_power or target == ally:
                continue
            if state.g_enemy_flag[target] != 0:
                continue  # already enemy
            # ally hostile to target (both trust words zero)
            ally_target_hi = int(trust_hi_mat[ally, target])
            ally_target_lo = int(state.g_ally_trust_score[ally, target])
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
            if int(state.g_rank_matrix[target, own_power]) >= 2:
                continue
            # Gang-up fires: mark target enemy, clear ally trust toward target
            state.g_enemy_flag[target] = 1
            state.g_ally_trust_score[own_power, target] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, target] = 0
            break  # one target per ally

    # ── LAB_0042b203: distressed-ally rescue (decompile lines 2077–2166) ──────
    # For each ally with g_ally_distress_flag==1 that is not already an enemy:
    # If own trust toward top-1 or top-2 feared > 30 (in Hi word), look up
    # g_power_proximity_rank[ally][0] and [1]; if in own top-2/3 feared AND
    # g_rank_matrix[own][rank_neighbor] < 3 → set that neighbor as enemy.
    # NOTE: g_power_proximity_rank stride=0x14(20 bytes per power, 5 int32s per row).
    # Simplified: use own top3 as proxy for proximity rank.
    trust_threshold_hi = (
        int(trust_hi_mat[own_power, top_enemy_1]) > 30
        or int(trust_hi_mat[own_power, top_enemy_2]) > 30
    )
    for ally in range(num_powers):
        if (int(state.g_ally_distress_flag[ally]) != 1
                or state.g_enemy_flag[ally] != 0
                or not trust_threshold_hi):
            continue
        # Use g_power_proximity_rank[ally] — proxy via own top3 if unavailable
        prox_rank = getattr(state, 'g_power_proximity_rank', None)
        candidates = []
        if prox_rank is not None:
            # Access g_power_proximity_rank[ally][0] and [1] (stride 5 int32s per power)
            candidates = [int(prox_rank[ally, 0]), int(prox_rank[ally, 1])]
        else:
            candidates = [top_enemy_1, top_enemy_2]
        for neighbor in candidates:
            if not (0 <= neighbor < num_powers) or neighbor == own_power:
                continue
            if (neighbor in (top_enemy_2, top_enemy_3)  # in own top-2/3 feared
                    and int(state.g_rank_matrix[own_power, neighbor]) < 3):
                state.g_enemy_flag[neighbor] = 1
                state.g_ally_trust_score[own_power, neighbor] = 0
                if hasattr(trust_hi_mat, '__setitem__'):
                    trust_hi_mat[own_power, neighbor] = 0

    # ── Weak-elimination + SC-grab pass (decompile lines 2168–2283) ──────────
    g_deceit = int(getattr(state, 'g_deceit_level', 0))
    g_infl_raw = getattr(state, 'g_influence_matrix_raw', state.g_influence_matrix)
    for p in range(num_powers):
        sc_p = int(state.sc_count[p])
        infl_own_p = float(state.g_influence_matrix[own_power, p])
        infl_p_own = float(state.g_influence_matrix[p, own_power])
        raw_own_p  = float(g_infl_raw[own_power, p])
        raw_p_own  = float(g_infl_raw[p, own_power])

        # Weak-elimination: g_deceit_level > 2 AND (sc < 3 OR high influence dominance)
        if g_deceit > 2 and (
                sc_p < 3 or (
                    infl_own_p > 0.0 and p != own_power
                    and raw_own_p / (raw_p_own + 1.0) > 4.5
                    and infl_p_own > 10.0
                )):
            state.g_enemy_flag[p] = 1
            state.g_ally_trust_score[own_power, p] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, p] = 0

        # SC-grab: own_sc < 4 AND vulnerable unguarded SC (decompile lines
        # 2200-2276). C reads g_contact_weighted (DAT_00b755cc) with ±21-int32
        # strides — interpretation as [own, p-1], [own, p], [own, p+1]
        # (adjacent-power contact counts). Proxy: use g_contact_weighted row for
        # own_power, require prev/cur positive and next zero + target_sc > 3.
        if own_sc < 4 and p != own_power and sc_p > 3:
            cw = getattr(state, 'g_contact_weighted', None)
            if cw is not None:
                p_prev = (p - 1) % num_powers
                p_next = (p + 1) % num_powers
                try:
                    if (int(cw[own_power, p_prev]) > 0
                            and int(cw[own_power, p]) > 0
                            and int(cw[own_power, p_next]) == 0):
                        state.g_enemy_flag[p] = 1
                        state.g_ally_trust_score[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
                except (IndexError, ValueError):
                    pass

    # ── Dominance sweep (decompile lines 2284–2328) ───────────────────────────
    # MUST come after all per-power passes above.
    # DAT_00baed6a = 0 first (reset), then check condition.
    # Condition: g_sc_percent[own] > 75.0 AND own_pct - g_sc_percent[local_128] >= 2.0
    # (Note: uses local_128 not max_pct; uses >= not >)
    # NOTE: second write of log-only g_leading_flag — see note at first write
    # above; no downstream C reads.  Kept for parity.
    state.g_leading_flag = 0
    if local_128 != own_power:
        lead_pct_dominate = float(state.g_sc_percent[local_128])
        if own_pct > 75.0 and (own_pct - lead_pct_dominate) >= 2.0:
            state.g_leading_flag = 1
            for k in range(num_powers):
                if k != own_power:
                    state.g_enemy_flag[k] = 1
                    state.g_ally_trust_score[own_power, k] = 0
                    if hasattr(trust_hi_mat, '__setitem__'):
                        trust_hi_mat[own_power, k] = 0

    # ── Alliance-agreement → enemy (decompile lines 2329–2403) ──────────────
    # Honor ally's declared enemies; conditions (decompile lines 2356–2363):
    #   g_enemy_flag[pow_b] == 0 (not yet enemy)
    #   auStack_dc[pow_a + 1] == 0  (pow_a has no prior alliance enforcement)
    #   g_ally_matrix[own][pow_b] == 1  (own allied with pow_b)
    #   DAT_004c6bc4 != pow_b  (pow_b is not opening best ally)
    #   g_ally_trust_score_hi[own][pow_b] < 1 AND (Hi<0 OR Lo<2)  (low trust)
    # opening_best_ally defined above (shared with gang-up)
    # Track which pow_a rows have already set an enemy (auStack_dc equivalent)
    pow_a_enforced = [False] * num_powers
    for pow_a in range(num_powers):
        for pow_b in range(num_powers):
            if pow_a_enforced[pow_a]:
                continue
            t_hi_b = int(trust_hi_mat[own_power, pow_b])
            t_lo_b = int(state.g_ally_trust_score[own_power, pow_b])
            if (state.g_enemy_flag[pow_b] == 0
                    and int(state.g_ally_matrix[pow_a, pow_b]) == 1
                    and int(state.g_ally_matrix[own_power, pow_b]) == 1
                    and pow_b != opening_best_ally
                    and t_hi_b < 1 and (t_hi_b < 0 or t_lo_b < 2)):
                state.g_enemy_flag[pow_b] = 1
                state.g_ally_trust_score[own_power, pow_b] = 0
                if hasattr(trust_hi_mat, '__setitem__'):
                    trust_hi_mat[own_power, pow_b] = 0
                pow_a_enforced[pow_a] = True
