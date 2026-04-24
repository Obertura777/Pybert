
uint __thiscall
BuildOrder_CTO(void *this,int src_province,undefined4 dst_province,int via_count,
              undefined4 *via_array_ptr)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int local_8 [2];
  
  puVar4 = (undefined4 *)OrderedSet_FindOrInsert((void *)((int)this + 0x2450),local_8,&src_province)
  ;
  pvVar1 = (void *)*puVar4;
  iVar2 = puVar4[1];
  iVar3 = *(int *)((int)this + 0x2454);
  if ((pvVar1 == (void *)0x0) || (pvVar1 != (void *)((int)this + 0x2450))) {
    puVar4 = (undefined4 *)FUN_0047a948();
  }
  if (iVar2 != iVar3) {
    if (pvVar1 == (void *)0x0) {
      FUN_0047a948();
    }
    if (iVar2 == *(int *)((int)pvVar1 + 4)) {
      FUN_0047a948();
    }
    *(undefined4 *)(iVar2 + 0x20) = 6;
    if (iVar2 == *(int *)((int)pvVar1 + 4)) {
      FUN_0047a948();
    }
    *(undefined4 *)(iVar2 + 0x24) = dst_province;
    if (iVar2 == *(int *)((int)pvVar1 + 4)) {
      FUN_0047a948();
    }
    *(undefined2 *)(iVar2 + 0x28) = AMY;
    if (iVar2 == *(int *)((int)pvVar1 + 4)) {
      FUN_0047a948();
    }
    FUN_00401850(iVar2 + 0x34);
    piVar6 = (int *)via_count;
    if (0 < via_count) {
      src_province = via_count;
      puVar4 = via_array_ptr;
      do {
        if (iVar2 == *(int *)((int)pvVar1 + 4)) {
          FUN_0047a948();
        }
        iVar3 = *(int *)(iVar2 + 0x38);
        iVar5 = FUN_00401b00(iVar3,*(undefined4 *)(iVar3 + 4),puVar4);
        FUN_00403ec0((void *)(iVar2 + 0x34),1);
        *(int *)(iVar3 + 4) = iVar5;
        piVar6 = *(int **)(iVar5 + 4);
        puVar4 = puVar4 + 1;
        src_province = src_province + -1;
        *piVar6 = iVar5;
      } while (src_province != 0);
    }
    return CONCAT31((int3)((uint)piVar6 >> 8),1);
  }
  return (uint)puVar4 & 0xffffff00;
}


uint __thiscall
BuildOrder_CTO_Ring(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_8 [2];
  
  puVar4 = (undefined4 *)OrderedSet_FindOrInsert((void *)((int)this + 0x2450),local_8,&param_1);
  pvVar1 = (void *)*puVar4;
  iVar2 = puVar4[1];
  iVar3 = *(int *)((int)this + 0x2454);
  if ((pvVar1 == (void *)0x0) || (pvVar1 != (void *)((int)this + 0x2450))) {
    puVar4 = (undefined4 *)FUN_0047a948();
  }
  if (iVar2 == iVar3) {
    return (uint)puVar4 & 0xffffff00;
  }
  if (pvVar1 == (void *)0x0) {
    FUN_0047a948();
  }
  if (iVar2 == *(int *)((int)pvVar1 + 4)) {
    FUN_0047a948();
  }
  *(undefined4 *)(iVar2 + 0x20) = 2;
  if (iVar2 == *(int *)((int)pvVar1 + 4)) {
    FUN_0047a948();
  }
  *(undefined4 *)(iVar2 + 0x28) = param_3;
  *(undefined4 *)(iVar2 + 0x24) = param_2;
  return CONCAT31((int3)((uint)param_3 >> 8),1);
}

