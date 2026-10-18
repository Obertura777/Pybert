// sub_48f7c8 @ 0x48f7c8
// hopper name: sub_48f7c8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f7c8() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_c = ebx;
    decomp_var_10 = esi;
    esp = esp - 0xc;
    var_14 = edi;
    if (*dword_bc6f70 == 0x0) {
            esp = esp - 0x10;
            if (GetLocaleInfoW(0x0, 0x1, 0x0, 0x0) != 0x0) {
                    *dword_bc6f70 = 0x1;
                    esi = 0x0;
                    if (arg_14 == 0x0) {
                            arg_14 = *(*arg_0 + 0x4);
                    }
                    ebx = GetLocaleInfoW;
                    esp = esp - 0x10;
                    ecx = GetLocaleInfoW(arg_4, arg_8, esi, esi);
                    bool_43 = ecx <= esi;
                    var_8 = ecx;
                    if (ecx == esi) {
                            &var_14 = &var_14;
                            eax = sub_47ad69();
                    }
                    else {
                            if (!bool_43) {
                                    esp = (esp - 0x4) + 0x4;
                                    if (0xffffffe0 / ecx >= 0x2) {
                                            eax = ecx + ecx + 0x8;
                                            if (eax <= 0x400) {
                                                    sub_47ceb0(var_14);
                                                    edi = &var_14;
                                                    if (edi != esi) {
                                                            *edi = 0xcccc;
                                                            edi = edi + 0x8;
                                                            if (edi != esi) {
                                                                    esp = esp - 0x10;
                                                                    if ((ebx)(arg_4, arg_8, edi, var_8) != 0x0) {
                                                                            esi = 0x0;
                                                                            decomp_var_18 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = 0x0;
                                                                            if (arg_10 == 0x0) {
                                                                                    decomp_var_20 = esi;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_24 = esi;
                                                                            }
                                                                            else {
                                                                                    decomp_var_20 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_24 = arg_c;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            esi = WideCharToMultiByte(arg_14, esi, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                    }
                                                                    sub_482993(edi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                                    else {
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    eax = sub_47c836();
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax != esi) {
                                                            *eax = 0xdddd;
                                                            eax = eax + 0x8;
                                                    }
                                                    edi = eax;
                                                    if (edi != esi) {
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoW(arg_4, arg_8, edi, var_8) != 0x0) {
                                                                    decomp_var_18 = esi;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_1c = esi;
                                                                    if (arg_10 == esi) {
                                                                            esi = 0x0;
                                                                            decomp_var_20 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_24 = 0x0;
                                                                    }
                                                                    else {
                                                                            decomp_var_20 = arg_10;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_24 = arg_c;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    esi = WideCharToMultiByte(arg_14, esi, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                            }
                                                            sub_482993(edi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_14 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            esi = 0x0;
                                            if (0x0 != 0x0) {
                                                    edi = 0x0;
                                                    esp = esp - 0x10;
                                                    if ((ebx)(arg_4, arg_8, 0x0, var_8) != 0x0) {
                                                            decomp_var_18 = esi;
                                                            esp = esp - 0x8;
                                                            decomp_var_1c = esi;
                                                            if (arg_10 == esi) {
                                                                    decomp_var_20 = esi;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_24 = esi;
                                                            }
                                                            else {
                                                                    decomp_var_20 = arg_10;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_24 = arg_c;
                                                            }
                                                            esp = esp - 0x10;
                                                            esi = WideCharToMultiByte(arg_14, esi, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                    }
                                                    sub_482993(0x0);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &var_14 = &var_14;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    if (0x0 != esi) {
                                            esp = esp - 0x10;
                                            if ((ebx)(arg_4, arg_8, 0x0, var_8) != 0x0) {
                                                    decomp_var_18 = esi;
                                                    esp = esp - 0x8;
                                                    decomp_var_1c = esi;
                                                    if (arg_10 == esi) {
                                                            decomp_var_20 = esi;
                                                            esp = esp - 0x8;
                                                            decomp_var_24 = esi;
                                                    }
                                                    else {
                                                            decomp_var_20 = arg_10;
                                                            esp = esp - 0x8;
                                                            decomp_var_24 = arg_c;
                                                    }
                                                    esp = esp - 0x10;
                                                    esi = WideCharToMultiByte(arg_14, esi, 0x0, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                            }
                                            sub_482993(0x0);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    &var_14 = &var_14;
                                    eax = sub_47ad69();
                            }
                    }
            }
            else {
                    if (GetLastError() == 0x78) {
                            eax = 0x2;
                            esp = (esp - 0x4) + 0x4;
                            *dword_bc6f70 = 0x2;
                    }
                    else {
                            eax = *dword_bc6f70;
                    }
                    switch (eax) {
                        case 2:
                            esp = esp - 0x10;
                            GetLocaleInfoA(arg_4, arg_8, arg_c, arg_10);
                            &var_14 = &var_14;
                            eax = sub_47ad69();
                            break;
                        case 0:
                            esp = esp - 0x10;
                            GetLocaleInfoA(arg_4, arg_8, arg_c, arg_10);
                            &var_14 = &var_14;
                            eax = sub_47ad69();
                            break;
                        default:
                            if (eax == 0x1) {
                                    if (arg_14 == 0x0) {
                                            arg_14 = *(*arg_0 + 0x4);
                                    }
                                    esp = esp - 0x10;
                                    ecx = GetLocaleInfoW(arg_4, arg_8, 0x0, 0x0);
                                    bool_40 = ecx <= 0x0;
                                    var_8 = ecx;
                                    if (ecx == 0x0) {
                                            &var_14 = &var_14;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (!bool_40) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (0xffffffe0 / ecx >= 0x2) {
                                                            eax = ecx + ecx + 0x8;
                                                            if (eax <= 0x400) {
                                                                    sub_47ceb0(var_14);
                                                                    edi = &var_14;
                                                                    if (edi != 0x0) {
                                                                            *edi = 0xcccc;
                                                                            edi = edi + 0x8;
                                                                            esi = 0x0;
                                                                            if (edi != 0x0) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoW(arg_4, arg_8, edi, var_8) != 0x0) {
                                                                                            decomp_var_18 = esi;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = esi;
                                                                                            if (arg_10 == esi) {
                                                                                                    decomp_var_20 = 0x0;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_24 = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_20 = arg_10;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_24 = arg_c;
                                                                                            }
                                                                                            esp = esp - 0x10;
                                                                                            esi = WideCharToMultiByte(arg_14, 0x0, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                                    }
                                                                                    sub_482993(edi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            &var_14 = &var_14;
                                                                            eax = sub_47ad69();
                                                                    }
                                                                    else {
                                                                            &var_14 = &var_14;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47c836();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax != 0x0) {
                                                                            *eax = 0xdddd;
                                                                            eax = eax + 0x8;
                                                                    }
                                                                    edi = eax;
                                                                    esi = 0x0;
                                                                    if (edi != 0x0) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoW(arg_4, arg_8, edi, var_8) != 0x0) {
                                                                                    decomp_var_18 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = 0x0;
                                                                                    if (arg_10 == 0x0) {
                                                                                            decomp_var_20 = 0x0;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_24 = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_20 = arg_10;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_24 = arg_c;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    esi = WideCharToMultiByte(arg_14, 0x0, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                            }
                                                                            sub_482993(edi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_14 = &var_14;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            esi = 0x0;
                                                            if (0x0 != 0x0) {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoW(arg_4, arg_8, 0x0, var_8) != 0x0) {
                                                                            decomp_var_18 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = 0x0;
                                                                            if (arg_10 == 0x0) {
                                                                                    decomp_var_20 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_24 = 0x0;
                                                                            }
                                                                            else {
                                                                                    decomp_var_20 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_24 = arg_c;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            esi = WideCharToMultiByte(arg_14, 0x0, 0x0, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                    }
                                                                    sub_482993(0x0);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    esi = 0x0;
                                                    if (0x0 != 0x0) {
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoW(arg_4, arg_8, 0x0, var_8) != 0x0) {
                                                                    esi = 0x0;
                                                                    decomp_var_18 = 0x0;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_1c = 0x0;
                                                                    if (arg_10 == 0x0) {
                                                                            esi = 0x0;
                                                                            decomp_var_20 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_24 = 0x0;
                                                                    }
                                                                    else {
                                                                            decomp_var_20 = arg_10;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_24 = arg_c;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    esi = WideCharToMultiByte(arg_14, esi, 0x0, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                            }
                                                            sub_482993(0x0);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_14 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                            else {
                                    &var_14 = &var_14;
                                    eax = sub_47ad69();
                            }
                            break;
                    }
            }
    }
    else {
            if (*dword_bc6f70 != 0x2) {
                    eax = *dword_bc6f70;
                    if (*dword_bc6f70 != 0x0) {
                            if (eax == 0x1) {
                                    if (arg_14 == 0x0) {
                                            arg_14 = *(*arg_0 + 0x4);
                                    }
                                    esi = 0x0;
                                    esp = esp - 0x10;
                                    ecx = GetLocaleInfoW(arg_4, arg_8, 0x0, 0x0);
                                    bool_2 = ecx <= 0x0;
                                    var_8 = ecx;
                                    if (ecx == 0x0) {
                                            &var_14 = &var_14;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (!bool_2) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (0xffffffe0 / ecx >= 0x2) {
                                                            eax = ecx + ecx + 0x8;
                                                            if (eax <= 0x400) {
                                                                    sub_47ceb0(var_14);
                                                                    edi = &var_14;
                                                                    if (edi != esi) {
                                                                            *edi = 0xcccc;
                                                                            edi = edi + 0x8;
                                                                            if (edi != esi) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoW(arg_4, arg_8, edi, var_8) != 0x0) {
                                                                                            decomp_var_18 = esi;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = esi;
                                                                                            if (arg_10 == esi) {
                                                                                                    decomp_var_20 = esi;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_24 = esi;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_20 = arg_10;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_24 = arg_c;
                                                                                            }
                                                                                            esp = esp - 0x10;
                                                                                            esi = WideCharToMultiByte(arg_14, esi, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                                    }
                                                                                    sub_482993(edi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            &var_14 = &var_14;
                                                                            eax = sub_47ad69();
                                                                    }
                                                                    else {
                                                                            &var_14 = &var_14;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47c836();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax != esi) {
                                                                            *eax = 0xdddd;
                                                                            eax = eax + 0x8;
                                                                    }
                                                                    edi = eax;
                                                                    if (edi != esi) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoW(arg_4, arg_8, edi, var_8) != 0x0) {
                                                                                    decomp_var_18 = esi;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = esi;
                                                                                    if (arg_10 == esi) {
                                                                                            decomp_var_20 = esi;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_24 = esi;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_20 = arg_10;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_24 = arg_c;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    esi = WideCharToMultiByte(arg_14, esi, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                            }
                                                                            sub_482993(edi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_14 = &var_14;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (0x0 != esi) {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoW(arg_4, arg_8, 0x0, var_8) != 0x0) {
                                                                            decomp_var_18 = esi;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = esi;
                                                                            if (arg_10 == esi) {
                                                                                    decomp_var_20 = esi;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_24 = esi;
                                                                            }
                                                                            else {
                                                                                    decomp_var_20 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_24 = arg_c;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            esi = WideCharToMultiByte(arg_14, esi, 0x0, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                                    }
                                                                    sub_482993(0x0);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    esi = 0x0;
                                                    if (0x0 != 0x0) {
                                                            edi = 0x0;
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoW(arg_4, arg_8, 0x0, var_8) != 0x0) {
                                                                    decomp_var_18 = esi;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_1c = esi;
                                                                    if (arg_10 == esi) {
                                                                            decomp_var_20 = esi;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_24 = esi;
                                                                    }
                                                                    else {
                                                                            decomp_var_20 = arg_10;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_24 = arg_c;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    esi = WideCharToMultiByte(arg_14, esi, edi, 0xffffffff, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18);
                                                            }
                                                            sub_482993(edi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_14 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                            else {
                                    &var_14 = &var_14;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            GetLocaleInfoA(arg_4, arg_8, arg_c, arg_10);
                            &var_14 = &var_14;
                            eax = sub_47ad69();
                    }
            }
            else {
                    esp = esp - 0x10;
                    GetLocaleInfoA(arg_4, arg_8, arg_c, arg_10);
                    &var_14 = &var_14;
                    eax = sub_47ad69();
            }
    }
    return eax;
}
