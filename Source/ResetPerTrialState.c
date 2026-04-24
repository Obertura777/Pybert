
void __fastcall ResetPerTrialState(int param_1)

{
  char cVar1;
  int iVar2;
  int *_Memory;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  
  local_c = **(int **)(param_1 + 0x2454);
  local_10 = param_1 + 0x2450;
  while( true ) {
    iVar5 = local_c;
    iVar4 = local_10;
    iVar2 = *(int *)(param_1 + 0x2454);
    if ((local_10 == 0) || (local_10 != param_1 + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar5 == iVar2) break;
    if (iVar4 == 0) {
      FUN_0047a948();
    }
    if (iVar5 == *(int *)(iVar4 + 4)) {
      FUN_0047a948();
    }
    *(undefined4 *)(iVar5 + 0x20) = 0;
    UnitList_Advance(&local_10);
  }
  local_c = **(int **)(param_1 + 0x2460);
  local_10 = param_1 + 0x245c;
  while( true ) {
    iVar5 = local_c;
    iVar4 = local_10;
    iVar2 = *(int *)(param_1 + 0x2460);
    if ((local_10 == 0) || (local_10 != param_1 + 0x245c)) {
      FUN_0047a948();
    }
    if (iVar5 == iVar2) break;
    if (iVar4 == 0) {
      FUN_0047a948();
    }
    if (iVar5 == *(int *)(iVar4 + 4)) {
      FUN_0047a948();
    }
    *(undefined4 *)(iVar5 + 0x20) = 0;
    UnitList_Advance(&local_10);
  }
  _Memory = *(int **)(*(int *)(param_1 + 0x2478) + 4);
  cVar1 = *(char *)((int)_Memory + 0x19);
  while (cVar1 == '\0') {
    FUN_0040fb70((int *)_Memory[2]);
    piVar3 = (int *)*_Memory;
    _free(_Memory);
    _Memory = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x19);
  }
  *(int *)(*(int *)(param_1 + 0x2478) + 4) = *(int *)(param_1 + 0x2478);
  *(undefined4 *)(param_1 + 0x247c) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x2478) = *(undefined4 *)(param_1 + 0x2478);
  *(int *)(*(int *)(param_1 + 0x2478) + 8) = *(int *)(param_1 + 0x2478);
  *(undefined4 *)(param_1 + 0x2480) = 0;
  return;
}

