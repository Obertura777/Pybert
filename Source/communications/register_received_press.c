
undefined *
FUN_00431310(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
            undefined2 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
            undefined1 param_9,undefined1 param_10,int **param_11,undefined1 param_12)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  int **ppiVar6;
  undefined1 *puVar7;
  int **ppiVar8;
  uint uVar9;
  byte *pbVar10;
  uint **ppuVar11;
  int iVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined1 auStack_240 [12];
  undefined4 uStack_234;
  undefined1 auStack_22c [4];
  undefined4 uStack_228;
  undefined1 *local_1fc;
  undefined1 *local_1f8;
  undefined1 *local_1f4;
  int **local_1f0;
  int local_1e8;
  uint *local_1e4 [4];
  undefined1 local_1d4 [4];
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined1 local_1c8 [12];
  undefined1 local_1bc [4];
  int local_1b8;
  undefined4 local_1b4;
  undefined1 local_1b0 [4];
  int local_1ac;
  undefined4 local_1a8;
  undefined4 auStack_1a4 [21];
  undefined1 *local_150;
  undefined1 local_14c [16];
  undefined1 local_13c;
  __time64_t local_134;
  undefined1 local_12c [16];
  undefined2 local_11c;
  undefined1 local_118 [20];
  undefined1 *local_104;
  void *local_100 [4];
  uint *local_f0 [3];
  undefined1 *local_e4 [2];
  undefined1 local_dc [208];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00496e70;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 2;
  FUN_00422960((int)local_1d4);
  local_4._0_1_ = 3;
  FUN_00465f60(local_100,(void **)&param_1);
  uVar5 = param_5;
  local_1fc = (undefined1 *)(uint)(byte)param_5;
  local_4 = CONCAT31(local_4._1_3_,4);
  uVar9 = FUN_00465930((int)&param_6);
  StdMap_FindOrInsert(local_1c8,&local_1f4,(int *)&local_1fc);
  iVar14 = 0;
  if (0 < (int)uVar9) {
    do {
      pbVar10 = (byte *)GetListElement(&param_6,(undefined2 *)&local_1fc,iVar14);
      local_1f8 = (undefined1 *)(uint)*pbVar10;
      StdMap_FindOrInsert(local_1c8,&local_1f4,(int *)&local_1f8);
      iVar14 = iVar14 + 1;
    } while (iVar14 < (int)uVar9);
  }
  local_1cc = 0;
  local_1d0 = 0;
  local_1d4[0] = 0;
  ppuVar11 = FUN_00466f80(&SUB,local_1e4,(void **)&DAT_00bc1e0c);
  local_4._0_1_ = 5;
  AppendList(local_14c,ppuVar11);
  local_4._0_1_ = 4;
  FreeList(local_1e4);
  local_13c = 0;
  AppendList(local_12c,local_100);
  local_11c = uVar5;
  AppendList(local_118,(void **)&param_6);
  local_1f8 = &stack0xfffffde4;
  FUN_004220e0(&stack0xfffffde4,(int)&param_10);
  local_1fc = auStack_22c;
  local_4._0_1_ = 6;
  uStack_234 = 0x431497;
  FUN_00465f60(auStack_22c,(void **)&param_6);
  local_104 = &stack0xfffffdd0;
  local_1f4 = auStack_240;
  local_4._0_1_ = 8;
  FUN_00465f60(auStack_240,(void **)&param_1);
  local_4 = CONCAT31(local_4._1_3_,4);
  local_1fc = (undefined1 *)FUN_00426140(local_1e8);
  FUN_00410cf0(*(int **)(local_1b8 + 4));
  *(int *)(local_1b8 + 4) = local_1b8;
  local_1b4 = 0;
  *(int *)local_1b8 = local_1b8;
  *(int *)(local_1b8 + 8) = local_1b8;
  FUN_00410cf0(*(int **)(local_1ac + 4));
  *(int *)(local_1ac + 4) = local_1ac;
  local_1a8 = 0;
  *(int *)local_1ac = local_1ac;
  *(int *)(local_1ac + 8) = local_1ac;
  local_150 = (undefined1 *)0xffffffff;
  local_1d0 = 0;
  local_134 = __time64((__time64_t *)0x0);
  local_1f0 = (int **)*param_11;
  local_1f4 = &param_10;
  while( true ) {
    ppiVar8 = local_1f0;
    puVar13 = local_1f4;
    ppiVar6 = param_11;
    if ((local_1f4 == (undefined1 *)0x0) || (local_1f4 != &param_10)) {
      FUN_0047a948();
    }
    if (ppiVar8 == ppiVar6) break;
    if (puVar13 == (undefined1 *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar8 == *(int ***)(puVar13 + 4)) {
      FUN_0047a948();
    }
    if (*(char *)(ppiVar8 + 7) == '\x01') {
      if (ppiVar8 == *(int ***)(puVar13 + 4)) {
        FUN_0047a948();
      }
      ppuVar11 = local_f0;
      puVar13 = local_1b0;
    }
    else {
      if (ppiVar8 == *(int ***)(puVar13 + 4)) {
        FUN_0047a948();
      }
      ppuVar11 = local_1e4;
      puVar13 = local_1bc;
    }
    FUN_00419300(puVar13,ppuVar11,ppiVar8 + 3);
    std_Tree_IteratorIncrement((int *)&local_1f4);
  }
  iVar14 = *(int *)(local_1e8 + 8);
  iVar12 = 0;
  if (0 < *(int *)(iVar14 + 0x2404)) {
    do {
      if (local_1fc == (undefined *)0x0) {
        auStack_1a4[iVar12] = 0;
      }
      else {
        auStack_1a4[iVar12] = local_1fc;
        local_1d4[0] = 1;
        local_1cc = DAT_004c6bbc;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(iVar14 + 0x2404));
  }
  local_1f8 = DAT_00bb65f4;
  local_e4[0] = DAT_00bb65f4;
  local_150 = (undefined1 *)0xffffffff;
  BuildHostilityRecord(local_dc,local_1d4);
  local_4._0_1_ = 9;
  SendAlliancePress(&DAT_00bb65ec,local_1e4,(int *)local_e4);
  local_4 = CONCAT31(local_4._1_3_,4);
  DestroyAllianceRecord((int)local_dc);
  cVar1 = *(char *)((int)*(int **)(local_1b8 + 4) + 0x1d);
  piVar3 = *(int **)(local_1b8 + 4);
  while (cVar1 == '\0') {
    FUN_00410cf0((int *)piVar3[2]);
    piVar2 = (int *)*piVar3;
    FreeList((void **)(piVar3 + 3));
    _free(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  *(int *)(local_1b8 + 4) = local_1b8;
  local_1b4 = 0;
  *(int *)local_1b8 = local_1b8;
  *(int *)(local_1b8 + 8) = local_1b8;
  cVar1 = *(char *)((int)*(int **)(local_1ac + 4) + 0x1d);
  piVar3 = *(int **)(local_1ac + 4);
  while (cVar1 == '\0') {
    FUN_00410cf0((int *)piVar3[2]);
    piVar2 = (int *)*piVar3;
    FreeList((void **)(piVar3 + 3));
    _free(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  *(int *)(local_1ac + 4) = local_1ac;
  local_1a8 = 0;
  *(int *)local_1ac = local_1ac;
  *(int *)(local_1ac + 8) = local_1ac;
  local_1f0 = (int **)*param_11;
  local_1f4 = &param_10;
  local_13c = param_12;
  while( true ) {
    ppiVar8 = local_1f0;
    puVar13 = local_1f4;
    ppiVar6 = param_11;
    if ((local_1f4 == (undefined1 *)0x0) || (local_1f4 != &param_10)) {
      FUN_0047a948();
    }
    puVar7 = local_1fc;
    puVar4 = DAT_00bb65f4;
    if (ppiVar8 == ppiVar6) break;
    if (puVar13 == (undefined1 *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar8 == *(int ***)(puVar13 + 4)) {
      FUN_0047a948();
    }
    if (*(char *)(ppiVar8 + 7) == '\0') {
      if (ppiVar8 == *(int ***)(puVar13 + 4)) {
        FUN_0047a948();
      }
      ppuVar11 = local_1e4;
      puVar13 = local_1b0;
    }
    else {
      if (ppiVar8 == *(int ***)(puVar13 + 4)) {
        FUN_0047a948();
      }
      ppuVar11 = local_f0;
      puVar13 = local_1bc;
    }
    FUN_00419300(puVar13,ppuVar11,ppiVar8 + 3);
    std_Tree_IteratorIncrement((int *)&local_1f4);
  }
  iVar14 = *(int *)(local_1e8 + 8);
  iVar12 = 0;
  if (0 < *(int *)(iVar14 + 0x2404)) {
    do {
      if (local_1fc == (undefined *)0x0) {
        auStack_1a4[iVar12] = 0;
      }
      else {
        auStack_1a4[iVar12] = local_1fc;
        local_1d4[0] = 1;
        local_1cc = DAT_004c6bbc;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(iVar14 + 0x2404));
  }
  local_150 = local_1f8;
  local_e4[0] = DAT_00bb65f4;
  BuildHostilityRecord(local_dc,local_1d4);
  local_4._0_1_ = 10;
  SendAlliancePress(&DAT_00bb65ec,local_1e4,(int *)local_e4);
  local_4._0_1_ = 4;
  DestroyAllianceRecord((int)local_dc);
  DAT_00baed60 = puVar4;
  local_4._0_1_ = 3;
  FreeList(local_100);
  local_4._0_1_ = 2;
  DestroyAllianceRecord((int)local_1d4);
  local_4._0_1_ = 1;
  FreeList((void **)&param_1);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&param_6);
  local_4 = 0xffffffff;
  uStack_228 = 0x431906;
  FUN_0041abc0(&param_10,&local_1f4,&param_10,(int **)*param_11,&param_10,param_11);
  _free(param_11);
  ExceptionList = local_c;
  return puVar7;
}

