
void __fastcall ComputePress(int param_1)

{
  ushort uVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int local_20;
  int local_1c;
  int **local_18;
  int *local_14;
  int *local_c;
  
  iVar8 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    puVar9 = &DAT_00b85768;
    do {
      iVar5 = 0;
      (&DAT_00b85710)[iVar8] = 0;
      puVar7 = puVar9;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
        do {
          *puVar7 = 0;
          iVar5 = iVar5 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar5 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
      }
      iVar8 = iVar8 + 1;
      puVar9 = puVar9 + 0x100;
    } while (iVar8 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  local_1c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_20 = *(int *)(param_1 + 8) + 0x2450;
  while( true ) {
    iVar2 = local_1c;
    iVar5 = local_20;
    iVar8 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_20 == 0) || (local_20 != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar2 == iVar8) break;
    if (iVar5 == 0) {
      FUN_0047a948();
    }
    if ((iVar2 == *(int *)(iVar5 + 4)) && (FUN_0047a948(), iVar2 == *(int *)(iVar5 + 4))) {
      FUN_0047a948();
    }
    ppiVar6 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar2 + 0x10) * 0x24),
                         (ushort *)(iVar2 + 0x14));
    local_14 = (int *)*ppiVar6[1];
    local_18 = ppiVar6;
    while( true ) {
      piVar4 = local_14;
      ppiVar3 = local_18;
      local_c = ppiVar6[1];
      if ((local_18 == (int **)0x0) || (local_18 != ppiVar6)) {
        FUN_0047a948();
      }
      if (piVar4 == local_c) break;
      if (ppiVar3 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar4 == ppiVar3[1]) {
        FUN_0047a948();
      }
      if (*(char *)(*(int *)(param_1 + 8) + 3 + piVar4[3] * 0x24) != '\0') {
        if (piVar4 == ppiVar3[1]) {
          FUN_0047a948();
        }
        uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 0x20 + piVar4[3] * 0x24);
        if (((char)(uVar1 >> 8) != 'A') || ((uVar1 & 0xff) == 0x14)) {
          if (iVar2 == *(int *)(local_20 + 4)) {
            FUN_0047a948();
          }
          if (piVar4 == ppiVar3[1]) {
            FUN_0047a948();
          }
          if ((&DAT_00b85768)[*(int *)(iVar2 + 0x18) * 0x100 + piVar4[3]] == 0) {
            if (iVar2 == *(int *)(local_20 + 4)) {
              FUN_0047a948();
            }
            (&DAT_00b85710)[*(int *)(iVar2 + 0x18)] = (&DAT_00b85710)[*(int *)(iVar2 + 0x18)] + 1;
          }
          if (iVar2 == *(int *)(local_20 + 4)) {
            FUN_0047a948();
          }
          if (piVar4 == ppiVar3[1]) {
            FUN_0047a948();
          }
          (&DAT_00b85768)[*(int *)(iVar2 + 0x18) * 0x100 + piVar4[3]] = 1;
        }
      }
      FUN_0040f400((int *)&local_18);
    }
    UnitList_Advance(&local_20);
  }
  return;
}

