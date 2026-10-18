// sub_46dbce @ 0x46dbce
// hopper name: sub_46dbce
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46dbce() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    while (true) {
            esi = sub_47c836();
            esp = (esp - 0x4) + 0x4;
            if (esi != 0x0) {
                    temp_0 = 0x0;
                    break;
            }
            else {
                    if (*dword_4c833c != 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            if (dword_4c833c(edi) != 0x0) {
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x0;
                            break;
                    }
            }
    }
    eax = esi;
    return eax;
}
