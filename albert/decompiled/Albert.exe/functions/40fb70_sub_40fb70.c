// sub_40fb70 @ 0x40fb70
// hopper name: sub_40fb70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40fb70() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_0;
    ebx = ecx;
    esi = edi;
    if (edi[0x19] == 0x0) {
            do {
                    sub_40fb70(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x19] == 0x0);
    }
    return;
}
