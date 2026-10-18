// sub_1000101e @ 0x1000101e
// hopper name: sub_1000101e
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_1000101e() {
    eax = arg_0;
    if (arg_4[0x2] != 0x0) {
            *(int16_t *)*eax = 0x348;
            *eax = *eax + 0x2;
    }
    else {
            *(int16_t *)*eax = 0xd48;
            edx = *eax;
            *eax = edx + 0x2;
            edx[0x1] = 0x40;
            ecx = *eax;
            *eax = ecx + 0x2;
            ecx[0x1] = 0x348;
            edx = *eax;
            *eax = edx + 0x2;
            edx[0x1] = 0x140;
            *eax = *eax + 0x2;
    }
    return;
}
