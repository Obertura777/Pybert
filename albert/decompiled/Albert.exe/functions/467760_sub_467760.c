// sub_467760 @ 0x467760
// hopper name: sub_467760
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467760() {
    var_C = *0x0;
    var_50 = ebx;
    var_58 = edi;
    esp = esp - 0x5c;
    decomp_var_5c = *dword_4c8db8 ^ &var_58;
    *0x0 = &var_C;
    edx = ecx[0x10];
    esi = arg_0;
    if ((edx & 0x2) == 0x0) {
            eax = ecx[0x9];
            if (*eax != 0x0) {
                    eax = *eax;
                    edx = ecx[0xf];
                    if (edx >= eax) {
                            eax = edx;
                    }
                    ecx = ecx[0x5];
                    ecx = *ecx;
                    decomp_var_60 = eax - ecx;
                    esp = esp - 0x8;
                    decomp_var_64 = ecx;
                    var_44 = 0x0;
                    sub_402650(decomp_var_64, decomp_var_60);
                    decomp_var_68 = 0xffffffff;
                    decomp_var_6c = 0x0;
                    esi[0x6] = 0xf;
                    esi[0x5] = 0x0;
                    esp = esp - 0xc;
                    esi[0x4] = 0x0;
                    sub_4024f0(&var_50, 0x0, 0xffffffff);
                    if (var_44 >= 0x10) {
                            esp = esp - 0x4;
                            sub_47c8f9();
                            esp = esp + 0x4;
                    }
                    *0x0 = var_1C;
                    eax = sub_47ad69();
            }
            else {
                    if ((edx & 0x4) == 0x0) {
                            edx = ecx[0x8];
                            if (*edx != 0x0) {
                                    eax = ecx[0xc];
                                    eax = *eax;
                                    eax = eax + *edx;
                                    ecx = ecx[0x4];
                                    ecx = *ecx;
                                    decomp_var_60 = eax - ecx;
                                    esp = esp - 0x8;
                                    decomp_var_64 = ecx;
                                    var_44 = 0x0;
                                    sub_402650(decomp_var_64, decomp_var_60);
                                    decomp_var_68 = 0xffffffff;
                                    decomp_var_6c = 0x0;
                                    esi[0x6] = 0xf;
                                    esi[0x5] = 0x0;
                                    esp = esp - 0xc;
                                    esi[0x4] = 0x0;
                                    sub_4024f0(&var_50, 0x0, 0xffffffff);
                                    if (var_44 >= 0x10) {
                                            esp = esp - 0x4;
                                            sub_47c8f9();
                                            esp = esp + 0x4;
                                    }
                                    *0x0 = var_1C;
                                    eax = sub_47ad69();
                            }
                            else {
                                    decomp_var_60 = 0xffffffff;
                                    decomp_var_64 = 0x0;
                                    esp = esp - 0xc;
                                    decomp_var_68 = &var_2C;
                                    esi[0x6] = 0xf;
                                    esi[0x5] = 0x0;
                                    esi[0x4] = 0x0;
                                    sub_4024f0(decomp_var_68, 0x0, 0xffffffff);
                                    if (var_20 >= 0x10) {
                                            esp = esp - 0x4;
                                            decomp_var_6c = var_34;
                                            sub_47c8f9();
                                            esp = esp + 0x4;
                                    }
                                    *0x0 = var_1C;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            decomp_var_60 = 0xffffffff;
                            decomp_var_64 = 0x0;
                            esp = esp - 0xc;
                            decomp_var_68 = &var_2C;
                            esi[0x6] = 0xf;
                            esi[0x5] = 0x0;
                            esi[0x4] = 0x0;
                            sub_4024f0(decomp_var_68, 0x0, 0xffffffff);
                            if (var_20 >= 0x10) {
                                    esp = esp - 0x4;
                                    decomp_var_6c = var_34;
                                    sub_47c8f9();
                                    esp = esp + 0x4;
                            }
                            *0x0 = var_1C;
                            eax = sub_47ad69();
                    }
            }
    }
    else {
            if ((edx & 0x4) == 0x0) {
                    edx = ecx[0x8];
                    if (*edx != 0x0) {
                            eax = ecx[0xc];
                            eax = *eax;
                            eax = eax + *edx;
                            ecx = ecx[0x4];
                            ecx = *ecx;
                            decomp_var_60 = eax - ecx;
                            esp = esp - 0x8;
                            decomp_var_64 = ecx;
                            var_44 = 0x0;
                            sub_402650(decomp_var_64, decomp_var_60);
                            decomp_var_68 = 0xffffffff;
                            decomp_var_6c = 0x0;
                            esi[0x6] = 0xf;
                            esi[0x5] = 0x0;
                            esp = esp - 0xc;
                            esi[0x4] = 0x0;
                            sub_4024f0(&var_50, 0x0, 0xffffffff);
                            if (var_44 >= 0x10) {
                                    esp = esp - 0x4;
                                    sub_47c8f9();
                                    esp = esp + 0x4;
                            }
                            *0x0 = var_1C;
                            eax = sub_47ad69();
                    }
                    else {
                            decomp_var_60 = 0xffffffff;
                            decomp_var_64 = 0x0;
                            esp = esp - 0xc;
                            decomp_var_68 = &var_2C;
                            esi[0x6] = 0xf;
                            esi[0x5] = 0x0;
                            esi[0x4] = 0x0;
                            sub_4024f0(decomp_var_68, 0x0, 0xffffffff);
                            if (var_20 >= 0x10) {
                                    esp = esp - 0x4;
                                    decomp_var_6c = var_34;
                                    sub_47c8f9();
                                    esp = esp + 0x4;
                            }
                            *0x0 = var_1C;
                            eax = sub_47ad69();
                    }
            }
            else {
                    decomp_var_60 = 0xffffffff;
                    decomp_var_64 = 0x0;
                    esp = esp - 0xc;
                    decomp_var_68 = &var_2C;
                    esi[0x6] = 0xf;
                    esi[0x5] = 0x0;
                    esi[0x4] = 0x0;
                    sub_4024f0(decomp_var_68, 0x0, 0xffffffff);
                    if (var_20 >= 0x10) {
                            esp = esp - 0x4;
                            decomp_var_6c = var_34;
                            sub_47c8f9();
                            esp = esp + 0x4;
                    }
                    *0x0 = var_1C;
                    eax = sub_47ad69();
            }
    }
    return eax;
}
