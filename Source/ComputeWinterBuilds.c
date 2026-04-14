
void __fastcall ComputeWinterBuilds(int param_1)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int **ppiVar10;
  int iVar11;
  float10 fVar12;
  float local_4c;
  float local_48;
  int *local_3c;
  int local_38;
  undefined4 *local_30;
  int local_2c;
  undefined *local_28;
  undefined4 *local_24;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  undefined4 *local_14;
  int local_c;
  
  piVar5 = (int *)(uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  iVar6 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2400)) {
    do {
      (&DAT_005408e8)[iVar6] = 0;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(iVar6 * 4 + 0x5404e4) = 0;
    } while (iVar6 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
  }
  local_24 = (undefined4 *)*DAT_00bc1e20;
  local_38 = -1;
  local_28 = &DAT_00bc1e1c;
  do {
    puVar8 = local_24;
    puVar4 = local_28;
    puVar7 = DAT_00bc1e20;
    if ((local_28 == (undefined *)0x0) || (local_28 != &DAT_00bc1e1c)) {
      FUN_0047a948();
    }
    if (puVar8 == puVar7) {
      if (local_38 != -1) {
        (&DAT_005408e8)[local_38] = local_4c;
        (&DAT_005404e8)[local_38] = local_48;
      }
      return;
    }
    if (puVar4 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar8 == *(undefined4 **)(puVar4 + 4)) {
      FUN_0047a948();
    }
    if (puVar8[3] != local_38) {
      if (local_38 != -1) {
        (&DAT_005408e8)[local_38] = local_4c;
        (&DAT_005404e8)[local_38] = local_48;
      }
      if (puVar8 == *(undefined4 **)(puVar4 + 4)) {
        FUN_0047a948();
      }
      local_38 = puVar8[3];
      local_4c = 0.0;
      local_48 = 0.0;
    }
    if (*(char *)(*(int *)(param_1 + 8) + 3 + local_38 * 0x24) != '\0') {
      uVar2 = *(ushort *)(*(int *)(param_1 + 8) + local_38 * 0x24 + 0x20);
      if ((char)(uVar2 >> 8) == 'A') {
        local_3c = (int *)(uVar2 & 0xff);
      }
      else {
        local_3c = (int *)0x14;
      }
      if (puVar8 == *(undefined4 **)(puVar4 + 4)) {
        FUN_0047a948();
      }
      local_2c = *(int *)puVar8[6];
      local_30 = puVar8 + 5;
      while( true ) {
        iVar6 = local_2c;
        puVar7 = local_30;
        if (puVar8 == *(undefined4 **)(local_28 + 4)) {
          FUN_0047a948();
        }
        iVar11 = puVar8[6];
        if ((puVar7 == (undefined4 *)0x0) || (puVar7 != puVar8 + 5)) {
          FUN_0047a948();
        }
        if (iVar6 == iVar11) break;
        iVar11 = *(int *)(param_1 + 8);
        local_c = *(int *)(iVar11 + 0x2478);
        if (puVar7 == (undefined4 *)0x0) {
          FUN_0047a948();
        }
        if (iVar6 == puVar7[1]) {
          FUN_0047a948();
        }
        iVar3 = *(int *)(param_1 + 8);
        local_1c = *(undefined4 **)(iVar3 + 0x2478);
        piVar1 = (int *)(iVar6 + 0x10);
        if (*(char *)((int)local_1c[1] + 0x19) == '\0') {
          puVar7 = (undefined4 *)local_1c[1];
          do {
            if (((int)puVar7[3] < *piVar1) ||
               ((puVar7[3] == *piVar1 && (*(ushort *)(puVar7 + 4) < *(ushort *)(iVar6 + 0x14))))) {
              puVar8 = (undefined4 *)puVar7[2];
            }
            else {
              puVar8 = (undefined4 *)*puVar7;
              local_1c = puVar7;
            }
            puVar7 = puVar8;
          } while (*(char *)((int)puVar8 + 0x19) == '\0');
        }
        local_20 = iVar3 + 0x2474;
        if (((local_1c == *(undefined4 **)(iVar3 + 0x2478)) || (*piVar1 < (int)local_1c[3])) ||
           ((*piVar1 == local_1c[3] && (*(ushort *)(iVar6 + 0x14) < *(ushort *)(local_1c + 4))))) {
          local_14 = *(undefined4 **)(iVar3 + 0x2478);
          local_18 = iVar3 + 0x2474;
          piVar9 = &local_18;
        }
        else {
          piVar9 = &local_20;
        }
        iVar3 = piVar9[1];
        if ((*piVar9 == 0) || (*piVar9 != iVar11 + 0x2474)) {
          FUN_0047a948();
        }
        if (iVar3 != local_c) {
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          fVar12 = (float10)*(double *)(iVar6 + 0x20);
          if ((float10)30.0 < fVar12) {
            fVar12 = (float10)30.0;
          }
          local_4c = (float)((float10)10000.0 / fVar12 + (float10)local_4c);
        }
        if (iVar6 == local_30[1]) {
          FUN_0047a948();
        }
        iVar11 = (int)piVar5 * 0x100;
        if ((*(int *)(&g_SCOwnership + (*piVar1 + iVar11) * 8) == 1) &&
           (*(int *)(&DAT_00520cec + (*piVar1 + iVar11) * 8) == 0)) {
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          ppiVar10 = UnitList_FindOrInsert((void *)(*(int *)(param_1 + 8) + 0x2450),piVar1);
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          if (*(short *)(iVar6 + 0x14) == *(short *)(ppiVar10 + 1)) {
            if (iVar6 == local_30[1]) {
              FUN_0047a948();
            }
            local_4c = (float)((float10)10000.0 / (float10)*(double *)(iVar6 + 0x20) +
                              (float10)local_4c);
          }
        }
        if (iVar6 == local_30[1]) {
          FUN_0047a948();
        }
        if ((*(int *)(&DAT_005164e8 + (*piVar1 + iVar11) * 8) == 1) &&
           (*(int *)(&DAT_005164ec + (*piVar1 + iVar11) * 8) == 0)) {
LAB_00445f2e:
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          ppiVar10 = UnitList_FindOrInsert((void *)(*(int *)(param_1 + 8) + 0x2450),piVar1);
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          if (*(short *)(iVar6 + 0x14) == *(short *)(ppiVar10 + 1)) {
            if ((ppiVar10[2] == local_3c) || ((local_3c == (int *)0x14 && (ppiVar10[2] != piVar5))))
            {
              if (iVar6 == local_30[1]) {
                FUN_0047a948();
              }
              local_48 = (float)((float10)10000.0 / (float10)*(double *)(iVar6 + 0x20) +
                                (float10)local_48);
            }
            if (local_3c == piVar5) {
              if (iVar6 == local_30[1]) {
                FUN_0047a948();
              }
              if ((*(int *)(&DAT_0050bce8 + (*piVar1 + iVar11) * 8) != 1) ||
                 (*(int *)(&DAT_0050bcec + (*piVar1 + iVar11) * 8) != 0)) {
                if (iVar6 == local_30[1]) {
                  FUN_0047a948();
                }
                if ((*(int *)(&DAT_004f6ce8 + (*piVar1 + iVar11) * 8) != 1) ||
                   (*(int *)(&DAT_004f6cec + (*piVar1 + iVar11) * 8) != 0)) goto LAB_0044603b;
              }
              iVar11 = (int)piVar5 * 0x15 + (int)ppiVar10[2];
              if (((int)(&g_AllyTrustScore_Hi)[iVar11 * 2] < 1) &&
                 (((int)(&g_AllyTrustScore_Hi)[iVar11 * 2] < 0 ||
                  ((uint)(&g_AllyTrustScore)[iVar11 * 2] < 3)))) {
                if (iVar6 == local_30[1]) {
                  FUN_0047a948();
                }
                local_48 = (float)((float10)10000.0 / (float10)*(double *)(iVar6 + 0x20) +
                                  (float10)local_48);
              }
            }
          }
        }
        else {
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          if ((*(int *)(&DAT_0050bce8 + (*piVar1 + iVar11) * 8) == 1) &&
             (*(int *)(&DAT_0050bcec + (*piVar1 + iVar11) * 8) == 0)) goto LAB_00445f2e;
          if (iVar6 == local_30[1]) {
            FUN_0047a948();
          }
          if ((*(int *)(&DAT_004f6ce8 + (*piVar1 + iVar11) * 8) == 1) &&
             (*(int *)(&DAT_004f6cec + (*piVar1 + iVar11) * 8) == 0)) goto LAB_00445f2e;
        }
LAB_0044603b:
        FUN_0040f7f0((int *)&local_30);
        puVar8 = local_24;
      }
    }
    std_Tree_IteratorIncrement((int *)&local_28);
  } while( true );
}

