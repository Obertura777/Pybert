// sub_4808d1 @ 0x4808d1
// hopper name: sub_4808d1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4808d1() {
    esp = esp - 0x8;
    sub_47f31c(0x4c36a0, 0xc);
    decomp_var_1c = 0x0;
    eax = arg_c;
    ecx = eax[0x1];
    if (ecx != 0x0) {
            if (ecx[0x8] != 0x0) {
                    edx = 0x0;
                    ecx = eax[0x2];
                    if (ecx == 0x0) {
                            if ((*eax & 0x80000000) != 0x0) {
                                    eax = *eax;
                                    esi = arg_8;
                                    if (eax >= 0x0) {
                                            esi = ecx + esi + 0xc;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_c = 0x1;
                                    bool_22 = (eax & 0x8) == 0x0;
                                    if ((eax & 0x8) != 0x0) {
                                            edi = arg_4;
                                            decomp_var_10 = edi[0x6];
                                            esp = (esp - 0x4) + 0x8;
                                            if (sub_48a922(decomp_var_10) != 0x0) {
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_48a922(esi) != 0x0) {
                                                            eax = edi[0x6];
                                                            *esi = eax;
                                                            esp = esp - 0x4;
                                                            decomp_var_c = arg_10 + 0x8;
                                                            *esi = sub_48063b(eax, decomp_var_c);
                                                            eax = sub_47f361();
                                                    }
                                                    else {
                                                            sub_4810dd();
                                                            eax = sub_47f361();
                                                    }
                                            }
                                            else {
                                                    sub_4810dd();
                                                    eax = sub_47f361();
                                            }
                                    }
                                    else {
                                            edi = arg_10;
                                            esp = esp - 0x4;
                                            decomp_var_10 = arg_4[0x6];
                                            if (!bool_22) {
                                                    esp = esp + 0x8;
                                                    if (sub_48a922(decomp_var_10) != 0x0) {
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_48a922(esi) != 0x0) {
                                                                    decomp_var_c = edi[0x5];
                                                                    decomp_var_10 = arg_4[0x6];
                                                                    sub_47f9a0(esi, decomp_var_10, decomp_var_c);
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (edi[0x5] == 0x4) {
                                                                            eax = *esi;
                                                                            if (eax != 0x0) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_c = edi + 0x8;
                                                                                    *esi = sub_48063b(eax, decomp_var_c);
                                                                                    eax = sub_47f361();
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
                                                                    sub_4810dd();
                                                                    eax = sub_47f361();
                                                            }
                                                    }
                                                    else {
                                                            sub_4810dd();
                                                            eax = sub_47f361();
                                                    }
                                            }
                                            else {
                                                    if (edi[0x6] == edx) {
                                                            esp = esp + 0x8;
                                                            if (sub_48a922(decomp_var_10) != 0x0) {
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (sub_48a922(esi) != 0x0) {
                                                                            sub_47f9a0(esi, sub_48063b(arg_4[0x6], edi + 0x8), decomp_var_c);
                                                                            eax = sub_47f361();
                                                                    }
                                                                    else {
                                                                            sub_4810dd();
                                                                            eax = sub_47f361();
                                                                    }
                                                            }
                                                            else {
                                                                    sub_4810dd();
                                                                    eax = sub_47f361();
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x8;
                                                            if (sub_48a922(decomp_var_10) != 0x0) {
                                                                    decomp_var_c = 0x1;
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (sub_48a922(esi) != 0x0) {
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (sub_48a922(edi[0x6]) != 0x0) {
                                                                                    decomp_var_1c = ((*(int8_t *)edi & 0x4) != 0x0 ? 0x1 : 0x0) + 0x1;
                                                                            }
                                                                            else {
                                                                                    sub_4810dd();
                                                                            }
                                                                            eax = sub_47f361();
                                                                    }
                                                                    else {
                                                                            sub_4810dd();
                                                                            eax = sub_47f361();
                                                                    }
                                                            }
                                                            else {
                                                                    sub_4810dd();
                                                                    eax = sub_47f361();
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    eax = sub_47f361();
                            }
                    }
                    else {
                            eax = *eax;
                            esi = arg_8;
                            if (eax >= 0x0) {
                                    esi = ecx + esi + 0xc;
                            }
                            edx = 0x0;
                            esp = esp - 0x4;
                            decomp_var_c = 0x1;
                            bool_14 = (eax & 0x8) == 0x0;
                            if ((eax & 0x8) != 0x0) {
                                    edi = arg_4;
                                    decomp_var_10 = edi[0x6];
                                    esp = (esp - 0x4) + 0x8;
                                    if (sub_48a922(decomp_var_10) != 0x0) {
                                            esp = (esp - 0x8) + 0x8;
                                            if (sub_48a922(esi) != 0x0) {
                                                    eax = edi[0x6];
                                                    *esi = eax;
                                                    esp = esp - 0x4;
                                                    decomp_var_c = arg_10 + 0x8;
                                                    *esi = sub_48063b(eax, decomp_var_c);
                                                    eax = sub_47f361();
                                            }
                                            else {
                                                    sub_4810dd();
                                                    eax = sub_47f361();
                                            }
                                    }
                                    else {
                                            sub_4810dd();
                                            eax = sub_47f361();
                                    }
                            }
                            else {
                                    edi = arg_10;
                                    esp = esp - 0x4;
                                    decomp_var_10 = arg_4[0x6];
                                    if (!bool_14) {
                                            esp = esp + 0x8;
                                            if (sub_48a922(decomp_var_10) != 0x0) {
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_48a922(esi) != 0x0) {
                                                            decomp_var_c = edi[0x5];
                                                            decomp_var_10 = arg_4[0x6];
                                                            sub_47f9a0(esi, decomp_var_10, decomp_var_c);
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (edi[0x5] == 0x4) {
                                                                    eax = *esi;
                                                                    if (eax != 0x0) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_c = edi + 0x8;
                                                                            *esi = sub_48063b(eax, decomp_var_c);
                                                                            eax = sub_47f361();
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
                                                            sub_4810dd();
                                                            eax = sub_47f361();
                                                    }
                                            }
                                            else {
                                                    sub_4810dd();
                                                    eax = sub_47f361();
                                            }
                                    }
                                    else {
                                            if (edi[0x6] == edx) {
                                                    esp = esp + 0x8;
                                                    if (sub_48a922(decomp_var_10) != 0x0) {
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_48a922(esi) != 0x0) {
                                                                    sub_47f9a0(esi, sub_48063b(arg_4[0x6], edi + 0x8), decomp_var_c);
                                                                    eax = sub_47f361();
                                                            }
                                                            else {
                                                                    sub_4810dd();
                                                                    eax = sub_47f361();
                                                            }
                                                    }
                                                    else {
                                                            sub_4810dd();
                                                            eax = sub_47f361();
                                                    }
                                            }
                                            else {
                                                    esp = esp + 0x8;
                                                    if (sub_48a922(decomp_var_10) != 0x0) {
                                                            decomp_var_c = 0x1;
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_48a922(esi) != 0x0) {
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    if (sub_48a922(edi[0x6]) != 0x0) {
                                                                            decomp_var_1c = ((*(int8_t *)edi & 0x4) != 0x0 ? 0x1 : 0x0) + 0x1;
                                                                    }
                                                                    else {
                                                                            sub_4810dd();
                                                                    }
                                                                    eax = sub_47f361();
                                                            }
                                                            else {
                                                                    sub_4810dd();
                                                                    eax = sub_47f361();
                                                            }
                                                    }
                                                    else {
                                                            sub_4810dd();
                                                            eax = sub_47f361();
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    eax = sub_47f361();
            }
    }
    else {
            eax = sub_47f361();
    }
    return eax;
}
