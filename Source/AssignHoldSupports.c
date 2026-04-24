
void __thiscall AssignHoldSupports(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14 [4];
  
  FUN_004019f0(*(int **)(*(int *)((int)this + 0x4d00) + 4));
  *(int *)(*(int *)((int)this + 0x4d00) + 4) = *(int *)((int)this + 0x4d00);
  *(undefined4 *)((int)this + 0x4d04) = 0;
  *(undefined4 *)*(undefined4 *)((int)this + 0x4d00) = *(undefined4 *)((int)this + 0x4d00);
  *(int *)(*(int *)((int)this + 0x4d00) + 8) = *(int *)((int)this + 0x4d00);
  local_20 = **(int **)(param_1 + 4);
  local_24 = param_1;
  while( true ) {
    iVar1 = local_24;
    iVar2 = *(int *)(param_1 + 4);
    if ((local_24 == 0) || (local_24 != param_1)) {
      FUN_0047a948();
    }
    if (local_20 == iVar2) break;
    iVar2 = _rand();
    if (iVar1 == 0) {
      FUN_0047a948();
    }
    if (local_20 == *(int *)(iVar1 + 4)) {
      FUN_0047a948();
    }
    local_18 = *(undefined4 *)(local_20 + 0xc);
    local_1c = (iVar2 / 0x17) % 0x7c17 + 500;
    ScoreConvoyFleet((void *)((int)this + 0x4cfc),local_14,&local_1c);
    TreeIterator_Advance(&local_24);
  }
  return;
}

