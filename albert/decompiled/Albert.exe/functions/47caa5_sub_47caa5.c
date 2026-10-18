// sub_47caa5 @ 0x47caa5
// hopper name: sub_47caa5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47caa5() {
    esp = esp - 0x8;
    eax = sub_47f31c(0x4c34c8, 0x10);
    ebx = arg_4;
    if (ebx == 0x0) {
            sub_47c836();
            sub_47f361();
    }
    else {
            esi = arg_8;
            if (esi == 0x0) {
                    sub_47c8f9();
                    sub_47f361();
            }
            else {
                    if (*dword_bc720c == 0x3) {
                            while (true) {
                                    edi = 0x0;
                                    decomp_var_1c = 0x0;
                                    if (esi > 0xffffffe0) {
                                            temp_0 = 0x3;
                                            break;
                                    }
                                    sub_487c06(0x4);
                                    eax = sub_487d79(ebx);
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    decomp_var_20 = eax;
                                    if (eax != 0x0) {
                                            if (esi <= *dword_bc7218) {
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_48826e(eax, ebx, esi) != 0x0) {
                                                            decomp_var_1c = ebx;
                                                    }
                                                    else {
                                                            eax = sub_48854d(esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                            decomp_var_1c = eax;
                                                            if (eax != 0x0) {
                                                                    eax = *(ebx - 0x4);
                                                                    eax = eax - 0x1;
                                                                    if (eax >= esi) {
                                                                            eax = esi;
                                                                    }
                                                                    sub_47c000(decomp_var_1c, ebx, eax);
                                                                    decomp_var_1c = ebx;
                                                                    decomp_var_20 = sub_487d79(ebx);
                                                                    sub_487da4(decomp_var_20, decomp_var_1c);
                                                                    esp = (esp - 0x18) + 0x18;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_1c == 0x0) {
                                                    if (esi == 0x0) {
                                                            esi = 0x1;
                                                    }
                                                    esi = esi + 0xf & 0xfffffff0;
                                                    esp = esp - 0xc;
                                                    eax = HeapAlloc(*dword_bc69f4, 0x0, esi);
                                                    decomp_var_1c = eax;
                                                    if (eax != 0x0) {
                                                            eax = *(ebx - 0x4);
                                                            eax = eax - 0x1;
                                                            if (eax >= esi) {
                                                                    eax = esi;
                                                            }
                                                            sub_47c000(decomp_var_1c, ebx, eax);
                                                            decomp_var_1c = decomp_var_20;
                                                            sub_487da4(decomp_var_1c, ebx);
                                                            esp = (esp - 0x14) + 0x14;
                                                    }
                                            }
                                    }
                                    eax = sub_47cbe9();
                                    if (decomp_var_20 == 0x0) {
                                            if (esi == 0x0) {
                                                    esi = esi + 0x1;
                                            }
                                            esi = esi + 0xf & 0xfffffff0;
                                            esp = esp - 0x10;
                                            eax = HeapReAlloc(*dword_bc69f4, 0x0, ebx, esi);
                                            edi = eax;
                                    }
                                    else {
                                            edi = decomp_var_1c;
                                    }
                                    if (edi != 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (*dword_bc6d10 == edi) {
                                            if (edi == 0x0) {
                                                    eax = sub_47d812();
                                                    if (decomp_var_20 != edi) {
                                                            *eax = 0xc;
                                                            temp_0 = 0x1;
                                                    }
                                                    else {
                                                            temp_0 = 0x5;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x0;
                                            }
                                            break;
                                    }
                                    eax = sub_488ac8(esi);
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax != 0x0) {
                                            continue;
                                    }
                                    eax = sub_47d812();
                                    if (decomp_var_20 == edi) {
                                            temp_0 = 0x2;
                                    }
                                    else {
                                            temp_0 = 0x4;
                                    }
                                    break;
                            }
                            switch (temp_0) {
                                case 0:
                                    sub_47f361();
                                    break;
                                case 1:
                                    sub_47f361();
                                    break;
                                case 2:
                                    *eax = sub_47d7d7(GetLastError());
                                    sub_47f361();
                                    break;
                                case 3:
                                    sub_488ac8(esi);
                                    eax = sub_47d812();
                                    *eax = 0xc;
                                    sub_47f361();
                                    break;
                                default:
                                    if (temp_0 != 0x4) {
                                            *eax = sub_47d7d7(GetLastError());
                                    }
                                    else {
                                            *eax = 0xc;
                                    }
                                    sub_47f361();
                                    break;
                            }
                    }
                    else {
                            while (true) {
                                    if (esi > 0xffffffe0) {
                                            temp_1 = 0x2;
                                            break;
                                    }
                                    else {
                                            if (esi == 0x0) {
                                                    esi = esi + 0x1;
                                            }
                                            esp = esp - 0x10;
                                            eax = HeapReAlloc(*dword_bc69f4, 0x0, ebx, esi);
                                            edi = eax;
                                            if (edi == 0x0) {
                                                    if (*dword_bc6d10 != eax) {
                                                            eax = sub_488ac8(esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax != 0x0) {
                                                                    continue;
                                                            }
                                                            eax = sub_47d812();
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            if (edi == 0x0) {
                                                                    eax = sub_47d812();
                                                                    temp_1 = 0x3;
                                                            }
                                                            else {
                                                                    temp_1 = 0x0;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x4;
                                                    break;
                                            }
                                    }
                            }
                            switch (temp_1) {
                                case 0:
                                    sub_47f361();
                                    break;
                                case 1:
                                    *eax = sub_47d7d7(GetLastError());
                                    sub_47f361();
                                    break;
                                case 2:
                                    sub_488ac8(esi);
                                    eax = sub_47d812();
                                    *eax = 0xc;
                                    sub_47f361();
                                    break;
                                case 3:
                                    *eax = sub_47d7d7(GetLastError());
                                    sub_47f361();
                                    break;
                                default:
                                    sub_47f361();
                                    break;
                            }
                    }
            }
    }
    return;
}
