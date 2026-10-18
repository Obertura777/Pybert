// sub_4136d0 @ 0x4136d0
// hopper name: sub_4136d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4136d0() {
    var_C = *0x0;
    var_58 = ebp;
    var_5C = esi;
    esp = esp - 0x64;
    *0x0 = &var_C;
    edi = ecx;
    if (edi[0x2] >= 0x15555554) {
            var_4C = 0x0;
            sub_402650("map/set<T> too long", 0x13);
            sub_402a30(&var_58);
            esp = esp - 0x14;
            var_3C = 0x4af47c;
            eax = sub_47a958(&var_3C, 0x4bb9a4);
    }
    eax = edi[0x1];
    esi = arg_0;
    esp = esp - 0x14;
    ebp = sub_4102e0(eax, esi, eax, arg_4, 0x0);
    eax = edi[0x1];
    edi[0x2] = edi[0x2] + 0x1;
    if (esi == eax) {
            eax[0x1] = ebp;
            *edi[0x1] = ebp;
            *(edi[0x1] + 0x8) = ebp;
    }
    else {
            if (saved_fp != 0x0) {
                    *esi = ebp;
                    eax = edi[0x1];
                    if (esi == *eax) {
                            *eax = ebp;
                    }
            }
            else {
                    esi[0x2] = ebp;
                    eax = edi[0x1];
                    if (esi == eax[0x2]) {
                            eax[0x2] = ebp;
                    }
            }
    }
    eax = &arg_0;
    esi = ebp;
    if (arg_0[0x18] == 0x0) {
            &var_5C = &var_5C;
            do {
                    ecx = *eax;
                    edx = ecx[0x1];
                    if (ecx == *edx) {
                            edx = edx[0x2];
                            if (edx[0x18] == 0x0) {
                                    ecx[0x18] = 0x1;
                                    edx[0x18] = 0x1;
                                    *(int8_t *)(*(*eax + 0x4) + 0x18) = 0x0;
                                    esi = *(*eax + 0x4);
                            }
                            else {
                                    if (esi == ecx[0x2]) {
                                            esi = ecx;
                                            esp = esp - 0x4;
                                            sub_40f8d0(esi);
                                    }
                                    *(int8_t *)(esi[0x1] + 0x18) = 0x1;
                                    *(int8_t *)(*(esi[0x1] + 0x4) + 0x18) = 0x0;
                                    esp = esp - 0x4;
                                    sub_40e0f0(*(esi[0x1] + 0x4));
                            }
                    }
                    else {
                            edx = *edx;
                            if (edx[0x18] == 0x0) {
                                    ecx[0x18] = 0x1;
                                    edx[0x18] = 0x1;
                                    *(int8_t *)(*(*eax + 0x4) + 0x18) = 0x0;
                                    esi = *(*eax + 0x4);
                            }
                            else {
                                    if (esi == *ecx) {
                                            esi = ecx;
                                            esp = esp - 0x4;
                                            sub_40e0f0(esi);
                                    }
                                    *(int8_t *)(esi[0x1] + 0x18) = 0x1;
                                    *(int8_t *)(*(esi[0x1] + 0x4) + 0x18) = 0x0;
                                    eax = esi[0x1];
                                    eax = eax[0x1];
                                    ecx = eax[0x2];
                                    eax[0x2] = *ecx;
                                    edx = *ecx;
                                    if (edx[0x19] == 0x0) {
                                            edx[0x1] = eax;
                                    }
                                    ecx[0x1] = eax[0x1];
                                    edx = edi[0x1];
                                    if (eax == edx[0x1]) {
                                            edx[0x1] = ecx;
                                    }
                                    else {
                                            edx = eax[0x1];
                                            if (eax == *edx) {
                                                    *edx = ecx;
                                            }
                                            else {
                                                    edx[0x2] = ecx;
                                            }
                                    }
                                    *ecx = eax;
                                    eax[0x1] = ecx;
                            }
                    }
                    eax = esi + 0x4;
            } while (*(int8_t *)(esi[0x1] + 0x18) == 0x0);
    }
    *(int8_t *)(*(edi[0x1] + 0x4) + 0x18) = 0x1;
    eax = arg_18;
    eax[0x1] = ebp;
    *eax = edi;
    *0x0 = arg_8;
    return eax;
}
