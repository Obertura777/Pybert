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
    """
    _BWX = 0x4A02
    own = state.albert_power_idx
    bVar1 = bVar2 = False
    bVar3 = True
    for tok in rest:
        p = _pow_idx(tok)
        if p is None:
            continue
        if p == own:
            bVar1 = True
        else:
            if p == from_power:
                bVar2 = True
            if int(state.g_enemy_flag[p]) == 1 or int(state.g_relation_score[own, p]) < 0:
                bVar3 = False
    if bVar1 and bVar2:
        return 0x481C if bVar3 else 0x4814   # YES or REJ
    return _BWX


def _eval_dmz(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0041f090 — DMZ (demilitarise) proposal evaluator.

    Proposal shape after the leading ``DMZ`` token has been stripped:
        rest = [(powers_sublist), (provinces_sublist)]

    C semantics (_eval_dmz.c):
      * Build a set of DMZ powers from sublist-1 (``local_48``).  Set
        ``own_in_dmz`` if Albert is named in that set.
      * For ``from_power`` (sublist-0 in C is the from-power singleton):
          - If ``from_power == own``: trivial accept (skip province check).
          - Else: run the ally-trust gate (``_ally_trust_ok``).  Failure → REJ.
      * For each province in sublist-2: walk ``g_order_list`` looking for an
        entry whose ``province`` and ``ally_power`` both match.  An entry
        "justifies" the DMZ when:
            entry.flag1 is True (alliance order)
            NOT (entry.flag3 is False AND own_in_dmz)
            from_power is NOT in the DMZ-powers list
        If no qualifying entry exists for some province → REJ.

    Return: YES (0x481C) on accept, REJ (0x4814) on reject.

    NOTE: The C inner BST loop's last gate inspects a StdMap value-pointer
    via GameBoard_GetPowerRec(local_48,...) that has uncertain Python
    semantics (the map's value type is never explicitly written).  We
    interpret it as "from_power is in the DMZ-powers list" — which matches
    the observed behaviour that own-proposed DMZ is trivially accepted and
    third-party DMZ requires an Albert/ally order to justify it.
    """
    _YES, _REJ = 0x481C, 0x4814
    own = int(state.albert_power_idx)

    # Section split — rest[0] = powers list, rest[1] = provinces list.
    powers_section   = rest[0] if len(rest) >= 1 else []
    provs_section    = rest[1] if len(rest) >= 2 else []

    dmz_powers = _extract_powers(powers_section)
    own_in_dmz = own in dmz_powers

    # Trivial-accept: Albert's own DMZ proposals don't get province-checked
    # (mirrors C line 109: province validation gated on ``local_78 != uVar15``).
    if from_power == own:
        return _YES

    if not _ally_trust_ok(state, own, from_power):
        return _REJ

    prov_ids = _extract_provs(state, provs_section)
    order_list = getattr(state, 'g_order_list', []) or []

    for prov in prov_ids:
        # Walk g_order_list for a node justifying DMZ on this province.
        # C BST loop (lines 120-155): for each entry matching (province, ally_power),
        # apply three gates.  The third gate does a per-entry lookup of the entry's
        # ally_power in the DMZ-powers std::map (local_48) via GameBoard_GetPowerRec.
        # A hit means the entry's ally_power is a DMZ participant → disqualify.
        found_qualifying = False
        for entry in order_list:
            if entry.get('province') != prov:
                continue
            entry_ally = entry.get('ally_power')
            if entry_ally != from_power:
                continue
            # Match candidate; apply the three gating checks from the BST loop.
            if not entry.get('flag1', False):
                continue
            if not entry.get('flag3', False) and own_in_dmz:
                continue
            # Gate 3: per-entry DMZ-powers membership check.  C looks up the
            # *entry's* ally_power in local_48 (the DMZ-powers map built from
            # the proposal).  A match disqualifies this entry.
            if entry_ally in dmz_powers:
                continue
            found_qualifying = True
            break
        if not found_qualifying:
            return _REJ

    return _YES


def _eval_aly(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0041e2d0 — ALY proposal evaluator.

    DAIDE proposal shape: ``ALY (powers) VSS (powers)``.  After the leading
    ALY token is stripped by ``_eval_single_xdo``:
        rest = [(aly_powers_sublist), VSS_token, (vss_powers_sublist)]

    C demands all four conditions (_eval_aly.c lines 229):
      bVar1 = own  power in ALY list
      bVar2 = from-power in ALY list
      bVar3 = no VSS-side power has any existing ALY-side power in
              ``local_88`` (the ally-side StdMap built earlier)
      bVar4 = for each (aly_power, vss_power) pair, the per-pair compatibility
              gate passes — checks ally trust, enemy flags, relation score,
              proximity (g_mutual_enemy_table), proposal counter (g_relation_score),
              and press-mode gates.

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
    # rest[1] should be the VSS token; we ignore its identity and use its
    # presence as a structural gate (the dispatcher already verified ALY).
    vss_section = rest[2]

    aly_powers = _extract_powers(aly_section)
    vss_powers = _extract_powers(vss_section)

    bVar1 = own in aly_powers
    bVar2 = from_power in aly_powers
    if not (bVar1 and bVar2):
        return _REJ

    # bVar3: no VSS power may already be in our ALY-side relationship.  The C
    # builds local_88 by walking aly_powers and inserting each as a key, then
    # looks up each vss_power; a hit means "the proposed enemy is already on
    # the ally side" → reject.
    aly_set = set(aly_powers)
    if any(v in aly_set for v in vss_powers):
        return _REJ

    # bVar4: per-pair compatibility.  This is the bulk of _eval_aly.c.
    # Fixed 2026-04-20 (M-COM-1): press-mode promise-queue gates now checked
    # via g_diplomacy_state_a/B, matching C lines 180-210.
    press_mode = int(getattr(state, 'g_press_flag', 0)) == 1
    enemy_flag = getattr(state, 'g_enemy_flag', None)
    rel        = state.g_relation_score           # DAT_00634e90
    ally_mat   = state.g_ally_matrix              # DAT_006340c0/g_ally_matrix overlap
    mutual_en  = getattr(state, 'g_mutual_enemy_table', None)  # DAT_00b9fdd8
    diplo_a    = getattr(state, 'g_diplomacy_state_a', None)   # DAT_004d5480
    diplo_b    = getattr(state, 'g_diplomacy_state_b', None)   # DAT_004d5484

    for aly_p in aly_powers:
        if aly_p == own:
            continue
        for vss_p in vss_powers:
            # Forward enemy/relation gate.
            if press_mode:
                # Promise-queue gate (C _eval_aly.c lines 180-210):
                # Check g_diplomacy_state_a[aly_p] and g_diplomacy_state_b[vss_p]
                # to ensure we haven't already committed contradictory promises.
                if diplo_a is not None and diplo_b is not None:
                    dip_a = int(diplo_a[aly_p]) if aly_p < len(diplo_a) else 0
                    dip_b = int(diplo_b[vss_p]) if vss_p < len(diplo_b) else 0
                    # C: if DiplomacyStateA[aly_p] != 0 and already committed
                    # to a different vss target, reject.
                    if dip_a != 0 and dip_a != vss_p and dip_a != -1:
                        return _REJ
                    # C: if DiplomacyStateB[vss_p] != 0 and already committed
                    # to a different aly partner, reject.
                    if dip_b != 0 and dip_b != aly_p and dip_b != -1:
                        return _REJ

                ef = int(enemy_flag[aly_p]) if enemy_flag is not None else 0
                if ef == 0 and int(rel[own, aly_p]) >= 0:
                    # vss must be a real opponent we're not already allied with
                    is_v_friendly_now = (
                        int(rel[own, vss_p]) >= 0
                        and (enemy_flag is None or int(enemy_flag[vss_p]) != 1)
                    )
                    already_allied = int(ally_mat[aly_p, vss_p]) >= 1
                    if not is_v_friendly_now and not already_allied:
                        if not _ally_trust_ok(state, own, aly_p):
                            return _REJ
                        if mutual_en is not None and int(mutual_en[aly_p]) != vss_p:
                            return _REJ
                        continue
                return _REJ
            else:
                # Non-press path (line 185+): VSS must not already be allied
                # to ALY power, and trust gate must pass.
                if int(ally_mat[aly_p, vss_p]) >= 1:
                    return _REJ
                if not _ally_trust_ok(state, own, aly_p):
                    return _REJ
                if mutual_en is not None and int(mutual_en[aly_p]) != vss_p:
                    return _REJ

    return _YES


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

    text = ' '.join(str(t) for t in context_toks).strip()
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
    (gate.py lines 365–378) and for self-generated entries via
    emit_xdo_proposals_to_broadcast, enabling accurate delta-score classification
    into YES/REJ/BWX/HUH verdict bands.

    High-level flow (mirrors C):

      1. Clause-extraction phase (C lines 162–280):
         Split ``context_toks`` into positive (plain XDO) and negative
         (NOT-wrapped XDO) clause lists via ``_split_xdo_clauses``.

      2. Sequence-catalog walk (C lines 299–401):
         Iterate ``state.g_broadcast_list`` (the Python equivalent of
         ``DAT_00bb65ec``) looking for an entry whose order_candidates
         contain **every** positive proposed clause and do NOT contain
         any of the negative proposed clauses. First match wins.

      3. Matching-sequence scoring (C lines 539–630):
         In C this computes delta = current.score[own] − predecessor.score[own]
         and classifies into YES/REJ/BWX/HUH bands. Here we lack the score
         vector, so we approximate: a match alone is evidence the proposal
         aligns with own plan → YES-eligible. Set ``delta_class = 'YES'``.

      4. Legitimacy gate (C lines 645–684):
         Build a candidate-order set and invoke ``legitimacy_gate``. If the
         min per-order score is negative AND the verdict was YES-eligible,
         demote to REJ. (Matches the C "This proposal is now non-legit"
         demotion path.)

      5. Verdict emission:
         YES-eligible & gate ≥ 0  →  YES
         YES-eligible & gate < 0  →  REJ (demoted)
         no match                 →  REJ
         (BWX / HUH require the numeric-delta branches, currently
          unreachable absent the score-vector schema extension.)
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
    matched_index = -1
    pos_set = set(positive)
    neg_set = set(negative)
    for idx, entry in enumerate(state.g_broadcast_list):
        cands = entry.get('order_candidates', []) if isinstance(entry, dict) else []
        # Stringify candidate tokens for comparison with clause text.
        cand_texts = set()
        for c in cands:
            t = c.get('tokens') if isinstance(c, dict) else c
            if t is not None:
                cand_texts.add(' '.join(str(x) for x in t) if isinstance(t, (list, tuple)) else str(t))
        # All positive proposed clauses must be in the candidate set.
        if not pos_set.issubset(cand_texts):
            continue
        # No negative proposed clauses should appear in the candidate set.
        # (C: negative XDOs check the entry's negative sub-tree; here we treat
        # absence from the positive candidate list as sufficient evidence
        # they're not planned.)
        if neg_set & cand_texts:
            continue
        matched_entry = entry
        matched_index = idx
        break

    if matched_entry is None:
        _log.debug(
            "cal_value: no matching sequence for pos=%r neg=%r → REJ",
            positive, negative,
        )
        # C: SEND_LOG("Could not find matching sequence") + BuildAllianceMsg archive.
        import time as _t
        state.g_alliance_msg_tree.add(int(_t.time()))
        return _REJ

    # ── 3. Matching-sequence scoring (delta + verdict bands) ─────────────
    # C (CAL_VALUE.c lines 484–570):
    #   preflight gates — history_flag >= 1, predecessor exists,
    #   predecessor.score[own] >= -79999, predecessor.score[target] >= -79999
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

    # Tree-predecessor: nearest-smaller-key entry in the same catalog
    # (C iterates the std::set<AllianceRecord> which is keyed by int at
    # offset +16, so predecessor = highest-key entry with key < current.key).
    # In the Python port the list is maintained sorted by `key` in
    # send_alliance_press, so predecessor is simply matched_index − 1 when
    # that entry's key is strictly less.
    target_power = matched_entry.get('target_power', own_power_idx)
    history_flag = matched_entry.get('history_flag', 0)
    cur_key = matched_entry.get('key', 0)
    predecessor = None
    if matched_index > 0:
        cand_pred = state.g_broadcast_list[matched_index - 1]
        if isinstance(cand_pred, dict) and cand_pred.get('key', 0) < cur_key:
            predecessor = cand_pred

    use_diff = False
    if history_flag >= 1 and predecessor is not None:
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
    try:
        cand_list = matched_entry.get('order_candidates', [])
        gate_score = legitimacy_gate(
            state, own_power_idx,
            [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)
              if isinstance(c, dict) else 0} for c in cand_list],
        )
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


def _eval_slo(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0041ea20 — SLO (solo-win) proposal evaluator.

    C: YES if own power is in the proposed SLO power list.
    (The `local_4c == 1` guard in C tracks single-proposer; approximated
    here by accepting whenever own power appears.)
    """
    own = state.albert_power_idx
    for tok in rest:
        if _pow_idx(tok) == own:
            return 0x481C   # YES — someone is offering Albert the win
    return 0x4814            # REJ


def _eval_drw(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0041ed30 — DRW (draw) proposal evaluator.

    C logic (from _eval_drw.c):
      bVar6 = True  iff  len(full_input)==2 (i.e. DRW + power_list section)
                   AND own power is in the power list.
      Returns YES  iff  g_draw_sent (DAT_00baed5d) != 0  AND  bVar6.
      Otherwise REJ.

    `rest` is tokens[1:] after DRW is stripped, so C's len==2 ↔ len(rest)==1.
    """
    # C uVar8==2 ↔ Python len(rest)==1 (DRW already consumed)
    if len(rest) != 1:
        return 0x4814   # REJ — not a well-formed DRW proposal

    own = state.albert_power_idx
    bVar5 = False
    pwr_section = rest[0]
    iterable = pwr_section if isinstance(pwr_section, (list, tuple)) else rest
    for tok in iterable:
        if _pow_idx(tok) == own:
            bVar5 = True
            break

    if state.g_draw_sent and bVar5:
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
    power_tokens = [_pow_idx(t) for t in rest if _pow_idx(t) is not None]
    has_dup = len(power_tokens) != len(set(power_tokens))
    bVar4 = (len(rest) < 3) and not has_dup
    bVar2 = bVar3 = False
    for tok in rest:
        p = _pow_idx(tok)
        if p is None:
            continue
        if p == own:
            bVar2 = True
        elif p == from_power:
            bVar3 = True
    if bVar2 and bVar3:
        return 0x481C if bVar4 else 0x4814   # YES or REJ
    if bVar2:
        return _BWX   # own found but proposer not in list
    return 0x481C     # default YES (Albert not named → not applicable)


def _eval_not_dmz(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
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
                    in the DMZ-powers set → ``bVar4 = False``.
                  • If (q,d) is recorded in counter but NOT in promise AND
                    g_near_end_game_factor < 3.0 → ``bVar4 = False``.

      Phase D (lines 244-250) — ally-trust gate using own,from_power scores.
                If iter_powers > 2 and trust gates fail → ``bVar4 = False``.

      Verdict (lines 251-281):
                bVar3 still True   → REJ if !bVar4 else YES
                bVar3 False        → BWX path: returns BWX unless count<3 and
                                     local_cc DOES NOT contain from_power, in
                                     which case fall through to YES/REJ.

    NOTE: The C constructs ``local_7c`` from FUN_00466480 calls on a separate
    caller-provided list (likely ALY relations of own and from_power). That
    arg is not plumbed through to the Python dispatcher, so we use the
    DMZ-powers list itself as the iteration set — sufficient to exercise the
    DMZ-membership and per-pair gates correctly.

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
    iter_powers = list(dmz_powers)                       # local_7c surrogate (see NOTE)

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

            # Sub-check B (lines 186-213): both ledgers record (q,d) AND q ∈ DMZ.
            if in_counter and in_promise and (q in dmz_set):
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

    # bVar3 False: BWX path with from_power-in-DMZ override.
    n_iter = len(iter_powers)
    from_in_dmz = (from_p in dmz_set)
    if n_iter < 3:
        # For n_iter > 1 OR (n_iter == 1 AND from_p ∈ DMZ): emit BWX.
        if n_iter > 1:
            if from_in_dmz:
                return _BWX
            # Fall through to YES/REJ when from_power is not in DMZ-set.
            return _YES if bVar4 else _REJ
        if n_iter == 1 and from_in_dmz:
            return _BWX
        return _YES if bVar4 else _REJ
    return _BWX


def _eval_sub_xdo(rest: list) -> int:
    """
    Port of FUN_0040d450 — SUB XDO evaluator (no `this` / no ECX).

    C (_eval_sub_xdo.c): unconditionally sets *param_1 = REJ and returns.
    Plain cdecl, not __thiscall.
    """
    return 0x4814   # REJ — always


def _eval_single_xdo(state: "InnerGameState", tokens: list,
                     from_power: int = 0) -> int:
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
      NOT NOT XDO      → _cal_value       (local_48 = [NOT, NOT, …])
      SUB PCE          → _eval_not_pce    (FUN_0040d310, same as NOT PCE)
      SUB DMZ          → _eval_not_dmz    (FUN_0041f5a0, same as NOT DMZ)
      SUB XDO          → _eval_sub_xdo    (FUN_0040d450, no `this`)
      SUB NOT XDO      → _cal_value       (local_48 context)
      else             → HUH

    DAT_004c6e14 = 0x4A26 = SUB token (confirmed via research.md §2585).
    """
    _YES, _REJ, _HUH = 0x481C, 0x4814, 0x4806
    _PCE, _DMZ, _ALY = 0x4A10, 0x4A03, 0x4A00
    _XDO, _SLO, _DRW = 0x4A1F, 0x4816, 0x4801
    _NOT, _SUB        = 0x480D, 0x4A26

    _NAME = {
        _PCE: 'PCE', _DMZ: 'DMZ', _ALY: 'ALY',
        _XDO: 'XDO', _SLO: 'SLO', _DRW: 'DRW',
        _NOT: 'NOT', _SUB: 'SUB',
    }

    def _teq(tok, val):
        return tok == val or str(tok).upper() == _NAME.get(val, '')

    if not tokens:
        return _HUH

    t0 = tokens[0]
    rest = tokens[1:]

    if _teq(t0, _PCE):
        return _eval_pce(state, rest, from_power)

    if _teq(t0, _DMZ):
        return _eval_dmz(state, rest, from_power)

    if _teq(t0, _ALY):
        return _eval_aly(state, rest, from_power)

    if _teq(t0, _XDO):
        return _cal_value(state, rest)

    if _teq(t0, _SLO):
        return _eval_slo(state, rest, from_power)

    if _teq(t0, _DRW):
        return _eval_drw(state, rest, from_power)

    if _teq(t0, _NOT):
        if not rest:
            return _HUH
        t1 = rest[0]
        rest2 = rest[1:]
        if _teq(t1, _PCE):
            return _eval_not_pce(state, rest2, from_power)
        if _teq(t1, _DMZ):
            return _eval_not_dmz(state, rest2, from_power)
        if _teq(t1, _XDO):
            return _cal_value(state, [_NOT] + rest)
        if _teq(t1, _NOT):
            if not rest2 or not _teq(rest2[0], _XDO):
                return _HUH
            return _cal_value(state, [_NOT, _NOT] + rest2)
        return _HUH

    if _teq(t0, _SUB):
        # SUB = DAT_004c6e14 = 0x4A26; C logs the message before dispatching
        if not rest:
            return _HUH
        t1 = rest[0]
        rest2 = rest[1:]
        if _teq(t1, _PCE):
            return _eval_not_pce(state, rest2, from_power)   # same as NOT PCE
        if _teq(t1, _DMZ):
            return _eval_not_dmz(state, rest2, from_power)   # same as NOT DMZ
        if _teq(t1, _XDO):
            return _eval_sub_xdo(rest2)                       # FUN_0040d450
        if _teq(t1, _NOT):
            if not rest2 or not _teq(rest2[0], _XDO):
                return _HUH
            return _cal_value(state, [_NOT] + rest2)
        return _HUH

    return _HUH
