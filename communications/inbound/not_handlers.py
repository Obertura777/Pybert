"""NOT dispatcher sub-handlers — CCD, TME, and fallback.

Ported during the 2026-04 handler port.

The NOT dispatcher (NOTDispatcher.c) routes NOT variants to:
  * NOT ( CCD ( power ) )  → handle_not_ccd  — FUN_0045e9f0
  * NOT ( TME ( secs ) )   → handle_not_tme  — vtable +0x50
  * NOT ( ... )            → handle_not_unknown — vtable +0xc0

No C source exists for FUN_0045e9f0 or the vtable slots. Implementations
are derived from DAIDE protocol specification and inferred C behaviour.

DAIDE protocol semantics:
  NOT (CCD (power))  — Server announces a power is NO LONGER in civil disorder
                        (reconnected). Reverses a prior CCD announcement.
  NOT (TME (seconds)) — Server rejects a TME (time extension) request.
                         Albert should note that extra time was not granted.
"""

import logging as _logging

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups

_log = _logging.getLogger(__name__)

_DAIDE_POWERS = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]


def handle_not_ccd(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle NOT ( CCD ( power ) ) — power reconnected (no longer in civil disorder).

    Port of FUN_0045e9f0.

    C behaviour (inferred): removes the power from the civil-disorder set,
    re-enabling it as an active negotiation partner. The CCD handler
    (FUN_0045e470) sets the power as disconnected; NOT(CCD) reverses that.

    Args:
        state: InnerGameState.
        full_message: the complete NOT message string.
        inner_group: the content inside NOT( CCD( ... ) ), e.g. "ENG".
    """
    # Extract power from CCD body
    # CCD body contains a single power token: CCD ( power )
    ccd_groups = _extract_top_paren_groups(inner_group)
    if ccd_groups:
        power_str = ccd_groups[0].strip().upper()
    else:
        # inner_group itself might be "CCD ENG" or just the tokens after CCD
        tokens = inner_group.split()
        # Skip 'CCD' if present
        power_str = ''
        for t in tokens:
            t_upper = t.strip('()').upper()
            if t_upper in _DAIDE_POWERS:
                power_str = t_upper
                break

    if power_str in _DAIDE_POWERS:
        power_idx = _DAIDE_POWERS.index(power_str)
        # Remove from civil disorder set
        state.g_ccd_powers.discard(power_idx)
        _log.info("handle_not_ccd: %s(%d) reconnected — removed from CCD set",
                  power_str, power_idx)
    else:
        _log.warning("handle_not_ccd: could not extract power from %r", inner_group)


def handle_not_tme(state: InnerGameState, full_message: str, inner_group: str) -> None:
    """
    Handle NOT ( TME ( seconds ) ) — server rejects time-extension request.

    Port of vtable slot +0x50.

    C behaviour (inferred): the server declined our TME request. Albert
    notes the rejection but takes no special action — the press-scheduling
    code already has time-limit guards that work without extensions.

    Args:
        state: InnerGameState.
        full_message: the complete NOT message string.
        inner_group: the content inside NOT( TME( ... ) ), e.g. "300".
    """
    # Extract the requested seconds from the TME body
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

    _log.info("handle_not_tme: time extension rejected (requested=%s)", secs_str)
    # No state mutation needed — Albert's scheduling already respects
    # g_move_time_limit_sec from the HST/MTL parse.


def handle_not_unknown(state: InnerGameState, full_message: str, variant_group: str) -> None:
    """
    Handle NOT ( ... ) — unknown NOT variant (fallback).

    Port of vtable slot +0xc0.

    C behaviour (inferred): logs the unexpected NOT variant. Most NOT
    variants that Albert doesn't handle are server-level rejections of
    proposals we never send (NOT(GOF), NOT(DRW), etc.).

    The FRM-level NOT handling (NOT inside press envelopes) is already
    handled by process_frm_message → ack_matcher with _ACK_TOK_REJ.
    This handler covers bare top-level NOT from the server.

    Args:
        state: InnerGameState.
        full_message: the complete NOT message string.
        variant_group: the first paren group content from the NOT body.
    """
    _log.warning("handle_not_unknown: unhandled NOT variant: %r (message=%r)",
                 variant_group[:80], full_message[:120])
