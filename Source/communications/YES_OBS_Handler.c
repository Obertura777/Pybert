// vtable +0x9c — YES_OBS handler (virtual method)
// Called from YESDispatcher (Source/communications/YESDispatcher.c) when the
// inner token of a YES message is OBS:
//   YES ( OBS )
// Vtable call: (**(code **)(*(int *)this + 0x9c))(pvVar1, puVar4, uVar2)
//   pvVar1   = full YES message TokenList
//   puVar4   = GetSubList(inner, 1) — the OBS sub-list (no sub-parameters)
//   uVar2    = stack-security cookie (DAT_004c8db8 ^ &stack0xffffffc8)
//
// The third parameter (uVar2) is the caller's stack-security cookie.  This
// binary passes the cookie as an explicit argument to certain virtual-dispatch
// sites whose callees themselves carry a large local frame that ends with
// __security_check_cookie (see PrepareDrawVoteSet.c line 38 for the same
// pattern with vtable +0x0c).  The OBS handler is the only YES sub-handler
// that receives the cookie, implying it has a deeper call tree or a larger
// frame than the NME / IAM / GOF / TME / DRW siblings.
//
// Server has accepted Albert's OBS registration request.  Albert normally
// connects as a power, not as an observer; this path fires only if OBS was
// sent during connection setup.  No inner-state writes are confirmed
// (Python handle_yes_obs: informational log, no mutation).
//
// Known body (estimated 30–35 instructions):
//   1. Set up exception frame; compute own cookie from DAT_004c8db8 ^ stack ptr.
//   2. GetSubList(puVar4, local_1c, 1) — extract OBS body (empty; no sub-params).
//   3. No inner-state writes.
//   4. FreeList(local_1c).
//   5. Tear down frame.
//   6. __security_check_cookie(uVar2) — verify caller-supplied cookie on return.
//
// C References:
//   YESDispatcher → (Source/communications/YESDispatcher.c lines 33–38)
//   Same cookie-passing pattern: PrepareDrawVoteSet.c line 38
//   Compare: YES(NME) at vtable +0x98 (2-arg, no cookie)
//            YES(IAM) at vtable +0xa0 (2-arg, no cookie)
//
// Python equivalent: handle_yes_obs (communications/inbound/yes_handlers.py)
//   logs "observer registration accepted"; no state mutation.

void __thiscall Albert_vtable_0x9c_YES_OBS(void *this,void *full_msg,void *obs_sublist,uint caller_cookie)

{
  void *local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00497XX0;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // OBS carries no sub-parameters; extract sub-group 1 for structural
  // consistency with sibling YES-variant handlers.
  GetSubList(obs_sublist,local_1c,1);
  local_4 = 0;
  // No inner-state writes — OBS acceptance is informational only.

  local_4 = 0xffffffff;
  FreeList(local_1c);
  ExceptionList = local_c;
  __security_check_cookie(caller_cookie);
  return;
}
