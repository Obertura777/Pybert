// sub_48e1c4 @ 0x48e1c4
// hopper name: sub_48e1c4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e1c4() {
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    esi = arg_4;
    esp = esp - 0xc;
    decomp_var_1c = edi;
    edi = arg_8;
    if (esi == 0x0) {
            if (edi > 0x0) {
                    eax = arg_0;
                    if (eax != 0x0) {
                            *eax = 0x0;
                    }
                    eax = 0x0;
            }
            else {
                    eax = arg_0;
                    if (eax != 0x0) {
                            *eax = *eax | 0xffffffff;
                    }
                    if (edi > 0x7fffffff) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            esp = esp - 0x4;
                            sub_47aea2(arg_10);
                            eax = var_10;
                            if (eax[0x5] == 0x0) {
                                    eax = arg_c;
                                    if (eax > 0xff) {
                                            if (esi != 0x0 && edi > 0x0) {
                                                    sub_47ba40(esi, 0x0, edi);
                                                    esp = (esp - 0xc) + 0xc;
                                            }
                                            *sub_47d812() = 0x2a;
                                            eax = sub_47d812();
                                            eax = *eax;
                                            if (var_4 != 0x0) {
                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                            }
                                    }
                                    else {
                                            if (esi != 0x0) {
                                                    if (edi <= 0x0) {
                                                            *sub_47d812() = 0x22;
                                                            sub_47a924();
                                                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                            if (var_4 != 0x0) {
                                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                            }
                                                            eax = 0x22;
                                                    }
                                                    else {
                                                            *(int8_t *)esi = eax;
                                                            eax = arg_0;
                                                            if (eax != 0x0) {
                                                                    *eax = 0x1;
                                                            }
                                                            if (var_4 != 0x0) {
                                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                            }
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = arg_0;
                                                    if (eax != 0x0) {
                                                            *eax = 0x1;
                                                    }
                                                    if (var_4 != 0x0) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                            }
                                    }
                            }
                            else {
                                    ebx = 0x0;
                                    arg_4 = 0x0;
                                    esp = esp - 0x20;
                                    eax = WideCharToMultiByte(eax[0x1], 0x0, &arg_c, 0x1, esi, edi, 0x0, &arg_4);
                                    if (eax != 0x0) {
                                            ebx = 0x0;
                                            if (arg_4 == 0x0) {
                                                    ecx = arg_0;
                                                    if (ecx != ebx) {
                                                            *ecx = eax;
                                                    }
                                                    if (var_4 != ebx) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                            }
                                            else {
                                                    *sub_47d812() = 0x2a;
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                                    if (var_4 != ebx) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                            }
                                    }
                                    else {
                                            if (GetLastError() == 0x7a) {
                                                    if (esi != 0x0) {
                                                            ebx = 0x0;
                                                            if (edi > 0x0) {
                                                                    sub_47ba40(esi, ebx, edi);
                                                                    esp = (esp - 0xc) + 0xc;
                                                            }
                                                    }
                                                    *sub_47d812() = 0x22;
                                                    sub_47a924();
                                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                    if (var_4 != 0x0) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x22;
                                            }
                                            else {
                                                    *sub_47d812() = 0x2a;
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                                    if (var_4 != ebx) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            eax = arg_0;
            if (eax != 0x0) {
                    *eax = *eax | 0xffffffff;
            }
            if (edi > 0x7fffffff) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                    eax = 0x16;
            }
            else {
                    ebx = 0x0;
                    esp = esp - 0x4;
                    sub_47aea2(arg_10);
                    eax = var_10;
                    if (eax[0x5] == 0x0) {
                            eax = arg_c;
                            if (eax > 0xff) {
                                    if (esi != ebx && edi > ebx) {
                                            sub_47ba40(esi, ebx, edi);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    *sub_47d812() = 0x2a;
                                    eax = sub_47d812();
                                    eax = *eax;
                                    if (var_4 != ebx) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                            }
                            else {
                                    if (esi != ebx) {
                                            if (edi <= ebx) {
                                                    *sub_47d812() = 0x22;
                                                    sub_47a924();
                                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                    if (var_4 != ebx) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x22;
                                            }
                                            else {
                                                    *(int8_t *)esi = eax;
                                                    eax = arg_0;
                                                    if (eax != ebx) {
                                                            *eax = 0x1;
                                                    }
                                                    if (var_4 != ebx) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = arg_0;
                                            if (eax != ebx) {
                                                    *eax = 0x1;
                                            }
                                            if (var_4 != ebx) {
                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            arg_4 = ebx;
                            esp = esp - 0x20;
                            eax = WideCharToMultiByte(eax[0x1], ebx, &arg_c, 0x1, esi, edi, ebx, &arg_4);
                            if (eax != ebx) {
                                    if (arg_4 == ebx) {
                                            ecx = arg_0;
                                            if (ecx != ebx) {
                                                    *ecx = eax;
                                            }
                                            if (var_4 != ebx) {
                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                    }
                                    else {
                                            *sub_47d812() = 0x2a;
                                            eax = sub_47d812();
                                            eax = *eax;
                                            if (var_4 != ebx) {
                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                            }
                                    }
                            }
                            else {
                                    if (GetLastError() == 0x7a) {
                                            if (esi != ebx) {
                                                    if (edi > ebx) {
                                                            sub_47ba40(esi, ebx, edi);
                                                            esp = (esp - 0xc) + 0xc;
                                                    }
                                            }
                                            *sub_47d812() = 0x22;
                                            sub_47a924();
                                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                            if (var_4 != ebx) {
                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x22;
                                    }
                                    else {
                                            *sub_47d812() = 0x2a;
                                            eax = sub_47d812();
                                            eax = *eax;
                                            if (var_4 != ebx) {
                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                            }
                                    }
                            }
                    }
            }
    }
    return eax;
}
