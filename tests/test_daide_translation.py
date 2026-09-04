"""Regression coverage for coast-aware DAIDE/DipNet translation."""

import os
import sys


_PKG_ROOT = os.path.dirname(os.path.dirname(__file__))
_PARENT = os.path.dirname(_PKG_ROOT)
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)

_PKG = os.path.basename(_PKG_ROOT)
_translate = __import__(
    f"{_PKG}.utils.translate",
    fromlist=["daidefy_location", "dipnet_location"],
)


def test_all_daide_coast_directions_round_trip():
    coast_names = {
        "NC": "NCS", "NE": "NEC", "EC": "ECS", "SE": "SEC",
        "SC": "SCS", "SW": "SWC", "WC": "WCS", "NW": "NWC",
    }

    for dipnet_coast, daide_coast in coast_names.items():
        daide_location = f"( TST {daide_coast} )"
        assert _translate.daidefy_location(
            f"TST/{dipnet_coast}"
        ) == daide_location
        assert _translate.dipnet_location(daide_location) == (
            f"TST/{dipnet_coast}"
        )
