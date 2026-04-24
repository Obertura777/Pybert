
int * __thiscall BuildOrder_SUP_MTO(void *this,int *param_1,int param_2,int param_3,int *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int **ppiVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  int **ppiVar8;
  int **ppiVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  int **local_10;
  int *local_c;
  int local_8;
  int local_4;
  
  bVar3 = false;
  ppiVar8 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),&param_2);
  ppiVar9 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),&param_3);
  iVar11 = param_2;
  bVar15 = AMY == *(short *)(ppiVar8 + 1);
  FUN_004607f0(*(void **)((int)this + 8),param_2,param_3,param_4);
  iVar14 = iVar11 * 0x10 - param_2;
  (&g_OrderTable)[iVar14 * 2] = 4;
  (&DAT_00baeda4)[iVar14 * 2] = param_3;
  (&DAT_00baeda8)[iVar14 * 2] = param_4;
  (&g_ProvinceBaseScore)[iVar14 * 2] = 1;
  ppiVar8 = OrderedSet_FindOrInsert((void *)((int)this + (int)param_1 * 0xc + 0x4000),ppiVar8);
  iVar11 = param_2;
  (&g_ConvoyChainScore)[iVar14 * 2] = *ppiVar8;
  (&DAT_00baedbc)[iVar14 * 2] = ppiVar8[1];
  if (bVar15) {
    (&DAT_00baee00)[iVar14 * 2] = 0;
    *(undefined4 *)(&DAT_00baee04 + iVar14 * 8) = 0;
  }
  RegisterConvoyFleet(this,(int)param_1,param_2);
  if (ppiVar9[2] != param_1) {
    iVar10 = (int)param_1 * 0x15 + (int)ppiVar9[2];
    iVar13 = (&g_AllyTrustScore_Hi)[iVar10 * 2];
    if ((&g_AllyTrustScore)[iVar10 * 2] == 0 && iVar13 == 0) {
      DAT_00633f14 = 0x1e;
      (&g_ConvoyActiveFlag)[(int)param_4] = 1;
    }
    else if ((iVar13 < 1) && ((iVar13 < 0 || ((uint)(&g_AllyTrustScore)[iVar10 * 2] < 5)))) {
      DAT_00633f14 = 10;
      (&g_ConvoyActiveFlag)[(int)param_4] = 1;
    }
    else {
      DAT_00633f14 = 0xfffffff6;
      (&g_ConvoyActiveFlag)[(int)param_4] = 1;
    }
  }
  iVar13 = (int)param_1 * 0x100;
  piVar12 = (int *)((iVar13 + iVar11) * 8);
  if (((&DAT_005460e8)[(iVar13 + iVar11) * 2] == piVar12[0x14d73a]) &&
     (piVar12[0x15183b] == piVar12[0x14d73b])) {
    local_4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
    local_8 = *(int *)((int)this + 8) + 0x2450;
    bVar15 = true;
    while( true ) {
      iVar6 = local_4;
      iVar10 = local_8;
      iVar11 = *(int *)(*(int *)((int)this + 8) + 0x2454);
      if ((local_8 == 0) || (local_8 != *(int *)((int)this + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (iVar6 == iVar11) break;
      if (iVar10 == 0) {
        FUN_0047a948();
      }
      if (iVar6 == *(int *)(iVar10 + 4)) {
        FUN_0047a948();
      }
      iVar11 = *(int *)(iVar6 + 0x10) + iVar13;
      if ((*(int *)(&DAT_004f6ce8 + iVar11 * 8) == 1) && (*(int *)(&DAT_004f6cec + iVar11 * 8) == 0)
         ) {
LAB_00440fce:
        if (iVar6 == *(int *)(iVar10 + 4)) {
          FUN_0047a948();
        }
        ppiVar8 = UnitList_FindOrInsert
                            ((void *)(*(int *)((int)this + 8) + 0x2450),(int *)(iVar6 + 0xc));
        if (iVar6 == *(int *)(iVar10 + 4)) {
          FUN_0047a948();
        }
        ppiVar9 = AdjacencyList_FilterByUnitType
                            ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar6 + 0xc) * 0x24),
                             (ushort *)(ppiVar8 + 1));
        local_c = (int *)*ppiVar9[1];
        bVar1 = false;
        bVar2 = false;
        bVar3 = false;
        bVar7 = false;
        local_10 = ppiVar9;
        while( true ) {
          piVar5 = local_c;
          ppiVar4 = local_10;
          piVar12 = ppiVar9[1];
          if ((local_10 == (int **)0x0) || (local_10 != ppiVar9)) {
            FUN_0047a948();
          }
          if (piVar5 == piVar12) break;
          if (ppiVar4 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar5 == ppiVar4[1]) {
            FUN_0047a948();
          }
          if (piVar5[3] == param_2) {
            bVar1 = true;
          }
          if (piVar5 == ppiVar4[1]) {
            FUN_0047a948();
          }
          if (((int *)piVar5[3] == param_4) || (*ppiVar8 == param_4)) {
            bVar2 = true;
          }
          if (piVar5 == ppiVar4[1]) {
            FUN_0047a948();
          }
          if ((piVar5[3] == param_3) && (*ppiVar8 == param_4)) {
            if (piVar5 == ppiVar4[1]) {
              FUN_0047a948();
            }
            if ((&g_ThreatScore)[(int)ppiVar8[2] * 0x100 + piVar5[3]] -
                (&g_ProvinceBaseScore)[(int)param_4 * 0x1e] == 1) {
              bVar3 = true;
            }
          }
          if (piVar5 == ppiVar4[1]) {
            FUN_0047a948();
          }
          if (piVar5[3] != param_2) {
            if (piVar5 == ppiVar4[1]) {
              FUN_0047a948();
            }
            if (((int *)piVar5[3] != param_4) && (*ppiVar8 != param_4)) {
              if (piVar5 == ppiVar4[1]) {
                FUN_0047a948();
              }
              if ((*(int *)(&g_SCOwnership + (piVar5[3] + iVar13) * 8) == 1) &&
                 (*(int *)(&DAT_00520cec + (piVar5[3] + iVar13) * 8) == 0)) {
                if (piVar5 == ppiVar4[1]) {
                  FUN_0047a948();
                }
                if ((&g_OrderTable)[piVar5[3] * 0x1e] == 4) {
                  if (piVar5 == ppiVar4[1]) {
                    FUN_0047a948();
                  }
                  if ((int *)(&DAT_00baeda8)[piVar5[3] * 0x1e] == param_4) {
                    if (piVar5 == ppiVar4[1]) {
                      FUN_0047a948();
                    }
                    if ((&DAT_00baede0)[piVar5[3] * 0x1e] == 1) {
                      bVar7 = true;
                    }
                  }
                }
              }
            }
          }
          FUN_0040f400((int *)&local_10);
        }
        if (bVar7) {
          if ((&DAT_00baede0)[iVar14 * 2] != 1) {
            if ((((&DAT_00baede0)[iVar14 * 2] == 2) && (bVar1)) && (bVar2)) goto LAB_0044120d;
            goto LAB_004411f5;
          }
          bVar7 = true;
        }
        else {
LAB_004411f5:
          bVar7 = false;
        }
        if (((bVar1) && (!bVar2)) && (!bVar7)) {
          bVar15 = false;
        }
      }
      else {
        if (iVar6 == *(int *)(iVar10 + 4)) {
          FUN_0047a948();
        }
        iVar11 = *(int *)(iVar6 + 0x10) + iVar13;
        if ((*(int *)(&DAT_0050bce8 + iVar11 * 8) == 1) &&
           (*(int *)(&DAT_0050bcec + iVar11 * 8) == 0)) goto LAB_00440fce;
      }
LAB_0044120d:
      UnitList_Advance(&local_8);
    }
    iVar11 = (int)param_4 * 0x78;
    piVar12 = param_4;
    if (bVar15) {
      (&g_ProvinceBaseScore)[(int)param_4 * 0x1e] = (&g_ProvinceBaseScore)[(int)param_4 * 0x1e] + 1;
      if (bVar3) {
        ppiVar8 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),(int *)&param_4);
        iVar14 = (int)ppiVar8[2] * 0x100 + param_3;
        (&g_ProximityScore)[iVar14] = (&g_ProximityScore)[iVar14] + 2;
        piVar12 = &g_ProximityScore + iVar14;
      }
      goto LAB_0044128f;
    }
  }
  else {
    iVar11 = (int)param_4 * 0x78;
  }
  *(int *)((int)&DAT_00baedd8 + iVar11) = *(int *)((int)&DAT_00baedd8 + iVar11) + 1;
LAB_0044128f:
  if (*(int *)((int)&DAT_00baedf0 + iVar11) == 1) {
    *(undefined4 *)((int)&DAT_00baedf0 + iVar11) = 0;
    (&g_SupportAssignmentMap)[(int)param_4] = 0xffffffff;
  }
  return piVar12;
}

