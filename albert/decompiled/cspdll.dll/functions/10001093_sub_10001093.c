// sub_10001093 @ 0x10001093
// hopper name: sub_10001093
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001093() {
    *(int16_t *)*arg_4 = 0x748;
    ecx = *arg_4;
    *arg_4 = ecx + 0x2;
    ecx[0x1] = 0x40;
    eax = *arg_4;
    *arg_4 = eax + 0x2;
    eax[0x1] = arg_8[0x3];
    edx = *arg_4;
    *arg_4 = edx + 0x2;
    edx[0x1] = 0x140;
    eax = *arg_4;
    *arg_4 = eax + 0x2;
    eax[0x1] = 0x40;
    *arg_4 = *arg_4 + 0x2;
    *(int16_t *)*arg_4 = sub_10001000();
    ecx = *arg_4;
    *arg_4 = ecx + 0x2;
    ecx[0x1] = 0x140;
    *arg_4 = *arg_4 + 0x2;
    return;
}
