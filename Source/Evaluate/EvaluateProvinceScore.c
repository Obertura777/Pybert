
/* WARNING: Removing unreachable block (ram,0x00433f62) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __thiscall EvaluateProvinceScore(void *this,int province,int power)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int **this_00;
  int iVar5;
  int iVar6;
  int *piVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  longlong lVar9;
  undefined8 local_38;
  int local_30;
  int local_2c;
  int local_28;
  undefined2 local_24;
  int local_1c;
  int local_18;
  int local_10 [2];
  int local_8 [2];
  
  iVar5 = (int)this + province * 0xc + 0x2a1c;
  local_2c = **(int **)((int)this + province * 0xc + 0x2a20);
  local_38 = 0;
  local_24 = 0;
  local_30 = iVar5;
  while( true ) {
    iVar6 = local_2c;
    iVar1 = local_30;
    iVar4 = *(int *)(iVar5 + 4);
    if ((local_30 == 0) || (local_30 != iVar5)) {
      FUN_0047a948();
    }
    if (iVar6 == iVar4) break;
    iVar4 = *(int *)((int)this + 8);
    local_1c = *(int *)(iVar4 + 0x2454);
    if (iVar1 == 0) {
      FUN_0047a948();
    }
    if (iVar6 == *(int *)(iVar1 + 4)) {
      FUN_0047a948();
    }
    piVar7 = (int *)(iVar6 + 0xc);
    piVar3 = (int *)OrderedSet_FindOrInsert
                              ((void *)(*(int *)((int)this + 8) + 0x2450),local_10,piVar7);
    if ((*piVar3 == 0) || (*piVar3 != iVar4 + 0x2450)) {
      FUN_0047a948();
    }
    if (piVar3[1] != local_1c) {
      if (local_2c == *(int *)(local_30 + 4)) {
        FUN_0047a948();
      }
      iVar4 = *piVar7 + power * 0x100;
      if ((*(int *)(&DAT_004f6ce8 + iVar4 * 8) != 1) || (*(int *)(&DAT_004f6cec + iVar4 * 8) != 0))
      {
        if (local_2c == *(int *)(local_30 + 4)) {
          FUN_0047a948();
        }
        iVar4 = *piVar7 + power * 0x100;
        if ((*(int *)(&DAT_0050bce8 + iVar4 * 8) != 1) || (*(int *)(&DAT_0050bcec + iVar4 * 8) != 0)
           ) goto LAB_00433efb;
      }
      if (local_2c == *(int *)(local_30 + 4)) {
        FUN_0047a948();
      }
      piVar3 = (int *)OrderedSet_FindOrInsert
                                ((void *)(*(int *)((int)this + 8) + 0x2450),local_8,piVar7);
      iVar4 = *piVar3;
      iVar1 = piVar3[1];
      local_18 = iVar4;
      if (iVar4 == 0) {
        FUN_0047a948();
      }
      if (iVar1 == *(int *)(iVar4 + 4)) {
        FUN_0047a948();
      }
      iVar6 = (int)(&curr_sc_cnt)[*(int *)(iVar1 + 0x18)] >> 0x1f;
      if (((int)local_38._4_4_ <= iVar6) &&
         (((int)local_38._4_4_ < iVar6 ||
          ((uint)local_38 < (uint)(&curr_sc_cnt)[*(int *)(iVar1 + 0x18)])))) {
        if (iVar1 == *(int *)(iVar4 + 4)) {
          FUN_0047a948();
        }
        if (*(int *)(iVar1 + 0x18) != power) {
          if (iVar1 == *(int *)(iVar4 + 4)) {
            FUN_0047a948();
          }
          if (local_2c == *(int *)(local_30 + 4)) {
            FUN_0047a948();
          }
          this_00 = AdjacencyList_FilterByUnitType
                              ((void *)(*(int *)((int)this + 8) + 8 + *piVar7 * 0x24),
                               (ushort *)(iVar1 + 0x14));
          piVar3 = this_00[1];
          local_28 = province;
          local_24 = 0;
          piVar7 = SubList_Find(this_00,&local_28);
          if ((piVar7 != piVar3) && (piVar7[3] == province)) {
            if (iVar1 == *(int *)(local_18 + 4)) {
              FUN_0047a948();
            }
            local_38 = (longlong)(int)(&curr_sc_cnt)[*(int *)(iVar1 + 0x18)];
          }
        }
      }
    }
LAB_00433efb:
    TreeIterator_Advance(&local_30);
  }
  fVar8 = (float10)_g_NearEndGameFactor;
  if ((local_38 < 0) || (((int)local_38._4_4_ < 1 && ((uint)local_38 == 0)))) {
LAB_00433fe6:
    if ((uint)local_38 == 0 && local_38._4_4_ == 0) {
      iVar5 = power * 0x100 + province;
      if ((-1 < (int)(&DAT_005850ec)[iVar5 * 2]) &&
         ((0 < (int)(&DAT_005850ec)[iVar5 * 2] || ((&DAT_005850e8)[iVar5 * 2] != 0)))) {
        if ((&DAT_0058f8e8)[iVar5 * 2] == 0 && (&DAT_0058f8ec)[iVar5 * 2] == 0) {
          if (fVar8 <= (float10)6.0) {
            local_38 = 0x32;
          }
          else {
            local_38 = 100;
          }
        }
        else {
          local_38 = 0xf;
          if (fVar8 <= (float10)6.0) {
            local_38 = 2;
          }
        }
      }
    }
  }
  else {
    uVar2 = *(uint *)((int)this + 0x3ffc);
    lVar9 = __allmul((uint)local_38,local_38._4_4_,100,0);
    lVar9 = __alldiv((uint)lVar9,(uint)((ulonglong)lVar9 >> 0x20),uVar2,(int)uVar2 >> 0x1f);
    if (0x32 < lVar9) {
      iVar5 = power * 0x100 + province;
      iVar4 = (&DAT_0052b4ec)[iVar5 * 2] + (uint)(0xfffffffe < (uint)(&DAT_0052b4e8)[iVar5 * 2]);
      if (((int)(&DAT_0058f8ec)[iVar5 * 2] <= iVar4) &&
         (((int)(&DAT_0058f8ec)[iVar5 * 2] < iVar4 ||
          ((uint)(&DAT_0058f8e8)[iVar5 * 2] <= (&DAT_0052b4e8)[iVar5 * 2] + 1)))) {
        lVar9 = __allmul((uint)lVar9 - 0x32,
                         (int)((ulonglong)lVar9 >> 0x20) - (uint)((uint)lVar9 < 0x32),0x96,0);
        local_38 = __alldiv((uint)lVar9,(uint)((ulonglong)lVar9 >> 0x20),100,0);
        local_38 = local_38 + 0x32;
        fVar8 = extraout_ST0_00;
        goto LAB_00433fe6;
      }
    }
    local_38 = 0x32;
    fVar8 = extraout_ST0;
  }
  if ((DAT_00baed68 == '\x01') && (fVar8 < (float10)3.0)) {
    if ((uint)local_38 == 0 && local_38._4_4_ == 0) {
      iVar5 = power * 0x100 + province;
      if ((-1 < (int)(&DAT_0057a8ec)[iVar5 * 2]) &&
         ((0 < (int)(&DAT_0057a8ec)[iVar5 * 2] || ((&DAT_0057a8e8)[iVar5 * 2] != 0)))) {
        return 2;
      }
    }
  }
  return local_38;
}

