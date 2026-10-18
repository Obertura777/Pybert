// sub_4613d0 @ 0x4613d0
// hopper name: sub_4613d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4613d0() {
    var_8 = sub_499110;
    var_C = *0x0;
    decomp_var_44 = ebx;
    decomp_var_48 = ebp;
    decomp_var_4c = esi;
    decomp_var_50 = edi;
    esp = esp - 0x54;
    *0x0 = &var_C;
    ebx = ecx;
    var_40 = 0x0;
    edi = edi | 0xffffffff;
    sub_465870();
    sub_465870();
    if (ebx[0x900] != edi) {
            ebp = arg_0;
            eax = sub_466060(&var_1C, 0x0);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            if (sub_4658e0() != 0x0) {
                    esp = esp - 0x4;
                    eax = sub_4658f0(&arg_0);
                    if (*(int16_t *)word_4c7794 != *(int16_t *)eax) {
                            edi = 0x0;
                    }
                    else {
                            esp = esp - 0x4;
                            sub_401950(*(ebx[0x937] + 0x4));
                            eax = *(ebx + 0x24dc);
                            eax[0x1] = eax;
                            eax = *(ebx + 0x24dc);
                            *(ebx + 0x24e0) = 0x0;
                            *eax = eax;
                            esi = *(ebx + 0x24dc);
                            esi[0x2] = esi;
                            esi = 0x1;
                            if (sub_465930() > 0x1) {
                                    while (true) {
                                            if (edi != 0xffffffff) {
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            eax = sub_466060(&var_1C, esi);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            esp = esp - 0x10;
                                            eax = sub_460ec0(&var_2C);
                                            edi = eax;
                                            if (edi != 0xffffffff) {
                                                    esp = esp - 0x4;
                                                    edi = edi + sub_466110(esi);
                                            }
                                            esi = esi + 0x1;
                                            if (esi < sub_465930()) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
            }
            else {
                    edi = 0x0;
            }
    }
    sub_465fa0();
    sub_465fa0();
    eax = edi;
    *0x0 = var_8;
    return eax;
}
