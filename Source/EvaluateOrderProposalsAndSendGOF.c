
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall EvaluateOrderProposalsAndSendGOF(void *param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  int *_Memory;
  undefined4 *puVar5;
  int iVar6;
  char cVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  undefined1 auStack_a8 [4];
  undefined4 uStack_a4;
  undefined *local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  int local_5c;
  undefined4 *local_58;
  int local_54;
  int local_4c;
  int local_48 [2];
  void *local_40 [2];
  void *local_38 [4];
  void *local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497e68;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  bVar4 = false;
  FUN_00465870(local_28);
  local_c = 0;
  FUN_00465870(local_38);
  local_64 = (undefined4 *)*DAT_00bb65cc;
  local_c = CONCAT31(local_c._1_3_,1);
  local_68 = &DAT_00bb65c8;
  while( true ) {
    puVar5 = local_64;
    puVar9 = local_68;
    puVar8 = DAT_00bb65cc;
    if ((local_68 == (undefined *)0x0) || (local_68 != &DAT_00bb65c8)) {
      FUN_0047a948();
    }
    if (puVar5 == puVar8) break;
    if (puVar9 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar5 == *(undefined4 **)(puVar9 + 4)) {
      FUN_0047a948();
    }
    if (*(char *)(puVar5 + 8) == '\0') {
      bVar3 = true;
      if (puVar5 == *(undefined4 **)(puVar9 + 4)) {
        FUN_0047a948();
      }
      local_5c = *(int *)puVar5[0xd];
      local_60 = puVar5 + 0xc;
      while( true ) {
        iVar6 = local_5c;
        puVar8 = local_60;
        if (puVar5 == *(undefined4 **)(puVar9 + 4)) {
          FUN_0047a948();
        }
        iVar1 = puVar5[0xd];
        if ((puVar8 == (undefined4 *)0x0) || (puVar8 != puVar5 + 0xc)) {
          FUN_0047a948();
        }
        puVar9 = local_68;
        if (iVar6 == iVar1) break;
        if (puVar5 == *(undefined4 **)(local_68 + 4)) {
          FUN_0047a948();
        }
        local_4c = puVar5[0x10];
        if (puVar8 == (undefined4 *)0x0) {
          FUN_0047a948();
        }
        if (iVar6 == puVar8[1]) {
          FUN_0047a948();
        }
        if (puVar5 == *(undefined4 **)(local_68 + 4)) {
          FUN_0047a948();
        }
        puVar8 = (undefined4 *)GameBoard_GetPowerRec(puVar5 + 0xf,local_48,(int *)(iVar6 + 0xc));
        if (((undefined4 *)*puVar8 == (undefined4 *)0x0) || ((undefined4 *)*puVar8 != puVar5 + 0xf))
        {
          FUN_0047a948();
        }
        if (puVar8[1] == local_4c) {
          bVar3 = false;
        }
        TreeIterator_Advance((int *)&local_60);
        puVar9 = local_68;
      }
      if (bVar3) {
        if (puVar5 == *(undefined4 **)(local_68 + 4)) {
          FUN_0047a948();
        }
        *(undefined1 *)(puVar5 + 8) = 1;
        if (puVar5 == *(undefined4 **)(puVar9 + 4)) {
          FUN_0047a948();
        }
        if (puVar5[0x14] == 0) {
          cVar7 = *(char *)((int)DAT_00bb65e4[1] + 0x11);
          _Memory = DAT_00bb65e4[1];
          while (cVar7 == '\0') {
            FUN_00401950((int *)_Memory[2]);
            piVar2 = (int *)*_Memory;
            _free(_Memory);
            _Memory = piVar2;
            cVar7 = *(char *)((int)piVar2 + 0x11);
          }
          DAT_00bb65e4[1] = (int *)DAT_00bb65e4;
          _DAT_00bb65e8 = 0;
          *DAT_00bb65e4 = (int *)DAT_00bb65e4;
          DAT_00bb65e4[2] = (int *)DAT_00bb65e4;
          if (puVar5 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          if (puVar5 + 0xc != (undefined4 *)&DAT_00bb65e0) {
            uStack_a4 = 0x457755;
            SerializeOrders(&DAT_00bb65e0,local_40,&DAT_00bb65e0,(int **)*DAT_00bb65e4,&DAT_00bb65e0
                            ,DAT_00bb65e4);
            RegisterProposalOrders(&DAT_00bb65e0,(int)(puVar5 + 0xc));
          }
          if (puVar5 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          local_54 = *(int *)puVar5[0x16];
          local_58 = puVar5 + 0x15;
          while( true ) {
            iVar6 = local_54;
            puVar8 = local_58;
            if (puVar5 == *(undefined4 **)(local_68 + 4)) {
              FUN_0047a948();
            }
            iVar1 = puVar5[0x16];
            if ((puVar8 == (undefined4 *)0x0) || (puVar8 != puVar5 + 0x15)) {
              FUN_0047a948();
            }
            if (iVar6 == iVar1) break;
            if (puVar5 == *(undefined4 **)(local_68 + 4)) {
              FUN_0047a948();
            }
            FUN_00405090(&stack0xffffff68,(int)(puVar5 + 0xf));
            local_c = CONCAT31(local_c._1_3_,2);
            if (puVar8 == (undefined4 *)0x0) {
              FUN_0047a948();
            }
            if (iVar6 == puVar8[1]) {
              FUN_0047a948();
            }
            FUN_00465f60(auStack_a8,(void **)(iVar6 + 0xc));
            local_c = CONCAT31(local_c._1_3_,1);
            cVar7 = CAL_MOVE(param_1);
            if (cVar7 == '\x01') {
              bVar4 = true;
            }
            FUN_00401590((int *)&local_58);
          }
        }
      }
    }
    FUN_0040f860((int *)&local_68);
  }
  if (bVar4) {
    NormalizeInfluenceMatrix((int)param_1);
    send_GOF(param_1);
  }
  else {
    ScheduledPressDispatch(param_1);
  }
  local_c = local_c & 0xffffff00;
  FreeList(local_38);
  local_c = 0xffffffff;
  FreeList(local_28);
  ExceptionList = local_14;
  return;
}

