// sub_45eff0 @ 0x45eff0
// hopper name: sub_45eff0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45eff0() {
    decomp_var_10 = esi;
    esi = ecx;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    if (esi[0x2] == 0x0) {
            sub_45e620(arg_0, 0x1, esi[0x1], arg_c, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4);
            eax = arg_0;
    }
    else {
            edi = *esi[0x1];
            esp = esp - 0x4;
            decomp_var_18 = ebp;
            ebp = arg_4;
            if (ebp == 0x0 || ebp != esi) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_1c = ebx;
            ebx = arg_8;
            if (ebx == edi) {
                    edi = arg_c;
                    esp = esp - 0x8;
                    if (sub_45bc10(edi, ebx + 0xc, decomp_var_1c) != 0x0) {
                            sub_45e620(arg_0, 0x1, ebx, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                            eax = arg_0;
                    }
                    else {
                            eax = sub_45ea80(&var_C, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4, saved_fp, arg_0);
                            *arg_0 = *eax;
                            arg_0[0x1] = eax[0x1];
                            eax = arg_0;
                    }
            }
            else {
                    edi = esi[0x1];
                    if (ebp == 0x0 || ebp != esi) {
                            sub_47a948();
                    }
                    bool_6 = ebx != edi;
                    edi = arg_c;
                    if (!bool_6) {
                            esp = esp - 0x8;
                            if (sub_45bc10(*(esi[0x1] + 0x8) + 0xc, edi, decomp_var_1c) != 0x0) {
                                    sub_45e620(arg_0, 0x0, *(esi[0x1] + 0x8), edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                    eax = arg_0;
                            }
                            else {
                                    eax = sub_45ea80(&var_C, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4, saved_fp, arg_0);
                                    *arg_0 = *eax;
                                    arg_0[0x1] = eax[0x1];
                                    eax = arg_0;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            if (sub_45bc10(edi, ebx + 0xc, decomp_var_1c) != 0x0) {
                                    arg_4 = ebp;
                                    arg_8 = ebx;
                                    sub_40f920();
                                    esp = esp - 0x8;
                                    if (sub_45bc10(arg_8 + 0xc, edi, decomp_var_1c) != 0x0) {
                                            eax = arg_8;
                                            esp = esp - 0x4;
                                            decomp_var_20 = edi;
                                            edi = arg_0;
                                            if (*(int8_t *)(eax[0x2] + 0x2d) != 0x0) {
                                                    sub_45e620(edi, 0x0, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                            else {
                                                    sub_45e620(edi, 0x1, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            if (sub_45bc10(ebx + 0xc, edi, decomp_var_1c) != 0x0) {
                                                    arg_8 = ebx;
                                                    var_8 = esi[0x1];
                                                    var_C = esi;
                                                    sub_40f5f0();
                                                    esp = esp - 0x4;
                                                    eax = sub_40dfe0(&var_C);
                                                    ebp = arg_8;
                                                    if (eax == 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = sub_45bc10(edi, &arg_8, decomp_var_1c);
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_20 = edi;
                                                                    edi = arg_0;
                                                                    if (*(int8_t *)(ebx[0x2] + 0x2d) != 0x0) {
                                                                            sub_45e620(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                                    else {
                                                                            sub_45e620(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_45ea80(&var_C, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4, saved_fp, arg_0);
                                                                    *arg_0 = *eax;
                                                                    arg_0[0x1] = eax[0x1];
                                                                    eax = arg_0;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x2d) != 0x0) {
                                                                    sub_45e620(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_45e620(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = sub_45ea80(&var_C, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4, saved_fp, arg_0);
                                                    *arg_0 = *eax;
                                                    arg_0[0x1] = eax[0x1];
                                                    eax = arg_0;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    if (sub_45bc10(ebx + 0xc, edi, decomp_var_1c) != 0x0) {
                                            arg_8 = ebx;
                                            var_8 = esi[0x1];
                                            var_C = esi;
                                            sub_40f5f0();
                                            esp = esp - 0x4;
                                            eax = sub_40dfe0(&var_C);
                                            ebp = arg_8;
                                            if (eax == 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = sub_45bc10(edi, &arg_8, decomp_var_1c);
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x2d) != 0x0) {
                                                                    sub_45e620(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_45e620(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_45ea80(&var_C, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4, saved_fp, arg_0);
                                                            *arg_0 = *eax;
                                                            arg_0[0x1] = eax[0x1];
                                                            eax = arg_0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_20 = edi;
                                                    edi = arg_0;
                                                    if (*(int8_t *)(ebx[0x2] + 0x2d) != 0x0) {
                                                            sub_45e620(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                                    else {
                                                            sub_45e620(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_45ea80(&var_C, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4, saved_fp, arg_0);
                                            *arg_0 = *eax;
                                            arg_0[0x1] = eax[0x1];
                                            eax = arg_0;
                                    }
                            }
                    }
            }
    }
    return eax;
}
