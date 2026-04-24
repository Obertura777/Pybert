
void __thiscall InsertCandidateRecord(void *this,void **param_1,void **param_2)

{
  char cVar1;
  int **ppiVar2;
  void *pvVar3;
  int **ppiVar4;
  uint uVar5;
  undefined4 *puVar6;
  int **ppiVar7;
  char local_c;
  void *local_8;
  int **local_4;
  
  ppiVar2 = (int **)(*(int ***)((int)this + 4))[1];
  cVar1 = *(char *)((int)ppiVar2 + 0x629);
  local_c = '\x01';
  ppiVar4 = *(int ***)((int)this + 4);
  while (cVar1 == '\0') {
    uVar5 = FUN_00465cf0(param_2,(int *)(ppiVar2 + 3));
    local_c = (char)uVar5;
    if (local_c == '\0') {
      ppiVar7 = (int **)ppiVar2[2];
    }
    else {
      ppiVar7 = (int **)*ppiVar2;
    }
    ppiVar4 = ppiVar2;
    ppiVar2 = ppiVar7;
    cVar1 = *(char *)((int)ppiVar7 + 0x629);
  }
  local_8 = this;
  local_4 = ppiVar4;
  if (local_c != '\0') {
    if (ppiVar4 == (int **)**(int **)((int)this + 4)) {
      puVar6 = (undefined4 *)FUN_0044d4b0(this,&local_8,'\x01',ppiVar4,param_2);
      pvVar3 = (void *)*puVar6;
      param_1[1] = (void *)puVar6[1];
      *(undefined1 *)(param_1 + 2) = 1;
      *param_1 = pvVar3;
      return;
    }
    FUN_0040f1c0((int *)&local_8);
  }
  ppiVar2 = local_4;
  uVar5 = FUN_00465cf0(local_4 + 3,(int *)param_2);
  if ((char)uVar5 == '\0') {
    param_1[1] = ppiVar2;
    *(undefined1 *)(param_1 + 2) = 0;
    *param_1 = local_8;
    return;
  }
  puVar6 = (undefined4 *)FUN_0044d4b0(this,&local_8,local_c,ppiVar4,param_2);
  pvVar3 = (void *)*puVar6;
  param_1[1] = (void *)puVar6[1];
  *(undefined1 *)(param_1 + 2) = 1;
  *param_1 = pvVar3;
  return;
}

