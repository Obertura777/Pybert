// sub_48b535 @ 0x48b535
// hopper name: sub_48b535
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48b535() {
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_1c = edi;
    var_4 = 0x0;
    var_10 = esi;
    if (esi[0x6] == 0x0) {
            if (esi[0x7] == 0x0) {
                    var_4 = 0x0;
                    var_8 = 0x0;
                    eax = esi[0x2e];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            InterlockedDecrement(eax);
                    }
                    eax = esi[0x2c];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(eax) == 0x0) {
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x8;
                            }
                    }
                    esi[0x2e] = var_4;
                    esi[0x2c] = var_8;
                    esi[0x2f] = dword_4c8de4;
                    eax = 0x0;
            }
            else {
                    ebx = sub_4812c0(0x1, 0x30);
                    esp = (esp - 0x8) + 0x8;
                    if (ebx == 0x0) {
                            eax = 0x1;
                    }
                    else {
                            edi = 0x0;
                            eax = sub_481280(0x4);
                            esp = (esp - 0x4) + 0x4;
                            var_8 = eax;
                            if (eax == 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_20 = ebx;
                                    sub_47c8f9();
                                    esp = esp + 0x4;
                                    eax = 0x1;
                            }
                            else {
                                    *eax = edi;
                                    bool_23 = true;
                                    if (esi[0x6] != edi) {
                                            eax = sub_481280(0x4);
                                            esp = (esp - 0x4) + 0x4;
                                            var_4 = eax;
                                            if (eax == edi) {
                                                    decomp_var_20 = ebx;
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x4;
                                                    esp = esp + 0x4;
                                                    eax = 0x1;
                                            }
                                            else {
                                                    *eax = 0x0;
                                                    esp = (esp - 0x50) + 0x50 - 0xc;
                                                    esp = (esp - 0x44) + 0x50 - 0x18;
                                                    esp = (esp - 0x38) + 0x50 - 0x24;
                                                    esp = (esp - 0x18) + 0x3c;
                                                    if ((sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8()) != 0x0) {
                                                            sub_48b4ac(ebx);
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x10) + 0x10;
                                                            eax = 0x1;
                                                    }
                                                    else {
                                                            eax = ebx[0x7];
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
                                                            esi = arg_0;
                                                            *ebx = *arg_0[0x2f];
                                                            ebx[0x1] = *(arg_0[0x2f] + 0x4);
                                                            ebx[0x2] = *(arg_0[0x2f] + 0x8);
                                                            *var_8 = 0x1;
                                                            if (var_4 != 0x0) {
                                                                    *var_4 = 0x1;
                                                            }
                                                            eax = esi[0x2e];
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    InterlockedDecrement(eax);
                                                            }
                                                            eax = esi[0x2c];
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    if (InterlockedDecrement(eax) == 0x0) {
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x8;
                                                                    }
                                                            }
                                                            esi[0x2e] = var_4;
                                                            esi[0x2c] = var_8;
                                                            esi[0x2f] = ebx;
                                                            eax = 0x0;
                                                    }
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = *dword_4c8de4;
                                            esi = arg_0;
                                            *ebx = *arg_0[0x2f];
                                            ebx[0x1] = *(arg_0[0x2f] + 0x4);
                                            ebx[0x2] = *(arg_0[0x2f] + 0x8);
                                            *var_8 = 0x1;
                                            if (var_4 != 0x0) {
                                                    *var_4 = 0x1;
                                            }
                                            eax = esi[0x2e];
                                            if (eax != 0x0) {
                                                    esp = esp - 0x4;
                                                    InterlockedDecrement(eax);
                                            }
                                            eax = esi[0x2c];
                                            if (eax != 0x0) {
                                                    esp = esp - 0x4;
                                                    if (InterlockedDecrement(eax) == 0x0) {
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x8;
                                                    }
                                            }
                                            esi[0x2e] = var_4;
                                            esi[0x2c] = var_8;
                                            esi[0x2f] = ebx;
                                            eax = 0x0;
                                    }
                            }
                    }
            }
    }
    else {
            ebx = sub_4812c0(0x1, 0x30);
            esp = (esp - 0x8) + 0x8;
            if (ebx == 0x0) {
                    eax = 0x1;
            }
            else {
                    edi = 0x0;
                    eax = sub_481280(0x4);
                    esp = (esp - 0x4) + 0x4;
                    var_8 = eax;
                    if (eax == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_20 = ebx;
                            sub_47c8f9();
                            esp = esp + 0x4;
                            eax = 0x1;
                    }
                    else {
                            *eax = edi;
                            bool_8 = true;
                            if (esi[0x6] != edi) {
                                    eax = sub_481280(0x4);
                                    esp = (esp - 0x4) + 0x4;
                                    var_4 = eax;
                                    if (eax == edi) {
                                            decomp_var_20 = ebx;
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            esp = (esp - 0x8) + 0x4;
                                            esp = esp + 0x4;
                                            eax = 0x1;
                                    }
                                    else {
                                            *eax = edi;
                                            esp = (esp - 0x50) + 0x50 - 0xc;
                                            esp = (esp - 0x44) + 0x50 - 0x18;
                                            esp = (esp - 0x38) + 0x50 - 0x24;
                                            esp = (esp - 0x18) + 0x3c;
                                            if ((sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8() | sub_4896f8()) != 0x0) {
                                                    sub_48b4ac(ebx);
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x10) + 0x10;
                                                    eax = 0x1;
                                            }
                                            else {
                                                    eax = ebx[0x7];
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
                                                    esi = arg_0;
                                                    *ebx = *arg_0[0x2f];
                                                    ebx[0x1] = *(arg_0[0x2f] + 0x4);
                                                    ebx[0x2] = *(arg_0[0x2f] + 0x8);
                                                    *var_8 = 0x1;
                                                    if (var_4 != 0x0) {
                                                            *var_4 = 0x1;
                                                    }
                                                    eax = esi[0x2e];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            InterlockedDecrement(eax);
                                                    }
                                                    eax = esi[0x2c];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            if (InterlockedDecrement(eax) == 0x0) {
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x8;
                                                            }
                                                    }
                                                    esi[0x2e] = var_4;
                                                    esi[0x2c] = var_8;
                                                    esi[0x2f] = ebx;
                                                    eax = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = (esp - 0x4) + 0x4;
                                    *ebx = *dword_4c8de4;
                                    esi = arg_0;
                                    *ebx = *arg_0[0x2f];
                                    ebx[0x1] = *(arg_0[0x2f] + 0x4);
                                    ebx[0x2] = *(arg_0[0x2f] + 0x8);
                                    *var_8 = 0x1;
                                    if (var_4 != 0x0) {
                                            *var_4 = 0x1;
                                    }
                                    eax = esi[0x2e];
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            InterlockedDecrement(eax);
                                    }
                                    eax = esi[0x2c];
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            if (InterlockedDecrement(eax) == 0x0) {
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x8;
                                            }
                                    }
                                    esi[0x2e] = var_4;
                                    esi[0x2c] = var_8;
                                    esi[0x2f] = ebx;
                                    eax = 0x0;
                            }
                    }
            }
    }
    return eax;
}
