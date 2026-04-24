
uint __thiscall
BuildOrder_CVY(void *this,undefined4 fleet_province,undefined4 army_unit_type,
              undefined4 army_province)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_8 [2];
  
  puVar4 = (undefined4 *)
           OrderedSet_FindOrInsert((void *)((int)this + 0x2450),local_8,&fleet_province);
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
  *(undefined4 *)(iVar2 + 0x20) = 5;
  if (iVar2 == *(int *)((int)pvVar1 + 4)) {
    FUN_0047a948();
  }
  *(undefined4 *)(iVar2 + 0x2c) = army_unit_type;
  if (iVar2 == *(int *)((int)pvVar1 + 4)) {
    FUN_0047a948();
  }
  *(undefined4 *)(iVar2 + 0x30) = army_province;
  return CONCAT31((int3)((uint)army_province >> 8),1);
}

