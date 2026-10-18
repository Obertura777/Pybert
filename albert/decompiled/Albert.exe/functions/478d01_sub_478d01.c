// sub_478d01 @ 0x478d01
// hopper name: sub_478d01
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478d01() {
    eax = *ecx;
    if (eax != 0x0) {
            eax = GlobalFree(eax);
    }
    return eax;
}
