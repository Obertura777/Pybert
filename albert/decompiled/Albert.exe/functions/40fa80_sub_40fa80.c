// sub_40fa80 @ 0x40fa80
// hopper name: sub_40fa80
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40fa80() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (*esi == 0x0) {
            sub_47a948();
    }
    if (esi[0x1] == *(*esi + 0x4)) {
            sub_47a948();
    }
    eax = esi[0x1];
    eax = eax + 0x10;
    return eax;
}
