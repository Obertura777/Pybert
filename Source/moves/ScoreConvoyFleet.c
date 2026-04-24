
void __thiscall ScoreConvoyFleet(void *this,undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  int **ppiVar5;
  bool local_8 [8];
  
  ppiVar5 = *(int ***)((int)this + 4);
  local_8[0] = true;
  if (*(char *)((int)ppiVar5[1] + 0x15) == '\0') {
    ppiVar3 = (int **)ppiVar5[1];
    do {
      ppiVar5 = ppiVar3;
      if (*param_2 <= (int)ppiVar5[3]) {
        ppiVar3 = (int **)ppiVar5[2];
      }
      else {
        ppiVar3 = (int **)*ppiVar5;
      }
      local_8[0] = *param_2 > (int)ppiVar5[3];
    } while (*(char *)((int)ppiVar3 + 0x15) == '\0');
  }
  puVar4 = (undefined4 *)FUN_00413ba0(this,(void **)local_8,local_8[0],ppiVar5,param_2);
  uVar1 = *puVar4;
  uVar2 = puVar4[1];
  *(undefined1 *)(param_1 + 2) = 1;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  return;
}

