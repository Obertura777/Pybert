
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __thiscall _eval_not_dmz(void *this,undefined2 *param_1)

{
  undefined *puVar1;
  undefined *this_00;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int **ppiVar5;
  undefined2 uVar6;
  uint **ppuVar7;
  void **ppvVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  byte in_stack_00000018;
  uint local_d0;
  undefined1 local_cc [4];
  int **local_c8;
  undefined4 local_c4;
  uint local_c0;
  uint local_bc;
  int local_b8;
  undefined2 local_b2;
  uint local_b0;
  uint local_ac;
  void *local_a8;
  uint local_a4;
  uint *local_a0 [4];
  uint local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  void *local_7c [4];
  void *local_6c [4];
  void *local_5c [5];
  int local_48;
  int local_40;
  int local_3c [2];
  int local_34 [2];
  int local_2c [2];
  int local_24 [2];
  int local_1c [2];
  int local_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495a6f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar15 = 0;
  local_4 = 1;
  *param_1 = 0;
  local_a8 = this;
  FUN_00465870(local_5c);
  local_4._0_1_ = 2;
  FUN_00465870(local_6c);
  local_4._0_1_ = 3;
  FUN_00465870(local_7c);
  local_4._0_1_ = 4;
  local_c8 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_c8 + 0x11) = 1;
  local_c8[1] = (int *)local_c8;
  *local_c8 = (int *)local_c8;
  local_c8[2] = (int *)local_c8;
  local_c4 = 0;
  local_bc = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 5;
  bVar3 = true;
  ppuVar7 = FUN_00466480(&stack0x0000001c,local_a0,&stack0x00000018);
  local_4._0_1_ = 6;
  AppendList(local_7c,ppuVar7);
  local_4._0_1_ = 5;
  FreeList(local_a0);
  bVar4 = true;
  ppuVar7 = FUN_00466480(&stack0x0000001c,local_a0,&stack0x00000018);
  local_4._0_1_ = 7;
  AppendList(local_7c,ppuVar7);
  local_4._0_1_ = 5;
  FreeList(local_a0);
  ppvVar8 = (void **)GetSubList(&stack0x00000008,local_a0,1);
  local_4._0_1_ = 8;
  AppendList(local_5c,ppvVar8);
  local_4._0_1_ = 5;
  FreeList(local_a0);
  ppvVar8 = (void **)GetSubList(&stack0x00000008,local_a0,2);
  local_4._0_1_ = 9;
  AppendList(local_6c,ppvVar8);
  local_4 = CONCAT31(local_4._1_3_,5);
  FreeList(local_a0);
  uVar9 = FUN_00465930((int)local_7c);
  local_a4 = uVar9;
  uVar10 = FUN_00465930((int)local_5c);
  local_90 = uVar10;
  local_ac = FUN_00465930((int)local_6c);
  if (0 < (int)uVar10) {
    do {
      pbVar11 = (byte *)GetListElement(local_5c,&local_b2,iVar15);
      local_b0 = (uint)*pbVar11;
      StdMap_FindOrInsert(local_cc,local_a0,(int *)&local_b0);
      iVar15 = iVar15 + 1;
    } while (iVar15 < (int)uVar10);
  }
  local_c0 = 0;
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
    local_b8 = 0;
    do {
      iVar15 = local_b8;
      iVar14 = 0;
      if (0 < (int)local_ac) {
        puVar1 = &DAT_00bb7028 + local_b8;
        do {
          pbVar11 = (byte *)GetListElement(local_6c,&local_b2,iVar14);
          local_d0 = (uint)*pbVar11;
          iVar2 = *(int *)((int)&DAT_00bb702c + iVar15);
          puVar12 = (undefined4 *)GameBoard_GetPowerRec(puVar1,&local_84,(int *)&local_d0);
          if (((undefined *)*puVar12 == (undefined *)0x0) || ((undefined *)*puVar12 != puVar1)) {
            FUN_0047a948();
          }
          if (puVar12[1] == iVar2) {
            this_00 = &DAT_00bb6f28 + local_b8;
            if (this_00 == (undefined *)0x0) {
              FUN_0047a948();
            }
            puVar12 = (undefined4 *)GameBoard_GetPowerRec(this_00,&local_8c,(int *)&local_d0);
            if (((undefined *)*puVar12 == (undefined *)0x0) || ((undefined *)*puVar12 != this_00)) {
              FUN_0047a948();
            }
          }
          iVar14 = iVar14 + 1;
          uVar10 = local_90;
          this = local_a8;
        } while (iVar14 < (int)local_ac);
      }
      local_b8 = local_b8 + 0xc;
      local_c0 = local_c0 + 1;
      uVar9 = local_a4;
    } while ((int)local_c0 < *(int *)(*(int *)((int)this + 8) + 0x2404));
  }
  local_b0 = 0;
  if (0 < (int)uVar9) {
    do {
      uVar10 = local_b0;
      pbVar11 = (byte *)GetListElement(local_7c,&local_b2,local_b0);
      local_c0 = (uint)*pbVar11;
      local_a8 = (void *)0x0;
      uVar9 = local_c0;
      if (0 < (int)local_ac) {
        do {
          pbVar11 = (byte *)GetListElement(local_6c,(undefined2 *)&local_b8,(int)local_a8);
          local_d0 = (uint)*pbVar11;
          uVar10 = uVar9;
          if (uVar9 != local_bc) {
            if (uVar9 == in_stack_00000018) {
              local_40 = (&DAT_00bb702c)[uVar9 * 3];
              puVar12 = (undefined4 *)
                        GameBoard_GetPowerRec(&DAT_00bb7028 + uVar9 * 0xc,local_3c,(int *)&local_d0)
              ;
              if (((undefined *)*puVar12 == (undefined *)0x0) ||
                 ((undefined *)*puVar12 != &DAT_00bb7028 + uVar9 * 0xc)) {
                FUN_0047a948();
              }
              if (puVar12[1] == local_40) {
                iVar15 = (&DAT_00bb6f2c)[uVar9 * 3];
                puVar12 = (undefined4 *)
                          GameBoard_GetPowerRec
                                    (&DAT_00bb6f28 + uVar9 * 0xc,local_34,(int *)&local_d0);
                if (((undefined *)*puVar12 == (undefined *)0x0) ||
                   ((undefined *)*puVar12 != &DAT_00bb6f28 + uVar9 * 0xc)) {
                  FUN_0047a948();
                }
                if (puVar12[1] == iVar15) {
                  bVar3 = false;
                }
              }
            }
            iVar15 = uVar9 * 0xc;
            local_48 = (&DAT_00bb702c)[uVar9 * 3];
            puVar1 = &DAT_00bb7028 + iVar15;
            puVar12 = (undefined4 *)GameBoard_GetPowerRec(puVar1,local_24,(int *)&local_d0);
            if (((undefined *)*puVar12 == (undefined *)0x0) || ((undefined *)*puVar12 != puVar1)) {
              FUN_0047a948();
            }
            if (puVar12[1] != local_48) {
              local_88 = (&DAT_00bb6f2c)[uVar9 * 3];
              puVar12 = (undefined4 *)
                        GameBoard_GetPowerRec(&DAT_00bb6f28 + iVar15,local_14,(int *)&local_d0);
              if (((undefined *)*puVar12 == (undefined *)0x0) ||
                 ((undefined *)*puVar12 != &DAT_00bb6f28 + iVar15)) {
                FUN_0047a948();
              }
              ppiVar5 = local_c8;
              uVar10 = local_c0;
              if (puVar12[1] != local_88) {
                piVar13 = (int *)GameBoard_GetPowerRec(local_cc,local_1c,(int *)&local_c0);
                if (((undefined1 *)*piVar13 == (undefined1 *)0x0) ||
                   ((undefined1 *)*piVar13 != local_cc)) {
                  FUN_0047a948();
                }
                uVar10 = local_c0;
                if ((int **)piVar13[1] == ppiVar5) {
                  bVar4 = false;
                }
              }
            }
            local_80 = (&DAT_00bb702c)[uVar9 * 3];
            puVar12 = (undefined4 *)GameBoard_GetPowerRec(puVar1,local_2c,(int *)&local_d0);
            if (((undefined *)*puVar12 == (undefined *)0x0) || ((undefined *)*puVar12 != puVar1)) {
              FUN_0047a948();
            }
            if (puVar12[1] != local_80) {
              iVar14 = (&DAT_00bb6f2c)[uVar9 * 3];
              puVar12 = (undefined4 *)
                        GameBoard_GetPowerRec
                                  (&DAT_00bb6f28 + iVar15,(int *)local_a0,(int *)&local_d0);
              if (((undefined *)*puVar12 == (undefined *)0x0) ||
                 ((undefined *)*puVar12 != &DAT_00bb6f28 + iVar15)) {
                FUN_0047a948();
              }
              if ((puVar12[1] == iVar14) && (_g_NearEndGameFactor < 3.0)) {
                bVar4 = false;
              }
            }
          }
          local_a8 = (void *)((int)local_a8 + 1);
          uVar9 = uVar10;
          uVar10 = local_b0;
        } while ((int)local_a8 < (int)local_ac);
      }
      local_b0 = uVar10 + 1;
      uVar10 = local_90;
      uVar9 = local_a4;
    } while ((int)local_b0 < (int)local_a4);
  }
  ppiVar5 = local_c8;
  iVar15 = local_bc * 0x15 + (uint)in_stack_00000018;
  if (((int)(&g_AllyTrustScore_Hi)[iVar15 * 2] < 1) &&
     ((((int)(&g_AllyTrustScore_Hi)[iVar15 * 2] < 0 || ((uint)(&g_AllyTrustScore)[iVar15 * 2] < 2))
      && (2 < (int)uVar9)))) {
    bVar4 = false;
  }
  if (bVar3) goto LAB_0041fbd5;
  uVar6 = BWX;
  if ((int)uVar9 < 3) {
    if (1 < (int)uVar10) {
      local_bc = (uint)in_stack_00000018;
      piVar13 = (int *)GameBoard_GetPowerRec(local_cc,(int *)local_a0,(int *)&local_bc);
      if (((undefined1 *)*piVar13 == (undefined1 *)0x0) || ((undefined1 *)*piVar13 != local_cc)) {
        FUN_0047a948();
      }
      if ((int **)piVar13[1] != ppiVar5) goto LAB_0041fb83;
LAB_0041fbc2:
      *param_1 = BWX;
      goto LAB_0041fbff;
    }
LAB_0041fb83:
    ppiVar5 = local_c8;
    if (uVar10 == 1) {
      local_bc = (uint)in_stack_00000018;
      piVar13 = (int *)GameBoard_GetPowerRec(local_cc,(int *)local_a0,(int *)&local_bc);
      if (((undefined1 *)*piVar13 == (undefined1 *)0x0) || ((undefined1 *)*piVar13 != local_cc)) {
        FUN_0047a948();
      }
      if ((int **)piVar13[1] == ppiVar5) goto LAB_0041fbc2;
    }
LAB_0041fbd5:
    uVar6 = REJ;
    if (bVar4) {
      *param_1 = YES;
      goto LAB_0041fbff;
    }
  }
  *param_1 = uVar6;
LAB_0041fbff:
  local_4._0_1_ = 4;
  SerializeOrders(local_cc,local_a0,local_cc,(int **)*local_c8,local_cc,local_c8);
  _free(local_c8);
  local_c8 = (int **)0x0;
  local_c4 = 0;
  local_4._0_1_ = 3;
  FreeList(local_7c);
  local_4._0_1_ = 2;
  FreeList(local_6c);
  local_4._0_1_ = 1;
  FreeList(local_5c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

