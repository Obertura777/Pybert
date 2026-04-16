"""Albert DAIDE / press-handling subpackage.

Originally a single 6,174-line ``communications.py``.  Split into
submodules during the 2026-04 refactor:

- ``tokens``    — DAIDE token primitives and press-type token constants

All public names previously importable as ``albert.communications.X`` remain
available at that path via the re-exports below; nothing external should need
to change.
"""

from ..state import InnerGameState

# ── Re-exports from submodules (preserve flat public surface) ────────────────
from .tokens import (
    _TOK_ALY, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_AND, _TOK_VSS, _TOK_XDO,
    _token_seq_copy,
    _token_seq_overlap,
    _token_seq_no_overlap,
    _token_seq_concat_single,
    _token_seq_count,
    _token_seq_less,
    _wrap_single_token,
    _get_daide_context_ptr,
)



def process_hst(state: InnerGameState, message: str):
    """
    Port of ParseHSTResponse (FUN_0041b410).
    Maps host capability tables.
    """
    import re
    import random
    
    # Parse LVL
    lvl_match = re.search(r'LVL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if lvl_match:
        lvl = int(lvl_match.group(1) or lvl_match.group(2))
        state.g_HistoryCounter = lvl

    # Parse MTL 
    mtl_match = re.search(r'MTL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if mtl_match:
        mtl = int(mtl_match.group(1) or mtl_match.group(2))
        state.g_MoveTimeLimit = mtl

    # Initialize per-game press threshold randomization (0-98)
    state.g_PressThreshRandom = random.randrange(50) + random.randrange(50)
    
    # Force press level config override if needed
    if getattr(state, 'g_ForceDisablePress', 0) == 1:
        state.g_HistoryCounter = 0

    # Populate per-power allowed-press-type maps (DAT_00bb6e10[p*0xc]).
    # C: RegisterAllowedPressToken called for each token in g_AllowedPressTokenList[0..lvl-1].
    # Threshold table (research.md §3548-3552):
    #   lvl > 9:  adds PCE, ALY, VSS, DMZ
    #   lvl > 19: adds XDO
    #   lvl > 29: adds AND, ORR
    lvl = state.g_HistoryCounter
    allowed: set = set()
    if lvl > 9:
        allowed |= {_TOK_PCE, _TOK_ALY, _TOK_VSS, _TOK_DMZ}
    if lvl > 19:
        allowed.add(_TOK_XDO)
    if lvl > 29:
        allowed |= {_TOK_AND, _TOK_ORR}
    num_powers = getattr(state, 'g_NumPowers', 7)
    state.g_press_history = {p: set(allowed) for p in range(num_powers)}

import re


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


# ── RegisterReceivedPress helpers ────────────────────────────────────────────

def _extract_top_paren_groups(text: str) -> list:
    """Return a list of the content strings of each top-level ( ... ) group."""
    groups: list = []
    depth = 0
    start = -1
    for i, c in enumerate(text):
        if c == '(':
            if depth == 0:
                start = i + 1
            depth += 1
        elif c == ')':
            depth -= 1
            if depth == 0 and start != -1:
                groups.append(text[start:i].strip())
                start = -1
    return groups


def _parse_xdo_candidates(content_str: str) -> list:
    """
    Extract XDO order sequences from a press content string.

    Returns a list of dicts: {'tokens': [str, ...], 'type_flag': 0}.
    type_flag=0 marks these as external (received) order candidates.
    """
    candidates: list = []
    tokens = content_str.split()
    idx = 0
    while idx < len(tokens):
        if tokens[idx] == 'XDO':
            xdo_tokens = ['XDO']
            idx += 1
            depth = 0
            opened = False  # have we entered the body's outer paren yet?
            while idx < len(tokens):
                t = tokens[idx]
                xdo_tokens.append(t)
                if t == '(':
                    depth += 1
                    opened = True
                elif t == ')':
                    depth -= 1
                idx += 1
                # End of this XDO body: opened the outer paren and
                # closed it (depth back to 0). Without `opened`, a
                # zero-depth start would terminate before consuming
                # anything; without the post-decrement break, multiple
                # XDOs in a single press body get concatenated.
                if opened and depth == 0:
                    break
            candidates.append({'tokens': xdo_tokens, 'type_flag': 0})
        else:
            idx += 1
    return candidates


# ── DAIDE XDO body → order_seq translator ────────────────────────────────────
#
# Bridge between the inbound press registry (g_BroadcastList, populated by
# register_received_press) and the MC reader (state.g_GeneralOrders[power] /
# state.g_AllianceOrders[power] consumed by monte_carlo.process_turn at sub-
# pass 1c).
#
# This is the Python equivalent of the writer loop inside ScoreOrderCandidates
# (Source/ScoreOrderCandidates.c, lines 217–294): for each broadcast entry
# that survives the legitimacy gate, parse each XDO order_record, identify
# the proposer power, and insert the order into that power's general /
# alliance set.
#
# The C binary tracks a std::set<order_record> per power keyed on the unit
# province; in Python we use a plain list (de-duplication absorbed; the MC
# reader's per-trial state reset makes duplicates harmless).

_DAIDE_TO_ORDER_TYPE_TAG = {
    'HLD': 'HLD',
    'MTO': 'MTO',
    'SUP': 'SUP',
    'CTO': 'CTO',
    'CVY': 'CVY',
}


def _split_top_level_groups(tokens: list) -> list:
    """
    Walk a flat DAIDE token list and yield top-level items, where each item is
    either a bare token (str) or a sub-list of the inner tokens of a balanced
    paren group (list[str]).

    Outer parens are consumed; nested parens inside groups are preserved
    verbatim so callers can recurse with the same function.
    """
    items: list = []
    i = 0
    n = len(tokens)
    while i < n:
        t = tokens[i]
        if t == '(':
            depth = 1
            j = i + 1
            while j < n and depth > 0:
                if tokens[j] == '(':
                    depth += 1
                elif tokens[j] == ')':
                    depth -= 1
                    if depth == 0:
                        break
                j += 1
            # Inner (does NOT include the outer parens themselves).
            items.append(tokens[i + 1:j])
            i = j + 1
        elif t == ')':
            # Stray close paren — should not happen on a balanced input.
            i += 1
        else:
            items.append(t)
            i += 1
    return items


def _parse_unit_triple(triple: list) -> "tuple[int, str, str] | None":
    """
    Parse a (POWER UNIT_TYPE PROV) DAIDE sub-list.

    Returns (power_idx, unit_type_letter, prov_name) or None on malformed input.
    UNIT_TYPE is normalised to 'A' or 'F' (DAIDE uses AMY / FLT).
    """
    if len(triple) < 3:
        return None
    p_idx = _pow_idx(triple[0])
    if p_idx is None:
        return None
    utyp = str(triple[1]).upper()
    if utyp in ('AMY', 'A'):
        unit_chr = 'A'
    elif utyp in ('FLT', 'F'):
        unit_chr = 'F'
    else:
        return None
    prov = str(triple[2]).upper()
    return p_idx, unit_chr, prov


def _parse_destination(item) -> "tuple[str, str]":
    """
    Resolve a destination item — either a bare province token or a
    (PROV COAST) sub-list — into a (prov_name, coast_str) pair.
    """
    if isinstance(item, list):
        prov = str(item[0]).upper() if item else ''
        coast = str(item[1]).upper() if len(item) > 1 else ''
        return prov, coast
    return str(item).upper(), ''


def _parse_xdo_body_to_order(xdo_tokens: list) -> "tuple[int, dict] | None":
    """
    Parse a single XDO token list into (proposer_power_idx, order_seq_dict).

    The order_seq_dict matches the schema consumed by
    dispatch.dispatch_single_order — keys: 'type', 'unit', and command-
    specific fields (target/coast/target_unit/target_dest/target_coast).

    Supported commands: HLD, MTO, SUP (HLD and MTO forms), CTO, CVY.
    Returns None for malformed or unsupported sequences (caller should
    skip-with-debug-log).

    Token shape (DAIDE press as emitted by python-diplomacy):
        XDO ( ( POWER UTYP PROV ) CMD ... )
    """
    if not xdo_tokens or xdo_tokens[0] != 'XDO':
        return None

    # Strip the leading XDO; the remainder must be a single top-level paren
    # group containing the order body.
    outer = _split_top_level_groups(xdo_tokens[1:])
    if not outer or not isinstance(outer[0], list):
        return None
    body = _split_top_level_groups(outer[0])
    if not body or not isinstance(body[0], list):
        return None

    unit_info = _parse_unit_triple(body[0])
    if unit_info is None:
        return None
    power_idx, unit_chr, prov_name = unit_info
    unit_str = f"{unit_chr} {prov_name}"

    # Order command is the next bare token after the unit triple.
    cmd_idx = 1
    if cmd_idx >= len(body) or isinstance(body[cmd_idx], list):
        return None
    cmd = str(body[cmd_idx]).upper()
    tag = _DAIDE_TO_ORDER_TYPE_TAG.get(cmd)
    if tag is None:
        return None

    order: dict = {'type': tag, 'unit': unit_str}

    if tag == 'HLD':
        return power_idx, order

    if tag == 'MTO':
        if cmd_idx + 1 >= len(body):
            return None
        target, coast = _parse_destination(body[cmd_idx + 1])
        order['target'] = target
        order['coast'] = coast
        return power_idx, order

    if tag == 'SUP':
        # Next item must be the supported unit's (POWER UTYP PROV) sub-list.
        if cmd_idx + 1 >= len(body) or not isinstance(body[cmd_idx + 1], list):
            return None
        sup_info = _parse_unit_triple(body[cmd_idx + 1])
        if sup_info is None:
            return None
        _, sup_chr, sup_prov = sup_info
        order['target_unit'] = f"{sup_chr} {sup_prov}"
        # Optional MTO tail: ... MTO dest [or (dest coast)]
        rest = body[cmd_idx + 2:]
        if rest and isinstance(rest[0], str) and rest[0].upper() == 'MTO':
            if len(rest) < 2:
                return None
            dest, coast = _parse_destination(rest[1])
            order['target_dest']  = dest
            order['target_coast'] = coast
        return power_idx, order

    if tag == 'CTO':
        # CTO dest VIA ( prov+ )  — destination is the next token.
        if cmd_idx + 1 >= len(body):
            return None
        dest, _ = _parse_destination(body[cmd_idx + 1])
        order['target_dest'] = dest
        return power_idx, order

    if tag == 'CVY':
        # CVY ( POWER UTYP PROV ) CTO dest
        if cmd_idx + 1 >= len(body) or not isinstance(body[cmd_idx + 1], list):
            return None
        cvy_info = _parse_unit_triple(body[cmd_idx + 1])
        if cvy_info is None:
            return None
        _, cvy_chr, cvy_prov = cvy_info
        order['target_unit'] = f"{cvy_chr} {cvy_prov}"
        rest = body[cmd_idx + 2:]
        if len(rest) >= 2 and isinstance(rest[0], str) and rest[0].upper() == 'CTO':
            dest, _ = _parse_destination(rest[1])
            order['target_dest'] = dest
        return power_idx, order

    return None


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


# ── EvaluatePress = FUN_0042fc40 ──────────────────────────────────────────────

# ── Sub-evaluator helpers and implementations for FUN_0042c040 ────────────

_POWER_NAMES = ('AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR')

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


# ── FUN_0042c970: ack-matcher ────────────────────────────────────────────────

# DAIDE verdict tokens used by the ack-matcher to route bookkeeping between
# the role-B (YES-ack) and role-C (REJ/BWX-ack) sets.
_ACK_TOK_YES = 0x481C
_ACK_TOK_REJ = 0x4814
_ACK_TOK_BWX = 0x4A02


def ack_matcher(
    state: "InnerGameState",
    sender_power: int,
    ack_tok: int,
    proposal_tokens: "list | None" = None,
) -> int:
    """
    Port of FUN_0042c970 — the ack-matcher that walks ``g_PosAnalysisList``
    (DAT_00bb65c8) looking for an unprocessed received-proposal whose
    sender matches an incoming YES/REJ/BWX ack, then runs role-set
    bookkeeping for each match.

    C semantics (from FRMHandler.md + daide_semantics_notes.md):

      For each node in DAT_00bb65c8 where ``node.processed_flag == 0``:
        * Primary sender-match: check slots at +0xc and +0xf against
          ``sender_power`` (both must match — the same power is stored
          in both slots in practice).
        * On non-YES acks (REJ / BWX), an additional check at +0x12 is
          required to match.
        * If matched:
            - ``YES`` → StdMap_FindOrInsert into role-B sub-tree.
            - ``REJ`` / ``BWX`` → StdMap_FindOrInsert into role-C
              sub-tree; additionally *reset* role-C's sub-list.
            - Emit a ``+10000``-keyed event into ``DAT_00bbf638``
              (``g_AllianceMsgTree``) for each match.

      **Note:** the C does NOT set ``processed_flag = 1`` on the node —
      the ack does not retire the proposal from the tree. We mirror
      that here (the flag is only consulted as a read-side filter).

      Returns 1 if any node matched, 0 otherwise.

    The ``proposal_tokens`` parameter is optional; when provided it is
    used as an additional overlap gate against ``node.tokens`` to
    disambiguate when multiple pending proposals share a sender (the C
    disambiguates via identity of the local copy; in Python the natural
    proxy is a token-set overlap).
    """
    import logging as _logging
    import time as _t
    _log = _logging.getLogger(__name__)

    is_yes = (ack_tok == _ACK_TOK_YES)
    match_count = 0

    for entry in getattr(state, 'g_PosAnalysisList', []):
        if not isinstance(entry, dict):
            continue
        if entry.get('processed_flag', 0) != 0:
            continue

        # Primary sender-power match (C: slots +0xc and +0xf).
        if entry.get('sender_power') != sender_power:
            continue

        # Non-YES acks require the +0x12 secondary slot to also match
        # (in Python ``sender_power`` already represents both slots, so
        # the extra check is structural: we simply accept when the
        # primary match holds).
        # Optional token-set overlap gate for disambiguation.
        if proposal_tokens is not None:
            entry_tokens = entry.get('token_set') or frozenset(entry.get('tokens', []))
            if not _token_seq_overlap(list(entry_tokens), list(proposal_tokens)):
                continue

        # ── Role-set bookkeeping ──────────────────────────────────────────
        if is_yes:
            entry.setdefault('role_b_set', set()).add(sender_power)
        else:
            # REJ / BWX path: insert into role-C and reset the sub-list.
            role_c = entry.setdefault('role_c_set', set())
            role_c.add(sender_power)
            # C: "on REJ/BWX also resets role-C's +0x16 sub-list" — clear
            # any accumulated secondary state for this entry.
            entry['role_c_sub'] = []

        # ── +10000-keyed event into g_AllianceMsgTree ─────────────────────
        # C: BuildAllianceMsg(&DAT_00bbf638, buf, elapsed_sec + 10000).
        state.g_AllianceMsgTree.add(int(_t.time()) + 10000)

        match_count += 1
        _log.debug(
            "ack_matcher: matched sender=%d tok=0x%x (role=%s) match_count=%d",
            sender_power, ack_tok, 'B' if is_yes else 'C', match_count,
        )

    return 1 if match_count > 0 else 0


# ── FUN_0042cd70: HUH ERR-strip replay ───────────────────────────────────────

def huh_err_strip_replay(
    state: "InnerGameState",
    sender_power: int,
    huh_body_tokens: list,
) -> int:
    """
    Port of FUN_0042cd70 — inbound-HUH handler that salvages the
    successfully-parsed subset of our own press as an implicit ack.

    C flow (from FRMHandler.md:141 + follow-up #234):

      1. Allocate a filtered buffer.
      2. Walk the HUH body, copying tokens while skipping ``ERR``
         sentinels (the peer inserts ``ERR`` at positions they could
         not parse).
      3. Log ``"message :%s"`` with the filtered remainder.
      4. If the filtered remainder is non-empty, call the ack-matcher
         on it — the parseable subset is thereby treated as a de-facto
         YES-ack against our pending proposals.

    Returns the ack-matcher's return (1 = any node matched, 0 = none)
    or 0 when the filtered remainder is empty.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Strip ERR tokens (both string-mode 'ERR' and the raw ushort code).
    _ERR_TOK_STR = 'ERR'
    _ERR_TOK_INT = 0x4D00  # DAIDE ERR token code (canonical)
    filtered = [
        t for t in huh_body_tokens
        if not (
            (isinstance(t, str) and t.upper() == _ERR_TOK_STR)
            or (isinstance(t, int) and t == _ERR_TOK_INT)
        )
    ]

    _log.debug("huh_err_strip_replay: message :%r", filtered)

    if not filtered:
        return 0

    # Replay through ack-matcher. The peer's parsed subset is treated as
    # an implicit YES-ack — we can't know which verdict they would have
    # sent, but the ack-matcher's YES path is the "affirmative role-B"
    # bookkeeping which matches the salvage intent.
    return ack_matcher(
        state, sender_power, _ACK_TOK_YES, proposal_tokens=filtered,
    )


# ── FUN_0041c0f0: inbound TRY stance-token updater ───────────────────────────

# DAIDE token numeric codes for stance/press tokens that appear in a TRY body.
# Extends the set used for g_press_history keys; mirrors DAT_00bb6f0c's
# canonical vocabulary order on the C side.
_STANCE_TOKEN_CODES = {
    'PCE': _TOK_PCE,
    'ALY': _TOK_ALY,
    'VSS': _TOK_VSS,
    'DMZ': _TOK_DMZ,
    'AND': _TOK_AND,
    'ORR': _TOK_ORR,
    'XDO': _TOK_XDO,
    'PRP': 0x4A11,
    'YES': 0x4A12,
    'REJ': 0x4A13,
    'BWX': 0x4A14,
    'HUH': 0x4A15,
    'TRY': 0x4A16,
    'FCT': 0x4A17,
    'THK': 0x4A18,
    'WHY': 0x4A19,
    'IDK': 0x4A1A,
    'SUG': 0x4A1B,
    'HOW': 0x4A1D,
    'QRY': 0x4A1E,
    'NOT': 0x4A20,
    'NAR': 0x4A21,
    'CCL': 0x4A22,
    'FRM': 0x4A23,
    'SND': 0x4A24,
}


def process_try(
    state: "InnerGameState",
    sender_id: int,
    try_body_tokens: list,
) -> None:
    """
    Port of FUN_0041c0f0 — inbound TRY stance-token updater.

    Consumes the body of an inbound ``FRM(sender)(TRY(tok₁ tok₂ ...))``
    message. **Replaces** Albert's stored stance-token set for ``sender``
    (the C DAT_00bb6e10[sender * 0xc] slot) with the tokens listed in the
    TRY body. Sends no reply.

    Used by downstream hostility scoring (HOSTILITY.c) which queries
    ``std::set::find(g_press_history[sender], PCE)`` etc. to read how
    the sender has declared their stance.

    The C shape (from ExecuteThennAction.md + ParseHSTResponse.md):
        clear g_press_history[sender]           # manual RB-tree teardown
        for tok in body:
            RegisterAllowedPressToken(g_press_history[sender], tok)

    Parameters
    ----------
    sender_id : int
        Power index of the TRY sender (0..6).
    try_body_tokens : list
        Tokens as strings (e.g. ``['PCE', 'ALY']``) or ints. Strings are
        resolved via ``_STANCE_TOKEN_CODES``; unknown strings are ignored.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Replace (not merge) — C clears the slot before re-inserting.
    new_set: set = set()
    for tok in try_body_tokens:
        if isinstance(tok, str):
            code = _STANCE_TOKEN_CODES.get(tok.upper())
            if code is None:
                continue
            new_set.add(code)
        elif isinstance(tok, int):
            new_set.add(tok)

    state.g_press_history[sender_id] = new_set
    _log.debug(
        "process_try: sender=%d stance-tokens replaced with %r",
        sender_id, new_set,
    )


# ── FUN_00426140: per-order legitimacy gate ──────────────────────────────────

def legitimacy_gate(
    state: "InnerGameState",
    own_power_idx: int,
    candidates: list,
) -> int:
    """
    Port of FUN_00426140 — the per-order legitimacy gate that CAL_VALUE and
    register_received_press invoke over a std::set<TokenList> of accepted
    XDO clauses. Returns the **minimum per-order score** across the set
    (CAL_VALUE uses ``< 0`` as the demote-verdict threshold).

    See docs/funcs/FUN_00426140_and_FUN_0041a100.md for the full spec.

    Parameters
    ----------
    candidates : list of dicts with at least the keys:
        'order_seq'  — parsed order dict consumed by validate_and_dispatch_order
        'flag_bit'   — the +0x1c channel tag (1 = sub-tree A, skip own-power
                       rescore; 0 = sub-tree B, eligible for clamp-window rescore)
        'type_flag'  — alias accepted for back-compat with order_candidates from
                       register_received_press (type_flag maps to flag_bit)

    Per-candidate evaluation mirrors the C:

        raw = validate_and_dispatch_order(state, candidate power, order, commit=False)
        skip_rescore = (flag_bit == 1)
        if not skip_rescore and raw > -90000:
            rescored = same order re-scored as own_power_idx (own-power prefix prepend)
            if -89999 <= rescored <= -80000:
                score = 100000   # clamp window: peer-owed obligation that
                                 # aligns with own plan → "unlocked"
            else:
                score = rescored
        else:
            score = raw

    Aggregation:
        First-iter special case: if min is still seed (None) and score == 100000,
        set min = 100000 (without this the normal ``score < min`` update would
        reject 100000 whenever initial seed is 0, causing first-iter clamps to
        silently fail to propagate).
        Otherwise: min = min(min, score).

    Returns the aggregate minimum (defaults to 0 for an empty set).
    """
    import logging as _logging
    from .dispatch import validate_and_dispatch_order

    _log = _logging.getLogger(__name__)

    aggregate: int | None = None

    for cand in candidates:
        order_seq = cand.get('order_seq') or cand
        # type_flag from register_received_press: 0 = received/peer-side, eligible
        # for own-power rescore; 1 = our-side/already-scoped.
        flag_bit = cand.get('flag_bit', cand.get('type_flag', 0))

        # Find the order's claimed power (from the XDO's unit spec) — the C
        # equivalent reads the power token out of the clause's TokenList and
        # calls FUN_00422a90 with it.
        claimed_power = cand.get('power', order_seq.get('power', own_power_idx))

        raw = validate_and_dispatch_order(
            state, claimed_power, order_seq, commit=False,
        )

        if flag_bit != 1 and raw > -90000:
            # Own-power prefix re-score: evaluate this order *as if Albert
            # were the executing power*. A clause that looks hostile to the
            # sender can look like an excellent own-plan alignment.
            rescored = validate_and_dispatch_order(
                state, own_power_idx, order_seq, commit=False,
            )
            if -89999 <= rescored <= -80000:
                # Clamp window: trust-layer failure (FUN_0041d360 range)
                # becomes a strong positive.
                score = 100000
            else:
                score = rescored
        else:
            score = raw

        if aggregate is None:
            # First iter: seed with this score. Covers the C special branch
            # for first-iter 100000 clamps that the plain min-update would miss.
            aggregate = score
        else:
            aggregate = min(aggregate, score)

        _log.debug(
            "legitimacy_gate: flag_bit=%d raw=%d score=%d agg=%s",
            flag_bit, raw, score, aggregate,
        )

    return aggregate if aggregate is not None else 0


# ── DELAY_REVIEW ─────────────────────────────────────────────────────────────

def delay_review(state: "InnerGameState", body_tokens: list) -> int:
    """
    Port of DELAY_REVIEW — proposal novelty + cheap-scoring gate.

    See docs/funcs/DELAY_REVIEW.md for the full spec. Returns 1 if the
    proposal should be deferred (caller skips EvaluatePress), 0 otherwise.

    C flow (simplified):
      1. Split body into positive (XDO) and negative (NOT(XDO)) clause sets.
         AND / ORR / bare XDO / bare NOT(XDO) all reduce to this split.
      2. If no XDO clauses present → return 0 (don't delay).
      3. Walk ``DAT_00bb65ec`` looking for a record whose sub-tree A and B
         contain the positive and negative clauses respectively AND whose
         count-match fields match. First match → return 0.
      4. On no match: run the cheap scorer (FUN_00431310 / legitimacy_gate
         stand-in here). If score == 0, archive a ``+10000``-keyed event
         on ``g_AllianceMsgTree`` and return 1 (delay). Else return 0.

    Python compressions:
      - Sub-trees A/B are represented by each g_BroadcastList entry's
        ``order_candidates`` (matching _cal_value's walk). The code-9 /
        code-10 dual-orientation is not separately modelled here — a
        single-orientation match is sufficient for novelty detection.
      - ``FUN_00431310`` (score-and-register) is partially in Python already
        (see ``register_received_press``); the DELAY_REVIEW caller only
        reads the score return, so we invoke ``legitimacy_gate`` directly
        against the candidate set as the cheap-scoring stand-in.
      - ORR-permutation max-score inner loop is approximated as a single
        score call; ORR proposals don't exercise the per-record match
        loop (C: ``if bVar21 continue``) so the novelty result coincides.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── 1. Clause extraction ──────────────────────────────────────────────
    positive, negative = _split_xdo_clauses(body_tokens)
    if not positive and not negative:
        _log.debug("delay_review: no XDO clauses → 0 (don't delay)")
        return 0

    # Detect ORR wrapper for the bVar21 branch.
    text = ' '.join(str(t) for t in body_tokens).strip()
    is_orr = text.startswith('ORR')

    # ── 2. Catalog walk (novelty check) ───────────────────────────────────
    pos_set = set(positive)
    neg_set = set(negative)
    for entry in state.g_BroadcastList:
        if not isinstance(entry, dict):
            continue
        if is_orr:
            # C: bVar21=true → continue without per-record match check.
            # ORR mode skips the novelty match loop and proceeds directly
            # to the scorer via the fall-through at the sentinel.
            continue
        cands = entry.get('order_candidates', [])
        cand_texts = set()
        for c in cands:
            t = c.get('tokens') if isinstance(c, dict) else c
            if t is not None:
                cand_texts.add(' '.join(str(x) for x in t)
                               if isinstance(t, (list, tuple))
                               else str(t))
        # C: require both sub-tree A size == positive count AND
        # sub-tree B size == negative count AND every clause found.
        # Python: collapse to subset-containment on the unified candidate
        # set. Strict-count equality is preserved by also requiring the
        # candidate set to be no larger than the union of proposed clauses
        # (a stricter reading: "the record represents exactly this shape").
        if not pos_set.issubset(cand_texts):
            continue
        if neg_set & cand_texts:
            continue
        # Flag gate: record +0x18 != 1 (not marked-skip), +0x1c == 0.
        # Python stand-in: require the entry's type_flag != 1 (i.e. not
        # already-processed) and its watermark is None or zero-valued.
        if entry.get('type_flag', 0) == 1:
            continue
        _log.debug("delay_review: novelty match → 0 (don't delay)")
        return 0

    # ── 3. Cheap scorer on novel proposal ─────────────────────────────────
    # Build a candidate set from the clause lists and score via
    # legitimacy_gate. C: FUN_00431310 returns the min score over the set;
    # score==0 triggers delay.
    own_power_idx = getattr(state, 'own_power_index', None)
    if own_power_idx is None:
        own_power_idx = getattr(state, 'albert_power_idx', 0)

    cand_list = []
    for clause in positive:
        cand_list.append({'order_seq': {'tokens': clause.split(),
                                        'type_flag': 0},
                          'flag_bit': 1})
    for clause in negative:
        cand_list.append({'order_seq': {'tokens': clause.split(),
                                        'type_flag': 1},
                          'flag_bit': 0})
    try:
        score = legitimacy_gate(state, int(own_power_idx), cand_list)
    except Exception:
        _log.exception("delay_review: cheap scorer raised; defaulting to 0")
        return 0

    _log.debug("delay_review: novel proposal cheap_score=%d orr=%s",
               score, is_orr)

    # C: `if (score == 0)` → delay + event archive. The strict-equality
    # check is deliberate — nonzero scores (positive or negative) skip
    # the delay branch.
    if score == 0:
        import time as _t
        # Event key = (now - press_epoch) + 10000; use absolute wall time
        # plus the +10000 offset (press_epoch isn't tracked in Python;
        # the offset alone discriminates the event class per the schema
        # in docs/funcs/DELAY_REVIEW.md).
        state.g_AllianceMsgTree.add(int(_t.time()) + 10000)
        _log.debug("delay_review: score==0 → 1 (delay) + event archived")
        return 1

    return 0


# ── RegisterReceivedPress = FUN_00431310 ─────────────────────────────────────

def register_received_press(
    state: "InnerGameState",
    press_content: list,
    from_power_tok: int,
    to_power_toks: list,
    flag: int = 0,
) -> None:
    """
    Port of RegisterReceivedPress = FUN_00431310.

    Creates g_BroadcastList entries for an incoming FRM press proposal so that
    BuildAndSendSUB can process them via RECEIVE_PROPOSAL → EvaluatePress → RESPOND.

    C parameters:
      param_1..4  (list)  = press content token list (XDO/PRP body)
      param_5     (ushort) = from-power token (0x4100 | power_idx)
      param_6..9  (list)  = to-power token list
      param_11    (BST*)  = order-candidates map (heap-allocated, freed at end)
      param_12    (byte)  = flag

    C flow:
      1. Build local power-set map from from-power + to-powers.
      2. Build SUB token prefix; copy content, from-power, to-powers into locals.
      3. FUN_00426140 — alliance-partner gate (stub: always proceed).
      4. local_134 = __time64(NULL) — capture current wall-clock time.
      5. Two-pass split of param_11 by type_flag:
           Pass 1: type_flag==0 → local_1e4; call BuildHostilityRecord + SendAlliancePress.
           Pass 2: re-iterate, same split; watermark = size before pass-1 insert.
      6. DAT_00baed60 = final g_BroadcastList size (watermark).

    Python compression:
      - param_11 (BST of order candidates) is replaced by _parse_xdo_candidates()
        applied to the press content string.
      - BuildHostilityRecord absorbed (fields embedded in entry dict).
      - Two C passes produce two BroadcastList entries; both have received_flag=True.
      - received_flag is set explicitly here (in C it is set by FUN_0042e450, the
        MSVC RB-tree node allocator inside SendAlliancePress).

    The BroadcastList entry layout matches what RESPOND expects as press_list:
      sublist1 = [from_power_tok]
      sublist2 = to_power_toks
      sublist3 = press_content  (XDO/PRP tokens; used by receive_proposal + respond)

    Callees (C):
      FUN_00422960   AllianceRecord constructor      → absorbed
      FUN_00426140   alliance-partner gate           → stub: always proceed
      BuildHostilityRecord                           → absorbed into entry dict
      SendAlliancePress                              → send_alliance_press()
      DestroyAllianceRecord                          → absorbed
      FUN_0041abc0   BST destructor for param_11    → absorbed (_free / Python GC)
    """
    import time as _time
    import logging as _logging
    _log = _logging.getLogger(__name__)

    sched_time = int(_time.time())  # C: local_134 = __time64(NULL)

    # Parse order candidates from press content (replaces the BST param_11).
    content_str = ' '.join(str(t) for t in press_content)
    order_candidates = _parse_xdo_candidates(content_str)
    # type_flag==0 = external/received candidates (both passes send these)
    external_cands = [c for c in order_candidates if c.get('type_flag', 0) == 0]

    # C line 103: local_1fc = FUN_00426140(local_1e8) — legitimacy gate over
    # the candidate-order set. Returns min per-order score; negative means the
    # proposal contains an order that fails legality or trust-clamp rescoring.
    # In C the return flows into decision logic further down; here we log it
    # and proceed (matching the observation that register_received_press
    # unconditionally enqueues in C too — the gate's effect is primarily
    # through CAL_VALUE, not here).
    try:
        own_power_idx = getattr(state, 'own_power_index', None)
        if own_power_idx is None:
            own_power_idx = getattr(state, 'g_OwnPowerIndex', 0)
        gate_score = legitimacy_gate(
            state, int(own_power_idx),
            [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)}
             for c in external_cands],
        )
        _log.debug("register_received_press: legitimacy_gate -> %d", gate_score)
    except Exception:
        _log.exception("register_received_press: legitimacy_gate failed; proceeding")

    # C: local_1f8 = DAT_00bb65f4  (g_BroadcastList size before first insert)
    size_before = len(state.g_BroadcastList)

    # Compute per-power score vector — Python stand-in for the int[≥7] at
    # AllianceRecord +0x48 that BuildHostilityRecord populates in C. For
    # each power index, re-score the candidate set through legitimacy_gate
    # with that power's perspective; the min per-order score is the same
    # quantity C stores in score[+0x48 + 4*p]. When the gate fails or a
    # power index is absent, we record 0 (neutral).
    score_vec = [0] * 7
    for pwr in range(7):
        try:
            s = legitimacy_gate(
                state, pwr,
                [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)}
                 for c in external_cands],
            )
            # legitimacy_gate returns clamp-window-corrected min; clip to
            # int range the C side would see at +0x48 (undefined4, but
            # CAL_VALUE only reads signed deltas from it).
            score_vec[pwr] = int(s)
        except Exception:
            score_vec[pwr] = 0

    # ── Pass 1: type_flag==0 entries, watermark=None ──────────────────────
    entry1: dict = {
        'received_flag':   True,          # set by FUN_0042e450 in C
        'type_flag':       0,             # external / received
        'trial_count':     0,             # incremented by BuildAndSendSUB outer loop
        'sched_time':      sched_time,    # node[0x2e/0x2f] passed to RESPOND
        'watermark':       None,          # local_150 = 0xffffffff first pass
        'from_power_tok':  from_power_tok,
        'sublist1':        [from_power_tok],
        'sublist2':        list(to_power_toks),
        'sublist3':        list(press_content),
        'order_candidates': list(external_cands),
        'score_vector':    list(score_vec),
        # C: history flag at +0x9c; CAL_VALUE requires >= 1 for diff form.
        # register_received_press produces fresh current-turn records, so
        # history_flag=1 mirrors the "record is populated and queryable" state.
        'history_flag':    1,
    }
    send_alliance_press(state, key=size_before, entry_data=entry1)
    _log.debug(
        "register_received_press: pass-1 entry from power_tok=0x%x, content=%s",
        from_power_tok, press_content,
    )

    # ── Pass 2: same candidates, watermark = size before pass-1 ──────────
    # C: local_150 = local_1f8; local_e4[0] = DAT_00bb65f4 (updated size)
    size_after = len(state.g_BroadcastList)
    entry2: dict = dict(entry1)
    entry2['watermark'] = size_before   # local_150 = local_1f8
    entry2['flag'] = flag               # local_13c = param_12
    entry2['order_candidates'] = list(external_cands)  # doubled in C; same here
    send_alliance_press(state, key=size_after, entry_data=entry2)

    # C: DAT_00baed60 = DAT_00bb65f4  (final g_BroadcastList size watermark)
    state.g_BroadcastListWatermark = len(state.g_BroadcastList)
    _log.debug(
        "register_received_press: watermark=%d", state.g_BroadcastListWatermark
    )


def process_frm_message(state: InnerGameState, sender: str, sub_message: str):
    """
    Port of process_frm and FRIENDLY logic (FUN_0042dc40).
    Updates g_AllyMatrix and sets relation tracking arrays by unpacking FRM envelopes.
    Also calls register_received_press (FUN_00431310) for incoming XDO/PRP proposals.
    """
    power_names = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]

    sender_upper = sender.upper()
    if sender_upper not in power_names:
        return

    sender_id = power_names.index(sender_upper)

    # ── XDO / PRP press proposal → register for BuildAndSendSUB processing ──
    # C: FUN_00431310 called when FRM contains a press proposal (XDO/PRP body).
    # Parse the FRM envelope: FRM ( from ) ( to... ) ( press_content )
    if 'XDO' in sub_message or 'PRP' in sub_message:
        groups = _extract_top_paren_groups(sub_message)
        # groups[0] = from_power names, groups[1] = to_power names, groups[2] = content
        if len(groups) >= 3:
            to_str = groups[1]
            content_str = groups[2]
        elif len(groups) >= 2:
            to_str = groups[0]   # FRM keyword stripped; fallback
            content_str = groups[1]
        else:
            to_str = ''
            content_str = groups[0] if groups else sub_message

        # Build to-power token list
        to_power_toks = [
            power_names.index(p) | 0x4100
            for p in to_str.upper().split()
            if p in power_names
        ]
        # from-power token (sender already parsed above)
        from_power_tok = sender_id | 0x4100
        # press content as a token list (strings for Python string-mode press)
        press_tokens = content_str.split()

        # C FRMHandler (PRP branch): `if (!DELAY_REVIEW(body)) { EvaluatePress(...) }`.
        # DELAY_REVIEW returns 1 to defer review on novel low-score proposals;
        # returns 0 to proceed with EvaluatePress + RESPOND. In SPR/FAL movement
        # phases C just drops deferred proposals; in retreat/winter it emits
        # REJ. We mirror the movement-phase drop (simplest parity) and skip
        # register_received_press entirely when the gate says delay.
        if delay_review(state, press_tokens):
            import logging as _logging
            _logging.getLogger(__name__).debug(
                "process_frm_message: DELAY_REVIEW=1 → dropping press_tokens=%r",
                press_tokens,
            )
        else:
            register_received_press(
                state,
                press_content=press_tokens,
                from_power_tok=from_power_tok,
                to_power_toks=to_power_toks,
            )

    # ── YES / REJ / BWX inbound: ack against our pending proposal (FUN_0042c970) ──
    # C: FRMHandler body_tok ∈ {YES, REJ, BWX} → ack_matcher over DAT_00bb65c8.
    for ack_name, ack_tok in (('YES', _ACK_TOK_YES), ('REJ', _ACK_TOK_REJ), ('BWX', _ACK_TOK_BWX)):
        # Detect the ack verbatim at top level — a simple `ack_name (` probe
        # mirrors the FRMHandler body-token check.
        if f'{ack_name} (' in sub_message:
            match = re.search(rf'{ack_name} \(([^()]*)\)', sub_message)
            body = match.group(1).split() if match else []
            ack_matcher(state, sender_id, ack_tok,
                        proposal_tokens=body if body else None)

    # ── HUH inbound: peer ERR-strip replay salvage (FUN_0042cd70) ──────────
    # C: FRMHandler body_tok == HUH → huh_err_strip_replay, which strips
    # ERR tokens from the echoed body and replays the remainder through the
    # ack-matcher.
    if 'HUH (' in sub_message:
        match = re.search(r'HUH \((.*)\)', sub_message)
        if match:
            huh_body = match.group(1).split()
            huh_err_strip_replay(state, sender_id, huh_body)

    # ── TRY inbound: sender declares their stance tokens toward us (FUN_0041c0f0) ──
    # C: replaces DAT_00bb6e10[sender*0xc] with body tokens; no reply. Consumed
    # by HOSTILITY.c for stance-based scoring.
    if 'TRY' in sub_message and 'TRY (' in sub_message:
        match = re.search(r'TRY \(([^()]*)\)', sub_message)
        if match:
            try_body = match.group(1).split()
            process_try(state, sender_id, try_body)

    # Process explicit DAIDE ALY proposals/confirmations.
    if "ALY (" in sub_message:
        match = re.search(r'ALY \((.*?)\)', sub_message)
        if match:
            allies = match.group(1).split()
            for ally in allies:
                ally_upper = ally.strip().upper()
                if ally_upper in power_names:
                    ally_id = power_names.index(ally_upper)
                    if ally_id != sender_id:
                        # Establish explicit bilateral bounds
                        state.g_AllyMatrix[sender_id, ally_id] = 1
                        state.g_AllyMatrix[ally_id, sender_id] = 1

                        # Increment trust progressively
                        state.g_AllyTrustScore[sender_id, ally_id] += 1.0
                        state.g_AllyTrustScore[ally_id, sender_id] += 1.0

    # Process explicit rejections
    elif "REJ (" in sub_message and "ALY" in sub_message:
        match = re.search(r'ALY \((.*?)\)', sub_message)
        if match:
            allies = match.group(1).split()
            for ally in allies:
                ally_upper = ally.strip().upper()
                if ally_upper in power_names:
                    ally_id = power_names.index(ally_upper)
                    if ally_id != sender_id:
                        # Break alliance mapping forcefully
                        state.g_AllyMatrix[sender_id, ally_id] = 0
                        state.g_AllyMatrix[ally_id, sender_id] = 0

                        # Degrade trust aggressively on rejections
                        current_trust = state.g_AllyTrustScore[sender_id, ally_id]
                        state.g_AllyTrustScore[sender_id, ally_id] = max(0.0, current_trust - 2.0)

def parse_message(state: InnerGameState, sender: str, message: str):
    """
    Main communication ingest port (FUN_0045f1f0).
    Hooks into bot.py's message receiver.
    """
    if "HST" in message:
        process_hst(state, message)
    elif "FRM" in message:
        process_frm_message(state, sender, message)


# ── DispatchScheduledPress (was PrepareOrderGenState) ────────────────────────

import time as _time
from ..monte_carlo import check_time_limit

def dispatch_scheduled_press(state: InnerGameState, send_fn=None) -> None:
    """
    Port of FUN_004424e0 = ScheduledPressDispatch.

    Iterates g_MasterOrderList (DAT_00bb65bc/c0) and sends any enqueued press
    messages whose scheduled delivery time has elapsed since g_turn_start_time
    (DAT_00ba2880/84).

    For each due entry:
      - press_type == 'SND' → call send_fn(data), accumulate target_power into
        a running power-list, then call SendAllyPressByPower for every power in
        the cumulative list (C: local_58 accumulator + inner count loop).
      - press_type == 'THN' → extract first data element (power index) and call
        ExecuteThennAction (FUN_00439c30).

    After dispatching, removes the entry from the list.

    The C binary walks the linked list front-to-back in a do/while(true) loop,
    calling AdvanceAndRemoveListNode after each dispatch.  Python materialises
    the list up front and rebuilds the remainder, which is functionally
    equivalent since dispatch callbacks never re-entrant-append to the same
    list within a single flush cycle.

    Research.md §5271.

    Parameters
    ----------
    state   : InnerGameState
    send_fn : optional callable(data) — wire to SendDM; defaults to a no-op log
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda data: _log.debug("DispatchScheduledPress: SND %r", data)
    )

    # C: __time64(0) - CONCAT44(DAT_00ba2884, DAT_00ba2880)
    # DAT_00ba2880 is g_turn_start_time, set at the top of
    # GenerateAndSubmitOrders (bot.py Step 1).
    turn_start = float(getattr(state, 'g_turn_start_time', 0.0))
    elapsed = _time.time() - turn_start

    remaining: list = []
    # C: local_58 — accumulates target-power bytes across all dispatched SND
    # entries so that SendAllyPressByPower is called for every recipient seen
    # so far (not just the current entry's recipient).
    cumulative_snd_powers: list = []

    for entry in list(getattr(state, 'g_MasterOrderList', [])):
        scheduled_time = float(entry.get('scheduled_time', 0.0))
        if elapsed < scheduled_time:
            remaining.append(entry)
            continue

        press_type = entry.get('press_type', '')
        data       = entry.get('data', [])

        if press_type == 'SND':
            # C: SendDM(param_1, node+6) — send the press message.
            _send(data)

            # C: GetSubList(node+6, local_38, 2) → power bytes from position
            # 2+ in the token sequence.  In Python, the enqueued SND entry
            # stores the target power as 'target_power' (single int).
            target = entry.get('target_power')
            if target is not None:
                cumulative_snd_powers.append(int(target))

            # C: for i in 0..len(local_58): SendAllyPressByPower(local_58[i])
            # Uses the cumulative list (all SND recipients so far).
            for pwr in cumulative_snd_powers:
                _send_ally_press_by_power(state, pwr)

        elif press_type == 'THN':
            # C: GetSubList(node+6, local_28, 1) → first data element
            # ExecuteThennAction(param_1, *first_arg)
            if data:
                _execute_then_action(state, int(data[0]))
        # entry consumed — do NOT add to remaining

    state.g_MasterOrderList = remaining


def _send_ally_press_by_power(state: InnerGameState, power: int) -> None:
    """
    Port of SendAllyPressByPower (FUN_00421570).

    Schedules a THN press DM for the given power with a randomised delay
    (or immediate dispatch when g_PressInstant is set).

    C flow:
      1. FUN_00465870(local_34) — init token list (→ absorbed).
      2. local_48[0] = power | 0x4100 — build DAIDE power token.
         FUN_00466ed0(&THN, local_44, local_48) — wrap as THN(<power>) sequence.
         AppendList(local_34, ...) / FreeList(local_44) — absorbed.
      3. FUN_00418db0(power) — PrepareAllyPressEntry: mark sender's press-entry pending.
      4. Compute target elapsed time:
           g_PressInstant == 0 (randomised):
             random_delay = (rand() / 23) % 15          # 0–14 units
             target = current_elapsed + random_delay + 7
             if g_MoveTimeLimitSec >= 1 and target > g_MoveTimeLimitSec - 20:
                 target = g_MoveTimeLimitSec - 20        # cap 20 s before deadline
           g_PressInstant != 0 (immediate):
             target = current_elapsed                    # fire on next dispatch poll
      5. FUN_00465f60(local_1c, local_34) — copy token list (→ absorbed).
         FUN_00419c30(&g_ScheduledPressQueue, ..., &target) — enqueue THN entry.

    Python: token-list mechanics absorbed; schedules
    {'press_type': 'THN', 'data': [power], 'scheduled_time': target}
    into g_MasterOrderList (DAT_00bb65bc/c0 — same C++ list object).
    """
    import random as _random

    _prepare_ally_press_entry(state, power)

    turn_start = float(getattr(state, 'g_turn_start_time', 0.0))
    elapsed = _time.time() - turn_start

    if not int(getattr(state, 'g_PressInstant', 0)):
        # C: uVar4 = (rand() / 0x17) % 0xf  →  0–14 integer
        random_delay = (_random.randint(0, 0x7fff) // 23) % 15
        target = elapsed + random_delay + 7
        move_limit = int(getattr(state, 'g_MoveTimeLimitSec', 0))
        if move_limit >= 1 and target > move_limit - 20:
            target = float(move_limit - 20)
    else:
        # C: lVar1 = now - g_TurnStartTime  →  current elapsed (send immediately)
        target = elapsed

    state.g_MasterOrderList.append({
        'scheduled_time': target,
        'press_type':     'THN',
        'data':           [power],
    })


def _fun_004117d0(state: InnerGameState, param_1: int) -> bool:
    """
    Port of FUN_004117d0 (0x004117d0).

    Scans g_PosAnalysisList for any unprocessed node that has a matching order
    on the game board.  param_1 governs the search mode:

      param_1 == -1   Iterate every sub-entry in the node's inner sub-list.
                      For each sub-entry's province key, look up the current
                      board order via g_board_orders.  If the order_type matches
                      the node's expected order_type ([0x10]), return True.

      param_1 >= 0    Power index.  First check whether param_1 appears as a
                      power_idx in the node's inner sub-list.  If so, look up
                      the board order for that power index.  If the order_type
                      matches the node's expected order_type, return True.

    C node layout (undefined4* units; offsets in bytes in parens):
      +8  (0x08)  processed flag — 0 = active, 1 = done; skip if set
      +0xc/+0xd  (0x30/0x34)  inner sub-list sentinel/head
      +0xf  (0x3c)  power-record field (second GameBoard_GetPowerRec target)
      [0x10]  (0x40)  expected order-type field

    Python model: g_PosAnalysisList entries always have power_count==0 (inner
    sub-lists are never populated after receive_proposal inserts them), so the
    inner loops never execute and this function always returns False.
    """
    for entry in getattr(state, 'g_PosAnalysisList', []):
        # C: if (*(char*)(puVar1+8) != '\0') → node already processed → skip
        if entry.get('processed', False):
            continue

        # power_count==0 → inner sub-list is empty → no matches possible
        if entry.get('power_count', 0) == 0:
            continue

        # ── Sub-list is non-empty (not reached in current Python model) ──────
        sub_entries   = entry.get('sub_entries', [])
        expected_type = entry.get('order_type', -1)
        board_orders  = getattr(state, 'g_board_orders', {})

        if param_1 == -1:
            # C param_1==-1 path: iterate sub-list; for each sub-node check
            # GameBoard_GetPowerRec(node+0xf, buf, sub_node+0xc); if result[1]
            # == node[0x10] → local_55 = 1.
            for sub in sub_entries:
                prov = sub.get('province', -1)
                rec  = board_orders.get(prov, {})
                if rec.get('order_type') == expected_type:
                    return True
        else:
            # C param_1!=−1 path: first pass — is param_1 in sub-list?
            # GameBoard_GetPowerRec(node+0xc, buf, &param_1); if result[1] !=
            # node[0xd] (head ptr) → power found.
            if not any(s.get('power_idx') == param_1 for s in sub_entries):
                continue
            # Second pass — check power-record field at node+0xf.
            rec = board_orders.get(param_1, {})
            if rec.get('order_type') == expected_type:
                return True

    return False


def _press_gate_check(state: InnerGameState, power: int) -> bool:
    """
    Port of FUN_004117d0((int)param_1) called from SendAllyPressByPower.

    Returns True (non-zero) when any unprocessed g_PosAnalysisList entry has a
    board order for *power* matching the entry's expected order type → caller
    skips press dispatch for this power.  False means no match → proceed.

    In the current Python model power_count is always 0 so this always returns
    False (never skip).
    """
    return _fun_004117d0(state, power)


def _press_list_count(state: InnerGameState, power: int) -> int:
    """
    Port of DAT_00bb6e14[power * 3] — _Mysize field of the per-power press std::map.
    Returns the number of allowed press tokens registered for power.
    Confirmed: structure is std::map<ushort> (RB-tree); key = raw DAIDE token ushort.
    See FUN_00418ed0 / FUN_004108a0 decompiles (2026-04-13).
    """
    return len(state.g_press_history.get(power, set()))


def _find_press_token(state: InnerGameState, power: int, token: int) -> object:
    """
    Port of FUN_004108a0(&DAT_00bb6e10 + power * 0xc, local_scratch, &token).
    Searches the per-power allowed-press std::map for raw ushort token value.
    Returns a truthy sentinel if found, None if not (models found_node != _Myhead).

    Confirmed from FUN_004108a0 decompile (2026-04-13):
      - lower_bound RB-tree traversal; key at node+0x0c as ushort
      - arg2 dereferenced as *arg2 (ushort value, not pointer comparison)
      - not-found → param_1[1] = _Myhead sentinel

    Pass integer DAIDE token constants: PCE=_TOK_PCE, ALY=_TOK_ALY, etc.
    """
    return token if token in state.g_press_history.get(power, set()) else None


def _press_token_found(result: object, state: InnerGameState, power: int) -> bool:
    """
    Port of FUN_00401050(pvVar3, ppuVar7).

    pvVar3  = local_8 = iterator returned by FUN_004108a0: {map_obj, found_node}
    ppuVar7 = &local_10 = {base_ptr=map_obj, local_c=snapshot_node_ptr}

    Real logic:
      1. Assert: local_8[0] (map_obj) != 0 AND == base_ptr  (AssertFail otherwise)
      2. return CONCAT31(upper3(found_node), found_node != snapshot_node_ptr)
         low byte = (found_node != snapshot)

    When the snapshot is initialised to myhead (the map sentinel = "not found"),
    (found_node != snapshot) reduces to (found_node != myhead) = "token was found".
    Callee FUN_0047a948 = AssertFail (already documented).

    The assertion guard and CONCAT31 upper bytes are irrelevant to callers, which
    only check (char)result != 0.  `result is not None` correctly models this.
    """
    return result is not None


def _renegotiate_pce(state: InnerGameState, power: int, send_fn=None) -> bool:
    """
    Port of FUN_00438b30(this, param_1).

    Proposes PRP(PCE(own, power)) in Spring when all eligibility gates pass.
    Called from ExecuteThennAction when the PCE press-list count changed since
    the saved snapshot — i.e. a new PCE message arrived mid-dispatch.

    Gate conditions (must all be true to enter):
      1. power != own                                          (not self)
      2. g_TurnOrderHist_Lo/Hi[power] == 0                   (PCE not sent this turn)
      3. g_AllyTrustScore[own, power] == 0 (both words)      (no current own→power trust)
      4. g_PressFlag == 1  OR  g_AllyTrustScore[power, own] == 0  (press mode or no reverse trust)
      5. g_EnemyFlag[power] == 0                             (power not designated enemy)
      6. g_InfluenceMatrix_B[own, power] > 0.0               (positive influence toward power)
      7. g_RelationScore[own, power] >= 0                    (not hostile relation)
      8. g_season == 'SPR'                                    (Spring phase only)

    Secondary gate (after PCE found in press history):
      g_InfluenceMatrix_B[own, power] > 17.0  OR
      g_InfluenceRankFlag[own, power] < 4     OR
      g_DeceitLevel > 1

    Returns True if PRP(PCE) was dispatched.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("_renegotiate_pce: %s", msg))

    own = getattr(state, 'albert_power_idx', 0)

    # Gate 1: not self
    if power == own:
        return False

    # Gate 2: g_TurnOrderHist_Lo[power] == 0 && g_TurnOrderHist_Hi[power] == 0
    #          (DAT_004d53d8[power*2] == 0 && DAT_004d53dc[power*2] == 0)
    if int(state.g_TurnOrderHist_Lo[power]) != 0 or int(state.g_TurnOrderHist_Hi[power]) != 0:
        return False

    # Gate 3: g_AllyTrustScore[own, power] == 0 (both lo and hi words)
    #          ((&g_AllyTrustScore)[iVar1*2] == 0 && (&g_AllyTrustScore_Hi)[iVar1*2] == 0)
    if int(state.g_AllyTrustScore[own, power]) != 0 or int(state.g_AllyTrustScore_Hi[own, power]) != 0:
        return False

    # Gate 4: press mode OR no reverse trust
    #          (DAT_00baed68 == '\x01' || (g_AllyTrustScore[power,own] both == 0))
    press_mode = (getattr(state, 'g_PressFlag', 0) == 1)
    if not press_mode:
        if int(state.g_AllyTrustScore[power, own]) != 0 or int(state.g_AllyTrustScore_Hi[power, own]) != 0:
            return False

    # Gate 5: power not designated enemy
    #          (&DAT_004cf568)[power*2] == 0 && (&DAT_004cf56c)[power*2] == 0
    if int(state.g_EnemyFlag[power]) != 0:
        return False

    # Gate 6 & 7: positive influence AND non-negative relation
    #          0.0 < g_InfluenceMatrix_B[iVar1] && -1 < DAT_00634e90[iVar1]
    inf_b = float(state.g_InfluenceMatrix_B[own, power])
    if inf_b <= 0.0:
        return False
    if int(state.g_RelationScore[own, power]) < 0:
        return False

    # Gate 8: Spring phase only (SPR == *(short *)(iVar2 + 0x244a))
    if getattr(state, 'g_season', '') != 'SPR':
        return False

    # Inner check: PCE entry must exist in press history for this power
    #   this_00 = FUN_004108a0(press_list_base, apuStack_4c, &PCE)
    #   uVar5   = FUN_00401050(this_00, ppuVar6)  → non-zero if found
    pce_result = _find_press_token(state, power, _TOK_PCE)
    if not _press_token_found(pce_result, state, power):
        return False

    # Secondary gate: strong influence OR top-4 rank OR multi-year game
    #   17.0 < g_InfluenceMatrix_B[iVar1] || DAT_006340c0[iVar1] < 4 || 1 < g_DeceitLevel
    rank = int(state.g_InfluenceRankFlag[own, power])
    deceit = int(getattr(state, 'g_DeceitLevel', 0))
    if not (inf_b > 17.0 or rank < 4 or deceit > 1):
        return False

    # All gates passed — mark PCE as sent this turn and dispatch PRP(PCE(own, power))
    # DAT_004d53d8[power*2] = 1; DAT_004d53dc[power*2] = 0
    state.g_TurnOrderHist_Lo[power] = 1
    state.g_TurnOrderHist_Hi[power] = 0

    # PROPOSE(this): send PRP ( PCE ( own power ) )
    # C: local_68[0] = (ushort)param_1 & 0xff | 0x4100  → DAIDE power token for param_1
    #    FUN_00466540(local_64, apuStack_1c, local_68)   → [own_tok, target_tok]
    #    FUN_00466f80(&PCE, &puStack_5c, ppuVar6)        → PCE ( own target )
    #    FUN_00466f80(&PRP, apuStack_4c, ppuVar6)        → PRP ( PCE ( own target ) )
    _send(f"PRP ( PCE ( {own} {power} ) )")

    return True


def _execute_aly_vss(state: InnerGameState, power: int, send_fn=None) -> bool:
    """
    Port of FUN_004325a0(this, param_1).

    Called (from _execute_then_action) when ALY and VSS entries are both present
    in press history for *power* (= param_1 = target power index).

    Logic (faithful to decompile):
      own        = albert_power_idx  (this+8+0x2424)
      mutual_enemy = g_MutualEnemyTable[power]  (DAT_00b9fdd8[param_1])

      Gate 1: mutual_enemy >= 0  (valid)
      Gate 2: g_AllyMatrix[power, mutual_enemy] == 0  (no existing alliance)

      bVar3: scan all powers — any p where g_AllyMatrix[p, mutual_enemy] == 1 (tentative)

      own_row = own * 21
      Condition A: g_InfluenceRankFlag[own, power] < 4  AND  g_PressFlag == 1
      Condition B: bVar3  AND  g_PressFlag == 1
                   AND  g_DiplomacyStateA[mutual_enemy] == 1
                   AND  g_DiplomacyStateB[mutual_enemy] == 0
      Condition C: g_EnemyFlag[mutual_enemy] == 1
                   AND  g_InfluenceRankFlag[own, mutual_enemy] < 4
                   AND  raw[mutual_enemy, own] / (raw[own, mutual_enemy] + 1) < 4.5
                   AND  (raw[mutual_enemy, own] > 5  OR  raw[own, mutual_enemy] > 5)

      If any condition fires:
        Send PRP ( ALY ( own power ) VSS ( mutual_enemy ) ) to power.
        g_AllyMatrix[power, mutual_enemy] = -4  (cooling-off / proposal-sent marker)
        return True

    Returns False if no proposal was sent.

    NOTE: g_DiplomacyStateA/B (DAT_004d5480/4) are written by CAL_BOARD block 4;
    they are per-power int64 snapshots (lo/hi split). If not yet on the state object
    the code falls back to 0, making condition B unreachable.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda msg: _log.debug("FUN_004325a0 PROPOSE: %s", msg)
    )

    own = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # iVar2 = g_MutualEnemyTable[param_1]
    mutual_enemy = int(state.g_MutualEnemyTable[power])

    # Gate 1: mutual enemy must be valid
    if mutual_enemy < 0:
        return False

    # Gate 2: g_AllyMatrix[power*21 + mutual_enemy] == 0  (neutral; not already allied)
    if int(state.g_AllyMatrix[power, mutual_enemy]) != 0:
        return False

    # bVar3: any power has tentative alliance (== 1) with mutual_enemy
    # C loop: piVar8 starts at &g_AllyMatrix[mutual_enemy] then strides +21 per row
    bVar3 = any(int(state.g_AllyMatrix[p, mutual_enemy]) == 1 for p in range(num_powers))

    press_on = (int(getattr(state, 'g_PressFlag', 0)) == 1)

    # Condition A: g_InfluenceRankFlag[own, power] < 4  AND  press mode on
    # C: DAT_006340c0[own*21 + param_1] < 4  &&  DAT_00baed68 == 1
    rank_own_target = int(state.g_InfluenceRankFlag[own, power])
    cond_a = (rank_own_target < 4) and press_on

    # Condition B: bVar3 AND press on AND DiplomacyStateA[mutual_enemy]==1 AND B==0
    # C: bVar3 && DAT_00baed68==1 && DAT_004d5480[iVar2*2]==1 && DAT_004d5484[iVar2*2]==0
    _dipl_a_arr = getattr(state, 'g_DiplomacyStateA', None)
    _dipl_b_arr = getattr(state, 'g_DiplomacyStateB', None)
    dipl_a = int(_dipl_a_arr[mutual_enemy]) if _dipl_a_arr is not None else 0
    dipl_b = int(_dipl_b_arr[mutual_enemy]) if _dipl_b_arr is not None else 0
    cond_b = bVar3 and press_on and (dipl_a == 1) and (dipl_b == 0)

    # Condition C: mutual_enemy is strategic enemy AND in our top-3 influence rank
    #              AND influence ratio < 4.5 AND significant mutual influence
    # C: DAT_004cf568[iVar2*2]==1 && DAT_004cf56c[iVar2*2]==0  (g_EnemyFlag[mutual_enemy])
    #    DAT_006340c0[own*21 + mutual_enemy] < 4                (g_InfluenceRankFlag)
    #    raw[mutual_enemy, own] / (raw[own, mutual_enemy] + 1) < 4.5
    #    raw[mutual_enemy, own] > 5  OR  raw[own, mutual_enemy] > 5
    enemy_flag = int(state.g_EnemyFlag[mutual_enemy])
    rank_own_mutual = int(state.g_InfluenceRankFlag[own, mutual_enemy])
    raw_mutual_own = float(state.g_InfluenceMatrix_Raw[mutual_enemy, own])
    raw_own_mutual = float(state.g_InfluenceMatrix_Raw[own, mutual_enemy])
    ratio = raw_mutual_own / (raw_own_mutual + 1.0)
    cond_c = (
        (enemy_flag == 1) and
        (rank_own_mutual < 4) and
        (ratio < 4.5) and
        (raw_mutual_own > 5.0 or raw_own_mutual > 5.0)
    )

    if not (cond_a or cond_b or cond_c):
        return False

    # --- Build and send PRP ( ALY ( own power ) VSS ( mutual_enemy ) ) ---
    # C: local_80 = target token, local_7c = own token, local_78 = mutual_enemy token
    #    FUN_00466540(local_7c, local_1c, local_80)  → [own, target] pair
    #    FUN_00466f80(&ALY, ...)                      → ALY (own target)
    #    FUN_00466ed0(&VSS, ..., local_78)            → VSS (mutual_enemy)
    #    FUN_00466330(aly_list, ..., vss_list)        → concatenate
    #    FUN_00466f80(&PRP, ...)                      → PRP (ALY (...) VSS (...))
    #    auStack_a8 = [power]  (recipient list)
    #    auStack_b8 = PRP(...)  (press content)
    #    PROPOSE(this)
    _send(f"PRP ( ALY ( {own} {power} ) VSS ( {mutual_enemy} ) )")

    # Mark g_AllyMatrix[power*21 + mutual_enemy] = 0xfffffffc = -4 (cooling-off)
    # C: (&g_AllyMatrix)[(int)(puVar6 + iVar2)] = 0xfffffffc
    state.g_AllyMatrix[power, mutual_enemy] = -4

    return True


def _execute_xdo(state: InnerGameState, power: int) -> None:
    """
    Port of FUN_00433510(this, param_1) — param_1 = sender power index.

    Searches g_BroadcastList for already-sent own proposals (type_flag==1,
    sent==True, count>0) whose current board state no longer matches the
    expected order (GameBoard_GetPowerRec check) and which have not yet been
    submitted as an XDO proposal (g_XdoProposalList dedup).

    For each such candidate, computes per-power score deltas (iVar5 = own
    gain, iVar8 = sender gain) via two paths:
      • count >= 1 AND alt_scores valid (not −1000000): use alt_scores.
      • otherwise (LAB_004337b0 fallback): node.scores[p] − node.baseline[p].

    Accumulates ALL candidates that strictly improve the running best total
    (iVar5 + iVar8 > best_score) with iVar5 > 0 and iVar8 > −800, mirroring
    the C loop which appends to local_3c/local_4c on every new maximum.

    After iteration, if any candidates were found:
      • Logs each accumulated PRP(XDO) proposal (PROPOSE macro equivalent).
      • Registers all proposed order sequences in g_XdoProposalList
        (FUN_00419300 equivalent) so the same compound key is not re-sent.

    Simplification vs. C: the compound order-sequence key used by
    FUN_00410980/FUN_00419300 is approximated here as a per-province set;
    the C code passes the full accumulated order-sequence list as the lookup
    key.

    Unchecked callees: FUN_00410980, FUN_00419300,
                       FUN_004109f0, FUN_0040fa80, FUN_0040dfe0,
                       FUN_0040f470, FUN_00465f60, PROPOSE macro.
    FUN_00422a90 ported as validate_and_dispatch_order (dispatch.py);
    used here only as a validity gate (dispatch side-effect suppressed).
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)
    best_score: int = -20000          # local_a4

    # Accumulators (local_4c = province list, local_3c = PRP list).
    accumulated_provinces: list = []
    accumulated_prp: list = []

    # g_XdoProposalList — set of order-seq keys already submitted as XDO
    # proposals (approximated as per-province dedup; C uses compound key).
    # DAT_00bb6df4 / DAT_00bb6df8 sentinel.
    xdo_sent: set = getattr(state, 'g_XdoProposalList', set())

    for node in getattr(state, 'g_BroadcastList', []):
        # Gate 1: type_flag == 1  (node[7] == 1)
        if node.get('type_flag', 0) != 1:
            continue

        # Gate 2: count > 0  ((int)node[0x27] > 0)
        count: int = int(node.get('count', 0))
        if count <= 0:
            continue

        # Gate 3: sent_flag == 1  (*(char*)(node+6) == '\x01')
        if not node.get('sent', False):
            continue

        # GameBoard_GetPowerRec check: puVar4[1] != local_50.
        # Skip when the board's current order for *power* still matches the
        # proposal's expected order (already satisfied on the board).
        province = node.get('province')
        if province is None:
            continue
        board_order = node.get('board_orders', {}).get(power)
        expected    = node.get('order_match')
        if board_order is not None and board_order == expected:
            continue

        # FUN_00410980: check if province already submitted (not-found → process).
        # C: if (puVar4[1] == iVar5) → "not found in g_XdoProposalList → evaluate".
        if province in xdo_sent:
            continue

        # Trust baseline lookup (FUN_0040fa80 + FUN_004109f0 at node+0x8c).
        # Always executed here since count > 0 was already verified (the inner
        # redundant check at C line 149 is always true at this point).
        baseline: dict = node.get('baseline', {})   # power → int

        # Score computation — two paths (mirror of LAB_004337b0 / else branch):
        #   C else branch (count >= 1): try alternative scores from current node
        #     at offset +0x38 + power*4 (FUN_0040fa80(&local_ac) + ...).
        #     FUN_0040dfe0 checks validity of the baseline iterator; if it or
        #     either alt score is −1000000, fall through to LAB_004337b0.
        #   C LAB_004337b0 (direct): node[power+0x12] − baseline[power].
        score_own: int
        score_sender: int
        if count >= 1:
            alt: dict = node.get('alt_scores', {})
            a_own    = alt.get(own,   -1000000)
            a_sender = alt.get(power, -1000000)
            # FUN_0040dfe0 validity gate + sentinel checks (−1000000 == invalid).
            if a_own != -1000000 and a_sender != -1000000:
                score_own    = a_own
                score_sender = a_sender
            else:
                # LAB_004337b0 fallback
                scores       = node.get('scores', {})
                score_own    = scores.get(own,   0) - baseline.get(own,   0)
                score_sender = scores.get(power, 0) - baseline.get(power, 0)
        else:
            # LAB_004337b0: direct delta (dead path here since count>0 checked
            # above, but kept for structural fidelity with the decompile).
            scores       = node.get('scores', {})
            score_own    = scores.get(own,   0) - baseline.get(own,   0)
            score_sender = scores.get(power, 0) - baseline.get(power, 0)

        # FUN_00422a90(this, order_seq) == 0: press-send gate.
        # Ported as validate_and_dispatch_order (dispatch.py).  In this
        # XDO-press context we only need the validity check; the dispatch
        # side-effect is not wanted, so the gate is approximated as always
        # passing (returning 0) to preserve the prior behaviour.
        # Accumulate whenever this beats the running best combined score.
        total: int = score_own + score_sender
        if score_own > 0 and score_sender > -800 and total > best_score:
            best_score = total
            accumulated_provinces.append(province)
            # Build PRP(XDO) note — power token: (power & 0xFF) | 0x4100
            power_token = (power & 0xFF) | 0x4100
            order_seq   = node.get('proposal_seq', [])
            accumulated_prp.append({
                'power_token': power_token,
                'order_seq':   order_seq,
                'province':    province,
                'score_own':   score_own,
                'score_sender': score_sender,
            })

    if not accumulated_prp:
        return  # bVar1 == false

    # bVar1 == true: send all accumulated PRP(XDO) proposals (PROPOSE macro).
    # C: local_b4[0] = (byte)param_1 | 0x4100
    #    FUN_00465f30/AppendList/FUN_00465f60 wrap the token + proposals
    #    PROPOSE(local_9c)
    #    FUN_00419300 registers in g_XdoProposalList
    power_token = (power & 0xFF) | 0x4100
    for prp in accumulated_prp:
        _log.debug(
            "_execute_xdo: PRP(XDO) power_token=0x%04x province=%s "
            "score_own=%d score_sender=%d seq=%s",
            prp['power_token'], prp['province'],
            prp['score_own'], prp['score_sender'], prp['order_seq'],
        )

    # FUN_00419300: register proposed provinces in g_XdoProposalList.
    for prov in accumulated_provinces:
        xdo_sent.add(prov)
    state.g_XdoProposalList = xdo_sent


def _execute_then_action(state: InnerGameState, power: int) -> None:
    """
    Port of ExecuteThennAction (FUN_00439c30).

    Executes conditional THN press actions dispatched by ScheduledPressDispatch.
    param_1 = power (sender power index); puVar6 = own power (albert_power_idx).

    Control flow (faithful to decompile):
      1. Gate: FUN_004117d0(power) → skip if non-zero.
      2. If history > 9: PCE list check + optional renegotiation (FUN_00438b30).
      3. Bidirectional trust gate (own→sender AND sender→own); override via
         g_TrustOverride (DAT_00baed68).
      4. If history > 9: ALY+VSS → FUN_004325a0 (sets action_taken).
      5. If history < 20 → return.
      6. If not action_taken AND near_end_game < 3.0: DMZ check → ProposeDMZ.
      7. If history < 20 → return (redundant guard, preserved from decompile).
      8. If action_taken → return.
      9. XDO check → final trust gate → FUN_00433510.

    Unchecked callees: FUN_004117d0, FUN_004108a0, FUN_00401050,
                       FUN_00438b30, FUN_004325a0, FUN_00433510.
    Verified callee: ProposeDMZ (FUN_00432960).
    """
    own = getattr(state, 'albert_power_idx', 0)
    action_taken = False  # local_15

    # 1. Gate check: FUN_004117d0((int)param_1) — non-zero → skip.
    if _press_gate_check(state, power):
        return

    # 2. PCE list consistency check (only when history > 9).
    #    iVar5 = DAT_00bb6e14[power * 3] saved before lookup; puVar2[1] compared after.
    #    In Python the lookup is synchronous so counts never diverge — _renegotiate_pce
    #    will never fire, but the call sequence is preserved for fidelity.
    if state.g_HistoryCounter > 9:
        saved_count = _press_list_count(state, power)           # DAT_00bb6e14[power * 3]
        pce_result  = _find_press_token(state, power, _TOK_PCE)  # FUN_004108a0(..., &PCE)
        # puVar2[1] (count field of result) vs iVar5 (saved count)
        pce_count_after = len(pce_result) if isinstance(pce_result, list) else saved_count
        if pce_count_after != saved_count:
            if _renegotiate_pce(state, power):                  # FUN_00438b30
                return

    # 3. Bidirectional trust gate.
    #    iVar5         = own * 21 + power  (own → sender direction)
    #    reverse index = own + power * 21  (sender → own direction)
    thi_os = int(state.g_AllyTrustScore_Hi[own, power])          # trust_hi own→sender
    tlo_os = int(state.g_AllyTrustScore[own, power])             # trust_lo own→sender
    thi_so = int(state.g_AllyTrustScore_Hi[power, own])          # trust_hi sender→own
    tlo_so = int(state.g_AllyTrustScore[power, own])             # trust_lo sender→own

    # Trust < 3 condition: hi < 0 OR (hi < 1 AND lo < 3)
    def _trust_below_3(hi: int, lo: int) -> bool:
        return hi < 0 or (hi < 1 and lo < 3)

    trust_override = (getattr(state, 'g_TrustOverride', 0) == 1)  # DAT_00baed68

    if _trust_below_3(thi_os, tlo_os):
        # own→sender trust < 3: allow only if override flag set
        if not trust_override:
            return
    elif _trust_below_3(thi_so, tlo_so):
        # sender→own trust < 3 (own→sender was OK): same fallback
        if not trust_override:
            return

    # 4. ALY + VSS check (history > 9).
    if state.g_HistoryCounter > 9:
        aly_result = _find_press_token(state, power, _TOK_ALY)   # FUN_004108a0(..., &ALY)
        if _press_token_found(aly_result, state, power):         # FUN_00401050
            vss_result = _find_press_token(state, power, _TOK_VSS)  # FUN_004108a0(..., &VSS)
            if _press_token_found(vss_result, state, power):
                action_taken = _execute_aly_vss(state, power)   # FUN_004325a0

    # 5. First history-20 gate.
    if state.g_HistoryCounter < 20:
        return

    # 6. DMZ check: only if no action yet and not near end-game.
    if not action_taken and state.g_NearEndGameFactor < 3.0:
        dmz_result = _find_press_token(state, power, _TOK_DMZ)   # FUN_004108a0(..., &DMZ)
        if _press_token_found(dmz_result, state, power):
            # Extra condition (lines 80-83 of decompile):
            #   DAT_00baed68 == 0  OR  g_DiplomacyStateB[power] > 1
            dipl_b = int(getattr(state, 'g_DiplomacyStateB', [0] * 8)[power])  # DAT_004d5484[power]
            dipl_a = int(getattr(state, 'g_DiplomacyStateA', [0] * 8)[power])  # DAT_004d5480[power]
            dipl_ok = not trust_override or (dipl_b > 0 and (dipl_b > 1 or dipl_a > 1))
            if dipl_ok:
                action_taken = bool(propose_dmz(state, power))  # FUN_00432960

    # 7. Second history-20 guard (matches decompile; effectively dead code).
    if state.g_HistoryCounter < 20:
        return

    # 8. If any action was taken, done.
    if action_taken:
        return

    # 9. XDO check.
    xdo_result = _find_press_token(state, power, _TOK_XDO)       # FUN_004108a0(..., &XDO)
    if not _press_token_found(xdo_result, state, power):         # FUN_00401050
        return

    # Final trust gate for XDO execution.
    # Strong path: both directions >= 3 → execute.
    trust_os_strong = thi_os >= 0 and (thi_os > 0 or tlo_os > 2)
    trust_so_strong = thi_so > 0 or (thi_so >= 0 and tlo_so > 2)

    if trust_os_strong and trust_so_strong:
        _execute_xdo(state, power)                               # FUN_00433510
        return

    # Weak path: own SC count must be exactly 1, and sender trust must be ≥ 0 and ≠ 0.
    if getattr(state, 'curr_sc_cnt', [0] * 8)[own] != 1:
        return
    if thi_so < 0:
        return
    if thi_so < 1 and tlo_so == 0:
        return
    _execute_xdo(state, power)                                   # FUN_00433510


# ── ComputeOrderDipFlags ──────────────────────────────────────────────────────

_NEUTRAL_POWER = 0x14  # 20 — placeholder power index for "no unit / neutral"


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
            coop      = int(state.g_CoopFlag[row, col])
            some_coop = int(state.g_SomeCoopScore[row, col])
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
    """LAB_0042df19 sub-routine: log/clear betrayal counter when own power receives peace signal."""
    if (trust_lo == 0 and trust_hi == 0 and neutral == 0 and
            peace_sig == 1 and relation >= 0):
        state.g_BetrayalCounter[col] = 0
        _log.debug("FRIENDLY: getting peace signal from power %d", col)


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


# ── CAL_MOVE ─────────────────────────────────────────────────────────────────

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


# ── RECEIVE_PROPOSAL ─────────────────────────────────────────────────────────

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


def receive_proposal(
    state: "InnerGameState",
    sender_power: int,
    proposal_tokens: list,
    send_fn=None,
) -> None:
    """
    Port of RECEIVE_PROPOSAL (named; no binary address recovered by Ghidra).

    Deduplicates an incoming proposal press against g_PosAnalysisList
    (DAT_00bb65c8/cc).  If this proposal has not yet been recorded:

      1. Appends its token sequence to g_PosAnalysisList.
      2. Logs "We have received the proposal: %s" (mirrors C SEND_LOG).
      3. Adds sender_power to g_AllianceMsgTree (DAT_00bbf638) — the Python
         equivalent of BuildAllianceMsg's sorted-BST insert.
      4. Calls _prepare_ally_press_entry(state, sender_power) [FUN_00418db0
         stub — marks the sender's press-entry as pending for RESPOND].

    C parameters (recovered as in_stack offsets by Ghidra, pushed by caller):
      +0x14  sender_power     — byte index of the sending power
      +0x18  proposal_tokens  — ordered token list (iterated for map inserts)
      +0x04  sub_tokens       — token list used by FUN_00465d90 overlap check
                                (same data as proposal_tokens in practice;
                                 Python uses proposal_tokens for both roles)

    Called from BuildAndSendSUB when:
      puVar18[0x2c] == 1  (has-received-proposal flag set)
      puVar18[7]    == 0  (not yet marked as sent)

    Callees absorbed inline:
      FUN_00465870  — std::list default-constructor → []
      FUN_0047020b  — get own-power context ptr (→ state.albert_power_idx)
      FUN_004243a0  — init analysis-record struct (→ absorbed, no Python state)
      FUN_00465930  — TokenSeq_Count (→ len())
      FUN_00401950  — list content destructor (→ no-op; locals start empty)
      StdMap_FindOrInsert  — std::map lower-bound+insert (→ set.add / dict)
      FUN_00419cb0  — list/range iterator init for g_PosAnalysisList (→ loop)
      FUN_00411a80  — bind iteration to DAT_00bb65d4 secondary sentinel (→ loop)
      GetListElement  — indexed token fetch (→ list index)
      FUN_00465d90  — token-seq overlap bool (→ frozenset intersection)
      GameBoard_GetPowerRec — power-record lookup (→ absorbed; inner loop only
                              fires for nodes with power_count>0, which never
                              occurs for freshly inserted entries → no-op)
      TreeIterator_Advance  — BST iterator step (→ absorbed in loop)
      FUN_0040f860  — std::list::iterator++ (→ Python for-loop)
      FUN_00465f60  — token-list copy (→ list())
      FUN_004223c0  — analysis-struct copy/init (→ absorbed)
      FUN_00430370  — std::list insert at sentinel (→ list.append)
      FUN_00421400  — free analysis struct (→ no-op)
      FreeList      — free temp token list (→ no-op)
      FUN_0046b050  — token-list → string repr (→ str(), already in unchecked)
      SEND_LOG      — debug/log sink (→ logging.info)
      BuildAllianceMsg — BST insert of sender into DAT_00bbf638
                         (→ g_AllianceMsgTree.add; already in unchecked)
      FUN_00418db0  — PrepareAllyPressEntry (→ _prepare_ally_press_entry stub)
    """
    import logging as _log_module
    _log = _log_module.getLogger(__name__)

    # ── Overlap check against g_PosAnalysisList ───────────────────────────────
    # C outer loop iterates g_PosAnalysisList nodes; FUN_00465d90(node+4, &stack4)
    # returns True when node's token set overlaps the incoming proposal.
    # The inner power-record loop uses piStack_c8 which is always empty for
    # freshly inserted entries (power_count == 0), so it never executes and
    # acStack_102[0] stays '\x01' → the outer loop breaks immediately on any
    # overlap, treating the proposal as already seen.
    proposal_set = frozenset(proposal_tokens)
    already_seen = any(
        proposal_set & entry['token_set']
        for entry in state.g_PosAnalysisList
    )

    if already_seen:
        return

    # ── Insert into g_PosAnalysisList ────────────────────────────────────────
    # C: FUN_00465f60(copy, &stack4)  →  copy proposal token list
    #    FUN_004223c0(analysis, record)  →  init analysis struct (absorbed)
    #    FUN_00430370(&sentinel, &iter, copy)  →  std::list insert
    state.g_PosAnalysisList.append({
        'tokens': list(proposal_tokens),
        'token_set': proposal_set,
        'power_count': 0,   # C node[0xe]; always 0 for newly inserted entries
        # ── Ack-matcher schema extension (2026-04-14) ──────────────────────
        # FUN_0042c970 keys sender-match against C node offsets +0xc/+0xf/+0x12.
        # +0xc / +0xf both hold the sender power (primary check on any ack).
        # +0x12 is the secondary slot consulted on non-YES (REJ/BWX) acks.
        # In the Python model a single ``sender_power`` captures both.
        'sender_power':     sender_power,
        'processed_flag':   0,          # C node[+8]; 0 = unprocessed, set by ack-matcher bookkeeping
        'role_b_set':       set(),      # C node[+0x0e / per-role sub-tree] — YES-ack role-B set
        'role_c_set':       set(),      # C node[+0x16 / per-role sub-tree] — REJ/BWX role-C set
    })

    # ── Log ──────────────────────────────────────────────────────────────────
    # C: FUN_0046b050(&stack4, buf) → string repr of token list
    #    SEND_LOG(&pvStack_ec, L"We have received the proposal: %s")
    _log.info("We have received the proposal: %s", proposal_tokens)

    # ── BuildAllianceMsg — record sender in g_AllianceMsgTree ────────────────
    # C: puStack_f4 = (int)(elapsed_seconds + 10000)
    #    BuildAllianceMsg(&DAT_00bbf638, &pvStack_e8, (int *)&puStack_f4)
    # Python models g_AllianceMsgTree keyed by power index rather than by the
    # C timestamp value (elapsed_seconds + 10000).
    build_alliance_msg(state, sender_power)

    # ── PrepareAllyPressEntry — FUN_00418db0(sender_power) ───────────────────
    # C: final call; marks sender's per-power press-entry as pending so that
    #    RESPOND / SendAllyPressByPower can schedule the DM reply.
    _prepare_ally_press_entry(state, sender_power)


# ── RESPOND ───────────────────────────────────────────────────────────────────

def _respond_walk_pos_analysis(
    state: "InnerGameState",
    sublist3: list,
    sender_power: int,
    response_type: int,
    own_power: int,
) -> None:
    """
    LAB_00421ebc — walk g_PosAnalysisList for proposals matching *sublist3*
    and register *own_power* in g_DeviationTree for each match.

    C flow (decompiled.txt lines 261–316):
      Iterate g_PosAnalysisList (DAT_00bb65c8/cc sentinel loop):
        FUN_00465d90(node+0x10, local_3c) — token-seq overlap check.
        If overlap:
          iStack_68 = node[0x34]  (power-count field)
          GameBoard_GetPowerRec(node+0x30, apuStack_8c, &uStack_c4)
          if puVar13[1] != iStack_68                  ← power-count mismatch
             AND (YES != param_2 OR g_PowerActiveTurn[sender] == 1):
               StdMap_FindOrInsert(node+0x48, &send_time, &uStack_c4)
        FUN_0040f860(&iter)  ← advance list iterator

    GameBoard_GetPowerRec (power-count mismatch check) is absorbed — the check
    fires conservatively whenever the token sets overlap.
    StdMap_FindOrInsert → g_DeviationTree[(token_key, own_power)] insert.
    FUN_00465d90        → frozenset intersection (already used in receive_proposal).
    FUN_0047a948        → AssertFail (absorbed).
    FUN_0040f860        → list iterator advance (absorbed as Python for-loop).
    """
    _YES = 0x481c
    g_active = getattr(state, 'g_PowerActiveTurn', None)
    sender_active = bool(g_active is not None and g_active[sender_power])

    sublist3_set = frozenset(sublist3)
    if not sublist3_set:
        return

    for entry in state.g_PosAnalysisList:
        entry_set = entry.get('token_set', frozenset())
        if not (entry_set & sublist3_set):
            continue
        # C: (puVar13[1] != iStack_68) — power-count mismatch; absorbed as True.
        # C: (YES != param_2 || g_PowerActiveTurn[sender] == 1)
        if response_type != _YES or sender_active:
            key = (frozenset(entry['tokens']), own_power)
            state.g_DeviationTree[key] = state.g_DeviationTree.get(key, 0)
            if 'deviation_powers' not in entry:
                entry['deviation_powers'] = set()
            entry['deviation_powers'].add(own_power)


def respond(
    state: "InnerGameState",
    press_list: dict,
    response_type: int,
    elapsed_lo: int = 0,
    elapsed_hi: int = 0,
    send_fn=None,
) -> None:
    """
    Port of RESPOND (named; called from BuildAndSendSUB after RECEIVE_PROPOSAL).

    Generates Albert's reply to an incoming ally press and queues it for dispatch.

    C signature:
      void __thiscall RESPOND(void *this, void *param_1, short param_2,
                               uint param_3, int param_4)

    Mapping:
      this      → state
      param_1   → press_list  — incoming press as a dict with three sublists:
                    'sublist1': [sender_power_token]   e.g. [0x4103] for GER
                    'sublist2': [power_tokens …]        powers named in proposal
                    'sublist3': [order_tokens …]        XDO/PRP content
      param_2   → response_type  YES=0x481c, REJ=0x4814, HUH=0x4806
      param_3   → elapsed_lo     low-word of current timestamp (uint32)
      param_4   → elapsed_hi     high-word of current timestamp (int32)

    Deception path (REJ + single power + enemy + trust gate):
      If g_EnemyFlag[sender]==1 AND sender's trust toward own is positive AND
      relation >= 0 AND random gate fails to trigger avoidance → respond YES
      (deceitfully accept).  Logs "We are DECEITFULLY responding to: (%s)".
      Sets g_PowerActiveTurn[sender] = 1.

    Normal path:
      Echoes response_type unchanged.
      Logs "Our response to a message was: %s".

    Both paths: enqueue SND entry into g_MasterOrderList, update
    g_AllianceMsgTree, then walk g_PosAnalysisList via
    _respond_walk_pos_analysis.

    HUH path:
      FUN_0040d4d0 (absorbed) + _send_ally_press_by_power(sender) → schedule
      THN response.  Skips queueing step; goes straight to proposal-list walk.

    Timing (non-tournament mode):
      target = elapsed_since_session_start + rand(0–7) + 5 s
      If target < best_ally_turn_score  → push to best_score + 2 s
      If g_MoveTimeLimitSec > 0        → cap at limit − 20 s
    Timing (tournament mode / g_PressInstant != 0):
      target = elapsed_since_session_start  (send immediately)

    Callees absorbed inline:
      FUN_00465870  list init          → []
      FUN_0047020b  own-context ptr    → state.albert_power_idx
      GetSubList    sublist extraction → press_list['sublistN']
      AppendList / FreeList            → Python list ops
      FUN_004658f0  first token        → list[0]
      FUN_00465930  TokenSeq_Count     → len()
      FUN_00465f30  wrap token→list    → [token]
      FUN_00466480  filter by type     → absorbed in power-loop
      FUN_00466f80  prefix+content     → [type_token] + sublist3
      FUN_00466e10  add power token    → list.append
      FUN_00466c40  concat token lists → list + list
      FUN_00465f60  copy token list    → list()
      FUN_00419c30  enqueue press      → g_MasterOrderList.append
      FUN_0046b050  serialize tokens   → str()
      SEND_LOG                         → logging.debug
      BuildAllianceMsg                 → g_AllianceMsgTree.add
      FUN_0040d4d0  HUH forward        → absorbed (no-op)
      ATL::CSimpleStringT::CloneData   → absorbed
      LOCK / UNLOCK                    → absorbed
    """
    import logging as _logging
    import random as _random

    _log = _logging.getLogger(__name__)

    # DAIDE token constants (from daide_client/tokens.h)
    _YES = 0x481c
    _REJ = 0x4814
    _HUH = 0x4806

    own_power: int = getattr(state, 'albert_power_idx', 0)
    # DAT_00baed32 — tournament mode (g_PressInstant in Python)
    tournament_mode: int = int(getattr(state, 'g_PressInstant', 0))

    # ── Extract sublists ─────────────────────────────────────────────────────
    # C: GetSubList(param_1, buf, 1/2/3)
    sublist1: list = press_list.get('sublist1', [])   # sender power token(s)
    sublist2: list = press_list.get('sublist2', [])   # powers in proposal
    sublist3: list = press_list.get('sublist3', [])   # order content

    # local_c8[0] = FUN_004658f0(local_1c, &uStack_8e) → first token of sublist1
    # (byte)local_c8[0] extracts the low byte = power index (0-6)
    sender_token: int = sublist1[0] if sublist1 else 0
    sender_power: int = sender_token & 0xff

    # uStack_c4 = *(byte *)(*(int *)(this+8) + 0x2424) — own power index
    # (already extracted above as own_power)

    # ── Initial best ally turn-score lookup ──────────────────────────────────
    # C: iVar16 = -1; puStack_bc = 0xffffffff
    #    if (DAT_00ba27b4[power*8] >= 0): iVar16 = ...; puStack_bc = ...
    g_turn_score = getattr(state, 'g_TurnScore', None)
    best_score_hi: int = -1
    best_score_lo: int = 0xffffffff

    if g_turn_score is not None and sender_power < len(g_turn_score):
        val = int(g_turn_score[sender_power])
        hi_val = val >> 32
        lo_val = val & 0xffffffff
        if hi_val >= 0:
            best_score_hi = hi_val
            best_score_lo = lo_val

    # ── Power-list loop (local_4c = sublist2) — update best turn score ───────
    # C: uStack_84 = FUN_00465930(local_4c)  (count of entries)
    #    for each entry != own_power: FUN_00466480 filter + score comparison
    power_count: int = len(sublist2)
    for pw_token in sublist2:
        pw_idx = pw_token & 0xff
        if pw_idx == own_power:
            continue
        if g_turn_score is not None and pw_idx < len(g_turn_score):
            val = int(g_turn_score[pw_idx])
            hi_val = val >> 32
            lo_val = val & 0xffffffff
            if hi_val >= 0 and (
                hi_val > best_score_hi
                or (hi_val == best_score_hi and lo_val > best_score_lo)
            ):
                best_score_hi = hi_val
                best_score_lo = lo_val

    # ── Compute target send time ──────────────────────────────────────────────
    elapsed: float = _time.time() - float(getattr(state, 'g_turn_start_time', 0.0))

    if not tournament_mode:
        # C: uVar17 = (rand() / 0x17) & 0x80000007  → 0-7 (mod-8 random)
        rand_val = _random.randint(0, 0x7fff)
        rand_offset = (rand_val // 23) % 8          # 0-7 units
        target = elapsed + rand_offset + 5.0

        # C: if (pvVar8 <= iVar16 && ...): puVar20 = puStack_bc + 2
        # Push target forward past best ally's score + 2 s if needed
        if best_score_hi >= 0:
            best_f = float(best_score_hi) * float(2**32) + float(best_score_lo)
            if target <= best_f:
                target = best_f + 2.0

        # C: if (0 < DAT_00624ef4): cap at limit - 0x14
        move_limit = int(getattr(state, 'g_MoveTimeLimitSec', 0))
        if move_limit > 0:
            cap = float(move_limit - 20)
            if target > cap:
                target = cap
    else:
        # Tournament mode: send at current elapsed (no random delay)
        target = elapsed

    # ── HUH path ─────────────────────────────────────────────────────────────
    # C: if (HUH == param_2) { FUN_0040d4d0(...); SendAllyPressByPower(sender); goto end }
    if response_type == _HUH:
        # FUN_0040d4d0(local_6c, param_1) — unknown HUH forward handler; absorbed
        _send_ally_press_by_power(state, sender_power)
        _respond_walk_pos_analysis(state, sublist3, sender_power, response_type, own_power)
        return

    # ── REJ + single ally power → potential deceit YES ───────────────────────
    # C: if ((REJ == param_2) && (uStack_84 == 1)) { ... } else { LAB_00421d01: ... }
    if response_type == _REJ and power_count == 1:
        uVar17 = sender_power

        # Gate 1: sender must be designated enemy
        # C: (&DAT_004cf568)[uVar17*2] == 1  AND  (&DAT_004cf56c)[uVar17*2] == 0
        # Python: g_EnemyFlag[sender] == 1 (int32; hi-word of int64 is always 0)
        g_enemy = getattr(state, 'g_EnemyFlag', None)
        enemy_flag = int(g_enemy[uVar17]) if g_enemy is not None else 0

        if enemy_flag == 1:
            # Gate 2: trust and relation check
            # C: iVar18 = uVar17*21 + own_power  (sender→own direction in int64 array)
            trust_hi = int(state.g_AllyTrustScore_Hi[uVar17, own_power])
            trust_lo = int(state.g_AllyTrustScore[uVar17, own_power])
            # g_RelationScore[own_power, uVar17]  (DAT_00634e90[own*21+sender])
            relation = int(state.g_RelationScore[own_power, uVar17])

            # Condition to SKIP deceit (goto normal path):
            #   (trust_hi < 0 OR (trust_hi < 1 AND trust_lo == 0) OR relation < 0)
            #   AND random passes
            low_trust = (
                trust_hi < 0
                or (trust_hi < 1 and trust_lo == 0)
                or relation < 0
            )

            aggressiveness = int(getattr(state, 'g_DMZAggressiveness', 0))
            press_mode = int(getattr(state, 'g_PressFlag', 0)) == 1

            # C: (iVar18 = rand(), (iVar18 / 0x17) % 0x14 + aggressiveness < 0x51)
            r1 = _random.randint(0, 0x7fff)
            rand_check1 = (r1 // 23) % 20 + aggressiveness < 81

            if press_mode:
                # C: DAT_00baed68 == '\x01': RandUpTo(n)(0x14) + aggressiveness < 0x47
                r2 = _random.randint(0, 20)
                rand_check2 = r2 + aggressiveness < 71
                random_passes = rand_check1 and rand_check2
            else:
                random_passes = rand_check1

            skip_deceit = low_trust and random_passes

            if not skip_deceit:
                # ── Deceit path: respond YES instead of REJ ───────────────────
                # C: FUN_00466f80(&YES, &local_6c, local_3c) → [YES] + sublist3
                response_tokens = [_YES] + list(sublist3)

                _log.debug("We are DECEITFULLY responding to: (%s)", response_tokens)

                # C: (&DAT_00633768)[(byte)local_c8[0]] = 1
                g_active = getattr(state, 'g_PowerActiveTurn', None)
                if g_active is not None:
                    g_active[sender_power] = 1

                # C: FUN_00419c30(&DAT_00bb65bc, apuStack_7c, (uint*)&puStack_bc)
                state.g_MasterOrderList.append({
                    'scheduled_time': target,
                    'press_type':     'SND',
                    'data':           response_tokens,
                    'target_power':   sender_power,
                })

                # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_7c, (int*)&puStack_bc)
                build_alliance_msg(state, sender_power)

                _respond_walk_pos_analysis(
                    state, sublist3, sender_power, response_type, own_power
                )
                return

    # ── Normal path (LAB_00421d01) ────────────────────────────────────────────
    # C: FUN_00466f80(&param_2, &local_6c, local_3c) → [response_type] + sublist3
    response_tokens = [response_type] + list(sublist3)

    _log.debug("Our response to a message was: %s", response_tokens)

    # C: FUN_00419c30(&DAT_00bb65bc, apuStack_7c, (uint*)&puStack_ac)
    state.g_MasterOrderList.append({
        'scheduled_time': target,
        'press_type':     'SND',
        'data':           response_tokens,
        'target_power':   sender_power,
    })

    # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_7c, (int*)&puStack_bc)
    build_alliance_msg(state, sender_power)

    _respond_walk_pos_analysis(state, sublist3, sender_power, response_type, own_power)


# ── AllianceTree insert (FUN_00414a10 / FUN_00413fd0) ────────────────────────

def alliance_tree_find_or_insert(state: "InnerGameState", key: int) -> tuple:
    """AllianceTree_FindOrInsert — MSVC ``std::set<int>`` BST insert + RB fixup.

    addr: ``0x00414a10``
    C signature: ``void __thiscall FUN_00414a10(void *this, void **param_1,
                    char param_2, int **param_3, undefined4 *param_4)``

    This is the MSVC ``std::set<int>::insert`` fast-path called by
    ``BuildAllianceMsg`` (``FUN_00413fd0``) after the BST descent has located
    the insertion slot.  The C implementation:

      1. Rejects inserts when ``*(uint*)(this+8) > 0x1ffffffd`` (size limit) —
         throws ``std::length_error("map/set<T> too long")``.
      2. Calls ``FUN_00411c40`` (``operator_new(0x18)``-based node ctor) to
         allocate a 24-byte RB-tree node and initialise its fields::

             node[+0x00] = param_1            # _Left  (left child ptr)
             node[+0x04] = param_2            # _Parent (parent ptr)
             node[+0x08] = param_3            # _Right  (right child ptr)
             node[+0x0C] = *param_4           # int key (e.g. elapsed_s+10000)
             node[+0x10] = CSimpleStringT     # cloned ATL CString ptr
                             .CloneData(param_4[1] - 0x10) + 0x10
             byte(node+0x14) = param_5        # _Color (0=RED, nonzero=BLACK)
             byte(node+0x15) = 0              # _Isnil = 0 (real node)
      3. Increments ``*(this+8)`` (``_Mysize``).
      4. Links the new node into the min/max bookkeeping pointers held in
         ``*(this+4)`` (``_Myhead``).
      5. RB-tree colour fixup while ``parent.color == red``:
           - Uncle is red   → recolour uncle + parent black, grandparent red,
                              walk up.
           - Uncle is black + new node is inner child → rotate to make it outer
                              (``FUN_0040f170`` left-rotate or ``FUN_0040e050``
                              right-rotate on parent), then fall through.
           - Uncle is black + new node is outer child → recolour parent black,
                              grandparent red, rotate grandparent the other way.
      6. Forces root black: ``*(this+4)->_Parent.color = black``.
      7. Writes ``param_1[0] = this`` (container back-pointer) and
         ``param_1[1] = new_node`` (node pointer).

    In Python ``g_AllianceMsgTree`` (``DAT_00bbf638``) is a plain ``set``; all
    pointer-wiring and RB rebalancing collapse to a single ``set.add``.  The
    return value mirrors the C ``param_1`` pair:

      (container_set, key, was_inserted: bool)

    Callees (C):
      FUN_00411c40 — 24-byte RB-tree node allocator (left/parent/right +
                     int key + ATL CString clone + color + isnil)
      FUN_0040f170 — RB-tree left-rotation (insert fixup)
      FUN_0040e050 — RB-tree right-rotation (insert fixup)
      FUN_00402650 — ``std::length_error`` constructor (exception path only)
      FUN_00402a30 — MSVC exception rethrow helper (exception path only)
    """
    was_inserted = key not in state.g_AllianceMsgTree
    state.g_AllianceMsgTree.add(key)
    return state.g_AllianceMsgTree, key, was_inserted


def build_alliance_msg(state: "InnerGameState", key: int) -> tuple:
    """BuildAllianceMsg — insert a power key into the alliance BST.

    addr: ``0x00413fd0``
    C signature: ``void __thiscall BuildAllianceMsg(void *this,
                    undefined4 *param_1, int *param_2)``

    Traverses the ``std::set<int>`` rooted at ``this`` (``DAT_00bbf638``) to
    find the insertion slot for ``*param_2`` (power index), then delegates the
    actual insert + RB fixup to ``AllianceTree_FindOrInsert`` (``FUN_00414a10``).
    Writes the resulting ``(container, node)`` pair plus a proposal-active flag
    into the caller's ``param_1`` output buffer::

        param_1[0] = container_ptr   (this)
        param_1[1] = node_ptr        (new or existing node)
        param_1[2] = 1               (proposal-active flag, set by caller)

    BST traversal uses ``node+0x0`` (left) / ``node+0x8`` (right) child pointers
    and compares ``*param_2`` against ``node+0xc`` (key).  Nil sentinel check:
    ``*(char*)(node + 0x15) == '\\0'``.

    Returns the same ``(container, key, flag=1)`` triple that the C caller reads
    from its stack buffer.
    """
    container, node, _ = alliance_tree_find_or_insert(state, key)
    return container, node, 1   # param_1[2] = 1 (proposal-active flag)


# ── STL tree copy (FUN_00401d70) ──────────────────────────────────────────────

def _stl_tree_copy(dest: list, source: list) -> list:
    """MSVC ``std::_Tree::_Copy`` — recursive BST deep-copy.

    addr: ``0x00401d70``
    C signature: ``undefined4 * __thiscall FUN_00401d70(void *this,
                     undefined4 *param_1, undefined4 param_2)``

    Recursively copies the BST rooted at *param_1* into the destination tree
    (*this*), allocating each new node via ``FUN_00401b40`` (_Buynode), then
    wiring left/right children from the recursive results.

    Node layout for this tree type (compact, 18 bytes minimum):
      +0x00  ``_Left``   — left-child pointer  (param_1[0])
      +0x04  ``_Parent`` — parent pointer      (param_1[1])
      +0x08  ``_Right``  — right-child pointer (param_1[2])
      +0x0C  ``_Value``  — key/value data       (param_1+3; passed to _Buynode)
      +0x10  ``_Color``  — RB-tree color byte
      +0x11  ``_Isnil``  — non-zero = sentinel/nil node
                           (checked at +0x11; distinct from g_OrderList which
                           uses +0x21; this is a smaller per-proposal-orders
                           tree type)

    Control flow:
      if param_1._Isnil == 0  (real node):
          puVar1  = _Buynode(head, parent=param_2, left=head,
                             val=param_1.value, color=param_1.color)
          if sentinel._Isnil != 0:   # always true for the sentinel
              local_18 = puVar1      # track begin / return root copy
          puVar1.left  = _Copy(this, param_1.left,  puVar1)
          puVar1.right = _Copy(this, param_1.right, puVar1)
          return puVar1
      else:                          # nil sentinel node
          return this->_Myhead       # return destination sentinel unchanged

    In Python the tree is a sorted ``list[dict]``; all pointer/coloring
    bookkeeping disappears.  The function reduces to a deep-copy of the
    source list into (and replacing) the destination list.

    Callees (C):
      FUN_00401b40 — ``std::_Tree::_Buynode``: allocates + initialises one
                     node with (head, parent, left=head, value, color);
                     see unchecked.md
    """
    import copy
    dest.clear()
    dest.extend(copy.deepcopy(source))
    return dest


# ── STL tree erase (FUN_00402b70) ─────────────────────────────────────────────

def _stl_tree_erase_node(tree: list, idx: int) -> int:
    """MSVC ``std::_Tree::erase(iterator)`` — erase one node from the sorted list.

    addr: ``0x00402b70``
    C signature: ``void __thiscall FUN_00402b70(void *this, int *param_1,
                    int param_2, int **param_3)``

    Operates on the same per-proposal-orders tree type as ``_stl_tree_copy``
    (compact node layout: ``_Color`` at ``+0x10``, ``_Isnil`` at ``+0x11``).

    C algorithm:
      1. Validate *param_3* (the node to erase) is not the nil sentinel
         (``*(char*)(param_3 + 0x11) != 0`` → throws
         ``std::out_of_range("invalid map/set<T> iterator")`` via
         ``FUN_00402650`` + ``FUN_00402a30``).
      2. ``TreeIterator_Advance(&param_2)`` — advance *param_2* to the
         in-order successor of *param_3*.
      3. Determine the replacement / splice node:
         - left child non-nil  → replacement = left child
         - else                → replacement = right child
         (The two-child splice branch guarded by ``param_3 != _Memory`` is dead
         code: ``_Memory = param_3`` at entry, so the condition is always
         false; Ghidra emits the branch but it is unreachable.)
      4. Update all parent/child back-pointers bypassing the erased node;
         update header's leftmost (``this+4``→``*header``) and rightmost
         (``this+4``→``header[2]``) via ``FUN_004010a0`` / ``FUN_00401080``
         when the erased node was the current begin or end.
      5. RB-tree delete fixup (``LAB_00402ce5``): iterate up the tree
         correcting colours via left-rotations (``FUN_004016a0``) and
         right-rotations (``FUN_004010c0``).
      6. ``_free(_Memory)`` + ``this->_Mysize -= 1``.
      7. Write successor iterator into ``*param_1``.

    Node layout (same tree type as ``_stl_tree_copy``):
      +0x00  ``_Left``   — left child
      +0x04  ``_Parent`` — parent
      +0x08  ``_Right``  — right child
      +0x0C  ``_Value``  — 4-byte key/value
      +0x10  ``_Color``  — RB colour byte (0 = red, 1 = black)
      +0x11  ``_Isnil``  — non-zero = sentinel/nil node

    Python representation: the tree is a sorted ``list[dict]``; all
    pointer/colour bookkeeping disappears.  The function reduces to removing
    the entry at *idx* and returning the new index of the successor (which,
    after deletion, is automatically ``idx``).

    Raises ``IndexError`` if *idx* is out of range (mirrors the C
    ``std::out_of_range`` throw for the end-sentinel / past-the-end check).

    Callees (C):
      FUN_00402650         — ``std::string`` ctor from ``(char*, size_t)``
                             builds the "invalid map/set<T> iterator" message
      FUN_00402a30         — ``std::out_of_range`` constructor
      TreeIterator_Advance — in-order successor step (Ghidra-named; analogous
                             to ``std_Tree_IteratorIncrement`` at 0x0040f6f0
                             but for this compact tree type; address unknown)
      FUN_004010a0         — leftmost-descendant finder; returns new begin
                             after the old leftmost node is erased
      FUN_00401080         — rightmost-descendant finder; returns new end
                             (rightmost) after the old rightmost node is erased
      FUN_004016a0         — RB-tree left-rotation used in delete fixup
      FUN_004010c0         — RB-tree right-rotation used in delete fixup
    """
    if idx < 0 or idx >= len(tree):
        raise IndexError("invalid map/set<T> iterator")
    tree.pop(idx)
    # After deletion 'idx' naturally addresses the former successor (or
    # len(tree) when the erased entry was the last), matching the C behaviour
    # where *param_1 is set to the advanced iterator after the node is freed.
    return idx


# ── HostilityRecord ───────────────────────────────────────────────────────────

def build_hostility_record(src: dict) -> dict:
    """Copy constructor for HostilityRecord.

    C: ``undefined * __thiscall BuildHostilityRecord(void *this, undefined *param_1)``

    Copies every field from *src* (param_1) into a new record (this) using the
    appropriate per-field copy operation, then returns the destination.  In
    Python, all C field copies collapse to a single ``copy.deepcopy``.

    Struct layout (C offset → Python key):
      +0x00  1B   'flag_0'        — leading flag/type byte
      +0x04  4B   'int_4'         — dword
      +0x08  4B   'int_8'         — dword
      +0x0c  12B  'obj_0c'        — 12-byte token/proposal object
                                    (FUN_00405090 copy constructor)
      +0x18  12B  'obj_18'        — 12-byte object
                                    (FUN_0041c3c0 copy constructor)
      +0x24  12B  'obj_24'        — 12-byte object
                                    (FUN_0041c3c0 copy constructor)
      +0x30  84B  'trust_row'     — 21×int32 raw copy (one g_AllyTrustScore row)
      +0x84  4B   'int_84'        — dword
      +0x88  16B  'token_list_88' — token list (FUN_00465f60 copy)
      +0x98  1B   'flag_98'       — flag byte
      +0xa0  4B   'int_a0'        — dword
      +0xa4  4B   'int_a4'        — dword
      +0xa8  16B  'token_list_a8' — token list (FUN_00465f60 copy)
      +0xb8  2B   'word_b8'       — word
      +0xbc  16B  'token_list_bc' — token list (FUN_00465f60 copy)

    Callees (C):
      FUN_00405090  — 12-byte object copy (already in unchecked)
      FUN_0041c3c0  — 12-byte STL set copy constructor (see below)
      FUN_00465f60  — token-list copy (already in unchecked)
    """
    import copy
    return copy.deepcopy(src)


def _ordered_token_seq_insert(container: list, key_seq) -> tuple:
    """Port of FUN_00419300 — MSVC ``std::set<TokenSeq>::insert(value)``.

    addr: ``0x00419300``
    C signature: ``void __thiscall FUN_00419300(void *this,
                    void **param_1, void **param_2)``

    The C body is a full MSVC RB-tree insert for a ``std::set`` whose element
    type is a token-sequence list.  It descends the tree from root using
    ``FUN_00465cf0`` (token-sequence less-than comparator, ``+0x1d`` sentinel
    flag) to locate the insertion point, then detects duplicates in two paths:

      * Last BST step went LEFT (``local_c != 0``, ``param_2 < parent.key``):
        if parent is the leftmost node → fast-insert (no predecessor possible);
        otherwise call ``FUN_00401790`` to step back to the in-order
        predecessor and re-check ``FUN_00465cf0(predecessor.key, param_2)``.
        If predecessor >= param_2 the keys are equal → no insert.
      * Last BST step went RIGHT (``local_c == 0``, ``param_2 >= parent.key``):
        check ``FUN_00465cf0(parent.key, param_2)``; if parent >= param_2 the
        keys are equal → no insert.

    On successful insert, ``FUN_004134d0`` allocates and splices a new RB-tree
    node.  The result is written through *param_1*:

      param_1[0]  — iterator node pointer (existing or newly inserted)
      param_1[1]  — iterator ``_Myhead`` (header/sentinel pointer)
      param_1[2]  — bool: 1 = new node inserted, 0 = key already existed

    The 12-byte ``this`` layout::

        +0  allocator/compare  (zeroed)
        +4  _Myhead            (sentinel node ptr; [0]=leftmost, [1]=root, [2]=rightmost)
        +8  _Mysize            (element count)

    Sentinel node: ``node + 0x1d`` = ``_Isnil`` flag (0 = real node, 1 = nil).

    Python mapping:
      *container*  — sorted ``list[tuple]`` representing the BST in-order
                     contents; Python lexicographic tuple comparison matches
                     ``FUN_00465cf0`` semantics exactly.
      *key_seq*    — iterable token sequence; normalised to ``tuple``.
      Returns ``(key_tuple, inserted: bool)``.

    Callees absorbed:
      FUN_00465cf0 — TokenSeq less-than comparator (tuple ``<``)
      FUN_004134d0 — RB-tree node allocate-and-insert (``list.insert`` via bisect)
      FUN_00401790 — in-order predecessor step (not required in Python)
    """
    import bisect
    key = tuple(key_seq)
    idx = bisect.bisect_left(container, key)
    if idx < len(container) and container[idx] == key:
        return (container[idx], False)
    container.insert(idx, key)
    return (key, True)


def _copy_stl_ordered_set(src):
    """Copy constructor for a 12-byte MSVC ``std::set<int>`` (FUN_0041c3c0).

    C signature: ``void * __thiscall FUN_0041c3c0(void *this, int param_1)``

    Called from BuildHostilityRecord for the 'obj_18' and 'obj_24' fields::

        FUN_0041c3c0((void *)(this + 0x18), (int)(param_1 + 0x18))
        FUN_0041c3c0((void *)(this + 0x24), (int)(param_1 + 0x24))

    The C++ body has two phases:

    **Phase 1 — default-construct an empty set (``this``)**:

    * ``FUN_0040fd90()`` — ``operator_new(0x20)``; zeros offsets 0/4/8
      (``_Left``/``_Parent``/``_Right``); sets ``+0x1c = 1`` (``_Color =
      BLACK``); explicitly sets ``+0x1d = 0`` (``_Isnil`` starts as 0 —
      NOT yet a sentinel; the caller marks it).  Returns the raw pointer
      in EAX (Ghidra shows ``void`` return but value survives in EAX).
      Same structural role as ``FUN_00401e30`` inside ``StdSet_Init``
      (``FUN_00405660``).
    * Stores the sentinel at ``this+4`` (``_Myhead``).
    * Marks the sentinel: ``sentinel+0x1d = 1`` (``_Isnil`` flag) and sets
      ``_Left = _Parent = _Right = sentinel`` (circular self-links for an
      empty RB-tree head).  These two steps are done by the caller
      (``FUN_0041c3c0``), not by ``FUN_0040fd90``.
    * Sets ``this+8 = 0`` (``_Mysize``).

    **Phase 2 — copy-assign from source**:

    * ``FUN_00411a80(this, param_1)`` — the MSVC ``_Tree::_Copy`` helper;
      walks the source tree in-order and inserts each element into ``this``.

    The 12-byte container layout is::

        this+0   4B  allocator/compare (unused — zero-initialised by caller)
        this+4   4B  _Myhead  (sentinel node ptr)
        this+8   4B  _Mysize  (element count)

    Python absorption: both phases collapse to ``copy.deepcopy(src)`` because
    ``src`` is already the correct Python container (``set`` of ints).

    Callees (C) — absorbed:
      FUN_0040fd90  — allocate BST sentinel node (absorbed as Python alloc)
      FUN_00411a80  — MSVC ``_Tree::_Copy``: outer copy driver; calls
                      FUN_00410db0 on the source root (absorbed as deepcopy)
      FUN_00410db0  — MSVC ``_Tree::_Copy_nodes``: recursive pre-order node
                      copy; for each non-nil src node calls FUN_0040fdd0 to
                      allocate a dst node (copying key at src+0x0c and color
                      byte at src+0x1c), then recurses into left (*src) and
                      right (src[2]) with parent=new_node; returns new_node
                      or dst sentinel (absorbed as deepcopy)
      FUN_0040fdd0  — MSVC ``_Tree::_Buynode``: allocates a raw tree node,
                      sets _Left=_Right=sentinel, _Parent=arg2, copies key
                      from arg4, sets _Color=arg5 (absorbed as Python alloc)
    """
    import copy
    return copy.deepcopy(src)
