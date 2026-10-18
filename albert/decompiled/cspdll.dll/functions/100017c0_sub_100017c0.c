// sub_100017c0 @ 0x100017c0
// hopper name: sub_100017c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100017c0() {
    ecx = arg_c;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    *(int16_t *)ecx = 0x348;
    ecx[0x1] = 0xc;
    ecx[0x4] = arg_8;
    edx = *esi;
    eax = 0x0;
    if (*(int16_t *)edx == 0x348) {
            eax = 0x1;
            *esi = edx + 0x2;
            ecx[0x2] = 0x1;
    }
    return eax;
}
