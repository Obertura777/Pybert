
void __thiscall
BuildOrder_MTO(void *this,uint power,int *src_province,int *dst_province,undefined4 coast)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int **ppiVar4;
  int **ppiVar5;
  bool bVar6;
  uint uVar7;
  
  ClearConvoyState();
  ppiVar5 = &src_province;
  ppiVar4 = UnitList_FindOrInsert((void *)(*(int *)((int)this + 8) + 0x2450),(int *)ppiVar5);
  uVar3 = coast;
  piVar2 = dst_province;
  piVar1 = src_province;
  bVar6 = AMY == *(short *)(ppiVar4 + 1);
  BuildOrder_CTO_Ring(*(void **)((int)this + 8),src_province,dst_province,
                      CONCAT22((short)((uint)ppiVar5 >> 0x10),(short)coast));
  ppiVar5 = ConvoyList_Insert(&DAT_00bb65a0,(int *)&dst_province);
  *ppiVar5 = piVar1;
  (&g_OrderTable)[(int)piVar1 * 0x1e] = 2;
  (&DAT_00baeda8)[(int)piVar1 * 0x1e] = piVar2;
  *(undefined4 *)(&DAT_00baedac + (int)piVar1 * 0x3c) = uVar3;
  (&g_ProvinceBaseScore)[(int)piVar2 * 0x1e] = 1;
  ppiVar5 = OrderedSet_FindOrInsert((void *)((int)this + power * 0xc + 0x4000),&dst_province);
  (&g_ConvoyChainScore)[(int)piVar2 * 0x1e] = *ppiVar5;
  (&DAT_00baedbc)[(int)piVar2 * 0x1e] = ppiVar5[1];
  (&DAT_00baede4)[(int)piVar2 * 0x1e] =
       (&g_MoveHistoryMatrix)[(int)(piVar2 + (int)(piVar1 + power * 0x40) * 0x40)];
  if ((bVar6) && ((&DAT_00baedf0)[(int)piVar1 * 0x1e] != 5)) {
    (&DAT_00baee00)[(int)piVar2 * 0x1e] = 0;
    *(undefined4 *)(&DAT_00baee04 + (int)piVar2 * 0x78) = 0;
  }
  uVar7 = power;
  RegisterConvoyFleet(this,power,(int)piVar2);
  src_province = (int *)&stack0xffffffd8;
  AssignSupportOrder(this,power,(int)piVar1,piVar2,
                     CONCAT22((short)(uVar7 >> 0x10),(undefined2)coast),(int **)0x0);
  return;
}

