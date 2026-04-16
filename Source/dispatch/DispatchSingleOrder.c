
void __thiscall DispatchSingleOrder(void *this,int *power_index)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  byte *pbVar7;
  int **ppiVar8;
  uint *puVar9;
  void **ppvVar10;
  int *piVar11;
  int iVar12;
  undefined2 uVar13;
  uint *apuStack_7c [2];
  undefined2 auStack_74 [2];
  undefined1 *apuStack_70 [4];
  int *apiStack_60 [4];
  int iStack_50;
  int *piStack_4c;
  uint local_48;
  void *apvStack_3c [4];
  void *apvStack_2c [4];
  void *apvStack_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00497a00;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  local_48 = local_48 & 0xffff0000;
  piVar4 = FUN_0047020b();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_50 = (**(code **)(*piVar4 + 0xc))();
  iStack_50 = iStack_50 + 0x10;
  local_4._0_1_ = 1;
  FUN_00465870(apvStack_3c);
  local_4._0_1_ = 2;
  FUN_00465870(apvStack_1c);
  local_4._0_1_ = 3;
  puVar5 = GetSubList(&stack0x00000008,apiStack_60,0);
  local_4._0_1_ = 4;
  GetListElement(puVar5,auStack_74,0);
  local_4._0_1_ = 3;
  FreeList(apiStack_60);
  puVar5 = GetSubList(&stack0x00000008,apiStack_60,0);
  local_4._0_1_ = 5;
  puVar6 = (undefined2 *)GetListElement(puVar5,(undefined2 *)apuStack_7c,1);
  uVar13 = *puVar6;
  local_4._0_1_ = 3;
  auStack_74[0] = uVar13;
  FreeList(apiStack_60);
  puVar5 = GetSubList(&stack0x00000008,apuStack_70,0);
  local_4._0_1_ = 6;
  pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_7c,2);
  piVar4 = (int *)(uint)*pbVar7;
  local_4._0_1_ = 3;
  apiStack_60[0] = piVar4;
  FreeList(apuStack_70);
  ppiVar8 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),(int *)apiStack_60);
  if (ppiVar8[4] == (int *)0x0) {
    apiStack_60[0] = (int *)FUN_00465930((int)&stack0x00000008);
    puVar5 = GetSubList(&stack0x00000008,apvStack_2c,1);
    local_4._0_1_ = 7;
    puVar6 = (undefined2 *)GetListElement(puVar5,(undefined2 *)apuStack_70,0);
    apuStack_7c[0] = (uint *)CONCAT22(apuStack_7c[0]._2_2_,*puVar6);
    local_4._0_1_ = 3;
    FreeList(apvStack_2c);
    if (HLD == (short)apuStack_7c[0]) {
      BuildOrder_HLD(this,(int)power_index,(int)piVar4);
    }
    else if (MTO == (short)apuStack_7c[0]) {
      apiStack_60[0] = (int *)&stack0xffffff6c;
      local_4._0_1_ = 8;
      puVar5 = GetSubList(&stack0x00000008,apvStack_2c,2);
      local_4._0_1_ = 10;
      puVar9 = ParseDestinationWithCoast((uint *)apuStack_70,puVar5,uVar13);
      piVar11 = (int *)*puVar9;
      local_48 = puVar9[1];
      local_4._0_1_ = 3;
      piStack_4c = piVar11;
      FreeList(apvStack_2c);
      ppiVar8 = &piStack_4c;
      puVar5 = (undefined4 *)
               OrderedSet_FindOrInsert
                         ((void *)(*(int *)((int)this + 8) + 0x2450),(int *)apiStack_60,
                          (int *)ppiVar8);
      DAT_00bb65b4 = *puVar5;
      DAT_00bb65b8 = puVar5[1];
      apiStack_60[0] = (int *)&stack0xffffff68;
      BuildOrder_MTO(this,(uint)power_index,piVar4,piVar11,
                     CONCAT22((short)((uint)ppiVar8 >> 0x10),(undefined2)local_48));
    }
    else if (SUP == (short)apuStack_7c[0]) {
      ppvVar10 = (void **)GetSubList(&stack0x00000008,apvStack_2c,2);
      local_4._0_1_ = 0xb;
      AppendList(apvStack_3c,ppvVar10);
      local_4._0_1_ = 3;
      FreeList(apvStack_2c);
      puVar5 = GetSubList(&stack0x00000008,&piStack_4c,2);
      local_4._0_1_ = 0xc;
      puVar5 = GetSubList(puVar5,apvStack_2c,0);
      local_4._0_1_ = 0xd;
      GetListElement(puVar5,(undefined2 *)apuStack_70,0);
      local_4._0_1_ = 0xc;
      FreeList(apvStack_2c);
      local_4._0_1_ = 3;
      FreeList(&piStack_4c);
      puVar5 = GetSubList(&stack0x00000008,apvStack_2c,2);
      if (apiStack_60[0] == (int *)0x5) {
        local_4._0_1_ = 0xe;
        pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_70,2);
        bVar1 = *pbVar7;
        local_4._0_1_ = 3;
        FreeList(apvStack_2c);
        puVar5 = GetSubList(&stack0x00000008,apvStack_2c,4);
        local_4._0_1_ = 0xf;
        pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_70,0);
        apiStack_60[0] = (int *)(uint)*pbVar7;
        local_4._0_1_ = 3;
        FreeList(apvStack_2c);
        BuildOrder_SUP_MTO(this,power_index,(int)piVar4,(uint)bVar1,apiStack_60[0]);
      }
      else {
        local_4._0_1_ = 0x10;
        pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_70,2);
        bVar1 = *pbVar7;
        local_4._0_1_ = 3;
        FreeList(apvStack_2c);
        BuildOrder_SUP_HLD(this,power_index,(int)piVar4,(uint)bVar1);
      }
    }
    else if (CTO == (short)apuStack_7c[0]) {
      *(undefined4 *)((int)this + 0x2a10) = 0xffffffff;
      *(undefined4 *)((int)this + 0x2a14) = 0xffffffff;
      *(undefined4 *)((int)this + 0x2a18) = 0xffffffff;
      ClearConvoyState();
      puVar5 = GetSubList(&stack0x00000008,apvStack_2c,4);
      local_4._0_1_ = 0x11;
      piVar11 = (int *)FUN_00465930((int)puVar5);
      local_4._0_1_ = 3;
      apiStack_60[0] = piVar11;
      FreeList(apvStack_2c);
      if ((int)piVar11 < 4) {
        iVar12 = 0;
        if (0 < (int)apiStack_60[0]) {
          apuStack_7c[0] = (uint *)((int)this + 0x2a10);
          do {
            puVar5 = GetSubList(&stack0x00000008,apvStack_2c,4);
            local_4._0_1_ = 0x12;
            pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_70,iVar12);
            *apuStack_7c[0] = (uint)*pbVar7;
            local_4._0_1_ = 3;
            FreeList(apvStack_2c);
            apuStack_7c[0] = apuStack_7c[0] + 1;
            iVar12 = iVar12 + 1;
          } while (iVar12 < (int)apiStack_60[0]);
        }
        apuStack_70[0] = &stack0xffffff6c;
        local_4._0_1_ = 0x13;
        uVar13 = auStack_74[0];
        puVar5 = GetSubList(&stack0x00000008,apvStack_2c,2);
        local_4._0_1_ = 0x15;
        puVar9 = ParseDestinationWithCoast((uint *)apuStack_7c,puVar5,uVar13);
        piVar11 = (int *)*puVar9;
        local_48 = puVar9[1];
        local_4._0_1_ = 3;
        piStack_4c = piVar11;
        FreeList(apvStack_2c);
        BuildOrder_CTO(*(void **)((int)this + 8),(int)piVar4,piVar11,(int)apiStack_60[0],
                       (undefined4 *)((int)this + 0x2a10));
        ppiVar8 = ConvoyList_Insert(&DAT_00bb65a0,(int *)&piStack_4c);
        *ppiVar8 = piVar4;
        (&g_OrderTable)[(int)piVar4 * 0x1e] = 6;
        (&DAT_00baeda8)[(int)piVar4 * 0x1e] = piVar11;
        *(uint *)(&DAT_00baedac + (int)piVar4 * 0x3c) = local_48;
        (&DAT_00baedfc)[(int)piVar4 * 0x1e] =
             *(undefined4 *)((int)this + (int)piVar11 * 0x14 + 0x214);
        (&DAT_00baee08)[(int)piVar4 * 0x1e] = *(undefined4 *)((int)this + 0x2a10);
        (&DAT_00baee0c)[(int)piVar4 * 0x1e] = *(undefined4 *)((int)this + 0x2a14);
        (&DAT_00baee10)[(int)piVar4 * 0x1e] = *(undefined4 *)((int)this + 0x2a18);
        (&g_ProvinceBaseScore)[(int)piVar11 * 0x1e] = 1;
        ppiVar8 = OrderedSet_FindOrInsert
                            ((void *)((int)this + (int)power_index * 0xc + 0x4000),&piStack_4c);
        (&g_ConvoyChainScore)[(int)piVar11 * 0x1e] = *ppiVar8;
        (&DAT_00baedbc)[(int)piVar11 * 0x1e] = ppiVar8[1];
      }
    }
    else if (CVY == (short)apuStack_7c[0]) {
      puVar5 = GetSubList(&stack0x00000008,apvStack_2c,2);
      local_4._0_1_ = 0x16;
      pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_70,2);
      bVar1 = *pbVar7;
      local_4._0_1_ = 3;
      FreeList(apvStack_2c);
      puVar5 = GetSubList(&stack0x00000008,apvStack_2c,4);
      local_4._0_1_ = 0x17;
      pbVar7 = (byte *)GetListElement(puVar5,(undefined2 *)apuStack_70,0);
      piStack_4c = (int *)(uint)*pbVar7;
      local_4._0_1_ = 3;
      FreeList(apvStack_2c);
      piVar11 = piStack_4c;
      local_48 = CONCAT22(local_48._2_2_,AMY);
      BuildOrder_CVY(*(void **)((int)this + 8),piVar4,(uint)bVar1,piStack_4c);
      (&g_OrderTable)[(int)piVar4 * 0x1e] = 5;
      (&DAT_00baeda4)[(int)piVar4 * 0x1e] = (uint)bVar1;
      (&DAT_00baeda8)[(int)piVar4 * 0x1e] = piVar11;
      *(uint *)(&DAT_00baedac + (int)piVar4 * 0x3c) = local_48;
      uVar2 = *(undefined4 *)(&g_MaxProvinceScore + (int)(piVar4 + (int)power_index * 0x40) * 8);
      uVar3 = *(undefined4 *)(&DAT_0055b0ec + (int)(piVar4 + (int)power_index * 0x40) * 8);
      (&g_ProvinceBaseScore)[(int)piVar4 * 0x1e] = 1;
      (&g_ConvoyChainScore)[(int)piVar4 * 0x1e] = uVar2;
      (&DAT_00baedbc)[(int)piVar4 * 0x1e] = uVar3;
      RegisterConvoyFleet(this,(int)power_index,(int)piVar4);
    }
  }
  local_4._0_1_ = 2;
  FreeList(apvStack_1c);
  local_4._0_1_ = 1;
  FreeList(apvStack_3c);
  local_4 = (uint)local_4._1_3_ << 8;
  piVar4 = (int *)(iStack_50 + -4);
  LOCK();
  iVar12 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar12 == 1 || iVar12 + -1 < 0) {
    (**(code **)(**(int **)(iStack_50 + -0x10) + 4))();
  }
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000008);
  ExceptionList = local_c;
  return;
}

