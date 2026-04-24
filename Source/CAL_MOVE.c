
char __thiscall CAL_MOVE(void *this)

{
  char cVar1;
  short *psVar2;
  undefined4 uVar3;
  void **ppvVar4;
  int **in_stack_00000018;
  undefined1 auStack_48 [4];
  undefined4 uStack_44;
  undefined1 *local_20;
  undefined1 *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00496238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  cVar1 = '\0';
  psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
  if (PCE == *psVar2) {
    local_20 = &stack0xffffffc4;
    uStack_44 = 0x424135;
    FUN_00465f60(&stack0xffffffc4,(void **)&stack0x00000004);
    cVar1 = PCE((int)this);
  }
  else {
    psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
    if (ALY == *psVar2) {
      local_20 = &stack0xffffffc4;
      uStack_44 = 0x424175;
      FUN_00465f60(&stack0xffffffc4,(void **)&stack0x00000004);
      cVar1 = ALY((int)this);
    }
    else {
      psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
      if (DMZ == *psVar2) {
        local_20 = &stack0xffffffc4;
        uStack_44 = 0x4241b5;
        FUN_00465f60(&stack0xffffffc4,(void **)&stack0x00000004);
        cVar1 = DMZ((int)this);
      }
      else {
        psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
        if (XDO == *psVar2) {
          local_20 = &stack0xffffffc8;
          FUN_00405090(&stack0xffffffc8,(int)&stack0x00000014);
          local_1c[0] = auStack_48;
          local_4._0_1_ = 2;
          FUN_00465f60(auStack_48,(void **)&stack0x00000004);
          local_4._0_1_ = 1;
          uVar3 = XDO();
          cVar1 = (char)uVar3;
        }
        else {
          psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
          if (NOT == *psVar2) {
            ppvVar4 = (void **)GetSubList(&stack0x00000004,local_1c,1);
            local_4._0_1_ = 3;
            AppendList(&stack0x00000004,ppvVar4);
            local_4._0_1_ = 1;
            FreeList(local_1c);
            psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
            if (PCE == *psVar2) {
              local_1c[0] = &stack0xffffffc4;
              uStack_44 = 0x4242a4;
              FUN_00465f60(&stack0xffffffc4,(void **)&stack0x00000004);
              cVar1 = CANCEL(this);
            }
            else {
              psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
              if (DMZ == *psVar2) {
                local_1c[0] = &stack0xffffffc4;
                uStack_44 = 0x4242e4;
                FUN_00465f60(&stack0xffffffc4,(void **)&stack0x00000004);
                cVar1 = REMOVE_DMZ((int)this);
              }
              else {
                psVar2 = (short *)GetListElement(&stack0x00000004,(undefined2 *)&local_20,0);
                if (XDO == *psVar2) {
                  local_1c[0] = &stack0xffffffc8;
                  FUN_00405090(&stack0xffffffc8,(int)&stack0x00000014);
                  local_20 = auStack_48;
                  local_4._0_1_ = 4;
                  FUN_00465f60(auStack_48,(void **)&stack0x00000004);
                  local_4._0_1_ = 1;
                  uVar3 = NOT_XDO();
                  cVar1 = (char)uVar3;
                }
              }
            }
          }
        }
      }
    }
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList((void **)&stack0x00000004);
  local_4 = 0xffffffff;
  uStack_44 = 0x424377;
  SerializeOrders(&stack0x00000014,local_1c,&stack0x00000014,(int **)*in_stack_00000018,
                  &stack0x00000014,in_stack_00000018);
  _free(in_stack_00000018);
  ExceptionList = local_c;
  return cVar1;
}

