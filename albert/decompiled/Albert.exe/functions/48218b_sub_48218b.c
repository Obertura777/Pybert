// sub_48218b @ 0x48218b
// hopper name: sub_48218b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48218b() {
    ebp = &var_64;
    arg_58 = *dword_4c8db8 ^ ebp;
    decomp_var_bc = ebx;
    decomp_var_c0 = esi;
    esi = arg_64;
    esp = esp - 0xc0;
    decomp_var_c4 = edi;
    edi = arg_70;
    decomp_var_3c = arg_68;
    decomp_var_44 = edi;
    decomp_var_40 = arg_74;
    eax = sub_480086();
    decomp_var_4c = eax + 0xc4;
    ebx = eax + 0xbc;
    decomp_var_48 = eax + 0xc8;
    decomp_var_38 = eax + 0x14b;
    if (esi != 0x0) {
            if (decomp_var_3c != 0x0) {
                    if (arg_6c != 0x0) {
                            if (*(int8_t *)esi == 0x43) {
                                    if (esi[0x1] == 0x0) {
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_47db5e(decomp_var_3c, arg_6c, 0x4b1d28) != 0x0) {
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            if (edi != 0x0) {
                                                    *(int16_t *)edi = 0x0;
                                                    edi[0x1] = 0x0;
                                                    edi[0x2] = 0x0;
                                            }
                                            esi = 0x0;
                                            eax = decomp_var_40;
                                            if (eax != 0x0) {
                                                    *eax = esi;
                                            }
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            eax = sub_47d630(esi);
                                            esp = (esp - 0x4) + 0x4;
                                            decomp_var_50 = eax;
                                            if (eax < 0x83) {
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_47fd80(decomp_var_38, esi) != 0x0) {
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_47fd80(decomp_var_48, esi) != 0x0) {
                                                                    decomp_var_54 = decomp_var_54 & 0x0;
                                                                    eax = sub_481e86(&decomp_var_34, esi);
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (eax == 0x0) {
                                                                            eax = sub_48c154(&decomp_var_34, ebx, &decomp_var_34);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (eax != 0x0) {
                                                                                    *decomp_var_4c = ebx[0x2] & 0xffff;
                                                                                    sub_481faf(decomp_var_38, 0x83, &decomp_var_34);
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (*(int8_t *)esi != 0x0) {
                                                                                            eax = decomp_var_50;
                                                                                            if (eax >= 0x83) {
                                                                                                    eax = decomp_var_54;
                                                                                                    esi = 0x4b1973;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = decomp_var_54;
                                                                                            esi = 0x4b1973;
                                                                                    }
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    if (sub_47f4a4(decomp_var_48, 0x83, esi, eax + 0x1) != 0x0) {
                                                                                            sub_47a828();
                                                                                            esp = (esp - 0x14) + 0x14;
                                                                                    }
                                                                                    if (decomp_var_44 != 0x0) {
                                                                                            sub_47c000(decomp_var_44, ebx, 0x6);
                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                    }
                                                                                    esi = 0x0;
                                                                                    if (decomp_var_40 != 0x0) {
                                                                                            sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                    }
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                                            sub_47a828();
                                                                                            esp = (esp - 0x14) + 0x14;
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
                                                                    if (decomp_var_44 != 0x0) {
                                                                            sub_47c000(decomp_var_44, ebx, 0x6);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                    }
                                                                    esi = 0x0;
                                                                    if (decomp_var_40 != 0x0) {
                                                                            sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                    }
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                            sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (decomp_var_44 != 0x0) {
                                                                    sub_47c000(decomp_var_44, ebx, 0x6);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                            if (decomp_var_40 != 0x0) {
                                                                    sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    decomp_var_54 = decomp_var_54 & 0x0;
                                                    eax = sub_481e86(&decomp_var_34, esi);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax == 0x0) {
                                                            eax = sub_48c154(&decomp_var_34, ebx, &decomp_var_34);
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (eax != 0x0) {
                                                                    *decomp_var_4c = ebx[0x2] & 0xffff;
                                                                    sub_481faf(decomp_var_38, 0x83, &decomp_var_34);
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (*(int8_t *)esi != 0x0) {
                                                                            eax = decomp_var_50;
                                                                            if (eax >= 0x83) {
                                                                                    eax = decomp_var_54;
                                                                                    esi = 0x4b1973;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = decomp_var_54;
                                                                            esi = 0x4b1973;
                                                                    }
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    if (sub_47f4a4(decomp_var_48, 0x83, esi, eax + 0x1) != 0x0) {
                                                                            sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    if (decomp_var_44 != 0x0) {
                                                                            sub_47c000(decomp_var_44, ebx, 0x6);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                    }
                                                                    if (decomp_var_40 != 0x0) {
                                                                            sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                    }
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                            sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
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
                                    }
                            }
                            else {
                                    eax = sub_47d630(esi);
                                    esp = (esp - 0x4) + 0x4;
                                    decomp_var_50 = eax;
                                    if (eax < 0x83) {
                                            esp = (esp - 0x8) + 0x8;
                                            if (sub_47fd80(decomp_var_38, esi) != 0x0) {
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_47fd80(decomp_var_48, esi) != 0x0) {
                                                            decomp_var_54 = decomp_var_54 & 0x0;
                                                            eax = sub_481e86(&decomp_var_34, esi);
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax == 0x0) {
                                                                    eax = sub_48c154(&decomp_var_34, ebx, &decomp_var_34);
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (eax != 0x0) {
                                                                            *decomp_var_4c = ebx[0x2] & 0xffff;
                                                                            sub_481faf(decomp_var_38, 0x83, &decomp_var_34);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (*(int8_t *)esi != 0x0) {
                                                                                    eax = decomp_var_50;
                                                                                    if (eax >= 0x83) {
                                                                                            eax = decomp_var_54;
                                                                                            esi = 0x4b1973;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = decomp_var_54;
                                                                                    esi = 0x4b1973;
                                                                            }
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            if (sub_47f4a4(decomp_var_48, 0x83, esi, eax + 0x1) != 0x0) {
                                                                                    sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                            }
                                                                            if (decomp_var_44 != 0x0) {
                                                                                    sub_47c000(decomp_var_44, ebx, 0x6);
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                            }
                                                                            if (decomp_var_40 != 0x0) {
                                                                                    sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                            }
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                                    sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
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
                                                            if (decomp_var_44 != 0x0) {
                                                                    sub_47c000(decomp_var_44, ebx, 0x6);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                            if (decomp_var_40 != 0x0) {
                                                                    sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    if (decomp_var_44 != 0x0) {
                                                            sub_47c000(decomp_var_44, ebx, 0x6);
                                                            esp = (esp - 0xc) + 0xc;
                                                    }
                                                    if (decomp_var_40 != 0x0) {
                                                            sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                            esp = (esp - 0xc) + 0xc;
                                                    }
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                            sub_47a828();
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            decomp_var_54 = decomp_var_54 & 0x0;
                                            eax = sub_481e86(&decomp_var_34, esi);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax == 0x0) {
                                                    eax = sub_48c154(&decomp_var_34, ebx, &decomp_var_34);
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (eax != 0x0) {
                                                            *decomp_var_4c = ebx[0x2] & 0xffff;
                                                            sub_481faf(decomp_var_38, 0x83, &decomp_var_34);
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (*(int8_t *)esi != 0x0) {
                                                                    eax = decomp_var_50;
                                                                    if (eax >= 0x83) {
                                                                            eax = decomp_var_54;
                                                                            esi = 0x4b1973;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = decomp_var_54;
                                                                    esi = 0x4b1973;
                                                            }
                                                            esp = (esp - 0x10) + 0x10;
                                                            if (sub_47f4a4(decomp_var_48, 0x83, esi, eax + 0x1) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            if (decomp_var_44 != 0x0) {
                                                                    sub_47c000(decomp_var_44, ebx, 0x6);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                            if (decomp_var_40 != 0x0) {
                                                                    sub_47c000(decomp_var_40, decomp_var_4c, 0x4);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_47db5e(decomp_var_3c, arg_6c, decomp_var_38) != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
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
    else {
            eax = sub_47ad69();
    }
    return eax;
}
