"""HLO (Hello) message handler — server announces bot identity and game variant.

Split from the dispatcher stub during the 2026-04 handler port.

Port of HLO_Dispatch (FUN_0045abf0, Source/communications/HLO_Dispatch.c).

DAIDE message shape:
  HLO ( power ) ( passcode ) ( variant... )

Inner-state writes (C offsets relative to inner_state pointer):
  +0x2424 — our-power byte (albert_power_idx)
  +0x2428 — passcode (sign-extended from 14-bit DAIDE token)
  +0x242c — variant TokenList (appended in-place)
  +0x2448 — "HLO received" flag set to 1

After setting state, C calls vtable slot +0xd4 (subclass OnHLO hook).
In Python the diplomacy.Game layer handles variant/reconnect natively;
the OnHLO hook is a no-op stub.
"""

import logging as _logging

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups

_log = _logging.getLogger(__name__)

# 3-letter DAIDE power codes, index-aligned with the 7 standard powers.
_DAIDE_POWERS = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]


def hlo_dispatch(state: InnerGameState, message: str) -> None:
    """
    Parse HLO message and initialize bot identity state.

    Port of FUN_0045abf0 (Source/communications/HLO_Dispatch.c).

    HLO message format:
      HLO ( power ) ( passcode ) ( variant_token variant_token ... )

    Examples:
      HLO ( FRA ) ( 1234 ) ( LVL 10 )
      HLO ( ENG ) ( -42 ) ( LVL 20 MTL 300 )

    Args:
        state: InnerGameState to populate with identity info.
        message: raw HLO message string.
    """
    groups = _extract_top_paren_groups(message)
    if len(groups) < 2:
        _log.warning("hlo_dispatch: message too short (need power+passcode): %r",
                     message[:100])
        return

    # ── Extract power (group[0]) ──────────────────────────────────────────
    # C: GetSubList(param_1, buf, 1) → extract element [1] (power)
    #    FUN_004658f0 → first token; FUN_00460de0 → write decoded power-index
    #    byte into inner+0x2424.
    power_str = groups[0].strip().upper()
    if power_str in _DAIDE_POWERS:
        power_idx = _DAIDE_POWERS.index(power_str)
    else:
        # Try numeric parse (raw DAIDE token value — low byte is power index)
        try:
            raw_tok = int(power_str, 0)
            power_idx = raw_tok & 0xff
            if power_idx >= 7:
                _log.warning("hlo_dispatch: power index %d out of range", power_idx)
                return
        except ValueError:
            _log.warning("hlo_dispatch: unknown power %r", power_str)
            return

    state.albert_power_idx = power_idx
    state.g_albert_power = power_idx  # keep mirror in sync

    # ── Extract passcode (group[1]) ───────────────────────────────────────
    # C: sign-extend from 14-bit DAIDE field:
    #   uVar3 = (uint)*puVar2
    #   if ((*puVar2 & 0x2000) != 0) uVar3 = uVar3 | 0xffffe000
    #   *(uint*)(inner + 0x2428) = uVar3
    passcode_str = groups[1].strip()
    try:
        raw_passcode = int(passcode_str)
        # Sign-extend from 14 bits (bit 13 is sign bit)
        if raw_passcode & 0x2000:
            raw_passcode = raw_passcode | ~0x1fff  # sign-extend
        state.g_passcode = raw_passcode
    except ValueError:
        _log.warning("hlo_dispatch: invalid passcode %r", passcode_str)
        state.g_passcode = 0

    # ── Extract variant list (group[2:]) ──────────────────────────────────
    # C: GetSubList(this_00, buf, 3) → AppendList(inner + 0x242c, buf)
    # The variant list is the third group onward; may contain multiple tokens.
    variant_tokens = []
    if len(groups) >= 3:
        for g in groups[2:]:
            variant_tokens.extend(g.split())
    state.g_variant_list = variant_tokens

    # ── Set "HLO received" flag ───────────────────────────────────────────
    # C: *(undefined1*)(inner + 0x2448) = 1
    state.g_hlo_received = True

    _log.info("hlo_dispatch: power=%s(%d) passcode=%d variants=%s",
              _DAIDE_POWERS[power_idx] if power_idx < 7 else '?',
              power_idx, state.g_passcode, variant_tokens)

    # ── OnHLO vtable hook (+0xd4) ─────────────────────────────────────────
    # C: (**(code**)(*(int*)this + 0xd4))()
    # In Python the diplomacy.Game layer handles variant init and reconnection
    # natively. If process_hst needs to run on the variant list, it would be
    # triggered here. For now this is a no-op stub.
    # TODO: if variant list contains LVL, trigger process_hst-like init.
    if variant_tokens:
        # Synthesize an HST-like message from variant tokens so that
        # process_hst can set g_history_counter and allowed-press maps.
        from .history import process_hst
        hst_msg = ' '.join(variant_tokens)
        process_hst(state, hst_msg)
