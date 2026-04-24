
void __fastcall EnumerateHoldOrders(int param_1)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  int **ppiVar4;
  uint **ppuVar5;
  void **ppvVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_7c;
  int *local_78;
  undefined4 *local_74;
  int local_70;
  int local_6c;
  int **local_68;
  int *local_64;
  uint *local_58;
  int *local_54;
  void *local_48 [4];
  void *local_38 [4];
  uint *local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497548;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_74 = (undefined4 *)((uint)local_74 & 0xffff0000);
  FUN_00465870(local_48);
  local_c = 0;
  FUN_00465870(local_38);
  iVar10 = 0;
  local_c = CONCAT31(local_c._1_3_,1);
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    iVar7 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
    do {
      iVar8 = 0;
      if (0 < iVar7) {
        iVar2 = iVar10 << 10;
        do {
          *(undefined4 *)((int)&g_UnitProvinceReach + iVar2) = 0;
          *(undefined4 *)((int)&g_MaxNonAllyReach + iVar2) = 0;
          iVar7 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
          iVar8 = iVar8 + 1;
          iVar2 = iVar2 + 4;
        } while (iVar8 < iVar7);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  local_6c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_70 = *(int *)(param_1 + 8) + 0x2450;
  while( true ) {
    iVar7 = local_6c;
    iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_70 == 0) || (local_70 != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar7 == iVar10) break;
    local_7c = 0;
    if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
      iVar10 = 0;
      pvVar9 = (void *)(param_1 + 0x4000);
      do {
        if (local_70 == 0) {
          FUN_0047a948();
        }
        if (iVar7 == *(int *)(local_70 + 4)) {
          FUN_0047a948();
        }
        if (iVar7 == *(int *)(local_70 + 4)) {
          FUN_0047a948();
        }
        ppiVar3 = OrderedSet_FindOrInsert(pvVar9,(int **)(iVar7 + 0x10));
        (&g_UnitProvinceReach)[*(int *)(iVar7 + 0xc) + iVar10] = *ppiVar3;
        local_7c = local_7c + 1;
        pvVar9 = (void *)((int)pvVar9 + 0xc);
        iVar10 = iVar10 + 0x100;
      } while (local_7c < *(int *)(*(int *)(param_1 + 8) + 0x2404));
    }
    iVar10 = local_70;
    if (local_70 == 0) {
      FUN_0047a948();
    }
    if (iVar7 == *(int *)(iVar10 + 4)) {
      FUN_0047a948();
      if (iVar7 == *(int *)(iVar10 + 4)) {
        FUN_0047a948();
      }
    }
    ppiVar3 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar7 + 0xc) * 0x24),
                         (ushort *)(iVar7 + 0x14));
    if (iVar7 == *(int *)(iVar10 + 4)) {
      FUN_0047a948();
      if (iVar7 == *(int *)(iVar10 + 4)) {
        FUN_0047a948();
      }
    }
    iVar10 = *(int *)(iVar7 + 0x18) * 0x100;
    (&g_MaxNonAllyReach)[*(int *)(iVar7 + 0xc) + iVar10] =
         (&g_UnitProvinceReach)[*(int *)(iVar7 + 0xc) + iVar10];
    local_64 = (int *)*ppiVar3[1];
    local_68 = ppiVar3;
    while( true ) {
      piVar1 = local_64;
      ppiVar4 = local_68;
      local_54 = ppiVar3[1];
      if ((local_68 == (int **)0x0) || (local_68 != ppiVar3)) {
        FUN_0047a948();
      }
      if (piVar1 == local_54) break;
      if (ppiVar4 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar1 == ppiVar4[1]) {
        FUN_0047a948();
      }
      local_74 = (undefined4 *)CONCAT22(local_74._2_2_,(short)piVar1[4]);
      if (piVar1 == ppiVar4[1]) {
        FUN_0047a948();
      }
      local_78 = (int *)piVar1[3];
      iVar10 = 0;
      if (-1 < (int)(&DAT_004d3610)[(int)local_78 * 2]) {
        iVar10 = (&g_AllyTrustScore)
                 [(*(int *)(iVar7 + 0x18) * 0x15 + (&DAT_004d3610)[(int)local_78 * 2]) * 2];
      }
      if (-1 < (int)(&DAT_004d2610)[(int)local_78 * 2]) {
        iVar10 = (&g_AllyTrustScore)
                 [(*(int *)(iVar7 + 0x18) * 0x15 + (&DAT_004d2610)[(int)local_78 * 2]) * 2];
      }
      if (-1 < (int)(&g_AllyDesignation_A)[(int)local_78 * 2]) {
        iVar10 = (&g_AllyTrustScore)
                 [(*(int *)(iVar7 + 0x18) * 0x15 + (&g_AllyDesignation_A)[(int)local_78 * 2]) * 2];
      }
      if (iVar10 == 0) {
        if (iVar7 == *(int *)(local_70 + 4)) {
          FUN_0047a948();
        }
        ppiVar4 = OrderedSet_FindOrInsert
                            ((void *)(param_1 + 0x4000 + *(int *)(iVar7 + 0x18) * 0xc),&local_78);
        iVar10 = (int)(&g_MaxNonAllyReach)[*(int *)(iVar7 + 0x18) * 0x100 + *(int *)(iVar7 + 0xc)]
                 >> 0x1f;
        if ((iVar10 <= (int)ppiVar4[1]) &&
           ((iVar10 < (int)ppiVar4[1] ||
            ((int *)(&g_MaxNonAllyReach)[*(int *)(iVar7 + 0x18) * 0x100 + *(int *)(iVar7 + 0xc)] <
             *ppiVar4)))) {
          if (iVar7 == *(int *)(local_70 + 4)) {
            FUN_0047a948();
          }
          ppiVar4 = OrderedSet_FindOrInsert
                              ((void *)(param_1 + 0x4000 + *(int *)(iVar7 + 0x18) * 0xc),&local_78);
          (&g_MaxNonAllyReach)[*(int *)(iVar7 + 0x18) * 0x100 + *(int *)(iVar7 + 0xc)] = *ppiVar4;
        }
      }
      FUN_0040f400((int *)&local_68);
    }
    UnitList_Advance(&local_70);
  }
  local_74 = (undefined4 *)*DAT_00baed80;
  local_78 = (int *)&DAT_00baed7c;
  while( true ) {
    puVar11 = DAT_00baed80;
    iVar10 = 0;
    if ((local_78 == (int *)0x0) || (local_78 != (int *)&DAT_00baed7c)) {
      FUN_0047a948();
    }
    if (local_74 == puVar11) break;
    if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
      puVar11 = local_74 + 5;
      pvVar9 = (void *)(param_1 + 0x4000);
      do {
        if (local_78 == (int *)0x0) {
          FUN_0047a948();
        }
        if (local_74 == (undefined4 *)local_78[1]) {
          FUN_0047a948();
        }
        puVar11[0x15] = 0;
        if (local_74 == (undefined4 *)local_78[1]) {
          FUN_0047a948();
        }
        if (local_74 == (undefined4 *)local_78[1]) {
          FUN_0047a948();
        }
        ppiVar3 = OrderedSet_FindOrInsert(pvVar9,(int **)(local_74 + 3));
        *puVar11 = *ppiVar3;
        iVar10 = iVar10 + 1;
        puVar11 = puVar11 + 1;
        pvVar9 = (void *)((int)pvVar9 + 0xc);
      } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
    }
    FUN_0040f380((int *)&local_78);
  }
  local_6c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_70 = *(int *)(param_1 + 8) + 0x2450;
  while( true ) {
    iVar8 = local_6c;
    iVar7 = local_70;
    iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_70 == 0) || (local_70 != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar8 == iVar10) break;
    if (iVar7 == 0) {
      FUN_0047a948();
    }
    if (iVar8 == *(int *)(iVar7 + 4)) {
      FUN_0047a948();
      if (iVar8 == *(int *)(iVar7 + 4)) {
        FUN_0047a948();
      }
    }
    ppiVar3 = FUN_0041c270(&DAT_00baed7c,(int **)(iVar8 + 0x10));
    ppiVar3[*(int *)(iVar8 + 0x18) + 0x15] = (int *)0x1e;
    UnitList_Advance(&local_70);
  }
  iVar10 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    do {
      if ((&curr_sc_cnt)[iVar10] != 0) {
        (&DAT_00b954d0)[iVar10] = 0;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  iVar10 = *(int *)(param_1 + 8);
  local_7c = 0;
  if (0 < *(int *)(iVar10 + 0x2404)) {
    local_78 = (int *)&g_HoldOrderSeqs;
    do {
      piVar1 = local_78;
      ResetPerTrialState(iVar10);
      ppuVar5 = FUN_00466f80(&SUB,&local_58,(void **)&DAT_00bc1e0c);
      local_c._0_1_ = 2;
      AppendList(local_48,ppuVar5);
      local_c = CONCAT31(local_c._1_3_,1);
      FreeList(&local_58);
      AppendList(piVar1,local_48);
      local_6c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
      local_70 = *(int *)(param_1 + 8) + 0x2450;
      while( true ) {
        iVar8 = local_6c;
        iVar7 = local_70;
        iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
        if ((local_70 == 0) || (local_70 != *(int *)(param_1 + 8) + 0x2450)) {
          FUN_0047a948();
        }
        piVar1 = local_78;
        if (iVar8 == iVar10) break;
        if (iVar7 == 0) {
          FUN_0047a948();
        }
        if (iVar8 == *(int *)(iVar7 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar8 + 0x18) == local_7c) {
          if (iVar8 == *(int *)(iVar7 + 4)) {
            FUN_0047a948();
          }
          BuildOrder_RTO(*(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar8 + 0xc),
                         *(undefined4 *)(iVar8 + 0xc));
          if (iVar8 == *(int *)(iVar7 + 4)) {
            FUN_0047a948();
          }
          ppvVar6 = (void **)FUN_00463690(*(void **)(param_1 + 8),&local_68,(int *)(iVar8 + 0x10));
          local_c._0_1_ = 3;
          AppendList(local_38,ppvVar6);
          local_c._0_1_ = 1;
          FreeList(&local_68);
          ppuVar5 = FUN_00466c40(local_48,local_28,local_38);
          local_c._0_1_ = 4;
          AppendList(local_48,ppuVar5);
          local_c = CONCAT31(local_c._1_3_,1);
          FreeList(local_28);
        }
        UnitList_Advance(&local_70);
      }
      AppendList(local_78,local_48);
      iVar10 = *(int *)(param_1 + 8);
      local_7c = local_7c + 1;
      local_78 = piVar1 + 4;
    } while (local_7c < *(int *)(iVar10 + 0x2404));
  }
  local_c = local_c & 0xffffff00;
  FreeList(local_38);
  local_c = 0xffffffff;
  FreeList(local_48);
  ExceptionList = local_14;
  return;
}

