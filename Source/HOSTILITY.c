
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall HOSTILITY(int param_1)

{
  CStringData *pCVar1;
  int *piVar2;
  double dVar3;
  short sVar4;
  void *pvVar5;
  undefined1 uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  CStringData *pCVar10;
  int iVar11;
  uint uVar12;
  _AFX_AYGSHELL_STATE *p_Var13;
  int iVar14;
  rsize_t rVar15;
  undefined4 *puVar16;
  uint *puVar17;
  int *piVar18;
  ushort *puVar19;
  ushort uStack_76;
  int local_74;
  uint local_70;
  void *pvStack_6c;
  int *piStack_68;
  CStringData *pCStack_64;
  undefined4 *puStack_60;
  CStringData *pCStack_5c;
  int iStack_58;
  int *piStack_54;
  int aiStack_50 [3];
  undefined4 auStack_44 [3];
  void *apvStack_38 [4];
  void *apvStack_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_00496c08;
  local_14 = ExceptionList;
  uVar7 = DAT_004c8db8 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  local_70 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_74 = param_1;
  piVar8 = FUN_0047020b();
  if (piVar8 == (int *)0x0) {
    piVar8 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar9 = (**(code **)(*piVar8 + 0xc))(uVar7);
  pvStack_6c = (void *)(iVar9 + 0x10);
  iStack_c = 0;
  FUN_00465870(apvStack_28);
  iStack_c._0_1_ = 1;
  FUN_00465870(apvStack_38);
  iStack_c._0_1_ = 2;
  uVar6 = (undefined1)iStack_c;
  iStack_c._0_1_ = 2;
  if (DAT_00baed5f == '\0') {
    SEND_LOG(&pvStack_6c,(wchar_t *)"Enemy not desired yet");
    puStack_60 = (undefined4 *)0x1e;
    pCVar10 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_6c + -0x10));
    pCStack_5c = pCVar10 + 0x10;
    iStack_c._0_1_ = 3;
    BuildAllianceMsg(&DAT_00bbf638,aiStack_50,(int *)&puStack_60);
    iStack_c._0_1_ = 2;
    pCVar1 = pCVar10 + 0xc;
    LOCK();
    iVar9 = *(int *)pCVar1;
    *(int *)pCVar1 = *(int *)pCVar1 + -1;
    UNLOCK();
    if (iVar9 == 1 || iVar9 + -1 < 0) {
      (**(code **)(**(int **)pCVar10 + 4))(pCVar10);
    }
    uVar6 = (undefined1)iStack_c;
    if (DAT_00baed68 == '\0') {
      iVar9 = _rand();
      iVar9 = (iVar9 / 0x17) % 0x14;
      if (1 < iVar9 + 5) {
        iVar9 = iVar9 + 4;
        do {
          iVar11 = _rand();
          puStack_60 = (undefined4 *)((iVar11 / 0x17) % 100);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      uVar6 = (undefined1)iStack_c;
      if ((int)puStack_60 < (g_DeceitLevel + 3) * 0xf) {
        DAT_00baed5f = '\x01';
        SEND_LOG(&pvStack_6c,(wchar_t *)"Enemy is now desired just starting this turn (%d)<(%d)");
        piStack_68 = (int *)0x1e;
        pCVar10 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_6c + -0x10));
        pCStack_64 = pCVar10 + 0x10;
        iStack_c._0_1_ = 4;
        BuildAllianceMsg(&DAT_00bbf638,aiStack_50,(int *)&piStack_68);
        iStack_c._0_1_ = 2;
        pCVar1 = pCVar10 + 0xc;
        LOCK();
        iVar9 = *(int *)pCVar1;
        *(int *)pCVar1 = *(int *)pCVar1 + -1;
        UNLOCK();
        uVar6 = (undefined1)iStack_c;
        if (iVar9 == 1 || iVar9 + -1 < 0) {
          (**(code **)(**(int **)pCVar10 + 4))(pCVar10);
          uVar6 = (undefined1)iStack_c;
        }
      }
    }
  }
  iStack_c._0_1_ = uVar6;
  if (((DAT_00baed68 == '\x01') ||
      (sVar4 = *(short *)(*(int *)(param_1 + 8) + 0x244a), FAL == sVar4)) || (WIN == sVar4)) {
    CAL_BOARD(param_1);
    uVar7 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
      piStack_68 = (int *)0x0;
      puVar17 = &DAT_00b9fdd8;
      do {
        *puVar17 = 0xffffffff;
        uVar12 = 0;
        iVar9 = 10000;
        if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
          do {
            if (((((uVar12 != uVar7) && (uVar7 != local_70)) &&
                 ((uVar12 != local_70 &&
                  ((0 < (int)(&curr_sc_cnt)[uVar12] &&
                   ((int)(&DAT_006340c0)[(int)piStack_68 + uVar12] < 4)))))) &&
                (((int)(&DAT_006340c0)[local_70 * 0x15 + uVar12] < 4 ||
                 (((((&DAT_004cf568)[uVar12 * 2] == 1 && ((&DAT_004cf56c)[uVar12 * 2] == 0)) &&
                   (param_1 = local_74, DAT_00baed69 == '\x01')) && (uVar12 == DAT_0062480c)))))) &&
               (iVar11 = (&DAT_006340c0)[local_70 * 0x15 + uVar12] +
                         (&DAT_006340c0)[(int)piStack_68 + uVar12], iVar11 < iVar9)) {
              *puVar17 = uVar12;
              iVar9 = iVar11;
            }
            uVar12 = uVar12 + 1;
          } while ((int)uVar12 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
        }
        piStack_68 = (int *)((int)piStack_68 + 0x15);
        uVar7 = uVar7 + 1;
        puVar17 = puVar17 + 1;
      } while ((int)uVar7 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
    }
    if ((-1 < (int)DAT_004c6bc4) && (-1 < (int)(&DAT_00b9fdd8)[DAT_004c6bc4])) {
      puVar19 = &uStack_76;
      uStack_76 = *(byte *)(&DAT_00b9fdd8 + DAT_004c6bc4) | 0x4100;
      p_Var13 = _AfxAygshellState();
      GetProvinceToken(p_Var13,puVar19);
      SEND_LOG(&pvStack_6c,(wchar_t *)"A good mutual enemy with our best Ally is (%s)");
      piStack_68 = (int *)0x28;
      pCVar10 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_6c + -0x10));
      pCStack_64 = pCVar10 + 0x10;
      iStack_c._0_1_ = 5;
      BuildAllianceMsg(&DAT_00bbf638,aiStack_50,(int *)&piStack_68);
      iStack_c._0_1_ = 2;
      pCVar1 = pCVar10 + 0xc;
      LOCK();
      iVar9 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + -1;
      UNLOCK();
      if (iVar9 == 1 || iVar9 + -1 < 0) {
        (**(code **)(**(int **)pCVar10 + 4))(pCVar10);
      }
    }
  }
  FUN_004113d0(param_1);
  sVar4 = *(short *)(*(int *)(param_1 + 8) + 0x244a);
  if ((SPR == sVar4) || (FAL == sVar4)) {
    iVar9 = param_1;
    if (DAT_00baed68 == '\x01') {
      iVar9 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
        puVar16 = &DAT_004d55c8;
        do {
          *puVar16 = 0;
          puVar16[1] = 0;
          (&DAT_004d6248)[iVar9 * 2] = 0;
          (&DAT_004d624c)[iVar9 * 2] = 0;
          (&DAT_004d5480)[iVar9 * 2] = 0;
          (&DAT_004d5484)[iVar9 * 2] = 0;
          iVar9 = iVar9 + 1;
          puVar16 = puVar16 + 0x2a;
        } while (iVar9 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      SEND_LOG(&pvStack_6c,L"This is the first turn");
      pvVar5 = pvStack_6c;
      piVar8 = (int *)((int)pvStack_6c + -0x10);
      piStack_68 = (int *)0x1f;
      puVar16 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_6c + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar16 != (undefined4 *)*piVar8)) {
        piVar8 = (int *)(**(code **)*puVar16)(*(undefined4 *)((int)pvVar5 + -0xc),1);
        if (piVar8 == (int *)0x0) {
LAB_0042f330:
          ErrorExit();
          return;
        }
        piVar8[1] = *(int *)((int)pvVar5 + -0xc);
        rVar15 = *(int *)((int)pvVar5 + -0xc) + 1;
        _memcpy_s(piVar8 + 4,rVar15,pvVar5,rVar15);
      }
      else {
        LOCK();
        *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
        UNLOCK();
      }
      pCStack_64 = (CStringData *)(piVar8 + 4);
      iStack_c._0_1_ = 6;
      BuildAllianceMsg(&DAT_00bbf638,aiStack_50,(int *)&piStack_68);
      iStack_c._0_1_ = 2;
      piVar18 = piVar8 + 3;
      LOCK();
      iVar9 = *piVar18;
      *piVar18 = *piVar18 + -1;
      UNLOCK();
      if (iVar9 + -1 < 1) {
        (**(code **)(*(int *)*piVar8 + 4))(piVar8);
      }
      iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      uVar7 = 0;
      if (0 < iVar9) {
        iVar11 = 0;
        puVar17 = &DAT_00633f20;
        do {
          uVar12 = 0;
          if (0 < iVar9) {
            do {
              if (uVar7 != uVar12) {
                iVar9 = uVar12 + iVar11;
                dVar3 = (double)(&g_InfluenceMatrix_B)[iVar9];
                (&g_AllyTrustScore_Hi)[iVar9 * 2] = 0;
                if (dVar3 <= 17.0) {
                  (&g_AllyTrustScore)[iVar9 * 2] = 5;
                }
                else {
                  (&g_AllyTrustScore)[iVar9 * 2] = 3;
                }
              }
              uVar12 = uVar12 + 1;
            } while ((int)uVar12 < *(int *)(*(int *)(local_74 + 8) + 0x2404));
          }
          iVar9 = _rand();
          iVar9 = (iVar9 / 0x17) % 0x14;
          if (1 < iVar9 + 5) {
            iVar9 = iVar9 + 4;
            do {
              iVar14 = _rand();
              puStack_60 = (undefined4 *)((iVar14 / 0x17) % 100);
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          if ((int)puStack_60 < 0x19) {
            uVar12 = puVar17[-1];
            (&g_AllyTrustScore)[(uVar12 + iVar11) * 2] = 1;
            (&g_AllyTrustScore_Hi)[(uVar12 + iVar11) * 2] = 0;
            if (uVar7 == local_70) {
              DAT_004c6bc4 = *puVar17;
              DAT_004c6bc8 = puVar17[1];
            }
          }
          else if ((int)puStack_60 < 0x32) {
            uVar12 = *puVar17;
            (&g_AllyTrustScore)[(uVar12 + iVar11) * 2] = 1;
            (&g_AllyTrustScore_Hi)[(uVar12 + iVar11) * 2] = 0;
            if (uVar7 == local_70) {
              DAT_004c6bc4 = puVar17[-1];
              DAT_004c6bc8 = puVar17[1];
            }
          }
          else if ((int)puStack_60 < 0x4b) {
            uVar12 = puVar17[1];
            (&g_AllyTrustScore)[(uVar12 + iVar11) * 2] = 1;
            (&g_AllyTrustScore_Hi)[(uVar12 + iVar11) * 2] = 0;
            if (uVar7 == local_70) {
              DAT_004c6bc4 = puVar17[-1];
              DAT_004c6bc8 = *puVar17;
              DAT_00baed42 = 1;
            }
          }
          else {
            DAT_00baed43 = 1;
            if (uVar7 == local_70) {
              DAT_004c6bc4 = puVar17[-1];
              DAT_004c6bc8 = *puVar17;
              DAT_004c6bcc = puVar17[1];
              if (DAT_004c6bc4 == local_70) {
                DAT_004c6bc4 = 0xffffffff;
              }
              if (DAT_004c6bc8 == local_70) {
                DAT_004c6bc8 = 0xffffffff;
              }
              if (DAT_004c6bcc == local_70) {
                DAT_004c6bcc = 0xffffffff;
              }
            }
          }
          iVar9 = *(int *)(*(int *)(local_74 + 8) + 0x2404);
          uVar7 = uVar7 + 1;
          iVar11 = iVar11 + 0x15;
          puVar17 = puVar17 + 5;
        } while ((int)uVar7 < iVar9);
      }
      iVar11 = local_74;
      if ((0 < g_HistoryCounter) && (iVar9 = 0, 0 < *(int *)(*(int *)(local_74 + 8) + 0x2404))) {
        puVar17 = &g_AllyTrustScore + local_70 * 0x2a;
        do {
          uVar7 = puVar17[1];
          uVar12 = *puVar17;
          (&DAT_004d5480)[iVar9 * 2] = uVar12;
          (&DAT_004d5484)[iVar9 * 2] = uVar7;
          if (((int)uVar7 < 1) && (((int)uVar7 < 0 || (uVar12 < 5)))) {
            *puVar17 = 0;
            puVar17[1] = 0;
          }
          SendAllyPressByPower((byte)iVar9);
          iVar9 = iVar9 + 1;
          puVar17 = puVar17 + 2;
        } while (iVar9 < *(int *)(*(int *)(iVar11 + 8) + 0x2404));
      }
      if (5.0 < _g_NearEndGameFactor) {
        DAT_00baed5f = '\x01';
      }
      iVar9 = local_74;
      if (3.0 < _g_NearEndGameFactor) {
        CAL_BOARD(iVar11);
        iVar9 = local_74;
      }
    }
    sVar4 = SPR;
    param_1 = local_74;
    if (DAT_00baed5f == '\x01') {
      iVar14 = 0;
      iVar11 = 0;
      if (0 < *(int *)(*(int *)(iVar9 + 8) + 0x2404)) {
        piVar18 = &DAT_00634e90 + local_70 * 0x15;
        piVar8 = &g_AllyTrustScore + local_70 * 0x2a;
        do {
          if (((&DAT_004cf568)[iVar11 * 2] == 0 && (&DAT_004cf56c)[iVar11 * 2] == 0) &&
             (*piVar8 == 0 && piVar8[1] == 0)) {
            puVar17 = &DAT_004cf4c0 + iVar11 * 2;
            uVar7 = *puVar17;
            *puVar17 = *puVar17 + 1;
            (&DAT_004cf4c4)[iVar11 * 2] = (&DAT_004cf4c4)[iVar11 * 2] + (uint)(0xfffffffe < uVar7);
          }
          if (((-1 < piVar8[1]) && (((0 < piVar8[1] || (*piVar8 != 0)) && (0xe < *piVar18)))) ||
             (*piVar18 < 0)) {
            (&DAT_004cf4c0)[iVar11 * 2] = 0;
            (&DAT_004cf4c4)[iVar11 * 2] = 0;
          }
          if (((-1 < (int)(&DAT_004cf4c4)[iVar11 * 2]) &&
              ((0 < (int)(&DAT_004cf4c4)[iVar11 * 2] || (9 < (uint)(&DAT_004cf4c0)[iVar11 * 2]))))
             && (sVar4 == *(short *)(*(int *)(iVar9 + 8) + 0x244a))) {
            (&DAT_004cf4c0)[iVar11 * 2] = 0;
            (&DAT_004cf4c4)[iVar11 * 2] = 0;
          }
          iVar11 = iVar11 + 1;
          piVar18 = piVar18 + 1;
          piVar8 = piVar8 + 2;
        } while (iVar11 < *(int *)(*(int *)(iVar9 + 8) + 0x2404));
      }
      if ((0 < g_HistoryCounter) && (0 < *(int *)(*(int *)(iVar9 + 8) + 0x2404))) {
        do {
          SendAllyPressByPower((byte)iVar14);
          iVar14 = iVar14 + 1;
        } while (iVar14 < *(int *)(*(int *)(iVar9 + 8) + 0x2404));
      }
      uVar7 = 0;
      if (0 < *(int *)(*(int *)(local_74 + 8) + 0x2404)) {
        piVar8 = &g_AllyTrustScore + local_70 * 2;
        do {
          if (uVar7 != local_70) {
            iVar9 = piVar8[1];
            if ((-1 < iVar9) && ((0 < iVar9 || (*piVar8 != 0)))) {
              iVar11 = local_70 * 0x15 + uVar7;
              if (((&g_AllyTrustScore)[iVar11 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar11 * 2] == 0)
                 && ((((&DAT_004cf568)[uVar7 * 2] == 0 && (&DAT_004cf56c)[uVar7 * 2] == 0 &&
                      (0.0 < (double)(&g_InfluenceMatrix_B)[iVar11])) &&
                     (-1 < (int)(&DAT_00634e90)[iVar11])))) {
                (&g_AllyTrustScore)[iVar11 * 2] = *piVar8;
                (&g_AllyTrustScore_Hi)[iVar11 * 2] = iVar9;
                puVar19 = &uStack_76;
                uStack_76 = (ushort)uVar7 & 0xff | 0x4100;
                p_Var13 = _AfxAygshellState();
                GetProvinceToken(p_Var13,puVar19);
                SEND_LOG(&pvStack_6c,
                         (wchar_t *)"We thought we were going to attack (%s)- but changed our minds"
                        );
                pvVar5 = pvStack_6c;
                piVar18 = (int *)((int)pvStack_6c + -0x10);
                puStack_60 = (undefined4 *)0x3c;
                puVar16 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_6c + -0x10) + 0x10))();
                if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar16 != (undefined4 *)*piVar18)) {
                  piVar18 = (int *)(**(code **)*puVar16)(*(undefined4 *)((int)pvVar5 + -0xc),1);
                  if (piVar18 == (int *)0x0) goto LAB_0042f330;
                  piVar18[1] = *(int *)((int)pvVar5 + -0xc);
                  rVar15 = *(int *)((int)pvVar5 + -0xc) + 1;
                  _memcpy_s(piVar18 + 4,rVar15,pvVar5,rVar15);
                }
                else {
                  LOCK();
                  *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
                  UNLOCK();
                }
                pCStack_5c = (CStringData *)(piVar18 + 4);
                iStack_c._0_1_ = 7;
                BuildAllianceMsg(&DAT_00bbf638,aiStack_50,(int *)&puStack_60);
                iStack_c._0_1_ = 2;
                piVar2 = piVar18 + 3;
                LOCK();
                iVar9 = *piVar2;
                *piVar2 = *piVar2 + -1;
                UNLOCK();
                if (iVar9 == 1 || iVar9 + -1 < 0) {
                  (**(code **)(*(int *)*piVar18 + 4))(piVar18);
                }
              }
            }
          }
          uVar7 = uVar7 + 1;
          piVar8 = piVar8 + 0x2a;
        } while ((int)uVar7 < *(int *)(*(int *)(local_74 + 8) + 0x2404));
      }
      uVar7 = 0;
      param_1 = local_74;
      if (0 < *(int *)(*(int *)(local_74 + 8) + 0x2404)) {
        piStack_68 = &DAT_00634e90 + local_70;
        puStack_60 = &g_AllyTrustScore + local_70 * 2;
        do {
          iVar9 = DAT_00bb6e14;
          if (g_HistoryCounter == 0) {
LAB_0042f95f:
            if ((((0 < (int)(&curr_sc_cnt)[uVar7]) &&
                 ((2 < (int)(&curr_sc_cnt)[uVar7] ||
                  (SPR == *(short *)(*(int *)(local_74 + 8) + 0x244a))))) &&
                (((SPR == *(short *)(*(int *)(local_74 + 8) + 0x244a) ||
                  ((&DAT_0062b7b0)[local_70 * 0x15 + uVar7] == 0)) &&
                 ((((uVar7 != local_70 &&
                    ((&DAT_004cf568)[uVar7 * 2] == 0 && (&DAT_004cf56c)[uVar7 * 2] == 0)) &&
                   (iVar9 = local_70 * 0x15 + uVar7,
                   (&g_AllyTrustScore)[iVar9 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar9 * 2] == 0))
                  && ((-1 < (int)(&DAT_00634e90)[iVar9] && (-1 < *piStack_68)))))))) &&
               (((iVar11 = _rand(), (iVar11 / 0x17) % 100 < 0xf ||
                 (((int)(&DAT_004cf4c4)[uVar7 * 2] < 1 &&
                  (((int)(&DAT_004cf4c4)[uVar7 * 2] < 0 || ((uint)(&DAT_004cf4c0)[uVar7 * 2] < 2))))
                 )) && ((g_HistoryCounter == 0 || (1 < g_DeceitLevel)))))) {
              iVar11 = (&DAT_00634e90)[iVar9];
              (&g_AllyTrustScore)[iVar9 * 2] = 1;
              (&g_AllyTrustScore_Hi)[iVar9 * 2] = 0;
              *puStack_60 = 1;
              puStack_60[1] = 0;
              if (iVar11 != 0x32) {
                (&DAT_00634e90)[iVar9] = 0;
                *piStack_68 = 0;
              }
              puVar19 = &uStack_76;
              uStack_76 = (ushort)uVar7 & 0xff | 0x4100;
              p_Var13 = _AfxAygshellState();
              GetProvinceToken(p_Var13,puVar19);
              SEND_LOG(&pvStack_6c,(wchar_t *)"Attempting to actively form peace with (%s)");
              pvVar5 = pvStack_6c;
              piVar8 = (int *)((int)pvStack_6c + -0x10);
              iStack_58 = 0x3d;
              puVar16 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_6c + -0x10) + 0x10))();
              if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar16 != (undefined4 *)*piVar8)) {
                piVar8 = (int *)(**(code **)*puVar16)(*(undefined4 *)((int)pvVar5 + -0xc),1);
                if (piVar8 == (int *)0x0) goto LAB_0042f330;
                piVar8[1] = *(int *)((int)pvVar5 + -0xc);
                rVar15 = *(int *)((int)pvVar5 + -0xc) + 1;
                _memcpy_s(piVar8 + 4,rVar15,pvVar5,rVar15);
              }
              else {
                LOCK();
                *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
                UNLOCK();
              }
              piStack_54 = piVar8 + 4;
              iStack_c._0_1_ = 8;
              BuildAllianceMsg(&DAT_00bbf638,auStack_44,&iStack_58);
              iStack_c._0_1_ = 2;
              piVar18 = piVar8 + 3;
              LOCK();
              iVar9 = *piVar18;
              *piVar18 = *piVar18 + -1;
              UNLOCK();
              if (iVar9 == 1 || iVar9 + -1 < 0) {
                (**(code **)(*(int *)*piVar8 + 4))(piVar8);
              }
            }
          }
          else {
            puVar16 = (undefined4 *)FUN_004108a0(&DAT_00bb6e10,aiStack_50,&PCE);
            if (((undefined *)*puVar16 == (undefined *)0x0) ||
               ((undefined *)*puVar16 != &DAT_00bb6e10)) {
              FUN_0047a948();
            }
            if (puVar16[1] == iVar9) goto LAB_0042f95f;
          }
          puStack_60 = puStack_60 + 0x2a;
          piStack_68 = piStack_68 + 0x15;
          uVar7 = uVar7 + 1;
          param_1 = local_74;
        } while ((int)uVar7 < *(int *)(*(int *)(local_74 + 8) + 0x2404));
      }
    }
  }
  if ((DAT_00baed68 == '\0') || (3.0 < _g_NearEndGameFactor)) {
    UpdateRelationHistory(param_1);
  }
  iStack_c._0_1_ = 1;
  FreeList(apvStack_38);
  iStack_c = (uint)iStack_c._1_3_ << 8;
  FreeList(apvStack_28);
  iStack_c = 0xffffffff;
  piVar8 = (int *)((int)pvStack_6c + -4);
  LOCK();
  iVar9 = *piVar8;
  *piVar8 = *piVar8 + -1;
  UNLOCK();
  if (iVar9 == 1 || iVar9 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_6c + -0x10) + 4))((undefined4 *)((int)pvStack_6c + -0x10));
  }
  ExceptionList = local_14;
  return;
}

