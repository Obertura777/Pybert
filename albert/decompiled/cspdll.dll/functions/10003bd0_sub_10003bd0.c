// sub_10003bd0 @ 0x10003bd0
// hopper name: sub_10003bd0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003bd0() {
    eax = arg_4 & 0xff;
    if (eax <= 0x4 && *(eax * 0x4 + 0x10003c1c) != 0x0) {
            if (*(eax * 0x4 + 0x10003c1c) != 0x1) {
                    eax = arg_0;
                    *(int16_t *)*eax = 0x1448;
            }
            else {
                    eax = arg_0;
                    *(int16_t *)*eax = 0x1c48;
            }
            edx = *eax;
            *eax = edx + 0x2;
            edx[0x1] = 0x40;
            *eax = *eax + 0x2;
    }
    return;
}
