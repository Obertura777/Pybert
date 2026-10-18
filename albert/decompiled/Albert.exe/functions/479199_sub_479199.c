// sub_479199 @ 0x479199
// hopper name: sub_479199
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479199() {
    eax = arg_0;
    *eax = ecx[0x4];
    ecx[0x3] = ecx[0x3] - 0x1;
    bool_0 = ecx[0x3] != 0x0;
    ecx[0x4] = eax;
    if (!bool_0) {
            eax = sub_47916e();
    }
    return eax;
}
