
uint * ParseDestinationWithCoast(uint *param_1,void *param_2,undefined2 param_3)

{
  uint *puVar1;
  void *this;
  bool bVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  
  this = param_2;
  puVar1 = param_1;
  *(undefined2 *)(param_1 + 1) = 0;
  bVar2 = FUN_004658e0((int)param_2);
  if (bVar2) {
    pbVar3 = (byte *)FUN_004658f0(this,(undefined2 *)&param_1);
    *puVar1 = (uint)*pbVar3;
    *(undefined2 *)(puVar1 + 1) = param_3;
    return puVar1;
  }
  pbVar3 = (byte *)GetListElement(this,&param_3,0);
  *puVar1 = (uint)*pbVar3;
  puVar4 = (undefined2 *)GetListElement(this,&param_3,1);
  *(undefined2 *)(puVar1 + 1) = *puVar4;
  return puVar1;
}

