// FUN_0045af10 — SCO handler
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == SCO.
// DAIDE: SCO ( power sc sc... ) ( power sc sc... ) ( UNO sc... )
//
// Iterates over each power sub-group, extracts the first token (power) and
// counts the remaining tokens (supply centres owned by that power). Writes
// the count into a 7-element int array at inner+0x258c (g_sco_power_sc_count,
// indexed 0=AUS through 6=TUR). Unowned SCs under UNO are ignored.
//
// Then fires vtable +0xdc (on-SCO hook — where heuristic province scoring
// and MC evaluation pick up the updated SC counts).
//
// Inner-state write:
//   inner+0x258c — int[7] per-power SC count; zeroed then updated each call.
//                  Indexed by power (AUS=0, ENG=1, FRA=2, GER=3, ITA=4,
//                  RUS=5, TUR=6).
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (line: SCO == sVar1 branch)
//   on-SCO vtable slot: +0xdc
//   Power token range: AUS=0x4100 through TUR=0x4106 (low byte = index)
//
// Python equivalent: handle_sco (communications/inbound/server_handlers.py)
//   updates state.g_sco_power_sc_count[power_idx] per group.

void __thiscall FUN_0045af10(void *this,void *param_1)

{
  int iVar1;
  short *psVar2;
  int *inner;
  int sc_count;
  int group_idx;
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497c30;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  inner = *(int **)((int)this + 8);

  // Zero the 7-element SC count array at inner+0x258c
  memset((void *)((int)inner + 0x258c),0,0x1c);

  local_4 = 0;
  group_idx = 1;

  // Iterate sub-groups until GetSubList returns NULL (no more power blocks)
  while (GetSubList(param_1,local_2c,group_idx) != (void *)0x0) {
    local_4._0_1_ = (char)group_idx;

    // First token is the power (or UNO for unowned SCs)
    psVar2 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
    iVar1 = (int)(short)*psVar2;

    // High byte 0x41 ('A') identifies a valid power token; low byte = index
    if ((char)(iVar1 >> 8) == 'A') {
      sc_count = GetListSize(local_2c) - 1;   // all tokens after power token
      *(int *)((int)inner + 0x258c + ((iVar1 & 0xff) * 4)) = sc_count;
    }
    // else UNO (0x5800) — unowned SCs; ignore for per-power tracking

    local_4 = (uint)local_4._1_3_ << 8;
    FreeList(local_2c);
    group_idx = group_idx + 1;
  }

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;

  // Fire on-SCO hook: triggers re-scoring of provinces and MC seed update
  (**(code **)(*(int *)this + 0xdc))(param_1);
  return;
}
