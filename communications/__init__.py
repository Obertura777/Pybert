"""Albert DAIDE / press-handling subpackage.

Originally a single 6,174-line ``communications.py``.  Split into
submodules during the 2026-04 refactor:

- ``tokens``      — DAIDE token primitives and press-type token constants
- ``parsers``     — XDO / press-content text and token parsers (pure, no state)
- ``scheduling``  — scheduled-press dispatch queue + ThennAction execution
- ``senders``     — outbound press senders, proposal builders, dispatch loop
- ``evaluators``  — press-evaluation pipeline, legitimacy handlers, proposal scoring
- ``alliance``    — alliance-tree, STL container, and hostility-record helpers
- ``inbound``     — inbound DAIDE message pipeline and press-response generation

All public names previously importable as ``albert.communications.X`` remain
available at that path via the re-exports below; nothing external should need
to change.
"""

import time as _time

from ..state import InnerGameState
from ..monte_carlo import check_time_limit

# ── Re-exports from submodules (preserve flat public surface) ────────────────
from .tokens import (
    _TOK_ALY, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_AND, _TOK_VSS, _TOK_XDO,
    _token_seq_copy,
    _token_seq_overlap,
    _token_seq_no_overlap,
    _token_seq_concat_single,
    _token_seq_count,
    _token_seq_less,
    _wrap_single_token,
    _get_daide_context_ptr,
)
from .parsers import (
    _DAIDE_TO_ORDER_TYPE_TAG,
    _extract_top_paren_groups,
    _parse_xdo_candidates,
    _split_top_level_groups,
    _parse_unit_triple,
    _parse_destination,
    _parse_xdo_body_to_order,
)
from .scheduling import (
    dispatch_scheduled_press,
    _send_ally_press_by_power,
    _fun_004117d0,
    _press_gate_check,
    _press_list_count,
    _find_press_token,
    _press_token_found,
    _renegotiate_pce,
    _execute_aly_vss,
    _execute_xdo,
    _execute_then_action,
)
from .senders import (
    send_alliance_press,
    emit_xdo_proposals_to_broadcast,
    score_order_candidates_from_broadcast,
    propose_dmz,
    _update_relation_history,
    friendly,
    _friendly_peace_signal_check,
    cancel_prior_press,
    _is_game_active,
    _check_server_reachable,
    dispatch_press_and_fallback_gof,
    _prepare_ally_press_entry,
)
from .evaluators import (
    _POWER_NAMES, _NEUTRAL_POWER,
    _pow_idx, _eval_pce,
    _flatten_section, _extract_powers, _extract_provs, _ally_trust_ok,
    _eval_dmz, _eval_aly, _split_xdo_clauses, _cal_value,
    _eval_slo, _eval_drw, _eval_not_pce, _eval_not_dmz,
    _eval_sub_xdo, _eval_single_xdo, evaluate_press,
    compute_order_dip_flags, cal_move,
    _handle_pce, _handle_aly, _handle_dmz, _handle_xdo,
    _score_support_opp, _score_sup_attacker,
    _cancel_pce, _remove_dmz, _not_xdo,
)

from .alliance import (
    alliance_tree_find_or_insert,
    build_alliance_msg,
    _stl_tree_copy,
    _stl_tree_erase_node,
    build_hostility_record,
    _ordered_token_seq_insert,
    _copy_stl_ordered_set,
)
from .inbound import (
    process_hst,
    ack_matcher,
    huh_err_strip_replay,
    process_try,
    legitimacy_gate,
    delay_review,
    register_received_press,
    process_frm_message,
    parse_message,
    receive_proposal,
    _respond_walk_pos_analysis,
    respond,
    _ACK_TOK_YES,
    _ACK_TOK_REJ,
    _ACK_TOK_BWX,
    _STANCE_TOKEN_CODES,
    inbound_daide_dispatcher,
    not_dispatcher,
    yes_dispatcher,
    parse_now,
    parse_now_unit,
    hlo_dispatch,
    handle_not_ccd,
    handle_not_tme,
    handle_not_unknown,
    handle_yes_nme,
    handle_yes_obs,
    handle_yes_iam,
    handle_yes_not,
    handle_yes_gof,
    handle_yes_tme,
    handle_yes_drw,
    handle_yes_snd,
    handle_yes_unknown,
    handle_map,
    handle_mdf,
    handle_ord,
    handle_sco,
    handle_rej,
    handle_ccd,
    handle_out,
    handle_huh,
    handle_mis,
    handle_off,
    handle_sve,
    handle_thx,
    handle_tme,
    handle_adm,
    handle_lod,
)
