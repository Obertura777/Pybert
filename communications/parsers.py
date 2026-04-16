"""DAIDE XDO / press-content parsers.

Text- and token-level parsers that convert raw DAIDE press content into
structured order candidates consumed by the scoring layer and by
``register_received_press``.  Extracted from ``communications.py`` during
the 2026-04 structural refactor.

Contains:

- ``_extract_top_paren_groups``  — split a parenthesised string into top-level groups
- ``_parse_xdo_candidates``      — parse an XDO press payload into candidate-order dicts
- ``_split_top_level_groups``    — same split but on a flat token list
- ``_parse_unit_triple``         — decode a ``(POWER UNIT_TYPE PROVINCE)`` triple
- ``_parse_destination``         — decode a destination ``(PROVINCE [COAST])``
- ``_parse_xdo_body_to_order``   — full XDO body → (power_idx, order_dict) decode
- ``_DAIDE_TO_ORDER_TYPE_TAG``   — mapping of DAIDE order tokens to tag strings

None of these functions touch ``InnerGameState`` — they are pure parsers.
"""

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


