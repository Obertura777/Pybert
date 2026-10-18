// sub_4829ae @ 0x4829ae
// hopper name: sub_4829ae
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4829ae() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0xc;
    var_20 = edi;
    esi = ecx;
    if (*dword_bc6890 == 0x0) {
            decomp_var_24 = 0x0;
            decomp_var_28 = 0x0;
            decomp_var_2c = 0x1;
            esp = esp - 0x18;
            if (LCMapStringW(0x0, 0x100, 0x4b3b5c, 0x1, 0x0, 0x0) != 0x0) {
                    *dword_bc6890 = 0x1;
            }
            else {
                    if (GetLastError() == 0x78) {
                            *dword_bc6890 = 0x2;
                    }
            }
    }
    if (arg_c > 0x0) {
            ecx = arg_c;
            eax = arg_8;
            while (true) {
                    ebx = 0x0;
                    ecx = ecx - 0x1;
                    if (*(int8_t *)eax == 0x0) {
                            break;
                    }
                    eax = eax + 0x1;
                    if (ecx != ebx) {
                            continue;
                    }
                    ecx = ecx | 0xffffffff;
                    break;
            }
            eax = arg_c - ecx - 0x1;
            if (eax < arg_c) {
                    eax = eax + 0x1;
            }
            arg_c = eax;
    }
    if (*dword_bc6890 != 0x2) {
            ebx = 0x0;
            if (*dword_bc6890 != 0x0) {
                    if (*dword_bc6890 == 0x1) {
                            var_8 = ebx;
                            if (arg_18 == ebx) {
                                    arg_18 = *(*esi + 0x4);
                            }
                            decomp_var_24 = ebx;
                            decomp_var_28 = ebx;
                            decomp_var_2c = arg_c;
                            esp = esp - 0x18;
                            edi = MultiByteToWideChar(arg_18, (arg_1c != ebx ? 0x1 : 0x0) * 0x8 + 0x1, arg_8, decomp_var_2c, decomp_var_28, decomp_var_24);
                            bool_99 = edi <= ebx;
                            if (arg_1c != ebx) {
                                    if (!bool_99) {
                                            decomp_var_24 = 0xffffffe0;
                                            esp = (esp - 0x4) + 0x4;
                                            if (0xffffffe0 / edi >= 0x2) {
                                                    eax = edi + edi + 0x8;
                                                    if (eax <= 0x400) {
                                                            sub_47ceb0(var_20);
                                                            eax = &var_20;
                                                            if (eax != ebx) {
                                                                    *eax = 0xcccc;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_24 = eax;
                                                            eax = sub_47c836();
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax != ebx) {
                                                                    *eax = 0xdddd;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    var_C = eax;
                                            }
                                            else {
                                                    var_C = ebx;
                                            }
                                    }
                                    else {
                                            var_C = ebx;
                                    }
                                    if (var_C != ebx) {
                                            decomp_var_28 = var_C;
                                            decomp_var_2c = arg_c;
                                            esp = esp - 0x18;
                                            if (MultiByteToWideChar(arg_18, 0x1, arg_8, decomp_var_2c, decomp_var_28, edi) != 0x0) {
                                                    decomp_var_28 = ebx;
                                                    decomp_var_2c = edi;
                                                    esp = esp - 0x18;
                                                    ecx = LCMapStringW(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, ebx);
                                                    var_8 = ecx;
                                                    if (ecx != ebx) {
                                                            if ((arg_4 & 0x400) != 0x0) {
                                                                    if (arg_14 != ebx) {
                                                                            if (ecx <= arg_14) {
                                                                                    decomp_var_28 = arg_10;
                                                                                    decomp_var_2c = edi;
                                                                                    esp = esp - 0x18;
                                                                                    LCMapStringW(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, arg_14);
                                                                            }
                                                                    }
                                                                    decomp_var_24 = var_C;
                                                                    sub_482993(decomp_var_24);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &var_20 = &var_20;
                                                                    eax = sub_47ad69();
                                                            }
                                                            else {
                                                                    if (ecx > ebx) {
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (0xffffffe0 / ecx >= 0x2) {
                                                                                    eax = ecx + ecx + 0x8;
                                                                                    if (eax <= 0x400) {
                                                                                            sub_47ceb0(var_20);
                                                                                            esi = &var_20;
                                                                                            if (esi != ebx) {
                                                                                                    *esi = 0xcccc;
                                                                                                    esi = esi + 0x8;
                                                                                                    if (esi != ebx) {
                                                                                                            decomp_var_28 = esi;
                                                                                                            decomp_var_2c = edi;
                                                                                                            esp = esp - 0x18;
                                                                                                            if (LCMapStringW(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, var_8) != 0x0) {
                                                                                                                    decomp_var_24 = ebx;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_28 = ebx;
                                                                                                                    if (arg_14 == ebx) {
                                                                                                                            decomp_var_2c = ebx;
                                                                                                                            esp = esp - 0x8;
                                                                                                                            decomp_var_30 = ebx;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            decomp_var_2c = arg_14;
                                                                                                                            esp = esp - 0x8;
                                                                                                                            decomp_var_30 = arg_10;
                                                                                                                    }
                                                                                                                    esp = esp - 0x10;
                                                                                                                    var_8 = WideCharToMultiByte(arg_18, ebx, esi, var_8, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                                            }
                                                                                                            sub_482993(esi);
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                    }
                                                                                                    decomp_var_24 = var_C;
                                                                                                    sub_482993(decomp_var_24);
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    &var_20 = &var_20;
                                                                                                    eax = sub_47ad69();
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_24 = var_C;
                                                                                                    sub_482993(decomp_var_24);
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    &var_20 = &var_20;
                                                                                                    eax = sub_47ad69();
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_47c836();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            if (eax != ebx) {
                                                                                                    *eax = 0xdddd;
                                                                                                    eax = eax + 0x8;
                                                                                            }
                                                                                            esi = eax;
                                                                                            if (esi != ebx) {
                                                                                                    decomp_var_28 = esi;
                                                                                                    decomp_var_2c = edi;
                                                                                                    esp = esp - 0x18;
                                                                                                    if (LCMapStringW(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, var_8) != 0x0) {
                                                                                                            decomp_var_24 = ebx;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_28 = ebx;
                                                                                                            if (arg_14 == ebx) {
                                                                                                                    decomp_var_2c = ebx;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_30 = ebx;
                                                                                                            }
                                                                                                            else {
                                                                                                                    decomp_var_2c = arg_14;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_30 = arg_10;
                                                                                                            }
                                                                                                            esp = esp - 0x10;
                                                                                                            var_8 = WideCharToMultiByte(arg_18, ebx, esi, var_8, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                                    }
                                                                                                    sub_482993(esi);
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                            }
                                                                                            decomp_var_24 = var_C;
                                                                                            sub_482993(decomp_var_24);
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            &var_20 = &var_20;
                                                                                            eax = sub_47ad69();
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (0x0 != ebx) {
                                                                                            decomp_var_28 = 0x0;
                                                                                            decomp_var_2c = edi;
                                                                                            esp = esp - 0x18;
                                                                                            if (LCMapStringW(arg_0, arg_4, var_C, decomp_var_2c, 0x0, var_8) != 0x0) {
                                                                                                    decomp_var_24 = ebx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_28 = ebx;
                                                                                                    if (arg_14 == ebx) {
                                                                                                            decomp_var_2c = ebx;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_30 = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            decomp_var_2c = arg_14;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_30 = arg_10;
                                                                                                    }
                                                                                                    esp = esp - 0x10;
                                                                                                    var_8 = WideCharToMultiByte(arg_18, ebx, 0x0, var_8, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                            }
                                                                                            sub_482993(0x0);
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    decomp_var_24 = var_C;
                                                                                    sub_482993(decomp_var_24);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    &var_20 = &var_20;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (0x0 != ebx) {
                                                                                    decomp_var_28 = 0x0;
                                                                                    decomp_var_2c = edi;
                                                                                    esp = esp - 0x18;
                                                                                    if (LCMapStringW(arg_0, arg_4, var_C, decomp_var_2c, 0x0, var_8) != 0x0) {
                                                                                            decomp_var_24 = ebx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_28 = ebx;
                                                                                            if (arg_14 == ebx) {
                                                                                                    decomp_var_2c = ebx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_30 = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_2c = arg_14;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_30 = arg_10;
                                                                                            }
                                                                                            esp = esp - 0x10;
                                                                                            var_8 = WideCharToMultiByte(arg_18, ebx, 0x0, var_8, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                    }
                                                                                    sub_482993(0x0);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            decomp_var_24 = var_C;
                                                                            sub_482993(decomp_var_24);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            &var_20 = &var_20;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_24 = var_C;
                                                            sub_482993(decomp_var_24);
                                                            esp = (esp - 0x4) + 0x4;
                                                            &var_20 = &var_20;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    decomp_var_24 = var_C;
                                                    sub_482993(decomp_var_24);
                                                    esp = (esp - 0x4) + 0x4;
                                                    &var_20 = &var_20;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            &var_20 = &var_20;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    &var_20 = &var_20;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            &var_20 = &var_20;
                            eax = sub_47ad69();
                    }
            }
            else {
                    var_C = ebx;
                    var_10 = ebx;
                    if (arg_0 == ebx) {
                            arg_0 = *(*esi + 0x14);
                    }
                    ebx = 0x0;
                    if (arg_18 == 0x0) {
                            arg_18 = *(*esi + 0x4);
                    }
                    decomp_var_24 = arg_0;
                    eax = sub_48c440(decomp_var_24);
                    esp = (esp - 0x4) + 0x4;
                    var_14 = eax;
                    if (eax == 0xffffffff) {
                            &var_20 = &var_20;
                            eax = sub_47ad69();
                    }
                    else {
                            if (eax != arg_18) {
                                    decomp_var_24 = ebx;
                                    decomp_var_28 = ebx;
                                    decomp_var_2c = &arg_c;
                                    eax = sub_48c487(arg_18, eax, arg_8, decomp_var_2c, decomp_var_28, decomp_var_24);
                                    esp = (esp - 0x18) + 0x18;
                                    var_C = eax;
                                    if (eax != ebx) {
                                            decomp_var_24 = ebx;
                                            decomp_var_28 = ebx;
                                            decomp_var_2c = arg_c;
                                            esp = esp - 0x18;
                                            eax = LCMapStringA(arg_0, arg_4, eax, decomp_var_2c, decomp_var_28, decomp_var_24);
                                            bool_71 = eax <= ebx;
                                            var_8 = eax;
                                            if (eax == ebx) {
                                                    if (var_C != ebx) {
                                                            decomp_var_24 = var_C;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    eax = var_10;
                                                    if (eax != ebx && arg_10 != eax) {
                                                            decomp_var_24 = eax;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_20 = &var_20;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    if (!bool_71) {
                                                            if (eax <= 0xffffffe0) {
                                                                    eax = eax + 0x8;
                                                                    if (eax <= 0x400) {
                                                                            sub_47ceb0(var_20);
                                                                            edi = &var_20;
                                                                            if (edi != ebx) {
                                                                                    *edi = 0xcccc;
                                                                                    edi = edi + 0x8;
                                                                                    if (edi != ebx) {
                                                                                            sub_47ba40(edi, ebx, var_8);
                                                                                            decomp_var_24 = var_8;
                                                                                            decomp_var_28 = edi;
                                                                                            decomp_var_2c = arg_c;
                                                                                            esp = (esp - 0xc) + 0xc - 0x18;
                                                                                            eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                            var_8 = eax;
                                                                                            if (eax == ebx) {
                                                                                                    esi = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    eax = sub_48c487(var_14, arg_18, edi, &var_8, arg_10, arg_14);
                                                                                                    var_10 = eax;
                                                                                                    esp = (esp - 0x18) + 0x18;
                                                                                                    esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                                            }
                                                                                            sub_482993(edi);
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            esi = 0x0;
                                                                                    }
                                                                                    if (var_C != ebx) {
                                                                                            decomp_var_24 = var_C;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    eax = var_10;
                                                                                    if (eax != ebx && arg_10 != eax) {
                                                                                            decomp_var_24 = eax;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    &var_20 = &var_20;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                            else {
                                                                                    if (var_C != ebx) {
                                                                                            decomp_var_24 = var_C;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    eax = var_10;
                                                                                    if (eax != ebx && arg_10 != eax) {
                                                                                            decomp_var_24 = eax;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    &var_20 = &var_20;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                                    else {
                                                                            decomp_var_24 = eax;
                                                                            eax = sub_47c836();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (eax != ebx) {
                                                                                    *eax = 0xdddd;
                                                                                    eax = eax + 0x8;
                                                                            }
                                                                            edi = eax;
                                                                            if (edi != ebx) {
                                                                                    sub_47ba40(edi, ebx, var_8);
                                                                                    decomp_var_24 = var_8;
                                                                                    decomp_var_28 = edi;
                                                                                    decomp_var_2c = arg_c;
                                                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                                                    eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                    var_8 = eax;
                                                                                    if (eax == ebx) {
                                                                                            esi = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_48c487(var_14, arg_18, edi, &var_8, arg_10, arg_14);
                                                                                            var_10 = eax;
                                                                                            esp = (esp - 0x18) + 0x18;
                                                                                            esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                                    }
                                                                                    sub_482993(edi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            else {
                                                                                    esi = 0x0;
                                                                            }
                                                                            if (var_C != ebx) {
                                                                                    decomp_var_24 = var_C;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            eax = var_10;
                                                                            if (eax != ebx && arg_10 != eax) {
                                                                                    decomp_var_24 = eax;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            &var_20 = &var_20;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    if (0x0 != ebx) {
                                                                            sub_47ba40(0x0, ebx, var_8);
                                                                            decomp_var_24 = var_8;
                                                                            decomp_var_28 = 0x0;
                                                                            decomp_var_2c = arg_c;
                                                                            esp = (esp - 0xc) + 0xc - 0x18;
                                                                            eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, 0x0, decomp_var_24);
                                                                            var_8 = eax;
                                                                            if (eax == ebx) {
                                                                                    esi = 0x0;
                                                                            }
                                                                            else {
                                                                                    eax = sub_48c487(var_14, arg_18, 0x0, &var_8, arg_10, arg_14);
                                                                                    var_10 = eax;
                                                                                    esp = (esp - 0x18) + 0x18;
                                                                                    esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                            }
                                                                            sub_482993(0x0);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    else {
                                                                            esi = 0x0;
                                                                    }
                                                                    if (var_C != ebx) {
                                                                            decomp_var_24 = var_C;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    eax = var_10;
                                                                    if (eax != ebx && arg_10 != eax) {
                                                                            decomp_var_24 = eax;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_20 = &var_20;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (0x0 != ebx) {
                                                                    sub_47ba40(0x0, ebx, var_8);
                                                                    decomp_var_24 = var_8;
                                                                    decomp_var_28 = 0x0;
                                                                    decomp_var_2c = arg_c;
                                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                                    eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, 0x0, decomp_var_24);
                                                                    var_8 = eax;
                                                                    if (eax == ebx) {
                                                                            esi = 0x0;
                                                                    }
                                                                    else {
                                                                            eax = sub_48c487(var_14, arg_18, 0x0, &var_8, arg_10, arg_14);
                                                                            var_10 = eax;
                                                                            esp = (esp - 0x18) + 0x18;
                                                                            esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                    }
                                                                    sub_482993(0x0);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            else {
                                                                    esi = 0x0;
                                                            }
                                                            if (var_C != ebx) {
                                                                    decomp_var_24 = var_C;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            eax = var_10;
                                                            if (eax != ebx && arg_10 != eax) {
                                                                    decomp_var_24 = eax;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_20 = &var_20;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                    }
                                    else {
                                            &var_20 = &var_20;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    decomp_var_24 = arg_14;
                                    decomp_var_28 = arg_10;
                                    decomp_var_2c = arg_c;
                                    esp = esp - 0x18;
                                    esi = LCMapStringA(arg_0, arg_4, arg_8, decomp_var_2c, decomp_var_28, decomp_var_24);
                                    if (var_C != ebx) {
                                            decomp_var_24 = var_C;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    eax = var_10;
                                    if (eax != ebx && arg_10 != eax) {
                                            decomp_var_24 = eax;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    &var_20 = &var_20;
                                    eax = sub_47ad69();
                            }
                    }
            }
    }
    else {
            ebx = 0x0;
            var_C = 0x0;
            var_10 = 0x0;
            if (arg_0 == 0x0) {
                    arg_0 = *(*esi + 0x14);
            }
            if (arg_18 == ebx) {
                    arg_18 = *(*esi + 0x4);
            }
            decomp_var_24 = arg_0;
            eax = sub_48c440(decomp_var_24);
            esp = (esp - 0x4) + 0x4;
            var_14 = eax;
            if (eax == 0xffffffff) {
                    &var_20 = &var_20;
                    eax = sub_47ad69();
            }
            else {
                    if (eax != arg_18) {
                            decomp_var_24 = ebx;
                            decomp_var_28 = ebx;
                            decomp_var_2c = &arg_c;
                            eax = sub_48c487(arg_18, eax, arg_8, decomp_var_2c, decomp_var_28, decomp_var_24);
                            esp = (esp - 0x18) + 0x18;
                            var_C = eax;
                            if (eax != ebx) {
                                    decomp_var_24 = ebx;
                                    decomp_var_28 = ebx;
                                    decomp_var_2c = arg_c;
                                    esp = esp - 0x18;
                                    eax = LCMapStringA(arg_0, arg_4, eax, decomp_var_2c, decomp_var_28, decomp_var_24);
                                    bool_21 = eax <= ebx;
                                    var_8 = eax;
                                    if (eax == ebx) {
                                            if (var_C != ebx) {
                                                    decomp_var_24 = var_C;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            eax = var_10;
                                            if (eax != ebx && arg_10 != eax) {
                                                    decomp_var_24 = eax;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            &var_20 = &var_20;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (!bool_21) {
                                                    if (eax <= 0xffffffe0) {
                                                            eax = eax + 0x8;
                                                            if (eax <= 0x400) {
                                                                    sub_47ceb0(var_20);
                                                                    edi = &var_20;
                                                                    if (edi != ebx) {
                                                                            *edi = 0xcccc;
                                                                            edi = edi + 0x8;
                                                                            if (edi != ebx) {
                                                                                    sub_47ba40(edi, ebx, var_8);
                                                                                    decomp_var_24 = var_8;
                                                                                    decomp_var_28 = edi;
                                                                                    decomp_var_2c = arg_c;
                                                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                                                    eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                                    var_8 = eax;
                                                                                    if (eax == ebx) {
                                                                                            esi = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_48c487(var_14, arg_18, edi, &var_8, arg_10, arg_14);
                                                                                            var_10 = eax;
                                                                                            esp = (esp - 0x18) + 0x18;
                                                                                            esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                                    }
                                                                                    sub_482993(edi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            else {
                                                                                    esi = 0x0;
                                                                            }
                                                                            if (var_C != ebx) {
                                                                                    decomp_var_24 = var_C;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            eax = var_10;
                                                                            if (eax != ebx && arg_10 != eax) {
                                                                                    decomp_var_24 = eax;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            &var_20 = &var_20;
                                                                            eax = sub_47ad69();
                                                                    }
                                                                    else {
                                                                            if (var_C != ebx) {
                                                                                    decomp_var_24 = var_C;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            eax = var_10;
                                                                            if (eax != ebx && arg_10 != eax) {
                                                                                    decomp_var_24 = eax;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            &var_20 = &var_20;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    decomp_var_24 = eax;
                                                                    eax = sub_47c836();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax != ebx) {
                                                                            *eax = 0xdddd;
                                                                            eax = eax + 0x8;
                                                                    }
                                                                    edi = eax;
                                                                    if (edi != ebx) {
                                                                            sub_47ba40(edi, ebx, var_8);
                                                                            decomp_var_24 = var_8;
                                                                            decomp_var_28 = edi;
                                                                            decomp_var_2c = arg_c;
                                                                            esp = (esp - 0xc) + 0xc - 0x18;
                                                                            eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, decomp_var_28, decomp_var_24);
                                                                            var_8 = eax;
                                                                            if (eax == ebx) {
                                                                                    esi = 0x0;
                                                                            }
                                                                            else {
                                                                                    eax = sub_48c487(var_14, arg_18, edi, &var_8, arg_10, arg_14);
                                                                                    var_10 = eax;
                                                                                    esp = (esp - 0x18) + 0x18;
                                                                                    esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                            }
                                                                            sub_482993(edi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    else {
                                                                            esi = 0x0;
                                                                    }
                                                                    if (var_C != ebx) {
                                                                            decomp_var_24 = var_C;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    eax = var_10;
                                                                    if (eax != ebx && arg_10 != eax) {
                                                                            decomp_var_24 = eax;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    &var_20 = &var_20;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            if (0x0 != ebx) {
                                                                    sub_47ba40(0x0, ebx, var_8);
                                                                    decomp_var_24 = var_8;
                                                                    decomp_var_28 = 0x0;
                                                                    decomp_var_2c = arg_c;
                                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                                    eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, 0x0, decomp_var_24);
                                                                    var_8 = eax;
                                                                    if (eax == ebx) {
                                                                            esi = 0x0;
                                                                    }
                                                                    else {
                                                                            eax = sub_48c487(var_14, arg_18, 0x0, &var_8, arg_10, arg_14);
                                                                            var_10 = eax;
                                                                            esp = (esp - 0x18) + 0x18;
                                                                            esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                                    }
                                                                    sub_482993(0x0);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            else {
                                                                    esi = 0x0;
                                                            }
                                                            if (var_C != ebx) {
                                                                    decomp_var_24 = var_C;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            eax = var_10;
                                                            if (eax != ebx && arg_10 != eax) {
                                                                    decomp_var_24 = eax;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            &var_20 = &var_20;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    if (0x0 != ebx) {
                                                            sub_47ba40(0x0, ebx, var_8);
                                                            decomp_var_24 = var_8;
                                                            decomp_var_28 = 0x0;
                                                            decomp_var_2c = arg_c;
                                                            esp = (esp - 0xc) + 0xc - 0x18;
                                                            eax = LCMapStringA(arg_0, arg_4, var_C, decomp_var_2c, 0x0, decomp_var_24);
                                                            var_8 = eax;
                                                            if (eax == ebx) {
                                                                    esi = 0x0;
                                                            }
                                                            else {
                                                                    eax = sub_48c487(var_14, arg_18, 0x0, &var_8, arg_10, arg_14);
                                                                    var_10 = eax;
                                                                    esp = (esp - 0x18) + 0x18;
                                                                    esi = -eax - -eax + CARRY(EFLAGS(cf)) & var_8;
                                                            }
                                                            sub_482993(0x0);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    else {
                                                            esi = 0x0;
                                                    }
                                                    if (var_C != ebx) {
                                                            decomp_var_24 = var_C;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    eax = var_10;
                                                    if (eax != ebx && arg_10 != eax) {
                                                            decomp_var_24 = eax;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    &var_20 = &var_20;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                            else {
                                    &var_20 = &var_20;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            decomp_var_24 = arg_14;
                            decomp_var_28 = arg_10;
                            decomp_var_2c = arg_c;
                            esp = esp - 0x18;
                            esi = LCMapStringA(arg_0, arg_4, arg_8, decomp_var_2c, decomp_var_28, decomp_var_24);
                            if (var_C != ebx) {
                                    decomp_var_24 = var_C;
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            eax = var_10;
                            if (eax != ebx && arg_10 != eax) {
                                    decomp_var_24 = eax;
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            &var_20 = &var_20;
                            eax = sub_47ad69();
                    }
            }
    }
    return eax;
}
