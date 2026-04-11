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
    _send_ally_press_by_power,
)
from .heuristics import (
    cal_board,
    compute_draw_vote,
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

    Decompile-verified structure (decompiled.txt):
      1. Per-(a,b) reach table: reach[a][adj]=1 for adj-of-a-units not occupied by b;
         upgrade to 2 where b-unit is adjacent; b5e8[a][b] = b-units adj to reach≥2 zones;
         bcd0[a][b] = b's MTO/CTO moving into a-reachable (reach 2→3), SUP_MTO similarly.
      2. Pre-ratio trust reset: non-own-power pairs with trust < 3 → force to 1.
      3. Ratio trust updates for all (a,b) pairs.
      4. Pre-compaction restore: if no current trust<2, restore first original low-trust ally.
      5. Slot invalidation (trust < 2 → drop), compact, best-ally check, sticky-enemy detect.
    """
    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)

    trust = state.g_AllyTrustScore  # (7,7) float64; updated in-place

    # Save own_power's trust row before any modifications (for pre-compaction restore)
    orig_own_trust = trust[own_power, :].copy()

    bcd0 = np.zeros((num_powers, num_powers), dtype=np.int32)  # b's aggressive moves toward a
    af00 = np.zeros((num_powers, num_powers), dtype=np.int32)  # allied (a) units near contested dest
    b5e8 = np.zeros((num_powers, num_powers), dtype=np.int32)  # b-units pressuring a

    # Build province→power map and per-power province lists
    prov_power = np.full(256, -1, dtype=np.int32)
    power_provs: list[list[int]] = [[] for _ in range(num_powers)]
    for prov, unit in state.unit_info.items():
        p = unit.get('power', -1)
        if 0 <= p < num_powers:
            prov_power[prov] = p
            power_provs[p].append(prov)

    # --- Phases 1 & 2: per-(a,b) reach table ---------------------------------
    # For each attacking power a and defending power b:
    #   reach[adj]=1  ← adj province of an a-unit, not occupied by b
    #   reach[adj]=2  ← upgrade if also adjacent to a b-unit
    #   b5e8[a][b]    ← count b-units that have at least one reach≥2 adjacent province
    #   bcd0[a][b]    ← b's MTO/CTO moves into reach-2 zones (upgrade to 3); SUP_MTO similarly
    reach = np.zeros(256, dtype=np.int32)  # per-(a,b) scratch table

    for a in range(num_powers):
        for b in range(num_powers):
            if a == b:
                continue

            reach[:] = 0

            # Pass 1: mark adj-of-a-units that are NOT b-occupied as reach=1
            for prov in power_provs[a]:
                for adj in state.adj_matrix.get(prov, []):
                    if prov_power[adj] != b and reach[adj] == 0:
                        reach[adj] = 1

            # Pass 2: for each b-unit, upgrade reach-1 adjacent provinces to reach-2
            for b_prov in power_provs[b]:
                for adj in state.adj_matrix.get(b_prov, []):
                    if reach[adj] == 1:
                        reach[adj] = 2

            # Pass 3: count b5e8 and apply order effects for bcd0/af00
            for b_prov in power_provs[b]:
                # b5e8: b-unit counts if ANY adjacent province has reach≥2
                for adj in state.adj_matrix.get(b_prov, []):
                    if reach[adj] >= 2:
                        b5e8[a, b] += 1
                        break

                # Order effects (C types 2=MTO, 6=CTO, 4=SUP_MTO)
                order_type = int(state.g_OrderTable[b_prov, _F_ORDER_TYPE])
                dest       = int(state.g_OrderTable[b_prov, _F_DEST_PROV])

                if order_type in (_ORDER_MTO, _ORDER_CTO):      # C types 2 and 6
                    if 0 <= dest < 256:
                        if reach[dest] == 2:
                            # b moves into a-reachable contested province → aggressive
                            bcd0[a, b] += 1
                            reach[dest] = 3
                            for adj2 in state.adj_matrix.get(dest, []):
                                if prov_power[adj2] == a:
                                    af00[a, b] += 1
                        elif reach[dest] == 3:
                            # b was moving to already-upgraded province → un-count
                            bcd0[a, b] -= 1
                            reach[dest] = 2
                elif order_type == _ORDER_SUP_MTO:              # C type 4
                    # Only count if b is NOT supporting an a-unit
                    secondary = int(state.g_OrderTable[b_prov, _F_SECONDARY])
                    if (0 <= dest < 256
                            and not (0 <= secondary < 256 and prov_power[secondary] == a)
                            and reach[dest] >= 2):
                        bcd0[a, b] += 1

    # --- Pre-ratio trust reset -----------------------------------------------
    # Other powers' inter-trust: if not strongly allied (trust<3) → set to 1 (suspicious)
    for a in range(num_powers):
        if a == own_power:
            continue
        for b in range(num_powers):
            if a != b and trust[a, b] < 3:
                trust[a, b] = 1

    # --- Phase 3 — ratio-based trust updates (all (a,b) pairs) ---------------
    # ratio_ab = bcd0[a][b] / b5e8[a][b]: fraction of b's pressure that is aggressive toward a
    # High ratio_ab → b is hostile to a → trust[a][b] decreases
    for a in range(num_powers):
        for b in range(num_powers):
            if a == b:
                continue
            ratio_ab = float(bcd0[a, b]) / b5e8[a, b] if b5e8[a, b] > 0 else -1.0
            ratio_ba = float(bcd0[b, a]) / b5e8[b, a] if b5e8[b, a] > 0 else -1.0

            if ratio_ab < 0:
                continue  # no pressure from b toward a; skip

            if ratio_ab == 0.0:
                # b not aggressive → increment trust; if mutually non-aggressive: allies
                trust[a, b] += 1
                if ratio_ba == 0.0:
                    trust[a, b] = 5  # override: mutual non-aggression
                    logger.debug(
                        "Seems (%d) and (%d) have applied no pressure to each other", a, b)
            elif (ratio_ab == 1.0 and b5e8[a, b] == 1
                  and af00[a, b] == 0 and af00[b, a] == 0
                  and trust[a, b] > 1):
                trust[a, b] = 2  # single-unit bounce; may still ally
                logger.debug(
                    "Seems (%d) and (%d) have bounced and still may have a viable alliance",
                    a, b)
            elif ratio_ab >= 0.55:
                if trust[a, b] < 5:
                    trust[a, b] = 1  # high aggression → hostile
            else:  # 0 < ratio_ab < 0.55
                trust[a, b] += 1
                if ratio_ba == 0.0:
                    trust[a, b] += 1
                    logger.debug(
                        "Seems (%d) and (%d) have applied little pressure to each other", a, b)

    # --- Pre-compaction: restore original hostility if trust inflated --------
    # If no power currently has trust<2 but originally some did, restore the first such ally.
    # (C: cStack_bd79 / LAB_00435fe6 guard; prevents false trust upgrades.)
    has_low_trust_now = any(
        trust[own_power, p] < 2 for p in range(num_powers) if p != own_power
    )
    if not has_low_trust_now:
        for p in range(num_powers):
            if p != own_power and orig_own_trust[p] < 2:
                trust[own_power, p] = orig_own_trust[p]
                break

    # --- Phase 4 — opening ally selection ------------------------------------
    # Invalidate ally slots where trust dropped below 2 (distrusted)
    for attr in ('g_BestAllySlot0', 'g_BestAllySlot1', 'g_BestAllySlot2'):
        slot = getattr(state, attr, -1)
        if 0 <= slot < num_powers and trust[own_power, slot] < 2:
            setattr(state, attr, -1)

    # Compact: shift valid slots to front (left-pack)
    slots = [getattr(state, f'g_BestAllySlot{i}', -1) for i in range(3)]
    valid = [s for s in slots if s >= 0]
    while len(valid) < 3:
        valid.append(-1)
    state.g_BestAllySlot0, state.g_BestAllySlot1, state.g_BestAllySlot2 = (
        valid[0], valid[1], valid[2])

    # Best ally (after compaction) fully pressured by one power → g_AllyUnderAttack
    best_ally = getattr(state, 'g_BestAllySlot0', -1)
    if 0 <= best_ally < num_powers:
        for c in range(num_powers):
            if (c != best_ally
                    and bcd0[best_ally, c] > 1
                    and bcd0[best_ally, c] == b5e8[best_ally, c]):
                state.g_AllyUnderAttack = 1
                logger.debug(
                    "Best ally (%d) severely pressured by power (%d)", best_ally, c)
                break

    # Detect single hostile (trust==1) power → sticky enemy mode
    hostile = [p for p in range(num_powers) if trust[own_power, p] == 1]
    if len(hostile) == 1:
        p = hostile[0]
        state.g_OpeningStickyMode = 1
        state.g_OpeningEnemy      = p
        trust[own_power, p]       = 0
        state.g_StabbedFlag       = 1   # DAT_00baed5f = g_EnemyDesired
        logger.debug("Enemy set to single original enemy: power %d", p)
        return  # goto LAB_00436427 (skip triple-front check)

    # Triple-front mode: demote trust-3 entries to trust-1 for own_power
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


def _stab_enemy_slot_remove(slots, target):
    """Remove target from the 3-slot g_EnemySlot queue.

    Slot[0] removal left-shifts remaining entries (C lines 418-426 / 430-436).
    Slot[1] or slot[2] removal just clears that slot (C lines 437-455).
    """
    if slots[0] == target:
        slots[0] = slots[1] if slots[1] != -1 else -1
        if slots[1] != -1:
            slots[1] = slots[2] if slots[2] != -1 else -1
            slots[2] = -1
    elif slots[1] == target:
        slots[1] = -1
    elif slots[2] == target:
        slots[2] = -1


def _stab_clear_ally_list(state, attr, power_idx):
    """Clear g_AllyPromiseList[power_idx] or g_AllyCounterList[power_idx].

    Supports dict-of-sets (preferred), list-of-sets, and legacy np.ndarray.
    """
    lst = getattr(state, attr, None)
    if lst is None:
        return
    if isinstance(lst, dict):
        lst[power_idx] = set()
    elif isinstance(lst, list) and 0 <= power_idx < len(lst):
        lst[power_idx] = set() if isinstance(lst[power_idx], set) else 0
    elif hasattr(lst, '__setitem__'):
        try:
            lst[power_idx] = 0
        except (IndexError, ValueError):
            pass


def _stabbed(state: InnerGameState) -> None:
    """STABBED (FUN_0042c730). Stab detection for the move-order phase (Year-1).

    Double loop (outer=row=victim, inner=col=stabber). For each pair:

    Phase 0 — zero-init pass (identical to DEVIATE_MOVE):
      g_StabFlag, g_NeutralFlag, g_CeaseFire, g_PeaceSignal always;
      g_SomeCoopScore (DAT_0062c580) if SPR;
      g_CoopFlag (DAT_0062be98) if FAL.

    Phase 1 — unit-list proposed-order check (Albert+0x2450/54):
      For each unit of power col (not row): check if the unit's province has a
      per-province alliance record (Albert+prov*0x24) whose ally field == row.
      Python proxy: g_AllyDesignation_A/B[prov] == row.
      Sets stab_flag for this (row,col) pair.

    Phase 2 — submitted-order stab check (Albert+0x248c/90):
      For each submitted order by col (not row):
        MTO/CTO (type 2/6): dest must appear in g_AllyCounterList[col] (when
          col attacked row=own_power) or g_AllyPromiseList[row] (when col=own
          attacked row).
        SUP-MTO (type 4): same check using support-target province.
      If destination not found in expected list → stab_flag set.

    On stab (stab_flag==True):
      g_StabFlag[row, col] = 1.
      If row==own_power (victim): log + set g_StabbedFlag + clear stabber's
        ally lists + update g_EnemySlot (removal) + g_OpeningStickyMode.
      If col==own_power (stabber): clear victim's ally lists.
      Always: bilateral g_SomeCoopScore or g_CoopFlag; bilateral trust reset.
    """
    own_power = int(getattr(state, 'albert_power_idx', 0))
    num_powers = 7
    season = state.g_season

    # ── Phase 0: Init pass ────────────────────────────────────────────────────
    # Arrays: int[pow*21+other], stride 0x54=21*4 per row, 4 per col.
    # In Python they are (7,7); fill(0) is equivalent.
    state.g_StabFlag.fill(0)
    state.g_NeutralFlag.fill(0)
    state.g_CeaseFire.fill(0)
    state.g_PeaceSignal.fill(0)
    # DAT_0062c580 = g_SomeCoopScore, cleared when season == SPR
    if season == 'SPR':
        state.g_SomeCoopScore.fill(0)
    # DAT_0062be98 = g_CoopFlag, cleared when season == FAL
    elif season == 'FAL':
        state.g_CoopFlag.fill(0)

    # ── Phase 1: unit-list province-designation check (Albert+0x2450/54) ─────
    # C: for each unit node (iVar15) where unit.power==col and col!=row:
    #   byte  at Albert+3+prov*0x24        → nonzero = has ally designation
    #   ushort at Albert+0x20+prov*0x24    → hi='A', lo=designated ally power
    #   if hi!='A': lo = 0x14 (invalid)
    #   if lo == row: uStack_92 |= 1
    # Python proxy: g_AllyDesignation_A[prov]==row or g_AllyDesignation_B[prov]==row.
    stab_unit = np.zeros((num_powers, num_powers), dtype=bool)
    for prov, unit in state.unit_info.items():
        col = int(unit['power'])
        prov_id = int(prov) if not isinstance(prov, int) else prov
        if prov_id >= 256:
            continue
        desig_a = int(state.g_AllyDesignation_A[prov_id])
        desig_b = int(state.g_AllyDesignation_B[prov_id])
        for row in range(num_powers):
            if row == col:
                continue
            if desig_a == row or desig_b == row:
                stab_unit[row, col] = True

    # ── Phase 2: submitted-order stab check (Albert+0x248c/90) ───────────────
    # g_AllyCounterList[col]: set of expected dest provinces for col's moves
    #   (checked when col != own, row == own; C: DAT_00bb7028/2c per power)
    # g_AllyPromiseList[row]: set of expected dest provinces for own's moves
    #   into row's territory (C: DAT_00bb6f28/2c per power)
    # Submitted orders in g_SubmittedOrderList lack order_type; treated as MTO.
    ally_counter = getattr(state, 'g_AllyCounterList', None)
    ally_promise = getattr(state, 'g_AllyPromiseList', None)

    def _in_list(lst, power, dest):
        if lst is None:
            return False
        if isinstance(lst, dict):
            return dest in lst.get(power, set())
        if isinstance(lst, (list, np.ndarray)):
            try:
                entry = lst[power]
                if isinstance(entry, set):
                    return dest in entry
            except (IndexError, KeyError):
                pass
        return False

    stab_order = np.zeros((num_powers, num_powers), dtype=bool)
    for order in getattr(state, 'g_SubmittedOrderList', []):
        col = int(order.get('power', -1))
        if not (0 <= col < num_powers):
            continue
        dest = int(order.get('dst_prov', -1))
        if dest < 0:
            continue
        # Treat all submitted orders as MTO-type (order_type not in Python state).
        # Case A: attacker (col) hits own_power (row==own_power)
        if col != own_power:
            row = own_power
            if not _in_list(ally_counter, col, dest):
                stab_order[row, col] = True
        # Case B: own_power (col) moves into other power's (row) territory
        elif col == own_power:
            for row in range(num_powers):
                if row == col:
                    continue
                if not _in_list(ally_promise, row, dest):
                    stab_order[row, col] = True

    # ── Phase 3: apply stab consequences ─────────────────────────────────────
    slots = list(map(int, state.g_EnemySlot))
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            if not (stab_unit[row, col] or stab_order[row, col]):
                continue

            state.g_StabFlag[row, col] = 1

            # Victim == own_power (C lines 270-367)
            if row == own_power:
                logger.info("We have been stabbed by (%d) during the turn", col)
                state.g_StabbedFlag = 1
                logger.info("Enemy desired because of stab")
                _stab_clear_ally_list(state, 'g_AllyPromiseList', col)
                _stab_clear_ally_list(state, 'g_AllyCounterList', col)

            # Stabber == own_power (C lines 368-398)
            if col == own_power:
                _stab_clear_ally_list(state, 'g_AllyPromiseList', row)
                _stab_clear_ally_list(state, 'g_AllyCounterList', row)

            # Season-dependent bilateral CoopScore flags (C lines 399-413)
            if season in ('SUM', 'FAL'):
                state.g_SomeCoopScore[row, col] = 1
                state.g_SomeCoopScore[col, row] = 1
            else:  # AUT, WIN, SPR
                state.g_CoopFlag[row, col] = 1
                state.g_CoopFlag[col, row] = 1

            # Bilateral trust reset (C lines 409-413)
            state.g_AllyTrustScore[row, col] = 0
            state.g_AllyTrustScore_Hi[row, col] = 0
            state.g_AllyTrustScore[col, row] = 0
            state.g_AllyTrustScore_Hi[col, row] = 0

            # g_EnemySlot removal — victim==own: remove stabber;
            # stabber==own: remove victim (C lines 414-455).
            # Slot[0] removal left-shifts; slot[1]/[2] just cleared.
            if row == own_power:
                _stab_enemy_slot_remove(slots, col)
                # g_OpeningStickyMode (C lines 415-417)
                if state.g_OpeningStickyMode == 1 and col != state.g_OpeningEnemy:
                    state.g_OpeningStickyMode = 0
            if col == own_power:
                _stab_enemy_slot_remove(slots, row)

    state.g_EnemySlot = np.array(slots[:3], dtype=np.int32)


def _deviate_move(state: InnerGameState) -> None:
    """DEVIATE_MOVE (FUN_0043a000). Stab detection + consequence engine.
    Year >= 2 or retreat phase.

    Structure (outer loop = all 7 powers as victim perspective):
      Phase 0 – zero init pass (6 arrays, numPowers×numPowers)
      Phase 1 – retreat-list peace signal (stub: g_RetreatList not yet in state)
      Phase 2 – order-history retreat stab detection (g_OrderHistList type-7 records)
      Phase 3 – movement-order deviation stab (stub: requires g_RetreatList)
      On stab detected → _apply_deviate_stab consequences
    """
    own_power = getattr(state, 'albert_power_idx', 0)
    num_powers = 7
    season = state.g_season

    # Phase 0: Init pass — identical stride/layout in both STABBED and DEVIATE_MOVE
    state.g_StabFlag.fill(0)
    state.g_NeutralFlag.fill(0)
    state.g_CeaseFire.fill(0)
    state.g_PeaceSignal.fill(0)
    if season == 'SPR':
        state.g_CoopScoreFlag_A.fill(0)
    elif season == 'FAL':
        state.g_CoopScoreFlag_B.fill(0)

    # Phase 1: retreat-list peace signal (C: Albert+0x248c/0x2490 = g_RetreatList)
    # For each retreating unit: scan adjacency; if source province owned by p AND
    # dest owned by p → g_PeaceSignal[p*21+other]=1.
    # TODO: implement when g_RetreatList is added to InnerGameState.

    # Phase 2: order-history retreat stab detection (C: Albert+0x2498/0x249c = g_OrderHistList)
    # Outer loop uStack_1c0 = victim power p (0..numPowers-1).
    # Gate: trust[attacker + p*21] > 0.  Order type 7 = retreat order.
    # Checks expected_dest against ally designation; determines stab vs neutral.
    order_hist = getattr(state, 'g_OrderHistList', [])
    for p in range(num_powers):
        for rec in order_hist:
            attacker = int(rec.get('power', -1))
            if not (0 <= attacker < num_powers) or attacker == p:
                continue

            # Gate: trust[attacker + p*21] > 0  (C: g_AllyTrustScore_Hi check)
            if int(state.g_AllyTrustScore[attacker, p]) <= 0:
                continue

            order_type = int(rec.get('order_type', -1))
            if order_type != 7:
                continue  # phase 2 only handles retreat orders (type 7)

            expected_dest = int(rec.get('expected_dest', rec.get('dst_prov', -1)))
            if expected_dest < 0:
                continue

            # Check expected_dest against ally designation tables
            # C: DAT_004cf610/DAT_004cfe10 (two per-province designation arrays).
            # Python approximation via g_AllyDesignation_A/B indexed by province.
            desig_a = int(state.g_AllyDesignation_A[expected_dest]) if expected_dest < 256 else -1
            desig_b = int(state.g_AllyDesignation_B[expected_dest]) if expected_dest < 256 else -1
            if desig_a != p and desig_b != p:
                continue  # dest not in p's designated ally territory

            # Reverse-trust check determines stab vs neutral (C: lines 260-274)
            trust_pa = int(state.g_AllyTrustScore[p, attacker])
            if trust_pa <= 0:
                # Both directions ≤ 0 → neutral attack
                state.g_NeutralFlag[attacker, p] = 1
                if p == own_power:
                    logger.info("We have been attacked by (%d) during the retreat phase", attacker)
            else:
                # At least one direction > 0 → stab (LAB_0043bad4)
                _apply_deviate_stab(state, attacker, p, own_power, num_powers, season,
                                    retreat_phase=True)

    # Phase 3: movement-order deviation stab (C: LAB_0043aacd / LAB_0043b0b2)
    # For each unit in g_RetreatList: compare actual order type/dest against expected
    # ally designation. If deviation and 4.0 <= g_NearEndGameFactor → skip.
    # trust[p][attacker] < 0 AND trust[attacker][p] < 0 → g_NeutralFlag
    # else → _apply_deviate_stab
    # TODO: implement when g_RetreatList is added to InnerGameState.


def _apply_deviate_stab(state, attacker, p, own_power, num_powers, season,
                        retreat_phase=False):
    """Apply stab consequences from DEVIATE_MOVE (LAB_0043bad4 / LAB_0043b0b2).

    Sets g_StabFlag[attacker,p], bilateral CoopScoreFlag (season-dependent),
    bilateral trust reset, and — when p==own_power — clears AllyMatrix rows,
    manages g_EnemySlot (removal-based, C lines 1263-1321), g_OpeningStickyMode.
    """
    state.g_StabFlag[attacker, p] = 1

    # Bilateral CoopScoreFlag update (C lines 306-325):
    #   SUM or FAL → g_CoopScoreFlag_A[attacker+p*21] and [attacker*21+p]
    #   AUT, WIN, SPR → g_CoopScoreFlag_B (same indices)
    if season in ('SUM', 'FAL'):
        state.g_CoopScoreFlag_A[attacker, p] = 1
        state.g_CoopScoreFlag_A[p, attacker] = 1
    else:
        state.g_CoopScoreFlag_B[attacker, p] = 1
        state.g_CoopScoreFlag_B[p, attacker] = 1

    # Bilateral trust reset (C lines 358-366)
    state.g_AllyTrustScore[attacker, p] = 0
    state.g_AllyTrustScore[p, attacker] = 0

    if p == own_power:
        if retreat_phase:
            logger.info("We have been stabbed by (%d) during the retreat phase", attacker)
        else:
            logger.info("We have been stabbed by (%d) during the turn", attacker)

        # Clear g_AllyMatrix[attacker row] (C lines 1219-1222)
        for j in range(num_powers):
            state.g_AllyMatrix[attacker, j] = 0

        # g_EnemySlot: REMOVAL-based management (C lines 1263-1321).
        # When attacker == slot[k]: remove attacker, shift remaining slots left.
        # This is distinct from STABBED's push-front insertion.
        slots = list(getattr(state, 'g_EnemySlot', np.array([-1, -1, -1])))
        if attacker in slots:
            idx = slots.index(attacker)
            slots.pop(idx)
            slots.append(-1)
        state.g_EnemySlot = slots[:3]

        # g_OpeningStickyMode (C lines 1254-1261)
        if getattr(state, 'g_OpeningStickyMode', 0) == 1:
            if getattr(state, 'g_OpeningEnemy', -1) != attacker:
                state.g_OpeningStickyMode = 0

    elif attacker == own_power:
        # We (own_power) stabbed victim p: clear own AllyMatrix row (C lines 1243-1249)
        for j in range(num_powers):
            state.g_AllyMatrix[own_power, j] = 0


def _friendly(state: InnerGameState) -> None:
    """FRIENDLY (FUN_0042dc40). Per-turn power×power relationship and alliance
    state update. research.md §4364."""
    friendly(state)


def _hostility(state: InnerGameState) -> None:
    """HOSTILITY (FUN_~0x42F200).

    Highest-level per-turn diplomatic strategy function.  research.md §6649.

    Block 1 — enemy activation: random roll gates g_EnemyDesired (= g_StabbedFlag).
    Block 2 — CAL_BOARD + mutual-enemy table (press_on or FAL/WIN).
    Block 3 — FUN_004113d0 (ComputeOrderDipFlags) — always; not yet ported, skipped.
    Block 4 — press-on initialisation (SPR/FAL): trust from proximity, random ally.
    Block 5 — enemy-desired trust management (SPR/FAL): betrayal counter, peace overtures.
    Block 6 — UpdateRelationHistory when press off or near-end (embedded in friendly()).
    """
    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)
    phase      = state.g_season
    press_on   = (state.g_PressFlag == 1)

    # g_EnemyDesired ≡ g_StabbedFlag (same address DAT_00baed5f)
    enemy_desired = state.g_StabbedFlag

    # ── Block 1: enemy activation check ──────────────────────────────────────
    # C: outer gate = g_EnemyDesired==0; inner gate = press_off (DAT_00baed68==0).
    # Threshold = (g_DeceitLevel + 3) * 15  → ~60 % year-1, ~75 % year-2.
    # C fires multiple rand calls but only the final value is used.
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
    # C gate: press_on OR FAL OR WIN.
    if press_on or phase in ('FAL', 'WIN'):
        cal_board(state, own_power)

        # For each power a, find best mutual enemy c that minimises
        # rank[own_power,c] + rank[a,c].
        # Mandatory inner filter: rank[a,c] < 4.
        # Outer filter: rank[own_power,c] < 4  OR  c is the committed enemy.
        # C: a == own_power is excluded by the condition (uVar7 != local_70);
        #    g_MutualEnemyTable[own_power] stays -1.
        rank_mtx  = state.g_InfluenceRankFlag   # DAT_006340c0
        ally_slot0 = state.g_BestAllySlot0

        for a in range(num_powers):
            state.g_MutualEnemyTable[a] = -1
            if a == own_power:
                continue
            best_c, best_score = -1, 10_000
            for c in range(num_powers):
                if c == a or c == own_power:
                    continue
                if int(state.sc_count[c]) <= 0:
                    continue
                r_ac = int(rank_mtx[a, c])
                if r_ac >= 4:
                    continue  # mandatory inner filter
                r_own_c = int(rank_mtx[own_power, c])
                is_committed = (
                    enemy_desired and c == state.g_CommittedEnemy
                    and int(state.g_EnemyFlag[c]) != 0
                )
                if r_own_c >= 4 and not is_committed:
                    continue
                score = r_own_c + r_ac
                if score < best_score:
                    best_score, best_c = score, c
            state.g_MutualEnemyTable[a] = best_c

        if 0 <= ally_slot0 < num_powers and state.g_MutualEnemyTable[ally_slot0] >= 0:
            logger.debug(
                "HOSTILITY: good mutual enemy with best ally %d → power %d",
                ally_slot0, state.g_MutualEnemyTable[ally_slot0],
            )

    # ── Block 3: ComputeOrderDipFlags (FUN_004113d0) — always ────────────────
    # TODO: port ComputeOrderDipFlags; sets flag1/flag2/flag3 on each g_OrderList node.

    # ── SPR||FAL outer gate (wraps Blocks 4 and 5) ───────────────────────────
    if phase in ('SPR', 'FAL'):

        # ── Block 4: press-on per-turn initialisation ─────────────────────────
        # C: runs every SPR/FAL with press_on (not gated by g_HistoryCounter==0).
        if press_on:
            # Zero per-power press counters.
            state.g_AllyPressCount.fill(0)
            state.g_AllyPressHi.fill(0)

            # Trust init from g_InfluenceMatrix_B for ALL power pairs (not just own).
            # ≤ 17.0 → nearby (trust 5); > 17.0 → distant (trust 3).
            # C outer loop: uVar7 = 0..num_powers-1; inner: uVar12 = 0..num_powers-1.
            inf_b = state.g_InfluenceMatrix_B
            prox  = state.g_PowerProximityRank
            for a in range(num_powers):
                for p in range(num_powers):
                    if p == a:
                        continue
                    state.g_AllyTrustScore_Hi[a, p] = 0
                    state.g_AllyTrustScore[a, p] = (
                        5 if float(inf_b[a, p]) <= 17.0 else 3
                    )

                # Random ally selection for this power; only own_power updates slots.
                # C: puVar17[-1]=prox[base], puVar17[0]=prox[base+1], puVar17[1]=prox[base+2]
                # Trust is set for the PRIMARY target; slots hold the OTHER neighbors.
                if prox is not None:
                    base = a * 5
                    roll = random.randrange(100)
                    if roll < 25:
                        # Primary trust target = prox[base]; slots = [base+1, base+2]
                        ally_idx = int(prox[base])
                        state.g_AllyTrustScore[a, ally_idx] = 1
                        state.g_AllyTrustScore_Hi[a, ally_idx] = 0
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base + 1])
                            state.g_BestAllySlot1 = int(prox[base + 2])
                    elif roll < 50:
                        # Primary trust target = prox[base+1]; slots = [base, base+2]
                        ally_idx = int(prox[base + 1])
                        state.g_AllyTrustScore[a, ally_idx] = 1
                        state.g_AllyTrustScore_Hi[a, ally_idx] = 0
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base])
                            state.g_BestAllySlot1 = int(prox[base + 2])
                    elif roll < 75:
                        # Primary trust target = prox[base+2]; slots = [base, base+1]
                        ally_idx = int(prox[base + 2])
                        state.g_AllyTrustScore[a, ally_idx] = 1
                        state.g_AllyTrustScore_Hi[a, ally_idx] = 0
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base])
                            state.g_BestAllySlot1 = int(prox[base + 1])
                            state.g_TripleFrontMode2 = 1
                    else:
                        # Triple-front: no single primary; all three slots assigned.
                        state.g_TripleFrontFlag = 1
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base])
                            state.g_BestAllySlot1 = int(prox[base + 1])
                            state.g_BestAllySlot2 = int(prox[base + 2])
                            for attr in ('g_BestAllySlot0', 'g_BestAllySlot1', 'g_BestAllySlot2'):
                                if getattr(state, attr) == own_power:
                                    setattr(state, attr, -1)

            # g_HistoryCounter > 0 path: snapshot own-power trust row and send press.
            # C: saves g_AllyTrustScore[own_power, p] to DAT_004d5480/4, clears low trust,
            #    then calls SendAllyPressByPower(p) for each p.
            # Deferred: press dispatch requires send_fn; handled by caller after _hostility.

            # ── Near-end-game overrides (inside press_on + SPR/FAL block) ─────
            if state.g_NearEndGameFactor > 5.0:
                state.g_StabbedFlag = 1
                enemy_desired = 1
            if state.g_NearEndGameFactor > 3.0:
                cal_board(state, own_power)

        # ── Block 5: enemy-desired trust management ───────────────────────────
        # C: gated by g_StabbedFlag (g_EnemyDesired) inside SPR||FAL.
        if state.g_StabbedFlag == 1:
            inf_b = state.g_InfluenceMatrix_B

            # Betrayal-counter loop.
            # C: piVar18 iterates g_RelationScore[own_power, p] (row own, advancing by col).
            #    piVar8 iterates g_AllyTrustScore[own_power, p] (same row).
            for p in range(num_powers):
                if p == own_power or int(state.g_EnemyFlag[p]) != 0:
                    continue
                trust_op_lo = int(state.g_AllyTrustScore[own_power, p])
                trust_op_hi = int(state.g_AllyTrustScore_Hi[own_power, p])
                # C: both g_EnemyFlag[p] words must be 0 (already filtered above).
                if trust_op_lo == 0 and trust_op_hi == 0:
                    state.g_BetrayalCounter[p] += 1

                proximity = float(inf_b[own_power, p])
                relation  = int(state.g_RelationScore[own_power, p])
                if proximity > 14 or relation < 0:
                    state.g_BetrayalCounter[p] = 0

                if int(state.g_BetrayalCounter[p]) >= 10 and phase == 'SPR':
                    state.g_BetrayalCounter[p] = 0

            # SendAllyPressByPower for all powers when history > 0 (inside enemy block).
            # C: lines 618-622; deferred to caller (send_fn not available here).

            # "Changed our minds" loop.
            # C: piVar8 iterates g_AllyTrustScore[p, own_power] (column own_power);
            #    advances by full row (stride 21*2=42 ints) per iteration.
            for p in range(num_powers):
                if p == own_power:
                    continue
                trust_po_lo = int(state.g_AllyTrustScore[p, own_power])
                trust_po_hi = int(state.g_AllyTrustScore_Hi[p, own_power])
                # C: trust[p,own] > 0 = trust_hi >= 0 AND (trust_hi > 0 OR trust_lo != 0)
                if not (trust_po_hi >= 0 and (trust_po_hi > 0 or trust_po_lo != 0)):
                    continue
                trust_op_lo = int(state.g_AllyTrustScore[own_power, p])
                trust_op_hi = int(state.g_AllyTrustScore_Hi[own_power, p])
                proximity   = float(inf_b[own_power, p])
                relation    = int(state.g_RelationScore[own_power, p])
                if (trust_op_lo == 0 and trust_op_hi == 0
                        and int(state.g_EnemyFlag[p]) == 0
                        and proximity > 0.0 and relation >= 0):
                    state.g_AllyTrustScore[own_power, p]    = trust_po_lo
                    state.g_AllyTrustScore_Hi[own_power, p] = trust_po_hi
                    logger.debug("HOSTILITY: changed our minds about attacking power %d", p)

            # Peace overture loop.
            # C: g_HistoryCounter==0 path goes directly to LAB_0042f95f; history>0 path
            #    checks PCE in press history first (stubbed: always proceed).
            for p in range(num_powers):
                if p == own_power or int(state.g_EnemyFlag[p]) != 0:
                    continue
                sc = int(state.sc_count[p])
                if sc <= 0:
                    continue
                # sc > 2 OR phase == SPR
                if sc <= 2 and phase != 'SPR':
                    continue
                # phase == SPR OR g_NeutralFlag[own, p] == 0
                # C: DAT_0062b7b0 = g_NeutralFlag (not g_CeaseFire)
                if phase != 'SPR' and int(state.g_NeutralFlag[own_power, p]) != 0:
                    continue
                trust_op_lo = int(state.g_AllyTrustScore[own_power, p])
                trust_op_hi = int(state.g_AllyTrustScore_Hi[own_power, p])
                if trust_op_lo != 0 or trust_op_hi != 0:
                    continue
                # Both relation scores must be non-negative.
                # C: (&DAT_00634e90)[iVar9] = g_RelationScore[own,p]; *piStack_68 = g_RelationScore[p,own]
                if int(state.g_RelationScore[own_power, p]) < 0:
                    continue
                if int(state.g_RelationScore[p, own_power]) < 0:
                    continue
                # Random 15% gate OR betrayal counter < 2 (lo-word).
                betrayal_lo = int(state.g_BetrayalCounter[p]) & 0xFFFFFFFF
                rand_pass   = (random.randrange(100) < 15) or (betrayal_lo < 2)
                if not rand_pass:
                    continue
                # History or deceit gate: history==0 OR DeceitLevel > 1.
                if not (state.g_HistoryCounter == 0 or state.g_DeceitLevel > 1):
                    continue

                # Form peace: set bilateral trust; reset relation if not already at 50.
                prev_relation = int(state.g_RelationScore[own_power, p])
                state.g_AllyTrustScore[own_power, p]    = 1
                state.g_AllyTrustScore_Hi[own_power, p] = 0
                state.g_AllyTrustScore[p, own_power]    = 1
                state.g_AllyTrustScore_Hi[p, own_power] = 0
                if prev_relation != 50:
                    state.g_RelationScore[own_power, p] = 0
                    state.g_RelationScore[p, own_power] = 0
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


def _rank_candidates_for_power(state: InnerGameState, power_idx: int) -> None:
    """FUN_00424850 — RankCandidatesForPower.

    Called from BuildAndSendSUB (inner loop) as FUN_00424850(power_idx, '\\0').
    Selects the best order candidates for *power_idx* from
    g_CandidateRecordList via a 7-phase pipeline:

      Phase 1  Find max score among this power's candidates.
      Phase 2  Build sorted list (ascending adjusted score; offset = 2500 - max).
      Phase 3  Pareto-dominance filter across all completed MC-trial dimensions
               (penalty 100 if n_allies==0, else 50).  Pareto-selected
               candidates accumulate an accepted frontier; dominated ones get
               a rank number and update min/max_rank.
      Phase 4  Probability scoring: each non-processed candidate's share of
               "remaining probability space" based on SC counts vs. up to
               three left-neighbours; write to rec['weight'] and update EMA
               of rec['running_avg'].
      Phase 5  Re-sort (same offset; order unchanged in practice).
      Phase 6  Rank/select: promote candidates whose running_avg ≥ threshold
               (call_count + 1) subject to rank/near-end-game guards.
               Promoted → processed=1, score = −1 000 000 − rank,
               output_score same, g_ScoreBaseline += 1.
      Phase 7  Normalize output_score: redistribute remaining probability
               budget (capped at 90) among non-promoted candidates.

    Only the param_2=='\\0' path is implemented (used by BuildAndSendSUB).

    Callees (C++, absorbed into Python list ops / math):
      FUN_00410330  — allocate list/tree node (absorbed into local list)
      FUN_00465870  — init empty token list (absorbed)
      FUN_0040fb70  — free list internals (absorbed)
      FUN_0040f260  — advance g_CandidateRecordList iterator (absorbed)
      FUN_00419fa0  — sorted-list insert (absorbed into sort())
      FUN_00412540  — advance accepted-frontier pointer (absorbed)
      FUN_0040e680  — basic iterator advance (absorbed)
      FUN_00414e10  — sorted-list destructor (absorbed)
    """
    # ── globals ───────────────────────────────────────────────────────────
    # DAT_0062cc64 — number of completed MC trials at call time
    n_trials: int = getattr(state, 'g_n_trials_completed', 0)
    # DAT_0062e460[power] — unit count (non-zero = active)
    unit_count_arr = state.g_UnitCount
    # DAT_00b9fe88[power] — ProcessTurn call count
    call_count_arr = getattr(state, 'g_PowerCallCount',
                             np.zeros(7, dtype=np.int32))
    near_end: float = state.g_NearEndGameFactor

    sc_count_local: int = int(unit_count_arr[power_idx]) + 1   # local_90 init
    alpha: float = (n_trials / (n_trials + 2)) if n_trials >= 0 else 0.0  # local_7c
    threshold: float = float(int(call_count_arr[power_idx]) + 1)  # local_80 (param_2=='\0' path)

    # ── Phase 1: find max score ──────────────────────────────────────────
    SENTINEL = -(1 << 20)
    max_score: int = SENTINEL
    for rec in state.g_CandidateRecordList:
        if rec.get('power_idx', rec.get('power', -1)) == power_idx:
            s = int(rec.get('score', 0))
            if max_score == SENTINEL or s > max_score:
                max_score = s
    if max_score == SENTINEL:
        return  # no candidates for this power

    score_offset: int = 0x9C4 - max_score   # local_78 = 2500 - max_score

    # ── Phase 2: sorted list by adjusted score ───────────────────────────
    power_recs = [
        rec for rec in state.g_CandidateRecordList
        if rec.get('power_idx', rec.get('power', -1)) == power_idx
    ]
    power_recs.sort(key=lambda r: int(r.get('score', 0)) + score_offset)

    # ── Phase 3: Pareto-dominance filter ────────────────────────────────
    # accepted_frontier holds the "not yet dominated" prefix of the sorted list.
    # A candidate is dominated if any frontier member beats it on ALL
    # trial dims by ≥ penalty AND their final-dim scores differ.
    accepted_frontier: list = []
    rank_counter: int = 0   # local_b8 (integer rank for non-Pareto items)

    for cand in power_recs:
        if cand.get('processed', 0):
            continue

        n_allies: int = int(cand.get('n_allies', 0))
        penalty: int = 100 if n_allies == 0 else 50
        trial_scores_c = cand.get('trial_scores', [])
        final_dim_c: int = cand.get('final_dim_score', 0)

        dominated = False
        for prev in accepted_frontier:
            trial_scores_p = prev.get('trial_scores', [])
            final_dim_p: int = prev.get('final_dim_score', 0)
            # Skip dim 0 if n_trials > 7 (start at 2); check dims 0..n_trials
            start_dim = 2 if n_trials > 7 else 0
            prev_dominates_all = True
            for t in range(start_dim, n_trials + 1):
                ps = trial_scores_p[t] if t < len(trial_scores_p) else 0
                cs = trial_scores_c[t] if t < len(trial_scores_c) else 0
                if ps < cs + penalty:
                    prev_dominates_all = False
                    break
            if prev_dominates_all and final_dim_p != final_dim_c:
                dominated = True
                break

        if not dominated:
            cand['pareto_flag'] = 1
            cand['running_avg'] = (
                (1.0 - alpha) * rank_counter
                + alpha * float(cand.get('running_avg', 0.0))
            )
            accepted_frontier.append(cand)
        else:
            cand['pareto_flag'] = 0
            ri = rank_counter
            if ri < int(cand.get('min_rank', 10001)):
                cand['min_rank'] = ri
            if int(cand.get('max_rank', 0)) < ri:
                cand['max_rank'] = ri
            rank_counter += 1

    # ── Phase 4: probability scoring ────────────────────────────────────
    # Walk non-processed records in sorted order; for each compute a
    # "share of remaining territory" using up to 3 left-neighbours'
    # SC counts via _safe_pow-based Elo-like formulas.
    # local_90 accumulates (starts at sc_count_local).
    non_proc = [r for r in power_recs if not r.get('processed', 0)]
    running_pool: float = float(sc_count_local)  # local_90

    for i, cand in enumerate(non_proc):
        sc_i: float = float(max(int(cand.get('sc_count', 0)), 0))
        share_a = 0.0   # local_b4
        share_b = 0.0   # local_48 low word
        share_c = 0.0   # local_68 low word

        if sc_i > 0:
            # Neighbour 1 (i-1): share_a = sc_j / (pow(sc_i-sc_j, sc_j) + sc_i + sc_j)
            if i >= 1:
                sc_j = float(max(int(non_proc[i - 1].get('sc_count', 0)), 0))
                if sc_j > 0:
                    diff_a = sc_i - sc_j
                    powered_a = _safe_pow(diff_a, sc_j) if diff_a != 0 else 1.0
                    denom_a = powered_a + sc_i + sc_j
                    share_a = sc_j / denom_a if denom_a else 0.0

            # Neighbour 2 (i-2): share_b = sc_k*0.666 / (pow(sc_i-sc_k,sc_k*0.666) + sc_i + sc_k)
            if i >= 2:
                sc_k = float(max(int(non_proc[i - 2].get('sc_count', 0)), 0))
                if sc_k > 0:
                    exp_b = sc_k * 0.666
                    diff_b = sc_i - sc_k
                    powered_b = _safe_pow(diff_b, exp_b) if diff_b != 0 else 1.0
                    denom_b = powered_b + sc_i + sc_k
                    share_b = exp_b / denom_b if denom_b else 0.0

            # Neighbour 3 (i-3): share_c = sc_l*0.5 / (pow(sc_i-sc_l,sc_l*0.5) + sc_i + sc_l)
            if i >= 3:
                sc_l = float(max(int(non_proc[i - 3].get('sc_count', 0)), 0))
                if sc_l > 0:
                    exp_c = sc_l * 0.5
                    diff_c = sc_i - sc_l
                    powered_c = _safe_pow(diff_c, exp_c) if diff_c != 0 else 1.0
                    denom_c = powered_c + sc_i + sc_l
                    share_c = exp_c / denom_c if denom_c else 0.0

        # fVar1 = (1.0 - share_b) * (100.0 - running_pool) * (1.0 - share_a) * (1.0 - share_c)
        fVar1 = (1.0 - share_b) * (100.0 - running_pool) * (1.0 - share_a) * (1.0 - share_c)
        cand['weight'] = fVar1          # ppiVar6[5][0x16]
        running_pool += fVar1           # local_90 accumulates

        # EMA update: running_avg = (1-alpha)*rank_position + alpha*old_avg
        rank_pos = float(i)             # local_b8 at this point (count of processed so far)
        cand['running_avg'] = (
            (1.0 - alpha) * rank_pos
            + alpha * float(cand.get('running_avg', 0.0))
        )

    # ── Phase 5: re-sort with same offset (already sorted; no-op) ───────

    # ── Phase 6: rank/select ─────────────────────────────────────────────
    rank_b: float = 0.0
    near_end_count: float = 0.0

    for cand in power_recs:
        # Count near-end-game non-processed candidates with move orders
        if int(cand.get('has_moves', 0)) and not cand.get('processed', 0) and near_end < 7.0:
            near_end_count += 1.0

        running_avg_f = float(cand.get('running_avg', 0.0))
        rank_i = int(rank_b)
        min_rank_v = int(cand.get('min_rank', 10001))
        pareto_f = int(cand.get('pareto_flag', 0))

        # Conditions that force "skip/demote" (goto LAB_00425626):
        # (a) running_avg < threshold, OR
        # (b) min_rank >= 6 AND rank >= 10, OR
        # (c) has_moves AND near_end_count < 10, OR
        # (d) already processed
        skip = (
            running_avg_f < threshold
            or (min_rank_v >= 6 and rank_i >= 10)
            or (bool(cand.get('has_moves', 0)) and near_end_count < 10.0)
            or bool(cand.get('processed', 0))
        )

        if not skip:
            # Promote: mark as selected, assign negative rank score
            final_s = -1000000 - rank_i
            cand['processed'] = 1
            cand['weight'] = 0.0
            cand['score'] = final_s
            cand['output_score'] = float(final_s)
            state.g_ScoreBaseline += 1
        else:
            # Demoted: clear pareto-selected weight, blend output_score
            if pareto_f == 1:
                cand['weight'] = 0.0
                cand['output_score'] = 0.0
            if n_trials >= 1:
                w = float(cand.get('weight', 0.0))
                os_old = float(cand.get('output_score', 0.0))
                cand['output_score'] = (1.0 - alpha) * w + os_old * alpha
            else:
                cand['output_score'] = float(cand.get('weight', 0.0))
            # Update rank bounds
            if rank_i < int(cand.get('min_rank', 10001)):
                cand['min_rank'] = rank_i
            if int(cand.get('max_rank', 0)) < rank_i:
                cand['max_rank'] = rank_i

        rank_b += 1.0

    # ── Phase 7: normalize output_score ─────────────────────────────────
    # Sum output_score for non-processed candidates → remaining = 100 - sum.
    # Cap remaining at 90.  Redistribute proportionally.
    total_os: float = sum(
        float(r.get('output_score', 0.0))
        for r in power_recs if not r.get('processed', 0)
    )
    remaining = 100.0 - total_os
    if remaining > 90.0:
        remaining = 90.0
    denom_n = 100.0 - remaining
    if denom_n and remaining > 0.0:
        for cand in power_recs:
            if not cand.get('processed', 0):
                os = float(cand.get('output_score', 0.0))
                cand['output_score'] = os + remaining * os / denom_n


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

    Token DAT constants (confirmed from token table at 0x004c7670):
        DAT_004c7678 = CTO (0x4320)
        DAT_004c767c = CVY (0x4321)
        DAT_004c7680 = HLD (0x4322)
        DAT_004c7684 = MTO (0x4323)
        DAT_004c7688 = SUP (0x4324)
        DAT_004c768c = VIA (0x4325)

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

    FUN_00463690 = _build_movement_order_token (fully ported).
    SPR/SUM orders are read from state.unit_info (own-power units with non-zero order type).
    FAL/AUT orders are read from state.g_retreat_order_list (populated before _send_gof);
         only own-power nodes are emitted (mirrors C power check at iVar6+0x18).
    WIN:
      Build entries should come from the build-candidate list at this+0x2474/0x2478.
      Each candidate has province at +0x0c (int) and BLD/REM DAIDE token at +0x10 (short).
      this+0x2480 (int) = waive count; this+0x2488 (char) = fleet-build flag.
      THESE FIELDS HAVE NO PYTHON EQUIVALENT YET — the build loop currently falls back
      to state.g_build_order_list (stub) so callers must populate that list before
      invoking _send_gof. state.g_waive_count (int) and state.g_fleet_build_flag (bool)
      must also be set. TODO: add these fields to InnerGameState once the winter-order
      handler that populates this+0x2474 is ported (needs Ghidra for handler function).
    """
    phase = getattr(state, 'g_season', 'SPR')
    own_power = getattr(state, 'albert_power_idx', 0)
    power_name = _DAIDE_POWER_NAMES[own_power] if 0 <= own_power < len(_DAIDE_POWER_NAMES) else 'UNO'

    # DAT_004c77a0 = GOF (0x4803) — always the first token
    seq: list = ['GOF']

    if phase in ('SPR', 'SUM'):
        # FUN_00463690 = _build_movement_order_token.
        # C: for each unit in active list (this+0x2450/2454):
        #   if unit.power (iVar6+0x18) == own_power (this+0x2424) AND
        #      unit.order_flag (iVar6+0x20) != 0:
        #     build token via FUN_00463690; FUN_00466c40 wraps in parens, appends to output.
        for prov, unit_data in state.unit_info.items():
            if unit_data.get('power') != own_power:
                continue
            tok = _build_movement_order_token(state, prov)
            if tok is not None:
                seq.append(f'( {tok} )')        # FUN_00466c40 wraps in parens
    elif phase in ('FAL', 'AUT'):
        # FUN_00460110 = _build_retreat_order_token.
        # C: for each unit in retreat list (this+0x245c/2460):
        #   if unit.power (iVar6+0x18) == own_power (this+0x2424) AND
        #      unit.order_flag (iVar6+0x20) != 0:
        #     build token; FUN_00466c40 wraps in parens, appends to output.
        # Power filter mirrors the C power check; g_retreat_order_list may contain
        # all powers' retreat units.
        for node in state.g_retreat_order_list:
            if node.get('power') != own_power:          # iVar6+0x18 == own_power check
                continue
            tok = _build_retreat_order_token(state, node)
            if tok is not None:
                seq.append(f'( {tok} )')          # FUN_00466c40 wraps in parens
    else:
        # WIN: BLD/REM per candidate (build list this+0x2474/2478) +
        #      WVE per waiver (count at this+0x2480).
        # DAT values (all confirmed — see DaideTokenEncoding.md token table at 0x004c7670):
        #   DAT_004c7670 = AMY (0x4200)
        #   DAT_004c7674 = FLT (0x4201)
        #   DAT_004c7698 = BLD (0x4380)
        #   DAT_004c769c = REM (0x4381)
        #   DAT_004c76a0 = WVE (0x4382)
        # C per-candidate:
        #   1. [POWER] from this+0x2424
        #   2. If *(short*)(iVar3+0x10) == AMY: append AMY; else append FLT → [POWER, AMY/FLT]
        #      (iVar3+0x10 = unit type token: AMY=0x4200 or FLT=0x4201)
        #   3. Province from iVar3+0x0c; CONCAT22(0x46, 0x42xx) → byte1=0x42≠0x46 → no coast
        #      → [POWER, FLT/AMY, PROV]
        #   4. FUN_00465aa0 wraps → ( POWER FLT/AMY PROV )  ← standard DAIDE unit spec
        #   5. If this+0x2488 == 0: append REM (remove phase); else append BLD (build phase)
        #   6. FUN_00466c40 wraps all → ( ( POWER FLT/AMY PROV ) BLD/REM )  ← standard DAIDE ✓
        # this+0x2488 = 0 → remove phase; != 0 → build phase.
        # g_build_order_list: populated by WIN handler; cleared by ResetPerTrialState.
        for order in state.g_build_order_list:
            seq.append(f'( {order} )')
        # WVE: C calls FUN_00466540(own_power_tok, ..., WVE) → [own_power, WVE].
        # AppendSeq wraps to ( own_power WVE ). Per DAIDE spec: "power WVE".
        waive_count: int = state.g_waive_count
        for _ in range(waive_count):
            seq.append(f'( {power_name} WVE )')  # DAT_004c76a0=WVE; power from this+0x2424

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

        # 5f — GenerateOrders + ScoreOrderCandidates (FUN_004559c0)
        # ScoreOrderCandidates:
        #   Step 1: clear g_CandidateList2 (per-power secondary lists) → reset
        #            g_CandidateRecordList so each scoring pass starts fresh.
        #   Step 2: reset proposal records in g_CandidateRecordList for new round.
        #   Step 3: call ProcessTurn for each power where
        #             unit_count[p] > 0 AND general_orders_present[p] != 0.
        #            trial_count = (unit_count[p] * g_TrialScale + 10) // 10;
        #            if g_PressProposalsCap == 0 AND p != own_power: trial_count = 1.
        #   Steps 4–5: proposal matching / scoring (DAIDE token comparison) — absorbed
        #              into the MC candidate scoring: each ProcessTurn call populates
        #              g_CandidateRecordList entries with scored order sets.
        from .monte_carlo import generate_orders
        generate_orders(self.state, own_power_idx)

        # Step 1 — clear candidate list before scoring pass
        self.state.g_CandidateRecordList = []

        # Step 3 — call ProcessTurn for every active power (DAT_0062e460 / g_UnitCount)
        # g_TrialScale = DAT_004c6bb8 = difficulty*2+60 (default difficulty=100 → 260)
        # g_PressProposalsCap = DAT_004c6bbc = (difficulty*3)//10 capped at 30
        trial_scale: int = getattr(self.state, 'g_TrialScale', 260)
        press_cap: int = getattr(self.state, 'g_PressProposalsCap', 30)
        unit_count = getattr(self.state, 'g_UnitCount', np.zeros(num_powers, dtype=np.int32))
        general_orders_present = getattr(
            self.state, 'g_GeneralOrdersPresent', np.zeros(num_powers, dtype=np.int32))
        for p in range(num_powers):
            if int(unit_count[p]) > 0 and int(general_orders_present[p]) != 0:
                if press_cap == 0 and p != own_power_idx:
                    n_trials = 1
                else:
                    n_trials = (int(unit_count[p]) * trial_scale + 10) // 10
                process_turn(self.state, p, num_trials=n_trials)
        best_orders = self.state.g_CandidateRecordList  # populated by process_turn

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

            # Draw vote — FUN_0044c9d0 wrapper (PrepareDrawVoteSet):
            #   Build friendly-powers set: own power + any power p where
            #     curr_sc_cnt[p] > 0 AND g_AllyTrustScore[own, p] > 1
            #   (C: StdMap_FindOrInsert keyed by power index; passed as param_1
            #    to ComputeDrawVote where Map_Find(param_1, unit+0x18) checks
            #    unit.power ∈ friendly_powers).
            #   Result stored in DAT_00baed2b; any of the four draw flags set → DRW.
            sc_count = getattr(self.state, 'sc_count',
                               np.zeros(num_powers, dtype=np.int32))
            friendly_powers: set = {own_power_idx}
            for p in range(num_powers):
                if p == own_power_idx:
                    continue
                if int(sc_count[p]) > 0:
                    trust_hi = int(self.state.g_AllyTrustScore_Hi[own_power_idx, p])
                    trust_lo = int(self.state.g_AllyTrustScore[own_power_idx, p])
                    # C: trust > 1 ↔ Hi >= 0 AND (Hi > 0 OR Lo > 1)
                    if trust_hi >= 0 and (trust_hi > 0 or trust_lo > 1):
                        friendly_powers.add(p)

            draw_vote = compute_draw_vote(self.state, friendly_powers)
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

        In the C bot this is a multi-trial proposal-scoring loop over
        g_BroadcastList; Monte Carlo (process_turn) plays that role in Python,
        so only the surrounding press/submission scaffold is ported here.

        Structure (mirroring FUN_00457890 at each labelled site):
          1. ScheduledPressDispatch     — pre-loop flush (line 252).
          2. CheckTimeLimit             — abort if MTL already fired (line 291).
          3. Order submission           — RegisterProposalOrders / ScoreOrderCandidates
                                         collapsed to game.set_orders (MC already ran).
          4. UpdateScoreState           — refresh ally order tables after commit
                                         (line 395 inside inner loop, post-submission).
          5. SendAllyPressByPower loop  — for each power when g_HistoryCounter > 0
                                         (lines 659–666).
          6. g_ProposalHistoryMap press — iterate received/sent proposals, check
                                         province overlap and trust, send DM press
                                         (lines 847–1271; STUB — awaits RECEIVE_PROPOSAL
                                         / RESPOND / g_ProposalHistoryMap port).
          7. CancelPriorPress           — withdraw stale prior-press token (line 693).

        Callees still unported: ScoreOrderCandidates (FUN_004559c0),
        RECEIVE_PROPOSAL, RESPOND, BuildHostilityRecord, SendAlliancePress,
        FUN_00419300, FUN_00466ed0, FUN_00466f80, FUN_00465df0, GetSubList,
        FUN_00465930, FUN_00465d90, FUN_00422a90, FUN_00465cf0, FUN_00410cf0,
        FUN_00443ed0.
        """
        own_power_idx = getattr(self.state, 'albert_power_idx', 0)
        n_powers = int(getattr(self.state, 'n_powers', 7))

        # ── 1. ScheduledPressDispatch — pre-loop press flush (line 252) ──────
        dispatch_scheduled_press(self.state, self._send_dm)

        # ── 2. CheckTimeLimit (line 291) — MTL guard ─────────────────────────
        if check_time_limit(self.state):
            logger.warning("MTL expired before BuildAndSendSUB — skipping SUB")
            return

        if not best_orders:
            logger.warning("MC selection produced no orders — nothing submitted")
            return

        # ── 3. Order submission ───────────────────────────────────────────────
        # C: RegisterProposalOrders + ScoreOrderCandidates per trial in inner
        # loop.  Python: MC already selected best_orders; build and submit
        # directly.
        best = best_orders[0]
        order_pairs = best.get('orders', [])   # [(prov, order_type), ...]

        self.state.g_OrderList = []
        for prov, _order_type in order_pairs:
            seq = _build_order_seq_from_table(self.state, prov)
            if seq is not None:
                dispatch_single_order(self.state, own_power_idx, seq)

        formatted = list(self.state.g_OrderList)
        logger.info("SUB — %d orders for %s: %s",
                    len(formatted), self.power_name, formatted)

        if self.game is not None:
            self.game.set_orders(self.power_name, formatted)

        # ── 3b. RankCandidatesForPower — inner-loop candidate selection ─────
        # C: FUN_00424850(piVar10, '\0') called per-power in BuildAndSendSUB
        # inner loop after ScoreOrderCandidates.  In Python, MC has already
        # run; call once per power to rank g_CandidateRecordList entries.
        for power_i in range(n_powers):
            _rank_candidates_for_power(self.state, power_i)

        # ── 4. UpdateScoreState — post-commit refresh (line 395) ─────────────
        update_score_state(self.state)

        # ── 5. SendAllyPressByPower loop (lines 659–666) ─────────────────────
        # C: if puVar18[4] == DAT_00baed60 AND g_HistoryCounter > 0:
        #      for i in range(n_powers): SendAllyPressByPower(i)
        # The g_BroadcastList node condition collapses to "own proposal processed"
        # which is always true here after order submission.
        if self.state.g_HistoryCounter > 0:
            for power_i in range(n_powers):
                _send_ally_press_by_power(self.state, power_i, self._send_dm)

        # ── 6. g_ProposalHistoryMap press deal matching (lines 847–1271) ─────
        # STUB: full port awaits RECEIVE_PROPOSAL / RESPOND / g_ProposalHistoryMap.
        # C iterates g_ProposalHistoryMap; for each entry:
        #   received proposals (node[4] == own_power): trust ≥ 1, province
        #     overlap ≥ 3 → SUB press via AppendList + SendAlliancePress.
        #   sent proposals (node[6] == own_power): trust ≥ 2 for other power
        #     → SUB press via SendAlliancePress.
        # Placeholder: iterate g_DealList as a loose proxy (trust ≥ 3, overlap).
        if self.state.g_HistoryCounter > 19:
            submitted_provs = {prov for prov, _ in order_pairs}
            for deal in list(getattr(self.state, 'g_DealList', [])):
                other = deal.get('power', -1)
                if other < 0:
                    continue
                trust = int(self.state.g_AllyTrustScore[own_power_idx, other])
                if trust < 3:
                    continue
                deal_provs = deal.get('province_set', set())
                if deal_provs & submitted_provs:
                    self._send_dm(f"PRP ( PCE ( {own_power_idx} {other} ) )")
                    logger.debug("Deal match: sent ally press to power %d (trust=%d)",
                                 other, trust)

        # ── 7. CancelPriorPress — DM send with TokenSeq_Count guard (line 693)
        cancel_prior_press(self.state, own_power_idx, self._send_dm)

    # ── Press handler ────────────────────────────────────────────────────────

    def on_message_received(self, sender: str, msg: str) -> None:
        """Triggered when a press message (FRM) arrives."""
        parse_message(self.state, sender, msg)
