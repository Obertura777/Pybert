
short * __thiscall EvaluatePress(void *this,short *param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void **ppvVar4;
  short *psVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  undefined1 auStack_bc [12];
  undefined4 uStack_b0;
  undefined1 auStack_a8 [4];
  undefined4 uStack_a4;
  int local_80;
  undefined2 uStack_7a;
  int iStack_78;
  undefined1 *puStack_74;
  undefined1 *puStack_70;
  void *local_6c [4];
  undefined1 *puStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  int iStack_50;
  void *apvStack_4c [4];
  void *local_3c [4];
  void *apvStack_2c [4];
  void *apvStack_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00496cc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  *param_1 = 0;
  FUN_00465870(local_6c);
  local_4._0_1_ = 2;
  FUN_00465870(local_3c);
  local_4 = CONCAT31(local_4._1_3_,3);
  piVar3 = FUN_0047020b();
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_50 = (**(code **)(*piVar3 + 0xc))();
  iStack_50 = iStack_50 + 0x10;
  local_4._0_1_ = 4;
  FUN_00410cf0(*(int **)(DAT_00bb65d8 + 4));
  *(int *)(DAT_00bb65d8 + 4) = DAT_00bb65d8;
  DAT_00bb65dc = 0;
  *(int *)DAT_00bb65d8 = DAT_00bb65d8;
  *(int *)(DAT_00bb65d8 + 8) = DAT_00bb65d8;
  uStack_a4 = 0x42fd21;
  ppvVar4 = (void **)GetSubList(&stack0x00000008,apvStack_4c,1);
  local_4._0_1_ = 5;
  AppendList(&stack0x00000008,ppvVar4);
  local_4._0_1_ = 4;
  FreeList(apvStack_4c);
  uStack_a4 = 0x42fd58;
  psVar5 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&puStack_74,0);
  if (AND == *psVar5) {
    local_80 = 0;
    bVar10 = true;
    uVar6 = FUN_00465930((int)&stack0x00000008);
    iStack_78 = uVar6 - 1;
    iVar8 = 0;
    if (0 < iStack_78) {
      do {
        iVar8 = iVar8 + 1;
        uStack_a4 = 0x42fda8;
        ppvVar4 = (void **)GetSubList(&stack0x00000008,apvStack_4c,iVar8);
        local_4._0_1_ = 6;
        AppendList(local_6c,ppvVar4);
        local_4._0_1_ = 4;
        FreeList(apvStack_4c);
        uStack_a4 = 0x42fdda;
        psVar5 = (short *)GetListElement(local_6c,(undefined2 *)&puStack_74,0);
        if (NOT == *psVar5) {
          uStack_a4 = 0x42fdfb;
          ppvVar4 = (void **)GetSubList(local_6c,apvStack_2c,1);
          local_4._0_1_ = 7;
          AppendList(local_6c,ppvVar4);
          local_4._0_1_ = 4;
          FreeList(apvStack_2c);
        }
        uStack_a4 = 0x42fe2d;
        psVar5 = (short *)GetListElement(local_6c,&uStack_7a,0);
        if (XDO == *psVar5) {
          local_80 = local_80 + 1;
        }
      } while (iVar8 < iStack_78);
      if (1 < local_80) {
        puStack_70 = auStack_a8;
        uStack_b0 = 0x42fe6c;
        FUN_00465f60(auStack_a8,(void **)&stack0x0000001c);
        puStack_5c = &stack0xffffff54;
        puStack_74 = auStack_bc;
        local_4._0_1_ = 9;
        FUN_00465f60(auStack_bc,(void **)&stack0x00000008);
        local_4._0_1_ = 4;
        psVar5 = CAL_VALUE(this,&uStack_7a);
        bVar9 = YES != *psVar5;
        *param_1 = *psVar5;
        if (bVar9) {
          bVar10 = false;
        }
      }
    }
    iVar8 = 0;
    if (0 < iStack_78) {
      do {
        iVar8 = iVar8 + 1;
        puStack_74 = (undefined1 *)((uint)puStack_74 & 0xffffff00);
        uStack_a4 = 0x42feea;
        ppvVar4 = (void **)GetSubList(&stack0x00000008,apvStack_4c,iVar8);
        local_4._0_1_ = 10;
        AppendList(local_6c,ppvVar4);
        local_4._0_1_ = 4;
        FreeList(apvStack_4c);
        AppendList(local_3c,local_6c);
        uStack_a4 = 0x42ff2a;
        psVar5 = (short *)GetListElement(local_3c,&uStack_7a,0);
        if (NOT == *psVar5) {
          uStack_a4 = 0x42ff4e;
          ppvVar4 = (void **)GetSubList(local_3c,apvStack_1c,1);
          local_4._0_1_ = 0xb;
          AppendList(local_3c,ppvVar4);
          local_4._0_1_ = 4;
          FreeList(apvStack_1c);
        }
        uStack_a4 = 0x42ff80;
        psVar5 = (short *)GetListElement(local_3c,(undefined2 *)&puStack_5c,0);
        cVar2 = '\x01';
        if (XDO != *psVar5) {
          cVar2 = (char)puStack_74;
        }
        if ((local_80 < 2) || (cVar2 == '\0')) {
          puStack_74 = auStack_a8;
          uStack_b0 = 0x42ffbc;
          FUN_00465f60(auStack_a8,(void **)&stack0x0000001c);
          puStack_58 = &stack0xffffff54;
          puStack_54 = auStack_bc;
          local_4._0_1_ = 0xd;
          FUN_00465f60(auStack_bc,local_6c);
          local_4._0_1_ = 4;
          psVar5 = FUN_0042c040(this,(undefined2 *)&puStack_70);
          *param_1 = *psVar5;
          uStack_a4 = 0x430017;
          FUN_00419300(&DAT_00bb65d4,apvStack_2c,local_6c);
          if (YES != *param_1) {
            bVar10 = false;
          }
        }
      } while (iVar8 < iStack_78);
    }
    iVar8 = DAT_00bb65d8;
    if (!bVar10) {
      piVar3 = *(int **)(DAT_00bb65d8 + 4);
      cVar2 = *(char *)((int)piVar3 + 0x1d);
      *param_1 = REJ;
      while (cVar2 == '\0') {
        FUN_00410cf0((int *)piVar3[2]);
        piVar1 = (int *)*piVar3;
        FreeList((void **)(piVar3 + 3));
        _free(piVar3);
        piVar3 = piVar1;
        iVar8 = DAT_00bb65d8;
        cVar2 = *(char *)((int)piVar1 + 0x1d);
      }
      *(int *)(iVar8 + 4) = iVar8;
      DAT_00bb65dc = 0;
      *(int *)DAT_00bb65d8 = DAT_00bb65d8;
      *(int *)(DAT_00bb65d8 + 8) = DAT_00bb65d8;
      goto LAB_004302d4;
    }
LAB_00430244:
    *param_1 = YES;
  }
  else {
    uStack_a4 = 0x4300ba;
    psVar5 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&puStack_70,0);
    if (ORR != *psVar5) {
      puStack_54 = auStack_a8;
      uStack_b0 = 0x43026a;
      FUN_00465f60(auStack_a8,(void **)&stack0x0000001c);
      puStack_58 = &stack0xffffff54;
      local_4._0_1_ = 0x12;
      FUN_00465f60(auStack_bc,(void **)&stack0x00000008);
      local_4._0_1_ = 4;
      psVar5 = FUN_0042c040(this,(undefined2 *)&puStack_70);
      bVar10 = YES == *psVar5;
      *param_1 = *psVar5;
      if (bVar10) {
        uStack_a4 = 0x4302d4;
        FUN_00419300(&DAT_00bb65d4,apvStack_4c,(void **)&stack0x00000008);
      }
      goto LAB_004302d4;
    }
    bVar10 = false;
    uVar6 = FUN_00465930((int)&stack0x00000008);
    iStack_78 = uVar6 - 1;
    iVar8 = 0;
    if (0 < iStack_78) {
      do {
        iVar8 = iVar8 + 1;
        uStack_a4 = 0x430118;
        ppvVar4 = (void **)GetSubList(&stack0x00000008,apvStack_1c,iVar8);
        local_4._0_1_ = 0xe;
        AppendList(local_6c,ppvVar4);
        local_4._0_1_ = 4;
        FreeList(apvStack_1c);
        puStack_54 = auStack_a8;
        uStack_b0 = 0x430150;
        FUN_00465f60(auStack_a8,(void **)&stack0x0000001c);
        puStack_58 = &stack0xffffff54;
        puStack_5c = auStack_bc;
        local_4._0_1_ = 0x10;
        FUN_00465f60(auStack_bc,local_6c);
        local_4._0_1_ = 4;
        psVar5 = FUN_0042c040(this,(undefined2 *)&puStack_70);
        bVar9 = YES == *psVar5;
        *param_1 = *psVar5;
        if (bVar9) {
          bVar10 = true;
          if (DAT_00bb65dc == 0) {
            ppvVar4 = apvStack_2c;
          }
          else {
            iVar7 = _rand();
            if ((iVar7 / 0x17) % 100 < 0x33) goto LAB_00430222;
            FUN_00410cf0(*(int **)(DAT_00bb65d8 + 4));
            *(int *)(DAT_00bb65d8 + 4) = DAT_00bb65d8;
            DAT_00bb65dc = 0;
            *(int *)DAT_00bb65d8 = DAT_00bb65d8;
            *(int *)(DAT_00bb65d8 + 8) = DAT_00bb65d8;
            ppvVar4 = apvStack_4c;
          }
          uStack_a4 = 0x430222;
          FUN_00419300(&DAT_00bb65d4,ppvVar4,local_6c);
        }
LAB_00430222:
      } while (iVar8 < iStack_78);
      if (bVar10) goto LAB_00430244;
    }
    *param_1 = REJ;
  }
LAB_004302d4:
  local_4._0_1_ = 3;
  piVar3 = (int *)(iStack_50 + -4);
  LOCK();
  iVar8 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar8 == 1 || iVar8 + -1 < 0) {
    (**(code **)(**(int **)(iStack_50 + -0x10) + 4))();
  }
  local_4._0_1_ = 2;
  FreeList(local_3c);
  local_4._0_1_ = 1;
  FreeList(local_6c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

