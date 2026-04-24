"""YES dispatcher sub-handlers — NME, OBS, IAM, NOT, GOF, TME, DRW, SND.

Ported during the 2026-04 handler port.

The YES dispatcher (YESDispatcher.c) routes YES variants to:
  * YES ( NME ... )  → handle_yes_nme   — vtable +0x98
  * YES ( OBS ... )  → handle_yes_obs   — vtable +0x9c
  * YES ( IAM ... )  → handle_yes_iam   — vtable +0xa0
  * YES ( NOT ... )  → handle_yes_not   — FUN_0045b070
  * YES ( GOF ... )  → handle_yes_gof   — vtable +0xa4
  * YES ( TME ... )  → handle_yes_tme   — vtable +0xa8
  * YES ( DRW ... )  → handle_yes_drw   — vtable +0xac
  * YES ( SND ... )  → handle_yes_snd   — FUN_0045d210
  * YES ( ... )      → handle_yes_unknown — vtable +0xcc

No C source exists for any of these. Implementations are derived from
DAIDE protocol specification and the C dispatcher's structural patterns.

DAIDE protocol semantics:
  YES (NME (name)(version))  — Server accepts our NME (name) handshake.
  YES (OBS)                  — Server accepts our observer registration.
  YES (IAM (power)(passcode)) — Server accepts our reconnect identity.
  YES (NOT (GOF))            — Server accepts our NOT(GOF) (cancel go-flag).
  YES (GOF)                  — Server accepts our GOF (go-flag).
  YES (TME (seconds))        — Server grants our time-extension request.
  YES (DRW)                  — Server accepts our draw proposal.
  YES (SND (...))            — Server confirms delivery of our SND press.
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

    For NOT(GOF): the C binary likely clears the "GOF sent" flag so that
    the press-scheduling loop knows it needs to re-send GOF after submitting
    revised orders.
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
        # YES(NOT(GOF)) — go-flag cancellation accepted
        # Clear any GOF-sent tracking so press scheduling re-evaluates
        state.g_gof_sent = False
        _log.info("handle_yes_not: NOT(GOF) accepted — go-flag cancelled")

    elif variant == 'DRW':
        # YES(NOT(DRW)) — draw withdrawal accepted
        state.g_draw_sent = 0
        _log.info("handle_yes_not: NOT(DRW) accepted — draw proposal withdrawn")

    elif variant == 'TME':
        _log.info("handle_yes_not: NOT(TME) accepted — time request withdrawn")

    else:
        _log.info("handle_yes_not: NOT(%s) accepted", variant)


def handle_yes_gof(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( GOF ) — server accepts our go-flag (ready to adjudicate).

    Port of vtable slot +0xa4.

    C behaviour (inferred): the server has acknowledged that Albert is
    ready for adjudication. Sets a "GOF acknowledged" flag. The next
    server message will typically be the adjudication results (ORD, SCO,
    or a new NOW for the next phase).
    """
    # Mark GOF as acknowledged
    state.g_gof_sent = True
    _log.info("handle_yes_gof: GOF accepted — ready for adjudication")


def handle_yes_tme(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( TME ( seconds ) ) — server grants time extension.

    Port of vtable slot +0xa8.

    C behaviour (inferred): the server has granted additional time for
    the current phase. Update the move time limit so that press scheduling
    and Monte Carlo evaluation can use the extra time.
    """
    # Extract the granted seconds
    tme_groups = _extract_top_paren_groups(inner_group)
    if tme_groups:
        secs_str = tme_groups[0].strip()
    else:
        tokens = inner_group.split()
        secs_str = ''
        for t in tokens:
            t_clean = t.strip('()')
            if t_clean.isdigit():
                secs_str = t_clean
                break

    if secs_str.isdigit():
        granted_secs = int(secs_str)
        # Extend the move time limit
        old_limit = getattr(state, 'g_move_time_limit_sec', 0)
        state.g_move_time_limit_sec = old_limit + granted_secs
        _log.info("handle_yes_tme: time extension granted: +%d sec (new limit=%d)",
                  granted_secs, state.g_move_time_limit_sec)
    else:
        _log.info("handle_yes_tme: TME accepted (seconds=%r)", secs_str)


def handle_yes_drw(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( DRW ) — server accepts our draw proposal.

    Port of vtable slot +0xac.

    C behaviour (inferred): the server has accepted the draw vote. This
    does NOT mean the game is drawn — it means our vote was registered.
    The actual DRW game-end comes as a bare top-level DRW message
    (handled by inbound_daide_dispatcher → g_game_over = True).
    """
    _log.info("handle_yes_drw: draw proposal accepted (vote registered)")
    # The draw vote was accepted; g_draw_sent stays at 1 since our vote
    # is still active. The game-end signal comes separately.


def handle_yes_snd(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle YES ( SND ( power ) ( power... ) ( content... ) ) — server
    confirms delivery of our outbound press.

    Port of FUN_0045d210.

    C behaviour (inferred from YESDispatcher.c:88-93):
    FUN_0045d210(this, pvVar1, puVar4) receives the SND sub-list, which
    echoes the SND we originally sent. The confirmation means the server
    has forwarded our press to the target power(s).

    The C binary likely:
      1. Marks the corresponding entry in g_master_order_list as delivered.
      2. Optionally timestamps the delivery for turn-score tracking.

    In Python, the master order list entries are consumed by the dispatch
    loop and removed; the YES(SND) confirmation is informational.
    """
    _log.debug("handle_yes_snd: SND delivery confirmed (%s)", inner_group[:100])
    # Mark any pending master-order-list entries matching this SND as delivered.
    # Walk g_master_order_list and flag matching entries.
    for entry in getattr(state, 'g_master_order_list', []):
        if not isinstance(entry, dict):
            continue
        if entry.get('press_type') == 'SND' and not entry.get('delivered'):
            # Simple heuristic: mark the oldest undelivered SND as delivered.
            # A more precise match would compare target powers and content,
            # but the C binary uses identity-based matching which we can't
            # replicate without the exact token list comparison.
            entry['delivered'] = True
            _log.debug("handle_yes_snd: marked entry as delivered: %r",
                       entry.get('data', [])[:5])
            break


def handle_yes_unknown(state: InnerGameState, full_message: str, variant_group: str) -> None:
    """
    Handle YES ( ... ) — unknown YES variant (fallback).

    Port of vtable slot +0xcc.

    C behaviour (inferred): logs the unexpected YES variant. This covers
    any YES response that doesn't match the known variants above.
    """
    _log.warning("handle_yes_unknown: unhandled YES variant: %r (message=%r)",
                 variant_group[:80], full_message[:120])
