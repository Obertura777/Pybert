// sub_48e7ad @ 0x48e7ad
// hopper name: sub_48e7ad
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e7ad() {
    decomp_var_2c = ebx;
    decomp_var_30 = esi;
    decomp_var_34 = edi;
    esi = eax;
    var_14 = 0x0;
    var_18 = 0x0;
    var_2 = 0x0;
    var_28 = 0xc;
    esp = (esp - 0x10) + 0x4;
    if ((arg_8 & 0x80) != 0x0) {
            var_1 = 0x10;
    }
    else {
            var_1 = 0x0;
    }
    eax = sub_492cd0(&var_14);
    esp = (esp - 0x4) + 0x4;
    if (eax != 0x0) {
            decomp_var_38 = 0x0;
            decomp_var_3c = 0x0;
            sub_47a828();
            esp = (esp - 0x14) + 0x14;
    }
    eax = sub_47d8ff(&var_18);
    bool_80 = eax != 0x0;
    esp = (esp - 0x4) + 0x4;
    if (eax != 0x0) {
            decomp_var_38 = 0x0;
            decomp_var_3c = 0x0;
            sub_47a828();
            esp = (esp - 0x14) + 0x14;
    }
    if (!bool_80 && ((arg_8 & 0x74000) != 0x0 || var_14 != 0x8000)) {
            var_1 = var_1 | 0x80;
    }
    esp = (esp - 0x4) + 0x4;
    eax = (arg_8 & 0x3) - 0x0;
    if (eax == 0x0) goto loc_48e88a;
    goto loc_48e84c;

loc_48e88a:
    var_C = 0x80000000;
    goto loc_48e88d;

loc_48e84c:
    eax = eax - 0x1;
    if (eax == 0x0) goto loc_48e881;
    goto loc_48e84f;

loc_48e88d:
    eax = arg_c - 0x10;
    if (eax == 0x0) goto loc_48e8c9;
    goto loc_48e894;

loc_48e881:
    var_C = 0x40000000;
    goto loc_48e88d;

loc_48e84f:
    if (eax == 0x1) goto loc_48e878;
    goto .l3;

loc_48e8c9:
    var_8 = 0x0;
    goto loc_48e8cc;

loc_48e894:
    edi = 0x10;
    eax = eax - 0x10;
    if (eax == 0x0) goto loc_48e8c0;
    goto loc_48e898;

loc_48e878:
    var_C = 0xc0000000;
    goto loc_48e88d;

.l3:
    *sub_47d825() = 0x0;
    *esi = *esi | 0xffffffff;
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
    goto loc_48ed07;

loc_48e8cc:
    eax = arg_8 & 0x700;
    bool_13 = eax == 0x400;
    if (eax > 0x400) goto loc_48e91d;
    goto loc_48e8df;

loc_48e8c0:
    var_8 = 0x1;
    goto loc_48e8cc;

loc_48e898:
    eax = eax - edi;
    if (eax == 0x0) goto loc_48e8b7;
    goto loc_48e89c;

loc_48ed07:
    eax = 0x16;
    return eax;

loc_48e91d:
    if (eax == 0x500) goto loc_48e933;
    goto loc_48e924;

loc_48e8df:
    if (bool_13 || eax == 0x0) goto loc_48e914;
    goto loc_48e8e5;

loc_48e8b7:
    var_8 = 0x2;
    goto loc_48e8cc;

loc_48e89c:
    eax = eax - edi;
    if (eax == 0x0) goto loc_48e8b2;
    goto loc_48e8a0;

loc_48e933:
    var_10 = 0x1;
    goto loc_48e93a;

loc_48e924:
    if (eax == 0x600) goto loc_48e98f;
    goto loc_48e92b;

loc_48e914:
    var_10 = 0x3;
    goto loc_48e93a;

loc_48e8e5:
    if (eax == 0x100) goto loc_48e90b;
    goto loc_48e8ec;

loc_48e8b2:
    var_8 = 0x3;
    goto loc_48e8cc;

loc_48e8a0:
    if (eax != 0x40) goto .l3;
    goto loc_48e8a5;

loc_48e93a:
    ecx = arg_8;
    edi = 0x80;
    if ((0x100 & ecx) != 0x0 && (!*dword_bc64b8 & arg_10) >= 0x0) {
            edi = 0x1;
    }
    if ((ecx & 0x40) != 0x0) {
            var_C = var_C | 0x10000;
            edi = edi | 0x4000000;
            if (var_18 == 0x2) {
                    var_8 = var_8 | 0x4;
            }
    }
    if ((ecx & 0x1000) != 0x0) {
            edi = edi | 0x100;
    }
    if ((ecx & 0x20) != 0x0) {
            edi = edi | 0x8000000;
    }
    else {
            if ((ecx & 0x10) != 0x0) {
                    edi = edi | 0x10000000;
            }
    }
    eax = sub_48e56f();
    *esi = eax;
    if (eax != 0xffffffff) goto loc_48e9c6;
    goto loc_48e9af;

loc_48e98f:
    var_10 = 0x5;
    goto loc_48e93a;

loc_48e92b:
    if (eax != 0x700) goto loc_48e852;
    goto .l28;

loc_48e90b:
    var_10 = 0x4;
    goto loc_48e93a;

loc_48e8ec:
    if (eax == 0x200) goto loc_48e98f;
    goto loc_48e8f7;

loc_48e8a5:
    var_8 = var_C == 0x80000000 ? 0x1 : 0x0;
    goto loc_48e8cc;

loc_48e9c6:
    *arg_0 = 0x1;
    esp = esp - 0x1c;
    eax = CreateFileA(arg_4, var_C, var_8, &var_28, var_10, edi, 0x0);
    edi = eax;
    if (edi != 0xffffffff) goto loc_48ea22;
    goto loc_48e9ee;

loc_48e9af:
    *sub_47d825() = 0x0;
    *esi = *esi | 0xffffffff;
    *sub_47d812() = 0x18;
    goto loc_48ea16;

loc_48e852:
    *sub_47d825() = 0x0;
    *esi = *esi | 0xffffffff;
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
    eax = 0x16;
    return eax;

.l28:
    var_10 = 0x1;
    ecx = arg_8;
    edi = 0x80;
    if ((0x100 & ecx) != 0x0 && (!*dword_bc64b8 & arg_10) >= 0x0) {
            edi = 0x1;
    }
    if ((ecx & 0x40) != 0x0) {
            var_C = var_C | 0x10000;
            edi = edi | 0x4000000;
            if (var_18 == 0x2) {
                    var_8 = var_8 | 0x4;
            }
    }
    if ((ecx & 0x1000) != 0x0) {
            edi = edi | 0x100;
    }
    if ((ecx & 0x20) != 0x0) {
            edi = edi | 0x8000000;
    }
    else {
            if ((ecx & 0x10) != 0x0) {
                    edi = edi | 0x10000000;
            }
    }
    eax = sub_48e56f();
    *esi = eax;
    if (eax != 0xffffffff) goto .l14;
    goto .l4;

loc_48e8f7:
    if (eax != 0x300) goto .l3;
    goto loc_48e902;

loc_48ea22:
    ebx = 0x0;
    esp = esp - 0x4;
    eax = GetFileType(edi);
    if (eax != 0x0) goto loc_48ea51;
    goto loc_48ea2d;

loc_48e9ee:
    esi = *esi;
    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfe;
    goto loc_48ea09;

loc_48ea16:
    eax = sub_47d812();
    eax = *eax;
    return eax;

.l14:
    *arg_0 = 0x1;
    esp = esp - 0x1c;
    eax = CreateFileA(arg_4, var_C, var_8, &var_28, var_10, edi, 0x0);
    edi = eax;
    if (edi != 0xffffffff) goto .l8;
    goto .l12;

.l4:
    *sub_47d825() = 0x0;
    *esi = *esi | 0xffffffff;
    *sub_47d812() = 0x18;
    goto .l17;

loc_48e902:
    var_10 = 0x2;
    goto loc_48e93a;

loc_48ea51:
    if (eax == 0x2) {
            var_1 = var_1 | 0x40;
    }
    else {
            if (eax == 0x3) {
                    var_1 = var_1 | 0x8;
            }
    }
    sub_48e33e(*esi, edi);
    eax = *esi;
    esp = (esp - 0x8) + 0x8;
    ecx = var_1 | 0x1;
    *(int8_t *)(*((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x4) = ecx;
    eax = *esi;
    edx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(edx + (eax & 0x1f) * 0x28 + 0x24) = *(int8_t *)(edx + (eax & 0x1f) * 0x28 + 0x24) & 0x80;
    var_3 = ecx & 0x48;
    var_1 = ecx;
    if (var_3 != 0x0) goto loc_48eb38;
    goto loc_48eab8;

loc_48ea2d:
    esi = *esi;
    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfe;
    esp = esp - 0x4;
    CloseHandle(edi);
    goto loc_48ea09;

loc_48ea09:
    esp = esp - 0x4;
    decomp_var_38 = GetLastError();
    sub_47d838(decomp_var_38);
    goto loc_48ea15;

.l8:
    ebx = 0x0;
    esp = esp - 0x4;
    eax = GetFileType(edi);
    if (eax != 0x0) goto .l2;
    goto .l21;

.l12:
    esi = *esi;
    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfe;
    goto .l5;

.l17:
    eax = sub_47d812();
    eax = *eax;
    return eax;

loc_48eb38:
    bool_31 = (var_1 & 0x80) != 0x0;
    if ((var_1 & 0x80) == 0x0) goto loc_48ed72;
    goto loc_48eb42;

loc_48eab8:
    if ((ecx & 0x80) == 0x0) goto loc_48ed72;
    goto loc_48eac1;

loc_48ea15:
    esp = esp + 0x4;
    goto loc_48ea16;

.l2:
    if (eax == 0x2) {
            var_1 = var_1 | 0x40;
    }
    else {
            if (eax == 0x3) {
                    var_1 = var_1 | 0x8;
            }
    }
    sub_48e33e(*esi, edi);
    eax = *esi;
    esp = (esp - 0x8) + 0x8;
    ecx = var_1 | 0x1;
    *(int8_t *)(*((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x4) = ecx;
    eax = *esi;
    edx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(edx + (eax & 0x1f) * 0x28 + 0x24) = *(int8_t *)(edx + (eax & 0x1f) * 0x28 + 0x24) & 0x80;
    var_3 = ecx & 0x48;
    var_1 = ecx;
    if (var_3 != 0x0) goto .l9;
    goto .l10;

.l21:
    esi = *esi;
    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) & 0xfe;
    esp = esp - 0x4;
    CloseHandle(edi);
    goto .l5;

.l5:
    esp = esp - 0x4;
    decomp_var_38 = GetLastError();
    sub_47d838(decomp_var_38);
    goto .l11;

loc_48ed72:
    eax = *esi;
    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
    eax = *esi;
    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
            esi = *esi;
            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
    }
    eax = ebx;
    return eax;

loc_48eb42:
    if (!bool_31) {
            eax = var_14 & 0x74000;
            if (eax == 0x0) {
                    arg_8 = arg_8 | 0x4000;
            }
            else {
                    arg_8 = arg_8 | eax;
            }
    }
    eax = arg_8 & 0x74000;
    if (eax != 0x4000) {
            if (eax != 0x10000 && eax != 0x14000) {
                    if (eax != 0x20000 && eax != 0x24000) {
                            if (eax == 0x40000 || eax == 0x44000) {
                                    var_2 = 0x1;
                            }
                    }
                    else {
                            var_2 = 0x2;
                    }
            }
            else {
                    if ((arg_8 & 0x301) == 0x301) {
                            var_2 = 0x2;
                    }
            }
    }
    else {
            var_2 = ebx;
    }
    if ((arg_8 & 0x70000) == 0x0) goto loc_48ed72;
    goto loc_48ebbd;

loc_48eac1:
    if ((arg_8 & 0x2) == 0x0) goto loc_48eb38;
    goto loc_48eac7;

.l9:
    bool_87 = (var_1 & 0x80) != 0x0;
    if ((var_1 & 0x80) == 0x0) goto .l37;
    goto .l7;

.l10:
    if ((ecx & 0x80) == 0x0) goto .l37;
    goto .l6;

.l11:
    esp = esp + 0x4;
    goto .l17;

loc_48ebbd:
    var_8 = ebx;
    if ((var_1 & 0x40) != 0x0) goto loc_48ed72;
    goto loc_48ebca;

loc_48eac7:
    edi = edi | 0xffffffff;
    eax = sub_492ba2(*esi, edi, 0x2);
    esp = (esp - 0xc) + 0xc;
    var_8 = eax;
    if (eax != edi) goto loc_48eaf7;
    goto loc_48eade;

.l37:
    eax = *esi;
    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
    eax = *esi;
    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
            esi = *esi;
            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
    }
    eax = ebx;
    return eax;

.l7:
    if (!bool_87) {
            eax = var_14 & 0x74000;
            if (eax == 0x0) {
                    arg_8 = arg_8 | 0x4000;
            }
            else {
                    arg_8 = arg_8 | eax;
            }
    }
    eax = arg_8 & 0x74000;
    if (eax != 0x4000) {
            if (eax != 0x10000 && eax != 0x14000) {
                    if (eax != 0x20000 && eax != 0x24000) {
                            if (eax == 0x40000 || eax == 0x44000) {
                                    var_2 = 0x1;
                            }
                    }
                    else {
                            var_2 = 0x2;
                    }
            }
            else {
                    if ((arg_8 & 0x301) == 0x301) {
                            var_2 = 0x2;
                    }
            }
    }
    else {
            var_2 = ebx;
    }
    if ((arg_8 & 0x70000) == 0x0) goto .l37;
    goto .l19;

.l6:
    if ((arg_8 & 0x2) == 0x0) goto .l9;
    goto .l20;

loc_48ebca:
    eax = var_C & 0xc0000000;
    if (eax == 0x40000000) goto loc_48ec96;
    goto loc_48ebdf;

loc_48eaf7:
    var_4 = ebx;
    eax = sub_492524(*esi, &var_4, 0x1);
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0 || var_4 != 0x1a) goto loc_48eb28;
    goto loc_48eb14;

loc_48eade:
    if (*sub_47d825() == 0x83) goto loc_48eb38;
    goto loc_48eaeb;

.l19:
    var_8 = ebx;
    if ((var_1 & 0x40) != 0x0) goto .l37;
    goto .l16;

.l20:
    edi = edi | 0xffffffff;
    eax = sub_492ba2(*esi, edi, 0x2);
    esp = (esp - 0xc) + 0xc;
    var_8 = eax;
    if (eax != edi) goto .l53;
    goto .l22;

loc_48ec96:
    eax = var_10;
    if (eax <= ebx) goto loc_48ed72;
    goto loc_48eca1;

loc_48ebdf:
    if (eax == 0x80000000) goto loc_48ec5d;
    goto loc_48ebe6;

loc_48eb28:
    esp = (esp - 0xc) + 0xc;
    if (sub_492ba2(*esi, ebx, ebx) == edi) goto loc_48eaeb;
    goto loc_48eb38;

loc_48eb14:
    edx = var_8 & 0x80000000 ? 0xffffffff : 0x0;
    esp = (esp - 0xc) + 0xc;
    if (sub_492370(*esi, var_8, edx) == edi) goto loc_48eaeb;
    goto loc_48eb28;

loc_48eaeb:
    esp = esp - 0x4;
    decomp_var_38 = *esi;
    sub_48664d(decomp_var_38);
    goto loc_48ea15;

.l16:
    eax = var_C & 0xc0000000;
    if (eax == 0x40000000) goto .l56;
    goto .l13;

.l53:
    var_4 = ebx;
    eax = sub_492524(*esi, &var_4, 0x1);
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0) goto .l43;
    goto loc_48eb0e;

.l22:
    if (*sub_47d825() == 0x83) goto .l9;
    goto .l18;

loc_48eca1:
    if (eax <= 0x2) goto loc_48ec0c;
    goto loc_48ecaa;

loc_48ec5d:
    eax = sub_492524(*esi, &var_8, 0x3);
    esp = (esp - 0xc) + 0xc;
    if (eax == 0xffffffff) goto loc_48eaeb;
    goto loc_48ec76;

loc_48ebe6:
    if (eax != 0xc0000000) goto loc_48ed72;
    goto loc_48ebee;

.l56:
    eax = var_10;
    if (eax <= ebx) goto .l37;
    goto .l38;

.l13:
    if (eax == 0x80000000) goto .l52;
    goto .l55;

.l43:
    esp = (esp - 0xc) + 0xc;
    if (sub_492ba2(*esi, ebx, ebx) == edi) goto .l58;
    goto .l9;

loc_48eb0e:
    if (var_4 != 0x1a) goto .l65;
    goto .l74;

.l18:
    esp = esp - 0x4;
    decomp_var_38 = *esi;
    sub_48664d(decomp_var_38);
    goto .l11;

loc_48ec0c:
    edi = 0x0;
    eax = sign_extend_32(var_2) - 0x1;
    if (eax == 0x0) goto loc_48ed3f;
    goto loc_48ec19;

loc_48ecaa:
    if (eax > 0x4) goto loc_48ec03;
    goto loc_48ecb3;

loc_48ec76:
    if (eax == 0x2) goto loc_48ece6;
    goto loc_48ec7b;

loc_48ebee:
    eax = var_10;
    if (eax <= ebx) goto loc_48ed72;
    goto loc_48ebf9;

.l38:
    if (eax <= 0x2) goto .l42;
    goto .l32;

.l52:
    eax = sub_492524(*esi, &var_8, 0x3);
    esp = (esp - 0xc) + 0xc;
    if (eax == 0xffffffff) goto .l18;
    goto .l44;

.l55:
    if (eax != 0xc0000000) goto .l37;
    goto .l33;

.l58:
    esp = esp - 0x4;
    decomp_var_38 = *esi;
    sub_48664d(decomp_var_38);
    esp = esp + 0x4;
    eax = sub_47d812();
    eax = *eax;
    return eax;

.l65:
    esp = (esp - 0xc) + 0xc;
    if (sub_492ba2(*esi, ebx, ebx) == edi) goto .l62;
    goto .l70;

.l74:
    edx = var_8 & 0x80000000 ? 0xffffffff : 0x0;
    esp = (esp - 0xc) + 0xc;
    if (sub_492370(*esi, var_8, edx) != edi) {
            esp = (esp - 0xc) + 0xc;
            if (sub_492ba2(*esi, ebx, ebx) != edi) {
                    bool_244 = (var_1 & 0x80) != 0x0;
                    if ((var_1 & 0x80) != 0x0) {
                            if (!bool_244) {
                                    eax = var_14 & 0x74000;
                                    if (eax == 0x0) {
                                            arg_8 = arg_8 | 0x4000;
                                    }
                                    else {
                                            arg_8 = arg_8 | eax;
                                    }
                            }
                            eax = arg_8 & 0x74000;
                            switch (eax) {
                                case 16384:
                                    var_2 = ebx;
                                    break;
                                case 65536:
                                    if ((arg_8 & 0x301) == 0x301) {
                                            var_2 = 0x2;
                                    }
                                    break;
                                case 81920:
                                    if ((arg_8 & 0x301) == 0x301) {
                                            var_2 = 0x2;
                                    }
                                    break;
                                default:
                                    if (eax != 0x20000 && eax != 0x24000) {
                                            if (eax == 0x40000 || eax == 0x44000) {
                                                    var_2 = 0x1;
                                            }
                                    }
                                    else {
                                            var_2 = 0x2;
                                    }
                                    break;
                            }
                            if ((arg_8 & 0x70000) != 0x0) {
                                    var_8 = ebx;
                                    if ((var_1 & 0x40) == 0x0) {
                                            eax = var_C & 0xc0000000;
                                            if (eax != 0x40000000) {
                                                    if (eax != 0x80000000) {
                                                            if (eax == 0xc0000000) {
                                                                    eax = var_10;
                                                                    if (eax > ebx) {
                                                                            if (eax > 0x2) {
                                                                                    if (eax > 0x4) {
                                                                                            if (eax == 0x5) {
                                                                                                    edi = 0x0;
                                                                                                    eax = sign_extend_32(var_2) - 0x1;
                                                                                                    if (eax != 0x0) {
                                                                                                            if (eax == 0x1) {
                                                                                                                    var_10 = 0x2;
                                                                                                                    while (true) {
                                                                                                                            eax = sub_4878d3();
                                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                                            if (eax == 0xffffffff) {
                                                                                                                                    temp_0 = 0x0;
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                            edi = edi + eax;
                                                                                                                            if (var_10 > edi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_0 = 0x1;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    if (temp_0 != 0x0) {
                                                                                                                            eax = *esi;
                                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                            eax = *esi;
                                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                    esi = *esi;
                                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                            }
                                                                                                                            eax = ebx;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            decomp_var_38 = *esi;
                                                                                                                            sub_48664d(decomp_var_38);
                                                                                                                            esp = esp + 0x4;
                                                                                                                            eax = sub_47d812();
                                                                                                                            eax = *eax;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = *esi;
                                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                    eax = *esi;
                                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                            esi = *esi;
                                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                    }
                                                                                                                    eax = ebx;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            var_10 = 0x3;
                                                                                                            while (true) {
                                                                                                                    eax = sub_4878d3();
                                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                                    if (eax == 0xffffffff) {
                                                                                                                            temp_0 = 0x0;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    edi = edi + eax;
                                                                                                                    if (var_10 > edi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_0 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            if (temp_0 != 0x0) {
                                                                                                                    eax = *esi;
                                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                    eax = *esi;
                                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                            esi = *esi;
                                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                    }
                                                                                                                    eax = ebx;
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_38 = *esi;
                                                                                                                    sub_48664d(decomp_var_38);
                                                                                                                    esp = esp + 0x4;
                                                                                                                    eax = sub_47d812();
                                                                                                                    eax = *eax;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) != 0x0) {
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    if ((sub_48df70(*esi, ebx, ebx, ebx) & edx) != 0xffffffff) {
                                                                                                            eax = sub_492524(*esi, &var_8, 0x3);
                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                            switch (eax) {
                                                                                                                case -1:
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_38 = *esi;
                                                                                                                    sub_48664d(decomp_var_38);
                                                                                                                    esp = esp + 0x4;
                                                                                                                    eax = sub_47d812();
                                                                                                                    eax = *eax;
                                                                                                                    break;
                                                                                                                case 2:
                                                                                                                    eax = var_8 & 0xffff;
                                                                                                                    if (eax == 0xfffe) {
                                                                                                                            sub_48664d(*esi);
                                                                                                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                                                                            *sub_47d812() = 0x16;
                                                                                                                            eax = 0x16;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (eax == 0xfeff) {
                                                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                                                    if (sub_492ba2(*esi, 0x2, ebx) != 0xffffffff) {
                                                                                                                                            var_2 = 0x2;
                                                                                                                                            eax = *esi;
                                                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                                            eax = *esi;
                                                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                                    esi = *esi;
                                                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                                            }
                                                                                                                                            eax = ebx;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esp = esp - 0x4;
                                                                                                                                            decomp_var_38 = *esi;
                                                                                                                                            sub_48664d(decomp_var_38);
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                            eax = sub_47d812();
                                                                                                                                            eax = *eax;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = sub_492ba2(*esi, ebx, ebx);
                                                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                                                    if (eax == 0xffffffff) {
                                                                                                                                            esp = esp - 0x4;
                                                                                                                                            decomp_var_38 = *esi;
                                                                                                                                            sub_48664d(decomp_var_38);
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                            eax = sub_47d812();
                                                                                                                                            eax = *eax;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            eax = *esi;
                                                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                                            eax = *esi;
                                                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                                    esi = *esi;
                                                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                                            }
                                                                                                                                            eax = ebx;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    break;
                                                                                                                default:
                                                                                                                    if (eax == 0x3) {
                                                                                                                            if (var_8 == 0xbfbbef) {
                                                                                                                                    var_2 = 0x1;
                                                                                                                                    eax = *esi;
                                                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                                    eax = *esi;
                                                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                            esi = *esi;
                                                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                                    }
                                                                                                                                    eax = ebx;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = var_8 & 0xffff;
                                                                                                                                    if (eax == 0xfffe) {
                                                                                                                                            sub_48664d(*esi);
                                                                                                                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                                                                                            *sub_47d812() = 0x16;
                                                                                                                                            eax = 0x16;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            if (eax == 0xfeff) {
                                                                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                                                                    if (sub_492ba2(*esi, 0x2, ebx) != 0xffffffff) {
                                                                                                                                                            var_2 = 0x2;
                                                                                                                                                            eax = *esi;
                                                                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                                                            eax = *esi;
                                                                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                                                    esi = *esi;
                                                                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                                                            }
                                                                                                                                                            eax = ebx;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                            decomp_var_38 = *esi;
                                                                                                                                                            sub_48664d(decomp_var_38);
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                            eax = sub_47d812();
                                                                                                                                                            eax = *eax;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    eax = sub_492ba2(*esi, ebx, ebx);
                                                                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                                                                    if (eax == 0xffffffff) {
                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                            decomp_var_38 = *esi;
                                                                                                                                                            sub_48664d(decomp_var_38);
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                            eax = sub_47d812();
                                                                                                                                                            eax = *eax;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            eax = *esi;
                                                                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                                                            eax = *esi;
                                                                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                                                    esi = *esi;
                                                                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                                                            }
                                                                                                                                                            eax = ebx;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = sub_492ba2(*esi, ebx, ebx);
                                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                                            if (eax == 0xffffffff) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    decomp_var_38 = *esi;
                                                                                                                                    sub_48664d(decomp_var_38);
                                                                                                                                    esp = esp + 0x4;
                                                                                                                                    eax = sub_47d812();
                                                                                                                                    eax = *eax;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = *esi;
                                                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                                    eax = *esi;
                                                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                            esi = *esi;
                                                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                                    }
                                                                                                                                    eax = ebx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_38 = *esi;
                                                                                                            sub_48664d(decomp_var_38);
                                                                                                            esp = esp + 0x4;
                                                                                                            eax = sub_47d812();
                                                                                                            eax = *eax;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    edi = 0x0;
                                                                                                    eax = sign_extend_32(var_2) - 0x1;
                                                                                                    if (eax != 0x0) {
                                                                                                            if (eax == 0x1) {
                                                                                                                    var_10 = 0x2;
                                                                                                                    while (true) {
                                                                                                                            eax = sub_4878d3();
                                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                                            if (eax == 0xffffffff) {
                                                                                                                                    temp_0 = 0x0;
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                            edi = edi + eax;
                                                                                                                            if (var_10 > edi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_0 = 0x1;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    if (temp_0 != 0x0) {
                                                                                                                            eax = *esi;
                                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                            eax = *esi;
                                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                                    esi = *esi;
                                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                            }
                                                                                                                            eax = ebx;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            decomp_var_38 = *esi;
                                                                                                                            sub_48664d(decomp_var_38);
                                                                                                                            esp = esp + 0x4;
                                                                                                                            eax = sub_47d812();
                                                                                                                            eax = *eax;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = *esi;
                                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                    eax = *esi;
                                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                            esi = *esi;
                                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                    }
                                                                                                                    eax = ebx;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            var_10 = 0x3;
                                                                                                            while (true) {
                                                                                                                    eax = sub_4878d3();
                                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                                    if (eax == 0xffffffff) {
                                                                                                                            temp_0 = 0x0;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    edi = edi + eax;
                                                                                                                    if (var_10 > edi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_0 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            if (temp_0 != 0x0) {
                                                                                                                    eax = *esi;
                                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                                    eax = *esi;
                                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                            esi = *esi;
                                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                                    }
                                                                                                                    eax = ebx;
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_38 = *esi;
                                                                                                                    sub_48664d(decomp_var_38);
                                                                                                                    esp = esp + 0x4;
                                                                                                                    eax = sub_47d812();
                                                                                                                    eax = *eax;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    edi = 0x0;
                                                                                    eax = sign_extend_32(var_2) - 0x1;
                                                                                    if (eax != 0x0) {
                                                                                            if (eax == 0x1) {
                                                                                                    var_10 = 0x2;
                                                                                                    while (true) {
                                                                                                            eax = sub_4878d3();
                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                            if (eax == 0xffffffff) {
                                                                                                                    temp_0 = 0x0;
                                                                                                                    break;
                                                                                                            }
                                                                                                            edi = edi + eax;
                                                                                                            if (var_10 > edi) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_0 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    if (temp_0 != 0x0) {
                                                                                                            eax = *esi;
                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                            eax = *esi;
                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                    esi = *esi;
                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                            }
                                                                                                            eax = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_38 = *esi;
                                                                                                            sub_48664d(decomp_var_38);
                                                                                                            esp = esp + 0x4;
                                                                                                            eax = sub_47d812();
                                                                                                            eax = *eax;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            var_10 = 0x3;
                                                                                            while (true) {
                                                                                                    eax = sub_4878d3();
                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                    if (eax == 0xffffffff) {
                                                                                                            temp_0 = 0x0;
                                                                                                            break;
                                                                                                    }
                                                                                                    edi = edi + eax;
                                                                                                    if (var_10 > edi) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            if (temp_0 != 0x0) {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_38 = *esi;
                                                                                                    sub_48664d(decomp_var_38);
                                                                                                    esp = esp + 0x4;
                                                                                                    eax = sub_47d812();
                                                                                                    eax = *eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = *esi;
                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                            eax = *esi;
                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                    esi = *esi;
                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = *esi;
                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                    eax = *esi;
                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                            esi = *esi;
                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_492524(*esi, &var_8, 0x3);
                                                            esp = (esp - 0xc) + 0xc;
                                                            switch (eax) {
                                                                case -1:
                                                                    esp = esp - 0x4;
                                                                    decomp_var_38 = *esi;
                                                                    sub_48664d(decomp_var_38);
                                                                    esp = esp + 0x4;
                                                                    eax = sub_47d812();
                                                                    eax = *eax;
                                                                    break;
                                                                case 2:
                                                                    eax = var_8 & 0xffff;
                                                                    if (eax == 0xfffe) {
                                                                            sub_48664d(*esi);
                                                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                            *sub_47d812() = 0x16;
                                                                            eax = 0x16;
                                                                    }
                                                                    else {
                                                                            if (eax == 0xfeff) {
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (sub_492ba2(*esi, 0x2, ebx) != 0xffffffff) {
                                                                                            var_2 = 0x2;
                                                                                            eax = *esi;
                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                            eax = *esi;
                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                    esi = *esi;
                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                            }
                                                                                            eax = ebx;
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_38 = *esi;
                                                                                            sub_48664d(decomp_var_38);
                                                                                            esp = esp + 0x4;
                                                                                            eax = sub_47d812();
                                                                                            eax = *eax;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_492ba2(*esi, ebx, ebx);
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (eax == 0xffffffff) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_38 = *esi;
                                                                                            sub_48664d(decomp_var_38);
                                                                                            esp = esp + 0x4;
                                                                                            eax = sub_47d812();
                                                                                            eax = *eax;
                                                                                    }
                                                                                    else {
                                                                                            eax = *esi;
                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                            eax = *esi;
                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                    esi = *esi;
                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                            }
                                                                                            eax = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    break;
                                                                default:
                                                                    if (eax == 0x3) {
                                                                            if (var_8 == 0xbfbbef) {
                                                                                    var_2 = 0x1;
                                                                                    eax = *esi;
                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                    eax = *esi;
                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                            esi = *esi;
                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                    }
                                                                                    eax = ebx;
                                                                            }
                                                                            else {
                                                                                    eax = var_8 & 0xffff;
                                                                                    if (eax == 0xfffe) {
                                                                                            sub_48664d(*esi);
                                                                                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                                                                            *sub_47d812() = 0x16;
                                                                                            eax = 0x16;
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0xfeff) {
                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                    if (sub_492ba2(*esi, 0x2, ebx) != 0xffffffff) {
                                                                                                            var_2 = 0x2;
                                                                                                            eax = *esi;
                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                            eax = *esi;
                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                    esi = *esi;
                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                            }
                                                                                                            eax = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_38 = *esi;
                                                                                                            sub_48664d(decomp_var_38);
                                                                                                            esp = esp + 0x4;
                                                                                                            eax = sub_47d812();
                                                                                                            eax = *eax;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = sub_492ba2(*esi, ebx, ebx);
                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                    if (eax == 0xffffffff) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_38 = *esi;
                                                                                                            sub_48664d(decomp_var_38);
                                                                                                            esp = esp + 0x4;
                                                                                                            eax = sub_47d812();
                                                                                                            eax = *eax;
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = *esi;
                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                            eax = *esi;
                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                    esi = *esi;
                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                            }
                                                                                                            eax = ebx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_492ba2(*esi, ebx, ebx);
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (eax == 0xffffffff) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_38 = *esi;
                                                                                    sub_48664d(decomp_var_38);
                                                                                    esp = esp + 0x4;
                                                                                    eax = sub_47d812();
                                                                                    eax = *eax;
                                                                            }
                                                                            else {
                                                                                    eax = *esi;
                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                    eax = *esi;
                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                            esi = *esi;
                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                    }
                                                                                    eax = ebx;
                                                                            }
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = var_10;
                                                    if (eax > ebx) {
                                                            if (eax > 0x2) {
                                                                    if (eax <= 0x4) {
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) != 0x0) {
                                                                                    eax = sub_48df70(*esi, ebx, ebx, ebx);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = eax & edx;
                                                                                    if (eax == 0xffffffff) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_38 = *esi;
                                                                                            sub_48664d(decomp_var_38);
                                                                                            esp = esp + 0x4;
                                                                                            eax = sub_47d812();
                                                                                            eax = *eax;
                                                                                    }
                                                                                    else {
                                                                                            eax = *esi;
                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                            eax = *esi;
                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                    esi = *esi;
                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                            }
                                                                                            eax = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    edi = 0x0;
                                                                                    eax = sign_extend_32(var_2) - 0x1;
                                                                                    if (eax != 0x0) {
                                                                                            if (eax == 0x1) {
                                                                                                    var_10 = 0x2;
                                                                                                    while (true) {
                                                                                                            eax = sub_4878d3();
                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                            if (eax == 0xffffffff) {
                                                                                                                    temp_0 = 0x0;
                                                                                                                    break;
                                                                                                            }
                                                                                                            edi = edi + eax;
                                                                                                            if (var_10 > edi) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_0 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    if (temp_0 != 0x0) {
                                                                                                            eax = *esi;
                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                            eax = *esi;
                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                    esi = *esi;
                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                            }
                                                                                                            eax = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_38 = *esi;
                                                                                                            sub_48664d(decomp_var_38);
                                                                                                            esp = esp + 0x4;
                                                                                                            eax = sub_47d812();
                                                                                                            eax = *eax;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            var_10 = 0x3;
                                                                                            while (true) {
                                                                                                    eax = sub_4878d3();
                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                    if (eax == 0xffffffff) {
                                                                                                            temp_0 = 0x0;
                                                                                                            break;
                                                                                                    }
                                                                                                    edi = edi + eax;
                                                                                                    if (var_10 > edi) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            if (temp_0 != 0x0) {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_38 = *esi;
                                                                                                    sub_48664d(decomp_var_38);
                                                                                                    esp = esp + 0x4;
                                                                                                    eax = sub_47d812();
                                                                                                    eax = *eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax == 0x5) {
                                                                                    edi = 0x0;
                                                                                    eax = sign_extend_32(var_2) - 0x1;
                                                                                    if (eax != 0x0) {
                                                                                            if (eax == 0x1) {
                                                                                                    var_10 = 0x2;
                                                                                                    while (true) {
                                                                                                            eax = sub_4878d3();
                                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                                            if (eax == 0xffffffff) {
                                                                                                                    temp_0 = 0x0;
                                                                                                                    break;
                                                                                                            }
                                                                                                            edi = edi + eax;
                                                                                                            if (var_10 > edi) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_0 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    if (temp_0 != 0x0) {
                                                                                                            eax = *esi;
                                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                            eax = *esi;
                                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                                    esi = *esi;
                                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                            }
                                                                                                            eax = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_38 = *esi;
                                                                                                            sub_48664d(decomp_var_38);
                                                                                                            esp = esp + 0x4;
                                                                                                            eax = sub_47d812();
                                                                                                            eax = *eax;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            var_10 = 0x3;
                                                                                            while (true) {
                                                                                                    eax = sub_4878d3();
                                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                                    if (eax == 0xffffffff) {
                                                                                                            temp_0 = 0x0;
                                                                                                            break;
                                                                                                    }
                                                                                                    edi = edi + eax;
                                                                                                    if (var_10 > edi) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            if (temp_0 != 0x0) {
                                                                                                    eax = *esi;
                                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                                    eax = *esi;
                                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                            esi = *esi;
                                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                                    }
                                                                                                    eax = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_38 = *esi;
                                                                                                    sub_48664d(decomp_var_38);
                                                                                                    esp = esp + 0x4;
                                                                                                    eax = sub_47d812();
                                                                                                    eax = *eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = *esi;
                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                    eax = *esi;
                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                            esi = *esi;
                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                    }
                                                                                    eax = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    edi = 0x0;
                                                                    eax = sign_extend_32(var_2) - 0x1;
                                                                    if (eax != 0x0) {
                                                                            if (eax == 0x1) {
                                                                                    var_10 = 0x2;
                                                                                    while (true) {
                                                                                            eax = sub_4878d3();
                                                                                            esp = (esp - 0xc) + 0xc;
                                                                                            if (eax == 0xffffffff) {
                                                                                                    temp_0 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                            edi = edi + eax;
                                                                                            if (var_10 > edi) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    if (temp_0 != 0x0) {
                                                                                            eax = *esi;
                                                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                            eax = *esi;
                                                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                                    esi = *esi;
                                                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                            }
                                                                                            eax = ebx;
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_38 = *esi;
                                                                                            sub_48664d(decomp_var_38);
                                                                                            esp = esp + 0x4;
                                                                                            eax = sub_47d812();
                                                                                            eax = *eax;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = *esi;
                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                    eax = *esi;
                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                            esi = *esi;
                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                    }
                                                                                    eax = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            var_10 = 0x3;
                                                                            while (true) {
                                                                                    eax = sub_4878d3();
                                                                                    esp = (esp - 0xc) + 0xc;
                                                                                    if (eax == 0xffffffff) {
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    edi = edi + eax;
                                                                                    if (var_10 > edi) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            if (temp_0 != 0x0) {
                                                                                    eax = *esi;
                                                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                                                    eax = *esi;
                                                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                                            esi = *esi;
                                                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                                                    }
                                                                                    eax = ebx;
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_38 = *esi;
                                                                                    sub_48664d(decomp_var_38);
                                                                                    esp = esp + 0x4;
                                                                                    eax = sub_47d812();
                                                                                    eax = *eax;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = *esi;
                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                            eax = *esi;
                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                    esi = *esi;
                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = *esi;
                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                            eax = *esi;
                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                    esi = *esi;
                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_38 = *esi;
                    sub_48664d(decomp_var_38);
                    esp = esp + 0x4;
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    else {
            esp = esp - 0x4;
            decomp_var_38 = *esi;
            sub_48664d(decomp_var_38);
            esp = esp + 0x4;
            eax = sub_47d812();
            eax = *eax;
    }
    return eax;

loc_48ed3f:
    var_10 = 0x3;
    goto loc_48ed4d;

loc_48ec19:
    if (eax != 0x1) goto loc_48ed72;
    goto loc_48ec20;

loc_48ec03:
    if (eax != 0x5) goto loc_48ed72;
    goto loc_48ec0c;

loc_48ecb3:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) == 0x0) goto loc_48ec0c;
    goto loc_48ecc9;

loc_48ece6:
    eax = var_8 & 0xffff;
    if (eax != 0xfffe) goto loc_48ed0e;
    goto loc_48ecf5;

loc_48ec7b:
    if (eax != 0x3) goto loc_48ed31;
    goto loc_48ec84;

loc_48ebf9:
    if (eax <= 0x2) goto loc_48ec0c;
    goto loc_48ebfe;

.l42:
    edi = 0x0;
    eax = sign_extend_32(var_2) - 0x1;
    if (eax == 0x0) goto .l39;
    goto .l36;

.l32:
    if (eax > 0x4) goto .l45;
    goto .l23;

.l44:
    if (eax == 0x2) goto .l47;
    goto .l29;

.l33:
    eax = var_10;
    if (eax <= ebx) goto .l37;
    goto .l25;

.l62:
    esp = esp - 0x4;
    decomp_var_38 = *esi;
    sub_48664d(decomp_var_38);
    esp = esp + 0x4;
    eax = sub_47d812();
    eax = *eax;
    return eax;

.l70:
    bool_173 = (var_1 & 0x80) != 0x0;
    if ((var_1 & 0x80) == 0x0) goto .l40;
    goto .l73;

loc_48ed4d:
    while (true) {
            eax = sub_4878d3();
            esp = (esp - 0xc) + 0xc;
            if (eax == 0xffffffff) {
                    temp_0 = 0x0;
                    break;
            }
            edi = edi + eax;
            if (var_10 > edi) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0) goto loc_48eaeb;
    goto loc_48ed72;

loc_48ec20:
    var_10 = 0x2;
    goto loc_48ed4d;

loc_48ecc9:
    eax = sub_48df70(*esi, ebx, ebx, ebx);
    esp = (esp - 0x10) + 0x10;
    eax = eax & edx;
    goto loc_48ecd8;

loc_48ed0e:
    if (eax != 0xfeff) goto loc_48ed31;
    goto loc_48ed15;

loc_48ecf5:
    sub_48664d(*esi);
    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
    *sub_47d812() = 0x16;
    goto loc_48ed07;

loc_48ed31:
    eax = sub_492ba2(*esi, ebx, ebx);
    esp = (esp - 0xc) + 0xc;
    goto loc_48ecd8;

loc_48ec84:
    if (var_8 != 0xbfbbef) goto loc_48ece6;
    goto loc_48ec8d;

loc_48ebfe:
    if (eax <= 0x4) goto loc_48ec33;
    goto loc_48ec03;

.l39:
    var_10 = 0x3;
    goto .l76;

.l36:
    if (eax != 0x1) goto .l37;
    goto .l30;

.l45:
    if (eax != 0x5) goto .l37;
    goto .l42;

.l23:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) == 0x0) goto .l42;
    goto .l24;

.l47:
    eax = var_8 & 0xffff;
    if (eax != 0xfffe) goto .l57;
    goto .l34;

.l29:
    if (eax != 0x3) goto .l46;
    goto .l35;

.l25:
    if (eax <= 0x2) goto .l42;
    goto .l49;

.l40:
    eax = *esi;
    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
    eax = *esi;
    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
            esi = *esi;
            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
    }
    eax = ebx;
    return eax;

.l73:
    if (!bool_173) {
            eax = var_14 & 0x74000;
            if (eax == 0x0) {
                    arg_8 = arg_8 | 0x4000;
            }
            else {
                    arg_8 = arg_8 | eax;
            }
    }
    eax = arg_8 & 0x74000;
    switch (eax) {
        case 16384:
            var_2 = ebx;
            break;
        case 65536:
            if ((arg_8 & 0x301) == 0x301) {
                    var_2 = 0x2;
            }
            break;
        case 81920:
            if ((arg_8 & 0x301) == 0x301) {
                    var_2 = 0x2;
            }
            break;
        default:
            if (eax != 0x20000 && eax != 0x24000) {
                    if (eax == 0x40000 || eax == 0x44000) {
                            var_2 = 0x1;
                    }
            }
            else {
                    var_2 = 0x2;
            }
            break;
    }
    if ((arg_8 & 0x70000) == 0x0) goto .l40;
    goto .l69;

loc_48ecd8:
    if (eax != 0xffffffff) goto loc_48ed72;
    goto loc_48eaeb;

loc_48ed15:
    esp = (esp - 0xc) + 0xc;
    if (sub_492ba2(*esi, 0x2, ebx) == 0xffffffff) goto loc_48eaeb;
    goto loc_48ed2b;

loc_48ec8d:
    var_2 = 0x1;
    goto loc_48ed72;

loc_48ec33:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) == 0x0) goto loc_48ec0c;
    goto loc_48ec45;

.l76:
    while (true) {
            eax = sub_4878d3();
            esp = (esp - 0xc) + 0xc;
            if (eax == 0xffffffff) {
                    temp_0 = 0x0;
                    break;
            }
            edi = edi + eax;
            if (var_10 > edi) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0) goto .l18;
    goto .l37;

.l30:
    var_10 = 0x2;
    goto .l76;

.l24:
    eax = sub_48df70(*esi, ebx, ebx, ebx);
    esp = (esp - 0x10) + 0x10;
    eax = eax & edx;
    goto .l31;

.l57:
    if (eax != 0xfeff) goto .l46;
    goto .l51;

.l34:
    sub_48664d(*esi);
    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
    *sub_47d812() = 0x16;
    eax = 0x16;
    return eax;

.l46:
    eax = sub_492ba2(*esi, ebx, ebx);
    esp = (esp - 0xc) + 0xc;
    goto .l31;

.l35:
    if (var_8 != 0xbfbbef) goto .l47;
    goto .l48;

.l49:
    if (eax <= 0x4) goto .l41;
    goto .l45;

.l69:
    var_8 = ebx;
    if ((var_1 & 0x40) != 0x0) goto .l40;
    goto .l71;

loc_48ed2b:
    var_2 = 0x2;
    goto loc_48ed72;

loc_48ec45:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, ebx) & edx) == 0xffffffff) goto loc_48eaeb;
    goto loc_48ec5d;

.l31:
    if (eax != 0xffffffff) goto .l37;
    goto .l18;

.l51:
    esp = (esp - 0xc) + 0xc;
    if (sub_492ba2(*esi, 0x2, ebx) == 0xffffffff) goto .l18;
    goto .l54;

.l48:
    var_2 = 0x1;
    goto .l37;

.l41:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) == 0x0) goto .l42;
    goto .l50;

.l71:
    eax = var_C & 0xc0000000;
    if (eax == 0x40000000) goto .l64;
    goto .l72;

.l54:
    var_2 = 0x2;
    goto .l37;

.l50:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, ebx) & edx) == 0xffffffff) goto .l18;
    goto .l52;

.l64:
    eax = var_10;
    if (eax > ebx) {
            if (eax > 0x2) {
                    if (eax <= 0x4) {
                            esp = (esp - 0x10) + 0x10;
                            if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) != 0x0) {
                                    eax = sub_48df70(*esi, ebx, ebx, ebx);
                                    esp = (esp - 0x10) + 0x10;
                                    eax = eax & edx;
                                    if (eax == 0xffffffff) {
                                            esp = esp - 0x4;
                                            decomp_var_38 = *esi;
                                            sub_48664d(decomp_var_38);
                                            esp = esp + 0x4;
                                            eax = sub_47d812();
                                            eax = *eax;
                                    }
                                    else {
                                            eax = *esi;
                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                            eax = *esi;
                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                    esi = *esi;
                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    edi = 0x0;
                                    eax = sign_extend_32(var_2) - 0x1;
                                    if (eax != 0x0) {
                                            if (eax == 0x1) {
                                                    var_10 = 0x2;
                                                    while (true) {
                                                            eax = sub_4878d3();
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (eax == 0xffffffff) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            edi = edi + eax;
                                                            if (var_10 > edi) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    if (temp_0 != 0x0) {
                                                            eax = *esi;
                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                            eax = *esi;
                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                    esi = *esi;
                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                            }
                                                            eax = ebx;
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_38 = *esi;
                                                            sub_48664d(decomp_var_38);
                                                            esp = esp + 0x4;
                                                            eax = sub_47d812();
                                                            eax = *eax;
                                                    }
                                            }
                                            else {
                                                    eax = *esi;
                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                    eax = *esi;
                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                            esi = *esi;
                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            var_10 = 0x3;
                                            while (true) {
                                                    eax = sub_4878d3();
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (eax == 0xffffffff) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    edi = edi + eax;
                                                    if (var_10 > edi) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            if (temp_0 != 0x0) {
                                                    eax = *esi;
                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                    eax = *esi;
                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                            esi = *esi;
                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                    }
                                                    eax = ebx;
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = *esi;
                                                    sub_48664d(decomp_var_38);
                                                    esp = esp + 0x4;
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                            }
                    }
                    else {
                            if (eax == 0x5) {
                                    edi = 0x0;
                                    eax = sign_extend_32(var_2) - 0x1;
                                    if (eax != 0x0) {
                                            if (eax == 0x1) {
                                                    var_10 = 0x2;
                                                    while (true) {
                                                            eax = sub_4878d3();
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (eax == 0xffffffff) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            edi = edi + eax;
                                                            if (var_10 > edi) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    if (temp_0 != 0x0) {
                                                            eax = *esi;
                                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                            eax = *esi;
                                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                                    esi = *esi;
                                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                            }
                                                            eax = ebx;
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_38 = *esi;
                                                            sub_48664d(decomp_var_38);
                                                            esp = esp + 0x4;
                                                            eax = sub_47d812();
                                                            eax = *eax;
                                                    }
                                            }
                                            else {
                                                    eax = *esi;
                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                    eax = *esi;
                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                            esi = *esi;
                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            var_10 = 0x3;
                                            while (true) {
                                                    eax = sub_4878d3();
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (eax == 0xffffffff) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    edi = edi + eax;
                                                    if (var_10 > edi) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            if (temp_0 != 0x0) {
                                                    eax = *esi;
                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                    eax = *esi;
                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                            esi = *esi;
                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                    }
                                                    eax = ebx;
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = *esi;
                                                    sub_48664d(decomp_var_38);
                                                    esp = esp + 0x4;
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                            }
                            else {
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                    }
            }
            else {
                    edi = 0x0;
                    eax = sign_extend_32(var_2) - 0x1;
                    if (eax != 0x0) {
                            if (eax == 0x1) {
                                    var_10 = 0x2;
                                    while (true) {
                                            eax = sub_4878d3();
                                            esp = (esp - 0xc) + 0xc;
                                            if (eax == 0xffffffff) {
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            edi = edi + eax;
                                            if (var_10 > edi) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    if (temp_0 != 0x0) {
                                            eax = *esi;
                                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                            eax = *esi;
                                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                    esi = *esi;
                                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                            }
                                            eax = ebx;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_38 = *esi;
                                            sub_48664d(decomp_var_38);
                                            esp = esp + 0x4;
                                            eax = sub_47d812();
                                            eax = *eax;
                                    }
                            }
                            else {
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            var_10 = 0x3;
                            while (true) {
                                    eax = sub_4878d3();
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax == 0xffffffff) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    edi = edi + eax;
                                    if (var_10 > edi) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (temp_0 != 0x0) {
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_38 = *esi;
                                    sub_48664d(decomp_var_38);
                                    esp = esp + 0x4;
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
            }
    }
    else {
            eax = *esi;
            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
            eax = *esi;
            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                    esi = *esi;
                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
            }
            eax = ebx;
    }
    return eax;

.l72:
    if (eax == 0x80000000) goto .l63;
    goto .l60;

.l63:
    eax = sub_492524(*esi, &var_8, 0x3);
    esp = (esp - 0xc) + 0xc;
    switch (eax) {
        case -1:
            esp = esp - 0x4;
            decomp_var_38 = *esi;
            sub_48664d(decomp_var_38);
            esp = esp + 0x4;
            eax = sub_47d812();
            eax = *eax;
            break;
        case 2:
            eax = var_8 & 0xffff;
            if (eax == 0xfffe) {
                    sub_48664d(*esi);
                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                    *sub_47d812() = 0x16;
                    eax = 0x16;
            }
            else {
                    if (eax == 0xfeff) {
                            esp = (esp - 0xc) + 0xc;
                            if (sub_492ba2(*esi, 0x2, ebx) != 0xffffffff) {
                                    var_2 = 0x2;
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_38 = *esi;
                                    sub_48664d(decomp_var_38);
                                    esp = esp + 0x4;
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
                    else {
                            eax = sub_492ba2(*esi, ebx, ebx);
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0xffffffff) {
                                    esp = esp - 0x4;
                                    decomp_var_38 = *esi;
                                    sub_48664d(decomp_var_38);
                                    esp = esp + 0x4;
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                            else {
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                    }
            }
            break;
        default:
            if (eax == 0x3) {
                    if (var_8 == 0xbfbbef) {
                            var_2 = 0x1;
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
                    else {
                            eax = var_8 & 0xffff;
                            if (eax == 0xfffe) {
                                    sub_48664d(*esi);
                                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                                    *sub_47d812() = 0x16;
                                    eax = 0x16;
                            }
                            else {
                                    if (eax == 0xfeff) {
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_492ba2(*esi, 0x2, ebx) != 0xffffffff) {
                                                    var_2 = 0x2;
                                                    eax = *esi;
                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                    eax = *esi;
                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                            esi = *esi;
                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                    }
                                                    eax = ebx;
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = *esi;
                                                    sub_48664d(decomp_var_38);
                                                    esp = esp + 0x4;
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                    }
                                    else {
                                            eax = sub_492ba2(*esi, ebx, ebx);
                                            esp = (esp - 0xc) + 0xc;
                                            if (eax == 0xffffffff) {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = *esi;
                                                    sub_48664d(decomp_var_38);
                                                    esp = esp + 0x4;
                                                    eax = sub_47d812();
                                                    eax = *eax;
                                            }
                                            else {
                                                    eax = *esi;
                                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                                    eax = *esi;
                                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                                            esi = *esi;
                                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                            }
                    }
            }
            else {
                    eax = sub_492ba2(*esi, ebx, ebx);
                    esp = (esp - 0xc) + 0xc;
                    if (eax == 0xffffffff) {
                            esp = esp - 0x4;
                            decomp_var_38 = *esi;
                            sub_48664d(decomp_var_38);
                            esp = esp + 0x4;
                            eax = sub_47d812();
                            eax = *eax;
                    }
                    else {
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
            }
            break;
    }
    return eax;

.l60:
    if (eax != 0xc0000000) goto .l40;

.l67:
    eax = var_10;
    if (eax <= ebx) goto .l40;

.l66:
    if (eax <= 0x2) goto .l26;
    goto .l59;

.l26:
    edi = 0x0;
    eax = sign_extend_32(var_2) - 0x1;
    if (eax != 0x0) {
            if (eax == 0x1) {
                    var_10 = 0x2;
                    while (true) {
                            eax = sub_4878d3();
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0xffffffff) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            edi = edi + eax;
                            if (var_10 > edi) {
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    if (temp_0 != 0x0) {
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_38 = *esi;
                            sub_48664d(decomp_var_38);
                            esp = esp + 0x4;
                            eax = sub_47d812();
                            eax = *eax;
                    }
            }
            else {
                    eax = *esi;
                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                    eax = *esi;
                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                            esi = *esi;
                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                    }
                    eax = ebx;
            }
    }
    else {
            var_10 = 0x3;
            while (true) {
                    eax = sub_4878d3();
                    esp = (esp - 0xc) + 0xc;
                    if (eax == 0xffffffff) {
                            temp_0 = 0x0;
                            break;
                    }
                    edi = edi + eax;
                    if (var_10 > edi) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
            if (temp_0 != 0x0) {
                    eax = *esi;
                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                    eax = *esi;
                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                            esi = *esi;
                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                    }
                    eax = ebx;
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_38 = *esi;
                    sub_48664d(decomp_var_38);
                    esp = esp + 0x4;
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    return eax;

.l59:
    if (eax <= 0x4) goto .l68;
    goto .l75;

.l68:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, 0x2) | edx) == 0x0) goto .l27;
    goto .l61;

.l75:
    if (eax == 0x5) {
            edi = 0x0;
            eax = sign_extend_32(var_2) - 0x1;
            if (eax != 0x0) {
                    if (eax == 0x1) {
                            var_10 = 0x2;
                            while (true) {
                                    eax = sub_4878d3();
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax == 0xffffffff) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    edi = edi + eax;
                                    if (var_10 > edi) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (temp_0 != 0x0) {
                                    eax = *esi;
                                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                                    eax = *esi;
                                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                            esi = *esi;
                                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                                    }
                                    eax = ebx;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_38 = *esi;
                                    sub_48664d(decomp_var_38);
                                    esp = esp + 0x4;
                                    eax = sub_47d812();
                                    eax = *eax;
                            }
                    }
                    else {
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
            }
            else {
                    var_10 = 0x3;
                    while (true) {
                            eax = sub_4878d3();
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0xffffffff) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            edi = edi + eax;
                            if (var_10 > edi) {
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    if (temp_0 != 0x0) {
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_38 = *esi;
                            sub_48664d(decomp_var_38);
                            esp = esp + 0x4;
                            eax = sub_47d812();
                            eax = *eax;
                    }
            }
    }
    else {
            eax = *esi;
            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
            eax = *esi;
            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                    esi = *esi;
                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
            }
            eax = ebx;
    }
    return eax;

.l27:
    edi = 0x0;
    eax = sign_extend_32(var_2) - 0x1;
    if (eax != 0x0) {
            if (eax == 0x1) {
                    var_10 = 0x2;
                    while (true) {
                            eax = sub_4878d3();
                            esp = (esp - 0xc) + 0xc;
                            if (eax == 0xffffffff) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            edi = edi + eax;
                            if (var_10 > edi) {
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    if (temp_0 != 0x0) {
                            eax = *esi;
                            eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                            *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                            eax = *esi;
                            ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                            if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                                    esi = *esi;
                                    eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                                    *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                            }
                            eax = ebx;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_38 = *esi;
                            sub_48664d(decomp_var_38);
                            esp = esp + 0x4;
                            eax = sub_47d812();
                            eax = *eax;
                    }
            }
            else {
                    eax = *esi;
                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                    eax = *esi;
                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                            esi = *esi;
                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                    }
                    eax = ebx;
            }
    }
    else {
            var_10 = 0x3;
            while (true) {
                    eax = sub_4878d3();
                    esp = (esp - 0xc) + 0xc;
                    if (eax == 0xffffffff) {
                            temp_0 = 0x0;
                            break;
                    }
                    edi = edi + eax;
                    if (var_10 > edi) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
            if (temp_0 != 0x0) {
                    eax = *esi;
                    eax = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x24;
                    *(int8_t *)eax = *(int8_t *)eax ^ (*(int8_t *)eax ^ var_2) & 0x7f;
                    eax = *esi;
                    ecx = *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                    *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) = arg_8 >> 0x10 << 0x7 | *(int8_t *)(ecx + (eax & 0x1f) * 0x28 + 0x24) & 0x7f;
                    if (var_3 == ebx && (arg_8 & 0x8) != 0x0) {
                            esi = *esi;
                            eax = *((SAR(esi, 0x5)) * 0x4 + dword_bc7240);
                            *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) = *(int8_t *)(eax + (esi & 0x1f) * 0x28 + 0x4) | 0x20;
                    }
                    eax = ebx;
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_38 = *esi;
                    sub_48664d(decomp_var_38);
                    esp = esp + 0x4;
                    eax = sub_47d812();
                    eax = *eax;
            }
    }
    return eax;

.l61:
    esp = (esp - 0x10) + 0x10;
    if ((sub_48df70(*esi, ebx, ebx, ebx) & edx) == 0xffffffff) goto .l15;
    goto .l63;

.l15:
    esp = esp - 0x4;
    decomp_var_38 = *esi;
    sub_48664d(decomp_var_38);
    esp = esp + 0x4;
    eax = sub_47d812();
    eax = *eax;
    return eax;
}
