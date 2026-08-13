"""Monte-Carlo trial loop (ProcessTurn) and its auxiliaries.

Split from monte_carlo.py during the 2026-04 refactor.  This is the core of
the MC engine:

- ``trial_evaluate_orders``    — deep-copy a candidate order set for an
                                 isolated trial.
- ``process_turn``             — 1 200+ line port of FUN_0044c9d0; the full
                                 MC trial loop (Phases 1a–5) that dispatches
                                 candidate orders into ``g_order_table``,
                                 scores each realisation, and rolls up the
                                 per-province best-score tables.
- ``_update_ally_order_score`` — adjust ally-order score after Phase 3.
- ``_refresh_order_table``     — rebuild ``g_order_table`` between trials.
- ``update_score_state``       — composite helper used by Phase 5.
- ``check_time_limit``         — read ``state.mtl_expired`` atomically.

Module-level deps: ``copy``, ``random``, ``numpy``, ``..state.InnerGameState``,
three enumerators from ``..moves``, ``evaluate_order_proposal`` from
``.evaluation``, and field/order-type constants from ``._flags``.
"""

import collections
import copy
import logging
import random

import numpy as np

_dbg_log = logging.getLogger("pybert.scoring_dbg")

from ..state import InnerGameState
from ..moves import (
    assign_support_order,
    assign_hold_supports,
    register_convoy_fleet,
    score_convoy_fleet,
    build_convoy_orders,
)

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_SELECTED_SCORE_LO, _F_SELECTED_SCORE_HI,
    _F_INCOMING_MOVE, _F_SUP_CHAIN_CONFLICT,
    _F_THREAT_TOTAL, _F_MOVE_HISTORY, _F_ORDER_ASGN,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from .evaluation import (
    candidate_orders_key,
    evaluate_order_proposal,
    restore_order_entry,
)


def trial_evaluate_orders(state: InnerGameState, trial_candidate: dict) -> dict:
    """
    State duplicator for trial resolutions.  Deep-copies the candidate order
    dict so each MC trial is isolated.  The caller is responsible for loading
    trial_candidate into state.g_order_table before calling evaluate_order_score.
    """
    return copy.deepcopy(trial_candidate)


def _step3_designation_trust(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    dest: int,
    num_powers: int = 7,
) -> tuple[int, int]:
    """Return ProcessTurn Step 3's designation-derived trust pair.

    C:2016-2041 evaluates the slots in C, A, B order.  Each qualifying slot
    overwrites the pair, so B has final precedence.  Unlike the later order
    emission block, A is not an "only if empty" fallback: it is guarded by the
    designated power differing from ``power_index`` and by that power's threat
    at ``dest`` being below 2.
    """
    trust_lo = 0
    trust_hi = 0

    def read_slot(arr_lo, arr_hi) -> tuple[int, int] | None:
        if not 0 <= dest < len(arr_lo):
            return None
        slot_lo = int(arr_lo[dest])
        slot_hi = int(arr_hi[dest])
        if slot_hi < 0 or not 0 <= slot_lo < num_powers:
            return None
        relation = int(state.g_relation_score[power_index, slot_lo])
        if relation <= 9 and power_index != own_power:
            return None
        return (
            int(state.g_ally_trust_score[power_index, slot_lo]),
            int(state.g_ally_trust_score_hi[power_index, slot_lo]),
        )

    # Slot C (DAT_004d3610/14).
    slot_trust = read_slot(
        state.g_ally_designation_c,
        state.g_ally_designation_c_hi,
    )
    if slot_trust is not None:
        trust_lo, trust_hi = slot_trust

    # Slot A (g_AllyDesignation_A): C additionally rejects our own power and
    # requires DAT_005460e8/ec[A, dest] to represent a threat value below 2.
    if 0 <= dest < len(state.g_ally_designation_a):
        slot_a = int(state.g_ally_designation_a[dest])
        if (slot_a != power_index and 0 <= slot_a < num_powers
                and int(state.g_threat_level[slot_a, dest]) < 2):
            slot_trust = read_slot(
                state.g_ally_designation_a,
                state.g_ally_designation_a_hi,
            )
            if slot_trust is not None:
                trust_lo, trust_hi = slot_trust

    # Slot B (DAT_004d2610/14) is evaluated last and overwrites unconditionally
    # when its validity/relation checks pass.
    slot_trust = read_slot(
        state.g_ally_designation_b,
        state.g_ally_designation_b_hi,
    )
    if slot_trust is not None:
        trust_lo, trust_hi = slot_trust

    return trust_lo, trust_hi


def _apply_step3_support_filter(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    source: int,
    candidates: list[tuple],
    score_threshold: float,
    reachable_provinces: dict,
    num_powers: int = 7,
) -> float:
    """Run ProcessTurn C:1987-2085 and return its updated threshold.

    Despite the historical Python name/comment, this block does not remove a
    candidate.  ``DAT_00bb7124`` is the reachable/history set assembled at
    the start of ProcessTurn, not a unit-occupancy lookup.  Candidates outside
    that set and without designation trust are registered with
    ``ScoreSupportOpp`` unless they are class-1/unmarked/unclaimed.  In that
    final case a candidate at or above the threshold replaces the threshold
    and exits the walk; a lower candidate is simply advanced past.
    """
    for candidate in candidates:
        cand_score, dest = candidate[:2]
        dest = int(dest)
        trust_lo, trust_hi = _step3_designation_trust(
            state, power_index, own_power, dest, num_powers
        )
        if dest in reachable_provinces or trust_lo != 0 or trust_hi != 0:
            continue

        target_class = (
            int(state.g_prov_target_flag[power_index, dest])
            if 0 <= dest < 256 else 0
        )
        companion = (
            int(state.g_target_flag2[power_index, dest])
            if 0 <= dest < 256 else 0
        )
        incoming = (
            int(state.g_order_table[dest, _F_INCOMING_MOVE])
            if 0 <= dest < state.g_order_table.shape[0] else 0
        )
        if target_class != 1 or companion != 0 or incoming != 0:
            state.g_support_opp_map.setdefault(source, dest)
            continue

        if float(cand_score) >= float(score_threshold):
            score_threshold = float(cand_score)
            break

    return score_threshold


def _apply_step4_xdo_constraint(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    source: int,
    candidates: list[tuple],
) -> list[tuple]:
    """Apply ProcessTurn Step 4's accepted-XDO move/hold constraint.

    DAT_00bb69f8 supplies a source→destination move, while membership in
    DAT_00bb6af8 means the proposed destination is the source itself (hold).
    The sole exception is an XDO move whose destination already contains our
    own unit with a HLD order; C leaves that unit's candidate list untouched.
    """
    if power_index != own_power:
        return candidates

    move_map = state.g_xdo_order_move_by_power.get(power_index, {})
    hold_set = state.g_xdo_order_hold_by_power.get(power_index, set())
    if source in move_map:
        proposed_dest = move_map[source]
        dest_unit = state.unit_info.get(proposed_dest)
        own_unit_holding = (
            dest_unit is not None
            and int(dest_unit.get('power', -1)) == power_index
            and 0 <= proposed_dest < state.g_order_table.shape[0]
            and int(state.g_order_table[proposed_dest, _F_ORDER_TYPE]) == _ORDER_HLD
        )
        if own_unit_holding:
            return candidates
    elif source in hold_set:
        proposed_dest = source
    else:
        return candidates

    matching = [candidate for candidate in candidates
                if int(candidate[1]) == proposed_dest]
    # C first scans for the proposed destination and only enters its removal
    # pass when a matching candidate exists.
    return matching if matching else candidates


def _dedupe_step5_fleet_candidates(candidates: list[tuple]) -> list[tuple]:
    """Apply ProcessTurn C:2184-2234 to one fleet's candidate tree.

    ``piStack_70c`` is a temporary set created empty immediately before the
    walk.  C inserts each candidate's destination into that set and removes a
    candidate only when its destination is already present.  After a removal
    it clears the set and restarts the walk.  The net result is stable
    destination de-duplication of *this candidate list*; it does not inspect
    orders assigned to other fleets.
    """
    seen: set[int] = set()
    deduped: list[tuple] = []
    for candidate in candidates:
        dest = int(candidate[1])
        if dest in seen:
            continue
        seen.add(dest)
        deduped.append(candidate)
    return deduped


def _apply_step6_target_filter(
    state: InnerGameState,
    power_index: int,
    source: int,
    candidates: list[tuple],
    score_threshold: float,
) -> list[tuple]:
    """Apply ProcessTurn's target-class pruning at C:2235-2391.

    A class-1 or class-2 destination with companion marker zero is removed
    when its score is below the source threshold.  The exception in both C
    branches is a province marked by ``RegisterConvoyFleet`` that is also in
    the source province's adjacency map (the per-province maps at +0x2a1c).

    C's two class-2 blocks split on ``current_outer_candidate.dest == dest``
    and ``!=`` and then execute the same removal gate, so together they cover
    every class-2 destination.  ``g_ProvinceBase[source] < 5000`` is also in
    both blocks; that counter starts at zero and is incremented by one at
    C:2687, making the guard invariant for real Diplomacy positions.
    """
    if score_threshold <= 0:
        return candidates

    source_adjacencies = set(state.adj_matrix.get(source, ()))
    filtered: list[tuple] = []
    for candidate in candidates:
        score, dest = candidate[:2]
        dest = int(dest)
        if not 0 <= dest < 256:
            filtered.append(candidate)
            continue

        target_class = int(state.g_prov_target_flag[power_index, dest])
        companion = int(state.g_target_flag2[power_index, dest])
        below_threshold = float(score) < float(score_threshold)
        if target_class in (1, 2) and companion == 0 and below_threshold:
            convoy_exception = (
                int(state.g_province_score_trial[dest]) != 0
                and dest in source_adjacencies
            )
            if not convoy_exception:
                continue
        filtered.append(candidate)
    return filtered


def _apply_convoy_swap(
    state: InnerGameState,
    power_index: int,
    source: int,
    destination: int,
    rand_value: int | None = None,
) -> bool:
    """Port ProcessTurn's ``LAB_00453cac`` path (C:2757-2865).

    When a destination already has a registered mover and a pending support
    assignment, C occasionally resolves that assignment as a complete convoy
    chain instead of making ``source`` emit SUP_MTO.  The random expression is
    the binary's ``(rand() / 0x17) % 100 > 60``.  ``rand_value`` exists only so
    the boundary can be tested without replacing the module RNG.
    """
    if int(state.g_order_table[destination, _F_ORDER_ASGN]) != 1:
        return False

    roll_source = random.randint(0, 32767) if rand_value is None else rand_value
    if (int(roll_source) // 0x17) % 100 <= 60:
        return False

    source_demand = int(state.g_support_demand[source])
    destination_unit = state.unit_info.get(destination)
    own_unit_at_destination = (
        destination_unit is not None
        and int(destination_unit.get('power', -1)) == power_index
    )
    if source_demand != 1 and not (own_unit_at_destination and source_demand == 0):
        return False

    assigned = int(state.g_convoy_source_prov[destination])
    if not 0 <= assigned < state.g_order_table.shape[0]:
        return False

    # C:2772-2829.  Destination advances from pending (1) to consumed (2);
    # source and its assigned province become complete convoy-chain members.
    state.g_order_table[destination, _F_ORDER_ASGN] += 1.0
    state.g_order_table[source, _F_ORDER_ASGN] = 5.0
    state.g_order_table[assigned, _F_ORDER_ASGN] = 5.0
    state.g_order_table[assigned, 24] = -1.0
    state.g_order_table[assigned, 25] = -1.0

    source_score = float(state.final_score_set[power_index, source])
    assigned_score = float(state.final_score_set[power_index, assigned])
    state.g_convoy_chain_score[source] = source_score
    state.g_order_score_hi[source] = 0.0
    state.g_order_table[source, _F_CONVOY_LO] = source_score
    state.g_order_table[source, _F_CONVOY_HI] = 0.0
    state.g_convoy_chain_score[assigned] = assigned_score
    state.g_order_score_hi[assigned] = 0.0
    state.g_order_table[assigned, _F_CONVOY_LO] = assigned_score
    state.g_order_table[assigned, _F_CONVOY_HI] = 0.0
    state.g_order_table[source, _F_INCOMING_MOVE] = 1.0
    state.g_order_table[assigned, _F_INCOMING_MOVE] = 1.0
    return True


def process_turn(state: InnerGameState, power_index: int, num_trials: int = -1) -> None:
    """
    Port of FUN_00453220 = ProcessTurn(Albert *this, int **power_index, int num_trials).

    Per-power Monte Carlo order-assignment engine.  Called by ScoreOrderCandidates
    once per active power.  Runs ``num_trials`` independent MC trials for
    ``power_index`` and accumulates results into state.g_candidate_record_list.

    Signature matches decompiled: __thiscall ProcessTurn(param_1_00, power_index, num_trials)
      param_1_00  → state (Albert *this)
      power_index → the power being simulated this call
      num_trials  → number of Monte Carlo iterations; if -1 (default), computed from
                    state per ScoreOrderCandidates.c:331–334:
                    (unit_count[p] * g_trial_scale + 10) // 10, or 1 for non-own
                    powers when g_press_proposals_cap == 0.

    Phase 0 — Setup (once per call)
    --------------------------------
    0a. Build reachable-province set (reachable_provinces) by scanning the ally-
        shared order-history list for power_index (or own-power variant when
        power_index == own_power).
    0b. Per-power order-history copy: copy g_order_history[p] → local per-power sets.
    0c. Ally flag scan: local_76f = 1 if g_xdo_press_sent[power_index, p] for any p.
    0d. Random start offset for the cyclical power-expand pass.

    Phase 1 — Monte Carlo trial loop (num_trials iterations)
    ----------------------------------------------------------
    Each trial:
    1a. Per-trial state reset:
        - clear g_support_trust_adj / g_ring_convoy_score / g_EarlyGameAdjScore / g_other_score
        - clear g_convoy_dst_list, g_trial_list2, g_trial_map
        - reset g_order_table all-provinces (order type 0, coast -1, other fields 0)
        - reset g_convoy_source_prov[prov] = -1, g_convoy_active_flag[prov] = 0,
          g_ProvinceScore[prov] = 0, g_army_adj_count[prov] = 0
        - reset g_unit_presence[power, prov] = -1 for all power,prov
    1b. Unit list scan:
        - g_unit_presence[unit.power, unit.province] = 0
        - for own armies: g_army_adj_count[adj]++ for each AMY-adjacent province
    1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP):
        - If power_index == own_power (or trusted ally): dispatch g_alliance_orders[power_index]
        - Dispatch g_general_orders[power_index] (second pass)
    1d. Ring-convoy check (if g_ring_convoy_enabled):
        - Verify ring A→B, B→C, C→A is still intact; build MTO orders if valid.
    1e. Random exploit pass (15% chance; 35% if late-game + has_ally):
        - Cycle through allied powers looking for defection / secondary targets.
        - Insert matching proposal records from g_deal_list into local candidate set.
    1f. Support assignment:
        - Find own unordered SC provinces → call assign_hold_supports.
    1g. Convoy chain assignment:
        - Iterate g_convoy_dst_list; score / rank fleet candidates via score_convoy_fleet.
    1h. Target-bonus scoring:
        - +150/+75 per MTO/CTO unit moving to a flagged target province.
        - +50 per SUP_MTO into an SC-gaining support.
    1i. Call evaluate_order_proposal(state, power_index) once per trial.

    Callees (unported stubs where noted):
      reset_per_trial_state   — FUN_00460be0; resets board-level snapshot
      dispatch_single_order   — dispatch.py; already ported
      assign_hold_supports    — FUN_0041d270; ported (moves.hold)
      score_convoy_fleet      — BST insert-with-score; ported (moves.convoy)
      move_candidate          — BST erase/pop from Albert+0x4cfc; ported (inner func)
      build_order_mto         — writes MTO into g_order_table; ported (inner func)
      insert_order_candidate  — FUN_004153b0; std::_Tree::_Insert for InsertOrderCandidate tree; ported inline as _insert_order_candidate (bisect-sorted list)
      evaluate_order_proposal — monte_carlo.py; already ported
    """
    import logging
    logger = logging.getLogger(__name__)

    own_power: int = getattr(state, 'albert_power_idx', 0)

    # ScoreOrderCandidates.c:331–334: compute per-power trial count when the
    # caller did not supply one explicitly.
    if num_trials < 0:
        _uc = getattr(state, 'g_unit_count', [])
        _scale = int(getattr(state, 'g_trial_scale', 260))
        num_trials = max(1, (int(_uc[power_index]) * _scale + 10) // 10)
    # ScoreOrderCandidates.c:333–335: clamp non-own powers to 1 trial when
    # press proposals are disabled.  Applied unconditionally so callers that
    # pass explicit num_trials are also guarded.
    if int(getattr(state, 'g_press_proposals_cap', 30)) == 0 and power_index != own_power:
        num_trials = 1

    num_provinces: int = int(getattr(state, 'num_provinces',
                                     state.g_order_table.shape[0]))
    num_powers: int = 7

    # ── helpers for unported stubs ────────────────────────────────────────────
    def _reset_per_trial_state() -> None:
        """Port of FUN_00460be0 = ResetPerTrialState.

        C operations (see Source/monte_carlo/ResetPerTrialState.c):
        (1) Walk active unit list (this+0x2450/54): clear node+0x20 per unit.
        (2) Walk retreat unit list (this+0x245c/60): same.
        (3) Walk and free all BST nodes at this+0x2478 (lines 52-60).
        (4) Reset BST sentinel: sentinel[1]=sentinel, *sentinel=sentinel,
            sentinel[2]=sentinel (lines 61, 63, 64).
        (5) this+0x247c = 0  — BST _Mysize counter (line 62).
        (6) this+0x2480 = 0  — waive count (line 65).
        Python: (3)+(4)+(5) are all implicit in list.clear(); tracked
        explicitly via g_build_order_list_size for offset parity.
        """
        # (1) Active unit list — clear per-unit order-assigned pointer.
        for prov in state.unit_info:
            state.g_order_table[prov, _F_ORDER_TYPE] = 0.0
        # (2) Retreat unit list — clear per-unit order-assigned pointer.
        for entry in getattr(state, 'g_retreat_order_list', []):
            entry['order_type'] = 0
        # (3)+(4) Free BST nodes + reset sentinel → list.clear().
        state.g_build_order_list.clear()
        # (5) this+0x247c = 0 — BST size counter.
        state.g_build_order_list_size = 0
        # (6) this+0x2480 = 0 — waive count.
        state.g_waive_count = 0


    def _move_candidate(prov: int) -> None:
        """MoveCandidate (FUN_00411cf0) — BST erase from g_convoy_fleet_candidates.

        Removes the existing entry for *prov* (if any) before re-inserting with
        an updated score.  Mirrors std::map::erase(iterator).
        """
        state.g_convoy_fleet_candidates = [
            e for e in state.g_convoy_fleet_candidates if e[1] != prov
        ]

    def _build_order_mto(src: int, dst: int, coast: int) -> None:
        """Port of BuildOrder_MTO — write MTO into g_order_table.

        Decompile-verified (decompiled.txt).  Signature:
          __thiscall BuildOrder_MTO(this, power, src_province, dst_province, coast)

        Stubbed callees:
          ClearConvoyState()        — clears per-convoy temp state; trial reset covers it
          BuildOrder_CTO_Ring(...)  — builds CTO ring chain; decompile-verified (BuildOrder_CTO.c:67)
          RegisterConvoyFleet(...)  — decompile-verified (RegisterConvoyFleet.c); called at end of fn
        """
        # ClearConvoyState() — STUB (per-trial reset at Phase 1a covers observable effect)

        # Determine unit type at src (AMY vs FLT)
        unit_type = state.unit_info.get(src, {}).get('type', '')
        is_army = (unit_type == 'A')

        # Unit-type terrain gate: fleets cannot enter landlocked provinces,
        # armies cannot enter sea zones.  Silently reject — the trial will
        # fall back to the default HLD seeded in Phase 1b'.
        if unit_type in ('F', 'FLT') and dst in state.land_provinces:
            return
        if unit_type in ('A', 'AMY') and dst in state.water_provinces:
            return

        # ── Same-power self-bump / swap prevention ───────────────────────
        # The C post-selection logic (ProcessTurn.c lines 2579-2694)
        # rejects a move when a same-power unit at the destination is NOT
        # leaving (HLD/SUP/CVY → self-bump) or IS leaving but back to src
        # (reciprocal swap A→B + B→A).  Only allow when the unit at dst
        # has MTO/CTO to a DIFFERENT province (it is vacating dst).
        # Guard here so ALL call sites are protected; fall back to HLD.
        dst_unit = state.unit_info.get(dst)
        if dst_unit is not None:
            src_unit = state.unit_info.get(src)
            if src_unit is not None and dst_unit.get('power') == src_unit.get('power'):
                dest_ot = int(state.g_order_table[dst, _F_ORDER_TYPE])
                if dest_ot in (_ORDER_MTO, _ORDER_CTO):
                    # Unit at dst is leaving — but is it a swap?
                    dest_dst = int(state.g_order_table[dst, _F_DEST_PROV])
                    if dest_dst == src:
                        # Reciprocal swap: reject
                        state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_HLD)
                        return
                    # Leaving to a different province: allow the move
                else:
                    # Unit at dst is NOT leaving (HLD, SUP, CVY): self-bump
                    state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_HLD)
                    return

        # ── Coast resolution for multi-coast destinations ────────────────
        # In C, each adjacency-list edge carries a coast token (piVar7[4]),
        # so the BST candidate node already has the correct coast when
        # BuildOrder_MTO is called.  The Python adj_matrix only stores
        # province IDs, so callers pass coast=0.  Resolve it here for
        # fleet moves to multi-coast provinces (BUL, SPA, STP).
        if coast == 0 and unit_type in ('F', 'FLT'):
            coast = state.resolve_fleet_coast(src, dst)

        # BuildOrder_CTO_Ring(gamestate, src, dst, coast)
        # OrderedSet_FindOrInsert(this+0x2450, &src): insert src into active-unit set.
        # If src already present (iVar2 == iVar3 sentinel) → early return, no-op.
        # Otherwise write node+0x20=2 (MTO ring), node+0x24=dst, node+0x28=coast.
        # Python: g_order_table proxies the ordered-set node fields; guard on
        # _F_ORDER_TYPE != 0 mirrors the "already inserted" early-return.
        if int(state.g_order_table[src, _F_ORDER_TYPE]) == 0:
            state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_MTO)  # 2 = MTO ring
            state.g_order_table[src, _F_DEST_PROV]  = float(dst)
            state.g_order_table[src, _F_DEST_COAST] = float(coast)

        # ConvoyList_Insert(&DAT_00bb65a0, &dst): append dst to convoy dst list; record dst→src
        if dst not in state.g_convoy_dst_list:
            state.g_convoy_dst_list.append(dst)
        if not hasattr(state, 'g_convoy_dst_to_src'):
            state.g_convoy_dst_to_src = {}
        state.g_convoy_dst_to_src[dst] = src

        # g_order_table[src]: write MTO order type, destination, coast
        state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_MTO)
        state.g_order_table[src, _F_DEST_PROV]  = float(dst)
        state.g_order_table[src, _F_DEST_COAST] = float(coast)

        # g_ProvinceBaseScore[dst] = 1: mark dst as having an incoming move
        state.g_order_table[dst, _F_INCOMING_MOVE] = 1.0

        # OrderedSet_FindOrInsert(this + power*0xc + 0x4000, &dst):
        # inherit dst's candidate score (final_score_set) into convoy chain score fields
        score_lo = float(state.final_score_set[power_index, dst])
        score_hi = 0.0
        state.g_convoy_chain_score[dst]        = score_lo
        state.g_order_score_hi[dst]            = score_hi
        state.g_order_table[dst, _F_CONVOY_LO] = score_lo
        state.g_order_table[dst, _F_CONVOY_HI] = score_hi

        # DAT_00baede4[dst*0x1e] = g_move_history_matrix[dst + (src + power*0x40)*0x40]
        # Python layout: g_move_history_matrix[power, src, dst]
        state.g_order_table[dst, _F_MOVE_HISTORY] = float(
            state.g_move_history_matrix[power_index, src, dst]
        )

        # If AMY and convoy chain depth at src ≠ 5 (not complete): clear dst score fields
        # DAT_00baedf0[src*0x1e] = _F_ORDER_ASGN holds convoy chain depth in this context
        if is_army and int(state.g_order_table[src, _F_ORDER_ASGN]) != 5:
            state.g_order_table[dst, 24] = 0.0  # DAT_00baee00[dst*0x1e]
            state.g_order_table[dst, 25] = 0.0  # DAT_00baee04[dst*0x78]

        register_convoy_fleet(state, power_index, dst)

        # AssignSupportOrder(this, power, src, dst, coast, NULL)
        assign_support_order(state, power_index, src, dst, coast, flag=0)

    def _build_order_sup_hld(supporter: int, supported: int) -> None:
        """Port of BuildOrder_SUP_HLD (Source/BuildOrder/BuildOrder_SUP_HLD.c).

        Signature: BuildOrder_SUP_HLD(this, power, supporter_prov, supported_prov)

        Writes _ORDER_SUP_HLD (=3) into g_order_table[supporter] with the
        supported province in _F_DEST_PROV (DAT_00baeda8 — decompile line 29).
        Inherits supporter's candidate score into g_convoy_chain_score /
        _F_CONVOY_LO/HI; clears convoy legs if the supporter is an army.
        Then registers the supporter as a convoy-fleet candidate, runs the
        ally-trust side-effect branch (C lines 39-53), and runs the
        chain-robustness adjacency scan tail (C lines 55-190).
        """
        # "Already inserted" early-return: supporter already has an order.
        if int(state.g_order_table[supporter, _F_ORDER_TYPE]) != 0:
            return

        # Core write (decompile lines 28-30):
        #   g_order_table[supporter, 0]  = 3           (SUP_HLD)
        #   g_order_table[supporter, 2]  = supported   (DAT_00baeda8)
        #   g_ProvinceBaseScore[supporter] = 1 → order_table[_F_INCOMING_MOVE]
        state.g_order_table[supporter, _F_ORDER_TYPE] = float(_ORDER_SUP_HLD)
        state.g_order_table[supporter, _F_DEST_PROV]  = float(supported)
        state.g_order_table[supporter, _F_DEST_COAST] = 0.0
        state.g_order_table[supporter, _F_INCOMING_MOVE] = 1.0

        # OrderedSet_FindOrInsert(this + power*0xc + 0x4000, supporter):
        # inherit supporter's final_score_set entry into convoy-chain scores.
        score_lo = float(state.final_score_set[power_index, supporter])
        state.g_convoy_chain_score[supporter]       = score_lo
        state.g_order_score_hi[supporter]           = 0.0
        state.g_order_table[supporter, _F_CONVOY_LO] = score_lo
        state.g_order_table[supporter, _F_CONVOY_HI] = 0.0

        # If supporter is AMY: clear [24]/[25] (DAT_00baee00/04 —  SUP_HLD lines 34-37)
        is_army = (state.unit_info.get(supporter, {}).get('type') == 'A')
        if is_army:
            state.g_order_table[supporter, 24] = 0.0
            state.g_order_table[supporter, 25] = 0.0

        # RegisterConvoyFleet(this, power, supporter)
        register_convoy_fleet(state, power_index, supporter)

        # Ally-trust side-effect (C lines 39-53): if the supported unit belongs
        # to a different power, set g_convoy_active_flag[supported] = 1 and
        # update g_support_trust_adj based on trust level.
        supported_power = state.unit_info.get(supported, {}).get('power', power_index)
        if supported_power != power_index:
            trust_lo = float(state.g_ally_trust_score[power_index, supported_power])
            trust_hi = int(state.g_ally_trust_score_hi[power_index, supported_power])
            if trust_lo == 0 and trust_hi == 0:
                state.g_support_trust_adj = 30      # DAT_00633f14 = 0x1e
            elif trust_hi < 1 and (trust_hi < 0 or trust_lo < 5):
                state.g_support_trust_adj = 10
            else:
                state.g_support_trust_adj = -10
            state.g_convoy_active_flag[supported] = 1

        # Chain-robustness adjacency tail (C lines 55-190).
        # Bumps supported's _F_INCOMING_MOVE when the chain is robust, or
        # supported's _F_SUP_CHAIN_CONFLICT when an enemy can cut it.
        _sup_chain_tail(supporter, supported, supported, _ORDER_SUP_HLD)

    def _sup_chain_tail(supporter: int, supported: int, accum_prov: int,
                        order_type: int = _ORDER_SUP_HLD) -> None:
        """Shared adjacency-scan tail for BuildOrder_SUP_HLD / SUP_MTO.

        Ported from Source/BuildOrder/BuildOrder_SUP_HLD.c L55-190 and
        Source/BuildOrder/BuildOrder_SUP_MTO.c L61-220.  Both functions run
        the same structural scan against the unit list, with accum_prov
        receiving the outcome bump (supported for HLD, target for MTO).

        Semantics from the C:
          1. Threat gate — g_threat_level[power, supporter].  If zero, skip
             the scan and bump _F_INCOMING_MOVE unconditionally (safe).
          2. Mismatch short-circuit — if threat != g_enemy_reach_score at the
             supporter, non-reach enemy pressure is present → chain broken
             (_F_SUP_CHAIN_CONFLICT).
          3. Unit scan — iterate all units gated by g_enemy_presence (primary)
             or g_established_ally_flag (secondary, DAT_0050bce8).  For each,
             filter adjacency by unit type (AdjacencyList_FilterByUnitType) and
             inspect:
               b_sup  — adj province == supporter
               b_tgt  — adj province == supported (HLD) / target (MTO)
               b_chain — sister-supporter: another own SC-province with
                 order_type (3 for HLD, 4 for MTO), dest == accum_prov,
                 and g_order_table[adj, 16] == 1.
             b_chain post-check: if b_chain and g_order_table[supporter, 16]
             != 1, it's discarded unless field 16 == 2 and b_sup and b_tgt
             (which skips the conflict check for that unit entirely).
             A conflicting unit (b_sup and not b_tgt and not b_chain) breaks
             the chain.
          4. Bump _F_INCOMING_MOVE (chain ok) or _F_SUP_CHAIN_CONFLICT on
             accum_prov.

        Fixed 2026-04-20 (M-MC-1): adjacency scan uses can_reach_by_type for
        coast-aware filtering, matching C's AdjacencyList_FilterByUnitType.
        Fixed 2026-05-01 (M-MC-2): threat gate now uses g_threat_level
        (DAT_005460e8) — was g_proximity_score (always 0, making the scan
        dead code).  Unit gate now uses g_enemy_presence + g_established_ally_flag
        (was g_enemy_reach_score + g_enemy_pressure_secondary).  b_chain now
        uses field 16 (_F_THREAT_TOTAL) and accum_prov instead of field 13 and
        supported; includes the field-16-on-supporter post-check.
        """
        # Threat gate (SUP_HLD L55-57; SUP_MTO L63-64).
        # C: DAT_005460e8 = g_threat_level, compared against g_EnemyReachScore.
        threat = int(state.g_threat_level[power_index, supporter])
        er = int(state.g_enemy_reach_score[power_index, supporter])
        if threat == 0:
            # No threat at all — chain is unconditionally safe.
            state.g_order_table[accum_prov, _F_INCOMING_MOVE] += 1.0
            return
        if threat != er:
            # Non-reach pressure present — chain broken immediately.
            state.g_order_table[accum_prov, _F_SUP_CHAIN_CONFLICT] += 1.0
            return

        # Adjacency scan — unit gate: g_enemy_presence (DAT_004f6ce8, primary)
        # or g_established_ally_flag (DAT_0050bce8, secondary fallback).
        chain_ok = True
        for this_prov, this_unit in state.unit_info.items():
            ep_flag = int(state.g_enemy_presence[power_index, this_prov]) == 1
            ea_flag = int(state.g_established_ally_flag[power_index, this_prov]) == 1
            if not (ep_flag or ea_flag):
                continue

            unit_type = this_unit.get('type', 'A')
            adjs = [p for p in state.adj_matrix.get(this_prov, [])
                    if state.can_reach_by_type(this_prov, p, unit_type)]
            b_sup = supporter in adjs
            b_tgt = supported in adjs  # supported == accum_prov for HLD, mover for MTO

            # Sister-supporter (b_chain): another own SC-province adjacent to
            # this unit carries the same type of support onto accum_prov with
            # g_order_table[adj, 16] == 1 (DAT_00baede0, _F_THREAT_TOTAL).
            b_chain = False
            for adj_prov in adjs:
                if adj_prov in (supporter, accum_prov):
                    continue
                if state.g_sc_ownership[power_index, adj_prov] != 1:
                    continue
                if int(state.g_order_table[adj_prov, _F_ORDER_TYPE]) != order_type:
                    continue
                if int(state.g_order_table[adj_prov, _F_DEST_PROV]) != accum_prov:
                    continue
                if int(state.g_order_table[adj_prov, _F_THREAT_TOTAL]) != 1:
                    continue
                b_chain = True
                break

            # Post-check: b_chain is only valid when supporter's own field 16 == 1.
            # If field 16 == 2 and b_sup and b_tgt: skip this unit entirely.
            if b_chain:
                sup_f16 = int(state.g_order_table[supporter, 16])
                if sup_f16 != 1:
                    if sup_f16 == 2 and b_sup and b_tgt:
                        continue  # skip conflict check for this unit
                    b_chain = False

            if b_sup and not b_tgt and not b_chain:
                chain_ok = False

        if chain_ok:
            state.g_order_table[accum_prov, _F_INCOMING_MOVE] += 1.0
        else:
            state.g_order_table[accum_prov, _F_SUP_CHAIN_CONFLICT] += 1.0

    def _build_order_sup_mto(supporter: int, mover: int, target: int) -> None:
        """Port of BuildOrder_SUP_MTO (Source/BuildOrder/BuildOrder_SUP_MTO.c).

        Signature: BuildOrder_SUP_MTO(this, power, supporter, mover, target)

        Writes _ORDER_SUP_MTO (=4) into g_order_table[supporter] — the mover's
        province in _F_SECONDARY (DAT_00baeda4, decompile L33), the target
        province in _F_DEST_PROV (DAT_00baeda8, decompile L34). Inherits the
        supporter's final_score_set entry into convoy-chain score fields and
        clears convoy legs if the supporter is an army.  Runs the ally-trust
        side-effect branch (C lines 45-59) and chain-robustness tail (C L61-220).

        Note: the C tail also sets g_proximity_score[target.power, mover] += 2
        when the chain is robust AND an enemy at the target exerts exactly 1
        threat unit on the mover (bVar3 condition, C L133-136).  That write is
        deferred; the chain_ok / conflict determination is fully ported.
        """
        if int(state.g_order_table[supporter, _F_ORDER_TYPE]) != 0:
            return

        state.g_order_table[supporter, _F_ORDER_TYPE] = float(_ORDER_SUP_MTO)
        state.g_order_table[supporter, _F_SECONDARY] = float(mover)
        state.g_order_table[supporter, _F_DEST_PROV] = float(target)
        state.g_order_table[supporter, _F_INCOMING_MOVE] = 1.0

        score_lo = float(state.final_score_set[power_index, supporter])
        state.g_convoy_chain_score[supporter]         = score_lo
        state.g_order_score_hi[supporter]             = 0.0
        state.g_order_table[supporter, _F_CONVOY_LO] = score_lo
        state.g_order_table[supporter, _F_CONVOY_HI] = 0.0

        is_army = (state.unit_info.get(supporter, {}).get('type') == 'A')
        if is_army:
            state.g_order_table[supporter, 24] = 0.0
            state.g_order_table[supporter, 25] = 0.0

        register_convoy_fleet(state, power_index, supporter)

        # Ally-trust side-effect (C lines 45-59): if the mover unit belongs
        # to a different power, set g_convoy_active_flag[target] = 1.
        mover_power = state.unit_info.get(mover, {}).get('power', power_index)
        if mover_power != power_index:
            trust_lo = float(state.g_ally_trust_score[power_index, mover_power])
            trust_hi = int(state.g_ally_trust_score_hi[power_index, mover_power])
            if trust_lo == 0 and trust_hi == 0:
                state.g_support_trust_adj = 30      # DAT_00633f14 = 0x1e
            elif trust_hi < 1 and (trust_hi < 0 or trust_lo < 5):
                state.g_support_trust_adj = 10
            else:
                state.g_support_trust_adj = -10
            state.g_convoy_active_flag[target] = 1

        # Chain-robustness adjacency tail (C L63-220).  accum_prov = target.
        # `supported` arg = mover: the scan checks adjacency to both the
        # supporter and the mover (the unit being supported into the target).
        _sup_chain_tail(supporter, mover, target, _ORDER_SUP_MTO)

    def _prov_from_unit_str(unit_str: str) -> int:
        """Parse 'A PAR' / 'F LON/NCS' → prov_id; -1 if unknown.

        DAIDE unit strings are "<type> <province>[/<coast>]".  For MC trial
        purposes we strip the coast — the adjacency matrix is coast-agnostic
        so integer prov_id suffices.
        """
        if not unit_str:
            return -1
        parts = unit_str.split()
        if len(parts) < 2:
            return -1
        prov_name = parts[1].split('/')[0]
        return int(state.prov_to_id.get(prov_name, -1))

    def _dispatch_to_order_table(order_seq: dict) -> None:
        """Project a press-agreed order_seq dict into g_order_table.

        Mirrors the side-effects of the C DispatchSingleOrder switch
        (ProcessTurn.c Phase 1c), which calls BuildOrder_{HLD,MTO,CTO,CVY,
        SUP_HLD,SUP_MTO} on the per-power order sets.  The Python pipeline
        previously used dispatch.dispatch_single_order which only formats
        DAIDE output strings — so press-agreed orders never made it into
        the MC trial state.  This helper closes that gap by calling the
        same nested _build_order_* helpers Phase 1d/1f.5/1f.7 already use.

        Silent no-op when:
          - unit province can't be parsed
          - the unit at that province doesn't belong to power_index
          - the supporter/mover/target referenced in a SUP doesn't resolve
          - order_type is HLD and the slot already carries an explicit
            non-HLD order (don't clobber move/support commitments)
        """
        otype = (order_seq.get('type') or '').upper()
        src = _prov_from_unit_str(order_seq.get('unit', ''))
        if src < 0:
            return
        # Sanity: the order must describe a unit this power actually owns.
        unit = state.unit_info.get(src)
        if unit is None or unit.get('power') != power_index:
            return

        if otype == 'HLD':
            # Only seed HLD if slot is still empty — never overwrite an
            # already-built MTO/SUP/CTO/CVY.  (Phase 1b' has usually
            # pre-seeded HLD anyway; this is idempotent in that case.)
            if int(state.g_order_table[src, _F_ORDER_TYPE]) == 0:
                state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_HLD)
            return

        if otype == 'MTO':
            dst = int(state.prov_to_id.get(order_seq.get('target', ''), -1))
            if dst < 0:
                return
            # Upgrade default HLD to MTO — clear first so _build_order_mto's
            # "already inserted" guard (order_type != 0) doesn't short-circuit.
            if int(state.g_order_table[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                state.g_order_table[src, _F_ORDER_TYPE] = 0.0
            _build_order_mto(src, dst, 0)
            return

        if otype == 'SUP':
            supported = _prov_from_unit_str(order_seq.get('target_unit', ''))
            if supported < 0:
                return
            target_dest = order_seq.get('target_dest')
            if target_dest:
                # SUP_MTO form: S <supported> MTO <target_dest>
                tgt = int(state.prov_to_id.get(target_dest, -1))
                if tgt < 0:
                    return
                src_type  = unit.get('type', 'A')
                src_coast = unit.get('coast', '')
                if not state.can_reach_by_type(src, tgt, src_type, src_coast):
                    return
                if int(state.g_order_table[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                    state.g_order_table[src, _F_ORDER_TYPE] = 0.0
                _build_order_sup_mto(src, supported, tgt)
            else:
                # SUP_HLD form: S <supported>
                if int(state.g_order_table[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                    state.g_order_table[src, _F_ORDER_TYPE] = 0.0
                _build_order_sup_hld(src, supported)
            return

        if otype == 'CTO':
            dst = int(state.prov_to_id.get(order_seq.get('target_dest', ''), -1))
            if dst < 0:
                return
            # build_convoy_orders handles the full CTO + CVY chain, but it
            # requires state.g_convoy_route[src][dst] to be populated for
            # this specific destination (route-planning output, per-dst
            # shape from Fix #7).  If unavailable, fall back to a direct
            # CTO write without the fleet CVY chain — mirrors the C
            # fallback when no valid convoy route is registered.
            from ..moves.convoy import _get_convoy_route
            _fc, _ = _get_convoy_route(state, src, dst)
            if _fc > 0:
                build_convoy_orders(state, power_index, src, dst)
            else:
                if int(state.g_order_table[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                    state.g_order_table[src, _F_ORDER_TYPE] = 0.0
                state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_CTO)
                state.g_order_table[src, _F_DEST_PROV]  = float(dst)
            return

        if otype == 'CVY':
            # Fleet convoying an army: S = fleet, target_unit = army being
            # convoyed, target_dest = army's destination.
            army_prov = _prov_from_unit_str(order_seq.get('target_unit', ''))
            dst = int(state.prov_to_id.get(order_seq.get('target_dest', ''), -1))
            if army_prov < 0 or dst < 0:
                return
            if int(state.g_order_table[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                state.g_order_table[src, _F_ORDER_TYPE] = 0.0
            state.g_order_table[src, _F_ORDER_TYPE]  = float(_ORDER_CVY)
            # C DispatchSingleOrder.c:213 — col 1 (_F_SECONDARY) carries the
            # convoyed army's province, not col 16.
            state.g_order_table[src, _F_SECONDARY]   = float(army_prov)
            state.g_order_table[src, _F_DEST_PROV]   = float(dst)
            return

    def _insert_order_candidate(candidate_list: list, score: int, entry: dict) -> dict:
        """InsertOrderCandidate — BST sorted insert keyed on score (ascending).

        Mirrors the C++ `InsertOrderCandidate` / `FUN_004153b0` pair:
          - Descends the BST comparing node[3] < *param_2 (go left) until sentinel.
          - Allocates a new node (or returns existing) and links it.
          - Returns {container, node, is_new=1} via param_1; here returns the entry dict.

        `FUN_00410480` (`std_Tree_Buynode` for InsertOrderCandidate tree) is absorbed
        here.  In C++ it called `operator_new(0x3c)` (60-byte node) then
        `FUN_0040fa10(node, head, parent, head, data_ptr, color=0)`:

          Confirmed node layout (60 bytes / 0x3c):
            [0x00] _Left   = head   (param_1)
            [0x04] _Parent = parent (param_2)
            [0x08] _Right  = head   (param_3)
            [0x0c..0x27]  7-int payload — data_ptr[0..6] (slots 3–9)
                          data_ptr[0] = score (BST key)
            [0x28..0x37]  16-byte TokenSeq — FUN_00465f60(node+0x28, data_ptr+7)
                          (slots 10–13; data_ptr[7] = buf ptr, data_ptr[8] = count)
            [0x38]        color byte = param_6 = 0 (RED in MSVC RB-tree)
            [0x39]        0 (isNil = false)

        In Python this collapses to `dict(entry)` (payload copy) +
        `candidate_list.insert(pos, ...)` (linking).  No Albert logic — pure STL
        boilerplate; no separate Python function is needed.

        Python representation: candidate_list is a list of (score, entry_dict) tuples
        maintained in ascending score order via bisect.  Duplicate keys are allowed
        (same score → inserted to the right of existing equal-key entries).
        """
        import bisect
        keys = [s for s, _ in candidate_list]
        pos = bisect.bisect_right(keys, score)
        new_entry = dict(entry)
        new_entry['score'] = score
        candidate_list.insert(pos, (score, new_entry))
        return new_entry

    # ── lazy-init per-trial arrays not yet on state ───────────────────────────
    if not hasattr(state, 'g_unit_presence'):
        state.g_unit_presence = np.full((num_powers, num_provinces), -1, dtype=np.int32)
    if not hasattr(state, 'g_convoy_active_flag'):
        state.g_convoy_active_flag = np.zeros(num_provinces, dtype=np.int32)
    if not hasattr(state, 'g_convoy_dst_list'):
        state.g_convoy_dst_list = []
    if not hasattr(state, 'g_trial_list2'):
        state.g_trial_list2 = []
    if not hasattr(state, 'g_trial_map'):
        state.g_trial_map = {}
    if not hasattr(state, 'g_support_trust_adj'):
        state.g_support_trust_adj = 0
    if not hasattr(state, 'g_ring_convoy_score'):
        state.g_ring_convoy_score = 0
    if not hasattr(state, 'g_other_score'):
        state.g_other_score = 0
    if not hasattr(state, 'g_ring_convoy_enabled'):
        state.g_ring_convoy_enabled = 0
    if not hasattr(state, 'g_ring_prov_a'):
        state.g_ring_prov_a = -1
    if not hasattr(state, 'g_ring_prov_b'):
        state.g_ring_prov_b = -1
    if not hasattr(state, 'g_ring_prov_c'):
        state.g_ring_prov_c = -1
    if not hasattr(state, 'g_ring_coast_a'):
        state.g_ring_coast_a = 0
    if not hasattr(state, 'g_ring_coast_b'):
        state.g_ring_coast_b = 0
    if not hasattr(state, 'g_ring_coast_c'):
        state.g_ring_coast_c = 0
    if not hasattr(state, 'g_alliance_orders'):
        state.g_alliance_orders = {}          # {power: [order_seq, ...]}
    if not hasattr(state, 'g_general_orders'):
        state.g_general_orders = {}           # {power: [order_seq, ...]}
    # NB: g_alliance_orders_present / g_general_orders_present do NOT exist as
    # separate globals in the C binary.  ScoreOrderCandidates.c reads them as
    # `&DAT_00bb6d00 + p*0xc`, which is the `_Mysize` field (offset +8) of the
    # std::set<order_record> at slot p inside g_general_orders (each slot is
    # 0xc bytes: comparator/_Myhead/_Mysize).  Same for the alliance variant.
    # We model the "is populated" check as `len(state.g_general_orders.get(p,
    # ())) > 0` directly — no parallel array — to avoid the parallel-state
    # rot that bit us before (always-zero array → 1c never dispatched even
    # when orders existed).
    if not hasattr(state, 'g_order_history'):
        state.g_order_history = {}            # {power: [{province, ...}, ...]}
    if not hasattr(state, 'g_ally_order_history'):
        state.g_ally_order_history = {}        # {power: [{province, ...}, ...]}
    if not hasattr(state, 'g_proposal_history_map'):
        # DAT_00baed98 — proposal history map; mirrors state.g_deal_list
        state.g_proposal_history_map = getattr(state, 'g_deal_list', [])
    if not hasattr(state, 'g_stab_mode'):
        state.g_stab_mode = 0                 # DAT_00baed69

    # ── Phase 0 — Setup ───────────────────────────────────────────────────────

    # Reset per-power alt-order map (local_6e4 in C is a local BST, fresh each call).
    state.g_alt_order_list[power_index] = {}

    # 0a. Build reachable-province set (reachable_provinces) for power_index.
    #     Mirrors the StdMap_FindOrInsert(&DAT_00bb7124, ...) scan in decompile.
    reachable_provinces = {}  # {prov: True}; DAT_00bb7124
    if power_index == own_power:
        # own power: scan ally-shared order history (DAT_00bb7028[power_index])
        for entry in state.g_ally_order_history.get(power_index, []):
            prov = entry.get('province', -1)
            if prov >= 0:
                reachable_provinces[prov] = True
    else:
        # ally: only scan when relation > 9 OR trust (hi > 0, or hi >= 0 and lo > 5)
        trust_lo = int(state.g_ally_trust_score[own_power, power_index])
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power_index])
        # DAT_00634e90 = g_relation_score.  This used to read
        # g_relation_history, a duplicate binding nothing wrote (always 0),
        # so the `rel > 9` arm of the gate could never fire.
        rel      = int(state.g_relation_score[own_power, power_index])
        if rel > 9 or (trust_hi > 0) or (trust_hi >= 0 and trust_lo > 5):
            for entry in state.g_ally_order_history.get(power_index, []):
                prov = entry.get('province', -1)
                if prov >= 0:
                    reachable_provinces[prov] = True

    # 0b. Per-power order-history snapshot (auStack_138[p] in decompile).
    #     Mirrors the DAT_00bb6f2c[p] copy loop.
    per_power_order_sets: list = [
        dict(state.g_order_history.get(p, {})) for p in range(num_powers)
    ]

    # 0c. Ally flag scan: local_76f = 1 if any g_xdo_press_sent[power_index, p] == 1.
    has_ally: bool = bool(
        np.any(state.g_xdo_press_sent[power_index] == 1)
    )

    # 0d. Random start offset for the cyclical power-expand pass.
    rand_power_start: int = random.randrange(num_powers)
    rand_power_cursor: int = rand_power_start

    # ── Phase 1 — Monte Carlo trial loop ─────────────────────────────────────
    # Mirror of the do { ... } while (iStack_684 < num_trials) block.

    for _trial in range(num_trials):

        # 1a. Per-trial state reset ────────────────────────────────────────────
        state.g_support_trust_adj   = 0     # DAT_00633f14
        state.g_ring_convoy_score   = 0     # DAT_0062c57c
        state.g_early_game_bonus    = 0     # DAT_0062be94 (g_EarlyGameAdjScore)
        state.g_other_score        = 0     # DAT_0062b7ac

        _reset_per_trial_state()           # FUN_00460be0

        # Clear per-trial lists (DAT_00bb65a4 / DAT_00bbf648 / DAT_00bb6e04).
        state.g_convoy_dst_list.clear()
        state.g_trial_list2.clear()
        state.g_trial_map.clear()
        # C:510-522 clears the dst→src move map itself at the top of every
        # trial — the tree-destroy walk followed by resetting the header's
        # _Left/_Parent/_Right to self is MSVC's std::map::clear().  Only
        # g_convoy_dst_list (a different container) was being cleared here, so
        # the map carried moves across trials: in trial 2+ a unit could find
        # its own stale entry and support its own move, which is an illegal
        # order.  Both bindings stand for parts of the same C state.
        state.g_convoy_dst_to_src.clear()
        # Same omission for the convoy-rescore map (C `&DAT_00bb6e00`, bound as
        # g_sub_order_map): C:536-547 clears it per trial with the same
        # tree-destroy + reset-header sequence.  Step 1's source-province dedup
        # and monte_carlo/evaluation.py:517 both read it, so a map that only
        # ever grew let trial 2+ see trial 1's memberships.
        state.g_sub_order_map.clear()

        # Reset per-province order-table fields.
        # Mirrors the loop over 0..numProvinces zeroing DAT_00baedac fields.
        state.g_order_table[:num_provinces, :] = 0.0
        state.g_order_table[:num_provinces, _F_DEST_COAST] = -1.0   # 0xffffffff
        # g_SupportScoreLo/Hi (fields 18/19) use -1.0 as "unset" sentinel
        # to match C's (lo & hi) == 0xffffffff AssignSupportOrder check.
        # Fixed 2026-04-14 — was 0.0, which conflated "zero score" with "unset".
        state.g_order_table[:num_provinces, 18] = -1.0
        state.g_order_table[:num_provinces, 19] = -1.0
        # H3 verified: g_convoy_source_prov IS g_SupportAssignmentMap — C uses a
        # single array at one address for both support assignment and convoy
        # source tracking.  ProcessTurn.c:580 resets it to 0xffffffff each
        # trial, then support and convoy dispatch write sequentially (no conflict).
        state.g_convoy_source_prov[:num_provinces]  = -1.0  # g_SupportAssignmentMap sentinel (0xffffffff)
        state.g_convoy_active_flag[:num_provinces]  = 0
        state.g_province_score_trial[:num_provinces] = 0
        if hasattr(state, 'g_convoy_source_score'):
            state.g_convoy_source_score[:num_provinces] = 0.0
        state.g_army_adj_count[:num_provinces]      = 0
        state.g_convoy_fleet_registered.clear()
        # DAT_00bbf644 — per-trial ScoreSupportOpp map (src_prov → dest_prov).
        state.g_support_opp_map: dict = {}

        # Reset unit-presence matrix (g_unit_presence[power*0x100+prov] = -1).
        state.g_unit_presence[:, :num_provinces] = -1

        # 1b. Unit list scan ───────────────────────────────────────────────────
        # Mirrors: for each unit in this+8+0x2450 { g_unit_presence[...] = 0;
        #           if own AMY: g_army_adj_count[adj]++ }
        for prov, unit in state.unit_info.items():
            p_u  = unit['power']
            utyp = unit.get('type', '')
            state.g_unit_presence[p_u, prov] = 0

            if p_u == power_index and utyp in ('A', 'AMY'):
                for adj in state.get_unit_adjacencies(prov):
                    state.g_army_adj_count[adj] += 1

        # 1b'. Default-HOLD seed — MOVED to after evaluate_order_proposal ────
        # H2 fix: In C, units without orders remain at order_type==0 and are
        # skipped by EvaluateOrderProposal (which checks order_type != 0).
        # Pre-seeding HLD before dispatch made all own units enter the HLD
        # branch of Step 3, inflating heat scores for units that C would skip.
        #
        # The HLD seed is now applied AFTER evaluate_order_proposal (see
        # "1b'-post" below) so that evaluation matches C's skip-zero behavior,
        # while still ensuring every unit has an order for submission.

        # 1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP) ─────────
        # First pass: alliance orders (DAT_00bb65f8[power*0xc]) — own or trusted ally.
        # Now writes into g_order_table via _dispatch_to_order_table (was
        # previously calling dispatch.dispatch_single_order, which only
        # formats DAIDE strings and so left g_order_table untouched —
        # meaning press-agreed orders never entered MC trials).
        dispatch_first_pass = False
        if power_index == own_power:
            dispatch_first_pass = True
        else:
            trust_lo2 = int(state.g_ally_trust_score[own_power, power_index])
            trust_hi2 = int(state.g_ally_trust_score_hi[own_power, power_index])
            if trust_hi2 > 0 or (trust_hi2 >= 0 and trust_lo2 > 2):
                dispatch_first_pass = True

        # Priority mirrors ProcessTurn's loop order: HLD → MTO → CTO → CVY → SUP.
        # SUP is last because it can depend on the mover's MTO landing first.
        _DISPATCH_PRIORITY = ['HLD', 'MTO', 'CTO', 'CVY', 'SUP']

        if dispatch_first_pass and len(state.g_alliance_orders.get(power_index, ())) > 0:
            for wanted_type in _DISPATCH_PRIORITY:
                for order_seq in state.g_alliance_orders.get(power_index, []):
                    if (order_seq.get('type') or '').upper() == wanted_type:
                        _dispatch_to_order_table(order_seq)

        # Second pass: general orders (DAT_00bb6cf8[power*0xc]) — unconditional.
        if len(state.g_general_orders.get(power_index, ())) > 0:
            for wanted_type in _DISPATCH_PRIORITY:
                for order_seq in state.g_general_orders.get(power_index, []):
                    if (order_seq.get('type') or '').upper() == wanted_type:
                        _dispatch_to_order_table(order_seq)

        # HOLD-DBG: after Phase 1c — log what was dispatched for own-power units.
        # Fires once per turn (trial 0 only) to trace why units hold.
        if _trial == 0 and power_index == own_power:
            _id2n = getattr(state, '_id_to_prov', {})
            _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
            _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
            _after1c = {
                _id2n.get(p, str(p)): int(state.g_order_table[p, _F_ORDER_TYPE])
                for p, u in state.unit_info.items()
                if u.get('power') == power_index
            }
            _gen_cnt = len(state.g_general_orders.get(power_index, []))
            _ali_cnt = len(state.g_alliance_orders.get(power_index, []))
            logger.info(
                "HOLD_DBG[%s] trial=0 after Phase1c: "
                "gen_orders=%d ali_orders=%d  unit_ot_after_dispatch=%s",
                _pname, _gen_cnt, _ali_cnt, _after1c,
            )

        # 1d. Ring-convoy check (DAT_00baed5c == 1) ───────────────────────────
        if state.g_ring_convoy_enabled == 1:
            ring_broken = False
            pA, pB, pC = state.g_ring_prov_a, state.g_ring_prov_b, state.g_ring_prov_c
            if (int(state.g_order_table[pA, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_order_table[pA, _F_DEST_PROV]) != pB):
                ring_broken = True
            if (int(state.g_order_table[pB, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_order_table[pB, _F_DEST_PROV]) != pC):
                ring_broken = True
            if (int(state.g_order_table[pC, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_order_table[pC, _F_DEST_PROV]) != pA):
                ring_broken = True

            # Also check whether unit is absent from ring province (own-power gate).
            if power_index == own_power:
                # Mirroring: FUN_00402140 checks whether ring prov is in own order set.
                ring_in_set = (pA in per_power_order_sets[power_index] and
                               pB in per_power_order_sets[power_index] and
                               pC in per_power_order_sets[power_index])
                if not ring_in_set:
                    ring_broken = True
            # If ring intact: build the three MTO orders.
            if not ring_broken:
                _build_order_mto(pA, pB, state.g_ring_coast_a)
                _build_order_mto(pB, pC, state.g_ring_coast_b)
                _build_order_mto(pC, pA, state.g_ring_coast_c)

        # 1e. Random exploit pass ─────────────────────────────────────────────
        # C (decompile 816-847), both arms sharing ONE roll:
        #   r = (rand() / 0x17) % 100
        #   if (r < 0x0f)  { if (has_ally) → exploit }          # 15 %
        #   fallback: if (r < 0x41 && g_other_power_lead_flag == 1
        #                 && near_end > 6.0)  → trust check → exploit
        # Corrected 2026-08-12: the fallback threshold is 0x41 = 65, not 35,
        # and its gate is g_other_power_lead_flag (DAT_00baed69) rather than a
        # has_ally / albert-power test.  The has_ally requirement belongs to
        # the FIRST arm only.
        r_exploit = random.randrange(100)
        do_exploit = r_exploit < 15 and has_ally
        if (not do_exploit
                and r_exploit < 65
                and int(getattr(state, 'g_other_power_lead_flag', 0)) == 1
                and state.g_near_end_game_factor > 6.0):
            do_exploit = True

        if do_exploit:
            # Advance cyclical power cursor to next allied power.
            rand_power_cursor = (rand_power_cursor + 1) % num_powers
            # Find an allied power.
            exploit_power = rand_power_cursor
            for _ in range(num_powers):
                if state.g_xdo_press_sent[power_index, exploit_power]:
                    break
                exploit_power = (exploit_power + 1) % num_powers

            # Determine secondary target for stab scoring (65% × late-game).
            secondary_target = -1
            r2 = random.randrange(100)
            if (r2 < 65 and state.g_stab_mode == 1
                    and state.g_near_end_game_factor > 6.0):
                trust_lo3 = int(state.g_ally_trust_score[own_power, exploit_power])
                trust_hi3 = int(state.g_ally_trust_score_hi[own_power, exploit_power])
                if trust_hi3 > 0 or (trust_hi3 >= 0 and trust_lo3 != 0):
                    secondary_target = (exploit_power + 1) % num_powers
                    for _ in range(num_powers):
                        st_lo = int(state.g_ally_trust_score[own_power, secondary_target])
                        st_hi = int(state.g_ally_trust_score_hi[own_power, secondary_target])
                        if st_lo == 0 and st_hi == 0:
                            secondary_target = -1
                            break
                        if secondary_target == exploit_power:
                            secondary_target = -1
                            break
                        secondary_target = (secondary_target + 1) % num_powers

            # Build exploit candidate list (local_6e0 in C — temporary scored list)
            # and persist to g_alt_order_list (local_6e4 — per-power BST keyed on
            # source province, read by EvaluateOrderProposal for the 750 penalty check).
            exploit_candidates: list = []   # [(score, entry_dict), ...] ascending
            alt_map = state.g_alt_order_list[power_index]  # local alias for population

            # Scan proposal history (DAT_00baed98 / g_deal_list) for matching entries.
            for rec in list(state.g_proposal_history_map):
                if rec.get('power') != power_index:
                    continue
                rec_prov = rec.get('province', -1)
                # Check reachable / alt order set match (mirrors GameBoard_GetPowerRec).
                if rec_prov not in per_power_order_sets[power_index]:
                    continue
                score = rec.get('score', 0)
                entry = {
                    'unit_prov':    rec_prov,
                    'target_power': rec.get('target_power', -1),
                    'via_prov':     rec.get('src_prov', -1),
                    'dst_prov':     rec.get('dst_prov', -1),
                }
                # Primary insert: auStack_204 call site (C line 939).
                # Also writes to g_alt_order_list (local_6e4, C line 939);
                # dedup by source province mirrors the FUN_00402140 pre-check (line 910).
                if rec.get('target_power') == exploit_power:
                    _insert_order_candidate(exploit_candidates, score, entry)
                    if rec_prov not in alt_map:
                        alt_map[rec_prov] = rec.get('dst_prov', -1)
                # Secondary insert: auStack_150 call site (C line 966).
                # Condition: target_power == secondary_target AND via_prov == dst_prov.
                if secondary_target >= 0 and rec.get('target_power') == secondary_target:
                    if rec.get('src_prov') == rec.get('dst_prov'):
                        _insert_order_candidate(exploit_candidates, score, entry)
                        if rec_prov not in alt_map:
                            alt_map[rec_prov] = rec.get('dst_prov', -1)

            # Count cap computed AFTER insertions (mirrors decompile: lines 81–102
            # overwrite ppiStack_7bc with the cap after the insertion loop).
            r3 = random.randrange(100)
            if secondary_target < 0:
                # C: if (iVar20 < 0x41) cap=1; else cap = (0x54 < iVar20) + 2
                # → [0,64]→1, [65,84]→2, [85,99]→3
                if r3 < 65:
                    count_cap = 1
                else:
                    count_cap = 2 + int(r3 > 84)
            else:
                if r3 < 40:
                    count_cap = 1
                elif r3 < 60:
                    count_cap = 2
                elif r3 < 80:
                    count_cap = 3
                else:
                    count_cap = 4 + int(r3 > 89)

            # Consumption loop (decompile lines 103–246):
            # Iterate local_6e4 ascending by score; 60% rand gate + total count cap.
            # Full trust/convoy conditions are implemented below:
            #   - relay province reads via g_ally_designation_b/c (≈ g_ConvoyProv1/2)
            #     and g_ally_designation_a (≈ g_ConvoyProv3 / ally guard)
            #   - three-probe trust accumulation (relay3, relay1, ally_a last-wins)
            #   - early-game mutual-trust path vs. not-early-game low-trust gate
            #   - reachability via reachable_provinces (≈ GameBoard_GetPowerRec)
            #   - convoy route dispatch via _get_convoy_route / build_convoy_orders
            consumed = 0
            for _score, cand in exploit_candidates:
                if random.randrange(100) >= 60:     # < 0x3c = 60% gate
                    continue
                if consumed >= count_cap:
                    break
                unit_prov = cand['unit_prov']
                if int(state.g_unit_presence[power_index, unit_prov]) == -1:
                    continue

                # Phase-1e: convoy trust/route check
                # Ported from ProcessTurn.c lines 2463–2751.
                army_src = unit_prov
                dst      = cand['dst_prov']
                coast    = 0  # coast not carried in the candidate dict

                # Self-move: ordered to own province → hold and stop candidate scan.
                if dst == army_src:
                    state.g_order_table[army_src, _F_ORDER_TYPE] = float(_ORDER_HLD)
                    consumed += 1
                    break

                # Register dst in convoy destination tracking.
                if dst not in state.g_convoy_dst_list:
                    state.g_convoy_dst_list.append(dst)

                # Read relay province tables (interleaved lo/hi int32 pairs in C).
                # C: DAT_004d3610[prov*2] = lo, DAT_004d3614[prov*2] = hi.
                # Python: _a/_b/_c = lo arrays, _a_hi/_b_hi/_c_hi = hi guard arrays.
                #   relay3 ← g_ally_designation_c / _c_hi  (DAT_004d3610/14)
                #   relay1 ← g_ally_designation_b / _b_hi  (DAT_004d2610/14)
                #   ally_a ← g_ally_designation_a / _a_hi  (DAT_004d2e10/14)
                #
                # Fix 2026-04-21 (MC-2): Previously derived hi from sign of lo
                # (single int64 encoding). Now reads separate _hi arrays matching
                # C's interleaved int32 pair layout.
                relay3_lo = int(state.g_ally_designation_c[dst])
                relay3_hi = int(state.g_ally_designation_c_hi[dst])
                relay1_lo = int(state.g_ally_designation_b[dst])
                relay1_hi = int(state.g_ally_designation_b_hi[dst])
                ally_a_lo = int(state.g_ally_designation_a[dst])
                ally_a_hi = int(state.g_ally_designation_a_hi[dst])

                # Three-probe trust accumulation (last-wins; ally_a only if still zero).
                trust_lo = trust_hi = 0
                probes = [
                    (relay3_lo, relay3_hi, False),
                    (relay1_lo, relay1_hi, False),
                    (ally_a_lo, ally_a_hi, True),
                ]
                for probe_lo, guard_hi, is_ally_a in probes:
                    if guard_hi < 0:
                        continue
                    if is_ally_a and (trust_lo != 0 or trust_hi != 0):
                        continue
                    if 0 <= probe_lo < num_powers:
                        # g_ally_history_count threshold: `> 9` = trusted ally.
                        # Fixed 2026-04-14 — DAT_00634e90 is g_relation_score
                        # (formerly labeled g_ally_history_count); state.py has
                        # both names but only g_relation_score is populated.
                        history = int(state.g_relation_score[power_index, probe_lo])
                        if history > 9 or power_index == own_power:
                            trust_lo = float(state.g_ally_trust_score[power_index, probe_lo])
                            trust_hi = int(state.g_ally_trust_score_hi[power_index, probe_lo])

                # C ProcessTurn.c:2543-2546: if dst IS found in the map, override trust to
                # (lo=3, hi=0), which fails the gate below → move rejected (ally claimed it).
                # Not-found means no ally claimed it; keep probe trust and potentially accept.
                if dst in reachable_provinces:
                    trust_lo, trust_hi = 3, 0

                # Trust gate.
                # not_early_game: DAT_00baed68 (g_press_flag) != 1  OR  g_near_end_game_factor >= 2.0
                not_early_game = (state.g_press_flag != 1) or (state.g_near_end_game_factor >= 2.0)
                # C:2549 — low trust (no ally claim on territory) → accept path.
                low_trust = trust_hi < 1 and (trust_hi < 0 or trust_lo == 0)
                if not_early_game or relay1_hi < 0:
                    reaches_accept = low_trust
                else:
                    # Early-game mutual-trust path.
                    mutual_trust = False
                    if 0 <= relay1_lo < num_powers:
                        fwd_hi = int(state.g_ally_trust_score_hi[power_index, relay1_lo])
                        fwd_lo = float(state.g_ally_trust_score[power_index, relay1_lo])
                        if fwd_hi >= 0 and (fwd_hi > 0 or fwd_lo > 1):
                            rev_hi = int(state.g_ally_trust_score_hi[relay1_lo, power_index])
                            rev_lo = float(state.g_ally_trust_score[relay1_lo, power_index])
                            if rev_hi >= 0 and (rev_hi > 0 or rev_lo > 1):
                                mutual_trust = True
                    # No mutual trust → C skips the gate entirely and accepts.
                    reaches_accept = low_trust if mutual_trust else True

                # C:2574 — g_ConvoyActiveFlag[dst] > 0 REJECTS the candidate
                # (the province is already receiving one of our support orders).
                accepted = reaches_accept and int(state.g_convoy_active_flag[dst]) <= 0

                if accepted and int(state.g_sc_ownership[power_index, dst]) == 1:
                    # C:2579-2694 own-SC block — NOT yet ported (findings 2/3 in
                    # completed_rewrite.md).  C emits SUP_HLD or scores a convoy
                    # fleet here and suppresses the move; Python reproduces only
                    # the ScoreConvoyFleet side effect and suppresses the move.
                    score_convoy_fleet(state, dst, 0x7ffb)
                    accepted = False

                if not accepted:
                    continue  # ClearConvoyState + RemoveOrderCandidate

                # Accept → always a plain MTO.  C:2715 picks BuildOrder_MTO vs
                # BuildConvoyOrders on `this + dst*0x14 + 0x214` (the convoy
                # leg count), and that field can only be nonzero if the
                # convoy-chain BFS at C:1674-1940 ran for this unit.  That BFS
                # sits behind C:1669-1671, a `std::string::compare` of the
                # unit's province token against a hard-coded 3-character
                # literal — so it fires for at most one province per game.
                # Everywhere else the leg count is 0 (written ungated at
                # C:1628/1655 for every adjacency) or -1, so C:2715 always
                # takes the MTO arm.  Consistently, BuildConvoyOrders has
                # exactly one caller in the whole C source (ProcessTurn.c:2747)
                # and it is behind that same dead branch.
                #
                # The previous `water_provinces` proxy for the leg count was
                # true for nearly every coastal province, so this path emitted
                # convoys where C emits none.  See finding (7) in
                # completed_rewrite.md for the gate analysis and its caveat.
                _build_order_mto(army_src, dst, coast)
                consumed += 1

        # 1f. Support assignment ───────────────────────────────────────────────
        # Per-province threat aggregates (C lines 1440-1492).  C walks every
        # other power under a three-clause hostility gate and stores TWO
        # aggregates per province: the PEAK gated reach in col 15
        # (DAT_00baeddc = g_support_demand) at C:1488, and the SUM of gated
        # reaches in col 16 (DAT_00baede0 = _F_THREAT_TOTAL) at C:1487.
        #
        # Both are substituted from ScoreProvinces' output rather than
        # recomputed from g_ThreatScore here: scoring.py:548-576 accumulates
        # `reach` under a hostile_gate that is clause-for-clause identical to
        # C:1467-1471 — including the per-province is_ally_desig term — taking
        # the max into g_threat_level and the sum into g_enemy_reach_score.
        # So g_threat_level is C's peak and g_enemy_reach_score is C's total.
        #
        # C recomputes this inside the per-unit loop; it is loop-invariant
        # (nothing in the loop touches trust, relation or reach), so hoisting
        # it out is equivalent.  -1 sentinel means "no threat scored" → 0.
        #
        # Col 16 was previously never written, leaving the `== 1` / `== 2`
        # readers in moves/support.py, monte_carlo/evaluation.py and
        # _sup_chain_tail with nothing meaningful to read.
        state.g_support_demand[:num_provinces] = np.maximum(
            0, state.g_threat_level[power_index, :num_provinces]
        )
        state.g_order_table[:num_provinces, _F_THREAT_TOTAL] = np.maximum(
            0, state.g_enemy_reach_score[power_index, :num_provinces]
        )

        # Find own unordered SC provinces; call AssignHoldSupports.
        # Mirrors: for each prov where g_sc_ownership[power_index,prov]==1 AND
        #          g_order_table[prov,0]==0 → add to support_candidates.
        support_candidates: dict = {}
        for prov in range(num_provinces):
            if (state.g_sc_ownership[power_index, prov] == 1 and
                    int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0):
                support_candidates[prov] = True
        if _trial == 0 and power_index == 3 and _dbg_log.isEnabledFor(logging.DEBUG):
            id2n = getattr(state, '_id_to_prov', {})
            _sc_provs = [(id2n.get(p, str(p)), int(state.g_sc_ownership[3, p]))
                         for p in range(num_provinces) if state.g_sc_ownership[3, p] == 1]
            _ot_provs = [(id2n.get(p, str(p)), int(state.g_order_table[p, _F_ORDER_TYPE]))
                         for p in range(num_provinces) if int(state.g_order_table[p, _F_ORDER_TYPE]) != 0]
            _unit_provs = [(id2n.get(p, str(p)), u.get('power'), u.get('type'))
                           for p, u in state.unit_info.items() if u.get('power') == 3]
            _dbg_log.debug(
                "MC_DBG[GER] Phase1f: sc_provs=%s  ordered_provs=%s  "
                "own_units=%s  support_cands=%s  g_convoy_fleet_cands_before=%d",
                _sc_provs, _ot_provs, _unit_provs,
                [id2n.get(p, str(p)) for p in support_candidates],
                len(state.g_convoy_fleet_candidates),
            )
        assign_hold_supports(state, support_candidates)

        # 1f.5  Emit SUP HLD orders for confirmed supports ─────────────────────
        # _assign_hold_supports only fills the g_convoy_fleet_candidates BST with
        # random scores — it doesn't write any order_type.  The C binary's
        # ProcessTurn pipeline (decompile line 2642) calls BuildOrder_SUP_HLD
        # out of the convoy-chain second pass after assign_support_order has
        # set g_SupportConfirmed + g_SupportTarget on the supported province.
        #
        # Here we walk own-power unordered units, probe adjacent support-
        # candidate provinces via assign_support_order, and emit SUP HLD when
        # the commit fires (dst[20]==1, g_convoy_source_prov[dst]==src).  Each
        # supporter gets at most one SUP HLD per trial — matches C's
        # single-commit semantics (RegisterConvoyFleet → g_last_mto_insert
        # conflict branch).
        if power_index == own_power:
            for src_prov, unit in state.unit_info.items():
                if unit['power'] != power_index:
                    continue
                # Allow HLD default (from Phase 1b') to be upgraded to SUP_HLD.
                # Skip only if supporter already has an explicit move/support/cvy
                # order — the C "already inserted" sentinel guards the SUP
                # order itself, not a pre-existing default HLD.
                cur = int(state.g_order_table[src_prov, _F_ORDER_TYPE])
                if cur not in (0, _ORDER_HLD):
                    continue
                for dst_prov in state.adj_matrix.get(src_prov, []):
                    if dst_prov not in support_candidates:
                        continue
                    if int(state.g_order_table[dst_prov, _F_ORDER_ASGN]) == 1:
                        # already confirmed by a different supporter this trial
                        continue
                    assign_support_order(state, power_index, src_prov, dst_prov, 0)
                    confirmed = int(state.g_order_table[dst_prov, _F_ORDER_ASGN])
                    target    = int(state.g_convoy_source_prov[dst_prov])
                    # ConvoySourceProv is stored as float; -1 sentinel comes back as ~4.29e9.
                    if confirmed == 1 and target == src_prov:
                        # Clear the default HLD so _build_order_sup_hld's own
                        # "already inserted" guard (order_type != 0) doesn't fire.
                        state.g_order_table[src_prov, _F_ORDER_TYPE] = 0.0
                        _build_order_sup_hld(src_prov, dst_prov)
                        break  # one SUP HLD per supporter

        # 1f.7  Emit SUP MTO orders from g_support_opportunities_set ─────────────
        # build_support_opportunities populates g_support_opportunities_set during
        # Phase 0 setup with (mover, target, supporter) triples that satisfy
        # the triangle-geometry gate (defensive only — requires own-SC target).
        if power_index == own_power:
            sup_opps = getattr(state, 'g_support_opportunities_set', None) or []
            consumed_supporters: set = set()
            for opp in sup_opps:
                if int(opp.get('power', -1)) != power_index:
                    continue
                supporter = int(opp['supporter_prov'])
                mover     = int(opp['mover_prov'])
                target    = int(opp['target_prov'])

                if supporter in consumed_supporters:
                    continue
                sup_unit = state.unit_info.get(supporter)
                if sup_unit is None or sup_unit['power'] != power_index:
                    continue
                cur = int(state.g_order_table[supporter, _F_ORDER_TYPE])
                if cur not in (0, _ORDER_HLD):
                    continue
                mover_ot   = int(state.g_order_table[mover, _F_ORDER_TYPE])
                mover_dst  = int(state.g_order_table[mover, _F_DEST_PROV])
                if mover_ot not in (_ORDER_MTO, _ORDER_CTO) or mover_dst != target:
                    continue
                sup_type  = sup_unit.get('type', 'A')
                sup_coast = sup_unit.get('coast', '')
                if not state.can_reach_by_type(supporter, target, sup_type, sup_coast):
                    continue

                state.g_order_table[supporter, _F_ORDER_TYPE] = 0.0
                _build_order_sup_mto(supporter, mover, target)
                consumed_supporters.add(supporter)

        # 1f.8  (removed — was a misplaced approximation of C lines 3033–3327;
        #        the actual post-Phase-2 HLD→SUP_MTO sweep is section 1h.5)

        # 1g. Convoy chain assignment ─────────────────────────────────────────
        # Iterate g_convoy_dst_list (DAT_00bb65a4); for each prov with enemy presence /
        # SC ownership: find in Albert+0x4cfc candidate list → ScoreConvoyFleet.
        fleet_pool_a = 0x7ffb   # ppiStack_7c0 initial value (from decompile line 1239)
        inserted_count = 0
        for prov in list(state.g_convoy_dst_list):
            iVar20 = power_index * 0x100 + prov
            enemy_hi  = int(state.g_enemy_presence[power_index, prov])
            sc_own    = int(state.g_sc_ownership[power_index, prov])
            if enemy_hi > 0 or (enemy_hi >= 0 and sc_own != 0):
                # Mirrors: find ppiStack_7bc in Albert+0x4cfc where node[4]==prov
                # then MoveCandidate + StdMap_FindOrInsert + ScoreConvoyFleet.
                inserted_count += 1
                fleet_pool_a -= 1
                _move_candidate(prov)
                state.g_sub_order_map.add(prov)
                score_convoy_fleet(state, prov, fleet_pool_a)

        # Own-power only: second convoy pass (ProcessTurn.c lines 1294–1409).
        # Iterates g_convoy_fleet_candidates (Albert+0x4cfc); for candidates with
        # score < 0x7e1f (Phase 1f SC-province entries) whose dst is in
        # g_MoveList[own_power] (= state.g_convoy_dst_to_src, populated by
        # _build_order_mto), re-scores up to two candidates with pool-B scores
        # then restarts the outer loop from the beginning.
        #
        # pool-B initial score: ppiStack_7b4 = 0x7fff - (1 + inserted_count) * 4
        #   = 0x7ffb - 4 * inserted_count  (ppiStack_79c starts at 1 in C).
        # Two scoring ops per found candidate (fleet-prov sub-pass + dst sub-pass),
        # each decrementing fleet_pool_b by 1.
        #
        # C lookup key matching details:
        #   ppiStack_7bc (fleet/src prov) = g_MoveList node value [4] → army_src
        #     via state.g_convoy_dst_to_src[dst]; score check mirrors Phase 1g check.
        #   ppiStack_7c0 (dst prov) = *(candidate + 0x10) = candidate dst province.
        #   LAB_004516fb = advance (skip candidate, no restart).
        #   LAB_0045162d = second sub-pass (dst re-score, always reached).
        #   LAB_004516f1  = restart outer loop (ppiStack_790 = first element).
        if power_index == own_power:
            fleet_pool_b = 0x7ffb - 4 * inserted_count
            found = True
            while found:
                found = False
                for cand_score, dst in list(state.g_convoy_fleet_candidates):
                    if cand_score >= 0x7e1f:
                        # LAB_004516fb: score too high (Phase 1g/1h candidate) → advance
                        continue
                    # g_MoveList[own_power] lookup: is dst a target of own MTO?
                    army_src = state.g_convoy_dst_to_src.get(dst)
                    if army_src is None:
                        # LAB_004516fb: no own-power MTO targets this province → advance
                        continue
                    # First sub-pass (lines 1347–1375): optional — score army_src candidate
                    # if army_src passes the enemy-presence / SC-ownership gate.
                    # Mirrors: if (-1 < g_enemy_presence[power, fleet_prov]) and
                    #          (g_enemy_presence > 0 or g_sc_ownership != 0).
                    src_enemy = int(state.g_enemy_presence[power_index, army_src])
                    src_sc    = int(state.g_sc_ownership[power_index, army_src])
                    if src_enemy > 0 or (src_enemy >= 0 and src_sc != 0):
                        _move_candidate(army_src)
                        state.g_sub_order_map.add(army_src)
                        fleet_pool_b -= 1
                        score_convoy_fleet(state, army_src, fleet_pool_b)
                    # LAB_0045162d: second sub-pass (lines 1378–1400) — always score dst.
                    _move_candidate(dst)
                    fleet_pool_b -= 1
                    score_convoy_fleet(state, dst, fleet_pool_b)
                    # LAB_004516f1: restart outer loop from beginning.
                    found = True
                    break

        # 1g.5  Default-hold backfill ─────────────────────────────────────────
        # Units that pass through 1c–1g without acquiring an explicit order
        # default to HLD.  The C binary's resolver treats _F_ORDER_TYPE == 0
        # the same as HLD; we set it explicitly so evaluate_order_proposal
        # sees real candidates.  g_general_orders is populated by
        # generate_self_proposals (no-press) or score_order_candidates_from_broadcast
        # (press), so 1c fires and produces MTO orders — but units that
        # nothing touches still need this seed.
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            if int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0:
                state.g_order_table[prov, _F_ORDER_TYPE] = float(_ORDER_HLD)

        # Phase 2: Adjacency walk + post-processing ─────────────────────────
        # ProcessTurn.c lines 1411-2900.  For each unordered unit in
        # g_convoy_fleet_candidates, score reachable adjacencies, then apply
        # the full C post-processing pipeline before selecting a destination.
        #
        # Fix 2026-04-21 (MC-1): Full port of post-processing including:
        #   - Source-province dedup (lines 1950-1977)
        #   - Water-province score threshold (lines 1978-1986)
        #   - 3-slot ally-trust filtering (lines 1990-2068)
        #   - XDO press integration (lines 2086-2182) — own_power only
        #   - Fleet dedup (lines 2184-2234) — FLT units only
        #   - Target-flag filtering (lines 2235-2391)
        #   - Probabilistic final selection (lines 2392-2750)
        #     → BuildOrder_MTO / BuildConvoyOrders / BuildOrder_HLD
        _mc_dbg = (_trial == 0 and power_index == own_power
                   and _dbg_log.isEnabledFor(logging.DEBUG))
        if _mc_dbg:
            id2n = getattr(state, '_id_to_prov', {})
            _dbg_log.debug(
                "MC_DBG[p%d] trial=0  final_score_set nonzero: %s",
                power_index,
                [(id2n.get(p, str(p)), float(state.final_score_set[power_index, p]))
                 for p in range(256) if state.final_score_set[power_index, p] != 0],
            )
            _dbg_log.debug(
                "MC_DBG[p%d] Phase2 g_convoy_fleet_candidates=%s",
                power_index,
                [(s, id2n.get(p, str(p))) for s, p in state.g_convoy_fleet_candidates],
            )

        # HOLD-DBG: log state entering Phase 2 (trial 0, own power only).
        if _trial == 0 and power_index == own_power:
            _id2n = getattr(state, '_id_to_prov', {})
            _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
            _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
            _fleet_cands_own = [
                (_id2n.get(p, str(p)), s)
                for s, p in state.g_convoy_fleet_candidates
                if state.unit_info.get(p, {}).get('power') == power_index
            ]
            _pre_p2_ots = {
                _id2n.get(p, str(p)): int(state.g_order_table[p, _F_ORDER_TYPE])
                for p, u in state.unit_info.items()
                if u.get('power') == power_index
            }
            _fss_nonzero = int(np.count_nonzero(state.final_score_set[power_index, :256]))
            logger.info(
                "HOLD_DBG[%s] entering Phase2: fleet_cands_own=%s  "
                "unit_ot_pre_phase2=%s  final_score_set_nonzero=%d",
                _pname, _fleet_cands_own, _pre_p2_ots, _fss_nonzero,
            )
        for _cand_score, cand_prov in list(state.g_convoy_fleet_candidates):
            unit = state.unit_info.get(cand_prov)
            if unit is None:
                continue
            if unit['power'] != power_index:
                continue

            # ProcessTurn.c:1508-1509 copies the selected province score pair
            # into order-table columns 8/9 before candidate construction.
            # EvaluateOrderScore later adds this pair unconditionally for each
            # unit, making it the primary per-order score channel.
            state.g_order_table[cand_prov, _F_SELECTED_SCORE_LO] = float(
                state.final_score_set[power_index, cand_prov]
            )
            state.g_order_table[cand_prov, _F_SELECTED_SCORE_HI] = 0.0

            # AdjacencyList_FilterByUnitType (C line 1517-1519)
            # Fleets use fleet_adj_matrix which only contains fleet-reachable
            # neighbours (built from uppercase abut_list entries).  This
            # correctly excludes land-only borders between coastal provinces
            # (e.g. ANK→SMY) that the old terrain-only filter missed.
            utype = unit['type']
            if utype in ('A', 'AMY'):
                raw_adj = state.adj_matrix.get(cand_prov, [])
                adj_list = [a for a in raw_adj if a not in state.water_provinces]
            elif utype in ('F', 'FLT'):
                adj_list = list(state.fleet_adj_matrix.get(cand_prov, []))
                # Fallback for coast-variant units stored at base province ID
                # (e.g. F STP/SC stored at STP base id=66 with coast='SC').
                if not adj_list:
                    _coast = unit.get('coast', '')
                    if _coast:
                        _coast_key = '/' + _coast.upper()
                        adj_list = list(
                            getattr(state, 'fleet_coast_adj', {}).get(
                                (cand_prov, _coast_key), []))
            else:
                adj_list = list(state.adj_matrix.get(cand_prov, []))

            if not adj_list:
                continue

            # 30% random gate (C line 1523: (rand()/0x17)%100 < 0x1e)
            r_gate = random.randint(0, 32767)
            scored_mode = (r_gate // 0x17) % 100 < 0x1e

            # ── Inner scoring loop: build candidate list ──────────────────
            # C accumulates into a BST (local_784); we use a sorted list of
            # (score_lo, score_hi, dest_prov) tuples to mirror the BST ordering.
            cand_list: list[tuple] = []  # [(score, dest_prov), ...]

            for adj_prov in adj_list:
                if scored_mode:
                    # C lines 1542-1558: three-level gate determines random
                    # vs deterministic scoring.
                    # Level 1 (C 1542-1544): g_enemy_presence[power, adj] > 0
                    #   → random 500+
                    # Level 2 (C 1548-1549): g_sc_ownership[power, adj] != 0
                    #   → deterministic (fall through to LAB_00451bb0)
                    # Level 3 (C 1553-1555): g_proximity_score[power, adj] > 0
                    #   → random 500+; else → deterministic
                    # Fixed 2026-04-28: was using wrong variables (g_own_reach_score
                    # instead of g_enemy_presence/g_proximity_score) and had the
                    # SC-ownership logic inverted — provinces with own units got
                    # random 500+ instead of deterministic, inflating owned-SC scores
                    # and causing units to move back to occupied SCs.
                    enemy_pres = int(state.g_enemy_presence[power_index, adj_prov])
                    sc = int(state.g_sc_ownership[power_index, adj_prov])
                    prox = float(state.g_proximity_score[power_index, adj_prov])
                    use_random = (enemy_pres > 0
                                  or (sc == 0 and prox > 0))
                    if use_random:
                        r2 = random.randint(0, 32767)
                        score = (r2 // 0x17) % 100 + 500
                    else:
                        # deterministic: enemy_pres <= 0 AND
                        #   (sc != 0 OR prox <= 0)
                        fs = float(state.final_score_set[power_index, adj_prov])
                        if utype in ('A', 'AMY'):
                            score = fs + int(state.g_province_score_trial[adj_prov])
                        else:
                            score = fs
                else:
                    fs = float(state.final_score_set[power_index, adj_prov])
                    if utype in ('A', 'AMY'):
                        score = fs + int(state.g_province_score_trial[adj_prov])
                    else:
                        score = fs
                    # (Own-SC penalty removed — scoring.py Pass 3c now
                    # applies the C-matching Adjustment 9 cap to
                    # final_score_set directly.)
                cand_list.append((score, adj_prov))

            # Post-loop: source unit's own entry (C lines 1632-1653).
            # Fixed 2026-04-28: was gated by `not scored_mode`, but C adds
            # the hold entry UNCONDITIONALLY after the adjacency loop.
            # Missing hold in scored_mode (30% of trials) forced units to
            # move away from unoccupied SCs instead of staying to capture.
            if adj_list:
                fs_src = float(state.final_score_set[power_index, cand_prov])
                if utype in ('A', 'AMY'):
                    src_score = fs_src + int(state.g_province_score_trial[adj_list[0]])
                else:
                    src_score = fs_src
                cand_list.append((src_score, cand_prov))

            # ProcessTurn C:1669 compares the current unit-type token with the
            # three-byte literal at PTR_DAT_004b13ac (AMY).  On equality its
            # C:1674-1940 BFS adds destinations reachable through 1-3 own
            # fleets, carrying the fleet legs in the per-destination route
            # struct.  This block follows the source/hold insertion in C, and
            # convoy landings use the OrderedSet score directly: unlike normal
            # adjacent army moves, DAT_00ba3b70 is not added here.
            if utype in ('A', 'AMY'):
                from ..moves.convoy import _enumerate_convoy_chains_for_src
                route_dests = _enumerate_convoy_chains_for_src(
                    state, cand_prov
                )
                if route_dests:
                    direct_dests = {int(candidate[1]) for candidate in cand_list}
                    for convoy_dest, route in route_dests.items():
                        if convoy_dest in direct_dests:
                            continue
                        score = float(state.final_score_set[power_index, convoy_dest])
                        cand_list.append((score, convoy_dest))

            if not cand_list:
                continue

            # Sort descending by score (C BST pops highest first)
            cand_list.sort(key=lambda x: x[0], reverse=True)

            if _mc_dbg:
                _pn = id2n.get(cand_prov, str(cand_prov))
                _dbg_log.debug(
                    "MC_DBG[GER] unit=%s@%-4s scored_mode=%s cands=%s",
                    utype, _pn, scored_mode,
                    [(f"{s:.0f}", id2n.get(d, str(d)))
                     for s, d in cand_list[:8]],
                )

            # ── Post-processing Step 1: source-province dedup (1950-1977) ─
            # C condition: (puVar10[1] != iStack_460) AND (cand_count > 1)
            #              AND (g_ProvinceBase[src] < 500)  → drop the
            # dest == src candidate, i.e. take away the hold option.
            #
            # Corrected 2026-08-12.  `&DAT_00bb6e00` is a std::map and
            # DAT_00bb6e04 is its _Myhead, i.e. end() — C:536-547 clears the
            # container through that pointer using the standard MSVC
            # tree-destroy + reset-header-to-self sequence, and C:1946 asserts
            # `*puVar10 == &DAT_00bb6e00` (container identity).  So
            # `puVar10[1] != iStack_460` means the find did NOT hit end(): the
            # source province is a MEMBER of that map.  It is not an SC-owner
            # comparison and DAT_00bb6e04 is not a power index; the previous
            # reading (2026-04-28) gated on g_sc_owner, which is unrelated.
            #
            # The map is populated by StdMap_FindOrInsert at C:1286/1372, the
            # two convoy-rescore passes — bound in Python as g_sub_order_map
            # (see the .add() calls beside score_convoy_fleet in Phase 1e/1g).
            # g_ProvinceBase has no Python binding (finding (10)); its only
            # other C reader is unported, and the `< 500` guard is permissive
            # early on, so it is left out rather than faked.
            if cand_prov in state.g_sub_order_map and len(cand_list) > 1:
                cand_list = [candidate for candidate in cand_list
                             if candidate[1] != cand_prov]

            # ── Post-processing Step 2: score threshold (C:1978-1986) ─────
            # C: if the int64 pair DAT_005b98e8/ec[src] == 1 → threshold 0;
            # else threshold = final_score_set[power, src].  Used by the
            # target-flag filter in Step 6.
            #
            # Corrected 2026-08-12: DAT_005b98e8 is not a water-province
            # classification.  It is the per-province top-reach flag —
            # initialised to -1 by GenerateOrders.c:136, set to 0/1 by
            # ScoreOrderCandidates_AllPowers.c:512/580, and read the same way
            # by BuildSupportOpportunities.c:99.  Python binds it as
            # state.g_top_reach_flag (heuristics/scoring.py:318 writes it,
            # moves/support.py:74 reads it).  The old `cand_prov in
            # water_provinces` proxy was unrelated to it.
            #
            # C uses 0 where this used None; Step 6's guard tests
            # `threshold > 0`, so the two are equivalent there, but 0 is what C
            # actually stores.
            if int(state.g_top_reach_flag[cand_prov]) == 1:
                score_threshold = 0.0
            else:
                score_threshold = float(state.final_score_set[power_index, cand_prov])

            # ── Post-processing Step 3: trust/support scan (1990-2085) ─────
            # This updates the threshold and the per-trial support-opportunity
            # map.  It does not erase candidates; Step 6 owns target pruning.
            score_threshold = _apply_step3_support_filter(
                state,
                power_index,
                own_power,
                cand_prov,
                cand_list,
                score_threshold,
                reachable_provinces,
                num_powers,
            )

            # ── Post-processing Step 4: XDO press integration (2086-2182) ─
            # Only for own_power.  Step 4 reads the accepted-order containers
            # written at XDO.c:166/190, not the sender/global bookkeeping maps
            # written at XDO.c:90/91/155.
            cand_list = _apply_step4_xdo_constraint(
                state, power_index, own_power, cand_prov, cand_list
            )
            if not cand_list:
                continue

            # ── Post-processing Step 5: fleet dedup (2184-2234) ───────────
            # For FLT units, piStack_70c is a fresh temporary set.  It removes
            # duplicate destinations in this fleet's own candidate tree.
            if utype in ('F', 'FLT'):
                cand_list = _dedupe_step5_fleet_candidates(cand_list)

            # ── Post-processing Step 6: target-flag filter (2235-2391) ────
            cand_list = _apply_step6_target_filter(
                state, power_index, cand_prov, cand_list, score_threshold
            )

            # NOTE: the old "Step 6b self-bump filter" lived here.  It dropped
            # destinations occupied by a non-leaving own unit, and destinations
            # already claimed by another own mover.  Both are cases where C does
            # NOT drop the candidate — it emits SUP_HLD (C:2642) or SUP_MTO
            # (C:2896) instead.  Pre-filtering them turned every support
            # opportunity into "move somewhere else", which is why the port had
            # to synthesise supports afterwards by conscripting neighbours.
            # The emission tail below now handles both cases where C does.

            if not cand_list:
                continue

            # ── Post-processing Step 7: probabilistic final selection ─────
            # LAB_004531a8 (lines 2392-2750): pop best candidate, apply
            # score-ratio random gate, then dispatch.
            # C walks the BST from best to worst.  For each consecutive
            # pair (A=current, B=next) it computes:
            #   delta   = (A - B) * 5             [__allmul, line 2430]
            #   combined = delta + B               (= 5A - 4B, line 2433)
            #   divisor  = A + combined            (= 6A - 4B, line 2437)
            #   ratio    = (B * 100) / divisor     [__allmul/__alldiv, 2440-2442]
            #   if ratio <= rand(100) AND rand(100) > 20 → BREAK (keep A)
            # Otherwise advance: A ← B, fetch new B.
            # C line 2424: if score_cur == 0 (both lo/hi words) → ratio = 0.
            # Only overwrite HLD / unset orders — preserve Phase 1c MTO/SUP/CTO.
            # Hoisted out of the retry loop below: it concerns cand_prov, which
            # does not change between retries.
            cur_order = int(state.g_order_table[cand_prov, _F_ORDER_TYPE])
            if cur_order not in (0, _ORDER_HLD):
                continue

            # C wraps selection, gating and emission in a
            # `do { … } while (cStack_7c1 == '\0')` (C:2392-2905): whenever a
            # candidate is rejected, RemoveOrderCandidate drops it and the loop
            # re-runs the selection over what is left.  `remaining` is that
            # shrinking set; the port used to select once and give up, so a
            # rejection meant the unit held.
            remaining = list(cand_list)
            while remaining:
                selected_idx = 0  # start with best
                for i in range(len(remaining) - 1):
                    score_cur = remaining[i][0]       # A (current, higher)
                    score_nxt = remaining[i + 1][0]   # B (next, lower)
                    # C formula: ratio = B*100 / (6A - 4B)
                    if score_cur == 0:
                        ratio = 0
                    else:
                        diff_times_5 = (score_cur - score_nxt) * 5
                        combined = diff_times_5 + score_nxt       # 5A - 4B
                        divisor = score_cur + combined             # 6A - 4B
                        if divisor == 0:
                            ratio = 0
                        else:
                            ratio = int((score_nxt * 100) / divisor)
                    r1 = random.randrange(100)
                    if ratio <= r1:
                        r2 = random.randrange(100)
                        if r2 > 20:
                            break  # C: keep current candidate (line 2447)
                    # C: fall through → advance to next candidate (2448-2449)
                    selected_idx = i + 1
                selected_dest = remaining[selected_idx][1]

                # C:2475-2479 — dest == src → BuildOrder_HLD, unit done.  This
                # sits ahead of the trust gate in C, not after the dispatch.
                if selected_dest == cand_prov:
                    if _trial == 0 and power_index == own_power:
                        _id2n = getattr(state, '_id_to_prov', {})
                        _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
                        _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
                        _top_cands = [(round(c[0], 1), _id2n.get(c[1], str(c[1])))
                                      for c in remaining[:5]]
                        logger.info(
                            "HOLD_DBG[%s] unit@%s SELF-SELECTED HOLD "
                            "(src scored highest)  top_cands=%s  filtered=%d→%d",
                            _pname,
                            _id2n.get(cand_prov, str(cand_prov)),
                            _top_cands,
                            len(adj_list),
                            len(cand_list),
                        )
                    state.g_order_table[cand_prov, _F_ORDER_TYPE] = float(_ORDER_HLD)
                    break

                # 3-slot trust re-check on selected destination (C 2496-2547)
                # This emission block intentionally differs from Step 3: it
                # evaluates C, B, A and applies A only if trust is still empty.
                trust_lo_final = 0
                trust_hi_final = 0
                emission_desig_slots = [
                    (state.g_ally_designation_c, state.g_ally_designation_c_hi),
                    (state.g_ally_designation_b, state.g_ally_designation_b_hi),
                    (state.g_ally_designation_a, state.g_ally_designation_a_hi),
                ]
                for arr_lo, arr_hi in emission_desig_slots:
                    slot_lo = int(arr_lo[selected_dest]) if selected_dest < 256 else -1
                    slot_hi = int(arr_hi[selected_dest]) if selected_dest < 256 else -1
                    if slot_hi < 0:
                        continue
                    if arr_lo is state.g_ally_designation_a and (trust_lo_final != 0 or trust_hi_final != 0):
                        continue
                    if 0 <= slot_lo < num_powers:
                        rel = int(state.g_relation_score[power_index, slot_lo]) if slot_lo < 7 else 0
                        if rel > 9 or power_index == own_power:
                            # C indexes the flat 21-stride g_AllyTrustScore as
                            # [power*0x15 + slot]; the Python array is 2D (7,7),
                            # so the equivalent is [power, slot].  The former
                            # `.flat[]` form indexed 49 elements with stride 21 —
                            # correct only for power 0, wrong cell for 1-2,
                            # IndexError for 3-6 (swallowed), leaving the gate
                            # inert for six powers.
                            trust_lo_final = int(state.g_ally_trust_score[power_index, slot_lo])
                            trust_hi_final = int(state.g_ally_trust_score_hi[power_index, slot_lo])

                # C:2543-2546: if selected_dest IS in ally-claimed territory
                # (found in reachable_provinces), override trust to (lo=3, hi=0)
                # → gate rejects.  Prior port incorrectly used "foreign unit at
                # dest", which blocked all attacks.
                if selected_dest in reachable_provinces:
                    trust_lo_final, trust_hi_final = 3, 0

                # Trust gate (C lines 2547-2574).  C control flow:
                #   branch A (not_early or desig_b_hi < 0) → LAB_004536b5
                #   branch B: mutual-trust test —
                #       mutual trust holds → goto LAB_004536b5 (same gate as A)
                #       mutual trust fails → falls into LAB_004536bf, no gate
                #   LAB_004536b5 (C:2549): low trust → LAB_004536bf, else REJECT
                #   LAB_004536bf (C:2574): g_ConvoyActiveFlag[dest] > 0 → REJECT
                not_early = (state.g_press_flag != 1) or (state.g_near_end_game_factor >= 2.0)
                desig_b_hi_sel = int(state.g_ally_designation_b_hi[selected_dest]) if selected_dest < 256 else -1
                # "Low trust" = no ally claims on this territory → safe to enter.
                low_trust = trust_hi_final < 1 and (trust_hi_final < 0 or trust_lo_final == 0)
                if not_early or desig_b_hi_sel < 0:
                    reaches_accept = low_trust
                else:
                    # Early-game mutual trust path
                    mutual_trust = False
                    desig_b_lo = int(state.g_ally_designation_b[selected_dest]) if selected_dest < 256 else -1
                    if 0 <= desig_b_lo < num_powers:
                        fwd_hi = int(state.g_ally_trust_score_hi[power_index, desig_b_lo])
                        fwd_lo = float(state.g_ally_trust_score[power_index, desig_b_lo])
                        if fwd_hi >= 0 and (fwd_hi > 0 or fwd_lo > 1):
                            rev_hi = int(state.g_ally_trust_score_hi[desig_b_lo, power_index])
                            rev_lo = float(state.g_ally_trust_score[desig_b_lo, power_index])
                            if rev_hi >= 0 and (rev_hi > 0 or rev_lo > 1):
                                mutual_trust = True
                    # No mutual trust → C skips the gate entirely and accepts.
                    reaches_accept = low_trust if mutual_trust else True

                # C:2574 — the only read of g_ConvoyActiveFlag in ProcessTurn.c,
                # and it REJECTS.  The flag is written by
                # BuildOrder_SUP_HLD/SUP_MTO on the supported province when the
                # supported unit is foreign, i.e. "we already committed support
                # here" → don't also move into it.
                accepted_final = reaches_accept and int(state.g_convoy_active_flag[selected_dest]) <= 0

                if _mc_dbg:
                    _pn = id2n.get(cand_prov, str(cand_prov))
                    _dn = id2n.get(selected_dest, str(selected_dest))
                    _dbg_log.debug(
                        "MC_DBG[GER] unit@%-4s → %-4s  accepted=%s  "
                        "trust_final=(%d,%d)",
                        _pn, _dn, accepted_final,
                        trust_lo_final, trust_hi_final,
                    )

                if not accepted_final:
                    # HOLD-DBG: log the trust-gate rejection.
                    if _trial == 0 and power_index == own_power:
                        _id2n = getattr(state, '_id_to_prov', {})
                        _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
                        _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
                        _top_cands = [(round(c[0], 1), _id2n.get(c[1], str(c[1])))
                                      for c in remaining[:5]]
                        logger.info(
                            "HOLD_DBG[%s] unit@%s→%s TRUST-GATE REJECTED "
                            "(trust_final=lo=%d hi=%d  in_reachable=%s)  top_cands=%s",
                            _pname,
                            _id2n.get(cand_prov, str(cand_prov)),
                            _id2n.get(selected_dest, str(selected_dest)),
                            trust_lo_final, trust_hi_final,
                            selected_dest in reachable_provinces,
                            _top_cands,
                        )
                    remaining.pop(selected_idx)
                    continue

                # ── LAB_004536bf tail (C:2579-2694) ───────────────────────
                # Is the destination occupied by one of OUR units?
                # g_sc_ownership[p, x] == 1 means "power p has a unit at x"
                # (heuristics/scoring.py:477) — despite the name, it is unit
                # presence, not supply-centre ownership.
                emit_move = True     # C cStack_7a5
                rejected  = False    # C cStack_7c1 == '\0'
                if int(state.g_sc_ownership[power_index, selected_dest]) == 1:
                    # C reads the occupant's order from the unit record at
                    # board+0x2450 (field +0x20); the Python port keeps a single
                    # order store, so g_order_table[dest, 0] stands in for it —
                    # the same substitution the old step-6b filter made.
                    dest_ot = int(state.g_order_table[selected_dest, _F_ORDER_TYPE])
                    if dest_ot != 0:
                        if int(state.g_order_table[selected_dest, _F_ORDER_ASGN]) > 1:
                            rejected = True                      # C:2597
                        elif dest_ot not in (_ORDER_MTO, _ORDER_CTO):
                            # Occupant is staying put (C:2610/2619 test the
                            # order field against 2 and 6).  Support it holding
                            # rather than bouncing off it — but only if the
                            # province is under more pressure than it has cover
                            # for (C:2627).
                            if (int(state.g_support_demand[selected_dest])
                                    <= int(state.g_order_table[selected_dest, _F_INCOMING_MOVE])):
                                rejected = True
                            else:
                                # C:2642 — BuildOrder_SUP_HLD, and cStack_7a5=0
                                # so no MTO follows.  Zero the order type first:
                                # the 1g.5 backfill left every own unit at HLD
                                # and _build_order_sup_hld early-returns on any
                                # non-zero order.
                                state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                                _build_order_sup_hld(cand_prov, selected_dest)
                                emit_move = False
                        # dest_ot in (MTO, CTO): occupant is leaving → fall
                        # through and take the province.
                    else:
                        # C:2650-2693 — our province, nothing ordered on it.
                        # Re-score the fleet candidate for this unit instead of
                        # moving.  C walks the candidate list for the entry
                        # whose province is dest and takes its score (+0xc).
                        _entry_score = None
                        for _s, _p in state.g_convoy_fleet_candidates:
                            if _p == selected_dest:
                                _entry_score = _s
                        if _entry_score is not None and _entry_score >= 0:
                            score_convoy_fleet(state, cand_prov, int(_entry_score) - 1)
                            # C:2687 also does g_ProvinceBase[src] += 1.  That
                            # array has no Python binding and its only C reader
                            # (C:1951) is itself unported, so the write is
                            # omitted — see finding (10).
                            emit_move = False
                        else:
                            rejected = True

                if rejected:
                    remaining.pop(selected_idx)
                    continue

                # ── LAB_00453a2c (C:2696-2903) ────────────────────────────
                # Is another own unit already ordered into this destination?
                # g_convoy_dst_to_src is C's DAT_00bb65a0 move map.
                _mover = state.g_convoy_dst_to_src.get(selected_dest)
                if _mover == cand_prov:
                    # Defensive: a unit must never support its own move.  C
                    # cannot reach this (the map is cleared per trial and a unit
                    # that has emitted its MTO breaks out of the retry loop),
                    # but a stale entry here would emit an illegal order.
                    _mover = None
                if _mover is None:
                    # C:2702-2750 — nobody else is going there.
                    if emit_move:
                        state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                        from ..moves.convoy import _get_convoy_route
                        fleet_count, _route = _get_convoy_route(
                            state, cand_prov, selected_dest
                        )
                        route_available = fleet_count > 0 and all(
                            int(state.g_order_table[fleet, _F_ORDER_TYPE])
                            in (0, _ORDER_HLD)
                            for fleet in _route
                        )
                        if route_available:
                            build_convoy_orders(
                                state, power_index, cand_prov, selected_dest, 0
                            )
                        elif fleet_count > 0 and selected_dest not in adj_list:
                            # Non-adjacent candidates exist only via convoy. If
                            # their fleet route was consumed by an earlier unit,
                            # C's inline route state can no longer select them.
                            # Remove this candidate and retry the next one.
                            state.g_order_table[cand_prov, _F_ORDER_TYPE] = float(
                                _ORDER_HLD
                            )
                            remaining.pop(selected_idx)
                            continue
                        else:
                            _build_order_mto(cand_prov, selected_dest, 0)
                    break
                # C:2757-2865 — a pending support assignment on this occupied
                # destination can be promoted to a completed convoy chain.  On
                # success C jumps past SUP_MTO emission to LAB_00453f34.
                if _apply_convoy_swap(
                    state,
                    power_index,
                    cand_prov,
                    selected_dest,
                ):
                    if emit_move:
                        state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                        _build_order_mto(cand_prov, selected_dest, 0)
                    break
                # C:2873-2898 — support that mover instead of contesting the
                # province, provided it is not already over-supported.
                if (int(state.g_order_table[selected_dest, _F_INCOMING_MOVE])
                        <= int(state.g_support_demand[selected_dest])
                        and int(state.g_order_table[selected_dest, _F_ORDER_ASGN]) != 2):
                    # A convoy-only landing is a legal move candidate for an
                    # army, but that does not make the army adjacent enough to
                    # support somebody else's move there.  C's SUP_MTO builder
                    # is reached through a coast/type-filtered candidate node;
                    # Python's merged list also contains convoy-only nodes, so
                    # enforce the supporter-side move adjacency before using
                    # this branch.
                    _supporter = state.unit_info.get(cand_prov, {})
                    if not state.can_reach_by_type(
                        cand_prov,
                        selected_dest,
                        _supporter.get('type', 'A'),
                        _supporter.get('coast', ''),
                    ):
                        remaining.pop(selected_idx)
                        continue
                    state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                    _build_order_sup_mto(cand_prov, _mover, selected_dest)
                    break
                # C:2901-2903 — otherwise drop this destination and retry.
                remaining.pop(selected_idx)

        # HOLD-DBG: summarize final unit orders after Phase 2 (trial 0 only).
        if _trial == 0 and power_index == own_power:
            _id2n = getattr(state, '_id_to_prov', {})
            _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
            _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
            _fleet_provs = {p for _, p in state.g_convoy_fleet_candidates}
            _post_p2 = []
            for _pp, _uu in state.unit_info.items():
                if _uu.get('power') != power_index:
                    continue
                _ot = int(state.g_order_table[_pp, _F_ORDER_TYPE])
                _dst = int(state.g_order_table[_pp, _F_DEST_PROV]) if _ot not in (0, 1) else None
                _in_cands = _pp in _fleet_provs
                _post_p2.append((
                    _id2n.get(_pp, str(_pp)),
                    _ot,
                    _id2n.get(_dst, str(_dst)) if _dst is not None else '-',
                    'in_cands' if _in_cands else 'NOT_IN_CANDS',
                ))
            logger.info(
                "HOLD_DBG[%s] after Phase2: unit_orders=%s",
                _pname, _post_p2,
            )

        # 1h. Target-bonus scoring ────────────────────────────────────────────
        # Pass 1: MTO/CTO toward target-flagged provinces (+150 or +75).
        # Pass 2: RTO / unit-presence check (lines 2909–2940 in decompile).
        # Pass 3: SUP_MTO toward SC-gaining flag (+50, lines 2958–3032).
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            order_type = int(state.g_order_table[prov, _F_ORDER_TYPE])
            press_active = (state.g_press_flag == 1)   # C: DAT_00baed68 == '\x01'

            # C tests g_TargetFlag (0x5e40e8, hi word DAT_005e40ec) here — a
            # DIFFERENT array from g_ProvTargetFlag (0x5ee8e8), which this same
            # function uses at decompile line 3717.  g_TargetFlag is bound as
            # state.g_target_flag (written by SnapshotProvinceState with 1/2);
            # g_prov_target_flag is ScoreProvinces' classification.
            # Corrected 2026-08-12: both sites read g_prov_target_flag.
            if order_type in (_ORDER_MTO, _ORDER_CTO):
                dest = int(state.g_order_table[prov, _F_DEST_PROV])
                tflag = int(state.g_target_flag[power_index, dest])
                if tflag == 2:
                    state.g_early_game_bonus += 150 if press_active else 75

            elif order_type == _ORDER_SUP_MTO:
                # C (decompile 3021-3027) uses TWO different node offsets:
                #   node+0x2c = the supported unit's province  → _F_SECONDARY
                #   node+0x30 = that unit's destination        → _F_DEST_PROV
                # The SC gate is on +0x2c; only the target-flag test is on
                # +0x30.  Corrected 2026-08-12: both read _F_DEST_PROV.
                supported = int(state.g_order_table[prov, _F_SECONDARY])
                dest = int(state.g_order_table[prov, _F_DEST_PROV])
                # C's second operand is DAT_00520cec — the HI word of
                # g_SCOwnership, i.e. the pair is one int64 == 0 test, not a
                # separate enemy-presence check (0x4f6ce8).
                sc_at_supported = int(state.g_sc_ownership[power_index, supported])
                if sc_at_supported == 0:
                    tflag_dest = int(state.g_target_flag[power_index, dest])
                    if (tflag_dest == 2) or (press_active and state.g_history_counter == 0):
                        state.g_early_game_bonus += 50

        # 1h.5  Post-Phase-2 HLD→SUP_MTO sweep (C lines 3033–3327) ──────────
        # Runs after ALL MTOs are finalised (distinct from Phase 2's inline
        # scan at C 1784–1808 which fires per-MTO-assignment).  Iterates
        # own-power HLD units; for each, scans adjacencies against
        # g_convoy_dst_list.  When incoming-MTO count < threat score at the
        # adjacent destination, converts the HLD unit to SUP_MTO.
        #
        # C condition: g_ProvinceBaseScore[adj] < DAT_00baeddc[adj]
        #   = _F_INCOMING_MOVE[adj] < threat_score[adj].
        # C lines 1440–1492 recompute threat_score from g_ThreatScore (raw
        # per-power reachability counts) with the same trust/ally gate as
        # ScoreProvinces.c:373–383, which Python stores as
        # state.g_threat_level[power_index, prov].  The ppiVar24[0x1500]
        # subtraction at C:1473 is dead (array initialised to 0xffffffff
        # → (int)-1, condition `0 < -1` is never true).
        for unit_prov, unit in state.unit_info.items():
            if unit.get('power') != power_index:
                continue
            if int(state.g_order_table[unit_prov, _F_ORDER_TYPE]) != _ORDER_HLD:
                continue
            best_dst   = None
            best_score = -1.0
            unit_type  = unit.get('type', 'A')
            unit_coast = unit.get('coast', '')
            for adj_prov in state.adj_matrix.get(unit_prov, []):
                if not state.can_reach_by_type(unit_prov, adj_prov, unit_type, unit_coast):
                    continue
                if adj_prov not in state.g_convoy_dst_list:
                    continue
                if int(state.g_order_table[adj_prov, _F_ORDER_ASGN]) == 2:
                    continue
                incoming = int(state.g_order_table[adj_prov, _F_INCOMING_MOVE])
                threat   = int(state.g_threat_level[power_index, adj_prov])
                if incoming >= threat:
                    continue
                score = float(state.final_score_set[power_index, adj_prov])
                if score > best_score:
                    best_score = score
                    best_dst   = adj_prov
            if best_dst is None:
                continue
            mover = (state.g_convoy_dst_to_src or {}).get(best_dst)
            if mover is None:
                continue
            state.g_order_table[unit_prov, _F_ORDER_TYPE] = 0.0
            _build_order_sup_mto(unit_prov, mover, best_dst)

        # ProcessTurn.c lines 3695–3746: scan other-power units (gamestate+0x24b4
        # list, populated by ParseNOWUnit for non-own-power units) for units whose
        # g_order_table destination has g_ProvTargetFlag[own, dest] == 1 AND
        # (g_army_adj_count[dest] == 0 OR unit is FLT).  For each matching unit,
        # search g_trial_list2 (DAT_00bbf648) for a same-unit entry; if found and
        # g_order_table[entry_prov, _F_INCOMING_MOVE] == 0 → g_other_score++.
        #
        # DAT_00bbf648 is cleared each trial (1a) and NEVER written to during MC
        # trials — no C caller populates it within ProcessTurn.  The inner search
        # always exits immediately, so g_other_score stays 0 every trial.
        # The scan is reproduced structurally for parity; g_trial_list2 ensures
        # the correct zero result without any proxy approximation.
        for _uprov, _uinfo in state.unit_info.items():
            if _uinfo.get('power') == power_index:
                continue  # 0x24b4 = other-power units only
            if _uprov < 0 or _uprov >= 256:
                continue
            _udest = int(state.g_order_table[_uprov, _F_DEST_PROV])
            if _udest < 0 or _udest >= 256:
                continue
            if int(state.g_prov_target_flag[power_index, _udest]) != 1:
                continue
            _no_army = (int(state.g_army_adj_count[_udest]) == 0)
            _is_flt  = _uinfo.get('type', '') in ('F', 'FLT')
            if not (_no_army or _is_flt):
                continue
            # Inner search over g_trial_list2 (always empty — see note above):
            for _entry in state.g_trial_list2:
                if _entry.get('unit_id') == _uprov:
                    _ep = _entry.get('province', -1)
                    if 0 <= _ep < 256 and int(state.g_order_table[_ep, _F_INCOMING_MOVE]) == 0:
                        state.g_other_score += 1
                    break

        # Every own unit must reach EvaluateOrderProposal with a serializable
        # order.  Several C retry branches clear a staging order before either
        # rebuilding it or falling through to BuildOrder_HLD; Python's
        # collapsed table can otherwise retain zero after a rejected convoy.
        for prov, unit in state.unit_info.items():
            if (unit.get('power') == power_index
                    and int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0):
                state.g_order_table[prov, _F_ORDER_TYPE] = float(_ORDER_HLD)

        # 1i. Evaluate order proposal for this power (once per trial). ─────────
        # Mirrors: EvaluateOrderProposal(param_1_00, power_index) at decompile line 3747.
        evaluate_order_proposal(state, power_index, trial_idx=_trial)

        # 1b'-post. Default-HOLD seed for unassigned own units ────────────────
        # H2 fix: In C, EvaluateOrderProposal skips units with order_type==0.
        # After evaluation, seed HLD for any own units that still have no
        # order so that the submission pipeline has a valid order for every
        # unit.  Dispatch passes (1c-1h) already wrote non-zero order types
        # for units with movement/support/convoy orders; only truly idle
        # units remain at 0 here.
        for prov, unit in state.unit_info.items():
            if unit['power'] == power_index:
                if int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0:
                    state.g_order_table[prov, _F_ORDER_TYPE] = float(_ORDER_HLD)

    # Stamp this power as processed for the current round so UpdateScoreState's
    # stale check (power_round_record[p] != g_current_round) fires correctly
    # after _orders.py advances g_current_round post-MC-loop.
    state.g_power_round_record[power_index] = state.g_current_round


# ── UpdateScoreState ──────────────────────────────────────────────────────────

def _update_ally_order_score(state: InnerGameState, power: int) -> None:
    """
    Port of UpdateAllyOrderScore (FUN_00442770).
    Pass 1 sub-function of UpdateScoreState.

    C algorithm (1107 lines):
      Outer loop: iterate g_CandidateRecordList for entries where candidate.power == param_1.
      For each non-skipped candidate:
        (b)  Clear g_mc_province_pressure / g_mc_fleet_pressure and staging area.
        (c)  Compute round count local_b08 = min(trial_counter+4, 30).
             C groups those slots in a map keyed by the sum of each selected
             candidate's heat_scores[power] across all powers.  Each map node
             stores the first slot with that key and a multiplicity count.
        BST walk — one pass per distinct key, in ascending-key order:
             Ally orders come from the representative slot, own orders come
             from this candidate, and pressure accumulation is weighted by the
             key's multiplicity.
          (e) For each ally power ≠ current with sc_count > 0, copy
              g_bbf694[ally*30+0].order_list into staging via FindOrInsert.
          (d) Insert candidate's own orders via FindOrInsert.
          (f) Recompute pressure_own/pressure_adj from full accumulated staging set.
          (g) Accumulate g_mc_province_pressure with weight = local_b08.
        (h)  Call EvaluateAllianceScore (once per candidate).
        (i)  Store result in candidate['alliance_score'] / ['alliance_score_avg'].
    """
    if getattr(state, 'g_candidate_record_list', None) is None:
        return

    num_provinces = 256
    num_powers = len(state.g_unit_count)
    # DAT_0062cc64 is BuildAndSendSUB's current proposal-trial counter.  It is
    # unrelated to g_HistoryCounter (the DAIDE press level); conflating them
    # made full-press games evaluate 30 slots on their first trial instead of
    # C's four.
    trial_counter = int(getattr(state, 'g_n_trials_completed', 0))
    local_b08 = min(trial_counter + 4, 30) if trial_counter < 8 else 30
    water_provs = getattr(state, 'water_provinces', set())
    coastal_provs = getattr(state, 'coastal_provinces', set())

    from ..heuristics import evaluate_alliance_score

    candidate_by_key = {
        candidate_orders_key(
            int(rec.get('power', -1)), rec.get('orders', [])): rec
        for rec in state.g_candidate_record_list
    }

    for c in state.g_candidate_record_list:
        if c.get('power') != power:
            continue
        if c.get('skip_flag', False):
            continue

        # ── Phase (b): clear MC pressure arrays ──────────────────────────────
        # C: lines 150–200 — clear g_baed7c record[0x1a+p] and DAT_00b9a980/b95580
        state.g_mc_province_pressure.fill(0)
        state.g_mc_fleet_pressure.fill(0)

        # Clear staging area for this candidate.
        # C: the staging OrderedSet (+0x2450) is rebuilt empty for each candidate.
        state.g_order_table[:, _F_ORDER_TYPE] = 0.0
        state.g_order_table[:, _F_DEST_PROV] = 0.0
        state.g_order_table[:, _F_DEST_COAST] = 0.0
        state.g_order_table[:, _F_SECONDARY] = 0.0

        # C UpdateAllyOrderScore.c:193-259 sums record+0x1c8+power*4 for
        # every selected power at each slot.  TrialEvaluateOrders places
        # aiStack_a9c at record offset 0x1ac, so +0x1c8 is exactly element 7
        # of the 21-entry array: heat_scores[power].  Duplicate sums share a
        # map node whose field 4 is incremented; field 5 retains the first
        # slot.  Python keeps that record payload directly on each candidate.
        slot_groups: dict[int, list[int]] = {}
        for slot in range(local_b08):
            slot_score = 0
            for selected_power in range(num_powers):
                selected_slots = state.g_current_best_order.get(
                    selected_power, [])
                if slot >= len(selected_slots):
                    continue
                selected_orders = selected_slots[slot]
                selected_key = candidate_orders_key(
                    selected_power, selected_orders)
                selected_record = candidate_by_key.get(selected_key)
                if selected_record is None:
                    continue
                heat_scores = selected_record.get('heat_scores', [])
                if power < len(heat_scores):
                    slot_score += int(heat_scores[power])
            if slot_score in slot_groups:
                slot_groups[slot_score][1] += 1
            else:
                slot_groups[slot_score] = [slot, 1]

        for _slot_score in sorted(slot_groups):
            r, group_weight = slot_groups[_slot_score]
            # ── Phase (e): ally orders for slot r (FindOrInsert) ─────────────
            # C: lines 293–462 — for each ally_power with sc_count > 0, walk
            # g_bbf694[ally*30+r].order_list, insert each entry via FindOrInsert.
            # Ally orders go first; own orders cannot overwrite them.
            for ally_power in range(num_powers):
                if ally_power == power or int(state.sc_count[ally_power]) <= 0:
                    continue
                slot_list = state.g_current_best_order.get(ally_power, [])
                if r >= len(slot_list):
                    continue
                slot_orders = slot_list[r]
                if not isinstance(slot_orders, (list, tuple)):
                    continue
                # Each DAT_00bbf690/694 slot points to one complete candidate
                # record and its full order list.  The previous port treated a
                # slot as one unit order, losing the rest of the ally's set.
                for ao in slot_orders:
                    if not isinstance(ao, (list, tuple)) or len(ao) < 2:
                        continue
                    ap, aot = int(ao[0]), int(ao[1])
                    if ap < 0 or ap >= num_provinces or aot <= 0:
                        continue
                    if int(state.g_order_table[ap, _F_ORDER_TYPE]) != 0:
                        continue
                    restore_order_entry(state.g_order_table, ao)
                    if aot == _ORDER_SUP_HLD and len(ao) > 4:
                        # BuildOrder_SUP_HLD stores the supported province in
                        # the destination column in Python's collapsed table.
                        state.g_order_table[ap, _F_DEST_PROV] = float(ao[4])

            # ── Phase (d): own orders for slot r (FindOrInsert) ──────────────
            # C: lines 464–604 — walk candidate's own order list, insert via
            # OrderedSet_FindOrInsert.  Own orders cannot overwrite ally entries.
            for order_entry in c.get('orders', []):
                if not isinstance(order_entry, (list, tuple)) or len(order_entry) < 2:
                    continue
                prov = int(order_entry[0])
                if prov < 0 or prov >= num_provinces:
                    continue
                if int(state.g_order_table[prov, _F_ORDER_TYPE]) != 0:
                    continue
                order_type = int(order_entry[1])
                state.g_order_table[prov, _F_ORDER_TYPE] = float(order_type)
                if order_type == _ORDER_MTO and len(order_entry) > 2:
                    state.g_order_table[prov, _F_DEST_PROV] = float(order_entry[2])
                    if len(order_entry) > 3:
                        state.g_order_table[prov, _F_DEST_COAST] = float(order_entry[3])
                    if len(order_entry) > 4:
                        state.g_order_table[prov, _F_SECONDARY] = float(order_entry[4])
                elif order_type == _ORDER_SUP_HLD and len(order_entry) > 4:
                    # C case 3: supported unit's province — col 2 for SUP_HLD
                    # (BuildOrder_SUP_HLD.c:28).  See the ally branch above.
                    state.g_order_table[prov, _F_DEST_PROV] = float(order_entry[4])
                elif order_type in (_ORDER_SUP_MTO, 5) and len(order_entry) > 4:
                    # C case 4/5: staging+0x2c = local_b58[4]; staging+0x30 not in tuple
                    state.g_order_table[prov, _F_SECONDARY] = float(order_entry[4])
                elif order_type == _ORDER_CTO and len(order_entry) > 2:
                    # C case 6: staging+0x24 = local_b58[2], staging+0x28 = local_b58[3]
                    state.g_order_table[prov, _F_DEST_PROV] = float(order_entry[2])
                    if len(order_entry) > 3:
                        state.g_order_table[prov, _F_DEST_COAST] = float(order_entry[3])

            # ── Phase (f): pressure arrays from staging ───────────────────────
            # C: lines 607–785 — three flag branches per staging node:
            #   flag 0x6b (committed support/convoy): pressure_own[staging.dest_prov]
            #   flag 0x6a (fleet MTO):                pressure_adj[each fleet adj] (dedup)
            #   else (non-fleet ordered unit):         pressure_own[unit.prov]
            # Both arrays feed the fleet-expansion gate in Phase (f2).
            pressure_own = np.zeros(num_provinces, dtype=np.int32)  # apiStack_a40
            pressure_adj = np.zeros(num_provinces, dtype=np.int32)  # apiStack_640

            for prov, unit in state.unit_info.items():
                order_type = int(state.g_order_table[prov, _F_ORDER_TYPE])
                if order_type == 0:
                    continue
                utype = unit.get('type', 'A')

                if order_type in (_ORDER_SUP_HLD, _ORDER_SUP_MTO, _ORDER_CVY):
                    # flag 0x6b: committed order — marks staging.dest_prov
                    # (SUP_HLD/SUP_MTO don't write _F_DEST_PROV, so this lands on 0)
                    dest = int(state.g_order_table[prov, _F_DEST_PROV])
                    if 0 <= dest < num_provinces:
                        pressure_own[dest] += 1
                elif utype in ('F', 'FLT') and order_type == _ORDER_MTO:
                    # flag 0x6a: fleet MTO — adjacency pressure (deduplicated)
                    last_seen = -1
                    for adj in state.fleet_adj_matrix.get(prov, []):
                        if adj != last_seen and adj < num_provinces:
                            pressure_adj[adj] += 1
                            last_seen = adj
                else:
                    # else: non-fleet ordered unit — marks own province as occupied
                    pressure_own[prov] += 1

            # ── Phase (f2): fleet-MTO expansion pass ─────────────────────────
            # C: lines 802–877 — for each fleet MTO unit, check fleet adjacencies.
            # A unit earns ally-record credit (Phase g) only if ≥1 adjacent province
            # satisfies all three gates:
            #   pressure_own[adj] == 0   (not occupied / targeted by another order)
            #   pressure_adj[adj] < 2    (fewer than 2 fleets already adjacent)
            #   adj != 0                 (C: adj != staging+0x60, zero-initialised)
            fleet_mto_has_expansion: set = set()

            for prov, unit in state.unit_info.items():
                if int(state.g_order_table[prov, _F_ORDER_TYPE]) != _ORDER_MTO:
                    continue
                if unit.get('type', 'A') not in ('F', 'FLT'):
                    continue
                for adj in state.fleet_adj_matrix.get(prov, []):
                    if adj == 0:
                        continue
                    if pressure_own[adj] != 0:
                        continue
                    if pressure_adj[adj] >= 2:
                        continue
                    fleet_mto_has_expansion.add(prov)
                    break

            # ── Phase (g): accumulate into g_mc_province_pressure ────────────
            # C: lines 896–1034 — single BST node, weight = local_b08.
            # Ally-record weight is 0 for:
            #   • unordered units (flag never set in Phase f)
            #   • fleet MTO units with no expansion opportunity (Phase f2 absent)
            for prov, unit in state.unit_info.items():
                unit_power = unit.get('power', -1)
                if unit_power < 0 or int(state.sc_count[unit_power]) <= 0:
                    continue
                order_type = int(state.g_order_table[prov, _F_ORDER_TYPE])
                if order_type == 0:
                    continue
                utype = unit.get('type', 'A')
                # fleet MTO: only credit when Phase f2 found an expansion opportunity
                if order_type == _ORDER_MTO and utype in ('F', 'FLT'):
                    if prov not in fleet_mto_has_expansion:
                        continue

                state.g_mc_province_pressure[unit_power, prov] += group_weight

                is_fleet = utype in ('F', 'FLT')
                is_coastal = prov in coastal_provs
                if is_fleet:
                    adj_list = list(state.fleet_adj_matrix.get(prov, []))
                elif utype in ('A', 'AMY'):
                    adj_list = [a for a in state.adj_matrix.get(prov, [])
                                if a not in water_provs]
                else:
                    adj_list = list(state.adj_matrix.get(prov, []))

                last_adj = -1
                for adj in sorted(adj_list):
                    if adj == last_adj:
                        continue
                    last_adj = adj
                    if is_fleet and is_coastal:
                        state.g_mc_fleet_pressure[unit_power, adj] += group_weight
                    else:
                        state.g_mc_province_pressure[unit_power, adj] += group_weight

        # ── Phase (h): EvaluateAllianceScore — called once per candidate ──────
        # C: line 1069 — EvaluateAllianceScore(this, param_1, local_b08).
        # The third argument is the per-candidate trial weight computed above;
        # it is the band cutoff in that function's empty-province penalty pass.
        # Passed explicitly from 2026-08-12 (previously dropped, and the
        # callee substituted win_threshold).
        evaluate_alliance_score(state, power, local_b08)

        # ── Phase (i): store per-candidate result ─────────────────────────────
        # C: lines 1071–1101 — puVar5[9] = new_score; average with previous if
        # trial_counter > 0; store round count.
        # For rounds after zero C averages the new result with candidate field
        # 9, i.e. the preceding live alliance score.
        old_score = int(c.get('score', 0))
        new_score = (int(state.g_alliance_desirability[power])
                     if power < len(state.g_alliance_desirability) else 0)
        avg_score = (old_score // 2 + new_score // 2) if trial_counter > 0 else new_score
        c['alliance_score'] = new_score
        c['alliance_score_avg'] = avg_score
        c['round_count'] = trial_counter
        # UpdateAllyOrderScore writes the new alliance score to candidate field
        # 9, while field 8 retains EvaluateOrderScore for the next reset.
        c.setdefault('base_score', c.get('score', 0))
        c['score'] = new_score

        # C also writes two PER-ROUND slots (decompile 1092-1098):
        #   puVar5[trial_counter + 0x35] = new_score
        #   puVar5[trial_counter + 0x53] = avg_score
        # _rank_candidates_for_power's Pareto filter reads exactly these —
        # trial_scores[t] across t = 0..trial_counter, and the current
        # round's 0x53 slot as the tie-break dimension.  Without them every
        # comparison was 0-vs-0 and nothing could ever be dominated.
        # Added 2026-08-12.
        trial_scores = c.setdefault('trial_scores', [])
        while len(trial_scores) <= trial_counter:
            trial_scores.append(0)
        trial_scores[trial_counter] = new_score
        c['final_dim_score'] = avg_score

    # C tail-call: FUN_00424850((int *)param_1, '\x01').  This is not a
    # conviction/deceit dispatcher as previously assumed — it is
    # RankCandidatesForPower, already ported as _rank_candidates_for_power for
    # the param_2 == '\0' call site in BuildAndSendSUB.  It prunes dominated
    # candidates, assigns each survivor a share of the remaining probability
    # mass, and writes the per-candidate selection probability the order
    # picker consumes.  Wired up 2026-08-12 (was a documented no-op).
    from ..bot.analysis import _rank_candidates_for_power
    _rank_candidates_for_power(state, power, flag=1)


def _refresh_order_table(state: InnerGameState, power: int) -> None:
    """
    Port of RefreshOrderTable (FUN_00424490).

    Populates g_current_best_order[power] with 30 complete candidate order
    sets using RefreshOrderTable.c's score-ordered rejection walk.

    The C code sorts candidates by the integer conversion of
    RankCandidatesForPower's weight, walks that tree from greatest to least,
    and compares a 0..999 MSVC-rand draw against a complement threshold.
    First-slot SC gates abort that walk and use the first tree element.

    Fix 2026-04-20 (M-MC-3): previously wrote to g_order_table (wrong target)
    and missed the SC threshold gates entirely.
    """
    import random

    candidates = [c for c in state.g_candidate_record_list if c.get('power') == power]
    if not candidates:
        return

    # C's temporary tree holds a pair of pointers to each candidate record;
    # each DAT_00bbf690/694 slot therefore selects the candidate's complete
    # order list.  Do not flatten unit orders across candidates: that creates
    # hybrid sets which never existed in any trial.
    candidate_pool: list = []  # [(complete_order_set, integer_weight, insertion_idx), ...]
    for insertion_idx, c in enumerate(candidates):
        # RefreshOrderTable.c inserts FloatToInt64(candidate[0x16]) into its
        # temporary tree.  RankCandidatesForPower writes that field; Python
        # binds it as ``weight``.  ``pressure_cost`` is local_c10's input and
        # must not bypass the ranker's probability calculation here.
        # FloatToInt64 truncates toward zero.  Preserve negative and >1000
        # values here; the C tree key is not clamped.
        selection_weight = int(float(c.get('weight', 0)))
        orders = c.get('orders', [])
        if isinstance(orders, (list, tuple)) and orders:
            candidate_pool.append((orders, selection_weight, insertion_idx))

    if not candidate_pool:
        return

    # FUN_00419fa0 stores the integer weight as the ordered-map key.  Its
    # comparator body is not present in Source; the surrounding selection
    # arithmetic is coherent with the established descending traversal (zero
    # weight records form the terminal fallback band).  Equal-key order also
    # remains unavailable, so retain insertion order as the stable analogue.
    candidate_pool.sort(key=lambda entry: (-entry[1], entry[2]))

    # SC threshold gates (C:157-186).  On slot zero, a failing gate breaks the
    # traversal and the post-loop fallback selects the tree's first element.
    own_power = int(getattr(state, 'albert_power_idx', 0))
    war_mode = getattr(state, 'g_war_mode_flag', 0)
    press_flag = getattr(state, 'g_press_flag', 0)
    sc_cnt = int(state.sc_count[power]) if power < len(state.sc_count) else 0

    def _passes_sc_gate(selection_weight: int, slot_idx: int) -> bool:
        """Return False when C breaks to the first-tree-element fallback."""
        if slot_idx != 0:
            return True
        # Gate 1: war mode AND not own power → reject if score < 50
        if war_mode == 1 and own_power != power:
            if selection_weight < 50:
                return False
        # Gate 2: SC count < 4 AND press off → reject if score < 50
        if sc_cnt < 4 and press_flag == 0:
            if selection_weight < 50:
                return False
        # Gate 3: SC count < 6 → reject if score < 20
        if sc_cnt < 6:
            if selection_weight < 20:
                return False
        return True

    # Fill 30 slots via the C rejection walk.
    _MAX_SLOTS = 30
    result_orders: list = []

    for slot_idx in range(_MAX_SLOTS):
        first = candidate_pool[0]
        sel = first
        previous_weight = 0.0  # local_58

        # The decompiled loop always looks one node ahead.  Reaching end does
        # not select the terminal node; control falls through to `*head`, the
        # first tree element.  This is why a terminal zero-weight band behaves
        # like a sentinel/fallback in the original.
        for idx, entry in enumerate(candidate_pool[:-1]):
            current_weight = int(entry[1])
            next_weight = int(candidate_pool[idx + 1][1])
            if current_weight < 1 or next_weight < 1:
                complement = 0.0
            else:
                complement = float(1000 - current_weight) - previous_weight

            # C draws count=(rand()/23)%3 + 1 and retains only the final draw.
            draw_count = (random.randint(0, 0x7fff) // 0x17) % 3 + 1
            roll = 0
            for _ in range(draw_count):
                roll = (random.randint(0, 0x7fff) // 0x17) % 1000

            # Decompiled condition `fVar1 < roll != (fVar1 == roll)` is the
            # compiler's unordered-aware spelling of fVar1 <= roll.  That
            # exits to the common selection label with the current iterator.
            if complement <= float(roll):
                sel = entry
                break

            # C applies all three slot-zero gates to the look-ahead node
            # (ppiVar5[3]), not the current candidate.
            if not _passes_sc_gate(next_weight, slot_idx):
                sel = first
                break

            previous_weight += float(current_weight)

        result_orders.append(copy.deepcopy(list(sel[0])))

    # Write to g_current_best_order (DAT_00bbf690/94) — NOT g_order_table.
    state.g_current_best_order[power] = result_orders


def update_score_state(state: InnerGameState) -> None:
    """
    Port of UpdateScoreState (FUN_0044c8e0).

    Two-phase order-table refresh.  For each power that has an active alliance
    (g_unit_count[power] > 0) whose per-power game-board record predates
    g_current_round:

      Pass 1 → UpdateAllyOrderScore (FUN_00442770)
      Pass 2 → RefreshOrderTable    (FUN_00424490)

    Semantics: "stale" means the game board recorded a different round for
    this power than the current simulation round, so its order table needs
    refreshing before the next trial.

    Research.md §5323.
    """
    num_powers = len(state.g_unit_count)

    # Pass 1 — update ally order scores for stale-round powered alliances
    for power in range(num_powers):
        if state.g_unit_count[power] <= 0:
            continue
        power_round = state.g_power_round_record.get(power, 0)
        if power_round != state.g_current_round:
            _update_ally_order_score(state, power)

    # Pass 2 — refresh order table entries for the same stale powers
    for power in range(num_powers):
        if state.g_unit_count[power] <= 0:
            continue
        power_round = state.g_power_round_record.get(power, 0)
        if power_round != state.g_current_round:
            _refresh_order_table(state, power)


# ── CheckTimeLimit ────────────────────────────────────────────────────────────

def check_time_limit(state: InnerGameState) -> bool:
    """
    Port of CheckTimeLimit (CheckTimeLimit).

    In the original binary: mutex-protected read of
    g_network_state->field_0x20 (the MTL timeout flag set by the timer thread
    when the Move Time Limit fires).  Returns True if time has expired.

    Python equivalent: reads state.mtl_expired directly (GIL guarantees
    atomicity for simple int reads; no additional lock needed).

    Research.md §5358.
    """
    return int(getattr(state, 'mtl_expired', 0)) != 0
