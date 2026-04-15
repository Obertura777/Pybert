// FUN_00465c70 — TokenList::BuildOffsetArray (lazy)
// Called from FUN_00466110 (GetSublistStreamOffset) the first time a
// `TokenList` with nested sublists is indexed. Allocates an `(N+1)`-entry
// int32 offset array where N = param_1[3] (pre-counted top-level element
// count). Walks the raw token stream tracking paren depth; each time depth
// returns to zero, records the current token index as the start of a new
// top-level element. The final slot holds param_1[1] (token count) as an
// end sentinel so callers can compute element length via offset[i+1]-offset[i].
//
// param_1 layout (TokenList):
//   [0] short* tokens          (raw token stream)
//   [1] int    token_count
//   [2] int*   offsets         (built here; element start indices)
//   [3] int    top_level_count (pre-counted)
//
// DAT_004c79b4 = open-paren token (BRA), DAT_004c79b8 = close-paren (KET).
// Not ported to Python — the rewrite consumes diplomacy.Game directly and
// never tokenizes DAIDE streams.

void __fastcall FUN_00465c70(int *param_1)
{
  short sVar1;
  longlong lVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  iVar6 = 0;
  lVar2 = (ulonglong)(param_1[3] + 1) * 4;
  pvVar3 = operator_new(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  param_1[2] = (int)pvVar3;
  iVar4 = 0;
  if (0 < param_1[1]) {
    iVar5 = 0;
    do {
      if (iVar6 == 0) {
        *(int *)(iVar5 + param_1[2]) = iVar4;
        iVar5 = iVar5 + 4;
      }
      sVar1 = *(short *)(*param_1 + iVar4 * 2);
      if (DAT_004c79b4 == sVar1) {
        iVar6 = iVar6 + 1;
      }
      if (DAT_004c79b8 == sVar1) {
        iVar6 = iVar6 + -1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1[1]);
  }
  *(int *)(param_1[2] + param_1[3] * 4) = param_1[1];
  return;
}
