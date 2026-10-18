// sub_4888e5 @ 0x4888e5
// hopper name: sub_4888e5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4888e5() {
    var_4 = ecx;
    decomp_var_8 = ebx;
    ebx = arg_0;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = 0x0;
    while (ebx != *(edi * 0x8 + 0x4c9aa8)) {
            edi = edi + 0x1;
            if (edi >= 0x17) {
                    break;
            }
    }
    if (edi < 0x17) {
            decomp_var_14 = ebp;
            esp = (esp - 0x8) + 0x4;
            if (sub_48f60c(0x3) != 0x1) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_48f60c(0x3) == 0x0) {
                            if (*dword_4c8e20 != 0x1) {
                                    if (ebx != 0xfc) {
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_47db5e(0xbc69f8, 0x314, "Runtime Error!\n\nProgram: ") != 0x0) {
                                                    decomp_var_18 = 0x0;
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            esp = esp - 0xc;
                                            *(int8_t *)byte_bc6b15 = 0x0;
                                            if (GetModuleFileNameA(0x0, 0xbc6a11, 0x104) == 0x0) {
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_47db5e(0xbc6a11, 0x2fb, "<program name unknown>") != 0x0) {
                                                            decomp_var_18 = 0x0;
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                            }
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_47d630(0xbc6a11) > 0x3b) {
                                                    eax = sub_47d630(0xbc6a11);
                                                    esp = (esp - 0x14) + 0x14;
                                                    if (sub_47f4a4(eax + 0xbc69d6, dword_bc6d0c - eax + 0xbc69d6, 0x4b7ba4, 0x3) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                            }
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_47f557(0xbc69f8, 0x314, 0x4b7ba0) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_47f557(0xbc69f8, 0x314, *(edi * 0x8 + 0x4c9aac)) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            sub_48f46e(0xbc69f8, "Microsoft Visual C++ Runtime Library", 0x12010);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    esp = esp + 0x4;
                            }
                            else {
                                    esp = esp - 0x4;
                                    ebp = GetStdHandle(0xfffffff4);
                                    if (ebp != 0x0) {
                                            if (ebp != 0xffffffff) {
                                                    esp = (esp - 0xc) + 0x4 - 0xc;
                                                    WriteFile(ebp, *(edi * 0x8 + 0x4c9aac), sub_47d630(*(edi * 0x8 + 0x4c9aac)), decomp_var_1c, decomp_var_18);
                                            }
                                    }
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            if (ebx != 0xfc) {
                                    esp = (esp - 0xc) + 0xc;
                                    if (sub_47db5e(0xbc69f8, 0x314, "Runtime Error!\n\nProgram: ") != 0x0) {
                                            decomp_var_18 = 0x0;
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    esp = esp - 0xc;
                                    *(int8_t *)byte_bc6b15 = 0x0;
                                    if (GetModuleFileNameA(0x0, 0xbc6a11, 0x104) == 0x0) {
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_47db5e(0xbc6a11, 0x2fb, "<program name unknown>") != 0x0) {
                                                    decomp_var_18 = 0x0;
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                    }
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_47d630(0xbc6a11) > 0x3b) {
                                            eax = sub_47d630(0xbc6a11);
                                            esp = (esp - 0x14) + 0x14;
                                            if (sub_47f4a4(eax + 0xbc69d6, dword_bc6d0c - eax + 0xbc69d6, 0x4b7ba4, 0x3) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                    }
                                    esp = (esp - 0xc) + 0xc;
                                    if (sub_47f557(0xbc69f8, 0x314, 0x4b7ba0) != 0x0) {
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    esp = (esp - 0xc) + 0xc;
                                    if (sub_47f557(0xbc69f8, 0x314, *(edi * 0x8 + 0x4c9aac)) != 0x0) {
                                            sub_47a828();
                                            esp = (esp - 0x14) + 0x14;
                                    }
                                    sub_48f46e(0xbc69f8, "Microsoft Visual C++ Runtime Library", 0x12010);
                                    esp = (esp - 0xc) + 0xc;
                            }
                            esp = esp + 0x4;
                    }
            }
            else {
                    esp = esp - 0x4;
                    ebp = GetStdHandle(0xfffffff4);
                    if (ebp != 0x0) {
                            if (ebp != 0xffffffff) {
                                    esp = (esp - 0xc) + 0x4 - 0xc;
                                    WriteFile(ebp, *(edi * 0x8 + 0x4c9aac), sub_47d630(*(edi * 0x8 + 0x4c9aac)), decomp_var_1c, decomp_var_18);
                            }
                    }
                    esp = esp + 0x4;
            }
    }
    return;
}
