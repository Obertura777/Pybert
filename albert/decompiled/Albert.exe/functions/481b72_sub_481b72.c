// sub_481b72 @ 0x481b72
// hopper name: sub_481b72
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481b72() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_0;
    esp = esp - 0x14;
    InterlockedIncrement(esi, edi, decomp_var_c, decomp_var_8, decomp_var_4);
    eax = esi[0x2c];
    if (eax != 0x0) {
            esp = esp - 0x4;
            InterlockedIncrement(eax, decomp_var_8, decomp_var_4);
    }
    eax = esi[0x2e];
    if (eax != 0x0) {
            esp = esp - 0x4;
            InterlockedIncrement(eax);
    }
    eax = esi[0x2d];
    if (eax != 0x0) {
            esp = esp - 0x4;
            InterlockedIncrement(eax);
    }
    eax = esi[0x30];
    if (eax != 0x0) {
            esp = esp - 0x4;
            InterlockedIncrement(eax);
    }
    ebx = esi + 0x50;
    esp = (esp - 0x4) + 0x4;
    do {
            if (*(ebx - 0x8) != 0x4c9518) {
                    eax = *ebx;
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            InterlockedIncrement(eax);
                    }
            }
            if (*(ebx - 0x4) != 0x0) {
                    eax = ebx[0x1];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            InterlockedIncrement(eax);
                    }
            }
            ebx = ebx + 0x10;
    } while (&decomp_var_1 != 0x0);
    eax = esi[0x35];
    eax = InterlockedIncrement(eax + 0xb4);
    return eax;
}
