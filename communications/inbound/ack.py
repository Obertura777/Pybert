"""ACK-token matching, HUH error strip/replay, and TRY-stance parsing.

Split from communications/inbound.py during the 2026-04 refactor.

Groups the helpers that classify *individual* inbound press tokens from
the server (ack, rejection, busy-wait, huh-error replay, stance queries):

  * ``_ACK_TOK_YES`` / ``_ACK_TOK_REJ`` / ``_ACK_TOK_BWX`` — ack-token codes.
  * ``_STANCE_TOKEN_CODES``                                — TRY-stance vocab.
  * ``ack_matcher``          — decide YES / REJ / BWX for an incoming ack.
  * ``huh_err_strip_replay`` — server returned HUH; strip and replay.
  * ``process_try``          — parse an inbound TRY (stance query).

Module-level deps: ``...state.InnerGameState``;
``..tokens._token_seq_equal`` for ``ack_matcher``.
"""

from ...state import InnerGameState
from ..tokens import (
    _TOK_ALY, _TOK_AND, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_VSS, _TOK_XDO,
    _token_seq_equal,
)


_ACK_TOK_YES = 0x481C
_ACK_TOK_REJ = 0x4814
_ACK_TOK_BWX = 0x4A02
_ACK_TOK_HUH = 0x4806
_ERR_TOK = 0x4902


def ack_matcher(
    state: "InnerGameState",
    sender_power: int,
    ack_tok: int,
    proposal_tokens: "list | None" = None,
) -> int:
    """
    Port of FUN_0042c970 — match a reply against ``g_pos_analysis_list``.

    C arguments: the replied-to proposal (the reply's first sub-list, e.g.
    ``PRP ( ... )``), the replying power byte and the reply token.

    C flow:
      * ``sender != own power`` → SendAllyPressByPower(sender), before the
        walk and whether or not anything matches.
      * For every node (DAT_00bb65c8) whose token list equals the proposal
        (FUN_00465d90) and whose processed byte (node+0x20) is clear, and
        whose participant set (node+0x30) contains the sender:
          - insert the sender into the responded set (node+0x3c) — for every
            reply token;
          - for any token other than YES, also insert the sender into the
            rejection set (node+0x48) and, on first insertion, clear the
            node's clause list (node+0x54);
          - log "We have received a reply" and archive elapsed + 10000.
      * Returns 1 when any node matched.

    The reply is not optional: FUN_00465d90 is false for an empty list, so a
    reply with no proposal body matches nothing.
    """
    import logging as _logging
    import time as _t
    from ..senders import send_ally_press_by_power
    _log = _logging.getLogger(__name__)

    own_power = int(getattr(state, 'albert_power_idx', 0))
    if int(sender_power) != own_power:
        send_ally_press_by_power(state, int(sender_power))

    is_yes = (ack_tok == _ACK_TOK_YES)
    matched = 0

    for entry in getattr(state, 'g_pos_analysis_list', []):
        if not isinstance(entry, dict):
            continue
        if not _token_seq_equal(entry.get('tokens', []), proposal_tokens or []):
            continue
        if entry.get('processed_flag', 0) != 0:
            continue
        if sender_power not in set(entry.get('participant_powers', set())):
            continue

        entry.setdefault('role_b_set', set()).add(sender_power)
        if not is_yes:
            rejected = entry.setdefault('role_c_set', set())
            if sender_power not in rejected:
                rejected.add(sender_power)
                entry['press_entries'] = []

        matched = 1
        state.g_alliance_msg_tree.add(
            int(_t.time() - getattr(state, 'g_turn_start_time', 0.0)) + 10000
        )
        _log.debug(
            "We have received a reply: 0x%x from %d", ack_tok, sender_power,
        )

    return matched


def _strip_err_tokens(tokens: list) -> list:
    """The ERR-removal copy loop of the inbound HUH handler (0x0042cd70).

    C counts the ERR tokens, then copies ``len - count`` tokens, advancing a
    skip counter whenever the token at the *output* index is ERR.  The source
    index is ``output + skips``, so the ERR test lags behind the source once
    one ERR has been skipped; a single ERR is removed exactly, later ones are
    not always.  Reproduced as-is.
    """
    def _is_err(tok) -> bool:
        return tok == _ERR_TOK or (isinstance(tok, str) and tok.upper() == 'ERR')

    tokens = list(tokens)
    out_len = len(tokens) - sum(1 for tok in tokens if _is_err(tok))
    out: list = []
    skips = 0
    for i in range(out_len):
        if _is_err(tokens[i]):
            skips += 1
        out.append(tokens[i + skips])
    return out


def huh_err_strip_replay(
    state: "InnerGameState",
    sender_power: int,
    huh_body_tokens: list,
) -> int:
    """
    Port of HUH (0x0042cd70) — a peer's HUH reply to our press.

    The FRM handler passes the HUH message's first sub-list (``ERR PRP
    ( ... )``).  The handler strips the ERR markers and, when anything is
    left, runs FUN_0042c970 with the reply token HUH.  HUH is not YES, so the
    sender lands in both the responded and the rejection sets of the matching
    proposal: a proposal the peer could not parse counts as rejected.

    Returns the ack-matcher's result, or 0 when nothing survives the strip.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    filtered = _strip_err_tokens(huh_body_tokens)
    _log.debug("message :%s", ' '.join(str(t) for t in filtered))
    if not filtered:
        return 0
    return ack_matcher(
        state, sender_power, _ACK_TOK_HUH, proposal_tokens=filtered,
    )


_STANCE_TOKEN_CODES = {
    'PCE': _TOK_PCE,
    'ALY': _TOK_ALY,
    'VSS': _TOK_VSS,
    'DMZ': _TOK_DMZ,
    'AND': _TOK_AND,
    'ORR': _TOK_ORR,
    'XDO': _TOK_XDO,
    'PRP': 0x4A13,   # utils/tokens.py "4A13":"PRP"
    'YES': 0x481C,   # utils/tokens.py "481C":"YES"
    'REJ': 0x4814,   # utils/tokens.py "4814":"REJ"
    'BWX': 0x4A02,   # utils/tokens.py "4A02":"BWX"
    'NOT': 0x480D,   # utils/tokens.py "480D":"NOT"
    'HUH': 0x4806,   # utils/tokens.py "4806":"HUH"
    'TRY': 0x4A1A,   # utils/tokens.py "4A1A":"TRY"
    'FCT': 0x4A06,   # python-diplomacy daide/tokens.py FCT
    'THK': 0x4A18,   # utils/tokens.py "4A18":"THK"
    'WHY': 0x4A1E,   # utils/tokens.py "4A1E":"WHY"
    'IDK': 0x4A0A,   # utils/tokens.py "4A0A":"IDK"
    'SUG': 0x4A17,   # utils/tokens.py "4A17":"SUG"
    'HOW': 0x4A09,   # utils/tokens.py "4A09":"HOW"
    'QRY': 0x4A14,   # utils/tokens.py "4A14":"QRY"
    'NAR': 0x4A25,   # python-diplomacy daide/tokens.py NAR
    'CCL': 0x4A26,   # DAT_004c6e14 in Albert.exe; python-diplomacy CCL
    'FRM': 0x4802,   # utils/tokens.py "4802":"FRM"
    'SND': 0x4817,   # utils/tokens.py "4817":"SND"
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
