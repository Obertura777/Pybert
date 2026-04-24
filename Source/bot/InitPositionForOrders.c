
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall InitPositionForOrders(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  uint **ppuVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  undefined4 *puVar13;
  int iVar14;
  uint local_df0;
  int local_de8;
  int local_de4;
  uint local_de0;
  uint local_ddc;
  int local_dd8;
  void *local_dd4;
  int local_dd0;
  void *local_dc8 [2];
  void *local_dc0 [4];
  uint *local_db0 [4];
  int *local_da0;
  undefined2 local_d9c;
  undefined4 local_d98 [42];
  undefined4 local_cf0;
  undefined4 local_cec;
  undefined4 local_ce8;
  undefined4 local_ce4;
  undefined4 local_ce0;
  undefined4 local_cdc;
  undefined4 local_cd8;
  undefined4 local_ccc;
  undefined4 local_cc8;
  undefined4 local_cc4;
  undefined1 local_cbc;
  undefined4 local_cb4;
  undefined4 auStack_cb0 [30];
  undefined4 auStack_c38 [30];
  undefined4 auStack_bc0 [30];
  undefined4 local_b48;
  undefined4 auStack_af0 [256];
  undefined1 local_6f0 [4];
  int **local_6ec;
  undefined4 local_6e8;
  undefined4 local_6e0 [21];
  undefined4 auStack_68c [22];
  void *local_634 [4];
  undefined1 local_624 [1552];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497ab7;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_de8 = 0;
  local_6ec = (int **)FUN_00410050();
  *(undefined1 *)((int)local_6ec + 0x31) = 1;
  local_6ec[1] = (int *)local_6ec;
  *local_6ec = (int *)local_6ec;
  local_6ec[2] = (int *)local_6ec;
  local_6e8 = 0;
  local_c = 0;
  FUN_00465870(local_dc0);
  iVar5 = 0;
  local_c._0_1_ = 1;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    iVar14 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
    do {
      auStack_68c[iVar5] = 0;
      local_6e0[iVar5] = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar14);
  }
  ppuVar6 = FUN_00466f80(&SUB,local_db0,(void **)&DAT_00bc1e0c);
  local_c._0_1_ = 2;
  AppendList(local_dc0,ppuVar6);
  local_c = CONCAT31(local_c._1_3_,1);
  FreeList(local_db0);
  local_cb4 = 0;
  local_cec = 0;
  local_cdc = 0x461c4000;
  local_ce8 = 0;
  local_cbc = 0;
  local_ce4 = 10000;
  local_b48 = 0;
  local_ce0 = 0;
  local_ccc = 0;
  local_cc8 = 0;
  local_cc4 = 0;
  local_cd8 = 0;
  local_cf0 = 0;
  FUN_0041c480(local_6ec[1]);
  local_6ec[1] = (int *)local_6ec;
  local_6e8 = 0;
  *local_6ec = (int *)local_6ec;
  local_6ec[2] = (int *)local_6ec;
  local_df0 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    iVar5 = 0;
    do {
      iVar14 = *(int *)((int)&DAT_00bb6f2c + iVar5);
      auStack_af0[local_df0 + -0x15] = 0;
      piVar7 = *(int **)(iVar14 + 4);
      cVar1 = *(char *)((int)piVar7 + 0x11);
      while (cVar1 == '\0') {
        FUN_00401950((int *)piVar7[2]);
        piVar3 = (int *)*piVar7;
        _free(piVar7);
        piVar7 = piVar3;
        cVar1 = *(char *)((int)piVar3 + 0x11);
      }
      *(int *)(*(int *)((int)&DAT_00bb6f2c + iVar5) + 4) = *(int *)((int)&DAT_00bb6f2c + iVar5);
      *(undefined4 *)((int)&DAT_00bb6f30 + iVar5) = 0;
      *(undefined4 *)*(undefined4 *)((int)&DAT_00bb6f2c + iVar5) =
           *(undefined4 *)((int)&DAT_00bb6f2c + iVar5);
      *(int *)(*(int *)((int)&DAT_00bb6f2c + iVar5) + 8) = *(int *)((int)&DAT_00bb6f2c + iVar5);
      piVar7 = *(int **)(*(int *)((int)&DAT_00bb702c + iVar5) + 4);
      cVar1 = *(char *)((int)piVar7 + 0x11);
      while (cVar1 == '\0') {
        FUN_00401950((int *)piVar7[2]);
        piVar3 = (int *)*piVar7;
        _free(piVar7);
        piVar7 = piVar3;
        cVar1 = *(char *)((int)piVar3 + 0x11);
      }
      *(int *)(*(int *)((int)&DAT_00bb702c + iVar5) + 4) = *(int *)((int)&DAT_00bb702c + iVar5);
      *(undefined4 *)((int)&DAT_00bb7030 + iVar5) = 0;
      *(undefined4 *)*(undefined4 *)((int)&DAT_00bb702c + iVar5) =
           *(undefined4 *)((int)&DAT_00bb702c + iVar5);
      *(int *)(*(int *)((int)&DAT_00bb702c + iVar5) + 8) = *(int *)((int)&DAT_00bb702c + iVar5);
      local_df0 = local_df0 + 1;
      iVar5 = iVar5 + 0xc;
    } while ((int)local_df0 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  iVar5 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    do {
      (&DAT_00ba2f70)[iVar5] = 0xffffffff;
      iVar14 = *(int *)(param_1 + 8);
      auStack_af0[iVar5] = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(iVar14 + 0x2400));
  }
  iVar5 = 0;
  do {
    auStack_cb0[iVar5] = 0;
    auStack_c38[iVar5] = 0;
    auStack_bc0[iVar5] = 0;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x1e);
  FUN_00465f60(local_634,local_dc0);
  local_c._0_1_ = 3;
  TrialEvaluateOrders(local_624,&local_cf0);
  local_c._0_1_ = 4;
  InsertCandidateRecord(&DAT_00bbf614,&local_dd4,local_634);
  local_c = CONCAT31(local_c._1_3_,1);
  FUN_0042ee00(local_634);
  cVar1 = *(char *)((int)*(int **)(DAT_00bb7134 + 4) + 0x19);
  piVar7 = *(int **)(DAT_00bb7134 + 4);
  while (cVar1 == '\0') {
    FUN_0040fb70((int *)piVar7[2]);
    piVar3 = (int *)*piVar7;
    _free(piVar7);
    piVar7 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x19);
  }
  *(int *)(DAT_00bb7134 + 4) = DAT_00bb7134;
  _DAT_00bb7138 = 0;
  *(int *)DAT_00bb7134 = DAT_00bb7134;
  *(int *)(DAT_00bb7134 + 8) = DAT_00bb7134;
  *(undefined4 *)(param_1 + 0x3ffc) = 0;
  local_de4 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    local_dc8[0] = (void *)(param_1 + 0x2a1c);
    local_df0 = 0;
    do {
      iVar5 = local_df0 + *(int *)(param_1 + 8);
      if (*(char *)(local_df0 + 3 + *(int *)(param_1 + 8)) != '\0') {
        local_de8 = local_de8 + 1;
      }
      local_dd8 = **(int **)(iVar5 + 0xc);
      local_de0 = iVar5 + 8;
      local_ddc = local_de0;
      while( true ) {
        iVar14 = local_dd8;
        uVar8 = local_ddc;
        iVar5 = *(int *)(local_de0 + 4);
        if ((local_ddc == 0) || (local_ddc != local_de0)) {
          FUN_0047a948();
        }
        if (iVar14 == iVar5) break;
        if (uVar8 == 0) {
          FUN_0047a948();
        }
        if (iVar14 == *(int *)(uVar8 + 4)) {
          FUN_0047a948();
        }
        local_dd0 = **(int **)(iVar14 + 0x14);
        local_dd4 = (void *)(iVar14 + 0x10);
        while( true ) {
          iVar11 = local_dd0;
          pvVar12 = local_dd4;
          iVar5 = *(int *)(iVar14 + 0x14);
          if ((local_dd4 == (void *)0x0) || (local_dd4 != (void *)(iVar14 + 0x10))) {
            FUN_0047a948();
          }
          if (iVar11 == iVar5) break;
          if (pvVar12 == (void *)0x0) {
            FUN_0047a948();
          }
          if (iVar11 == *(int *)((int)pvVar12 + 4)) {
            FUN_0047a948();
          }
          StdMap_FindOrInsert(local_dc8[0],local_db0,(int *)(iVar11 + 0xc));
          FUN_0040f400((int *)&local_dd4);
        }
        FUN_00401590((int *)&local_ddc);
      }
      local_df0 = local_df0 + 0x24;
      local_dc8[0] = (void *)((int)local_dc8[0] + 0xc);
      local_de4 = local_de4 + 1;
    } while (local_de4 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  *(int *)(param_1 + 0x3ffc) = local_de8 / 2 + 1;
  local_de4 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    local_de8 = 0;
    pvVar12 = (void *)(param_1 + 0x2a1c);
    do {
      iVar5 = local_de8 + *(int *)(param_1 + 8);
      if (*(char *)(local_de8 + 3 + *(int *)(param_1 + 8)) != '\0') {
        if ((char)(*(ushort *)(iVar5 + 0x20) >> 8) == 'A') {
          local_df0 = *(ushort *)(iVar5 + 0x20) & 0xff;
        }
        else {
          local_df0 = 0x14;
        }
        iVar14 = *(int *)(iVar5 + 0x18);
        local_de0 = local_df0;
        piVar7 = (int *)GameBoard_GetPowerRec
                                  ((void *)(iVar5 + 0x14),(int *)local_dc8,(int *)&local_de0);
        if (((void *)*piVar7 == (void *)0x0) || ((void *)*piVar7 != (void *)(iVar5 + 0x14))) {
          FUN_0047a948();
        }
        if (piVar7[1] != iVar14) {
          (&DAT_00ba2f70)[local_de4] = local_df0;
          local_dd0 = **(int **)((int)pvVar12 + 4);
          local_dd4 = pvVar12;
          while( true ) {
            iVar14 = local_dd0;
            pvVar4 = local_dd4;
            iVar5 = *(int *)((int)pvVar12 + 4);
            if ((local_dd4 == (void *)0x0) || (local_dd4 != pvVar12)) {
              FUN_0047a948();
            }
            if (iVar14 == iVar5) break;
            if (pvVar4 == (void *)0x0) {
              FUN_0047a948();
            }
            if (iVar14 == *(int *)((int)pvVar4 + 4)) {
              FUN_0047a948();
            }
            if ((&DAT_00ba2f70)[*(int *)(iVar14 + 0xc)] == -1) {
              if (iVar14 == *(int *)((int)pvVar4 + 4)) {
                FUN_0047a948();
              }
              (&DAT_00ba2f70)[*(int *)(iVar14 + 0xc)] = local_df0;
              TreeIterator_Advance((int *)&local_dd4);
            }
            else {
              if (iVar14 == *(int *)((int)pvVar4 + 4)) {
                FUN_0047a948();
              }
              if ((&DAT_00ba2f70)[*(int *)(iVar14 + 0xc)] != local_df0) {
                if (iVar14 == *(int *)((int)pvVar4 + 4)) {
                  FUN_0047a948();
                }
                (&DAT_00ba2f70)[*(int *)(iVar14 + 0xc)] = 0xfffffffe;
              }
              TreeIterator_Advance((int *)&local_dd4);
            }
          }
        }
      }
      local_de8 = local_de8 + 0x24;
      local_de4 = local_de4 + 1;
      pvVar12 = (void *)((int)pvVar12 + 0xc);
    } while (local_de4 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  local_dc8[0] = (void *)0x0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    local_df0 = 0;
    do {
      (&DAT_004cf4c0)[(int)local_dc8[0] * 2] = 0;
      (&DAT_004cf4c4)[(int)local_dc8[0] * 2] = 0;
      iVar5 = 0;
      uVar8 = local_df0;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
        do {
          *(undefined4 *)((int)&DAT_0062a2f8 + uVar8) = 0;
          *(undefined4 *)((int)&g_AllyMatrix + uVar8) = 0;
          iVar5 = iVar5 + 1;
          uVar8 = uVar8 + 4;
        } while (iVar5 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      piVar7 = (int *)0x0;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
        local_de8 = 0;
        do {
          local_dd8 = **(int **)(local_de8 + 0xc + *(int *)(param_1 + 8));
          local_de0 = local_de8 + 8 + *(int *)(param_1 + 8);
          local_ddc = local_de0;
          while( true ) {
            iVar14 = local_dd8;
            uVar8 = local_ddc;
            iVar5 = *(int *)(local_de0 + 4);
            if ((local_ddc == 0) || (local_ddc != local_de0)) {
              FUN_0047a948();
            }
            if (iVar14 == iVar5) break;
            if (uVar8 == 0) {
              FUN_0047a948();
            }
            if (iVar14 == *(int *)(uVar8 + 4)) {
              FUN_0047a948();
            }
            uVar2 = *(undefined2 *)(iVar14 + 0xc);
            puVar9 = local_6e0;
            puVar13 = local_d98;
            for (iVar5 = 0x2a; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar13 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar13 = puVar13 + 1;
            }
            local_da0 = piVar7;
            local_d9c = uVar2;
            FUN_00419150(&DAT_00baed7c,local_db0,&local_da0);
            puVar9 = local_6e0;
            puVar13 = local_d98;
            for (iVar5 = 0x2a; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar13 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar13 = puVar13 + 1;
            }
            local_da0 = piVar7;
            local_d9c = uVar2;
            FUN_00419150(&DAT_00baed88,&local_dd4,&local_da0);
            FUN_00401590((int *)&local_ddc);
          }
          local_de8 = local_de8 + 0x24;
          piVar7 = (int *)((int)piVar7 + 1);
        } while ((int)piVar7 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
      }
      local_dc8[0] = (void *)((int)local_dc8[0] + 1);
      local_df0 = local_df0 + 0x54;
    } while ((int)local_dc8[0] < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  EnumerateConvoyReach(param_1);
  iVar5 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    iVar14 = 0;
    do {
      iVar11 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
        do {
          iVar10 = 0;
          if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
            puVar9 = &g_MoveHistoryMatrix + (iVar14 + iVar11) * 0x100;
            do {
              *puVar9 = 0;
              iVar10 = iVar10 + 1;
              puVar9 = puVar9 + 1;
            } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
      }
      iVar5 = iVar5 + 1;
      iVar14 = iVar14 + 0x100;
    } while (iVar5 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  local_c = local_c & 0xffffff00;
  FreeList(local_dc0);
  local_c = 0xffffffff;
  FUN_004225b0(local_6f0,&local_dd4,local_6f0,(int **)*local_6ec,local_6f0,local_6ec);
  _free(local_6ec);
  ExceptionList = local_14;
  return;
}

