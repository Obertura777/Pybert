// sub_48de66 @ 0x48de66
// hopper name: sub_48de66
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48de66() {
    if (arg_4 == 0x7ff00000) {
            if (arg_0 == 0x0) {
                    eax = 0x1;
            }
            else {
                    ecx = arg_6 & 0x7ff8;
                    if (ecx == 0x7ff8) {
                            esp = esp - 0x4;
                            decomp_var_4 = 0x3;
                            eax = decomp_var_4;
                    }
                    else {
                            if (ecx == 0x7ff0) {
                                    if ((arg_4 & 0x7ffff) == 0x0) {
                                            if (arg_0 != 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_4 = 0x4;
                                                    eax = decomp_var_4;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_4 = 0x4;
                                            eax = decomp_var_4;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    else {
            if (arg_4 == 0xfff00000) {
                    if (arg_0 == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_4 = 0x2;
                            eax = decomp_var_4;
                    }
                    else {
                            ecx = arg_6 & 0x7ff8;
                            if (ecx == 0x7ff8) {
                                    esp = esp - 0x4;
                                    decomp_var_4 = 0x3;
                                    eax = decomp_var_4;
                            }
                            else {
                                    if (ecx == 0x7ff0) {
                                            if ((arg_4 & 0x7ffff) == 0x0) {
                                                    if (arg_0 != 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_4 = 0x4;
                                                            eax = decomp_var_4;
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_4 = 0x4;
                                                    eax = decomp_var_4;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ecx = arg_6 & 0x7ff8;
                    if (ecx == 0x7ff8) {
                            esp = esp - 0x4;
                            decomp_var_4 = 0x3;
                            eax = decomp_var_4;
                    }
                    else {
                            if (ecx == 0x7ff0) {
                                    if ((arg_4 & 0x7ffff) == 0x0) {
                                            if (arg_0 != 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_4 = 0x4;
                                                    eax = decomp_var_4;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_4 = 0x4;
                                            eax = decomp_var_4;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    return eax;
}
