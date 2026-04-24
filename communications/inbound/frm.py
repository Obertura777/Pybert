"""FRM-envelope message dispatcher + top-level inbound entrypoint.

Split from communications/inbound.py during the 2026-04 refactor.

Holds the two routers that take a raw inbound message, peel off the FRM
envelope, classify it, and dispatch to the right handler / gate:

  * ``process_frm_message`` — classifies the FRM payload (ACK, HUH, TRY,
    or fresh proposal) and dispatches into ``.ack`` and ``.gate``.
  * ``parse_message``       — top-level inbound entrypoint: routes HST
    to ``.history`` and FRM to ``process_frm_message``.

Cross-module deps: handlers in ``.history``, ``.ack``, ``.gate`` and
``...state.InnerGameState``.
"""

import re

from ...state import InnerGameState
from ..alliance import build_alliance_msg
from ..parsers import _extract_top_paren_groups, _split_top_level_groups
from .history import process_hst
from .ack import (
    ack_matcher,
    huh_err_strip_replay,
    process_try,
    _ACK_TOK_YES,
    _ACK_TOK_REJ,
    _ACK_TOK_BWX,
)
from .gate import delay_review, register_received_press


def process_frm_message(state: InnerGameState, sender: str, sub_message: str):
    """
    Port of process_frm and FRIENDLY logic (FUN_0042dc40).
    Updates g_AllyMatrix and sets relation tracking arrays by unpacking FRM envelopes.
    Also calls register_received_press (FUN_00431310) for incoming XDO/PRP proposals.

    The ``sender`` arrives from python-diplomacy as a full DipNet name
    ("FRANCE") but power tokens *inside* the DAIDE press body use 3-letter
    codes ("FRA").  Keep two index-aligned tables so sender-validation and
    body-token parsing each consult the right form.  Fixed 2026-04-18
    (AUDIT_moves_and_messages.md #3b — discovered during #3 verification).
    """
    power_names = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]
    # 3-letter DAIDE codes, same order as power_names (index-aligned).
    # Matches bot._shared._DAIDE_POWER_NAMES; duplicated here to avoid
    # cross-package import from communications → bot.
    daide_names = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]

    sender_upper = sender.upper()
    if sender_upper not in power_names:
        return

    sender_id = power_names.index(sender_upper)

    # ── Parse the FRM envelope once: FRM ( from ) ( to... ) ( content... ) ──
    # C FRMHandler peels the envelope, then dispatches on the *first token*
    # of the content group. Token-level dispatch (vs substring match on the
    # whole wire string) is essential: a REJ body echoes the original PRP
    # verbatim, so substring probes for 'YES (' / 'PRP (' / 'XDO' etc. would
    # spuriously fire on nested occurrences and double-process the message.
    # Fixed 2026-04-18 (AUDIT_moves_and_messages.md #4).
    groups = _extract_top_paren_groups(sub_message)
    if len(groups) >= 3:
        to_str = groups[1]
        content_str = groups[2]
    elif len(groups) >= 2:
        to_str = groups[0]   # FRM keyword stripped; fallback
        content_str = groups[1]
    else:
        to_str = ''
        content_str = groups[0] if groups else sub_message

    content_tokens = content_str.split()
    top_tok = content_tokens[0] if content_tokens else ''
    # First balanced paren group after top_tok is the body argument.
    rest_items = (
        _split_top_level_groups(content_tokens[1:])
        if len(content_tokens) > 1 else []
    )
    top_body = rest_items[0] if rest_items and isinstance(rest_items[0], list) else []

    # ── PRP: fresh press proposal → register for BuildAndSendSUB processing ──
    # C: FUN_00431310 called only when the top-level body token is PRP.
    # A REJ/YES echoing our own PRP must NOT re-register it as incoming.
    if top_tok == 'PRP':
        # Build to-power token list — body tokens are 3-letter DAIDE codes.
        to_power_toks = [
            daide_names.index(p) | 0x4100
            for p in to_str.upper().split()
            if p in daide_names
        ]
        from_power_tok = sender_id | 0x4100
        # Press content is the inner tokens of the PRP group.
        press_tokens = top_body

        # C FRMHandler (PRP branch): `if (!DELAY_REVIEW(body)) { EvaluatePress(...) }`.
        # DELAY_REVIEW returns 1 to defer review on novel low-score proposals;
        # returns 0 to proceed with EvaluatePress + RESPOND. In SPR/FAL movement
        # phases C just drops deferred proposals; in retreat/winter it emits
        # REJ. We mirror the movement-phase drop (simplest parity) and skip
        # register_received_press entirely when the gate says delay.
        delay_result = delay_review(state, press_tokens)
        if delay_result == 2:
            # Phase-aware REJ: retreat/build phases emit explicit REJ rather
            # than silently dropping.  Fixed 2026-04-20 (audit finding M3).
            import logging as _logging
            _logging.getLogger(__name__).debug(
                "process_frm_message: DELAY_REVIEW=2 → sending REJ for press_tokens=%r",
                press_tokens,
            )
            from ..senders import send_alliance_press
            rej_entry = {
                'type': 'REJ',
                'from_power_tok': sender_id | 0x4100,
                'sublist3': list(press_tokens),
            }
            send_alliance_press(state, key=len(state.g_BroadcastList), entry_data=rej_entry)
        elif delay_result == 1:
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
    elif top_tok in ('YES', 'REJ', 'BWX'):
        ack_tok_map = {
            'YES': _ACK_TOK_YES,
            'REJ': _ACK_TOK_REJ,
            'BWX': _ACK_TOK_BWX,
        }
        ack_matcher(state, sender_id, ack_tok_map[top_tok],
                    proposal_tokens=top_body if top_body else None)

    # ── HUH inbound: peer ERR-strip replay salvage (FUN_0042cd70) ──────────
    # C: FRMHandler body_tok == HUH → huh_err_strip_replay, which strips
    # ERR tokens from the echoed body and replays the remainder through the
    # ack-matcher.
    elif top_tok == 'HUH':
        if top_body:
            huh_err_strip_replay(state, sender_id, top_body)

    # ── TRY inbound: sender declares their stance tokens toward us (FUN_0041c0f0) ──
    # C: replaces DAT_00bb6e10[sender*0xc] with body tokens; no reply. Consumed
    # by HOSTILITY.c for stance-based scoring.
    elif top_tok == 'TRY':
        if top_body:
            process_try(state, sender_id, top_body)

    # ── ALY side-channel processing ────────────────────────────────────────
    # REJ-of-ALY and plain-ALY alliance mapping. Both variants reach the
    # alliance-matrix side-channel; the top_tok gate disambiguates REJ
    # (break alliance, degrade trust) from PRP/YES (establish, increment
    # trust). Nested ALY inside REJ(PRP(ALY(...))) is correctly seen as a
    # REJ because top_tok is the first token of the content group.
    # Fixed 2026-04-18 (AUDIT_moves_and_messages.md #3, #4).
    if top_tok == 'REJ' and 'ALY' in content_str:
        match = re.search(r'ALY \((.*?)\)', content_str)
        if match:
            allies = match.group(1).split()
            for ally in allies:
                ally_upper = ally.strip().upper()
                # Body tokens are 3-letter DAIDE codes ("FRA") — consult
                # daide_names, not the full-name power_names used for sender.
                if ally_upper in daide_names:
                    ally_id = daide_names.index(ally_upper)
                    if ally_id != sender_id:
                        # Break alliance mapping forcefully
                        state.g_AllyMatrix[sender_id, ally_id] = 0
                        state.g_AllyMatrix[ally_id, sender_id] = 0

                        # Degrade trust aggressively on rejections
                        current_trust = state.g_AllyTrustScore[sender_id, ally_id]
                        state.g_AllyTrustScore[sender_id, ally_id] = max(0.0, current_trust - 2.0)

                        # Update alliance tree — C's FRMHandler always calls
                        # BuildAllianceMsg for ALY arrivals. Fixed 2026-04-20
                        # (audit finding C2).
                        ally_key = ally_id | 0x4100
                        build_alliance_msg(state, ally_key)

    elif top_tok in ('PRP', 'YES') and 'ALY' in content_str:
        match = re.search(r'ALY \((.*?)\)', content_str)
        if match:
            allies = match.group(1).split()
            for ally in allies:
                ally_upper = ally.strip().upper()
                if ally_upper in daide_names:
                    ally_id = daide_names.index(ally_upper)
                    if ally_id != sender_id:
                        # Establish explicit bilateral bounds
                        state.g_AllyMatrix[sender_id, ally_id] = 1
                        state.g_AllyMatrix[ally_id, sender_id] = 1

                        # Increment trust progressively
                        state.g_AllyTrustScore[sender_id, ally_id] += 1.0
                        state.g_AllyTrustScore[ally_id, sender_id] += 1.0

                        # Update alliance tree — mirrors REJ branch above.
                        # Fixed 2026-04-20 (audit finding C2).
                        ally_key = ally_id | 0x4100
                        build_alliance_msg(state, ally_key)


def parse_message(state: InnerGameState, sender: str, message: str):
    """
    Main communication ingest port (FUN_0045f1f0).
    Hooks into bot.py's message receiver.

    Dispatches on the first top-level token, mirroring C
    InboundDAIDEDispatcher (Source/communications/InboundDAIDEDispatcher.c).
    Most DipNet-level tokens (HLO/MAP/MDF/NOW/ORD/SCO/CCD/OUT) are handled
    by python-diplomacy above this call site. What remained dropped before
    Fix #5 (AUDIT_moves_and_messages.md #5) was the game-end pair DRW/SLO
    and the peer-handshake replies NOT/REJ/YES/HUH when they arrive at the
    top level (rather than wrapped in an FRM envelope from another power).
    """
    # Tokenize first word — DAIDE messages are whitespace-delimited after
    # the optional leading envelope.
    stripped = message.lstrip().lstrip('(').lstrip()
    first = stripped.split(None, 1)[0] if stripped else ''

    if first == 'HST' or 'HST' in message and 'FRM' not in message:
        # HST is DipNet history, not a DAIDE envelope — route it up front.
        process_hst(state, message)
        return
    if first == 'FRM' or 'FRM' in message:
        process_frm_message(state, sender, message)
        return

    # ── Bare top-level game-end signals ────────────────────────────────
    # C: DRW/SLO both set `*(int *)((int)this + 8) + 0x2449 = 1` before
    # invoking the per-token vtable slot. That byte is what Python calls
    # state.g_game_over; bot/client/_orders.py:125 reads it as the main-
    # loop exit guard. Setting it here is the minimum viable port.
    if first in ('DRW', 'SLO'):
        import logging as _logging
        _logging.getLogger(__name__).info(
            "parse_message: game-end signal %s — setting g_game_over", first,
        )
        state.g_game_over = True
        return

    # ── Bare top-level handshake replies ───────────────────────────────
    # YES/REJ/BWX/HUH/NOT at the top level are server acks for messages
    # WE sent (MDF/HLO/NOT negotiation, etc.), not peer press replies.
    # python-diplomacy's message-loop surfaces most of these as high-level
    # callbacks; we log at warning level so a drop is at least visible.
    if first in ('YES', 'REJ', 'BWX', 'HUH', 'NOT'):
        import logging as _logging
        _logging.getLogger(__name__).warning(
            "parse_message: top-level %s from server not ported — message=%r",
            first, message[:200],
        )
        return

    # Unknown / unhandled top-level token. Keep it debug-level so noise
    # doesn't drown out real warnings, but still leave a trail.
    if first:
        import logging as _logging
        _logging.getLogger(__name__).debug(
            "parse_message: no handler for top-level token %r; dropping", first,
        )
