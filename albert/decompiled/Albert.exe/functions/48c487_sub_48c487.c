// sub_48c487 @ 0x48c487
// hopper name: sub_48c487
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c487() {
    var_4 = *dword_4c8db8 ^ ebp;
    var_28 = arg_8;
    var_30 = arg_c;
    var_24 = *arg_c;
    eax = arg_0;
    esp = esp - 0xc;
    var_40 = edi;
    var_34 = arg_10;
    var_20 = 0x0;
    var_2C = 0x0;
    if (eax != arg_4) {
            esp = esp - 0x8;
            eax = GetCPInfo(eax, &var_18);
            if (eax != 0x0) {
                    if (var_18 == 0x1) {
                            esp = esp - 0x8;
                            eax = GetCPInfo(arg_4, &var_18);
                            if (eax != 0x0) {
                                    if (var_18 == 0x1) {
                                            esi = var_24;
                                            bool_15 = esi <= 0xffffffff;
                                            var_2C = 0x1;
                                            if (esi == 0xffffffff) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = sub_47d630(var_28) + 0x1;
                                            }
                                            if (!bool_15 && esi <= 0x7ffffff0) {
                                                    eax = esi + esi + 0x8;
                                                    if (eax <= 0x400) {
                                                            sub_47ceb0(var_40);
                                                            eax = &var_40;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xcccc;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47c836();
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xdddd;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    var_1C = eax;
                                            }
                                            else {
                                                    var_1C = 0x0;
                                            }
                                            if (var_1C != 0x0) {
                                                    sub_47ba40(var_1C, 0x0, esi + esi);
                                                    decomp_var_54 = 0x1;
                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                    decomp_var_58 = arg_0;
                                                    if (MultiByteToWideChar(decomp_var_58, 0x1, var_28, var_24, var_1C, esi) != 0x0) {
                                                            edi = 0x0;
                                                            ebx = var_34;
                                                            if (ebx != 0x0) {
                                                                    decomp_var_54 = 0x0;
                                                                    decomp_var_58 = arg_14;
                                                                    esp = esp - 0x20;
                                                                    if (WideCharToMultiByte(arg_4, 0x0, var_1C, esi, ebx, decomp_var_58, 0x0, 0x0) != 0x0) {
                                                                            var_20 = ebx;
                                                                    }
                                                                    decomp_var_50 = var_1C;
                                                                    sub_482993(decomp_var_50);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &decomp_var_4c = &var_40;
                                                                    eax = sub_47ad69();
                                                            }
                                                            else {
                                                                    if (var_2C == edi) {
                                                                            decomp_var_54 = 0x0;
                                                                            decomp_var_58 = 0x0;
                                                                            esp = esp - 0x20;
                                                                            esi = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, 0x0, 0x0, 0x0, 0x0);
                                                                            if (esi != 0x0) {
                                                                                    decomp_var_54 = 0x1;
                                                                                    eax = sub_4812c0(0x1, esi);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    var_20 = eax;
                                                                                    if (eax != 0x0) {
                                                                                            edi = 0x0;
                                                                                            decomp_var_54 = 0x0;
                                                                                            decomp_var_58 = esi;
                                                                                            esp = esp - 0x20;
                                                                                            eax = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, eax, decomp_var_58, 0x0, 0x0);
                                                                                            if (eax == 0x0) {
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    var_20 = edi;
                                                                                            }
                                                                                            else {
                                                                                                    if (var_24 != 0xffffffff) {
                                                                                                            *var_30 = eax;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    decomp_var_50 = var_1C;
                                                                                    sub_482993(decomp_var_50);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    &decomp_var_4c = &var_40;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                            else {
                                                                                    decomp_var_50 = var_1C;
                                                                                    sub_482993(decomp_var_50);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    &decomp_var_4c = &var_40;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                                    else {
                                                                            decomp_var_54 = 0x1;
                                                                            eax = sub_4812c0(0x1, esi);
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            var_20 = eax;
                                                                            if (eax != edi) {
                                                                                    decomp_var_54 = edi;
                                                                                    decomp_var_58 = esi;
                                                                                    esp = esp - 0x20;
                                                                                    eax = WideCharToMultiByte(arg_4, edi, var_1C, esi, eax, decomp_var_58, decomp_var_54, edi);
                                                                                    if (eax == edi) {
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            var_20 = edi;
                                                                                    }
                                                                                    else {
                                                                                            if (var_24 != 0xffffffff) {
                                                                                                    *var_30 = eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            decomp_var_50 = var_1C;
                                                                            sub_482993(decomp_var_50);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            &decomp_var_4c = &var_40;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_50 = var_1C;
                                                            sub_482993(decomp_var_50);
                                                            esp = (esp - 0x4) + 0x4;
                                                            &decomp_var_4c = &var_40;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    &decomp_var_4c = &var_40;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            decomp_var_50 = var_28;
                                            decomp_var_54 = 0x1;
                                            esp = esp - 0x18;
                                            decomp_var_58 = arg_0;
                                            esi = MultiByteToWideChar(decomp_var_58, 0x1, decomp_var_50, var_24, 0x0, 0x0);
                                            bool_51 = esi <= 0x0;
                                            if (esi == 0x0) {
                                                    &decomp_var_4c = &var_40;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    if (!bool_51 && esi <= 0x7ffffff0) {
                                                            eax = esi + esi + 0x8;
                                                            if (eax <= 0x400) {
                                                                    sub_47ceb0(var_40);
                                                                    eax = &var_40;
                                                                    if (eax != 0x0) {
                                                                            *eax = 0xcccc;
                                                                            eax = eax + 0x8;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47c836();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax != 0x0) {
                                                                            *eax = 0xdddd;
                                                                            eax = eax + 0x8;
                                                                    }
                                                            }
                                                            var_1C = eax;
                                                    }
                                                    else {
                                                            var_1C = 0x0;
                                                    }
                                                    if (var_1C != 0x0) {
                                                            sub_47ba40(var_1C, 0x0, esi + esi);
                                                            decomp_var_54 = 0x1;
                                                            esp = (esp - 0xc) + 0xc - 0x18;
                                                            decomp_var_58 = arg_0;
                                                            if (MultiByteToWideChar(decomp_var_58, 0x1, var_28, var_24, var_1C, esi) != 0x0) {
                                                                    ebx = var_34;
                                                                    if (ebx != 0x0) {
                                                                            decomp_var_54 = 0x0;
                                                                            decomp_var_58 = arg_14;
                                                                            esp = esp - 0x20;
                                                                            if (WideCharToMultiByte(arg_4, 0x0, var_1C, esi, ebx, decomp_var_58, 0x0, 0x0) != 0x0) {
                                                                                    var_20 = ebx;
                                                                            }
                                                                            decomp_var_50 = var_1C;
                                                                            sub_482993(decomp_var_50);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            &decomp_var_4c = &var_40;
                                                                            eax = sub_47ad69();
                                                                    }
                                                                    else {
                                                                            if (var_2C == 0x0) {
                                                                                    decomp_var_54 = 0x0;
                                                                                    decomp_var_58 = 0x0;
                                                                                    esp = esp - 0x20;
                                                                                    esi = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, 0x0, 0x0, 0x0, 0x0);
                                                                                    if (esi != 0x0) {
                                                                                            decomp_var_54 = 0x1;
                                                                                            eax = sub_4812c0(0x1, esi);
                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                            var_20 = eax;
                                                                                            if (eax != 0x0) {
                                                                                                    decomp_var_54 = 0x0;
                                                                                                    decomp_var_58 = esi;
                                                                                                    esp = esp - 0x20;
                                                                                                    eax = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, eax, decomp_var_58, 0x0, 0x0);
                                                                                                    if (eax == 0x0) {
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            var_20 = 0x0;
                                                                                                    }
                                                                                                    else {
                                                                                                            if (var_24 != 0xffffffff) {
                                                                                                                    *var_30 = eax;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            decomp_var_50 = var_1C;
                                                                                            sub_482993(decomp_var_50);
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            &decomp_var_4c = &var_40;
                                                                                            eax = sub_47ad69();
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_50 = var_1C;
                                                                                            sub_482993(decomp_var_50);
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            &decomp_var_4c = &var_40;
                                                                                            eax = sub_47ad69();
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    decomp_var_54 = 0x1;
                                                                                    eax = sub_4812c0(0x1, esi);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    var_20 = eax;
                                                                                    if (eax != 0x0) {
                                                                                            decomp_var_54 = 0x0;
                                                                                            decomp_var_58 = esi;
                                                                                            esp = esp - 0x20;
                                                                                            eax = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, eax, decomp_var_58, 0x0, 0x0);
                                                                                            if (eax == 0x0) {
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    var_20 = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    if (var_24 != 0xffffffff) {
                                                                                                            *var_30 = eax;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    decomp_var_50 = var_1C;
                                                                                    sub_482993(decomp_var_50);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    &decomp_var_4c = &var_40;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    decomp_var_50 = var_1C;
                                                                    sub_482993(decomp_var_50);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &decomp_var_4c = &var_40;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            &decomp_var_4c = &var_40;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_50 = var_28;
                                    decomp_var_54 = 0x1;
                                    esp = esp - 0x18;
                                    decomp_var_58 = arg_0;
                                    esi = MultiByteToWideChar(decomp_var_58, 0x1, decomp_var_50, var_24, 0x0, 0x0);
                                    bool_43 = esi <= 0x0;
                                    if (esi == 0x0) {
                                            &decomp_var_4c = &var_40;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            if (!bool_43 && esi <= 0x7ffffff0) {
                                                    eax = esi + esi + 0x8;
                                                    if (eax <= 0x400) {
                                                            sub_47ceb0(var_40);
                                                            eax = &var_40;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xcccc;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47c836();
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xdddd;
                                                                    eax = eax + 0x8;
                                                            }
                                                    }
                                                    var_1C = eax;
                                            }
                                            else {
                                                    var_1C = 0x0;
                                            }
                                            if (var_1C != 0x0) {
                                                    sub_47ba40(var_1C, 0x0, esi + esi);
                                                    decomp_var_54 = 0x1;
                                                    esp = (esp - 0xc) + 0xc - 0x18;
                                                    decomp_var_58 = arg_0;
                                                    if (MultiByteToWideChar(decomp_var_58, 0x1, var_28, var_24, var_1C, esi) != 0x0) {
                                                            ebx = var_34;
                                                            if (ebx != 0x0) {
                                                                    decomp_var_54 = 0x0;
                                                                    decomp_var_58 = arg_14;
                                                                    esp = esp - 0x20;
                                                                    if (WideCharToMultiByte(arg_4, 0x0, var_1C, esi, ebx, decomp_var_58, 0x0, 0x0) != 0x0) {
                                                                            var_20 = ebx;
                                                                    }
                                                                    decomp_var_50 = var_1C;
                                                                    sub_482993(decomp_var_50);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &decomp_var_4c = &var_40;
                                                                    eax = sub_47ad69();
                                                            }
                                                            else {
                                                                    edi = 0x0;
                                                                    if (var_2C == 0x0) {
                                                                            decomp_var_54 = edi;
                                                                            decomp_var_58 = edi;
                                                                            esp = esp - 0x20;
                                                                            esi = WideCharToMultiByte(arg_4, edi, var_1C, esi, edi, decomp_var_58, decomp_var_54, edi);
                                                                            if (esi != edi) {
                                                                                    decomp_var_54 = 0x1;
                                                                                    eax = sub_4812c0(0x1, esi);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    var_20 = eax;
                                                                                    if (eax != 0x0) {
                                                                                            decomp_var_54 = 0x0;
                                                                                            decomp_var_58 = esi;
                                                                                            esp = esp - 0x20;
                                                                                            eax = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, eax, decomp_var_58, 0x0, 0x0);
                                                                                            if (eax == 0x0) {
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    var_20 = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    if (var_24 != 0xffffffff) {
                                                                                                            *var_30 = eax;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    decomp_var_50 = var_1C;
                                                                                    sub_482993(decomp_var_50);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    &decomp_var_4c = &var_40;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                            else {
                                                                                    decomp_var_50 = var_1C;
                                                                                    sub_482993(decomp_var_50);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    &decomp_var_4c = &var_40;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                                    else {
                                                                            edi = 0x0;
                                                                            decomp_var_54 = 0x1;
                                                                            eax = sub_4812c0(0x1, esi);
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            var_20 = eax;
                                                                            if (eax != 0x0) {
                                                                                    decomp_var_54 = edi;
                                                                                    decomp_var_58 = esi;
                                                                                    esp = esp - 0x20;
                                                                                    eax = WideCharToMultiByte(arg_4, edi, var_1C, esi, eax, decomp_var_58, decomp_var_54, edi);
                                                                                    if (eax == edi) {
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            var_20 = edi;
                                                                                    }
                                                                                    else {
                                                                                            if (var_24 != 0xffffffff) {
                                                                                                    *var_30 = eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            decomp_var_50 = var_1C;
                                                                            sub_482993(decomp_var_50);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            &decomp_var_4c = &var_40;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_50 = var_1C;
                                                            sub_482993(decomp_var_50);
                                                            esp = (esp - 0x4) + 0x4;
                                                            &decomp_var_4c = &var_40;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    &decomp_var_4c = &var_40;
                                                    eax = sub_47ad69();
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_50 = var_28;
                            decomp_var_54 = 0x1;
                            esp = esp - 0x18;
                            decomp_var_58 = arg_0;
                            esi = MultiByteToWideChar(decomp_var_58, 0x1, decomp_var_50, var_24, 0x0, 0x0);
                            bool_47 = esi <= 0x0;
                            if (esi == 0x0) {
                                    &decomp_var_4c = &var_40;
                                    eax = sub_47ad69();
                            }
                            else {
                                    if (!bool_47 && esi <= 0x7ffffff0) {
                                            eax = esi + esi + 0x8;
                                            if (eax <= 0x400) {
                                                    sub_47ceb0(var_40);
                                                    eax = &var_40;
                                                    if (eax != 0x0) {
                                                            *eax = 0xcccc;
                                                            eax = eax + 0x8;
                                                    }
                                            }
                                            else {
                                                    eax = sub_47c836();
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax != 0x0) {
                                                            *eax = 0xdddd;
                                                            eax = eax + 0x8;
                                                    }
                                            }
                                            var_1C = eax;
                                    }
                                    else {
                                            var_1C = 0x0;
                                    }
                                    if (var_1C != 0x0) {
                                            sub_47ba40(var_1C, 0x0, esi + esi);
                                            decomp_var_54 = 0x1;
                                            esp = (esp - 0xc) + 0xc - 0x18;
                                            decomp_var_58 = arg_0;
                                            if (MultiByteToWideChar(decomp_var_58, 0x1, var_28, var_24, var_1C, esi) != 0x0) {
                                                    ebx = var_34;
                                                    if (ebx != 0x0) {
                                                            decomp_var_54 = 0x0;
                                                            decomp_var_58 = arg_14;
                                                            esp = esp - 0x20;
                                                            if (WideCharToMultiByte(arg_4, 0x0, var_1C, esi, ebx, decomp_var_58, 0x0, 0x0) != 0x0) {
                                                                    var_20 = ebx;
                                                            }
                                                            decomp_var_50 = var_1C;
                                                            sub_482993(decomp_var_50);
                                                            esp = (esp - 0x4) + 0x4;
                                                            &decomp_var_4c = &var_40;
                                                            eax = sub_47ad69();
                                                    }
                                                    else {
                                                            if (var_2C == 0x0) {
                                                                    decomp_var_54 = 0x0;
                                                                    decomp_var_58 = 0x0;
                                                                    esp = esp - 0x20;
                                                                    esi = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, 0x0, 0x0, 0x0, 0x0);
                                                                    if (esi != 0x0) {
                                                                            decomp_var_54 = 0x1;
                                                                            eax = sub_4812c0(0x1, esi);
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            var_20 = eax;
                                                                            if (eax != 0x0) {
                                                                                    edi = 0x0;
                                                                                    decomp_var_54 = 0x0;
                                                                                    decomp_var_58 = esi;
                                                                                    esp = esp - 0x20;
                                                                                    eax = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, eax, decomp_var_58, 0x0, 0x0);
                                                                                    if (eax == 0x0) {
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            var_20 = edi;
                                                                                    }
                                                                                    else {
                                                                                            if (var_24 != 0xffffffff) {
                                                                                                    *var_30 = eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            decomp_var_50 = var_1C;
                                                                            sub_482993(decomp_var_50);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            &decomp_var_4c = &var_40;
                                                                            eax = sub_47ad69();
                                                                    }
                                                                    else {
                                                                            decomp_var_50 = var_1C;
                                                                            sub_482993(decomp_var_50);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            &decomp_var_4c = &var_40;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    decomp_var_54 = 0x1;
                                                                    eax = sub_4812c0(0x1, esi);
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    var_20 = eax;
                                                                    if (eax != 0x0) {
                                                                            edi = 0x0;
                                                                            decomp_var_54 = 0x0;
                                                                            decomp_var_58 = esi;
                                                                            esp = esp - 0x20;
                                                                            eax = WideCharToMultiByte(arg_4, 0x0, var_1C, esi, eax, decomp_var_58, 0x0, 0x0);
                                                                            if (eax == 0x0) {
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    var_20 = edi;
                                                                            }
                                                                            else {
                                                                                    if (var_24 != 0xffffffff) {
                                                                                            *var_30 = eax;
                                                                                    }
                                                                            }
                                                                    }
                                                                    decomp_var_50 = var_1C;
                                                                    sub_482993(decomp_var_50);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &decomp_var_4c = &var_40;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                            }
                                            else {
                                                    decomp_var_50 = var_1C;
                                                    sub_482993(decomp_var_50);
                                                    esp = (esp - 0x4) + 0x4;
                                                    &decomp_var_4c = &var_40;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            &decomp_var_4c = &var_40;
                                            eax = sub_47ad69();
                                    }
                            }
                    }
            }
            else {
                    decomp_var_50 = var_28;
                    decomp_var_54 = 0x1;
                    esp = esp - 0x18;
                    decomp_var_58 = arg_0;
                    esi = MultiByteToWideChar(decomp_var_58, 0x1, decomp_var_50, var_24, 0x0, 0x0);
                    bool_4 = esi <= 0x0;
                    if (esi == 0x0) {
                            &decomp_var_4c = &var_40;
                            eax = sub_47ad69();
                    }
                    else {
                            if (!bool_4 && esi <= 0x7ffffff0) {
                                    eax = esi + esi + 0x8;
                                    if (eax <= 0x400) {
                                            sub_47ceb0(var_40);
                                            eax = &var_40;
                                            if (eax != 0x0) {
                                                    *eax = 0xcccc;
                                                    eax = eax + 0x8;
                                            }
                                    }
                                    else {
                                            eax = sub_47c836();
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax != 0x0) {
                                                    *eax = 0xdddd;
                                                    eax = eax + 0x8;
                                            }
                                    }
                                    var_1C = eax;
                            }
                            else {
                                    var_1C = 0x0;
                            }
                            if (var_1C != 0x0) {
                                    edi = 0x0;
                                    sub_47ba40(var_1C, 0x0, esi + esi);
                                    decomp_var_54 = 0x1;
                                    esp = (esp - 0xc) + 0xc - 0x18;
                                    decomp_var_58 = arg_0;
                                    if (MultiByteToWideChar(decomp_var_58, 0x1, var_28, var_24, var_1C, esi) != 0x0) {
                                            ebx = var_34;
                                            if (ebx != edi) {
                                                    decomp_var_54 = edi;
                                                    decomp_var_58 = arg_14;
                                                    esp = esp - 0x20;
                                                    if (WideCharToMultiByte(arg_4, edi, var_1C, esi, ebx, decomp_var_58, decomp_var_54, edi) != 0x0) {
                                                            var_20 = ebx;
                                                    }
                                                    decomp_var_50 = var_1C;
                                                    sub_482993(decomp_var_50);
                                                    esp = (esp - 0x4) + 0x4;
                                                    &decomp_var_4c = &var_40;
                                                    eax = sub_47ad69();
                                            }
                                            else {
                                                    if (var_2C == edi) {
                                                            decomp_var_54 = edi;
                                                            decomp_var_58 = edi;
                                                            esp = esp - 0x20;
                                                            esi = WideCharToMultiByte(arg_4, edi, var_1C, esi, edi, decomp_var_58, decomp_var_54, edi);
                                                            if (esi != edi) {
                                                                    decomp_var_54 = 0x1;
                                                                    eax = sub_4812c0(0x1, esi);
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    var_20 = eax;
                                                                    if (eax != edi) {
                                                                            decomp_var_54 = edi;
                                                                            decomp_var_58 = esi;
                                                                            esp = esp - 0x20;
                                                                            eax = WideCharToMultiByte(arg_4, edi, var_1C, esi, eax, decomp_var_58, decomp_var_54, edi);
                                                                            if (eax == edi) {
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    var_20 = edi;
                                                                            }
                                                                            else {
                                                                                    if (var_24 != 0xffffffff) {
                                                                                            *var_30 = eax;
                                                                                    }
                                                                            }
                                                                    }
                                                                    decomp_var_50 = var_1C;
                                                                    sub_482993(decomp_var_50);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &decomp_var_4c = &var_40;
                                                                    eax = sub_47ad69();
                                                            }
                                                            else {
                                                                    decomp_var_50 = var_1C;
                                                                    sub_482993(decomp_var_50);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    &decomp_var_4c = &var_40;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_54 = 0x1;
                                                            eax = sub_4812c0(0x1, esi);
                                                            esp = (esp - 0x8) + 0x8;
                                                            var_20 = eax;
                                                            if (eax != edi) {
                                                                    decomp_var_54 = edi;
                                                                    decomp_var_58 = esi;
                                                                    esp = esp - 0x20;
                                                                    eax = WideCharToMultiByte(arg_4, edi, var_1C, esi, eax, decomp_var_58, decomp_var_54, edi);
                                                                    if (eax == edi) {
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            var_20 = edi;
                                                                    }
                                                                    else {
                                                                            if (var_24 != 0xffffffff) {
                                                                                    *var_30 = eax;
                                                                            }
                                                                    }
                                                            }
                                                            decomp_var_50 = var_1C;
                                                            sub_482993(decomp_var_50);
                                                            esp = (esp - 0x4) + 0x4;
                                                            &decomp_var_4c = &var_40;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_50 = var_1C;
                                            sub_482993(decomp_var_50);
                                            esp = (esp - 0x4) + 0x4;
                                            &decomp_var_4c = &var_40;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    &decomp_var_4c = &var_40;
                                    eax = sub_47ad69();
                            }
                    }
            }
    }
    else {
            &decomp_var_4c = &var_40;
            eax = sub_47ad69();
    }
    return eax;
}
