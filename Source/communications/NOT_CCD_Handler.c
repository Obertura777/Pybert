// FUN_0045e9f0 — NOT_CCD handler
// Called from NOTDispatcher (Source/communications/NOTDispatcher.c) when the
// inner token of a NOT message is CCD:
//   NOT ( CCD ( power ) )
// Signature: FUN_0045e9f0(this, full_not_msg, ccd_sublist)
//
// Reversal of CCD_Handler (FUN_0045e470): clears byte [power_idx] at
// inner+0x25a8 to indicate the power has reconnected and is no longer in
// civil disorder. Does NOT clear the OUT flag at inner+0x25b0 — NOT(CCD)
// cannot undo elimination.
//
// The `full_msg` parameter (pvVar1 in NOTDispatcher) is the complete NOT
// token list, retained in case the subclass on-NOT-CCD hook needs it.
// The `ccd_sublist` parameter (puVar4) is GetSubList(inner, 1) — the
// CCD ( power ) sub-list already extracted by NOTDispatcher.
//
// Inner-state write:
//   inner+0x25a8[power_idx] — byte; cleared to 0 (power reconnected)
//
// C References:
//   NOTDispatcher → (Source/communications/NOTDispatcher.c line 25-29)
//   CCD array: inner+0x25a8 (shared with CCD_Handler / FUN_0045e470)
//   Power token range: AUS=0x4100 through TUR=0x4106 (low byte = index)
//
// Python equivalent: handle_not_ccd (communications/inbound/not_handlers.py)
//   state.g_ccd_powers.discard(power_idx)

void __thiscall FUN_0045e9f0(void *this,void *full_msg,void *ccd_sublist)

{
  short *psVar1;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_004979a0;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // ccd_sublist is CCD ( power ) — extract the inner power sub-group
  GetSubList(ccd_sublist,local_1c,1);
  local_4 = 0;

  psVar1 = (short *)GetListElement(local_1c,(undefined2 *)&full_msg,0);

  // High byte 'A' (0x41) confirms valid power token; low byte = index 0..6
  if ((char)((uint)(short)*psVar1 >> 8) == 'A') {
    *(undefined1 *)(*(int *)((int)this + 8) + 0x25a8 + ((uint)(short)*psVar1 & 0xff)) = 0;
  }

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  return;
}
