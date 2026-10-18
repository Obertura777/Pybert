// sub_48cc5f @ 0x48cc5f
// hopper name: sub_48cc5f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48cc5f() {
    decomp_var_2c = ebx;
    ebx = arg_4;
    decomp_var_30 = esi;
    esi = arg_8;
    esp = esp - 0xc;
    decomp_var_34 = edi;
    edi = arg_0;
    var_8 = 0x0;
    if (*dword_bc6f4c != 0x0) {
            eax = sub_47fe7c(*dword_bc7208);
            esp = (esp - 0x4) + 0x4;
    }
    else {
            eax = sub_481e45;
    }
    ecx = arg_c;
    bool_29 = ecx == edx;
    if (ecx <= 0xa6) {
            if (!bool_29) {
                    bool_17 = ecx == 0x19;
                    if (ecx <= 0x19) {
                            if (!bool_17) {
                                    esp = (esp - 0x4) + 0x4;
                                    edx = ecx - 0x2;
                                    if (edx != 0x0) {
                                            edx = edx - 0x1;
                                            if (edx != 0x0) {
                                                    edx = edx - 0x5;
                                                    if (edx != 0x0) {
                                                            edx = edx - 0x1;
                                                            if (edx != 0x0) {
                                                                    edx = edx - 0x5;
                                                                    if (edx != 0x0) {
                                                                            edx = edx - 0x1;
                                                                            if (edx != 0x0) {
                                                                                    if (edx == 0x9) {
                                                                                            var_28 = 0x3;
                                                                                            asm { fld        qword [edi] };
                                                                                            ecx = &var_28;
                                                                                            asm { fstp       qword [ebp+var_20] };
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_38 = ecx;
                                                                                            asm { fld        qword [ebx] };
                                                                                            asm { fstp       qword [ebp+var_18] };
                                                                                            asm { fld        qword [esi] };
                                                                                            asm { fstp       qword [ebp+var_10] };
                                                                                            eax = (eax)(decomp_var_38);
                                                                                            esp = esp + 0x4;
                                                                                            if (eax == 0x0) {
                                                                                                    eax = sub_47d812();
                                                                                                    *eax = 0x22;
                                                                                            }
                                                                                            asm { fld        qword [ebp+var_10] };
                                                                                            asm { fstp       qword [esi] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fld        qword [edi] };
                                                                                    ecx = &var_28;
                                                                                    asm { fstp       qword [ebp+var_20] };
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_38 = ecx;
                                                                                    asm { fld        qword [ebx] };
                                                                                    var_28 = 0x4;
                                                                                    asm { fstp       qword [ebp+var_18] };
                                                                                    asm { fld        qword [esi] };
                                                                                    asm { fstp       qword [ebp+var_10] };
                                                                                    eax = (eax)(decomp_var_38);
                                                                                    esp = esp + 0x4;
                                                                                    asm { fld        qword [ebp+var_10] };
                                                                                    asm { fstp       qword [esi] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            var_28 = 0x3;
                                                                            asm { fld        qword [edi] };
                                                                            ecx = &var_28;
                                                                            asm { fstp       qword [ebp+var_20] };
                                                                            esp = esp - 0x4;
                                                                            decomp_var_38 = ecx;
                                                                            asm { fld        qword [ebx] };
                                                                            asm { fstp       qword [ebp+var_18] };
                                                                            asm { fld        qword [esi] };
                                                                            asm { fstp       qword [ebp+var_10] };
                                                                            eax = (eax)(decomp_var_38);
                                                                            esp = esp + 0x4;
                                                                            if (eax == 0x0) {
                                                                                    eax = sub_47d812();
                                                                                    *eax = 0x22;
                                                                            }
                                                                            asm { fld        qword [ebp+var_10] };
                                                                            asm { fstp       qword [esi] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fld        qword [edi] };
                                                                    asm { fstp       qword [ebp+var_20] };
                                                                    asm { fld        qword [ebx] };
                                                                    asm { fstp       qword [ebp+var_18] };
                                                                    asm { fld        qword [esi] };
                                                                    ecx = &var_28;
                                                                    asm { fstp       qword [ebp+var_10] };
                                                                    var_28 = 0x1;
                                                                    eax = (eax)(ecx);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax == 0x0) {
                                                                            eax = sub_47d812();
                                                                            *eax = 0x21;
                                                                    }
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    asm { fstp       qword [esi] };
                                                            }
                                                    }
                                                    else {
                                                            var_28 = 0x2;
                                                            asm { fld        qword [edi] };
                                                            ecx = &var_28;
                                                            asm { fstp       qword [ebp+var_20] };
                                                            esp = esp - 0x4;
                                                            decomp_var_38 = ecx;
                                                            asm { fld        qword [ebx] };
                                                            asm { fstp       qword [ebp+var_18] };
                                                            asm { fld        qword [esi] };
                                                            asm { fstp       qword [ebp+var_10] };
                                                            eax = (eax)(decomp_var_38);
                                                            esp = esp + 0x4;
                                                            if (eax == 0x0) {
                                                                    eax = sub_47d812();
                                                                    *eax = 0x22;
                                                            }
                                                            asm { fld        qword [ebp+var_10] };
                                                            asm { fstp       qword [esi] };
                                                    }
                                            }
                                            else {
                                                    asm { fld        qword [edi] };
                                                    asm { fstp       qword [ebp+var_20] };
                                                    asm { fld        qword [ebx] };
                                                    asm { fstp       qword [ebp+var_18] };
                                                    asm { fld        qword [esi] };
                                                    ecx = &var_28;
                                                    asm { fstp       qword [ebp+var_10] };
                                                    var_28 = 0x1;
                                                    eax = (eax)(ecx);
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax == 0x0) {
                                                            eax = sub_47d812();
                                                            *eax = 0x21;
                                                    }
                                                    asm { fld        qword [ebp+var_10] };
                                                    asm { fstp       qword [esi] };
                                            }
                                    }
                                    else {
                                            var_28 = 0x2;
                                            asm { fld        qword [edi] };
                                            ecx = &var_28;
                                            asm { fstp       qword [ebp+var_20] };
                                            esp = esp - 0x4;
                                            decomp_var_38 = ecx;
                                            asm { fld        qword [ebx] };
                                            asm { fstp       qword [ebp+var_18] };
                                            asm { fld        qword [esi] };
                                            asm { fstp       qword [ebp+var_10] };
                                            eax = (eax)(decomp_var_38);
                                            esp = esp + 0x4;
                                            if (eax == 0x0) {
                                                    eax = sub_47d812();
                                                    *eax = 0x22;
                                            }
                                            asm { fld        qword [ebp+var_10] };
                                            asm { fstp       qword [esi] };
                                    }
                            }
                            else {
                                    asm { fld        qword [edi] };
                                    ecx = &var_28;
                                    asm { fstp       qword [ebp+var_20] };
                                    esp = esp - 0x4;
                                    decomp_var_38 = ecx;
                                    asm { fld        qword [ebx] };
                                    var_28 = 0x4;
                                    asm { fstp       qword [ebp+var_18] };
                                    asm { fld        qword [esi] };
                                    asm { fstp       qword [ebp+var_10] };
                                    eax = (eax)(decomp_var_38);
                                    esp = esp + 0x4;
                                    asm { fld        qword [ebp+var_10] };
                                    asm { fstp       qword [esi] };
                            }
                    }
                    else {
                            ecx = ecx - 0x1a;
                            if (ecx != 0x0) {
                                    ecx = ecx - 0x1;
                                    if (ecx != 0x0) {
                                            ecx = ecx - 0x1;
                                            if (ecx != 0x0) {
                                                    ecx = ecx - 0x1;
                                                    if (ecx != 0x0) {
                                                            ecx = ecx - 0x1d;
                                                            if (ecx != 0x0) {
                                                                    if (ecx == 0x3) {
                                                                            asm { fld        qword [edi] };
                                                                            asm { fstp       qword [ebp+var_20] };
                                                                            asm { fld        qword [ebx] };
                                                                            asm { fstp       qword [ebp+var_18] };
                                                                            asm { fld        qword [esi] };
                                                                            ecx = &var_28;
                                                                            asm { fstp       qword [ebp+var_10] };
                                                                            var_28 = 0x1;
                                                                            eax = (eax)(ecx);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (eax == 0x0) {
                                                                                    eax = sub_47d812();
                                                                                    *eax = 0x21;
                                                                            }
                                                                            asm { fld        qword [ebp+var_10] };
                                                                            asm { fstp       qword [esi] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fld        qword [edi] };
                                                                    asm { fstp       qword [ebp+var_20] };
                                                                    asm { fld        qword [ebx] };
                                                                    asm { fstp       qword [ebp+var_18] };
                                                                    asm { fld        qword [esi] };
                                                                    ecx = &var_28;
                                                                    asm { fstp       qword [ebp+var_10] };
                                                                    var_28 = 0x1;
                                                                    eax = (eax)(ecx);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (eax == 0x0) {
                                                                            eax = sub_47d812();
                                                                            *eax = 0x21;
                                                                    }
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    asm { fstp       qword [esi] };
                                                            }
                                                    }
                                                    else {
                                                            asm { fld        qword [edi] };
                                                            asm { fstp       qword [esi] };
                                                            asm { fld        qword [edi] };
                                                            asm { fstp       qword [ebp+var_20] };
                                                            asm { fld        qword [ebx] };
                                                            asm { fstp       qword [ebp+var_18] };
                                                            asm { fld        qword [esi] };
                                                            ecx = &var_28;
                                                            asm { fstp       qword [ebp+var_10] };
                                                            var_28 = 0x1;
                                                            eax = (eax)(ecx);
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (eax == 0x0) {
                                                                    eax = sub_47d812();
                                                                    *eax = 0x21;
                                                            }
                                                            asm { fld        qword [ebp+var_10] };
                                                            asm { fstp       qword [esi] };
                                                    }
                                            }
                                            else {
                                                    asm { fld        qword [edi] };
                                                    asm { fstp       qword [ebp+var_20] };
                                                    asm { fld        qword [ebx] };
                                                    asm { fstp       qword [ebp+var_18] };
                                                    asm { fld        qword [esi] };
                                                    ecx = &var_28;
                                                    asm { fstp       qword [ebp+var_10] };
                                                    var_28 = 0x1;
                                                    eax = (eax)(ecx);
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (eax == 0x0) {
                                                            eax = sub_47d812();
                                                            *eax = 0x21;
                                                    }
                                                    asm { fld        qword [ebp+var_10] };
                                                    asm { fstp       qword [esi] };
                                            }
                                    }
                                    else {
                                            var_28 = 0x2;
                                            asm { fld        qword [edi] };
                                            ecx = &var_28;
                                            asm { fstp       qword [ebp+var_20] };
                                            esp = esp - 0x4;
                                            decomp_var_38 = ecx;
                                            asm { fld        qword [ebx] };
                                            asm { fstp       qword [ebp+var_18] };
                                            asm { fld        qword [esi] };
                                            asm { fstp       qword [ebp+var_10] };
                                            eax = (eax)(decomp_var_38);
                                            esp = esp + 0x4;
                                            if (eax == 0x0) {
                                                    eax = sub_47d812();
                                                    *eax = 0x22;
                                            }
                                            asm { fld        qword [ebp+var_10] };
                                            asm { fstp       qword [esi] };
                                    }
                            }
                            else {
                                    asm { fld1 };
                                    asm { fstp       qword [esi] };
                            }
                    }
            }
            else {
                    var_28 = 0x3;
                    asm { fld        qword [edi] };
                    ecx = &var_28;
                    asm { fstp       qword [ebp+var_20] };
                    esp = esp - 0x4;
                    decomp_var_38 = ecx;
                    asm { fld        qword [ebx] };
                    asm { fstp       qword [ebp+var_18] };
                    asm { fld        qword [esi] };
                    asm { fstp       qword [ebp+var_10] };
                    eax = (eax)(decomp_var_38);
                    esp = esp + 0x4;
                    if (eax == 0x0) {
                            eax = sub_47d812();
                            *eax = 0x22;
                    }
                    asm { fld        qword [ebp+var_10] };
                    asm { fstp       qword [esi] };
            }
    }
    else {
            ecx = ecx + 0xfffffc18;
            if (ecx <= 0xc) {
                    switch (*(ecx * 0x4 + switch_table)) {
                        case 0:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 1:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 2:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 3:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 4:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 5:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 6:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 7:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 8:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        case 9:
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            asm { fld        qword [esi] };
                            break;
                        default:
                            if (*(ecx * 0x4 + switch_table) != 0xa) {
                            }
                            asm { fld        qword [edi] };
                            asm { fmul       qword [ebp+var_8] };
                            asm { fst        qword [esi] };
                            asm { fld        qword [edi] };
                            asm { fstp       qword [ebp+var_20] };
                            asm { fld        qword [ebx] };
                            asm { fstp       qword [ebp+var_18] };
                            break;
                    }
                    ecx = &var_28;
                    asm { fstp       qword [ebp+var_10] };
                    var_28 = 0x1;
                    eax = (eax)(ecx);
                    esp = (esp - 0x4) + 0x4;
                    if (eax == 0x0) {
                            eax = sub_47d812();
                            *eax = 0x21;
                    }
                    asm { fld        qword [ebp+var_10] };
                    asm { fstp       qword [esi] };
            }
    }
    return eax;
}
