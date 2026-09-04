// FUN_00460de0 — SetOwnPower (inner-state method)
// Called from HLO_Dispatch on game start with (inner_state, power_token).
// The one and only writer of the owner-gate field at inner+0x2424.
//
// `param_1` is the raw 16-bit DAIDE power token:
//   AUS=0x4100, ENG=0x4101, FRA=0x4102, GER=0x4103,
//   ITA=0x4104, RUS=0x4105, TUR=0x4106
// All valid power tokens share high-byte 'A' (0x41), which the function
// uses as a validity guard.
//
// Inner-state effects:
//   +0x2424 (ushort) = full power token (e.g. 0x4101). Byte-reads of this
//                      offset return the power index 0..6 (low byte);
//                      short-reads return the full token. This reconciles
//                      the dual access patterns at ParseNOW.c:147 (short)
//                      and ParseNOWUnit owner-gate (byte).
//   +0x243c — std::map<int,?> whose allocator sits at +0x243c, _Myhead at
//             +0x2440, and _Mysize at +0x2444.  Cleared at the top of this
//             function (lines below), then populated in the per-province loop
//             with OWN HOME SUPPLY CENTRES — province indices p for which
//             province[p]+0x14 is a std::set<int> containing own_power_idx.
//
//             province[p]+0x14 is a std::set<int>, not a map.  Evidence:
//             the nil-flag _Isnil is checked at node+0x11, which is byte 17
//             from the node base.  With Left(0)+Parent(4)+Right(8)+key(0xC)
//             the layout is set<int> (Color at +0x10, Isnil at +0x11).
//             A map<int,V> node would push _Isnil to +0x15 or beyond.
//
//             GameBoard_GetPowerRec returns a two-word iterator
//             `{container,node}`. The condition `local_20[1] != local_18`
//             compares the returned node with province[p]+0x18 (`_Myhead`),
//             so it is precisely the successful-find test. Result: +0x243c
//             contains exactly own_power's home SCs.
//
//             Consumed in ParseNOW.c lines 130-168 (winter NOW path): the
//             map is iterated to find own home SCs where province[p]+0x20
//             (current unit-holder token, stamped by ComputeBuildDelta) equals
//             own_power_token and is absent from the unit set, inserting the
//             available build site into the map at +0x24cc. FUN_0044bd40
//             consumes +0x24cc as its legal WIN build-site map.
//   +0x2440 / +0x2444 — map._Myhead and map._Mysize (part of +0x243c map
//                       object; see above).  Cleared here via the same
//                       sentinel-reset pattern as a std::set clear.
//                       Element destructor = FUN_00401950.
//   +0x2448 = 1 ("HLO received" flag — redundant with HLO_Dispatch's own
//             write; ensures the flag is set regardless of caller).
//
// Python equivalent: `self.state.albert_power_idx = own_power_idx`
// (bot.py:2218). Python stores a 0-6 index rather than the full token;
// when a token is needed it's reconstructed via `power_idx | 0x4100`
// (matching the C pattern at ParseNOWUnit line ~147).
// The +0x243c own-home-SC map is materialised via two Python steps:
//   1. handle_mdf (server_handlers.py) parses the MDF supply-centres block
//      into state.g_mdf_home_sc {power_name → [prov_name, ...]}
//      (equivalent of the on-MDF vtable hook populating province[p]+0x14).
//   2. hlo_dispatch (hlo.py) converts g_mdf_home_sc + prov_to_id into
//      state.home_centers {power_idx → frozenset[prov_id]}, used by
//      parse_now's WIN path to compute state.g_available_home_centers.
// inner+0x24cc is consumed by FUN_0044bd40's build selector.

void __thiscall FUN_00460de0(void *this,uint param_1)
{
  void *this_00;
  uint uVar1;
  uint local_24;
  undefined4 *local_20;
  int local_18;
  int local_14 [2];
  void *local_c [3];

  uVar1 = param_1;

  // --- Write the power token at +0x2424 ---
  *(undefined2 *)((int)this + 0x2424) = (undefined2)param_1;

  // --- Clear the std::map at +0x243c (_Myhead at +0x2440, size at +0x2444) ---
  FUN_00401950(*(int **)(*(int *)((int)this + 0x2440) + 4));
  *(int *)(*(int *)((int)this + 0x2440) + 4) = *(int *)((int)this + 0x2440);
  *(undefined4 *)((int)this + 0x2444) = 0;
  *(undefined4 *)*(undefined4 *)((int)this + 0x2440) = *(undefined4 *)((int)this + 0x2440);
  *(int *)(*(int *)((int)this + 0x2440) + 8) = *(int *)((int)this + 0x2440);

  // --- Validity guard: high byte of token must be 'A' (0x41) ---
  if ((char)(uVar1 >> 8) == 'A') {
    local_24 = uVar1 & 0xff;   // power index 0..6
    param_1 = 0;
    if (0 < *(int *)((int)this + 0x2400)) {   // loop over all provinces
      do {
        uVar1 = param_1;
        local_18 = *(int *)((int)this + param_1 * 0x24 + 0x18);
        this_00 = (void *)((int)this + param_1 * 0x24 + 0x14);
        // GameBoard_GetPowerRec searches the std::set<int> at province[p]+0x14
        // for own_power_idx and returns `{container,node}` (or
        // `{container,header}` when absent). local_18 is the set header.
        local_20 = (undefined4 *)GameBoard_GetPowerRec(this_00,local_14,(int *)&local_24);
        if (((void *)*local_20 == (void *)0x0) || ((void *)*local_20 != this_00)) {
          FUN_0047a948();
        }
        // node != header: own_power is a home-SC power for this province.
        if (local_20[1] != local_18) {
          StdMap_FindOrInsert((void *)((int)this + 0x243c),local_c,(int *)&param_1);
        }
        param_1 = uVar1 + 1;
      } while ((int)param_1 < *(int *)((int)this + 0x2400));
    }
  }

  // --- HLO-received flag (redundant with HLO_Dispatch's own write) ---
  *(undefined1 *)((int)this + 0x2448) = 1;
  return;
}
