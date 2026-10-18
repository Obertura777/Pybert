// sub_4776c0 @ 0x4776c0
// hopper name: sub_4776c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4776c0() {
    decomp_var_8 = ebx;
    decomp_var_c = ebp;
    esi = ecx;
    esp = esp - 0x18;
    decomp_var_4 = esi + 0x1c;
    EnterCriticalSection(esi + 0x1c);
    eax = esi[0x1];
    edi = esi[0x2];
    if (edi < eax) {
            if ((*(int8_t *)(esi[0x4] + edi * 0x8) & 0x1) != 0x0) {
                    edi = 0x1;
                    if (eax > 0x1) {
                            ecx = esi[0x4];
                            ecx = ecx + 0x8;
                            while ((*(int8_t *)ecx & 0x1) != 0x0) {
                                    edi = edi + 0x1;
                                    ecx = ecx + 0x8;
                                    if (edi >= eax) {
                                            break;
                                    }
                            }
                            if (edi >= eax) {
                                    ebp = eax + 0x20;
                                    eax = esi[0x4];
                                    if (eax == 0x0) {
                                            decomp_var_4 = sub_4656f0(ebp, 0x8);
                                            esp = (esp - 0x8) + 0x8 - 0x8;
                                            decomp_var_8 = 0x2;
                                            eax = GlobalAlloc(0x2, decomp_var_4);
                                    }
                                    else {
                                            ebx = GlobalHandle(eax);
                                            GlobalUnlock(ebx);
                                            decomp_var_4 = 0x2002;
                                            decomp_var_8 = sub_4656f0(ebp, 0x8, 0x2002);
                                            esp = (esp - 0x14) + 0x8 - 0x8;
                                            eax = GlobalReAlloc(ebx, decomp_var_8, decomp_var_4);
                                    }
                                    if (eax == 0x0) {
                                            esi = esi[0x4];
                                            if (esi != 0x0) {
                                                    esp = esp - 0x8;
                                                    GlobalLock(GlobalHandle(esi));
                                            }
                                            LeaveCriticalSection(arg_4);
                                            sub_46dea8();
                                    }
                                    ebx = GlobalLock(eax);
                                    eax = esi[0x1];
                                    sub_47ba40(ebx + eax * 0x8, 0x0, ebp - eax << 0x3);
                                    esp = (esp - 0x10) + 0xc;
                                    esi[0x1] = ebp;
                                    esi[0x4] = ebx;
                                    if (edi >= esi[0x3]) {
                                            esi[0x3] = edi + 0x1;
                                    }
                                    eax = esi[0x4];
                                    *(eax + edi * 0x8) = *(eax + edi * 0x8) | 0x1;
                                    esi[0x2] = edi + 0x1;
                                    LeaveCriticalSection(arg_4);
                            }
                            else {
                                    if (edi >= esi[0x3]) {
                                            esi[0x3] = edi + 0x1;
                                    }
                                    eax = esi[0x4];
                                    *(eax + edi * 0x8) = *(eax + edi * 0x8) | 0x1;
                                    esi[0x2] = edi + 0x1;
                                    LeaveCriticalSection(arg_4);
                            }
                    }
                    else {
                            ebp = eax + 0x20;
                            eax = esi[0x4];
                            if (eax == 0x0) {
                                    decomp_var_4 = sub_4656f0(ebp, 0x8);
                                    esp = (esp - 0x8) + 0x8 - 0x8;
                                    decomp_var_8 = 0x2;
                                    eax = GlobalAlloc(0x2, decomp_var_4);
                            }
                            else {
                                    ebx = GlobalHandle(eax);
                                    GlobalUnlock(ebx);
                                    decomp_var_4 = 0x2002;
                                    decomp_var_8 = sub_4656f0(ebp, 0x8, 0x2002);
                                    esp = (esp - 0x14) + 0x8 - 0x8;
                                    eax = GlobalReAlloc(ebx, decomp_var_8, decomp_var_4);
                            }
                            if (eax == 0x0) {
                                    esi = esi[0x4];
                                    if (esi != 0x0) {
                                            esp = esp - 0x8;
                                            GlobalLock(GlobalHandle(esi));
                                    }
                                    LeaveCriticalSection(arg_4);
                                    sub_46dea8();
                            }
                            ebx = GlobalLock(eax);
                            eax = esi[0x1];
                            sub_47ba40(ebx + eax * 0x8, 0x0, ebp - eax << 0x3);
                            esp = (esp - 0x10) + 0xc;
                            esi[0x1] = ebp;
                            esi[0x4] = ebx;
                            if (0x1 >= esi[0x3]) {
                                    esi[0x3] = 0x2;
                            }
                            eax = esi[0x4];
                            *(eax + 0x8) = *(eax + 0x8) | 0x1;
                            esi[0x2] = 0x2;
                            LeaveCriticalSection(arg_4);
                    }
            }
            else {
                    if (edi >= esi[0x3]) {
                            esi[0x3] = edi + 0x1;
                    }
                    eax = esi[0x4];
                    *(eax + edi * 0x8) = *(eax + edi * 0x8) | 0x1;
                    esi[0x2] = edi + 0x1;
                    LeaveCriticalSection(arg_4);
            }
    }
    else {
            edi = 0x1;
            if (eax > 0x1) {
                    ecx = esi[0x4];
                    ecx = ecx + 0x8;
                    while ((*(int8_t *)ecx & 0x1) != 0x0) {
                            edi = edi + 0x1;
                            ecx = ecx + 0x8;
                            if (edi >= eax) {
                                    break;
                            }
                    }
                    if (edi >= eax) {
                            ebp = eax + 0x20;
                            eax = esi[0x4];
                            if (eax == 0x0) {
                                    decomp_var_4 = sub_4656f0(ebp, 0x8);
                                    esp = (esp - 0x8) + 0x8 - 0x8;
                                    decomp_var_8 = 0x2;
                                    eax = GlobalAlloc(0x2, decomp_var_4);
                            }
                            else {
                                    ebx = GlobalHandle(eax);
                                    GlobalUnlock(ebx);
                                    decomp_var_4 = 0x2002;
                                    decomp_var_8 = sub_4656f0(ebp, 0x8, 0x2002);
                                    esp = (esp - 0x14) + 0x8 - 0x8;
                                    eax = GlobalReAlloc(ebx, decomp_var_8, decomp_var_4);
                            }
                            if (eax == 0x0) {
                                    esi = esi[0x4];
                                    if (esi != 0x0) {
                                            esp = esp - 0x8;
                                            GlobalLock(GlobalHandle(esi));
                                    }
                                    LeaveCriticalSection(arg_4);
                                    sub_46dea8();
                            }
                            ebx = GlobalLock(eax);
                            eax = esi[0x1];
                            sub_47ba40(ebx + eax * 0x8, 0x0, ebp - eax << 0x3);
                            esp = (esp - 0x10) + 0xc;
                            esi[0x1] = ebp;
                            esi[0x4] = ebx;
                            if (edi >= esi[0x3]) {
                                    esi[0x3] = edi + 0x1;
                            }
                            eax = esi[0x4];
                            *(eax + edi * 0x8) = *(eax + edi * 0x8) | 0x1;
                            esi[0x2] = edi + 0x1;
                            LeaveCriticalSection(arg_4);
                    }
                    else {
                            if (edi >= esi[0x3]) {
                                    esi[0x3] = edi + 0x1;
                            }
                            eax = esi[0x4];
                            *(eax + edi * 0x8) = *(eax + edi * 0x8) | 0x1;
                            esi[0x2] = edi + 0x1;
                            LeaveCriticalSection(arg_4);
                    }
            }
            else {
                    ebp = eax + 0x20;
                    eax = esi[0x4];
                    if (eax == 0x0) {
                            decomp_var_4 = sub_4656f0(ebp, 0x8);
                            esp = (esp - 0x8) + 0x8 - 0x8;
                            decomp_var_8 = 0x2;
                            eax = GlobalAlloc(0x2, decomp_var_4);
                    }
                    else {
                            ebx = GlobalHandle(eax);
                            GlobalUnlock(ebx);
                            decomp_var_4 = 0x2002;
                            decomp_var_8 = sub_4656f0(ebp, 0x8, 0x2002);
                            esp = (esp - 0x14) + 0x8 - 0x8;
                            eax = GlobalReAlloc(ebx, decomp_var_8, decomp_var_4);
                    }
                    if (eax == 0x0) {
                            esi = esi[0x4];
                            if (esi != 0x0) {
                                    esp = esp - 0x8;
                                    GlobalLock(GlobalHandle(esi));
                            }
                            LeaveCriticalSection(arg_4);
                            sub_46dea8();
                    }
                    ebx = GlobalLock(eax);
                    eax = esi[0x1];
                    sub_47ba40(ebx + eax * 0x8, 0x0, ebp - eax << 0x3);
                    esp = (esp - 0x10) + 0xc;
                    esi[0x1] = ebp;
                    esi[0x4] = ebx;
                    if (0x1 >= esi[0x3]) {
                            esi[0x3] = 0x2;
                    }
                    eax = esi[0x4];
                    *(eax + 0x8) = *(eax + 0x8) | 0x1;
                    esi[0x2] = 0x2;
                    LeaveCriticalSection(arg_4);
            }
    }
    return;
}
