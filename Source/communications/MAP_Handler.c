// FUN_0045e310 — MAP handler
// Called from InboundDAIDEDispatcher (FUN_0045f1f0) when first token == MAP.
// DAIDE: MAP ( 'map_name' )
//
// Extracts the map-name token group at sub-element [1] and appends it onto
// the TokenList at inner+0x2560 (g_map_name_tokens). Then fires vtable +0x54
// (on-MAP hook — subclass sends MDF request and begins map-load sequence).
//
// Inner-state write:
//   inner+0x2560 — TokenList holding map-name token sequence (AppendList)
//
// C References:
//   InboundDAIDEDispatcher → FUN_0045f1f0 (line: MAP == sVar1 branch)
//   on-MAP vtable slot: +0x54
//
// Python equivalent: handle_map (communications/inbound/server_handlers.py)
//   stores groups[0] in state.g_map_name.

void __thiscall FUN_0045e310(void *this,void *param_1)

{
  void *pvVar1;
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497f80;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Extract sub-element [1] — map-name token group
  pvVar1 = GetSubList(param_1,local_1c,1);
  local_4 = 0;

  // Append map-name tokens onto inner+0x2560 (g_map_name_tokens)
  AppendList((void *)(*(int *)((int)this + 8) + 0x2560),pvVar1);

  // Fire on-MAP hook: subclass sends MDF request and loads map topology
  (**(code **)(*(int *)this + 0x54))();

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  return;
}
