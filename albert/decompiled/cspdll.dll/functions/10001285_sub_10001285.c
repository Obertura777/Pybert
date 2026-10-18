// sub_10001285 @ 0x10001285
// hopper name: sub_10001285
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001285() {
    eax = arg_4;
    if (eax[0x5] == 0x0 && eax[0x3] == 0x258) {
            if (eax[0x4] == 0x0) {
                    *(int16_t *)*arg_0 = 0xe48;
                    *arg_0 = *arg_0 + 0x2;
            }
    }
    return;
}
