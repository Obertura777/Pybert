// sub_10004b00 @ 0x10004b00
// hopper name: sub_10004b00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004b00() {
    decomp_var_4 = esi;
    esi = arg_0;
    eax = sub_10004c90();
    esp = (esp - 0x8) + 0x4;
    if (eax == 0x0) {
            sub_10005a00(esi, eax);
            eax = 0x1;
    }
    else {
            if (*(*esi + 0x20) != 0x0) {
                    *(esi[0x1] + 0x8) = 0x33;
                    eax = esi[0x1];
                    esp = esp - 0xc;
                    if ((*0x10009174)(*eax, eax[0x1], eax[0x2]) != 0x0) {
                            eax = (*0x10009178)();
                    }
                    else {
                            esp = esp - 0xc;
                            decomp_var_10 = *esi[0x1];
                            if ((*0x10009134)() != 0x0) {
                                    eax = (*0x10009178)();
                                    if (eax == 0x2733) {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    *(esi[0x1] + 0x8) = 0x8;
                    eax = esi[0x1];
                    esp = esp - 0xc;
                    if ((*0x10009174)(*eax, eax[0x1], eax[0x2]) != 0x0) {
                            eax = (*0x10009178)();
                    }
                    else {
                            esp = esp - 0xc;
                            decomp_var_10 = *esi[0x1];
                            if ((*0x1000912c)() != 0x0) {
                                    eax = (*0x10009178)();
                            }
                            else {
                                    esp = esp - 0x8;
                                    decomp_var_18 = *esi[0x1];
                                    if ((*0x1000914c)() != 0x0) {
                                            eax = (*0x10009178)();
                                    }
                                    else {
                                            esp = esp - 0xc;
                                            if ((*g_tsck_func_table)() != 0xffffffff) {
                                                    sub_10004f00(esi, 0x0);
                                                    esp = (esp - 0x8) + 0x8;
                                            }
                                            eax = 0x0;
                                    }
                            }
                    }
            }
    }
    return eax;
}
