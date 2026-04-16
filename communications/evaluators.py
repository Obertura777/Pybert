"""Press-evaluation pipeline, legitimacy handlers, and proposal scoring.

Extracted from ``communications.py`` during the 2026-04 structural refactor.
Behaviour preserved verbatim; only organisation changed.

Contents (by broad role):

* Per-token evaluators (``FUN_0042c040`` family)
    - ``_pow_idx``, ``_flatten_section``, ``_extract_powers``, ``_extract_provs``,
      ``_ally_trust_ok``                        — shared helpers
    - ``_eval_pce``, ``_eval_dmz``, ``_eval_aly``, ``_eval_slo``, ``_eval_drw``,
      ``_eval_not_pce``, ``_eval_not_dmz``, ``_eval_sub_xdo``,
      ``_eval_single_xdo``                      — per-token scorers

* XDO clause handling
    - ``_split_xdo_clauses``                    — head/context split
    - ``_cal_value``                            — headline cal-value score

* Press-evaluation entrypoint
    - ``evaluate_press``                        (FUN_0042fc40)

* Board-state flag computation
    - ``compute_order_dip_flags``               (FUN_004113d0)

* CAL_MOVE and press-action handlers
    - ``cal_move``                              (CAL_MOVE / __thiscall)
    - ``_handle_pce``, ``_handle_aly``, ``_handle_dmz``, ``_handle_xdo``
                                                — YES-branch handlers
    - ``_score_support_opp``, ``_score_sup_attacker``
                                                — XDO scoring helpers
    - ``_cancel_pce``, ``_remove_dmz``, ``_not_xdo``
                                                — NOT-branch handlers

Cross-slice callees still residing in ``communications/__init__.py``
(``legitimacy_gate``, ``build_alliance_msg``, ``_ordered_token_seq_insert``)
are imported lazily inside the seven call sites below to avoid a circular
import — the same pattern used in ``scheduling.py``.
"""

from ..state import InnerGameState
from .parsers import _extract_top_paren_groups

# Module-level constants shared across the evaluators.
_POWER_NAMES = ('AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR')
_NEUTRAL_POWER = 0x14  # 20 — placeholder power index for "no unit / neutral"

def _pow_idx(tok) -> "int | None":
    """Return 0-based power index from a DAIDE power token or name string."""
    if isinstance(tok, int):
        if 0x4100 <= tok <= 0x4106:
            return tok & 0x7f
        return None
    s = str(tok).upper()
    return _POWER_NAMES.index(s) if s in _POWER_NAMES else None


def _eval_pce(state: "InnerGameState", rest: list, from_power: int = 0) -> int:
    """
    Port of FUN_0040d1a0 — PCE proposal evaluator.

    Iterates the power list in the PCE proposal.
    bVar1 = own power found, bVar2 = proposer found, bVar3 = no hostile powers.
    Returns:
      YES if bVar1 AND bVar2 AND bVar3
      REJ if bVar1 AND bVar2 AND NOT bVar3
      BWX otherwise (0x4A02 — "busy waiting", i.e. not applicable to us)
    Hostile = g_EnemyFlag[p]==1 OR g_RelationScore[own][p] < 0.
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
            if int(state.g_EnemyFlag[p]) == 1 or int(state.g_RelationScore[own, p]) < 0:
                bVar3 = False
    if bVar1 and bVar2:
        return 0x481C if bVar3 else 0x4814   # YES or REJ
    return _BWX


# ── Helpers shared by DMZ / ALY / NOT-DMZ evaluators ─────────────────────────

def _flatten_section(section) -> list:
    """Return ``section`` as a flat list of tokens.

    DAIDE sub-lists arrive as nested Python lists/tuples (string-mode press)
    or as flat token streams.  Both are normalised to a flat list.
    """
    if isinstance(section, (list, tuple)):
        out: list = []
        for tok in section:
            if isinstance(tok, (list, tuple)):
                out.extend(_flatten_section(tok))
            else:
                out.append(tok)
        return out
    return [section]


def _extract_powers(section) -> list:
    """Extract a list of 0-based power indices from a DAIDE power sub-list."""
    out: list = []
    for tok in _flatten_section(section):
        p = _pow_idx(tok)
        if p is not None:
            out.append(p)
    return out


def _extract_provs(state: "InnerGameState", section) -> list:
    """Extract province IDs (state.prov_to_id) from a DAIDE province sub-list.

    Tokens may be raw province names ('MUN'), DAIDE province ints, or already
    resolved IDs.  Returns the list in input order, dropping unknown tokens.
    """
    p2id = getattr(state, 'prov_to_id', {}) or {}
    out: list = []
    for tok in _flatten_section(section):
        if isinstance(tok, int):
            # Already a province ID, or a DAIDE prov token; accept the ID
            # path (DAIDE-int → name resolution is server-mode and not
            # plumbed through string-mode press).
            if tok in getattr(state, '_id_to_prov', {}) or 0 <= tok < 256:
                out.append(int(tok))
            continue
        name = str(tok).upper()
        if name in p2id:
            out.append(int(p2id[name]))
    return out


def _ally_trust_ok(state: "InnerGameState", own: int, other: int) -> bool:
    """Replicate the bVar2 ally-trust check used by _eval_dmz.

    C (_eval_dmz.c lines 173-185):
      Forward (own→other):
        Hi[own,other] >= 0 AND (Hi > 0 OR Lo[own,other] > 2)
      Reverse (other→own):
        Hi[other,own] >= 0 AND (Hi > 0 OR Lo[other,own] != 0)
        AND NOT enemy_flag[other]
        AND relation_score[own,other] >= 0
        AND (press_mode == 0
             OR diplomacy_state_b[other] > 0
             OR (diplomacy_state_b[other] >= 0 AND diplomacy_state_a[other] > 1))
    """
    try:
        hi_fwd = int(state.g_AllyTrustScore_Hi[own, other])
        lo_fwd = int(state.g_AllyTrustScore[own, other])
    except Exception:
        return False
    if hi_fwd < 0 or (hi_fwd == 0 and lo_fwd <= 2):
        return False
    try:
        hi_rev = int(state.g_AllyTrustScore_Hi[other, own])
        lo_rev = int(state.g_AllyTrustScore[other, own])
    except Exception:
        return False
    if hi_rev < 0 or (hi_rev == 0 and lo_rev == 0):
        return False
    if int(getattr(state, 'g_EnemyFlag', [0] * 7)[other]) == 1:
        return False
    try:
        rel = int(state.g_RelationScore[own, other])  # DAT_00634e90
    except Exception:
        rel = 0
    if rel < 0:
        return False
    press_mode = int(getattr(state, 'g_PressFlag', 0)) == 1
    if press_mode:
        try:
            ds_b = int(getattr(state, 'g_DiplomacyStateB', [0] * 8)[other])  # DAT_004d5484
            ds_a = int(getattr(state, 'g_DiplomacyStateA', [0] * 8)[other])  # DAT_004d5480
        except Exception:
            ds_a = ds_b = 0
        if not (ds_b > 0 or (ds_b >= 0 and ds_a > 1)):
            return False
    return True


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
      * For each province in sublist-2: walk ``g_OrderList`` looking for an
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
    order_list = getattr(state, 'g_OrderList', []) or []
    from_in_dmz = from_power in dmz_powers

    for prov in prov_ids:
        # Walk g_OrderList for a node justifying DMZ on this province.
        found_qualifying = False
        for entry in order_list:
            if entry.get('province') != prov:
                continue
            if entry.get('ally_power') != from_power:
                continue
            # Match candidate; apply the three gating checks from the BST loop.
            if not entry.get('flag1', False):
                continue
            if not entry.get('flag3', False) and own_in_dmz:
                continue
            if from_in_dmz:
                # Last gate: presence in the dmz-powers std::map (local_48)
                # disqualifies this match.  See NOTE above.
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
              proximity (g_MutualEnemyTable), proposal counter (g_RelationScore),
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
    # We capture the sub-checks that are deterministic from current Albert
    # state and skip the press-mode "promise queue" checks (DAT_004d5480/4
    # = g_DiplomacyStateA/B), which are also gated on press_mode == 1.
    press_mode = int(getattr(state, 'g_PressFlag', 0)) == 1
    enemy_flag = getattr(state, 'g_EnemyFlag', None)
    rel        = state.g_RelationScore           # DAT_00634e90
    ally_mat   = state.g_AllyMatrix              # DAT_006340c0/g_AllyMatrix overlap
    mutual_en  = getattr(state, 'g_MutualEnemyTable', None)  # DAT_00b9fdd8

    for aly_p in aly_powers:
        if aly_p == own:
            continue
        for vss_p in vss_powers:
            # Forward enemy/relation gate.
            if press_mode:
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
    control-flow skeleton faithfully; the delta-score arithmetic (C lines
    539–570) is approximated because Python's g_BroadcastList entries do
    not yet carry the per-power score vector at +0x48 that C's AllianceRecord
    exposes (schema-extension gap tracked in python_parity_overview.md).

    High-level flow (mirrors C):

      1. Clause-extraction phase (C lines 162–280):
         Split ``context_toks`` into positive (plain XDO) and negative
         (NOT-wrapped XDO) clause lists via ``_split_xdo_clauses``.

      2. Sequence-catalog walk (C lines 299–401):
         Iterate ``state.g_BroadcastList`` (the Python equivalent of
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

    # Cross-slice call: ``legitimacy_gate`` still lives in the package
    # ``__init__.py``.  Deferred import at call time avoids a circular import
    # during package initialisation.
    from . import legitimacy_gate

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
    for idx, entry in enumerate(state.g_BroadcastList):
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
        state.g_AllianceMsgTree.add(int(_t.time()))
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
        cand_pred = state.g_BroadcastList[matched_index - 1]
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
    except Exception:
        _log.exception("cal_value: legitimacy_gate raised; treating as non-blocking")
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
                    g_NearEndGameFactor < 3.0 → ``bVar4 = False``.

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

    near_end = float(getattr(state, 'g_NearEndGameFactor', 0.0))

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
        hi = int(state.g_AllyTrustScore_Hi[own, from_p])
        lo = int(state.g_AllyTrustScore[own, from_p])
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


def evaluate_press(state: "InnerGameState", entry: dict) -> int:
    """
    Port of EvaluatePress = FUN_0042fc40.

    Evaluates an AND / ORR / single-XDO press proposal and returns
    YES (0x481C) or REJ (0x4814).  The result is passed directly to
    RESPOND as param_2.

    C flow (decompiled.txt FUN_0042fc40):
      - Clears DAT_00bb65d8 scratch list at entry.
      - Gets first token of press content:
          AND  → count XDO sub-proposals; if count > 1 call CAL_VALUE
                 (FUN_004266b6) for combined score; then evaluate each
                 sub-proposal individually via FUN_0042c040.
                 All must pass → YES; any fail → REJ + clear accepted list.
          ORR  → evaluate each sub-proposal; first YES wins.
                 Random 51% gate: if scratch non-empty, may replace stored
                 accepted proposal with new YES one.
          else → single proposal: call FUN_0042c040 directly.
      - On YES: registers accepted tokens in DAT_00bb65d4 (g_AcceptedProposals).

    CAL_VALUE (FUN_004266b6): wired to _cal_value() for multi-XDO AND coherence.
    FUN_0042c040 = _eval_single_xdo: type dispatcher (PCE/DMZ/ALY/XDO/SLO/DRW/NOT/SUB).
    """
    import random as _random
    import logging as _logging
    _log = _logging.getLogger(__name__)

    _YES, _REJ = 0x481C, 0x4814
    _AND, _ORR, _XDO = 0x4A01, 0x4A0F, 0x4A1F

    # C: clears DAT_00bb65d8 (scratch list) at start of each call.
    # Python: use local scratch; nothing to clear on state.

    press = entry.get('sublist3', entry.get('press_content', []))
    order_cands = entry.get('order_candidates', [])

    if not press and not order_cands:
        return _REJ

    # Extract from_power index for sub-evaluator calls.
    _from_tok = entry.get('from_power_tok', 0)
    _from_pow = (_from_tok & 0x7f) if isinstance(_from_tok, int) and _from_tok >= 0x4100 else 0

    # Identify first token (may be string like 'AND' or int like 0x4A01)
    first = press[0] if press else None
    first_is_and = (first == _AND or str(first).upper() == 'AND')
    first_is_orr = (first == _ORR or str(first).upper() == 'ORR')

    if first_is_and:
        # ── AND path ─────────────────────────────────────────────────────
        # Count XDO sub-proposals among order_cands.
        xdo_count = sum(
            1 for c in order_cands
            if (c.get('tokens') or [''])[0] in (_XDO, 'XDO')
        )

        result_ok = True

        # CAL_VALUE: coherence check for multi-XDO compound proposals.
        # C: if (1 < local_80): psVar5 = CAL_VALUE(this, &uStack_7a)
        if xdo_count > 1:
            cal_verdict = _cal_value(state, press)
            if cal_verdict != _YES:
                result_ok = False

        if result_ok:
            for cand in order_cands:
                tok = cand.get('tokens', [])
                r = _eval_single_xdo(state, tok, _from_pow)
                if r == _YES:
                    # C: FUN_00419300(&DAT_00bb65d4, apvStack_2c, local_6c)
                    state.g_AcceptedProposals.append(tok)
                else:
                    result_ok = False

        if not result_ok:
            state.g_AcceptedProposals.clear()  # C: cleanup loop on failure
            _log.debug("evaluate_press: AND proposal rejected")
            return _REJ

        _log.debug("evaluate_press: AND proposal accepted")
        return _YES

    elif first_is_orr:
        # ── ORR path ─────────────────────────────────────────────────────
        # DAT_00bb65dc == 0 check: scratch list empty at start of call.
        scratch: list = []   # DAT_00bb65d8 analog
        scratch_count = 0    # DAT_00bb65dc analog

        for cand in order_cands:
            tok = cand.get('tokens', [])
            r = _eval_single_xdo(state, tok, _from_pow)
            if r == _YES:
                if scratch_count == 0:
                    scratch = tok
                    scratch_count = 1
                else:
                    # C: (rand()/0x17)%100 < 0x33  → 51% keep, 49% replace
                    rv = _random.randint(0, 0x7FFF)
                    if (rv // 23) % 100 >= 0x33:
                        scratch = tok
                # C: FUN_00419300(&DAT_00bb65d4, ppvVar4, local_6c)
                state.g_AcceptedProposals.append(tok)

        if scratch_count > 0:
            _log.debug("evaluate_press: ORR proposal accepted")
            return _YES

        _log.debug("evaluate_press: ORR proposal rejected")
        return _REJ

    else:
        # ── Single proposal path ─────────────────────────────────────────
        tok = order_cands[0].get('tokens', press) if order_cands else press
        r = _eval_single_xdo(state, tok, _from_pow)
        if r == _YES:
            # C: FUN_00419300(&DAT_00bb65d4, apvStack_4c, &stack0x00000008)
            state.g_AcceptedProposals.append(tok)
            _log.debug("evaluate_press: single proposal accepted")
        else:
            _log.debug("evaluate_press: single proposal rejected")
        return r



# ── compute_order_dip_flags (FUN_004113d0) ────────────────────────────────

def compute_order_dip_flags(state: InnerGameState) -> None:
    """
    Port of ComputeOrderDipFlags (FUN_004113d0).

    Re-initialises the three diplomatic flags on every g_OrderList node:
      flag1 (+0x1c): True  = province is genuinely contested vs. ordering power
      flag2 (+0x1d): True  = bilateral ally coordination is viable
      flag3 (+0x1e): False = hostile unit present at or adjacent to the province

    Called unconditionally from HOSTILITY Block 3 so that ProposeDMZ always
    sees fresh flags.

    Callees (all absorbed / already in unchecked.md):
      FUN_0047a948            — MSVC iterator validity assertion
      TreeIterator_Advance    — adjacency-set BST iterator step
      std_Tree_IteratorIncrement — g_OrderList std::map iterator advance
    """
    own      = getattr(state, 'albert_power_idx', 0)
    press_on = (state.g_PressFlag == 1)
    dipl_a   = getattr(state, 'g_DiplomacyStateA', None)
    dipl_b   = getattr(state, 'g_DiplomacyStateB', None)

    for entry in state.g_OrderList:
        province       = int(entry['province'])
        ordering_power = int(entry['ally_power'])

        # ── Init (lines 48/52/56 of decompile) ───────────────────────────────
        flag1 = True
        flag2 = True
        flag3 = False

        # ── Phase 1a: g_ScOwner check (lines 57–68) ──────────────────────────
        # g_ScOwner[prov] == ordering_power → province already owned by orderer
        # g_ScOwner[prov] == own            → we own it; no bilateral coord needed
        sc_owner = int(state.g_ScOwner[province]) if province < len(state.g_ScOwner) else -1
        if sc_owner == ordering_power:
            flag1 = False
        elif sc_owner == own:
            flag2 = False

        # ── Phase 1b: board unit at province (lines 69–85) ───────────────────
        # Unit belonging to own_power → not contested (flag1=0)
        # Unit belonging to ordering_power → ordering power already there (flag2=0)
        unit = state.unit_info.get(province)
        if unit is not None:
            occ = int(unit['power'])
            if occ == own:
                flag1 = False
            elif occ == ordering_power:
                flag2 = False

        # ── Phase 2: trust/stab check at province (lines 86–115) ─────────────
        # Only runs when a unit is present (*(char*)(board+prov*0x24+3) != '\0').
        if unit is not None:
            occ = int(unit['power'])
            # Clear flag2 when the occupant is not a trustworthy ally of own_power:
            #   neutral, enemy-stab flagged, own unit, or zero trust.
            if occ == _NEUTRAL_POWER:
                flag2 = False
            elif 0 <= occ < 7 and int(state.g_EnemyFlag[occ]) == 1:
                flag2 = False
            elif occ == own:
                flag2 = False
            elif 0 <= occ < 7 and (
                int(state.g_AllyTrustScore[own, occ]) == 0 and
                int(state.g_AllyTrustScore_Hi[own, occ]) == 0
            ):
                flag2 = False

            # Set flag3 when ordering_power does not trust the occupant
            # (occ is neutral or ordering_power has zero trust in occ).
            if occ != ordering_power:
                if occ == _NEUTRAL_POWER or (
                    0 <= occ < 7 and
                    int(state.g_AllyTrustScore[ordering_power, occ]) == 0 and
                    int(state.g_AllyTrustScore_Hi[ordering_power, occ]) == 0
                ):
                    flag3 = True

        # ── Phase 3: adjacent-province units (inner loop, lines 116–177) ─────
        for adj_prov in state.get_unit_adjacencies(province):
            adj_unit = state.unit_info.get(adj_prov)
            if adj_unit is None:
                continue
            occ = int(adj_unit['power'])

            # Enemy-stab flag always clears flag2 (lines 142–147).
            if 0 <= occ < 7 and int(state.g_EnemyFlag[occ]) == 1:
                flag2 = False

            # Press-on block (lines 148–164).
            if press_on:
                # Ordering power's own unit at adj → skip remaining checks for
                # this adj province (goto LAB_004116fa in C).
                if occ == ordering_power:
                    continue
                if occ != own and occ != _NEUTRAL_POWER and 0 <= occ < 7:
                    t_hi = int(state.g_AllyTrustScore_Hi[own, occ])
                    t_lo = int(state.g_AllyTrustScore[own, occ])
                    d_b  = int(dipl_b[occ]) if dipl_b is not None else 0
                    d_a  = int(dipl_a[occ]) if dipl_a is not None else 0
                    # int64 trust < 2  OR  DiplomacyState < 2
                    if (t_hi < 0 or
                            (t_hi < 1 and t_lo < 2) or
                            (d_b < 1 and (d_b < 0 or d_a < 2))):
                        flag2 = False

            # flag3: ordering_power does not trust this adjacent occupant
            # (lines 165–172).
            if occ != ordering_power and occ != own and occ != _NEUTRAL_POWER:
                if (0 <= occ < 7 and
                        int(state.g_AllyTrustScore[ordering_power, occ]) == 0 and
                        int(state.g_AllyTrustScore_Hi[ordering_power, occ]) == 0):
                    flag3 = True

        # ── Write back ────────────────────────────────────────────────────────
        entry['flag1'] = flag1
        entry['flag2'] = flag2
        entry['flag3'] = flag3



# ── CAL_MOVE, YES/NOT handlers, XDO scoring ───────────────────────────────

def cal_move(state: InnerGameState, press_tokens: list) -> bool:
    """
    Port of CAL_MOVE (named; __thiscall).

    Dispatches a press proposal token list to the appropriate DAIDE keyword
    handler based on the leading token.  Called per inner-list entry in
    EvaluateOrderProposalsAndSendGOF; returns True (1) to trigger the GOF
    commit path.

    press_tokens: flat list of DAIDE token strings for the proposal, e.g.
        ['PCE', ...] or ['NOT', 'XDO', ...] (NOT wrapper already unwrapped
        at the C level via GetSubList/AppendList before the inner dispatch).

    C structure:
      1. GetListElement(list, &out, 0) — read first token (position 0; all
         else-branch calls also read position 0: Ghidra artifact of the
         same register being reused, not list advancement).
      2. if PCE  → FUN_00465f60(local, list) + PCE(this)
         if ALY  → FUN_00465f60(local, list) + ALY(this)
         if DMZ  → FUN_00465f60(local, list) + DMZ(this)
         if XDO  → FUN_00405090(...) + FUN_00465f60(local, list) + XDO()
         if NOT  → GetSubList(list, tmp, 1) + AppendList(list, tmp) +
                   FreeList(tmp)  [unwrap NOT(…)] then:
             if PCE → FUN_00465f60 + CANCEL(this)
             if DMZ → FUN_00465f60 + REMOVE_DMZ(this)
             if XDO → FUN_00405090 + FUN_00465f60 + NOT_XDO()
      3. FreeList(list) + SerializeOrders(…) + _free(…)
    """
    if not press_tokens:
        return False

    first = press_tokens[0]

    if first == 'PCE':
        # C: FUN_00465f60 copies list to local; PCE(this) gets that local
        return bool(_handle_pce(state, press_tokens))

    if first == 'ALY':
        return bool(_handle_aly(state, press_tokens))

    if first == 'DMZ':
        return bool(_handle_dmz(state, press_tokens))

    if first == 'XDO':
        # C: FUN_00405090 preps a target ptr; FUN_00465f60 copies list to local
        return bool(_handle_xdo(state, press_tokens))

    if first == 'NOT':
        # C: GetSubList extracts the inner parenthesised content of NOT(…),
        # AppendList flattens it back into the working list, FreeList frees the
        # temp wrapper.  Net effect: inner tokens of NOT are exposed for the
        # second-level dispatch.
        inner_tokens = press_tokens[1:]   # strip leading NOT token
        if not inner_tokens:
            return False
        inner_first = inner_tokens[0]
        if inner_first == 'PCE':
            return bool(_cancel_pce(state, inner_tokens))
        if inner_first == 'DMZ':
            return bool(_remove_dmz(state, inner_tokens))
        if inner_first == 'XDO':
            return bool(_not_xdo(state, inner_tokens))

    return False


# ── Callee stubs (all UNCHECKED — addresses unknown) ─────────────────────────

def _handle_pce(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function PCE() at address 0x0041dc10.

    Evaluates a PCE (peace) proposal from another power.  Called from
    cal_move() when the leading press token is 'PCE'.

    tokens[0] == 'PCE'; tokens[1:] == power indices included in the proposal.

    Algorithm:
      1. For every ordered pair (power_i, power_j) of PCE powers where i != j:
           - If power_i == own_power: mark power_j as PCE-applied this turn
             (g_TurnOrderHist_Lo[power_j] = 2).
           - Compute new trust = max(1, 3 − g_StabCounter[i,j]), capped at 3
             when _g_NearEndGameFactor >= 4.0.
           - Update g_AllyTrustScore[i,j] / g_AllyTrustScore_Hi[i,j] if the
             new trust (as uint64) exceeds the current value.
      2. If any score was updated: log + BuildAllianceMsg(0x66) (recalc notice).
      3. If g_PressFlag == 1 (trust-override / press mode active):
           - Scan all 7 powers; if any power still has a pending PCE flag
             (g_TurnOrderHist_Lo == 1) or has zero trust despite having
             a DiplomacyState entry, the peace deal is not yet complete.
           - If ALL powers accepted: log, BuildAllianceMsg(0x65), restore
             g_AllyTrustScore[own,*] from g_DiplomacyStateA/B snapshot.
      4. If changed: call ComputeOrderDipFlags (FUN_004113d0) — not yet ported.

    Returns True if the trust matrix was updated (signals GOF recalculation).
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging
    _log = logging.getLogger(__name__)

    own_power  = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # tokens[1:] are the power indices inside PCE ( pow1 pow2 ... )
    pce_powers = [int(t) for t in tokens[1:]]
    n = len(pce_powers)

    changed = False

    # ── Double loop: all ordered pairs (i, j), i != j ────────────────────────
    for i in range(n):
        power_i = pce_powers[i]   # uVar16
        for j in range(n):
            if i == j:
                continue
            power_j = pce_powers[j]   # uVar12

            # If own power is in the pair: mark power_j as PCE-applied
            # C: if (uVar16 == uVar4) { DAT_004d53d8[uVar12*2] = 2; DAT_004d53dc[uVar12*2] = 0; }
            if power_i == own_power:
                state.g_TurnOrderHist_Lo[power_j] = 2
                state.g_TurnOrderHist_Hi[power_j] = 0

            # Compute trust: 3 − g_StabCounter[i,j] clamped to [1, 3]
            # When near-end-game (factor >= 4.0) always use 3.
            # C: uVar9 = 3; if (_g_NearEndGameFactor < 4.0) uVar9 = max(1, 3-stab)
            if state.g_NearEndGameFactor < 4.0:
                trust = 3 - int(state.g_StabCounter[power_i, power_j])
                if trust < 1:
                    trust = 1
            else:
                trust = 3

            # int64 sign-extend trust → (trust_hi, trust_lo)
            # C: iVar14 = (int)uVar9 >> 0x1f  → 0 for positive trust
            trust_hi = trust >> 31   # always 0 for trust in [1,3]

            curr_hi = int(state.g_AllyTrustScore_Hi[power_i, power_j])
            curr_lo = int(state.g_AllyTrustScore[power_i, power_j])

            # Update if (trust_hi, trust) > (curr_hi, curr_lo) as uint64.
            # C: curr_hi <= trust_hi AND (curr_hi < trust_hi OR curr_lo_uint < trust_uint)
            if curr_hi <= trust_hi and (curr_hi < trust_hi or curr_lo < trust):
                state.g_AllyTrustScore[power_i, power_j]    = trust
                state.g_AllyTrustScore_Hi[power_i, power_j] = trust_hi
                changed = True

    # ── If any score changed: log + BuildAllianceMsg(0x66) ───────────────────
    if changed:
        powers_str = ' '.join(str(p) for p in pce_powers)
        _log.debug("Recalculating: Because we have applied a peace deal %s", powers_str)
        # C: BuildAllianceMsg(&DAT_00bbf638, &pvStack_38, 0x66)
        build_alliance_msg(state, 0x66)

    # ── All-powers-accepted check (only when g_PressFlag == 1) ───────────────
    # C: if (DAT_00baed68 == '\x01') { ... if (bVar3) goto LAB_0041deab; ... }
    if state.g_PressFlag == 1:
        dipl_a_arr = getattr(state, 'g_DiplomacyStateA', None)
        dipl_b_arr = getattr(state, 'g_DiplomacyStateB', None)
        not_all_accepted = False
        for i in range(num_powers):
            # Condition 1: pending PCE flag (sent but not yet applied)
            # C: DAT_004d53d8[i*2] == 1 AND DAT_004d53dc[i*2] == 0
            if int(state.g_TurnOrderHist_Lo[i]) == 1 and int(state.g_TurnOrderHist_Hi[i]) == 0:
                not_all_accepted = True

            # Condition 2: own has no trust with power i despite diplomatic state
            # C: g_AllyTrustScore[own*21+i]==0 AND g_AllyTrustScore_Hi==0
            #    AND (DAT_004d5480[i*2]!=0 OR DAT_004d5484[i*2]!=0)
            t_lo = int(state.g_AllyTrustScore[own_power, i])
            t_hi = int(state.g_AllyTrustScore_Hi[own_power, i])
            dipl_a = int(dipl_a_arr[i]) if dipl_a_arr is not None else 0
            dipl_b = int(dipl_b_arr[i]) if dipl_b_arr is not None else 0
            if t_lo == 0 and t_hi == 0 and (dipl_a != 0 or dipl_b != 0):
                not_all_accepted = True

        if not not_all_accepted:
            # All powers accepted — restore trust from DiplomacyState snapshot
            _log.debug("ALL powers have accepted PCE: return to original plan")
            # C: BuildAllianceMsg(&DAT_00bbf638, &pvStack_38, 0x65)
            build_alliance_msg(state, 0x65)

            # C: puVar11 = &g_AllyTrustScore + uVar4*0x2a; copies DAT_004d5480/4 into it
            if dipl_a_arr is not None and dipl_b_arr is not None:
                for i in range(num_powers):
                    state.g_AllyTrustScore[own_power, i]    = int(dipl_a_arr[i])
                    state.g_AllyTrustScore_Hi[own_power, i] = int(dipl_b_arr[i])
            changed = True

    # ── If changed: ComputeOrderDipFlags (FUN_004113d0) ─────────────────────
    # C: LAB_0041deab falls through to FUN_004113d0 when cStack_52 == '\x01'
    if changed:
        compute_order_dip_flags(state)

    return changed


def _handle_aly(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function ALY() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'ALY'.

    tokens layout (from CAL_MOVE pre-processing):
        tokens[0] == 'ALY'
        tokens[1..] == powers listed in ALY ( p1 p2 ... ) VSS ( v1 v2 ... )
    The raw press list still contains both the ALY sub-list and the VSS
    sub-list; we extract them via the same GetSubList(index=1) / (index=3)
    convention used in the C code.

    Algorithm (decompile §ALY, decompiled.txt lines 57–143):

      uStack_74 = own_power   (from *(param_1+8)+0x2424)
      local_58  = GetSubList(press_list, 1)  → ALY power list
      local_48  = GetSubList(press_list, 3)  → VSS power list

      For each aly_power in ALY list:
        For each vss_power in VSS list:
          if aly_power == own_power: skip            (line 83)
          idx = vss_power + aly_power * 21           (line 84)
          if g_AllyMatrix[idx] < 1:
              g_AllyMatrix[idx] = 1; changed = True  (lines 85–88)
          if g_EnemyDesired == 1 and g_AllyTrustScore_Hi[aly,vss] >= 0:
              g_AllyTrustScore[aly,vss]    = 0       (lines 89–93)
              g_AllyTrustScore_Hi[aly,vss] = 0
              g_RelationScore[aly,vss]     = 0
              changed = True
          own_idx = own_power * 21 + aly_power       (line 95)
          if trust[own→aly] == 0 (both lo and hi)
             AND enemy_flag_lo[aly] == 0
             AND enemy_flag_hi[aly] == 0:            (lines 96–97)
              build PCE(own, aly_power) and call _handle_pce()
              changed = True                         (lines 98–112)

      If changed:
        log "Recalculating: Because we have applied an ALY: (%s)"
        BuildAllianceMsg(0x66) — stub

      Returns True (\\x01) if anything was changed.

    Global mapping:
      own_power           ← *(param_1+8)+0x2424  = state.albert_power_idx
      g_AllyMatrix        ← &g_AllyMatrix[row*21+col]  (char, 21×21 flat)
      g_EnemyDesired      ← DAT_00baed5f  = state.g_StabbedFlag / g_EnemyDesired
      g_AllyTrustScore    ← &g_AllyTrustScore[idx*2]   (lo word of uint64)
      g_AllyTrustScore_Hi ← &g_AllyTrustScore_Hi[idx*2](hi word of uint64)
      g_RelationScore     ← DAT_00634e90  = state.g_RelationScore[row,col]
      g_EnemyFlag         ← DAT_004cf568/6c  = state.g_EnemyFlag[power] lo/hi

    Callee added to Unchecked: none new (BuildAllianceMsg already unchecked).
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own_power = getattr(state, 'albert_power_idx', 0)

    # ── Extract ALY and VSS power sub-lists ──────────────────────────────────
    # C: GetSubList(&stack0x4, apuStack_68, 1) → local_58 (ALY powers)
    #    GetSubList(&stack0x4, apuStack_68, 3) → local_48 (VSS powers)
    # tokens layout after CAL_MOVE: ['ALY', aly_p1, aly_p2, ..., 'VSS', vss_p1, ...]
    # Find the VSS boundary inside the token list.
    try:
        vss_idx = tokens.index('VSS')
        aly_powers = [int(t) for t in tokens[1:vss_idx]]
        vss_powers = [int(t) for t in tokens[vss_idx + 1:]]
    except ValueError:
        # No VSS keyword — treat entire token payload as ALY powers, VSS list empty.
        aly_powers = [int(t) for t in tokens[1:]]
        vss_powers = []

    changed = False

    # ── Double loop: ALY × VSS ────────────────────────────────────────────────
    for aly_power in aly_powers:          # uVar5 / bVar2
        for vss_power in vss_powers:      # *pbVar6 (inner)

            # C line 83: if (uVar5 != uStack_74) { ... }
            if aly_power == own_power:
                continue

            # C line 84: iVar7 = (uint)*pbVar6 + uVar5 * 0x15
            # iVar7 is used as flat index into g_AllyMatrix (21-wide)
            idx = int(vss_power) + aly_power * 21    # iVar7

            # C lines 85–88: g_AllyMatrix[iVar7] < 1  → set to 1
            if int(state.g_AllyMatrix[aly_power, vss_power]) < 1:
                state.g_AllyMatrix[aly_power, vss_power] = 1
                changed = True

            # C lines 89–93: g_EnemyDesired==1 AND trust_hi[aly,vss] >= 0
            #   → zero g_AllyTrustScore, g_AllyTrustScore_Hi, g_RelationScore
            enemy_desired = int(getattr(state, 'g_StabbedFlag', 0))   # DAT_00baed5f
            trust_hi_av = int(state.g_AllyTrustScore_Hi[aly_power, vss_power])
            if enemy_desired == 1 and trust_hi_av >= 0:
                # C: (&g_AllyTrustScore)[iVar7*2] = 0; (&g_AllyTrustScore_Hi)[iVar7*2] = 0
                state.g_AllyTrustScore[aly_power, vss_power]    = 0
                state.g_AllyTrustScore_Hi[aly_power, vss_power] = 0
                # C: (&DAT_00634e90)[iVar7] = 0   — g_RelationScore
                state.g_RelationScore[aly_power, vss_power]     = 0
                changed = True

            # C line 95: iVar7 = uStack_74 * 0x15 + uVar5  (own→aly direction)
            # C lines 96–97: trust[own→aly] == 0 AND enemy flags of aly_power == 0
            trust_lo_oa = int(state.g_AllyTrustScore[own_power, aly_power])
            trust_hi_oa = int(state.g_AllyTrustScore_Hi[own_power, aly_power])

            # DAT_004cf568[uVar5*2] and DAT_004cf56c[uVar5*2]:
            # these are the lo/hi int32 words of g_EnemyFlag for aly_power
            enemy_flag = getattr(state, 'g_EnemyFlag', None)
            if enemy_flag is not None:
                ef_lo = int(enemy_flag[aly_power])
                # hi word — stored in a separate array or second element
                ef_hi_arr = getattr(state, 'g_EnemyFlag_Hi', None)
                ef_hi = int(ef_hi_arr[aly_power]) if ef_hi_arr is not None else 0
            else:
                ef_lo = ef_hi = 0

            if (trust_lo_oa == 0 and trust_hi_oa == 0
                    and ef_lo == 0 and ef_hi == 0):
                # C lines 98–112: build PCE(own, aly_power) and evaluate it
                # C: local_90[0] = token for own_power side
                #    local_8c[0] = bVar2 | 0x4100  (aly_power with DAIDE power flag)
                # In Python: synthesise tokens list for _handle_pce
                pce_tokens = ['PCE', own_power, aly_power]
                _handle_pce(state, pce_tokens)
                changed = True

    # ── Log + BuildAllianceMsg if anything changed ───────────────────────────
    if changed:
        aly_str = ' '.join(str(p) for p in aly_powers)
        _log.debug(
            "Recalculating: Because we have applied an ALY: (%s)", aly_str
        )
        # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_68, (int*)&puStack_7c=0x66)
        build_alliance_msg(state, 0x66)

    return changed


def _handle_dmz(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function DMZ() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'DMZ'.

    C signature: char __fastcall DMZ(int param_1)
    param_1 is the press token-stream pointer (stack0x00000004 in the caller).
    Returns '\x01' (True) if the DMZ agreement was applied / any state changed.

    Token layout after CAL_MOVE preprocessing:
        tokens[0] == 'DMZ'
        tokens[1..n] == powers in the DMZ  (sublist index 1 in C)
        tokens[n+1..] == provinces in the DMZ  (sublist index 2 in C)

    Algorithm (faithful to decompile):

      own_power  = albert_power_idx  (piStack_88)
      dmz_powers = GetSubList(press, 1)  → local_74  (the DMZ power list)
      dmz_provs  = GetSubList(press, 2)  → local_48  (the DMZ province list)

      Outer double loop over dmz_powers (i, j):
        Condition: (i != j) OR len(dmz_powers) == 1.
        Inner loop over dmz_provs (province k):

          piVar4  = dmz_powers[i]   (outer power; piStack_ac saved copy)
          piVar9  = dmz_provs[k]    (the province being DMZ'd; piStack_b0)

          BRANCH A — piVar4 == own_power:
            Walk g_DmzOrderList (DAT_00bb65e4, sentinel DAT_00bb65e0).
            For each record rec:
              if rec.owner_power == own_power: skip  (*(pCVar8+0xc) == piStack_88)
              iVar10 = rec.owner_power
              iStack_34 = DAT_00bb6f2c[iVar10*3]  (province-tree record for that power)
              call GameBoard_GetPowerRec(DAT_00bb6f28+iVar10*0xc, aiStack_30, province_k)
                → check record validity (non-null, non-sentinel)
              if puVar7[1] == iStack_34:   (province k belongs to this power's territory)
                cStack_b1 = '\x01'         (DMZ accepted for this province/power)
                StdMap_FindOrInsert(owner_power_base, apvStack_18, province_k)
                  → g_ActiveDmzMap[province_k] = rec.owner_power  (record the DMZ)

          BRANCH B — piVar4 != own_power:
            iVar10 = DAT_00bb702c[piVar4*3]  (this power's province-tree record)
            puVar11 = DAT_00bb7028 + piVar4*0xc  (power-record base address)
            GameBoard_GetPowerRec(puVar11, aiStack_28, province_k)
            if puVar7[1] == iVar10:   (province k is in this power's territory)
              cStack_b1 = '\x01'
              StdMap_FindOrInsert(puVar11, &pvStack_64, province_k)
                → g_ActiveDmzMap[province_k] = piVar4
            Walk g_ActiveDmzList (DAT_00bb7134, sentinel DAT_00bb7130):
              For each rec:
                if rec[3] == piVar4 (outer power)
                   AND rec[4] != piVar9 (different province than current):
                  FUN_00412280(DAT_00bb7130, aiStack_20, (int)puVar11, rec)
                    → remove this stale DMZ entry  (erase from g_ActiveDmzList)

      If cStack_b1 == '\x01':
        FUN_0046b050(...)  (serialize DMZ token list to string — absorbed as log)
        SEND_LOG("Recalculating: Because we have applied a DMZ: (%s)")
        BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  (stub)

      Returns cStack_b1  (True if any change, False otherwise)

    Global mapping:
      own_power       ← state.albert_power_idx
      g_DmzOrderList  ← state.g_DmzOrderList   list[dict]:
                          each entry: {'owner_power': int, 'provinces': set, 'active': bool}
      g_ActiveDmzMap  ← state.g_ActiveDmzMap    dict: {province: power} — accepted DMZ entries
      g_ActiveDmzList ← state.g_ActiveDmzList   list[dict]:
                          each entry: {'power': int, 'province': int} — active agreements
      g_ScOwner       ← state.g_ScOwner[province]  — province SC owner index
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own_power = getattr(state, 'albert_power_idx', 0)

    # ── Extract DMZ powers (sublist 1) and DMZ provinces (sublist 2) ──────────
    # C: GetSubList(&stack4, &pvStack_64, 1) → local_74  (power list)
    #    GetSubList(&stack4, &pvStack_64, 2) → local_48  (province list)
    # tokens layout: ['DMZ', pow1, pow2, ..., prov1, prov2, ...]
    # We split on the first integer run vs a possible explicit list separator.
    # In practice CAL_MOVE passes the raw sub-token list; we extract two int groups.
    dmz_powers: list = []
    dmz_provs:  list = []
    # Simple heuristic: collect ints from tokens[1:]; power indices are small (<7),
    # province indices can be larger.  The C GetSubList(1) returns the first nested
    # parenthesised group and GetSubList(2) the second.  With flat token lists we
    # rely on the split being signalled by a non-int sentinel, or fall back to
    # "first group = powers (values < 7), second group = provinces".
    # More robust: if tokens contain explicit sentinels they were stripped by CAL_MOVE.
    # We therefore split by value: tokens < 7 are powers, ≥ 7 are provinces.
    for tok in tokens[1:]:
        try:
            v = int(tok)
        except (ValueError, TypeError):
            continue
        if v < 7:
            dmz_powers.append(v)
        else:
            dmz_provs.append(v)

    if not dmz_powers or not dmz_provs:
        return False

    # uStack_80 = FUN_00465930(local_74)  — count of dmz_powers
    # uStack_8c = FUN_00465930(local_48)  — count of dmz_provs
    n_powers = len(dmz_powers)   # uStack_80
    n_provs  = len(dmz_provs)    # uStack_8c

    # cStack_b1 — return value / changed flag
    changed = False

    # Lazy-init the two DMZ state dicts if not present on state
    if not hasattr(state, 'g_DmzOrderList'):
        state.g_DmzOrderList = []   # DAT_00bb65e0/e4: list[dict{owner_power,provinces}]
    if not hasattr(state, 'g_ActiveDmzMap'):
        state.g_ActiveDmzMap = {}   # DAT_00bb6f28/*: {province: power}
    if not hasattr(state, 'g_ActiveDmzList'):
        state.g_ActiveDmzList = []  # DAT_00bb7130/34: list[dict{power, province}]

    g_DmzOrderList: list = state.g_DmzOrderList
    g_ActiveDmzMap: dict = state.g_ActiveDmzMap
    g_ActiveDmzList: list = state.g_ActiveDmzList

    # ── Outer double loop: powers i, j ────────────────────────────────────────
    # C: if (0 < (int)uVar3) { do { ... } while (iStack_90 < (int)uVar3); }
    # Outer i (iStack_90), inner j (iStack_84):
    #   condition inner body runs: (i != j) OR (uVar3 == 1)
    for i_idx in range(n_powers):
        outer_power = dmz_powers[i_idx]  # piVar4 / piStack_ac

        for j_idx in range(n_powers):
            # C: if (((iVar10 != iVar13) || (uVar3 == 1)) && (iStack_a4 = 0, 0 < (int)uStack_8c))
            if i_idx == j_idx and n_powers != 1:
                continue

            # ── Inner k loop: each DMZ province ─────────────────────────────
            for k_idx in range(n_provs):
                province = dmz_provs[k_idx]   # piVar9 / piStack_b0

                if outer_power == own_power:
                    # ── BRANCH A: own power is in the DMZ pair ────────────────
                    # C lines 97–140: walk g_DmzOrderList (DAT_00bb65e4 .. sentinel DAT_00bb65e0)
                    # For each rec:
                    #   if rec.owner_power == own_power: skip
                    #   iVar10 = rec.owner_power
                    #   puVar7 = GameBoard_GetPowerRec(base+owner*0xc, buf, &province)
                    #   if puVar7[1] == iStack_34: → StdMap_FindOrInsert + changed
                    for rec in list(g_DmzOrderList):
                        rec_owner = int(rec.get('owner_power', -1))
                        # C: if (*(int*)(pCVar8+0xc) != piStack_88) → process; else next
                        if rec_owner == own_power:
                            # skip: the decompile skips when owner == own_power
                            # (outer block only runs the body when rec_owner != piStack_88)
                            continue
                        # GameBoard_GetPowerRec check:
                        # "does province k fall within rec_owner's territory?"
                        # In Python: check g_ScOwner for this province.
                        sc_owner = int(state.g_ScOwner[province]) if province < len(state.g_ScOwner) else -1
                        if sc_owner == rec_owner:
                            # puVar7[1] == iStack_34 → accept: cStack_b1 = '\x01'
                            changed = True
                            # StdMap_FindOrInsert: register the accepted DMZ for this province
                            # absorb as: g_ActiveDmzMap[province] = rec_owner
                            g_ActiveDmzMap[province] = rec_owner

                else:
                    # ── BRANCH B: non-own outer power ─────────────────────────
                    # C lines 143–185:
                    # puVar11 = &DAT_00bb7028 + piVar4*0xc  (outer_power's base)
                    # GameBoard_GetPowerRec check → province k in outer_power's territory?
                    sc_owner = int(state.g_ScOwner[province]) if province < len(state.g_ScOwner) else -1
                    if sc_owner == outer_power:
                        # cStack_b1 = '\x01'; StdMap_FindOrInsert → accept DMZ
                        changed = True
                        g_ActiveDmzMap[province] = outer_power

                    # ── Walk g_ActiveDmzList: remove stale entries ─────────────
                    # C lines 153–184:
                    # Walk DAT_00bb7134 list; for each rec:
                    #   if ppiVar12[3] == piStack_ac (outer_power)
                    #      AND ppiVar12[4] != piVar9 (province k was NOT this province):
                    #     FUN_00412280(DAT_00bb7130, ..., rec)  → erase from list
                    #  (restart iteration after erase matches C do-while restart)
                    restart = True
                    while restart:
                        restart = False
                        for idx, active_rec in enumerate(list(g_ActiveDmzList)):
                            rec_power   = int(active_rec.get('power', -1))
                            rec_province = int(active_rec.get('province', -1))
                            if rec_power == outer_power and rec_province != province:
                                # FUN_00412280: erase this stale DMZ entry
                                # C: ppiStack_94 = (int**)*DAT_00bb7134 after erase
                                #    (the list head is reset to the new front)
                                try:
                                    g_ActiveDmzList.remove(active_rec)
                                except ValueError:
                                    pass
                                restart = True
                                break

    # ── Post-loop: if changed, log and BuildAllianceMsg ───────────────────────
    # C lines 198–220:
    #   FUN_0046b050(...)  → serialize province list (absorbed as debug log)
    #   SEND_LOG("Recalculating: Because we have applied a DMZ: (%s)")
    #   BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  (stub)
    if changed:
        prov_str = ' '.join(str(p) for p in dmz_provs)
        _log.debug(
            "Recalculating: Because we have applied a DMZ: (%s)", prov_str
        )
        # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
        build_alliance_msg(state, 0x66)

    return changed


def _handle_xdo(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function XDO() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'XDO'.
    Preceded by FUN_00405090 prep in the caller (provides in_stack_00000018 =
    the outer candidate-proposal list, passed as the second state-based
    parameter here via state.g_xdo_candidate_list).

    Algorithm (faithful to decompile, decompiled.txt lines 2–266):

      1. Init three empty local token lists (local_40, local_2c, local_1c).
         Allocate a local proposal sentinel (local_74).
      2. GetSubList(&stack4, 1) → local_40 = XDO inner content
         (the full order triple: unit, order-type, destination).
      3. Element 0 of sublist 0 → bVar3 = sender power (byte).
         FUN_00465930(local_40) → uVar11 = element count of local_40.
         FUN_00419300(DAT_00bb65f8 + bVar3*0xc, ..., local_40)
           → register this XDO proposal into sender's proposal map
             (g_XdoProposalBySender[sender_power]).
      4. Element 2 of sublist 0 → pvStack_80 = destination/scope province.
         StdMap_FindOrInsert(DAT_00bb6bf8 + bVar3*0xc, ..., pvStack_80)
           → g_XdoDestBySender[sender_power][dest_prov] = dest_prov
         StdMap_FindOrInsert(DAT_00bb713c, ..., pvStack_80)
           → g_XdoGlobalDestMap[dest_prov] = dest_prov
      5. Element 0 of sublist 1 → sVar4 = order command token (short).
      6a. If MTO or CTO:
            Element 0 of sublist 2 → ppiStack_7c = destination province.
            Loop over g_xdo_candidate_list (in_stack_00000018):
              ScoreSupportOpp(DAT_00bb67f8 + entry.power * 0xc, buf,
                               (dest_prov, dest_prov))
      6b. If SUP:
            local_2c = GetSubList(local_40, 2)  (the supported unit sub-token)
            sublist-1 element 0 → unused (supported unit identity)
            sublist-2 element 0 → ppiVar14 = supported power
            sublist-0 of sublist-2 of local_40  element 0 → bVar3 re-read
              = province of the unit being supported (piStack_b0)
            StdMap_FindOrInsert(DAT_00bb713c, ..., ppiStack_7c)
              → g_XdoGlobalDestMap[ppiStack_7c] = ppiStack_7c
            If uVar11 == 5 (SUP MTO — 5-element XDO):
              ScoreSupportOpp(DAT_00bb69f8 + bVar3*0xc, buf,
                               (ppiVar14, ppiVar16))
              Loop over g_xdo_candidate_list:
                FUN_004193f0(DAT_00bb68f8 + entry.power*0xc, buf,
                              (dest_prov, dest_prov))
            Else (SUP HLD):
              StdMap_FindOrInsert(DAT_00bb6af8 + bVar3*0xc, ...,
                                   ppiStack_7c)
              Loop over g_xdo_candidate_list:
                FUN_004193f0(DAT_00bb68f8 + entry.power*0xc, buf,
                              (dest_prov, dest_prov))
      7. Log "Recalculating: Because we have applied a XDO: (%s)" +
         BuildAllianceMsg(0x66) stub.
      8. Clear local_74 sentinel via SerializeOrders (absorbed as no-op).
         Clear in_stack_00000018 = g_xdo_candidate_list via SerializeOrders
         + _free (absorbed as list clear).
      9. Return True (\x01).

    New global state fields:
      g_XdoProposalBySender : dict[int, list]  — DAT_00bb65f8 per-power list
      g_XdoDestBySender     : dict[int, dict]  — DAT_00bb6bf8 per-power map
      g_XdoGlobalDestMap    : dict             — DAT_00bb713c global map
      g_xdo_candidate_list  : list[dict]       — in_stack_00000018 from FUN_00405090

    Unchecked callees: ScoreSupportOpp (DAT_00bb67f8/00bb69f8 paths),
                       FUN_004193f0 (DAT_00bb68f8 path),
                       FUN_00419300 (XDO proposal registration),
                       BuildAllianceMsg (stub).
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg, _ordered_token_seq_insert

    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── Parse token stream ────────────────────────────────────────────────────
    # Expected layout after CAL_MOVE: ['XDO', sender_power, order_cmd, dest_prov, ...]
    # Mirrors C layer: GetSubList(press, 1) → local_40 = XDO inner content.
    # De-serialised here from the flat token list.
    if len(tokens) < 2:
        return True   # always returns 1 per decompile; just no-op if malformed

    # ──  Step 3: sender power = element 0 (byte) of sublist 0 ────────────────
    # C: GetSubList(local_40, pvStack_6c, 0) + GetListElement(puVar9, uStack_92, 0)
    #    bVar3 = *pbVar10  (byte)
    try:
        sender_power: int = int(tokens[1]) & 0xFF    # bVar3
    except (IndexError, ValueError):
        sender_power = 0

    # uVar11 = FUN_00465930(local_40) = count of token slots in local_40
    # In our flat layout the effective "count" is the number of non-keyword tokens.
    payload = tokens[1:]     # local_40 equivalent
    uVar11  = len(payload)   # C: FUN_00465930

    # FUN_00419300: register XDO proposal for the sender in g_XdoProposalBySender
    # C: FUN_00419300(&DAT_00bb65f8 + bVar3*0xc, &pvStack_50, local_40)
    _ordered_token_seq_insert(
        state.g_XdoProposalBySender.setdefault(sender_power, []),
        payload,
    )

    # ── Step 4: destination/scope province = element 2 of sublist 0 ──────────
    # C: GetSubList(local_40, pvStack_6c, 0) + GetListElement(puVar9, uStack_92, 2)
    #    pvStack_80 = (void*)(uint)*pbVar10
    try:
        dest_prov: int = int(tokens[3]) & 0xFF       # pvStack_80
    except (IndexError, ValueError):
        dest_prov = 0

    # DAT_00bb6bf8 + sender*0xc: per-sender destination map
    if not hasattr(state, 'g_XdoDestBySender'):
        state.g_XdoDestBySender = {}
    state.g_XdoDestBySender.setdefault(sender_power, {})[dest_prov] = dest_prov

    # DAT_00bb713c: global destination map
    if not hasattr(state, 'g_XdoGlobalDestMap'):
        state.g_XdoGlobalDestMap = {}
    state.g_XdoGlobalDestMap[dest_prov] = dest_prov

    # ── Step 5: order command = element 0 of sublist 1 ───────────────────────
    # C: GetSubList(local_40, pvStack_6c, 1) + GetListElement(puVar9, uStack_92, 0)
    #    sVar4 = *psVar12  (short — MTO/CTO/SUP etc.)
    try:
        order_cmd: str = str(tokens[2])   # sVar4
    except IndexError:
        order_cmd = ''

    # Candidate list provided by the caller via FUN_00405090 / in_stack_00000018.
    # Absorbed into state.g_xdo_candidate_list.
    candidate_list: list = getattr(state, 'g_xdo_candidate_list', [])

    if order_cmd in ('MTO', 'CTO'):
        # ── Step 6a: MTO / CTO branch ─────────────────────────────────────────
        # C: GetSubList(local_40, pvStack_6c, 2) + GetListElement(0)
        #    ppiStack_7c = destination province
        try:
            mto_dest: int = int(tokens[4]) & 0xFF     # ppiStack_7c
        except (IndexError, ValueError):
            mto_dest = dest_prov

        # Loop over in_stack_00000018 (candidate entries from caller):
        #   ScoreSupportOpp(&DAT_00bb67f8 + entry.power * 0xc, buf, (mto_dest, dest_prov))
        for entry in candidate_list:
            entry_power: int = int(entry.get('power', entry.get('node_power', 0)))
            _score_support_opp(
                state,
                base_offset='DAT_00bb67f8',
                power=entry_power,
                args=(mto_dest, dest_prov),
            )

    elif order_cmd == 'SUP':
        # ── Step 6b: SUP branch ───────────────────────────────────────────────
        # local_2c = GetSubList(local_40, 2)  (the supported-unit sub-token group)
        # sublist-1 element 0 → supported unit identity (unused)
        # sublist-2 element 0 → ppiVar14 = supported power
        try:
            sup_power: int = int(tokens[4]) & 0xFF    # ppiVar14
        except (IndexError, ValueError):
            sup_power = 0

        # GetSubList(local_40, pvStack_50, 2) + GetSubList(puVar9, pvStack_6c, 0)
        # GetListElement(0) → bVar3 re-read = province of supported unit (piStack_b0)
        try:
            sup_unit_prov: int = int(tokens[3]) & 0xFF   # bVar3 re-read
        except (IndexError, ValueError):
            sup_unit_prov = 0

        # StdMap_FindOrInsert(DAT_00bb713c, ..., ppiStack_7c = ppiVar14)
        state.g_XdoGlobalDestMap[sup_power] = sup_power

        if uVar11 == 5:
            # SUP MTO (5-element XDO: XDO sender cmd sup_power dest_prov)
            # ppiVar16 = element 4 of local_40 = final MTO destination
            try:
                ppiVar16: int = int(tokens[5]) & 0xFF
            except (IndexError, ValueError):
                ppiVar16 = 0

            # ScoreSupportOpp(DAT_00bb69f8 + sup_unit_prov*0xc, buf, (sup_power, ppiVar16))
            _score_support_opp(
                state,
                base_offset='DAT_00bb69f8',
                power=sup_unit_prov,
                args=(sup_power, ppiVar16),
            )

            # Loop over in_stack_00000018:
            #   FUN_004193f0(&DAT_00bb68f8 + entry.power*0xc, buf, (dest_prov, dest_prov))
            for entry in candidate_list:
                entry_power = int(entry.get('power', entry.get('node_power', 0)))
                _score_sup_attacker(
                    state,
                    base_offset='DAT_00bb68f8',
                    power=entry_power,
                    args=(dest_prov, dest_prov),
                )
        else:
            # SUP HLD
            # StdMap_FindOrInsert(DAT_00bb6af8 + sup_unit_prov*0xc, ..., ppiStack_7c = sup_power)
            if not hasattr(state, 'g_XdoSupHldMap'):
                state.g_XdoSupHldMap = {}
            state.g_XdoSupHldMap.setdefault(sup_unit_prov, {})[sup_power] = sup_power

            # Loop over in_stack_00000018:
            #   FUN_004193f0(&DAT_00bb68f8 + entry.power*0xc, buf, (dest_prov, dest_prov))
            for entry in candidate_list:
                entry_power = int(entry.get('power', entry.get('node_power', 0)))
                _score_sup_attacker(
                    state,
                    base_offset='DAT_00bb68f8',
                    power=entry_power,
                    args=(dest_prov, dest_prov),
                )

    # ── Step 7: log + BuildAllianceMsg ───────────────────────────────────────
    _log.debug("Recalculating: Because we have applied a XDO: (%s)", ' '.join(str(t) for t in tokens[1:]))
    # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
    build_alliance_msg(state, 0x66)

    # ── Step 8: clear candidate list (in_stack_00000018 freed by caller) ─────
    # C: SerializeOrders(local_78, ...) — clears local sentinel set (no-op)
    # C: SerializeOrders(&stack0x14, ...) + _free(in_stack_00000018)
    if hasattr(state, 'g_xdo_candidate_list'):
        state.g_xdo_candidate_list = []

    # Always returns '\x01' (True) per decompile line 265.
    return True


def _score_support_opp(
    state: InnerGameState,
    base_offset: str,
    power: int,
    args: tuple,
) -> tuple:
    """
    ScoreSupportOpp (FUN_00404fd0) — MSVC std::map<int,int> find-or-insert.

    C signature:
      void __thiscall ScoreSupportOpp(void *this, void **param_1, int *param_2)

    this     = &table[power * 0xc]  — per-power (or per-province) map object
    param_1  = output: [0]=iterator_base, [1]=node_ptr, [2]=was_inserted
    param_2  = pointer to key (= args[0]); args[1] passed through to the
               BST insert helper FUN_00403ca0 but not used by this function.

    Node layout (MSVC release std::map<int,int>):
      +0x00  left child ptr      (ppiVar4[0])
      +0x04  parent ptr          (ppiVar4[1])
      +0x08  right child ptr     (ppiVar4[2])
      +0x0C  key   (int)         (ppiVar4[3])  ← compared against *param_2
      +0x10  value (int)         (ppiVar4[4])  ← zero on insert
      +0x14  _Color byte
      +0x15  _Isnil byte         ← sentinel check: == '\\0' means real node

    Algorithm: BST lower-bound walk; if key already present return its node
    (was_inserted=False); else allocate zero-valued node via FUN_00403ca0
    (was_inserted=True).  FUN_00401400 = BST iterator-decrement (predecessor).

    Python tables:
      'DAT_00bb67f8' → state.g_xdo_mto_opp_score[power][key]   (MTO/CTO path)
      'DAT_00bb69f8' → state.g_xdo_sup_mto_score[power][key]   (SUP-MTO path)

    Returns (sub_table, key, was_inserted).  Call sites that only need the
    side-effect (ensuring the key exists with a default-0 value) may discard
    the return value.

    Callees: FUN_00401400 (BST predecessor), FUN_00403ca0 (BST insert).
    """
    _TABLE_ATTR: dict = {
        'DAT_00bb67f8': 'g_xdo_mto_opp_score',
        'DAT_00bb69f8': 'g_xdo_sup_mto_score',
    }
    attr: str = _TABLE_ATTR.get(base_offset, base_offset)
    if not hasattr(state, attr):
        setattr(state, attr, {})
    table: dict = getattr(state, attr)
    sub: dict = table.setdefault(power, {})
    key: int = int(args[0])
    was_inserted: bool = key not in sub
    if was_inserted:
        sub[key] = 0   # zero-initialise mapped int (mirrors default-construct)
    return sub, key, was_inserted


def _score_sup_attacker(
    state: InnerGameState,
    base_offset: str,
    power: int,
    args: tuple,
) -> tuple:
    """
    Port of FUN_004193f0 — MSVC std::map<int,int> find-or-insert.

    C signature (decompiled.txt lines 2–50):
      void __thiscall FUN_004193f0(void *this, void **param_1, int *param_2)

    this     = &DAT_00bb68f8 + entry_power*0xc  — per-power attacker-score map
    param_1  = output: [0]=iterator_base, [1]=node_ptr, [2]=was_inserted
    param_2  = pointer to key (args[0])

    Algorithm is structurally identical to ScoreSupportOpp (FUN_00404fd0):
      BST lower-bound walk using the node layout
        +0x00 left, +0x04 parent, +0x08 right, +0x0C key (int),
        +0x10 value (int), +0x19 isnil byte (== '\\0' → real node)
      If key found: return existing node, was_inserted=False.
      Else: allocate zero-valued node via FUN_004136d0, was_inserted=True.
      FUN_0040e5f0 = BST iterator-decrement (predecessor).

    Python table:
      'DAT_00bb68f8' → state.g_xdo_sup_attacker_score[power][key]

    Callees (absorbed into dict operations):
      FUN_0040e5f0 (BST predecessor / iterator-decrement)
      FUN_004136d0 (BST insert helper)
    """
    attr = 'g_xdo_sup_attacker_score'
    if not hasattr(state, attr):
        setattr(state, attr, {})
    table: dict = getattr(state, attr)
    sub: dict = table.setdefault(power, {})
    key: int = int(args[0])
    was_inserted: bool = key not in sub
    if was_inserted:
        sub[key] = 0   # zero-initialise mapped int (mirrors default-construct)
    return sub, key, was_inserted


def _cancel_pce(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named export CANCEL(param_1).

    Called from CAL_MOVE's NOT-PCE branch when a NOT(PCE(...)) press is
    received, cancelling an active peace arrangement.

    Decompile walk (decompiled.txt lines 2-184):

    Setup
    -----
    - uStack_44 = own power index (param_1+8+0x2424, i.e. albert_power_idx).
    - FUN_00465f60 copies incoming press token-list into local_1c.
    - GetSubList(&token_list, &pvStack_38, 1) extracts sub-list 1
      (the PCE power set), AppendList-merges it back into token_list,
      FreeList releases the temp.
    - uVar3 = FUN_00465930(&token_list)  → count of powers in the PCE.

    First loop (lines 61-64): iterates i=0..N-1 calling GetListElement,
    populating uStack_58 (low byte = power token).  This is a read-only pass
    with no observable side-effects in Python; we model it as extracting the
    powers list.

    Main double loop (outer iStack_4c, inner iStack_50, lines 67-128):
    For each ordered pair (a = powers[i], b = powers[j]) where i ≠ j:

      idx = a * 21 + b   (flat index into trust matrices)

      Trust-zero branch (lines 79-85):
        if g_AllyTrustScore_Hi[idx*2] > 0
           OR (g_AllyTrustScore_Hi[idx*2] == 0 AND g_AllyTrustScore[idx*2] != 0):
          → g_AllyTrustScore[idx*2]    = 0
          → g_AllyTrustScore_Hi[idx*2] = 0
          → cStack_59 = '\x01'  (changed)

      Own-power branch (lines 86-122) — only when outer power a == own:
        if DAT_00bb6f30[b*3] != 0 OR DAT_00bb7030[b*3] != 0:
          → changed
        Walk & free linked list at DAT_00bb6f2c[b*3]:
          while node.isnil == 0: FUN_00401950(node[2]); node = node.next; free
          Reset sentinel links (prev=next=self) and count to 0.
        Walk & free linked list at DAT_00bb702c[b*3]:
          same pattern.

    Post loop (lines 129-167): if changed → log + BuildAllianceMsg(0x66) stub.
    Returns cStack_59.

    Python mapping of C globals:
      uStack_44              → state.albert_power_idx
      g_AllyTrustScore       → state.g_AllyTrustScore  (2-D array indexed [a, b])
      g_AllyTrustScore_Hi    → state.g_AllyTrustScore_Hi
      DAT_00bb6f2c[p*3]      → state.g_DesigListA[p]   (list of records, cleared on cancel)
      DAT_00bb6f30[p*3]      → state.g_DesigCountA[p]  (int count)
      DAT_00bb702c[p*3]      → state.g_DesigListB[p]
      DAT_00bb7030[p*3]      → state.g_DesigCountB[p]

    The C linked-list walk-and-free is absorbed as list.clear().
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)

    # ── Extract PCE powers from the token list ────────────────────────────────
    # GetSubList(&token_list, ..., 1) fetches the power sub-list (index 1).
    # In Python `tokens` already contains the unwrapped list from CAL_MOVE.
    # The PCE token is: PCE ( power1 power2 … ) → tokens[1:] are power bytes.
    pce_powers: list[int] = []
    for tok in tokens[1:]:
        try:
            p = int(tok) & 0xFF
            pce_powers.append(p)
        except (TypeError, ValueError):
            pass

    uVar3: int = len(pce_powers)   # FUN_00465930 result
    if uVar3 <= 0:
        return False

    changed: bool = False          # cStack_59

    # ── Main double loop ──────────────────────────────────────────────────────
    for i, a in enumerate(pce_powers):       # iStack_4c / uStack_48
        for j, b in enumerate(pce_powers):   # iStack_50 / uVar10
            if i == j:                        # if (iVar5 != iVar11) guard
                continue

            # idx = a * 21 + b  (flat index)
            idx: int = a * 21 + b

            # Trust-zero branch (lines 79-85)
            # Condition:
            #   (&g_AllyTrustScore_Hi)[idx*2] > 0
            #   OR ((&g_AllyTrustScore_Hi)[idx*2] == 0
            #        AND (&g_AllyTrustScore)[idx*2] != 0)
            # Equivalent to: trust_hi > 0  OR  trust != 0  (when trust_hi == 0)
            try:
                t_hi = int(state.g_AllyTrustScore_Hi[a, b])
                t_lo = int(state.g_AllyTrustScore[a, b])
            except Exception:
                t_hi = 0
                t_lo = 0

            trust_nonzero = (t_hi > 0) or (t_hi == 0 and t_lo != 0)
            if trust_nonzero:
                state.g_AllyTrustScore[a, b]    = 0
                state.g_AllyTrustScore_Hi[a, b] = 0
                changed = True

            # Own-power branch (lines 86-122): a == own
            if a == own:
                # DAT_00bb6f30[b*3] and DAT_00bb7030[b*3] are count fields.
                g_DesigCountA = getattr(state, 'g_DesigCountA', {})
                g_DesigCountB = getattr(state, 'g_DesigCountB', {})
                cnt_a = int(g_DesigCountA.get(b, 0))
                cnt_b = int(g_DesigCountB.get(b, 0))

                if cnt_a != 0 or cnt_b != 0:
                    changed = True

                # Walk & free linked list A (DAT_00bb6f2c[b*3]) — lines 90-102.
                # Absorbed as list.clear(); sentinel reset (list now empty).
                g_DesigListA = getattr(state, 'g_DesigListA', {})
                if b in g_DesigListA:
                    g_DesigListA[b] = []
                else:
                    g_DesigListA[b] = []
                state.g_DesigListA = g_DesigListA

                # Reset count field A (DAT_00bb6f30[b*3] = 0) — line 100.
                g_DesigCountA[b] = 0
                state.g_DesigCountA = g_DesigCountA

                # Walk & free linked list B (DAT_00bb702c[b*3]) — lines 103-122.
                g_DesigListB = getattr(state, 'g_DesigListB', {})
                if b in g_DesigListB:
                    g_DesigListB[b] = []
                else:
                    g_DesigListB[b] = []
                state.g_DesigListB = g_DesigListB

                # Reset count field B (DAT_00bb7030[b*3] = 0) — line 120.
                g_DesigCountB[b] = 0
                state.g_DesigCountB = g_DesigCountB

    # ── Post-loop: log if changed ─────────────────────────────────────────────
    if changed:
        # FUN_0046b050 — string serializer for the token-list (absorbed as debug log).
        # SEND_LOG(..., L"Recalculating: Because we are CANCELLING: (%s)")
        _log.debug(
            "Recalculating: Because we are CANCELLING: (%s)",
            ' '.join(str(p) for p in pce_powers),
        )
        # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
        build_alliance_msg(state, 0x66)

    return changed


def _remove_dmz(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named export REMOVE_DMZ(param_1) — decompile-verified.

    Called from cal_move()'s NOT-DMZ branch when a NOT(DMZ(...)) press is
    received, signalling that a previous DMZ arrangement is being revoked.

    Decompile walk (decompiled.txt lines 2-182):

    Setup
    -----
    - uStack_74 = own power index  (param_1+8+0x2424 = albert_power_idx)
    - local_60  = GetSubList(press, 1)  → DMZ power-list
    - local_34  = GetSubList(press, 2)  → DMZ province-list
    - uVar6   = FUN_00465930(local_60)  → n_powers
    - uStack_84 = FUN_00465930(local_34) → n_provs

    Triple loop (lines 78-134):
      outer i (iStack_7c):  0 .. n_powers-1
        outer_power = GetListElement(local_60, i) → uStack_88 / uVar13
      inner j (iStack_78):  0 .. n_powers-1
        j_power = GetListElement(local_60, j) → uStack_6c
        condition: (j != i) OR (n_powers == 1)
          inner k (iStack_94): 0 .. n_provs-1
            province = GetListElement(local_34, k) → uStack_80

            BRANCH A (uVar13 == uStack_74, i.e. outer_power == own):
              this = &DAT_00bb6f28 + uVar3 * 0xc
                     (uVar3 = uStack_6c = j_power)
              puVar8 = GameBoard_GetPowerRec(this, aiStack_14, &province)
              puVar14 = *puVar8          (lower-bound node)
              ppiVar12 = puVar8[1]       (found iterator)
              ppiVar2 = &DAT_00bb6f2c[uVar3 * 3]  (DesigListA head for j_power)
              if ppiVar12 != ppiVar2:
                FUN_00402b70(this, &apvStack_24, puVar14, ppiVar12)
                cStack_95 = '\\x01'   (changed)

            BRANCH B (outer_power != own):
              this = &DAT_00bb7028 + uVar13 * 0xc
                     (uVar13 = outer_power)
              puVar8 = GameBoard_GetPowerRec(this, aiStack_1c, &province)
              ppiVar2 = &DAT_00bb702c[uVar13 * 3]  (DesigListB head for outer_power)
              if ppiVar12 != ppiVar2:
                FUN_00402b70(this, &pvStack_50, puVar14, ppiVar12)
                cStack_95 = '\\x01'   (changed)

    Post-loop (lines 135-163):
      if changed:
        FUN_0046b050 → log "Recalculating: Because we removed a DMZ: %s"
        BuildAllianceMsg(0x66) — stub

    Python mapping:
      uStack_74            → state.albert_power_idx
      DAT_00bb6f28[p*0xc]  → designation map for p (BRANCH A — own side)
      DAT_00bb6f2c[p*3]    → g_DesigListA[p]  (sentinel/head pointer)
      ppiVar12 != ppiVar2  → province is in g_DesigListA[p] (non-empty find)
      DAT_00bb7028[p*0xc]  → designation map for p (BRANCH B — sender side)
      DAT_00bb702c[p*3]    → g_DesigListB[p]
      FUN_00402b70         → std::map::insert / _Copy — absorbed as list membership

    FUN_0047a948 (AssertFail) is called when the GameBoard_GetPowerRec
    sanity-check fails (puVar14 == 0 or puVar14 != this); absorbed as
    a silent continue in Python (the iterator is invalid, so we skip).

    Callees absorbed:
      FUN_00465870 ✓ (list init — Python list literals)
      GetSubList ✓ (absorbed into token parsing)
      AppendList ✓ (absorbed)
      FreeList   ✓ (absorbed)
      FUN_00465930 ✓ (len())
      GetListElement ✓ (absorbed into indexed list access)
      GameBoard_GetPowerRec  → g_ScOwner membership check (absorbed)
      FUN_00402b70           → absorbed as `province in g_DesigListA/B[p]`
      FUN_0047a948 (AssertFail) → absorbed as silent skip
      FUN_0046b050 ✓ (absorbed as debug log)
      BuildAllianceMsg   → stub (unchecked)
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)

    # ── Parse token stream ────────────────────────────────────────────────────
    # GetSubList(press, 1) → power list  (local_60)
    # GetSubList(press, 2) → province list (local_34)
    # In Python, `tokens` is the flat unwrapped list from cal_move().
    # Layout after CAL_MOVE strips the leading 'DMZ': [pow1 pow2 … prov1 prov2 …]
    # We split the same way as _handle_dmz: values < 7 are power indices,
    # values >= 7 are province indices.
    dmz_powers: list[int] = []
    dmz_provs:  list[int] = []
    for tok in tokens[1:]:
        try:
            v = int(tok)
        except (ValueError, TypeError):
            continue
        if v < 7:
            dmz_powers.append(v)
        else:
            dmz_provs.append(v)

    n_powers: int = len(dmz_powers)   # uVar6
    n_provs:  int = len(dmz_provs)    # uStack_84

    if n_powers == 0 or n_provs == 0:
        return False

    # Lazy-init designation-list state (same fields used by _cancel_pce).
    g_DesigListA: dict = getattr(state, 'g_DesigListA', {})
    g_DesigListB: dict = getattr(state, 'g_DesigListB', {})

    changed: bool = False   # cStack_95

    # ── Triple loop ───────────────────────────────────────────────────────────
    for i_idx in range(n_powers):                  # iStack_7c
        outer_power = dmz_powers[i_idx]            # uStack_88 / uVar13

        for j_idx in range(n_powers):              # iStack_78
            j_power = dmz_powers[j_idx]            # uStack_6c

            # Condition: (j != i) OR (n_powers == 1)
            # C: if (((iVar11 != iVar10) || (uVar6 == 1)) && (iStack_94 = 0, 0 < (int)uStack_84))
            if i_idx == j_idx and n_powers != 1:
                continue

            for k_idx in range(n_provs):           # iStack_94
                province = dmz_provs[k_idx]        # uStack_80

                if outer_power == own:
                    # ── BRANCH A: outer power is own ──────────────────────────
                    # C: this = &DAT_00bb6f28 + uVar3 * 0xc  (j_power = uVar3 = uStack_6c)
                    # GameBoard_GetPowerRec(this, aiStack_14, &province)
                    #   → puVar8[1] = iterator into j_power's designation map
                    # ppiVar2 = &DAT_00bb6f2c[uVar3 * 3]  (DesigListA sentinel)
                    # if (ppiVar12 != ppiVar2) → found → FUN_00402b70 → changed
                    #
                    # Python absorption: "province is in j_power's designation list"
                    desig_a: list = g_DesigListA.get(j_power, [])
                    if province in desig_a:
                        # FUN_00402b70 — inserts a copy into local stack slot
                        # (side-effect on the local buffer irrelevant in Python)
                        changed = True

                else:
                    # ── BRANCH B: non-own outer power ─────────────────────────
                    # C: this = &DAT_00bb7028 + uVar13 * 0xc  (outer_power = uVar13)
                    # GameBoard_GetPowerRec(this, aiStack_1c, &province)
                    # ppiVar2 = &DAT_00bb702c[uVar13 * 3]  (DesigListB sentinel)
                    # if (ppiVar12 != ppiVar2) → found → FUN_00402b70 → changed
                    desig_b: list = g_DesigListB.get(outer_power, [])
                    if province in desig_b:
                        changed = True

    # ── Post-loop: log if changed ─────────────────────────────────────────────
    # C lines 135-163:
    #   FUN_0046b050(press, &pvStack_50) → string of token list
    #   SEND_LOG(&iStack_8c, L"Recalculating: Because we removed a DMZ: %s")
    #   uStack_74 = 0x66; BuildAllianceMsg(&DAT_00bbf638, ..., &uStack_74)
    if changed:
        prov_str = ' '.join(str(p) for p in dmz_provs)
        _log.debug(
            "Recalculating: Because we removed a DMZ: (%s)", prov_str
        )
        # C: uStack_74 = 0x66; BuildAllianceMsg(&DAT_00bbf638, ..., &uStack_74)
        build_alliance_msg(state, 0x66)

    return changed


def _not_xdo(state: "InnerGameState", tokens: list) -> bool:
    """
    Port of named function NOT_XDO(void) — decompile-verified against decompiled.txt.

    Called from cal_move()'s NOT-XDO branch when a NOT(XDO(...)) press is
    received, cancelling a previously submitted XDO order proposal.

    Decompile walk (decompiled.txt lines 2-115):

    Setup / token extraction
    ------------------------
    - FUN_00465870(local_1c)         — init empty local token list.
    - GetSubList(&stack4, &pvStack_38, 1)
        → extract sub-list at index 1 from the incoming XDO press
          (the inner XDO order content: unit, order-cmd, dest, …).
    - AppendList(local_1c, ppvVar8)  — merge into local_1c.
    - FreeList(&pvStack_38)          — release temp.
    - GetSubList(local_1c, &pvStack_38, 0)
        → this = first sub-element of local_1c (the order content group).
    - GetListElement(this, &uStack_46, 0)
        → uStack_46 (low byte) = element 0 of that group.
          In practice this is the sender/unit province byte; used in
          the TreeIterator_Advance sentinel check but NOT stored separately.
    - FreeList(&pvStack_38).

    Registration loop (lines 56-72)
    ---------------------------------
    - pCStack_3c = *in_stack_00000018   (head of outer candidate list)
    - puStack_40 = &stack0x00000014     (iterator = current node)
    - while pCVar1 != in_stack_00000018 (not sentinel):
        FUN_00419300(
            &DAT_00bb66f8 + *(pCVar1+0xc) * 0xc,  — per-power NOT-XDO list
            &pvStack_38,
            local_1c                               — the extracted XDO content
        )
        TreeIterator_Advance(&puStack_40)

    Python absorption:
      in_stack_00000018 = state.g_xdo_candidate_list  (set by FUN_00405090 in caller)
      *(pCVar1+0xc)     = entry['power'] (power index from candidate node)
      DAT_00bb66f8 + p*0xc → state.g_NotXdoListBySender[power]  (new field)
      FUN_00419300(…, local_1c) → append extracted XDO content to that list

    Post-loop cleanup (lines 73-114)
    -----------------------------------
    - FUN_0046b050 → serialize press token list to string (absorbed as debug log arg).
    - SEND_LOG("Recalculating: Because we have applied a NOT XDO: (%s)")
    - BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  — stub (unchecked).
    - FreeList(local_1c)
    - FreeList(&stack4)
    - SerializeOrders + _free(in_stack_00000018) → clear g_xdo_candidate_list.
    - Returns CONCAT31(..., 1) → True always.

    New state field:
      g_NotXdoListBySender : dict[int, list]  — DAT_00bb66f8 per-power list.
        Keyed by power index; each value is a list of extracted XDO content lists
        representing orders that the peer is retracting.

    Unchecked callees (retained as stubs/absorbed):
      FUN_00419300           — absorbed as list append
      BuildAllianceMsg       — unchecked stub
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg, _ordered_token_seq_insert

    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── Step 1: extract XDO inner content (GetSubList index 1) ───────────────
    # C: GetSubList(&stack4, &pvStack_38, 1)  → sub-list at index 1 of the
    #    incoming press (the XDO order content group).
    # In Python `tokens` is the flat unwrapped NOT-XDO list from cal_move().
    # Layout: ['XDO', sender_power, order_cmd, dest, ...]
    # We treat tokens[1:] as the XDO inner content (local_1c equivalent).
    xdo_content: list = list(tokens[1:]) if len(tokens) > 1 else []

    # ── Step 2: registration loop over in_stack_00000018 ─────────────────────
    # C: pCStack_3c = *in_stack_00000018 (head); puStack_40 = &stack0x14 (iter)
    # while pCVar1 != in_stack_00000018 (sentinel):
    #     FUN_00419300(&DAT_00bb66f8 + *(pCVar1+0xc)*0xc, &pvStack_38, local_1c)
    #     TreeIterator_Advance(&puStack_40)
    #
    # Absorbed: iterate g_xdo_candidate_list; for each entry append xdo_content
    # into g_NotXdoListBySender[entry['power']].
    candidate_list: list = getattr(state, 'g_xdo_candidate_list', [])

    for entry in candidate_list:
        power: int = int(entry.get('power', entry.get('node_power', 0)))
        # FUN_00419300(&DAT_00bb66f8 + power*0xc, &pvStack_38, local_1c)
        # → inserts local_1c (XDO content) into the per-power NOT-XDO ordered set.
        _ordered_token_seq_insert(
            state.g_NotXdoListBySender.setdefault(power, []),
            xdo_content,
        )

    # ── Post-loop: log + BuildAllianceMsg ─────────────────────────────────────
    # C: FUN_0046b050 → serialize token list → SEND_LOG("... NOT XDO: (%s)")
    _log.debug(
        "Recalculating: Because we have applied a NOT XDO: (%s)",
        ' '.join(str(t) for t in tokens[1:]),
    )
    # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
    build_alliance_msg(state, 0x66)

    # ── Cleanup: clear candidate list (SerializeOrders + _free) ──────────────
    # C: SerializeOrders(&stack14,...) + _free(in_stack_00000018)
    if hasattr(state, 'g_xdo_candidate_list'):
        state.g_xdo_candidate_list = []

    # Always returns '\x01' (True) per decompile line 114.
    return True


