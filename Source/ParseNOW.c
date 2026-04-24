
int __thiscall ParseNOW(void *this,void *param_1)

{
  bool bVar1;
  void **ppvVar2;
  short *psVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined1 auStack_98 [4];
  undefined4 uStack_94;
  undefined4 *local_74;
  undefined1 *local_70;
  int local_6c;
  int local_68;
  int local_60;
  int local_58;
  int local_54 [2];
  void *local_4c [4];
  void *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004996e0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_70 = (undefined1 *)0xffffffff;
  InitEmptyTokenList(local_2c);
  local_4 = 0;
  InitEmptyTokenList(local_3c);
  local_4._0_1_ = 1;
  InitEmptyTokenList(local_1c);
  local_4._0_1_ = 2;
  if (*(int *)((int)this + 0x2400) != -1) {
    uStack_94 = 0x464038;
    ppvVar2 = (void **)GetSubList(param_1,local_4c,0);
    local_4._0_1_ = 3;
    AppendList(local_2c,ppvVar2);
    local_4._0_1_ = 2;
    FreeList(local_4c);
    bVar1 = FUN_004658e0((int)local_2c);
    if (bVar1) {
      psVar3 = (short *)FUN_004658f0(local_2c,(undefined2 *)&local_74);
      if (DAT_004c7778 == *psVar3) {
        uStack_94 = 0x464099;
        ppvVar2 = (void **)GetSubList(param_1,local_4c,1);
        local_4._0_1_ = 4;
        AppendList(local_3c,ppvVar2);
        local_4._0_1_ = 2;
        FreeList(local_4c);
        uStack_94 = 0x4640cb;
        puVar4 = (undefined2 *)GetListElement(local_3c,(undefined2 *)&local_74,0);
        *(undefined2 *)((int)this + 0x244a) = *puVar4;
        uStack_94 = 0x4640e5;
        puVar5 = (ushort *)GetListElement(local_3c,(undefined2 *)&local_74,1);
        uVar6 = (uint)*puVar5;
        if ((*puVar5 & 0x2000) != 0) {
          uVar6 = uVar6 | 0xffffe000;
        }
        *(uint *)((int)this + 0x244c) = uVar6;
        FUN_00407b00(*(int **)(*(int *)((int)this + 0x2454) + 4));
        *(int *)(*(int *)((int)this + 0x2454) + 4) = *(int *)((int)this + 0x2454);
        *(undefined4 *)((int)this + 0x2458) = 0;
        *(undefined4 *)*(undefined4 *)((int)this + 0x2454) = *(undefined4 *)((int)this + 0x2454);
        *(int *)(*(int *)((int)this + 0x2454) + 8) = *(int *)((int)this + 0x2454);
        FUN_00407b00(*(int **)(*(int *)((int)this + 0x2460) + 4));
        *(int *)(*(int *)((int)this + 0x2460) + 4) = *(int *)((int)this + 0x2460);
        *(undefined4 *)((int)this + 0x2464) = 0;
        *(undefined4 *)*(undefined4 *)((int)this + 0x2460) = *(undefined4 *)((int)this + 0x2460);
        *(int *)(*(int *)((int)this + 0x2460) + 8) = *(int *)((int)this + 0x2460);
        FUN_00401950(*(int **)(*(int *)((int)this + 0x24b8) + 4));
        *(int *)(*(int *)((int)this + 0x24b8) + 4) = *(int *)((int)this + 0x24b8);
        *(undefined4 *)((int)this + 0x24bc) = 0;
        *(undefined4 *)*(undefined4 *)((int)this + 0x24b8) = *(undefined4 *)((int)this + 0x24b8);
        *(int *)(*(int *)((int)this + 0x24b8) + 8) = *(int *)((int)this + 0x24b8);
        FUN_00401950(*(int **)(*(int *)((int)this + 0x24c4) + 4));
        *(int *)(*(int *)((int)this + 0x24c4) + 4) = *(int *)((int)this + 0x24c4);
        *(undefined4 *)((int)this + 0x24c8) = 0;
        *(undefined4 *)*(undefined4 *)((int)this + 0x24c4) = *(undefined4 *)((int)this + 0x24c4);
        *(int *)(*(int *)((int)this + 0x24c4) + 8) = *(int *)((int)this + 0x24c4);
        FUN_00401950(*(int **)(*(int *)((int)this + 0x24d0) + 4));
        *(int *)(*(int *)((int)this + 0x24d0) + 4) = *(int *)((int)this + 0x24d0);
        *(undefined4 *)((int)this + 0x24d4) = 0;
        *(undefined4 *)*(undefined4 *)((int)this + 0x24d0) = *(undefined4 *)((int)this + 0x24d0);
        *(int *)(*(int *)((int)this + 0x24d0) + 8) = *(int *)((int)this + 0x24d0);
        FUN_0040fb70(*(int **)(*(int *)((int)this + 0x2478) + 4));
        *(int *)(*(int *)((int)this + 0x2478) + 4) = *(int *)((int)this + 0x2478);
        *(undefined4 *)((int)this + 0x247c) = 0;
        *(undefined4 *)*(undefined4 *)((int)this + 0x2478) = *(undefined4 *)((int)this + 0x2478);
        *(int *)(*(int *)((int)this + 0x2478) + 8) = *(int *)((int)this + 0x2478);
        *(undefined4 *)((int)this + 0x2480) = 0;
        iVar9 = 2;
        uVar6 = FUN_00465930((int)param_1);
        if (2 < (int)uVar6) {
          do {
            if (local_70 != (undefined1 *)0xffffffff) break;
            uStack_94 = 0x46423d;
            ppvVar2 = (void **)GetSubList(param_1,local_4c,iVar9);
            local_4._0_1_ = 5;
            AppendList(local_1c,ppvVar2);
            local_4._0_1_ = 2;
            FreeList(local_4c);
            local_70 = auStack_98;
            FUN_00465f60(auStack_98,local_1c);
            local_70 = (undefined1 *)ParseNOWUnit(this);
            if (local_70 != (undefined1 *)0xffffffff) {
              iVar7 = FUN_00466110(param_1,iVar9);
              local_70 = (undefined1 *)((int)local_70 + iVar7);
            }
            iVar9 = iVar9 + 1;
            uVar6 = FUN_00465930((int)param_1);
          } while (iVar9 < (int)uVar6);
        }
        if (DAT_004c773c == *(short *)((int)this + 0x244a)) {
          FUN_0040ab10((int)this);
        }
        if (*(short *)((int)this + 0x2424) != 0) {
          FUN_00401950(*(int **)(*(int *)((int)this + 0x24d0) + 4));
          *(int *)(*(int *)((int)this + 0x24d0) + 4) = *(int *)((int)this + 0x24d0);
          *(undefined4 *)((int)this + 0x24d4) = 0;
          *(undefined4 *)*(undefined4 *)((int)this + 0x24d0) = *(undefined4 *)((int)this + 0x24d0);
          local_6c = (int)this + 0x243c;
          *(int *)(*(int *)((int)this + 0x24d0) + 8) = *(int *)((int)this + 0x24d0);
          local_68 = **(int **)((int)this + 0x2440);
          while( true ) {
            iVar9 = local_6c;
            local_60 = *(int *)((int)this + 0x2440);
            if ((local_6c == 0) || (local_6c != (int)this + 0x243c)) {
              AssertFail();
            }
            if (local_68 == local_60) break;
            if (iVar9 == 0) {
              AssertFail();
            }
            if (local_68 == *(int *)(iVar9 + 4)) {
              AssertFail();
            }
            piVar8 = (int *)(local_68 + 0xc);
            if (*(short *)((int)this + 0x2424) ==
                *(short *)((int)this + *(int *)(local_68 + 0xc) * 0x24 + 0x20)) {
              local_58 = *(int *)((int)this + 0x2454);
              if (local_68 == *(int *)(iVar9 + 4)) {
                AssertFail();
              }
              uStack_94 = 0x46439d;
              local_74 = (undefined4 *)
                         OrderedSet_FindOrInsert((void *)((int)this + 0x2450),local_54,piVar8);
              if (((void *)*local_74 == (void *)0x0) ||
                 ((void *)*local_74 != (void *)((int)this + 0x2450))) {
                AssertFail();
              }
              if (local_74[1] == local_58) {
                if (local_68 == *(int *)(iVar9 + 4)) {
                  AssertFail();
                }
                uStack_94 = 0x4643df;
                StdMap_FindOrInsert((void *)((int)this + 0x24cc),local_4c,piVar8);
              }
            }
            TreeIterator_Advance(&local_6c);
          }
          *(int *)((int)this + 0x24e4) = *(int *)((int)this + 0x24bc) - *(int *)((int)this + 0x24e0)
          ;
        }
        goto LAB_00464403;
      }
    }
    local_70 = (undefined1 *)0x0;
  }
LAB_00464403:
  local_4._0_1_ = 1;
  FreeList(local_1c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_3c);
  local_4 = 0xffffffff;
  FreeList(local_2c);
  ExceptionList = local_c;
  return (int)local_70;
}

