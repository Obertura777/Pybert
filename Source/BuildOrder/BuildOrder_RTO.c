
uint __fastcall BuildOrder_RTO(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_8 [2];
  
  puVar4 = (undefined4 *)
           OrderedSet_FindOrInsert((void *)(param_1 + 0x2450),local_8,(int *)&stack0x00000004);
  pvVar1 = (void *)*puVar4;
  iVar2 = puVar4[1];
  iVar3 = *(int *)(param_1 + 0x2454);
  if ((pvVar1 == (void *)0x0) || (pvVar1 != (void *)(param_1 + 0x2450))) {
    puVar4 = (undefined4 *)FUN_0047a948();
  }
  if (iVar2 == iVar3) {
    return (uint)puVar4 & 0xffffff00;
  }
  if (pvVar1 == (void *)0x0) {
    puVar4 = (undefined4 *)FUN_0047a948();
  }
  if (iVar2 == *(int *)((int)pvVar1 + 4)) {
    puVar4 = (undefined4 *)FUN_0047a948();
  }
  *(undefined4 *)(iVar2 + 0x20) = 1;
  return CONCAT31((int3)((uint)puVar4 >> 8),1);
}

