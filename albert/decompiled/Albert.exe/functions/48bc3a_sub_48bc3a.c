// sub_48bc3a @ 0x48bc3a
// hopper name: sub_48bc3a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bc3a() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x4;
    esi = ecx;
    if (esi != 0x0) {
            if (*(int8_t *)esi != 0x0) {
                    esp = (esp - 0x8) + 0x8;
                    if (sub_47fd80(esi, 0x4b9470) != 0x0) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_47fd80(esi, 0x4b946c) == 0x0) {
                                    decomp_var_14 = 0x8;
                                    decomp_var_18 = &var_C;
                                    esp = esp - 0xc;
                                    decomp_var_1c = 0xb;
                                    esp = esp - 0x4;
                                    decomp_var_20 = edi[0x7];
                                    if (GetLocaleInfoA(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14) != 0x0) {
                                            esi = &var_C;
                                            sub_47b259(esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    eax = sub_47ad69();
                            }
                            else {
                                    sub_47b259(esi);
                                    esp = (esp - 0x4) + 0x4;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            decomp_var_14 = 0x8;
                            decomp_var_18 = &var_C;
                            esp = esp - 0xc;
                            decomp_var_1c = 0x1004;
                            esp = esp - 0x4;
                            decomp_var_20 = edi[0x7];
                            if (GetLocaleInfoA(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14) != 0x0) {
                                    esi = &var_C;
                                    sub_47b259(esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                            eax = sub_47ad69();
                    }
            }
            else {
                    decomp_var_14 = 0x8;
                    decomp_var_18 = &var_C;
                    esp = esp - 0xc;
                    decomp_var_1c = 0x1004;
                    esp = esp - 0x4;
                    decomp_var_20 = edi[0x7];
                    if (GetLocaleInfoA(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14) != 0x0) {
                            esi = &var_C;
                            sub_47b259(esi);
                            esp = (esp - 0x4) + 0x4;
                    }
                    eax = sub_47ad69();
            }
    }
    else {
            decomp_var_14 = 0x8;
            decomp_var_18 = &var_C;
            esp = esp - 0xc;
            decomp_var_1c = 0x1004;
            esp = esp - 0x4;
            decomp_var_20 = edi[0x7];
            if (GetLocaleInfoA(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14) != 0x0) {
                    esi = &var_C;
                    sub_47b259(esi);
                    esp = (esp - 0x4) + 0x4;
            }
            eax = sub_47ad69();
    }
    return eax;
}
