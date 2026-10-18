// sub_47aa91 @ 0x47aa91
// hopper name: sub_47aa91
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47aa91() {
    esp = esp - 0x4;
    decomp_var_3c = ebx;
    if (arg_0 == 0x123) {
            *arg_4 = 0x47ab3a;
            eax = 0x1;
    }
    else {
            var_28 = *0x0;
            *0x0 = &var_28;
            var_34 = arg_0;
            (*(sub_480086() + 0x80))(*arg_0, &var_34);
            esp = (esp - 0x8) + 0x8;
            var_38 = 0x1 & 0x0;
            if ((var_4 & 0x0) != 0x0) {
                    *var_28 = **0x0;
                    *0x0 = var_28;
            }
            else {
                    *0x0 = var_28;
            }
            eax = var_38;
    }
    return eax;
}
