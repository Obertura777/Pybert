
void __thiscall RECEIVE_MSG(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00498938;
  local_c = ExceptionList;
  uVar2 = DAT_004c8db8 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_c;
  pvStack_10 = this;
  piVar3 = FUN_0047020b();
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040b5a0(-0x7fffbffb);
  }
  iVar4 = (**(code **)(*piVar3 + 0xc))(uVar2);
  pvVar5 = (void *)(iVar4 + 0x10);
  uStack_4 = 0;
  pvStack_10 = pvVar5;
  switch(*(undefined2 *)(param_1 + 8)) {
  case 1:
    LOG("Connected Message received");
    FUN_0045ab70(this,param_1);
    break;
  default:
    LOG("Unexpected Local Message received");
    ERR("Unexpected Local message event %d");
    break;
  case 3:
    LOG("Out of Memory Message received");
    ERR("Out of Memory");
    break;
  case 5:
    SEND_LOG(&pvStack_10,(wchar_t *)"Read Error Message received. Error code %d");
    pvVar5 = pvStack_10;
    LOG(pvStack_10);
    pcVar1 = *(code **)(*(int *)this + 0xf8);
    *(undefined1 *)((int)this + 0x28) = 0;
    (*pcVar1)();
    break;
  case 6:
    SEND_LOG(&pvStack_10,(wchar_t *)"Write Error Message received. Error code %d");
    pvVar5 = pvStack_10;
    LOG(pvStack_10);
    pcVar1 = *(code **)(*(int *)this + 0xf8);
    *(undefined1 *)((int)this + 0x28) = 0;
    (*pcVar1)();
    break;
  case 7:
    LOG("Close Message received");
    pcVar1 = *(code **)(*(int *)this + 0xf8);
    *(undefined1 *)((int)this + 0x28) = 0;
    (*pcVar1)();
  }
  uStack_4 = 0xffffffff;
  piVar3 = (int *)((int)pvVar5 + -4);
  LOCK();
  iVar4 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar4 == 1 || iVar4 + -1 < 0) {
    (**(code **)(**(int **)((int)pvVar5 + -0x10) + 4))((undefined4 *)((int)pvVar5 + -0x10));
  }
  ExceptionList = local_c;
  return;
}

