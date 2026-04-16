
/* WARNING: Removing unreachable block (ram,0x00434d30) */
/* WARNING: Removing unreachable block (ram,0x00434c63) */
/* WARNING: Removing unreachable block (ram,0x00434e75) */

void __fastcall SnapshotProvinceState(int param_1)

{
  int *piVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int **ppiVar7;
  void *_Src;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int **ppiVar11;
  _AFX_AYGSHELL_STATE *this;
  undefined4 *puVar12;
  rsize_t _DstSize;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  int iStack_460;
  int iStack_45c;
  uint uStack_454;
  int iStack_450;
  int iStack_44c;
  uint uStack_448;
  int iStack_444;
  int iStack_440;
  int *piStack_43c;
  int **ppiStack_438;
  int *piStack_434;
  int iStack_430;
  void *pvStack_42c;
  uint local_428;
  undefined4 auStack_424 [3];
  int aiStack_418 [257];
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_00497216;
  local_14 = ExceptionList;
  uVar8 = DAT_004c8db8 ^ (uint)&stack0xfffffb88;
  ExceptionList = &local_14;
  local_428 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  bVar6 = false;
  bVar5 = false;
  piVar9 = FUN_0047020b();
  if (piVar9 == (int *)0x0) {
    piVar9 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar10 = (**(code **)(*piVar9 + 0xc))(uVar8);
  pvStack_42c = (void *)(iVar10 + 0x10);
  iVar10 = 0;
  iStack_c = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    do {
      (&DAT_004d2610)[iVar10 * 2] = 0xffffffff;
      (&DAT_004d2614)[iVar10 * 2] = 0xffffffff;
      (&g_AllyDesignation_A)[iVar10 * 2] = 0xffffffff;
      (&DAT_004d2e14)[iVar10 * 2] = 0xffffffff;
      (&DAT_004d3610)[iVar10 * 2] = 0xffffffff;
      (&DAT_004d3614)[iVar10 * 2] = 0xffffffff;
      (&DAT_004d3e10)[iVar10 * 2] = 0xffffffff;
      (&DAT_004d3e14)[iVar10 * 2] = 0xffffffff;
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  iVar14 = 0;
  iVar10 = *(int *)(param_1 + 8);
  iVar13 = 0;
  if (0 < *(int *)(iVar10 + 0x2400)) {
    do {
      if (*(char *)(iVar10 + 3 + iVar14) != '\0') {
        uVar2 = *(ushort *)(iVar10 + 0x20 + iVar14);
        uVar8 = uVar2 & 0xff;
        if ((char)(uVar2 >> 8) != 'A') {
          uVar8 = 0x14;
        }
        (&DAT_004d3610)[iVar13 * 2] = 0xfffffffe;
        (&DAT_004d3614)[iVar13 * 2] = 0xffffffff;
        if (uVar8 != 0x14) {
          (&DAT_004d2610)[iVar13 * 2] = uVar8;
          (&DAT_004d2614)[iVar13 * 2] = 0;
        }
      }
      iVar10 = *(int *)(param_1 + 8);
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + 0x24;
    } while (iVar13 < *(int *)(iVar10 + 0x2400));
  }
  iStack_44c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  iStack_450 = *(int *)(param_1 + 8) + 0x2450;
  while( true ) {
    iVar14 = iStack_44c;
    iVar13 = iStack_450;
    iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((iStack_450 == 0) || (iStack_450 != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar14 == iVar10) break;
    if (iVar13 == 0) {
      FUN_0047a948();
    }
    if ((iVar14 == *(int *)(iVar13 + 4)) && (FUN_0047a948(), iVar14 == *(int *)(iVar13 + 4))) {
      FUN_0047a948();
    }
    iVar10 = *(int *)(iVar14 + 0x18);
    iVar13 = *(int *)(iVar14 + 0x10);
    (&g_AllyDesignation_A)[iVar13 * 2] = iVar10;
    (&DAT_004d2e14)[iVar13 * 2] = iVar10 >> 0x1f;
    UnitList_Advance(&iStack_450);
  }
  if (DAT_00baed69 == '\0') {
    iVar10 = *(int *)(param_1 + 8);
    iStack_444 = 0;
    if (0 < *(int *)(iVar10 + 0x2400)) {
      iStack_460 = 0;
      iVar13 = param_1 + 0x2a1c;
      do {
        if (((*(char *)(iVar10 + 3 + iStack_460) != '\0') &&
            (uVar2 = *(ushort *)(iVar10 + 0x20 + iStack_460), (char)(uVar2 >> 8) == 'A')) &&
           (uVar8 = uVar2 & 0xff, uVar8 != 0x14)) {
          piStack_43c = (int *)**(undefined4 **)(iVar13 + 4);
          iStack_440 = iVar13;
          while( true ) {
            piVar1 = piStack_43c;
            iVar10 = iStack_440;
            piVar9 = *(int **)(iVar13 + 4);
            if ((iStack_440 == 0) || (iStack_440 != iVar13)) {
              FUN_0047a948();
            }
            if (piVar1 == piVar9) break;
            if (iVar10 == 0) {
              FUN_0047a948();
            }
            if (piVar1 == *(int **)(iVar10 + 4)) {
              FUN_0047a948();
            }
            if (((&DAT_004d3610)[piVar1[3] * 2] & (&DAT_004d3614)[piVar1[3] * 2]) == 0xffffffff) {
              if (piVar1 == *(int **)(iVar10 + 4)) {
                FUN_0047a948();
              }
              iVar10 = piVar1[3];
              (&DAT_004d3610)[iVar10 * 2] = uVar8;
              (&DAT_004d3614)[iVar10 * 2] = 0;
              TreeIterator_Advance(&iStack_440);
            }
            else {
              if (piVar1 == *(int **)(iVar10 + 4)) {
                FUN_0047a948();
              }
              if (((&DAT_004d3610)[piVar1[3] * 2] & (&DAT_004d3614)[piVar1[3] * 2]) != 0xffffffff) {
                if (piVar1 == *(int **)(iVar10 + 4)) {
                  FUN_0047a948();
                }
                if (((&DAT_004d3610)[piVar1[3] * 2] != uVar8) ||
                   ((&DAT_004d3614)[piVar1[3] * 2] != 0)) {
                  if (piVar1 == *(int **)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  iVar10 = piVar1[3];
                  (&DAT_004d3610)[iVar10 * 2] = 0xfffffffe;
                  (&DAT_004d3614)[iVar10 * 2] = 0xffffffff;
                }
              }
              TreeIterator_Advance(&iStack_440);
            }
          }
        }
        iVar10 = *(int *)(param_1 + 8);
        iStack_444 = iStack_444 + 1;
        iStack_460 = iStack_460 + 0x24;
        iVar13 = iVar13 + 0xc;
      } while (iStack_444 < *(int *)(iVar10 + 0x2400));
    }
    iVar10 = *(int *)(param_1 + 8);
    uStack_454 = 0;
    if (0 < *(int *)(iVar10 + 0x2404)) {
      iStack_45c = 0;
      do {
        iStack_444 = 0;
        if (0 < *(int *)(iVar10 + 0x2400)) {
          iStack_460 = 0;
          iVar13 = param_1 + 0x2a1c;
          do {
            if (*(char *)(iStack_460 + 3 + iVar10) != '\0') {
              uVar2 = *(ushort *)(iStack_460 + 0x20 + iVar10);
              uVar8 = uVar2 & 0xff;
              if ((char)(uVar2 >> 8) != 'A') {
                uVar8 = 0x14;
              }
              if (uVar8 == uStack_454) {
                piStack_43c = (int *)**(undefined4 **)(iVar13 + 4);
                iStack_440 = iVar13;
                while( true ) {
                  piVar1 = piStack_43c;
                  iVar10 = iStack_440;
                  piVar9 = *(int **)(iVar13 + 4);
                  if ((iStack_440 == 0) || (iStack_440 != iVar13)) {
                    FUN_0047a948();
                  }
                  if (piVar1 == piVar9) break;
                  if (iVar10 == 0) {
                    FUN_0047a948();
                  }
                  if (piVar1 == *(int **)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  if (*(char *)(*(int *)(param_1 + 8) + 3 + piVar1[3] * 0x24) == '\0') {
                    if (piVar1 == *(int **)(iVar10 + 4)) {
                      FUN_0047a948();
                    }
                    iVar10 = piVar1[3];
                    (&g_TargetFlag)[(iVar10 + iStack_45c) * 2] = 1;
                    (&DAT_005e40ec)[(iVar10 + iStack_45c) * 2] = 0;
                  }
                  TreeIterator_Advance(&iStack_440);
                }
              }
            }
            iVar10 = *(int *)(param_1 + 8);
            iStack_460 = iStack_460 + 0x24;
            iStack_444 = iStack_444 + 1;
            iVar13 = iVar13 + 0xc;
          } while (iStack_444 < *(int *)(iVar10 + 0x2400));
        }
        iVar10 = *(int *)(param_1 + 8);
        iStack_45c = iStack_45c + 0x100;
        uStack_454 = uStack_454 + 1;
      } while ((int)uStack_454 < *(int *)(iVar10 + 0x2404));
    }
    iVar13 = *(int *)(param_1 + 8);
    iVar10 = *(int *)(iVar13 + 0x2404);
    uStack_454 = 0;
    if (0 < iVar10) {
      iStack_460 = 0;
      iStack_45c = 0;
      do {
        uStack_448 = 0;
        if (0 < iVar10) {
          do {
            if (uStack_454 != uStack_448) {
              if ((-1 < (int)(&g_AllyTrustScore_Hi)[(uStack_448 + iStack_45c) * 2]) &&
                 (((0 < (int)(&g_AllyTrustScore_Hi)[(uStack_448 + iStack_45c) * 2] ||
                   (1 < (uint)(&g_AllyTrustScore)[(uStack_448 + iStack_45c) * 2])) &&
                  (iStack_444 = 0, 0 < *(int *)(iVar13 + 0x2400))))) {
                iStack_430 = 0;
                iVar10 = param_1 + 0x2a1c;
                do {
                  if (*(char *)(iStack_430 + 3 + iVar13) != '\0') {
                    uVar2 = *(ushort *)(iStack_430 + 0x20 + iVar13);
                    uVar8 = uVar2 & 0xff;
                    if ((char)(uVar2 >> 8) != 'A') {
                      uVar8 = 0x14;
                    }
                    if (uVar8 == uStack_448) {
                      piStack_43c = (int *)**(undefined4 **)(iVar10 + 4);
                      iStack_440 = iVar10;
                      while( true ) {
                        piVar1 = piStack_43c;
                        iVar13 = iStack_440;
                        piVar9 = *(int **)(iVar10 + 4);
                        if ((iStack_440 == 0) || (iStack_440 != iVar10)) {
                          FUN_0047a948();
                        }
                        if (piVar1 == piVar9) break;
                        if (iVar13 == 0) {
                          FUN_0047a948();
                        }
                        if (piVar1 == *(int **)(iVar13 + 4)) {
                          FUN_0047a948();
                        }
                        if (((&g_TargetFlag)[(piVar1[3] + iStack_460) * 2] == 1) &&
                           ((&DAT_005e40ec)[(piVar1[3] + iStack_460) * 2] == 0)) {
                          if (piVar1 == *(int **)(iVar13 + 4)) {
                            FUN_0047a948();
                          }
                          iVar13 = piVar1[3];
                          (&g_TargetFlag)[(iVar13 + iStack_460) * 2] = 2;
                          (&DAT_005e40ec)[(iVar13 + iStack_460) * 2] = 0;
                        }
                        TreeIterator_Advance(&iStack_440);
                      }
                    }
                  }
                  iVar13 = *(int *)(param_1 + 8);
                  iStack_444 = iStack_444 + 1;
                  iStack_430 = iStack_430 + 0x24;
                  iVar10 = iVar10 + 0xc;
                } while (iStack_444 < *(int *)(iVar13 + 0x2400));
              }
            }
            iVar13 = *(int *)(param_1 + 8);
            uStack_448 = uStack_448 + 1;
          } while ((int)uStack_448 < *(int *)(iVar13 + 0x2404));
        }
        iVar13 = *(int *)(param_1 + 8);
        iVar10 = *(int *)(iVar13 + 0x2404);
        iStack_45c = iStack_45c + 0x15;
        iStack_460 = iStack_460 + 0x100;
        uStack_454 = uStack_454 + 1;
      } while ((int)uStack_454 < iVar10);
    }
    iVar13 = *(int *)(param_1 + 8);
    iVar10 = *(int *)(iVar13 + 0x2404);
    uStack_454 = 0;
    if (0 < iVar10) {
      iStack_460 = 0;
      iStack_45c = 0;
      do {
        uStack_448 = 0;
        if (0 < iVar10) {
          do {
            if (uStack_454 != uStack_448) {
              if (((int)(&g_AllyTrustScore_Hi)[(iStack_45c + uStack_448) * 2] < 1) &&
                 ((((int)(&g_AllyTrustScore_Hi)[(iStack_45c + uStack_448) * 2] < 0 ||
                   ((uint)(&g_AllyTrustScore)[(iStack_45c + uStack_448) * 2] < 2)) &&
                  (iStack_444 = 0, 0 < *(int *)(iVar13 + 0x2400))))) {
                iStack_430 = 0;
                iVar10 = param_1 + 0x2a1c;
                do {
                  if (*(char *)(iStack_430 + 3 + iVar13) != '\0') {
                    uVar2 = *(ushort *)(iStack_430 + 0x20 + iVar13);
                    uVar8 = uVar2 & 0xff;
                    if ((char)(uVar2 >> 8) != 'A') {
                      uVar8 = 0x14;
                    }
                    if (uVar8 == uStack_448) {
                      piStack_43c = (int *)**(undefined4 **)(iVar10 + 4);
                      iStack_440 = iVar10;
                      while( true ) {
                        piVar1 = piStack_43c;
                        iVar13 = iStack_440;
                        piVar9 = *(int **)(iVar10 + 4);
                        if ((iStack_440 == 0) || (iStack_440 != iVar10)) {
                          FUN_0047a948();
                        }
                        if (piVar1 == piVar9) break;
                        if (iVar13 == 0) {
                          FUN_0047a948();
                        }
                        if (piVar1 == *(int **)(iVar13 + 4)) {
                          FUN_0047a948();
                        }
                        if (((&g_TargetFlag)[(piVar1[3] + iStack_460) * 2] == 2) &&
                           ((&DAT_005e40ec)[(piVar1[3] + iStack_460) * 2] == 0)) {
                          if (piVar1 == *(int **)(iVar13 + 4)) {
                            FUN_0047a948();
                          }
                          iVar13 = piVar1[3];
                          (&g_TargetFlag)[(iVar13 + iStack_460) * 2] = 1;
                          (&DAT_005e40ec)[(iVar13 + iStack_460) * 2] = 0;
                        }
                        TreeIterator_Advance(&iStack_440);
                      }
                    }
                  }
                  iVar13 = *(int *)(param_1 + 8);
                  iStack_444 = iStack_444 + 1;
                  iStack_430 = iStack_430 + 0x24;
                  iVar10 = iVar10 + 0xc;
                } while (iStack_444 < *(int *)(iVar13 + 0x2400));
              }
            }
            iVar13 = *(int *)(param_1 + 8);
            uStack_448 = uStack_448 + 1;
          } while ((int)uStack_448 < *(int *)(iVar13 + 0x2404));
        }
        iStack_44c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
        iStack_450 = *(int *)(param_1 + 8) + 0x2450;
        while( true ) {
          iVar14 = iStack_44c;
          iVar13 = iStack_450;
          iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
          if ((iStack_450 == 0) || (iStack_450 != *(int *)(param_1 + 8) + 0x2450)) {
            FUN_0047a948();
          }
          if (iVar14 == iVar10) break;
          if (iVar13 == 0) {
            FUN_0047a948();
          }
          if (iVar14 == *(int *)(iVar13 + 4)) {
            FUN_0047a948();
          }
          if (*(uint *)(iVar14 + 0x18) != uStack_454) {
            if (iVar14 == *(int *)(iVar13 + 4)) {
              FUN_0047a948();
            }
            iVar10 = *(int *)(iVar14 + 0x18) + iStack_45c;
            if (((int)(&g_AllyTrustScore_Hi)[iVar10 * 2] < 1) &&
               (((int)(&g_AllyTrustScore_Hi)[iVar10 * 2] < 0 ||
                ((uint)(&g_AllyTrustScore)[iVar10 * 2] < 2)))) {
              if ((iVar14 == *(int *)(iVar13 + 4)) &&
                 (FUN_0047a948(), iVar14 == *(int *)(iVar13 + 4))) {
                FUN_0047a948();
              }
              ppiVar11 = AdjacencyList_FilterByUnitType
                                   ((void *)(*(int *)(param_1 + 8) + 8 +
                                            *(int *)(iVar14 + 0x10) * 0x24),
                                    (ushort *)(iVar14 + 0x14));
              piStack_434 = (int *)*ppiVar11[1];
              ppiStack_438 = ppiVar11;
              while( true ) {
                piVar1 = piStack_434;
                ppiVar7 = ppiStack_438;
                piVar9 = ppiVar11[1];
                if ((ppiStack_438 == (int **)0x0) || (ppiStack_438 != ppiVar11)) {
                  FUN_0047a948();
                }
                if (piVar1 == piVar9) break;
                if (ppiVar7 == (int **)0x0) {
                  FUN_0047a948();
                }
                if (piVar1 == ppiVar7[1]) {
                  FUN_0047a948();
                }
                iVar10 = piVar1[3];
                (&g_TargetFlag)[(iVar10 + iStack_460) * 2] = 0;
                (&DAT_005e40ec)[(iVar10 + iStack_460) * 2] = 0;
                FUN_0040f400((int *)&ppiStack_438);
              }
            }
          }
          UnitList_Advance(&iStack_450);
        }
        iVar13 = *(int *)(param_1 + 8);
        iVar10 = *(int *)(iVar13 + 0x2404);
        iStack_45c = iStack_45c + 0x15;
        iStack_460 = iStack_460 + 0x100;
        uStack_454 = uStack_454 + 1;
      } while ((int)uStack_454 < iVar10);
    }
  }
  if ((g_DeceitLevel < 2) && (DAT_00baed45 == '\x01')) {
    iStack_450 = *(int *)(param_1 + 8);
    iVar10 = *(int *)(iStack_450 + 0x2400);
    if (0 < iVar10) {
      piVar9 = aiStack_418;
      for (; iVar10 != 0; iVar10 = iVar10 + -1) {
        *piVar9 = -1;
        piVar9 = piVar9 + 1;
      }
    }
    iStack_44c = **(int **)(iStack_450 + 0x2454);
    iStack_450 = iStack_450 + 0x2450;
    while( true ) {
      iVar14 = iStack_44c;
      iVar13 = iStack_450;
      iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
      if ((iStack_450 == 0) || (iStack_450 != *(int *)(param_1 + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (iVar14 == iVar10) break;
      if (iVar13 == 0) {
        FUN_0047a948();
      }
      if (iVar14 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      if (*(uint *)(iVar14 + 0x18) == local_428) {
        if ((iVar14 == *(int *)(iVar13 + 4)) && (FUN_0047a948(), iVar14 == *(int *)(iVar13 + 4))) {
          FUN_0047a948();
        }
        ppiVar11 = AdjacencyList_FilterByUnitType
                             ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar14 + 0x10) * 0x24),
                              (ushort *)(iVar14 + 0x14));
        piStack_434 = (int *)*ppiVar11[1];
        ppiStack_438 = ppiVar11;
        while( true ) {
          piVar1 = piStack_434;
          ppiVar7 = ppiStack_438;
          piVar9 = ppiVar11[1];
          if ((ppiStack_438 == (int **)0x0) || (ppiStack_438 != ppiVar11)) {
            FUN_0047a948();
          }
          if (piVar1 == piVar9) break;
          if (ppiVar7 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar1 == ppiVar7[1]) {
            FUN_0047a948();
          }
          if (aiStack_418[piVar1[3]] == -1) {
            if (piVar1 == ppiVar7[1]) {
              FUN_0047a948();
            }
            aiStack_418[piVar1[3]] = 0;
            FUN_0040f400((int *)&ppiStack_438);
          }
          else {
            if (piVar1 == ppiVar7[1]) {
              FUN_0047a948();
            }
            aiStack_418[piVar1[3]] = -10;
            FUN_0040f400((int *)&ppiStack_438);
          }
        }
      }
      UnitList_Advance(&iStack_450);
    }
    iStack_44c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
    iStack_450 = *(int *)(param_1 + 8) + 0x2450;
    while( true ) {
      iVar14 = iStack_44c;
      iVar13 = iStack_450;
      bVar4 = false;
      iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
      if ((iStack_450 == 0) || (iStack_450 != *(int *)(param_1 + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (iVar14 == iVar10) break;
      if (iVar13 == 0) {
        FUN_0047a948();
      }
      if (iVar14 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      if (*(uint *)(iVar14 + 0x18) == local_428) {
        if (iVar14 == *(int *)(iVar13 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(*(int *)(param_1 + 8) + 3 + *(int *)(iVar14 + 0x10) * 0x24) == '\0') {
          bVar4 = false;
        }
        else {
          bVar5 = true;
          if (iVar14 == *(int *)(iVar13 + 4)) {
            FUN_0047a948();
          }
          bVar4 = true;
        }
        if (bVar5) {
          bVar5 = false;
        }
        if (bVar4) {
          if ((iVar14 == *(int *)(iVar13 + 4)) && (FUN_0047a948(), iVar14 == *(int *)(iVar13 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar11 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar14 + 0x10) * 0x24)
                                ,(ushort *)(iVar14 + 0x14));
          piStack_434 = (int *)*ppiVar11[1];
          ppiStack_438 = ppiVar11;
          while( true ) {
            piVar1 = piStack_434;
            ppiVar7 = ppiStack_438;
            piVar9 = ppiVar11[1];
            if ((ppiStack_438 == (int **)0x0) || (ppiStack_438 != ppiVar11)) {
              FUN_0047a948();
            }
            if (piVar1 == piVar9) break;
            if (ppiVar7 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar1 == ppiVar7[1]) {
              FUN_0047a948();
            }
            if (*(char *)(*(int *)(param_1 + 8) + 3 + piVar1[3] * 0x24) == '\0') {
              bVar4 = false;
            }
            else {
              bVar6 = true;
              if (piVar1 == ppiVar7[1]) {
                FUN_0047a948();
              }
              bVar4 = true;
            }
            if (bVar6) {
              bVar6 = false;
            }
            if (bVar4) {
              if (piVar1 == ppiVar7[1]) {
                FUN_0047a948();
              }
              if (aiStack_418[piVar1[3]] == 0) {
                if (piVar1 == ppiVar7[1]) {
                  FUN_0047a948();
                }
                aiStack_418[piVar1[3]] = 1;
              }
            }
            FUN_0040f400((int *)&ppiStack_438);
          }
        }
      }
      UnitList_Advance(&iStack_450);
    }
    iStack_44c = **(int **)(*(int *)(param_1 + 8) + 0x2454);
    iStack_450 = *(int *)(param_1 + 8) + 0x2450;
    while( true ) {
      iVar14 = iStack_44c;
      iVar13 = iStack_450;
      iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
      if ((iStack_450 == 0) || (iStack_450 != *(int *)(param_1 + 8) + 0x2450)) {
        FUN_0047a948();
      }
      if (iVar14 == iVar10) break;
      if (iVar13 == 0) {
        FUN_0047a948();
      }
      if (iVar14 == *(int *)(iVar13 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar14 + 0x18) == DAT_004c6bc4) {
        if (iVar14 == *(int *)(iVar13 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(*(int *)(param_1 + 8) + 3 + *(int *)(iVar14 + 0x10) * 0x24) == '\0') {
LAB_00434e80:
          bVar5 = true;
        }
        else {
          if (iVar14 == *(int *)(iVar13 + 4)) {
            FUN_0047a948();
          }
          if (*(char *)(*(int *)(param_1 + 8) + 3 + *(int *)(iVar14 + 0x10) * 0x24) == '\x01') {
            bVar4 = true;
            if (iVar14 == *(int *)(iVar13 + 4)) {
              FUN_0047a948();
            }
            goto LAB_00434e80;
          }
          bVar5 = false;
        }
        if (bVar4) {
          bVar4 = false;
        }
        if (bVar5) {
          if ((iVar14 == *(int *)(iVar13 + 4)) && (FUN_0047a948(), iVar14 == *(int *)(iVar13 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar11 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)(param_1 + 8) + 8 + *(int *)(iVar14 + 0x10) * 0x24)
                                ,(ushort *)(iVar14 + 0x14));
          piStack_434 = (int *)*ppiVar11[1];
          ppiStack_438 = ppiVar11;
          while( true ) {
            piVar1 = piStack_434;
            ppiVar7 = ppiStack_438;
            piVar9 = ppiVar11[1];
            if ((ppiStack_438 == (int **)0x0) || (ppiStack_438 != ppiVar11)) {
              FUN_0047a948();
            }
            if (piVar1 == piVar9) break;
            if (ppiVar7 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar1 == ppiVar7[1]) {
              FUN_0047a948();
            }
            if (aiStack_418[piVar1[3]] == 1) {
              if (piVar1 == ppiVar7[1]) {
                FUN_0047a948();
              }
              iVar10 = piVar1[3];
              iVar13 = DAT_004c6bc4 >> 0x1f;
              (&DAT_004d3610)[iVar10 * 2] = DAT_004c6bc4;
              (&DAT_004d3614)[iVar10 * 2] = iVar13;
              if (piVar1 == ppiVar7[1]) {
                FUN_0047a948();
              }
              puVar15 = (ushort *)(*(int *)(param_1 + 8) + piVar1[3] * 0x24);
              this = _AfxAygshellState();
              GetProvinceToken(this,puVar15);
              SEND_LOG(&pvStack_42c,L"We are in a position to share (%s) with our best ally ");
              _Src = pvStack_42c;
              piVar9 = (int *)((int)pvStack_42c + -0x10);
              iStack_440 = 3;
              puVar12 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_42c + -0x10) + 0x10))();
              if ((*(int *)((int)_Src + -4) < 0) || (puVar12 != (undefined4 *)*piVar9)) {
                piVar9 = (int *)(**(code **)*puVar12)(*(undefined4 *)((int)_Src + -0xc),1);
                if (piVar9 == (int *)0x0) {
                  ErrorExit();
                  return;
                }
                piVar9[1] = *(int *)((int)_Src + -0xc);
                _DstSize = *(int *)((int)_Src + -0xc) + 1;
                _memcpy_s(piVar9 + 4,_DstSize,_Src,_DstSize);
              }
              else {
                LOCK();
                *(int *)((int)_Src + -4) = *(int *)((int)_Src + -4) + 1;
                UNLOCK();
              }
              piStack_43c = piVar9 + 4;
              iStack_c._0_1_ = 1;
              BuildAllianceMsg(&DAT_00bbf638,auStack_424,&iStack_440);
              iStack_c = (uint)iStack_c._1_3_ << 8;
              piVar1 = piVar9 + 3;
              LOCK();
              iVar10 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar10 == 1 || iVar10 + -1 < 0) {
                (**(code **)(*(int *)*piVar9 + 4))(piVar9);
              }
            }
            FUN_0040f400((int *)&ppiStack_438);
          }
        }
      }
      UnitList_Advance(&iStack_450);
    }
  }
  sVar3 = *(short *)(*(int *)(param_1 + 8) + 0x244a);
  if (((SPR == sVar3) || (FAL == sVar3)) &&
     (iVar10 = 0, 0 < *(int *)(*(int *)(param_1 + 8) + 0x2400))) {
    do {
      iVar13 = iVar10 * 8;
      (&DAT_004d0e10)[iVar10 * 2] = (&DAT_004d2610)[iVar10 * 2];
      (&DAT_004d0e14)[iVar10 * 2] = (&DAT_004d2614)[iVar10 * 2];
      (&DAT_004d1610)[iVar10 * 2] = (&g_AllyDesignation_A)[iVar10 * 2];
      (&DAT_004d1614)[iVar10 * 2] = (&DAT_004d2e14)[iVar10 * 2];
      (&DAT_004d1e10)[iVar10 * 2] = (&DAT_004d3610)[iVar10 * 2];
      (&DAT_004d1e14)[iVar10 * 2] = (&DAT_004d3614)[iVar10 * 2];
      iVar14 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
        do {
          *(undefined4 *)((int)&DAT_005d98e8 + iVar13) =
               *(undefined4 *)((int)&g_TargetFlag + iVar13);
          *(undefined4 *)((int)&DAT_005d98ec + iVar13) =
               *(undefined4 *)((int)&DAT_005e40ec + iVar13);
          iVar14 = iVar14 + 1;
          iVar13 = iVar13 + 0x800;
        } while (iVar14 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  sVar3 = *(short *)(*(int *)(param_1 + 8) + 0x244a);
  if (((SUM == sVar3) || (AUT == sVar3)) &&
     (iVar10 = 0, 0 < *(int *)(*(int *)(param_1 + 8) + 0x2400))) {
    do {
      (&DAT_004cf610)[iVar10 * 2] = (&DAT_004d2610)[iVar10 * 2];
      (&DAT_004cf614)[iVar10 * 2] = (&DAT_004d2614)[iVar10 * 2];
      (&DAT_004cfe10)[iVar10 * 2] = (&g_AllyDesignation_A)[iVar10 * 2];
      (&DAT_004cfe14)[iVar10 * 2] = (&DAT_004d2e14)[iVar10 * 2];
      (&DAT_004d0610)[iVar10 * 2] = (&DAT_004d3610)[iVar10 * 2];
      (&DAT_004d0614)[iVar10 * 2] = (&DAT_004d3614)[iVar10 * 2];
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  iStack_c = 0xffffffff;
  piVar9 = (int *)((int)pvStack_42c + -4);
  LOCK();
  iVar10 = *piVar9;
  *piVar9 = *piVar9 + -1;
  UNLOCK();
  if (iVar10 == 1 || iVar10 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_42c + -0x10) + 4))
              ((undefined4 *)((int)pvStack_42c + -0x10));
  }
  ExceptionList = local_14;
  return;
}

