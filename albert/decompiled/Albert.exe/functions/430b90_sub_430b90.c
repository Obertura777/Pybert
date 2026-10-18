// sub_430b90 @ 0x430b90
// hopper name: sub_430b90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_430b90() {
    decomp_var_10 = esi;
    esi = ecx;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    if (esi[0x2] == 0x0) {
            sub_430550(arg_0, 0x1, esi[0x1], arg_c, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4);
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
                    if (sub_401120(edi, ebx + 0xc) != 0x0) {
                            sub_430550(arg_0, 0x1, ebx, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                            eax = arg_0;
                    }
                    else {
                            eax = sub_4308b0(&var_C, edi);
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
                            ebx = *(esi[0x1] + 0x8);
                            esp = esp - 0x8;
                            if (sub_401120(ebx + 0xc, edi) != 0x0) {
                                    sub_430550(arg_0, 0x0, ebx, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                    eax = arg_0;
                            }
                            else {
                                    eax = sub_4308b0(&var_C, edi);
                                    *arg_0 = *eax;
                                    arg_0[0x1] = eax[0x1];
                                    eax = arg_0;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            if (sub_401120(edi, ebx + 0xc) != 0x0) {
                                    arg_4 = ebp;
                                    arg_8 = ebx;
                                    sub_40f660();
                                    esp = esp - 0x8;
                                    if (sub_401120(arg_8 + 0xc, edi) != 0x0) {
                                            eax = arg_8;
                                            esp = esp - 0x4;
                                            decomp_var_20 = edi;
                                            edi = arg_0;
                                            if (*(int8_t *)(eax[0x2] + 0x21) != 0x0) {
                                                    sub_430550(edi, 0x0, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                            else {
                                                    sub_430550(edi, 0x1, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            if (sub_401120(ebx + 0xc, edi) != 0x0) {
                                                    arg_8 = ebx;
                                                    var_C = esi;
                                                    sub_40f6f0();
                                                    esp = esp - 0x4;
                                                    eax = sub_40dfe0(&var_C);
                                                    ebp = arg_8;
                                                    if (eax == 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = sub_401120(edi, &arg_8);
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_20 = edi;
                                                                    edi = arg_0;
                                                                    if (*(int8_t *)(ebx[0x2] + 0x21) != 0x0) {
                                                                            sub_430550(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                                    else {
                                                                            sub_430550(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_4308b0(&var_C, edi);
                                                                    *arg_0 = *eax;
                                                                    arg_0[0x1] = eax[0x1];
                                                                    eax = arg_0;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x21) != 0x0) {
                                                                    sub_430550(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_430550(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = sub_4308b0(&var_C, edi);
                                                    *arg_0 = *eax;
                                                    arg_0[0x1] = eax[0x1];
                                                    eax = arg_0;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    if (sub_401120(ebx + 0xc, edi) != 0x0) {
                                            arg_8 = ebx;
                                            var_C = esi;
                                            sub_40f6f0();
                                            esp = esp - 0x4;
                                            eax = sub_40dfe0(&var_C);
                                            ebp = arg_8;
                                            if (eax == 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = sub_401120(edi, &arg_8);
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x21) != 0x0) {
                                                                    sub_430550(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_430550(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_4308b0(&var_C, edi);
                                                            *arg_0 = *eax;
                                                            arg_0[0x1] = eax[0x1];
                                                            eax = arg_0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_20 = edi;
                                                    edi = arg_0;
                                                    if (*(int8_t *)(ebx[0x2] + 0x21) != 0x0) {
                                                            sub_430550(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                                    else {
                                                            sub_430550(edi, 0x1, ebp, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_4308b0(&var_C, edi);
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
