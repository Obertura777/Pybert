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
//   +0x2440 / +0x2444 — std::set<int> *cleared* (head sentinel reset,
//                       size zeroed). Element destructor = FUN_00401950
//                       (Tier-A int-node dtor per
//                       ParseNOW-CallTree-Checklist.md).
//   +0x243c — std::map root, populated in the per-province loop below
//             with the indices of provinces whose home-SC record for our
//             power disagrees with the province's own +0x18 field. Most
//             likely "home supply centres owned by our power" or similar.
//   +0x2448 = 1 ("HLO received" flag — redundant with HLO_Dispatch's own
//             write; ensures the flag is set regardless of caller).
//
// Python equivalent: `self.state.albert_power_idx = own_power_idx`
// (bot.py:2218). Python stores a 0-6 index rather than the full token;
// when a token is needed it's reconstructed via `power_idx | 0x4100`
// (matching the C pattern at ParseNOWUnit line ~147). The per-province
// home-SC enumeration is handled by diplomacy.Game's map metadata and
// does not require a materialised std::map.

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

  // --- Clear the std::set<int> at +0x2440 (size at +0x2444) ---
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
        // Look up our-power's record in the per-province home-SC set.
        local_20 = (undefined4 *)GameBoard_GetPowerRec(this_00,local_14,(int *)&local_24);
        if (((void *)*local_20 == (void *)0x0) || ((void *)*local_20 != this_00)) {
          FUN_0047a948();
        }
        // Province's home-SC record for our power disagrees with its
        // own +0x18 field → insert province index into map at +0x243c.
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
