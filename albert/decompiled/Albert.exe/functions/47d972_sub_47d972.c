// sub_47d972 @ 0x47d972
// hopper name: sub_47d972
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d972() {
    if (sub_47b30b != 0x0) {
            decomp_var_4 = dword_value_4698891;
            esp = (esp - 0x4) + 0x4;
            if (sub_488b62() != 0x0) {
                    sub_47b30b(arg_0);
                    esp = (esp - 0x4) + 0x4;
            }
    }
    sub_483c86();
    esp = (esp - 0x8) + 0x8;
    if (sub_47d8df(0x4af408, 0x4af428) == 0x0) {
            saved_fp = esi;
            decomp_var_4 = edi;
            sub_47ae90(0x48921f);
            esi = 0x4ad438;
            esp = (esp - 0xc) + 0x4;
            if (0x4ad438 < 0x4af404) {
                    do {
                            eax = *esi;
                            if (eax != 0x0) {
                                    (eax)();
                            }
                            esi = esi + 0x4;
                    } while (esi < 0x4af404);
            }
            esp = esp + 0x8;
            if (*dword_bc8380 != 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_488b62() != 0x0) {
                            (*dword_bc8380)(0x0, 0x2, 0x0);
                    }
            }
    }
    return;
}
