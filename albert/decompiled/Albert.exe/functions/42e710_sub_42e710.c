// sub_42e710 @ 0x42e710
// hopper name: sub_42e710
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42e710() {
    var_C = *0x0;
    esp = esp - 0x6c;
    *0x0 = &var_C;
    ebx = ecx;
    var_58 = ebx;
    eax = arg_8;
    if (eax[0x61] != 0x0) {
            var_38 = 0xf;
            sub_402650("invalid map/set<T> iterator", 0x1b);
            sub_402a30(&var_58);
            esp = esp - 0x14;
            var_3C = 0x4af488;
            eax = sub_47a958(&var_3C, 0x4bb89c);
    }
    ebp = eax;
    sub_40f860();
    eax = *ebp;
    if (eax[0x61] != 0x0) {
            edi = arg_4;
            esi = arg_0;
            if (edi[0x61] == 0x0) {
                    edi[0x1] = esi;
            }
            eax = ebx[0x1];
            if (eax[0x1] == ebp) {
                    eax[0x1] = edi;
                    ebx = ebx[0x1];
                    if (*ebx == ebp) {
                            if (edi[0x61] != 0x0) {
                                    eax = esi;
                                    *ebx = eax;
                                    ebx = var_3C[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x61] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e4a0(edi);
                                            }
                                    }
                            }
                            else {
                                    eax = sub_40e4c0(edi);
                                    esp = (esp - 0x4) + 0x4;
                                    *ebx = eax;
                                    ebx = var_3C[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x61] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e4a0(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            ebx = var_3C[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e4a0(edi);
                                    }
                            }
                    }
            }
            else {
                    if (*esi == ebp) {
                            *esi = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = var_3C[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x61] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e4a0(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_40e4c0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = var_3C[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x61] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e4a0(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = var_3C[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x61] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e4a0(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            esi[0x2] = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e4c0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_3C[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e4a0(edi);
                                    }
                            }
                    }
            }
    }
    else {
            if (arg_4[0x61] != 0x0) {
                    edi = eax;
                    esi = arg_0;
                    if (edi[0x61] == 0x0) {
                            edi[0x1] = esi;
                    }
                    eax = ebx[0x1];
                    if (eax[0x1] == ebp) {
                            eax[0x1] = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = var_3C[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x61] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e4a0(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_40e4c0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = var_3C[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x61] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e4a0(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = var_3C[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x61] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e4a0(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            if (*esi == ebp) {
                                    *esi = edi;
                            }
                            else {
                                    esi[0x2] = edi;
                            }
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e4c0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_3C[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e4a0(edi);
                                    }
                            }
                    }
            }
            else {
                    ecx = arg_0;
                    edi = ecx[0x2];
                    if (ecx == ebp) {
                            esi = arg_0;
                            if (edi[0x61] == 0x0) {
                                    edi[0x1] = esi;
                            }
                            eax = ebx[0x1];
                            if (eax[0x1] == ebp) {
                                    eax[0x1] = edi;
                            }
                            else {
                                    if (*esi == ebp) {
                                            *esi = edi;
                                    }
                                    else {
                                            esi[0x2] = edi;
                                    }
                            }
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e4c0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_3C[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x61] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e4a0(edi);
                                    }
                            }
                    }
                    else {
                            eax[0x1] = ecx;
                            *ecx = *ebp;
                            if (ecx == arg_4) {
                                    esi = ecx;
                            }
                            else {
                                    bool_18 = edi[0x61] != 0x0;
                                    esi = ecx[0x1];
                                    if (!bool_18) {
                                            edi[0x1] = esi;
                                    }
                                    *esi = edi;
                                    ecx[0x2] = arg_4;
                                    arg_4[0x1] = ecx;
                            }
                            eax = ebx[0x1];
                            if (eax[0x1] == ebp) {
                                    eax[0x1] = ecx;
                            }
                            else {
                                    eax = arg_0;
                                    if (*eax == ebp) {
                                            *eax = ecx;
                                    }
                                    else {
                                            eax[0x2] = ecx;
                                    }
                            }
                            ecx[0x1] = arg_0;
                            eax = ecx[0x60];
                            ecx[0x60] = arg_5c;
                            arg_5c = eax;
                    }
            }
    }
    if (arg_5c == 0x1) {
            ecx = var_30;
            eax = ecx[0x1];
            if (edi != eax[0x1]) {
                    while (true) {
                            if (edi[0x60] != 0x1) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            eax = *esi;
                            if (edi == eax) {
                                    eax = esi[0x2];
                                    if (eax[0x60] == 0x0) {
                                            eax[0x60] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x60] = 0x0;
                                            sub_40efb0(esi);
                                            eax = esi[0x2];
                                            ecx = var_30;
                                    }
                                    if (eax[0x61] == 0x0) {
                                            if (*(int8_t *)(*eax + 0x60) == 0x1) {
                                                    if (*(int8_t *)(eax[0x2] + 0x60) != 0x1) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            eax[0x60] = 0x0;
                                                            eax = ecx[0x1];
                                                            edi = esi;
                                                            bool_62 = edi != eax[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_62) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = ecx[0x1];
                                            edi = esi;
                                            bool_58 = edi != eax[0x1];
                                            esi = esi[0x1];
                                            if (bool_58) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    if (eax[0x60] == 0x0) {
                                            eax[0x60] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x60] = 0x0;
                                            sub_40f000(esi);
                                            eax = *esi;
                                            ecx = var_30;
                                    }
                                    if (eax[0x61] == 0x0) {
                                            if (*(int8_t *)(eax[0x2] + 0x60) == 0x1) {
                                                    if (*(int8_t *)(*eax + 0x60) == 0x1) {
                                                            eax[0x60] = 0x0;
                                                            eax = ecx[0x1];
                                                            edi = esi;
                                                            bool_68 = edi != eax[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_68) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            temp_0 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x3;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = ecx[0x1];
                                            edi = esi;
                                            bool_67 = edi != eax[0x1];
                                            esi = esi[0x1];
                                            if (bool_67) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
                    if (temp_0 != 0x0 && temp_0 != 0x1) {
                            if (temp_0 != 0x2) {
                                    if (*(int8_t *)(*eax + 0x60) == 0x1) {
                                            *(int8_t *)(eax[0x2] + 0x60) = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x60] = 0x0;
                                            sub_40efb0(eax);
                                            eax = *esi;
                                    }
                                    eax[0x60] = esi[0x60];
                                    esi[0x60] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(*eax + 0x60) = 0x1;
                                    sub_40f000(esi);
                            }
                            else {
                                    if (*(int8_t *)(eax[0x2] + 0x60) == 0x1) {
                                            *(int8_t *)(*eax + 0x60) = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x60] = 0x0;
                                            sub_40f000(eax);
                                            eax = esi[0x2];
                                    }
                                    eax[0x60] = esi[0x60];
                                    esi[0x60] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(eax[0x2] + 0x60) = 0x1;
                                    sub_40efb0(esi);
                            }
                    }
            }
            edi[0x60] = 0x1;
    }
    sub_421400();
    sub_465fa0();
    sub_47c8f9();
    ecx = var_24;
    eax = ecx[0x2];
    esp = (esp - 0x4) + 0x4;
    if (eax > 0x0) {
            ecx[0x2] = eax - 0x1;
    }
    eax = arg_34;
    *eax = arg_38;
    eax[0x1] = arg_3c;
    *0x0 = arg_24;
    return eax;
}
