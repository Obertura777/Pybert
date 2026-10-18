// sub_48aa67 @ 0x48aa67
// hopper name: sub_48aa67
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48aa67() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0xc;
    var_14 = edi;
    edi = ecx;
    if (*dword_bc6f44 == 0x0) {
            decomp_var_18 = &var_8;
            decomp_var_1c = 0x1;
            esp = esp - 0x10;
            if (GetStringTypeW(0x1, 0x4b3b5c, 0x1, decomp_var_18) != 0x0) {
                    *dword_bc6f44 = 0x1;
                    var_8 = 0x0;
                    if (arg_10 == 0x0) {
                            arg_10 = *(*edi + 0x4);
                    }
                    ebx = 0x0;
                    decomp_var_18 = 0x0;
                    decomp_var_1c = 0x0;
                    esp = esp - 0x18;
                    edi = MultiByteToWideChar(arg_10, (arg_18 != 0x0 ? 0x1 : 0x0) * 0x8 + 0x1, arg_4, arg_8, 0x0, 0x0);
                    bool_54 = edi <= 0x0;
                    if (arg_18 != 0x0) {
                            if (!bool_54 && edi <= 0x7ffffff0) {
                                    eax = edi + edi + 0x8;
                                    if (eax <= 0x400) {
                                            sub_47ceb0(var_14);
                                            eax = &var_14;
                                            if (eax != 0x0) {
                                                    *eax = 0xcccc;
                                                    eax = eax + 0x8;
                                            }
                                    }
                                    else {
                                            decomp_var_18 = eax;
                                            eax = sub_47c836();
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax != 0x0) {
                                                    *eax = 0xdddd;
                                                    eax = eax + 0x8;
                                            }
                                    }
                                    ebx = eax;
                            }
                            if (ebx != 0x0) {
                                    sub_47ba40(ebx, 0x0, edi + edi);
                                    decomp_var_18 = edi;
                                    decomp_var_1c = ebx;
                                    esp = (esp - 0xc) + 0xc - 0x18;
                                    eax = MultiByteToWideChar(arg_10, 0x1, arg_4, arg_8, decomp_var_1c, decomp_var_18);
                                    if (eax != 0x0) {
                                            esp = esp - 0x10;
                                            var_8 = GetStringTypeW(arg_0, ebx, eax, arg_c);
                                    }
                                    sub_482993(ebx);
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    &decomp_var_20 = &var_14;
                    eax = sub_47ad69();
            }
            else {
                    if (GetLastError() == 0x78) {
                            decomp_var_18 = 0x2;
                            eax = 0x2;
                            esp = (esp - 0x4) + 0x4;
                            *dword_bc6f44 = 0x2;
                    }
                    else {
                            eax = *dword_bc6f44;
                    }
                    switch (eax) {
                        case 2:
                            if (arg_14 == 0x0) {
                                    arg_14 = *(*edi + 0x14);
                            }
                            if (arg_10 == 0x0) {
                                    arg_10 = *(*edi + 0x4);
                            }
                            decomp_var_18 = arg_14;
                            eax = sub_48c440(decomp_var_18);
                            esp = (esp - 0x4) + 0x4;
                            if (eax == 0xffffffff) {
                                    &decomp_var_20 = &var_14;
                                    eax = sub_47ad69();
                            }
                            else {
                                    if (eax != arg_10) {
                                            decomp_var_18 = 0x0;
                                            decomp_var_1c = 0x0;
                                            eax = sub_48c487(arg_10, eax, arg_4, &arg_8, 0x0, 0x0);
                                            esi = eax;
                                            esp = (esp - 0x18) + 0x18;
                                            if (esi != 0x0) {
                                                    arg_4 = esi;
                                                    decomp_var_18 = arg_c;
                                                    decomp_var_1c = arg_8;
                                                    esp = esp - 0x14;
                                                    edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                                    if (esi != 0x0) {
                                                            decomp_var_18 = esi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &decomp_var_20 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    &decomp_var_20 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            decomp_var_18 = arg_c;
                                            decomp_var_1c = arg_8;
                                            esp = esp - 0x14;
                                            edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                            if (0x0 != 0x0) {
                                                    decomp_var_18 = 0x0;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &decomp_var_20 = &var_14;
                                            eax = sub_47ad69();
                                    }
                            }
                            break;
                        case 0:
                            ebx = 0x0;
                            if (arg_14 == 0x0) {
                                    arg_14 = *(*edi + 0x14);
                            }
                            if (arg_10 == ebx) {
                                    arg_10 = *(*edi + 0x4);
                            }
                            decomp_var_18 = arg_14;
                            eax = sub_48c440(decomp_var_18);
                            esp = (esp - 0x4) + 0x4;
                            if (eax == 0xffffffff) {
                                    &decomp_var_20 = &var_14;
                                    eax = sub_47ad69();
                            }
                            else {
                                    if (eax != arg_10) {
                                            decomp_var_18 = ebx;
                                            decomp_var_1c = ebx;
                                            eax = sub_48c487(arg_10, eax, arg_4, &arg_8, decomp_var_1c, decomp_var_18);
                                            esi = eax;
                                            esp = (esp - 0x18) + 0x18;
                                            if (esi != ebx) {
                                                    arg_4 = esi;
                                                    decomp_var_18 = arg_c;
                                                    decomp_var_1c = arg_8;
                                                    esp = esp - 0x14;
                                                    edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                                    if (esi != ebx) {
                                                            decomp_var_18 = esi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &decomp_var_20 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    &decomp_var_20 = &var_14;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            decomp_var_18 = arg_c;
                                            decomp_var_1c = arg_8;
                                            esp = esp - 0x14;
                                            edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                            if (0x0 != 0x0) {
                                                    decomp_var_18 = 0x0;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &decomp_var_20 = &var_14;
                                            eax = sub_47ad69();
                                    }
                            }
                            break;
                        default:
                            if (eax == 0x1) {
                                    ebx = 0x0;
                                    var_8 = 0x0;
                                    if (arg_10 == 0x0) {
                                            arg_10 = *(*edi + 0x4);
                                    }
                                    decomp_var_18 = ebx;
                                    decomp_var_1c = ebx;
                                    esp = esp - 0x18;
                                    edi = MultiByteToWideChar(arg_10, (arg_18 != ebx ? 0x1 : 0x0) * 0x8 + 0x1, arg_4, arg_8, decomp_var_1c, decomp_var_18);
                                    bool_47 = edi <= ebx;
                                    if (arg_18 != ebx) {
                                            if (!bool_47 && edi <= 0x7ffffff0) {
                                                    eax = edi + edi + 0x8;
                                                    if (eax <= 0x400) {
                                                            sub_47ceb0(var_14);
                                                            eax = &var_14;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xcccc;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_18 = eax;
                                                            eax = sub_47c836();
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xdddd;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    ebx = eax;
                                            }
                                            if (ebx != 0x0) {
                                                    sub_47ba40(ebx, 0x0, edi + edi);
                                                    decomp_var_18 = edi;
                                                    decomp_var_1c = ebx;
                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                    eax = MultiByteToWideChar(arg_10, 0x1, arg_4, arg_8, decomp_var_1c, decomp_var_18);
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x10;
                                                            var_8 = GetStringTypeW(arg_0, ebx, eax, arg_c);
                                                    }
                                                    sub_482993(ebx);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                                    &decomp_var_20 = &var_14;
                                    eax = sub_47ad69();
                            }
                            else {
                                    &decomp_var_20 = &var_14;
                                    eax = sub_47ad69();
                            }
                            break;
                    }
            }
    }
    else {
            switch (*dword_bc6f44) {
                case 2:
                    if (arg_14 == 0x0) {
                            arg_14 = *(*edi + 0x14);
                    }
                    ebx = 0x0;
                    if (arg_10 == 0x0) {
                            arg_10 = *(*edi + 0x4);
                    }
                    decomp_var_18 = arg_14;
                    eax = sub_48c440(decomp_var_18);
                    esp = (esp - 0x4) + 0x4;
                    if (eax == 0xffffffff) {
                            &decomp_var_20 = &var_14;
                            eax = sub_47ad69();
                    }
                    else {
                            if (eax != arg_10) {
                                    decomp_var_18 = ebx;
                                    decomp_var_1c = ebx;
                                    eax = sub_48c487(arg_10, eax, arg_4, &arg_8, decomp_var_1c, decomp_var_18);
                                    esi = eax;
                                    esp = (esp - 0x18) + 0x18;
                                    if (esi != ebx) {
                                            arg_4 = esi;
                                            decomp_var_18 = arg_c;
                                            decomp_var_1c = arg_8;
                                            esp = esp - 0x14;
                                            edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                            if (esi != ebx) {
                                                    decomp_var_18 = esi;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &decomp_var_20 = &var_14;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            &decomp_var_20 = &var_14;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    decomp_var_18 = arg_c;
                                    decomp_var_1c = arg_8;
                                    esp = esp - 0x14;
                                    edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                    if (0x0 != ebx) {
                                            decomp_var_18 = 0x0;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    &decomp_var_20 = &var_14;
                                    eax = sub_47ad69();
                            }
                    }
                    break;
                case 0:
                    if (arg_14 == 0x0) {
                            arg_14 = *(*edi + 0x14);
                    }
                    if (arg_10 == 0x0) {
                            arg_10 = *(*edi + 0x4);
                    }
                    decomp_var_18 = arg_14;
                    eax = sub_48c440(decomp_var_18);
                    esp = (esp - 0x4) + 0x4;
                    if (eax == 0xffffffff) {
                            &decomp_var_20 = &var_14;
                            eax = sub_47ad69();
                    }
                    else {
                            if (eax != arg_10) {
                                    decomp_var_18 = 0x0;
                                    decomp_var_1c = 0x0;
                                    eax = sub_48c487(arg_10, eax, arg_4, &arg_8, 0x0, 0x0);
                                    esi = eax;
                                    esp = (esp - 0x18) + 0x18;
                                    if (esi != 0x0) {
                                            arg_4 = esi;
                                            decomp_var_18 = arg_c;
                                            decomp_var_1c = arg_8;
                                            esp = esp - 0x14;
                                            edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                            if (esi != 0x0) {
                                                    decomp_var_18 = esi;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &decomp_var_20 = &var_14;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            &decomp_var_20 = &var_14;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    decomp_var_18 = arg_c;
                                    decomp_var_1c = arg_8;
                                    esp = esp - 0x14;
                                    edi = GetStringTypeA(arg_14, arg_0, arg_4, decomp_var_1c, decomp_var_18);
                                    if (0x0 != 0x0) {
                                            decomp_var_18 = 0x0;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    &decomp_var_20 = &var_14;
                                    eax = sub_47ad69();
                            }
                    }
                    break;
                default:
                    if (*dword_bc6f44 == 0x1) {
                            ebx = 0x0;
                            var_8 = 0x0;
                            if (arg_10 == 0x0) {
                                    arg_10 = *(*edi + 0x4);
                            }
                            decomp_var_18 = ebx;
                            decomp_var_1c = ebx;
                            esp = esp - 0x18;
                            edi = MultiByteToWideChar(arg_10, (arg_18 != ebx ? 0x1 : 0x0) * 0x8 + 0x1, arg_4, arg_8, decomp_var_1c, decomp_var_18);
                            bool_13 = edi <= ebx;
                            if (arg_18 != ebx) {
                                    if (!bool_13 && edi <= 0x7ffffff0) {
                                            eax = edi + edi + 0x8;
                                            if (eax <= 0x400) {
                                                    sub_47ceb0(var_14);
                                                    eax = &var_14;
                                                    if (eax != 0x0) {
                                                            *eax = 0xcccc;
                                                            eax = eax + 0x8;
                                                    }
                                            }
                                            else {
                                                    decomp_var_18 = eax;
                                                    eax = sub_47c836();
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax != 0x0) {
                                                            *eax = 0xdddd;
                                                            eax = eax + 0x8;
                                                    }
                                            }
                                            ebx = eax;
                                    }
                                    if (ebx != 0x0) {
                                            sub_47ba40(ebx, 0x0, edi + edi);
                                            decomp_var_18 = edi;
                                            decomp_var_1c = ebx;
                                            esp = (esp - 0xc) + 0xc - 0x18;
                                            eax = MultiByteToWideChar(arg_10, 0x1, arg_4, arg_8, decomp_var_1c, decomp_var_18);
                                            if (eax != 0x0) {
                                                    esp = esp - 0x10;
                                                    var_8 = GetStringTypeW(arg_0, ebx, eax, arg_c);
                                            }
                                            sub_482993(ebx);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                            &decomp_var_20 = &var_14;
                            eax = sub_47ad69();
                    }
                    else {
                            &decomp_var_20 = &var_14;
                            eax = sub_47ad69();
                    }
                    break;
            }
    }
    return eax;
}
