"""Inbound DAIDE message pipeline — facade for the split inbound package.

Originally a single 1,257-line ``inbound.py``.  Split into submodules
during the 2026-04 refactor; the flat public surface is preserved by
the re-exports below so nothing external needs to change.

Internal organisation:

* ``history``        — ``process_hst`` (HST history-message parser).
* ``ack``            — server-response classifiers: ``_ACK_TOK_YES`` /
  ``_ACK_TOK_REJ`` / ``_ACK_TOK_BWX``, ``_STANCE_TOKEN_CODES``,
  ``ack_matcher``, ``huh_err_strip_replay``, ``process_try``.
* ``gate``           — ``legitimacy_gate`` predicate + ``delay_review``
  (deferred-review queue) + ``register_received_press`` (ledger entry).
* ``hlo``            — ``hlo_dispatch`` (HLO message handler).
* ``not_handlers``   — NOT variant sub-handlers (CCD, TME, unknown).
* ``yes_handlers``   — YES variant sub-handlers (NME, OBS, IAM, NOT,
  GOF, TME, DRW, SND, unknown).
* ``server_handlers`` — top-level server message handlers (MAP, MDF,
  ORD, SCO, REJ, CCD, OUT, HUH, MIS, OFF, SVE, THX, TME, ADM, LOD).
* ``dispatcher``     — ``inbound_daide_dispatcher`` (top-level DAIDE router) +
  ``not_dispatcher`` (NOT variant dispatcher) + ``yes_dispatcher``
  (YES variant dispatcher).
* ``frm``            — ``process_frm_message`` (FRM envelope dispatcher) +
  ``parse_message`` (top-level inbound router).
* ``now_parser``     — ``parse_now`` (NOW message parser) +
  ``parse_now_unit`` (unit entry parser).
* ``respond``        — press-response generation: ``receive_proposal``,
  ``_respond_walk_pos_analysis``, ``respond``.
"""

from .history import process_hst
from .ack import (
    ack_matcher,
    huh_err_strip_replay,
    process_try,
    _ACK_TOK_YES,
    _ACK_TOK_REJ,
    _ACK_TOK_BWX,
    _STANCE_TOKEN_CODES,
)
from .gate import legitimacy_gate, delay_review, register_received_press
from .hlo import hlo_dispatch
from .not_handlers import handle_not_ccd, handle_not_tme, handle_not_unknown
from .yes_handlers import (
    handle_yes_nme, handle_yes_obs, handle_yes_iam, handle_yes_not,
    handle_yes_gof, handle_yes_tme, handle_yes_drw, handle_yes_snd,
    handle_yes_unknown,
)
from .server_handlers import (
    handle_map, handle_mdf, handle_ord, handle_sco, handle_rej,
    handle_ccd, handle_out, handle_huh, handle_mis, handle_off,
    handle_sve, handle_thx, handle_tme, handle_adm, handle_lod,
)
from .dispatcher import inbound_daide_dispatcher, not_dispatcher, yes_dispatcher
from .frm import process_frm_message, parse_message
from .now_parser import parse_now, parse_now_unit
from .respond import receive_proposal, _respond_walk_pos_analysis, respond
