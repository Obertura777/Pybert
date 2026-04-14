
undefined4 * __fastcall BaseBot(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  _AFX_AYGSHELL_STATE *p_Var4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00498e07;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = BaseBot::vftable;
  iVar1 = FUN_0040ff10();
  param_1[4] = iVar1;
  *(undefined1 *)(iVar1 + 0xf) = 1;
  *(undefined4 *)(param_1[4] + 4) = param_1[4];
  *(undefined4 *)param_1[4] = param_1[4];
  *(undefined4 *)(param_1[4] + 8) = param_1[4];
  param_1[5] = 0;
  local_4 = 0;
  uVar2 = FUN_0045bac0();
  param_1[7] = uVar2;
  param_1[8] = 0;
  local_4._0_1_ = 1;
  FUN_00465870(param_1 + 0xb);
  local_4._0_1_ = 2;
  uVar2 = FUN_0045baa0();
  param_1[0x11] = uVar2;
  param_1[0x12] = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  piVar3 = FUN_0047020b();
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar1 = (**(code **)(*piVar3 + 0xc))();
  param_1[0x14] = iVar1 + 0x10;
  piVar3 = FUN_0047020b();
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar1 = (**(code **)(*piVar3 + 0xc))();
  param_1[0x19] = iVar1 + 0x10;
  param_1[1] = 0;
  local_4 = CONCAT31(local_4._1_3_,4);
  g_NetworkState = (astruct *)param_1;
  *(undefined1 *)(param_1 + 10) = 0;
  p_Var4 = _AfxAygshellState();
  param_1[2] = p_Var4;
  *(undefined1 *)(param_1 + 0xf) = 0;
  ExceptionList = local_c;
  return param_1;
}

