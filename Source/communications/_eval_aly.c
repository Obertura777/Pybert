
undefined2 * __thiscall _eval_aly(void *this,undefined2 *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int **ppiVar5;
  uint uVar6;
  uint **ppuVar7;
  void **ppvVar8;
  byte *pbVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  byte in_stack_00000018;
  undefined1 local_8c [4];
  int **local_88;
  undefined4 local_84;
  undefined1 local_80 [4];
  int **local_7c;
  undefined4 local_78;
  uint local_74;
  undefined2 local_6e;
  uint local_6c;
  int local_68;
  void *local_64;
  void *local_60 [2];
  void *local_58 [3];
  uint *local_4c [4];
  void *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004958b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar16 = 0;
  local_4 = 1;
  *param_1 = 0;
  local_64 = this;
  FUN_00465870(local_3c);
  local_4._0_1_ = 2;
  FUN_00465870(local_1c);
  local_4._0_1_ = 3;
  FUN_00465870(local_2c);
  local_4._0_1_ = 4;
  local_7c = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_7c + 0x11) = 1;
  local_7c[1] = (int *)local_7c;
  *local_7c = (int *)local_7c;
  local_7c[2] = (int *)local_7c;
  local_78 = 0;
  local_4._0_1_ = 5;
  local_88 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_88 + 0x11) = 1;
  local_88[1] = (int *)local_88;
  *local_88 = (int *)local_88;
  local_88[2] = (int *)local_88;
  local_84 = 0;
  uVar14 = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 6;
  bVar1 = false;
  bVar2 = false;
  bVar4 = true;
  bVar3 = true;
  uVar6 = FUN_00465930((int)&stack0x00000008);
  if (uVar6 == 4) {
    ppuVar7 = FUN_00466480(&stack0x0000001c,local_4c,&stack0x00000018);
    local_4._0_1_ = 7;
    AppendList(local_2c,ppuVar7);
    local_4._0_1_ = 6;
    FreeList(local_4c);
    ppvVar8 = (void **)GetSubList(&stack0x00000008,local_4c,1);
    local_4._0_1_ = 8;
    AppendList(local_3c,ppvVar8);
    local_4._0_1_ = 6;
    FreeList(local_4c);
    ppvVar8 = (void **)GetSubList(&stack0x00000008,local_4c,3);
    local_4._0_1_ = 9;
    AppendList(local_1c,ppvVar8);
    local_4._0_1_ = 6;
    FreeList(local_4c);
    uVar6 = FUN_00465930((int)local_2c);
    local_6c = FUN_00465930((int)local_3c);
    local_60[0] = (void *)FUN_00465930((int)local_1c);
    FUN_00401950(local_7c[1]);
    local_7c[1] = (int *)local_7c;
    local_78 = 0;
    *local_7c = (int *)local_7c;
    local_7c[2] = (int *)local_7c;
    FUN_00401950(local_88[1]);
    local_88[1] = (int *)local_88;
    local_84 = 0;
    *local_88 = (int *)local_88;
    local_88[2] = (int *)local_88;
    if (0 < (int)uVar6) {
      do {
        pbVar9 = (byte *)GetListElement(local_2c,&local_6e,iVar16);
        local_74 = (uint)*pbVar9;
        StdMap_FindOrInsert(local_8c,local_58,(int *)&local_74);
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)uVar6);
    }
    iVar16 = 0;
    if (0 < (int)local_6c) {
      do {
        pbVar9 = (byte *)GetListElement(local_3c,&local_6e,iVar16);
        uVar6 = (uint)*pbVar9;
        local_74 = uVar6;
        StdMap_FindOrInsert(local_80,local_4c,(int *)&local_74);
        ppiVar5 = local_88;
        if (uVar6 == uVar14) {
          bVar1 = true;
        }
        if (uVar6 == in_stack_00000018) {
          bVar2 = true;
        }
        piVar10 = (int *)GameBoard_GetPowerRec(local_8c,(int *)local_58,(int *)&local_74);
        if (((undefined1 *)*piVar10 == (undefined1 *)0x0) || ((undefined1 *)*piVar10 != local_8c)) {
          FUN_0047a948();
        }
        if ((int **)piVar10[1] == ppiVar5) {
          bVar3 = false;
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)local_6c);
    }
    local_58[0] = (void *)0x0;
    pvVar15 = local_60[0];
    if (0 < (int)local_6c) {
      do {
        pbVar9 = (byte *)GetListElement(local_3c,&local_6e,(int)local_58[0]);
        uVar6 = (uint)*pbVar9;
        if ((uVar6 != uVar14) && (local_68 = 0, 0 < (int)pvVar15)) {
          do {
            pbVar9 = (byte *)GetListElement(local_1c,(undefined2 *)&local_74,local_68);
            uVar11 = (uint)*pbVar9;
            if (DAT_00baed5f == '\x01') {
              if (((((&DAT_004cf568)[uVar6 * 2] != 0 || (&DAT_004cf56c)[uVar6 * 2] != 0) ||
                   ((int)(&DAT_00634e90)[uVar14 * 0x15 + uVar6] < 0)) ||
                  ((((&DAT_004cf568)[uVar11 * 2] != 1 || ((&DAT_004cf56c)[uVar11 * 2] != 0)) &&
                   (-1 < (int)(&DAT_00634e90)[uVar14 * 0x15 + uVar11])))) &&
                 ((int)(&g_AllyMatrix)[uVar6 * 0x15 + uVar11] < 1)) {
                iVar16 = uVar14 * 0x15 + uVar6;
                if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2]) &&
                   ((0 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2] ||
                    (2 < (uint)(&g_AllyTrustScore)[iVar16 * 2])))) {
                  iVar12 = uVar6 * 0x15 + uVar14;
                  if (((-1 < (int)(&g_AllyTrustScore_Hi)[iVar12 * 2]) &&
                      (((0 < (int)(&g_AllyTrustScore_Hi)[iVar12 * 2] ||
                        ((&g_AllyTrustScore)[iVar12 * 2] != 0)) &&
                       (((&DAT_004cf568)[uVar6 * 2] != 1 || ((&DAT_004cf56c)[uVar6 * 2] != 0))))))
                     && ((((-1 < (int)(&DAT_00634e90)[iVar16] && ((&DAT_00b9fdd8)[uVar6] == uVar11))
                          && ((int)(&DAT_006340c0)[iVar16] < 4)) &&
                         ((DAT_004c6bc4 != uVar11 && ((int)(&DAT_00633ec0)[uVar14] < 2)))))) {
                    iVar16 = *(int *)(*(int *)((int)local_64 + 8) + 0x2404);
                    if (0 < iVar16) {
                      piVar13 = &DAT_006340c0 + uVar14 * 0x15;
                      piVar10 = &g_AllyMatrix + uVar11 * 0x15;
                      do {
                        if ((*piVar10 == 1) && (*piVar13 < 4)) {
                          bVar4 = false;
                        }
                        piVar10 = piVar10 + 1;
                        piVar13 = piVar13 + 1;
                        iVar16 = iVar16 + -1;
                      } while (iVar16 != 0);
                    }
                    goto LAB_0041e8c1;
                  }
                }
LAB_0041e8bc:
                bVar4 = false;
              }
            }
            else if ((((&DAT_004cf568)[uVar11 * 2] != 1) || ((&DAT_004cf56c)[uVar11 * 2] != 0)) &&
                    ((int)(&g_AllyMatrix)[uVar6 * 0x15 + uVar11] < 1)) {
              iVar16 = uVar6 * 0x15 + uVar14;
              if ((((-1 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2]) &&
                   ((0 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2] ||
                    ((&g_AllyTrustScore)[iVar16 * 2] != 0)))) &&
                  (((&DAT_004cf568)[uVar6 * 2] != 1 || ((&DAT_004cf56c)[uVar6 * 2] != 0)))) &&
                 (iVar16 = uVar14 * 0x15 + uVar6, -1 < (int)(&DAT_00634e90)[iVar16])) {
                iVar12 = (&g_AllyTrustScore_Hi)[iVar16 * 2];
                if ((((0 < iVar12) || ((-1 < iVar12 && (2 < (uint)(&g_AllyTrustScore)[iVar16 * 2])))
                     ) || ((DAT_00baed68 == '\x01' &&
                           ((-1 < iVar12 && ((0 < iVar12 || ((&g_AllyTrustScore)[iVar16 * 2] != 0)))
                            ))))) && ((&DAT_00b9fdd8)[uVar6] == uVar11)) {
                  if (((DAT_00baed68 != '\x01') || ((&DAT_004d5480)[uVar11 * 2] != 1)) ||
                     ((&DAT_004d5484)[uVar11 * 2] != 0)) {
                    if (((&DAT_00b9fdd8)[uVar6] != uVar11) || (3 < (int)(&DAT_006340c0)[iVar16]))
                    goto LAB_0041e8bc;
                    if ((DAT_00baed68 == '\0') &&
                       (iVar16 = *(int *)(*(int *)((int)local_64 + 8) + 0x2404), 0 < iVar16)) {
                      piVar13 = &DAT_006340c0 + uVar14 * 0x15;
                      piVar10 = &g_AllyMatrix + uVar11 * 0x15;
                      do {
                        if ((*piVar10 == 1) && (*piVar13 < 4)) {
                          bVar4 = false;
                        }
                        piVar10 = piVar10 + 1;
                        piVar13 = piVar13 + 1;
                        iVar16 = iVar16 + -1;
                      } while (iVar16 != 0);
                    }
                  }
                  goto LAB_0041e8c1;
                }
              }
              goto LAB_0041e8bc;
            }
LAB_0041e8c1:
            local_68 = local_68 + 1;
            pvVar15 = local_60[0];
          } while (local_68 < (int)local_60[0]);
        }
        local_58[0] = (void *)((int)local_58[0] + 1);
      } while ((int)local_58[0] < (int)local_6c);
    }
    if ((((bVar1) && (bVar2)) && (bVar3)) && (bVar4)) {
      *param_1 = YES;
      goto LAB_0041e92f;
    }
  }
  *param_1 = REJ;
LAB_0041e92f:
  local_4._0_1_ = 5;
  SerializeOrders(local_8c,local_60,local_8c,(int **)*local_88,local_8c,local_88);
  _free(local_88);
  local_88 = (int **)0x0;
  local_84 = 0;
  local_4._0_1_ = 4;
  SerializeOrders(local_80,local_60,local_80,(int **)*local_7c,local_80,local_7c);
  _free(local_7c);
  local_7c = (int **)0x0;
  local_78 = 0;
  local_4._0_1_ = 3;
  FreeList(local_2c);
  local_4._0_1_ = 2;
  FreeList(local_1c);
  local_4._0_1_ = 1;
  FreeList(local_3c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

