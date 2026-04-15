
int __fastcall ParseNOWUnit(int param_1)

{
  ushort uVar1;
  bool bVar2;
  byte *pbVar3;
  ushort *puVar4;
  void **ppvVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  short *psVar9;
  int **ppiVar10;
  void *pvVar11;
  byte bVar12;
  int iVar14;
  ushort uVar15;
  undefined4 **ppuVar16;
  ushort local_d4 [2];
  undefined4 *local_d0;
  undefined4 *local_cc;
  int local_c8;
  void *local_c4 [4];
  void *local_b4 [4];
  void *local_a4 [4];
  void *local_94;
  int local_90;
  undefined4 *local_88;
  ushort local_84;
  undefined4 *local_80;
  ushort local_7c;
  undefined4 local_78;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_28 [12];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  undefined4 *puVar13;
  
  puStack_8 = &LAB_0049937d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  local_c8 = -1;
  FUN_00465870(local_b4);
  local_4._0_1_ = 1;
  FUN_004064f0((int)&local_88);
  local_4._0_1_ = 2;
  FUN_00465870(local_a4);
  local_4._0_1_ = 3;
  pbVar3 = (byte *)GetListElement(&stack0x00000004,local_d4,0);
  local_d0 = (undefined4 *)(uint)*pbVar3;
  if (*(int *)(param_1 + 0x2404) <= (int)local_d0) {
    local_c8 = 0;
    goto LAB_00462f91;
  }
  puVar4 = (ushort *)GetListElement(&stack0x00000004,local_d4,1);
  uVar1 = *puVar4;
  ppvVar5 = (void **)GetSubList(&stack0x00000004,local_c4,2);
  local_4._0_1_ = 4;
  AppendList(local_b4,ppvVar5);
  local_4._0_1_ = 3;
  FreeList(local_c4);
  bVar2 = FUN_004658e0((int)local_b4);
  if (bVar2) {
    puVar6 = (undefined2 *)FUN_004658f0(local_b4,(undefined2 *)&local_cc);
    bVar12 = (byte)*puVar6;
    local_d4[0] = uVar1;
LAB_00462d05:
    puVar13 = (undefined4 *)(uint)bVar12;
    if ((int)puVar13 < *(int *)(param_1 + 0x2400)) {
      local_90 = *(int *)(param_1 + 0xc + (int)puVar13 * 0x24);
      pvVar11 = (void *)(param_1 + 8 + (int)puVar13 * 0x24);
      local_cc = (undefined4 *)AdjacencyList_LowerBound(pvVar11,(int *)local_c4,local_d4);
      if (((void *)*local_cc == (void *)0x0) || ((void *)*local_cc != pvVar11)) {
        FUN_0047a948();
      }
      puVar8 = local_d0;
      if (local_cc[1] == local_90) {
        local_c8 = 2;
      }
      else {
        local_84 = local_d4[0];
        local_80 = local_d0;
        local_78 = 0;
        local_34 = 0;
        local_33 = 0;
        local_32 = 0;
        local_31 = 0;
        local_30 = 0;
        local_2f = 0;
        local_2e = 0;
        local_2d = 1;
        local_2c = 0;
        local_88 = puVar13;
        local_7c = uVar1;
        uVar7 = FUN_00465930((int)&stack0x00000004);
        if (uVar7 == 5) {
          puVar8 = GetSubList(&stack0x00000004,local_c4,3);
          local_4._0_1_ = 5;
          psVar9 = (short *)FUN_004658f0(puVar8,(undefined2 *)&local_cc);
          local_d4[0] = CONCAT11(local_d4[0]._1_1_,DAT_004c77cc != *psVar9);
          local_4._0_1_ = 3;
          FreeList(local_c4);
          if ((char)local_d4[0] == '\0') {
            ppvVar5 = (void **)GetSubList(&stack0x00000004,local_c4,4);
            local_4._0_1_ = 6;
            AppendList(local_a4,ppvVar5);
            local_4._0_1_ = 3;
            FreeList(local_c4);
            FUN_004028a0((int)local_28);
            iVar14 = 0;
            uVar7 = FUN_00465930((int)local_a4);
            if (0 < (int)uVar7) {
              do {
                local_cc = (undefined4 *)&stack0xffffff14;
                local_4._0_1_ = 7;
                uVar15 = uVar1;
                puVar8 = GetSubList(local_a4,local_1c,iVar14);
                local_4._0_1_ = 9;
                ppiVar10 = (int **)ParseDestinationWithCoast((uint *)local_c4,puVar8,uVar15);
                FUN_00404e10(local_28,&local_94,ppiVar10);
                local_4._0_1_ = 3;
                FreeList(local_1c);
                iVar14 = iVar14 + 1;
                uVar7 = FUN_00465930((int)local_a4);
              } while (iVar14 < (int)uVar7);
            }
          }
          else {
            local_c8 = FUN_00466110(&stack0x00000004,3);
          }
          ppuVar16 = &local_88;
          local_cc = puVar13;
          ppiVar10 = UnitList_FindOrInsert((void *)(param_1 + 0x245c),(int *)&local_cc);
          FUN_0042e120(ppiVar10,ppuVar16);
          if (local_d0 != (undefined4 *)(uint)*(byte *)(param_1 + 0x2424)) goto LAB_00462f91;
          pvVar11 = (void *)(param_1 + 0x24c0);
        }
        else {
          ppuVar16 = &local_88;
          local_d0 = puVar13;
          ppiVar10 = UnitList_FindOrInsert((void *)(param_1 + 0x2450),(int *)&local_d0);
          FUN_0042e120(ppiVar10,ppuVar16);
          if (puVar8 != (undefined4 *)(uint)*(byte *)(param_1 + 0x2424)) goto LAB_00462f91;
          pvVar11 = (void *)(param_1 + 0x24b4);
        }
        local_d0 = puVar13;
        StdMap_FindOrInsert(pvVar11,local_c4,(int *)&local_d0);
      }
      goto LAB_00462f91;
    }
  }
  else if (FLT == uVar1) {
    puVar6 = (undefined2 *)GetListElement(local_b4,(undefined2 *)&local_cc,0);
    bVar12 = (byte)*puVar6;
    puVar4 = (ushort *)GetListElement(local_b4,local_d4,1);
    local_d4[0] = *puVar4;
    goto LAB_00462d05;
  }
  local_c8 = 2;
LAB_00462f91:
  local_4._0_1_ = 2;
  FreeList(local_a4);
  local_4._0_1_ = 1;
  FUN_00406440((int)&local_88);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_b4);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000004);
  ExceptionList = local_c;
  return local_c8;
}

