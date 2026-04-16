
undefined2 * __thiscall _eval_pce(void *this,undefined2 *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  void **ppvVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte in_stack_00000018;
  undefined2 local_1e;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00494818;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar8 = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4 = 1;
  *param_1 = 0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = true;
  ppvVar4 = (void **)GetSubList(&stack0x00000008,local_1c,1);
  local_4._0_1_ = 2;
  AppendList(&stack0x00000008,ppvVar4);
  local_4 = CONCAT31(local_4._1_3_,1);
  FreeList(local_1c);
  uVar5 = FUN_00465930((int)&stack0x00000008);
  iVar9 = 0;
  if (0 < (int)uVar5) {
    do {
      pbVar6 = (byte *)GetListElement(&stack0x00000008,&local_1e,iVar9);
      uVar7 = (uint)*pbVar6;
      if (uVar7 == uVar8) {
        bVar1 = true;
      }
      else {
        if (uVar7 == in_stack_00000018) {
          bVar2 = true;
        }
        if (((uVar5 != 2) || ((&DAT_00633768)[in_stack_00000018] != '\x01')) &&
           ((((&DAT_004cf568)[uVar7 * 2] == 1 && ((&DAT_004cf56c)[uVar7 * 2] == 0)) ||
            ((int)(&DAT_00634e90)[uVar8 * 0x15 + uVar7] < 0)))) {
          bVar3 = false;
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)uVar5);
    if ((bVar1) && (bVar2)) {
      if (bVar3) {
        *param_1 = YES;
      }
      else {
        *param_1 = REJ;
      }
      goto LAB_0040d2d5;
    }
  }
  *param_1 = BWX;
LAB_0040d2d5:
  local_4 = local_4 & 0xffffff00;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

