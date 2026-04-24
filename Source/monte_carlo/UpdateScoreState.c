
void __fastcall UpdateScoreState(void *param_1)

{
  int iVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  int **local_14;
  int local_10 [3];
  
  local_14 = (int **)0x0;
  if (0 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404)) {
    do {
      ppiVar2 = local_14;
      iVar1 = DAT_00bc1e04;
      if (0 < (int)(&DAT_0062e460)[(int)local_14]) {
        puVar3 = (undefined4 *)GameBoard_GetPowerRec(&DAT_00bc1e00,local_10,(int *)&local_14);
        if (((undefined *)*puVar3 == (undefined *)0x0) || ((undefined *)*puVar3 != &DAT_00bc1e00)) {
          FUN_0047a948();
        }
        if (puVar3[1] != iVar1) {
          UpdateAllyOrderScore(param_1,ppiVar2);
        }
      }
      local_14 = (int **)((int)ppiVar2 + 1);
    } while ((int)local_14 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404));
  }
  local_14 = (int **)0x0;
  if (0 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404)) {
    do {
      ppiVar2 = local_14;
      iVar1 = DAT_00bc1e04;
      if (0 < (int)(&DAT_0062e460)[(int)local_14]) {
        puVar3 = (undefined4 *)GameBoard_GetPowerRec(&DAT_00bc1e00,local_10,(int *)&local_14);
        if (((undefined *)*puVar3 == (undefined *)0x0) || ((undefined *)*puVar3 != &DAT_00bc1e00)) {
          FUN_0047a948();
        }
        if (puVar3[1] != iVar1) {
          RefreshOrderTable((int)ppiVar2);
        }
      }
      local_14 = (int **)((int)ppiVar2 + 1);
    } while ((int)local_14 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404));
  }
  return;
}

