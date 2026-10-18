// sub_47af24 @ 0x47af24
// hopper name: sub_47af24
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47af24() {
    decomp_var_18 = ebx;
    decomp_var_1c = esi;
    esp = esp - 0xc;
    decomp_var_20 = edi;
    edi = arg_0;
    if (edi != 0x0) {
            if (arg_4 > 0x0) {
                    if (edi != 0x0) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_482d93(edi, arg_4) >= arg_4) {
                                    *(int8_t *)edi = 0x0;
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                    eax = 0x16;
                            }
                            else {
                                    ebx = 0x0;
                                    esp = esp - 0x4;
                                    sub_47aea2(arg_8);
                                    esi = edi;
                                    if (*(int8_t *)esi != 0x0) {
                                            while (true) {
                                                    ecx = *(int8_t *)edi;
                                                    eax = (ecx & 0xff) + var_10;
                                                    edx = eax[0x1d];
                                                    if ((edx & 0x4) == 0x0) {
                                                            if ((edx & 0x20) != 0x0) {
                                                                    eax = eax[0x11d];
                                                            }
                                                            else {
                                                                    eax = ecx;
                                                            }
                                                            *(int8_t *)esi = eax;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x1;
                                                            if (*(int8_t *)edi != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    eax = sub_482d50(&var_14, var_10[0x3], 0x200, edi, 0x2, &var_4, 0x2, var_10[0x1], 0x1);
                                                    esp = (esp - 0x24) + 0x24;
                                                    if (eax == ebx) {
                                                            *sub_47d812() = 0x2a;
                                                            *(int8_t *)arg_0 = ebx;
                                                            eax = sub_47d812();
                                                            eax = *eax;
                                                            if (var_8 != ebx) {
                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    temp_0 = 0x2;
                                                            }
                                                            else {
                                                                    temp_0 = 0x0;
                                                            }
                                                            break;
                                                    }
                                                    ecx = var_4;
                                                    *(int8_t *)esi = ecx;
                                                    esi = esi + 0x1;
                                                    edi = edi + 0x1;
                                                    if (eax > 0x1) {
                                                            *(int8_t *)esi = HIBYTE(ecx);
                                                            esi = esi + 0x1;
                                                    }
                                                    edi = edi + 0x1;
                                                    if (*(int8_t *)edi != ebx) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            if (temp_0 != 0x0 && temp_0 == 0x1) {
                                                    *(int8_t *)esi = 0x0;
                                                    if (var_8 != 0x0) {
                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            *(int8_t *)esi = 0x0;
                                            if (var_8 != 0x0) {
                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                    eax = 0x16;
            }
    }
    else {
            if (arg_4 != 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                    eax = 0x16;
            }
            else {
                    if (edi != 0x0) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_482d93(edi, arg_4) >= arg_4) {
                                    ebx = 0x0;
                                    *(int8_t *)edi = 0x0;
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                    eax = 0x16;
                            }
                            else {
                                    ebx = 0x0;
                                    esp = esp - 0x4;
                                    sub_47aea2(arg_8);
                                    esi = edi;
                                    if (*(int8_t *)esi != 0x0) {
                                            while (true) {
                                                    ecx = *(int8_t *)edi;
                                                    eax = (ecx & 0xff) + var_10;
                                                    edx = eax[0x1d];
                                                    if ((edx & 0x4) == 0x0) {
                                                            if ((edx & 0x20) != 0x0) {
                                                                    eax = eax[0x11d];
                                                            }
                                                            else {
                                                                    eax = ecx;
                                                            }
                                                            *(int8_t *)esi = eax;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x1;
                                                            if (*(int8_t *)edi != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    eax = sub_482d50(&var_14, var_10[0x3], 0x200, edi, 0x2, &var_4, 0x2, var_10[0x1], 0x1);
                                                    esp = (esp - 0x24) + 0x24;
                                                    if (eax == ebx) {
                                                            *sub_47d812() = 0x2a;
                                                            *(int8_t *)arg_0 = ebx;
                                                            eax = sub_47d812();
                                                            eax = *eax;
                                                            if (var_8 != ebx) {
                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    temp_0 = 0x2;
                                                            }
                                                            else {
                                                                    temp_0 = 0x0;
                                                            }
                                                            break;
                                                    }
                                                    ecx = var_4;
                                                    *(int8_t *)esi = ecx;
                                                    esi = esi + 0x1;
                                                    edi = edi + 0x1;
                                                    if (eax > 0x1) {
                                                            *(int8_t *)esi = HIBYTE(ecx);
                                                            esi = esi + 0x1;
                                                    }
                                                    edi = edi + 0x1;
                                                    if (*(int8_t *)edi != ebx) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            if (temp_0 != 0x0 && temp_0 == 0x1) {
                                                    *(int8_t *)esi = ebx;
                                                    if (var_8 != ebx) {
                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            *(int8_t *)esi = 0x0;
                                            if (var_8 != 0x0) {
                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    return eax;
}
