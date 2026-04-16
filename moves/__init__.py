"""Move / support / convoy enumeration — facade for the split moves package.

Re-exports the flat public API of the original ``albert.moves`` module
so external callers (``albert.monte_carlo`` and ``albert.heuristics``)
keep working unchanged. Organized into three internal submodules:

  * ``.hold``    — hold-weight population, safe-reach scoring.
  * ``.support`` — support opportunity enumeration, assignment, proposals.
  * ``.convoy``  — convoy-reach BFS, fleet registration, convoy orders.
"""

from .hold import (
    enumerate_hold_orders,
    compute_safe_reach,
)
from .support import (
    build_support_opportunities,
    assign_support_order,
    build_support_proposals,
)
from .convoy import (
    enumerate_convoy_reach,
    register_convoy_fleet,
    build_convoy_orders,
)
