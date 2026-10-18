// sub_477dfa @ 0x477dfa
// hopper name: sub_477dfa
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477dfa() {
    esp = esp - 0x4;
    decomp_var_4 = edi;
    edi = arg_0;
    if (edi != 0x0) {
            esp = esp - 0x8;
            esi = GlobalFlags(edi) & 0xff;
            if (esi != 0x0) {
                    do {
                            esp = esp - 0x4;
                            esi = esi - 0x1;
                            GlobalUnlock(edi);
                    } while (esi != 0x0);
            }
            GlobalFree(edi);
            esp = (esp - 0x4) + 0x4;
    }
    return;
}
