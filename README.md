# Pybert

Pybert is a Python port of Albert, a DAIDE Diplomacy bot. The implementation
is reconstructed from the recovered C routines in [`Source/`](Source/) and
uses [ALLAN-DIP/diplomacy](https://github.com/ALLAN-DIP/diplomacy) for game
state, order validation, and server integration.

The project is still a fidelity port rather than a finished drop-in
replacement. The current implementation generates Albert's complete opening
order set for all seven powers in the bounded `game_10.json` candidate oracle,
and the test suite contains 430 regressions. Exact submitted-order
matching is not yet a reliable oracle because the saved references do not
include Albert's PRNG call history or structured DAIDE press state. See
[`progress.md`](progress.md) for the current evidence and remaining work.

## Requirements and setup

- Python 3.13 or newer
- [uv](https://docs.astral.sh/uv/)
- A compatible `diplomacy` server when running live bots

Install the locked dependencies from the repository root:

```bash
uv sync
```

## Run a local seven-bot game

`run_7bots.py` creates a game and launches one Pybert process for each power:

```bash
uv run run_7bots.py --host localhost --port 8433 --deadline 0
```

Useful options:

| Option | Default | Description |
|---|---:|---|
| `--host` | `localhost` | Diplomacy server hostname. Port 443 uses TLS. |
| `--port` | `8433` | Diplomacy server port. |
| `--deadline` | `0` | Seconds per phase; zero waits for every bot. |
| `--press` | off | Create a full-press game and enable bot messaging. |
| `--pause-phase` | `W1910A` | Pause and save the game at this short phase name. |

Saved games and the detailed debug log are written under `games/`, which is
ignored by Git.

`main.py` contains the single-power client CLI. Its arguments can be inspected
with:

```bash
uv run python main.py --help
```

## Verify the port

Run the regression suite:

```bash
uv run python -m pytest -q
```

Compare generated orders with the saved Albert references:

```bash
# Small movement-phase smoke comparison
uv run compare_albert.py --max-games 5

# One bounded candidate-coverage run
uv run compare_albert.py \
  --game game_10.json \
  --phase S1901M \
  --candidate-coverage \
  --candidate-seed-count 10

# Check whether the reference corpus contains replayable DAIDE press
uv run compare_albert.py --audit-press-inputs
```

The comparison commands require matching files in `all_games/` and
`all_games_albert/`. Those corpora are local test data and are ignored by Git.
Candidate coverage is the structural oracle; submitted-order equality is only
diagnostic unless the original PRNG and press context are available.

## Repository layout

- `bot/` — client lifecycle, turn analysis, order submission, and strategy.
- `communications/` — inbound and outbound DAIDE press handling.
- `dispatch/` — order parsing, legality checks, serialization, and validation.
- `heuristics/` — board, influence, province, alliance, and adjustment scoring.
- `monte_carlo/` — candidate generation, evaluation, ranking, and turn trials.
- `moves/` — hold, support, and convoy construction.
- `utils/` — DAIDE token and DipNet translation helpers.
- `state.py` — the numeric and container state corresponding to Albert's
  process globals.
- `Source/` — recovered C routines used as the behavioral authority.
- `tests/` — source-backed regression tests.
- `compare_albert.py` — offline reference and candidate-coverage harness.
- `run_7bots.py` — live seven-power integration runner.
- `progress.md` — current verified checkpoint and implementation history.

## Known limitations

- The reference games contain human-readable press, not structured DAIDE
  messages, so XDO/ALY/DMZ state cannot be replayed faithfully.
- Exact final selection depends on an uncaptured process-wide MSVC CRT random
  stream and timing-dependent calls.
- The game 10 `S1904R` reference is inconsistent with its paired NOW state:
  the reference retreats `A ROM` to `VEN`, while the state permits only `APU`.
- Exact submitted-order matching remains diagnostic even when the complete
  reference set is generated, because the saved corpus lacks Albert's process
  PRNG state and structured press state.
