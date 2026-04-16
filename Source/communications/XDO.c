
undefined4 XDO(void)

{
  CStringData *pCVar1;
  int iVar2;
  byte bVar3;
  short sVar4;
  int **ppiVar5;
  int iVar6;
  int *piVar7;
  void **ppvVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  uint uVar11;
  short *psVar12;
  CStringData *pCVar13;
  undefined4 extraout_EAX;
  int **ppiVar14;
  CStringData *pCVar15;
  int **ppiVar16;
  int **in_stack_00000018;
  undefined2 uStack_92;
  int **ppiStack_90;
  int **ppiStack_8c;
  void *pvStack_88;
  CStringData *pCStack_84;
  void *pvStack_80;
  int **ppiStack_7c;
  undefined1 local_78 [4];
  int **local_74;
  undefined4 local_70;
  void *pvStack_6c;
  void *pvStack_68;
  uint uStack_54;
  void *pvStack_50;
  int **ppiStack_4c;
  int **ppiStack_48;
  void *local_40 [4];
  int iStack_30;
  uint *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495c23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  FUN_00465870(local_40);
  local_4._0_1_ = 2;
  FUN_00465870(local_2c);
  local_4._0_1_ = 3;
  FUN_00465870(local_1c);
  local_4._0_1_ = 4;
  local_74 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_74 + 0x11) = 1;
  local_74[1] = (int *)local_74;
  *local_74 = (int *)local_74;
  local_74[2] = (int *)local_74;
  local_70 = 0;
  local_4 = CONCAT31(local_4._1_3_,5);
  piVar7 = FUN_0047020b();
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_30 = (**(code **)(*piVar7 + 0xc))();
  iStack_30 = iStack_30 + 0x10;
  local_4._0_1_ = 6;
  ppvVar8 = (void **)GetSubList(&stack0x00000004,&pvStack_6c,1);
  local_4._0_1_ = 7;
  AppendList(local_40,ppvVar8);
  local_4._0_1_ = 6;
  FreeList(&pvStack_6c);
  puVar9 = GetSubList(local_40,&pvStack_6c,0);
  local_4._0_1_ = 8;
  pbVar10 = (byte *)GetListElement(puVar9,&uStack_92,0);
  bVar3 = *pbVar10;
  local_4._0_1_ = 6;
  FreeList(&pvStack_6c);
  uVar11 = FUN_00465930((int)local_40);
  FUN_00419300(&DAT_00bb65f8 + (uint)bVar3 * 0xc,&pvStack_50,local_40);
  puVar9 = GetSubList(local_40,&pvStack_6c,0);
  local_4._0_1_ = 9;
  pbVar10 = (byte *)GetListElement(puVar9,&uStack_92,2);
  pvStack_80 = (void *)(uint)*pbVar10;
  local_4._0_1_ = 6;
  FreeList(&pvStack_6c);
  StdMap_FindOrInsert(&DAT_00bb6bf8 + (uint)bVar3 * 0xc,&pvStack_50,(int *)&pvStack_80);
  StdMap_FindOrInsert(&DAT_00bb713c,&pvStack_50,(int *)&pvStack_80);
  puVar9 = GetSubList(local_40,&pvStack_6c,1);
  local_4._0_1_ = 10;
  psVar12 = (short *)GetListElement(puVar9,&uStack_92,0);
  sVar4 = *psVar12;
  local_4._0_1_ = 6;
  FreeList(&pvStack_6c);
  if ((MTO == sVar4) || (CTO == sVar4)) {
    puVar9 = GetSubList(local_40,&pvStack_6c,2);
    local_4._0_1_ = 0xb;
    pbVar10 = (byte *)GetListElement(puVar9,&uStack_92,0);
    ppiStack_7c = (int **)(uint)*pbVar10;
    local_4._0_1_ = 6;
    FreeList(&pvStack_6c);
    ppiStack_8c = (int **)*in_stack_00000018;
    ppiStack_90 = (int **)&stack0x00000014;
    while( true ) {
      ppiVar5 = ppiStack_8c;
      ppiVar16 = ppiStack_90;
      ppiVar14 = in_stack_00000018;
      if ((ppiStack_90 == (int **)0x0) || (ppiStack_90 != (int **)&stack0x00000014)) {
        FUN_0047a948();
      }
      if (ppiVar5 == ppiVar14) break;
      pvStack_88 = pvStack_80;
      pCStack_84 = (CStringData *)ppiStack_7c;
      if (ppiVar16 == (int **)0x0) {
        FUN_0047a948();
      }
      if (ppiVar5 == (int **)ppiVar16[1]) {
        FUN_0047a948();
      }
      ScoreSupportOpp(&DAT_00bb67f8 + (int)ppiVar5[3] * 0xc,&pvStack_6c,(int *)&pvStack_88);
      TreeIterator_Advance((int *)&ppiStack_90);
    }
  }
  else if (SUP == sVar4) {
    ppvVar8 = (void **)GetSubList(local_40,&pvStack_6c,2);
    local_4._0_1_ = 0xc;
    AppendList(local_2c,ppvVar8);
    local_4._0_1_ = 6;
    FreeList(&pvStack_6c);
    puVar9 = GetSubList(local_2c,&pvStack_6c,1);
    local_4._0_1_ = 0xd;
    GetListElement(puVar9,&uStack_92,0);
    local_4._0_1_ = 6;
    FreeList(&pvStack_6c);
    puVar9 = GetSubList(local_2c,&pvStack_6c,2);
    local_4._0_1_ = 0xe;
    pbVar10 = (byte *)GetListElement(puVar9,&uStack_92,0);
    ppiVar14 = (int **)(uint)*pbVar10;
    local_4._0_1_ = 6;
    ppiStack_7c = ppiVar14;
    FreeList(&pvStack_6c);
    puVar9 = GetSubList(local_40,&pvStack_50,2);
    local_4._0_1_ = 0xf;
    puVar9 = GetSubList(puVar9,&pvStack_6c,0);
    local_4._0_1_ = 0x10;
    pbVar10 = (byte *)GetListElement(puVar9,&uStack_92,0);
    bVar3 = *pbVar10;
    local_4._0_1_ = 0xf;
    FreeList(&pvStack_6c);
    local_4._0_1_ = 6;
    FreeList(&pvStack_50);
    StdMap_FindOrInsert(&DAT_00bb713c,&pvStack_50,(int *)&ppiStack_7c);
    if (uVar11 == 5) {
      FUN_00465aa0(local_2c);
      puVar9 = GetSubList(local_40,&pvStack_6c,4);
      local_4._0_1_ = 0x11;
      pbVar10 = (byte *)GetListElement(puVar9,&uStack_92,0);
      ppiVar16 = (int **)(uint)*pbVar10;
      local_4._0_1_ = 6;
      FreeList(&pvStack_6c);
      ppiStack_90 = ppiVar14;
      ppiStack_8c = ppiVar16;
      ScoreSupportOpp(&DAT_00bb69f8 + (uint)bVar3 * 0xc,&pvStack_50,(int *)&ppiStack_90);
      ppiStack_8c = (int **)*in_stack_00000018;
      ppiStack_90 = (int **)&stack0x00000014;
      while( true ) {
        ppiVar5 = ppiStack_90;
        pCStack_84 = (CStringData *)in_stack_00000018;
        if ((ppiStack_90 == (int **)0x0) || (ppiStack_90 != (int **)&stack0x00000014)) {
          FUN_0047a948();
        }
        if ((CStringData *)ppiStack_8c == pCStack_84) break;
        pvStack_50 = pvStack_80;
        ppiStack_4c = ppiVar14;
        ppiStack_48 = ppiVar16;
        if (ppiVar5 == (int **)0x0) {
          FUN_0047a948();
        }
        if (ppiStack_8c == (int **)ppiVar5[1]) {
          FUN_0047a948();
        }
        FUN_004193f0(&DAT_00bb68f8 + (int)ppiStack_8c[3] * 0xc,&pvStack_6c,(int *)&pvStack_50);
        TreeIterator_Advance((int *)&ppiStack_90);
      }
    }
    else {
      StdMap_FindOrInsert(&DAT_00bb6af8 + (uint)bVar3 * 0xc,&pvStack_6c,(int *)&ppiStack_7c);
      ppiStack_8c = (int **)*in_stack_00000018;
      ppiStack_90 = (int **)&stack0x00000014;
      while( true ) {
        ppiVar5 = ppiStack_8c;
        ppiVar16 = ppiStack_90;
        pCStack_84 = (CStringData *)in_stack_00000018;
        if ((ppiStack_90 == (int **)0x0) || (ppiStack_90 != (int **)&stack0x00000014)) {
          FUN_0047a948();
        }
        if ((CStringData *)ppiVar5 == pCStack_84) break;
        pvStack_50 = pvStack_80;
        ppiStack_4c = ppiVar14;
        ppiStack_48 = ppiVar14;
        if (ppiVar16 == (int **)0x0) {
          FUN_0047a948();
        }
        if (ppiVar5 == (int **)ppiVar16[1]) {
          FUN_0047a948();
        }
        FUN_004193f0(&DAT_00bb68f8 + (int)ppiVar5[3] * 0xc,&pvStack_6c,(int *)&pvStack_50);
        TreeIterator_Advance((int *)&ppiStack_90);
      }
    }
  }
  FUN_0046b050(&stack0x00000004,&pvStack_6c);
  local_4._0_1_ = 0x12;
  SEND_LOG(&iStack_30,(wchar_t *)"Recalculating: Because we have applied a XDO: (%s)");
  local_4._0_1_ = 6;
  if (0xf < uStack_54) {
    _free(pvStack_68);
  }
  iVar6 = iStack_30;
  pCVar15 = (CStringData *)(iStack_30 + -0x10);
  pvStack_88 = (void *)0x66;
  pCVar13 = ATL::CSimpleStringT<char,0>::CloneData(pCVar15);
  pCStack_84 = pCVar13 + 0x10;
  local_4._0_1_ = 0x13;
  BuildAllianceMsg(&DAT_00bbf638,&pvStack_6c,(int *)&pvStack_88);
  local_4._0_1_ = 6;
  pCVar1 = pCVar13 + 0xc;
  LOCK();
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)pCVar13 + 4))(pCVar13);
  }
  local_4._0_1_ = 5;
  piVar7 = (int *)(iVar6 + -4);
  LOCK();
  iVar2 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)pCVar15 + 4))(pCVar15);
  }
  local_4._0_1_ = 4;
  SerializeOrders(local_78,&pvStack_88,local_78,(int **)*local_74,local_78,local_74);
  _free(local_74);
  local_74 = (int **)0x0;
  local_70 = 0;
  local_4._0_1_ = 3;
  FreeList(local_1c);
  local_4._0_1_ = 2;
  FreeList(local_2c);
  local_4._0_1_ = 1;
  FreeList(local_40);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000004);
  local_4 = 0xffffffff;
  SerializeOrders(&stack0x00000014,&pvStack_88,&stack0x00000014,(int **)*in_stack_00000018,
                  &stack0x00000014,in_stack_00000018);
  _free(in_stack_00000018);
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
}

