
void __fastcall STABBED(int param_1)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  int *piVar4;
  uint uVar5;
  short sVar6;
  void *pvVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  _AFX_AYGSHELL_STATE *this;
  rsize_t rVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ushort *puVar17;
  ushort uStack_92;
  uint uStack_90;
  uint uStack_8c;
  uint local_88;
  int local_84;
  int iStack_80;
  void *pvStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int *piStack_6c;
  int iStack_68;
  int *piStack_64;
  int iStack_5c;
  int iStack_54;
  int aiStack_50 [2];
  int aiStack_48 [2];
  int aiStack_40 [2];
  int aiStack_38 [2];
  undefined4 auStack_30 [3];
  undefined4 auStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_00496a48;
  local_14 = ExceptionList;
  uVar8 = DAT_004c8db8 ^ (uint)&stack0xffffff58;
  ExceptionList = &local_14;
  local_88 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_84 = param_1;
  piVar9 = FUN_0047020b();
  iVar16 = 0;
  if (piVar9 == (int *)0x0) {
    piVar9 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar10 = (**(code **)(*piVar9 + 0xc))(uVar8);
  sVar6 = FAL;
  sVar3 = SPR;
  pvStack_7c = (void *)(iVar10 + 0x10);
  iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar15 = 0;
  iStack_c = 0;
  if (0 < iVar10) {
    do {
      iVar14 = 0;
      iVar11 = iVar16;
      if (0 < iVar10) {
        do {
          *(undefined4 *)((int)&g_StabFlag + iVar11) = 0;
          *(undefined4 *)((int)&DAT_0062b7b0 + iVar11) = 0;
          *(undefined4 *)((int)&DAT_0062b0c8 + iVar11) = 0;
          *(undefined4 *)((int)&g_PeaceSignal + iVar11) = 0;
          if (sVar3 == *(short *)(*(int *)(param_1 + 8) + 0x244a)) {
            *(undefined4 *)((int)&DAT_0062c580 + iVar11) = 0;
          }
          if (sVar6 == *(short *)(*(int *)(local_84 + 8) + 0x244a)) {
            *(undefined4 *)((int)&DAT_0062be98 + iVar11) = 0;
          }
          iVar14 = iVar14 + 1;
          iVar11 = iVar11 + 4;
          param_1 = local_84;
        } while (iVar14 < *(int *)(*(int *)(local_84 + 8) + 0x2404));
      }
      iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar15 = iVar15 + 1;
      iVar16 = iVar16 + 0x54;
    } while (iVar15 < iVar10);
  }
  iVar16 = *(int *)(param_1 + 8);
  iVar10 = *(int *)(iVar16 + 0x2404);
  uStack_90 = 0;
  if (0 < iVar10) {
    do {
      uStack_8c = 0;
      if (0 < iVar10) {
        do {
          iStack_78 = iVar16 + 0x2450;
          iStack_74 = **(int **)(iVar16 + 0x2454);
          uStack_92 = uStack_92 & 0xff00;
          while( true ) {
            iVar15 = iStack_74;
            iVar10 = iStack_78;
            iVar16 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
            if ((iStack_78 == 0) || (iStack_78 != *(int *)(param_1 + 8) + 0x2450)) {
              FUN_0047a948();
            }
            if (iVar15 == iVar16) break;
            if (iVar10 == 0) {
              FUN_0047a948();
            }
            if (iVar15 == *(int *)(iVar10 + 4)) {
              FUN_0047a948();
            }
            if (*(uint *)(iVar15 + 0x18) == uStack_8c) {
              if (iVar15 == *(int *)(iVar10 + 4)) {
                FUN_0047a948();
              }
              if (*(uint *)(iVar15 + 0x18) != uStack_90) {
                if (iVar15 == *(int *)(iVar10 + 4)) {
                  FUN_0047a948();
                }
                if (*(char *)(*(int *)(param_1 + 8) + 3 + *(int *)(iVar15 + 0x10) * 0x24) != '\0') {
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  uVar2 = *(ushort *)(*(int *)(param_1 + 8) + 0x20 + *(int *)(iVar15 + 0x10) * 0x24)
                  ;
                  uVar8 = uVar2 & 0xff;
                  if ((char)(uVar2 >> 8) != 'A') {
                    uVar8 = 0x14;
                  }
                  if (uVar8 == uStack_90) {
                    uStack_92 = CONCAT11(uStack_92._1_1_,1);
                  }
                }
              }
            }
            UnitList_Advance(&iStack_78);
          }
          iStack_74 = **(int **)(*(int *)(param_1 + 8) + 0x2490);
          iStack_78 = *(int *)(param_1 + 8) + 0x248c;
          while( true ) {
            iVar15 = iStack_74;
            iVar10 = iStack_78;
            iVar16 = *(int *)(*(int *)(param_1 + 8) + 0x2490);
            if ((iStack_78 == 0) || (iStack_78 != *(int *)(param_1 + 8) + 0x248c)) {
              FUN_0047a948();
            }
            if (iVar15 == iVar16) break;
            if (iVar10 == 0) {
              FUN_0047a948();
            }
            if (iVar15 == *(int *)(iVar10 + 4)) {
              FUN_0047a948();
            }
            if (*(uint *)(iVar15 + 0x18) == uStack_8c) {
              if (iVar15 == *(int *)(iVar10 + 4)) {
                FUN_0047a948();
              }
              if (*(uint *)(iVar15 + 0x18) != uStack_90) {
                if (iVar15 == *(int *)(iVar10 + 4)) {
                  FUN_0047a948();
                }
                if (*(int *)(iVar15 + 0x20) == 2) {
LAB_0042d477:
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  iStack_80 = *(int *)(iVar15 + 0x24);
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  if ((*(uint *)(iVar15 + 0x18) == local_88) || (uStack_90 != local_88)) {
LAB_0042d504:
                    if (iVar15 == *(int *)(iVar10 + 4)) {
                      FUN_0047a948();
                    }
                    if ((*(uint *)(iVar15 + 0x18) != local_88) || (uStack_90 == local_88))
                    goto LAB_0042d558;
                    piVar9 = aiStack_38;
                    goto LAB_0042d533;
                  }
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  iVar16 = *(int *)(iVar15 + 0x18);
                  iStack_54 = (&DAT_00bb702c)[iVar16 * 3];
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  puVar12 = (undefined4 *)
                            GameBoard_GetPowerRec
                                      (&DAT_00bb7028 + *(int *)(iVar15 + 0x18) * 0xc,aiStack_40,
                                       &iStack_80);
                  if (((undefined *)*puVar12 == (undefined *)0x0) ||
                     ((undefined *)*puVar12 != &DAT_00bb7028 + iVar16 * 0xc)) {
                    FUN_0047a948();
                  }
                  if (puVar12[1] == iStack_54) goto LAB_0042d504;
                }
                else {
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  if (*(int *)(iVar15 + 0x20) == 6) goto LAB_0042d477;
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  if (*(int *)(iVar15 + 0x20) != 4) goto LAB_0042d558;
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  iStack_80 = *(int *)(iVar15 + 0x30);
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  if ((*(uint *)(iVar15 + 0x18) != local_88) && (uStack_90 == local_88)) {
                    if (iVar15 == *(int *)(iVar10 + 4)) {
                      FUN_0047a948();
                    }
                    iVar16 = *(int *)(iVar15 + 0x18);
                    iStack_5c = (&DAT_00bb702c)[iVar16 * 3];
                    if (iVar15 == *(int *)(iVar10 + 4)) {
                      FUN_0047a948();
                    }
                    puVar12 = (undefined4 *)
                              GameBoard_GetPowerRec
                                        (&DAT_00bb7028 + *(int *)(iVar15 + 0x18) * 0xc,aiStack_50,
                                         &iStack_80);
                    if (((undefined *)*puVar12 == (undefined *)0x0) ||
                       ((undefined *)*puVar12 != &DAT_00bb7028 + iVar16 * 0xc)) {
                      FUN_0047a948();
                    }
                    if (puVar12[1] == iStack_5c) goto LAB_0042d437;
                    goto LAB_0042d553;
                  }
LAB_0042d437:
                  if (iVar15 == *(int *)(iVar10 + 4)) {
                    FUN_0047a948();
                  }
                  if ((*(uint *)(iVar15 + 0x18) != local_88) || (uStack_90 == local_88))
                  goto LAB_0042d558;
                  piVar9 = aiStack_48;
LAB_0042d533:
                  iVar16 = uStack_90 * 0xc;
                  iVar10 = (&DAT_00bb6f2c)[uStack_90 * 3];
                  puVar12 = (undefined4 *)
                            GameBoard_GetPowerRec(&DAT_00bb6f28 + iVar16,piVar9,&iStack_80);
                  if (((undefined *)*puVar12 == (undefined *)0x0) ||
                     ((undefined *)*puVar12 != &DAT_00bb6f28 + iVar16)) {
                    FUN_0047a948();
                  }
                  if (puVar12[1] == iVar10) goto LAB_0042d558;
                }
LAB_0042d553:
                uStack_92 = CONCAT11(uStack_92._1_1_,1);
              }
            }
LAB_0042d558:
            UnitList_Advance(&iStack_78);
            param_1 = local_84;
          }
          if ((char)uStack_92 == '\x01') {
            iStack_80 = uStack_90 * 0x15 + uStack_8c;
            (&g_StabFlag)[iStack_80] = 1;
            if (uStack_90 == local_88) {
              puVar17 = &uStack_92;
              uStack_92 = (ushort)uStack_8c & 0xff | 0x4100;
              this = _AfxAygshellState();
              GetProvinceToken(this,puVar17);
              SEND_LOG(&pvStack_7c,(wchar_t *)"We have been stabbed by (%s) during the turn");
              pvVar7 = pvStack_7c;
              piVar9 = (int *)((int)pvStack_7c + -0x10);
              iStack_70 = 10;
              puVar12 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_7c + -0x10) + 0x10))();
              if ((*(int *)((int)pvVar7 + -4) < 0) || (puVar12 != (undefined4 *)*piVar9)) {
                piVar9 = (int *)(**(code **)*puVar12)(*(undefined4 *)((int)pvVar7 + -0xc),1);
                if (piVar9 == (int *)0x0) goto LAB_0042db43;
                piVar9[1] = *(int *)((int)pvVar7 + -0xc);
                rVar13 = *(int *)((int)pvVar7 + -0xc) + 1;
                _memcpy_s(piVar9 + 4,rVar13,pvVar7,rVar13);
              }
              else {
                LOCK();
                *(int *)((int)pvVar7 + -4) = *(int *)((int)pvVar7 + -4) + 1;
                UNLOCK();
              }
              piStack_6c = piVar9 + 4;
              iStack_c._0_1_ = 1;
              BuildAllianceMsg(&DAT_00bbf638,auStack_30,&iStack_70);
              iStack_c = (uint)iStack_c._1_3_ << 8;
              piVar4 = piVar9 + 3;
              LOCK();
              iVar16 = *piVar4;
              *piVar4 = *piVar4 + -1;
              UNLOCK();
              if (iVar16 == 1 || iVar16 + -1 < 0) {
                (**(code **)(*(int *)*piVar9 + 4))(piVar9);
              }
              DAT_00baed5f = 1;
              SEND_LOG(&pvStack_7c,(wchar_t *)"Enemy desired because of stab");
              pvVar7 = pvStack_7c;
              piVar9 = (int *)((int)pvStack_7c + -0x10);
              iStack_68 = 0x1e;
              puVar12 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_7c + -0x10) + 0x10))();
              if ((*(int *)((int)pvVar7 + -4) < 0) || (puVar12 != (undefined4 *)*piVar9)) {
                piVar9 = (int *)(**(code **)*puVar12)(*(undefined4 *)((int)pvVar7 + -0xc),1);
                if (piVar9 == (int *)0x0) {
LAB_0042db43:
                  ErrorExit();
                  return;
                }
                piVar9[1] = *(int *)((int)pvVar7 + -0xc);
                rVar13 = *(int *)((int)pvVar7 + -0xc) + 1;
                _memcpy_s(piVar9 + 4,rVar13,pvVar7,rVar13);
              }
              else {
                LOCK();
                *(int *)((int)pvVar7 + -4) = *(int *)((int)pvVar7 + -4) + 1;
                UNLOCK();
              }
              piStack_64 = piVar9 + 4;
              iStack_c._0_1_ = 2;
              BuildAllianceMsg(&DAT_00bbf638,auStack_24,&iStack_68);
              iStack_c = (uint)iStack_c._1_3_ << 8;
              piVar4 = piVar9 + 3;
              LOCK();
              iVar16 = *piVar4;
              *piVar4 = *piVar4 + -1;
              UNLOCK();
              if (iVar16 == 1 || iVar16 + -1 < 0) {
                (**(code **)(*(int *)*piVar9 + 4))(piVar9);
              }
              uVar8 = uStack_8c;
              cVar1 = *(char *)((int)*(int **)((&DAT_00bb6f2c)[uStack_8c * 3] + 4) + 0x11);
              piVar9 = *(int **)((&DAT_00bb6f2c)[uStack_8c * 3] + 4);
              while (cVar1 == '\0') {
                FUN_00401950((int *)piVar9[2]);
                piVar4 = (int *)*piVar9;
                _free(piVar9);
                piVar9 = piVar4;
                cVar1 = *(char *)((int)piVar4 + 0x11);
              }
              *(undefined4 *)((&DAT_00bb6f2c)[uVar8 * 3] + 4) = (&DAT_00bb6f2c)[uVar8 * 3];
              (&DAT_00bb6f30)[uVar8 * 3] = 0;
              *(undefined4 *)(&DAT_00bb6f2c)[uVar8 * 3] = (&DAT_00bb6f2c)[uVar8 * 3];
              *(undefined4 *)((&DAT_00bb6f2c)[uVar8 * 3] + 8) = (&DAT_00bb6f2c)[uVar8 * 3];
              cVar1 = *(char *)((int)*(int **)((&DAT_00bb702c)[uVar8 * 3] + 4) + 0x11);
              piVar9 = *(int **)((&DAT_00bb702c)[uVar8 * 3] + 4);
              param_1 = local_84;
              while (local_84 = param_1, cVar1 == '\0') {
                FUN_00401950((int *)piVar9[2]);
                piVar4 = (int *)*piVar9;
                _free(piVar9);
                piVar9 = piVar4;
                param_1 = local_84;
                cVar1 = *(char *)((int)piVar4 + 0x11);
              }
              *(undefined4 *)((&DAT_00bb702c)[uVar8 * 3] + 4) = (&DAT_00bb702c)[uVar8 * 3];
              (&DAT_00bb7030)[uVar8 * 3] = 0;
              *(undefined4 *)(&DAT_00bb702c)[uVar8 * 3] = (&DAT_00bb702c)[uVar8 * 3];
              *(undefined4 *)((&DAT_00bb702c)[uVar8 * 3] + 8) = (&DAT_00bb702c)[uVar8 * 3];
            }
            uVar8 = uStack_90;
            if (local_88 == uStack_8c) {
              cVar1 = *(char *)((int)*(int **)((&DAT_00bb6f2c)[uStack_90 * 3] + 4) + 0x11);
              piVar9 = *(int **)((&DAT_00bb6f2c)[uStack_90 * 3] + 4);
              while (cVar1 == '\0') {
                FUN_00401950((int *)piVar9[2]);
                piVar4 = (int *)*piVar9;
                _free(piVar9);
                piVar9 = piVar4;
                cVar1 = *(char *)((int)piVar4 + 0x11);
              }
              *(undefined4 *)((&DAT_00bb6f2c)[uVar8 * 3] + 4) = (&DAT_00bb6f2c)[uVar8 * 3];
              (&DAT_00bb6f30)[uVar8 * 3] = 0;
              *(undefined4 *)(&DAT_00bb6f2c)[uVar8 * 3] = (&DAT_00bb6f2c)[uVar8 * 3];
              *(undefined4 *)((&DAT_00bb6f2c)[uVar8 * 3] + 8) = (&DAT_00bb6f2c)[uVar8 * 3];
              cVar1 = *(char *)((int)*(int **)((&DAT_00bb702c)[uVar8 * 3] + 4) + 0x11);
              piVar9 = *(int **)((&DAT_00bb702c)[uVar8 * 3] + 4);
              param_1 = local_84;
              while (local_84 = param_1, cVar1 == '\0') {
                FUN_00401950((int *)piVar9[2]);
                piVar4 = (int *)*piVar9;
                _free(piVar9);
                piVar9 = piVar4;
                param_1 = local_84;
                cVar1 = *(char *)((int)piVar4 + 0x11);
              }
              *(undefined4 *)((&DAT_00bb702c)[uVar8 * 3] + 4) = (&DAT_00bb702c)[uVar8 * 3];
              (&DAT_00bb7030)[uVar8 * 3] = 0;
              *(undefined4 *)(&DAT_00bb702c)[uVar8 * 3] = (&DAT_00bb702c)[uVar8 * 3];
              *(undefined4 *)((&DAT_00bb702c)[uVar8 * 3] + 8) = (&DAT_00bb702c)[uVar8 * 3];
            }
            sVar3 = *(short *)(*(int *)(param_1 + 8) + 0x244a);
            if ((SUM == sVar3) || (FAL == sVar3)) {
              (&DAT_0062c580)[iStack_80] = 1;
              (&DAT_0062c580)[uStack_8c * 0x15 + uStack_90] = 1;
            }
            sVar3 = *(short *)(*(int *)(param_1 + 8) + 0x244a);
            if (((AUT == sVar3) || (WIN == sVar3)) || (SPR == sVar3)) {
              (&DAT_0062be98)[iStack_80] = 1;
              (&DAT_0062be98)[uStack_8c * 0x15 + uStack_90] = 1;
            }
            (&g_AllyTrustScore)[iStack_80 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iStack_80 * 2] = 0;
            iVar16 = uStack_8c * 0x15 + uStack_90;
            (&g_AllyTrustScore)[iVar16 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar16 * 2] = 0;
            if (uStack_90 == local_88) {
              if ((g_OpeningStickyMode == '\x01') && (uStack_8c != g_OpeningEnemy)) {
                g_OpeningStickyMode = '\0';
              }
              if (((-1 < (int)DAT_004c6bc4) && (uStack_8c == DAT_004c6bc4)) &&
                 (DAT_004c6bc4 = 0xffffffff, -1 < (int)DAT_004c6bc8)) {
                DAT_004c6bc4 = DAT_004c6bc8;
                DAT_004c6bc8 = 0xffffffff;
                if (-1 < (int)DAT_004c6bcc) {
                  DAT_004c6bc8 = DAT_004c6bcc;
                  DAT_004c6bcc = 0xffffffff;
                }
              }
            }
            uVar5 = DAT_004c6bcc;
            uVar8 = DAT_004c6bc8;
            if ((((uStack_8c == local_88) && (-1 < (int)DAT_004c6bc4)) &&
                (uStack_90 == DAT_004c6bc4)) &&
               ((DAT_004c6bc4 = 0xffffffff, -1 < (int)DAT_004c6bc8 &&
                (DAT_004c6bc8 = 0xffffffff, DAT_004c6bc4 = uVar8, -1 < (int)DAT_004c6bcc)))) {
              DAT_004c6bcc = 0xffffffff;
              DAT_004c6bc8 = uVar5;
            }
            uVar8 = DAT_004c6bcc;
            if (((uStack_90 == local_88) && (-1 < (int)DAT_004c6bc8)) && (uStack_8c == DAT_004c6bc8)
               ) {
              DAT_004c6bc8 = 0xffffffff;
            }
            if ((((uStack_8c == local_88) && (-1 < (int)DAT_004c6bc8)) &&
                (uStack_90 == DAT_004c6bc8)) && (DAT_004c6bc8 = 0xffffffff, -1 < (int)DAT_004c6bcc))
            {
              DAT_004c6bcc = 0xffffffff;
              DAT_004c6bc8 = uVar8;
            }
            if (((uStack_90 == local_88) && (-1 < (int)DAT_004c6bcc)) && (uStack_8c == DAT_004c6bcc)
               ) {
              DAT_004c6bcc = 0xffffffff;
            }
            if (((uStack_8c == local_88) && (-1 < (int)DAT_004c6bcc)) && (uStack_90 == DAT_004c6bcc)
               ) {
              DAT_004c6bcc = 0xffffffff;
            }
          }
          iVar16 = *(int *)(param_1 + 8);
          uStack_8c = uStack_8c + 1;
        } while ((int)uStack_8c < *(int *)(iVar16 + 0x2404));
      }
      iVar16 = *(int *)(param_1 + 8);
      iVar10 = *(int *)(iVar16 + 0x2404);
      uStack_90 = uStack_90 + 1;
    } while ((int)uStack_90 < iVar10);
  }
  iStack_c = 0xffffffff;
  piVar9 = (int *)((int)pvStack_7c + -4);
  LOCK();
  iVar16 = *piVar9;
  *piVar9 = *piVar9 + -1;
  UNLOCK();
  if (iVar16 == 1 || iVar16 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_7c + -0x10) + 4))((undefined4 *)((int)pvStack_7c + -0x10));
  }
  ExceptionList = local_14;
  return;
}

