// sub_46e486 @ 0x46e486
// hopper name: sub_46e486
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e486() {
    ebx = arg_0;
    esp = esp - 0x4;
    decomp_var_8 = esi;
    esi = ecx;
    if (ebx <= 0x0) {
            esp = esp - 0x4;
            sub_46f8ec(ebx, decomp_var_8, decomp_var_4);
            if (esi[0x16] != 0x0) {
                    eax = *esi[0x16];
                    eax = (eax[0x4])();
                    arg_0 = eax;
                    if (eax != 0x0) {
                            do {
                                    eax = *esi[0x16];
                                    esp = esp - 0x4;
                                    eax = (eax[0x5])(&arg_0);
                                    (*(*eax + 0x88))();
                            } while (arg_0 != 0x0);
                    }
            }
    }
    else {
            if (ebx == 0x1) {
                    esp = esp - 0x4;
                    sub_46f8ec(ebx, decomp_var_8, decomp_var_4);
            }
    }
    eax = ebx < 0x1 ? 0x1 : 0x0;
    return eax;
}
