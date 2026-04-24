
void RefreshOrderTable(int param_1)

{
  float fVar1;
  int *piVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar9;
  undefined4 extraout_ECX_04;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *extraout_EDX_01;
  int *extraout_EDX_02;
  int *piVar10;
  int *extraout_EDX_03;
  int **ppiVar11;
  int **ppiVar12;
  ulonglong uVar13;
  float local_58;
  int local_54;
  int local_50;
  int **local_48;
  int *local_44;
  int **local_40;
  int **local_3c;
  int *local_38;
  int *local_34;
  int **local_30;
  undefined4 local_2c;
  undefined4 local_28 [3];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004962b0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_30 = (int **)FUN_00410330();
  *(undefined1 *)((int)local_30 + 0x19) = 1;
  local_30[1] = (int *)local_30;
  *local_30 = (int *)local_30;
  local_30[2] = (int *)local_30;
  local_2c = 0;
  local_4 = 0;
  FUN_00465870(local_1c);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0040fb70(local_30[1]);
  local_30[1] = (int *)local_30;
  local_2c = 0;
  *local_30 = (int *)local_30;
  local_30[2] = (int *)local_30;
  local_44 = (int *)*DAT_00bbf60c;
  local_48 = (int **)&g_CandidateRecordList;
  uVar9 = extraout_ECX;
  piVar10 = DAT_00bbf60c;
  while( true ) {
    piVar3 = local_44;
    ppiVar12 = local_48;
    piVar2 = DAT_00bbf60c;
    if ((local_48 == (int **)0x0) || (local_48 != (int **)&g_CandidateRecordList)) {
      FUN_0047a948();
      uVar9 = extraout_ECX_00;
      piVar10 = extraout_EDX;
    }
    if (piVar3 == piVar2) break;
    if (ppiVar12 == (int **)0x0) {
      FUN_0047a948();
      uVar9 = extraout_ECX_01;
      piVar10 = extraout_EDX_00;
    }
    if (piVar3 == ppiVar12[1]) {
      FUN_0047a948();
      uVar9 = extraout_ECX_02;
      piVar10 = extraout_EDX_01;
    }
    if (piVar3[7] == param_1) {
      if (piVar3 == ppiVar12[1]) {
        FUN_0047a948();
        uVar9 = extraout_ECX_03;
        piVar10 = extraout_EDX_02;
      }
      uVar13 = FloatToInt64(uVar9,piVar10);
      local_40 = (int **)uVar13;
      local_3c = ppiVar12;
      local_38 = piVar3;
      FUN_00419fa0(&local_34,local_28,(int *)&local_40);
    }
    FUN_0040f260((int *)&local_48);
    uVar9 = extraout_ECX_04;
    piVar10 = extraout_EDX_03;
  }
  local_54 = 0;
  do {
    local_58 = 0.0;
    local_48 = &local_34;
    ppiVar12 = (int **)*local_30;
    if ((int **)*local_30 != local_30) {
      while( true ) {
        local_40 = local_48;
        local_3c = ppiVar12;
        FUN_0040e680((int *)&local_40);
        ppiVar6 = local_30;
        ppiVar4 = local_40;
        if ((local_40 == (int **)0x0) || (local_40 != &local_34)) {
          FUN_0047a948();
        }
        ppiVar5 = local_3c;
        ppiVar11 = local_48;
        if (local_3c == ppiVar6) break;
        if (local_48 == (int **)0x0) {
          FUN_0047a948();
        }
        if (ppiVar12 == (int **)ppiVar11[1]) {
          FUN_0047a948();
        }
        if ((int)ppiVar12[3] < 1) {
LAB_00424684:
          fVar1 = 0.0;
        }
        else {
          if (ppiVar4 == (int **)0x0) {
            FUN_0047a948();
          }
          if (ppiVar5 == (int **)ppiVar4[1]) {
            FUN_0047a948();
          }
          if ((int)ppiVar5[3] < 1) goto LAB_00424684;
          if (ppiVar12 == (int **)ppiVar11[1]) {
            FUN_0047a948();
          }
          fVar1 = (float)(1000 - (int)ppiVar12[3]) - local_58;
        }
        iVar7 = _rand();
        iVar7 = (iVar7 / 0x17) % 3;
        if (1 < iVar7 + 2) {
          iVar7 = iVar7 + 1;
          do {
            iVar8 = _rand();
            local_50 = (iVar8 / 0x17) % 1000;
            iVar7 = iVar7 + -1;
            ppiVar11 = local_48;
          } while (iVar7 != 0);
        }
        if (fVar1 < (float)local_50 != (fVar1 == (float)local_50)) goto LAB_004247b9;
        if (local_54 == 0) {
          if ((DAT_00baed6c == '\x01') && (DAT_00624124 != param_1)) {
            if (ppiVar4 == (int **)0x0) {
              FUN_0047a948();
            }
            if (ppiVar5 == (int **)ppiVar4[1]) {
              FUN_0047a948();
            }
            if ((int)ppiVar5[3] < 0x32) break;
          }
          if (((int)(&curr_sc_cnt)[param_1] < 4) && (DAT_00baed68 == '\0')) {
            if (ppiVar4 == (int **)0x0) {
              FUN_0047a948();
            }
            if (ppiVar5 == (int **)ppiVar4[1]) {
              FUN_0047a948();
            }
            if ((int)ppiVar5[3] < 0x32) break;
          }
          ppiVar11 = local_48;
          if ((int)(&curr_sc_cnt)[param_1] < 6) {
            if (ppiVar4 == (int **)0x0) {
              FUN_0047a948();
            }
            if (ppiVar5 == (int **)ppiVar4[1]) {
              FUN_0047a948();
            }
            ppiVar11 = local_48;
            if ((int)ppiVar5[3] < 0x14) break;
          }
        }
        if (ppiVar12 == (int **)ppiVar11[1]) {
          FUN_0047a948();
        }
        local_48 = ppiVar4;
        local_58 = (float)(int)ppiVar12[3] + local_58;
        ppiVar12 = ppiVar5;
      }
    }
    ppiVar12 = (int **)*local_30;
    ppiVar11 = &local_34;
    local_48 = ppiVar11;
LAB_004247b9:
    if (ppiVar11 == (int **)0x0) {
      FUN_0047a948();
    }
    if (ppiVar12 == (int **)ppiVar11[1]) {
      FUN_0047a948();
    }
    iVar7 = param_1 * 0x1e + local_54;
    local_54 = local_54 + 1;
    (&DAT_00bbf690)[iVar7 * 2] = ppiVar12[4];
    (&DAT_00bbf694)[iVar7 * 2] = ppiVar12[5];
    if (0x1d < local_54) {
      local_4 = local_4 & 0xffffff00;
      FreeList(local_1c);
      local_4 = 0xffffffff;
      FUN_00414e10(&local_34,&local_40,&local_34,(int **)*local_30,&local_34,local_30);
      _free(local_30);
      ExceptionList = local_c;
      return;
    }
  } while( true );
}

