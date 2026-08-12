// FUN_0045d180 — OUT handler
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == OUT.
// DAIDE: OUT ( power )
//
// Extracts the power token, sets byte [power_idx] of the elimination array at
// inner+0x25b0 to 1, and also sets the CCD byte at inner+0x25a8[power_idx]
// (eliminated powers are trivially in civil disorder). Then fires vtable +0xf0
// (on-OUT hook — subclass may update alliance/scoring structures).
//
// Albert uses inner+0x25b0 to skip eliminated powers in press generation,
// order scoring, and MC population. The SC count for the power at
// inner+0x258c[power_idx] is zeroed to keep scoring consistent.
//
// Inner-state writes:
//   inner+0x25b0[power_idx] — byte; set to 1 (power eliminated)
//   inner+0x25a8[power_idx] — byte; set to 1 (also mark CCD)
//   inner+0x258c + power_idx*4 — int; zeroed (SC count cleared on elimination)
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (line: OUT == sVar1 branch)
//   CCD array: inner+0x25a8 (shared with CCD_Handler.c / FUN_0045e470)
//   on-OUT vtable slot: +0xf0
//   Power token range: AUS=0x4100 through TUR=0x4106 (low byte = index)
//
// Python equivalent: handle_out (communications/inbound/server_handlers.py)
//   state.g_out_powers.add(power_idx); state.g_ccd_powers.add(power_idx)

void __thiscall FUN_0045d180(void *this,void *param_1)

{
  uint uVar1;
  short *psVar2;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_004978c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Extract sub-element [1] — single power token group
  GetSubList(param_1,local_1c,1);
  local_4 = 0;

  psVar2 = (short *)GetListElement(local_1c,(undefined2 *)&param_1,0);
  uVar1 = (uint)(short)*psVar2;

  // High byte 'A' (0x41) confirms valid power token; low byte = index 0..6
  if ((char)(uVar1 >> 8) == 'A') {
    // Mark eliminated at inner+0x25b0[power_idx]
    *(undefined1 *)(*(int *)((int)this + 8) + 0x25b0 + (uVar1 & 0xff)) = 1;
    // Also mark civil disorder (eliminated ⇒ trivially CCD)
    *(undefined1 *)(*(int *)((int)this + 8) + 0x25a8 + (uVar1 & 0xff)) = 1;
    // Clear SC count at inner+0x258c[power_idx]
    *(undefined4 *)(*(int *)((int)this + 8) + 0x258c + (uVar1 & 0xff) * 4) = 0;
  }

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;

  // Fire on-OUT hook: alliance/hostility model updates for eliminated power
  (**(code **)(*(int *)this + 0xf0))(param_1);
  return;
}
