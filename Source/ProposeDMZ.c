
undefined1 __thiscall ProposeDMZ(void *this,uint *power_index)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  uint **ppuVar7;
  byte *pbVar8;
  undefined4 auStack_f4 [2];
  undefined4 uStack_ec;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  ushort local_c0 [2];
  ushort local_bc [3];
  undefined1 local_b6 [2];
  undefined *local_b4;
  undefined4 *local_b0;
  undefined2 local_ac [2];
  undefined *local_a8;
  undefined4 *local_a4;
  uint *local_a0;
  undefined4 *local_9c;
  undefined4 local_98;
  undefined4 *local_90;
  int local_8c;
  void *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  uint *local_7c;
  undefined4 *local_78;
  uint local_6c;
  void *local_68 [4];
  void *local_58 [4];
  uint *local_48 [4];
  void *local_38 [4];
  uint *local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0049710a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_b6[0] = 0;
  local_bc[0] = 0;
  local_c0[0] = 0;
  local_ac[0] = 0;
  local_88 = this;
  FUN_00465870(local_58);
  local_c = 0;
  FUN_00465870(local_38);
  local_c._0_1_ = 1;
  FUN_00465870(local_68);
  local_6c = (uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_b0 = (undefined4 *)*DAT_00bb6f20;
  local_8c = ((int)(DAT_004c6bd4 + (DAT_004c6bd4 >> 0x1f & 3U)) >> 2) + -4;
  local_c = CONCAT31(local_c._1_3_,2);
  local_b4 = &g_OrderList;
  while( true ) {
    iVar6 = local_8c;
    puVar1 = local_b0;
    puVar3 = local_b4;
    local_80 = DAT_00bb6f20;
    if ((local_b4 == (undefined *)0x0) || (local_b4 != &g_OrderList)) {
      FUN_0047a948();
    }
    if (puVar1 == local_80) break;
    if (puVar3 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
      FUN_0047a948();
    }
    if ((uint *)puVar1[5] == power_index) {
      if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
        FUN_0047a948();
      }
      if (*(char *)(puVar1 + 4) == '\0') {
        if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        if (iVar6 < (int)puVar1[3]) {
          local_24 = (&DAT_00bb702c)[(int)power_index * 3];
          if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
            FUN_0047a948();
          }
          uStack_e0 = 0x432abf;
          local_90 = (undefined4 *)
                     GameBoard_GetPowerRec
                               (&DAT_00bb7028 + (int)power_index * 0xc,(int *)&local_a0,puVar1 + 6);
          if (((undefined *)*local_90 == (undefined *)0x0) ||
             ((undefined *)*local_90 != &DAT_00bb7028 + (int)power_index * 0xc)) {
            FUN_0047a948();
          }
          if (local_90[1] == local_24) {
            if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
              FUN_0047a948();
            }
            if (*(char *)(puVar1 + 7) == '\x01') {
              if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
                FUN_0047a948();
              }
              if (*(char *)((int)puVar1 + 0x1d) == '\x01') {
                iVar6 = Iterator_GetData((int *)&local_b4);
                if (*(char *)(iVar6 + 0x12) == '\0') {
                  local_a4 = (undefined4 *)*DAT_00bb7134;
                  bVar2 = false;
                  local_a8 = &DAT_00bb7130;
                  while( true ) {
                    puVar4 = local_a4;
                    puVar3 = local_a8;
                    local_78 = DAT_00bb7134;
                    if ((local_a8 == (undefined *)0x0) || (local_a8 != &DAT_00bb7130)) {
                      FUN_0047a948();
                    }
                    if (puVar4 == local_78) break;
                    if (puVar3 == (undefined *)0x0) {
                      FUN_0047a948();
                    }
                    if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                      FUN_0047a948();
                    }
                    if ((uint *)puVar4[3] == power_index) {
                      if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                        FUN_0047a948();
                      }
                      if (puVar1 == *(undefined4 **)(local_b4 + 4)) {
                        FUN_0047a948();
                      }
                      if (puVar4[4] == puVar1[6]) {
                        bVar2 = true;
                      }
                    }
                    FUN_0040e680((int *)&local_a8);
                  }
                  if (!bVar2) {
                    if (puVar1 == *(undefined4 **)(local_b4 + 4)) {
                      FUN_0047a948();
                    }
                    uStack_e0 = 0x432bee;
                    ppuVar7 = FUN_00466480(local_38,local_48,
                                           (void *)(*(int *)((int)local_88 + 8) + puVar1[6] * 0x24))
                    ;
                    local_c._0_1_ = 3;
                    AppendList(local_38,ppuVar7);
                    local_c = CONCAT31(local_c._1_3_,2);
                    FreeList(local_48);
                  }
                }
              }
            }
          }
        }
      }
    }
    std_Tree_IteratorIncrement((int *)&local_b4);
  }
  local_84 = (undefined4 *)FUN_00465930((int)local_38);
  if ((int)local_84 < 2) {
    local_b0 = (undefined4 *)*DAT_00bb6f20;
    local_b4 = &g_OrderList;
    do {
      puVar4 = local_b0;
      puVar3 = local_b4;
      puVar1 = DAT_00bb6f20;
      if ((local_b4 == (undefined *)0x0) || (local_b4 != &g_OrderList)) {
        FUN_0047a948();
      }
      if (puVar4 == puVar1) goto LAB_004334b0;
      if (puVar3 == (undefined *)0x0) {
        FUN_0047a948();
      }
      if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
        FUN_0047a948();
      }
      if ((uint *)puVar4[5] == power_index) {
        if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        if (*(char *)(puVar4 + 4) == '\0') {
          if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
            FUN_0047a948();
          }
          if (local_8c < (int)puVar4[3]) {
            local_78 = (undefined4 *)(&DAT_00bb702c)[(int)power_index * 3];
            if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
              FUN_0047a948();
            }
            uStack_e0 = 0x432f3c;
            local_84 = (undefined4 *)
                       GameBoard_GetPowerRec
                                 (&DAT_00bb7028 + (int)power_index * 0xc,(int *)&local_a0,puVar4 + 6
                                 );
            if (((undefined *)*local_84 == (undefined *)0x0) ||
               ((undefined *)*local_84 != &DAT_00bb7028 + (int)power_index * 0xc)) {
              FUN_0047a948();
            }
            if ((undefined4 *)local_84[1] == local_78) {
              if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                FUN_0047a948();
              }
              if (*(char *)(puVar4 + 7) == '\x01') {
                if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                if (*(char *)((int)puVar4 + 0x1d) == '\x01') {
                  if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                    FUN_0047a948();
                  }
                  if (*(char *)((int)puVar4 + 0x1e) == '\0') {
                    local_a4 = (undefined4 *)*DAT_00bb7134;
                    bVar2 = false;
                    local_a8 = &DAT_00bb7130;
                    goto LAB_00432ff0;
                  }
                }
              }
              if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                FUN_0047a948();
              }
              if (*(char *)(puVar4 + 7) == '\x01') {
                if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                  FUN_0047a948();
                }
                if (*(char *)((int)puVar4 + 0x1d) == '\0') {
                  if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
                    FUN_0047a948();
                  }
                  if (*(char *)((int)puVar4 + 0x1e) == '\0') goto LAB_00433254;
                }
              }
            }
          }
        }
      }
      std_Tree_IteratorIncrement((int *)&local_b4);
    } while( true );
  }
  local_8c = 0;
  if (0 < (int)local_84) {
    local_a0 = power_index;
    do {
      uStack_e0 = 0x432c77;
      pbVar8 = (byte *)GetListElement(local_38,(undefined2 *)local_b6,local_8c);
      local_9c = (undefined4 *)(uint)*pbVar8;
      local_98 = 1;
      uStack_e0 = 0x432c9f;
      local_90 = local_9c;
      FUN_00419df0(&DAT_00bb7130,&local_7c,(int *)&local_a0);
      local_b0 = (undefined4 *)*DAT_00bb6f20;
      local_b4 = &g_OrderList;
      while( true ) {
        puVar4 = local_b0;
        puVar3 = local_b4;
        puVar1 = DAT_00bb6f20;
        if ((local_b4 == (undefined *)0x0) || (local_b4 != &g_OrderList)) {
          FUN_0047a948();
        }
        if (puVar4 == puVar1) break;
        if (puVar3 == (undefined *)0x0) {
          FUN_0047a948();
        }
        if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        if ((uint *)puVar4[5] == power_index) {
          if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
            FUN_0047a948();
          }
          if ((undefined4 *)puVar4[6] == local_90) {
            if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
              FUN_0047a948();
            }
            *(undefined1 *)(puVar4 + 4) = 1;
          }
        }
        std_Tree_IteratorIncrement((int *)&local_b4);
      }
      local_8c = local_8c + 1;
    } while (local_8c < (int)local_84);
  }
  local_c0[0] = (byte)power_index | 0x4100;
  local_bc[0] = (byte)local_6c | 0x4100;
  uStack_e0 = 0x432d67;
  ppuVar7 = FUN_00466540(local_bc,&local_28,local_c0);
  local_c._0_1_ = 4;
  uStack_e0 = 0x432d7f;
  ppuVar7 = FUN_00466f80(&DMZ,&local_7c,ppuVar7);
  local_c._0_1_ = 5;
  uStack_e0 = 0x432d9b;
  ppuVar7 = FUN_00466c40(ppuVar7,&local_a0,local_38);
  local_c._0_1_ = 6;
  uStack_e0 = 0x432db7;
  ppuVar7 = FUN_00466f80(&PRP,local_48,ppuVar7);
  local_c._0_1_ = 7;
  AppendList(local_58,ppuVar7);
  local_c._0_1_ = 6;
  FreeList(local_48);
  local_c._0_1_ = 5;
  FreeList(&local_a0);
  local_c._0_1_ = 4;
  FreeList(&local_7c);
  local_c._0_1_ = 2;
  FreeList(&local_28);
  FUN_00465f30(&local_a0,local_c0);
  local_c._0_1_ = 8;
  AppendList(local_68,&local_a0);
  local_c._0_1_ = 2;
  FreeList(&local_a0);
  local_84 = &uStack_e4;
  uStack_ec = 0x432e5d;
  FUN_00465f60(&uStack_e4,local_68);
  local_90 = auStack_f4;
  local_c._0_1_ = 9;
  FUN_00465f60(auStack_f4,local_58);
  local_c = CONCAT31(local_c._1_3_,2);
  PROPOSE(local_88);
  goto LAB_004334ab;
LAB_00432ff0:
  puVar1 = local_a4;
  local_78 = DAT_00bb7134;
  if ((local_a8 == (undefined *)0x0) || (local_a8 != &DAT_00bb7130)) {
    FUN_0047a948();
  }
  if (puVar1 == local_78) {
    if (bVar2) goto LAB_004334b0;
    if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
      FUN_0047a948();
    }
    local_9c = (undefined4 *)puVar4[6];
    local_98 = 1;
    local_a0 = power_index;
    uStack_e0 = 0x4330d8;
    FUN_00419df0(&DAT_00bb7130,&local_7c,(int *)&local_a0);
    goto LAB_004330d8;
  }
  if (local_a8 == (undefined *)0x0) {
    FUN_0047a948();
  }
  if (puVar1 == *(undefined4 **)(local_a8 + 4)) {
    FUN_0047a948();
  }
  if ((uint *)puVar1[3] == power_index) {
    if (puVar1 == *(undefined4 **)(local_a8 + 4)) {
      FUN_0047a948();
    }
    if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
      FUN_0047a948();
    }
    if (puVar1[4] == puVar4[6]) {
      bVar2 = true;
      if (puVar1 == *(undefined4 **)(local_a8 + 4)) {
        FUN_0047a948();
      }
      if ((int)puVar1[5] < 2) goto LAB_00433084;
    }
  }
  FUN_0040e680((int *)&local_a8);
  goto LAB_00432ff0;
LAB_00433084:
  if (puVar1 == *(undefined4 **)(local_a8 + 4)) {
    FUN_0047a948();
  }
  puVar1[5] = puVar1[5] + 1;
LAB_004330d8:
  local_c0[0] = (byte)power_index | 0x4100;
  local_bc[0] = (byte)local_6c | 0x4100;
  if (puVar4 == *(undefined4 **)(puVar3 + 4)) {
    FUN_0047a948();
  }
  pvVar5 = local_88;
  local_ac[0] = *(undefined2 *)(*(int *)((int)local_88 + 8) + puVar4[6] * 0x24);
  uStack_e0 = 0x43312c;
  ppuVar7 = FUN_00466540(local_bc,&local_28,local_c0);
  local_c._0_1_ = 10;
  uStack_e0 = 0x433144;
  ppuVar7 = FUN_00466f80(&DMZ,&local_7c,ppuVar7);
  local_c._0_1_ = 0xb;
  uStack_e0 = 0x43315d;
  ppuVar7 = FUN_00466e10(ppuVar7,&local_a0,local_ac);
  local_c._0_1_ = 0xc;
  uStack_e0 = 0x433178;
  ppuVar7 = FUN_00466f80(&PRP,local_48,ppuVar7);
  local_c._0_1_ = 0xd;
  AppendList(local_58,ppuVar7);
  local_c._0_1_ = 0xc;
  FreeList(local_48);
  local_c._0_1_ = 0xb;
  FreeList(&local_a0);
  local_c._0_1_ = 10;
  FreeList(&local_7c);
  local_c._0_1_ = 2;
  FreeList(&local_28);
  FUN_00465f30(&local_a0,local_c0);
  local_c._0_1_ = 0xe;
  AppendList(local_68,&local_a0);
  local_c._0_1_ = 2;
  FreeList(&local_a0);
  local_84 = &uStack_e4;
  uStack_ec = 0x43321f;
  FUN_00465f60(&uStack_e4,local_68);
  local_90 = auStack_f4;
  local_c._0_1_ = 0xf;
  FUN_00465f60(auStack_f4,local_58);
  local_c = CONCAT31(local_c._1_3_,2);
  PROPOSE(pvVar5);
  puVar1 = *(undefined4 **)(puVar3 + 4);
  goto LAB_004334a0;
LAB_00433254:
  local_a4 = (undefined4 *)*DAT_00bb7134;
  bVar2 = false;
  local_a8 = &DAT_00bb7130;
  do {
    puVar1 = local_a4;
    puVar3 = local_a8;
    local_78 = DAT_00bb7134;
    if ((local_a8 == (undefined *)0x0) || (local_a8 != &DAT_00bb7130)) {
      FUN_0047a948();
    }
    if (puVar1 == local_78) {
      if (bVar2) goto LAB_004334b0;
      if (puVar4 == *(undefined4 **)(local_b4 + 4)) {
        FUN_0047a948();
      }
      local_9c = (undefined4 *)puVar4[6];
      local_98 = 1;
      local_a0 = power_index;
      uStack_e0 = 0x43334f;
      FUN_00419df0(&DAT_00bb7130,&local_7c,(int *)&local_a0);
      goto LAB_0043334f;
    }
    if (puVar3 == (undefined *)0x0) {
      FUN_0047a948();
    }
    if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
      FUN_0047a948();
    }
    if ((uint *)puVar1[3] == power_index) {
      if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
        FUN_0047a948();
      }
      if (puVar4 == *(undefined4 **)(local_b4 + 4)) {
        FUN_0047a948();
      }
      if (puVar1[4] == puVar4[6]) {
        bVar2 = true;
        if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
          FUN_0047a948();
        }
        if ((int)puVar1[5] < 2) break;
      }
    }
    FUN_0040e680((int *)&local_a8);
  } while( true );
  if (puVar1 == *(undefined4 **)(puVar3 + 4)) {
    FUN_0047a948();
  }
  puVar1[5] = puVar1[5] + 1;
LAB_0043334f:
  local_c0[0] = (byte)power_index | 0x4100;
  local_bc[0] = (byte)local_6c | 0x4100;
  if (puVar4 == *(undefined4 **)(local_b4 + 4)) {
    FUN_0047a948();
  }
  pvVar5 = local_88;
  local_ac[0] = *(undefined2 *)(*(int *)((int)local_88 + 8) + puVar4[6] * 0x24);
  uStack_e0 = 0x4333a5;
  ppuVar7 = FUN_00466ed0(&DMZ,&local_7c,local_c0);
  local_c._0_1_ = 0x10;
  uStack_e0 = 0x4333be;
  ppuVar7 = FUN_00466e10(ppuVar7,&local_a0,local_ac);
  local_c._0_1_ = 0x11;
  uStack_e0 = 0x4333da;
  ppuVar7 = FUN_00466f80(&PRP,local_48,ppuVar7);
  local_c._0_1_ = 0x12;
  AppendList(local_58,ppuVar7);
  local_c._0_1_ = 0x11;
  FreeList(local_48);
  local_c._0_1_ = 0x10;
  FreeList(&local_a0);
  local_c._0_1_ = 2;
  FreeList(&local_7c);
  FUN_00465f30(&local_a0,local_c0);
  local_c._0_1_ = 0x13;
  AppendList(local_68,&local_a0);
  local_c._0_1_ = 2;
  FreeList(&local_a0);
  local_84 = &uStack_e4;
  uStack_ec = 0x43346c;
  FUN_00465f60(&uStack_e4,local_68);
  local_90 = auStack_f4;
  local_c._0_1_ = 0x14;
  FUN_00465f60(auStack_f4,local_58);
  local_c = CONCAT31(local_c._1_3_,2);
  PROPOSE(pvVar5);
  puVar1 = *(undefined4 **)(local_b4 + 4);
LAB_004334a0:
  if (puVar4 == puVar1) {
    FUN_0047a948();
  }
  *(undefined1 *)(puVar4 + 4) = 1;
LAB_004334ab:
  local_b6[0] = 1;
LAB_004334b0:
  local_c._0_1_ = 1;
  FreeList(local_68);
  local_c = (uint)local_c._1_3_ << 8;
  FreeList(local_38);
  local_c = 0xffffffff;
  FreeList(local_58);
  ExceptionList = local_14;
  return local_b6[0];
}

