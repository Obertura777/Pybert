// FUN_0045e470 — CCD handler
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == CCD.
// DAIDE: CCD ( power )
//
// Extracts the power token from the single sub-group, converts it to a
// power index (low byte of the DAIDE token, 0=AUS through 6=TUR), and sets
// byte [power_idx] of the civil-disorder array at inner+0x25a8 to 1.
//
// Albert uses this array to suppress press generation toward CCD powers and
// to adjust order scoring (CCD powers hold their prior positions).
//
// Reversal: NOT ( CCD ( power ) ) → FUN_0045e9f0 (NOT_CCD_Handler.c) clears
// the same byte when the power reconnects.
//
// Inner-state write:
//   inner+0x25a8[power_idx] — byte; set to 1 (power in civil disorder)
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (line: CCD == sVar1 branch)
//   Reversal handler: FUN_0045e9f0 (NOT_CCD_Handler.c)
//   Power token range: AUS=0x4100 through TUR=0x4106 (low byte = index)
//
// Python equivalent: handle_ccd (communications/inbound/server_handlers.py)
//   state.g_ccd_powers.add(power_idx)

void __thiscall FUN_0045e470(void *this,void *param_1)

{
  short *psVar1;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497b50;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Extract sub-element [1] — single power token group
  GetSubList(param_1,local_1c,1);
  local_4 = 0;

  psVar1 = (short *)GetListElement(local_1c,(undefined2 *)&param_1,0);

  // High byte 'A' (0x41) confirms valid power token; low byte = index 0..6
  if ((char)((uint)(short)*psVar1 >> 8) == 'A') {
    *(undefined1 *)(*(int *)((int)this + 8) + 0x25a8 + ((uint)(short)*psVar1 & 0xff)) = 1;
  }

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  return;
}
