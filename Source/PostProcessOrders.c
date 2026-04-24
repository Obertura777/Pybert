
void __fastcall PostProcessOrders(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar3 = 0;
  if (0 < *(int *)(iVar4 + 0x2404)) {
    iVar6 = 0;
    do {
      iVar4 = *(int *)(iVar4 + 0x2400);
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          iVar2 = 0;
          if (0 < iVar4) {
            piVar1 = &g_MoveHistoryMatrix + (iVar6 + iVar5) * 0x100;
            do {
              if (*piVar1 < 3) {
                *piVar1 = 0;
              }
              else {
                *piVar1 = *piVar1 + -3;
              }
              iVar2 = iVar2 + 1;
              piVar1 = piVar1 + 1;
            } while (iVar2 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
          }
          iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x2400);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      iVar4 = *(int *)(param_1 + 8);
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 0x100;
    } while (iVar3 < *(int *)(iVar4 + 0x2404));
  }
  local_4 = **(int **)(*(int *)(param_1 + 8) + 0x2490);
  local_8 = *(int *)(param_1 + 8) + 0x248c;
  while( true ) {
    iVar6 = local_4;
    iVar3 = local_8;
    iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x2490);
    if ((local_8 == 0) || (local_8 != *(int *)(param_1 + 8) + 0x248c)) {
      FUN_0047a948();
    }
    if (iVar6 == iVar4) break;
    if (iVar3 == 0) {
      FUN_0047a948();
    }
    if (iVar6 == *(int *)(iVar3 + 4)) {
      FUN_0047a948();
    }
    if (*(char *)(iVar6 + 0x69) == '\x01') {
      if (iVar6 == *(int *)(iVar3 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(iVar6 + 0x6a) == '\0') {
        if (((iVar6 == *(int *)(iVar3 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) &&
           (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) {
          FUN_0047a948();
        }
        if ((int)(&g_MoveHistoryMatrix)
                 [(*(int *)(iVar6 + 0x18) * 0x100 + *(int *)(iVar6 + 0x10)) * 0x100 +
                  *(int *)(iVar6 + 0x24)] < 0xc9) {
          if (((iVar6 == *(int *)(iVar3 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) &&
             (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) {
            FUN_0047a948();
          }
          (&g_MoveHistoryMatrix)
          [(*(int *)(iVar6 + 0x18) * 0x100 + *(int *)(iVar6 + 0x10)) * 0x100 +
           *(int *)(iVar6 + 0x24)] =
               (&g_MoveHistoryMatrix)
               [(*(int *)(iVar6 + 0x18) * 0x100 + *(int *)(iVar6 + 0x10)) * 0x100 +
                *(int *)(iVar6 + 0x24)] + 10;
        }
      }
    }
    if (iVar6 == *(int *)(iVar3 + 4)) {
      FUN_0047a948();
    }
    if ((*(char *)(iVar6 + 0x6b) == '\x01') &&
       (iVar4 = 0, 0 < *(int *)(*(int *)(param_1 + 8) + 0x2400))) {
      do {
        if ((iVar6 == *(int *)(iVar3 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) {
          FUN_0047a948();
        }
        (&g_MoveHistoryMatrix)
        [(*(int *)(iVar6 + 0x18) * 0x100 + *(int *)(iVar6 + 0x10)) * 0x100 + iVar4] = 0;
        if ((iVar6 == *(int *)(iVar3 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) {
          FUN_0047a948();
        }
        (&g_MoveHistoryMatrix)
        [(*(int *)(iVar6 + 0x18) * 0x100 + *(int *)(iVar6 + 0x24)) * 0x100 + iVar4] = 0;
        if ((iVar6 == *(int *)(iVar3 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) {
          FUN_0047a948();
        }
        iVar5 = *(int *)(iVar6 + 0x18) * 0x100 + iVar4;
        iVar4 = iVar4 + 1;
        (&g_MoveHistoryMatrix)[iVar5 * 0x100 + *(int *)(iVar6 + 0x24)] = 0;
      } while (iVar4 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
    }
    if (iVar6 == *(int *)(iVar3 + 4)) {
      FUN_0047a948();
    }
    if ((*(char *)(iVar6 + 0x6a) == '\x01') &&
       (iVar4 = 0, 0 < *(int *)(*(int *)(param_1 + 8) + 0x2400))) {
      do {
        if ((iVar6 == *(int *)(iVar3 + 4)) && (FUN_0047a948(), iVar6 == *(int *)(iVar3 + 4))) {
          FUN_0047a948();
        }
        (&g_MoveHistoryMatrix)
        [(*(int *)(iVar6 + 0x18) * 0x100 + *(int *)(iVar6 + 0x10)) * 0x100 + iVar4] = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(*(int *)(param_1 + 8) + 0x2400));
    }
    UnitList_Advance(&local_8);
  }
  return;
}

