// sub_4835c8 @ 0x4835c8
// hopper name: sub_4835c8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4835c8() {
    decomp_var_28 = esi;
    decomp_var_2c = edi;
    esp = esp - 0xc;
    var_14 = 0x3ff;
    var_4 = 0x30;
    sub_47aea2(arg_14);
    if (arg_c < 0x0) {
            arg_c = 0x0;
    }
    esi = arg_4;
    if (esi != 0x0) goto loc_483625;
    goto .l19;

loc_483625:
    if (arg_8 <= 0x0) goto loc_4835fa;
    goto loc_48362a;

.l19:
    eax = sub_47d812();
    esp = esp - 0x4;
    decomp_var_30 = 0x16;
    esi = decomp_var_30;
    *eax = esi;
    sub_47a924();
    esp = (esp + 0x4 - 0x14) + 0x14;
    if (var_18 != 0x0) {
            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
    }
    eax = esi;
    return eax;

loc_4835fa:
    eax = sub_47d812();
    esp = esp - 0x4;
    decomp_var_30 = 0x16;
    esi = decomp_var_30;
    *eax = esi;
    sub_47a924();
    esp = (esp + 0x4 - 0x14) + 0x14;
    if (var_18 != 0x0) {
            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
    }
    eax = esi;
    return eax;

loc_48362a:
    *(int8_t *)esi = 0x0;
    if (arg_8 > arg_c + 0xb) goto loc_483641;
    goto loc_483638;

loc_483641:
    edi = arg_0;
    eax = edi[0x1];
    esp = esp - 0x4;
    decomp_var_30 = ebx;
    if ((eax >> 0x14 & 0x7ff) != 0x7ff) goto loc_4836f3;
    goto loc_483663;

loc_483638:
    eax = sub_47d812();
    esp = esp - 0x4;
    decomp_var_30 = 0x22;
    esi = decomp_var_30;
    *eax = esi;
    sub_47a924();
    esp = (esp + 0x4 - 0x14) + 0x14;
    if (var_18 != 0x0) {
            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
    }
    eax = esi;
    return eax;

loc_4836f3:
    if ((0x0 | eax & 0x80000000) != 0x0) {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
    }
    *(int8_t *)esi = 0x30;
    esi[0x1] = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x78;
    esi = esi + 0x2;
    ebx = (-arg_10 - -arg_10 + CARRY(EFLAGS(cf)) & 0xffffffe0) + 0x27;
    if (arg_10 == 0x0) {
            *(int8_t *)esi = 0x30;
            esi = esi + 0x1;
            if ((*edi | edi[0x1] & 0xfffff) == 0x0) {
                    var_14 = 0x0;
            }
            else {
                    var_14 = 0x3fe;
            }
    }
    else {
            *(int8_t *)esi = 0x31;
            esi = esi + 0x1;
    }
    eax = esi;
    esi = esi + 0x1;
    arg_4 = eax;
    if (arg_c == 0x0) {
            *(int8_t *)eax = 0x0;
    }
    else {
            *(int8_t *)eax = *(int8_t *)*var_24[0x2f];
    }
    ecx = edi[0x1];
    eax = *edi;
    if ((ecx & 0xfffff) > 0x0) goto loc_48378d;
    goto loc_483785;

loc_483663:
    if (0x0 != 0x0) goto .l10;
    goto loc_48366b;

loc_48378d:
    var_C = 0x0;
    var_8 = 0xf0000;
    while (arg_c > 0x0) {
            eax = sub_48cb10();
            eax = eax + 0x30 & 0xffff;
            if (eax > 0x39) {
                    eax = eax + ebx;
            }
            ecx = var_8;
            var_4 = var_4 - 0x4;
            *(int8_t *)esi = eax;
            eax = var_C;
            asm { shrd       eax, ecx, 0x4 };
            esi = esi + 0x1;
            arg_c = arg_c - 0x1;
            var_C = eax;
            var_8 = ecx >> 0x4;
            if (var_4 < 0x0) {
                    break;
            }
    }
    if (var_4 < 0x0) goto loc_483842;
    goto loc_4837f1;

loc_483785:
    if (eax <= 0x0) goto .l7;
    goto .l3;

.l10:
    if ((0x0 | eax & 0x80000000) != 0x0) {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
    }
    *(int8_t *)esi = 0x30;
    esi[0x1] = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x78;
    esi = esi + 0x2;
    ebx = (-arg_10 - -arg_10 + CARRY(EFLAGS(cf)) & 0xffffffe0) + 0x27;
    if (arg_10 == 0x0) {
            *(int8_t *)esi = 0x30;
            esi = esi + 0x1;
            if ((*edi | edi[0x1] & 0xfffff) == 0x0) {
                    var_14 = 0x0;
            }
            else {
                    var_14 = 0x3fe;
            }
    }
    else {
            *(int8_t *)esi = 0x31;
            esi = esi + 0x1;
    }
    eax = esi;
    esi = esi + 0x1;
    arg_4 = eax;
    if (arg_c == 0x0) {
            *(int8_t *)eax = 0x0;
    }
    else {
            *(int8_t *)eax = *(int8_t *)*var_24[0x2f];
    }
    ecx = edi[0x1];
    eax = *edi;
    if ((ecx & 0xfffff) > 0x0) goto .l9;
    goto .l14;

loc_48366b:
    eax = arg_8;
    if (eax == 0xffffffff) {
            eax = eax | eax;
    }
    else {
            eax = eax - 0x2;
    }
    ebx = esi + 0x2;
    eax = sub_4835aa(edi, ebx, eax, arg_c, 0x0);
    esp = (esp - 0x14) + 0x14;
    if (eax != 0x0) {
            *(int8_t *)esi = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
    }
    else {
            if (*(int8_t *)ebx == 0x2d) {
                    *(int8_t *)esi = 0x2d;
                    esi = esi + 0x1;
            }
            *(int8_t *)esi = 0x30;
            esi[0x1] = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x78;
            eax = sub_48a7f0(esi + 0x2, 0x65);
            esp = (esp - 0x8) + 0x8;
            if (arg_10 != 0x0) {
                    *(int8_t *)eax = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
                    eax[0x3] = 0x0;
            }
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
    }
    esp = esp + 0x4;
    return eax;

loc_483842:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_13 = edx > 0x0;
    if (edx >= 0x0 && (bool_13 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_16 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_16) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ebx = 0x0;
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_20 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_20) {
                                                    if (eax >= 0x64) {
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = ebx;
                            }
                    }
                    else {
                            bool_284 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_284) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_288 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_288) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = ebx;
                                    }
                            }
                    }
                    else {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = ebx;
                    }
            }
    }
    else {
            bool_291 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_291) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_60 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_60) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

loc_4837f1:
    if (sub_48cb10() <= 0x8) goto .l6;
    goto loc_483811;

.l7:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_134 = edx > 0x0;
    if (edx >= 0x0 && (bool_134 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_137 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_137) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ebx = 0x0;
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_132 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_132) {
                                                    if (eax >= 0x64) {
                                                            ecx = 0x3e8;
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = ebx;
                            }
                    }
                    else {
                            bool_306 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_306) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_310 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_310) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = ebx;
                                    }
                            }
                    }
                    else {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = ebx;
                    }
            }
    }
    else {
            bool_313 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_313) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_122 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_122) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l3:
    var_C = 0x0;
    var_8 = 0xf0000;
    while (arg_c > 0x0) {
            eax = sub_48cb10();
            eax = eax + 0x30 & 0xffff;
            if (eax > 0x39) {
                    eax = eax + ebx;
            }
            ecx = var_8;
            var_4 = var_4 - 0x4;
            *(int8_t *)esi = eax;
            eax = var_C;
            asm { shrd       eax, ecx, 0x4 };
            esi = esi + 0x1;
            arg_c = arg_c - 0x1;
            var_C = eax;
            var_8 = ecx >> 0x4;
            if (var_4 < 0x0) {
                    break;
            }
    }
    if (var_4 < 0x0) goto .l5;
    goto .l2;

.l9:
    var_C = 0x0;
    var_8 = 0xf0000;
    while (arg_c > 0x0) {
            eax = sub_48cb10();
            eax = eax + 0x30 & 0xffff;
            if (eax > 0x39) {
                    eax = eax + ebx;
            }
            ecx = var_8;
            var_4 = var_4 - 0x4;
            *(int8_t *)esi = eax;
            eax = var_C;
            asm { shrd       eax, ecx, 0x4 };
            esi = esi + 0x1;
            arg_c = arg_c - 0x1;
            var_C = eax;
            var_8 = ecx >> 0x4;
            if (var_4 < 0x0) {
                    break;
            }
    }
    if (var_4 < 0x0) goto .l12;
    goto .l8;

.l14:
    edx = 0x0;
    if (eax <= 0x0) goto .l18;
    goto .l15;

.l6:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_40 = edx > 0x0;
    if (edx >= 0x0 && (bool_40 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_39 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_39) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ebx = 0x0;
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_38 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_38) {
                                                    if (eax >= 0x64) {
                                                            ecx = 0x3e8;
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                            }
                            else {
                                    ecx = 0x3e8;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = ebx;
                            }
                    }
                    else {
                            bool_295 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_295) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_299 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_299) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = ebx;
                                    }
                            }
                    }
                    else {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = ebx;
                    }
            }
    }
    else {
            bool_302 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_302) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_54 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_54) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

loc_483811:
    eax = esi - 0x1;
    while (true) {
            ecx = *(int8_t *)eax;
            if (ecx == 0x66) {
                    *(int8_t *)eax = 0x30;
                    eax = eax - 0x1;
                    continue;
            }
            if (ecx != 0x46) {
                    break;
            }
            *(int8_t *)eax = 0x30;
            eax = eax - 0x1;
    }
    if (eax != arg_4) {
            ecx = *(int8_t *)eax;
            if (ecx == 0x39) {
                    *(int8_t *)eax = ebx + 0x3a;
            }
            else {
                    *(int8_t *)eax = ecx + 0x1;
            }
    }
    else {
            *(int8_t *)(eax - 0x1) = *(int8_t *)(eax - 0x1) + 0x1;
    }
    goto loc_483842;

.l5:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_105 = edx > 0x0;
    if (edx >= 0x0 && (bool_105 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_94 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_94) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ebx = 0x0;
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_95 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_95) {
                                                    if (eax >= 0x64) {
                                                            ecx = 0x3e8;
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = ebx;
                                                    }
                                            }
                                            else {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                            }
                            else {
                                    ecx = 0x3e8;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = ebx;
                            }
                    }
                    else {
                            bool_317 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_317) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_321 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_321) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = ebx;
                                    }
                            }
                    }
                    else {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = ebx;
                    }
            }
    }
    else {
            bool_324 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_324) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_108 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_108) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l2:
    if (sub_48cb10() <= 0x8) goto .l4;
    goto loc_483811;

.l12:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_181 = edx > 0x0;
    if (edx >= 0x0 && (bool_181 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_180 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_180) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ebx = 0x0;
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_179 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_179) {
                                                    if (eax >= 0x64) {
                                                            ecx = 0x3e8;
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                            }
                            else {
                                    ecx = 0x3e8;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = ebx;
                            }
                    }
                    else {
                            bool_339 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_339) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x0;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x0;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_179 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_179) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = ebx;
                                    }
                            }
                    }
                    else {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = ebx;
                    }
            }
    }
    else {
            bool_339 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_339) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_195 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_195) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l8:
    if (sub_48cb10() <= 0x8) goto .l11;
    goto loc_483811;

.l18:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_258 = edx > 0x0;
    if (edx >= 0x0 && (bool_258 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_264 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_264) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_262 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_262) {
                                                    if (eax >= 0x64) {
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            bool_262 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_262) {
                                            if (eax >= 0x64) {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_262 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_262) {
                                            if (eax >= 0x64) {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    else {
            bool_262 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_262) {
                            if (eax >= 0x64) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_256 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_256) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l15:
    var_C = edx;
    var_8 = 0xf0000;
    while (arg_c > 0x0) {
            eax = sub_48cb10();
            eax = eax + 0x30 & 0xffff;
            if (eax > 0x39) {
                    eax = eax + ebx;
            }
            ecx = var_8;
            var_4 = var_4 - 0x4;
            *(int8_t *)esi = eax;
            eax = var_C;
            asm { shrd       eax, ecx, 0x4 };
            esi = esi + 0x1;
            arg_c = arg_c - 0x1;
            var_C = eax;
            var_8 = ecx >> 0x4;
            if (var_4 < 0x0) {
                    break;
            }
    }
    if (var_4 < 0x0) goto .l17;
    goto .l13;

.l4:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_78 = edx > 0x0;
    if (edx >= 0x0 && (bool_78 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_87 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_87) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    edx = 0x0;
                                    bool_77 = 0x0 > 0x0;
                                    if (0x0 >= 0x0) {
                                            if (!bool_77) {
                                                    if (eax >= 0x64) {
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, 0x0, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            bool_328 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_328) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_332 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_332) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x3e8;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = ebx;
                                            }
                                    }
                                    else {
                                            ecx = 0x3e8;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = ebx;
                                    }
                            }
                    }
                    else {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = ebx;
                    }
            }
    }
    else {
            bool_335 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_335) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_73 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_73) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l11:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_172 = edx > 0x0;
    if (edx >= 0x0 && (bool_172 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_166 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_166) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_169 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_169) {
                                                    if (eax >= 0x64) {
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            bool_169 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_169) {
                                            if (eax >= 0x64) {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_169 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_169) {
                                            if (eax >= 0x64) {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    else {
            bool_169 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_169) {
                            if (eax >= 0x64) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_154 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_154) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l17:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_229 = edx > 0x0;
    if (edx >= 0x0 && (bool_229 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_236 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_236) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_239 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_239) {
                                                    if (eax >= 0x64) {
                                                            ecx = 0x0;
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    ecx = 0x0;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                            }
                            else {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            bool_239 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_239) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x0;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x0;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_239 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_239) {
                                            if (eax >= 0x64) {
                                                    ecx = 0x0;
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            ecx = 0x0;
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    else {
            bool_239 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_239) {
                            if (eax >= 0x64) {
                                    ecx = 0x0;
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            ecx = 0x0;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_224 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_224) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;

.l13:
    if (sub_48cb10() <= 0x8) goto .l16;
    goto loc_483811;

.l16:
    if (arg_c > 0x0) {
            sub_47ba40(esi, 0x30, arg_c);
            esp = (esp - 0xc) + 0xc;
            esi = esi + arg_c;
    }
    eax = arg_4;
    if (*(int8_t *)eax == 0x0) {
            esi = eax;
    }
    *(int8_t *)esi = ((arg_10 == 0x0 ? 0x1 : 0x0) - 0x1 & 0xe0) + 0x70;
    esi = esi + 0x1;
    eax = sub_48cb10();
    eax = (eax & 0x7ff) - var_14;
    ecx = 0x0;
    esp = (esp - 0x4) + 0x4;
    edx = (edx & 0x0) - 0x0 + CARRY(EFLAGS(cf));
    bool_217 = edx > 0x0;
    if (edx >= 0x0 && (bool_217 || eax >= 0x0)) {
            *(int8_t *)esi = 0x2b;
            esi = esi + 0x1;
    }
    else {
            *(int8_t *)esi = 0x2d;
            esi = esi + 0x1;
            eax = -eax;
            edx = -(edx + 0x0 + CARRY(EFLAGS(cf)));
    }
    bool_207 = edx > 0x0;
    edi = esi;
    *(int8_t *)esi = 0x30;
    if (edx >= 0x0) {
            if (!bool_207) {
                    ecx = 0x3e8;
                    if (eax >= 0x3e8) {
                            ecx = 0x3e8;
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                            if (esi == edi) {
                                    bool_202 = edx > 0x0;
                                    if (edx >= 0x0) {
                                            if (!bool_202) {
                                                    if (eax >= 0x64) {
                                                            esp = esp - 0x10;
                                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                            esi = esi + 0x1;
                                                            eax = ecx;
                                                            edx = 0x0;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            bool_202 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_202) {
                                            if (eax >= 0x64) {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
            }
            else {
                    ecx = 0x3e8;
                    esp = esp - 0x10;
                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x3e8, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                    esi = esi + 0x1;
                    eax = ecx;
                    edx = 0x0;
                    if (esi == edi) {
                            bool_202 = edx > 0x0;
                            if (edx >= 0x0) {
                                    if (!bool_202) {
                                            if (eax >= 0x64) {
                                                    esp = esp - 0x10;
                                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                                    esi = esi + 0x1;
                                                    eax = ecx;
                                                    edx = 0x0;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                            esi = esi + 0x1;
                                            eax = ecx;
                                            edx = 0x0;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    else {
            bool_202 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_202) {
                            if (eax >= 0x64) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    edx = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0x64, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            edx = 0x0;
                    }
            }
    }
    if (esi == edi) {
            bool_219 = edx > 0x0;
            if (edx >= 0x0) {
                    if (!bool_219) {
                            if (eax >= 0xa) {
                                    esp = esp - 0x10;
                                    *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                                    esi = esi + 0x1;
                                    eax = ecx;
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    *(int8_t *)esi = eax + 0x30;
                                    esi[0x1] = 0x0;
                                    if (var_18 != 0x0) {
                                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
                            esi = esi + 0x1;
                            eax = ecx;
                            *(int8_t *)esi = eax + 0x30;
                            esi[0x1] = 0x0;
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
            else {
                    *(int8_t *)esi = eax + 0x30;
                    esi[0x1] = 0x0;
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp - 0x10;
            *(int8_t *)esi = sub_48ca30(eax, edx, 0xa, 0x0, decomp_var_30, decomp_var_2c) + 0x30;
            esi = esi + 0x1;
            eax = ecx;
            *(int8_t *)esi = eax + 0x30;
            esi[0x1] = 0x0;
            if (var_18 != 0x0) {
                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
            esp = esp + 0x4;
    }
    return eax;
}
