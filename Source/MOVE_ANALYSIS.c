
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall MOVE_ANALYSIS(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  void *pvVar3;
  int **ppiVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  int **ppiVar9;
  _AFX_AYGSHELL_STATE *p_Var10;
  undefined4 *puVar11;
  rsize_t rVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  uint *puVar17;
  int iVar18;
  bool bVar19;
  ushort *puVar20;
  undefined4 uStack_bd90;
  int local_bd8c;
  uint uStack_bd88;
  void *pvStack_bd84;
  float fStack_bd80;
  char cStack_bd7a;
  char cStack_bd79;
  int iStack_bd78;
  int iStack_bd74;
  int *piStack_bd70;
  int **ppiStack_bd6c;
  int *piStack_bd68;
  int iStack_bd64;
  int *piStack_bd60;
  uint local_bd5c;
  int iStack_bd58;
  int *piStack_bd54;
  int iStack_bd50;
  undefined4 uStack_bd4c;
  int *piStack_bd48;
  undefined4 auStack_bd40 [3];
  undefined4 auStack_bd34 [3];
  uint auStack_bd28 [22];
  int aiStack_bcd0 [442];
  int aiStack_b5e8 [442];
  int aiStack_af00 [442];
  uint auStack_a818 [10751];
  undefined4 uStack_1c;
  int iStack_18;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_0049728d;
  local_14 = ExceptionList;
  uStack_1c = 0x43522f;
  uVar5 = DAT_004c8db8 ^ (uint)&stack0xffff4260;
  ExceptionList = &local_14;
  local_bd5c = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_bd8c = param_1;
  iStack_18 = param_1;
  piVar6 = FUN_0047020b();
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar7 = (**(code **)(*piVar6 + 0xc))(uVar5);
  pvStack_bd84 = (void *)(iVar7 + 0x10);
  iVar7 = *(int *)(param_1 + 8);
  uVar5 = *(uint *)(iVar7 + 0x2404);
  iStack_c = 0;
  cStack_bd7a = '\0';
  cStack_bd79 = '\0';
  iStack_bd50 = 0;
  uStack_bd88 = 0;
  if (0 < (int)uVar5) {
    uStack_bd90 = &g_AllyTrustScore + local_bd5c * 0x2a;
    iVar16 = 0;
    do {
      uVar13 = uStack_bd90[1];
      uVar14 = *uStack_bd90;
      auStack_bd28[uStack_bd88] = uVar14;
      if (((int)uVar13 < 1) && (((int)uVar13 < 0 || (uVar14 < 3)))) {
        cStack_bd7a = '\x01';
      }
      uStack_bd90 = uStack_bd90 + 2;
      puVar11 = (undefined4 *)((int)aiStack_af00 + iVar16);
      for (uVar13 = uVar5 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      puVar11 = (undefined4 *)((int)aiStack_bcd0 + iVar16);
      for (uVar13 = uVar5 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      puVar11 = (undefined4 *)((int)aiStack_b5e8 + iVar16);
      for (uVar13 = uVar5 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      uStack_bd88 = uStack_bd88 + 1;
      iVar16 = iVar16 + 0x54;
    } while ((int)uStack_bd88 < (int)uVar5);
  }
  uStack_bd88 = 0;
  if (0 < (int)uVar5) {
    do {
      uStack_bd90 = (uint *)0x0;
      if (0 < (int)uVar5) {
        do {
          iVar16 = *(int *)(iVar7 + 0x2400);
          if (0 < iVar16) {
            auStack_a818[uStack_bd88 * 0x200] = 0;
            auStack_a818[uStack_bd88 * 0x200 + 1] = 0;
            puVar8 = auStack_a818 + uStack_bd88 * 0x200;
            puVar17 = auStack_a818 + uStack_bd88 * 0x200 + 2;
            for (uVar5 = iVar16 * 8 - 5U >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar17 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar17 = puVar17 + 1;
            }
          }
          iStack_bd78 = 0;
          if (0 < iVar16) {
            fStack_bd80 = 0.0;
            iVar16 = local_bd8c + 0x2a1c;
            do {
              if (*(char *)((int)fStack_bd80 + 3 + iVar7) != '\0') {
                uVar1 = *(ushort *)((int)fStack_bd80 + 0x20 + iVar7);
                uVar5 = uVar1 & 0xff;
                if ((char)(uVar1 >> 8) != 'A') {
                  uVar5 = 0x14;
                }
                if (uVar5 == uStack_bd88) {
                  piStack_bd54 = (int *)**(undefined4 **)(iVar16 + 4);
                  iStack_bd58 = iVar16;
                  while( true ) {
                    piVar15 = piStack_bd54;
                    iVar7 = iStack_bd58;
                    piVar6 = *(int **)(iVar16 + 4);
                    if ((iStack_bd58 == 0) || (iStack_bd58 != iVar16)) {
                      FUN_0047a948();
                    }
                    if (piVar15 == piVar6) break;
                    if (iVar7 == 0) {
                      FUN_0047a948();
                    }
                    if (piVar15 == *(int **)(iVar7 + 4)) {
                      FUN_0047a948();
                    }
                    if (*(char *)(*(int *)(local_bd8c + 8) + 3 + piVar15[3] * 0x24) == '\0') {
LAB_00435443:
                      if (piVar15 == *(int **)(iVar7 + 4)) {
                        FUN_0047a948();
                      }
                      iVar7 = uStack_bd88 * 0x100 + piVar15[3];
                      auStack_a818[iVar7 * 2] = 1;
                      auStack_a818[iVar7 * 2 + 1] = 0;
                    }
                    else {
                      uVar1 = *(ushort *)((int)fStack_bd80 + 0x20 + *(int *)(local_bd8c + 8));
                      puVar8 = (uint *)(uVar1 & 0xff);
                      if ((char)(uVar1 >> 8) != 'A') {
                        puVar8 = (uint *)0x14;
                      }
                      if (puVar8 != uStack_bd90) goto LAB_00435443;
                    }
                    TreeIterator_Advance(&iStack_bd58);
                  }
                }
              }
              iVar7 = *(int *)(local_bd8c + 8);
              iStack_bd78 = iStack_bd78 + 1;
              fStack_bd80 = (float)((int)fStack_bd80 + 0x24);
              iVar16 = iVar16 + 0xc;
            } while (iStack_bd78 < *(int *)(iVar7 + 0x2400));
          }
          piStack_bd60 = (int *)**(undefined4 **)(*(int *)(local_bd8c + 8) + 0x2490);
          iStack_bd64 = *(int *)(local_bd8c + 8) + 0x248c;
          while( true ) {
            piVar15 = piStack_bd60;
            iVar16 = iStack_bd64;
            iVar7 = local_bd8c;
            piVar6 = *(int **)(*(int *)(local_bd8c + 8) + 0x2490);
            if ((iStack_bd64 == 0) || (iStack_bd64 != *(int *)(local_bd8c + 8) + 0x248c)) {
              FUN_0047a948();
            }
            if (piVar15 == piVar6) break;
            if (iVar16 == 0) {
              FUN_0047a948();
            }
            if (piVar15 == *(int **)(iVar16 + 4)) {
              FUN_0047a948();
            }
            piVar6 = piStack_bd60;
            iVar7 = iStack_bd64;
            if ((uint *)piVar15[6] == uStack_bd90) {
              if ((piStack_bd60 == *(int **)(iStack_bd64 + 4)) &&
                 (FUN_0047a948(), piVar6 == *(int **)(iVar7 + 4))) {
                FUN_0047a948();
              }
              ppiVar9 = AdjacencyList_FilterByUnitType
                                  ((void *)(*(int *)(local_bd8c + 8) + 8 + piStack_bd60[4] * 0x24),
                                   (ushort *)(piStack_bd60 + 5));
              piStack_bd68 = (int *)*ppiVar9[1];
              ppiStack_bd6c = ppiVar9;
              while( true ) {
                piVar15 = piStack_bd68;
                ppiVar4 = ppiStack_bd6c;
                piVar6 = ppiVar9[1];
                if ((ppiStack_bd6c == (int **)0x0) || (ppiStack_bd6c != ppiVar9)) {
                  FUN_0047a948();
                }
                uVar5 = uStack_bd88;
                if (piVar15 == piVar6) break;
                if (ppiVar4 == (int **)0x0) {
                  FUN_0047a948();
                }
                if (piVar15 == ppiVar4[1]) {
                  FUN_0047a948();
                }
                iVar16 = uStack_bd88 * 0x100;
                iVar7 = piVar15[3] + iVar16;
                if ((auStack_a818[iVar7 * 2] == 1) && (auStack_a818[iVar7 * 2 + 1] == 0)) {
                  if (piVar15 == ppiVar4[1]) {
                    FUN_0047a948();
                  }
                  iVar16 = piVar15[3] + iVar16;
                  auStack_a818[iVar16 * 2] = 2;
                  auStack_a818[iVar16 * 2 + 1] = 0;
                }
                FUN_0040f400((int *)&ppiStack_bd6c);
              }
              piStack_bd68 = (int *)*ppiVar9[1];
              ppiStack_bd6c = ppiVar9;
              while( true ) {
                piVar6 = piStack_bd68;
                ppiVar4 = ppiStack_bd6c;
                piStack_bd48 = ppiVar9[1];
                if ((ppiStack_bd6c == (int **)0x0) || (ppiStack_bd6c != ppiVar9)) {
                  FUN_0047a948();
                }
                if (piVar6 == piStack_bd48) goto LAB_00435668;
                if (ppiVar4 == (int **)0x0) {
                  FUN_0047a948();
                }
                if (piVar6 == ppiVar4[1]) {
                  FUN_0047a948();
                }
                iVar7 = uVar5 * 0x100 + piVar6[3];
                if ((0 < (int)auStack_a818[iVar7 * 2 + 1]) ||
                   ((-1 < (int)auStack_a818[iVar7 * 2 + 1] && (1 < auStack_a818[iVar7 * 2]))))
                break;
                FUN_0040f400((int *)&ppiStack_bd6c);
              }
              aiStack_b5e8[uVar5 * 0x15 + (int)uStack_bd90] =
                   aiStack_b5e8[uVar5 * 0x15 + (int)uStack_bd90] + 1;
LAB_00435668:
              piVar6 = piStack_bd60;
              iVar7 = iStack_bd64;
              if (piStack_bd60 == *(int **)(iStack_bd64 + 4)) {
                FUN_0047a948();
              }
              if (piVar6[8] != 2) {
                if (piVar6 == *(int **)(iVar7 + 4)) {
                  FUN_0047a948();
                }
                if (piVar6[8] != 6) {
                  if (piVar6 == *(int **)(iVar7 + 4)) {
                    FUN_0047a948();
                  }
                  if (piVar6[8] == 4) {
                    if (piVar6 == *(int **)(iVar7 + 4)) {
                      FUN_0047a948();
                    }
                    iVar16 = piVar6[0xc];
                    if (piVar6 == *(int **)(iVar7 + 4)) {
                      FUN_0047a948();
                    }
                    if (((&DAT_004d1610)[piVar6[0xb] * 2] != uVar5) ||
                       ((&DAT_004d1614)[piVar6[0xb] * 2] != (int)uVar5 >> 0x1f)) {
                      iVar16 = uVar5 * 0x100 + iVar16;
                      if ((-1 < (int)auStack_a818[iVar16 * 2 + 1]) &&
                         ((0 < (int)auStack_a818[iVar16 * 2 + 1] || (1 < auStack_a818[iVar16 * 2])))
                         ) {
                        aiStack_bcd0[uVar5 * 0x15 + (int)uStack_bd90] =
                             aiStack_bcd0[uVar5 * 0x15 + (int)uStack_bd90] + 1;
                      }
                    }
                  }
                  goto LAB_00435835;
                }
              }
              if (piVar6 == *(int **)(iVar7 + 4)) {
                FUN_0047a948();
              }
              iStack_bd78 = piVar6[9];
              iVar7 = uVar5 * 0x100 + iStack_bd78;
              puVar8 = auStack_a818 + iVar7 * 2;
              if ((*puVar8 == 2) && (auStack_a818[iVar7 * 2 + 1] == 0)) {
                iVar16 = uStack_bd88 * 0x15 + (int)uStack_bd90;
                auStack_a818[iVar7 * 2 + 1] = 0;
                aiStack_bcd0[iVar16] = aiStack_bcd0[iVar16] + 1;
                *puVar8 = 3;
                piStack_bd70 = (int *)**(undefined4 **)(*(int *)(local_bd8c + 8) + 0x2454);
                iStack_bd74 = *(int *)(local_bd8c + 8) + 0x2450;
                while( true ) {
                  piVar15 = piStack_bd70;
                  iVar7 = iStack_bd74;
                  piVar6 = *(int **)(*(int *)(local_bd8c + 8) + 0x2454);
                  if ((iStack_bd74 == 0) || (iStack_bd74 != *(int *)(local_bd8c + 8) + 0x2450)) {
                    FUN_0047a948();
                  }
                  if (piVar15 == piVar6) break;
                  if (iVar7 == 0) {
                    FUN_0047a948();
                  }
                  if (piVar15 == *(int **)(iVar7 + 4)) {
                    FUN_0047a948();
                  }
                  if ((uint *)piVar15[6] == uStack_bd90) {
                    if (piVar15 == *(int **)(iVar7 + 4)) {
                      FUN_0047a948();
                    }
                    if (piVar15[4] == iStack_bd78) {
                      aiStack_af00[iVar16] = aiStack_af00[iVar16] + 1;
                    }
                  }
                  UnitList_Advance(&iStack_bd74);
                }
              }
              else if ((*puVar8 == 3) && (auStack_a818[iVar7 * 2 + 1] == 0)) {
                aiStack_bcd0[uVar5 * 0x15 + (int)uStack_bd90] =
                     aiStack_bcd0[uVar5 * 0x15 + (int)uStack_bd90] + -1;
                *puVar8 = 2;
                auStack_a818[iVar7 * 2 + 1] = 0;
              }
            }
LAB_00435835:
            UnitList_Advance(&iStack_bd64);
          }
          iVar7 = *(int *)(iVar7 + 8);
          uStack_bd90 = (uint *)((int)uStack_bd90 + 1);
        } while ((int)uStack_bd90 < *(int *)(iVar7 + 0x2404));
      }
      iVar7 = *(int *)(local_bd8c + 8);
      uVar5 = *(uint *)(iVar7 + 0x2404);
      uStack_bd88 = uStack_bd88 + 1;
    } while ((int)uStack_bd88 < (int)uVar5);
  }
  uVar5 = local_bd5c;
  uVar13 = 0;
  if (0 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404)) {
    do {
      if (uVar13 != uVar5) {
        puVar20 = (ushort *)&uStack_bd90;
        uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,(short)uVar13) & 0xffff00ff | 0x4100);
        p_Var10 = _AfxAygshellState();
        GetProvinceToken(p_Var10,puVar20);
        SEND_LOG(&pvStack_bd84,
                 (wchar_t *)
                 "Our Moves Analysis shows (%s) moved %d units of %d to pressuring provinces");
        pvVar3 = pvStack_bd84;
        piVar6 = (int *)((int)pvStack_bd84 + -0x10);
        iStack_bd74 = 1;
        puVar11 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 0x10))();
        if ((*(int *)((int)pvVar3 + -4) < 0) || (puVar11 != (undefined4 *)*piVar6)) {
          piVar6 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)pvVar3 + -0xc),1);
          if (piVar6 == (int *)0x0) goto LAB_00436378;
          piVar6[1] = *(int *)((int)pvVar3 + -0xc);
          rVar12 = *(int *)((int)pvVar3 + -0xc) + 1;
          _memcpy_s(piVar6 + 4,rVar12,pvVar3,rVar12);
        }
        else {
          LOCK();
          *(int *)((int)pvVar3 + -4) = *(int *)((int)pvVar3 + -4) + 1;
          UNLOCK();
        }
        piStack_bd70 = piVar6 + 4;
        iStack_c._0_1_ = 1;
        BuildAllianceMsg(&DAT_00bbf638,&uStack_bd4c,&iStack_bd74);
        iStack_c = (uint)iStack_c._1_3_ << 8;
        piVar15 = piVar6 + 3;
        LOCK();
        iVar7 = *piVar15;
        *piVar15 = *piVar15 + -1;
        UNLOCK();
        if (iVar7 == 1 || iVar7 + -1 < 0) {
          (**(code **)(*(int *)*piVar6 + 4))(piVar6);
        }
      }
      uVar13 = uVar13 + 1;
    } while ((int)uVar13 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404));
  }
  if (((g_DeceitLevel != 1) || (DAT_00baed68 != '\0')) ||
     (FAL != *(short *)(*(int *)(local_bd8c + 8) + 0x244a))) goto LAB_00436427;
  iVar7 = *(int *)(*(int *)(local_bd8c + 8) + 0x2404);
  uVar13 = 0;
  if (0 < iVar7) {
    iVar16 = 0;
    do {
      if ((uVar13 != uVar5) && (uVar14 = 0, 0 < iVar7)) {
        do {
          if (uVar13 != uVar14) {
            iVar7 = iVar16 + uVar14;
            if (((int)(&g_AllyTrustScore_Hi)[iVar7 * 2] < 1) &&
               (((int)(&g_AllyTrustScore_Hi)[iVar7 * 2] < 0 ||
                ((uint)(&g_AllyTrustScore)[iVar7 * 2] < 5)))) {
              (&g_AllyTrustScore)[iVar7 * 2] = 1;
              (&g_AllyTrustScore_Hi)[iVar7 * 2] = 0;
            }
          }
          uVar14 = uVar14 + 1;
        } while ((int)uVar14 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404));
      }
      iVar7 = *(int *)(*(int *)(local_bd8c + 8) + 0x2404);
      uVar13 = uVar13 + 1;
      iVar16 = iVar16 + 0x15;
    } while ((int)uVar13 < iVar7);
  }
  iVar7 = *(int *)(*(int *)(local_bd8c + 8) + 0x2404);
  uStack_bd88 = 0;
  if (0 < iVar7) {
    iStack_bd78 = 0;
    do {
      uVar5 = 0;
      if (0 < iVar7) {
        ppiStack_bd6c = (int **)(uStack_bd88 * 4);
        do {
          if (uStack_bd88 != uVar5) {
            iVar16 = iStack_bd78 + uVar5;
            iVar7 = aiStack_b5e8[iVar16];
            if (iVar7 < 1) {
              uStack_bd90 = (uint *)0xbf800000;
            }
            else {
              uStack_bd90 = (uint *)((float)aiStack_bcd0[iVar16] / (float)iVar7);
            }
            if (*(int *)((int)aiStack_b5e8 + (int)ppiStack_bd6c) < 1) {
              fStack_bd80 = -1.0;
            }
            else {
              fStack_bd80 = (float)*(int *)((int)aiStack_bcd0 + (int)ppiStack_bd6c) /
                            (float)*(int *)((int)aiStack_b5e8 + (int)ppiStack_bd6c);
            }
            if ((float)uStack_bd90 != -1.0) {
              uVar2 = (undefined2)uVar5;
              if ((float)uStack_bd90 == 0.0) {
                puVar8 = &g_AllyTrustScore + iVar16 * 2;
                uVar13 = *puVar8;
                *puVar8 = *puVar8 + 1;
                (&g_AllyTrustScore_Hi)[iVar16 * 2] =
                     (&g_AllyTrustScore_Hi)[iVar16 * 2] + (uint)(0xfffffffe < uVar13);
                if (fStack_bd80 == 0.0) {
                  puVar20 = (ushort *)&uStack_bd90;
                  (&g_AllyTrustScore)[iVar16 * 2] = 5;
                  (&g_AllyTrustScore_Hi)[iVar16 * 2] = 0;
                  uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,uVar2) & 0xffff00ff | 0x4100);
                  p_Var10 = _AfxAygshellState();
                  GetProvinceToken(p_Var10,puVar20);
                  puVar20 = (ushort *)&uStack_bd90;
                  uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,(ushort)(byte)uStack_bd88) |
                                        0x4100);
                  p_Var10 = _AfxAygshellState();
                  GetProvinceToken(p_Var10,puVar20);
                  SEND_LOG(&pvStack_bd84,
                           (wchar_t *)"Seems (%s) and (%s) have applied no pressure to each other");
                  pvVar3 = pvStack_bd84;
                  piVar6 = (int *)((int)pvStack_bd84 + -0x10);
                  iStack_bd74 = 2;
                  puVar11 = (undefined4 *)
                            (**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 0x10))();
                  if ((*(int *)((int)pvVar3 + -4) < 0) || (puVar11 != (undefined4 *)*piVar6)) {
                    piVar6 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)pvVar3 + -0xc),1);
                    if (piVar6 == (int *)0x0) goto LAB_00436378;
                    piVar6[1] = *(int *)((int)pvVar3 + -0xc);
                    rVar12 = *(int *)((int)pvVar3 + -0xc) + 1;
                    _memcpy_s(piVar6 + 4,rVar12,pvVar3,rVar12);
                  }
                  else {
                    LOCK();
                    *(int *)((int)pvVar3 + -4) = *(int *)((int)pvVar3 + -4) + 1;
                    UNLOCK();
                  }
                  piVar6 = piVar6 + 4;
                  iStack_c._0_1_ = 2;
                  piVar15 = &iStack_bd74;
                  puVar11 = &uStack_bd4c;
                  piStack_bd70 = piVar6;
LAB_00435ee4:
                  BuildAllianceMsg(&DAT_00bbf638,puVar11,piVar15);
                  iStack_c = (uint)iStack_c._1_3_ << 8;
                  piVar15 = piVar6 + -1;
                  LOCK();
                  iVar7 = *piVar15;
                  *piVar15 = *piVar15 + -1;
                  UNLOCK();
                  if (iVar7 == 1 || iVar7 + -1 < 0) {
                    (**(code **)(*(int *)piVar6[-4] + 4))(piVar6 + -4);
                  }
                }
              }
              else {
                if ((((((float)uStack_bd90 == 1.0) && (iVar7 == 1)) && (aiStack_af00[iVar16] == 0))
                    && ((*(int *)((int)aiStack_af00 + (int)ppiStack_bd6c) == 0 &&
                        (-1 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2])))) &&
                   ((0 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2] ||
                    (1 < (uint)(&g_AllyTrustScore)[iVar16 * 2])))) {
                  (&g_AllyTrustScore)[iVar16 * 2] = 2;
                  (&g_AllyTrustScore_Hi)[iVar16 * 2] = 0;
                  puVar20 = (ushort *)&uStack_bd90;
                  uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,uVar2) & 0xffff00ff | 0x4100);
                  p_Var10 = _AfxAygshellState();
                  GetProvinceToken(p_Var10,puVar20);
                  puVar20 = (ushort *)&uStack_bd90;
                  uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,(ushort)(byte)uStack_bd88) |
                                        0x4100);
                  p_Var10 = _AfxAygshellState();
                  GetProvinceToken(p_Var10,puVar20);
                  SEND_LOG(&pvStack_bd84,
                           L"Seems (%s) and (%s) have bounced and still may have a viable alliance")
                  ;
                  pvVar3 = pvStack_bd84;
                  piVar6 = (int *)((int)pvStack_bd84 + -0x10);
                  iStack_bd58 = 2;
                  puVar11 = (undefined4 *)
                            (**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 0x10))();
                  if ((*(int *)((int)pvVar3 + -4) < 0) || (puVar11 != (undefined4 *)*piVar6)) {
                    piVar6 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)pvVar3 + -0xc),1);
                    if (piVar6 == (int *)0x0) goto LAB_00436378;
                    piVar6[1] = *(int *)((int)pvVar3 + -0xc);
                    rVar12 = *(int *)((int)pvVar3 + -0xc) + 1;
                    _memcpy_s(piVar6 + 4,rVar12,pvVar3,rVar12);
                  }
                  else {
                    LOCK();
                    *(int *)((int)pvVar3 + -4) = *(int *)((int)pvVar3 + -4) + 1;
                    UNLOCK();
                  }
                  piVar6 = piVar6 + 4;
                  iStack_c._0_1_ = 3;
                  piVar15 = &iStack_bd58;
                  puVar11 = auStack_bd34;
                  piStack_bd54 = piVar6;
                  goto LAB_00435ee4;
                }
                if (0.55 <= (float)uStack_bd90) {
                  if (((int)(&g_AllyTrustScore_Hi)[iVar16 * 2] < 1) &&
                     (((int)(&g_AllyTrustScore_Hi)[iVar16 * 2] < 0 ||
                      ((uint)(&g_AllyTrustScore)[iVar16 * 2] < 5)))) {
                    (&g_AllyTrustScore)[iVar16 * 2] = 1;
                    (&g_AllyTrustScore_Hi)[iVar16 * 2] = 0;
                  }
                }
                else {
                  puVar8 = &g_AllyTrustScore + iVar16 * 2;
                  uVar13 = *puVar8;
                  *puVar8 = *puVar8 + 1;
                  (&g_AllyTrustScore_Hi)[iVar16 * 2] =
                       (&g_AllyTrustScore_Hi)[iVar16 * 2] + (uint)(0xfffffffe < uVar13);
                  if (fStack_bd80 == 0.0) {
                    puVar8 = &g_AllyTrustScore + iVar16 * 2;
                    uVar13 = *puVar8;
                    *puVar8 = *puVar8 + 1;
                    puVar20 = (ushort *)&uStack_bd90;
                    (&g_AllyTrustScore_Hi)[iVar16 * 2] =
                         (&g_AllyTrustScore_Hi)[iVar16 * 2] + (uint)(0xfffffffe < uVar13);
                    uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,uVar2) & 0xffff00ff | 0x4100);
                    p_Var10 = _AfxAygshellState();
                    GetProvinceToken(p_Var10,puVar20);
                    puVar20 = (ushort *)&uStack_bd90;
                    uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,(ushort)(byte)uStack_bd88) |
                                          0x4100);
                    p_Var10 = _AfxAygshellState();
                    GetProvinceToken(p_Var10,puVar20);
                    SEND_LOG(&pvStack_bd84,
                             (wchar_t *)
                             "Seems (%s) and (%s) have applied little pressure to each other");
                    pvVar3 = pvStack_bd84;
                    piVar6 = (int *)((int)pvStack_bd84 + -0x10);
                    iStack_bd64 = 2;
                    puVar11 = (undefined4 *)
                              (**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 0x10))();
                    if ((*(int *)((int)pvVar3 + -4) < 0) || (puVar11 != (undefined4 *)*piVar6)) {
                      piVar6 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)pvVar3 + -0xc),1);
                      if (piVar6 == (int *)0x0) goto LAB_00436378;
                      piVar6[1] = *(int *)((int)pvVar3 + -0xc);
                      rVar12 = *(int *)((int)pvVar3 + -0xc) + 1;
                      _memcpy_s(piVar6 + 4,rVar12,pvVar3,rVar12);
                    }
                    else {
                      LOCK();
                      *(int *)((int)pvVar3 + -4) = *(int *)((int)pvVar3 + -4) + 1;
                      UNLOCK();
                    }
                    piVar6 = piVar6 + 4;
                    iStack_c._0_1_ = 4;
                    piVar15 = &iStack_bd64;
                    puVar11 = auStack_bd40;
                    piStack_bd60 = piVar6;
                    goto LAB_00435ee4;
                  }
                }
              }
            }
          }
          ppiStack_bd6c = ppiStack_bd6c + 0x15;
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404));
      }
      iVar7 = *(int *)(*(int *)(local_bd8c + 8) + 0x2404);
      iStack_bd78 = iStack_bd78 + 0x15;
      uStack_bd88 = uStack_bd88 + 1;
      uVar5 = local_bd5c;
    } while ((int)uStack_bd88 < iVar7);
  }
  iVar7 = *(int *)(*(int *)(local_bd8c + 8) + 0x2404);
  uVar13 = 0;
  if (iVar7 < 1) {
LAB_00435fe6:
    if ((cStack_bd7a == '\x01') && (uVar13 = 0, 0 < iVar7)) {
      do {
        if (((int)auStack_bd28[uVar13] < 2) && (uVar13 != uVar5)) {
          uVar14 = auStack_bd28[uVar13];
          iVar7 = uVar5 * 0x15 + uVar13;
          (&g_AllyTrustScore)[iVar7 * 2] = uVar14;
          (&g_AllyTrustScore_Hi)[iVar7 * 2] = (int)uVar14 >> 0x1f;
          break;
        }
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < iVar7);
    }
  }
  else {
    puVar8 = &g_AllyTrustScore + uVar5 * 0x2a;
    do {
      if (((int)puVar8[1] < 1) && ((((int)puVar8[1] < 0 || (*puVar8 < 2)) && (uVar13 != uVar5)))) {
        cStack_bd79 = '\x01';
      }
      uVar13 = uVar13 + 1;
      puVar8 = puVar8 + 2;
    } while ((int)uVar13 < iVar7);
    if (cStack_bd79 == '\0') goto LAB_00435fe6;
  }
  iVar7 = uVar5 * 0x15;
  if (((int)(&g_AllyTrustScore_Hi)[(iVar7 + DAT_004c6bc4) * 2] < 1) &&
     (((int)(&g_AllyTrustScore_Hi)[(iVar7 + DAT_004c6bc4) * 2] < 0 ||
      ((uint)(&g_AllyTrustScore)[(iVar7 + DAT_004c6bc4) * 2] < 2)))) {
    DAT_004c6bc4 = 0xffffffff;
  }
  if (((int)(&g_AllyTrustScore_Hi)[(iVar7 + DAT_004c6bc8) * 2] < 1) &&
     (((int)(&g_AllyTrustScore_Hi)[(iVar7 + DAT_004c6bc8) * 2] < 0 ||
      ((uint)(&g_AllyTrustScore)[(iVar7 + DAT_004c6bc8) * 2] < 2)))) {
    DAT_004c6bc8 = 0xffffffff;
  }
  uVar13 = DAT_004c6bc8;
  if (((int)(&g_AllyTrustScore_Hi)[(iVar7 + DAT_004c6bcc) * 2] < 1) &&
     (((int)(&g_AllyTrustScore_Hi)[(iVar7 + DAT_004c6bcc) * 2] < 0 ||
      ((uint)(&g_AllyTrustScore)[(iVar7 + DAT_004c6bcc) * 2] < 2)))) {
    DAT_004c6bcc = 0xffffffff;
  }
  uVar14 = DAT_004c6bcc;
  if ((DAT_004c6bc4 == 0xffffffff) && (-1 < (int)DAT_004c6bc8)) {
    DAT_004c6bc8 = 0xffffffff;
    DAT_004c6bc4 = uVar13;
LAB_004360ba:
    if (-1 < (int)DAT_004c6bcc) {
      DAT_004c6bcc = 0xffffffff;
      DAT_004c6bc8 = uVar14;
    }
  }
  else if (DAT_004c6bc8 == 0xffffffff) goto LAB_004360ba;
  uVar13 = DAT_004c6bcc;
  bVar19 = DAT_004c6bc4 == 0xffffffff;
  if (bVar19) {
    if ((DAT_004c6bc8 == 0xffffffff) && (-1 < (int)DAT_004c6bcc)) {
      DAT_004c6bcc = 0xffffffff;
      bVar19 = uVar13 == 0xffffffff;
      DAT_004c6bc4 = uVar13;
      goto LAB_004360fa;
    }
  }
  else {
LAB_004360fa:
    if ((!bVar19 && -2 < (int)DAT_004c6bc4) &&
       (uVar14 = 0, uVar13 = DAT_004c6bc4, 0 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404))) {
      do {
        if ((uVar14 != uVar5) && (uVar14 != uVar13)) {
          iVar7 = uVar13 * 0x15 + uVar14;
          if ((1 < aiStack_bcd0[iVar7]) && (aiStack_bcd0[iVar7] == aiStack_b5e8[iVar7])) {
            puVar20 = (ushort *)&uStack_bd90;
            uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,(short)uVar13) & 0xffff00ff | 0x4100);
            p_Var10 = _AfxAygshellState();
            GetProvinceToken(p_Var10,puVar20);
            SEND_LOG(&pvStack_bd84,
                     (wchar_t *)
                     "It would seem our best ally (%s) has been severely pressured by another power "
                    );
            pvVar3 = pvStack_bd84;
            piVar6 = (int *)((int)pvStack_bd84 + -0x10);
            iStack_bd74 = 3;
            puVar11 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 0x10))();
            if ((*(int *)((int)pvVar3 + -4) < 0) || (puVar11 != (undefined4 *)*piVar6)) {
              piVar6 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)pvVar3 + -0xc),1);
              if (piVar6 == (int *)0x0) goto LAB_00436378;
              piVar6[1] = *(int *)((int)pvVar3 + -0xc);
              rVar12 = *(int *)((int)pvVar3 + -0xc) + 1;
              _memcpy_s(piVar6 + 4,rVar12,pvVar3,rVar12);
            }
            else {
              LOCK();
              *(int *)((int)pvVar3 + -4) = *(int *)((int)pvVar3 + -4) + 1;
              UNLOCK();
            }
            piStack_bd70 = piVar6 + 4;
            iStack_c._0_1_ = 5;
            BuildAllianceMsg(&DAT_00bbf638,auStack_bd40,&iStack_bd74);
            iStack_c = (uint)iStack_c._1_3_ << 8;
            piVar15 = piVar6 + 3;
            LOCK();
            iVar7 = *piVar15;
            *piVar15 = *piVar15 + -1;
            UNLOCK();
            if (iVar7 == 1 || iVar7 + -1 < 0) {
              (**(code **)(*(int *)*piVar6 + 4))(piVar6);
            }
            DAT_00baed45 = 1;
            uVar13 = DAT_004c6bc4;
          }
        }
        uVar14 = uVar14 + 1;
      } while ((int)uVar14 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404));
    }
  }
  iVar7 = *(int *)(*(int *)(local_bd8c + 8) + 0x2404);
  if (0 < iVar7) {
    piVar6 = &g_AllyTrustScore + uVar5 * 0x2a;
    piVar15 = piVar6;
    iVar16 = iVar7;
    iVar18 = iStack_bd50;
    do {
      if ((*piVar15 == 1) && (piVar15[1] == 0)) {
        iVar18 = iVar18 + 1;
      }
      piVar15 = piVar15 + 2;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    if (iVar18 == 1) {
      iVar7 = 0;
      do {
        if ((*piVar6 == 1) && (piVar6[1] == 0)) {
          *piVar6 = 0;
          piVar6[1] = 0;
          g_OpeningStickyMode = 1;
          g_OpeningEnemy = iVar7;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 2;
      } while (iVar7 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404));
      puVar20 = (ushort *)&uStack_bd90;
      DAT_00baed5f = 1;
      uStack_bd90 = (uint *)(CONCAT22(uStack_bd90._2_2_,(ushort)(byte)g_OpeningEnemy) | 0x4100);
      p_Var10 = _AfxAygshellState();
      GetProvinceToken(p_Var10,puVar20);
      SEND_LOG(&pvStack_bd84,
               (wchar_t *)"Enemy is set to our single - and likely original enemy (%s)");
      pvVar3 = pvStack_bd84;
      piVar6 = (int *)((int)pvStack_bd84 + -0x10);
      iStack_bd74 = 0x1e;
      puVar11 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 0x10))();
      if ((*(int *)((int)pvVar3 + -4) < 0) || (puVar11 != (undefined4 *)*piVar6)) {
        piVar6 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)pvVar3 + -0xc),1);
        if (piVar6 == (int *)0x0) {
LAB_00436378:
          ErrorExit();
          return;
        }
        piVar6[1] = *(int *)((int)pvVar3 + -0xc);
        rVar12 = *(int *)((int)pvVar3 + -0xc) + 1;
        _memcpy_s(piVar6 + 4,rVar12,pvVar3,rVar12);
      }
      else {
        LOCK();
        *(int *)((int)pvVar3 + -4) = *(int *)((int)pvVar3 + -4) + 1;
        UNLOCK();
      }
      piStack_bd70 = piVar6 + 4;
      iStack_c._0_1_ = 6;
      BuildAllianceMsg(&DAT_00bbf638,auStack_bd40,&iStack_bd74);
      iStack_c = (uint)iStack_c._1_3_ << 8;
      piVar15 = piVar6 + 3;
      LOCK();
      iVar7 = *piVar15;
      *piVar15 = *piVar15 + -1;
      UNLOCK();
      if (iVar7 + -1 < 1) {
        (**(code **)(*(int *)*piVar6 + 4))(piVar6);
      }
      goto LAB_00436427;
    }
  }
  if ((DAT_00baed43 == '\x01') && (iVar16 = 0, 0 < iVar7)) {
    piVar6 = &g_AllyTrustScore + uVar5 * 0x2a;
    do {
      if ((*piVar6 == 3) && (piVar6[1] == 0)) {
        *piVar6 = 1;
        piVar6[1] = 0;
      }
      iVar16 = iVar16 + 1;
      piVar6 = piVar6 + 2;
    } while (iVar16 < *(int *)(*(int *)(local_bd8c + 8) + 0x2404));
  }
LAB_00436427:
  iStack_c = 0xffffffff;
  piVar6 = (int *)((int)pvStack_bd84 + -4);
  LOCK();
  iVar7 = *piVar6;
  *piVar6 = *piVar6 + -1;
  UNLOCK();
  if (iVar7 == 1 || iVar7 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_bd84 + -0x10) + 4))
              ((undefined4 *)((int)pvStack_bd84 + -0x10));
  }
  ExceptionList = local_14;
  return;
}

