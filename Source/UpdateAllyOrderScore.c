
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall UpdateAllyOrderScore(void *this,int **param_1)

{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int **ppiVar12;
  int **ppiVar13;
  undefined4 *puVar14;
  int *piVar15;
  int **local_b5c;
  int *local_b58;
  int **local_b54;
  void *local_b50;
  int local_b4c;
  int local_b48;
  int *local_b44;
  undefined *local_b40;
  undefined4 *local_b3c;
  undefined4 *local_b38;
  int local_b34;
  int **local_b30;
  int *local_b2c;
  undefined *local_b28;
  undefined4 *local_b24;
  int **local_b20;
  undefined *local_b1c;
  undefined4 *local_b18;
  undefined1 local_b14 [4];
  int **local_b10;
  undefined4 local_b0c;
  uint local_b08;
  int *local_b04;
  int local_b00;
  int **local_afc;
  undefined4 local_af8;
  undefined4 *local_af4;
  int *local_af0;
  int *local_aec;
  int *local_ae8;
  undefined2 local_ae4;
  undefined4 *local_adc;
  undefined4 *local_ad4;
  undefined4 *local_acc;
  undefined4 *local_ac4;
  int *local_abc;
  void *local_ab8 [3];
  int local_aac;
  int *local_aa4;
  int *local_a9c;
  int local_a94;
  int *local_a8c;
  int local_a88 [2];
  void *local_a80 [4];
  int local_a70 [2];
  void *local_a68 [4];
  undefined4 local_a58 [3];
  undefined4 local_a4c [3];
  int *apiStack_a40 [256];
  int *apiStack_640 [258];
  void *local_238;
  undefined4 local_228;
  uint local_224;
  undefined1 local_220 [516];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00497775;
  local_14 = ExceptionList;
  local_1c = DAT_004c8db8 ^ (uint)&local_b5c;
  ExceptionList = &local_14;
  local_b50 = this;
  local_b10 = (int **)FUN_004103b0();
  *(undefined1 *)((int)local_b10 + 0x21) = 1;
  local_b10[1] = (int *)local_b10;
  *local_b10 = (int *)local_b10;
  local_b10[2] = (int *)local_b10;
  local_b0c = 0;
  local_c = 0;
  FUN_00465870(local_a80);
  local_224 = 0xf;
  local_228 = 0;
  local_238 = (void *)((uint)local_238 & 0xffffff00);
  local_c._0_1_ = 2;
  FUN_00465870(local_a68);
  local_c._0_1_ = 3;
  if (DAT_0062cc64 < 8) {
    local_b08 = DAT_0062cc64 + 4;
  }
  else {
    local_b08 = 0x1e;
  }
  `eh_vector_constructor_iterator'(local_220,2,0x100,FUN_00401040,ClearConvoyState);
  local_c = CONCAT31(local_c._1_3_,4);
  FUN_0045ff80(*(undefined4 *)((int)this + 8),0,0);
  local_b18 = (undefined4 *)*DAT_00bbf60c;
  local_b1c = &g_CandidateRecordList;
  do {
    puVar3 = local_b1c;
    local_acc = DAT_00bbf60c;
    if ((local_b1c == (undefined *)0x0) || (local_b1c != &g_CandidateRecordList)) {
      FUN_0047a948();
    }
    if (local_b18 == local_acc) {
      FUN_00424850((int *)param_1,'\x01');
      local_c._0_1_ = 3;
      `eh_vector_destructor_iterator'(local_220,2,0x100,ClearConvoyState);
      local_c = CONCAT31(local_c._1_3_,2);
      FreeList(local_a68);
      if (0xf < local_224) {
        _free(local_238);
      }
      local_224 = 0xf;
      local_228 = 0;
      local_238 = (void *)((uint)local_238 & 0xffffff00);
      local_c = local_c & 0xffffff00;
      FreeList(local_a80);
      local_c = 0xffffffff;
      FUN_004150e0(local_b14,local_ab8,local_b14,(int **)*local_b10,local_b14,local_b10);
      _free(local_b10);
      ExceptionList = local_14;
      @__security_check_cookie@4(local_1c ^ (uint)&local_b5c);
      return;
    }
    if (puVar3 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (local_b18 == *(undefined4 **)(puVar3 + 4)) {
      FUN_0047a948();
    }
    if ((int **)local_b18[7] == param_1) {
      if (local_b18 == *(undefined4 **)(puVar3 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(local_b18 + 0x14) == '\0') {
        local_b24 = (undefined4 *)*DAT_00baed80;
        local_b28 = &DAT_00baed7c;
        while( true ) {
          puVar7 = DAT_00baed80;
          iVar11 = 0;
          if ((local_b28 == (undefined *)0x0) || (local_b28 != &DAT_00baed7c)) {
            FUN_0047a948();
          }
          iVar9 = *(int *)((int)this + 8);
          if (local_b24 == puVar7) break;
          if (0 < *(int *)(iVar9 + 0x2404)) {
            puVar7 = local_b24 + 0x1a;
            do {
              if (local_b28 == (undefined *)0x0) {
                FUN_0047a948();
              }
              if (local_b24 == *(undefined4 **)(local_b28 + 4)) {
                FUN_0047a948();
              }
              *puVar7 = 0;
              iVar11 = iVar11 + 1;
              puVar7 = puVar7 + 1;
            } while (iVar11 < *(int *)(*(int *)((int)this + 8) + 0x2404));
          }
          FUN_0040f380((int *)&local_b28);
        }
        iVar11 = 0;
        if (0 < *(int *)(iVar9 + 0x2400)) {
          iVar9 = *(int *)(iVar9 + 0x2404);
          do {
            iVar10 = 0;
            if (0 < iVar9) {
              iVar6 = iVar11 * 4;
              do {
                *(undefined4 *)((int)&DAT_00b9a980 + iVar6) = 0;
                *(undefined4 *)((int)&DAT_00b95580 + iVar6) = 0;
                iVar9 = *(int *)(*(int *)((int)this + 8) + 0x2404);
                iVar10 = iVar10 + 1;
                iVar6 = iVar6 + 0x400;
              } while (iVar10 < iVar9);
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < *(int *)(*(int *)((int)this + 8) + 0x2400));
        }
        iVar11 = 0;
        if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
          do {
            (&DAT_00b9fe30)[iVar11] = 0;
            iVar11 = iVar11 + 1;
          } while (iVar11 < *(int *)(*(int *)((int)this + 8) + 0x2404));
        }
        cVar1 = *(char *)((int)DAT_00bbf660[1] + 0x19);
        piVar8 = (int *)DAT_00bbf660[1];
        while (cVar1 == '\0') {
          FUN_0040fb70((int *)piVar8[2]);
          piVar15 = (int *)*piVar8;
          _free(piVar8);
          piVar8 = piVar15;
          cVar1 = *(char *)((int)piVar15 + 0x19);
        }
        DAT_00bbf660[1] = DAT_00bbf660;
        _DAT_00bbf664 = 0;
        *DAT_00bbf660 = DAT_00bbf660;
        DAT_00bbf660[2] = DAT_00bbf660;
        local_b54 = (int **)0x0;
        if (0 < (int)local_b08) {
          local_b44 = &DAT_00bbf690;
          do {
            ppiVar12 = (int **)0x0;
            iVar11 = 0;
            local_b5c = (int **)0x0;
            piVar8 = local_b44;
            ppiVar13 = local_b5c;
            if (0 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404)) {
              do {
                if (*piVar8 == 0) {
                  FUN_0047a948();
                }
                if (piVar8[1] == *(int *)(*piVar8 + 4)) {
                  FUN_0047a948();
                }
                ppiVar12 = (int **)((int)ppiVar12 + *(int *)(piVar8[1] + 0x1c8 + (int)param_1 * 4));
                iVar11 = iVar11 + 1;
                piVar8 = piVar8 + 0x3c;
                ppiVar13 = ppiVar12;
              } while (iVar11 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404));
            }
            local_b5c = ppiVar13;
            ppiVar13 = local_b5c;
            puVar7 = (undefined4 *)FUN_00410ad0(&DAT_00bbf65c,local_a70,(int *)&local_b5c);
            puVar3 = (undefined *)*puVar7;
            puVar7 = (undefined4 *)puVar7[1];
            local_ad4 = DAT_00bbf660;
            if ((puVar3 == (undefined *)0x0) || (puVar3 != &DAT_00bbf65c)) {
              FUN_0047a948();
            }
            if (puVar7 == local_ad4) {
              local_af8 = 1;
              local_af4 = local_b54;
              local_afc = ppiVar13;
              FUN_00419f30(&DAT_00bbf65c,local_a58,(int *)&local_afc);
            }
            else {
              if (puVar3 == (undefined *)0x0) {
                FUN_0047a948();
              }
              if (puVar7 == *(undefined4 **)(puVar3 + 4)) {
                FUN_0047a948();
              }
              puVar7[4] = puVar7[4] + 1;
            }
            local_b44 = local_b44 + 2;
            local_b54 = (int **)((int)local_b54 + 1);
          } while ((int)local_b54 < (int)local_b08);
        }
        DAT_0062e4b4 = DAT_0062e4b4 + local_b08;
        local_b3c = (undefined4 *)*DAT_00bbf660;
        local_b40 = &DAT_00bbf65c;
        while( true ) {
          puVar14 = local_b3c;
          puVar3 = local_b40;
          puVar7 = DAT_00bbf660;
          if ((local_b40 == (undefined *)0x0) || (local_b40 != &DAT_00bbf65c)) {
            FUN_0047a948();
          }
          if (puVar14 == puVar7) break;
          if (puVar3 == (undefined *)0x0) {
            FUN_0047a948();
          }
          if (puVar14 == *(undefined4 **)(puVar3 + 4)) {
            FUN_0047a948();
          }
          DAT_0062e45c = DAT_0062e45c + -1 + puVar14[4];
          iVar11 = *(int *)((int)local_b50 + 8);
          iVar9 = *(int *)(iVar11 + 0x2400);
          iVar10 = 0;
          if (0 < iVar9) {
            do {
              apiStack_a40[iVar10] = (int *)0x0;
              apiStack_640[iVar10] = (int *)0x0;
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar9);
          }
          local_b54 = (int **)0x0;
          if (0 < *(int *)(iVar11 + 0x2404)) {
            local_b44 = (int *)0x0;
            do {
              if ((local_b54 != param_1) && (0 < (int)(&DAT_0062e460)[(int)local_b54])) {
                if (puVar14 == *(undefined4 **)(local_b40 + 4)) {
                  FUN_0047a948();
                }
                iVar11 = puVar14[5] + (int)local_b44;
                if ((&DAT_00bbf690)[iVar11 * 2] == 0) {
                  FUN_0047a948();
                }
                if ((&DAT_00bbf694)[iVar11 * 2] == *(int *)((&DAT_00bbf690)[iVar11 * 2] + 4)) {
                  FUN_0047a948();
                }
                local_b34 = **(int **)((&DAT_00bbf694)[iVar11 * 2] + 0x620);
                local_b38 = (undefined4 *)((&DAT_00bbf694)[iVar11 * 2] + 0x61c);
                while( true ) {
                  puVar7 = local_b38;
                  if (puVar14 == *(undefined4 **)(local_b40 + 4)) {
                    FUN_0047a948();
                  }
                  iVar11 = puVar14[5] + (int)local_b44;
                  if ((&DAT_00bbf690)[iVar11 * 2] == 0) {
                    FUN_0047a948();
                  }
                  if ((&DAT_00bbf694)[iVar11 * 2] == *(int *)((&DAT_00bbf690)[iVar11 * 2] + 4)) {
                    FUN_0047a948();
                  }
                  iVar9 = *(int *)((&DAT_00bbf694)[iVar11 * 2] + 0x620);
                  if ((puVar7 == (undefined4 *)0x0) ||
                     (puVar7 != (undefined4 *)((&DAT_00bbf694)[iVar11 * 2] + 0x61c))) {
                    FUN_0047a948();
                  }
                  if (local_b34 == iVar9) break;
                  if (puVar7 == (undefined4 *)0x0) {
                    FUN_0047a948();
                  }
                  if (local_b34 == puVar7[1]) {
                    FUN_0047a948();
                  }
                  iVar9 = local_b34;
                  local_b58 = (int *)(local_b34 + 0xc);
                  piVar8 = (int *)OrderedSet_FindOrInsert
                                            ((void *)(*(int *)((int)local_b50 + 8) + 0x2450),
                                             local_a88,local_b58);
                  local_b4c = *piVar8;
                  iVar11 = piVar8[1];
                  if (local_b34 == puVar7[1]) {
                    FUN_0047a948();
                  }
                  if (local_b4c == 0) {
                    FUN_0047a948();
                  }
                  if (iVar11 == *(int *)(local_b4c + 4)) {
                    FUN_0047a948();
                  }
                  *(undefined4 *)(iVar11 + 0x20) = *(undefined4 *)(iVar9 + 0x10);
                  if (iVar11 == *(int *)(local_b4c + 4)) {
                    FUN_0047a948();
                  }
                  switch(*(undefined4 *)(iVar11 + 0x20)) {
                  case 2:
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar11 + 0x2c) = *(undefined4 *)(iVar9 + 0x1c);
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar11 + 0x24) = *(undefined4 *)(iVar9 + 0x14);
                    *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(iVar9 + 0x18);
                    FUN_0040e310((int *)&local_b38);
                    puVar14 = local_b3c;
                    break;
                  case 3:
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar11 + 0x2c) = *(undefined4 *)(iVar9 + 0x1c);
                    FUN_0040e310((int *)&local_b38);
                    puVar14 = local_b3c;
                    break;
                  case 4:
                  case 5:
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar11 + 0x2c) = *(undefined4 *)(iVar9 + 0x1c);
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar11 + 0x30) = *(undefined4 *)(iVar9 + 0x20);
                    FUN_0040e310((int *)&local_b38);
                    puVar14 = local_b3c;
                    break;
                  case 6:
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar11 + 0x24) = *(undefined4 *)(iVar9 + 0x14);
                    *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(iVar9 + 0x18);
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    puVar14 = *(undefined4 **)(iVar11 + 0x38);
                    ppiVar13 = (int **)*puVar14;
                    piVar8 = (int *)(iVar11 + 0x34);
                    *puVar14 = puVar14;
                    *(int *)(*(int *)(iVar11 + 0x38) + 4) = *(int *)(iVar11 + 0x38);
                    *(undefined4 *)(iVar11 + 0x3c) = 0;
                    if (ppiVar13 != *(int ***)(iVar11 + 0x38)) {
                      do {
                        local_b5c = (int **)*ppiVar13;
                        _free(ppiVar13);
                        ppiVar13 = local_b5c;
                      } while (local_b5c != *(int ***)(iVar11 + 0x38));
                    }
                    if (local_b34 == puVar7[1]) {
                      FUN_0047a948();
                    }
                    if (iVar11 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    piVar15 = local_b58 + 6;
                    if (piVar8 != piVar15) {
                      puVar7 = (undefined4 *)local_b58[7];
                      local_ac4 = (undefined4 *)*puVar7;
                      puVar14 = *(undefined4 **)(iVar11 + 0x38);
                      ppiVar13 = (int **)*puVar14;
                      *puVar14 = puVar14;
                      *(int *)(*(int *)(iVar11 + 0x38) + 4) = *(int *)(iVar11 + 0x38);
                      *(undefined4 *)(iVar11 + 0x3c) = 0;
                      if (ppiVar13 != *(int ***)(iVar11 + 0x38)) {
                        do {
                          local_b5c = (int **)*ppiVar13;
                          _free(ppiVar13);
                          ppiVar13 = local_b5c;
                        } while (local_b5c != *(int ***)(iVar11 + 0x38));
                      }
                      FUN_004054c0(piVar8,piVar8,**(int **)(iVar11 + 0x38),(int)piVar15,local_ac4,
                                   (int)piVar15,puVar7);
                    }
                  default:
                    FUN_0040e310((int *)&local_b38);
                    puVar14 = local_b3c;
                  }
                }
              }
              local_b44 = (int *)((int)local_b44 + 0x1e);
              local_b54 = (int **)((int)local_b54 + 1);
            } while ((int)local_b54 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404));
          }
          if (local_b18 == *(undefined4 **)(local_b1c + 4)) {
            FUN_0047a948();
          }
          local_b34 = *(int *)local_b18[0x188];
          local_b54 = (int **)(local_b18 + 0x187);
          local_b38 = local_b54;
          while( true ) {
            iVar11 = local_b34;
            puVar7 = local_b38;
            ppiVar13 = local_b54;
            if (local_b18 == *(undefined4 **)(local_b1c + 4)) {
              FUN_0047a948();
            }
            local_a94 = (int)ppiVar13[1];
            if ((puVar7 == (undefined4 *)0x0) || ((int **)puVar7 != ppiVar13)) {
              FUN_0047a948();
            }
            pvVar4 = local_b50;
            if (iVar11 == local_a94) break;
            if (puVar7 == (undefined4 *)0x0) {
              FUN_0047a948();
            }
            if (iVar11 == puVar7[1]) {
              FUN_0047a948();
            }
            local_b58 = (int *)(iVar11 + 0xc);
            piVar8 = (int *)OrderedSet_FindOrInsert
                                      ((void *)(*(int *)((int)local_b50 + 8) + 0x2450),
                                       (int *)local_ab8,local_b58);
            local_b4c = *piVar8;
            iVar9 = piVar8[1];
            if (iVar11 == puVar7[1]) {
              FUN_0047a948();
            }
            if (local_b4c == 0) {
              FUN_0047a948();
            }
            if (iVar9 == *(int *)(local_b4c + 4)) {
              FUN_0047a948();
            }
            *(int *)(iVar9 + 0x20) = local_b58[1];
            if (iVar9 == *(int *)(local_b4c + 4)) {
              FUN_0047a948();
            }
            switch(*(undefined4 *)(iVar9 + 0x20)) {
            case 2:
              if (iVar11 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              *(int *)(iVar9 + 0x2c) = local_b58[4];
              if (iVar11 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              *(int *)(iVar9 + 0x24) = local_b58[2];
              *(int *)(iVar9 + 0x28) = local_b58[3];
              break;
            case 3:
              if (iVar11 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              *(int *)(iVar9 + 0x2c) = local_b58[4];
              break;
            case 4:
            case 5:
              if (iVar11 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              *(int *)(iVar9 + 0x2c) = local_b58[4];
              if (iVar11 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              *(int *)(iVar9 + 0x30) = local_b58[5];
              break;
            case 6:
              if (iVar11 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              *(int *)(iVar9 + 0x24) = local_b58[2];
              *(int *)(iVar9 + 0x28) = local_b58[3];
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              puVar14 = *(undefined4 **)(iVar9 + 0x38);
              ppiVar13 = (int **)*puVar14;
              piVar8 = (int *)(iVar9 + 0x34);
              *puVar14 = puVar14;
              *(int *)(*(int *)(iVar9 + 0x38) + 4) = *(int *)(iVar9 + 0x38);
              *(undefined4 *)(iVar9 + 0x3c) = 0;
              if (ppiVar13 != *(int ***)(iVar9 + 0x38)) {
                do {
                  local_b5c = (int **)*ppiVar13;
                  _free(ppiVar13);
                  ppiVar13 = local_b5c;
                } while (local_b5c != *(int ***)(iVar9 + 0x38));
              }
              if (local_b34 == puVar7[1]) {
                FUN_0047a948();
              }
              if (iVar9 == *(int *)(local_b4c + 4)) {
                FUN_0047a948();
              }
              piVar15 = local_b58 + 6;
              if (piVar8 != piVar15) {
                puVar7 = (undefined4 *)local_b58[7];
                puVar14 = *(undefined4 **)(iVar9 + 0x38);
                ppiVar13 = (int **)*puVar14;
                local_adc = (undefined4 *)*puVar7;
                *puVar14 = puVar14;
                *(int *)(*(int *)(iVar9 + 0x38) + 4) = *(int *)(iVar9 + 0x38);
                *(undefined4 *)(iVar9 + 0x3c) = 0;
                if (ppiVar13 != *(int ***)(iVar9 + 0x38)) {
                  do {
                    local_b5c = (int **)*ppiVar13;
                    _free(ppiVar13);
                    ppiVar13 = local_b5c;
                  } while (local_b5c != *(int ***)(iVar9 + 0x38));
                }
                FUN_004054c0(piVar8,piVar8,**(int **)(iVar9 + 0x38),(int)piVar15,local_adc,
                             (int)piVar15,puVar7);
              }
            }
            FUN_0040e310((int *)&local_b38);
          }
          FUN_0040b560(*(void **)((int)local_b50 + 8));
          local_b48 = **(int **)(*(int *)((int)pvVar4 + 8) + 0x2454);
          local_b4c = *(int *)((int)pvVar4 + 8) + 0x2450;
          while( true ) {
            puVar7 = local_b3c;
            iVar9 = local_b48;
            iVar11 = local_b4c;
            local_aac = *(int *)(*(int *)((int)local_b50 + 8) + 0x2454);
            if ((local_b4c == 0) || (local_b4c != *(int *)((int)local_b50 + 8) + 0x2450)) {
              FUN_0047a948();
            }
            if (iVar9 == local_aac) break;
            if (iVar11 == 0) {
              FUN_0047a948();
            }
            if (iVar9 == *(int *)(iVar11 + 4)) {
              FUN_0047a948();
            }
            if (*(char *)(iVar9 + 0x6b) == '\x01') {
              if ((iVar9 == *(int *)(iVar11 + 4)) && (FUN_0047a948(), iVar9 == *(int *)(iVar11 + 4))
                 ) {
                FUN_0047a948();
              }
              local_b5c = FUN_0041c270(&DAT_00baed7c,(int **)(iVar9 + 0x24));
              local_b5c = local_b5c + *(int *)(iVar9 + 0x18) + 0x15;
              if (puVar7 == *(undefined4 **)(local_b40 + 4)) {
                FUN_0047a948();
              }
              *local_b5c = (int *)((int)*local_b5c + puVar7[4]);
              if (iVar9 == *(int *)(iVar11 + 4)) {
                FUN_0047a948();
              }
              local_b5c = apiStack_a40 + *(int *)(iVar9 + 0x24);
              if (puVar7 == *(undefined4 **)(local_b40 + 4)) {
                FUN_0047a948();
              }
              *local_b5c = (int *)((int)*local_b5c + puVar7[4]);
              if (iVar9 == *(int *)(iVar11 + 4)) {
                FUN_0047a948();
              }
              if ((*(int ***)(iVar9 + 0x18) == param_1) &&
                 (local_b5c = (int **)0x0, 0 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404))) {
                local_b54 = (int **)0x0;
                do {
                  if ((local_b5c != param_1) && (0 < (int)(&DAT_0062e460)[(int)local_b5c])) {
                    if (puVar7 == *(undefined4 **)(local_b40 + 4)) {
                      FUN_0047a948();
                    }
                    iVar10 = local_b3c[5] + (int)local_b54;
                    if ((&DAT_00bbf690)[iVar10 * 2] == 0) {
                      FUN_0047a948();
                    }
                    if ((&DAT_00bbf694)[iVar10 * 2] == *(int *)((&DAT_00bbf690)[iVar10 * 2] + 4)) {
                      FUN_0047a948();
                    }
                    iVar10 = (&DAT_00bbf694)[iVar10 * 2];
                    if (iVar9 == *(int *)(iVar11 + 4)) {
                      FUN_0047a948();
                    }
                    *(undefined4 *)(iVar10 + 0x21c + *(int *)(iVar9 + 0x24) * 4) = 1;
                    puVar7 = local_b3c;
                  }
                  local_b54 = (int **)((int)local_b54 + 0x1e);
                  local_b5c = (int **)((int)local_b5c + 1);
                } while ((int)local_b5c < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404));
              }
            }
            else {
              if (iVar9 == *(int *)(iVar11 + 4)) {
                FUN_0047a948();
              }
              if (*(char *)(iVar9 + 0x6a) == '\x01') {
                local_b58 = (int *)0xffffffff;
                if ((iVar9 == *(int *)(iVar11 + 4)) &&
                   (FUN_0047a948(), iVar9 == *(int *)(iVar11 + 4))) {
                  FUN_0047a948();
                }
                local_b30 = AdjacencyList_FilterByUnitType
                                      ((void *)(*(int *)((int)local_b50 + 8) + 8 +
                                               *(int *)(iVar9 + 0x10) * 0x24),
                                       (ushort *)(iVar9 + 0x14));
                local_b2c = (int *)*local_b30[1];
                local_b20 = local_b30;
                while( true ) {
                  piVar8 = local_b2c;
                  ppiVar13 = local_b30;
                  local_abc = local_b20[1];
                  if ((local_b30 == (int **)0x0) || (local_b30 != local_b20)) {
                    FUN_0047a948();
                  }
                  if (piVar8 == local_abc) break;
                  if (ppiVar13 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (piVar8 == ppiVar13[1]) {
                    FUN_0047a948();
                  }
                  if ((int *)piVar8[3] != local_b58) {
                    if (piVar8 == ppiVar13[1]) {
                      FUN_0047a948();
                    }
                    local_b5c = apiStack_640 + piVar8[3];
                    if (local_b3c == *(undefined4 **)(local_b40 + 4)) {
                      FUN_0047a948();
                    }
                    *local_b5c = (int *)((int)*local_b5c + local_b3c[4]);
                    if (piVar8 == ppiVar13[1]) {
                      FUN_0047a948();
                    }
                    local_b58 = (int *)piVar8[3];
                  }
                  FUN_0040f400((int *)&local_b30);
                }
              }
              else {
                if ((iVar9 == *(int *)(iVar11 + 4)) &&
                   (FUN_0047a948(), iVar9 == *(int *)(iVar11 + 4))) {
                  FUN_0047a948();
                }
                local_b5c = FUN_0041c270(&DAT_00baed7c,(int **)(iVar9 + 0x10));
                local_b5c = local_b5c + *(int *)(iVar9 + 0x18) + 0x15;
                if (puVar7 == *(undefined4 **)(local_b40 + 4)) {
                  FUN_0047a948();
                }
                *local_b5c = (int *)((int)*local_b5c + puVar7[4]);
                if (iVar9 == *(int *)(iVar11 + 4)) {
                  FUN_0047a948();
                }
                local_b5c = apiStack_a40 + *(int *)(iVar9 + 0x10);
                if (puVar7 == *(undefined4 **)(local_b40 + 4)) {
                  FUN_0047a948();
                }
                *local_b5c = (int *)((int)*local_b5c + puVar7[4]);
                if (iVar9 == *(int *)(iVar11 + 4)) {
                  FUN_0047a948();
                }
                if ((*(int ***)(iVar9 + 0x18) == param_1) &&
                   (ppiVar13 = (int **)0x0, 0 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404))) {
                  local_b54 = (int **)0x0;
                  do {
                    if ((ppiVar13 != param_1) && (0 < (int)(&DAT_0062e460)[(int)ppiVar13])) {
                      if (local_b3c == *(undefined4 **)(local_b40 + 4)) {
                        FUN_0047a948();
                      }
                      iVar11 = local_b3c[5] + (int)local_b54;
                      if ((&DAT_00bbf690)[iVar11 * 2] == 0) {
                        FUN_0047a948();
                      }
                      if ((&DAT_00bbf694)[iVar11 * 2] == *(int *)((&DAT_00bbf690)[iVar11 * 2] + 4))
                      {
                        FUN_0047a948();
                      }
                      iVar11 = (&DAT_00bbf694)[iVar11 * 2];
                      if (iVar9 == *(int *)(local_b4c + 4)) {
                        FUN_0047a948();
                      }
                      *(undefined4 *)(iVar11 + 0x21c + *(int *)(iVar9 + 0x10) * 4) = 1;
                    }
                    local_b54 = (int **)((int)local_b54 + 0x1e);
                    ppiVar13 = (int **)((int)ppiVar13 + 1);
                  } while ((int)ppiVar13 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404));
                }
              }
            }
            iVar11 = local_b4c;
            if (iVar9 == *(int *)(local_b4c + 4)) {
              FUN_0047a948();
            }
            if (*(char *)(iVar9 + 0x69) == '\x01') {
              if (iVar9 == *(int *)(iVar11 + 4)) {
                FUN_0047a948();
              }
              puVar7 = local_b3c;
              iVar11 = *(int *)(iVar9 + 0x24);
              if (local_b3c == *(undefined4 **)(local_b40 + 4)) {
                FUN_0047a948();
              }
              apiStack_a40[iVar11] = (int *)((int)apiStack_a40[iVar11] + puVar7[4]);
            }
            UnitList_Advance(&local_b4c);
          }
          local_b48 = **(int **)(*(int *)((int)local_b50 + 8) + 0x2454);
          local_b4c = *(int *)((int)local_b50 + 8) + 0x2450;
          while( true ) {
            iVar10 = local_b48;
            iVar9 = local_b4c;
            iVar11 = *(int *)(*(int *)((int)local_b50 + 8) + 0x2454);
            if ((local_b4c == 0) || (local_b4c != *(int *)((int)local_b50 + 8) + 0x2450)) {
              FUN_0047a948();
            }
            if (iVar10 == iVar11) break;
            if (iVar9 == 0) {
              FUN_0047a948();
            }
            if (iVar10 == *(int *)(iVar9 + 4)) {
              FUN_0047a948();
            }
            if (*(char *)(iVar10 + 0x6a) == '\x01') {
              cVar1 = *(char *)((int)local_b10[1] + 0x21);
              piVar8 = local_b10[1];
              iVar11 = local_b4c;
              while (local_b4c = iVar11, cVar1 == '\0') {
                std_Tree_DestroyTree((int *)piVar8[2]);
                piVar15 = (int *)*piVar8;
                _free(piVar8);
                piVar8 = piVar15;
                iVar11 = local_b4c;
                cVar1 = *(char *)((int)piVar15 + 0x21);
              }
              local_b10[1] = (int *)local_b10;
              local_b0c = 0;
              *local_b10 = (int *)local_b10;
              local_b10[2] = (int *)local_b10;
              if ((iVar10 == *(int *)(iVar11 + 4)) &&
                 (FUN_0047a948(), iVar10 == *(int *)(iVar11 + 4))) {
                FUN_0047a948();
              }
              local_b30 = AdjacencyList_FilterByUnitType
                                    ((void *)(*(int *)((int)local_b50 + 8) + 8 +
                                             *(int *)(iVar10 + 0x10) * 0x24),
                                     (ushort *)(iVar10 + 0x14));
              local_b2c = (int *)*local_b30[1];
              local_b20 = local_b30;
              while( true ) {
                piVar8 = local_b2c;
                ppiVar13 = local_b30;
                local_a9c = local_b20[1];
                if ((local_b30 == (int **)0x0) || (local_b30 != local_b20)) {
                  FUN_0047a948();
                }
                if (piVar8 == local_a9c) break;
                if (ppiVar13 == (int **)0x0) {
                  FUN_0047a948();
                }
                if (piVar8 == ppiVar13[1]) {
                  FUN_0047a948();
                }
                if (apiStack_a40[piVar8[3]] == (int *)0x0) {
                  if (piVar8 == ppiVar13[1]) {
                    FUN_0047a948();
                  }
                  if ((int)apiStack_640[piVar8[3]] < 2) {
                    if (piVar8 == ppiVar13[1]) {
                      FUN_0047a948();
                    }
                    if (iVar10 == *(int *)(local_b4c + 4)) {
                      FUN_0047a948();
                    }
                    if (piVar8[3] != *(int *)(iVar10 + 0x60)) {
                      if (piVar8 == ppiVar13[1]) {
                        FUN_0047a948();
                      }
                      piVar15 = (int *)piVar8[3];
                      iVar11 = piVar8[4];
                      local_b04 = piVar15;
                      local_b00 = iVar11;
                      if (iVar10 == *(int *)(local_b4c + 4)) {
                        FUN_0047a948();
                      }
                      ppiVar13 = OrderedSet_FindOrInsert
                                           ((void *)((int)local_b50 +
                                                    *(int *)(iVar10 + 0x18) * 0xc + 0x4000),
                                            &local_b04);
                      local_af0 = *ppiVar13;
                      local_aec = ppiVar13[1];
                      local_ae4 = (undefined2)iVar11;
                      local_ae8 = piVar15;
                      BuildOrderSpec(local_b14,local_a4c,(uint *)&local_af0);
                    }
                  }
                }
                FUN_0040f400((int *)&local_b30);
              }
              ppiVar13 = (int **)*local_b10;
              if (ppiVar13 != local_b10) {
                if (iVar10 == *(int *)(local_b4c + 4)) {
                  FUN_0047a948();
                }
                ppiVar13 = FUN_0041c270(&DAT_00baed7c,ppiVar13 + 6);
                puVar7 = local_b3c;
                iVar11 = *(int *)(iVar10 + 0x18);
                if (local_b3c == *(undefined4 **)(local_b40 + 4)) {
                  FUN_0047a948();
                }
                ppiVar13[iVar11 + 0x15] = (int *)((int)ppiVar13[iVar11 + 0x15] + puVar7[4]);
              }
            }
            UnitList_Advance(&local_b4c);
          }
          FUN_0040e680((int *)&local_b40);
        }
        local_b24 = (undefined4 *)*DAT_00baed80;
        local_b28 = &DAT_00baed7c;
        while( true ) {
          puVar14 = local_b24;
          puVar7 = DAT_00baed80;
          if ((local_b28 == (undefined *)0x0) || (local_b28 != &DAT_00baed7c)) {
            FUN_0047a948();
          }
          puVar5 = local_b18;
          puVar3 = local_b1c;
          if (puVar14 == puVar7) break;
          local_b5c = (int **)0x0;
          if (0 < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404)) {
            local_b44 = puVar14 + 0x1a;
            local_b54 = (int **)0x0;
            do {
              puVar3 = local_b28;
              if (local_b28 == (undefined *)0x0) {
                FUN_0047a948();
              }
              if (puVar14 == *(undefined4 **)(puVar3 + 4)) {
                FUN_0047a948();
              }
              puVar3 = local_b28;
              if (0 < *local_b44) {
                if (puVar14 == *(undefined4 **)(local_b28 + 4)) {
                  FUN_0047a948();
                }
                iVar11 = puVar14[3] + (int)local_b54;
                if (puVar14 == *(undefined4 **)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                (&DAT_00b9a980)[iVar11] = (&DAT_00b9a980)[iVar11] + *local_b44;
                if (puVar14 == *(undefined4 **)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                pvVar4 = local_b50;
                if (*(char *)(*(int *)((int)local_b50 + 8) + 3 + puVar14[3] * 0x24) != '\0') {
                  if (puVar14 == *(undefined4 **)(puVar3 + 4)) {
                    FUN_0047a948();
                  }
                  uVar2 = *(ushort *)(*(int *)((int)pvVar4 + 8) + 0x20 + puVar14[3] * 0x24);
                  ppiVar13 = (int **)(uVar2 & 0xff);
                  if ((char)(uVar2 >> 8) != 'A') {
                    ppiVar13 = (int **)0x14;
                  }
                  if (ppiVar13 != local_b5c) {
                    if ((puVar14 == *(undefined4 **)(puVar3 + 4)) &&
                       (FUN_0047a948(), puVar14 == *(undefined4 **)(puVar3 + 4))) {
                      FUN_0047a948();
                    }
                    local_b30 = AdjacencyList_FilterByUnitType
                                          ((void *)(*(int *)((int)pvVar4 + 8) + 8 +
                                                   puVar14[3] * 0x24),(ushort *)(puVar14 + 4));
                    local_b2c = (int *)*local_b30[1];
                    local_b58 = (int *)0xffffffff;
                    local_b20 = local_b30;
                    while( true ) {
                      piVar8 = local_b2c;
                      ppiVar13 = local_b30;
                      local_a8c = local_b20[1];
                      if ((local_b30 == (int **)0x0) || (local_b30 != local_b20)) {
                        FUN_0047a948();
                      }
                      if (piVar8 == local_a8c) break;
                      if (ppiVar13 == (int **)0x0) {
                        FUN_0047a948();
                      }
                      if (piVar8 == ppiVar13[1]) {
                        FUN_0047a948();
                      }
                      if ((int *)piVar8[3] != local_b58) {
                        if (piVar8 == ppiVar13[1]) {
                          FUN_0047a948();
                        }
                        local_b58 = &DAT_00b95580 + piVar8[3] + (int)local_b54;
                        if (puVar14 == *(undefined4 **)(local_b28 + 4)) {
                          FUN_0047a948();
                        }
                        *local_b58 = *local_b58 + *local_b44;
                        if (piVar8 == ppiVar13[1]) {
                          FUN_0047a948();
                        }
                        local_b58 = (int *)piVar8[3];
                      }
                      FUN_0040f400((int *)&local_b30);
                    }
                    goto LAB_00443c01;
                  }
                }
                if ((puVar14 == *(undefined4 **)(puVar3 + 4)) &&
                   (FUN_0047a948(), puVar14 == *(undefined4 **)(puVar3 + 4))) {
                  FUN_0047a948();
                }
                local_b30 = AdjacencyList_FilterByUnitType
                                      ((void *)(*(int *)((int)pvVar4 + 8) + 8 + puVar14[3] * 0x24),
                                       (ushort *)(puVar14 + 4));
                local_b2c = (int *)*local_b30[1];
                local_b58 = (int *)0xffffffff;
                local_b20 = local_b30;
                while( true ) {
                  piVar8 = local_b2c;
                  ppiVar13 = local_b30;
                  local_aa4 = local_b20[1];
                  if ((local_b30 == (int **)0x0) || (local_b30 != local_b20)) {
                    FUN_0047a948();
                  }
                  if (piVar8 == local_aa4) break;
                  if (ppiVar13 == (int **)0x0) {
                    FUN_0047a948();
                  }
                  if (piVar8 == ppiVar13[1]) {
                    FUN_0047a948();
                  }
                  if ((int *)piVar8[3] != local_b58) {
                    if (piVar8 == ppiVar13[1]) {
                      FUN_0047a948();
                    }
                    local_b58 = &DAT_00b9a980 + piVar8[3] + (int)local_b54;
                    if (puVar14 == *(undefined4 **)(local_b28 + 4)) {
                      FUN_0047a948();
                    }
                    *local_b58 = *local_b58 + *local_b44;
                    if (piVar8 == ppiVar13[1]) {
                      FUN_0047a948();
                    }
                    local_b58 = (int *)piVar8[3];
                  }
                  FUN_0040f400((int *)&local_b30);
                }
              }
LAB_00443c01:
              local_b44 = local_b44 + 1;
              local_b54 = local_b54 + 0x40;
              local_b5c = (int **)((int)local_b5c + 1);
            } while ((int)local_b5c < *(int *)(*(int *)((int)local_b50 + 8) + 0x2404));
          }
          FUN_0040f380((int *)&local_b28);
        }
        if (local_b18 == *(undefined4 **)(local_b1c + 4)) {
          FUN_0047a948();
        }
        DAT_0062b0c4 = puVar5 + 7;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        DAT_00633ebc = puVar5[0x15];
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        DAT_0062c57c = puVar5[0xe];
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        g_EarlyGameAdjScore = puVar5[0xf];
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        DAT_00633e64 = puVar5[0x13];
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        DAT_0062e358 = puVar5[0x10];
        DAT_0062e35c = DAT_0062e358 >> 0x1f;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        DAT_0062db50 = puVar5[0x11];
        _DAT_0062db54 = DAT_0062db50 >> 0x1f;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        DAT_006240cc = puVar5[0x12];
        ppiVar13 = (int **)EvaluateAllianceScore(local_b50,(int *)param_1,local_b08);
        local_b5c = ppiVar13;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        puVar5[0x10] = DAT_0062e358;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        puVar5[0x11] = DAT_0062db50;
        if (0 < DAT_0062cc64) {
          if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
            FUN_0047a948();
          }
          ppiVar13 = (int **)((int)puVar5[9] / 2 + (int)local_b5c / 2);
        }
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        puVar5[9] = local_b5c;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        puVar5[DAT_0062cc64 + 0x35] = local_b5c;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        puVar5[DAT_0062cc64 + 0x53] = ppiVar13;
        if (puVar5 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        puVar5[0xd] = DAT_0062cc64;
        this = local_b50;
      }
    }
    FUN_0040f260((int *)&local_b1c);
  } while( true );
}

