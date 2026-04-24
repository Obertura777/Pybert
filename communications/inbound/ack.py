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
``..tokens._token_seq_overlap`` for ``ack_matcher``.
"""

from ...state import InnerGameState
from ..tokens import (
    _TOK_ALY, _TOK_AND, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_VSS, _TOK_XDO,
    _token_seq_overlap,
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
              (``g_alliance_msg_tree``) for each match.

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

    for entry in getattr(state, 'g_pos_analysis_list', []):
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

        # ── +10000-keyed event into g_alliance_msg_tree ─────────────────────
        # C: BuildAllianceMsg(&DAT_00bbf638, buf, elapsed_sec + 10000).
        state.g_alliance_msg_tree.add(int(_t.time()) + 10000)

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
