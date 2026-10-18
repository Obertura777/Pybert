// sub_480b4d @ 0x480b4d
// hopper name: sub_480b4d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480b4d() {
    esi = arg_0;
    if (*esi != 0x80000003) {
            esp = esp - 0x4;
            decomp_var_10 = edi;
            if (*(sub_480086() + 0x80) != 0x0) {
                    if (*(sub_480086() + 0x80) != sub_47fe73()) {
                            if (*esi != 0xe0434f4d) {
                                    esp = (esp - 0x1c) + 0x1c;
                                    if (sub_47aa91(esi, arg_4, arg_8, arg_c, arg_10, arg_18, arg_1c) == 0x0) {
                                            edi = arg_10;
                                            if (edi[0x3] == 0x0) {
                                                    sub_4810dd();
                                            }
                                            esi = arg_14;
                                            eax = sub_47ac03(edi, arg_18, esi, &var_4, &var_8);
                                            edi = eax;
                                            esp = (esp - 0x14) + 0x14;
                                            if (var_4 < var_8) {
                                                    esp = esp - 0x4;
                                                    decomp_var_14 = ebx;
                                                    do {
                                                            if (esi < *edi) {
                                                                    var_4 = var_4 + 0x1;
                                                                    edi = edi + 0x14;
                                                                    if (var_4 < var_8) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            if (esi > edi[0x1]) {
                                                                    var_4 = var_4 + 0x1;
                                                                    edi = edi + 0x14;
                                                                    if (var_4 < var_8) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = edi[0x3];
                                                            eax = (eax << 0x4) + edi[0x4];
                                                            ecx = *(eax - 0xc);
                                                            if (ecx == 0x0) {
                                                                    if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                                            sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                                            esi = arg_14;
                                                                            esp = (esp - 0x1c) + 0x1c;
                                                                    }
                                                                    var_4 = var_4 + 0x1;
                                                                    edi = edi + 0x14;
                                                                    if (var_4 < var_8) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            if (ecx[0x8] != 0x0) {
                                                                    var_4 = var_4 + 0x1;
                                                                    edi = edi + 0x14;
                                                                    if (var_4 < var_8) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                                    sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                                    esi = arg_14;
                                                                    esp = (esp - 0x1c) + 0x1c;
                                                            }
                                                            var_4 = var_4 + 0x1;
                                                            edi = edi + 0x14;
                                                    } while (var_4 < var_8);
                                                    esp = esp + 0x4;
                                            }
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    edi = arg_10;
                                    if (edi[0x3] == 0x0) {
                                            sub_4810dd();
                                    }
                                    esi = arg_14;
                                    eax = sub_47ac03(edi, arg_18, esi, &var_4, &var_8);
                                    edi = eax;
                                    esp = (esp - 0x14) + 0x14;
                                    if (var_4 < var_8) {
                                            esp = esp - 0x4;
                                            decomp_var_14 = ebx;
                                            do {
                                                    if (esi < *edi) {
                                                            var_4 = var_4 + 0x1;
                                                            edi = edi + 0x14;
                                                            if (var_4 < var_8) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if (esi > edi[0x1]) {
                                                            var_4 = var_4 + 0x1;
                                                            edi = edi + 0x14;
                                                            if (var_4 < var_8) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = edi[0x3];
                                                    eax = (eax << 0x4) + edi[0x4];
                                                    ecx = *(eax - 0xc);
                                                    if (ecx == 0x0) {
                                                            if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                                    sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                                    esi = arg_14;
                                                                    esp = (esp - 0x1c) + 0x1c;
                                                            }
                                                            var_4 = var_4 + 0x1;
                                                            edi = edi + 0x14;
                                                            if (var_4 < var_8) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if (ecx[0x8] != 0x0) {
                                                            var_4 = var_4 + 0x1;
                                                            edi = edi + 0x14;
                                                            if (var_4 < var_8) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                            sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                            esi = arg_14;
                                                            esp = (esp - 0x1c) + 0x1c;
                                                    }
                                                    var_4 = var_4 + 0x1;
                                                    edi = edi + 0x14;
                                            } while (var_4 < var_8);
                                            esp = esp + 0x4;
                                    }
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            edi = arg_10;
                            if (edi[0x3] == 0x0) {
                                    sub_4810dd();
                            }
                            esi = arg_14;
                            eax = sub_47ac03(edi, arg_18, esi, &var_4, &var_8);
                            edi = eax;
                            esp = (esp - 0x14) + 0x14;
                            if (var_4 < var_8) {
                                    esp = esp - 0x4;
                                    decomp_var_14 = ebx;
                                    do {
                                            if (esi < *edi) {
                                                    var_4 = var_4 + 0x1;
                                                    edi = edi + 0x14;
                                                    if (var_4 < var_8) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            if (esi > edi[0x1]) {
                                                    var_4 = var_4 + 0x1;
                                                    edi = edi + 0x14;
                                                    if (var_4 < var_8) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            eax = edi[0x3];
                                            eax = (eax << 0x4) + edi[0x4];
                                            ecx = *(eax - 0xc);
                                            if (ecx == 0x0) {
                                                    if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                            sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                            esi = arg_14;
                                                            esp = (esp - 0x1c) + 0x1c;
                                                    }
                                                    var_4 = var_4 + 0x1;
                                                    edi = edi + 0x14;
                                                    if (var_4 < var_8) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            if (ecx[0x8] != 0x0) {
                                                    var_4 = var_4 + 0x1;
                                                    edi = edi + 0x14;
                                                    if (var_4 < var_8) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                    sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                    esi = arg_14;
                                                    esp = (esp - 0x1c) + 0x1c;
                                            }
                                            var_4 = var_4 + 0x1;
                                            edi = edi + 0x14;
                                    } while (var_4 < var_8);
                                    esp = esp + 0x4;
                            }
                            esp = esp + 0x4;
                    }
            }
            else {
                    edi = arg_10;
                    if (edi[0x3] == 0x0) {
                            sub_4810dd();
                    }
                    esi = arg_14;
                    eax = sub_47ac03(edi, arg_18, esi, &var_4, &var_8);
                    edi = eax;
                    esp = (esp - 0x14) + 0x14;
                    if (var_4 < var_8) {
                            esp = esp - 0x4;
                            decomp_var_14 = ebx;
                            do {
                                    if (esi < *edi) {
                                            var_4 = var_4 + 0x1;
                                            edi = edi + 0x14;
                                            if (var_4 < var_8) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (esi > edi[0x1]) {
                                            var_4 = var_4 + 0x1;
                                            edi = edi + 0x14;
                                            if (var_4 < var_8) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    eax = edi[0x3];
                                    eax = (eax << 0x4) + edi[0x4];
                                    ecx = *(eax - 0xc);
                                    if (ecx == 0x0) {
                                            if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                                    sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                                    esi = arg_14;
                                                    esp = (esp - 0x1c) + 0x1c;
                                            }
                                            var_4 = var_4 + 0x1;
                                            edi = edi + 0x14;
                                            if (var_4 < var_8) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (ecx[0x8] != 0x0) {
                                            var_4 = var_4 + 0x1;
                                            edi = edi + 0x14;
                                            if (var_4 < var_8) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if ((*(int8_t *)(eax - 0x10) & 0x40) == 0x0) {
                                            sub_480ae1(arg_0, arg_8, arg_c, arg_10, 0x0, arg_18, arg_1c);
                                            esi = arg_14;
                                            esp = (esp - 0x1c) + 0x1c;
                                    }
                                    var_4 = var_4 + 0x1;
                                    edi = edi + 0x14;
                            } while (var_4 < var_8);
                            esp = esp + 0x4;
                    }
                    esp = esp + 0x4;
            }
    }
    return;
}
