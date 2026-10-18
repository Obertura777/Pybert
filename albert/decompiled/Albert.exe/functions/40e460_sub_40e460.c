// sub_40e460 @ 0x40e460
// hopper name: sub_40e460
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40e460() {
    eax = arg_0;
    ecx = *eax;
    if (ecx[0xbd] == 0x0) {
            do {
                    eax = ecx;
                    ecx = *eax;
            } while (ecx[0xbd] == 0x0);
    }
    return eax;
}
