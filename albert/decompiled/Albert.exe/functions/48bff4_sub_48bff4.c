// sub_48bff4 @ 0x48bff4
// hopper name: sub_48bff4
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bff4() {
    var_4 = *dword_4c8db8 ^ ebp;
    esi = sub_480086() + 0x9c;
    edi = sub_48bccf();
    eax = esi[0x4];
    esp = esp - 0x18;
    eax = GetLocaleInfoA(edi, (-eax - -eax + CARRY(EFLAGS(cf)) & 0xfffff002) + 0x1001, &var_7C, 0x78);
    if (eax == 0x0) {
            esi[0x2] = esi[0x2] & eax;
            eax = sub_47ad69();
    }
    else {
            eax = sub_48fc86(*esi, &var_7C);
            esp = (esp - 0x8) + 0x8;
            if (eax == 0x0) {
                    if (esi[0x4] == eax) {
                            esp = esp - 0x4;
                            decomp_var_78 = edi;
                            esp = (esp - 0x4) + 0x8;
                            if (sub_48bdb2(decomp_var_78, decomp_var_74) != 0x0) {
                                    esi[0x2] = esi[0x2] | 0x4;
                                    esi[0x6] = edi;
                                    esi[0x7] = edi;
                            }
                    }
                    else {
                            esi[0x2] = esi[0x2] | 0x4;
                            esi[0x6] = edi;
                            esi[0x7] = edi;
                    }
                    eax = sub_47ad69();
            }
            else {
                    if (esi[0x4] == 0x0) {
                            if (esi[0x3] != 0x0) {
                                    decomp_var_78 = &var_7C;
                                    eax = sub_48fc86(*esi, decomp_var_78);
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_78 = edi;
                                            esp = (esp - 0x4) + 0x8;
                                            if (sub_48bdb2(decomp_var_78, decomp_var_74) != 0x0) {
                                                    esi[0x2] = esi[0x2] | 0x4;
                                                    esi[0x6] = edi;
                                                    esi[0x7] = edi;
                                            }
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            eax = sub_47ad69();
                    }
            }
    }
    return eax;
}
