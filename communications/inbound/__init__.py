"""Inbound DAIDE message pipeline — facade for the split inbound package.

Originally a single 1,257-line ``inbound.py``.  Split into submodules
during the 2026-04 refactor; the flat public surface is preserved by
the re-exports below so nothing external needs to change.

Internal organisation:

* ``history``   — ``process_hst`` (HST history-message parser).
* ``ack``       — server-response classifiers: ``_ACK_TOK_YES`` /
  ``_ACK_TOK_REJ`` / ``_ACK_TOK_BWX``, ``_STANCE_TOKEN_CODES``,
  ``ack_matcher``, ``huh_err_strip_replay``, ``process_try``.
* ``gate``      — ``legitimacy_gate`` predicate + ``delay_review``
  (deferred-review queue) + ``register_received_press`` (ledger entry).
* ``frm``       — ``process_frm_message`` (FRM envelope dispatcher) +
  ``parse_message`` (top-level inbound router).
* ``respond``   — press-response generation: ``receive_proposal``,
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
from .frm import process_frm_message, parse_message
from .respond import receive_proposal, _respond_walk_pos_analysis, respond
