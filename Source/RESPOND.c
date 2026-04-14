
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall RESPOND(void *this,void *param_1,short param_2,uint param_3,int param_4)

{
  CStringData *pCVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  void **ppvVar5;
  undefined2 *puVar6;
  byte *pbVar7;
  void *pvVar8;
  uint **ppuVar9;
  uint *puVar10;
  uint **ppuVar11;
  CStringData *pCVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint *puVar20;
  undefined2 local_c8 [2];
  uint uStack_c4;
  int iStack_c0;
  uint *puStack_bc;
  CStringData *pCStack_b8;
  uint *puStack_ac;
  void *pvStack_a8;
  void *apvStack_a4 [4];
  uint uStack_94;
  undefined2 uStack_8e;
  uint *apuStack_8c [2];
  uint uStack_84;
  int iStack_80;
  uint *apuStack_7c [4];
  uint *local_6c;
  int iStack_68;
  void *local_5c [4];
  void *local_4c [4];
  void *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00495ec8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar18 = 0;
  local_c8[0] = 0;
  local_6c = this;
  FUN_00465870(local_3c);
  local_4 = 0;
  FUN_00465870(local_1c);
  local_4._0_1_ = 1;
  FUN_00465870(local_5c);
  local_4._0_1_ = 2;
  FUN_00465870(local_4c);
  local_4._0_1_ = 3;
  FUN_00465870(local_2c);
  local_4 = CONCAT31(local_4._1_3_,4);
  piVar4 = FUN_0047020b();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_c0 = (**(code **)(*piVar4 + 0xc))();
  iStack_c0 = iStack_c0 + 0x10;
  uStack_c4 = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 5;
  ppvVar5 = (void **)GetSubList(param_1,&puStack_ac,1);
  local_4._0_1_ = 6;
  AppendList(local_1c,ppvVar5);
  local_4._0_1_ = 5;
  FreeList(&puStack_ac);
  puVar6 = (undefined2 *)FUN_004658f0(local_1c,&uStack_8e);
  local_c8[0] = *puVar6;
  ppvVar5 = (void **)GetSubList(param_1,&puStack_ac,2);
  local_4._0_1_ = 7;
  AppendList(local_4c,ppvVar5);
  local_4._0_1_ = 5;
  FreeList(&puStack_ac);
  ppvVar5 = (void **)GetSubList(param_1,&puStack_ac,3);
  local_4._0_1_ = 8;
  AppendList(local_3c,ppvVar5);
  local_4._0_1_ = 5;
  FreeList(&puStack_ac);
  puStack_bc = (uint *)0xffffffff;
  FUN_00465f30(&puStack_ac,local_c8);
  local_4._0_1_ = 9;
  AppendList(local_2c,&puStack_ac);
  local_4 = CONCAT31(local_4._1_3_,5);
  FreeList(&puStack_ac);
  iVar16 = -1;
  if (-1 < *(int *)(&DAT_00ba27b4 + (uint)(byte)local_c8[0] * 8)) {
    iVar16 = *(int *)(&DAT_00ba27b4 + (uint)(byte)local_c8[0] * 8);
    puStack_bc = *(uint **)(&DAT_00ba27b0 + (uint)(byte)local_c8[0] * 8);
  }
  uStack_84 = FUN_00465930((int)local_4c);
  if (0 < (int)uStack_84) {
    do {
      pbVar7 = (byte *)GetListElement(local_4c,&uStack_8e,iVar18);
      uVar17 = (uint)*pbVar7;
      if (uVar17 != uStack_c4) {
        pvVar8 = (void *)GetListElement(local_4c,(undefined2 *)apuStack_8c,iVar18);
        ppuVar9 = FUN_00466480(local_2c,&puStack_ac,pvVar8);
        local_4._0_1_ = 10;
        AppendList(local_2c,ppuVar9);
        local_4 = CONCAT31(local_4._1_3_,5);
        FreeList(&puStack_ac);
        iVar2 = *(int *)(&DAT_00ba27b4 + uVar17 * 8);
        if (((-1 < iVar2) && (iVar16 <= iVar2)) &&
           ((iVar16 < iVar2 || (puStack_bc < *(uint **)(&DAT_00ba27b0 + uVar17 * 8))))) {
          iVar16 = iVar2;
          puStack_bc = *(uint **)(&DAT_00ba27b0 + uVar17 * 8);
        }
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < (int)uStack_84);
  }
  if (DAT_00baed32 == '\0') {
    iVar18 = _rand();
    uVar17 = iVar18 / 0x17 & 0x80000007;
    if ((int)uVar17 < 0) {
      uVar17 = (uVar17 - 1 | 0xfffffff8) + 1;
    }
    uVar19 = (uVar17 - _DAT_00ba2880) + param_3;
    puVar20 = (uint *)(uVar19 + 5);
    pvVar8 = (void *)(((((int)uVar17 >> 0x1f) - _DAT_00ba2884) - (uint)(uVar17 < _DAT_00ba2880)) +
                      param_4 + (uint)CARRY4(uVar17 - _DAT_00ba2880,param_3) +
                     (uint)(0xfffffffa < uVar19));
    if (((int)pvVar8 <= iVar16) && (((int)pvVar8 < iVar16 || (puVar20 < puStack_bc)))) {
      puVar20 = (uint *)((int)puStack_bc + 2);
      pvVar8 = (void *)(iVar16 + (uint)((uint *)0xfffffffd < puStack_bc));
    }
    if (0 < DAT_00624ef4) {
      puVar10 = (uint *)(DAT_00624ef4 - 0x14);
      pvVar15 = (void *)((int)puVar10 >> 0x1f);
      if (((int)pvVar15 <= (int)pvVar8) && (((int)pvVar15 < (int)pvVar8 || (puVar10 < puVar20)))) {
        pvVar8 = pvVar15;
        puVar20 = puVar10;
      }
    }
  }
  else {
    puVar20 = (uint *)(param_3 - _DAT_00ba2880);
    pvVar8 = (void *)((param_4 - _DAT_00ba2884) - (uint)(param_3 < _DAT_00ba2880));
  }
  apuStack_8c[0] = puVar20 + 0x9c4;
  if (HUH == param_2) {
    FUN_0040d4d0(local_6c,param_1);
    SendAllyPressByPower((byte)local_c8[0]);
    goto LAB_00421ebc;
  }
  puStack_ac = puVar20;
  pvStack_a8 = pvVar8;
  if ((REJ == param_2) && (uStack_84 == 1)) {
    uVar17 = (uint)(byte)local_c8[0];
    if (((&DAT_004cf568)[uVar17 * 2] != 1) || ((&DAT_004cf56c)[uVar17 * 2] != 0)) goto LAB_00421d01;
    iVar18 = uVar17 * 0x15 + uStack_c4;
    if ((((int)(&g_AllyTrustScore_Hi)[iVar18 * 2] < 0) ||
        ((((int)(&g_AllyTrustScore_Hi)[iVar18 * 2] < 1 && ((&g_AllyTrustScore)[iVar18 * 2] == 0)) ||
         ((int)(&DAT_00634e90)[uStack_c4 * 0x15 + uVar17] < 0)))) &&
       ((iVar18 = _rand(), (iVar18 / 0x17) % 0x14 + DAT_004c6bd4 < 0x51 &&
        ((DAT_00baed68 != '\x01' || (iVar18 = RandUpTo(n)(0x14), iVar18 + DAT_004c6bd4 < 0x47))))))
    goto LAB_00421d01;
    ppuVar9 = FUN_00466f80(&YES,&local_6c,local_3c);
    local_4._0_1_ = 0xb;
    ppuVar11 = FUN_00466f80(&SND,&puStack_bc,(void **)&DAT_00bc1e0c);
    local_4._0_1_ = 0xc;
    ppuVar11 = FUN_00466e10(ppuVar11,apuStack_7c,local_c8);
    local_4._0_1_ = 0xd;
    ppuVar9 = FUN_00466c40(ppuVar11,&puStack_ac,ppuVar9);
    local_4._0_1_ = 0xe;
    AppendList(local_5c,ppuVar9);
    local_4._0_1_ = 0xd;
    FreeList(&puStack_ac);
    local_4._0_1_ = 0xc;
    FreeList(apuStack_7c);
    local_4._0_1_ = 0xb;
    FreeList(&puStack_bc);
    local_4._0_1_ = 5;
    FreeList(&local_6c);
    FUN_00465f60(apvStack_a4,local_5c);
    local_4._0_1_ = 0xf;
    FUN_00419c30(&DAT_00bb65bc,apuStack_7c,(uint *)&puStack_ac);
    local_4._0_1_ = 5;
    FreeList(apvStack_a4);
    (&DAT_00633768)[(byte)local_c8[0]] = 1;
    FUN_0046b050(local_5c,&puStack_ac);
    local_4._0_1_ = 0x10;
    SEND_LOG(&iStack_c0,(wchar_t *)"We are DECEITFULLY responding to: (%s)");
    local_4._0_1_ = 5;
    if (0xf < uStack_94) {
      _free(pvStack_a8);
    }
    puStack_bc = apuStack_8c[0];
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)(iStack_c0 + -0x10));
    pCStack_b8 = pCVar12 + 0x10;
    local_4._0_1_ = 0x11;
    BuildAllianceMsg(&DAT_00bbf638,apuStack_7c,(int *)&puStack_bc);
    pCVar1 = pCVar12 + 0xc;
    LOCK();
    iVar18 = *(int *)pCVar1;
    *(int *)pCVar1 = *(int *)pCVar1 + -1;
    UNLOCK();
  }
  else {
LAB_00421d01:
    ppuVar9 = FUN_00466f80(&param_2,&local_6c,local_3c);
    local_4._0_1_ = 0x12;
    ppuVar11 = FUN_00466f80(&SND,&puStack_bc,(void **)&DAT_00bc1e0c);
    local_4._0_1_ = 0x13;
    ppuVar11 = FUN_00466c40(ppuVar11,apuStack_7c,local_2c);
    local_4._0_1_ = 0x14;
    ppuVar9 = FUN_00466c40(ppuVar11,&puStack_ac,ppuVar9);
    local_4._0_1_ = 0x15;
    AppendList(local_5c,ppuVar9);
    local_4._0_1_ = 0x14;
    FreeList(&puStack_ac);
    local_4._0_1_ = 0x13;
    FreeList(apuStack_7c);
    local_4._0_1_ = 0x12;
    FreeList(&puStack_bc);
    local_4._0_1_ = 5;
    FreeList(&local_6c);
    FUN_00465f60(apvStack_a4,local_5c);
    local_4._0_1_ = 0x16;
    FUN_00419c30(&DAT_00bb65bc,apuStack_7c,(uint *)&puStack_ac);
    local_4._0_1_ = 5;
    FreeList(apvStack_a4);
    FUN_0046b050(local_5c,&puStack_ac);
    local_4._0_1_ = 0x17;
    SEND_LOG(&iStack_c0,(wchar_t *)"Our response to a message was: %s");
    local_4._0_1_ = 5;
    if (0xf < uStack_94) {
      _free(pvStack_a8);
    }
    puStack_bc = apuStack_8c[0];
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)(iStack_c0 + -0x10));
    pCStack_b8 = pCVar12 + 0x10;
    local_4._0_1_ = 0x18;
    BuildAllianceMsg(&DAT_00bbf638,apuStack_7c,(int *)&puStack_bc);
    pCVar1 = pCVar12 + 0xc;
    LOCK();
    iVar18 = *(int *)pCVar1;
    *(int *)pCVar1 = *(int *)pCVar1 + -1;
    UNLOCK();
  }
  local_4 = CONCAT31(local_4._1_3_,5);
  if (iVar18 + -1 < 1) {
    (**(code **)(**(int **)pCVar12 + 4))(pCVar12);
  }
LAB_00421ebc:
  pCStack_b8 = (CStringData *)*DAT_00bb65cc;
  puStack_bc = (uint *)&DAT_00bb65c8;
  while( true ) {
    pCVar1 = pCStack_b8;
    puVar20 = puStack_bc;
    puVar13 = DAT_00bb65cc;
    if ((puStack_bc == (uint *)0x0) || (puStack_bc != (uint *)&DAT_00bb65c8)) {
      FUN_0047a948();
    }
    if (pCVar1 == (CStringData *)puVar13) break;
    if (puVar20 == (uint *)0x0) {
      FUN_0047a948();
    }
    if (pCVar1 == (CStringData *)puVar20[1]) {
      FUN_0047a948();
    }
    bVar3 = FUN_00465d90((undefined4 *)((int)pCVar1 + 0x10),(int *)local_3c);
    if (bVar3) {
      if (pCVar1 == (CStringData *)puVar20[1]) {
        FUN_0047a948();
      }
      iStack_68 = *(int *)((int)pCVar1 + 0x34);
      if (pCVar1 == (CStringData *)puVar20[1]) {
        FUN_0047a948();
      }
      puVar13 = (undefined4 *)
                GameBoard_GetPowerRec
                          ((undefined4 *)((int)pCVar1 + 0x30),(int *)apuStack_8c,(int *)&uStack_c4);
      if (((undefined4 *)*puVar13 == (undefined4 *)0x0) ||
         ((undefined4 *)*puVar13 != (undefined4 *)((int)pCVar1 + 0x30))) {
        FUN_0047a948();
      }
      if ((puVar13[1] != iStack_68) &&
         ((YES != param_2 || ((&DAT_00633768)[(byte)local_c8[0]] == '\x01')))) {
        if (pCVar1 == (CStringData *)puVar20[1]) {
          FUN_0047a948();
        }
        iStack_80 = *(int *)((int)pCVar1 + 0x4c);
        puVar13 = (undefined4 *)((int)pCVar1 + 0x48);
        if (pCVar1 == (CStringData *)puVar20[1]) {
          FUN_0047a948();
        }
        puVar14 = (undefined4 *)GameBoard_GetPowerRec(puVar13,(int *)apuStack_7c,(int *)&uStack_c4);
        if (((undefined4 *)*puVar14 == (undefined4 *)0x0) || ((undefined4 *)*puVar14 != puVar13)) {
          FUN_0047a948();
        }
        if (puVar14[1] == iStack_80) {
          if (pCVar1 == (CStringData *)puVar20[1]) {
            FUN_0047a948();
          }
          StdMap_FindOrInsert(puVar13,&puStack_ac,(int *)&uStack_c4);
        }
      }
    }
    FUN_0040f860((int *)&puStack_bc);
  }
  local_4._0_1_ = 4;
  piVar4 = (int *)(iStack_c0 + -4);
  LOCK();
  iVar18 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar18 == 1 || iVar18 + -1 < 0) {
    (**(code **)(**(int **)(iStack_c0 + -0x10) + 4))((undefined4 *)(iStack_c0 + -0x10));
  }
  local_4._0_1_ = 3;
  FreeList(local_2c);
  local_4._0_1_ = 2;
  FreeList(local_4c);
  local_4._0_1_ = 1;
  FreeList(local_5c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_1c);
  local_4 = 0xffffffff;
  FreeList(local_3c);
  ExceptionList = local_c;
  return;
}

