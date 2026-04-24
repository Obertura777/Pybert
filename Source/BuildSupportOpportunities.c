
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall BuildSupportOpportunities(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int **ppiVar7;
  int **ppiVar8;
  int **ppiVar9;
  int **ppiVar10;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  void *local_88;
  int local_84;
  int **local_80;
  int *local_7c;
  int **local_78;
  int *local_74;
  int **local_70;
  int *local_6c;
  int **local_68;
  int **local_64;
  int **local_60;
  int **local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined2 local_4c;
  int *local_48;
  undefined2 local_44;
  int *local_40;
  undefined2 local_3c;
  int *local_34;
  int local_2c;
  int *local_24;
  undefined2 local_20;
  undefined4 local_14 [4];
  
  local_84 = param_1;
  FUN_00410c70(*(int **)(DAT_00baed74 + 4));
  *(int *)(DAT_00baed74 + 4) = DAT_00baed74;
  _DAT_00baed78 = 0;
  *(int *)DAT_00baed74 = DAT_00baed74;
  *(int *)(DAT_00baed74 + 8) = DAT_00baed74;
  local_90 = *(int *)(param_1 + 8);
  local_94 = 0;
  if (0 < *(int *)(local_90 + 0x2404)) {
    local_88 = (void *)(param_1 + 0x4000);
    local_98 = 0;
    do {
      local_8c = **(int **)(local_90 + 0x2454);
      local_90 = local_90 + 0x2450;
      while( true ) {
        iVar5 = local_8c;
        iVar4 = local_90;
        iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
        if ((local_90 == 0) || (local_90 != *(int *)(param_1 + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar5 == iVar1) break;
        if (iVar4 == 0) {
          FUN_0047a948();
        }
        if (iVar5 == *(int *)(iVar4 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar5 + 0x18) == local_94) {
          if ((iVar5 == *(int *)(iVar4 + 4)) && (FUN_0047a948(), iVar5 == *(int *)(iVar4 + 4))) {
            FUN_0047a948();
          }
          local_80 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar5 + 0x10) * 0x24),
                                (ushort *)(iVar5 + 0x14));
          local_7c = (int *)*local_80[1];
          local_68 = local_80;
          while( true ) {
            piVar6 = local_7c;
            ppiVar10 = local_80;
            piVar2 = local_68[1];
            if ((local_80 == (int **)0x0) || (local_80 != local_68)) {
              FUN_0047a948();
            }
            if (piVar6 == piVar2) break;
            if (ppiVar10 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar6 == ppiVar10[1]) {
              FUN_0047a948();
            }
            ppiVar9 = (int **)(piVar6 + 3);
            if (((&DAT_005b98e8)[piVar6[3] * 2] == 1) && ((&DAT_005b98ec)[piVar6[3] * 2] == 0)) {
              if (piVar6 == ppiVar10[1]) {
                FUN_0047a948();
              }
              if ((*(int *)(&g_SCOwnership + ((int)*ppiVar9 + local_98) * 8) == 1) &&
                 (*(int *)(&DAT_00520cec + ((int)*ppiVar9 + local_98) * 8) == 0)) {
                if ((piVar6 == ppiVar10[1]) && (FUN_0047a948(), piVar6 == ppiVar10[1])) {
                  FUN_0047a948();
                }
                ppiVar8 = OrderedSet_FindOrInsert(local_88,ppiVar9);
                iVar1 = local_8c;
                if ((*ppiVar8 == *(int **)(&g_MaxProvinceScore + ((int)*ppiVar9 + local_98) * 8)) &&
                   (ppiVar8[1] == *(int **)(&DAT_0055b0ec + ((int)*ppiVar9 + local_98) * 8))) {
                  if (local_8c == *(int *)(local_90 + 4)) {
                    FUN_0047a948();
                  }
                  local_2c = *(int *)(iVar1 + 0x10);
                  if (piVar6 == ppiVar10[1]) {
                    FUN_0047a948();
                  }
                  iVar1 = local_84;
                  ppiVar9 = UnitList_FindOrInsert
                                      ((void *)(*(int *)(local_84 + 8) + 0x2450),(int *)ppiVar9);
                  local_24 = *ppiVar9;
                  if (piVar6 == ppiVar10[1]) {
                    FUN_0047a948();
                  }
                  local_20 = (undefined2)piVar6[4];
                  ppiVar10 = AdjacencyList_FilterByUnitType
                                       ((void *)(*(int *)(iVar1 + 8) + 8 + (int)*ppiVar9 * 0x24),
                                        (ushort *)(ppiVar9 + 1));
                  local_74 = (int *)*ppiVar10[1];
                  local_78 = ppiVar10;
                  local_5c = ppiVar10;
                  while( true ) {
                    piVar6 = local_74;
                    ppiVar9 = local_78;
                    piVar2 = ppiVar10[1];
                    if ((local_78 == (int **)0x0) || (local_78 != ppiVar10)) {
                      FUN_0047a948();
                    }
                    if (piVar6 == piVar2) break;
                    if (ppiVar9 == (int **)0x0) {
                      FUN_0047a948();
                    }
                    if (piVar6 == ppiVar9[1]) {
                      FUN_0047a948();
                    }
                    if ((*(int *)(&g_SCOwnership + (piVar6[3] + local_98) * 8) == 1) &&
                       (*(int *)(&DAT_00520cec + (piVar6[3] + local_98) * 8) == 0)) {
                      if (piVar6 == ppiVar9[1]) {
                        FUN_0047a948();
                      }
                      if (local_8c == *(int *)(local_90 + 4)) {
                        FUN_0047a948();
                      }
                      if (piVar6[3] != *(int *)(local_8c + 0x10)) {
                        if (piVar6 == ppiVar9[1]) {
                          FUN_0047a948();
                        }
                        iVar1 = local_84;
                        ppiVar9 = UnitList_FindOrInsert
                                            ((void *)(*(int *)(local_84 + 8) + 0x2450),piVar6 + 3);
                        local_60 = ppiVar9;
                        ppiVar8 = AdjacencyList_FilterByUnitType
                                            ((void *)(*(int *)(iVar1 + 8) + 8 + (int)*ppiVar9 * 0x24
                                                     ),(ushort *)(ppiVar9 + 1));
                        local_6c = (int *)*ppiVar8[1];
                        local_70 = ppiVar8;
                        local_64 = ppiVar8;
                        while( true ) {
                          piVar2 = local_6c;
                          ppiVar7 = local_70;
                          local_34 = ppiVar8[1];
                          if ((local_70 == (int **)0x0) || (local_70 != ppiVar8)) {
                            FUN_0047a948();
                          }
                          ppiVar10 = local_5c;
                          if (piVar2 == local_34) break;
                          if (ppiVar7 == (int **)0x0) {
                            FUN_0047a948();
                          }
                          if (piVar2 == ppiVar7[1]) {
                            FUN_0047a948();
                          }
                          piVar6 = local_74;
                          if (piVar2[3] == local_2c) {
                            piVar3 = *ppiVar9;
                            if (local_74 == local_78[1]) {
                              FUN_0047a948();
                            }
                            iVar1 = piVar6[4];
                            if (piVar2 == ppiVar7[1]) {
                              FUN_0047a948();
                            }
                            piVar6 = local_7c;
                            iVar4 = piVar2[4];
                            if (local_7c == local_80[1]) {
                              FUN_0047a948();
                            }
                            local_54 = local_94;
                            local_58 = *(int *)(&g_MaxProvinceScore + (piVar6[3] + local_98) * 8);
                            local_50 = local_2c;
                            local_48 = local_24;
                            local_44 = local_20;
                            local_4c = (short)iVar4;
                            local_40 = piVar3;
                            local_3c = (short)iVar1;
                            StdSet_Insert(&g_SupportOpportunitiesSet,local_14,&local_58);
                            ppiVar9 = local_60;
                            ppiVar8 = local_64;
                          }
                          FUN_0040f400((int *)&local_70);
                        }
                      }
                    }
                    FUN_0040f400((int *)&local_78);
                  }
                }
              }
            }
            FUN_0040f400((int *)&local_80);
            param_1 = local_84;
          }
        }
        UnitList_Advance(&local_90);
      }
      local_90 = *(int *)(param_1 + 8);
      local_88 = (void *)((int)local_88 + 0xc);
      local_98 = local_98 + 0x100;
      local_94 = local_94 + 1;
    } while (local_94 < *(int *)(local_90 + 0x2404));
  }
  return;
}

