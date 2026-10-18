// sub_10003c30 @ 0x10003c30
// hopper name: sub_10003c30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003c30() {
    sprintf(&var_18, "%08x_%04x.clg", sub_100068d0());
    eax = fopen(&saved_fp, 0x100090b0);
    *(*(arg_18 + arg_4 * 0x4 + 0x4) + 0x38) = eax;
    eax = *(*(arg_18 + arg_4 * 0x4 + 0x4) + 0x38) != 0x0 ? 0x1 : 0x0;
    return eax;
}
