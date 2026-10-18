// sub_4622a0 @ 0x4622a0
// hopper name: sub_4622a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4622a0() {
    var_C = *0x0;
    esp = esp - 0x70;
    *0x0 = &var_C;
    ebx = ecx;
    eax = arg_8;
    if (eax[0x29] != 0x0) {
            var_38 = 0xf;
            sub_402650("invalid map/set<T> iterator", 0x1b);
            sub_402a30(&var_58);
            esp = esp - 0x14;
            var_3C = 0x4af488;
            eax = sub_47a958(&var_3C, 0x4bb89c);
    }
    ebp = eax;
    sub_40e210();
    eax = *ebp;
    if (eax[0x29] != 0x0) {
            edi = arg_4;
            esi = arg_0;
            if (edi[0x29] == 0x0) {
                    edi[0x1] = esi;
            }
            eax = ebx[0x1];
            if (eax[0x1] == ebp) {
                    eax[0x1] = edi;
                    ebx = ebx[0x1];
                    if (*ebx == ebp) {
                            if (edi[0x29] != 0x0) {
                                    eax = esi;
                                    *ebx = eax;
                                    ebx = var_40[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x29] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_401600(edi);
                                            }
                                    }
                            }
                            else {
                                    eax = sub_40e0b0(edi);
                                    esp = (esp - 0x4) + 0x4;
                                    *ebx = eax;
                                    ebx = var_40[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x29] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_401600(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            ebx = var_40[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_401600(edi);
                                    }
                            }
                    }
            }
            else {
                    if (*esi == ebp) {
                            *esi = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = var_40[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x29] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_401600(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = var_40[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x29] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_401600(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = var_40[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x29] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_401600(edi);
                                            }
                                    }
                            }
                    }
                    else {
                            esi[0x2] = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_40[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_401600(edi);
                                    }
                            }
                    }
            }
    }
    else {
            if (arg_4[0x29] != 0x0) {
                    edi = eax;
                    esi = arg_0;
                    if (edi[0x29] == 0x0) {
                            edi[0x1] = esi;
                    }
                    eax = ebx[0x1];
                    if (eax[0x1] == ebp) {
                            eax[0x1] = edi;
                            ebx = ebx[0x1];
                            if (*ebx == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = var_40[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x29] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_401600(edi);
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx = eax;
                                            ebx = var_40[0x1];
                                            if (ebx[0x2] == ebp) {
                                                    if (edi[0x29] != 0x0) {
                                                            ebx[0x2] = esi;
                                                    }
                                                    else {
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx[0x2] = sub_401600(edi);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebx = var_40[0x1];
                                    if (ebx[0x2] == ebp) {
                                            if (edi[0x29] != 0x0) {
                                                    ebx[0x2] = esi;
                                            }
                                            else {
                                                    esp = (esp - 0x4) + 0x4;
                                                    ebx[0x2] = sub_401600(edi);
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
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_40[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_401600(edi);
                                    }
                            }
                    }
            }
            else {
                    ecx = arg_0;
                    edi = ecx[0x2];
                    if (ecx == ebp) {
                            esi = arg_0;
                            if (edi[0x29] == 0x0) {
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
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = var_40[0x1];
                            if (ebx[0x2] == ebp) {
                                    if (edi[0x29] != 0x0) {
                                            ebx[0x2] = esi;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            ebx[0x2] = sub_401600(edi);
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
                                    bool_18 = edi[0x29] != 0x0;
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
                            eax = ecx[0x28];
                            ecx[0x28] = arg_24;
                            arg_24 = eax;
                    }
            }
    }
    if (arg_24 == 0x1) {
            ecx = var_34;
            eax = ecx[0x1];
            if (edi != eax[0x1]) {
                    while (true) {
                            if (edi[0x28] != 0x1) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            eax = *esi;
                            if (edi == eax) {
                                    eax = esi[0x2];
                                    if (eax[0x28] == 0x0) {
                                            eax[0x28] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x28] = 0x0;
                                            sub_401740(esi);
                                            eax = esi[0x2];
                                            ecx = var_34;
                                    }
                                    if (eax[0x29] == 0x0) {
                                            if (*(int8_t *)(*eax + 0x28) == 0x1) {
                                                    if (*(int8_t *)(eax[0x2] + 0x28) != 0x1) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            eax[0x28] = 0x0;
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
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = ecx[0x1];
                                            edi = esi;
                                            bool_69 = edi != eax[0x1];
                                            esi = esi[0x1];
                                            if (bool_69) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    if (eax[0x28] == 0x0) {
                                            eax[0x28] = 0x1;
                                            esp = esp - 0x4;
                                            esi[0x28] = 0x0;
                                            sub_4012a0(esi);
                                            eax = *esi;
                                            ecx = var_34;
                                    }
                                    if (eax[0x29] == 0x0) {
                                            if (*(int8_t *)(eax[0x2] + 0x28) == 0x1) {
                                                    if (*(int8_t *)(*eax + 0x28) == 0x1) {
                                                            eax[0x28] = 0x0;
                                                            eax = ecx[0x1];
                                                            edi = esi;
                                                            bool_64 = edi != eax[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_64) {
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
                                            bool_59 = edi != eax[0x1];
                                            esi = esi[0x1];
                                            if (bool_59) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
                    if (temp_0 != 0x0 && temp_0 != 0x1) {
                            if (temp_0 != 0x2) {
                                    if (*(int8_t *)(*eax + 0x28) == 0x1) {
                                            *(int8_t *)(eax[0x2] + 0x28) = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x28] = 0x0;
                                            sub_401740(eax);
                                            eax = *esi;
                                    }
                                    eax[0x28] = esi[0x28];
                                    esi[0x28] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(*eax + 0x28) = 0x1;
                                    sub_4012a0(esi);
                            }
                            else {
                                    if (*(int8_t *)(eax[0x2] + 0x28) == 0x1) {
                                            *(int8_t *)(*eax + 0x28) = 0x1;
                                            esp = esp - 0x4;
                                            eax[0x28] = 0x0;
                                            sub_4012a0(eax);
                                            eax = esi[0x2];
                                    }
                                    eax[0x28] = esi[0x28];
                                    esi[0x28] = 0x1;
                                    esp = esp - 0x4;
                                    *(int8_t *)(eax[0x2] + 0x28) = 0x1;
                                    sub_401740(esi);
                            }
                    }
            }
            edi[0x28] = 0x1;
    }
    sub_4053f0(&var_24, &arg_c, *arg_10, &arg_c, arg_10);
    sub_47c8f9();
    *(&arg_c + 0x4) = 0x0;
    *(&arg_c + 0x8) = 0x0;
    sub_47c8f9();
    ecx = var_28;
    eax = ecx[0x2];
    esp = (esp - 0x1c) + 0x8;
    if (eax > 0x0) {
            ecx[0x2] = eax - 0x1;
    }
    eax = arg_34;
    *eax = arg_38;
    eax[0x1] = arg_3c;
    *0x0 = arg_24;
    return eax;
}
