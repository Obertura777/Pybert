
int ** __thiscall g_BuildCandidateList(void *this,int **param_1)

{
  int **ppiVar1;
  void **ppvVar2;
  void *local_3c [2];
  void *local_34 [2];
  undefined1 local_2c [4];
  int **local_28;
  undefined4 local_24;
  int *local_20;
  undefined2 local_1c;
  undefined1 local_18 [4];
  int **local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004971c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_3c[0] = this;
  ppiVar1 = (int **)FUN_0040eee0(this,(int *)param_1);
  if (this == (void *)0x0) {
    FUN_0047a948();
  }
  if (((ppiVar1 == *(int ***)((int)this + 4)) || ((int)*param_1 < (int)ppiVar1[3])) ||
     ((*param_1 == ppiVar1[3] && (*(ushort *)(param_1 + 1) < *(ushort *)(ppiVar1 + 4))))) {
    local_28 = (int **)FUN_00410370();
    *(undefined1 *)((int)local_28 + 0x39) = 1;
    local_28[1] = (int *)local_28;
    *local_28 = (int *)local_28;
    local_28[2] = (int *)local_28;
    local_24 = 0;
    local_20 = *param_1;
    local_1c = *(undefined2 *)(param_1 + 1);
    local_4 = 0;
    FUN_00422460(local_18,(int)local_2c);
    local_4._0_1_ = 1;
    ppvVar2 = FUN_00430b90(local_3c[0],local_34,this,ppiVar1,&local_20);
    this = *ppvVar2;
    ppiVar1 = ppvVar2[1];
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0041aa20(local_18,local_3c,local_18,(int **)*local_14,local_18,local_14);
    _free(local_14);
    local_14 = (int **)0x0;
    local_10 = 0;
    local_4 = 0xffffffff;
    FUN_0041aa20(local_2c,local_3c,local_2c,(int **)*local_28,local_2c,local_28);
    _free(local_28);
    local_28 = (int **)0x0;
    local_24 = 0;
  }
  if (this == (void *)0x0) {
    FUN_0047a948();
  }
  if (ppiVar1 == *(int ***)((int)this + 4)) {
    FUN_0047a948();
  }
  ExceptionList = local_c;
  return ppiVar1 + 5;
}

