// sub_4766b8 @ 0x4766b8
// hopper name: sub_4766b8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4766b8() {
    if (ecx[0x13] != 0x0) {
            eax = *ecx[0x13];
            eax = (eax[0x15])();
    }
    else {
            eax = 0x0;
    }
    return eax;
}
