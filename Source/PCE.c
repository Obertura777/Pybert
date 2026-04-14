
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __fastcall PCE(int param_1)

{
  CStringData *pCVar1;
  int *piVar2;
  bool bVar3;
  void *_Src;
  uint uVar4;
  int *piVar5;
  int iVar6;
  void **ppvVar7;
  byte *pbVar8;
  uint uVar9;
  CStringData *pCVar10;
  undefined4 *puVar11;
  rsize_t _DstSize;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  char cStack_52;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  void *pvStack_4c;
  int local_48;
  uint uStack_44;
  uint uStack_40;
  CStringData *pCStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  uint uStack_20;
  void *apvStack_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004957e8;
  local_c = ExceptionList;
  uVar4 = DAT_004c8db8 ^ (uint)&stack0xffffff9c;
  ExceptionList = &local_c;
  iVar15 = 0;
  local_4 = 0;
  local_48 = param_1;
  piVar5 = FUN_0047020b();
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*piVar5 + 0xc))(uVar4);
  pvStack_4c = (void *)(iVar6 + 0x10);
  local_4._0_1_ = 1;
  FUN_00465f60(apvStack_1c,(void **)&stack0x00000004);
  uVar4 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_4._0_1_ = 2;
  bVar3 = false;
  cStack_52 = '\0';
  uStack_44 = uVar4;
  ppvVar7 = (void **)GetSubList(&stack0x00000004,&pvStack_38,1);
  local_4._0_1_ = 3;
  AppendList(&stack0x00000004,ppvVar7);
  local_4 = CONCAT31(local_4._1_3_,2);
  FreeList(&pvStack_38);
  uStack_40 = FUN_00465930((int)&stack0x00000004);
  if (0 < (int)uStack_40) {
    do {
      pbVar8 = (byte *)GetListElement(&stack0x00000004,&uStack_50,iVar15);
      uVar16 = (uint)*pbVar8;
      iVar6 = 0;
      do {
        pbVar8 = (byte *)GetListElement(&stack0x00000004,&uStack_4e,iVar6);
        uVar12 = (uint)*pbVar8;
        if (iVar15 != iVar6) {
          if (uVar16 == uVar4) {
            (&DAT_004d53d8)[uVar12 * 2] = 2;
            (&DAT_004d53dc)[uVar12 * 2] = 0;
          }
          uVar9 = 3;
          if ((_g_NearEndGameFactor < 4.0) &&
             (uVar9 = 3 - (&DAT_0062a2f8)[uVar16 * 0x15 + uVar12], (int)uVar9 < 1)) {
            uVar9 = 1;
          }
          iVar13 = uVar16 * 0x15 + uVar12;
          iVar14 = (int)uVar9 >> 0x1f;
          uVar4 = uStack_44;
          if (((int)(&g_AllyTrustScore_Hi)[iVar13 * 2] <= iVar14) &&
             (((int)(&g_AllyTrustScore_Hi)[iVar13 * 2] < iVar14 ||
              ((uint)(&g_AllyTrustScore)[iVar13 * 2] < uVar9)))) {
            (&g_AllyTrustScore)[iVar13 * 2] = uVar9;
            (&g_AllyTrustScore_Hi)[iVar13 * 2] = iVar14;
            cStack_52 = '\x01';
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uStack_40);
      iVar15 = iVar15 + 1;
    } while (iVar15 < (int)uStack_40);
    if (cStack_52 == '\x01') {
      FUN_0046b050(apvStack_1c,&pvStack_38);
      local_4._0_1_ = 4;
      SEND_LOG(&pvStack_4c,(wchar_t *)"Recalculating: Because we have applied a peace deal %s");
      local_4._0_1_ = 2;
      if (0xf < uStack_20) {
        _free(pvStack_34);
      }
      uStack_40 = 0x66;
      pCVar10 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)((int)pvStack_4c + -0x10));
      pCStack_3c = pCVar10 + 0x10;
      local_4._0_1_ = 5;
      BuildAllianceMsg(&DAT_00bbf638,&pvStack_38,(int *)&uStack_40);
      local_4 = CONCAT31(local_4._1_3_,2);
      pCVar1 = pCVar10 + 0xc;
      LOCK();
      iVar15 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + -1;
      UNLOCK();
      if (iVar15 + -1 < 1) {
        (**(code **)(**(int **)pCVar10 + 4))(pCVar10);
      }
    }
  }
  if (DAT_00baed68 == '\x01') {
    iVar15 = *(int *)(*(int *)(local_48 + 8) + 0x2404);
    iVar6 = 0;
    if (0 < iVar15) {
      do {
        if ((((&DAT_004d53d8)[iVar6 * 2] == 1) && ((&DAT_004d53dc)[iVar6 * 2] == 0)) ||
           ((iVar13 = uVar4 * 0x15 + iVar6,
            (&g_AllyTrustScore)[iVar13 * 2] == 0 && (&g_AllyTrustScore_Hi)[iVar13 * 2] == 0 &&
            ((&DAT_004d5480)[iVar6 * 2] != 0 || (&DAT_004d5484)[iVar6 * 2] != 0)))) {
          bVar3 = true;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar15);
      if (bVar3) goto LAB_0041deab;
    }
    SEND_LOG(&pvStack_4c,L"ALL powers have accepted PCE: return to original plan");
    _Src = pvStack_4c;
    piVar5 = (int *)((int)pvStack_4c + -0x10);
    uStack_40 = 0x65;
    puVar11 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_4c + -0x10) + 0x10))();
    if ((*(int *)((int)_Src + -4) < 0) || (puVar11 != (undefined4 *)*piVar5)) {
      piVar5 = (int *)(**(code **)*puVar11)(*(undefined4 *)((int)_Src + -0xc),1);
      if (piVar5 == (int *)0x0) {
        ErrorExit();
      }
      piVar5[1] = *(int *)((int)_Src + -0xc);
      _DstSize = *(int *)((int)_Src + -0xc) + 1;
      _memcpy_s(piVar5 + 4,_DstSize,_Src,_DstSize);
    }
    else {
      LOCK();
      *(int *)((int)_Src + -4) = *(int *)((int)_Src + -4) + 1;
      UNLOCK();
    }
    pCStack_3c = (CStringData *)(piVar5 + 4);
    local_4._0_1_ = 6;
    BuildAllianceMsg(&DAT_00bbf638,&pvStack_38,(int *)&uStack_40);
    local_4 = CONCAT31(local_4._1_3_,2);
    piVar2 = piVar5 + 3;
    LOCK();
    iVar15 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar15 == 1 || iVar15 + -1 < 0) {
      (**(code **)(*(int *)*piVar5 + 4))(piVar5);
    }
    iVar15 = 0;
    if (0 < *(int *)(*(int *)(local_48 + 8) + 0x2404)) {
      puVar11 = &g_AllyTrustScore + uVar4 * 0x2a;
      do {
        *puVar11 = (&DAT_004d5480)[iVar15 * 2];
        puVar11[1] = (&DAT_004d5484)[iVar15 * 2];
        iVar15 = iVar15 + 1;
        puVar11 = puVar11 + 2;
      } while (iVar15 < *(int *)(*(int *)(local_48 + 8) + 0x2404));
    }
    cStack_52 = '\x01';
  }
  else {
LAB_0041deab:
    if (cStack_52 != '\x01') goto LAB_0041debb;
  }
  FUN_004113d0(local_48);
LAB_0041debb:
  local_4._0_1_ = 1;
  FreeList(apvStack_1c);
  local_4 = (uint)local_4._1_3_ << 8;
  piVar5 = (int *)((int)pvStack_4c + -4);
  LOCK();
  iVar15 = *piVar5;
  *piVar5 = *piVar5 + -1;
  UNLOCK();
  if (iVar15 == 1 || iVar15 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_4c + -0x10) + 4))((undefined4 *)((int)pvStack_4c + -0x10));
  }
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000004);
  ExceptionList = local_c;
  return cStack_52;
}

