
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __thiscall CAL_VALUE(void *this,undefined2 *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  int **ppiVar7;
  int **ppiVar8;
  void *pvVar9;
  undefined *puVar10;
  int *piVar11;
  int iVar12;
  short *psVar13;
  uint uVar14;
  void **ppvVar15;
  undefined4 **ppuVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int *piVar20;
  rsize_t rVar21;
  undefined2 uVar22;
  undefined1 *puVar23;
  undefined4 *puVar24;
  undefined4 *puVar25;
  bool bVar26;
  bool bVar27;
  __time64_t _Var28;
  undefined1 auStack_120 [12];
  undefined4 uStack_114;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined1 *puStack_d8;
  int **ppiStack_d4;
  undefined *puStack_d0;
  undefined4 *puStack_cc;
  undefined1 auStack_c8 [4];
  int **ppiStack_c4;
  int iStack_c0;
  undefined1 auStack_bc [4];
  int **ppiStack_b8;
  int iStack_b4;
  undefined1 auStack_b0 [4];
  int **ppiStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  int *piStack_a0;
  void *pvStack_98;
  undefined *puStack_94;
  undefined4 *puStack_90;
  undefined4 *puStack_8c;
  undefined4 *puStack_88;
  undefined1 *local_84;
  undefined1 auStack_80 [4];
  int **ppiStack_7c;
  undefined4 uStack_78;
  void *pvStack_74;
  undefined4 *puStack_70;
  undefined4 *puStack_64;
  undefined4 *puStack_60;
  void *apvStack_54 [4];
  void *pvStack_44;
  undefined4 *puStack_40;
  undefined1 uStack_34;
  void *local_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  void *apvStack_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004964ce;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_84 = (undefined1 *)(uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4 = 1;
  *param_1 = 0;
  bVar5 = false;
  bVar6 = false;
  local_30 = this;
  piVar11 = FUN_0047020b();
  if (piVar11 == (int *)0x0) {
    piVar11 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar12 = (**(code **)(*piVar11 + 0xc))();
  pvStack_98 = (void *)(iVar12 + 0x10);
  local_4._0_1_ = 2;
  bVar27 = false;
  ppiStack_7c = (int **)FUN_0040fd90();
  *(undefined1 *)((int)ppiStack_7c + 0x1d) = 1;
  ppiStack_7c[1] = (int *)ppiStack_7c;
  *ppiStack_7c = (int *)ppiStack_7c;
  ppiStack_7c[2] = (int *)ppiStack_7c;
  uStack_78 = 0;
  local_4._0_1_ = 3;
  FUN_00465870(apvStack_54);
  local_4._0_1_ = 4;
  FUN_00465870(apvStack_1c);
  local_4._0_1_ = 5;
  ppiStack_c4 = (int **)FUN_0040fd90();
  *(undefined1 *)((int)ppiStack_c4 + 0x1d) = 1;
  ppiStack_c4[1] = (int *)ppiStack_c4;
  *ppiStack_c4 = (int *)ppiStack_c4;
  ppiStack_c4[2] = (int *)ppiStack_c4;
  iStack_c0 = 0;
  local_4._0_1_ = 6;
  ppiStack_b8 = (int **)FUN_0040fd90();
  *(undefined1 *)((int)ppiStack_b8 + 0x1d) = 1;
  ppiStack_b8[1] = (int *)ppiStack_b8;
  *ppiStack_b8 = (int *)ppiStack_b8;
  ppiStack_b8[2] = (int *)ppiStack_b8;
  iStack_b4 = 0;
  local_4._0_1_ = 7;
  puStack_94 = (undefined *)0x0;
  puStack_90 = (undefined4 *)0x0;
  FUN_00410cf0(ppiStack_c4[1]);
  ppiStack_c4[1] = (int *)ppiStack_c4;
  iStack_c0 = 0;
  *ppiStack_c4 = (int *)ppiStack_c4;
  ppiStack_c4[2] = (int *)ppiStack_c4;
  FUN_00410cf0(ppiStack_b8[1]);
  ppiStack_b8[1] = (int *)ppiStack_b8;
  iStack_b4 = 0;
  *ppiStack_b8 = (int *)ppiStack_b8;
  ppiStack_b8[2] = (int *)ppiStack_b8;
  ppiStack_ac = (int **)FUN_0040fed0();
  *(undefined1 *)((int)ppiStack_ac + 0x21) = 1;
  ppiStack_ac[1] = (int *)ppiStack_ac;
  *ppiStack_ac = (int *)ppiStack_ac;
  ppiStack_ac[2] = (int *)ppiStack_ac;
  uStack_a8 = 0;
  local_4._0_1_ = 8;
  psVar13 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&puStack_d8,0);
  if (AND == *psVar13) {
    uVar14 = FUN_00465930((int)&stack0x00000008);
    iVar12 = 0;
    if (0 < (int)(uVar14 - 1)) {
      do {
        iVar12 = iVar12 + 1;
        ppvVar15 = (void **)GetSubList(&stack0x00000008,&puStack_64,iVar12);
        local_4._0_1_ = 9;
        AppendList(apvStack_54,ppvVar15);
        local_4._0_1_ = 8;
        FreeList(&puStack_64);
        AppendList(apvStack_1c,apvStack_54);
        psVar13 = (short *)GetListElement(apvStack_54,(undefined2 *)&puStack_d8,0);
        bVar26 = NOT == *psVar13;
        if (bVar26) {
          ppvVar15 = (void **)GetSubList(apvStack_54,&puStack_2c,1);
          local_4._0_1_ = 10;
          AppendList(apvStack_54,ppvVar15);
          local_4._0_1_ = 8;
          FreeList(&puStack_2c);
        }
        psVar13 = (short *)GetListElement(apvStack_54,(undefined2 *)&puStack_8c,0);
        if (XDO == *psVar13) {
          bVar27 = true;
          if (bVar26) {
            ppvVar15 = &pvStack_44;
            puVar23 = auStack_bc;
          }
          else {
            ppvVar15 = &pvStack_74;
            puVar23 = auStack_c8;
          }
          FUN_00419300(puVar23,ppvVar15,apvStack_54);
          FUN_00419300(&DAT_00bb65d4,&puStack_a4,apvStack_1c);
        }
      } while (iVar12 < (int)(uVar14 - 1));
      if (bVar27) goto LAB_004266af;
    }
  }
  else {
    psVar13 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&puStack_8c,0);
    bVar27 = NOT == *psVar13;
    if (bVar27) {
      ppvVar15 = (void **)GetSubList(&stack0x00000008,&pvStack_74,1);
      local_4._0_1_ = 0xb;
      AppendList(&stack0x00000008,ppvVar15);
      local_4._0_1_ = 8;
      FreeList(&pvStack_74);
    }
    psVar13 = (short *)GetListElement(&stack0x00000008,(undefined2 *)&puStack_8c,0);
    if (XDO == *psVar13) {
      if (bVar27) {
        FUN_00419300(auStack_bc,&pvStack_74,(void **)&stack0x00000008);
      }
      else {
        FUN_00419300(auStack_c8,&pvStack_74,(void **)&stack0x00000008);
      }
LAB_004266af:
      puStack_cc = (undefined4 *)*DAT_00bb65f0;
      puStack_d0 = &DAT_00bb65ec;
      do {
        puVar24 = puStack_cc;
        puVar19 = DAT_00bb65f0;
        if ((puStack_d0 == (undefined *)0x0) || (puStack_d0 != &DAT_00bb65ec)) {
          FUN_0047a948();
        }
        if (puVar24 == puVar19) break;
        ppiStack_d4 = (int **)*ppiStack_c4;
        puStack_d8 = auStack_c8;
        bVar27 = true;
        while( true ) {
          ppiVar8 = ppiStack_c4;
          ppiVar7 = ppiStack_d4;
          puVar23 = puStack_d8;
          if ((puStack_d8 == (undefined1 *)0x0) || (puStack_d8 != auStack_c8)) {
            FUN_0047a948();
          }
          if (ppiVar7 == ppiVar8) break;
          if (puStack_d0 == (undefined *)0x0) {
            FUN_0047a948();
          }
          if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
            FUN_0047a948();
          }
          puVar19 = puVar24 + 0xc;
          puStack_40 = (undefined4 *)puVar24[0xd];
          if (puVar23 == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (ppiVar7 == *(int ***)(puVar23 + 4)) {
            FUN_0047a948();
          }
          if (puStack_cc == *(undefined4 **)(puStack_d0 + 4)) {
            FUN_0047a948();
          }
          puVar17 = (undefined4 *)((undefined4 *)puVar24[0xd])[1];
          cVar3 = *(char *)((int)puVar17 + 0x1d);
          puVar18 = (undefined4 *)puVar24[0xd];
          while (cVar3 == '\0') {
            uVar14 = FUN_00465cf0(puVar17 + 3,(int *)(ppiVar7 + 3));
            if ((char)uVar14 == '\0') {
              puVar25 = (undefined4 *)*puVar17;
            }
            else {
              puVar25 = (undefined4 *)puVar17[2];
              puVar17 = puVar18;
            }
            puVar18 = puVar17;
            puVar17 = puVar25;
            cVar3 = *(char *)((int)puVar25 + 0x1d);
          }
          puStack_88 = puVar18;
          puStack_8c = puVar19;
          if ((puVar18 == (undefined4 *)puVar24[0xd]) ||
             (uVar14 = FUN_00465cf0(ppiVar7 + 3,puVar18 + 3), (char)uVar14 != '\0')) {
            uStack_28 = puVar24[0xd];
            puStack_2c = puVar19;
            ppuVar16 = &puStack_2c;
          }
          else {
            ppuVar16 = &puStack_8c;
          }
          puVar24 = ppuVar16[1];
          if ((*ppuVar16 == (undefined4 *)0x0) || (*ppuVar16 != puVar19)) {
            FUN_0047a948();
          }
          if (puVar24 == puStack_40) {
            bVar27 = false;
          }
          FUN_00401590((int *)&puStack_d8);
          puVar24 = puStack_cc;
        }
        ppiStack_d4 = (int **)*ppiStack_b8;
        puStack_d8 = auStack_bc;
        while( true ) {
          ppiVar8 = ppiStack_b8;
          ppiVar7 = ppiStack_d4;
          puVar23 = puStack_d8;
          if ((puStack_d8 == (undefined1 *)0x0) || (puStack_d8 != auStack_bc)) {
            FUN_0047a948();
          }
          if (ppiVar7 == ppiVar8) break;
          if (puStack_d0 == (undefined *)0x0) {
            FUN_0047a948();
          }
          if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
            FUN_0047a948();
          }
          puVar19 = puVar24 + 0xf;
          puStack_70 = (undefined4 *)puVar24[0x10];
          if (puVar23 == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (ppiVar7 == *(int ***)(puVar23 + 4)) {
            FUN_0047a948();
          }
          if (puStack_cc == *(undefined4 **)(puStack_d0 + 4)) {
            FUN_0047a948();
          }
          puVar17 = (undefined4 *)((undefined4 *)puVar24[0x10])[1];
          cVar3 = *(char *)((int)puVar17 + 0x1d);
          puVar18 = (undefined4 *)puVar24[0x10];
          while (cVar3 == '\0') {
            uVar14 = FUN_00465cf0(puVar17 + 3,(int *)(ppiVar7 + 3));
            if ((char)uVar14 == '\0') {
              puVar25 = (undefined4 *)*puVar17;
            }
            else {
              puVar25 = (undefined4 *)puVar17[2];
              puVar17 = puVar18;
            }
            puVar18 = puVar17;
            puVar17 = puVar25;
            cVar3 = *(char *)((int)puVar25 + 0x1d);
          }
          puStack_60 = puVar18;
          puStack_64 = puVar19;
          if ((puVar18 == (undefined4 *)puVar24[0x10]) ||
             (uVar14 = FUN_00465cf0(ppiVar7 + 3,puVar18 + 3), (char)uVar14 != '\0')) {
            piStack_a0 = (int *)puVar24[0x10];
            puStack_a4 = puVar19;
            ppuVar16 = &puStack_a4;
          }
          else {
            ppuVar16 = &puStack_64;
          }
          puVar24 = ppuVar16[1];
          if ((*ppuVar16 == (undefined4 *)0x0) || (*ppuVar16 != puVar19)) {
            FUN_0047a948();
          }
          if (puVar24 == puStack_70) {
            bVar27 = false;
          }
          FUN_00401590((int *)&puStack_d8);
          puVar24 = puStack_cc;
        }
        if (puStack_d0 == (undefined *)0x0) {
          FUN_0047a948();
        }
        if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(puVar24 + 6) != '\0') {
          if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
            FUN_0047a948();
          }
          iVar12 = iStack_c0;
          if (puVar24[7] == 0) {
            if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
              FUN_0047a948();
            }
            iVar2 = iStack_b4;
            if (iVar12 == puVar24[0xe]) {
              if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
                FUN_0047a948();
              }
              if ((iVar2 == puVar24[0x11]) && (bVar27)) goto LAB_00426a81;
            }
          }
        }
        FUN_0040f470((int *)&puStack_d0);
      } while( true );
    }
  }
  bVar27 = false;
  _Var28 = __time64((__time64_t *)0x0);
  lVar4 = (_Var28 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)) + 10000;
  piStack_a0 = (int *)((ulonglong)lVar4 >> 0x20);
  SEND_LOG(&pvStack_98,(wchar_t *)"Could not find matching sequence");
  pvVar9 = pvStack_98;
  piVar11 = (int *)((int)pvStack_98 + -0x10);
  puStack_a4 = (undefined4 *)lVar4;
  puVar19 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_98 + -0x10) + 0x10))();
  if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar19 != (undefined4 *)*piVar11)) {
    piVar20 = (int *)(**(code **)*puVar19)();
    if (piVar20 == (int *)0x0) {
      ErrorExit();
    }
    piVar20[1] = *(int *)((int)pvVar9 + -0xc);
    rVar21 = *(int *)((int)pvVar9 + -0xc) + 1;
    _memcpy_s(piVar20 + 4,rVar21,pvVar9,rVar21);
  }
  else {
    LOCK();
    *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
    UNLOCK();
    piVar20 = piVar11;
  }
  piStack_a0 = piVar20 + 4;
  local_4._0_1_ = 0xf;
  BuildAllianceMsg(&DAT_00bbf638,&pvStack_74,(int *)&puStack_a4);
  local_4._0_1_ = 8;
  piVar1 = piVar20 + 3;
  LOCK();
  iVar12 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar12 == 1 || iVar12 + -1 < 0) {
    (**(code **)(*(int *)*piVar20 + 4))();
  }
  goto LAB_0042705f;
LAB_00426a81:
  if (puVar24 == *(undefined4 **)(puStack_d0 + 4)) {
    FUN_0047a948();
  }
  cVar3 = *(char *)((int)ppiStack_ac[1] + 0x21);
  puStack_8c = (undefined4 *)puVar24[4];
  piVar11 = ppiStack_ac[1];
  while (cVar3 == '\0') {
    FUN_00410d70((int *)piVar11[2]);
    piVar20 = (int *)*piVar11;
    FreeList((void **)(piVar11 + 3));
    _free(piVar11);
    piVar11 = piVar20;
    cVar3 = *(char *)((int)piVar20 + 0x21);
  }
  ppiStack_ac[1] = (int *)ppiStack_ac;
  uStack_a8 = 0;
  *ppiStack_ac = (int *)ppiStack_ac;
  ppiStack_ac[2] = (int *)ppiStack_ac;
  ppiStack_d4 = (int **)*ppiStack_c4;
  puStack_d8 = auStack_c8;
  while( true ) {
    ppiVar8 = ppiStack_c4;
    ppiVar7 = ppiStack_d4;
    puVar23 = puStack_d8;
    if ((puStack_d8 == (undefined1 *)0x0) || (puStack_d8 != auStack_c8)) {
      FUN_0047a948();
    }
    if (ppiVar7 == ppiVar8) break;
    if (puVar23 == (undefined1 *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar7 == *(int ***)(puVar23 + 4)) {
      FUN_0047a948();
    }
    FUN_00465f60(&pvStack_44,ppiVar7 + 3);
    uStack_34 = 1;
    local_4._0_1_ = 0xc;
    FUN_0041a100(auStack_b0,&pvStack_74,&pvStack_44);
    local_4._0_1_ = 8;
    FreeList(&pvStack_44);
    FUN_00401590((int *)&puStack_d8);
  }
  ppiStack_d4 = (int **)*ppiStack_b8;
  puStack_d8 = auStack_bc;
  while( true ) {
    ppiVar8 = ppiStack_b8;
    ppiVar7 = ppiStack_d4;
    puVar23 = puStack_d8;
    if ((puStack_d8 == (undefined1 *)0x0) || (puStack_d8 != auStack_bc)) {
      FUN_0047a948();
    }
    if (ppiVar7 == ppiVar8) break;
    if (puVar23 == (undefined1 *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar7 == *(int ***)(puVar23 + 4)) {
      FUN_0047a948();
    }
    FUN_00465f60(&pvStack_44,ppiVar7 + 3);
    uStack_34 = 0;
    local_4._0_1_ = 0xd;
    FUN_0041a100(auStack_b0,&pvStack_74,&pvStack_44);
    local_4._0_1_ = 8;
    FreeList(&pvStack_44);
    FUN_00401590((int *)&puStack_d8);
  }
  cVar3 = *(char *)((int)DAT_00bb65f0[1] + 0xe9);
  puVar19 = (undefined4 *)DAT_00bb65f0[1];
  piStack_a0 = DAT_00bb65f0;
  while (puVar24 = puVar19, cVar3 == '\0') {
    if ((int)puVar24[4] < (int)puStack_8c) {
      puVar19 = (undefined4 *)puVar24[2];
      puVar24 = piStack_a0;
    }
    else {
      puVar19 = (undefined4 *)*puVar24;
    }
    cVar3 = *(char *)((int)puVar19 + 0xe9);
    piStack_a0 = puVar24;
  }
  puStack_a4 = (undefined4 *)&DAT_00bb65ec;
  if ((piStack_a0 == DAT_00bb65f0) || ((int)puStack_8c < piStack_a0[4])) {
    puStack_60 = DAT_00bb65f0;
    puStack_64 = (undefined4 *)&DAT_00bb65ec;
    ppuVar16 = &puStack_64;
  }
  else {
    ppuVar16 = &puStack_a4;
  }
  puVar19 = *ppuVar16;
  puVar24 = ppuVar16[1];
  if (puVar19 == (undefined4 *)0x0) {
    FUN_0047a948();
  }
  if (puVar24 == (undefined4 *)puVar19[1]) {
    FUN_0047a948();
  }
  puStack_8c = (undefined4 *)(uint)*(byte *)(puVar24 + 0x34);
  if (puVar24 == (undefined4 *)puVar19[1]) {
    FUN_0047a948();
  }
  if (0 < (int)puVar24[0x27]) {
    if (puVar24 == (undefined4 *)puVar19[1]) {
      FUN_0047a948();
    }
    piStack_a0 = DAT_00bb65f0;
    if (*(char *)((int)DAT_00bb65f0[1] + 0xe9) == '\0') {
      puVar17 = (undefined4 *)DAT_00bb65f0[1];
      do {
        if ((int)puVar17[4] < (int)puVar24[0x27]) {
          puVar18 = (undefined4 *)puVar17[2];
        }
        else {
          puVar18 = (undefined4 *)*puVar17;
          piStack_a0 = puVar17;
        }
        puVar17 = puVar18;
      } while (*(char *)((int)puVar18 + 0xe9) == '\0');
    }
    puStack_a4 = (undefined4 *)&DAT_00bb65ec;
    if ((piStack_a0 == DAT_00bb65f0) || ((int)puVar24[0x27] < piStack_a0[4])) {
      puStack_64 = (undefined4 *)&DAT_00bb65ec;
      puStack_94 = &DAT_00bb65ec;
      puStack_90 = DAT_00bb65f0;
      puStack_60 = DAT_00bb65f0;
    }
    else {
      puStack_94 = &DAT_00bb65ec;
      puStack_90 = piStack_a0;
    }
  }
  puVar10 = puStack_94;
  if (puVar24 == (undefined4 *)puVar19[1]) {
    FUN_0047a948();
  }
  puVar17 = DAT_00bb65f0;
  if ((int)puVar24[0x27] < 1) {
LAB_00426e2e:
    if (puVar24 == (undefined4 *)puVar19[1]) {
      FUN_0047a948();
    }
    iVar12 = puVar24[(int)local_84 + 0x12];
    bVar27 = puVar24 == (undefined4 *)puVar19[1];
  }
  else {
    if ((puVar10 == (undefined *)0x0) || (puVar10 != &DAT_00bb65ec)) {
      FUN_0047a948();
    }
    if (puStack_90 == puVar17) goto LAB_00426e2e;
    if (puVar10 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puStack_90 == *(undefined4 **)(puVar10 + 4)) {
      FUN_0047a948();
    }
    if ((int)puStack_90[(int)local_84 + 0x12] < -79999) goto LAB_00426e2e;
    if (puStack_90 == *(undefined4 **)(puVar10 + 4)) {
      FUN_0047a948();
    }
    if ((int)puStack_90[(int)puStack_8c + 0x12] < -79999) goto LAB_00426e2e;
    if (puVar24 == (undefined4 *)puVar19[1]) {
      FUN_0047a948();
    }
    if (puStack_90 == *(undefined4 **)(puVar10 + 4)) {
      FUN_0047a948();
    }
    puVar17 = puStack_90;
    iVar12 = puVar24[(int)local_84 + 0x12] - puStack_90[(int)local_84 + 0x12];
    if (puVar24 == (undefined4 *)puVar19[1]) {
      FUN_0047a948();
    }
    bVar27 = puVar17 == *(undefined4 **)(puStack_94 + 4);
  }
  if (bVar27) {
    FUN_0047a948();
  }
  _Var28 = __time64((__time64_t *)0x0);
  lVar4 = (_Var28 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)) + 10000;
  piStack_a0 = (int *)((ulonglong)lVar4 >> 0x20);
  if (puVar24 == (undefined4 *)puVar19[1]) {
    FUN_0047a948();
  }
  SEND_LOG(&pvStack_98,(wchar_t *)"Our Delta value for sequence (%d) is (%d)");
  pvVar9 = pvStack_98;
  piVar11 = (int *)((int)pvStack_98 + -0x10);
  puStack_a4 = (undefined4 *)lVar4;
  puVar19 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_98 + -0x10) + 0x10))();
  if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar19 != (undefined4 *)*piVar11)) {
    piVar20 = (int *)(**(code **)*puVar19)();
    if (piVar20 == (int *)0x0) {
      ErrorExit();
    }
    piVar20[1] = *(int *)((int)pvVar9 + -0xc);
    rVar21 = *(int *)((int)pvVar9 + -0xc) + 1;
    _memcpy_s(piVar20 + 4,rVar21,pvVar9,rVar21);
  }
  else {
    LOCK();
    *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
    UNLOCK();
    piVar20 = piVar11;
  }
  piStack_a0 = piVar20 + 4;
  local_4._0_1_ = 0xe;
  BuildAllianceMsg(&DAT_00bbf638,&pvStack_74,(int *)&puStack_a4);
  local_4._0_1_ = 8;
  piVar1 = piVar20 + 3;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(*(int *)*piVar20 + 4))();
  }
  if (iVar12 < -199) {
    if (iVar12 < -99999) {
      bVar27 = false;
      bVar5 = true;
    }
    else if (iVar12 < -89999) {
      bVar27 = false;
      bVar6 = true;
    }
    else {
      bVar27 = false;
    }
  }
  else {
    bVar27 = true;
  }
LAB_0042705f:
  local_84 = &stack0xffffff04;
  FUN_004220e0(&stack0xffffff04,(int)auStack_b0);
  puStack_8c = &uStack_10c;
  local_4._0_1_ = 0x10;
  uStack_114 = 0x427093;
  FUN_00465f60(&uStack_10c,(void **)&stack0x0000001c);
  puStack_d8 = &stack0xfffffef0;
  puStack_d0 = auStack_120;
  local_4._0_1_ = 0x12;
  FUN_00465f60(auStack_120,(void **)&stack0x00000008);
  local_4 = CONCAT31(local_4._1_3_,8);
  iVar12 = FUN_00426140(local_30);
  if (bVar27) {
    uVar22 = YES;
    if (iVar12 < 0) {
      _Var28 = __time64((__time64_t *)0x0);
      lVar4 = (_Var28 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)) + 10000;
      piStack_a0 = (int *)((ulonglong)lVar4 >> 0x20);
      SEND_LOG(&pvStack_98,L"This proposal is now non-legit (%d)");
      pvVar9 = pvStack_98;
      piVar11 = (int *)((int)pvStack_98 + -0x10);
      puStack_a4 = (undefined4 *)lVar4;
      puVar19 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_98 + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar19 != (undefined4 *)*piVar11)) {
        piVar20 = (int *)(**(code **)*puVar19)();
        if (piVar20 == (int *)0x0) {
          ErrorExit();
        }
        piVar20[1] = *(int *)((int)pvVar9 + -0xc);
        rVar21 = *(int *)((int)pvVar9 + -0xc) + 1;
        _memcpy_s(piVar20 + 4,rVar21,pvVar9,rVar21);
      }
      else {
        LOCK();
        *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
        UNLOCK();
        piVar20 = piVar11;
      }
      piStack_a0 = piVar20 + 4;
      local_4._0_1_ = 0x13;
      BuildAllianceMsg(&DAT_00bbf638,&pvStack_74,(int *)&puStack_a4);
      local_4 = CONCAT31(local_4._1_3_,8);
      piVar1 = piVar20 + 3;
      LOCK();
      iVar12 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar12 == 1 || iVar12 + -1 < 0) {
        (**(code **)(*(int *)*piVar20 + 4))();
      }
      goto LAB_004271da;
    }
  }
  else {
LAB_004271da:
    if (bVar5) {
      *param_1 = HUH;
      goto LAB_00427221;
    }
    uVar22 = REJ;
    if (bVar6) {
      *param_1 = BWX;
      goto LAB_00427221;
    }
  }
  *param_1 = uVar22;
LAB_00427221:
  local_4._0_1_ = 7;
  uStack_108 = 0x427246;
  FUN_0041abc0(auStack_b0,&pvStack_74,auStack_b0,(int **)*ppiStack_ac,auStack_b0,ppiStack_ac);
  _free(ppiStack_ac);
  ppiStack_ac = (int **)0x0;
  uStack_a8 = 0;
  local_4._0_1_ = 6;
  uStack_108 = 0x427282;
  FUN_00419cb0(auStack_bc,&pvStack_74,auStack_bc,(int **)*ppiStack_b8,auStack_bc,ppiStack_b8);
  _free(ppiStack_b8);
  ppiStack_b8 = (int **)0x0;
  iStack_b4 = 0;
  local_4._0_1_ = 5;
  uStack_108 = 0x4272bc;
  FUN_00419cb0(auStack_c8,&pvStack_74,auStack_c8,(int **)*ppiStack_c4,auStack_c8,ppiStack_c4);
  _free(ppiStack_c4);
  ppiStack_c4 = (int **)0x0;
  iStack_c0 = 0;
  local_4._0_1_ = 4;
  FreeList(apvStack_1c);
  local_4._0_1_ = 3;
  FreeList(apvStack_54);
  local_4._0_1_ = 2;
  uStack_108 = 0x42731e;
  FUN_00419cb0(auStack_80,&pvStack_74,auStack_80,(int **)*ppiStack_7c,auStack_80,ppiStack_7c);
  _free(ppiStack_7c);
  ppiStack_7c = (int **)0x0;
  uStack_78 = 0;
  local_4._0_1_ = 1;
  piVar20 = piVar11 + 3;
  LOCK();
  iVar12 = *piVar20;
  *piVar20 = *piVar20 + -1;
  UNLOCK();
  if (iVar12 == 1 || iVar12 + -1 < 0) {
    (**(code **)(*(int *)*piVar11 + 4))();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

