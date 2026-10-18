// sub_419ed0 @ 0x419ed0
// hopper name: sub_419ed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_419ed0() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_0;
    ebx = ecx;
    esi = edi;
    if (edi[0x15] == 0x0) {
            do {
                    esp = esp - 0x4;
                    sub_419ed0(esi[0x2]);
                    eax = edi[0x4];
                    esi = *esi;
                    eax = eax - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
                    edi = esi;
            } while (esi[0x15] == 0x0);
    }
    return;
}
