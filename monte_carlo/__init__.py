import copy
import random
import numpy as np
from ..state import InnerGameState
from ..heuristics import score_order_candidates_all_powers
from ..moves import enumerate_hold_orders, enumerate_convoy_reach, compute_safe_reach, build_support_opportunities, build_support_proposals, assign_support_order, register_convoy_fleet, build_convoy_orders, populate_convoy_routes

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_HOLD_WEIGHT, _F_CTO_DEST_PROP,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2, _F_CONVOY_DEPTH,
    _F_INCOMING_MOVE, _F_SUP_SRC_LO, _F_SUP_CHAIN_CONFLICT,
    _F_TARGET_PROV, _F_SOURCE_PROV, _F_SUP_COUNT, _F_SUP_TARGET,
    _F_ORDER_ASGN, _F_CUM_SCORE,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from .evaluation import (
    evaluate_order_score,
    evaluate_order_proposal,
)
from .generation import generate_orders
from .trial import (
    trial_evaluate_orders,
    process_turn,
    _update_ally_order_score,
    _refresh_order_table,
    update_score_state,
    check_time_limit,
)
