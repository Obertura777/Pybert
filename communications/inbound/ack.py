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


def ack_matcher(
    state: "InnerGameState",
    sender_power: int,
    ack_tok: int,
    proposal_tokens: "list | None" = None,
) -> int:
    """
    Port of FUN_0042c970 — the ack-matcher that walks ``g_pos_analysis_list``
    (DAT_00bb65c8) looking for an unprocessed received-proposal whose
    sender matches an incoming YES/REJ/BWX ack, then runs role-set
    bookkeeping for each match.

    C semantics (from FRMHandler.md + daide_semantics_notes.md):

      For each node in DAT_00bb65c8 where ``node.processed_flag == 0``:
        * Primary sender-match: sender must occur in the participant map at
          +0xc. The +0xf map is the affirmative role set and +0x12 is the
          rejection/deviation role set.
        * If matched:
            - ``YES`` → StdMap_FindOrInsert into role-B sub-tree.
            - ``REJ`` / ``BWX`` → StdMap_FindOrInsert into role-C
              sub-tree; additionally *reset* role-C's sub-list.
            - Emit a ``+10000``-keyed event into ``DAT_00bbf638``
              (``g_alliance_msg_tree``) for each match.

      **Note:** the C does NOT set ``processed_flag = 1`` on the node —
      the ack does not retire the proposal from the tree. We mirror
      that here (the flag is only consulted as a read-side filter).

      Returns 1 if any node matched, 0 otherwise.

    The ``proposal_tokens`` parameter is optional; when provided it is
    used as an additional exact-token gate against ``node.tokens`` to
    disambiguate when multiple pending proposals share a sender.
    """
    import logging as _logging
    import time as _t
    _log = _logging.getLogger(__name__)

    is_yes = (ack_tok == _ACK_TOK_YES)
    match_count = 0

    for entry in getattr(state, 'g_pos_analysis_list', []):
        if not isinstance(entry, dict):
            continue
        if entry.get('processed_flag', 0) != 0:
            continue

        # +0xc is the participant map. +0xf is populated by the YES path.
        if sender_power not in set(entry.get('participant_powers', set())):
            continue

        # Optional exact token-sequence gate for disambiguation.
        if proposal_tokens is not None:
            entry_tokens = entry.get('tokens', [])
            if not _token_seq_equal(entry_tokens, proposal_tokens):
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

        # ── +10000-keyed event into g_alliance_msg_tree ─────────────────────
        # C: BuildAllianceMsg(&DAT_00bbf638, buf, elapsed_sec + 10000).
        # elapsed_sec = current_time − _DAT_00ba2880 (turn start).
        state.g_alliance_msg_tree.add(
            int(_t.time() - getattr(state, 'g_turn_start_time', 0.0)) + 10000
        )

        match_count += 1
        _log.debug(
            "ack_matcher: matched sender=%d tok=0x%x (role=%s) match_count=%d",
            sender_power, ack_tok, 'B' if is_yes else 'C', match_count,
        )

    return 1 if match_count > 0 else 0


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
    'FCT': 0x4A07,   # utils/tokens.py "4A07":"FCT"
    'THK': 0x4A18,   # utils/tokens.py "4A18":"THK"
    'WHY': 0x4A1E,   # utils/tokens.py "4A1E":"WHY"
    'IDK': 0x4A0A,   # utils/tokens.py "4A0A":"IDK"
    'SUG': 0x4A17,   # utils/tokens.py "4A17":"SUG"
    'HOW': 0x4A09,   # utils/tokens.py "4A09":"HOW"
    'QRY': 0x4A14,   # utils/tokens.py "4A14":"QRY"
    'NAR': 0x4A21,   # (no entry in utils/tokens.py — keep as-is)
    'CCL': 0x4A22,   # (no entry in utils/tokens.py — keep as-is)
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
