
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall EvaluateOrderProposal(void *this,int **param_1)

{
  undefined1 *puVar1;
  undefined *this_00;
  char cVar2;
  ushort uVar3;
  int *piVar4;
  uint **ppuVar5;
  void **ppvVar6;
  uint uVar7;
  int ***pppiVar8;
  int **ppiVar9;
  int iVar10;
  int **ppiVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  int **ppiVar16;
  int **ppiVar17;
  bool bVar18;
  ulonglong uVar19;
  undefined4 *puVar20;
  int local_d40;
  int **local_d3c;
  int **local_d38;
  char local_d31;
  int **local_d30;
  int **local_d2c;
  int **local_d28;
  int local_d24;
  int *local_d20 [2];
  int **local_d18;
  int **local_d14;
  int local_d0c;
  int local_d08;
  int local_d04;
  undefined4 local_d00;
  undefined4 local_cfc;
  undefined4 local_cf8;
  undefined4 local_cf4;
  undefined4 local_cf0;
  undefined1 local_cec [4];
  int *local_ce8;
  undefined4 local_ce4;
  uint local_ce0;
  int **local_cdc;
  int **local_cd4;
  int local_cd0;
  int *local_ccc;
  int local_cc8;
  int local_cc4;
  int **local_cc0;
  uint *local_cbc;
  int **local_cb8;
  void *local_cac [4];
  void *local_c9c [4];
  int local_c8c;
  undefined4 local_c88;
  undefined4 local_c84;
  undefined2 local_c80;
  undefined4 local_c7c;
  undefined4 local_c78;
  undefined1 local_c74 [4];
  int *local_c70;
  undefined4 local_c6c;
  uint *local_c68 [4];
  void *local_c58 [4];
  int **local_c48;
  undefined4 local_c44;
  undefined4 local_c40;
  undefined4 local_c3c;
  undefined4 local_c38;
  undefined4 local_c34;
  undefined4 local_c30;
  undefined4 local_c2c;
  int local_c28;
  undefined4 local_c24;
  undefined4 local_c20;
  int local_c1c;
  undefined4 local_c18;
  undefined1 local_c14;
  undefined1 local_c13;
  int local_c10;
  undefined4 local_c0c;
  undefined4 auStack_c08 [30];
  undefined4 auStack_b90 [30];
  undefined4 auStack_b18 [30];
  undefined4 local_aa0;
  int aiStack_a9c [21];
  undefined4 auStack_a48 [256];
  undefined1 local_648 [4];
  int **local_644;
  undefined4 local_640;
  void *local_638 [4];
  undefined1 local_628 [1556];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497b4e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_644 = (int **)FUN_00410050();
  *(undefined1 *)((int)local_644 + 0x31) = 1;
  local_644[1] = (int *)local_644;
  *local_644 = (int *)local_644;
  iVar15 = 0;
  local_644[2] = (int *)local_644;
  local_640 = 0;
  local_c = 0;
  local_cf8 = (uint)local_cf8._2_2_ << 0x10;
  local_ce8 = (int *)FUN_004018e0();
  local_ce4 = 0;
  local_c._0_1_ = 1;
  FUN_00465870(local_cac);
  local_c._0_1_ = 2;
  FUN_00465870(local_c9c);
  local_d30 = (int **)(uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_c = CONCAT31(local_c._1_3_,3);
  local_d24 = 0;
  local_d31 = '\0';
  local_d04 = 0;
  local_c1c = 0;
  puVar20 = (undefined4 *)0x44e159;
  ResetPerTrialState(*(int *)((int)this + 8));
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2400)) {
    piVar14 = &g_OrderTable;
    do {
      iVar12 = *piVar14;
      if (iVar12 != 0) {
        if (iVar12 == 1) {
          puVar20 = (undefined4 *)piVar14[2];
          BuildOrder_RTO(*(undefined4 *)((int)this + 8));
        }
        else if (iVar12 == 2) {
          local_cd4 = (int **)&stack0xfffff2a4;
          puVar20 = (undefined4 *)CONCAT22((short)((uint)puVar20 >> 0x10),(short)piVar14[3]);
          BuildOrder_CTO_Ring(*(void **)((int)this + 8),iVar15,piVar14[2],puVar20);
        }
        else if (iVar12 == 3) {
          puVar20 = (undefined4 *)piVar14[2];
          FUN_00460770(*(void **)((int)this + 8),iVar15,puVar20);
        }
        else if (iVar12 == 4) {
          puVar20 = (undefined4 *)piVar14[2];
          FUN_004607f0(*(void **)((int)this + 8),iVar15,piVar14[1],puVar20);
        }
        else if (iVar12 == 5) {
          puVar20 = (undefined4 *)piVar14[2];
          BuildOrder_CVY(*(void **)((int)this + 8),iVar15,piVar14[1],puVar20);
        }
        else if (iVar12 == 6) {
          if (-1 < piVar14[0x1a]) {
            *(int *)((int)this + 0x2a10) = piVar14[0x1a];
          }
          if (-1 < piVar14[0x1b]) {
            *(int *)((int)this + 0x2a14) = piVar14[0x1b];
          }
          if (-1 < piVar14[0x1c]) {
            *(int *)((int)this + 0x2a18) = piVar14[0x1c];
          }
          puVar20 = (undefined4 *)((int)this + 0x2a10);
          BuildOrder_CTO(*(void **)((int)this + 8),iVar15,piVar14[2],piVar14[0x17],puVar20);
        }
        else {
          puVar20 = (undefined4 *)0x0;
          AfxMessageBox("Unrecognized Order",0,0);
        }
      }
      iVar15 = iVar15 + 1;
      piVar14 = piVar14 + 0x1e;
    } while (iVar15 < *(int *)(*(int *)((int)this + 8) + 0x2400));
  }
  ppuVar5 = FUN_00466f80(&SUB,&local_cbc,(void **)&DAT_00bc1e0c);
  local_c._0_1_ = 4;
  AppendList(local_cac,ppuVar5);
  local_c = CONCAT31(local_c._1_3_,3);
  FreeList(&local_cbc);
  local_d3c = (int **)**(undefined4 **)(*(int *)((int)this + 8) + 0x2454);
  local_d40 = *(int *)((int)this + 8) + 0x2450;
  while( true ) {
    ppiVar11 = local_d3c;
    iVar15 = local_d40;
    ppiVar9 = *(int ***)(*(int *)((int)this + 8) + 0x2454);
    if ((local_d40 == 0) || (local_d40 != *(int *)((int)this + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (ppiVar11 == ppiVar9) break;
    if (iVar15 == 0) {
      FUN_0047a948();
    }
    if (ppiVar11 == *(int ***)(iVar15 + 4)) {
      FUN_0047a948();
    }
    if ((int **)ppiVar11[6] == param_1) {
      if (ppiVar11 == *(int ***)(iVar15 + 4)) {
        FUN_0047a948();
      }
      if (ppiVar11[8] != (int *)0x0) {
        if (ppiVar11 == *(int ***)(iVar15 + 4)) {
          FUN_0047a948();
        }
        ppvVar6 = (void **)FUN_00463690(*(void **)((int)this + 8),local_c58,(int *)(ppiVar11 + 4));
        local_c._0_1_ = 5;
        AppendList(local_c9c,ppvVar6);
        local_c = CONCAT31(local_c._1_3_,3);
        FreeList(local_c58);
        if (param_1 == local_d30) {
          ppiVar9 = (int **)(&DAT_00bb66f8 + (int)param_1 * 0xc);
          local_d38 = (int **)(&DAT_00bb66fc)[(int)param_1 * 3];
          cVar2 = *(char *)((int)local_d38[1] + 0x1d);
          local_cdc = local_d38;
          ppiVar17 = (int **)local_d38[1];
          while (cVar2 == '\0') {
            uVar7 = FUN_00465cf0(ppiVar17 + 3,(int *)local_c9c);
            if ((char)uVar7 == '\0') {
              ppiVar16 = (int **)*ppiVar17;
              local_d38 = ppiVar17;
            }
            else {
              ppiVar16 = (int **)ppiVar17[2];
            }
            ppiVar17 = ppiVar16;
            cVar2 = *(char *)((int)ppiVar16 + 0x1d);
          }
          local_d14 = local_d38;
          local_d18 = ppiVar9;
          if ((local_d38 == (int **)(&DAT_00bb66fc)[(int)param_1 * 3]) ||
             (uVar7 = FUN_00465cf0(local_c9c,(int *)(local_d38 + 3)), (char)uVar7 != '\0')) {
            local_d28 = (int **)(&DAT_00bb66fc)[(int)param_1 * 3];
            local_d2c = ppiVar9;
            pppiVar8 = &local_d2c;
          }
          else {
            pppiVar8 = &local_d18;
          }
          ppiVar17 = pppiVar8[1];
          if ((*pppiVar8 == (int **)0x0) || (*pppiVar8 != ppiVar9)) {
            FUN_0047a948();
          }
          if (ppiVar17 != local_cdc) {
            local_d31 = '\x01';
          }
        }
        ppuVar5 = FUN_00466c40(local_cac,local_c68,local_c9c);
        local_c._0_1_ = 6;
        AppendList(local_cac,ppuVar5);
        local_c = CONCAT31(local_c._1_3_,3);
        FreeList(local_c68);
        local_d08 = DAT_00bb6e04;
        if (ppiVar11 == *(int ***)(local_d40 + 4)) {
          FUN_0047a948();
        }
        puVar20 = (undefined4 *)
                  GameBoard_GetPowerRec(&DAT_00bb6e00,(int *)&local_cbc,(int *)(ppiVar11 + 4));
        if (((undefined *)*puVar20 == (undefined *)0x0) || ((undefined *)*puVar20 != &DAT_00bb6e00))
        {
          FUN_0047a948();
        }
        if (puVar20[1] != local_d08) {
          if (ppiVar11 == *(int ***)(local_d40 + 4)) {
            FUN_0047a948();
          }
          if (ppiVar11[8] != (int *)0x2) {
            if (ppiVar11 == *(int ***)(local_d40 + 4)) {
              FUN_0047a948();
            }
            if (ppiVar11[8] != (int *)0x6) {
              local_d04 = 500;
            }
          }
        }
        if (param_1 == local_d30) {
          this_00 = &DAT_00bb69f8 + (int)param_1 * 0xc;
          local_cc8 = (&DAT_00bb69fc)[(int)param_1 * 3];
          if (ppiVar11 == *(int ***)(local_d40 + 4)) {
            FUN_0047a948();
          }
          puVar20 = (undefined4 *)FUN_00402140(this_00,&local_cc4,(int *)(ppiVar11 + 4));
          if (((undefined *)*puVar20 == (undefined *)0x0) || ((undefined *)*puVar20 != this_00)) {
            FUN_0047a948();
          }
          if (puVar20[1] != local_cc8) {
            if (ppiVar11 == *(int ***)(local_d40 + 4)) {
              FUN_0047a948();
            }
            piVar14 = (int *)FUN_00402140(this_00,(int *)local_d20,(int *)(ppiVar11 + 4));
            iVar12 = local_d40;
            local_cd0 = piVar14[1];
            iVar15 = *piVar14;
            if (ppiVar11 == *(int ***)(local_d40 + 4)) {
              FUN_0047a948();
            }
            if (ppiVar11[8] == (int *)0x2) {
LAB_0044e58b:
              if (ppiVar11 == *(int ***)(iVar12 + 4)) {
                FUN_0047a948();
              }
              if (iVar15 == 0) {
                FUN_0047a948();
              }
              if (local_cd0 == *(int *)(iVar15 + 4)) {
                FUN_0047a948();
              }
              if (ppiVar11[9] == *(int **)(local_cd0 + 0x10)) goto LAB_0044e5c6;
            }
            else {
              if (ppiVar11 == *(int ***)(iVar12 + 4)) {
                FUN_0047a948();
              }
              if (ppiVar11[8] == (int *)0x6) goto LAB_0044e58b;
            }
            local_d04 = 0x2ee;
          }
        }
      }
    }
LAB_0044e5c6:
    UnitList_Advance(&local_d40);
  }
  cVar2 = *(char *)((int)DAT_00bbf60c[1] + 0x629);
  ppiVar9 = (int **)DAT_00bbf60c[1];
  local_cdc = DAT_00bbf60c;
  ppiVar11 = DAT_00bbf60c;
  while (ppiVar17 = ppiVar9, cVar2 == '\0') {
    uVar7 = FUN_00465cf0(ppiVar17 + 3,(int *)local_cac);
    if ((char)uVar7 == '\0') {
      ppiVar9 = (int **)*ppiVar17;
    }
    else {
      ppiVar9 = (int **)ppiVar17[2];
      ppiVar17 = ppiVar11;
    }
    cVar2 = *(char *)((int)ppiVar9 + 0x629);
    ppiVar11 = ppiVar17;
  }
  local_d14 = ppiVar11;
  local_d18 = (int **)&g_CandidateRecordList;
  if ((ppiVar11 == DAT_00bbf60c) ||
     (uVar7 = FUN_00465cf0(local_cac,(int *)(ppiVar11 + 3)), (char)uVar7 != '\0')) {
    local_d28 = DAT_00bbf60c;
    local_d2c = (int **)&g_CandidateRecordList;
    pppiVar8 = &local_d2c;
  }
  else {
    pppiVar8 = &local_d18;
  }
  ppiVar9 = pppiVar8[1];
  if ((*pppiVar8 == (int **)0x0) || (*pppiVar8 != (int **)&g_CandidateRecordList)) {
    FUN_0047a948();
  }
  if ((ppiVar9 == local_cdc) && (local_d31 != '\x01')) {
    local_d3c = (int **)**(int **)(*(int *)((int)this + 8) + 0x2454);
    local_d40 = *(int *)((int)this + 8) + 0x2450;
    while( true ) {
      ppiVar9 = local_d3c;
      iVar12 = local_d40;
      iVar15 = *(int *)(*(int *)((int)this + 8) + 0x2454);
      if ((local_d40 == 0) || (local_d40 != *(int *)((int)this + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (ppiVar9 == (int **)iVar15) break;
      if (iVar12 == 0) {
        FUN_0047a948();
      }
      if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
        FUN_0047a948();
      }
      if (*(int ***)((int)ppiVar9 + 0x18) == param_1) {
        if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)((int)ppiVar9 + 0x20) != 0) {
          if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
            FUN_0047a948();
          }
          local_d00 = *(undefined4 *)((int)ppiVar9 + 0x20);
          if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
            FUN_0047a948();
          }
          local_cfc = *(undefined4 *)((int)ppiVar9 + 0x24);
          local_cf8 = *(int *)((int)ppiVar9 + 0x28);
          if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
            FUN_0047a948();
          }
          local_cf0 = *(undefined4 *)((int)ppiVar9 + 0x30);
          if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
            FUN_0047a948();
          }
          local_cf4 = *(undefined4 *)((int)ppiVar9 + 0x2c);
          piVar14 = (int *)*local_ce8;
          *local_ce8 = (int)local_ce8;
          local_ce8[1] = (int)local_ce8;
          local_ce4 = 0;
          if (piVar14 != local_ce8) {
            do {
              piVar4 = (int *)*piVar14;
              _free(piVar14);
              piVar14 = piVar4;
            } while (piVar4 != local_ce8);
          }
          if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
            FUN_0047a948();
          }
          puVar1 = (undefined1 *)((int)ppiVar9 + 0x34);
          if (local_cec != puVar1) {
            FUN_004226e0(local_cec,(int)puVar1,(undefined4 *)**(undefined4 **)((int)ppiVar9 + 0x38),
                         (int)puVar1,*(undefined4 **)((int)ppiVar9 + 0x38));
          }
          if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
            FUN_0047a948();
          }
          local_c8c = *(int *)((int)ppiVar9 + 0xc);
          local_c88 = local_d00;
          local_c80 = (undefined2)local_cf8;
          local_c84 = local_cfc;
          local_c7c = local_cf4;
          local_c78 = local_cf0;
          FUN_00405d20(local_c74,(int)local_cec);
          local_c._0_1_ = 7;
          FUN_00433a20(local_648,&local_cbc,&local_c8c);
          piVar14 = (int *)*local_c70;
          *local_c70 = (int)local_c70;
          local_c70[1] = (int)local_c70;
          local_c = CONCAT31(local_c._1_3_,3);
          local_c6c = 0;
          if (piVar14 != local_c70) {
            do {
              piVar4 = (int *)*piVar14;
              _free(piVar14);
              piVar14 = piVar4;
            } while (piVar4 != local_c70);
          }
          _free(local_c70);
        }
      }
      if (DAT_00baed68 == '\x01') {
        if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
          FUN_0047a948();
        }
        if (*(int ***)((int)ppiVar9 + 0x18) != param_1) goto LAB_0044e99f;
        if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)((int)ppiVar9 + 0x20) != 2) goto LAB_0044e99f;
        if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(*(int *)((int)this + 8) + 3 + *(int *)((int)ppiVar9 + 0x24) * 0x24) != '\x01')
        goto LAB_0044e99f;
        if (ppiVar9 == (int **)*(int *)(iVar12 + 4)) {
          FUN_0047a948();
        }
        uVar3 = *(ushort *)(*(int *)((int)this + 8) + 0x20 + *(int *)((int)ppiVar9 + 0x24) * 0x24);
        ppiVar9 = (int **)(uVar3 & 0xff);
        if ((char)(uVar3 >> 8) != 'A') {
          ppiVar9 = (int **)0x14;
        }
        if ((ppiVar9 == param_1) || (ppiVar9 == (int **)0x14)) goto LAB_0044e99f;
        iVar15 = (int)param_1 * 0x15 + (int)ppiVar9;
        if (((int)(&g_AllyTrustScore_Hi)[iVar15 * 2] < 1) &&
           (((int)(&g_AllyTrustScore_Hi)[iVar15 * 2] < 0 ||
            ((uint)(&g_AllyTrustScore)[iVar15 * 2] < 2)))) {
          local_d24 = 0x32;
          UnitList_Advance(&local_d40);
        }
        else {
          iVar15 = (int)ppiVar9 * 0x15 + (int)param_1;
          if ((0 < (int)(&g_AllyTrustScore_Hi)[iVar15 * 2]) ||
             ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar15 * 2] &&
              (1 < (uint)(&g_AllyTrustScore)[iVar15 * 2])))) {
            local_d24 = 0x96;
            goto LAB_0044e99f;
          }
          local_d24 = 0x6e;
          UnitList_Advance(&local_d40);
        }
      }
      else {
LAB_0044e99f:
        UnitList_Advance(&local_d40);
      }
    }
    local_d40 = *(int *)((int)this + 8);
    iVar15 = 0;
    if (0 < *(int *)(local_d40 + 0x2404)) {
      do {
        aiStack_a9c[iVar15] = 0;
        iVar15 = iVar15 + 1;
      } while (iVar15 < *(int *)(local_d40 + 0x2404));
    }
    local_d3c = (int **)**(undefined4 **)(local_d40 + 0x2454);
    local_d40 = local_d40 + 0x2450;
    while( true ) {
      ppiVar9 = local_d3c;
      iVar15 = local_d40;
      local_cc0 = *(int ***)(*(int *)((int)this + 8) + 0x2454);
      if ((local_d40 == 0) || (local_d40 != *(int *)((int)this + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (ppiVar9 == local_cc0) break;
      if (iVar15 == 0) {
        FUN_0047a948();
      }
      if (ppiVar9 == *(int ***)(iVar15 + 4)) {
        FUN_0047a948();
      }
      if ((int **)ppiVar9[6] != param_1) goto LAB_0044f15e;
      if (ppiVar9 == *(int ***)(iVar15 + 4)) {
        FUN_0047a948();
      }
      if (ppiVar9[8] == (int *)0x2) {
LAB_0044ecee:
        if (ppiVar9 == *(int ***)(iVar15 + 4)) {
          FUN_0047a948();
        }
        local_d20[0] = ppiVar9[9];
        if (ppiVar9 == *(int ***)(iVar15 + 4)) {
          FUN_0047a948();
        }
        local_ccc = ppiVar9[4];
        local_d0c = (int)local_ccc * 8;
        local_d14 = (int **)((int)param_1 >> 0x1f);
        local_d18 = param_1;
        if (((((int **)(&DAT_004d2610)[(int)local_ccc * 2] != param_1) ||
             ((int **)(&DAT_004d2614)[(int)local_ccc * 2] != local_d14)) || (DAT_00baed69 != '\x01')
            ) || (_g_NearEndGameFactor <= 5.0)) {
LAB_0044edc1:
          if ((6.0 < _g_NearEndGameFactor) && (DAT_00baed69 == '\x01')) {
            piVar14 = local_ccc + (int)param_1 * 0x40;
            iVar15 = (&DAT_005460ec)[(int)piVar14 * 2];
            iVar12 = (&DAT_0058f8ec)[(int)piVar14 * 2];
            uVar7 = (&DAT_0058f8e8)[(int)piVar14 * 2];
            if ((iVar12 <= iVar15) &&
               ((iVar12 < iVar15 || (uVar7 < (uint)(&DAT_005460e8)[(int)piVar14 * 2])))) {
              iVar12 = (&DAT_005658ec)[(int)piVar14 * 2] + iVar12 +
                       (uint)CARRY4((&DAT_005658e8)[(int)piVar14 * 2],uVar7);
              if ((iVar15 <= iVar12) &&
                 ((iVar15 < iVar12 ||
                  ((uint)(&DAT_005460e8)[(int)piVar14 * 2] <=
                   (&DAT_005658e8)[(int)piVar14 * 2] + uVar7)))) goto LAB_0044ee24;
            }
          }
        }
        else {
          piVar14 = local_ccc + (int)param_1 * 0x40;
          local_ce0 = (&DAT_005460e8)[(int)piVar14 * 2];
          iVar15 = (&DAT_0058f8ec)[(int)piVar14 * 2];
          uVar7 = (&DAT_0058f8e8)[(int)piVar14 * 2];
          iVar12 = (&DAT_005460ec)[(int)piVar14 * 2];
          if ((iVar12 < iVar15) || ((iVar12 <= iVar15 && (local_ce0 <= uVar7)))) goto LAB_0044edc1;
          iVar15 = (&DAT_005658ec)[(int)piVar14 * 2] + iVar15 +
                   (uint)CARRY4((&DAT_005658e8)[(int)piVar14 * 2],uVar7);
          if ((iVar15 < iVar12) ||
             ((iVar15 <= iVar12 && ((&DAT_005658e8)[(int)piVar14 * 2] + uVar7 < local_ce0))))
          goto LAB_0044edc1;
LAB_0044ee24:
          local_c1c = local_c1c + 0x32;
        }
        local_d38 = (int **)0x0;
        if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
          local_d30 = (int **)((int)local_d20[0] * 8);
LAB_0044ee60:
          ppiVar9 = local_d3c;
          if ((((int)local_d30[0x163e3b] < 1) &&
              ((((int)local_d30[0x163e3b] < 0 || (local_d30[0x163e3a] == (int *)0x0)) &&
               (*(int *)((int)&DAT_0058f8ec + local_d0c) < 1)))) &&
             ((*(int *)((int)&DAT_0058f8ec + local_d0c) < 0 ||
              (*(int *)((int)&DAT_0058f8e8 + local_d0c) == 0)))) {
            if (((((int)local_d30[0x173c3b] < 1) &&
                 ((((int)local_d30[0x173c3b] < 0 || (local_d30[0x173c3a] == (int *)0x0)) &&
                  (((int)local_d30[0x17123b] < 1 &&
                   ((((int)local_d30[0x17123b] < 0 || (local_d30[0x17123a] == (int *)0x0)) &&
                    (*(int *)((int)&DAT_005c48ec + local_d0c) < 1)))))))) &&
                (((*(int *)((int)&DAT_005c48ec + local_d0c) < 0 ||
                  (*(int *)((int)&DAT_005c48e8 + local_d0c) == 0)) &&
                 (*(int *)((int)&DAT_005ba0ec + local_d0c) < 1)))) &&
               (((*(int *)((int)&DAT_005ba0ec + local_d0c) < 0 ||
                 (*(int *)((int)&DAT_005ba0e8 + local_d0c) == 0)) &&
                (((int)local_d30[0x16e83b] < 1 &&
                 (((int)local_d30[0x16e83b] < 0 || (local_d30[0x16e83a] == (int *)0x0)))))))) {
              ppiVar9 = (int **)(&DAT_004d2e14)[(int)local_d20[0] * 2];
              if (((-1 < (int)ppiVar9) &&
                  (((int **)(&g_AllyDesignation_A)[(int)local_d20[0] * 2] != local_d38 ||
                   (ppiVar9 != (int **)((int)local_d38 >> 0x1f))))) &&
                 (((int **)(&g_AllyDesignation_A)[(int)local_d20[0] * 2] != local_d18 ||
                  (ppiVar9 != local_d14)))) {
                ppiVar9 = UnitList_FindOrInsert
                                    ((void *)(*(int *)((int)this + 8) + 0x2450),(int *)local_d20);
                local_d2c = AdjacencyList_FilterByUnitType
                                      ((void *)(*(int *)((int)this + 8) + 8 + (int)*ppiVar9 * 0x24),
                                       (ushort *)(ppiVar9 + 1));
                ppiVar11 = local_d38;
                local_d28 = (int **)*local_d2c[1];
                local_cd4 = local_d2c;
                do {
                  ppiVar17 = local_d28;
                  ppiVar9 = local_d2c;
                  local_cb8 = (int **)local_cd4[1];
                  if ((local_d2c == (int **)0x0) || (local_d2c != local_cd4)) {
                    FUN_0047a948();
                  }
                  if (ppiVar17 == local_cb8) break;
                  if (ppiVar9 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (ppiVar17 == (int **)ppiVar9[1]) {
                    FUN_0047a948();
                  }
                  if ((-1 < (int)(&DAT_0058f8ec)[(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2]) &&
                     ((0 < (int)(&DAT_0058f8ec)[(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2] ||
                      (1 < (uint)(&DAT_0058f8e8)[(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2]))))
                  {
                    if ((ppiVar17 == (int **)ppiVar9[1]) &&
                       (FUN_0047a948(), ppiVar17 == (int **)ppiVar9[1])) {
                      FUN_0047a948();
                    }
                    ppiVar9 = local_d3c;
                    uVar7 = (uint)((uint)(&DAT_0052b4e8)
                                         [(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2] <
                                  (uint)(&DAT_0058f8e8)
                                        [(int)(ppiVar17[3] + (int)param_1 * 0x40) * 2]);
                    bVar18 = -1 < (int)(((&DAT_0052b4ec)
                                         [(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2] -
                                        (&DAT_0058f8ec)
                                        [(int)(ppiVar17[3] + (int)param_1 * 0x40) * 2]) - uVar7);
                    if (((&DAT_0052b4ec)[(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2] -
                         (&DAT_0058f8ec)[(int)(ppiVar17[3] + (int)param_1 * 0x40) * 2] != uVar7 &&
                         bVar18) ||
                       ((bVar18 &&
                        (1 < (uint)((&DAT_0052b4e8)[(int)(ppiVar17[3] + (int)ppiVar11 * 0x40) * 2] -
                                   (&DAT_0058f8e8)[(int)(ppiVar17[3] + (int)param_1 * 0x40) * 2]))))
                       ) goto LAB_0044f07a;
                  }
                  FUN_0040f400((int *)&local_d2c);
                } while( true );
              }
              goto LAB_0044f133;
            }
            if (local_d3c == *(int ***)(local_d40 + 4)) {
              FUN_0047a948();
            }
            goto LAB_0044f093;
          }
          if (local_d3c == *(int ***)(local_d40 + 4)) {
            FUN_0047a948();
          }
          ppiVar9 = OrderedSet_FindOrInsert
                              ((void *)((int)this + (int)param_1 * 0xc + 0x4000),ppiVar9 + 9);
          aiStack_a9c[(int)local_d38] =
               (int)*ppiVar9 +
               aiStack_a9c[(int)local_d38] + (int)local_d20[0] + (int)(local_ccc + 0xfa);
          goto LAB_0044f133;
        }
LAB_0044f15e:
        UnitList_Advance(&local_d40);
      }
      else {
        if (ppiVar9 == *(int ***)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if (ppiVar9[8] == (int *)0x6) goto LAB_0044ecee;
        if (ppiVar9 == *(int ***)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if (ppiVar9[8] == (int *)0x4) {
          if (ppiVar9 == *(int ***)(iVar15 + 4)) {
            FUN_0047a948();
          }
          piVar14 = ppiVar9[0xc];
          if (ppiVar9 == *(int ***)(iVar15 + 4)) {
            FUN_0047a948();
          }
          piVar4 = ppiVar9[4];
          iVar15 = 0;
          if (*(int *)(*(int *)((int)this + 8) + 0x2404) < 1) goto LAB_0044f15e;
          local_d30 = *(int ***)((int)this + 8);
          iVar12 = (int)piVar4 * 8;
          iVar10 = (int)piVar14 * 8;
          do {
            if (((((-1 < *(int *)((int)&DAT_0058f8ec + iVar12)) &&
                  ((0 < *(int *)((int)&DAT_0058f8ec + iVar12) ||
                   (*(int *)((int)&DAT_0058f8e8 + iVar12) != 0)))) ||
                 (0 < *(int *)((int)&DAT_005cf0ec + iVar10))) ||
                ((((-1 < *(int *)((int)&DAT_005cf0ec + iVar10) &&
                   (*(int *)((int)&DAT_005cf0e8 + iVar10) != 0)) ||
                  (0 < *(int *)((int)&DAT_005c48ec + iVar10))) ||
                 (((-1 < *(int *)((int)&DAT_005c48ec + iVar10) &&
                   (*(int *)((int)&DAT_005c48e8 + iVar10) != 0)) ||
                  ((0 < *(int *)((int)&DAT_005ba0ec + iVar10) ||
                   ((-1 < *(int *)((int)&DAT_005ba0ec + iVar10) &&
                    (*(int *)((int)&DAT_005ba0e8 + iVar10) != 0)))))))))) ||
               ((-1 < *(int *)((int)&DAT_005ba0ec + iVar12) &&
                ((0 < *(int *)((int)&DAT_005ba0ec + iVar12) ||
                 (*(int *)((int)&DAT_005ba0e8 + iVar12) != 0)))))) {
              aiStack_a9c[iVar15] = aiStack_a9c[iVar15] + (int)(piVar4 + 500) + (int)piVar14;
            }
            iVar15 = iVar15 + 1;
            iVar10 = iVar10 + 0x800;
            iVar12 = iVar12 + 0x800;
          } while (iVar15 < (int)local_d30[0x901]);
          UnitList_Advance(&local_d40);
        }
        else {
          if (ppiVar9 == *(int ***)(iVar15 + 4)) {
            FUN_0047a948();
          }
          if (ppiVar9[8] == (int *)0x3) {
            if (ppiVar9 == *(int ***)(iVar15 + 4)) {
              FUN_0047a948();
            }
            piVar14 = ppiVar9[0xb];
            local_d20[0] = piVar14;
            if (ppiVar9 == *(int ***)(iVar15 + 4)) {
              FUN_0047a948();
            }
            piVar4 = ppiVar9[4];
            iVar15 = 0;
            if (*(int *)(*(int *)((int)this + 8) + 0x2404) < 1) goto LAB_0044f15e;
            iVar10 = *(int *)((int)this + 8);
            piVar13 = &DAT_005c48e8 + (int)piVar14 * 2;
            iVar12 = (int)piVar4 * 8;
            do {
              if (((0 < *(int *)((int)&DAT_0058f8ec + iVar12)) ||
                  ((((-1 < *(int *)((int)&DAT_0058f8ec + iVar12) &&
                     (*(int *)((int)&DAT_0058f8e8 + iVar12) != 0)) || (0 < piVar13[1])) ||
                   ((-1 < piVar13[1] && (*piVar13 != 0)))))) ||
                 ((-1 < *(int *)((int)&DAT_005ba0ec + iVar12) &&
                  ((0 < *(int *)((int)&DAT_005ba0ec + iVar12) ||
                   (*(int *)((int)&DAT_005ba0e8 + iVar12) != 0)))))) {
                aiStack_a9c[iVar15] = aiStack_a9c[iVar15] + (int)(piVar4 + 0x2ee) + (int)piVar14;
                piVar14 = local_d20[0];
              }
              iVar15 = iVar15 + 1;
              piVar13 = piVar13 + 0x200;
              iVar12 = iVar12 + 0x800;
            } while (iVar15 < *(int *)(iVar10 + 0x2404));
            UnitList_Advance(&local_d40);
          }
          else {
            if (ppiVar9 == *(int ***)(iVar15 + 4)) {
              FUN_0047a948();
            }
            if (ppiVar9[8] != (int *)0x1) {
              if (ppiVar9 == *(int ***)(iVar15 + 4)) {
                FUN_0047a948();
              }
              if (ppiVar9[8] != (int *)0x5) goto LAB_0044f15e;
            }
            if (ppiVar9 == *(int ***)(iVar15 + 4)) {
              FUN_0047a948();
            }
            piVar14 = ppiVar9[4];
            iVar15 = 0;
            if (*(int *)(*(int *)((int)this + 8) + 0x2404) < 1) goto LAB_0044f15e;
            iVar10 = *(int *)((int)this + 8);
            iVar12 = (int)piVar14 * 8;
            do {
              if (((0 < *(int *)((int)&DAT_0058f8ec + iVar12)) ||
                  ((-1 < *(int *)((int)&DAT_0058f8ec + iVar12) &&
                   (*(int *)((int)&DAT_0058f8e8 + iVar12) != 0)))) ||
                 ((-1 < *(int *)((int)&DAT_005ba0ec + iVar12) &&
                  ((0 < *(int *)((int)&DAT_005ba0ec + iVar12) ||
                   (*(int *)((int)&DAT_005ba0e8 + iVar12) != 0)))))) {
                aiStack_a9c[iVar15] = (int)piVar14 + aiStack_a9c[iVar15] + 4000;
              }
              iVar15 = iVar15 + 1;
              iVar12 = iVar12 + 0x800;
            } while (iVar15 < *(int *)(iVar10 + 0x2404));
            UnitList_Advance(&local_d40);
          }
        }
      }
    }
    if ((_g_NearEndGameFactor == 1.0) && (g_DeceitLevel == 1)) {
      local_d40 = *(int *)((int)this + 8);
      if (0 < *(int *)(local_d40 + 0x2400)) {
        ppvVar6 = local_638;
        for (iVar15 = *(int *)(local_d40 + 0x2400); iVar15 != 0; iVar15 = iVar15 + -1) {
          *ppvVar6 = (void *)0x0;
          ppvVar6 = ppvVar6 + 1;
        }
      }
      local_d3c = (int **)**(undefined4 **)(local_d40 + 0x2454);
      local_d40 = local_d40 + 0x2450;
      while( true ) {
        ppiVar9 = local_d3c;
        iVar15 = local_d40;
        local_cb8 = *(int ***)(*(int *)((int)this + 8) + 0x2454);
        if ((local_d40 == 0) || (local_d40 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (ppiVar9 == local_cb8) break;
        if (iVar15 == 0) {
          FUN_0047a948();
        }
        if (ppiVar9 == *(int ***)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if ((int **)ppiVar9[6] == param_1) {
          if (ppiVar9 == *(int ***)(iVar15 + 4)) {
            FUN_0047a948();
          }
          if (ppiVar9[8] == (int *)0x2) {
LAB_0044f25a:
            if ((ppiVar9 == *(int ***)(iVar15 + 4)) &&
               (FUN_0047a948(), ppiVar9 == *(int ***)(iVar15 + 4))) {
              FUN_0047a948();
            }
            ppiVar11 = ppiVar9 + 10;
            piVar14 = ppiVar9[9];
          }
          else {
            if (ppiVar9 == *(int ***)(iVar15 + 4)) {
              FUN_0047a948();
            }
            if (ppiVar9[8] == (int *)0x6) goto LAB_0044f25a;
            if ((ppiVar9 == *(int ***)(iVar15 + 4)) &&
               (FUN_0047a948(), ppiVar9 == *(int ***)(iVar15 + 4))) {
              FUN_0047a948();
            }
            ppiVar11 = ppiVar9 + 5;
            piVar14 = ppiVar9[4];
          }
          ppiVar9 = AdjacencyList_FilterByUnitType
                              ((void *)(*(int *)((int)this + 8) + 8 + (int)piVar14 * 0x24),
                               (ushort *)ppiVar11);
          local_d2c = ppiVar9;
          local_d28 = (int **)*ppiVar9[1];
          while( true ) {
            ppiVar17 = local_d28;
            ppiVar11 = local_d2c;
            local_cc0 = (int **)ppiVar9[1];
            if ((local_d2c == (int **)0x0) || (local_d2c != ppiVar9)) {
              FUN_0047a948();
            }
            if (ppiVar17 == local_cc0) break;
            if (ppiVar11 == (int **)0x0) {
              FUN_0047a948();
            }
            if (ppiVar17 == (int **)ppiVar11[1]) {
              FUN_0047a948();
            }
            local_638[(int)ppiVar17[3]] = (void *)((int)local_638[(int)ppiVar17[3]] + 1);
            FUN_0040f400((int *)&local_d2c);
          }
        }
        UnitList_Advance(&local_d40);
      }
      iVar15 = 0;
      if (0 < *(int *)(*(int *)((int)this + 8) + 0x2400)) {
        iVar12 = 0;
        do {
          if (*(char *)(iVar12 + 3 + *(int *)((int)this + 8)) != '\0') {
            uVar3 = *(ushort *)(iVar12 + *(int *)((int)this + 8) + 0x20);
            ppiVar9 = (int **)(uVar3 & 0xff);
            if ((char)(uVar3 >> 8) != 'A') {
              ppiVar9 = (int **)0x14;
            }
            if (param_1 != ppiVar9) {
              iVar10 = (int)param_1 * 0x15 + (int)ppiVar9;
              if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar10 * 2]) &&
                 (((0 < (int)(&g_AllyTrustScore_Hi)[iVar10 * 2] ||
                   (1 < (uint)(&g_AllyTrustScore)[iVar10 * 2])) && (1 < (int)local_638[iVar15])))) {
                g_EarlyGameAdjScore = g_EarlyGameAdjScore + 0xa0;
              }
            }
          }
          iVar15 = iVar15 + 1;
          iVar12 = iVar12 + 0x24;
        } while (iVar15 < *(int *)(*(int *)((int)this + 8) + 0x2400));
      }
    }
    aiStack_a9c[(int)param_1] = 0;
    uVar19 = EvaluateOrderScore(this,(int)param_1);
    iVar15 = DAT_00633f14;
    local_c44 = (undefined4)uVar19;
    local_c0c = 0;
    (&DAT_00b9fe88)[(int)param_1] = (&DAT_00b9fe88)[(int)param_1] + 1;
    local_c34 = 0x461c4000;
    local_c10 = iVar15 + local_d04 + local_d24;
    local_aa0 = 0;
    local_c28 = g_EarlyGameAdjScore;
    iVar15 = *(int *)((int)this + 8);
    local_c2c = DAT_0062c57c;
    local_c14 = 0;
    local_c24 = 0;
    local_c20 = 0;
    local_c13 = 0;
    local_c3c = 10000;
    local_c38 = 0;
    local_c30 = 0;
    local_c18 = DAT_0062b7ac;
    local_c48 = param_1;
    iVar12 = 0;
    if (0 < *(int *)(iVar15 + 0x2400)) {
      do {
        auStack_a48[iVar12] = 0;
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(int *)(iVar15 + 0x2400));
    }
    iVar15 = 0;
    do {
      auStack_c08[iVar15] = 0;
      auStack_b90[iVar15] = 0;
      auStack_b18[iVar15] = 0;
      iVar15 = iVar15 + 1;
    } while (iVar15 < 0x1e);
    local_c40 = local_c44;
    FUN_00465f60(local_638,local_cac);
    local_c._0_1_ = 8;
    TrialEvaluateOrders(local_628,&local_c48);
    local_c._0_1_ = 9;
    InsertCandidateRecord(&g_CandidateRecordList,&local_cbc,local_638);
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_0042ee00(local_638);
    BuildSupportProposals(this,(int)param_1);
  }
  local_c._0_1_ = 2;
  FreeList(local_c9c);
  local_c = CONCAT31(local_c._1_3_,1);
  FreeList(local_cac);
  piVar14 = (int *)*local_ce8;
  *local_ce8 = (int)local_ce8;
  local_ce8[1] = (int)local_ce8;
  local_ce4 = 0;
  if (piVar14 != local_ce8) {
    do {
      piVar4 = (int *)*piVar14;
      _free(piVar14);
      piVar14 = piVar4;
    } while (piVar4 != local_ce8);
  }
  _free(local_ce8);
  local_ce8 = (int *)0x0;
  local_c = 0xffffffff;
  FUN_004225b0(local_648,&local_cbc,local_648,(int **)*local_644,local_648,local_644);
  _free(local_644);
  ExceptionList = local_14;
  return;
LAB_0044f07a:
  if (local_d3c == *(int ***)(local_d40 + 4)) {
    FUN_0047a948();
  }
LAB_0044f093:
  ppiVar9 = OrderedSet_FindOrInsert((void *)((int)this + (int)param_1 * 0xc + 0x4000),ppiVar9 + 9);
  aiStack_a9c[(int)local_d38] =
       (int)*ppiVar9 + aiStack_a9c[(int)local_d38] + (int)local_ccc + (int)local_d20[0] + 1000;
LAB_0044f133:
  local_d0c = local_d0c + 0x800;
  local_d30 = local_d30 + 0x200;
  local_d38 = (int **)((int)local_d38 + 1);
  if (*(int *)(*(int *)((int)this + 8) + 0x2404) <= (int)local_d38) goto LAB_0044f15e;
  goto LAB_0044ee60;
}

