"""Per-token press evaluators (PCE / DMZ / ALY / SLO / DRW / NOT-PCE / NOT-DMZ / XDO).

Split from communications/evaluators.py during the 2026-04 refactor.

Holds the ``FUN_0042c040`` family of per-token scorers and the headline
``_cal_value`` XDO score function.  These are pure scorers — they read
``InnerGameState`` and return a DAIDE ack token (YES / REJ / BWX).

Public names (re-exported through the evaluators package facade):
  * ``_eval_pce``, ``_eval_dmz``, ``_eval_aly``,
    ``_eval_slo``, ``_eval_drw``,
    ``_eval_not_pce``, ``_eval_not_dmz``,
    ``_eval_sub_xdo``, ``_eval_single_xdo``  — per-token evaluators.
  * ``_split_xdo_clauses``, ``_cal_value``    — XDO clause split + headline score.

Cross-module deps: ``_common`` helpers (``_pow_idx``, ``_extract_powers``,
``_extract_provs``, ``_ally_trust_ok``) and ``..state.InnerGameState``.
"""

from ...state import InnerGameState
from ._common import (
    _pow_idx,
    _extract_powers,
    _extract_provs,
    _ally_trust_ok,
    _POWER_NAMES,
)


def _eval_pce(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0040d1a0 — PCE proposal evaluator.

    Iterates the power list in the PCE proposal.
    bVar1 = own power found, bVar2 = proposer found, bVar3 = no hostile powers.
    Returns:
      YES if bVar1 AND bVar2 AND bVar3
      REJ if bVar1 AND bVar2 AND NOT bVar3
      BWX otherwise (0x4A02 — "busy waiting", i.e. not applicable to us)
    Hostile = g_enemy_flag[p]==1 OR g_relation_score[own][p] < 0.

    C (_eval_pce.c:48) exempts the hostility test entirely when the proposal
    is a straight two-party PCE *and* the sender carries the deceit/active-turn
    flag DAT_00633768 (state.g_power_active_turn, set by the RESPOND deceit
    path).  Restored 2026-08-12 — the gate was previously unconditional, so a
    bilateral peace from such a sender was rejected where C accepts it.
    """
    _BWX = 0x4A02
    own = state.albert_power_idx
    bVar1 = bVar2 = False
    bVar3 = True

    powers = _extract_powers(rest)
    _active = getattr(state, 'g_power_active_turn', None)
    _sender_active = (
        _active is not None and 0 <= from_power < len(_active)
        and int(_active[from_power]) == 1
    )
    skip_hostility = (len(powers) == 2 and _sender_active)

    for p in powers:
        if p == own:
            bVar1 = True
        else:
            if p == from_power:
                bVar2 = True
            enemy_hi = int(getattr(state, 'g_enemy_flag_hi', [0] * 7)[p])
            if not skip_hostility and (
                    (int(state.g_enemy_flag[p]) == 1 and enemy_hi == 0)
                    or int(state.g_relation_score[own, p]) < 0):
                bVar3 = False
    if bVar1 and bVar2:
        return 0x481C if bVar3 else 0x4814   # YES or REJ
    return _BWX


def _eval_dmz(state: "InnerGameState", rest: list, from_power: int = 0,
              context_powers: "list[int] | None" = None) -> int:
    """
    Port of FUN_0041f090 — DMZ (demilitarise) proposal evaluator.

    Proposal shape after the leading ``DMZ`` token has been stripped:
        rest = [(powers_sublist), (provinces_sublist)]

    C semantics (_eval_dmz.c):
      * Build a set of DMZ powers from sublist-1 (``local_48``).  Set
        ``own_in_dmz`` if Albert is named in that set.
      * Build ``local_3c`` by appending the sender to the caller-provided
        recipient list.  For every participant in that context:
          - If the participant is Albert: skip its province check.
          - Else: run the ally-trust gate.  Failure → REJ.
      * For each province in sublist-2: walk ``g_order_list`` looking for an
        entry whose ``province`` and ``ally_power`` both match. An entry
        justifies the DMZ when ``flag2`` is set whenever Albert is named in
        the DMZ, and either ``flag1`` is clear or the participant is named in
        the DMZ.
        If no qualifying entry exists for some province → REJ.

    Return: YES (0x481C) on accept, REJ (0x4814) on reject.

    The three node bytes at +0x1c/+0x1d/+0x1e map to flag1/flag2/flag3.
    This evaluator reads flag1 and flag2; flag3 belongs to the separate DMZ
    action handler and must not be substituted here.
    """
    _YES, _REJ = 0x481C, 0x4814
    own = int(state.albert_power_idx)

    # Section split — rest[0] = powers list, rest[1] = provinces list.
    powers_section   = rest[0] if len(rest) >= 1 else []
    provs_section    = rest[1] if len(rest) >= 2 else []

    dmz_powers = _extract_powers(powers_section)
    own_in_dmz = own in dmz_powers

    prov_ids = _extract_provs(state, provs_section)
    order_list = getattr(state, 'g_order_list', []) or []

    # C: local_3c = recipients + sender (FUN_00466480).  Direct unit-level
    # calls lack that hidden argument, so retain the sender-only fallback.
    participants = list(context_powers) if context_powers is not None else [from_power]
    for participant in participants:
        if participant == own:
            continue
        if not _ally_trust_ok(state, own, participant):
            return _REJ

        for prov in prov_ids:
            # Walk g_order_list for a node justifying DMZ on this province.
            found_qualifying = False
            for entry in order_list:
                if entry.get('province') != prov:
                    continue
                entry_ally = entry.get('ally_power')
                if entry_ally != participant:
                    continue
                if not entry.get('flag2', False) and own_in_dmz:
                    continue
                if entry.get('flag1', False) and entry_ally not in dmz_powers:
                    continue
                found_qualifying = True
                break
            if not found_qualifying:
                return _REJ

    return _YES


def _eval_aly(state: "InnerGameState", rest: list, from_power: int = 0,
              context_powers: "list[int] | None" = None) -> int:
    """
    Port of FUN_0041e2d0 — ALY proposal evaluator.

    DAIDE proposal shape: ``ALY (powers) VSS (powers)``.  After the leading
    ALY token is stripped by ``_eval_single_xdo``:
        rest = [(aly_powers_sublist), VSS_token, (vss_powers_sublist)]

    C demands all four conditions (_eval_aly.c lines 229):
      bVar1 = own  power in ALY list
      bVar2 = from-power in ALY list
      bVar3 = every ALY-side power occurs in ``recipients + sender``
              (``local_8c``, built from the hidden caller context)
      bVar4 = for each (aly_power != own, vss_power) pair, the per-pair
              compatibility gate passes.

      Outer branch (line 147): ``DAT_00baed5f`` (g_stabbed_flag) == 1
      selects the stabbed-mode path (lines 147–183); else the normal path
      (lines 185–220).  Both paths consult trust scores, enemy flags,
      relation score, mutual-enemy table, influence-rank flags, and
      potentially a mutual-ally scan loop (lines 165–177 / 203–213) that
      scans every power q and sets bVar4=False when vss_p is already allied
      with a high-priority ally of own.  ``DAT_00baed68`` (g_press_flag)
      governs secondary trust-threshold relaxation and the diplo-override
      gate on the normal path only.

    Returns YES iff (bVar1 && bVar2 && bVar3 && bVar4); else REJ.

    NOTE: The C code only enters the validation block when
    ``len(full_input) == 4`` (line 76 ``uVar6 == 4``) — the four DAIDE tokens
    of ``ALY (..) VSS (..)``.  ``_eval_single_xdo`` strips the leading ALY,
    so we accept ``len(rest) == 3`` (powers, VSS, powers).  Anything else REJ.
    """
    _YES, _REJ = 0x481C, 0x4814
    own = int(state.albert_power_idx)

    if len(rest) != 3:
        return _REJ

    aly_section = rest[0]
    vss_section = rest[2]

    aly_powers = _extract_powers(aly_section)
    vss_powers = _extract_powers(vss_section)

    bVar1 = own in aly_powers
    bVar2 = from_power in aly_powers
    if not (bVar1 and bVar2):
        return _REJ

    # C local_8c is the participant set (recipients + sender), not the ALY
    # or VSS proposal set.  Each ALY power must be a message participant.
    participants = set(context_powers) if context_powers is not None else {from_power}
    if any(p not in participants for p in aly_powers):
        return _REJ

    # bVar4: per-pair compatibility (bulk of _eval_aly.c lines 139–228).
    stabbed    = int(getattr(state, 'g_stabbed_flag', 0)) == 1    # DAT_00baed5f
    press_flag = int(getattr(state, 'g_press_flag', 0)) == 1      # DAT_00baed68
    enemy_flag    = getattr(state, 'g_enemy_flag', None)           # DAT_004cf568
    enemy_flag_hi = getattr(state, 'g_enemy_flag_hi', None)        # DAT_004cf56c
    rel            = state.g_relation_score                         # DAT_00634e90
    ally_mat       = state.g_ally_matrix
    trust_hi       = state.g_ally_trust_score_hi
    trust_lo       = state.g_ally_trust_score
    mutual_en      = getattr(state, 'g_mutual_enemy_table', None)  # DAT_00b9fdd8
    infl_rank      = getattr(state, 'g_influence_rank_flag', None) # DAT_006340c0
    enemy_slot     = getattr(state, 'g_enemy_slot', None)          # DAT_004c6bc4
    enemy_count    = getattr(state, 'g_enemy_count', None)         # DAT_00633ec0
    diplo_a        = getattr(state, 'g_diplomacy_state_a', None)   # DAT_004d5480
    diplo_b        = getattr(state, 'g_diplomacy_state_b', None)   # DAT_004d5484
    n_powers       = int(getattr(state, 'g_num_powers', 7))

    def ef1(p):   return int(enemy_flag[p])    if enemy_flag    is not None else 0
    def ef2(p):   return int(enemy_flag_hi[p]) if enemy_flag_hi is not None else 0
    def mu(p):    return int(mutual_en[p])     if mutual_en     is not None else -1
    def rk(a, b): return int(infl_rank[a, b])  if infl_rank     is not None else -1
    def es0():    return int(enemy_slot[0])    if enemy_slot    is not None else -1
    def ec(p):    return int(enemy_count[p])   if enemy_count   is not None else 0

    bVar4 = True

    for aly_p in aly_powers:
        if aly_p == own:
            continue
        for vss_p in vss_powers:
            if stabbed:
                # Stabbed-mode path (_eval_aly.c lines 147–183).
                ef1a = ef1(aly_p); ef2a = ef2(aly_p)
                ef1v = ef1(vss_p); ef2v = ef2(vss_p)
                rel_oa = int(rel[own, aly_p])
                aam    = int(ally_mat[aly_p, vss_p])
                # Outer gate (lines 148–152): enter block only if:
                #   ((aly has enemy flags OR aly relation < 0) OR
                #    (vss is not (1,0) confirmed-enemy AND vss relation >= 0))
                #   AND aly_p/vss_p not yet allied.
                cond_A = (ef1a != 0 or ef2a != 0) or rel_oa < 0
                cond_B = (ef1v != 1 or ef2v != 0) and int(rel[own, vss_p]) >= 0
                if not ((cond_A or cond_B) and aam < 1):
                    continue
                # Trust own→aly (lines 153–156):
                #   trust_hi[own,aly] >= 0  AND  (trust_hi > 0  OR  trust_lo > 2)
                th1 = int(trust_hi[own, aly_p])
                tl1 = int(trust_lo[own, aly_p])
                if not (th1 >= 0 and (th1 > 0 or int(tl1) > 2)):
                    bVar4 = False
                    continue
                # Reversed trust aly→own + further conditions (lines 157–164):
                #   trust_hi[aly,own] >= 0
                #   AND (trust_hi > 0 OR trust_lo != 0)
                #   AND aly_p NOT (1,0) enemy
                #   AND rel[own,aly] >= 0
                #   AND mutual_enemy[aly] == vss
                #   AND infl_rank[own,aly] < 4
                #   AND enemy_slot[0] != vss
                #   AND enemy_count[own] < 2
                th2 = int(trust_hi[aly_p, own])
                tl2 = int(trust_lo[aly_p, own])
                if (th2 >= 0 and (th2 > 0 or tl2 != 0) and (ef1a != 1 or ef2a != 0)
                        and rel_oa >= 0
                        and mu(aly_p) == vss_p
                        and rk(own, aly_p) < 4
                        and es0() != vss_p
                        and ec(own) < 2):
                    # Mutual-ally scan (lines 165–177): for each power q,
                    # if vss_p is allied with q AND q is high-priority for
                    # own (infl_rank < 4), this alliance would be contradictory.
                    for q in range(n_powers):
                        if int(ally_mat[vss_p, q]) == 1 and rk(own, q) < 4:
                            bVar4 = False
                    continue  # LAB_0041e8c1
                bVar4 = False  # LAB_0041e8bc

            else:
                # Normal path (_eval_aly.c lines 185–220).
                # Outer gate (lines 185–186):
                #   vss NOT (1,0) confirmed-enemy AND aly_p/vss_p not yet allied.
                ef1v = ef1(vss_p); ef2v = ef2(vss_p)
                ef1a = ef1(aly_p); ef2a = ef2(aly_p)
                aam  = int(ally_mat[aly_p, vss_p])
                if not ((ef1v != 1 or ef2v != 0) and aam < 1):
                    continue
                # Trust phase 1: aly→own (lines 187–191):
                #   trust_hi[aly,own] >= 0  AND  (trust_hi > 0 OR trust_lo != 0)
                #   AND aly NOT (1,0) enemy
                #   AND rel[own,aly] >= 0  (comma-expression reassigns iVar16)
                th_ao  = int(trust_hi[aly_p, own])
                tl_ao  = int(trust_lo[aly_p, own])
                rel_oa = int(rel[own, aly_p])
                if not ((th_ao >= 0 and (th_ao > 0 or tl_ao != 0))
                        and (ef1a != 1 or ef2a != 0)
                        and rel_oa >= 0):
                    bVar4 = False
                    continue
                # Trust phase 2: own→aly (lines 193–196), with press_flag relaxation:
                #   trust_hi[own,aly] > 0
                #   OR (trust_hi >= 0 AND trust_lo > 2)
                #   OR (press_flag AND trust_hi >= 0 AND (trust_hi > 0 OR trust_lo != 0))
                # AND mutual_enemy[aly] == vss  (line 197)
                th_oa = int(trust_hi[own, aly_p])
                tl_oa = int(trust_lo[own, aly_p])
                trust2 = (
                    (th_oa > 0 or (th_oa >= 0 and int(tl_oa) > 2))
                    or (press_flag and th_oa >= 0 and (th_oa > 0 or tl_oa != 0))
                )
                if not (trust2 and mu(aly_p) == vss_p):
                    bVar4 = False
                    continue
                # Diplo-override gate (lines 198–199):
                #   skip the rank+loop block when press_flag AND
                #   diplo_a[vss]==1 AND diplo_b[vss]==0  (already dispatched).
                da_v = int(diplo_a[vss_p]) if diplo_a is not None else 0
                db_v = int(diplo_b[vss_p]) if diplo_b is not None else 0
                if not (press_flag and da_v == 1 and db_v == 0):
                    # Rank gate (lines 200–201):
                    #   if mutual_enemy[aly] != vss OR infl_rank[own,aly] > 3 → bVar4=False
                    if mu(aly_p) != vss_p or rk(own, aly_p) > 3:
                        bVar4 = False
                        continue
                    # Mutual-ally scan when not press_flag (lines 202–213).
                    if not press_flag:
                        for q in range(n_powers):
                            if int(ally_mat[vss_p, q]) == 1 and rk(own, q) < 4:
                                bVar4 = False
                # goto LAB_0041e8c1 (continue)

    return _YES if bVar4 else _REJ


def _split_xdo_clauses(context_toks: list) -> "tuple[list, list]":
    """
    Port of CAL_VALUE.c:162-280 — clause-extraction phase.

    Splits ``context_toks`` into (positive_clauses, negative_clauses) where
    positive = plain ``XDO(...)`` and negative = ``NOT(XDO(...))``.

    Mirrors the C dual-sink insertion into ``ppiStack_c4`` (positive sink,
    auStack_c8) vs. ``ppiStack_b8`` (negative sink, auStack_bc) driven by
    the ``is_not`` flag on each clause.

    Handles both:
      * ``AND ( XDO(a) ) ( XDO(b) ) ( NOT ( XDO(c) ) )``  (multi-clause)
      * ``XDO(a)`` / ``NOT ( XDO(a) )``                    (single clause)

    Tokens here are strings (Python string-mode press).
    """
    def _strip_parens(s: str) -> str:
        s = s.strip()
        while s.startswith('(') and s.endswith(')'):
            depth = 0
            stripped = True
            for i, ch in enumerate(s):
                if ch == '(':
                    depth += 1
                elif ch == ')':
                    depth -= 1
                    if depth == 0 and i < len(s) - 1:
                        stripped = False
                        break
            if not stripped:
                break
            s = s[1:-1].strip()
        return s

    def _serialize(items) -> str:
        parts = []
        for item in items if isinstance(items, (list, tuple)) else [items]:
            if isinstance(item, (list, tuple)):
                parts.append(f"( {_serialize(item)} )")
            else:
                parts.append(str(item))
        return ' '.join(parts)

    text = _serialize(context_toks).strip()
    text = _strip_parens(text)

    positive: list = []
    negative: list = []

    def _push_clause(clause_text: str):
        c = _strip_parens(clause_text).strip()
        is_not = False
        if c.startswith('NOT'):
            is_not = True
            c = _strip_parens(c[3:]).strip()
        if c.startswith('XDO'):
            (negative if is_not else positive).append(c)

    # AND( ... )( ... )( ... ) multi-clause shape
    # Lazy import to break circular dependency: parsers → evaluators → parsers
    from ..parsers import _extract_top_paren_groups
    if text.startswith('AND'):
        rest = text[3:].strip()
        # Split on top-level paren groups
        groups = _extract_top_paren_groups(rest) if rest else []
        for g in groups:
            _push_clause(g)
    elif text.startswith('ORR'):
        rest = text[3:].strip()
        groups = _extract_top_paren_groups(rest) if rest else []
        for g in groups:
            _push_clause(g)
    else:
        _push_clause(text)

    return positive, negative


def _cal_value(state: "InnerGameState", context_toks: list) -> int:
    """
    Port of CAL_VALUE = FUN_004266b6 — XDO / negated-XDO coherence scorer.

    See docs/funcs/CAL_VALUE.md for the full spec. This port implements the
    control-flow skeleton faithfully with full per-power score vector support:
    score vectors are computed for inbound entries via register_received_press
    (gate.py lines 365–378), enabling delta-score classification into
    YES/REJ/BWX/HUH verdict bands. Self-generated support requests live in
    g_ProposalHistoryMap, a separate C container.

    High-level flow (mirrors C):

      1. Clause-extraction phase (C lines 162–280):
         Split ``context_toks`` into positive (plain XDO) and negative
         (NOT-wrapped XDO) clause lists via ``_split_xdo_clauses``.

      2. Sequence-catalog walk (C lines 299–401):
         Iterate ``state.g_broadcast_list`` (the Python equivalent of
         ``DAT_00bb65ec``) with three gates mirroring the C:
           *(char *)(puVar24 + 6) != '\0'  → received_flag is set
           puVar24[7] == 0                 → type_flag == 0 (skip self-generated)
           iStack_c0 == puVar24[0xe]       → exact positive XDO count match
           iStack_b4 == puVar24[0x11]      → exact negative NOT-XDO count match
           bVar27                          → all proposed clauses found in sub-trees
         Candidates are split into positive (XDO) vs negative (NOT-XDO) sub-trees
         and compared independently. First fully-matching entry wins.

      3. Matching-sequence scoring (C lines 539–630):
         Uses node[0x27] as an exact prior-record key. When that reference
         resolves and both baseline scores clear the -79999 floor, computes
         ``current.score[own] - baseline.score[own]``; otherwise uses the
         current score directly. Band classification:
           delta >= -199      → YES-eligible
           [-89999, -199)     → REJ
           [-99999, -89999)   → BWX
           < -99999           → HUH

      4. Legitimacy gate (C lines 645–684):
         Two post-match passes mirror CAL_VALUE.c lines 421–468:
           Pass 1 (positive clauses, uStack_34=1 → flag_bit=1): sub-tree A
             candidates from the matched entry, scored raw (skip own-power
             rescore).
           Pass 2 (negative clauses, uStack_34=0 → flag_bit=0): NOT-XDO
             clauses from the proposal itself, eligible for own-power rescore.
         Both pass sets are fed to ``legitimacy_gate``.  A negative aggregate
         min demotes a YES-eligible verdict to REJ.

      5. Verdict emission:
         YES-eligible & gate ≥ 0  →  YES
         YES-eligible & gate < 0  →  REJ (demoted)
         BWX-eligible             →  BWX
         HUH-eligible             →  HUH
         no match / plain REJ     →  REJ
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Cross-slice call: ``legitimacy_gate`` lives in the parent
    # ``communications`` package (re-exported from ``inbound.gate``).
    # Deferred import at call time avoids a circular import during
    # package initialisation.  Fixed 2026-04-20: was ``from .`` (evaluators
    # package, which does not re-export it) → ``from ..`` (communications).
    from .. import legitimacy_gate

    _YES, _REJ, _HUH, _BWX = 0x481C, 0x4814, 0x4806, 0x4A02

    # ── 1. Clause extraction ──────────────────────────────────────────────
    positive, negative = _split_xdo_clauses(context_toks)
    if not positive and not negative:
        # No XDO clauses found → C falls through to "no match" → REJ.
        _log.debug("cal_value: no XDO clauses in %r → REJ", context_toks)
        return _REJ

    # ── 2. Sequence-catalog walk ──────────────────────────────────────────
    matched_entry = None
    pos_set = set(positive)
    neg_set = set(negative)
    _NOT_TOK = 0x480D

    def _cand_is_neg(tok_list: list) -> bool:
        if not tok_list:
            return False
        t0 = tok_list[0]
        return t0 == _NOT_TOK or str(t0).upper() == 'NOT'

    def _neg_cand_text(tok_list: list) -> str:
        # Strip leading NOT (and any outer parens) so the result matches the
        # XDO-only strings stored in neg_set by _split_xdo_clauses.
        t = tok_list[1:] if tok_list else []
        while t and t[0] == '(' and t[-1] == ')':
            t = t[1:-1]
        return ' '.join(str(x) for x in t)

    for entry in state.g_broadcast_list:
        if not isinstance(entry, dict):
            continue
        # C: *(char *)(puVar24 + 6) != '\0'
        # Field at node+24: set by FUN_0042e450 (RB-tree insert) for received entries.
        # Python equivalent: received_flag = True (set by register_received_press).
        if not entry.get('received_flag', False):
            continue
        # C: puVar24[7] == 0  — skip self-generated (type_flag == 1) entries.
        if entry.get('type_flag', 0) != 0:
            continue
        cands = entry.get('order_candidates', [])
        if not cands:
            continue
        # Split candidates into positive (plain XDO) and negative (NOT-XDO) sub-trees.
        # C: ppiStack_c4 positive BST / ppiStack_b8 negative BST in the entry.
        pos_cands_tok: list = []
        neg_cands_tok: list = []
        for c in cands:
            tok = c.get('tokens', []) if isinstance(c, dict) else (c if isinstance(c, list) else [])
            (neg_cands_tok if _cand_is_neg(tok) else pos_cands_tok).append(tok)
        # C: iStack_c0 == puVar24[0xe] AND iStack_b4 == puVar24[0x11] — exact count.
        if len(positive) != len(pos_cands_tok) or len(negative) != len(neg_cands_tok):
            continue
        # C: bVar27 — all proposed clauses found in the entry's respective sub-trees.
        pos_texts = {' '.join(str(x) for x in t) for t in pos_cands_tok}
        neg_texts = {_neg_cand_text(t) for t in neg_cands_tok}
        if not pos_set.issubset(pos_texts):
            continue
        if not neg_set.issubset(neg_texts):
            continue
        matched_entry = entry
        break

    if matched_entry is None:
        _log.debug(
            "cal_value: no matching sequence for pos=%r neg=%r → REJ",
            positive, negative,
        )
        # C: SEND_LOG("Could not find matching sequence") + BuildAllianceMsg archive.
        import time as _t
        state.g_alliance_msg_tree.add(
            int(_t.time() - getattr(state, 'g_turn_start_time', 0.0)) + 10000
        )
        return _REJ

    # ── 3. Matching-sequence scoring (delta + verdict bands) ─────────────
    # C (CAL_VALUE.c lines 484–570):
    #   preflight gates — reference key >= 1, referenced record exists,
    #   baseline.score[own] >= -79999, baseline.score[target] >= -79999
    #   diff form:      delta = current.score[own] − predecessor.score[own]
    #   fallback form:  delta = current.score[own]
    # Band classification (CAL_VALUE.c lines 612–627):
    #   delta >= -199      → YES-eligible
    #   [-89999, -199)     → REJ
    #   [-99999, -89999)   → BWX
    #   < -99999           → HUH
    own_power_idx = getattr(state, 'own_power_index', None)
    if own_power_idx is None:
        own_power_idx = getattr(state, 'albert_power_idx', 0)
    own_power_idx = int(own_power_idx)

    cur_vec = matched_entry.get('score_vector') or [0] * 7
    cur_own = cur_vec[own_power_idx] if own_power_idx < len(cur_vec) else 0

    target_power = matched_entry.get('target_power')
    if target_power is None:
        from_tok = matched_entry.get('from_power_tok', own_power_idx)
        target_power = (
            (int(from_tok) & 0x7f) if isinstance(from_tok, int)
            else own_power_idx
        )
    target_power = int(target_power)
    # C node[0x27] is local_150: the prior-record key captured by the
    # registration pass (0xffffffff for no baseline). It is not the nearby
    # one-byte history flag.
    reference_key = matched_entry.get('watermark')
    predecessor = None
    if reference_key is not None and int(reference_key) >= 1:
        predecessor = next(
            (candidate for candidate in state.g_broadcast_list
             if isinstance(candidate, dict)
             and int(candidate.get('key', -1)) == int(reference_key)),
            None,
        )

    use_diff = False
    if predecessor is not None:
        pred_vec = predecessor.get('score_vector') or [0] * 7
        pred_own = pred_vec[own_power_idx] if own_power_idx < len(pred_vec) else 0
        pred_tgt = pred_vec[target_power] if target_power < len(pred_vec) else 0
        # -79999 floor: CAL_VALUE refuses to use a predecessor whose
        # baseline is below that (records crippled to the trust-layer
        # clamp window are meaningless subtraction baselines).
        if pred_own >= -79999 and pred_tgt >= -79999:
            use_diff = True

    if use_diff:
        delta = cur_own - pred_own
    else:
        delta = cur_own

    yes_eligible = False
    bwx_flag = False
    huh_flag = False
    if delta >= -199:
        yes_eligible = True
    elif delta < -99999:
        huh_flag = True
    elif delta < -89999:
        bwx_flag = True
    # else: [-89999, -199) → plain REJ (all flags remain False)

    _log.debug(
        "cal_value: matched idx=%d delta=%d (use_diff=%s) → "
        "yes=%s bwx=%s huh=%s",
        matched_index, delta, use_diff, yes_eligible, bwx_flag, huh_flag,
    )

    # ── 4. Legitimacy gate (demotion) ─────────────────────────────────────
    # C (CAL_VALUE.c lines 645–684): FUN_00426140 runs unconditionally; its
    # return value is consulted only on the YES-eligible path, where a
    # negative min demotes YES → REJ. HUH/BWX paths (bVar27=false with
    # bVar5/bVar6) bypass the demotion entirely — they flow to LAB_004271da
    # with `uVar22` never set to YES.
    #
    # Two input passes (CAL_VALUE.c lines 421–468):
    #   Pass 1 positive clauses  uStack_34=1 → flag_bit=1 (sub-tree A, raw score)
    #   Pass 2 negative clauses  uStack_34=0 → flag_bit=0 (sub-tree B, rescore-eligible)
    from ..parsers import _parse_xdo_candidates as _pxc
    try:
        cand_list = matched_entry.get('order_candidates', [])
        # Pass 1: positive candidates, sub-tree A → flag_bit=1 (skip rescore)
        pos_gate = []
        for c in cand_list:
            toks = c.get('tokens', []) if isinstance(c, dict) else []
            if _cand_is_neg(toks) or not isinstance(c, dict) or 'order_seq' not in c:
                continue
            pos_gate.append({
                'order_seq': c['order_seq'],
                'power': c.get('power', own_power_idx),
                'flag_bit': 1,
            })
        # Pass 2: negative candidates, sub-tree B → flag_bit=0 (rescore-eligible)
        neg_gate = []
        for neg_str in negative:
            for parsed in _pxc(neg_str):
                if 'order_seq' not in parsed:
                    continue
                neg_gate.append({
                    'order_seq': parsed['order_seq'],
                    'power': parsed.get('power', own_power_idx),
                    'flag_bit': 0,
                })
        gate_score = legitimacy_gate(state, own_power_idx, pos_gate + neg_gate)
    except (KeyError, IndexError, TypeError, ValueError) as exc:
        _log.warning("cal_value: legitimacy_gate raised %s; treating as non-blocking", exc)
        gate_score = 0

    if yes_eligible and gate_score < 0:
        _log.debug(
            "cal_value: YES demoted to REJ by legitimacy_gate (score=%d)",
            gate_score,
        )
        return _REJ

    # ── 5. Verdict ────────────────────────────────────────────────────────
    if yes_eligible:
        return _YES
    if huh_flag:
        return _HUH
    if bwx_flag:
        return _BWX
    return _REJ


def _eval_slo(state: "InnerGameState", rest: list, from_power: int = 0,
              context_powers: "list[int] | None" = None) -> int:
    """
    Port of FUN_0041ea20 — SLO (solo-win) proposal evaluator.

    C logic (from _eval_slo.c):
      Two ``std::set<int>`` objects are built.  The first-constructed set
      lives at ``local_54`` (head ``local_50``, size ``local_4c``); the
      second at ``local_48`` (head ``local_44``, size ``local_40``).  The
      destructor pairing in the epilogue fixes that binding, and
      ``_eval_drw.c`` uses the identical idiom, which confirms the argument
      order ``StdMap_FindOrInsert(set_object, ret_slot, key)``.

      * The participant list ``recipients + sender`` (``local_2c``) is
        inserted into the ``local_48`` set — whose size ``local_40`` is
        never read.
      * The SLO power sublist ``GetSubList(input, 1)`` (``local_1c``) is
        inserted into the ``local_54`` set, and sets ``bVar2`` when Albert
        occurs in it.

      The verdict is ``local_4c == 1 && bVar2``: YES iff the SLO names
      exactly one distinct power and that power is Albert — i.e. Albert
      accepts only a proposal that *he* takes the solo.  REJ otherwise.

    `rest` is tokens[1:] after SLO is stripped; rest[0] is the (power) sublist.

    ``context_powers`` is retained for signature compatibility with the other
    context-sensitive evaluators; C builds the participant set but never
    consults its size here.
    """
    own = state.albert_power_idx
    pwr_section = rest[0] if rest else []
    if not isinstance(pwr_section, (list, tuple)):
        pwr_section = rest
    slo_powers = _extract_powers(pwr_section)

    distinct = set(slo_powers)
    own_is_target = own in distinct
    if len(distinct) == 1 and own_is_target:
        return 0x481C   # YES
    return 0x4814        # REJ


def _eval_drw(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0041ed30 — DRW (draw) proposal evaluator.

    C logic (from _eval_drw.c):
      If len(full_input)==2 (DRW + power-list), bVar6 becomes True only
      when the list is non-empty and contains Albert.  For every other input
      length, the guarded validation block is skipped and bVar6 becomes True.
      Returns YES  iff  g_draw_sent (DAT_00baed5d) != 0  AND  bVar6.
      Otherwise REJ.

    `rest` is tokens[1:] after DRW is stripped, so C's len==2 ↔ len(rest)==1.
    """
    own = state.albert_power_idx
    bVar6 = True
    if len(rest) == 1:
        bVar6 = False
        pwr_section = rest[0]
        iterable = pwr_section if isinstance(pwr_section, (list, tuple)) else rest
        for tok in iterable:
            if _pow_idx(tok) == own:
                bVar6 = True
                break

    if state.g_draw_sent and bVar6:
        return 0x481C   # YES
    return 0x4814        # REJ


def _eval_not_pce(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0040d310 — NOT PCE / SUB PCE evaluator.

    C logic (from _eval_not_pce.c):
      bVar4 = (len(power_list) < 3) AND NOT _has_duplicate_powers(power_list)
      bVar2 = own power in list, bVar3 = from_power in list.
      Returns:
        YES  if bVar2 AND bVar3 AND bVar4
        REJ  if bVar2 AND bVar3 AND NOT bVar4
        BWX  if bVar2 AND NOT bVar3
        YES  (default uVar8) otherwise
    """
    _BWX = 0x4A02
    own = state.albert_power_idx
    # FUN_0040d0a0: returns 1 if any two elements in the list share the
    # same first byte (= same power token), 0 if all unique.
    # bVar4 = short list AND no duplicate powers.
    power_tokens = _extract_powers(rest)
    has_dup = len(power_tokens) != len(set(power_tokens))
    bVar4 = (len(power_tokens) < 3) and not has_dup
    bVar2 = bVar3 = False
    for p in power_tokens:
        if p == own:
            bVar2 = True
        elif p == from_power:
            bVar3 = True
    if bVar2 and bVar3:
        return 0x481C if bVar4 else 0x4814   # YES or REJ
    if bVar2:
        return _BWX   # own found but proposer not in list
    return 0x481C     # default YES (Albert not named → not applicable)


def _eval_not_dmz(state: "InnerGameState", rest: list, from_power: int = 0,
                  context_powers: "list[int] | None" = None) -> int:
    """
    Port of FUN_0041f5a0 — NOT DMZ / SUB DMZ evaluator.

    Proposal shape (after stripping NOT/SUB wrapper): ``(DMZ (powers) (provinces))``
    so ``rest = [powers_section, provs_section]``.

    Algorithm (mirrors C lines 105-281 of _eval_not_dmz.c):

      Phase A — extract DMZ powers and provinces; build local_cc as a set
                from the DMZ-powers list (StdMap_FindOrInsert at line 109).

      Phase B (lines 113-148) — validation walk over (every power, every
                province): probe g_ally_counter_list[p] then g_ally_promise_list[p].
                Pure validation; no flag side-effects captured by the Python view.

      Phase C (lines 149-243) — per (q in iter_powers, d in provinces) where
                q != own:
                  • If q == from_power AND (q,d) is recorded in NEITHER counter
                    NOR promise lists → ``bVar3 = False`` (no rejection signal
                    came from the proposer's own ledgers).
                  • If (q,d) is recorded in BOTH counter AND promise AND q is
                    NOT in the DMZ-powers set → ``bVar4 = False``.
                  • If (q,d) is recorded in counter but NOT in promise AND
                    g_near_end_game_factor < 3.0 → ``bVar4 = False``.

      Phase D (lines 244-250) — ally-trust gate using own,from_power scores.
                If iter_powers > 2 and trust gates fail → ``bVar4 = False``.

      Verdict (lines 251-281):
                bVar3 still True   → REJ if !bVar4 else YES
                bVar3 False        → BWX when the doubled participant count is
                                     >= 3; otherwise BWX iff the DMZ power
                                     sublist is non-empty and does not name
                                     the sender.  Everything else falls
                                     through to YES/REJ.

    The C appends the sender to the recipient list twice into ``local_7c``.
    The duplicate traversal matters to its later ``count < 3`` verdict gate,
    so Python preserves both copies rather than reducing them to a set.

    Reference: ``_eval_not_dmz.c``  (FUN_0041f5a0)
    """
    _YES, _REJ, _BWX = 0x481C, 0x4814, 0x4A02

    own = int(state.albert_power_idx)
    from_p = int(from_power)

    # ── Phase A: extract DMZ shape ────────────────────────────────────────
    powers_section = rest[0] if len(rest) >= 1 else []
    provs_section  = rest[1] if len(rest) >= 2 else []
    dmz_powers = _extract_powers(powers_section)         # local_5c → local_cc set
    dmz_provs  = _extract_provs(state, provs_section)    # local_6c
    dmz_set    = set(dmz_powers)
    participants = list(context_powers) if context_powers is not None else [from_p]
    iter_powers = participants + participants           # two AppendList calls in C

    # ── helpers: dest_prov membership in promise / counter dicts ──────────
    promise_map = getattr(state, 'g_ally_promise_list', {}) or {}
    counter_map = getattr(state, 'g_ally_counter_list', {}) or {}

    def _has(map_: dict, p: int, prov: int) -> bool:
        recs = map_.get(p) or []
        for r in recs:
            if isinstance(r, dict):
                if int(r.get('dest_prov', -1)) == prov:
                    return True
            else:
                # Tolerate plain-int storage.
                try:
                    if int(r) == prov:
                        return True
                except Exception:
                    pass
        return False

    near_end = float(getattr(state, 'g_near_end_game_factor', 0.0))

    bVar3 = True   # REJ-eligibility flag (becomes False when from_power's ledger is silent)
    bVar4 = True   # YES-eligibility flag (cleared by DMZ-conflict or NearEnd-counter check)

    # ── Phase C: per (power_q, province_d) walk ───────────────────────────
    for q in iter_powers:
        if q == own:
            continue
        for d in dmz_provs:
            in_counter = _has(counter_map, q, d)
            in_promise = _has(promise_map, q, d)

            # Sub-check A (lines 162-184): from_power's own ledgers are silent.
            if q == from_p and (not in_counter) and (not in_promise):
                bVar3 = False

            # Sub-check B (lines 186-213): both ledgers record (q,d) and q is
            # NOT named in the DMZ power set.  C tests
            # ``piVar13[1] == ppiVar5`` — the returned node IS the head
            # sentinel, i.e. ``find() == end()`` — so the clearing case is
            # absence, not membership.  (_eval_aly.c:127 and _eval_dmz.c:154
            # use the same idiom with the opposite comparison.)
            if in_counter and in_promise and (q not in dmz_set):
                bVar4 = False

            # Sub-check C (lines 215-232): counter says yes, promise says no,
            # and we're still in the early/mid game.
            if in_counter and (not in_promise) and near_end < 3.0:
                bVar4 = False

    # ── Phase D: ally-trust gate (lines 244-250) ──────────────────────────
    # if Hi < 1 AND (Hi < 0 OR Lo < 2) AND iter_powers > 2: bVar4 = False
    try:
        hi = int(state.g_ally_trust_score_hi[own, from_p])
        lo = int(state.g_ally_trust_score[own, from_p])
    except Exception:
        hi, lo = 0, 0
    if (hi < 1) and ((hi < 0) or (lo < 2)) and (len(iter_powers) > 2):
        bVar4 = False

    # ── Verdict (lines 251-281) ───────────────────────────────────────────
    if bVar3:
        # No "from_power silent" signal → straight YES/REJ.
        return _YES if bVar4 else _REJ

    # bVar3 False: BWX path.  C branches on TWO different counts here —
    # ``uVar9`` is local_a4, the doubled participant count, but ``uVar10`` is
    # local_90, the length of the DMZ *power* sublist (local_5c).  Both are
    # reloaded from their backing locals on every loop exit, so the verdict
    # block always sees those two values.
    n_iter = len(iter_powers)          # uVar9  — doubled participants
    n_dmz  = len(dmz_powers)           # uVar10 — DMZ power sublist length
    from_in_dmz = (from_p in dmz_set)
    if n_iter >= 3:
        return _BWX
    if n_dmz > 1:
        # C: found → LAB_0041fb83 (uVar10 != 1, so straight on to the
        # YES/REJ tail); not found → LAB_0041fbc2 → BWX.
        if not from_in_dmz:
            return _BWX
    elif n_dmz == 1:
        # LAB_0041fb83: the single-power list only escapes BWX when the
        # sender is that power.
        if not from_in_dmz:
            return _BWX
    return _YES if bVar4 else _REJ


def _eval_sub_xdo(rest: list) -> int:
    """
    Port of FUN_0040d450 — SUB XDO evaluator (no `this` / no ECX).

    C (_eval_sub_xdo.c): unconditionally sets *param_1 = REJ and returns.
    Plain cdecl, not __thiscall.
    """
    return 0x4814   # REJ — always


def _eval_single_xdo(state: "InnerGameState", tokens: list,
                     from_power: int = 0,
                     context_powers: "list[int] | None" = None) -> int:
    """
    Port of FUN_0042c040 — single-proposal type dispatcher.

    Dispatches to type-specific sub-evaluators based on the first token
    of the proposal list.  Returns YES (0x481C), REJ (0x4814), or
    HUH (0x4806).

    C dispatch table (from _eval_single_xdo.c):
      PCE              → _eval_pce        (FUN_0040d1a0)
      DMZ              → _eval_dmz        (FUN_0041f090)
      ALY              → _eval_aly        (FUN_0041e2d0)
      XDO              → _cal_value       (CAL_VALUE / FUN_004266b6)
      SLO              → _eval_slo        (FUN_0041ea20)
      DRW              → _eval_drw        (FUN_0041ed30)
      NOT PCE          → _eval_not_pce    (FUN_0040d310)
      NOT DMZ          → _eval_not_dmz    (FUN_0041f5a0)
      NOT XDO          → _cal_value       (local_48 = [NOT, …] passed as ctx)
      NOT (other)      → HUH
      SUB PCE          → _eval_not_pce    (FUN_0040d310, same as NOT PCE)
      SUB DMZ          → _eval_not_dmz    (FUN_0041f5a0, same as NOT DMZ)
      SUB XDO          → _eval_sub_xdo    (FUN_0040d450, no `this`)
      SUB NOT XDO      → _cal_value       (local_48 context)
      else             → HUH

    DAT_004c6e14 is PRP (0x4A13), the press-proposal wrapper.
    """
    _YES, _REJ, _HUH = 0x481C, 0x4814, 0x4806
    _PCE, _DMZ, _ALY = 0x4A10, 0x4A03, 0x4A00
    _XDO, _SLO, _DRW = 0x4A1F, 0x4816, 0x4801
    _NOT, _PRP        = 0x480D, 0x4A13

    _NAME = {
        _PCE: 'PCE', _DMZ: 'DMZ', _ALY: 'ALY',
        _XDO: 'XDO', _SLO: 'SLO', _DRW: 'DRW',
        _NOT: 'NOT', _PRP: 'PRP',
    }

    def _teq(tok, val):
        return tok == val or str(tok).upper() == _NAME.get(val, '')

    if not tokens:
        return _HUH

    raw_tokens = list(tokens)
    if '(' in raw_tokens or ')' in raw_tokens:
        from ..parsers import _split_top_level_groups
        tokens = _split_top_level_groups(raw_tokens)
    else:
        tokens = raw_tokens

    def _unwrap(item) -> list:
        if not isinstance(item, list):
            return [item]
        if '(' in item or ')' in item:
            from ..parsers import _split_top_level_groups
            return _split_top_level_groups(item)
        return list(item)

    t0 = tokens[0]
    rest = tokens[1:]

    if _teq(t0, _PCE):
        return _eval_pce(state, rest, from_power)

    if _teq(t0, _DMZ):
        return _eval_dmz(state, rest, from_power, context_powers)

    if _teq(t0, _ALY):
        return _eval_aly(state, rest, from_power, context_powers)

    if _teq(t0, _XDO):
        return _cal_value(state, raw_tokens)

    if _teq(t0, _SLO):
        return _eval_slo(state, rest, from_power, context_powers)

    if _teq(t0, _DRW):
        return _eval_drw(state, rest, from_power)

    if _teq(t0, _NOT):
        if not rest:
            return _HUH
        inner = _unwrap(rest[0]) if isinstance(rest[0], list) else rest
        if not inner:
            return _HUH
        t1 = inner[0]
        rest2 = inner[1:]
        if _teq(t1, _PCE):
            return _eval_not_pce(state, rest2, from_power)
        if _teq(t1, _DMZ):
            return _eval_not_dmz(state, rest2, from_power, context_powers)
        if _teq(t1, _XDO):
            return _cal_value(state, raw_tokens)
        return _HUH

    if _teq(t0, _PRP):
        # PRP = DAT_004c6e14; unwrap its one press-content sublist.
        if not rest:
            return _HUH
        inner = _unwrap(rest[0]) if isinstance(rest[0], list) else rest
        if not inner:
            return _HUH
        t1 = inner[0]
        rest2 = inner[1:]
        if _teq(t1, _PCE):
            return _eval_not_pce(state, rest2, from_power)   # same as NOT PCE
        if _teq(t1, _DMZ):
            return _eval_not_dmz(state, rest2, from_power, context_powers)   # same as NOT DMZ
        if _teq(t1, _XDO):
            return _eval_sub_xdo(rest2)                       # FUN_0040d450
        if _teq(t1, _NOT):
            # _eval_single_xdo.c:238-243.  The top-level NOT arm (line 131)
            # descends with GetSubList(input, 1) before re-testing element 0;
            # this SUB/PRP arm calls AppendList(local_48, input) and then
            # re-reads element 0 of the *undescended* list, which is still
            # NOT.  The `XDO != *psVar4` test therefore always jumps to
            # LAB_0042c5e4, so CAL_VALUE is unreachable here and Albert
            # answers HUH to every `PRP (NOT (XDO ...))`.  Reproduced rather
            # than repaired: this is a fidelity port.
            return _HUH
        return _HUH

    return _HUH
