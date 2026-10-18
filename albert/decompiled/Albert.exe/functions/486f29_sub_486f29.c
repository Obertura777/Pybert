// sub_486f29 @ 0x486f29
// hopper name: sub_486f29
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486f29() {
    sub_47f31c(0x4c3850, 0x10);
    edi = 0x0;
    sub_487c06(0x1);
    esp = (esp - 0xc) + 0x4;
    esi = 0x0;
    while (true) {
            if (esi >= *dword_bc8360) {
                    temp_0 = 0x0;
                    break;
            }
            eax = *dword_bc7340;
            eax = eax + esi * 0x4;
            if (*eax == 0x0) {
                    esi = esi << 0x2;
                    esp = (esp - 0x4) + 0x4;
                    esi[*dword_bc7340] = sub_481280(0x38);
                    eax = *dword_bc7340;
                    eax = eax + esi;
                    if (*eax != 0x0) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_489876() == 0x0) {
                                    sub_47c8f9();
                                    esi[*dword_bc7340] = 0x0;
                                    temp_0 = 0x3;
                            }
                            else {
                                    EnterCriticalSection(esi[*dword_bc7340] + 0x20);
                                    edi = esi[*dword_bc7340];
                                    temp_0 = 0x2;
                            }
                    }
                    else {
                            temp_0 = 0x1;
                    }
                    break;
            }
            if ((*(int8_t *)(*eax + 0xc) & 0x83) != 0x0) {
                    esi = esi + 0x1;
                    continue;
            }
            if (esi > 0x13) {
                    decomp_var_c = *(*dword_bc7340 + esi * 0x4);
                    sub_48690d(esi, decomp_var_c);
                    esp = (esp - 0x8) + 0x8;
                    eax = *dword_bc7340;
                    eax = *(eax + esi * 0x4);
                    if ((eax[0xc] & 0x83) != 0x0) {
                            sub_48695f(esi, eax);
                            esp = (esp - 0x8) + 0x8;
                            esi = esi + 0x1;
                            continue;
                    }
                    edi = eax;
                    temp_0 = 0x2;
                    break;
            }
            esp = (esp - 0x4) + 0x4;
            if (sub_487b43() == 0x0) {
                    temp_0 = 0x0;
                    break;
            }
            decomp_var_c = *(*dword_bc7340 + esi * 0x4);
            sub_48690d(esi, decomp_var_c);
            esp = (esp - 0x8) + 0x8;
            eax = *dword_bc7340;
            eax = *(eax + esi * 0x4);
            if ((eax[0xc] & 0x83) != 0x0) {
                    sub_48695f(esi, eax);
                    esp = (esp - 0x8) + 0x8;
                    esi = esi + 0x1;
                    continue;
            }
            edi = eax;
            temp_0 = 0x2;
            break;
    }
    if (temp_0 != 0x0) {
            if (temp_0 != 0x1 && temp_0 == 0x2) {
                    if (edi != 0x0) {
                            edi[0x1] = 0x0;
                            edi[0x3] = 0x0;
                            edi[0x2] = 0x0;
                            *edi = 0x0;
                            edi[0x7] = 0x0;
                            edi[0x4] = edi[0x4] | 0xffffffff;
                    }
                    sub_487046();
                    eax = sub_47f361();
            }
            else {
                    if (edi != 0x0) {
                            edi[0x1] = 0x0;
                            edi[0x3] = 0x0;
                            edi[0x2] = 0x0;
                            *edi = 0x0;
                            edi[0x7] = 0x0;
                            edi[0x4] = edi[0x4] | 0xffffffff;
                    }
                    sub_487046();
                    eax = sub_47f361();
            }
    }
    else {
            if (edi != 0x0) {
                    edi[0x1] = 0x0;
                    edi[0x3] = 0x0;
                    edi[0x2] = 0x0;
                    *edi = 0x0;
                    edi[0x7] = 0x0;
                    edi[0x4] = edi[0x4] | 0xffffffff;
            }
            sub_487046();
            eax = sub_47f361();
    }
    return eax;
}
