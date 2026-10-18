// sub_4240d0 @ 0x4240d0
// hopper name: sub_4240d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4240d0() {
    var_C = *0x0;
    *0x0 = &var_C;
    esi = ecx;
    esp = esp - 0x34;
    ebx = 0x0;
    eax = sub_465900(&var_20, 0x0);
    if (*(int16_t *)word_4c6dc4 != *(int16_t *)eax) {
            var_20 = &decomp_var_3c;
            esp = esp - 0x14;
            sub_465f60(&arg_0);
            eax = sub_41daf0();
            ebx = eax;
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&var_20, 0x0);
            if (*(int16_t *)word_4c6d88 != *(int16_t *)eax) {
                    var_20 = &decomp_var_3c;
                    esp = esp - 0x14;
                    sub_465f60(&arg_0);
                    eax = sub_41fcc0();
                    ebx = eax;
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_20, 0x0);
                    if (*(int16_t *)word_4c6d94 != *(int16_t *)eax) {
                            var_20 = &decomp_var_3c;
                            esp = esp - 0x14;
                            sub_465f60(&arg_0);
                            eax = sub_420100();
                            ebx = eax;
                    }
                    else {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_20, 0x0);
                            if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                    var_20 = &decomp_var_38;
                                    sub_405090(&arg_10);
                                    var_1C = &decomp_var_48;
                                    esp = esp - 0x24;
                                    sub_465f60(&arg_0);
                                    eax = sub_420630();
                                    ebx = eax;
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_20, 0x0);
                                    if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                                            eax = sub_466060(&var_1C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            esp = esp - 0x14;
                                            eax = sub_465900(&var_20, 0x0);
                                            if (*(int16_t *)word_4c6dc4 != *(int16_t *)eax) {
                                                    var_1C = &decomp_var_3c;
                                                    esp = esp - 0x14;
                                                    sub_465f60(&arg_0);
                                                    eax = sub_41df20();
                                                    ebx = eax;
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_20, 0x0);
                                                    if (*(int16_t *)word_4c6d94 != *(int16_t *)eax) {
                                                            var_1C = &decomp_var_3c;
                                                            esp = esp - 0x14;
                                                            sub_465f60(&arg_0);
                                                            eax = sub_421040();
                                                            ebx = eax;
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_20, 0x0);
                                                            if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                                                    var_1C = &decomp_var_38;
                                                                    sub_405090(&arg_10);
                                                                    var_20 = &decomp_var_48;
                                                                    esp = esp - 0x24;
                                                                    sub_465f60(&arg_0);
                                                                    eax = sub_420dd0();
                                                                    ebx = eax;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    sub_465fa0();
    sub_403430(&var_10, &arg_1c, *arg_20, &arg_1c, arg_20);
    sub_47c8f9();
    eax = ebx;
    *0x0 = saved_fp;
    return eax;
}
