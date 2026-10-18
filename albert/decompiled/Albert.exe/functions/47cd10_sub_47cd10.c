// sub_47cd10 @ 0x47cd10
// hopper name: sub_47cd10
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47cd10() {
    decomp_var_18 = ebx;
    ebx = arg_4;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    esi = ebx[0x2];
    esi = esi ^ *dword_4c8db8;
    esp = esp - 0x24;
    decomp_var_24 = edi;
    eax = *esi;
    var_11 = 0x0;
    var_C = 0x1;
    edi = ebx + 0x10;
    if (eax != 0xfffffffe) {
            sub_47ad69();
    }
    sub_47ad69();
    eax = arg_0;
    if ((eax[0x4] & 0x66) == 0x0) {
            ebp = ebx[0x3];
            var_8 = eax;
            *(ebx - 0x4) = &var_8;
            if (ebp != 0xfffffffe) {
                    while (true) {
                            ecx = *(esi + (ebp + ebp * 0x2) * 0x4 + 0x14);
                            ebx = esi + (ebp + ebp * 0x2) * 0x4 + 0x10;
                            eax = *ebx;
                            var_10 = eax;
                            if (ecx == 0x0) {
                                    ebp = eax;
                                    if (eax != 0xfffffffe) {
                                            continue;
                                    }
                                    if (var_11 != 0x0) {
                                            temp_0 = 0x0;
                                    }
                                    else {
                                            temp_0 = 0x1;
                                    }
                                    break;
                            }
                            eax = sub_487142();
                            bool_9 = eax > 0x0;
                            var_11 = 0x1;
                            if (eax < 0x0) {
                                    var_C = 0x0;
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (bool_9) {
                                    if (*arg_0 == 0xe06d7363) {
                                            if (sub_4805e7 != 0x0) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_488b62() != 0x0) {
                                                            sub_4805e7();
                                                            esp = (esp - 0x8) + 0x8;
                                                            temp_0 = 0x4;
                                                    }
                                                    else {
                                                            temp_0 = 0x3;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x2;
                                            }
                                    }
                                    else {
                                            temp_0 = 0x2;
                                    }
                                    break;
                            }
                            eax = var_10;
                            ebp = eax;
                            if (eax != 0xfffffffe) {
                                    continue;
                            }
                            if (var_11 != 0x0) {
                                    temp_0 = 0x0;
                            }
                            else {
                                    temp_0 = 0x1;
                            }
                            break;
                    }
                    switch (temp_0) {
                        case 0:
                            eax = *esi;
                            if (eax != 0xfffffffe) {
                                    sub_47ad69();
                            }
                            sub_47ad69();
                            eax = var_C;
                            break;
                        case 1:
                            eax = var_C;
                            break;
                        default:
                            sub_487172();
                            eax = arg_c;
                            if (eax[0x3] != ebp) {
                                    esp = esp - 0x8;
                                    sub_48718c(edi, dword_4c8db8);
                                    eax = arg_c;
                            }
                            eax[0x3] = var_8;
                            eax = *esi;
                            if (eax != 0xfffffffe) {
                                    sub_47ad69();
                            }
                            sub_47ad69();
                            ecx = ebx[0x2];
                            edx = edi;
                            sub_48aa45(0x1);
                            eax = (ecx)();
                            break;
                    }
            }
            else {
                    eax = var_C;
            }
    }
    else {
            if (ebx[0x3] != 0xfffffffe) {
                    esp = esp - 0x8;
                    sub_48718c(edi, dword_4c8db8);
                    eax = *esi;
                    if (eax != 0xfffffffe) {
                            sub_47ad69();
                    }
                    sub_47ad69();
                    eax = var_C;
            }
            else {
                    eax = var_C;
            }
    }
    return eax;
}
