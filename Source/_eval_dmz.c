
undefined2 * __thiscall _eval_dmz(void *this,undefined2 *param_1)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  int **ppiVar8;
  uint **ppuVar9;
  void **ppvVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  undefined2 local_80;
  undefined2 local_7e;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined *local_60;
  undefined4 *local_5c;
  uint *local_58 [4];
  undefined1 local_48 [4];
  int **local_44;
  undefined4 local_40;
  void *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004959e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar16 = 0;
  local_4 = 1;
  *param_1 = 0;
  FUN_00465870(local_1c);
  local_4._0_1_ = 2;
  FUN_00465870(local_2c);
  local_4._0_1_ = 3;
  FUN_00465870(local_3c);
  local_4._0_1_ = 4;
  local_44 = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_44 + 0x11) = 1;
  local_44[1] = (int *)local_44;
  *local_44 = (int *)local_44;
  local_44[2] = (int *)local_44;
  local_40 = 0;
  uVar15 = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 5;
  bVar3 = false;
  bVar2 = true;
  local_64 = uVar15;
  ppuVar9 = FUN_00466480(&stack0x0000001c,local_58,&stack0x00000018);
  local_4._0_1_ = 6;
  AppendList(local_3c,ppuVar9);
  local_4._0_1_ = 5;
  FreeList(local_58);
  ppvVar10 = (void **)GetSubList(&stack0x00000008,local_58,1);
  local_4._0_1_ = 7;
  AppendList(local_1c,ppvVar10);
  local_4._0_1_ = 5;
  FreeList(local_58);
  ppvVar10 = (void **)GetSubList(&stack0x00000008,local_58,2);
  local_4._0_1_ = 8;
  AppendList(local_2c,ppvVar10);
  local_4 = CONCAT31(local_4._1_3_,5);
  FreeList(local_58);
  local_6c = FUN_00465930((int)local_3c);
  uVar11 = FUN_00465930((int)local_1c);
  local_74 = FUN_00465930((int)local_2c);
  FUN_00401950(local_44[1]);
  local_44[1] = (int *)local_44;
  local_40 = 0;
  *local_44 = (int *)local_44;
  local_44[2] = (int *)local_44;
  if (0 < (int)uVar11) {
    do {
      pbVar12 = (byte *)GetListElement(local_1c,&local_80,iVar16);
      bVar1 = *pbVar12;
      local_70 = (uint)bVar1;
      StdMap_FindOrInsert(local_48,local_58,(int *)&local_70);
      if (bVar1 == uVar15) {
        bVar3 = true;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < (int)uVar11);
  }
  local_70 = 0;
  if (0 < (int)local_6c) {
    do {
      uVar11 = local_70;
      pbVar12 = (byte *)GetListElement(local_3c,&local_80,local_70);
      local_78 = (uint)*pbVar12;
      if (local_78 == uVar15) {
LAB_0041f33f:
        if (((bVar2) && (local_78 != uVar15)) && (local_7c = 0, 0 < (int)local_74)) {
          do {
            pbVar12 = (byte *)GetListElement(local_2c,&local_7e,local_7c);
            local_68 = (uint)*pbVar12;
            local_5c = (undefined4 *)*DAT_00bb6f20;
            bVar4 = false;
            local_60 = &g_OrderList;
            while( true ) {
              puVar7 = local_5c;
              puVar6 = local_60;
              puVar5 = DAT_00bb6f20;
              if ((local_60 == (undefined *)0x0) || (local_60 != &g_OrderList)) {
                FUN_0047a948();
              }
              if (puVar7 == puVar5) break;
              if (puVar6 == (undefined *)0x0) {
                FUN_0047a948();
              }
              if (puVar7 == *(undefined4 **)(puVar6 + 4)) {
                FUN_0047a948();
              }
              if (puVar7[6] == local_68) {
                if (puVar7 == *(undefined4 **)(puVar6 + 4)) {
                  FUN_0047a948();
                }
                if (puVar7[5] != local_78) goto LAB_0041f45c;
                bVar4 = true;
                if (puVar7 == *(undefined4 **)(puVar6 + 4)) {
                  FUN_0047a948();
                }
                if ((*(char *)((int)puVar7 + 0x1d) == '\0') && (bVar3)) {
                  bVar4 = false;
                }
                if (puVar7 == *(undefined4 **)(puVar6 + 4)) {
                  FUN_0047a948();
                }
                ppiVar8 = local_44;
                if (*(char *)(puVar7 + 7) != '\x01') goto LAB_0041f45c;
                piVar14 = (int *)GameBoard_GetPowerRec(local_48,(int *)local_58,(int *)&local_78);
                if (((undefined1 *)*piVar14 == (undefined1 *)0x0) ||
                   ((undefined1 *)*piVar14 != local_48)) {
                  FUN_0047a948();
                }
                if ((int **)piVar14[1] != ppiVar8) goto LAB_0041f45c;
                bVar4 = false;
                std_Tree_IteratorIncrement((int *)&local_60);
              }
              else {
LAB_0041f45c:
                if (bVar4) break;
                std_Tree_IteratorIncrement((int *)&local_60);
              }
            }
            if (!bVar4) {
              bVar2 = false;
            }
            local_7c = local_7c + 1;
            uVar15 = local_64;
            uVar11 = local_70;
          } while (local_7c < (int)local_74);
        }
      }
      else {
        iVar16 = uVar15 * 0x15 + local_78;
        if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2]) &&
           ((0 < (int)(&g_AllyTrustScore_Hi)[iVar16 * 2] ||
            (2 < (uint)(&g_AllyTrustScore)[iVar16 * 2])))) {
          iVar13 = local_78 * 0x15 + uVar15;
          if (((-1 < (int)(&g_AllyTrustScore_Hi)[iVar13 * 2]) &&
              ((((0 < (int)(&g_AllyTrustScore_Hi)[iVar13 * 2] ||
                 ((&g_AllyTrustScore)[iVar13 * 2] != 0)) &&
                (((&DAT_004cf568)[local_78 * 2] != 1 || ((&DAT_004cf56c)[local_78 * 2] != 0)))) &&
               (-1 < (int)(&DAT_00634e90)[iVar16])))) &&
             (((DAT_00baed68 == '\0' || (0 < (int)(&DAT_004d5484)[local_78 * 2])) ||
              ((-1 < (int)(&DAT_004d5484)[local_78 * 2] && (1 < (uint)(&DAT_004d5480)[local_78 * 2])
               ))))) goto LAB_0041f33f;
        }
        bVar2 = false;
      }
      local_70 = uVar11 + 1;
    } while ((int)local_70 < (int)local_6c);
    if (!bVar2) {
      *param_1 = REJ;
      goto LAB_0041f4d8;
    }
  }
  *param_1 = YES;
LAB_0041f4d8:
  local_4._0_1_ = 4;
  SerializeOrders(local_48,local_58,local_48,(int **)*local_44,local_48,local_44);
  _free(local_44);
  local_44 = (int **)0x0;
  local_40 = 0;
  local_4._0_1_ = 3;
  FreeList(local_3c);
  local_4._0_1_ = 2;
  FreeList(local_2c);
  local_4._0_1_ = 1;
  FreeList(local_1c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000008);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x0000001c);
  ExceptionList = local_c;
  return param_1;
}

