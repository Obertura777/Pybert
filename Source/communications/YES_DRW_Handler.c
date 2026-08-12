// vtable +0xac — YES_DRW handler (virtual method)
// Called from YESDispatcher (Source/communications/YESDispatcher.c) when the
// inner token of a YES message is DRW:
//   YES ( DRW )
// Vtable call: (**(code **)(*(int *)this + 0xac))(pvVar1, puVar4)
//   pvVar1   = full YES message TokenList
//   puVar4   = GetSubList(inner, 1) — the DRW sub-list (no sub-parameters)
//
// Server has registered Albert's draw vote.  This does NOT end the game;
// the game-ending draw signal arrives as a bare top-level DRW message
// (handled by InboundDAIDEDispatcher line 65–68: sets inner+0x2449 = 1,
// then fires vtable +0x18).
//
// YES(DRW) is purely a confirmation that our DRW proposal was accepted by
// the server.  DAT_00baed5d (g_draw_sent / "want to draw" flag), which is
// set to 1 by GenerateAndSubmitOrders (line 492) when the board evaluation
// decides to vote for a draw, is left unchanged — our vote remains active
// until the game ends or we send NOT(DRW).
//
// DAT_00baed2b (ComputeDrawVote result, set by PrepareDrawVoteSet) is also
// left unchanged.
//
// Known body (estimated 20–25 instructions):
//   1. Set up exception frame.
//   2. GetSubList(puVar4, local_1c, 1) — extract DRW body (empty; no sub-params).
//   3. No inner-state writes — draw-vote confirmation is informational.
//      DAT_00baed5d (g_draw_sent) stays at 1; vote remains active.
//   4. FreeList(local_1c).
//   5. Tear down frame and return.
//
// C References:
//   YESDispatcher → (Source/communications/YESDispatcher.c lines 78–83)
//   InboundDAIDEDispatcher → bare DRW game-end (Source/communications/
//                            InboundDAIDEDispatcher.c lines 65–68)
//   DAT_00baed5d setter:  GenerateAndSubmitOrders.c lines 492, 503
//   DAT_00baed5d consumer: _eval_drw.c line 116 (Albert's own draw-eval)
//
// Python equivalent: handle_yes_drw (communications/inbound/yes_handlers.py)
//   logs "draw proposal accepted (vote registered)"; no state mutation.

void __thiscall Albert_vtable_0xac_YES_DRW(void *this,void *full_msg,void *drw_sublist)

{
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497XX4;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // DRW carries no sub-parameters; extract sub-group 1 for structural
  // consistency with sibling YES-variant handlers.
  GetSubList(drw_sublist,local_1c,1);
  local_4 = 0;
  // No inner-state writes — DAT_00baed5d (g_draw_sent) stays at 1.
  // The game-end DRW arrives separately as a top-level DRW message.

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  return;
}
