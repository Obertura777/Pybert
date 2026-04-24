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

import copy
import logging

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
      g_build_order_list is populated by compute_win_builds (FUN_00442040) or
      compute_win_removes (FUN_0044bd40) before _send_gof is called.
      Unit-type (AMY/FLT): coastal → FLT, inland → AMY (confirmed by
      FUN_00442040 / FUN_00461010 decompile; see docs/funcs/ComputeWinBuilds_Populate.md).
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
    Port of FUN_0045aa40 = send_GOF.

    Builds the GOF (Go Order Final) DAIDE token sequence from the inner
    gamestate (FUN_00464460 = _build_gof_seq) and transmits it via SendDM
    only when the sequence contains more than one token (non-empty guard).

    C flow:
      local_2c  = FUN_00465870()          // init temp list
      ppvVar1   = FUN_00464460(gamestate, local_1c)  // build GOF seq
      AppendList(local_2c, ppvVar1)
      FreeList(local_1c)
      if TokenSeq_Count(local_2c) > 1:
          puVar3 = FUN_00464460(gamestate, local_1c)  // rebuild for send
          SendDM(this, puVar3)
          FreeList(local_1c)
      FreeList(local_2c)
    """
    gof_seq = _build_gof_seq(state)          # FUN_00464460
    if len(gof_seq) > 1:                     # TokenSeq_Count(local_2c) > 1
        gof_seq = _build_gof_seq(state)      # FUN_00464460 — rebuild for send
        send_dm(gof_seq)                     # SendDM


# ── EvaluateOrderProposalsAndSendGOF ─────────────────────────────────────────

def _evaluate_order_proposals_and_send_gof(
    state: 'InnerGameState',
    send_dm,
) -> None:
    """
    Port of FUN_00457520 = EvaluateOrderProposalsAndSendGOF.

    Iterates g_OwnProposalMap (Python: state.g_PosAnalysisList) looking for
    entries whose proposed XDO orders are now all committed to the game board.
    For each newly-satisfied entry it runs CAL_MOVE on every associated press
    entry; if any CAL_MOVE returns truthy the GOF commit path fires
    (NormalizeInfluenceMatrix + send_GOF), otherwise ScheduledPressDispatch is
    called.

    C layout (undefined4* offsets from BST node puVar5):
      +8        board_satisfied byte (0 = pending, 1 = done; outer gate)
      +0xc/0xd  inner XDO sub-list (sentinel/head)
      +0xf      unit/province field for GameBoard_GetPowerRec
      [0x10]    expected power-token (equality check vs board result[1])
      [0x14]    type_flag (0 = external/received proposal)
      +0x15/16  press-entry sub-list (used for CAL_MOVE inner loop)

    Board-satisfaction rule (C lines 59–101 in the decompile):
      bVar3 starts True.  For each XDO sub-entry, call GameBoard_GetPowerRec;
      if result[1] == node[0x10] (board already has the expected order token)
      → bVar3 = False.  bVar3 True after full scan ⟹ board not yet committed
      → entry is "satisfiable" and the GOF candidate path runs.

    Python model note:
      g_PosAnalysisList entries are inserted by receive_proposal with empty
      sub_entries / press_entries, so the inner board-check loop never executes
      (bVar3 stays True) and the press-entry loop also never executes (bVar4
      stays False).  Result: ScheduledPressDispatch is always called.  The full
      sub-list population path is preserved for future fidelity.
    """
    from ..communications import dispatch_scheduled_press, cal_move
    from ..heuristics import normalize_influence_matrix

    bVar4 = False
    board_orders = getattr(state, 'g_board_orders', {})

    for entry in getattr(state, 'g_PosAnalysisList', []):
        # C: if (*(char*)(puVar5 + 8) == '\0') — skip already-satisfied entries
        if entry.get('board_satisfied', False) or entry.get('processed', False):
            continue

        # ── Board-satisfaction inner loop (node+0xc/0xd sub-list) ─────────────
        # bVar3 starts True; cleared if any sub-entry is already on the board
        # with the expected power-token (i.e. the proposed order is committed).
        bVar3 = True
        sub_entries   = entry.get('sub_entries', [])
        expected_tok  = entry.get('order_type', -1)  # node[0x10]

        for sub in sub_entries:
            prov = sub.get('province', -1)
            rec  = board_orders.get(prov, {})
            # C: if (puVar8[1] == local_4c) bVar3 = false
            if rec.get('order_type') == expected_tok:
                bVar3 = False

        if bVar3:
            # C: *(undefined1*)(puVar5 + 8) = 1
            entry['board_satisfied'] = True
            entry['processed'] = True          # keep _fun_004117d0 in sync

            # C: if (puVar5[0x14] == 0) — external/received proposal
            if entry.get('type_flag', 0) == 0:
                # C: clear DAT_00bb65e4 (pending-GOF linked list) — no Python
                # equivalent; the C list is a singly-linked structure that is
                # rebuilt each time.  Skip.

                # C: SerializeOrders + RegisterProposalOrders(DAT_00bb65e0,
                #    puVar5+0xc) — clears the staging set then deep-copies the
                #    proposal's XDO sub-tree into it so the downstream
                #    GameBoard_GetPowerRec lookups (and CAL_MOVE) see the
                #    proposed orders as the "current" set.
                #
                # Cross-domain note: DAT_00bb65e0 is the same global the DMZ
                # handler uses (state.g_DmzOrderList).  C accepts the collision
                # — both writers clear-and-rewrite — and the DMZ handler
                # refreshes the list on its next call.  Faithful port keeps the
                # same semantics.
                try:
                    if not hasattr(state, 'g_DmzOrderList') or state.g_DmzOrderList is None:
                        state.g_DmzOrderList = []
                    state.g_DmzOrderList.clear()
                    state.g_DmzOrderList.extend(
                        copy.deepcopy(sub) for sub in sub_entries
                    )
                except Exception:
                    logger.exception(
                        "RegisterProposalOrders staging copy raised; continuing"
                        " with empty g_DmzOrderList"
                    )

                # ── Inner press-entry loop (node+0x15/0x16 sub-list) ──────────
                # C: FUN_00405090 + FUN_00465f60(auStack_a8, inner+0xc)
                #    cVar7 = CAL_MOVE(param_1); if cVar7==1 → bVar4 = true
                press_entries = entry.get('press_entries', [])
                for pe in press_entries:
                    tokens = pe.get('tokens', []) if isinstance(pe, dict) else list(pe)
                    if cal_move(state, tokens):
                        bVar4 = True

    # C: if (bVar4) NormalizeInfluenceMatrix + send_GOF; else ScheduledPressDispatch
    if bVar4:
        normalize_influence_matrix(state)
        _send_gof(state, send_dm)
    else:
        dispatch_scheduled_press(state, send_dm)


