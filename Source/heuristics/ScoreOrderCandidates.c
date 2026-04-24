
undefined * __thiscall
ScoreOrderCandidates
          (void *this,undefined4 param_1,int **param_2,undefined4 param_3,undefined4 param_4,
          int **param_5)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  bool bVar6;
  int *piVar7;
  undefined4 *puVar8;
  void **ppvVar9;
  byte *pbVar10;
  uint uVar11;
  short *psVar12;
  uint **ppuVar13;
  int *piVar14;
  int iVar15;
  undefined *puVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  int **ppiVar20;
  char acStack_5aa [2];
  int *piStack_5a8;
  int **ppiStack_5a4;
  char acStack_59e [2];
  int *piStack_59c;
  uint uStack_598;
  void *local_594;
  undefined *puStack_590;
  undefined4 *puStack_58c;
  int iStack_588;
  uint local_584;
  undefined2 uStack_57e;
  void *local_57c [4];
  undefined *local_56c;
  uint *local_568 [4];
  undefined2 uStack_556;
  undefined2 uStack_554;
  undefined2 uStack_552;
  int iStack_550;
  void *apvStack_54c [3];
  void *apvStack_540 [4];
  uint *apuStack_530 [4];
  uint *local_520 [4];
  void *apvStack_510 [4];
  void *apvStack_500 [4];
  void *apvStack_4f0 [4];
  void *apvStack_4e0 [4];
  void *apvStack_4d0 [4];
  uint *apuStack_4c0 [4];
  void *apvStack_4b0 [4];
  void *apvStack_4a0 [4];
  void *apvStack_490 [4];
  void *apvStack_480 [4];
  void *apvStack_470 [4];
  void *apvStack_460 [4];
  int aiStack_450 [21];
  int local_3fc [63];
  int local_300 [63];
  int local_204 [63];
  int local_108 [63];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00497dfe;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_584 = 0;
  local_4 = 1;
  local_56c = &DAT_00989680;
  local_594 = this;
  `eh_vector_constructor_iterator'(local_3fc,0xc,0x15,FUN_004220b0,FUN_0041cc10);
  local_4._0_1_ = 2;
  `eh_vector_constructor_iterator'(local_204,0xc,0x15,FUN_004220b0,FUN_0041cc10);
  local_4._0_1_ = 3;
  `eh_vector_constructor_iterator'(local_300,0xc,0x15,FUN_004220b0,FUN_0041cc10);
  local_4._0_1_ = 4;
  `eh_vector_constructor_iterator'(local_108,0xc,0x15,FUN_004220b0,FUN_0041cc10);
  local_4._0_1_ = 5;
  FUN_00465870(local_57c);
  local_4._0_1_ = 6;
  FUN_00465870(local_568);
  local_4._0_1_ = 7;
  FUN_00465870(local_520);
  local_4 = CONCAT31(local_4._1_3_,8);
  piVar7 = FUN_0047020b();
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_550 = (**(code **)(*piVar7 + 0xc))();
  iStack_550 = iStack_550 + 0x10;
  piStack_59c = (int *)(uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  iVar18 = 0;
  local_4._0_1_ = 9;
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
    piVar7 = &DAT_00bb6cfc;
    do {
      FUN_00410cf0(*(int **)(*piVar7 + 4));
      *(int *)(*piVar7 + 4) = *piVar7;
      piVar7[1] = 0;
      *(int *)*piVar7 = *piVar7;
      *(int *)(*piVar7 + 8) = *piVar7;
      iVar18 = iVar18 + 1;
      piVar7 = piVar7 + 3;
    } while (iVar18 < *(int *)(*(int *)((int)this + 8) + 0x2404));
  }
  puStack_58c = (undefined4 *)*DAT_00bbf60c;
  puStack_590 = &g_CandidateRecordList;
  while( true ) {
    puVar5 = puStack_58c;
    puVar16 = puStack_590;
    puVar8 = DAT_00bbf60c;
    if ((puStack_590 == (undefined *)0x0) || (puStack_590 != &g_CandidateRecordList)) {
      FUN_0047a948();
    }
    iVar18 = DAT_00bc1e04;
    if (puVar5 == puVar8) break;
    if (puVar16 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
      FUN_0047a948();
    }
    puVar8 = (undefined4 *)GameBoard_GetPowerRec(&DAT_00bc1e00,(int *)&piStack_5a8,puVar5 + 7);
    if (((undefined *)*puVar8 == (undefined *)0x0) || ((undefined *)*puVar8 != &DAT_00bc1e00)) {
      FUN_0047a948();
    }
    if (puVar8[1] != iVar18) {
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[0x16] = 0;
      if ((puVar5 == *(undefined4 **)(puVar16 + 4)) &&
         (FUN_0047a948(), puVar5 == *(undefined4 **)(puVar16 + 4))) {
        FUN_0047a948();
      }
      puVar5[9] = puVar5[8];
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      *(undefined1 *)(puVar5 + 0x14) = 0;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      iVar18 = 0;
      puVar5[0x10] = 0;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[0x11] = 0;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      *(undefined1 *)((int)puVar5 + 0x51) = 0;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[10] = 10000;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[0xc] = 0x461c4000;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[0xb] = 0;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[0xd] = 0;
      if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
        FUN_0047a948();
      }
      puVar5[0x71] = 0;
      if (0 < *(int *)(*(int *)((int)local_594 + 8) + 0x2400)) {
        puVar8 = puVar5 + 0x87;
        do {
          if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
            FUN_0047a948();
          }
          *puVar8 = 0;
          iVar18 = iVar18 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar18 < *(int *)(*(int *)((int)local_594 + 8) + 0x2400));
      }
      puVar8 = puVar5 + 0x35;
      iVar18 = 0x1e;
      do {
        if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
          FUN_0047a948();
        }
        puVar8[-0x1e] = 0;
        if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
          FUN_0047a948();
        }
        *puVar8 = 0;
        if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
          FUN_0047a948();
        }
        puVar8[0x1e] = 0;
        puVar8 = puVar8 + 1;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
    }
    FUN_0040f260((int *)&puStack_590);
    this = local_594;
  }
  ppiStack_5a4 = (int **)*param_2;
  piStack_5a8 = &param_1;
  while( true ) {
    ppiVar4 = ppiStack_5a4;
    piVar7 = piStack_5a8;
    ppiVar20 = param_2;
    if ((piStack_5a8 == (int *)0x0) || (piStack_5a8 != &param_1)) {
      FUN_0047a948();
    }
    if (ppiVar4 == ppiVar20) break;
    if (piVar7 == (int *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar4 == (int **)piVar7[1]) {
      FUN_0047a948();
    }
    ppvVar9 = (void **)GetSubList(ppiVar4 + 3,apvStack_4a0,1);
    local_4._0_1_ = 10;
    AppendList(local_57c,ppvVar9);
    local_4._0_1_ = 9;
    FreeList(apvStack_4a0);
    puVar8 = GetSubList(local_57c,apvStack_4f0,0);
    local_4._0_1_ = 0xb;
    pbVar10 = (byte *)GetListElement(puVar8,(undefined2 *)acStack_59e,0);
    bVar1 = *pbVar10;
    local_4._0_1_ = 9;
    FreeList(apvStack_4f0);
    FUN_00419300(local_3fc + (uint)bVar1 * 3,apvStack_54c,local_57c);
    FUN_00419300(&DAT_00bb6cf8 + (uint)bVar1 * 0xc,apvStack_470,local_57c);
    uVar11 = FUN_00465930((int)local_57c);
    puVar8 = GetSubList(local_57c,apvStack_4b0,1);
    local_4._0_1_ = 0xc;
    psVar12 = (short *)GetListElement(puVar8,(undefined2 *)acStack_5aa,0);
    sVar2 = *psVar12;
    local_4._0_1_ = 9;
    FreeList(apvStack_4b0);
    if (SUP == sVar2) {
      ppvVar9 = (void **)GetSubList(local_57c,apvStack_4d0,2);
      local_4._0_1_ = 0xd;
      AppendList(local_568,ppvVar9);
      local_4._0_1_ = 9;
      FreeList(apvStack_4d0);
      puVar8 = GetSubList(local_57c,apvStack_4e0,2);
      local_4._0_1_ = 0xe;
      puVar8 = GetSubList(puVar8,apvStack_500,0);
      local_4._0_1_ = 0xf;
      pbVar10 = (byte *)GetListElement(puVar8,&uStack_57e,0);
      uVar17 = (uint)*pbVar10;
      local_4._0_1_ = 0xe;
      FreeList(apvStack_500);
      local_4._0_1_ = 9;
      FreeList(apvStack_4e0);
      if (uVar11 == 5) {
        FUN_00465aa0(local_568);
        ppvVar9 = (void **)GetSubList(local_57c,apvStack_540,4);
        local_4._0_1_ = 0x10;
        ppuVar13 = FUN_00466480(local_568,apuStack_530,&MTO);
        local_4._0_1_ = 0x11;
        ppuVar13 = FUN_00466330(ppuVar13,apuStack_4c0,ppvVar9);
        local_4._0_1_ = 0x12;
        AppendList(local_520,ppuVar13);
        local_4._0_1_ = 0x11;
        FreeList(apuStack_4c0);
        local_4._0_1_ = 0x10;
        FreeList(apuStack_530);
        local_4._0_1_ = 9;
        FreeList(apvStack_540);
        FUN_00419300(local_300 + uVar17 * 3,apvStack_480,local_520);
        ppuVar13 = local_520;
        ppvVar9 = apvStack_490;
        piVar7 = (int *)(&DAT_00bb6cf8 + uVar17 * 0xc);
      }
      else {
        ppuVar13 = local_568;
        ppvVar9 = apvStack_510;
        piVar7 = local_108 + uVar17 * 3;
      }
      FUN_00419300(piVar7,ppvVar9,ppuVar13);
    }
    FUN_00401590((int *)&piStack_5a8);
  }
  ppiStack_5a4 = (int **)*param_5;
  piStack_5a8 = &param_4;
  while( true ) {
    ppiVar4 = ppiStack_5a4;
    piVar7 = piStack_5a8;
    ppiVar20 = param_5;
    if ((piStack_5a8 == (int *)0x0) || (piStack_5a8 != &param_4)) {
      FUN_0047a948();
    }
    if (ppiVar4 == ppiVar20) break;
    if (piVar7 == (int *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar4 == (int **)piVar7[1]) {
      FUN_0047a948();
    }
    ppvVar9 = (void **)GetSubList(ppiVar4 + 3,apvStack_540,1);
    local_4._0_1_ = 0x13;
    AppendList(local_57c,ppvVar9);
    local_4._0_1_ = 9;
    FreeList(apvStack_540);
    puVar8 = GetSubList(local_57c,apuStack_530,0);
    local_4._0_1_ = 0x14;
    pbVar10 = (byte *)GetListElement(puVar8,&uStack_57e,0);
    bVar1 = *pbVar10;
    local_4._0_1_ = 9;
    FreeList(apuStack_530);
    FUN_00419300(local_204 + (uint)bVar1 * 3,apvStack_510,local_57c);
    FUN_00401590((int *)&piStack_5a8);
  }
  piVar7 = (int *)0x0;
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
    piVar19 = &DAT_00bb6d00;
    do {
      if ((0 < (int)(&DAT_0062e460)[(int)piVar7]) && (*piVar19 != 0)) {
        iVar18 = ((&DAT_0062e460)[(int)piVar7] * DAT_004c6bb8 + 10) / 10;
        DAT_00baed5c = 0;
        if ((DAT_004c6bbc == 0) && (piVar7 != piStack_59c)) {
          iVar18 = 1;
        }
        ProcessTurn(this,piVar7,iVar18);
      }
      piVar7 = (int *)((int)piVar7 + 1);
      piVar19 = piVar19 + 3;
    } while ((int)piVar7 < *(int *)(*(int *)((int)this + 8) + 0x2404));
  }
  iStack_588 = 0;
  if (0 < *(int *)(*(int *)((int)local_594 + 8) + 0x2404)) {
    do {
      iVar15 = iStack_588;
      iVar18 = DAT_00bc1e04;
      puVar8 = (undefined4 *)GameBoard_GetPowerRec(&DAT_00bc1e00,(int *)apvStack_54c,&iStack_588);
      if (((undefined *)*puVar8 == (undefined *)0x0) || ((undefined *)*puVar8 != &DAT_00bc1e00)) {
        FUN_0047a948();
      }
      if (puVar8[1] != iVar18) {
        puStack_58c = (undefined4 *)*DAT_00bbf60c;
        aiStack_450[iVar15] = 0;
        puStack_590 = &g_CandidateRecordList;
        while( true ) {
          puVar5 = puStack_58c;
          puVar16 = puStack_590;
          puVar8 = DAT_00bbf60c;
          if ((puStack_590 == (undefined *)0x0) || (puStack_590 != &g_CandidateRecordList)) {
            FUN_0047a948();
          }
          if (puVar5 == puVar8) break;
          if (puVar16 == (undefined *)0x0) {
            FUN_0047a948();
          }
          if (puVar5 == *(undefined4 **)(puVar16 + 4)) {
            FUN_0047a948();
          }
          puVar8 = puStack_58c;
          if (iVar15 == puVar5[7]) {
            if (puStack_58c == *(undefined4 **)(puStack_590 + 4)) {
              FUN_0047a948();
            }
            AppendList(local_57c,(void **)(puVar8 + 3));
            uStack_598 = FUN_00465930((int)local_57c);
            iVar18 = iStack_588;
            piVar7 = (int *)(iStack_588 * 0xc);
            acStack_5aa[0] = '\x01';
            piStack_59c = piVar7;
            if ((local_3fc + 2)[iStack_588 * 3] == 0) {
LAB_00456386:
              if ((local_204 + 2)[iVar18 * 3] != 0) {
                ppiStack_5a4 = *(int ***)(local_204 + 1)[iVar18 * 3];
                piStack_5a8 = local_204 + iVar18 * 3;
                while( true ) {
                  piVar19 = piStack_5a8;
                  ppiVar20 = *(int ***)((int)(local_204 + 1) + (int)piVar7);
                  if ((piStack_5a8 == (int *)0x0) ||
                     (piStack_5a8 != (int *)((int)local_204 + (int)piVar7))) {
                    FUN_0047a948();
                  }
                  if (ppiStack_5a4 == ppiVar20) break;
                  iVar18 = 2;
                  if (2 < (int)uStack_598) {
                    ppiVar20 = ppiStack_5a4 + 3;
                    do {
                      piVar7 = GetSubList(local_57c,apuStack_530,iVar18);
                      local_4 = CONCAT31(local_4._1_3_,0x16);
                      if (piVar19 == (int *)0x0) {
                        FUN_0047a948();
                      }
                      if (ppiStack_5a4 == (int **)piVar19[1]) {
                        FUN_0047a948();
                      }
                      bVar6 = FUN_00465d90(ppiVar20,piVar7);
                      local_4._0_1_ = 9;
                      FreeList(apuStack_530);
                      if (bVar6) {
                        acStack_5aa[0] = '\0';
                      }
                      iVar18 = iVar18 + 1;
                    } while (iVar18 < (int)uStack_598);
                  }
                  FUN_00401590((int *)&piStack_5a8);
                  piVar7 = piStack_59c;
                }
                if (acStack_5aa[0] != '\x01') goto LAB_004568d5;
              }
              if (*(int *)((int)(local_300 + 2) + (int)piVar7) != 0) {
                ppiStack_5a4 = (int **)**(undefined4 **)((int)(local_300 + 1) + (int)piVar7);
                piStack_5a8 = (int *)((int)local_300 + (int)piVar7);
                while( true ) {
                  piVar19 = piStack_5a8;
                  ppiVar20 = *(int ***)((int)(local_300 + 1) + (int)piVar7);
                  if ((piStack_5a8 == (int *)0x0) ||
                     (piStack_5a8 != (int *)((int)local_300 + (int)piVar7))) {
                    FUN_0047a948();
                  }
                  if (ppiStack_5a4 == ppiVar20) break;
                  iVar18 = 2;
                  acStack_59e[0] = '\0';
                  if ((int)uStack_598 < 3) {
LAB_00456717:
                    acStack_5aa[0] = '\0';
                  }
                  else {
                    do {
                      puVar8 = GetSubList(local_57c,apvStack_4e0,iVar18);
                      local_4._0_1_ = 0x17;
                      ppvVar9 = (void **)GetSubList(puVar8,apuStack_4c0,0);
                      local_4._0_1_ = 0x18;
                      AppendList(local_568,ppvVar9);
                      local_4._0_1_ = 0x17;
                      FreeList(apuStack_4c0);
                      local_4._0_1_ = 9;
                      FreeList(apvStack_4e0);
                      puVar8 = GetSubList(local_57c,apvStack_4d0,iVar18);
                      local_4._0_1_ = 0x19;
                      puVar8 = GetSubList(puVar8,apvStack_500,1);
                      local_4._0_1_ = 0x1a;
                      psVar12 = (short *)GetListElement(puVar8,&uStack_57e,0);
                      sVar2 = *psVar12;
                      local_4._0_1_ = 0x19;
                      FreeList(apvStack_500);
                      local_4 = CONCAT31(local_4._1_3_,9);
                      FreeList(apvStack_4d0);
                      if (piVar19 == (int *)0x0) {
                        FUN_0047a948();
                      }
                      ppiVar20 = ppiStack_5a4;
                      if (ppiStack_5a4 == (int **)piVar19[1]) {
                        FUN_0047a948();
                      }
                      puVar8 = GetSubList(ppiVar20 + 3,apvStack_4b0,0);
                      local_584 = local_584 | 1;
                      local_4 = CONCAT31(local_4._1_3_,0x1b);
                      bVar6 = FUN_00465d90(puVar8,(int *)local_568);
                      if ((bVar6) && ((MTO == sVar2 || (CTO == sVar2)))) {
                        bVar6 = true;
                      }
                      else {
                        bVar6 = false;
                      }
                      local_4._0_1_ = 9;
                      local_4._1_3_ = 0;
                      if ((local_584 & 1) != 0) {
                        local_584 = local_584 & 0xfffffffe;
                        FreeList(apvStack_4b0);
                      }
                      if (bVar6) {
                        puVar8 = GetSubList(local_57c,apvStack_4a0,iVar18);
                        local_4._0_1_ = 0x1c;
                        puVar8 = GetSubList(puVar8,apvStack_4f0,2);
                        local_4._0_1_ = 0x1d;
                        psVar12 = (short *)GetListElement(puVar8,&uStack_554,0);
                        sVar2 = *psVar12;
                        local_4._0_1_ = 0x1c;
                        FreeList(apvStack_4f0);
                        local_4 = CONCAT31(local_4._1_3_,9);
                        FreeList(apvStack_4a0);
                        if (ppiStack_5a4 == (int **)piVar19[1]) {
                          FUN_0047a948();
                        }
                        puVar8 = GetSubList(ppiStack_5a4 + 3,apvStack_510,2);
                        local_4._0_1_ = 0x1e;
                        psVar12 = (short *)GetListElement(puVar8,&uStack_552,0);
                        sVar3 = *psVar12;
                        local_4._0_1_ = 9;
                        FreeList(apvStack_510);
                        if (sVar2 == sVar3) {
                          acStack_59e[0] = '\x01';
                        }
                      }
                      iVar18 = iVar18 + 1;
                    } while (iVar18 < (int)uStack_598);
                    if (acStack_59e[0] == '\0') goto LAB_00456717;
                  }
                  FUN_00401590((int *)&piStack_5a8);
                  piVar7 = piStack_59c;
                }
                if (acStack_5aa[0] != '\x01') goto LAB_004568d5;
              }
              if (*(int *)((int)(local_108 + 2) + (int)piVar7) != 0) {
                ppiStack_5a4 = (int **)**(undefined4 **)((int)(local_108 + 1) + (int)piStack_59c);
                piVar7 = (int *)((int)local_108 + (int)piStack_59c);
                piStack_5a8 = piVar7;
                piStack_59c = piVar7;
                while( true ) {
                  piVar19 = piStack_5a8;
                  ppiVar20 = (int **)piVar7[1];
                  if ((piStack_5a8 == (int *)0x0) || (piStack_5a8 != piVar7)) {
                    FUN_0047a948();
                  }
                  uVar11 = uStack_598;
                  if (ppiStack_5a4 == ppiVar20) break;
                  iVar18 = 2;
                  if (2 < (int)uStack_598) {
                    do {
                      puVar8 = GetSubList(local_57c,apvStack_480,iVar18);
                      local_4._0_1_ = 0x1f;
                      ppvVar9 = (void **)GetSubList(puVar8,apvStack_490,0);
                      local_4._0_1_ = 0x20;
                      AppendList(local_568,ppvVar9);
                      local_4._0_1_ = 0x1f;
                      FreeList(apvStack_490);
                      local_4._0_1_ = 9;
                      FreeList(apvStack_480);
                      puVar8 = GetSubList(local_57c,apvStack_460,iVar18);
                      local_4._0_1_ = 0x21;
                      puVar8 = GetSubList(puVar8,apvStack_470,1);
                      local_4._0_1_ = 0x22;
                      psVar12 = (short *)GetListElement(puVar8,&uStack_556,0);
                      sVar2 = *psVar12;
                      local_4._0_1_ = 0x21;
                      FreeList(apvStack_470);
                      local_4._0_1_ = 9;
                      FreeList(apvStack_460);
                      if (piVar19 == (int *)0x0) {
                        FUN_0047a948();
                      }
                      if (ppiStack_5a4 == (int **)piVar19[1]) {
                        FUN_0047a948();
                      }
                      bVar6 = FUN_00465d90(ppiStack_5a4 + 3,(int *)local_568);
                      if ((bVar6) && ((MTO == sVar2 || (CTO == sVar2)))) {
                        acStack_5aa[0] = '\0';
                      }
                      iVar18 = iVar18 + 1;
                      piVar7 = piStack_59c;
                    } while (iVar18 < (int)uVar11);
                  }
                  FUN_00401590((int *)&piStack_5a8);
                }
                goto LAB_004568d5;
              }
            }
            else {
              ppiStack_5a4 = *(int ***)(local_3fc + 1)[iStack_588 * 3];
              piStack_5a8 = local_3fc + iStack_588 * 3;
              while( true ) {
                piVar19 = piStack_5a8;
                ppiVar20 = (int **)(local_3fc + 1)[iVar18 * 3];
                if ((piStack_5a8 == (int *)0x0) || (piStack_5a8 != local_3fc + iVar18 * 3)) {
                  FUN_0047a948();
                }
                if (ppiStack_5a4 == ppiVar20) break;
                iVar15 = 2;
                acStack_59e[0] = '\0';
                if ((int)uStack_598 < 3) {
LAB_00456364:
                  acStack_5aa[0] = '\0';
                }
                else {
                  do {
                    piVar14 = GetSubList(local_57c,apvStack_540,iVar15);
                    local_4 = CONCAT31(local_4._1_3_,0x15);
                    if (piVar19 == (int *)0x0) {
                      FUN_0047a948();
                    }
                    if (ppiStack_5a4 == (int **)piVar19[1]) {
                      FUN_0047a948();
                    }
                    bVar6 = FUN_00465d90(ppiStack_5a4 + 3,piVar14);
                    local_4._0_1_ = 9;
                    FreeList(apvStack_540);
                    if (bVar6) {
                      acStack_59e[0] = '\x01';
                    }
                    iVar15 = iVar15 + 1;
                  } while (iVar15 < (int)uStack_598);
                  if (acStack_59e[0] == '\0') goto LAB_00456364;
                }
                FUN_00401590((int *)&piStack_5a8);
              }
              if (acStack_5aa[0] == '\x01') goto LAB_00456386;
LAB_004568d5:
              puVar8 = puStack_58c;
              puVar16 = puStack_590;
              if (acStack_5aa[0] == '\0') {
                if (puStack_58c == *(undefined4 **)(puStack_590 + 4)) {
                  FUN_0047a948();
                }
                *(undefined1 *)(puVar8 + 0x14) = 1;
                if (puVar8 == *(undefined4 **)(puVar16 + 4)) {
                  FUN_0047a948();
                }
                puVar8[9] = 0xff676980;
                goto LAB_00456911;
              }
            }
            aiStack_450[iStack_588] = aiStack_450[iStack_588] + 1;
          }
LAB_00456911:
          FUN_0040f260((int *)&puStack_590);
          iVar15 = iStack_588;
        }
      }
      iStack_588 = iVar15 + 1;
    } while (iStack_588 < *(int *)(*(int *)((int)local_594 + 8) + 0x2404));
  }
  piStack_59c = (int *)0x0;
  puVar16 = local_56c;
  if (0 < *(int *)(*(int *)((int)local_594 + 8) + 0x2404)) {
    do {
      piVar7 = piStack_59c;
      iVar18 = DAT_00bc1e04;
      puVar8 = (undefined4 *)
               GameBoard_GetPowerRec(&DAT_00bc1e00,(int *)apvStack_54c,(int *)&piStack_59c);
      if (((undefined *)*puVar8 == (undefined *)0x0) || ((undefined *)*puVar8 != &DAT_00bc1e00)) {
        FUN_0047a948();
      }
      if (((puVar8[1] != iVar18) && (local_3fc[(int)piVar7 * 3 + 2] != 0)) &&
         (aiStack_450[(int)piVar7] < (int)puVar16)) {
        puVar16 = (undefined *)aiStack_450[(int)piVar7];
      }
      piStack_59c = (int *)((int)piVar7 + 1);
    } while ((int)piStack_59c < *(int *)(*(int *)((int)local_594 + 8) + 0x2404));
  }
  local_56c = puVar16;
  local_4._0_1_ = 8;
  piVar7 = (int *)(iStack_550 + -4);
  LOCK();
  iVar18 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar18 == 1 || iVar18 + -1 < 0) {
    (**(code **)(**(int **)(iStack_550 + -0x10) + 4))((undefined4 *)(iStack_550 + -0x10));
  }
  local_4._0_1_ = 7;
  FreeList(local_520);
  local_4._0_1_ = 6;
  FreeList(local_568);
  local_4._0_1_ = 5;
  FreeList(local_57c);
  local_4._0_1_ = 4;
  `eh_vector_destructor_iterator'(local_108,0xc,0x15,FUN_0041cc10);
  local_4._0_1_ = 3;
  `eh_vector_destructor_iterator'(local_300,0xc,0x15,FUN_0041cc10);
  local_4._0_1_ = 2;
  `eh_vector_destructor_iterator'(local_204,0xc,0x15,FUN_0041cc10);
  local_4._0_1_ = 1;
  `eh_vector_destructor_iterator'(local_3fc,0xc,0x15,FUN_0041cc10);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00419cb0(&param_1,apvStack_54c,&param_1,(int **)*param_2,&param_1,param_2);
  _free(param_2);
  param_2 = (int **)0x0;
  param_3 = 0;
  local_4 = 0xffffffff;
  FUN_00419cb0(&param_4,apvStack_54c,&param_4,(int **)*param_5,&param_4,param_5);
  _free(param_5);
  ExceptionList = local_c;
  return local_56c;
}

