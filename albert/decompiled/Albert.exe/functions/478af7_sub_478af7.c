// sub_478af7 @ 0x478af7
// hopper name: sub_478af7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478af7() {
    esp = esp - 0x4;
    decomp_var_c = &var_4;
    esi = ecx;
    sub_4788be();
    if (var_4 != 0xffff) {
            eax = var_4 & 0xffff;
    }
    else {
            esp = esp - 0x4;
            sub_478901();
            eax = var_4;
    }
    return eax;
}
