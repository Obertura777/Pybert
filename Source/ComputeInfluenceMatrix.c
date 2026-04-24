
void __fastcall ComputeInfluenceMatrix(int param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  double *pdVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  double *pdVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  bool bVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 fVar18;
  ulonglong uVar19;
  int local_28;
  double *local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_c;
  
  uVar9 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  uVar13 = 0;
  if (0 < iVar3) {
    local_28 = 0;
    do {
      uVar11 = 0;
      iVar12 = local_28;
      if (0 < iVar3) {
        do {
          if ((uVar9 == uVar13) || (uVar9 == uVar11)) {
            dVar1 = *(double *)((int)&g_InfluenceMatrix_Raw + iVar12);
          }
          else {
            iVar3 = *(int *)((int)&g_AllyTrustScore_Hi + iVar12);
            uVar2 = *(uint *)((int)&g_AllyTrustScore + iVar12);
            if ((iVar3 < 0) || ((iVar3 < 1 && (uVar2 < 6)))) {
              dVar1 = *(double *)((int)&g_InfluenceMatrix_Raw + iVar12) /
                      (double)CONCAT44(iVar3 + (uint)(0xfffffffe < uVar2),uVar2 + 1);
            }
            else {
              dVar1 = *(double *)((int)&g_InfluenceMatrix_Raw + iVar12) / 6.0;
            }
          }
          *(double *)((int)&g_InfluenceMatrix_Alt + iVar12) = dVar1;
          uVar11 = uVar11 + 1;
          iVar12 = iVar12 + 8;
        } while ((int)uVar11 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      local_28 = local_28 + 0xa8;
      uVar13 = uVar13 + 1;
    } while ((int)uVar13 < iVar3);
  }
  fVar17 = (float10)0;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar12 = 0;
  if (0 < iVar3) {
    do {
      iVar14 = 0;
      if (3 < iVar3) {
        iVar7 = (iVar3 - 4U >> 2) + 1;
        iVar14 = iVar7 * 4;
        do {
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (iVar14 < iVar3) {
        iVar3 = iVar3 - iVar14;
        do {
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      uVar19 = PackScoreU64();
      (&DAT_004f6af0)[iVar12 * 2] = (int)uVar19;
      (&DAT_004f6af4)[iVar12 * 2] = (int)(uVar19 >> 0x20);
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar12 = iVar12 + 1;
      fVar17 = extraout_ST0;
    } while (iVar12 < iVar3);
  }
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar12 = 0;
  if (0 < iVar3) {
    pdVar10 = (double *)&g_InfluenceMatrix_Alt;
    do {
      iVar14 = 0;
      pdVar4 = pdVar10;
      if (0 < iVar3) {
        do {
          fVar17 = (float10)_safe_pow();
          iVar14 = iVar14 + 1;
          *pdVar4 = (double)(fVar17 * (float10)500.0 + (float10)*pdVar4);
          pdVar4 = pdVar4 + 1;
        } while (iVar14 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
        fVar17 = (float10)0;
      }
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar12 = iVar12 + 1;
      pdVar10 = pdVar10 + 0x15;
    } while (iVar12 < iVar3);
  }
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  iVar12 = 0;
  if (0 < iVar3) {
    iVar14 = 0;
    pdVar10 = (double *)&DAT_00b81ff8;
    do {
      iVar7 = 0;
      fVar18 = fVar17;
      if (3 < iVar3) {
        iVar5 = (iVar3 - 4U >> 2) + 1;
        iVar7 = iVar5 * 4;
        pdVar4 = pdVar10;
        do {
          iVar5 = iVar5 + -1;
          fVar18 = fVar18 + (float10)pdVar4[-1] + (float10)*pdVar4 + (float10)pdVar4[1] +
                   (float10)pdVar4[2];
          pdVar4 = pdVar4 + 4;
        } while (iVar5 != 0);
      }
      if (iVar7 < iVar3) {
        pdVar4 = (double *)(&g_InfluenceMatrix_Alt + iVar14 + iVar7);
        iVar7 = iVar3 - iVar7;
        do {
          fVar18 = fVar18 + (float10)*pdVar4;
          pdVar4 = pdVar4 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar7 = 0;
      if (0 < iVar3) {
        do {
          if (fVar17 != fVar18) {
            (&g_InfluenceMatrix_Alt)[iVar14 + iVar7] =
                 (double)(((float10)(double)(&g_InfluenceMatrix_Alt)[iVar14 + iVar7] *
                          (float10)100.0) / fVar18);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      iVar12 = iVar12 + 1;
      pdVar10 = pdVar10 + 0x15;
      iVar14 = iVar14 + 0x15;
    } while (iVar12 < iVar3);
  }
  iVar3 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
    piVar8 = &DAT_006340c0;
    puVar15 = &DAT_00633f1c;
    do {
      puVar15[-1] = uVar9;
      *puVar15 = uVar9;
      puVar15[1] = uVar9;
      puVar15[2] = uVar9;
      puVar15[3] = uVar9;
      iVar12 = 0;
      piVar6 = piVar8;
      if (0 < *(int *)(*(int *)(param_1 + 8) + 0x2404)) {
        do {
          bVar16 = iVar3 != iVar12;
          iVar12 = iVar12 + 1;
          *piVar6 = bVar16 - 2;
          piVar6 = piVar6 + 1;
        } while (iVar12 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
      }
      iVar3 = iVar3 + 1;
      puVar15 = puVar15 + 5;
      piVar8 = piVar8 + 0x15;
    } while (iVar3 < *(int *)(*(int *)(param_1 + 8) + 0x2404));
  }
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
  local_c = 0;
  if (0 < iVar3) {
    iVar12 = 0;
    local_1c = 0;
    local_28 = 0;
    local_20 = &DAT_006340c4;
    local_24 = (double *)&DAT_00b81ff8;
    do {
      local_18 = 1;
      if (0 < iVar3) {
        do {
          iVar14 = 0;
          dVar1 = -1.0;
          if (3 < iVar3) {
            pdVar10 = local_24;
            piVar8 = local_20;
            do {
              if ((dVar1 < pdVar10[-1]) && (piVar8[-1] == -1)) {
                dVar1 = pdVar10[-1];
                iVar12 = iVar14;
              }
              if ((dVar1 < *pdVar10) && (*piVar8 == -1)) {
                iVar12 = iVar14 + 1;
                dVar1 = *pdVar10;
              }
              if ((dVar1 < pdVar10[1]) && (piVar8[1] == -1)) {
                iVar12 = iVar14 + 2;
                dVar1 = pdVar10[1];
              }
              if ((dVar1 < pdVar10[2]) && (piVar8[2] == -1)) {
                iVar12 = iVar14 + 3;
                dVar1 = pdVar10[2];
              }
              iVar14 = iVar14 + 4;
              piVar8 = piVar8 + 4;
              pdVar10 = pdVar10 + 4;
            } while (iVar14 < iVar3 + -3);
          }
          if (iVar14 < iVar3) {
            pdVar10 = (double *)(&g_InfluenceMatrix_Alt + local_28 + iVar14);
            piVar8 = &DAT_006340c0 + local_28 + iVar14;
            do {
              if ((dVar1 < *pdVar10) && (*piVar8 == -1)) {
                dVar1 = *pdVar10;
                iVar12 = iVar14;
              }
              iVar14 = iVar14 + 1;
              piVar8 = piVar8 + 1;
              pdVar10 = pdVar10 + 1;
            } while (iVar14 < iVar3);
          }
          if (local_18 < iVar3) {
            (&DAT_006340c0)[local_28 + iVar12] = local_18;
            (&DAT_00633f18)[local_1c + local_18] = iVar12;
          }
          iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
          bVar16 = local_18 < iVar3;
          local_18 = local_18 + 1;
        } while (bVar16);
      }
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x2404);
      local_24 = local_24 + 0x15;
      local_20 = local_20 + 0x15;
      local_28 = local_28 + 0x15;
      local_1c = local_1c + 5;
      local_c = local_c + 1;
    } while (local_c < iVar3);
  }
  return;
}

