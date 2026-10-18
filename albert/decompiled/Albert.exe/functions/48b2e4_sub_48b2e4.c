// sub_48b2e4 @ 0x48b2e4
// hopper name: sub_48b2e4
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48b2e4() {
    decomp_var_1c = ebx;
    ebx = arg_0;
    decomp_var_20 = esi;
    esp = esp - 0xc;
    decomp_var_24 = edi;
    var_18 = ebx;
    if (ebx[0x7] == 0x0) {
            if (ebx[0x6] == 0x0) {
                    var_4 = 0x0;
                    var_8 = 0x0;
                    arg_0 = dword_4c8de4;
                    eax = ebx[0x2d];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            InterlockedDecrement(eax);
                    }
                    eax = ebx[0x2c];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(eax) == 0x0) {
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x8;
                            }
                    }
                    ebx[0x2d] = var_4;
                    ebx[0x2c] = var_8;
                    ebx[0x2f] = arg_0;
                    eax = 0x0;
            }
            else {
                    edi = sub_4812c0(0x1, 0x30);
                    bool_27 = true;
                    esp = (esp - 0x8) + 0x8;
                    arg_0 = edi;
                    if (edi == 0x0) {
                            eax = 0x1;
                    }
                    else {
                            *edi = *ebx[0x2f];
                            eax = sub_481280(0x4);
                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                            var_8 = eax;
                            if (eax == 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                                    eax = 0x1;
                            }
                            else {
                                    *eax = 0x0;
                                    if (ebx[0x7] != 0x0) {
                                            eax = sub_481280(0x4);
                                            esp = (esp - 0x4) + 0x4;
                                            var_4 = eax;
                                            if (eax == 0x0) {
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x8;
                                                    eax = 0x1;
                                            }
                                            else {
                                                    *eax = 0x0;
                                                    esi = arg_0;
                                                    decomp_var_28 = esi;
                                                    var_10 = esi + 0x8;
                                                    esp = (esp - 0x3c) + 0x3c;
                                                    if ((sub_4896f8() | sub_4896f8() | sub_4896f8()) != 0x0) {
                                                            sub_48b2a4(esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                            esi = esi | 0xffffffff;
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x8;
                                                            eax = esi;
                                                    }
                                                    else {
                                                            eax = *var_10;
                                                            while (*(int8_t *)eax != 0x0) {
                                                                    ecx = *(int8_t *)eax;
                                                                    if (ecx < 0x30) {
                                                                            if (ecx == 0x3b) {
                                                                                    esi = eax;
                                                                                    do {
                                                                                            *(int8_t *)esi = esi[0x1];
                                                                                            esi = esi + 0x1;
                                                                                    } while (*(int8_t *)esi != 0x0);
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x1;
                                                                            }
                                                                            continue;
                                                                    }
                                                                    if (ecx <= 0x39) {
                                                                            *(int8_t *)eax = ecx - 0x30;
                                                                            eax = eax + 0x1;
                                                                            continue;
                                                                    }
                                                                    if (ecx == 0x3b) {
                                                                            esi = eax;
                                                                            do {
                                                                                    *(int8_t *)esi = esi[0x1];
                                                                                    esi = esi + 0x1;
                                                                            } while (*(int8_t *)esi != 0x0);
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x1;
                                                                    }
                                                            }
                                                            *var_8 = 0x1;
                                                            eax = var_4;
                                                            if (eax != 0x0) {
                                                                    *eax = 0x1;
                                                            }
                                                            eax = ebx[0x2d];
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    InterlockedDecrement(eax);
                                                            }
                                                            eax = ebx[0x2c];
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (InterlockedDecrement(eax) == 0x0) {
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x8;
                                                                    }
                                                            }
                                                            ebx[0x2d] = var_4;
                                                            ebx[0x2c] = var_8;
                                                            ebx[0x2f] = arg_0;
                                                            eax = 0x0;
                                                    }
                                            }
                                    }
                                    else {
                                            *arg_0 = *dword_4c8de4;
                                            arg_0[0x1] = *dword_4c8de8;
                                            var_4 = 0x0;
                                            arg_0[0x2] = *dword_4c8dec;
                                            *var_8 = 0x1;
                                            eax = var_4;
                                            if (eax != 0x0) {
                                                    *eax = 0x1;
                                            }
                                            eax = ebx[0x2d];
                                            if (eax != 0x0) {
                                                    esp = esp - 0x4;
                                                    InterlockedDecrement(eax);
                                            }
                                            eax = ebx[0x2c];
                                            if (eax != 0x0) {
                                                    esp = esp - 0x4;
                                                    if (InterlockedDecrement(eax) == 0x0) {
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x8;
                                                    }
                                            }
                                            ebx[0x2d] = var_4;
                                            ebx[0x2c] = var_8;
                                            ebx[0x2f] = arg_0;
                                            eax = 0x0;
                                    }
                            }
                    }
            }
    }
    else {
            edi = sub_4812c0(0x1, 0x30);
            bool_6 = true;
            esp = (esp - 0x8) + 0x8;
            arg_0 = edi;
            if (edi == 0x0) {
                    eax = 0x1;
            }
            else {
                    *edi = *ebx[0x2f];
                    eax = sub_481280(0x4);
                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                    var_8 = eax;
                    if (eax == 0x0) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                            eax = 0x1;
                    }
                    else {
                            *eax = 0x0;
                            if (ebx[0x7] != 0x0) {
                                    esi = 0x0;
                                    eax = sub_481280(0x4);
                                    esp = (esp - 0x4) + 0x4;
                                    var_4 = eax;
                                    if (eax == 0x0) {
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            esp = (esp - 0x8) + 0x8;
                                            eax = 0x1;
                                    }
                                    else {
                                            *eax = esi;
                                            esi = arg_0;
                                            decomp_var_28 = esi;
                                            var_10 = esi + 0x8;
                                            esp = (esp - 0x3c) + 0x3c;
                                            if ((sub_4896f8() | sub_4896f8() | sub_4896f8()) != 0x0) {
                                                    sub_48b2a4(esi);
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = esi | 0xffffffff;
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x8;
                                                    eax = esi;
                                            }
                                            else {
                                                    eax = *var_10;
                                                    while (*(int8_t *)eax != 0x0) {
                                                            ecx = *(int8_t *)eax;
                                                            if (ecx >= 0x30) {
                                                                    if (ecx <= 0x39) {
                                                                            *(int8_t *)eax = ecx - 0x30;
                                                                            eax = eax + 0x1;
                                                                            continue;
                                                                    }
                                                                    if (ecx == 0x3b) {
                                                                            esi = eax;
                                                                            do {
                                                                                    *(int8_t *)esi = esi[0x1];
                                                                                    esi = esi + 0x1;
                                                                            } while (*(int8_t *)esi != 0x0);
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x1;
                                                                    }
                                                                    continue;
                                                            }
                                                            if (ecx == 0x3b) {
                                                                    esi = eax;
                                                                    do {
                                                                            *(int8_t *)esi = esi[0x1];
                                                                            esi = esi + 0x1;
                                                                    } while (*(int8_t *)esi != 0x0);
                                                            }
                                                            else {
                                                                    eax = eax + 0x1;
                                                            }
                                                    }
                                                    *var_8 = 0x1;
                                                    eax = var_4;
                                                    if (eax != 0x0) {
                                                            *eax = 0x1;
                                                    }
                                                    eax = ebx[0x2d];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            InterlockedDecrement(eax);
                                                    }
                                                    eax = ebx[0x2c];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            if (InterlockedDecrement(eax) == 0x0) {
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x8;
                                                            }
                                                    }
                                                    ebx[0x2d] = var_4;
                                                    ebx[0x2c] = var_8;
                                                    ebx[0x2f] = arg_0;
                                                    eax = 0x0;
                                            }
                                    }
                            }
                            else {
                                    *arg_0 = *dword_4c8de4;
                                    arg_0[0x1] = *dword_4c8de8;
                                    var_4 = 0x0;
                                    arg_0[0x2] = *dword_4c8dec;
                                    *var_8 = 0x1;
                                    eax = var_4;
                                    if (eax != 0x0) {
                                            *eax = 0x1;
                                    }
                                    eax = ebx[0x2d];
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            InterlockedDecrement(eax);
                                    }
                                    eax = ebx[0x2c];
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            if (InterlockedDecrement(eax) == 0x0) {
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x8;
                                            }
                                    }
                                    ebx[0x2d] = var_4;
                                    ebx[0x2c] = var_8;
                                    ebx[0x2f] = arg_0;
                                    eax = 0x0;
                            }
                    }
            }
    }
    return eax;
}
