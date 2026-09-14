"""YES dispatcher sub-handlers — NME, OBS, IAM, NOT, GOF, TME, DRW, SND.

BaseBot's YESDispatcher (0x0045db40) calls a virtual per variant; Albert's
vtable (0x004afc74) resolves them as follows:
  * YES ( NME ... )  +0x98 [38] FUN_0045b720 — empty
  * YES ( OBS ... )  +0x9c [39] FUN_0045b720 — empty
  * YES ( IAM ... )  +0xa0 [40] FUN_0045b730 — bot+0x3c = 1, send MAP
  * YES ( NOT ... )  FUN_0045b070: GOF +0xb4 [45], DRW +0xb8 [46],
                     SUB +0xbc [47] FUN_0045b720, other +0xd0 [52]
                     FUN_0040d180 — all empty
  * YES ( GOF ... )  +0xa4 [41] FUN_0045b720 — empty
  * YES ( TME ... )  +0xa8 [42] FUN_0045b720 — empty (DAT_00624ef4 is
                     written only by ParseHSTResponse)
  * YES ( DRW ... )  +0xac [43] FUN_0045b720 — empty
  * YES ( SND ... )  FUN_0045d210, then +0xb0 [44] FUN_0045a090
  * YES ( ... )      +0xcc [51] FUN_0040d180 — empty

The handlers below therefore only log, except SND.  python-diplomacy sends
none of these acknowledgements and the client does not wire this dispatcher.
"""

import logging as _logging

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups

_log = _logging.getLogger(__name__)

_DAIDE_POWERS = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]


def handle_yes_nme(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( NME ( name ) ( version ) ) — server accepts name handshake.

    Port of vtable slot +0x98.

    C behaviour (inferred): server has accepted our NME registration. This
    confirms that the bot's name and version were accepted. In the C binary
    this likely triggers the MAP request sequence (NME → YES(NME) → MAP).
    In python-diplomacy the handshake is handled by the client layer.

    We set g_hlo_received as a secondary signal that handshake has completed
    (the primary path is through HLO).
    """
    _log.info("handle_yes_nme: NME accepted — handshake complete (%s)",
              inner_group[:80])
    # No critical state mutation — python-diplomacy handles the handshake.


def handle_yes_obs(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( OBS ) — server accepts observer registration.

    Port of vtable slot +0x9c.

    Albert normally plays as a power, not an observer. This handler
    logs the acceptance but takes no action.
    """
    _log.info("handle_yes_obs: observer registration accepted")


def handle_yes_iam(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( IAM ( power ) ( passcode ) ) — server accepts reconnect.

    Port of vtable slot +0xa0.

    C behaviour (inferred): the server has accepted our IAM (identity
    assertion for reconnection). The power and passcode are already set
    from the original HLO; this confirms they are still valid.

    In python-diplomacy, reconnection is handled by the client layer.
    """
    # Extract power if present (for logging)
    groups = _extract_top_paren_groups(inner_group)
    if groups:
        power_str = groups[0].strip().upper()
        _log.info("handle_yes_iam: IAM accepted for power=%s", power_str)
    else:
        _log.info("handle_yes_iam: IAM accepted (%s)", inner_group[:80])


def handle_yes_not(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( NOT ( ... ) ) — server accepts our NOT proposal.

    Port of FUN_0045b070.

    C behaviour (inferred from YESDispatcher.c:52-56):
    FUN_0045b070(this, pvVar1, puVar4) is called with the full message and
    the sub-list extracted from the NOT body. The most common case is
    YES(NOT(GOF)) — server confirms that our go-flag cancellation was accepted.

    Other cases:
      YES(NOT(DRW)) — server accepts withdrawal of our draw proposal.
      YES(NOT(TME(n))) — server accepts withdrawal of our time request.

    Albert's slots for NOT(GOF), NOT(DRW), NOT(SUB) and any other NOT body
    are empty, so the acknowledgement changes no state.
    """
    # Parse the inner NOT body to determine what was NOT'd
    not_groups = _extract_top_paren_groups(inner_group)
    if not_groups:
        not_body_tokens = not_groups[0].split()
    else:
        tokens = inner_group.split()
        # Skip 'NOT' if present
        not_body_tokens = [t for t in tokens if t.upper() != 'NOT']

    variant = not_body_tokens[0].upper() if not_body_tokens else 'UNKNOWN'

    if variant == 'GOF':
        _log.info("handle_yes_not: NOT(GOF) accepted — go-flag cancelled")

    elif variant == 'DRW':
        # DAT_00baed5d (g_draw_sent) is written only by FUN_0040de30 and
        # GenerateAndSubmitOrders, never by this acknowledgement.
        _log.info("handle_yes_not: NOT(DRW) accepted — draw proposal withdrawn")

    elif variant == 'TME':
        _log.info("handle_yes_not: NOT(TME) accepted — time request withdrawn")

    else:
        _log.info("handle_yes_not: NOT(%s) accepted", variant)


def handle_yes_gof(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( GOF ) — server accepts our go-flag (ready to adjudicate).

    Port of vtable slot +0xa4.

    Albert's slot is empty: the acknowledgement changes no state.
    """
    _log.info("handle_yes_gof: GOF accepted — ready for adjudication")


def handle_yes_tme(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( TME ( seconds ) ) — server grants time extension.

    Port of vtable slot +0xa8.

    Albert's slot is empty: DAT_00624ef4, the move time limit, is written
    only by ParseHSTResponse, so a granted extension changes no state.
    """
    _log.info("handle_yes_tme: TME accepted (%s)", inner_group[:80])


def handle_yes_drw(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( DRW ) — server accepts our draw proposal.

    Port of vtable slot +0xac.

    Albert's slot is empty: the acknowledgement changes no state.  The
    game-end signal is the bare top-level DRW message.
    """
    _log.info("handle_yes_drw: draw proposal accepted (vote registered)")


def handle_own_press_delivered(state: InnerGameState, press_body, send_fn=None) -> None:
    """
    Port of FUN_0045a090 — Albert's hook for a delivered SND.

    BaseBot's YES ( SND ... ) handler (FUN_0045d210) drops the message from
    its pending list and calls this vtable override (+0xb0) with it.  When
    the delivered press is ``YES ( PRP ... )`` — Albert's own acceptance —
    Albert inserts itself into the responded set (node+0x3c) of every
    g_pos_analysis_list node whose token list equals the accepted proposal
    and whose participant set contains Albert (the processed byte is not
    consulted), then runs EvaluateOrderProposalsAndSendGOF.  Any other press
    changes nothing.

    ``press_body`` is the SND's press message, as wire text or tokens.
    """
    from ..tokens import _c_sublist, _c_token_at, _token_seq_equal, _wire_tokens

    tokens = _wire_tokens(press_body) if isinstance(press_body, str) else list(press_body)
    if str(_c_token_at(tokens, 0)).upper() != 'YES':
        return
    proposal = _c_sublist(tokens, 1)
    if str(_c_token_at(proposal, 0)).upper() != 'PRP':
        return

    own_power = int(getattr(state, 'albert_power_idx', 0))
    for entry in getattr(state, 'g_pos_analysis_list', []):
        if not _token_seq_equal(entry.get('tokens', []), proposal):
            continue
        if own_power not in set(entry.get('participant_powers', set())):
            continue
        entry.setdefault('role_b_set', set()).add(own_power)

    from ...bot.gof import _evaluate_order_proposals_and_send_gof
    _evaluate_order_proposals_and_send_gof(state, send_fn)


def handle_yes_snd(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( SND ( turn ) ( powers ) ( press ) ) — the server confirms
    delivery of our outbound press.

    Port of FUN_0045d210: BaseBot removes the matching pending message, then
    Albert's override FUN_0045a090 (``handle_own_press_delivered``) inspects
    the press, the SND's element 3.
    """
    from ..tokens import _c_sublist, _wire_tokens

    _log.debug("handle_yes_snd: SND delivery confirmed (%s)", inner_group[:100])
    # C: GetSubList(GetSubList(msg, 1), 3) — Albert's SND always carries the
    # turn, so element 3 is the press.
    handle_own_press_delivered(state, _c_sublist(_wire_tokens(inner_group), 3))


def handle_yes_unknown(state: InnerGameState, full_message: str, variant_group: str) -> None:
    """
    Handle YES ( ... ) — unknown YES variant (fallback).

    Port of vtable slot +0xcc.

    Albert's slot (FUN_0040d180) is empty; the port logs the variant.
    """
    _log.warning("handle_yes_unknown: unhandled YES variant: %r (message=%r)",
                 variant_group[:80], full_message[:120])
