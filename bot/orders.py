"""Order serialization: InnerGameState tables → DAIDE / DipNet order tokens.

Split from bot.py during the 2026-04 refactor.

Pure transformations from order-table / retreat-list state into DAIDE-format
token strings and retreat command lists.  Zero calls to other bot submodules.
"""

import logging

import numpy as np

from ..state import InnerGameState
from ..monte_carlo import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from ._shared import _DAIDE_COAST_TO_STR, _DAIDE_POWER_NAMES

logger = logging.getLogger(__name__)




def _init_position_for_orders(state: InnerGameState) -> None:
    """InitPositionForOrders. Sets up per-turn position state required 
    before Monte Carlo order evaluation. Writes g_ScOwner, resets 
    g_AllyMatrix, and zeros g_MoveHistoryMatrix."""
    num_powers = 7
    num_provinces = 256
    
    # Step 1 — Clear per-power order candidate lists
    state.g_CandidateRecordList.clear()
    
    # Step 2 — Initialize g_ScOwner to "unknown" (-1 = unoccupied, -2 = contested)
    state.g_ScOwner = getattr(state, 'g_ScOwner', np.full(num_provinces, -1, dtype=np.int32))
    state.g_ScOwner.fill(-1)
    
    # Step 4 — Populate g_ScOwner from unit list
    for prov, unit in state.unit_info.items():
        power = unit.get('power', -1)
        if power < 0:
            continue
        if state.g_ScOwner[prov] == -1:
            state.g_ScOwner[prov] = power
        elif state.g_ScOwner[prov] != power:
            state.g_ScOwner[prov] = -2  # contested (-2)
            
    # Step 5 — Zero g_AllyMatrix per power (to be rebuilt by FRIENDLY)
    state.g_AllyMatrix.fill(0)
    
    # Step 6 — Convoy reach and history
    if not hasattr(state, 'g_MoveHistoryMatrix'):
        state.g_MoveHistoryMatrix = np.zeros((num_powers, num_provinces, num_provinces), dtype=np.int32)
    else:
        state.g_MoveHistoryMatrix.fill(0)
        
    # C: Albert+0x3ffc = victory_threshold = sc_count/2 + 1
    # (InitPositionForOrders.c:236 — `local_de8 / 2 + 1`, where local_de8 is
    # incremented on lines 188-192 once per province whose byte-offset +3 is
    # nonzero.  That +3 byte is the "is supply center" flag of the province
    # record; for standard Diplomacy's 34 SCs this yields 18, matching the
    # state.win_threshold default.  Using unit_count here (22 start → 12) would
    # be semantically wrong.  See research.md §7229 / docs/funcs/
    # InitPositionForOrders.md:76 and verification trace on local_de8.)
    #
    # Python canonical: state.win_threshold (read throughout heuristics/board.py,
    # heuristics/scoring.py, heuristics/_primitives.py).  Keep both in sync so
    # the C-faithful name (g_VictoryThreshold) also has a live writer matching
    # whatever state.win_threshold reflects.
    sc_count = len(getattr(state, 'sc_provinces', ()))
    if sc_count > 0:
        victory_threshold = sc_count // 2 + 1
    else:
        # Pre-init / mock states without sc_provinces populated — preserve the
        # state.py:249 default rather than computing a degenerate value.
        victory_threshold = int(getattr(state, 'win_threshold', 18))
    state.g_VictoryThreshold = victory_threshold
    state.win_threshold      = victory_threshold


def _build_movement_order_token(state: 'InnerGameState', prov: int) -> 'str | None':
    """
    Port of FUN_00463690 — build DAIDE token string for one movement-phase order.

    C: undefined4 * __thiscall FUN_00463690(void *this, undefined4 *param_1, int *param_2)
      this    = inner gamestate (unit list at this+0x2450)
      param_1 = output token list
      param_2 = order record starting at unit+0x10 in the unit struct:
        [0]  source province ID
        [1]  source coast token
        [2]  power index
        [3]  unit type (0=AMY, 1=FLT)
        [4]  order type: 0/1=HLD, 2=MTO, 3=SUP_HLD, 4=SUP_MTO, 5=CVY, 6=CTO
               (unit+0x20 != 0 guard in caller = this field non-zero)
        [5]  dest province (MTO, CTO)
        [6]  dest coast token (MTO, CTO; high byte 0x46 = coast category)
        [7]  target unit province (SUP_HLD, SUP_MTO, CVY)
        [8]  secondary dest province (SUP_MTO dest; CVY army dest)
        [10] CTO via-list head pointer (linked list of convoy fleet provinces)

    Token DAT constants (confirmed from token table at 0x004c7670):
        DAT_004c7678 = CTO (0x4320)
        DAT_004c767c = CVY (0x4321)
        DAT_004c7680 = HLD (0x4322)
        DAT_004c7684 = MTO (0x4323)
        DAT_004c7688 = SUP (0x4324)
        DAT_004c768c = VIA (0x4325)

    Python mapping of param_2 fields → g_OrderTable columns:
        param_2[4]   order type  → _F_ORDER_TYPE  (1-indexed; 0/1→HLD=1, 2→MTO=2, …)
        param_2[7]   target prov → _F_SECONDARY   (SUP target or CVY army)
        param_2[5,8] dest prov   → _F_DEST_PROV   (MTO/CTO dest; SUP_MTO/CVY dest)
        param_2[6]   dest coast  → _F_DEST_COAST
        param_2[10]  via list    → _F_CONVOY_LEG0/_LEG1/_LEG2 (up to 3 fleet provinces)

    Absorbed helpers:
        FUN_0045ffa0 → inline: build ( POWER AMY|FLT PROVINCE [COAST] ) unit token
        FUN_0045fca0 → inline: build PROVINCE or ( PROVINCE COAST ) dest token
        FUN_00466480/FUN_00466330/AppendList → string concat (no Python equivalent needed)
        FUN_00465870 → token-list alloc (no Python equivalent needed)
        FUN_00466c40 → wrap sub-list in parens (absorbed as f"( {via_str} )")
        UnitList_FindOrInsert → state.unit_info.get(target_prov)
    """
    order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
    if order_type == 0:
        return None

    unit_data = state.unit_info.get(prov)
    if unit_data is None:
        return None

    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    # FUN_0045ffa0: build unit identifier ( POWER AMY|FLT PROVINCE [COAST] )
    # param_2[0..3] = {province, coast, power, unit_type}
    power_idx  = unit_data.get('power', 0)
    power_name = _DAIDE_POWER_NAMES[power_idx] if 0 <= power_idx < len(_DAIDE_POWER_NAMES) else 'UNO'
    _utype = unit_data.get('type', 'A')
    unit_chr   = 'AMY' if _utype in ('A', 'AMY') else 'FLT'
    prov_name  = id_to_prov.get(prov, str(prov))
    unit_coast = unit_data.get('coast', '')
    if unit_coast:
        unit_tok = f"( {power_name} {unit_chr} {prov_name} {unit_coast} )"
    else:
        unit_tok = f"( {power_name} {unit_chr} {prov_name} )"

    # FUN_0045fca0: build dest token — PROVINCE or ( PROVINCE COAST )
    # param_2[5] = dest province, param_2[6] = dest coast (high byte 0x46 = coast category)
    dest_id       = int(state.g_OrderTable[prov, _F_DEST_PROV])
    dest_name     = id_to_prov.get(dest_id, str(dest_id))
    dest_coast_tok = int(state.g_OrderTable[prov, _F_DEST_COAST])
    dest_coast_str = _DAIDE_COAST_TO_STR.get(dest_coast_tok, '')
    if dest_coast_str:
        dest_tok = f"( {dest_name} {dest_coast_str} )"
    else:
        dest_tok = dest_name

    def _target_unit_tok(target_prov: int) -> 'str | None':
        """FUN_0045ffa0 applied to target unit at target_prov."""
        td = state.unit_info.get(target_prov)
        if td is None:
            return None
        tp = td.get('power', 0)
        tn = _DAIDE_POWER_NAMES[tp] if 0 <= tp < len(_DAIDE_POWER_NAMES) else 'UNO'
        _ttype = td.get('type', 'A')
        tc = 'AMY' if _ttype in ('A', 'AMY') else 'FLT'
        tp_name = id_to_prov.get(target_prov, str(target_prov))
        tcoast  = td.get('coast', '')
        if tcoast:
            return f"( {tn} {tc} {tp_name} {tcoast} )"
        return f"( {tn} {tc} {tp_name} )"

    if order_type == _ORDER_HLD:
        # case 0/1: DAT_004c7680 = HLD
        # FUN_0045ffa0 → unit_tok; FUN_00466480(unit_tok, HLD); AppendList
        return f"{unit_tok} HLD"

    elif order_type == _ORDER_MTO:
        # case 2: FUN_0045fca0 → dest_tok; FUN_0045ffa0 → unit_tok
        #         FUN_00466480(unit_tok, MTO=DAT_004c7684); FUN_00466330(+dest_tok); AppendList
        return f"{unit_tok} MTO {dest_tok}"

    elif order_type == _ORDER_SUP_HLD:
        # case 3: UnitList_FindOrInsert(param_2+7) → target unit
        #         FUN_0045ffa0(target) → target_tok
        #         FUN_0045ffa0(self)   → unit_tok
        #         FUN_00466480(unit_tok, SUP=DAT_004c7688); FUN_00466330(+target_tok); AppendList
        target_prov = int(state.g_OrderTable[prov, _F_SECONDARY])
        target_tok  = _target_unit_tok(target_prov)
        if target_tok is None:
            return None
        return f"{unit_tok} SUP {target_tok}"

    elif order_type == _ORDER_SUP_MTO:
        # case 4: UnitList_FindOrInsert(param_2+7) → target; dest = this+param_2[8]*0x24
        #         FUN_0045ffa0(target) → target_tok
        #         FUN_0045ffa0(self)   → unit_tok
        #         FUN_00466480(unit_tok, SUP); concat(+target_tok)
        #         FUN_00466480(+MTO=DAT_004c7684); FUN_00466480(+dest_province); AppendList
        # param_2[7] = _F_SECONDARY (supported unit); param_2[8] = _F_DEST_PROV (its destination)
        target_prov = int(state.g_OrderTable[prov, _F_SECONDARY])
        target_tok  = _target_unit_tok(target_prov)
        if target_tok is None:
            return None
        return f"{unit_tok} SUP {target_tok} MTO {dest_name}"

    elif order_type == _ORDER_CVY:
        # case 5: UnitList_FindOrInsert(param_2+7) → army unit at army_prov
        #         FUN_0045ffa0(army)  → army_tok
        #         FUN_0045ffa0(fleet) → unit_tok
        #         FUN_00466480(unit_tok, CVY=DAT_004c767c); concat(+army_tok)
        #         FUN_00466480(+CTO=DAT_004c7678); FUN_00466480(+dest_province); AppendList
        # param_2[7] = army prov (_F_SECONDARY); param_2[8] = army dest (_F_DEST_PROV)
        army_prov = int(state.g_OrderTable[prov, _F_SECONDARY])
        army_tok  = _target_unit_tok(army_prov)
        if army_tok is None:
            return None
        return f"{unit_tok} CVY {army_tok} CTO {dest_name}"

    elif order_type == _ORDER_CTO:
        # case 6: FUN_0045fca0 → dest_tok (with coast); FUN_0045ffa0 → army unit_tok
        #         FUN_00466480(unit_tok, CTO=DAT_004c7678); concat(+dest_tok); AppendList main order
        #         iterate param_2[10] via-list (linked list), each node[2]=fleet_prov:
        #           FUN_00466480(local_1ec, fleet_prov_token); AppendList(local_1ec)
        #         FUN_00466480(param_1, VIA=DAT_004c768c)
        #         FUN_00466c40(+local_1ec wrapped in parens); AppendList
        # param_2[10] via list → _F_CONVOY_LEG0/_LEG1/_LEG2 (non-zero fleet province IDs)
        via_provs = []
        for leg_col in (_F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2):
            leg_prov = int(state.g_OrderTable[prov, leg_col])
            if leg_prov:
                via_provs.append(id_to_prov.get(leg_prov, str(leg_prov)))
        if via_provs:
            # FUN_00466c40 wraps the via-province list in parens (DAT_004c768c = VIA)
            via_tok = "( " + " ".join(via_provs) + " )"
            return f"{unit_tok} CTO {dest_tok} VIA {via_tok}"
        return f"{unit_tok} CTO {dest_tok}"

    return None


def _build_retreat_order_token(state: 'InnerGameState', node: dict) -> 'str | None':
    """
    Port of FUN_00460110 — build DAIDE token string for one retreat-phase order node.

    C param_2 layout (int *):
        [0..3] = unit data (province, type, power, ...)  → consumed by FUN_0045ffa0
        [4]    = order type: 0 or 8 → DSB, 7 → RTO, other → skip (return param_1 unchanged)
        [5]    = destination province ID (RTO only)      → FUN_0045fca0
        [6]    = coast low-byte; CONCAT22(0x46, [6]) → coast token (RTO only)

    Key constants:
        DAT_004c7690 = DSB (0x4340)   — appended by FUN_00466480 for DSB path
        DAT_004c7694 = RTO (0x4341)   — appended by FUN_00466480 for RTO path

    Returns DAIDE order string (without outer parens) for appending to GOF seq,
    or None to skip this node entirely.

    Inline helpers absorbed into string operations (no standalone Python port needed):
        FUN_0045ffa0  — build unit token seq  ('POWER AMY|FLT PROVINCE [COAST]')
        FUN_0045fca0  — build province+coast dest seq  ('PROVINCE [COAST]')
        FUN_00466480  — append single token to seq     (→ string concat)
        FUN_00466330  — concat two token seqs          (→ string concat)
        FUN_00465870  — init empty token list          (→ not needed in Python)
    """
    order_type = node.get('order_type', -1)

    # FUN_0045ffa0: build unit token seq → 'POWER AMY|FLT PROVINCE [COAST]'
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    power_idx = node.get('power', 0)
    power_name = _DAIDE_POWER_NAMES[power_idx] if 0 <= power_idx < len(_DAIDE_POWER_NAMES) else 'UNO'
    _utype = node.get('unit_type', 'A')
    unit_chr = 'AMY' if _utype in ('A', 'AMY') else 'FLT'
    prov_name = state._id_to_prov.get(node.get('province', 0), str(node.get('province', 0)))
    unit_coast = node.get('unit_coast', '')
    # FUN_00465aa0 wraps the unit seq in parens at the end of FUN_0045ffa0,
    # so the unit portion must be ( POWER UNIT PROVINCE [COAST] ).
    unit_str = f"( {power_name} {unit_chr} {prov_name}"
    if unit_coast:
        unit_str += f" {unit_coast}"
    unit_str += " )"

    if order_type == 7:  # RTO
        # FUN_0045fca0: build destination seq ('PROVINCE [COAST]')
        dest_id = node.get('dest_province', 0)
        dest_name = state._id_to_prov.get(dest_id, str(dest_id))
        # C: param_3._1_1_ == 'F' checks high byte == 0x46 (coast category).
        # dest_coast stores the full DAIDE coast token (0 = no coast, 0x46xx = coast).
        coast_tok = node.get('dest_coast', 0)
        coast_str = _DAIDE_COAST_TO_STR.get(coast_tok, '')
        # FUN_00466540 builds [province_tok, coast_tok]; FUN_00465aa0 then wraps in ( ).
        # DAIDE prov_coast grammar: ( province coast ) — parens required for coasted dest.
        if coast_str:
            dest_str = f"( {dest_name} {coast_str} )"
        else:
            dest_str = dest_name
        # FUN_00466480(unit_seq, buf, &DAT_004c7694=RTO) + FUN_00466330(unit+RTO, buf, dest)
        return f"{unit_str} RTO {dest_str}"

    elif order_type in (0, 8):  # DSB
        # FUN_00466480(unit_seq, buf, &DAT_004c7690=DSB)
        return f"{unit_str} DSB"

    # All other order types: C returns param_1 unchanged (no entry appended)
    return None


# ── Retreat-phase order population ──────────────────────────────────────────

# Coast suffix → DAIDE coast token (reverse of _DAIDE_COAST_TO_STR)
_COAST_STR_TO_DAIDE = {
    'NC': 0x4600, 'NE': 0x4602, 'EC': 0x4604,
    'SC': 0x4606, 'WC': 0x460C, 'NW': 0x460E,
}


def _populate_retreat_orders(
    state: 'InnerGameState',
    game: 'Game',
    power_name: str,
    own_power_idx: int,
) -> list:
    """
    Build g_retreat_order_list entries for the current retreat phase.

    For each dislodged own-power unit (from game.powers[power_name].retreats),
    evaluate possible retreat destinations using g_GlobalProvinceScore and pick
    the best one.  If no valid retreat exists, order a disband (DSB).

    Returns a list of dicts matching the schema at state.py line 539:
        {'province': int, 'unit_type': str, 'unit_coast': str,
         'power': int, 'order_type': int,
         'dest_province': int, 'dest_coast': int}
    where order_type 7 = RTO, 8 = DSB.
    """
    power = game.powers.get(power_name)
    if power is None or not power.retreats:
        return []

    prov_to_id = state.prov_to_id
    scores = state.g_GlobalProvinceScore  # [256] float array from generate_orders

    result = []
    for unit_spec, destinations in power.retreats.items():
        # unit_spec: 'A TYR' or 'F STP/NC'
        parts = unit_spec.split()
        if len(parts) < 2:
            continue
        u_type = parts[0]              # 'A' or 'F'
        u_loc  = parts[1]              # 'TYR' or 'STP/NC'

        # Resolve province ID and coast for the source
        src_base = u_loc.split('/')[0].upper()
        src_id = prov_to_id.get(u_loc, prov_to_id.get(src_base, -1))
        src_coast = ''
        if '/' in u_loc:
            src_coast = u_loc.split('/')[1].upper()

        if src_id < 0:
            logger.warning(
                "Retreat: cannot resolve province %r → skipping", u_loc)
            continue

        # Evaluate each destination by g_GlobalProvinceScore
        best_score = -1e30
        best_dest_id = -1
        best_dest_coast = 0
        for dest in destinations:
            # dest: 'BOH' or 'SPA/SC'
            dest_base = dest.split('/')[0].upper()
            d_id = prov_to_id.get(dest, prov_to_id.get(dest_base, -1))
            if d_id < 0:
                continue
            d_score = float(scores[d_id]) if 0 <= d_id < len(scores) else 0.0
            if d_score > best_score:
                best_score = d_score
                best_dest_id = d_id
                best_dest_coast = 0
                if '/' in dest:
                    coast_str = dest.split('/')[1].upper()
                    best_dest_coast = _COAST_STR_TO_DAIDE.get(coast_str, 0)

        if best_dest_id >= 0:
            # RTO — retreat to best destination
            node = {
                'province':      src_id,
                'unit_type':     u_type,
                'unit_coast':    src_coast,
                'power':         own_power_idx,
                'order_type':    7,           # RTO
                'dest_province': best_dest_id,
                'dest_coast':    best_dest_coast,
            }
        else:
            # DSB — no valid retreat destination
            node = {
                'province':      src_id,
                'unit_type':     u_type,
                'unit_coast':    src_coast,
                'power':         own_power_idx,
                'order_type':    8,           # DSB
                'dest_province': 0,
                'dest_coast':    0,
            }
        result.append(node)

    return result


def _format_retreat_commands(state: 'InnerGameState') -> list:
    """
    Convert g_retreat_order_list entries into diplomacy-lib order strings.

    Returns a list like ['A TYR R VEN', 'F SPA/SC R MAO'] or ['A TYR D'].
    These are passed to game.set_orders() to commit the retreat decisions.
    """
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    commands = []
    for node in state.g_retreat_order_list:
        u_type = node.get('unit_type', 'A')
        u_chr = 'A' if u_type in ('A', 'AMY') else 'F'
        src_name = id_to_prov.get(node.get('province', 0), '???')
        src_coast = node.get('unit_coast', '')
        src_str = f"{src_name}/{src_coast}" if src_coast else src_name

        order_type = node.get('order_type', -1)
        if order_type == 7:  # RTO
            dest_id = node.get('dest_province', 0)
            dest_name = id_to_prov.get(dest_id, '???')
            dest_coast_tok = node.get('dest_coast', 0)
            dest_coast_str = _DAIDE_COAST_TO_STR.get(dest_coast_tok, '')
            dest_str = (f"{dest_name}/{dest_coast_str}"
                        if dest_coast_str else dest_name)
            commands.append(f"{u_chr} {src_str} R {dest_str}")
        elif order_type in (0, 8):  # DSB
            commands.append(f"{u_chr} {src_str} D")

    return commands


def get_sub_list(press_seq: 'str | list[str]', index: int) -> list:
    """
    Port of GetSubList (FUN_00466060).

    C: undefined4 * __thiscall GetSubList(void *this, undefined4 *param_1, int param_2)
      this    = press-sequence object:
                  this[0]  = pointer to flat ushort token buffer (2 bytes/token)
                  this[2]  = pointer to int index array:
                               index_array[i]   = start offset of sub-list i
                               index_array[i+1] = end offset (exclusive)
                  this[3]  = count of sub-lists
      param_1 = output TokenSeq (initialised to {0, 0xffffffff, 0, 0xffffffff})
      param_2 = 0-based index of the sub-list to extract

    Extraction logic (decompile lines 25–36):
      length = index_array[i+1] - index_array[i]
      if length == 1:
          data = buf[start]          # bare single token — no parens to strip
          count = 1
      else:
          data = buf[start + 1]      # skip leading '('
          count = length - 2         # skip trailing ')' too
      FUN_00465940(param_1, data, count)   # init output TokenSeq from slice

    FUN_00465940 = TokenSeq_InitFromBuffer: populates a TokenSeq struct from a
    raw pointer + length.  In Python this is simply returning the token slice.

    Python equivalent:
      Tokenise press_seq, walk top-level parenthesised groups (and bare tokens),
      return the inner tokens of the index-th group with outer parens stripped.
      Returns [] if index is out of range or press_seq is empty.

    Called from BuildAndSendSUB as GetSubList(puVar31 + 10, apvStack_180, 1)
    to extract the second top-level sub-expression from a proposal token seq.
    """
    tokens: list[str] = press_seq.split() if isinstance(press_seq, str) else list(press_seq)

    # Collect top-level groups: each is either a '(…)' span or a bare token.
    groups: list[tuple[int, int]] = []  # (start_idx, end_idx) inclusive in tokens
    depth = 0
    group_start: int | None = None

    for i, tok in enumerate(tokens):
        if tok == '(':
            if depth == 0:
                group_start = i
            depth += 1
        elif tok == ')':
            depth -= 1
            if depth == 0 and group_start is not None:
                groups.append((group_start, i))
                group_start = None
        elif depth == 0:
            # bare token at top level — single-token sub-list with no parens
            groups.append((i, i))

    if index < 0 or index >= len(groups):
        return []

    start, end = groups[index]
    group_tokens = tokens[start:end + 1]
    length = len(group_tokens)

    if length == 1:
        # single bare token — return as-is (mirrors iVar2 == 1 branch)
        return group_tokens
    else:
        # strip outer '(' and ')' (mirrors iVar2 != 1 branch: skip first + last)
        return group_tokens[1:-1]



# ── Order-sequence builder ───────────────────────────────────────────────────

def _build_order_seq_from_table(state: InnerGameState, prov: int) -> dict | None:
    """
    Builds a dispatch_single_order-compatible order dict from g_OrderTable[prov].
    Returns None if the province has no active order or no unit present.

    Mirrors the DispatchSingleOrder (FUN_0044cc50) input construction step —
    reading g_OrderTable fields and converting province IDs to name strings via
    the state.prov_to_id reverse map.
    """
    order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
    if order_type == 0:
        return None

    unit_data = state.unit_info.get(prov)
    if unit_data is None:
        return None

    # Build reverse province-id → name map on demand
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    unit_chr = ('A' if unit_data['type'] in ('A', 'AMY') else 'F')
    prov_name = id_to_prov.get(prov, str(prov))
    coast = unit_data.get('coast', '')
    loc_str = f"{prov_name}/{coast}" if coast else prov_name
    unit_str = f"{unit_chr} {loc_str}"

    dest_id   = int(state.g_OrderTable[prov, _F_DEST_PROV])
    dest_name = id_to_prov.get(dest_id, str(dest_id))
    sec_id    = int(state.g_OrderTable[prov, _F_SECONDARY])
    sec_name  = id_to_prov.get(sec_id, str(sec_id))
    dest_coast_tok = int(state.g_OrderTable[prov, _F_DEST_COAST])
    dest_coast = _DAIDE_COAST_TO_STR.get(dest_coast_tok, '')

    _ORDER_TYPE_MAP = {
        _ORDER_HLD:     'HLD',
        _ORDER_MTO:     'MTO',
        _ORDER_SUP_HLD: 'SUP',
        _ORDER_SUP_MTO: 'SUP',
        _ORDER_CVY:     'CVY',
        _ORDER_CTO:     'CTO',
    }

    seq: dict = {
        'type': _ORDER_TYPE_MAP.get(order_type, 'HLD'),
        'unit': unit_str,
    }

    if order_type == _ORDER_MTO:
        seq['target'] = dest_name
        seq['coast']  = dest_coast

    elif order_type == _ORDER_CTO:
        sec_data = state.unit_info.get(sec_id)
        if sec_data:
            sec_chr = 'A' if sec_data['type'] in ('A', 'AMY') else 'F'
            seq['target_unit'] = f"{sec_chr} {sec_name}"
        seq['target_dest'] = dest_name

    elif order_type == _ORDER_SUP_MTO:
        sec_data = state.unit_info.get(sec_id)
        if sec_data:
            sec_chr = 'A' if sec_data['type'] in ('A', 'AMY') else 'F'
            seq['target_unit'] = f"{sec_chr} {sec_name}"
        seq['target_dest']  = dest_name
        seq['target_coast'] = dest_coast

    elif order_type == _ORDER_SUP_HLD:
        sec_data = state.unit_info.get(sec_id)
        if sec_data:
            sec_chr = 'A' if sec_data['type'] in ('A', 'AMY') else 'F'
            seq['target_unit'] = f"{sec_chr} {sec_name}"

    elif order_type == _ORDER_CVY:
        seq['target_dest'] = dest_name

    return seq

