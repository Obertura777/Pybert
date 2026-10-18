// sub_40ee50 @ 0x40ee50
// hopper name: sub_40ee50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40ee50() {
    eax = ecx[0x1];
    decomp_var_4 = esi;
    esi = eax[0x1];
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = eax;
    if (esi[0x1d] == 0x0) {
            esp = esp - 0x4;
            ebx = arg_0;
            do {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            edi = esi;
                            esi = *esi;
                    }
            } while (esi[0x1d] == 0x0);
            eax = edi;
            esp = esp + 0x4;
    }
    return eax;
}
