// sub_41c780 @ 0x41c780
// hopper name: sub_41c780
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41c780() {
    decomp_var_10 = esi;
    esi = ecx;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    if (esi[0x2] == 0x0) {
            sub_4159b0(arg_0, 0x1, esi[0x1], arg_c, decomp_var_14, decomp_var_10, var_C, var_8, decomp_var_4);
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
                    if (*edi < ebx[0x3]) {
                            sub_4159b0(arg_0, 0x1, ebx, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                            eax = arg_0;
                    }
                    else {
                            eax = sub_41ae40(&var_C, edi, decomp_var_1c);
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
                            if (eax[0x3] < *edi) {
                                    sub_4159b0(arg_0, 0x0, eax, edi, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                    eax = arg_0;
                            }
                            else {
                                    eax = sub_41ae40(&var_C, edi, decomp_var_1c);
                                    *arg_0 = *eax;
                                    arg_0[0x1] = eax[0x1];
                                    eax = arg_0;
                            }
                    }
                    else {
                            eax = *edi;
                            bool_19 = ebx[0x3] <= eax;
                            bool_18 = ebx[0x3] >= eax;
                            if (!bool_19) {
                                    arg_4 = ebp;
                                    sub_40e560();
                                    eax = *edi;
                                    ecx = ebx;
                                    bool_17 = ecx[0x3] >= eax;
                                    if (ecx[0x3] < eax) {
                                            esp = esp - 0x4;
                                            decomp_var_20 = edi;
                                            edi = arg_0;
                                            if (*(int8_t *)(ecx[0x2] + 0x29) != 0x0) {
                                                    sub_4159b0(edi, 0x0, ecx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                            else {
                                                    sub_4159b0(edi, 0x1, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                    eax = edi;
                                            }
                                    }
                                    else {
                                            if (!bool_17) {
                                                    var_C = esi;
                                                    sub_40e210();
                                                    esp = esp - 0x4;
                                                    eax = sub_40dfe0(&var_C);
                                                    bool_14 = eax != 0x0;
                                                    eax = ebx;
                                                    if (!bool_14) {
                                                            if (*edi < eax[0x3]) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_20 = edi;
                                                                    edi = arg_0;
                                                                    if (*(int8_t *)(ebx[0x2] + 0x29) != 0x0) {
                                                                            sub_4159b0(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                                    else {
                                                                            sub_4159b0(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                            eax = edi;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_41ae40(&var_C, edi, decomp_var_1c);
                                                                    *arg_0 = *eax;
                                                                    arg_0[0x1] = eax[0x1];
                                                                    eax = arg_0;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x29) != 0x0) {
                                                                    sub_4159b0(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_4159b0(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = sub_41ae40(&var_C, edi, decomp_var_1c);
                                                    *arg_0 = *eax;
                                                    arg_0[0x1] = eax[0x1];
                                                    eax = arg_0;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_18) {
                                            var_C = esi;
                                            sub_40e210();
                                            esp = esp - 0x4;
                                            eax = sub_40dfe0(&var_C);
                                            bool_20 = eax != 0x0;
                                            eax = ebx;
                                            if (!bool_20) {
                                                    if (*edi < eax[0x3]) {
                                                            esp = esp - 0x4;
                                                            decomp_var_20 = edi;
                                                            edi = arg_0;
                                                            if (*(int8_t *)(ebx[0x2] + 0x29) != 0x0) {
                                                                    sub_4159b0(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                            else {
                                                                    sub_4159b0(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                                    eax = edi;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_41ae40(&var_C, edi, decomp_var_1c);
                                                            *arg_0 = *eax;
                                                            arg_0[0x1] = eax[0x1];
                                                            eax = arg_0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_20 = edi;
                                                    edi = arg_0;
                                                    if (*(int8_t *)(ebx[0x2] + 0x29) != 0x0) {
                                                            sub_4159b0(edi, 0x0, ebx, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                                    else {
                                                            sub_4159b0(edi, 0x1, eax, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C);
                                                            eax = edi;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_41ae40(&var_C, edi, decomp_var_1c);
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
