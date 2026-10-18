// sub_476745 @ 0x476745
// hopper name: sub_476745
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476745() {
    if (ecx[0x14] == 0x0) {
            GetWindowLongA(ecx[0x8], 0xfffffff0);
    }
    else {
            (*(*ecx[0x14] + 0x78))();
    }
    return;
}
