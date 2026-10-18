// sub_469d10 @ 0x469d10
// hopper name: sub_469d10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_469d10() {
    var_C = *0x0;
    var_10 = *dword_4c8db8 ^ &var_50;
    decomp_var_54 = ebx;
    decomp_var_58 = ebp;
    decomp_var_5c = esi;
    decomp_var_60 = edi;
    decomp_var_64 = *dword_4c8db8 ^ &decomp_var_60;
    *0x0 = &var_C;
    ebx = arg_1c;
    var_3C = arg_4;
    var_48 = arg_14;
    eax = sub_465800(&var_40);
    ebp = var_40;
    esp = (esp - 0x6c) + 0x4;
    esi = sub_469210(eax);
    var_44 = esi;
    if (ebp != 0x0) {
            esp = esp - 0x4;
            sub_4931ea(0x0);
            eax = arg_0;
            if (eax > 0x0 && eax < 0xffffffff) {
                    arg_0 = eax - 0x1;
            }
            edi = !(-arg_0 - -arg_0 + CARRY(EFLAGS(cf))) & ebp;
            sub_49320b();
            if (edi != 0x0) {
                    esp = esp - 0x4;
                    (**edi)(0x1);
            }
    }
    esp = esp - 0x4;
    sub_468bc0(&var_2C);
    eax = *(int8_t *)ebx;
    if (eax != 0x2b && eax != 0x2d) {
            if (eax == 0x30) {
                    eax = ebx[0x1];
                    if (eax != 0x78 && eax != 0x58) {
                            var_50 = 0x0;
                    }
                    else {
                            var_50 = 0x2;
                    }
            }
            else {
                    var_50 = 0x0;
            }
    }
    else {
            var_50 = 0x1;
    }
    ecx = var_14;
    edx = var_28;
    eax = edx;
    if (ecx < 0x10) {
            eax = &var_28;
    }
    if (*(int8_t *)eax != 0x7f) {
            eax = edx;
            if (ecx < 0x10) {
                    eax = &var_28;
            }
            if (*(int8_t *)eax > 0x0) {
                    if (ecx >= 0x10) {
                            var_4C = edx;
                    }
                    else {
                            var_4C = &var_28;
                    }
                    eax = *(int8_t *)var_4C;
                    ebp = arg_20;
                    esi = ebp;
                    if (eax != 0x7f) {
                            while (true) {
                                    if (eax <= 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    eax = sign_extend_32(eax);
                                    if (eax >= esi - var_50) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    esi = esi - eax;
                                    sub_47a62a(ebx + esi + 0x1, (ebp - esi) + 0x1, ebx + esi, (ebp - esi) + 0x1);
                                    eax = var_4C;
                                    esp = (esp - 0x10) + 0x10;
                                    *(int8_t *)(ebx + esi) = 0x0;
                                    ebp = &arg_fffffffffffffffd;
                                    if (eax[0x1] > 0x0) {
                                            eax = eax + 0x1;
                                            var_4C = eax;
                                    }
                                    eax = *(int8_t *)eax;
                                    if (eax != 0x7f) {
                                            continue;
                                    }
                                    temp_0 = 0x2;
                                    break;
                            }
                    }
            }
            else {
                    ebp = arg_20;
            }
    }
    else {
            ebp = arg_20;
    }
    ecx = var_48;
    edi = ecx[0x6];
    if (edi > 0x0 && edi > ebp) {
            edi = edi - ebp;
    }
    else {
            edi = 0x0;
    }
    esi = arg_0;
    eax = ecx[0x4];
    eax = eax & 0x1c0;
    if (eax != 0x40) {
            if (eax != 0x100) {
                    decomp_var_78 = arg_8;
                    decomp_var_7c = &var_38;
                    esp = esp - 0x1c;
                    eax = sub_468930(esi, decomp_var_7c, decomp_var_78, arg_c, arg_10, arg_18, edi);
                    arg_8 = *eax;
                    arg_c = eax[0x1];
                    arg_10 = eax[0x2];
            }
            else {
                    decomp_var_78 = arg_8;
                    eax = sub_4688b0(esi, &var_38, decomp_var_78, arg_c, arg_10, ebx, var_50);
                    ebx = ebx + var_50;
                    ebp = ebp - var_50;
                    decomp_var_78 = *eax;
                    decomp_var_7c = &var_38;
                    esp = (esp - 0x1c) + 0x1c - 0x1c;
                    eax = sub_468930(esi, decomp_var_7c, decomp_var_78, eax[0x1], eax[0x2], arg_18, edi);
                    arg_8 = *eax;
                    arg_c = eax[0x1];
                    arg_10 = eax[0x2];
            }
            esp = esp + 0x1c;
            edi = 0x0;
    }
    eax = (*(*var_44 + 0x8))();
    decomp_var_7c = arg_8;
    eax = sub_4689b0(esi, &var_38, decomp_var_7c, arg_c, arg_10, ebx, ebp, eax);
    edx = *eax;
    ebx = eax[0x1];
    eax = eax[0x2];
    decomp_var_68 = edi;
    edi = var_3C;
    var_48[0x6] = 0x0;
    decomp_var_78 = edx;
    sub_468930(esi, edi, decomp_var_78, ebx, eax, arg_18, decomp_var_68);
    esp = ((esp - 0x20) + 0x20 - 0x1c) + 0x1c;
    if (var_14 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = var_C;
    eax = sub_47ad69();
    return eax;
}
