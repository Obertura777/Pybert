// sub_486a47 @ 0x486a47
// hopper name: sub_486a47
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486a47() {
    sub_47f31c(0x4c3830, 0x54);
    GetStartupInfoA(&decomp_var_64);
    eax = sub_4812c0(0x20, 0x28);
    esp = ((esp - 0x14) + 0x4 - 0x4) + 0x8;
    if (eax != 0x0) {
            *dword_bc7240 = eax;
            *dword_bc7228 = 0x20;
            for (ecx = eax + 0x500; eax < ecx; ecx = ecx + 0x500) {
                    eax[0x4] = 0x0;
                    *eax = *eax | 0xffffffff;
                    eax[0x5] = 0xa;
                    eax[0x2] = 0x0;
                    eax[0x24] = 0x0;
                    eax[0x25] = 0xa;
                    eax[0x26] = 0xa;
                    eax = eax + 0x28;
                    ecx = *dword_bc7240;
            }
            if (decomp_var_32 != 0x0) {
                    eax = decomp_var_30;
                    if (eax != 0x0) {
                            edi = *eax;
                            ebx = eax + 0x4;
                            decomp_var_1c = ebx + edi;
                            if (edi >= 0x800) {
                                    edi = 0x800;
                            }
                            esi = 0x1;
                            while (*dword_bc7228 < edi) {
                                    eax = sub_4812c0(0x20, 0x28);
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax != 0x0) {
                                            ecx = esi * 0x4 + dword_bc7240;
                                            *ecx = eax;
                                            *dword_bc7228 = *dword_bc7228 + 0x20;
                                            for (edx = eax + 0x500; eax < edx; edx = edx + 0x500) {
                                                    eax[0x4] = 0x0;
                                                    *eax = *eax | 0xffffffff;
                                                    eax[0x5] = 0xa;
                                                    eax[0x2] = eax[0x2] & 0x0;
                                                    eax[0x24] = eax[0x24] & 0x80;
                                                    eax[0x25] = 0xa;
                                                    eax[0x26] = 0xa;
                                                    eax = eax + 0x28;
                                                    edx = *ecx;
                                            }
                                            esi = esi + 0x1;
                                            continue;
                                    }
                                    edi = *dword_bc7228;
                                    break;
                            }
                            decomp_var_20 = decomp_var_20 & 0x0;
                            if (edi > 0x0) {
                                    while (true) {
                                            eax = decomp_var_1c;
                                            ecx = *eax;
                                            if (ecx == 0xffffffff) {
                                                    decomp_var_20 = decomp_var_20 + 0x1;
                                                    ebx = ebx + 0x1;
                                                    decomp_var_1c = decomp_var_1c + 0x4;
                                                    if (decomp_var_20 < edi) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            if (ecx == 0xfffffffe) {
                                                    decomp_var_20 = decomp_var_20 + 0x1;
                                                    ebx = ebx + 0x1;
                                                    decomp_var_1c = decomp_var_1c + 0x4;
                                                    if (decomp_var_20 < edi) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            eax = *(int8_t *)ebx;
                                            if ((eax & 0x1) == 0x0) {
                                                    decomp_var_20 = decomp_var_20 + 0x1;
                                                    ebx = ebx + 0x1;
                                                    decomp_var_1c = decomp_var_1c + 0x4;
                                                    if (decomp_var_20 < edi) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            if ((eax & 0x8) == 0x0) {
                                                    esp = esp - 0x4;
                                                    eax = GetFileType(ecx);
                                                    if (eax != 0x0) {
                                                            esi = (decomp_var_20 & 0x1f) * 0x28 + *((SAR(decomp_var_20, 0x5)) * 0x4 + dword_bc7240);
                                                            *esi = *decomp_var_1c;
                                                            esi[0x4] = *(int8_t *)ebx;
                                                            eax = sub_489876();
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax != 0x0) {
                                                                    esi[0x2] = esi[0x2] + 0x1;
                                                                    decomp_var_20 = decomp_var_20 + 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    decomp_var_1c = decomp_var_1c + 0x4;
                                                                    if (decomp_var_20 < edi) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_1 = 0x0;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_20 = decomp_var_20 + 0x1;
                                                            ebx = ebx + 0x1;
                                                            decomp_var_1c = decomp_var_1c + 0x4;
                                                            if (decomp_var_20 < edi) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esi = (decomp_var_20 & 0x1f) * 0x28 + *((SAR(decomp_var_20, 0x5)) * 0x4 + dword_bc7240);
                                                    *esi = *decomp_var_1c;
                                                    esi[0x4] = *(int8_t *)ebx;
                                                    eax = sub_489876();
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax != 0x0) {
                                                            esi[0x2] = esi[0x2] + 0x1;
                                                            decomp_var_20 = decomp_var_20 + 0x1;
                                                            ebx = ebx + 0x1;
                                                            decomp_var_1c = decomp_var_1c + 0x4;
                                                            if (decomp_var_20 < edi) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            temp_1 = 0x0;
                                                            break;
                                                    }
                                            }
                                    }
                                    if (temp_1 != 0x0) {
                                            ebx = 0x0;
                                            while (true) {
                                                    esi = ebx * 0x28 + *dword_bc7240;
                                                    eax = *esi;
                                                    if (eax != 0xffffffff) {
                                                            if (eax != 0xfffffffe) {
                                                                    esi[0x4] = esi[0x4] | 0x80;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    esi[0x4] = 0x81;
                                                                    if (ebx == 0x0) {
                                                                            eax = 0xfffffff6;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    else {
                                                                            eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    edi = GetStdHandle(eax);
                                                                    if (edi != 0xffffffff) {
                                                                            if (edi != 0x0) {
                                                                                    esp = esp - 0x4;
                                                                                    eax = GetFileType(edi);
                                                                                    if (eax != 0x0) {
                                                                                            *esi = edi;
                                                                                            eax = eax & 0xff;
                                                                                            if (eax == 0x2) {
                                                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                                            }
                                                                                            else {
                                                                                                    if (eax == 0x3) {
                                                                                                            esi[0x4] = esi[0x4] | 0x8;
                                                                                                    }
                                                                                            }
                                                                                            eax = sub_489876();
                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                            if (eax != 0x0) {
                                                                                                    esi[0x2] = esi[0x2] + 0x1;
                                                                                                    ebx = ebx + 0x1;
                                                                                                    if (ebx < 0x3) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    SetHandleCount(*dword_bc7228);
                                                                                                    eax = 0x0;
                                                                                                    temp_0 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                                            *esi = 0xfffffffe;
                                                                                            ebx = ebx + 0x1;
                                                                                            if (ebx < 0x3) {
                                                                                                    continue;
                                                                                            }
                                                                                            SetHandleCount(*dword_bc7228);
                                                                                            eax = 0x0;
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                                    *esi = 0xfffffffe;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < 0x3) {
                                                                                            continue;
                                                                                    }
                                                                                    SetHandleCount(*dword_bc7228);
                                                                                    eax = 0x0;
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                            *esi = 0xfffffffe;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi[0x4] = 0x81;
                                                            if (ebx == 0x0) {
                                                                    eax = 0xfffffff6;
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            else {
                                                                    eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                                            }
                                                            esp = esp - 0x4;
                                                            edi = GetStdHandle(eax);
                                                            if (edi != 0xffffffff) {
                                                                    if (edi != 0x0) {
                                                                            esp = esp - 0x4;
                                                                            eax = GetFileType(edi);
                                                                            if (eax != 0x0) {
                                                                                    *esi = edi;
                                                                                    eax = eax & 0xff;
                                                                                    if (eax == 0x2) {
                                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0x3) {
                                                                                                    esi[0x4] = esi[0x4] | 0x8;
                                                                                            }
                                                                                    }
                                                                                    eax = sub_489876();
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax != 0x0) {
                                                                                            esi[0x2] = esi[0x2] + 0x1;
                                                                                            ebx = ebx + 0x1;
                                                                                            if (ebx < 0x3) {
                                                                                                    continue;
                                                                                            }
                                                                                            SetHandleCount(*dword_bc7228);
                                                                                            eax = 0x0;
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                                    *esi = 0xfffffffe;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < 0x3) {
                                                                                            continue;
                                                                                    }
                                                                                    SetHandleCount(*dword_bc7228);
                                                                                    eax = 0x0;
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                            *esi = 0xfffffffe;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                    *esi = 0xfffffffe;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            eax = sub_47f361();
                                    }
                                    else {
                                            eax = sub_47f361();
                                    }
                            }
                            else {
                                    ebx = 0x0;
                                    while (true) {
                                            esi = ebx * 0x28 + *dword_bc7240;
                                            eax = *esi;
                                            if (eax != 0xffffffff) {
                                                    if (eax != 0xfffffffe) {
                                                            esi[0x4] = esi[0x4] | 0x80;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < 0x3) {
                                                                    continue;
                                                            }
                                                            SetHandleCount(*dword_bc7228);
                                                            eax = 0x0;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            esi[0x4] = 0x81;
                                                            if (ebx == 0x0) {
                                                                    eax = 0xfffffff6;
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            else {
                                                                    eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                                            }
                                                            esp = esp - 0x4;
                                                            edi = GetStdHandle(eax);
                                                            if (edi != 0xffffffff) {
                                                                    if (edi != 0x0) {
                                                                            esp = esp - 0x4;
                                                                            eax = GetFileType(edi);
                                                                            if (eax != 0x0) {
                                                                                    *esi = edi;
                                                                                    eax = eax & 0xff;
                                                                                    if (eax == 0x2) {
                                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0x3) {
                                                                                                    esi[0x4] = esi[0x4] | 0x8;
                                                                                            }
                                                                                    }
                                                                                    eax = sub_489876();
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax != 0x0) {
                                                                                            esi[0x2] = esi[0x2] + 0x1;
                                                                                            ebx = ebx + 0x1;
                                                                                            if (ebx < 0x3) {
                                                                                                    continue;
                                                                                            }
                                                                                            SetHandleCount(*dword_bc7228);
                                                                                            eax = 0x0;
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                                    *esi = 0xfffffffe;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < 0x3) {
                                                                                            continue;
                                                                                    }
                                                                                    SetHandleCount(*dword_bc7228);
                                                                                    eax = 0x0;
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                            *esi = 0xfffffffe;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                    *esi = 0xfffffffe;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    esi[0x4] = 0x81;
                                                    if (ebx == 0x0) {
                                                            eax = 0xfffffff6;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    else {
                                                            eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                                    }
                                                    esp = esp - 0x4;
                                                    edi = GetStdHandle(eax);
                                                    if (edi != 0xffffffff) {
                                                            if (edi != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    eax = GetFileType(edi);
                                                                    if (eax != 0x0) {
                                                                            *esi = edi;
                                                                            eax = eax & 0xff;
                                                                            if (eax == 0x2) {
                                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                            }
                                                                            else {
                                                                                    if (eax == 0x3) {
                                                                                            esi[0x4] = esi[0x4] | 0x8;
                                                                                    }
                                                                            }
                                                                            eax = sub_489876();
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            if (eax != 0x0) {
                                                                                    esi[0x2] = esi[0x2] + 0x1;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < 0x3) {
                                                                                            continue;
                                                                                    }
                                                                                    SetHandleCount(*dword_bc7228);
                                                                                    eax = 0x0;
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                            *esi = 0xfffffffe;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                    *esi = 0xfffffffe;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi[0x4] = esi[0x4] | 0x40;
                                                            *esi = 0xfffffffe;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < 0x3) {
                                                                    continue;
                                                            }
                                                            SetHandleCount(*dword_bc7228);
                                                            eax = 0x0;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    eax = sub_47f361();
                            }
                    }
                    else {
                            ebx = 0x0;
                            while (true) {
                                    esi = ebx * 0x28 + *dword_bc7240;
                                    eax = *esi;
                                    if (eax != 0xffffffff) {
                                            if (eax != 0xfffffffe) {
                                                    esi[0x4] = esi[0x4] | 0x80;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < 0x3) {
                                                            continue;
                                                    }
                                                    SetHandleCount(*dword_bc7228);
                                                    eax = 0x0;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    esi[0x4] = 0x81;
                                                    if (ebx == 0x0) {
                                                            eax = 0xfffffff6;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    else {
                                                            eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                                    }
                                                    esp = esp - 0x4;
                                                    edi = GetStdHandle(eax);
                                                    if (edi != 0xffffffff) {
                                                            if (edi != 0x0) {
                                                                    esp = esp - 0x4;
                                                                    eax = GetFileType(edi);
                                                                    if (eax != 0x0) {
                                                                            *esi = edi;
                                                                            eax = eax & 0xff;
                                                                            if (eax == 0x2) {
                                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                            }
                                                                            else {
                                                                                    if (eax == 0x3) {
                                                                                            esi[0x4] = esi[0x4] | 0x8;
                                                                                    }
                                                                            }
                                                                            eax = sub_489876();
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            if (eax != 0x0) {
                                                                                    esi[0x2] = esi[0x2] + 0x1;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < 0x3) {
                                                                                            continue;
                                                                                    }
                                                                                    SetHandleCount(*dword_bc7228);
                                                                                    eax = 0x0;
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                            *esi = 0xfffffffe;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                    *esi = 0xfffffffe;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi[0x4] = esi[0x4] | 0x40;
                                                            *esi = 0xfffffffe;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < 0x3) {
                                                                    continue;
                                                            }
                                                            SetHandleCount(*dword_bc7228);
                                                            eax = 0x0;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            esi[0x4] = 0x81;
                                            if (ebx == 0x0) {
                                                    eax = 0xfffffff6;
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            else {
                                                    eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                            }
                                            esp = esp - 0x4;
                                            edi = GetStdHandle(eax);
                                            if (edi != 0xffffffff) {
                                                    if (edi != 0x0) {
                                                            esp = esp - 0x4;
                                                            eax = GetFileType(edi);
                                                            if (eax != 0x0) {
                                                                    *esi = edi;
                                                                    eax = eax & 0xff;
                                                                    if (eax == 0x2) {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                    }
                                                                    else {
                                                                            if (eax == 0x3) {
                                                                                    esi[0x4] = esi[0x4] | 0x8;
                                                                            }
                                                                    }
                                                                    eax = sub_489876();
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (eax != 0x0) {
                                                                            esi[0x2] = esi[0x2] + 0x1;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                    *esi = 0xfffffffe;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi[0x4] = esi[0x4] | 0x40;
                                                            *esi = 0xfffffffe;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < 0x3) {
                                                                    continue;
                                                            }
                                                            SetHandleCount(*dword_bc7228);
                                                            eax = 0x0;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esi[0x4] = esi[0x4] | 0x40;
                                                    *esi = 0xfffffffe;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < 0x3) {
                                                            continue;
                                                    }
                                                    SetHandleCount(*dword_bc7228);
                                                    eax = 0x0;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            eax = sub_47f361();
                    }
            }
            else {
                    ebx = 0x0;
                    while (true) {
                            esi = ebx * 0x28 + *dword_bc7240;
                            eax = *esi;
                            if (eax != 0xffffffff) {
                                    if (eax != 0xfffffffe) {
                                            esi[0x4] = esi[0x4] | 0x80;
                                            ebx = ebx + 0x1;
                                            if (ebx < 0x3) {
                                                    continue;
                                            }
                                            SetHandleCount(*dword_bc7228);
                                            eax = 0x0;
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    else {
                                            esi[0x4] = 0x81;
                                            if (ebx == 0x0) {
                                                    eax = 0xfffffff6;
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            else {
                                                    eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                            }
                                            esp = esp - 0x4;
                                            edi = GetStdHandle(eax);
                                            if (edi != 0xffffffff) {
                                                    if (edi != 0x0) {
                                                            esp = esp - 0x4;
                                                            eax = GetFileType(edi);
                                                            if (eax != 0x0) {
                                                                    *esi = edi;
                                                                    eax = eax & 0xff;
                                                                    if (eax == 0x2) {
                                                                            esi[0x4] = esi[0x4] | 0x40;
                                                                    }
                                                                    else {
                                                                            if (eax == 0x3) {
                                                                                    esi[0x4] = esi[0x4] | 0x8;
                                                                            }
                                                                    }
                                                                    eax = sub_489876();
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (eax != 0x0) {
                                                                            esi[0x2] = esi[0x2] + 0x1;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < 0x3) {
                                                                                    continue;
                                                                            }
                                                                            SetHandleCount(*dword_bc7228);
                                                                            eax = 0x0;
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                                    *esi = 0xfffffffe;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi[0x4] = esi[0x4] | 0x40;
                                                            *esi = 0xfffffffe;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < 0x3) {
                                                                    continue;
                                                            }
                                                            SetHandleCount(*dword_bc7228);
                                                            eax = 0x0;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esi[0x4] = esi[0x4] | 0x40;
                                                    *esi = 0xfffffffe;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < 0x3) {
                                                            continue;
                                                    }
                                                    SetHandleCount(*dword_bc7228);
                                                    eax = 0x0;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    esi[0x4] = 0x81;
                                    if (ebx == 0x0) {
                                            eax = 0xfffffff6;
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    else {
                                            eax = -(ebx - 0x1) - -(ebx - 0x1) + CARRY(EFLAGS(cf)) - 0xb;
                                    }
                                    esp = esp - 0x4;
                                    edi = GetStdHandle(eax);
                                    if (edi != 0xffffffff) {
                                            if (edi != 0x0) {
                                                    esp = esp - 0x4;
                                                    eax = GetFileType(edi);
                                                    if (eax != 0x0) {
                                                            *esi = edi;
                                                            eax = eax & 0xff;
                                                            if (eax == 0x2) {
                                                                    esi[0x4] = esi[0x4] | 0x40;
                                                            }
                                                            else {
                                                                    if (eax == 0x3) {
                                                                            esi[0x4] = esi[0x4] | 0x8;
                                                                    }
                                                            }
                                                            eax = sub_489876();
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (eax != 0x0) {
                                                                    esi[0x2] = esi[0x2] + 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < 0x3) {
                                                                            continue;
                                                                    }
                                                                    SetHandleCount(*dword_bc7228);
                                                                    eax = 0x0;
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi[0x4] = esi[0x4] | 0x40;
                                                            *esi = 0xfffffffe;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < 0x3) {
                                                                    continue;
                                                            }
                                                            SetHandleCount(*dword_bc7228);
                                                            eax = 0x0;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esi[0x4] = esi[0x4] | 0x40;
                                                    *esi = 0xfffffffe;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < 0x3) {
                                                            continue;
                                                    }
                                                    SetHandleCount(*dword_bc7228);
                                                    eax = 0x0;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            esi[0x4] = esi[0x4] | 0x40;
                                            *esi = 0xfffffffe;
                                            ebx = ebx + 0x1;
                                            if (ebx < 0x3) {
                                                    continue;
                                            }
                                            SetHandleCount(*dword_bc7228);
                                            eax = 0x0;
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
                    eax = sub_47f361();
            }
    }
    else {
            eax = sub_47f361();
    }
    return eax;
}
