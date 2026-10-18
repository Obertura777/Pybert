// sub_48730d @ 0x48730d
// hopper name: sub_48730d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48730d() {
    ebp = &var_51C;
    arg_510 = *dword_4c8db8 ^ ebp;
    eax = arg_520;
    esp = esp - 0x598;
    decomp_var_59c = esi;
    decomp_var_64 = eax;
    decomp_var_60 = 0x0;
    decomp_var_68 = 0x0;
    if (arg_524 != 0x0) goto loc_487349;
    goto loc_4878bd;

loc_487349:
    if (eax != 0x0) goto loc_487374;
    goto loc_48734d;

loc_4878bd:
    eax = sub_47ad69();
    return eax;

loc_487374:
    esi = arg_51c;
    decomp_var_5a0 = ebx;
    ebx = (esi & 0x1f) * 0x28;
    esp = esp - 0x8;
    decomp_var_5a4 = edi;
    edi = (SAR(esi, 0x5)) * 0x4 + dword_bc7240;
    eax = *edi;
    eax = eax + ebx;
    ecx = eax[0x24];
    ecx = SAR(ecx + ecx, 0x1);
    decomp_var_70 = edi;
    decomp_var_55 = ecx;
    if (ecx == 0x2 || ecx == 0x1) goto loc_4873ab;
    goto .l234;

loc_48734d:
    *sub_47d825() = 0x0;
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = (esp - 0x14) + 0x14;
    goto loc_4878bd;

loc_4873ab:
    if ((!arg_524 & 0x1) != 0x0) goto loc_4873de;
    goto loc_4873b8;

.l234:
    if ((eax[0x4] & 0x20) != 0x0) {
            sub_48df70(esi, 0x0, 0x0, 0x2);
            esp = (esp - 0x10) + 0x10;
    }
    esp = (esp - 0x4) + 0x4;
    if (sub_48e150(esi) == 0x0) goto .l232;
    goto .l358;

loc_4873de:
    if ((eax[0x4] & 0x20) != 0x0) {
            sub_48df70(esi, 0x0, 0x0, 0x2);
            esp = (esp - 0x10) + 0x10;
    }
    esp = (esp - 0x4) + 0x4;
    if (sub_48e150(esi) == 0x0) goto loc_4875f8;
    goto loc_487402;

loc_4873b8:
    *sub_47d825() = 0x0;
    *sub_47d812() = 0x16;
    eax = sub_47a924();
    esp = (esp - 0x14) + 0x14;
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l232:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l374;
    goto .l237;

.l358:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x80) == 0x0) goto .l308;
    goto .l244;

loc_4875f8:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto loc_48782b;
    goto loc_487606;

loc_487402:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x80) == 0x0) goto .l29;
    goto loc_48740f;

.l374:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l369;
    goto .l367;

.l237:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l191;
    goto .l233;

.l308:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l214;
    goto .l394;

.l244:
    eax = sub_480086();
    eax = eax[0x1b];
    bool_206 = eax[0x5] == 0x0;
    bool_205 = eax[0x5] == 0x0;
    esp = esp - 0x8;
    esi = bool_206 ? 0x1 : 0x0;
    GetConsoleMode(*(ebx + *edi), &decomp_var_7c);
    if (bool_205) goto .l322;
    goto .l377;

loc_48782b:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax == 0x0) {
            edi = decomp_var_70;
            if (decomp_var_54 != 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    if (decomp_var_54 == 0x5) {
                            *sub_47d812() = 0x9;
                            eax = sub_47d825();
                            *eax = 0x5;
                    }
                    else {
                            eax = sub_47d838(decomp_var_54);
                            esp = (esp - 0x4) + 0x4;
                    }
            }
            else {
                    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
                            *sub_47d812() = 0x1c;
                            eax = sub_47d825();
                            *eax = 0x0;
                    }
            }
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

loc_487606:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto loc_4876a9;
    goto loc_487618;

.l29:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l134;
    goto .l67;

loc_48740f:
    eax = sub_480086();
    eax = eax[0x1b];
    bool_103 = eax[0x5] == 0x0;
    bool_102 = eax[0x5] == 0x0;
    esp = esp - 0x8;
    esi = bool_103 ? 0x1 : 0x0;
    GetConsoleMode(*(ebx + *edi), &decomp_var_7c);
    if (bool_102) goto .l110;
    goto loc_487438;

.l369:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l367:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l366;
    goto .l373;

.l191:
    if (decomp_var_55 != 0x2) goto .l347;
    goto .l197;

.l233:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l203;
    goto .l417;

.l214:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l209;
    goto .l207;

.l394:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l255;
    goto .l396;

.l322:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l348;
    goto .l316;

.l377:
    if (esi == 0x0) goto .l387;
    goto .l379;

loc_4876a9:
    if (decomp_var_55 != 0x2) goto loc_487750;
    goto loc_4876b3;

loc_487618:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l2;
    goto .l402;

.l134:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l129;
    goto .l127;

.l67:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l27;
    goto .l64;

.l110:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l73;
    goto .l104;

loc_487438:
    if (esi == 0x0) goto .l179;
    goto loc_48743c;

.l366:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l372;
    goto .l369;

.l373:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l368;
    goto .l371;

.l347:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l201;
    goto .l419;

.l197:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l202;
    goto .l416;

.l203:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l417:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l375;
    goto .l229;

.l209:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l207:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l206;
    goto .l213;

.l255:
    if (decomp_var_55 != 0x2) goto .l333;
    goto .l261;

.l396:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l302;
    goto .l400;

.l348:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l338;
    goto .l336;

.l316:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l267;
    goto .l245;

.l387:
    eax = GetConsoleCP();
    decomp_var_50 = decomp_var_50 & 0x0;
    esi = decomp_var_64;
    decomp_var_7c = eax;
    decomp_var_74 = esi;
    if (arg_524 <= 0x0) goto .l290;
    goto .l284;

.l379:
    if (decomp_var_55 == 0x0) goto .l278;
    goto .l283;

loc_487750:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto loc_48788c;
    goto .l401;

loc_4876b3:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l22;
    goto .l409;

.l2:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l402:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto loc_4878b8;
    goto loc_487862;

.l129:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l127:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l126;
    goto .l133;

.l27:
    if (decomp_var_55 != 0x2) goto .l121;
    goto .l35;

.l64:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l41;
    goto .l411;

.l73:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l155;
    goto .l153;

.l104:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l160;
    goto .l98;

.l179:
    eax = GetConsoleCP();
    decomp_var_50 = decomp_var_50 & 0x0;
    esi = decomp_var_64;
    decomp_var_7c = eax;
    decomp_var_74 = esi;
    if (arg_524 <= 0x0) goto loc_487865;
    goto .l83;

loc_48743c:
    if (decomp_var_55 == 0x0) goto .l30;
    goto loc_487446;

.l372:
    *sub_47d812() = 0x1c;
    goto .l370;

.l368:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l369;

.l371:
    *sub_47d812() = 0x9;
    goto .l370;

.l201:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l419:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l198;
    goto .l195;

.l202:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l416:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l185;
    goto .l199;

.l375:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l229:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l204;
    goto .l238;

.l206:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l212;
    goto .l209;

.l213:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l208;
    goto .l211;

.l333:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l265;
    goto .l418;

.l261:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l301;
    goto .l415;

.l302:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l400:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l215;
    goto .l357;

.l338:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l336:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l335;
    goto .l353;

.l267:
    if (decomp_var_55 != 0x2) goto .l269;
    goto .l247;

.l245:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l317;
    goto .l404;

.l290:
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l280;
    goto .l288;

.l284:
    decomp_var_5c = decomp_var_5c & 0x0;
    goto loc_48746f;

.l278:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l227;
    goto .l385;

.l283:
    eax = GetConsoleCP();
    decomp_var_50 = decomp_var_50 & 0x0;
    esi = decomp_var_64;
    decomp_var_7c = eax;
    decomp_var_74 = esi;
    if (arg_524 <= 0x0) goto .l222;
    goto .l293;

loc_48788c:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l401:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto loc_4878bb;
    goto .l6;

.l22:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l409:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l14;
    goto .l12;

loc_4878b8:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

loc_487862:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l21;
    goto loc_48786c;

.l126:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l132;
    goto .l129;

.l133:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l128;
    goto .l131;

.l121:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l39;
    goto .l412;

.l35:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l40;
    goto .l423;

.l41:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l411:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l135;
    goto .l61;

.l155:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l153:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l152;
    goto .l72;

.l160:
    if (decomp_var_55 != 0x2) goto .l162;
    goto .l99;

.l98:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l105;
    goto loc_487627;

loc_487865:
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l86;
    goto .l92;

.l83:
    decomp_var_5c = decomp_var_5c & 0x0;
    goto .l426;

.l30:
    eax = *edi;
    eax = eax + ebx;
    if ((eax[0x4] & 0x80) == 0x0) goto .l147;
    goto .l177;

loc_487446:
    eax = GetConsoleCP();
    decomp_var_50 = decomp_var_50 & 0x0;
    esi = decomp_var_64;
    decomp_var_7c = eax;
    decomp_var_74 = esi;
    if (arg_524 <= 0x0) goto .l142;
    goto loc_487466;

.l370:
    eax = sub_47d825();
    *eax = esi;
    goto .l369;

.l198:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l195:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l194;
    goto .l190;

.l185:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l199:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l200;
    goto .l189;

.l204:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l236;
    goto .l205;

.l238:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l230;
    goto .l235;

.l212:
    *sub_47d812() = 0x1c;
    goto .l210;

.l208:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l209;

.l211:
    *sub_47d812() = 0x9;
    goto .l210;

.l265:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l418:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l262;
    goto .l259;

.l301:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l415:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l249;
    goto .l263;

.l215:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l357:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l313;
    goto .l395;

.l335:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l352;
    goto .l338;

.l353:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l337;
    goto .l351;

.l269:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l315;
    goto .l420;

.l247:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l241;
    goto .l408;

.l317:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l404:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l350;
    goto .l243;

.l280:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l291;
    goto .l296;

.l288:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l286;
    goto .l292;

loc_48746f:
    eax = decomp_var_55;
    if (eax == 0x0) {
            eax = *(int8_t *)esi;
            bool_386 = eax != 0xa;
            decomp_var_78 = eax == 0xa ? 0x1 : 0x0;
            sub_487c6d(sign_extend_32(eax));
            esp = (esp - 0x4) + 0x4;
            if (!bool_386) {
                    eax = sub_48f457(&decomp_var_54, esi, 0x1);
                    esp = (esp - 0xc) + 0xc;
                    if (eax != 0xffffffff) {
                            esp = esp - 0x20;
                            decomp_var_5c = decomp_var_5c + 0x1;
                            decomp_var_74 = esi + 0x1;
                            eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                            esi = eax;
                            if (esi != 0x0) {
                                    esp = esp - 0x14;
                                    eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                    if (eax != 0x0) {
                                            decomp_var_60 = decomp_var_60 + decomp_var_50;
                                            if (decomp_var_50 >= esi) {
                                                    if (decomp_var_78 != 0x0) {
                                                            arg_508 = 0xd;
                                                            esp = esp - 0x14;
                                                            eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                            if (eax != 0x0) {
                                                                    if (decomp_var_50 >= 0x1) {
                                                                            decomp_var_68 = decomp_var_68 + 0x1;
                                                                            decomp_var_60 = decomp_var_60 + 0x1;
                                                                            if (decomp_var_5c < arg_524) {
                                                                                    esi = decomp_var_74;
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_1 = 0x4;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (decomp_var_5c < arg_524) {
                                                                    esi = decomp_var_74;
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x8;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x4;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x7;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x7;
                            break;
                    }
            }
            else {
                    if ((decomp_var_64 - esi) + arg_524 > 0x1) {
                            eax = sub_48f457(&decomp_var_54, esi, 0x2);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0xffffffff) {
                                    esi = esi + 0x1;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    esp = esp - 0x20;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    decomp_var_74 = esi + 0x1;
                                    eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                                    esi = eax;
                                    if (esi != 0x0) {
                                            esp = esp - 0x14;
                                            eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                            if (eax != 0x0) {
                                                    decomp_var_60 = decomp_var_60 + decomp_var_50;
                                                    if (decomp_var_50 >= esi) {
                                                            if (decomp_var_78 != 0x0) {
                                                                    arg_508 = 0xd;
                                                                    esp = esp - 0x14;
                                                                    eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                                    if (eax != 0x0) {
                                                                            if (decomp_var_50 >= 0x1) {
                                                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                                                    if (decomp_var_5c < arg_524) {
                                                                                            esi = decomp_var_74;
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x4;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (decomp_var_5c < arg_524) {
                                                                            esi = decomp_var_74;
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_1 = 0x8;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x4;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x7;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x3;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x2;
                            break;
                    }
            }
    }
    else {
            if (eax == 0x1 || eax == 0x2) {
                    ecx = *(int16_t *)esi & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    decomp_var_54 = ecx;
                    decomp_var_74 = esi + 0x2;
                    decomp_var_78 = ecx == 0xa ? 0x1 : 0x0;
            }
            if (eax != 0x1) {
                    if (eax == 0x2) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_48f282(decomp_var_54) == decomp_var_54) {
                                    decomp_var_60 = decomp_var_60 + 0x1;
                                    if (decomp_var_78 != 0x0) {
                                            decomp_var_54 = 0xd;
                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                            if (sub_48f282(0xd) == 0xd) {
                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                    if (decomp_var_5c < arg_524) {
                                                            esi = decomp_var_74;
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x6;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x5;
                                    break;
                            }
                    }
                    else {
                            if (decomp_var_5c < arg_524) {
                                    esi = decomp_var_74;
                                    continue;
                            }
                            temp_1 = 0x1;
                            break;
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_48f282(decomp_var_54) == decomp_var_54) {
                            decomp_var_60 = decomp_var_60 + 0x1;
                            if (decomp_var_78 != 0x0) {
                                    decomp_var_54 = 0xd;
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    if (sub_48f282(0xd) == 0xd) {
                                            decomp_var_60 = decomp_var_60 + 0x1;
                                            decomp_var_68 = decomp_var_68 + 0x1;
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x6;
                                            break;
                                    }
                            }
                            else {
                                    if (decomp_var_5c < arg_524) {
                                            esi = decomp_var_74;
                                            continue;
                                    }
                                    temp_1 = 0x1;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x5;
                            break;
                    }
            }
    }
    goto .l406;

.l227:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l361;
    goto .l359;

.l385:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l300;
    goto .l382;

.l222:
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l325;
    goto .l218;

.l293:
    decomp_var_5c = decomp_var_5c & 0x0;
    goto .l422;

loc_4878bb:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l6:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l8;
    goto .l7;

.l14:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l12:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l11;
    goto .l18;

.l21:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto loc_4878a1;
    goto .l4;

loc_48786c:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto loc_487881;
    goto loc_487874;

.l132:
    *sub_47d812() = 0x1c;
    goto .l130;

.l128:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l129;

.l131:
    *sub_47d812() = 0x9;
    goto .l130;

.l39:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l412:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l36;
    goto .l33;

.l40:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l423:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l19;
    goto .l37;

.l135:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l61:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l42;
    goto .l68;

.l152:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l71;
    goto .l155;

.l72:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l154;
    goto .l70;

.l162:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l103;
    goto .l424;

.l99:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l100;
    goto .l407;

.l105:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

loc_487627:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l74;
    goto .l96;

.l86:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l91;
    goto .l87;

.l92:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l88;
    goto .l90;

.l426:
    eax = decomp_var_55;
    if (eax == 0x0) {
            eax = *(int8_t *)esi;
            bool_624 = eax != 0xa;
            decomp_var_78 = eax == 0xa ? 0x1 : 0x0;
            sub_487c6d(sign_extend_32(eax));
            esp = (esp - 0x4) + 0x4;
            if (!bool_624) {
                    eax = sub_48f457(&decomp_var_54, esi, 0x1);
                    esp = (esp - 0xc) + 0xc;
                    if (eax != 0xffffffff) {
                            esp = esp - 0x20;
                            decomp_var_5c = decomp_var_5c + 0x1;
                            decomp_var_74 = esi + 0x1;
                            eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                            esi = eax;
                            if (esi != 0x0) {
                                    esp = esp - 0x14;
                                    eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                    if (eax != 0x0) {
                                            decomp_var_60 = decomp_var_60 + decomp_var_50;
                                            if (decomp_var_50 >= esi) {
                                                    if (decomp_var_78 != 0x0) {
                                                            arg_508 = 0xd;
                                                            esp = esp - 0x14;
                                                            eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                            if (eax != 0x0) {
                                                                    if (decomp_var_50 >= 0x1) {
                                                                            decomp_var_68 = decomp_var_68 + 0x1;
                                                                            decomp_var_60 = decomp_var_60 + 0x1;
                                                                            if (decomp_var_5c < arg_524) {
                                                                                    esi = decomp_var_74;
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_1 = 0x4;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (decomp_var_5c < arg_524) {
                                                                    esi = decomp_var_74;
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x8;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x4;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x7;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x7;
                            break;
                    }
            }
            else {
                    if ((decomp_var_64 - esi) + arg_524 > 0x1) {
                            eax = sub_48f457(&decomp_var_54, esi, 0x2);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0xffffffff) {
                                    esi = esi + 0x1;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    esp = esp - 0x20;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    decomp_var_74 = esi + 0x1;
                                    eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                                    esi = eax;
                                    if (esi != 0x0) {
                                            esp = esp - 0x14;
                                            eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                            if (eax != 0x0) {
                                                    decomp_var_60 = decomp_var_60 + decomp_var_50;
                                                    if (decomp_var_50 >= esi) {
                                                            if (decomp_var_78 != 0x0) {
                                                                    arg_508 = 0xd;
                                                                    esp = esp - 0x14;
                                                                    eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                                    if (eax != 0x0) {
                                                                            if (decomp_var_50 >= 0x1) {
                                                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                                                    if (decomp_var_5c < arg_524) {
                                                                                            esi = decomp_var_74;
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x4;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (decomp_var_5c < arg_524) {
                                                                            esi = decomp_var_74;
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_1 = 0x8;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x4;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x7;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x3;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x2;
                            break;
                    }
            }
    }
    else {
            if (eax == 0x1 || eax == 0x2) {
                    ecx = *(int16_t *)esi & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    decomp_var_54 = ecx;
                    decomp_var_74 = esi + 0x2;
                    decomp_var_78 = ecx == 0xa ? 0x1 : 0x0;
            }
            if (eax != 0x1) {
                    if (eax == 0x2) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_48f282(decomp_var_54) == decomp_var_54) {
                                    decomp_var_60 = decomp_var_60 + 0x1;
                                    if (decomp_var_78 != 0x0) {
                                            decomp_var_54 = 0xd;
                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                            if (sub_48f282(0xd) == 0xd) {
                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                    if (decomp_var_5c < arg_524) {
                                                            esi = decomp_var_74;
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x6;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x5;
                                    break;
                            }
                    }
                    else {
                            if (decomp_var_5c < arg_524) {
                                    esi = decomp_var_74;
                                    continue;
                            }
                            temp_1 = 0x1;
                            break;
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_48f282(decomp_var_54) == decomp_var_54) {
                            decomp_var_60 = decomp_var_60 + 0x1;
                            if (decomp_var_78 != 0x0) {
                                    decomp_var_54 = 0xd;
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    if (sub_48f282(0xd) == 0xd) {
                                            decomp_var_60 = decomp_var_60 + 0x1;
                                            decomp_var_68 = decomp_var_68 + 0x1;
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x6;
                                            break;
                                    }
                            }
                            else {
                                    if (decomp_var_5c < arg_524) {
                                            esi = decomp_var_74;
                                            continue;
                                    }
                                    temp_1 = 0x1;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x5;
                            break;
                    }
            }
    }
    goto .l427;

.l147:
    esp = esp - 0x14;
    eax = WriteFile(*eax, decomp_var_64, arg_524, &decomp_var_6c, 0x0);
    if (eax != 0x0) {
            decomp_var_54 = decomp_var_54 & 0x0;
            decomp_var_60 = decomp_var_6c;
    }
    else {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l59;
    goto .l57;

.l177:
    eax = decomp_var_64;
    decomp_var_54 = 0x0;
    if (decomp_var_55 != 0x0) goto .l50;
    goto .l174;

.l142:
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l113;
    goto .l138;

loc_487466:
    decomp_var_5c = decomp_var_5c & 0x0;
    goto .l414;

.l194:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l346;
    goto .l198;

.l190:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l186;
    goto .l188;

.l200:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l193;
    goto .l185;

.l189:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l192;
    goto .l187;

.l236:
    *sub_47d812() = 0x1c;
    goto .l231;

.l205:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l230:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l205;

.l235:
    *sub_47d812() = 0x9;
    goto .l231;

.l210:
    eax = sub_47d825();
    *eax = esi;
    goto .l209;

.l262:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l259:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l258;
    goto .l254;

.l249:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l263:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l264;
    goto .l253;

.l313:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l393;
    goto .l305;

.l395:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l356;
    goto .l398;

.l352:
    *sub_47d812() = 0x1c;
    goto .l339;

.l337:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l338;

.l351:
    *sub_47d812() = 0x9;
    goto .l339;

.l315:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l420:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l242;
    goto .l340;

.l241:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l408:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l326;
    goto .l248;

.l350:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l243:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l240;
    goto .l239;

.l291:
    *sub_47d812() = 0x1c;
    goto .l282;

.l296:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l286:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l296;

.l292:
    *sub_47d812() = 0x9;
    goto .l282;

.l406:
    if (temp_1 != 0x0 && temp_1 != 0x1) {
            if (temp_1 != 0x2 && temp_1 != 0x3) {
                    switch (temp_1) {
                        case 4:
                            decomp_var_54 = GetLastError();
                            break;
                        case 5:
                            decomp_var_54 = GetLastError();
                            break;
                        case 6:
                            decomp_var_54 = GetLastError();
                            break;
                        case 7:
                            break;
                    }
            }
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l285;
    goto .l388;

.l361:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l359:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l397;
    goto .l226;

.l300:
    if (decomp_var_55 != 0x2) goto .l279;
    goto .l364;

.l382:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l275;
    goto .l410;

.l325:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l223;
    goto .l321;

.l218:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l217;
    goto .l216;

.l422:
    eax = decomp_var_55;
    if (eax == 0x0) {
            eax = *(int8_t *)esi;
            bool_565 = eax != 0xa;
            decomp_var_78 = eax == 0xa ? 0x1 : 0x0;
            sub_487c6d(sign_extend_32(eax));
            esp = (esp - 0x4) + 0x4;
            if (!bool_565) {
                    eax = sub_48f457(&decomp_var_54, esi, 0x1);
                    esp = (esp - 0xc) + 0xc;
                    if (eax != 0xffffffff) {
                            esp = esp - 0x20;
                            decomp_var_5c = decomp_var_5c + 0x1;
                            decomp_var_74 = esi + 0x1;
                            eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                            esi = eax;
                            if (esi != 0x0) {
                                    esp = esp - 0x14;
                                    eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                    if (eax != 0x0) {
                                            decomp_var_60 = decomp_var_60 + decomp_var_50;
                                            if (decomp_var_50 >= esi) {
                                                    if (decomp_var_78 != 0x0) {
                                                            arg_508 = 0xd;
                                                            esp = esp - 0x14;
                                                            eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                            if (eax != 0x0) {
                                                                    if (decomp_var_50 >= 0x1) {
                                                                            decomp_var_68 = decomp_var_68 + 0x1;
                                                                            decomp_var_60 = decomp_var_60 + 0x1;
                                                                            if (decomp_var_5c < arg_524) {
                                                                                    esi = decomp_var_74;
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_1 = 0x4;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (decomp_var_5c < arg_524) {
                                                                    esi = decomp_var_74;
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x8;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x4;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x7;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x7;
                            break;
                    }
            }
            else {
                    if ((decomp_var_64 - esi) + arg_524 > 0x1) {
                            eax = sub_48f457(&decomp_var_54, esi, 0x2);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0xffffffff) {
                                    esi = esi + 0x1;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    esp = esp - 0x20;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    decomp_var_74 = esi + 0x1;
                                    eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                                    esi = eax;
                                    if (esi != 0x0) {
                                            esp = esp - 0x14;
                                            eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                            if (eax != 0x0) {
                                                    decomp_var_60 = decomp_var_60 + decomp_var_50;
                                                    if (decomp_var_50 >= esi) {
                                                            if (decomp_var_78 != 0x0) {
                                                                    arg_508 = 0xd;
                                                                    esp = esp - 0x14;
                                                                    eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                                    if (eax != 0x0) {
                                                                            if (decomp_var_50 >= 0x1) {
                                                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                                                    if (decomp_var_5c < arg_524) {
                                                                                            esi = decomp_var_74;
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x4;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (decomp_var_5c < arg_524) {
                                                                            esi = decomp_var_74;
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_1 = 0x8;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x4;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x7;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x3;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x2;
                            break;
                    }
            }
    }
    else {
            if (eax == 0x1 || eax == 0x2) {
                    ecx = *(int16_t *)esi & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    decomp_var_54 = ecx;
                    decomp_var_74 = esi + 0x2;
                    decomp_var_78 = ecx == 0xa ? 0x1 : 0x0;
            }
            if (eax != 0x1) {
                    if (eax == 0x2) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_48f282(decomp_var_54) == decomp_var_54) {
                                    decomp_var_60 = decomp_var_60 + 0x1;
                                    if (decomp_var_78 != 0x0) {
                                            decomp_var_54 = 0xd;
                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                            if (sub_48f282(0xd) == 0xd) {
                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                    if (decomp_var_5c < arg_524) {
                                                            esi = decomp_var_74;
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x6;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x5;
                                    break;
                            }
                    }
                    else {
                            if (decomp_var_5c < arg_524) {
                                    esi = decomp_var_74;
                                    continue;
                            }
                            temp_1 = 0x1;
                            break;
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_48f282(decomp_var_54) == decomp_var_54) {
                            decomp_var_60 = decomp_var_60 + 0x1;
                            if (decomp_var_78 != 0x0) {
                                    decomp_var_54 = 0xd;
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    if (sub_48f282(0xd) == 0xd) {
                                            decomp_var_60 = decomp_var_60 + 0x1;
                                            decomp_var_68 = decomp_var_68 + 0x1;
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x6;
                                            break;
                                    }
                            }
                            else {
                                    if (decomp_var_5c < arg_524) {
                                            esi = decomp_var_74;
                                            continue;
                                    }
                                    temp_1 = 0x1;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x5;
                            break;
                    }
            }
    }
    goto .l421;

.l8:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l3;
    goto loc_4878bb;

.l7:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l10;
    goto .l9;

.l11:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l17;
    goto .l14;

.l18:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l13;
    goto .l16;

loc_4878a1:
    *sub_47d812() = 0x1c;
    goto loc_4878ac;

.l4:
    esp = esp + 0x8;
    goto loc_4878bd;

loc_487881:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l4;

loc_487874:
    *sub_47d812() = 0x9;
    goto loc_4878ac;

.l130:
    eax = sub_47d825();
    *eax = esi;
    goto .l129;

.l36:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l33:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l32;
    goto .l26;

.l19:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l37:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l38;
    goto .l25;

.l42:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l66;
    goto .l43;

.l68:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l62;
    goto .l65;

.l71:
    *sub_47d812() = 0x1c;
    goto .l156;

.l154:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l155;

.l70:
    *sub_47d812() = 0x9;
    goto .l156;

.l103:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l424:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l97;
    goto .l157;

.l100:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l407:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l114;
    goto .l93;

.l74:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l96:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l94;
    goto .l101;

.l91:
    *sub_47d812() = 0x1c;
    goto .l89;

.l87:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l88:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l87;

.l90:
    *sub_47d812() = 0x9;
    goto .l89;

.l427:
    if (temp_1 != 0x0 && temp_1 != 0x1) {
            if (temp_1 != 0x2 && temp_1 != 0x3) {
                    switch (temp_1) {
                        case 4:
                            decomp_var_54 = GetLastError();
                            break;
                        case 5:
                            decomp_var_54 = GetLastError();
                            break;
                        case 6:
                            decomp_var_54 = GetLastError();
                            break;
                        case 7:
                            break;
                    }
            }
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l85;
    goto .l180;

.l59:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l57:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l69;
    goto .l146;

.l50:
    if (decomp_var_55 != 0x2) goto .l76;
    goto .l56;

.l174:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l168;
    goto .l425;

.l113:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l143;
    goto .l109;

.l138:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l137;
    goto .l136;

.l414:
    eax = decomp_var_55;
    if (eax == 0x0) {
            eax = *(int8_t *)esi;
            bool_469 = eax != 0xa;
            decomp_var_78 = eax == 0xa ? 0x1 : 0x0;
            sub_487c6d(sign_extend_32(eax));
            esp = (esp - 0x4) + 0x4;
            if (!bool_469) {
                    eax = sub_48f457(&decomp_var_54, esi, 0x1);
                    esp = (esp - 0xc) + 0xc;
                    if (eax != 0xffffffff) {
                            esp = esp - 0x20;
                            decomp_var_5c = decomp_var_5c + 0x1;
                            decomp_var_74 = esi + 0x1;
                            eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                            esi = eax;
                            if (esi != 0x0) {
                                    esp = esp - 0x14;
                                    eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                    if (eax != 0x0) {
                                            decomp_var_60 = decomp_var_60 + decomp_var_50;
                                            if (decomp_var_50 >= esi) {
                                                    if (decomp_var_78 != 0x0) {
                                                            arg_508 = 0xd;
                                                            esp = esp - 0x14;
                                                            eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                            if (eax != 0x0) {
                                                                    if (decomp_var_50 >= 0x1) {
                                                                            decomp_var_68 = decomp_var_68 + 0x1;
                                                                            decomp_var_60 = decomp_var_60 + 0x1;
                                                                            if (decomp_var_5c < arg_524) {
                                                                                    esi = decomp_var_74;
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_1 = 0x4;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (decomp_var_5c < arg_524) {
                                                                    esi = decomp_var_74;
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x8;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x4;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x7;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x7;
                            break;
                    }
            }
            else {
                    if ((decomp_var_64 - esi) + arg_524 > 0x1) {
                            eax = sub_48f457(&decomp_var_54, esi, 0x2);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0xffffffff) {
                                    esi = esi + 0x1;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    esp = esp - 0x20;
                                    decomp_var_5c = decomp_var_5c + 0x1;
                                    decomp_var_74 = esi + 0x1;
                                    eax = WideCharToMultiByte(decomp_var_7c, 0x0, &decomp_var_54, 0x1, &arg_508, 0x5, 0x0, 0x0);
                                    esi = eax;
                                    if (esi != 0x0) {
                                            esp = esp - 0x14;
                                            eax = WriteFile(*(ebx + *edi), &arg_508, esi, &decomp_var_50, 0x0);
                                            if (eax != 0x0) {
                                                    decomp_var_60 = decomp_var_60 + decomp_var_50;
                                                    if (decomp_var_50 >= esi) {
                                                            if (decomp_var_78 != 0x0) {
                                                                    arg_508 = 0xd;
                                                                    esp = esp - 0x14;
                                                                    eax = WriteFile(*(ebx + *edi), &arg_508, 0x1, &decomp_var_50, 0x0);
                                                                    if (eax != 0x0) {
                                                                            if (decomp_var_50 >= 0x1) {
                                                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                                                    if (decomp_var_5c < arg_524) {
                                                                                            esi = decomp_var_74;
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x4;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (decomp_var_5c < arg_524) {
                                                                            esi = decomp_var_74;
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_1 = 0x8;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x4;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x7;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x3;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x2;
                            break;
                    }
            }
    }
    else {
            if (eax == 0x1 || eax == 0x2) {
                    ecx = *(int16_t *)esi & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    decomp_var_54 = ecx;
                    decomp_var_74 = esi + 0x2;
                    decomp_var_78 = ecx == 0xa ? 0x1 : 0x0;
            }
            if (eax != 0x1) {
                    if (eax == 0x2) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_48f282(decomp_var_54) == decomp_var_54) {
                                    decomp_var_60 = decomp_var_60 + 0x1;
                                    if (decomp_var_78 != 0x0) {
                                            decomp_var_54 = 0xd;
                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                            if (sub_48f282(0xd) == 0xd) {
                                                    decomp_var_60 = decomp_var_60 + 0x1;
                                                    decomp_var_68 = decomp_var_68 + 0x1;
                                                    if (decomp_var_5c < arg_524) {
                                                            esi = decomp_var_74;
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x6;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x5;
                                    break;
                            }
                    }
                    else {
                            if (decomp_var_5c < arg_524) {
                                    esi = decomp_var_74;
                                    continue;
                            }
                            temp_1 = 0x1;
                            break;
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_48f282(decomp_var_54) == decomp_var_54) {
                            decomp_var_60 = decomp_var_60 + 0x1;
                            if (decomp_var_78 != 0x0) {
                                    decomp_var_54 = 0xd;
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    if (sub_48f282(0xd) == 0xd) {
                                            decomp_var_60 = decomp_var_60 + 0x1;
                                            decomp_var_68 = decomp_var_68 + 0x1;
                                            if (decomp_var_5c < arg_524) {
                                                    esi = decomp_var_74;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x6;
                                            break;
                                    }
                            }
                            else {
                                    if (decomp_var_5c < arg_524) {
                                            esi = decomp_var_74;
                                            continue;
                                    }
                                    temp_1 = 0x1;
                                    break;
                            }
                    }
                    else {
                            temp_1 = 0x5;
                            break;
                    }
            }
    }
    goto .l413;

.l346:
    *sub_47d812() = 0x1c;
    goto .l376;

.l186:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l198;

.l188:
    *sub_47d812() = 0x9;
    goto .l376;

.l193:
    *sub_47d812() = 0x1c;
    goto .l196;

.l192:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l185;

.l187:
    *sub_47d812() = 0x9;
    goto .l196;

.l231:
    eax = sub_47d825();
    *eax = esi;
    goto .l205;

.l258:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l332;
    goto .l262;

.l254:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l250;
    goto .l252;

.l264:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l257;
    goto .l249;

.l253:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l256;
    goto .l251;

.l393:
    *sub_47d812() = 0x1c;
    goto .l399;

.l305:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l356:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l305;

.l398:
    *sub_47d812() = 0x9;
    goto .l399;

.l339:
    eax = sub_47d825();
    *eax = esi;
    goto .l338;

.l242:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l340:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l341;
    goto .l331;

.l326:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l248:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l318;
    goto .l330;

.l240:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l320;
    goto .l319;

.l239:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l323;
    goto .l324;

.l282:
    eax = sub_47d825();
    *eax = esi;
    goto .l296;

.l285:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l388:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l219;
    goto .l298;

.l397:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l225;
    goto .l361;

.l226:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l360;
    goto .l224;

.l279:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l273;
    goto .l403;

.l364:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l274;
    goto loc_4876c2;

.l275:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l410:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l228;
    goto .l378;

.l223:
    *sub_47d812() = 0x1c;
    goto .l220;

.l321:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l217:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l321;

.l216:
    *sub_47d812() = 0x9;
    goto .l220;

.l421:
    if (temp_1 != 0x0 && temp_1 != 0x1) {
            if (temp_1 != 0x2 && temp_1 != 0x3) {
                    switch (temp_1) {
                        case 4:
                            decomp_var_54 = GetLastError();
                            break;
                        case 5:
                            decomp_var_54 = GetLastError();
                            break;
                        case 6:
                            decomp_var_54 = GetLastError();
                            break;
                        case 7:
                            break;
                    }
            }
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l344;
    goto .l281;

.l3:
    *sub_47d812() = 0x1c;
    goto .l5;

.l10:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto loc_4878bb;

.l9:
    *sub_47d812() = 0x9;
    goto .l5;

.l17:
    *sub_47d812() = 0x1c;
    goto .l15;

.l13:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l14;

.l16:
    *sub_47d812() = 0x9;
    goto .l15;

loc_4878ac:
    eax = sub_47d825();
    *eax = esi;
    goto .l4;

.l32:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l120;
    goto .l36;

.l26:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l20;
    goto .l24;

.l38:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l31;
    goto .l19;

.l25:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l28;
    goto .l23;

.l66:
    *sub_47d812() = 0x1c;
    goto .l63;

.l43:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l62:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l43;

.l65:
    *sub_47d812() = 0x9;
    goto .l63;

.l156:
    eax = sub_47d825();
    *eax = esi;
    goto .l155;

.l97:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l157:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l158;
    goto .l119;

.l114:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l93:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l106;
    goto .l118;

.l94:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l108;
    goto .l107;

.l101:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l111;
    goto .l112;

.l89:
    eax = sub_47d825();
    *eax = esi;
    goto .l87;

.l85:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l180:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l139;
    goto .l84;

.l69:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l145;
    goto .l59;

.l146:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l58;
    goto .l144;

.l76:
    decomp_var_5c = eax;
    if (arg_524 <= 0x0) goto .l166;
    goto loc_48775f;

.l56:
    decomp_var_50 = eax;
    if (arg_524 <= 0x0) goto .l167;
    goto .l405;

.l168:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l425:
    while (true) {
            decomp_var_5c = decomp_var_5c & 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x1;
                    edx = *(int8_t *)edx;
                    ecx = ecx + 0x1;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x1;
                            *(int8_t *)eax = 0xd;
                            eax = eax + 0x1;
                            decomp_var_5c = decomp_var_5c + 0x1;
                    }
                    *(int8_t *)eax = edx;
                    eax = eax + 0x1;
                    decomp_var_5c = decomp_var_5c + 0x1;
                    if (decomp_var_5c >= 0x400) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_3 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_3 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_3 = 0x1;
            break;
    }
    if (temp_3 != 0x0 && temp_3 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l148;
    goto .l171;

.l143:
    *sub_47d812() = 0x1c;
    goto .l140;

.l109:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l137:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l109;

.l136:
    *sub_47d812() = 0x9;
    goto .l140;

.l413:
    if (temp_1 != 0x0 && temp_1 != 0x1) {
            if (temp_1 != 0x2 && temp_1 != 0x3) {
                    switch (temp_1) {
                        case 4:
                            decomp_var_54 = GetLastError();
                            break;
                        case 5:
                            decomp_var_54 = GetLastError();
                            break;
                        case 6:
                            decomp_var_54 = GetLastError();
                            break;
                        case 7:
                            break;
                    }
            }
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l124;
    goto .l77;

.l376:
    eax = sub_47d825();
    *eax = esi;
    goto .l198;

.l196:
    eax = sub_47d825();
    *eax = esi;
    goto .l185;

.l332:
    *sub_47d812() = 0x1c;
    goto .l334;

.l250:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l262;

.l252:
    *sub_47d812() = 0x9;
    goto .l334;

.l257:
    *sub_47d812() = 0x1c;
    goto .l260;

.l256:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l249;

.l251:
    *sub_47d812() = 0x9;
    goto .l260;

.l399:
    eax = sub_47d825();
    *eax = esi;
    goto .l305;

.l341:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l345;
    goto .l242;

.l331:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l327;
    goto .l329;

.l318:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l266;
    goto .l326;

.l330:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l268;
    goto .l328;

.l320:
    *sub_47d812() = 0x1c;
    goto .l314;

.l319:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l323:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l319;

.l324:
    *sub_47d812() = 0x9;
    goto .l314;

.l219:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l289;
    goto .l221;

.l298:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l389;
    goto .l391;

.l225:
    *sub_47d812() = 0x1c;
    goto .l362;

.l360:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l361;

.l224:
    *sub_47d812() = 0x9;
    goto .l362;

.l273:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l403:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l270;
    goto .l363;

.l274:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

loc_4876c2:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l311;
    goto .l271;

.l228:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l378:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l276;
    goto .l386;

.l220:
    eax = sub_47d825();
    *eax = esi;
    goto .l321;

.l344:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l281:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l354;
    goto .l343;

.l5:
    eax = sub_47d825();
    *eax = esi;
    goto loc_4878bb;

.l15:
    eax = sub_47d825();
    *eax = esi;
    goto .l14;

.l120:
    *sub_47d812() = 0x1c;
    goto .l151;

.l20:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l36;

.l24:
    *sub_47d812() = 0x9;
    goto .l151;

.l31:
    *sub_47d812() = 0x1c;
    goto .l34;

.l28:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l19;

.l23:
    *sub_47d812() = 0x9;
    goto .l34;

.l63:
    eax = sub_47d825();
    *eax = esi;
    goto .l43;

.l158:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l125;
    goto .l97;

.l119:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l115;
    goto .l117;

.l106:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l159;
    goto .l114;

.l118:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l161;
    goto .l116;

.l108:
    *sub_47d812() = 0x1c;
    goto .l102;

.l107:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l111:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l107;

.l112:
    *sub_47d812() = 0x9;
    goto .l102;

.l139:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l82;
    goto .l141;

.l84:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l181;
    goto .l183;

.l145:
    *sub_47d812() = 0x1c;
    goto .l60;

.l58:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l59;

.l144:
    *sub_47d812() = 0x9;
    goto .l60;

.l166:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

loc_48775f:
    while (true) {
            decomp_var_50 = decomp_var_50 & 0x0;
            ecx = decomp_var_5c - decomp_var_64;
            eax = &arg_3b4;
            esp = (esp - 0x4) + 0x4;
            while (ecx < arg_524) {
                    edx = *(int16_t *)decomp_var_5c & 0xffff;
                    decomp_var_5c = decomp_var_5c + 0x2;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            decomp_var_50 = decomp_var_50 + 0x2;
                    }
                    decomp_var_50 = decomp_var_50 + 0x2;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    if (decomp_var_50 >= 0x152) {
                            break;
                    }
            }
            esi = 0x0;
            esp = esp - 0x20;
            eax = WideCharToMultiByte(0xfde9, 0x0, &arg_3b4, SAR(eax - &arg_3b4 - (eax - &arg_3b4 & 0x80000000 ? 0xffffffff : 0x0), 0x1), &arg_104, 0x2ab, 0x0, 0x0);
            edi = eax;
            if (edi == 0x0) {
                    temp_2 = 0x2;
                    break;
            }
            while (true) {
                    esp = esp - 0x14;
                    eax = WriteFile(*(ebx + *decomp_var_70), ebp + esi + 0x108, edi - esi, &decomp_var_6c, 0x0);
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    esi = esi + decomp_var_6c;
                    if (edi > esi) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    decomp_var_54 = GetLastError();
            }
            if (edi > esi) {
                    temp_2 = 0x0;
                    break;
            }
            decomp_var_60 = decomp_var_5c - decomp_var_64;
            if (decomp_var_5c - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 != 0x0 && temp_2 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l163;
    goto .l54;

.l167:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) {
            *sub_47d812() = 0x1c;
            eax = sub_47d825();
            *eax = 0x0;
    }
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l405:
    while (true) {
            esi = 0x0;
            ecx = decomp_var_50 - decomp_var_64;
            eax = &decomp_var_4c;
            while (ecx < arg_524) {
                    edx = decomp_var_50;
                    decomp_var_50 = decomp_var_50 + 0x2;
                    edx = *(int16_t *)edx & 0xffff;
                    ecx = ecx + 0x2;
                    if (edx == 0xa) {
                            decomp_var_68 = decomp_var_68 + 0x2;
                            *(int16_t *)eax = 0xd;
                            eax = eax + 0x2;
                            esi = esi + 0x2;
                    }
                    edi = decomp_var_70;
                    *(int16_t *)eax = edx;
                    eax = eax + 0x2;
                    esi = esi + 0x2;
                    if (esi >= 0x3ff) {
                            break;
                    }
            }
            esi = eax - &decomp_var_4c;
            esp = esp - 0x14;
            eax = WriteFile(*(ebx + *edi), &decomp_var_4c, esi, &decomp_var_6c, 0x0);
            if (eax == 0x0) {
                    temp_4 = 0x2;
                    break;
            }
            decomp_var_60 = decomp_var_60 + decomp_var_6c;
            if (decomp_var_6c < esi) {
                    temp_4 = 0x0;
                    break;
            }
            if (decomp_var_50 - decomp_var_64 < arg_524) {
                    continue;
            }
            temp_4 = 0x1;
            break;
    }
    if (temp_4 != 0x0 && temp_4 != 0x1) {
            decomp_var_54 = GetLastError();
    }
    eax = decomp_var_60;
    if (eax != 0x0) goto .l44;
    goto .l164;

.l148:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l171:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l169;
    goto .l178;

.l140:
    eax = sub_47d825();
    *eax = esi;
    goto .l109;

.l124:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l77:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l149;
    goto .l123;

.l334:
    eax = sub_47d825();
    *eax = esi;
    goto .l262;

.l260:
    eax = sub_47d825();
    *eax = esi;
    goto .l249;

.l345:
    *sub_47d812() = 0x1c;
    goto .l349;

.l327:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l242;

.l329:
    *sub_47d812() = 0x9;
    goto .l349;

.l266:
    *sub_47d812() = 0x1c;
    goto .l246;

.l268:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l326;

.l328:
    *sub_47d812() = 0x9;
    goto .l246;

.l314:
    eax = sub_47d825();
    *eax = esi;
    goto .l319;

.l289:
    *sub_47d812() = 0x1c;
    goto .l390;

.l221:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l389:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l221;

.l391:
    *sub_47d812() = 0x9;
    goto .l390;

.l362:
    eax = sub_47d825();
    *eax = esi;
    goto .l361;

.l270:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l363:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l303;
    goto .l306;

.l311:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l271:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l272;
    goto .l309;

.l276:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l384;
    goto .l277;

.l386:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l380;
    goto .l383;

.l354:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l295;
    goto .l355;

.l343:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l294;
    goto .l297;

.l151:
    eax = sub_47d825();
    *eax = esi;
    goto .l36;

.l34:
    eax = sub_47d825();
    *eax = esi;
    goto .l19;

.l125:
    *sub_47d812() = 0x1c;
    goto .l75;

.l115:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l97;

.l117:
    *sub_47d812() = 0x9;
    goto .l75;

.l159:
    *sub_47d812() = 0x1c;
    goto .l95;

.l161:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l114;

.l116:
    *sub_47d812() = 0x9;
    goto .l95;

.l102:
    eax = sub_47d825();
    *eax = esi;
    goto .l107;

.l82:
    *sub_47d812() = 0x1c;
    goto .l182;

.l141:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l181:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l141;

.l183:
    *sub_47d812() = 0x9;
    goto .l182;

.l60:
    eax = sub_47d825();
    *eax = esi;
    goto .l59;

.l163:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l54:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l53;
    goto .l49;

.l44:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l164:
    edi = decomp_var_70;
    esi = 0x0;
    if (decomp_var_54 == 0x0) goto .l165;
    goto .l48;

.l169:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l176;
    goto .l170;

.l178:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l172;
    goto .l175;

.l149:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l81;
    goto .l150;

.l123:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l78;
    goto .l80;

.l349:
    eax = sub_47d825();
    *eax = esi;
    goto .l242;

.l246:
    eax = sub_47d825();
    *eax = esi;
    goto .l326;

.l390:
    eax = sub_47d825();
    *eax = esi;
    goto .l221;

.l303:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l392;
    goto .l270;

.l306:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l304;
    goto .l312;

.l272:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l307;
    goto .l311;

.l309:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l310;
    goto .l299;

.l384:
    *sub_47d812() = 0x1c;
    goto .l381;

.l277:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l380:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l277;

.l383:
    *sub_47d812() = 0x9;
    goto .l381;

.l295:
    *sub_47d812() = 0x1c;
    goto .l287;

.l355:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l294:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l355;

.l297:
    *sub_47d812() = 0x9;
    goto .l287;

.l75:
    eax = sub_47d825();
    *eax = esi;
    goto .l97;

.l95:
    eax = sub_47d825();
    *eax = esi;
    goto .l114;

.l182:
    eax = sub_47d825();
    *eax = esi;
    goto .l141;

.l53:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l184;
    goto .l163;

.l49:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l45;
    goto .l47;

.l165:
    if ((*(int8_t *)(ebx + *edi + 0x4) & 0x40) == 0x0 || *(int8_t *)decomp_var_64 != 0x1a) goto .l52;
    goto .l44;

.l48:
    esi = 0x5;
    esp = (esp - 0x4) + 0x4;
    if (decomp_var_54 != 0x5) goto .l51;
    goto .l46;

.l176:
    *sub_47d812() = 0x1c;
    goto .l173;

.l170:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l172:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l170;

.l175:
    *sub_47d812() = 0x9;
    goto .l173;

.l81:
    *sub_47d812() = 0x1c;
    goto .l79;

.l150:
    esp = esp + 0x8;
    eax = sub_47ad69();
    return eax;

.l78:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l150;

.l80:
    *sub_47d812() = 0x9;
    goto .l79;

.l392:
    *sub_47d812() = 0x1c;
    goto .l342;

.l304:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l270;

.l312:
    *sub_47d812() = 0x9;
    goto .l342;

.l307:
    *sub_47d812() = 0x1c;
    goto .l365;

.l310:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l311;

.l299:
    *sub_47d812() = 0x9;
    goto .l365;

.l381:
    eax = sub_47d825();
    *eax = esi;
    goto .l277;

.l287:
    eax = sub_47d825();
    *eax = esi;
    goto .l355;

.l184:
    *sub_47d812() = 0x1c;
    goto .l122;

.l45:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l163;

.l47:
    *sub_47d812() = 0x9;
    goto .l122;

.l52:
    *sub_47d812() = 0x1c;
    goto .l55;

.l51:
    eax = sub_47d838(decomp_var_54);
    esp = (esp - 0x4) + 0x4;
    goto .l44;

.l46:
    *sub_47d812() = 0x9;
    goto .l55;

.l173:
    eax = sub_47d825();
    *eax = esi;
    goto .l170;

.l79:
    eax = sub_47d825();
    *eax = esi;
    goto .l150;

.l342:
    eax = sub_47d825();
    *eax = esi;
    goto .l270;

.l365:
    eax = sub_47d825();
    *eax = esi;
    goto .l311;

.l122:
    eax = sub_47d825();
    *eax = esi;
    goto .l163;

.l55:
    eax = sub_47d825();
    *eax = esi;
    goto .l44;
}
