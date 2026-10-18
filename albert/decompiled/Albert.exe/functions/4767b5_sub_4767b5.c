// sub_4767b5 @ 0x4767b5
// hopper name: sub_4767b5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4767b5() {
    if (ecx[0x14] == 0x0) {
            EnableWindow(ecx[0x8], arg_0);
    }
    else {
            (*(*ecx[0x14] + 0xa8))();
    }
    return;
}
