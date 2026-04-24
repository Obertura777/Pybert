"""Shared constants used across multiple bot submodules.

Split from bot.py during the 2026-04 refactor.

Holds module-level lookup tables that were previously defined at the top of
bot.py and referenced from multiple clusters.  Leaf module: no imports from
other bot submodules, avoiding circular-import pitfalls.
"""

_POWER_NAMES = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]

# DAIDE coast token value → DipNet coast suffix (subset covering standard coasts)
_DAIDE_COAST_TO_STR = {
    0x4600: 'NC', 0x4602: 'NE', 0x4604: 'EC',
    0x4606: 'SC', 0x4608: 'SC', 0x460A: 'SW',
    0x460C: 'WC', 0x460E: 'NW',
    0: '',
}

# Power index → DAIDE short token name (AUS=0x4100 … TUR=0x4106)
_DAIDE_POWER_NAMES = ['AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
