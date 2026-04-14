
undefined4 * __thiscall BuildOrder_SUP_HLD(void *this,int *param_1,int param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int **ppiVar9;
  int **ppiVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int **local_10;
  int *local_c;
  int local_8;
  int local_4;
  
  ppiVar9 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),&param_2);
  ppiVar10 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),&param_3);
  iVar4 = param_2;
  bVar13 = AMY == *(short *)(ppiVar9 + 1);
  FUN_00460770(*(void **)((int)this + 8),param_2,param_3);
  (&g_OrderTable)[iVar4 * 0x1e] = 3;
  (&DAT_00baeda8)[iVar4 * 0x1e] = param_3;
  (&g_ProvinceBaseScore)[iVar4 * 0x1e] = 1;
  ppiVar9 = OrderedSet_FindOrInsert((void *)((int)this + (int)param_1 * 0xc + 0x4000),ppiVar9);
  (&g_ConvoyChainScore)[iVar4 * 0x1e] = *ppiVar9;
  (&DAT_00baedbc)[iVar4 * 0x1e] = ppiVar9[1];
  if (bVar13) {
    (&DAT_00baee00)[iVar4 * 0x1e] = 0;
    *(undefined4 *)(&DAT_00baee04 + iVar4 * 0x78) = 0;
  }
  RegisterConvoyFleet(this,(int)param_1,iVar4);
  if (ppiVar10[2] != param_1) {
    iVar11 = (int)param_1 * 0x15 + (int)ppiVar10[2];
    iVar12 = (&g_AllyTrustScore_Hi)[iVar11 * 2];
    if ((&g_AllyTrustScore)[iVar11 * 2] == 0 && iVar12 == 0) {
      DAT_00633f14 = 0x1e;
      (&g_ConvoyActiveFlag)[param_3] = 1;
    }
    else if ((iVar12 < 1) && ((iVar12 < 0 || ((uint)(&g_AllyTrustScore)[iVar11 * 2] < 5)))) {
      DAT_00633f14 = 10;
      (&g_ConvoyActiveFlag)[param_3] = 1;
    }
    else {
      DAT_00633f14 = 0xfffffff6;
      (&g_ConvoyActiveFlag)[param_3] = 1;
    }
  }
  iVar11 = (int)param_1 * 0x100;
  iVar12 = iVar11 + iVar4;
  if ((&DAT_005460e8)[iVar12 * 2] != 0 || (&DAT_005460ec)[iVar12 * 2] != 0) {
    if (((&DAT_005460e8)[iVar12 * 2] != (&g_EnemyReachScore)[iVar12 * 2]) ||
       ((&DAT_005460ec)[iVar12 * 2] != (&DAT_00535cec)[iVar12 * 2])) {
      (&DAT_00baedd8)[param_3 * 0x1e] = (&DAT_00baedd8)[param_3 * 0x1e] + 1;
      return &DAT_00baedd8 + param_3 * 0x1e;
    }
    local_4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
    local_8 = *(int *)((int)this + 8) + 0x2450;
    bVar13 = true;
    while( true ) {
      iVar7 = local_4;
      iVar6 = local_8;
      iVar12 = *(int *)(*(int *)((int)this + 8) + 0x2454);
      if ((local_8 == 0) || (local_8 != *(int *)((int)this + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (iVar7 == iVar12) break;
      if (iVar6 == 0) {
        FUN_0047a948();
      }
      if (iVar7 == *(int *)(iVar6 + 4)) {
        FUN_0047a948();
      }
      iVar12 = *(int *)(iVar7 + 0x10) + iVar11;
      if ((*(int *)(&DAT_004f6ce8 + iVar12 * 8) == 1) && (*(int *)(&DAT_004f6cec + iVar12 * 8) == 0)
         ) {
LAB_00440b62:
        if (iVar7 == *(int *)(iVar6 + 4)) {
          FUN_0047a948();
        }
        ppiVar9 = UnitList_FindOrInsert
                            ((void *)(*(int *)((int)this + 8) + 0x2450),(int *)(iVar7 + 0xc));
        if (iVar7 == *(int *)(iVar6 + 4)) {
          FUN_0047a948();
        }
        ppiVar9 = AdjacencyList_FilterByUnitType
                            ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar7 + 0xc) * 0x24),
                             (ushort *)(ppiVar9 + 1));
        local_c = (int *)*ppiVar9[1];
        bVar2 = false;
        bVar3 = false;
        bVar8 = false;
        local_10 = ppiVar9;
        while( true ) {
          piVar5 = local_c;
          ppiVar10 = local_10;
          piVar1 = ppiVar9[1];
          if ((local_10 == (int **)0x0) || (local_10 != ppiVar9)) {
            FUN_0047a948();
          }
          if (piVar5 == piVar1) break;
          if (ppiVar10 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar5 == ppiVar10[1]) {
            FUN_0047a948();
          }
          iVar12 = param_2;
          if (piVar5[3] == param_2) {
            bVar2 = true;
          }
          if (piVar5 == ppiVar10[1]) {
            FUN_0047a948();
          }
          if (piVar5[3] == param_3) {
            bVar3 = true;
          }
          if (piVar5 == ppiVar10[1]) {
            FUN_0047a948();
          }
          if (piVar5[3] != iVar12) {
            if (piVar5 == ppiVar10[1]) {
              FUN_0047a948();
            }
            if (piVar5[3] != param_3) {
              if (piVar5 == ppiVar10[1]) {
                FUN_0047a948();
              }
              if ((*(int *)(&g_SCOwnership + (piVar5[3] + iVar11) * 8) == 1) &&
                 (*(int *)(&DAT_00520cec + (piVar5[3] + iVar11) * 8) == 0)) {
                if (piVar5 == ppiVar10[1]) {
                  FUN_0047a948();
                }
                if ((&g_OrderTable)[piVar5[3] * 0x1e] == 3) {
                  if (piVar5 == ppiVar10[1]) {
                    FUN_0047a948();
                  }
                  if ((&DAT_00baeda8)[piVar5[3] * 0x1e] == param_3) {
                    if (piVar5 == ppiVar10[1]) {
                      FUN_0047a948();
                    }
                    if ((&DAT_00baede0)[piVar5[3] * 0x1e] == 1) {
                      bVar8 = true;
                    }
                  }
                }
              }
            }
          }
          FUN_0040f400((int *)&local_10);
        }
        if (bVar8) {
          if ((&DAT_00baede0)[iVar4 * 0x1e] != 1) {
            if ((((&DAT_00baede0)[iVar4 * 0x1e] == 2) && (bVar2)) && (bVar3)) goto LAB_00440d27;
            goto LAB_00440d0b;
          }
          bVar8 = true;
        }
        else {
LAB_00440d0b:
          bVar8 = false;
        }
        if (((bVar2) && (!bVar3)) && (!bVar8)) {
          bVar13 = false;
        }
      }
      else {
        if (iVar7 == *(int *)(iVar6 + 4)) {
          FUN_0047a948();
        }
        iVar12 = *(int *)(iVar7 + 0x10) + iVar11;
        if ((*(int *)(&DAT_0050bce8 + iVar12 * 8) == 1) &&
           (*(int *)(&DAT_0050bcec + iVar12 * 8) == 0)) goto LAB_00440b62;
      }
LAB_00440d27:
      UnitList_Advance(&local_8);
    }
    if (!bVar13) {
      (&DAT_00baedd8)[param_3 * 0x1e] = (&DAT_00baedd8)[param_3 * 0x1e] + 1;
      return &DAT_00baedd8 + param_3 * 0x1e;
    }
  }
  (&g_ProvinceBaseScore)[param_3 * 0x1e] = (&g_ProvinceBaseScore)[param_3 * 0x1e] + 1;
  return &g_ProvinceBaseScore + param_3 * 0x1e;
}

