
undefined4 ParseOrderToken(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  void *this;
  bool bVar3;
  void **ppvVar4;
  short *psVar5;
  int **this_00;
  uint uVar6;
  byte *pbVar7;
  undefined2 *puVar8;
  byte bVar9;
  int iVar10;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined4 local_48;
  int *local_44;
  short local_40;
  void *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar10 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004992f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_48 = 0xffffffff;
  FUN_00465870(local_2c);
  this = param_2;
  local_4 = 0;
  local_40 = 0;
  ppvVar4 = (void **)GetSubList(param_2,local_3c,0);
  local_4._0_1_ = 1;
  AppendList(local_2c,ppvVar4);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_3c);
  bVar3 = FUN_004658e0((int)local_2c);
  if (bVar3) {
    psVar5 = (short *)FUN_004658f0(local_2c,(undefined2 *)&param_2);
    sVar1 = *psVar5;
    param_2 = (void *)CONCAT22(param_2._2_2_,sVar1);
    if (AMY == sVar1) {
      *(undefined1 *)(param_1 + 4) = 1;
    }
  }
  else {
    puVar8 = (undefined2 *)GetListElement(local_2c,(undefined2 *)&param_2,1);
    param_2 = (void *)CONCAT22(param_2._2_2_,*puVar8);
    param_1._0_2_ = FLT;
    sVar1 = (short)param_1;
  }
  param_1._0_2_ = sVar1;
  this_00 = AdjacencyList_FilterByUnitType((void *)(iVar10 + 8),(ushort *)&param_2);
  if (this_00[2] == (int *)0x0) {
    iVar10 = 1;
    uVar6 = FUN_00465930((int)this);
    if (1 < (int)uVar6) {
      do {
        ppvVar4 = (void **)GetSubList(this,local_1c,iVar10);
        local_4._0_1_ = 2;
        AppendList(local_2c,ppvVar4);
        local_4 = (uint)local_4._1_3_ << 8;
        FreeList(local_1c);
        bVar3 = FUN_004658e0((int)local_2c);
        if (bVar3) {
          pbVar7 = (byte *)FUN_004658f0(local_2c,(undefined2 *)&param_2);
          bVar9 = *pbVar7;
          local_40 = (short)param_1;
        }
        else {
          puVar8 = (undefined2 *)GetListElement(local_2c,&local_4c,0);
          uVar2 = *puVar8;
          psVar5 = (short *)GetListElement(local_2c,&local_4a,1);
          local_40 = *psVar5;
          bVar9 = (byte)uVar2;
        }
        local_44 = (int *)(uint)bVar9;
        FUN_00404e10(this_00,local_3c,&local_44);
        iVar10 = iVar10 + 1;
        uVar6 = FUN_00465930((int)this);
      } while (iVar10 < (int)uVar6);
    }
  }
  else {
    local_48 = 0;
  }
  local_4 = 0xffffffff;
  FreeList(local_2c);
  ExceptionList = local_c;
  return local_48;
}

