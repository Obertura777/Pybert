// sub_46b340 @ 0x46b340
// hopper name: sub_46b340
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46b340() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_0;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    ebp = ecx;
    edi = esi;
    if (esi[0x2d] == 0x0) {
            do {
                    esp = esp - 0x4;
                    sub_46b340(edi[0x2]);
                    bool_2 = esi[0xa] < 0x10;
                    edi = *edi;
                    if (!bool_2) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    esi[0xa] = 0xf;
                    esi[0x9] = 0x0;
                    esi[0x14] = 0x0;
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
                    esi = edi;
            } while (edi[0x2d] == 0x0);
    }
    return;
}
