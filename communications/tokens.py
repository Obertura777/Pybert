"""DAIDE token-sequence primitives.

Leaf helpers used across the communications subpackage.  None of these
functions depend on any other communications function; they were
extracted from ``communications.py`` during the 2026-04 structural
refactor to make the module tree easier to navigate.

Contains:

- DAIDE press-type token constants (``_TOK_ALY`` … ``_TOK_XDO``)
- TokenSeq primitives (``_token_seq_copy`` / ``_overlap`` / ``_no_overlap`` /
  ``_concat_single`` / ``_count`` / ``_less``)
- ``_wrap_single_token`` — build a ``[prefix, payload]`` token pair
- ``_get_daide_context_ptr`` — accessor for the per-thread DAIDE
  context (returns ``state.albert_power_idx``)

Historical C xrefs preserved in each docstring.
"""

from ..state import InnerGameState


# DAIDE press-type token constants (raw ushort values; keys in g_PerPowerPressHistory std::map).
# Confirmed from FUN_00418ed0 / FUN_004108a0 decompiles (2026-04-13).
_TOK_ALY = 0x4A00
_TOK_DMZ = 0x4A03
_TOK_ORR = 0x4A0F
_TOK_PCE = 0x4A10
_TOK_AND = 0x4A01
_TOK_VSS = 0x4A1C
_TOK_XDO = 0x4A1F


def _token_seq_copy(source_tokens) -> list:
    """
    Port of FUN_00465f60 — TokenSeq copy constructor.

    C signature: ``undefined4 * __thiscall FUN_00465f60(void *this, void **param_1)``

    16-byte output struct (4 × int32):
      this[0]  = pointer to flat ushort token buffer  (0 when empty)
      this[1]  = token count / empty sentinel         (0xffffffff when empty)
      this[2]  = pointer to int index array           (0 when empty)
      this[3]  = sub-list count / empty sentinel      (0xffffffff when empty)

    Flow:
      1. Zero this[0] and this[2].
      2. If param_1[0] (source buffer pointer) == NULL:
           set this[1] = this[3] = 0xffffffff, re-zero this[0]/this[2], return.
      3. Else: FUN_00465940(this, param_1[0], param_1[1])
               = TokenSeq_InitFromBuffer — copy tokens from raw buffer + length.

    Python mapping:
      Non-empty source  →  list(source_tokens)   [FUN_00465940 = TokenSeq_InitFromBuffer]
      Empty / None      →  []                    [empty struct, sentinel fields = 0xffffffff]

    Called from FUN_004325a0 (_execute_aly_vss) to build the recipient list and
    press-content token sequences consumed by PROPOSE.
    Also called from EvaluateOrderProposalsAndSendGOF, InitPositionForOrders,
    BuildAndSendSUB, BuildHostilityRecord, and RECEIVE_PROPOSAL.
    """
    return list(source_tokens) if source_tokens else []


def _token_seq_overlap(seq_a, seq_b) -> bool:
    """
    Port of FUN_00465d90 — token-seq overlap / containment check.

    C signature: ``bool __thiscall FUN_00465d90(void *this, int *param_1)``

    Returns True when the two token sequences share at least one element.
    Absorbed throughout the codebase as ``frozenset(a) & frozenset(b)``.

    Called from:
      receive_proposal               — deduplicate proposals against g_PosAnalysisList
      _respond_walk_pos_analysis     — match proposals for g_DeviationTree inserts
      _cancel_prior_press            — scan g_MasterOrderList for THN(<power>) entries
    """
    return bool(frozenset(seq_a) & frozenset(seq_b))


def _token_seq_no_overlap(seq_a, seq_b) -> bool:
    """
    Port of FUN_00465df0 — negated token-seq overlap check.

    C signature: ``bool __thiscall FUN_00465df0(void *this, int *param_1)``

    Decompiled body (decompiled.txt lines 128–135):
        bVar1 = FUN_00465d90(this, param_1);   // _token_seq_overlap
        return (bool)('\\x01' - bVar1);         // = !bVar1

    Returns True when the two token sequences share NO element.
    Called from BuildAndSendSUB as:
        FUN_00465df0(puVar31 + 10, (int *)apvStack_220)
    to gate whether a proposal's province list is disjoint from the current
    SUB token list — proposals that don't touch any ordered province are skipped.
    """
    return not _token_seq_overlap(seq_a, seq_b)


def _token_seq_concat_single(prefix_seq: list, out: list, payload_token: int) -> list:
    """
    Port of FUN_00466e10 — concatenate a prefix token-seq with one payload token
    into an output token-seq struct.

    C signature:
        uint ** __thiscall FUN_00466e10(void *this, uint **param_1, void *param_2)
          this    = prefix token sequence (TokenSeq)
          param_1 = output token sequence (written in place, returned)
          param_2 = pointer to single payload token (ushort *)

    Flow (decompiled.txt):
      1. FUN_00465940(local_1c, param_2, 1)
           — TokenSeq_InitFromBuffer: init a 1-element temp seq from *param_2.
      2. FUN_00466c40(this, param_1, local_1c)
           — concat: param_1 = prefix_seq + local_1c  (= prefix_seq + [payload_token]).
      3. EH cleanup: destruct + free temp buffer (absorbed).
      Returns param_1.

    Python: out[:] = list(prefix_seq) + [payload_token]; return out.

    Absorbed at call sites as ``list + [token]`` or ``seq.append(token)`` — see
    FUN_00466ed0 (_wrap_single_token) step 2, and the power-token loop in
    BuildAndSendSUB / SendAllyPressByPower.
    """
    out[:] = list(prefix_seq) + [payload_token]
    return out


def _token_seq_count(seq) -> int:
    """
    Port of FUN_00465930 — return the number of elements in a token sequence.

    C signature: ``uint __fastcall FUN_00465930(int param_1)``

    Decompiled body (decompiled.txt line 89):
        return -(uint)(*(uint *)(param_1 + 0xc) != 0xffffffff)
               & *(uint *)(param_1 + 0xc);

    The C TokenSeq struct stores its element count at offset +0xc; the sentinel
    value 0xffffffff marks an uninitialized / empty sequence (count = 0).
    The expression is a branchless idiom:
      * count == 0xffffffff  →  mask = 0           →  returns 0
      * count != 0xffffffff  →  mask = 0xffffffff  →  returns count

    Python mapping: an empty/uninitialized C seq (sentinel) ↔ None; live seq ↔ list.
    All call sites reduce to len() in the Python rewrite.

    Leaf function — no callees.
    """
    return len(seq) if seq is not None else 0


def _token_seq_less(seq_a, seq_b) -> bool:
    """Port of FUN_00465cf0 — lexicographic less-than for token sequences.

    addr: ``0x00465cf0``
    C signature: ``uint __thiscall FUN_00465cf0(void *this, int *param_1)``

    Both operands are 16-byte MSVC ``TokenSeq`` structs whose first two
    fields are:

    .. code-block:: text

        +0  ushort*  buffer   — pointer to flat ushort token array (NULL = empty)
        +4  int      count    — number of tokens (0xffffffff sentinel = empty)

    Decompiled logic (reconstructed):

    1. ``min_len = min(this->count, param_1->count)``
    2. If ``param_1->buffer == NULL`` (right-hand empty) → return ``False``
       (nothing is less-than an empty sequence).
    3. If ``this->buffer == NULL`` (left-hand empty, right-hand non-empty)
       → return ``True`` (empty precedes any non-empty sequence).
    4. Loop ``i`` in ``[0, min_len)``:
         - Compare ``this->buffer[i]`` vs ``param_1->buffer[i]`` as ``uint16``.
         - First mismatch determines result (< → True, > → False); exit loop.
    5. If all ``min_len`` elements are equal and no mismatch found:
         return ``(this->count < param_1->count)`` (shorter sequence is less).

    The CONCAT31/uVar6 manipulations in the Ghidra output are artefacts of
    the calling-convention flag-byte packing; the meaningful return is the
    low byte (0 = False, 1 = True).

    Python mapping:
      Token sequences are plain ``list[int]``.  Python's built-in tuple
      comparison is lexicographic over element values and uses length as a
      tiebreaker when one sequence is a prefix of the other — identical
      semantics.  The NULL-buffer edge cases map to empty lists, which
      Python handles correctly (``() < (x,)`` → True, ``(x,) < ()`` →
      False, ``() < ()`` → False).

      The function therefore reduces to ``tuple(seq_a) < tuple(seq_b)``.

    Called from:
      ``BuildAndSendSUB`` (``FUN_00457890``) as
      ``FUN_00465cf0(puVar18 + 3, puVar31 + 10)`` — compares a proposal
      entry's token-sequence key against a candidate sequence to decide
      ordering in the broadcast-list traversal.

      ``_ordered_token_seq_insert`` (``FUN_00419300``) — absorbed as Python
      tuple ``<`` inside ``bisect.bisect_left`` comparisons; not called
      explicitly there.

    Leaf function — no callees.
    """
    return tuple(seq_a) < tuple(seq_b)


def _wrap_single_token(prefix_token: int, payload_token: int) -> list:
    """
    Port of FUN_00466ed0 — wrap a single payload token with a prefix token.

    C signature: ``uint ** __thiscall FUN_00466ed0(void *this, uint **param_1, void *param_2)``

    Flow (decompiled.txt lines 95–125):
      1. FUN_00465940(local_1c, this, 1)
           — TokenSeq_InitFromBuffer: init a one-element temp list from the
             single prefix-token pointer ``this``.
      2. FUN_00466e10(local_1c, param_1, param_2)
           — append the single payload token (``*param_2``) into param_1,
             prepended by the temp list → param_1 = [prefix_token, payload_token].
      3. MSVC EH cleanup: destructs & frees the temp token buffer (absorbed).
      Returns param_1.

    Contrast with FUN_00466f80 which accepts a *list* of payload tokens
    (``[prefix] + list``); this variant takes exactly one token.

    Call sites:
      FUN_00466ed0(&THN, local, &power_token)   → [THN_token, power_token]
        (SendAllyPressByPower — builds THN(<power>) press sequence)
      FUN_00466ed0(&VSS, local, &enemy_token)   → [VSS_token, enemy_token]
        (_execute_aly_vss — builds VSS(<mutual_enemy>) clause)
      FUN_00466ed0(&FRM, local, puVar18+0x34)   → [FRM_token, token]
        (BuildAndSendSUB — builds FRM-prefixed token list)
    """
    return [prefix_token, payload_token]


def _get_daide_context_ptr(state: 'InnerGameState') -> int:
    """
    FUN_0047020b — TLS accessor for the per-thread DAIDE message context pointer.

    C: ``undefined4 * FUN_0047020b(void) { return &DAT_00bc46e4; }``

    DAT_00bc46e4 is a TLS slot that holds the game-context object.  Every call
    site immediately follows with the vtable dereference ``(*piVar6 + 0xc)`` to
    read the own-power index out of that object.  In Python the whole sequence
    collapses to a single attribute read on the shared state object.

    Returns:
        state.albert_power_idx — own power index (0-based).
    """
    return getattr(state, 'albert_power_idx', 0)
