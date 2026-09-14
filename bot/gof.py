"""GOF (Go Order Final) DAIDE-token sequence builder + send/evaluate pipeline.

Split from bot.py during the 2026-04 refactor.

This submodule builds the Go-Order-Final token sequence from the per-turn
order table (``_build_gof_seq``), sends it on a ``send_dm`` channel
(``_send_gof``), and drives the ``EvaluateOrderProposalsAndSendGOF`` entry
point (``_evaluate_order_proposals_and_send_gof``).  Depends on
``.orders`` (movement/retreat token builders) and ``._shared`` (power-name
table); cross-package dep is ``..communications`` for scheduled-press
dispatch.  ``normalize_influence_matrix`` is pulled in via a deferred
function-body import to avoid a circular-import risk with ``..heuristics``.
"""

from __future__ import annotations

import logging
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ..state import InnerGameState

from ..communications import dispatch_scheduled_press
from ._shared import _DAIDE_POWER_NAMES
from .orders import _build_movement_order_token, _build_retreat_order_token

logger = logging.getLogger(__name__)



def _build_gof_seq(state: 'InnerGameState') -> list:
    """
    Port of FUN_00464460 — builds the DAIDE GOF+orders token sequence
    from the inner gamestate.

    C structure:
      1. Init output list (param_1) and working list (local_b8).
      2. Prepend DAT_004c77a0 = GOF (0x4803) to output.
      3. Phase-dependent order iteration:
           SPR/SUM  (0x4700/4701): iterate active unit list (this+0x2450/2454);
                    for each own unit (unit.power==own_power) with an order
                    (unit+0x20 != 0): FUN_00463690 builds the movement-order
                    token seq; FUN_00466c40 wraps it in parens and appends to output.
           FAL/AUT  (0x4702/4703): same pattern over retreat list (this+0x245c/2460);
                    FUN_00460110 builds the retreat-order token seq.
           WIN: iterate build list (this+0x2474/2478);
                    for each candidate append power_token + BLD(0x4380)/REM(0x4381)
                    + province + coast (DAT_004c7698 or DAT_004c769c per this+0x2488);
                    then for each waived build (count at this+0x2480) append WVE(0x4382).
      4. Each per-order entry is wrapped: ( order_tokens ) via FUN_00466c40.

    TokenSeq_Count in the caller counts list nodes; > 1 means at least one
    order entry is present (header alone = 1).

    FUN_00463690 = _build_movement_order_token (fully ported).
    SPR/SUM orders are read from state.unit_info (own-power units with non-zero order type).
    FAL/AUT orders are read from state.g_retreat_order_list (populated before _send_gof);
         only own-power nodes are emitted (mirrors C power check at iVar6+0x18).
    WIN:
      Build entries should come from the build-candidate list at this+0x2474/0x2478.
      Each candidate has province at +0x0c (int) and BLD/REM DAIDE token at +0x10 (short).
      this+0x2480 (int) = waive count → state.g_waive_count.
      this+0x2488 (char) = build/remove flag — encoded in g_build_order_list strings
        (each entry already contains 'BLD' or 'REM').
      g_build_order_list is populated by compute_win_builds (FUN_0044bd40) or
      compute_win_removes (FUN_00442040) before _send_gof is called.
      Unit-type (AMY/FLT): coastal → FLT, inland → AMY (confirmed by
      WIN candidate-set writers and ScoreOrderCandidates_OwnPower decompiles).
    """
    phase = getattr(state, 'g_season', 'SPR')
    own_power = getattr(state, 'albert_power_idx', 0)
    power_name = _DAIDE_POWER_NAMES[own_power] if 0 <= own_power < len(_DAIDE_POWER_NAMES) else 'UNO'

    # DAT_004c77a0 = GOF (0x4803) — always the first token
    seq: list = ['GOF']

    if phase in ('SPR', 'SUM'):
        # FUN_00463690 = _build_movement_order_token.
        # C: for each unit in active list (this+0x2450/2454):
        #   if unit.power (iVar6+0x18) == own_power (this+0x2424) AND
        #      unit.order_flag (iVar6+0x20) != 0:
        #     build token via FUN_00463690; FUN_00466c40 wraps in parens, appends to output.
        for prov, unit_data in state.unit_info.items():
            if unit_data.get('power') != own_power:
                continue
            tok = _build_movement_order_token(state, prov)
            if tok is not None:
                seq.append(f'( {tok} )')        # FUN_00466c40 wraps in parens
    elif phase in ('FAL', 'AUT'):
        # FUN_00460110 = _build_retreat_order_token.
        # C: for each unit in retreat list (this+0x245c/2460):
        #   if unit.power (iVar6+0x18) == own_power (this+0x2424) AND
        #      unit.order_flag (iVar6+0x20) != 0:
        #     build token; FUN_00466c40 wraps in parens, appends to output.
        # Power filter mirrors the C power check; g_retreat_order_list may contain
        # all powers' retreat units.
        for node in state.g_retreat_order_list:
            if node.get('power') != own_power:          # iVar6+0x18 == own_power check
                continue
            tok = _build_retreat_order_token(state, node)
            if tok is not None:
                seq.append(f'( {tok} )')          # FUN_00466c40 wraps in parens
    else:
        # WIN: BLD/REM per candidate (build list this+0x2474/2478) +
        #      WVE per waiver (count at this+0x2480).
        # DAT values (all confirmed — see DaideTokenEncoding.md token table at 0x004c7670):
        #   DAT_004c7670 = AMY (0x4200)
        #   DAT_004c7674 = FLT (0x4201)
        #   DAT_004c7698 = BLD (0x4380)
        #   DAT_004c769c = REM (0x4381)
        #   DAT_004c76a0 = WVE (0x4382)
        # C per-candidate:
        #   1. [POWER] from this+0x2424
        #   2. If *(short*)(iVar3+0x10) == AMY: append AMY; else append FLT → [POWER, AMY/FLT]
        #      (iVar3+0x10 = unit type token: AMY=0x4200 or FLT=0x4201)
        #   3. Province from iVar3+0x0c; CONCAT22(0x46, 0x42xx) → byte1=0x42≠0x46 → no coast
        #      → [POWER, FLT/AMY, PROV]
        #   4. FUN_00465aa0 wraps → ( POWER FLT/AMY PROV )  ← standard DAIDE unit spec
        #   5. If this+0x2488 == 0: append REM (remove phase); else append BLD (build phase)
        #   6. FUN_00466c40 wraps all → ( ( POWER FLT/AMY PROV ) BLD/REM )  ← standard DAIDE ✓
        # this+0x2488 = 0 → remove phase; != 0 → build phase.
        # g_build_order_list: populated by WIN handler; cleared by ResetPerTrialState.
        for order in state.g_build_order_list:
            seq.append(f'( {order} )')
        # WVE: C calls FUN_00466540(own_power_tok, ..., WVE) → [own_power, WVE].
        # AppendSeq wraps to ( own_power WVE ). Per DAIDE spec: "power WVE".
        waive_count: int = state.g_waive_count
        for _ in range(waive_count):
            seq.append(f'( {power_name} WVE )')  # DAT_004c76a0=WVE; power from this+0x2424

    return seq


def _send_gof(state: 'InnerGameState', send_dm) -> None:
    """
    The GOF send at the end of AwaitPressAndSendGOF (0x00443ed0).

    C sends ``GOF`` and clears DAT_00baed47 (``g_cancel_press_sent``), the
    flag CancelPriorPress sets when it withdraws readiness with NOT(GOF), so
    the next NOT(GOF) and GOF pair can follow.  In python-diplomacy the GOF
    token is ``game.no_wait()``.  (The order SUB itself is FUN_0045aa40,
    which the client submits through ``set_orders``.)
    """
    _build_gof_seq(state)
    send_dm('GOF')
    state.g_gof_sent = True
    state.g_cancel_press_sent = 0


# ── EvaluateOrderProposalsAndSendGOF ─────────────────────────────────────────

def _evaluate_order_proposals_and_send_gof(
    state: 'InnerGameState',
    send_dm,
    send_gof_fn=None,
) -> None:
    """
    Port of FUN_00457520 = EvaluateOrderProposalsAndSendGOF.

    Walks g_pos_analysis_list (DAT_00bb65c8) for unprocessed proposals every
    participant has answered, and applies the ones nobody rejected.

    C node layout (undefined4* offsets from the list node):
      +8   (node+0x20)  processed byte
      +0xc (node+0x30)  participant set
      +0xf (node+0x3c)  responded set — every power that answered
      +0x12(node+0x48)  rejection set; [0x14] (node+0x50) is its size
      +0x15(node+0x54)  clause list; [0x16] its head

    C flow per unprocessed node:
      * every participant found in the responded set → set the processed
        byte (a rejected proposal is retired too);
      * rejection set empty → clear DAT_00bb65e0 and copy the participant set
        into it (RegisterProposalOrders), then for each clause call
        CAL_MOVE(clause, copy of the responded set); CAL_MOVE == 1 → bVar4.
    Finally bVar4 → NormalizeInfluenceMatrix + send_GOF (the whole order
    generation pass, re-run with the applied agreements); otherwise
    ScheduledPressDispatch.

    ``send_gof_fn`` (or ``state.g_send_gof_callback``) is that send_GOF pass;
    without one the GOF readiness signal is sent instead.
    """
    from ..communications import dispatch_scheduled_press, cal_move
    from ..heuristics import normalize_influence_matrix

    bVar4 = False
    for entry in getattr(state, 'g_pos_analysis_list', []):
        if (entry.get('board_satisfied', False)
                or entry.get('processed', False)
                or entry.get('processed_flag', 0) != 0):
            continue

        participants = set(entry.get('participant_powers', set()))
        responded = set(entry.get('role_b_set', set()))
        if not participants.issubset(responded):
            continue

        entry['board_satisfied'] = True
        entry['processed'] = True
        entry['processed_flag'] = 1

        if entry.get('role_c_set'):
            continue

        # SerializeOrders + RegisterProposalOrders(DAT_00bb65e0, node+0x30).
        # DAT_00bb65e0 is the same global the DMZ handler uses
        # (state.g_dmz_order_list); both writers clear and rewrite it.
        if not hasattr(state, 'g_dmz_order_list') or state.g_dmz_order_list is None:
            state.g_dmz_order_list = []
        state.g_dmz_order_list.clear()
        state.g_dmz_order_list.extend(
            {'owner_power': int(power)} for power in sorted(participants)
        )

        for pe in list(entry.get('press_entries', [])):
            # FUN_00405090 copies the responded set; XDO()/NOT_XDO() read it
            # as in_stack_00000018, one std::set<int> key per power.
            state.g_xdo_candidate_list = [
                {'power': int(power)} for power in sorted(responded)
            ]
            tokens = pe.get('tokens', []) if isinstance(pe, dict) else list(pe)
            if cal_move(state, tokens):
                bVar4 = True

    if bVar4:
        normalize_influence_matrix(state)
        callback = send_gof_fn or getattr(state, 'g_send_gof_callback', None)
        if callback is not None:
            callback()
        elif send_dm is not None:
            _send_gof(state, send_dm)
    else:
        dispatch_scheduled_press(state, send_dm)
