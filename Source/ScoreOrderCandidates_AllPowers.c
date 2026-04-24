
void __thiscall ScoreOrderCandidates_AllPowers(void *this,int param_1)

{
  int **ppiVar1;
  void *pvVar2;
  char cVar3;
  ushort uVar4;
  int *piVar5;
  int iVar6;
  int **ppiVar7;
  int **ppiVar8;
  uint uVar9;
  int iVar10;
  int **ppiVar11;
  int iVar12;
  void *pvVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  float10 fVar17;
  longlong lVar18;
  ulonglong uVar19;
  longlong lVar20;
  uint local_f4;
  int local_f0;
  int **local_ec;
  int *local_e8;
  int *local_e4;
  uint local_e0;
  int **local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  void *local_c4;
  void *local_c0;
  int local_bc;
  int **local_b8;
  int *local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  int local_9c;
  undefined8 local_98;
  int local_8c;
  int local_88;
  int local_84;
  uint local_80;
  uint local_7c;
  double local_78;
  int local_70;
  int iStack_6c;
  int *local_64;
  int local_5c;
  int local_54;
  int *local_4c;
  int local_44;
  int *local_3c;
  int local_34;
  int local_2c;
  int local_24;
  int *local_1c;
  int local_14;
  int local_c;
  
  local_80 = *(uint *)((int)this + 0x4d98) - *(uint *)((int)this + 0x4d38);
  local_7c = (*(int *)((int)this + 0x4d9c) - *(int *)((int)this + 0x4d3c)) -
             (uint)(*(uint *)((int)this + 0x4d98) < *(uint *)((int)this + 0x4d38));
  local_e0 = local_e0 & 0xffff0000;
  local_f4 = 0;
  if (0 < *(int *)(*(int *)((int)this + 8) + 0x2404)) {
    do {
      local_bc = **(int **)((int)this + local_f4 * 0x78 + 0x3620);
      pvVar13 = (void *)((int)this + local_f4 * 0x78 + 0x361c);
      local_a8 = 1;
      local_b0 = 100000000000000000;
      local_c0 = pvVar13;
      while( true ) {
        iVar15 = local_bc;
        pvVar2 = local_c0;
        local_14 = *(int *)((int)pvVar13 + 4);
        if ((local_c0 == (void *)0x0) || (local_c0 != pvVar13)) {
          FUN_0047a948();
        }
        if (iVar15 == local_14) break;
        if (pvVar2 == (void *)0x0) {
          FUN_0047a948();
        }
        if (iVar15 == *(int *)((int)pvVar2 + 4)) {
          FUN_0047a948();
        }
        local_e4 = *(int **)(iVar15 + 0x10);
        local_e0 = *(uint *)(iVar15 + 0x14);
        lVar20 = 0;
        iVar15 = 0;
        local_c4 = pvVar13;
        do {
          ppiVar7 = OrderedSet_FindOrInsert(local_c4,&local_e4);
          lVar18 = __allmul(*(uint *)(param_1 + iVar15 * 8),*(uint *)(param_1 + 4 + iVar15 * 8),
                            (uint)*ppiVar7,(uint)ppiVar7[1]);
          lVar20 = lVar18 + lVar20;
          local_c4 = (void *)((int)local_c4 + 0xc);
          iVar15 = iVar15 + 1;
        } while (iVar15 < 10);
        if ((DAT_00baed6c == '\x01') && (DAT_00624124 != local_f4)) {
          ppiVar7 = OrderedSet_FindOrInsert(pvVar13,&local_e4);
          lVar18 = __allmul(local_80,local_7c,(uint)*ppiVar7,(uint)ppiVar7[1]);
          lVar20 = lVar18 + lVar20;
        }
        iVar15 = (int)((ulonglong)lVar20 >> 0x20);
        lVar18 = local_a8;
        if (((int)local_a8._4_4_ <= iVar15) &&
           (((int)local_a8._4_4_ < iVar15 || ((uint)local_a8 < (uint)lVar20)))) {
          lVar18 = lVar20;
        }
        local_a8 = lVar18;
        lVar18 = local_b0;
        if ((iVar15 <= (int)local_b0._4_4_) &&
           ((iVar15 < (int)local_b0._4_4_ || ((uint)lVar20 < (int *)local_b0)))) {
          lVar18 = lVar20;
        }
        local_b0 = lVar18;
        ppiVar7 = OrderedSet_FindOrInsert((void *)((int)this + local_f4 * 0xc + 0x4000),&local_e4);
        *(longlong *)ppiVar7 = lVar20;
        std_Tree_IteratorIncrement((int *)&local_c0);
      }
      if ((int *)local_b0 == (int *)0x0 && local_b0._4_4_ == (int *)0x0) {
        local_b0 = 1;
      }
      local_98 = __alldiv((uint)local_a8,(uint)((ulonglong)local_a8 >> 0x20),100,0);
      if (((int *)local_b0 == (int *)(uint)local_98) &&
         (local_b0._4_4_ == (int *)(int)((ulonglong)local_98 >> 0x20))) {
        local_98 = CONCAT44((int)local_b0._4_4_ + (uint)(0xfffffffe < (int *)local_b0),
                            (int)(int *)local_b0 + 1);
      }
      local_bc = **(int **)((int)pvVar13 + 4);
      local_c0 = pvVar13;
      while( true ) {
        iVar15 = local_bc;
        pvVar2 = local_c0;
        local_54 = *(int *)((int)pvVar13 + 4);
        if ((local_c0 == (void *)0x0) || (local_c0 != pvVar13)) {
          FUN_0047a948();
        }
        if (iVar15 == local_54) break;
        if (pvVar2 == (void *)0x0) {
          FUN_0047a948();
        }
        if (iVar15 == *(int *)((int)pvVar2 + 4)) {
          FUN_0047a948();
        }
        local_e4 = *(int **)(iVar15 + 0x10);
        local_e0 = *(uint *)(iVar15 + 0x14);
        pvVar2 = (void *)((int)this + local_f4 * 0xc + 0x4000);
        ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
        if ((local_98._4_4_ < (int)ppiVar7[1]) ||
           ((local_98._4_4_ <= (int)ppiVar7[1] && ((int *)local_98 <= *ppiVar7)))) {
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          lVar20 = __allmul((uint)*ppiVar7,(uint)ppiVar7[1],1000,0);
          lVar20 = __alldiv((uint)lVar20,(uint)((ulonglong)lVar20 >> 0x20),(uint)local_a8,
                            local_a8._4_4_);
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          *(longlong *)ppiVar7 = lVar20 + 0xf;
        }
        else {
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          if (*ppiVar7 == (int *)0x0 && ppiVar7[1] == (int *)0x0) {
LAB_0044a34c:
            ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
            *ppiVar7 = (int *)0x1;
            ppiVar7[1] = (int *)0x0;
          }
          else {
            ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
            if ((*ppiVar7 == (int *)local_b0) && (ppiVar7[1] == local_b0._4_4_)) goto LAB_0044a34c;
            OrderedSet_FindOrInsert(pvVar2,&local_e4);
            fVar17 = (float10)_safe_pow();
            local_78 = (double)fVar17;
            _safe_pow();
            uVar19 = PackScoreU64();
            ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
            *(ulonglong *)ppiVar7 = uVar19;
          }
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          if ((-1 < (int)ppiVar7[1]) && ((0 < (int)ppiVar7[1] || ((int *)0xa < *ppiVar7)))) {
            ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
            *ppiVar7 = (int *)0xa;
            ppiVar7[1] = (int *)0x0;
          }
        }
        ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
        piVar14 = local_e4 + local_f4 * 0x40;
        iVar15 = (int)piVar14 * 8;
        if ((*(int *)(&DAT_0055b0ec + iVar15) <= (int)ppiVar7[1]) &&
           ((*(int *)(&DAT_0055b0ec + iVar15) < (int)ppiVar7[1] ||
            (*(int **)(&g_MaxProvinceScore + iVar15) < *ppiVar7)))) {
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          *(int **)(&g_MaxProvinceScore + iVar15) = *ppiVar7;
          *(int **)(&DAT_0055b0ec + iVar15) = ppiVar7[1];
        }
        ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
        if (((int)ppiVar7[1] <= (int)(&DAT_005508ec)[(int)piVar14 * 2]) &&
           (((int)ppiVar7[1] < (int)(&DAT_005508ec)[(int)piVar14 * 2] ||
            (*ppiVar7 < (int *)(&DAT_005508e8)[(int)piVar14 * 2])))) {
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          (&DAT_005508e8)[(int)piVar14 * 2] = *ppiVar7;
          (&DAT_005508ec)[(int)piVar14 * 2] = ppiVar7[1];
        }
        std_Tree_IteratorIncrement((int *)&local_c0);
      }
      local_bc = **(int **)((int)pvVar13 + 4);
      local_c0 = pvVar13;
      while( true ) {
        pvVar2 = local_c0;
        iVar15 = *(int *)((int)pvVar13 + 4);
        if ((local_c0 == (void *)0x0) || (local_c0 != pvVar13)) {
          FUN_0047a948();
        }
        if (local_bc == iVar15) break;
        if (pvVar2 == (void *)0x0) {
          FUN_0047a948();
        }
        if (local_bc == *(int *)((int)pvVar2 + 4)) {
          FUN_0047a948();
        }
        local_e0 = *(uint *)(local_bc + 0x14);
        piVar14 = *(int **)(local_bc + 0x10);
        local_e4 = piVar14;
        if (AMY == (short)local_e0) {
          pvVar2 = (void *)((int)this + local_f4 * 0xc + 0x4000);
          ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
          iVar15 = (int)(piVar14 + local_f4 * 0x40) * 8;
          if (((int)ppiVar7[1] <= *(int *)(&DAT_0055b0ec + (int)(piVar14 + local_f4 * 0x40) * 8)) &&
             (((int)ppiVar7[1] < *(int *)(&DAT_0055b0ec + (int)(piVar14 + local_f4 * 0x40) * 8) ||
              (*ppiVar7 < *(int **)(&g_MaxProvinceScore + iVar15))))) {
            ppiVar7 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
            ppiVar8 = OrderedSet_FindOrInsert(pvVar2,&local_e4);
            piVar14 = *(int **)(&g_MaxProvinceScore + iVar15);
            local_70 = (int)piVar14 - (int)*ppiVar8;
            iStack_6c = (*(int *)(&DAT_0055b0ec + iVar15) - (int)ppiVar8[1]) -
                        (uint)(piVar14 < *ppiVar8);
            uVar19 = PackScoreU64();
            *(ulonglong *)ppiVar7 = uVar19;
          }
        }
        std_Tree_IteratorIncrement((int *)&local_c0);
      }
      iVar15 = local_f4 * 0xc;
      cVar3 = *(char *)((int)*(int **)(*(int *)(&DAT_00bc202c + iVar15) + 4) + 0x21);
      piVar14 = *(int **)(*(int *)(&DAT_00bc202c + iVar15) + 4);
      local_9c = iVar15;
      while (cVar3 == '\0') {
        std_Tree_DestroyTree((int *)piVar14[2]);
        piVar5 = (int *)*piVar14;
        _free(piVar14);
        piVar14 = piVar5;
        cVar3 = *(char *)((int)piVar5 + 0x21);
      }
      *(int *)(*(int *)(&DAT_00bc202c + iVar15) + 4) = *(int *)(&DAT_00bc202c + iVar15);
      *(undefined4 *)(&DAT_00bc2030 + iVar15) = 0;
      *(undefined4 *)*(undefined4 *)(&DAT_00bc202c + iVar15) =
           *(undefined4 *)(&DAT_00bc202c + iVar15);
      *(int *)(*(int *)(&DAT_00bc202c + iVar15) + 8) = *(int *)(&DAT_00bc202c + iVar15);
      iVar15 = *(int *)((int)this + 8);
      iVar16 = 0;
      if (0 < *(int *)(iVar15 + 0x2400)) {
        local_dc = (int **)0x0;
        do {
          if (*(char *)((int)local_dc + iVar15 + 3) == '\0') {
LAB_0044a693:
            iVar10 = local_f4 * 0x100 + iVar16;
            iVar15 = iVar10 * 8;
            if ((((int)(&DAT_006040ec)[iVar10 * 2] < 1) &&
                (((int)(&DAT_006040ec)[iVar10 * 2] < 0 || ((&g_AttackCount)[iVar10 * 2] == 0)))) &&
               (((&g_TargetFlag)[iVar10 * 2] != 2 || ((&DAT_005e40ec)[iVar10 * 2] != 0)))) {
              iVar12 = (&DAT_0058f8ec)[iVar10 * 2];
              iVar6 = (&DAT_0058f8e8)[iVar10 * 2];
              if ((iVar12 < 0) ||
                 ((((iVar12 < 1 && (iVar6 == 0)) ||
                   (*(int *)(&g_SCOwnership + iVar15) != 0 || *(int *)(&DAT_00520cec + iVar15) != 0)
                   ) || ((&DAT_0052b4e8)[iVar10 * 2] != 0 || (&DAT_0052b4ec)[iVar10 * 2] != 0)))) {
                if ((((iVar6 == 1) && (iVar12 == 0)) && (*(int *)(&g_SCOwnership + iVar15) == 1)) &&
                   ((*(int *)(&DAT_00520cec + iVar15) == 0 &&
                    ((&g_EnemyReachScore)[iVar10 * 2] == 0 && (&DAT_00535cec)[iVar10 * 2] == 0)))) {
                  (&g_ProvTargetFlag)[iVar10 * 2] = 1;
                }
                else {
                  if (((iVar12 < 0) ||
                      (((iVar12 < 1 && (iVar6 == 0)) || (*(int *)(&g_SCOwnership + iVar15) != 1))))
                     || ((*(int *)(&DAT_00520cec + iVar15) != 0 ||
                         ((&g_EnemyReachScore)[iVar10 * 2] != 0 || (&DAT_00535cec)[iVar10 * 2] != 0)
                         ))) goto LAB_0044a777;
                  (&g_ProvTargetFlag)[iVar10 * 2] = 2;
                }
              }
              else {
                (&g_ProvTargetFlag)[iVar10 * 2] = 1;
              }
              (&DAT_005ee8ec)[iVar10 * 2] = 0;
            }
          }
          else {
            uVar4 = *(ushort *)((int)local_dc + iVar15 + 0x20);
            uVar9 = uVar4 & 0xff;
            if ((char)(uVar4 >> 8) != 'A') {
              uVar9 = 0x14;
            }
            if (uVar9 == local_f4) goto LAB_0044a693;
          }
LAB_0044a777:
          iVar15 = *(int *)((int)this + 8);
          iVar16 = iVar16 + 1;
          local_dc = local_dc + 9;
        } while (iVar16 < *(int *)(iVar15 + 0x2400));
      }
      local_d4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_d8 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar10 = local_d4;
        iVar16 = local_d8;
        iVar15 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_d8 == 0) || (local_d8 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar10 == iVar15) break;
        if (iVar16 == 0) {
          FUN_0047a948();
        }
        if (iVar10 == *(int *)(iVar16 + 4)) {
          FUN_0047a948();
        }
        if (*(uint *)(iVar10 + 0x18) == local_f4) {
          if ((iVar10 == *(int *)(iVar16 + 4)) && (FUN_0047a948(), iVar10 == *(int *)(iVar16 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar7 = AdjacencyList_FilterByUnitType
                              ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar10 + 0x10) * 0x24
                                       ),(ushort *)(iVar10 + 0x14));
          local_e8 = (int *)*ppiVar7[1];
          local_ec = ppiVar7;
          while( true ) {
            piVar5 = local_e8;
            ppiVar8 = local_ec;
            piVar14 = ppiVar7[1];
            if ((local_ec == (int **)0x0) || (local_ec != ppiVar7)) {
              FUN_0047a948();
            }
            if (piVar5 == piVar14) break;
            if (ppiVar8 == (int **)0x0) {
              FUN_0047a948();
            }
            if ((piVar5 == ppiVar8[1]) && (FUN_0047a948(), piVar5 == ppiVar8[1])) {
              FUN_0047a948();
            }
            local_dc = AdjacencyList_FilterByUnitType
                                 ((void *)(*(int *)((int)this + 8) + 8 + piVar5[3] * 0x24),
                                  (ushort *)(piVar5 + 4));
            local_b4 = (int *)*local_dc[1];
            local_b8 = local_dc;
            while( true ) {
              piVar14 = local_b4;
              ppiVar8 = local_b8;
              local_64 = local_dc[1];
              if ((local_b8 == (int **)0x0) || (local_b8 != local_dc)) {
                FUN_0047a948();
              }
              if (piVar14 == local_64) break;
              if (ppiVar8 == (int **)0x0) {
                FUN_0047a948();
              }
              if (piVar14 == ppiVar8[1]) {
                FUN_0047a948();
              }
              if (*(char *)(*(int *)((int)this + 8) + 3 + piVar14[3] * 0x24) != '\0') {
                if (piVar14 == ppiVar8[1]) {
                  FUN_0047a948();
                }
                uVar4 = *(ushort *)(*(int *)((int)this + 8) + 0x20 + piVar14[3] * 0x24);
                uVar9 = uVar4 & 0xff;
                if ((char)(uVar4 >> 8) != 'A') {
                  uVar9 = 0x14;
                }
                if ((uVar9 != local_f4) && ((int)(&DAT_00634e90)[local_f4 * 0x15 + uVar9] < 10)) {
                  if (piVar5 == local_ec[1]) {
                    FUN_0047a948();
                  }
                  iVar15 = piVar5[3] + local_f4 * 0x100;
                  if (((&g_ProvTargetFlag)[iVar15 * 2] == 1) && ((&DAT_005ee8ec)[iVar15 * 2] == 0))
                  {
                    if (piVar5 == local_ec[1]) {
                      FUN_0047a948();
                    }
                    iVar15 = piVar5[3] + local_f4 * 0x100;
                    (&g_ProvTargetFlag)[iVar15 * 2] = 0xfffffff6;
                    (&DAT_005ee8ec)[iVar15 * 2] = 0xffffffff;
                  }
                }
              }
              FUN_0040f400((int *)&local_b8);
            }
            FUN_0040f400((int *)&local_ec);
          }
        }
        UnitList_Advance(&local_d8);
      }
      iVar15 = *(int *)((int)this + 8);
      local_c4 = (void *)0x0;
      if (0 < *(int *)(iVar15 + 0x2400)) {
        local_f0 = (int)this + 0x2a1c;
        local_d0 = 0;
        do {
          if (*(char *)(local_d0 + 3 + iVar15) != '\0') {
            uVar4 = *(ushort *)(local_d0 + 0x20 + iVar15);
            uVar9 = uVar4 & 0xff;
            if ((char)(uVar4 >> 8) != 'A') {
              uVar9 = 0x14;
            }
            if ((uVar9 != local_f4) && ((int)(&DAT_00634e90)[local_f4 * 0x15 + uVar9] < 10)) {
              local_c8 = **(int **)(local_f0 + 4);
              local_dc = (int **)0x0;
              local_cc = local_f0;
              while( true ) {
                iVar10 = local_c8;
                iVar16 = local_cc;
                iVar15 = *(int *)(local_f0 + 4);
                if ((local_cc == 0) || (local_cc != local_f0)) {
                  FUN_0047a948();
                }
                if (iVar10 == iVar15) break;
                if (iVar16 == 0) {
                  FUN_0047a948();
                }
                if (iVar10 == *(int *)(iVar16 + 4)) {
                  FUN_0047a948();
                }
                iVar15 = local_f4 * 0x100 + *(int *)(iVar10 + 0xc);
                if (((&g_ProvTargetFlag)[iVar15 * 2] == -10) && ((&DAT_005ee8ec)[iVar15 * 2] == -1))
                {
                  local_dc = (int **)((int)local_dc + 1);
                }
                TreeIterator_Advance(&local_cc);
              }
              local_c8 = **(int **)(local_f0 + 4);
              local_cc = local_f0;
              while( true ) {
                iVar10 = local_c8;
                iVar16 = local_cc;
                iVar15 = *(int *)(local_f0 + 4);
                if ((local_cc == 0) || (local_cc != local_f0)) {
                  FUN_0047a948();
                }
                if (iVar10 == iVar15) break;
                if (iVar16 == 0) {
                  FUN_0047a948();
                }
                if (iVar10 == *(int *)(iVar16 + 4)) {
                  FUN_0047a948();
                }
                iVar15 = *(int *)(iVar10 + 0xc) + local_f4 * 0x100;
                if ((((&g_ProvTargetFlag)[iVar15 * 2] == -10) && ((&DAT_005ee8ec)[iVar15 * 2] == -1)
                    ) && (1 < (int)local_dc)) {
                  if (iVar10 == *(int *)(iVar16 + 4)) {
                    FUN_0047a948();
                  }
                  iVar15 = *(int *)(iVar10 + 0xc) + local_f4 * 0x100;
                  (&g_ProvTargetFlag)[iVar15 * 2] = 1;
                  (&DAT_005ee8ec)[iVar15 * 2] = 0;
                }
                TreeIterator_Advance(&local_cc);
              }
            }
          }
          iVar15 = *(int *)((int)this + 8);
          local_d0 = local_d0 + 0x24;
          local_f0 = local_f0 + 0xc;
          local_c4 = (void *)((int)local_c4 + 1);
        } while ((int)local_c4 < *(int *)(iVar15 + 0x2400));
      }
      local_d4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_d8 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar16 = local_d4;
        iVar15 = local_d8;
        local_44 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_d8 == 0) || (local_d8 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar16 == local_44) break;
        if (iVar15 == 0) {
          FUN_0047a948();
        }
        if (iVar16 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if (*(uint *)(iVar16 + 0x18) == local_f4) {
          if ((iVar16 == *(int *)(iVar15 + 4)) && (FUN_0047a948(), iVar16 == *(int *)(iVar15 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar7 = OrderedSet_FindOrInsert
                              ((void *)(local_9c + 0x4000 + (int)this),(int **)(iVar16 + 0x10));
          iVar10 = local_f4 * 0x100 + *(int *)(iVar16 + 0x10);
          if (((int)ppiVar7[1] <= *(int *)(&DAT_0055b0ec + iVar10 * 8)) &&
             (((int)ppiVar7[1] < *(int *)(&DAT_0055b0ec + iVar10 * 8) ||
              (*ppiVar7 < *(int **)(&g_MaxProvinceScore + iVar10 * 8))))) {
            if (iVar16 == *(int *)(iVar15 + 4)) {
              FUN_0047a948();
            }
            iVar15 = *(int *)(iVar16 + 0x10);
            (&DAT_005b98e8)[iVar15 * 2] = 0;
            (&DAT_005b98ec)[iVar15 * 2] = 0;
          }
        }
        UnitList_Advance(&local_d8);
      }
      local_d4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_d8 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar16 = local_d4;
        iVar15 = local_d8;
        local_24 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_d8 == 0) || (local_d8 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar16 == local_24) break;
        if (iVar15 == 0) {
          FUN_0047a948();
        }
        if (iVar16 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if (*(uint *)(iVar16 + 0x18) == local_f4) {
          if ((iVar16 == *(int *)(iVar15 + 4)) && (FUN_0047a948(), iVar16 == *(int *)(iVar15 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar7 = AdjacencyList_FilterByUnitType
                              ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar16 + 0x10) * 0x24
                                       ),(ushort *)(iVar16 + 0x14));
          local_e8 = (int *)*ppiVar7[1];
          local_ec = ppiVar7;
          while( true ) {
            piVar5 = local_e8;
            ppiVar8 = local_ec;
            piVar14 = ppiVar7[1];
            if ((local_ec == (int **)0x0) || (local_ec != ppiVar7)) {
              FUN_0047a948();
            }
            if (piVar5 == piVar14) break;
            if (ppiVar8 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar5 == ppiVar8[1]) {
              FUN_0047a948();
            }
            ppiVar1 = (int **)(piVar5 + 3);
            if ((&DAT_005b98e8)[piVar5[3] * 2] == 0 && (&DAT_005b98ec)[piVar5[3] * 2] == 0) {
              if (piVar5 == ppiVar8[1]) {
                FUN_0047a948();
              }
              if ((*(int *)(&g_SCOwnership + (int)(*ppiVar1 + local_f4 * 0x40) * 8) == 1) &&
                 (*(int *)(&DAT_00520cec + (int)(*ppiVar1 + local_f4 * 0x40) * 8) == 0)) {
                if (local_e8 == ppiVar8[1]) {
                  FUN_0047a948();
                }
                if (local_e8 == ppiVar8[1]) {
                  FUN_0047a948();
                }
                ppiVar11 = OrderedSet_FindOrInsert((void *)(local_9c + 0x4000 + (int)this),ppiVar1);
                if ((*ppiVar11 ==
                     *(int **)(&g_MaxProvinceScore + (int)(*ppiVar1 + local_f4 * 0x40) * 8)) &&
                   (ppiVar11[1] == *(int **)(&DAT_0055b0ec + (int)(*ppiVar1 + local_f4 * 0x40) * 8))
                   ) {
                  if (local_e8 == ppiVar8[1]) {
                    FUN_0047a948();
                  }
                  piVar14 = *ppiVar1;
                  (&DAT_005b98e8)[(int)piVar14 * 2] = 1;
                  (&DAT_005b98ec)[(int)piVar14 * 2] = 0;
                }
              }
            }
            FUN_0040f400((int *)&local_ec);
          }
        }
        UnitList_Advance(&local_d8);
      }
      BuildSupportOpportunities((int)this);
      local_d4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_d8 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar16 = local_d4;
        iVar15 = local_d8;
        local_34 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_d8 == 0) || (local_d8 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar16 == local_34) break;
        if (iVar15 == 0) {
          FUN_0047a948();
        }
        if (iVar16 == *(int *)(iVar15 + 4)) {
          FUN_0047a948();
        }
        if (*(uint *)(iVar16 + 0x18) == local_f4) {
          if ((iVar16 == *(int *)(iVar15 + 4)) && (FUN_0047a948(), iVar16 == *(int *)(iVar15 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar7 = AdjacencyList_FilterByUnitType
                              ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar16 + 0x10) * 0x24
                                       ),(ushort *)(iVar16 + 0x14));
          local_e8 = (int *)*ppiVar7[1];
          local_ec = ppiVar7;
          while( true ) {
            ppiVar8 = local_ec;
            piVar14 = ppiVar7[1];
            if ((local_ec == (int **)0x0) || (local_ec != ppiVar7)) {
              FUN_0047a948();
            }
            if (local_e8 == piVar14) break;
            if (ppiVar8 == (int **)0x0) {
              FUN_0047a948();
            }
            if (local_e8 == ppiVar8[1]) {
              FUN_0047a948();
            }
            piVar14 = local_e8 + 3;
            if (-1 < (int)(&DAT_004d2e14)[local_e8[3] * 2]) {
              if (local_e8 == ppiVar8[1]) {
                FUN_0047a948();
              }
              local_5c = (int)local_f4 >> 0x1f;
              if (((&g_AllyDesignation_A)[*piVar14 * 2] != local_f4) ||
                 ((&DAT_004d2e14)[*piVar14 * 2] != local_5c)) {
                if (local_e8 == ppiVar8[1]) {
                  FUN_0047a948();
                }
                local_d0 = local_f4 * 0x100;
                if ((-1 < (int)(&DAT_0058f8ec)[(*piVar14 + local_d0) * 2]) &&
                   ((0 < (int)(&DAT_0058f8ec)[(*piVar14 + local_d0) * 2] ||
                    ((&DAT_0058f8e8)[(*piVar14 + local_d0) * 2] != 0)))) {
                  if (local_e8 == ppiVar8[1]) {
                    FUN_0047a948();
                  }
                  ppiVar8 = UnitList_FindOrInsert
                                      ((void *)(*(int *)((int)this + 8) + 0x2450),piVar14);
                  ppiVar8 = AdjacencyList_FilterByUnitType
                                      ((void *)(*(int *)((int)this + 8) + 8 + (int)*ppiVar8 * 0x24),
                                       (ushort *)(ppiVar8 + 1));
                  local_b4 = (int *)*ppiVar8[1];
                  local_b8 = ppiVar8;
                  while( true ) {
                    piVar14 = local_b4;
                    ppiVar1 = local_b8;
                    local_4c = ppiVar8[1];
                    if ((local_b8 == (int **)0x0) || (local_b8 != ppiVar8)) {
                      FUN_0047a948();
                    }
                    if (piVar14 == local_4c) break;
                    if (ppiVar1 == (int **)0x0) {
                      FUN_0047a948();
                    }
                    if (piVar14 == ppiVar1[1]) {
                      FUN_0047a948();
                    }
                    iVar15 = piVar14[3];
                    (&DAT_005cf0e8)[(iVar15 + local_d0) * 2] = 1;
                    (&DAT_005cf0ec)[(iVar15 + local_d0) * 2] = 0;
                    FUN_0040f400((int *)&local_b8);
                  }
                }
              }
            }
            FUN_0040f400((int *)&local_ec);
          }
        }
        UnitList_Advance(&local_d8);
      }
      local_d4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
      local_d8 = *(int *)((int)this + 8) + 0x2450;
      while( true ) {
        iVar10 = local_d4;
        iVar16 = local_d8;
        iVar15 = *(int *)(*(int *)((int)this + 8) + 0x2454);
        if ((local_d8 == 0) || (local_d8 != *(int *)((int)this + 8) + 0x2450)) {
          FUN_0047a948();
        }
        if (iVar10 == iVar15) break;
        if (iVar16 == 0) {
          FUN_0047a948();
        }
        if (iVar10 == *(int *)(iVar16 + 4)) {
          FUN_0047a948();
        }
        if (*(uint *)(iVar10 + 0x18) == local_f4) {
          if ((iVar10 == *(int *)(iVar16 + 4)) && (FUN_0047a948(), iVar10 == *(int *)(iVar16 + 4)))
          {
            FUN_0047a948();
          }
          ppiVar7 = AdjacencyList_FilterByUnitType
                              ((void *)(*(int *)((int)this + 8) + 8 + *(int *)(iVar10 + 0x10) * 0x24
                                       ),(ushort *)(iVar10 + 0x14));
          local_e8 = (int *)*ppiVar7[1];
          local_ec = ppiVar7;
          while( true ) {
            piVar5 = local_e8;
            ppiVar8 = local_ec;
            piVar14 = ppiVar7[1];
            if ((local_ec == (int **)0x0) || (local_ec != ppiVar7)) {
              FUN_0047a948();
            }
            if (piVar5 == piVar14) break;
            if (ppiVar8 == (int **)0x0) {
              FUN_0047a948();
            }
            if (piVar5 == ppiVar8[1]) {
              FUN_0047a948();
            }
            iVar15 = piVar5[3];
            iVar16 = local_f4 * 0x100;
            (&DAT_005c48e8)[(iVar15 + iVar16) * 2] = 1;
            (&DAT_005c48ec)[(iVar15 + iVar16) * 2] = 0;
            local_d0 = iVar16;
            if ((piVar5 == ppiVar8[1]) && (FUN_0047a948(), piVar5 == ppiVar8[1])) {
              FUN_0047a948();
            }
            local_dc = AdjacencyList_FilterByUnitType
                                 ((void *)(*(int *)((int)this + 8) + 8 + piVar5[3] * 0x24),
                                  (ushort *)(piVar5 + 4));
            local_b4 = (int *)*local_dc[1];
            local_b8 = local_dc;
            while( true ) {
              piVar14 = local_b4;
              ppiVar8 = local_b8;
              local_3c = local_dc[1];
              if ((local_b8 == (int **)0x0) || (local_b8 != local_dc)) {
                FUN_0047a948();
              }
              if (piVar14 == local_3c) break;
              if (ppiVar8 == (int **)0x0) {
                FUN_0047a948();
              }
              if (piVar14 == ppiVar8[1]) {
                FUN_0047a948();
              }
              if (*(char *)(*(int *)((int)this + 8) + 3 + piVar14[3] * 0x24) != '\0') {
                if (piVar14 == ppiVar8[1]) {
                  FUN_0047a948();
                }
                iVar15 = piVar14[3];
                (&DAT_005ba0e8)[(iVar15 + iVar16) * 2] = 1;
                (&DAT_005ba0ec)[(iVar15 + iVar16) * 2] = 0;
                if (piVar14 == ppiVar8[1]) {
                  FUN_0047a948();
                }
                local_cc = (int)this + piVar14[3] * 0xc + 0x2a1c;
                local_c8 = **(int **)((int)this + piVar14[3] * 0xc + 0x2a20);
                while( true ) {
                  iVar15 = local_cc;
                  if (piVar14 == ppiVar8[1]) {
                    FUN_0047a948();
                  }
                  iVar16 = *(int *)((int)this + piVar14[3] * 0xc + 0x2a20);
                  if ((iVar15 == 0) || (iVar15 != (int)this + piVar14[3] * 0xc + 0x2a1c)) {
                    FUN_0047a948();
                  }
                  if (local_c8 == iVar16) break;
                  if (iVar15 == 0) {
                    FUN_0047a948();
                  }
                  if (local_c8 == *(int *)(iVar15 + 4)) {
                    FUN_0047a948();
                  }
                  iVar15 = *(int *)(local_c8 + 0xc) + local_d0;
                  (&DAT_005ba0e8)[iVar15 * 2] = 1;
                  (&DAT_005ba0ec)[iVar15 * 2] = 0;
                  TreeIterator_Advance(&local_cc);
                  ppiVar8 = local_b8;
                }
              }
              FUN_0040f400((int *)&local_b8);
              iVar16 = local_d0;
            }
            FUN_0040f400((int *)&local_ec);
          }
        }
        UnitList_Advance(&local_d8);
      }
      local_dc = (int **)0x3;
      do {
        local_d4 = **(int **)(*(int *)((int)this + 8) + 0x2454);
        local_d8 = *(int *)((int)this + 8) + 0x2450;
        while( true ) {
          iVar16 = local_d4;
          iVar15 = local_d8;
          local_2c = *(int *)(*(int *)((int)this + 8) + 0x2454);
          if ((local_d8 == 0) || (local_d8 != *(int *)((int)this + 8) + 0x2450)) {
            FUN_0047a948();
          }
          if (iVar16 == local_2c) break;
          if (iVar15 == 0) {
            FUN_0047a948();
          }
          if (iVar16 == *(int *)(iVar15 + 4)) {
            FUN_0047a948();
          }
          local_d0 = local_f4 * 0x100;
          iVar10 = *(int *)(iVar16 + 0x10) + local_d0;
          if (((&DAT_005c48e8)[iVar10 * 2] == 1) && ((&DAT_005c48ec)[iVar10 * 2] == 0)) {
            if ((iVar16 == *(int *)(iVar15 + 4)) && (FUN_0047a948(), iVar16 == *(int *)(iVar15 + 4))
               ) {
              FUN_0047a948();
            }
            ppiVar7 = AdjacencyList_FilterByUnitType
                                ((void *)(*(int *)((int)this + 8) + 8 +
                                         *(int *)(iVar16 + 0x10) * 0x24),(ushort *)(iVar16 + 0x14));
            local_e8 = (int *)*ppiVar7[1];
            local_ec = ppiVar7;
            while( true ) {
              piVar14 = local_e8;
              ppiVar8 = local_ec;
              local_1c = ppiVar7[1];
              if ((local_ec == (int **)0x0) || (local_ec != ppiVar7)) {
                FUN_0047a948();
              }
              if (piVar14 == local_1c) break;
              if (ppiVar8 == (int **)0x0) {
                FUN_0047a948();
              }
              if (piVar14 == ppiVar8[1]) {
                FUN_0047a948();
              }
              iVar15 = piVar14[3];
              (&DAT_005c48e8)[(iVar15 + local_d0) * 2] = 1;
              (&DAT_005c48ec)[(iVar15 + local_d0) * 2] = 0;
              FUN_0040f400((int *)&local_ec);
            }
          }
          UnitList_Advance(&local_d8);
        }
        local_dc = (int **)((int)local_dc + -1);
      } while (local_dc != (int **)0x0);
      iVar15 = *(int *)((int)this + 8);
      local_c4 = (void *)0x0;
      local_dc = (int **)0x0;
      if (0 < *(int *)(iVar15 + 0x2400)) {
        iVar16 = (int)this + 0x2a1c;
        local_dc = (int **)0x0;
        do {
          if (*(char *)((int)local_dc + iVar15 + 3) != '\0') {
            local_d0 = local_f4 * 0x100;
            pvVar13 = (void *)(local_d0 + (int)local_c4);
            local_78 = (double)CONCAT44(local_78._4_4_,(int)pvVar13 * 8);
            if ((-1 < (int)(&DAT_0058f8ec)[(int)pvVar13 * 2]) &&
               ((0 < (int)(&DAT_0058f8ec)[(int)pvVar13 * 2] ||
                ((&DAT_0058f8e8)[(int)pvVar13 * 2] != 0)))) {
              uVar4 = *(ushort *)((int)local_dc + iVar15 + 0x20);
              uVar9 = uVar4 & 0xff;
              if ((char)(uVar4 >> 8) != 'A') {
                uVar9 = 0x14;
              }
              if (uVar9 != local_f4) {
                local_c8 = **(int **)(iVar16 + 4);
                local_cc = iVar16;
                while( true ) {
                  iVar10 = local_c8;
                  iVar15 = local_cc;
                  local_c = *(int *)(iVar16 + 4);
                  if ((local_cc == 0) || (local_cc != iVar16)) {
                    FUN_0047a948();
                  }
                  if (iVar10 == local_c) break;
                  if (iVar15 == 0) {
                    FUN_0047a948();
                  }
                  if (iVar10 == *(int *)(iVar15 + 4)) {
                    FUN_0047a948();
                  }
                  iVar12 = *(int *)(iVar10 + 0xc) + local_d0;
                  if ((-1 < *(int *)(&DAT_00520cec + iVar12 * 8)) &&
                     ((0 < *(int *)(&DAT_00520cec + iVar12 * 8) ||
                      (*(int *)(&g_SCOwnership + iVar12 * 8) != 0)))) {
                    if (iVar10 == *(int *)(iVar15 + 4)) {
                      FUN_0047a948();
                    }
                    if (*(char *)(*(int *)((int)this + 8) + 3 + *(int *)(iVar10 + 0xc) * 0x24) !=
                        '\0') {
                      if (iVar10 == *(int *)(iVar15 + 4)) {
                        FUN_0047a948();
                      }
                      uVar4 = *(ushort *)
                               (*(int *)((int)this + 8) + 0x20 + *(int *)(iVar10 + 0xc) * 0x24);
                      uVar9 = uVar4 & 0xff;
                      if ((char)(uVar4 >> 8) != 'A') {
                        uVar9 = 0x14;
                      }
                      if (uVar9 != local_f4) goto LAB_0044b6ea;
                    }
                    if (iVar10 == *(int *)(iVar15 + 4)) {
                      FUN_0047a948();
                    }
                    iVar12 = *(int *)((int)this + 8) + 8 + *(int *)(iVar10 + 0xc) * 0x24;
                    local_84 = iVar12;
                    if (iVar10 == *(int *)(iVar15 + 4)) {
                      FUN_0047a948();
                    }
                    local_e4 = *(int **)(iVar10 + 0xc);
                    local_88 = **(int **)(iVar12 + 4);
                    local_8c = iVar12;
                    while( true ) {
                      iVar12 = local_88;
                      iVar10 = local_8c;
                      iVar15 = *(int *)(local_84 + 4);
                      if ((local_8c == 0) || (local_8c != local_84)) {
                        FUN_0047a948();
                      }
                      if (iVar12 == iVar15) break;
                      if (iVar10 == 0) {
                        FUN_0047a948();
                      }
                      if (iVar12 == *(int *)(iVar10 + 4)) {
                        FUN_0047a948();
                      }
                      local_e0 = CONCAT22(local_e0._2_2_,*(undefined2 *)(iVar12 + 0xc));
                      pvVar13 = (void *)(local_9c + 0x4000 + (int)this);
                      ppiVar7 = OrderedSet_FindOrInsert(pvVar13,&local_e4);
                      iVar15 = local_78._0_4_;
                      if ((*(int *)((int)&DAT_005700ec + local_78._0_4_) <= (int)ppiVar7[1]) &&
                         ((*(int *)((int)&DAT_005700ec + local_78._0_4_) < (int)ppiVar7[1] ||
                          (*(int **)((int)&g_ThreatPathScore + local_78._0_4_) < *ppiVar7)))) {
                        ppiVar7 = OrderedSet_FindOrInsert(pvVar13,&local_e4);
                        *(int **)((int)&g_ThreatPathScore + iVar15) = *ppiVar7;
                        *(int **)((int)&DAT_005700ec + iVar15) = ppiVar7[1];
                      }
                      FUN_00401590(&local_8c);
                    }
                  }
LAB_0044b6ea:
                  TreeIterator_Advance(&local_cc);
                }
              }
            }
          }
          iVar15 = *(int *)((int)this + 8);
          local_c4 = (void *)((int)local_c4 + 1);
          local_dc = local_dc + 9;
          iVar16 = iVar16 + 0xc;
        } while ((int)local_c4 < *(int *)(iVar15 + 0x2400));
      }
      local_f4 = local_f4 + 1;
    } while ((int)local_f4 < *(int *)(*(int *)((int)this + 8) + 0x2404));
  }
  return;
}

