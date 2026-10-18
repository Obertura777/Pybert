// sub_47b678 @ 0x47b678
// hopper name: sub_47b678
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b678() {
    eax = sub_480086();
    ecx = eax[0x5];
    eax[0x5] = ecx * 0x343fd + 0x269ec3;
    eax = ecx * 0x343fd + 0x269ec3 >> 0x10 & 0x7fff;
    return eax;
}
