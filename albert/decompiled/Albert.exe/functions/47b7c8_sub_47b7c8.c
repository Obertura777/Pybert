// sub_47b7c8 @ 0x47b7c8
// hopper name: sub_47b7c8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b7c8() {
    esp = esp - 0x4;
    decomp_var_24 = ebx;
    if (arg_c == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = eax | 0xffffffff;
    }
    else {
            decomp_var_28 = esi;
            esi = arg_4;
            esp = esp - 0x8;
            decomp_var_2c = edi;
            edi = arg_8;
            if (edi != 0x0) {
                    ebx = 0x0;
                    if (esi == 0x0) {
                            *sub_47d812() = 0x16;
                            eax = sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = eax | 0xffffffff;
                            esp = esp + 0x8;
                    }
                    else {
                            var_1C = 0x7fffffff;
                            if (edi <= 0x7fffffff) {
                                    var_1C = edi;
                            }
                            var_20 = esi;
                            eax = (arg_0)(&var_20, arg_c, arg_10, arg_14);
                            esp = (esp - 0x10) + 0x10;
                            arg_c = eax;
                            if (esi != ebx) {
                                    if (eax >= ebx) {
                                            var_1C = var_1C - 0x1;
                                            if (var_1C >= 0x0) {
                                                    *(int8_t *)var_20 = ebx;
                                                    eax = arg_c;
                                            }
                                            else {
                                                    decomp_var_24 = ebx;
                                                    eax = sub_48501e(decomp_var_24, &var_20);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax != 0xffffffff) {
                                                            eax = arg_c;
                                                    }
                                                    else {
                                                            *(int8_t *)(esi + (edi - 0x1)) = ebx;
                                                            eax = (var_1C >= ebx ? 0x1 : 0x0) - 0x2;
                                                    }
                                            }
                                    }
                                    else {
                                            *(int8_t *)(esi + (edi - 0x1)) = ebx;
                                            eax = (var_1C >= ebx ? 0x1 : 0x0) - 0x2;
                                    }
                            }
                            esp = esp + 0x8;
                    }
            }
            else {
                    var_1C = 0x7fffffff;
                    if (edi <= 0x7fffffff) {
                            var_1C = edi;
                    }
                    var_20 = esi;
                    eax = (arg_0)(&var_20, arg_c, arg_10, arg_14);
                    esp = (esp - 0x10) + 0x10;
                    arg_c = eax;
                    if (esi != 0x0) {
                            ebx = 0x0;
                            if (eax >= 0x0) {
                                    var_1C = var_1C - 0x1;
                                    if (var_1C >= 0x0) {
                                            *(int8_t *)var_20 = ebx;
                                            eax = arg_c;
                                    }
                                    else {
                                            decomp_var_24 = ebx;
                                            eax = sub_48501e(decomp_var_24, &var_20);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax != 0xffffffff) {
                                                    eax = arg_c;
                                            }
                                            else {
                                                    *(int8_t *)(esi + (edi - 0x1)) = ebx;
                                                    eax = (var_1C >= ebx ? 0x1 : 0x0) - 0x2;
                                            }
                                    }
                            }
                            else {
                                    *(int8_t *)(esi + (edi - 0x1)) = ebx;
                                    eax = (var_1C >= ebx ? 0x1 : 0x0) - 0x2;
                            }
                    }
                    esp = esp + 0x8;
            }
    }
    return eax;
}
