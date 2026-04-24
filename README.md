# Albert DAIDE Python Rewrite

Welcome to the Python rewrite of the **Albert** Diplomacy AI bot!

This directory (`albert/`) contains the structural rewrite of the original C++ Albert binary into modern standard Python, utilizing numpy for array acceleration and integrating cleanly with the modern [ALLAN-DIP/diplomacy](https://github.com/ALLAN-DIP/diplomacy) package for server integration.

## Design Philosophy

The original Albert uses high-precision math and raw memory manipulation (e.g., deep-copying `1556`-byte memory blocks for its turn simulations) bound natively to the DCSP wire protocol and DAIDE tokens. The modernization strategy revolves around isolating the "brain" (the MC evaluator and heuristics) from the "mouth" (how it speaks to the server). 

- **Internal State:** Kept as fast numpy arrays mirroring the binary's `InnerGameState` (found in `state.py`).
- **Translation Layer:** Mapped via `utils.py` and `communications.py` to seamlessly convert standard DAIDE tags (`( FRA AMY PAR ) MTO BUR`) into DipNet formatting (`A PAR - BUR`).
- **Network Interface:** `bot.py` utilizes modern `asyncio`/websockets to manage updates.

## Modules

- `bot.py`: The `AlbertClient` orchestrator. Main `asyncio` loop connecting to the diplomacy server.
- `communications.py`: Parser and dispatcher for DAIDE press messages (`FRM`, `ALY`, `PRP`, `HLO`, `HST`, etc.).
- `dispatch.py`: `DispatchSingleOrder` — serialises a single order from the order table into a DAIDE `SUB` token sequence.
- `heuristics.py`: Province and position scoring (`EvaluateProvinceScore`, `ScoreProvinces`, `ComputeInfluenceMatrix`, etc.).
- `main.py`: Entry point (`main()`).
- `monte_carlo.py`: Monte Carlo order evaluation loop (`TrialEvaluateOrders`, `EvaluateOrderScore`), order-table field constants, and turn processing.
- `moves.py`: Move enumeration (`EnumerateConvoyReach`, `ComputeSafeReach`, `BuildSupportOpportunities`, etc.).
- `state.py`: `InnerGameState` — all numeric globals as numpy arrays (mirrors the binary's global address space).
- `utils.py`: DAIDE token ↔ DipNet string converters and province/power index helpers.

## Running

*Entry point not yet wired up.* Once complete:
```bash
python -m albert.main --server 0.0.0.0:16713 --power AUS
```
