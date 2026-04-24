
void __fastcall InitScoringState(int param_1)

{
  char cVar1;
  ushort uVar2;
  int *piVar3;
  undefined1 *puVar4;
  int **ppiVar5;
  int iVar6;
  int **ppiVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint extraout_ECX;
  uint uVar11;
  undefined *puVar12;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  undefined4 *puVar16;
  int *piVar17;
  uint uVar18;
  float *pfVar19;
  ulonglong uVar20;
  undefined *local_464;
  undefined4 *local_460;
  int local_45c;
  undefined1 local_458 [4];
  int **local_454;
  undefined4 local_450;
  uint local_44c;
  uint local_448;
  uint local_444;
  undefined4 *local_440;
  int local_43c;
  undefined1 *local_438;
  int **local_434;
  int local_430;
  void *local_42c;
  int local_428;
  undefined4 local_424 [3];
  int local_418 [257];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0049783b;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_430 = param_1;
  local_454 = (int **)FUN_0040ff50();
  *(undefined1 *)((int)local_454 + 0x15) = 1;
  local_454[1] = (int *)local_454;
  *local_454 = (int *)local_454;
  local_454[2] = (int *)local_454;
  local_450 = 0;
  iVar15 = 0;
  local_c = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
    puVar16 = &DAT_00624ef8;
    do {
      iVar6 = 0;
      puVar8 = puVar16;
      if (0 < iVar9) {
        do {
          *puVar8 = 0;
          iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
          iVar6 = iVar6 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar6 < iVar9);
      }
      iVar15 = iVar15 + 1;
      puVar16 = puVar16 + 0x100;
    } while (iVar15 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  iVar15 = *(int *)(param_1 + 8);
  iVar9 = *(int *)(iVar15 + 0x2400);
  if (0 < iVar9) {
    piVar17 = local_418;
    for (; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
  }
  iVar9 = 0;
  if (0 < *(int *)(iVar15 + 0x2404)) {
    iVar15 = 0;
    do {
      (&target_sc_cnt)[iVar9] = (&curr_sc_cnt)[iVar9];
      iVar10 = 0;
      iVar6 = iVar15;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
        do {
          *(undefined4 *)((int)&DAT_00624810 + iVar6) = 0;
          *(undefined4 *)((int)&DAT_00624128 + iVar6) = 0;
          *(undefined4 *)((int)&DAT_006239e8 + iVar6) = 0;
          iVar10 = iVar10 + 1;
          iVar6 = iVar6 + 4;
        } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar9 = iVar9 + 1;
      iVar15 = iVar15 + 0x54;
    } while (iVar9 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  local_460 = (undefined4 *)**(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_464 = (undefined *)(*(int *)(param_1 + 8) + 0x2450);
  while( true ) {
    puVar16 = local_460;
    puVar12 = local_464;
    iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_464 == (undefined *)0x0) ||
       (local_464 != (undefined *)(*(int *)(param_1 + 8) + 0x2450))) {
      FUN_0047a948();
    }
    if (puVar16 == (undefined4 *)iVar15) break;
    if (puVar12 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar16 == (undefined4 *)*(int *)(puVar12 + 4)) {
      FUN_0047a948();
    }
    local_418[*(int *)((int)puVar16 + 0x10)] = 1;
    UnitList_Advance((int *)&local_464);
  }
  local_460 = (undefined4 *)*DAT_00bc1e20;
  local_464 = &DAT_00bc1e1c;
  while( true ) {
    puVar8 = local_460;
    puVar12 = local_464;
    puVar16 = DAT_00bc1e20;
    if ((local_464 == (undefined *)0x0) || (local_464 != &DAT_00bc1e1c)) {
      FUN_0047a948();
    }
    if (puVar8 == puVar16) break;
    if (puVar12 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar8 == *(undefined4 **)(puVar12 + 4)) {
      FUN_0047a948();
    }
    local_438 = (undefined1 *)puVar8[3];
    local_434 = (int **)puVar8[4];
    if (((*(char *)(*(int *)(param_1 + 8) + 3 + (int)local_438 * 0x24) != '\0') &&
        (uVar2 = *(ushort *)(*(int *)(param_1 + 8) + (int)local_438 * 0x24 + 0x20),
        (char)(uVar2 >> 8) == 'A')) && ((uVar2 & 0xff) != 0x14)) {
      if (local_460 == *(undefined4 **)(local_464 + 4)) {
        FUN_0047a948();
      }
      local_440 = local_460 + 5;
      local_43c = *(int *)local_460[6];
      while( true ) {
        iVar15 = local_43c;
        puVar8 = local_440;
        puVar16 = local_460;
        if (local_460 == *(undefined4 **)(local_464 + 4)) {
          FUN_0047a948();
        }
        iVar9 = puVar16[6];
        if ((puVar8 == (undefined4 *)0x0) || (puVar8 != puVar16 + 5)) {
          FUN_0047a948();
        }
        if (iVar15 == iVar9) break;
        if (puVar8 == (undefined4 *)0x0) {
          FUN_0047a948();
        }
        if (iVar15 == puVar8[1]) {
          FUN_0047a948();
        }
        local_428 = *(int *)(iVar15 + 0x14);
        if (local_418[*(int *)(iVar15 + 0x10)] == 1) {
          if (iVar15 == puVar8[1]) {
            FUN_0047a948();
          }
          ppiVar7 = UnitList_FindOrInsert
                              ((void *)(*(int *)(param_1 + 8) + 0x2450),(int *)(iVar15 + 0x10));
          if ((short)local_428 == *(short *)(ppiVar7 + 1)) {
            if (iVar15 == puVar8[1]) {
              FUN_0047a948();
            }
            (&DAT_00624ef8)[(int)(local_438 + (int)ppiVar7[2] * 0x100)] =
                 (float)((float10)10000.0 / (float10)*(double *)(iVar15 + 0x20) +
                        (float10)(float)(&DAT_00624ef8)[(int)(local_438 + (int)ppiVar7[2] * 0x100)])
            ;
          }
        }
        FUN_0040f7f0((int *)&local_440);
      }
    }
    std_Tree_IteratorIncrement((int *)&local_464);
  }
  uVar13 = *(uint *)(param_1 + 8);
  iVar15 = *(int *)(uVar13 + 0x2404);
  local_440 = (undefined4 *)0x0;
  if (0 < iVar15) {
    local_44c = 0;
    local_464 = (undefined *)0x0;
    do {
      local_448 = 0;
      if (0 < iVar15) {
        do {
          cVar1 = *(char *)((int)local_454[1] + 0x15);
          piVar17 = local_454[1];
          while (cVar1 == '\0') {
            FUN_004019f0((int *)piVar17[2]);
            piVar3 = (int *)*piVar17;
            _free(piVar17);
            piVar17 = piVar3;
            uVar13 = extraout_EDX;
            cVar1 = *(char *)((int)piVar3 + 0x15);
          }
          local_454[1] = (int *)local_454;
          iVar9 = 0;
          local_450 = 0;
          *local_454 = (int *)local_454;
          local_454[2] = (int *)local_454;
          iVar15 = *(int *)(param_1 + 8);
          local_45c = 0;
          if (0 < *(int *)(iVar15 + 0x2400)) {
            local_444 = 0;
            do {
              uVar11 = local_444;
              if (*(char *)(iVar15 + 3 + local_444) != '\0') {
                uVar2 = *(ushort *)(iVar15 + 0x20 + local_444);
                uVar18 = uVar2 & 0xff;
                if ((char)(uVar2 >> 8) != 'A') {
                  uVar18 = 0x14;
                }
                uVar13 = local_444;
                if (uVar18 == local_448) {
                  puVar12 = local_464 + iVar9;
                  iVar15 = uVar18 * 0x100 + iVar9;
                  local_42c = (void *)((float)(&DAT_00624ef8)[(int)puVar12] /
                                      (float)(&DAT_00624ef8)[iVar15]);
                  local_428 = iVar9;
                  FUN_0041a180(local_458,local_424,(float *)&local_42c);
                  local_45c = local_45c + 1;
                  uVar11 = extraout_ECX;
                  uVar13 = extraout_EDX_00;
                  if ((float)(&DAT_00624ef8)[iVar15] < (float)(&DAT_00624ef8)[(int)puVar12]) {
                    iVar15 = local_44c + uVar18;
                    uVar13 = (&g_AllyTrustScore)[iVar15 * 2];
                    uVar11 = 1;
                    (&DAT_00624128)[iVar15] = (&DAT_00624128)[iVar15] + 1;
                    uVar13 = uVar13 | (&g_AllyTrustScore_Hi)[iVar15 * 2];
                    if (uVar13 == 0) {
                      (&target_sc_cnt)[(int)local_440] = (&target_sc_cnt)[(int)local_440] + 1;
                      (&target_sc_cnt)[uVar18] = (&target_sc_cnt)[uVar18] + -1;
                    }
                  }
                }
              }
              iVar15 = *(int *)(local_430 + 8);
              local_444 = local_444 + 0x24;
              iVar9 = iVar9 + 1;
            } while (iVar9 < *(int *)(iVar15 + 0x2400));
            if (0 < local_45c) {
              uVar20 = FloatToInt64(uVar11,uVar13);
              local_45c = (int)uVar20;
              if (local_45c == 0) {
                local_45c = 1;
              }
              iVar15 = 0;
              local_438 = local_458;
              local_434 = (int **)*local_454;
              while( true ) {
                ppiVar5 = local_434;
                puVar4 = local_438;
                ppiVar7 = local_454;
                if ((local_438 == (undefined1 *)0x0) || (local_438 != local_458)) {
                  FUN_0047a948();
                }
                if (ppiVar5 == ppiVar7) break;
                if (puVar4 == (undefined1 *)0x0) {
                  FUN_0047a948();
                }
                if (ppiVar5 == *(int ***)(puVar4 + 4)) {
                  FUN_0047a948();
                }
                iVar15 = iVar15 + 1;
                (&DAT_00624810)[local_448 + local_44c] =
                     (float)ppiVar5[3] + (float)(&DAT_00624810)[local_448 + local_44c];
                if (local_45c <= iVar15) break;
                FUN_0040f400((int *)&local_438);
              }
              (&DAT_00624810)[local_448 + local_44c] =
                   (float)(&DAT_00624810)[local_448 + local_44c] / (float)local_45c;
              uVar13 = local_44c;
            }
          }
          local_448 = local_448 + 1;
          param_1 = local_430;
        } while ((int)local_448 < *(int *)(*(int *)(local_430 + 8) + 0x2404));
      }
      uVar13 = *(uint *)(param_1 + 8);
      iVar15 = *(int *)(uVar13 + 0x2404);
      local_464 = local_464 + 0x100;
      local_44c = local_44c + 0x15;
      local_440 = (undefined4 *)((int)local_440 + 1);
    } while ((int)local_440 < iVar15);
  }
  iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar9 = 0;
  if (0 < iVar15) {
    local_464 = (undefined *)0x0;
    pfVar14 = (float *)&DAT_00624810;
    do {
      iVar6 = 0;
      puVar12 = local_464;
      pfVar19 = pfVar14;
      if (0 < iVar15) {
        do {
          if (*pfVar19 <= 0.0) {
            *(undefined4 *)((int)&DAT_006239e8 + (int)puVar12) = 0x41200000;
          }
          else {
            *(float *)((int)&DAT_006239e8 + (int)puVar12) =
                 *(float *)((int)&DAT_00624810 + (int)puVar12) / *pfVar19;
          }
          iVar6 = iVar6 + 1;
          puVar12 = puVar12 + 4;
          pfVar19 = pfVar19 + 0x15;
        } while (iVar6 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      local_464 = local_464 + 0x54;
      iVar9 = iVar9 + 1;
      pfVar14 = pfVar14 + 1;
    } while (iVar9 < iVar15);
  }
  local_c = 0xffffffff;
  FUN_0041afd0(local_458,&local_42c,local_458,(int **)*local_454,local_458,local_454);
  _free(local_454);
  ExceptionList = local_14;
  return;
}

