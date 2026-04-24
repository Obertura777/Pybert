"""Alliance-tree, STL container, and hostility-record helpers.

Split from communications/__init__.py during the 2026-04 refactor.

This submodule hosts the decompiled MSVC ``std::set<int>`` / ``std::_Tree``
RB-tree ports (alliance_tree_find_or_insert, _stl_tree_copy,
_stl_tree_erase_node, _ordered_token_seq_insert, _copy_stl_ordered_set) plus
the per-power BuildHostilityRecord copy-constructor and BuildAllianceMsg
entry point.  Pure container bookkeeping — no DAIDE parsing, no network,
no dependencies on sibling comms submodules.
"""

from ..state import InnerGameState


# ── AllianceTree insert (FUN_00414a10 / FUN_00413fd0) ────────────────────────

def alliance_tree_find_or_insert(state: "InnerGameState", key: int) -> tuple:
    """AllianceTree_FindOrInsert — MSVC ``std::set<int>`` BST insert + RB fixup.

    addr: ``0x00414a10``
    C signature: ``void __thiscall FUN_00414a10(void *this, void **param_1,
                    char param_2, int **param_3, undefined4 *param_4)``

    This is the MSVC ``std::set<int>::insert`` fast-path called by
    ``BuildAllianceMsg`` (``FUN_00413fd0``) after the BST descent has located
    the insertion slot.  The C implementation:

      1. Rejects inserts when ``*(uint*)(this+8) > 0x1ffffffd`` (size limit) —
         throws ``std::length_error("map/set<T> too long")``.
      2. Calls ``FUN_00411c40`` (``operator_new(0x18)``-based node ctor) to
         allocate a 24-byte RB-tree node and initialise its fields::

             node[+0x00] = param_1            # _Left  (left child ptr)
             node[+0x04] = param_2            # _Parent (parent ptr)
             node[+0x08] = param_3            # _Right  (right child ptr)
             node[+0x0C] = *param_4           # int key (e.g. elapsed_s+10000)
             node[+0x10] = CSimpleStringT     # cloned ATL CString ptr
                             .CloneData(param_4[1] - 0x10) + 0x10
             byte(node+0x14) = param_5        # _Color (0=RED, nonzero=BLACK)
             byte(node+0x15) = 0              # _Isnil = 0 (real node)
      3. Increments ``*(this+8)`` (``_Mysize``).
      4. Links the new node into the min/max bookkeeping pointers held in
         ``*(this+4)`` (``_Myhead``).
      5. RB-tree colour fixup while ``parent.color == red``:
           - Uncle is red   → recolour uncle + parent black, grandparent red,
                              walk up.
           - Uncle is black + new node is inner child → rotate to make it outer
                              (``FUN_0040f170`` left-rotate or ``FUN_0040e050``
                              right-rotate on parent), then fall through.
           - Uncle is black + new node is outer child → recolour parent black,
                              grandparent red, rotate grandparent the other way.
      6. Forces root black: ``*(this+4)->_Parent.color = black``.
      7. Writes ``param_1[0] = this`` (container back-pointer) and
         ``param_1[1] = new_node`` (node pointer).

    In Python ``g_alliance_msg_tree`` (``DAT_00bbf638``) is a plain ``set``; all
    pointer-wiring and RB rebalancing collapse to a single ``set.add``.  The
    return value mirrors the C ``param_1`` pair:

      (container_set, key, was_inserted: bool)

    Callees (C):
      FUN_00411c40 — 24-byte RB-tree node allocator (left/parent/right +
                     int key + ATL CString clone + color + isnil)
      FUN_0040f170 — RB-tree left-rotation (insert fixup)
      FUN_0040e050 — RB-tree right-rotation (insert fixup)
      FUN_00402650 — ``std::length_error`` constructor (exception path only)
      FUN_00402a30 — MSVC exception rethrow helper (exception path only)
    """
    was_inserted = key not in state.g_alliance_msg_tree
    state.g_alliance_msg_tree.add(key)
    return state.g_alliance_msg_tree, key, was_inserted


def build_alliance_msg(state: "InnerGameState", key: int) -> tuple:
    """BuildAllianceMsg — insert a power key into the alliance BST.

    addr: ``0x00413fd0``
    C signature: ``void __thiscall BuildAllianceMsg(void *this,
                    undefined4 *param_1, int *param_2)``

    Traverses the ``std::set<int>`` rooted at ``this`` (``DAT_00bbf638``) to
    find the insertion slot for ``*param_2`` (power index), then delegates the
    actual insert + RB fixup to ``AllianceTree_FindOrInsert`` (``FUN_00414a10``).
    Writes the resulting ``(container, node)`` pair plus a proposal-active flag
    into the caller's ``param_1`` output buffer::

        param_1[0] = container_ptr   (this)
        param_1[1] = node_ptr        (new or existing node)
        param_1[2] = 1               (proposal-active flag, set by caller)

    BST traversal uses ``node+0x0`` (left) / ``node+0x8`` (right) child pointers
    and compares ``*param_2`` against ``node+0xc`` (key).  Nil sentinel check:
    ``*(char*)(node + 0x15) == '\\0'``.

    Returns the same ``(container, key, flag=1)`` triple that the C caller reads
    from its stack buffer.
    """
    container, node, _ = alliance_tree_find_or_insert(state, key)
    return container, node, 1   # param_1[2] = 1 (proposal-active flag)


# ── STL tree copy (FUN_00401d70) ──────────────────────────────────────────────

def _stl_tree_copy(dest: list, source: list) -> list:
    """MSVC ``std::_Tree::_Copy`` — recursive BST deep-copy.

    addr: ``0x00401d70``
    C signature: ``undefined4 * __thiscall FUN_00401d70(void *this,
                     undefined4 *param_1, undefined4 param_2)``

    Recursively copies the BST rooted at *param_1* into the destination tree
    (*this*), allocating each new node via ``FUN_00401b40`` (_Buynode), then
    wiring left/right children from the recursive results.

    Node layout for this tree type (compact, 18 bytes minimum):
      +0x00  ``_Left``   — left-child pointer  (param_1[0])
      +0x04  ``_Parent`` — parent pointer      (param_1[1])
      +0x08  ``_Right``  — right-child pointer (param_1[2])
      +0x0C  ``_Value``  — key/value data       (param_1+3; passed to _Buynode)
      +0x10  ``_Color``  — RB-tree color byte
      +0x11  ``_Isnil``  — non-zero = sentinel/nil node
                           (checked at +0x11; distinct from g_order_list which
                           uses +0x21; this is a smaller per-proposal-orders
                           tree type)

    Control flow:
      if param_1._Isnil == 0  (real node):
          puVar1  = _Buynode(head, parent=param_2, left=head,
                             val=param_1.value, color=param_1.color)
          if sentinel._Isnil != 0:   # always true for the sentinel
              local_18 = puVar1      # track begin / return root copy
          puVar1.left  = _Copy(this, param_1.left,  puVar1)
          puVar1.right = _Copy(this, param_1.right, puVar1)
          return puVar1
      else:                          # nil sentinel node
          return this->_Myhead       # return destination sentinel unchanged

    In Python the tree is a sorted ``list[dict]``; all pointer/coloring
    bookkeeping disappears.  The function reduces to a deep-copy of the
    source list into (and replacing) the destination list.

    Callees (C):
      FUN_00401b40 — ``std::_Tree::_Buynode``: allocates + initialises one
                     node with (head, parent, left=head, value, color);
                     see unchecked.md
    """
    import copy
    dest.clear()
    dest.extend(copy.deepcopy(source))
    return dest


# ── STL tree erase (FUN_00402b70) ─────────────────────────────────────────────

def _stl_tree_erase_node(tree: list, idx: int) -> int:
    """MSVC ``std::_Tree::erase(iterator)`` — erase one node from the sorted list.

    addr: ``0x00402b70``
    C signature: ``void __thiscall FUN_00402b70(void *this, int *param_1,
                    int param_2, int **param_3)``

    Operates on the same per-proposal-orders tree type as ``_stl_tree_copy``
    (compact node layout: ``_Color`` at ``+0x10``, ``_Isnil`` at ``+0x11``).

    C algorithm:
      1. Validate *param_3* (the node to erase) is not the nil sentinel
         (``*(char*)(param_3 + 0x11) != 0`` → throws
         ``std::out_of_range("invalid map/set<T> iterator")`` via
         ``FUN_00402650`` + ``FUN_00402a30``).
      2. ``TreeIterator_Advance(&param_2)`` — advance *param_2* to the
         in-order successor of *param_3*.
      3. Determine the replacement / splice node:
         - left child non-nil  → replacement = left child
         - else                → replacement = right child
         (The two-child splice branch guarded by ``param_3 != _Memory`` is dead
         code: ``_Memory = param_3`` at entry, so the condition is always
         false; Ghidra emits the branch but it is unreachable.)
      4. Update all parent/child back-pointers bypassing the erased node;
         update header's leftmost (``this+4``→``*header``) and rightmost
         (``this+4``→``header[2]``) via ``FUN_004010a0`` / ``FUN_00401080``
         when the erased node was the current begin or end.
      5. RB-tree delete fixup (``LAB_00402ce5``): iterate up the tree
         correcting colours via left-rotations (``FUN_004016a0``) and
         right-rotations (``FUN_004010c0``).
      6. ``_free(_Memory)`` + ``this->_Mysize -= 1``.
      7. Write successor iterator into ``*param_1``.

    Node layout (same tree type as ``_stl_tree_copy``):
      +0x00  ``_Left``   — left child
      +0x04  ``_Parent`` — parent
      +0x08  ``_Right``  — right child
      +0x0C  ``_Value``  — 4-byte key/value
      +0x10  ``_Color``  — RB colour byte (0 = red, 1 = black)
      +0x11  ``_Isnil``  — non-zero = sentinel/nil node

    Python representation: the tree is a sorted ``list[dict]``; all
    pointer/colour bookkeeping disappears.  The function reduces to removing
    the entry at *idx* and returning the new index of the successor (which,
    after deletion, is automatically ``idx``).

    Raises ``IndexError`` if *idx* is out of range (mirrors the C
    ``std::out_of_range`` throw for the end-sentinel / past-the-end check).

    Callees (C):
      FUN_00402650         — ``std::string`` ctor from ``(char*, size_t)``
                             builds the "invalid map/set<T> iterator" message
      FUN_00402a30         — ``std::out_of_range`` constructor
      TreeIterator_Advance — in-order successor step (Ghidra-named; analogous
                             to ``std_Tree_IteratorIncrement`` at 0x0040f6f0
                             but for this compact tree type; address unknown)
      FUN_004010a0         — leftmost-descendant finder; returns new begin
                             after the old leftmost node is erased
      FUN_00401080         — rightmost-descendant finder; returns new end
                             (rightmost) after the old rightmost node is erased
      FUN_004016a0         — RB-tree left-rotation used in delete fixup
      FUN_004010c0         — RB-tree right-rotation used in delete fixup
    """
    if idx < 0 or idx >= len(tree):
        raise IndexError("invalid map/set<T> iterator")
    tree.pop(idx)
    # After deletion 'idx' naturally addresses the former successor (or
    # len(tree) when the erased entry was the last), matching the C behaviour
    # where *param_1 is set to the advanced iterator after the node is freed.
    return idx


# ── HostilityRecord ───────────────────────────────────────────────────────────

def build_hostility_record(src: dict) -> dict:
    """Copy constructor for HostilityRecord.

    C: ``undefined * __thiscall BuildHostilityRecord(void *this, undefined *param_1)``

    Copies every field from *src* (param_1) into a new record (this) using the
    appropriate per-field copy operation, then returns the destination.  In
    Python, all C field copies collapse to a single ``copy.deepcopy``.

    Struct layout (C offset → Python key):
      +0x00  1B   'flag_0'        — leading flag/type byte
      +0x04  4B   'int_4'         — dword
      +0x08  4B   'int_8'         — dword
      +0x0c  12B  'obj_0c'        — 12-byte token/proposal object
                                    (FUN_00405090 copy constructor)
      +0x18  12B  'obj_18'        — 12-byte object
                                    (FUN_0041c3c0 copy constructor)
      +0x24  12B  'obj_24'        — 12-byte object
                                    (FUN_0041c3c0 copy constructor)
      +0x30  84B  'trust_row'     — 21×int32 raw copy (one g_ally_trust_score row)
      +0x84  4B   'int_84'        — dword
      +0x88  16B  'token_list_88' — token list (FUN_00465f60 copy)
      +0x98  1B   'flag_98'       — flag byte
      +0xa0  4B   'int_a0'        — dword
      +0xa4  4B   'int_a4'        — dword
      +0xa8  16B  'token_list_a8' — token list (FUN_00465f60 copy)
      +0xb8  2B   'word_b8'       — word
      +0xbc  16B  'token_list_bc' — token list (FUN_00465f60 copy)

    Callees (C):
      FUN_00405090  — 12-byte object copy (already in unchecked)
      FUN_0041c3c0  — 12-byte STL set copy constructor (see below)
      FUN_00465f60  — token-list copy (already in unchecked)
    """
    import copy
    return copy.deepcopy(src)


def _ordered_token_seq_insert(container: list, key_seq) -> tuple:
    """Port of FUN_00419300 — MSVC ``std::set<TokenSeq>::insert(value)``.

    addr: ``0x00419300``
    C signature: ``void __thiscall FUN_00419300(void *this,
                    void **param_1, void **param_2)``

    The C body is a full MSVC RB-tree insert for a ``std::set`` whose element
    type is a token-sequence list.  It descends the tree from root using
    ``FUN_00465cf0`` (token-sequence less-than comparator, ``+0x1d`` sentinel
    flag) to locate the insertion point, then detects duplicates in two paths:

      * Last BST step went LEFT (``local_c != 0``, ``param_2 < parent.key``):
        if parent is the leftmost node → fast-insert (no predecessor possible);
        otherwise call ``FUN_00401790`` to step back to the in-order
        predecessor and re-check ``FUN_00465cf0(predecessor.key, param_2)``.
        If predecessor >= param_2 the keys are equal → no insert.
      * Last BST step went RIGHT (``local_c == 0``, ``param_2 >= parent.key``):
        check ``FUN_00465cf0(parent.key, param_2)``; if parent >= param_2 the
        keys are equal → no insert.

    On successful insert, ``FUN_004134d0`` allocates and splices a new RB-tree
    node.  The result is written through *param_1*:

      param_1[0]  — iterator node pointer (existing or newly inserted)
      param_1[1]  — iterator ``_Myhead`` (header/sentinel pointer)
      param_1[2]  — bool: 1 = new node inserted, 0 = key already existed

    The 12-byte ``this`` layout::

        +0  allocator/compare  (zeroed)
        +4  _Myhead            (sentinel node ptr; [0]=leftmost, [1]=root, [2]=rightmost)
        +8  _Mysize            (element count)

    Sentinel node: ``node + 0x1d`` = ``_Isnil`` flag (0 = real node, 1 = nil).

    Python mapping:
      *container*  — sorted ``list[tuple]`` representing the BST in-order
                     contents; Python lexicographic tuple comparison matches
                     ``FUN_00465cf0`` semantics exactly.
      *key_seq*    — iterable token sequence; normalised to ``tuple``.
      Returns ``(key_tuple, inserted: bool)``.

    Callees absorbed:
      FUN_00465cf0 — TokenSeq less-than comparator (tuple ``<``)
      FUN_004134d0 — RB-tree node allocate-and-insert (``list.insert`` via bisect)
      FUN_00401790 — in-order predecessor step (not required in Python)
    """
    import bisect
    key = tuple(key_seq)
    idx = bisect.bisect_left(container, key)
    if idx < len(container) and container[idx] == key:
        return (container[idx], False)
    container.insert(idx, key)
    return (key, True)


def _copy_stl_ordered_set(src):
    """Copy constructor for a 12-byte MSVC ``std::set<int>`` (FUN_0041c3c0).

    C signature: ``void * __thiscall FUN_0041c3c0(void *this, int param_1)``

    Called from BuildHostilityRecord for the 'obj_18' and 'obj_24' fields::

        FUN_0041c3c0((void *)(this + 0x18), (int)(param_1 + 0x18))
        FUN_0041c3c0((void *)(this + 0x24), (int)(param_1 + 0x24))

    The C++ body has two phases:

    **Phase 1 — default-construct an empty set (``this``)**:

    * ``FUN_0040fd90()`` — ``operator_new(0x20)``; zeros offsets 0/4/8
      (``_Left``/``_Parent``/``_Right``); sets ``+0x1c = 1`` (``_Color =
      BLACK``); explicitly sets ``+0x1d = 0`` (``_Isnil`` starts as 0 —
      NOT yet a sentinel; the caller marks it).  Returns the raw pointer
      in EAX (Ghidra shows ``void`` return but value survives in EAX).
      Same structural role as ``FUN_00401e30`` inside ``StdSet_Init``
      (``FUN_00405660``).
    * Stores the sentinel at ``this+4`` (``_Myhead``).
    * Marks the sentinel: ``sentinel+0x1d = 1`` (``_Isnil`` flag) and sets
      ``_Left = _Parent = _Right = sentinel`` (circular self-links for an
      empty RB-tree head).  These two steps are done by the caller
      (``FUN_0041c3c0``), not by ``FUN_0040fd90``.
    * Sets ``this+8 = 0`` (``_Mysize``).

    **Phase 2 — copy-assign from source**:

    * ``FUN_00411a80(this, param_1)`` — the MSVC ``_Tree::_Copy`` helper;
      walks the source tree in-order and inserts each element into ``this``.

    The 12-byte container layout is::

        this+0   4B  allocator/compare (unused — zero-initialised by caller)
        this+4   4B  _Myhead  (sentinel node ptr)
        this+8   4B  _Mysize  (element count)

    Python absorption: both phases collapse to ``copy.deepcopy(src)`` because
    ``src`` is already the correct Python container (``set`` of ints).

    Callees (C) — absorbed:
      FUN_0040fd90  — allocate BST sentinel node (absorbed as Python alloc)
      FUN_00411a80  — MSVC ``_Tree::_Copy``: outer copy driver; calls
                      FUN_00410db0 on the source root (absorbed as deepcopy)
      FUN_00410db0  — MSVC ``_Tree::_Copy_nodes``: recursive pre-order node
                      copy; for each non-nil src node calls FUN_0040fdd0 to
                      allocate a dst node (copying key at src+0x0c and color
                      byte at src+0x1c), then recurses into left (*src) and
                      right (src[2]) with parent=new_node; returns new_node
                      or dst sentinel (absorbed as deepcopy)
      FUN_0040fdd0  — MSVC ``_Tree::_Buynode``: allocates a raw tree node,
                      sets _Left=_Right=sentinel, _Parent=arg2, copies key
                      from arg4, sets _Color=arg5 (absorbed as Python alloc)
    """
    import copy
    return copy.deepcopy(src)
