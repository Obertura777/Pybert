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


def _fear_weighted_threshold(
    influence_1: float,
    trust_divisor_1: int,
    influence_2: float,
    trust_divisor_2: int,
) -> int:
    """Return Albert's x87 weighted random-selection threshold.

    The decompiler lost the floating-point expression passed through
    ``FloatToInt64``. Disassembly of Albert.exe at 0x429a25-0x429a58 and
    0x42a827-0x42a865 shows ``100*a/(a+b)``, where each ``a``/``b`` is the
    feared power's influence divided by its trust tier. FloatToInt64 then
    truncates toward zero.
    """
    weighted_1 = float(influence_1) / int(trust_divisor_1)
    weighted_2 = float(influence_2) / int(trust_divisor_2)
    total = weighted_1 + weighted_2
    if total == 0.0:
        return 0
    return int((weighted_1 * 100.0) / total)


def _populate_enemy_rank_matrix(
    state: InnerGameState,
    trust_hi_mat,
    num_powers: int = 7,
) -> None:
    """Build CAL_BOARD's enemy counts and ``DAT_00633780`` matrix.

    C first counts each row's live enemies.  It then writes that count to
    every non-enemy cell and ``count - 1`` to each enemy cell.  The matrix is
    therefore an enemy-count-with-this-power-excluded table, not the separate
    1-indexed influence ranking stored at ``DAT_006340c0``.
    """
    enemy_gate = np.zeros((num_powers, num_powers), dtype=np.int8)
    state.g_enemy_count.fill(0)

    for row in range(num_powers):
        for col in range(num_powers):
            trust_lo = int(state.g_ally_trust_score[row, col])
            trust_hi = int(trust_hi_mat[row, col])
            is_enemy = (
                row != col
                and trust_hi < 1
                and (trust_hi < 0 or trust_lo < 2)
                and float(state.g_influence_matrix[row, col]) > 0.0
                and int(state.g_target_sc_cnt[col]) > 2
            )
            if is_enemy:
                enemy_gate[row, col] = 1
                state.g_enemy_count[row] += 1

    for row in range(num_powers):
        enemy_count = int(state.g_enemy_count[row])
        for col in range(num_powers):
            state.g_rank_matrix[row, col] = (
                enemy_count - int(enemy_gate[row, col])
            )


def _apply_distressed_ally_rescue(
    state: InnerGameState,
    own_power: int,
    top_enemy_1: int,
    top_enemy_2: int,
    trust_hi_mat,
    num_powers: int = 7,
) -> None:
    """Port CAL_BOARD.c:2077-2166's distressed-ally enemy selection.

    ``DAT_00633f18`` is the inverse influence ranking populated by
    ComputeInfluenceMatrix. C tests each distressed ally's rank-1/rank-2
    powers against our rank-3/rank-4 powers, then applies the
    ``DAT_00633780 < 3`` enemy-exclusion gate. The outer threshold reads
    ``DAT_00634e90`` (relation score), not either trust word.
    """
    relation_gate = (
        int(state.g_relation_score[own_power, top_enemy_1]) > 30
        or int(state.g_relation_score[own_power, top_enemy_2]) > 30
    )
    if not relation_gate:
        return

    own_later_ranks = (
        int(state.g_ally_pref_ranking[own_power, 3]),
        int(state.g_ally_pref_ranking[own_power, 4]),
    )
    enemy_hi_arr = getattr(state, 'g_enemy_flag_hi', None)

    for ally in range(num_powers):
        enemy_hi = int(enemy_hi_arr[ally]) if enemy_hi_arr is not None else 0
        if (int(state.g_ally_distress_flag[ally]) != 1
                or int(state.g_enemy_flag[ally]) != 0
                or enemy_hi != 0):
            continue
        for rank in (1, 2):
            neighbor = int(state.g_ally_pref_ranking[ally, rank])
            if (not 0 <= neighbor < num_powers
                    or neighbor == own_power
                    or neighbor not in own_later_ranks
                    or int(state.g_rank_matrix[own_power, neighbor]) >= 3):
                continue

            state.g_ally_trust_score[own_power, neighbor] = 0
            trust_hi_mat[own_power, neighbor] = 0
            state.g_enemy_flag[neighbor] = 1
            if enemy_hi_arr is not None:
                enemy_hi_arr[neighbor] = 0

            # C clears the reverse one-point trust marker as well.
            if (int(state.g_ally_trust_score[neighbor, own_power]) == 1
                    and int(trust_hi_mat[neighbor, own_power]) == 0):
                state.g_ally_trust_score[neighbor, own_power] = 0
                trust_hi_mat[neighbor, own_power] = 0


def _apply_late_gang_up(
    state: InnerGameState,
    own_power: int,
    top_enemy_1: int,
    top_enemy_2: int,
    top_enemy_3: int,
    top_enemy_4: int,
    trust_hi_mat,
    num_powers: int = 7,
) -> None:
    """Port CAL_BOARD.c:1925-2076's symmetric gang-up block.

    A trusted top-two feared power can point us at feared power three or four,
    provided the other top-two power is already hostile, the enemy-exclusion
    count is below three, and the candidate pressures us more than we pressure
    it. The C block tries rank three before rank four.
    """
    raw = getattr(state, 'g_influence_matrix_raw', state.g_influence_matrix)
    enemy_hi_arr = getattr(state, 'g_enemy_flag_hi', None)

    def _hostile(source: int, target: int) -> bool:
        return (
            int(state.g_ally_trust_score[source, target]) == 0
            and int(trust_hi_mat[source, target]) == 0
        )

    def _good_ally(power: int) -> bool:
        trust_lo = int(state.g_ally_trust_score[own_power, power])
        trust_hi = int(trust_hi_mat[own_power, power])
        return trust_hi >= 0 and (trust_hi > 0 or trust_lo > 3)

    def _candidate_works(ally: int, target: int) -> bool:
        if not (0 <= target < num_powers) or target == own_power:
            return False
        if not _hostile(ally, target):
            return False
        return (
            float(raw[target, own_power])
            / (float(raw[own_power, target]) + 1.0)
            > 1.0
        )

    def _try_side(ally: int, opposing_top: int) -> bool:
        if not (0 <= ally < num_powers and 0 <= opposing_top < num_powers):
            return False
        if (not _good_ally(ally)
                or not _hostile(own_power, opposing_top)
                or int(state.g_rank_matrix[own_power, opposing_top]) >= 3):
            return False

        for target in (top_enemy_3, top_enemy_4):
            if not _candidate_works(ally, target):
                continue
            state.g_ally_trust_score[own_power, target] = 0
            trust_hi_mat[own_power, target] = 0
            state.g_enemy_flag[target] = 1
            if enemy_hi_arr is not None:
                enemy_hi_arr[target] = 0
            return True
        return False

    # The two source branches are mutually exclusive: one requires top one to
    # be trusted and top two hostile, while the other requires the reverse.
    if not _try_side(top_enemy_1, top_enemy_2):
        _try_side(top_enemy_2, top_enemy_1)


def _apply_validated_top3_gang_up(
    state: InnerGameState,
    own_power: int,
    top_enemy_1: int,
    top_enemy_2: int,
    opening_best_ally: int,
    trust_hi_mat,
) -> None:
    """Port the gang-up checks immediately after C validates feared #3.

    This is CAL_BOARD.c:1493-1557, a separate site from the later symmetric
    rank-three/rank-four block. It can add feared #2 through a strong #1 ally,
    or add feared #1 through a strong #2 ally.
    """
    raw = getattr(state, 'g_influence_matrix_raw', state.g_influence_matrix)
    enemy_hi_arr = getattr(state, 'g_enemy_flag_hi', None)

    def _hostile(source: int, target: int) -> bool:
        return (
            int(state.g_ally_trust_score[source, target]) == 0
            and int(trust_hi_mat[source, target]) == 0
        )

    def _mark(target: int) -> None:
        state.g_enemy_flag[target] = 1
        if enemy_hi_arr is not None:
            enemy_hi_arr[target] = 0
        state.g_ally_trust_score[own_power, target] = 0
        trust_hi_mat[own_power, target] = 0

    top1_lo = int(state.g_ally_trust_score[own_power, top_enemy_1])
    top1_hi = int(trust_hi_mat[own_power, top_enemy_1])
    top2_lo = int(state.g_ally_trust_score[own_power, top_enemy_2])
    top2_hi = int(trust_hi_mat[own_power, top_enemy_2])

    reverse_to_top1 = (
        top2_hi >= 0
        and (top2_hi > 0 or top2_lo >= 7)
        and opening_best_ally != top_enemy_1
        and int(state.g_rank_matrix[own_power, top_enemy_1]) <= 1
    )
    if reverse_to_top1:
        if (_hostile(top_enemy_1, top_enemy_2)
                and top_enemy_1 != own_power
                and float(raw[top_enemy_1, own_power])
                / (float(raw[own_power, top_enemy_1]) + 1.0) > 1.0):
            _mark(top_enemy_1)
        return

    if (top1_hi >= 0
            and (top1_hi > 0 or top1_lo > 6)
            and opening_best_ally != top_enemy_2
            and int(state.g_rank_matrix[own_power, top_enemy_2]) < 2
            and _hostile(top_enemy_2, top_enemy_1)
            and top_enemy_2 != own_power
            and float(raw[top_enemy_2, own_power])
            / (float(raw[own_power, top_enemy_2]) + 1.0) > 1.0):
        _mark(top_enemy_2)


def _is_weak_influence_target(
    state: InnerGameState,
    own_power: int,
    target: int,
) -> bool:
    """Return CAL_BOARD's directional 4.5x weak-power predicate."""
    raw = getattr(state, 'g_influence_matrix_raw', state.g_influence_matrix)
    return (
        float(state.g_influence_matrix[own_power, target]) > 0.0
        and target != own_power
        and float(raw[target, own_power])
        / (float(raw[own_power, target]) + 1.0) > 4.5
        and float(state.g_influence_matrix[target, own_power]) > 10.0
    )


def _apply_weak_elimination_and_sc_grab(
    state: InnerGameState,
    own_power: int,
    trust_hi_mat,
    num_powers: int = 7,
) -> None:
    """Port CAL_BOARD.c:2168-2283's per-power enemy pass."""
    deceit = int(getattr(state, 'g_deceit_level', 0))
    own_sc = int(state.g_target_sc_cnt[own_power])
    enemy_hi_arr = getattr(state, 'g_enemy_flag_hi', None)

    def _mark(power: int) -> None:
        state.g_enemy_flag[power] = 1
        if enemy_hi_arr is not None:
            enemy_hi_arr[power] = 0
        state.g_ally_trust_score[own_power, power] = 0
        trust_hi_mat[own_power, power] = 0
        if (int(state.g_ally_trust_score[power, own_power]) == 1
                and int(trust_hi_mat[power, own_power]) == 0):
            state.g_ally_trust_score[power, own_power] = 0
            trust_hi_mat[power, own_power] = 0

    for power in range(num_powers):
        sc_power = int(state.g_target_sc_cnt[power])
        weak = (
            sc_power < 3
            or _is_weak_influence_target(state, own_power, power)
        )
        if deceit > 2 and weak:
            _mark(power)

        vulnerable_sc = (
            int(state.g_contact_count[own_power, power]) > 0
            and int(state.g_contact_weighted[own_power, power]) > 0
            and int(state.g_contact_owner_count[own_power, power]) == 0
        )
        if vulnerable_sc and (
                own_sc < 4
                or int(state.g_influence_rank_flag[own_power, power]) > 3):
                _mark(power)


def _apply_dominance_sweep(
    state: InnerGameState,
    own_power: int,
    leading_other_power: int,
    trust_hi_mat,
    num_powers: int = 7,
) -> None:
    """Port CAL_BOARD.c:2284-2328's dominant-leader sweep."""
    state.g_leading_flag = 0
    own_pct = float(state.g_sc_percent[own_power])
    other_pct = float(state.g_sc_percent[leading_other_power])
    if not (own_pct > 75.0 and own_pct - other_pct >= 2.0):
        return

    state.g_leading_flag = 1
    for power in range(num_powers):
        if power == own_power:
            continue
        state.g_ally_trust_score[own_power, power] = 0
        trust_hi_mat[own_power, power] = 0
        state.g_enemy_flag[power] = 1
        state.g_enemy_flag_hi[power] = 0
        if (int(state.g_ally_trust_score[power, own_power]) == 1
                and int(trust_hi_mat[power, own_power]) == 0):
            state.g_ally_trust_score[power, own_power] = 0
            trust_hi_mat[power, own_power] = 0


def _apply_alliance_agreement_enemies(
    state: InnerGameState,
    own_power: int,
    opening_best_ally: int,
    trust_hi_mat,
    num_powers: int = 7,
) -> None:
    """Port CAL_BOARD.c:2329-2403's alliance-agreement enemy pass.

    C's first nested loop repeatedly overwrites ``auStack_dc[1..N]``. The
    surviving values are therefore the final power's ally-matrix row, not
    mutable per-declarer state. The second loop may honor multiple targets
    from one declaring power while both enemy int64 words remain clear.
    """
    if num_powers <= 0:
        return
    final_power = num_powers - 1
    final_row_allies = [
        int(state.g_ally_matrix[final_power, power]) == 1
        for power in range(num_powers)
    ]

    for declaring_power in range(num_powers):
        for target in range(num_powers):
            if (int(state.g_enemy_flag[declaring_power]) != 0
                    or int(state.g_enemy_flag_hi[declaring_power]) != 0
                    or int(state.g_enemy_flag[target]) != 0
                    or int(state.g_enemy_flag_hi[target]) != 0
                    or final_row_allies[declaring_power]
                    or int(state.g_ally_matrix[declaring_power, target]) != 1
                    or target == opening_best_ally):
                continue

            trust_lo = int(
                state.g_ally_trust_score[declaring_power, target]
            )
            trust_hi = int(trust_hi_mat[declaring_power, target])
            if not (trust_hi < 1
                    and (trust_hi < 0 or (trust_lo & 0xFFFFFFFF) < 2)):
                continue

            state.g_enemy_flag[target] = 1
            state.g_enemy_flag_hi[target] = 0
            state.g_ally_trust_score[own_power, target] = 0
            trust_hi_mat[own_power, target] = 0
            if (int(state.g_ally_trust_score[target, own_power]) == 1
                    and int(trust_hi_mat[target, own_power]) == 0):
                state.g_ally_trust_score[target, own_power] = 0
                trust_hi_mat[target, own_power] = 0


def cal_board(state: InnerGameState, own_power: int) -> None:
    """
    Port of CAL_BOARD (FUN_00427960).

    Strategic board evaluation engine, called once per turn before order
    generation.  Computes:
      - _g_NearEndGameFactor
      - g_power_exp_score  (quadratic power score)
      - g_sc_percent      (SC percentage per power, relative to win_threshold)
      - g_enemy_count     (genuine enemy count per power)
      - g_rank_matrix      (enemy-count-with-column-excluded matrix)
      - g_ally_pref_ranking / g_influence_rank_flag (influence ranking)
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

    # SC counts: CAL_BOARD reads `target_sc_cnt` at all 15 of its SC sites and
    # `curr_sc_cnt` at exactly one (the opening-ally demotion below).
    # InitScoringState.c:94 seeds target_sc_cnt from curr_sc_cnt and then
    # adjusts it ±1 per the urgency comparison, so the two are NOT the same
    # array — target_sc_cnt is the *projected* count, bound here as
    # state.g_target_sc_cnt.  GenerateOrders (→ InitScoringState) runs before
    # HOSTILITY (→ CAL_BOARD) in both GenerateAndSubmitOrders.c:318/479 and
    # bot/client/_orders.py, so the projection is populated by this point.
    # Corrected 2026-08-12: every site here previously read state.sc_count.

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
        sc = max(0, min(int(state.g_target_sc_cnt[k]), win_threshold))
        state.g_power_exp_score[k] = (sc ** 2) * 100.0 + 1.0

    # ── Phase 1b: NearEndGameFactor + g_sc_percent (Loop B in decompile) ──────
    # g_sc_percent[k] = sc[k] * 100 / win_threshold  (divisor = win threshold, NOT total SCs)
    # g_war_mode_flag reset to 0 before this loop (decompile line 121)
    state.g_war_mode_flag = 0
    near_end = 1.0

    own_sc = int(state.g_target_sc_cnt[own_power])
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
        sc = int(state.g_target_sc_cnt[k])
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

    # Opening-ally-slot promotion (decompile lines 148-156).  The C condition
    # is a comma-expression:
    #     if (slot0 >= 0 && curr_sc_cnt[slot0] < 2 && (slot0 = -1, slot1 >= 0))
    # so slot0 is cleared whenever it drops below 2 SCs, but the promotion
    # body only runs when slot1 is occupied — and slot2 is only touched from
    # inside that body.  This is the one site that reads curr_sc_cnt rather
    # than target_sc_cnt.
    # Corrected 2026-08-12: the previous version cleared slot2 (and moved it
    # into slot1) even when slot1 was empty, which C never does.
    try:
        s0 = int(getattr(state, 'g_best_ally_slot0', -1))
        s1 = int(getattr(state, 'g_best_ally_slot1', -1))
        s2 = int(getattr(state, 'g_best_ally_slot2', -1))
        if 0 <= s0 < num_powers and int(state.sc_count[s0]) < 2:
            state.g_best_ally_slot0 = -1
            if s1 >= 0:
                state.g_best_ally_slot0 = s1
                state.g_best_ally_slot1 = -1
                if s2 >= 0:
                    state.g_best_ally_slot1 = s2
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
    state.g_ally_distress_flag.fill(0)
    _populate_enemy_rank_matrix(state, trust_hi_mat, num_powers)

    # ── Phase 2b: ally distress flag (C lines 660-720) ────────────────────────
    # For each ally p: if own has high trust toward p, p is at war with BOTH
    # its top 2 enemies, and BOTH those enemies rank own_power as rank 1
    # (g_rank_matrix[enemy, own] == 1 — the 21-stride mutual-enemy
    # exclusion count), and the SC
    # balance condition holds → mark p as distressed.
    for ally in range(num_powers):
        if ally == own_power:
            continue
        t_hi = int(trust_hi_mat[own_power, ally])
        t_lo = int(state.g_ally_trust_score[own_power, ally])
        if not (t_hi >= 0 and (t_hi > 0 or t_lo > 6)):
            continue
        if int(state.g_target_sc_cnt[ally]) <= 2:
            continue
        enemy1 = int(state.g_ally_pref_ranking[ally, 1])
        enemy2 = int(state.g_ally_pref_ranking[ally, 2])
        if not (0 <= enemy1 < num_powers and 0 <= enemy2 < num_powers):
            continue
        if (int(state.g_ally_trust_score[ally, enemy1]) != 0
                or int(trust_hi_mat[ally, enemy1]) != 0):
            continue
        if (int(state.g_ally_trust_score[ally, enemy2]) != 0
                or int(trust_hi_mat[ally, enemy2]) != 0):
            continue
        # Both enemies must rank own_power as their #1 feared power.
        # sum == 2 is the minimum possible (both rank 1), matching C's
        # rank_matrix[enemy1,own]==1 AND rank_matrix[enemy2,own]==1.
        if (int(state.g_rank_matrix[enemy1, own_power]) != 1
                or int(state.g_rank_matrix[enemy2, own_power]) != 1):
            continue
        sc_ally = int(state.g_target_sc_cnt[ally])
        sc_e1 = int(state.g_target_sc_cnt[enemy1])
        sc_e2 = int(state.g_target_sc_cnt[enemy2])
        if not (sc_ally + 1 < sc_e1 + sc_e2 and sc_ally <= own_sc + 1):
            continue
        state.g_ally_distress_flag[ally] = 1

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
    # (decompile lines 729-820, local_fc initialised to -1 at line 85)
    #
    # C compares the *double* percentage against (double)local_fc — the
    # already-truncated running max — so a rival at 60.7 % still displaces a
    # leader recorded as 60.  Comparing int(pct) > local_fc (as this did
    # before 2026-08-12) silently dropped those updates.
    #
    # On an exact tie C runs a fear-based tie-break (decompile lines 736-755).
    # Collapsing its nested comparisons: the outer pair of int64 trust tests
    # can only both hold when trust(own, k) == trust(own, leader) in both
    # words, so the surviving conditions are equal trust, relation(own, k) <=
    # relation(own, leader), and rank_flag(own, k) < rank_flag(own, leader) —
    # i.e. switch to the power we fear less.  This matters most in the
    # opening, where six powers share the same SC%.
    local_fc: int = -1
    local_128: int = own_power  # sentinel (own_power used when no rival found)
    for k in range(num_powers):
        if k == own_power:
            continue
        pct = float(state.g_sc_percent[k])
        if pct > float(local_fc):
            local_fc = int(pct)   # FloatToInt64 truncates toward 0
            local_128 = k
        elif pct == float(local_fc) and local_128 != own_power:
            k_hi = int(trust_hi_mat[own_power, k])
            k_lo = int(state.g_ally_trust_score[own_power, k])
            l_hi = int(trust_hi_mat[own_power, local_128])
            l_lo = int(state.g_ally_trust_score[own_power, local_128])
            if (k_hi == l_hi and k_lo == l_lo
                    and int(state.g_relation_score[own_power, k])
                        <= int(state.g_relation_score[own_power, local_128])
                    and int(state.g_influence_rank_flag[own_power, k])
                        < int(state.g_influence_rank_flag[own_power, local_128])):
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
    # g_leading_flag is reset here and recomputed by the final dominance
    # sweep. EvaluateAllianceScore reads it to select the 1/16 candidate-
    # maximum penalty instead of the ordinary 1/8 scale.
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
        #   AND g_influence_rank_flag[own, leading] in {1, 2}
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
            # ── Per-power trust rewrite (decompile 937-1082) ─────────────
            # Ported 2026-08-12; this whole loop was previously collapsed to
            # the `local_fc >= 80` trust-zeroing below.  Pointer walks from
            # the C setup at :938-943, with pdVar15 = inner power:
            #   piVar20 (+1)      → g_relation_score[own, inner]
            #   piVar7  (+0x15)   → g_relation_score[inner, own]
            #   pdStack_118 (+1)  → int64 trust[own, inner]
            #   local_11c (+0x2a) → int64 trust[inner, local_128]
            for inner in range(num_powers):
                # C:946-948 — clear the enemy flag and stamp the near-victory
                # power into DAT_00b9fdd8[inner].
                state.g_enemy_flag[inner] = 0
                # DAT_00b9fdd8 is reused by HOSTILITY as the mutual-enemy
                # table. A later CAL_BOARD call leaves this near-victory value
                # in the same storage until HOSTILITY rebuilds the table.
                state.g_mutual_enemy_table[inner] = local_128

                if inner == local_128:
                    continue

                # C:950-952 — "at war with everyone" zeroing.
                # piStack_12c starts at &DAT_00633f1c and walks +5 ints per
                # inner power.  DAT_00633f18 is the base of a 5-int-per-power
                # record (confirmed by the unrolled 5x sentinel init at
                # 0040dbb4-0040dbbf, EDI = 0x633f1c covering f18..f28), and
                # ComputeInfluenceMatrix.c:238 fills it as the INVERSE of the
                # influence ranking:
                #     DAT_006340c0[p*21 + q] = rank      (g_influence_rank_flag)
                #     DAT_00633f18[p*5 + rank] = q       (rank -> power)
                # So *piStack_12c = DAT_00633f18[inner*5 + 1] = the power
                # ranked SECOND by influence from `inner`'s perspective.  That
                # is derivable from the rank matrix already on state, so no new
                # array is needed.  Ported 2026-08-12.
                rank1 = -1
                for q in range(num_powers):
                    if int(state.g_influence_rank_flag[inner, q]) == 1:
                        rank1 = q
                        break
                if (local_fc > 0x4f and 0 <= rank1 < num_powers
                        and float(state.g_sc_percent[rank1]) < 75.0):
                    state.g_relation_score[local_128, inner] = 0
                    state.g_ally_trust_score[local_128, inner] = 0
                    trust_hi_mat[local_128, inner] = 0

                rel_out = int(state.g_relation_score[own_power, inner])
                rel_in  = int(state.g_relation_score[inner, own_power])
                trust_zero = (
                    int(state.g_ally_trust_score[own_power, inner]) == 0
                    and int(trust_hi_mat[own_power, inner]) == 0
                )
                pct_inner = float(state.g_sc_percent[inner])

                if local_fc < 0x55:          # 85
                    if local_fc < 0x46 or not trust_zero:      # 70
                        # C:986-991 — only relax a negative outbound relation,
                        # and only when we hold no trust and it is not deeply
                        # negative.
                        if rel_out > -21 and trust_zero and rel_out < 0:
                            state.g_relation_score[own_power, inner] = 0
                    elif local_fc < 0x50:    # 80
                        if pct_inner >= 65.0:
                            if rel_out < -10:
                                state.g_relation_score[own_power, inner] = -10
                        elif rel_out < 0:
                            state.g_relation_score[own_power, inner] = 0
                        if rel_in < -10:
                            state.g_relation_score[inner, own_power] = -10
                    elif pct_inner >= 70.0:  # C:1004
                        if rel_out < 0:
                            state.g_relation_score[own_power, inner] = 0
                        if rel_in < 0:
                            state.g_relation_score[inner, own_power] = 0
                    else:                    # C:1013-1021
                        if rel_out < 0x0f:
                            state.g_relation_score[own_power, inner] = 0x0f
                        if rel_in < 5:
                            state.g_relation_score[inner, own_power] = 5
                        if hasattr(state, 'g_peace_counter'):
                            state.g_peace_counter[inner] = 0
                else:
                    # C:1023-1058 — "trusting every other power 100 percent".
                    # Blanket-set the inner power's relation COLUMN to 50,
                    # drop its trust toward the near-victory power, and clear
                    # that pair's relation/trust entirely.
                    for k in range(num_powers):
                        state.g_relation_score[k, inner] = 0x32
                    state.g_ally_trust_score[inner, local_128] = 0
                    trust_hi_mat[inner, local_128] = 0
                    state.g_relation_score[local_128, inner] = 0
                    state.g_ally_trust_score[local_128, inner] = 0
                    trust_hi_mat[local_128, inner] = 0
                    if pct_inner >= 75.0:
                        if rel_out < 5:
                            state.g_relation_score[own_power, inner] = 5
                        if rel_in < 0:
                            state.g_relation_score[inner, own_power] = 0
                    else:
                        state.g_relation_score[own_power, inner] = 0x32
                        if rel_in < 0x0f:
                            state.g_relation_score[inner, own_power] = 0x0f
                    if hasattr(state, 'g_peace_counter'):
                        state.g_peace_counter[inner] = 0

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
                        if int(state.g_target_sc_cnt[p]) < 2:
                            state.g_enemy_flag[p] = 1
                            state.g_ally_trust_score[own_power, p] = 0
                            if hasattr(trust_hi_mat, '__setitem__'):
                                trust_hi_mat[own_power, p] = 0
            else:
                # local_fc <= 75 AND leading_pct > own_pct
                for p in range(num_powers):
                    sc_p = int(state.g_target_sc_cnt[p])
                    if (sc_p < 2
                            or _is_weak_influence_target(state, own_power, p)):
                        state.g_enemy_flag[p] = 1
                        state.g_ally_trust_score[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
        # goto LAB_0042bff2 — skip all remaining passes
        return  # early exit; function writes are complete

    # C:1093 jumps directly to function end while HOSTILITY says an enemy is
    # not desired. A near-victory keep-alliance decision (bVar26) still reaches
    # this gate and, when enabled, continues through normal selection.
    g_stabbed = int(getattr(state, 'g_stabbed_flag', 0))
    if g_stabbed == 0:
        return

    # ── Phase 4c: normal enemy selection (LAB_00429317, lines 1091-1810) ───
    # The near-victory-enemy path returned above; every other source path enters
    # this scoped block, including bVar26's keep-alliance path.
    if not state.g_other_power_lead_flag:
        from .. import rng as _random
        g_opening_sticky = int(getattr(state, 'g_opening_sticky_mode', 0))
        g_deceit = int(getattr(state, 'g_deceit_level', 0))
        g_opening_enemy = int(getattr(state, 'g_opening_enemy', -1))

        enemy_selected = False

        t_hi_1 = int(trust_hi_mat[own_power, top_enemy_1])
        t_lo_1 = int(state.g_ally_trust_score[own_power, top_enemy_1])
        t_hi_2 = int(trust_hi_mat[own_power, top_enemy_2])
        t_lo_2 = int(state.g_ally_trust_score[own_power, top_enemy_2])
        t_hi_3 = int(trust_hi_mat[own_power, top_enemy_3])
        t_lo_3 = int(state.g_ally_trust_score[own_power, top_enemy_3])

        # DAT_00634e90 — written by FRIENDLY.c / CAL_BOARD.c.  This used to
        # read g_relation_history, a duplicate binding nothing wrote.
        rel_hist = getattr(state, 'g_relation_score', None)
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

        # Branch precedence (C decompile 1101/1219): the "at war with both
        # top-2 enemies" test is the OUTER if, and opening-sticky lives in its
        # else.  Evaluating sticky first — as this did before 2026-08-12 —
        # inverted that, letting a sticky opening enemy override a live
        # two-front war.
        at_war_1 = (t_hi_1 == 0 and t_lo_1 == 0)
        at_war_2 = (t_hi_2 == 0 and t_lo_2 == 0)
        at_war_3 = (t_hi_3 == 0 and t_lo_3 == 0)
        # C's entry test (decompile 1093-1096) is trust-only; the
        # top_enemy_2 == own_power case is handled *inside* the branch at
        # line 1121, not excluded from it.  Requiring it here skipped the
        # whole branch — and its `enemy_flag[enemy1] = 1` — in that case.
        both_zero = at_war_1 and at_war_2

        if not enemy_selected and both_zero:
            # C line 1105: "We are at war with our top 2 enemies"
            if top_enemy_2 == own_power:
                state.g_enemy_flag[top_enemy_1] = 1
                enemy_selected = True
            elif hist_2 <= hist_1:
                # Lines 1125-1196: peace-signal / neutral / random
                # C: g_peace_counter[enemy]==0 (DAT_004cf4c0/c4, both int32 halves of int64)
                #    && DAT_0062b7b0[other_enemy]==0  → pick other_enemy
                # C:1126-1161 tests each feared power's peace counter and
                # neutral marker in turn. A clear pair for #2 selects #1; if
                # that fails, a clear pair for #1 selects #2.
                n1 = _neutral(top_enemy_1)
                n2 = _neutral(top_enemy_2)
                peace_ctr = getattr(state, 'g_peace_counter', None)
                pc1_zero = peace_ctr is None or peace_ctr[top_enemy_1] == 0
                pc2_zero = peace_ctr is None or peace_ctr[top_enemy_2] == 0

                if pc2_zero and (not n2):
                    state.g_enemy_flag[top_enemy_1] = 1
                elif pc1_zero and (not n1):
                    state.g_enemy_flag[top_enemy_2] = 1
                else:
                    # Albert.exe 0x429626-0x429669: 100*inf1/(inf1+inf2).
                    inf_alt = state.g_influence_matrix
                    inf1 = float(inf_alt[own_power, top_enemy_1])
                    inf2 = float(inf_alt[own_power, top_enemy_2])
                    threshold = _fear_weighted_threshold(inf1, 1, inf2, 1)
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

        # Branch 1 (C line 1226): opening-sticky mode.  Lives in the ELSE of
        # the two-front-war test above, so it only runs when that did not fire.
        if not enemy_selected and (
                g_opening_sticky == 1 and g_deceit < 3
                and 0 <= g_opening_enemy < num_powers):
            state.g_enemy_flag[g_opening_enemy] = 1
            state.g_ally_trust_score[own_power, g_opening_enemy] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, g_opening_enemy] = 0
            enemy_selected = True

        # Branch 3 (C line 1256-1259): at war with exactly one
        if not enemy_selected and (at_war_1 or at_war_2 or at_war_3):
            # "at war with at least one of our Top 3 enemies — validate"
            if at_war_1:
                # Trust[#1]==0: validate #1 as enemy
                state.g_enemy_flag[top_enemy_1] = 1
                enemy_selected = True
            else:
                # #1 has trust. C may keep hostile #2, validate hostile #3,
                # or rechoose after checking influence, power, and opening-
                # alliance constraints.
                # Top-3 enemy (local_f0) trust check
                top_e3_trust_lo = t_lo_3
                top_e3_trust_hi = t_hi_3

                # Influence matrix alt check (C lines 1296-1302)
                inf_alt = state.g_influence_matrix
                power_exp = getattr(state, 'g_power_exp_score', None)
                dac_4c6bc4 = int(getattr(state, 'g_opening_best_ally',
                                          getattr(state, 'g_best_ally_slot0', -1)))

                # C:1296-1305 decides whether #3 must be inspected. If it does
                # not, C validates #2 at 1559. If it does, #3 is validated only
                # when its trust and all three influence thresholds pass.
                inf_1_val = float(inf_alt[own_power, top_enemy_1])
                inf_2_val = float(inf_alt[own_power, top_enemy_2])
                inf_3_val = float(inf_alt[own_power, top_enemy_3])
                ratio_21 = (inf_2_val * 100.0) / (inf_1_val + 1.0)
                pe_own = float(power_exp[own_power])
                pe_1 = float(power_exp[top_enemy_1])
                power_gate_fails = (pe_own - pe_1 * 1.7) + 69.0 <= 0.0

                inspect_third = (
                    t_lo_2 != 0
                    or t_hi_2 != 0
                    or top_enemy_2 == own_power
                    or ratio_21 <= 20.0
                    or (ratio_21 <= 70.0 and power_gate_fails)
                )
                third_rejected = True
                rechoose_rolls = None
                if inspect_third:
                    third_rejected = (
                        top_e3_trust_lo != 0
                        or top_e3_trust_hi != 0
                        or inf_3_val <= 15.0
                        or top_enemy_3 == own_power
                    )
                    if not third_rejected:
                        ratio_31 = (inf_3_val * 100.0) / (inf_1_val + 1.0)
                        ratio_32 = (inf_3_val * 100.0) / (inf_2_val + 1.0)
                        third_rejected = (
                            ratio_31 <= 20.0
                            or ratio_32 <= 50.0
                            or (ratio_21 <= 70.0 and power_gate_fails)
                        )

                if inspect_third and not third_rejected:
                    state.g_enemy_flag[top_enemy_3] = 1
                    state.g_enemy_flag_hi[top_enemy_3] = 0
                    _apply_validated_top3_gang_up(
                        state, own_power, top_enemy_1, top_enemy_2,
                        dac_4c6bc4, trust_hi_mat,
                    )
                    enemy_selected = True
                elif not inspect_third:
                    # C:1559-1571: feared #2 still meets the criteria, so keep
                    # the current war instead of entering the rechoose block.
                    state.g_enemy_flag[top_enemy_2] = 1
                    state.g_enemy_flag_hi[top_enemy_2] = 0
                    enemy_selected = True
                else:
                    # C LAB_0042a6ef: "rechoose a new one"
                    r1 = (_random.randint(0, 32767) // 0x17) % 50
                    r2 = (_random.randint(0, 32767) // 0x17) % 50
                    rechoose_rolls = (r1, r2)

                    # Opening alliance preservation (C lines 1400-1427)
                    if dac_4c6bc4 >= 0 and top_enemy_1 != dac_4c6bc4 and top_enemy_2 == dac_4c6bc4:
                        # enemy2 is our opening best ally — try to preserve
                        if top_enemy_2 != own_power:
                            inf_2_val = float(inf_alt[own_power, top_enemy_2])
                            inf_1_val = float(inf_alt[own_power, top_enemy_1])
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
                    inf_1_val = float(inf_alt[own_power, top_enemy_1])
                    inf_2_val = float(inf_alt[own_power, top_enemy_2])
                    tier_1 = 1
                    if t_hi_1 >= 0 and (t_hi_1 > 0 or t_lo_1 > 2):
                        tier_1 = 3 if t_hi_1 == 0 and t_lo_1 < 5 else 4
                    tier_2 = 1
                    if t_hi_2 >= 0 and (t_hi_2 > 0 or t_lo_2 > 2):
                        tier_2 = 3 if t_hi_2 == 0 and t_lo_2 < 5 else 4
                    threshold = _fear_weighted_threshold(
                        inf_1_val, tier_1, inf_2_val, tier_2,
                    )

                    if rechoose_rolls is None:
                        r1 = (_random.randint(0, 32767) // 0x17) % 50
                        r2 = (_random.randint(0, 32767) // 0x17) % 50
                    else:
                        r1, r2 = rechoose_rolls
                    if (r2 + r1 < threshold) or (top_enemy_2 == own_power):
                        state.g_enemy_flag[top_enemy_1] = 1
                        state.g_ally_trust_score[own_power, top_enemy_1] = 0
                        trust_hi_mat[own_power, top_enemy_1] = 0
                    else:
                        state.g_enemy_flag[top_enemy_2] = 1
                        state.g_ally_trust_score[own_power, top_enemy_2] = 0
                        trust_hi_mat[own_power, top_enemy_2] = 0
                    enemy_selected = True

        # C:1586-1590 permits peace selection only for three non-negative,
        # non-zero trust pairs, and suppresses it for highly deceitful powers
        # that already have more than two enemies.
        peace_selection_allowed = (
            not (t_hi_1 < 0 or (t_hi_1 < 1 and t_lo_1 == 0))
            and not (t_hi_2 < 0 or (t_hi_2 < 1 and t_lo_2 == 0))
            and not (t_hi_3 < 0 or (t_hi_3 < 1 and t_lo_3 == 0))
            and not (int(state.g_enemy_count[own_power]) > 2 and g_deceit > 2)
        )

        # Branch 4 (C lines 1591-1809): peace with all top enemies — random
        # weighted selection with trust tiers and opening-alliance preservation.
        if not enemy_selected and peace_selection_allowed:
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

            inf_alt = state.g_influence_matrix
            inf1 = float(inf_alt[own_power, top_enemy_1])
            inf2 = float(inf_alt[own_power, top_enemy_2])
            threshold = _fear_weighted_threshold(
                inf1, tier_1, inf2, tier_2,
            )

            history_counter = int(getattr(state, 'g_history_counter', 0))
            dac_4c6bc4_b4 = int(getattr(state, 'g_best_ally_slot0',
                                         getattr(state, 'g_opening_best_ally', -1)))
            power_exp = getattr(state, 'g_power_exp_score', None)

            # Opening-alliance preservation / late-game selection (C lines 1626-1799)
            b4_done = False
            _enter_opening = history_counter < 10  # C: g_HistoryCounter < 10 → LAB_00429d0f

            def _mark_branch4_enemy(target: int) -> None:
                """Apply the shared C:1804-1809 enemy/trust cleanup."""
                state.g_enemy_flag[target] = 1
                state.g_enemy_flag_hi[target] = 0
                state.g_ally_trust_score[own_power, target] = 0
                trust_hi_mat[own_power, target] = 0
                if (int(state.g_ally_trust_score[target, own_power]) == 1
                        and int(trust_hi_mat[target, own_power]) == 0):
                    state.g_ally_trust_score[target, own_power] = 0
                    trust_hi_mat[target, own_power] = 0

            if not _enter_opening:
                # C lines 1730-1799: late-game branch (g_HistoryCounter >= 10)

                # Coalition counts: powers allied with top_enemy_1 (ec) and top_enemy_2 (lc)
                # C lines 556-604 (ally counts built in earlier loop; reconstructed here)
                ally_mat = getattr(state, 'g_ally_matrix', None)
                if ally_mat is not None:
                    ec = sum(1 for p in range(num_powers)
                             if p != top_enemy_2 and int(ally_mat[p, top_enemy_1]) == 1)
                    lc = sum(1 for p in range(num_powers)
                             if p != top_enemy_1 and int(ally_mat[p, top_enemy_2]) == 1)
                    if dac_4c6bc4_b4 == top_enemy_1:
                        ec -= 1
                    elif dac_4c6bc4_b4 == top_enemy_2:
                        lc -= 1
                else:
                    ec = lc = 0

                # C lines 1731-1766: preliminary top_enemy_1 selection
                inf1_lg = float(inf_alt[own_power, top_enemy_1])
                fvar28_lg = (inf1_lg * 100.0) / (inf1_lg + 1.0)
                if dac_4c6bc4_b4 != top_enemy_1 and lc < ec and fvar28_lg > 20.0:
                    pe_ok_lg = fvar28_lg > 70.0
                    if not pe_ok_lg and power_exp is not None:
                        pe_own_lg = float(power_exp[own_power]) \
                            if hasattr(power_exp, '__getitem__') else 0.0
                        pe_te1_lg = float(power_exp[top_enemy_1]) \
                            if hasattr(power_exp, '__getitem__') else 0.0
                        if (pe_own_lg - pe_te1_lg * 1.7) + 69.0 > 0.0:
                            pe_ok_lg = True
                    if pe_ok_lg:
                        _mark_branch4_enemy(top_enemy_1)

                # C lines 1767-1774: secondary gate — redirect to opening block if any holds
                inf2_sg = float(inf_alt[own_power, top_enemy_2])
                fvar28_sg = (inf2_sg * 100.0) / (inf2_sg + 1.0)
                pe_fail_sg = (
                    fvar28_sg <= 70.0 and power_exp is not None
                    and ((float(power_exp[own_power]) if hasattr(power_exp, '__getitem__') else 0.0)
                         - (float(power_exp[top_enemy_2]) if hasattr(power_exp, '__getitem__') else 0.0)
                         * 1.7 + 69.0) <= 0.0
                )
                if (history_counter < 10 or dac_4c6bc4_b4 == top_enemy_2
                        or lc <= ec or fvar28_sg <= 20.0 or pe_fail_sg):
                    _enter_opening = True
                else:
                    # C lines 1775-1799: late-game identified enemy = top_enemy_2
                    _mark_branch4_enemy(top_enemy_2)
                    b4_done = True

            if _enter_opening:
                # C: LAB_00429d0f — opening-alliance preservation
                if dac_4c6bc4_b4 >= 0:
                    if top_enemy_1 == dac_4c6bc4_b4:
                        # enemy1 IS opening ally → pick enemy2, keep alliance
                        _mark_branch4_enemy(top_enemy_2)
                        b4_done = True
                    elif (top_enemy_2 != dac_4c6bc4_b4
                          or top_enemy_2 == own_power):
                        pass  # fall to LAB_00429efb (random selection)
                    else:
                        # enemy2 IS opening ally — check if enemy1 is viable
                        if top_enemy_1 != own_power:
                            inf_1_val = float(inf_alt[own_power, top_enemy_1])
                            inf_2_val = float(inf_alt[own_power, top_enemy_2])
                            ratio_b4 = (inf_2_val * 100.0) / (inf_1_val + 1.0)
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
                                    _mark_branch4_enemy(top_enemy_1)
                                    b4_done = True

            # LAB_00429efb: random threshold selection
            if not b4_done:
                if rand_sum < threshold or top_enemy_2 == own_power:
                    _mark_branch4_enemy(top_enemy_1)
                else:
                    _mark_branch4_enemy(top_enemy_2)
            enemy_selected = True

    # Opening best ally lookup (used by alliance-agreement below).
    opening_best_ally = int(getattr(state, 'g_best_ally_slot0',
                                    getattr(state, 'g_opening_best_ally', -1)))

    # ── Late symmetric gang-up block (C:1925–2076) ───────────────────
    # This exact late block uses top one/two as allies and tries top three,
    # then inverse-rank slot four, as the shared enemy.
    top_enemy_4 = int(state.g_ally_pref_ranking[own_power, 4])
    _apply_late_gang_up(
        state, own_power, top_enemy_1, top_enemy_2,
        top_enemy_3, top_enemy_4, trust_hi_mat, num_powers,
    )

    # ── LAB_0042b203: distressed-ally rescue (C:2077–2166) ────────────
    _apply_distressed_ally_rescue(
        state, own_power, top_enemy_1, top_enemy_2,
        trust_hi_mat, num_powers,
    )

    # ── Weak-elimination + two SC-grab branches (C:2168–2283) ───────
    _apply_weak_elimination_and_sc_grab(
        state, own_power, trust_hi_mat, num_powers,
    )

    # ── Dominance sweep (decompile lines 2284–2328) ───────────────────────────
    # MUST come after all per-power passes above.
    # DAT_00baed6a = 0 first (reset), then check condition.
    # Condition: g_sc_percent[own] > 75.0 AND own_pct - g_sc_percent[local_128] >= 2.0
    # (Note: uses local_128 not max_pct; uses >= not >)
    # EvaluateAllianceScore reads this flag to halve its candidate-maximum
    # penalty (Albert.exe 0x43d738-0x43d75d).
    _apply_dominance_sweep(
        state, own_power, local_128, trust_hi_mat, num_powers,
    )

    # ── Alliance-agreement → enemy (decompile lines 2329–2403) ──────────────
    # The helper preserves the final-row auStack_dc snapshot and both-word
    # enemy gates before honoring each declaring power's low-trust targets.
    _apply_alliance_agreement_enemies(
        state, own_power, opening_best_ally, trust_hi_mat, num_powers,
    )
