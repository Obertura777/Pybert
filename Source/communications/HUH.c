
void HUH(void *param_1)

{
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00498568;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0046b050(param_1,local_28);
  local_4 = 0;
  ERR("HUH message received : %s");
  if (0xf < local_10) {
    _free(local_24);
  }
  ExceptionList = local_c;
  return;
}

