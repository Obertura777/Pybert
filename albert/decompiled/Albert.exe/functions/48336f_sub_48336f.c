// sub_48336f @ 0x48336f
// hopper name: sub_48336f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48336f() {
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x10;
    ebx = eax;
    sub_47aea2(arg_14);
    if (ebx == 0x0) {
            eax = sub_47d812();
            esp = esp - 0x4;
            decomp_var_20 = 0x16;
            edi = decomp_var_20;
            *eax = edi;
            sub_47a924();
            esp = (esp + 0x4 - 0x14) + 0x14;
            if (var_4 != 0x0) {
                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
            }
            eax = edi;
    }
    else {
            if (arg_0 > 0x0) {
                    esi = 0x0;
                    if (arg_4 > 0x0) {
                            eax = arg_4;
                    }
                    else {
                            eax = 0x0;
                    }
                    if (arg_0 <= eax + 0x9) {
                            eax = sub_47d812();
                            esp = esp - 0x4;
                            decomp_var_20 = 0x22;
                            edi = decomp_var_20;
                            *eax = edi;
                            sub_47a924();
                            esp = (esp + 0x4 - 0x14) + 0x14;
                            if (var_4 != 0x0) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                            eax = edi;
                    }
                    else {
                            if (arg_10 != 0x0) {
                                    sub_483336();
                            }
                            edi = arg_c;
                            esi = ebx;
                            if (*edi == 0x2d) {
                                    *(int8_t *)ebx = 0x2d;
                                    esi = ebx + 0x1;
                            }
                            if (arg_4 > 0x0) {
                                    *(int8_t *)esi = esi[0x1];
                                    esi = esi + 0x1;
                                    *(int8_t *)esi = *(int8_t *)*var_10[0x2f];
                            }
                            esi = esi + (arg_10 == 0x0 ? 0x1 : 0x0) + arg_4;
                            if (arg_10 == 0x0) {
                                    ebx = ebx | 0xffffffff;
                            }
                            else {
                                    ebx = (ebx - esi) + arg_0;
                            }
                            esp = (esp - 0xc) + 0xc;
                            if (sub_47db5e(esi, ebx, "e+000") != 0x0) {
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            ecx = esi + 0x2;
                            if (arg_8 != 0x0) {
                                    *(int8_t *)esi = 0x45;
                            }
                            esi = esi + 0x1;
                            if (*(int8_t *)edi[0x3] != 0x30) {
                                    eax = edi[0x1];
                                    eax = eax - 0x1;
                                    if (eax < 0x0) {
                                            eax = -eax;
                                            *(int8_t *)esi = 0x2d;
                                    }
                                    esi = esi + 0x1;
                                    if (eax >= 0x64) {
                                            esp = (esp - 0x4) + 0x4;
                                            *(int8_t *)esi = *(int8_t *)esi + eax / 0x64;
                                            eax = eax % 0x64;
                                    }
                                    esi = esi + 0x1;
                                    if (eax >= 0xa) {
                                            esp = (esp - 0x4) + 0x4;
                                            *(int8_t *)esi = *(int8_t *)esi + eax / 0xa;
                                            eax = eax % 0xa;
                                    }
                                    esi[0x1] = esi[0x1] + eax;
                            }
                            if ((*(int8_t *)byte_bc6f48 & 0x1) != 0x0 && *(int8_t *)ecx == 0x30) {
                                    sub_47f9a0(ecx, ecx + 0x1, 0x3);
                                    esp = (esp - 0xc) + 0xc;
                            }
                            if (var_4 != 0x0) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                    }
            }
            else {
                    eax = sub_47d812();
                    esp = esp - 0x4;
                    decomp_var_20 = 0x16;
                    edi = decomp_var_20;
                    *eax = edi;
                    sub_47a924();
                    esp = (esp + 0x4 - 0x14) + 0x14;
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
                    eax = edi;
            }
    }
    return eax;
}
