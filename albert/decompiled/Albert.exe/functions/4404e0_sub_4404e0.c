// sub_4404e0 @ 0x4404e0
// hopper name: sub_4404e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4404e0() {
    var_C = *0x0;
    var_58 = ebx;
    esp = esp - 0x68;
    *0x0 = &var_C;
    ebp = ecx;
    eax = arg_8;
    if (eax[0x629] != 0x0) {
            var_38 = 0xf;
            sub_402650("invalid map/set<T> iterator", 0x1b);
            sub_402a30(&var_58);
            esp = esp - 0x14;
            var_3C = 0x4af488;
            eax = sub_47a958(&var_3C, 0x4bb89c);
    }
    ebx = eax;
    sub_40f260();
    eax = *ebx;
    if (eax[0x629] != 0x0) {
            edi = ebx[0x2];
            bool_33 = edi[0x629] != 0x0;
            esi = ebx[0x1];
            if (!bool_33) {
                    edi[0x1] = esi;
            }
            eax = arg_0;
            if (eax[0x1] == ebx) {
                    eax[0x1] = edi;
                    ebx = arg_0;
                    if (*ebx == var_44) {
                            if (edi[0x629] != 0x0) {
                                    eax = esi;
                                    *ebx = eax;
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
                                            if (edi[0x629] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e400(edi);
                                            }
                                    }
                            }
                            else {
                                    eax = sub_40e420(edi);
                                    esp = (esp - 0x4) + 0x4;
                                    *ebx = eax;
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
                                            if (edi[0x629] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e400(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
                                    if (edi[0x629] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e400(edi);
                                    }
                            }
                    }
            }
            else {
                    if (*esi == ebx) {
                            *esi = edi;
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x629] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
                                                    if (edi[0x629] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e400(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_40e420(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
                                                    if (edi[0x629] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e400(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
                                            if (edi[0x629] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e400(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            esi[0x2] = edi;
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x629] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e420(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
                                    if (edi[0x629] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e400(edi);
                                    }
                            }
                    }
            }
    }
    else {
            edx = ebx[0x2];
            if (edx[0x629] != 0x0) {
                    edi = eax;
                    bool_20 = edi[0x629] != 0x0;
                    esi = ebx[0x1];
                    if (!bool_20) {
                            edi[0x1] = esi;
                    }
                    eax = arg_0;
                    if (eax[0x1] == ebx) {
                            eax[0x1] = edi;
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x629] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
                                                    if (edi[0x629] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e400(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_40e420(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
                                                    if (edi[0x629] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_40e400(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
                                            if (edi[0x629] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_40e400(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            if (*esi == ebx) {
                                    *esi = edi;
                            }
                            else {
                                    esi[0x2] = edi;
                            }
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x629] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e420(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
                                    if (edi[0x629] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e400(edi);
                                    }
                            }
                    }
            }
            else {
                    ecx = arg_0;
                    edi = ecx[0x2];
                    if (ecx == ebx) {
                            bool_1 = edi[0x629] != 0x0;
                            esi = ebx[0x1];
                            if (!bool_1) {
                                    edi[0x1] = esi;
                            }
                            eax = arg_0;
                            if (eax[0x1] == ebx) {
                                    eax[0x1] = edi;
                            }
                            else {
                                    if (*esi == ebx) {
                                            *esi = edi;
                                    }
                                    else {
                                            esi[0x2] = edi;
                                    }
                            }
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x629] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e420(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
                                    if (edi[0x629] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_40e400(edi);
                                    }
                            }
                    }
                    else {
                            eax[0x1] = ecx;
                            *ecx = *ebx;
                            if (ecx == ebx[0x2]) {
                                    esi = ecx;
                            }
                            else {
                                    bool_18 = edi[0x629] != 0x0;
                                    esi = ecx[0x1];
                                    if (!bool_18) {
                                            edi[0x1] = esi;
                                    }
                                    *esi = edi;
                                    ecx[0x2] = ebx[0x2];
                                    *(ebx[0x2] + 0x4) = ecx;
                            }
                            eax = arg_0;
                            if (eax[0x1] == ebx) {
                                    eax[0x1] = ecx;
                            }
                            else {
                                    eax = ebx[0x1];
                                    if (*eax == ebx) {
                                            *eax = ecx;
                                    }
                                    else {
                                            eax[0x2] = ecx;
                                    }
                            }
                            ecx[0x1] = ebx[0x1];
                            edx = ebx[0x628];
                            eax = ecx[0x628];
                            ecx[0x628] = edx;
                            ebx[0x628] = eax;
                    }
            }
    }
    eax = var_2C;
    if (eax[0x628] == 0x1) {
            if (edi != arg_0[0x1]) {
                    while (true) {
                            if (edi[0x628] != 0x1) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            eax = *esi;
                            if (edi == eax) {
                                    eax = esi[0x2];
                                    if (eax[0x628] == 0x0) {
                                            eax[0x628] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x628] = 0x0;
                                            sub_40ec20(esi);
                                            eax = esi[0x2];
                                    }
                                    if (eax[0x629] == 0x0) {
                                            ebx = 0x1;
                                            edx = *eax;
                                            if (edx[0x628] == 0x1) {
                                                    if (*(int8_t *)(eax[0x2] + 0x628) != ebx) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            eax[0x628] = 0x0;
                                                            edx = arg_0;
                                                            edi = esi;
                                                            bool_67 = edi != edx[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_67) {
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
                                            edx = arg_0;
                                            edi = esi;
                                            bool_71 = edi != edx[0x1];
                                            esi = esi[0x1];
                                            if (bool_71) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    if (eax[0x628] == 0x0) {
                                            eax[0x628] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x628] = 0x0;
                                            sub_40ec80(esi);
                                            eax = *esi;
                                    }
                                    if (eax[0x629] == 0x0) {
                                            edx = eax[0x2];
                                            if (edx[0x628] == 0x1) {
                                                    if (*(int8_t *)(*eax + 0x628) == 0x1) {
                                                            eax[0x628] = 0x0;
                                                            edx = arg_0;
                                                            edi = esi;
                                                            bool_61 = edi != edx[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_61) {
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
                                            edx = arg_0;
                                            edi = esi;
                                            bool_65 = edi != edx[0x1];
                                            esi = esi[0x1];
                                            if (bool_65) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
                    if (temp_0 != 0x0 && temp_0 != 0x1) {
                            if (temp_0 != 0x2) {
                                    if (*(int8_t *)(*eax + 0x628) == 0x1) {
                                            edx[0x628] = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x628] = 0x0;
                                            sub_40ec20(eax);
                                            eax = *esi;
                                    }
                                    eax[0x628] = esi[0x628];
                                    esi[0x628] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(*eax + 0x628) = 0x1;
                                    sub_40ec80(esi);
                            }
                            else {
                                    if (*(int8_t *)(eax[0x2] + 0x628) == 0x1) {
                                            edx[0x628] = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x628] = 0x0;
                                            sub_40ec80(eax);
                                            eax = esi[0x2];
                                    }
                                    eax[0x628] = esi[0x628];
                                    esi[0x628] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(eax[0x2] + 0x628) = 0x1;
                                    sub_40ec20(esi);
                            }
                    }
            }
            edi[0x628] = 0x1;
    }
    sub_42ee00();
    sub_47c8f9();
    eax = arg_4;
    esp = (esp - 0x4) + 0x4;
    eax = arg_40;
    *eax = arg_44;
    eax[0x1] = arg_48;
    *0x0 = arg_30;
    return eax;
}
