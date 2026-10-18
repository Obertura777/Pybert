// sub_41d360 @ 0x41d360
// hopper name: sub_41d360
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41d360() {
    var_C = *0x0;
    decomp_var_58 = esi;
    decomp_var_5c = edi;
    decomp_var_60 = *dword_4c8db8 ^ &decomp_var_5c;
    *0x0 = &var_C;
    var_38 = ecx;
    eax = sub_401e30();
    var_14 = eax;
    eax[0x11] = 0x1;
    var_14[0x1] = var_14;
    *var_14 = var_14;
    var_14[0x2] = var_14;
    var_4 = 0x1;
    var_40 = 0x0;
    var_3C = arg_4 & 0xff;
    eax = sub_465930();
    ebp = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    edi = eax;
    esp = esp - 0x68;
    var_4C = ebp;
    eax = sub_404ce0(&var_24, &var_3C, decomp_var_60);
    esi = 0x0;
    if (edi > 0x0) {
            do {
                    eax = sub_465900(&arg_4, esi);
                    esp = esp - 0x10;
                    var_34 = *(int8_t *)eax & 0xff;
                    eax = sub_404ce0(&var_24, &var_34, decomp_var_60);
                    esi = esi + 0x1;
            } while (esi < edi);
    }
    edi = *(arg_0 * 0x8 + 0x4d2614);
    ebx = *(arg_0 * 0x8 + 0x4d2610);
    esi = *(arg_0 * 0x8 + 0x4d3610);
    ecx = *(arg_0 * 0x8 + 0x4d3614);
    bool_2 = ecx > 0x0;
    var_28 = edi;
    if (ecx >= 0x0) {
            if (!bool_2) {
                    if (esi >= 0x0) {
                            if (arg_18 == ebp) {
                                    ebp = arg_1c;
                                    edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
                                    if (ebp == esi) {
                                            if (edx != ecx) {
                                                    ebp = var_14;
                                                    esp = esp - 0x8;
                                                    arg_4 = esi;
                                                    eax = sub_401ff0(&var_24, &arg_4, decomp_var_60, decomp_var_5c, decomp_var_58);
                                                    edi = eax;
                                                    eax = *edi;
                                                    if (eax == 0x0 || eax != &var_18) {
                                                            sub_47a948();
                                                    }
                                                    bool_107 = edi[0x1] != ebp;
                                                    edi = var_28;
                                                    ebp = arg_1c;
                                                    if (!bool_107) {
                                                            var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                                    }
                                            }
                                    }
                                    else {
                                            ebp = var_14;
                                            esp = esp - 0x8;
                                            arg_4 = esi;
                                            eax = sub_401ff0(&var_24, &arg_4, decomp_var_60, decomp_var_5c, decomp_var_58);
                                            edi = eax;
                                            eax = *edi;
                                            if (eax != 0x0) {
                                                    if (eax != &var_18) {
                                                            sub_47a948();
                                                    }
                                                    bool_92 = edi[0x1] != ebp;
                                                    edi = var_28;
                                                    ebp = arg_1c;
                                                    if (!bool_92) {
                                                            var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    bool_35 = edi[0x1] != ebp;
                                                    edi = var_28;
                                                    ebp = arg_1c;
                                                    if (!bool_35) {
                                                            var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
                                    if (esi == ebp && ecx == edx) {
                                            if (arg_1c != ebp) {
                                                    var_40 = 0xa;
                                            }
                                    }
                                    ebp = arg_1c;
                            }
                    }
                    else {
                            ebp = arg_1c;
                    }
            }
            else {
                    if (arg_18 == ebp) {
                            ebp = arg_1c;
                            edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
                            if (ebp == esi) {
                                    if (edx != ecx) {
                                            ebp = var_14;
                                            esp = esp - 0x8;
                                            arg_4 = esi;
                                            eax = sub_401ff0(&var_24, &arg_4, decomp_var_60, decomp_var_5c, decomp_var_58);
                                            edi = eax;
                                            eax = *edi;
                                            if (eax != 0x0) {
                                                    if (eax != &var_18) {
                                                            sub_47a948();
                                                    }
                                                    bool_99 = edi[0x1] != ebp;
                                                    edi = var_28;
                                                    ebp = arg_1c;
                                                    if (!bool_99) {
                                                            var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    bool_93 = edi[0x1] != ebp;
                                                    edi = var_28;
                                                    ebp = arg_1c;
                                                    if (!bool_93) {
                                                            var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                                    }
                                            }
                                    }
                            }
                            else {
                                    ebp = var_14;
                                    esp = esp - 0x8;
                                    arg_4 = esi;
                                    eax = sub_401ff0(&var_24, &arg_4, decomp_var_60, decomp_var_5c, decomp_var_58);
                                    edi = eax;
                                    eax = *edi;
                                    if (eax != 0x0) {
                                            if (eax != &var_18) {
                                                    sub_47a948();
                                            }
                                            bool_102 = edi[0x1] != ebp;
                                            edi = var_28;
                                            ebp = arg_1c;
                                            if (!bool_102) {
                                                    var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            bool_103 = edi[0x1] != ebp;
                                            edi = var_28;
                                            ebp = arg_1c;
                                            if (!bool_103) {
                                                    var_40 = *((var_4C * 0x15 + esi) * 0x8 + 0x4d5528);
                                            }
                                    }
                            }
                    }
                    else {
                            edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
                            if (esi == ebp) {
                                    if (ecx == edx) {
                                            if (arg_1c != ebp) {
                                                    var_40 = 0xa;
                                                    ebp = arg_1c;
                                            }
                                            else {
                                                    ebp = arg_1c;
                                            }
                                    }
                                    else {
                                            ebp = arg_1c;
                                    }
                            }
                            else {
                                    ebp = arg_1c;
                            }
                    }
            }
    }
    else {
            ebp = arg_1c;
    }
    bool_10 = edi > 0x0;
    if (edi < 0x0) goto loc_41d596;
    goto loc_41d519;

loc_41d596:
    bool_18 = arg_c > 0x0;
    if (arg_c < 0x0) goto loc_41d631;
    goto loc_41d5a1;

loc_41d519:
    if (bool_10) goto .l14;
    goto loc_41d51b;

loc_41d631:
    if (arg_14 == 0x0) goto loc_41d68b;
    goto loc_41d638;

loc_41d5a1:
    if (bool_18) goto .l3;
    goto loc_41d5a3;

.l14:
    ecx = var_2C;
    if (arg_38 != ecx) goto .l23;
    goto .l15;

loc_41d51b:
    if (ebx < 0x0) goto loc_41d596;
    goto loc_41d51f;

loc_41d68b:
    if (arg_18 == 0x0) goto loc_41d6e3;
    goto loc_41d692;

loc_41d638:
    sub_403430(&arg_38, &arg_44, *arg_48, &arg_44, arg_48);
    sub_47c8f9();
    esp = (esp - 0x18) + 0x4;
    sub_465fa0();
    eax = 0xfffec77f;
    *0x0 = arg_70;
    return eax;

.l3:
    ecx = var_C;
    if (arg_58 != ecx) goto .l12;
    goto .l4;

loc_41d5a3:
    if (arg_8 < 0x0) goto loc_41d631;
    goto loc_41d5ae;

.l23:
    edx = ecx & 0x80000000 ? 0xffffffff : 0x0;
    goto loc_41d596;

.l15:
    edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
    if (ebp != ebx) goto .l20;
    goto .l16;

loc_41d51f:
    ecx = var_2C;
    if (arg_38 != ecx) goto loc_41d57f;
    goto loc_41d529;

loc_41d6e3:
    if (arg_1c == 0x0) goto loc_41d73b;
    goto loc_41d6ea;

loc_41d692:
    sub_403430(&arg_38, &arg_44, *arg_48, &arg_44, arg_48);
    sub_47c8f9();
    esp = (esp - 0x18) + 0x4;
    sub_465fa0();
    eax = 0xfffec77e;
    *0x0 = arg_70;
    return eax;

.l12:
    edx = ecx & 0x80000000 ? 0xffffffff : 0x0;
    goto loc_41d631;

.l4:
    ecx = arg_8;
    edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
    if (ebp != ecx) goto .l9;
    goto .l5;

loc_41d5ae:
    ecx = var_C;
    if (arg_58 != ecx) goto loc_41d616;
    goto loc_41d5b8;

.l20:
    edi = arg_8;
    esp = esp - 0x8;
    arg_24 = ebx;
    eax = sub_401ff0(&var_4, &arg_24, var_40, var_3C, var_38);
    esi = eax;
    eax = *esi;
    if (eax == 0x0) goto .l22;
    goto .l21;

.l16:
    if (edx == edi) goto loc_41d596;
    goto .l17;

loc_41d57f:
    edx = ecx & 0x80000000 ? 0xffffffff : 0x0;
    goto loc_41d596;

loc_41d529:
    edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
    if (ebp != ebx) goto .l13;
    goto loc_41d530;

loc_41d73b:
    eax = arg_78;
    edx = arg_10;
    if (eax != edx) goto loc_41d9bf;
    goto loc_41d74b;

loc_41d6ea:
    sub_403430(&arg_38, &arg_44, *arg_48, &arg_44, arg_48);
    sub_47c8f9();
    esp = (esp - 0x18) + 0x4;
    sub_465fa0();
    eax = 0xfffec77d;
    *0x0 = arg_70;
    return eax;

.l9:
    edi = arg_28;
    arg_44 = ecx;
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_18, &arg_44, decomp_var_20, decomp_var_1c, var_18);
    esi = eax;
    eax = *esi;
    if (eax == 0x0) goto .l11;
    goto .l10;

.l5:
    if (edx == arg_c) goto loc_41d631;
    goto .l6;

loc_41d616:
    edx = ecx & 0x80000000 ? 0xffffffff : 0x0;
    goto loc_41d631;

loc_41d5b8:
    ecx = arg_8;
    edx = ebp & 0x80000000 ? 0xffffffff : 0x0;
    if (ebp != ecx) goto .l2;
    goto loc_41d5c3;

.l22:
    sub_47a948();
    if (esi[0x1] != edi) goto loc_41d596;
    goto loc_41d596;

.l21:
    if (eax != &arg_4) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d596;
    goto loc_41d596;

.l17:
    edi = arg_8;
    esp = esp - 0x8;
    arg_24 = ebx;
    eax = sub_401ff0(&var_4, &arg_24, var_40, var_3C, var_38);
    esi = eax;
    eax = *esi;
    if (eax == 0x0) goto .l19;
    goto .l18;

.l13:
    edi = arg_8;
    esp = esp - 0x8;
    arg_24 = ebx;
    eax = sub_401ff0(&var_4, &arg_24, var_40, var_3C, var_38);
    esi = eax;
    eax = *esi;
    if (eax == 0x0) goto loc_41d55f;
    goto loc_41d557;

loc_41d530:
    if (edx == edi) goto loc_41d596;
    goto loc_41d534;

loc_41d9bf:
    if (ebp == eax) {
            esp = esp - 0xc;
            arg_30 = (ebp + ebp * 0x2) * 0x4 + 0xbb7028;
            sub_401ff0(&arg_38, &arg_60, &arg_30, saved_fp, arg_0);
            eax = sub_401050(&arg_30);
            if (eax != 0x0) {
                    sub_405620();
                    sub_465fa0();
                    eax = 0xfffec758;
                    *0x0 = arg_70;
            }
            else {
                    sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    sub_465fa0();
                    eax = 0x0;
                    *0x0 = arg_70;
            }
    }
    else {
            if (ebp != edx) {
                    esp = esp - 0xc;
                    arg_30 = (eax + eax * 0x2) * 0x4 + 0xbb7028;
                    sub_401ff0(&arg_38, &arg_60, &arg_30, saved_fp, arg_0);
                    eax = sub_401050(&arg_30);
                    if (eax != 0x0) {
                            sub_405620();
                            sub_465fa0();
                            eax = 0xfffec74e;
                            *0x0 = arg_70;
                    }
                    else {
                            sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                            sub_47c8f9();
                            esp = (esp - 0x18) + 0x4;
                            sub_465fa0();
                            eax = 0x0;
                            *0x0 = arg_70;
                    }
            }
            else {
                    sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    sub_465fa0();
                    eax = 0x0;
                    *0x0 = arg_70;
            }
    }
    return eax;

loc_41d74b:
    ecx = 0x0;
    arg_64 = 0x0;
    if (*(arg_24[0x2] + 0x2404) <= 0x0) goto loc_41d8d0;
    goto loc_41d764;

.l11:
    sub_47a948();
    if (esi[0x1] != edi) goto loc_41d631;
    goto loc_41d631;

.l10:
    if (eax != &arg_24) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d631;
    goto loc_41d631;

.l6:
    edi = arg_28;
    arg_44 = ecx;
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_18, &arg_44, decomp_var_20, decomp_var_1c, var_18);
    esi = eax;
    eax = *esi;
    if (eax == 0x0) goto .l8;
    goto .l7;

.l2:
    edi = arg_28;
    arg_44 = ecx;
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_18, &arg_44, decomp_var_20, decomp_var_1c, var_18);
    esi = eax;
    eax = *esi;
    if (eax == 0x0) goto loc_41d5f4;
    goto loc_41d5ec;

loc_41d5c3:
    if (edx == arg_c) goto loc_41d631;
    goto loc_41d5c9;

.l19:
    sub_47a948();
    if (esi[0x1] != edi) goto loc_41d596;

.l18:
    if (eax != &arg_4) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d596;
    goto loc_41d596;

loc_41d55f:
    sub_47a948();
    if (esi[0x1] != edi) goto loc_41d596;

loc_41d557:
    if (eax != &arg_4) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d596;
    goto loc_41d596;

loc_41d534:
    edi = arg_8;
    esp = esp - 0x8;
    arg_24 = ebx;
    eax = sub_401ff0(&var_4, &arg_24, var_40, var_3C, var_38);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != &arg_4) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d596;
    goto loc_41d596;

loc_41d8d0:
    if (ebp != edx) {
            ebx = *((ebp + ebp * 0x2) * 0x4 + 0xbb702c);
            esi = (ebp + ebp * 0x2) * 0x4 + 0xbb7028;
            esp = esp - 0x8;
            eax = sub_401ff0(&arg_58, &arg_80, arg_1c, arg_20, arg_24);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] != ebx) {
                    sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    sub_465fa0();
                    eax = 0xfffec762;
                    *0x0 = arg_70;
            }
            else {
                    sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    sub_465fa0();
                    eax = 0x0;
                    *0x0 = arg_70;
            }
    }
    else {
            sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
            sub_47c8f9();
            esp = (esp - 0x18) + 0x4;
            sub_465fa0();
            eax = 0x0;
            *0x0 = arg_70;
    }
    return eax;

loc_41d764:
    goto loc_41d770;

.l8:
    sub_47a948();
    if (esi[0x1] != edi) goto loc_41d631;

.l7:
    if (eax != &arg_24) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d631;
    goto loc_41d631;

loc_41d5f4:
    sub_47a948();
    if (esi[0x1] != edi) goto loc_41d631;

loc_41d5ec:
    if (eax != &arg_24) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d631;
    goto loc_41d631;

loc_41d5c9:
    edi = arg_28;
    arg_44 = ecx;
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_18, &arg_44, decomp_var_20, decomp_var_1c, var_18);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != &arg_24) {
            sub_47a948();
    }
    if (esi[0x1] != edi) goto loc_41d631;
    goto loc_41d631;

loc_41d770:
    edx = *(ecx * 0x8 + 0x4cf568);
    edx = edx | *(ecx * 0x8 + 0x4cf56c);
    if (edx != 0x0) goto loc_41d8b2;
    goto loc_41d784;

loc_41d8b2:
    eax = arg_44[0x2];
    ecx = ecx + 0x1;
    arg_84 = ecx;
    if (ecx < eax[0x901]) {
            continue;
    }
    edx = arg_30;
    temp_1 = 0x2;
    break;

loc_41d784:
    ebx = (ecx + ecx * 0x2) * 0x4 + 0xbb6f28;
    eax = ebx[0x1];
    eax = *eax;
    esi = ebx;
    edi = eax;
    arg_48 = esi;
    arg_4c = edi;
    goto loc_41d7a0;

.l24:
    switch (temp_1) {
        case 0:
            *0x0 = arg_70;
            break;
        case 1:
            *0x0 = arg_70;
            break;
        default:
            if (ebp != edx) {
                    ebx = *((ebp + ebp * 0x2) * 0x4 + 0xbb702c);
                    esi = (ebp + ebp * 0x2) * 0x4 + 0xbb7028;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&arg_58, &arg_80, arg_1c, arg_20, arg_24);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] != ebx) {
                            sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                            sub_47c8f9();
                            esp = (esp - 0x18) + 0x4;
                            sub_465fa0();
                            eax = 0xfffec762;
                            *0x0 = arg_70;
                    }
                    else {
                            sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                            sub_47c8f9();
                            esp = (esp - 0x18) + 0x4;
                            sub_465fa0();
                            eax = 0x0;
                            *0x0 = arg_70;
                    }
            }
            else {
                    sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    sub_465fa0();
                    eax = 0x0;
                    *0x0 = arg_70;
            }
            break;
    }
    return eax;

loc_41d7a0:
    ebp = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            eax = sub_47a948();
            ecx = arg_84;
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
                    ecx = arg_84;
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
                    ecx = arg_84;
            }
            if (edi[0x3] != arg_80) {
                    eax = sub_401520();
                    edi = arg_4c;
                    esi = arg_48;
                    ecx = arg_84;
                    continue;
            }
            eax = arg_9C;
            if (eax == arg_30) {
                    if (arg_40 == ecx) {
                            eax = sub_401520();
                            edi = arg_4c;
                            esi = arg_48;
                            ecx = arg_84;
                            continue;
                    }
                    eax = sub_403430(&arg_58, &arg_64, *arg_68, &arg_64, arg_68);
                    edx = arg_68;
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    ecx = &arg_88;
                    arg_68 = 0x0;
                    sub_465fa0();
                    eax = 0xfffec776;
                    temp_0 = 0x0;
                    break;
            }
            else {
                    if (eax == ecx) {
                            edi = arg_68;
                            edx = &arg_58;
                            esp = esp - 0x8;
                            ecx = &arg_64;
                            eax = sub_401ff0(edx, &arg_84, arg_1c, arg_20, arg_24);
                            esi = eax;
                            eax = *esi;
                            if (eax != 0x0) {
                                    ecx = &arg_64;
                                    if (eax != ecx) {
                                            eax = sub_47a948();
                                    }
                            }
                            else {
                                    eax = sub_47a948();
                            }
                            if (esi[0x1] != edi) {
                                    eax = sub_401520();
                                    edi = arg_4c;
                                    esi = arg_48;
                                    ecx = arg_84;
                                    continue;
                            }
                            temp_0 = 0x2;
                            break;
                    }
                    else {
                            temp_0 = 0x2;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x1;
            break;
    }
    goto .l25;

.l25:
    if (temp_0 != 0x0) {
            if (temp_0 != 0x1) {
                    edx = *arg_68;
                    eax = sub_403430(&arg_58, &arg_64, edx, &arg_64, arg_68);
                    sub_47c8f9();
                    esp = (esp - 0x18) + 0x4;
                    arg_68 = 0x0;
                    sub_465fa0();
                    eax = 0xfffec76c;
                    temp_1 = 0x1;
                    break;
            }
            else {
                    ebp = arg_9C;
                    eax = arg_44[0x2];
                    ecx = ecx + 0x1;
                    arg_84 = ecx;
                    if (ecx < eax[0x901]) {
                            continue;
                    }
                    edx = arg_30;
                    temp_1 = 0x2;
                    break;
            }
    }
    else {
            temp_1 = 0x0;
            break;
    }
    goto .l24;
}
