
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall send_GOF(void *param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint **ppuVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  int iVar13;
  uint *puVar14;
  __time64_t _Var15;
  int *piStack_50;
  int iStack_44;
  undefined *puStack_40;
  undefined4 *puStack_3c;
  uint *apuStack_38 [4];
  void *local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497e30;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00465870(local_28);
  uVar10 = (uint)*(byte *)(*(int *)((int)param_1 + 8) + 0x2424);
  local_c = 0;
  FUN_00446630(*(int **)(DAT_00bbf60c + 4));
  *(int *)(DAT_00bbf60c + 4) = DAT_00bbf60c;
  _DAT_00bbf610 = 0;
  *(int *)DAT_00bbf60c = DAT_00bbf60c;
  *(int *)(DAT_00bbf60c + 8) = DAT_00bbf60c;
  FUN_00411b00(*(int **)(DAT_00baed98 + 4));
  *(int *)(DAT_00baed98 + 4) = DAT_00baed98;
  _DAT_00baed9c = 0;
  *(int *)DAT_00baed98 = DAT_00baed98;
  *(int *)(DAT_00baed98 + 8) = DAT_00baed98;
  DAT_00baed34 = 0;
  g_CumScore = 0;
  _DAT_00baed4c = 0;
  _DAT_00baed50 = 0;
  SnapshotProvinceState((int)param_1);
  ResetPerTrialState(*(int *)((int)param_1 + 8));
  sVar2 = *(short *)(*(int *)((int)param_1 + 8) + 0x244a);
  if ((SPR == sVar2) || (SUM == sVar2)) {
    ScoreProvinces(param_1,*(uint *)((int)param_1 + 0x4d18),*(uint *)((int)param_1 + 0x4d1c),
                   *(uint *)((int)param_1 + 0x4d20),*(uint *)((int)param_1 + 0x4d24));
    iVar13 = (int)param_1 + 0x4d38;
LAB_00456d5c:
    ScoreOrderCandidates_AllPowers(param_1,iVar13);
  }
  else {
    if ((FAL == sVar2) || (AUT == sVar2)) {
      ScoreProvinces(param_1,*(uint *)((int)param_1 + 0x4d28),*(uint *)((int)param_1 + 0x4d2c),
                     *(uint *)((int)param_1 + 0x4d30),*(uint *)((int)param_1 + 0x4d34));
      iVar13 = (int)param_1 + 0x4d98;
      goto LAB_00456d5c;
    }
    ScoreProvinces(param_1,*(uint *)((int)param_1 + 0x4d18),*(uint *)((int)param_1 + 0x4d1c),
                   *(uint *)((int)param_1 + 0x4d20),*(uint *)((int)param_1 + 0x4d24));
    if (*(uint *)(*(int *)((int)param_1 + 8) + 0x24e0) <
        *(uint *)(*(int *)((int)param_1 + 8) + 0x24bc)) {
      ScoreOrderCandidates_OwnPower
                (param_1,(int)param_1 + 0x4e58,*(uint *)((int)param_1 + 0x4e50),
                 *(uint *)((int)param_1 + 0x4e54));
    }
    else {
      ScoreOrderCandidates_OwnPower
                (param_1,(int)param_1 + 0x4e00,*(uint *)((int)param_1 + 0x4df8),
                 *(uint *)((int)param_1 + 0x4dfc));
    }
  }
  _Var15 = __time64((__time64_t *)0x0);
  _DAT_00ba2878 = _Var15 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880);
  if ((&DAT_0062e460)[uVar10] == 0) {
LAB_004573b8:
    sVar2 = *(short *)(*(int *)((int)param_1 + 8) + 0x244a);
    if ((SPR == sVar2) || (FAL == sVar2)) {
      DAT_0062cc64 = DAT_004c6bbc;
      goto LAB_004574e6;
    }
  }
  else {
    sVar2 = *(short *)(*(int *)((int)param_1 + 8) + 0x244a);
    if ((SPR == sVar2) || (FAL == sVar2)) {
      ComputeSafeReach((int)param_1);
      EnumerateHoldOrders((int)param_1);
      iVar13 = 0;
      if (0 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404)) {
        piVar11 = &DAT_00bb6cfc;
        do {
          iVar6 = *piVar11;
          (&DAT_00b9fe88)[iVar13] = 0;
          FUN_00410cf0(*(int **)(iVar6 + 4));
          *(int *)(*piVar11 + 4) = *piVar11;
          piVar11[1] = 0;
          *(int *)*piVar11 = *piVar11;
          *(int *)(*piVar11 + 8) = *piVar11;
          iVar13 = iVar13 + 1;
          piVar11 = piVar11 + 3;
        } while (iVar13 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404));
      }
      iStack_44 = 10;
      do {
        uVar7 = 0;
        if (0 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404)) {
          piStack_50 = &DAT_0062e460;
          do {
            if (0 < *piStack_50) {
              iVar13 = (*piStack_50 * DAT_004c6bb8 + 10) / 10;
              DAT_00baed5c = 0;
              if ((DAT_004c6bbc == 0) && (uVar7 != uVar10)) {
                iVar13 = 1;
              }
              ProcessTurn(param_1,uVar7,iVar13);
              puStack_3c = (undefined4 *)*DAT_00baed74;
              puStack_40 = &g_SupportOpportunitiesSet;
              while( true ) {
                puVar9 = puStack_40;
                puVar8 = DAT_00baed74;
                if ((puStack_40 == (undefined *)0x0) || (puStack_40 != &g_SupportOpportunitiesSet))
                {
                  FUN_0047a948();
                }
                if (puStack_3c == puVar8) break;
                if (puVar9 == (undefined *)0x0) {
                  FUN_0047a948();
                }
                if (puStack_3c == *(undefined4 **)(puVar9 + 4)) {
                  FUN_0047a948();
                }
                puVar12 = puStack_3c + 4;
                if (*puVar12 == uVar7) {
                  iVar13 = (*piStack_50 * 10) / 10;
                  DAT_00baed5c = 1;
                  if ((DAT_004c6bbc == 0) && (uVar7 != uVar10)) {
                    iVar13 = 1;
                  }
                  if (puStack_3c == *(undefined4 **)(puVar9 + 4)) {
                    FUN_0047a948();
                  }
                  puVar14 = &DAT_00bbf668;
                  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *puVar14 = *puVar12;
                    puVar12 = puVar12 + 1;
                    puVar14 = puVar14 + 1;
                  }
                  ProcessTurn(param_1,uVar7,iVar13);
                }
                FUN_0040f5f0((int *)&puStack_40);
              }
            }
            piStack_50 = piStack_50 + 1;
            uVar7 = uVar7 + 1;
          } while ((int)uVar7 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404));
        }
        iStack_44 = iStack_44 + -1;
      } while (iStack_44 != 0);
      DAT_0062cc64 = 0;
      puStack_3c = (undefined4 *)*DAT_00bb65f0;
      puStack_40 = &DAT_00bb65ec;
      while( true ) {
        puVar4 = puStack_3c;
        puVar9 = puStack_40;
        puVar8 = DAT_00bb65f0;
        if ((puStack_40 == (undefined *)0x0) || (puStack_40 != &DAT_00bb65ec)) {
          FUN_0047a948();
        }
        if (puVar4 == puVar8) break;
        if (puVar9 == (undefined *)0x0) {
          FUN_0047a948();
        }
        if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
          FUN_0047a948();
        }
        if (puVar4[4] == 0) {
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          puVar4[8] = 0;
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          cVar1 = *(char *)((int)*(int **)(puVar4[0xd] + 4) + 0x1d);
          piVar11 = *(int **)(puVar4[0xd] + 4);
          puVar9 = puStack_40;
          while (puStack_40 = puVar9, cVar1 == '\0') {
            FUN_00410cf0((int *)piVar11[2]);
            piVar3 = (int *)*piVar11;
            FreeList((void **)(piVar11 + 3));
            _free(piVar11);
            piVar11 = piVar3;
            puVar9 = puStack_40;
            cVar1 = *(char *)((int)piVar3 + 0x1d);
          }
          *(undefined4 *)(puVar4[0xd] + 4) = puVar4[0xd];
          puVar4[0xe] = 0;
          *(undefined4 *)puVar4[0xd] = puVar4[0xd];
          *(undefined4 *)(puVar4[0xd] + 8) = puVar4[0xd];
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          puVar4[7] = 0;
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          *(undefined1 *)(puVar4 + 6) = 0;
          ppuVar5 = FUN_00466f80(&SUB,apuStack_38,(void **)&DAT_00bc1e0c);
          local_c._0_1_ = 1;
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          AppendList(puVar4 + 0x28,ppuVar5);
          local_c = (uint)local_c._1_3_ << 8;
          FreeList(apuStack_38);
          iVar13 = 0;
          if (0 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404)) {
            puVar8 = puVar4 + 0x12;
            do {
              if (puVar4 == *(undefined4 **)(puStack_40 + 4)) {
                FUN_0047a948();
              }
              *puVar8 = 0;
              iVar13 = iVar13 + 1;
              puVar8 = puVar8 + 1;
              puVar9 = puStack_40;
            } while (iVar13 < *(int *)(*(int *)((int)param_1 + 8) + 0x2404));
          }
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          *(undefined1 *)(puVar4 + 0x2c) = 0;
          FUN_0040f470((int *)&puStack_40);
        }
        else {
          if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
            FUN_0047a948();
          }
          if (puVar4[7] == 1) {
            if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
              FUN_0047a948();
            }
            puVar4[7] = 0xffffffff;
            if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
              FUN_0047a948();
            }
            puVar4[8] = DAT_004c6bbc;
            if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
              FUN_0047a948();
            }
            *(undefined1 *)(puVar4 + 6) = 1;
            FUN_0040f470((int *)&puStack_40);
          }
          else {
            if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
              FUN_0047a948();
            }
            if (puVar4[7] == 0) {
              if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
                FUN_0047a948();
              }
              if (*(char *)(puVar4 + 6) == '\0') {
                if (puVar4 == *(undefined4 **)(puVar9 + 4)) {
                  FUN_0047a948();
                }
                puVar4[8] = 0;
              }
            }
            FUN_0040f470((int *)&puStack_40);
          }
        }
      }
      _Var15 = __time64((__time64_t *)0x0);
      _DAT_00ba2870 = (_Var15 - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)) - _DAT_00ba2878;
      DAT_0062e4b4 = 0;
      DAT_0062e45c = 0;
      g_ScoreBaseline = 0;
      _DAT_00b95368 = 0;
      _DAT_00b9536c = 0;
      _DAT_00b95370 = 0;
      _DAT_00b95374 = 0;
      _DAT_00b95378 = 0;
      _DAT_00b9537c = 0;
      _DAT_00b95380 = 0;
      _DAT_00b95384 = 0;
      _DAT_00b95388 = 0;
      _DAT_00b9538c = 0;
      _DAT_00b95390 = 0;
      _DAT_00b95394 = 0;
      _DAT_00b95398 = 0;
      _DAT_00b9539c = 0;
      _DAT_00b953a0 = 0;
      _DAT_00b953a4 = 0;
      _DAT_00b953a8 = 0;
      _DAT_00b953ac = 0;
      _DAT_00b953b0 = 0;
      _DAT_00b953b4 = 0;
      _DAT_00b953b8 = 0;
      _DAT_00b953bc = 0;
      _DAT_00b953c0 = 0;
      _DAT_00b953c4 = 0;
      _DAT_00b953c8 = 0;
      _DAT_00b953cc = 0;
      _DAT_00b953d0 = 0;
      _DAT_00b953d4 = 0;
      _DAT_00b953d8 = 0;
      _DAT_00b953dc = 0;
      _DAT_00b953e0 = 0;
      _DAT_00b953e4 = 0;
      _DAT_00b953e8 = 0;
      _DAT_00b953ec = 0;
      _DAT_00b953f0 = 0;
      _DAT_00b953f4 = 0;
      _DAT_00b953f8 = 0;
      _DAT_00b953fc = 0;
      _DAT_00b95400 = 0;
      _DAT_00b95404 = 0;
      _DAT_00b95408 = 0;
      _DAT_00b9540c = 0;
      _DAT_00b95410 = 0;
      _DAT_00b95414 = 0;
      _DAT_00b95418 = 0;
      _DAT_00b9541c = 0;
      _DAT_00b95420 = 0;
      _DAT_00b95424 = 0;
      _DAT_00b95428 = 0;
      _DAT_00b9542c = 0;
      _DAT_00b95430 = 0;
      _DAT_00b95434 = 0;
      _DAT_00b95438 = 0;
      _DAT_00b9543c = 0;
      _DAT_00b95440 = 0;
      _DAT_00b95444 = 0;
      _DAT_00b95448 = 0;
      _DAT_00b9544c = 0;
      _DAT_00b95450 = 0;
      _DAT_00b95454 = 0;
      _DAT_00b95458 = 0;
      _DAT_00b9545c = 0;
      _DAT_00b95460 = 0;
      _DAT_00b95464 = 0;
      _DAT_00b95468 = 0;
      _DAT_00b9546c = 0;
      _DAT_00b95470 = 0;
      _DAT_00b95474 = 0;
      _DAT_00b95478 = 0;
      _DAT_00b9547c = 0;
      _DAT_00b95480 = 0;
      _DAT_00b95484 = 0;
      _DAT_00b95488 = 0;
      _DAT_00b9548c = 0;
      _DAT_00b95490 = 0;
      _DAT_00b95494 = 0;
      _DAT_00b95498 = 0;
      _DAT_00b9549c = 0;
      _DAT_00b954a0 = 0;
      _DAT_00b954a4 = 0;
      _DAT_00b954a8 = 0;
      _DAT_00b954ac = 0;
      _DAT_00b954b0 = 0;
      _DAT_00b954b4 = 0;
      _DAT_00b954b8 = 0;
      _DAT_00b954bc = 0;
      _DAT_00b954c0 = 0;
      _DAT_00b954c4 = 0;
      _DAT_00b954c8 = 0;
      _DAT_00b954cc = 0;
      DAT_00baed46 = 1;
      DAT_00baed6d = 0;
      BuildAndSendSUB(param_1);
    }
    if ((&DAT_0062e460)[uVar10] == 0) goto LAB_004573b8;
  }
  iVar13 = *(int *)((int)param_1 + 8);
  sVar2 = *(short *)(iVar13 + 0x244a);
  if ((SUM == sVar2) || (AUT == sVar2)) {
    FUN_004418e0(param_1);
    if ((0 < DAT_00baed34) && (DAT_00baed32 == '\0')) {
      iVar13 = (DAT_00baed34 + 2) * 2000;
LAB_004574a1:
      iVar6 = _rand();
      Sleep(iVar13 + (iVar6 / 0x17) % 6000);
    }
  }
  else {
    if (WIN != sVar2) goto LAB_004574e6;
    if (*(uint *)(iVar13 + 0x24e0) < *(uint *)(iVar13 + 0x24bc)) {
      FUN_00442040(param_1,*(int *)(iVar13 + 0x24bc) - *(int *)(iVar13 + 0x24e0));
    }
    else if (*(uint *)(iVar13 + 0x24bc) < *(uint *)(iVar13 + 0x24e0)) {
      FUN_0044bd40(param_1,*(int *)(iVar13 + 0x24e0) - *(int *)(iVar13 + 0x24bc));
    }
    if ((0 < DAT_00baed34) && (DAT_00baed32 == '\0')) {
      iVar13 = DAT_00baed34 * 2000 + 5000;
      goto LAB_004574a1;
    }
  }
  FUN_0045aa40(param_1);
  DAT_0062cc64 = DAT_004c6bbc;
  DAT_00baed6d = 1;
LAB_004574e6:
  FUN_00443ed0(param_1);
  local_c = 0xffffffff;
  FreeList(local_28);
  ExceptionList = local_14;
  return;
}

