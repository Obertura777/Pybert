
void __thiscall YESDispatcher(void *this,void *param_1)

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
  puStack_8 = &LAB_00498be8;
  local_c = ExceptionList;
  uVar2 = DAT_004c8db8 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_c;
  GetSubList(param_1,local_2c,1);
  local_4 = 0;
  psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
  if (NME == *psVar3) {
    puVar4 = GetSubList(local_2c,local_1c,1);
    local_4._0_1_ = 1;
    (**(code **)(*(int *)this + 0x98))(pvVar1,puVar4);
    local_4 = (uint)local_4._1_3_ << 8;
    FreeList(local_1c);
  }
  else {
    psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
    if (OBS == *psVar3) {
      puVar4 = GetSubList(local_2c,local_1c,1);
      local_4._0_1_ = 2;
      (**(code **)(*(int *)this + 0x9c))(pvVar1,puVar4,uVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      FreeList(local_1c);
    }
    else {
      psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
      if (IAM == *psVar3) {
        puVar4 = GetSubList(local_2c,local_1c,1);
        local_4._0_1_ = 3;
        (**(code **)(*(int *)this + 0xa0))(pvVar1,puVar4);
        local_4 = (uint)local_4._1_3_ << 8;
        FreeList(local_1c);
      }
      else {
        psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
        if (NOT == *psVar3) {
          puVar4 = GetSubList(local_2c,local_1c,1);
          local_4._0_1_ = 4;
          FUN_0045b070(this,pvVar1,puVar4);
          local_4 = (uint)local_4._1_3_ << 8;
          FreeList(local_1c);
        }
        else {
          psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
          if (GOF == *psVar3) {
            puVar4 = GetSubList(local_2c,local_1c,1);
            local_4._0_1_ = 5;
            (**(code **)(*(int *)this + 0xa4))(pvVar1,puVar4);
            local_4 = (uint)local_4._1_3_ << 8;
            FreeList(local_1c);
          }
          else {
            psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
            if (TME == *psVar3) {
              puVar4 = GetSubList(local_2c,local_1c,1);
              local_4._0_1_ = 6;
              (**(code **)(*(int *)this + 0xa8))(pvVar1,puVar4);
              local_4 = (uint)local_4._1_3_ << 8;
              FreeList(local_1c);
            }
            else {
              psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
              if (DRW == *psVar3) {
                puVar4 = GetSubList(local_2c,local_1c,1);
                local_4._0_1_ = 7;
                (**(code **)(*(int *)this + 0xac))(pvVar1,puVar4);
                local_4 = (uint)local_4._1_3_ << 8;
                FreeList(local_1c);
              }
              else {
                psVar3 = (short *)GetListElement(local_2c,(undefined2 *)&param_1,0);
                if (SND == *psVar3) {
                  puVar4 = GetSubList(local_2c,local_1c,1);
                  local_4._0_1_ = 8;
                  FUN_0045d210(this,pvVar1,puVar4);
                  local_4 = (uint)local_4._1_3_ << 8;
                  FreeList(local_1c);
                }
                else {
                  (**(code **)(*(int *)this + 0xcc))(pvVar1);
                }
              }
            }
          }
        }
      }
    }
  }
  local_4 = 0xffffffff;
  FreeList(local_2c);
  ExceptionList = local_c;
  return;
}

