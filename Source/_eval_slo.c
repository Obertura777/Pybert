
undefined2 * __thiscall _eval_slo(void *this,undefined2 *param_1)

{
  byte bVar1;
  bool bVar2;
  uint **ppuVar3;
  void **ppvVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  undefined2 local_66;
  void *local_64;
  uint local_60;
  void *local_5c [2];
  undefined1 local_54 [4];
  int **local_50;
  int local_4c;
  undefined1 local_48 [4];
  int **local_44;
  undefined4 local_40;
  uint *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495920;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  *param_1 = 0;
  FUN_00465870(local_1c);
  local_4._0_1_ = 2;
  FUN_00465870(local_2c);
  local_4._0_1_ = 3;
  local_50 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_50 + 0x11) = 1;
  local_50[1] = (int *)local_50;
  *local_50 = (int *)local_50;
  local_50[2] = (int *)local_50;
  local_4c = 0;
  local_4._0_1_ = 4;
  local_44 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_44 + 0x11) = 1;
  local_44[1] = (int *)local_44;
  *local_44 = (int *)local_44;
  local_44[2] = (int *)local_44;
  local_40 = 0;
  local_5c[0] = (void *)(uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 5;
  bVar2 = false;
  ppuVar3 = FUN_00466480(&stack0x0000001c,local_3c,&stack0x00000018);
  local_4._0_1_ = 6;
  AppendList(local_2c,ppuVar3);
  local_4._0_1_ = 5;
  FreeList(local_3c);
  ppvVar4 = (void **)GetSubList(&stack0x00000008,local_3c,1);
  local_4._0_1_ = 7;
  AppendList(local_1c,ppvVar4);
  local_4 = CONCAT31(local_4._1_3_,5);
  FreeList(local_3c);
  uVar5 = FUN_00465930((int)local_2c);
  local_60 = FUN_00465930((int)local_1c);
  FUN_00401950(local_50[1]);
  local_50[1] = (int *)local_50;
  local_4c = 0;
  *local_50 = (int *)local_50;
  local_50[2] = (int *)local_50;
  FUN_00401950(local_44[1]);
  local_44[1] = (int *)local_44;
  local_40 = 0;
  *local_44 = (int *)local_44;
  iVar7 = 0;
  local_44[2] = (int *)local_44;
  if (0 < (int)uVar5) {
    do {
      pbVar6 = (byte *)GetListElement(local_2c,&local_66,iVar7);
      local_64 = (void *)(uint)*pbVar6;
      StdMap_FindOrInsert(local_48,local_3c,(int *)&local_64);
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar5);
  }
  iVar7 = 0;
  if (0 < (int)local_60) {
    do {
      pbVar6 = (byte *)GetListElement(local_1c,&local_66,iVar7);
      bVar1 = *pbVar6;
      local_64 = (void *)(uint)bVar1;
      StdMap_FindOrInsert(local_54,local_3c,(int *)&local_64);
      if ((void *)(uint)bVar1 == local_5c[0]) {
        bVar2 = true;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)local_60);
  }
  if ((local_4c == 1) && (bVar2)) {
    *param_1 = YES;
  }
  else {
    *param_1 = REJ;
  }
  local_4._0_1_ = 4;
  SerializeOrders(local_48,local_5c,local_48,(int **)*local_44,local_48,local_44);
  _free(local_44);
  local_44 = (int **)0x0;
  local_40 = 0;
  local_4._0_1_ = 3;
  SerializeOrders(local_54,local_5c,local_54,(int **)*local_50,local_54,local_50);
  _free(local_50);
  local_50 = (int **)0x0;
  local_4c = 0;
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

