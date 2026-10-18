// sub_4747b0 @ 0x4747b0
// hopper name: sub_4747b0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4747b0() {
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
                    bool_6 = true;
                    bool_5 = true;
                    bool_4 = true;
                    bool_3 = true;
                    if (arg_18 != 0x0) {
                            eax = eax[0x2];
                            ecx = *eax;
                            decomp_var_1c = arg_8;
                            decomp_var_1c = arg_8;
                            decomp_var_1c = arg_8;
                            esp = esp - 0x1c;
                            decomp_var_1c = arg_8;
                            eax = (ecx[0x10])(eax, arg_4);
                    }
                    else {
                            eax = 0x80004003;
                    }
            }
    }
    return eax;
}
