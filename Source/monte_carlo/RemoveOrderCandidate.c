
void __thiscall RemoveOrderCandidate(void *this,int *param_1,int param_2,int **param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int **_Memory;
  int **ppiVar5;
  undefined4 uVar6;
  int **ppiVar7;
  int **ppiVar8;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00494c18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  _Memory = param_3;
  if (*(char *)((int)param_3 + 0x21) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    FUN_00402650(local_50,(undefined4 *)"invalid map/set<T> iterator",0x1b);
    local_4 = 0;
    FUN_00402a30(local_34,local_50);
    local_34[0] = std::out_of_range::vftable;
    _Memory = (int **)__CxxThrowException@8(local_34,&DAT_004bb89c);
  }
  std_Tree_IteratorIncrement(&param_2);
  ppiVar7 = (int **)*_Memory;
  if (*(char *)((int)ppiVar7 + 0x21) == '\0') {
    ppiVar8 = ppiVar7;
    if ((*(char *)((int)_Memory[2] + 0x21) == '\0') &&
       (ppiVar8 = (int **)param_3[2], param_3 != _Memory)) {
      ppiVar7[1] = (int *)param_3;
      *param_3 = *_Memory;
      ppiVar7 = param_3;
      if (param_3 != (int **)_Memory[2]) {
        ppiVar7 = (int **)param_3[1];
        if (*(char *)((int)ppiVar8 + 0x21) == '\0') {
          ppiVar8[1] = (int *)ppiVar7;
        }
        *ppiVar7 = (int *)ppiVar8;
        param_3[2] = _Memory[2];
        _Memory[2][1] = (int)param_3;
      }
      if (*(int ***)(*(int *)((int)this + 4) + 4) == _Memory) {
        *(int ***)(*(int *)((int)this + 4) + 4) = param_3;
      }
      else {
        piVar4 = _Memory[1];
        if ((int **)*piVar4 == _Memory) {
          *piVar4 = (int)param_3;
        }
        else {
          piVar4[2] = (int)param_3;
        }
      }
      param_3[1] = _Memory[1];
      uVar1 = *(undefined1 *)(param_3 + 8);
      *(undefined1 *)(param_3 + 8) = *(undefined1 *)(_Memory + 8);
      *(undefined1 *)(_Memory + 8) = uVar1;
      goto LAB_00412975;
    }
  }
  else {
    ppiVar8 = (int **)_Memory[2];
  }
  ppiVar7 = (int **)_Memory[1];
  if (*(char *)((int)ppiVar8 + 0x21) == '\0') {
    ppiVar8[1] = (int *)ppiVar7;
  }
  if (*(int ***)(*(int *)((int)this + 4) + 4) == _Memory) {
    *(int ***)(*(int *)((int)this + 4) + 4) = ppiVar8;
  }
  else if ((int **)*ppiVar7 == _Memory) {
    *ppiVar7 = (int *)ppiVar8;
  }
  else {
    ppiVar7[2] = (int *)ppiVar8;
  }
  puVar2 = *(undefined4 **)((int)this + 4);
  if ((int **)*puVar2 == _Memory) {
    ppiVar5 = ppiVar7;
    if (*(char *)((int)ppiVar8 + 0x21) == '\0') {
      ppiVar5 = (int **)FUN_0040e3e0(ppiVar8);
    }
    *puVar2 = ppiVar5;
  }
  iVar3 = *(int *)((int)this + 4);
  if (*(int ***)(iVar3 + 8) == _Memory) {
    if (*(char *)((int)ppiVar8 + 0x21) == '\0') {
      uVar6 = FUN_0040e3c0((int)ppiVar8);
      *(undefined4 *)(iVar3 + 8) = uVar6;
    }
    else {
      *(int ***)(iVar3 + 8) = ppiVar7;
    }
  }
LAB_00412975:
  if (*(char *)(_Memory + 8) == '\x01') {
    if (ppiVar8 != *(int ***)(*(int *)((int)this + 4) + 4)) {
      do {
        ppiVar5 = ppiVar7;
        if (*(char *)(ppiVar8 + 8) != '\x01') break;
        ppiVar7 = (int **)*ppiVar5;
        if (ppiVar8 == ppiVar7) {
          ppiVar7 = (int **)ppiVar5[2];
          if (*(char *)(ppiVar7 + 8) == '\0') {
            *(undefined1 *)(ppiVar7 + 8) = 1;
            *(undefined1 *)(ppiVar5 + 8) = 0;
            FUN_0040f120(this,(int *)ppiVar5);
            ppiVar7 = (int **)ppiVar5[2];
          }
          if (*(char *)((int)ppiVar7 + 0x21) == '\0') {
            if (((char)(*ppiVar7)[8] != '\x01') || ((char)ppiVar7[2][8] != '\x01')) {
              if ((char)ppiVar7[2][8] == '\x01') {
                *(undefined1 *)(*ppiVar7 + 8) = 1;
                *(undefined1 *)(ppiVar7 + 8) = 0;
                FUN_0040eb10(this,(int *)ppiVar7);
                ppiVar7 = (int **)ppiVar5[2];
              }
              *(undefined1 *)(ppiVar7 + 8) = *(undefined1 *)(ppiVar5 + 8);
              *(undefined1 *)(ppiVar5 + 8) = 1;
              *(undefined1 *)(ppiVar7[2] + 8) = 1;
              FUN_0040f120(this,(int *)ppiVar5);
              break;
            }
LAB_00412a2e:
            *(undefined1 *)(ppiVar7 + 8) = 0;
          }
        }
        else {
          if (*(char *)(ppiVar7 + 8) == '\0') {
            *(undefined1 *)(ppiVar7 + 8) = 1;
            *(undefined1 *)(ppiVar5 + 8) = 0;
            FUN_0040eb10(this,(int *)ppiVar5);
            ppiVar7 = (int **)*ppiVar5;
          }
          if (*(char *)((int)ppiVar7 + 0x21) == '\0') {
            if (((char)ppiVar7[2][8] == '\x01') && ((char)(*ppiVar7)[8] == '\x01'))
            goto LAB_00412a2e;
            if ((char)(*ppiVar7)[8] == '\x01') {
              *(undefined1 *)(ppiVar7[2] + 8) = 1;
              *(undefined1 *)(ppiVar7 + 8) = 0;
              FUN_0040f120(this,(int *)ppiVar7);
              ppiVar7 = (int **)*ppiVar5;
            }
            *(undefined1 *)(ppiVar7 + 8) = *(undefined1 *)(ppiVar5 + 8);
            *(undefined1 *)(ppiVar5 + 8) = 1;
            *(undefined1 *)(*ppiVar7 + 8) = 1;
            FUN_0040eb10(this,(int *)ppiVar5);
            break;
          }
        }
        ppiVar7 = (int **)ppiVar5[1];
        ppiVar8 = ppiVar5;
      } while (ppiVar5 != *(int ***)(*(int *)((int)this + 4) + 4));
    }
    *(undefined1 *)(ppiVar8 + 8) = 1;
  }
  _free(_Memory);
  if (*(int *)((int)this + 8) != 0) {
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  }
  *param_1 = param_2;
  param_1[1] = (int)param_3;
  ExceptionList = local_c;
  return;
}

