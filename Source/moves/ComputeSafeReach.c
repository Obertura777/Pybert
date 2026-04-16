
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall ComputeSafeReach(int param_1)

{
  undefined2 uVar1;
  int *piVar2;
  int **ppiVar3;
  int iVar4;
  uint uVar5;
  int **ppiVar6;
  int **ppiVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  undefined2 *puVar13;
  bool bVar14;
  int *local_5428;
  int **local_5424;
  int *local_5420;
  int local_541c;
  int local_5418;
  int **local_5414;
  int *local_5410;
  int local_540c;
  int local_5408 [5375];
  undefined4 uStack_c;
  
  uStack_c = 0x43dfc0;
  iVar11 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    do {
      (&g_SafeReachScore)[iVar11] = 0xffffffff;
      iVar4 = *(int *)(param_1 + 8);
      iVar8 = *(int *)(iVar4 + 0x2404);
      if (0 < iVar8) {
        piVar2 = local_5408 + iVar11;
        do {
          *piVar2 = 0;
          piVar2 = piVar2 + 0x100;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(iVar4 + 0x2400));
  }
  local_5418 = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_541c = *(int *)(param_1 + 8) + 0x2450;
  local_540c = param_1;
  while( true ) {
    iVar8 = local_5418;
    iVar4 = local_541c;
    iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_541c == 0) || (local_541c != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar8 == iVar11) break;
    if (iVar4 == 0) {
      FUN_0047a948();
    }
    if ((iVar8 == *(int *)(iVar4 + 4)) && (FUN_0047a948(), iVar8 == *(int *)(iVar4 + 4))) {
      FUN_0047a948();
    }
    ppiVar3 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar8 + 0xc) * 0x24),
                         (ushort *)(iVar8 + 0x14));
    iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
    iVar4 = 0;
    if (0 < iVar11) {
      iVar9 = 0;
      do {
        if (iVar4 != *(int *)(iVar8 + 0x18)) {
          local_5408[*(int *)(iVar8 + 0x10) + iVar9] = 1;
        }
        iVar4 = iVar4 + 1;
        iVar9 = iVar9 + 0x100;
      } while (iVar4 < iVar11);
    }
    local_5420 = (int *)*ppiVar3[1];
    local_5424 = ppiVar3;
    local_5414 = ppiVar3;
    while( true ) {
      ppiVar6 = local_5424;
      piVar2 = ppiVar3[1];
      if ((local_5424 == (int **)0x0) || (local_5424 != ppiVar3)) {
        FUN_0047a948();
      }
      if (local_5420 == piVar2) break;
      iVar11 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
        iVar4 = 0;
        do {
          if (iVar11 != *(int *)(local_5418 + 0x18)) {
            if (ppiVar6 == (int **)0x0) {
              FUN_0047a948();
            }
            if (local_5420 == ppiVar6[1]) {
              FUN_0047a948();
            }
            local_5408[local_5420[3] + iVar4] = 1;
          }
          iVar11 = iVar11 + 1;
          iVar4 = iVar4 + 0x100;
          ppiVar3 = local_5414;
        } while (iVar11 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      FUN_0040f400((int *)&local_5424);
    }
    UnitList_Advance(&local_541c);
  }
  ppiVar3 = *(int ***)(*(int *)(param_1 + 8) + 0x2400);
  if (0 < (int)ppiVar3) {
    piVar2 = local_5408;
    puVar13 = (undefined2 *)(*(int *)(param_1 + 8) + 0x20);
    local_5414 = ppiVar3;
    do {
      if (*(char *)((int)puVar13 + -0x1d) == '\x01') {
        iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
        uVar5 = 0;
        if (0 < iVar11) {
          uVar1 = *puVar13;
          piVar12 = piVar2;
          do {
            uVar10 = (uint)(byte)uVar1;
            if ((char)((ushort)uVar1 >> 8) != 'A') {
              uVar10 = 0x14;
            }
            if (uVar5 != uVar10) {
              *piVar12 = 1;
            }
            uVar5 = uVar5 + 1;
            piVar12 = piVar12 + 0x100;
          } while ((int)uVar5 < iVar11);
        }
      }
      piVar2 = piVar2 + 1;
      puVar13 = puVar13 + 0x12;
      local_5414 = (int **)((int)local_5414 + -1);
    } while (local_5414 != (int **)0x0);
  }
  local_5418 = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_541c = *(int *)(param_1 + 8) + 0x2450;
  while( true ) {
    iVar8 = local_5418;
    iVar4 = local_541c;
    iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_541c == 0) || (local_541c != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar8 == iVar11) break;
    if (iVar4 == 0) {
      FUN_0047a948();
    }
    if (iVar8 == *(int *)(iVar4 + 4)) {
      FUN_0047a948();
    }
    ppiVar3 = (int **)(iVar8 + 0x10);
    if (iVar8 == *(int *)(iVar4 + 4)) {
      FUN_0047a948();
    }
    ppiVar6 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar8 + 0xc) * 0x24),
                         (ushort *)(iVar8 + 0x14));
    ppiVar7 = OrderedSet_FindOrInsert
                        ((void *)(param_1 + 0x4000 + *(int *)(iVar8 + 0x18) * 0xc),ppiVar3);
    local_5428 = *ppiVar7;
    local_5420 = (int *)*ppiVar6[1];
    bVar14 = local_5408[(int)(*ppiVar3 + *(int *)(iVar8 + 0x18) * 0x40)] != 1;
    local_5424 = ppiVar6;
    while( true ) {
      piVar2 = local_5420;
      ppiVar7 = local_5424;
      local_5410 = ppiVar6[1];
      if ((local_5424 == (int **)0x0) || (local_5424 != ppiVar6)) {
        FUN_0047a948();
      }
      if (piVar2 == local_5410) break;
      if (ppiVar7 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar2 == ppiVar7[1]) {
        FUN_0047a948();
      }
      ppiVar7 = OrderedSet_FindOrInsert
                          ((void *)(local_540c + 0x4000 + *(int *)(iVar8 + 0x18) * 0xc),
                           (int **)(piVar2 + 3));
      if ((int)local_5428 < (int)*ppiVar7) {
        local_5428 = *ppiVar7;
      }
      if (piVar2 == local_5424[1]) {
        FUN_0047a948();
      }
      if (local_5408[(int)((int *)piVar2[3] + *(int *)(iVar8 + 0x18) * 0x40)] == 1) {
        bVar14 = false;
      }
      FUN_0040f400((int *)&local_5424);
    }
    if (bVar14) {
      (&g_SafeReachScore)[(int)*ppiVar3] = local_5428;
    }
    UnitList_Advance(&local_541c);
    param_1 = local_540c;
  }
  return;
}

