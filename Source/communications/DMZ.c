
char __fastcall DMZ(int param_1)

{
  CStringData *pCVar1;
  int **ppiVar2;
  uint uVar3;
  int *piVar4;
  void **ppvVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  CStringData *pCVar8;
  int *piVar9;
  int iVar10;
  undefined *puVar11;
  int **ppiVar12;
  int iVar13;
  char cStack_b1;
  int *piStack_b0;
  int *piStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined *puStack_a0;
  CStringData *pCStack_9c;
  undefined *puStack_98;
  int **ppiStack_94;
  int iStack_90;
  uint uStack_8c;
  int *piStack_88;
  int iStack_84;
  uint uStack_80;
  undefined2 uStack_7a;
  undefined2 uStack_78;
  undefined2 uStack_76;
  void *local_74 [4];
  void *pvStack_64;
  void *pvStack_60;
  uint uStack_4c;
  void *local_48 [5];
  int iStack_34;
  int aiStack_30 [2];
  int aiStack_28 [2];
  int aiStack_20 [2];
  void *apvStack_18 [3];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495b56;
  local_c = ExceptionList;
  uVar3 = DAT_004c8db8 ^ (uint)&stack0xffffff3c;
  ExceptionList = &local_c;
  local_4 = 0;
  FUN_00465870(local_74);
  local_4._0_1_ = 1;
  FUN_00465870(local_48);
  local_4 = CONCAT31(local_4._1_3_,2);
  piVar4 = FUN_0047020b();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iStack_a8 = (**(code **)(*piVar4 + 0xc))(uVar3);
  iStack_a8 = iStack_a8 + 0x10;
  piStack_88 = (int *)(uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_4._0_1_ = 3;
  cStack_b1 = '\0';
  ppvVar5 = (void **)GetSubList(&stack0x00000004,&pvStack_64,1);
  local_4._0_1_ = 4;
  AppendList(local_74,ppvVar5);
  local_4._0_1_ = 3;
  FreeList(&pvStack_64);
  ppvVar5 = (void **)GetSubList(&stack0x00000004,&pvStack_64,2);
  local_4._0_1_ = 5;
  AppendList(local_48,ppvVar5);
  local_4._0_1_ = 3;
  FreeList(&pvStack_64);
  uVar3 = FUN_00465930((int)local_74);
  uStack_80 = uVar3;
  uStack_8c = FUN_00465930((int)local_48);
  iStack_90 = 0;
  if (0 < (int)uVar3) {
    do {
      iVar10 = iStack_90;
      pbVar6 = (byte *)GetListElement(local_74,&uStack_7a,iStack_90);
      piVar4 = (int *)(uint)*pbVar6;
      iStack_84 = 0;
      piStack_ac = piVar4;
      do {
        iVar13 = iStack_84;
        GetListElement(local_74,&uStack_78,iStack_84);
        if (((iVar10 != iVar13) || (uVar3 == 1)) && (iStack_a4 = 0, 0 < (int)uStack_8c)) {
          do {
            pbVar6 = (byte *)GetListElement(local_48,&uStack_76,iStack_a4);
            piVar9 = (int *)(uint)*pbVar6;
            piStack_b0 = piVar9;
            if (piVar4 == piStack_88) {
              pCStack_9c = *(CStringData **)DAT_00bb65e4;
              puStack_a0 = &DAT_00bb65e0;
              while( true ) {
                pCVar8 = pCStack_9c;
                puVar11 = puStack_a0;
                pCVar1 = DAT_00bb65e4;
                if ((puStack_a0 == (undefined *)0x0) || (puStack_a0 != &DAT_00bb65e0)) {
                  FUN_0047a948();
                }
                if (pCVar8 == pCVar1) break;
                if (puVar11 == (undefined *)0x0) {
                  FUN_0047a948();
                }
                if (pCVar8 == *(CStringData **)(puVar11 + 4)) {
                  FUN_0047a948();
                }
                if (*(int **)(pCVar8 + 0xc) != piStack_88) {
                  if (pCVar8 == *(CStringData **)(puVar11 + 4)) {
                    FUN_0047a948();
                  }
                  iVar10 = *(int *)(pCVar8 + 0xc);
                  iStack_34 = (&DAT_00bb6f2c)[iVar10 * 3];
                  if (pCVar8 == *(CStringData **)(puVar11 + 4)) {
                    FUN_0047a948();
                  }
                  puVar7 = (undefined4 *)
                           GameBoard_GetPowerRec
                                     (&DAT_00bb6f28 + *(int *)(pCVar8 + 0xc) * 0xc,aiStack_30,
                                      (int *)&piStack_b0);
                  if (((undefined *)*puVar7 == (undefined *)0x0) ||
                     ((undefined *)*puVar7 != &DAT_00bb6f28 + iVar10 * 0xc)) {
                    FUN_0047a948();
                  }
                  if (puVar7[1] == iStack_34) {
                    if (pCVar8 == *(CStringData **)(puVar11 + 4)) {
                      FUN_0047a948();
                    }
                    StdMap_FindOrInsert(&DAT_00bb6f28 + *(int *)(pCVar8 + 0xc) * 0xc,apvStack_18,
                                        (int *)&piStack_b0);
                    cStack_b1 = '\x01';
                  }
                }
                TreeIterator_Advance((int *)&puStack_a0);
              }
            }
            else {
              iVar10 = (&DAT_00bb702c)[(int)piVar4 * 3];
              puVar11 = &DAT_00bb7028 + (int)piVar4 * 0xc;
              puVar7 = (undefined4 *)GameBoard_GetPowerRec(puVar11,aiStack_28,(int *)&piStack_b0);
              if (((undefined *)*puVar7 == (undefined *)0x0) || ((undefined *)*puVar7 != puVar11)) {
                FUN_0047a948();
              }
              if (puVar7[1] == iVar10) {
                cStack_b1 = '\x01';
                StdMap_FindOrInsert(puVar11,&pvStack_64,(int *)&piStack_b0);
              }
              ppiVar12 = (int **)*DAT_00bb7134;
              puVar11 = &DAT_00bb7130;
              puStack_98 = &DAT_00bb7130;
              ppiStack_94 = ppiVar12;
              if (ppiVar12 != DAT_00bb7134) {
                do {
                  if (puVar11 == (undefined *)0x0) {
                    FUN_0047a948();
                  }
                  if (ppiVar12 == *(int ***)(puVar11 + 4)) {
                    FUN_0047a948();
                  }
                  if (ppiVar12[3] == piStack_ac) {
                    if (ppiVar12 == *(int ***)(puVar11 + 4)) {
                      FUN_0047a948();
                    }
                    if (ppiVar12[4] != piVar9) goto LAB_00420474;
                    FUN_00412280(&DAT_00bb7130,aiStack_20,(int)puVar11,ppiVar12);
                    ppiStack_94 = (int **)*DAT_00bb7134;
                    puStack_98 = &DAT_00bb7130;
                  }
                  else {
LAB_00420474:
                    FUN_0040e680((int *)&puStack_98);
                  }
                  ppiVar12 = ppiStack_94;
                  puVar11 = puStack_98;
                  ppiVar2 = DAT_00bb7134;
                  if ((puStack_98 == (undefined *)0x0) || (puStack_98 != &DAT_00bb7130)) {
                    FUN_0047a948();
                  }
                } while (ppiVar12 != ppiVar2);
              }
            }
            iStack_a4 = iStack_a4 + 1;
            uVar3 = uStack_80;
            iVar10 = iStack_90;
            piVar4 = piStack_ac;
            iVar13 = iStack_84;
          } while (iStack_a4 < (int)uStack_8c);
        }
        iStack_84 = iVar13 + 1;
      } while (iStack_84 < (int)uVar3);
      iStack_90 = iVar10 + 1;
    } while (iStack_90 < (int)uVar3);
    if (cStack_b1 == '\x01') {
      FUN_0046b050(&stack0x00000004,&pvStack_64);
      local_4._0_1_ = 6;
      SEND_LOG(&iStack_a8,(wchar_t *)"Recalculating: Because we have applied a DMZ: (%s)");
      local_4._0_1_ = 3;
      if (0xf < uStack_4c) {
        _free(pvStack_60);
      }
      puStack_a0 = (undefined *)0x66;
      pCVar8 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)(iStack_a8 + -0x10));
      pCStack_9c = pCVar8 + 0x10;
      local_4._0_1_ = 7;
      BuildAllianceMsg(&DAT_00bbf638,&pvStack_64,(int *)&puStack_a0);
      local_4._0_1_ = 3;
      pCVar1 = pCVar8 + 0xc;
      LOCK();
      iVar10 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + -1;
      UNLOCK();
      if (iVar10 == 1 || iVar10 + -1 < 0) {
        (**(code **)(**(int **)pCVar8 + 4))(pCVar8);
      }
    }
  }
  local_4._0_1_ = 2;
  piVar4 = (int *)(iStack_a8 + -4);
  LOCK();
  iVar10 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar10 == 1 || iVar10 + -1 < 0) {
    (**(code **)(**(int **)(iStack_a8 + -0x10) + 4))((undefined4 *)(iStack_a8 + -0x10));
  }
  local_4._0_1_ = 1;
  FreeList(local_48);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_74);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000004);
  ExceptionList = local_c;
  return cStack_b1;
}

