"""FRM-envelope message dispatcher + top-level inbound entrypoint.

Split from communications/inbound.py during the 2026-04 refactor.

Holds the two routers that take a raw inbound message, peel off the FRM
envelope, classify it, and dispatch to the right handler / gate:

  * ``process_frm_message`` — port of Albert's FRM handler (FUN_0045a2f0):
    proposals, replies (YES/REJ/BWX), HUH, TRY and everything else.
  * ``parse_message``       — top-level inbound entrypoint: routes HST
    to ``.history`` and FRM to ``process_frm_message``.

Cross-module deps: handlers in ``.history``, ``.ack``, ``.gate``,
``.respond`` and ``...state.InnerGameState``.
"""

import time as _time

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups
from ..tokens import _c_sublist, _c_token_at, _wire_tokens
from .history import process_hst
from .ack import (
    ack_matcher,
    huh_err_strip_replay,
    process_try,
    _ACK_TOK_YES,
    _ACK_TOK_REJ,
    _ACK_TOK_BWX,
)
from .gate import delay_review
from .respond import receive_proposal, respond, send_huh_and_try

_POWER_NAMES = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]
# 3-letter DAIDE codes, index-aligned with _POWER_NAMES.
_DAIDE_NAMES = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]

_REPLY_TOKENS = {
    'YES': _ACK_TOK_YES,
    'REJ': _ACK_TOK_REJ,
    'BWX': _ACK_TOK_BWX,
}


def _evaluate_press(state, content_tokens, sender_id, recipients) -> int:
    from ..evaluators import evaluate_press
    return evaluate_press(state, {
        'from_power_tok': 0x4100 | sender_id,
        'sublist2': [0x4100 | p for p in recipients],
        'sublist3': list(content_tokens),
    })


def process_frm_message(
    state: InnerGameState,
    sender: str,
    sub_message: str,
    send_fn=None,
):
    """
    Port of Albert's FRM handler (FUN_0045a2f0).

    ``FRM ( sender ) ( recipients ) ( content )``.  ``sender`` arrives from
    python-diplomacy as a full power name ("FRANCE"); an empty sender is taken
    from the envelope.  Power tokens inside the envelope and body are 3-letter
    DAIDE codes.

    C flow:
      * now = __time64 (the answer's time base); CancelPriorPress.
      * The early deadline test (content PRP *and* YES) is unreachable.
      * ``content[0] == PRP`` and g_HistoryCounter > 0:
          DELAY_REVIEW(content) — registers novel XDO proposals.
          not delayed → EvaluatePress, RECEIVE_PROPOSAL, RESPOND(verdict, now);
          delayed     → RESPOND(REJ, now) unless the season is SPR or FAL.
      * otherwise, by ``content[0]``:
          YES/REJ/BWX → reply = content's first sub-list;
              FUN_0042c970(reply, sender, token).  Nothing matched and the
              token is YES → EvaluatePress(reply); if YES, RECEIVE_PROPOSAL
              (reply, sender, recipients) and FUN_0042c970(reply, own, YES).
          HUH → HUH(content's first sub-list, sender).
          TRY → TRY(content's first sub-list, sender).
          anything else, including a PRP while g_HistoryCounter <= 0 →
              FUN_0040d4d0: ``HUH ( ERR content )`` + ``TRY ( ... )``.
      * EvaluateOrderProposalsAndSendGOF, on every path.
    """
    groups = _extract_top_paren_groups(sub_message)
    if len(groups) >= 3:
        from_str, to_str, content_str = groups[0], groups[1], groups[2]
    elif len(groups) >= 2:
        from_str, to_str, content_str = '', groups[0], groups[1]
    else:
        from_str, to_str = '', ''
        content_str = groups[0] if groups else sub_message

    sender_upper = (sender or '').upper()
    if sender_upper in _POWER_NAMES:
        sender_id = _POWER_NAMES.index(sender_upper)
    else:
        envelope = from_str.upper().split()
        if not envelope or envelope[0] not in _DAIDE_NAMES:
            return
        sender_id = _DAIDE_NAMES.index(envelope[0])

    recipients = [
        _DAIDE_NAMES.index(p)
        for p in to_str.upper().split()
        if p in _DAIDE_NAMES
    ]
    content = _wire_tokens(content_str)
    first = str(_c_token_at(content, 0)).upper()
    now = int(_time.time())
    own_power = int(getattr(state, 'albert_power_idx', 0))

    from ..senders import cancel_prior_press
    cancel_prior_press(state, own_power, send_fn)

    if first == 'PRP' and int(getattr(state, 'g_history_counter', 0)) > 0:
        if not delay_review(state, content, sender_id, recipients):
            verdict = _evaluate_press(state, content, sender_id, recipients)
            receive_proposal(
                state, sender_id, content,
                participant_powers=recipients, send_fn=send_fn,
            )
            respond(
                state,
                {
                    'sublist1': [0x4100 | sender_id],
                    'sublist2': [0x4100 | p for p in recipients],
                    'sublist3': content,
                },
                verdict,
                elapsed_lo=now & 0xFFFFFFFF,
                elapsed_hi=(now >> 32) & 0xFFFFFFFF,
                send_fn=send_fn,
            )
        elif getattr(state, 'g_season', '') not in ('SPR', 'FAL'):
            respond(
                state,
                {
                    'sublist1': [0x4100 | sender_id],
                    'sublist2': [0x4100 | p for p in recipients],
                    'sublist3': content,
                },
                _ACK_TOK_REJ,
                elapsed_lo=now & 0xFFFFFFFF,
                elapsed_hi=(now >> 32) & 0xFFFFFFFF,
                send_fn=send_fn,
            )
    elif first in _REPLY_TOKENS:
        reply_tok = _REPLY_TOKENS[first]
        reply = _c_sublist(content, 1)
        matched = ack_matcher(state, sender_id, reply_tok, reply)
        if not matched and reply_tok == _ACK_TOK_YES:
            verdict = _evaluate_press(state, reply, sender_id, recipients)
            if verdict == _ACK_TOK_YES:
                receive_proposal(
                    state, sender_id, reply,
                    participant_powers=recipients, send_fn=send_fn,
                )
                ack_matcher(state, own_power, _ACK_TOK_YES, reply)
    elif first == 'HUH':
        huh_err_strip_replay(state, sender_id, _c_sublist(content, 1))
    elif first == 'TRY':
        process_try(state, sender_id, _c_sublist(content, 1))
    else:
        send_huh_and_try(state, sender_id, content, send_fn)

    from ...bot.gof import _evaluate_order_proposals_and_send_gof
    _evaluate_order_proposals_and_send_gof(state, send_fn)


def parse_message(state: InnerGameState, sender: str, message: str, send_fn=None):
    """
    Main communication ingest port (FUN_0045f1f0).
    Hooks into bot.py's message receiver.

    Dispatches on the first top-level token, mirroring C
    InboundDAIDEDispatcher (Source/communications/InboundDAIDEDispatcher.c).
    Most DipNet-level tokens (HLO/MAP/MDF/NOW/ORD/SCO/CCD/OUT) are handled
    by python-diplomacy above this call site.  What remains here is HST, the
    FRM press envelope, the game-end pair DRW/SLO, and bare peer press, which
    python-diplomacy delivers without an FRM envelope.

    ``send_fn`` receives outbound press and readiness controls produced while
    the message is processed.
    """
    stripped = message.lstrip().lstrip('(').lstrip()
    first = stripped.split(None, 1)[0] if stripped else ''

    if first == 'HST':
        # HST is DipNet history, not a DAIDE envelope — route it up front.
        process_hst(state, message)
        return
    if first == 'FRM':
        process_frm_message(state, sender, message, send_fn=send_fn)
        return

    # ── Bare top-level game-end signals ────────────────────────────────
    # C: DRW/SLO both set `*(int *)((int)this + 8) + 0x2449 = 1` before
    # invoking the per-token vtable slot. That byte is what Python calls
    # state.g_game_over; bot/client/_orders.py:125 reads it as the main-
    # loop exit guard.
    if first in ('DRW', 'SLO'):
        import logging as _logging
        _logging.getLogger(__name__).info(
            "parse_message: game-end signal %s — setting g_game_over", first,
        )
        state.g_game_over = True
        return

    # ── Bare peer press (python-diplomacy strips the FRM envelope) ─────────
    # In the C binary, inter-bot press is wrapped in FRM (from)(to)(content).
    # python-diplomacy delivers only the content body as the message string;
    # sender/recipient are in the Message metadata.  A python-diplomacy
    # message has exactly one recipient, so the synthesised envelope names
    # Albert alone.
    import logging as _logging
    _log_pm = _logging.getLogger(__name__)
    sender_upper = sender.upper()
    if sender_upper not in _POWER_NAMES:
        _log_pm.debug(
            "parse_message: bare %s from unknown sender %r — dropping",
            first, sender,
        )
        return
    if not first:
        return
    sender_daide = _DAIDE_NAMES[_POWER_NAMES.index(sender_upper)]
    own_idx = getattr(state, 'albert_power_idx', 0)
    own_daide = _DAIDE_NAMES[own_idx] if 0 <= own_idx < len(_DAIDE_NAMES) else 'UNO'
    frm_msg = f"FRM ( {sender_daide} ) ( {own_daide} ) ( {message} )"
    _log_pm.debug(
        "parse_message: bare %s from %s — synthesised FRM envelope",
        first, sender_daide,
    )
    process_frm_message(state, sender, frm_msg, send_fn=send_fn)
