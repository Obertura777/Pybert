
void __fastcall analyze_position(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  int local_4;
  
  iVar3 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    do {
      (&DAT_0062e460)[iVar3] = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  local_4 = **(int **)(*(int *)(param_1 + 8) + 0x2454);
  local_8 = *(int *)(param_1 + 8) + 0x2450;
  while( true ) {
    iVar2 = local_4;
    iVar1 = local_8;
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2454);
    if ((local_8 == 0) || (local_8 != *(int *)(param_1 + 8) + 0x2450)) {
      FUN_0047a948();
    }
    if (iVar2 == iVar3) break;
    if (iVar1 == 0) {
      FUN_0047a948();
    }
    if (iVar2 == *(int *)(iVar1 + 4)) {
      FUN_0047a948();
    }
    (&DAT_0062e460)[*(int *)(iVar2 + 0x18)] = (&DAT_0062e460)[*(int *)(iVar2 + 0x18)] + 1;
    UnitList_Advance(&local_8);
  }
  return;
}

