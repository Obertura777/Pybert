// vtable +0xa8 — YES_TME handler (virtual method)
// Called from YESDispatcher (Source/communications/YESDispatcher.c) when the
// inner token of a YES message is TME:
//   YES ( TME ( seconds ) )
// Vtable call: (**(code **)(*(int *)this + 0xa8))(pvVar1, puVar4)
//   pvVar1   = full YES message TokenList
//   puVar4   = GetSubList(inner, 1) — the TME ( seconds ) sub-list
//
// Server has granted a time extension of <seconds> additional seconds for
// the current phase.  The handler extracts the seconds value and adds it
// to DAT_00624ef4 (g_move_time_limit_sec), which is the absolute phase
// deadline consulted by BuildAndSendSUB (line 343 / 649) and RESPOND
// (line 142) to gate late-phase press and order submission.
//
// DAT_00624ef4 is set initially by ParseHSTResponse (line 337) from the
// MTL/RTL time-limit token in the HLO message.  Subsequent YES(TME(n))
// arrivals extend it additively.
//
// Inner-state write:
//   DAT_00624ef4 += (int)(sVar1 & 0x3fff)   — seconds token (14-bit DAIDE field)
//
// This handler is the inverse of NOT_TME_Handler (vtable +0x50): that
// handler extracts the seconds token as informational only and does not
// update DAT_00624ef4; this handler does update it.
//
// Known body (estimated 30–35 instructions):
//   1. Set up exception frame.
//   2. GetSubList(puVar4, local_1c, 1) — extract TME body.
//   3. GetListElement(local_1c, ..., 0) — read seconds token.
//   4. DAT_00624ef4 += (int)(token & 0x3fff).
//   5. FreeList(local_1c).
//   6. Tear down frame and return.
//
// C References:
//   YESDispatcher → (Source/communications/YESDispatcher.c lines 69–74)
//   NOT_TME_Handler → (Source/communications/NOT_TME_Handler.c) — inverse
//   DAT_00624ef4 consumers: BuildAndSendSUB.c lines 343, 346, 649, 653
//                           RESPOND.c lines 142–143
//                           SendAllyPressByPower.c lines 41–42
//   DAT_00624ef4 setter:    ParseHSTResponse.c line 337
//
// Python equivalent: handle_yes_tme (communications/inbound/yes_handlers.py)
//   state.g_move_time_limit_sec += granted_secs

void __thiscall Albert_vtable_0xa8_YES_TME(void *this,void *full_msg,void *tme_sublist)

{
  short *psVar1;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497XX8;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Extract seconds value from TME ( seconds ) sub-list
  GetSubList(tme_sublist,local_1c,1);
  local_4 = 0;
  psVar1 = (short *)GetListElement(local_1c,(undefined2 *)&full_msg,0);

  // Add granted seconds to the absolute phase deadline.
  // DAIDE time tokens are 14-bit unsigned; mask off the type-byte.
  DAT_00624ef4 = DAT_00624ef4 + (int)((uint)(short)*psVar1 & 0x3fff);

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  return;
}
