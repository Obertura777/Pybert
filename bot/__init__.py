import asyncio
import copy
import logging
import random
import time

import numpy as np
from diplomacy.client.connection import connect

from ..state import InnerGameState
from ..monte_carlo import (
    process_turn,
    update_score_state,
    check_time_limit,
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from ..communications import (
    parse_message,
    dispatch_scheduled_press,
    cancel_prior_press,
    friendly,
    _send_ally_press_by_power,
)
from ..heuristics import (
    cal_board,
    compute_draw_vote,
    post_process_orders, compute_press, compute_influence_matrix,
    _safe_pow,
    score_provinces,
    score_order_candidates_all_powers,
    score_order_candidates_own_power,
    populate_build_candidates,
    populate_remove_candidates,
    compute_win_builds,
    compute_win_removes,
    _WIN_BUILD_WEIGHTS,
    _WIN_REMOVE_WEIGHTS,
    _SPR_FAL_WEIGHTS,
)
from ..dispatch import validate_and_dispatch_order
from ..utils import dipnet_order  # noqa: F401 — re-exported for callers

logger = logging.getLogger(__name__)

from ._shared import _DAIDE_COAST_TO_STR, _DAIDE_POWER_NAMES, _POWER_NAMES
from .orders import (
    _init_position_for_orders,
    _init_scoring_state,
    _build_movement_order_token,
    _build_retreat_order_token,
    _COAST_STR_TO_DAIDE,
    _populate_retreat_orders,
    _format_retreat_commands,
    get_sub_list,
    _build_order_seq_from_table,
)
from .gof import _build_gof_seq, _send_gof, _evaluate_order_proposals_and_send_gof
from .analysis import (
    _phase_handler, _analyze_position, _move_analysis,
    _post_process_orders, _compute_press,
    _cleanup_turn, _prepare_draw_vote_set,
    _rank_candidates_for_power,
    _game_phase, _game_status,
)
from .strategy import (
    _stab_enemy_slot_remove, _destroy_inner_list, free_list,
    _destroy_candidate_tree, _stab_clear_ally_list,
    _stabbed, _deviate_move, _apply_deviate_stab,
    _friendly, _hostility, _post_friendly_update,
)

from .client import AlbertClient
