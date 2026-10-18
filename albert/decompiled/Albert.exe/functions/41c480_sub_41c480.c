// sub_41c480 @ 0x41c480
// hopper name: sub_41c480
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41c480() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    ebx = ecx;
    edi = esi;
    if (esi[0x31] == 0x0) {
            esp = esp - 0x4;
            decomp_var_10 = ebp;
            do {
                    esp = esp - 0x4;
                    sub_41c480(edi[0x2]);
                    ecx = esi[0xa];
                    eax = *ecx;
                    edi = *edi;
                    *ecx = ecx;
                    ecx = esi[0xa];
                    ecx[0x1] = ecx;
                    bool_1 = eax == esi[0xa];
                    esi[0xb] = 0x0;
                    if (!bool_1) {
                            do {
                                    ebp = *eax;
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                                    eax = ebp;
                            } while (ebp != esi[0xa]);
                    }
                    sub_47c8f9();
                    esi[0xa] = 0x0;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x8;
                    esi = edi;
            } while (edi[0x31] == 0x0);
            esp = esp + 0x4;
    }
    return;
}
