import asyncio
import logging
import random
import time

import numpy as np
from diplomacy.client.connection import connect

from .state import InnerGameState
from .monte_carlo import (
    process_turn,
    update_score_state,
    check_time_limit,
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from .communications import (
    parse_message,
    dispatch_scheduled_press,
    cancel_prior_press,
    friendly,
)
from .heuristics import (
    cal_board,
    compute_draw_vote, detect_stabs_and_hostility,
    post_process_orders, compute_press, compute_influence_matrix,
    _safe_pow,
)
from .dispatch import dispatch_single_order
from .utils import dipnet_order  # noqa: F401 — re-exported for callers

logger = logging.getLogger(__name__)

_POWER_NAMES = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]

# DAIDE coast token value → DipNet coast suffix (subset covering standard coasts)
_DAIDE_COAST_TO_STR = {
    0x4600: 'NC', 0x4602: 'NE', 0x4604: 'EC',
    0x4606: 'SC', 0x4608: 'SC', 0x460A: 'SW',
    0x460C: 'WC', 0x460E: 'NW',
    0: '',
}

# Power index → DAIDE short token name (AUS=0x4100 … TUR=0x4106)
_DAIDE_POWER_NAMES = ['AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']


# ── Stub sub-functions (unimplemented; named after research.md §sub-function table) ──

def _phase_handler(state: InnerGameState, phase: int) -> None:
    """PhaseHandler (FUN_0040df20).

    Snapshots g_AllyTrustScore and g_RelationScore (DAT_00634e90) into
    phase-indexed arrays at each sub-phase boundary (phase 0–3).

    research.md §6534:
      idx = power + phase * 21
      g_InfluenceSnapshot[idx, j] ← g_RelationScore[power, j]
      g_TrustSnapshot[idx, j]     ← g_AllyTrustScore[power, j]  (lo + hi word)
    """
    num_powers = 7

    if not hasattr(state, 'g_TrustSnapshot'):
        # 4 phases × up to 21 powers; each entry holds one row of 7 values
        state.g_TrustSnapshot    = np.zeros((4 * 21, 7), dtype=np.float64)
        state.g_TrustSnapshot_Hi = np.zeros((4 * 21, 7), dtype=np.int32)
        state.g_InfluenceSnapshot = np.zeros((4 * 21, 7), dtype=np.int32)

    for power in range(num_powers):
        idx = power + phase * 21
        for j in range(num_powers):
            state.g_InfluenceSnapshot[idx, j] = int(state.g_RelationScore[power, j])
            state.g_TrustSnapshot[idx, j]     = float(state.g_AllyTrustScore[power, j])
            state.g_TrustSnapshot_Hi[idx, j]  = int(state.g_AllyTrustScore_Hi[power, j])


def _analyze_position(state: InnerGameState) -> None:
    """AnalyzePosition (FUN_004119d0).

    Counts live units per power and writes the result into g_UnitCount
    (DAT_0062e460).  research.md §6560 corrects the prior "has-alliance flag"
    label: this array is a plain unit-count; non-zero ↔ power has units.
    """
    state.g_UnitCount.fill(0)
    for unit in state.unit_info.values():
        power = unit.get('power', -1)
        if 0 <= power < 7:
            state.g_UnitCount[power] += 1


def _move_analysis(state: InnerGameState) -> None:
    """MOVE_ANALYSIS (FUN_~0x435400).

    Evaluates inter-power pressure from the current order table and updates
    g_AllyTrustScore based on observed aggression ratios.  On exactly one
    hostile power detected, sets g_OpeningStickyMode and g_OpeningEnemy.

    Four phases per research.md §6582:
      1. Build reachability table (reach 1=reachable, 2=contested, 3=threatening)
      2. Count pressuring units  (b5e8[a][b])
      3. Trust updates           (ratio logic)
      4. Opening ally selection  (compact slots, detect single enemy)
    """
    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)

    # --- Phase 1 — reachability table ----------------------------------------
    reach = np.zeros((num_powers, 256), dtype=np.int32)
    bcd0  = np.zeros((num_powers, num_powers), dtype=np.int32)  # moves/convoys a→b
    af00  = np.zeros((num_powers, num_powers), dtype=np.int32)  # ally units near convoy dest
    b5e8  = np.zeros((num_powers, num_powers), dtype=np.int32)  # units of a pressuring b

    for prov, unit in state.unit_info.items():
        a = unit.get('power', -1)
        if a < 0:
            continue
        reach[a, prov] = max(reach[a, prov], 1)
        for adj in state.adj_matrix.get(prov, []):
            b = state.get_unit_power(adj)
            if 0 <= b != a and reach[a, adj] == 1:
                reach[a, adj] = 2

        order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
        dest       = int(state.g_OrderTable[prov, _F_DEST_PROV])

        if order_type == _ORDER_CTO:
            if 0 <= dest < 256 and reach[a, dest] == 2:
                reach[a, dest] = 3
                dest_power = state.get_unit_power(dest)
                if 0 <= dest_power != a:
                    bcd0[a, dest_power] += 1
                for adj2 in state.adj_matrix.get(dest, []):
                    if state.get_unit_power(adj2) == a:
                        af00[a, max(dest_power, 0)] += 1
        elif order_type in (_ORDER_MTO, _ORDER_SUP_MTO):
            if 0 <= dest < 256 and reach[a, dest] == 3:
                reach[a, dest] = 2

    # --- Phase 2 — count pressuring units ------------------------------------
    for prov, unit in state.unit_info.items():
        a = unit.get('power', -1)
        if a < 0:
            continue
        for adj in state.adj_matrix.get(prov, []):
            b = state.get_unit_power(adj)
            if 0 <= b != a and reach[a, adj] >= 2:
                b5e8[a, b] += 1

    # --- Phase 3 — trust updates ---------------------------------------------
    trust = state.g_AllyTrustScore  # float64 (7,7) in-place

    for a in range(num_powers):
        for b in range(num_powers):
            if a == b:
                continue
            ratio_ab = float(bcd0[a, b]) / b5e8[a, b] if b5e8[a, b] > 0 else -1.0
            ratio_ba = float(bcd0[b, a]) / b5e8[b, a] if b5e8[b, a] > 0 else -1.0

            if ratio_ab < 0:
                continue  # no pressure from a toward b

            if ratio_ab == 0.0 and ratio_ba == 0.0:
                trust[a, b] = 5
            elif ratio_ab == 1.0 and b5e8[a, b] == 1 and af00[a, b] == 0 and trust[a, b] > 1:
                trust[a, b] = 2   # bounced — may still ally
            elif ratio_ab >= 0.55 and trust[a, b] < 5:
                trust[a, b] = 1   # high aggression → hostile
            elif ratio_ab < 0.55:
                trust[a, b] += 1
                if ratio_ba == 0.0:
                    trust[a, b] += 1

    # Best ally fully pressured by one power → g_AllyUnderAttack
    best_ally = getattr(state, 'g_BestAllySlot0', -1)
    if 0 <= best_ally < num_powers:
        for c in range(num_powers):
            if c != best_ally and bcd0[best_ally, c] > 1 and bcd0[best_ally, c] == b5e8[best_ally, c]:
                state.g_AllyUnderAttack = 1
                break

    # --- Phase 4 — opening ally selection ------------------------------------
    # Invalidate ally slots where trust has degraded to ≥ 2
    for attr in ('g_BestAllySlot0', 'g_BestAllySlot1', 'g_BestAllySlot2'):
        slot = getattr(state, attr, -1)
        if 0 <= slot < num_powers and trust[own_power, slot] >= 2:
            setattr(state, attr, -1)

    # Compact: shift valid slots to front
    slots = [getattr(state, f'g_BestAllySlot{i}', -1) for i in range(3)]
    valid = [s for s in slots if s >= 0]
    while len(valid) < 3:
        valid.append(-1)
    state.g_BestAllySlot0, state.g_BestAllySlot1, state.g_BestAllySlot2 = valid

    # Detect single hostile power → sticky enemy mode
    hostile = [p for p in range(num_powers) if p != own_power and trust[own_power, p] == 1]
    if len(hostile) == 1:
        p = hostile[0]
        state.g_OpeningStickyMode = 1
        state.g_OpeningEnemy      = p
        trust[own_power, p]       = 0
        state.g_StabbedFlag       = 1   # DAT_00baed5f = g_EnemyDesired
        logger.debug("Enemy set to single original enemy: power %d", p)

    # Triple-front mode: demote all trust-3 entries to trust-1
    if getattr(state, 'g_TripleFrontFlag', 0) == 1:
        for p in range(num_powers):
            if trust[own_power, p] == 3:
                trust[own_power, p] = 1


def _post_process_orders(state: InnerGameState) -> None:
    """PostProcessOrders (FUN_00411120). Decays g_MoveHistoryMatrix and
    updates it from submitted-order outcomes. research.md §2039."""
    post_process_orders(state)


def _compute_press(state: InnerGameState) -> None:
    """ComputePress (FUN_004401f0). Builds g_PressMatrix / g_PressCount.
    research.md §1295."""
    compute_press(state)


def _stabbed(state: InnerGameState) -> None:
    """STABBED (FUN_0042c730). Stab detection in move phase.
    Year-1 fall/retreat — detect if ally betrayed us. Also writes g_OpeningStickyMode."""
    own_power = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # Phase 0: Init pass
    state.g_StabFlag.fill(0)
    state.g_NeutralFlag.fill(0)
    state.g_CeaseFire.fill(0)
    state.g_PeaceSignal.fill(0)
    if state.g_season == 'SPR':
        state.g_CoopScoreFlag_A.fill(0)
    elif state.g_season == 'FAL':
        state.g_CoopScoreFlag_B.fill(0)

    # Core logic comparison vs expected orders deferred to heuristics fallback
    detect_stabs_and_hostility(state, own_power)

    # Apply stab consequences (victim perspective)
    for col in range(num_powers):
        if state.g_StabFlag[col, own_power] == 1:
            logger.info(f"We have been stabbed by ({col}) during the turn")
            state.g_StabbedFlag = 1
            state.g_AllyPromiseList = getattr(state, 'g_AllyPromiseList', np.zeros(num_powers))
            state.g_AllyCounterList = getattr(state, 'g_AllyCounterList', np.zeros(num_powers))
            state.g_AllyPromiseList[col] = 0
            state.g_AllyCounterList[col] = 0
            
            if state.g_season in ('SUM', 'FAL'):
                state.g_CoopScoreFlag_A[col, own_power] = 1
            else:
                state.g_CoopScoreFlag_B[col, own_power] = 1

            state.g_AllyTrustScore[col, own_power] = 0
            state.g_AllyTrustScore[own_power, col] = 0
            
            # g_EnemySlot priority queue push-front LRU
            slots = [s for s in getattr(state, 'g_EnemySlot', [-1]*3) if s != col and s != -1]
            slots.insert(0, col)
            while len(slots) < 3:
                slots.append(-1)
            state.g_EnemySlot = slots[:3]

            if getattr(state, 'g_OpeningStickyMode', 0) == 1 and getattr(state, 'g_OpeningEnemy', -1) != col:
                state.g_OpeningStickyMode = 0


def _deviate_move(state: InnerGameState) -> None:
    """DEVIATE_MOVE (FUN_0043a000). Stab detection engine for retreat phase.
    Year >= 2 or retreat phase — handle ally deviation."""
    own_power = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # Phase 0: Init pass
    state.g_StabFlag.fill(0)
    state.g_NeutralFlag.fill(0)
    state.g_CeaseFire.fill(0)
    state.g_PeaceSignal.fill(0)
    if state.g_season == 'SPR':
        state.g_CoopScoreFlag_A.fill(0)
    elif state.g_season == 'FAL':
        state.g_CoopScoreFlag_B.fill(0)

    # Detect deviation orders vs expected targets
    detect_stabs_and_hostility(state, own_power)

    # Handle the stab consequences
    for attacker in range(num_powers):
        if state.g_StabFlag[attacker, own_power] == 1:
            if getattr(state, 'g_NearEndGameFactor', 0.0) >= 4.0:
                continue # End game exception
                
            state.g_AllyTrustScore[attacker, own_power] = 0
            state.g_AllyTrustScore[own_power, attacker] = 0
            
            for j in range(num_powers):
                state.g_AllyMatrix[attacker, j] = 0
                state.g_AllyMatrix[own_power, j] = 0

            slots = [s for s in getattr(state, 'g_EnemySlot', [-1]*3) if s != attacker and s != -1]
            slots.insert(0, attacker)
            while len(slots) < 3:
                slots.append(-1)
            state.g_EnemySlot = slots[:3]

            if getattr(state, 'g_OpeningStickyMode', 0) == 1 and getattr(state, 'g_OpeningEnemy', -1) != attacker:
                state.g_OpeningStickyMode = 0


def _friendly(state: InnerGameState) -> None:
    """FRIENDLY (FUN_0042dc40). Per-turn power×power relationship and alliance
    state update. research.md §4364."""
    friendly(state)


def _hostility(state: InnerGameState) -> None:
    """HOSTILITY (FUN_~0x42F200).

    Highest-level per-turn diplomatic strategy function.  research.md §6649.

    Block 1 — enemy activation: random roll gates g_EnemyDesired (= g_StabbedFlag).
    Block 2 — CAL_BOARD + mutual-enemy table (press_on or FAL/WIN).
    Block 3 — FUN_004113d0 (UpdateAllyRelations, role TBD — skipped).
    Block 4 — first-turn press-on initialisation (trust from proximity, random ally).
    Block 5 — enemy-desired trust management (betrayal counter, peace overtures).
    Block 6 — UpdateRelationHistory when press off or near-end (deferred to friendly).
    """
    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)
    phase      = state.g_season
    press_on   = (state.g_PressFlag == 1)

    # g_EnemyDesired ≡ g_StabbedFlag (same address DAT_00baed5f)
    enemy_desired = state.g_StabbedFlag

    # ── Block 1: enemy activation check ──────────────────────────────────────
    # Gate: g_EnemyDesired == 0 AND press_off
    # Threshold = (g_DeceitLevel + 3) * 15  → ~60 % year-1, ~75 % year-2
    if enemy_desired == 0 and not press_on:
        threshold = (state.g_DeceitLevel + 3) * 15
        if random.randrange(100) < threshold:
            state.g_StabbedFlag = 1
            enemy_desired = 1
            logger.debug(
                "HOSTILITY: enemy now desired (DeceitLevel=%d, threshold=%d)",
                state.g_DeceitLevel, threshold,
            )

    # ── Block 2: CAL_BOARD + mutual-enemy table ───────────────────────────────
    if press_on or phase in ('FAL', 'WIN'):
        cal_board(state, own_power)

        # For each power find best mutual enemy: minimise sum of rank scores
        # vs. the power and its best ally.  Filter: own rank to candidate < 4,
        # or candidate is the committed enemy already (g_EnemyDesired + committed).
        ally_slot0 = state.g_BestAllySlot0
        rank_mtx   = state.g_InfluenceRankFlag   # DAT_006340c0

        for a in range(num_powers):
            ally_a = ally_slot0 if a == own_power else -1
            best_c, best_score = -1, 10_000
            for c in range(num_powers):
                if c == a or c == ally_a or int(state.sc_count[c]) <= 0:
                    continue
                r_ac    = int(rank_mtx[a, c])        if rank_mtx[a, c] >= 0 else 9_999
                r_allc  = (int(rank_mtx[ally_a, c])  if 0 <= ally_a < num_powers
                           and rank_mtx[ally_a, c] >= 0 else 9_999)
                combined = r_ac + r_allc
                our_rank = int(rank_mtx[own_power, c]) if rank_mtx[own_power, c] >= 0 else 9_999
                is_committed = (enemy_desired and c == state.g_CommittedEnemy
                                and state.g_EnemyFlag[c])
                if our_rank >= 4 and not is_committed:
                    continue
                if combined < best_score:
                    best_score, best_c = combined, c
            state.g_MutualEnemyTable[a] = best_c

        if 0 <= ally_slot0 < num_powers and state.g_MutualEnemyTable[ally_slot0] >= 0:
            logger.debug(
                "HOSTILITY: good mutual enemy with best ally %d → power %d",
                ally_slot0, state.g_MutualEnemyTable[ally_slot0],
            )

    # ── Block 4: first-turn press-on initialisation ───────────────────────────
    if press_on and state.g_HistoryCounter == 0:
        state.g_AllyPressCount.fill(0)
        state.g_AllyPressHi.fill(0)

        # Assign initial trust from g_InfluenceMatrix_B proximity values.
        # ≤ 17.0 → nearby power (trust 5); > 17.0 → distant (trust 3).
        inf_b = state.g_InfluenceMatrix_B
        for p in range(num_powers):
            if p == own_power:
                continue
            state.g_AllyTrustScore[own_power, p] = (
                5.0 if float(inf_b[own_power, p]) <= 17.0 else 3.0
            )

        # Random ally selection from proximity rank table (stride 5 per power).
        prox = state.g_PowerProximityRank
        if prox is not None:
            base = own_power * 5
            roll = random.randrange(100)
            if roll < 25:
                state.g_BestAllySlot0 = int(prox[base])
            elif roll < 50:
                state.g_BestAllySlot0 = int(prox[base + 1])
            elif roll < 75:
                state.g_BestAllySlot0 = int(prox[base + 2])
                state.g_TripleFrontMode2 = 1
            else:
                state.g_TripleFrontFlag  = 1
                state.g_BestAllySlot0    = int(prox[base])
                state.g_BestAllySlot1    = int(prox[base + 1])
                state.g_BestAllySlot2    = int(prox[base + 2])
            # Self-invalidate any slot equal to own power
            for attr in ('g_BestAllySlot0', 'g_BestAllySlot1', 'g_BestAllySlot2'):
                if getattr(state, attr) == own_power:
                    setattr(state, attr, -1)

    # ── Near-end-game overrides ───────────────────────────────────────────────
    if state.g_NearEndGameFactor > 5.0:
        state.g_StabbedFlag = 1
    if state.g_NearEndGameFactor > 3.0:
        cal_board(state, own_power)

    # ── Block 5: enemy-desired trust management ───────────────────────────────
    if state.g_StabbedFlag == 1:
        inf_b = state.g_InfluenceMatrix_B

        for p in range(num_powers):
            if p == own_power or state.g_EnemyFlag[p]:
                continue

            trust_op = float(state.g_AllyTrustScore[own_power, p])
            trust_po = float(state.g_AllyTrustScore[p, own_power])

            if trust_op == 0 and trust_po == 0:
                state.g_BetrayalCounter[p] += 1

            if state.g_BetrayalCounter[p] >= 10 and phase == 'SPR':
                state.g_BetrayalCounter[p] = 0

            proximity = float(inf_b[own_power, p])
            relation  = int(state.g_RelationScore[own_power, p])
            if proximity > 14 or relation < 0:
                state.g_BetrayalCounter[p] = 0

            # They consider us ally but we're hostile → change our minds
            if trust_po > 0 and trust_op == 0 and proximity > 0.0 and relation >= 0:
                state.g_AllyTrustScore[own_power, p] = trust_po
                logger.debug("HOSTILITY: changed our minds about attacking power %d", p)

            # Active peace overture: neutral power with SCs, spring, no cease-fire
            if (trust_op == 0 and int(state.sc_count[p]) > 2
                    and phase == 'SPR'
                    and state.g_CeaseFire[own_power, p] == 0):
                state.g_AllyTrustScore[own_power, p] = 1.0
                state.g_AllyTrustScore[p, own_power] = 1.0
                logger.debug("HOSTILITY: attempting peace with power %d", p)


def _post_friendly_update(state: InnerGameState) -> None:
    """ComputeInfluenceMatrix (FUN_0040d8c0). Trust-adjusts g_InfluenceMatrix,
    adds noise, row-normalises to 100, builds g_AllyPrefRanking.
    research.md §4241."""
    own_power = getattr(state, 'albert_power_idx', 0)
    compute_influence_matrix(state, own_power)


def _cleanup_turn(state: InnerGameState) -> None:
    """NormalizeInfluenceMatrix. Trust-adjusts g_InfluenceMatrix_Raw by
    (g_AllyTrustScore + 1), injects _safe_pow noise, and row-normalises to 100.

    Was mislabelled 'Per-turn cleanup'; corrected per _index.md.
    Writes g_InfluenceMatrix (consumed by compute_influence_matrix ranking).

    Decompile: decompiled.txt lines 460-593.
    Phases match GenerateOrders Phase 4-5 but operate on Raw/trust-adjusted copy.
    """
    n = 7  # numPowers

    # Phase 1 — trust-adjust: g_InfluenceMatrix[row,col] = Raw[row,col] / (trust+1)
    # C: DAT_00b82db8 = g_InfluenceMatrix_Raw / CONCAT44(trust_hi+carry, trust_lo+1)
    for row in range(n):
        for col in range(n):
            raw   = float(state.g_InfluenceMatrix_Raw[row, col])
            trust = float(state.g_AllyTrustScore[row, col])
            state.g_InfluenceMatrix[row, col] = raw / (trust + 1.0)

    # Phase 2 — per-power row sum via PackScoreU64 (trunc toward zero, not banker's round;
    # FRNDINT+correction always restores truncation)
    # C: DAT_004f6b98[power*2] = PackScoreU64() after FPU row-sum accumulation
    power_sum = np.array(
        [int(float(np.sum(state.g_InfluenceMatrix[p]))) for p in range(n)],
        dtype=np.int64,
    )

    # Phase 3 — per-cell noise: cell += _safe_pow(cell / (col_sum+1), 0.3) * 500
    # C: fVar8 = _safe_pow(); *pdVar6 = fVar8 * 500.0 + *pdVar6
    # base exponent 0.3 = DAT_004af9f8 (33 33 33 33 33 33 d3 3f)
    for row in range(n):
        for col in range(n):
            col_total = float(power_sum[col])
            base = float(state.g_InfluenceMatrix[row, col]) / (col_total + 1.0)
            state.g_InfluenceMatrix[row, col] += _safe_pow(base, 0.3) * 500.0

    # Phase 4 — row-normalise to 100
    # C: cell = (cell * 100.0) / row_sum  (skipped when row_sum == 0)
    for row in range(n):
        row_sum = float(np.sum(state.g_InfluenceMatrix[row]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[row] = (state.g_InfluenceMatrix[row] * 100.0) / row_sum


def _init_position_for_orders(state: InnerGameState) -> None:
    """InitPositionForOrders. Sets up per-turn position state required 
    before Monte Carlo order evaluation. Writes g_ScOwner, resets 
    g_AllyMatrix, and zeros g_MoveHistoryMatrix."""
    num_powers = 7
    num_provinces = 256
    
    # Step 1 — Clear per-power order candidate lists
    state.g_CandidateRecordList.clear()
    
    # Step 2 — Initialize g_ScOwner to "unknown" (-1 = unoccupied, -2 = contested)
    state.g_ScOwner = getattr(state, 'g_ScOwner', np.full(num_provinces, -1, dtype=np.int32))
    state.g_ScOwner.fill(-1)
    
    # Step 4 — Populate g_ScOwner from unit list
    for prov, unit in state.unit_info.items():
        power = unit.get('power', -1)
        if power < 0:
            continue
        if state.g_ScOwner[prov] == -1:
            state.g_ScOwner[prov] = power
        elif state.g_ScOwner[prov] != power:
            state.g_ScOwner[prov] = -2  # contested (-2)
            
    # Step 5 — Zero g_AllyMatrix per power (to be rebuilt by FRIENDLY)
    state.g_AllyMatrix.fill(0)
    
    # Step 6 — Convoy reach and history
    if not hasattr(state, 'g_MoveHistoryMatrix'):
        state.g_MoveHistoryMatrix = np.zeros((num_powers, num_provinces, num_provinces), dtype=np.int32)
    else:
        state.g_MoveHistoryMatrix.fill(0)
        
    state.g_VictoryThreshold = len(state.unit_info) // 2 + 1


def _build_movement_order_token(state: 'InnerGameState', prov: int) -> 'str | None':
    """
    Port of FUN_00463690 — build DAIDE token string for one movement-phase order.

    C: undefined4 * __thiscall FUN_00463690(void *this, undefined4 *param_1, int *param_2)
      this    = inner gamestate (unit list at this+0x2450)
      param_1 = output token list
      param_2 = order record starting at unit+0x10 in the unit struct:
        [0]  source province ID
        [1]  source coast token
        [2]  power index
        [3]  unit type (0=AMY, 1=FLT)
        [4]  order type: 0/1=HLD, 2=MTO, 3=SUP_HLD, 4=SUP_MTO, 5=CVY, 6=CTO
               (unit+0x20 != 0 guard in caller = this field non-zero)
        [5]  dest province (MTO, CTO)
        [6]  dest coast token (MTO, CTO; high byte 0x46 = coast category)
        [7]  target unit province (SUP_HLD, SUP_MTO, CVY)
        [8]  secondary dest province (SUP_MTO dest; CVY army dest)
        [10] CTO via-list head pointer (linked list of convoy fleet provinces)

    Token DAT constants (DAIDE 0x43 order-type category):
        DAT_004c7678 = CTO (0x4300)
        DAT_004c767c = CVY (0x4301)
        DAT_004c7680 = HLD (0x4302)
        DAT_004c7684 = MTO (0x4303)
        DAT_004c7688 = SUP (0x4304)
        DAT_004c768c = VIA (0x4305)

    Python mapping of param_2 fields → g_OrderTable columns:
        param_2[4]   order type  → _F_ORDER_TYPE  (1-indexed; 0/1→HLD=1, 2→MTO=2, …)
        param_2[7]   target prov → _F_SECONDARY   (SUP target or CVY army)
        param_2[5,8] dest prov   → _F_DEST_PROV   (MTO/CTO dest; SUP_MTO/CVY dest)
        param_2[6]   dest coast  → _F_DEST_COAST
        param_2[10]  via list    → _F_CONVOY_LEG0/_LEG1/_LEG2 (up to 3 fleet provinces)

    Absorbed helpers:
        FUN_0045ffa0 → inline: build ( POWER AMY|FLT PROVINCE [COAST] ) unit token
        FUN_0045fca0 → inline: build PROVINCE or ( PROVINCE COAST ) dest token
        FUN_00466480/FUN_00466330/AppendList → string concat (no Python equivalent needed)
        FUN_00465870 → token-list alloc (no Python equivalent needed)
        FUN_00466c40 → wrap sub-list in parens (absorbed as f"( {via_str} )")
        UnitList_FindOrInsert → state.unit_info.get(target_prov)
    """
    order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
    if order_type == 0:
        return None

    unit_data = state.unit_info.get(prov)
    if unit_data is None:
        return None

    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    # FUN_0045ffa0: build unit identifier ( POWER AMY|FLT PROVINCE [COAST] )
    # param_2[0..3] = {province, coast, power, unit_type}
    power_idx  = unit_data.get('power', 0)
    power_name = _DAIDE_POWER_NAMES[power_idx] if 0 <= power_idx < len(_DAIDE_POWER_NAMES) else 'UNO'
    unit_chr   = 'AMY' if unit_data.get('type', 'AMY') == 'AMY' else 'FLT'
    prov_name  = id_to_prov.get(prov, str(prov))
    unit_coast = unit_data.get('coast', '')
    if unit_coast:
        unit_tok = f"( {power_name} {unit_chr} {prov_name} {unit_coast} )"
    else:
        unit_tok = f"( {power_name} {unit_chr} {prov_name} )"

    # FUN_0045fca0: build dest token — PROVINCE or ( PROVINCE COAST )
    # param_2[5] = dest province, param_2[6] = dest coast (high byte 0x46 = coast category)
    dest_id       = int(state.g_OrderTable[prov, _F_DEST_PROV])
    dest_name     = id_to_prov.get(dest_id, str(dest_id))
    dest_coast_tok = int(state.g_OrderTable[prov, _F_DEST_COAST])
    dest_coast_str = _DAIDE_COAST_TO_STR.get(dest_coast_tok, '')
    if dest_coast_str:
        dest_tok = f"( {dest_name} {dest_coast_str} )"
    else:
        dest_tok = dest_name

    def _target_unit_tok(target_prov: int) -> 'str | None':
        """FUN_0045ffa0 applied to target unit at target_prov."""
        td = state.unit_info.get(target_prov)
        if td is None:
            return None
        tp = td.get('power', 0)
        tn = _DAIDE_POWER_NAMES[tp] if 0 <= tp < len(_DAIDE_POWER_NAMES) else 'UNO'
        tc = 'AMY' if td.get('type', 'AMY') == 'AMY' else 'FLT'
        tp_name = id_to_prov.get(target_prov, str(target_prov))
        tcoast  = td.get('coast', '')
        if tcoast:
            return f"( {tn} {tc} {tp_name} {tcoast} )"
        return f"( {tn} {tc} {tp_name} )"

    if order_type == _ORDER_HLD:
        # case 0/1: DAT_004c7680 = HLD
        # FUN_0045ffa0 → unit_tok; FUN_00466480(unit_tok, HLD); AppendList
        return f"{unit_tok} HLD"

    elif order_type == _ORDER_MTO:
        # case 2: FUN_0045fca0 → dest_tok; FUN_0045ffa0 → unit_tok
        #         FUN_00466480(unit_tok, MTO=DAT_004c7684); FUN_00466330(+dest_tok); AppendList
        return f"{unit_tok} MTO {dest_tok}"

    elif order_type == _ORDER_SUP_HLD:
        # case 3: UnitList_FindOrInsert(param_2+7) → target unit
        #         FUN_0045ffa0(target) → target_tok
        #         FUN_0045ffa0(self)   → unit_tok
        #         FUN_00466480(unit_tok, SUP=DAT_004c7688); FUN_00466330(+target_tok); AppendList
        target_prov = int(state.g_OrderTable[prov, _F_SECONDARY])
        target_tok  = _target_unit_tok(target_prov)
        if target_tok is None:
            return None
        return f"{unit_tok} SUP {target_tok}"

    elif order_type == _ORDER_SUP_MTO:
        # case 4: UnitList_FindOrInsert(param_2+7) → target; dest = this+param_2[8]*0x24
        #         FUN_0045ffa0(target) → target_tok
        #         FUN_0045ffa0(self)   → unit_tok
        #         FUN_00466480(unit_tok, SUP); concat(+target_tok)
        #         FUN_00466480(+MTO=DAT_004c7684); FUN_00466480(+dest_province); AppendList
        # param_2[7] = _F_SECONDARY (supported unit); param_2[8] = _F_DEST_PROV (its destination)
        target_prov = int(state.g_OrderTable[prov, _F_SECONDARY])
        target_tok  = _target_unit_tok(target_prov)
        if target_tok is None:
            return None
        return f"{unit_tok} SUP {target_tok} MTO {dest_name}"

    elif order_type == _ORDER_CVY:
        # case 5: UnitList_FindOrInsert(param_2+7) → army unit at army_prov
        #         FUN_0045ffa0(army)  → army_tok
        #         FUN_0045ffa0(fleet) → unit_tok
        #         FUN_00466480(unit_tok, CVY=DAT_004c767c); concat(+army_tok)
        #         FUN_00466480(+CTO=DAT_004c7678); FUN_00466480(+dest_province); AppendList
        # param_2[7] = army prov (_F_SECONDARY); param_2[8] = army dest (_F_DEST_PROV)
        army_prov = int(state.g_OrderTable[prov, _F_SECONDARY])
        army_tok  = _target_unit_tok(army_prov)
        if army_tok is None:
            return None
        return f"{unit_tok} CVY {army_tok} CTO {dest_name}"

    elif order_type == _ORDER_CTO:
        # case 6: FUN_0045fca0 → dest_tok (with coast); FUN_0045ffa0 → army unit_tok
        #         FUN_00466480(unit_tok, CTO=DAT_004c7678); concat(+dest_tok); AppendList main order
        #         iterate param_2[10] via-list (linked list), each node[2]=fleet_prov:
        #           FUN_00466480(local_1ec, fleet_prov_token); AppendList(local_1ec)
        #         FUN_00466480(param_1, VIA=DAT_004c768c)
        #         FUN_00466c40(+local_1ec wrapped in parens); AppendList
        # param_2[10] via list → _F_CONVOY_LEG0/_LEG1/_LEG2 (non-zero fleet province IDs)
        via_provs = []
        for leg_col in (_F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2):
            leg_prov = int(state.g_OrderTable[prov, leg_col])
            if leg_prov:
                via_provs.append(id_to_prov.get(leg_prov, str(leg_prov)))
        if via_provs:
            # FUN_00466c40 wraps the via-province list in parens (DAT_004c768c = VIA)
            via_tok = "( " + " ".join(via_provs) + " )"
            return f"{unit_tok} CTO {dest_tok} VIA {via_tok}"
        return f"{unit_tok} CTO {dest_tok}"

    return None


def _build_retreat_order_token(state: 'InnerGameState', node: dict) -> 'str | None':
    """
    Port of FUN_00460110 — build DAIDE token string for one retreat-phase order node.

    C param_2 layout (int *):
        [0..3] = unit data (province, type, power, ...)  → consumed by FUN_0045ffa0
        [4]    = order type: 0 or 8 → DSB, 7 → RTO, other → skip (return param_1 unchanged)
        [5]    = destination province ID (RTO only)      → FUN_0045fca0
        [6]    = coast low-byte; CONCAT22(0x46, [6]) → coast token (RTO only)

    Key constants:
        DAT_004c7690 = DSB (0x4340)   — appended by FUN_00466480 for DSB path
        DAT_004c7694 = RTO (0x4341)   — appended by FUN_00466480 for RTO path

    Returns DAIDE order string (without outer parens) for appending to GOF seq,
    or None to skip this node entirely.

    Inline helpers absorbed into string operations (no standalone Python port needed):
        FUN_0045ffa0  — build unit token seq  ('POWER AMY|FLT PROVINCE [COAST]')
        FUN_0045fca0  — build province+coast dest seq  ('PROVINCE [COAST]')
        FUN_00466480  — append single token to seq     (→ string concat)
        FUN_00466330  — concat two token seqs          (→ string concat)
        FUN_00465870  — init empty token list          (→ not needed in Python)
    """
    order_type = node.get('order_type', -1)

    # FUN_0045ffa0: build unit token seq → 'POWER AMY|FLT PROVINCE [COAST]'
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    power_idx = node.get('power', 0)
    power_name = _DAIDE_POWER_NAMES[power_idx] if 0 <= power_idx < len(_DAIDE_POWER_NAMES) else 'UNO'
    unit_chr = 'AMY' if node.get('unit_type', 'AMY') == 'AMY' else 'FLT'
    prov_name = state._id_to_prov.get(node.get('province', 0), str(node.get('province', 0)))
    unit_coast = node.get('unit_coast', '')
    # FUN_00465aa0 wraps the unit seq in parens at the end of FUN_0045ffa0,
    # so the unit portion must be ( POWER UNIT PROVINCE [COAST] ).
    unit_str = f"( {power_name} {unit_chr} {prov_name}"
    if unit_coast:
        unit_str += f" {unit_coast}"
    unit_str += " )"

    if order_type == 7:  # RTO
        # FUN_0045fca0: build destination seq ('PROVINCE [COAST]')
        dest_id = node.get('dest_province', 0)
        dest_name = state._id_to_prov.get(dest_id, str(dest_id))
        # C: param_3._1_1_ == 'F' checks high byte == 0x46 (coast category).
        # dest_coast stores the full DAIDE coast token (0 = no coast, 0x46xx = coast).
        coast_tok = node.get('dest_coast', 0)
        coast_str = _DAIDE_COAST_TO_STR.get(coast_tok, '')
        # FUN_00466540 builds [province_tok, coast_tok]; FUN_00465aa0 then wraps in ( ).
        # DAIDE prov_coast grammar: ( province coast ) — parens required for coasted dest.
        if coast_str:
            dest_str = f"( {dest_name} {coast_str} )"
        else:
            dest_str = dest_name
        # FUN_00466480(unit_seq, buf, &DAT_004c7694=RTO) + FUN_00466330(unit+RTO, buf, dest)
        return f"{unit_str} RTO {dest_str}"

    elif order_type in (0, 8):  # DSB
        # FUN_00466480(unit_seq, buf, &DAT_004c7690=DSB)
        return f"{unit_str} DSB"

    # All other order types: C returns param_1 unchanged (no entry appended)
    return None


def _build_gof_seq(state: 'InnerGameState') -> list:
    """
    Port of FUN_00464460 — builds the DAIDE GOF+orders token sequence
    from the inner gamestate.

    C structure:
      1. Init output list (param_1) and working list (local_b8).
      2. Prepend DAT_004c77a0 = GOF (0x4803) to output.
      3. Phase-dependent order iteration:
           SPR/SUM  (0x4700/4701): iterate active unit list (this+0x2450/2454);
                    for each own unit (unit.power==own_power) with an order
                    (unit+0x20 != 0): FUN_00463690 builds the movement-order
                    token seq; FUN_00466c40 wraps it in parens and appends to output.
           FAL/AUT  (0x4702/4703): same pattern over retreat list (this+0x245c/2460);
                    FUN_00460110 builds the retreat-order token seq.
           WIN: iterate build list (this+0x2474/2478);
                    for each candidate append power_token + BLD(0x4380)/REM(0x4381)
                    + province + coast (DAT_004c7698 or DAT_004c769c per this+0x2488);
                    then for each waived build (count at this+0x2480) append WVE(0x4382).
      4. Each per-order entry is wrapped: ( order_tokens ) via FUN_00466c40.

    TokenSeq_Count in the caller counts list nodes; > 1 means at least one
    order entry is present (header alone = 1).

    FUN_00463690 not yet decompiled.
    SPR/SUM orders are read from state.g_OrderList (populated by _build_and_send_sub).
    FAL/AUT orders are read from state.g_retreat_order_list (populated before _send_gof).
    """
    phase = getattr(state, 'g_season', 'SPR')
    orders: list = list(getattr(state, 'g_OrderList', []))

    # DAT_004c77a0 = GOF (0x4803) — always the first token
    seq: list = ['GOF']

    if phase in ('SPR', 'SUM'):
        # FUN_00463690: for each own unit (unit.power==own_power) with an order
        # (unit+0x20 != 0 ↔ g_OrderTable[prov, _F_ORDER_TYPE] != 0):
        # build DAIDE movement-order token seq; FUN_00466c40 wraps in parens.
        own_power = getattr(state, 'albert_power_idx', 0)
        for prov, unit_data in state.unit_info.items():
            if unit_data.get('power') != own_power:
                continue
            tok = _build_movement_order_token(state, prov)
            if tok is not None:
                seq.append(f'( {tok} )')        # FUN_00466c40 wraps in parens
    elif phase in ('FAL', 'AUT'):
        # FUN_00460110: retreat order token builder over retreat list (this+0x245c/2460).
        # g_OrderList is NOT used here — that is the press-candidate list.
        for node in state.g_retreat_order_list:
            tok = _build_retreat_order_token(state, node)
            if tok is not None:
                seq.append(f'( {tok} )')          # FUN_00466c40 wraps in parens
    else:
        # WIN: BLD/REM per candidate (build list this+0x2474/2478) +
        #      WVE per waiver (count at this+0x2480).
        # DAT_004c7670=BLD(0x4380), DAT_004c7674=REM(0x4381), DAT_004c76a0=WVE(0x4382).
        # Coast selection per build candidate: this+0x2488 == 0 → DAT_004c769c,
        # else → DAT_004c7698 (two fleet-build coast tokens, values TBC).
        for order in orders:
            seq.append(f'( {order} )')
        waive_count: int = int(getattr(state, 'g_waive_count', 0))
        for _ in range(waive_count):
            # FUN_00466540(own_power_token, ..., &DAT_004c76a0) → ( power WVE )
            seq.append(f'( WVE )')              # DAT_004c76a0 = WVE(0x4382)

    return seq


def _send_gof(state: 'InnerGameState', send_dm) -> None:
    """
    Port of FUN_0045aa40 = send_GOF.

    Builds the GOF (Go Order Final) DAIDE token sequence from the inner
    gamestate (FUN_00464460 = _build_gof_seq) and transmits it via SendDM
    only when the sequence contains more than one token (non-empty guard).

    C flow:
      local_2c  = FUN_00465870()          // init temp list
      ppvVar1   = FUN_00464460(gamestate, local_1c)  // build GOF seq
      AppendList(local_2c, ppvVar1)
      FreeList(local_1c)
      if TokenSeq_Count(local_2c) > 1:
          puVar3 = FUN_00464460(gamestate, local_1c)  // rebuild for send
          SendDM(this, puVar3)
          FreeList(local_1c)
      FreeList(local_2c)
    """
    gof_seq = _build_gof_seq(state)          # FUN_00464460
    if len(gof_seq) > 1:                     # TokenSeq_Count(local_2c) > 1
        gof_seq = _build_gof_seq(state)      # FUN_00464460 — rebuild for send
        send_dm(gof_seq)                     # SendDM


# ── Order-sequence builder ───────────────────────────────────────────────────

def _build_order_seq_from_table(state: InnerGameState, prov: int) -> dict | None:
    """
    Builds a dispatch_single_order-compatible order dict from g_OrderTable[prov].
    Returns None if the province has no active order or no unit present.

    Mirrors the DispatchSingleOrder (FUN_0044cc50) input construction step —
    reading g_OrderTable fields and converting province IDs to name strings via
    the state.prov_to_id reverse map.
    """
    order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
    if order_type == 0:
        return None

    unit_data = state.unit_info.get(prov)
    if unit_data is None:
        return None

    # Build reverse province-id → name map on demand
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    unit_chr = 'A' if unit_data['type'] == 'AMY' else 'F'
    prov_name = id_to_prov.get(prov, str(prov))
    coast = unit_data.get('coast', '')
    loc_str = f"{prov_name}/{coast}" if coast else prov_name
    unit_str = f"{unit_chr} {loc_str}"

    dest_id   = int(state.g_OrderTable[prov, _F_DEST_PROV])
    dest_name = id_to_prov.get(dest_id, str(dest_id))
    sec_id    = int(state.g_OrderTable[prov, _F_SECONDARY])
    sec_name  = id_to_prov.get(sec_id, str(sec_id))
    dest_coast_tok = int(state.g_OrderTable[prov, _F_DEST_COAST])
    dest_coast = _DAIDE_COAST_TO_STR.get(dest_coast_tok, '')

    _ORDER_TYPE_MAP = {
        _ORDER_HLD:     'HLD',
        _ORDER_MTO:     'MTO',
        _ORDER_SUP_HLD: 'SUP',
        _ORDER_SUP_MTO: 'SUP',
        _ORDER_CVY:     'CVY',
        _ORDER_CTO:     'CTO',
    }

    seq: dict = {
        'type': _ORDER_TYPE_MAP.get(order_type, 'HLD'),
        'unit': unit_str,
    }

    if order_type == _ORDER_MTO:
        seq['target'] = dest_name
        seq['coast']  = dest_coast

    elif order_type == _ORDER_CTO:
        sec_data = state.unit_info.get(sec_id)
        if sec_data:
            sec_chr = 'A' if sec_data['type'] == 'AMY' else 'F'
            seq['target_unit'] = f"{sec_chr} {sec_name}"
        seq['target_dest'] = dest_name

    elif order_type == _ORDER_SUP_MTO:
        sec_data = state.unit_info.get(sec_id)
        if sec_data:
            sec_chr = 'A' if sec_data['type'] == 'AMY' else 'F'
            seq['target_unit'] = f"{sec_chr} {sec_name}"
        seq['target_dest']  = dest_name
        seq['target_coast'] = dest_coast

    elif order_type == _ORDER_SUP_HLD:
        sec_data = state.unit_info.get(sec_id)
        if sec_data:
            sec_chr = 'A' if sec_data['type'] == 'AMY' else 'F'
            seq['target_unit'] = f"{sec_chr} {sec_name}"

    elif order_type == _ORDER_CVY:
        seq['target_dest'] = dest_name

    return seq


# ── Main bot class ───────────────────────────────────────────────────────────

class AlbertClient:
    def __init__(self, power_name: str, host: str, port: int):
        self.power_name = power_name
        self.host = host
        self.port = port
        self.state = InnerGameState()
        self.connection = None
        self.game = None
        self.current_phase = None

    async def play(self):
        """
        Main event loop connecting to the diplomacy server.
        """
        self.connection = await connect(self.host, self.port)
        channel = await self.connection.authenticate(
            username=f'Albert_{self.power_name}',
            password='password'
        )

        logger.info(f"Albert successfully authenticated as {self.power_name}")

        games = await channel.list_games()
        if not games:
            logger.warning("No active games found on the server.")
            return

        target_game_id = games[0]['game_id']
        logger.info(f"Joining game: {target_game_id}")

        self.game = await channel.join_game(target_game_id, power_name=self.power_name)

        while True:
            await asyncio.sleep(2)
            game_state = self.game.get_state()  # noqa: F841 — consumed by on_game_update
            phase = self.game.get_phase()

            if self.current_phase != phase:
                self.current_phase = phase
                logger.info(f"New phase: {phase}")
                self.on_game_update(self.game)

    # ── NOW-handler entry point ──────────────────────────────────────────────

    def on_game_update(self, game_object):
        """
        Triggered when NOW or SCO received (or state polled).
        Mirrors the NOW handler → vtable+0xe8 → GenerateAndSubmitOrders call chain.
        """
        self.state.synchronize_from_game(game_object)

        if game_object.get_phase() != 'COMPLETED':
            self.generate_and_submit_orders()

    # ── GenerateAndSubmitOrders ──────────────────────────────────────────────

    def generate_and_submit_orders(self) -> None:
        """
        Port of FUN_004592a0 = GenerateAndSubmitOrders.

        Called from on_game_update after board state is synchronized.
        Mirrors the full C++ execution flow documented in research.md
        §GenerateAndSubmitOrders — FUN_004592a0 ⭐.

        Execution flow (matching research.md §Execution flow):
          Step 1  Record turn-start timestamp.
          Step 2  Reset per-turn scalar flags.
          Step 3  Cancel stale orders if reconnecting.
          Step 4  Press-flag refresh.
          Step 5  Main AI block (skipped when game_over):
            5a  Reset press candidate tables.
            5b  PhaseHandler(0).
            5c  Per-power reset loop (trust counters, score matrices).
            5d  Phase checks: increment g_DeceitLevel (SPR), AnalyzePosition,
                MOVE_ANALYSIS (year-1 FAL, press-off, allied).
            5e  Clear g_baed6d sentinel.
            5f  GenerateOrders + MC selection (process_turn).
            5g  PostProcessOrders (SPR/FAL).
            5h  ComputePress (if press active).
            5i  Alliance block (STABBED / DEVIATE_MOVE / FRIENDLY / HOSTILITY /
                PhaseHandler 1–3).
            5j  BuildAndSendSUB (movement phases) + draw vote;
                or HOSTILITY + PhaseHandler(3) (retreat/adjustment).
          Step 6  CleanupTurn + GOF.
        """
        own_power_idx = (
            _POWER_NAMES.index(self.power_name)
            if self.power_name in _POWER_NAMES else 0
        )
        self.state.albert_power_idx = own_power_idx

        # Step 1 — record turn start timestamp (DAT_00ba2880 = __time64(0))
        self.state.g_turn_start_time = time.time()

        # Step 2 — reset per-turn scalar flags
        # Mirrors: DAT_0062cc64 / ba2858 / ba285c / baed46 / baed5e / baed47 = 0
        if not hasattr(self.state, 'g_pending_orders_A'):
            self.state.g_pending_orders_A = 0
        if not hasattr(self.state, 'g_pending_orders_B'):
            self.state.g_pending_orders_B = 0

        game_over: bool = getattr(self.state, 'g_game_over', False)

        # Step 3 — cancel stale pending orders if reconnecting
        # Condition: !game_over AND (pending_A != 0 OR pending_B != 0)
        if not game_over and (
            self.state.g_pending_orders_A != 0
            or self.state.g_pending_orders_B != 0
        ):
            logger.info("Stale pending orders found — cancelling (reconnect path)")
            self.state.g_pending_orders_A = 0
            self.state.g_pending_orders_B = 0

        # Step 4 — press flag refresh
        # Clear press flag, then re-arm from one-shot config flag (DAT_004c6bdc).
        # DAT_00baed68: 0 = press off, 1 = run ComputePress this turn.
        if self.state.g_PressFlag == 1:
            self.state.g_PressFlag = 0
        one_shot_press = getattr(self.state, 'g_one_shot_press', 0)
        if one_shot_press == 1:
            self.state.g_PressFlag = 1
            self.state.g_one_shot_press = 0

        if game_over:
            logger.info("Game-over flag set — skipping order generation")
            _cleanup_turn(self.state)
            _send_gof(self.state, self._send_dm)
            return

        # ── Step 5 — main AI block ──────────────────────────────────────────
        phase: str = self.state.g_season          # 'SPR'|'SUM'|'FAL'|'AUT'|'WIN'
        movement_phase: bool = phase in ('SPR', 'FAL')
        num_powers = 7

        # 5a — reset press candidate tables
        # DAT_00bbf690[power][30] and DAT_00bc0a40[power][30] — cleared to sentinel
        self.state.g_PressCandidateA = [[None] * 30 for _ in range(num_powers)]
        self.state.g_PressCandidateB = [[None] * 30 for _ in range(num_powers)]

        # 5b — PhaseHandler step 0
        _phase_handler(self.state, 0)

        # 5c — per-power reset loop
        # DAT_00ba2888[power] = signed trust/relationship counter:
        #   own/ally powers: converges +1 toward 0 each movement turn (started negative)
        #   non-ally powers: reset to 0
        if not hasattr(self.state, 'g_trust_counter'):
            self.state.g_trust_counter = np.zeros(num_powers, dtype=np.int32)

        for p in range(num_powers):
            ally_p = int(self.state.g_AllyMatrix[own_power_idx, p]) != 0
            is_self = (p == own_power_idx)
            for j in range(num_powers):
                if is_self or ally_p:
                    if self.state.g_trust_counter[j] < 0 and movement_phase:
                        self.state.g_trust_counter[j] += 1
                else:
                    self.state.g_trust_counter[j] = 0

        # 5d — phase-specific pre-processing

        # g_DeceitLevel (DAT_00baed64) = Spring-year counter; 0=pre-game, 1=year 1, …
        # Incremented each SPR. Also labelled "Deceit Level" in Albert's internal log.
        if phase == 'SPR':
            self.state.g_DeceitLevel += 1
            logger.debug(
                f"DeceitLevel = {self.state.g_DeceitLevel} "
                f"(Spring of year {self.state.g_DeceitLevel})"
            )

        if movement_phase:
            _analyze_position(self.state)

        # MOVE_ANALYSIS gate: year-1, press-off, Fall, allied own power
        ally_own: bool = int(self.state.g_AllyMatrix[own_power_idx, own_power_idx]) != 0
        if (
            self.state.g_DeceitLevel == 1
            and self.state.g_PressFlag == 0
            and phase == 'FAL'
            and ally_own
        ):
            _move_analysis(self.state)

        # 5e — DAT_00baed6d = 0  (deviation/retry sentinel cleared before GenerateOrders)
        self.state.g_baed6d = 0

        # 5f — GenerateOrders (FUN_004466e0) + MC trial loop → best order set
        # process_turn wraps GenerateOrders and the MC selection (BuildAndSendSUB inner loop)
        best_orders = process_turn(self.state, num_trials=1000)

        # 5g — PostProcessOrders (SPR/FAL only; runs after GenerateOrders, before SUB)
        if movement_phase:
            _post_process_orders(self.state)

        # 5h — ComputePress if press mode is active this turn
        if self.state.g_PressFlag == 1:
            _compute_press(self.state)

        # 5i — alliance-active block
        # Gate: ally[own_power] != 0 AND DAT_00baed33 == 0 (alliance debug flag off)
        alliance_debug: bool = getattr(self.state, 'g_alliance_debug', False)
        if ally_own and not alliance_debug:
            logger.debug("Alliance block active")

            # Year-1 non-SPR non-retreat: STABBED check.
            # Year >= 2 or retreat phase: DEVIATE_MOVE.
            if self.state.g_DeceitLevel < 2 and phase not in ('AUT', 'WIN'):
                if self.state.g_DeceitLevel == 1 and phase != 'SPR':
                    _stabbed(self.state)
            else:
                _deviate_move(self.state)

            _phase_handler(self.state, 1)
            _friendly(self.state)
            _phase_handler(self.state, 2)
            _post_friendly_update(self.state)

        # 5j — submit orders and draw vote (movement) OR retreat handling
        if movement_phase:
            _hostility(self.state)
            _phase_handler(self.state, 3)
            self._build_and_send_sub(best_orders)

            # Draw vote: DAT_00baed29/2a/2b/30 — any set → DRW; else → NOT DRW (sent every turn)
            # g_draw_sent (DAT_00baed5d) records the decision.
            draw_vote = compute_draw_vote(self.state, best_orders, self.power_name)
            extra_draw_flags = getattr(self.state, 'g_draw_flags', [])
            if draw_vote or any(extra_draw_flags):
                logger.info("Draw vote: proposing DRW")
                self.state.g_draw_sent = 1
            else:
                logger.info("Draw vote: sending NOT DRW")
                self.state.g_draw_sent = 0
        else:
            # Retreat / adjustment phase — no SUB, but HOSTILITY runs in WIN
            if phase == 'WIN':
                _hostility(self.state)
            _phase_handler(self.state, 3)

        # Step 6 — CleanupTurn + GOF
        _cleanup_turn(self.state)
        _send_gof(self.state, self._send_dm)

    # ── DM wire helper ───────────────────────────────────────────────────────

    def _send_dm(self, msg: object) -> None:
        """
        Send DAIDE direct-message using python-diplomacy NetworkGame API.
        """
        logger.debug("SendDM: %r", msg)
        if self.game is not None:
            try:
                from diplomacy import Message
                recipient = getattr(msg, 'recipient', 'ALL')
                self.game.add_message(Message(sender=self.power_name, recipient=recipient, message=str(msg)))
            except ImportError:
                logger.warning("diplomacy.Message not available; cannot send DAIDE press.")

    # ── BuildAndSendSUB helper ───────────────────────────────────────────────

    def _build_and_send_sub(self, best_orders: list) -> None:
        """
        Port of BuildAndSendSUB (FUN_00457890).

        Orchestrates the outer proposal-generation and order-submission loop:

          1. DispatchScheduledPress  — flush any queued timed press messages.
          2. Time-limit guard        — abort if MTL has already fired.
          3. UpdateScoreState        — refresh stale ally order tables.
          4. Build + submit orders   — BuildPowerOrderSeq → DispatchSingleOrder
                                       → AssembleAndSendSUB → game.set_orders.
          5. Press deal matching     — when g_HistoryCounter > 19, iterate
                                       g_DealList and send ally press for deals
                                       whose province set overlaps current orders
                                       and where trust ≥ 3.
          6. CancelPriorPress        — withdraw any stale prior-press token.

        Research.md §4633 / §BuildAndSendSUB.
        """
        own_power_idx = getattr(self.state, 'albert_power_idx', 0)

        # ── 1. DispatchScheduledPress (PrepareOrderGenState / FUN_004424e0) ──
        dispatch_scheduled_press(self.state, self._send_dm)

        # ── 2. Time-limit guard ──────────────────────────────────────────────
        if check_time_limit(self.state):
            logger.warning("MTL expired before BuildAndSendSUB — skipping SUB")
            return

        if not best_orders:
            logger.warning("MC selection produced no orders — nothing submitted")
            return

        # ── 3. UpdateScoreState — refresh stale ally order tables ────────────
        update_score_state(self.state)

        # ── 4. Build + submit orders ─────────────────────────────────────────
        best = best_orders[0]
        order_pairs = best.get('orders', [])   # [(prov, order_type), ...]

        self.state.g_OrderList = []
        for prov, _order_type in order_pairs:
            seq = _build_order_seq_from_table(self.state, prov)
            if seq is not None:
                dispatch_single_order(
                    self.state, own_power_idx, seq
                )

        formatted = list(self.state.g_OrderList)
        logger.info(f"SUB — {len(formatted)} orders for {self.power_name}: {formatted}")

        if self.game is not None:
            self.game.set_orders(self.power_name, formatted)

        # ── 5. Press deal matching (g_HistoryCounter > 19) ───────────────────
        # Mirrors the g_DealList iteration in BuildAndSendSUB §4661:
        # for each received deal where trust ≥ 3 and province set overlaps
        # current submitted orders → send ally press confirmation.
        if self.state.g_HistoryCounter > 19:
            submitted_provs = {prov for prov, _ in order_pairs}
            for deal in list(self.state.g_DealList):
                other = deal.get('power', -1)
                if other < 0:
                    continue
                trust = int(self.state.g_AllyTrustScore[own_power_idx, other])
                if trust < 3:
                    continue
                deal_provs = deal.get('province_set', set())
                if deal_provs & submitted_provs:
                    self._send_dm(f"PRP ( PCE ( {own_power_idx} {other} ) )")
                    logger.debug(
                        "Deal match: sent ally press to power %d (trust=%d)",
                        other, trust,
                    )

        # ── 6. CancelPriorPress — withdraw stale press token ─────────────────
        cancel_prior_press(self.state, own_power_idx, self._send_dm)

    # ── Press handler ────────────────────────────────────────────────────────

    def on_message_received(self, sender: str, msg: str) -> None:
        """Triggered when a press message (FRM) arrives."""
        parse_message(self.state, sender, msg)
