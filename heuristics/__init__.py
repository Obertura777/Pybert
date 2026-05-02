import numpy as np
from ..state import InnerGameState

from ._primitives import (
    evaluate_province_score, compute_winter_builds,
    _safe_pow, _float_to_int64, evaluate_alliance_score,
)
from .board import cal_board
from .influence import (
    apply_influence_scores, update_relation_history,
    compute_influence_matrix, normalize_influence_matrix,
    compute_alliance_score, set_opening_targets,
)
from .scoring import (
    score_order_candidates_all_powers,
    score_order_candidates_own_power,
    apply_press_corroboration_penalty,
    score_provinces,
    _PRESS_DISAGREE_PENALTY,
)
from .win import (
    populate_build_candidates,
    populate_remove_candidates,
    compute_win_builds,
    compute_win_removes,
    _WIN_BUILD_WEIGHTS,
    _WIN_REMOVE_WEIGHTS,
    _SPR_ROUND_WEIGHTS,
    _FAL_ROUND_WEIGHTS,
    _SPR_FAL_WEIGHTS,
    _WIN_DAIDE_POWER_NAMES,
)
from .strategy import (
    compute_draw_vote,
    post_process_orders,
    generate_self_proposals,
    compute_press,
)
from .snapshot import snapshot_province_state
