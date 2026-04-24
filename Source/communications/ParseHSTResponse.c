
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall ParseHSTResponse(void *this,void *param_1)

{
  char cVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  void **ppvVar5;
  short *psVar6;
  ushort *puVar7;
  uint **ppuVar8;
  int iVar9;
  uint uVar10;
  undefined *this_00;
  uint uVar11;
  int iVar12;
  __time64_t _Var13;
  undefined2 uStack_142;
  int iStack_140;
  uint local_13c;
  uint local_138;
  uint *apuStack_134 [4];
  void *local_124;
  uint *apuStack_120 [4];
  int iStack_110;
  uint *apuStack_10c [4];
  uint *apuStack_fc [4];
  uint *apuStack_ec [4];
  uint *apuStack_dc [4];
  uint *apuStack_cc [4];
  uint *apuStack_bc [4];
  uint *apuStack_ac [4];
  uint *apuStack_9c [4];
  uint *apuStack_8c [4];
  void *local_7c [4];
  void *local_6c [4];
  void *local_5c [4];
  uint *apuStack_4c [4];
  uint *apuStack_3c [4];
  uint *apuStack_2c [4];
  void *apvStack_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00495679;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_124 = this;
  FUN_00465870(local_7c);
  local_4 = 0;
  FUN_00465870(local_6c);
  local_4._0_1_ = 1;
  FUN_00465870(local_5c);
  uVar11 = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4 = CONCAT31(local_4._1_3_,2);
  uVar10 = 0;
  local_13c = 0;
  local_138 = uVar11;
  piVar4 = FUN_0047020b();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_110 = (**(code **)(*piVar4 + 0xc))();
  iStack_110 = iStack_110 + 0x10;
  local_4._0_1_ = 3;
  FUN_00465870(apvStack_1c);
  local_4._0_1_ = 4;
  ppvVar5 = (void **)GetSubList(param_1,apuStack_134,3);
  local_4._0_1_ = 5;
  AppendList(local_7c,ppvVar5);
  local_4._0_1_ = 4;
  FreeList(apuStack_134);
  ppvVar5 = (void **)GetSubList(local_7c,apuStack_134,0);
  local_4._0_1_ = 6;
  AppendList(local_6c,ppvVar5);
  local_4._0_1_ = 4;
  FreeList(apuStack_134);
  ppvVar5 = (void **)GetSubList(local_7c,apuStack_134,1);
  local_4._0_1_ = 7;
  AppendList(local_5c,ppvVar5);
  local_4 = CONCAT31(local_4._1_3_,4);
  FreeList(apuStack_134);
  psVar6 = (short *)GetListElement(local_6c,&uStack_142,0);
  if (LVL == *psVar6) {
    puVar7 = (ushort *)GetListElement(local_6c,&uStack_142,1);
    uVar2 = *puVar7;
    iStack_140 = CONCAT22(iStack_140._2_2_,uVar2);
    uVar10 = (uint)uVar2;
    if ((uVar2 & 0x2000) != 0) {
      uVar10 = uVar10 | 0xffffe000;
    }
  }
  g_HistoryCounter = uVar10;
  if (DAT_00baed40 == '\x01') {
    g_HistoryCounter = 0;
  }
  ppuVar8 = FUN_00466540(&YES,apuStack_10c,&REJ);
  local_4._0_1_ = 8;
  ppuVar8 = FUN_00466480(ppuVar8,apuStack_dc,&BWX);
  local_4._0_1_ = 9;
  ppuVar8 = FUN_00466480(ppuVar8,apuStack_fc,&NOT);
  local_4._0_1_ = 10;
  ppuVar8 = FUN_00466480(ppuVar8,apuStack_120,&DAT_004c6e14);
  local_4._0_1_ = 0xb;
  ppuVar8 = FUN_00466480(ppuVar8,apuStack_ec,&SLO);
  local_4._0_1_ = 0xc;
  ppuVar8 = FUN_00466480(ppuVar8,apuStack_134,&DRW);
  local_4._0_1_ = 0xd;
  AppendList(&DAT_00bb6f0c,ppuVar8);
  local_4._0_1_ = 0xc;
  FreeList(apuStack_134);
  local_4._0_1_ = 0xb;
  FreeList(apuStack_ec);
  local_4._0_1_ = 10;
  FreeList(apuStack_120);
  local_4._0_1_ = 9;
  FreeList(apuStack_fc);
  local_4._0_1_ = 8;
  FreeList(apuStack_dc);
  local_4._0_1_ = 4;
  FreeList(apuStack_10c);
  if (9 < (int)g_HistoryCounter) {
    ppuVar8 = FUN_00466540(&YES,apuStack_9c,&REJ);
    local_4._0_1_ = 0xe;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_bc,&BWX);
    local_4._0_1_ = 0xf;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_8c,&NOT);
    local_4._0_1_ = 0x10;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_ac,&DAT_004c6e14);
    local_4._0_1_ = 0x11;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_cc,&SLO);
    local_4._0_1_ = 0x12;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_134,&DRW);
    local_4._0_1_ = 0x13;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_ec,&PRP);
    local_4._0_1_ = 0x14;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_120,&PCE);
    local_4._0_1_ = 0x15;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_fc,&DMZ);
    local_4._0_1_ = 0x16;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_dc,&ALY);
    local_4._0_1_ = 0x17;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_10c,&VSS);
    local_4._0_1_ = 0x18;
    AppendList(&DAT_00bb6f0c,ppuVar8);
    local_4._0_1_ = 0x17;
    FreeList(apuStack_10c);
    local_4._0_1_ = 0x16;
    FreeList(apuStack_dc);
    local_4._0_1_ = 0x15;
    FreeList(apuStack_fc);
    local_4._0_1_ = 0x14;
    FreeList(apuStack_120);
    local_4._0_1_ = 0x13;
    FreeList(apuStack_ec);
    local_4._0_1_ = 0x12;
    FreeList(apuStack_134);
    local_4._0_1_ = 0x11;
    FreeList(apuStack_cc);
    local_4._0_1_ = 0x10;
    FreeList(apuStack_ac);
    local_4._0_1_ = 0xf;
    FreeList(apuStack_8c);
    local_4._0_1_ = 0xe;
    FreeList(apuStack_bc);
    local_4._0_1_ = 4;
    FreeList(apuStack_9c);
  }
  if (0x13 < (int)g_HistoryCounter) {
    ppuVar8 = FUN_00466540(&YES,apuStack_4c,&REJ);
    local_4._0_1_ = 0x19;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_134,&BWX);
    local_4._0_1_ = 0x1a;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_ec,&NOT);
    local_4._0_1_ = 0x1b;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_120,&DAT_004c6e14);
    local_4._0_1_ = 0x1c;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_fc,&SLO);
    local_4._0_1_ = 0x1d;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_dc,&DRW);
    local_4._0_1_ = 0x1e;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_10c,&PRP);
    local_4._0_1_ = 0x1f;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_cc,&PCE);
    local_4._0_1_ = 0x20;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_ac,&DMZ);
    local_4._0_1_ = 0x21;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_8c,&ALY);
    local_4._0_1_ = 0x22;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_bc,&VSS);
    local_4._0_1_ = 0x23;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_9c,&XDO);
    local_4._0_1_ = 0x24;
    AppendList(&DAT_00bb6f0c,ppuVar8);
    local_4._0_1_ = 0x23;
    FreeList(apuStack_9c);
    local_4._0_1_ = 0x22;
    FreeList(apuStack_bc);
    local_4._0_1_ = 0x21;
    FreeList(apuStack_8c);
    local_4._0_1_ = 0x20;
    FreeList(apuStack_ac);
    local_4._0_1_ = 0x1f;
    FreeList(apuStack_cc);
    local_4._0_1_ = 0x1e;
    FreeList(apuStack_10c);
    local_4._0_1_ = 0x1d;
    FreeList(apuStack_dc);
    local_4._0_1_ = 0x1c;
    FreeList(apuStack_fc);
    local_4._0_1_ = 0x1b;
    FreeList(apuStack_120);
    local_4._0_1_ = 0x1a;
    FreeList(apuStack_ec);
    local_4._0_1_ = 0x19;
    FreeList(apuStack_134);
    local_4._0_1_ = 4;
    FreeList(apuStack_4c);
  }
  if (0x1d < (int)g_HistoryCounter) {
    ppuVar8 = FUN_00466540(&YES,apuStack_3c,&REJ);
    local_4._0_1_ = 0x25;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_2c,&BWX);
    local_4._0_1_ = 0x26;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_134,&NOT);
    local_4._0_1_ = 0x27;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_ec,&DAT_004c6e14);
    local_4._0_1_ = 0x28;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_120,&SLO);
    local_4._0_1_ = 0x29;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_fc,&DRW);
    local_4._0_1_ = 0x2a;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_dc,&PRP);
    local_4._0_1_ = 0x2b;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_10c,&PCE);
    local_4._0_1_ = 0x2c;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_cc,&DMZ);
    local_4._0_1_ = 0x2d;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_ac,&ALY);
    local_4._0_1_ = 0x2e;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_8c,&VSS);
    local_4._0_1_ = 0x2f;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_bc,&XDO);
    local_4._0_1_ = 0x30;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_9c,&AND);
    local_4._0_1_ = 0x31;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_4c,&ORR);
    local_4._0_1_ = 0x32;
    AppendList(&DAT_00bb6f0c,ppuVar8);
    local_4._0_1_ = 0x31;
    FreeList(apuStack_4c);
    local_4._0_1_ = 0x30;
    FreeList(apuStack_9c);
    local_4._0_1_ = 0x2f;
    FreeList(apuStack_bc);
    local_4._0_1_ = 0x2e;
    FreeList(apuStack_8c);
    local_4._0_1_ = 0x2d;
    FreeList(apuStack_ac);
    local_4._0_1_ = 0x2c;
    FreeList(apuStack_cc);
    local_4._0_1_ = 0x2b;
    FreeList(apuStack_10c);
    local_4._0_1_ = 0x2a;
    FreeList(apuStack_dc);
    local_4._0_1_ = 0x29;
    FreeList(apuStack_fc);
    local_4._0_1_ = 0x28;
    FreeList(apuStack_120);
    local_4._0_1_ = 0x27;
    FreeList(apuStack_ec);
    local_4._0_1_ = 0x26;
    FreeList(apuStack_134);
    local_4._0_1_ = 0x25;
    FreeList(apuStack_2c);
    local_4._0_1_ = 4;
    FreeList(apuStack_3c);
  }
  if (DAT_00baed40 == '\x01') {
    ppuVar8 = FUN_00466540(&YES,apuStack_2c,&REJ);
    local_4._0_1_ = 0x33;
    ppuVar8 = FUN_00466480(ppuVar8,apuStack_3c,&BWX);
    local_4._0_1_ = 0x34;
    AppendList(&DAT_00bb6f0c,ppuVar8);
    local_4._0_1_ = 0x33;
    FreeList(apuStack_3c);
    local_4._0_1_ = 4;
    FreeList(apuStack_2c);
  }
  uVar10 = FUN_00465930(0xbb6f0c);
  iStack_140 = 0;
  if (0 < *(int *)(*(int *)((int)local_124 + 8) + 0x2404)) {
    this_00 = &DAT_00bb6e10;
    do {
      cVar1 = *(char *)((int)*(int **)(*(int *)(this_00 + 4) + 4) + 0xf);
      piVar4 = *(int **)(*(int *)(this_00 + 4) + 4);
      while (cVar1 == '\0') {
        FUN_00410c30((int *)piVar4[2]);
        piVar3 = (int *)*piVar4;
        _free(piVar4);
        piVar4 = piVar3;
        cVar1 = *(char *)((int)piVar3 + 0xf);
      }
      *(int *)(*(int *)(this_00 + 4) + 4) = *(int *)(this_00 + 4);
      iVar12 = 0;
      *(undefined4 *)(this_00 + 8) = 0;
      *(undefined4 *)*(undefined4 *)(this_00 + 4) = *(undefined4 *)(this_00 + 4);
      *(int *)(*(int *)(this_00 + 4) + 8) = *(int *)(this_00 + 4);
      if (0 < (int)uVar10) {
        do {
          puVar7 = (ushort *)GetListElement(&DAT_00bb6f0c,&uStack_142,iVar12);
          RegisterAllowedPressToken(this_00,apuStack_134,puVar7);
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)uVar10);
      }
      iStack_140 = iStack_140 + 1;
      this_00 = this_00 + 0xc;
      uVar11 = local_138;
    } while (iStack_140 < *(int *)(*(int *)((int)local_124 + 8) + 0x2404));
  }
  DAT_00baed41 = 1;
  psVar6 = (short *)GetListElement(local_5c,&uStack_142,0);
  if (MTL == *psVar6) {
    puVar7 = (ushort *)GetListElement(local_5c,&uStack_142,1);
    uVar2 = *puVar7;
    local_138 = CONCAT22(local_138._2_2_,uVar2);
    local_13c = (uint)uVar2;
    if ((uVar2 & 0x2000) != 0) {
      local_13c = local_13c | 0xffffe000;
    }
  }
  DAT_00624ef4 = local_13c;
  _Var13 = __time64((__time64_t *)0x0);
  SetTurnDeadline((int)_Var13 + uVar11 * 1000);
  iVar12 = _rand();
  iVar9 = _rand();
  _DAT_00bbf686 = MTO;
  _DAT_00bbf68c = SUP;
  _DAT_00bbf688 = CTO;
  local_4._0_1_ = 3;
  DAT_004c6bd4 = (iVar12 / 0x17) % 0x32 + (iVar9 / 0x17) % 0x32;
  DAT_00bbf684 = HLD;
  _DAT_00bbf68a = CVY;
  FreeList(apvStack_1c);
  local_4._0_1_ = 2;
  piVar4 = (int *)(iStack_110 + -4);
  LOCK();
  iVar12 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar12 == 1 || iVar12 + -1 < 0) {
    (**(code **)(**(int **)(iStack_110 + -0x10) + 4))((undefined4 *)(iStack_110 + -0x10));
  }
  local_4._0_1_ = 1;
  FreeList(local_5c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_6c);
  local_4 = 0xffffffff;
  FreeList(local_7c);
  ExceptionList = local_c;
  return;
}

