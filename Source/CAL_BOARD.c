
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall CAL_BOARD(int param_1)

{
  double dVar1;
  uint uVar2;
  double dVar3;
  undefined2 uVar4;
  void *pvVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  _AFX_AYGSHELL_STATE *p_Var9;
  undefined4 *puVar10;
  rsize_t rVar11;
  CStringData *pCVar12;
  CStringData *pCVar13;
  double *pdVar14;
  double *pdVar15;
  int iVar16;
  int iVar17;
  double *pdVar18;
  int iVar19;
  int *piVar20;
  uint *puVar21;
  int iVar22;
  double *pdVar23;
  int *piVar24;
  byte *pbVar25;
  bool bVar26;
  float10 fVar27;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar28;
  ulonglong uVar29;
  ushort *puVar30;
  double **ppdVar31;
  void *pvStack_174;
  undefined4 uStack_170;
  double *local_16c;
  int iStack_168;
  CStringData *pCStack_164;
  ushort uStack_152;
  int local_150;
  ushort uStack_14a;
  double *pdStack_148;
  double *local_144;
  ushort uStack_13e;
  double *local_13c;
  undefined4 uStack_138;
  double *pdStack_134;
  CStringData *pCStack_130;
  int *piStack_12c;
  double *local_128;
  int iStack_124;
  CStringData *pCStack_120;
  uint *local_11c;
  double *pdStack_118;
  CStringData *pCStack_114;
  undefined4 auStack_10c [3];
  ushort uStack_fe;
  int local_fc;
  double *pdStack_f8;
  CStringData *pCStack_f4;
  double *local_f0;
  int local_ec;
  CStringData *pCStack_e8;
  int aiStack_e4 [2];
  uint auStack_dc [36];
  void *local_4c;
  undefined1 *puStack_48;
  int iStack_44;
  
  iStack_44 = 0xffffffff;
  puStack_48 = &LAB_00496809;
  local_4c = ExceptionList;
  uVar6 = DAT_004c8db8 ^ (uint)&stack0xfffffe40;
  ExceptionList = &local_4c;
  local_16c = (double *)(uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  iVar22 = 0;
  local_ec = 0;
  local_11c = (uint *)0x0;
  local_fc = -1;
  local_150 = param_1;
  local_144 = local_16c;
  local_13c = local_16c;
  local_128 = local_16c;
  local_f0 = local_16c;
  piVar7 = FUN_0047020b();
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar8 = (**(code **)(*piVar7 + 0xc))(uVar6);
  iVar16 = local_150;
  pvStack_174 = (void *)(iVar8 + 0x10);
  DAT_00baed69 = '\0';
  DAT_0062480c = (double *)0xffffffff;
  iVar8 = 0;
  iStack_44._0_1_ = 0;
  iStack_44._1_3_ = 0;
  pdStack_118 = (double *)0x0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    do {
      pdVar18 = (double *)(&target_sc_cnt)[iVar22];
      pdStack_134 = *(double **)(iVar16 + 0x3ffc);
      pdStack_f8 = pdStack_134;
      if (((int)pdVar18 <= (int)pdStack_134) && (pdStack_f8 = pdVar18, (int)pdVar18 < 0)) {
        pdStack_f8 = (double *)0x0;
      }
      fVar27 = (float10)_safe_pow();
      iVar22 = iVar22 + 1;
      *(double *)(iVar22 * 8 + 0x6238e0) = (double)(fVar27 * (float10)100.0 + (float10)1.0);
    } while (iVar22 < *(int *)(*(int *)(iVar16 + 8) + 0x2404));
  }
  _g_NearEndGameFactor = (double *)0x3f800000;
  if (*(int *)(local_150 + 0x3ffc) - (&target_sc_cnt)[(int)local_16c] == 1) {
    DAT_00baed6b = 1;
  }
  DAT_00baed6c = 0;
  iVar22 = 0;
  if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
    do {
      iVar16 = (&target_sc_cnt)[iVar22];
      (&DAT_004cf568)[iVar22 * 2] = 0;
      (&DAT_004cf56c)[iVar22 * 2] = 0;
      dVar1 = ((double)iVar16 * 100.0) / (double)*(int *)(local_150 + 0x3ffc);
      (&DAT_0062e360)[iVar22] = dVar1;
      if (80.0 < dVar1) {
        DAT_00baed6c = 1;
      }
      pdStack_134 = (double *)(float)((iVar16 - *(int *)(local_150 + 0x3ffc)) + 9);
      if ((float)_g_NearEndGameFactor < (float)pdStack_134) {
        _g_NearEndGameFactor = pdStack_134;
      }
      if (iVar8 < iVar16) {
        pdStack_118 = (double *)0x1;
        iVar8 = iVar16;
        DAT_00624124 = iVar22;
      }
      else if (iVar16 == iVar8) {
        pdStack_118 = (double *)((int)pdStack_118 + 1);
      }
      iVar22 = iVar22 + 1;
    } while (iVar22 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
  }
  if (((-1 < (int)DAT_004c6bc4) && ((int)(&curr_sc_cnt)[(int)DAT_004c6bc4] < 2)) &&
     (DAT_004c6bc4 = (double *)0xffffffff, -1 < (int)DAT_004c6bc8)) {
    DAT_004c6bc4 = DAT_004c6bc8;
    DAT_004c6bc8 = (double *)0xffffffff;
    if (-1 < (int)DAT_004c6bcc) {
      DAT_004c6bc8 = DAT_004c6bcc;
      DAT_004c6bcc = (double *)0xffffffff;
    }
  }
  if ((int)pdStack_118 < 2) {
    puVar30 = &uStack_13e;
    uStack_13e = (byte)DAT_00624124 | 0x4100;
    p_Var9 = _AfxAygshellState();
    GetProvinceToken(p_Var9,puVar30);
    SEND_LOG(&pvStack_174,(wchar_t *)"The lone lead power is (%s)");
    pvVar5 = pvStack_174;
    piVar7 = (int *)((int)pvStack_174 + -0x10);
    iStack_124 = 0x28;
    puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
    if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
      piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
      if (piVar7 == (int *)0x0) {
LAB_0042796a:
        ErrorExit();
        return;
      }
      piVar7[1] = *(int *)((int)pvVar5 + -0xc);
      rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
      _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
    }
    else {
      LOCK();
      *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
      UNLOCK();
    }
    pCStack_120 = (CStringData *)(piVar7 + 4);
    iStack_44._0_1_ = 1;
    BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
    iStack_44._0_1_ = 0;
    piVar20 = piVar7 + 3;
    LOCK();
    iVar22 = *piVar20;
    *piVar20 = *piVar20 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(*(int *)*piVar7 + 4))();
    }
  }
  else {
    DAT_00624124 = -1;
  }
  if (-1 < (int)DAT_004c6bc4) {
    puVar30 = &uStack_13e;
    uStack_13e = (ushort)DAT_004c6bc4 & 0xff | 0x4100;
    p_Var9 = _AfxAygshellState();
    GetProvinceToken(p_Var9,puVar30);
    SEND_LOG(&pvStack_174,(wchar_t *)"We still have our opening best Ally (%s)");
    pvVar5 = pvStack_174;
    piVar7 = (int *)((int)pvStack_174 + -0x10);
    iStack_124 = 0x28;
    puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
    if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
      piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
      if (piVar7 == (int *)0x0) {
        ErrorExit();
        return;
      }
      piVar7[1] = *(int *)((int)pvVar5 + -0xc);
      rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
      _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
    }
    else {
      LOCK();
      *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
      UNLOCK();
    }
    pCStack_120 = (CStringData *)(piVar7 + 4);
    iStack_44._0_1_ = 2;
    BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
    iStack_44._0_1_ = 0;
    piVar20 = piVar7 + 3;
    LOCK();
    iVar22 = *piVar20;
    *piVar20 = *piVar20 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(*(int *)*piVar7 + 4))();
    }
  }
  if (-1 < (int)DAT_004c6bc8) {
    puVar30 = &uStack_13e;
    uStack_13e = (ushort)DAT_004c6bc8 & 0xff | 0x4100;
    p_Var9 = _AfxAygshellState();
    GetProvinceToken(p_Var9,puVar30);
    SEND_LOG(&pvStack_174,(wchar_t *)"We still have our opening second best Ally (%s)");
    pvVar5 = pvStack_174;
    piVar7 = (int *)((int)pvStack_174 + -0x10);
    iStack_124 = 0x28;
    puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
    if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
      piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
      if (piVar7 == (int *)0x0) {
        ErrorExit();
        return;
      }
      piVar7[1] = *(int *)((int)pvVar5 + -0xc);
      rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
      _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
    }
    else {
      LOCK();
      *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
      UNLOCK();
    }
    pCStack_120 = (CStringData *)(piVar7 + 4);
    iStack_44._0_1_ = 3;
    BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
    iStack_44._0_1_ = 0;
    piVar20 = piVar7 + 3;
    LOCK();
    iVar22 = *piVar20;
    *piVar20 = *piVar20 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(*(int *)*piVar7 + 4))();
    }
  }
  if (-1 < (int)DAT_004c6bcc) {
    puVar30 = &uStack_13e;
    uStack_13e = (ushort)DAT_004c6bcc & 0xff | 0x4100;
    p_Var9 = _AfxAygshellState();
    GetProvinceToken(p_Var9,puVar30);
    SEND_LOG(&pvStack_174,L"We still have our opening third best Ally (%s)");
    pvVar5 = pvStack_174;
    piVar7 = (int *)((int)pvStack_174 + -0x10);
    iStack_124 = 0x28;
    puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
    if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
      piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
      if (piVar7 == (int *)0x0) {
        ErrorExit();
        return;
      }
      piVar7[1] = *(int *)((int)pvVar5 + -0xc);
      rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
      _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
    }
    else {
      LOCK();
      *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
      UNLOCK();
    }
    pCStack_120 = (CStringData *)(piVar7 + 4);
    iStack_44._0_1_ = 4;
    BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
    iStack_44._0_1_ = 0;
    piVar20 = piVar7 + 3;
    LOCK();
    iVar22 = *piVar20;
    *piVar20 = *piVar20 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(*(int *)*piVar7 + 4))();
    }
  }
  pdVar18 = local_16c;
  if ((1 < (int)(&target_sc_cnt)[(int)local_16c]) || (7.0 <= (float)_g_NearEndGameFactor)) {
    if ((2 < (int)(&target_sc_cnt)[(int)local_16c]) || (5.0 <= (float)_g_NearEndGameFactor)) {
      SEND_LOG(&pvStack_174,(wchar_t *)"Near End Game Factor = %.1f");
      pvVar5 = pvStack_174;
      piVar7 = (int *)((int)pvStack_174 + -0x10);
      iStack_124 = 0x28;
      puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
        piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
        if (piVar7 == (int *)0x0) {
          ErrorExit();
          return;
        }
        piVar7[1] = *(int *)((int)pvVar5 + -0xc);
        rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
        _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
      }
      else {
        LOCK();
        *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
        UNLOCK();
      }
      pCStack_120 = (CStringData *)(piVar7 + 4);
      iStack_44._0_1_ = 7;
    }
    else {
      _g_NearEndGameFactor = (double *)0x40a00000;
      SEND_LOG(&pvStack_174,(wchar_t *)"We are close to elimination: Near End Game Factor = %.1f");
      pvVar5 = pvStack_174;
      piVar7 = (int *)((int)pvStack_174 + -0x10);
      iStack_124 = 0x28;
      puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
        piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
        if (piVar7 == (int *)0x0) {
          ErrorExit();
          return;
        }
        piVar7[1] = *(int *)((int)pvVar5 + -0xc);
        rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
        _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
      }
      else {
        LOCK();
        *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
        UNLOCK();
      }
      pCStack_120 = (CStringData *)(piVar7 + 4);
      iStack_44._0_1_ = 6;
    }
  }
  else {
    _g_NearEndGameFactor = (double *)0x41000000;
    SEND_LOG(&pvStack_174,L"We are about to be eliminated: Near End Game Factor = %.1f");
    pvVar5 = pvStack_174;
    piVar7 = (int *)((int)pvStack_174 + -0x10);
    iStack_124 = 0x28;
    puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
    if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
      piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
      if (piVar7 == (int *)0x0) {
        ErrorExit();
        return;
      }
      piVar7[1] = *(int *)((int)pvVar5 + -0xc);
      rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
      _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
    }
    else {
      LOCK();
      *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
      UNLOCK();
    }
    pCStack_120 = (CStringData *)(piVar7 + 4);
    iStack_44._0_1_ = 5;
  }
  pCVar13 = pCStack_120;
  BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
  iStack_44 = (uint)iStack_44._1_3_ << 8;
  piVar7 = (int *)((int)pCVar13 + -4);
  LOCK();
  iVar22 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar22 == 1 || iVar22 + -1 < 0) {
    (**(code **)(**(int **)((int)pCVar13 + -0x10) + 4))();
  }
  SEND_LOG(&pvStack_174,(wchar_t *)"Our Deceit Level = %d");
  pvVar5 = pvStack_174;
  piVar7 = (int *)((int)pvStack_174 + -0x10);
  iStack_124 = 0x29;
  puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
  if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
    piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
    if (piVar7 == (int *)0x0) {
      ErrorExit();
      return;
    }
    piVar7[1] = *(int *)((int)pvVar5 + -0xc);
    rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
    _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
  }
  else {
    LOCK();
    *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
    UNLOCK();
  }
  pCStack_120 = (CStringData *)(piVar7 + 4);
  iStack_44._0_1_ = 8;
  BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
  iStack_44 = (uint)iStack_44._1_3_ << 8;
  piVar20 = piVar7 + 3;
  LOCK();
  iVar22 = *piVar20;
  *piVar20 = *piVar20 + -1;
  UNLOCK();
  if (iVar22 == 1 || iVar22 + -1 < 0) {
    (**(code **)(*(int *)*piVar7 + 4))();
  }
  pdVar14 = local_16c;
  iVar22 = *(int *)(*(int *)(local_150 + 8) + 0x2404);
  pdVar15 = (double *)0x0;
  if (0 < iVar22) {
    iVar16 = (int)pdVar18 * 8;
    pdVar23 = (double *)(&g_InfluenceMatrix_Alt + (int)pdVar18 * 0x15);
    do {
      if (*(double *)((int)&g_InfluenceMatrix_Alt + iVar16 + (int)pdVar18 * 0xa8) < *pdVar23) {
        iVar16 = (int)pdVar15 * 8;
        local_144 = pdVar15;
      }
      pdVar15 = (double *)((int)pdVar15 + 1);
      pdVar23 = pdVar23 + 1;
    } while ((int)pdVar15 < iVar22);
  }
  pdVar15 = (double *)0x0;
  if (0 < iVar22) {
    iVar16 = (int)pdVar18 * 8;
    pdVar23 = (double *)(&g_InfluenceMatrix_Alt + (int)pdVar18 * 0x15);
    do {
      if ((*(double *)((int)&g_InfluenceMatrix_Alt + iVar16 + (int)pdVar18 * 0xa8) < *pdVar23) &&
         (pdVar15 != local_144)) {
        iVar16 = (int)pdVar15 * 8;
        local_13c = pdVar15;
      }
      pdVar15 = (double *)((int)pdVar15 + 1);
      pdVar23 = pdVar23 + 1;
    } while ((int)pdVar15 < iVar22);
  }
  pdVar18 = local_13c;
  pdVar15 = (double *)0x0;
  if (0 < iVar22) {
    iVar16 = (int)local_16c * 8;
    pdVar23 = (double *)(&g_InfluenceMatrix_Alt + (int)local_16c * 0x15);
    do {
      if (((*(double *)((int)&g_InfluenceMatrix_Alt + iVar16 + (int)local_16c * 0xa8) < *pdVar23) &&
          (pdVar15 != local_144)) && (pdVar15 != local_13c)) {
        iVar16 = (int)pdVar15 * 8;
        local_f0 = pdVar15;
      }
      pdVar15 = (double *)((int)pdVar15 + 1);
      pdVar23 = pdVar23 + 1;
    } while ((int)pdVar15 < iVar22);
  }
  iVar16 = 0;
  if (0 < iVar22) {
    piVar7 = &DAT_00633780;
    do {
      iVar22 = 0;
      (&DAT_00633ec0)[iVar16] = 0;
      (&DAT_00633e68)[iVar16] = 0;
      piVar20 = piVar7;
      if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
        do {
          bVar26 = iVar16 != iVar22;
          iVar22 = iVar22 + 1;
          *piVar20 = bVar26 - 2;
          piVar20 = piVar20 + 1;
        } while (iVar22 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
      }
      iVar16 = iVar16 + 1;
      piVar7 = piVar7 + 0x15;
    } while (iVar16 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
  }
  iVar22 = *(int *)(*(int *)(local_150 + 8) + 0x2404);
  iVar16 = 0;
  if (0 < iVar22) {
    iVar8 = 0;
    do {
      iVar17 = 0;
      iVar19 = iVar8;
      if (0 < iVar22) {
        do {
          if ((((*(int *)((int)&g_AllyTrustScore_Hi + iVar19) < 1) &&
               ((*(int *)((int)&g_AllyTrustScore_Hi + iVar19) < 0 ||
                (*(uint *)((int)&g_AllyTrustScore + iVar19) < 2)))) && (iVar17 != iVar16)) &&
             ((0.0 < *(double *)((int)&g_InfluenceMatrix_Alt + iVar19) &&
              (2 < (int)(&target_sc_cnt)[iVar17])))) {
            (&DAT_00633ec0)[iVar16] = (&DAT_00633ec0)[iVar16] + 1;
          }
          iVar17 = iVar17 + 1;
          iVar19 = iVar19 + 8;
        } while (iVar17 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
      }
      iVar22 = *(int *)(*(int *)(local_150 + 8) + 0x2404);
      iVar16 = iVar16 + 1;
      iVar8 = iVar8 + 0xa8;
    } while (iVar16 < iVar22);
  }
  uStack_170 = (&DAT_00633ec0)[(int)local_16c];
  SEND_LOG(&pvStack_174,(wchar_t *)"We have %d enemies");
  pvVar5 = pvStack_174;
  piVar7 = (int *)((int)pvStack_174 + -0x10);
  iStack_124 = 0x29;
  puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
  if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
    piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
    if (piVar7 == (int *)0x0) {
      ErrorExit();
      return;
    }
    piVar7[1] = *(int *)((int)pvVar5 + -0xc);
    rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
    _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
  }
  else {
    LOCK();
    *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
    UNLOCK();
  }
  pCStack_120 = (CStringData *)(piVar7 + 4);
  iStack_44._0_1_ = 9;
  BuildAllianceMsg(&DAT_00bbf638,&iStack_168,&iStack_124);
  iStack_44 = (uint)iStack_44._1_3_ << 8;
  piVar20 = piVar7 + 3;
  LOCK();
  iVar22 = *piVar20;
  *piVar20 = *piVar20 + -1;
  UNLOCK();
  if (iVar22 == 1 || iVar22 + -1 < 0) {
    (**(code **)(*(int *)*piVar7 + 4))();
  }
  iVar22 = *(int *)(*(int *)(local_150 + 8) + 0x2404);
  pdVar15 = (double *)0x0;
  if (0 < iVar22) {
    pdStack_118 = (double *)(&g_AllyMatrix + (int)local_13c);
    pdStack_f8 = (double *)(&g_AllyMatrix + (int)local_144);
    piStack_12c = (int *)0x0;
    piVar7 = &DAT_00633780;
    do {
      if ((*(int *)pdStack_f8 == 1) && (pdVar15 != local_13c)) {
        local_ec = local_ec + 1;
      }
      if ((*(int *)pdStack_118 == 1) && (pdVar15 != local_144)) {
        local_11c = (uint *)((int)local_11c + 1);
      }
      pdVar18 = (double *)0x0;
      if (0 < iVar22) {
        iVar22 = (&DAT_00633ec0)[(int)pdVar15];
        piVar20 = piStack_12c;
        piVar24 = piVar7;
        do {
          if ((0 < piVar20[0x13554b]) ||
             ((((-1 < piVar20[0x13554b] && (1 < (uint)piVar20[0x13554a])) || (pdVar18 == pdVar15))
              || ((*(double *)(piVar20 + 0x2e07fc) <= 0.0 ||
                  ((int)(&target_sc_cnt)[(int)pdVar18] < 3)))))) {
            *piVar24 = iVar22;
          }
          else {
            *piVar24 = iVar22 + -1;
          }
          pdVar18 = (double *)((int)pdVar18 + 1);
          piVar20 = piVar20 + 2;
          piVar24 = piVar24 + 1;
        } while ((int)pdVar18 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
      }
      iVar22 = *(int *)(*(int *)(local_150 + 8) + 0x2404);
      pdStack_f8 = (double *)((int)pdStack_f8 + 0x54);
      pdStack_118 = (double *)((int)pdStack_118 + 0x54);
      piStack_12c = piStack_12c + 0x2a;
      pdVar15 = (double *)((int)pdVar15 + 1);
      piVar7 = piVar7 + 0x15;
      pdVar18 = local_13c;
      pdVar14 = local_16c;
    } while ((int)pdVar15 < iVar22);
  }
  if (DAT_004c6bc4 == local_144) {
    local_ec = local_ec + -1;
  }
  else if (DAT_004c6bc4 == pdVar18) {
    local_11c = (uint *)((int)local_11c + -1);
  }
  iStack_124 = (int)pdVar14 * 0x14;
  pdStack_f8 = (double *)(&DAT_00633f28)[(int)pdVar14 * 5];
  uStack_13e = (ushort)pdStack_f8 & 0xff | 0x4100;
  puVar30 = &uStack_fe;
  uStack_fe = uStack_13e;
  p_Var9 = _AfxAygshellState();
  GetProvinceToken(p_Var9,puVar30);
  uStack_14a = (byte)local_f0 | 0x4100;
  puVar30 = &uStack_14a;
  uStack_fe = uStack_14a;
  p_Var9 = _AfxAygshellState();
  GetProvinceToken(p_Var9,puVar30);
  uStack_152 = (ushort)pdVar18 & 0xff | 0x4100;
  puVar30 = &uStack_152;
  uStack_14a = uStack_152;
  p_Var9 = _AfxAygshellState();
  GetProvinceToken(p_Var9,puVar30);
  uStack_152 = (byte)local_144 | 0x4100;
  puVar30 = (ushort *)&uStack_138;
  uStack_138 = (double *)(CONCAT22(uStack_138._2_2_,(ushort)(byte)local_144) | 0x4100);
  p_Var9 = _AfxAygshellState();
  GetProvinceToken(p_Var9,puVar30);
  SEND_LOG(&pvStack_174,(wchar_t *)"Our top 4 feared powers are (%s)(%s)(%s)(%s)");
  pvVar5 = pvStack_174;
  piVar7 = (int *)((int)pvStack_174 + -0x10);
  pdStack_134 = (double *)0x2a;
  puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
  if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
    piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
    if (piVar7 == (int *)0x0) {
      ErrorExit();
      return;
    }
    piVar7[1] = *(int *)((int)pvVar5 + -0xc);
    rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
    _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
  }
  else {
    LOCK();
    *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
    UNLOCK();
  }
  pCStack_130 = (CStringData *)(piVar7 + 4);
  iStack_44._0_1_ = 10;
  BuildAllianceMsg(&DAT_00bbf638,&iStack_168,(int *)&pdStack_134);
  iStack_44._0_1_ = 0;
  piVar20 = piVar7 + 3;
  LOCK();
  iVar22 = *piVar20;
  *piVar20 = *piVar20 + -1;
  UNLOCK();
  if (iVar22 == 1 || iVar22 + -1 < 0) {
    (**(code **)(*(int *)*piVar7 + 4))();
  }
  pdVar18 = (double *)0x0;
  if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
    pdStack_118 = (double *)0x0;
    piStack_12c = &DAT_00633f1c;
    puVar21 = &g_AllyTrustScore + (int)local_16c * 0x2a;
    do {
      if ((((-1 < (int)puVar21[1]) &&
           (((0 < (int)puVar21[1] || (6 < *puVar21)) && (pdVar18 != local_16c)))) &&
          ((((iVar22 = (&target_sc_cnt)[(int)pdVar18], 2 < iVar22 &&
             (iVar16 = *piStack_12c,
             (&g_AllyTrustScore)[(iVar16 + (int)pdStack_118) * 2] == 0 &&
             (&g_AllyTrustScore_Hi)[(iVar16 + (int)pdStack_118) * 2] == 0)) &&
            (iVar8 = piStack_12c[1],
            (&g_AllyTrustScore)[((int)pdStack_118 + iVar8) * 2] == 0 &&
            (&g_AllyTrustScore_Hi)[((int)pdStack_118 + iVar8) * 2] == 0)) &&
           (((&DAT_00633780)[iVar16 * 0x15 + (int)local_16c] == 1 &&
            ((&DAT_00633780)[iVar8 * 0x15 + (int)local_16c] == 1)))))) &&
         ((iVar22 + 1 < (int)((&target_sc_cnt)[iVar8] + (&target_sc_cnt)[iVar16]) &&
          (iVar22 <= (&target_sc_cnt)[(int)local_16c] + 1)))) {
        puVar30 = (ushort *)&uStack_138;
        (&DAT_00633e68)[(int)pdVar18] = 1;
        uStack_138 = (double *)(CONCAT22(uStack_138._2_2_,(short)pdVar18) & 0xffff00ff | 0x4100);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)
                 "Our ally (%s) is distressed and being attacked by its 2 worst enemies- who only ha ve 1 enemy each"
                );
        pvVar5 = pvStack_174;
        piVar7 = (int *)((int)pvStack_174 + -0x10);
        pdStack_134 = (double *)0x2a;
        puVar10 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
        if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
          piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
          if (piVar7 == (int *)0x0) goto LAB_0042796a;
          piVar7[1] = *(int *)((int)pvVar5 + -0xc);
          rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
          _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
        }
        else {
          LOCK();
          *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
          UNLOCK();
        }
        pCStack_130 = (CStringData *)(piVar7 + 4);
        iStack_44._0_1_ = 0xb;
        BuildAllianceMsg(&DAT_00bbf638,&iStack_168,(int *)&pdStack_134);
        iStack_44._0_1_ = 0;
        piVar20 = piVar7 + 3;
        LOCK();
        iVar22 = *piVar20;
        *piVar20 = *piVar20 + -1;
        UNLOCK();
        if (iVar22 == 1 || iVar22 + -1 < 0) {
          (**(code **)(*(int *)*piVar7 + 4))();
        }
      }
      pdStack_118 = (double *)((int)pdStack_118 + 0x15);
      piStack_12c = piStack_12c + 5;
      pdVar18 = (double *)((int)pdVar18 + 1);
      puVar21 = puVar21 + 2;
    } while ((int)pdVar18 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
  }
  iVar22 = *(int *)(local_150 + 8);
  pdStack_148 = (double *)0x0;
  if (*(int *)(iVar22 + 0x2404) < 1) {
LAB_00428c71:
    DAT_00baed2a = 0;
    iVar16 = local_fc;
  }
  else {
    do {
      pdVar18 = pdStack_148;
      dVar1 = ((double)(int)(&target_sc_cnt)[(int)pdStack_148] * 100.0) /
              (double)*(int *)(local_150 + 0x3ffc);
      dVar3 = (double)local_fc;
      if ((dVar3 < dVar1 != (dVar3 == dVar1)) && (pdStack_148 != local_16c)) {
        if (dVar1 <= dVar3) {
          if (dVar3 == dVar1) {
            iVar22 = (int)local_16c * 0x15 + (int)pdStack_148;
            iVar16 = (&g_AllyTrustScore_Hi)[iVar22 * 2];
            uVar6 = (&g_AllyTrustScore)[iVar22 * 2];
            iVar19 = (int)local_16c * 0x15 + (int)local_128;
            iVar8 = (&g_AllyTrustScore_Hi)[iVar19 * 2];
            uVar2 = (&g_AllyTrustScore)[iVar19 * 2];
            if ((iVar16 <= iVar8) &&
               (((iVar16 < iVar8 || (uVar6 <= uVar2)) &&
                ((int)(&DAT_00634e90)[iVar22] <= (int)(&DAT_00634e90)[iVar19])))) {
              if ((iVar8 < iVar16) || ((iVar8 <= iVar16 && (uVar2 <= uVar6)))) {
                if (((uVar2 == uVar6) &&
                    ((iVar8 == iVar16 &&
                     ((int)(&DAT_006340c0)[iVar22] < (int)(&DAT_006340c0)[iVar19])))) &&
                   (local_128 = pdStack_148, 0x3b < local_fc)) {
                  SEND_LOG(&pvStack_174,
                           L"Due to a proximity to victory tie, We are siding with power that we fea r less"
                          );
                  pdStack_118 = (double *)0x2a;
                  pCVar13 = ATL::CSimpleStringT<char,0>::CloneData
                                      ((CStringData *)((int)pvStack_174 + -0x10));
                  pCVar13 = pCVar13 + 0x10;
                  ppdVar31 = &pdStack_118;
                  piVar7 = aiStack_e4;
                  iStack_44._0_1_ = 0xd;
                  pCStack_114 = pCVar13;
                  goto LAB_00428a32;
                }
              }
              else {
                local_128 = pdStack_148;
                if (0x3b < local_fc) {
                  SEND_LOG(&pvStack_174,
                           (wchar_t *)
                           "Due to a proximity to victory tie, We are siding with power that we have  more trust"
                          );
                  pvVar5 = pvStack_174;
                  piVar7 = (int *)((int)pvStack_174 + -0x10);
                  pdStack_134 = (double *)0x2a;
                  puVar10 = (undefined4 *)
                            (**(code **)(**(int **)((int)pvStack_174 + -0x10) + 0x10))();
                  if ((*(int *)((int)pvVar5 + -4) < 0) || (puVar10 != (undefined4 *)*piVar7)) {
                    piVar7 = (int *)(**(code **)*puVar10)(*(undefined4 *)((int)pvVar5 + -0xc));
                    if (piVar7 == (int *)0x0) goto LAB_0042796a;
                    piVar7[1] = *(int *)((int)pvVar5 + -0xc);
                    rVar11 = *(int *)((int)pvVar5 + -0xc) + 1;
                    _memcpy_s(piVar7 + 4,rVar11,pvVar5,rVar11);
                  }
                  else {
                    LOCK();
                    *(int *)((int)pvVar5 + -4) = *(int *)((int)pvVar5 + -4) + 1;
                    UNLOCK();
                  }
                  pCVar13 = (CStringData *)(piVar7 + 4);
                  ppdVar31 = &pdStack_134;
                  piVar7 = &iStack_168;
                  iStack_44._0_1_ = 0xc;
                  pCStack_130 = pCVar13;
LAB_00428a32:
                  BuildAllianceMsg(&DAT_00bbf638,piVar7,(int *)ppdVar31);
                  iStack_44._0_1_ = 0;
                  pCVar12 = pCVar13 + -4;
                  LOCK();
                  iVar22 = *(int *)pCVar12;
                  *(int *)pCVar12 = *(int *)pCVar12 + -1;
                  UNLOCK();
                  if (iVar22 == 1 || iVar22 + -1 < 0) {
                    (**(code **)(**(int **)(pCVar13 + -0x10) + 4))();
                  }
                }
              }
            }
          }
        }
        else {
          uVar29 = FloatToInt64(iVar22,local_150);
          local_fc = (int)uVar29;
          local_128 = pdVar18;
        }
      }
      iVar16 = local_fc;
      pdStack_148 = (double *)((int)pdVar18 + 1);
      iVar22 = local_150;
    } while ((int)pdStack_148 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
    if ((local_fc < 0x50) ||
       ((double)(&DAT_0062e360)[(int)local_128] <= (double)(&DAT_0062e360)[(int)local_16c] + 15.0))
    {
      if ((local_fc < 0x3c) ||
         ((double)(&DAT_0062e360)[(int)local_128] <= (double)(&DAT_0062e360)[(int)local_16c] + 25.0)
         ) goto LAB_00428c71;
      DAT_00baed2a = 1;
      SEND_LOG(&pvStack_174,L"We are requesting a DRAW");
      pdStack_134 = (double *)0x2b;
      pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_130 = pCVar12 + 0x10;
      iStack_44._0_1_ = 0xf;
      BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,(int *)&pdStack_134);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
    }
    else {
      DAT_00baed2a = 1;
      SEND_LOG(&pvStack_174,L"We are requesting a DRAW");
      pdStack_134 = (double *)0x2b;
      pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_130 = pCVar12 + 0x10;
      iStack_44._0_1_ = 0xe;
      BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,(int *)&pdStack_134);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
    }
    iStack_44._0_1_ = 0;
    if (iVar22 + -1 < 1) {
      (**(code **)(**(int **)pCVar12 + 4))();
    }
  }
  if (DAT_00baed30 == '\x01') {
    SEND_LOG(&pvStack_174,L"We are requesting a DRAW; because the map is static");
    pdStack_134 = (double *)0x2b;
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
    pCStack_130 = pCVar12 + 0x10;
    iStack_44._0_1_ = 0x10;
    BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,(int *)&pdStack_134);
    iStack_44._0_1_ = 0;
    pCVar13 = pCVar12 + 0xc;
    LOCK();
    iVar22 = *(int *)pCVar13;
    *(int *)pCVar13 = *(int *)pCVar13 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(**(int **)pCVar12 + 4))();
    }
  }
  pdVar18 = local_16c;
  bVar26 = false;
  if (0x3b < iVar16) {
    pdStack_148 = (double *)((int)local_16c * 0x15);
    pdVar14 = (double *)((int)pdStack_148 + (int)local_128);
    pdStack_134 = pdVar14;
    if ((-1 < (int)(&g_AllyTrustScore_Hi)[(int)pdVar14 * 2]) &&
       ((((0 < (int)(&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] ||
          (0xb < (uint)(&g_AllyTrustScore)[(int)pdVar14 * 2])) &&
         (0.0 < ((double)(&g_PowerExpScore)[(int)local_16c] -
                (double)(&g_PowerExpScore)[(int)local_128] * 1.7) + 69.0)) &&
        (((&DAT_006340c0)[(int)pdVar14] == 1 || ((&DAT_006340c0)[(int)pdVar14] == 2)))))) {
      puVar30 = (ushort *)&uStack_138;
      bVar26 = true;
      uStack_138 = (double *)(CONCAT22(uStack_138._2_2_,(short)local_128) & 0xffff00ff | 0x4100);
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,
               (wchar_t *)
               "Other power (%s) is close to Victory: But I will keep my alliance with him");
      pdStack_118 = (double *)0x2c;
      pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_114 = pCVar12 + 0x10;
      iStack_44._0_1_ = 0x11;
      BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,(int *)&pdStack_118);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
      if (iVar22 == 1 || iVar22 + -1 < 0) {
        (**(code **)(**(int **)pCVar12 + 4))();
      }
    }
    if (((double)(&DAT_0062e360)[(int)local_128] <= (double)(&DAT_0062e360)[(int)pdVar18]) ||
       (bVar26)) goto LAB_00429317;
    puVar30 = (ushort *)&uStack_138;
    DAT_00baed69 = '\x01';
    uStack_170 = CONCAT22(uStack_170._2_2_,(short)local_128) & 0xffff00ff | 0x4100;
    uStack_138 = (double *)(CONCAT22(uStack_138._2_2_,(short)local_128) & 0xffff00ff | 0x4100);
    DAT_0062480c = local_128;
    p_Var9 = _AfxAygshellState();
    GetProvinceToken(p_Var9,puVar30);
    SEND_LOG(&pvStack_174,L"Other power (%s) is close to Victory");
    pdStack_118 = (double *)0x2c;
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
    pCStack_114 = pCVar12 + 0x10;
    iStack_44._0_1_ = 0x12;
    BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,(int *)&pdStack_118);
    iStack_44._0_1_ = 0;
    pCVar13 = pCVar12 + 0xc;
    LOCK();
    iVar22 = *(int *)pCVar13;
    *(int *)pCVar13 = *(int *)pCVar13 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(**(int **)pCVar12 + 4))();
    }
    pdVar15 = (double *)0x0;
    if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
      piVar20 = &DAT_00634e90 + (int)pdVar18 * 0x15;
      pdStack_118 = (double *)(&g_AllyTrustScore + (int)pdVar18 * 0x2a);
      local_11c = &g_AllyTrustScore + (int)local_128 * 2;
      piStack_12c = &DAT_00633f1c;
      piVar7 = &DAT_00634e90 + (int)pdVar18;
      do {
        pdVar18 = DAT_0062480c;
        (&DAT_004cf568)[(int)pdVar15 * 2] = 0;
        (&DAT_004cf56c)[(int)pdVar15 * 2] = 0;
        (&DAT_00b9fdd8)[(int)pdVar15] = pdVar18;
        if (pdVar15 != local_128) {
          if ((0x4f < local_fc) && ((double)(&DAT_0062e360)[*piStack_12c] < 75.0)) {
            iVar22 = (int)local_128 * 0x15 + (int)pdVar15;
            (&DAT_00634e90)[iVar22] = 0;
            (&g_AllyTrustScore)[iVar22 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
            puVar30 = (ushort *)&uStack_138;
            uStack_138 = (double *)CONCAT22(uStack_138._2_2_,(ushort)uStack_170);
            p_Var9 = _AfxAygshellState();
            GetProvinceToken(p_Var9,puVar30);
            SEND_LOG(&pvStack_174,(wchar_t *)"We assume that (%s) is at war with everyone");
            local_ec = 0x2d;
            pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
            pCStack_e8 = pCVar12 + 0x10;
            iStack_44._0_1_ = 0x13;
            BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,&local_ec);
            iStack_44._0_1_ = 0;
            pCVar13 = pCVar12 + 0xc;
            LOCK();
            iVar22 = *(int *)pCVar13;
            *(int *)pCVar13 = *(int *)pCVar13 + -1;
            UNLOCK();
            if (iVar22 == 1 || iVar22 + -1 < 0) {
              (**(code **)(**(int **)pCVar12 + 4))();
            }
          }
          if (local_fc < 0x55) {
            if ((local_fc < 0x50) ||
               (*(int *)pdStack_118 != 0 || *(int *)((int)pdStack_118 + 4) != 0)) {
              if ((local_fc < 0x46) ||
                 (*(int *)pdStack_118 != 0 || *(int *)((int)pdStack_118 + 4) != 0)) {
                iVar22 = *piVar20;
                if ((-0x15 < iVar22) &&
                   (*(int *)pdStack_118 == 0 && *(int *)((int)pdStack_118 + 4) == 0))
                goto LAB_00429297;
              }
              else {
                if (65.0 <= (double)(&DAT_0062e360)[(int)pdVar15]) {
                  if (*piVar20 < -10) {
                    *piVar20 = -10;
                  }
                }
                else {
                  iVar22 = *piVar20;
LAB_00429297:
                  if (iVar22 < 0) {
                    *piVar20 = 0;
                  }
                }
                if (*piVar7 < -10) {
                  *piVar7 = -10;
                }
              }
            }
            else if (70.0 <= (double)(&DAT_0062e360)[(int)pdVar15]) {
              if (*piVar20 < 0) {
                *piVar20 = 0;
              }
              if (*piVar7 < 0) {
                *piVar7 = 0;
              }
            }
            else {
              if (*piVar20 < 0xf) {
                *piVar20 = 0xf;
              }
              if (*piVar7 < 5) {
                *piVar7 = 5;
              }
              (&DAT_004cf4c0)[(int)pdVar15 * 2] = 0;
              (&DAT_004cf4c4)[(int)pdVar15 * 2] = 0;
            }
          }
          else {
            iVar22 = 0;
            if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
              puVar10 = &DAT_00634e90 + (int)pdVar15;
              do {
                *puVar10 = 0x32;
                iVar22 = iVar22 + 1;
                puVar10 = puVar10 + 0x15;
              } while (iVar22 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
            }
            dVar1 = (double)(&DAT_0062e360)[(int)pdVar15];
            *local_11c = 0;
            local_11c[1] = 0;
            iVar22 = (int)local_128 * 0x15 + (int)pdVar15;
            (&g_AllyTrustScore)[iVar22 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
            (&DAT_00634e90)[iVar22] = 0;
            if (75.0 <= dVar1) {
              if (*piVar20 < 5) {
                *piVar20 = 5;
              }
              if (*piVar7 < 0) {
                *piVar7 = 0;
              }
            }
            else {
              *piVar20 = 0x32;
              if (*piVar7 < 0xf) {
                *piVar7 = 0xf;
              }
            }
            (&DAT_004cf4c0)[(int)pdVar15 * 2] = 0;
            (&DAT_004cf4c4)[(int)pdVar15 * 2] = 0;
            SEND_LOG(&pvStack_174,
                     L"We are trusting every other power 100 percent: unless it is getting close to victory"
                    );
            iStack_168 = 0x2d;
            pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
            pCStack_164 = pCVar12 + 0x10;
            iStack_44._0_1_ = 0x14;
            BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
            iStack_44._0_1_ = 0;
            pCVar13 = pCVar12 + 0xc;
            LOCK();
            iVar22 = *(int *)pCVar13;
            *(int *)pCVar13 = *(int *)pCVar13 + -1;
            UNLOCK();
            if (iVar22 == 1 || iVar22 + -1 < 0) {
              (**(code **)(**(int **)pCVar12 + 4))();
            }
          }
        }
        piStack_12c = piStack_12c + 5;
        pdStack_118 = pdStack_118 + 1;
        local_11c = local_11c + 0x2a;
        pdVar15 = (double *)((int)pdVar15 + 1);
        piVar20 = piVar20 + 1;
        piVar7 = piVar7 + 0x15;
        pdVar14 = pdStack_134;
      } while ((int)pdVar15 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
    }
    (&DAT_004cf568)[(int)local_128 * 2] = 1;
    (&DAT_004cf56c)[(int)local_128 * 2] = 0;
    (&g_AllyTrustScore)[(int)pdVar14 * 2] = 0;
    (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
    goto LAB_0042ac27;
  }
LAB_00429317:
  pdVar18 = local_144;
  if (DAT_00baed5f == '\0') goto LAB_0042bff2;
  pdVar15 = (double *)((int)local_16c * 0x15);
  pdVar14 = (double *)((int)local_144 + (int)pdVar15);
  iVar22 = (&g_AllyTrustScore)[(int)pdVar14 * 2];
  iVar16 = (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2];
  puVar21 = &g_AllyTrustScore + (int)pdVar14 * 2;
  pdStack_148 = pdVar15;
  uStack_138 = pdVar14;
  if ((iVar22 == 0 && iVar16 == 0) &&
     (pdStack_118 = (double *)((int)local_13c + (int)pdVar15),
     (&g_AllyTrustScore)[(int)pdStack_118 * 2] == 0 &&
     (&g_AllyTrustScore_Hi)[(int)pdStack_118 * 2] == 0)) {
    SEND_LOG(&pvStack_174,(wchar_t *)"We are at war with our top 2 enemies");
    iStack_168 = 0x2e;
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
    pCStack_164 = pCVar12 + 0x10;
    iStack_44._0_1_ = 0x15;
    BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
    iStack_44._0_1_ = 0;
    pCVar13 = pCVar12 + 0xc;
    LOCK();
    iVar22 = *(int *)pCVar13;
    *(int *)pCVar13 = *(int *)pCVar13 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(**(int **)pCVar12 + 4))();
    }
    if (local_13c == local_16c) {
      (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
      (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
      goto LAB_0042ac27;
    }
    if ((int)(&DAT_00634e90)[(int)pdStack_118] <= (int)(&DAT_00634e90)[(int)uStack_138]) {
      if (((&DAT_004cf4c0)[(int)local_13c * 2] == 0 && (&DAT_004cf4c4)[(int)local_13c * 2] == 0) &&
         ((&DAT_0062b7b0)[(int)pdStack_118] == 0)) {
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
        (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)
                 "We select (%s) as enemy because we we maybe getting a peace signal from poss enemy 2"
                );
        iStack_168 = 0x2f;
        pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCStack_164 + 0x10;
        iStack_44._0_1_ = 0x17;
      }
      else if (((&DAT_004cf4c0)[(int)pdVar18 * 2] == 0 && (&DAT_004cf4c4)[(int)pdVar18 * 2] == 0) &&
              ((&DAT_0062b7b0)[(int)uStack_138] == 0)) {
        (&DAT_004cf568)[(int)local_13c * 2] = 1;
        (&DAT_004cf56c)[(int)local_13c * 2] = 0;
        puVar30 = (ushort *)&uStack_170;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)
                 "We select (%s) as enemy because we we maybe getting a peace signal from poss enemy 1"
                );
        iStack_168 = 0x2f;
        pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCStack_164 + 0x10;
        iStack_44._0_1_ = 0x18;
      }
      else {
        iVar22 = _rand();
        iVar22 = (iVar22 / 0x17) % 100;
        uVar29 = FloatToInt64(100,iVar22);
        if (iVar22 < (int)uVar29) {
          puVar30 = (ushort *)&uStack_170;
          (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
          (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
          uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          SEND_LOG(&pvStack_174,
                   (wchar_t *)"We select (%s) by random selection (random number %d < %d)");
          iStack_168 = 0x30;
          pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
          pCStack_164 = pCStack_164 + 0x10;
          iStack_44._0_1_ = 0x19;
        }
        else {
          puVar30 = (ushort *)&uStack_170;
          (&DAT_004cf568)[(int)local_13c * 2] = 1;
          (&DAT_004cf56c)[(int)local_13c * 2] = 0;
          uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          SEND_LOG(&pvStack_174,
                   (wchar_t *)"We select (%s) by random selection (random number %d > %d)");
          iStack_168 = 0x30;
          pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
          pCStack_164 = pCStack_164 + 0x10;
          iStack_44._0_1_ = 0x1a;
        }
      }
      goto LAB_0042a6aa;
    }
    puVar30 = (ushort *)&uStack_170;
    (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
    (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
    uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
    p_Var9 = _AfxAygshellState();
    GetProvinceToken(p_Var9,puVar30);
    SEND_LOG(&pvStack_174,(wchar_t *)"We select (%s) as enemy because we trust him less");
    iStack_168 = 0x2f;
    pCVar13 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
    iStack_44._0_1_ = 0x16;
LAB_004294b4:
    pCVar12 = pCVar13 + 0x10;
    pCStack_164 = pCVar12;
    BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
    iStack_44._0_1_ = 0;
    pCVar13 = pCVar13 + 0xc;
    LOCK();
    iVar22 = *(int *)pCVar13;
    *(int *)pCVar13 = *(int *)pCVar13 + -1;
    UNLOCK();
LAB_0042a6cc:
    iStack_44._0_1_ = 0;
    if (iVar22 + -1 < 1) {
      (**(code **)(**(int **)(pCVar12 + -0x10) + 4))();
    }
  }
  else {
    if ((g_OpeningStickyMode == '\x01') && (g_DeceitLevel < 3)) {
      puVar30 = (ushort *)&uStack_170;
      uStack_170 = CONCAT22(uStack_170._2_2_,(ushort)(byte)g_OpeningEnemy) | 0x4100;
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,
               (wchar_t *)"We are at war with our opening selected enemy (%s) and sticking with it")
      ;
      iStack_168 = 0x32;
      pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_164 = pCVar12 + 0x10;
      iStack_44._0_1_ = 0x1b;
      BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
      if (iVar22 == 1 || iVar22 + -1 < 0) {
        (**(code **)(**(int **)pCVar12 + 4))();
      }
      iVar22 = g_OpeningEnemy;
      (&DAT_004cf568)[g_OpeningEnemy * 2] = 1;
      (&DAT_004cf56c)[iVar22 * 2] = 0;
      iVar22 = iVar22 + (int)pdVar15;
      (&g_AllyTrustScore)[iVar22 * 2] = 0;
      (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
      goto LAB_0042ac27;
    }
    if ((iVar22 == 0 && iVar16 == 0) ||
       (iVar8 = (int)local_13c + (int)pdVar15,
       (&g_AllyTrustScore)[iVar8 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar8 * 2] == 0)) {
LAB_0042a06b:
      SEND_LOG(&pvStack_174,
               (wchar_t *)
               "We are at war with at least one of our Top 3 enemies and need to validate");
      iStack_168 = 0x32;
      pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_164 = pCVar12 + 0x10;
      iStack_44._0_1_ = 0x1c;
      BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
      if (iVar22 == 1 || iVar22 + -1 < 0) {
        (**(code **)(**(int **)pCVar12 + 4))();
      }
      pdVar18 = local_13c;
      if (*puVar21 == 0 && (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] == 0) {
        (&DAT_004cf568)[(int)local_144 * 2] = 1;
        (&DAT_004cf56c)[(int)local_144 * 2] = 0;
        puVar30 = (ushort *)&uStack_170;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)"We have validated possible enemy 1 (%s) as our identified enemy");
        iStack_168 = 0x33;
        pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCStack_164 + 0x10;
        iStack_44._0_1_ = 0x1d;
      }
      else {
        pdStack_118 = (double *)((int)local_13c + (int)pdVar15);
        local_11c = &g_AllyTrustScore + (int)pdStack_118 * 2;
        if (((((&g_AllyTrustScore)[(int)pdStack_118 * 2] != 0 ||
               (&g_AllyTrustScore_Hi)[(int)pdStack_118 * 2] != 0) || (local_13c == local_16c)) ||
            (dVar1 = ((double)(&g_InfluenceMatrix_Alt)[(int)pdStack_118] * 100.0) /
                     ((double)(&g_InfluenceMatrix_Alt)[(int)uStack_138] + 1.0), dVar1 <= 20.0)) ||
           ((dVar1 <= 70.0 &&
            (((double)(&g_PowerExpScore)[(int)local_16c] -
             (double)(&g_PowerExpScore)[(int)local_144] * 1.7) + 69.0 <= 0.0)))) {
          iVar22 = (int)local_f0 + (int)pdVar15;
          if (((&g_AllyTrustScore)[iVar22 * 2] != 0 || (&g_AllyTrustScore_Hi)[iVar22 * 2] != 0) ||
             (((double)(&g_InfluenceMatrix_Alt)[iVar22] <= 15.0 || (local_f0 == local_16c)))) {
LAB_0042a6ef:
            SEND_LOG(&pvStack_174,
                     L"Our Current enemy does not meet the criteria: rechoose a new one");
            iStack_168 = 0x33;
            pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
            pCStack_164 = pCVar12 + 0x10;
            iStack_44._0_1_ = 0x22;
            BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
            iStack_44._0_1_ = 0;
            pCVar13 = pCVar12 + 0xc;
            LOCK();
            iVar22 = *(int *)pCVar13;
            *(int *)pCVar13 = *(int *)pCVar13 + -1;
            UNLOCK();
            if (iVar22 == 1 || iVar22 + -1 < 0) {
              (**(code **)(**(int **)pCVar12 + 4))();
            }
            iVar16 = _rand();
            iVar22 = _rand();
            iVar8 = (iVar22 / 0x17) % 0x32;
            uStack_170 = 1;
            piStack_12c = (int *)0x1;
            iVar22 = (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2];
            if ((-1 < iVar22) && ((0 < iVar22 || (2 < *puVar21)))) {
              if ((iVar22 < 0) || ((iVar22 < 1 && (*puVar21 < 5)))) {
                uStack_170 = 3;
              }
              else {
                uStack_170 = 4;
              }
            }
            uVar6 = *local_11c;
            uVar2 = local_11c[1];
            if ((-1 < (int)uVar2) && ((0 < (int)uVar2 || (2 < uVar6)))) {
              if (((int)uVar2 < 0) || (((int)uVar2 < 1 && (uVar6 < 5)))) {
                piStack_12c = (int *)0x3;
              }
              else {
                piStack_12c = (int *)0x4;
              }
            }
            pdVar18 = (double *)(&g_InfluenceMatrix_Alt + (int)uStack_138);
            pdStack_134 = (double *)(&g_InfluenceMatrix_Alt + (int)pdStack_118);
            uVar29 = FloatToInt64(uVar6,iVar8);
            pdVar23 = local_13c;
            pdVar15 = local_144;
            if ((int)DAT_004c6bc4 < 0) {
LAB_0042aa75:
              if ((iVar8 + (iVar16 / 0x17) % 0x32 < (int)uVar29) || (local_13c == local_16c)) {
                puVar30 = (ushort *)&uStack_170;
                (&DAT_004cf568)[(int)local_144 * 2] = 1;
                (&DAT_004cf56c)[(int)local_144 * 2] = 0;
                *puVar21 = 0;
                (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
                uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
                p_Var9 = _AfxAygshellState();
                GetProvinceToken(p_Var9,puVar30);
                SEND_LOG(&pvStack_174,
                         (wchar_t *)
                         "New selection is possible enemy 1 (%s) as our identified enemy (random num ber %d < %d)"
                        );
                iStack_168 = 0x34;
                pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                        ((CStringData *)((int)pvStack_174 + -0x10));
                pCStack_164 = pCStack_164 + 0x10;
                iStack_44._0_1_ = 0x25;
                goto LAB_0042abc6;
              }
              (&DAT_004cf56c)[(int)local_13c * 2] = 0;
              *local_11c = 0;
              local_11c[1] = 0;
              puVar30 = (ushort *)&uStack_170;
              (&DAT_004cf568)[(int)local_13c * 2] = 1;
              uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              SEND_LOG(&pvStack_174,
                       (wchar_t *)
                       "New selection is possible enemy 2 (%s) as our identified enemy (random numbe r %d > %d)"
                      );
              iStack_168 = 0x34;
              pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
              pCStack_164 = pCVar12 + 0x10;
              iStack_44._0_1_ = 0x26;
              BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
              iStack_44._0_1_ = 0;
              pCVar13 = pCVar12 + 0xc;
              LOCK();
              iVar22 = *(int *)pCVar13;
              *(int *)pCVar13 = *(int *)pCVar13 + -1;
              UNLOCK();
            }
            else {
              if (local_144 != DAT_004c6bc4) {
                if ((((local_13c == DAT_004c6bc4) && (local_13c != local_16c)) &&
                    (fVar27 = (extraout_ST0_00 * (float10)*pdStack_134) /
                              ((float10)*pdVar18 + (float10)1.0), (float10)20.0 < fVar27)) &&
                   (((float10)70.0 < fVar27 ||
                    (0.0 < ((double)(&g_PowerExpScore)[(int)local_16c] -
                           (double)(&g_PowerExpScore)[(int)local_144] * 1.45) + 41.0)))) {
                  puVar30 = (ushort *)&uStack_170;
                  (&DAT_004cf568)[(int)local_144 * 2] = 1;
                  (&DAT_004cf56c)[(int)local_144 * 2] = 0;
                  *puVar21 = 0;
                  (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
                  uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
                  p_Var9 = _AfxAygshellState();
                  GetProvinceToken(p_Var9,puVar30);
                  SEND_LOG(&pvStack_174,
                           (wchar_t *)
                           "New selection is possible enemy 1 (%s) as our identified enemy - we are keeping our opening alliance"
                          );
                  iStack_168 = 0x34;
                  pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                          ((CStringData *)((int)pvStack_174 + -0x10));
                  pCStack_164 = pCStack_164 + 0x10;
                  iStack_44._0_1_ = 0x24;
                  goto LAB_0042abc6;
                }
                goto LAB_0042aa75;
              }
              *local_11c = 0;
              local_11c[1] = 0;
              (&DAT_004cf56c)[(int)local_13c * 2] = 0;
              puVar30 = (ushort *)&uStack_170;
              (&DAT_004cf568)[(int)local_13c * 2] = 1;
              uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              SEND_LOG(&pvStack_174,
                       (wchar_t *)
                       "New selection is possible enemy 2 (%s) as our identified enemy - we are keep ing our opening alliance)"
                      );
              iStack_168 = 0x34;
              pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
              pCStack_164 = pCVar12 + 0x10;
              iStack_44._0_1_ = 0x23;
              BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
              iStack_44._0_1_ = 0;
              pCVar13 = pCVar12 + 0xc;
              LOCK();
              iVar22 = *(int *)pCVar13;
              *(int *)pCVar13 = *(int *)pCVar13 + -1;
              UNLOCK();
            }
            iStack_44._0_1_ = 0;
            if (iVar22 + -1 < 1) {
              (**(code **)(**(int **)pCVar12 + 4))();
            }
            piVar7 = &g_AllyTrustScore + ((int)pdVar23 * 0x15 + (int)local_16c) * 2;
            goto LAB_0042ac0f;
          }
          if ((((double)(&g_InfluenceMatrix_Alt)[iVar22] * 100.0) /
               ((double)(&g_InfluenceMatrix_Alt)[(int)uStack_138] + 1.0) <= 20.0) ||
             ((((double)(&g_InfluenceMatrix_Alt)[iVar22] * 100.0) /
               ((double)(&g_InfluenceMatrix_Alt)[(int)pdStack_118] + 1.0) <= 50.0 ||
              ((((double)(&g_InfluenceMatrix_Alt)[(int)pdStack_118] * 100.0) /
                ((double)(&g_InfluenceMatrix_Alt)[(int)uStack_138] + 1.0) <= 70.0 &&
               (((double)(&g_PowerExpScore)[(int)local_16c] -
                (double)(&g_PowerExpScore)[(int)local_144] * 1.7) + 69.0 <= 0.0))))))
          goto LAB_0042a6ef;
          (&DAT_004cf568)[(int)local_f0 * 2] = 1;
          (&DAT_004cf56c)[(int)local_f0 * 2] = 0;
          puVar30 = (ushort *)&uStack_170;
          uStack_170 = CONCAT22(uStack_170._2_2_,uStack_fe);
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          SEND_LOG(&pvStack_174,
                   (wchar_t *)"We have validated possible enemy 3 (%s) as our identified enemy");
          iStack_168 = 0x33;
          pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                              ((CStringData *)((int)pvStack_174 + -0x10));
          pCStack_164 = pCVar12 + 0x10;
          iStack_44._0_1_ = 0x1f;
          BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
          iStack_44._0_1_ = 0;
          pCVar13 = pCVar12 + 0xc;
          LOCK();
          iVar22 = *(int *)pCVar13;
          *(int *)pCVar13 = *(int *)pCVar13 + -1;
          UNLOCK();
          if (iVar22 == 1 || iVar22 + -1 < 0) {
            (**(code **)(**(int **)pCVar12 + 4))();
          }
          if (((int)local_11c[1] < 0) ||
             (((((int)local_11c[1] < 1 && (*local_11c < 7)) || (DAT_004c6bc4 == local_144)) ||
              (1 < (int)(&DAT_00633780)[(int)uStack_138])))) {
            if ((((-1 < (int)(&g_AllyTrustScore_Hi)[(int)pdVar14 * 2]) &&
                 (((0 < (int)(&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] || (6 < *puVar21)) &&
                  ((DAT_004c6bc4 != pdVar18 &&
                   (((int)(&DAT_00633780)[(int)pdStack_118] < 2 &&
                    (iVar22 = (int)pdVar18 * 0x15 + (int)local_144,
                    (&g_AllyTrustScore)[iVar22 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar22 * 2] == 0)
                    ))))))) &&
                (1.0 < (double)(&g_InfluenceMatrix_Raw)[(int)pdVar18 * 0x15 + (int)local_16c] /
                       ((double)(&g_InfluenceMatrix_Raw)[(int)pdStack_118] + 1.0))) &&
               (pdVar18 != local_16c)) {
              puVar30 = (ushort *)&uStack_170;
              (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
              (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
              *local_11c = 0;
              local_11c[1] = 0;
              uStack_170._0_2_ = uStack_14a;
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              puVar30 = (ushort *)&uStack_170;
              uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              SEND_LOG(&pvStack_174,
                       (wchar_t *)
                       "We are attempting to gang up on our #2 (%s): with our good ally (%s)");
              iStack_168 = 0x33;
              pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                      ((CStringData *)((int)pvStack_174 + -0x10));
              pCStack_164 = pCStack_164 + 0x10;
              iStack_44._0_1_ = 0x21;
              goto LAB_0042a6aa;
            }
          }
          else {
            iVar22 = (int)local_144 * 0x15 + (int)pdVar18;
            if ((((&g_AllyTrustScore)[iVar22 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar22 * 2] == 0)
                && (1.0 < (double)(&g_InfluenceMatrix_Raw)[(int)local_144 * 0x15 + (int)local_16c] /
                          ((double)(&g_InfluenceMatrix_Raw)[(int)uStack_138] + 1.0))) &&
               (local_144 != local_16c)) {
              (&DAT_004cf568)[(int)local_144 * 2] = 1;
              (&DAT_004cf56c)[(int)local_144 * 2] = 0;
              puVar30 = (ushort *)&uStack_170;
              *puVar21 = 0;
              (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
              uStack_170._0_2_ = uStack_14a;
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              puVar30 = (ushort *)&uStack_170;
              uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              SEND_LOG(&pvStack_174,
                       (wchar_t *)
                       "We are attempting to gang up on our #1 (%s): with our good ally (%s)");
              iStack_168 = 0x33;
              pCVar13 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
              iStack_44._0_1_ = 0x20;
              goto LAB_004294b4;
            }
          }
          goto LAB_0042ac27;
        }
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)local_13c * 2] = 1;
        (&DAT_004cf56c)[(int)local_13c * 2] = 0;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,L"We have validated possible enemy 2 (%s) as our identified enemy");
        iStack_168 = 0x33;
        pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCStack_164 + 0x10;
        iStack_44._0_1_ = 0x1e;
      }
LAB_0042a6aa:
      pCVar12 = pCStack_164;
      BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + -4;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
      goto LAB_0042a6cc;
    }
    iStack_168 = (&g_AllyTrustScore)[((int)local_f0 + (int)pdVar15) * 2];
    iVar19 = (&g_AllyTrustScore_Hi)[((int)local_f0 + (int)pdVar15) * 2];
    if (iStack_168 == 0 && iVar19 == 0) goto LAB_0042a06b;
    if (((((iVar16 < 0) || ((iVar16 < 1 && (iVar22 == 0)))) ||
         ((int)(&g_AllyTrustScore_Hi)[iVar8 * 2] < 0)) ||
        ((((int)(&g_AllyTrustScore_Hi)[iVar8 * 2] < 1 && ((&g_AllyTrustScore)[iVar8 * 2] == 0)) ||
         ((iVar19 < 0 || ((iVar19 < 1 && (iStack_168 == 0)))))))) ||
       ((2 < (int)uStack_170 && (2 < g_DeceitLevel)))) goto LAB_0042ac27;
    SEND_LOG(&pvStack_174,L"We are at peace with top 3 possible enemies and need to select one");
    iStack_168 = 0x35;
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
    pCStack_164 = pCVar12 + 0x10;
    iStack_44._0_1_ = 0x27;
    BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
    iStack_44._0_1_ = 0;
    pCVar13 = pCVar12 + 0xc;
    LOCK();
    iVar22 = *(int *)pCVar13;
    *(int *)pCVar13 = *(int *)pCVar13 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(**(int **)pCVar12 + 4))();
    }
    iVar22 = _rand();
    iVar16 = _rand();
    uStack_170 = 1;
    piStack_12c = (int *)0x1;
    pdStack_134 = (double *)((iVar16 / 0x17) % 0x32 + (iVar22 / 0x17) % 0x32);
    if ((-1 < (int)(&g_AllyTrustScore_Hi)[(int)pdVar14 * 2]) &&
       ((0 < (int)(&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] || (2 < *puVar21)))) {
      uStack_170 = 3;
    }
    if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar8 * 2]) &&
       ((0 < (int)(&g_AllyTrustScore_Hi)[iVar8 * 2] || (2 < (uint)(&g_AllyTrustScore)[iVar8 * 2]))))
    {
      piStack_12c = (int *)0x3;
    }
    pdVar18 = (double *)(&g_InfluenceMatrix_Alt + (int)uStack_138);
    uStack_138 = pdVar18;
    uVar29 = FloatToInt64(0x32,pdStack_134);
    pdVar15 = local_144;
    pdStack_118 = (double *)uVar29;
    fVar27 = extraout_ST0;
    if (g_HistoryCounter < 10) {
LAB_00429d0f:
      pdVar15 = local_13c;
      if (-1 < (int)DAT_004c6bc4) {
        if (local_144 == DAT_004c6bc4) {
          puVar30 = (ushort *)&uStack_170;
          (&DAT_004cf568)[(int)local_13c * 2] = 1;
          (&DAT_004cf56c)[(int)local_13c * 2] = 0;
          (&g_AllyTrustScore)[iVar8 * 2] = 0;
          (&g_AllyTrustScore_Hi)[iVar8 * 2] = 0;
          uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          SEND_LOG(&pvStack_174,
                   (wchar_t *)
                   "New selection is possible enemy 2 (%s) as our identified enemy - we are keeping our opening alliance)"
                  );
          iStack_168 = 0x36;
          pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
          pCStack_164 = pCStack_164 + 0x10;
          iStack_44._0_1_ = 0x2a;
          goto LAB_0042abc6;
        }
        if (((local_13c != DAT_004c6bc4) || (local_13c == local_16c)) ||
           ((fVar27 = (fVar27 * (float10)(double)(&g_InfluenceMatrix_Alt)[iVar8]) /
                      ((float10)*uStack_138 + (float10)1.0), fVar27 <= (float10)20.0 ||
            ((fVar27 <= (float10)70.0 &&
             (((double)(&g_PowerExpScore)[(int)local_16c] -
              (double)(&g_PowerExpScore)[(int)local_144] * 1.7) + 69.0 <= 0.0))))))
        goto LAB_00429efb;
        (&DAT_004cf568)[(int)local_144 * 2] = 1;
        (&DAT_004cf56c)[(int)local_144 * 2] = 0;
        puVar30 = (ushort *)&uStack_170;
        *puVar21 = 0;
        (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)
                 "New selection is possible enemy 1 (%s) as our identified enemy - we are keeping ou r opening alliance"
                );
        iStack_168 = 0x36;
        pCVar13 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        iStack_44._0_1_ = 0x2b;
LAB_00429ea4:
        pCStack_164 = pCVar13 + 0x10;
        BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
        iStack_44._0_1_ = 0;
        pCVar12 = pCVar13 + 0xc;
        LOCK();
        iVar22 = *(int *)pCVar12;
        *(int *)pCVar12 = *(int *)pCVar12 + -1;
        UNLOCK();
        if (iVar22 == 1 || iVar22 + -1 < 0) {
          (**(code **)(**(int **)pCVar13 + 4))();
        }
        piVar7 = &g_AllyTrustScore + ((int)local_144 * 0x15 + (int)local_16c) * 2;
        goto LAB_0042ac0f;
      }
LAB_00429efb:
      if (((int)pdStack_134 < (int)pdStack_118) || (local_13c == local_16c)) {
        (&DAT_004cf568)[(int)local_144 * 2] = 1;
        (&DAT_004cf56c)[(int)local_144 * 2] = 0;
        puVar30 = (ushort *)&uStack_170;
        *puVar21 = 0;
        (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)
                 "New selection is possible enemy 1 (%s) as our identified enemy (random number %d <  %d)"
                );
        iStack_168 = 0x36;
        pCVar13 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        iStack_44._0_1_ = 0x2c;
        goto LAB_00429ea4;
      }
      (&DAT_004cf56c)[(int)local_13c * 2] = 0;
      (&g_AllyTrustScore)[iVar8 * 2] = 0;
      (&g_AllyTrustScore_Hi)[iVar8 * 2] = 0;
      puVar30 = (ushort *)&uStack_170;
      (&DAT_004cf568)[(int)local_13c * 2] = 1;
      uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,
               (wchar_t *)
               "New selection is possible enemy 2 (%s) as our identified enemy (random number %d > % d)"
              );
      iStack_168 = 0x36;
      pCVar13 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_164 = pCVar13 + 0x10;
      iStack_44._0_1_ = 0x2d;
      BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
      iStack_44._0_1_ = 0;
      pCVar12 = pCVar13 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar12;
      *(int *)pCVar12 = *(int *)pCVar12 + -1;
      UNLOCK();
    }
    else {
      if ((((DAT_004c6bc4 != local_144) && ((int)local_11c < local_ec)) &&
          (fVar28 = ((float10)*pdVar18 * extraout_ST0) / ((float10)*pdVar18 + (float10)1.0),
          (float10)20.0 < fVar28)) &&
         (((float10)70.0 < fVar28 ||
          (0.0 < ((double)(&g_PowerExpScore)[(int)local_16c] -
                 (double)(&g_PowerExpScore)[(int)local_144] * 1.7) + 69.0)))) {
        (&DAT_004cf56c)[(int)local_144 * 2] = 0;
        *puVar21 = 0;
        (&g_AllyTrustScore_Hi)[(int)pdVar14 * 2] = 0;
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)local_144 * 2] = 1;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_152);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,(wchar_t *)"New selection is based on Alliances against (%s)");
        iStack_168 = 0x36;
        pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCVar12 + 0x10;
        iStack_44._0_1_ = 0x28;
        BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
        iStack_44._0_1_ = 0;
        pCVar13 = pCVar12 + 0xc;
        LOCK();
        iVar22 = *(int *)pCVar13;
        *(int *)pCVar13 = *(int *)pCVar13 + -1;
        UNLOCK();
        if (iVar22 == 1 || iVar22 + -1 < 0) {
          (**(code **)(**(int **)pCVar12 + 4))();
        }
        iVar22 = (int)pdVar15 * 0x15 + (int)local_16c;
        if (((&g_AllyTrustScore)[iVar22 * 2] == 1) && ((&g_AllyTrustScore_Hi)[iVar22 * 2] == 0)) {
          (&g_AllyTrustScore)[iVar22 * 2] = 0;
          (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
        }
        fVar27 = (float10)100.0;
      }
      pdVar15 = local_13c;
      if (((((g_HistoryCounter < 10) || (DAT_004c6bc4 == local_13c)) || ((int)local_11c <= local_ec)
           ) || (fVar28 = ((float10)(double)(&g_InfluenceMatrix_Alt)[iVar8] * fVar27) /
                          ((float10)(double)(&g_InfluenceMatrix_Alt)[iVar8] + (float10)1.0),
                fVar28 <= (float10)20.0)) ||
         ((fVar28 <= (float10)70.0 &&
          (((double)(&g_PowerExpScore)[(int)local_16c] -
           (double)(&g_PowerExpScore)[(int)local_13c] * 1.7) + 69.0 <= 0.0)))) goto LAB_00429d0f;
      puVar30 = (ushort *)&uStack_170;
      (&DAT_004cf568)[(int)local_13c * 2] = 1;
      (&DAT_004cf56c)[(int)local_13c * 2] = 0;
      (&g_AllyTrustScore)[iVar8 * 2] = 0;
      (&g_AllyTrustScore_Hi)[iVar8 * 2] = 0;
      uStack_170 = CONCAT22(uStack_170._2_2_,uStack_14a);
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,(wchar_t *)"New selection is based on Alliances against (%s)");
      iStack_168 = 0x36;
      pCStack_164 = ATL::CSimpleStringT<char,0>::CloneData
                              ((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_164 = pCStack_164 + 0x10;
      iStack_44._0_1_ = 0x29;
LAB_0042abc6:
      pCVar12 = pCStack_164;
      BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
      pCVar13 = pCVar12 + -0x10;
      pCVar12 = pCVar12 + -4;
      iStack_44._0_1_ = 0;
      LOCK();
      iVar22 = *(int *)pCVar12;
      *(int *)pCVar12 = *(int *)pCVar12 + -1;
      UNLOCK();
    }
    iStack_44._0_1_ = 0;
    if (iVar22 + -1 < 1) {
      (**(code **)(**(int **)pCVar13 + 4))();
    }
    piVar7 = &g_AllyTrustScore + ((int)pdVar15 * 0x15 + (int)local_16c) * 2;
LAB_0042ac0f:
    if ((*piVar7 == 1) && (piVar7[1] == 0)) {
      piVar7[1] = 0;
      *piVar7 = 0;
    }
  }
LAB_0042ac27:
  pdVar15 = local_f0;
  pdVar14 = pdStack_f8;
  pdVar18 = local_16c;
  if (DAT_00baed69 != '\0') {
    if (0x3b < local_fc) {
      if (((0x4b < local_fc) ||
          (iVar22 = (int)local_16c * 8,
          (double)(&DAT_0062e360)[(int)local_128] <= (double)(&DAT_0062e360)[(int)local_16c])) ||
         (dVar1 = (double)(&DAT_0062e360)[(int)local_16c],
         NAN(dVar1) || 20.0 < dVar1 == (dVar1 == 20.0))) {
        if (((local_fc < 0x56) &&
            ((double)(&DAT_0062e360)[(int)local_16c] < (double)(&DAT_0062e360)[(int)local_128])) &&
           (dVar1 = (double)(&DAT_0062e360)[(int)local_16c],
           !NAN(dVar1) && 20.0 < dVar1 != (dVar1 == 20.0))) {
          iVar22 = *(int *)(local_150 + 8);
          iVar16 = 0;
          if (0 < *(int *)(iVar22 + 0x2404)) {
            puVar10 = &g_AllyTrustScore + (int)local_16c * 0x2a;
            piVar7 = &g_AllyTrustScore + (int)local_16c * 2;
            do {
              if (((int)(&target_sc_cnt)[iVar16] < 2) && (FAL == *(short *)(iVar22 + 0x244a))) {
                (&DAT_004cf56c)[iVar16 * 2] = 0;
                *puVar10 = 0;
                puVar10[1] = 0;
                puVar30 = (ushort *)&uStack_170;
                (&DAT_004cf568)[iVar16 * 2] = 1;
                uStack_170 = CONCAT22(uStack_170._2_2_,(short)iVar16) & 0xffff00ff | 0x4100;
                p_Var9 = _AfxAygshellState();
                GetProvinceToken(p_Var9,puVar30);
                SEND_LOG(&pvStack_174,
                         (wchar_t *)
                         "We need to eliminate (%s): who has 1 SC (even though a power is close to v ictory)"
                        );
                iStack_168 = 0x3a;
                pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                    ((CStringData *)((int)pvStack_174 + -0x10));
                pCStack_164 = pCVar12 + 0x10;
                iStack_44._0_1_ = 0x3a;
                BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
                iStack_44._0_1_ = 0;
                pCVar13 = pCVar12 + 0xc;
                LOCK();
                iVar22 = *(int *)pCVar13;
                *(int *)pCVar13 = *(int *)pCVar13 + -1;
                UNLOCK();
                if (iVar22 == 1 || iVar22 + -1 < 0) {
                  (**(code **)(**(int **)pCVar12 + 4))();
                }
                if ((*piVar7 == 1) && (piVar7[1] == 0)) {
                  *piVar7 = 0;
                  piVar7[1] = 0;
                }
              }
              iVar22 = *(int *)(local_150 + 8);
              iVar16 = iVar16 + 1;
              puVar10 = puVar10 + 2;
              piVar7 = piVar7 + 0x2a;
            } while (iVar16 < *(int *)(iVar22 + 0x2404));
          }
        }
      }
      else {
        pdVar18 = (double *)0x0;
        if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
          iVar16 = (int)local_16c * 0xa8;
          do {
            if (((int)(&target_sc_cnt)[(int)pdVar18] < 2) ||
               ((((0.0 < *(double *)((int)&g_InfluenceMatrix_Alt + iVar16) && (pdVar18 != local_16c)
                  ) && (4.5 < *(double *)((int)&g_InfluenceMatrix_Raw + iVar22) /
                              (*(double *)((int)&g_InfluenceMatrix_Raw + iVar16) + 1.0))) &&
                (10.0 < *(double *)((int)&g_InfluenceMatrix_Alt + iVar22))))) {
              puVar30 = (ushort *)&uStack_170;
              (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
              (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
              *(undefined4 *)((int)&g_AllyTrustScore + iVar16) = 0;
              *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar16) = 0;
              uStack_170 = CONCAT22(uStack_170._2_2_,(short)pdVar18) & 0xffff00ff | 0x4100;
              p_Var9 = _AfxAygshellState();
              GetProvinceToken(p_Var9,puVar30);
              SEND_LOG(&pvStack_174,
                       (wchar_t *)
                       "We need to eliminate (%s): who is very weak (even though a power is close to  victory)"
                      );
              iStack_168 = 0x3a;
              pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                  ((CStringData *)((int)pvStack_174 + -0x10));
              pCStack_164 = pCVar12 + 0x10;
              iStack_44._0_1_ = 0x39;
              BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
              iStack_44._0_1_ = 0;
              pCVar13 = pCVar12 + 0xc;
              LOCK();
              iVar8 = *(int *)pCVar13;
              *(int *)pCVar13 = *(int *)pCVar13 + -1;
              UNLOCK();
              if (iVar8 == 1 || iVar8 + -1 < 0) {
                (**(code **)(**(int **)pCVar12 + 4))();
              }
              if ((*(int *)((int)&g_AllyTrustScore + iVar22) == 1) &&
                 (*(int *)((int)&g_AllyTrustScore_Hi + iVar22) == 0)) {
                *(undefined4 *)((int)&g_AllyTrustScore + iVar22) = 0;
                *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar22) = 0;
              }
            }
            pdVar18 = (double *)((int)pdVar18 + 1);
            iVar16 = iVar16 + 8;
            iVar22 = iVar22 + 0xa8;
          } while ((int)pdVar18 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
        }
      }
    }
    goto LAB_0042bff2;
  }
  uStack_138 = (double *)((int)pdStack_148 + (int)local_144);
  if ((((-1 < (int)(&g_AllyTrustScore_Hi)[(int)uStack_138 * 2]) &&
       ((0 < (int)(&g_AllyTrustScore_Hi)[(int)uStack_138 * 2] ||
        (3 < (uint)(&g_AllyTrustScore)[(int)uStack_138 * 2])))) &&
      (iVar22 = (int)local_13c + (int)pdStack_148,
      (&g_AllyTrustScore)[iVar22 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar22 * 2] == 0)) &&
     ((int)(&DAT_00633780)[iVar22] < 3)) {
    iVar22 = (int)local_144 * 0x15 + (int)local_f0;
    if ((((&g_AllyTrustScore)[iVar22 * 2] != 0 || (&g_AllyTrustScore_Hi)[iVar22 * 2] != 0) ||
        (iVar22 = (int)pdStack_148 + (int)local_f0,
        (double)(&g_InfluenceMatrix_Raw)[(int)local_f0 * 0x15 + (int)local_16c] /
        ((double)(&g_InfluenceMatrix_Raw)[iVar22] + 1.0) <= 1.0)) || (local_f0 == local_16c)) {
      iVar22 = (int)local_144 * 0x15 + (int)pdStack_f8;
      if ((((&g_AllyTrustScore)[iVar22 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar22 * 2] == 0) &&
          (iVar22 = (int)pdStack_148 + (int)pdStack_f8,
          1.0 < (double)(&g_InfluenceMatrix_Raw)[(int)pdStack_f8 * 0x15 + (int)local_16c] /
                ((double)(&g_InfluenceMatrix_Raw)[iVar22] + 1.0))) && (pdStack_f8 != local_16c)) {
        (&g_AllyTrustScore)[iVar22 * 2] = 0;
        (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)pdStack_f8 * 2] = 1;
        (&DAT_004cf56c)[(int)pdStack_f8 * 2] = 0;
        uStack_170._0_2_ = uStack_152;
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        puVar30 = (ushort *)&uStack_170;
        uStack_170 = CONCAT22(uStack_170._2_2_,uStack_13e);
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)"We are attempting to gang up on (%s): with our good ally (%s)");
        iStack_168 = 0x37;
        pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCVar12 + 0x10;
        iStack_44._0_1_ = 0x2f;
        BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
        iStack_44._0_1_ = 0;
        pCVar13 = pCVar12 + 0xc;
        LOCK();
        iVar22 = *(int *)pCVar13;
        *(int *)pCVar13 = *(int *)pCVar13 + -1;
        UNLOCK();
        if (iVar22 != 1 && -1 < iVar22 + -1) goto LAB_0042af3b;
        (**(code **)(**(int **)pCVar12 + 4))();
        pdVar18 = local_16c;
      }
    }
    else {
      (&g_AllyTrustScore)[iVar22 * 2] = 0;
      (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
      puVar30 = (ushort *)&uStack_170;
      (&DAT_004cf568)[(int)local_f0 * 2] = 1;
      (&DAT_004cf56c)[(int)local_f0 * 2] = 0;
      uStack_170._0_2_ = uStack_152;
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      puVar30 = (ushort *)&uStack_170;
      uStack_170 = CONCAT22(uStack_170._2_2_,uStack_fe);
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,
               (wchar_t *)"We are attempting to gang up on (%s): with our good ally (%s)");
      iStack_168 = 0x37;
      pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      pCStack_164 = pCVar12 + 0x10;
      iStack_44._0_1_ = 0x2e;
      BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
      iStack_44._0_1_ = 0;
      pCVar13 = pCVar12 + 0xc;
      LOCK();
      iVar22 = *(int *)pCVar13;
      *(int *)pCVar13 = *(int *)pCVar13 + -1;
      UNLOCK();
      pdVar14 = pdStack_f8;
      if (iVar22 == 1 || iVar22 + -1 < 0) {
        (**(code **)(**(int **)pCVar12 + 4))();
        pdVar14 = pdStack_f8;
      }
      else {
LAB_0042af3b:
        iStack_44._0_1_ = 0;
        pdVar18 = local_16c;
      }
    }
  }
  pdStack_118 = (double *)((int)pdStack_148 + (int)local_13c);
  if (((-1 < (int)(&g_AllyTrustScore_Hi)[(int)pdStack_118 * 2]) &&
      ((0 < (int)(&g_AllyTrustScore_Hi)[(int)pdStack_118 * 2] ||
       (3 < (uint)(&g_AllyTrustScore)[(int)pdStack_118 * 2])))) &&
     (((&g_AllyTrustScore)[(int)uStack_138 * 2] == 0 &&
       (&g_AllyTrustScore_Hi)[(int)uStack_138 * 2] == 0 &&
      ((int)(&DAT_00633780)[(int)uStack_138] < 3)))) {
    iVar22 = (int)local_13c * 0x15 + (int)pdVar15;
    if ((((&g_AllyTrustScore)[iVar22 * 2] != 0 || (&g_AllyTrustScore_Hi)[iVar22 * 2] != 0) ||
        (iVar22 = (int)pdStack_148 + (int)pdVar15,
        (double)(&g_InfluenceMatrix_Raw)[(int)pdVar15 * 0x15 + (int)pdVar18] /
        ((double)(&g_InfluenceMatrix_Raw)[iVar22] + 1.0) <= 1.0)) || (pdVar15 == pdVar18)) {
      iVar22 = (int)local_13c * 0x15 + (int)pdVar14;
      if ((((&g_AllyTrustScore)[iVar22 * 2] != 0 || (&g_AllyTrustScore_Hi)[iVar22 * 2] != 0) ||
          (iVar22 = (int)pdStack_148 + (int)pdVar14,
          (double)(&g_InfluenceMatrix_Raw)[(int)pdVar14 * 0x15 + (int)pdVar18] /
          ((double)(&g_InfluenceMatrix_Raw)[iVar22] + 1.0) <= 1.0)) || (pdVar15 == pdVar18))
      goto LAB_0042b203;
      (&g_AllyTrustScore)[iVar22 * 2] = 0;
      (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
      puVar30 = (ushort *)&uStack_170;
      (&DAT_004cf568)[(int)pdVar14 * 2] = 1;
      (&DAT_004cf56c)[(int)pdVar14 * 2] = 0;
      uStack_170._0_2_ = uStack_14a;
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      puVar30 = (ushort *)&uStack_170;
      uStack_170 = CONCAT22(uStack_170._2_2_,uStack_13e);
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,
               (wchar_t *)"We are attempting to gang up on (%s): with our good ally (%s)");
      iStack_168 = 0x37;
      pCVar13 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      iStack_44._0_1_ = 0x31;
    }
    else {
      (&g_AllyTrustScore)[iVar22 * 2] = 0;
      (&g_AllyTrustScore_Hi)[iVar22 * 2] = 0;
      puVar30 = (ushort *)&uStack_170;
      (&DAT_004cf568)[(int)pdVar15 * 2] = 1;
      (&DAT_004cf56c)[(int)pdVar15 * 2] = 0;
      uStack_170._0_2_ = uStack_14a;
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      puVar30 = (ushort *)&uStack_170;
      uStack_170 = CONCAT22(uStack_170._2_2_,uStack_fe);
      p_Var9 = _AfxAygshellState();
      GetProvinceToken(p_Var9,puVar30);
      SEND_LOG(&pvStack_174,
               (wchar_t *)"We are attempting to gang up on (%s): with our good ally (%s)");
      iStack_168 = 0x37;
      pCVar13 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
      iStack_44._0_1_ = 0x30;
    }
    pCStack_164 = pCVar13 + 0x10;
    BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
    iStack_44._0_1_ = 0;
    pCVar12 = pCVar13 + 0xc;
    LOCK();
    iVar22 = *(int *)pCVar12;
    *(int *)pCVar12 = *(int *)pCVar12 + -1;
    UNLOCK();
    if (iVar22 == 1 || iVar22 + -1 < 0) {
      (**(code **)(**(int **)pCVar13 + 4))();
    }
  }
LAB_0042b203:
  iVar22 = iStack_124;
  iVar16 = 0;
  if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
    pbVar25 = (byte *)&DAT_00633f20;
    do {
      if ((((&DAT_00633e68)[iVar16] == 1) &&
          ((&DAT_004cf568)[iVar16 * 2] == 0 && (&DAT_004cf56c)[iVar16 * 2] == 0)) &&
         ((0x1e < (int)(&DAT_00634e90)[(int)uStack_138] ||
          (0x1e < (int)(&DAT_00634e90)[(int)pdStack_118])))) {
        iVar8 = *(int *)(pbVar25 + -4);
        if (((*(int *)((int)&DAT_00633f24 + iVar22) == iVar8) ||
            (*(int *)((int)&DAT_00633f28 + iVar22) == iVar8)) &&
           (iVar19 = (int)pdStack_148 + iVar8, (int)(&DAT_00633780)[iVar19] < 3)) {
          (&g_AllyTrustScore)[iVar19 * 2] = 0;
          (&DAT_004cf568)[iVar8 * 2] = 1;
          (&DAT_004cf56c)[iVar8 * 2] = 0;
          (&g_AllyTrustScore_Hi)[iVar19 * 2] = 0;
          puVar30 = (ushort *)&uStack_170;
          uStack_170 = CONCAT22(uStack_170._2_2_,(short)iVar16) & 0xffff00ff | 0x4100;
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          puVar30 = (ushort *)&uStack_170;
          uStack_170 = CONCAT22(uStack_170._2_2_,(ushort)pbVar25[-4]) | 0x4100;
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          SEND_LOG(&pvStack_174,L"We are setting (%s) as enemy: to help our distressed ally (%s)");
          iStack_168 = 0x37;
          pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                              ((CStringData *)((int)pvStack_174 + -0x10));
          pCStack_164 = pCVar12 + 0x10;
          iStack_44._0_1_ = 0x32;
          BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
          iStack_44._0_1_ = 0;
          pCVar13 = pCVar12 + 0xc;
          LOCK();
          iVar8 = *(int *)pCVar13;
          *(int *)pCVar13 = *(int *)pCVar13 + -1;
          UNLOCK();
          if (iVar8 + -1 < 1) {
            (**(code **)(**(int **)pCVar12 + 4))();
          }
          iVar8 = *(int *)(pbVar25 + -4) * 0x15 + (int)local_16c;
          if (((&g_AllyTrustScore)[iVar8 * 2] == 1) && ((&g_AllyTrustScore_Hi)[iVar8 * 2] == 0)) {
            (&g_AllyTrustScore)[iVar8 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar8 * 2] = 0;
          }
        }
        iVar8 = *(int *)pbVar25;
        if (((*(int *)((int)&DAT_00633f24 + iVar22) == iVar8) ||
            (*(int *)((int)&DAT_00633f28 + iVar22) == iVar8)) &&
           (iVar19 = (int)pdStack_148 + iVar8, (int)(&DAT_00633780)[iVar19] < 3)) {
          (&g_AllyTrustScore)[iVar19 * 2] = 0;
          (&DAT_004cf568)[iVar8 * 2] = 1;
          (&DAT_004cf56c)[iVar8 * 2] = 0;
          (&g_AllyTrustScore_Hi)[iVar19 * 2] = 0;
          puVar30 = (ushort *)&uStack_170;
          uStack_170 = CONCAT22(uStack_170._2_2_,(short)iVar16) & 0xffff00ff | 0x4100;
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          puVar30 = (ushort *)&uStack_170;
          uStack_170 = CONCAT22(uStack_170._2_2_,(ushort)*pbVar25) | 0x4100;
          p_Var9 = _AfxAygshellState();
          GetProvinceToken(p_Var9,puVar30);
          SEND_LOG(&pvStack_174,L"We are setting (%s) as enemy: to help our distressed ally (%s)");
          iStack_124 = 0x37;
          pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                              ((CStringData *)((int)pvStack_174 + -0x10));
          pCStack_120 = pCVar12 + 0x10;
          iStack_44._0_1_ = 0x33;
          BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,&iStack_124);
          iStack_44._0_1_ = 0;
          pCVar13 = pCVar12 + 0xc;
          LOCK();
          iVar8 = *(int *)pCVar13;
          *(int *)pCVar13 = *(int *)pCVar13 + -1;
          UNLOCK();
          if (iVar8 == 1 || iVar8 + -1 < 0) {
            (**(code **)(**(int **)pCVar12 + 4))();
          }
          iVar8 = *(int *)pbVar25 * 0x15 + (int)local_16c;
          if (((&g_AllyTrustScore)[iVar8 * 2] == 1) && ((&g_AllyTrustScore_Hi)[iVar8 * 2] == 0)) {
            (&g_AllyTrustScore)[iVar8 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar8 * 2] = 0;
          }
        }
      }
      iVar16 = iVar16 + 1;
      pbVar25 = pbVar25 + 0x14;
    } while (iVar16 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
  }
  pdVar18 = (double *)0x0;
  if (0 < *(int *)(*(int *)(local_150 + 8) + 0x2404)) {
    pdStack_134 = (double *)(&DAT_006340c0 + (int)local_16c * 0x15);
    pdStack_148 = (double *)(&g_AllyRankingAux + (int)local_16c * 0x3f);
    iVar22 = (int)local_16c * 8;
    iVar16 = (int)local_16c * 0xa8;
    do {
      uVar4 = SUB42(pdVar18,0);
      if ((2 < g_DeceitLevel) &&
         (((int)(&target_sc_cnt)[(int)pdVar18] < 3 ||
          ((((0.0 < *(double *)((int)&g_InfluenceMatrix_Alt + iVar16) && (pdVar18 != local_16c)) &&
            (4.5 < *(double *)((int)&g_InfluenceMatrix_Raw + iVar22) /
                   (*(double *)((int)&g_InfluenceMatrix_Raw + iVar16) + 1.0))) &&
           (10.0 < *(double *)((int)&g_InfluenceMatrix_Alt + iVar22))))))) {
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
        (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
        *(undefined4 *)((int)&g_AllyTrustScore + iVar16) = 0;
        *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar16) = 0;
        uStack_170 = CONCAT22(uStack_170._2_2_,uVar4) & 0xffff00ff | 0x4100;
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,(wchar_t *)"We need to eliminate (%s): who is very weak");
        iStack_168 = 0x38;
        pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_164 = pCVar12 + 0x10;
        iStack_44._0_1_ = 0x34;
        BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
        iStack_44._0_1_ = 0;
        pCVar13 = pCVar12 + 0xc;
        LOCK();
        iVar8 = *(int *)pCVar13;
        *(int *)pCVar13 = *(int *)pCVar13 + -1;
        UNLOCK();
        if (iVar8 == 1 || iVar8 + -1 < 0) {
          (**(code **)(**(int **)pCVar12 + 4))();
        }
        if ((*(int *)((int)&g_AllyTrustScore + iVar22) == 1) &&
           (*(int *)((int)&g_AllyTrustScore_Hi + iVar22) == 0)) {
          *(undefined4 *)((int)&g_AllyTrustScore + iVar22) = 0;
          *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar22) = 0;
        }
      }
      if ((((int)(&target_sc_cnt)[(int)local_16c] < 4) && (0 < *(int *)((int)pdStack_148 + -0x54)))
         && ((0 < *(int *)pdStack_148 && (*(int *)((int)pdStack_148 + 0x54) == 0)))) {
        (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
        *(undefined4 *)((int)&g_AllyTrustScore + iVar16) = 0;
        *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar16) = 0;
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
        uStack_170 = CONCAT22(uStack_170._2_2_,uVar4) & 0xffff00ff | 0x4100;
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 (wchar_t *)
                 "We are very small and trying to grab an SC from (%s): who left one vulnerable");
        iStack_124 = 0x38;
        pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_120 = pCVar12 + 0x10;
        iStack_44._0_1_ = 0x35;
        BuildAllianceMsg(&DAT_00bbf638,aiStack_e4,&iStack_124);
        iStack_44._0_1_ = 0;
        pCVar13 = pCVar12 + 0xc;
        LOCK();
        iVar8 = *(int *)pCVar13;
        *(int *)pCVar13 = *(int *)pCVar13 + -1;
        UNLOCK();
        if (iVar8 == 1 || iVar8 + -1 < 0) {
          (**(code **)(**(int **)pCVar12 + 4))();
        }
        if ((*(int *)((int)&g_AllyTrustScore + iVar22) == 1) &&
           (*(int *)((int)&g_AllyTrustScore_Hi + iVar22) == 0)) {
          *(undefined4 *)((int)&g_AllyTrustScore + iVar22) = 0;
          *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar22) = 0;
        }
      }
      if ((((0 < *(int *)((int)pdStack_148 + -0x54)) && (0 < *(int *)pdStack_148)) &&
          (*(int *)((int)pdStack_148 + 0x54) == 0)) && (3 < *(int *)pdStack_134)) {
        (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
        *(undefined4 *)((int)&g_AllyTrustScore + iVar16) = 0;
        *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar16) = 0;
        puVar30 = (ushort *)&uStack_170;
        (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
        uStack_170 = CONCAT22(uStack_170._2_2_,uVar4) & 0xffff00ff | 0x4100;
        p_Var9 = _AfxAygshellState();
        GetProvinceToken(p_Var9,puVar30);
        SEND_LOG(&pvStack_174,
                 L"We are trying to grab an SC from (%s): who left one vulnerable and does not proje ct much fear onto us"
                );
        pdStack_f8 = (double *)0x38;
        pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
        pCStack_f4 = pCVar12 + 0x10;
        iStack_44._0_1_ = 0x36;
        BuildAllianceMsg(&DAT_00bbf638,&pdStack_118,(int *)&pdStack_f8);
        iStack_44._0_1_ = 0;
        pCVar13 = pCVar12 + 0xc;
        LOCK();
        iVar8 = *(int *)pCVar13;
        *(int *)pCVar13 = *(int *)pCVar13 + -1;
        UNLOCK();
        if (iVar8 == 1 || iVar8 + -1 < 0) {
          (**(code **)(**(int **)pCVar12 + 4))();
        }
        if ((*(int *)((int)&g_AllyTrustScore + iVar22) == 1) &&
           (*(int *)((int)&g_AllyTrustScore_Hi + iVar22) == 0)) {
          *(undefined4 *)((int)&g_AllyTrustScore + iVar22) = 0;
          *(undefined4 *)((int)&g_AllyTrustScore_Hi + iVar22) = 0;
        }
      }
      pdStack_148 = (double *)((int)pdStack_148 + 4);
      pdStack_134 = (double *)((int)pdStack_134 + 4);
      pdVar18 = (double *)((int)pdVar18 + 1);
      iVar16 = iVar16 + 8;
      iVar22 = iVar22 + 0xa8;
    } while ((int)pdVar18 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
  }
  iVar22 = local_150;
  pdVar18 = local_16c;
  DAT_00baed6a = 0;
  if ((75.0 < (double)(&DAT_0062e360)[(int)local_16c]) &&
     (2.0 <= (double)(&DAT_0062e360)[(int)local_16c] - (double)(&DAT_0062e360)[(int)local_128])) {
    SEND_LOG(&pvStack_174,
             (wchar_t *)"We are ahead of everyone and will make everyone our enemy- ha ha ha ha");
    iStack_168 = 0x39;
    pCVar12 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_174 + -0x10));
    pCStack_164 = pCVar12 + 0x10;
    iStack_44._0_1_ = 0x37;
    BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
    iStack_44._0_1_ = 0;
    pCVar13 = pCVar12 + 0xc;
    LOCK();
    iVar16 = *(int *)pCVar13;
    *(int *)pCVar13 = *(int *)pCVar13 + -1;
    UNLOCK();
    if (iVar16 == 1 || iVar16 + -1 < 0) {
      (**(code **)(**(int **)pCVar12 + 4))();
    }
    DAT_00baed6a = 1;
    pdVar14 = (double *)0x0;
    if (0 < *(int *)(*(int *)(iVar22 + 8) + 0x2404)) {
      puVar10 = &g_AllyTrustScore + (int)pdVar18 * 0x2a;
      piVar7 = &g_AllyTrustScore + (int)pdVar18 * 2;
      do {
        if (pdVar14 != pdVar18) {
          *puVar10 = 0;
          puVar10[1] = 0;
          iVar16 = *piVar7;
          (&DAT_004cf568)[(int)pdVar14 * 2] = 1;
          (&DAT_004cf56c)[(int)pdVar14 * 2] = 0;
          if ((iVar16 == 1) && (piVar7[1] == 0)) {
            *piVar7 = 0;
            piVar7[1] = 0;
          }
        }
        pdVar14 = (double *)((int)pdVar14 + 1);
        puVar10 = puVar10 + 2;
        piVar7 = piVar7 + 0x2a;
        pdVar18 = local_16c;
      } while ((int)pdVar14 < *(int *)(*(int *)(iVar22 + 8) + 0x2404));
    }
  }
  iVar22 = *(int *)(*(int *)(iVar22 + 8) + 0x2404);
  if (0 < iVar22) {
    piVar7 = &g_AllyMatrix;
    iVar16 = iVar22;
    do {
      iVar8 = 0;
      piVar20 = piVar7;
      do {
        iVar19 = *piVar20;
        iVar8 = iVar8 + 1;
        piVar20 = piVar20 + 1;
        auStack_dc[iVar8] = (uint)(iVar19 == 1);
      } while (iVar8 < iVar22);
      piVar7 = piVar7 + 0x15;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  pdStack_148 = (double *)0x0;
  if (0 < iVar22) {
    pdStack_f8 = (double *)0x0;
    pdStack_134 = (double *)&DAT_004cf568;
    do {
      pdVar18 = (double *)0x0;
      if (0 < iVar22) {
        puVar10 = &g_AllyTrustScore + (int)local_16c * 0x2a;
        piVar7 = &g_AllyTrustScore + (int)local_16c * 2;
        do {
          if ((((*(int *)pdStack_134 == 0 && *(int *)((int)pdStack_134 + 4) == 0) &&
               ((&DAT_004cf568)[(int)pdVar18 * 2] == 0 && (&DAT_004cf56c)[(int)pdVar18 * 2] == 0))
              && (auStack_dc[(int)pdStack_148 + 1] == 0)) &&
             (((iVar22 = (int)pdStack_f8 + (int)pdVar18, (&g_AllyMatrix)[iVar22] == 1 &&
               (DAT_004c6bc4 != pdVar18)) &&
              (((int)(&g_AllyTrustScore_Hi)[iVar22 * 2] < 1 &&
               (((int)(&g_AllyTrustScore_Hi)[iVar22 * 2] < 0 ||
                ((uint)(&g_AllyTrustScore)[iVar22 * 2] < 2)))))))) {
            puVar30 = (ushort *)&uStack_170;
            (&DAT_004cf568)[(int)pdVar18 * 2] = 1;
            (&DAT_004cf56c)[(int)pdVar18 * 2] = 0;
            uStack_170 = CONCAT22(uStack_170._2_2_,(short)pdVar18) & 0xffff00ff | 0x4100;
            p_Var9 = _AfxAygshellState();
            GetProvinceToken(p_Var9,puVar30);
            SEND_LOG(&pvStack_174,
                     (wchar_t *)"We have set (%s) as enemy because of an alliance agreement");
            iStack_168 = 0x39;
            pCVar12 = ATL::CSimpleStringT<char,0>::CloneData
                                ((CStringData *)((int)pvStack_174 + -0x10));
            pCStack_164 = pCVar12 + 0x10;
            iStack_44._0_1_ = 0x38;
            BuildAllianceMsg(&DAT_00bbf638,auStack_10c,&iStack_168);
            iStack_44._0_1_ = 0;
            pCVar13 = pCVar12 + 0xc;
            LOCK();
            iVar22 = *(int *)pCVar13;
            *(int *)pCVar13 = *(int *)pCVar13 + -1;
            UNLOCK();
            if (iVar22 == 1 || iVar22 + -1 < 0) {
              (**(code **)(**(int **)pCVar12 + 4))();
            }
            *puVar10 = 0;
            puVar10[1] = 0;
            if ((*piVar7 == 1) && (piVar7[1] == 0)) {
              *piVar7 = 0;
              piVar7[1] = 0;
            }
          }
          pdVar18 = (double *)((int)pdVar18 + 1);
          puVar10 = puVar10 + 2;
          piVar7 = piVar7 + 0x2a;
        } while ((int)pdVar18 < *(int *)(*(int *)(local_150 + 8) + 0x2404));
      }
      iVar22 = *(int *)(*(int *)(local_150 + 8) + 0x2404);
      pdStack_134 = pdStack_134 + 1;
      pdStack_f8 = (double *)((int)pdStack_f8 + 0x15);
      pdStack_148 = (double *)((int)pdStack_148 + 1);
    } while ((int)pdStack_148 < iVar22);
  }
LAB_0042bff2:
  piVar7 = (int *)((int)pvStack_174 + -4);
  iStack_44 = 0xffffffff;
  LOCK();
  iVar22 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar22 == 1 || iVar22 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_174 + -0x10) + 4))();
  }
  ExceptionList = local_4c;
  return;
}

