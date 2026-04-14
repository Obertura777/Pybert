
ulonglong __thiscall EvaluateOrderScore(void *this,int param_1)

{
  longlong *plVar1;
  void *this_00;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  int **ppiVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int **ppiVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  ulonglong *puVar15;
  uint unaff_EDI;
  float10 extraout_ST0;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  ulonglong uVar19;
  float local_130;
  float *local_12c;
  float local_128;
  int local_124;
  float local_120;
  float local_118;
  int local_114;
  int **local_110;
  int *piStack_10c;
  int **local_104;
  uint local_100;
  int iStack_fc;
  int *local_f4;
  int *local_ec;
  uint local_e8;
  uint uStack_e4;
  int local_e0;
  int iStack_dc;
  int local_d8;
  int iStack_d4;
  int local_d0;
  int iStack_cc;
  int local_c8;
  int iStack_c4;
  int local_c0;
  int iStack_bc;
  int local_b8;
  int iStack_b4;
  void *local_b0 [4];
  void *local_a0 [4];
  void *local_90 [17];
  void *local_4c;
  undefined1 *puStack_48;
  int local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_004972c8;
  local_4c = ExceptionList;
  uVar8 = DAT_004c8db8 ^ (uint)&stack0xfffffec0;
  ExceptionList = &local_4c;
  FUN_00465870(local_90);
  local_44 = 0;
  FUN_00465870(local_a0);
  local_44._0_1_ = 1;
  FUN_00465870(local_b0);
  local_104 = *(int ***)((int)this + 8);
  local_120 = 500.0;
  local_44 = CONCAT31(local_44._1_3_,2);
  local_124 = 0;
  if (0 < (int)local_104[0x900]) {
    local_12c = (float *)(&DAT_00540ce8 + param_1 * 0x100);
    local_128 = 0.0;
    local_f4 = &g_OrderTable;
    iVar13 = param_1 << 0xb;
    do {
      fVar18 = (float10)0.25;
      if ((-1 < *(int *)((int)&DAT_0058f8ec + iVar13)) &&
         ((0 < *(int *)((int)&DAT_0058f8ec + iVar13) || (*(int *)((int)&DAT_0058f8e8 + iVar13) != 0)
          ))) {
        uVar3 = local_f4[0xd];
        if ((int)uVar3 < 1) {
          if (((uVar3 == 0) && (uVar3 = local_f4[0xf], 0 < (int)uVar3)) &&
             ((local_f4[0x12] & local_f4[0x13]) == 0xffffffff)) {
            iStack_fc = (int)uVar3 >> 0x1f;
            local_ec = (int *)(local_f4[0x10] >> 0x1f);
            if (*(int *)(&g_SCOwnership + iVar13) == 0 && *(int *)(&DAT_00520cec + iVar13) == 0) {
              iVar12 = *(int *)((int)&DAT_0058f8ec + iVar13);
              if (iVar12 < iStack_fc) {
                uVar4 = *(uint *)((int)&DAT_0058f8e8 + iVar13);
              }
              else if ((iStack_fc < iVar12) ||
                      (uVar4 = *(uint *)((int)&DAT_0058f8e8 + iVar13), uVar3 < uVar4)) {
                local_130 = 1.0;
                goto LAB_00437d40;
              }
              if ((uVar4 == uVar3) && (iVar12 == iStack_fc)) {
                if ((*(int *)(&DAT_004f6ce8 + iVar13) == 1) &&
                   (*(int *)(&DAT_004f6cec + iVar13) == 0)) {
LAB_00437d2e:
                  local_130 = 0.25;
                }
                else {
                  local_130 = 0.33;
                }
              }
              else {
                if (*(int *)(&DAT_004f6ce8 + iVar13) != 1) goto LAB_00437d2e;
                if ((*(int *)(&DAT_004f6cec + iVar13) == 0) &&
                   (*(char *)((int)local_128 + 3 + (int)local_104) == '\x01')) {
                  local_130 = 0.05;
                }
                else {
                  if (*(int *)(&DAT_004f6cec + iVar13) != 0) goto LAB_00437d2e;
                  local_130 = 0.15;
                }
              }
            }
            else {
              if (local_f4[0x10] == 1) {
                fVar18 = (float10)*local_12c;
              }
              else {
                fVar18 = (float10)(longlong)(int)uVar3 * (float10)0.5;
              }
              local_130 = (float)fVar18;
              if (1.0 < local_130) {
                local_130 = 1.0;
              }
            }
LAB_00437d40:
            iVar12 = *(int *)(&g_MaxProvinceScore + iVar13);
            iVar9 = *(int *)(&DAT_0055b0ec + iVar13);
            local_f4[4] = (int)local_130;
            local_f4[6] = -iVar12;
            local_f4[7] = -(iVar9 + (uint)(iVar12 != 0));
            local_100 = uVar3;
          }
        }
        else {
          iVar12 = (int)uVar3 >> 0x1f;
          local_130 = 0.0;
          local_110 = (int **)local_f4[0xe];
          piStack_10c = (int *)((int)local_110 >> 0x1f);
          local_100 = local_f4[0xf];
          iStack_fc = (int)local_100 >> 0x1f;
          if ((((*(int *)((int)&DAT_006040ec + iVar13) < 0) ||
               (((*(int *)((int)&DAT_006040ec + iVar13) < 1 &&
                 (*(int *)((int)&g_AttackCount + iVar13) == 0)) ||
                (*(int *)(&DAT_004f6ce8 + iVar13) != 0 || *(int *)(&DAT_004f6cec + iVar13) != 0))))
              && (((iVar9 = *local_f4, iVar9 != 1 && (iVar9 != 3)) && (iVar9 != 4)))) &&
             ((iVar9 != 5 && (local_f4[0x14] < 2)))) {
            FUN_0040e890((float10 *)0x33333333,(double)CONCAT44(uVar8,local_f4[0x11] / 10),unaff_EDI
                        );
            local_118 = (float)extraout_ST0;
            iVar9 = iVar12 + (uint)(0xfffffffe < uVar3);
            if ((iVar9 <= iStack_fc) &&
               (((iVar9 < iStack_fc || (uVar3 + 1 < local_100)) &&
                (*(char *)((int)local_128 + 3 + (int)local_104) == '\x01')))) {
              local_c0 = uVar3 - 1;
              iStack_bc = iVar12 - (uint)(uVar3 == 0);
              fVar18 = (float10)local_118 * (float10)0.1 +
                       (float10)CONCAT44(iStack_bc,local_c0) * (float10)0.25;
              fVar16 = (float10)CONCAT44(piStack_10c,local_110) * (float10)0.15;
              goto LAB_0043799c;
            }
            if ((iVar12 <= iStack_fc) && ((iVar12 < iStack_fc || (uVar3 < local_100)))) {
              if (*(char *)((int)local_128 + 3 + (int)local_104) != '\x01') {
                fVar18 = (float10)0.15;
                local_b8 = uVar3 - 1;
                iStack_b4 = iVar12 - (uint)(uVar3 == 0);
                fVar17 = (float10)local_118 * fVar18 + (float10)0.1;
                fVar16 = (float10)CONCAT44(iStack_b4,local_b8) * (float10)0.25;
LAB_00437994:
                fVar16 = fVar16 + fVar17;
                goto LAB_00437996;
              }
              local_c8 = uVar3 - 1;
              iStack_c4 = iVar12 - (uint)(uVar3 == 0);
              fVar18 = (float10)CONCAT44(iStack_c4,local_c8) * (float10)0.25 +
                       (float10)local_118 * (float10)0.1 + (float10)0.05;
              fVar16 = (float10)CONCAT44(piStack_10c,local_110) * (float10)0.15;
              goto LAB_0043799c;
            }
            if ((uVar3 == local_100) && (iVar12 == iStack_fc)) {
              iVar9 = *(int *)((int)&DAT_005a48ec + iVar13);
              if ((iVar9 < 0) ||
                 ((((iVar9 < 1 && (*(uint *)((int)&g_AttackHistory + iVar13) < 0xb)) ||
                   (*(int *)(&DAT_004f6ce8 + iVar13) != 0 || *(int *)(&DAT_004f6cec + iVar13) != 0))
                  || ((*(char *)((int)local_128 + 3 + (int)local_104) != '\0' &&
                      (SPR != *(short *)((int)local_104 + 0x244a))))))) {
                if ((*(char *)((int)local_128 + 3 + (int)local_104) == '\0') &&
                   (((iVar9 < 1 && ((iVar9 < 0 || (*(uint *)((int)&g_AttackHistory + iVar13) < 10)))
                     ) && (local_f4[0x11] < 0xf)))) {
                  local_d0 = uVar3 - 1;
                  iStack_cc = iVar12 - (uint)(uVar3 == 0);
                  fVar17 = ((float10)local_118 * (float10)0.2 + (float10)0.25) -
                           (float10)*(longlong *)(&DAT_004f6ce8 + iVar13) * (float10)0.1;
                  lVar2 = CONCAT44(iStack_cc,local_d0);
                }
                else {
                  local_d8 = uVar3 - 1;
                  iStack_d4 = iVar12 - (uint)(uVar3 == 0);
                  fVar17 = (float10)local_118 * (float10)0.2 + (float10)0.15;
                  lVar2 = CONCAT44(iStack_d4,local_d8);
                }
                fVar18 = (float10)0.2;
                fVar16 = (float10)lVar2 * (float10)0.3;
                goto LAB_00437994;
              }
              local_130 = 0.8;
            }
            else if ((iStack_fc <= iVar12) && ((iStack_fc < iVar12 || (local_100 < uVar3)))) {
              local_130 = 1.0;
            }
          }
          else {
            if ((iStack_fc < iVar12) || ((iStack_fc <= iVar12 && (local_100 <= uVar3)))) {
              if ((uVar3 == local_100) && (iVar12 == iStack_fc)) {
                local_130 = 1.0;
              }
              else if ((iStack_fc <= iVar12) && ((iStack_fc < iVar12 || (local_100 < uVar3)))) {
                local_130 = 1.0;
              }
              goto LAB_00437a5d;
            }
            if (*(char *)((int)local_128 + 3 + (int)local_104) == '\x01') {
              local_e0 = uVar3 - 1;
              iStack_dc = iVar12 - (uint)(uVar3 == 0);
              fVar16 = (float10)CONCAT44(iStack_dc,local_e0) * (float10)0.3 + (float10)0.15;
            }
            else {
              local_e8 = uVar3 - 1;
              uStack_e4 = iVar12 - (uint)(uVar3 == 0);
              fVar16 = (float10)CONCAT44(uStack_e4,local_e8) * (float10)0.3 + (float10)0.35;
            }
LAB_00437996:
            fVar18 = (float10)CONCAT44(piStack_10c,local_110) * fVar18;
LAB_0043799c:
            local_130 = (float)(fVar16 + fVar18);
            if (1.0 < local_130) {
              local_130 = 1.0;
            }
          }
LAB_00437a5d:
          local_f4[4] = (int)local_130;
        }
      }
      local_104 = *(int ***)((int)this + 8);
      local_12c = local_12c + 1;
      local_128 = (float)((int)local_128 + 0x24);
      local_124 = local_124 + 1;
      local_f4 = local_f4 + 0x1e;
      iVar13 = iVar13 + 8;
    } while (local_124 < (int)local_104[0x900]);
  }
  local_12c = (float *)0x3;
  do {
    local_124 = 0;
    if (0 < *(int *)(*(int *)((int)this + 8) + 0x2400)) {
      piVar14 = &DAT_00baeda8;
      do {
        if (piVar14[-2] == 2) {
          if ((0 < piVar14[0xb]) && (piVar14[0x12] < 2)) {
            iVar13 = local_124 + param_1 * 0x100;
            if (((((&g_AttackCount)[iVar13 * 2] == 0 && (&DAT_006040ec)[iVar13 * 2] == 0) &&
                 (((int)(&DAT_005a48ec)[iVar13 * 2] < 0 ||
                  (((int)(&DAT_005a48ec)[iVar13 * 2] < 1 &&
                   ((uint)(&g_AttackHistory)[iVar13 * 2] < 0xb)))))) ||
                (((&g_AttackCount)[iVar13 * 2] == 0 && (&DAT_006040ec)[iVar13 * 2] == 0 &&
                 (((-1 < (int)(&DAT_005a48ec)[iVar13 * 2] &&
                   (((0 < (int)(&DAT_005a48ec)[iVar13 * 2] ||
                     (10 < (uint)(&g_AttackHistory)[iVar13 * 2])) &&
                    (*(int *)(&DAT_004f6ce8 + iVar13 * 8) == 1)))) &&
                  (*(int *)(&DAT_004f6cec + iVar13 * 8) == 0)))))) || (-1 < piVar14[0x11])) {
              iVar13 = *piVar14;
              if ((&g_ProvinceBaseScore)[iVar13 * 0x1e] == (&DAT_00baeddc)[iVar13 * 0x1e]) {
                iVar12 = iVar13 + param_1 * 0x100;
                if (((0 < (int)(&DAT_006040ec)[iVar12 * 2]) ||
                    ((-1 < (int)(&DAT_006040ec)[iVar12 * 2] && ((&g_AttackCount)[iVar12 * 2] != 0)))
                    ) || ((-1 < (int)(&DAT_005a48ec)[iVar12 * 2] &&
                          (((0 < (int)(&DAT_005a48ec)[iVar12 * 2] ||
                            (10 < (uint)(&g_AttackHistory)[iVar12 * 2])) &&
                           (*(int *)(&DAT_004f6ce8 + iVar12 * 8) == 0 &&
                            *(int *)(&DAT_004f6cec + iVar12 * 8) == 0)))))) {
                  piVar14[2] = 0x3e99999a;
                  goto LAB_00437bfa;
                }
              }
              if ((float)(&DAT_00baedb0)[iVar13 * 0x1e] < (float)piVar14[2]) {
                piVar14[2] = (&DAT_00baedb0)[iVar13 * 0x1e];
              }
            }
          }
LAB_00437bfa:
          if ((((piVar14[-2] == 2) && (piVar14[0xb] == 0)) && (piVar14[5] < 1)) &&
             ((piVar14[5] < 0 && (piVar14[0xd] == 1)))) {
            iVar13 = *piVar14;
            if ((&g_ProvinceBaseScore)[iVar13 * 0x1e] == (&DAT_00baeddc)[iVar13 * 0x1e]) {
              iVar12 = param_1 * 0x100 + iVar13;
              if ((((int)(&DAT_006040ec)[iVar12 * 2] < 1) &&
                  (((int)(&DAT_006040ec)[iVar12 * 2] < 0 || ((&g_AttackCount)[iVar12 * 2] == 0))))
                 && (((int)(&DAT_005a48ec)[iVar12 * 2] < 0 ||
                     ((((int)(&DAT_005a48ec)[iVar12 * 2] < 1 &&
                       ((uint)(&g_AttackHistory)[iVar12 * 2] < 0xb)) ||
                      (*(int *)(&DAT_004f6ce8 + iVar12 * 8) != 0 ||
                       *(int *)(&DAT_004f6cec + iVar12 * 8) != 0)))))) {
                if ((&g_ProvinceBaseScore)[iVar13 * 0x1e] == (&DAT_00baeddc)[iVar13 * 0x1e]) {
                  piVar14[2] = (&DAT_00baedb0)[iVar13 * 0x1e];
                }
              }
              else {
                piVar14[2] = 0x3f000000;
              }
            }
          }
        }
        local_124 = local_124 + 1;
        piVar14 = piVar14 + 0x1e;
      } while (local_124 < *(int *)(*(int *)((int)this + 8) + 0x2400));
    }
    local_12c = (float *)((int)local_12c + -1);
  } while (local_12c != (float *)0x0);
  iVar13 = *(int *)((int)this + 8);
  local_124 = 0;
  if (0 < *(int *)(iVar13 + 0x2400)) {
    local_128 = 0.0;
    local_118 = 0.0;
    do {
      if ((*(char *)((int)local_118 + 4 + iVar13) == '\0') &&
         (*(int *)((int)&g_ProvinceBaseScore + (int)local_128) == 1)) {
        local_110 = AdjacencyList_FilterByUnitType((void *)((int)local_118 + 8 + iVar13),&FLT);
        local_130 = *(float *)((int)&DAT_00baedb0 + (int)local_128);
        if ((local_130 < 1.0) && (0.5 < local_130)) {
          local_130 = 0.5;
        }
        piStack_10c = (int *)*local_110[1];
        local_104 = local_110;
        while( true ) {
          piVar7 = piStack_10c;
          ppiVar10 = local_110;
          piVar14 = local_104[1];
          if ((local_110 == (int **)0x0) || (local_110 != local_104)) {
            FUN_0047a948();
          }
          if (piVar7 == piVar14) break;
          if (ppiVar10 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar7 == ppiVar10[1]) {
            FUN_0047a948();
          }
          if (-1 < *(int *)(&DAT_00baee04 + piVar7[3] * 0x78)) {
            if (piVar7 == ppiVar10[1]) {
              FUN_0047a948();
            }
            iVar13 = *(int *)((int)this + 8) + 0x14 + piVar7[3] * 0x24;
            local_ec = *(int **)(iVar13 + 4);
            if (piVar7 == ppiVar10[1]) {
              FUN_0047a948();
            }
            piVar14 = (int *)GameBoard_GetPowerRec
                                       ((void *)(*(int *)((int)this + 8) + 0x14 + piVar7[3] * 0x24),
                                        (int *)&local_e8,&param_1);
            if ((*piVar14 == 0) || (*piVar14 != iVar13)) {
              FUN_0047a948();
            }
            if ((int *)piVar14[1] == local_ec) {
              if (piVar7 == ppiVar10[1]) {
                FUN_0047a948();
              }
              if ((float)*(longlong *)(&DAT_00baee00 + piVar7[3] * 0x1e) <
                  (float)*(longlong *)((int)&g_ConvoyChainScore + (int)local_128) * local_130 * 0.2)
              {
                if (piVar7 == ppiVar10[1]) {
                  FUN_0047a948();
                }
                goto LAB_0043805c;
              }
            }
            else {
              if (piVar7 == ppiVar10[1]) {
                FUN_0047a948();
              }
              if ((float)*(longlong *)(&DAT_00baee00 + piVar7[3] * 0x1e) <
                  (float)*(longlong *)((int)&g_ConvoyChainScore + (int)local_128) * local_130 * 0.2
                  * 0.75) {
                if (piVar7 == ppiVar10[1]) {
                  FUN_0047a948();
                }
LAB_0043805c:
                uVar19 = PackScoreU64();
                iVar13 = piVar7[3];
                (&DAT_00baee00)[iVar13 * 0x1e] = (int)uVar19;
                *(int *)(&DAT_00baee04 + iVar13 * 0x78) = (int)(uVar19 >> 0x20);
              }
            }
          }
          FUN_0040f400((int *)&local_110);
        }
      }
      iVar13 = *(int *)((int)this + 8);
      local_118 = (float)((int)local_118 + 0x24);
      local_128 = (float)((int)local_128 + 0x78);
      local_124 = local_124 + 1;
    } while (local_124 < *(int *)(iVar13 + 0x2400));
  }
  local_124 = 0;
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2400)) {
    iVar13 = param_1 << 0xb;
    piVar14 = &DAT_00baeda8;
    do {
      plVar1 = (longlong *)((int)&DAT_005460e8 + iVar13);
      local_110 = *(int ***)plVar1;
      piStack_10c = *(int **)((int)&DAT_005460ec + iVar13);
      if (((local_110 == (int **)0x0 && piStack_10c == (int *)0x0) &&
          (*(int *)(&g_SCOwnership + iVar13) == 0 && *(int *)(&DAT_00520cec + iVar13) == 0)) &&
         (piVar14[0xb] == 0)) {
LAB_0043812e:
        piVar14[0x13] = 0x3f800000;
      }
      else if ((((local_110 == (int **)0x0 && piStack_10c == (int *)0x0) && (piVar14[0xb] == 0)) &&
               ((*(int *)(&g_SCOwnership + iVar13) == 1 &&
                ((*(int *)(&DAT_00520cec + iVar13) == 0 && (piVar14[-2] == 2)))))) &&
              (piVar14[0x12] < 2)) {
        iVar12 = *piVar14;
        if ((&g_ProvinceBaseScore)[iVar12 * 0x1e] != (&DAT_00baeddc)[iVar12 * 0x1e])
        goto LAB_0043812e;
        iVar9 = iVar12 + param_1 * 0x100;
        if (((int)(&DAT_006040ec)[iVar9 * 2] < 0) ||
           (((int)(&DAT_006040ec)[iVar9 * 2] < 1 && ((&g_AttackCount)[iVar9 * 2] == 0)))) {
          if ((&g_ProvinceBaseScore)[iVar12 * 0x1e] != (&DAT_00baeddc)[iVar12 * 0x1e])
          goto LAB_0043812e;
          piVar14[0x13] = (&DAT_00baedb0)[iVar12 * 0x1e];
        }
        else {
          piVar14[0x13] = 0x3e99999a;
        }
      }
      else if (((*(int *)(&DAT_004f6ce8 + iVar13) == 1) && (*(int *)(&DAT_004f6cec + iVar13) == 0))
              && (piVar14[0xb] == 0)) {
        piVar14[0x13] = (int)(float)((float10)0.2 / (float10)*plVar1);
      }
      else if (((*(int *)(&DAT_004f6ce8 + iVar13) == 0 && *(int *)(&DAT_004f6cec + iVar13) == 0) &&
               (piVar14[0xb] == 0)) &&
              ((-1 < (int)piStack_10c && ((0 < (int)piStack_10c || (local_110 != (int **)0x0)))))) {
        piVar14[0x13] = (int)(float)((float10)0.4 / (float10)*plVar1);
      }
      local_124 = local_124 + 1;
      iVar13 = iVar13 + 8;
      piVar14 = piVar14 + 0x1e;
    } while (local_124 < *(int *)(*(int *)((int)this + 8) + 0x2400));
  }
  local_114 = **(int **)(*(int *)((int)this + 8) + 0x2454);
  local_118 = (float)(*(int *)((int)this + 8) + 0x2450);
  while( true ) {
    iVar12 = local_114;
    fVar5 = local_118;
    iVar13 = *(int *)(*(int *)((int)this + 8) + 0x2454);
    if ((local_118 == 0.0) || (local_118 != (float)(*(int *)((int)this + 8) + 0x2450))) {
      FUN_0047a948();
    }
    if (iVar12 == iVar13) break;
    if (fVar5 == 0.0) {
      FUN_0047a948();
    }
    if (iVar12 == *(int *)((int)fVar5 + 4)) {
      FUN_0047a948();
    }
    if ((int)(&g_ProvinceBaseScore)[*(int *)(iVar12 + 0x10) * 0x1e] < 1) goto LAB_004385f2;
    if ((iVar12 == *(int *)((int)fVar5 + 4)) && (FUN_0047a948(), iVar12 == *(int *)((int)fVar5 + 4))
       ) {
      FUN_0047a948();
    }
    ppiVar10 = AdjacencyList_FilterByUnitType
                         ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar12 + 0x10) * 0x24),
                          (ushort *)(iVar12 + 0x14));
    local_128 = 0.0;
    piStack_10c = (int *)*ppiVar10[1];
    local_110 = ppiVar10;
    while( true ) {
      piVar14 = piStack_10c;
      ppiVar6 = local_110;
      local_ec = ppiVar10[1];
      if ((local_110 == (int **)0x0) || (local_110 != ppiVar10)) {
        FUN_0047a948();
      }
      if (piVar14 == local_ec) break;
      if (iVar12 == *(int *)((int)local_118 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar12 + 0x18) == param_1) {
LAB_004383e4:
        if (iVar12 == *(int *)((int)local_118 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar12 + 0x18) != param_1) {
          if (ppiVar6 == (int **)0x0) {
            FUN_0047a948();
          }
          if (piVar14 == ppiVar6[1]) {
            FUN_0047a948();
          }
          iVar13 = param_1 * 0x100 + piVar14[3];
          if ((*(int *)(&g_SCOwnership + iVar13 * 8) == 1) &&
             (*(int *)(&DAT_00520cec + iVar13 * 8) == 0)) {
            if (piVar14 == ppiVar6[1]) {
              FUN_0047a948();
            }
            if ((&g_OrderTable)[piVar14[3] * 0x1e] == 2) {
              if (piVar14 == ppiVar6[1]) {
                FUN_0047a948();
              }
              if (iVar12 == *(int *)((int)local_118 + 4)) {
                FUN_0047a948();
              }
              if ((&DAT_00baeda8)[piVar14[3] * 0x1e] == *(int *)(iVar12 + 0x10)) goto LAB_004384a2;
            }
          }
        }
        if (ppiVar6 == (int **)0x0) {
          FUN_0047a948();
        }
        if (piVar14 == ppiVar6[1]) {
          FUN_0047a948();
        }
        local_128 = (float)(&DAT_00baedf4)[piVar14[3] * 0x1e] + local_128;
      }
      else {
        if (ppiVar6 == (int **)0x0) {
          FUN_0047a948();
        }
        if (piVar14 == ppiVar6[1]) {
          FUN_0047a948();
        }
        iVar13 = param_1 * 0x100 + piVar14[3];
        if (((&g_EnemyReachScore)[iVar13 * 2] != 1) || ((&DAT_00535cec)[iVar13 * 2] != 0))
        goto LAB_004383e4;
        if (piVar14 == ppiVar6[1]) {
          FUN_0047a948();
        }
        if ((&g_ProvinceBaseScore)[piVar14[3] * 0x1e] != 0) goto LAB_004383e4;
        local_128 = local_128 + 1.0;
      }
LAB_004384a2:
      FUN_0040f400((int *)&local_110);
    }
    if (NAN(local_128) || 1.0 < local_128 == (local_128 == 1.0)) {
      if (iVar12 == *(int *)((int)local_118 + 4)) {
        FUN_0047a948();
      }
      if (*(int *)(iVar12 + 0x18) == param_1) {
        if ((iVar12 == *(int *)((int)local_118 + 4)) &&
           (FUN_0047a948(), iVar12 == *(int *)((int)local_118 + 4))) {
          FUN_0047a948();
        }
        if ((int)(&DAT_00baeddc)[*(int *)(iVar12 + 0x10) * 0x1e] <=
            (int)(&g_ProvinceBaseScore)[*(int *)(iVar12 + 0x10) * 0x1e]) goto LAB_00438571;
        if (iVar12 == *(int *)((int)local_118 + 4)) {
          FUN_0047a948();
        }
        local_12c = (float *)((1.0 - local_128) * -1.0);
LAB_004385e1:
        (&DAT_00baedf8)[*(int *)(iVar12 + 0x10) * 0x1e] = local_12c;
      }
      else {
LAB_00438571:
        if (iVar12 == *(int *)((int)local_118 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar12 + 0x18) != param_1) {
          if (iVar12 == *(int *)((int)local_118 + 4)) {
            FUN_0047a948();
          }
          if (iVar12 == *(int *)((int)local_118 + 4)) {
            FUN_0047a948();
          }
          if (1 < (int)((&g_ProvinceBaseScore)[*(int *)(iVar12 + 0x10) * 0x1e] +
                       (&DAT_00baedd8)[*(int *)(iVar12 + 0x10) * 0x1e])) {
            if (iVar12 == *(int *)((int)local_118 + 4)) {
              FUN_0047a948();
            }
            local_12c = (float *)(1.0 - local_128);
            goto LAB_004385e1;
          }
        }
      }
LAB_004385f2:
      UnitList_Advance((int *)&local_118);
    }
    else {
      if (iVar12 == *(int *)((int)local_118 + 4)) {
        FUN_0047a948();
      }
      (&DAT_00baedf8)[*(int *)(iVar12 + 0x10) * 0x1e] = 0;
      UnitList_Advance((int *)&local_118);
    }
  }
  iVar13 = *(int *)((int)this + 8);
  local_124 = 0;
  if (0 < *(int *)(iVar13 + 0x2400)) {
    local_12c = (float *)0x0;
    piVar14 = &g_OrderTable;
    do {
      if ((piVar14[9] < 0) || ((piVar14[9] < 1 && (piVar14[8] == 0)))) goto LAB_00438839;
      if (((piVar14[0x13] < 1) &&
          (((((piVar14[0x13] < 0 || (piVar14[0x12] == 0)) && (iVar12 = *piVar14, iVar12 != 1)) &&
            ((iVar12 != 5 && (iVar12 != 4)))) && (iVar12 != 3)))) && (piVar14[0x14] != 5)) {
        if (*(char *)(iVar13 + 3 + (int)local_12c) == '\x01') {
          if ((SPR != *(short *)(iVar13 + 0x244a)) &&
             (((FAL != *(short *)(iVar13 + 0x244a) || ((iVar12 != 2 && (iVar12 != 6)))) ||
              (*(char *)(iVar13 + 3 + piVar14[2] * 0x24) != '\0')))) {
            if ((FAL != *(short *)(iVar13 + 0x244a)) ||
               (((iVar12 != 2 && (iVar12 != 6)) ||
                (iVar12 = piVar14[2], *(char *)(iVar13 + 3 + iVar12 * 0x24) != '\x01'))))
            goto LAB_004387a3;
            if ((piVar14[0xf] == 1) && (0 < (int)(&DAT_00baeddc)[iVar12 * 0x1e])) {
              if (0 < piVar14[0xd]) {
                iVar9 = param_1 * 0x100 + local_124;
                if ((0 < (int)(&DAT_006040ec)[iVar9 * 2]) ||
                   ((-1 < (int)(&DAT_006040ec)[iVar9 * 2] && ((&g_AttackCount)[iVar9 * 2] != 0))))
                goto LAB_00438831;
              }
              iVar9 = param_1 * 0x100 + iVar12;
              if (((int)(&DAT_006040ec)[iVar9 * 2] < 1) &&
                 ((((int)(&DAT_006040ec)[iVar9 * 2] < 0 || ((&g_AttackCount)[iVar9 * 2] == 0)) &&
                  ((int)(&g_ProvinceBaseScore)[iVar12 * 0x1e] <= (int)(&DAT_00baeddc)[iVar12 * 0x1e]
                  )))) goto LAB_004387a3;
            }
          }
          goto LAB_00438831;
        }
LAB_004387a3:
        iVar12 = param_1 * 0x100 + local_124;
        iVar9 = (&DAT_005a48ec)[iVar12 * 2];
        if (-1 < iVar9) {
          if (((iVar9 < 1) && ((uint)(&g_AttackHistory)[iVar12 * 2] < 0xb)) ||
             ((SPR != *(short *)(iVar13 + 0x244a) || ((*piVar14 != 2 && (*piVar14 != 6)))))) {
            if ((iVar9 < 0) ||
               ((((iVar9 < 1 && ((uint)(&g_AttackHistory)[iVar12 * 2] < 0xb)) ||
                 (FAL != *(short *)(iVar13 + 0x244a))) || ((*piVar14 != 2 && (*piVar14 != 6))))))
            goto LAB_00438839;
            if (*(char *)(iVar13 + 3 + piVar14[2] * 0x24) != '\0') {
              iVar13 = param_1 * 0x100 + piVar14[2];
              if (((int)(&DAT_006040ec)[iVar13 * 2] < 0) ||
                 (((int)(&DAT_006040ec)[iVar13 * 2] < 1 && ((&g_AttackCount)[iVar13 * 2] == 0))))
              goto LAB_00438839;
            }
          }
          goto LAB_00438831;
        }
      }
      else {
LAB_00438831:
        piVar14[8] = 0;
        piVar14[9] = 0;
      }
LAB_00438839:
      iVar13 = *(int *)((int)this + 8);
      local_12c = (float *)((int)local_12c + 0x24);
      local_124 = local_124 + 1;
      piVar14 = piVar14 + 0x1e;
    } while (local_124 < *(int *)(iVar13 + 0x2400));
  }
  iVar13 = *(int *)((int)this + 8);
  local_124 = 0;
  if (0 < *(int *)(iVar13 + 0x2400)) {
    local_12c = (float *)0x0;
    puVar15 = (ulonglong *)&DAT_00baee00;
    do {
      local_e8 = (uint)puVar15[-3];
      uStack_e4 = *(uint *)((int)puVar15 + -0x14);
      if (((local_e8 & uStack_e4) == 0xffffffff) || ((int)puVar15[-2] == 5)) {
        local_120 = (float)(longlong)puVar15[-9] * *(float *)(puVar15 + -10) + local_120;
      }
      else {
        local_118 = (float)(longlong)puVar15[-9] * *(float *)(puVar15 + -10) + local_120;
        local_120 = (float)(longlong)puVar15[-3] + local_118;
        if ((*(int *)((int)puVar15 + -0x2c) == 0) || ((int)puVar15[-2] == 2)) {
          local_ec = *(int **)((int)local_12c + 0x18 + iVar13);
          this_00 = (void *)((int)local_12c + 0x14 + iVar13);
          puVar11 = (undefined4 *)GameBoard_GetPowerRec(this_00,&local_d0,&param_1);
          if (((void *)*puVar11 == (void *)0x0) || ((void *)*puVar11 != this_00)) {
            FUN_0047a948();
          }
          if (((int *)puVar11[1] != local_ec) &&
             (FAL == *(short *)(*(int *)((int)this + 8) + 0x244a))) {
            local_120 = local_120 + 100.0;
          }
        }
      }
      iVar13 = (int)puVar15[-0xc];
      local_120 = (float)(longlong)puVar15[-8] + local_120;
      if (iVar13 == 5) {
        uVar19 = PackScoreU64();
        *puVar15 = uVar19;
      }
      iStack_dc = *(int *)((int)puVar15 + 4);
      local_e0 = (int)*puVar15;
      if ((-1 < iStack_dc) && ((0 < iStack_dc || (local_e0 != 0)))) {
        uVar19 = PackScoreU64();
        *puVar15 = uVar19;
        local_120 = (float)(longlong)*puVar15 + local_120;
      }
      if ((iVar13 == 3) || (iVar13 == 4)) {
        local_118 = (float)((&DAT_00baedd8)[(int)puVar15[-0xb] * 0x1e] +
                           (&g_ProvinceBaseScore)[(int)puVar15[-0xb] * 0x1e]);
        uVar19 = PackScoreU64();
        puVar15[-7] = uVar19;
        local_120 = (float)(longlong)puVar15[-7] + local_120;
      }
      if (*(float *)(puVar15 + -10) == 1.0) {
        iVar13 = param_1 * 0x100 + local_124;
        if ((-1 < (int)(&DAT_005a48ec)[iVar13 * 2]) &&
           ((0 < (int)(&DAT_005a48ec)[iVar13 * 2] || (10 < (uint)(&g_AttackHistory)[iVar13 * 2]))))
        {
          iStack_d4 = *(int *)((int)puVar15 + -0x44);
          local_d8 = (int)puVar15[-9];
          if ((-1 < iStack_d4) &&
             ((((0 < iStack_d4 || (local_d8 != 0)) &&
               (*(int *)(&g_SCOwnership + iVar13 * 8) == 0 &&
                *(int *)(&DAT_00520cec + iVar13 * 8) == 0)) &&
              ((0 < *(int *)((int)puVar15 + -0x24) && (0 < *(int *)((int)puVar15 + -0x2c))))))) {
            local_120 = (float)((float10)(longlong)puVar15[-9] * (float10)0.4 + (float10)local_120);
          }
        }
      }
      if (*(float *)(puVar15 + -1) != 0.0) {
        local_120 = *(float *)(puVar15 + -1) * 100.0 + local_120;
      }
      iVar13 = *(int *)((int)this + 8);
      local_12c = (float *)((int)local_12c + 0x24);
      local_124 = local_124 + 1;
      puVar15 = puVar15 + 0xf;
    } while (local_124 < *(int *)(iVar13 + 0x2400));
  }
  uVar19 = PackScoreU64();
  local_44._0_1_ = 1;
  FreeList(local_b0);
  local_44 = (uint)local_44._1_3_ << 8;
  FreeList(local_a0);
  local_44 = 0xffffffff;
  FreeList(local_90);
  ExceptionList = local_4c;
  return uVar19;
}

