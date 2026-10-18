// sub_10002030 @ 0x10002030
// hopper name: sub_10002030
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002030() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_c;
    *(int16_t *)edi = 0xc48;
    edi[0x1] = 0x88;
    edi[0x4] = arg_8;
    eax = *esi;
    if (*(int16_t *)eax == 0xc48) {
            eax = eax + 0x2;
            *esi = eax;
            if (*(int16_t *)eax == 0x40) {
                    *esi = eax + 0x2;
                    esp = (esp - 0xc) + 0xc;
                    if (sub_10001660(esi, edi + 0x6, 0x41) != 0x0) {
                            eax = *esi;
                            if (*(int16_t *)eax == 0x140) {
                                    eax = eax + 0x2;
                                    *esi = eax;
                                    if (*(int16_t *)eax == 0x40) {
                                            *esi = eax + 0x2;
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_10001660(esi, edi + 0x47, 0x41) != 0x0) {
                                                    eax = *esi;
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
    }
    else {
            eax = 0x0;
    }
    return eax;
}
