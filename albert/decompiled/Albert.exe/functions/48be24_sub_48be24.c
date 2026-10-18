// sub_48be24 @ 0x48be24
// hopper name: sub_48be24
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48be24() {
    var_4 = *dword_4c8db8 ^ ebp;
    esi = sub_480086() + 0x9c;
    edi = sub_48bccf();
    eax = esi[0x5];
    esp = esp - 0x1c;
    eax = GetLocaleInfoA(edi, (-eax - -eax + CARRY(EFLAGS(cf)) & 0xfffff005) + 0x1002, &var_7C, 0x78);
    if (eax == 0x0) {
            esi[0x2] = esi[0x2] & 0x0;
            eax = sub_47ad69();
    }
    else {
            eax = sub_48fc86(esi[0x1], &var_7C);
            esp = (esp - 0x8) + 0x8;
            if (eax == 0x0) {
                    decomp_var_78 = 0x78;
                    var_7C = &var_7C;
                    eax = esi[0x4];
                    esp = esp - 0x10;
                    if (GetLocaleInfoA(edi, (-eax - -eax + CARRY(EFLAGS(cf)) & 0xfffff002) + 0x1001, var_7C, 0x78) != 0x0) {
                            decomp_var_78 = &var_7C;
                            var_7C = *esi;
                            esp = (esp - 0x8) + 0x8;
                            if (sub_48fc86(var_7C, decomp_var_78) == 0x0) {
                                    esi[0x2] = esi[0x2] | 0x304;
                                    esi[0x6] = edi;
                                    esi[0x7] = edi;
                            }
                            else {
                                    if ((esi[0x8] & 0x2) == 0x0) {
                                            eax = esi[0x3];
                                            if (eax != 0x0) {
                                                    decomp_var_70 = eax;
                                                    decomp_var_74 = &var_7C;
                                                    decomp_var_78 = *esi;
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_48fdc6(decomp_var_78, decomp_var_74, decomp_var_70) == 0x0) {
                                                            decomp_var_70 = *esi;
                                                            esi[0x2] = esi[0x2] | 0x2;
                                                            esi[0x7] = edi;
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_47d630(decomp_var_70) == esi[0x3]) {
                                                                    esi[0x6] = edi;
                                                            }
                                                    }
                                                    else {
                                                            edx = esi[0x2];
                                                            if ((edx & 0x1) == 0x0) {
                                                                    decomp_var_70 = edi;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_48bcb1(decomp_var_70) != 0x0) {
                                                                            esi[0x2] = edx | 0x1;
                                                                            esi[0x7] = edi;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    edx = esi[0x2];
                                                    if ((edx & 0x1) == 0x0) {
                                                            decomp_var_70 = edi;
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_48bcb1(decomp_var_70) != 0x0) {
                                                                    esi[0x2] = edx | 0x1;
                                                                    esi[0x7] = edi;
                                                            }
                                                    }
                                            }
                                    }
                            }
                            if ((esi[0x2] & 0x300) != 0x300) {
                                    decomp_var_70 = &var_7C;
                                    eax = esi[0x4];
                                    decomp_var_74 = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xfffff002) + 0x1001;
                                    esp = esp - 0x10;
                                    decomp_var_78 = edi;
                                    if (GetLocaleInfoA(decomp_var_78, decomp_var_74, decomp_var_70, 0x78) != 0x0) {
                                            decomp_var_70 = *esi;
                                            eax = sub_48fc86(decomp_var_70, &var_7C);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax == 0x0) {
                                                    esi[0x2] = esi[0x2] | 0x200;
                                                    bool_18 = esi[0x4] == 0x0;
                                                    eax = esi[0x2];
                                                    if (!bool_18) {
                                                            esi[0x2] = eax | 0x100;
                                                            if (esi[0x6] == 0x0) {
                                                                    esi[0x6] = edi;
                                                            }
                                                    }
                                                    else {
                                                            ebx = 0x0;
                                                            if (esi[0x3] != 0x0) {
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_47d630(*esi) == esi[0x3]) {
                                                                            esp = esp - 0x4;
                                                                            esp = (esp - 0x4) + 0x8;
                                                                            if (sub_48bdb2(edi, decomp_var_60) != 0x0) {
                                                                                    esi[0x2] = esi[0x2] | 0x100;
                                                                                    if (esi[0x6] == 0x0) {
                                                                                            esi[0x6] = edi;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi[0x2] = esi[0x2] | 0x100;
                                                                            if (esi[0x6] == ebx) {
                                                                                    esi[0x6] = edi;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x2] = esi[0x2] | 0x100;
                                                                    if (esi[0x6] == ebx) {
                                                                            esi[0x6] = edi;
                                                                    }
                                                            }
                                                    }
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    if (esi[0x4] == 0x0) {
                                                            if (esi[0x3] != 0x0) {
                                                                    eax = sub_48fc86(*esi, &var_7C);
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (eax == 0x0) {
                                                                            esp = esp - 0x4;
                                                                            esp = (esp - 0x4) + 0x8;
                                                                            if (sub_48bdb2(edi, decomp_var_60) != 0x0) {
                                                                                    esi[0x2] = esi[0x2] | 0x100;
                                                                                    if (esi[0x6] == 0x0) {
                                                                                            esi[0x6] = edi;
                                                                                    }
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
                                    else {
                                            esi[0x2] = esi[0x2] & 0x0;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            esi[0x2] = esi[0x2] & 0x0;
                            eax = sub_47ad69();
                    }
            }
            else {
                    if ((esi[0x2] & 0x300) != 0x300) {
                            decomp_var_70 = &var_7C;
                            eax = esi[0x4];
                            decomp_var_74 = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xfffff002) + 0x1001;
                            esp = esp - 0x10;
                            decomp_var_78 = edi;
                            if (GetLocaleInfoA(decomp_var_78, decomp_var_74, decomp_var_70, 0x78) != 0x0) {
                                    decomp_var_70 = *esi;
                                    eax = sub_48fc86(decomp_var_70, &var_7C);
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax == 0x0) {
                                            esi[0x2] = esi[0x2] | 0x200;
                                            bool_15 = esi[0x4] == 0x0;
                                            eax = esi[0x2];
                                            if (!bool_15) {
                                                    esi[0x2] = eax | 0x100;
                                                    if (esi[0x6] == 0x0) {
                                                            esi[0x6] = edi;
                                                    }
                                            }
                                            else {
                                                    if (esi[0x3] != 0x0) {
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_47d630(*esi) == esi[0x3]) {
                                                                    esp = esp - 0x4;
                                                                    esp = (esp - 0x4) + 0x8;
                                                                    if (sub_48bdb2(edi, decomp_var_60) != 0x0) {
                                                                            esi[0x2] = esi[0x2] | 0x100;
                                                                            if (esi[0x6] == 0x0) {
                                                                                    esi[0x6] = edi;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x2] = esi[0x2] | 0x100;
                                                                    if (esi[0x6] == 0x0) {
                                                                            esi[0x6] = edi;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi[0x2] = esi[0x2] | 0x100;
                                                            if (esi[0x6] == 0x0) {
                                                                    esi[0x6] = edi;
                                                            }
                                                    }
                                            }
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (esi[0x4] == 0x0) {
                                                    if (esi[0x3] != 0x0) {
                                                            eax = sub_48fc86(*esi, &var_7C);
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax == 0x0) {
                                                                    esp = esp - 0x4;
                                                                    esp = (esp - 0x4) + 0x8;
                                                                    if (sub_48bdb2(edi, decomp_var_60) != 0x0) {
                                                                            esi[0x2] = esi[0x2] | 0x100;
                                                                            if (esi[0x6] == 0x0) {
                                                                                    esi[0x6] = edi;
                                                                            }
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
                            else {
                                    esi[0x2] = esi[0x2] & 0x0;
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
