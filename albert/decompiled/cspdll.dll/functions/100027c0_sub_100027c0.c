// sub_100027c0 @ 0x100027c0
// hopper name: sub_100027c0
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100027c0() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_c;
    *(int16_t *)edi = 0x1b48;
    edi[0x1] = 0x8;
    edi[0x4] = arg_8;
    eax = *esi;
    if (*(int16_t *)eax == 0x1b48) {
            eax = eax + 0x2;
            *esi = eax;
            if (*(int16_t *)eax == 0x40) {
                    *esi = eax + 0x2;
                    edi[0x3] = sub_10001640(eax[0x1]);
                    edx = *esi;
                    esp = (esp - 0x4) + 0x4;
                    eax = edx + 0x2;
                    *esi = edx + 0x2;
                    if (*(int16_t *)eax == 0x140) {
                            *esi = eax + 0x2;
                            eax = 0x1;
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
