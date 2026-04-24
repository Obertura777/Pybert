
char __thiscall ComputeDrawVote(void *this,void *param_1)

{
  void *pvVar1;
  char cVar2;
  ushort uVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int **ppiVar9;
  int *piVar10;
  int **ppiVar11;
  int **ppiVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  int iVar15;
  undefined1 *puVar16;
  char local_115;
  int local_110;
  int local_10c;
  undefined1 local_108 [4];
  int **local_104;
  undefined4 local_100;
  int *local_fc;
  int **local_f8;
  int **local_f4;
  undefined1 *local_f0;
  int **local_ec;
  int local_e8;
  undefined1 local_e4 [4];
  int **local_e0;
  undefined4 local_dc;
  int local_d8;
  int **local_d4;
  undefined4 local_d0;
  int *local_cc;
  undefined1 *local_c8;
  int **local_c4;
  undefined1 local_c0 [4];
  int **local_bc;
  undefined4 local_b8;
  int **local_b4;
  int *local_b0;
  undefined1 *local_ac;
  int **local_a8;
  int **local_a4;
  int *local_a0;
  int *local_9c;
  int local_98;
  int local_94;
  void *local_90 [3];
  int *local_84 [2];
  undefined4 local_7c;
  int *local_70;
  int local_68;
  int local_60;
  int *local_58;
  int local_50;
  int local_48;
  int local_40;
  int local_3c [2];
  int local_34 [2];
  int local_2c [2];
  int *local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0049780c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_f8 = (int **)((uint)local_f8 & 0xffff0000);
  local_e0 = (int **)FUN_00410330();
  *(undefined1 *)((int)local_e0 + 0x19) = 1;
  local_e0[1] = (int *)local_e0;
  *local_e0 = (int *)local_e0;
  local_e0[2] = (int *)local_e0;
  local_dc = 0;
  local_c = 0;
  local_104 = (int **)FUN_004602b0();
  *(undefined1 *)((int)local_104 + 0x29) = 1;
  local_104[1] = (int *)local_104;
  *local_104 = (int *)local_104;
  local_104[2] = (int *)local_104;
  local_100 = 0;
  local_c._0_1_ = 1;
  local_d4 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_d4 + 0x11) = 1;
  local_d4[1] = (int *)local_d4;
  *local_d4 = (int *)local_d4;
  local_d4[2] = (int *)local_d4;
  local_d0 = 0;
  local_c._0_1_ = 2;
  local_bc = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_bc + 0x11) = 1;
  local_bc[1] = (int *)local_bc;
  *local_bc = (int *)local_bc;
  local_bc[2] = (int *)local_bc;
  local_b8 = 0;
  iVar8 = *(int *)((int)this + 8);
  local_c = CONCAT31(local_c._1_3_,3);
  local_84[0] = (int *)((uint)local_84[0] & 0xffffff00);
  local_7c = (int *)((uint)local_7c._2_2_ << 0x10);
  local_70 = (int *)((uint)local_70 & 0xffffff00);
  local_115 = '\x01';
  local_cc = (int *)0x0;
  if (0 < *(int *)(iVar8 + 0x2400)) {
    do {
      piVar10 = local_cc;
      puVar16 = (undefined1 *)(iVar8 + 8 + (int)local_cc * 0x24);
      local_fc = local_cc;
      ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)&local_cc);
      *ppiVar9 = local_84[0];
      ppiVar9[1] = (int *)0xffffffff;
      ppiVar9[2] = local_7c;
      ppiVar9[3] = (int *)0x0;
      ppiVar9[4] = (int *)0x0;
      ppiVar9[5] = local_70;
      local_c8 = puVar16;
      local_c4 = (int **)**(undefined4 **)(puVar16 + 4);
      while( true ) {
        puVar7 = local_c8;
        local_a8 = *(int ***)(puVar16 + 4);
        if ((local_c8 == (undefined1 *)0x0) || (local_c8 != puVar16)) {
          FUN_0047a948();
        }
        if (local_c4 == local_a8) break;
        if (puVar7 == (undefined1 *)0x0) {
          FUN_0047a948();
        }
        if (local_c4 == *(int ***)(puVar7 + 4)) {
          FUN_0047a948();
        }
        local_f8 = (int **)CONCAT22(local_f8._2_2_,*(undefined2 *)(local_c4 + 3));
        ppiVar9 = Map_FindOrInsert_ByteRecord(local_e4,&local_fc);
        *(undefined1 *)ppiVar9 = 0;
        FUN_00401590((int *)&local_c8);
      }
      iVar8 = *(int *)((int)this + 8);
      local_cc = (int *)((int)piVar10 + 1);
    } while ((int)piVar10 + 1 < *(int *)(iVar8 + 0x2400));
  }
  local_10c = **(int **)(*(int *)((int)this + 8) + 0x2454);
  local_110 = *(int *)((int)this + 8) + 0x2450;
  while( true ) {
    iVar6 = local_10c;
    iVar15 = local_110;
    iVar8 = *(int *)(*(int *)((int)this + 8) + 0x2454);
    if ((local_110 == 0) || (local_110 != *(int *)((int)this + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar6 == iVar8) break;
    local_a8 = *(int ***)((int)param_1 + 4);
    if (iVar15 == 0) {
      FUN_0047a948();
    }
    if (iVar6 == *(int *)(iVar15 + 4)) {
      FUN_0047a948();
    }
    piVar10 = (int *)GameBoard_GetPowerRec(param_1,&local_98,(int *)(iVar6 + 0x18));
    if (((void *)*piVar10 == (void *)0x0) || ((void *)*piVar10 != param_1)) {
      FUN_0047a948();
    }
    if ((int **)piVar10[1] == local_a8) {
      if (iVar6 == *(int *)(iVar15 + 4)) {
        FUN_0047a948();
      }
      ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(iVar6 + 0x10));
      *(undefined1 *)(ppiVar9 + 5) = 1;
LAB_0044442e:
      UnitList_Advance(&local_110);
    }
    else {
      if (iVar6 == *(int *)(iVar15 + 4)) {
        FUN_0047a948();
      }
      ppiVar9 = (int **)(iVar6 + 0x10);
      ppiVar11 = Map_FindOrInsert_ByteRecord(local_e4,ppiVar9);
      *(undefined1 *)ppiVar11 = 1;
      if (iVar6 == *(int *)(iVar15 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(*(int *)((int)this + 8) + 4 + (int)*ppiVar9 * 0x24) != '\x01')
      goto LAB_0044442e;
      if (iVar6 == *(int *)(iVar15 + 4)) {
        FUN_0047a948();
      }
      local_fc = *ppiVar9;
      local_f8 = (int **)CONCAT22(local_f8._2_2_,AMY);
      ppiVar9 = Map_FindOrInsert_ByteRecord(local_e4,&local_fc);
      *(undefined1 *)ppiVar9 = 1;
      UnitList_Advance(&local_110);
    }
  }
  do {
    bVar5 = false;
    local_f0 = local_e4;
    local_ec = (int **)*local_e0;
    while( true ) {
      ppiVar11 = local_e0;
      ppiVar9 = local_ec;
      puVar16 = local_f0;
      if ((local_f0 == (undefined1 *)0x0) || (local_f0 != local_e4)) {
        FUN_0047a948();
      }
      if (ppiVar9 == ppiVar11) break;
      if (puVar16 == (undefined1 *)0x0) {
        FUN_0047a948();
      }
      if (ppiVar9 == *(int ***)(puVar16 + 4)) {
        FUN_0047a948();
      }
      ppiVar11 = Map_FindOrInsert_ByteRecord(local_e4,ppiVar9 + 3);
      if (*(char *)ppiVar11 == '\x01') {
        if ((ppiVar9 == *(int ***)(puVar16 + 4)) &&
           (FUN_0047a948(), ppiVar9 == *(int ***)(puVar16 + 4))) {
          FUN_0047a948();
        }
        local_b4 = AdjacencyList_FilterByUnitType
                             ((void *)(*(int *)((int)this + 8) + 8 + (int)ppiVar9[3] * 0x24),
                              (ushort *)(ppiVar9 + 4));
        local_b0 = (int *)*local_b4[1];
        local_a4 = local_b4;
        while( true ) {
          piVar4 = local_b0;
          ppiVar9 = local_b4;
          piVar10 = local_a4[1];
          if ((local_b4 == (int **)0x0) || (local_b4 != local_a4)) {
            FUN_0047a948();
          }
          if (piVar4 == piVar10) break;
          if (ppiVar9 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar4 == ppiVar9[1]) {
            FUN_0047a948();
          }
          ppiVar11 = (int **)(piVar4 + 3);
          ppiVar12 = Map_FindOrInsert_LargeRecord(local_108,(int *)ppiVar11);
          if (*(char *)(ppiVar12 + 5) == '\0') {
            if (piVar4 == ppiVar9[1]) {
              FUN_0047a948();
            }
            ppiVar12 = Map_FindOrInsert_ByteRecord(local_e4,ppiVar11);
            if (*(char *)ppiVar12 == '\0') {
              if (piVar4 == ppiVar9[1]) {
                FUN_0047a948();
              }
              ppiVar12 = Map_FindOrInsert_ByteRecord(local_e4,ppiVar11);
              *(undefined1 *)ppiVar12 = 1;
              if (piVar4 == ppiVar9[1]) {
                FUN_0047a948();
              }
              if (*(char *)(*(int *)((int)this + 8) + 4 + (int)*ppiVar11 * 0x24) == '\x01') {
                if (piVar4 == ppiVar9[1]) {
                  FUN_0047a948();
                }
                local_fc = *ppiVar11;
                local_f8 = (int **)CONCAT22(local_f8._2_2_,AMY);
                ppiVar9 = Map_FindOrInsert_ByteRecord(local_e4,&local_fc);
                *(undefined1 *)ppiVar9 = 1;
              }
              bVar5 = true;
            }
          }
          FUN_0040f400((int *)&local_b4);
        }
      }
      FUN_0040e680((int *)&local_f0);
    }
  } while (bVar5);
  local_f0 = local_e4;
  local_ec = (int **)*local_e0;
  while( true ) {
    ppiVar11 = local_e0;
    ppiVar9 = local_ec;
    puVar16 = local_f0;
    if ((local_f0 == (undefined1 *)0x0) || (local_f0 != local_e4)) {
      FUN_0047a948();
    }
    if (ppiVar9 == ppiVar11) break;
    if (puVar16 == (undefined1 *)0x0) {
      FUN_0047a948();
    }
    if (ppiVar9 == *(int ***)(puVar16 + 4)) {
      FUN_0047a948();
    }
    if (*(char *)(*(int *)((int)this + 8) + 3 + (int)ppiVar9[3] * 0x24) != '\0') {
      if (ppiVar9 == *(int ***)(puVar16 + 4)) {
        FUN_0047a948();
      }
      uVar3 = *(ushort *)(*(int *)((int)this + 8) + 0x20 + (int)ppiVar9[3] * 0x24);
      local_cc = (int *)(uVar3 & 0xff);
      if ((char)(uVar3 >> 8) != 'A') {
        local_cc = (int *)0x14;
      }
      local_a8 = *(int ***)((int)param_1 + 4);
      piVar10 = (int *)GameBoard_GetPowerRec(param_1,&local_98,(int *)&local_cc);
      if (((void *)*piVar10 == (void *)0x0) || ((void *)*piVar10 != param_1)) {
        FUN_0047a948();
      }
      if ((int **)piVar10[1] == local_a8) {
        if (ppiVar9 == *(int ***)(local_f0 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(ppiVar9 + 5) == '\x01') {
          local_115 = '\0';
        }
      }
    }
    FUN_0040e680((int *)&local_f0);
  }
  if (local_115 == '\x01') {
    local_f4 = (int **)0xffffffff;
    local_f0 = local_e4;
    local_ec = (int **)*local_e0;
    puVar16 = local_f0;
    while( true ) {
      ppiVar11 = local_e0;
      ppiVar9 = local_ec;
      if ((puVar16 == (undefined1 *)0x0) || (puVar16 != local_e4)) {
        FUN_0047a948();
      }
      if (ppiVar9 == ppiVar11) break;
      if (puVar16 == (undefined1 *)0x0) {
        FUN_0047a948();
      }
      if (ppiVar9 == *(int ***)(puVar16 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(ppiVar9 + 5) == '\x01') {
        if (ppiVar9 == *(int ***)(puVar16 + 4)) {
          FUN_0047a948();
        }
        if (local_f4 != (int **)ppiVar9[3]) {
          local_fc = &local_d8;
          local_f8 = (int **)*local_d4;
          while( true ) {
            ppiVar11 = local_d4;
            ppiVar9 = local_f8;
            piVar10 = local_fc;
            if ((local_fc == (int *)0x0) || (local_fc != &local_d8)) {
              FUN_0047a948();
            }
            if (ppiVar9 == ppiVar11) break;
            if (piVar10 == (int *)0x0) {
              FUN_0047a948();
            }
            if (ppiVar9 == (int **)piVar10[1]) {
              FUN_0047a948();
            }
            ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(ppiVar9 + 3));
            ppiVar9[4] = (int *)((int)ppiVar9[4] + 1);
            TreeIterator_Advance((int *)&local_fc);
          }
          cVar2 = *(char *)((int)local_d4[1] + 0x11);
          piVar10 = local_d4[1];
          ppiVar9 = local_ec;
          while (local_ec = ppiVar9, cVar2 == '\0') {
            FUN_00401950((int *)piVar10[2]);
            piVar4 = (int *)*piVar10;
            _free(piVar10);
            piVar10 = piVar4;
            ppiVar9 = local_ec;
            cVar2 = *(char *)((int)piVar4 + 0x11);
          }
          local_d4[1] = (int *)local_d4;
          local_d0 = 0;
          *local_d4 = (int *)local_d4;
          local_d4[2] = (int *)local_d4;
          if (ppiVar9 == *(int ***)(local_f0 + 4)) {
            FUN_0047a948();
          }
          local_f4 = (int **)ppiVar9[3];
          ppiVar9 = local_ec;
          puVar16 = local_f0;
        }
        if ((ppiVar9 == *(int ***)(puVar16 + 4)) &&
           (FUN_0047a948(), ppiVar9 == *(int ***)(puVar16 + 4))) {
          FUN_0047a948();
        }
        local_b4 = AdjacencyList_FilterByUnitType
                             ((void *)(*(int *)((int)this + 8) + 8 + (int)ppiVar9[3] * 0x24),
                              (ushort *)(ppiVar9 + 4));
        local_b0 = (int *)*local_b4[1];
        local_a4 = local_b4;
        while( true ) {
          piVar4 = local_b0;
          ppiVar9 = local_b4;
          piVar10 = local_a4[1];
          if ((local_b4 == (int **)0x0) || (local_b4 != local_a4)) {
            FUN_0047a948();
          }
          if (piVar4 == piVar10) break;
          if (ppiVar9 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar4 == ppiVar9[1]) {
            FUN_0047a948();
          }
          piVar10 = piVar4 + 3;
          ppiVar11 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
          if (*(char *)(ppiVar11 + 5) == '\x01') {
            if (piVar4 == ppiVar9[1]) {
              FUN_0047a948();
            }
            StdMap_FindOrInsert(&local_d8,local_90,piVar10);
            if (piVar4 == ppiVar9[1]) {
              FUN_0047a948();
            }
            ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
            ppiVar9[1] = (int *)local_f4;
          }
          FUN_0040f400((int *)&local_b4);
        }
      }
      FUN_0040e680((int *)&local_f0);
      ppiVar9 = local_e0;
      puVar16 = local_f0;
      if ((local_f0 == (undefined1 *)0x0) || (local_f0 != local_e4)) {
        FUN_0047a948();
      }
      if (local_ec == ppiVar9) {
        local_fc = &local_d8;
        local_f8 = (int **)*local_d4;
        while( true ) {
          ppiVar11 = local_d4;
          ppiVar9 = local_f8;
          piVar10 = local_fc;
          if ((local_fc == (int *)0x0) || (local_fc != &local_d8)) {
            FUN_0047a948();
          }
          puVar16 = local_f0;
          if (ppiVar9 == ppiVar11) break;
          if (piVar10 == (int *)0x0) {
            FUN_0047a948();
          }
          if (ppiVar9 == (int **)piVar10[1]) {
            FUN_0047a948();
          }
          ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(ppiVar9 + 3));
          ppiVar9[4] = (int *)((int)ppiVar9[4] + 1);
          TreeIterator_Advance((int *)&local_fc);
        }
      }
    }
    local_10c = **(int **)(*(int *)((int)this + 8) + 0x2454);
    local_110 = *(int *)((int)this + 8) + 0x2450;
    while( true ) {
      iVar6 = local_10c;
      iVar15 = local_110;
      iVar8 = *(int *)(*(int *)((int)this + 8) + 0x2454);
      if ((local_110 == 0) || (local_110 != *(int *)((int)this + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (iVar6 == iVar8) break;
      local_a8 = *(int ***)((int)param_1 + 4);
      if (iVar15 == 0) {
        FUN_0047a948();
      }
      if (iVar6 == *(int *)(iVar15 + 4)) {
        FUN_0047a948();
      }
      piVar10 = (int *)GameBoard_GetPowerRec(param_1,&local_98,(int *)(iVar6 + 0x18));
      if (((void *)*piVar10 == (void *)0x0) || ((void *)*piVar10 != param_1)) {
        FUN_0047a948();
      }
      if ((int **)piVar10[1] == local_a8) {
        if (iVar6 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        piVar10 = (int *)(iVar6 + 0x10);
        ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
        if (1 < (int)ppiVar9[4]) {
          if (iVar6 == *(int *)(iVar15 + 4)) {
            FUN_0047a948();
          }
          ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
          ppiVar9[1] = (int *)0xffffffff;
          goto LAB_00444aba;
        }
        if (iVar6 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
        *(undefined1 *)ppiVar9 = 1;
        if (iVar6 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
        *(undefined1 *)((int)ppiVar9 + 9) = 1;
        UnitList_Advance(&local_110);
      }
      else {
LAB_00444aba:
        UnitList_Advance(&local_110);
      }
    }
    do {
      if (local_115 != '\x01') goto LAB_0044547a;
      local_f0 = (undefined1 *)0x0;
      do {
        local_f0 = local_f0 + 1;
        local_10c = **(int **)(*(int *)((int)this + 8) + 0x2454);
        local_110 = *(int *)((int)this + 8) + 0x2450;
        bVar5 = false;
        while( true ) {
          iVar15 = local_10c;
          iVar8 = local_110;
          local_68 = *(int *)(*(int *)((int)this + 8) + 0x2454);
          if ((local_110 == 0) || (local_110 != *(int *)((int)this + 8) + 0x2450)) {
            FUN_0047a948();
          }
          if (iVar15 == local_68) break;
          local_48 = *(int *)((int)param_1 + 4);
          if (iVar8 == 0) {
            FUN_0047a948();
          }
          if (iVar15 == *(int *)(iVar8 + 4)) {
            FUN_0047a948();
          }
          piVar10 = (int *)GameBoard_GetPowerRec(param_1,local_34,(int *)(iVar15 + 0x18));
          if (((void *)*piVar10 == (void *)0x0) || ((void *)*piVar10 != param_1)) {
            FUN_0047a948();
          }
          if (piVar10[1] == local_48) {
            if (iVar15 == *(int *)(iVar8 + 4)) {
              FUN_0047a948();
            }
            piVar10 = (int *)(iVar15 + 0x10);
            local_a0 = piVar10;
            ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
            if (*(char *)ppiVar9 == '\x01') {
              if (iVar15 == *(int *)(iVar8 + 4)) {
                FUN_0047a948();
              }
              ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
              if (*(char *)(ppiVar9 + 2) == '\0') {
                if ((iVar15 == *(int *)(iVar8 + 4)) &&
                   (FUN_0047a948(), iVar15 == *(int *)(iVar8 + 4))) {
                  FUN_0047a948();
                }
                local_a4 = AdjacencyList_FilterByUnitType
                                     ((void *)(*(int *)((int)this + 8) + 8 + *local_a0 * 0x24),
                                      (ushort *)(iVar15 + 0x14));
                local_f4 = (int **)0xffffffff;
                local_e8 = 0;
                local_b4 = local_a4;
                local_b0 = (int *)*local_a4[1];
                while( true ) {
                  piVar10 = local_b0;
                  ppiVar9 = local_b4;
                  local_58 = local_a4[1];
                  if ((local_b4 == (int **)0x0) || (local_b4 != local_a4)) {
                    FUN_0047a948();
                  }
                  if (piVar10 == local_58) break;
                  if (ppiVar9 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (piVar10 == ppiVar9[1]) {
                    FUN_0047a948();
                  }
                  local_9c = piVar10 + 3;
                  ppiVar11 = Map_FindOrInsert_LargeRecord(local_108,local_9c);
                  if (*(char *)(ppiVar11 + 5) == '\x01') {
                    if (piVar10 == ppiVar9[1]) {
                      FUN_0047a948();
                    }
                    ppiVar11 = Map_FindOrInsert_LargeRecord(local_108,local_9c);
                    if (*(char *)((int)ppiVar11 + 9) == '\0') {
                      if (piVar10 == ppiVar9[1]) {
                        FUN_0047a948();
                      }
                      if (local_f4 != (int **)*local_9c) {
                        if (iVar15 == *(int *)(local_110 + 4)) {
                          FUN_0047a948();
                        }
                        ppiVar11 = Map_FindOrInsert_LargeRecord(local_108,local_a0);
                        if (ppiVar11[1] == (int *)0xffffffff) {
                          local_e8 = local_e8 + 1;
                          if (piVar10 == ppiVar9[1]) {
                            FUN_0047a948();
                          }
                          local_f4 = (int **)*local_9c;
                        }
                        else {
                          if (iVar15 == *(int *)(local_110 + 4)) {
                            FUN_0047a948();
                          }
                          ppiVar11 = Map_FindOrInsert_LargeRecord(local_108,local_a0);
                          piVar4 = ppiVar11[1];
                          if (piVar10 == ppiVar9[1]) {
                            FUN_0047a948();
                          }
                          local_cc = (int *)*local_9c;
                          pvVar1 = (void *)((int)this + (int)piVar4 * 0xc + 0x2a1c);
                          local_50 = *(int *)((int)pvVar1 + 4);
                          puVar13 = (undefined4 *)
                                    GameBoard_GetPowerRec(pvVar1,local_3c,(int *)&local_cc);
                          if (((void *)*puVar13 == (void *)0x0) || ((void *)*puVar13 != pvVar1)) {
                            FUN_0047a948();
                          }
                          if (puVar13[1] != local_50) {
                            local_e8 = local_e8 + 1;
                            if (local_b0 == ppiVar9[1]) {
                              FUN_0047a948();
                            }
                            local_f4 = (int **)*local_9c;
                          }
                        }
                      }
                    }
                  }
                  FUN_0040f400((int *)&local_b4);
                  iVar15 = local_10c;
                }
                if (local_e8 == 0) {
                  if (iVar15 == *(int *)(local_110 + 4)) {
                    FUN_0047a948();
                  }
                  ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,local_a0);
                  *(undefined1 *)(ppiVar9 + 2) = 1;
                }
                else {
                  if (local_e8 != 1) goto LAB_00444e42;
                  if (iVar15 == *(int *)(local_110 + 4)) {
                    FUN_0047a948();
                  }
                  ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,local_a0);
                  *(undefined1 *)(ppiVar9 + 2) = 1;
                  ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)&local_f4);
                  ppiVar9[3] = (int *)((int)ppiVar9[3] + 1);
                }
                bVar5 = true;
              }
            }
          }
LAB_00444e42:
          local_c8 = local_108;
          local_c4 = (int **)*local_104;
          while( true ) {
            ppiVar11 = local_c4;
            puVar16 = local_c8;
            ppiVar9 = local_104;
            if ((local_c8 == (undefined1 *)0x0) || (local_c8 != local_108)) {
              FUN_0047a948();
            }
            if (ppiVar11 == ppiVar9) break;
            if (puVar16 == (undefined1 *)0x0) {
              FUN_0047a948();
            }
            if (ppiVar11 == *(int ***)(puVar16 + 4)) {
              FUN_0047a948();
            }
            if (*(char *)(ppiVar11 + 9) == '\x01') {
              if ((ppiVar11 == *(int ***)(puVar16 + 4)) &&
                 (FUN_0047a948(), ppiVar11 == *(int ***)(puVar16 + 4))) {
                FUN_0047a948();
              }
              if ((int)ppiVar11[8] + -1 <= (int)ppiVar11[7]) {
                if (ppiVar11 == *(int ***)(puVar16 + 4)) {
                  FUN_0047a948();
                }
                *(undefined1 *)((int)ppiVar11 + 0x19) = 1;
              }
            }
            FUN_0040e210((int *)&local_c8);
          }
          UnitList_Advance(&local_110);
        }
      } while (bVar5);
      do {
        local_f0 = local_f0 + 1;
        local_10c = **(int **)(*(int *)((int)this + 8) + 0x2454);
        local_110 = *(int *)((int)this + 8) + 0x2450;
        bVar5 = false;
        while( true ) {
          iVar15 = local_10c;
          iVar8 = local_110;
          local_60 = *(int *)(*(int *)((int)this + 8) + 0x2454);
          if ((local_110 == 0) || (local_110 != *(int *)((int)this + 8) + 0x2450)) {
            FUN_0047a948();
          }
          if (iVar15 == local_60) break;
          local_40 = *(int *)((int)param_1 + 4);
          if (iVar8 == 0) {
            FUN_0047a948();
          }
          if (iVar15 == *(int *)(iVar8 + 4)) {
            FUN_0047a948();
          }
          piVar10 = (int *)GameBoard_GetPowerRec(param_1,local_2c,(int *)(iVar15 + 0x18));
          if (((void *)*piVar10 == (void *)0x0) || ((void *)*piVar10 != param_1)) {
            FUN_0047a948();
          }
          iVar8 = local_10c;
          if (piVar10[1] == local_40) {
            if (local_10c == *(int *)(local_110 + 4)) {
              FUN_0047a948();
            }
            ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(iVar8 + 0x10));
            if (*(char *)((int)ppiVar9 + 9) == '\0') {
              cVar2 = *(char *)((int)local_bc[1] + 0x11);
              local_e8 = 0;
              piVar10 = local_bc[1];
              while (cVar2 == '\0') {
                FUN_00401950((int *)piVar10[2]);
                piVar4 = (int *)*piVar10;
                _free(piVar10);
                piVar10 = piVar4;
                cVar2 = *(char *)((int)piVar4 + 0x11);
              }
              local_bc[1] = (int *)local_bc;
              local_b8 = 0;
              *local_bc = (int *)local_bc;
              local_bc[2] = (int *)local_bc;
              if (local_10c == *(int *)(local_110 + 4)) {
                FUN_0047a948();
              }
              local_fc = (int *)((int)this + *(int *)(local_10c + 0x10) * 0xc + 0x2a1c);
              local_f8 = (int **)**(undefined4 **)
                                   ((int)this + *(int *)(local_10c + 0x10) * 0xc + 0x2a20);
              while( true ) {
                piVar10 = local_fc;
                iVar8 = local_10c;
                if (local_10c == *(int *)(local_110 + 4)) {
                  FUN_0047a948();
                }
                ppiVar9 = *(int ***)((int)this + *(int *)(iVar8 + 0x10) * 0xc + 0x2a20);
                if ((piVar10 == (int *)0x0) ||
                   (piVar10 != (int *)((int)this + *(int *)(iVar8 + 0x10) * 0xc + 0x2a1c))) {
                  FUN_0047a948();
                }
                if (local_f8 == ppiVar9) break;
                if (piVar10 == (int *)0x0) {
                  FUN_0047a948();
                }
                if (local_f8 == (int **)piVar10[1]) {
                  FUN_0047a948();
                }
                local_f4 = local_f8 + 3;
                ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)local_f4);
                if (*(char *)(ppiVar9 + 5) == '\x01') {
                  if (local_f8 == (int **)piVar10[1]) {
                    FUN_0047a948();
                  }
                  ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)local_f4);
                  if (*(char *)ppiVar9 == '\x01') {
                    if (local_f8 == (int **)piVar10[1]) {
                      FUN_0047a948();
                    }
                    ppiVar11 = Map_FindOrInsert_LargeRecord(local_108,(int *)local_f4);
                    ppiVar9 = local_f8;
                    if (*(char *)(ppiVar11 + 2) == '\0') {
                      if (local_f8 == (int **)piVar10[1]) {
                        FUN_0047a948();
                      }
                      ppiVar11 = local_f4;
                      ppiVar12 = Map_FindOrInsert_LargeRecord(local_108,(int *)local_f4);
                      if (ppiVar12[1] == (int *)0xffffffff) {
                        if (ppiVar9 == (int **)piVar10[1]) {
                          FUN_0047a948();
                        }
                        ppiVar9 = UnitList_FindOrInsert
                                            ((void *)(*(int *)((int)this + 8) + 0x2450),
                                             (int *)ppiVar11);
                        iVar8 = local_10c;
                        if (local_10c == *(int *)(local_110 + 4)) {
                          FUN_0047a948();
                        }
                        uVar14 = IsLegalMove(*(void **)((int)this + 8),(int *)ppiVar9,
                                             *(int *)(iVar8 + 0x10));
                        if ((char)uVar14 == '\x01') {
                          local_e8 = local_e8 + 1;
                          if (local_f8 == (int **)piVar10[1]) {
                            FUN_0047a948();
                          }
                          ppiVar9 = local_24;
LAB_0044528d:
                          StdMap_FindOrInsert(local_c0,ppiVar9,(int *)local_f4);
                        }
                      }
                      else {
                        if (ppiVar9 == (int **)piVar10[1]) {
                          FUN_0047a948();
                        }
                        ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)ppiVar11);
                        piVar4 = ppiVar9[1];
                        if (local_10c == *(int *)(local_110 + 4)) {
                          FUN_0047a948();
                        }
                        local_cc = *(int **)(local_10c + 0x10);
                        pvVar1 = (void *)((int)this + (int)piVar4 * 0xc + 0x2a1c);
                        local_94 = *(int *)((int)pvVar1 + 4);
                        puVar13 = (undefined4 *)
                                  GameBoard_GetPowerRec(pvVar1,(int *)local_90,(int *)&local_cc);
                        if (((void *)*puVar13 == (void *)0x0) || ((void *)*puVar13 != pvVar1)) {
                          FUN_0047a948();
                        }
                        if (puVar13[1] != local_94) {
                          if (local_f8 == (int **)piVar10[1]) {
                            FUN_0047a948();
                          }
                          ppiVar9 = UnitList_FindOrInsert
                                              ((void *)(*(int *)((int)this + 8) + 0x2450),
                                               (int *)local_f4);
                          iVar8 = local_10c;
                          if (local_10c == *(int *)(local_110 + 4)) {
                            FUN_0047a948();
                          }
                          uVar14 = IsLegalMove(*(void **)((int)this + 8),(int *)ppiVar9,
                                               *(int *)(iVar8 + 0x10));
                          if ((char)uVar14 == '\x01') {
                            local_e8 = local_e8 + 1;
                            if (local_f8 == (int **)piVar10[1]) {
                              FUN_0047a948();
                            }
                            ppiVar9 = local_84;
                            goto LAB_0044528d;
                          }
                        }
                      }
                    }
                  }
                }
                TreeIterator_Advance((int *)&local_fc);
              }
              if (iVar8 == *(int *)(local_110 + 4)) {
                FUN_0047a948();
              }
              if (iVar8 == *(int *)(local_110 + 4)) {
                FUN_0047a948();
              }
              ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(iVar8 + 0x10));
              piVar4 = ppiVar9[4];
              piVar10 = (int *)(iVar8 + 0x10);
              ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
              iVar15 = local_110;
              if ((int)piVar4 + (-local_e8 - (int)ppiVar9[3]) < 2) {
                if ((iVar8 == *(int *)(local_110 + 4)) &&
                   (FUN_0047a948(), iVar8 == *(int *)(iVar15 + 4))) {
                  FUN_0047a948();
                }
                ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(iVar8 + 0x10));
                piVar4 = ppiVar9[4];
                ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
                if ((int)piVar4 + (-local_e8 - (int)ppiVar9[3]) == 1) {
                  bVar5 = true;
                  if (iVar8 == *(int *)(local_110 + 4)) {
                    FUN_0047a948();
                  }
                  ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,piVar10);
                  *(undefined1 *)((int)ppiVar9 + 9) = 1;
                  local_ac = local_c0;
                  local_a8 = (int **)*local_bc;
                  while( true ) {
                    ppiVar11 = local_a8;
                    puVar16 = local_ac;
                    ppiVar9 = local_bc;
                    if ((local_ac == (undefined1 *)0x0) || (local_ac != local_c0)) {
                      FUN_0047a948();
                    }
                    if (ppiVar11 == ppiVar9) break;
                    if (puVar16 == (undefined1 *)0x0) {
                      FUN_0047a948();
                    }
                    if (ppiVar11 == *(int ***)(puVar16 + 4)) {
                      FUN_0047a948();
                    }
                    ppiVar9 = Map_FindOrInsert_LargeRecord(local_108,(int *)(ppiVar11 + 3));
                    *(undefined1 *)(ppiVar9 + 2) = 1;
                    TreeIterator_Advance((int *)&local_ac);
                  }
                }
              }
              else {
                local_115 = '\0';
              }
            }
          }
          UnitList_Advance(&local_110);
        }
      } while ((bVar5) && (local_115 == '\x01'));
    } while (2 < (int)local_f0);
    if (local_115 == '\x01') {
      local_c8 = local_108;
      local_c4 = (int **)*local_104;
      while( true ) {
        ppiVar11 = local_c4;
        puVar16 = local_c8;
        ppiVar9 = local_104;
        if ((local_c8 == (undefined1 *)0x0) || (local_c8 != local_108)) {
          FUN_0047a948();
        }
        if (ppiVar11 == ppiVar9) break;
        if (puVar16 == (undefined1 *)0x0) {
          FUN_0047a948();
        }
        if (ppiVar11 == *(int ***)(puVar16 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(ppiVar11 + 9) == '\x01') {
          if (ppiVar11 == *(int ***)(puVar16 + 4)) {
            FUN_0047a948();
          }
          if (*(char *)((int)ppiVar11 + 0x19) == '\0') {
            local_115 = '\0';
          }
        }
        FUN_0040e210((int *)&local_c8);
      }
    }
  }
LAB_0044547a:
  local_c._0_1_ = 2;
  SerializeOrders(local_c0,local_90,local_c0,(int **)*local_bc,local_c0,local_bc);
  _free(local_bc);
  local_bc = (int **)0x0;
  local_b8 = 0;
  local_c._0_1_ = 1;
  SerializeOrders(&local_d8,local_90,&local_d8,(int **)*local_d4,&local_d8,local_d4);
  _free(local_d4);
  local_d4 = (int **)0x0;
  local_d0 = 0;
  local_c = (uint)local_c._1_3_ << 8;
  Container_Destroy_TypeB(local_108,local_90,local_108,(int **)*local_104,local_108,local_104);
  _free(local_104);
  local_104 = (int **)0x0;
  local_100 = 0;
  local_c = 0xffffffff;
  Container_Destroy_TypeA(local_e4,local_90,local_e4,(int **)*local_e0,local_e4,local_e0);
  _free(local_e0);
  ExceptionList = local_14;
  return local_115;
}

