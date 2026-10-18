// sub_461660 @ 0x461660
// hopper name: sub_461660
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_461660() {
    var_8 = 0x4991a8;
    var_C = *0x0;
    *0x0 = &var_C;
    edi = ecx;
    sub_465870();
    eax = sub_466060(&var_1C, 0x1);
    esp = esp - 0x50;
    eax = sub_4658f0(&var_34);
    esi = *(int16_t *)eax;
    ecx = &var_1C;
    sub_465fa0();
    if (*(int16_t *)word_4c7680 == esi) {
            arg_0[0x4] = 0x1;
    }
    else {
            if (*(int16_t *)word_4c7684 == esi) {
                    decomp_var_48 = ecx;
                    ecx = arg_0[0x6];
                    arg_0[0x4] = 0x2;
                    decomp_var_48 = ecx;
                    eax = sub_466060(&var_1C, 0x2);
                    esp = esp - 0x14;
                    eax = sub_45fc30(&var_34, eax, decomp_var_48);
                    arg_0[0x5] = *eax;
                    arg_0[0x6] = eax[0x1];
                    sub_465fa0();
            }
            else {
                    if (*(int16_t *)word_4c7688 == esi) {
                            eax = sub_465930();
                            esi = arg_0;
                            decomp_var_48 = 0x2;
                            esp = esp - 0x8;
                            decomp_var_4c = &var_1C;
                            if (eax == 0x3) {
                                    esi[0x4] = 0x3;
                                    eax = sub_466060(decomp_var_4c, decomp_var_48);
                                    esp = esp - 0x8;
                                    eax = sub_45fd80(&var_34, eax);
                                    esi[0x7] = *eax;
                                    sub_465fa0();
                            }
                            else {
                                    esi[0x4] = 0x4;
                                    eax = sub_466060(decomp_var_4c, decomp_var_48);
                                    eax = sub_45fd80(&var_34, eax);
                                    esi[0x7] = *eax;
                                    sub_465fa0();
                                    esp = esp - 0x10;
                                    eax = sub_466060(&var_1C, 0x4);
                                    esp = esp - 0x4;
                                    eax = sub_4658f0(&arg_0);
                                    esi[0x8] = *(int8_t *)eax & 0xff;
                                    sub_465fa0();
                            }
                    }
                    else {
                            if (*(int16_t *)word_4c767c == esi) {
                                    esi = arg_0;
                                    esi[0x4] = 0x5;
                                    eax = sub_466060(&var_1C, 0x2);
                                    eax = sub_45fd80(&var_34, eax);
                                    esi[0x7] = *eax;
                                    sub_465fa0();
                                    esp = esp - 0x18;
                                    eax = sub_466060(&var_1C, 0x4);
                                    esp = esp - 0x4;
                                    eax = sub_4658f0(&arg_0);
                                    esi[0x8] = *(int8_t *)eax & 0xff;
                                    sub_465fa0();
                            }
                            else {
                                    if (*(int16_t *)word_4c7678 == esi) {
                                            esi = arg_0;
                                            decomp_var_48 = ecx;
                                            ecx = esi[0x6];
                                            esi[0x4] = 0x6;
                                            arg_0 = &decomp_var_48;
                                            decomp_var_48 = ecx;
                                            eax = sub_466060(&var_1C, 0x2);
                                            eax = sub_45fc30(&var_34, eax, decomp_var_48);
                                            esi[0x5] = *eax;
                                            esi[0x6] = eax[0x1];
                                            sub_465fa0();
                                            esi = esi + 0x24;
                                            sub_401850();
                                            eax = sub_466060(&var_1C, 0x4);
                                            esp = esp - 0x20;
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            edi = 0x0;
                                            if (sub_4658d0() > 0x0) {
                                                    do {
                                                            eax = sub_465900(&arg_0, edi);
                                                            esp = esp - 0xc;
                                                            var_34 = *(int8_t *)eax & 0xff;
                                                            sub_4610b0(&var_34);
                                                            edi = edi + 0x1;
                                                    } while (edi < sub_4658d0());
                                            }
                                    }
                                    else {
                                            if (*(int16_t *)word_4c7690 == esi) {
                                                    arg_0[0x4] = 0x8;
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c7694 == esi) {
                                                            edx = arg_0[0x6];
                                                            decomp_var_48 = ecx;
                                                            arg_0[0x4] = 0x7;
                                                            decomp_var_48 = edx;
                                                            eax = sub_466060(&var_1C, 0x2);
                                                            esp = esp - 0x14;
                                                            eax = sub_45fc30(&var_34, eax, decomp_var_48);
                                                            arg_0[0x5] = *eax;
                                                            arg_0[0x6] = eax[0x1];
                                                            sub_465fa0();
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = arg_4;
    return eax;
}
