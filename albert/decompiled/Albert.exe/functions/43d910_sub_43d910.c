// sub_43d910 @ 0x43d910
// hopper name: sub_43d910
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_43d910() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_80 = ebx;
    decomp_var_84 = ebp;
    decomp_var_88 = esi;
    decomp_var_8c = edi;
    esp = esp - 0x8c;
    decomp_var_90 = *dword_4c8db8 ^ &decomp_var_8c;
    *0x0 = &decomp_var_10;
    edi = ecx;
    sub_465870();
    sub_465870();
    eax = edi[0x2];
    esi = 0x0;
    if (eax[0x901] <= 0x0) goto loc_43d9bd;
    goto loc_43d977;

loc_43d9bd:
    eax = edi[0x2];
    esi = *eax[0x915];
    ecx = eax + 0x2450;
    decomp_var_6c = ecx;
    decomp_var_68 = esi;
    goto loc_43d9e0;

loc_43d977:
    ecx = eax[0x900];
    while (true) {
            if (ecx > 0x0) {
                    sub_43d990();
            }
            esi = esi + 0x1;
            if (esi < *(edi[0x2] + 0x2404)) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0) goto .l1;
    goto .l2;

loc_43d9e0:
    eax = edi[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (ecx == 0x0 || ecx != eax) {
            sub_47a948();
    }
    if (esi == ebp) goto .l19;
    goto loc_43da03;

.l1:
    return;

.l2:
    eax = edi[0x2];
    esi = *eax[0x915];
    ecx = eax + 0x2450;
    decomp_var_6c = ecx;
    decomp_var_68 = esi;
    goto .l16;

.l19:
    break;

loc_43da03:
    decomp_var_78 = 0x0;
    if (*(edi[0x2] + 0x2404) > 0x0) {
            ebx = 0x0;
            ebp = edi + 0x4000;
            do {
                    if (decomp_var_6c == 0x0) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    *((esi[0x3] + ebx) * 0x4 + 0xb8ff68) = *sub_41c1e0(esi + 0x10);
                    ebp = &arg_8;
                    ebx = ebx + 0x100;
                    bool_68 = decomp_var_78 + 0x1 < *(edi[0x2] + 0x2404);
                    decomp_var_78 = decomp_var_78 + 0x1;
            } while (bool_68);
    }
    ebx = decomp_var_6c;
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_78 = sub_4075b0(esi + 0x14, decomp_var_90);
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x6];
    edx = esi[0x3];
    ecx = esi[0x3];
    edx = *((edx + (eax << 0x8)) * 0x4 + 0xb8ff68);
    ecx = ecx + (eax << 0x8);
    eax = decomp_var_78;
    *(ecx * 0x4 + 0xb8ab68) = edx;
    ebx = *eax[0x1];
    ebp = eax;
    decomp_var_64 = ebp;
    decomp_var_60 = ebx;
    goto loc_43db00;

.l16:
    eax = edi[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (ecx == 0x0 || ecx != eax) {
            sub_47a948();
    }
    if (esi == ebp) goto .l15;
    goto .l13;
    eax = 0xbaed7c;
    decomp_var_74 = 0xbaed7c;
    decomp_var_70 = **dword_baed80;
    goto .l8;

loc_43db00:
    decomp_var_50 = eax[0x1];
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (ebx != decomp_var_50) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            edx = *(eax * 0x8 + 0x4d2610);
            ebx = *(eax * 0x8 + 0x4d2e10);
            decomp_var_74 = eax;
            eax = *(eax * 0x8 + 0x4d3610);
            ecx = 0x0;
            if (eax >= 0x0) {
                    ecx = esi[0x6];
                    ecx = *((ecx * 0x15 + eax) * 0x8 + 0x4d5528);
            }
            if (edx >= 0x0) {
                    ecx = *((esi[0x6] * 0x15 + edx) * 0x8 + 0x4d5528);
            }
            if (ebx >= 0x0) {
                    ecx = esi[0x6];
                    ecx = *((ecx * 0x15 + ebx) * 0x8 + 0x4d5528);
            }
            if (ecx != 0x0) {
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            if (esi == decomp_var_6c[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_41c1e0(&decomp_var_74);
            ecx = eax;
            eax = *(((esi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb8ab68);
            ebx = ecx[0x1];
            bool_72 = ebx > (eax & 0x80000000 ? 0xffffffff : 0x0);
            if (ebx < (eax & 0x80000000 ? 0xffffffff : 0x0)) {
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            if (bool_72) {
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&decomp_var_74);
                    *(((esi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb8ab68) = *eax;
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            if (*ecx > eax) {
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&decomp_var_74);
                    *(((esi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb8ab68) = *eax;
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            sub_40f400();
            ebx = decomp_var_60;
            ebp = decomp_var_64;
            eax = decomp_var_78;
            continue;
    }
    break;

.l15:
    break;

.l13:
    decomp_var_78 = 0x0;
    if (*(edi[0x2] + 0x2404) > 0x0) {
            ebx = 0x0;
            ebp = edi + 0x4000;
            do {
                    if (decomp_var_6c == 0x0) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    *((esi[0x3] + ebx) * 0x4 + 0xb8ff68) = *sub_41c1e0(esi + 0x10);
                    ebp = &arg_8;
                    ebx = ebx + 0x100;
                    bool_116 = decomp_var_78 + 0x1 < *(edi[0x2] + 0x2404);
                    decomp_var_78 = decomp_var_78 + 0x1;
            } while (bool_116);
    }
    ebx = decomp_var_6c;
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_78 = sub_4075b0(esi + 0x14, decomp_var_90);
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x6];
    edx = esi[0x3];
    ecx = esi[0x3];
    edx = *((edx + (eax << 0x8)) * 0x4 + 0xb8ff68);
    ecx = ecx + (eax << 0x8);
    eax = decomp_var_78;
    *(ecx * 0x4 + 0xb8ab68) = edx;
    ebx = *eax[0x1];
    ebp = eax;
    decomp_var_64 = ebp;
    decomp_var_60 = ebx;
    goto .l17;

.l8:
    if (eax == 0x0 || eax != 0xbaed7c) {
            sub_47a948();
    }
    if (decomp_var_70 != *dword_baed80) {
            ebx = 0x0;
            if (*(edi[0x2] + 0x2404) <= 0x0) {
                    sub_40f380();
                    eax = decomp_var_74;
                    continue;
            }
            esi = decomp_var_70 + 0x14;
            ebp = edi + 0x4000;
            do {
                    if (decomp_var_74 == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_70 == decomp_var_74[0x1]) {
                            sub_47a948();
                    }
                    esi[0x15] = 0x0;
                    if (decomp_var_70 == decomp_var_74[0x1]) {
                            sub_47a948();
                    }
                    if (decomp_var_70 == decomp_var_74[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    *esi = *sub_41c1e0(decomp_var_70 + 0xc);
                    ebx = ebx + 0x1;
                    esi = esi + 0x4;
                    ebp = &arg_8;
            } while (ebx < *(edi[0x2] + 0x2404));
            sub_40f380();
            eax = decomp_var_74;
            continue;
    }
    break;
    sub_401390();
    esi = decomp_var_68;
    ecx = decomp_var_6c;
    continue;
    eax = 0xbaed7c;
    decomp_var_74 = 0xbaed7c;
    decomp_var_70 = **dword_baed80;
    goto loc_43dc64;

.l17:
    decomp_var_50 = eax[0x1];
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (ebx != decomp_var_50) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            edx = *(eax * 0x8 + 0x4d2610);
            ebx = *(eax * 0x8 + 0x4d2e10);
            decomp_var_74 = eax;
            eax = *(eax * 0x8 + 0x4d3610);
            ecx = 0x0;
            if (eax >= 0x0) {
                    ecx = esi[0x6];
                    ecx = *((ecx * 0x15 + eax) * 0x8 + 0x4d5528);
            }
            if (edx >= 0x0) {
                    ecx = *((esi[0x6] * 0x15 + edx) * 0x8 + 0x4d5528);
            }
            if (ebx >= 0x0) {
                    ecx = esi[0x6];
                    ecx = *((ecx * 0x15 + ebx) * 0x8 + 0x4d5528);
            }
            if (ecx != 0x0) {
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            if (esi == decomp_var_6c[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_41c1e0(&decomp_var_74);
            ecx = eax;
            eax = *(((esi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb8ab68);
            ebx = ecx[0x1];
            bool_105 = ebx > (eax & 0x80000000 ? 0xffffffff : 0x0);
            if (ebx < (eax & 0x80000000 ? 0xffffffff : 0x0)) {
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            if (bool_105) {
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&decomp_var_74);
                    *(((esi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb8ab68) = *eax;
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            if (*ecx > eax) {
                    if (esi == decomp_var_6c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&decomp_var_74);
                    *(((esi[0x6] << 0x8) + esi[0x3]) * 0x4 + 0xb8ab68) = *eax;
                    sub_40f400();
                    ebx = decomp_var_60;
                    ebp = decomp_var_64;
                    eax = decomp_var_78;
                    continue;
            }
            sub_40f400();
            ebx = decomp_var_60;
            ebp = decomp_var_64;
            eax = decomp_var_78;
            continue;
    }
    break;
    eax = edi[0x2];
    esi = eax + 0x2450;
    ebp = *eax[0x915];
    decomp_var_6c = esi;
    decomp_var_68 = ebp;
    &decomp_var_90 = &decomp_var_90;
    goto .l12;

loc_43dc64:
    if (eax == 0x0 || eax != 0xbaed7c) {
            sub_47a948();
    }
    if (decomp_var_70 != *dword_baed80) {
            ebx = 0x0;
            if (*(edi[0x2] + 0x2404) <= 0x0) {
                    sub_40f380();
                    eax = decomp_var_74;
                    continue;
            }
            esi = decomp_var_70 + 0x14;
            ebp = edi + 0x4000;
            do {
                    if (decomp_var_74 == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_70 == decomp_var_74[0x1]) {
                            sub_47a948();
                    }
                    esi[0x15] = 0x0;
                    if (decomp_var_70 == decomp_var_74[0x1]) {
                            sub_47a948();
                    }
                    if (decomp_var_70 == decomp_var_74[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    *esi = *sub_41c1e0(decomp_var_70 + 0xc);
                    ebx = ebx + 0x1;
                    esi = esi + 0x4;
                    ebp = &arg_8;
            } while (ebx < *(edi[0x2] + 0x2404));
            sub_40f380();
            eax = decomp_var_74;
            continue;
    }
    break;
    sub_401390();
    esi = decomp_var_68;
    ecx = decomp_var_6c;
    continue;

.l12:
    eax = edi[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
                    if (ebp == esi[0x1]) {
                            sub_47a948();
                    }
            }
            esp = esp - 0x4;
            eax = sub_41c270(&arg_c);
            *(eax + arg_14 * 0x4 + 0x54) = 0x1e;
            sub_401390();
            ebp = decomp_var_68;
            esi = decomp_var_6c;
            continue;
    }
    break;
    eax = edi[0x2];
    esi = eax + 0x2450;
    ebp = *eax[0x915];
    decomp_var_6c = esi;
    decomp_var_68 = ebp;
    &decomp_var_90 = &decomp_var_90;
    goto loc_43dd40;
    eax = 0x0;
    if (*(edi[0x2] + 0x2404) > 0x0) {
            if (*(eax * 0x4 + dword_623990) != 0x0) {
                    *(eax * 0x4 + 0xb954d0) = 0x0;
            }
            eax = eax + 0x1;
            if (eax < *(edi[0x2] + 0x2404)) {
                    continue;
            }
            break;
    }
    decomp_var_78 = 0x0;
    if (*(edi[0x2] + 0x2404) <= 0x0) goto loc_43df74;
    goto loc_43dde8;

loc_43dd40:
    eax = edi[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
                    if (ebp == esi[0x1]) {
                            sub_47a948();
                    }
            }
            esp = esp - 0x4;
            eax = sub_41c270(&arg_c);
            *(eax + arg_14 * 0x4 + 0x54) = 0x1e;
            sub_401390();
            ebp = decomp_var_68;
            esi = decomp_var_6c;
            continue;
    }
    break;

loc_43df74:
    sub_465fa0();
    sub_465fa0();
    *0x0 = decomp_var_10;
    &decomp_var_7c = decomp_var_84;
    return;

loc_43dde8:
    esi = 0xbbf4b8;
    decomp_var_74 = 0xbbf4b8;
    goto loc_43ddf1;
    eax = 0x0;
    if (*(edi[0x2] + 0x2404) > 0x0) {
            do {
                    if (*(eax * 0x4 + dword_623990) != 0x0) {
                            *(eax * 0x4 + 0xb954d0) = 0x0;
                    }
                    eax = eax + 0x1;
            } while (eax < *(edi[0x2] + 0x2404));
    }
    decomp_var_78 = 0x0;
    if (*(edi[0x2] + 0x2404) <= 0x0) goto .l3;
    goto .l7;

loc_43ddf1:
    sub_460be0(decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78);
    eax = sub_466f80(&decomp_var_54, 0xbc1e0c);
    sub_465ff0(eax);
    sub_465fa0();
    esp = esp - 0x10;
    eax = sub_465ff0(&decomp_var_44);
    eax = edi[0x2];
    ebp = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_6c = ebp;
    decomp_var_68 = esi;
    goto loc_43de60;

.l3:
    sub_465fa0();
    sub_465fa0();
    *0x0 = decomp_var_10;
    &decomp_var_7c = decomp_var_84;
    return;

.l7:
    esi = 0xbbf4b8;
    decomp_var_74 = 0xbbf4b8;
    goto .l10;

loc_43de60:
    eax = edi[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            if (esi[0x6] == decomp_var_78) {
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_460670(esi[0x3]);
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    eax = sub_463690(&decomp_var_64, esi + 0x10);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_466c40(&decomp_var_24, &decomp_var_34);
                    esp = esp - 0x18;
                    sub_465ff0(eax);
                    sub_465fa0();
            }
            sub_401390();
            esi = decomp_var_68;
            ebp = decomp_var_6c;
            continue;
    }
    break;

.l10:
    sub_460be0(decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78);
    eax = sub_466f80(&decomp_var_54, 0xbc1e0c);
    sub_465ff0(eax);
    sub_465fa0();
    esp = esp - 0x10;
    eax = sub_465ff0(&decomp_var_44);
    eax = edi[0x2];
    ebp = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_6c = ebp;
    decomp_var_68 = esi;
    goto .l11;
    esp = esp - 0x4;
    eax = sub_465ff0(&decomp_var_44);
    esi = decomp_var_74 + 0x10;
    bool_5 = decomp_var_78 + 0x1 < *(edi[0x2] + 0x2404);
    decomp_var_78 = decomp_var_78 + 0x1;
    decomp_var_74 = esi;
    if (bool_5) {
            continue;
    }
    break;

.l11:
    eax = edi[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            if (esi[0x6] == decomp_var_78) {
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_460670(esi[0x3]);
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    eax = sub_463690(&decomp_var_64, esi + 0x10);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_466c40(&decomp_var_24, &decomp_var_34);
                    esp = esp - 0x18;
                    sub_465ff0(eax);
                    sub_465fa0();
            }
            sub_401390();
            esi = decomp_var_68;
            ebp = decomp_var_6c;
            continue;
    }
    break;
    esp = esp - 0x4;
    eax = sub_465ff0(&decomp_var_44);
    esi = decomp_var_74 + 0x10;
    bool_36 = decomp_var_78 + 0x1 < *(edi[0x2] + 0x2404);
    decomp_var_78 = decomp_var_78 + 0x1;
    decomp_var_74 = esi;
    if (bool_36) {
            continue;
    }
    break;
}
