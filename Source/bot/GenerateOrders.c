
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall GenerateOrders(int param_1)

{
  void *pvVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  int **ppiVar7;
  undefined1 *puVar8;
  int **ppiVar9;
  int iVar10;
  undefined4 *puVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  double *pdVar16;
  undefined4 extraout_ECX;
  int iVar17;
  int iVar18;
  undefined4 extraout_EDX;
  int iVar19;
  double *pdVar20;
  int *piVar21;
  bool bVar22;
  float10 extraout_ST0;
  float10 fVar23;
  float10 fVar24;
  undefined8 uVar25;
  ulonglong uVar26;
  uint auStackY_6818 [459];
  undefined4 uStackY_60ec;
  uint *local_60bc;
  int local_60b8;
  uint *local_60b4;
  double local_60b0;
  int local_60a4;
  undefined1 local_60a0 [4];
  int **local_609c;
  undefined4 local_6098;
  int local_6094;
  int local_6090;
  undefined1 local_608c [4];
  int **local_6088;
  undefined4 local_6084;
  int local_6080;
  int iStack_607c;
  undefined1 *local_6078;
  int **local_6074;
  int local_6070;
  int local_606c;
  void *local_6068 [3];
  int local_605c;
  int local_6054;
  int local_604c;
  int local_6044;
  int *local_6040;
  uint local_603c;
  int local_6038;
  int local_602c [2];
  void *local_6024 [3];
  int aiStack_6018 [512];
  undefined4 local_5818 [2048];
  uint heat_movement_scores [512];
  uint local_3018 [512];
  uint local_2818 [2048];
  uint heat_build_scores [511];
  undefined4 uStack_1c;
  int iStack_18;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_004978a6;
  local_14 = ExceptionList;
  uStack_1c = 0x4466ff;
  ExceptionList = &local_14;
  local_60b8 = param_1;
  iStack_18 = param_1;
  local_6088 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_6088 + 0x11) = 1;
  local_6088[1] = (int *)local_6088;
  *local_6088 = (int *)local_6088;
  local_6088[2] = (int *)local_6088;
  local_6084 = 0;
  local_c = 0;
  local_609c = (int **)FUN_004103b0();
  *(undefined1 *)((int)local_609c + 0x21) = 1;
  local_609c[1] = (int *)local_609c;
  *local_609c = (int *)local_609c;
  local_609c[2] = (int *)local_609c;
  local_6098 = 0;
  local_c = CONCAT31(local_c._1_3_,1);
  InitScoringState(param_1);
  iVar19 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    iVar18 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
    do {
      iVar17 = 0;
      if (0 < iVar18) {
        iVar10 = iVar19 << 0xb;
        do {
          *(undefined4 *)((int)&g_CandidateScores + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005af0e8 + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005cf0e8 + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005c48e8 + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005ba0e8 + iVar10) = 0;
          *(undefined4 *)((int)&g_ProvTargetFlag + iVar10) = 0;
          *(undefined4 *)((int)&g_TargetFlag + iVar10) = 0;
          *(undefined4 *)((int)&DAT_0059a0ec + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005af0ec + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005cf0ec + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005c48ec + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005ba0ec + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005ee8ec + iVar10) = 0;
          *(undefined4 *)((int)&DAT_005e40ec + iVar10) = 0;
          iVar18 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
          iVar17 = iVar17 + 1;
          iVar10 = iVar10 + 8;
        } while (iVar17 < iVar18);
      }
      iVar19 = iVar19 + 1;
    } while (iVar19 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  iVar19 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    do {
      *(undefined4 *)(&g_GlobalProvinceScore + iVar19) = 0;
      *(undefined4 *)((int)&g_GlobalProvinceScore + iVar19 * 8 + 4) = 0;
      (&DAT_005b98e8)[iVar19 * 2] = 0xffffffff;
      (&DAT_005b98ec)[iVar19 * 2] = 0xffffffff;
      iVar19 = iVar19 + 1;
    } while (iVar19 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar18 = 0;
  if (0 < iVar19) {
    iVar17 = 0;
    do {
      iVar14 = 0;
      iVar10 = iVar17;
      if (0 < iVar19) {
        do {
          *(undefined8 *)((int)&g_InfluenceMatrix_B + iVar10) = 0;
          iVar14 = iVar14 + 1;
          *(undefined8 *)((int)&g_InfluenceMatrix_Raw + iVar10) = 0;
          iVar10 = iVar10 + 8;
        } while (iVar14 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar18 = iVar18 + 1;
      iVar17 = iVar17 + 0xa8;
    } while (iVar18 < iVar19);
  }
  iVar19 = *(int *)(param_1 + 8);
  local_60b4 = (uint *)0x0;
  if (0 < *(int *)(iVar19 + 0x2404)) {
    do {
      local_60a4 = 0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        local_60bc = (uint *)0x0;
        iVar19 = (int)local_60b4 << 0xb;
        do {
          *(undefined4 *)((int)&DAT_004ec2f0 + iVar19) = 0;
          *(undefined4 *)((int)&g_UnitAdjacencyCount + iVar19) = 0;
          *(undefined4 *)((int)&DAT_004ec2f4 + iVar19) = 0;
          *(undefined4 *)((int)&DAT_004e1af4 + iVar19) = 0;
          local_6044 = *(int *)(*(int *)(local_60b8 + 8) + 0x18 + (int)local_60bc);
          pvVar1 = (void *)(*(int *)(local_60b8 + 8) + 0x14 + (int)local_60bc);
          puVar11 = (undefined4 *)GameBoard_GetPowerRec(pvVar1,local_602c,(int *)&local_60b4);
          if (((void *)*puVar11 == (void *)0x0) || ((void *)*puVar11 != pvVar1)) {
            FUN_0047a948();
          }
          if (puVar11[1] == local_6044) {
LAB_004469d9:
            aiStack_6018[local_60a4 * 2] = 0;
LAB_004469ea:
            aiStack_6018[local_60a4 * 2 + 1] = 0;
          }
          else {
            uVar4 = *(ushort *)(*(int *)(local_60b8 + 8) + 0x20 + (int)local_60bc);
            puVar12 = (uint *)(uVar4 & 0xff);
            if ((char)(uVar4 >> 8) != 'A') {
              puVar12 = (uint *)0x14;
            }
            if (puVar12 != local_60b4) goto LAB_004469d9;
            if (DAT_00baed68 == '\x01') {
              aiStack_6018[local_60a4 * 2] = 5000;
              goto LAB_004469ea;
            }
            if ((int)(&target_sc_cnt)[(int)local_60b4] <= (int)(&curr_sc_cnt)[(int)local_60b4]) {
              aiStack_6018[local_60a4 * 2] = 1000;
              goto LAB_004469ea;
            }
            iVar18 = (((&target_sc_cnt)[(int)local_60b4] - (&curr_sc_cnt)[(int)local_60b4]) + 2) *
                     500;
            aiStack_6018[local_60a4 * 2] = iVar18;
            aiStack_6018[local_60a4 * 2 + 1] = iVar18 >> 0x1f;
          }
          puVar11 = local_5818 + local_60a4 * 2;
          iVar18 = 5;
          do {
            *puVar11 = 0;
            puVar11[1] = 0;
            puVar11 = puVar11 + 0x200;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
          local_60bc = local_60bc + 9;
          local_60a4 = local_60a4 + 1;
          iVar19 = iVar19 + 8;
        } while (local_60a4 < *(int *)(*(int *)(local_60b8 + 8) + 0x2400));
      }
      local_60bc = (uint *)0x100;
      local_60b0 = (double)CONCAT44(local_60b0._4_4_,local_5818);
      do {
        local_60a4 = 0;
        if (0 < *(int *)(*(int *)(local_60b8 + 8) + 0x2400)) {
          iVar19 = local_60b8 + 0x2a1c;
          puVar12 = (uint *)local_60b0._0_4_;
          do {
            local_6094 = iVar19;
            local_6090 = **(int **)(iVar19 + 4);
            while( true ) {
              iVar17 = local_6090;
              iVar18 = local_6094;
              local_605c = *(int *)(iVar19 + 4);
              if ((local_6094 == 0) || (local_6094 != iVar19)) {
                FUN_0047a948();
              }
              if (iVar17 == local_605c) break;
              if (iVar18 == 0) {
                FUN_0047a948();
              }
              if (iVar17 == *(int *)(iVar18 + 4)) {
                FUN_0047a948();
              }
              iVar18 = *(int *)(iVar17 + 0xc) + (int)local_60bc;
              uVar5 = auStackY_6818[iVar18 * 2];
              uVar2 = *puVar12;
              *puVar12 = *puVar12 + uVar5;
              puVar12[1] = puVar12[1] + auStackY_6818[iVar18 * 2 + 1] + (uint)CARRY4(uVar2,uVar5);
              TreeIterator_Advance(&local_6094);
            }
            uVar25 = __alldiv(*puVar12,puVar12[1],5,0);
            *(undefined8 *)puVar12 = uVar25;
            local_60a4 = local_60a4 + 1;
            iVar19 = iVar19 + 0xc;
            puVar12 = puVar12 + 2;
          } while (local_60a4 < *(int *)(*(int *)(local_60b8 + 8) + 0x2400));
        }
        local_60b0 = (double)CONCAT44(local_60b0._4_4_,(int)local_60b0._0_4_ + 0x800);
        local_60bc = local_60bc + 0x40;
      } while ((int)local_60bc < 0x600);
      iVar19 = *(int *)(local_60b8 + 8);
      iVar18 = *(int *)(iVar19 + 0x2400);
      if (0 < iVar18) {
        puVar12 = local_2818;
        do {
          puVar12[-0x200] = 0;
          puVar12[-0x1ff] = 0;
          iVar17 = 5;
          puVar13 = puVar12;
          do {
            *puVar13 = 0;
            puVar13[1] = 0;
            puVar13 = puVar13 + 0x200;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          puVar12 = puVar12 + 2;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      local_6070 = iVar19 + 0x2450;
      local_606c = **(int **)(iVar19 + 0x2454);
      while( true ) {
        iVar17 = local_606c;
        iVar18 = local_6070;
        iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2454);
        if ((local_6070 == 0) || (local_6070 != *(int *)(local_60b8 + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar17 == iVar19) break;
        if (iVar18 == 0) {
          FUN_0047a948();
        }
        if (iVar17 == *(int *)(iVar18 + 4)) {
          FUN_0047a948();
        }
        if (*(uint **)(iVar17 + 0x18) == local_60b4) {
          if (iVar17 == *(int *)(iVar18 + 4)) {
            FUN_0047a948();
          }
          iVar19 = *(int *)(iVar17 + 0x10);
          puVar12 = local_3018 + iVar19 * 2;
          uVar2 = *puVar12;
          *puVar12 = *puVar12 + 5000;
          local_3018[iVar19 * 2 + 1] = local_3018[iVar19 * 2 + 1] + (uint)(0xffffec77 < uVar2);
        }
        UnitList_Advance(&local_6070);
      }
      local_60b0 = (double)CONCAT44(local_60b0._4_4_,0x100);
      local_60bc = local_2818;
      do {
        local_60a4 = 0;
        if (0 < *(int *)(*(int *)(local_60b8 + 8) + 0x2400)) {
          iVar19 = local_60b8 + 0x2a1c;
          puVar12 = local_60bc;
          do {
            local_6094 = iVar19;
            local_6090 = **(int **)(iVar19 + 4);
            while( true ) {
              iVar17 = local_6090;
              iVar18 = local_6094;
              local_604c = *(int *)(iVar19 + 4);
              if ((local_6094 == 0) || (local_6094 != iVar19)) {
                FUN_0047a948();
              }
              if (iVar17 == local_604c) break;
              if (iVar18 == 0) {
                FUN_0047a948();
              }
              if (iVar17 == *(int *)(iVar18 + 4)) {
                FUN_0047a948();
              }
              iVar18 = *(int *)(iVar17 + 0xc) + (int)local_60b0._0_4_;
              uVar5 = heat_movement_scores[iVar18 * 2];
              uVar2 = *puVar12;
              *puVar12 = *puVar12 + uVar5;
              puVar12[1] = puVar12[1] + heat_movement_scores[iVar18 * 2 + 1] +
                           (uint)CARRY4(uVar2,uVar5);
              TreeIterator_Advance(&local_6094);
            }
            uVar25 = __alldiv(*puVar12,puVar12[1],5,0);
            *(undefined8 *)puVar12 = uVar25;
            local_60a4 = local_60a4 + 1;
            iVar19 = iVar19 + 0xc;
            puVar12 = puVar12 + 2;
          } while (local_60a4 < *(int *)(*(int *)(local_60b8 + 8) + 0x2400));
        }
        local_60bc = local_60bc + 0x200;
        iVar19 = (int)local_60b0._0_4_ + 0x100;
        local_60b0 = (double)CONCAT44(local_60b0._4_4_,iVar19);
      } while (iVar19 < 0x600);
      iVar19 = *(int *)(local_60b8 + 8);
      local_60bc = (uint *)0x0;
      if (0 < *(int *)(iVar19 + 0x2404)) {
        do {
          iVar18 = 0;
          local_60b0 = 0.0;
          if (0 < *(int *)(iVar19 + 0x2400)) {
            iVar17 = 0;
            do {
              local_6054 = *(int *)(iVar19 + 0x18 + iVar17);
              pvVar1 = (void *)(iVar19 + 0x14 + iVar17);
              puVar11 = (undefined4 *)
                        GameBoard_GetPowerRec(pvVar1,(int *)local_6068,(int *)&local_60bc);
              if (((void *)*puVar11 == (void *)0x0) || ((void *)*puVar11 != pvVar1)) {
                FUN_0047a948();
              }
              if ((puVar11[1] != local_6054) && (local_60b4 != local_60bc)) {
                local_6080 = heat_build_scores[iVar18 * 2] + heat_movement_scores[iVar18 * 2];
                iStack_607c = heat_build_scores[iVar18 * 2 + 1] +
                              heat_movement_scores[iVar18 * 2 + 1] +
                              (uint)CARRY4(heat_build_scores[iVar18 * 2],
                                           heat_movement_scores[iVar18 * 2]);
                local_60b0 = (double)CONCAT44(iStack_607c,local_6080) + local_60b0;
              }
              iVar19 = *(int *)(local_60b8 + 8);
              iVar18 = iVar18 + 1;
              iVar17 = iVar17 + 0x24;
            } while (iVar18 < *(int *)(iVar19 + 0x2400));
          }
          iVar19 = (int)local_60bc * 0x15;
          local_60bc = (uint *)((int)local_60bc + 1);
          (&g_InfluenceMatrix_B)[iVar19 + (int)local_60b4] = local_60b0;
          iVar19 = *(int *)(local_60b8 + 8);
        } while ((int)local_60bc < *(int *)(iVar19 + 0x2404));
      }
      iVar19 = local_60b8;
      cVar3 = *(char *)((int)local_609c[1] + 0x21);
      piVar21 = local_609c[1];
      while (cVar3 == '\0') {
        std_Tree_DestroyTree((int *)piVar21[2]);
        piVar6 = (int *)*piVar21;
        _free(piVar21);
        piVar21 = piVar6;
        cVar3 = *(char *)((int)piVar6 + 0x21);
      }
      local_609c[1] = (int *)local_609c;
      iVar10 = 0;
      local_6098 = 0;
      *local_609c = (int *)local_609c;
      local_609c[2] = (int *)local_609c;
      iVar18 = *(int *)(iVar19 + 8);
      iVar17 = 0;
      if (0 < *(int *)(iVar18 + 0x2400)) {
        do {
          if (*(char *)(iVar10 + 3 + iVar18) != '\0') {
            local_6040 = (int *)heat_movement_scores[iVar17 * 2];
            local_603c = heat_movement_scores[iVar17 * 2 + 1];
            local_6038 = iVar17;
            OrderedSet_FindOrInsert_64bit(local_60a0,local_6024,&local_6040);
          }
          iVar18 = *(int *)(iVar19 + 8);
          iVar17 = iVar17 + 1;
          iVar10 = iVar10 + 0x24;
        } while (iVar17 < *(int *)(iVar18 + 0x2400));
      }
      local_60b0 = (double)CONCAT44(local_60b0._4_4_,1);
      local_6078 = local_60a0;
      local_6074 = (int **)*local_609c;
      while( true ) {
        ppiVar9 = local_6074;
        puVar8 = local_6078;
        ppiVar7 = local_609c;
        if ((local_6078 == (undefined1 *)0x0) || (local_6078 != local_60a0)) {
          FUN_0047a948();
        }
        if (ppiVar9 == ppiVar7) break;
        if ((int)local_60b0._0_4_ <= *(int *)(iVar19 + 0x3ff8)) {
          if (puVar8 == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (ppiVar9 == *(int ***)(puVar8 + 4)) {
            FUN_0047a948();
          }
          uVar4 = *(ushort *)(*(int *)(iVar19 + 8) + 0x20 + (int)ppiVar9[6] * 0x24);
          puVar12 = (uint *)(uVar4 & 0xff);
          if ((char)(uVar4 >> 8) != 'A') {
            puVar12 = (uint *)0x14;
          }
          if (puVar12 != local_60b4) {
            if ((ppiVar9 == *(int ***)(puVar8 + 4)) &&
               (FUN_0047a948(), ppiVar9 == *(int ***)(puVar8 + 4))) {
              FUN_0047a948();
            }
            piVar21 = ppiVar9[6];
            local_60b0 = (double)CONCAT44(local_60b0._4_4_,(int)local_60b0._0_4_ + 1);
            (&g_CandidateScores)[(int)(piVar21 + (int)local_60b4 * 0x40) * 2] = ppiVar9[4];
            (&DAT_0059a0ec)[(int)(piVar21 + (int)local_60b4 * 0x40) * 2] = ppiVar9[5];
          }
        }
        std_Tree_IteratorIncrement((int *)&local_6078);
      }
      iVar18 = 0;
      if (0 < *(int *)(*(int *)(iVar19 + 8) + 0x2400)) {
        iVar17 = (int)local_60b4 << 0xb;
        do {
          uVar2 = heat_movement_scores[iVar18 * 2];
          uVar5 = heat_movement_scores[iVar18 * 2 + 1];
          *(uint *)((int)&DAT_005af0e8 + iVar17) = uVar2;
          *(uint *)((int)&DAT_004ec2f0 + iVar17) = uVar2;
          *(uint *)((int)&DAT_005af0ec + iVar17) = uVar5;
          *(uint *)((int)&DAT_004ec2f4 + iVar17) = uVar5;
          iVar18 = iVar18 + 1;
          iVar17 = iVar17 + 8;
        } while (iVar18 < *(int *)(*(int *)(iVar19 + 8) + 0x2400));
      }
      iVar19 = *(int *)(iVar19 + 8);
      local_60b4 = (uint *)((int)local_60b4 + 1);
    } while ((int)local_60b4 < *(int *)(iVar19 + 0x2404));
  }
  iVar18 = local_60b8;
  fVar23 = (float10)0;
  iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
  iVar17 = 0;
  if (0 < iVar19) {
    iVar10 = 0;
    do {
      iVar15 = 0;
      iVar14 = iVar10;
      if (0 < iVar19) {
        do {
          iVar15 = iVar15 + 1;
          *(undefined8 *)((int)&g_InfluenceMatrix_Raw + iVar14) =
               *(undefined8 *)((int)&g_InfluenceMatrix_B + iVar14);
          iVar14 = iVar14 + 8;
        } while (iVar15 < *(int *)(*(int *)(local_60b8 + 8) + 0x2404));
      }
      iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
      iVar17 = iVar17 + 1;
      iVar10 = iVar10 + 0xa8;
    } while (iVar17 < iVar19);
  }
  iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
  iVar17 = 0;
  if (0 < iVar19) {
    do {
      if (0 < iVar19) {
        do {
          iVar19 = iVar19 + -1;
        } while (iVar19 != 0);
      }
      uVar26 = PackScoreU64();
      (&g_PowerInfluenceSum)[iVar17 * 2] = (int)uVar26;
      (&DAT_004f6c44)[iVar17 * 2] = (int)(uVar26 >> 0x20);
      iVar19 = *(int *)(*(int *)(iVar18 + 8) + 0x2404);
      iVar17 = iVar17 + 1;
      fVar23 = extraout_ST0;
    } while (iVar17 < iVar19);
  }
  iVar19 = *(int *)(*(int *)(iVar18 + 8) + 0x2404);
  iVar18 = 0;
  if (0 < iVar19) {
    local_60b0 = (double)CONCAT44(local_60b0._4_4_,&g_InfluenceMatrix_B);
    do {
      iVar17 = local_60b8;
      iVar10 = 0;
      if (0 < iVar19) {
        pdVar20 = local_60b0._0_4_;
        do {
          local_6080 = (&g_PowerInfluenceSum)[iVar10 * 2] + 1;
          iStack_607c = (&DAT_004f6c44)[iVar10 * 2] +
                        (uint)(0xfffffffe < (uint)(&g_PowerInfluenceSum)[iVar10 * 2]);
          fVar23 = (float10)_safe_pow();
          iVar10 = iVar10 + 1;
          *pdVar20 = (double)(fVar23 * (float10)500.0 + (float10)*pdVar20);
          pdVar20 = pdVar20 + 1;
        } while (iVar10 < *(int *)(*(int *)(iVar17 + 8) + 0x2404));
      }
      iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
      local_60b0 = (double)CONCAT44(local_60b0._4_4_,(int)local_60b0._0_4_ + 0xa8);
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar19);
    fVar23 = (float10)0;
  }
  iVar18 = local_60b8;
  iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
  iVar17 = 0;
  if (0 < iVar19) {
    iVar10 = 0;
    pdVar20 = (double *)&g_InfluenceMatrix_B;
    do {
      pdVar16 = pdVar20;
      iVar14 = iVar19;
      fVar24 = fVar23;
      if (0 < iVar19) {
        do {
          fVar24 = fVar24 + (float10)*pdVar16;
          iVar14 = iVar14 + -1;
          pdVar16 = pdVar16 + 1;
        } while (iVar14 != 0);
      }
      iVar14 = 0;
      if (0 < iVar19) {
        do {
          if (fVar23 != fVar24) {
            (&g_InfluenceMatrix_B)[iVar10 + iVar14] =
                 (double)(((float10)(double)(&g_InfluenceMatrix_B)[iVar10 + iVar14] * (float10)100.0
                          ) / fVar24);
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < *(int *)(*(int *)(local_60b8 + 8) + 0x2404));
      }
      iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
      iVar17 = iVar17 + 1;
      pdVar20 = pdVar20 + 0x15;
      iVar10 = iVar10 + 0x15;
    } while (iVar17 < iVar19);
  }
  iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
  iVar17 = 0;
  if (0 < iVar19) {
    pdVar20 = (double *)&g_InfluenceMatrix_Raw;
    iVar10 = 0;
    local_60b0 = (double)CONCAT44(local_60b0._4_4_,&g_InfluenceMatrix_Raw);
    do {
      iVar14 = iVar19;
      fVar24 = fVar23;
      if (0 < iVar19) {
        do {
          fVar24 = fVar24 + (float10)*pdVar20;
          pdVar20 = pdVar20 + 0x15;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
      }
      iVar14 = 0;
      pdVar20 = local_60b0._0_4_;
      if (0 < iVar19) {
        do {
          if (iVar14 != iVar17) {
            if (((&curr_sc_cnt)[iVar17] == 0) || ((&curr_sc_cnt)[iVar14] == 0)) {
              (&g_AllianceScore)[iVar10 + iVar14] = (double)fVar23;
            }
            else {
              iVar19 = iVar10 + iVar14;
              if ((double)(&g_InfluenceMatrix_Raw)[iVar19] < *pdVar20 ==
                  ((double)(&g_InfluenceMatrix_Raw)[iVar19] == *pdVar20)) {
                (&g_AllianceScore)[iVar19] =
                     (double)(((((float10)(double)(&g_InfluenceMatrix_Raw)[iVar19] /
                                ((float10)*pdVar20 + (float10)1)) * (float10)*pdVar20) / fVar24) *
                             (float10)-3.0);
              }
              else {
                (&g_AllianceScore)[iVar19] =
                     (double)(((((float10)*pdVar20 /
                                ((float10)(double)(&g_InfluenceMatrix_Raw)[iVar19] + (float10)1)) *
                               (float10)*pdVar20) / fVar24) * (float10)3.0);
              }
            }
          }
          iVar14 = iVar14 + 1;
          pdVar20 = pdVar20 + 0x15;
        } while (iVar14 < *(int *)(*(int *)(local_60b8 + 8) + 0x2404));
      }
      iVar19 = *(int *)(*(int *)(local_60b8 + 8) + 0x2404);
      iVar17 = iVar17 + 1;
      pdVar20 = local_60b0._0_4_ + 1;
      iVar10 = iVar10 + 0x15;
      local_60b0 = (double)CONCAT44(local_60b0._4_4_,pdVar20);
    } while (iVar17 < iVar19);
  }
  ApplyInfluenceScores(local_60b8);
  local_60b4 = (uint *)0x0;
  if (0 < *(int *)(*(int *)(iVar18 + 8) + 0x2404)) {
    local_60b0 = (double)((ulonglong)local_60b0 & 0xffffffff00000000);
    piVar21 = &g_OpeningTarget;
    do {
      bVar22 = g_DeceitLevel == 1;
      *piVar21 = -1;
      if ((bVar22) && (iVar19 = *(int *)(iVar18 + 8), SPR == *(short *)(iVar19 + 0x244a))) {
        iVar17 = 0;
        local_60bc = (uint *)0x0;
        if (0 < *(int *)(iVar19 + 0x2400)) {
          iVar10 = 0;
          do {
            if ((*(char *)(iVar19 + 3 + iVar10) != '\0') &&
               (((uVar4 = *(ushort *)(iVar19 + 0x20 + iVar10), (char)(uVar4 >> 8) != 'A' ||
                 ((uVar4 & 0xff) == 0x14)) &&
                (fVar23 = (float10)_safe_pow(),
                (float10)(int)local_60bc <
                (fVar23 + fVar23) / (float10)(longlong)(&g_GlobalProvinceScore)[iVar17])))) {
              uVar26 = FloatToInt64(extraout_ECX,extraout_EDX);
              local_60bc = (uint *)uVar26;
              *piVar21 = iVar17;
            }
            iVar19 = *(int *)(iVar18 + 8);
            iVar17 = iVar17 + 1;
            iVar10 = iVar10 + 0x24;
          } while (iVar17 < *(int *)(iVar19 + 0x2400));
        }
      }
      local_60b0 = (double)CONCAT44(local_60b0._4_4_,(int)local_60b0._0_4_ + 0x100);
      local_60b4 = (uint *)((int)local_60b4 + 1);
      piVar21 = piVar21 + 1;
    } while ((int)local_60b4 < *(int *)(*(int *)(iVar18 + 8) + 0x2404));
  }
  local_c = local_c & 0xffffff00;
  uStackY_60ec = 0x4473f2;
  std_map_erase_range(local_60a0,local_6068,local_60a0,(int **)*local_609c,local_60a0,local_609c);
  _free(local_609c);
  local_609c = (int **)0x0;
  local_6098 = 0;
  local_c = 0xffffffff;
  uStackY_60ec = 0x44742e;
  SerializeOrders(local_608c,local_6068,local_608c,(int **)*local_6088,local_608c,local_6088);
  _free(local_6088);
  ExceptionList = local_14;
  return;
}

