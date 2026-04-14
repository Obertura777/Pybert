
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall ScoreProvinces(void *this,uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  ushort uVar2;
  int *piVar3;
  float fVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int **ppiVar10;
  int *piVar11;
  int **ppiVar12;
  char cVar15;
  uint uVar13;
  uint uVar14;
  int iVar16;
  int **ppiVar17;
  int *piVar18;
  int iVar19;
  void *pvVar20;
  bool bVar21;
  longlong lVar22;
  undefined8 uVar23;
  ulonglong uVar24;
  longlong lVar25;
  int **local_559c;
  int **local_5598;
  int **local_5594;
  int *local_5590;
  int **local_558c;
  int *local_5588;
  char local_5581;
  int *local_5580;
  int **local_557c;
  char local_5575;
  int **local_5574;
  int local_5570;
  int local_556c;
  int **local_5568;
  int *local_5564;
  int *local_5560;
  int *local_555c;
  int **local_5558;
  int *local_5554;
  void *local_554c;
  int **local_5548;
  int *local_5544;
  int **local_553c;
  int **local_5538;
  int *local_5534;
  int **local_5530;
  short local_552c;
  int **local_5528;
  int *local_5524;
  uint local_5520;
  int local_551c;
  int **local_5514;
  uint local_5510;
  int *local_550c;
  int **local_5504;
  int *local_5500;
  int *local_54fc;
  undefined2 local_54f8;
  int *local_54f4;
  int *local_54ec;
  int *local_54e4;
  int local_54dc;
  int local_54d4;
  int *local_54cc;
  int *local_54c4;
  int local_54bc;
  int *local_54b4;
  undefined4 local_54b0;
  int *local_54a4;
  int local_549c;
  int *local_5494;
  int local_548c;
  int *local_5484;
  int local_547c;
  int local_5474;
  int *local_546c;
  undefined4 local_5468;
  int local_545c;
  int local_5454;
  int local_5450 [2];
  int local_5448 [2];
  int local_5440 [2];
  int local_5438 [2];
  int local_5430 [2];
  int local_5428 [2];
  int local_5420 [2];
  int local_5418 [2];
  int local_5410 [2];
  int *local_5408 [5375];
  undefined4 uStack_c;
  
  uStack_c = 0x447470;
  iVar19 = *(int *)((int)this + 8);
  local_5514 = (int **)(uint)*(byte *)(iVar19 + 0x2424);
  local_552c = 0;
  local_54f8 = 0;
  local_557c = (int **)0x0;
  if (0 < *(int *)(iVar19 + 0x2404)) {
    iVar19 = *(int *)(iVar19 + 0x2400);
    do {
      iVar16 = 0;
      if (0 < iVar19) {
        iVar6 = (int)local_557c << 0xb;
        do {
          *(undefined4 *)(&DAT_006190e8 + iVar6) = 0;
          *(undefined4 *)((int)&g_AttackCount + iVar6) = 0;
          *(undefined4 *)(&DAT_0060e8e8 + iVar6) = 0;
          *(undefined4 *)(&DAT_005f98e8 + iVar6) = 0;
          *(undefined4 *)(&g_SCOwnership + iVar6) = 0;
          *(undefined4 *)(&DAT_005164e8 + iVar6) = 0;
          *(undefined4 *)(&DAT_0050bce8 + iVar6) = 0;
          *(undefined4 *)(&DAT_004f6ce8 + iVar6) = 0;
          *(undefined4 *)(&g_MaxProvinceScore + iVar6) = 0;
          *(undefined4 *)((int)&DAT_005508e8 + iVar6) = 1000000;
          *(undefined4 *)(&DAT_005014e8 + iVar6) = 0;
          *(undefined4 *)(&DAT_006190ec + iVar6) = 0;
          *(undefined4 *)((int)&DAT_006040ec + iVar6) = 0;
          *(undefined4 *)(&DAT_0060e8ec + iVar6) = 0;
          *(undefined4 *)(&DAT_005f98ec + iVar6) = 0;
          *(undefined4 *)(&DAT_00520cec + iVar6) = 0;
          *(undefined4 *)(&DAT_005164ec + iVar6) = 0;
          *(undefined4 *)(&DAT_0050bcec + iVar6) = 0;
          *(undefined4 *)(&DAT_004f6cec + iVar6) = 0;
          *(undefined4 *)(&DAT_0055b0ec + iVar6) = 0;
          *(undefined4 *)((int)&DAT_005508ec + iVar6) = 0;
          *(undefined4 *)(&DAT_005014ec + iVar6) = 0;
          iVar19 = *(int *)(*(int *)((int)this + 8) + 0x2400);
          iVar16 = iVar16 + 1;
          iVar6 = iVar6 + 8;
        } while (iVar16 < iVar19);
      }
      local_557c = (int **)((int)local_557c + 1);
    } while ((int)local_557c < *(int *)(*(int *)((int)this + 8) + 0x2404));
  }
  iVar19 = 0;
  do {
    iVar16 = *(int *)((int)this + 8);
    ppiVar17 = (int **)0x0;
    local_557c = (int **)0x0;
    if (0 < *(int *)(iVar16 + 0x2404)) {
      local_5590 = (int *)0x0;
      do {
        iVar6 = 0;
        if (0 < *(int *)(iVar16 + 0x2400)) {
          do {
            if (iVar19 == 0) {
              (&g_ThreatScore)[(int)local_5590 + iVar6] = 0;
            }
            else {
              (&g_ThreatScore)[(iVar19 * 0x15 + (int)ppiVar17) * 0x100 + iVar6] = 0xffffffff;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(*(int *)((int)this + 8) + 0x2400));
        }
        iVar16 = *(int *)((int)this + 8);
        local_5590 = local_5590 + 0x40;
        ppiVar17 = (int **)((int)ppiVar17 + 1);
        local_557c = ppiVar17;
      } while ((int)ppiVar17 < *(int *)(iVar16 + 0x2404));
    }
    iVar19 = iVar19 + 1;
  } while (iVar19 < 2);
  local_5598 = (int **)0x0;
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2400)) {
    local_5574 = local_5408;
    do {
      (&g_ProvinceBase)[(int)local_5598] = 0;
      ppiVar17 = (int **)0x0;
      local_557c = (int **)0x0;
      if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
        puVar9 = &DAT_00540ce8 + (int)local_5598;
        iVar19 = (int)local_5598 * 8;
        ppiVar10 = local_5574;
        do {
          *(undefined4 *)((int)&DAT_0058f8e8 + iVar19) = 0;
          *puVar9 = 0;
          *(undefined4 *)((int)&DAT_005658e8 + iVar19) = 0;
          *(undefined4 *)((int)&DAT_005850e8 + iVar19) = 0;
          *(undefined4 *)((int)&DAT_0057a8e8 + iVar19) = 0;
          *(undefined4 *)((int)&g_ThreatPathScore + iVar19) = 0;
          *(undefined4 *)((int)&DAT_005460e8 + iVar19) = 0;
          *(undefined4 *)((int)&g_EnemyReachScore + iVar19) = 0;
          *(undefined4 *)((int)&DAT_0052b4e8 + iVar19) = 0;
          *(undefined4 *)((int)&DAT_0058f8ec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_005658ec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_005850ec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_0057a8ec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_005700ec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_005460ec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_00535cec + iVar19) = 0;
          *(undefined4 *)((int)&DAT_0052b4ec + iVar19) = 0;
          iVar16 = *(int *)((int)this + 8);
          *ppiVar10 = (int *)0x0;
          ppiVar17 = (int **)((int)ppiVar17 + 1);
          ppiVar10 = ppiVar10 + 1;
          puVar9 = puVar9 + 0x100;
          iVar19 = iVar19 + 0x800;
          local_557c = ppiVar17;
        } while ((int)ppiVar17 < *(int *)(iVar16 + 0x2404));
      }
      local_5598 = (int **)((int)local_5598 + 1);
      local_5574 = local_5574 + 0x15;
    } while ((int)local_5598 < *(int *)(*(int *)((int)this + 8) + 0x2400));
  }
  local_556c = **(int **)(*(int *)((int)this + 8) + 0x2454);
  local_5570 = *(int *)((int)this + 8) + 0x2450;
  while( true ) {
    iVar19 = local_556c;
    local_551c = *(int *)(*(int *)((int)this + 8) + 0x2454);
    if ((local_5570 == 0) || (local_5570 != *(int *)((int)this + 8) + 0x2450)) {
      FUN_0047a948();
    }
    fVar4 = _g_NearEndGameFactor;
    if (iVar19 == local_551c) break;
    if (local_5570 == 0) {
      FUN_0047a948();
    }
    if ((iVar19 == *(int *)(local_5570 + 4)) && (FUN_0047a948(), iVar19 == *(int *)(local_5570 + 4))
       ) {
      FUN_0047a948();
    }
    local_5598 = AdjacencyList_FilterByUnitType
                           ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar19 + 0x10) * 0x24),
                            (ushort *)(iVar19 + 0x14));
    local_5588 = (int *)*local_5598[1];
    local_5594 = (int **)0xffffffff;
    local_558c = local_5598;
    while( true ) {
      piVar11 = local_5588;
      local_550c = local_5598[1];
      if ((local_558c == (int **)0x0) || (local_558c != local_5598)) {
        FUN_0047a948();
      }
      if (piVar11 == local_550c) break;
      if (local_558c == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar11 == local_558c[1]) {
        FUN_0047a948();
      }
      if ((int **)piVar11[3] != local_5594) {
        if (piVar11 == local_558c[1]) {
          FUN_0047a948();
        }
        if (iVar19 == *(int *)(local_5570 + 4)) {
          FUN_0047a948();
        }
        local_5408[*(int *)(iVar19 + 0x18) + piVar11[3] * 0x15] =
             (int *)((int)local_5408[*(int *)(iVar19 + 0x18) + piVar11[3] * 0x15] + 1);
        if (iVar19 == *(int *)(local_5570 + 4)) {
          FUN_0047a948();
        }
        if (piVar11 == local_558c[1]) {
          FUN_0047a948();
        }
        (&g_ThreatScore)[*(int *)(iVar19 + 0x18) * 0x100 + piVar11[3]] =
             (&g_ThreatScore)[*(int *)(iVar19 + 0x18) * 0x100 + piVar11[3]] + 1;
      }
      if (piVar11 == local_558c[1]) {
        FUN_0047a948();
      }
      local_5594 = (int **)piVar11[3];
      FUN_0040f400((int *)&local_558c);
    }
    if (iVar19 == *(int *)(local_5570 + 4)) {
      FUN_0047a948();
    }
    if (iVar19 == *(int *)(local_5570 + 4)) {
      FUN_0047a948();
    }
    local_5408[*(int *)(iVar19 + 0x10) * 0x15 + *(int *)(iVar19 + 0x18)] =
         (int *)((int)local_5408[*(int *)(iVar19 + 0x10) * 0x15 + *(int *)(iVar19 + 0x18)] + 1);
    if (iVar19 == *(int *)(local_5570 + 4)) {
      FUN_0047a948();
    }
    if (iVar19 == *(int *)(local_5570 + 4)) {
      FUN_0047a948();
    }
    (&g_ThreatScore)[*(int *)(iVar19 + 0x18) * 0x100 + *(int *)(iVar19 + 0x10)] =
         (&g_ThreatScore)[*(int *)(iVar19 + 0x18) * 0x100 + *(int *)(iVar19 + 0x10)] + 1;
    if (iVar19 == *(int *)(local_5570 + 4)) {
      FUN_0047a948();
    }
    if (iVar19 == *(int *)(local_5570 + 4)) {
      FUN_0047a948();
    }
    (&g_ProximityScore)[*(int *)(iVar19 + 0x18) * 0x100 + *(int *)(iVar19 + 0x10)] = 0;
    UnitList_Advance(&local_5570);
  }
  iVar19 = *(int *)((int)this + 8);
  iVar16 = *(int *)(iVar19 + 0x2404);
  local_559c = (int **)0x0;
  if (0 < iVar16) {
    local_5580 = (int *)0x0;
    local_5594 = (int **)0x0;
    do {
      local_5598 = (int **)0x0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        local_554c = (void *)0x0;
        do {
          local_557c = (int **)0x0;
          if (0 < iVar16) {
            local_5528 = (int **)(&g_AllyDesignation_A)[(int)local_5598 * 2];
            local_5524 = (int *)(&DAT_004d2e14)[(int)local_5598 * 2];
            local_5534 = (int *)(&DAT_004d2614)[(int)local_5598 * 2];
            local_5538 = (int **)(&DAT_004d2610)[(int)local_5598 * 2];
            local_5554 = (int *)(&DAT_004d3614)[(int)local_5598 * 2];
            local_5544 = (int *)((int)local_559c >> 0x1f);
            local_5558 = (int **)(&DAT_004d3610)[(int)local_5598 * 2];
            local_5548 = local_559c;
            do {
              iVar19 = 0;
              local_555c = (int *)0x0;
              local_5575 = '\0';
              if (-1 < (int)local_5554) {
                iVar19 = (&g_AllyTrustScore)[((int)local_5558 + (int)local_5594) * 2];
                local_555c = (int *)(&g_AllyTrustScore_Hi)[((int)local_5558 + (int)local_5594) * 2];
              }
              if (-1 < (int)local_5534) {
                iVar19 = (&g_AllyTrustScore)[((int)local_5594 + (int)local_5538) * 2];
                local_555c = (int *)(&g_AllyTrustScore_Hi)[((int)local_5594 + (int)local_5538) * 2];
              }
              if (-1 < (int)local_5524) {
                iVar19 = (&g_AllyTrustScore)[((int)local_5594 + (int)local_5528) * 2];
                local_555c = (int *)(&g_AllyTrustScore_Hi)[((int)local_5594 + (int)local_5528) * 2];
              }
              if ((((local_5538 == local_559c) && (local_5534 == local_5544)) ||
                  ((local_5528 == local_559c && (local_5524 == local_5544)))) ||
                 ((local_5558 == local_559c && (local_5554 == local_5544)))) {
                local_5575 = '\x01';
              }
              if (((DAT_00baed68 == '\x01') && (fVar4 < 2.0)) && (-1 < (int)local_5534)) {
                if ((-1 < (int)(&g_AllyTrustScore_Hi)[((int)local_5594 + (int)local_5538) * 2]) &&
                   ((0 < (int)(&g_AllyTrustScore_Hi)[((int)local_5594 + (int)local_5538) * 2] ||
                    (1 < (uint)(&g_AllyTrustScore)[((int)local_5594 + (int)local_5538) * 2])))) {
                  iVar16 = (int)local_5538 * 0x15 + (int)local_559c;
                  if ((0 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2]) ||
                     ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2] &&
                      (1 < (uint)(&g_AllyTrustScore)[iVar16 * 2])))) goto LAB_00447b0d;
                }
                iVar19 = 0;
                local_555c = (int *)0x0;
              }
LAB_00447b0d:
              if (local_557c == local_559c) {
                if (iVar19 == 0 && local_555c == (int *)0x0) {
                  piVar11 = local_5408[(int)local_554c + (int)local_557c];
                  iVar6 = (int)piVar11 >> 0x1f;
                  iVar19 = (int)local_5580 + (int)local_5598;
                  iVar16 = iVar19 * 8;
                  (&DAT_0058f8e8)[iVar19 * 2] = piVar11;
                  (&DAT_0058f8ec)[iVar19 * 2] = iVar6;
                  goto LAB_00447c0c;
                }
              }
              else {
                piVar11 = local_5408[(int)local_554c + (int)local_557c];
                iVar6 = (int)piVar11 >> 0x1f;
                iVar19 = (int)local_5580 + (int)local_5598;
                iVar16 = iVar19 * 8;
                if (((int)(&DAT_005460ec)[iVar19 * 2] <= iVar6) &&
                   (((int)(&DAT_005460ec)[iVar19 * 2] < iVar6 ||
                    ((int *)(&DAT_005460e8)[iVar19 * 2] < piVar11)))) {
                  iVar7 = (int)local_5594 + (int)local_557c;
                  local_5520 = (&g_AllyTrustScore)[iVar7 * 2];
                  iVar8 = (&g_AllyTrustScore_Hi)[iVar7 * 2];
                  if (((local_5520 == 0 && iVar8 == 0) || ((int)(&DAT_00634e90)[iVar7] < 10)) ||
                     ((-1 < iVar8 && (((0 < iVar8 || (1 < local_5520)) && (local_5575 == '\0'))))))
                  {
                    (&DAT_005460e8)[iVar19 * 2] = piVar11;
                    (&DAT_005460ec)[iVar19 * 2] = iVar6;
                    goto LAB_00447c0c;
                  }
                }
                if ((-1 < (int)(&g_AllyTrustScore_Hi)[((int)local_5594 + (int)local_557c) * 2]) &&
                   ((0 < (int)(&g_AllyTrustScore_Hi)[((int)local_5594 + (int)local_557c) * 2] ||
                    (3 < (uint)(&g_AllyTrustScore)[((int)local_5594 + (int)local_557c) * 2])))) {
                  puVar1 = &DAT_005658e8 + iVar19 * 2;
                  uVar14 = *puVar1;
                  *puVar1 = *puVar1 + (int)piVar11;
                  (&DAT_005658ec)[iVar19 * 2] =
                       (&DAT_005658ec)[iVar19 * 2] + iVar6 + (uint)CARRY4(uVar14,(uint)piVar11);
                }
LAB_00447c0c:
                if (local_557c != local_559c) {
                  iVar8 = (int)local_5594 + (int)local_557c;
                  local_5520 = (&g_AllyTrustScore)[iVar8 * 2];
                  iVar19 = (&g_AllyTrustScore_Hi)[iVar8 * 2];
                  if (((local_5520 == 0 && iVar19 == 0) || ((int)(&DAT_00634e90)[iVar8] < 10)) ||
                     ((-1 < iVar19 && (((0 < iVar19 || (1 < local_5520)) && (local_5575 == '\0')))))
                     ) {
                    puVar1 = (uint *)((int)&g_EnemyReachScore + iVar16);
                    uVar14 = *puVar1;
                    *puVar1 = *puVar1 + (int)piVar11;
                    *(int *)((int)&DAT_00535cec + iVar16) =
                         *(int *)((int)&DAT_00535cec + iVar16) + iVar6 +
                         (uint)CARRY4(uVar14,(uint)piVar11);
                  }
                  puVar1 = (uint *)((int)&DAT_0052b4e8 + iVar16);
                  uVar14 = *puVar1;
                  *puVar1 = *puVar1 + (int)piVar11;
                  *(int *)((int)&DAT_0052b4ec + iVar16) =
                       *(int *)((int)&DAT_0052b4ec + iVar16) + iVar6 +
                       (uint)CARRY4(uVar14,(uint)piVar11);
                }
              }
              iVar16 = *(int *)(*(int *)((int)this + 8) + 0x2404);
              local_557c = (int **)((int)local_557c + 1);
            } while ((int)local_557c < iVar16);
          }
          local_554c = (void *)((int)local_554c + 0x15);
          local_5598 = (int **)((int)local_5598 + 1);
        } while ((int)local_5598 < *(int *)(*(int *)((int)this + 8) + 0x2400));
      }
      iVar19 = *(int *)((int)this + 8);
      iVar16 = *(int *)(iVar19 + 0x2404);
      local_5594 = (int **)((int)local_5594 + 0x15);
      local_5580 = local_5580 + 0x40;
      local_559c = (int **)((int)local_559c + 1);
    } while ((int)local_559c < iVar16);
  }
  iVar19 = *(int *)((int)this + 8);
  local_559c = (int **)0x0;
  if (0 < *(int *)(iVar19 + 0x2404)) {
    do {
      iVar16 = 0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        local_5590 = (int *)0x0;
        do {
          pvVar20 = (void *)(iVar19 + 0x14 + (int)local_5590);
          local_54dc = *(int *)((int)pvVar20 + 4);
          puVar9 = (undefined4 *)GameBoard_GetPowerRec(pvVar20,local_5450,(int *)&local_559c);
          if (((void *)*puVar9 == (void *)0x0) || ((void *)*puVar9 != pvVar20)) {
            FUN_0047a948();
          }
          if (puVar9[1] != local_54dc) {
            iVar19 = (int)local_559c * 0x100 + iVar16;
            if (DAT_00baed69 == '\x01') {
              (&g_AttackCount)[iVar19 * 2] = 1;
            }
            else {
              (&g_AttackCount)[iVar19 * 2] = 5;
            }
            (&DAT_006040ec)[iVar19 * 2] = 0;
          }
          iVar19 = *(int *)((int)this + 8);
          local_5590 = local_5590 + 9;
          iVar16 = iVar16 + 1;
        } while (iVar16 < *(int *)(iVar19 + 0x2400));
      }
      iVar19 = *(int *)((int)this + 8);
      local_5581 = '\0';
      local_5598 = (int **)0x0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        local_5590 = (int *)0x0;
        do {
          local_5574 = (int **)(iVar19 + 8 + (int)local_5590);
          local_5544 = (int *)*local_5574[1];
          local_5548 = local_5574;
          local_5530 = local_5598;
          while( true ) {
            piVar18 = local_5544;
            ppiVar17 = local_5548;
            piVar11 = local_5574[1];
            if ((local_5548 == (int **)0x0) || (local_5548 != local_5574)) {
              FUN_0047a948();
            }
            if (piVar18 == piVar11) break;
            if (ppiVar17 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar18 == ppiVar17[1]) {
              FUN_0047a948();
            }
            ppiVar17 = local_559c;
            local_552c = (short)piVar18[3];
            lVar22 = __allmul((&g_AttackCount)[(int)(local_5598 + (int)local_559c * 0x40) * 2],
                              (&DAT_006040ec)[(int)(local_5598 + (int)local_559c * 0x40) * 2],
                              param_3,param_4);
            ppiVar10 = OrderedSet_FindOrInsert
                                 ((void *)((int)this + (int)ppiVar17 * 0x78 + 0x361c),
                                  (int **)&local_5530);
            *(longlong *)ppiVar10 = lVar22;
            pvVar20 = (void *)((int)this + (int)ppiVar17 * 0x78 + 0x3628);
            iVar19 = 9;
            do {
              ppiVar17 = OrderedSet_FindOrInsert(pvVar20,(int **)&local_5530);
              pvVar20 = (void *)((int)pvVar20 + 0xc);
              iVar19 = iVar19 + -1;
              *ppiVar17 = (int *)0x0;
              ppiVar17[1] = (int *)0x0;
            } while (iVar19 != 0);
            FUN_00401590((int *)&local_5548);
          }
          iVar19 = *(int *)((int)this + 8);
          local_5590 = local_5590 + 9;
          local_5598 = (int **)((int)local_5598 + 1);
        } while ((int)local_5598 < *(int *)(iVar19 + 0x2400));
      }
      local_554c = (void *)((int)this + (int)local_559c * 0x78);
      local_5594 = (int **)((int)local_554c + 0x3628);
      local_5574 = (int **)0x9;
      local_553c = local_5594;
      do {
        local_5564 = (int *)*local_5594[1];
        local_5568 = local_5594;
        while( true ) {
          piVar11 = local_5564;
          ppiVar10 = local_5568;
          ppiVar17 = local_5594;
          local_54ec = local_5594[1];
          if ((local_5568 == (int **)0x0) || (local_5568 != local_5594)) {
            FUN_0047a948();
          }
          if (piVar11 == local_54ec) break;
          if (ppiVar10 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar11 == ppiVar10[1]) {
            FUN_0047a948();
          }
          if (piVar11 == ppiVar10[1]) {
            FUN_0047a948();
          }
          local_5598 = AdjacencyList_FilterByUnitType
                                 ((void *)(*(int *)((int)this + 8) + 8 + (int)piVar11[4] * 0x24),
                                  (ushort *)(piVar11 + 5));
          local_5588 = (int *)*local_5598[1];
          local_5580 = (int *)0xffffffff;
          local_558c = local_5598;
          while( true ) {
            ppiVar17 = local_558c;
            local_5494 = local_5598[1];
            if ((local_558c == (int **)0x0) || (local_558c != local_5598)) {
              FUN_0047a948();
            }
            if (local_5588 == local_5494) break;
            if (ppiVar17 == (int **)0x0) {
              FUN_0047a948();
            }
            if (local_5588 == ppiVar17[1]) {
              FUN_0047a948();
            }
            ppiVar17 = (int **)(local_5588 + 3);
            if ((int *)local_5588[3] == local_5580) {
              if (local_5588 == local_558c[1]) {
                FUN_0047a948();
              }
              ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,ppiVar17);
              if (((int)local_555c <= (int)ppiVar10[1]) &&
                 (((int)local_555c < (int)ppiVar10[1] || (local_5560 < *ppiVar10)))) {
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                piVar18 = (int *)piVar11[6];
                piVar11[6] = (int)piVar18 - (int)local_5560;
                piVar11[7] = (piVar11[7] - (int)local_555c) - (uint)(piVar18 < local_5560);
                if (local_5588 == local_558c[1]) {
                  FUN_0047a948();
                }
                ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,ppiVar17);
                local_5560 = *ppiVar10;
                local_555c = ppiVar10[1];
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                uVar14 = piVar11[6];
                piVar11[6] = uVar14 + (int)local_5560;
                piVar11[7] = (int)local_555c + (uint)CARRY4(uVar14,(uint)local_5560) + piVar11[7];
              }
            }
            else {
              if (local_5588 == local_558c[1]) {
                FUN_0047a948();
              }
              ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,ppiVar17);
              local_5560 = *ppiVar10;
              local_555c = ppiVar10[1];
              if (piVar11 == local_5568[1]) {
                FUN_0047a948();
              }
              if (piVar11 == local_5568[1]) {
                FUN_0047a948();
              }
              uVar14 = piVar11[6];
              piVar11[6] = uVar14 + (int)local_5560;
              piVar11[7] = (int)local_555c + (uint)CARRY4(uVar14,(uint)local_5560) + piVar11[7];
            }
            if (local_5588 == local_558c[1]) {
              FUN_0047a948();
            }
            local_5580 = *ppiVar17;
            FUN_0040f400((int *)&local_558c);
          }
          if (piVar11 == local_5568[1]) {
            FUN_0047a948();
          }
          if (piVar11 == local_5568[1]) {
            FUN_0047a948();
          }
          if (piVar11 == local_5568[1]) {
            FUN_0047a948();
          }
          ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,(int **)(piVar11 + 4));
          ppiVar17 = local_5568;
          uVar14 = piVar11[6];
          piVar18 = *ppiVar10;
          piVar3 = ppiVar10[1];
          piVar11[6] = uVar14 + (int)*ppiVar10;
          piVar11[7] = (int)piVar3 + (uint)CARRY4(uVar14,(uint)piVar18) + piVar11[7];
          if ((piVar11 == local_5568[1]) && (FUN_0047a948(), piVar11 == ppiVar17[1])) {
            FUN_0047a948();
          }
          uVar23 = __alldiv(piVar11[6],piVar11[7],5,0);
          *(undefined8 *)(piVar11 + 6) = uVar23;
          std_Tree_IteratorIncrement((int *)&local_5568);
        }
        local_5594 = ppiVar17 + 3;
        local_5574 = (int **)((int)local_5574 + -1);
      } while (local_5574 != (int **)0x0);
      iVar19 = 0;
      if (0 < *(int *)(*(int *)((int)this + 8) + 0x2400)) {
        iVar16 = (int)local_559c << 0xb;
        do {
          *(undefined4 *)(&DAT_006190e8 + iVar16) = 0;
          *(undefined4 *)((int)&g_AttackCount + iVar16) = 0;
          *(undefined4 *)(&DAT_006190ec + iVar16) = 0;
          *(undefined4 *)((int)&DAT_006040ec + iVar16) = 0;
          iVar19 = iVar19 + 1;
          iVar16 = iVar16 + 8;
        } while (iVar19 < *(int *)(*(int *)((int)this + 8) + 0x2400));
      }
      local_556c = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_5570 = *(int *)((int)this + 8) + 0x2450;
      local_5574 = (int **)0x0;
      while( true ) {
        iVar6 = local_556c;
        iVar16 = local_5570;
        iVar19 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_5570 == 0) || (local_5570 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar6 == iVar19) break;
        if (iVar16 == 0) {
          FUN_0047a948();
        }
        if ((iVar6 == *(int *)(iVar16 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar16 + 4))) {
          FUN_0047a948();
        }
        local_5598 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)((int)this + 8) + 8 +
                                        *(int *)(local_556c + 0x10) * 0x24),
                                (ushort *)(local_556c + 0x14));
        local_5588 = (int *)*local_5598[1];
        local_5580 = (int *)0x0;
        local_558c = local_5598;
        while( true ) {
          piVar11 = local_5588;
          ppiVar10 = local_558c;
          ppiVar17 = local_5598;
          local_54cc = local_5598[1];
          if ((local_558c == (int **)0x0) || (local_558c != local_5598)) {
            FUN_0047a948();
          }
          if (piVar11 == local_54cc) break;
          if (ppiVar10 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar11 == ppiVar10[1]) {
            FUN_0047a948();
          }
          iVar19 = (int)local_559c * 0x100 + piVar11[3];
          if ((-1 < (int)(&DAT_0058f8ec)[iVar19 * 2]) &&
             ((0 < (int)(&DAT_0058f8ec)[iVar19 * 2] || ((&DAT_0058f8e8)[iVar19 * 2] != 0)))) {
            if (local_556c == *(int *)(local_5570 + 4)) {
              FUN_0047a948();
            }
            if (*(int ***)(local_556c + 0x18) != local_559c) {
              local_5575 = '\0';
              if (piVar11 == ppiVar10[1]) {
                FUN_0047a948();
              }
              local_5534 = (int *)(&DAT_004d2614)[piVar11[3] * 2];
              ppiVar17 = (int **)(&DAT_004d2610)[piVar11[3] * 2];
              if (piVar11 == ppiVar10[1]) {
                FUN_0047a948();
              }
              local_5528 = (int **)(&g_AllyDesignation_A)[piVar11[3] * 2];
              local_5524 = (int *)(&DAT_004d2e14)[piVar11[3] * 2];
              if (piVar11 == ppiVar10[1]) {
                FUN_0047a948();
              }
              piVar18 = (int *)((int)local_559c >> 0x1f);
              if ((((ppiVar17 == local_559c) && (local_5534 == piVar18)) ||
                  ((local_5528 == local_559c && (local_5524 == piVar18)))) ||
                 ((cVar15 = local_5575, (int **)(&DAT_004d3610)[piVar11[3] * 2] == local_559c &&
                  ((int *)(&DAT_004d3614)[piVar11[3] * 2] == piVar18)))) {
                cVar15 = '\x01';
              }
              if (local_556c == *(int *)(local_5570 + 4)) {
                FUN_0047a948();
              }
              iVar16 = (int)local_559c * 0x15;
              iVar19 = *(int *)(local_556c + 0x18) + iVar16;
              if (((&g_AllyTrustScore)[iVar19 * 2] != 0 || (&g_AllyTrustScore_Hi)[iVar19 * 2] != 0)
                 && (9 < (int)(&DAT_00634e90)[iVar16 + (int)local_557c])) {
                if (local_556c == *(int *)(local_5570 + 4)) {
                  FUN_0047a948();
                }
                iVar16 = *(int *)(local_556c + 0x18) + iVar16;
                if (((int)(&g_AllyTrustScore_Hi)[iVar16 * 2] < 0) ||
                   ((((int)(&g_AllyTrustScore_Hi)[iVar16 * 2] < 1 &&
                     ((uint)(&g_AllyTrustScore)[iVar16 * 2] < 2)) || (cVar15 != '\0'))))
                goto LAB_00448474;
              }
              local_5580 = (int *)((int)local_5580 + 1);
            }
          }
LAB_00448474:
          FUN_0040f400((int *)&local_558c);
        }
        if (0 < (int)local_5580) {
          local_5588 = (int *)*ppiVar17[1];
          local_558c = ppiVar17;
          while( true ) {
            piVar11 = local_5588;
            ppiVar10 = local_558c;
            local_5484 = ppiVar17[1];
            if ((local_558c == (int **)0x0) || (local_558c != ppiVar17)) {
              FUN_0047a948();
            }
            if (piVar11 == local_5484) break;
            if (ppiVar10 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar11 == ppiVar10[1]) {
              FUN_0047a948();
            }
            (&DAT_00540ce8)[(int)local_559c * 0x100 + piVar11[3]] =
                 1.0 / (float)(int)local_5580 +
                 (float)(&DAT_00540ce8)[(int)local_559c * 0x100 + piVar11[3]];
            FUN_0040f400((int *)&local_558c);
          }
        }
        UnitList_Advance(&local_5570);
      }
      local_556c = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_5570 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar6 = local_556c;
        iVar16 = local_5570;
        iVar19 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_5570 == 0) || (local_5570 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar6 == iVar19) break;
        if (iVar16 == 0) {
          FUN_0047a948();
        }
        if (iVar6 == *(int *)(iVar16 + 4)) {
          FUN_0047a948();
        }
        if (*(int ***)(iVar6 + 0x18) == local_559c) {
          if (iVar6 == *(int *)(iVar16 + 4)) {
            FUN_0047a948();
          }
          iVar19 = (int)local_559c * 0x100 + *(int *)(iVar6 + 0x10);
          *(undefined4 *)(&g_SCOwnership + iVar19 * 8) = 1;
          *(undefined4 *)(&DAT_00520cec + iVar19 * 8) = 0;
          UnitList_Advance(&local_5570);
        }
        else {
          if (iVar6 == *(int *)(iVar16 + 4)) {
            FUN_0047a948();
          }
          local_5574 = (int **)((int)local_559c * 0x15);
          iVar19 = *(int *)(iVar6 + 0x18) + (int)local_5574;
          if (((int)(&g_AllyTrustScore_Hi)[iVar19 * 2] < 0) ||
             (((int)(&g_AllyTrustScore_Hi)[iVar19 * 2] < 1 && ((&g_AllyTrustScore)[iVar19 * 2] == 0)
              ))) {
            if (iVar6 == *(int *)(iVar16 + 4)) {
              FUN_0047a948();
            }
            iVar19 = (int)local_559c * 0x100 + *(int *)(iVar6 + 0x10);
            *(undefined4 *)(&DAT_004f6ce8 + iVar19 * 8) = 1;
            *(undefined4 *)(&DAT_004f6cec + iVar19 * 8) = 0;
LAB_004486a4:
            UnitList_Advance(&local_5570);
          }
          else {
            if (iVar6 == *(int *)(iVar16 + 4)) {
              FUN_0047a948();
            }
            iVar8 = (int)local_559c * 0x100;
            iVar19 = *(int *)(iVar6 + 0x10) + iVar8;
            *(undefined4 *)(&DAT_005164e8 + iVar19 * 8) = 1;
            *(undefined4 *)(&DAT_005164ec + iVar19 * 8) = 0;
            if (iVar6 == *(int *)(iVar16 + 4)) {
              FUN_0047a948();
            }
            if (9 < (int)(&DAT_00634e90)[*(int *)(iVar6 + 0x18) + (int)local_5574])
            goto LAB_004486a4;
            if (iVar6 == *(int *)(iVar16 + 4)) {
              FUN_0047a948();
            }
            iVar8 = *(int *)(iVar6 + 0x10) + iVar8;
            *(undefined4 *)(&DAT_0050bce8 + iVar8 * 8) = 1;
            *(undefined4 *)(&DAT_0050bcec + iVar8 * 8) = 0;
            UnitList_Advance(&local_5570);
          }
        }
      }
      local_556c = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_5570 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar6 = local_556c;
        iVar16 = local_5570;
        iVar19 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_5570 == 0) || (local_5570 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar6 == iVar19) break;
        if (iVar16 == 0) {
          FUN_0047a948();
        }
        if ((iVar6 == *(int *)(iVar16 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar16 + 4))) {
          FUN_0047a948();
        }
        local_5598 = AdjacencyList_FilterByUnitType
                               ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar6 + 0x10) * 0x24
                                        ),(ushort *)(iVar6 + 0x14));
        local_5588 = (int *)*local_5598[1];
        local_5594 = (int **)0xffffffff;
        local_558c = local_5598;
        while( true ) {
          piVar18 = local_5588;
          ppiVar17 = local_558c;
          piVar11 = local_5598[1];
          if ((local_558c == (int **)0x0) || (local_558c != local_5598)) {
            FUN_0047a948();
          }
          if (piVar18 == piVar11) break;
          if (ppiVar17 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar18 == ppiVar17[1]) {
            FUN_0047a948();
          }
          piVar11 = local_5588;
          if ((int **)piVar18[3] != local_5594) {
            if (local_5588 == local_558c[1]) {
              FUN_0047a948();
            }
            piVar18 = local_5588;
            ppiVar17 = local_558c;
            if (((int)(&DAT_004d2e14)[piVar11[3] * 2] < 1) &&
               ((int)(&DAT_004d2e14)[piVar11[3] * 2] < 0)) {
              if ((local_5588 == local_558c[1]) && (FUN_0047a948(), piVar18 == ppiVar17[1])) {
                FUN_0047a948();
              }
              local_5574 = AdjacencyList_FilterByUnitType
                                     ((void *)(*(int *)((int)this + 8) + 8 + local_5588[3] * 0x24),
                                      (ushort *)(local_5588 + 4));
              local_5500 = (int *)*local_5574[1];
              local_5504 = local_5574;
              while( true ) {
                piVar18 = local_5500;
                ppiVar17 = local_5504;
                piVar11 = local_5574[1];
                if ((local_5504 == (int **)0x0) || (local_5504 != local_5574)) {
                  FUN_0047a948();
                }
                if (piVar18 == piVar11) break;
                if (local_556c == *(int *)(local_5570 + 4)) {
                  FUN_0047a948();
                }
                iVar16 = (int)local_559c * 0x100;
                iVar19 = *(int *)(local_556c + 0x10) + iVar16;
                if ((*(int *)(&DAT_004f6ce8 + iVar19 * 8) == 1) &&
                   (*(int *)(&DAT_004f6cec + iVar19 * 8) == 0)) {
                  if (ppiVar17 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (piVar18 == ppiVar17[1]) {
                    FUN_0047a948();
                  }
                  if (*(int *)(&g_SCOwnership + (piVar18[3] + iVar16) * 8) == 0 &&
                      *(int *)(&DAT_00520cec + (piVar18[3] + iVar16) * 8) == 0) {
                    if (piVar18 == ppiVar17[1]) {
                      FUN_0047a948();
                    }
                    iVar19 = piVar18[3];
                    puVar1 = &DAT_005850e8 + (iVar19 + iVar16) * 2;
                    uVar14 = *puVar1;
                    *puVar1 = *puVar1 + 1;
                    (&DAT_005850ec)[(iVar19 + iVar16) * 2] =
                         (&DAT_005850ec)[(iVar19 + iVar16) * 2] + (uint)(0xfffffffe < uVar14);
                  }
                }
                if (local_556c == *(int *)(local_5570 + 4)) {
                  FUN_0047a948();
                }
                if (*(int ***)(local_556c + 0x18) != local_559c) {
                  if (ppiVar17 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (piVar18 == ppiVar17[1]) {
                    FUN_0047a948();
                  }
                  iVar19 = piVar18[3];
                  puVar1 = &DAT_0057a8e8 + (iVar19 + iVar16) * 2;
                  uVar14 = *puVar1;
                  *puVar1 = *puVar1 + 1;
                  (&DAT_0057a8ec)[(iVar19 + iVar16) * 2] =
                       (&DAT_0057a8ec)[(iVar19 + iVar16) * 2] + (uint)(0xfffffffe < uVar14);
                }
                FUN_0040f400((int *)&local_5504);
              }
            }
          }
          piVar11 = local_5588;
          if (local_5588 == local_558c[1]) {
            FUN_0047a948();
          }
          local_5594 = (int **)piVar11[3];
          FUN_0040f400((int *)&local_558c);
        }
        UnitList_Advance(&local_5570);
      }
      if ((local_559c == local_5514) && (WIN == *(short *)(*(int *)((int)this + 8) + 0x244a))) {
        ComputeWinterBuilds((int)this);
      }
      iVar19 = *(int *)((int)this + 8);
      local_5598 = (int **)0x0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        iVar16 = 0;
        do {
          if (*(char *)(iVar19 + 3 + iVar16) != '\0') {
            local_54bc = *(int *)(iVar19 + 0x18 + iVar16);
            pvVar20 = (void *)(iVar19 + 0x14 + iVar16);
            puVar9 = (undefined4 *)GameBoard_GetPowerRec(pvVar20,local_5440,(int *)&local_559c);
            if (((void *)*puVar9 == (void *)0x0) || ((void *)*puVar9 != pvVar20)) {
              FUN_0047a948();
            }
            if (puVar9[1] != local_54bc) {
              uVar2 = *(ushort *)(iVar16 + 0x20 + *(int *)((int)this + 8));
              ppiVar17 = (int **)(uVar2 & 0xff);
              if ((char)(uVar2 >> 8) != 'A') {
                ppiVar17 = (int **)0x14;
              }
              if (ppiVar17 != local_559c) {
                local_5581 = '\x01';
              }
            }
          }
          iVar19 = *(int *)((int)this + 8);
          local_5598 = (int **)((int)local_5598 + 1);
          iVar16 = iVar16 + 0x24;
        } while ((int)local_5598 < *(int *)(iVar19 + 0x2400));
      }
      iVar19 = *(int *)((int)this + 8);
      local_5598 = (int **)0x0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        do {
          piVar11 = (int *)((int)local_5598 * 0x24);
          local_5580 = piVar11;
          if (*(char *)(iVar19 + 3 + (int)piVar11) != '\0') {
            uVar2 = *(ushort *)(iVar19 + 0x20 + (int)piVar11);
            local_5594 = (int **)(uVar2 & 0xff);
            if ((char)(uVar2 >> 8) != 'A') {
              local_5594 = (int **)0x14;
            }
            if (local_5594 == local_559c) {
              if ((((uint)(&g_AllyDesignation_A)[(int)local_5598 * 2] &
                   (&DAT_004d2e14)[(int)local_5598 * 2]) == 0xffffffff) ||
                 (((int **)(&g_AllyDesignation_A)[(int)local_5598 * 2] == local_559c &&
                  ((&DAT_004d2e14)[(int)local_5598 * 2] == (int)local_559c >> 0x1f)))) {
LAB_00448b2b:
                ppiVar17 = local_5598 + (int)local_559c * 0x40;
                lVar22 = EvaluateProvinceScore(this,(int)local_5598,(int)local_559c);
                *(longlong *)(&g_AttackCount + (int)ppiVar17 * 2) = lVar22;
                local_5474 = *(int *)((int)piVar11 + *(int *)((int)this + 8) + 0x18);
                pvVar20 = (void *)((int)piVar11 + *(int *)((int)this + 8) + 0x14);
                puVar9 = (undefined4 *)GameBoard_GetPowerRec(pvVar20,local_5420,(int *)&local_559c);
                if (((void *)*puVar9 == (void *)0x0) || ((void *)*puVar9 != pvVar20)) {
                  FUN_0047a948();
                }
                if (puVar9[1] == local_5474) {
                  if ((-1 < (int)(&DAT_006040ec)[(int)ppiVar17 * 2]) &&
                     (((0 < (int)(&DAT_006040ec)[(int)ppiVar17 * 2] ||
                       ((&g_AttackCount)[(int)ppiVar17 * 2] != 0)) && (local_5581 == '\x01')))) {
                    (&g_AttackCount)[(int)ppiVar17 * 2] = 0x50;
                    goto LAB_00448be8;
                  }
                }
                else if (((-1 < (int)(&DAT_006040ec)[(int)ppiVar17 * 2]) &&
                         ((0 < (int)(&DAT_006040ec)[(int)ppiVar17 * 2] ||
                          (0xf < (uint)(&g_AttackCount)[(int)ppiVar17 * 2])))) &&
                        (local_5581 != '\0')) {
                  (&g_AttackCount)[(int)ppiVar17 * 2] = 0x96;
LAB_00448be8:
                  (&DAT_006040ec)[(int)ppiVar17 * 2] = 0;
                }
                if (local_5594 != local_559c) {
                  iVar19 = (int)local_559c * 0x15 + (int)local_5594;
                  if (((-1 < (int)(&g_AllyTrustScore_Hi)[iVar19 * 2]) &&
                      ((0 < (int)(&g_AllyTrustScore_Hi)[iVar19 * 2] ||
                       (4 < (uint)(&g_AllyTrustScore)[iVar19 * 2])))) &&
                     (((int **)(&DAT_004d2610)[(int)local_5598 * 2] == local_5594 &&
                      ((&DAT_004d2614)[(int)local_5598 * 2] == (int)local_5594 >> 0x1f)))) {
                    if (((int)(&DAT_005460ec)[(int)(local_5598 + (int)local_5594 * 0x40) * 2] < 0)
                       || (((int)(&DAT_005460ec)[(int)(local_5598 + (int)local_5594 * 0x40) * 2] < 1
                           && ((&DAT_005460e8)[(int)(local_5598 + (int)local_5594 * 0x40) * 2] == 0)
                           ))) {
                      (&g_AttackCount)[(int)ppiVar17 * 2] = 0;
                      (&DAT_006040ec)[(int)ppiVar17 * 2] = 0;
                    }
                    else {
                      uVar23 = __alldiv((&g_AttackCount)[(int)ppiVar17 * 2],
                                        (&DAT_006040ec)[(int)ppiVar17 * 2],3,0);
                      *(undefined8 *)(&g_AttackCount + (int)ppiVar17 * 2) = uVar23;
                    }
                  }
                }
                if (((0.95 < *(double *)(&DAT_00b76a28 + (int)ppiVar17 * 8)) &&
                    ((&g_AttackCount)[(int)ppiVar17 * 2] == 0 &&
                     (&DAT_006040ec)[(int)ppiVar17 * 2] == 0)) && (_g_NearEndGameFactor < 3.0)) {
                  (&g_AttackCount)[(int)ppiVar17 * 2] = 10;
                  (&DAT_006040ec)[(int)ppiVar17 * 2] = 0;
                }
                goto LAB_00449139;
              }
            }
            else {
              iVar16 = (int)local_559c * 0x15 + (int)local_5594;
              iVar19 = (&g_AllyTrustScore_Hi)[iVar16 * 2];
              if ((-1 < iVar19) &&
                 ((((((0 < iVar19 || (4 < (uint)(&g_AllyTrustScore)[iVar16 * 2])) && (-1 < iVar19))
                    && ((0 < iVar19 || ((&g_AllyTrustScore)[iVar16 * 2] != 0)))) &&
                   ((int **)(&DAT_004d2610)[(int)local_5598 * 2] == local_5594)) &&
                  ((&DAT_004d2614)[(int)local_5598 * 2] == 0)))) goto LAB_00448b2b;
            }
            ppiVar17 = (int **)((int)(local_5598 + (int)local_559c * 0x40) * 8);
            ppiVar17[0x18643a] = (int *)0x2;
            ppiVar17[0x18643b] = (int *)0x0;
            local_5590 = *(int **)((int)this + 8);
            uVar2 = *(ushort *)(local_5590 + 8 + (int)local_5598 * 9);
            cVar15 = (char)(uVar2 >> 8);
            ppiVar10 = (int **)(uVar2 & 0xff);
            if (cVar15 != 'A') {
              ppiVar10 = (int **)0x14;
            }
            if ((((ppiVar10 != local_559c) ||
                 (ppiVar10 = (int **)(&g_AllyDesignation_A)[(int)local_5598 * 2],
                 ((uint)ppiVar10 & (&DAT_004d2e14)[(int)local_5598 * 2]) == 0xffffffff)) ||
                ((ppiVar10 == local_559c &&
                 ((&DAT_004d2e14)[(int)local_5598 * 2] == (int)local_559c >> 0x1f)))) &&
               (ppiVar10 = (int **)(uint)(byte)uVar2, cVar15 != 'A')) {
              ppiVar10 = (int **)0x14;
            }
            local_5574 = ppiVar17;
            if (ppiVar10 == (int **)0x14) {
              if (((int **)(&g_OpeningTarget)[(int)local_559c] == local_5598) &&
                 (ppiVar17[0x163e3a] == (int *)0x0 && ppiVar17[0x163e3b] == (int *)0x0)) {
                ppiVar17[0x18643a] = (int *)0x96;
                ppiVar17[0x18643b] = (int *)0x0;
              }
              else {
                local_5594 = (int **)local_5590[0x901];
                ppiVar17 = (int **)0x0;
                bVar21 = false;
                local_557c = (int **)0x0;
                if ((int)local_5594 < 1) {
LAB_00448ef8:
                  piVar11 = (int *)0x4b;
                }
                else {
                  piVar11 = &DAT_00b85768 + (int)local_5598;
                  do {
                    if ((ppiVar17 != local_559c) && (0 < *piVar11)) {
                      bVar21 = true;
                    }
                    ppiVar17 = (int **)((int)ppiVar17 + 1);
                    piVar11 = piVar11 + 0x100;
                  } while ((int)ppiVar17 < (int)local_5594);
                  local_557c = ppiVar17;
                  if (!bVar21) goto LAB_00448ef8;
                  piVar11 = (int *)0x0;
                  local_557c = (int **)0x0;
                  local_5590 = &DAT_00b85768 + (int)local_5598;
                  do {
                    if ((local_557c != local_559c) && (0 < *local_5590)) {
                      iVar19 = (int)local_559c * 0x15 + (int)local_557c;
                      uVar14 = (&g_AllyTrustScore_Hi)[iVar19 * 2];
                      uVar13 = (&g_AllyTrustScore)[iVar19 * 2];
                      if (((int)uVar14 < 1) && (((int)uVar14 < 0 || (uVar13 < 2)))) {
                        piVar11 = (int *)0x4b;
                      }
                      else {
                        if ((int)(&DAT_00b85768)[(int)(local_5598 + (int)local_5514 * 0x40)] < 1) {
                          uVar23 = __alldiv(100,0,uVar13,uVar14);
                          local_5468 = (undefined4)uVar23;
                          uVar5 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),local_54b0);
                        }
                        else {
                          if (1 < (int)(&DAT_00b85710)[(int)local_557c]) {
                            piVar11 = (int *)0x4b;
                            goto LAB_00448ed9;
                          }
                          uVar23 = __alldiv(100,0,uVar13,uVar14);
                          uVar5 = uVar23;
                        }
                        local_54b0 = (undefined4)uVar5;
                        if (((int)piVar11 >> 0x1f <= (int)((ulonglong)uVar5 >> 0x20)) &&
                           (((int)piVar11 >> 0x1f < (int)((ulonglong)uVar23 >> 0x20) ||
                            (piVar11 < (int *)uVar23)))) {
                          uVar23 = __alldiv(0x4b,0,uVar13,uVar14);
                          piVar11 = (int *)uVar23;
                        }
                      }
                    }
LAB_00448ed9:
                    local_5590 = local_5590 + 0x100;
                    local_557c = (int **)((int)local_557c + 1);
                  } while ((int)local_557c < (int)local_5594);
                }
                local_5574[0x18643a] = piVar11;
                local_5574[0x18643b] = (int *)((int)piVar11 >> 0x1f);
                ppiVar17 = local_5574;
              }
            }
            else {
              iVar19 = (int)local_559c * 0x15 + (int)ppiVar10;
              local_5510 = (&g_AllyTrustScore)[iVar19 * 2];
              local_550c = (int *)(&g_AllyTrustScore_Hi)[iVar19 * 2];
              if (((int)local_550c < 0) || (((int)local_550c < 1 && (local_5510 < 2)))) {
                ppiVar17[0x18643a] = (int *)0xa;
              }
              else {
                ppiVar17[0x18643a] = (int *)0x1;
              }
              iVar19 = (&curr_sc_cnt)[(int)local_559c];
              ppiVar17[0x18643b] = (int *)0x0;
              if (2 < iVar19) {
                if ((((g_DeceitLevel < 2) && (local_559c == local_5514)) &&
                    (WIN == *(short *)(*(int *)((int)this + 8) + 0x244a))) &&
                   (g_OpeningStickyMode == '\x01')) {
                  iVar19 = (int)local_5514 * 0x15 + (int)ppiVar10;
                  if (((int)(&g_AllyTrustScore_Hi)[iVar19 * 2] < 1) &&
                     (((int)(&g_AllyTrustScore_Hi)[iVar19 * 2] < 0 ||
                      ((uint)(&g_AllyTrustScore)[iVar19 * 2] < 2)))) goto LAB_00448fe2;
                  ppiVar17[0x18643a] = (int *)0x5;
                  ppiVar17[0x18643b] = (int *)0x0;
                }
                else {
LAB_00448fe2:
                  uVar24 = PackScoreU64();
                  *(ulonglong *)(ppiVar17 + 0x18643a) = uVar24;
                }
                uVar2 = *(ushort *)((int)local_5580 + *(int *)((int)this + 8) + 0x20);
                cVar15 = (char)(uVar2 >> 8);
                uVar14 = uVar2 & 0xff;
                if (cVar15 != 'A') {
                  uVar14 = 0x14;
                }
                uVar13 = (uint)(byte)uVar2;
                if (cVar15 != 'A') {
                  uVar13 = 0x14;
                }
                if ((int)(&curr_sc_cnt)[uVar13] < 2) {
                  ppiVar10 = ppiVar17 + 0x18643a;
                  bVar21 = (int *)0xffffffaf < *ppiVar10;
                  *ppiVar10 = *ppiVar10 + 0x14;
                }
                else {
                  if (0xc < ((&curr_sc_cnt)[uVar14] * 100) / *(int *)((int)this + 0x3ffc))
                  goto LAB_00449077;
                  ppiVar10 = ppiVar17 + 0x18643a;
                  bVar21 = (int *)0xffffffeb < *ppiVar10;
                  *ppiVar10 = *ppiVar10 + 5;
                }
                ppiVar17[0x18643b] = (int *)((int)ppiVar17[0x18643b] + (uint)bVar21);
              }
LAB_00449077:
              if (((5.0 < _g_NearEndGameFactor) && (-1 < (int)local_550c)) &&
                 ((0 < (int)local_550c || (10 < local_5510)))) {
                ppiVar17[0x18643a] = (int *)0x0;
                ppiVar17[0x18643b] = (int *)0x0;
              }
            }
            local_549c = *(int *)((int)local_5580 + *(int *)((int)this + 8) + 0x18);
            pvVar20 = (void *)((int)local_5580 + *(int *)((int)this + 8) + 0x14);
            puVar9 = (undefined4 *)GameBoard_GetPowerRec(pvVar20,local_5430,(int *)&local_559c);
            if (((void *)*puVar9 == (void *)0x0) || ((void *)*puVar9 != pvVar20)) {
              FUN_0047a948();
            }
            if (puVar9[1] != local_549c) {
              uVar2 = *(ushort *)((int)local_5580 + *(int *)((int)this + 8) + 0x20);
              ppiVar10 = (int **)(uVar2 & 0xff);
              if ((char)(uVar2 >> 8) != 'A') {
                ppiVar10 = (int **)0x14;
              }
              if (ppiVar10 == local_559c) {
                ppiVar17[0x18643a] = (int *)0x5a;
              }
              else {
                ppiVar17[0x18643a] = (int *)0x96;
              }
              ppiVar17[0x18643b] = (int *)0x0;
            }
          }
LAB_00449139:
          iVar19 = *(int *)((int)this + 8);
          local_5598 = (int **)((int)local_5598 + 1);
        } while ((int)local_5598 < *(int *)(iVar19 + 0x2400));
      }
      iVar19 = *(int *)((int)this + 8);
      iVar16 = 0;
      local_5581 = '\0';
      local_5598 = (int **)0x0;
      if (*(int *)(iVar19 + 0x2400) < 1) {
LAB_00449210:
        iVar19 = *(int *)((int)this + 8);
        iVar16 = 0;
        if (0 < *(int *)(iVar19 + 0x2400)) {
          local_5590 = (int *)0x0;
          do {
            local_548c = *(int *)(iVar19 + 0x18 + (int)local_5590);
            pvVar20 = (void *)(iVar19 + 0x14 + (int)local_5590);
            puVar9 = (undefined4 *)GameBoard_GetPowerRec(pvVar20,local_5448,(int *)&local_559c);
            if (((void *)*puVar9 == (void *)0x0) || ((void *)*puVar9 != pvVar20)) {
              FUN_0047a948();
            }
            if (puVar9[1] != local_548c) {
              iVar19 = (int)local_559c * 0x100 + iVar16;
              *(undefined4 *)(&DAT_006190e8 + iVar19 * 8) = 600;
              *(undefined4 *)(&DAT_006190ec + iVar19 * 8) = 0;
            }
            iVar19 = *(int *)((int)this + 8);
            local_5590 = local_5590 + 9;
            iVar16 = iVar16 + 1;
          } while (iVar16 < *(int *)(iVar19 + 0x2400));
        }
      }
      else {
        do {
          local_5454 = *(int *)(iVar19 + 0x18 + iVar16);
          pvVar20 = (void *)(iVar19 + 0x14 + iVar16);
          puVar9 = (undefined4 *)GameBoard_GetPowerRec(pvVar20,local_5410,(int *)&local_559c);
          if (((void *)*puVar9 == (void *)0x0) || ((void *)*puVar9 != pvVar20)) {
            FUN_0047a948();
          }
          if (puVar9[1] != local_5454) {
            uVar2 = *(ushort *)(iVar16 + 0x20 + *(int *)((int)this + 8));
            ppiVar17 = (int **)(uVar2 & 0xff);
            if ((char)(uVar2 >> 8) != 'A') {
              ppiVar17 = (int **)0x14;
            }
            if (ppiVar17 == local_559c) {
              local_5581 = '\x01';
            }
          }
          iVar19 = *(int *)((int)this + 8);
          local_5598 = (int **)((int)local_5598 + 1);
          iVar16 = iVar16 + 0x24;
        } while ((int)local_5598 < *(int *)(iVar19 + 0x2400));
        if (local_5581 == '\0') goto LAB_00449210;
      }
      if (WIN != *(short *)(*(int *)((int)this + 8) + 0x244a)) {
        local_5564 = (int *)**(undefined4 **)((int)local_554c + 0x368c);
        local_5574 = (int **)((int)local_554c + 0x3688);
        local_5568 = local_5574;
        while( true ) {
          piVar18 = local_5564;
          ppiVar17 = local_5568;
          piVar11 = local_5574[1];
          if ((local_5568 == (int **)0x0) || (local_5568 != local_5574)) {
            FUN_0047a948();
          }
          if (piVar18 == piVar11) break;
          if (ppiVar17 == (int **)0x0) {
            FUN_0047a948();
          }
          if ((piVar18 == ppiVar17[1]) && (FUN_0047a948(), piVar18 == ppiVar17[1])) {
            FUN_0047a948();
          }
          local_5598 = AdjacencyList_FilterByUnitType
                                 ((void *)(*(int *)((int)this + 8) + 8 + piVar18[4] * 0x24),
                                  (ushort *)(piVar18 + 5));
          local_5588 = (int *)*local_5598[1];
          local_558c = local_5598;
          while( true ) {
            piVar18 = local_5588;
            ppiVar17 = local_558c;
            piVar11 = local_5598[1];
            if ((local_558c == (int **)0x0) || (local_558c != local_5598)) {
              FUN_0047a948();
            }
            if (piVar18 == piVar11) break;
            if (ppiVar17 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar18 == ppiVar17[1]) {
              FUN_0047a948();
            }
            if (*(char *)(*(int *)((int)this + 8) + 3 + piVar18[3] * 0x24) != '\0') {
              if (piVar18 == ppiVar17[1]) {
                FUN_0047a948();
              }
              uVar2 = *(ushort *)(*(int *)((int)this + 8) + 0x20 + piVar18[3] * 0x24);
              ppiVar17 = (int **)(uVar2 & 0xff);
              if ((char)(uVar2 >> 8) != 'A') {
                ppiVar17 = (int **)0x14;
              }
              iVar19 = (int)local_559c * 0x15 + (int)ppiVar17;
              if (((int)(&g_AllyTrustScore_Hi)[iVar19 * 2] < 1) &&
                 ((((int)(&g_AllyTrustScore_Hi)[iVar19 * 2] < 0 ||
                   ((uint)(&g_AllyTrustScore)[iVar19 * 2] < 0xf)) && (ppiVar17 != local_559c))))
              goto LAB_00449436;
            }
            FUN_0040f400((int *)&local_558c);
          }
          if (local_5564 == local_5568[1]) {
            FUN_0047a948();
          }
          iVar19 = (int)local_559c * 0x100 + local_5564[4];
          if ((&g_EnemyReachScore)[iVar19 * 2] == 0 && (&DAT_00535cec)[iVar19 * 2] == 0) {
            if (local_5564 == local_5568[1]) {
              FUN_0047a948();
            }
            local_5564[6] = 0;
            local_5564[7] = 0;
          }
LAB_00449436:
          std_Tree_IteratorIncrement((int *)&local_5568);
        }
      }
      iVar19 = *(int *)((int)this + 8);
      if (((WIN == *(short *)(iVar19 + 0x244a)) &&
          (*(uint *)(iVar19 + 0x24bc) < *(uint *)(iVar19 + 0x24e0))) &&
         (local_5598 = (int **)0x0, 0 < *(int *)(iVar19 + 0x2400))) {
        local_5590 = (int *)((int)local_559c << 8);
        ppiVar10 = (int **)((int)this + 0x2a1c);
        ppiVar17 = (int **)((int)local_559c << 0xb);
        local_5580 = (int *)0x0;
        do {
          local_5594 = ppiVar17;
          local_5574 = ppiVar10;
          if ((((-1 < (int)ppiVar17[0x18643b]) &&
               ((0 < (int)ppiVar17[0x18643b] || ((int *)0x14 < ppiVar17[0x18643a])))) &&
              (uVar2 = *(ushort *)(iVar19 + 0x20 + (int)local_5580), (char)(uVar2 >> 8) == 'A')) &&
             ((uVar2 & 0xff) != 0x14)) {
            piVar11 = ppiVar17[0x163e3b];
            piVar18 = ppiVar17[0x14d73b];
            iVar19 = (int)piVar11 + (uint)((int *)0xfffffffe < ppiVar17[0x163e3a]);
            if ((((int)piVar18 <= iVar19) &&
                ((((int)piVar18 < iVar19 ||
                  (ppiVar17[0x14d73a] <= (int *)((int)ppiVar17[0x163e3a] + 1U))) &&
                 ((int)piVar11 <= (int)piVar18)))) &&
               (((int)piVar11 < (int)piVar18 || (ppiVar17[0x163e3a] <= ppiVar17[0x14d73a])))) {
              local_5554 = (int *)*ppiVar10[1];
              local_5558 = ppiVar10;
              while( true ) {
                ppiVar12 = local_5558;
                ppiVar10 = local_5574;
                ppiVar17 = local_5594;
                local_546c = local_5574[1];
                if ((local_5558 == (int **)0x0) || (local_5558 != local_5574)) {
                  FUN_0047a948();
                }
                if (local_5554 == local_546c) break;
                iVar19 = *(int *)((int)this + 8);
                local_547c = *(int *)(iVar19 + 0x2454);
                if (ppiVar12 == (int **)0x0) {
                  FUN_0047a948();
                }
                if (local_5554 == ppiVar12[1]) {
                  FUN_0047a948();
                }
                piVar18 = local_5554 + 3;
                piVar11 = (int *)OrderedSet_FindOrInsert
                                           ((void *)(*(int *)((int)this + 8) + 0x2450),local_5438,
                                            piVar18);
                if ((*piVar11 == 0) || (*piVar11 != iVar19 + 0x2450)) {
                  FUN_0047a948();
                }
                if (piVar11[1] == local_547c) {
                  uVar2 = *(ushort *)((int)local_5580 + *(int *)((int)this + 8) + 0x20);
                  uVar14 = uVar2 & 0xff;
                  if ((char)(uVar2 >> 8) != 'A') {
                    uVar14 = 0x14;
                  }
                  iVar19 = (int)local_559c * 0x15 + uVar14;
                  if ((&g_AllyTrustScore)[iVar19 * 2] == 0 &&
                      (&g_AllyTrustScore_Hi)[iVar19 * 2] == 0) {
                    if (local_5554 == local_5558[1]) {
                      FUN_0047a948();
                    }
                    if (*(int *)(&DAT_006190e8 + (*piVar18 + (int)local_5590) * 8) == 0 &&
                        *(int *)(&DAT_006190ec + (*piVar18 + (int)local_5590) * 8) == 0) {
                      if (local_5554 == local_5558[1]) {
                        FUN_0047a948();
                      }
                      uVar23 = __alldiv((uint)local_5594[0x18643a],(uint)local_5594[0x18643b],2,0);
                      iVar19 = *piVar18;
                      *(int *)(&DAT_006190e8 + (iVar19 + (int)local_5590) * 8) = (int)uVar23;
                      *(int *)(&DAT_006190ec + (iVar19 + (int)local_5590) * 8) =
                           (int)((ulonglong)uVar23 >> 0x20);
                    }
                  }
                }
                TreeIterator_Advance((int *)&local_5558);
              }
            }
          }
          if ((-1 < (int)ppiVar17[0x18103b]) &&
             ((0 < (int)ppiVar17[0x18103b] || ((int *)0xf < ppiVar17[0x18103a])))) {
            iVar19 = *(int *)((int)this + 8);
            uVar2 = *(ushort *)((int)local_5580 + iVar19 + 0x20);
            ppiVar12 = (int **)(uVar2 & 0xff);
            if ((char)(uVar2 >> 8) != 'A') {
              ppiVar12 = (int **)0x14;
            }
            if (ppiVar12 == local_559c) {
              if (((int)ppiVar17[0x163e3b] <= (int)ppiVar17[0x14d73b]) &&
                 (((int)ppiVar17[0x163e3b] < (int)ppiVar17[0x14d73b] ||
                  (ppiVar17[0x163e3a] < ppiVar17[0x14d73a])))) {
                local_545c = *(int *)((int)local_5580 + iVar19 + 0x18);
                pvVar20 = (void *)((int)local_5580 + iVar19 + 0x14);
                local_54f4 = (int *)GameBoard_GetPowerRec(pvVar20,local_5428,(int *)&local_559c);
                if (((void *)*local_54f4 == (void *)0x0) || ((void *)*local_54f4 != pvVar20)) {
                  FUN_0047a948();
                }
                if ((local_54f4[1] == local_545c) ||
                   ((ppiVar17[0x14833a] == (int *)0x1 && (ppiVar17[0x14833b] == (int *)0x0)))) {
                  local_5554 = (int *)*ppiVar10[1];
                  local_5558 = ppiVar10;
                  while( true ) {
                    ppiVar12 = local_5558;
                    local_54e4 = ppiVar10[1];
                    if ((local_5558 == (int **)0x0) || (local_5558 != ppiVar10)) {
                      FUN_0047a948();
                    }
                    if (local_5554 == local_54e4) break;
                    iVar19 = *(int *)((int)this + 8);
                    local_54d4 = *(int *)(iVar19 + 0x2454);
                    if (ppiVar12 == (int **)0x0) {
                      FUN_0047a948();
                    }
                    if (local_5554 == ppiVar12[1]) {
                      FUN_0047a948();
                    }
                    piVar18 = local_5554 + 3;
                    piVar11 = (int *)OrderedSet_FindOrInsert
                                               ((void *)(*(int *)((int)this + 8) + 0x2450),
                                                local_5418,piVar18);
                    if ((*piVar11 == 0) || (*piVar11 != iVar19 + 0x2450)) {
                      FUN_0047a948();
                    }
                    if (piVar11[1] == local_54d4) {
                      if (local_5554 == local_5558[1]) {
                        FUN_0047a948();
                      }
                      if ((&g_AttackCount)[(*piVar18 + (int)local_5590) * 2] == 0 &&
                          (&DAT_006040ec)[(*piVar18 + (int)local_5590) * 2] == 0) {
                        if (local_5554 == local_5558[1]) {
                          FUN_0047a948();
                        }
                        uVar23 = __alldiv((uint)local_5594[0x18103a],(uint)local_5594[0x18103b],2,0)
                        ;
                        iVar19 = *piVar18;
                        (&g_AttackCount)[(iVar19 + (int)local_5590) * 2] = (int)uVar23;
                        (&DAT_006040ec)[(iVar19 + (int)local_5590) * 2] =
                             (int)((ulonglong)uVar23 >> 0x20);
                      }
                    }
                    TreeIterator_Advance((int *)&local_5558);
                    ppiVar10 = local_5574;
                    ppiVar17 = local_5594;
                  }
                }
              }
            }
          }
          iVar19 = *(int *)((int)this + 8);
          local_5580 = local_5580 + 9;
          local_5598 = (int **)((int)local_5598 + 1);
          ppiVar17 = ppiVar17 + 2;
          ppiVar10 = ppiVar10 + 3;
          local_5594 = ppiVar17;
          local_5574 = ppiVar10;
        } while ((int)local_5598 < *(int *)(iVar19 + 0x2400));
      }
      iVar19 = *(int *)((int)this + 8);
      local_5598 = (int **)0x0;
      if (0 < *(int *)(iVar19 + 0x2400)) {
        do {
          local_5544 = (int *)**(undefined4 **)(iVar19 + 0xc + (int)local_5598 * 0x24);
          local_5574 = (int **)(iVar19 + 8 + (int)local_5598 * 0x24);
          local_5548 = local_5574;
          local_5530 = local_5598;
          while( true ) {
            piVar11 = local_5544;
            ppiVar10 = local_5548;
            ppiVar17 = local_5598;
            local_54c4 = local_5574[1];
            if ((local_5548 == (int **)0x0) || (local_5548 != local_5574)) {
              FUN_0047a948();
            }
            if (piVar11 == local_54c4) break;
            if (ppiVar10 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar11 == ppiVar10[1]) {
              FUN_0047a948();
            }
            local_552c = (short)piVar11[3];
            ppiVar17 = local_5598 + (int)local_559c * 0x40;
            iVar19 = (int)ppiVar17 * 8;
            lVar22 = __allmul(*(uint *)(&DAT_006190e8 + (int)ppiVar17 * 8),
                              *(uint *)(&DAT_006190ec + iVar19),param_1,param_2);
            lVar25 = __allmul((&g_AttackCount)[(int)ppiVar17 * 2],(&DAT_006040ec)[(int)ppiVar17 * 2]
                              ,param_3,param_4);
            ppiVar17 = OrderedSet_FindOrInsert
                                 ((void *)((int)local_554c + 0x361c),(int **)&local_5530);
            *(longlong *)ppiVar17 = lVar25 + lVar22;
            if ((((WIN == *(short *)(*(int *)((int)this + 8) + 0x244a)) &&
                 (*(int *)(&g_SCOwnership + iVar19) == 1)) &&
                (*(int *)(&DAT_00520cec + iVar19) == 0)) &&
               (ppiVar17 = UnitList_FindOrInsert
                                     ((void *)(*(int *)((int)this + 8) + 0x2450),(int *)&local_5598)
               , local_552c == *(short *)(ppiVar17 + 1))) {
              ppiVar17 = OrderedSet_FindOrInsert
                                   ((void *)((int)local_554c + 0x361c),(int **)&local_5530);
              piVar11 = *ppiVar17;
              *ppiVar17 = *ppiVar17 + -0x9c4;
              ppiVar17[1] = (int *)((int)ppiVar17[1] + (((int *)0x270f < piVar11) - 1));
            }
            iVar19 = 8;
            ppiVar17 = local_553c;
            do {
              ppiVar10 = OrderedSet_FindOrInsert(ppiVar17,(int **)&local_5530);
              ppiVar17 = ppiVar17 + 3;
              iVar19 = iVar19 + -1;
              *ppiVar10 = (int *)0x0;
              ppiVar10[1] = (int *)0x0;
            } while (iVar19 != 0);
            FUN_00401590((int *)&local_5548);
          }
          iVar19 = *(int *)((int)this + 8);
          local_5598 = (int **)((int)ppiVar17 + 1);
        } while ((int)local_5598 < *(int *)(iVar19 + 0x2400));
      }
      iVar19 = *(int *)((int)this + 8);
      if (WIN == *(short *)(iVar19 + 0x244a)) {
        local_551c = **(int **)(iVar19 + 0x2478);
        local_5520 = iVar19 + 0x2474;
        while( true ) {
          iVar16 = local_551c;
          uVar14 = local_5520;
          iVar19 = *(int *)(*(int *)((int)this + 8) + 0x2478);
          if ((local_5520 == 0) || (local_5520 != *(int *)((int)this + 8) + 0x2474U)) {
            FUN_0047a948();
          }
          if (iVar16 == iVar19) break;
          if (uVar14 == 0) {
            FUN_0047a948();
          }
          if (iVar16 == *(int *)(uVar14 + 4)) {
            FUN_0047a948();
          }
          local_54fc = *(int **)(iVar16 + 0xc);
          if (iVar16 == *(int *)(uVar14 + 4)) {
            FUN_0047a948();
          }
          local_54f8 = *(undefined2 *)(iVar16 + 0x10);
          if (*(uint *)(*(int *)((int)this + 8) + 0x24e0) <
              *(uint *)(*(int *)((int)this + 8) + 0x24bc)) {
            ppiVar17 = OrderedSet_FindOrInsert((void *)((int)local_554c + 0x361c),&local_54fc);
            piVar11 = *ppiVar17;
            *ppiVar17 = *ppiVar17 + 0x9c4;
            ppiVar17[1] = (int *)((int)ppiVar17[1] + (uint)((int *)0xffffd8ef < piVar11));
            FUN_0040e680((int *)&local_5520);
          }
          else {
            ppiVar17 = OrderedSet_FindOrInsert((void *)((int)local_554c + 0x361c),&local_54fc);
            piVar11 = *ppiVar17;
            *ppiVar17 = *ppiVar17 + -0x9c4;
            ppiVar17[1] = (int *)((int)ppiVar17[1] + (((int *)0x270f < piVar11) - 1));
            FUN_0040e680((int *)&local_5520);
          }
        }
      }
      local_5594 = local_553c;
      local_553c = (int **)0x8;
      do {
        local_5564 = (int *)*local_5594[1];
        local_5568 = local_5594;
        while( true ) {
          piVar11 = local_5564;
          ppiVar10 = local_5568;
          ppiVar17 = local_5594;
          local_54b4 = local_5594[1];
          if ((local_5568 == (int **)0x0) || (local_5568 != local_5594)) {
            FUN_0047a948();
          }
          if (piVar11 == local_54b4) break;
          if (ppiVar10 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar11 == ppiVar10[1]) {
            FUN_0047a948();
          }
          if (piVar11 == ppiVar10[1]) {
            FUN_0047a948();
          }
          local_5598 = AdjacencyList_FilterByUnitType
                                 ((void *)(*(int *)((int)this + 8) + 8 + (int)piVar11[4] * 0x24),
                                  (ushort *)(piVar11 + 5));
          local_5588 = (int *)*local_5598[1];
          local_5580 = (int *)0xffffffff;
          local_558c = local_5598;
          while( true ) {
            ppiVar17 = local_558c;
            local_54a4 = local_5598[1];
            if ((local_558c == (int **)0x0) || (local_558c != local_5598)) {
              FUN_0047a948();
            }
            if (local_5588 == local_54a4) break;
            if (ppiVar17 == (int **)0x0) {
              FUN_0047a948();
            }
            if (local_5588 == ppiVar17[1]) {
              FUN_0047a948();
            }
            ppiVar17 = (int **)(local_5588 + 3);
            if ((int *)local_5588[3] == local_5580) {
              if (local_5588 == local_558c[1]) {
                FUN_0047a948();
              }
              ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,ppiVar17);
              if (((int)local_555c <= (int)ppiVar10[1]) &&
                 (((int)local_555c < (int)ppiVar10[1] || (local_5560 < *ppiVar10)))) {
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                piVar18 = (int *)piVar11[6];
                piVar11[6] = (int)piVar18 - (int)local_5560;
                piVar11[7] = (piVar11[7] - (int)local_555c) - (uint)(piVar18 < local_5560);
                if (local_5588 == local_558c[1]) {
                  FUN_0047a948();
                }
                ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,ppiVar17);
                local_5560 = *ppiVar10;
                local_555c = ppiVar10[1];
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                if (piVar11 == local_5568[1]) {
                  FUN_0047a948();
                }
                uVar14 = piVar11[6];
                piVar11[6] = uVar14 + (int)local_5560;
                piVar11[7] = (int)local_555c + (uint)CARRY4(uVar14,(uint)local_5560) + piVar11[7];
              }
            }
            else {
              if (local_5588 == local_558c[1]) {
                FUN_0047a948();
              }
              ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,ppiVar17);
              local_5560 = *ppiVar10;
              local_555c = ppiVar10[1];
              if (piVar11 == local_5568[1]) {
                FUN_0047a948();
              }
              if (piVar11 == local_5568[1]) {
                FUN_0047a948();
              }
              uVar14 = piVar11[6];
              piVar11[6] = uVar14 + (int)local_5560;
              piVar11[7] = (int)local_555c + (uint)CARRY4(uVar14,(uint)local_5560) + piVar11[7];
            }
            if (local_5588 == local_558c[1]) {
              FUN_0047a948();
            }
            local_5580 = *ppiVar17;
            FUN_0040f400((int *)&local_558c);
          }
          if (piVar11 == local_5568[1]) {
            FUN_0047a948();
          }
          if (piVar11 == local_5568[1]) {
            FUN_0047a948();
          }
          if (piVar11 == local_5568[1]) {
            FUN_0047a948();
          }
          ppiVar10 = OrderedSet_FindOrInsert(local_5594 + -3,(int **)(piVar11 + 4));
          ppiVar17 = local_5568;
          uVar14 = piVar11[6];
          piVar18 = *ppiVar10;
          piVar3 = ppiVar10[1];
          piVar11[6] = uVar14 + (int)*ppiVar10;
          piVar11[7] = (int)piVar3 + (uint)CARRY4(uVar14,(uint)piVar18) + piVar11[7];
          if ((piVar11 == local_5568[1]) && (FUN_0047a948(), piVar11 == ppiVar17[1])) {
            FUN_0047a948();
          }
          uVar23 = __alldiv(piVar11[6],piVar11[7],5,0);
          *(undefined8 *)(piVar11 + 6) = uVar23;
          std_Tree_IteratorIncrement((int *)&local_5568);
        }
        local_5594 = ppiVar17 + 3;
        local_553c = (int **)((int)local_553c + -1);
      } while (local_553c != (int **)0x0);
      iVar19 = *(int *)((int)this + 8);
      local_559c = (int **)((int)local_559c + 1);
      local_553c = (int **)0x0;
      fVar4 = _g_NearEndGameFactor;
    } while ((int)local_559c < *(int *)(iVar19 + 0x2404));
  }
  iVar19 = *(int *)((int)this + 8);
  iVar16 = 0;
  if (0 < *(int *)(iVar19 + 0x2400)) {
    local_5590 = (int *)0x0;
    do {
      if (*(char *)(iVar19 + 3 + (int)local_5590) != '\0') {
        uVar2 = *(ushort *)(iVar19 + 0x20 + (int)local_5590);
        uVar14 = uVar2 & 0xff;
        if ((char)(uVar2 >> 8) != 'A') {
          uVar14 = 0x14;
        }
        if (-1 < (int)(&DAT_004d2614)[iVar16 * 2]) {
          if ((-1 < (int)(&DAT_004d2e14)[iVar16 * 2]) &&
             ((((&DAT_004d2610)[iVar16 * 2] != (&g_AllyDesignation_A)[iVar16 * 2] ||
               ((&DAT_004d2614)[iVar16 * 2] != (&DAT_004d2e14)[iVar16 * 2])) &&
              (iVar19 = uVar14 * 0x100 + iVar16,
              (&DAT_0058f8e8)[iVar19 * 2] == 0 && (&DAT_0058f8ec)[iVar19 * 2] == 0)))) {
            (&DAT_004d2610)[iVar16 * 2] = 0xffffffff;
            (&DAT_004d2614)[iVar16 * 2] = 0xffffffff;
          }
        }
      }
      iVar19 = *(int *)((int)this + 8);
      local_5590 = (int *)((int)local_5590 + 0x24);
      iVar16 = iVar16 + 1;
    } while (iVar16 < *(int *)(iVar19 + 0x2400));
  }
  if (5.0 < fVar4) {
    iVar19 = *(int *)((int)this + 8);
    iVar16 = 0;
    if (0 < *(int *)(iVar19 + 0x2400)) {
      iVar6 = 0;
      do {
        if (*(char *)(iVar19 + 3 + iVar6) != '\0') {
          uVar2 = *(ushort *)(iVar19 + 0x20 + iVar6);
          uVar14 = uVar2 & 0xff;
          if ((char)(uVar2 >> 8) != 'A') {
            uVar14 = 0x14;
          }
          iVar19 = uVar14 * 0x100 + iVar16;
          if ((((&DAT_0058f8e8)[iVar19 * 2] == 0 && (&DAT_0058f8ec)[iVar19 * 2] == 0) &&
              (-1 < (int)(&DAT_00535cec)[iVar19 * 2])) &&
             ((0 < (int)(&DAT_00535cec)[iVar19 * 2] || ((&g_EnemyReachScore)[iVar19 * 2] != 0)))) {
            (&DAT_004d2610)[iVar16 * 2] = 0xfffffffe;
            (&DAT_004d0e10)[iVar16 * 2] = 0xfffffffe;
            *(undefined4 *)(&DAT_005014e8 + iVar19 * 8) = 1;
            (&DAT_004d2614)[iVar16 * 2] = 0xffffffff;
            (&DAT_004d0e14)[iVar16 * 2] = 0xffffffff;
            *(undefined4 *)(&DAT_005014ec + iVar19 * 8) = 0;
          }
        }
        iVar19 = *(int *)((int)this + 8);
        iVar16 = iVar16 + 1;
        iVar6 = iVar6 + 0x24;
      } while (iVar16 < *(int *)(iVar19 + 0x2400));
    }
  }
  return;
}

