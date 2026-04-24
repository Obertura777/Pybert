
undefined4 __thiscall IsLegalMove(void *this,int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_10;
  undefined2 local_c;
  int local_8 [2];
  
  local_c = 0;
  piVar3 = (int *)AdjacencyList_LowerBound
                            ((void *)((int)this + *param_1 * 0x24 + 8),local_8,
                             (ushort *)(param_1 + 1));
  puVar5 = (undefined4 *)*piVar3;
  iVar1 = piVar3[1];
  puVar4 = (undefined4 *)((int)this + *param_1 * 0x24 + 8);
  iVar2 = puVar4[1];
  if ((puVar5 == (undefined4 *)0x0) || (puVar5 != puVar4)) {
    puVar4 = (undefined4 *)FUN_0047a948();
  }
  if (iVar1 != iVar2) {
    if (puVar5 == (undefined4 *)0x0) {
      FUN_0047a948();
    }
    if (iVar1 == puVar5[1]) {
      FUN_0047a948();
    }
    local_10 = param_2;
    local_c = 0;
    puVar5 = SubList_Find((void *)(iVar1 + 0x10),&local_10);
    puVar4 = puVar5;
    if ((void *)(iVar1 + 0x10) == (void *)0x0) {
      puVar4 = (undefined4 *)FUN_0047a948();
    }
    if ((puVar5 != *(undefined4 **)(iVar1 + 0x14)) && (puVar5[3] == param_2)) {
      return CONCAT31((int3)((uint)puVar4 >> 8),1);
    }
  }
  return (uint)puVar4 & 0xffffff00;
}


void __thiscall IsLegalMove_Alt(void *this,void **param_1,int *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  void **ppvVar3;
  void *local_10;
  undefined4 *local_c;
  void *local_8;
  undefined4 *local_4;
  
  puVar2 = SubList_Find(this,param_2);
  local_c = puVar2;
  if (this == (void *)0x0) {
    FUN_0047a948();
  }
  local_10 = this;
  if (((puVar2 == *(undefined4 **)((int)this + 4)) || (*param_2 < (int)puVar2[3])) ||
     ((*param_2 == puVar2[3] && (*(ushort *)(param_2 + 1) < *(ushort *)(puVar2 + 4))))) {
    local_4 = *(undefined4 **)((int)this + 4);
    local_8 = this;
    ppvVar3 = &local_8;
  }
  else {
    ppvVar3 = &local_10;
  }
  pvVar1 = ppvVar3[1];
  *param_1 = *ppvVar3;
  param_1[1] = pvVar1;
  return;
}

