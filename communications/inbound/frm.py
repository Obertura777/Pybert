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

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups
from .history import process_hst
from .ack import ack_matcher, huh_err_strip_replay, process_try
from .gate import delay_review, register_received_press


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
