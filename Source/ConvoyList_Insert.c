
int ** __thiscall ConvoyList_Insert(void *this,int *param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  void **ppvVar3;
  int **ppiVar4;
  int local_10 [2];
  void *local_8 [2];
  
  ppiVar4 = *(int ***)((int)this + 4);
  if (*(char *)((int)ppiVar4[1] + 0x15) == '\0') {
    ppiVar1 = (int **)ppiVar4[1];
    do {
      if ((int)ppiVar1[3] < *param_1) {
        ppiVar2 = (int **)ppiVar1[2];
      }
      else {
        ppiVar2 = (int **)*ppiVar1;
        ppiVar4 = ppiVar1;
      }
      ppiVar1 = ppiVar2;
    } while (*(char *)((int)ppiVar2 + 0x15) == '\0');
  }
  if ((ppiVar4 == *(int ***)((int)this + 4)) || (*param_1 < (int)ppiVar4[3])) {
    local_10[0] = *param_1;
    local_10[1] = 0;
    ppvVar3 = FUN_00419a70(this,local_8,this,ppiVar4,local_10);
    this = *ppvVar3;
    ppiVar4 = ppvVar3[1];
  }
  if (this == (void *)0x0) {
    FUN_0047a948();
  }
  if (ppiVar4 == *(int ***)((int)this + 4)) {
    FUN_0047a948();
  }
  return ppiVar4 + 4;
}

