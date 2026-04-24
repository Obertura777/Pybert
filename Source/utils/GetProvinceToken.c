
int ** __thiscall GetProvinceToken(void *this,ushort *param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  void **ppvVar3;
  int **ppiVar4;
  void *local_50 [2];
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  ushort local_2c [2];
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00496500;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ppiVar4 = *(int ***)((int)this + 4);
  if (*(char *)((int)ppiVar4[1] + 0x2d) == '\0') {
    ppiVar1 = (int **)ppiVar4[1];
    do {
      if (*(ushort *)(ppiVar1 + 3) < *param_1) {
        ppiVar2 = (int **)ppiVar1[2];
      }
      else {
        ppiVar2 = (int **)*ppiVar1;
        ppiVar4 = ppiVar1;
      }
      ppiVar1 = ppiVar2;
    } while (*(char *)((int)ppiVar2 + 0x2d) == '\0');
  }
  if ((ppiVar4 == *(int ***)((int)this + 4)) || (*param_1 < *(ushort *)(ppiVar4 + 3))) {
    local_30 = 0xf;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffffff00);
    local_2c[0] = *param_1;
    local_4 = 0;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_004024f0(local_28,local_48,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    ppvVar3 = FUN_00425ae0(this,local_50,this,ppiVar4,local_2c);
    this = *ppvVar3;
    ppiVar4 = ppvVar3[1];
    if (0xf < local_10) {
      _free(local_24);
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (0xf < local_30) {
      _free(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffffff00);
  }
  if (this == (void *)0x0) {
    FUN_0047a948();
  }
  if (ppiVar4 == *(int ***)((int)this + 4)) {
    FUN_0047a948();
  }
  ExceptionList = local_c;
  return ppiVar4 + 4;
}

