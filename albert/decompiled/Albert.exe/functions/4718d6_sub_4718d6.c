// sub_4718d6 @ 0x4718d6
// hopper name: sub_4718d6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4718d6() {
    ebx = arg_0;
    esp = esp - 0xc;
    var_20 = 0x0;
    if (ebx != 0x0) goto loc_4718f6;
    goto loc_4718ec;

loc_4718f6:
    edi = arg_14;
    if (edi != 0x0) goto loc_471907;
    goto loc_4718fd;

loc_4718ec:
    eax = 0x80070057;
    return eax;

loc_471907:
    ecx = edi[0x2];
    if (ecx <= 0x5) goto loc_471919;
    goto loc_47190f;

loc_4718fd:
    eax = 0x80020008;
    return eax;

loc_471919:
    edx = 0x0;
    arg_0 = 0x0;
    if (edi[0x3] <= 0x0) goto loc_47194a;
    goto loc_471921;

loc_47190f:
    eax = 0x8002000e;
    return eax;

loc_47194a:
    if (arg_0 < ecx) {
            edx = ecx - arg_0;
            eax = (arg_0 << 0x4) + *edi;
            ecx = ecx - arg_0;
            edx = ebp + (edx * 0x4 - 0x48);
            do {
                    *edx = eax;
                    eax = eax + 0x10;
                    edx = edx - 0x4;
                    ecx = ecx - 0x1;
            } while (ecx != 0x0);
    }
    if (arg_20 == 0x0) {
            arg_20 = &arg_10;
    }
    if (arg_18 == 0x0) {
            arg_18 = &var_20;
    }
    esp = esp - 0x4;
    eax = VariantInit(&var_10);
    eax = arg_4 + 0x139a;
    if (eax > 0x12) goto loc_471e40;
    goto loc_4719a6;

loc_471921:
    arg_14 = edi[0x1];
    while (true) {
            eax = *arg_14;
            if (eax >= ecx) {
                    temp_0 = 0x0;
                    break;
            }
            arg_14 = arg_14 + 0x4;
            arg_0 = arg_0 + 0x1;
            *(ebp + (eax * 0x4 - 0x44)) = *edi + edx;
            edx = edx + 0x10;
            if (arg_0 < edi[0x3]) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0) goto .l2;
    goto .l4;

loc_471e40:
    esp = esp - 0x4;
    VariantClear(&var_10);
    eax = 0x80020003;
    return eax;

loc_4719a6:
    ecx = arg_10;
    esp = (esp - 0x4) + 0x4;
    if (*(eax * 0x4 + switch_table) == 0x0) goto loc_4719b3;
    goto .l46;

.l2:
    eax = 0x8002000e;
    return eax;

.l4:
    if (arg_0 < ecx) {
            edx = ecx - arg_0;
            eax = (arg_0 << 0x4) + *edi;
            ecx = ecx - arg_0;
            edx = ebp + (edx * 0x4 - 0x48);
            do {
                    *edx = eax;
                    eax = eax + 0x10;
                    edx = edx - 0x4;
                    ecx = ecx - 0x1;
            } while (ecx != 0x0);
    }
    if (arg_20 == 0x0) {
            arg_20 = &arg_10;
    }
    if (arg_18 == 0x0) {
            arg_18 = &var_20;
    }
    esp = esp - 0x4;
    eax = VariantInit(&var_10);
    eax = arg_4 + 0x139a;
    if (eax > 0x12) goto .l3;
    goto .l9;

loc_4719b3:
    bool_11 = true;
    bool_10 = true;
    bool_9 = true;
    bool_8 = true;
    if (edi[0x2] == 0x1) {
            eax = *ebx;
            decomp_var_60 = *var_44;
            decomp_var_60 = *var_44;
            decomp_var_60 = *var_44;
            esp = esp - 0x14;
            decomp_var_60 = *var_44;
            eax = (eax[0x19])(ebx);
            esi = eax;
    }
    else {
            esi = 0x8002000e;
    }
    esp = esp - 0x4;
    VariantClear(&var_10);
    eax = esi;
    return eax;

.l46:
    if (*(eax * 0x4 + switch_table) == 0x1) goto loc_4719d4;
    goto .l47;

.l3:
    esp = esp - 0x4;
    VariantClear(&var_10);
    eax = 0x80020003;
    return eax;

.l9:
    ecx = arg_10;
    esp = (esp - 0x4) + 0x4;
    if (*(eax * 0x4 + switch_table) == 0x0) goto .l8;
    goto .l17;

loc_4719d4:
    if (edi[0x2] == 0x2) {
            eax = var_44;
            if (*(int16_t *)eax != 0x3) {
                    esp = esp - 0x10;
                    eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                    esi = eax;
                    if (esi >= 0x0) {
                            eax = &var_10;
                            arg_10 = eax[0x2];
                            eax = var_40;
                            if (*(int16_t *)eax != 0x3) {
                                    esp = esp - 0x10;
                                    eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                    esi = eax;
                                    if (esi >= 0x0) {
                                            eax = &var_10;
                                            eax = eax[0x2];
                                            esp = esp - 0x10;
                                            eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                                            esi = eax;
                                    }
                                    else {
                                            *arg_20 = 0x1;
                                    }
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                            else {
                                    eax = eax[0x2];
                                    esp = esp - 0x10;
                                    eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                                    esi = eax;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                    }
                    else {
                            *arg_20 = *arg_20 & 0x0;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    arg_10 = eax[0x2];
                    eax = var_40;
                    if (*(int16_t *)eax != 0x3) {
                            esp = esp - 0x10;
                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                            esi = eax;
                            if (esi >= 0x0) {
                                    eax = &var_10;
                                    eax = eax[0x2];
                                    esp = esp - 0x10;
                                    eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                                    esi = eax;
                            }
                            else {
                                    *arg_20 = 0x1;
                            }
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
                    else {
                            eax = eax[0x2];
                            esp = esp - 0x10;
                            eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                            esi = eax;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
    }
    else {
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = 0x8002000e;
    }
    return eax;

.l47:
    if (*(eax * 0x4 + switch_table) == 0x2) goto loc_471a41;
    goto .l48;

.l8:
    bool_337 = true;
    bool_336 = true;
    bool_335 = true;
    bool_334 = true;
    if (edi[0x2] == 0x1) {
            eax = *ebx;
            decomp_var_60 = *var_44;
            decomp_var_60 = *var_44;
            decomp_var_60 = *var_44;
            esp = esp - 0x14;
            decomp_var_60 = *var_44;
            eax = (eax[0x19])(ebx);
            esi = eax;
    }
    else {
            esi = 0x8002000e;
    }
    esp = esp - 0x4;
    VariantClear(&var_10);
    eax = esi;
    return eax;

.l17:
    if (*(eax * 0x4 + switch_table) == 0x1) goto .l6;
    goto .l12;

loc_471a41:
    if (edi[0x2] == 0x2) {
            eax = var_44;
            bool_109 = true;
            bool_108 = true;
            bool_107 = true;
            bool_106 = true;
            if (*(int16_t *)eax != 0x3) {
                    esp = esp - 0x10;
                    eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                    esi = eax;
                    bool_113 = true;
                    bool_112 = true;
                    bool_111 = true;
                    bool_110 = true;
                    if (esi >= 0x0) {
                            eax = &var_10;
                            eax = eax[0x2];
                            ecx = *ebx;
                            decomp_var_64 = *var_40;
                            decomp_var_64 = *var_40;
                            decomp_var_64 = *var_40;
                            esp = esp - 0x1c;
                            decomp_var_64 = *var_40;
                            eax = (ecx[0x17])(ebx, eax);
                            esi = eax;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
                    else {
                            *arg_20 = *arg_20 & 0x0;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    eax = eax[0x2];
                    ecx = *ebx;
                    decomp_var_64 = *var_40;
                    decomp_var_64 = *var_40;
                    decomp_var_64 = *var_40;
                    esp = esp - 0x1c;
                    decomp_var_64 = *var_40;
                    eax = (ecx[0x17])(ebx, eax);
                    esi = eax;
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = esi;
            }
    }
    else {
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = 0x8002000e;
    }
    return eax;

.l48:
    if (*(eax * 0x4 + switch_table) == 0x3) goto loc_471a8e;
    goto .l49;

.l6:
    if (edi[0x2] == 0x2) {
            eax = var_44;
            if (*(int16_t *)eax != 0x3) {
                    esp = esp - 0x10;
                    eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                    esi = eax;
                    if (esi >= 0x0) {
                            eax = &var_10;
                            arg_10 = eax[0x2];
                            eax = var_40;
                            if (*(int16_t *)eax != 0x3) {
                                    esp = esp - 0x10;
                                    eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                    esi = eax;
                                    if (esi >= 0x0) {
                                            eax = &var_10;
                                            eax = eax[0x2];
                                            esp = esp - 0x10;
                                            eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                                            esi = eax;
                                    }
                                    else {
                                            *arg_20 = 0x1;
                                    }
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                            else {
                                    eax = eax[0x2];
                                    esp = esp - 0x10;
                                    eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                                    esi = eax;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                    }
                    else {
                            *arg_20 = *arg_20 & 0x0;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    arg_10 = eax[0x2];
                    eax = var_40;
                    if (*(int16_t *)eax != 0x3) {
                            esp = esp - 0x10;
                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                            esi = eax;
                            if (esi >= 0x0) {
                                    eax = &var_10;
                                    eax = eax[0x2];
                                    esp = esp - 0x10;
                                    eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                                    esi = eax;
                            }
                            else {
                                    *arg_20 = 0x1;
                            }
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
                    else {
                            eax = eax[0x2];
                            esp = esp - 0x10;
                            eax = (*(*ebx + 0x60))(ebx, arg_10, eax, arg_18);
                            esi = eax;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
    }
    else {
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = 0x8002000e;
    }
    return eax;

.l12:
    if (*(eax * 0x4 + switch_table) == 0x2) goto .l7;
    goto .l14;

loc_471a8e:
    if (edi[0x2] != 0x5) goto .l25;
    goto loc_471a98;

.l49:
    switch (*(eax * 0x4 + switch_table)) {
        case 4:
            if (edi[0x2] == 0x2) {
                    eax = var_44;
                    bool_71 = true;
                    bool_70 = true;
                    bool_69 = true;
                    bool_68 = true;
                    if (*(int16_t *)eax != 0x3) {
                            esp = esp - 0x10;
                            decomp_var_60 = &var_10;
                            esi = VariantChangeType(decomp_var_60, eax, 0x0, 0x3);
                            bool_76 = true;
                            bool_75 = true;
                            bool_74 = true;
                            bool_73 = true;
                            if (esi >= 0x0) {
                                    eax = &var_10;
                                    eax = eax[0x2];
                                    ecx = *ebx;
                                    decomp_var_60 = *var_40;
                                    decomp_var_60 = *var_40;
                                    decomp_var_60 = *var_40;
                                    esp = esp - 0x18;
                                    decomp_var_60 = *var_40;
                                    eax = (ecx[0x15])(ebx, eax);
                                    esi = eax;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                            else {
                                    *arg_20 = *arg_20 & 0x0;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                    }
                    else {
                            eax = eax[0x2];
                            ecx = *ebx;
                            decomp_var_60 = *var_40;
                            decomp_var_60 = *var_40;
                            decomp_var_60 = *var_40;
                            esp = esp - 0x18;
                            decomp_var_60 = *var_40;
                            eax = (ecx[0x15])(ebx, eax);
                            esi = eax;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = 0x8002000e;
            }
            break;
        case 5:
            bool_93 = true;
            bool_92 = true;
            bool_91 = true;
            bool_90 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0x14])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 6:
            eax = *ebx;
            esp = esp - 0x8;
            eax = (eax[0x13])(ebx, arg_18);
            esi = eax;
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 7:
            eax = *ebx;
            esp = esp - 0x8;
            eax = (eax[0x12])(ebx, arg_18);
            esi = eax;
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 8:
            bool_54 = true;
            bool_53 = true;
            bool_52 = true;
            bool_51 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0x11])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 9:
            if (edi[0x2] == 0x2) {
                    esi = var_44;
                    eax = *(int16_t *)esi & 0xffff;
                    if ((eax & 0x4000) != 0x0) {
                            if ((eax & 0xc) == 0x0) {
                                    *arg_20 = *arg_20 & 0x0;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = 0x80020005;
                            }
                            else {
                                    bool_60 = true;
                                    bool_59 = true;
                                    bool_58 = true;
                                    bool_57 = true;
                                    if (eax == 0x400c) {
                                            esp = esp - 0x4;
                                            VariantClear(esi[0x2]);
                                            *(int16_t *)esi[0x2] = 0x8;
                                            eax = esi[0x2];
                                            eax = eax + 0x8;
                                    }
                                    else {
                                            if (eax == 0x4008) {
                                                    eax = esi[0x2];
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    VariantClear(esi);
                                                    eax = esi + 0x8;
                                                    *(int16_t *)esi = 0x8;
                                            }
                                    }
                                    ecx = *ebx;
                                    var_40 = *var_40;
                                    var_40 = *var_40;
                                    var_40 = *var_40;
                                    esp = esp - 0x1c;
                                    var_40 = *var_40;
                                    eax = (ecx[0x10])(ebx, eax);
                                    esi = eax;
                                    if (esi >= 0x0) {
                                            *(int16_t *)arg_18 = 0x3;
                                    }
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                    }
                    else {
                            if (eax == 0x400c) {
                                    esp = esp - 0x4;
                                    VariantClear(esi[0x2]);
                                    *(int16_t *)esi[0x2] = 0x8;
                                    eax = esi[0x2];
                                    eax = eax + 0x8;
                            }
                            else {
                                    bool_45 = true;
                                    bool_44 = true;
                                    bool_43 = true;
                                    bool_42 = true;
                                    if (eax == 0x4008) {
                                            eax = esi[0x2];
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            VariantClear(esi);
                                            eax = esi + 0x8;
                                            *(int16_t *)esi = 0x8;
                                    }
                            }
                            ecx = *ebx;
                            var_40 = *var_40;
                            var_40 = *var_40;
                            var_40 = *var_40;
                            esp = esp - 0x1c;
                            var_40 = *var_40;
                            eax = (ecx[0x10])(ebx, eax);
                            esi = eax;
                            if (esi >= 0x0) {
                                    *(int16_t *)arg_18 = 0x3;
                            }
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = 0x8002000e;
            }
            break;
        case 10:
            bool_148 = true;
            bool_147 = true;
            bool_146 = true;
            bool_145 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xf])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 11:
            bool_133 = true;
            bool_132 = true;
            bool_131 = true;
            bool_130 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xe])(ebx);
                    esi = eax;
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 12:
            bool_168 = true;
            bool_167 = true;
            bool_166 = true;
            bool_165 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xd])(ebx);
                    esi = eax;
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 13:
            bool_172 = true;
            bool_171 = true;
            bool_170 = true;
            bool_169 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xc])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 14:
            if ((0x2 & ecx) != 0x0) {
                    bool_154 = true;
                    bool_153 = true;
                    bool_152 = true;
                    bool_151 = true;
                    if (edi[0x2] == 0x1) {
                            eax = *ebx;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            esp = esp - 0x18;
                            decomp_var_64 = *var_44;
                            eax = (eax[0xb])(ebx);
                            esi = eax;
                            if (esi >= 0x0) {
                                    *(int16_t *)arg_18 = 0x8;
                            }
                    }
                    else {
                            esi = 0x8002000e;
                    }
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = esi;
            }
            else {
                    if ((ecx & 0x4) != 0x0) {
                            bool_139 = true;
                            bool_138 = true;
                            bool_137 = true;
                            if (edi[0x2] == 0x2) {
                                    eax = var_40;
                                    bool_143 = true;
                                    bool_142 = true;
                                    bool_141 = true;
                                    bool_140 = true;
                                    bool_136 = *(int16_t *)eax == 0x8;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    if (!bool_136) {
                                            esp = esp - 0x10;
                                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                            esi = eax;
                                            bool_87 = true;
                                            bool_86 = true;
                                            bool_85 = true;
                                            bool_84 = true;
                                            if (esi >= 0x0) {
                                                    eax = &var_10;
                                                    ecx = *ebx;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    esp = esp - 0x18;
                                                    decomp_var_64 = var_30;
                                                    eax = (ecx[0x1b])(ebx);
                                                    esi = eax;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                            else {
                                                    *arg_20 = 0x1;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                    }
                                    else {
                                            ecx = *ebx;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            esp = esp - 0x18;
                                            decomp_var_64 = var_30;
                                            eax = (ecx[0x1b])(ebx);
                                            esi = eax;
                                            esp = esp - 0x4;
                                            VariantClear(&var_10);
                                            eax = esi;
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = 0x8002000e;
                            }
                    }
                    else {
                            if ((0x2 & ecx) != 0x0) {
                                    bool_27 = true;
                                    bool_26 = true;
                                    bool_25 = true;
                                    bool_24 = true;
                                    if (edi[0x2] == 0x1) {
                                            eax = *ebx;
                                            decomp_var_64 = *var_44;
                                            decomp_var_64 = *var_44;
                                            decomp_var_64 = *var_44;
                                            esp = esp - 0x18;
                                            decomp_var_64 = *var_44;
                                            eax = (eax[0xa])(ebx);
                                            esi = eax;
                                            if (esi >= 0x0) {
                                                    *(int16_t *)arg_18 = 0x8;
                                            }
                                    }
                                    else {
                                            esi = 0x8002000e;
                                    }
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                            else {
                                    if ((ecx & 0x4) != 0x0) {
                                            bool_37 = true;
                                            bool_36 = true;
                                            bool_35 = true;
                                            if (edi[0x2] == 0x2) {
                                                    eax = var_40;
                                                    bool_41 = true;
                                                    bool_40 = true;
                                                    bool_39 = true;
                                                    bool_38 = true;
                                                    bool_34 = *(int16_t *)eax == 0x8;
                                                    var_30 = *var_44;
                                                    var_30 = *var_44;
                                                    var_30 = *var_44;
                                                    var_30 = *var_44;
                                                    if (!bool_34) {
                                                            esp = esp - 0x10;
                                                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                                            esi = eax;
                                                            bool_22 = true;
                                                            bool_21 = true;
                                                            bool_20 = true;
                                                            bool_19 = true;
                                                            if (esi < 0x0) {
                                                                    *arg_20 = 0x1;
                                                                    esp = esp - 0x4;
                                                                    VariantClear(&var_10);
                                                                    eax = esi;
                                                            }
                                                            else {
                                                                    eax = &var_10;
                                                                    ecx = *ebx;
                                                                    decomp_var_64 = var_30;
                                                                    decomp_var_64 = var_30;
                                                                    decomp_var_64 = var_30;
                                                                    esp = esp - 0x18;
                                                                    decomp_var_64 = var_30;
                                                                    eax = (ecx[0x1a])(ebx);
                                                                    esi = eax;
                                                                    esp = esp - 0x4;
                                                                    VariantClear(&var_10);
                                                                    eax = esi;
                                                            }
                                                    }
                                                    else {
                                                            ecx = *ebx;
                                                            decomp_var_64 = var_30;
                                                            decomp_var_64 = var_30;
                                                            decomp_var_64 = var_30;
                                                            esp = esp - 0x18;
                                                            decomp_var_64 = var_30;
                                                            eax = (ecx[0x1a])(ebx);
                                                            esi = eax;
                                                            esp = esp - 0x4;
                                                            VariantClear(&var_10);
                                                            eax = esi;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = 0x8002000e;
                                            }
                                    }
                                    else {
                                            bool_182 = true;
                                            bool_181 = true;
                                            bool_180 = true;
                                            bool_179 = true;
                                            if (edi[0x2] != 0x1) {
                                                    esi = 0x8002000e;
                                            }
                                            else {
                                                    eax = *ebx;
                                                    decomp_var_64 = *var_44;
                                                    decomp_var_64 = *var_44;
                                                    decomp_var_64 = *var_44;
                                                    esp = esp - 0x18;
                                                    decomp_var_64 = *var_44;
                                                    eax = (eax[0x9])(ebx);
                                                    esi = eax;
                                                    if (esi >= 0x0) {
                                                            *(int16_t *)arg_18 = 0x9;
                                                    }
                                            }
                                            esp = esp - 0x4;
                                            VariantClear(&var_10);
                                            eax = esi;
                                    }
                            }
                    }
            }
            break;
        case 15:
            if ((0x2 & ecx) != 0x0) {
                    bool_82 = true;
                    bool_81 = true;
                    bool_80 = true;
                    bool_79 = true;
                    if (edi[0x2] == 0x1) {
                            eax = *ebx;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            esp = esp - 0x18;
                            decomp_var_64 = *var_44;
                            eax = (eax[0xa])(ebx);
                            esi = eax;
                            if (esi >= 0x0) {
                                    *(int16_t *)arg_18 = 0x8;
                            }
                    }
                    else {
                            esi = 0x8002000e;
                    }
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = esi;
            }
            else {
                    if ((ecx & 0x4) != 0x0) {
                            bool_158 = true;
                            bool_157 = true;
                            bool_156 = true;
                            if (edi[0x2] == 0x2) {
                                    eax = var_40;
                                    bool_163 = true;
                                    bool_162 = true;
                                    bool_161 = true;
                                    bool_160 = true;
                                    bool_155 = *(int16_t *)eax == 0x8;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    if (!bool_155) {
                                            esp = esp - 0x10;
                                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                            esi = eax;
                                            bool_104 = true;
                                            bool_103 = true;
                                            bool_102 = true;
                                            bool_101 = true;
                                            if (esi < 0x0) {
                                                    *arg_20 = 0x1;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                            else {
                                                    eax = &var_10;
                                                    ecx = *ebx;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    esp = esp - 0x18;
                                                    decomp_var_64 = var_30;
                                                    eax = (ecx[0x1a])(ebx);
                                                    esi = eax;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                    }
                                    else {
                                            ecx = *ebx;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            esp = esp - 0x18;
                                            decomp_var_64 = var_30;
                                            eax = (ecx[0x1a])(ebx);
                                            esi = eax;
                                            esp = esp - 0x4;
                                            VariantClear(&var_10);
                                            eax = esi;
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = 0x8002000e;
                            }
                    }
                    else {
                            bool_127 = true;
                            bool_126 = true;
                            bool_125 = true;
                            bool_124 = true;
                            if (edi[0x2] != 0x1) {
                                    esi = 0x8002000e;
                            }
                            else {
                                    eax = *ebx;
                                    decomp_var_64 = *var_44;
                                    decomp_var_64 = *var_44;
                                    decomp_var_64 = *var_44;
                                    esp = esp - 0x18;
                                    decomp_var_64 = *var_44;
                                    eax = (eax[0x9])(ebx);
                                    esi = eax;
                                    if (esi >= 0x0) {
                                            *(int16_t *)arg_18 = 0x9;
                                    }
                            }
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            break;
        case 16:
            bool_98 = true;
            bool_97 = true;
            bool_96 = true;
            bool_95 = true;
            if (edi[0x2] != 0x1) {
                    esi = 0x8002000e;
            }
            else {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0x9])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x9;
                    }
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        default:
            if (*(eax * 0x4 + switch_table) != 0x11) {
                    eax = *ebx;
                    esp = esp - 0x8;
                    eax = (eax[0x7])(ebx, arg_18 + 0x8);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x9;
                    }
            }
            else {
                    eax = *ebx;
                    esp = esp - 0x8;
                    eax = (eax[0x8])(ebx, arg_18 + 0x8);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x3;
                    }
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
    }
    return eax;

.l7:
    if (edi[0x2] == 0x2) {
            eax = var_44;
            bool_256 = true;
            bool_255 = true;
            bool_254 = true;
            bool_253 = true;
            if (*(int16_t *)eax != 0x3) {
                    esp = esp - 0x10;
                    eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                    esi = eax;
                    bool_260 = true;
                    bool_259 = true;
                    bool_258 = true;
                    bool_257 = true;
                    if (esi >= 0x0) {
                            eax = &var_10;
                            eax = eax[0x2];
                            ecx = *ebx;
                            decomp_var_64 = *var_40;
                            decomp_var_64 = *var_40;
                            decomp_var_64 = *var_40;
                            esp = esp - 0x1c;
                            decomp_var_64 = *var_40;
                            eax = (ecx[0x17])(ebx, eax);
                            esi = eax;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
                    else {
                            *arg_20 = *arg_20 & 0x0;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    eax = eax[0x2];
                    ecx = *ebx;
                    decomp_var_64 = *var_40;
                    decomp_var_64 = *var_40;
                    decomp_var_64 = *var_40;
                    esp = esp - 0x1c;
                    decomp_var_64 = *var_40;
                    eax = (ecx[0x17])(ebx, eax);
                    esi = eax;
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = esi;
            }
    }
    else {
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = 0x8002000e;
    }
    return eax;

.l14:
    if (*(eax * 0x4 + switch_table) == 0x3) goto .l15;
    goto .l5;

.l25:
    esi = 0x8002000e;
    goto .l10;

loc_471a98:
    esi = var_44;
    eax = var_10;
    goto loc_471a9e;

.l15:
    if (edi[0x2] != 0x5) goto .l16;
    goto .l11;

.l5:
    switch (*(eax * 0x4 + switch_table)) {
        case 4:
            if (edi[0x2] == 0x2) {
                    eax = var_44;
                    bool_316 = true;
                    bool_315 = true;
                    bool_314 = true;
                    bool_313 = true;
                    if (*(int16_t *)eax != 0x3) {
                            esp = esp - 0x10;
                            decomp_var_60 = &var_10;
                            esi = VariantChangeType(decomp_var_60, eax, 0x0, 0x3);
                            bool_321 = true;
                            bool_320 = true;
                            bool_319 = true;
                            bool_318 = true;
                            if (esi >= 0x0) {
                                    eax = &var_10;
                                    eax = eax[0x2];
                                    ecx = *ebx;
                                    decomp_var_60 = *var_40;
                                    decomp_var_60 = *var_40;
                                    decomp_var_60 = *var_40;
                                    esp = esp - 0x18;
                                    decomp_var_60 = *var_40;
                                    eax = (ecx[0x15])(ebx, eax);
                                    esi = eax;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                            else {
                                    *arg_20 = *arg_20 & 0x0;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                    }
                    else {
                            eax = eax[0x2];
                            ecx = *ebx;
                            decomp_var_60 = *var_40;
                            decomp_var_60 = *var_40;
                            decomp_var_60 = *var_40;
                            esp = esp - 0x18;
                            decomp_var_60 = *var_40;
                            eax = (ecx[0x15])(ebx, eax);
                            esi = eax;
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = 0x8002000e;
            }
            break;
        case 5:
            bool_240 = true;
            bool_239 = true;
            bool_238 = true;
            bool_237 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0x14])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 6:
            eax = *ebx;
            esp = esp - 0x8;
            eax = (eax[0x13])(ebx, arg_18);
            esi = eax;
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 7:
            eax = *ebx;
            esp = esp - 0x8;
            eax = (eax[0x12])(ebx, arg_18);
            esi = eax;
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 8:
            bool_279 = true;
            bool_278 = true;
            bool_277 = true;
            bool_276 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0x11])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 9:
            if (edi[0x2] == 0x2) {
                    esi = var_44;
                    eax = *(int16_t *)esi & 0xffff;
                    if ((eax & 0x4000) != 0x0) {
                            if ((eax & 0xc) == 0x0) {
                                    *arg_20 = *arg_20 & 0x0;
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = 0x80020005;
                            }
                            else {
                                    if (eax == 0x400c) {
                                            esp = esp - 0x4;
                                            VariantClear(esi[0x2]);
                                            *(int16_t *)esi[0x2] = 0x8;
                                            eax = esi[0x2];
                                            eax = eax + 0x8;
                                    }
                                    else {
                                            bool_285 = true;
                                            bool_284 = true;
                                            bool_283 = true;
                                            bool_282 = true;
                                            if (eax == 0x4008) {
                                                    eax = esi[0x2];
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    VariantClear(esi);
                                                    eax = esi + 0x8;
                                                    *(int16_t *)esi = 0x8;
                                            }
                                    }
                                    ecx = *ebx;
                                    var_40 = *var_40;
                                    var_40 = *var_40;
                                    var_40 = *var_40;
                                    esp = esp - 0x1c;
                                    var_40 = *var_40;
                                    eax = (ecx[0x10])(ebx, eax);
                                    esi = eax;
                                    if (esi >= 0x0) {
                                            *(int16_t *)arg_18 = 0x3;
                                    }
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                    }
                    else {
                            bool_308 = true;
                            bool_307 = true;
                            bool_306 = true;
                            bool_305 = true;
                            if (eax == 0x400c) {
                                    esp = esp - 0x4;
                                    VariantClear(esi[0x2]);
                                    *(int16_t *)esi[0x2] = 0x8;
                                    eax = esi[0x2];
                                    eax = eax + 0x8;
                            }
                            else {
                                    if (eax == 0x4008) {
                                            eax = esi[0x2];
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            VariantClear(esi);
                                            eax = esi + 0x8;
                                            *(int16_t *)esi = 0x8;
                                    }
                            }
                            ecx = *ebx;
                            var_40 = *var_40;
                            var_40 = *var_40;
                            var_40 = *var_40;
                            esp = esp - 0x1c;
                            var_40 = *var_40;
                            eax = (ecx[0x10])(ebx, eax);
                            esi = eax;
                            if (esi >= 0x0) {
                                    *(int16_t *)arg_18 = 0x3;
                            }
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            else {
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = 0x8002000e;
            }
            break;
        case 10:
            bool_352 = true;
            bool_351 = true;
            bool_350 = true;
            bool_349 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xf])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 11:
            bool_229 = true;
            bool_228 = true;
            bool_227 = true;
            bool_226 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xe])(ebx);
                    esi = eax;
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 12:
            bool_205 = true;
            bool_204 = true;
            bool_203 = true;
            bool_202 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xd])(ebx);
                    esi = eax;
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 13:
            bool_209 = true;
            bool_208 = true;
            bool_207 = true;
            bool_206 = true;
            if (edi[0x2] == 0x1) {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0xc])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x8;
                    }
            }
            else {
                    esi = 0x8002000e;
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        case 14:
            if ((0x2 & ecx) != 0x0) {
                    bool_358 = true;
                    bool_357 = true;
                    bool_356 = true;
                    bool_355 = true;
                    if (edi[0x2] == 0x1) {
                            eax = *ebx;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            esp = esp - 0x18;
                            decomp_var_64 = *var_44;
                            eax = (eax[0xb])(ebx);
                            esi = eax;
                            if (esi >= 0x0) {
                                    *(int16_t *)arg_18 = 0x8;
                            }
                    }
                    else {
                            esi = 0x8002000e;
                    }
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = esi;
            }
            else {
                    if ((ecx & 0x4) != 0x0) {
                            bool_235 = true;
                            bool_234 = true;
                            bool_233 = true;
                            if (edi[0x2] == 0x2) {
                                    eax = var_40;
                                    bool_347 = true;
                                    bool_346 = true;
                                    bool_345 = true;
                                    bool_344 = true;
                                    bool_232 = *(int16_t *)eax == 0x8;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    if (!bool_232) {
                                            esp = esp - 0x10;
                                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                            esi = eax;
                                            bool_332 = true;
                                            bool_331 = true;
                                            bool_330 = true;
                                            bool_329 = true;
                                            if (esi >= 0x0) {
                                                    eax = &var_10;
                                                    ecx = *ebx;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    esp = esp - 0x18;
                                                    decomp_var_64 = var_30;
                                                    eax = (ecx[0x1b])(ebx);
                                                    esi = eax;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                            else {
                                                    *arg_20 = 0x1;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                    }
                                    else {
                                            ecx = *ebx;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            esp = esp - 0x18;
                                            decomp_var_64 = var_30;
                                            eax = (ecx[0x1b])(ebx);
                                            esi = eax;
                                            esp = esp - 0x4;
                                            VariantClear(&var_10);
                                            eax = esi;
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = 0x8002000e;
                            }
                    }
                    else {
                            edx = 0x2;
                            if ((0x2 & ecx) != 0x0) {
                                    bool_272 = true;
                                    bool_271 = true;
                                    bool_270 = true;
                                    bool_269 = true;
                                    if (edi[0x2] == 0x1) {
                                            eax = *ebx;
                                            decomp_var_64 = *var_44;
                                            decomp_var_64 = *var_44;
                                            decomp_var_64 = *var_44;
                                            esp = esp - 0x18;
                                            decomp_var_64 = *var_44;
                                            eax = (eax[0xa])(ebx);
                                            esi = eax;
                                            if (esi >= 0x0) {
                                                    *(int16_t *)arg_18 = 0x8;
                                            }
                                    }
                                    else {
                                            esi = 0x8002000e;
                                    }
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = esi;
                            }
                            else {
                                    if ((ecx & 0x4) != 0x0) {
                                            bool_300 = true;
                                            bool_299 = true;
                                            bool_298 = true;
                                            if (edi[0x2] == edx) {
                                                    eax = var_40;
                                                    bool_304 = true;
                                                    bool_303 = true;
                                                    bool_302 = true;
                                                    bool_301 = true;
                                                    bool_297 = *(int16_t *)eax == 0x8;
                                                    var_30 = *var_44;
                                                    var_30 = *var_44;
                                                    var_30 = *var_44;
                                                    var_30 = *var_44;
                                                    if (!bool_297) {
                                                            esp = esp - 0x10;
                                                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                                            esi = eax;
                                                            bool_267 = true;
                                                            bool_266 = true;
                                                            bool_265 = true;
                                                            bool_264 = true;
                                                            if (esi < 0x0) {
                                                                    *arg_20 = 0x1;
                                                                    esp = esp - 0x4;
                                                                    VariantClear(&var_10);
                                                                    eax = esi;
                                                            }
                                                            else {
                                                                    eax = &var_10;
                                                                    ecx = *ebx;
                                                                    decomp_var_64 = var_30;
                                                                    decomp_var_64 = var_30;
                                                                    decomp_var_64 = var_30;
                                                                    esp = esp - 0x18;
                                                                    decomp_var_64 = var_30;
                                                                    eax = (ecx[0x1a])(ebx);
                                                                    esi = eax;
                                                                    esp = esp - 0x4;
                                                                    VariantClear(&var_10);
                                                                    eax = esi;
                                                            }
                                                    }
                                                    else {
                                                            ecx = *ebx;
                                                            decomp_var_64 = var_30;
                                                            decomp_var_64 = var_30;
                                                            decomp_var_64 = var_30;
                                                            esp = esp - 0x18;
                                                            decomp_var_64 = var_30;
                                                            eax = (ecx[0x1a])(ebx);
                                                            esi = eax;
                                                            esp = esp - 0x4;
                                                            VariantClear(&var_10);
                                                            eax = esi;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = 0x8002000e;
                                            }
                                    }
                                    else {
                                            bool_191 = true;
                                            bool_190 = true;
                                            bool_189 = true;
                                            bool_188 = true;
                                            if (edi[0x2] != 0x1) {
                                                    esi = 0x8002000e;
                                            }
                                            else {
                                                    eax = *ebx;
                                                    decomp_var_64 = *var_44;
                                                    decomp_var_64 = *var_44;
                                                    decomp_var_64 = *var_44;
                                                    esp = esp - 0x18;
                                                    decomp_var_64 = *var_44;
                                                    eax = (eax[0x9])(ebx);
                                                    esi = eax;
                                                    if (esi >= 0x0) {
                                                            *(int16_t *)arg_18 = 0x9;
                                                    }
                                            }
                                            esp = esp - 0x4;
                                            VariantClear(&var_10);
                                            eax = esi;
                                    }
                            }
                    }
            }
            break;
        case 15:
            if ((0x2 & ecx) != 0x0) {
                    bool_327 = true;
                    bool_326 = true;
                    bool_325 = true;
                    bool_324 = true;
                    if (edi[0x2] == 0x1) {
                            eax = *ebx;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            decomp_var_64 = *var_44;
                            esp = esp - 0x18;
                            decomp_var_64 = *var_44;
                            eax = (eax[0xa])(ebx);
                            esi = eax;
                            if (esi >= 0x0) {
                                    *(int16_t *)arg_18 = 0x8;
                            }
                    }
                    else {
                            esi = 0x8002000e;
                    }
                    esp = esp - 0x4;
                    VariantClear(&var_10);
                    eax = esi;
            }
            else {
                    if ((ecx & 0x4) != 0x0) {
                            bool_362 = true;
                            bool_361 = true;
                            bool_360 = true;
                            if (edi[0x2] == 0x2) {
                                    eax = var_40;
                                    bool_359 = *(int16_t *)eax == 0x8;
                                    bool_200 = true;
                                    bool_199 = true;
                                    bool_198 = true;
                                    bool_197 = true;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    var_30 = *var_44;
                                    if (!bool_359) {
                                            esp = esp - 0x10;
                                            eax = VariantChangeType(&var_10, eax, 0x0, 0x3);
                                            esi = eax;
                                            bool_251 = true;
                                            bool_250 = true;
                                            bool_249 = true;
                                            bool_248 = true;
                                            if (esi < 0x0) {
                                                    *arg_20 = 0x1;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                            else {
                                                    eax = &var_10;
                                                    ecx = *ebx;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    decomp_var_64 = var_30;
                                                    esp = esp - 0x18;
                                                    decomp_var_64 = var_30;
                                                    eax = (ecx[0x1a])(ebx);
                                                    esi = eax;
                                                    esp = esp - 0x4;
                                                    VariantClear(&var_10);
                                                    eax = esi;
                                            }
                                    }
                                    else {
                                            ecx = *ebx;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            decomp_var_64 = var_30;
                                            esp = esp - 0x18;
                                            decomp_var_64 = var_30;
                                            eax = (ecx[0x1a])(ebx);
                                            esi = eax;
                                            esp = esp - 0x4;
                                            VariantClear(&var_10);
                                            eax = esi;
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    VariantClear(&var_10);
                                    eax = 0x8002000e;
                            }
                    }
                    else {
                            bool_223 = true;
                            bool_222 = true;
                            bool_221 = true;
                            bool_220 = true;
                            if (edi[0x2] != 0x1) {
                                    esi = 0x8002000e;
                            }
                            else {
                                    eax = *ebx;
                                    decomp_var_64 = *var_44;
                                    decomp_var_64 = *var_44;
                                    decomp_var_64 = *var_44;
                                    esp = esp - 0x18;
                                    decomp_var_64 = *var_44;
                                    eax = (eax[0x9])(ebx);
                                    esi = eax;
                                    if (esi >= 0x0) {
                                            *(int16_t *)arg_18 = 0x9;
                                    }
                            }
                            esp = esp - 0x4;
                            VariantClear(&var_10);
                            eax = esi;
                    }
            }
            break;
        case 16:
            bool_245 = true;
            bool_244 = true;
            bool_243 = true;
            bool_242 = true;
            if (edi[0x2] != 0x1) {
                    esi = 0x8002000e;
            }
            else {
                    eax = *ebx;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    decomp_var_64 = *var_44;
                    esp = esp - 0x18;
                    decomp_var_64 = *var_44;
                    eax = (eax[0x9])(ebx);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x9;
                    }
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
        default:
            if (*(eax * 0x4 + switch_table) != 0x11) {
                    eax = *ebx;
                    esp = esp - 0x8;
                    eax = (eax[0x7])(ebx, arg_18 + 0x8);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x9;
                    }
            }
            else {
                    eax = *ebx;
                    esp = esp - 0x8;
                    eax = (eax[0x8])(ebx, arg_18 + 0x8);
                    esi = eax;
                    if (esi >= 0x0) {
                            *(int16_t *)arg_18 = 0x3;
                    }
            }
            esp = esp - 0x4;
            VariantClear(&var_10);
            eax = esi;
            break;
    }
    return eax;

.l10:
    esp = esp - 0x4;
    VariantClear(&var_10);
    eax = esi;
    return eax;

loc_471a9e:
    ecx = *(int16_t *)esi & 0xffff;
    bool_16 = true;
    bool_15 = true;
    bool_14 = true;
    bool_13 = true;
    if ((ecx & 0x4000) != 0x0 && (ecx & 0xf) != 0x0) {
            if ((ecx & 0xc) != 0x0) {
                    esp = esp - 0x4;
                    VariantClear(esi[0x2]);
                    *(int16_t *)esi[0x2] = 0x3;
                    eax = esi[0x2];
                    eax = eax + 0x8;
            }
            else {
                    eax = esi[0x2];
            }
            continue;
    }
    break;

.l16:
    esi = 0x8002000e;
    goto .l13;

.l11:
    esi = var_44;
    eax = var_10;
    goto .l20;
    *arg_20 = *arg_20 & 0x0;
    ecx = *ebx;
    decomp_var_60 = *var_34;
    decomp_var_60 = *var_34;
    decomp_var_60 = *var_34;
    esp = esp - 0x24;
    decomp_var_60 = *var_34;
    eax = (ecx[0x16])(ebx, eax, var_C, var_8, var_4);
    esi = eax;
    goto .l10;

.l13:
    esp = esp - 0x4;
    VariantClear(&var_10);
    eax = esi;
    return eax;

.l20:
    ecx = *(int16_t *)esi & 0xffff;
    bool_342 = true;
    bool_341 = true;
    bool_340 = true;
    bool_339 = true;
    if ((ecx & 0x4000) != 0x0 && (ecx & 0xf) != 0x0) {
            if ((ecx & 0xc) != 0x0) {
                    esp = esp - 0x4;
                    VariantClear(esi[0x2]);
                    *(int16_t *)esi[0x2] = 0x3;
                    eax = esi[0x2];
                    eax = eax + 0x8;
            }
            else {
                    eax = esi[0x2];
            }
            continue;
    }
    break;
    *arg_20 = *arg_20 & 0x0;
    ecx = *ebx;
    decomp_var_60 = *var_34;
    decomp_var_60 = *var_34;
    decomp_var_60 = *var_34;
    esp = esp - 0x24;
    decomp_var_60 = *var_34;
    eax = (ecx[0x16])(ebx, eax, var_C, var_8, var_4);
    esi = eax;
    goto .l13;
}
