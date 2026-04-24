
void __thiscall BuildAllianceMsg(void *this,undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  bool local_8 [8];
  
  ppiVar4 = *(int ***)((int)this + 4);
  local_8[0] = true;
  if (*(char *)((int)ppiVar4[1] + 0x15) == '\0') {
    ppiVar2 = (int **)ppiVar4[1];
    do {
      ppiVar4 = ppiVar2;
      local_8[0] = *param_2 < (int)ppiVar4[3];
      if (local_8[0]) {
        ppiVar2 = (int **)*ppiVar4;
      }
      else {
        ppiVar2 = (int **)ppiVar4[2];
      }
    } while (*(char *)((int)ppiVar2 + 0x15) == '\0');
  }
  puVar3 = (undefined4 *)FUN_00414a10(this,(void **)local_8,local_8[0],ppiVar4,param_2);
  uVar1 = puVar3[1];
  *param_1 = *puVar3;
  param_1[1] = uVar1;
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}

