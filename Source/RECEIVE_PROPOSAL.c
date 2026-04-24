
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RECEIVE_PROPOSAL(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  void *_Src;
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  rsize_t _DstSize;
  undefined *puVar10;
  __time64_t _Var11;
  byte in_stack_00000014;
  char acStack_102 [2];
  undefined *puStack_100;
  undefined4 *puStack_fc;
  uint uStack_f8;
  undefined1 *puStack_f4;
  int *piStack_f0;
  void *pvStack_ec;
  void *pvStack_e8;
  undefined4 uStack_e4;
  undefined1 auStack_dc [8];
  longlong lStack_d4;
  undefined1 auStack_cc [4];
  int *piStack_c8;
  int iStack_c4;
  undefined1 auStack_c0 [4];
  int iStack_bc;
  undefined4 uStack_b8;
  int iStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a8 [4];
  int **ppiStack_a4;
  void *pvStack_98;
  int iStack_94;
  int *piStack_8c;
  void *local_88 [4];
  undefined1 auStack_78 [4];
  void *pvStack_74;
  uint uStack_60;
  void *apvStack_5c [4];
  undefined1 auStack_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00496fac;
  local_c = ExceptionList;
  uVar5 = DAT_004c8db8 ^ (uint)&stack0xfffffeec;
  ExceptionList = &local_c;
  local_4 = 1;
  FUN_00465870(local_88);
  local_4 = CONCAT31(local_4._1_3_,2);
  piVar6 = FUN_0047020b();
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar7 = (**(code **)(*piVar6 + 0xc))(uVar5);
  pvStack_ec = (void *)(iVar7 + 0x10);
  local_4._0_1_ = 3;
  FUN_004243a0((int)auStack_dc);
  uStack_f8 = (uint)in_stack_00000014;
  local_4 = CONCAT31(local_4._1_3_,4);
  uVar5 = FUN_00465930((int)&stack0x00000018);
  auStack_dc[0] = 0;
  _Var11 = __time64((__time64_t *)0x0);
  lStack_d4 = _Var11 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
  FUN_00401950(*(int **)(iStack_bc + 4));
  *(int *)(iStack_bc + 4) = iStack_bc;
  uStack_b8 = 0;
  *(int *)iStack_bc = iStack_bc;
  *(int *)(iStack_bc + 8) = iStack_bc;
  FUN_00401950((int *)piStack_c8[1]);
  piStack_c8[1] = (int)piStack_c8;
  iStack_c4 = 0;
  *piStack_c8 = (int)piStack_c8;
  piStack_c8[2] = (int)piStack_c8;
  FUN_00401950(*(int **)(iStack_b0 + 4));
  *(int *)(iStack_b0 + 4) = iStack_b0;
  uStack_ac = 0;
  *(int *)iStack_b0 = iStack_b0;
  *(int *)(iStack_b0 + 8) = iStack_b0;
  StdMap_FindOrInsert(auStack_cc,&pvStack_e8,(int *)&uStack_f8);
  StdMap_FindOrInsert(auStack_c0,&pvStack_e8,(int *)&uStack_f8);
  FUN_00419cb0(auStack_a8,&pvStack_98,auStack_a8,(int **)*ppiStack_a4,auStack_a8,ppiStack_a4);
  FUN_00411a80(auStack_a8,0xbb65d4);
  iVar7 = 0;
  if (0 < (int)uVar5) {
    do {
      pbVar8 = (byte *)GetListElement(&stack0x00000018,(undefined2 *)acStack_102,iVar7);
      puStack_100 = (undefined *)(uint)*pbVar8;
      StdMap_FindOrInsert(auStack_cc,&pvStack_e8,(int *)&puStack_100);
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar5);
  }
  puStack_fc = (undefined4 *)*DAT_00bb65cc;
  acStack_102[0] = '\0';
  puStack_100 = &DAT_00bb65c8;
  while( true ) {
    puVar2 = puStack_fc;
    puVar10 = puStack_100;
    puVar9 = DAT_00bb65cc;
    if ((puStack_100 == (undefined *)0x0) || (puStack_100 != &DAT_00bb65c8)) {
      FUN_0047a948();
    }
    if (puVar2 == puVar9) break;
    if (puVar10 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar2 == *(undefined4 **)(puVar10 + 4)) {
      FUN_0047a948();
    }
    bVar4 = FUN_00465d90(puVar2 + 4,(int *)&stack0x00000004);
    if (bVar4) {
      if (puVar2 == *(undefined4 **)(puVar10 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(puVar2 + 8) != '\0') goto LAB_0043232b;
      piStack_f0 = (int *)*piStack_c8;
      puStack_f4 = auStack_cc;
      acStack_102[0] = '\x01';
      while( true ) {
        piVar6 = piStack_f0;
        puVar3 = puStack_f4;
        piStack_8c = piStack_c8;
        if ((puStack_f4 == (undefined1 *)0x0) || (puStack_f4 != auStack_cc)) {
          FUN_0047a948();
        }
        iVar7 = iStack_c4;
        if (piVar6 == piStack_8c) break;
        if (puVar2 == *(undefined4 **)(puVar10 + 4)) {
          FUN_0047a948();
        }
        iStack_94 = puVar2[0xd];
        if (puVar3 == (undefined1 *)0x0) {
          FUN_0047a948();
        }
        if (piVar6 == *(int **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        if (puVar2 == *(undefined4 **)(puStack_100 + 4)) {
          FUN_0047a948();
        }
        puVar9 = (undefined4 *)GameBoard_GetPowerRec(puVar2 + 0xc,(int *)&pvStack_e8,piVar6 + 3);
        if (((undefined4 *)*puVar9 == (undefined4 *)0x0) || ((undefined4 *)*puVar9 != puVar2 + 0xc))
        {
          FUN_0047a948();
        }
        if (puVar9[1] == iStack_94) {
          acStack_102[0] = '\0';
        }
        TreeIterator_Advance((int *)&puStack_f4);
        puVar10 = puStack_100;
      }
      if (puVar2 == *(undefined4 **)(puVar10 + 4)) {
        FUN_0047a948();
      }
      if (iVar7 == puVar2[0xe]) goto LAB_0043232b;
      acStack_102[0] = '\0';
      FUN_0040f860((int *)&puStack_100);
    }
    else {
LAB_0043232b:
      if (acStack_102[0] == '\x01') break;
      FUN_0040f860((int *)&puStack_100);
    }
  }
  if (acStack_102[0] == '\0') {
    FUN_00465f60(apvStack_5c,(void **)&stack0x00000004);
    local_4._0_1_ = 5;
    FUN_004223c0(auStack_4c,auStack_dc);
    local_4._0_1_ = 6;
    FUN_00430370(&DAT_00bb65c8,&pvStack_e8,apvStack_5c);
    local_4._0_1_ = 7;
    FUN_00421400((int)auStack_4c);
    local_4._0_1_ = 4;
    FreeList(apvStack_5c);
    __time64((__time64_t *)0x0);
    _Var11 = __time64((__time64_t *)0x0);
    uStack_e4 = (undefined4)((ulonglong)_Var11 >> 0x20);
    iVar7 = (int)_Var11 - _DAT_00ba2880;
    FUN_0046b050(&stack0x00000004,auStack_78);
    local_4._0_1_ = 8;
    SEND_LOG(&pvStack_ec,(wchar_t *)"We have received the proposal: %s");
    local_4 = CONCAT31(local_4._1_3_,4);
    if (0xf < uStack_60) {
      _free(pvStack_74);
    }
    _Src = pvStack_ec;
    piVar6 = (int *)((int)pvStack_ec + -0x10);
    puStack_f4 = (undefined1 *)(iVar7 + 10000);
    puVar9 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_ec + -0x10) + 0x10))();
    if ((*(int *)((int)_Src + -4) < 0) || (puVar9 != (undefined4 *)*piVar6)) {
      piVar6 = (int *)(**(code **)*puVar9)(*(undefined4 *)((int)_Src + -0xc),1);
      if (piVar6 == (int *)0x0) {
        ErrorExit();
      }
      piVar6[1] = *(int *)((int)_Src + -0xc);
      _DstSize = *(int *)((int)_Src + -0xc) + 1;
      _memcpy_s(piVar6 + 4,_DstSize,_Src,_DstSize);
    }
    else {
      LOCK();
      *(int *)((int)_Src + -4) = *(int *)((int)_Src + -4) + 1;
      UNLOCK();
    }
    piStack_f0 = piVar6 + 4;
    local_4._0_1_ = 9;
    BuildAllianceMsg(&DAT_00bbf638,&pvStack_e8,(int *)&puStack_f4);
    local_4 = CONCAT31(local_4._1_3_,4);
    piVar1 = piVar6 + 3;
    LOCK();
    iVar7 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar7 == 1 || iVar7 + -1 < 0) {
      (**(code **)(*(int *)*piVar6 + 4))(piVar6);
    }
    FUN_00418db0((byte)uStack_f8);
  }
  local_4._0_1_ = 3;
  FUN_00421400((int)auStack_dc);
  local_4._0_1_ = 2;
  piVar6 = (int *)((int)pvStack_ec + -4);
  LOCK();
  iVar7 = *piVar6;
  *piVar6 = *piVar6 + -1;
  UNLOCK();
  if (iVar7 == 1 || iVar7 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_ec + -0x10) + 4))((undefined4 *)((int)pvStack_ec + -0x10));
  }
  local_4._0_1_ = 1;
  FreeList(local_88);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000004);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000018);
  ExceptionList = local_c;
  return;
}

