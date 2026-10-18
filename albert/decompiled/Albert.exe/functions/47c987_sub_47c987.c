// sub_47c987 @ 0x47c987
// hopper name: sub_47c987
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c987() {
    esp = esp - 0x8;
    sub_47f31c(0x4c34a8, 0xc);
    ecx = arg_4;
    if (ecx <= 0x0) goto loc_47c9ca;
    goto loc_47c99c;

loc_47c9ca:
    esi = ecx * arg_8;
    arg_4 = esi;
    if (esi != 0x0) goto .l2;
    goto loc_47c9d7;

loc_47c99c:
    esp = (esp - 0x4) + 0x4;
    if (0xffffffe0 / ecx - 0xffffffe0 / ecx + CARRY(EFLAGS(cf)) != 0xffffffff) goto loc_47c9ca;
    goto loc_47c9ab;

.l2:
    while (true) {
            if (esi <= 0xffffffe0) {
                    if (*dword_bc720c == 0x3) {
                            esi = esi + 0xf & 0xfffffff0;
                            if (arg_4 <= *dword_bc7218) {
                                    sub_487c06(0x4);
                                    sub_48854d(arg_4);
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    sub_47ca83();
                                    ebx = decomp_var_1c;
                                    if (ebx != 0x0) {
                                            edi = 0x0;
                                            sub_47ba40(ebx, 0x0, arg_4);
                                            esp = (esp - 0xc) + 0xc;
                                            if (ebx == edi) {
                                                    esp = esp - 0xc;
                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                    edi = 0x0;
                                                    if (ebx == 0x0) {
                                                            if (*dword_bc6d10 != edi) {
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_2 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_2 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_2 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_2 = 0x0;
                                                    break;
                                            }
                                    }
                                    else {
                                            esp = esp - 0xc;
                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                            if (ebx == 0x0) {
                                                    if (*dword_bc6d10 != 0x0) {
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_488ac8(esi) != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_2 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            temp_2 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_2 = 0x3;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    edi = 0x0;
                                    ebx = 0x0;
                                    if (0x0 == 0x0) {
                                            esp = esp - 0xc;
                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                            if (ebx == edi) {
                                                    if (*dword_bc6d10 != edi) {
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_488ac8(esi) != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_2 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            temp_2 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_2 = 0x3;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_2 = 0x0;
                                            break;
                                    }
                            }
                    }
                    else {
                            edi = 0x0;
                            ebx = 0x0;
                            if (0x0 == 0x0) {
                                    esp = esp - 0xc;
                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                    if (ebx == edi) {
                                            if (*dword_bc6d10 != edi) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_488ac8(esi) != 0x0) {
                                                            continue;
                                                    }
                                                    temp_2 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_2 = 0x2;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_2 = 0x3;
                                            break;
                                    }
                            }
                            else {
                                    temp_2 = 0x0;
                                    break;
                            }
                    }
            }
            else {
                    edi = 0x0;
                    ebx = 0x0;
                    if (0x0 == 0x0) {
                            if (*dword_bc6d10 != edi) {
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_488ac8(esi) != 0x0) {
                                            continue;
                                    }
                                    temp_2 = 0x1;
                                    break;
                            }
                            else {
                                    temp_2 = 0x2;
                                    break;
                            }
                    }
                    else {
                            temp_2 = 0x3;
                            break;
                    }
            }
    }
    if (temp_2 == 0x0) goto .l6;
    goto .l24;

loc_47c9d7:
    if (0x1 > 0xffffffe0) goto loc_47ca4d;
    goto loc_47c9e4;

loc_47c9ab:
    *sub_47d812() = 0xc;
    sub_47a924();
    goto loc_47ca9f;

.l6:
    eax = sub_47f361();
    return eax;

.l24:
    if (temp_2 == 0x1) goto loc_47ca68;
    goto .l25;

loc_47ca4d:
    if (0x0 != 0x0) goto .l5;
    goto loc_47ca51;

loc_47c9e4:
    if (*dword_bc720c == 0x3) {
            esi = 0x10 & 0xfffffff0;
            if (arg_4 <= *dword_bc7218) {
                    sub_487c06(0x4);
                    sub_48854d(arg_4);
                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                    sub_47ca83();
                    ebx = decomp_var_1c;
                    if (ebx != 0x0) {
                            sub_47ba40(ebx, 0x0, arg_4);
                            esp = (esp - 0xc) + 0xc;
                            edi = 0x0;
                            if (ebx == 0x0) {
                                    esp = esp - 0xc;
                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                    if (ebx == edi) {
                                            edi = 0x0;
                                            if (*dword_bc6d10 != 0x0) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_488ac8(esi) == 0x0) {
                                                            eax = arg_c;
                                                            if (eax != edi) {
                                                                    *eax = 0xc;
                                                            }
                                                            eax = sub_47f361();
                                                    }
                                                    else {
                                                            while (true) {
                                                                    if (esi <= 0xffffffe0) {
                                                                            if (*dword_bc720c == 0x3) {
                                                                                    esi = esi + 0xf & 0xfffffff0;
                                                                                    if (arg_4 <= *dword_bc7218) {
                                                                                            sub_487c06(0x4);
                                                                                            sub_48854d(arg_4);
                                                                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                                            sub_47ca83();
                                                                                            ebx = decomp_var_1c;
                                                                                            if (ebx != edi) {
                                                                                                    sub_47ba40(ebx, edi, arg_4);
                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                    if (ebx == edi) {
                                                                                                            esp = esp - 0xc;
                                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                                            if (ebx == edi) {
                                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_2 = 0x1;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            temp_2 = 0x2;
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_2 = 0x3;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x0;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0xc;
                                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                                    if (ebx == edi) {
                                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_2 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_2 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = 0x0;
                                                                                            if (0x0 == edi) {
                                                                                                    esp = esp - 0xc;
                                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                                    if (ebx == edi) {
                                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_2 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_2 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = 0x0;
                                                                                    if (0x0 == edi) {
                                                                                            esp = esp - 0xc;
                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                            if (ebx == edi) {
                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_2 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = 0x0;
                                                                            if (0x0 == edi) {
                                                                                    if (*dword_bc6d10 != edi) {
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_2 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x3;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            switch (temp_2) {
                                                                case 0:
                                                                    eax = sub_47f361();
                                                                    break;
                                                                case 1:
                                                                    eax = arg_c;
                                                                    if (eax != 0x0) {
                                                                            *eax = 0xc;
                                                                    }
                                                                    eax = sub_47f361();
                                                                    break;
                                                                case 2:
                                                                    if (ebx == edi) {
                                                                            eax = arg_c;
                                                                            if (eax != 0x0) {
                                                                                    *eax = 0xc;
                                                                            }
                                                                    }
                                                                    eax = sub_47f361();
                                                                    break;
                                                                default:
                                                                    eax = sub_47f361();
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (ebx == 0x0) {
                                                            eax = arg_c;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xc;
                                                            }
                                                    }
                                                    eax = sub_47f361();
                                            }
                                    }
                                    else {
                                            eax = sub_47f361();
                                    }
                            }
                            else {
                                    eax = sub_47f361();
                            }
                    }
                    else {
                            esp = esp - 0xc;
                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                            if (ebx == 0x0) {
                                    edi = 0x0;
                                    if (*dword_bc6d10 != 0x0) {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_488ac8(esi) == 0x0) {
                                                    eax = arg_c;
                                                    if (eax != edi) {
                                                            *eax = 0xc;
                                                    }
                                                    eax = sub_47f361();
                                            }
                                            else {
                                                    while (true) {
                                                            if (esi <= 0xffffffe0) {
                                                                    if (*dword_bc720c == 0x3) {
                                                                            esi = esi + 0xf & 0xfffffff0;
                                                                            if (arg_4 <= *dword_bc7218) {
                                                                                    sub_487c06(0x4);
                                                                                    sub_48854d(arg_4);
                                                                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                                    sub_47ca83();
                                                                                    ebx = decomp_var_1c;
                                                                                    if (ebx != edi) {
                                                                                            sub_47ba40(ebx, edi, arg_4);
                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                            if (ebx == edi) {
                                                                                                    esp = esp - 0xc;
                                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                                    if (ebx == edi) {
                                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_2 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_2 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0xc;
                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                            if (ebx == edi) {
                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_2 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = 0x0;
                                                                                    if (0x0 == edi) {
                                                                                            esp = esp - 0xc;
                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                            if (ebx == edi) {
                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_2 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = 0x0;
                                                                            if (0x0 == edi) {
                                                                                    esp = esp - 0xc;
                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                    if (ebx == edi) {
                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_2 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = 0x0;
                                                                    if (0x0 == edi) {
                                                                            if (*dword_bc6d10 != edi) {
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_2 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_2 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    switch (temp_2) {
                                                        case 0:
                                                            eax = sub_47f361();
                                                            break;
                                                        case 1:
                                                            eax = arg_c;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xc;
                                                            }
                                                            eax = sub_47f361();
                                                            break;
                                                        case 2:
                                                            if (ebx == 0x0) {
                                                                    eax = arg_c;
                                                                    if (eax != 0x0) {
                                                                            *eax = 0xc;
                                                                    }
                                                            }
                                                            eax = sub_47f361();
                                                            break;
                                                        default:
                                                            eax = sub_47f361();
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (ebx == edi) {
                                                    eax = arg_c;
                                                    if (eax != 0x0) {
                                                            *eax = 0xc;
                                                    }
                                            }
                                            eax = sub_47f361();
                                    }
                            }
                            else {
                                    eax = sub_47f361();
                            }
                    }
            }
            else {
                    if (0x0 == 0x0) {
                            esp = esp - 0xc;
                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                            edi = 0x0;
                            if (ebx == 0x0) {
                                    if (*dword_bc6d10 != edi) {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_488ac8(esi) == 0x0) {
                                                    eax = arg_c;
                                                    if (eax != 0x0) {
                                                            *eax = 0xc;
                                                    }
                                                    eax = sub_47f361();
                                            }
                                            else {
                                                    while (true) {
                                                            if (esi <= 0xffffffe0) {
                                                                    if (*dword_bc720c == 0x3) {
                                                                            esi = esi + 0xf & 0xfffffff0;
                                                                            if (arg_4 <= *dword_bc7218) {
                                                                                    sub_487c06(0x4);
                                                                                    sub_48854d(arg_4);
                                                                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                                    sub_47ca83();
                                                                                    ebx = decomp_var_1c;
                                                                                    if (ebx != edi) {
                                                                                            sub_47ba40(ebx, edi, arg_4);
                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                            if (ebx == edi) {
                                                                                                    esp = esp - 0xc;
                                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                                    if (ebx == edi) {
                                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_2 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_2 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0xc;
                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                            if (ebx == edi) {
                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_2 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = 0x0;
                                                                                    if (0x0 == edi) {
                                                                                            esp = esp - 0xc;
                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                            if (ebx == edi) {
                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_2 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = 0x0;
                                                                            if (0x0 == edi) {
                                                                                    esp = esp - 0xc;
                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                    if (ebx == edi) {
                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_2 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = 0x0;
                                                                    if (0x0 == edi) {
                                                                            if (*dword_bc6d10 != edi) {
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_2 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_2 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    switch (temp_2) {
                                                        case 0:
                                                            eax = sub_47f361();
                                                            break;
                                                        case 1:
                                                            eax = arg_c;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xc;
                                                            }
                                                            eax = sub_47f361();
                                                            break;
                                                        case 2:
                                                            if (ebx == edi) {
                                                                    eax = arg_c;
                                                                    if (eax != 0x0) {
                                                                            *eax = 0xc;
                                                                    }
                                                            }
                                                            eax = sub_47f361();
                                                            break;
                                                        default:
                                                            eax = sub_47f361();
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            edi = 0x0;
                                            if (ebx == 0x0) {
                                                    eax = arg_c;
                                                    if (eax != edi) {
                                                            *eax = 0xc;
                                                    }
                                            }
                                            eax = sub_47f361();
                                    }
                            }
                            else {
                                    eax = sub_47f361();
                            }
                    }
                    else {
                            eax = sub_47f361();
                    }
            }
    }
    else {
            if (0x0 == 0x0) {
                    esp = esp - 0xc;
                    ebx = HeapAlloc(*dword_bc69f4, 0x8, 0x1);
                    edi = 0x0;
                    if (ebx == 0x0) {
                            if (*dword_bc6d10 != edi) {
                                    esi = 0x1;
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_488ac8(0x1) == 0x0) {
                                            eax = arg_c;
                                            if (eax != 0x0) {
                                                    *eax = 0xc;
                                            }
                                            eax = sub_47f361();
                                    }
                                    else {
                                            while (true) {
                                                    if (esi <= 0xffffffe0) {
                                                            if (*dword_bc720c == 0x3) {
                                                                    esi = esi + 0xf & 0xfffffff0;
                                                                    if (arg_4 <= *dword_bc7218) {
                                                                            sub_487c06(0x4);
                                                                            sub_48854d(arg_4);
                                                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                            sub_47ca83();
                                                                            ebx = decomp_var_1c;
                                                                            if (ebx != edi) {
                                                                                    sub_47ba40(ebx, edi, arg_4);
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (ebx == edi) {
                                                                                            esp = esp - 0xc;
                                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                            if (ebx == edi) {
                                                                                                    if (*dword_bc6d10 != edi) {
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_2 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_2 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0xc;
                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                    if (ebx == edi) {
                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_2 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = 0x0;
                                                                            if (0x0 == edi) {
                                                                                    esp = esp - 0xc;
                                                                                    ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                                    if (ebx == edi) {
                                                                                            if (*dword_bc6d10 != edi) {
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (sub_488ac8(esi) != 0x0) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_2 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_2 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = 0x0;
                                                                    if (0x0 == edi) {
                                                                            esp = esp - 0xc;
                                                                            ebx = HeapAlloc(*dword_bc69f4, 0x8, esi);
                                                                            if (ebx == edi) {
                                                                                    if (*dword_bc6d10 != edi) {
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_2 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x3;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ebx = 0x0;
                                                            if (0x0 == edi) {
                                                                    if (*dword_bc6d10 != edi) {
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (sub_488ac8(esi) != 0x0) {
                                                                                    continue;
                                                                            }
                                                                            temp_2 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_2 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_2 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            switch (temp_2) {
                                                case 0:
                                                    eax = sub_47f361();
                                                    break;
                                                case 1:
                                                    eax = arg_c;
                                                    if (eax != 0x0) {
                                                            *eax = 0xc;
                                                    }
                                                    eax = sub_47f361();
                                                    break;
                                                case 2:
                                                    if (ebx == edi) {
                                                            eax = arg_c;
                                                            if (eax != 0x0) {
                                                                    *eax = 0xc;
                                                            }
                                                    }
                                                    eax = sub_47f361();
                                                    break;
                                                default:
                                                    eax = sub_47f361();
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (ebx == 0x0) {
                                            eax = arg_c;
                                            if (eax != 0x0) {
                                                    *eax = 0xc;
                                            }
                                    }
                                    eax = sub_47f361();
                            }
                    }
                    else {
                            eax = sub_47f361();
                    }
            }
            else {
                    eax = sub_47f361();
            }
    }
    return eax;

loc_47ca9f:
    eax = sub_47f361();
    return eax;

loc_47ca68:
    eax = arg_c;
    if (eax != 0x0) {
            *eax = 0xc;
    }
    eax = sub_47f361();
    return eax;

.l25:
    if (temp_2 == 0x2) goto loc_47ca8c;
    goto loc_47ca9d;

.l5:
    eax = sub_47f361();
    return eax;

loc_47ca51:
    edi = 0x0;
    if (*dword_bc6d10 == 0x0) goto .l4;
    goto loc_47ca59;

loc_47ca8c:
    edi = 0x0;
    if (ebx == 0x0) {
            eax = arg_c;
            if (eax != edi) {
                    *eax = 0xc;
            }
    }
    goto loc_47ca9f;

loc_47ca9d:
    eax = sub_47f361();
    return eax;

.l4:
    if (0x0 == edi) {
            eax = arg_c;
            if (eax != edi) {
                    *eax = 0xc;
            }
    }
    eax = sub_47f361();
    return eax;

loc_47ca59:
    esi = 0x1;
    esp = (esp - 0x4) + 0x4;
    if (sub_488ac8(0x1) != 0x0) goto .l2;

.l3:
    eax = arg_c;
    if (eax != edi) {
            *eax = 0xc;
    }
    eax = sub_47f361();
    return eax;
}
