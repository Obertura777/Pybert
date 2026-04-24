
char __fastcall CANCEL(int param_1)

{
  char cVar1;
  int *piVar2;
  void *_Src;
  uint uVar3;
  int *piVar4;
  int iVar5;
  void **ppvVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  rsize_t _DstSize;
  int iVar9;
  uint uVar10;
  int iVar11;
  char cStack_59;
  undefined2 uStack_58;
  undefined2 uStack_56;
  void *pvStack_54;
  int iStack_50;
  int iStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  int *piStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  uint uStack_20;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00495840;
  local_c = ExceptionList;
  uVar3 = DAT_004c8db8 ^ (uint)&stack0xffffff94;
  ExceptionList = &local_c;
  local_4 = 0;
  FUN_00465f60(local_1c,(void **)&stack0x00000004);
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar4 = FUN_0047020b();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*piVar4 + 0xc))(uVar3);
  pvStack_54 = (void *)(iVar5 + 0x10);
  uStack_44 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0x2424);
  local_4._0_1_ = 2;
  cStack_59 = '\0';
  ppvVar6 = (void **)GetSubList(&stack0x00000004,&pvStack_38,1);
  local_4._0_1_ = 3;
  AppendList(&stack0x00000004,ppvVar6);
  local_4._0_1_ = 2;
  FreeList(&pvStack_38);
  uVar3 = FUN_00465930((int)&stack0x00000004);
  iVar5 = 0;
  uStack_40 = uVar3;
  if (0 < (int)uVar3) {
    do {
      GetListElement(&stack0x00000004,&uStack_58,iVar5);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar3);
  }
  iStack_4c = 0;
  if (0 < (int)uVar3) {
    do {
      iVar5 = iStack_4c;
      pbVar7 = (byte *)GetListElement(&stack0x00000004,&uStack_58,iStack_4c);
      uStack_48 = (uint)*pbVar7;
      iStack_50 = 0;
      do {
        iVar11 = iStack_50;
        pbVar7 = (byte *)GetListElement(&stack0x00000004,&uStack_56,iStack_50);
        uVar10 = (uint)*pbVar7;
        if (iVar5 != iVar11) {
          iVar9 = uStack_48 * 0x15 + uVar10;
          if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar9 * 2]) &&
             ((0 < (int)(&g_AllyTrustScore_Hi)[iVar9 * 2] || ((&g_AllyTrustScore)[iVar9 * 2] != 0)))
             ) {
            (&g_AllyTrustScore)[iVar9 * 2] = 0;
            (&g_AllyTrustScore_Hi)[iVar9 * 2] = 0;
            cStack_59 = '\x01';
          }
          if (uStack_48 == uStack_44) {
            if (((&DAT_00bb6f30)[uVar10 * 3] != 0) || ((&DAT_00bb7030)[uVar10 * 3] != 0)) {
              cStack_59 = '\x01';
            }
            cVar1 = *(char *)((int)*(int **)((&DAT_00bb6f2c)[uVar10 * 3] + 4) + 0x11);
            piVar4 = *(int **)((&DAT_00bb6f2c)[uVar10 * 3] + 4);
            while (cVar1 == '\0') {
              FUN_00401950((int *)piVar4[2]);
              piVar2 = (int *)*piVar4;
              _free(piVar4);
              piVar4 = piVar2;
              cVar1 = *(char *)((int)piVar2 + 0x11);
            }
            *(undefined4 *)((&DAT_00bb6f2c)[uVar10 * 3] + 4) = (&DAT_00bb6f2c)[uVar10 * 3];
            (&DAT_00bb6f30)[uVar10 * 3] = 0;
            *(undefined4 *)(&DAT_00bb6f2c)[uVar10 * 3] = (&DAT_00bb6f2c)[uVar10 * 3];
            *(undefined4 *)((&DAT_00bb6f2c)[uVar10 * 3] + 8) = (&DAT_00bb6f2c)[uVar10 * 3];
            cVar1 = *(char *)((int)*(int **)((&DAT_00bb702c)[uVar10 * 3] + 4) + 0x11);
            piVar4 = *(int **)((&DAT_00bb702c)[uVar10 * 3] + 4);
            iVar11 = iStack_50;
            iVar5 = iStack_4c;
            uVar3 = uStack_40;
            while (iStack_4c = iVar5, uStack_40 = uVar3, cVar1 == '\0') {
              iStack_50 = iVar11;
              FUN_00401950((int *)piVar4[2]);
              piVar2 = (int *)*piVar4;
              _free(piVar4);
              piVar4 = piVar2;
              iVar11 = iStack_50;
              iVar5 = iStack_4c;
              uVar3 = uStack_40;
              cVar1 = *(char *)((int)piVar2 + 0x11);
            }
            *(undefined4 *)((&DAT_00bb702c)[uVar10 * 3] + 4) = (&DAT_00bb702c)[uVar10 * 3];
            (&DAT_00bb7030)[uVar10 * 3] = 0;
            *(undefined4 *)(&DAT_00bb702c)[uVar10 * 3] = (&DAT_00bb702c)[uVar10 * 3];
            *(undefined4 *)((&DAT_00bb702c)[uVar10 * 3] + 8) = (&DAT_00bb702c)[uVar10 * 3];
          }
        }
        iStack_50 = iVar11 + 1;
      } while (iStack_50 < (int)uVar3);
      iStack_4c = iVar5 + 1;
    } while (iStack_4c < (int)uVar3);
    if (cStack_59 == '\x01') {
      FUN_0046b050(local_1c,&pvStack_38);
      local_4._0_1_ = 4;
      SEND_LOG(&pvStack_54,L"Recalculating: Because we are CANCELLING: (%s)");
      local_4 = CONCAT31(local_4._1_3_,2);
      if (0xf < uStack_20) {
        _free(pvStack_34);
      }
      _Src = pvStack_54;
      piVar4 = (int *)((int)pvStack_54 + -0x10);
      uStack_40 = 0x66;
      puVar8 = (undefined4 *)(**(code **)(**(int **)((int)pvStack_54 + -0x10) + 0x10))();
      if ((*(int *)((int)_Src + -4) < 0) || (puVar8 != (undefined4 *)*piVar4)) {
        piVar4 = (int *)(**(code **)*puVar8)(*(undefined4 *)((int)_Src + -0xc),1);
        if (piVar4 == (int *)0x0) {
          ErrorExit();
        }
        piVar4[1] = *(int *)((int)_Src + -0xc);
        _DstSize = *(int *)((int)_Src + -0xc) + 1;
        _memcpy_s(piVar4 + 4,_DstSize,_Src,_DstSize);
      }
      else {
        LOCK();
        *(int *)((int)_Src + -4) = *(int *)((int)_Src + -4) + 1;
        UNLOCK();
      }
      piStack_3c = piVar4 + 4;
      local_4._0_1_ = 5;
      BuildAllianceMsg(&DAT_00bbf638,&pvStack_38,(int *)&uStack_40);
      local_4._0_1_ = 2;
      piVar2 = piVar4 + 3;
      LOCK();
      iVar5 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar5 + -1 < 1) {
        (**(code **)(*(int *)*piVar4 + 4))(piVar4);
      }
    }
  }
  local_4._0_1_ = 1;
  piVar4 = (int *)((int)pvStack_54 + -4);
  LOCK();
  iVar5 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)((int)pvStack_54 + -0x10) + 4))((undefined4 *)((int)pvStack_54 + -0x10));
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_1c);
  local_4 = 0xffffffff;
  FreeList((void **)&stack0x00000004);
  ExceptionList = local_c;
  return cStack_59;
}

