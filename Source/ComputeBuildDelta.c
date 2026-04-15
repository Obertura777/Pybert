// FUN_0040ab10 — ComputeBuildDelta
// Called from ParseNOW after the per-unit loop when season == WIN.
// Returns 1 (low byte of uVar) when any power has SC != unit count, else 0.
//
// Semantics (cross-referenced against the Python rewrite —
// bot.py:generate_and_submit_orders WIN branch):
//   - Zero two per-power int[256] accumulators:
//       local_808 = SC counts per power
//       local_408 = unit counts per power
//   - Walk the unit std::set at `this+0x2450` (populated by ParseNOWUnit's
//     4-elt no-order branch, which is the form used during WIN NOWs).
//     For each unit node `n`:
//       *(u16 *)(this + 0x20 + n.prov_id * 0x24) = (n.power | 0x4100);
//       local_408[n.power]++;
//     (Entry +0x20 is the province array, stride 0x24.)
//   - Walk the province array `+0x20`, counting SC owners into local_808
//     (skipping SEA / non-SC flag).
//   - For each power p in [0, this+0x2404):
//       entry = std::map::insert(this+0x2468, {p, ...}).first
//       if (SC > unit): entry.flag=1 (build), entry.delta = SC - unit
//       else:           entry.flag=0 (remove), entry.delta = unit - SC
//       entry.candidates_ptr = nullptr
//       clear (destroy) entry.candidate_bst (calls FUN_0040fb70 on each node)
//       if (SC != unit) imbalance = 1
//   - Returns low byte = imbalance flag.

uint __fastcall FUN_0040ab10(int param_1)
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int **ppiVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  undefined1 local_81d;
  int local_81c;
  int local_818;
  int local_814;
  int local_80c;
  int local_808 [256];
  int local_408 [257];

  uVar8 = *(uint *)(param_1 + 0x2404);
  local_81d = 0;
  if (0 < (int)uVar8) {
    piVar10 = local_808;
    for (uVar7 = uVar8 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    }
    piVar10 = local_408;
    for (uVar8 = uVar8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    }
  }
  pbVar5 = *(byte **)(param_1 + 0x2454);
  local_818 = *(int *)pbVar5;
  local_81c = param_1 + 0x2450;
  local_814 = param_1;
  while( true ) {
    iVar2 = local_818;
    iVar9 = local_81c;
    local_80c = *(int *)(param_1 + 0x2454);
    if ((local_81c == 0) || (local_81c != param_1 + 0x2450)) {
      pbVar5 = (byte *)FUN_0047a948();
    }
    if (iVar2 == local_80c) break;
    if (iVar9 == 0) {
      FUN_0047a948();
    }
    if (iVar2 == *(int *)(iVar9 + 4)) {
      FUN_0047a948();
    }
    *(ushort *)(param_1 + 0x20 + *(int *)(iVar2 + 0x10) * 0x24) = *(byte *)(iVar2 + 0x18) | 0x4100;
    local_408[*(int *)(iVar2 + 0x18)] = local_408[*(int *)(iVar2 + 0x18)] + 1;
    pbVar5 = (byte *)UnitList_Advance(&local_81c);
  }
  iVar9 = *(int *)(param_1 + 0x2400);
  if (0 < iVar9) {
    pbVar5 = (byte *)(param_1 + 0x20);
    do {
      if ((pbVar5[-0x1d] != 0) && (DAT_004c61a0 != *(short *)pbVar5)) {
        local_808[*pbVar5] = local_808[*pbVar5] + 1;
      }
      pbVar5 = pbVar5 + 0x24;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_81c = 0;
  if (*(int *)(param_1 + 0x2404) < 1) {
    return (uint)pbVar5 & 0xffffff00;
  }
  do {
    iVar4 = local_81c;
    ppiVar6 = FUN_00409de0((void *)(param_1 + 0x2468),&local_81c);
    iVar9 = local_408[iVar4];
    iVar2 = local_808[iVar4];
    if (iVar9 < iVar2) {
      *(undefined1 *)(ppiVar6 + 5) = 1;
      piVar10 = (int *)(iVar2 - iVar9);
    }
    else {
      *(undefined1 *)(ppiVar6 + 5) = 0;
      piVar10 = (int *)(iVar9 - iVar2);
    }
    ppiVar6[4] = piVar10;
    if (iVar2 != iVar9) {
      local_81d = 1;
    }
    ppiVar6[3] = (int *)0x0;
    cVar1 = *(char *)(ppiVar6[1][1] + 0x19);
    piVar10 = (int *)ppiVar6[1][1];
    param_1 = local_814;
    while (local_814 = param_1, cVar1 == '\0') {
      FUN_0040fb70((int *)piVar10[2]);
      piVar3 = (int *)*piVar10;
      _free(piVar10);
      piVar10 = piVar3;
      param_1 = local_814;
      cVar1 = *(char *)((int)piVar3 + 0x19);
    }
    ppiVar6[1][1] = (int)ppiVar6[1];
    piVar10 = ppiVar6[1];
    ppiVar6[2] = (int *)0x0;
    *piVar10 = (int)piVar10;
    local_81c = iVar4 + 1;
    ppiVar6[1][2] = (int)ppiVar6[1];
  } while (local_81c < *(int *)(param_1 + 0x2404));
  return CONCAT31((int3)((uint)piVar10 >> 8),local_81d);
}
