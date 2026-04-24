
void ClearConvoyState(void)

{
  return;
}


int __fastcall ClearProvinceState(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x18)) {
    return *(int *)(param_1 + 4);
  }
  return param_1 + 4;
}

