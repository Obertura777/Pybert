
void __fastcall CancelPriorPress(void *param_1)

{
  uint **ppuVar1;
  void *local_2c [4];
  uint *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00494980;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00465870(local_2c);
  local_4 = 0;
  if ((DAT_00baed47 == '\0') &&
     ((0 < (int)(&curr_sc_cnt)[*(byte *)(*(int *)((int)param_1 + 8) + 0x2424)] ||
      (*(int *)(*(int *)((int)param_1 + 8) + 0x24bc) != 0)))) {
    ppuVar1 = FUN_00466ed0(&NOT,local_1c,&GOF);
    local_4._0_1_ = 1;
    AppendList(local_2c,ppuVar1);
    local_4 = (uint)local_4._1_3_ << 8;
    FreeList(local_1c);
    SendDM(param_1,local_2c);
    DAT_00baed47 = '\x01';
  }
  local_4 = 0xffffffff;
  FreeList(local_2c);
  ExceptionList = local_c;
  return;
}

