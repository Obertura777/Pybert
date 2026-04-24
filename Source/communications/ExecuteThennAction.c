
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall ExecuteThennAction(void *this,uint *param_1)

{
  undefined *this_00;
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  char local_15;
  undefined *local_10;
  undefined4 local_c;
  int local_8 [2];
  
  puVar6 = (undefined *)(uint)*(byte *)(*(int *)((int)this + 8) + 0x2424);
  local_15 = '\0';
  local_10 = puVar6;
  cVar1 = FUN_004117d0((int)param_1);
  if (cVar1 != '\0') {
    return;
  }
  if (9 < g_HistoryCounter) {
    iVar5 = (&DAT_00bb6e14)[(int)param_1 * 3];
    puVar2 = (undefined4 *)FUN_004108a0(&DAT_00bb6e10 + (int)param_1 * 0xc,local_8,&PCE);
    if (((undefined *)*puVar2 == (undefined *)0x0) ||
       ((undefined *)*puVar2 != &DAT_00bb6e10 + (int)param_1 * 0xc)) {
      FUN_0047a948();
    }
    puVar6 = local_10;
    if ((puVar2[1] != iVar5) &&
       (local_15 = FUN_00438b30(this,(uint)param_1), puVar6 = local_10, local_15 != '\0')) {
      return;
    }
  }
  iVar5 = (int)puVar6 * 0x15 + (int)param_1;
  if (((int)(&g_AllyTrustScore_Hi)[iVar5 * 2] < 0) ||
     (((int)(&g_AllyTrustScore_Hi)[iVar5 * 2] < 1 && ((uint)(&g_AllyTrustScore)[iVar5 * 2] < 3)))) {
LAB_00439cfe:
    if (DAT_00baed68 != '\x01') {
      return;
    }
  }
  else if (((int)(&g_AllyTrustScore_Hi)[(int)(puVar6 + (int)param_1 * 0x15) * 2] < 1) &&
          (((int)(&g_AllyTrustScore_Hi)[(int)(puVar6 + (int)param_1 * 0x15) * 2] < 0 ||
           ((uint)(&g_AllyTrustScore)[(int)(puVar6 + (int)param_1 * 0x15) * 2] < 3))))
  goto LAB_00439cfe;
  if (9 < g_HistoryCounter) {
    ppuVar7 = &local_10;
    this_00 = &DAT_00bb6e10 + (int)param_1 * 0xc;
    local_c = (&DAT_00bb6e14)[(int)param_1 * 3];
    local_10 = this_00;
    pvVar3 = (void *)FUN_004108a0(this_00,local_8,&ALY);
    uVar4 = FUN_00401050(pvVar3,(int *)ppuVar7);
    if ((char)uVar4 != '\0') {
      local_c = (&DAT_00bb6e14)[(int)param_1 * 3];
      ppuVar7 = &local_10;
      local_10 = this_00;
      pvVar3 = (void *)FUN_004108a0(this_00,local_8,&VSS);
      uVar4 = FUN_00401050(pvVar3,(int *)ppuVar7);
      if ((char)uVar4 != '\0') {
        local_15 = FUN_004325a0(this,(int)param_1);
      }
    }
  }
  if (g_HistoryCounter < 0x14) {
    return;
  }
  if ((local_15 == '\0') && (_g_NearEndGameFactor < 3.0)) {
    local_10 = &DAT_00bb6e10 + (int)param_1 * 0xc;
    local_c = (&DAT_00bb6e14)[(int)param_1 * 3];
    ppuVar7 = &local_10;
    pvVar3 = (void *)FUN_004108a0(local_10,local_8,&DMZ);
    uVar4 = FUN_00401050(pvVar3,(int *)ppuVar7);
    if (((char)uVar4 != '\0') &&
       ((DAT_00baed68 == '\0' ||
        ((-1 < (int)(&DAT_004d5484)[(int)param_1 * 2] &&
         ((0 < (int)(&DAT_004d5484)[(int)param_1 * 2] ||
          (1 < (uint)(&DAT_004d5480)[(int)param_1 * 2])))))))) {
      local_15 = ProposeDMZ(this,param_1);
    }
  }
  if (g_HistoryCounter < 0x14) {
    return;
  }
  if (local_15 != '\0') {
    return;
  }
  local_c = (&DAT_00bb6e14)[(int)param_1 * 3];
  local_10 = &DAT_00bb6e10 + (int)param_1 * 0xc;
  ppuVar7 = &local_10;
  pvVar3 = (void *)FUN_004108a0(local_10,local_8,&XDO);
  uVar4 = FUN_00401050(pvVar3,(int *)ppuVar7);
  if ((char)uVar4 == '\0') {
    return;
  }
  if ((-1 < (int)(&g_AllyTrustScore_Hi)[iVar5 * 2]) &&
     ((0 < (int)(&g_AllyTrustScore_Hi)[iVar5 * 2] || (2 < (uint)(&g_AllyTrustScore)[iVar5 * 2])))) {
    if ((0 < (int)(&g_AllyTrustScore_Hi)[(int)(puVar6 + (int)param_1 * 0x15) * 2]) ||
       ((-1 < (int)(&g_AllyTrustScore_Hi)[(int)(puVar6 + (int)param_1 * 0x15) * 2] &&
        (2 < (uint)(&g_AllyTrustScore)[(int)(puVar6 + (int)param_1 * 0x15) * 2]))))
    goto LAB_00439eaf;
  }
  if ((&curr_sc_cnt)[(int)puVar6] != 1) {
    return;
  }
  if ((int)(&g_AllyTrustScore_Hi)[(int)(puVar6 + (int)param_1 * 0x15) * 2] < 0) {
    return;
  }
  if (((int)(&g_AllyTrustScore_Hi)[(int)(puVar6 + (int)param_1 * 0x15) * 2] < 1) &&
     ((&g_AllyTrustScore)[(int)(puVar6 + (int)param_1 * 0x15) * 2] == 0)) {
    return;
  }
LAB_00439eaf:
  FUN_00433510(this,(int)param_1);
  return;
}

