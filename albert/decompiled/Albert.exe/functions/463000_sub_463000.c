// sub_463000 @ 0x463000
// hopper name: sub_463000
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_463000() {
    var_8 = 0x499478;
    var_C = *0x0;
    decomp_var_18c = ebx;
    decomp_var_190 = ebp;
    decomp_var_194 = esi;
    decomp_var_198 = edi;
    esp = esp - 0x19c;
    decomp_var_19c = *dword_4c8db8 ^ &decomp_var_198;
    *0x0 = &var_C;
    edi = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_410330();
    var_158 = eax;
    eax[0x19] = 0x1;
    var_158[0x1] = var_158;
    *var_158 = var_158;
    var_158[0x2] = var_158;
    var_154 = 0x0;
    sub_4064f0();
    if (edi[0x900] != (esi | 0xffffffff)) {
            esi = arg_0;
            if (sub_465930() == 0x4) {
                    esp = esp - 0x8;
                    eax = sub_466060(&var_16C, 0x0);
                    ebx = 0x1;
                    if (sub_4658e0() != 0x0) {
                            eax = sub_466060(&var_144, 0x0);
                            ebx = 0x7;
                            esp = esp - 0xc;
                            eax = sub_4658f0(&var_186);
                            var_187 = 0x0;
                            if (*(int16_t *)word_4c7784 != *(int16_t *)eax) {
                                    var_187 = 0x1;
                            }
                    }
                    else {
                            var_187 = 0x1;
                    }
                    if ((ebx & 0x4) != 0x0) {
                            ebx = ebx & 0xfffffffb;
                    }
                    if ((ebx & 0x2) != 0x0) {
                            ebx = ebx & 0xfffffffd;
                            sub_465fa0();
                    }
                    if ((ebx & 0x1) != 0x0) {
                            sub_465fa0();
                    }
                    if (var_187 == 0x0) {
                            ebp = 0x0;
                            eax = sub_466060(&var_144, 0x1);
                            sub_465ff0(eax);
                            sub_465fa0();
                            eax = sub_466060(&var_144, 0x2);
                            sub_465ff0(eax);
                            sub_465fa0();
                            eax = sub_466060(&var_144, 0x3);
                            sub_465ff0(eax);
                            sub_465fa0();
                            esp = esp - 0x2c;
                            eax = sub_465900(&var_186, 0x0);
                            esi = *(int16_t *)eax;
                            if (*(int16_t *)word_4c772c != esi) {
                                    if (*(int16_t *)word_4c7734 == esi && edi[0x1258] != esi) {
                                            edi[0x1258] = esi;
                                            sub_409db0();
                                            sub_409db0();
                                            sub_462590();
                                    }
                            }
                            else {
                                    if (edi[0x1258] != esi) {
                                            edi[0x1258] = esi;
                                            sub_409db0();
                                            sub_409db0();
                                            sub_462590();
                                    }
                            }
                            eax = sub_466060(&var_144, ebp);
                            sub_465ff0(eax);
                            sub_465fa0();
                            eax = sub_466060(&var_144, 0x1);
                            eax = sub_4658f0(&var_186);
                            ebp = *(int16_t *)eax;
                            sub_465fa0();
                            esp = esp - 0x20;
                            eax = sub_465900(&var_186, 0x0);
                            bool_12 = *(int16_t *)word_4c773c != esi;
                            ebx = *(int8_t *)eax & 0xff;
                            var_184 = ebx;
                            edx = &var_174;
                            if (!bool_12) {
                                    esi = edi + 0x24a4;
                                    eax = sub_460360(edx, &var_184, decomp_var_19c, decomp_var_198, decomp_var_194);
                                    var_180 = *eax;
                                    esp = esp - 0xc;
                                    var_170 = esi[0x1];
                                    var_174 = esi;
                                    eax = sub_40dfe0(&var_174);
                                    if (eax != 0x0) {
                                            sub_4028d0();
                                            eax = sub_406740(&var_184, &var_15C);
                                            esp = esp - 0x10;
                                            eax = sub_4074f0(&var_16C, eax, decomp_var_19c);
                                            var_180 = *eax;
                                            sub_4065b0();
                                    }
                                    if (*(int16_t *)word_4c76a0 == ebp) {
                                            eax = sub_410b70();
                                            eax[0x4] = eax[0x4] + 0x1;
                                    }
                                    else {
                                            if (*(int16_t *)word_4c7698 == ebp) {
                                                    eax = sub_45fd80(&var_174, &var_128);
                                                    esp = esp - 0x10;
                                                    sub_410b70() + 0x4;
                                                    sub_404ef0(decomp_var_1a4, decomp_var_1a0);
                                                    *(int8_t *)(sub_410b70() + 0x18) = 0x1;
                                            }
                                            else {
                                                    eax = sub_45fd80(&var_174, &var_128);
                                                    esp = esp - 0x10;
                                                    sub_410b70() + 0x4;
                                                    sub_404ef0(decomp_var_1a4, decomp_var_1a0);
                                                    *(int8_t *)(sub_410b70() + 0x18) = 0x0;
                                            }
                                    }
                            }
                            else {
                                    eax = sub_45fd80(edx, &var_128);
                                    var_E8 = *eax;
                                    var_E4 = eax[0x1];
                                    sub_465900(&var_186, 0x1);
                                    sub_465f60(&var_118);
                                    sub_461660(&var_E8, decomp_var_1ac, decomp_var_1a8, decomp_var_1a4, decomp_var_1a0, decomp_var_19c, decomp_var_198);
                                    sub_465f60(&var_F8);
                                    esp = esp - 0x40;
                                    eax = sub_45fe30(&var_E8, decomp_var_1ac, decomp_var_1a8, decomp_var_1a4, decomp_var_1a0, decomp_var_19c, decomp_var_198);
                                    if (*(int16_t *)word_4c772c != esi && *(int16_t *)word_4c7734 != esi) {
                                            eax = sub_406720(&var_E8, &var_E8);
                                            decomp_var_1a0 = eax;
                                            esp = esp - 0x10;
                                    }
                                    else {
                                            var_7C = var_E8;
                                            sub_4065f0(&var_E8);
                                            decomp_var_1a0 = &var_7C;
                                            esp = esp - 0xc;
                                    }
                                    sub_4070a0(decomp_var_1a0, decomp_var_19c, decomp_var_198);
                                    sub_406440();
                            }
                    }
            }
    }
    sub_406440();
    sub_4053f0(&var_170, &var_158, *var_154, &var_158, var_154);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = var_174;
    *0x0 = var_8;
    return eax;
}
