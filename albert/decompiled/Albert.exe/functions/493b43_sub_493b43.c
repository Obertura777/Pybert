// sub_493b43 @ 0x493b43
// hopper name: sub_493b43
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_493b43() {
    decomp_var_48 = ebx;
    esi = arg_0;
    edx = esi[0x2];
    ecx = esi[0x1];
    ebx = esi[0x3];
    esp = esp - 0xc;
    edi = esi[0x5];
    var_18 = edx + word_400000;
    edx = esi[0x4];
    ebx = ebx + word_400000;
    edx = edx + word_400000;
    var_4 = esi[0x7];
    var_38 = ecx + word_400000;
    ecx = 0x0;
    var_C = edi + word_400000;
    bool_0 = (*esi & 0x1) != 0x0;
    var_44 = 0x24;
    var_40 = esi;
    asm { stosd      dword [edi], eax };
    var_28 = ecx;
    var_24 = ecx;
    if (bool_0) goto loc_493bc7;
    goto loc_493ba8;

loc_493bc7:
    edi = *var_18;
    edx = *(edx + (SAR(arg_4 - ebx, 0x2) << 0x2));
    arg_0 = SAR(arg_4 - ebx, 0x2) << 0x2;
    eax = edx + 0x400002;
    if ((!(edx >> 0x1f) & 0x1) == 0x0) {
            eax = edx & 0xffff;
    }
    var_30 = eax;
    ebx = 0x0;
    if (*dword_bc7200 == 0x0) goto loc_493c15;
    goto loc_493c04;

loc_493ba8:
    arg_4 = &var_44;
    esp = esp - 0x10;
    RaiseException(0xc06d0057, 0x0, 0x1, &arg_4);
    eax = 0x0;
    return eax;

loc_493c15:
    if (edi != 0x0) goto loc_493cbf;
    goto loc_493c1d;

loc_493c04:
    esp = esp - 0x8;
    eax = dword_bc7200(0x0, &var_44);
    ebx = eax;
    if (ebx != 0x0) goto loc_493d5a;
    goto loc_493c15;

loc_493cbf:
    if (*dword_bc7200 != 0x0) {
            esp = esp - 0x8;
            eax = dword_bc7200(0x2, &var_44);
            ebx = eax;
    }
    if (ebx != 0x0) goto loc_493d55;
    goto loc_493cd9;

loc_493c1d:
    if (*dword_bc7200 == 0x0) goto loc_493c34;
    goto loc_493c26;

loc_493d5a:
    if (*dword_bc7200 != 0x0) {
            esp = esp - 0x8;
            eax = dword_bc7200(0x5, &var_44);
    }
    eax = ebx;
    return eax;

loc_493d55:
    *arg_4 = ebx;
    goto loc_493d5a;

loc_493cd9:
    if (esi[0x5] != ebx) {
            if (esi[0x7] != ebx) {
                    eax = edi[0xf];
                    eax = eax + edi;
                    if (*eax == 0x4550) {
                            if (eax[0x2] == var_4) {
                                    if (edi == eax[0xd]) {
                                            ebx = *(arg_0 + var_C);
                                            if (ebx == 0x0) {
                                                    esp = esp - 0x8;
                                                    ebx = GetProcAddress(edi, var_30);
                                                    if (ebx == 0x0) {
                                                            var_24 = GetLastError();
                                                            if (*dword_bc71fc != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                    ebx = eax;
                                                            }
                                                            if (ebx == 0x0) {
                                                                    arg_0 = &var_44;
                                                                    esp = esp - 0x10;
                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                    ebx = var_28;
                                                            }
                                                    }
                                                    *arg_4 = ebx;
                                                    if (*dword_bc7200 != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc7200(0x5, &var_44);
                                                    }
                                                    eax = ebx;
                                            }
                                            else {
                                                    *arg_4 = ebx;
                                                    if (*dword_bc7200 != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc7200(0x5, &var_44);
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            ebx = GetProcAddress(edi, var_30);
                                            if (ebx == 0x0) {
                                                    var_24 = GetLastError();
                                                    if (*dword_bc71fc != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc71fc(0x4, &var_44);
                                                            ebx = eax;
                                                    }
                                                    if (ebx == 0x0) {
                                                            arg_0 = &var_44;
                                                            esp = esp - 0x10;
                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                            ebx = var_28;
                                                    }
                                            }
                                            *arg_4 = ebx;
                                            if (*dword_bc7200 != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc7200(0x5, &var_44);
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    ebx = GetProcAddress(edi, var_30);
                                    if (ebx == 0x0) {
                                            var_24 = GetLastError();
                                            if (*dword_bc71fc != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc71fc(0x4, &var_44);
                                                    ebx = eax;
                                            }
                                            if (ebx == 0x0) {
                                                    arg_0 = &var_44;
                                                    esp = esp - 0x10;
                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                    ebx = var_28;
                                            }
                                    }
                                    *arg_4 = ebx;
                                    if (*dword_bc7200 != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc7200(0x5, &var_44);
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            ebx = GetProcAddress(edi, var_30);
                            if (ebx == 0x0) {
                                    var_24 = GetLastError();
                                    if (*dword_bc71fc != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc71fc(0x4, &var_44);
                                            ebx = eax;
                                    }
                                    if (ebx == 0x0) {
                                            arg_0 = &var_44;
                                            esp = esp - 0x10;
                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                            ebx = var_28;
                                    }
                            }
                            *arg_4 = ebx;
                            if (*dword_bc7200 != 0x0) {
                                    esp = esp - 0x8;
                                    eax = dword_bc7200(0x5, &var_44);
                            }
                            eax = ebx;
                    }
            }
            else {
                    esp = esp - 0x8;
                    ebx = GetProcAddress(edi, var_30);
                    if (ebx == 0x0) {
                            var_24 = GetLastError();
                            if (*dword_bc71fc != 0x0) {
                                    esp = esp - 0x8;
                                    eax = dword_bc71fc(0x4, &var_44);
                                    ebx = eax;
                            }
                            if (ebx == 0x0) {
                                    arg_0 = &var_44;
                                    esp = esp - 0x10;
                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                    ebx = var_28;
                            }
                    }
                    *arg_4 = ebx;
                    if (*dword_bc7200 != 0x0) {
                            esp = esp - 0x8;
                            eax = dword_bc7200(0x5, &var_44);
                    }
                    eax = ebx;
            }
    }
    else {
            esp = esp - 0x8;
            ebx = GetProcAddress(edi, var_30);
            if (ebx == 0x0) {
                    var_24 = GetLastError();
                    if (*dword_bc71fc != 0x0) {
                            esp = esp - 0x8;
                            eax = dword_bc71fc(0x4, &var_44);
                            ebx = eax;
                    }
                    if (ebx == 0x0) {
                            arg_0 = &var_44;
                            esp = esp - 0x10;
                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                            ebx = var_28;
                    }
            }
            *arg_4 = ebx;
            if (*dword_bc7200 != 0x0) {
                    esp = esp - 0x8;
                    eax = dword_bc7200(0x5, &var_44);
            }
            eax = ebx;
    }
    return eax;

loc_493c34:
    esp = esp - 0x4;
    edi = LoadLibraryA(var_38);
    if (edi != 0x0) goto .l3;
    goto loc_493c43;

loc_493c26:
    esp = esp - 0x8;
    eax = dword_bc7200(0x1, &var_44);
    edi = eax;
    if (edi == 0x0) {
            esp = esp - 0x4;
            edi = LoadLibraryA(var_38);
            if (edi == 0x0) {
                    var_24 = GetLastError();
                    if (*dword_bc71fc != 0x0) {
                            esp = esp - 0x8;
                            eax = dword_bc71fc(0x3, &var_44);
                            edi = eax;
                            if (edi == 0x0) {
                                    arg_4 = &var_44;
                                    esp = esp - 0x10;
                                    RaiseException(0xc06d007e, 0x0, 0x1, &arg_4);
                                    eax = var_28;
                            }
                            else {
                                    esp = esp - 0x8;
                                    if (InterlockedExchange(var_18, edi) != edi) {
                                            if (esi[0x6] != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = LocalAlloc(0x40, 0x8);
                                                    if (eax != 0x0) {
                                                            eax[0x1] = esi;
                                                            *eax = *dword_bc71f8;
                                                            *dword_bc71f8 = eax;
                                                    }
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            FreeLibrary(edi);
                                    }
                                    if (*dword_bc7200 != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc7200(0x2, &var_44);
                                            ebx = eax;
                                    }
                                    if (ebx == 0x0) {
                                            if (esi[0x5] != ebx) {
                                                    if (esi[0x7] != ebx) {
                                                            eax = edi[0xf];
                                                            eax = eax + edi;
                                                            if (*eax == 0x4550) {
                                                                    if (eax[0x2] == var_4) {
                                                                            if (edi == eax[0xd]) {
                                                                                    ebx = *(arg_0 + var_C);
                                                                                    if (ebx == 0x0) {
                                                                                            esp = esp - 0x8;
                                                                                            ebx = GetProcAddress(edi, var_30);
                                                                                            if (ebx == 0x0) {
                                                                                                    var_24 = GetLastError();
                                                                                                    if (*dword_bc71fc != 0x0) {
                                                                                                            esp = esp - 0x8;
                                                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                                                            ebx = eax;
                                                                                                    }
                                                                                                    if (ebx == 0x0) {
                                                                                                            arg_0 = &var_44;
                                                                                                            esp = esp - 0x10;
                                                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                                            ebx = var_28;
                                                                                                    }
                                                                                            }
                                                                                            *arg_4 = ebx;
                                                                                            if (*dword_bc7200 != 0x0) {
                                                                                                    esp = esp - 0x8;
                                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                                            }
                                                                                            eax = ebx;
                                                                                    }
                                                                                    else {
                                                                                            *arg_4 = ebx;
                                                                                            if (*dword_bc7200 != 0x0) {
                                                                                                    esp = esp - 0x8;
                                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                                            }
                                                                                            eax = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x8;
                                                                                    ebx = GetProcAddress(edi, var_30);
                                                                                    if (ebx == 0x0) {
                                                                                            var_24 = GetLastError();
                                                                                            if (*dword_bc71fc != 0x0) {
                                                                                                    esp = esp - 0x8;
                                                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                                                    ebx = eax;
                                                                                            }
                                                                                            if (ebx == 0x0) {
                                                                                                    arg_0 = &var_44;
                                                                                                    esp = esp - 0x10;
                                                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                                    ebx = var_28;
                                                                                            }
                                                                                    }
                                                                                    *arg_4 = ebx;
                                                                                    if (*dword_bc7200 != 0x0) {
                                                                                            esp = esp - 0x8;
                                                                                            eax = dword_bc7200(0x5, &var_44);
                                                                                    }
                                                                                    eax = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x8;
                                                                            ebx = GetProcAddress(edi, var_30);
                                                                            if (ebx == 0x0) {
                                                                                    var_24 = GetLastError();
                                                                                    if (*dword_bc71fc != 0x0) {
                                                                                            esp = esp - 0x8;
                                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                                            ebx = eax;
                                                                                    }
                                                                                    if (ebx == 0x0) {
                                                                                            arg_0 = &var_44;
                                                                                            esp = esp - 0x10;
                                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                            ebx = var_28;
                                                                                    }
                                                                            }
                                                                            *arg_4 = ebx;
                                                                            if (*dword_bc7200 != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    ebx = GetProcAddress(edi, var_30);
                                                                    if (ebx == 0x0) {
                                                                            var_24 = GetLastError();
                                                                            if (*dword_bc71fc != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                                    ebx = eax;
                                                                            }
                                                                            if (ebx == 0x0) {
                                                                                    arg_0 = &var_44;
                                                                                    esp = esp - 0x10;
                                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                    ebx = var_28;
                                                                            }
                                                                    }
                                                                    *arg_4 = ebx;
                                                                    if (*dword_bc7200 != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc7200(0x5, &var_44);
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            ebx = GetProcAddress(edi, var_30);
                                                            if (ebx == 0x0) {
                                                                    var_24 = GetLastError();
                                                                    if (*dword_bc71fc != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                            ebx = eax;
                                                                    }
                                                                    if (ebx == 0x0) {
                                                                            arg_0 = &var_44;
                                                                            esp = esp - 0x10;
                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                            ebx = var_28;
                                                                    }
                                                            }
                                                            *arg_4 = ebx;
                                                            if (*dword_bc7200 != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc7200(0x5, &var_44);
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    ebx = GetProcAddress(edi, var_30);
                                                    if (ebx == 0x0) {
                                                            var_24 = GetLastError();
                                                            if (*dword_bc71fc != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                    ebx = eax;
                                                            }
                                                            if (ebx == 0x0) {
                                                                    arg_0 = &var_44;
                                                                    esp = esp - 0x10;
                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                    ebx = var_28;
                                                            }
                                                    }
                                                    *arg_4 = ebx;
                                                    if (*dword_bc7200 != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc7200(0x5, &var_44);
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            *arg_4 = ebx;
                                            if (*dword_bc7200 != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc7200(0x5, &var_44);
                                            }
                                            eax = ebx;
                                    }
                            }
                    }
                    else {
                            arg_4 = &var_44;
                            esp = esp - 0x10;
                            RaiseException(0xc06d007e, 0x0, 0x1, &arg_4);
                            eax = var_28;
                    }
            }
            else {
                    esp = esp - 0x8;
                    if (InterlockedExchange(var_18, edi) != edi) {
                            if (esi[0x6] != 0x0) {
                                    esp = esp - 0x8;
                                    eax = LocalAlloc(0x40, 0x8);
                                    if (eax != 0x0) {
                                            eax[0x1] = esi;
                                            *eax = *dword_bc71f8;
                                            *dword_bc71f8 = eax;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            FreeLibrary(edi);
                    }
                    if (*dword_bc7200 != 0x0) {
                            esp = esp - 0x8;
                            eax = dword_bc7200(0x2, &var_44);
                            ebx = eax;
                    }
                    if (ebx == 0x0) {
                            if (esi[0x5] != ebx) {
                                    if (esi[0x7] != ebx) {
                                            eax = edi[0xf];
                                            eax = eax + edi;
                                            if (*eax == 0x4550) {
                                                    if (eax[0x2] == var_4) {
                                                            if (edi == eax[0xd]) {
                                                                    ebx = *(arg_0 + var_C);
                                                                    if (ebx == 0x0) {
                                                                            esp = esp - 0x8;
                                                                            ebx = GetProcAddress(edi, var_30);
                                                                            if (ebx == 0x0) {
                                                                                    var_24 = GetLastError();
                                                                                    if (*dword_bc71fc != 0x0) {
                                                                                            esp = esp - 0x8;
                                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                                            ebx = eax;
                                                                                    }
                                                                                    if (ebx == 0x0) {
                                                                                            arg_0 = &var_44;
                                                                                            esp = esp - 0x10;
                                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                            ebx = var_28;
                                                                                    }
                                                                            }
                                                                            *arg_4 = ebx;
                                                                            if (*dword_bc7200 != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                                    else {
                                                                            *arg_4 = ebx;
                                                                            if (*dword_bc7200 != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    ebx = GetProcAddress(edi, var_30);
                                                                    if (ebx == 0x0) {
                                                                            var_24 = GetLastError();
                                                                            if (*dword_bc71fc != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                                    ebx = eax;
                                                                            }
                                                                            if (ebx == 0x0) {
                                                                                    arg_0 = &var_44;
                                                                                    esp = esp - 0x10;
                                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                    ebx = var_28;
                                                                            }
                                                                    }
                                                                    *arg_4 = ebx;
                                                                    if (*dword_bc7200 != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc7200(0x5, &var_44);
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            ebx = GetProcAddress(edi, var_30);
                                                            if (ebx == 0x0) {
                                                                    var_24 = GetLastError();
                                                                    if (*dword_bc71fc != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                            ebx = eax;
                                                                    }
                                                                    if (ebx == 0x0) {
                                                                            arg_0 = &var_44;
                                                                            esp = esp - 0x10;
                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                            ebx = var_28;
                                                                    }
                                                            }
                                                            *arg_4 = ebx;
                                                            if (*dword_bc7200 != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc7200(0x5, &var_44);
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    ebx = GetProcAddress(edi, var_30);
                                                    if (ebx == 0x0) {
                                                            var_24 = GetLastError();
                                                            if (*dword_bc71fc != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                    ebx = eax;
                                                            }
                                                            if (ebx == 0x0) {
                                                                    arg_0 = &var_44;
                                                                    esp = esp - 0x10;
                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                    ebx = var_28;
                                                            }
                                                    }
                                                    *arg_4 = ebx;
                                                    if (*dword_bc7200 != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc7200(0x5, &var_44);
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            ebx = GetProcAddress(edi, var_30);
                                            if (ebx == 0x0) {
                                                    var_24 = GetLastError();
                                                    if (*dword_bc71fc != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc71fc(0x4, &var_44);
                                                            ebx = eax;
                                                    }
                                                    if (ebx == 0x0) {
                                                            arg_0 = &var_44;
                                                            esp = esp - 0x10;
                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                            ebx = var_28;
                                                    }
                                            }
                                            *arg_4 = ebx;
                                            if (*dword_bc7200 != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc7200(0x5, &var_44);
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    ebx = GetProcAddress(edi, var_30);
                                    if (ebx == 0x0) {
                                            var_24 = GetLastError();
                                            if (*dword_bc71fc != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc71fc(0x4, &var_44);
                                                    ebx = eax;
                                            }
                                            if (ebx == 0x0) {
                                                    arg_0 = &var_44;
                                                    esp = esp - 0x10;
                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                    ebx = var_28;
                                            }
                                    }
                                    *arg_4 = ebx;
                                    if (*dword_bc7200 != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc7200(0x5, &var_44);
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            *arg_4 = ebx;
                            if (*dword_bc7200 != 0x0) {
                                    esp = esp - 0x8;
                                    eax = dword_bc7200(0x5, &var_44);
                            }
                            eax = ebx;
                    }
            }
    }
    else {
            esp = esp - 0x8;
            if (InterlockedExchange(var_18, edi) != edi) {
                    if (esi[0x6] != 0x0) {
                            esp = esp - 0x8;
                            eax = LocalAlloc(0x40, 0x8);
                            if (eax != 0x0) {
                                    eax[0x1] = esi;
                                    *eax = *dword_bc71f8;
                                    *dword_bc71f8 = eax;
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    FreeLibrary(edi);
            }
            if (*dword_bc7200 != 0x0) {
                    esp = esp - 0x8;
                    eax = dword_bc7200(0x2, &var_44);
                    ebx = eax;
            }
            if (ebx == 0x0) {
                    if (esi[0x5] != ebx) {
                            if (esi[0x7] != ebx) {
                                    eax = edi[0xf];
                                    eax = eax + edi;
                                    if (*eax == 0x4550) {
                                            if (eax[0x2] == var_4) {
                                                    if (edi == eax[0xd]) {
                                                            ebx = *(arg_0 + var_C);
                                                            if (ebx == 0x0) {
                                                                    esp = esp - 0x8;
                                                                    ebx = GetProcAddress(edi, var_30);
                                                                    if (ebx == 0x0) {
                                                                            var_24 = GetLastError();
                                                                            if (*dword_bc71fc != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                                    ebx = eax;
                                                                            }
                                                                            if (ebx == 0x0) {
                                                                                    arg_0 = &var_44;
                                                                                    esp = esp - 0x10;
                                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                    ebx = var_28;
                                                                            }
                                                                    }
                                                                    *arg_4 = ebx;
                                                                    if (*dword_bc7200 != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc7200(0x5, &var_44);
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                            else {
                                                                    *arg_4 = ebx;
                                                                    if (*dword_bc7200 != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc7200(0x5, &var_44);
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            ebx = GetProcAddress(edi, var_30);
                                                            if (ebx == 0x0) {
                                                                    var_24 = GetLastError();
                                                                    if (*dword_bc71fc != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                            ebx = eax;
                                                                    }
                                                                    if (ebx == 0x0) {
                                                                            arg_0 = &var_44;
                                                                            esp = esp - 0x10;
                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                            ebx = var_28;
                                                                    }
                                                            }
                                                            *arg_4 = ebx;
                                                            if (*dword_bc7200 != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc7200(0x5, &var_44);
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    ebx = GetProcAddress(edi, var_30);
                                                    if (ebx == 0x0) {
                                                            var_24 = GetLastError();
                                                            if (*dword_bc71fc != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                    ebx = eax;
                                                            }
                                                            if (ebx == 0x0) {
                                                                    arg_0 = &var_44;
                                                                    esp = esp - 0x10;
                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                    ebx = var_28;
                                                            }
                                                    }
                                                    *arg_4 = ebx;
                                                    if (*dword_bc7200 != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc7200(0x5, &var_44);
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            ebx = GetProcAddress(edi, var_30);
                                            if (ebx == 0x0) {
                                                    var_24 = GetLastError();
                                                    if (*dword_bc71fc != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc71fc(0x4, &var_44);
                                                            ebx = eax;
                                                    }
                                                    if (ebx == 0x0) {
                                                            arg_0 = &var_44;
                                                            esp = esp - 0x10;
                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                            ebx = var_28;
                                                    }
                                            }
                                            *arg_4 = ebx;
                                            if (*dword_bc7200 != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc7200(0x5, &var_44);
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    ebx = GetProcAddress(edi, var_30);
                                    if (ebx == 0x0) {
                                            var_24 = GetLastError();
                                            if (*dword_bc71fc != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc71fc(0x4, &var_44);
                                                    ebx = eax;
                                            }
                                            if (ebx == 0x0) {
                                                    arg_0 = &var_44;
                                                    esp = esp - 0x10;
                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                    ebx = var_28;
                                            }
                                    }
                                    *arg_4 = ebx;
                                    if (*dword_bc7200 != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc7200(0x5, &var_44);
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            ebx = GetProcAddress(edi, var_30);
                            if (ebx == 0x0) {
                                    var_24 = GetLastError();
                                    if (*dword_bc71fc != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc71fc(0x4, &var_44);
                                            ebx = eax;
                                    }
                                    if (ebx == 0x0) {
                                            arg_0 = &var_44;
                                            esp = esp - 0x10;
                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                            ebx = var_28;
                                    }
                            }
                            *arg_4 = ebx;
                            if (*dword_bc7200 != 0x0) {
                                    esp = esp - 0x8;
                                    eax = dword_bc7200(0x5, &var_44);
                            }
                            eax = ebx;
                    }
            }
            else {
                    *arg_4 = ebx;
                    if (*dword_bc7200 != 0x0) {
                            esp = esp - 0x8;
                            eax = dword_bc7200(0x5, &var_44);
                    }
                    eax = ebx;
            }
    }
    return eax;

.l3:
    esp = esp - 0x8;
    if (InterlockedExchange(var_18, edi) != edi) {
            if (esi[0x6] != 0x0) {
                    esp = esp - 0x8;
                    eax = LocalAlloc(0x40, 0x8);
                    if (eax != 0x0) {
                            eax[0x1] = esi;
                            *eax = *dword_bc71f8;
                            *dword_bc71f8 = eax;
                    }
            }
    }
    else {
            esp = esp - 0x4;
            FreeLibrary(edi);
    }
    goto loc_493cbf;

loc_493c43:
    var_24 = GetLastError();
    if (*dword_bc71fc != 0x0) {
            esp = esp - 0x8;
            eax = dword_bc71fc(0x3, &var_44);
            edi = eax;
            if (edi == 0x0) {
                    arg_4 = &var_44;
                    esp = esp - 0x10;
                    RaiseException(0xc06d007e, 0x0, 0x1, &arg_4);
                    eax = var_28;
            }
            else {
                    esp = esp - 0x8;
                    if (InterlockedExchange(var_18, edi) != edi) {
                            if (esi[0x6] != 0x0) {
                                    esp = esp - 0x8;
                                    eax = LocalAlloc(0x40, 0x8);
                                    if (eax != 0x0) {
                                            eax[0x1] = esi;
                                            *eax = *dword_bc71f8;
                                            *dword_bc71f8 = eax;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            FreeLibrary(edi);
                    }
                    if (*dword_bc7200 != 0x0) {
                            esp = esp - 0x8;
                            eax = dword_bc7200(0x2, &var_44);
                            ebx = eax;
                    }
                    if (ebx == 0x0) {
                            if (esi[0x5] != ebx) {
                                    if (esi[0x7] != ebx) {
                                            eax = edi[0xf];
                                            eax = eax + edi;
                                            if (*eax == 0x4550) {
                                                    if (eax[0x2] == var_4) {
                                                            if (edi == eax[0xd]) {
                                                                    ebx = *(arg_0 + var_C);
                                                                    if (ebx == 0x0) {
                                                                            esp = esp - 0x8;
                                                                            ebx = GetProcAddress(edi, var_30);
                                                                            if (ebx == 0x0) {
                                                                                    var_24 = GetLastError();
                                                                                    if (*dword_bc71fc != 0x0) {
                                                                                            esp = esp - 0x8;
                                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                                            ebx = eax;
                                                                                    }
                                                                                    if (ebx == 0x0) {
                                                                                            arg_0 = &var_44;
                                                                                            esp = esp - 0x10;
                                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                            ebx = var_28;
                                                                                    }
                                                                            }
                                                                            *arg_4 = ebx;
                                                                            if (*dword_bc7200 != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                                    else {
                                                                            *arg_4 = ebx;
                                                                            if (*dword_bc7200 != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc7200(0x5, &var_44);
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    ebx = GetProcAddress(edi, var_30);
                                                                    if (ebx == 0x0) {
                                                                            var_24 = GetLastError();
                                                                            if (*dword_bc71fc != 0x0) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                                    ebx = eax;
                                                                            }
                                                                            if (ebx == 0x0) {
                                                                                    arg_0 = &var_44;
                                                                                    esp = esp - 0x10;
                                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                                    ebx = var_28;
                                                                            }
                                                                    }
                                                                    *arg_4 = ebx;
                                                                    if (*dword_bc7200 != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc7200(0x5, &var_44);
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            ebx = GetProcAddress(edi, var_30);
                                                            if (ebx == 0x0) {
                                                                    var_24 = GetLastError();
                                                                    if (*dword_bc71fc != 0x0) {
                                                                            esp = esp - 0x8;
                                                                            eax = dword_bc71fc(0x4, &var_44);
                                                                            ebx = eax;
                                                                    }
                                                                    if (ebx == 0x0) {
                                                                            arg_0 = &var_44;
                                                                            esp = esp - 0x10;
                                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                            ebx = var_28;
                                                                    }
                                                            }
                                                            *arg_4 = ebx;
                                                            if (*dword_bc7200 != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc7200(0x5, &var_44);
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    ebx = GetProcAddress(edi, var_30);
                                                    if (ebx == 0x0) {
                                                            var_24 = GetLastError();
                                                            if (*dword_bc71fc != 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = dword_bc71fc(0x4, &var_44);
                                                                    ebx = eax;
                                                            }
                                                            if (ebx == 0x0) {
                                                                    arg_0 = &var_44;
                                                                    esp = esp - 0x10;
                                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                                    ebx = var_28;
                                                            }
                                                    }
                                                    *arg_4 = ebx;
                                                    if (*dword_bc7200 != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc7200(0x5, &var_44);
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            ebx = GetProcAddress(edi, var_30);
                                            if (ebx == 0x0) {
                                                    var_24 = GetLastError();
                                                    if (*dword_bc71fc != 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = dword_bc71fc(0x4, &var_44);
                                                            ebx = eax;
                                                    }
                                                    if (ebx == 0x0) {
                                                            arg_0 = &var_44;
                                                            esp = esp - 0x10;
                                                            RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                            ebx = var_28;
                                                    }
                                            }
                                            *arg_4 = ebx;
                                            if (*dword_bc7200 != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc7200(0x5, &var_44);
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    ebx = GetProcAddress(edi, var_30);
                                    if (ebx == 0x0) {
                                            var_24 = GetLastError();
                                            if (*dword_bc71fc != 0x0) {
                                                    esp = esp - 0x8;
                                                    eax = dword_bc71fc(0x4, &var_44);
                                                    ebx = eax;
                                            }
                                            if (ebx == 0x0) {
                                                    arg_0 = &var_44;
                                                    esp = esp - 0x10;
                                                    RaiseException(0xc06d007f, ebx, 0x1, &arg_0);
                                                    ebx = var_28;
                                            }
                                    }
                                    *arg_4 = ebx;
                                    if (*dword_bc7200 != 0x0) {
                                            esp = esp - 0x8;
                                            eax = dword_bc7200(0x5, &var_44);
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            *arg_4 = ebx;
                            if (*dword_bc7200 != 0x0) {
                                    esp = esp - 0x8;
                                    eax = dword_bc7200(0x5, &var_44);
                            }
                            eax = ebx;
                    }
            }
    }
    else {
            arg_4 = &var_44;
            esp = esp - 0x10;
            RaiseException(0xc06d007e, 0x0, 0x1, &arg_4);
            eax = var_28;
    }
    return eax;
}
