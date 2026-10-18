// sub_480c3f @ 0x480c3f
// hopper name: sub_480c3f
// contains unmarked entry 0x481091
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480c3f() {
    ecx = arg_8;
    ebx = arg_14;
    eax = ebx[0x1];
    decomp_var_38 = esi;
    esp = esp - 0xc;
    decomp_var_3c = edi;
    decomp_var_1 = 0x0;
    if (eax <= 0x80) {
            ecx = sign_extend_32(ecx[0x8]);
    }
    else {
            ecx = ecx[0x2];
    }
    decomp_var_8 = ecx;
    if (ecx < 0xffffffff || ecx >= eax) {
            sub_4810dd();
    }
    esi = arg_4;
    if (*esi != 0xe06d7363) goto loc_480f51;
    goto loc_480c86;

loc_480f51:
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

loc_480c86:
    if (esi[0x4] != 0x3) goto .l18;
    goto loc_480c95;

.l1:
    return;

.l18:
    if (*esi != 0xe06d7363) goto loc_480f4e;
    goto loc_480dc6;

loc_480c95:
    eax = esi[0x5];
    if (eax == 0x19930520 || eax == 0x19930521 || eax == 0x19930522) goto loc_480cae;
    goto .l18;

loc_480f4e:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

loc_480dc6:
    if (esi[0x4] != 0x3) goto .l4;
    goto loc_480dd0;

loc_480cae:
    if (esi[0x7] != 0x0) goto .l18;
    goto loc_480cb8;

.l4:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

loc_480dd0:
    eax = esi[0x5];
    if (eax == 0x19930520) goto .l5;
    goto loc_480dd7;

loc_480cb8:
    if (*(sub_480086() + 0x88) == 0x0) goto .l1;
    goto loc_480cca;

.l5:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto loc_480eb5;
    goto .l6;

loc_480dd7:
    if (eax == 0x19930521) goto .l10;
    goto loc_480dde;

loc_480cca:
    esi = *(sub_480086() + 0x88);
    arg_4 = esi;
    eax = sub_480086();
    decomp_var_40 = 0x1;
    arg_c = eax[0x23];
    esp = (esp - 0x8) + 0x8;
    if (sub_48a922(esi) == 0x0) {
            sub_4810dd();
    }
    if (*esi == 0xe06d7363 && esi[0x4] == 0x3) {
            eax = esi[0x5];
            if (eax != 0x19930520 && eax != 0x19930521) {
                    if (eax == 0x19930522) {
                            if (esi[0x7] == 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (esi[0x7] == 0x0) {
                            sub_4810dd();
                    }
            }
    }
    if (*(sub_480086() + 0x94) == 0x0) goto loc_480dbe;
    goto loc_480d35;

loc_480eb5:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l6:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l51;

.l10:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l9;
    goto .l7;

loc_480dde:
    if (eax != 0x19930522) goto .l14;
    goto loc_480de9;

loc_480dbe:
    if (*esi != 0xe06d7363) goto .l34;
    goto .l37;

loc_480d35:
    edi = *(sub_480086() + 0x94);
    eax = sub_480086();
    decomp_var_40 = arg_4;
    esi = 0x0;
    eax[0x25] = 0x0;
    esp = (esp - 0x4) + 0x4;
    if (sub_480673(decomp_var_40) != 0x0) goto loc_480db6;
    goto loc_480d5a;

.l51:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l9:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l7:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l56;

.l14:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

loc_480de9:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l2;
    goto loc_480df6;

.l34:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l37:
    if (esi[0x4] != 0x3) goto .l36;
    goto .l47;

loc_480db6:
    esi = arg_4;
    goto .l18;

loc_480d5a:
    ebx = 0x0;
    if (*edi <= 0x0) {
            decomp_var_40 = 0x8;
            decomp_var_44 = 0x4c3718;
            sub_47f31c(0x4c3718, 0x8);
            eax = sub_480086();
            eax = eax[0x1e];
            if (eax == 0x0) {
                    sub_48a6f5();
            }
            (eax)(decomp_var_44, decomp_var_40);
            sub_48a6f5();
    }
    while (true) {
            esp = esp - 0x4;
            decomp_var_40 = 0x4c8fd0;
            if (sub_47a803(0x4c8fd0) != 0x0) {
                    sub_4805e7();
                    arg_4 = "bad exception";
                    eax = sub_47a696(&arg_4);
                    decomp_var_40 = 0x4c36dc;
                    esp = (esp - 0x8) + 0x8 - 0xc;
                    decomp_var_2c = 0x4b3a1c;
                    sub_47a958(&decomp_var_2c, 0x4c36dc);
                    temp_2 = 0x1;
                    break;
            }
            esi = esi + 0x1;
            ebx = ebx + 0x10;
            if (esi < *edi) {
                    continue;
            }
            temp_2 = 0x0;
            break;
    }
    if (temp_2 == 0x0) {
            decomp_var_40 = 0x8;
            decomp_var_44 = 0x4c3718;
            sub_47f31c(0x4c3718, 0x8);
            eax = sub_480086();
            eax = eax[0x1e];
            if (eax == 0x0) {
                    sub_48a6f5();
            }
            (eax)(decomp_var_44, decomp_var_40);
            sub_48a6f5();
    }
    esi = arg_4;
    if (*esi != 0xe06d7363) goto .l13;
    goto .l17;
    edi = arg_14;
    goto loc_480eb5;

.l56:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l2:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

loc_480df6:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l53;

.l36:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l47:
    eax = esi[0x5];
    if (eax == 0x19930520) goto .l48;
    goto .l50;

.l13:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l17:
    if (esi[0x4] != 0x3) goto .l16;
    goto .l28;
    edi = arg_14;
    goto .l9;

.l53:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l48:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l42;
    goto .l38;

.l50:
    if (eax == 0x19930521) goto .l49;
    goto .l32;

.l16:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l28:
    eax = esi[0x5];
    if (eax == ebx) goto .l29;
    goto .l31;
    edi = arg_14;
    goto .l2;

.l42:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l38:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l57;

.l49:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l41;
    goto .l39;

.l32:
    if (eax != 0x19930522) goto .l35;
    goto .l45;

.l29:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l23;
    goto .l19;

.l31:
    if (eax == 0x19930521) goto .l30;
    goto .l11;

.l57:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l41:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l39:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l52;

.l35:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l45:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l43;
    goto .l44;

.l23:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l19:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l58;

.l30:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l22;
    goto .l20;

.l11:
    if (eax != 0x19930522) goto .l15;
    goto .l26;
    edi = arg_14;
    goto .l42;

.l52:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l43:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l44:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l55;

.l58:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l22:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l20:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto .l54;

.l15:
    ebx = arg_14;
    if (ebx[0x3] > 0x0) {
            if (arg_18 != 0x0) {
                    decomp_var_40 = 0x8;
                    decomp_var_44 = 0x4c3718;
                    sub_47f31c(0x4c3718, 0x8);
                    eax = sub_480086();
                    eax = eax[0x1e];
                    if (eax == 0x0) {
                            sub_48a6f5();
                    }
                    (eax)(decomp_var_44, decomp_var_40);
                    sub_48a6f5();
            }
            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
            esp = (esp - 0x20) + 0x20;
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l26:
    edi = arg_14;
    if (edi[0x3] <= 0x0) goto .l24;
    goto .l25;
    edi = arg_14;
    goto .l41;

.l55:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;
    edi = arg_14;
    goto .l23;

.l54:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;

.l24:
    if (arg_18 != 0x0) {
            decomp_var_40 = 0x1;
            sub_4805e7();
            esp = (esp - 0x8) + 0x8;
    }
    if (decomp_var_1 == 0x0) {
            if ((*edi & 0x1fffffff) >= 0x19930521) {
                    if (edi[0x7] != 0x0) {
                            decomp_var_40 = esi;
                            esp = (esp - 0x4) + 0x4;
                            if (sub_480673(decomp_var_40) == 0x0) {
                                    sub_480086();
                                    sub_480086();
                                    *(sub_480086() + 0x88) = esi;
                                    *(sub_480086() + 0x8c) = arg_c;
                                    esp = esp - 0x4;
                                    decomp_var_40 = esi;
                                    if (arg_20 == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_8;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_44 = arg_20;
                                    }
                                    sub_47a9d9(decomp_var_44, decomp_var_40);
                                    esi = arg_14;
                                    sub_4804c1();
                                    esp = (esp - 0x10) + 0x10 - 0x4;
                                    decomp_var_40 = esi[0x7];
                                    sub_4806ec();
                                    ebx = arg_14;
                                    if (ebx[0x3] > 0x0) {
                                            if (arg_18 != 0x0) {
                                                    decomp_var_40 = 0x8;
                                                    decomp_var_44 = 0x4c3718;
                                                    sub_47f31c(0x4c3718, 0x8);
                                                    eax = sub_480086();
                                                    eax = eax[0x1e];
                                                    if (eax == 0x0) {
                                                            sub_48a6f5();
                                                    }
                                                    (eax)(decomp_var_44, decomp_var_40);
                                                    sub_48a6f5();
                                            }
                                            sub_480b4d(esi, arg_8, arg_c, arg_10, ebx, decomp_var_8, arg_1c, arg_20);
                                            esp = (esp - 0x20) + 0x20;
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                                    else {
                                            if (*(sub_480086() + 0x94) != 0x0) {
                                                    sub_4810dd();
                                            }
                                    }
                            }
                            else {
                                    if (*(sub_480086() + 0x94) != 0x0) {
                                            sub_4810dd();
                                    }
                            }
                    }
                    else {
                            if (*(sub_480086() + 0x94) != 0x0) {
                                    sub_4810dd();
                            }
                    }
            }
            else {
                    if (*(sub_480086() + 0x94) != 0x0) {
                            sub_4810dd();
                    }
            }
    }
    else {
            if (*(sub_480086() + 0x94) != 0x0) {
                    sub_4810dd();
            }
    }
    return;

.l25:
    decomp_var_40 = &decomp_var_1c;
    eax = sub_47ac03(edi, arg_1c, decomp_var_8, &decomp_var_10, decomp_var_40);
    esp = (esp - 0x14) + 0x14;
    edi = eax;
    goto loc_480e0f;
    edi = arg_14;
    goto .l43;
    edi = arg_14;
    goto .l22;

loc_480e0f:
    if (decomp_var_10 < decomp_var_1c) {
            eax = decomp_var_8;
            if (*edi > eax || eax > edi[0x1]) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            decomp_var_c = edi[0x4];
            eax = edi[0x3];
            decomp_var_18 = eax;
            if (eax <= 0x0) {
                    decomp_var_10 = decomp_var_10 + 0x1;
                    edi = edi + 0x14;
                    continue;
            }
            while (true) {
                    eax = esi[0x7];
                    eax = eax[0x3];
                    ebx = eax + 0x4;
                    eax = *eax;
                    decomp_var_14 = eax;
                    if (eax <= 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    while (true) {
                            decomp_var_40 = esi[0x7];
                            eax = *ebx;
                            decomp_var_20 = eax;
                            eax = sub_480421(decomp_var_c, eax, decomp_var_40);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            decomp_var_14 = decomp_var_14 - 0x1;
                            ebx = ebx + 0x4;
                            if (decomp_var_14 > eax) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            decomp_var_18 = decomp_var_18 - 0x1;
                            decomp_var_c = decomp_var_c + 0x10;
                            if (decomp_var_18 > 0x0) {
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    decomp_var_40 = arg_20;
                    decomp_var_1 = 0x1;
                    sub_480ae1(esi, arg_c, arg_10, arg_14, decomp_var_20, arg_1c, decomp_var_40);
                    esi = arg_4;
                    esp = (esp - 0x1c) + 0x1c;
            }
            decomp_var_10 = decomp_var_10 + 0x1;
            edi = edi + 0x14;
            continue;
    }
    break;
    edi = arg_14;
    goto .l24;
}
