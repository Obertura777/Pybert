// FUN_0045ad50 — MDF handler
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == MDF.
// DAIDE: MDF ( powers ) ( provinces ) ( adjacencies )
//
// Snapshots the full MDF message into inner+0x2568 (g_mdf_raw TokenList),
// sets the MDF-received flag at inner+0x2574, then fires vtable +0xd8
// (on-MDF / map-init hook — where the subclass builds its province-adjacency
// structures from the raw token data).
//
// Sub-element layout in the token list (indices 1-3):
//   [1] powers list     — power tokens participating in this game
//   [2] province data   — ( supply_centres ) ( provinces ) block
//   [3] adjacency list  — per-province adjacency sub-lists
//
// Inner-state writes:
//   inner+0x2568 — TokenList holding raw MDF token group [1]
//   inner+0x2574 — MDF-received flag set to 1
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (line: MDF == sVar1 branch)
//   on-MDF vtable slot: +0xd8
//
// Python equivalent: handle_mdf (communications/inbound/server_handlers.py)
//   stores _extract_top_paren_groups result in state.g_mdf_data.

void __thiscall FUN_0045ad50(void *this,void *param_1)

{
  void *pvVar1;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497e40;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Snapshot sub-element [1] (power list) into inner+0x2568 (g_mdf_raw)
  // The full message reference (param_1) is retained by the vtable hook for
  // further adjacency parsing; only the powers group is snapshotted here.
  pvVar1 = GetSubList(param_1,local_1c,1);
  local_4 = 0;
  AppendList((void *)(*(int *)((int)this + 8) + 0x2568),pvVar1);
  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;

  // Set MDF-received flag at inner+0x2574
  *(undefined1 *)(*(int *)((int)this + 8) + 0x2574) = 1;

  // Fire on-MDF hook: builds province adjacency structures from param_1
  (**(code **)(*(int *)this + 0xd8))(param_1);
  return;
}
