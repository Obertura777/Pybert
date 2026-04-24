undefined4 * __thiscall FUN_00463690(void *this,undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int **ppiVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  void *local_1ec [4];
  uint *local_1dc [4];
  uint *local_1cc [4];
  uint *local_1bc [4];
  uint *local_1ac [4];
  uint *local_19c [4];
  uint *local_18c [4];
  uint *local_17c [4];
  uint *local_16c [4];
  uint *local_15c [4];
  uint *local_14c [4];
  uint *local_13c [4];
  uint *local_12c [4];
  uint *local_11c [4];
  uint *local_10c [4];
  uint *local_fc [4];
  uint *local_ec [4];
  uint *local_dc [4];
  uint *local_cc [4];
  uint *local_bc [4];
  uint *local_ac [4];
  uint *local_9c [4];
  uint *local_8c [4];
  uint *local_7c [4];
  uint *local_6c [4];
  uint *local_5c [4];
  uint *local_4c [4];
  uint *local_3c [4];
  uint *local_2c [4];
  uint *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;

  puStack_8 = &LAB_004995f4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  FUN_00465870(param_1);
  local_4 = 0;
  uVar6 = 0x46;
  FUN_00465870(local_1ec);
  local_4 = 1;
  switch(param_2[4]) {
  case 0:
  case 1:
    ppuVar3 = FUN_0045ffa0(this,local_ec,param_2);
    local_4._0_1_ = 2;
    ppuVar3 = FUN_00466480(ppuVar3,local_10c,&HLD);
    local_4._0_1_ = 3;
    AppendList(param_1,ppuVar3);
    local_4 = CONCAT31(local_4._1_3_,2);
    FreeList(local_10c);
    ppuVar3 = local_ec;
    break;
  case 2:
    ppuVar3 = FUN_0045fca0(this,local_cc,param_2[5],CONCAT22(uVar6,(short)param_2[6]));
    local_4._0_1_ = 4;
    ppuVar4 = FUN_0045ffa0(this,local_18c,param_2);
    local_4._0_1_ = 5;
    ppuVar4 = FUN_00466480(ppuVar4,local_4c,&MTO);
    local_4._0_1_ = 6;
    ppuVar3 = FUN_00466330(ppuVar4,local_1ac,ppuVar3);
    local_4._0_1_ = 7;
    AppendList(param_1,ppuVar3);
    local_4._0_1_ = 6;
    FreeList(local_1ac);
    local_4._0_1_ = 5;
    FreeList(local_4c);
    local_4 = CONCAT31(local_4._1_3_,4);
    FreeList(local_18c);
    ppuVar3 = local_cc;
    break;
  case 3:
    ppiVar2 = UnitList_FindOrInsert((void *)((int)this + 0x2450),param_2 + 7);
    ppuVar3 = FUN_0045ffa0(this,local_ac,(int *)ppiVar2);
    local_4._0_1_ = 8;
    ppuVar4 = FUN_0045ffa0(this,local_14c,param_2);
    local_4._0_1_ = 9;
    ppuVar4 = FUN_00466480(ppuVar4,local_6c,&SUP);
    local_4._0_1_ = 10;
    ppuVar3 = FUN_00466330(ppuVar4,local_16c,ppuVar3);
    local_4._0_1_ = 0xb;
    AppendList(param_1,ppuVar3);
    local_4._0_1_ = 10;
    FreeList(local_16c);
    local_4._0_1_ = 9;
    FreeList(local_6c);
    local_4 = CONCAT31(local_4._1_3_,8);
    FreeList(local_14c);
    ppuVar3 = local_ac;
    break;
  case 4:
    ppiVar2 = UnitList_FindOrInsert((void *)((int)this + 0x2450),param_2 + 7);
    ppuVar3 = FUN_0045ffa0(this,local_1bc,(int *)ppiVar2);
    local_4._0_1_ = 0xc;
    ppuVar4 = FUN_0045ffa0(this,local_1cc,param_2);
    local_4._0_1_ = 0xd;
    ppuVar4 = FUN_00466480(ppuVar4,local_8c,&SUP);
    local_4._0_1_ = 0xe;
    ppuVar3 = FUN_00466330(ppuVar4,local_1dc,ppuVar3);
    local_4._0_1_ = 0xf;
    ppuVar3 = FUN_00466480(ppuVar3,local_2c,&MTO);
    local_4._0_1_ = 0x10;
    ppuVar3 = FUN_00466480(ppuVar3,local_12c,(void *)((int)this + param_2[8] * 0x24));
    local_4._0_1_ = 0x11;
    AppendList(param_1,ppuVar3);
    local_4._0_1_ = 0x10;
    FreeList(local_12c);
    local_4._0_1_ = 0xf;
    FreeList(local_2c);
    local_4._0_1_ = 0xe;
    FreeList(local_1dc);
    local_4._0_1_ = 0xd;
    FreeList(local_8c);
    local_4 = CONCAT31(local_4._1_3_,0xc);
    FreeList(local_1cc);
    ppuVar3 = local_1bc;
    break;
  case 5:
    ppiVar2 = UnitList_FindOrInsert((void *)((int)this + 0x2450),param_2 + 7);
    ppuVar3 = FUN_0045ffa0(this,local_fc,(int *)ppiVar2);
    local_4._0_1_ = 0x12;
    ppuVar4 = FUN_0045ffa0(this,local_11c,param_2);
    local_4._0_1_ = 0x13;
    ppuVar4 = FUN_00466480(ppuVar4,local_13c,&CVY);
    local_4._0_1_ = 0x14;
    ppuVar3 = FUN_00466330(ppuVar4,local_15c,ppuVar3);
    local_4._0_1_ = 0x15;
    ppuVar3 = FUN_00466480(ppuVar3,local_17c,&CTO);
    local_4._0_1_ = 0x16;
    ppuVar3 = FUN_00466480(ppuVar3,local_19c,(void *)((int)this + param_2[8] * 0x24));
    local_4._0_1_ = 0x17;
    AppendList(param_1,ppuVar3);
    local_4._0_1_ = 0x16;
    FreeList(local_19c);
    local_4._0_1_ = 0x15;
    FreeList(local_17c);
    local_4._0_1_ = 0x14;
    FreeList(local_15c);
    local_4._0_1_ = 0x13;
    FreeList(local_13c);
    local_4 = CONCAT31(local_4._1_3_,0x12);
    FreeList(local_11c);
    ppuVar3 = local_fc;
    break;
  case 6:
    ppuVar3 = FUN_0045fca0(this,local_7c,param_2[5],CONCAT22(uVar6,(short)param_2[6]));
    local_4._0_1_ = 0x18;
    ppuVar4 = FUN_0045ffa0(this,local_9c,param_2);
    local_4._0_1_ = 0x19;
    ppuVar4 = FUN_00466480(ppuVar4,local_bc,&CTO);
    local_4._0_1_ = 0x1a;
    ppuVar3 = FUN_00466330(ppuVar4,local_dc,ppuVar3);
    local_4._0_1_ = 0x1b;
    AppendList(param_1,ppuVar3);
    local_4._0_1_ = 0x1a;
    FreeList(local_dc);
    local_4._0_1_ = 0x19;
    FreeList(local_bc);
    local_4._0_1_ = 0x18;
    FreeList(local_9c);
    local_4 = CONCAT31(local_4._1_3_,1);
    FreeList(local_7c);
    puVar5 = *(undefined4 **)param_2[10];
    while( true ) {
      puVar1 = (undefined4 *)param_2[10];
      if (param_2 == (int *)0xffffffdc) {
        FUN_0047a948();
      }
      if (puVar5 == puVar1) break;
      if (param_2 == (int *)0xffffffdc) {
        FUN_0047a948();
      }
      if (puVar5 == (undefined4 *)param_2[10]) {
        FUN_0047a948();
      }
      ppuVar3 = FUN_00466480(local_1ec,local_5c,(void *)((int)this + puVar5[2] * 0x24));
      local_4._0_1_ = 0x1c;
      AppendList(local_1ec,ppuVar3);
      local_4 = CONCAT31(local_4._1_3_,1);
      FreeList(local_5c);
      if (puVar5 == (undefined4 *)param_2[10]) {
        FUN_0047a948();
      }
      puVar5 = (undefined4 *)*puVar5;
    }
    ppuVar3 = FUN_00466480(param_1,local_1c,&VIA);
    local_4._0_1_ = 0x1d;
    ppuVar3 = FUN_00466c40(ppuVar3,local_3c,local_1ec);
    local_4._0_1_ = 0x1e;
    AppendList(param_1,ppuVar3);
    local_4 = CONCAT31(local_4._1_3_,0x1d);
    FreeList(local_3c);
    ppuVar3 = local_1c;
    break;
  default:
    goto LAB_00463d02;
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  FreeList(ppuVar3);
LAB_00463d02:
  local_4 = local_4 & 0xffffff00;
  FreeList(local_1ec);
  ExceptionList = local_c;
  return param_1;
}
