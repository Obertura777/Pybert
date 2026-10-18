// sub_47b75b @ 0x47b75b
// hopper name: sub_47b75b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b75b() {
    esp = esp - 0x4;
    decomp_var_24 = esi;
    if (arg_4 == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = eax | 0xffffffff;
    }
    else {
            var_20 = 0x0;
            eax = (arg_0)(&var_20, arg_4, arg_8, arg_c, decomp_var_24);
            esp = (esp - 0x10) + 0x10;
    }
    return eax;
}
