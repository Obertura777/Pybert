// sub_48dc9b @ 0x48dc9b
// hopper name: sub_48dc9b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48dc9b() {
    &saved_fp = &saved_fp & 0xfffffff0;
    var_4 = *dword_4c8db8 ^ &var_84;
    ecx = *(int16_t *)arg_8 & 0xffff;
    decomp_var_88 = ebx;
    decomp_var_8c = esi;
    esi = arg_4;
    eax = *esi;
    eax = eax - 0x1;
    esp = esp - 0x90;
    decomp_var_90 = edi;
    var_84 = ecx;
    if (eax != 0x0) {
            eax = eax - 0x1;
            if (eax != 0x0) {
                    eax = eax - 0x1;
                    if (eax != 0x0) {
                            eax = eax - 0x1;
                            if (eax != 0x0) {
                                    eax = eax - 0x1;
                                    if (eax != 0x0) {
                                            eax = eax - 0x2;
                                            if (eax != 0x0) {
                                                    if (eax == 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_94 = 0x10;
                                                            ebx = decomp_var_94;
                                                            edi = esi + 0x18;
                                                            esp = (esp + 0x4 - 0xc) + 0xc;
                                                            if (sub_492061(ebx, edi, ecx) == 0x0) {
                                                                    eax = arg_0;
                                                                    switch (eax) {
                                                                        case 16:
                                                                            asm { fld        qword [esi+0x10] };
                                                                            asm { fstp       qword [esp+0x90+var_50] };
                                                                            break;
                                                                        case 22:
                                                                            asm { fld        qword [esi+0x10] };
                                                                            asm { fstp       qword [esp+0x90+var_50] };
                                                                            break;
                                                                        case 29:
                                                                            asm { fld        qword [esi+0x10] };
                                                                            asm { fstp       qword [esp+0x90+var_50] };
                                                                            break;
                                                                        default:
                                                                            break;
                                                                    }
                                                                    eax = sub_492040(&var_80, &var_84, ebx, eax, esi + 0x8, edi);
                                                                    esp = (esp - 0x18) + 0x18;
                                                            }
                                                            sub_492281(var_84, 0xffff);
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (*esi != 0x8) {
                                                                    if (*dword_4c9fac == 0x0) {
                                                                            decomp_var_94 = esi;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (sub_481e45() == 0x0) {
                                                                                    sub_492242(*esi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_492242(*esi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_492242(*esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            eax = sub_47ad69();
                                                            &var_84 = ebp;
                                                    }
                                                    else {
                                                            sub_492281(var_84, 0xffff);
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (*esi != 0x8) {
                                                                    if (*dword_4c9fac == 0x0) {
                                                                            decomp_var_94 = esi;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (sub_481e45() == 0x0) {
                                                                                    sub_492242(*esi);
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_492242(*esi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_492242(*esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            eax = sub_47ad69();
                                                            &var_84 = ebp;
                                                    }
                                            }
                                            else {
                                                    *esi = 0x1;
                                                    sub_492281(var_84, 0xffff);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (*esi != 0x8) {
                                                            if (*dword_4c9fac == 0x0) {
                                                                    decomp_var_94 = esi;
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_481e45() == 0x0) {
                                                                            sub_492242(*esi);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_492242(*esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            sub_492242(*esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    eax = sub_47ad69();
                                                    &var_84 = ebp;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_94 = 0x8;
                                            ebx = decomp_var_94;
                                            edi = esi + 0x18;
                                            esp = (esp + 0x4 - 0xc) + 0xc;
                                            if (sub_492061(ebx, edi, ecx) == 0x0) {
                                                    eax = arg_0;
                                                    switch (eax) {
                                                        case 16:
                                                            asm { fld        qword [esi+0x10] };
                                                            asm { fstp       qword [esp+0x90+var_50] };
                                                            break;
                                                        case 22:
                                                            asm { fld        qword [esi+0x10] };
                                                            asm { fstp       qword [esp+0x90+var_50] };
                                                            break;
                                                        case 29:
                                                            asm { fld        qword [esi+0x10] };
                                                            asm { fstp       qword [esp+0x90+var_50] };
                                                            break;
                                                        default:
                                                            break;
                                                    }
                                                    eax = sub_492040(&var_80, &var_84, ebx, eax, esi + 0x8, edi);
                                                    esp = (esp - 0x18) + 0x18;
                                            }
                                            sub_492281(var_84, 0xffff);
                                            esp = (esp - 0x8) + 0x8;
                                            if (*esi != 0x8) {
                                                    if (*dword_4c9fac == 0x0) {
                                                            decomp_var_94 = esi;
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_481e45() == 0x0) {
                                                                    sub_492242(*esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            sub_492242(*esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                            else {
                                                    sub_492242(*esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            eax = sub_47ad69();
                                            &var_84 = ebp;
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_94 = 0x12;
                                    ebx = decomp_var_94;
                                    edi = esi + 0x18;
                                    esp = (esp + 0x4 - 0xc) + 0xc;
                                    if (sub_492061(ebx, edi, ecx) == 0x0) {
                                            eax = arg_0;
                                            switch (eax) {
                                                case 16:
                                                    asm { fld        qword [esi+0x10] };
                                                    asm { fstp       qword [esp+0x90+var_50] };
                                                    break;
                                                case 22:
                                                    asm { fld        qword [esi+0x10] };
                                                    asm { fstp       qword [esp+0x90+var_50] };
                                                    break;
                                                case 29:
                                                    asm { fld        qword [esi+0x10] };
                                                    asm { fstp       qword [esp+0x90+var_50] };
                                                    break;
                                                default:
                                                    break;
                                            }
                                            eax = sub_492040(&var_80, &var_84, ebx, eax, esi + 0x8, edi);
                                            esp = (esp - 0x18) + 0x18;
                                    }
                                    sub_492281(var_84, 0xffff);
                                    esp = (esp - 0x8) + 0x8;
                                    if (*esi != 0x8) {
                                            if (*dword_4c9fac == 0x0) {
                                                    decomp_var_94 = esi;
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_481e45() == 0x0) {
                                                            sub_492242(*esi);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                            else {
                                                    sub_492242(*esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                                    else {
                                            sub_492242(*esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    eax = sub_47ad69();
                                    &var_84 = ebp;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_94 = 0x11;
                            ebx = decomp_var_94;
                            edi = esi + 0x18;
                            esp = (esp + 0x4 - 0xc) + 0xc;
                            if (sub_492061(ebx, edi, ecx) == 0x0) {
                                    eax = arg_0;
                                    switch (eax) {
                                        case 16:
                                            asm { fld        qword [esi+0x10] };
                                            asm { fstp       qword [esp+0x90+var_50] };
                                            break;
                                        case 22:
                                            asm { fld        qword [esi+0x10] };
                                            asm { fstp       qword [esp+0x90+var_50] };
                                            break;
                                        case 29:
                                            asm { fld        qword [esi+0x10] };
                                            asm { fstp       qword [esp+0x90+var_50] };
                                            break;
                                        default:
                                            break;
                                    }
                                    eax = sub_492040(&var_80, &var_84, ebx, eax, esi + 0x8, edi);
                                    esp = (esp - 0x18) + 0x18;
                            }
                            sub_492281(var_84, 0xffff);
                            esp = (esp - 0x8) + 0x8;
                            if (*esi != 0x8) {
                                    if (*dword_4c9fac == 0x0) {
                                            decomp_var_94 = esi;
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_481e45() == 0x0) {
                                                    sub_492242(*esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                                    else {
                                            sub_492242(*esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                            else {
                                    sub_492242(*esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                            eax = sub_47ad69();
                            &var_84 = ebp;
                    }
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_94 = 0x4;
                    ebx = decomp_var_94;
                    edi = esi + 0x18;
                    esp = (esp + 0x4 - 0xc) + 0xc;
                    if (sub_492061(ebx, edi, ecx) == 0x0) {
                            eax = arg_0;
                            switch (eax) {
                                case 16:
                                    asm { fld        qword [esi+0x10] };
                                    asm { fstp       qword [esp+0x90+var_50] };
                                    break;
                                case 22:
                                    asm { fld        qword [esi+0x10] };
                                    asm { fstp       qword [esp+0x90+var_50] };
                                    break;
                                case 29:
                                    asm { fld        qword [esi+0x10] };
                                    asm { fstp       qword [esp+0x90+var_50] };
                                    break;
                                default:
                                    break;
                            }
                            eax = sub_492040(&var_80, &var_84, ebx, eax, esi + 0x8, edi);
                            esp = (esp - 0x18) + 0x18;
                    }
                    sub_492281(var_84, 0xffff);
                    esp = (esp - 0x8) + 0x8;
                    if (*esi != 0x8) {
                            if (*dword_4c9fac == 0x0) {
                                    decomp_var_94 = esi;
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_481e45() == 0x0) {
                                            sub_492242(*esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                            else {
                                    sub_492242(*esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    else {
                            sub_492242(*esi);
                            esp = (esp - 0x4) + 0x4;
                    }
                    eax = sub_47ad69();
                    &var_84 = ebp;
            }
    }
    else {
            esp = esp - 0x4;
            decomp_var_94 = 0x8;
            ebx = decomp_var_94;
            edi = esi + 0x18;
            esp = (esp + 0x4 - 0xc) + 0xc;
            if (sub_492061(ebx, edi, ecx) == 0x0) {
                    eax = arg_0;
                    switch (eax) {
                        case 16:
                            asm { fld        qword [esi+0x10] };
                            asm { fstp       qword [esp+0x90+var_50] };
                            break;
                        case 22:
                            asm { fld        qword [esi+0x10] };
                            asm { fstp       qword [esp+0x90+var_50] };
                            break;
                        case 29:
                            asm { fld        qword [esi+0x10] };
                            asm { fstp       qword [esp+0x90+var_50] };
                            break;
                        default:
                            break;
                    }
                    eax = sub_492040(&var_80, &var_84, ebx, eax, esi + 0x8, edi);
                    esp = (esp - 0x18) + 0x18;
            }
            sub_492281(var_84, 0xffff);
            esp = (esp - 0x8) + 0x8;
            if (*esi != 0x8) {
                    if (*dword_4c9fac == 0x0) {
                            decomp_var_94 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_481e45() == 0x0) {
                                    sub_492242(*esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    else {
                            sub_492242(*esi);
                            esp = (esp - 0x4) + 0x4;
                    }
            }
            else {
                    sub_492242(*esi);
                    esp = (esp - 0x4) + 0x4;
            }
            eax = sub_47ad69();
            &var_84 = ebp;
    }
    return eax;
}
