// sub_4187d0 @ 0x4187d0
// hopper name: sub_4187d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4187d0() {
    var_C = *0x0;
    var_58 = ebx;
    esp = esp - 0x68;
    *0x0 = &var_C;
    ebp = ecx;
    eax = arg_8;
    if (eax[0x29] != 0x0) {
            var_38 = 0xf;
            sub_402650("invalid map/set<T> iterator", 0x1b);
            sub_402a30(&var_58);
            esp = esp - 0x14;
            var_3C = 0x4af488;
            eax = sub_47a958(&var_3C, 0x4bb89c);
    }
    ebx = eax;
    sub_40e210();
    eax = *ebx;
    if (eax[0x29] != 0x0) {
            edi = ebx[0x2];
            bool_33 = edi[0x29] != 0x0;
            esi = ebx[0x1];
            if (!bool_33) {
                    edi[0x1] = esi;
            }
            eax = arg_0;
            if (eax[0x1] == ebx) {
                    eax[0x1] = edi;
                    ebx = arg_0;
                    if (*ebx == var_44) {
                            if (edi[0x29] != 0x0) {
                                    eax = esi;
                                    *ebx = eax;
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
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
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
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
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
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
                    if (*esi == ebx) {
                            *esi = edi;
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
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
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
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
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
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
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
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
            edx = ebx[0x2];
            if (edx[0x29] != 0x0) {
                    edi = eax;
                    bool_20 = edi[0x29] != 0x0;
                    esi = ebx[0x1];
                    if (!bool_20) {
                            edi[0x1] = esi;
                    }
                    eax = arg_0;
                    if (eax[0x1] == ebx) {
                            eax[0x1] = edi;
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                            *ebx = eax;
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
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
                                            ebx = arg_0;
                                            if (ebx[0x2] == var_38) {
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
                                    ebx = arg_0;
                                    if (ebx[0x2] == var_38) {
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
                            if (*esi == ebx) {
                                    *esi = edi;
                            }
                            else {
                                    esi[0x2] = edi;
                            }
                            ebx = arg_0;
                            if (*ebx == var_44) {
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
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
                    if (ecx == ebx) {
                            bool_1 = edi[0x29] != 0x0;
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
                                    if (edi[0x29] != 0x0) {
                                            eax = esi;
                                    }
                                    else {
                                            eax = sub_40e0b0(edi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *ebx = eax;
                            }
                            ebx = arg_0;
                            if (ebx[0x2] == var_38) {
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
                            *ecx = *ebx;
                            if (ecx == ebx[0x2]) {
                                    esi = ecx;
                            }
                            else {
                                    bool_18 = edi[0x29] != 0x0;
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
                            edx = ebx[0x28];
                            eax = ecx[0x28];
                            ecx[0x28] = edx;
                            ebx[0x28] = eax;
                    }
            }
    }
    eax = var_2C;
    if (eax[0x28] == 0x1) {
            if (edi != arg_0[0x1]) {
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
                                    }
                                    if (eax[0x29] == 0x0) {
                                            edx = *eax;
                                            if (edx[0x28] == 0x1) {
                                                    if (*(int8_t *)(eax[0x2] + 0x28) != 0x1) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            eax[0x28] = 0x0;
                                                            edx = arg_0;
                                                            edi = esi;
                                                            bool_69 = edi != edx[0x1];
                                                            esi = esi[0x1];
                                                            if (bool_69) {
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
                                            bool_64 = edi != edx[0x1];
                                            esi = esi[0x1];
                                            if (bool_64) {
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
                                    }
                                    if (eax[0x29] == 0x0) {
                                            edx = eax[0x2];
                                            if (edx[0x28] == 0x1) {
                                                    if (*(int8_t *)(*eax + 0x28) == 0x1) {
                                                            eax[0x28] = 0x0;
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
                                            bool_68 = edi != edx[0x1];
                                            esi = esi[0x1];
                                            if (bool_68) {
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
                                            edx[0x28] = 0x1;
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
                                            edx[0x28] = 0x1;
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
    sub_47c8f9();
    eax = arg_4;
    esp = (esp - 0x4) + 0x4;
    eax = arg_34;
    *eax = arg_38;
    eax[0x1] = arg_3c;
    *0x0 = arg_24;
    return eax;
}
