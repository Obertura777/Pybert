
/* WARNING: Removing unreachable block (ram,0x0042165d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SendAllyPressByPower(byte param_1)

{
  longlong lVar1;
  uint **ppuVar2;
  int iVar3;
  uint uVar4;
  __time64_t _Var5;
  ushort local_48 [2];
  uint *local_44 [4];
  void *local_34 [4];
  longlong local_24;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00495da8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00465870(local_34);
  local_48[0] = param_1 | 0x4100;
  local_4 = 0;
  ppuVar2 = FUN_00466ed0(&THN,local_44,local_48);
  local_4._0_1_ = 1;
  AppendList(local_34,ppuVar2);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_44);
  FUN_00418db0(param_1);
  if (DAT_00baed32 == '\0') {
    _Var5 = __time64((__time64_t *)0x0);
    iVar3 = _rand();
    uVar4 = (iVar3 / 0x17) % 0xf;
    local_24 = _Var5 + CONCAT44((((int)uVar4 >> 0x1f) - _DAT_00ba2884) -
                                (uint)(uVar4 < _DAT_00ba2880),uVar4 - _DAT_00ba2880) + 7;
    if ((DAT_00624ef4 < 1) ||
       (lVar1 = (longlong)(DAT_00624ef4 + -0x14), local_24 <= DAT_00624ef4 + -0x14))
    goto LAB_0042167d;
  }
  else {
    _Var5 = __time64((__time64_t *)0x0);
    lVar1 = _Var5 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
  }
  local_24 = lVar1;
LAB_0042167d:
  FUN_00465f60(local_1c,local_34);
  local_4._0_1_ = 2;
  FUN_00419c30(&DAT_00bb65bc,local_44,(uint *)&local_24);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_1c);
  local_4 = 0xffffffff;
  FreeList(local_34);
  ExceptionList = local_c;
  return;
}

