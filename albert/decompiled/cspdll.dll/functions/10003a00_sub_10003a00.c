// sub_10003a00 @ 0x10003a00
// hopper name: sub_10003a00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003a00() {
    eax = malloc(saved_fp);
    *arg_8 = eax;
    *(int8_t *)eax = 0x5;
    *(int16_t *)(eax + 0x5) = arg_0[0x4];
    *(eax + 0x1) = arg_0[0x1];
    return;
}
