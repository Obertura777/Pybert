// FUN_0045aee0 — ORD handler
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == ORD.
// DAIDE: ORD ( season year ) ( order ) ( result_token )
//
// Extracts the three sub-elements (turn, order, result) and appends the order
// and result sub-lists onto the history list at inner+0x2580 (g_ord_history).
// The turn sub-list is used only to locate the insertion point (appended last).
//
// Sub-element layout:
//   [1] turn   — ( SPR 1901 ) or ( FAL 1901 ) etc.
//   [2] order  — ( power unit_type province move... )
//   [3] result — ( SUC ) | ( BNC ) | ( CUT ) | ( DSR ) | ( NSO ) | ( RET ... )
//
// Inner-state write:
//   inner+0x2580 — std::list or TokenList of (turn, order, result) records;
//                  each call appends one record via AppendList.
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (line: ORD == sVar1 branch)
//
// Python equivalent: handle_ord (communications/inbound/server_handlers.py)
//   appends {'turn': turn_str, 'groups': groups[1:], 'raw': message}
//   to state.g_ord_results.

void __thiscall FUN_0045aee0(void *this,void *param_1)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *local_3c [4];
  void *local_2c [4];
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497d10;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Extract sub-element [1]: turn ( season year )
  pvVar1 = GetSubList(param_1,local_3c,1);
  local_4 = 0;

  // Extract sub-element [2]: order
  pvVar2 = GetSubList(param_1,local_2c,2);
  local_4._0_1_ = 1;

  // Extract sub-element [3]: result token
  pvVar3 = GetSubList(param_1,local_1c,3);
  local_4._0_1_ = 2;

  // Append all three groups onto the ORD history list at inner+0x2580
  AppendList((void *)(*(int *)((int)this + 8) + 0x2580),pvVar1);
  AppendList((void *)(*(int *)((int)this + 8) + 0x2580),pvVar2);
  AppendList((void *)(*(int *)((int)this + 8) + 0x2580),pvVar3);

  local_4 = CONCAT31(local_4._1_3_,1);
  FreeList(local_1c);
  local_4._0_1_ = 1;
  FreeList(local_2c);
  local_4 = (uint)local_4._1_3_ << 8;
  FreeList(local_3c);
  ExceptionList = local_c;
  return;
}
