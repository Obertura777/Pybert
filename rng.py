"""Process-global Microsoft CRT pseudo-random stream used by Albert.

The 32-bit Windows binary calls MSVC ``rand()`` throughout the order, board,
and press code.  Python's :mod:`random` uses a different algorithm, so equal
integer seeds cannot reproduce the binary's values or branch sequence.

No ``srand`` call is present in the recovered source set.  MSVC starts with
seed 1 when ``srand`` is never called; callers such as the offline oracle may
still set an explicit seed to explore or replay a captured stream.
"""

from __future__ import annotations

_state = 1


def seed(value: int = 1) -> None:
    """Set the unsigned 32-bit CRT state (``srand`` semantics)."""
    global _state
    _state = int(value) & 0xFFFFFFFF


def getstate() -> int:
    """Return the current unsigned 32-bit state for diagnostics/replay."""
    return _state


def setstate(value: int) -> None:
    """Restore a state previously returned by :func:`getstate`."""
    seed(value)


def raw_rand() -> int:
    """Return one MSVC ``rand()`` output in the inclusive range 0..32767."""
    global _state
    _state = (_state * 214013 + 2531011) & 0xFFFFFFFF
    return (_state >> 16) & 0x7FFF


def randrange(stop: int) -> int:
    """Mirror Albert's recurring ``(rand() / 0x17) % stop`` expression."""
    stop = int(stop)
    if stop <= 0:
        raise ValueError("empty range for randrange()")
    return (raw_rand() // 0x17) % stop


def randint(start: int, stop: int) -> int:
    """Compatibility seam for existing raw-rand injection tests.

    Recovered call sites use ``randint(0, 0x7fff)`` when they need the raw CRT
    value.  Other inclusive ranges retain conventional ``randint`` behavior
    while consuming exactly one CRT value.
    """
    start = int(start)
    stop = int(stop)
    if stop < start:
        raise ValueError("empty range for randint()")
    if start == 0 and stop == 0x7FFF:
        return raw_rand()
    return start + randrange(stop - start + 1)
