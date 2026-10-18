// sub_48c154 @ 0x48c154
// hopper name: sub_48c154
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c154() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    ebp = arg_0;
    esi = sub_480086() + 0x9c;
    if (ebp == 0x0) {
            esi[0x2] = esi[0x2] | 0x104;
            eax = GetUserDefaultLCID();
            esi[0x6] = eax;
            esi[0x7] = eax;
            if (esi[0x2] != 0x0) {
                    ebx = sub_48bc3a();
                    switch (ebx) {
                        case 0:
                            eax = 0x0;
                            break;
                        case 65000:
                            eax = 0x0;
                            break;
                        case 65001:
                            eax = 0x0;
                            break;
                        default:
                            esp = esp - 0x4;
                            if (IsValidCodePage(ebx & 0xffff) != 0x0) {
                                    esp = esp - 0x8;
                                    if (IsValidLocale(esi[0x6], 0x1) != 0x0) {
                                            eax = arg_4;
                                            if (eax != 0x0) {
                                                    *(int16_t *)eax = esi[0xc];
                                                    eax[0x1] = esi[0xe];
                                                    eax[0x2] = ebx;
                                            }
                                            edi = arg_8;
                                            if (edi != 0x0) {
                                                    if (*(int16_t *)eax == 0x814) {
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_47db5e(edi, 0x40, "Norwegian-Nynorsk") != 0x0) {
                                                                    sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                    sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    eax = 0x1;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x10;
                                                            if (GetLocaleInfoA(esi[0x6], 0x1001, edi, 0x40) != 0x0) {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                            sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = 0x1;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                            break;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = &arg_3c;
            edi = esi + 0x4;
            *esi = ebp;
            *edi = eax;
            if (eax != 0x0 && *(int8_t *)eax != 0x0) {
                    sub_48bbda(0x4b93a0, 0x16, edi);
                    esp = (esp - 0xc) + 0xc;
            }
            ebx = 0x0;
            eax = *esi;
            esi[0x2] = 0x0;
            if (eax != 0x0) {
                    if (*(int8_t *)eax != ebx) {
                            eax = *edi;
                            if (eax != ebx && *(int8_t *)eax != ebx) {
                                    sub_48c0b3();
                            }
                            else {
                                    sub_48c118();
                            }
                            if (esi[0x2] == ebx) {
                                    esp = (esp - 0xc) + 0xc;
                                    if (sub_48bbda(0x4b9198, 0x40, esi) != 0x0) {
                                            edi = *edi;
                                            if (edi != ebx && *(int8_t *)edi != ebx) {
                                                    sub_48c0b3();
                                            }
                                            else {
                                                    sub_48c118();
                                            }
                                    }
                                    if (esi[0x2] != ebx) {
                                            ebx = sub_48bc3a();
                                            switch (ebx) {
                                                case 0:
                                                    eax = 0x0;
                                                    break;
                                                case 65000:
                                                    eax = 0x0;
                                                    break;
                                                case 65001:
                                                    eax = 0x0;
                                                    break;
                                                default:
                                                    esp = esp - 0x4;
                                                    if (IsValidCodePage(ebx & 0xffff) != 0x0) {
                                                            esp = esp - 0x8;
                                                            if (IsValidLocale(esi[0x6], 0x1) != 0x0) {
                                                                    eax = arg_4;
                                                                    if (eax != 0x0) {
                                                                            *(int16_t *)eax = esi[0xc];
                                                                            eax[0x1] = esi[0xe];
                                                                            eax[0x2] = ebx;
                                                                    }
                                                                    edi = arg_8;
                                                                    if (edi != 0x0) {
                                                                            if (*(int16_t *)eax == 0x814) {
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (sub_47db5e(edi, 0x40, "Norwegian-Nynorsk") != 0x0) {
                                                                                            sub_47a828();
                                                                                            esp = (esp - 0x14) + 0x14;
                                                                                    }
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                            sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            eax = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(esi[0x6], 0x1001, edi, 0x40) != 0x0) {
                                                                                            esp = esp - 0x10;
                                                                                            if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                                    sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    eax = 0x1;
                                                                                            }
                                                                                            else {
                                                                                                    eax = 0x0;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    ebx = sub_48bc3a();
                                    switch (ebx) {
                                        case 0:
                                            eax = 0x0;
                                            break;
                                        case 65000:
                                            eax = 0x0;
                                            break;
                                        case 65001:
                                            eax = 0x0;
                                            break;
                                        default:
                                            esp = esp - 0x4;
                                            if (IsValidCodePage(ebx & 0xffff) != 0x0) {
                                                    esp = esp - 0x8;
                                                    if (IsValidLocale(esi[0x6], 0x1) != 0x0) {
                                                            eax = arg_4;
                                                            if (eax != 0x0) {
                                                                    *(int16_t *)eax = esi[0xc];
                                                                    eax[0x1] = esi[0xe];
                                                                    eax[0x2] = ebx;
                                                            }
                                                            edi = arg_8;
                                                            if (edi != 0x0) {
                                                                    if (*(int16_t *)eax == 0x814) {
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (sub_47db5e(edi, 0x40, "Norwegian-Nynorsk") != 0x0) {
                                                                                    sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                    sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = 0x1;
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(esi[0x6], 0x1001, edi, 0x40) != 0x0) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                            sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            eax = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            edi = *edi;
                            if (edi != ebx) {
                                    if (*(int8_t *)edi != ebx) {
                                            eax = sub_47d630(edi);
                                            esp = (esp - 0x4) + 0x4 - 0x8;
                                            esi[0x5] = (-(eax - 0x3) - -(eax - 0x3) + CARRY(EFLAGS(cf))) + 0x1;
                                            EnumSystemLocalesA(sub_48bd1c, 0x1);
                                            if ((esi[0x8] & 0x4) == 0x0) {
                                                    esi[0x2] = ebx;
                                            }
                                    }
                                    else {
                                            esi[0x2] = 0x104;
                                            eax = GetUserDefaultLCID();
                                            esi[0x6] = eax;
                                            esi[0x7] = eax;
                                    }
                            }
                            else {
                                    esi[0x2] = 0x104;
                                    eax = GetUserDefaultLCID();
                                    esi[0x6] = eax;
                                    esi[0x7] = eax;
                            }
                            if (esi[0x2] != ebx) {
                                    ebx = sub_48bc3a();
                                    switch (ebx) {
                                        case 0:
                                            eax = 0x0;
                                            break;
                                        case 65000:
                                            eax = 0x0;
                                            break;
                                        case 65001:
                                            eax = 0x0;
                                            break;
                                        default:
                                            esp = esp - 0x4;
                                            if (IsValidCodePage(ebx & 0xffff) != 0x0) {
                                                    esp = esp - 0x8;
                                                    if (IsValidLocale(esi[0x6], 0x1) != 0x0) {
                                                            eax = arg_4;
                                                            if (eax != 0x0) {
                                                                    *(int16_t *)eax = esi[0xc];
                                                                    eax[0x1] = esi[0xe];
                                                                    eax[0x2] = ebx;
                                                            }
                                                            edi = arg_8;
                                                            if (edi != 0x0) {
                                                                    if (*(int16_t *)eax == 0x814) {
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (sub_47db5e(edi, 0x40, "Norwegian-Nynorsk") != 0x0) {
                                                                                    sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                            }
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                    sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = 0x1;
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(esi[0x6], 0x1001, edi, 0x40) != 0x0) {
                                                                                    esp = esp - 0x10;
                                                                                    if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                            sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            eax = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    edi = *edi;
                    if (edi != 0x0) {
                            if (*(int8_t *)edi != ebx) {
                                    eax = sub_47d630(edi);
                                    esp = (esp - 0x4) + 0x4 - 0x8;
                                    esi[0x5] = (-(eax - 0x3) - -(eax - 0x3) + CARRY(EFLAGS(cf))) + 0x1;
                                    EnumSystemLocalesA(sub_48bd1c, 0x1);
                                    if ((esi[0x8] & 0x4) == 0x0) {
                                            esi[0x2] = ebx;
                                    }
                            }
                            else {
                                    esi[0x2] = 0x104;
                                    eax = GetUserDefaultLCID();
                                    esi[0x6] = eax;
                                    esi[0x7] = eax;
                            }
                    }
                    else {
                            esi[0x2] = 0x104;
                            eax = GetUserDefaultLCID();
                            esi[0x6] = eax;
                            esi[0x7] = eax;
                    }
                    if (esi[0x2] != 0x0) {
                            ebx = sub_48bc3a();
                            switch (ebx) {
                                case 0:
                                    eax = 0x0;
                                    break;
                                case 65000:
                                    eax = 0x0;
                                    break;
                                case 65001:
                                    eax = 0x0;
                                    break;
                                default:
                                    esp = esp - 0x4;
                                    if (IsValidCodePage(ebx & 0xffff) != 0x0) {
                                            esp = esp - 0x8;
                                            if (IsValidLocale(esi[0x6], 0x1) != 0x0) {
                                                    eax = arg_4;
                                                    if (eax != 0x0) {
                                                            *(int16_t *)eax = esi[0xc];
                                                            eax[0x1] = esi[0xe];
                                                            eax[0x2] = ebx;
                                                    }
                                                    edi = arg_8;
                                                    if (edi != 0x0) {
                                                            if (*(int16_t *)eax == 0x814) {
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (sub_47db5e(edi, 0x40, "Norwegian-Nynorsk") != 0x0) {
                                                                            sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                            sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x10;
                                                                    if (GetLocaleInfoA(esi[0x6], 0x1001, edi, 0x40) != 0x0) {
                                                                            esp = esp - 0x10;
                                                                            if (GetLocaleInfoA(esi[0x7], 0x1002, edi + 0x40, 0x40) != 0x0) {
                                                                                    sub_48fefd(ebx, edi + 0x80, 0x10, 0xa);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = 0x1;
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                                    break;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    return eax;
}
