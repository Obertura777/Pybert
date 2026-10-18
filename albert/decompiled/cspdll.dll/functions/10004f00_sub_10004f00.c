// sub_10004f00 @ 0x10004f00
// hopper name: sub_10004f00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004f00() {
    eax = arg_4;
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (eax != 0x0) {
            eax = sub_100055f0(arg_0, 0x0, 0x4, eax, decomp_var_8, decomp_var_4);
    }
    else {
            esi = arg_0;
            edi = 0x1;
            eax = esi + 0x8;
            while (true) {
                    if (*eax == 0x0) {
                            if (edi < 0x32) {
                                    eax = sub_10005980(esi, decomp_var_8, decomp_var_4);
                                    esp = (esp - 0x4) + 0x4;
                                    *(esi + edi * 0x4 + 0x4) = eax;
                                    if (eax != 0x0) {
                                            eax = *(*esi + 0x44);
                                            if (eax != 0x0) {
                                                    eax = sub_10003c30(esi, edi, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax == 0x0) {
                                                            eax = sub_10005a00(esi, edi);
                                                            *(esi + edi * 0x4 + 0x4) = 0x0;
                                                            edi = decomp_var_8;
                                                            esi = decomp_var_4;
                                                            esp = (esp - 0x8) + 0x10;
                                                            temp_0 = 0x2;
                                                    }
                                                    else {
                                                            temp_0 = 0x3;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x1;
                                            }
                                    }
                                    else {
                                            temp_0 = 0x1;
                                    }
                            }
                            else {
                                    temp_0 = 0x0;
                            }
                            break;
                    }
                    edi = edi + 0x1;
                    eax = eax + 0x4;
                    if (edi < 0x32) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            switch (temp_0) {
                case 0:
                    esp = esp - 0xc;
                    decomp_var_14 = *esi[0x1];
                    eax = (*g_tsck_func_table)();
                    if (eax != 0xffffffff) {
                            esp = esp - 0x4;
                            decomp_var_18 = eax;
                            eax = (*0x10009130)();
                    }
                    break;
                case 1:
                    eax = *(esi + edi * 0x4 + 0x4);
                    if (eax != 0x0) {
                            decomp_var_10 = eax + 0x22;
                            esp = esp - 0xc;
                            decomp_var_14 = *esi[0x1];
                            **(esi + edi * 0x4 + 0x4) = (*g_tsck_func_table)();
                            eax = *(esi + edi * 0x4 + 0x4);
                            if (*eax != 0xffffffff) {
                                    eax[0x2] = 0x21;
                                    eax = *(esi + edi * 0x4 + 0x4);
                                    esp = esp - 0xc;
                                    if ((*0x10009174)(*eax, eax[0x1], eax[0x2]) != 0x0) {
                                            sub_100055f0(esi, 0x0, 0x4, (*0x10009178)(), decomp_var_14, decomp_var_10);
                                            eax = sub_10005a00(esi, edi);
                                            *(esi + edi * 0x4 + 0x4) = 0x0;
                                    }
                                    else {
                                            sub_100055f0(esi, edi, 0x4, 0x0, decomp_var_14, decomp_var_10);
                                            esi[0x33] = 0x1;
                                            eax = sub_10005030(esi, edi, 0x0);
                                    }
                            }
                            else {
                                    sub_100055f0(esi, 0x0, 0x4, (*0x10009178)(), decomp_var_14, decomp_var_10);
                                    eax = sub_10005a00(esi, edi);
                                    *(esi + edi * 0x4 + 0x4) = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0xc;
                            decomp_var_14 = *esi[0x1];
                            eax = (*g_tsck_func_table)();
                            if (eax != 0xffffffff) {
                                    esp = esp - 0x4;
                                    decomp_var_18 = eax;
                                    eax = (*0x10009130)();
                            }
                    }
                    break;
                default:
                    if (temp_0 != 0x2) {
                            eax = *(esi + edi * 0x4 + 0x4);
                            if (eax != 0x0) {
                                    decomp_var_10 = eax + 0x22;
                                    esp = esp - 0xc;
                                    decomp_var_14 = *esi[0x1];
                                    **(esi + edi * 0x4 + 0x4) = (*g_tsck_func_table)();
                                    eax = *(esi + edi * 0x4 + 0x4);
                                    if (*eax != 0xffffffff) {
                                            eax[0x2] = 0x21;
                                            eax = *(esi + edi * 0x4 + 0x4);
                                            esp = esp - 0xc;
                                            if ((*0x10009174)(*eax, eax[0x1], eax[0x2]) != 0x0) {
                                                    sub_100055f0(esi, 0x0, 0x4, (*0x10009178)(), decomp_var_14, decomp_var_10);
                                                    eax = sub_10005a00(esi, edi);
                                                    *(esi + edi * 0x4 + 0x4) = 0x0;
                                            }
                                            else {
                                                    sub_100055f0(esi, edi, 0x4, 0x0, decomp_var_14, decomp_var_10);
                                                    esi[0x33] = 0x1;
                                                    eax = sub_10005030(esi, edi, 0x0);
                                            }
                                    }
                                    else {
                                            sub_100055f0(esi, 0x0, 0x4, (*0x10009178)(), decomp_var_14, decomp_var_10);
                                            eax = sub_10005a00(esi, edi);
                                            *(esi + edi * 0x4 + 0x4) = 0x0;
                                    }
                            }
                            else {
                                    esp = esp - 0xc;
                                    decomp_var_14 = *esi[0x1];
                                    eax = (*g_tsck_func_table)();
                                    if (eax != 0xffffffff) {
                                            esp = esp - 0x4;
                                            decomp_var_18 = eax;
                                            eax = (*0x10009130)();
                                    }
                            }
                    }
                    break;
            }
    }
    return eax;
}
