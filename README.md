# Albert DAIDE Python Rewrite

Welcome to the Python rewrite of the **Albert** Diplomacy AI bot!

This directory (`albert/`) contains the structural rewrite of the original C++ Albert binary into modern standard Python, utilizing numpy for array acceleration and integrating cleanly with the modern [ALLAN-DIP/diplomacy](https://github.com/ALLAN-DIP/diplomacy) package for server integration..

## Modules

- `bot.py`: The `AlbertClient` orchestrator. Main `asyncio` loop connecting to the diplomacy server.
- `communications.py`: Parser and dispatcher for DAIDE press messages (`FRM`, `ALY`, `PRP`, `HLO`, `HST`, etc.).
- `dispatch.py`: `DispatchSingleOrder` — serialises a single order from the order table into a DAIDE `SUB` token sequence.
- `heuristics.py`: Province and position scoring (`EvaluateProvinceScore`, `ScoreProvinces`, `ComputeInfluenceMatrix`, etc.).
- `main.py`: CLI entry point — parses server, game, and press arguments, then launches the bot.
- `monte_carlo.py`: Monte Carlo order evaluation loop (`TrialEvaluateOrders`, `EvaluateOrderScore`), order-table field constants, and turn processing.
- `moves.py`: Move enumeration (`EnumerateConvoyReach`, `ComputeSafeReach`, `BuildSupportOpportunities`, etc.).
- `state.py`: `InnerGameState` — all numeric globals as numpy arrays (mirrors the binary's global address space).
- `utils.py`: DAIDE token ↔ DipNet string converters and province/power index helpers.

## Running

The bot is launched via `main.py`, which accepts CLI arguments for the server connection, game selection, press mode, and authentication.

### Quick start

```bash
# Connect to localhost, join the first available game as France with full press
python -m albert.main --power FRANCE

# Specify a remote server and game
python -m albert.main --host 192.168.1.10 --port 8433 --power ENGLAND --game-id game_123
```

### Full usage

```
python -m albert.main --power POWER [options]
```

| Argument | Default | Description |
|---|---|---|
| `--power` | *(required)* | Power to play: `AUSTRIA`, `ENGLAND`, `FRANCE`, `GERMANY`, `ITALY`, `RUSSIA`, or `TURKEY`. |
| `--host` | `localhost` | Server hostname or IP address. |
| `--port` | `8432` | Server port. |
| `--game-id` | *(auto)* | Game ID to join. Omit to join the first available game. |
| `--username` | `Albert_<POWER>` | Account username for authentication. |
| `--password` | `password` | Account password. |
| `--press` | `max` | Press mode: `none` (all messaging disabled) or `max` (full press: PCE, ALY, VSS, DMZ, XDO, AND, ORR). |
| `--log-level` | `INFO` | Logging verbosity: `DEBUG`, `INFO`, `WARNING`, `ERROR`, or `CRITICAL`. |

### Examples

```bash
# Play as Russia with no press on a remote server
python -m albert.main --host dipserver.local --port 16713 --power RUSSIA --press none

# Play as Austria with debug logging and custom credentials
python -m albert.main --power AUSTRIA --username my_bot --password s3cret --log-level DEBUG
```
