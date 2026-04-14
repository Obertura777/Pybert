
void __thiscall ScoreOrderCandidates_OwnPower(void *this,int param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  void *pvVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  int **ppiVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  void *local_3c;
  void *local_30;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  int local_c;
  
  uVar10 = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_2c = **(int **)((int)this + uVar10 * 0x78 + 0x3620);
  pvVar1 = (void *)((int)this + uVar10 * 0x78 + 0x361c);
  local_20 = 1;
  local_30 = pvVar1;
  while( true ) {
    iVar9 = local_2c;
    local_c = *(int *)((int)pvVar1 + 4);
    if ((local_30 == (void *)0x0) || (local_30 != pvVar1)) {
      FUN_0047a948();
    }
    if (iVar9 == local_c) break;
    if (local_30 == (void *)0x0) {
      FUN_0047a948();
    }
    if (iVar9 == *(int *)((int)local_30 + 4)) {
      FUN_0047a948();
    }
    local_28 = *(int **)(iVar9 + 0x10);
    local_24 = *(undefined4 *)(iVar9 + 0x14);
    iVar9 = 0;
    lVar12 = 0;
    local_3c = pvVar1;
    do {
      local_18._0_4_ = (int)lVar12;
      ppiVar6 = OrderedSet_FindOrInsert(local_3c,&local_28);
      lVar11 = __allmul(*(uint *)(param_1 + iVar9 * 8),*(uint *)(param_1 + 4 + iVar9 * 8),
                        (uint)*ppiVar6,(uint)ppiVar6[1]);
      lVar12 = lVar11 + CONCAT44((int)((ulonglong)lVar12 >> 0x20),(int)local_18);
      local_18._0_4_ = (int)lVar12;
      local_3c = (void *)((int)local_3c + 0xc);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 10);
    lVar11 = __allmul((&g_AttackCount)[(int)(local_28 + uVar10 * 0x40) * 2],
                      (&DAT_006040ec)[(int)(local_28 + uVar10 * 0x40) * 2],param_2,param_3);
    lVar11 = lVar11 + CONCAT44((int)((ulonglong)lVar12 >> 0x20),(int)local_18);
    iVar9 = (int)((ulonglong)lVar11 >> 0x20);
    lVar12 = local_20;
    if (((int)local_20._4_4_ <= iVar9) &&
       (((int)local_20._4_4_ < iVar9 || ((uint)local_20 < (uint)lVar11)))) {
      lVar12 = lVar11;
    }
    local_20 = lVar12;
    ppiVar6 = OrderedSet_FindOrInsert((void *)((int)this + uVar10 * 0xc + 0x4000),&local_28);
    *(longlong *)ppiVar6 = lVar11;
    std_Tree_IteratorIncrement((int *)&local_30);
  }
  local_2c = **(int **)((int)pvVar1 + 4);
  local_30 = pvVar1;
  while( true ) {
    iVar9 = local_2c;
    local_c = *(int *)((int)pvVar1 + 4);
    if ((local_30 == (void *)0x0) || (local_30 != pvVar1)) {
      FUN_0047a948();
    }
    if (iVar9 == local_c) break;
    if (local_30 == (void *)0x0) {
      FUN_0047a948();
    }
    if (iVar9 == *(int *)((int)local_30 + 4)) {
      FUN_0047a948();
    }
    local_24 = *(undefined4 *)(iVar9 + 0x14);
    piVar8 = *(int **)(iVar9 + 0x10);
    pvVar2 = (void *)((int)this + uVar10 * 0xc + 0x4000);
    local_28 = piVar8;
    ppiVar6 = OrderedSet_FindOrInsert(pvVar2,&local_28);
    lVar12 = __allmul((uint)*ppiVar6,(uint)ppiVar6[1],1000,0);
    uVar13 = __alldiv((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),(uint)local_20,local_20._4_4_);
    local_18 = uVar13;
    ppiVar6 = OrderedSet_FindOrInsert(pvVar2,&local_28);
    *(undefined8 *)ppiVar6 = local_18;
    ppiVar6 = OrderedSet_FindOrInsert(pvVar2,&local_28);
    piVar8 = piVar8 + uVar10 * 0x40;
    iVar9 = (int)piVar8 * 8;
    if ((*(int *)(&DAT_0055b0ec + (int)piVar8 * 8) <= (int)ppiVar6[1]) &&
       ((*(int *)(&DAT_0055b0ec + (int)piVar8 * 8) < (int)ppiVar6[1] ||
        (*(int **)(&g_MaxProvinceScore + iVar9) < *ppiVar6)))) {
      ppiVar6 = OrderedSet_FindOrInsert(pvVar2,&local_28);
      *(int **)(&g_MaxProvinceScore + iVar9) = *ppiVar6;
      *(int **)(&DAT_0055b0ec + iVar9) = ppiVar6[1];
    }
    std_Tree_IteratorIncrement((int *)&local_30);
  }
  local_2c = **(int **)((int)pvVar1 + 4);
  local_30 = pvVar1;
  while( true ) {
    pvVar2 = local_30;
    local_c = *(int *)((int)pvVar1 + 4);
    if ((local_30 == (void *)0x0) || (local_30 != pvVar1)) {
      FUN_0047a948();
    }
    if (local_2c == local_c) break;
    if (pvVar2 == (void *)0x0) {
      FUN_0047a948();
    }
    if (local_2c == *(int *)((int)pvVar2 + 4)) {
      FUN_0047a948();
    }
    piVar8 = *(int **)(local_2c + 0x10);
    local_24 = *(undefined4 *)(local_2c + 0x14);
    local_28 = piVar8;
    if (AMY == (short)local_24) {
      pvVar2 = (void *)((int)this + uVar10 * 0xc + 0x4000);
      ppiVar6 = OrderedSet_FindOrInsert(pvVar2,&local_28);
      iVar9 = (int)(piVar8 + uVar10 * 0x40) * 8;
      if (((int)ppiVar6[1] <= *(int *)(&DAT_0055b0ec + (int)(piVar8 + uVar10 * 0x40) * 8)) &&
         (((int)ppiVar6[1] < *(int *)(&DAT_0055b0ec + (int)(piVar8 + uVar10 * 0x40) * 8) ||
          (*ppiVar6 < *(int **)(&g_MaxProvinceScore + iVar9))))) {
        ppiVar6 = OrderedSet_FindOrInsert(pvVar2,&local_28);
        ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_28);
        piVar8 = *(int **)(&g_MaxProvinceScore + iVar9);
        local_18._0_4_ = (int)piVar8 - (int)*ppiVar7;
        local_18._4_4_ =
             (*(int *)(&DAT_0055b0ec + iVar9) - (int)ppiVar7[1]) - (uint)(piVar8 < *ppiVar7);
        uVar14 = PackScoreU64();
        *(ulonglong *)ppiVar6 = uVar14;
      }
    }
    std_Tree_IteratorIncrement((int *)&local_30);
  }
  iVar9 = uVar10 * 0xc;
  cVar3 = *(char *)((int)*(int **)(*(int *)(&DAT_00bc202c + iVar9) + 4) + 0x21);
  piVar8 = *(int **)(*(int *)(&DAT_00bc202c + iVar9) + 4);
  while (cVar3 == '\0') {
    std_Tree_DestroyTree((int *)piVar8[2]);
    piVar4 = (int *)*piVar8;
    _free(piVar8);
    piVar8 = piVar4;
    cVar3 = *(char *)((int)piVar4 + 0x21);
  }
  *(int *)(*(int *)(&DAT_00bc202c + iVar9) + 4) = *(int *)(&DAT_00bc202c + iVar9);
  *(undefined4 *)(&DAT_00bc2030 + iVar9) = 0;
  *(undefined4 *)*(undefined4 *)(&DAT_00bc202c + iVar9) = *(undefined4 *)(&DAT_00bc202c + iVar9);
  *(int *)(*(int *)(&DAT_00bc202c + iVar9) + 8) = *(int *)(&DAT_00bc202c + iVar9);
  local_2c = **(int **)((int)pvVar1 + 4);
  local_30 = pvVar1;
  while( true ) {
    iVar5 = local_2c;
    local_c = *(int *)((int)pvVar1 + 4);
    if ((local_30 == (void *)0x0) || (local_30 != pvVar1)) {
      FUN_0047a948();
    }
    if (iVar5 == local_c) break;
    if (local_30 == (void *)0x0) {
      FUN_0047a948();
    }
    if (iVar5 == *(int *)((int)local_30 + 4)) {
      FUN_0047a948();
    }
    local_28 = *(int **)(iVar5 + 0x10);
    local_24 = *(undefined4 *)(iVar5 + 0x14);
    ppiVar6 = OrderedSet_FindOrInsert(&DAT_00bc1e28 + iVar9,&local_28);
    ppiVar7 = OrderedSet_FindOrInsert(&DAT_00bc2028 + iVar9,&local_28);
    *ppiVar7 = *ppiVar6;
    ppiVar7[1] = ppiVar6[1];
    std_Tree_IteratorIncrement((int *)&local_30);
  }
  return;
}

