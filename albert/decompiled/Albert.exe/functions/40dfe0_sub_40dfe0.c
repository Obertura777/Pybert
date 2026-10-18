// sub_40dfe0 @ 0x40dfe0
// hopper name: sub_40dfe0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40dfe0() {
    decomp_var_4 = esi;
    esi = ecx;
    eax = *esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    if (eax == 0x0 || eax != *edi) {
            sub_47a948();
    }
    eax = esi[0x1] == edi[0x1] ? 0x1 : 0x0;
    return eax;
}
