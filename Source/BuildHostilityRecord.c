
undefined * __thiscall BuildHostilityRecord(void *this,undefined *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00495f4d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined *)this = *param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  FUN_00405090((void *)((int)this + 0xc),(int)(param_1 + 0xc));
  local_4 = 0;
  FUN_0041c3c0((void *)((int)this + 0x18),(int)(param_1 + 0x18));
  local_4._0_1_ = 1;
  FUN_0041c3c0((void *)((int)this + 0x24),(int)(param_1 + 0x24));
  puVar2 = (undefined4 *)(param_1 + 0x30);
  puVar3 = (undefined4 *)((int)this + 0x30);
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  local_4._0_1_ = 2;
  FUN_00465f60((void *)((int)this + 0x88),(void **)(param_1 + 0x88));
  *(undefined *)((int)this + 0x98) = param_1[0x98];
  *(undefined4 *)((int)this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  local_4._0_1_ = 3;
  *(undefined4 *)((int)this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  FUN_00465f60((void *)((int)this + 0xa8),(void **)(param_1 + 0xa8));
  *(undefined2 *)((int)this + 0xb8) = *(undefined2 *)(param_1 + 0xb8);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00465f60((void *)((int)this + 0xbc),(void **)(param_1 + 0xbc));
  ExceptionList = local_c;
  return this;
}

