// sub_48e56f @ 0x48e56f
// hopper name: sub_48e56f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e56f() {
    sub_47f31c(0x4c3990, 0x18);
    decomp_var_1c = decomp_var_1c | 0xffffffff;
    decomp_var_24 = 0x0;
    decomp_var_c = 0xb;
    eax = sub_487b43();
    esp = (esp - 0xc) + 0x4;
    if (eax != 0x0) {
            edi = 0x0;
            eax = sub_487c06(0xb);
            ecx = decomp_var_c;
            esp = (esp - 0x4) + 0x4;
            while (true) {
                    if (edi >= 0x40) {
                            temp_3 = 0x0;
                            break;
                    }
                    esi = *(edi * 0x4 + dword_bc7240);
                    if (esi == 0x0) {
                            eax = sub_4812c0(0x20, 0x28);
                            ecx = decomp_var_c;
                            esp = (esp - 0x8) + 0x8;
                            if (eax != 0x0) {
                                    ecx = edi * 0x4 + dword_bc7240;
                                    *ecx = eax;
                                    *dword_bc7228 = *dword_bc7228 + 0x20;
                                    temp_3 = 0x2;
                            }
                            else {
                                    temp_3 = 0x1;
                            }
                            break;
                    }
                    while (true) {
                            eax = *(edi * 0x4 + dword_bc7240);
                            eax = eax + 0x500;
                            if (esi >= eax) {
                                    temp_2 = 0x1;
                                    break;
                            }
                            if ((esi[0x4] & 0x1) != 0x0) {
                                    esi = esi + 0x28;
                                    continue;
                            }
                            if (esi[0x2] == 0x0) {
                                    sub_487c06(0xa);
                                    ecx = decomp_var_c;
                                    esp = (esp - 0x4) + 0x4;
                                    decomp_var_4 = 0x1;
                                    if (esi[0x2] == 0x0) {
                                            decomp_var_c = 0xfa0;
                                            decomp_var_10 = esi + 0xc;
                                            eax = sub_489876();
                                            ecx = decomp_var_c;
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax == 0x0) {
                                                    decomp_var_24 = 0x1;
                                            }
                                            else {
                                                    esi[0x2] = esi[0x2] + 0x1;
                                            }
                                    }
                                    sub_48e642();
                            }
                            if (decomp_var_24 != 0x0) {
                                    esi = esi + 0x28;
                                    continue;
                            }
                            ebx = esi + 0xc;
                            esp = esp - 0x4;
                            eax = EnterCriticalSection(ebx);
                            if ((esi[0x4] & 0x1) != 0x0) {
                                    esp = esp - 0x4;
                                    LeaveCriticalSection(ebx);
                                    esi = esi + 0x28;
                                    continue;
                            }
                            if (decomp_var_24 != 0x0) {
                                    esi = esi + 0x28;
                                    continue;
                            }
                            temp_2 = 0x0;
                            break;
                    }
                    if (temp_2 == 0x0) {
                            esi[0x4] = 0x1;
                            *esi = *esi | 0xffffffff;
                            eax = esi - *(edi * 0x4 + dword_bc7240);
                            esp = (esp - 0x4) + 0x4;
                            ecx = edi << 0x5;
                            eax = eax / 0x28 + ecx;
                            decomp_var_1c = eax;
                    }
                    if (decomp_var_1c == 0xffffffff) {
                            edi = edi + 0x1;
                            continue;
                    }
                    temp_3 = 0x0;
                    break;
            }
            if (temp_3 != 0x0 && temp_3 != 0x1) {
                    while (eax < *ecx + 0x500) {
                            eax[0x4] = 0x0;
                            *eax = *eax | 0xffffffff;
                            eax[0x5] = 0xa;
                            eax[0x2] = eax[0x2] & 0x0;
                            eax = eax + 0x28;
                    }
                    decomp_var_1c = edi << 0x5;
                    *(int8_t *)(*((SAR(edi << 0x5, 0x5)) * 0x4 + dword_bc7240) + (edi << 0x5 & 0x1f) * 0x28 + 0x4) = 0x1;
                    if (sub_48e4ad() == 0x0) {
                            decomp_var_1c = decomp_var_1c | 0xffffffff;
                    }
            }
            sub_48e705();
    }
    eax = sub_47f361();
    return eax;
}
