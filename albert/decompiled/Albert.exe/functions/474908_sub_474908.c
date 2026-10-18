// sub_474908 @ 0x474908
// hopper name: sub_474908
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474908() {
    eax = arg_0;
    esp = esp - 0x8;
    if (eax[0x2] == 0x0) {
            eax = 0x80010108;
    }
    else {
            if (arg_4 == 0x0) {
                    eax = 0x80004003;
            }
            else {
                    ecx = 0x0;
                    if (arg_8 != 0x0) {
                            if (arg_c != ecx) {
                                    bool_8 = true;
                                    bool_7 = true;
                                    bool_6 = true;
                                    bool_5 = true;
                                    if (arg_10 != ecx) {
                                            eax = eax[0x2];
                                            ecx = *eax;
                                            decomp_var_18 = arg_14;
                                            decomp_var_18 = arg_14;
                                            decomp_var_18 = arg_14;
                                            esp = esp - 0x24;
                                            decomp_var_18 = arg_14;
                                            eax = (ecx[0x16])(eax, arg_4, arg_8, arg_c, arg_10);
                                    }
                                    else {
                                            eax = 0x80004003;
                                    }
                            }
                            else {
                                    eax = 0x80004003;
                            }
                    }
                    else {
                            eax = 0x80004003;
                    }
            }
    }
    return eax;
}
