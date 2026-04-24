
char __fastcall REMOVE_DMZ(int param_1)

{
  CStringData *pCVar1;
  int **ppiVar2;
  uint uVar3;
  int *piVar4;
  void **ppvVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  CStringData *pCVar9;
  int iVar10;
  int iVar11;
  int **ppiVar12;
  uint uVar13;
  undefined *this;
  undefined *puVar14;
  undefined4 *puVar15;
  undefined4 auStack_c8 [4];
  char cStack_95;
  int iStack_94;
  int iStack_8c;
  uint uStack_88;
  uint uStack_84;
  uint uStack_80;
  int iStack_7c;
  int iStack_78;
  uint uStack_74;
  CStringData *pCStack_70;
  uint uStack_6c;
  undefined2 uStack_66;
  undefined2 uStack_64;
  undefined2 uStack_62;
  void *local_60 [4];
  void *pvStack_50;
  void *pvStack_4c;
  uint uStack_38;
  void *local_34 [4];
  void *apvStack_24 [2];
  int aiStack_1c [2];
  int aiStack_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495cf3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  FUN_00465870(local_60);
  local_4._0_1_ = 1;
  FUN_00465870(local_34);
  local_4 = CONCAT31(local_4._1_3_,2);
  piVar4 = FUN_0047020b();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_8c = (**(code **)(*piVar4 + 0xc))();
  iStack_8c = iStack_8c + 0x10;
  uStack_74 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_4._0_1_ = 3;
  cStack_95 = '\0';
  ppvVar5 = (void **)GetSubList(&stack0x00000004,&pvStack_50,1);
  local_4._0_1_ = 4;
  AppendList(local_60,ppvVar5);
  local_4._0_1_ = 3;
  FreeList(&pvStack_50);
  ppvVar5 = (void **)GetSubList(&stack0x00000004,&pvStack_50,2);
  local_4._0_1_ = 5;
  AppendList(local_34,ppvVar5);
  local_4._0_1_ = 3;
  FreeList(&pvStack_50);
  uVar6 = FUN_00465930((int)local_60);
  uStack_84 = FUN_00465930((int)local_34);
  iStack_7c = 0;
  if (0 < (int)uVar6) {
    do {
      iVar10 = iStack_7c;
      pbVar7 = (byte *)GetListElement(local_60,&uStack_64,iStack_7c);
      uVar13 = (uint)*pbVar7;
      iStack_78 = 0;
      uStack_88 = uVar13;
      do {
        iVar11 = iStack_78;
        pbVar7 = (byte *)GetListElement(local_60,&uStack_62,iStack_78);
        uStack_6c = (uint)*pbVar7;
        if (((iVar11 != iVar10) || (uVar6 == 1)) && (iStack_94 = 0, 0 < (int)uStack_84)) {
          do {
            uVar3 = uStack_6c;
            pbVar7 = (byte *)GetListElement(local_34,&uStack_66,iStack_94);
            uStack_80 = (uint)*pbVar7;
            if (uVar13 == uStack_74) {
              this = &DAT_00bb6f28 + uVar3 * 0xc;
              puVar8 = (undefined4 *)GameBoard_GetPowerRec(this,aiStack_14,(int *)&uStack_80);
              puVar14 = (undefined *)*puVar8;
              ppiVar12 = (int **)puVar8[1];
              ppiVar2 = (int **)(&DAT_00bb6f2c)[uVar3 * 3];
              if ((puVar14 == (undefined *)0x0) || (puVar14 != this)) {
                FUN_0047a948();
              }
              if (ppiVar12 != ppiVar2) {
                ppvVar5 = apvStack_24;
LAB_0042126d:
                auStack_c8[3] = 0x421277;
                FUN_00402b70(this,(int *)ppvVar5,(int)puVar14,ppiVar12);
                cStack_95 = '\x01';
              }
            }
            else {
              this = &DAT_00bb7028 + uVar13 * 0xc;
              puVar8 = (undefined4 *)GameBoard_GetPowerRec(this,aiStack_1c,(int *)&uStack_80);
              puVar14 = (undefined *)*puVar8;
              ppiVar12 = (int **)puVar8[1];
              ppiVar2 = (int **)(&DAT_00bb702c)[uVar13 * 3];
              if ((puVar14 == (undefined *)0x0) || (puVar14 != this)) {
                FUN_0047a948();
              }
              if (ppiVar12 != ppiVar2) {
                ppvVar5 = &pvStack_50;
                goto LAB_0042126d;
              }
            }
            iStack_94 = iStack_94 + 1;
            iVar11 = iStack_78;
            iVar10 = iStack_7c;
            uVar13 = uStack_88;
          } while (iStack_94 < (int)uStack_84);
        }
        iStack_78 = iVar11 + 1;
      } while (iStack_78 < (int)uVar6);
      iStack_7c = iVar10 + 1;
    } while (iStack_7c < (int)uVar6);
    if (cStack_95 == '\x01') {
      puVar8 = FUN_0046b050(&stack0x00000004,&pvStack_50);
      local_4._0_1_ = 6;
      puVar15 = auStack_c8;
      for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar15 = puVar15 + 1;
      }
      SEND_LOG(&iStack_8c,(wchar_t *)"Recalculating: Because we removed a DMZ: %s");
      local_4._0_1_ = 3;
      if (0xf < uStack_38) {
        _free(pvStack_4c);
      }
      uStack_74 = 0x66;
      pCVar9 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)(iStack_8c + -0x10));
      pCStack_70 = pCVar9 + 0x10;
      local_4._0_1_ = 7;
      BuildAllianceMsg(&DAT_00bbf638,&pvStack_50,(int *)&uStack_74);
      local_4._0_1_ = 3;
      pCVar1 = pCVar9 + 0xc;
      LOCK();
      iVar10 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + -1;
      UNLOCK();
      if (iVar10 + -1 < 1) {
        (**(code **)(**(int **)pCVar9 + 4))();
      }
    }
  }
  local_4._0_1_ = 2;
  piVar4 = (int *)(iStack_8c + -4);
  LOCK();
  iVar10 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar10 == 1 || iVar10 + -1 < 0) {
    (**(code **)(**(int **)(iStack_8c + -0x10) + 4))();
  }
  local_4._0_1_ = 1;
  FreeList(local_34);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_60);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000004);
  ExceptionList = local_c;
  return cStack_95;
}

