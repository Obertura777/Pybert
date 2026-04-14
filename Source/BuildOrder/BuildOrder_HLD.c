
void __thiscall BuildOrder_HLD(void *this,int power,int unit_province)

{
  int iVar1;
  int **ppiVar2;
  bool bVar3;
  
  ppiVar2 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),&unit_province);
  iVar1 = unit_province;
  bVar3 = AMY == *(short *)(ppiVar2 + 1);
  BuildOrder_RTO(*(undefined4 *)((int)this + 8));
  (&g_OrderTable)[iVar1 * 0x1e] = 1;
  (&DAT_00baeda8)[iVar1 * 0x1e] = *ppiVar2;
  *(int **)(&DAT_00baedac + iVar1 * 0x3c) = ppiVar2[1];
  (&g_ProvinceBaseScore)[iVar1 * 0x1e] = 1;
  ppiVar2 = OrderedSet_FindOrInsert((void *)((int)this + power * 0xc + 0x4000),ppiVar2);
  (&g_ConvoyChainScore)[iVar1 * 0x1e] = *ppiVar2;
  (&DAT_00baedbc)[iVar1 * 0x1e] = ppiVar2[1];
  if (bVar3) {
    (&DAT_00baee00)[iVar1 * 0x1e] = 0;
    *(undefined4 *)(&DAT_00baee04 + iVar1 * 0x78) = 0;
  }
  RegisterConvoyFleet(this,power,iVar1);
  return;
}

