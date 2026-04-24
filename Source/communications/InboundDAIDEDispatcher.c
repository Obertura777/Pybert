// FUN_0045f1f0 — InboundDAIDEDispatcher
// Top-level DAIDE inbound message handler. Tokenizes the raw wire bytes
// into a TokenList, validates the parenthesization via FUN_00466160, then
// branches on the first token to the appropriate per-message handler.
//
// Discovered 2026-04-14 via cross-reference on HLO. Critical sibling
// addresses anchored here:
//   HLO → FUN_0045abf0   (HLO_Dispatch — still to export)
//   MAP → FUN_0045e310
//   MDF → FUN_0045ad50
//   NOW → FUN_0045aeb0   (NOWHandler — already audited)
//   ORD → FUN_0045aee0
//   SCO → FUN_0045af10
//   NOT → NOTDispatcher
//   REJ → FUN_0045d600
//   YES → YESDispatcher
//   CCD → FUN_0045e470
//   OUT → FUN_0045d180
//   DRW/SLO/FRM/HUH/LOD/MIS/OFF/SVE/THX/TME/ADM → vtable dispatch
//
// PRN (protocol error / print) token bypasses tokenization entirely and
// goes straight to vtable slot +0x34.

void __thiscall FUN_0045f1f0(void *this,short *param_1,int param_2)
{
  short sVar1;
  uint uVar2;
  short *psVar3;
  void *local_38 [4];
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00498e80;
  local_c = ExceptionList;
  uVar2 = DAT_004c8db8 ^ (uint)&stack0xffffffc4;
  ExceptionList = &local_c;
  FUN_00465870(local_38);
  local_4 = 0;
  if (PRN == *param_1) {
    (**(code **)(*(int *)this + 0x34))(param_1,param_2,uVar2);
  }
  else {
    FUN_00465940(local_38,param_1,(uint *)(param_2 / 2));
    TokenSeq_Finalize('\x01',local_38);
    uVar2 = FUN_00466160(local_38,0);
    if ((char)uVar2 == '\0') {
      ERR("Illegal message received");
    }
    else {
      psVar3 = (short *)GetListElement(local_38,(undefined2 *)&param_2,0);
      sVar1 = *psVar3;
      if (HLO == sVar1) { FUN_0045abf0(this,(undefined *)local_38); }
      else if (MAP == sVar1) { FUN_0045e310(this,local_38); }
      else if (MDF == sVar1) { FUN_0045ad50(this,local_38); }
      else if (NOW == sVar1) { FUN_0045aeb0(this,local_38); }
      else if (ORD == sVar1) { FUN_0045aee0(this,local_38); }
      else if (SCO == sVar1) { FUN_0045af10(this,local_38); }
      else if (NOT == sVar1) { NOTDispatcher(this,local_38); }
      else if (REJ == sVar1) { FUN_0045d600(this,local_38); }
      else if (YES == sVar1) { YESDispatcher(this,local_38); }
      else if (CCD == sVar1) { FUN_0045e470(this,local_38); }
      else if (DRW == sVar1) {
        *(undefined1 *)(*(int *)((int)this + 8) + 0x2449) = 1;
        (**(code **)(*(int *)this + 0x18))(local_38);
      }
      else if (FRM == sVar1) { (**(code **)(*(int *)this + 0x1c))(local_38); }
      else if (HUH == sVar1) { (**(code **)(*(int *)this + 0x20))(local_38); }
      else if (LOD == sVar1) { (**(code **)(*(int *)this + 0x24))(local_38); }
      else if (MIS == sVar1) { (**(code **)(*(int *)this + 0x28))(local_38); }
      else if (OFF == sVar1) { (**(code **)(*(int *)this + 0x2c))(local_38); }
      else if (OUT == sVar1) { FUN_0045d180(this,local_38); }
      else if (SLO == sVar1) {
        *(undefined1 *)(*(int *)((int)this + 8) + 0x2449) = 1;
        (**(code **)(*(int *)this + 0xec))(local_38);
      }
      else if (DAT_004c70e8 == sVar1) { (**(code **)(*(int *)this + 0x38))(local_38); }
      else if (SVE == sVar1) { (**(code **)(*(int *)this + 0x3c))(local_38); }
      else if (THX == sVar1) { (**(code **)(*(int *)this + 0x40))(local_38); }
      else if (TME == sVar1) { (**(code **)(*(int *)this + 0x44))(local_38); }
      else if (ADM == sVar1) { (**(code **)(*(int *)this + 0x48))(local_38); }
      else {
        FUN_0046b050(local_38,local_28);
        local_4 = CONCAT31(local_4._1_3_,1);
        ERR("Unexpected first token in message : %s");
        FUN_0045bb70((int)local_28);
      }
    }
  }
  local_4 = 0xffffffff;
  FreeList(local_38);
  ExceptionList = local_c;
  return;
}
