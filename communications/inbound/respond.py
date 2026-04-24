"""Press-response generation (proposal acceptance + walk-pos analysis + reply).

Split from communications/inbound.py during the 2026-04 refactor.

Holds the three functions that, given a previously-accepted inbound
proposal, produce the outbound response:

  * ``receive_proposal``           — record a proposal in the ledger and
    classify it for the response pipeline.
  * ``_respond_walk_pos_analysis`` — per-province walk/position helper
    used by ``respond``.
  * ``respond``                    — the top-level reply generator; emits
    the outbound DAIDE press answering an inbound proposal.

Module-level deps: ``...state.InnerGameState``;
``..senders._prepare_ally_press_entry`` (receive_proposal),
``..alliance.build_alliance_msg`` (receive_proposal / respond),
``..scheduling._send_ally_press_by_power`` (respond).
"""

import time as _time

from ...state import InnerGameState
from ..scheduling import _send_ally_press_by_power
from ..senders import _prepare_ally_press_entry
from ..alliance import build_alliance_msg


def receive_proposal(
    state: "InnerGameState",
    sender_power: int,
    proposal_tokens: list,
    send_fn=None,
) -> None:
    """
    Port of RECEIVE_PROPOSAL (named; no binary address recovered by Ghidra).

    Deduplicates an incoming proposal press against g_pos_analysis_list
    (DAT_00bb65c8/cc).  If this proposal has not yet been recorded:

      1. Appends its token sequence to g_pos_analysis_list.
      2. Logs "We have received the proposal: %s" (mirrors C SEND_LOG).
      3. Adds sender_power to g_alliance_msg_tree (DAT_00bbf638) — the Python
         equivalent of BuildAllianceMsg's sorted-BST insert.
      4. Calls _prepare_ally_press_entry(state, sender_power) [FUN_00418db0
         stub — marks the sender's press-entry as pending for RESPOND].

    C parameters (recovered as in_stack offsets by Ghidra, pushed by caller):
      +0x14  sender_power     — byte index of the sending power
      +0x18  proposal_tokens  — ordered token list (iterated for map inserts)
      +0x04  sub_tokens       — token list used by FUN_00465d90 overlap check
                                (same data as proposal_tokens in practice;
                                 Python uses proposal_tokens for both roles)

    Called from BuildAndSendSUB when:
      puVar18[0x2c] == 1  (has-received-proposal flag set)
      puVar18[7]    == 0  (not yet marked as sent)

    Callees absorbed inline:
      FUN_00465870  — std::list default-constructor → []
      FUN_0047020b  — get own-power context ptr (→ state.albert_power_idx)
      FUN_004243a0  — init analysis-record struct (→ absorbed, no Python state)
      FUN_00465930  — TokenSeq_Count (→ len())
      FUN_00401950  — list content destructor (→ no-op; locals start empty)
      StdMap_FindOrInsert  — std::map lower-bound+insert (→ set.add / dict)
      FUN_00419cb0  — list/range iterator init for g_pos_analysis_list (→ loop)
      FUN_00411a80  — bind iteration to DAT_00bb65d4 secondary sentinel (→ loop)
      GetListElement  — indexed token fetch (→ list index)
      FUN_00465d90  — token-seq overlap bool (→ frozenset intersection)
      GameBoard_GetPowerRec — power-record lookup (→ absorbed; inner loop only
                              fires for nodes with power_count>0, which never
                              occurs for freshly inserted entries → no-op)
      TreeIterator_Advance  — BST iterator step (→ absorbed in loop)
      FUN_0040f860  — std::list::iterator++ (→ Python for-loop)
      FUN_00465f60  — token-list copy (→ list())
      FUN_004223c0  — analysis-struct copy/init (→ absorbed)
      FUN_00430370  — std::list insert at sentinel (→ list.append)
      FUN_00421400  — free analysis struct (→ no-op)
      FreeList      — free temp token list (→ no-op)
      FUN_0046b050  — token-list → string repr (→ str(), already in unchecked)
      SEND_LOG      — debug/log sink (→ logging.info)
      BuildAllianceMsg — BST insert of sender into DAT_00bbf638
                         (→ g_alliance_msg_tree.add; already in unchecked)
      FUN_00418db0  — PrepareAllyPressEntry (→ _prepare_ally_press_entry stub)
    """
    import logging as _log_module
    _log = _log_module.getLogger(__name__)

    # ── Overlap check against g_pos_analysis_list ───────────────────────────────
    # C outer loop iterates g_pos_analysis_list nodes; FUN_00465d90(node+4, &stack4)
    # returns True when node's token set overlaps the incoming proposal.
    # The inner power-record loop uses piStack_c8 which is always empty for
    # freshly inserted entries (power_count == 0), so it never executes and
    # acStack_102[0] stays '\x01' → the outer loop breaks immediately on any
    # overlap, treating the proposal as already seen.
    proposal_set = frozenset(proposal_tokens)
    already_seen = any(
        proposal_set & entry['token_set']
        for entry in state.g_pos_analysis_list
    )

    if already_seen:
        return

    # ── Insert into g_pos_analysis_list ────────────────────────────────────────
    # C: FUN_00465f60(copy, &stack4)  →  copy proposal token list
    #    FUN_004223c0(analysis, record)  →  init analysis struct (absorbed)
    #    FUN_00430370(&sentinel, &iter, copy)  →  std::list insert
    # Build sub_entries from XDO clauses in the proposal (C node+0xc/0xd).
    # Each XDO clause becomes a sub-entry with province and order_type for
    # the board-satisfaction check in EvaluateOrderProposalsAndSendGOF.
    # Fixed 2026-04-20 (M-BOT-3): previously empty, causing GOF board-check
    # to always pass (bVar3 stayed True → all proposals treated as satisfiable).
    from ..parsers import _parse_xdo_candidates
    sub_entries = []
    xdo_cands = _parse_xdo_candidates(' '.join(str(t) for t in proposal_tokens))
    for cand in xdo_cands:
        sub_entries.append({
            'province': cand.get('province', cand.get('src_prov', -1)),
            'order_type': cand.get('order_type', -1),
            'power': cand.get('power', sender_power),
        })

    state.g_pos_analysis_list.append({
        'tokens': list(proposal_tokens),
        'token_set': proposal_set,
        'power_count': 0,   # C node[0xe]; always 0 for newly inserted entries
        # ── Sub-entries for board-satisfaction check (C node+0xc/0xd) ─────
        'sub_entries': sub_entries,
        # ── Press-entries for CAL_MOVE inner loop (C node+0x15/0x16) ──────
        # Populated by ack_matcher when YES arrives for this proposal.
        'press_entries': [],
        # ── Ack-matcher schema extension (2026-04-14) ──────────────────────
        # FUN_0042c970 keys sender-match against C node offsets +0xc/+0xf/+0x12.
        # +0xc / +0xf both hold the sender power (primary check on any ack).
        # +0x12 is the secondary slot consulted on non-YES (REJ/BWX) acks.
        # In the Python model a single ``sender_power`` captures both.
        'sender_power':     sender_power,
        'processed_flag':   0,          # C node[+8]; 0 = unprocessed, set by ack-matcher bookkeeping
        'role_b_set':       set(),      # C node[+0x0e / per-role sub-tree] — YES-ack role-B set
        'role_c_set':       set(),      # C node[+0x16 / per-role sub-tree] — REJ/BWX role-C set
    })

    # ── Log ──────────────────────────────────────────────────────────────────
    # C: FUN_0046b050(&stack4, buf) → string repr of token list
    #    SEND_LOG(&pvStack_ec, L"We have received the proposal: %s")
    _log.info("We have received the proposal: %s", proposal_tokens)

    # ── BuildAllianceMsg — record sender in g_alliance_msg_tree ────────────────
    # C: puStack_f4 = (int)(elapsed_seconds + 10000)
    #    BuildAllianceMsg(&DAT_00bbf638, &pvStack_e8, (int *)&puStack_f4)
    # Python models g_alliance_msg_tree keyed by power index rather than by the
    # C timestamp value (elapsed_seconds + 10000).
    build_alliance_msg(state, sender_power)

    # ── PrepareAllyPressEntry — FUN_00418db0(sender_power) ───────────────────
    # C: final call; marks sender's per-power press-entry as pending so that
    #    RESPOND / SendAllyPressByPower can schedule the DM reply.
    _prepare_ally_press_entry(state, sender_power)


def _respond_walk_pos_analysis(
    state: "InnerGameState",
    sublist3: list,
    sender_power: int,
    response_type: int,
    own_power: int,
) -> None:
    """
    LAB_00421ebc — walk g_pos_analysis_list for proposals matching *sublist3*
    and register *own_power* in g_deviation_tree for each match.

    C flow (decompiled.txt lines 261–316):
      Iterate g_pos_analysis_list (DAT_00bb65c8/cc sentinel loop):
        FUN_00465d90(node+0x10, local_3c) — token-seq overlap check.
        If overlap:
          iStack_68 = node[0x34]  (power-count field)
          GameBoard_GetPowerRec(node+0x30, apuStack_8c, &uStack_c4)
          if puVar13[1] != iStack_68                  ← power-count mismatch
             AND (YES != param_2 OR g_power_active_turn[sender] == 1):
               StdMap_FindOrInsert(node+0x48, &send_time, &uStack_c4)
        FUN_0040f860(&iter)  ← advance list iterator

    GameBoard_GetPowerRec (power-count mismatch check) is absorbed — the check
    fires conservatively whenever the token sets overlap.
    StdMap_FindOrInsert → g_deviation_tree[(token_key, own_power)] insert.
    FUN_00465d90        → frozenset intersection (already used in receive_proposal).
    FUN_0047a948        → AssertFail (absorbed).
    FUN_0040f860        → list iterator advance (absorbed as Python for-loop).
    """
    _YES = 0x481c
    g_active = getattr(state, 'g_power_active_turn', None)
    sender_active = bool(g_active is not None and g_active[sender_power])

    sublist3_set = frozenset(sublist3)
    if not sublist3_set:
        return

    for entry in state.g_pos_analysis_list:
        entry_set = entry.get('token_set', frozenset())
        if not (entry_set & sublist3_set):
            continue
        # C: (puVar13[1] != iStack_68) — power-count mismatch; absorbed as True.
        # C: (YES != param_2 || g_power_active_turn[sender] == 1)
        if response_type != _YES or sender_active:
            key = (frozenset(entry['tokens']), own_power)
            state.g_deviation_tree[key] = state.g_deviation_tree.get(key, 0)
            if 'deviation_powers' not in entry:
                entry['deviation_powers'] = set()
            entry['deviation_powers'].add(own_power)


def respond(
    state: "InnerGameState",
    press_list: dict,
    response_type: int,
    elapsed_lo: int = 0,
    elapsed_hi: int = 0,
    send_fn=None,
) -> None:
    """
    Port of RESPOND (named; called from BuildAndSendSUB after RECEIVE_PROPOSAL).

    Generates Albert's reply to an incoming ally press and queues it for dispatch.

    C signature:
      void __thiscall RESPOND(void *this, void *param_1, short param_2,
                               uint param_3, int param_4)

    Mapping:
      this      → state
      param_1   → press_list  — incoming press as a dict with three sublists:
                    'sublist1': [sender_power_token]   e.g. [0x4103] for GER
                    'sublist2': [power_tokens …]        powers named in proposal
                    'sublist3': [order_tokens …]        XDO/PRP content
      param_2   → response_type  YES=0x481c, REJ=0x4814, HUH=0x4806
      param_3   → elapsed_lo     low-word of current timestamp (uint32)
      param_4   → elapsed_hi     high-word of current timestamp (int32)

    Deception path (REJ + single power + enemy + trust gate):
      If g_enemy_flag[sender]==1 AND sender's trust toward own is positive AND
      relation >= 0 AND random gate fails to trigger avoidance → respond YES
      (deceitfully accept).  Logs "We are DECEITFULLY responding to: (%s)".
      Sets g_power_active_turn[sender] = 1.

    Normal path:
      Echoes response_type unchanged.
      Logs "Our response to a message was: %s".

    Both paths: enqueue SND entry into g_master_order_list, update
    g_alliance_msg_tree, then walk g_pos_analysis_list via
    _respond_walk_pos_analysis.

    HUH path:
      FUN_0040d4d0 (absorbed) + _send_ally_press_by_power(sender) → schedule
      THN response.  Skips queueing step; goes straight to proposal-list walk.

    Timing (non-tournament mode):
      target = elapsed_since_session_start + rand(0–7) + 5 s
      If target < best_ally_turn_score  → push to best_score + 2 s
      If g_move_time_limit_sec > 0        → cap at limit − 20 s
    Timing (tournament mode / g_press_instant != 0):
      target = elapsed_since_session_start  (send immediately)

    Callees absorbed inline:
      FUN_00465870  list init          → []
      FUN_0047020b  own-context ptr    → state.albert_power_idx
      GetSubList    sublist extraction → press_list['sublistN']
      AppendList / FreeList            → Python list ops
      FUN_004658f0  first token        → list[0]
      FUN_00465930  TokenSeq_Count     → len()
      FUN_00465f30  wrap token→list    → [token]
      FUN_00466480  filter by type     → absorbed in power-loop
      FUN_00466f80  prefix+content     → [type_token] + sublist3
      FUN_00466e10  add power token    → list.append
      FUN_00466c40  concat token lists → list + list
      FUN_00465f60  copy token list    → list()
      FUN_00419c30  enqueue press      → g_master_order_list.append
      FUN_0046b050  serialize tokens   → str()
      SEND_LOG                         → logging.debug
      BuildAllianceMsg                 → g_alliance_msg_tree.add
      FUN_0040d4d0  HUH forward        → absorbed (no-op)
      ATL::CSimpleStringT::CloneData   → absorbed
      LOCK / UNLOCK                    → absorbed
    """
    import logging as _logging
    import random as _random

    _log = _logging.getLogger(__name__)

    # DAIDE token constants (from daide_client/tokens.h)
    _YES = 0x481c
    _REJ = 0x4814
    _HUH = 0x4806

    own_power: int = getattr(state, 'albert_power_idx', 0)
    # DAT_00baed32 — tournament mode (g_press_instant in Python)
    tournament_mode: int = int(getattr(state, 'g_press_instant', 0))

    # ── Extract sublists ─────────────────────────────────────────────────────
    # C: GetSubList(param_1, buf, 1/2/3)
    sublist1: list = press_list.get('sublist1', [])   # sender power token(s)
    sublist2: list = press_list.get('sublist2', [])   # powers in proposal
    sublist3: list = press_list.get('sublist3', [])   # order content

    # local_c8[0] = FUN_004658f0(local_1c, &uStack_8e) → first token of sublist1
    # (byte)local_c8[0] extracts the low byte = power index (0-6)
    sender_token: int = sublist1[0] if sublist1 else 0
    sender_power: int = sender_token & 0xff

    # uStack_c4 = *(byte *)(*(int *)(this+8) + 0x2424) — own power index
    # (already extracted above as own_power)

    # ── Initial best ally turn-score lookup ──────────────────────────────────
    # C: iVar16 = -1; puStack_bc = 0xffffffff
    #    if (DAT_00ba27b4[power*8] >= 0): iVar16 = ...; puStack_bc = ...
    g_turn_score = getattr(state, 'g_turn_score', None)
    best_score_hi: int = -1
    best_score_lo: int = 0xffffffff

    if g_turn_score is not None and sender_power < len(g_turn_score):
        val = int(g_turn_score[sender_power])
        hi_val = val >> 32
        lo_val = val & 0xffffffff
        if hi_val >= 0:
            best_score_hi = hi_val
            best_score_lo = lo_val

    # ── Power-list loop (local_4c = sublist2) — update best turn score ───────
    # C: uStack_84 = FUN_00465930(local_4c)  (count of entries)
    #    for each entry != own_power: FUN_00466480 filter + score comparison
    power_count: int = len(sublist2)
    for pw_token in sublist2:
        pw_idx = pw_token & 0xff
        if pw_idx == own_power:
            continue
        if g_turn_score is not None and pw_idx < len(g_turn_score):
            val = int(g_turn_score[pw_idx])
            hi_val = val >> 32
            lo_val = val & 0xffffffff
            if hi_val >= 0 and (
                hi_val > best_score_hi
                or (hi_val == best_score_hi and lo_val > best_score_lo)
            ):
                best_score_hi = hi_val
                best_score_lo = lo_val

    # ── Compute target send time ──────────────────────────────────────────────
    elapsed: float = _time.time() - float(getattr(state, 'g_turn_start_time', 0.0))

    if not tournament_mode:
        # C: uVar17 = (rand() / 0x17) & 0x80000007  → 0-7 (mod-8 random)
        rand_val = _random.randint(0, 0x7fff)
        rand_offset = (rand_val // 23) % 8          # 0-7 units
        target = elapsed + rand_offset + 5.0

        # C: if (pvVar8 <= iVar16 && ...): puVar20 = puStack_bc + 2
        # Push target forward past best ally's score + 2 s if needed
        if best_score_hi >= 0:
            best_f = float(best_score_hi) * float(2**32) + float(best_score_lo)
            if target <= best_f:
                target = best_f + 2.0

        # C: if (0 < DAT_00624ef4): cap at limit - 0x14
        move_limit = int(getattr(state, 'g_move_time_limit_sec', 0))
        if move_limit > 0:
            cap = float(move_limit - 20)
            if target > cap:
                target = cap
    else:
        # Tournament mode: send at current elapsed (no random delay)
        target = elapsed

    # ── HUH path ─────────────────────────────────────────────────────────────
    # C: if (HUH == param_2) { FUN_0040d4d0(...); SendAllyPressByPower(sender); goto end }
    if response_type == _HUH:
        # FUN_0040d4d0(local_6c, param_1) — unknown HUH forward handler; absorbed
        _send_ally_press_by_power(state, sender_power)
        _respond_walk_pos_analysis(state, sublist3, sender_power, response_type, own_power)
        return

    # ── REJ + single ally power → potential deceit YES ───────────────────────
    # C: if ((REJ == param_2) && (uStack_84 == 1)) { ... } else { LAB_00421d01: ... }
    if response_type == _REJ and power_count == 1:
        uVar17 = sender_power

        # Gate 1: sender must be designated enemy
        # C: (&DAT_004cf568)[uVar17*2] == 1  AND  (&DAT_004cf56c)[uVar17*2] == 0
        # Python: g_enemy_flag[sender] == 1 (int32; hi-word of int64 is always 0)
        g_enemy = getattr(state, 'g_enemy_flag', None)
        enemy_flag = int(g_enemy[uVar17]) if g_enemy is not None else 0

        if enemy_flag == 1:
            # Gate 2: trust and relation check
            # C: iVar18 = uVar17*21 + own_power  (sender→own direction in int64 array)
            trust_hi = int(state.g_ally_trust_score_hi[uVar17, own_power])
            trust_lo = int(state.g_ally_trust_score[uVar17, own_power])
            # g_relation_score[own_power, uVar17]  (DAT_00634e90[own*21+sender])
            relation = int(state.g_relation_score[own_power, uVar17])

            # Condition to SKIP deceit (goto normal path):
            #   (trust_hi < 0 OR (trust_hi < 1 AND trust_lo == 0) OR relation < 0)
            #   AND random passes
            low_trust = (
                trust_hi < 0
                or (trust_hi < 1 and trust_lo == 0)
                or relation < 0
            )

            aggressiveness = int(getattr(state, 'g_dmz_aggressiveness', 0))
            press_mode = int(getattr(state, 'g_press_flag', 0)) == 1

            # C: (iVar18 = rand(), (iVar18 / 0x17) % 0x14 + aggressiveness < 0x51)
            r1 = _random.randint(0, 0x7fff)
            rand_check1 = (r1 // 23) % 20 + aggressiveness < 81

            if press_mode:
                # C: DAT_00baed68 == '\x01': RandUpTo(n)(0x14) + aggressiveness < 0x47
                r2 = _random.randint(0, 20)
                rand_check2 = r2 + aggressiveness < 71
                random_passes = rand_check1 and rand_check2
            else:
                random_passes = rand_check1

            skip_deceit = low_trust and random_passes

            if not skip_deceit:
                # ── Deceit path: respond YES instead of REJ ───────────────────
                # C: FUN_00466f80(&YES, &local_6c, local_3c) → [YES] + sublist3
                response_tokens = [_YES] + list(sublist3)

                _log.debug("We are DECEITFULLY responding to: (%s)", response_tokens)

                # C: (&DAT_00633768)[(byte)local_c8[0]] = 1
                g_active = getattr(state, 'g_power_active_turn', None)
                if g_active is not None:
                    g_active[sender_power] = 1

                # C: FUN_00419c30(&DAT_00bb65bc, apuStack_7c, (uint*)&puStack_bc)
                state.g_master_order_list.append({
                    'scheduled_time': target,
                    'press_type':     'SND',
                    'data':           response_tokens,
                    'target_power':   sender_power,
                })

                # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_7c, (int*)&puStack_bc)
                build_alliance_msg(state, sender_power)

                _respond_walk_pos_analysis(
                    state, sublist3, sender_power, response_type, own_power
                )
                return

    # ── Normal path (LAB_00421d01) ────────────────────────────────────────────
    # C: FUN_00466f80(&param_2, &local_6c, local_3c) → [response_type] + sublist3
    response_tokens = [response_type] + list(sublist3)

    _log.debug("Our response to a message was: %s", response_tokens)

    # C: FUN_00419c30(&DAT_00bb65bc, apuStack_7c, (uint*)&puStack_ac)
    state.g_master_order_list.append({
        'scheduled_time': target,
        'press_type':     'SND',
        'data':           response_tokens,
        'target_power':   sender_power,
    })

    # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_7c, (int*)&puStack_bc)
    build_alliance_msg(state, sender_power)

    _respond_walk_pos_analysis(state, sublist3, sender_power, response_type, own_power)
