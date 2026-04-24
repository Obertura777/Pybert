"""Inbound DAIDE message dispatcher — routes to per-token handlers.

Split from communications/inbound.py during the 2026-04 refactor.
Handler stubs ported 2026-04-21.

Holds the dispatcher suite that routes raw inbound DAIDE messages to per-token
handlers:

  * ``inbound_daide_dispatcher`` — top-level router; dispatches all DAIDE
    tokens to appropriate handlers.
  * ``not_dispatcher``           — routes NOT variants (CCD/TME/fallback).
  * ``yes_dispatcher``           — routes YES variants (NME/OBS/IAM/NOT/GOF/TME/DRW/SND).

Cross-module deps: ``...state.InnerGameState``, submodule handlers from
``.hlo``, ``.now_parser``, ``.frm``, ``.not_handlers``, ``.yes_handlers``,
``.server_handlers``.

C References:
  * InboundDAIDEDispatcher = FUN_0045f1f0 (Source/communications/InboundDAIDEDispatcher.c)
  * YESDispatcher          = FUN_0045c640 (Source/communications/YESDispatcher.c)
  * NOTDispatcher          = FUN_0045c5e0 (Source/communications/NOTDispatcher.c)
"""

import logging as _logging

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups, _split_top_level_groups
from .frm import process_frm_message
from .now_parser import parse_now
from .hlo import hlo_dispatch
from .not_handlers import handle_not_ccd, handle_not_tme, handle_not_unknown
from .yes_handlers import (
    handle_yes_nme, handle_yes_obs, handle_yes_iam, handle_yes_not,
    handle_yes_gof, handle_yes_tme, handle_yes_drw, handle_yes_snd,
    handle_yes_unknown,
)
from .server_handlers import (
    handle_map, handle_mdf, handle_ord, handle_sco, handle_rej,
    handle_ccd, handle_out, handle_huh, handle_mis, handle_off,
    handle_sve, handle_thx, handle_tme, handle_adm, handle_lod,
)

_log = _logging.getLogger(__name__)


def not_dispatcher(state: InnerGameState, message: str):
    """
    Route NOT message variants.

    Port of NOTDispatcher (Source/communications/NOTDispatcher.c).

    C structure:
      GetSubList(param_1, local_2c, 1)  — extract first sub-list
      GetListElement(local_2c, &param_1, 0)  — get first token
      if (CCD == *psVar3):
          FUN_0045e9f0(this, pvVar1, GetSubList(local_2c, local_1c, 1))
      elif (TME == *psVar3):
          vtable+0x50(pvVar1, GetSubList(local_2c, local_1c, 1))
      else:
          vtable+0xc0(pvVar1)

    NOT messages have the form:
      NOT ( CCD ( ... ) )  — power reconnected / CCD cancelled
      NOT ( TME ( ... ) )  — time extension rejected
      NOT ( ... )          — unknown variant (fallback)

    Args:
        state: InnerGameState
        message: NOT message string
    """
    groups = _extract_top_paren_groups(message)
    if not groups:
        _log.warning("not_dispatcher: no groups in message: %r", message[:100])
        return

    variant_group = groups[0]
    variant_tokens = variant_group.split()
    if not variant_tokens:
        _log.warning("not_dispatcher: empty variant group")
        return

    variant_type = variant_tokens[0].upper()

    if variant_type == 'CCD':
        handle_not_ccd(state, message, variant_group)

    elif variant_type == 'TME':
        handle_not_tme(state, message, variant_group)

    else:
        handle_not_unknown(state, message, variant_group)


def yes_dispatcher(state: InnerGameState, message: str):
    """
    Route YES message variants.

    Port of YESDispatcher (Source/communications/YESDispatcher.c).

    C structure:
      GetSubList(param_1, local_2c, 1)  — extract first sub-list
      for each variant: GetListElement → check token → dispatch

    YES messages acknowledge proposals:
      YES ( NME ... )  → handle_yes_nme   (name handshake accepted)
      YES ( OBS ... )  → handle_yes_obs   (observer accepted)
      YES ( IAM ... )  → handle_yes_iam   (reconnect accepted)
      YES ( NOT ... )  → handle_yes_not   (NOT cancellation accepted)
      YES ( GOF ... )  → handle_yes_gof   (go-flag accepted)
      YES ( TME ... )  → handle_yes_tme   (time extension granted)
      YES ( DRW ... )  → handle_yes_drw   (draw vote accepted)
      YES ( SND ... )  → handle_yes_snd   (press delivery confirmed)
      YES ( ... )      → handle_yes_unknown (fallback)

    Args:
        state: InnerGameState
        message: YES message string
    """
    groups = _extract_top_paren_groups(message)
    if not groups:
        _log.warning("yes_dispatcher: no groups in message: %r", message[:100])
        return

    variant_group = groups[0]
    variant_tokens = variant_group.split()
    if not variant_tokens:
        _log.warning("yes_dispatcher: empty variant group")
        return

    variant_type = variant_tokens[0].upper()

    _YES_HANDLERS = {
        'NME': handle_yes_nme,
        'OBS': handle_yes_obs,
        'IAM': handle_yes_iam,
        'NOT': handle_yes_not,
        'GOF': handle_yes_gof,
        'TME': handle_yes_tme,
        'DRW': handle_yes_drw,
        'SND': handle_yes_snd,
    }

    handler = _YES_HANDLERS.get(variant_type)
    if handler is not None:
        handler(state, message, variant_group)
    else:
        handle_yes_unknown(state, message, variant_group)


def inbound_daide_dispatcher(state: InnerGameState, message: str):
    """
    Top-level DAIDE inbound message dispatcher.

    Port of InboundDAIDEDispatcher (FUN_0045f1f0, Source/communications/InboundDAIDEDispatcher.c).

    Routes incoming DAIDE messages on first token to per-handler callbacks.
    All handlers are now ported (2026-04-21).

    Token routing:
      HLO → hlo_dispatch           (extract power, passcode, variant list, set HLO flag)
      MAP → handle_map             (store map name)
      MDF → handle_mdf             (store map definition)
      NOW → parse_now              (extract turn info, unit positions)
      ORD → handle_ord             (store adjudicated order results)
      SCO → handle_sco             (store SC ownership)
      NOT → not_dispatcher         (routes CCD/TME/fallback)
      REJ → handle_rej             (server rejects our message)
      YES → yes_dispatcher         (routes NME/OBS/IAM/NOT/GOF/TME/DRW/SND)
      CCD → handle_ccd             (power in civil disorder)
      OUT → handle_out             (power eliminated)
      DRW → game-over              (bare top-level draw)
      SLO → game-over              (bare top-level sole survivor)
      FRM → process_frm_message    (press envelope dispatcher)
      HUH → handle_huh             (server parse error)
      LOD → handle_lod             (load game notification)
      MIS → handle_mis             (missing orders)
      OFF → handle_off             (server shutdown)
      SVE → handle_sve             (save game notification)
      THX → handle_thx             (order acknowledgment)
      TME → handle_tme             (time remaining)
      ADM → handle_adm             (admin message)

    Args:
        state: InnerGameState
        message: raw inbound DAIDE message string
    """
    # Tokenize first token
    stripped = message.lstrip().lstrip('(').lstrip()
    first_token = stripped.split(None, 1)[0].upper() if stripped else ''

    if not first_token:
        _log.warning("inbound_daide_dispatcher: empty message")
        return

    _log.debug("inbound_daide_dispatcher: routing first_token=%r", first_token)

    # ── Direct function-call handlers (C calls by address) ─────────────────
    if first_token == 'HLO':
        hlo_dispatch(state, message)

    elif first_token == 'MAP':
        handle_map(state, message)

    elif first_token == 'MDF':
        handle_mdf(state, message)

    elif first_token == 'NOW':
        parse_now(state, message)

    elif first_token == 'ORD':
        handle_ord(state, message)

    elif first_token == 'SCO':
        handle_sco(state, message)

    elif first_token == 'NOT':
        not_dispatcher(state, message)

    elif first_token == 'REJ':
        handle_rej(state, message)

    elif first_token == 'YES':
        yes_dispatcher(state, message)

    elif first_token == 'CCD':
        handle_ccd(state, message)

    elif first_token == 'OUT':
        handle_out(state, message)

    # ── Game-end signals (bare top-level) ──────────────────────────────────
    # C: *(undefined1*)(*(int*)((int)this + 8) + 0x2449) = 1
    #    then vtable dispatch for per-subclass end-game hook
    elif first_token == 'DRW':
        _log.info("inbound_daide_dispatcher: DRW (game-over, bare top-level)")
        state.g_game_over = True

    elif first_token == 'SLO':
        _log.info("inbound_daide_dispatcher: SLO (game-over, bare top-level)")
        state.g_game_over = True

    # ── FRM envelope ───────────────────────────────────────────────────────
    elif first_token == 'FRM':
        process_frm_message(state, '', message)

    # ── Vtable-dispatched server messages ──────────────────────────────────
    elif first_token == 'HUH':
        handle_huh(state, message)

    elif first_token == 'LOD':
        handle_lod(state, message)

    elif first_token == 'MIS':
        handle_mis(state, message)

    elif first_token == 'OFF':
        handle_off(state, message)

    elif first_token == 'SVE':
        handle_sve(state, message)

    elif first_token == 'THX':
        handle_thx(state, message)

    elif first_token == 'TME':
        handle_tme(state, message)

    elif first_token == 'ADM':
        handle_adm(state, message)

    else:
        _log.warning("inbound_daide_dispatcher: unexpected first token %r", first_token)
