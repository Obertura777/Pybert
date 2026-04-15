// FUN_0045abf0 — HLO_Dispatch
// DAIDE HLO (HELLO) handler. Fires once per game when the server announces
// the bot's identity, passcode, and game variant. Called from
// InboundDAIDEDispatcher (FUN_0045f1f0) on token HLO (0x4804).
//
// DAIDE message shape: HLO (power) (passcode) (variant)
//   [0] HLO token (consumed by the dispatcher)
//   [1] power     — single-token sublist containing the power byte
//   [2] passcode  — single-token sublist containing the 14-bit signed
//                   passcode used for later reconnect auth
//   [3] variant   — N-token sublist of variant/level options
//
// Inner-state writes (all into *(inner_state) = *(this+8)):
//   +0x2424 — our-power byte (written by FUN_00460de0; the *owner-gate*
//             field read by ParseNOWUnit and 30+ other sites)
//   +0x2428 — passcode (sign-extended from 14-bit DAIDE token)
//   +0x242c — variant TokenList (appended in-place)
//   +0x2448 — "HLO received" flag set to 1
//
// Then calls vtable slot +0xd4 (subclass OnHLO hook — where additional
// game-start init likely lives, possibly including ParseHSTResponse
// invocation on the variant sublist).
//
// Python equivalent: self.state.albert_power_idx = own_power_idx
// (bot.py:2218). Passcode, variant-list, and HLO-received flag are NOT
// PORTED — diplomacy.Game supplies variant info and the network layer
// handles reconnection natively.

void __thiscall FUN_0045abf0(void *this,undefined *param_1)
{
  undefined *this_00;
  void **ppvVar1;
  ushort *puVar2;
  uint uVar3;
  uint extraout_ECX;
  undefined4 local_3c [3];
  void *pvStack_30;
  undefined4 local_2c [4];
  void *local_1c [3];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_004982b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00465870(local_2c);                         // TokenList ctor — will hold power sublist
  local_4 = 0;
  FUN_00465870(local_3c);                         // TokenList ctor — will hold passcode sublist
  this_00 = param_1;
  local_4._0_1_ = 1;

  // --- Extract element [1] (power) into local_2c ---
  ppvVar1 = (void **)GetSubList(param_1,local_1c,1);
  local_4._0_1_ = 2;
  AppendList(local_2c,ppvVar1);
  local_4._0_1_ = 1;
  FreeList(local_1c);

  // --- Extract element [2] (passcode) into local_3c ---
  ppvVar1 = (void **)GetSubList(this_00,local_1c,2);
  local_4._0_1_ = 3;
  AppendList(local_3c,ppvVar1);
  local_4._0_1_ = 1;
  FreeList(local_1c);

  // --- Write our-power byte at inner+0x2424 ---
  // FUN_004658f0 returns the first-token pointer in ECX; FUN_00460de0
  // then writes the decoded power-index byte into inner+0x2424.
  param_1 = &stack0xffffffb0;
  uVar3 = extraout_ECX;
  FUN_004658f0(local_2c,(undefined2 *)&stack0xffffffb0);
  FUN_00460de0(*(void **)((int)this + 8),uVar3);

  // --- Write passcode (sign-extended from DAIDE 14-bit field) at +0x2428 ---
  puVar2 = (ushort *)FUN_004658f0(local_3c,(undefined2 *)&param_1);
  uVar3 = (uint)*puVar2;
  if ((*puVar2 & 0x2000) != 0) {
    uVar3 = uVar3 | 0xffffe000;   // sign-extend bit 13
  }
  *(uint *)(*(int *)((int)this + 8) + 0x2428) = uVar3;

  // --- Append element [3] (variant list) onto the TokenList at +0x242c ---
  ppvVar1 = (void **)GetSubList(this_00,local_1c,3);
  local_4._0_1_ = 4;
  AppendList((void *)(*(int *)((int)this + 8) + 0x242c),ppvVar1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FreeList(local_1c);

  // --- Set "HLO received" flag ---
  *(undefined1 *)(*(int *)((int)this + 8) + 0x2448) = 1;

  // --- Virtual dispatch: subclass OnHLO (vtable +0xd4) ---
  // Likely where additional HLO-triggered init lives, possibly including
  // ParseHSTResponse (FUN_0041b410) invocation on the variant sublist.
  (**(code **)(*(int *)this + 0xd4))();

  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  FreeList((void **)&stack0xffffffc0);
  puStack_8 = (undefined1 *)0xffffffff;
  FreeList(&pvStack_30);
  ExceptionList = pvStack_10;
  return;
}
