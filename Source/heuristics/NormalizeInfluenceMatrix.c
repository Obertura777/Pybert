
void __fastcall NormalizeInfluenceMatrix(int param_1)

{
  int iVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double *pdVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 fVar9;
  ulonglong uVar10;
  double *local_18;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar4 = 0;
  if (0 < iVar1) {
    iVar7 = 0;
    do {
      iVar3 = 0;
      iVar5 = iVar7;
      if (0 < iVar1) {
        do {
          iVar3 = iVar3 + 1;
          *(double *)((int)&DAT_00b82db8 + iVar5) =
               *(double *)((int)&g_InfluenceMatrix_Raw + iVar5) /
               (double)CONCAT44(*(int *)((int)&g_AllyTrustScore_Hi + iVar5) +
                                (uint)(0xfffffffe < *(uint *)((int)&g_AllyTrustScore + iVar5)),
                                *(uint *)((int)&g_AllyTrustScore + iVar5) + 1);
          iVar5 = iVar5 + 8;
        } while (iVar3 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 0xa8;
    } while (iVar4 < iVar1);
  }
  fVar8 = (float10)0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar7 = 0;
      if (3 < iVar1) {
        iVar5 = (iVar1 - 4U >> 2) + 1;
        iVar7 = iVar5 * 4;
        do {
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      if (iVar7 < iVar1) {
        iVar1 = iVar1 - iVar7;
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      uVar10 = PackScoreU64();
      (&DAT_004f6b98)[iVar4 * 2] = (int)uVar10;
      (&DAT_004f6b9c)[iVar4 * 2] = (int)(uVar10 >> 0x20);
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar4 = iVar4 + 1;
      fVar8 = extraout_ST0;
    } while (iVar4 < iVar1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar4 = 0;
  if (0 < iVar1) {
    local_18 = (double *)&DAT_00b82db8;
    do {
      iVar7 = 0;
      pdVar6 = local_18;
      if (0 < iVar1) {
        do {
          fVar8 = (float10)_safe_pow();
          iVar7 = iVar7 + 1;
          *pdVar6 = (double)(fVar8 * (float10)500.0 + (float10)*pdVar6);
          pdVar6 = pdVar6 + 1;
        } while (iVar7 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
        fVar8 = (float10)0;
      }
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar4 = iVar4 + 1;
      local_18 = local_18 + 0x15;
    } while (iVar4 < iVar1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar4 = 0;
  local_18 = (double *)0x0;
  if (0 < iVar1) {
    pdVar6 = (double *)&DAT_00b82dc0;
    do {
      iVar7 = 0;
      fVar9 = fVar8;
      if (3 < iVar1) {
        iVar5 = (iVar1 - 4U >> 2) + 1;
        iVar7 = iVar5 * 4;
        pdVar2 = pdVar6;
        do {
          iVar5 = iVar5 + -1;
          fVar9 = fVar9 + (float10)pdVar2[-1] + (float10)*pdVar2 + (float10)pdVar2[1] +
                  (float10)pdVar2[2];
          pdVar2 = pdVar2 + 4;
        } while (iVar5 != 0);
      }
      if (iVar7 < iVar1) {
        pdVar2 = (double *)(&DAT_00b82db8 + iVar4 + iVar7);
        iVar7 = iVar1 - iVar7;
        do {
          fVar9 = fVar9 + (float10)*pdVar2;
          pdVar2 = pdVar2 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar7 = 0;
      if (0 < iVar1) {
        do {
          if (fVar8 != fVar9) {
            (&DAT_00b82db8)[iVar4 + iVar7] =
                 (double)(((float10)(double)(&DAT_00b82db8)[iVar4 + iVar7] * (float10)100.0) / fVar9
                         );
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      local_18 = (double *)((int)local_18 + 1);
      pdVar6 = pdVar6 + 0x15;
      iVar4 = iVar4 + 0x15;
    } while ((int)local_18 < iVar1);
  }
  return;
}

