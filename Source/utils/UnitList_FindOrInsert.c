
int ** __thiscall UnitList_FindOrInsert(void *this,int *param_1)
{
  int **ppiVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  void **ppvVar4;
  int **ppiVar5;
  void *local_f0 [2];
  int local_e8;
  undefined1 local_e4 [108];
  undefined1 local_78 [108];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_004944b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ppiVar5 = *(int ***)((int)this + 4);
  if (*(char *)((int)ppiVar5[1] + 0x7d) == '\0') {
    ppiVar1 = (int **)ppiVar5[1];
    do {
      if ((int)ppiVar1[3] < *param_1) {
        ppiVar2 = (int **)ppiVar1[2];
      }
      else {
        ppiVar2 = (int **)*ppiVar1;
        ppiVar5 = ppiVar1;
      }
      ppiVar1 = ppiVar2;
    } while (*(char *)((int)ppiVar2 + 0x7d) == '\0');
  }
  if ((ppiVar5 == *(int ***)((int)this + 4)) || (*param_1 < (int)ppiVar5[3])) {
    puVar3 = (undefined4 *)FUN_004064f0((int)local_78);
    local_e8 = *param_1;
    local_4 = 0;
    FUN_004065f0(local_e4,puVar3);
    local_4._0_1_ = 1;
    ppvVar4 = FUN_00407330(this,local_f0,this,ppiVar5,&local_e8);
    this = *ppvVar4;
    ppiVar5 = ppvVar4[1];
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_00406440((int)local_e4);
    local_4 = 0xffffffff;
    FUN_00406440((int)local_78);
  }
  if (this == (void *)0x0) {
    FUN_0047a948();
  }
  if (ppiVar5 == *(int ***)((int)this + 4)) {
    FUN_0047a948();
  }
  ExceptionList = local_c;
  return ppiVar5 + 4;
}
