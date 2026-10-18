// sub_481e86 @ 0x481e86
// hopper name: sub_481e86
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481e86() {
    edi = arg_0;
    sub_47ba40(edi, 0x0, 0x90);
    esi = arg_4;
    eax = *(int8_t *)esi;
    esp = (esp - 0xc) + 0xc;
    if (eax == 0x0) {
            eax = 0x0;
    }
    else {
            bool_32 = eax != 0x2e;
            if (eax == 0x2e) {
                    eax = esi + 0x1;
                    bool_18 = *(int8_t *)eax != 0x0;
                    if (*(int8_t *)eax != 0x0) {
                            esp = (esp - 0x10) + 0x10;
                            if (sub_47f4a4(edi + 0x80, 0x10, eax, 0xf) != 0x0) {
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            edi[0x8f] = 0x0;
                            eax = 0x0;
                    }
                    else {
                            decomp_var_10 = 0x4b3b48;
                            esp = esp - 0x8;
                            decomp_var_14 = esi;
                            arg_4 = 0x0;
                            eax = sub_47d320(decomp_var_14, 0x4b3b48);
                            while (true) {
                                    esp = esp + 0x8;
                                    if (!bool_18) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    else {
                                            edi = eax + esi;
                                            ebx = *(int8_t *)edi;
                                            if (arg_4 == 0x0) {
                                                    if (eax < 0x40) {
                                                            if (ebx != 0x2e) {
                                                                    decomp_var_10 = eax;
                                                                    decomp_var_14 = esi;
                                                                    decomp_var_18 = 0x40;
                                                                    esp = esp - 0x10;
                                                                    decomp_var_1c = arg_0;
                                                                    eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                    esp = esp + 0x10;
                                                                    if (eax != 0x0) {
                                                                            eax = sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    if (ebx != 0x2c) {
                                                                            if (ebx != 0x0) {
                                                                                    arg_4 = arg_4 + 0x1;
                                                                                    esi = edi + 0x1;
                                                                                    decomp_var_10 = 0x4b3b48;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_14 = esi;
                                                                                    eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x7;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (arg_4 == 0x1) {
                                                            if (eax < 0x40) {
                                                                    if (ebx != 0x5f) {
                                                                            decomp_var_10 = eax;
                                                                            decomp_var_14 = esi;
                                                                            esp = esp - 0xc;
                                                                            decomp_var_18 = 0x40;
                                                                            eax = arg_0 + 0x40;
                                                                            esp = esp - 0x4;
                                                                            decomp_var_1c = eax;
                                                                            eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                            esp = esp + 0x10;
                                                                            if (eax != 0x0) {
                                                                                    eax = sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                            }
                                                                            if (ebx != 0x2c) {
                                                                                    if (ebx != 0x0) {
                                                                                            arg_4 = arg_4 + 0x1;
                                                                                            esi = edi + 0x1;
                                                                                            decomp_var_10 = 0x4b3b48;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_14 = esi;
                                                                                            eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x0;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x7;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x4;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (arg_4 == 0x2) {
                                                                    if (eax < 0x10) {
                                                                            if (ebx != 0x0) {
                                                                                    if (ebx == 0x2c) {
                                                                                            decomp_var_10 = eax;
                                                                                            decomp_var_14 = esi;
                                                                                            esp = esp - 0xc;
                                                                                            decomp_var_18 = 0x10;
                                                                                            eax = arg_0 + 0x80;
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_1c = eax;
                                                                                            eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                                            esp = esp + 0x10;
                                                                                            if (eax != 0x0) {
                                                                                                    eax = sub_47a828();
                                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                            }
                                                                                            if (ebx != 0x2c) {
                                                                                                    if (ebx != 0x0) {
                                                                                                            arg_4 = arg_4 + 0x1;
                                                                                                            esi = edi + 0x1;
                                                                                                            decomp_var_10 = 0x4b3b48;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_14 = esi;
                                                                                                            eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x7;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x8;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    decomp_var_10 = eax;
                                                                                    decomp_var_14 = esi;
                                                                                    esp = esp - 0xc;
                                                                                    decomp_var_18 = 0x10;
                                                                                    eax = arg_0 + 0x80;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_1c = eax;
                                                                                    eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                                    esp = esp + 0x10;
                                                                                    if (eax != 0x0) {
                                                                                            eax = sub_47a828();
                                                                                            esp = (esp - 0x14) + 0x14;
                                                                                    }
                                                                                    if (ebx != 0x2c) {
                                                                                            if (ebx != 0x0) {
                                                                                                    arg_4 = arg_4 + 0x1;
                                                                                                    esi = edi + 0x1;
                                                                                                    decomp_var_10 = 0x4b3b48;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_14 = esi;
                                                                                                    eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x7;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x6;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x5;
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                            }
                            switch (temp_0) {
                                case 0:
                                    eax = 0x0;
                                    break;
                                case 1:
                                    eax = eax | 0xffffffff;
                                    break;
                                case 2:
                                    eax = eax | 0xffffffff;
                                    break;
                                case 3:
                                    eax = eax | 0xffffffff;
                                    break;
                                case 4:
                                    eax = eax | 0xffffffff;
                                    break;
                                case 5:
                                    eax = eax | 0xffffffff;
                                    break;
                                case 6:
                                    eax = eax | 0xffffffff;
                                    break;
                                case 7:
                                    eax = 0x0;
                                    break;
                                default:
                                    eax = eax | 0xffffffff;
                                    break;
                            }
                    }
            }
            else {
                    decomp_var_10 = 0x4b3b48;
                    esp = esp - 0x8;
                    decomp_var_14 = esi;
                    arg_4 = 0x0;
                    eax = sub_47d320(decomp_var_14, 0x4b3b48);
                    while (true) {
                            esp = esp + 0x8;
                            if (!bool_32) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            else {
                                    edi = eax + esi;
                                    ebx = *(int8_t *)edi;
                                    if (arg_4 == 0x0) {
                                            if (eax < 0x40) {
                                                    if (ebx != 0x2e) {
                                                            decomp_var_10 = eax;
                                                            decomp_var_14 = esi;
                                                            decomp_var_18 = 0x40;
                                                            esp = esp - 0x10;
                                                            decomp_var_1c = arg_0;
                                                            eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                            esp = esp + 0x10;
                                                            if (eax != 0x0) {
                                                                    eax = sub_47a828();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            if (ebx != 0x2c) {
                                                                    if (ebx != 0x0) {
                                                                            arg_4 = arg_4 + 0x1;
                                                                            esi = edi + 0x1;
                                                                            decomp_var_10 = 0x4b3b48;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_14 = esi;
                                                                            eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_0 = 0x7;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (arg_4 == 0x1) {
                                                    if (eax < 0x40) {
                                                            if (ebx != 0x5f) {
                                                                    decomp_var_10 = eax;
                                                                    decomp_var_14 = esi;
                                                                    esp = esp - 0xc;
                                                                    decomp_var_18 = 0x40;
                                                                    eax = arg_0 + 0x40;
                                                                    esp = esp - 0x4;
                                                                    decomp_var_1c = eax;
                                                                    eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                    esp = esp + 0x10;
                                                                    if (eax != 0x0) {
                                                                            eax = sub_47a828();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                    }
                                                                    if (ebx != 0x2c) {
                                                                            if (ebx != 0x0) {
                                                                                    arg_4 = arg_4 + 0x1;
                                                                                    esi = edi + 0x1;
                                                                                    decomp_var_10 = 0x4b3b48;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_14 = esi;
                                                                                    eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x7;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x4;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (arg_4 == 0x2) {
                                                            if (eax < 0x10) {
                                                                    if (ebx != 0x0) {
                                                                            if (ebx == 0x2c) {
                                                                                    decomp_var_10 = eax;
                                                                                    decomp_var_14 = esi;
                                                                                    esp = esp - 0xc;
                                                                                    decomp_var_18 = 0x10;
                                                                                    eax = arg_0 + 0x80;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_1c = eax;
                                                                                    eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                                    esp = esp + 0x10;
                                                                                    if (eax != 0x0) {
                                                                                            eax = sub_47a828();
                                                                                            esp = (esp - 0x14) + 0x14;
                                                                                    }
                                                                                    if (ebx != 0x2c) {
                                                                                            if (ebx != 0x0) {
                                                                                                    arg_4 = arg_4 + 0x1;
                                                                                                    esi = edi + 0x1;
                                                                                                    decomp_var_10 = 0x4b3b48;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_14 = esi;
                                                                                                    eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x7;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x8;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            decomp_var_10 = eax;
                                                                            decomp_var_14 = esi;
                                                                            esp = esp - 0xc;
                                                                            decomp_var_18 = 0x10;
                                                                            eax = arg_0 + 0x80;
                                                                            esp = esp - 0x4;
                                                                            decomp_var_1c = eax;
                                                                            eax = sub_47f4a4(decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                                                                            esp = esp + 0x10;
                                                                            if (eax != 0x0) {
                                                                                    eax = sub_47a828();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                            }
                                                                            if (ebx != 0x2c) {
                                                                                    if (ebx != 0x0) {
                                                                                            arg_4 = arg_4 + 0x1;
                                                                                            esi = edi + 0x1;
                                                                                            decomp_var_10 = 0x4b3b48;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_14 = esi;
                                                                                            eax = sub_47d320(decomp_var_14, 0x4b3b48);
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x0;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x7;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x6;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x5;
                                                            break;
                                                    }
                                            }
                                    }
                            }
                    }
                    switch (temp_0) {
                        case 0:
                            eax = 0x0;
                            break;
                        case 1:
                            eax = eax | 0xffffffff;
                            break;
                        case 2:
                            eax = eax | 0xffffffff;
                            break;
                        case 3:
                            eax = eax | 0xffffffff;
                            break;
                        case 4:
                            eax = eax | 0xffffffff;
                            break;
                        case 5:
                            eax = eax | 0xffffffff;
                            break;
                        case 6:
                            eax = eax | 0xffffffff;
                            break;
                        case 7:
                            eax = 0x0;
                            break;
                        default:
                            eax = eax | 0xffffffff;
                            break;
                    }
            }
    }
    return eax;
}
