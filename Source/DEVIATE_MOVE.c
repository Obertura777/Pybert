
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall DEVIATE_MOVE(int param_1)

{
  CStringData *pCVar1;
  ushort uVar2;
  short sVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  uint uVar8;
  void *pvVar9;
  int **ppiVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  _AFX_AYGSHELL_STATE *p_Var15;
  int iVar16;
  uint uVar17;
  CStringData *pCVar18;
  rsize_t rVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  int iVar23;
  bool bVar24;
  ushort *puVar25;
  uint uStack_1c0;
  undefined4 uStack_1bc;
  int iStack_1b8;
  int iStack_1b4;
  void *pvStack_1b0;
  uint local_1ac;
  int local_1a8;
  char cStack_1a1;
  int **ppiStack_1a0;
  int **ppiStack_19c;
  int *piStack_198;
  int *piStack_190;
  int **ppiStack_18c;
  int *piStack_188;
  int iStack_184;
  int iStack_17c;
  int iStack_178;
  CStringData *pCStack_174;
  int iStack_170;
  CStringData *pCStack_16c;
  int iStack_168;
  int *piStack_164;
  int iStack_160;
  int *piStack_15c;
  int iStack_158;
  int *piStack_154;
  int iStack_150;
  CStringData *pCStack_14c;
  int iStack_148;
  int *piStack_144;
  int iStack_140;
  CStringData *pCStack_13c;
  int iStack_138;
  int *piStack_134;
  int iStack_130;
  CStringData *pCStack_12c;
  int iStack_128;
  int *piStack_124;
  int iStack_120;
  CStringData *pCStack_11c;
  int *piStack_114;
  int *piStack_10c;
  int *piStack_104;
  int *piStack_fc;
  int *piStack_f4;
  int aiStack_f0 [2];
  int aiStack_e8 [2];
  int aiStack_e0 [2];
  int aiStack_d8 [2];
  int aiStack_d0 [2];
  int aiStack_c8 [2];
  int aiStack_c0 [2];
  int aiStack_b8 [2];
  int aiStack_b0 [2];
  undefined4 auStack_a8 [3];
  undefined4 auStack_9c [3];
  undefined4 auStack_90 [3];
  undefined4 auStack_84 [3];
  undefined4 auStack_78 [3];
  undefined4 auStack_6c [3];
  undefined4 auStack_60 [3];
  undefined4 auStack_54 [3];
  undefined4 auStack_48 [3];
  undefined4 auStack_3c [3];
  undefined4 auStack_30 [3];
  undefined4 auStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_004974ff;
  local_14 = ExceptionList;
  uVar11 = DAT_004c8db8 ^ (uint)&stack0xfffffe30;
  ExceptionList = &local_14;
  local_1ac = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_1a8 = param_1;
  piVar12 = FUN_0047020b();
  if (piVar12 == (int *)0x0) {
    piVar12 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar13 = (**(code **)(*piVar12 + 0xc))(uVar11);
  pvStack_1b0 = (void *)(iVar13 + 0x10);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar21 = 0;
  iStack_c = 0;
  if (0 < iVar13) {
    iVar23 = 0;
    do {
      iVar20 = 0;
      iVar16 = iVar23;
      if (0 < iVar13) {
        do {
          sVar3 = SPR;
          *(undefined4 *)((int)&g_StabFlag + iVar16) = 0;
          *(undefined4 *)((int)&DAT_0062b7b0 + iVar16) = 0;
          *(undefined4 *)((int)&DAT_0062b0c8 + iVar16) = 0;
          *(undefined4 *)((int)&g_PeaceSignal + iVar16) = 0;
          if (sVar3 == *(short *)(*(int *)(param_1 + 8) + 0x244a)) {
            *(undefined4 *)((int)&DAT_0062c580 + iVar16) = 0;
          }
          if (FAL == *(short *)(*(int *)(param_1 + 8) + 0x244a)) {
            *(undefined4 *)((int)&DAT_0062be98 + iVar16) = 0;
          }
          iVar20 = iVar20 + 1;
          iVar16 = iVar16 + 4;
        } while (iVar20 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar21 = iVar21 + 1;
      iVar23 = iVar23 + 0x54;
    } while (iVar21 < iVar13);
  }
  iVar13 = *(int *)(param_1 + 8);
  uStack_1c0 = 0;
  if (*(int *)(iVar13 + 0x2404) < 1) {
LAB_0043bcd0:
    iStack_c = 0xffffffff;
    piVar12 = (int *)((int)pvStack_1b0 + -4);
    LOCK();
    iVar13 = *piVar12;
    *piVar12 = *piVar12 + -1;
    UNLOCK();
    if (iVar13 == 1 || iVar13 + -1 < 0) {
      (**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 4))
                ((undefined4 *)((int)pvStack_1b0 + -0x10));
    }
    ExceptionList = local_14;
    return;
  }
  do {
    iStack_1b8 = iVar13 + 0x248c;
    iStack_1b4 = **(int **)(iVar13 + 0x2490);
LAB_0043a010:
    iVar23 = iStack_1b4;
    iVar21 = iStack_1b8;
    iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x2490);
    if ((iStack_1b8 == 0) || (iStack_1b8 != *(int *)(param_1 + 8) + 0x248c)) {
      FUN_0047a948();
    }
    iVar16 = (int)uStack_1c0 >> 0x1f;
    if (iVar23 != iVar13) {
      cStack_1a1 = '\0';
      if (iVar21 == 0) {
        FUN_0047a948();
      }
      if ((iVar23 == *(int *)(iVar21 + 4)) && (FUN_0047a948(), iVar23 == *(int *)(iVar21 + 4))) {
        FUN_0047a948();
      }
      ppiStack_1a0 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)(local_1a8 + 8) + 8 +
                                        *(int *)(iVar23 + 0x10) * 0x24),(ushort *)(iVar23 + 0x14));
      piStack_188 = (int *)*ppiStack_1a0[1];
      ppiStack_18c = ppiStack_1a0;
      do {
        piVar22 = piStack_188;
        ppiVar5 = ppiStack_18c;
        piVar12 = ppiStack_1a0[1];
        if ((ppiStack_18c == (int **)0x0) || (ppiStack_18c != ppiStack_1a0)) {
          FUN_0047a948();
        }
        if (piVar22 == piVar12) goto LAB_0043a175;
        if (ppiVar5 == (int **)0x0) {
          FUN_0047a948();
        }
        if (piVar22 == ppiVar5[1]) {
          FUN_0047a948();
        }
        iStack_17c = iVar16;
        if (((&DAT_004d0e10)[piVar22[3] * 2] == uStack_1c0) &&
           ((&DAT_004d0e14)[piVar22[3] * 2] == iVar16)) {
LAB_0043a121:
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          if (*(uint *)(iVar23 + 0x18) != uStack_1c0) goto LAB_0043a152;
        }
        else {
          if (piVar22 == ppiVar5[1]) {
            FUN_0047a948();
          }
          if (((&DAT_004d1610)[piVar22[3] * 2] == uStack_1c0) &&
             ((&DAT_004d1614)[piVar22[3] * 2] == iStack_17c)) goto LAB_0043a121;
          if (piVar22 == ppiVar5[1]) {
            FUN_0047a948();
          }
          if (((&DAT_004d1e10)[piVar22[3] * 2] == uStack_1c0) &&
             ((&DAT_004d1e14)[piVar22[3] * 2] == iStack_17c)) goto LAB_0043a121;
        }
        FUN_0040f400((int *)&ppiStack_18c);
      } while( true );
    }
    iStack_1b4 = **(int **)(*(int *)(param_1 + 8) + 0x249c);
    iStack_1b8 = *(int *)(param_1 + 8) + 0x2498;
    while( true ) {
      iVar23 = iStack_1b4;
      iVar21 = iStack_1b8;
      iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x249c);
      if ((iStack_1b8 == 0) || (iStack_1b8 != *(int *)(param_1 + 8) + 0x2498)) {
        FUN_0047a948();
      }
      if (iVar23 == iVar13) break;
      if (iVar21 == 0) {
        FUN_0047a948();
      }
      if (iVar23 == *(int *)(iVar21 + 4)) {
        FUN_0047a948();
      }
      iVar20 = uStack_1c0 * 0x15;
      iVar13 = *(int *)(iVar23 + 0x18) + iVar20;
      if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar13 * 2]) &&
         ((0 < (int)(&g_AllyTrustScore_Hi)[iVar13 * 2] || ((&g_AllyTrustScore)[iVar13 * 2] != 0))))
      {
        if (iVar23 == *(int *)(iVar21 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar23 + 0x20) == 7) {
          if (iVar23 == *(int *)(iVar21 + 4)) {
            FUN_0047a948();
          }
          iVar13 = *(int *)(iVar23 + 0x24);
          if ((-1 < iVar13) &&
             ((((&DAT_004cf610)[iVar13 * 2] == uStack_1c0 && ((&DAT_004cf614)[iVar13 * 2] == iVar16)
               ) || (((&DAT_004cfe10)[iVar13 * 2] == uStack_1c0 &&
                     ((&DAT_004cfe14)[iVar13 * 2] == iVar16)))))) {
            if (iVar23 == *(int *)(iVar21 + 4)) {
              FUN_0047a948();
            }
            iVar13 = *(int *)(iVar23 + 0x18) + iVar20;
            if (((int)(&g_AllyTrustScore_Hi)[iVar13 * 2] < 1) &&
               (((int)(&g_AllyTrustScore_Hi)[iVar13 * 2] < 0 ||
                ((&g_AllyTrustScore)[iVar13 * 2] == 0)))) {
              if (iVar23 == *(int *)(iVar21 + 4)) {
                FUN_0047a948();
              }
              iVar13 = *(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0;
              if ((0 < (int)(&g_AllyTrustScore_Hi)[iVar13 * 2]) ||
                 ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar13 * 2] &&
                  ((&g_AllyTrustScore)[iVar13 * 2] != 0)))) goto LAB_0043bad4;
              if (iVar23 == *(int *)(iVar21 + 4)) {
                FUN_0047a948();
              }
              (&DAT_0062b7b0)[*(int *)(iVar23 + 0x18) + iVar20] = 1;
              if (uStack_1c0 == local_1ac) {
                if (iVar23 == *(int *)(iVar21 + 4)) {
                  FUN_0047a948();
                }
                puVar25 = (ushort *)&uStack_1bc;
                uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
                p_Var15 = _AfxAygshellState();
                GetProvinceToken(p_Var15,puVar25);
                SEND_LOG(&pvStack_1b0,
                         (wchar_t *)"We have been attacked by (%s) during the retreat phase");
                iStack_130 = 0xd;
                pCVar18 = ATL::CSimpleStringT<char,0>::CloneData
                                    ((CStringData *)((int)pvStack_1b0 + -0x10));
                pCStack_12c = pCVar18 + 0x10;
                iStack_c._0_1_ = 0xc;
                BuildAllianceMsg(&DAT_00bbf638,auStack_3c,&iStack_130);
                pCVar1 = pCVar18 + 0xc;
                LOCK();
                iVar13 = *(int *)pCVar1;
                *(int *)pCVar1 = *(int *)pCVar1 + -1;
                UNLOCK();
                goto LAB_0043bc4f;
              }
            }
            else {
LAB_0043bad4:
              if (iVar23 == *(int *)(iVar21 + 4)) {
                FUN_0047a948();
              }
              (&g_StabFlag)[*(int *)(iVar23 + 0x18) + iVar20] = 1;
              sVar3 = *(short *)(*(int *)(local_1a8 + 8) + 0x244a);
              if ((SUM == sVar3) || (FAL == sVar3)) {
                if (iVar23 == *(int *)(iVar21 + 4)) {
                  FUN_0047a948();
                }
                (&DAT_0062c580)[*(int *)(iVar23 + 0x18) + iVar20] = 1;
                if (iVar23 == *(int *)(iVar21 + 4)) {
                  FUN_0047a948();
                }
                (&DAT_0062c580)[*(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0] = 1;
              }
              sVar3 = *(short *)(*(int *)(local_1a8 + 8) + 0x244a);
              if (((AUT == sVar3) || (WIN == sVar3)) || (SPR == sVar3)) {
                if (iVar23 == *(int *)(iVar21 + 4)) {
                  FUN_0047a948();
                }
                (&DAT_0062be98)[*(int *)(iVar23 + 0x18) + iVar20] = 1;
                if (iVar23 == *(int *)(iVar21 + 4)) {
                  FUN_0047a948();
                }
                (&DAT_0062be98)[*(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0] = 1;
              }
              if (uStack_1c0 == local_1ac) {
                if (iVar23 == *(int *)(iVar21 + 4)) {
                  FUN_0047a948();
                }
                puVar25 = (ushort *)&uStack_1bc;
                uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
                p_Var15 = _AfxAygshellState();
                GetProvinceToken(p_Var15,puVar25);
                SEND_LOG(&pvStack_1b0,
                         (wchar_t *)"We have been stabbed by (%s) during the retreat phase");
                iStack_120 = 0xc;
                pCVar18 = ATL::CSimpleStringT<char,0>::CloneData
                                    ((CStringData *)((int)pvStack_1b0 + -0x10));
                pCStack_11c = pCVar18 + 0x10;
                iStack_c._0_1_ = 0xb;
                BuildAllianceMsg(&DAT_00bbf638,auStack_24,&iStack_120);
                pCVar1 = pCVar18 + 0xc;
                LOCK();
                iVar13 = *(int *)pCVar1;
                *(int *)pCVar1 = *(int *)pCVar1 + -1;
                UNLOCK();
LAB_0043bc4f:
                iStack_c = (uint)iStack_c._1_3_ << 8;
                if (iVar13 == 1 || iVar13 + -1 < 0) {
                  (**(code **)(**(int **)pCVar18 + 4))(pCVar18);
                }
              }
            }
            if (iVar23 == *(int *)(iVar21 + 4)) {
              FUN_0047a948();
            }
            iVar20 = *(int *)(iVar23 + 0x18) + iVar20;
            (&g_AllyTrustScore)[iVar20 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar20 * 2] = 0;
            if (iVar23 == *(int *)(iVar21 + 4)) {
              FUN_0047a948();
            }
            iVar13 = *(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0;
            (&g_AllyTrustScore)[iVar13 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar13 * 2] = 0;
          }
        }
      }
      UnitList_Advance(&iStack_1b8);
      param_1 = local_1a8;
    }
    iVar13 = *(int *)(param_1 + 8);
    uStack_1c0 = uStack_1c0 + 1;
    if (*(int *)(iVar13 + 0x2404) <= (int)uStack_1c0) goto LAB_0043bcd0;
  } while( true );
LAB_0043a152:
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  (&g_PeaceSignal)[uStack_1c0 * 0x15 + *(int *)(iVar23 + 0x18)] = 1;
LAB_0043a175:
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  if (*(uint *)(iVar23 + 0x18) == uStack_1c0) goto LAB_0043b8ab;
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  ppiVar7 = (int **)(uStack_1c0 * 0xc);
  ppiVar5 = ppiVar7 + 0x2ed9fe;
  ppiStack_1a0 = ppiVar7;
  puVar14 = (undefined4 *)FUN_00402140(ppiVar5,aiStack_b0,(int *)(iVar23 + 0x10));
  ppiStack_19c = (int **)*puVar14;
  piStack_198 = (int *)puVar14[1];
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  ppiVar10 = ppiStack_1a0;
  ppiVar6 = ppiStack_1a0 + 0x2eda3e;
  puVar14 = (undefined4 *)FUN_00410a60(ppiVar6,aiStack_c8,(int *)(iVar23 + 0x10));
  ppiVar4 = (int **)*puVar14;
  piStack_190 = (int *)puVar14[1];
  piStack_114 = ppiVar7[0x2ed9ff];
  if ((ppiStack_19c == (int **)0x0) || (ppiStack_19c != ppiVar5)) {
    FUN_0047a948();
  }
  if (piStack_198 == piStack_114) {
    piStack_fc = ppiVar10[0x2eda3f];
    if ((ppiVar4 == (int **)0x0) || (ppiVar4 != ppiVar6)) {
      FUN_0047a948();
    }
    if (piStack_190 == piStack_fc) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar23 + 0x20) == 2) {
LAB_0043acc1:
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        uStack_1bc = *(uint *)(iVar23 + 0x24);
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        puVar14 = (undefined4 *)FUN_00402140(ppiVar5,aiStack_d0,(int *)(iVar23 + 0x10));
        ppiVar6 = (int **)*puVar14;
        piStack_f4 = ppiVar7[0x2ed9ff];
        piVar12 = (int *)puVar14[1];
        if ((ppiVar6 == (int **)0x0) || (ppiVar6 != ppiVar5)) {
          FUN_0047a948();
        }
        if (piVar12 == piStack_f4) {
LAB_0043ad40:
          iVar13 = iStack_1b8;
          if (((((&DAT_004d0e10)[uStack_1bc * 2] == uStack_1c0) &&
               ((&DAT_004d0e14)[uStack_1bc * 2] == iVar16)) ||
              (((&DAT_004d1610)[uStack_1bc * 2] == uStack_1c0 &&
               ((&DAT_004d1614)[uStack_1bc * 2] == iVar16)))) ||
             (((&DAT_004d1e10)[uStack_1bc * 2] == uStack_1c0 &&
              ((&DAT_004d1e14)[uStack_1bc * 2] == iVar16)))) {
            uVar11 = uStack_1bc;
            if (*(char *)(*(int *)(local_1a8 + 8) + 3 + uStack_1bc * 0x24) != '\0') {
              uVar2 = *(ushort *)(*(int *)(local_1a8 + 8) + uStack_1bc * 0x24 + 0x20);
              uVar17 = uVar2 & 0xff;
              if ((char)(uVar2 >> 8) != 'A') {
                uVar17 = 0x14;
              }
              if (uVar17 == uStack_1c0) {
                if (iVar23 == *(int *)(iStack_1b8 + 4)) {
                  FUN_0047a948();
                }
                uVar11 = uStack_1bc;
                if (*(char *)(iVar23 + 0x6b) == '\x01') {
                  cStack_1a1 = '\x01';
                }
              }
            }
          }
          else {
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            if ((*(uint *)(iVar23 + 0x18) != local_1ac) && (uStack_1c0 == local_1ac)) {
              if (iVar23 == *(int *)(iVar13 + 4)) {
                FUN_0047a948();
              }
              iVar21 = *(int *)(iVar23 + 0x18);
              iVar16 = (&DAT_00bb702c)[iVar21 * 3];
              if (iVar23 == *(int *)(iVar13 + 4)) {
                FUN_0047a948();
              }
              puVar14 = (undefined4 *)
                        GameBoard_GetPowerRec
                                  (&DAT_00bb7028 + *(int *)(iVar23 + 0x18) * 0xc,aiStack_c0,
                                   &uStack_1bc);
              if (((undefined *)*puVar14 == (undefined *)0x0) ||
                 ((undefined *)*puVar14 != &DAT_00bb7028 + iVar21 * 0xc)) {
                FUN_0047a948();
              }
              uVar11 = uStack_1bc;
              if (puVar14[1] != iVar16) goto LAB_0043aeb9;
            }
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            if ((*(uint *)(iVar23 + 0x18) == local_1ac) && (uStack_1c0 != local_1ac)) {
              piVar12 = ppiStack_1a0[0x2edbcb];
              ppiVar5 = ppiStack_1a0 + 0x2edbca;
              puVar14 = (undefined4 *)GameBoard_GetPowerRec(ppiVar5,aiStack_f0,&uStack_1bc);
              if (((int **)*puVar14 == (int **)0x0) || ((int **)*puVar14 != ppiVar5)) {
                FUN_0047a948();
              }
              uVar11 = uStack_1bc;
              if ((int *)puVar14[1] != piVar12) goto LAB_0043aeb9;
            }
            uVar11 = 0xffffffff;
          }
        }
        else {
          if (ppiVar6 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar12 == ppiVar6[1]) {
            FUN_0047a948();
          }
          if (piVar12[4] != uStack_1bc) goto LAB_0043ad40;
          uVar11 = 0xffffffff;
        }
LAB_0043aeb9:
        iVar13 = iStack_1b8;
        if ((4.0 <= _g_NearEndGameFactor) && (2 < (int)(&curr_sc_cnt)[uStack_1c0]))
        goto LAB_0043aac0;
        iVar21 = uVar11 + 1;
        bVar24 = false;
        if (iVar21 == 0) {
          if ((iVar23 == *(int *)(iStack_1b8 + 4)) &&
             (FUN_0047a948(), iVar23 == *(int *)(iVar13 + 4))) {
            FUN_0047a948();
          }
          iVar21 = *(int *)(iVar23 + 0x18) * 0x100 + *(int *)(iVar23 + 0x24);
          if (((&DAT_005d98e8)[iVar21 * 2] == 2) && ((&DAT_005d98ec)[iVar21 * 2] == 0)) {
            if (iVar23 == *(int *)(iVar13 + 4)) {
              FUN_0047a948();
            }
            iVar21 = uStack_1c0 * 0x100 + *(int *)(iVar23 + 0x24);
            if ((-1 < (int)(&DAT_005d98ec)[iVar21 * 2]) &&
               ((0 < (int)(&DAT_005d98ec)[iVar21 * 2] || ((&DAT_005d98e8)[iVar21 * 2] != 0)))) {
              if (iVar23 == *(int *)(iVar13 + 4)) {
                FUN_0047a948();
              }
              (&DAT_0062b0c8)[uStack_1c0 * 0x15 + *(int *)(iVar23 + 0x18)] = 1;
              if (uStack_1c0 == local_1ac) {
                if (iVar23 == *(int *)(iVar13 + 4)) {
                  FUN_0047a948();
                }
                puVar25 = (ushort *)&uStack_1bc;
                uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
                p_Var15 = _AfxAygshellState();
                GetProvinceToken(p_Var15,puVar25);
                SEND_LOG(&pvStack_1b0,(wchar_t *)"We have unduly pressured by (%s) during this turn"
                        );
                iStack_178 = 10;
                pCVar18 = ATL::CSimpleStringT<char,0>::CloneData
                                    ((CStringData *)((int)pvStack_1b0 + -0x10));
                pCStack_174 = pCVar18 + 0x10;
                iStack_c._0_1_ = 6;
                BuildAllianceMsg(&DAT_00bbf638,auStack_60,&iStack_178);
                iStack_c = (uint)iStack_c._1_3_ << 8;
                pCVar1 = pCVar18 + 0xc;
                LOCK();
                iVar13 = *(int *)pCVar1;
                *(int *)pCVar1 = *(int *)pCVar1 + -1;
                UNLOCK();
                if (iVar13 == 1 || iVar13 + -1 < 0) {
                  (**(code **)(**(int **)pCVar18 + 4))(pCVar18);
                }
              }
            }
          }
          goto LAB_0043b8ab;
        }
      }
      else {
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar23 + 0x20) == 6) goto LAB_0043acc1;
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar23 + 0x20) == 4) {
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          uStack_1bc = *(uint *)(iVar23 + 0x30);
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          puVar14 = (undefined4 *)FUN_00410a60(ppiVar6,aiStack_d8,(int *)(iVar23 + 0x10));
          ppiVar5 = (int **)*puVar14;
          piStack_10c = ppiVar10[0x2eda3f];
          piVar12 = (int *)puVar14[1];
          if ((ppiVar5 == (int **)0x0) || (ppiVar5 != ppiVar6)) {
            FUN_0047a948();
          }
          iVar13 = iStack_1b8;
          if (piVar12 != piStack_10c) {
            if (ppiVar5 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar12 == ppiVar5[1]) {
              FUN_0047a948();
            }
            iVar13 = iStack_1b8;
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            if (piVar12[4] == *(int *)(iVar23 + 0x2c)) {
              if (piVar12 == ppiVar5[1]) {
                FUN_0047a948();
              }
              if (iVar23 == *(int *)(iVar13 + 4)) {
                FUN_0047a948();
              }
              if (piVar12[5] == *(int *)(iVar23 + 0x30)) goto LAB_0043b8ab;
            }
          }
          if (((((&DAT_004d0e10)[uStack_1bc * 2] == uStack_1c0) &&
               ((&DAT_004d0e14)[uStack_1bc * 2] == iVar16)) ||
              (((&DAT_004d1610)[uStack_1bc * 2] == uStack_1c0 &&
               ((&DAT_004d1614)[uStack_1bc * 2] == iVar16)))) ||
             (((&DAT_004d1e10)[uStack_1bc * 2] == uStack_1c0 &&
              ((&DAT_004d1e14)[uStack_1bc * 2] == iVar16)))) {
            if (iVar23 == *(int *)(iVar13 + 4)) {
              FUN_0047a948();
            }
            uVar11 = uStack_1bc;
            if (((&DAT_004d1610)[*(int *)(iVar23 + 0x2c) * 2] != uStack_1c0) ||
               (iVar13 = iStack_1b8, (&DAT_004d1614)[*(int *)(iVar23 + 0x2c) * 2] != iVar16))
            goto LAB_0043aac0;
          }
          if (iVar23 == *(int *)(iVar13 + 4)) {
            FUN_0047a948();
          }
          if ((*(uint *)(iVar23 + 0x18) != local_1ac) && (uStack_1c0 == local_1ac)) {
            if (iVar23 == *(int *)(iVar13 + 4)) {
              FUN_0047a948();
            }
            iVar21 = *(int *)(iVar23 + 0x18);
            iVar16 = (&DAT_00bb702c)[iVar21 * 3];
            if (iVar23 == *(int *)(iVar13 + 4)) {
              FUN_0047a948();
            }
            puVar14 = (undefined4 *)
                      GameBoard_GetPowerRec
                                (&DAT_00bb7028 + *(int *)(iVar23 + 0x18) * 0xc,aiStack_b8,
                                 &uStack_1bc);
            if (((undefined *)*puVar14 == (undefined *)0x0) ||
               ((undefined *)*puVar14 != &DAT_00bb7028 + iVar21 * 0xc)) {
              FUN_0047a948();
            }
            uVar11 = uStack_1bc;
            iVar13 = iStack_1b8;
            if (puVar14[1] != iVar16) goto LAB_0043aac0;
          }
          uVar11 = local_1ac;
          if (iVar23 == *(int *)(iVar13 + 4)) {
            FUN_0047a948();
          }
          if ((*(uint *)(iVar23 + 0x18) != uVar11) || (uStack_1c0 == uVar11)) goto LAB_0043b8ab;
          piVar12 = ppiStack_1a0[0x2edbcb];
          ppiVar5 = ppiStack_1a0 + 0x2edbca;
          puVar14 = (undefined4 *)GameBoard_GetPowerRec(ppiVar5,aiStack_e8,&uStack_1bc);
          if (((int **)*puVar14 == (int **)0x0) || ((int **)*puVar14 != ppiVar5)) {
            FUN_0047a948();
          }
          uVar11 = uStack_1bc;
          if ((int *)puVar14[1] == piVar12) goto LAB_0043b8ab;
        }
        else {
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          if (*(int *)(iVar23 + 0x20) != 3) goto LAB_0043b8ab;
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          uStack_1bc = *(uint *)(iVar23 + 0x2c);
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          puVar14 = (undefined4 *)FUN_00410a60(ppiVar6,aiStack_e0,(int *)(iVar23 + 0x10));
          ppiVar5 = (int **)*puVar14;
          piStack_104 = ppiVar10[0x2eda3f];
          piVar12 = (int *)puVar14[1];
          if ((ppiVar5 == (int **)0x0) || (ppiVar5 != ppiVar6)) {
            FUN_0047a948();
          }
          if (piVar12 != piStack_104) {
            if (ppiVar5 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar12 == ppiVar5[1]) {
              FUN_0047a948();
            }
            iVar13 = iStack_1b8;
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            if (piVar12[4] == *(int *)(iVar23 + 0x2c)) {
              if (piVar12 == ppiVar5[1]) {
                FUN_0047a948();
              }
              if (iVar23 == *(int *)(iVar13 + 4)) {
                FUN_0047a948();
              }
              if (piVar12[5] == *(int *)(iVar23 + 0x2c)) goto LAB_0043b8ab;
            }
          }
          if ((((&DAT_004d0e10)[uStack_1bc * 2] != uStack_1c0) ||
              ((&DAT_004d0e14)[uStack_1bc * 2] != iVar16)) ||
             ((uVar11 = uStack_1bc, (&DAT_004d1610)[uStack_1bc * 2] == uStack_1c0 &&
              ((&DAT_004d1614)[uStack_1bc * 2] == iVar16)))) goto LAB_0043b8ab;
        }
LAB_0043aac0:
        iVar21 = uVar11 + 1;
        bVar24 = uVar11 == 0xffffffff;
      }
      if (bVar24 || SBORROW4(uVar11,-1) != iVar21 < 0) goto LAB_0043b8ab;
    }
    else {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar23 + 0x20) == 4) {
        if (ppiVar4 == (int **)0x0) {
          FUN_0047a948();
        }
        if (piStack_190 == ppiVar4[1]) {
          FUN_0047a948();
        }
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        if (piStack_190[4] == *(int *)(iVar23 + 0x2c)) {
          if (piStack_190 == ppiVar4[1]) {
            FUN_0047a948();
          }
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          if (piStack_190[5] == *(int *)(iVar23 + 0x30)) goto LAB_0043b8ab;
        }
        if (uStack_1c0 == local_1ac) {
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          puVar25 = (ushort *)&uStack_1bc;
          uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
          p_Var15 = _AfxAygshellState();
          GetProvinceToken(p_Var15,puVar25);
          SEND_LOG(&pvStack_1b0,
                   (wchar_t *)"Power (%s) did not make his expected support order this turn");
          pvVar9 = pvStack_1b0;
          piVar12 = (int *)((int)pvStack_1b0 + -0x10);
          iStack_128 = 10;
          puVar14 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 0x10))();
          if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar14 != (undefined4 *)*piVar12)) {
            piVar12 = (int *)(**(code **)*puVar14)(*(undefined4 *)((int)pvVar9 + -0xc),1);
            if (piVar12 == (int *)0x0) goto LAB_0043bd12;
            piVar12[1] = *(int *)((int)pvVar9 + -0xc);
            rVar19 = *(int *)((int)pvVar9 + -0xc) + 1;
            _memcpy_s(piVar12 + 4,rVar19,pvVar9,rVar19);
          }
          else {
            LOCK();
            *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
            UNLOCK();
          }
          piVar12 = piVar12 + 4;
          iStack_c._0_1_ = 3;
          piVar22 = &iStack_128;
          puVar14 = auStack_30;
          piStack_124 = piVar12;
          goto LAB_0043a34c;
        }
      }
      else {
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar23 + 0x20) == 3) {
          if (ppiVar4 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piStack_190 == ppiVar4[1]) {
            FUN_0047a948();
          }
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          if (piStack_190[4] == *(int *)(iVar23 + 0x2c)) {
            if (piStack_190 == ppiVar4[1]) {
              FUN_0047a948();
            }
            if (piStack_190 == ppiVar4[1]) {
              FUN_0047a948();
            }
            if (piStack_190[5] == piStack_190[4]) goto LAB_0043b8ab;
          }
          if (uStack_1c0 == local_1ac) {
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            puVar25 = (ushort *)&uStack_1bc;
            uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
            p_Var15 = _AfxAygshellState();
            GetProvinceToken(p_Var15,puVar25);
            SEND_LOG(&pvStack_1b0,
                     (wchar_t *)"Power (%s) did not make his expected support order this turn");
            pvVar9 = pvStack_1b0;
            piVar12 = (int *)((int)pvStack_1b0 + -0x10);
            iStack_158 = 10;
            puVar14 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 0x10))();
            if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar14 != (undefined4 *)*piVar12)) {
              piVar12 = (int *)(**(code **)*puVar14)(*(undefined4 *)((int)pvVar9 + -0xc),1);
              if (piVar12 == (int *)0x0) goto LAB_0043bd12;
              piVar12[1] = *(int *)((int)pvVar9 + -0xc);
              rVar19 = *(int *)((int)pvVar9 + -0xc) + 1;
              _memcpy_s(piVar12 + 4,rVar19,pvVar9,rVar19);
            }
            else {
              LOCK();
              *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
              UNLOCK();
            }
            piVar12 = piVar12 + 4;
            iStack_c._0_1_ = 4;
            piVar22 = &iStack_158;
            puVar14 = auStack_78;
            piStack_154 = piVar12;
LAB_0043a34c:
            BuildAllianceMsg(&DAT_00bbf638,puVar14,piVar22);
            iStack_c = (uint)iStack_c._1_3_ << 8;
            piVar22 = piVar12 + -1;
            LOCK();
            iVar13 = *piVar22;
            *piVar22 = *piVar22 + -1;
            UNLOCK();
            if (iVar13 == 1 || iVar13 + -1 < 0) {
              (**(code **)(*(int *)piVar12[-4] + 4))(piVar12 + -4);
            }
          }
        }
        else if (uStack_1c0 == local_1ac) {
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          puVar25 = (ushort *)&uStack_1bc;
          uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
          p_Var15 = _AfxAygshellState();
          GetProvinceToken(p_Var15,puVar25);
          SEND_LOG(&pvStack_1b0,
                   (wchar_t *)"Power (%s) did not make his expected support order this turn");
          pvVar9 = pvStack_1b0;
          piVar12 = (int *)((int)pvStack_1b0 + -0x10);
          iStack_138 = 10;
          puVar14 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 0x10))();
          if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar14 != (undefined4 *)*piVar12)) {
            piVar12 = (int *)(**(code **)*puVar14)(*(undefined4 *)((int)pvVar9 + -0xc),1);
            if (piVar12 == (int *)0x0) goto LAB_0043bd12;
            piVar12[1] = *(int *)((int)pvVar9 + -0xc);
            rVar19 = *(int *)((int)pvVar9 + -0xc) + 1;
            _memcpy_s(piVar12 + 4,rVar19,pvVar9,rVar19);
          }
          else {
            LOCK();
            *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
            UNLOCK();
          }
          piVar12 = piVar12 + 4;
          iStack_c._0_1_ = 5;
          piVar22 = &iStack_138;
          puVar14 = auStack_48;
          piStack_134 = piVar12;
          goto LAB_0043a34c;
        }
      }
    }
  }
  else {
    if (iVar23 == *(int *)(iStack_1b8 + 4)) {
      FUN_0047a948();
    }
    if (*(int *)(iVar23 + 0x20) != 2) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar23 + 0x20) != 6) {
        if (uStack_1c0 == local_1ac) {
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          puVar25 = (ushort *)&uStack_1bc;
          uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
          p_Var15 = _AfxAygshellState();
          GetProvinceToken(p_Var15,puVar25);
          SEND_LOG(&pvStack_1b0,(wchar_t *)"Power (%s) did not make his expected move this turn");
          pvVar9 = pvStack_1b0;
          piVar12 = (int *)((int)pvStack_1b0 + -0x10);
          iStack_148 = 10;
          puVar14 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 0x10))();
          if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar14 != (undefined4 *)*piVar12)) {
            piVar12 = (int *)(**(code **)*puVar14)(*(undefined4 *)((int)pvVar9 + -0xc),1);
            if (piVar12 == (int *)0x0) goto LAB_0043bd12;
            piVar12[1] = *(int *)((int)pvVar9 + -0xc);
            rVar19 = *(int *)((int)pvVar9 + -0xc) + 1;
            _memcpy_s(piVar12 + 4,rVar19,pvVar9,rVar19);
          }
          else {
            LOCK();
            *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
            UNLOCK();
          }
          piVar12 = piVar12 + 4;
          iStack_c._0_1_ = 2;
          piVar22 = &iStack_148;
          puVar14 = auStack_90;
          piStack_144 = piVar12;
          goto LAB_0043a34c;
        }
        goto LAB_0043aacd;
      }
    }
    if (ppiStack_19c == (int **)0x0) {
      FUN_0047a948();
    }
    if (piStack_198 == ppiStack_19c[1]) {
      FUN_0047a948();
    }
    if (iVar23 == *(int *)(iStack_1b8 + 4)) {
      FUN_0047a948();
    }
    if (piStack_198[4] == *(int *)(iVar23 + 0x24)) goto LAB_0043b8ab;
    if (uStack_1c0 == local_1ac) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      puVar25 = (ushort *)&uStack_1bc;
      uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
      p_Var15 = _AfxAygshellState();
      GetProvinceToken(p_Var15,puVar25);
      SEND_LOG(&pvStack_1b0,(wchar_t *)"Power (%s) did not make his expected move this turn");
      pvVar9 = pvStack_1b0;
      piVar12 = (int *)((int)pvStack_1b0 + -0x10);
      iStack_168 = 10;
      puVar14 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar14 != (undefined4 *)*piVar12)) {
        piVar12 = (int *)(**(code **)*puVar14)(*(undefined4 *)((int)pvVar9 + -0xc),1);
        if (piVar12 == (int *)0x0) goto LAB_0043bd12;
        piVar12[1] = *(int *)((int)pvVar9 + -0xc);
        rVar19 = *(int *)((int)pvVar9 + -0xc) + 1;
        _memcpy_s(piVar12 + 4,rVar19,pvVar9,rVar19);
      }
      else {
        LOCK();
        *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
        UNLOCK();
      }
      piVar12 = piVar12 + 4;
      iStack_c._0_1_ = 1;
      piVar22 = &iStack_168;
      puVar14 = auStack_a8;
      piStack_164 = piVar12;
      goto LAB_0043a34c;
    }
  }
LAB_0043aacd:
  iVar13 = iStack_1b8;
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  iVar21 = uStack_1c0 * 0x15;
  iVar16 = *(int *)(iVar23 + 0x18) + iVar21;
  iStack_184 = iVar21;
  if (((int)(&g_AllyTrustScore_Hi)[iVar16 * 2] < 1) &&
     (((int)(&g_AllyTrustScore_Hi)[iVar16 * 2] < 0 || ((&g_AllyTrustScore)[iVar16 * 2] == 0)))) {
    if (iVar23 == *(int *)(iVar13 + 4)) {
      FUN_0047a948();
    }
    iVar16 = *(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0;
    if ((0 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2]) ||
       ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2] && ((&g_AllyTrustScore)[iVar16 * 2] != 0))))
    goto LAB_0043b0b2;
    if (cStack_1a1 == '\x01') {
      if (iVar23 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      if (-10 < (int)(&DAT_00634e90)[*(int *)(iVar23 + 0x18) + iVar21]) goto LAB_0043b0b2;
    }
    if (iVar23 == *(int *)(iVar13 + 4)) {
      FUN_0047a948();
    }
    (&DAT_0062b7b0)[*(int *)(iVar23 + 0x18) + iVar21] = 1;
    if (uStack_1c0 == local_1ac) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      puVar25 = (ushort *)&uStack_1bc;
      uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
      p_Var15 = _AfxAygshellState();
      GetProvinceToken(p_Var15,puVar25);
      SEND_LOG(&pvStack_1b0,(wchar_t *)"We have been attacked by (%s) during the turn");
      iStack_170 = 0xb;
      pCVar18 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_1b0 + -0x10));
      pCStack_16c = pCVar18 + 0x10;
      iStack_c._0_1_ = 10;
      BuildAllianceMsg(&DAT_00bbf638,auStack_9c,&iStack_170);
      iStack_c = (uint)iStack_c._1_3_ << 8;
      pCVar1 = pCVar18 + 0xc;
      LOCK();
      iVar13 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + -1;
      UNLOCK();
      if (iVar13 == 1 || iVar13 + -1 < 0) {
        (**(code **)(**(int **)pCVar18 + 4))(pCVar18);
      }
    }
  }
  else {
LAB_0043b0b2:
    if (iVar23 == *(int *)(iVar13 + 4)) {
      FUN_0047a948();
    }
    uVar11 = local_1ac;
    (&g_StabFlag)[*(int *)(iVar23 + 0x18) + iVar21] = 1;
    if (uStack_1c0 == local_1ac) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      puVar25 = (ushort *)&uStack_1bc;
      uStack_1bc = CONCAT22(uStack_1bc._2_2_,(ushort)*(byte *)(iVar23 + 0x18)) | 0x4100;
      p_Var15 = _AfxAygshellState();
      GetProvinceToken(p_Var15,puVar25);
      SEND_LOG(&pvStack_1b0,(wchar_t *)"We have been stabbed by (%s) during the turn");
      pvVar9 = pvStack_1b0;
      piVar12 = (int *)((int)pvStack_1b0 + -0x10);
      iStack_160 = 10;
      puVar14 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_1b0 + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar9 + -4) < 0) || (puVar14 != (undefined4 *)*piVar12)) {
        piVar12 = (int *)(**(code **)*puVar14)(*(undefined4 *)((int)pvVar9 + -0xc),1);
        if (piVar12 == (int *)0x0) {
LAB_0043bd12:
          ErrorExit();
          return;
        }
        piVar12[1] = *(int *)((int)pvVar9 + -0xc);
        rVar19 = *(int *)((int)pvVar9 + -0xc) + 1;
        _memcpy_s(piVar12 + 4,rVar19,pvVar9,rVar19);
      }
      else {
        LOCK();
        *(int *)((int)pvVar9 + -4) = *(int *)((int)pvVar9 + -4) + 1;
        UNLOCK();
      }
      piStack_15c = piVar12 + 4;
      iStack_c._0_1_ = 7;
      BuildAllianceMsg(&DAT_00bbf638,auStack_84,&iStack_160);
      iStack_c = (uint)iStack_c._1_3_ << 8;
      piVar22 = piVar12 + 3;
      LOCK();
      iVar13 = *piVar22;
      *piVar22 = *piVar22 + -1;
      UNLOCK();
      if (iVar13 == 1 || iVar13 + -1 < 0) {
        (**(code **)(*(int *)*piVar12 + 4))(piVar12);
      }
      uVar11 = 0;
      if (0 < *(int *)(*(int *)(local_1a8 + 8) + 0x2404)) {
        iVar13 = 0;
        do {
          iVar21 = iStack_1b8;
          if (uVar11 != local_1ac) {
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            iVar16 = *(int *)(iVar23 + 0x18) + iVar13;
            if ((&g_AllyTrustScore)[iVar16 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar16 * 2] == 0) {
              if (iVar23 == *(int *)(iVar21 + 4)) {
                FUN_0047a948();
              }
              if ((uVar11 != *(uint *)(iVar23 + 0x18)) && (2 < (int)(&curr_sc_cnt)[uVar11])) {
                (&DAT_004cf4c0)[uVar11 * 2] = 0;
                (&DAT_004cf4c4)[uVar11 * 2] = 0;
                puVar25 = (ushort *)&uStack_1bc;
                uStack_1bc = CONCAT22(uStack_1bc._2_2_,(short)uVar11) & 0xffff00ff | 0x4100;
                p_Var15 = _AfxAygshellState();
                GetProvinceToken(p_Var15,puVar25);
                SEND_LOG(&pvStack_1b0,
                         (wchar_t *)
                         "We have been stabbed and will try to eliminate past descresions with (%s) which we may now share an enemy with"
                        );
                iStack_150 = 10;
                pCVar18 = ATL::CSimpleStringT<char,0>::CloneData
                                    ((CStringData *)((int)pvStack_1b0 + -0x10));
                pCStack_14c = pCVar18 + 0x10;
                iStack_c._0_1_ = 8;
                BuildAllianceMsg(&DAT_00bbf638,auStack_6c,&iStack_150);
                iStack_c = (uint)iStack_c._1_3_ << 8;
                pCVar1 = pCVar18 + 0xc;
                LOCK();
                iVar21 = *(int *)pCVar1;
                *(int *)pCVar1 = *(int *)pCVar1 + -1;
                UNLOCK();
                if (iVar21 == 1 || iVar21 + -1 < 0) {
                  (**(code **)(**(int **)pCVar18 + 4))(pCVar18);
                }
              }
            }
          }
          uVar11 = uVar11 + 1;
          iVar13 = iVar13 + 0x15;
          iVar21 = iStack_184;
        } while ((int)uVar11 < *(int *)(*(int *)(local_1a8 + 8) + 0x2404));
      }
    }
    else {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      if ((uVar11 != *(uint *)(iVar23 + 0x18)) &&
         (iVar16 = uVar11 * 0x15, iVar13 = iVar16 + uStack_1c0,
         (&g_AllyTrustScore)[iVar13 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar13 * 2] == 0)) {
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        iVar16 = *(int *)(iVar23 + 0x18) + iVar16;
        if ((&g_AllyTrustScore)[iVar16 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar16 * 2] == 0) {
          if (iVar23 == *(int *)(iStack_1b8 + 4)) {
            FUN_0047a948();
          }
          if ((int)(&curr_sc_cnt)[local_1ac] <= (int)(&curr_sc_cnt)[*(int *)(iVar23 + 0x18)]) {
            if (iVar23 == *(int *)(iStack_1b8 + 4)) {
              FUN_0047a948();
            }
            if ((int)(&curr_sc_cnt)[uStack_1c0] <= (int)(&curr_sc_cnt)[*(int *)(iVar23 + 0x18)]) {
              (&DAT_004cf4c0)[uStack_1c0 * 2] = 0;
              (&DAT_004cf4c4)[uStack_1c0 * 2] = 0;
              puVar25 = (ushort *)&uStack_1bc;
              uStack_1bc = CONCAT22(uStack_1bc._2_2_,(short)uStack_1c0) & 0xffff00ff | 0x4100;
              p_Var15 = _AfxAygshellState();
              GetProvinceToken(p_Var15,puVar25);
              SEND_LOG(&pvStack_1b0,
                       (wchar_t *)
                       "(%s) has been stabbed by mutual enemy: Reset trust and turns unallied counte r"
                      );
              iStack_140 = 10;
              pCVar18 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_1b0 + -0x10));
              pCStack_13c = pCVar18 + 0x10;
              iStack_c._0_1_ = 9;
              BuildAllianceMsg(&DAT_00bbf638,auStack_54,&iStack_140);
              iStack_c = (uint)iStack_c._1_3_ << 8;
              pCVar1 = pCVar18 + 0xc;
              LOCK();
              iVar13 = *(int *)pCVar1;
              *(int *)pCVar1 = *(int *)pCVar1 + -1;
              UNLOCK();
              if (iVar13 == 1 || iVar13 + -1 < 0) {
                (**(code **)(**(int **)pCVar18 + 4))(pCVar18);
              }
            }
          }
        }
      }
    }
    iVar13 = iStack_1b8;
    sVar3 = *(short *)(*(int *)(local_1a8 + 8) + 0x244a);
    if ((SUM == sVar3) || (FAL == sVar3)) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      (&DAT_0062c580)[*(int *)(iVar23 + 0x18) + iVar21] = 1;
      if (iVar23 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      (&DAT_0062c580)[*(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0] = 1;
    }
    sVar3 = *(short *)(*(int *)(local_1a8 + 8) + 0x244a);
    if (((AUT == sVar3) || (WIN == sVar3)) || (SPR == sVar3)) {
      if (iVar23 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      (&DAT_0062be98)[*(int *)(iVar23 + 0x18) + iVar21] = 1;
      if (iVar23 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      (&DAT_0062be98)[*(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0] = 1;
    }
  }
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  iVar21 = *(int *)(iVar23 + 0x18) + iVar21;
  (&g_AllyTrustScore)[iVar21 * 2] = 0;
  (&g_AllyTrustScore_Hi)[iVar21 * 2] = 0;
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  iVar13 = *(int *)(iVar23 + 0x18) * 0x15 + uStack_1c0;
  (&g_AllyTrustScore)[iVar13 * 2] = 0;
  (&g_AllyTrustScore_Hi)[iVar13 * 2] = 0;
  if (uStack_1c0 == local_1ac) {
    if (iVar23 == *(int *)(iStack_1b8 + 4)) {
      FUN_0047a948();
    }
    iVar13 = *(int *)(iVar23 + 0x18);
    FUN_00401950(*(int **)((&DAT_00bb6f2c)[iVar13 * 3] + 4));
    *(undefined4 *)((&DAT_00bb6f2c)[iVar13 * 3] + 4) = (&DAT_00bb6f2c)[iVar13 * 3];
    (&DAT_00bb6f30)[iVar13 * 3] = 0;
    *(undefined4 *)(&DAT_00bb6f2c)[iVar13 * 3] = (&DAT_00bb6f2c)[iVar13 * 3];
    *(undefined4 *)((&DAT_00bb6f2c)[iVar13 * 3] + 8) = (&DAT_00bb6f2c)[iVar13 * 3];
    if (iVar23 == *(int *)(iStack_1b8 + 4)) {
      FUN_0047a948();
    }
    iVar13 = *(int *)(iVar23 + 0x18);
    FUN_00401950(*(int **)((&DAT_00bb702c)[iVar13 * 3] + 4));
    iVar21 = local_1a8;
    *(undefined4 *)((&DAT_00bb702c)[iVar13 * 3] + 4) = (&DAT_00bb702c)[iVar13 * 3];
    (&DAT_00bb7030)[iVar13 * 3] = 0;
    *(undefined4 *)(&DAT_00bb702c)[iVar13 * 3] = (&DAT_00bb702c)[iVar13 * 3];
    *(undefined4 *)((&DAT_00bb702c)[iVar13 * 3] + 8) = (&DAT_00bb702c)[iVar13 * 3];
    iVar13 = 0;
    if (0 < *(int *)(*(int *)(local_1a8 + 8) + 0x2404)) {
      do {
        if (iVar23 == *(int *)(iStack_1b8 + 4)) {
          FUN_0047a948();
        }
        (&g_AllyMatrix)[*(int *)(iVar23 + 0x18) * 0x15 + iVar13] = 0;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(*(int *)(iVar21 + 8) + 0x2404));
    }
  }
  uVar11 = local_1ac;
  if (iVar23 == *(int *)(iStack_1b8 + 4)) {
    FUN_0047a948();
  }
  ppiVar5 = ppiStack_1a0;
  if (*(uint *)(iVar23 + 0x18) == uVar11) {
    FUN_00401950((int *)ppiStack_1a0[0x2edbcb][1]);
    ppiVar5[0x2edbcb][1] = (int)ppiVar5[0x2edbcb];
    ppiVar5[0x2edbcc] = (int *)0x0;
    *ppiVar5[0x2edbcb] = (int)ppiVar5[0x2edbcb];
    ppiVar5[0x2edbcb][2] = (int)ppiVar5[0x2edbcb];
    FUN_00401950((int *)ppiVar5[0x2edc0b][1]);
    ppiVar5[0x2edc0b][1] = (int)ppiVar5[0x2edc0b];
    ppiVar5[0x2edc0c] = (int *)0x0;
    *ppiVar5[0x2edc0b] = (int)ppiVar5[0x2edc0b];
    ppiVar5[0x2edc0b][2] = (int)ppiVar5[0x2edc0b];
    uVar11 = local_1ac;
    if (0 < *(int *)(*(int *)(local_1a8 + 8) + 0x2404)) {
      puVar14 = &g_AllyMatrix + uStack_1c0 * 0x15;
      iVar13 = 0;
      do {
        *puVar14 = 0;
        iVar13 = iVar13 + 1;
        puVar14 = puVar14 + 1;
      } while (iVar13 < *(int *)(*(int *)(local_1a8 + 8) + 0x2404));
    }
  }
  iVar13 = iStack_1b8;
  if (uStack_1c0 == uVar11) {
    if (g_OpeningStickyMode == '\x01') {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar23 + 0x18) != g_OpeningEnemy) {
        g_OpeningStickyMode = '\0';
      }
    }
    iVar13 = iStack_1b8;
    if (-1 < (int)DAT_004c6bc4) {
      if (iVar23 == *(int *)(iStack_1b8 + 4)) {
        FUN_0047a948();
      }
      if ((*(uint *)(iVar23 + 0x18) == DAT_004c6bc4) &&
         (DAT_004c6bc4 = 0xffffffff, -1 < (int)DAT_004c6bc8)) {
        DAT_004c6bc4 = DAT_004c6bc8;
        DAT_004c6bc8 = 0xffffffff;
        if (-1 < (int)DAT_004c6bcc) {
          DAT_004c6bc8 = DAT_004c6bcc;
          DAT_004c6bcc = 0xffffffff;
        }
      }
    }
  }
  if (iVar23 == *(int *)(iVar13 + 4)) {
    FUN_0047a948();
  }
  uVar8 = DAT_004c6bcc;
  uVar17 = DAT_004c6bc8;
  if (((*(uint *)(iVar23 + 0x18) == uVar11) && (-1 < (int)DAT_004c6bc4)) &&
     ((uStack_1c0 == DAT_004c6bc4 &&
      ((DAT_004c6bc4 = 0xffffffff, -1 < (int)DAT_004c6bc8 &&
       (DAT_004c6bc8 = 0xffffffff, DAT_004c6bc4 = uVar17, -1 < (int)DAT_004c6bcc)))))) {
    DAT_004c6bcc = 0xffffffff;
    DAT_004c6bc8 = uVar8;
  }
  if ((uStack_1c0 == uVar11) && (-1 < (int)DAT_004c6bc8)) {
    if (iVar23 == *(int *)(iVar13 + 4)) {
      FUN_0047a948();
    }
    if (*(uint *)(iVar23 + 0x18) == DAT_004c6bc8) {
      DAT_004c6bc8 = 0xffffffff;
    }
  }
  if (iVar23 == *(int *)(iVar13 + 4)) {
    FUN_0047a948();
  }
  uVar17 = DAT_004c6bcc;
  if ((((*(uint *)(iVar23 + 0x18) == uVar11) && (-1 < (int)DAT_004c6bc8)) &&
      (uStack_1c0 == DAT_004c6bc8)) && (DAT_004c6bc8 = 0xffffffff, -1 < (int)DAT_004c6bcc)) {
    DAT_004c6bcc = 0xffffffff;
    DAT_004c6bc8 = uVar17;
  }
  if ((uStack_1c0 == uVar11) && (-1 < (int)DAT_004c6bcc)) {
    if (iVar23 == *(int *)(iVar13 + 4)) {
      FUN_0047a948();
    }
    if (*(uint *)(iVar23 + 0x18) == DAT_004c6bcc) {
      DAT_004c6bcc = 0xffffffff;
    }
  }
  if (iVar23 == *(int *)(iVar13 + 4)) {
    FUN_0047a948();
  }
  if (((*(uint *)(iVar23 + 0x18) == uVar11) && (-1 < (int)DAT_004c6bcc)) &&
     (uStack_1c0 == DAT_004c6bcc)) {
    DAT_004c6bcc = 0xffffffff;
  }
LAB_0043b8ab:
  UnitList_Advance(&iStack_1b8);
  param_1 = local_1a8;
  goto LAB_0043a010;
}

