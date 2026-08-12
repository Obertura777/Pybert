// NOTDispatcher — routes NOT ( ... ) messages to per-variant handlers.
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == NOT.
//
// Routes:
//   NOT ( CCD ( power ) )  → FUN_0045e9f0     (NOT_CCD_Handler.c)
//   NOT ( TME ( seconds ) ) → vtable +0x50    (NOT_TME_Handler.c)
//   NOT ( ... )            → vtable +0xc0     (unknown/fallback)
//
// C flow:
//   GetSubList(param_1, local_2c, 1)           — extract the NOT body sub-list
//   GetListElement(local_2c, ..., 0)           — read first token of body
//   if CCD  → GetSubList → FUN_0045e9f0(this, full_msg, ccd_sublist)
//   if TME  → GetSubList → (*vtable+0x50)(full_msg, tme_sublist)
//   else    → (*vtable+0xc0)(full_msg, ...)
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (Source/communications/InboundDAIDEDispatcher.c)
//   CCD branch → FUN_0045e9f0 (Source/communications/NOT_CCD_Handler.c lines 25-29)
//   TME branch → vtable +0x50 (Source/communications/NOT_TME_Handler.c lines 35-38)
//
// Python equivalent: not_dispatcher (communications/inbound/dispatcher.py)

void __thiscall NOTDispatcher(void *this,void *param_1)

{
  void *pvVar1;
  uint uVar2;
  short *psVar3;
  undefined4 *puVar4;
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  pvVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00498e48;
  local_c = ExceptionList;
  uVar2 = DAT_004c8db8 ^ (uint)&stack0xffffffcc;
  ExceptionList = &local_c;
  GetSubList(param_1,local_2c,1);
  local_4 = 0;
  psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
  if (CCD == *psVar3) {
    puVar4 = GetSubList(local_2c,local_1c,1);
    local_4._0_1_ = 1;
    FUN_0045e9f0(this,pvVar1,puVar4);
    local_4 = (uint)local_4._1_3_ << 8;
    FreeList(local_1c);
  }
  else {
    psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
    if (TME == *psVar3) {
      puVar4 = GetSubList(local_2c,local_1c,1);
      local_4._0_1_ = 2;
      (**(code **)(*(int *)this + 0x50))(pvVar1,puVar4);
      local_4 = (uint)local_4._1_3_ << 8;
      FreeList(local_1c);
    }
    else {
      (**(code **)(*(int *)this + 0xc0))(pvVar1,uVar2);
    }
  }
  local_4 = 0xffffffff;
  FreeList(local_2c);
  ExceptionList = local_c;
  return;
}

