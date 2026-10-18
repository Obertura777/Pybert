// sub_4816cf @ 0x4816cf
// hopper name: sub_4816cf
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4816cf() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_24 = ebx;
    ebx = arg_4;
    decomp_var_28 = esi;
    esp = esp - 0xc;
    decomp_var_2c = edi;
    edi = sub_481655();
    arg_0 = edi;
    if (edi == 0x0) {
            sub_4813d2();
            eax = sub_47ad69();
    }
    else {
            var_1C = 0x0;
            eax = 0x0;
            while (true) {
                    if (eax[0x132508] == edi) {
                            sub_47ba40(ebx + 0x1c, 0x0, 0x101);
                            esp = (esp - 0xc) + 0xc;
                            ecx = var_1C * 0x30;
                            var_20 = 0x0;
                            esi = ecx + 0x4c9430;
                            var_1C = esi;
                            do {
                                    if (*(int8_t *)esi != 0x0) {
                                            eax = esi[0x1];
                                            if (eax != 0x0) {
                                                    edi = *(int8_t *)esi & 0xff;
                                                    eax = eax & 0xff;
                                                    while (edi <= eax) {
                                                            *(int8_t *)(ebx + edi + 0x1d) = *(int8_t *)(ebx + edi + 0x1d) | var_20[0x4c941c];
                                                            eax = esi[0x1] & 0xff;
                                                            edi = edi + 0x1;
                                                    }
                                                    edi = arg_0;
                                                    esi = esi + 0x2;
                                                    continue;
                                            }
                                            var_20 = var_20 + 0x1;
                                            esi = var_1C + 0x8;
                                            var_1C = esi;
                                            if (var_20 < 0x4) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    var_20 = var_20 + 0x1;
                                    esi = var_1C + 0x8;
                                    var_1C = esi;
                            } while (var_20 < 0x4);
                            ebx[0x1] = edi;
                            ebx[0x2] = 0x1;
                            ebx[0x3] = sub_4813a3();
                            eax = ebx + 0x10;
                            ecx = ecx + 0x4c9424;
                            edx = 0x6;
                            esp = (esp - 0x4) + 0x4;
                            temp_1 = 0x2;
                            break;
                    }
                    var_1C = var_1C + 0x1;
                    eax = eax + 0x30;
                    if (eax < 0xf0) {
                            continue;
                    }
                    esp = esp - 0x8;
                    eax = GetCPInfo(edi, &var_18);
                    if (eax != 0x0) {
                            eax = sub_47ba40(ebx + 0x1c, 0x0, 0x101);
                            edx = 0x1;
                            esp = (esp - 0xc) + 0xc;
                            ebx[0x1] = edi;
                            ebx[0x3] = 0x0;
                            if (var_18 > 0x1) {
                                    bool_6 = true;
                                    bool_5 = true;
                                    bool_4 = true;
                                    if (var_12 != 0x0) {
                                            esi = &var_11;
                                            while (true) {
                                                    ecx = *(int8_t *)esi;
                                                    if (ecx == 0x0) {
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    eax = *(int8_t *)(esi - 0x1) & 0xff;
                                                    ecx = ecx & 0xff;
                                                    while (eax <= ecx) {
                                                            *(int8_t *)(ebx + eax + 0x1d) = *(int8_t *)(ebx + eax + 0x1d) | 0x4;
                                                            eax = eax + 0x1;
                                                    }
                                                    esi = esi + 0x2;
                                                    if (*(int8_t *)(esi - 0x1) != 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            if (temp_0 != 0x0) {
                                                    temp_1 = 0x3;
                                            }
                                            else {
                                                    temp_1 = 0x0;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x0;
                                    }
                            }
                            else {
                                    ebx[0x2] = 0x0;
                                    temp_1 = 0x4;
                            }
                    }
                    else {
                            if (*dword_bc6850 == 0x0) {
                                    eax = eax | 0xffffffff;
                                    temp_1 = 0x5;
                            }
                            else {
                                    temp_1 = 0x1;
                            }
                    }
                    break;
            }
            switch (temp_1) {
                case 0:
                    eax = ebx + 0x1e;
                    ecx = 0xfe;
                    do {
                            *(int8_t *)eax = *(int8_t *)eax | 0x8;
                            eax = eax + 0x1;
                            ecx = ecx - 0x1;
                            bool_3 = true;
                            bool_2 = true;
                            bool_1 = true;
                    } while (ecx != 0x0);
                    ebx[0x3] = sub_4813a3();
                    ebx[0x2] = edx;
                    eax = 0x0;
                    edi = ebx + 0x10;
                    asm { stosd      dword [edi], eax };
                    asm { stosd      dword [edi], eax };
                    asm { stosd      dword [edi], eax };
                    sub_481427();
                    eax = sub_47ad69();
                    break;
                case 1:
                    sub_4813d2();
                    eax = sub_47ad69();
                    break;
                case 2:
                    do {
                            *(int16_t *)eax = *(int16_t *)ecx;
                            ecx = ecx + 0x2;
                            eax = eax + 0x2;
                            edx = edx - 0x1;
                    } while (edx != 0x0);
                    sub_481427();
                    eax = sub_47ad69();
                    break;
                case 3:
                    eax = ebx + 0x1e;
                    ecx = 0xfe;
                    do {
                            *(int8_t *)eax = *(int8_t *)eax | 0x8;
                            eax = eax + 0x1;
                            ecx = ecx - 0x1;
                            bool_9 = true;
                            bool_8 = true;
                            bool_7 = true;
                    } while (ecx != 0x0);
                    ebx[0x3] = sub_4813a3();
                    ebx[0x2] = edx;
                    eax = 0x0;
                    edi = ebx + 0x10;
                    asm { stosd      dword [edi], eax };
                    asm { stosd      dword [edi], eax };
                    asm { stosd      dword [edi], eax };
                    sub_481427();
                    eax = sub_47ad69();
                    break;
                default:
                    if (temp_1 == 0x4) {
                            eax = 0x0;
                            edi = ebx + 0x10;
                            asm { stosd      dword [edi], eax };
                            asm { stosd      dword [edi], eax };
                            asm { stosd      dword [edi], eax };
                            sub_481427();
                    }
                    eax = sub_47ad69();
                    break;
            }
    }
    return eax;
}
