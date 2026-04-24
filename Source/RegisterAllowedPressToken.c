
void __thiscall RegisterAllowedPressToken(void *this,void **param_1,ushort *param_2)

{
  void *pvVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  bool local_c;
  void *local_8;
  int **local_4;
  
  ppiVar4 = *(int ***)((int)this + 4);
  local_c = true;
  if (*(char *)((int)ppiVar4[1] + 0xf) == '\0') {
    ppiVar2 = (int **)ppiVar4[1];
    do {
      ppiVar4 = ppiVar2;
      local_c = *param_2 < *(ushort *)(ppiVar4 + 3);
      if (local_c) {
        ppiVar2 = (int **)*ppiVar4;
      }
      else {
        ppiVar2 = (int **)ppiVar4[2];
      }
    } while (*(char *)((int)ppiVar2 + 0xf) == '\0');
  }
  local_8 = this;
  local_4 = ppiVar4;
  if (local_c) {
    if (ppiVar4 == (int **)**(int **)((int)this + 4)) {
      local_c = true;
      goto LAB_00418f2e;
    }
    FUN_0040f4f0((int *)&local_8);
  }
  if (*param_2 <= *(ushort *)(local_4 + 3)) {
    *param_1 = local_8;
    param_1[1] = local_4;
    *(undefined1 *)(param_1 + 2) = 0;
    return;
  }
LAB_00418f2e:
  puVar3 = (undefined4 *)FUN_00412ac0(this,&local_8,local_c,ppiVar4,param_2);
  pvVar1 = (void *)puVar3[1];
  *param_1 = (void *)*puVar3;
  param_1[1] = pvVar1;
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}

