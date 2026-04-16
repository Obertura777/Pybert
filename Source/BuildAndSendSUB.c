
/* WARNING: Removing unreachable block (ram,0x004583ab) */
/* WARNING: Removing unreachable block (ram,0x00457cdb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall BuildAndSendSUB(void *param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined1 *puVar7;
  bool bVar8;
  ushort uVar9;
  int *piVar10;
  int iVar11;
  short *psVar12;
  uint **ppuVar13;
  int iVar14;
  void **ppvVar15;
  uint uVar16;
  undefined **ppuVar17;
  undefined4 *puVar18;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar19;
  int iVar20;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar21;
  void *pvVar22;
  int iVar23;
  undefined *puVar24;
  undefined *puVar25;
  undefined4 *puVar26;
  __time64_t _Var27;
  undefined8 uVar28;
  ulonglong uVar29;
  undefined1 auStack_418 [4];
  undefined4 uStack_414;
  undefined4 in_stack_fffffbf4;
  int **ppiVar30;
  undefined4 *puVar31;
  int **in_stack_fffffc00;
  int **in_stack_fffffc04;
  int *piStack_3dc;
  void *local_3d8;
  undefined1 *puStack_3d4;
  undefined4 uStack_3d0;
  uint local_3cc;
  undefined4 uStack_3c8;
  uint local_3c4;
  undefined *puStack_3c0;
  undefined4 *puStack_3bc;
  undefined *puStack_3b8;
  undefined *puStack_3b4;
  undefined *puStack_3b0;
  undefined4 *puStack_3ac;
  int *piStack_3a8;
  undefined *puStack_3a4;
  undefined4 *puStack_3a0;
  ushort uStack_39c;
  ushort uStack_39a;
  uint uStack_398;
  int iStack_394;
  void *local_390 [4];
  int iStack_380;
  short asStack_37a [3];
  int iStack_374;
  undefined *puStack_370;
  undefined4 *puStack_36c;
  undefined *puStack_368;
  undefined4 *puStack_364;
  undefined *puStack_360;
  undefined4 uStack_35c;
  undefined *puStack_358;
  undefined4 *puStack_354;
  undefined1 auStack_350 [4];
  undefined4 uStack_34c;
  int iStack_348;
  undefined1 auStack_344 [4];
  int iStack_340;
  undefined4 uStack_33c;
  undefined1 auStack_338 [4];
  int iStack_334;
  undefined4 uStack_330;
  int iStack_328;
  undefined4 uStack_324;
  undefined4 auStack_320 [21];
  undefined4 uStack_2cc;
  undefined1 auStack_2c8 [16];
  undefined1 uStack_2b8;
  __time64_t _Stack_2b0;
  undefined1 auStack_2a8 [16];
  ushort uStack_298;
  undefined1 auStack_294 [24];
  void *apvStack_27c [4];
  void *apvStack_26c [4];
  void *apvStack_25c [4];
  void *apvStack_24c [4];
  undefined1 *puStack_23c;
  undefined *puStack_234;
  void *apvStack_230 [4];
  void *apvStack_220 [4];
  void *apvStack_210 [4];
  void *apvStack_200 [4];
  void *apvStack_1f0 [4];
  int *apiStack_1e0 [2];
  uint *apuStack_1d8 [4];
  uint *apuStack_1c8 [4];
  int *apiStack_1b8 [2];
  uint *apuStack_1b0 [4];
  int *apiStack_1a0 [2];
  uint *apuStack_198 [4];
  void *apvStack_188 [2];
  void *apvStack_180 [4];
  uint *apuStack_170 [4];
  void *apvStack_160 [4];
  void *apvStack_150 [3];
  int *apiStack_144 [3];
  void *apvStack_138 [3];
  void *apvStack_12c [3];
  int *apiStack_120 [3];
  void *apvStack_114 [3];
  int *apiStack_108 [3];
  void *apvStack_fc [3];
  int aiStack_f0 [2];
  undefined1 auStack_e8 [212];
  void *local_14;
  undefined1 *puStack_10;
  int local_c;

  local_c = 0xffffffff;
  puStack_10 = &LAB_00498008;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_3c4 = 0;
  local_3d8 = param_1;
  FUN_00465870(local_390);
  local_3cc = (uint)*(byte *)(*(int *)((int)param_1 + 8) + 0x2424);
  local_c = 0;
  piVar10 = FUN_0047020b();
  if (piVar10 == (int *)0x0) {
    in_stack_fffffc04 = (int **)0x457907;
    piVar10 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_380 = (**(code **)(*piVar10 + 0xc))();
  iStack_380 = iStack_380 + 0x10;
  local_c._0_1_ = 1;
  FUN_00465870(apvStack_26c);
  local_c._0_1_ = 2;
  FUN_00422960((int)auStack_350);
  local_c._0_1_ = 3;
  FUN_00465870(apvStack_27c);
  local_c._0_1_ = 4;
  FUN_00465870(apvStack_24c);
  local_c._0_1_ = 5;
  FUN_00465870(apvStack_25c);
  local_c = CONCAT31(local_c._1_3_,6);
  ScheduledPressDispatch(param_1);
  puVar18 = (undefined4 *)*DAT_00bb65f0;
  puStack_3c0 = &DAT_00bb65ec;
  puStack_3bc = puVar18;
  pvVar22 = local_3d8;
LAB_004579a9:
  do {
    puVar24 = puStack_3c0;
    puVar31 = DAT_00bb65f0;
    if ((puStack_3c0 == (undefined *)0x0) || (puStack_3c0 != &DAT_00bb65ec)) {
      FUN_0047a948();
    }
    if (puVar18 == puVar31) {
LAB_004591b3:
      AwaitPressAndSendGOF(pvVar22);
      local_c._0_1_ = 5;
      FreeList(apvStack_25c);
      local_c._0_1_ = 4;
      FreeList(apvStack_24c);
      local_c._0_1_ = 3;
      FreeList(apvStack_27c);
      local_c._0_1_ = 2;
      DestroyAllianceRecord((int)auStack_350);
      local_c._0_1_ = 1;
      FreeList(apvStack_26c);
      local_c = (uint)local_c._1_3_ << 8;
      piVar10 = (int *)(iStack_380 + -4);
      LOCK();
      iVar11 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
      if (iVar11 == 1 || iVar11 + -1 < 0) {
        (**(code **)(**(int **)(iStack_380 + -0x10) + 4))();
      }
      local_c = 0xffffffff;
      FreeList(local_390);
      ExceptionList = local_14;
      return;
    }
    bVar8 = CheckTimeLimit();
    if (bVar8) goto LAB_004591b3;
    if (puVar24 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
      FUN_0047a948();
    }
    if (*(char *)(puVar18 + 6) == '\0') {
      while( true ) {
        if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
          FUN_0047a948();
        }
        if (DAT_004c6bbc <= (int)puVar18[8]) break;
        bVar8 = CheckTimeLimit();
        if (bVar8) break;
        if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
          FUN_0047a948();
        }
        DAT_0062cc64 = puVar18[8];
        if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
          FUN_0047a948();
        }
        if (puVar18 + 9 != (undefined4 *)&DAT_00bc1e00) {
          in_stack_fffffc00 = (int **)*DAT_00bc1e04;
          in_stack_fffffbf4 = 0x457a64;
          SerializeOrders(&DAT_00bc1e00,apvStack_188,&DAT_00bc1e00,in_stack_fffffc00,&DAT_00bc1e00,
                          DAT_00bc1e04);
          in_stack_fffffc04 = (int **)0x457a6c;
          RegisterProposalOrders(&DAT_00bc1e00,(int)(puVar18 + 9));
        }
        if (DAT_0062cc64 == 0) {
          if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
            FUN_0047a948();
          }
          puVar24 = puStack_3c0;
          if (puVar18[4] != 0) {
            if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
              FUN_0047a948();
            }
            piStack_3a8 = (int *)&stack0xfffffc00;
            puVar31 = puVar18 + 0xf;
            ppiVar30 = (int **)0x457ab1;
            FUN_0041c3c0(&stack0xfffffc00,(int)puVar31);
            local_c._0_1_ = 7;
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              puVar31 = (undefined4 *)0x457ac3;
              FUN_0047a948();
            }
            piStack_3dc = (int *)&stack0xfffffbf4;
            uStack_414 = 0x457ad5;
            FUN_0041c3c0(&stack0xfffffbf4,(int)(puVar18 + 0xc));
            local_c = CONCAT31(local_c._1_3_,6);
            ScoreOrderCandidates
                      (pvVar22,in_stack_fffffbf4,ppiVar30,puVar31,in_stack_fffffc00,
                       in_stack_fffffc04);
            iVar11 = *(int *)(*(int *)((int)pvVar22 + 8) + 0x2404);
            iVar23 = 0;
            do {
              iVar20 = 0;
              iVar14 = iVar23;
              if (0 < iVar11) {
                do {
                  *(undefined4 *)((int)&DAT_00bbf690 + iVar14) =
                       *(undefined4 *)((int)&DAT_00bc0a40 + iVar14);
                  *(undefined4 *)((int)&DAT_00bbf694 + iVar14) =
                       *(undefined4 *)((int)&DAT_00bc0a44 + iVar14);
                  iVar11 = *(int *)(*(int *)((int)pvVar22 + 8) + 0x2404);
                  iVar20 = iVar20 + 1;
                  iVar14 = iVar14 + 0xf0;
                } while (iVar20 < iVar11);
              }
              iVar23 = iVar23 + 8;
            } while (iVar23 < 0xf0);
          }
          piStack_3dc = (int *)0x0;
          if (0 < *(int *)(*(int *)((int)pvVar22 + 8) + 0x2404)) {
            do {
              piVar10 = piStack_3dc;
              ppiVar30 = DAT_00bc1e04;
              if (0 < (int)(&DAT_0062e460)[(int)piStack_3dc]) {
                in_stack_fffffc04 = apiStack_1a0;
                in_stack_fffffc00 = (int **)0x457b77;
                puVar31 = (undefined4 *)
                          GameBoard_GetPowerRec
                                    (&DAT_00bc1e00,(int *)in_stack_fffffc04,(int *)&piStack_3dc);
                if (((undefined *)*puVar31 == (undefined *)0x0) ||
                   ((undefined *)*puVar31 != &DAT_00bc1e00)) {
                  FUN_0047a948();
                }
                if ((int **)puVar31[1] != ppiVar30) {
                  in_stack_fffffc00 = (int **)0x457b9e;
                  FUN_00424850(piVar10,'\0');
                  in_stack_fffffc04 = (int **)0x457ba6;
                  RefreshOrderTable((int)piVar10);
                  g_CumScore = g_CumScore + (&DAT_00b9fe88)[(int)piVar10];
                }
              }
              piStack_3dc = (int *)((int)piVar10 + 1);
              pvVar22 = local_3d8;
            } while ((int)piStack_3dc < *(int *)(*(int *)((int)local_3d8 + 8) + 0x2404));
          }
        }
        *(int *)(&DAT_00b95368 + DAT_0062cc64 * 4) = g_CumScore - g_ScoreBaseline;
        UpdateScoreState(pvVar22);
        iVar11 = DAT_0062cc64;
        iVar23 = DAT_0062e4b4 - _DAT_00baed4c;
        _DAT_00baed4c = DAT_0062e4b4;
        *(int *)(&DAT_00b95458 + DAT_0062cc64 * 4) = iVar23;
        iVar23 = g_ScoreBaseline - _DAT_00baed50;
        _DAT_00baed50 = g_ScoreBaseline;
        *(int *)(&DAT_00b953e0 + iVar11 * 4) = iVar23;
        puStack_3a0 = (undefined4 *)*DAT_00bbf60c;
        puStack_3a4 = &g_CandidateRecordList;
        while( true ) {
          puVar5 = puStack_3a0;
          puVar24 = puStack_3a4;
          puVar31 = DAT_00bbf60c;
          if ((puStack_3a4 == (undefined *)0x0) || (puStack_3a4 != &g_CandidateRecordList)) {
            FUN_0047a948();
          }
          pvVar22 = local_3d8;
          if (puVar5 == puVar31) break;
          if (puVar24 == (undefined *)0x0) {
            FUN_0047a948();
          }
          if (puVar5 == *(undefined4 **)(puVar24 + 4)) {
            FUN_0047a948();
            if (puVar5 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
          }
          puVar5[DAT_0062cc64 + 0x17] = puVar5[0x71];
          FUN_0040f260((int *)&puStack_3a4);
        }
        ScheduledPressDispatch(local_3d8);
        if (0 < DAT_00624ef4) {
          in_stack_fffffc04 = (int **)0x457cb9;
          _Var27 = __time64((__time64_t *)0x0);
          if ((longlong)(DAT_00624ef4 + -10) < _Var27 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)) {
            if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
              FUN_0047a948();
            }
            uVar16 = local_3cc;
            if (puVar18[4] == 0) {
              iVar11 = local_3cc * 0x3c;
              if ((&DAT_00bbf690)[iVar11] == 0) {
                FUN_0047a948();
              }
              if ((&DAT_00bbf694)[uVar16 * 0x3c] == *(int *)((&DAT_00bbf690)[iVar11] + 4)) {
                FUN_0047a948();
              }
              in_stack_fffffc04 = (int **)0x457d2c;
              AppendList(local_390,(void **)((&DAT_00bbf694)[uVar16 * 0x3c] + 0xc));
              iVar11 = TokenSeq_Count((int)local_390);
              if (1 < iVar11) {
                in_stack_fffffc04 = (int **)0x457d46;
                SendDM(pvVar22,local_390);
              }
            }
          }
        }
        DAT_0062cc64 = DAT_0062cc64 + 1;
        if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
          FUN_0047a948();
        }
        puVar18[8] = DAT_0062cc64;
        puVar24 = puStack_3c0;
      }
      if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
        FUN_0047a948();
      }
      puVar24 = puStack_3c0;
      if (puVar18[8] == DAT_004c6bbc) {
        if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
          FUN_0047a948();
        }
        uVar16 = local_3cc;
        iVar11 = local_3cc * 0x3c;
        *(undefined1 *)(puVar18 + 6) = 1;
        if ((&DAT_00bbf690)[iVar11] == 0) {
          FUN_0047a948();
        }
        if ((&DAT_00bbf694)[uVar16 * 0x3c] == *(int *)((&DAT_00bbf690)[iVar11] + 4)) {
          FUN_0047a948();
        }
        AppendList(local_390,(void **)((&DAT_00bbf694)[uVar16 * 0x3c] + 0xc));
        if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
          FUN_0047a948();
        }
        in_stack_fffffc04 = (int **)0x457ded;
        AppendList(puVar18 + 0x28,local_390);
        uStack_3c8 = 0;
        if (0 < *(int *)(*(int *)((int)local_3d8 + 8) + 0x2404)) {
          do {
            puStack_3a0 = (undefined4 *)*DAT_00bbf60c;
            uStack_3d0 = (undefined1 *)0x0;
            puStack_3a4 = &g_CandidateRecordList;
            while( true ) {
              puVar5 = puStack_3a0;
              puVar24 = puStack_3a4;
              puVar31 = DAT_00bbf60c;
              if ((puStack_3a4 == (undefined *)0x0) || (puStack_3a4 != &g_CandidateRecordList)) {
                FUN_0047a948();
              }
              ppiVar30 = DAT_00bc1e04;
              if (puVar5 == puVar31) break;
              if (puVar24 == (undefined *)0x0) {
                FUN_0047a948();
              }
              if (puVar5 == *(undefined4 **)(puVar24 + 4)) {
                FUN_0047a948();
              }
              if (puVar5[7] == uStack_3c8) {
                if (puVar5 == *(undefined4 **)(puVar24 + 4)) {
                  FUN_0047a948();
                }
                if (0.0 < (float)puVar5[0x16]) {
                  if (puVar5 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                    if (puVar5 == *(undefined4 **)(puVar24 + 4)) {
                      FUN_0047a948();
                    }
                  }
                  uStack_3d0 = (undefined1 *)
                               ((float)(int)puVar5[9] * (float)puVar5[0x16] + (float)uStack_3d0);
                }
              }
              FUN_0040f260((int *)&puStack_3a4);
            }
            in_stack_fffffc04 = apiStack_1b8;
            in_stack_fffffc00 = (int **)0x457ed2;
            uVar28 = GameBoard_GetPowerRec(&DAT_00bc1e00,(int *)in_stack_fffffc04,&uStack_3c8);
            uVar21 = (undefined4)((ulonglong)uVar28 >> 0x20);
            puVar24 = (undefined *)*(undefined4 *)uVar28;
            if ((puVar24 == (undefined *)0x0) || (uVar19 = extraout_ECX, puVar24 != &DAT_00bc1e00))
            {
              FUN_0047a948();
              uVar19 = extraout_ECX_00;
              uVar21 = extraout_EDX;
            }
            puVar24 = puStack_3c0;
            if ((int **)((undefined4 *)uVar28)[1] != ppiVar30) {
              if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
                FUN_0047a948();
                uVar19 = extraout_ECX_01;
                uVar21 = extraout_EDX_00;
              }
              if (puVar18[4] == 0) {
                if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
                  FUN_0047a948();
                  uVar19 = extraout_ECX_02;
                  uVar21 = extraout_EDX_01;
                }
                uVar29 = FloatToInt64(uVar19,uVar21);
                puVar18[uStack_3c8 + 0x12] = (int)uVar29;
              }
              else if ((float)uStack_3d0 == 0.0) {
                if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
                  FUN_0047a948();
                }
                puVar18[uStack_3c8 + 0x12] = 0xfff0bdc0;
              }
              else {
                if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
                  FUN_0047a948();
                  uVar19 = extraout_ECX_03;
                  uVar21 = extraout_EDX_02;
                }
                uVar16 = uStack_3c8;
                uVar29 = FloatToInt64(uVar19,uVar21);
                puVar18[uVar16 + 0x12] = (int)uVar29;
                uStack_3c8 = uVar16;
              }
            }
            uStack_3c8 = uStack_3c8 + 1;
          } while ((int)uStack_3c8 < *(int *)(*(int *)((int)local_3d8 + 8) + 0x2404));
        }
        puVar24 = puStack_3c0;
        if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
          FUN_0047a948();
        }
        pvVar22 = local_3d8;
        if (*(char *)(puVar18 + 0x2c) == '\x01') {
          if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
            FUN_0047a948();
          }
          pvVar22 = local_3d8;
          if (puVar18[7] == 0) {
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            piStack_3a8 = (int *)&stack0xfffffbfc;
            FUN_00465f60(&stack0xfffffbfc,(void **)(puVar18 + 0x35));
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            piStack_3dc = (int *)&stack0xfffffbf8;
            local_c._0_1_ = 9;
            piVar10 = (int *)&stack0xfffffbf8;
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
              piVar10 = piStack_3dc;
            }
            piStack_3dc = piVar10;
            puStack_3d4 = auStack_418;
            FUN_00465f60(auStack_418,(void **)(puVar18 + 0x30));
            local_c = CONCAT31(local_c._1_3_,6);
            psVar12 = EvaluatePress(local_3d8,asStack_37a);
            sVar2 = *psVar12;
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            piStack_3a8 = (int *)&stack0xfffffbfc;
            in_stack_fffffbf4 = 0x458060;
            FUN_00465f60(&stack0xfffffbfc,(void **)(puVar18 + 0x35));
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            piStack_3dc = (int *)&stack0xfffffbf8;
            local_c._0_1_ = 0xb;
            piVar10 = (int *)&stack0xfffffbf8;
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              in_stack_fffffbf4 = 0x45808d;
              FUN_0047a948();
              piVar10 = piStack_3dc;
            }
            piStack_3dc = piVar10;
            puStack_3d4 = auStack_418;
            FUN_00465f60(auStack_418,(void **)(puVar18 + 0x30));
            local_c = CONCAT31(local_c._1_3_,6);
            RECEIVE_PROPOSAL();
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            ppuVar13 = FUN_00466ed0(&FRM,apuStack_1b0,puVar18 + 0x34);
            local_c._0_1_ = 0xc;
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            ppuVar13 = FUN_00466c40(ppuVar13,apuStack_1c8,(void **)(puVar18 + 0x35));
            local_c._0_1_ = 0xd;
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            ppuVar13 = FUN_00466c40(ppuVar13,apuStack_1d8,(void **)(puVar18 + 0x30));
            local_c._0_1_ = 0xe;
            AppendList(apvStack_26c,ppuVar13);
            local_c._0_1_ = 0xd;
            FreeList(apuStack_1d8);
            local_c._0_1_ = 0xc;
            FreeList(apuStack_1c8);
            local_c = CONCAT31(local_c._1_3_,6);
            FreeList(apuStack_1b0);
            if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
              FUN_0047a948();
            }
            pvVar22 = local_3d8;
            in_stack_fffffc04 = (int **)puVar18[0x2e];
            piStack_3a8 = (int *)&stack0xfffffc00;
            in_stack_fffffc00 = (int **)CONCAT22((short)((uint)in_stack_fffffc04 >> 0x10),sVar2);
            RESPOND(local_3d8,apvStack_26c,sVar2,(uint)in_stack_fffffc04,puVar18[0x2f]);
            EvaluateOrderProposalsAndSendGOF(pvVar22);
          }
        }
        if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
          FUN_0047a948();
        }
        if (((puVar18[4] == DAT_00baed60) && (0 < g_HistoryCounter)) &&
           (iVar11 = 0, 0 < *(int *)(*(int *)((int)pvVar22 + 8) + 0x2404))) {
          do {
            in_stack_fffffc04 = (int **)0x4581ee;
            SendAllyPressByPower((byte)iVar11);
            iVar11 = iVar11 + 1;
          } while (iVar11 < *(int *)(*(int *)((int)pvVar22 + 8) + 0x2404));
        }
      }
      puVar24 = puStack_3c0;
      if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
        FUN_0047a948();
      }
      pvVar22 = local_3d8;
      if (puVar18[4] == 0) {
        if (puVar18 == *(undefined4 **)(puVar24 + 4)) {
          FUN_0047a948();
        }
        pvVar22 = local_3d8;
        if ((puVar18[8] == DAT_004c6bbc) && (DAT_00baed6d == '\0')) {
          _Var27 = __time64((__time64_t *)0x0);
          uVar16 = local_3cc;
          _DAT_00ba2868 =
               ((_Var27 - CONCAT44(_DAT_00ba2874,_DAT_00ba2870)) -
               CONCAT44(_DAT_00ba287c,_DAT_00ba2878)) - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
          piVar10 = &DAT_00bbf690 + local_3cc * 0x3c;
          piStack_3a8 = piVar10;
          if ((&DAT_00bbf690)[local_3cc * 0x3c] == 0) {
            FUN_0047a948();
          }
          if ((&DAT_00bbf694)[uVar16 * 0x3c] == *(int *)(*piVar10 + 4)) {
            FUN_0047a948();
          }
          in_stack_fffffc04 = (int **)0x4582b3;
          AppendList(local_390,(void **)((&DAT_00bbf694)[uVar16 * 0x3c] + 0xc));
          iVar11 = TokenSeq_Count((int)local_390);
          pvVar6 = local_3d8;
          if (1 < iVar11) {
            in_stack_fffffc04 = (int **)0x4582d1;
            SendDM(local_3d8,local_390);
          }
          DAT_00baed6d = '\x01';
          iVar11 = 0;
          if (0 < *(int *)(*(int *)((int)pvVar6 + 8) + 0x2404)) {
            puVar31 = puVar18 + 0x12;
            do {
              if (puVar18 == *(undefined4 **)(puStack_3c0 + 4)) {
                FUN_0047a948();
              }
              (&g_PerPowerFinalScore)[iVar11] = *puVar31;
              iVar11 = iVar11 + 1;
              puVar31 = puVar31 + 1;
            } while (iVar11 < *(int *)(*(int *)((int)pvVar6 + 8) + 0x2404));
          }
          iVar11 = *(int *)(*(int *)((int)pvVar6 + 8) + 0x2404);
          iVar23 = 0;
          do {
            iVar20 = 0;
            iVar14 = iVar23;
            if (0 < iVar11) {
              do {
                *(undefined4 *)((int)&DAT_00bc0a40 + iVar14) =
                     *(undefined4 *)((int)&DAT_00bbf690 + iVar14);
                *(undefined4 *)((int)&DAT_00bc0a44 + iVar14) =
                     *(undefined4 *)((int)&DAT_00bbf694 + iVar14);
                iVar11 = *(int *)(*(int *)((int)pvVar6 + 8) + 0x2404);
                iVar20 = iVar20 + 1;
                iVar14 = iVar14 + 0xf0;
              } while (iVar20 < iVar11);
            }
            iVar23 = iVar23 + 8;
          } while (iVar23 < 0xf0);
          pvVar22 = local_3d8;
          if (0x13 < g_HistoryCounter) {
            if (DAT_00624ef4 != 0) {
              in_stack_fffffc04 = (int **)0x458385;
              _Var27 = __time64((__time64_t *)0x0);
              pvVar22 = local_3d8;
              if ((longlong)(DAT_00624ef4 + -0xf) <= _Var27 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880))
              goto LAB_004579a9;
            }
            cVar1 = *(char *)((int)*(int **)(iStack_340 + 4) + 0x11);
            piVar10 = *(int **)(iStack_340 + 4);
            while (cVar1 == '\0') {
              FUN_00401950((int *)piVar10[2]);
              piVar3 = (int *)*piVar10;
              _free(piVar10);
              piVar10 = piVar3;
              cVar1 = *(char *)((int)piVar3 + 0x11);
            }
            *(int *)(iStack_340 + 4) = iStack_340;
            uStack_33c = 0;
            *(int *)iStack_340 = iStack_340;
            *(int *)(iStack_340 + 8) = iStack_340;
            StdMap_FindOrInsert(auStack_344,apvStack_138,(int *)&local_3cc);
            iStack_348 = 0;
            auStack_350[0] = 0;
            ppuVar13 = FUN_00466f80(&SUB,apuStack_198,(void **)&DAT_00bc1e0c);
            local_c._0_1_ = 0xf;
            AppendList(auStack_2c8,ppuVar13);
            local_c._0_1_ = 6;
            FreeList(apuStack_198);
            uStack_2b8 = 0;
            FUN_00465f30(apvStack_230,&SUB);
            local_c._0_1_ = 0x10;
            AppendList(auStack_2a8,apvStack_230);
            local_c._0_1_ = 6;
            FreeList(apvStack_230);
            uVar9 = (ushort)(byte)local_3cc;
            uStack_298 = uVar9 | 0x4100;
            uStack_3c8 = CONCAT22(uStack_3c8._2_2_,uVar9) | 0x4100;
            uStack_3d0 = (undefined1 *)(CONCAT22(uStack_3d0._2_2_,uVar9) | 0x4100);
            FUN_00465f30(apvStack_200,&uStack_3d0);
            local_c._0_1_ = 0x11;
            AppendList(auStack_294,apvStack_200);
            local_c = CONCAT31(local_c._1_3_,6);
            FreeList(apvStack_200);
            _Stack_2b0 = __time64((__time64_t *)0x0);
            cVar1 = *(char *)((int)*(int **)(iStack_334 + 4) + 0x1d);
            piVar10 = *(int **)(iStack_334 + 4);
            while (cVar1 == '\0') {
              FUN_00410cf0((int *)piVar10[2]);
              piVar3 = (int *)*piVar10;
              FreeList((void **)(piVar10 + 3));
              _free(piVar10);
              piVar10 = piVar3;
              cVar1 = *(char *)((int)piVar3 + 0x1d);
            }
            *(int *)(iStack_334 + 4) = iStack_334;
            uStack_330 = 0;
            *(int *)iStack_334 = iStack_334;
            *(int *)(iStack_334 + 8) = iStack_334;
            cVar1 = *(char *)((int)*(int **)(iStack_328 + 4) + 0x1d);
            piVar10 = *(int **)(iStack_328 + 4);
            while (cVar1 == '\0') {
              FUN_00410cf0((int *)piVar10[2]);
              piVar3 = (int *)*piVar10;
              FreeList((void **)(piVar10 + 3));
              _free(piVar10);
              piVar10 = piVar3;
              cVar1 = *(char *)((int)piVar3 + 0x1d);
            }
            *(int *)(iStack_328 + 4) = iStack_328;
            uStack_324 = 0;
            *(int *)iStack_328 = iStack_328;
            *(int *)(iStack_328 + 8) = iStack_328;
            iVar23 = DAT_00bb65f4;
            iVar11 = *(int *)((int)pvVar6 + 8);
            uStack_34c = 1;
            iVar14 = 0;
            if (0 < *(int *)(iVar11 + 0x2404)) {
              do {
                auStack_320[iVar14] = 0;
                iVar14 = iVar14 + 1;
              } while (iVar14 < *(int *)(iVar11 + 0x2404));
            }
            uStack_2cc = 0xffffffff;
            aiStack_f0[0] = DAT_00bb65f4;
            BuildHostilityRecord(auStack_e8,auStack_350);
            in_stack_fffffc04 = apiStack_120;
            local_c._0_1_ = 0x12;
            in_stack_fffffc00 = (int **)0x45868e;
            SendAlliancePress(&DAT_00bb65ec,in_stack_fffffc04,aiStack_f0);
            local_c = CONCAT31(local_c._1_3_,6);
            DestroyAllianceRecord((int)auStack_e8);
            cVar1 = *(char *)((int)DAT_00bb65f0[1] + 0xe9);
            puVar18 = (undefined4 *)DAT_00bb65f0[1];
            puStack_354 = DAT_00bb65f0;
            while (puVar31 = puVar18, cVar1 == '\0') {
              if ((int)puVar31[4] < iVar23) {
                puVar18 = (undefined4 *)puVar31[2];
                puVar31 = puStack_354;
              }
              else {
                puVar18 = (undefined4 *)*puVar31;
              }
              cVar1 = *(char *)((int)puVar18 + 0xe9);
              puStack_354 = puVar31;
            }
            puStack_358 = &DAT_00bb65ec;
            if ((puStack_354 == DAT_00bb65f0) || (iVar23 < (int)puStack_354[4])) {
              puStack_36c = DAT_00bb65f0;
              puStack_370 = &DAT_00bb65ec;
              ppuVar17 = &puStack_370;
            }
            else {
              ppuVar17 = &puStack_358;
            }
            puStack_3b8 = *ppuVar17;
            puStack_3b4 = ppuVar17[1];
            puStack_3ac = (undefined4 *)*DAT_00baed98;
            puStack_3b0 = &g_ProposalHistoryMap;
            while( true ) {
              puVar31 = puStack_3ac;
              puVar25 = puStack_3b0;
              puVar24 = puStack_3b4;
              puVar18 = DAT_00baed98;
              if ((puStack_3b0 == (undefined *)0x0) || (puStack_3b0 != &g_ProposalHistoryMap)) {
                FUN_0047a948();
              }
              if (puVar31 == puVar18) break;
              uStack_3d0 = (undefined1 *)((uint)uStack_3d0 & 0xffffff00);
              if (puVar25 == (undefined *)0x0) {
                FUN_0047a948();
              }
              if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                FUN_0047a948();
              }
              uVar16 = local_3cc;
              if (puVar31[4] == local_3cc) {
                if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                  FUN_0047a948();
                }
                iVar11 = uVar16 * 0x15 + puVar31[6];
                if (((int)(&g_AllyTrustScore_Hi)[iVar11 * 2] < 0) ||
                   (((int)(&g_AllyTrustScore_Hi)[iVar11 * 2] < 1 &&
                    ((uint)(&g_AllyTrustScore)[iVar11 * 2] < 3)))) goto LAB_004587cb;
                FUN_00465f30(apvStack_220,&SUB);
                local_3c4 = local_3c4 | 1;
                local_c = CONCAT31(local_c._1_3_,0x13);
                if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                  FUN_0047a948();
                }
                in_stack_fffffc04 = (int **)0x4587c3;
                bVar8 = FUN_00465df0(puVar31 + 10,(int *)apvStack_220);
                if (!bVar8) goto LAB_004587cb;
                bVar8 = true;
              }
              else {
LAB_004587cb:
                bVar8 = false;
              }
              local_c = 6;
              if ((local_3c4 & 1) != 0) {
                local_3c4 = local_3c4 & 0xfffffffe;
                FreeList(apvStack_220);
              }
              if (bVar8) {
                piStack_3dc = (int *)0x0;
                if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                  FUN_0047a948();
                }
                in_stack_fffffc00 = (int **)0x45881c;
                ppvVar15 = (void **)GetSubList(puVar31 + 10,apvStack_180,1);
                local_c._0_1_ = 0x14;
                AppendList(apvStack_25c,ppvVar15);
                local_c = CONCAT31(local_c._1_3_,6);
                FreeList(apvStack_180);
                puStack_3d4 = (undefined1 *)0x1e;
                piVar10 = piStack_3a8;
                do {
                  if (*piVar10 == 0) {
                    FUN_0047a948();
                  }
                  if (piVar10[1] == *(int *)(*piVar10 + 4)) {
                    FUN_0047a948();
                  }
                  in_stack_fffffc04 = (int **)0x45887d;
                  AppendList(apvStack_27c,(void **)(piVar10[1] + 0xc));
                  uVar16 = FUN_00465930((int)apvStack_27c);
                  iVar11 = 0;
                  if (0 < (int)uVar16) {
                    do {
                      in_stack_fffffc00 = (int **)0x4588a6;
                      ppvVar15 = (void **)GetSubList(apvStack_27c,apvStack_160,iVar11);
                      local_c._0_1_ = 0x15;
                      AppendList(apvStack_24c,ppvVar15);
                      local_c = CONCAT31(local_c._1_3_,6);
                      FreeList(apvStack_160);
                      in_stack_fffffc04 = (int **)0x4588e3;
                      bVar8 = FUN_00465d90(apvStack_24c,(int *)apvStack_25c);
                      if (bVar8) {
                        piStack_3dc = (int *)((int)piStack_3dc + 1);
                      }
                      iVar11 = iVar11 + 1;
                    } while (iVar11 < (int)uVar16);
                  }
                  piVar10 = piVar10 + 2;
                  puStack_3d4 = (undefined1 *)((int)puStack_3d4 + -1);
                } while (puStack_3d4 != (undefined1 *)0x0);
                puStack_3d4 = (undefined1 *)0x0;
                if ((int)piStack_3dc < 3) goto LAB_00458ab2;
                uStack_3d0 = (undefined1 *)CONCAT31(uStack_3d0._1_3_,1);
LAB_00458911:
                bVar8 = true;
              }
              else {
LAB_00458ab2:
                puVar24 = puStack_3b0;
                if (puVar31 == *(undefined4 **)(puStack_3b0 + 4)) {
                  FUN_0047a948();
                }
                uVar16 = local_3cc;
                if (puVar31[6] == local_3cc) {
                  FUN_00465f30(apvStack_210,&SUB);
                  local_3c4 = local_3c4 | 2;
                  local_c = CONCAT31(local_c._1_3_,0x16);
                  if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                  }
                  in_stack_fffffc04 = (int **)0x458b05;
                  bVar8 = FUN_00465df0(puVar31 + 10,(int *)apvStack_210);
                  if (bVar8) {
                    if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                      FUN_0047a948();
                    }
                    iVar11 = puVar31[4] * 0x15 + uVar16;
                    if ((0 < (int)(&g_AllyTrustScore_Hi)[iVar11 * 2]) ||
                       ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar11 * 2] &&
                        (2 < (uint)(&g_AllyTrustScore)[iVar11 * 2])))) goto LAB_00458911;
                  }
                }
                bVar8 = false;
              }
              local_c = 6;
              if ((local_3c4 & 2) != 0) {
                local_3c4 = local_3c4 & 0xfffffffd;
                FreeList(apvStack_210);
              }
              puVar24 = puStack_3b0;
              if (bVar8) {
                piStack_3dc = (int *)0x0;
                puStack_3d4 = (undefined1 *)0x0;
                if (puVar31 == *(undefined4 **)(puStack_3b0 + 4)) {
                  FUN_0047a948();
                }
                uVar16 = (&DAT_004d2610)[puVar31[8] * 2];
                iStack_374 = (&DAT_004d2614)[puVar31[8] * 2];
                if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                  FUN_0047a948();
                }
                uStack_398 = (&g_AllyDesignation_A)[puVar31[8] * 2];
                iStack_394 = (&DAT_004d2e14)[puVar31[8] * 2];
                if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                  FUN_0047a948();
                }
                uVar4 = (&DAT_004d3610)[puVar31[8] * 2];
                if ((-1 < (int)(&DAT_004d3614)[puVar31[8] * 2]) &&
                   ((uVar4 != local_3cc ||
                    ((&DAT_004d3614)[puVar31[8] * 2] != (int)local_3cc >> 0x1f)))) {
                  if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                  }
                  puStack_3d4 = (undefined1 *)(&g_AllyTrustScore)[(puVar31[4] * 0x15 + uVar4) * 2];
                }
                if ((-1 < iStack_374) &&
                   ((uVar16 != local_3cc || (iStack_374 != (int)local_3cc >> 0x1f)))) {
                  if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                  }
                  piStack_3dc = (int *)(&g_AllyTrustScore)[(puVar31[4] * 0x15 + uVar16) * 2];
                }
                if (((iStack_394 < 0) ||
                    ((uStack_398 == local_3cc && (iStack_394 == (int)local_3cc >> 0x1f)))) ||
                   ((uVar16 == local_3cc && (iStack_374 == (int)local_3cc >> 0x1f)))) {
LAB_00458b44:
                  if ((2 < (int)piStack_3dc) || (2 < (int)puStack_3d4)) goto LAB_00458a83;
                  if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                  }
                  puStack_234 = (undefined *)(&DAT_00bb65fc)[puVar31[4] * 3];
                  piStack_3dc = (int *)(&DAT_00bb65f8 + puVar31[4] * 0xc);
                  if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                    if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                      FUN_0047a948();
                    }
                  }
                  iVar11 = puVar31[4];
                  puVar18 = (undefined4 *)((undefined4 *)(&DAT_00bb65fc)[iVar11 * 3])[1];
                  cVar1 = *(char *)((int)puVar18 + 0x1d);
                  puVar5 = (undefined4 *)(&DAT_00bb65fc)[iVar11 * 3];
                  while (cVar1 == '\0') {
                    uVar16 = FUN_00465cf0(puVar18 + 3,puVar31 + 10);
                    if ((char)uVar16 == '\0') {
                      puVar26 = (undefined4 *)*puVar18;
                    }
                    else {
                      puVar26 = (undefined4 *)puVar18[2];
                      puVar18 = puVar5;
                    }
                    puVar5 = puVar18;
                    puVar18 = puVar26;
                    cVar1 = *(char *)((int)puVar26 + 0x1d);
                  }
                  puStack_364 = puVar5;
                  puStack_368 = &DAT_00bb65f8 + iVar11 * 0xc;
                  if (puVar5 == (undefined4 *)(&DAT_00bb65fc)[iVar11 * 3]) {
LAB_00458bff:
                    uStack_35c = (&DAT_00bb65fc)[iVar11 * 3];
                    puStack_360 = &DAT_00bb65f8 + iVar11 * 0xc;
                    ppuVar17 = &puStack_360;
                  }
                  else {
                    uVar16 = FUN_00465cf0(puVar31 + 10,puVar5 + 3);
                    if ((char)uVar16 != '\0') goto LAB_00458bff;
                    ppuVar17 = &puStack_368;
                  }
                  puVar24 = ppuVar17[1];
                  if (((int *)*ppuVar17 == (int *)0x0) || ((int *)*ppuVar17 != piStack_3dc)) {
                    FUN_0047a948();
                  }
                  puVar25 = puStack_3b0;
                  if (puVar24 != puStack_234) {
                    puStack_3d4 = (undefined1 *)0xfffb6c20;
                    goto LAB_00458a91;
                  }
                  if ((char)uStack_3d0 != '\0') {
                    if (puVar31 == *(undefined4 **)(puStack_3b0 + 4)) {
                      FUN_0047a948();
                    }
                    piStack_3dc = (int *)&stack0xfffffbfc;
                    uStack_39c = *(byte *)(puVar31 + 6) | 0x4100;
                    in_stack_fffffbf4 = 0x458cf1;
                    FUN_00465f30(&stack0xfffffbfc,&uStack_39c);
                    puStack_3d4 = &stack0xfffffbf8;
                    local_c._0_1_ = 0x1a;
                    puVar7 = &stack0xfffffbf8;
                    if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                      in_stack_fffffbf4 = 0x458d12;
                      FUN_0047a948();
                      puVar7 = puStack_3d4;
                    }
                    puStack_3d4 = puVar7;
                    puStack_23c = auStack_418;
                    FUN_00465f60(auStack_418,(void **)(puVar31 + 10));
                    local_c = CONCAT31(local_c._1_3_,6);
                    puStack_3d4 = (undefined1 *)FUN_00422a90(local_3d8);
                    goto LAB_00458a91;
                  }
                  if (puVar31 == *(undefined4 **)(puStack_3b0 + 4)) {
                    FUN_0047a948();
                  }
                  uStack_39a = *(byte *)(puVar31 + 4) | 0x4100;
                  piStack_3dc = (int *)&stack0xfffffbfc;
                  in_stack_fffffbf4 = 0x458c79;
                  FUN_00465f30(&stack0xfffffbfc,&uStack_39a);
                  puStack_3d4 = &stack0xfffffbf8;
                  local_c._0_1_ = 0x18;
                  puVar7 = &stack0xfffffbf8;
                  if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                    in_stack_fffffbf4 = 0x458c9a;
                    FUN_0047a948();
                    puVar7 = puStack_3d4;
                  }
                  puStack_3d4 = puVar7;
                  uStack_3d0 = auStack_418;
                  FUN_00465f60(auStack_418,(void **)(puVar31 + 10));
                  local_c = CONCAT31(local_c._1_3_,6);
                  puStack_3d4 = (undefined1 *)FUN_00422a90(local_3d8);
LAB_00458a9c:
                  if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                    FUN_0047a948();
                  }
                  piStack_3dc = (int *)puVar31[4];
                }
                else {
                  if (puVar31 == *(undefined4 **)(puVar24 + 4)) {
                    FUN_0047a948();
                  }
                  if ((int)(&g_AllyTrustScore)[(puVar31[4] * 0x15 + uStack_398) * 2] < 3)
                  goto LAB_00458b44;
LAB_00458a83:
                  puStack_3d4 = (undefined1 *)0xfffcf2c0;
                  puVar25 = puStack_3b0;
LAB_00458a91:
                  if ((char)uStack_3d0 == '\0') goto LAB_00458a9c;
                  if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                    FUN_0047a948();
                  }
                  piStack_3dc = (int *)puVar31[6];
                }
                cVar1 = *(char *)((int)*(int **)(iStack_340 + 4) + 0x11);
                piVar10 = *(int **)(iStack_340 + 4);
                while (cVar1 == '\0') {
                  FUN_00401950((int *)piVar10[2]);
                  piVar3 = (int *)*piVar10;
                  _free(piVar10);
                  piVar10 = piVar3;
                  cVar1 = *(char *)((int)piVar3 + 0x11);
                }
                *(int *)(iStack_340 + 4) = iStack_340;
                uStack_33c = 0;
                *(int *)iStack_340 = iStack_340;
                *(int *)(iStack_340 + 8) = iStack_340;
                StdMap_FindOrInsert(auStack_344,apvStack_114,(int *)&local_3cc);
                StdMap_FindOrInsert(auStack_344,apvStack_12c,(int *)&piStack_3dc);
                iStack_348 = 0;
                cVar1 = *(char *)((int)*(int **)(iStack_334 + 4) + 0x1d);
                piVar10 = *(int **)(iStack_334 + 4);
                while (cVar1 == '\0') {
                  FUN_00410cf0((int *)piVar10[2]);
                  piVar3 = (int *)*piVar10;
                  FreeList((void **)(piVar10 + 3));
                  _free(piVar10);
                  piVar10 = piVar3;
                  cVar1 = *(char *)((int)piVar3 + 0x1d);
                }
                *(int *)(iStack_334 + 4) = iStack_334;
                uStack_330 = 0;
                *(int *)iStack_334 = iStack_334;
                *(int *)(iStack_334 + 8) = iStack_334;
                cVar1 = *(char *)((int)*(int **)(iStack_328 + 4) + 0x1d);
                piVar10 = *(int **)(iStack_328 + 4);
                while (cVar1 == '\0') {
                  FUN_00410cf0((int *)piVar10[2]);
                  piVar3 = (int *)*piVar10;
                  FreeList((void **)(piVar10 + 3));
                  _free(piVar10);
                  piVar10 = piVar3;
                  cVar1 = *(char *)((int)piVar3 + 0x1d);
                }
                *(int *)(iStack_328 + 4) = iStack_328;
                uStack_324 = 0;
                *(int *)iStack_328 = iStack_328;
                *(int *)(iStack_328 + 8) = iStack_328;
                if (puStack_3b8 == (undefined *)0x0) {
                  FUN_0047a948();
                }
                puVar24 = puStack_3b4;
                if (puStack_3b4 == *(undefined **)(puStack_3b8 + 4)) {
                  FUN_0047a948();
                }
                puVar25 = puStack_3b0;
                uStack_2cc = *(undefined4 *)(puVar24 + 0x10);
                if (puVar31 == *(undefined4 **)(puStack_3b0 + 4)) {
                  FUN_0047a948();
                }
                FUN_00419300(auStack_338,apvStack_fc,(void **)(puVar31 + 10));
                uStack_34c = 1;
                auStack_350[0] = 0;
                ppuVar13 = FUN_00466f80(&SUB,apuStack_170,(void **)&DAT_00bc1e0c);
                local_c._0_1_ = 0x1b;
                AppendList(auStack_2c8,ppuVar13);
                local_c = CONCAT31(local_c._1_3_,6);
                FreeList(apuStack_170);
                uStack_2b8 = 0;
                if (puVar31 == *(undefined4 **)(puVar25 + 4)) {
                  FUN_0047a948();
                }
                AppendList(auStack_2a8,(void **)(puVar31 + 10));
                uStack_298 = (ushort)uStack_3c8;
                uStack_3d0 = (undefined1 *)
                             (CONCAT22(uStack_3d0._2_2_,(ushort)(byte)piStack_3dc) | 0x4100);
                FUN_00465f30(apvStack_1f0,&uStack_3d0);
                local_c._0_1_ = 0x1c;
                AppendList(auStack_294,apvStack_1f0);
                local_c = CONCAT31(local_c._1_3_,6);
                FreeList(apvStack_1f0);
                puVar7 = puStack_3d4;
                iVar23 = DAT_00bb65f4;
                iVar11 = *(int *)((int)local_3d8 + 8);
                iVar14 = 0;
                if (0 < *(int *)(iVar11 + 0x2404)) {
                  do {
                    if (puStack_3d4 == (undefined1 *)0x0) {
                      auStack_320[iVar14] = 0;
                    }
                    else {
                      auStack_320[iVar14] = puStack_3d4;
                      auStack_350[0] = 1;
                      iStack_348 = DAT_004c6bbc;
                    }
                    iVar14 = iVar14 + 1;
                  } while (iVar14 < *(int *)(iVar11 + 0x2404));
                }
                aiStack_f0[0] = DAT_00bb65f4;
                BuildHostilityRecord(auStack_e8,auStack_350);
                in_stack_fffffc04 = apiStack_144;
                local_c._0_1_ = 0x1d;
                in_stack_fffffc00 = (int **)0x459061;
                SendAlliancePress(&DAT_00bb65ec,in_stack_fffffc04,aiStack_f0);
                local_c = CONCAT31(local_c._1_3_,6);
                DestroyAllianceRecord((int)auStack_e8);
                DAT_00baed60 = iVar23;
                if (puVar7 == (undefined1 *)0x0) {
                  if (puVar31 == *(undefined4 **)(puStack_3b0 + 4)) {
                    FUN_0047a948();
                  }
                  puVar25 = puStack_3b8;
                  if (puVar24 == *(undefined **)(puStack_3b8 + 4)) {
                    FUN_0047a948();
                  }
                  FUN_00419300(puVar24 + 0x3c,apvStack_150,(void **)(puVar31 + 10));
                  if (puVar24 == *(undefined **)(puVar25 + 4)) {
                    FUN_0047a948();
                  }
                  iVar11 = *(int *)(puVar24 + 0x28);
                  puVar25 = puVar24 + 0x24;
                  if (puVar24 == *(undefined **)(puStack_3b8 + 4)) {
                    FUN_0047a948();
                  }
                  in_stack_fffffc04 = apiStack_1e0;
                  in_stack_fffffc00 = (int **)0x4590e5;
                  puVar18 = (undefined4 *)
                            GameBoard_GetPowerRec
                                      (puVar25,(int *)in_stack_fffffc04,(int *)&piStack_3dc);
                  if (((undefined *)*puVar18 == (undefined *)0x0) ||
                     ((undefined *)*puVar18 != puVar25)) {
                    FUN_0047a948();
                  }
                  if (puVar18[1] == iVar11) {
                    if (puVar24 == *(undefined **)(puStack_3b8 + 4)) {
                      FUN_0047a948();
                    }
                    in_stack_fffffc04 = apiStack_108;
                    in_stack_fffffc00 = (int **)0x45911d;
                    StdMap_FindOrInsert(puVar25,in_stack_fffffc04,(int *)&piStack_3dc);
                  }
                }
              }
              FUN_0040f7f0((int *)&puStack_3b0);
            }
            if (puStack_3b8 == (undefined *)0x0) {
              FUN_0047a948();
            }
            if (puVar24 == *(undefined **)(puStack_3b8 + 4)) {
              FUN_0047a948();
            }
            if (*(int *)(puVar24 + 0x44) == 0) {
              if (puVar24 == *(undefined **)(puStack_3b8 + 4)) {
                FUN_0047a948();
              }
              puVar24[0x18] = 1;
              if (puVar24 == *(undefined **)(puStack_3b8 + 4)) {
                FUN_0047a948();
              }
              *(int *)(puVar24 + 0x20) = DAT_004c6bbc;
            }
            puVar18 = (undefined4 *)*DAT_00bb65f0;
            puStack_3c0 = &DAT_00bb65ec;
            puStack_3bc = puVar18;
            pvVar22 = local_3d8;
          }
        }
      }
      goto LAB_004579a9;
    }
    FUN_0040f470((int *)&puStack_3c0);
    puVar18 = puStack_3bc;
  } while( true );
}
