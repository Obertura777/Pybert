
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall EvaluateAllianceScore(void *this,int *param_1,uint param_2)

{
  char *this_00;
  ushort uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  int **ppiVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int iVar12;
  int iVar13;
  int iVar14;
  void *pvVar15;
  int iVar16;
  int *piVar17;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar22;
  float10 extraout_ST1_01;
  float10 fVar23;
  float10 fVar24;
  ulonglong uVar25;
  longlong lVar26;
  undefined8 uVar27;
  int *piStack_102ec;
  int *piStack_102e8;
  void *pvStack_102e4;
  int *piStack_102e0;
  char *pcStack_102dc;
  undefined *puStack_102d8;
  undefined4 *puStack_102d4;
  void *pvStack_102d0;
  int *piStack_102cc;
  double dStack_102c8;
  int **ppiStack_102c0;
  int iStack_102bc;
  undefined8 uStack_102b8;
  int **ppiStack_102b0;
  int *piStack_102ac;
  double dStack_102a8;
  ushort uStack_1029e;
  int iStack_1029c;
  int *piStack_10298;
  undefined4 *puStack_10294;
  undefined8 uStack_10290;
  int iStack_10288;
  int iStack_10280;
  int *piStack_1027c;
  int aiStack_10278 [22];
  int aiStack_10220 [22];
  int aiStack_101c8 [22];
  int aiStack_10170 [2];
  int aiStack_10168 [22];
  int aiStack_10110 [22];
  int aiStack_100b8 [22];
  int aiStack_10060 [22];
  int aiStack_10008 [256];
  int local_fc08 [5376];
  int local_a808 [5376];
  int local_5408 [5375];
  undefined4 uStack_c;
  
  uStack_c = 0x43bd30;
  iVar13 = *(int *)((int)this + 8);
  piStack_1027c = (int *)(uint)*(byte *)(iVar13 + 0x2424);
  iStack_10288 = 0x32;
  iStack_1029c = 0x32;
  uStack_102b8._0_6_ = ZEXT46((int *)uStack_102b8);
  iStack_102bc = 0;
  if ((3.0 <= _g_NearEndGameFactor) && (2 < (int)(&curr_sc_cnt)[(int)param_1])) {
    if (_g_NearEndGameFactor < 5.0) {
      iStack_10288 = 0x50;
      iStack_1029c = 0x46;
    }
    else if (6.0 <= _g_NearEndGameFactor) {
      iStack_10288 = 0x78;
      iStack_1029c = 100;
    }
    else {
      iStack_10288 = 100;
      iStack_1029c = 0x5a;
    }
  }
  piVar5 = *(int **)(iVar13 + 0x2404);
  if (0 < (int)piVar5) {
    piVar17 = aiStack_10060;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
    piVar17 = aiStack_101c8;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
    piVar17 = aiStack_10168;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
    piVar17 = aiStack_10110;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
    piVar17 = aiStack_100b8;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
    piVar17 = aiStack_10220;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 0;
      piVar17 = piVar17 + 1;
    }
    piVar17 = aiStack_10278;
    for (uVar9 = (uint)piVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar17 = 5000;
      piVar17 = piVar17 + 1;
    }
    iVar12 = 0;
    piStack_102e0 = piVar5;
    do {
      if (0 < *(int *)(iVar13 + 0x2400)) {
        uVar9 = *(uint *)(iVar13 + 0x2400);
        puVar8 = (undefined4 *)((int)local_fc08 + iVar12);
        for (uVar10 = uVar9 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        puVar8 = (undefined4 *)((int)local_5408 + iVar12);
        for (uVar10 = uVar9 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        puVar8 = (undefined4 *)((int)local_a808 + iVar12);
        for (uVar9 = uVar9 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
      }
      iVar12 = iVar12 + 0x400;
      piStack_102e0 = (int *)((int)piStack_102e0 + -1);
    } while (piStack_102e0 != (int *)0x0);
  }
  iVar12 = 0;
  if (0 < *(int *)(iVar13 + 0x2400)) {
    do {
      (&DAT_0062db58)[iVar12 * 2] = 0;
      (&DAT_0062db5c)[iVar12 * 2] = 0;
      iVar13 = *(int *)((int)this + 8);
      aiStack_10008[iVar12] = 0;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(iVar13 + 0x2400));
  }
  puStack_102d4 = (undefined4 *)*DAT_00baed80;
  puStack_102d8 = &DAT_00baed7c;
  pvStack_102e4 = this;
  while( true ) {
    puVar3 = puStack_102d4;
    puVar2 = puStack_102d8;
    puVar8 = DAT_00baed80;
    if ((puStack_102d8 == (undefined *)0x0) || (puStack_102d8 != &DAT_00baed7c)) {
      FUN_0047a948();
    }
    if (puVar3 == puVar8) break;
    if (puVar2 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar3 == *(undefined4 **)(puVar2 + 4)) {
      FUN_0047a948();
    }
    iVar13 = puVar3[3];
    uStack_10290 = (double)CONCAT44(puVar3[4],(int)uStack_10290);
    iVar12 = 0;
    if (0 < *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2404)) {
      pcStack_102dc = (char *)aiStack_10008[iVar13];
      piStack_102e0 = aiStack_10008 + iVar13;
      piVar17 = puStack_102d4 + 0x1a;
      piVar5 = local_fc08 + iVar13;
      do {
        if (puStack_102d4 == *(undefined4 **)(puStack_102d8 + 4)) {
          FUN_0047a948();
        }
        pcStack_102dc = pcStack_102dc + *piVar17;
        if (puStack_102d4 == *(undefined4 **)(puStack_102d8 + 4)) {
          FUN_0047a948();
        }
        *piVar5 = *piVar5 + *piVar17;
        iVar12 = iVar12 + 1;
        piVar17 = piVar17 + 1;
        piVar5 = piVar5 + 0x100;
      } while (iVar12 < *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2404));
      *piStack_102e0 = (int)pcStack_102dc;
    }
    FUN_0040f380((int *)&puStack_102d8);
  }
  fVar18 = (float10)_g_NearEndGameFactor;
  ppiVar6 = *(int ***)((int)pvStack_102e4 + 8);
  piStack_102e0 = ppiVar6[0x900];
  pvStack_102d0 = (void *)0x0;
  if (0 < (int)piStack_102e0) {
    piVar5 = ppiVar6[0x901];
    do {
      piStack_102e8 = (int *)0x0;
      if (0 < (int)piVar5) {
        pcStack_102dc = (char *)0x0;
        piVar17 = local_5408 + (int)pvStack_102d0;
        do {
          piVar11 = (int *)0x0;
          iVar13 = (int)pvStack_102d0 * 4;
          do {
            if ((piStack_102e8 != piVar11) &&
               ((int)(&DAT_00634e90)[(int)(pcStack_102dc + (int)piVar11)] < 10)) {
              if (fVar18 <= (float10)5.0) {
                iVar12 = *(int *)((int)&DAT_00b95580 + iVar13) +
                         *(int *)((int)&DAT_00b9a980 + iVar13);
                if (*piVar17 < iVar12) {
                  *piVar17 = iVar12;
                }
              }
              else {
                *piVar17 = *piVar17 +
                           *(int *)((int)&DAT_00b95580 + iVar13) +
                           *(int *)((int)&DAT_00b9a980 + iVar13);
              }
            }
            piVar11 = (int *)((int)piVar11 + 1);
            iVar13 = iVar13 + 0x400;
          } while ((int)piVar11 < (int)piVar5);
          pcStack_102dc = pcStack_102dc + 0x15;
          piStack_102e8 = (int *)((int)piStack_102e8 + 1);
          piVar17 = piVar17 + 0x100;
        } while ((int)piStack_102e8 < (int)piVar5);
      }
      pvStack_102d0 = (void *)((int)pvStack_102d0 + 1);
    } while ((int)pvStack_102d0 < (int)piStack_102e0);
  }
  pvStack_102d0 = (void *)0x0;
  if (0 < (int)piStack_102e0) {
    pcStack_102dc = (char *)((int)ppiVar6 + 3);
    do {
      if (*pcStack_102dc == '\0') {
        iVar12 = (int)param_1 * 0x100 + (int)pvStack_102d0;
        iVar13 = local_5408[iVar12];
        iVar12 = (&DAT_00b9a980)[iVar12];
        if ((0 < iVar13) && (0 < iVar12)) {
          if (iVar12 - iVar13 < (int)param_2) {
            if (iVar13 * 3 < iVar12 * 2) {
              iStack_102bc = iStack_102bc + 10;
            }
            else if (iVar13 < iVar12) {
              iStack_102bc = iStack_102bc + 5;
            }
            else if (iVar12 != iVar13) {
              iStack_102bc = iStack_102bc + -10;
            }
          }
          else {
            iStack_102bc = iStack_102bc + 0x14;
          }
        }
      }
      if (*pcStack_102dc == '\x01') {
        piVar5 = ppiVar6[0x901];
        uVar9 = 0;
        if (0 < (int)piVar5) {
          uStack_1029e = *(ushort *)(pcStack_102dc + 0x1d);
          piStack_102e8 = (int *)CONCAT22(piStack_102e8._2_2_,uStack_1029e >> 8);
          piVar17 = piStack_102e8;
          iVar13 = (int)pvStack_102d0 * 4;
          ppiStack_102b0 = (int **)((int)pvStack_102d0 * 8);
          ppiStack_102c0 = (int **)0x0;
          dStack_102a8 = (double)CONCAT44(dStack_102a8._4_4_,iVar13);
          do {
            piStack_102e8._0_1_ = (char)(uStack_1029e >> 8);
            uVar10 = (uint)(byte)uStack_1029e;
            if ((char)piStack_102e8 != 'A') {
              uVar10 = 0x14;
            }
            iVar12 = *(int *)((int)local_5408 + iVar13);
            if (uVar10 == uVar9) {
              iVar14 = *(int *)((int)&DAT_00b95580 + iVar13) + *(int *)((int)&DAT_00b9a980 + iVar13)
              ;
              if ((float10)5.0 < fVar18) {
                uVar10 = 0;
                piVar11 = &DAT_00b9a980 + (int)pvStack_102d0;
                do {
                  if ((uVar10 != uVar9) &&
                     (0x23 < (int)(&DAT_00634e90)[(int)ppiStack_102c0 + uVar10])) {
                    iVar14 = iVar14 + *piVar11;
                  }
                  uVar10 = uVar10 + 1;
                  piVar11 = piVar11 + 0x100;
                  iVar13 = dStack_102a8._0_4_;
                } while ((int)uVar10 < (int)piVar5);
              }
              if (0 < iVar12) {
                if (iVar12 < iVar14) {
                  if ((iVar14 < iVar12 * 2) && (aiStack_10008[(int)pvStack_102d0] == 0)) {
                    iVar12 = (iVar12 - iVar14) + 1 + param_2;
                    iVar12 = (int)(iVar12 + (iVar12 >> 0x1f & 7U)) >> 3;
                  }
                  else {
LAB_0043c3eb:
                    iVar12 = (int)(param_2 + ((int)param_2 >> 0x1f & 0xfU)) >> 4;
                  }
LAB_0043c3f6:
                  aiStack_101c8[uVar9] = aiStack_101c8[uVar9] - iVar12;
                }
                else {
                  iVar16 = iVar12 - iVar14;
                  if (iVar16 < (int)param_2) {
                    if (iVar14 != 0) {
                      if (aiStack_10008[(int)pvStack_102d0] != 0) {
                        iVar13 = dStack_102a8._0_4_;
                        if (iVar12 != iVar14) goto LAB_0043c3b6;
                        goto LAB_0043c3eb;
                      }
                      iVar13 = iVar16 + 1 + param_2;
                      iVar12 = (int)(iVar13 + (iVar13 >> 0x1f & 7U)) >> 3;
                      iVar13 = dStack_102a8._0_4_;
                      goto LAB_0043c3f6;
                    }
                    aiStack_101c8[uVar9] = aiStack_101c8[uVar9] - iVar12;
                  }
                  else {
                    aiStack_101c8[uVar9] = aiStack_101c8[uVar9] - param_2;
                  }
                }
              }
            }
            else {
              iVar16 = *(int *)((int)&DAT_00b9a980 + iVar13);
              if (0 < iVar16) {
                if (iVar16 < *(int *)((int)&DAT_00b95580 + iVar13)) {
                  iVar16 = iVar16 * 2;
                }
                else {
                  iVar16 = iVar16 + *(int *)((int)&DAT_00b95580 + iVar13);
                }
                if (0 < iVar16) {
                  if (iVar16 < iVar12) {
                    if (0 < *(int *)((int)local_fc08 + iVar13)) {
                      iVar16 = iVar12 - iVar16;
                      if (iVar16 < (int)param_2) {
LAB_0043c3b6:
                        iVar12 = (int)(iVar16 + (iVar16 >> 0x1f & 3U)) >> 2;
                        goto LAB_0043c3f6;
                      }
                      aiStack_101c8[uVar9] = aiStack_101c8[uVar9] - param_2;
                    }
                  }
                  else if (((int)(&g_AllyTrustScore_Hi)[((int)ppiStack_102c0 + uVar10) * 2] < 1) &&
                          (((int)(&g_AllyTrustScore_Hi)[((int)ppiStack_102c0 + uVar10) * 2] < 0 ||
                           ((uint)(&g_AllyTrustScore)[((int)ppiStack_102c0 + uVar10) * 2] < 2)))) {
                    iVar14 = *(int *)((int)local_fc08 + iVar13);
                    if ((iVar14 < 1) || (iVar12 != 0)) {
                      iVar4 = iVar16 - iVar12;
                      if (iVar4 < (int)param_2) {
                        if (iVar12 == 0) {
                          aiStack_10168[uVar9] = aiStack_10168[uVar9] + iVar16;
                        }
                        else {
                          if (aiStack_10008[(int)pvStack_102d0] == 0) {
                            iVar4 = iVar4 + param_2;
                          }
                          else if (0 < iVar14) {
                            aiStack_10168[uVar9] = aiStack_10168[uVar9] + iVar14;
                            goto LAB_0043c25b;
                          }
                          aiStack_10168[uVar9] =
                               aiStack_10168[uVar9] + ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2);
                        }
                      }
                      else {
                        aiStack_10168[uVar9] = aiStack_10168[uVar9] + param_2;
                      }
                    }
LAB_0043c25b:
                    if (((((iVar14 == 0) &&
                          (ppiStack_102b0[0x15ea3a] == (int *)0x0 &&
                           ppiStack_102b0[0x15ea3b] == (int *)0x0)) &&
                         (SPR == *(ushort *)((int)ppiVar6 + 0x244a))) &&
                        (((int)param_2 <= iVar16 && (-1 < (int)ppiStack_102b0[0x15c03b])))) &&
                       ((0 < (int)ppiStack_102b0[0x15c03b] ||
                        (ppiStack_102b0[0x15c03a] != (int *)0x0)))) {
                      aiStack_10060[uVar9] =
                           (int)ppiStack_102b0[0x156c3a] +
                           (aiStack_10060[uVar9] - (int)ppiStack_102b0[0x15c03a]);
                    }
                  }
                }
              }
            }
            ppiStack_102b0 = ppiStack_102b0 + 0x200;
            ppiStack_102c0 = (int **)((int)ppiStack_102c0 + 0x15);
            uVar9 = uVar9 + 1;
            iVar13 = iVar13 + 0x400;
            dStack_102a8 = (double)CONCAT44(dStack_102a8._4_4_,iVar13);
            piStack_102e8 = piVar17;
          } while ((int)uVar9 < (int)piVar5);
        }
      }
      pcStack_102dc = pcStack_102dc + 0x24;
      pvStack_102d0 = (void *)((int)pvStack_102d0 + 1);
    } while ((int)pvStack_102d0 < (int)piStack_102e0);
  }
  piStack_10298 = ppiVar6[0x901];
  iVar13 = 0;
  if (0 < (int)piStack_10298) {
    do {
      if ((0 < aiStack_10060[iVar13]) && (aiStack_101c8[iVar13] == 0)) {
        aiStack_10278[iVar13] = aiStack_10278[iVar13] + aiStack_10060[iVar13];
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < (int)piStack_10298);
  }
  fVar19 = (float10)10.0;
  pvStack_102d0 = (void *)0x0;
  if (0 < (int)piStack_102e0) {
    fVar20 = (float10)20.0;
    fVar22 = (float10)1;
    fVar21 = (float10)6.0;
    ppiStack_102c0 = ppiVar6;
    do {
      piStack_102e8 = (int *)0x0;
      if (0 < (int)piStack_10298) {
        piStack_102ec = (int *)((int)pvStack_102d0 * 8);
        pcStack_102dc = (char *)((int)pvStack_102d0 * 4);
        uStack_1029e = CONCAT11(uStack_1029e._1_1_,*(undefined1 *)((int)ppiStack_102c0 + 3));
        dStack_102a8 = (double)((ulonglong)dStack_102a8 & 0xffffffff00000000);
        fVar23 = fVar20;
        do {
          fVar20 = fVar23;
          if ((char)uStack_1029e == '\x01') {
            piVar5 = (int *)(*(ushort *)(ppiStack_102c0 + 8) & 0xff);
            if ((char)(*(ushort *)(ppiStack_102c0 + 8) >> 8) != 'A') {
              piVar5 = (int *)0x14;
            }
            if (((piVar5 == piStack_102e8) && (DAT_00baed68 == '\0')) &&
               ((fVar18 < fVar21 || (DAT_00624124 == piStack_102e8)))) {
              iVar13 = *(int *)(pcStack_102dc + 0xb9a980);
              ppiVar6 = (int **)0x0;
              piVar17 = (int *)0x0;
              ppiStack_102b0 = (int **)0x0;
              piVar5 = &DAT_00b9a980 + (int)pvStack_102d0;
              do {
                if (piVar17 != piStack_102e8) {
                  iVar12 = dStack_102a8._0_4_ + (int)piVar17;
                  if (((9 < (int)(&DAT_00634e90)[iVar12]) ||
                      ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar12 * 2] &&
                       ((0 < (int)(&g_AllyTrustScore_Hi)[iVar12 * 2] ||
                        (1 < (uint)(&g_AllyTrustScore)[iVar12 * 2])))))) &&
                     ((iVar12 = *piVar5, piVar11 = (int *)dStack_102a8._0_4_, 0 < iVar12 ||
                      ((-1 < *(int *)((int)&DAT_005658ec + (int)piStack_102ec) &&
                       ((piVar11 = piStack_102ec,
                        0 < *(int *)((int)&DAT_005658ec + (int)piStack_102ec) ||
                        (*(int *)((int)&DAT_005658e8 + (int)piStack_102ec) != 0)))))))) {
                    if (iVar13 < iVar12) {
                      dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar12 - iVar13);
                      fVar20 = fVar22;
                      fVar24 = fVar23;
                      fVar18 = fVar19;
                      uVar25 = FloatToInt64(iVar12 - iVar13,piVar11);
                      ppiVar6 = (int **)uVar25;
                      fVar21 = extraout_ST0;
                      fVar22 = extraout_ST1;
                      fVar23 = fVar20;
                      fVar19 = fVar24;
                      ppiStack_102b0 = ppiVar6;
                    }
                    else if ((int)param_2 < iVar13) {
                      ppiVar6 = (int **)((int)ppiVar6 + 1);
                      ppiStack_102b0 = ppiVar6;
                    }
                    else {
                      dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,param_2 - iVar13);
                      fVar20 = fVar22;
                      fVar24 = fVar23;
                      fVar18 = fVar19;
                      uVar25 = FloatToInt64(iVar12,piVar11);
                      ppiVar6 = (int **)uVar25;
                      fVar21 = extraout_ST0_00;
                      fVar22 = extraout_ST1_00;
                      fVar23 = fVar20;
                      fVar19 = fVar24;
                      ppiStack_102b0 = ppiVar6;
                    }
                  }
                }
                piVar17 = (int *)((int)piVar17 + 1);
                piVar5 = piVar5 + 0x100;
              } while ((int)piVar17 < (int)piStack_10298);
              fVar20 = fVar23;
              if (0 < (int)ppiVar6) {
                iVar13 = param_2 - *(int *)((int)local_fc08 + (int)pcStack_102dc);
                dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar13);
                fVar20 = fVar22;
                fVar18 = fVar19;
                uVar25 = FloatToInt64(iVar13,pcStack_102dc);
                aiStack_10220[(int)piStack_102e8] = aiStack_10220[(int)piStack_102e8] - (int)uVar25;
                aiStack_10278[(int)piStack_102e8] = aiStack_10278[(int)piStack_102e8] - (int)uVar25;
                fVar21 = extraout_ST0_01;
                fVar22 = extraout_ST1_01;
                fVar19 = fVar23;
              }
            }
          }
          dStack_102a8 = (double)CONCAT44(dStack_102a8._4_4_,dStack_102a8._0_4_ + 0x15);
          piStack_102ec = (int *)((int)piStack_102ec + 0x800);
          pcStack_102dc = pcStack_102dc + 0x400;
          piStack_102e8 = (int *)((int)piStack_102e8 + 1);
          fVar23 = fVar20;
        } while ((int)piStack_102e8 < (int)piStack_10298);
      }
      ppiStack_102c0 = ppiStack_102c0 + 9;
      pvStack_102d0 = (void *)((int)pvStack_102d0 + 1);
    } while ((int)pvStack_102d0 < (int)piStack_102e0);
  }
  puStack_102d4 = (undefined4 *)*DAT_00baed80;
  puStack_102d8 = &DAT_00baed7c;
  while( true ) {
    puVar8 = puStack_102d4;
    puVar2 = puStack_102d8;
    puStack_10294 = DAT_00baed80;
    if ((puStack_102d8 == (undefined *)0x0) || (puStack_102d8 != &DAT_00baed7c)) {
      FUN_0047a948();
    }
    iVar13 = (int)param_1 >> 0x1f;
    if (puVar8 == puStack_10294) break;
    if (puVar2 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar8 == *(undefined4 **)(puVar2 + 4)) {
      FUN_0047a948();
    }
    uStack_10290 = *(double *)(puVar8 + 3);
    iVar12 = *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2404);
    piStack_102e8 = (int *)0x0;
    if (0 < iVar12) {
      pcStack_102dc = (char *)(puVar8[3] * 0x24);
      do {
        piVar5 = piStack_102e8;
        piStack_102e0 = (int *)0x0;
        if (0 < iVar12) {
          piStack_102ec = puVar8 + 0x1a;
          do {
            if (piStack_102e0 == piVar5) {
              if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                FUN_0047a948();
              }
              puVar2 = puStack_102d8;
              if (0 < *piStack_102ec) {
                if ((puVar8 == *(undefined4 **)(puStack_102d8 + 4)) &&
                   (FUN_0047a948(), puVar8 == *(undefined4 **)(puVar2 + 4))) {
                  FUN_0047a948();
                }
                aiStack_10278[(int)piVar5] =
                     aiStack_10278[(int)piVar5] +
                     (puVar8[(int)piVar5 + 5] * *piStack_102ec) / (int)param_2;
                if (pcStack_102dc[*(int *)((int)pvStack_102e4 + 8) + 3] == '\x01') {
                  piVar17 = (int *)(*(ushort *)
                                     (pcStack_102dc + *(int *)((int)pvStack_102e4 + 8) + 0x20) &
                                   0xff);
                  if ((char)(*(ushort *)(pcStack_102dc + *(int *)((int)pvStack_102e4 + 8) + 0x20) >>
                            8) != 'A') {
                    piVar17 = (int *)0x14;
                  }
                  if (piVar17 != piVar5) {
                    iVar12 = (int)piVar5 * 0x15 + (int)piVar17;
                    if (((int)(&g_AllyTrustScore_Hi)[iVar12 * 2] < 1) &&
                       (((int)(&g_AllyTrustScore_Hi)[iVar12 * 2] < 0 ||
                        ((uint)(&g_AllyTrustScore)[iVar12 * 2] < 3)))) {
                      if (puVar8 == *(undefined4 **)(puVar2 + 4)) {
                        FUN_0047a948();
                      }
                      aiStack_10110[(int)piVar5] =
                           aiStack_10110[(int)piVar5] + puVar8[(int)piVar5 + 0x1a];
                      if (puVar8 == *(undefined4 **)(puVar2 + 4)) {
                        FUN_0047a948();
                      }
                      aiStack_100b8[(int)piVar5] =
                           aiStack_100b8[(int)piVar5] + puVar8[(int)piVar5 + 0x1a];
                    }
                    else {
                      if ((puVar8 == *(undefined4 **)(puVar2 + 4)) &&
                         (FUN_0047a948(), puVar8 == *(undefined4 **)(puVar2 + 4))) {
                        FUN_0047a948();
                      }
                      aiStack_10278[(int)piVar5] =
                           aiStack_10278[(int)piVar5] -
                           (puVar8[(int)piVar5 + 5] * *piStack_102ec) / (int)param_2;
                    }
                  }
                }
                puVar2 = puStack_102d8;
                iVar12 = (int)piVar5 * 0x100 + (int)uStack_10290;
                if ((((-1 < (int)(&DAT_005a48ec)[iVar12 * 2]) &&
                     (((0 < (int)(&DAT_005a48ec)[iVar12 * 2] ||
                       (10 < (uint)(&g_AttackHistory)[iVar12 * 2])) &&
                      (*(int *)(&g_SCOwnership + iVar12 * 8) == 0 &&
                       *(int *)(&DAT_00520cec + iVar12 * 8) == 0)))) &&
                    (-1 < (int)(&DAT_005460ec)[iVar12 * 2])) &&
                   ((0 < (int)(&DAT_005460ec)[iVar12 * 2] || ((&DAT_005460e8)[iVar12 * 2] != 0)))) {
                  if ((puVar8 == *(undefined4 **)(puStack_102d8 + 4)) &&
                     (FUN_0047a948(), puVar8 == *(undefined4 **)(puVar2 + 4))) {
                    FUN_0047a948();
                  }
                  aiStack_10278[(int)piVar5] =
                       aiStack_10278[(int)piVar5] +
                       ((puVar8[(int)piVar5 + 5] * *piStack_102ec * 7) / 0x14) / (int)param_2;
                }
              }
            }
            else if (((int)(&DAT_00634e90)[(int)piVar5 * 0x15 + (int)piStack_102e0] < 0x1e) ||
                    (DAT_00baed69 == '\0')) {
              if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                FUN_0047a948();
              }
              if (0 < *piStack_102ec) {
                iVar12 = (int)piVar5 * 0x100 + (int)uStack_10290;
                if ((-1 < (int)(&DAT_0058f8ec)[iVar12 * 2]) &&
                   ((0 < (int)(&DAT_0058f8ec)[iVar12 * 2] || ((&DAT_0058f8e8)[iVar12 * 2] != 0)))) {
                  if ((piVar5 == param_1) &&
                     (((*(int *)(&g_SCOwnership + iVar12 * 8) == 1 &&
                       (*(int *)(&DAT_00520cec + iVar12 * 8) == 0)) ||
                      (((int *)(&DAT_004d2610)[(int)uStack_10290 * 2] == param_1 &&
                       ((&DAT_004d2614)[(int)uStack_10290 * 2] == iVar13)))))) {
                    if (((((int *)(&DAT_004d2610)[(int)uStack_10290 * 2] != param_1) ||
                         ((&DAT_004d2614)[(int)uStack_10290 * 2] != iVar13)) ||
                        (_g_NearEndGameFactor <= 6.0)) || (DAT_00624124 == param_1)) {
                      if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                        FUN_0047a948();
                      }
                      if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                        FUN_0047a948();
                      }
                      iVar14 = (int)puVar8[(int)piVar5 + 5] >> 0x1f;
                      if (((int)(&DAT_0062db5c)[puVar8[3] * 2] <= iVar14) &&
                         (((int)(&DAT_0062db5c)[puVar8[3] * 2] < iVar14 ||
                          ((uint)(&DAT_0062db58)[puVar8[3] * 2] < (uint)puVar8[(int)piVar5 + 5]))))
                      {
                        if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                          FUN_0047a948();
                        }
                        if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                          FUN_0047a948();
                        }
                        iVar14 = puVar8[(int)piVar5 + 5];
                        goto LAB_0043ca8f;
                      }
                    }
                    else {
                      if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                        FUN_0047a948();
                      }
                      if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                        FUN_0047a948();
                      }
                      iVar14 = (int)(puVar8[(int)piVar5 + 5] + 1000) >> 0x1f;
                      if (((int)(&DAT_0062db5c)[puVar8[3] * 2] <= iVar14) &&
                         (((int)(&DAT_0062db5c)[puVar8[3] * 2] < iVar14 ||
                          ((uint)(&DAT_0062db58)[puVar8[3] * 2] < puVar8[(int)piVar5 + 5] + 1000))))
                      {
                        if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                          FUN_0047a948();
                        }
                        if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                          FUN_0047a948();
                        }
                        iVar14 = puVar8[(int)piVar5 + 5] + 1000;
LAB_0043ca8f:
                        iVar16 = puVar8[3];
                        (&DAT_0062db58)[iVar16 * 2] = iVar14;
                        (&DAT_0062db5c)[iVar16 * 2] = iVar14 >> 0x1f;
                      }
                    }
                  }
                  if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                    FUN_0047a948();
                  }
                  if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                    FUN_0047a948();
                  }
                  iVar14 = (puVar8[(int)piVar5 + 5] * *piStack_102ec) / (int)param_2;
                  aiStack_10220[(int)piVar5] = aiStack_10220[(int)piVar5] - iVar14;
                  aiStack_10278[(int)piVar5] = aiStack_10278[(int)piVar5] - iVar14;
                }
                if (pcStack_102dc[*(int *)((int)pvStack_102e4 + 8) + 3] == '\x01') {
                  piVar17 = (int *)(*(ushort *)
                                     (pcStack_102dc + *(int *)((int)pvStack_102e4 + 8) + 0x20) &
                                   0xff);
                  if ((char)(*(ushort *)(pcStack_102dc + *(int *)((int)pvStack_102e4 + 8) + 0x20) >>
                            8) != 'A') {
                    piVar17 = (int *)0x14;
                  }
                  if (piVar17 == piVar5) {
                    if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                      FUN_0047a948();
                    }
                    aiStack_10110[(int)piVar5] = aiStack_10110[(int)piVar5] - *piStack_102ec;
                    if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                      FUN_0047a948();
                    }
                    aiStack_100b8[(int)piVar5] = aiStack_100b8[(int)piVar5] - *piStack_102ec;
                  }
                  else if ((-1 < (int)(&DAT_006040ec)[iVar12 * 2]) &&
                          ((0 < (int)(&DAT_006040ec)[iVar12 * 2] ||
                           ((&g_AttackCount)[iVar12 * 2] != 0)))) {
                    if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
                      FUN_0047a948();
                    }
                    aiStack_10110[(int)piVar5] = aiStack_10110[(int)piVar5] - *piStack_102ec;
                  }
                }
              }
            }
            piStack_102ec = piStack_102ec + 1;
            piStack_102e0 = (int *)((int)piStack_102e0 + 1);
          } while ((int)piStack_102e0 < *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2404));
        }
        if (pcStack_102dc[*(int *)((int)pvStack_102e4 + 8) + 4] == '\0') {
          if (puVar8 == *(undefined4 **)(puStack_102d8 + 4)) {
            FUN_0047a948();
          }
          if (0 < (int)puVar8[(int)piStack_102e8 + 0x1a]) {
            ppiStack_102c0 =
                 AdjacencyList_FilterByUnitType
                           (pcStack_102dc + *(int *)((int)pvStack_102e4 + 8) + 8,&FLT);
            puVar2 = puStack_102d8;
            if ((puVar8 == *(undefined4 **)(puStack_102d8 + 4)) &&
               (FUN_0047a948(), puVar8 == *(undefined4 **)(puVar2 + 4))) {
              FUN_0047a948();
            }
            piStack_102e0 =
                 (int *)(((puVar8[(int)piStack_102e8 + 5] + 0x32) *
                         puVar8[(int)piStack_102e8 + 0x1a]) / (int)param_2);
            piStack_102ac = (int *)*ppiStack_102c0[1];
            ppiStack_102b0 = ppiStack_102c0;
            while( true ) {
              piVar5 = piStack_102ac;
              ppiVar6 = ppiStack_102b0;
              piStack_102cc = ppiStack_102c0[1];
              if ((ppiStack_102b0 == (int **)0x0) || (ppiStack_102b0 != ppiStack_102c0)) {
                FUN_0047a948();
              }
              if (piVar5 == piStack_102cc) break;
              if (ppiVar6 == (int **)0x0) {
                FUN_0047a948();
              }
              if (piVar5 == ppiVar6[1]) {
                FUN_0047a948();
              }
              uStack_102b8 = CONCAT44(CONCAT22(uStack_102b8._6_2_,AMY),piVar5[3]);
              ppiVar7 = FUN_0041c270(&DAT_00baed7c,(int **)&uStack_102b8);
              if (0 < (int)ppiVar7[(int)piStack_102e8 + 0x15]) {
                if (piVar5 == ppiVar6[1]) {
                  FUN_0047a948();
                }
                iVar12 = *(int *)((int)pvStack_102e4 + 8) + 0x14 + piVar5[3] * 0x24;
                iStack_10280 = *(int *)(iVar12 + 4);
                dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar12);
                if (piVar5 == ppiVar6[1]) {
                  FUN_0047a948();
                }
                piVar17 = (int *)GameBoard_GetPowerRec
                                           ((void *)(*(int *)((int)pvStack_102e4 + 8) + 0x14 +
                                                    piVar5[3] * 0x24),aiStack_10170,
                                            (int *)&piStack_102e8);
                dStack_102a8 = (double)CONCAT44(dStack_102a8._4_4_,piVar17);
                if ((*piVar17 == 0) || (*piVar17 != dStack_102c8._0_4_)) {
                  FUN_0047a948();
                }
                if (*(int *)(dStack_102a8._0_4_ + 4) == iStack_10280) {
                  if (piVar5 == ppiVar6[1]) {
                    FUN_0047a948();
                  }
                  iVar12 = (int)piStack_102e8 * 0x100;
                  dStack_102a8 = (double)(int)piStack_102e0 * 0.1;
                  dStack_102c8 = (double)(int)param_2;
                  ppiVar7 = FUN_0041c270(&DAT_00baed7c,(int **)&uStack_102b8);
                  if ((double)local_a808[piVar5[3] + iVar12] <
                      ((double)(int)ppiVar7[(int)piStack_102e8 + 0x15] * dStack_102a8) /
                      dStack_102c8) {
                    if (piVar5 == ppiVar6[1]) {
                      FUN_0047a948();
                    }
                    FUN_0041c270(&DAT_00baed7c,(int **)&uStack_102b8);
                    uVar25 = FloatToInt64(extraout_ECX_00,piStack_102e8);
                    piVar17 = ppiVar6[1];
                    local_a808[piVar5[3] + iVar12] = (int)uVar25;
                    if (piVar5 == piVar17) {
                      FUN_0047a948();
                    }
                    if (0x14 < local_a808[piVar5[3] + iVar12]) {
                      if (piVar5 == ppiVar6[1]) {
                        FUN_0047a948();
                      }
                      local_a808[piVar5[3] + iVar12] = 0x14;
                    }
                  }
                }
                else {
                  if (piVar5 == ppiVar6[1]) {
                    FUN_0047a948();
                  }
                  iVar12 = (int)piStack_102e8 * 0x100;
                  dStack_102a8 = (double)(int)piStack_102e0 * 0.1 * 0.5;
                  dStack_102c8 = (double)(int)param_2;
                  ppiVar7 = FUN_0041c270(&DAT_00baed7c,(int **)&uStack_102b8);
                  if ((double)local_a808[piVar5[3] + iVar12] <
                      ((double)(int)ppiVar7[(int)piStack_102e8 + 0x15] * dStack_102a8) /
                      dStack_102c8) {
                    if (piVar5 == ppiVar6[1]) {
                      FUN_0047a948();
                    }
                    FUN_0041c270(&DAT_00baed7c,(int **)&uStack_102b8);
                    uVar25 = FloatToInt64(extraout_ECX,piStack_102e8);
                    piVar17 = ppiVar6[1];
                    local_a808[piVar5[3] + iVar12] = (int)uVar25;
                    if (piVar5 == piVar17) {
                      FUN_0047a948();
                    }
                    if (10 < local_a808[piVar5[3] + iVar12]) {
                      if (piVar5 == ppiVar6[1]) {
                        FUN_0047a948();
                      }
                      local_a808[piVar5[3] + iVar12] = 10;
                    }
                  }
                }
              }
              FUN_0040f400((int *)&ppiStack_102b0);
            }
          }
        }
        iVar12 = *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2404);
        piStack_102e8 = (int *)((int)piStack_102e8 + 1);
      } while ((int)piStack_102e8 < iVar12);
    }
    FUN_0040f380((int *)&puStack_102d8);
  }
  iVar12 = **(int **)(*(int *)((int)pvStack_102e4 + 8) + 0x2454);
  piVar5 = (int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2450);
  uStack_102b8 = CONCAT44(iVar12,piVar5);
  do {
    iStack_10280 = *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2454);
    if ((piVar5 == (int *)0x0) || (piVar5 != (int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2450))) {
      FUN_0047a948();
    }
    piStack_102ec = *(int **)((int)pvStack_102e4 + 8);
    if (iVar12 == iStack_10280) {
      fVar18 = (float10)_g_NearEndGameFactor;
      piStack_102e8 = (int *)0x0;
      pvVar15 = pvStack_102e4;
      if (0 < *(int *)((int)piStack_102ec + 0x2404)) {
        do {
          iVar12 = 0;
          if (0 < *(int *)((int)piStack_102ec + 0x2400)) {
            pvStack_102d0 = (void *)aiStack_10278[(int)piStack_102e8];
            piStack_102e0 = local_a808 + (int)piStack_102e8 * 0x100;
            pcStack_102dc = (char *)0x0;
            iVar14 = (int)piStack_102e8 << 0xb;
            do {
              pvStack_102d0 = (void *)((int)pvStack_102d0 + *piStack_102e0);
              iVar16 = *(int *)((int)&DAT_0058f8ec + iVar14);
              if (((-1 < iVar16) &&
                  (((0 < iVar16 || (*(int *)((int)&DAT_0058f8e8 + iVar14) != 0)) &&
                   (-1 < *(int *)((int)&DAT_005460ec + iVar14))))) &&
                 (((0 < *(int *)((int)&DAT_005460ec + iVar14) ||
                   (*(int *)((int)&DAT_005460e8 + iVar14) != 0)) &&
                  (((&g_AllyDesignation_A)[iVar12 * 2] & (&DAT_004d2e14)[iVar12 * 2]) == 0xffffffff)
                  ))) {
                pvStack_102d0 = (void *)((int)pvStack_102d0 + *(int *)((int)&DAT_005508e8 + iVar14))
                ;
              }
              if (((*(int *)((int)&DAT_006040ec + iVar14) < 0) ||
                  ((*(int *)((int)&DAT_006040ec + iVar14) < 1 &&
                   (*(int *)((int)&g_AttackCount + iVar14) == 0)))) ||
                 (((&g_AllyDesignation_A)[iVar12 * 2] & (&DAT_004d2e14)[iVar12 * 2]) != 0xffffffff))
              {
                if ((((((-1 < *(int *)((int)&DAT_005a48ec + iVar14)) &&
                       (((0 < *(int *)((int)&DAT_005a48ec + iVar14) ||
                         (10 < *(uint *)((int)&g_AttackHistory + iVar14))) &&
                        (((&g_AllyDesignation_A)[iVar12 * 2] & (&DAT_004d2e14)[iVar12 * 2]) ==
                         0xffffffff)))) && (-1 < iVar16)) &&
                     ((0 < iVar16 || (*(int *)((int)&DAT_0058f8e8 + iVar14) != 0)))) &&
                    ((-1 < *(int *)((int)&DAT_005460ec + iVar14) &&
                     ((0 < *(int *)((int)&DAT_005460ec + iVar14) ||
                      (*(int *)((int)&DAT_005460e8 + iVar14) != 0)))))) &&
                   ((pcStack_102dc[(int)piStack_102ec + 3] == '\0' ||
                    (SPR == *(ushort *)((int)piStack_102ec + 0x244a))))) {
                  uStack_102b8 = __allmul(param_2 - aiStack_10008[iVar12],
                                          (int)(param_2 - aiStack_10008[iVar12]) >> 0x1f,
                                          *(uint *)((int)&DAT_005508e8 + iVar14),
                                          *(uint *)((int)&DAT_005508ec + iVar14));
                  uVar25 = FloatToInt64(extraout_ECX_01,(int)((ulonglong)uStack_102b8 >> 0x20));
                  pvStack_102d0 = (void *)uVar25;
                }
              }
              else {
                lVar26 = __allmul(param_2 - aiStack_10008[iVar12],
                                  (int)(param_2 - aiStack_10008[iVar12]) >> 0x1f,
                                  *(uint *)((int)&DAT_005508e8 + iVar14),
                                  *(uint *)((int)&DAT_005508ec + iVar14));
                uVar9 = (uint)((ulonglong)lVar26 >> 0x20);
                dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,uVar9);
                uVar27 = __alldiv((uint)lVar26,uVar9,param_2,(int)param_2 >> 0x1f);
                pvStack_102d0 = (void *)((int)pvStack_102d0 + (int)uVar27);
              }
              iStack_10280 = *(int *)(pcStack_102dc + (int)piStack_102ec + 0x18);
              this_00 = pcStack_102dc + (int)piStack_102ec + 0x14;
              puVar8 = (undefined4 *)
                       GameBoard_GetPowerRec(this_00,aiStack_10170,(int *)&piStack_102e8);
              dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,puVar8);
              if (((char *)*puVar8 == (char *)0x0) || ((char *)*puVar8 != this_00)) {
                FUN_0047a948();
              }
              if (*(int *)(dStack_102c8._0_4_ + 4) != iStack_10280) {
                uVar1 = *(ushort *)(*(int *)((int)pvStack_102e4 + 8) + 0x244a);
                if (((SPR == uVar1) && ((int *)(&DAT_004d2610)[iVar12 * 2] == param_1)) &&
                   ((&DAT_004d2614)[iVar12 * 2] == iVar13)) {
                  iVar16 = (param_2 - aiStack_10008[iVar12]) * 10;
                }
                else {
                  if (((FAL != uVar1) || (aiStack_100b8[(int)piStack_102e8] < 1)) ||
                     (((int *)(&DAT_004d2610)[iVar12 * 2] != param_1 ||
                      ((&DAT_004d2614)[iVar12 * 2] != iVar13)))) goto LAB_0043d475;
                  iVar16 = (int)((param_2 - aiStack_10008[iVar12]) *
                                 aiStack_100b8[(int)piStack_102e8] * 0x14) / (int)param_2;
                }
                pvStack_102d0 = (void *)((int)pvStack_102d0 + iVar16 / (int)param_2);
              }
LAB_0043d475:
              piStack_102ec = *(int **)((int)pvStack_102e4 + 8);
              pcStack_102dc = pcStack_102dc + 0x24;
              piStack_102e0 = piStack_102e0 + 1;
              iVar12 = iVar12 + 1;
              iVar14 = iVar14 + 8;
            } while (iVar12 < *(int *)((int)piStack_102ec + 0x2400));
            fVar18 = (float10)_g_NearEndGameFactor;
            aiStack_10278[(int)piStack_102e8] = (int)pvStack_102d0;
            pvVar15 = pvStack_102d0;
          }
          piVar5 = piStack_102e8;
          piStack_102ec = *(int **)((int)pvStack_102e4 + 8);
          uVar1 = *(ushort *)((int)piStack_102ec + 0x244a);
          if (SPR == uVar1) {
            piStack_102e0 = (int *)(float)(int)param_2;
            uVar25 = FloatToInt64((uint)uVar1,pvVar15);
            iVar12 = (int)uVar25;
            aiStack_10278[(int)piVar5] = aiStack_10278[(int)piVar5] + iVar12;
            piStack_102e0 = (int *)aiStack_10278[(int)piVar5];
            if (iVar12 < 0) {
              aiStack_10220[(int)piVar5] = aiStack_10220[(int)piVar5] + iVar12;
            }
            uVar25 = FloatToInt64(extraout_ECX_02,piStack_102e0);
            aiStack_10278[(int)piVar5] = (int)uVar25;
            uVar25 = FloatToInt64(extraout_ECX_03,(int)(uVar25 >> 0x20));
            pvVar15 = (void *)(uVar25 >> 0x20);
            aiStack_10278[(int)piVar5] = aiStack_10278[(int)piVar5] + (int)uVar25;
            aiStack_10220[(int)piVar5] = aiStack_10220[(int)piVar5] - (int)uVar25;
            fVar18 = extraout_ST0_02;
          }
          else if (FAL == uVar1) {
            piStack_102e0 = (int *)(float)(int)param_2;
            uVar25 = FloatToInt64((uint)uVar1,pvVar15);
            iVar12 = (int)uVar25;
            aiStack_10278[(int)piVar5] = aiStack_10278[(int)piVar5] + iVar12;
            piStack_102e0 = (int *)aiStack_10278[(int)piVar5];
            if (iVar12 < 0) {
              aiStack_10220[(int)piVar5] = aiStack_10220[(int)piVar5] + iVar12;
            }
            uVar25 = FloatToInt64(piStack_102e0,(int)(uVar25 >> 0x20));
            aiStack_10278[(int)piVar5] = (int)uVar25;
            uVar25 = FloatToInt64(extraout_ECX_04,(int)(uVar25 >> 0x20));
            pvVar15 = (void *)(uVar25 >> 0x20);
            aiStack_10278[(int)piVar5] = aiStack_10278[(int)piVar5] + (int)uVar25;
            aiStack_10220[(int)piVar5] = aiStack_10220[(int)piVar5] + (int)uVar25;
            fVar18 = extraout_ST0_03;
          }
          piStack_102e8 = (int *)((int)piVar5 + 1);
        } while ((int)piStack_102e8 < *(int *)((int)piStack_102ec + 0x2404));
      }
      uVar9 = DAT_006240cc;
      aiStack_10278[(int)param_1] = aiStack_10278[(int)param_1] - DAT_0062c57c;
      aiStack_10220[(int)param_1] = aiStack_10220[(int)param_1] - DAT_0062c57c;
      aiStack_10278[(int)param_1] = aiStack_10278[(int)param_1] - DAT_00633ebc;
      aiStack_10220[(int)param_1] = aiStack_10220[(int)param_1] - DAT_00633ebc;
      aiStack_10278[(int)param_1] = aiStack_10278[(int)param_1] + DAT_00633e64 * -0x32;
      aiStack_10220[(int)param_1] = aiStack_10220[(int)param_1] + DAT_00633e64 * -0x32;
      piVar5 = aiStack_10278 + (int)param_1;
      iVar12 = 0;
      dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,DAT_006240cc);
      if (0 < *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2400)) {
        uStack_102b8 = (longlong)(int)param_1;
        piVar17 = (int *)(DAT_0062b0c4 + 0x200);
        do {
          if ((((int *)(&DAT_004d2610)[iVar12 * 2] == param_1) &&
              ((&DAT_004d2614)[iVar12 * 2] == iVar13)) &&
             ((0 < *piVar17 &&
              (((((float10)6.0 < fVar18 && (DAT_00624124 != param_1)) &&
                ((int)(&DAT_0062db5c)[iVar12 * 2] < 1)) &&
               (((int)(&DAT_0062db5c)[iVar12 * 2] < 0 || ((uint)(&DAT_0062db58)[iVar12 * 2] < 1000))
               )))))) {
            (&DAT_0062db58)[iVar12 * 2] = 1000;
            (&DAT_0062db5c)[iVar12 * 2] = 0;
          }
          iVar12 = iVar12 + 1;
          piVar17 = piVar17 + 1;
        } while (iVar12 < *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2400));
      }
      iVar13 = *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2400);
      iVar12 = 0;
      if (0 < iVar13) {
        do {
          uVar9 = uVar9 + (&DAT_0062db58)[iVar12 * 2];
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar13);
      }
      iVar12 = (int)uVar9 >> 0x1f;
      if ((DAT_0062e35c <= iVar12) && ((DAT_0062e35c < iVar12 || (DAT_0062e358 < uVar9)))) {
        DAT_0062e358 = uVar9;
        DAT_0062e35c = iVar12;
      }
      uVar25 = FloatToInt64(iVar13,iVar12);
      *piVar5 = *piVar5 - (int)uVar25;
      aiStack_10220[(int)param_1] = aiStack_10220[(int)param_1] - (int)uVar25;
      *piVar5 = *piVar5 - g_EarlyGameAdjScore;
      aiStack_10220[(int)param_1] = aiStack_10220[(int)param_1] - g_EarlyGameAdjScore;
      if (DAT_00baed68 == '\0') {
        *piVar5 = *piVar5 + iStack_102bc;
      }
      piStack_10298 = *(int **)(*(int *)((int)pvStack_102e4 + 8) + 0x2404);
      piVar17 = (int *)0x0;
      if (0 < (int)piStack_10298) {
        do {
          if (piVar17 != param_1) {
            iVar13 = (int)param_1 * 0x15 + (int)piVar17;
            uVar9 = (&g_AllyTrustScore)[iVar13 * 2];
            iVar12 = (&g_AllyTrustScore_Hi)[iVar13 * 2];
            if ((uVar9 == 0 && iVar12 == 0) ||
               (((uVar9 == 1 && (iVar12 == 0)) && ((int)(&DAT_00634e90)[iVar13] < 0xb)))) {
              iVar13 = (2000 - aiStack_10278[(int)piVar17]) * iStack_10288;
              dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar13);
              uVar25 = FloatToInt64(iVar12,iVar13);
              *piVar5 = *piVar5 + (int)uVar25;
              aiStack_10220[(int)param_1] = aiStack_10220[(int)param_1] + (int)uVar25;
            }
            else if ((((-1 < iVar12) && ((0 < iVar12 || (uVar9 != 0)))) &&
                     (0x13 < (int)(&DAT_00634e90)[iVar13])) ||
                    (((-1 < iVar12 && ((0 < iVar12 || (2 < uVar9)))) && (1 < g_DeceitLevel)))) {
              if ((((param_1 == piStack_1027c) && (iStack_1029c < 0x33)) &&
                  (piVar17 == DAT_004c6bc4)) && (DAT_00baed68 == '\0')) {
                if ((&curr_sc_cnt)[(int)param_1] + 1 < (int)(&curr_sc_cnt)[(int)DAT_004c6bc4]) {
                  uVar9 = iStack_1029c + 0x14;
                  iVar13 = (aiStack_10278[(int)piVar17] + -2000) * uVar9;
                  dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar13);
                }
                else {
                  uVar9 = iStack_1029c + 0x1e;
                  iVar13 = (aiStack_10278[(int)piVar17] + -2000) * uVar9;
                  dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar13);
                }
              }
              else {
                iVar13 = (aiStack_10278[(int)piVar17] + -2000) * iStack_1029c;
                dStack_102c8 = (double)CONCAT44(dStack_102c8._4_4_,iVar13);
              }
              uVar25 = FloatToInt64(iVar13,uVar9);
              *piVar5 = (int)uVar25;
            }
          }
          piVar17 = (int *)((int)piVar17 + 1);
        } while ((int)piVar17 < (int)piStack_10298);
      }
      return;
    }
    uVar9 = 0;
    if (0 < *(int *)((int)piStack_102ec + 0x2404)) {
      piStack_102ec = (int *)0x0;
      do {
        if (piVar5 == (int *)0x0) {
          FUN_0047a948();
        }
        if (iVar12 == piVar5[1]) {
          FUN_0047a948();
        }
        if (*(uint *)(iVar12 + 0x18) == uVar9) {
          if (iVar12 == piVar5[1]) {
            FUN_0047a948();
          }
          iVar14 = *(int *)(iVar12 + 0xc) + (int)piStack_102ec;
          if ((-1 < (int)(&DAT_00535cec)[iVar14 * 2]) &&
             ((0 < (int)(&DAT_00535cec)[iVar14 * 2] || ((&g_EnemyReachScore)[iVar14 * 2] != 0)))) {
            if (iVar12 == piVar5[1]) {
              FUN_0047a948();
            }
            iVar14 = (&g_UnitProvinceReach)[*(int *)(iVar12 + 0xc) + (int)piStack_102ec];
            aiStack_10220[uVar9] = aiStack_10220[uVar9] - iVar14;
            aiStack_10278[uVar9] = aiStack_10278[uVar9] - iVar14;
            if (iVar12 == piVar5[1]) {
              FUN_0047a948();
            }
            if (*(char *)(*(int *)((int)pvStack_102e4 + 8) + 3 + *(int *)(iVar12 + 0xc) * 0x24) !=
                '\0') {
              if (iVar12 == piVar5[1]) {
                FUN_0047a948();
              }
              uVar1 = *(ushort *)
                       (*(int *)((int)pvStack_102e4 + 8) + 0x20 + *(int *)(iVar12 + 0xc) * 0x24);
              uVar10 = uVar1 & 0xff;
              if ((char)(uVar1 >> 8) != 'A') {
                uVar10 = 0x14;
              }
              if (uVar10 != uVar9) goto LAB_0043d19d;
            }
            if (iVar12 == piVar5[1]) {
              FUN_0047a948();
            }
            if (*(int *)(iVar12 + 0x20) != 2) {
              if (iVar12 == piVar5[1]) {
                FUN_0047a948();
              }
              if (*(int *)(iVar12 + 0x20) != 6) goto LAB_0043d19d;
            }
            if ((iVar12 == piVar5[1]) && (FUN_0047a948(), iVar12 == piVar5[1])) {
              FUN_0047a948();
            }
            ppiVar6 = FUN_0041c270(&DAT_00baed7c,(int **)(iVar12 + 0x24));
            uStack_10290 = (double)(int)ppiVar6[uVar9];
            ppiVar6 = FUN_0041c270(&DAT_00baed7c,(int **)(iVar12 + 0x10));
            if (((double)(int)ppiVar6[uVar9] * 0.85 < uStack_10290) && (DAT_00baed68 == '\0')) {
              if ((iVar12 == piVar5[1]) && (FUN_0047a948(), iVar12 == piVar5[1])) {
                FUN_0047a948();
              }
              aiStack_10278[uVar9] =
                   (int)((param_2 - aiStack_10008[*(int *)(iVar12 + 0xc)]) *
                        (&g_UnitProvinceReach)[*(int *)(iVar12 + 0xc) + (int)piStack_102ec]) /
                   (int)param_2 + aiStack_10278[uVar9];
            }
          }
        }
        else {
          if (iVar12 == piVar5[1]) {
            FUN_0047a948();
          }
          iVar14 = *(int *)(iVar12 + 0xc) + (int)piStack_102ec;
          if ((-1 < (int)(&DAT_0058f8ec)[iVar14 * 2]) &&
             ((0 < (int)(&DAT_0058f8ec)[iVar14 * 2] || ((&DAT_0058f8e8)[iVar14 * 2] != 0)))) {
            if (iVar12 == piVar5[1]) {
              FUN_0047a948();
            }
            aiStack_10278[uVar9] =
                 aiStack_10278[uVar9] +
                 (&g_UnitProvinceReach)[*(int *)(iVar12 + 0xc) + (int)piStack_102ec];
            if (iVar12 == piVar5[1]) {
              FUN_0047a948();
            }
            iVar14 = *(int *)(iVar12 + 0xc) + (int)piStack_102ec;
            if (*(int *)(&DAT_005164e8 + iVar14 * 8) == 0 &&
                *(int *)(&DAT_005164ec + iVar14 * 8) == 0) {
              if ((iVar12 == piVar5[1]) && (FUN_0047a948(), iVar12 == piVar5[1])) {
                FUN_0047a948();
              }
              iVar14 = (int)((param_2 - aiStack_10008[*(int *)(iVar12 + 0xc)]) *
                            (&g_UnitProvinceReach)[*(int *)(iVar12 + 0xc) + (int)piStack_102ec]) /
                       (int)param_2;
              aiStack_10220[uVar9] = aiStack_10220[uVar9] - iVar14;
              aiStack_10278[uVar9] = aiStack_10278[uVar9] - iVar14;
            }
          }
        }
LAB_0043d19d:
        piStack_102ec = (int *)((int)piStack_102ec + 0x100);
        uVar9 = uVar9 + 1;
      } while ((int)uVar9 < *(int *)(*(int *)((int)pvStack_102e4 + 8) + 0x2404));
    }
    UnitList_Advance((int *)&uStack_102b8);
    iVar12 = uStack_102b8._4_4_;
    piVar5 = (int *)uStack_102b8;
  } while( true );
}

