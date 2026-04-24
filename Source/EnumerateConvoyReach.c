
void __fastcall EnumerateConvoyReach(int param_1)

{
  char cVar1;
  float10 fVar2;
  undefined1 *puVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int **ppiVar7;
  int *piVar8;
  int **ppiVar9;
  int **ppiVar10;
  undefined1 **ppuVar11;
  int ***pppiVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  int *bfsWave;
  undefined4 *puVar18;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  float10 fVar22;
  void **ppvVar23;
  float local_1b0;
  int *local_1ac;
  int *local_1a8;
  undefined1 *local_1a4;
  int **local_1a0;
  undefined1 reachCandidates [4];
  int **armyReachList;
  undefined4 local_194;
  int local_190;
  int **local_18c;
  int *local_188;
  char local_181;
  undefined1 freeDestinations [4];
  int **fleetChainList;
  undefined4 local_178;
  int *local_174;
  ushort local_170;
  int *local_16c;
  int *local_168;
  ushort coastToken;
  int **local_160;
  int *local_15c;
  int local_158;
  int *local_154;
  int *local_150;
  ushort local_14c;
  undefined4 local_148 [8];
  int *local_128 [2];
  double distWeightA;
  double distWeightB;
  undefined4 local_110;
  int local_108;
  int local_104;
  int **local_100;
  int *local_fc;
  void *local_f8;
  int **local_f4;
  int *local_f0;
  undefined2 local_ec;
  undefined1 local_e8 [4];
  int **local_e4;
  int local_dc;
  int **local_d8;
  int *local_d4;
  undefined1 *local_d0;
  int **local_cc;
  int **local_c8;
  int *local_c4;
  int **local_c0;
  int *local_bc;
  undefined1 *local_b8;
  int **local_b4;
  int **local_b0;
  int *local_ac;
  int **local_a8;
  int *local_a4;
  void *local_a0;
  int **local_9c;
  int **local_90;
  int **local_88;
  void *local_84 [3];
  void *local_78 [3];
  void *local_6c [3];
  void *local_60 [3];
  void *local_54 [3];
  void *local_48 [3];
  void *local_3c [3];
  void *local_30 [3];
  void *local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497621;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  bfsWave = (int *)0x0;
  coastToken = 0;
  local_170 = 0;
  local_190 = param_1;
  armyReachList = (int **)FUN_00410370();
  *(undefined1 *)((int)armyReachList + 0x39) = 1;
  armyReachList[1] = (int *)armyReachList;
  *armyReachList = (int *)armyReachList;
  armyReachList[2] = (int *)armyReachList;
  local_194 = 0;
  local_c = 0;
  fleetChainList = (int **)FUN_00410370();
  *(undefined1 *)((int)fleetChainList + 0x39) = 1;
  fleetChainList[1] = (int *)fleetChainList;
  *fleetChainList = (int *)fleetChainList;
  fleetChainList[2] = (int *)fleetChainList;
  local_178 = 0;
  distWeightA = 0.0;
  distWeightB = 0.0;
  local_c = CONCAT31(local_c._1_3_,1);
  local_110 = 0;
  local_128[0] = (int *)0x0;
  FUN_00410d30(armyReachList[1]);
  armyReachList[1] = (int *)armyReachList;
  local_194 = 0;
  *armyReachList = (int *)armyReachList;
  armyReachList[2] = (int *)armyReachList;
  iVar13 = *(int *)(param_1 + 8);
  if (0 < *(int *)(iVar13 + 0x2400)) {
    local_1b0 = 0.0;
    do {
      iVar13 = iVar13 + 8 + (int)local_1b0;
      local_154 = (int *)**(undefined4 **)(iVar13 + 4);
      local_158 = iVar13;
      while( true ) {
        piVar17 = local_154;
        iVar15 = local_158;
        local_fc = *(int **)(iVar13 + 4);
        if ((local_158 == 0) || (local_158 != iVar13)) {
          FUN_0047a948();
        }
        if (piVar17 == local_fc) break;
        if (iVar15 == 0) {
          FUN_0047a948();
        }
        if (piVar17 == *(int **)(iVar15 + 4)) {
          FUN_0047a948();
        }
        local_ec = (undefined2)piVar17[3];
        local_168 = bfsWave;
        local_f0 = bfsWave;
        FUN_00422460(local_e8,(int)reachCandidates);
        local_c._0_1_ = 2;
        FUN_004308b0(&DAT_00bc1e1c,&local_a0,&local_f0);
        local_c = CONCAT31(local_c._1_3_,1);
        FUN_0041aa20(local_e8,&local_f8,local_e8,(int **)*local_e4,local_e8,local_e4);
        _free(local_e4);
        FUN_00401590(&local_158);
      }
      iVar13 = *(int *)(local_190 + 8);
      local_1b0 = (float)((int)local_1b0 + 0x24);
      bfsWave = (int *)((int)bfsWave + 1);
    } while ((int)bfsWave < *(int *)(iVar13 + 0x2400));
  }
  iVar13 = *(int *)(local_190 + 8);
  local_16c = (int *)0x0;
  if (0 < *(int *)(iVar13 + 0x2400)) {
    do {
      local_dc = iVar13 + 8 + (int)local_16c * 0x24;
      local_158 = local_dc;
      local_154 = (int *)**(undefined4 **)(local_dc + 4);
      while( true ) {
        piVar8 = local_154;
        iVar13 = local_158;
        piVar17 = local_16c;
        bfsWave = *(int **)(local_dc + 4);
        if ((local_158 == 0) || (local_158 != local_dc)) {
          FUN_0047a948();
        }
        if (piVar8 == bfsWave) break;
        if (iVar13 == 0) {
          FUN_0047a948();
        }
        if (piVar8 == *(int **)(iVar13 + 4)) {
          FUN_0047a948();
        }
        piVar17 = local_16c;
        distWeightA = 1.0;
        coastToken = *(ushort *)(piVar8 + 3);
        distWeightB = 1.0;
        cVar1 = *(char *)((int)armyReachList[1] + 0x39);
        local_168 = local_16c;
        local_128[0] = (int *)0x0;
        local_110 = 0;
        bfsWave = armyReachList[1];
        while (cVar1 == '\0') {
          FUN_00410d30((int *)bfsWave[2]);
          piVar8 = (int *)*bfsWave;
          _free(bfsWave);
          bfsWave = piVar8;
          cVar1 = *(char *)((int)piVar8 + 0x39);
        }
        armyReachList[1] = (int *)armyReachList;
        local_194 = 0;
        *armyReachList = (int *)armyReachList;
        armyReachList[2] = (int *)armyReachList;
        local_150 = piVar17;
        local_14c = coastToken;
        ppiVar9 = local_128;
        puVar18 = local_148;
        for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar18 = *ppiVar9;
          ppiVar9 = ppiVar9 + 1;
          puVar18 = puVar18 + 1;
        }
        SortedList_Insert(reachCandidates,local_3c,&local_150);
        local_14c = coastToken;
        ppiVar9 = &local_150;
        local_150 = piVar17;
        ppiVar7 = local_128;
        puVar18 = local_148;
        for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar18 = *ppiVar7;
          ppiVar7 = ppiVar7 + 1;
          puVar18 = puVar18 + 1;
        }
        ppvVar23 = local_54;
        ppiVar7 = g_BuildCandidateList(&DAT_00bc1e1c,&local_168);
        SortedList_Insert(ppiVar7,ppvVar23,ppiVar9);
        local_110 = 0;
        bfsWave = (int *)0x0;
        do {
          piVar17 = bfsWave;
          local_1a0 = (int **)*armyReachList;
          bfsWave = (int *)((int)piVar17 + 1);
          local_1a4 = reachCandidates;
          local_181 = '\0';
          while( true ) {
            ppiVar7 = armyReachList;
            ppiVar9 = local_1a0;
            puVar3 = local_1a4;
            if ((local_1a4 == (undefined1 *)0x0) || (local_1a4 != reachCandidates)) {
              FUN_0047a948();
            }
            if (ppiVar9 == ppiVar7) break;
            if (puVar3 == (undefined1 *)0x0) {
              FUN_0047a948();
            }
            if (ppiVar9 == *(int ***)(puVar3 + 4)) {
              FUN_0047a948();
            }
            if (ppiVar9[6] == piVar17) {
              if ((ppiVar9 == *(int ***)(puVar3 + 4)) &&
                 (FUN_0047a948(), ppiVar9 == *(int ***)(puVar3 + 4))) {
                FUN_0047a948();
              }
              local_18c = AdjacencyList_FilterByUnitType
                                    ((void *)(*(int *)(local_190 + 8) + 8 + (int)ppiVar9[4] * 0x24),
                                     (ushort *)(ppiVar9 + 5));
              local_1ac = (int *)0x40e00000;
              piVar8 = bfsWave;
              if ((int)bfsWave < 0) {
                piVar8 = (int *)-(int)bfsWave;
              }
              local_1b0 = 1.0;
              while( true ) {
                if (((uint)piVar8 & 1) != 0) {
                  local_1b0 = local_1b0 * (float)local_1ac;
                }
                piVar8 = (int *)((uint)piVar8 >> 1);
                if (piVar8 == (int *)0x0) break;
                local_1ac = (int *)((float)local_1ac * (float)local_1ac);
              }
              fVar19 = (float10)local_1b0;
              fVar2 = (float10)1;
              if ((int)bfsWave < 0) {
                fVar19 = fVar2 / fVar19;
              }
              fVar20 = (float10)1.5;
              piVar8 = bfsWave;
              fVar21 = fVar2;
              fVar22 = fVar20;
              if ((int)bfsWave < 0) {
                piVar8 = (int *)-(int)bfsWave;
              }
              while( true ) {
                if (((uint)piVar8 & 1) != 0) {
                  fVar21 = fVar21 * fVar22;
                }
                if ((int *)((uint)piVar8 >> 1) == (int *)0x0) break;
                piVar8 = (int *)((uint)piVar8 >> 1);
                fVar22 = fVar22 * fVar22;
              }
              if ((int)bfsWave < 0) {
                fVar21 = fVar2 / fVar21;
              }
              distWeightA = (double)(fVar2 / (fVar2 / (float10)(float)fVar19 +
                                             fVar2 / (fVar21 * (float10)30.0)));
              local_1ac = (int *)0x41000000;
              piVar8 = bfsWave;
              if ((int)bfsWave < 0) {
                piVar8 = (int *)-(int)bfsWave;
              }
              local_1b0 = 1.0;
              while( true ) {
                if (((uint)piVar8 & 1) != 0) {
                  local_1b0 = local_1b0 * (float)local_1ac;
                }
                piVar8 = (int *)((uint)piVar8 >> 1);
                if (piVar8 == (int *)0x0) break;
                local_1ac = (int *)((float)local_1ac * (float)local_1ac);
              }
              fVar19 = (float10)local_1b0;
              if ((int)bfsWave < 0) {
                fVar19 = fVar2 / fVar19;
              }
              piVar8 = bfsWave;
              fVar21 = fVar2;
              if ((int)bfsWave < 0) {
                piVar8 = (int *)-(int)bfsWave;
              }
              while( true ) {
                if (((uint)piVar8 & 1) != 0) {
                  fVar21 = fVar21 * fVar20;
                }
                if ((int *)((uint)piVar8 >> 1) == (int *)0x0) break;
                fVar20 = fVar20 * fVar20;
                piVar8 = (int *)((uint)piVar8 >> 1);
              }
              if ((int)bfsWave < 0) {
                fVar21 = fVar2 / fVar21;
              }
              local_188 = (int *)*local_18c[1];
              distWeightB = (double)(fVar2 / (fVar2 / (float10)(float)fVar19 +
                                             fVar2 / (fVar21 * (float10)30.0)));
              local_160 = local_18c;
              local_128[0] = bfsWave;
              while( true ) {
                piVar16 = local_188;
                ppiVar9 = local_18c;
                piVar8 = local_160[1];
                if ((local_18c == (int **)0x0) || (local_18c != local_160)) {
                  FUN_0047a948();
                }
                if (piVar16 == piVar8) break;
                if (ppiVar9 == (int **)0x0) {
                  FUN_0047a948();
                }
                if (piVar16 == ppiVar9[1]) {
                  FUN_0047a948();
                }
                local_170 = *(ushort *)(piVar16 + 4);
                if (piVar16 == ppiVar9[1]) {
                  FUN_0047a948();
                }
                piVar8 = (int *)piVar16[3];
                local_174 = piVar8;
                ppiVar9 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                local_88 = (int **)ppiVar9[1];
                local_a8 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                piVar16 = (int *)local_a8[1][1];
                cVar1 = *(char *)((int)piVar16 + 0x39);
                local_a4 = local_a8[1];
                while (cVar1 == '\0') {
                  if ((piVar16[4] < (int)local_16c) ||
                     (((int *)piVar16[4] == local_16c && (*(ushort *)(piVar16 + 5) < coastToken))))
                  {
                    piVar14 = (int *)piVar16[2];
                    piVar16 = local_a4;
                  }
                  else {
                    piVar14 = (int *)*piVar16;
                  }
                  local_a4 = piVar16;
                  piVar16 = piVar14;
                  cVar1 = *(char *)((int)piVar14 + 0x39);
                }
                if (((local_a4 == local_a8[1]) || ((int)local_16c < local_a4[4])) ||
                   ((local_16c == (int *)local_a4[4] && (coastToken < *(ushort *)(local_a4 + 5)))))
                {
                  local_c8 = local_a8;
                  local_c4 = local_a8[1];
                  pppiVar12 = &local_c8;
                }
                else {
                  pppiVar12 = &local_a8;
                }
                ppiVar7 = pppiVar12[1];
                if ((*pppiVar12 == (int **)0x0) || (*pppiVar12 != ppiVar9)) {
                  FUN_0047a948();
                }
                if (ppiVar7 == local_88) {
                  local_150 = local_16c;
                  local_14c = coastToken;
                  ppiVar9 = local_128;
                  puVar18 = local_148;
                  for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                    *puVar18 = *ppiVar9;
                    ppiVar9 = ppiVar9 + 1;
                    puVar18 = puVar18 + 1;
                  }
                  ppiVar9 = &local_150;
                  ppvVar23 = local_84;
                  ppiVar7 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                  SortedList_Insert(ppiVar7,ppvVar23,ppiVar9);
                  local_14c = local_170;
                  local_150 = piVar8;
                  ppiVar9 = local_128;
                  puVar18 = local_148;
                  for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                    *puVar18 = *ppiVar9;
                    ppiVar9 = ppiVar9 + 1;
                    puVar18 = puVar18 + 1;
                  }
                  SortedList_Insert(reachCandidates,local_24,&local_150);
                  local_181 = '\x01';
                }
                FUN_0040f400((int *)&local_18c);
              }
            }
            FUN_0040f7f0((int *)&local_1a4);
          }
        } while (local_181 == '\x01');
        if (AMY == coastToken) {
          cVar1 = *(char *)((int)fleetChainList[1] + 0x39);
          piVar8 = fleetChainList[1];
          while (cVar1 == '\0') {
            FUN_00410d30((int *)piVar8[2]);
            piVar16 = (int *)*piVar8;
            _free(piVar8);
            piVar8 = piVar16;
            cVar1 = *(char *)((int)piVar16 + 0x39);
          }
          fleetChainList[1] = (int *)fleetChainList;
          local_178 = 0;
          *fleetChainList = (int *)fleetChainList;
          fleetChainList[2] = (int *)fleetChainList;
          local_1ac = (int *)0x0;
          if (-1 < (int)bfsWave) {
            do {
              local_1a0 = (int **)*armyReachList;
              local_1a4 = reachCandidates;
              while( true ) {
                ppiVar7 = armyReachList;
                ppiVar9 = local_1a0;
                puVar3 = local_1a4;
                if ((local_1a4 == (undefined1 *)0x0) || (local_1a4 != reachCandidates)) {
                  FUN_0047a948();
                }
                if (ppiVar9 == ppiVar7) break;
                if (puVar3 == (undefined1 *)0x0) {
                  FUN_0047a948();
                }
                if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                if (ppiVar9[6] == local_1ac) {
                  if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                    FUN_0047a948();
                  }
                  local_128[0] = (int *)((int)ppiVar9[6] + 1);
                  if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                    FUN_0047a948();
                  }
                  local_104 = **(int **)(*(int *)(local_190 + 8) + 0xc + (int)ppiVar9[4] * 0x24);
                  iVar13 = *(int *)(local_190 + 8) + 8 + (int)ppiVar9[4] * 0x24;
                  local_108 = iVar13;
                  while( true ) {
                    iVar6 = local_104;
                    iVar5 = local_108;
                    iVar15 = *(int *)(iVar13 + 4);
                    if ((local_108 == 0) || (local_108 != iVar13)) {
                      FUN_0047a948();
                    }
                    if (iVar6 == iVar15) break;
                    if (iVar5 == 0) {
                      FUN_0047a948();
                    }
                    if (iVar6 == *(int *)(iVar5 + 4)) {
                      FUN_0047a948();
                    }
                    if (AMY != *(ushort *)(iVar6 + 0xc)) {
                      if (iVar6 == *(int *)(iVar5 + 4)) {
                        FUN_0047a948();
                      }
                      if (ppiVar9 == *(int ***)(local_1a4 + 4)) {
                        FUN_0047a948();
                      }
                      ppiVar9 = AdjacencyList_FilterByUnitType
                                          ((void *)(*(int *)(local_190 + 8) + 8 +
                                                   (int)ppiVar9[4] * 0x24),(ushort *)(iVar6 + 0xc));
                      local_18c = ppiVar9;
                      local_188 = (int *)*ppiVar9[1];
                      while( true ) {
                        piVar16 = local_188;
                        ppiVar7 = local_18c;
                        piVar8 = ppiVar9[1];
                        if ((local_18c == (int **)0x0) || (local_18c != ppiVar9)) {
                          FUN_0047a948();
                        }
                        if (piVar16 == piVar8) break;
                        if (ppiVar7 == (int **)0x0) {
                          FUN_0047a948();
                        }
                        if (piVar16 == ppiVar7[1]) {
                          FUN_0047a948();
                        }
                        if (*(char *)(*(int *)(local_190 + 8) + 4 + piVar16[3] * 0x24) == '\0') {
                          if (piVar16 == ppiVar7[1]) {
                            FUN_0047a948();
                          }
                          local_150 = (int *)piVar16[3];
                          local_14c = *(ushort *)(piVar16 + 4);
                          ppiVar7 = local_128;
                          puVar18 = local_148;
                          for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
                            *puVar18 = *ppiVar7;
                            ppiVar7 = ppiVar7 + 1;
                            puVar18 = puVar18 + 1;
                          }
                          SortedList_Insert(freeDestinations,local_48,&local_150);
                        }
                        FUN_0040f400((int *)&local_18c);
                      }
                    }
                    FUN_00401590(&local_108);
                    ppiVar9 = local_1a0;
                  }
                }
                FUN_0040f7f0((int *)&local_1a4);
              }
              local_1ac = (int *)((int)local_1ac + 1);
            } while ((int)local_1ac <= (int)bfsWave);
          }
          local_1ac = (int *)0x0;
          if (-1 < (int)((int)piVar17 + 3U)) {
            do {
              local_1a0 = (int **)*fleetChainList;
              local_1a4 = freeDestinations;
              while( true ) {
                ppiVar7 = fleetChainList;
                ppiVar9 = local_1a0;
                puVar3 = local_1a4;
                if ((local_1a4 == (undefined1 *)0x0) || (local_1a4 != freeDestinations)) {
                  FUN_0047a948();
                }
                if (ppiVar9 == ppiVar7) break;
                if (puVar3 == (undefined1 *)0x0) {
                  FUN_0047a948();
                }
                if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                local_128[0] = (int *)((int)ppiVar9[6] + 1);
                if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                if (ppiVar9[6] == local_1ac) {
                  if ((ppiVar9 == *(int ***)(puVar3 + 4)) &&
                     (FUN_0047a948(), ppiVar9 == *(int ***)(puVar3 + 4))) {
                    FUN_0047a948();
                  }
                  local_160 = AdjacencyList_FilterByUnitType
                                        ((void *)(*(int *)(local_190 + 8) + 8 +
                                                 (int)ppiVar9[4] * 0x24),(ushort *)(ppiVar9 + 5));
                  local_18c = local_160;
                  local_188 = (int *)*local_160[1];
                  while( true ) {
                    piVar8 = local_188;
                    ppiVar9 = local_18c;
                    bfsWave = local_160[1];
                    if ((local_18c == (int **)0x0) || (local_18c != local_160)) {
                      FUN_0047a948();
                    }
                    if (piVar8 == bfsWave) break;
                    if (ppiVar9 == (int **)0x0) {
                      FUN_0047a948();
                    }
                    if (piVar8 == ppiVar9[1]) {
                      FUN_0047a948();
                    }
                    if (*(char *)(*(int *)(local_190 + 8) + 4 + piVar8[3] * 0x24) == '\0') {
                      local_90 = fleetChainList;
                      if (piVar8 == ppiVar9[1]) {
                        FUN_0047a948();
                      }
                      local_b4 = fleetChainList;
                      if (*(char *)((int)fleetChainList[1] + 0x39) == '\0') {
                        ppiVar7 = (int **)fleetChainList[1];
                        do {
                          if (((int)ppiVar7[4] < piVar8[3]) ||
                             ((ppiVar7[4] == (int *)piVar8[3] &&
                              (*(ushort *)(ppiVar7 + 5) < *(ushort *)(piVar8 + 4))))) {
                            ppiVar10 = (int **)ppiVar7[2];
                          }
                          else {
                            ppiVar10 = (int **)*ppiVar7;
                            local_b4 = ppiVar7;
                          }
                          ppiVar7 = ppiVar10;
                        } while (*(char *)((int)ppiVar10 + 0x39) == '\0');
                      }
                      local_b8 = freeDestinations;
                      if (((local_b4 == fleetChainList) || (piVar8[3] < (int)local_b4[4])) ||
                         (((int *)piVar8[3] == local_b4[4] &&
                          (*(ushort *)(piVar8 + 4) < *(ushort *)(local_b4 + 5))))) {
                        local_cc = fleetChainList;
                        local_d0 = freeDestinations;
                        ppuVar11 = &local_d0;
                      }
                      else {
                        ppuVar11 = &local_b8;
                      }
                      ppiVar7 = (int **)ppuVar11[1];
                      if ((*ppuVar11 == (undefined1 *)0x0) || (*ppuVar11 != freeDestinations)) {
                        FUN_0047a948();
                      }
                      if (ppiVar7 == local_90) {
                        if (piVar8 == ppiVar9[1]) {
                          FUN_0047a948();
                        }
                        local_150 = (int *)piVar8[3];
                        local_14c = *(ushort *)(piVar8 + 4);
                        ppiVar9 = local_128;
                        puVar18 = local_148;
                        for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                          *puVar18 = *ppiVar9;
                          ppiVar9 = ppiVar9 + 1;
                          puVar18 = puVar18 + 1;
                        }
                        SortedList_Insert(freeDestinations,local_60,&local_150);
                      }
                    }
                    FUN_0040f400((int *)&local_18c);
                  }
                }
                FUN_0040f7f0((int *)&local_1a4);
              }
              local_1ac = (int *)((int)local_1ac + 1);
            } while ((int)local_1ac <= (int)((int)piVar17 + 3U));
          }
          local_1a8 = (int *)0x0;
          local_15c = piVar17 + 1;
          if (-1 < (int)(piVar17 + 1)) {
            do {
              local_1a0 = (int **)*fleetChainList;
              local_1a4 = freeDestinations;
              while( true ) {
                ppiVar7 = fleetChainList;
                ppiVar9 = local_1a0;
                puVar3 = local_1a4;
                if ((local_1a4 == (undefined1 *)0x0) || (local_1a4 != freeDestinations)) {
                  FUN_0047a948();
                }
                if (ppiVar9 == ppiVar7) break;
                local_110 = 1;
                if (puVar3 == (undefined1 *)0x0) {
                  FUN_0047a948();
                }
                if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                local_128[0] = (int *)((int)ppiVar9[6] + 1);
                local_1ac = (int *)0x40e00000;
                bfsWave = local_128[0];
                if ((int)local_128[0] < 0) {
                  bfsWave = (int *)-(int)local_128[0];
                }
                local_1b0 = 1.0;
                while( true ) {
                  if (((uint)bfsWave & 1) != 0) {
                    local_1b0 = local_1b0 * (float)local_1ac;
                  }
                  bfsWave = (int *)((uint)bfsWave >> 1);
                  if (bfsWave == (int *)0x0) break;
                  local_1ac = (int *)((float)local_1ac * (float)local_1ac);
                }
                fVar19 = (float10)local_1b0;
                fVar2 = (float10)1;
                if ((int)local_128[0] < 0) {
                  fVar19 = fVar2 / fVar19;
                }
                fVar20 = (float10)1.5;
                bfsWave = local_128[0];
                fVar21 = fVar2;
                fVar22 = fVar20;
                if ((int)local_128[0] < 0) {
                  bfsWave = (int *)-(int)local_128[0];
                }
                while( true ) {
                  if (((uint)bfsWave & 1) != 0) {
                    fVar21 = fVar21 * fVar22;
                  }
                  if ((int *)((uint)bfsWave >> 1) == (int *)0x0) break;
                  bfsWave = (int *)((uint)bfsWave >> 1);
                  fVar22 = fVar22 * fVar22;
                }
                if ((int)local_128[0] < 0) {
                  fVar21 = fVar2 / fVar21;
                }
                distWeightA = (double)(fVar2 / (fVar2 / (fVar21 * (float10)300.0) +
                                               (float10)(float)fVar19 * (float10)0));
                local_1ac = (int *)0x41000000;
                bfsWave = local_128[0];
                if ((int)local_128[0] < 0) {
                  bfsWave = (int *)-(int)local_128[0];
                }
                local_1b0 = 1.0;
                while( true ) {
                  if (((uint)bfsWave & 1) != 0) {
                    local_1b0 = local_1b0 * (float)local_1ac;
                  }
                  bfsWave = (int *)((uint)bfsWave >> 1);
                  if (bfsWave == (int *)0x0) break;
                  local_1ac = (int *)((float)local_1ac * (float)local_1ac);
                }
                fVar19 = (float10)local_1b0;
                if ((int)local_128[0] < 0) {
                  fVar19 = fVar2 / fVar19;
                }
                bfsWave = local_128[0];
                fVar21 = fVar2;
                if ((int)local_128[0] < 0) {
                  bfsWave = (int *)-(int)local_128[0];
                }
                while( true ) {
                  if (((uint)bfsWave & 1) != 0) {
                    fVar21 = fVar21 * fVar20;
                  }
                  if ((int *)((uint)bfsWave >> 1) == (int *)0x0) break;
                  fVar20 = fVar20 * fVar20;
                  bfsWave = (int *)((uint)bfsWave >> 1);
                }
                if ((int)local_128[0] < 0) {
                  fVar21 = fVar2 / fVar21;
                }
                distWeightB = (double)(fVar2 / ((float10)0 * (float10)(float)fVar19 +
                                               fVar2 / (fVar21 * (float10)300.0)));
                if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                if (ppiVar9[6] == local_1a8) {
                  if ((ppiVar9 == *(int ***)(puVar3 + 4)) &&
                     (FUN_0047a948(), ppiVar9 == *(int ***)(puVar3 + 4))) {
                    FUN_0047a948();
                  }
                  local_18c = AdjacencyList_FilterByUnitType
                                        ((void *)(*(int *)(local_190 + 8) + 8 +
                                                 (int)ppiVar9[4] * 0x24),(ushort *)(ppiVar9 + 5));
                  bfsWave = local_16c;
                  local_188 = (int *)*local_18c[1];
                  local_160 = local_18c;
                  while( true ) {
                    piVar8 = local_188;
                    ppiVar9 = local_18c;
                    piVar17 = local_160[1];
                    if ((local_18c == (int **)0x0) || (local_18c != local_160)) {
                      FUN_0047a948();
                    }
                    if (piVar8 == piVar17) break;
                    if (ppiVar9 == (int **)0x0) {
                      FUN_0047a948();
                    }
                    if (piVar8 == ppiVar9[1]) {
                      FUN_0047a948();
                    }
                    if (*(char *)(*(int *)(local_190 + 8) + 4 + piVar8[3] * 0x24) == '\x01') {
                      local_170 = AMY;
                      if (piVar8 == ppiVar9[1]) {
                        FUN_0047a948();
                      }
                      piVar17 = (int *)piVar8[3];
                      local_174 = piVar17;
                      ppiVar9 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                      local_9c = (int **)ppiVar9[1];
                      local_c0 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                      piVar8 = (int *)local_c0[1][1];
                      cVar1 = *(char *)((int)piVar8 + 0x39);
                      local_bc = local_c0[1];
                      while (cVar1 == '\0') {
                        if ((piVar8[4] < (int)bfsWave) ||
                           (((int *)piVar8[4] == bfsWave && (*(ushort *)(piVar8 + 5) < coastToken)))
                           ) {
                          piVar16 = (int *)piVar8[2];
                          piVar8 = local_bc;
                        }
                        else {
                          piVar16 = (int *)*piVar8;
                        }
                        local_bc = piVar8;
                        piVar8 = piVar16;
                        cVar1 = *(char *)((int)piVar16 + 0x39);
                      }
                      if (((local_bc == local_c0[1]) || ((int)bfsWave < local_bc[4])) ||
                         ((bfsWave == (int *)local_bc[4] && (coastToken < *(ushort *)(local_bc + 5))
                          ))) {
                        local_d8 = local_c0;
                        local_d4 = local_c0[1];
                        pppiVar12 = &local_d8;
                      }
                      else {
                        pppiVar12 = &local_c0;
                      }
                      ppiVar7 = pppiVar12[1];
                      if ((*pppiVar12 == (int **)0x0) || (*pppiVar12 != ppiVar9)) {
                        FUN_0047a948();
                      }
                      if (ppiVar7 == local_9c) {
                        local_14c = coastToken;
                        ppiVar9 = &local_150;
                        local_150 = bfsWave;
                        ppiVar7 = local_128;
                        puVar18 = local_148;
                        for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                          *puVar18 = *ppiVar7;
                          ppiVar7 = ppiVar7 + 1;
                          puVar18 = puVar18 + 1;
                        }
                        ppvVar23 = local_30;
                        ppiVar7 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                        SortedList_Insert(ppiVar7,ppvVar23,ppiVar9);
                        local_150 = piVar17;
                        local_14c = local_170;
                        ppiVar9 = local_128;
                        puVar18 = local_148;
                        for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                          *puVar18 = *ppiVar9;
                          ppiVar9 = ppiVar9 + 1;
                          puVar18 = puVar18 + 1;
                        }
                        SortedList_Insert(reachCandidates,local_78,&local_150);
                      }
                    }
                    FUN_0040f400((int *)&local_18c);
                  }
                }
                FUN_0040f7f0((int *)&local_1a4);
              }
              local_1a8 = (int *)((int)local_1a8 + 1);
            } while ((int)local_1a8 <= (int)local_15c);
          }
          local_1a8 = (int *)0x0;
          do {
            local_1a0 = (int **)*armyReachList;
            local_1a4 = reachCandidates;
            while( true ) {
              ppiVar7 = armyReachList;
              ppiVar9 = local_1a0;
              puVar3 = local_1a4;
              if ((local_1a4 == (undefined1 *)0x0) || (local_1a4 != reachCandidates)) {
                FUN_0047a948();
              }
              if (ppiVar9 == ppiVar7) break;
              local_110 = 1;
              if (puVar3 == (undefined1 *)0x0) {
                FUN_0047a948();
              }
              if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                FUN_0047a948();
              }
              local_128[0] = (int *)((int)ppiVar9[6] + 1);
              local_1ac = (int *)0x40e00000;
              bfsWave = local_128[0];
              if ((int)local_128[0] < 0) {
                bfsWave = (int *)-(int)local_128[0];
              }
              local_1b0 = 1.0;
              while( true ) {
                if (((uint)bfsWave & 1) != 0) {
                  local_1b0 = local_1b0 * (float)local_1ac;
                }
                bfsWave = (int *)((uint)bfsWave >> 1);
                if (bfsWave == (int *)0x0) break;
                local_1ac = (int *)((float)local_1ac * (float)local_1ac);
              }
              fVar19 = (float10)local_1b0;
              fVar2 = (float10)1;
              if ((int)local_128[0] < 0) {
                fVar19 = fVar2 / fVar19;
              }
              fVar20 = (float10)1.5;
              bfsWave = local_128[0];
              fVar21 = fVar2;
              fVar22 = fVar20;
              if ((int)local_128[0] < 0) {
                bfsWave = (int *)-(int)local_128[0];
              }
              while( true ) {
                if (((uint)bfsWave & 1) != 0) {
                  fVar21 = fVar21 * fVar22;
                }
                if ((int *)((uint)bfsWave >> 1) == (int *)0x0) break;
                bfsWave = (int *)((uint)bfsWave >> 1);
                fVar22 = fVar22 * fVar22;
              }
              if ((int)local_128[0] < 0) {
                fVar21 = fVar2 / fVar21;
              }
              distWeightA = (double)(fVar2 / (fVar2 / (fVar21 * (float10)300.0) +
                                             (float10)(float)fVar19 * (float10)0));
              local_1ac = (int *)0x41000000;
              bfsWave = local_128[0];
              if ((int)local_128[0] < 0) {
                bfsWave = (int *)-(int)local_128[0];
              }
              local_1b0 = 1.0;
              while( true ) {
                if (((uint)bfsWave & 1) != 0) {
                  local_1b0 = local_1b0 * (float)local_1ac;
                }
                bfsWave = (int *)((uint)bfsWave >> 1);
                if (bfsWave == (int *)0x0) break;
                local_1ac = (int *)((float)local_1ac * (float)local_1ac);
              }
              fVar19 = (float10)local_1b0;
              if ((int)local_128[0] < 0) {
                fVar19 = fVar2 / fVar19;
              }
              local_15c = (int *)(float)fVar19;
              bfsWave = local_128[0];
              fVar21 = fVar2;
              if ((int)local_128[0] < 0) {
                bfsWave = (int *)-(int)local_128[0];
              }
              while( true ) {
                if (((uint)bfsWave & 1) != 0) {
                  fVar21 = fVar21 * fVar20;
                }
                if ((int *)((uint)bfsWave >> 1) == (int *)0x0) break;
                fVar20 = fVar20 * fVar20;
                bfsWave = (int *)((uint)bfsWave >> 1);
              }
              if ((int)local_128[0] < 0) {
                fVar21 = fVar2 / fVar21;
              }
              distWeightB = (double)(fVar2 / ((float10)0 * (float10)(float)fVar19 +
                                             fVar2 / (fVar21 * (float10)300.0)));
              if (ppiVar9 == *(int ***)(puVar3 + 4)) {
                FUN_0047a948();
              }
              if (ppiVar9[6] == local_1a8) {
                if ((ppiVar9 == *(int ***)(puVar3 + 4)) &&
                   (FUN_0047a948(), ppiVar9 == *(int ***)(puVar3 + 4))) {
                  FUN_0047a948();
                }
                local_18c = AdjacencyList_FilterByUnitType
                                      ((void *)(*(int *)(local_190 + 8) + 8 + (int)ppiVar9[4] * 0x24
                                               ),(ushort *)(ppiVar9 + 5));
                bfsWave = local_16c;
                local_188 = (int *)*local_18c[1];
                local_160 = local_18c;
                while( true ) {
                  piVar8 = local_188;
                  ppiVar9 = local_18c;
                  piVar17 = local_160[1];
                  if ((local_18c == (int **)0x0) || (local_18c != local_160)) {
                    FUN_0047a948();
                  }
                  if (piVar8 == piVar17) break;
                  if (ppiVar9 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (piVar8 == ppiVar9[1]) {
                    FUN_0047a948();
                  }
                  local_170 = *(ushort *)(piVar8 + 4);
                  if (piVar8 == ppiVar9[1]) {
                    FUN_0047a948();
                  }
                  local_174 = (int *)piVar8[3];
                  ppiVar9 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                  local_f4 = (int **)ppiVar9[1];
                  local_b0 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                  uVar4 = coastToken;
                  piVar17 = (int *)local_b0[1][1];
                  cVar1 = *(char *)((int)piVar17 + 0x39);
                  local_ac = local_b0[1];
                  while (cVar1 == '\0') {
                    if ((piVar17[4] < (int)bfsWave) ||
                       (((int *)piVar17[4] == bfsWave && (*(ushort *)(piVar17 + 5) < coastToken))))
                    {
                      piVar8 = (int *)piVar17[2];
                      piVar17 = local_ac;
                    }
                    else {
                      piVar8 = (int *)*piVar17;
                    }
                    local_ac = piVar17;
                    piVar17 = piVar8;
                    cVar1 = *(char *)((int)piVar8 + 0x39);
                  }
                  if (((local_ac == local_b0[1]) || ((int)bfsWave < local_ac[4])) ||
                     ((bfsWave == (int *)local_ac[4] && (coastToken < *(ushort *)(local_ac + 5)))))
                  {
                    local_100 = local_b0;
                    local_fc = local_b0[1];
                    pppiVar12 = &local_100;
                  }
                  else {
                    pppiVar12 = &local_b0;
                  }
                  ppiVar7 = pppiVar12[1];
                  if ((*pppiVar12 == (int **)0x0) || (*pppiVar12 != ppiVar9)) {
                    FUN_0047a948();
                  }
                  if (ppiVar7 == local_f4) {
                    local_150 = bfsWave;
                    local_14c = uVar4;
                    ppiVar9 = local_128;
                    puVar18 = local_148;
                    for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                      *puVar18 = *ppiVar9;
                      ppiVar9 = ppiVar9 + 1;
                      puVar18 = puVar18 + 1;
                    }
                    ppiVar9 = &local_150;
                    ppvVar23 = local_6c;
                    ppiVar7 = g_BuildCandidateList(&DAT_00bc1e1c,&local_174);
                    SortedList_Insert(ppiVar7,ppvVar23,ppiVar9);
                    local_150 = local_174;
                    local_14c = local_170;
                    ppiVar9 = local_128;
                    puVar18 = local_148;
                    for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
                      *puVar18 = *ppiVar9;
                      ppiVar9 = ppiVar9 + 1;
                      puVar18 = puVar18 + 1;
                    }
                    SortedList_Insert(reachCandidates,&local_f0,&local_150);
                  }
                  FUN_0040f400((int *)&local_18c);
                }
              }
              FUN_0040f7f0((int *)&local_1a4);
            }
            local_1a8 = (int *)((int)local_1a8 + 1);
          } while ((int)local_1a8 < 0xb);
        }
        FUN_00401590(&local_158);
      }
      iVar13 = *(int *)(local_190 + 8);
      local_16c = (int *)((int)piVar17 + 1);
    } while ((int)piVar17 + 1 < *(int *)(iVar13 + 0x2400));
  }
  local_c = local_c & 0xffffff00;
  FUN_0041aa20(freeDestinations,&local_f8,freeDestinations,(int **)*fleetChainList,freeDestinations,
               fleetChainList);
  _free(fleetChainList);
  fleetChainList = (int **)0x0;
  local_178 = 0;
  local_c = 0xffffffff;
  FUN_0041aa20(reachCandidates,&local_f8,reachCandidates,(int **)*armyReachList,reachCandidates,
               armyReachList);
  _free(armyReachList);
  ExceptionList = local_14;
  return;
}

