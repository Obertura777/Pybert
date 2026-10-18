// sub_47f375 @ 0x47f375
// hopper name: sub_47f375
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f375() {
    decomp_var_18 = ebx;
    esp = esp - 0x8;
    sub_47aea2(arg_8);
    if (arg_0 == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            if (var_8 != 0x0) {
                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
            }
    }
    else {
            esp = esp - 0x4;
            decomp_var_1c = esi;
            esi = arg_4;
            if (esi == 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    if (var_8 != 0x0) {
                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                    }
            }
            else {
                    ebx = 0x0;
                    esp = esp - 0x4;
                    decomp_var_20 = edi;
                    edi = var_10;
                    if (edi[0x2] == 0x0) {
                            sub_47fd80(arg_0, esi);
                            esp = (esp - 0x8) + 0x8;
                            if (var_8 != ebx) {
                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                            }
                    }
                    else {
                            while (true) {
                                    ecx = *(int8_t *)arg_0 & 0xff;
                                    ecx = ecx & 0xffff;
                                    eax = arg_0 + 0x1;
                                    arg_0 = eax;
                                    if ((*(int8_t *)((ecx & 0xff) + edi + 0x1d) & 0x4) != 0x0) {
                                            eax = *(int8_t *)eax;
                                            if (eax == ebx) {
                                                    ecx = 0x0;
                                            }
                                            else {
                                                    arg_0 = arg_0 + 0x1;
                                                    ecx = eax & 0xffff;
                                            }
                                    }
                                    eax = *(int8_t *)esi & 0xff;
                                    eax = eax & 0xffff;
                                    esi = esi + 0x1;
                                    if ((*(int8_t *)((eax & 0xff) + edi + 0x1d) & 0x4) != 0x0) {
                                            edx = *(int8_t *)esi;
                                            var_1 = edx;
                                            if (edx == ebx) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    esi = esi + 0x1;
                                                    eax = var_1 & 0xffff;
                                            }
                                    }
                                    bool_9 = true;
                                    if (eax != ecx) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    if (ecx != ebx) {
                                            continue;
                                    }
                                    if (var_8 != ebx) {
                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                            temp_0 = 0x0;
                                    }
                                    else {
                                            temp_0 = 0x0;
                                    }
                                    break;
                            }
                            if (temp_0 != 0x0 && var_8 != ebx) {
                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                            }
                    }
                    esp = esp + 0x4;
            }
            esp = esp + 0x4;
    }
    return;
}
