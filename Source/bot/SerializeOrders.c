
void __thiscall
SerializeOrders(void *this,void **param_1,void *param_2,int **param_3,void *param_4,int **param_5)

{
  int **ppiVar1;
  int **ppiVar2;
  void *pvVar3;
  int local_8 [2];
  
  pvVar3 = param_2;
  ppiVar1 = (int **)**(int **)((int)this + 4);
  if ((param_2 == (void *)0x0) || (param_2 != this)) {
    FUN_0047a948();
  }
  ppiVar2 = param_3;
  if (param_3 == ppiVar1) {
    ppiVar1 = *(int ***)((int)this + 4);
    if ((param_4 == (void *)0x0) || (param_4 != this)) {
      FUN_0047a948();
    }
    if (param_5 == ppiVar1) {
      FUN_00401950(*(int **)(*(int *)((int)this + 4) + 4));
      *(int *)(*(int *)((int)this + 4) + 4) = *(int *)((int)this + 4);
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)*(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 4);
      *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
      pvVar3 = (void *)**(undefined4 **)((int)this + 4);
      *param_1 = this;
      param_1[1] = pvVar3;
      return;
    }
  }
  while( true ) {
    if ((pvVar3 == (void *)0x0) || (pvVar3 != param_4)) {
      FUN_0047a948();
    }
    if (ppiVar2 == param_5) break;
    TreeIterator_Advance((int *)&param_2);
    FUN_00402b70(this,local_8,(int)pvVar3,ppiVar2);
    ppiVar2 = param_3;
    pvVar3 = param_2;
  }
  *param_1 = pvVar3;
  param_1[1] = ppiVar2;
  return;
}

