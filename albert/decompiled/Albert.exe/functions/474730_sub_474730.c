// sub_474730 @ 0x474730
// hopper name: sub_474730
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474730() {
    eax = arg_0;
    esp = esp - 0x8;
    if (eax[0x2] == 0x0) {
            eax = 0x80010108;
    }
    else {
            bool_5 = true;
            bool_4 = true;
            bool_3 = true;
            bool_2 = true;
            if (arg_14 == 0x0) {
                    eax = 0x80004003;
            }
            else {
                    eax = eax[0x2];
                    ecx = *eax;
                    decomp_var_1c = arg_4;
                    decomp_var_1c = arg_4;
                    decomp_var_1c = arg_4;
                    esp = esp - 0x18;
                    decomp_var_1c = arg_4;
                    eax = (ecx[0xe])(eax);
            }
    }
    return eax;
}
