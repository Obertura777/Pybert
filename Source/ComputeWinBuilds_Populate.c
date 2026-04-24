
void __thiscall ComputeWinBuilds_Populate(void *this,int param_1)

{
  byte bVar1;
  int iVar2;
  int **ppiVar3;
  int **ppiVar4;
  _AFX_AYGSHELL_STATE *p_Var5;
  ushort *puVar6;
  undefined1 local_a4 [4];
  int **local_a0;
  undefined4 local_9c;
  int local_98;
  int **local_94;
  undefined4 local_90;
  undefined1 *local_8c;
  int **local_88;
  undefined1 *local_84;
  int **local_80;
  undefined1 *local_7c;
  int **local_78;
  undefined1 *local_74;
  int **local_70;
  undefined1 *local_6c;
  int **local_68;
  undefined1 *local_64;
  int **local_60;
  undefined1 *local_5c;
  int **local_58;
  undefined1 *local_54;
  int **local_50;
  undefined1 *local_4c;
  int **local_48;
  undefined1 *local_44;
  int **local_40;
  int **local_3c;
  undefined1 *local_38;
  int **local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  undefined2 local_24;
  int **local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_004976cb;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_a0 = (int **)FUN_004103b0();
  *(undefined1 *)((int)local_a0 + 0x21) = 1;
  local_a0[1] = (int *)local_a0;
  *local_a0 = (int *)local_a0;
  local_a0[2] = (int *)local_a0;
  local_9c = 0;
  local_c = 0;
  local_98 = *(int *)((int)this + 8);
  bVar1 = *(byte *)(local_98 + 0x2424);
  local_94 = (int **)**(int **)(local_98 + 0x24b8);
  local_98 = local_98 + 0x24b4;
  while( true ) {
    iVar2 = local_98;
    local_70 = *(int ***)(*(int *)((int)this + 8) + 0x24b8);
    if ((local_98 == 0) || (local_98 != *(int *)((int)this + 8) + 0x24b4)) {
      FUN_0047a948();
    }
    if (local_94 == local_70) break;
    if (iVar2 == 0) {
      FUN_0047a948();
    }
    if (local_94 == *(int ***)(iVar2 + 4)) {
      FUN_0047a948();
    }
    ppiVar3 = UnitList_FindOrInsert
                        ((void *)(*(int *)((int)this + 8) + 0x2450),(int *)(local_94 + 3));
    ppiVar4 = OrderedSet_FindOrInsert((void *)((int)this + (uint)bVar1 * 0xc + 0x4000),ppiVar3);
    local_28 = *ppiVar3;
    local_30 = *ppiVar4 + 0x32;
    local_2c = (int)ppiVar4[1] + (uint)((int *)0xffffff37 < *ppiVar4);
    local_24 = *(undefined2 *)(ppiVar3 + 1);
    BuildOrderSpec(local_a4,&local_90,(uint *)&local_30);
    TreeIterator_Advance(&local_98);
  }
  if (0 < param_1) {
    local_98 = param_1;
    do {
      ppiVar3 = local_a0;
      DAT_00baed34 = DAT_00baed34 + 1;
      local_60 = local_a0;
      local_64 = local_a4;
      FUN_0040f660((int *)&local_64);
      if (local_64 == (undefined1 *)0x0) {
        FUN_0047a948();
      }
      if (local_60 == *(int ***)(local_64 + 4)) {
        FUN_0047a948();
      }
      ppiVar4 = local_60 + 7;
      p_Var5 = _AfxAygshellState();
      local_3c = GetProvinceToken(p_Var5,(ushort *)ppiVar4);
      if (local_3c[6] < (int *)0x10) {
        local_3c = local_3c + 1;
      }
      else {
        local_3c = (int **)local_3c[1];
      }
      local_80 = ppiVar3;
      local_84 = local_a4;
      FUN_0040f660((int *)&local_84);
      if (local_84 == (undefined1 *)0x0) {
        FUN_0047a948();
      }
      if (local_80 == *(int ***)(local_84 + 4)) {
        FUN_0047a948();
      }
      puVar6 = (ushort *)(*(int *)((int)this + 8) + (int)local_80[6] * 0x24);
      p_Var5 = _AfxAygshellState();
      GetProvinceToken(p_Var5,puVar6);
      ClearConvoyState();
      local_90 = 0;
      local_88 = ppiVar3;
      local_8c = local_a4;
      FUN_0040f660((int *)&local_8c);
      local_1c = (int **)*local_a0;
      if ((local_8c == (undefined1 *)0x0) || (local_8c != local_a4)) {
        FUN_0047a948();
      }
      if (local_88 != local_1c) {
        local_68 = ppiVar3;
        local_6c = local_a4;
        FUN_0040f660((int *)&local_6c);
        if (local_6c == (undefined1 *)0x0) {
          FUN_0047a948();
        }
        if (local_68 == *(int ***)(local_6c + 4)) {
          FUN_0047a948();
        }
        if (local_68[4] != (int *)0x0 || local_68[5] != (int *)0x0) {
          local_50 = ppiVar3;
          local_54 = local_a4;
          FUN_0040f660((int *)&local_54);
          if (local_54 == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (local_50 == *(int ***)(local_54 + 4)) {
            FUN_0047a948();
          }
          local_58 = ppiVar3;
          local_5c = local_a4;
          FUN_0040f660((int *)&local_5c);
          if (local_5c == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (local_58 == *(int ***)(local_5c + 4)) {
            FUN_0047a948();
          }
          local_38 = local_8c;
          local_34 = local_88;
          FUN_0040f660((int *)&local_38);
          if (local_38 == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (local_34 == *(int ***)(local_38 + 4)) {
            FUN_0047a948();
          }
          local_4c = local_8c;
          local_48 = local_88;
          FUN_0040f660((int *)&local_4c);
          if (local_4c == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (local_48 == *(int ***)(local_4c + 4)) {
            FUN_0047a948();
          }
          local_40 = ppiVar3;
          local_44 = local_a4;
          FUN_0040f660((int *)&local_44);
          if (local_44 == (undefined1 *)0x0) {
            FUN_0047a948();
          }
          if (local_40 == *(int ***)(local_44 + 4)) {
            FUN_0047a948();
          }
        }
      }
      local_78 = ppiVar3;
      local_7c = local_a4;
      FUN_0040f660((int *)&local_7c);
      if (local_7c == (undefined1 *)0x0) {
        FUN_0047a948();
      }
      if (local_78 == *(int ***)(local_7c + 4)) {
        FUN_0047a948();
      }
      FUN_00461010(*(undefined4 *)((int)this + 8),local_78[6],local_78[6]);
      local_70 = ppiVar3;
      local_74 = local_a4;
      FUN_0040f660((int *)&local_74);
      RemoveOrderCandidate(local_a4,(int *)&local_30,(int)local_74,local_70);
      local_98 = local_98 + -1;
    } while (local_98 != 0);
  }
  local_c = 0xffffffff;
  FUN_004150e0(local_a4,&local_30,local_a4,(int **)*local_a0,local_a4,local_a0);
  _free(local_a0);
  ExceptionList = local_14;
  return;
}

