"""DAIDE/DipNet utility layer — facade for the split utils package.

Re-exports the flat public API of the original ``albert.utils`` module
so external callers (e.g. ``albert.bot`` → ``dipnet_order``) keep
working unchanged. Organized into four internal submodules:

  * ``.tokens``    — HEX/DAIDE/power lookup tables (constants only).
  * ``.daide``     — byte-level DAIDE helpers (sanitize, convert, hex).
  * ``.translate`` — location / unit / order translators.
  * ``.messages``  — DAIDE incoming-message processors (NOW/ORD/SCO/MRT/FRM).
"""

from .tokens import (
    HEX2DAIDE,
    DAIDE2HEX,
    POWER_NAMES,
    DIPNET2DAIDE_LOC,
    DAIDE2DIPNET_LOC,
)
from .daide import (
    sanitize_daide,
    split_by_two_characters,
    convert,
    convert_to_hex,
    decimal_to_hex,
    hex_to_decimal,
    cal_remaining_len,
)
from .translate import (
    dipnet_location,
    daidefy_location,
    dipnet_unit,
    daidefy_unit,
    get_unit_power,
    dipnet_order,
    daidefy_order,
)
# LEGACY — message processors removed from public API (2026-04-20).
# The runtime inbound pipeline lives in communications.inbound.parse_message.
# If you need these for offline format-conversion, import directly:
#   from albert.utils.messages import process_now, process_ord, ...
