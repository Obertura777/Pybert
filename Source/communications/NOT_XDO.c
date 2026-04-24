
undefined4 NOT_XDO(void)

{
  CStringData *pCVar1;
  int iVar2;
  int **ppiVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  int *piVar7;
  void **ppvVar8;
  undefined4 *this;
  CStringData *pCVar9;
  undefined4 extraout_EAX;
  CStringData *pCVar10;
  int **in_stack_00000018;
  undefined2 uStack_46;
  int iStack_44;
  undefined1 *puStack_40;
  CStringData *pCStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  uint uStack_20;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495c90;
  local_c = ExceptionList;
  uVar6 = DAT_004c8db8 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_c;
  local_4 = 1;
  FUN_00465870(local_1c);
  local_4 = CONCAT31(local_4._1_3_,2);
  piVar7 = FUN_0047020b();
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_44 = (**(code **)(*piVar7 + 0xc))(uVar6);
  iStack_44 = iStack_44 + 0x10;
  local_4._0_1_ = 3;
  ppvVar8 = (void **)GetSubList(&stack0x00000004,&pvStack_38,1);
  local_4._0_1_ = 4;
  AppendList(local_1c,ppvVar8);
  local_4._0_1_ = 3;
  FreeList(&pvStack_38);
  this = GetSubList(local_1c,&pvStack_38,0);
  local_4._0_1_ = 5;
  GetListElement(this,&uStack_46,0);
  local_4 = CONCAT31(local_4._1_3_,3);
  FreeList(&pvStack_38);
  pCStack_3c = (CStringData *)*in_stack_00000018;
  puStack_40 = &stack0x00000014;
  while( true ) {
    pCVar1 = pCStack_3c;
    puVar5 = puStack_40;
    ppiVar3 = in_stack_00000018;
    if ((puStack_40 == (undefined1 *)0x0) || (puStack_40 != &stack0x00000014)) {
      FUN_0047a948();
    }
    if (pCVar1 == (CStringData *)ppiVar3) break;
    if (puVar5 == (undefined1 *)0x0) {
      FUN_0047a948();
    }
    if (pCVar1 == (CStringData *)*(int ***)(puVar5 + 4)) {
      FUN_0047a948();
    }
    FUN_00419300(&DAT_00bb66f8 + (int)*(int **)((int)pCVar1 + 0xc) * 0xc,&pvStack_38,local_1c);
    TreeIterator_Advance((int *)&puStack_40);
  }
  FUN_0046b050(&stack0x00000004,&pvStack_38);
  local_4._0_1_ = 6;
  SEND_LOG(&iStack_44,(wchar_t *)"Recalculating: Because we have applied a NOT XDO: (%s)");
  local_4._0_1_ = 3;
  if (0xf < uStack_20) {
    _free(pvStack_34);
  }
  iVar4 = iStack_44;
  pCVar10 = (CStringData *)(iStack_44 + -0x10);
  puStack_40 = (undefined1 *)0x66;
  pCVar9 = ATL::CSimpleStringT<char,0>::CloneData(pCVar10);
  pCStack_3c = pCVar9 + 0x10;
  local_4._0_1_ = 7;
  BuildAllianceMsg(&DAT_00bbf638,&pvStack_38,(int *)&puStack_40);
  local_4._0_1_ = 3;
  pCVar1 = pCVar9 + 0xc;
  LOCK();
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)pCVar9 + 4))(pCVar9);
  }
  local_4._0_1_ = 2;
  piVar7 = (int *)(iVar4 + -4);
  LOCK();
  iVar2 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)pCVar10 + 4))(pCVar10);
  }
  local_4._0_1_ = 1;
  FreeList(local_1c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000004);
  local_4 = 0xffffffff;
  SerializeOrders(&stack0x00000014,&puStack_40,&stack0x00000014,(int **)*in_stack_00000018,
                  &stack0x00000014,in_stack_00000018);
  _free(in_stack_00000018);
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
}

