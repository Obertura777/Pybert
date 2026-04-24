
void __thiscall
AssignSupportOrder(void *this,uint param_1,int param_2,int *param_3,undefined4 param_4,int **param_5
                  )

{
  longlong lVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int **ppiVar7;
  int **ppiVar8;
  int **ppiVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  void *pvVar15;
  bool bVar16;
  int **local_18;
  int *local_14;
  int local_c;
  int local_8 [2];
  
  bVar16 = false;
  ppiVar8 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),&param_2);
  uVar6 = param_1;
  iVar14 = param_1 * 0x100 + param_2;
  if (((((&g_EnemyReachScore)[iVar14 * 2] == 1) && ((&DAT_00535cec)[iVar14 * 2] == 0)) &&
      (*(int *)(&DAT_004f6ce8 + (int)(param_3 + param_1 * 0x40) * 8) == 1)) &&
     (*(int *)(&DAT_004f6cec + (int)(param_3 + param_1 * 0x40) * 8) == 0)) {
    ppiVar9 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),(int *)&param_3);
    ppiVar9 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)((int)this + 8) + 8 + (int)param_3 * 0x24),
                         (ushort *)(ppiVar9 + 1));
    local_14 = (int *)*ppiVar9[1];
    bVar16 = false;
    local_18 = ppiVar9;
    while( true ) {
      piVar11 = local_14;
      ppiVar7 = local_18;
      piVar13 = ppiVar9[1];
      if ((local_18 == (int **)0x0) || (local_18 != ppiVar9)) {
        FUN_0047a948();
      }
      if (piVar11 == piVar13) break;
      if (ppiVar7 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar11 == ppiVar7[1]) {
        FUN_0047a948();
      }
      if (piVar11[3] == param_2) {
        bVar16 = true;
      }
      FUN_0040f400((int *)&local_18);
    }
  }
  if (((((&g_EnemyReachScore)[iVar14 * 2] != 1) || ((&DAT_00535cec)[iVar14 * 2] != 0)) ||
      ((*(int *)(&DAT_004f6ce8 + (int)(param_3 + uVar6 * 0x40) * 8) != 1 ||
       ((*(int *)(&DAT_004f6cec + (int)(param_3 + uVar6 * 0x40) * 8) != 0 || (!bVar16)))))) &&
     ((&g_EnemyReachScore)[iVar14 * 2] != 0 || (&DAT_00535cec)[iVar14 * 2] != 0)) goto LAB_0044150f;
  iVar4 = *(int *)((int)this + 8);
  if (*(char *)(iVar4 + 3 + param_2 * 0x24) == '\0') {
LAB_00441475:
    pvVar15 = (void *)((int)this + param_1 * 0xc + 0x4000);
    ppiVar9 = OrderedSet_FindOrInsert(pvVar15,&param_3);
    lVar1 = *(longlong *)ppiVar9;
    ppiVar9 = OrderedSet_FindOrInsert(pvVar15,ppiVar8);
    if (((double)*(longlong *)ppiVar9 * 0.85 < (double)lVar1) ||
       ((-1 < (int)(&DAT_006040ec)[iVar14 * 2] &&
        ((0 < (int)(&DAT_006040ec)[iVar14 * 2] || ((&g_AttackCount)[iVar14 * 2] != 0)))))) {
      ppiVar9 = OrderedSet_FindOrInsert(pvVar15,ppiVar8);
      iVar14 = param_2;
      (&DAT_00baede8)[param_2 * 0x1e] = *ppiVar9;
      (&DAT_00baedec)[param_2 * 0x1e] = ppiVar9[1];
      ppiVar8 = OrderedSet_FindOrInsert(pvVar15,ppiVar8);
      (&g_ConvoyChainScore)[iVar14 * 0x1e] = *ppiVar8;
      (&DAT_00baedbc)[iVar14 * 0x1e] = ppiVar8[1];
    }
  }
  else {
    uVar3 = *(ushort *)(iVar4 + param_2 * 0x24 + 0x20);
    uVar10 = uVar3 & 0xff;
    if ((char)(uVar3 >> 8) != 'A') {
      uVar10 = 0x14;
    }
    if (uVar10 == param_1) goto LAB_00441475;
    iVar4 = iVar4 + (int)param_3 * 0x24;
    cVar2 = *(char *)(iVar4 + 3);
    if (cVar2 != '\0') {
      if (cVar2 == '\x01') {
        uVar3 = *(ushort *)(iVar4 + 0x20);
        uVar10 = uVar3 & 0xff;
        if ((char)(uVar3 >> 8) != 'A') {
          uVar10 = 0x14;
        }
        if (uVar10 == param_1) goto LAB_0044150f;
      }
      goto LAB_00441475;
    }
  }
LAB_0044150f:
  piVar13 = param_3;
  if (((&DAT_00baeddc)[(int)param_3 * 0x1e] == 1) &&
     (piVar11 = param_3 + uVar6 * 0x40, iVar14 = (int)piVar11 * 8,
     *(int *)(&DAT_006190e8 + (int)piVar11 * 8) == 0 && *(int *)(&DAT_006190ec + iVar14) == 0)) {
    iVar4 = (&DAT_0058f8ec)[(int)piVar11 * 2];
    if ((-1 < iVar4) &&
       ((((0 < iVar4 || (1 < (uint)(&DAT_0058f8e8)[(int)piVar11 * 2])) &&
         (*(int *)(&g_SCOwnership + iVar14) == 0 && *(int *)(&DAT_00520cec + iVar14) == 0)) ||
        ((((-1 < iVar4 && ((0 < iVar4 || (2 < (uint)(&DAT_0058f8e8)[(int)piVar11 * 2])))) &&
          (*(int *)(&g_SCOwnership + iVar14) == 1)) && (*(int *)(&DAT_00520cec + iVar14) == 0))))))
    {
      iVar4 = param_2 * 0x1e;
      if ((&DAT_00baeddc)[param_2 * 0x1e] != 1) {
        iVar5 = (int)param_3 * 0x24;
        local_c = *(int *)(iVar5 + 0x18 + *(int *)((int)this + 8));
        pvVar15 = (void *)(iVar5 + 0x14 + *(int *)((int)this + 8));
        puVar12 = (undefined4 *)GameBoard_GetPowerRec(pvVar15,local_8,(int *)&param_1);
        if (((void *)*puVar12 == (void *)0x0) || ((void *)*puVar12 != pvVar15)) {
          FUN_0047a948();
        }
        if (puVar12[1] == local_c) goto LAB_00441685;
        uVar3 = *(ushort *)(iVar5 + 0x20 + *(int *)((int)this + 8));
        uVar10 = uVar3 & 0xff;
        if ((char)(uVar3 >> 8) != 'A') {
          uVar10 = 0x14;
        }
        if ((uVar10 != param_1) || ((&DAT_00baeddc)[iVar4] != 0)) goto LAB_00441685;
      }
      if (((&DAT_00baedf0)[(int)piVar13 * 0x1e] == 0) &&
         (((((&DAT_00baede8)[(int)piVar13 * 0x1e] & (&DAT_00baedec)[(int)piVar13 * 0x1e]) ==
            0xffffffff &&
           (*(int *)(&DAT_004f6ce8 + iVar14) == 0 && *(int *)(&DAT_004f6cec + iVar14) == 0)) &&
          ((char)param_5 == '\0')))) {
        (&DAT_00baedf0)[(int)piVar13 * 0x1e] = 1;
        (&g_SupportAssignmentMap)[(int)param_3] = param_2;
      }
    }
  }
LAB_00441685:
  iVar14 = *(int *)(*(int *)((int)this + 8) + 0x24b8);
  pvVar15 = (void *)(*(int *)((int)this + 8) + 0x24b4);
  piVar13 = (int *)GameBoard_GetPowerRec(pvVar15,local_8,(int *)&param_3);
  if (((void *)*piVar13 == (void *)0x0) || ((void *)*piVar13 != pvVar15)) {
    FUN_0047a948();
  }
  if (piVar13[1] != iVar14) {
    if (DAT_00bb65b4 == 0) {
      FUN_0047a948();
    }
    if (DAT_00bb65b8 == *(int *)(DAT_00bb65b4 + 4)) {
      FUN_0047a948();
    }
    if (*(int *)(DAT_00bb65b8 + 0x20) == 2) {
      if (DAT_00bb65b4 == 0) {
        FUN_0047a948();
      }
      if (DAT_00bb65b8 == *(int *)(DAT_00bb65b4 + 4)) {
        FUN_0047a948();
      }
      if ((&DAT_00baedf0)[*(int *)(DAT_00bb65b8 + 0x24) * 0x1e] == 1) {
        if (DAT_00bb65b4 == 0) {
          FUN_0047a948();
        }
        if (DAT_00bb65b8 == *(int *)(DAT_00bb65b4 + 4)) {
          FUN_0047a948();
        }
        bVar16 = DAT_00bb65b4 == 0;
        (&DAT_00baedf0)[*(int *)(DAT_00bb65b8 + 0x24) * 0x1e] = 0;
        if (bVar16) {
          FUN_0047a948();
        }
        if (DAT_00bb65b8 == *(int *)(DAT_00bb65b4 + 4)) {
          FUN_0047a948();
        }
        (&g_SupportAssignmentMap)[*(int *)(DAT_00bb65b8 + 0x24)] = 0xffffffff;
      }
    }
  }
  piVar13 = param_3;
  if ((*(int *)(&DAT_004f6ce8 + (int)(param_3 + uVar6 * 0x40) * 8) == 1) &&
     (*(int *)(&DAT_004f6cec + (int)(param_3 + uVar6 * 0x40) * 8) == 0)) {
    ppiVar8 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),(int *)&param_3);
    param_5 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)((int)this + 8) + 8 + (int)piVar13 * 0x24),
                         (ushort *)(ppiVar8 + 1));
    local_14 = (int *)*param_5[1];
    local_18 = param_5;
    while( true ) {
      piVar11 = local_14;
      ppiVar9 = local_18;
      piVar13 = param_5[1];
      if ((local_18 == (int **)0x0) || (local_18 != param_5)) {
        FUN_0047a948();
      }
      if (piVar11 == piVar13) break;
      if (ppiVar9 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar11 == ppiVar9[1]) {
        FUN_0047a948();
      }
      if (piVar11[3] != param_2) {
        if (piVar11 == ppiVar9[1]) {
          FUN_0047a948();
        }
        (&g_ProximityScore)[(int)ppiVar8[2] * 0x100 + piVar11[3]] =
             (&g_ProximityScore)[(int)ppiVar8[2] * 0x100 + piVar11[3]] + 1;
      }
      if (piVar11 == ppiVar9[1]) {
        FUN_0047a948();
      }
      if (piVar11[3] == param_2) {
        if (piVar11 == ppiVar9[1]) {
          FUN_0047a948();
        }
        if ((&g_ThreatScore)[(int)ppiVar8[2] * 0x100 + piVar11[3]] == 1) {
          if (piVar11 == ppiVar9[1]) {
            FUN_0047a948();
          }
          (&g_ProximityScore)[(int)ppiVar8[2] * 0x100 + piVar11[3]] =
               (&g_ProximityScore)[(int)ppiVar8[2] * 0x100 + piVar11[3]] + 2;
        }
      }
      FUN_0040f400((int *)&local_18);
    }
  }
  return;
}

