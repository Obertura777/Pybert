// sub_47ccc0 @ 0x47ccc0
// hopper name: sub_47ccc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ccc0() {
    ecx = arg_4;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (ecx > 0x0) {
            esp = (esp - 0x4) + 0x4;
            if (0xffffffe0 / ecx < arg_8) {
                    *sub_47d812() = 0xc;
                    sub_47a924();
            }
            else {
                    sub_47caa5();
            }
    }
    else {
            sub_47caa5();
    }
    return;
}
