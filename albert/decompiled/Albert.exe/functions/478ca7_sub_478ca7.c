// sub_478ca7 @ 0x478ca7
// hopper name: sub_478ca7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478ca7() {
    sub_47d6bb(0x8);
    esp = (esp - 0x8) + 0x4;
    ecx = sub_46dbce(0x10);
    eax = 0x0;
    decomp_var_4 = 0x0;
    if (ecx != 0x0) {
            esp = esp - 0x8;
            eax = sub_478c3b();
    }
    decomp_var_10 = eax;
    eax = sub_47a958(&decomp_var_10, 0x4c316c);
    asm { int3 };
    return eax;
}
