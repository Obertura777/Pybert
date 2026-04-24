
void __fastcall UpdateRelationHistory(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  ulonglong uVar7;
  int local_14;
  uint *local_10;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  local_14 = 0;
  if (0 < iVar2) {
    local_10 = &g_AllyTrustScore;
    do {
      iVar5 = 0;
      puVar6 = local_10;
      if (0 < iVar2) {
        do {
          uVar1 = puVar6[1];
          if ((-1 < (int)uVar1) && ((0 < (int)uVar1 || (*puVar6 != 0)))) {
            _safe_pow();
            uVar7 = FloatToInt64(extraout_ECX,extraout_EDX);
            uVar3 = (uint)uVar7;
            uVar4 = (int)uVar3 >> 0x1f;
            if (((int)uVar1 <= (int)uVar4) && (((int)uVar1 < (int)uVar4 || (*puVar6 < uVar3)))) {
              *puVar6 = uVar3;
              puVar6[1] = uVar4;
            }
          }
          iVar5 = iVar5 + 1;
          puVar6 = puVar6 + 2;
        } while (iVar5 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      local_14 = local_14 + 1;
      local_10 = local_10 + 0x2a;
    } while (local_14 < iVar2);
  }
  return;
}

