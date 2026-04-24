"""AlbertClient — NetworkGame adapter wrapping the Albert bot pipeline.

Originally a single 1,207-line ``client.py``.  Split into three mixin
submodules during the 2026-04 refactor; the flat public surface — one
name, ``AlbertClient`` — is preserved by the composition below so
nothing external needs to change.

Internal organisation:

* ``_lifecycle.py`` — ``_LifecycleMixin``: connection, asyncio turn
  loop, inbound-press draining, game/message callbacks, and
  ``__init__`` (instance-state construction).
* ``_orders.py``    — ``_OrdersMixin``: the big per-turn order
  generation pipeline (``generate_and_submit_orders``), order
  validation, and adjustment-phase submission.
* ``_press.py``     — ``_PressMixin``: direct-message press sending,
  SUB (orders-message) builder, and draw-vote submission.

Cross-mixin method calls (e.g. ``_LifecycleMixin.on_game_update`` ->
``generate_and_submit_orders`` on the ``_OrdersMixin``) resolve
through normal Python MRO at call time — the class hierarchy is
linearised as ``AlbertClient -> _OrdersMixin -> _PressMixin ->
_LifecycleMixin -> object``.
"""

from ._lifecycle import _LifecycleMixin
from ._orders import _OrdersMixin
from ._press import _PressMixin


class AlbertClient(_OrdersMixin, _PressMixin, _LifecycleMixin):
    pass
