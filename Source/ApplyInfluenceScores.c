
void __fastcall ApplyInfluenceScores(int param_1)

{
  uint *puVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int **ppiVar8;
  undefined4 *puVar9;
  int extraout_ECX;
  int iVar10;
  undefined4 extraout_EDX;
  undefined4 uVar11;
  undefined4 extraout_EDX_00;
  int **ppiVar12;
  undefined4 *puVar13;
  uint uVar14;
  int iVar15;
  int **ppiVar16;
  void *pvVar17;
  uint uVar18;
  uint *puVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  float10 fVar23;
  undefined8 uVar24;
  longlong lVar25;
  ulonglong uVar26;
  int **local_c8;
  int **local_c4;
  uint *local_c0;
  int *local_bc;
  int **local_b8;
  int *piStack_b4;
  int **local_ac;
  int *local_a8;
  int *piStack_a4;
  int **local_a0;
  int *local_9c;
  undefined8 local_98;
  undefined8 local_90;
  int **local_84;
  undefined8 local_80;
  undefined8 local_78;
  int **local_6c;
  undefined8 local_68;
  undefined8 local_60;
  uint local_54;
  uint local_48;
  int local_44;
  uint local_40;
  int **local_3c;
  uint *local_38;
  uint local_34;
  int local_30 [2];
  int local_28 [2];
  undefined4 local_20 [3];
  undefined4 local_14 [4];
  
  iVar10 = *(int *)(param_1 + 8);
  local_6c = (int **)(uint)*(byte *)(iVar10 + 0x2424);
  local_78._0_6_ = ZEXT46((int *)local_78);
  local_c4 = (int **)0x0;
  if (0 < *(int *)(iVar10 + 0x2404)) {
    do {
      local_c0 = (uint *)0x0;
      if (0 < *(int *)(iVar10 + 0x2400)) {
        local_c8 = (int **)0x0;
        iVar15 = (int)local_c4 << 0xb;
        do {
          iVar10 = iVar10 + 8 + (int)local_c8;
          *(undefined4 *)((int)&g_HeatScore + iVar15) = 0;
          *(undefined4 *)((int)&g_AttackHistory + iVar15) = 0;
          *(undefined4 *)((int)&DAT_004d62f4 + iVar15) = 0;
          *(undefined4 *)((int)&DAT_005a48ec + iVar15) = 0;
          local_78 = (double)CONCAT44(local_78._4_4_,local_c0);
          local_80 = (double)CONCAT44(**(int **)(iVar10 + 4),iVar10);
          iVar20 = iVar10;
          iVar22 = **(int **)(iVar10 + 4);
          while( true ) {
            local_60 = (double)CONCAT44(*(undefined4 *)(iVar10 + 4),(undefined4)local_60);
            if ((iVar20 == 0) || (iVar20 != iVar10)) {
              FUN_0047a948();
            }
            if (iVar22 == local_60._4_4_) break;
            if (iVar20 == 0) {
              FUN_0047a948();
            }
            if (iVar22 == *(int *)(iVar20 + 4)) {
              FUN_0047a948();
            }
            local_78._0_6_ = CONCAT24(*(undefined2 *)(iVar22 + 0xc),(int *)local_78);
            pvVar17 = (void *)(param_1 + 0x361c + (int)local_c4 * 0x78);
            iVar20 = 6;
            do {
              ppiVar8 = OrderedSet_FindOrInsert(pvVar17,(int **)&local_78);
              pvVar17 = (void *)((int)pvVar17 + 0xc);
              iVar20 = iVar20 + -1;
              *ppiVar8 = (int *)0x0;
              ppiVar8[1] = (int *)0x0;
            } while (iVar20 != 0);
            FUN_00401590((int *)&local_80);
            iVar20 = (int)local_80;
            iVar22 = local_80._4_4_;
          }
          iVar10 = *(int *)(param_1 + 8);
          local_c8 = local_c8 + 9;
          local_c0 = (uint *)((int)local_c0 + 1);
          iVar15 = iVar15 + 8;
        } while ((int)local_c0 < *(int *)(iVar10 + 0x2400));
      }
      iVar10 = **(int **)(*(int *)(param_1 + 8) + 0x2454);
      iVar15 = *(int *)(param_1 + 8) + 0x2450;
      local_90 = (double)CONCAT44(iVar10,iVar15);
      while( true ) {
        iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
        if ((iVar15 == 0) || (iVar15 != *(int *)(param_1 + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar10 == iVar20) break;
        if (iVar15 == 0) {
          FUN_0047a948();
        }
        if (iVar10 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if (*(int ***)(iVar10 + 0x18) == local_c4) {
          if (iVar10 == *(int *)(iVar15 + 4)) {
            FUN_0047a948();
          }
          ppiVar8 = OrderedSet_FindOrInsert
                              ((void *)(param_1 + 0x361c + (int)local_c4 * 0x78),
                               (int **)(iVar10 + 0x10));
          *ppiVar8 = (int *)0x1388;
          ppiVar8[1] = (int *)0x0;
        }
        UnitList_Advance((int *)&local_90);
        iVar15 = (int)local_90;
        iVar10 = local_90._4_4_;
      }
      local_ac = (int **)(param_1 + (int)local_c4 * 0x78);
      local_c8 = local_ac + 0xd8a;
      local_c0 = (uint *)0x5;
      do {
        piStack_b4 = (int *)*local_c8[1];
        local_b8 = local_c8;
        while( true ) {
          piVar4 = piStack_b4;
          ppiVar16 = local_b8;
          ppiVar8 = local_c8;
          piVar21 = local_c8[1];
          if ((local_b8 == (int **)0x0) || (local_b8 != local_c8)) {
            FUN_0047a948();
          }
          ppiVar12 = local_ac;
          if (piVar4 == piVar21) break;
          if (ppiVar16 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar4 == ppiVar16[1]) {
            FUN_0047a948();
          }
          if (piVar4 == ppiVar16[1]) {
            FUN_0047a948();
          }
          local_a0 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)(param_1 + 8) + 8 + (int)piVar4[4] * 0x24),
                                (ushort *)(piVar4 + 5));
          local_9c = (int *)*local_a0[1];
          local_bc = (int *)0xffffffff;
          local_84 = local_a0;
          while( true ) {
            ppiVar8 = local_a0;
            local_68 = (double)CONCAT44(local_84[1],(undefined4)local_68);
            if ((local_a0 == (int **)0x0) || (local_a0 != local_84)) {
              FUN_0047a948();
            }
            if (local_9c == local_68._4_4_) break;
            if (ppiVar8 == (int **)0x0) {
              FUN_0047a948();
            }
            if (local_9c == ppiVar8[1]) {
              FUN_0047a948();
            }
            ppiVar16 = (int **)(local_9c + 3);
            if ((int *)local_9c[3] == local_bc) {
              if (local_9c == ppiVar8[1]) {
                FUN_0047a948();
              }
              ppiVar12 = local_c8 + -3;
              ppiVar8 = OrderedSet_FindOrInsert(ppiVar12,ppiVar16);
              if (((int)piStack_a4 <= (int)ppiVar8[1]) &&
                 (((int)piStack_a4 < (int)ppiVar8[1] || (local_a8 < *ppiVar8)))) {
                if (piVar4 == local_b8[1]) {
                  FUN_0047a948();
                }
                if (piVar4 == local_b8[1]) {
                  FUN_0047a948();
                }
                piVar21 = (int *)piVar4[6];
                piVar4[6] = (int)piVar21 - (int)local_a8;
                piVar4[7] = (piVar4[7] - (int)piStack_a4) - (uint)(piVar21 < local_a8);
                if (local_9c == local_a0[1]) {
                  FUN_0047a948();
                }
                ppiVar8 = OrderedSet_FindOrInsert(ppiVar12,ppiVar16);
                local_a8 = *ppiVar8;
                piStack_a4 = ppiVar8[1];
                if (piVar4 == local_b8[1]) {
                  FUN_0047a948();
                }
                if (piVar4 == local_b8[1]) {
                  FUN_0047a948();
                }
                uVar14 = piVar4[6];
                piVar4[6] = uVar14 + (int)local_a8;
                piVar4[7] = (int)piStack_a4 + (uint)CARRY4(uVar14,(uint)local_a8) + piVar4[7];
              }
            }
            else {
              if (local_9c == ppiVar8[1]) {
                FUN_0047a948();
              }
              ppiVar8 = OrderedSet_FindOrInsert(local_c8 + -3,ppiVar16);
              piVar21 = *ppiVar8;
              piStack_a4 = ppiVar8[1];
              local_a8 = piVar21;
              if (piVar4 == local_b8[1]) {
                FUN_0047a948();
              }
              if (piVar4 == local_b8[1]) {
                FUN_0047a948();
              }
              uVar14 = piVar4[6];
              piVar4[6] = uVar14 + (int)piVar21;
              piVar4[7] = (int)piStack_a4 + (uint)CARRY4(uVar14,(uint)piVar21) + piVar4[7];
            }
            if (local_9c == local_a0[1]) {
              FUN_0047a948();
            }
            local_bc = *ppiVar16;
            FUN_0040f400((int *)&local_a0);
            ppiVar16 = local_b8;
          }
          if (((piVar4 == ppiVar16[1]) && (FUN_0047a948(), piVar4 == ppiVar16[1])) &&
             (FUN_0047a948(), piVar4 == ppiVar16[1])) {
            FUN_0047a948();
          }
          ppiVar8 = OrderedSet_FindOrInsert(local_c8 + -3,(int **)(piVar4 + 4));
          uVar14 = piVar4[6];
          piVar21 = *ppiVar8;
          piVar3 = ppiVar8[1];
          piVar4[6] = uVar14 + (int)*ppiVar8;
          piVar4[7] = (int)piVar3 + (uint)CARRY4(uVar14,(uint)piVar21) + piVar4[7];
          if ((piVar4 == ppiVar16[1]) && (FUN_0047a948(), piVar4 == ppiVar16[1])) {
            FUN_0047a948();
          }
          uVar24 = __alldiv(piVar4[6],piVar4[7],5,0);
          *(undefined8 *)(piVar4 + 6) = uVar24;
          std_Tree_IteratorIncrement((int *)&local_b8);
        }
        local_c8 = ppiVar8 + 3;
        local_c0 = (uint *)((int)local_c0 + -1);
      } while (local_c0 != (uint *)0x0);
      ppiVar16 = local_ac + 0xd87;
      local_98 = (double)CONCAT44((int *)*local_ac[0xd88],ppiVar16);
      local_c0 = (uint *)0x0;
      piVar21 = (int *)*local_ac[0xd88];
      ppiVar8 = ppiVar16;
      while( true ) {
        piVar4 = ppiVar12[0xd88];
        if ((ppiVar8 == (int **)0x0) || (ppiVar8 != ppiVar16)) {
          FUN_0047a948();
        }
        if (piVar21 == piVar4) break;
        if (ppiVar8 == (int **)0x0) {
          FUN_0047a948();
        }
        if (piVar21 == ppiVar8[1]) {
          FUN_0047a948();
        }
        local_78 = *(double *)(piVar21 + 4);
        if (piVar21 == ppiVar8[1]) {
          FUN_0047a948();
        }
        iVar10 = (int)local_c4 * 0x100 + piVar21[4];
        puVar19 = &g_HeatScore + iVar10 * 2;
        ppiVar8 = OrderedSet_FindOrInsert(local_ac + 0xd8d,(int **)&local_78);
        piVar21 = *ppiVar8;
        uVar14 = *puVar19;
        *puVar19 = *puVar19 + (int)piVar21;
        (&DAT_004d62f4)[iVar10 * 2] =
             (int)ppiVar8[1] + (uint)CARRY4(uVar14,(uint)piVar21) + (&DAT_004d62f4)[iVar10 * 2];
        std_Tree_IteratorIncrement((int *)&local_98);
        piVar21 = local_98._4_4_;
        ppiVar8 = (int **)local_98;
      }
      iVar10 = *(int *)(param_1 + 8);
      local_c4 = (int **)((int)local_c4 + 1);
    } while ((int)local_c4 < *(int *)(iVar10 + 0x2404));
  }
  iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar15 = 0;
  if (0 < iVar10) {
    puVar13 = &g_AllyRankingAux;
    do {
      iVar20 = 0;
      puVar9 = puVar13;
      if (0 < iVar10) {
        do {
          puVar9[-0x15] = 0;
          *puVar9 = 0;
          puVar9[0x15] = 0;
          iVar20 = iVar20 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar20 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar15 = iVar15 + 1;
      puVar13 = puVar13 + 0x3f;
    } while (iVar15 < iVar10);
  }
  iVar10 = *(int *)(param_1 + 8);
  local_c8 = (int **)0x0;
  if (0 < *(int *)(iVar10 + 0x2404)) {
    local_c4 = (int **)0x0;
    do {
      iVar15 = 0;
      if (0 < *(int *)(iVar10 + 0x2400)) {
        local_bc = (int *)0x0;
        local_c0 = &g_HeatScore;
        do {
          if (((*(char *)((int)local_bc + iVar10 + 3) != '\0') &&
              (uVar2 = *(ushort *)((int)local_bc + iVar10 + 0x20), (char)(uVar2 >> 8) == 'A')) &&
             (ppiVar8 = (int **)(uVar2 & 0xff), ppiVar8 != (int **)0x14)) {
            if (ppiVar8 == local_c8) {
              local_ac = *(int ***)(iVar10 + 0x2404);
              ppiVar16 = (int **)0x0;
              local_b8 = (int **)0x0;
              piStack_b4 = (int *)0x0;
              puVar19 = local_c0;
              if (0 < (int)local_ac) {
                do {
                  if (ppiVar16 != local_c8) {
                    piVar21 = (int *)puVar19[1];
                    if (((int)piStack_b4 <= (int)piVar21) &&
                       (((int)piStack_b4 < (int)piVar21 || (local_b8 < (int **)*puVar19)))) {
                      local_b8 = (int **)*puVar19;
                      piStack_b4 = piVar21;
                    }
                  }
                  ppiVar16 = (int **)((int)ppiVar16 + 1);
                  puVar19 = puVar19 + 0x200;
                } while ((int)ppiVar16 < (int)local_ac);
              }
              iVar10 = (int)ppiVar8 * 0x100 + iVar15;
              local_98 = (double)CONCAT44((&DAT_004d62f4)[iVar10 * 2] +
                                          (uint)(0xfffffffe < (uint)(&g_HeatScore)[iVar10 * 2]),
                                          (&g_HeatScore)[iVar10 * 2] + 1);
              *(double *)(&DAT_00b76a28 + ((int)local_c4 + iVar15) * 8) =
                   (double)CONCAT44(piStack_b4,local_b8) / (double)(longlong)local_98;
            }
            else {
              iVar10 = (int)ppiVar8 * 0x100 + iVar15;
              local_80 = (double)CONCAT44((&DAT_004d62f4)[iVar10 * 2] +
                                          (uint)(0xfffffffe < (uint)(&g_HeatScore)[iVar10 * 2]),
                                          (&g_HeatScore)[iVar10 * 2] + 1);
              *(double *)(&DAT_00b76a28 + ((int)local_c4 + iVar15) * 8) =
                   (double)*(longlong *)(&g_HeatScore + ((int)local_c4 + iVar15) * 2) /
                   (double)(longlong)local_80;
            }
          }
          iVar10 = *(int *)(param_1 + 8);
          local_c0 = local_c0 + 2;
          iVar15 = iVar15 + 1;
          local_bc = local_bc + 9;
        } while (iVar15 < *(int *)(iVar10 + 0x2400));
      }
      iVar10 = *(int *)(param_1 + 8);
      local_c8 = (int **)((int)local_c8 + 1);
      local_c4 = local_c4 + 0x40;
    } while ((int)local_c8 < *(int *)(iVar10 + 0x2404));
  }
  iVar10 = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  iVar15 = *(int *)(param_1 + 8) + 0x2450;
  local_90 = (double)CONCAT44(iVar10,iVar15);
  while( true ) {
    iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((iVar15 == 0) || (iVar15 != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar10 == iVar20) break;
    if (iVar15 == 0) {
      FUN_0047a948();
    }
    if ((iVar10 == *(int *)(iVar15 + 4)) && (FUN_0047a948(), iVar10 == *(int *)(iVar15 + 4))) {
      FUN_0047a948();
    }
    ppiVar8 = AdjacencyList_FilterByUnitType
                        ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar10 + 0x10) * 0x24),
                         (ushort *)(iVar10 + 0x14));
    local_9c = (int *)*ppiVar8[1];
    local_a0 = ppiVar8;
    while( true ) {
      piVar21 = local_9c;
      ppiVar16 = local_a0;
      local_68 = (double)CONCAT44(ppiVar8[1],(undefined4)local_68);
      if ((local_a0 == (int **)0x0) || (local_a0 != ppiVar8)) {
        FUN_0047a948();
      }
      if (piVar21 == local_68._4_4_) break;
      if (iVar10 == *(int *)((int)local_90 + 4)) {
        FUN_0047a948();
      }
      if (ppiVar16 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar21 == ppiVar16[1]) {
        FUN_0047a948();
      }
      iVar15 = *(int *)(iVar10 + 0x18) * 0x100 + piVar21[3];
      puVar19 = &g_UnitAdjacencyCount + iVar15 * 2;
      uVar14 = *puVar19;
      *puVar19 = *puVar19 + 1;
      (&DAT_004e1af4)[iVar15 * 2] = (&DAT_004e1af4)[iVar15 * 2] + (uint)(0xfffffffe < uVar14);
      FUN_0040f400((int *)&local_a0);
    }
    if (iVar10 == *(int *)((int)local_90 + 4)) {
      FUN_0047a948();
    }
    if (iVar10 == *(int *)((int)local_90 + 4)) {
      FUN_0047a948();
    }
    iVar10 = *(int *)(iVar10 + 0x18) * 0x100 + *(int *)(iVar10 + 0x10);
    puVar19 = &g_UnitAdjacencyCount + iVar10 * 2;
    uVar14 = *puVar19;
    *puVar19 = *puVar19 + 1;
    (&DAT_004e1af4)[iVar10 * 2] = (&DAT_004e1af4)[iVar10 * 2] + (uint)(0xfffffffe < uVar14);
    UnitList_Advance((int *)&local_90);
    iVar10 = local_90._4_4_;
    iVar15 = (int)local_90;
  }
  iVar10 = *(int *)(param_1 + 8);
  local_c4 = (int **)0x0;
  if (0 < *(int *)(iVar10 + 0x2404)) {
    local_c8 = (int **)0x0;
    do {
      ppiVar8 = *(int ***)(iVar10 + 0x2400);
      uVar14 = 0;
      uVar18 = 0;
      iVar10 = 0;
      local_98 = (double)((ulonglong)local_98 & 0xffffffff00000000);
      ppiVar16 = local_c8;
      ppiVar12 = ppiVar8;
      if (0 < (int)ppiVar8) {
        do {
          local_ac = ppiVar12;
          iVar15 = *(int *)((int)&DAT_004ec2f4 + (int)ppiVar16);
          if ((iVar10 <= iVar15) &&
             ((iVar10 < iVar15 || (uVar18 < *(uint *)((int)&DAT_004ec2f0 + (int)ppiVar16))))) {
            iVar10 = iVar15;
            uVar18 = *(uint *)((int)&DAT_004ec2f0 + (int)ppiVar16);
          }
          uVar5 = *(uint *)((int)&DAT_005af0ec + (int)ppiVar16);
          if (((int)uVar14 <= (int)uVar5) &&
             (((int)uVar14 < (int)uVar5 ||
              ((int **)local_98 < *(uint *)((int)&DAT_005af0e8 + (int)ppiVar16))))) {
            local_98 = (double)CONCAT44(local_98._4_4_,*(uint *)((int)&DAT_005af0e8 + (int)ppiVar16)
                                       );
            uVar14 = uVar5;
          }
          local_ac = (int **)((int)local_ac + -1);
          ppiVar16 = ppiVar16 + 2;
          ppiVar12 = local_ac;
        } while (local_ac != (int **)0x0);
      }
      local_c0 = (uint *)0x0;
      if (0 < (int)ppiVar8) {
        ppiVar8 = local_c8;
        do {
          lVar25 = __allmul(*(uint *)((int)&DAT_004ec2f0 + (int)ppiVar8),
                            *(uint *)((int)&DAT_004ec2f4 + (int)ppiVar8),100,0);
          uVar24 = __alldiv((uint)lVar25,(uint)((ulonglong)lVar25 >> 0x20),uVar18 + 1,
                            iVar10 + (uint)(0xfffffffe < uVar18));
          *(undefined8 *)((int)&DAT_004ec2f0 + (int)ppiVar8) = uVar24;
          if ((-1 < (int)uVar14) && ((0 < (int)uVar14 || ((int **)local_98 != (int **)0x0)))) {
            lVar25 = __allmul(*(uint *)((int)&DAT_005af0e8 + (int)ppiVar8),
                              *(uint *)((int)&DAT_005af0ec + (int)ppiVar8),100,0);
            uVar24 = __alldiv((uint)lVar25,(uint)((ulonglong)lVar25 >> 0x20),(uint)(int **)local_98,
                              uVar14);
            *(undefined8 *)((int)&DAT_005af0e8 + (int)ppiVar8) = uVar24;
          }
          local_c0 = (uint *)((int)local_c0 + 1);
          ppiVar8 = ppiVar8 + 2;
        } while ((int)local_c0 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
      }
      iVar10 = *(int *)(param_1 + 8);
      local_c8 = local_c8 + 0x200;
      local_c4 = (int **)((int)local_c4 + 1);
    } while ((int)local_c4 < *(int *)(iVar10 + 0x2404));
  }
  iVar10 = 0;
  uVar14 = 0;
  uVar18 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
    do {
      iVar20 = 0;
      if (0 < iVar15) {
        puVar19 = &DAT_004ec2f0 + iVar10 * 2;
        do {
          uVar6 = *puVar19;
          puVar1 = (uint *)(&g_GlobalProvinceScore + iVar10);
          uVar5 = *puVar1;
          *puVar1 = *puVar1 + uVar6;
          piVar21 = (int *)((int)&g_GlobalProvinceScore + iVar10 * 8 + 4);
          *piVar21 = *piVar21 + puVar19[1] + (uint)CARRY4(uVar5,uVar6);
          iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
          iVar20 = iVar20 + 1;
          puVar19 = puVar19 + 0x200;
        } while (iVar20 < iVar15);
      }
      uVar5 = *(uint *)((int)&g_GlobalProvinceScore + iVar10 * 8 + 4);
      if (((int)uVar18 <= (int)uVar5) &&
         (((int)uVar18 < (int)uVar5 || (uVar14 < *(uint *)(&g_GlobalProvinceScore + iVar10))))) {
        uVar14 = *(uint *)(&g_GlobalProvinceScore + iVar10);
        uVar18 = uVar5;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  iVar10 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    do {
      if ((-1 < (int)uVar18) && ((0 < (int)uVar18 || (uVar14 != 0)))) {
        lVar25 = __allmul(*(uint *)(&g_GlobalProvinceScore + iVar10),
                          *(uint *)((int)&g_GlobalProvinceScore + iVar10 * 8 + 4),100,0);
        uVar24 = __alldiv((uint)lVar25,(uint)((ulonglong)lVar25 >> 0x20),uVar14,uVar18);
        *(int *)(&g_GlobalProvinceScore + iVar10) = (int)uVar24;
        *(int *)((int)&g_GlobalProvinceScore + iVar10 * 8 + 4) = (int)((ulonglong)uVar24 >> 0x20);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  iVar10 = *(int *)(param_1 + 8);
  iVar15 = *(int *)(iVar10 + 0x2404);
  local_c8 = (int **)0x0;
  if (0 < iVar15) {
    do {
      local_c4 = (int **)0x0;
      ppiVar8 = local_c8;
      if (0 < iVar15) {
        do {
          if (local_c4 != ppiVar8) {
            puVar19 = (uint *)0x0;
            local_b8 = (int **)0x0;
            piStack_b4 = (int *)0x0;
            local_a8 = (int *)0x0;
            piStack_a4 = (int *)0x0;
            local_c0 = (uint *)0x0;
            if (0 < *(int *)(iVar10 + 0x2400)) {
              fVar23 = (float10)_safe_pow();
              local_68 = (double)fVar23;
              fVar23 = (float10)_safe_pow();
              local_78 = (double)fVar23;
              fVar23 = (float10)_safe_pow();
              local_80 = (double)fVar23;
              ppiVar8 = (int **)((int)ppiVar8 << 0xb);
              iVar10 = 0;
              piVar21 = (int *)((int)local_c4 << 0xb);
              local_84 = ppiVar8;
              do {
                local_90 = (double)*(longlong *)(ppiVar8 + 0x16bc3a);
                local_98 = (double)*(longlong *)(piVar21 + 0x13b0bc);
                local_bc = piVar21;
                local_ac = ppiVar8;
                fVar23 = (float10)_safe_pow();
                local_60 = (double)(fVar23 / (float10)local_68);
                _safe_pow();
                uVar26 = PackScoreU64();
                (&g_MoveScore)[(int)puVar19 * 2] = (int)uVar26;
                (&DAT_004e12f4)[(int)puVar19 * 2] = (int)(uVar26 >> 0x20);
                fVar23 = (float10)_safe_pow();
                local_60 = (double)(fVar23 / (float10)local_80);
                _safe_pow();
                uVar26 = PackScoreU64();
                (&g_SupportScore)[(int)puVar19 * 2] = (int)uVar26;
                (&DAT_004e0af4)[(int)puVar19 * 2] = (int)(uVar26 >> 0x20);
                if ((ppiVar8[0x1386bc] == (int *)0x0 && ppiVar8[0x1386bd] == (int *)0x0) ||
                   (piVar21[0x1386bc] == 0 && piVar21[0x1386bd] == 0)) {
                  (&g_MoveScore)[(int)puVar19 * 2] = 0;
                  (&g_SupportScore)[(int)puVar19 * 2] = 0;
                  (&DAT_004e12f4)[(int)puVar19 * 2] = 0;
                  (&DAT_004e0af4)[(int)puVar19 * 2] = 0;
                }
                iVar15 = (&DAT_004e12f4)[(int)puVar19 * 2];
                if (((int)piStack_b4 <= iVar15) &&
                   (((int)piStack_b4 < iVar15 ||
                    (local_b8 < (int **)(&g_MoveScore)[(int)puVar19 * 2])))) {
                  local_b8 = (int **)(&g_MoveScore)[(int)puVar19 * 2];
                  piStack_b4 = (int *)iVar15;
                }
                if (((int)piStack_a4 <= (int)(&DAT_004e0af4)[(int)puVar19 * 2]) &&
                   (((int)piStack_a4 < (int)(&DAT_004e0af4)[(int)puVar19 * 2] ||
                    (local_a8 < (uint)(&g_SupportScore)[(int)puVar19 * 2])))) {
                  iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x18 + iVar10);
                  pvVar17 = (void *)(*(int *)(param_1 + 8) + 0x14 + iVar10);
                  puVar13 = (undefined4 *)
                            GameBoard_GetPowerRec(pvVar17,(int *)&local_a0,(int *)&local_c4);
                  if (((void *)*puVar13 == (void *)0x0) || ((void *)*puVar13 != pvVar17)) {
                    FUN_0047a948();
                  }
                  if (puVar13[1] == iVar15) {
                    iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x18 + iVar10);
                    pvVar17 = (void *)(*(int *)(param_1 + 8) + 0x14 + iVar10);
                    puVar13 = (undefined4 *)GameBoard_GetPowerRec(pvVar17,local_28,(int *)&local_c8)
                    ;
                    if (((void *)*puVar13 == (void *)0x0) || ((void *)*puVar13 != pvVar17)) {
                      FUN_0047a948();
                    }
                    if (puVar13[1] == iVar15) {
                      local_a8 = (int *)(&g_SupportScore)[(int)local_c0 * 2];
                      piStack_a4 = (int *)(&DAT_004e0af4)[(int)local_c0 * 2];
                    }
                  }
                }
                iVar15 = *(int *)(param_1 + 8);
                puVar19 = (uint *)((int)local_c0 + 1);
                ppiVar8 = local_ac + 2;
                piVar21 = local_bc + 2;
                iVar10 = iVar10 + 0x24;
                local_c0 = puVar19;
              } while ((int)puVar19 < *(int *)(iVar15 + 0x2400));
              local_bc = piVar21;
              local_ac = ppiVar8;
              if ((-1 < (int)piStack_b4) &&
                 (((0 < (int)piStack_b4 || (local_b8 != (int **)0x0)) &&
                  (iVar10 = 0, 0 < *(int *)(iVar15 + 0x2400))))) {
                ppiVar8 = local_84 + 0x16923a;
                iVar20 = iVar15;
                do {
                  uVar26 = FloatToInt64(iVar15,iVar20);
                  uVar14 = (uint)uVar26;
                  iVar20 = (int)uVar14 >> 0x1f;
                  piVar21 = *ppiVar8;
                  *ppiVar8 = (int *)((int)*ppiVar8 + uVar14);
                  ppiVar8[1] = (int *)((int)ppiVar8[1] + (uint)CARRY4((uint)piVar21,uVar14) + iVar20
                                      );
                  iVar10 = iVar10 + 1;
                  ppiVar8 = ppiVar8 + 2;
                  iVar15 = extraout_ECX;
                } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
              }
              ppiVar8 = local_c8;
              if ((-1 < (int)piStack_a4) && ((0 < (int)piStack_a4 || (local_a8 != (int *)0x0)))) {
                iVar10 = *(int *)(param_1 + 8);
                local_c0 = (uint *)0x0;
                if (0 < *(int *)(iVar10 + 0x2400)) {
                  local_68 = (double)CONCAT44(piStack_a4,local_a8);
                  iVar15 = (int)local_c8 * 0x15 + (int)local_c4;
                  local_84 = (int **)(&g_InfluenceMatrix_B + iVar15);
                  uVar26 = CONCAT44(local_84,local_bc);
                  do {
                    puVar19 = local_c0;
                    local_bc = (int *)uVar26;
                    uVar26 = FloatToInt64(iVar15,(int)(uVar26 >> 0x20));
                    local_bc = (int *)uVar26;
                    if ((local_c8 == local_6c) && (0 < (int)local_bc)) {
                      iVar15 = *(int *)(iVar10 + 0x2454);
                      uVar24 = OrderedSet_FindOrInsert
                                         ((void *)(iVar10 + 0x2450),local_30,(int *)&local_c0);
                      uVar11 = (undefined4)((ulonglong)uVar24 >> 0x20);
                      pvVar17 = (void *)*(int *)uVar24;
                      if ((pvVar17 == (void *)0x0) || (pvVar17 != (void *)(iVar10 + 0x2450))) {
                        FUN_0047a948();
                        uVar11 = extraout_EDX;
                      }
                      uVar26 = CONCAT44(uVar11,local_bc);
                      if (((int *)uVar24)[1] == iVar15) {
                        local_54 = local_54 & 0xffffff00;
                        local_48 = CONCAT13(local_48._3_1_,0x101);
                        if ((int **)(&DAT_00ba2f70)[(int)puVar19] == local_c4) {
                          local_48 = local_48 & 0xffffff00;
                        }
                        else if ((int **)(&DAT_00ba2f70)[(int)puVar19] == local_6c) {
                          local_48 = CONCAT22(local_48._2_2_,1);
                        }
                        if (*(char *)(*(int *)(param_1 + 8) + 3 + (int)puVar19 * 0x24) == '\0') {
                          puVar13 = local_14;
                        }
                        else {
                          uVar2 = *(ushort *)(*(int *)(param_1 + 8) + (int)puVar19 * 0x24 + 0x20);
                          uVar26 = CONCAT44((int)puVar19 * 9,local_bc);
                          if (((char)(uVar2 >> 8) != 'A') ||
                             (ppiVar8 = (int **)(uVar2 & 0xff),
                             uVar26 = CONCAT44((int)puVar19 * 9,local_bc), ppiVar8 == (int **)0x14))
                          goto LAB_004373df;
                          if (ppiVar8 == local_6c) {
                            local_48 = local_48 & 0xffffff00;
                            puVar13 = local_20;
                          }
                          else {
                            if (ppiVar8 == local_c4) {
                              local_48._0_2_ = (ushort)(byte)local_48;
                            }
                            puVar13 = local_20;
                          }
                        }
                        local_3c = local_c4;
                        local_40 = local_54;
                        local_44 = (int)local_bc;
                        local_34 = local_48;
                        local_38 = puVar19;
                        AppendOrder(&g_OrderList,puVar13,&local_44);
                        uVar26 = CONCAT44(extraout_EDX_00,local_bc);
                      }
                    }
LAB_004373df:
                    local_bc = (int *)uVar26;
                    iVar10 = *(int *)(param_1 + 8);
                    local_c0 = (uint *)((int)puVar19 + 1);
                    iVar15 = param_1;
                    ppiVar8 = local_c8;
                  } while ((int)local_c0 < *(int *)(iVar10 + 0x2400));
                }
              }
            }
          }
          iVar10 = *(int *)(param_1 + 8);
          local_c4 = (int **)((int)local_c4 + 1);
        } while ((int)local_c4 < *(int *)(iVar10 + 0x2404));
      }
      iVar10 = *(int *)(param_1 + 8);
      iVar15 = *(int *)(iVar10 + 0x2404);
      local_c8 = (int **)((int)ppiVar8 + 1);
    } while ((int)local_c8 < iVar15);
  }
  iVar10 = *(int *)(param_1 + 8);
  iVar15 = 0;
  uVar14 = 0;
  if (0 < *(int *)(iVar10 + 0x2404)) {
    local_bc = (int *)0x0;
    do {
      iVar20 = 0;
      if (0 < *(int *)(iVar10 + 0x2400)) {
        iVar22 = 0;
        do {
          if ((((*(char *)(iVar10 + 3 + iVar22) != '\0') &&
               (uVar2 = *(ushort *)(iVar10 + 0x20 + iVar22), (char)(uVar2 >> 8) == 'A')) &&
              (uVar18 = uVar2 & 0xff, uVar18 != 0x14)) &&
             ((uVar18 != uVar14 && (1.0 < *(double *)(&DAT_00b76a28 + ((int)local_bc + iVar20) * 8))
              ))) {
            iVar7 = (&g_UnitAdjacencyCount)[((int)local_bc + iVar20) * 2];
            iVar10 = uVar18 + iVar15;
            (&DAT_00b75578)[iVar10] = (&DAT_00b75578)[iVar10] + 1;
            (&g_AllyRankingAux)[iVar10] = (&g_AllyRankingAux)[iVar10] + iVar7;
            (&DAT_00b75620)[iVar10] =
                 (&DAT_00b75620)[iVar10] + (&g_UnitAdjacencyCount)[(uVar18 * 0x100 + iVar20) * 2];
          }
          iVar10 = *(int *)(param_1 + 8);
          iVar20 = iVar20 + 1;
          iVar22 = iVar22 + 0x24;
        } while (iVar20 < *(int *)(iVar10 + 0x2400));
      }
      iVar10 = *(int *)(param_1 + 8);
      local_bc = (int *)((int)local_bc + 0x100);
      uVar14 = uVar14 + 1;
      iVar15 = iVar15 + 0x3f;
    } while ((int)uVar14 < *(int *)(iVar10 + 0x2404));
  }
  return;
}

