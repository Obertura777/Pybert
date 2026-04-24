
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall PROPOSE(void *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint *puVar6;
  bool bVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  void **ppvVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  uint **ppuVar14;
  rsize_t _DstSize;
  int iVar15;
  __time64_t _Var16;
  uint uStack_100;
  undefined *puStack_fc;
  undefined4 *puStack_f8;
  void *pvStack_f4;
  uint *puStack_f0;
  int *piStack_ec;
  uint uStack_e0;
  undefined1 auStack_dc [8];
  undefined8 uStack_d4;
  uint uStack_cc;
  int *piStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_c0 [4];
  int iStack_bc;
  undefined4 uStack_b8;
  int iStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a8 [12];
  void *local_9c;
  uint *puStack_98;
  void *pvStack_94;
  uint uStack_80;
  uint *puStack_7c;
  int iStack_78;
  void *local_6c [4];
  void *apvStack_5c [4];
  undefined1 auStack_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00496f22;
  local_c = ExceptionList;
  uVar8 = DAT_004c8db8 ^ (uint)&stack0xfffffef0;
  ExceptionList = &local_c;
  local_4 = 1;
  local_9c = param_1;
  FUN_00465870(local_6c);
  local_4 = CONCAT31(local_4._1_3_,2);
  piVar9 = FUN_0047020b();
  iVar15 = 0;
  if (piVar9 == (int *)0x0) {
    piVar9 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar10 = (**(code **)(*piVar9 + 0xc))(uVar8);
  pvStack_f4 = (void *)(iVar10 + 0x10);
  local_4._0_1_ = 3;
  FUN_004243a0((int)auStack_dc);
  uStack_100 = (uint)*(byte *)(*(int *)((int)param_1 + 8) + 0x2424);
  local_4._0_1_ = 4;
  uVar8 = FUN_00465930((int)&stack0x00000014);
  auStack_dc[0] = 0;
  uStack_e0 = uVar8;
  FUN_00401950(*(int **)(iStack_bc + 4));
  *(int *)(iStack_bc + 4) = iStack_bc;
  uStack_b8 = 0;
  *(int *)iStack_bc = iStack_bc;
  *(int *)(iStack_bc + 8) = iStack_bc;
  FUN_00401950((int *)piStack_c8[1]);
  piStack_c8[1] = (int)piStack_c8;
  uStack_c4 = 0;
  *piStack_c8 = (int)piStack_c8;
  piStack_c8[2] = (int)piStack_c8;
  FUN_00401950(*(int **)(iStack_b0 + 4));
  *(int *)(iStack_b0 + 4) = iStack_b0;
  uStack_ac = 0;
  *(int *)iStack_b0 = iStack_b0;
  *(int *)(iStack_b0 + 8) = iStack_b0;
  StdMap_FindOrInsert(&uStack_cc,&puStack_98,(int *)&uStack_100);
  StdMap_FindOrInsert(auStack_c0,&puStack_98,(int *)&uStack_100);
  ppvVar11 = (void **)GetSubList(&stack0x00000004,&puStack_7c,1);
  local_4._0_1_ = 5;
  FUN_00419300(auStack_a8,&puStack_98,ppvVar11);
  local_4._0_1_ = 4;
  FreeList(&puStack_7c);
  if (0 < (int)uVar8) {
    do {
      pbVar12 = (byte *)GetListElement(&stack0x00000014,(undefined2 *)&uStack_100,iVar15);
      puStack_fc = (undefined *)(uint)*pbVar12;
      StdMap_FindOrInsert(&uStack_cc,&puStack_98,(int *)&puStack_fc);
      iVar15 = iVar15 + 1;
    } while (iVar15 < (int)uVar8);
  }
  puStack_f8 = (undefined4 *)*DAT_00bb65cc;
  uStack_100 = uStack_100 & 0xffffff00;
  puStack_fc = &DAT_00bb65c8;
  while( true ) {
    puVar4 = puStack_f8;
    puVar3 = puStack_fc;
    puVar13 = DAT_00bb65cc;
    if ((puStack_fc == (undefined *)0x0) || (puStack_fc != &DAT_00bb65c8)) {
      FUN_0047a948();
    }
    if (puVar4 == puVar13) break;
    if (puVar3 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
      FUN_0047a948();
    }
    bVar7 = FUN_00465d90(puVar4 + 4,(int *)&stack0x00000004);
    if (bVar7) {
      if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(puVar4 + 8) == '\0') {
        piStack_ec = (int *)*piStack_c8;
        puStack_f0 = &uStack_cc;
        uStack_100 = CONCAT31(uStack_100._1_3_,1);
        while( true ) {
          piVar1 = piStack_c8;
          piVar9 = piStack_ec;
          puVar6 = puStack_f0;
          if ((puStack_f0 == (uint *)0x0) || (puStack_f0 != &uStack_cc)) {
            FUN_0047a948();
          }
          uVar8 = uStack_e0;
          if (piVar9 == piVar1) break;
          if (puVar4 == *(undefined4 **)(puStack_fc + 4)) {
            FUN_0047a948();
          }
          iStack_78 = puVar4[0xd];
          if (puVar6 == (uint *)0x0) {
            FUN_0047a948();
          }
          if (piVar9 == (int *)puVar6[1]) {
            FUN_0047a948();
          }
          if (puVar4 == *(undefined4 **)(puStack_fc + 4)) {
            FUN_0047a948();
          }
          puVar13 = (undefined4 *)GameBoard_GetPowerRec(puVar4 + 0xc,(int *)&puStack_98,piVar9 + 3);
          if (((undefined4 *)*puVar13 == (undefined4 *)0x0) ||
             ((undefined4 *)*puVar13 != puVar4 + 0xc)) {
            FUN_0047a948();
          }
          if (puVar13[1] == iStack_78) {
            uStack_100 = uStack_100 & 0xffffff00;
          }
          TreeIterator_Advance((int *)&puStack_f0);
        }
      }
    }
    if ((char)uStack_100 == '\x01') break;
    FUN_0040f860((int *)&puStack_fc);
  }
  if ((char)uStack_100 == '\0') {
    ppuVar14 = FUN_00466f80(&SND,&puStack_f0,(void **)&DAT_00bc1e0c);
    local_4._0_1_ = 6;
    ppuVar14 = FUN_00466c40(ppuVar14,&puStack_7c,(void **)&stack0x00000014);
    local_4._0_1_ = 7;
    ppuVar14 = FUN_00466c40(ppuVar14,&puStack_98,(void **)&stack0x00000004);
    local_4._0_1_ = 8;
    AppendList(local_6c,ppuVar14);
    local_4._0_1_ = 7;
    FreeList(&puStack_98);
    local_4._0_1_ = 6;
    FreeList(&puStack_7c);
    local_4 = CONCAT31(local_4._1_3_,4);
    FreeList(&puStack_f0);
    _Var16 = __time64((__time64_t *)0x0);
    lVar2 = _Var16 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
    iVar15 = 0;
    if (0 < (int)uVar8) {
      do {
        DAT_00ba285c = (undefined4)((ulonglong)lVar2 >> 0x20);
        DAT_00ba2858 = (undefined4)lVar2;
        GetListElement(&stack0x00000014,(undefined2 *)&uStack_100,iVar15);
        lVar2 = CONCAT44(DAT_00ba285c,DAT_00ba2858);
        iVar15 = iVar15 + 1;
      } while (iVar15 < (int)uVar8);
    }
    DAT_00ba285c = (undefined4)((ulonglong)lVar2 >> 0x20);
    DAT_00ba2858 = (undefined4)lVar2;
    _Var16 = __time64((__time64_t *)0x0);
    uStack_d4 = _Var16 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
    FUN_00465f60(apvStack_5c,(void **)&stack0x00000004);
    local_4._0_1_ = 9;
    FUN_004223c0(auStack_4c,auStack_dc);
    local_4._0_1_ = 10;
    FUN_00430370(&DAT_00bb65c8,&puStack_98,apvStack_5c);
    local_4._0_1_ = 0xb;
    FUN_00421400((int)auStack_4c);
    local_4._0_1_ = 4;
    FreeList(apvStack_5c);
    pvVar5 = local_9c;
    CancelPriorPress(local_9c);
    SendDM(pvVar5,local_6c);
    _Var16 = __time64((__time64_t *)0x0);
    pvStack_94 = (void *)((ulonglong)_Var16 >> 0x20);
    iVar15 = (int)_Var16 - _DAT_00ba2880;
    FUN_0046b050(local_6c,&puStack_98);
    local_4._0_1_ = 0xc;
    SEND_LOG(&pvStack_f4,(wchar_t *)"We are proposing: %s");
    local_4 = CONCAT31(local_4._1_3_,4);
    if (0xf < uStack_80) {
      _free(pvStack_94);
    }
    pvVar5 = pvStack_f4;
    piVar9 = (int *)((int)pvStack_f4 + -0x10);
    puStack_f0 = (uint *)(iVar15 + 10000);
    puVar13 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_f4 + -0x10) + 0x10))();
    if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar13 != (undefined4 *)*piVar9)) {
      piVar9 = (int *)(**(code **)*puVar13)(*(undefined4 *)((int)pvVar5 + -0xc),1);
      if (piVar9 == (int *)0x0) {
        ErrorExit();
      }
      piVar9[1] = *(int *)((int)pvVar5 + -0xc);
      _DstSize = *(int *)((int)pvVar5 + -0xc) + 1;
      _memcpy_s(piVar9 + 4,_DstSize,pvVar5,_DstSize);
    }
    else {
      LOCK();
      *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
      UNLOCK();
    }
    piStack_ec = piVar9 + 4;
    local_4._0_1_ = 0xd;
    BuildAllianceMsg(&DAT_00bbf638,&puStack_98,(int *)&puStack_f0);
    local_4._0_1_ = 4;
    piVar1 = piVar9 + 3;
    LOCK();
    iVar15 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar15 == 1 || iVar15 + -1 < 0) {
      (**(code **)(*(int *)*piVar9 + 4))(piVar9);
    }
  }
  local_4._0_1_ = 3;
  FUN_00421400((int)auStack_dc);
  local_4._0_1_ = 2;
  piVar9 = (int *)((int)pvStack_f4 + -4);
  LOCK();
  iVar15 = *piVar9;
  *piVar9 = *piVar9 + -1;
  UNLOCK();
  if (iVar15 == 1 || iVar15 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_f4 + -0x10) + 4))((undefined4 *)((int)pvStack_f4 + -0x10));
  }
  local_4._0_1_ = 1;
  FreeList(local_6c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000004);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000014);
  ExceptionList = local_c;
  return;
}

