// sub_47b26f @ 0x47b26f
// hopper name: sub_47b26f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b26f() {
    GetSystemTimeAsFileTime(&var_8);
    eax = sub_483170(var_8 + 0x2ac18000, var_4 + 0xfe624e21 + CARRY(EFLAGS(cf)), 0x989680, 0x0);
    ecx = arg_0;
    if (ecx != 0x0) {
            *ecx = eax;
            ecx[0x1] = edx;
    }
    return eax;
}
