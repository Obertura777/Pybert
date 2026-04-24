"""Outbound press senders, proposal builders, and press-dispatch loop.

Extracted from ``communications.py`` during the 2026-04 structural refactor.
Behaviour preserved verbatim; only organisation changed.

Contents (by broad role):

* Alliance / ordinary press senders
    - ``send_alliance_press``                    (FUN_00417db0)
    - ``emit_xdo_proposals_to_broadcast``        (XDO_SUP → DAIDE wire tokens)
    - ``score_order_candidates_from_broadcast``  (broadcast-order scoring)

* Per-turn proposals
    - ``propose_dmz``                            (FUN_00432960)
    - ``friendly``                               (FUN_00418100 — peace-signal step)
    - ``_friendly_peace_signal_check``           (FUN_00418100 inner helper)
    - ``_update_relation_history``               (FUN_00417e90 / per-turn bookkeeping)

* Press-queue lifecycle
    - ``cancel_prior_press``                     (FUN_00419060)
    - ``_prepare_ally_press_entry``              (FUN_00418db0 — de-dup THN queue)
    - ``dispatch_press_and_fallback_gof``        (GenerateAndSubmitOrders loop)
    - ``_is_game_active``                        (FUN_0046ec10 gate helper)
    - ``_check_server_reachable``                (FUN_004117d0 wrapper for dispatch)

Module-level dependencies are plain imports (no deferred imports required) —
the senders slice is fully self-contained with respect to other submodules in
``albert.communications``.
"""

import re
import time as _time

from ..state import InnerGameState
from ..monte_carlo import check_time_limit
from .parsers import _parse_xdo_body_to_order
from .scheduling import _fun_004117d0, dispatch_scheduled_press

# ── SendAlliancePress ─────────────────────────────────────────────────────────

def send_alliance_press(
    state: 'InnerGameState',
    key: int,
    entry_data: dict | None = None,
) -> dict:
    """
    Port of SendAlliancePress (named symbol; address not confirmed beyond call site).

    C signature (thiscall on g_BroadcastList proxy DAT_00bb65ec):
        void __thiscall SendAlliancePress(void *this,
                                          undefined4 *param_1,
                                          int *param_2)

    The function body is MSVC ``std::set<ProposalRecord>::insert``:

    1. Load header sentinel: ``ppiVar4 = *(this+4)`` — i.e. ``_Myhead``.
    2. If root (``_Myhead[1]``) is not nil (``+0xe9 != 0``):
         Binary search from root, branching left when
         ``*param_2 < node[4]`` (int comparison on the key field at
         byte offset 16 of the proposal node), right otherwise.
         Loop terminates when next node is nil.
    3. Call ``FUN_0042e450(this, &go_left, go_left, parent, param_2)``
         — MSVC ``_Tree::_Insert``: allocates a new node, splices it
         in, and rebalances the red-black tree.
    4. Write result to ``param_1``: ``[node_ptr][secondary][inserted=1]``.
         Note: the bool is **hardcoded 1** — the caller does not need
         duplicate-detection; every call inserts a fresh entry.

    Python absorption
    -----------------
    * ``g_BroadcastList`` is a plain Python ``list`` (no tree structure).
    * The lower-bound search is replicated as a linear scan by ``key``.
    * ``FUN_0042e450`` (RB-tree node allocator + rebalancer) is absorbed
      into ``list.insert``.
    * The ``pair<iterator,bool>`` output is absorbed into the return value.

    Parameters
    ----------
    state      : InnerGameState
    key        : int — sort key (``*param_2`` / ``node[4]``; in the
                 BuildAndSendSUB press-deal loop this is the target
                 power index).
    entry_data : optional dict of extra fields to merge into the new
                 entry (province_set, press_seq, power, …).

    Returns
    -------
    The newly inserted entry dict (always inserted — bool result = 1).

    Callees (absorbed):
        FUN_0042e450  — MSVC _Tree::_Insert (node alloc + RB rebalance)
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    entry: dict = {
        'key':         key,
        'sent':        False,   # node+24 / node[6] — not yet dispatched
        'type_flag':   0,       # node+28 / node[7]
        'trial_count': 0,       # node+32 / node[8]
        # AllianceRecord score vector at +0x48 (C: int[≥7], indexed by power).
        # CAL_VALUE uses current.score[own] − predecessor.score[own] for the
        # delta classification that drives YES/REJ/BWX/HUH verdict bands.
        'score_vector': [0] * 7,
        # AllianceRecord +0x9c history flag (C: `[0x27] as undefined4*`).
        # CAL_VALUE preflight gate: must be >= 1 to use the diff-form delta,
        # else fall back to absolute current.score[own].
        'history_flag': 0,
    }
    if entry_data:
        entry.update(entry_data)

    bl: list = state.g_BroadcastList

    # lower_bound: first position where existing key >= new key
    insert_pos = len(bl)
    for i, node in enumerate(bl):
        if node.get('key', 0) >= key:
            insert_pos = i
            break

    bl.insert(insert_pos, entry)

    _log.debug(
        "send_alliance_press: inserted key=%d into g_BroadcastList at pos %d "
        "(list now %d entries)",
        key, insert_pos, len(bl),
    )
    return entry


# ── XDO proposal emission ────────────────────────────────────────────────────

def emit_xdo_proposals_to_broadcast(state: 'InnerGameState') -> int:
    """
    Convert accumulated g_XdoPressProposals into g_BroadcastList entries.

    In the C binary, BuildSupportProposals (FUN_0043e370) both builds the
    proposal records AND emits them as XDO(SUP(...)) token sequences into the
    broadcast list (via FUN_00466f80(&XDO, ...) + AppendList, lines 396–427).
    The Python port splits these concerns: ``build_support_proposals``
    populates ``g_XdoPressProposals`` and this function performs the emission.

    Each proposal dict has::

        {'type': 'XDO_SUP', 'supporter_prov': int, 'supporter_power': int,
         'mover_prov': int, 'dest': int, 'from_power': int, 'to_power': int,
         'priority': int, 'key': int}

    We convert these into g_BroadcastList entries with ``order_candidates``
    lists whose tokens follow the DAIDE XDO(SUP ...) pattern that
    ``_parse_xdo_body_to_order`` can consume downstream.

    Returns the number of proposals emitted.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    proposals = getattr(state, 'g_XdoPressProposals', None)
    if not proposals:
        return 0

    _POWER_NAMES = ['AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
    id_to_prov = state._id_to_prov
    if not id_to_prov:
        id_to_prov = {v: k for k, v in state.prov_to_id.items()}

    emitted = 0
    for prop in proposals:
        if prop.get('type') != 'XDO_SUP':
            continue

        sup_prov  = int(prop['supporter_prov'])
        sup_power = int(prop['supporter_power'])
        mov_prov  = int(prop['mover_prov'])
        dest_prov = int(prop['dest'])
        from_pow  = int(prop['from_power'])

        # Resolve province names
        sup_name = id_to_prov.get(sup_prov, str(sup_prov))
        mov_name = id_to_prov.get(mov_prov, str(mov_prov))
        dst_name = id_to_prov.get(dest_prov, str(dest_prov))

        # Determine unit types
        sup_info = state.unit_info.get(sup_prov, {})
        mov_info = state.unit_info.get(mov_prov, {})
        sup_type = 'FLT' if sup_info.get('type') == 'F' else 'AMY'
        mov_type = 'FLT' if mov_info.get('type') == 'F' else 'AMY'

        # Power tokens
        sup_pow_tok = _POWER_NAMES[sup_power] if 0 <= sup_power < 7 else 'UNO'
        from_pow_tok = _POWER_NAMES[from_pow] if 0 <= from_pow < 7 else 'UNO'

        # Build DAIDE XDO(SUP_MTO) token sequence:
        # XDO ( ( POWER UNIT_TYPE PROV ) SUP ( POWER UNIT_TYPE PROV ) MTO DEST )
        tokens = [
            'XDO', '(',
            '(', sup_pow_tok, sup_type, sup_name, ')',
            'SUP',
            '(', from_pow_tok, mov_type, mov_name, ')',
            'MTO', dst_name,
            ')',
        ]

        # Build g_BroadcastList entry (matches format consumed by
        # score_order_candidates_from_broadcast).
        key = prop.get('key', sup_prov * 1000000 + mov_prov * 1000 + dest_prov)
        entry = {
            'key':              key,
            'sent':             True,
            'type_flag':        1,       # 1 = self-generated (vs 0 = received)
            'trial_count':      0,
            'score_vector':     [0] * 7,
            'history_flag':     0,
            'order_candidates': [{'tokens': tokens, 'type_flag': 1}],
        }

        bl = state.g_BroadcastList
        # Insert sorted by key (C: lower_bound insertion)
        insert_pos = len(bl)
        for i, node in enumerate(bl):
            if node.get('key', 0) >= key:
                insert_pos = i
                break
        bl.insert(insert_pos, entry)
        emitted += 1

    if emitted:
        _log.debug(
            "emit_xdo_proposals: emitted %d SUP proposals into g_BroadcastList "
            "(list now %d entries)",
            emitted, len(state.g_BroadcastList),
        )

    # Clear consumed proposals (they've been emitted).
    state.g_XdoPressProposals.clear()
    return emitted


def score_order_candidates_from_broadcast(state: "InnerGameState") -> int:
    """
    Python port of ScoreOrderCandidates' writer loop
    (Source/ScoreOrderCandidates.c, lines 217–294).

    Walks state.g_BroadcastList (DAT_00bb65ec) and projects each entry's
    parsed XDO order_candidates into:

      * state.g_GeneralOrders[power]   (≡ DAT_00bb6cf8 + power*0xc) —
        unconditional general-orders set; consulted by MC sub-pass 1c
        unconditional second pass.
      * state.g_AllianceOrders[power]  (≡ DAT_00bb65f8 + power*0xc) —
        alliance-orders set; consulted by MC sub-pass 1c first pass when
        the proposer is the own power or a trusted ally.

    Trust gate for the alliance set mirrors the dispatch_first_pass
    decision in monte_carlo.process_turn (~line 1091): own power, or
    g_AllyTrustScore_Hi > 0, or (Hi >= 0 and Lo > 2).

    Returns the number of order_records inserted (sum across both sets).
    Designed to be safe to call multiple times — callers that want
    fresh state should clear g_GeneralOrders / g_AllianceOrders first.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    bl = getattr(state, 'g_BroadcastList', None)
    if not bl:
        return 0

    if not hasattr(state, 'g_GeneralOrders'):
        state.g_GeneralOrders = {}
    if not hasattr(state, 'g_AllianceOrders'):
        state.g_AllianceOrders = {}

    own_power = getattr(state, 'own_power_index', None)
    if own_power is None:
        own_power = getattr(state, 'albert_power_idx', 0)
    own_power = int(own_power)

    inserted = 0
    seen_keys: set = set()  # de-dup absorption of the C std::set semantics
    for entry in bl:
        if not isinstance(entry, dict):
            continue
        cands = entry.get('order_candidates') or []
        for cand in cands:
            tokens = cand.get('tokens') if isinstance(cand, dict) else None
            if not tokens:
                continue
            parsed = _parse_xdo_body_to_order(tokens)
            if parsed is None:
                _log.debug(
                    "score_order_candidates: skipped unparseable XDO %r",
                    tokens,
                )
                continue
            power_idx, order_seq = parsed

            # De-dup key: (power, type, unit, target?, target_unit?, target_dest?)
            key = (
                power_idx,
                order_seq.get('type'),
                order_seq.get('unit'),
                order_seq.get('target'),
                order_seq.get('target_unit'),
                order_seq.get('target_dest'),
            )
            if key in seen_keys:
                continue
            seen_keys.add(key)

            state.g_GeneralOrders.setdefault(power_idx, []).append(order_seq)
            inserted += 1

            # Alliance gate.
            is_ally_first_pass = False
            if power_idx == own_power:
                is_ally_first_pass = True
            else:
                try:
                    trust_lo = int(state.g_AllyTrustScore[own_power, power_idx])
                    trust_hi = int(state.g_AllyTrustScore_Hi[own_power, power_idx])
                    if trust_hi > 0 or (trust_hi >= 0 and trust_lo > 2):
                        is_ally_first_pass = True
                except Exception:
                    pass
            if is_ally_first_pass:
                state.g_AllianceOrders.setdefault(power_idx, []).append(order_seq)
                inserted += 1

    if inserted:
        _log.debug(
            "score_order_candidates: inserted %d order_records "
            "(general slots: %s, alliance slots: %s)",
            inserted,
            sorted(state.g_GeneralOrders.keys()),
            sorted(state.g_AllianceOrders.keys()),
        )
    return inserted


# ── ProposeDMZ ────────────────────────────────────────────────────────────────

def propose_dmz(state: InnerGameState,
                ally_power: int,
                send_fn=None) -> bool:
    """
    Port of ProposeDMZ (FUN_00432960).

    Iterates g_OrderList looking for contested provinces and sends DMZ
    proposals to *ally_power* via DAIDE PRP(DMZ(...)) press.

    Returns True if at least one proposal was sent.

    Three message types (research.md §1381):
      ≥2 contested  → PRP ( DMZ ( own ally ) prov1 prov2 … )
      1 bilateral   → PRP ( DMZ ( own ally ) prov )
      1 unilateral  → PRP ( DMZ ally prov )

    g_DMZAggressiveness = DAT_004c6bd4/4 − 4 ∈ [−4, 20] (randomised per game).
    Proposals to the same (power, province) pair are capped at 2.

    Research.md §1381.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("ProposeDMZ: %s", msg))

    own_power = getattr(state, 'albert_power_idx', 0)
    threshold = int(getattr(state, 'g_DMZAggressiveness', 0))
    sent = False

    contested: list = []   # entries with flag1=1

    for entry in getattr(state, 'g_OrderList', []):
        if entry.get('done', False):
            continue
        province  = int(entry.get('province', -1))
        flag1     = bool(entry.get('flag1', False))
        flag2     = bool(entry.get('flag2', False))
        flag3     = bool(entry.get('flag3', False))
        score     = int(entry.get('score', 0))

        if province < 0 or not flag1:
            continue

        # Cap per (power, province) at 2 proposals
        key = (ally_power, province)
        if state.g_SentProposals.get(key, 0) >= 2:
            continue

        if score < threshold:
            continue

        contested.append({'province': province, 'flag2': flag2, 'flag3': flag3})

    if len(contested) >= 2:
        provinces = [c['province'] for c in contested]
        prov_str = ' '.join(str(p) for p in provinces)
        msg = f"PRP ( DMZ ( {own_power} {ally_power} ) {prov_str} )"
        _send(msg)
        for c in contested:
            key = (ally_power, c['province'])
            state.g_SentProposals[key] = state.g_SentProposals.get(key, 0) + 1
        sent = True

    elif len(contested) == 1:
        c = contested[0]
        province = c['province']
        key = (ally_power, province)
        if c['flag2'] and not c['flag3']:
            msg = f"PRP ( DMZ ( {own_power} {ally_power} ) {province} )"
        else:
            msg = f"PRP ( DMZ {ally_power} {province} )"
        _send(msg)
        state.g_SentProposals[key] = state.g_SentProposals.get(key, 0) + 1
        sent = True

    # Mark proposed entries as done
    if sent:
        proposed_provs = {c['province'] for c in contested}
        for entry in state.g_OrderList:
            if int(entry.get('province', -1)) in proposed_provs:
                entry['done'] = True

    return sent


# ── UpdateRelationHistory ────────────────────────────────────────────────────

def _update_relation_history(state: InnerGameState) -> None:
    """
    Port of UpdateRelationHistory (FUN_0040d7e0).

    Enforces a _safe_pow(1.8, trust_lo/10) minimum floor on every positive
    g_AllyTrustScore[row][col] entry.  Called by friendly() (always) and by
    _hostility() when g_PressFlag==0 or g_NearEndGameFactor>3.0.

    The C function stores trust as a 64-bit int split into lo (puVar6[0]) and
    hi (puVar6[1]) uint words.  The floor is computed as:
        floor64 = int64(pow(1.8, trust_lo // 10))
        floor_lo = floor64 & 0xFFFFFFFF
        floor_hi = arithmetic_right_shift_31(floor_lo)   # 0 for positive values

    Trust is raised to floor when (trust_hi, trust_lo) < (floor_hi, floor_lo)
    in 64-bit lexicographic order.  Both words are updated on raise.
    """
    num_powers = 7
    for row in range(num_powers):
        for col in range(num_powers):
            trust_lo = int(state.g_AllyTrustScore[row, col])
            trust_hi = int(state.g_AllyTrustScore_Hi[row, col])
            # Guard: trust > 0 — C: (-1 < trust_hi) AND (0 < trust_hi OR trust_lo != 0)
            if not (trust_hi >= 0 and (trust_hi > 0 or trust_lo != 0)):
                continue
            floor64  = int(1.8 ** (trust_lo // 10))
            floor_lo = floor64 & 0xFFFFFFFF
            # C: uVar4 = (int)uVar3 >> 0x1f  — arithmetic shift, 0 for positive values
            floor_hi = -1 if (floor_lo >> 31) else 0
            # 64-bit comparison: (trust_hi, trust_lo) < (floor_hi, floor_lo)
            if trust_hi <= floor_hi and (trust_hi < floor_hi or trust_lo < floor_lo):
                state.g_AllyTrustScore[row, col]    = floor_lo
                state.g_AllyTrustScore_Hi[row, col] = floor_hi


# ── FRIENDLY ─────────────────────────────────────────────────────────────────

def friendly(state: InnerGameState) -> None:
    """
    Port of FRIENDLY (FUN_0042dc40).

    Per-turn power×power relationship update engine called from
    GenerateAndSubmitOrders between PhaseHandler(1) and PhaseHandler(2).

    Three phases (research.md §4364 / decompiled.txt):
      Phase 1 — update g_RelationScore for each (row, col) power pair
      Phase 2 — UpdateRelationHistory (FUN_0040d7e0)
      Phase 3 — upgrade/downgrade g_AllyMatrix based on trust thresholds
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)
    season     = getattr(state, 'g_season', 'SPR')
    season_rewards = season in ('FAL', 'WIN')

    # Phase 1 — per-power-pair relationship score update
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue

            # Eliminated power: zero out trust/relation for BOTH [row,col] and [col,row].
            # The reverse-direction clear pre-zeros pairs that won't reach the eliminated
            # branch when row=eliminated (since the check is on col's sc_count, not row's).
            if int(state.sc_count[col]) == 0:
                state.g_AllyTrustScore[row, col]    = 0
                state.g_AllyTrustScore_Hi[row, col] = 0
                state.g_TrustExtended_Lo[row, col]  = 0
                state.g_TrustExtended_Hi[row, col]  = 0
                state.g_RelationScore[row, col]      = 0
                # symmetric clear (*piVar3 / iStack_34 writes in decompiled)
                state.g_AllyTrustScore[col, row]    = 0
                state.g_AllyTrustScore_Hi[col, row] = 0
                state.g_TrustExtended_Lo[col, row]  = 0
                state.g_TrustExtended_Hi[col, row]  = 0
                state.g_RelationScore[col, row]      = 0
                continue

            stab      = int(state.g_StabFlag[row, col])
            cease     = int(state.g_CeaseFire[row, col])
            # g_CoopScoreFlag_B (DAT_0062be98) — fall/autumn cooperation flag
            # g_CoopScoreFlag_A (DAT_0062c580) — spring/summer cooperation flag
            # Both are tested in the FRIENDLY conjunction (C: FRIENDLY.c:123-124)
            # regardless of season.  Previously read the phantom names
            # g_CoopFlag / g_SomeCoopScore, which were never populated.
            coop      = int(state.g_CoopScoreFlag_B[row, col])
            some_coop = int(state.g_CoopScoreFlag_A[row, col])
            trust_lo  = int(state.g_AllyTrustScore[row, col])
            trust_hi  = int(state.g_AllyTrustScore_Hi[row, col])
            peace_sig = int(state.g_PeaceSignal[row, col])
            neutral   = int(state.g_NeutralFlag[row, col])
            relation  = int(state.g_RelationScore[row, col])
            rel_sym   = int(state.g_RelationScore[col, row])
            rank      = int(state.g_InfluenceRankFlag[row, col])
            stab_n    = int(state.g_StabCounter[row, col])

            if stab == 1:
                # Two-path stab penalty based on relation levels and influence rank.
                # Low-score path: at least one relation < 10 AND rank < 4
                if (rel_sym < 10 or relation < 10) and rank < 4:
                    if rel_sym > 4 and relation > 4:
                        # Both scores > 4: normal penalty n*-10-10, applied symmetrically
                        penalty  = stab_n * (-10) - 10
                        relation = max(relation + penalty, -50)
                        rel_sym  = max(rel_sym  + penalty, -50)
                        state.g_RelationScore[row, col] = relation
                        state.g_RelationScore[col, row] = rel_sym
                        state.g_StabCounter[row, col]   += 1
                    else:
                        # At least one score ≤ 4: zero both directions
                        state.g_RelationScore[row, col] = 0
                        state.g_RelationScore[col, row] = 0
                else:
                    # High-score / high-rank stab: larger penalty n*-20-70
                    penalty  = stab_n * (-20) - 70
                    relation = max(relation + penalty, -50)
                    rel_sym  = max(rel_sym  + penalty, -50)
                    state.g_RelationScore[row, col] = relation
                    state.g_RelationScore[col, row] = rel_sym
                    state.g_StabCounter[row, col]   += 1
                    # Clear betrayal counters for own power's other allies (cancel pending peace)
                    if row == own_power:
                        for k in range(num_powers):
                            if k != col:
                                state.g_BetrayalCounter[k] = 0
                _log.debug("FRIENDLY: stab (%d,%d) → rel=%d sym=%d",
                           row, col,
                           int(state.g_RelationScore[row, col]),
                           int(state.g_RelationScore[col, row]))

            elif cease == 1:
                # Cease-fire: cap both directions at 0
                if relation > 0:
                    state.g_RelationScore[row, col] = 0
                if rel_sym > 0:
                    state.g_RelationScore[col, row] = 0

            elif stab == 0 and coop == 0 and some_coop == 0 and season_rewards:
                # Normal relationship update (FAL/WIN only).
                # "Alliance confirmed" path requires: trust > 0 AND peace_signal == 1
                # AND neutral == 0 AND relation ≤ 49.
                alliance = (trust_hi >= 0 and (trust_hi >= 1 or trust_lo != 0) and
                            peace_sig == 1 and neutral == 0 and relation <= 49)

                if not alliance:
                    # Block A: symmetric partner has active trust, no peace signal → +5
                    sym_hi = int(state.g_AllyTrustScore_Hi[col, row])
                    sym_lo = int(state.g_AllyTrustScore[col, row])
                    if (sym_hi >= 0 and (sym_hi > 0 or sym_lo != 0) and
                            peace_sig == 0 and relation < 50):
                        relation += 5
                        state.g_RelationScore[row, col] = min(relation, 50)
                        if row == own_power:
                            _friendly_peace_signal_check(state, col, trust_lo, trust_hi,
                                                         neutral, peace_sig, relation, _log)
                    else:
                        # Block B: trust/neutral flags present, or relation < 0, or deceit < 2
                        b_cond = (trust_lo != 0 or trust_hi != 0 or neutral != 0 or
                                  relation < 0 or state.g_DeceitLevel < 2)
                        if b_cond:
                            if trust_lo == 0 and trust_hi == 0 and relation < 0:
                                # Organic recovery: +10, capped at 0
                                relation += 10
                                if relation > 0:
                                    relation = 0
                                state.g_RelationScore[row, col] = relation
                            elif (trust_lo == 0 and trust_hi == 0 and
                                  relation > 0 and neutral == 1):
                                # Neutral+positive: reset to 0
                                state.g_RelationScore[row, col] = 0
                        else:
                            # Block C: set tentative trust (row != own_power only)
                            if row != own_power:
                                state.g_AllyTrustScore[row, col]    = 1
                                state.g_AllyTrustScore_Hi[row, col] = 0
                                state.g_RelationScore[row, col]     = 0
                            else:
                                # LAB_0042df19: own_power — peace signal dispatch
                                _friendly_peace_signal_check(state, col, trust_lo, trust_hi,
                                                             neutral, peace_sig, relation, _log)

                    if int(state.g_RelationScore[row, col]) > 50:
                        state.g_RelationScore[row, col] = 50

                else:
                    # Block D: alliance confirmed — accumulate relation (+5 deceitful, +10 honest)
                    gain = 5 if state.g_DeceitLevel == 1 else 10
                    state.g_RelationScore[row, col] = relation + gain
                    if row == own_power:
                        _friendly_peace_signal_check(state, col, trust_lo, trust_hi,
                                                     neutral, peace_sig, relation, _log)
                    if int(state.g_RelationScore[row, col]) > 50:
                        state.g_RelationScore[row, col] = 50

    # Phase 2 — UpdateRelationHistory (FUN_0040d7e0).
    _update_relation_history(state)

    # Phase 3 — g_AllyMatrix alliance state transitions.
    # trust_hi < 0 OR (trust_hi < 1 AND trust_lo < 5) → downgrade full (2) → tentative (1)
    # otherwise → upgrade tentative (1) → full (2)
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = int(state.g_AllyTrustScore[row, col])
            trust_hi = int(state.g_AllyTrustScore_Hi[row, col])
            ally_val = int(state.g_AllyMatrix[row, col])
            if trust_hi < 0 or (trust_hi < 1 and trust_lo < 5):
                if ally_val == 2:
                    state.g_AllyMatrix[row, col] = 1   # full → tentative
            else:
                if ally_val == 1:
                    state.g_AllyMatrix[row, col] = 2   # tentative → full


def _friendly_peace_signal_check(state: InnerGameState, col: int,
                                  trust_lo: int, trust_hi: int,
                                  neutral: int, peace_sig: int,
                                  relation: int, _log) -> None:
    """LAB_0042df19 sub-routine: clear betrayal counter AND send peace
    press when own power receives a peace signal.

    C (FRIENDLY.c lines 160-178) builds a press entry with token 0x19
    (PCE press type) and inserts it into g_BroadcastList via
    FUN_0041c450 (SendAlliancePress).  The Python version was missing
    the press-sending half.  Fixed 2026-04-20 (audit finding M12).
    """
    if (trust_lo == 0 and trust_hi == 0 and neutral == 0 and
            peace_sig == 1 and relation >= 0):
        state.g_BetrayalCounter[col] = 0
        _log.debug("FRIENDLY: getting peace signal from power %d", col)

        # ── Press-sending (C: FRIENDLY.c lines 166-178) ──────────────
        # C builds token = col | 0x4100, sets uStack_4c = 0x19 (PCE
        # press type), then calls FUN_00410b40 → FUN_0041c450 to insert
        # into g_BroadcastList.  Mirror this as a send_alliance_press
        # call with type='PCE' so BuildAndSendSUB picks it up.
        peace_entry = {
            'type': 'PCE',
            'from_power_tok': col | 0x4100,
            'sublist3': [0x19],  # C: uStack_4c = 0x19
        }
        send_alliance_press(state, key=len(state.g_BroadcastList),
                            entry_data=peace_entry)


# ── CancelPriorPress ──────────────────────────────────────────────────────────

def cancel_prior_press(state: InnerGameState,
                       own_power: int,
                       send_fn=None) -> None:
    """
    Port of CancelPriorPress (FUN_0040e8e0).

    Sends NOT(g_prior_press_token) via SendDM to withdraw a prior press
    proposal.  Guarded by g_cancel_press_sent (once-per-turn flag).
    Fires when:
      - curr_sc_cnt[own_power] > 0, OR
      - reconnect flag is set (param_1+8+0x24bc in original)

    Research.md §1319 / §2570 note.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("CancelPriorPress: %s", msg))

    # Once-per-turn guard
    if getattr(state, 'g_cancel_press_sent', 0) == 1:
        return

    token = getattr(state, 'g_prior_press_token', None)
    if token is None:
        return

    own_sc = int(state.sc_count[own_power]) if hasattr(state, 'sc_count') else 1
    reconnect = bool(getattr(state, 'g_reconnect_flag', False))

    if own_sc > 0 or reconnect:
        msg = f"NOT ( {token} )"
        _send(msg)
        state.g_cancel_press_sent = 1
        state.g_prior_press_token = None


# ── DispatchPressAndFallbackGOF ───────────────────────────────────────────────

def _is_game_active(state: InnerGameState) -> bool:
    """
    Port of FUN_00411740.

    When DAT_00baed46 (g_baed46) != 1: returns True unconditionally.
    When DAT_00baed46 == 1: iterates g_BroadcastList; if ANY proposal has its
    sent flag == 0 (not yet sent), returns False.  Returns True if all proposals
    have been sent (or the list is empty).

    C detail: puVar3 is undefined4*, so '*(char*)(puVar3 + 6)' is pointer
    arithmetic — offset = 6 * 4 = 24 bytes — reaching the sent_flag char at
    offset 24 of each proposal record (same field as puVar5[6] in
    BuildAndSendSUB).

    Callees: FUN_0047a948 = AssertFail (already documented);
             FUN_0040f470 = MSVC list iterator advance (see unchecked list).
    """
    if getattr(state, 'g_baed46', 0) != 1:
        return True
    for entry in getattr(state, 'g_BroadcastList', []):
        if not entry.get('sent', True):
            return False
    return True


def _check_server_reachable(state: InnerGameState, mode: int = -1) -> bool:
    """
    Port of FUN_004117d0(-1) called from dispatch_press_and_fallback_gof.

    Returns True (non-zero) when any unprocessed g_PosAnalysisList entry has
    had its board orders satisfied — used by the caller to decide whether to
    apply the time-window check before sending a fallback GOF.  If False, the
    caller sends GOF immediately without checking the time window.

    NOTE: the original stub described this as a TCP server-reachability check.
    The actual decompile shows it scans g_PosAnalysisList for board-order
    matches; the "reachable/unreachable" framing was a misinterpretation.  In
    the C game, unmatched proposals (False) trigger immediate fallback; matched
    proposals (True) cause the caller to wait up to base_wait+25 s first.

    In the current Python model power_count is always 0, so this always returns
    False → the time-window check is skipped and the fallback GOF fires as soon
    as the other guards (game active, processing idle) allow it.
    """
    return _fun_004117d0(state, mode)


def dispatch_press_and_fallback_gof(state: InnerGameState,
                                    param_1: object,
                                    send_fn=None) -> None:
    """
    Port of FUN_00443ed0.

    Dispatches pending scheduled press, waits while active game processing
    is in flight (DAT_00bb65c4 != 0), then polls until one of two conditions
    warrants a fallback bare GOF send:
      (a) server becomes unreachable  (FUN_004117d0(-1) returns 0), OR
      (b) elapsed time since session start > g_base_wait_time + 25 s.

    When the fallback GOF fires: records elapsed time into g_elapsed_press_time,
    sends "GOF" via SendDM, and clears the GOF-pending flag
    (DAT_00baed47 → g_cancel_press_sent = 0).

    Does nothing if g_cancel_press_sent != 1 (GOF not pending) at any check
    point.

    Called from BuildAndSendSUB at LAB_004591b3 (loop exit) as
    FUN_00443ed0(pvVar22).

    Global mapping:
      DAT_00bb65c4  → state.g_processing_active   (nonzero while game processes)
      DAT_00baed47  → state.g_cancel_press_sent    (1 = fallback GOF still needed)
      DAT_00ba2880/84 → state.g_turn_start_time     (int64 reference timestamp)
      DAT_00ba2858/5c → state.g_base_wait_time     (int64 base threshold seconds)
      DAT_00ba2860/64 → state.g_elapsed_press_time (int64 recorded elapsed time)

    Unchecked callees:
      FUN_00411740 → _is_game_active(state)
      FUN_004117d0 → _check_server_reachable(state, -1)
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda msg: _log.debug("dispatch_press_and_fallback_gof: %r", msg))

    # C: FUN_00465870(local_2c) — init empty token list (Python: implicit list)
    # C: ScheduledPressDispatch(param_1)
    dispatch_scheduled_press(state, _send)

    # ── Phase 1: flush press while processing active ──────────────────────────
    # C: while (DAT_00bb65c4 != 0)
    while getattr(state, 'g_processing_active', 0) != 0:
        # C: if (CheckTimeLimit()) break
        if check_time_limit(state):
            break
        # C: if (DAT_00baed47 != '\x01') goto LAB_004440b4
        if getattr(state, 'g_cancel_press_sent', 0) != 1:
            return
        # C: if (FUN_00411740() != '\x01') break
        if not _is_game_active(state):
            break
        _time.sleep(1)
        # C: ScheduledPressDispatch(param_1)
        dispatch_scheduled_press(state, _send)

    # ── Phase 2: poll until fallback GOF conditions are met ──────────────────
    # C: do { ... } while(true)
    session_start = float(getattr(state, 'g_turn_start_time', 0.0))
    base_wait     = float(getattr(state, 'g_base_wait_time',   0.0))

    while True:
        # C: if (DAT_00baed47 != '\x01') goto LAB_004440b4
        if getattr(state, 'g_cancel_press_sent', 0) != 1:
            return

        game_ok      = _is_game_active(state)
        time_expired = check_time_limit(state)
        processing   = getattr(state, 'g_processing_active', 0) != 0
        server_ok    = _check_server_reachable(state, -1)
        now          = _time.time()
        elapsed      = now - session_start
        time_over    = elapsed > base_wait + 25.0

        # C: outer if-condition triggers inner re-check block when any fail
        outer_trigger = (
            not game_ok
            or time_expired
            or processing
            or not server_ok
            or time_over
        )

        if outer_trigger:
            # ── Inner re-check (C mirrors all conditions before sending) ─────
            if getattr(state, 'g_cancel_press_sent', 0) != 1:
                return
            if not _is_game_active(state):
                return
            if check_time_limit(state):
                return
            if getattr(state, 'g_processing_active', 0) != 0:
                return

            # C: cVar3 = FUN_004117d0(-1); if (cVar3 != '\0') { time check }
            server_ok2 = _check_server_reachable(state, -1)
            if server_ok2:
                elapsed2 = _time.time() - session_start
                if elapsed2 <= base_wait + 25.0:
                    # C: goto LAB_004440b4 — still within window, do not send
                    return

            # ── Send fallback bare GOF ────────────────────────────────────────
            # C: _DAT_00ba2860 = __time64(0) - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)
            state.g_elapsed_press_time = _time.time() - session_start
            # C: FUN_00465f30(local_1c, &GOF) + AppendList + SendDM
            _send("GOF")
            _log.debug("Fallback bare GOF sent (elapsed=%.1fs)",
                       state.g_elapsed_press_time)
            # C: DAT_00baed47 = '\0'
            state.g_cancel_press_sent = 0
            return

        # C: Sleep(1000) — no trigger yet, keep polling
        _time.sleep(1)


def _prepare_ally_press_entry(state: "InnerGameState", power: int) -> None:
    """
    FUN_00418db0(power) — PrepareAllyPressEntry.

    Removes all pending THN(<power>) entries from g_MasterOrderList before a
    new press item is scheduled for that power, preventing duplicates.

    C logic (decompiled.txt lines 27–84):
      1. FUN_00465870(local_28)            — init temp token list.
         local_44[0] = power | 0x4100      — build DAIDE power token.
         FUN_00466ed0(&THN, local_38, local_44) → local_28 holds THN(<power>).
      2. Outer do-while: restart scan from g_MasterOrderList head each time.
         Inner while: iterate nodes; FUN_00465d90(node+6, &local_28) checks
         whether the node's token-seq equals THN(<power>).
         No match → advance iterator (FUN_0040e210).
         Scan exhausted (iter == sentinel) → FreeList + return.
         Match → AdvanceAndRemoveListNode removes the node; outer loop restarts.

    Python: token-list mechanics absorbed; equality check reduces to
    press_type == 'THN' and data == [power].
    """
    master: list = getattr(state, 'g_MasterOrderList', [])
    state.g_MasterOrderList = [
        e for e in master
        if not (e.get('press_type') == 'THN' and e.get('data') == [power])
    ]


