// sub_10001760 @ 0x10001760
// hopper name: sub_10001760
// referenced by: called,immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001760() {
    edx = arg_c;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    eax = 0x0;
    edx[0x4] = arg_8;
    ecx = arg_0;
    *(int16_t *)edx = 0x48;
    edx[0x1] = 0xc;
    esi = *ecx;
    if (*(int16_t *)esi == 0x48) {
            esi = esi + 0x2;
            *ecx = esi;
            if (*(int16_t *)esi == 0x40) {
                    *ecx = esi + 0x2;
                    edx[0x3] = esi[0x1];
                    esi = *ecx;
                    esi = esi + 0x2;
                    *ecx = esi;
                    if (*(int16_t *)esi == 0x140) {
                            eax = 0x1;
                            *ecx = esi + 0x2;
                            edx[0x2] = 0x1;
                    }
            }
    }
    return eax;
}
