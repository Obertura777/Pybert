// sub_47c000 @ 0x47c000
// hopper name: sub_47c000
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c000() {
    esi = arg_4;
    ecx = arg_8;
    edi = arg_0;
    edx = ecx;
    eax = ecx + esi;
    if (edi > esi) {
            if (edi >= eax) {
                    if (ecx >= 0x100) {
                            if (*dword_bc8368 != 0x0) {
                                    bool_33 = (edi & 0xf) != (esi & 0xf);
                                    esi = esi;
                                    edi = edi;
                                    esp = (esp - 0x8) + 0x8;
                                    if (!bool_33) {
                                            eax = sub_48722a(arg_fffffffffffffffc, arg_0, arg_4);
                                    }
                                    else {
                                            if ((edi & 0x3) == 0x0) {
                                                    ecx = ecx >> 0x2;
                                                    edx = edx & 0x3;
                                                    bool_26 = true;
                                                    if (ecx >= 0x8) {
                                                            *edi = *esi;
                                                            eax = (*(edx * 0x4 + 0x47c174))();
                                                    }
                                                    else {
                                                            if (*(ecx * 0x4 + switch_table) != 0x0) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x1) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                                                            if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                                                    if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                                                            if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                                                    *(edi + (ecx * 0x4 - 0x1c)) = *(esi + (ecx * 0x4 - 0x1c));
                                                                                                            }
                                                                                                            *(edi + (ecx * 0x4 - 0x18)) = *(esi + (ecx * 0x4 - 0x18));
                                                                                                    }
                                                                                                    *(edi + (ecx * 0x4 - 0x14)) = *(esi + (ecx * 0x4 - 0x14));
                                                                                            }
                                                                                            *(edi + (ecx * 0x4 - 0x10)) = *(esi + (ecx * 0x4 - 0x10));
                                                                                    }
                                                                                    *(edi + (ecx * 0x4 - 0xc)) = *(esi + (ecx * 0x4 - 0xc));
                                                                            }
                                                                            *(edi + (ecx * 0x4 - 0x8)) = *(esi + (ecx * 0x4 - 0x8));
                                                                    }
                                                                    *(edi + (ecx * 0x4 - 0x4)) = *(esi + (ecx * 0x4 - 0x4));
                                                            }
                                                            eax = (*(edx * 0x4 + 0x47c174))();
                                                    }
                                            }
                                            else {
                                                    eax = edi;
                                                    ecx = ecx - 0x4;
                                                    if (ecx >= 0x0) {
                                                            eax = (*((eax & 0x3) * 0x4 + 0x47c088))();
                                                    }
                                                    else {
                                                            eax = (*(ecx * 0x4 + 0x47c184))();
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((edi & 0x3) == 0x0) {
                                            ecx = ecx >> 0x2;
                                            edx = edx & 0x3;
                                            bool_32 = true;
                                            if (ecx >= 0x8) {
                                                    *edi = *esi;
                                                    eax = (*(edx * 0x4 + 0x47c174))();
                                            }
                                            else {
                                                    if (*(ecx * 0x4 + switch_table) != 0x0) {
                                                            if (*(ecx * 0x4 + switch_table) != 0x1) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                                            if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                                                    if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                                            *(edi + (ecx * 0x4 - 0x1c)) = *(esi + (ecx * 0x4 - 0x1c));
                                                                                                    }
                                                                                                    *(edi + (ecx * 0x4 - 0x18)) = *(esi + (ecx * 0x4 - 0x18));
                                                                                            }
                                                                                            *(edi + (ecx * 0x4 - 0x14)) = *(esi + (ecx * 0x4 - 0x14));
                                                                                    }
                                                                                    *(edi + (ecx * 0x4 - 0x10)) = *(esi + (ecx * 0x4 - 0x10));
                                                                            }
                                                                            *(edi + (ecx * 0x4 - 0xc)) = *(esi + (ecx * 0x4 - 0xc));
                                                                    }
                                                                    *(edi + (ecx * 0x4 - 0x8)) = *(esi + (ecx * 0x4 - 0x8));
                                                            }
                                                            *(edi + (ecx * 0x4 - 0x4)) = *(esi + (ecx * 0x4 - 0x4));
                                                    }
                                                    eax = (*(edx * 0x4 + 0x47c174))();
                                            }
                                    }
                                    else {
                                            eax = edi;
                                            ecx = ecx - 0x4;
                                            if (ecx >= 0x0) {
                                                    eax = (*((eax & 0x3) * 0x4 + 0x47c088))();
                                            }
                                            else {
                                                    eax = (*(ecx * 0x4 + 0x47c184))();
                                            }
                                    }
                            }
                    }
                    else {
                            if ((edi & 0x3) == 0x0) {
                                    ecx = ecx >> 0x2;
                                    edx = edx & 0x3;
                                    bool_20 = true;
                                    if (ecx >= 0x8) {
                                            *edi = *esi;
                                            eax = (*(edx * 0x4 + 0x47c174))();
                                    }
                                    else {
                                            if (*(ecx * 0x4 + switch_table) != 0x0) {
                                                    if (*(ecx * 0x4 + switch_table) != 0x1) {
                                                            if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                                            if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                                    *(edi + (ecx * 0x4 - 0x1c)) = *(esi + (ecx * 0x4 - 0x1c));
                                                                                            }
                                                                                            *(edi + (ecx * 0x4 - 0x18)) = *(esi + (ecx * 0x4 - 0x18));
                                                                                    }
                                                                                    *(edi + (ecx * 0x4 - 0x14)) = *(esi + (ecx * 0x4 - 0x14));
                                                                            }
                                                                            *(edi + (ecx * 0x4 - 0x10)) = *(esi + (ecx * 0x4 - 0x10));
                                                                    }
                                                                    *(edi + (ecx * 0x4 - 0xc)) = *(esi + (ecx * 0x4 - 0xc));
                                                            }
                                                            *(edi + (ecx * 0x4 - 0x8)) = *(esi + (ecx * 0x4 - 0x8));
                                                    }
                                                    *(edi + (ecx * 0x4 - 0x4)) = *(esi + (ecx * 0x4 - 0x4));
                                            }
                                            eax = (*(edx * 0x4 + 0x47c174))();
                                    }
                            }
                            else {
                                    eax = edi;
                                    ecx = ecx - 0x4;
                                    if (ecx >= 0x0) {
                                            eax = (*((eax & 0x3) * 0x4 + 0x47c088))();
                                    }
                                    else {
                                            eax = (*(ecx * 0x4 + 0x47c184))();
                                    }
                            }
                    }
            }
            else {
                    esi = ecx + (esi - 0x4);
                    edi = ecx + (edi - 0x4);
                    if ((edi & 0x3) == 0x0) {
                            ecx = ecx >> 0x2;
                            edx = edx & 0x3;
                            if (ecx >= 0x8) {
                                    asm { std };
                                    *edi = *esi;
                                    asm { cld };
                                    eax = (*(edx * 0x4 + switch_table))();
                            }
                            else {
                                    eax = (*(-ecx * 0x4 + sub_47c2c0))();
                            }
                    }
                    else {
                            eax = edi;
                            if (ecx >= 0x4) {
                                    eax = (*((eax & 0x3) * 0x4 + 0x47c214))();
                            }
                            else {
                                    switch (*(ecx * 0x4 + switch_table)) {
                                        case 0:
                                            eax = arg_0;
                                            break;
                                        case 1:
                                            edi[0x3] = esi[0x3];
                                            eax = arg_0;
                                            break;
                                        case 2:
                                            edi[0x3] = esi[0x3];
                                            edi[0x2] = esi[0x2];
                                            eax = arg_0;
                                            break;
                                        default:
                                            edi[0x3] = esi[0x3];
                                            edi[0x2] = esi[0x2];
                                            edi[0x1] = esi[0x1];
                                            eax = arg_0;
                                            break;
                                    }
                            }
                    }
            }
    }
    else {
            if (ecx >= 0x100) {
                    if (*dword_bc8368 != 0x0) {
                            bool_6 = (edi & 0xf) != (esi & 0xf);
                            esi = esi;
                            edi = edi;
                            esp = (esp - 0x8) + 0x8;
                            if (!bool_6) {
                                    eax = sub_48722a(arg_fffffffffffffffc, arg_0, arg_4);
                            }
                            else {
                                    if ((edi & 0x3) == 0x0) {
                                            ecx = ecx >> 0x2;
                                            edx = edx & 0x3;
                                            bool_14 = true;
                                            if (ecx >= 0x8) {
                                                    *edi = *esi;
                                                    eax = (*(edx * 0x4 + 0x47c174))();
                                            }
                                            else {
                                                    if (*(ecx * 0x4 + switch_table) != 0x0) {
                                                            if (*(ecx * 0x4 + switch_table) != 0x1) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                                            if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                                                    if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                                            *(edi + (ecx * 0x4 - 0x1c)) = *(esi + (ecx * 0x4 - 0x1c));
                                                                                                    }
                                                                                                    *(edi + (ecx * 0x4 - 0x18)) = *(esi + (ecx * 0x4 - 0x18));
                                                                                            }
                                                                                            *(edi + (ecx * 0x4 - 0x14)) = *(esi + (ecx * 0x4 - 0x14));
                                                                                    }
                                                                                    *(edi + (ecx * 0x4 - 0x10)) = *(esi + (ecx * 0x4 - 0x10));
                                                                            }
                                                                            *(edi + (ecx * 0x4 - 0xc)) = *(esi + (ecx * 0x4 - 0xc));
                                                                    }
                                                                    *(edi + (ecx * 0x4 - 0x8)) = *(esi + (ecx * 0x4 - 0x8));
                                                            }
                                                            *(edi + (ecx * 0x4 - 0x4)) = *(esi + (ecx * 0x4 - 0x4));
                                                    }
                                                    eax = (*(edx * 0x4 + 0x47c174))();
                                            }
                                    }
                                    else {
                                            eax = edi;
                                            ecx = ecx - 0x4;
                                            if (ecx >= 0x0) {
                                                    eax = (*((eax & 0x3) * 0x4 + 0x47c088))();
                                            }
                                            else {
                                                    eax = (*(ecx * 0x4 + 0x47c184))();
                                            }
                                    }
                            }
                    }
                    else {
                            if ((edi & 0x3) == 0x0) {
                                    ecx = ecx >> 0x2;
                                    edx = edx & 0x3;
                                    bool_11 = true;
                                    if (ecx >= 0x8) {
                                            *edi = *esi;
                                            eax = (*(edx * 0x4 + 0x47c174))();
                                    }
                                    else {
                                            if (*(ecx * 0x4 + switch_table) != 0x0) {
                                                    if (*(ecx * 0x4 + switch_table) != 0x1) {
                                                            if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                                            if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                                    *(edi + (ecx * 0x4 - 0x1c)) = *(esi + (ecx * 0x4 - 0x1c));
                                                                                            }
                                                                                            *(edi + (ecx * 0x4 - 0x18)) = *(esi + (ecx * 0x4 - 0x18));
                                                                                    }
                                                                                    *(edi + (ecx * 0x4 - 0x14)) = *(esi + (ecx * 0x4 - 0x14));
                                                                            }
                                                                            *(edi + (ecx * 0x4 - 0x10)) = *(esi + (ecx * 0x4 - 0x10));
                                                                    }
                                                                    *(edi + (ecx * 0x4 - 0xc)) = *(esi + (ecx * 0x4 - 0xc));
                                                            }
                                                            *(edi + (ecx * 0x4 - 0x8)) = *(esi + (ecx * 0x4 - 0x8));
                                                    }
                                                    *(edi + (ecx * 0x4 - 0x4)) = *(esi + (ecx * 0x4 - 0x4));
                                            }
                                            eax = (*(edx * 0x4 + 0x47c174))();
                                    }
                            }
                            else {
                                    eax = edi;
                                    ecx = ecx - 0x4;
                                    if (ecx >= 0x0) {
                                            eax = (*((eax & 0x3) * 0x4 + 0x47c088))();
                                    }
                                    else {
                                            eax = (*(ecx * 0x4 + 0x47c184))();
                                    }
                            }
                    }
            }
            else {
                    if ((edi & 0x3) == 0x0) {
                            ecx = ecx >> 0x2;
                            edx = edx & 0x3;
                            bool_4 = true;
                            if (ecx >= 0x8) {
                                    *edi = *esi;
                                    eax = (*(edx * 0x4 + 0x47c174))();
                            }
                            else {
                                    if (*(ecx * 0x4 + switch_table) != 0x0) {
                                            if (*(ecx * 0x4 + switch_table) != 0x1) {
                                                    if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                            if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                            *(edi + (ecx * 0x4 - 0x1c)) = *(esi + (ecx * 0x4 - 0x1c));
                                                                                    }
                                                                                    *(edi + (ecx * 0x4 - 0x18)) = *(esi + (ecx * 0x4 - 0x18));
                                                                            }
                                                                            *(edi + (ecx * 0x4 - 0x14)) = *(esi + (ecx * 0x4 - 0x14));
                                                                    }
                                                                    *(edi + (ecx * 0x4 - 0x10)) = *(esi + (ecx * 0x4 - 0x10));
                                                            }
                                                            *(edi + (ecx * 0x4 - 0xc)) = *(esi + (ecx * 0x4 - 0xc));
                                                    }
                                                    *(edi + (ecx * 0x4 - 0x8)) = *(esi + (ecx * 0x4 - 0x8));
                                            }
                                            *(edi + (ecx * 0x4 - 0x4)) = *(esi + (ecx * 0x4 - 0x4));
                                    }
                                    eax = (*(edx * 0x4 + 0x47c174))();
                            }
                    }
                    else {
                            eax = edi;
                            ecx = ecx - 0x4;
                            if (ecx >= 0x0) {
                                    eax = (*((eax & 0x3) * 0x4 + 0x47c088))();
                            }
                            else {
                                    eax = (*(ecx * 0x4 + 0x47c184))();
                            }
                    }
            }
    }
    return eax;
}
