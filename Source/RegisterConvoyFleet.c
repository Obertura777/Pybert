
void __thiscall RegisterConvoyFleet(void *this,int param_1,int param_2)

{
  int *piVar1;
  int **ppiVar2;
  int *piVar3;
  int **ppiVar4;
  int iVar5;
  int **local_8;
  int *local_4;
  
  iVar5 = *(int *)((int)this + 8) + param_2 * 0x24;
  if (*(char *)(iVar5 + 4) == '\0') {
    ppiVar4 = AdjacencyList_FilterByUnitType((void *)(iVar5 + 8),&FLT);
    local_4 = (int *)*ppiVar4[1];
    local_8 = ppiVar4;
    while( true ) {
      piVar3 = local_4;
      ppiVar2 = local_8;
      piVar1 = ppiVar4[1];
      if ((local_8 == (int **)0x0) || (local_8 != ppiVar4)) {
        FUN_0047a948();
      }
      if (piVar3 == piVar1) break;
      if (ppiVar2 == (int **)0x0) {
        FUN_0047a948();
      }
      if (piVar3 == ppiVar2[1]) {
        FUN_0047a948();
      }
      if (0 < (int)(&DAT_00ba3f70)[piVar3[3]]) {
        if ((piVar3 == ppiVar2[1]) && (FUN_0047a948(), piVar3 == ppiVar2[1])) {
          FUN_0047a948();
        }
        iVar5 = param_1 * 0x100 + piVar3[3];
        if ((-1 < (int)(&DAT_005ee8ec)[iVar5 * 2]) &&
           ((0 < (int)(&DAT_005ee8ec)[iVar5 * 2] || ((&g_ProvTargetFlag)[iVar5 * 2] != 0)))) {
          if (piVar3 == ppiVar2[1]) {
            FUN_0047a948();
          }
          (&DAT_00ba3b70)[piVar3[3]] = 1;
        }
      }
      FUN_0040f400((int *)&local_8);
    }
  }
  return;
}

