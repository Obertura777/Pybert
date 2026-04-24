
void __thiscall SendDM(void *this,void *param_1)

{
  int iVar1;
  undefined1 *_Memory;
  
  TokenSeq_Finalize('\0',param_1);
  if (*(char *)((int)this + 0x28) != '\0') {
    iVar1 = TokenSeq_Count((int)param_1);
    _Memory = operator_new(iVar1 * 2 + 6);
    *(short *)(_Memory + 2) = (short)iVar1 * 2;
    *_Memory = 2;
    TokenSeq_CopyToBuffer(param_1,_Memory + 4,iVar1 + 1);
    iVar1 = dcsp_client_send_message(_Memory,iVar1 * 2 + 4);
    if (iVar1 == 0) {
      ERR("Failed to send message");
    }
    _free(_Memory);
    return;
  }
  LOG("Message not sent - not connected");
  return;
}

