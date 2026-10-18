// sub_40ff50 @ 0x40ff50
// hopper name: sub_40ff50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40ff50() {
    eax = sub_46dbce(0x18);
    if (eax != 0x0) {
            *eax = 0x0;
    }
    ecx = eax + 0x4;
    if (ecx != 0x0) {
            *ecx = 0x0;
    }
    ecx = eax + 0x8;
    if (ecx != 0x0) {
            *ecx = 0x0;
    }
    eax[0x14] = 0x1;
    eax[0x15] = 0x0;
    return;
}
