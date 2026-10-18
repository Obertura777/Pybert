// sub_489876 @ 0x489876
// hopper name: sub_489876
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_489876() {
    sub_47f31c(0x4c3910, 0x14);
    decomp_var_1c = 0x0;
    decomp_var_c = *dword_bc6e48;
    esp = (esp - 0xc) + 0x4;
    esi = sub_47fe7c(*dword_bc6e48);
    if (esi == 0x0) {
            eax = sub_47d8ff(&decomp_var_1c);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    decomp_var_c = 0x0;
                    decomp_var_1c = 0x0;
                    sub_47a828();
                    esp = (esp - 0x14) + 0x14;
            }
            if (decomp_var_1c != 0x1) {
                    edi = 0x0;
                    esp = esp - 0x4;
                    eax = GetModuleHandleA("kernel32.dll");
                    if (eax != 0x0) {
                            esp = esp - 0x8;
                            esi = GetProcAddress(eax, "InitializeCriticalSectionAndSpinCount");
                            if (esi == edi) {
                                    esi = sub_489866;
                            }
                    }
                    else {
                            esi = sub_489866;
                    }
            }
            else {
                    esi = sub_489866;
            }
            esp = (esp - 0x4) + 0x4;
            *dword_bc6e48 = sub_47fe10(esi);
    }
    decomp_var_20 = (esi)(arg_4, arg_8);
    eax = sub_47f361();
    return eax;
}
