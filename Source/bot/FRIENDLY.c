
void __fastcall FRIENDLY(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  _AFX_AYGSHELL_STATE *this;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  ushort *puVar10;
  undefined4 uStack_4c;
  uint uStack_48;
  int local_44;
  uint uStack_40;
  int iStack_3c;
  uint local_38;
  int iStack_34;
  int *piStack_30;
  int iStack_2c;
  undefined1 auStack_28 [8];
  undefined4 auStack_20 [3];
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_00496a80;
  local_14 = ExceptionList;
  uVar2 = DAT_004c8db8 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  local_38 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_44 = param_1;
  piVar3 = FUN_0047020b();
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_2c = (**(code **)(*piVar3 + 0xc))(uVar2);
  iStack_2c = iStack_2c + 0x10;
  iVar9 = *(int *)(param_1 + 8);
  iVar5 = *(int *)(iVar9 + 0x2404);
  iStack_c = 0;
  uStack_48 = 0;
  if (0 < iVar5) {
    iStack_3c = 0;
    piStack_30 = &DAT_00634e90;
    do {
      uStack_40 = 0;
      if (0 < iVar5) {
        iStack_34 = uStack_48 * 8;
        piVar3 = piStack_30;
        do {
          if (uStack_48 != uStack_40) {
            if ((&curr_sc_cnt)[uStack_40] == 0) {
              iVar5 = iStack_3c + uStack_40;
              (&g_AllyTrustScore)[iVar5 * 2] = 0;
              (&g_AllyTrustScore_Hi)[iVar5 * 2] = 0;
              *(undefined4 *)(&DAT_004d4610 + iVar5 * 8) = 0;
              *(undefined4 *)(&DAT_004d4614 + iVar5 * 8) = 0;
              (&DAT_00634e90)[iVar5] = 0;
              *piVar3 = 0;
              *(undefined4 *)((int)&g_AllyTrustScore + iStack_34) = 0;
              *(undefined4 *)((int)&g_AllyTrustScore_Hi + iStack_34) = 0;
              *(undefined4 *)(&DAT_004d4610 + iStack_34) = 0;
              *(undefined4 *)(&DAT_004d4614 + iStack_34) = 0;
            }
            else {
              iVar5 = iStack_3c + uStack_40;
              if ((&g_StabFlag)[iVar5] == 1) {
                if (((*piVar3 < 10) || ((int)(&DAT_00634e90)[iVar5] < 10)) &&
                   ((int)(&DAT_006340c0)[iVar5] < 4)) {
                  if (4 < *piVar3) {
                    piVar4 = &DAT_00634e90 + iVar5;
                    if (4 < (int)(&DAT_00634e90)[iVar5]) {
                      iVar9 = (&DAT_0062a2f8)[iVar5];
                      *piVar4 = (&DAT_00634e90)[iVar5] + iVar9 * -10 + -10;
                      *piVar3 = *piVar3 + iVar9 * -10 + -10;
                      (&DAT_0062a2f8)[iVar5] = iVar9 + 1;
                      goto LAB_0042dd6c;
                    }
                  }
                  piVar4 = &DAT_00634e90 + iVar5;
                  *piVar4 = 0;
                  *piVar3 = 0;
                }
                else {
                  iVar9 = (&DAT_0062a2f8)[iVar5];
                  piVar4 = &DAT_00634e90 + iVar5;
                  *piVar4 = *piVar4 + iVar9 * -0x14 + -0x46;
                  *piVar3 = *piVar3 + iVar9 * -0x14 + -0x46;
                  (&DAT_0062a2f8)[iVar5] = iVar9 + 1;
                  if (0 < *(int *)(*(int *)(local_44 + 8) + 0x2404)) {
                    uVar2 = 0;
                    do {
                      if ((uStack_48 == local_38) && (uVar2 != uStack_40)) {
                        (&DAT_004cf4c0)[uVar2 * 2] = 0;
                        (&DAT_004cf4c4)[uVar2 * 2] = 0;
                      }
                      uVar2 = uVar2 + 1;
                    } while ((int)uVar2 < *(int *)(*(int *)(local_44 + 8) + 0x2404));
                  }
                }
LAB_0042dd6c:
                if (*piVar4 < -0x32) {
                  *piVar4 = -0x32;
                }
                if (*piVar3 < -0x32) {
                  *piVar3 = -0x32;
                }
              }
              else if ((&DAT_0062b0c8)[iVar5] == 1) {
                if (0 < (int)(&DAT_00634e90)[iVar5]) {
                  (&DAT_00634e90)[iVar5] = 0;
                }
                if (0 < *piVar3) {
                  *piVar3 = 0;
                }
              }
              else if (((((&g_StabFlag)[iVar5] == 0) && ((&DAT_0062c580)[iVar5] == 0)) &&
                       ((&DAT_0062be98)[iVar5] == 0)) &&
                      ((FAL == *(short *)(iVar9 + 0x244a) || (WIN == *(short *)(iVar9 + 0x244a)))))
              {
                iVar9 = (&g_AllyTrustScore_Hi)[iVar5 * 2];
                iVar7 = (&g_AllyTrustScore)[iVar5 * 2];
                if ((((iVar9 < 0) || ((iVar9 < 1 && (iVar7 == 0)))) ||
                    ((&g_PeaceSignal)[iVar5] != 1)) ||
                   (((&DAT_0062b7b0)[iVar5] != 0 || (iVar1 = (&DAT_00634e90)[iVar5], 0x31 < iVar1)))
                   ) {
                  if (((-1 < *(int *)((int)&g_AllyTrustScore_Hi + iStack_34)) &&
                      (((0 < *(int *)((int)&g_AllyTrustScore_Hi + iStack_34) ||
                        (*(int *)((int)&g_AllyTrustScore + iStack_34) != 0)) &&
                       ((&g_PeaceSignal)[iVar5] == 0)))) && ((int)(&DAT_00634e90)[iVar5] < 0x32)) {
                    (&DAT_00634e90)[iVar5] = (&DAT_00634e90)[iVar5] + 5;
                    goto LAB_0042df0b;
                  }
                  if (((iVar7 != 0 || iVar9 != 0) || ((&DAT_0062b7b0)[iVar5] != 0)) ||
                     (((int)(&DAT_00634e90)[iVar5] < 0 || (g_DeceitLevel < 2)))) {
                    if ((iVar7 == 0 && iVar9 == 0) && ((int)(&DAT_00634e90)[iVar5] < 0)) {
                      iVar9 = (&DAT_00634e90)[iVar5] + 10;
                      (&DAT_00634e90)[iVar5] = iVar9;
                      if (0 < iVar9) {
LAB_0042df04:
                        (&DAT_00634e90)[iVar5] = 0;
                      }
                    }
                    else if ((iVar7 == 0 && iVar9 == 0) &&
                            ((0 < (int)(&DAT_00634e90)[iVar5] && ((&DAT_0062b7b0)[iVar5] == 1))))
                    goto LAB_0042df04;
                    goto LAB_0042df0b;
                  }
                  if (uStack_48 != local_38) {
                    (&g_AllyTrustScore)[iVar5 * 2] = 1;
                    (&g_AllyTrustScore_Hi)[iVar5 * 2] = 0;
                    goto LAB_0042df04;
                  }
LAB_0042df19:
                  if (((((&g_AllyTrustScore)[iVar5 * 2] == 0 &&
                         (&g_AllyTrustScore_Hi)[iVar5 * 2] == 0) && ((&DAT_0062b7b0)[iVar5] == 0))
                      && ((&g_PeaceSignal)[iVar5] == 1)) && (-1 < (int)(&DAT_00634e90)[iVar5])) {
                    (&DAT_004cf4c0)[uStack_40 * 2] = 0;
                    (&DAT_004cf4c4)[uStack_40 * 2] = 0;
                    puVar10 = (ushort *)&uStack_4c;
                    uStack_4c = CONCAT22(uStack_4c._2_2_,(short)uStack_40) & 0xffff00ff | 0x4100;
                    this = _AfxAygshellState();
                    GetProvinceToken(this,puVar10);
                    SEND_LOG(&iStack_2c,(wchar_t *)"I think we are getting a peace signal from (%s)"
                            );
                    uStack_4c = 0x19;
                    piVar4 = FUN_00410b40(auStack_28,&uStack_4c,&iStack_2c);
                    iStack_c._0_1_ = 1;
                    FUN_0041c450(&DAT_00bbf638,auStack_20,piVar4);
                    iStack_c = (uint)iStack_c._1_3_ << 8;
                    FUN_004106b0((int)auStack_28);
                  }
                }
                else {
                  if (g_DeceitLevel == 1) {
                    (&DAT_00634e90)[iVar5] = iVar1 + 5;
                  }
                  else {
                    (&DAT_00634e90)[iVar5] = iVar1 + 10;
                  }
LAB_0042df0b:
                  if (uStack_48 == local_38) goto LAB_0042df19;
                }
                if (0x32 < (int)(&DAT_00634e90)[iVar5]) {
                  (&DAT_00634e90)[iVar5] = 0x32;
                }
              }
            }
          }
          iVar9 = *(int *)(local_44 + 8);
          iStack_34 = iStack_34 + 0xa8;
          uStack_40 = uStack_40 + 1;
          piVar3 = piVar3 + 0x15;
        } while ((int)uStack_40 < *(int *)(iVar9 + 0x2404));
      }
      iVar9 = *(int *)(local_44 + 8);
      iVar5 = *(int *)(iVar9 + 0x2404);
      piStack_30 = piStack_30 + 1;
      iStack_3c = iStack_3c + 0x15;
      uStack_48 = uStack_48 + 1;
      param_1 = local_44;
    } while ((int)uStack_48 < iVar5);
  }
  UpdateRelationHistory(param_1);
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar9 = 0;
  if (0 < iVar5) {
    puVar8 = &g_AllyTrustScore;
    piVar3 = &g_AllyMatrix;
    do {
      iVar7 = 0;
      piVar4 = piVar3;
      puVar6 = puVar8;
      if (0 < iVar5) {
        do {
          if (((int)puVar6[1] < 0) || (((int)puVar6[1] < 1 && (*puVar6 < 5)))) {
            if (*piVar4 == 2) {
              *piVar4 = 1;
            }
          }
          else if (*piVar4 == 1) {
            *piVar4 = 2;
          }
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 2;
          piVar4 = piVar4 + 1;
        } while (iVar7 < *(int *)(*(int *)(local_44 + 8) + 0x2404));
      }
      iVar5 = *(int *)(*(int *)(local_44 + 8) + 0x2404);
      iVar9 = iVar9 + 1;
      piVar3 = piVar3 + 0x15;
      puVar8 = puVar8 + 0x2a;
    } while (iVar9 < iVar5);
  }
  iStack_c = 0xffffffff;
  piVar3 = (int *)(iStack_2c + -4);
  LOCK();
  iVar5 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(iStack_2c + -0x10) + 4))((undefined4 *)(iStack_2c + -0x10));
  }
  ExceptionList = local_14;
  return;
}

