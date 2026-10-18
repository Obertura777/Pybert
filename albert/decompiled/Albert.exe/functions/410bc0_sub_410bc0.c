// sub_410bc0 @ 0x410bc0
// hopper name: sub_410bc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_410bc0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (esi[0x7] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x7] = 0xf;
    esi[0x6] = 0x0;
    esi[0x8] = 0x0;
    return 0x0;
}
