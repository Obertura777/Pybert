
undefined2 * _eval_sub_xdo(undefined2 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00494878;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  *param_1 = REJ;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

