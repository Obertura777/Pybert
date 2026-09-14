"""Press-response generation (proposal acceptance + walk-pos analysis + reply).

Split from communications/inbound.py during the 2026-04 refactor.

Holds the functions that, given an inbound proposal, record it and produce
the outbound response:

  * ``receive_proposal``           — record a proposal in the ledger
    (RECEIVE_PROPOSAL).
  * ``send_huh_and_try``           — FUN_0040d4d0: answer a message Albert
    does not understand with ``HUH ( ERR ... )`` and ``TRY ( ... )``.
  * ``_respond_walk_pos_analysis`` — RESPOND's LAB_00421ebc walk that adds
    Albert to a proposal's rejection set.
  * ``respond``                    — the top-level reply generator; queues
    the outbound DAIDE press answering an inbound proposal.

Token lists are flat wire tokens.  A proposal's content keeps its ``PRP``
wrapper, as the C node token list (node+0x10) does.

Module-level deps: ``...state.InnerGameState``;
``..senders._prepare_ally_press_entry`` (receive_proposal),
``..alliance.build_alliance_msg`` (receive_proposal),
``..senders.send_ally_press_by_power`` (respond).
"""

import copy as _copy
import time as _time

from ...state import InnerGameState
from ..senders import _prepare_ally_press_entry, send_ally_press_by_power as _send_ally_press_by_power
from ..alliance import build_alliance_msg
from ..tokens import _c_token_at, _token_seq_equal

_POWER_FULL = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY",
               "ITALY", "RUSSIA", "TURKEY"]

_YES = 0x481c
_REJ = 0x4814
_HUH = 0x4806


def _power_name(power: int) -> "str | None":
    return _POWER_FULL[power] if 0 <= power < len(_POWER_FULL) else None


def _wire(tokens) -> str:
    return ' '.join(str(t) for t in tokens)


def receive_proposal(
    state: "InnerGameState",
    sender_power: int,
    proposal_tokens: list,
    send_fn=None,
    participant_powers: "list[int] | None" = None,
) -> None:
    """
    Port of RECEIVE_PROPOSAL (0x00431fe0).

    C arguments: the proposal content (``PRP ( ... )``), the sender byte and
    the FRM recipient list.

    C flow:
      1. Build a fresh analysis record: processed byte 0, elapsed time,
         participant set {sender} ∪ recipients (node+0x30), responded set
         {sender} (node+0x3c), empty rejection set (node+0x48), and the clause
         list (node+0x54) copied from DAT_00bb65d4 — the clauses the
         preceding EvaluatePress accepted.
      2. Walk g_pos_analysis_list for an unprocessed node with an equal token
         list (FUN_00465d90) and an identical participant set; if found, stop.
      3. Otherwise insert the record, log "We have received the proposal",
         archive elapsed + 10000 in DAT_00bbf638 and call FUN_00418db0(sender)
         to drop the sender's pending THN entries.
    """
    import logging as _log_module
    _log = _log_module.getLogger(__name__)

    participants = {int(sender_power)}
    participants.update(int(p) for p in (participant_powers or []))
    already_seen = any(
        _token_seq_equal(entry.get('tokens', []), proposal_tokens)
        and participants == set(entry.get('participant_powers', set()))
        for entry in state.g_pos_analysis_list
        if entry.get('processed_flag', 0) == 0
    )
    if already_seen:
        return

    elapsed = int(_time.time() - getattr(state, 'g_turn_start_time', 0.0))
    state.g_pos_analysis_list.append({
        'tokens': list(proposal_tokens),
        'token_set': frozenset(proposal_tokens),
        'participant_powers': participants,
        'press_entries': [
            {'tokens': _copy.deepcopy(t)}
            for t in getattr(state, 'g_accepted_proposals', [])
        ],
        'sender_power': sender_power,
        'elapsed': elapsed,
        'processed_flag': 0,
        'role_b_set': {sender_power},
        'role_c_set': set(),
    })

    _log.info("We have received the proposal: %s", _wire(proposal_tokens))
    build_alliance_msg(state, elapsed + 10000)
    _prepare_ally_press_entry(state, sender_power)


def send_huh_and_try(
    state: "InnerGameState",
    sender_power: int,
    content_tokens: list,
    send_fn=None,
) -> bool:
    """
    Port of FUN_0040d4d0 — reply to a message Albert does not understand.

    Called from the FRM handler for an unrecognised press token and from
    RESPOND for a HUH verdict.  Unless the content already starts with HUH or
    TRY it sends, immediately and to the sender only:

      * ``SND ( sender ) ( HUH ( ERR <content> ) )`` — ERR is prepended to the
        content (FUN_004665f0), not inserted at an error position;
      * ``SND ( sender ) ( TRY ( <DAT_00bb6f0c> ) )`` — the press tokens this
        bot accepts, as built by the HLO handler.

    Returns True when the two messages were sent.
    """
    first = _c_token_at(content_tokens, 0)
    if str(first).upper() in ('HUH', 'TRY') or first in (_HUH, 0x4A1A):
        return False
    if send_fn is None:
        return False

    recipient = _power_name(int(sender_power))
    allowed = list(getattr(state, 'g_allowed_press_token_list', []) or [])
    huh_body = f"HUH ( ERR {_wire(content_tokens)} )"
    try_body = f"TRY ( {_wire(allowed)} )" if allowed else "TRY ( )"
    send_fn({'message': huh_body, 'recipient': recipient})
    send_fn({'message': try_body, 'recipient': recipient})
    return True


def _respond_walk_pos_analysis(
    state: "InnerGameState",
    content_tokens: list,
    sender_power: int,
    response_type: int,
    own_power: int,
) -> None:
    """
    LAB_00421ebc — RESPOND's walk over g_pos_analysis_list.

    For every node whose token list equals the answered content
    (FUN_00465d90; the processed byte is not consulted) and whose participant
    set (node+0x30) contains Albert: when the answer is not YES, or the
    sender is flagged in DAT_00633768 (a deceitful YES), insert Albert into
    the node's rejection set (node+0x48) if it is not there yet.
    """
    g_active = getattr(state, 'g_power_active_turn', None)
    sender_flagged = bool(
        g_active is not None and int(g_active[sender_power]) == 1
    )
    if response_type == _YES and not sender_flagged:
        return

    for entry in state.g_pos_analysis_list:
        if not _token_seq_equal(entry.get('tokens', []), content_tokens):
            continue
        if own_power not in set(entry.get('participant_powers', set())):
            continue
        entry.setdefault('role_c_set', set()).add(own_power)


def respond(
    state: "InnerGameState",
    press_list: dict,
    response_type: int,
    elapsed_lo: int = 0,
    elapsed_hi: int = 0,
    send_fn=None,
) -> None:
    """
    Port of RESPOND (0x004216f0).

    C signature:
      void __thiscall RESPOND(void *this, void *param_1, short param_2,
                               uint param_3, int param_4)

    Mapping:
      param_1   → press_list — the FRM message as three sublists:
                    'sublist1': [sender_power_token]
                    'sublist2': [recipient power tokens]
                    'sublist3': content tokens, ``PRP ( ... )``
      param_2   → response_type  YES=0x481c, REJ=0x4814, HUH=0x4806
      param_3/4 → the int64 wall-clock time the message was received

    Reply recipients (local_2c) are the sender followed by every recipient
    other than Albert, and the queued message is
    ``SND ( turn ) ( recipients ) ( <verdict> ( <content> ) )``.

    Deception path (REJ + exactly one recipient + enemy sender + trust gate):
      answers YES to the sender alone and sets DAT_00633768[sender].

    HUH path: FUN_0040d4d0 (``send_huh_and_try``) + SendAllyPressByPower
      (sender), then the rejection-set walk; nothing is queued.

    Timing (non-tournament mode):
      target = received - turn_start + rand(0–7) + 5 s
      target <= best recipient turn score → best score + 2 s
      g_move_time_limit_sec > 0 → cap at limit − 20 s
    Timing (tournament mode / g_press_instant != 0):
      target = received - turn_start
    Every queued answer archives target + 2500 in DAT_00bbf638.
    """
    import logging as _logging
    from ... import rng as _random

    _log = _logging.getLogger(__name__)

    own_power: int = getattr(state, 'albert_power_idx', 0)
    tournament_mode: int = int(getattr(state, 'g_press_instant', 0))

    sublist1: list = press_list.get('sublist1', [])
    sublist2: list = press_list.get('sublist2', [])
    content: list = press_list.get('sublist3', [])

    sender_token: int = sublist1[0] if sublist1 else 0
    sender_power: int = sender_token & 0xff

    # ── Best recipient turn score (DAT_00ba27b0/b4) ──────────────────────────
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

    # local_2c = [sender] + every recipient that is not Albert.
    recipients: list = [sender_power]
    power_count: int = len(sublist2)
    for pw_token in sublist2:
        pw_idx = pw_token & 0xff
        if pw_idx == own_power:
            continue
        recipients.append(pw_idx)
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

    # ── Target send time ─────────────────────────────────────────────────────
    received_timestamp = (
        ((int(elapsed_hi) & 0xffffffff) << 32)
        | (int(elapsed_lo) & 0xffffffff)
    )
    if received_timestamp & (1 << 63):
        received_timestamp -= (1 << 64)
    elapsed = float(received_timestamp) - float(
        getattr(state, 'g_turn_start_time', 0.0)
    )

    if not tournament_mode:
        rand_val = _random.randint(0, 0x7fff)
        rand_offset = (rand_val // 23) % 8
        target = elapsed + rand_offset + 5.0

        if best_score_hi >= 0:
            best_f = float(best_score_hi) * float(2**32) + float(best_score_lo)
            if target <= best_f:
                target = best_f + 2.0

        move_limit = int(getattr(state, 'g_move_time_limit_sec', 0))
        if move_limit > 0:
            cap = float(move_limit - 20)
            if target > cap:
                target = cap
    else:
        target = elapsed

    # ── HUH path ─────────────────────────────────────────────────────────────
    if response_type == _HUH:
        send_huh_and_try(state, sender_power, content, send_fn)
        _send_ally_press_by_power(state, sender_power)
        _respond_walk_pos_analysis(state, content, sender_power, response_type, own_power)
        return

    # ── REJ + single recipient → potential deceit YES ────────────────────────
    if response_type == _REJ and power_count == 1:
        uVar17 = sender_power

        g_enemy = getattr(state, 'g_enemy_flag', None)
        g_enemy_hi = getattr(state, 'g_enemy_flag_hi', None)
        enemy_flag = int(g_enemy[uVar17]) if g_enemy is not None else 0
        enemy_flag_hi = int(g_enemy_hi[uVar17]) if g_enemy_hi is not None else 0

        if enemy_flag == 1 and enemy_flag_hi == 0:
            trust_hi = int(state.g_ally_trust_score_hi[uVar17, own_power])
            trust_lo = int(state.g_ally_trust_score[uVar17, own_power])
            relation = int(state.g_relation_score[own_power, uVar17])

            low_trust = (
                trust_hi < 0
                or (trust_hi < 1 and trust_lo == 0)
                or relation < 0
            )

            aggressiveness = int(getattr(state, 'g_press_thresh_random', 50))  # DAT_004c6bd4
            press_mode = int(getattr(state, 'g_press_flag', 0)) == 1

            # C: (rand() / 0x17) % 0x14 + DAT_004c6bd4 < 0x51, evaluated only
            # once the trust test has passed (&& short-circuit).
            if low_trust:
                r1 = _random.randint(0, 0x7fff)
                random_passes = (r1 // 23) % 20 + aggressiveness < 81
                if random_passes and press_mode:
                    r2 = _random.randrange(20)
                    random_passes = r2 + aggressiveness < 71
                skip_deceit = random_passes
            else:
                skip_deceit = False

            if not skip_deceit:
                deceit_msg = f"YES ( {_wire(content)} )"
                _log.debug("We are DECEITFULLY responding to: (%s)", deceit_msg)

                state.g_master_order_list.append({
                    'scheduled_time': target,
                    'press_type':     'SND',
                    'data':           {'message': deceit_msg,
                                       'recipient': _power_name(sender_power)},
                    'target_powers':  [sender_power],
                })

                g_active = getattr(state, 'g_power_active_turn', None)
                if g_active is not None:
                    g_active[sender_power] = 1

                build_alliance_msg(state, int(target) + 2500)

                _respond_walk_pos_analysis(
                    state, content, sender_power, response_type, own_power
                )
                return

    # ── Normal path (LAB_00421d01) ────────────────────────────────────────────
    resp_name = {_YES: 'YES', _REJ: 'REJ', _HUH: 'HUH'}.get(response_type)
    if resp_name is None:
        resp_name = str(response_type)
    resp_msg = f"{resp_name} ( {_wire(content)} )"
    _log.debug("Our response to a message was: %s", resp_msg)

    names = [_power_name(p) for p in recipients]
    data = {'message': resp_msg, 'recipient': names[0]}
    if len(names) > 1:
        data['recipients'] = names

    state.g_master_order_list.append({
        'scheduled_time': target,
        'press_type':     'SND',
        'data':           data,
        'target_powers':  list(recipients),
    })

    build_alliance_msg(state, int(target) + 2500)

    _respond_walk_pos_analysis(state, content, sender_power, response_type, own_power)
