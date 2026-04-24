
void __fastcall ComputeOrderDipFlags(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined *local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  
  uVar11 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_14 = (undefined4 *)*DAT_00bb6f20;
  local_18 = &g_OrderList;
  do {
    puVar6 = local_14;
    puVar5 = local_18;
    puVar4 = DAT_00bb6f20;
    if ((local_18 == (undefined *)0x0) || (local_18 != &g_OrderList)) {
      FUN_0047a948();
    }
    if (puVar6 == puVar4) {
      return;
    }
    if (puVar5 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
      FUN_0047a948();
    }
    iVar2 = puVar6[6];
    if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
      FUN_0047a948();
    }
    uVar3 = puVar6[5];
    if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
      FUN_0047a948();
    }
    *(undefined1 *)(puVar6 + 7) = 1;
    if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
      FUN_0047a948();
    }
    *(undefined1 *)((int)puVar6 + 0x1d) = 1;
    if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
      FUN_0047a948();
    }
    *(undefined1 *)((int)puVar6 + 0x1e) = 0;
    if ((&DAT_00ba2f70)[iVar2] == uVar3) {
      if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
        FUN_0047a948();
      }
      *(undefined1 *)(puVar6 + 7) = 0;
    }
    else if ((&DAT_00ba2f70)[iVar2] == uVar11) {
      if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
        FUN_0047a948();
      }
      *(undefined1 *)((int)puVar6 + 0x1d) = 0;
    }
    iVar10 = iVar2 * 0x24;
    if (((*(char *)(iVar10 + 3 + *(int *)(param_1 + 8)) != '\0') &&
        (uVar1 = *(ushort *)(iVar10 + *(int *)(param_1 + 8) + 0x20), (char)(uVar1 >> 8) == 'A')) &&
       (uVar9 = uVar1 & 0xff, uVar9 != 0x14)) {
      if (uVar9 == uVar11) {
        if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
          FUN_0047a948();
        }
        *(undefined1 *)(puVar6 + 7) = 0;
      }
      else if (uVar9 == uVar3) {
        if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
          FUN_0047a948();
        }
        *(undefined1 *)((int)puVar6 + 0x1d) = 0;
      }
    }
    iVar10 = *(int *)(param_1 + 8) + iVar10;
    if (*(char *)(iVar10 + 3) != '\0') {
      uVar1 = *(ushort *)(iVar10 + 0x20);
      if ((char)(uVar1 >> 8) == 'A') {
        uVar9 = uVar1 & 0xff;
        if (((uVar9 == 0x14) ||
            (((&DAT_004cf568)[uVar9 * 2] == 1 && ((&DAT_004cf56c)[uVar9 * 2] == 0)))) ||
           ((uVar9 == uVar11 ||
            (iVar10 = uVar11 * 0x15 + uVar9,
            (&g_AllyTrustScore)[iVar10 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar10 * 2] == 0))))
        goto LAB_0041155c;
      }
      else {
        uVar9 = 0x14;
LAB_0041155c:
        if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
          FUN_0047a948();
        }
        *(undefined1 *)((int)puVar6 + 0x1d) = 0;
      }
      if ((uVar9 != uVar3) &&
         ((uVar9 == 0x14 ||
          (iVar10 = uVar3 * 0x15 + uVar9,
          (&g_AllyTrustScore)[iVar10 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar10 * 2] == 0)))) {
        if (puVar6 == *(undefined4 **)(puVar5 + 4)) {
          FUN_0047a948();
        }
        *(undefined1 *)((int)puVar6 + 0x1e) = 1;
      }
    }
    local_c = **(int **)(param_1 + 0x2a20 + iVar2 * 0xc);
    iVar2 = param_1 + 0x2a1c + iVar2 * 0xc;
    local_10 = iVar2;
    while( true ) {
      iVar8 = local_c;
      iVar7 = local_10;
      iVar10 = *(int *)(iVar2 + 4);
      if ((local_10 == 0) || (local_10 != iVar2)) {
        FUN_0047a948();
      }
      if (iVar8 == iVar10) break;
      if (iVar7 == 0) {
        FUN_0047a948();
      }
      if (iVar8 == *(int *)(iVar7 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(*(int *)(param_1 + 8) + 3 + *(int *)(iVar8 + 0xc) * 0x24) != '\0') {
        if (iVar8 == *(int *)(iVar7 + 4)) {
          FUN_0047a948();
        }
        uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 0x20 + *(int *)(iVar8 + 0xc) * 0x24);
        uVar9 = uVar1 & 0xff;
        if ((char)(uVar1 >> 8) != 'A') {
          uVar9 = 0x14;
        }
        if (((&DAT_004cf568)[uVar9 * 2] == 1) && ((&DAT_004cf56c)[uVar9 * 2] == 0)) {
          if (puVar6 == *(undefined4 **)(local_18 + 4)) {
            FUN_0047a948();
          }
          *(undefined1 *)((int)puVar6 + 0x1d) = 0;
        }
        if (DAT_00baed68 == '\x01') {
          if (uVar9 == uVar3) goto LAB_004116fa;
          if ((uVar9 != uVar11) && (uVar9 != 0x14)) {
            iVar10 = uVar11 * 0x15 + uVar9;
            if ((((int)(&g_AllyTrustScore_Hi)[iVar10 * 2] < 0) ||
                (((int)(&g_AllyTrustScore_Hi)[iVar10 * 2] < 1 &&
                 ((uint)(&g_AllyTrustScore)[iVar10 * 2] < 2)))) ||
               (((int)(&DAT_004d5484)[uVar9 * 2] < 1 &&
                (((int)(&DAT_004d5484)[uVar9 * 2] < 0 || ((uint)(&DAT_004d5480)[uVar9 * 2] < 2))))))
            {
              if (puVar6 == *(undefined4 **)(local_18 + 4)) {
                FUN_0047a948();
              }
              *(undefined1 *)((int)puVar6 + 0x1d) = 0;
            }
          }
        }
        if ((((uVar9 != uVar3) && (uVar9 != uVar11)) && (uVar9 != 0x14)) &&
           (iVar10 = uVar3 * 0x15 + uVar9,
           (&g_AllyTrustScore)[iVar10 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar10 * 2] == 0)) {
          if (puVar6 == *(undefined4 **)(local_18 + 4)) {
            FUN_0047a948();
          }
          *(undefined1 *)((int)puVar6 + 0x1e) = 1;
        }
      }
LAB_004116fa:
      TreeIterator_Advance(&local_10);
    }
    std_Tree_IteratorIncrement((int *)&local_18);
  } while( true );
}

