// sub_471786 @ 0x471786
// hopper name: sub_471786
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471786() {
    if (sub_471691() != 0x0) {
            (*dword_bc5f28)();
    }
    else {
            esp = esp - 0x8;
            if ((arg_4 & 0x3) == 0x0) {
                    esi = arg_0;
                    if (esi[0x2] > 0x0 && esi[0x3] > 0x0) {
                            esp = esp - 0x4;
                            if (*esi < GetSystemMetrics(0x0)) {
                                    esp = esp - 0x4;
                                    esi[0x1] < GetSystemMetrics(0x1);
                            }
                    }
            }
    }
    return;
}
