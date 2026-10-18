// sub_48f652 @ 0x48f652
// hopper name: sub_48f652
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f652() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_c = ebx;
    decomp_var_10 = esi;
    esp = esp - 0xc;
    var_14 = edi;
    if (*dword_bc6f6c == 0x0) {
            esp = esp - 0x10;
            if (GetLocaleInfoW(0x0, 0x1, 0x0, 0x0) != 0x0) {
                    *dword_bc6f6c = 0x1;
                    esp = esp - 0x10;
                    GetLocaleInfoW(arg_4, arg_8, arg_c, arg_10);
                    &var_14 = &var_14;
                    eax = sub_47ad69();
            }
            else {
                    if (GetLastError() == 0x78) {
                            eax = 0x2;
                            esp = (esp - 0x4) + 0x4;
                            *dword_bc6f6c = 0x2;
                    }
                    else {
                            eax = *dword_bc6f6c;
                    }
                    if (eax == 0x1) {
                            esp = esp - 0x10;
                            GetLocaleInfoW(arg_4, arg_8, arg_c, arg_10);
                            &var_14 = &var_14;
                            eax = sub_47ad69();
                    }
                    else {
                            if (eax != 0x2) {
                                    edi = 0x0;
                                    if (eax == 0x0) {
                                            var_8 = edi;
                                            if (arg_14 == edi) {
                                                    arg_14 = *(*arg_0 + 0x4);
                                            }
                                            esp = esp - 0x10;
                                            ebx = GetLocaleInfoA(arg_4, arg_8, 0x0, 0x0);
                                            bool_71 = ebx <= 0x0;
                                            if (ebx == 0x0) {
                                                    &var_14 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    if (!bool_71) {
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (0xffffffe0 / ebx >= 0x1) {
                                                                    eax = ebx + 0x8;
                                                                    if (eax <= 0x400) {
                                                                            sub_47ceb0(var_14);
                                                                            esi = &var_14;
                                                                            if (esi != 0x0) {
                                                                                    *esi = 0xcccc;
                                                                                    esi = esi + 0x8;
                                                                                    if (esi != 0x0) {
                                                                                            esp = esp - 0x10;
                                                                                            if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                                    if (arg_10 == 0x0) {
                                                                                                            decomp_var_18 = 0x0;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_1c = 0x0;
                                                                                                    }
                                                                                                    else {
                                                                                                            decomp_var_18 = arg_10;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_1c = arg_c;
                                                                                                    }
                                                                                                    esp = esp - 0x10;
                                                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                                            }
                                                                                            sub_482993(esi);
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
                                                                            esi = eax;
                                                                            if (esi != 0x0) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                            if (arg_10 == 0x0) {
                                                                                                    decomp_var_18 = 0x0;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_1c = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_18 = arg_10;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_1c = arg_c;
                                                                                            }
                                                                                            esp = esp - 0x10;
                                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                                    }
                                                                                    sub_482993(esi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            &var_14 = &var_14;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    if (0x0 != 0x0) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                                    if (arg_10 == 0x0) {
                                                                                            decomp_var_18 = 0x0;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_18 = arg_10;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = arg_c;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                            }
                                                                            sub_482993(0x0);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_14 = &var_14;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (0x0 != 0x0) {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                            if (arg_10 == 0x0) {
                                                                                    decomp_var_18 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = 0x0;
                                                                            }
                                                                            else {
                                                                                    decomp_var_18 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = arg_c;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
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
                            }
                            else {
                                    edi = 0x0;
                                    var_8 = 0x0;
                                    if (arg_14 == 0x0) {
                                            arg_14 = *(*arg_0 + 0x4);
                                    }
                                    esp = esp - 0x10;
                                    ebx = GetLocaleInfoA(arg_4, arg_8, edi, edi);
                                    bool_61 = ebx <= 0x0;
                                    if (ebx == 0x0) {
                                            &var_14 = &var_14;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (!bool_61) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (0xffffffe0 / ebx >= 0x1) {
                                                            eax = ebx + 0x8;
                                                            if (eax <= 0x400) {
                                                                    sub_47ceb0(var_14);
                                                                    esi = &var_14;
                                                                    if (esi != 0x0) {
                                                                            *esi = 0xcccc;
                                                                            esi = esi + 0x8;
                                                                            if (esi != 0x0) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                            if (arg_10 == 0x0) {
                                                                                                    decomp_var_18 = 0x0;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_1c = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_18 = arg_10;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_1c = arg_c;
                                                                                            }
                                                                                            esp = esp - 0x10;
                                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                                    }
                                                                                    sub_482993(esi);
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
                                                                    esi = eax;
                                                                    if (esi != 0x0) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                    if (arg_10 == 0x0) {
                                                                                            decomp_var_18 = 0x0;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_18 = arg_10;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = arg_c;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                            }
                                                                            sub_482993(esi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_14 = &var_14;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (0x0 != 0x0) {
                                                                    esi = 0x0;
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                            if (arg_10 == 0x0) {
                                                                                    decomp_var_18 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = 0x0;
                                                                            }
                                                                            else {
                                                                                    decomp_var_18 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = arg_c;
                                                                            }
                                                                            esi = 0x0;
                                                                            esp = esp - 0x10;
                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                    }
                                                                    sub_482993(esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    if (0x0 != 0x0) {
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                    if (arg_10 == 0x0) {
                                                                            decomp_var_18 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = 0x0;
                                                                    }
                                                                    else {
                                                                            decomp_var_18 = arg_10;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = arg_c;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                            }
                                                            sub_482993(0x0);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_14 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (*dword_bc6f6c == 0x1) {
                    esp = esp - 0x10;
                    GetLocaleInfoW(arg_4, arg_8, arg_c, arg_10);
                    &var_14 = &var_14;
                    eax = sub_47ad69();
            }
            else {
                    eax = *dword_bc6f6c;
                    if (*dword_bc6f6c != 0x2) {
                            if (eax == 0x0) {
                                    edi = 0x0;
                                    var_8 = 0x0;
                                    if (arg_14 == 0x0) {
                                            arg_14 = *(*arg_0 + 0x4);
                                    }
                                    esp = esp - 0x10;
                                    ebx = GetLocaleInfoA(arg_4, arg_8, edi, edi);
                                    bool_18 = ebx <= 0x0;
                                    if (ebx == 0x0) {
                                            &var_14 = &var_14;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (!bool_18) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (0xffffffe0 / ebx >= 0x1) {
                                                            eax = ebx + 0x8;
                                                            if (eax <= 0x400) {
                                                                    sub_47ceb0(var_14);
                                                                    esi = &var_14;
                                                                    if (esi != 0x0) {
                                                                            *esi = 0xcccc;
                                                                            esi = esi + 0x8;
                                                                            if (esi != 0x0) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                            if (arg_10 == 0x0) {
                                                                                                    decomp_var_18 = 0x0;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_1c = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_18 = arg_10;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_1c = arg_c;
                                                                                            }
                                                                                            esp = esp - 0x10;
                                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                                    }
                                                                                    sub_482993(esi);
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
                                                                    esi = eax;
                                                                    if (esi != 0x0) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                    if (arg_10 == 0x0) {
                                                                                            decomp_var_18 = 0x0;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_18 = arg_10;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = arg_c;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                            }
                                                                            sub_482993(esi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_14 = &var_14;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (0x0 != 0x0) {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                            if (arg_10 == 0x0) {
                                                                                    decomp_var_18 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = 0x0;
                                                                            }
                                                                            else {
                                                                                    decomp_var_18 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = arg_c;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                    }
                                                                    sub_482993(0x0);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    if (0x0 != 0x0) {
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                    if (arg_10 == 0x0) {
                                                                            decomp_var_18 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = 0x0;
                                                                    }
                                                                    else {
                                                                            decomp_var_18 = arg_10;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = arg_c;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
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
                    }
                    else {
                            var_8 = 0x0;
                            if (arg_14 == 0x0) {
                                    arg_14 = *(*arg_0 + 0x4);
                            }
                            esp = esp - 0x10;
                            ebx = GetLocaleInfoA(arg_4, arg_8, 0x0, 0x0);
                            bool_3 = ebx <= 0x0;
                            if (ebx == 0x0) {
                                    &var_14 = &var_14;
                                    eax = sub_47ad69();
                            }
                            else {
                                    if (!bool_3) {
                                            esp = (esp - 0x4) + 0x4;
                                            if (0xffffffe0 / ebx >= 0x1) {
                                                    eax = ebx + 0x8;
                                                    if (eax <= 0x400) {
                                                            sub_47ceb0(var_14);
                                                            esi = &var_14;
                                                            if (esi != 0x0) {
                                                                    *esi = 0xcccc;
                                                                    esi = esi + 0x8;
                                                                    if (esi != 0x0) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                                    if (arg_10 == 0x0) {
                                                                                            decomp_var_18 = 0x0;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_18 = arg_10;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_1c = arg_c;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                            }
                                                                            sub_482993(esi);
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
                                                            esi = eax;
                                                            if (esi != 0x0) {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(arg_4, arg_8, esi, ebx) != 0x0) {
                                                                            if (arg_10 == 0x0) {
                                                                                    decomp_var_18 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = 0x0;
                                                                            }
                                                                            else {
                                                                                    decomp_var_18 = arg_10;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_1c = arg_c;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, esi, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                                    }
                                                                    sub_482993(esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_14 = &var_14;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    if (0x0 != 0x0) {
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                                    if (arg_10 == 0x0) {
                                                                            decomp_var_18 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = 0x0;
                                                                    }
                                                                    else {
                                                                            decomp_var_18 = arg_10;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_1c = arg_c;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                            }
                                                            sub_482993(0x0);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_14 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            if (0x0 != 0x0) {
                                                    esp = esp - 0x10;
                                                    if (GetLocaleInfoA(arg_4, arg_8, 0x0, ebx) != 0x0) {
                                                            if (arg_10 == 0x0) {
                                                                    decomp_var_18 = 0x0;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_1c = 0x0;
                                                            }
                                                            else {
                                                                    decomp_var_18 = arg_10;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_1c = arg_c;
                                                            }
                                                            esp = esp - 0x10;
                                                            var_8 = MultiByteToWideChar(arg_14, 0x1, 0x0, 0xffffffff, decomp_var_1c, decomp_var_18);
                                                    }
                                                    sub_482993(0x0);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &var_14 = &var_14;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
            }
    }
    return eax;
}
