
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall ScheduledPressDispatch(void *param_1)

{
  longlong lVar1;
  int **ppiVar2;
  undefined *puVar3;
  int **ppiVar4;
  short *psVar5;
  void **ppvVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  __time64_t _Var10;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined2 local_78;
  undefined2 local_76;
  void *local_74;
  undefined *local_70;
  int **local_6c;
  undefined8 local_68;
  int local_60 [2];
  void *local_58 [4];
  void *local_48 [4];
  void *local_38 [4];
  void *local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497710;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_74 = param_1;
  FUN_00465870(local_58);
  local_c = 0;
  FUN_00465870(local_48);
  local_c = CONCAT31(local_c._1_3_,1);
  _Var10 = __time64((__time64_t *)0x0);
  local_68 = _Var10 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
  do {
    local_6c = (int **)*DAT_00bb65c0;
    local_70 = &DAT_00bb65bc;
    while( true ) {
      ppiVar4 = local_6c;
      puVar3 = local_70;
      ppiVar2 = DAT_00bb65c0;
      if ((local_70 == (undefined *)0x0) || (local_70 != &DAT_00bb65bc)) {
        FUN_0047a948();
      }
      if (ppiVar4 == ppiVar2) {
        local_c = local_c & 0xffffff00;
        FreeList(local_48);
        local_c = 0xffffffff;
        FreeList(local_58);
        ExceptionList = local_14;
        return;
      }
      if (puVar3 == (undefined *)0x0) {
        FUN_0047a948();
      }
      lVar1 = local_68;
      if (ppiVar4 == *(int ***)(puVar3 + 4)) {
        FUN_0047a948();
        lVar1 = local_68;
      }
      local_68._4_4_ = (int)((ulonglong)lVar1 >> 0x20);
      local_68._0_4_ = (int *)lVar1;
      local_68 = lVar1;
      if (((int)ppiVar4[5] <= local_68._4_4_) &&
         (((int)ppiVar4[5] < local_68._4_4_ || (ppiVar4[4] <= (int *)local_68)))) break;
      FUN_0040e210((int *)&local_70);
    }
    if (ppiVar4 == *(int ***)(puVar3 + 4)) {
      FUN_0047a948();
    }
    psVar5 = (short *)GetListElement(ppiVar4 + 6,&local_7c,0);
    if (SND == *psVar5) {
      if (ppiVar4 == *(int ***)(puVar3 + 4)) {
        FUN_0047a948();
      }
      SendDM(param_1,ppiVar4 + 6);
      if (ppiVar4 == *(int ***)(puVar3 + 4)) {
        FUN_0047a948();
      }
      ppvVar6 = (void **)GetSubList(ppiVar4 + 6,local_38,2);
      local_c._0_1_ = 2;
      AppendList(local_58,ppvVar6);
      local_c = CONCAT31(local_c._1_3_,1);
      FreeList(local_38);
      uVar7 = FUN_00465930((int)local_58);
      iVar9 = 0;
      if (0 < (int)uVar7) {
        do {
          pbVar8 = (byte *)GetListElement(local_58,&local_7a,iVar9);
          SendAllyPressByPower(*pbVar8);
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar7);
      }
    }
    else {
      if (ppiVar4 == *(int ***)(puVar3 + 4)) {
        FUN_0047a948();
      }
      psVar5 = (short *)GetListElement(ppiVar4 + 6,&local_78,0);
      if (THN == *psVar5) {
        if (ppiVar4 == *(int ***)(puVar3 + 4)) {
          FUN_0047a948();
        }
        ppvVar6 = (void **)GetSubList(ppiVar4 + 6,local_28,1);
        local_c._0_1_ = 3;
        AppendList(local_48,ppvVar6);
        local_c = CONCAT31(local_c._1_3_,1);
        FreeList(local_28);
        pbVar8 = (byte *)GetListElement(local_48,&local_76,0);
        ExecuteThennAction(param_1,(uint *)(uint)*pbVar8);
      }
    }
    AdvanceAndRemoveListNode(&DAT_00bb65bc,local_60,(int)puVar3,ppiVar4);
    param_1 = local_74;
  } while( true );
}

