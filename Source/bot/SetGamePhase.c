
void __thiscall SetGamePhase(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  iVar2 = *(int *)(*(int *)((int)this + 8) + 0x2404);
  local_c = 0;
  if (0 < iVar2) {
    local_4 = &DAT_00634e90;
    local_8 = &g_AllyTrustScore;
    do {
      iVar4 = 0;
      if (0 < iVar2) {
        iVar2 = local_c + param_1 * 0x15;
        puVar1 = (undefined4 *)(&DAT_0062e4b8 + iVar2 * 0xa8);
        puVar3 = (undefined4 *)(&DAT_00631bd8 + iVar2 * 0x54);
        puVar5 = local_8;
        puVar6 = local_4;
        do {
          *puVar3 = *puVar6;
          *puVar1 = *puVar5;
          puVar1[1] = puVar5[1];
          iVar4 = iVar4 + 1;
          puVar6 = puVar6 + 1;
          puVar3 = puVar3 + 1;
          puVar5 = puVar5 + 2;
          puVar1 = puVar1 + 2;
        } while (iVar4 < *(int *)(*(int *)((int)this + 8) + 0x2404));
      }
      iVar2 = *(int *)(*(int *)((int)this + 8) + 0x2404);
      local_c = local_c + 1;
      local_8 = local_8 + 0x2a;
      local_4 = local_4 + 0x15;
    } while (local_c < iVar2);
  }
  return;
}

