
undefined2 * __thiscall _eval_single_xdo(void *this,undefined2 *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int *piVar3;
  short *psVar4;
  undefined2 *puVar5;
  void **ppvVar6;
  undefined2 uVar7;
  undefined1 *in_stack_00000018;
  undefined1 auStack_88 [12];
  undefined4 uStack_7c;
  undefined4 uStack_74;
  int iStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  void *local_48 [4];
  void *apvStack_38 [7];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puVar2 = param_1;
  puStack_8 = &LAB_00496950;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  *param_1 = 0;
  FUN_00465870(local_48);
  local_4._0_1_ = 2;
  FUN_00465870(local_1c);
  local_4 = CONCAT31(local_4._1_3_,3);
  piVar3 = FUN_0047020b();
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_54 = (**(code **)(*piVar3 + 0xc))();
  iStack_54 = iStack_54 + 0x10;
  local_4._0_1_ = 4;
  psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
  if (PCE == *psVar4) {
    puStack_50 = (undefined1 *)&uStack_74;
    uStack_7c = 0x42c0fc;
    FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
    puStack_4c = &stack0xffffff88;
    in_stack_00000018 = auStack_88;
    local_4._0_1_ = 6;
    FUN_00465f60(auStack_88,(void **)&stack0x00000008);
    local_4._0_1_ = 4;
    puVar5 = FUN_0040d1a0(this,(undefined2 *)&param_1);
    uVar7 = *puVar5;
  }
  else {
    psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
    if (DMZ == *psVar4) {
      puStack_4c = (undefined1 *)&uStack_74;
      uStack_7c = 0x42c184;
      FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
      puStack_50 = &stack0xffffff88;
      in_stack_00000018 = auStack_88;
      local_4._0_1_ = 8;
      FUN_00465f60(auStack_88,(void **)&stack0x00000008);
      local_4._0_1_ = 4;
      puVar5 = FUN_0041f090(this,(undefined2 *)&param_1);
      uVar7 = *puVar5;
    }
    else {
      psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
      if (ALY == *psVar4) {
        puStack_4c = (undefined1 *)&uStack_74;
        uStack_7c = 0x42c20c;
        FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
        puStack_50 = &stack0xffffff88;
        in_stack_00000018 = auStack_88;
        local_4._0_1_ = 10;
        FUN_00465f60(auStack_88,(void **)&stack0x00000008);
        local_4._0_1_ = 4;
        puVar5 = FUN_0041e2d0(this,(undefined2 *)&param_1);
        uVar7 = *puVar5;
      }
      else {
        psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
        if (XDO == *psVar4) {
          puStack_4c = (undefined1 *)&uStack_74;
          uStack_7c = 0x42c294;
          FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
          local_4._0_1_ = 0xc;
          ppvVar6 = (void **)&stack0x00000008;
LAB_0042c2b2:
          puStack_50 = &stack0xffffff88;
          in_stack_00000018 = auStack_88;
          FUN_00465f60(auStack_88,ppvVar6);
          local_4._0_1_ = 4;
          puVar5 = CAL_VALUE(this,(undefined2 *)&param_1);
          uVar7 = *puVar5;
        }
        else {
          psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
          if (SLO == *psVar4) {
            puStack_4c = (undefined1 *)&uStack_74;
            uStack_7c = 0x42c319;
            FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
            puStack_50 = &stack0xffffff88;
            in_stack_00000018 = auStack_88;
            local_4._0_1_ = 0xe;
            FUN_00465f60(auStack_88,(void **)&stack0x00000008);
            local_4._0_1_ = 4;
            puVar5 = FUN_0041ea20(this,(undefined2 *)&param_1);
            uVar7 = *puVar5;
          }
          else {
            psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
            if (DRW == *psVar4) {
              puStack_4c = (undefined1 *)&uStack_74;
              uStack_7c = 0x42c3a1;
              FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
              puStack_50 = &stack0xffffff88;
              in_stack_00000018 = auStack_88;
              local_4._0_1_ = 0x10;
              FUN_00465f60(auStack_88,(void **)&stack0x00000008);
              local_4._0_1_ = 4;
              puVar5 = FUN_0041ed30(this,(undefined2 *)&param_1);
              uVar7 = *puVar5;
            }
            else {
              psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
              if (NOT == *psVar4) {
                AppendList(local_48,(void **)&stack0x00000008);
                ppvVar6 = (void **)GetSubList(&stack0x00000008,apvStack_38,1);
                local_4._0_1_ = 0x11;
                AppendList(&stack0x00000008,ppvVar6);
                local_4._0_1_ = 4;
                FreeList(apvStack_38);
                psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                if (PCE == *psVar4) {
                  ppvVar6 = (void **)GetSubList(&stack0x00000008,apvStack_38,1);
                  local_4._0_1_ = 0x12;
                  AppendList(&stack0x00000008,ppvVar6);
                  local_4._0_1_ = 4;
                  FreeList(apvStack_38);
                  puStack_4c = (undefined1 *)&uStack_74;
                  uStack_7c = 0x42c4b8;
                  FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                  puStack_50 = &stack0xffffff88;
                  in_stack_00000018 = auStack_88;
                  local_4._0_1_ = 0x14;
                  FUN_00465f60(auStack_88,(void **)&stack0x00000008);
                  local_4._0_1_ = 4;
                  puVar5 = FUN_0040d310(this,(undefined2 *)&param_1);
                  uVar7 = *puVar5;
                }
                else {
                  psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                  if (DMZ != *psVar4) {
                    psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                    if (XDO != *psVar4) {
LAB_0042c5e4:
                      *puVar2 = HUH;
                      goto LAB_0042c8e8;
                    }
                    puStack_4c = (undefined1 *)&uStack_74;
                    uStack_7c = 0x42c5c4;
                    FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                    local_4._0_1_ = 0x18;
                    ppvVar6 = local_48;
                    goto LAB_0042c2b2;
                  }
                  puStack_4c = (undefined1 *)&uStack_74;
                  uStack_7c = 0x42c53c;
                  FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                  puStack_50 = &stack0xffffff88;
                  in_stack_00000018 = auStack_88;
                  local_4._0_1_ = 0x16;
                  FUN_00465f60(auStack_88,(void **)&stack0x00000008);
                  local_4._0_1_ = 4;
                  puVar5 = FUN_0041f5a0(this,(undefined2 *)&param_1);
                  uVar7 = *puVar5;
                }
              }
              else {
                psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                uVar7 = HUH;
                if (DAT_004c6e14 == *psVar4) {
                  ppvVar6 = (void **)GetSubList(&stack0x00000008,apvStack_38,1);
                  local_4._0_1_ = 0x19;
                  AppendList(&stack0x00000008,ppvVar6);
                  local_4._0_1_ = 4;
                  FreeList(apvStack_38);
                  FUN_0046b050(&stack0x00000008,apvStack_38);
                  local_4._0_1_ = 0x1a;
                  uStack_74 = 0x42c675;
                  SEND_LOG(&iStack_54,(wchar_t *)"message: %s");
                  local_4._0_1_ = 4;
                  FUN_0045bb70((int)apvStack_38);
                  psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                  if (PCE == *psVar4) {
                    ppvVar6 = (void **)GetSubList(&stack0x00000008,apvStack_38,1);
                    local_4._0_1_ = 0x1b;
                    AppendList(&stack0x00000008,ppvVar6);
                    local_4._0_1_ = 4;
                    FreeList(apvStack_38);
                    puStack_4c = (undefined1 *)&uStack_74;
                    uStack_7c = 0x42c6ec;
                    FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                    puStack_50 = &stack0xffffff88;
                    in_stack_00000018 = auStack_88;
                    local_4._0_1_ = 0x1d;
                    FUN_00465f60(auStack_88,(void **)&stack0x00000008);
                    local_4._0_1_ = 4;
                    puVar5 = FUN_0040d310(this,(undefined2 *)&param_1);
                    uVar7 = *puVar5;
                  }
                  else {
                    psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                    if (DMZ == *psVar4) {
                      puStack_4c = (undefined1 *)&uStack_74;
                      uStack_7c = 0x42c770;
                      FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                      puStack_50 = &stack0xffffff88;
                      in_stack_00000018 = auStack_88;
                      local_4._0_1_ = 0x1f;
                      FUN_00465f60(auStack_88,(void **)&stack0x00000008);
                      local_4._0_1_ = 4;
                      puVar5 = FUN_0041f5a0(this,(undefined2 *)&param_1);
                      uVar7 = *puVar5;
                    }
                    else {
                      psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                      if (XDO != *psVar4) {
                        psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                        if (NOT != *psVar4) {
                          *puVar2 = HUH;
                          goto LAB_0042c8e8;
                        }
                        AppendList(local_48,(void **)&stack0x00000008);
                        psVar4 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&param_1,0);
                        if (XDO != *psVar4) goto LAB_0042c5e4;
                        puStack_4c = (undefined1 *)&uStack_74;
                        uStack_7c = 0x42c8b3;
                        FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                        local_4._0_1_ = 0x23;
                        ppvVar6 = local_48;
                        goto LAB_0042c2b2;
                      }
                      puStack_4c = (undefined1 *)&uStack_74;
                      uStack_7c = 0x42c7f8;
                      FUN_00465f60(&uStack_74,(void **)&stack0x0000001c);
                      puStack_50 = &stack0xffffff88;
                      in_stack_00000018 = auStack_88;
                      local_4._0_1_ = 0x21;
                      FUN_00465f60(auStack_88,(void **)&stack0x00000008);
                      local_4._0_1_ = 4;
                      puVar5 = FUN_0040d450((undefined2 *)&param_1);
                      uVar7 = *puVar5;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *puVar2 = uVar7;
LAB_0042c8e8:
  local_4._0_1_ = 3;
  piVar3 = (int *)(iStack_54 + -4);
  LOCK();
  iVar1 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(**(int **)(iStack_54 + -0x10) + 4))();
  }
  local_4._0_1_ = 2;
  FreeList(local_1c);
  local_4._0_1_ = 1;
  FreeList(local_48);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return puVar2;
}

