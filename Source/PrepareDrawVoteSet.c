
void __fastcall PrepareDrawVoteSet(void *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  void **ppvVar5;
  uint uStack_3c;
  void *apvStack_38 [2];
  undefined1 local_30 [4];
  int **local_2c;
  undefined4 local_28;
  void *apvStack_24 [3];
  void *apvStack_18 [3];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497930;
  local_c = ExceptionList;
  uVar1 = DAT_004c8db8 ^ (uint)&stack0xffffffb4;
  ExceptionList = &local_c;
  local_2c = (int **)FUN_00401e30();
  *(undefined1 *)((int)local_2c + 0x11) = 1;
  local_2c[1] = (int *)local_2c;
  *local_2c = (int *)local_2c;
  local_2c[2] = (int *)local_2c;
  local_28 = 0;
  uVar4 = (uint)*(byte *)(*(int *)((int)param_1 + 8) + 0x2424);
  local_4 = 0;
  piVar2 = FUN_0047020b();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))(uVar1);
  apvStack_38[0] = (void *)(iVar3 + 0x10);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401950(local_2c[1]);
  local_2c[1] = (int *)local_2c;
  local_28 = 0;
  *local_2c = (int *)local_2c;
  local_2c[2] = (int *)local_2c;
  uStack_3c = 0;
  if (0 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404)) {
    do {
      uVar1 = uStack_3c;
      if (uStack_3c == uVar4) {
        ppvVar5 = apvStack_24;
LAB_0044cadf:
        StdMap_FindOrInsert(local_30,ppvVar5,(int *)&uStack_3c);
      }
      else if (0 < (int)(&curr_sc_cnt)[uStack_3c]) {
        iVar3 = uVar4 * 0x15 + uStack_3c;
        if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar3 * 2]) &&
           ((0 < (int)(&g_AllyTrustScore_Hi)[iVar3 * 2] ||
            (1 < (uint)(&g_AllyTrustScore)[iVar3 * 2])))) {
          ppvVar5 = apvStack_18;
          goto LAB_0044cadf;
        }
      }
      uStack_3c = uVar1 + 1;
    } while ((int)uStack_3c < *(int *)(*(int *)((int)param_1 + 8) + 0x2404));
  }
  DAT_00baed2b = ComputeDrawVote(param_1,local_30);
  local_4 = local_4 & 0xffffff00;
  piVar2 = (int *)((int)apvStack_38[0] + -4);
  LOCK();
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)((int)apvStack_38[0] + -0x10) + 4))
              ((undefined4 *)((int)apvStack_38[0] + -0x10));
  }
  local_4 = 0xffffffff;
  SerializeOrders(local_30,apvStack_38,local_30,(int **)*local_2c,local_30,local_2c);
  _free(local_2c);
  ExceptionList = local_c;
  return;
}

