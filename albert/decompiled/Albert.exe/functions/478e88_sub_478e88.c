// sub_478e88 @ 0x478e88
// hopper name: sub_478e88
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478e88() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x4;
    edi = ecx;
    var_48 = arg_0;
    if (edi[0x1] == 0x0) {
            eax = sub_47ad69();
    }
    else {
            ebx = GlobalLock(*edi);
            bool_3 = ebx[0x1] == 0xffff;
            bool_2 = ebx[0x1] != 0xffff;
            bool_1 = ebx[0x1] == 0xffff;
            var_50 = ebx;
            var_54 = bool_3 ? 0x1 : 0x0;
            var_4C = sub_478cea(ebx);
            esp = (esp - 0x10) + 0x4;
            esi = (bool_2 ? 0x1 : 0x0) + (bool_2 ? 0x1 : 0x0) + (bool_2 ? 0x1 : 0x0) + (bool_2 ? 0x1 : 0x0) + 0x2;
            if (!bool_1) {
                    ebx[0x3] = ebx[0x3] | 0x40;
            }
            else {
                    *ebx = *ebx | 0x40;
            }
            esp = esp - 0x4;
            if (lstrlenA(var_48) < 0x20) {
                    esp = esp - 0x18;
                    eax = MultiByteToWideChar(0x0, 0x0, var_48, 0xffffffff, &var_44, 0x20);
                    edx = esi + eax * 0x2;
                    var_48 = edx;
                    if (edx >= esi) {
                            var_58 = ebx;
                            eax = sub_478d15(var_58);
                            esp = (esp - 0x4) + 0x4;
                            ecx = 0x0;
                            ebx = eax;
                            if (var_4C != 0x0) {
                                    var_58 = ebx + esi;
                                    eax = sub_47d60b(var_58);
                                    edx = var_48;
                                    esp = (esp - 0x4) + 0x4;
                                    ecx = esi + eax * 0x2 + 0x2;
                            }
                            esi = ebx + edx + 0x3;
                            edx = var_50;
                            eax = ecx + ebx + 0x3 & 0xfffffffc;
                            esi = esi & 0xfffffffc;
                            var_4C = eax;
                            if (var_54 != 0x0) {
                                    edx = edx[0x8] & 0xffff;
                            }
                            else {
                                    edx = edx[0x4] & 0xffff;
                            }
                            if (var_48 != ecx) {
                                    if (edx > 0x0) {
                                            edx = edi[0x1];
                                            ecx = (edx - eax) + var_50;
                                            if (ecx > edx) {
                                                    esp = esp + 0x8;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    var_58 = ecx;
                                                    sub_478599(esi, var_58, eax, ecx);
                                                    esp = (esp - 0x10) + 0x10;
                                                    *(int16_t *)ebx = arg_4;
                                                    var_54 = &var_44;
                                                    sub_478599(ebx + var_58, var_48 - var_58, var_54, var_48 - var_58);
                                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                                    var_50 = *edi;
                                                    edi[0x1] = edi[0x1] + (esi - var_4C);
                                                    GlobalUnlock(var_50);
                                                    edi[0x2] = edi[0x2] & 0x0;
                                                    esp = esp + 0x8;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            *(int16_t *)ebx = arg_4;
                                            var_54 = &var_44;
                                            sub_478599(ebx + var_58, var_48 - var_58, var_54, var_48 - var_58);
                                            esp = (esp - 0x10) + 0x10 - 0x4;
                                            var_50 = *edi;
                                            edi[0x1] = edi[0x1] + (esi - var_4C);
                                            GlobalUnlock(var_50);
                                            edi[0x2] = edi[0x2] & 0x0;
                                            esp = esp + 0x8;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    *(int16_t *)ebx = arg_4;
                                    var_54 = &var_44;
                                    sub_478599(ebx + var_58, var_48 - var_58, var_54, var_48 - var_58);
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    var_50 = *edi;
                                    edi[0x1] = edi[0x1] + (esi - var_4C);
                                    GlobalUnlock(var_50);
                                    edi[0x2] = edi[0x2] & 0x0;
                                    esp = esp + 0x8;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            esp = esp + 0x8;
                            eax = sub_47ad69();
                    }
            }
            else {
                    esp = esp + 0x8;
                    eax = sub_47ad69();
            }
    }
    return eax;
}
