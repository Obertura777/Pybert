
void __cdecl QueueIncomingMessage(void *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *this;
  void *local_c;
  uint local_8;
  undefined4 local_4;
  
  local_c = operator_new(param_2);
  if (local_c == (void *)0x0) {
    ERR("Failed to allocate memory to queue message");
    return;
  }
  local_8 = param_2;
  local_4 = param_3;
  _memcpy(local_c,param_1,param_2);
  WaitForSingleObject(g_NetworkState->field30_0x24,0xffffffff);
  iVar1 = g_NetworkState->field25_0x1c;
  this = &g_NetworkState->field21_0x18;
  iVar2 = FUN_0045bae0(iVar1,*(undefined4 *)(iVar1 + 4),&local_c);
  FUN_0045d3b0(this,1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  ReleaseMutex(g_NetworkState->field30_0x24);
  PostMessageA(*(HWND *)(g_NetworkState->field4_0x4 + 0x20),0x4149,0,0);
  return;
}

