// sub_4775b4 @ 0x4775b4
// hopper name: sub_4775b4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4775b4() {
    esp = esp - 0x4;
    decomp_var_4 = 0x8;
    sub_47d6ee(0x8);
    esi = ecx;
    if (*esi == 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = 0x10;
            sub_478104();
            decomp_var_4 = decomp_var_4 & 0x0;
            if (*esi == 0x0) {
                    *esi = (arg_4)(decomp_var_8, decomp_var_4);
            }
            sub_478171();
    }
    eax = sub_47d75a();
    return eax;
}
