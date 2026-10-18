// sub_479d75 @ 0x479d75
// hopper name: sub_479d75
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479d75() {
    eax = arg_4;
    if (eax == 0x0 || arg_8 == 0x0) {
            sub_46dedc();
    }
    eax = sub_46dbce(eax * arg_8 + 0x4);
    *eax = *arg_0;
    *arg_0 = eax;
    return eax;
}
