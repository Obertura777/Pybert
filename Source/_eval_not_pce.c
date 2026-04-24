
undefined2 * __thiscall _eval_not_pce(void *this,undefined2 *param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  char *pcVar7;
  undefined2 uVar8;
  int iVar9;
  char in_stack_00000018;
  undefined1 in_stack_ffffffc8;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00494850;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar1 = *(char *)(*(int *)((int)this + 8) + 0x2424);
  bVar2 = false;
  local_4 = 1;
  *param_1 = 0;
  bVar3 = false;
  bVar4 = true;
  uVar6 = FUN_00465930((int)&stack0x00000008);
  if ((int)uVar6 < 3) {
    local_10 = &stack0xffffffc8;
    FUN_00465f60(&stack0xffffffc8,(void **)&stack0x00000008);
    cVar5 = FUN_0040d0a0(in_stack_ffffffc8);
    if (cVar5 == '\x01') goto LAB_0040d38d;
  }
  else {
LAB_0040d38d:
    bVar4 = false;
  }
  iVar9 = 0;
  uVar8 = YES;
  if (0 < (int)uVar6) {
    do {
      pcVar7 = (char *)GetListElement(&stack0x00000008,(undefined2 *)&local_10,iVar9);
      if (*pcVar7 == cVar1) {
        bVar2 = true;
      }
      else if (*pcVar7 == in_stack_00000018) {
        bVar3 = true;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)uVar6);
    uVar8 = YES;
    if ((bVar2) && (uVar8 = BWX, bVar3)) {
      if (bVar4) {
        *param_1 = YES;
      }
      else {
        *param_1 = REJ;
      }
      goto LAB_0040d40f;
    }
  }
  *param_1 = uVar8;
LAB_0040d40f:
  local_4 = local_4 & 0xffffff00;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

