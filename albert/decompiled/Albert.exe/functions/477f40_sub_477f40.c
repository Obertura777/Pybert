// sub_477f40 @ 0x477f40
// hopper name: sub_477f40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477f40() {
    eax = sub_4715ba();
    eax = InterlockedIncrement(eax + 0x2c);
    return eax;
}
