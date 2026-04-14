
void __thiscall BuildSupportProposals(void *this,int param_1)

{
  int iVar1;
  undefined *puVar2;
  int **ppiVar3;
  int iVar4;
  int iVar5;
  int **ppiVar6;
  undefined4 *puVar7;
  void **ppvVar8;
  uint **ppuVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int local_1ec;
  byte local_1e5;
  int local_1e4;
  int local_1dc;
  int local_1d8;
  void *local_1d4;
  int **local_1d0;
  int *local_1cc;
  int local_1c8;
  int *local_1c4;
  int local_1bc;
  int local_1b8;
  int local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  undefined4 local_19c;
  void *local_198 [4];
  int local_188;
  int local_184;
  void *local_180 [5];
  int *local_16c;
  void *local_168 [5];
  int *local_154;
  int local_14c;
  int local_144;
  int local_13c;
  int local_138;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  int local_128;
  int local_124;
  undefined4 local_120;
  void *local_11c [4];
  int local_10c;
  undefined4 local_108;
  undefined4 local_104;
  int local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4;
  void *local_f0 [4];
  void *local_e0 [4];
  void *local_d0 [4];
  uint *local_c0 [4];
  int local_b0 [2];
  int local_a8 [2];
  void *local_a0 [3];
  void *local_94 [3];
  int local_88 [4];
  undefined4 local_78;
  int local_6c;
  int local_68;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_004975d0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_1d4 = this;
  FUN_00465870(local_198);
  local_c = 0;
  FUN_004064f0((int)local_88);
  local_c._0_1_ = 1;
  FUN_00465870(local_168);
  local_c._0_1_ = 2;
  FUN_00465870(local_180);
  local_184 = **(int **)(*(int *)((int)this + 8) + 0x2454);
  local_188 = *(int *)((int)this + 8) + 0x2450;
  local_c = CONCAT31(local_c._1_3_,3);
  do {
    iVar12 = local_184;
    iVar4 = local_188;
    local_13c = *(int *)(*(int *)((int)this + 8) + 0x2454);
    if ((local_188 == 0) || (local_188 != *(int *)((int)this + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar12 == local_13c) {
      local_c._0_1_ = 2;
      FreeList(local_180);
      local_c._0_1_ = 1;
      FreeList(local_168);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_00406440((int)local_88);
      local_c = 0xffffffff;
      FreeList(local_198);
      ExceptionList = local_14;
      return;
    }
    if (iVar4 == 0) {
      FUN_0047a948();
    }
    if (iVar12 == *(int *)(iVar4 + 4)) {
      FUN_0047a948();
    }
    if (*(int *)(iVar12 + 0x18) == param_1) {
      if (iVar12 == *(int *)(iVar4 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar12 + 0x20) != 0) {
        if (iVar12 == *(int *)(iVar4 + 4)) {
          FUN_0047a948();
        }
        iVar1 = *(int *)(iVar12 + 0xc);
        if (iVar12 == *(int *)(iVar4 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar12 + 0x20) == 2) {
LAB_0043e4be:
          if (iVar12 == *(int *)(iVar4 + 4)) {
            FUN_0047a948();
          }
          iVar4 = *(int *)(iVar12 + 0x24);
          local_1e5 = 1;
        }
        else {
          if (iVar12 == *(int *)(iVar4 + 4)) {
            FUN_0047a948();
          }
          if (*(int *)(iVar12 + 0x20) == 6) goto LAB_0043e4be;
          local_1e5 = 0;
          iVar4 = iVar1;
        }
        local_1e4 = *(int *)((int)this + 8);
        local_1b4 = (&g_ProvinceBaseScore)[iVar4 * 0x1e];
        iVar11 = 0;
        iVar12 = 0;
        local_1ec = 0;
        if (0 < *(int *)(local_1e4 + 0x2404)) {
          piVar10 = &g_ThreatScore + iVar4;
          do {
            if (iVar11 != param_1) {
              iVar5 = *piVar10;
              if (0 < piVar10[0x1500]) {
                iVar5 = iVar5 - piVar10[0x1500];
              }
              if (iVar12 < iVar5) {
                iVar12 = iVar5;
              }
              if (0 < iVar5) {
                local_1ec = local_1ec + 1;
              }
            }
            iVar11 = iVar11 + 1;
            piVar10 = piVar10 + 0x100;
          } while (iVar11 < *(int *)(local_1e4 + 0x2404));
          if (local_1ec < 2) {
            if (((0 < local_1ec) && ((&DAT_00baedf0)[iVar1 * 0x1e] == 5)) && (DAT_00baed68 == '\0'))
            {
              local_1d8 = **(int **)(local_1e4 + 0x2454);
              local_1dc = local_1e4 + 0x2450;
              while( true ) {
                iVar5 = local_1d8;
                iVar11 = local_1dc;
                iVar12 = *(int *)(*(int *)((int)local_1d4 + 8) + 0x2454);
                if ((local_1dc == 0) || (local_1dc != *(int *)((int)local_1d4 + 8) + 0x2450)) {
                  FUN_0047a948();
                }
                if (iVar5 == iVar12) break;
                if (iVar11 == 0) {
                  FUN_0047a948();
                }
                if (iVar5 == *(int *)(iVar11 + 4)) {
                  FUN_0047a948();
                }
                if (*(int *)(iVar5 + 0x18) != param_1) {
                  if (iVar5 == *(int *)(iVar11 + 4)) {
                    FUN_0047a948();
                    if (iVar5 == *(int *)(iVar11 + 4)) {
                      FUN_0047a948();
                    }
                  }
                  ppiVar6 = AdjacencyList_FilterByUnitType
                                      ((void *)(*(int *)((int)local_1d4 + 8) + 8 +
                                               *(int *)(iVar5 + 0xc) * 0x24),
                                       (ushort *)(iVar5 + 0x14));
                  local_1cc = (int *)*ppiVar6[1];
                  local_1d0 = ppiVar6;
LAB_0043eb30:
                  do {
                    ppiVar3 = local_1d0;
                    local_154 = ppiVar6[1];
                    if ((local_1d0 == (int **)0x0) || (local_1d0 != ppiVar6)) {
                      FUN_0047a948();
                    }
                    if (local_1cc == local_154) break;
                    if (ppiVar3 == (int **)0x0) {
                      FUN_0047a948();
                    }
                    if (local_1cc == ppiVar3[1]) {
                      FUN_0047a948();
                    }
                    if (local_1cc[3] == iVar4) {
                      if (iVar5 == *(int *)(local_1dc + 4)) {
                        FUN_0047a948();
                      }
                      iVar12 = (*(int *)(iVar5 + 0xc) * 1000 + iVar1) * 1000 + iVar4;
                      local_1b8 = iVar12;
                      puVar7 = (undefined4 *)FUN_00410910(&g_ProposalHistoryMap,local_b0,&local_1b8)
                      ;
                      puVar2 = (undefined *)*puVar7;
                      local_1bc = puVar7[1];
                      local_14c = DAT_00baed98;
                      if ((puVar2 == (undefined *)0x0) || (puVar2 != &g_ProposalHistoryMap)) {
                        FUN_0047a948();
                      }
                      if (local_1bc != local_14c) {
                        if (puVar2 == (undefined *)0x0) {
                          FUN_0047a948();
                        }
                        if (local_1bc == *(int *)(puVar2 + 4)) {
                          FUN_0047a948();
                        }
                        *(int *)(local_1bc + 0x24) = *(int *)(local_1bc + 0x24) + 1;
                        FUN_0040f400((int *)&local_1d0);
                        goto LAB_0043eb30;
                      }
                      FUN_00465f30(local_e0,&SUB);
                      local_c._0_1_ = 7;
                      AppendList(local_180,local_e0);
                      local_c = CONCAT31(local_c._1_3_,3);
                      FreeList(local_e0);
                      iVar11 = local_1dc;
                      if (iVar5 == *(int *)(local_1dc + 4)) {
                        FUN_0047a948();
                      }
                      local_1ac = *(undefined4 *)(iVar5 + 0xc);
                      if (iVar5 == *(int *)(iVar11 + 4)) {
                        FUN_0047a948();
                      }
                      local_1b0 = *(undefined4 *)(iVar5 + 0x18);
                      local_1a8 = param_1;
                      local_19c = 1;
                      AppendList(local_198,local_180);
                      local_134 = local_1b0;
                      local_130 = local_1ac;
                      local_12c = local_1a8;
                      local_120 = local_19c;
                      local_1a4 = iVar1;
                      local_1a0 = iVar4;
                      local_138 = iVar12;
                      local_128 = iVar1;
                      local_124 = iVar4;
                      FUN_00465f60(local_11c,local_198);
                      local_c._0_1_ = 8;
                      FUN_00419240(&g_ProposalHistoryMap,local_a0,&local_138);
                      local_c = CONCAT31(local_c._1_3_,3);
                      FreeList(local_11c);
                      if (iVar5 == *(int *)(local_1dc + 4)) {
                        FUN_0047a948();
                      }
                      (&g_PressSentMatrix)[param_1 + *(int *)(iVar5 + 0x18) * 0x15] = 1;
                    }
                    FUN_0040f400((int *)&local_1d0);
                  } while( true );
                }
                UnitList_Advance(&local_1dc);
              }
            }
          }
          else {
            local_1c4 = &g_ProximityScore + iVar4;
            local_1ec = 0;
            do {
              iVar12 = local_1c4[-0x1500];
              if (0 < *local_1c4) {
                iVar12 = iVar12 - *local_1c4;
              }
              if (((local_1ec != param_1) && (0 < iVar12)) &&
                 ((int)(local_1b4 - (uint)local_1e5) < iVar12)) {
                if ((int)(&DAT_00634e90)[param_1 * 0x15 + local_1ec] < 0xf) {
                  if ((((&DAT_004d2610)[iVar4 * 2] == param_1) &&
                      ((&DAT_004d2614)[iVar4 * 2] == param_1 >> 0x1f)) &&
                     ((iVar4 == iVar1 && (local_1b4 < iVar12)))) {
                    local_1c8 = 8;
                  }
                  else {
                    local_1c8 = 4;
                  }
                }
                else {
                  local_1c8 = 1;
                }
                local_1d8 = **(int **)(local_1e4 + 0x2454);
                local_1dc = local_1e4 + 0x2450;
                while( true ) {
                  iVar5 = local_1d8;
                  iVar11 = local_1dc;
                  iVar12 = *(int *)(*(int *)((int)local_1d4 + 8) + 0x2454);
                  if ((local_1dc == 0) || (local_1dc != *(int *)((int)local_1d4 + 8) + 0x2450)) {
                    FUN_0047a948();
                  }
                  if (iVar5 == iVar12) break;
                  if (iVar11 == 0) {
                    FUN_0047a948();
                  }
                  if (iVar5 == *(int *)(iVar11 + 4)) {
                    FUN_0047a948();
                  }
                  if (*(int *)(iVar5 + 0x18) != param_1) {
                    if (iVar5 == *(int *)(iVar11 + 4)) {
                      FUN_0047a948();
                    }
                    if (*(int *)(iVar5 + 0x18) != local_1ec) {
                      if (iVar5 == *(int *)(iVar11 + 4)) {
                        FUN_0047a948();
                      }
                      if ((*(int *)(iVar5 + 0x18) != (&DAT_004d2610)[iVar4 * 2]) ||
                         (*(int *)(iVar5 + 0x18) >> 0x1f != (&DAT_004d2614)[iVar4 * 2])) {
                        if (iVar5 == *(int *)(iVar11 + 4)) {
                          FUN_0047a948();
                        }
                        if ((*(int *)(iVar5 + 0x18) != (&g_AllyDesignation_A)[iVar4 * 2]) ||
                           (*(int *)(iVar5 + 0x18) >> 0x1f != (&DAT_004d2e14)[iVar4 * 2])) {
                          if (iVar5 == *(int *)(iVar11 + 4)) {
                            FUN_0047a948();
                          }
                          if ((&g_ProvinceBaseScore)[*(int *)(iVar5 + 0xc) * 0x1e] == 0) {
                            if (iVar5 == *(int *)(iVar11 + 4)) {
                              FUN_0047a948();
                              if (iVar5 == *(int *)(iVar11 + 4)) {
                                FUN_0047a948();
                              }
                            }
                            ppiVar6 = AdjacencyList_FilterByUnitType
                                                ((void *)(*(int *)((int)local_1d4 + 8) + 8 +
                                                         *(int *)(iVar5 + 0xc) * 0x24),
                                                 (ushort *)(iVar5 + 0x14));
                            local_1cc = (int *)*ppiVar6[1];
                            local_1d0 = ppiVar6;
LAB_0043e722:
                            do {
                              ppiVar3 = local_1d0;
                              local_16c = ppiVar6[1];
                              if ((local_1d0 == (int **)0x0) || (local_1d0 != ppiVar6)) {
                                FUN_0047a948();
                              }
                              if (local_1cc == local_16c) break;
                              if (ppiVar3 == (int **)0x0) {
                                FUN_0047a948();
                              }
                              if (local_1cc == ppiVar3[1]) {
                                FUN_0047a948();
                              }
                              if (local_1cc[3] == iVar4) {
                                if (iVar5 == *(int *)(local_1dc + 4)) {
                                  FUN_0047a948();
                                }
                                iVar12 = (*(int *)(iVar5 + 0xc) * 1000 + iVar1) * 1000 + iVar4;
                                local_1b8 = iVar12;
                                puVar7 = (undefined4 *)
                                         FUN_00410910(&g_ProposalHistoryMap,local_a8,&local_1b8);
                                puVar2 = (undefined *)*puVar7;
                                local_1bc = puVar7[1];
                                local_144 = DAT_00baed98;
                                if ((puVar2 == (undefined *)0x0) ||
                                   (puVar2 != &g_ProposalHistoryMap)) {
                                  FUN_0047a948();
                                }
                                if (local_1bc != local_144) {
                                  if (puVar2 == (undefined *)0x0) {
                                    FUN_0047a948();
                                  }
                                  if (local_1bc == *(int *)(puVar2 + 4)) {
                                    FUN_0047a948();
                                  }
                                  *(int *)(local_1bc + 0x24) =
                                       *(int *)(local_1bc + 0x24) + local_1c8;
                                  FUN_0040f400((int *)&local_1d0);
                                  goto LAB_0043e722;
                                }
                                if (iVar5 == *(int *)(local_1dc + 4)) {
                                  FUN_0047a948();
                                }
                                FUN_0042e120(local_88,(undefined4 *)(iVar5 + 0x10));
                                if (iVar1 == iVar4) {
                                  local_78 = 3;
                                }
                                else {
                                  local_78 = 4;
                                  local_68 = iVar4;
                                }
                                local_6c = iVar1;
                                ppvVar8 = (void **)FUN_00463690(*(void **)((int)local_1d4 + 8),
                                                                local_d0,local_88);
                                local_c._0_1_ = 4;
                                AppendList(local_168,ppvVar8);
                                local_c._0_1_ = 3;
                                FreeList(local_d0);
                                ppuVar9 = FUN_00466f80(&XDO,local_c0,local_168);
                                local_c._0_1_ = 5;
                                AppendList(local_180,ppuVar9);
                                local_c = CONCAT31(local_c._1_3_,3);
                                FreeList(local_c0);
                                iVar11 = local_1dc;
                                if (iVar5 == *(int *)(local_1dc + 4)) {
                                  FUN_0047a948();
                                }
                                local_1ac = *(undefined4 *)(iVar5 + 0xc);
                                if (iVar5 == *(int *)(iVar11 + 4)) {
                                  FUN_0047a948();
                                }
                                local_1b0 = *(undefined4 *)(iVar5 + 0x18);
                                local_1a8 = param_1;
                                local_19c = 1;
                                AppendList(local_198,local_180);
                                local_108 = local_1b0;
                                local_104 = local_1ac;
                                local_100 = local_1a8;
                                local_f4 = local_19c;
                                local_1a4 = iVar1;
                                local_1a0 = iVar4;
                                local_10c = iVar12;
                                local_fc = iVar1;
                                local_f8 = iVar4;
                                FUN_00465f60(local_f0,local_198);
                                local_c._0_1_ = 6;
                                FUN_00419240(&g_ProposalHistoryMap,local_94,&local_10c);
                                local_c = CONCAT31(local_c._1_3_,3);
                                FreeList(local_f0);
                                if (iVar5 == *(int *)(local_1dc + 4)) {
                                  FUN_0047a948();
                                }
                                (&g_PressSentMatrix)[param_1 + *(int *)(iVar5 + 0x18) * 0x15] = 1;
                              }
                              FUN_0040f400((int *)&local_1d0);
                            } while( true );
                          }
                        }
                      }
                    }
                  }
                  UnitList_Advance(&local_1dc);
                }
              }
              local_1e4 = *(int *)((int)local_1d4 + 8);
              local_1c4 = local_1c4 + 0x100;
              local_1ec = local_1ec + 1;
            } while (local_1ec < *(int *)(local_1e4 + 0x2404));
          }
        }
      }
    }
    UnitList_Advance(&local_188);
    this = local_1d4;
  } while( true );
}

