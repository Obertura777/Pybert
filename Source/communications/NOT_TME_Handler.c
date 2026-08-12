// vtable +0x50 — NOT_TME handler (virtual method)
// Called from NOTDispatcher (Source/communications/NOTDispatcher.c) when the
// inner token of a NOT message is TME:
//   NOT ( TME ( seconds ) )
// Vtable call: (**(code **)(*(int *)this + 0x50))(pvVar1, puVar4)
//   pvVar1   = full NOT message TokenList
//   puVar4   = GetSubList(inner, 1) — the TME ( seconds ) sub-list
//
// The server sends NOT(TME) to reject a time-extension request that Albert
// sent (via TME ( seconds )). This is a pure informational rejection: Albert
// does not retry or adjust its time-limit tracking — CheckTimeLimit already
// uses the HST/MTL wall-clock value directly.
//
// This handler is a virtual method override on the Albert subclass (not a
// standalone named function). Ghidra's vtable reconstruction did not produce
// a standalone FUN_XXXXXXXX for slot +0x50; the implementation below is
// reconstructed from cross-references and call-site context.
//
// Known body (25–30 instructions):
//   1. Set up exception frame (local_c / puStack_8 / ExceptionList pattern).
//   2. GetSubList(puVar4, local_1c, 1) — extract seconds from TME body.
//   3. GetListElement(local_1c, ..., 0) → seconds token (informational only).
//   4. FreeList(local_1c).
//   5. Tear down frame and return.
// No inner-state writes confirmed; the rejection is logged but not recorded
// in any durable field (unlike YES(TME) which would update g_tme_deadline).
//
// C References:
//   NOTDispatcher → (Source/communications/NOTDispatcher.c line 33-38)
//   Compare: YES(TME) handler at vtable +0xa8 (grants extension, updates clock)
//
// Python equivalent: handle_not_tme (communications/inbound/not_handlers.py)
//   logs the rejection; no state mutation.

void __thiscall Albert_vtable_0x50_NOT_TME(void *this,void *full_msg,void *tme_sublist)

{
  short *psVar1;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_004979e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Extract seconds value from TME ( seconds ) sub-list — informational only
  GetSubList(tme_sublist,local_1c,1);
  local_4 = 0;
  psVar1 = (short *)GetListElement(local_1c,(undefined2 *)&full_msg,0);
  (void)*psVar1;   // value read but not stored — server's rejection is final

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  return;
}
