// sub_46f78c @ 0x46f78c
// hopper name: sub_46f78c
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f78c() {
    decomp_var_28 = ebx;
    ebx = arg_8;
    esp = esp - 0x8;
    decomp_var_2c = esi;
    decomp_var_4 = ecx;
    if (ebx == 0x0) {
            eax = 0x0;
    }
    else {
            eax = arg_4 - 0x0;
            esp = esp - 0x4;
            decomp_var_30 = edi;
            if (eax != 0x0) {
                    eax = eax - 0x2;
                    if (eax != 0x0) {
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
                    else {
                            esi = 0x0;
                            esp = esp - 0x4;
                            decomp_var_34 = *ebx;
                            eax = sub_473aee(decomp_var_34);
                            if (eax != 0x0) {
                                    edi = sub_47439d();
                                    if (edi != esi) {
                                            if (sub_472430() != 0x0) {
                                                    esi = 0x0;
                                                    if (edi[0x1a] != 0x0) {
                                                            edi = sub_46e5d5();
                                                            if (decomp_var_4[0x8] != esi) {
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_46f500(ebx) == 0x0) {
                                                                            if (ebx[0x1] == 0x202) {
                                                                                    esp = esp - 0x10;
                                                                                    SendMessageA(edi[0x8], 0x111, 0xe146, 0x0);
                                                                                    eax = 0x1;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    esi = 0x0;
                                                                                    sub_46e5d5();
                                                                                    if (arg_4 == 0x0) {
                                                                                            if (decomp_var_4[0x9] != esi) {
                                                                                                    eax = ebx[0x1];
                                                                                                    if (eax >= 0x100) {
                                                                                                            if (eax <= 0x109) {
                                                                                                                    esi = 0x0;
                                                                                                                    esp = esp - 0x4;
                                                                                                                    ebx = sub_477aab();
                                                                                                                    if (ebx == 0x0) {
                                                                                                                            sub_46dedc();
                                                                                                                    }
                                                                                                                    bool_13 = true;
                                                                                                                    if (ebx[0x38] == esi) {
                                                                                                                            ebx[0x38] = 0x1;
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                            decomp_var_20 = *arg_8;
                                                                                                                            esi = decomp_var_4;
                                                                                                                            if (sub_47679a() != 0x0) {
                                                                                                                                    eax = *esi;
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    eax = (eax[0x16])(&decomp_var_20);
                                                                                                                                    if (eax != 0x0) {
                                                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                                            eax = 0x1;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                                            eax = 0x0;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                                    eax = 0x0;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = 0x0;
                                                                                                                    }
                                                                                                                    esp = esp + 0x4;
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = 0x0;
                                                                                                                    esp = esp + 0x4;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = 0x0;
                                                                                                            esp = esp + 0x4;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = 0x0;
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x10;
                                                                            SendMessageA(edi[0x8], 0x111, 0xe146, 0x0);
                                                                            eax = 0x1;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = 0x0;
                                                                    sub_46e5d5();
                                                                    if (arg_4 == 0x0) {
                                                                            if (decomp_var_4[0x9] != esi) {
                                                                                    eax = ebx[0x1];
                                                                                    if (eax >= 0x100) {
                                                                                            if (eax <= 0x109) {
                                                                                                    esp = esp - 0x4;
                                                                                                    ebx = sub_477aab();
                                                                                                    if (ebx == esi) {
                                                                                                            sub_46dedc();
                                                                                                    }
                                                                                                    bool_15 = true;
                                                                                                    if (ebx[0x38] == esi) {
                                                                                                            ebx[0x38] = 0x1;
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            decomp_var_20 = *arg_8;
                                                                                                            esi = decomp_var_4;
                                                                                                            if (sub_47679a() != 0x0) {
                                                                                                                    eax = *esi;
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = (eax[0x16])(&decomp_var_20);
                                                                                                                    if (eax != 0x0) {
                                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                            eax = 0x1;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                            eax = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                    eax = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = 0x0;
                                                                                                    }
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                            else {
                                                                                                    eax = 0x0;
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi = 0x0;
                                                            sub_46e5d5();
                                                            if (arg_4 == 0x0) {
                                                                    if (decomp_var_4[0x9] != esi) {
                                                                            eax = ebx[0x1];
                                                                            if (eax >= 0x100) {
                                                                                    if (eax <= 0x109) {
                                                                                            esp = esp - 0x4;
                                                                                            ebx = sub_477aab();
                                                                                            if (ebx == esi) {
                                                                                                    sub_46dedc();
                                                                                            }
                                                                                            bool_36 = true;
                                                                                            if (ebx[0x38] == 0x0) {
                                                                                                    ebx[0x38] = 0x1;
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    decomp_var_20 = *arg_8;
                                                                                                    esi = decomp_var_4;
                                                                                                    if (sub_47679a() != 0x0) {
                                                                                                            eax = *esi;
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = (eax[0x16])(&decomp_var_20);
                                                                                                            if (eax != 0x0) {
                                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                    eax = 0x1;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                                    eax = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                            eax = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = 0x0;
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_46e5d5();
                                                    if (arg_4 == esi) {
                                                            if (decomp_var_4[0x9] != esi) {
                                                                    eax = ebx[0x1];
                                                                    if (eax >= 0x100) {
                                                                            if (eax <= 0x109) {
                                                                                    esp = esp - 0x4;
                                                                                    ebx = sub_477aab();
                                                                                    if (ebx == esi) {
                                                                                            sub_46dedc();
                                                                                    }
                                                                                    bool_58 = true;
                                                                                    if (ebx[0x38] == esi) {
                                                                                            ebx[0x38] = 0x1;
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            decomp_var_20 = *arg_8;
                                                                                            esi = decomp_var_4;
                                                                                            if (sub_47679a() != 0x0) {
                                                                                                    eax = *esi;
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = (eax[0x16])(&decomp_var_20);
                                                                                                    if (eax != 0x0) {
                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                            eax = 0x1;
                                                                                                    }
                                                                                                    else {
                                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                            eax = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                    eax = 0x0;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = 0x0;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                    }
                                    else {
                                            esi = 0x0;
                                            sub_46e5d5();
                                            if (arg_4 == 0x0) {
                                                    if (decomp_var_4[0x9] != esi) {
                                                            eax = ebx[0x1];
                                                            if (eax >= 0x100) {
                                                                    if (eax <= 0x109) {
                                                                            esp = esp - 0x4;
                                                                            ebx = sub_477aab();
                                                                            if (ebx == esi) {
                                                                                    sub_46dedc();
                                                                            }
                                                                            bool_69 = true;
                                                                            if (ebx[0x38] == esi) {
                                                                                    ebx[0x38] = 0x1;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    decomp_var_20 = *arg_8;
                                                                                    esi = decomp_var_4;
                                                                                    if (sub_47679a() != 0x0) {
                                                                                            eax = *esi;
                                                                                            esp = esp - 0x4;
                                                                                            eax = (eax[0x16])(&decomp_var_20);
                                                                                            if (eax != 0x0) {
                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                    eax = 0x1;
                                                                                            }
                                                                                            else {
                                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                                    eax = 0x0;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                            eax = 0x0;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                            }
                                    }
                            }
                            else {
                                    esi = 0x0;
                                    sub_46e5d5();
                                    if (arg_4 == 0x0) {
                                            if (decomp_var_4[0x9] != esi) {
                                                    eax = ebx[0x1];
                                                    if (eax >= 0x100) {
                                                            if (eax <= 0x109) {
                                                                    esp = esp - 0x4;
                                                                    ebx = sub_477aab();
                                                                    if (ebx == esi) {
                                                                            sub_46dedc();
                                                                    }
                                                                    bool_52 = true;
                                                                    if (ebx[0x38] == esi) {
                                                                            ebx[0x38] = 0x1;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            decomp_var_20 = *arg_8;
                                                                            esi = decomp_var_4;
                                                                            if (sub_47679a() != 0x0) {
                                                                                    eax = *esi;
                                                                                    esp = esp - 0x4;
                                                                                    eax = (eax[0x16])(&decomp_var_20);
                                                                                    if (eax != 0x0) {
                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                            eax = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                                            eax = 0x0;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                                    esp = esp + 0x4;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                            }
                    }
            }
            else {
                    esi = 0x0;
                    sub_46e5d5();
                    if (arg_4 == 0x0) {
                            if (decomp_var_4[0x9] != esi) {
                                    eax = ebx[0x1];
                                    if (eax >= 0x100) {
                                            if (eax <= 0x109) {
                                                    esp = esp - 0x4;
                                                    ebx = sub_477aab();
                                                    if (ebx == esi) {
                                                            sub_46dedc();
                                                    }
                                                    bool_8 = true;
                                                    if (ebx[0x38] == esi) {
                                                            ebx[0x38] = 0x1;
                                                            esp = (esp - 0x4) + 0x4;
                                                            decomp_var_20 = *arg_8;
                                                            esi = decomp_var_4;
                                                            if (sub_47679a() != 0x0) {
                                                                    eax = *esi;
                                                                    esp = esp - 0x4;
                                                                    eax = (eax[0x16])(&decomp_var_20);
                                                                    if (eax != 0x0) {
                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            ebx[0x38] = ebx[0x38] & 0x0;
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx[0x38] = ebx[0x38] & 0x0;
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
    }
    return eax;
}
