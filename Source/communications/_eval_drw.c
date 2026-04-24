
undefined2 * __thiscall _eval_drw(void *this,undefined2 *param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  bool bVar5;
  bool bVar6;
  int *_Memory;
  uint **ppuVar7;
  uint uVar8;
  byte *pbVar9;
  void **ppvVar10;
  int iVar11;
  undefined2 local_66;
  uint local_64;
  void *local_60 [3];
  undefined1 local_54 [4];
  int **local_50;
  undefined4 local_4c;
  undefined1 local_48 [4];
  int **local_44;
  undefined4 local_40;
  uint *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495980;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  *param_1 = 0;
  FUN_00465870(local_1c);
  local_4._0_1_ = 2;
  FUN_00465870(local_2c);
  local_4._0_1_ = 3;
  local_44 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_44 + 0x11) = 1;
  local_44[1] = (int *)local_44;
  *local_44 = (int *)local_44;
  local_44[2] = (int *)local_44;
  local_40 = 0;
  local_4._0_1_ = 4;
  local_50 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_50 + 0x11) = 1;
  local_50[1] = (int *)local_50;
  *local_50 = (int *)local_50;
  local_50[2] = (int *)local_50;
  local_4c = 0;
  bVar1 = *(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 5;
  bVar5 = false;
  bVar6 = false;
  ppuVar7 = FUN_00466480(&stack0x0000001c,local_3c,&stack0x00000018);
  local_4._0_1_ = 6;
  AppendList(local_2c,ppuVar7);
  local_4 = CONCAT31(local_4._1_3_,5);
  FreeList(local_3c);
  uVar8 = FUN_00465930((int)local_2c);
  FUN_00401950(local_50[1]);
  local_50[1] = (int *)local_50;
  local_4c = 0;
  *local_50 = (int *)local_50;
  iVar11 = 0;
  local_50[2] = (int *)local_50;
  if (0 < (int)uVar8) {
    do {
      pbVar9 = (byte *)GetListElement(local_2c,&local_66,iVar11);
      local_64 = (uint)*pbVar9;
      StdMap_FindOrInsert(local_54,local_60,(int *)&local_64);
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)uVar8);
  }
  uVar8 = FUN_00465930((int)&stack0x00000008);
  if (uVar8 == 2) {
    ppvVar10 = (void **)GetSubList(&stack0x00000008,local_3c,1);
    local_4._0_1_ = 7;
    AppendList(local_1c,ppvVar10);
    local_4 = CONCAT31(local_4._1_3_,5);
    FreeList(local_3c);
    local_60[0] = (void *)FUN_00465930((int)local_1c);
    cVar2 = *(char *)((int)local_44[1] + 0x11);
    _Memory = local_44[1];
    while (cVar2 == '\0') {
      FUN_00401950((int *)_Memory[2]);
      piVar4 = (int *)*_Memory;
      _free(_Memory);
      _Memory = piVar4;
      cVar2 = *(char *)((int)piVar4 + 0x11);
    }
    local_44[1] = (int *)local_44;
    local_40 = 0;
    *local_44 = (int *)local_44;
    iVar11 = 0;
    local_44[2] = (int *)local_44;
    if ((int)local_60[0] < 1) goto LAB_0041ef87;
    do {
      pbVar9 = (byte *)GetListElement(local_1c,&local_66,iVar11);
      bVar3 = *pbVar9;
      local_64 = (uint)bVar3;
      StdMap_FindOrInsert(local_48,local_3c,(int *)&local_64);
      if ((uint)bVar3 == (uint)bVar1) {
        bVar5 = true;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)local_60[0]);
    if (!bVar5) goto LAB_0041ef87;
  }
  bVar6 = true;
LAB_0041ef87:
  if ((DAT_00baed5d == '\0') || (!bVar6)) {
    *param_1 = REJ;
  }
  else {
    *param_1 = YES;
  }
  local_4._0_1_ = 4;
  SerializeOrders(local_54,local_60,local_54,(int **)*local_50,local_54,local_50);
  _free(local_50);
  local_50 = (int **)0x0;
  local_4c = 0;
  local_4._0_1_ = 3;
  SerializeOrders(local_48,local_60,local_48,(int **)*local_44,local_48,local_44);
  _free(local_44);
  local_44 = (int **)0x0;
  local_40 = 0;
  local_4._0_1_ = 2;
  FreeList(local_2c);
  local_4._0_1_ = 1;
  FreeList(local_1c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

