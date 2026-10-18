// sub_425ae0 @ 0x425ae0
// hopper name: sub_425ae0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_425ae0() {
    decomp_var_10 = esi;
    esi = ecx;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    if (esi[0x2] == 0x0) {
            sub_41c940(arg_0, 0x1, esi[0x1], arg_c, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4);
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
                    if (*(int16_t *)edi < ebx[0x6]) {
                            sub_41c940(arg_0, 0x1, ebx, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                            eax = arg_0;
                    }
                    else {
                            eax = sub_4224f0(&var_C, edi, decomp_var_1c);
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
                            eax = *(esi[0x1] + 0x8);
                            if (eax[0x6] < *(int16_t *)edi) {
                                    sub_41c940(arg_0, 0x0, eax, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                    eax = arg_0;
                            }
                            else {
                                    eax = sub_4224f0(&var_C, edi, decomp_var_1c);
                                    *arg_0 = *eax;
                                    arg_0[0x1] = eax[0x1];
                                    eax = arg_0;
                            }
                    }
                    else {
                            eax = *(int16_t *)edi & 0xffff;
                            bool_9 = ebx[0x6] >= eax;
                            if (ebx[0x6] > eax) {
                                    arg_4 = ebp;
                                    sub_40f920();
                                    eax = *(int16_t *)edi & 0xffff;
                                    ecx = ebx;
                                    bool_12 = ecx[0x6] >= eax;
                                    if (ecx[0x6] < eax) {
                                            esp = esp - 0x4;
                                            decomp_var_20 = edi;
                                            edi = arg_0;
                                            if (*(int8_t *)(ecx[0x2] + 0x2d) != 0x0) {
                                                    sub_41c940(edi, 0x0, ecx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                            else {
                                                    sub_41c940(edi, 0x1, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                    }
                                    else {
                                            if (!bool_12) {
                                                    var_C = esi;
                                                    sub_40f5f0();
                                                    esp = esp - 0x4;
                                                    eax = sub_40dfe0(&var_C);
                                                    bool_19 = eax != 0x0;
                                                    eax = ebx;
                                                    if (!bool_19) {
                                                            if (*(int16_t *)edi < eax[0x6]) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_20 = edi;
                                                                    edi = arg_0;
                                                                    if (*(int8_t *)(ebx[0x2] + 0x2d) != 0x0) {
                                                                            sub_41c940(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                                    else {
                                                                            sub_41c940(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_4224f0(&var_C, edi, decomp_var_1c);
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
                                                                    sub_41c940(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_41c940(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = sub_4224f0(&var_C, edi, decomp_var_1c);
                                                    *arg_0 = *eax;
                                                    arg_0[0x1] = eax[0x1];
                                                    eax = arg_0;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_9) {
                                            var_C = esi;
                                            sub_40f5f0();
                                            esp = esp - 0x4;
                                            eax = sub_40dfe0(&var_C);
                                            bool_13 = eax != 0x0;
                                            eax = ebx;
                                            if (!bool_13) {
                                                    if (*(int16_t *)edi < eax[0x6]) {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x2d) != 0x0) {
                                                                    sub_41c940(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_41c940(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_4224f0(&var_C, edi, decomp_var_1c);
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
                                                            sub_41c940(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                                    else {
                                                            sub_41c940(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_4224f0(&var_C, edi, decomp_var_1c);
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
