
void __thiscall
BuildConvoyOrders(void *this,uint param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *army_province;
  int **ppiVar4;
  int iVar5;
  uint uVar6;
  int local_1c;
  uint local_18;
  int **local_14;
  int **local_c;
  int local_8 [2];
  
  ClearConvoyState();
  army_province = param_3;
  *(undefined4 *)((int)this + 0x2a10) = *(undefined4 *)((int)this + (int)param_3 * 0x14 + 0x218);
  piVar1 = (int *)((int)this + ((int)param_3 * 5 + 0x87) * 4);
  *(int *)((int)this + 0x2a14) = *piVar1;
  *(undefined4 *)((int)this + 0x2a18) = *(undefined4 *)((int)this + (int)param_3 * 0x14 + 0x220);
  BuildOrder_CTO(*(void **)((int)this + 8),(int)param_2,param_3,
                 *(int *)((int)this + (int)param_3 * 0x14 + 0x214),
                 (undefined4 *)((int)this + 0x2a10));
  ppiVar4 = ConvoyList_Insert(&DAT_00bb65a0,(int *)&param_3);
  *ppiVar4 = param_2;
  *(undefined4 *)(&DAT_00baedac + (int)param_2 * 0x3c) = param_4;
  (&g_OrderTable)[(int)param_2 * 0x1e] = 6;
  (&DAT_00baeda8)[(int)param_2 * 0x1e] = army_province;
  (&DAT_00baedfc)[(int)param_2 * 0x1e] =
       *(undefined4 *)((int)this + (int)army_province * 0x14 + 0x214);
  (&DAT_00baee08)[(int)param_2 * 0x1e] =
       *(undefined4 *)((int)this + (int)army_province * 0x14 + 0x218);
  (&DAT_00baee0c)[(int)param_2 * 0x1e] = *piVar1;
  (&DAT_00baee10)[(int)param_2 * 0x1e] =
       *(undefined4 *)((int)this + (int)army_province * 0x14 + 0x220);
  (&g_ProvinceBaseScore)[(int)army_province * 0x1e] = 1;
  uVar6 = 0x44b863;
  ppiVar4 = OrderedSet_FindOrInsert((void *)((int)this + param_1 * 0xc + 0x4000),&param_3);
  (&g_ConvoyChainScore)[(int)army_province * 0x1e] = *ppiVar4;
  (&DAT_00baedbc)[(int)army_province * 0x1e] = ppiVar4[1];
  if (0 < *(int *)((int)this + (int)army_province * 0x14 + 0x214)) {
    BuildOrder_CVY(*(void **)((int)this + 8),
                   *(undefined4 *)((int)this + (int)army_province * 0x14 + 0x218),param_2,
                   army_province);
    (&g_OrderTable)[*(int *)((int)this + (int)army_province * 0x14 + 0x218) * 0x1e] = 5;
    (&DAT_00baeda4)[*(int *)((int)this + (int)army_province * 0x14 + 0x218) * 0x1e] = param_2;
    iVar2 = *(int *)((int)this + (int)army_province * 0x14 + 0x218);
    (&DAT_00baeda8)[iVar2 * 0x1e] = army_province;
    *(undefined4 *)(&DAT_00baedac + iVar2 * 0x3c) = param_4;
    (&g_ProvinceBaseScore)[*(int *)((int)this + (int)army_province * 0x14 + 0x218) * 0x1e] = 1;
    iVar2 = *(int *)((int)this + (int)army_province * 0x14 + 0x218);
    iVar5 = param_1 * 0x100 + iVar2;
    uVar3 = *(undefined4 *)(&DAT_0055b0ec + iVar5 * 8);
    (&g_ConvoyChainScore)[iVar2 * 0x1e] = *(undefined4 *)(&g_MaxProvinceScore + iVar5 * 8);
    (&DAT_00baedbc)[iVar2 * 0x1e] = uVar3;
    uVar6 = param_1;
    RegisterConvoyFleet(this,param_1,*(int *)((int)this + (int)army_province * 0x14 + 0x218));
  }
  if (1 < *(int *)((int)this + (int)army_province * 0x14 + 0x214)) {
    BuildOrder_CVY(*(void **)((int)this + 8),*piVar1,param_2,army_province);
    (&g_OrderTable)[*piVar1 * 0x1e] = 5;
    (&DAT_00baeda4)[*piVar1 * 0x1e] = param_2;
    iVar2 = *piVar1;
    (&DAT_00baeda8)[iVar2 * 0x1e] = army_province;
    *(undefined4 *)(&DAT_00baedac + iVar2 * 0x3c) = param_4;
    (&g_ProvinceBaseScore)[*piVar1 * 0x1e] = 1;
    iVar2 = *piVar1;
    iVar5 = param_1 * 0x100 + iVar2;
    uVar3 = *(undefined4 *)(&DAT_0055b0ec + iVar5 * 8);
    (&g_ConvoyChainScore)[iVar2 * 0x1e] = *(undefined4 *)(&g_MaxProvinceScore + iVar5 * 8);
    (&DAT_00baedbc)[iVar2 * 0x1e] = uVar3;
    uVar6 = param_1;
    RegisterConvoyFleet(this,param_1,*piVar1);
  }
  if (2 < *(int *)((int)this + (int)army_province * 0x14 + 0x214)) {
    BuildOrder_CVY(*(void **)((int)this + 8),
                   *(undefined4 *)((int)this + (int)army_province * 0x14 + 0x220),param_2,
                   army_province);
    (&g_OrderTable)[*(int *)((int)this + (int)army_province * 0x14 + 0x220) * 0x1e] = 5;
    (&DAT_00baeda4)[*(int *)((int)this + (int)army_province * 0x14 + 0x220) * 0x1e] = param_2;
    iVar2 = *(int *)((int)this + (int)army_province * 0x14 + 0x220);
    (&DAT_00baeda8)[iVar2 * 0x1e] = army_province;
    *(undefined4 *)(&DAT_00baedac + iVar2 * 0x3c) = param_4;
    (&g_ProvinceBaseScore)[*(int *)((int)this + (int)army_province * 0x14 + 0x220) * 0x1e] = 1;
    iVar2 = *(int *)((int)this + (int)army_province * 0x14 + 0x220);
    iVar5 = param_1 * 0x100 + iVar2;
    uVar3 = *(undefined4 *)(&DAT_0055b0ec + iVar5 * 8);
    (&g_ConvoyChainScore)[iVar2 * 0x1e] = *(undefined4 *)(&g_MaxProvinceScore + iVar5 * 8);
    (&DAT_00baedbc)[iVar2 * 0x1e] = uVar3;
    uVar6 = param_1;
    RegisterConvoyFleet(this,param_1,*(int *)((int)this + (int)army_province * 0x14 + 0x220));
  }
  local_1c = 4;
  do {
    local_14 = (int **)**(undefined4 **)((int)this + 0x4d00);
    local_18 = (int)this + 0x4cfc;
    while( true ) {
      ppiVar4 = local_14;
      local_c = *(int ***)((int)this + 0x4d00);
      if ((local_18 == 0) || (local_18 != (int)this + 0x4cfcU)) {
        FUN_0047a948();
      }
      if (ppiVar4 == local_c) goto LAB_0044bb9b;
      if (local_18 == 0) {
        FUN_0047a948();
      }
      if (ppiVar4 == *(int ***)(local_18 + 4)) {
        FUN_0047a948();
      }
      if (ppiVar4[4] == *(int **)((int)this + (int)army_province * 0x14 + 0x218)) break;
      if (ppiVar4 == *(int ***)(local_18 + 4)) {
        FUN_0047a948();
      }
      if (ppiVar4[4] == (int *)*piVar1) break;
      if (ppiVar4 == *(int ***)(local_18 + 4)) {
        FUN_0047a948();
      }
      if (ppiVar4[4] == *(int **)((int)this + (int)army_province * 0x14 + 0x220)) break;
      FUN_0040f400((int *)&local_18);
    }
    uVar6 = local_18;
    MoveCandidate((void *)((int)this + 0x4cfc),local_8,local_18,ppiVar4);
LAB_0044bb9b:
    local_1c = local_1c + -1;
    if (local_1c == 0) {
      AssignSupportOrder(this,param_1,(int)param_2,army_province,
                         CONCAT22((short)(uVar6 >> 0x10),(undefined2)param_4),(int **)0x1);
      return;
    }
  } while( true );
}

