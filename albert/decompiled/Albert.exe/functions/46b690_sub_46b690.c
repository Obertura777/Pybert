// sub_46b690 @ 0x46b690
// hopper name: sub_46b690
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46b690() {
    var_C = *0x0;
    esp = esp - 0x68;
    *0x0 = &var_C;
    ebx = ecx;
    eax = arg_8;
    if (eax[0x2d] != 0x0) {
            sub_402650("invalid map/set<T> iterator", 0x1b);
            sub_402a30(&var_50);
            esp = esp - 0x14;
            var_34 = 0x4af488;
            eax = sub_47a958(&var_34, 0x4bb89c);
    }
    ebp = eax;
    sub_40f5f0();
    eax = *ebp;
    if (eax[0x2d] != 0x0) {
            edi = arg_4;
            esi = arg_0;
            if (edi[0x2d] == 0x0) {
                    edi[0x1] = esi;
            }
            eax = ebx[0x1];
            if (eax[0x1] == ebp) {
                    eax[0x1] = edi;
                    ebx = ebx[0x1];
                    if (*ebx == ebp) {
                            if (edi[0x2d] != 0x0) {
                                    eax = esi;
                                    *ebx = eax;
                                    ebx = var_30[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x2d] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_45b7b0(edi);
                                            }
                                    }
                            }
                            else {
                                    eax = sub_45b7d0(edi);
                                    esp = (esp - 0x4) + 0x4;
                                    *ebx = eax;
                                    ebx = var_30[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x2d] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_45b7b0(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            ebx = var_30[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_45b7b0(edi);
                                    }
                            }
                    }
            }
            else {
                    if (*esi == ebp) {
                            *esi = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = var_30[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x2d] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_45b7b0(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_45b7d0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = var_30[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x2d] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_45b7b0(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = var_30[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x2d] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_45b7b0(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            esi[0x2] = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_45b7d0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_30[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_45b7b0(edi);
                                    }
                            }
                    }
            }
    }
    else {
            if (arg_4[0x2d] != 0x0) {
                    edi = eax;
                    esi = arg_0;
                    if (edi[0x2d] == 0x0) {
                            edi[0x1] = esi;
                    }
                    eax = ebx[0x1];
                    if (eax[0x1] == ebp) {
                            eax[0x1] = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = var_30[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x2d] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_45b7b0(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_45b7d0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = var_30[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x2d] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_45b7b0(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = var_30[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x2d] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_45b7b0(edi);
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
                                    if (edi[0x2d] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_45b7d0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_30[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_45b7b0(edi);
                                    }
                            }
                    }
            }
            else {
                    ecx = arg_8;
                    edi = ecx[0x2];
                    if (ecx == ebp) {
                            esi = arg_0;
                            if (edi[0x2d] == 0x0) {
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
                                    if (edi[0x2d] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_45b7d0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_30[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x2d] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_45b7b0(edi);
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
                                    bool_19 = edi[0x2d] != 0x0;
                                    esi = ecx[0x1];
                                    if (!bool_19) {
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
                            eax = ecx[0x2c];
                            ecx[0x2c] = arg_28;
                            arg_28 = eax;
                    }
            }
    }
    if (arg_28 == 0x1) {
            ecx = var_24;
            eax = ecx[0x1];
            if (edi != eax[0x1]) {
                    while (true) {
                            if (edi[0x2c] != 0x1) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            eax = *esi;
                            if (edi == eax) {
                                    eax = esi[0x2];
                                    if (eax[0x2c] == 0x0) {
                                            eax[0x2c] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x2c] = 0x0;
                                            sub_45ba00(esi);
                                            eax = esi[0x2];
                                            ecx = var_24;
                                    }
                                    if (eax[0x2d] == 0x0) {
                                            if (*(int8_t *)(*eax + 0x2c) == 0x1) {
                                                    if (*(int8_t *)(eax[0x2] + 0x2c) != 0x1) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            eax[0x2c] = 0x0;
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
                                            }
                                            else {
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = ecx[0x1];
                                            edi = esi;
                                            bool_61 = edi != eax[0x1];
                                            esi = esi[0x1];
                                            if (bool_61) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    if (eax[0x2c] == 0x0) {
                                            eax[0x2c] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x2c] = 0x0;
                                            sub_40e170(esi);
                                            eax = *esi;
                                            ecx = var_24;
                                    }
                                    if (eax[0x2d] == 0x0) {
                                            if (*(int8_t *)(eax[0x2] + 0x2c) == 0x1) {
                                                    if (*(int8_t *)(*eax + 0x2c) == 0x1) {
                                                            eax[0x2c] = 0x0;
                                                            eax = ecx[0x1];
                                                            edi = esi;
                                                            bool_63 = edi != eax[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_63) {
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
                                            bool_70 = edi != eax[0x1];
                                            esi = esi[0x1];
                                            if (bool_70) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
                    if (temp_0 != 0x0 && temp_0 != 0x1) {
                            if (temp_0 != 0x2) {
                                    if (*(int8_t *)(*eax + 0x2c) == 0x1) {
                                            *(int8_t *)(eax[0x2] + 0x2c) = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x2c] = 0x0;
                                            sub_45ba00(eax);
                                            eax = *esi;
                                    }
                                    eax[0x2c] = esi[0x2c];
                                    esi[0x2c] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(*eax + 0x2c) = 0x1;
                                    sub_40e170(esi);
                            }
                            else {
                                    if (*(int8_t *)(eax[0x2] + 0x2c) == 0x1) {
                                            *(int8_t *)(*eax + 0x2c) = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x2c] = 0x0;
                                            sub_40e170(eax);
                                            eax = esi[0x2];
                                    }
                                    eax[0x2c] = esi[0x2c];
                                    esi[0x2c] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(eax[0x2] + 0x2c) = 0x1;
                                    sub_45ba00(esi);
                            }
                    }
            }
            edi[0x2c] = 0x1;
    }
    if (arg_20 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    sub_47c8f9();
    ecx = var_18;
    eax = ecx[0x2];
    esp = (esp - 0x4) + 0x4;
    if (eax > 0x0) {
            ecx[0x2] = eax - 0x1;
    }
    eax = arg_3c;
    *eax = arg_40;
    eax[0x1] = arg_44;
    *0x0 = arg_2c;
    return eax;
}
