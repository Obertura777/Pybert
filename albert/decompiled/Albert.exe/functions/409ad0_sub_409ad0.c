// sub_409ad0 @ 0x409ad0
// hopper name: sub_409ad0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_409ad0() {
    var_8 = 0x494548;
    var_C = *0x0;
    decomp_var_6c = ebx;
    decomp_var_70 = ebp;
    decomp_var_74 = esi;
    decomp_var_78 = edi;
    esp = esp - 0x7c;
    var_7C = *dword_4c8db8 ^ &decomp_var_78;
    *0x0 = &var_C;
    ebx = ecx;
    eax = sub_40ff50();
    var_38 = eax;
    eax[0x15] = 0x1;
    var_38[0x1] = var_38;
    *var_38 = var_38;
    var_38[0x2] = var_38;
    ecx = ebx + 0x2450;
    edi = ecx;
    esi = *ecx[0x1];
    var_68 = ecx;
    var_64 = edi;
    var_60 = esi;
    goto loc_409b43;

loc_409b43:
    ebp = ecx[0x1];
    if (edi == 0x0 || edi != ecx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == arg_0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    ebp = sub_405ed0(esi + 0x10);
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    var_5C = ebp;
                    var_58 = esi[0x3];
                    eax = sub_405120(&var_24, &var_5C, var_7C);
            }
            sub_401390();
            esi = var_60;
            edi = var_64;
            ecx = var_68;
            continue;
    }
    break;
    ebx = arg_4;
    ebp = &var_3C;
    edi = var_38;
    var_30 = 0x0;
    goto loc_409bf0;

loc_409bf0:
    esi = *var_38;
    if (ebp == 0x0 || ebp != &var_3C) {
            sub_47a948();
    }
    if (edi != esi) {
            if (ebx[0x2] >= ebx[0x4]) {
                    sub_401400();
                    ebp = var_1C;
                    edi = var_18;
                    continue;
            }
            var_64 = ebp;
            var_60 = edi;
            sub_401400();
            edi = var_64;
            if (edi == 0x0) {
                    sub_47a948();
            }
            esi = var_60;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_407720(esi + 0x10);
            edx = ebx[0x1];
            ecx = edx[0x1];
            if (ecx[0x19] != 0x0) {
                    edi = ebx[0x1];
                    var_4C = ebx;
                    if (edx != edi) {
                            ecx = *eax;
                            esi = edx[0x3];
                            bool_15 = ecx != esi;
                            if (ecx >= esi) {
                                    if (!bool_15 && eax[0x2] < edx[0x8]) {
                                            var_44 = ebx;
                                            eax = &var_44;
                                    }
                                    else {
                                            eax = &var_4C;
                                    }
                            }
                            else {
                                    var_44 = ebx;
                                    eax = &var_44;
                            }
                    }
                    else {
                            var_44 = ebx;
                            eax = &var_44;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != ebx) {
                            sub_47a948();
                    }
                    if (esi == var_30) {
                            var_48 = var_18;
                            sub_401400();
                            edi = ebp;
                            if (edi == 0x0) {
                                    sub_47a948();
                            }
                            esi = var_48;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            var_14 = *sub_407720(esi + 0x10);
                            decomp_var_70 = &var_14;
                            var_C = *(int16_t *)word_4c605c;
                            esp = esp - 0xc;
                            decomp_var_74 = &var_8;
                            sub_404ef0(decomp_var_74, decomp_var_70);
                    }
                    sub_401400();
                    ebp = var_1C;
                    edi = var_18;
                    continue;
            }
            edi = *eax;
            &var_7C = &var_7C;
            do {
                    esi = ecx[0x3];
                    bool_24 = esi != edi;
                    if (esi < edi) {
                            ecx = ecx[0x2];
                            if (ecx[0x19] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_24) {
                            edx = ecx;
                            ecx = *ecx;
                            if (ecx[0x19] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (ecx[0x8] < eax[0x2]) {
                            ecx = ecx[0x2];
                    }
                    else {
                            edx = ecx;
                            ecx = *ecx;
                    }
            } while (ecx[0x19] == 0x0);
            edi = ebx[0x1];
            var_4C = ebx;
            if (edx != edi) {
                    ecx = *eax;
                    esi = edx[0x3];
                    bool_15 = ecx != esi;
                    if (ecx >= esi) {
                            if (!bool_15 && eax[0x2] < edx[0x8]) {
                                    var_44 = ebx;
                                    eax = &var_44;
                            }
                            else {
                                    eax = &var_4C;
                            }
                    }
                    else {
                            var_44 = ebx;
                            eax = &var_44;
                    }
            }
            else {
                    var_44 = ebx;
                    eax = &var_44;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != ebx) {
                    sub_47a948();
            }
            if (esi == var_30) {
                    var_48 = var_18;
                    sub_401400();
                    edi = ebp;
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    esi = var_48;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    var_14 = *sub_407720(esi + 0x10);
                    decomp_var_70 = &var_14;
                    var_C = *(int16_t *)word_4c605c;
                    esp = esp - 0xc;
                    decomp_var_74 = &var_8;
                    sub_404ef0(decomp_var_74, decomp_var_70);
            }
            sub_401400();
            ebp = var_1C;
            edi = var_18;
            continue;
    }
    break;
    sub_403b00(&var_44, &var_3C, *var_38, &var_3C, var_38);
    eax = sub_47c8f9();
    *0x0 = var_C;
    return eax;
}
