
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GenerateAndSubmitOrders(void *this,void **param_1)

{
  CStringData *pCVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  int *piVar5;
  void **ppvVar6;
  uint **ppuVar7;
  undefined4 *puVar8;
  CStringData *pCVar9;
  int *piVar10;
  int extraout_ECX;
  int extraout_ECX_00;
  void *extraout_ECX_01;
  int iVar11;
  int iVar12;
  undefined4 *local_20c;
  uint *local_208;
  int *local_204;
  uint local_200;
  uint local_1fc;
  uint *local_1f8 [4];
  int *local_1e8;
  uint *local_1e4;
  CStringData *local_1e0;
  void *local_1d4 [4];
  bool local_1c4 [4];
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined1 local_1b8 [16];
  int local_1a8;
  undefined4 local_1a4;
  int local_19c;
  undefined4 local_198;
  undefined4 auStack_194 [21];
  undefined4 local_140;
  undefined1 local_13c [16];
  undefined1 local_12c;
  undefined8 local_124;
  undefined1 local_11c [16];
  undefined2 local_10c;
  undefined1 local_108 [20];
  void *local_f4 [4];
  int local_e4 [2];
  undefined1 local_dc [208];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004980d5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00465870(local_1d4);
  local_4 = 0;
  FUN_00465870(local_f4);
  local_1fc = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_4._0_1_ = 1;
  FUN_00422960((int)local_1c4);
  local_4._0_1_ = 2;
  _DAT_00ba2880 = __time64((__time64_t *)0x0);
  FUN_00410cb0(*(int **)(DAT_00bb65c0 + 4));
  *(int *)(DAT_00bb65c0 + 4) = DAT_00bb65c0;
  DAT_00bb65c4 = 0;
  *(int *)DAT_00bb65c0 = DAT_00bb65c0;
  *(int *)(DAT_00bb65c0 + 8) = DAT_00bb65c0;
  FUN_00419ed0(*(int **)(g_PressQueue + 4));
  *(undefined **)(g_PressQueue + 4) = g_PressQueue;
  _DAT_00bbf640 = 0;
  *(undefined **)g_PressQueue = g_PressQueue;
  *(undefined **)(g_PressQueue + 8) = g_PressQueue;
  DAT_0062cc64 = 0;
  DAT_00ba2858 = 0;
  DAT_00ba285c = 0;
  AppendList(&DAT_00bbf488,param_1);
  ppvVar6 = (void **)GetSubList(param_1,local_1f8,1);
  local_4._0_1_ = 3;
  AppendList(&DAT_00bc1e0c,ppvVar6);
  local_4._0_1_ = 2;
  FreeList(local_1f8);
  ppuVar7 = FUN_00466f80(&SUB,local_1f8,(void **)&DAT_00bc1e0c);
  local_4._0_1_ = 4;
  AppendList(local_1d4,ppuVar7);
  local_4 = CONCAT31(local_4._1_3_,2);
  FreeList(local_1f8);
  DAT_00baed46 = 0;
  FUN_004303f0(*(int **)(DAT_00bb65cc + 4));
  *(int *)(DAT_00bb65cc + 4) = DAT_00bb65cc;
  _DAT_00bb65d0 = 0;
  *(int *)DAT_00bb65cc = DAT_00bb65cc;
  *(int *)(DAT_00bb65cc + 8) = DAT_00bb65cc;
  std_Tree_DestroyTree(*(int **)(DAT_00bb6f20 + 4));
  *(int *)(DAT_00bb6f20 + 4) = DAT_00bb6f20;
  _DAT_00bb6f24 = 0;
  *(int *)DAT_00bb6f20 = DAT_00bb6f20;
  *(int *)(DAT_00bb6f20 + 8) = DAT_00bb6f20;
  FUN_00430500(*(int **)(DAT_00bb65f0 + 4));
  *(int *)(DAT_00bb65f0 + 4) = DAT_00bb65f0;
  DAT_00bb65f4 = 0;
  *(int *)DAT_00bb65f0 = DAT_00bb65f0;
  *(int *)(DAT_00bb65f0 + 8) = DAT_00bb65f0;
  FUN_00410cf0(*(int **)(DAT_00bb6df8 + 4));
  *(int *)(DAT_00bb6df8 + 4) = DAT_00bb6df8;
  _DAT_00bb6dfc = 0;
  *(int *)DAT_00bb6df8 = DAT_00bb6df8;
  *(int *)(DAT_00bb6df8 + 8) = DAT_00bb6df8;
  FUN_00401950(*(int **)(DAT_00bb7140 + 4));
  *(int *)(DAT_00bb7140 + 4) = DAT_00bb7140;
  _DAT_00bb7144 = 0;
  *(int *)DAT_00bb7140 = DAT_00bb7140;
  *(int *)(DAT_00bb7140 + 8) = DAT_00bb7140;
  DAT_00baed5e = 0;
  DAT_00baed47 = 0;
  iVar12 = *(int *)((int)this + 8);
  if ((*(char *)(iVar12 + 0x2449) == '\0') &&
     ((*(int *)(iVar12 + 0x24bc) != 0 || (*(int *)(iVar12 + 0x24e0) != 0)))) {
    CancelPriorPress(this);
  }
  if (DAT_00baed68 == '\x01') {
    DAT_00baed68 = '\0';
  }
  if (DAT_004c6bdc == '\x01') {
    DAT_00baed68 = '\x01';
    DAT_004c6bdc = '\0';
  }
  if (*(char *)(*(int *)((int)this + 8) + 0x2449) == '\0') {
    uVar4 = *DAT_00bbf618;
    iVar12 = *(int *)(*(int *)((int)this + 8) + 0x2404);
    local_20c = (undefined4 *)0x0;
    do {
      iVar11 = 0;
      puVar8 = local_20c;
      if (0 < iVar12) {
        do {
          *(undefined **)((int)&DAT_00bbf690 + (int)puVar8) = &DAT_00bbf614;
          *(undefined4 *)((int)&DAT_00bbf694 + (int)puVar8) = uVar4;
          *(undefined **)((int)&DAT_00bc0a40 + (int)puVar8) = &DAT_00bbf614;
          *(undefined4 *)((int)&DAT_00bc0a44 + (int)puVar8) = uVar4;
          iVar12 = *(int *)(*(int *)((int)this + 8) + 0x2404);
          iVar11 = iVar11 + 1;
          puVar8 = (undefined4 *)((int)puVar8 + 0xf0);
        } while (iVar11 < iVar12);
      }
      local_20c = (undefined4 *)((int)local_20c + 8);
    } while ((int)local_20c < 0xf0);
    SetGamePhase(this,0);
    local_200 = 0;
    if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
      local_204 = (int *)&g_PressSentMatrix;
      local_1e4 = &g_AllyTrustScore;
      local_1e8 = &g_AllyMatrix;
      iVar12 = 0;
      do {
        (&g_PerPowerFinalScore)[local_200] = 0;
        (&DAT_004d53d8)[local_200 * 2] = 0;
        (&DAT_004d53dc)[local_200 * 2] = 0;
        *(undefined4 *)(&DAT_00ba27b0 + local_200 * 8) = 0;
        *(undefined4 *)(&DAT_00ba27b4 + local_200 * 8) = 0;
        (&DAT_00633768)[local_200] = 0;
        piVar10 = *(int **)(*(int *)((int)&DAT_00bb65fc + iVar12) + 4);
        cVar2 = *(char *)((int)piVar10 + 0x1d);
        while (cVar2 == '\0') {
          FUN_00410cf0((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          FreeList((void **)(piVar10 + 3));
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x1d);
        }
        *(int *)(*(int *)((int)&DAT_00bb65fc + iVar12) + 4) = *(int *)((int)&DAT_00bb65fc + iVar12);
        *(undefined4 *)((int)&DAT_00bb6600 + iVar12) = 0;
        *(undefined4 *)*(undefined4 *)((int)&DAT_00bb65fc + iVar12) =
             *(undefined4 *)((int)&DAT_00bb65fc + iVar12);
        *(int *)(*(int *)((int)&DAT_00bb65fc + iVar12) + 8) = *(int *)((int)&DAT_00bb65fc + iVar12);
        piVar10 = *(int **)(*(int *)((int)&DAT_00bb66fc + iVar12) + 4);
        cVar2 = *(char *)((int)piVar10 + 0x1d);
        while (cVar2 == '\0') {
          FUN_00410cf0((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          FreeList((void **)(piVar10 + 3));
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x1d);
        }
        *(int *)(*(int *)((int)&DAT_00bb66fc + iVar12) + 4) = *(int *)((int)&DAT_00bb66fc + iVar12);
        *(undefined4 *)((int)&DAT_00bb6700 + iVar12) = 0;
        *(undefined4 *)*(undefined4 *)((int)&DAT_00bb66fc + iVar12) =
             *(undefined4 *)((int)&DAT_00bb66fc + iVar12);
        *(int *)(*(int *)((int)&DAT_00bb66fc + iVar12) + 8) = *(int *)((int)&DAT_00bb66fc + iVar12);
        piVar10 = *(int **)(*(int *)((int)&DAT_00bb6bfc + iVar12) + 4);
        cVar2 = *(char *)((int)piVar10 + 0x11);
        while (cVar2 == '\0') {
          FUN_00401950((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x11);
        }
        *(int *)(*(int *)((int)&DAT_00bb6bfc + iVar12) + 4) = *(int *)((int)&DAT_00bb6bfc + iVar12);
        *(undefined4 *)((int)&DAT_00bb6c00 + iVar12) = 0;
        *(undefined4 *)*(undefined4 *)((int)&DAT_00bb6bfc + iVar12) =
             *(undefined4 *)((int)&DAT_00bb6bfc + iVar12);
        *(int *)(*(int *)((int)&DAT_00bb6bfc + iVar12) + 8) = *(int *)((int)&DAT_00bb6bfc + iVar12);
        piVar10 = *(int **)(*(int *)((int)&DAT_00bb69fc + iVar12) + 4);
        cVar2 = *(char *)((int)piVar10 + 0x15);
        while (cVar2 == '\0') {
          FUN_004019f0((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x15);
        }
        *(int *)(*(int *)((int)&DAT_00bb69fc + iVar12) + 4) = *(int *)((int)&DAT_00bb69fc + iVar12);
        *(undefined4 *)((int)&DAT_00bb6a00 + iVar12) = 0;
        *(undefined4 *)*(undefined4 *)((int)&DAT_00bb69fc + iVar12) =
             *(undefined4 *)((int)&DAT_00bb69fc + iVar12);
        *(int *)(*(int *)((int)&DAT_00bb69fc + iVar12) + 8) = *(int *)((int)&DAT_00bb69fc + iVar12);
        piVar10 = *(int **)(*(int *)((int)&DAT_00bb6afc + iVar12) + 4);
        cVar2 = *(char *)((int)piVar10 + 0x11);
        while (cVar2 == '\0') {
          FUN_00401950((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x11);
        }
        *(int *)(*(int *)((int)&DAT_00bb6afc + iVar12) + 4) = *(int *)((int)&DAT_00bb6afc + iVar12);
        *(undefined4 *)((int)&DAT_00bb6b00 + iVar12) = 0;
        *(undefined4 *)*(undefined4 *)((int)&DAT_00bb6afc + iVar12) =
             *(undefined4 *)((int)&DAT_00bb6afc + iVar12);
        *(int *)(*(int *)((int)&DAT_00bb6afc + iVar12) + 8) = *(int *)((int)&DAT_00bb6afc + iVar12);
        iVar11 = 0;
        if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
          local_20c = &g_AllyTrustScore + local_200 * 2;
          piVar10 = local_1e8;
          local_208 = local_1e4;
          do {
            *(undefined1 *)(iVar11 + (int)local_204) = 0;
            if ((local_200 == local_1fc) || ((&curr_sc_cnt)[local_200] != 0)) {
              if ((*piVar10 < 0) &&
                 ((sVar3 = *(short *)(*(int *)((int)this + 8) + 0x244a), SPR == sVar3 ||
                  (FAL == sVar3)))) {
                *piVar10 = *piVar10 + 1;
              }
            }
            else {
              *local_208 = 0;
              local_208[1] = 0;
              *local_20c = 0;
              local_20c[1] = 0;
              *piVar10 = 0;
            }
            local_208 = local_208 + 2;
            local_20c = local_20c + 0x2a;
            iVar11 = iVar11 + 1;
            piVar10 = piVar10 + 1;
          } while (iVar11 < *(int *)(*(int *)((int)this + 8) + 0x2404));
        }
        if ((local_200 != local_1fc) && ((&curr_sc_cnt)[local_200] == 0)) {
          piVar10 = *(int **)(*(int *)((int)&DAT_00bb6f2c + iVar12) + 4);
          cVar2 = *(char *)((int)piVar10 + 0x11);
          while (cVar2 == '\0') {
            FUN_00401950((int *)piVar10[2]);
            piVar5 = (int *)*piVar10;
            _free(piVar10);
            piVar10 = piVar5;
            cVar2 = *(char *)((int)piVar5 + 0x11);
          }
          *(int *)(*(int *)((int)&DAT_00bb6f2c + iVar12) + 4) =
               *(int *)((int)&DAT_00bb6f2c + iVar12);
          *(undefined4 *)((int)&DAT_00bb6f30 + iVar12) = 0;
          *(undefined4 *)*(undefined4 *)((int)&DAT_00bb6f2c + iVar12) =
               *(undefined4 *)((int)&DAT_00bb6f2c + iVar12);
          *(int *)(*(int *)((int)&DAT_00bb6f2c + iVar12) + 8) =
               *(int *)((int)&DAT_00bb6f2c + iVar12);
          piVar10 = *(int **)(*(int *)((int)&DAT_00bb702c + iVar12) + 4);
          cVar2 = *(char *)((int)piVar10 + 0x11);
          while (cVar2 == '\0') {
            FUN_00401950((int *)piVar10[2]);
            piVar5 = (int *)*piVar10;
            _free(piVar10);
            piVar10 = piVar5;
            cVar2 = *(char *)((int)piVar5 + 0x11);
          }
          *(int *)(*(int *)((int)&DAT_00bb702c + iVar12) + 4) =
               *(int *)((int)&DAT_00bb702c + iVar12);
          *(undefined4 *)((int)&DAT_00bb7030 + iVar12) = 0;
          *(undefined4 *)*(undefined4 *)((int)&DAT_00bb702c + iVar12) =
               *(undefined4 *)((int)&DAT_00bb702c + iVar12);
          *(int *)(*(int *)((int)&DAT_00bb702c + iVar12) + 8) =
               *(int *)((int)&DAT_00bb702c + iVar12);
        }
        local_1e8 = local_1e8 + 0x15;
        local_1e4 = local_1e4 + 0x2a;
        local_204 = (int *)((int)local_204 + 0x15);
        local_200 = local_200 + 1;
        iVar12 = iVar12 + 0xc;
      } while ((int)local_200 < *(int *)(*(int *)((int)this + 8) + 0x2404));
    }
    if (SPR == *(short *)(*(int *)((int)this + 8) + 0x244a)) {
      g_DeceitLevel = g_DeceitLevel + 1;
    }
    sVar3 = *(short *)(*(int *)((int)this + 8) + 0x244a);
    if ((SPR == sVar3) || (FAL == sVar3)) {
      analyze_position((int)this);
    }
    if ((((g_DeceitLevel == 1) && (DAT_00baed68 == '\0')) &&
        (FAL == *(short *)(*(int *)((int)this + 8) + 0x244a))) && ((&curr_sc_cnt)[local_1fc] != 0))
    {
      MOVE_ANALYSIS((int)this);
    }
    DAT_00baed6d = 0;
    GenerateOrders((int)this);
    sVar3 = *(short *)(*(int *)((int)this + 8) + 0x244a);
    if ((SPR == sVar3) || (FAL == sVar3)) {
      PostProcessOrders((int)this);
    }
    if (DAT_00baed68 == '\x01') {
      ComputePress((int)this);
    }
    local_124 = CONCAT44(local_124._4_4_,(undefined4)local_124);
    if (((&curr_sc_cnt)[local_1fc] != 0) &&
       (local_124 = CONCAT44(local_124._4_4_,(undefined4)local_124), DAT_00baed33 == '\0')) {
      FormatDebugMsg(&local_204,"Initiation of Alliance Debug");
      local_4._0_1_ = 5;
      local_1e4 = (uint *)0x0;
      pCVar9 = ATL::CSimpleStringT<char,0>::CloneData((CStringData *)(local_204 + -4));
      local_1e0 = pCVar9 + 0x10;
      local_4._0_1_ = 6;
      BuildAllianceMsg(&DAT_00bbf638,local_1f8,(int *)&local_1e4);
      local_4._0_1_ = 5;
      pCVar1 = pCVar9 + 0xc;
      LOCK();
      iVar12 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + -1;
      UNLOCK();
      if (iVar12 == 1 || iVar12 + -1 < 0) {
        (**(code **)(**(int **)pCVar9 + 4))(pCVar9);
      }
      local_4 = CONCAT31(local_4._1_3_,2);
      piVar10 = local_204 + -1;
      LOCK();
      iVar12 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
      if (iVar12 == 1 || iVar12 + -1 < 0) {
        (**(code **)(*(int *)local_204[-4] + 4))(local_204 + -4);
      }
      if (((g_DeceitLevel < 2) &&
          (sVar3 = *(short *)(*(int *)((int)this + 8) + 0x244a), AUT != sVar3)) && (WIN != sVar3)) {
        if ((g_DeceitLevel == 1) && (SPR != sVar3)) {
          STABBED((int)this);
        }
      }
      else {
        DEVIATE_MOVE((int)this);
      }
      local_1e4 = (uint *)0x0;
      if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
        local_20c = (undefined4 *)0x0;
        do {
          piVar10 = *(int **)(*(int *)(&DAT_00bb67fc + (int)local_20c) + 4);
          cVar2 = *(char *)((int)piVar10 + 0x15);
          while (cVar2 == '\0') {
            local_204 = piVar10;
            FUN_004019f0((int *)piVar10[2]);
            piVar10 = (int *)*piVar10;
            _free(local_204);
            cVar2 = *(char *)((int)piVar10 + 0x15);
          }
          *(int *)(*(int *)(&DAT_00bb67fc + (int)local_20c) + 4) =
               *(int *)(&DAT_00bb67fc + (int)local_20c);
          *(undefined4 *)(&DAT_00bb6800 + (int)local_20c) = 0;
          *(undefined4 *)*(undefined4 *)(&DAT_00bb67fc + (int)local_20c) =
               *(undefined4 *)(&DAT_00bb67fc + (int)local_20c);
          *(int *)(*(int *)(&DAT_00bb67fc + (int)local_20c) + 8) =
               *(int *)(&DAT_00bb67fc + (int)local_20c);
          piVar10 = *(int **)(*(int *)(&DAT_00bb68fc + (int)local_20c) + 4);
          cVar2 = *(char *)((int)piVar10 + 0x19);
          while (local_204 = piVar10, cVar2 == '\0') {
            FUN_0040fb70((int *)piVar10[2]);
            piVar10 = (int *)*piVar10;
            _free(local_204);
            cVar2 = *(char *)((int)piVar10 + 0x19);
          }
          *(int *)(*(int *)(&DAT_00bb68fc + (int)local_20c) + 4) =
               *(int *)(&DAT_00bb68fc + (int)local_20c);
          *(undefined4 *)(&DAT_00bb6900 + (int)local_20c) = 0;
          *(undefined4 *)*(undefined4 *)(&DAT_00bb68fc + (int)local_20c) =
               *(undefined4 *)(&DAT_00bb68fc + (int)local_20c);
          *(int *)(*(int *)(&DAT_00bb68fc + (int)local_20c) + 8) =
               *(int *)(&DAT_00bb68fc + (int)local_20c);
          local_1e4 = (uint *)((int)local_1e4 + 1);
          local_20c = (undefined4 *)((int)local_20c + 0xc);
        } while ((int)local_1e4 < *(int *)(*(int *)((int)this + 8) + 0x2404));
      }
      SetGamePhase(this,1);
      FRIENDLY(extraout_ECX);
      SetGamePhase(this,2);
      ComputeInfluenceMatrix(extraout_ECX_00);
      sVar3 = *(short *)(*(int *)((int)this + 8) + 0x244a);
      if ((SPR == sVar3) || (FAL == sVar3)) {
        if ((&DAT_0062e460)[local_1fc] != 0) {
          local_1bc = 0;
        }
        else {
          local_1bc = DAT_004c6bbc;
        }
        local_1c4[0] = (&DAT_0062e460)[local_1fc] == 0;
        cVar2 = *(char *)((int)*(int **)(local_1a8 + 4) + 0x1d);
        piVar10 = *(int **)(local_1a8 + 4);
        while (cVar2 == '\0') {
          FUN_00410cf0((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          FreeList((void **)(piVar10 + 3));
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x1d);
        }
        *(int *)(local_1a8 + 4) = local_1a8;
        local_1a4 = 0;
        *(int *)local_1a8 = local_1a8;
        *(int *)(local_1a8 + 8) = local_1a8;
        cVar2 = *(char *)((int)*(int **)(local_19c + 4) + 0x1d);
        piVar10 = *(int **)(local_19c + 4);
        while (cVar2 == '\0') {
          FUN_00410cf0((int *)piVar10[2]);
          piVar5 = (int *)*piVar10;
          FreeList((void **)(piVar10 + 3));
          _free(piVar10);
          piVar10 = piVar5;
          cVar2 = *(char *)((int)piVar5 + 0x1d);
        }
        *(int *)(local_19c + 4) = local_19c;
        local_198 = 0;
        *(int *)local_19c = local_19c;
        *(int *)(local_19c + 8) = local_19c;
        local_1c0 = 0;
        ppuVar7 = FUN_00466f80(&SUB,local_1f8,(void **)&DAT_00bc1e0c);
        local_4._0_1_ = 7;
        AppendList(local_13c,ppuVar7);
        local_4 = CONCAT31(local_4._1_3_,2);
        FreeList(local_1f8);
        local_204 = (int *)0x0;
        if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
          do {
            piVar10 = local_204;
            StdMap_FindOrInsert(local_1b8,local_1f8,(int *)&local_204);
            iVar12 = *(int *)((int)this + 8);
            auStack_194[(int)piVar10] = 0;
            local_204 = (int *)((int)piVar10 + 1);
          } while ((int)local_204 < *(int *)(iVar12 + 0x2404));
        }
        local_12c = 0;
        local_140 = 0xffffffff;
        FUN_00465f30(local_1f8,&OFF);
        local_4._0_1_ = 8;
        AppendList(local_11c,local_1f8);
        local_4._0_1_ = 2;
        FreeList(local_1f8);
        local_10c = OFF;
        FUN_00465f30(local_1f8,&OFF);
        local_4._0_1_ = 9;
        AppendList(local_108,local_1f8);
        local_4._0_1_ = 2;
        FreeList(local_1f8);
        local_124 = __time64((__time64_t *)0x0);
        local_e4[0] = 0;
        BuildHostilityRecord(local_dc,local_1c4);
        local_4._0_1_ = 10;
        SendAlliancePress(&DAT_00bb65ec,local_1f8,local_e4);
        local_4._0_1_ = 2;
        DestroyAllianceRecord((int)local_dc);
        HOSTILITY((int)this);
        SetGamePhase(this,3);
        PrepareDrawVoteSet(extraout_ECX_01);
        if ((((DAT_00baed29 == '\x01') || (DAT_00baed2a == '\x01')) || (DAT_00baed2b == '\x01')) ||
           (DAT_00baed30 == '\x01')) {
          FUN_00465870(local_1f8);
          local_4._0_1_ = 0xb;
          FUN_00465f30(&local_1e4,&DRW);
          local_4._0_1_ = 0xc;
          AppendList(local_1f8,&local_1e4);
          local_4 = CONCAT31(local_4._1_3_,0xb);
          FreeList(&local_1e4);
          SendDM(this,local_1f8);
          DAT_00baed5d = 1;
        }
        else {
          FUN_00465870(local_1f8);
          local_4._0_1_ = 0xe;
          ppuVar7 = FUN_00466ed0(&NOT,&local_1e4,&DRW);
          local_4._0_1_ = 0x10;
          AppendList(local_1f8,ppuVar7);
          local_4 = CONCAT31(local_4._1_3_,0xe);
          FreeList(&local_1e4);
          SendDM(this,local_1f8);
          DAT_00baed5d = 0;
        }
        local_4 = CONCAT31(local_4._1_3_,2);
        FreeList(local_1f8);
      }
      else {
        if (WIN == sVar3) {
          HOSTILITY((int)this);
        }
        SetGamePhase(this,3);
      }
    }
    NormalizeInfluenceMatrix((int)this);
    send_GOF(this);
  }
  local_4._0_1_ = 1;
  DestroyAllianceRecord((int)local_1c4);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_f4);
  local_4 = 0xffffffff;
  FreeList(local_1d4);
  ExceptionList = local_c;
  return;
}

