// sub_40e3c0 @ 0x40e3c0
// hopper name: sub_40e3c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40e3c0() {
    eax = arg_0;
    ecx = eax[0x2];
    if (ecx[0x21] == 0x0) {
            do {
                    eax = ecx;
                    ecx = eax[0x2];
            } while (ecx[0x21] == 0x0);
    }
    return eax;
}
