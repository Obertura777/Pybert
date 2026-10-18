// sub_47c8f9 @ 0x47c8f9
// hopper name: sub_47c8f9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c8f9() {
    decomp_var_4 = 0xc;
    esp = esp - 0x8;
    sub_47f31c(0x4c3488, 0xc);
    esi = arg_4;
    if (esi != 0x0) {
            if (*dword_bc720c == 0x3) {
                    sub_487c06(0x4);
                    eax = sub_487d79(esi);
                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                    decomp_var_1c = eax;
                    if (eax != 0x0) {
                            sub_487da4(eax, esi);
                            esp = (esp - 0x8) + 0x8;
                    }
                    sub_47c94f();
                    if (decomp_var_1c == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_c = arg_4;
                            esp = esp - 0x8;
                            if (HeapFree(*dword_bc69f4, 0x0, decomp_var_c) == 0x0) {
                                    *sub_47d812() = sub_47d7d7(GetLastError());
                            }
                            sub_47f361();
                    }
                    else {
                            sub_47f361();
                    }
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_c = esi;
                    esp = esp - 0x8;
                    if (HeapFree(*dword_bc69f4, 0x0, decomp_var_c) == 0x0) {
                            *sub_47d812() = sub_47d7d7(GetLastError());
                    }
                    sub_47f361();
            }
    }
    else {
            sub_47f361();
    }
    return;
}
