// sub_465470 @ 0x465470
// hopper name: sub_465470
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465470() {
    var_C = *0x0;
    decomp_var_64 = ebx;
    decomp_var_68 = ebp;
    decomp_var_6c = esi;
    decomp_var_70 = edi;
    esp = esp - 0x74;
    decomp_var_74 = *dword_4c8db8 ^ &decomp_var_70;
    *0x0 = &var_C;
    ebp = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    esi = arg_0;
    if (sub_465930() == 0x4) {
            eax = sub_466060(&var_1C, 0x0);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&var_1C, 0x1);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&var_1C, 0x2);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&var_1C, 0x3);
            esp = esp - 0x30;
            sub_465ff0(eax);
            sub_465fa0();
            if (sub_4658e0() != 0x0) {
                    esp = esp - 0x4;
                    eax = sub_4658f0(&arg_0);
                    if (*(int16_t *)word_4c7768 == *(int16_t *)eax) {
                            esp = esp - 0x4;
                            eax = sub_45fac0(&var_2C);
                            edi = eax;
                            if (edi != 0xffffffff) {
                                    esp = esp - 0x4;
                                    edi = edi + sub_466110(0x1);
                                    if (edi == 0xffffffff) {
                                            esp = esp - 0x4;
                                            eax = sub_462760(&var_3C, decomp_var_74);
                                            edi = eax;
                                            if (edi != 0xffffffff) {
                                                    esp = esp - 0x4;
                                                    edi = edi + sub_466110(0x2);
                                                    if (edi == 0xffffffff) {
                                                            esp = esp - 0x4;
                                                            eax = sub_465390(&var_4C);
                                                            edi = eax;
                                                            if (edi != 0xffffffff) {
                                                                    esp = esp - 0x4;
                                                                    edi = edi + sub_466110(0x3);
                                                            }
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    eax = sub_465390(&var_4C);
                                                    edi = eax;
                                                    if (edi != 0xffffffff) {
                                                            esp = esp - 0x4;
                                                            edi = edi + sub_466110(0x3);
                                                    }
                                            }
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = edi;
                                            *0x0 = var_C;
                                    }
                                    else {
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = edi;
                                            *0x0 = var_C;
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    eax = sub_462760(&var_3C, decomp_var_74);
                                    edi = eax;
                                    if (edi != 0xffffffff) {
                                            esp = esp - 0x4;
                                            edi = edi + sub_466110(0x2);
                                            if (edi == 0xffffffff) {
                                                    esp = esp - 0x4;
                                                    eax = sub_465390(&var_4C);
                                                    edi = eax;
                                                    if (edi != 0xffffffff) {
                                                            esp = esp - 0x4;
                                                            edi = edi + sub_466110(0x3);
                                                    }
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            eax = sub_465390(&var_4C);
                                            edi = eax;
                                            if (edi != 0xffffffff) {
                                                    esp = esp - 0x4;
                                                    edi = edi + sub_466110(0x3);
                                            }
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = edi;
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = 0x0;
                            *0x0 = var_C;
                    }
            }
            else {
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = 0x0;
                    *0x0 = var_C;
            }
    }
    else {
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            eax = 0x0;
            *0x0 = var_C;
    }
    return eax;
}
