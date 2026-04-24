
bool CheckTimeLimit(void)

{
  int iVar1;
  
  WaitForSingleObject(g_NetworkState->field30_0x24,0xffffffff);
  iVar1 = *(int *)&g_NetworkState->field_0x20;
  ReleaseMutex(g_NetworkState->field30_0x24);
  return iVar1 != 0;
}

