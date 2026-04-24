uint ** __thiscall FUN_00466c40(void *this,uint **param_1,void **param_2)

{
  uint uVar1;
  uint **ppuVar2;
  uint *puVar3;
  uint uVar4;
  uint *local_2c [4];
  uint *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;

  puStack_8 = &LAB_00499ddc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = (uint *)0x0;
  param_1[1] = (uint *)0xffffffff;
  param_1[2] = (uint *)0x0;
  param_1[3] = (uint *)0xffffffff;
  local_4 = 0;
  if (*(int *)this == 0) {
    ppuVar2 = FUN_004661a0(param_2,local_2c);
    local_4 = 1;
    AppendList(param_1,ppuVar2);
    local_4 = local_4 & 0xffffff00;
    FreeList(local_2c);
  }
  else if (*param_2 == (void *)0x0) {
    ppuVar2 = FUN_004661a0(param_2,local_1c);
    local_4 = 2;
    ppuVar2 = FUN_00466330(this,local_2c,ppuVar2);
    local_4._0_1_ = 3;
    AppendList(param_1,ppuVar2);
    local_4._0_1_ = 2;
    FreeList(local_2c);
    local_4 = (uint)local_4._1_3_ << 8;
    FreeList(local_1c);
  }
  else {
    uVar1 = *(int *)((int)this + 4) + 3 + (int)param_2[1];
    uVar4 = -(uint)((int)((ulonglong)uVar1 * 2 >> 0x20) != 0) | (uint)((ulonglong)uVar1 * 2);
    puVar3 = operator_new(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
    local_4 = 4;
    if (puVar3 == (uint *)0x0) {
      puVar3 = (uint *)0x0;
    }
    else {
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      `eh_vector_constructor_iterator'(puVar3,2,uVar1,FUN_00401040,ClearConvoyState);
    }
    *param_1 = puVar3;
    _memcpy(puVar3,*(void **)this,*(int *)((int)this + 4) * 2);
    _memcpy((void *)((int)*param_1 + *(int *)((int)this + 4) * 2 + 2),*param_2,(int)param_2[1] * 2);
    *(undefined2 *)((int)*param_1 + *(int *)((int)this + 4) * 2) = DAT_004c79b4;
    *(undefined2 *)((int)*param_1 + (*(int *)((int)this + 4) + (int)param_2[1]) * 2 + 2) =
         DAT_004c79b8;
    *(undefined2 *)((int)*param_1 + (*(int *)((int)this + 4) + (int)param_2[1]) * 2 + 4) =
         DAT_004c7d14;
    param_1[1] = (uint *)(*(int *)((int)this + 4) + 2 + (int)param_2[1]);
    param_1[3] = (uint *)(*(int *)((int)this + 0xc) + 1);
  }
  ExceptionList = local_c;
  return param_1;
}
