
void __thiscall BuildOrderSpec(void *this,undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  int **ppiVar5;
  char local_8 [8];
  
  ppiVar5 = *(int ***)((int)this + 4);
  local_8[0] = '\x01';
  if (*(char *)((int)ppiVar5[1] + 0x21) == '\0') {
    ppiVar3 = (int **)ppiVar5[1];
    do {
      ppiVar5 = ppiVar3;
      if (((int)param_2[1] < (int)ppiVar5[5]) ||
         (((int)param_2[1] <= (int)ppiVar5[5] && ((int *)*param_2 <= ppiVar5[4])))) {
        ppiVar3 = (int **)ppiVar5[2];
        local_8[0] = '\0';
      }
      else {
        ppiVar3 = (int **)*ppiVar5;
        local_8[0] = '\x01';
      }
    } while (*(char *)((int)ppiVar3 + 0x21) == '\0');
  }
  puVar4 = (undefined4 *)FUN_004151b0(this,(void **)local_8,local_8[0],ppiVar5,param_2);
  uVar1 = *puVar4;
  uVar2 = puVar4[1];
  *(undefined1 *)(param_1 + 2) = 1;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  return;
}

