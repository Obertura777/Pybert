"""Top-level server message handlers — MAP, MDF, ORD, SCO, REJ, CCD, OUT,
HUH, MIS, OFF, SVE, THX, TME, ADM, LOD.

Ported during the 2026-04 handler port.

These are the 15 top-level DAIDE message types that inbound_daide_dispatcher
routes to but previously had only logging stubs. Most are server→bot
informational messages that python-diplomacy also handles natively;
these handlers maintain Albert's internal state mirrors for consistency
with the C binary's data model.

C reference addresses (from InboundDAIDEDispatcher.c):
  MAP → FUN_0045e310        MDF → FUN_0045ad50
  ORD → FUN_0045aee0        SCO → FUN_0045af10
  REJ → FUN_0045d600        CCD → FUN_0045e470
  OUT → FUN_0045d180        HUH → vtable +0x20 (HUH.c)
  LOD → vtable +0x24        MIS → vtable +0x28
  OFF → vtable +0x2c        SVE → vtable +0x3c
  THX → vtable +0x40        TME → vtable +0x44
  ADM → vtable +0x48

No separate C source files exist for most of these (only HUH.c).
Implementations are derived from DAIDE protocol specification.
"""

import logging as _logging

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups

_log = _logging.getLogger(__name__)

_DAIDE_POWERS = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]


# ═══════════════════════════════════════════════════════════════════════════
# MAP — server sends map name
# ═══════════════════════════════════════════════════════════════════════════

def handle_map(state: InnerGameState, message: str) -> None:
    """
    Handle MAP ( map_name ) — server announces the game's map.

    Port of FUN_0045e310.

    DAIDE: MAP ( 'standard' )

    C behaviour (inferred): stores the map name, then sends MDF request
    to get the map definition. In python-diplomacy the map is loaded by
    diplomacy.Game; we store the name for reference and log it.
    """
    groups = _extract_top_paren_groups(message)
    if groups:
        map_name = groups[0].strip()
        state.g_map_name = map_name
        _log.info("handle_map: map=%s", map_name)
    else:
        _log.warning("handle_map: no map name in message: %r", message[:100])


# ═══════════════════════════════════════════════════════════════════════════
# MDF — server sends map definition (provinces, adjacencies, etc.)
# ═══════════════════════════════════════════════════════════════════════════

def handle_mdf(state: InnerGameState, message: str) -> None:
    """
    Handle MDF ( powers ) ( provinces ) ( adjacencies ) — map definition.

    Port of FUN_0045ad50.

    DAIDE: MDF ( power_list ) ( supply_centres ) ( adjacencies )

    C behaviour (inferred): parses the full map topology — provinces,
    adjacency lists, supply-centre ownership. In python-diplomacy, the
    map is loaded from Map objects; we store the raw MDF data for
    reference but do not parse it into the adjacency model.
    """
    groups = _extract_top_paren_groups(message)
    state.g_mdf_data = groups if groups else []
    _log.info("handle_mdf: received MDF with %d groups", len(groups) if groups else 0)


# ═══════════════════════════════════════════════════════════════════════════
# ORD — server sends adjudicated order results
# ═══════════════════════════════════════════════════════════════════════════

def handle_ord(state: InnerGameState, message: str) -> None:
    """
    Handle ORD ( turn ) ( order ) ( result ) — adjudicated order result.

    Port of FUN_0045aee0.

    DAIDE: ORD ( season year ) ( order ) ( SUC | BNC | CUT | DSR | NSO | RET )

    C behaviour (inferred): records the adjudication result for each order
    in the previous phase. Used for:
      1. Learning from failed orders (convoy cuts, bounces).
      2. Updating trust/hostility scores based on what others actually did
         vs what they promised in press.

    We store the results for downstream analysis.
    """
    groups = _extract_top_paren_groups(message)
    if len(groups) >= 2:
        turn_str = groups[0].strip()
        # Remaining groups are order/result pairs
        result_entry = {
            'turn': turn_str,
            'groups': groups[1:],
            'raw': message,
        }
        state.g_ord_results.append(result_entry)
        _log.debug("handle_ord: turn=%s result_groups=%d",
                   turn_str, len(groups) - 1)
    else:
        _log.warning("handle_ord: message too short: %r", message[:100])


# ═══════════════════════════════════════════════════════════════════════════
# SCO — server sends supply centre ownership
# ═══════════════════════════════════════════════════════════════════════════

def handle_sco(state: InnerGameState, message: str) -> None:
    """
    Handle SCO ( power sc sc ... ) ( power sc sc ... ) ... — SC ownership.

    Port of FUN_0045af10.

    DAIDE: SCO ( AUS BUD TRI VIE ) ( ENG EDI LON LVP ) ...

    C behaviour (inferred): updates the per-power supply-centre count
    and ownership arrays. In python-diplomacy, Game.get_centers() provides
    this; we mirror to g_sco_power_sc_count for C-faithful state tracking.
    """
    groups = _extract_top_paren_groups(message)
    if not groups:
        _log.warning("handle_sco: no groups in message: %r", message[:100])
        return

    import numpy as np
    state.g_sco_power_sc_count[:] = 0

    for group in groups:
        tokens = group.split()
        if not tokens:
            continue
        power_str = tokens[0].upper()
        if power_str in _DAIDE_POWERS:
            power_idx = _DAIDE_POWERS.index(power_str)
            # Remaining tokens are supply centre names
            sc_count = len(tokens) - 1
            state.g_sco_power_sc_count[power_idx] = sc_count
            _log.debug("handle_sco: %s has %d SCs", power_str, sc_count)
        elif power_str == 'UNO':
            # Unowned SCs — track count for reference
            _log.debug("handle_sco: %d unowned SCs", len(tokens) - 1)

    _log.info("handle_sco: SC counts = %s", list(state.g_sco_power_sc_count))


# ═══════════════════════════════════════════════════════════════════════════
# REJ — server rejects a message we sent
# ═══════════════════════════════════════════════════════════════════════════

def handle_rej(state: InnerGameState, message: str) -> None:
    """
    Handle REJ ( original_message ) — server rejects our message.

    Port of FUN_0045d600.

    DAIDE: REJ ( NME ... ) | REJ ( IAM ... ) | REJ ( GOF ) | etc.

    C behaviour (inferred): handles server-level rejections. The body
    echoes the message that was rejected. Common cases:
      REJ(NME) — name rejected, try different name
      REJ(IAM) — reconnect auth failed
      REJ(GOF) — go-flag rejected (missing orders?)

    Albert logs the rejection. Critical rejections (NME, IAM) would
    require connection-layer retry logic which python-diplomacy handles.
    """
    groups = _extract_top_paren_groups(message)
    rejected_msg = groups[0] if groups else message
    rejected_tokens = rejected_msg.split()
    rejected_type = rejected_tokens[0].upper() if rejected_tokens else 'UNKNOWN'

    _log.warning("handle_rej: server rejected our %s: %r",
                 rejected_type, rejected_msg[:100])

    # If GOF was rejected, clear the GOF-sent flag so we can retry
    if rejected_type == 'GOF':
        state.g_gof_sent = False


# ═══════════════════════════════════════════════════════════════════════════
# CCD — server announces a power is in civil disorder (disconnected)
# ═══════════════════════════════════════════════════════════════════════════

def handle_ccd(state: InnerGameState, message: str) -> None:
    """
    Handle CCD ( power ) — power is in civil disorder (disconnected).

    Port of FUN_0045e470.

    DAIDE: CCD ( FRA )

    C behaviour (inferred): marks the power as disconnected / in civil
    disorder. Orders for CCD powers are submitted as HOLD by the server.
    Albert should:
      1. Add the power to g_ccd_powers set.
      2. Treat them as non-negotiable for press purposes.
      3. Potentially adjust scoring (CCD powers are weaker targets).
    """
    groups = _extract_top_paren_groups(message)
    if groups:
        power_str = groups[0].strip().upper()
    else:
        tokens = message.split()
        power_str = ''
        for t in tokens:
            t_upper = t.strip('()').upper()
            if t_upper in _DAIDE_POWERS:
                power_str = t_upper
                break

    if power_str in _DAIDE_POWERS:
        power_idx = _DAIDE_POWERS.index(power_str)
        state.g_ccd_powers.add(power_idx)
        _log.info("handle_ccd: %s(%d) is in civil disorder", power_str, power_idx)
    else:
        _log.warning("handle_ccd: could not extract power from %r", message[:100])


# ═══════════════════════════════════════════════════════════════════════════
# OUT — server announces a power has been eliminated
# ═══════════════════════════════════════════════════════════════════════════

def handle_out(state: InnerGameState, message: str) -> None:
    """
    Handle OUT ( power ) — power has been eliminated from the game.

    Port of FUN_0045d180.

    DAIDE: OUT ( ITA )

    C behaviour (inferred): marks the power as eliminated.
    Eliminated powers hold no SCs and have no units. Albert should:
      1. Add the power to g_out_powers set.
      2. Remove them from alliance/hostility tracking.
      3. Skip them in press generation.
    """
    groups = _extract_top_paren_groups(message)
    if groups:
        power_str = groups[0].strip().upper()
    else:
        tokens = message.split()
        power_str = ''
        for t in tokens:
            t_upper = t.strip('()').upper()
            if t_upper in _DAIDE_POWERS:
                power_str = t_upper
                break

    if power_str in _DAIDE_POWERS:
        power_idx = _DAIDE_POWERS.index(power_str)
        state.g_out_powers.add(power_idx)
        # Also add to CCD since eliminated powers are trivially disconnected
        state.g_ccd_powers.add(power_idx)
        _log.info("handle_out: %s(%d) has been eliminated", power_str, power_idx)
    else:
        _log.warning("handle_out: could not extract power from %r", message[:100])


# ═══════════════════════════════════════════════════════════════════════════
# HUH — server sends error/confusion about a message we sent
# ═══════════════════════════════════════════════════════════════════════════

def handle_huh(state: InnerGameState, message: str) -> None:
    """
    Handle HUH ( error_message ) — server could not parse our message.

    Port of HUH handler (Source/communications/HUH.c).

    C implementation (25 lines):
      FUN_0046b050(param_1, local_28)  — serialize token list to string
      ERR("HUH message received : %s")  — log the error

    This is a diagnostic: the server inserts ERR tokens at positions in
    our original message where parsing failed. We log the full message
    for debugging.
    """
    _log.warning("handle_huh: HUH message received: %s", message[:200])


# ═══════════════════════════════════════════════════════════════════════════
# MIS — server announces missing orders for the current phase
# ═══════════════════════════════════════════════════════════════════════════

def handle_mis(state: InnerGameState, message: str) -> None:
    """
    Handle MIS ( unit unit ... ) — server reports missing orders.

    DAIDE: MIS ( FRA A PAR ) ( FRA F BRE )

    The server sends MIS when not all units have been given orders.
    This is a reminder/prompt for Albert to submit orders for the
    listed units. Albert's order-generation loop should already
    produce orders for all units, so this is primarily diagnostic.
    """
    groups = _extract_top_paren_groups(message)
    state.g_mis_powers = []
    for group in (groups or []):
        tokens = group.split()
        if tokens and tokens[0].upper() in _DAIDE_POWERS:
            power_idx = _DAIDE_POWERS.index(tokens[0].upper())
            state.g_mis_powers.append({
                'power': power_idx,
                'unit_tokens': tokens[1:],
            })
    _log.warning("handle_mis: %d units missing orders", len(state.g_mis_powers))


# ═══════════════════════════════════════════════════════════════════════════
# OFF — server announces game is over (server shutting down)
# ═══════════════════════════════════════════════════════════════════════════

def handle_off(state: InnerGameState, message: str) -> None:
    """
    Handle OFF — server is shutting down, game is over.

    DAIDE: OFF

    Sets both g_off_received and g_game_over so the bot's main loop exits.
    """
    state.g_off_received = True
    state.g_game_over = True
    _log.info("handle_off: server is shutting down — game over")


# ═══════════════════════════════════════════════════════════════════════════
# SVE — server sends save-game notification
# ═══════════════════════════════════════════════════════════════════════════

def handle_sve(state: InnerGameState, message: str) -> None:
    """
    Handle SVE ( game_name ) — server has saved the game.

    DAIDE: SVE ( 'my_game' )

    C behaviour (inferred): stores the game name for potential LOD
    (load) reference. No action needed from Albert.
    """
    groups = _extract_top_paren_groups(message)
    if groups:
        state.g_sve_game_name = groups[0].strip()
        _log.info("handle_sve: game saved as %r", state.g_sve_game_name)
    else:
        _log.info("handle_sve: save notification (no name)")


# ═══════════════════════════════════════════════════════════════════════════
# THX — server acknowledges our order submission
# ═══════════════════════════════════════════════════════════════════════════

def handle_thx(state: InnerGameState, message: str) -> None:
    """
    Handle THX ( order ) ( result ) — order acknowledgment.

    DAIDE: THX ( FRA A PAR - BUR ) ( MBV )
           THX ( FRA A PAR - BUR ) ( FAR )  — failure: too far

    Result codes:
      MBV — order is OK (MoveBounceVoid — accepted even if it might bounce)
      FAR — unit too far from destination
      NSP — no such province
      NSU — no such unit
      NAS — not at sea (army trying to convoy)
      NSF — no such fleet
      NSA — no such army
      NYU — not your unit
      NRN — no retreat needed
      NVR — not a valid retreat destination
      YSC — not a valid build location
      ESC — not an empty supply centre
      ADJ — wrong phase (adjustment needed)
      RTO — wrong phase (retreat needed)
      NMR — no more room (max units reached)
      NMB — no more builds available
      NRS — no more retreats for this unit

    Albert should check if any submitted order was rejected and potentially
    resubmit with a fallback order (typically HOLD).
    """
    groups = _extract_top_paren_groups(message)
    if len(groups) >= 2:
        order_str = groups[0].strip()
        result_str = groups[1].strip()
        state.g_thx_results.append({
            'order': order_str,
            'result': result_str,
        })
        if result_str != 'MBV':
            _log.warning("handle_thx: order REJECTED: %s → %s", order_str, result_str)
        else:
            _log.debug("handle_thx: order accepted: %s", order_str)
    else:
        _log.warning("handle_thx: message too short: %r", message[:100])


# ═══════════════════════════════════════════════════════════════════════════
# TME — server sends time remaining notification
# ═══════════════════════════════════════════════════════════════════════════

def handle_tme(state: InnerGameState, message: str) -> None:
    """
    Handle TME ( seconds ) — time remaining for current phase.

    DAIDE: TME ( 120 )

    This is an informational message from the server about how much
    time remains. Albert's Monte Carlo loop already tracks time via
    check_time_limit; this updates the remaining-time reference.
    """
    groups = _extract_top_paren_groups(message)
    if groups:
        secs_str = groups[0].strip()
        try:
            remaining = int(secs_str)
            _log.debug("handle_tme: %d seconds remaining", remaining)
            # Update time tracking so MC loop can use it
            import time as _time
            state.g_tme_deadline = _time.time() + remaining
        except ValueError:
            _log.warning("handle_tme: invalid seconds %r", secs_str)
    else:
        _log.debug("handle_tme: bare TME notification")


# ═══════════════════════════════════════════════════════════════════════════
# ADM — server sends admin message (human-readable text)
# ═══════════════════════════════════════════════════════════════════════════

def handle_adm(state: InnerGameState, message: str) -> None:
    """
    Handle ADM ( name ) ( message ) — admin/broadcast text message.

    DAIDE: ADM ( 'Server' ) ( 'Game will end in 5 minutes' )

    Informational only — no game-state impact.
    """
    groups = _extract_top_paren_groups(message)
    if len(groups) >= 2:
        sender = groups[0].strip()
        text = groups[1].strip()
        state.g_adm_message = text
        _log.info("handle_adm: [%s] %s", sender, text)
    elif groups:
        state.g_adm_message = groups[0].strip()
        _log.info("handle_adm: %s", groups[0][:200])
    else:
        _log.info("handle_adm: %s", message[:200])


# ═══════════════════════════════════════════════════════════════════════════
# LOD — server sends load-game notification
# ═══════════════════════════════════════════════════════════════════════════

def handle_lod(state: InnerGameState, message: str) -> None:
    """
    Handle LOD ( game_name ) — server is loading a saved game.

    DAIDE: LOD ( 'my_game' )

    After LOD, the server typically sends MAP, MDF, NOW, SCO to
    re-establish the game state. Albert will process those as they
    arrive. We log and store the game name.
    """
    groups = _extract_top_paren_groups(message)
    if groups:
        game_name = groups[0].strip()
        _log.info("handle_lod: loading game %r", game_name)
    else:
        _log.info("handle_lod: load notification")
