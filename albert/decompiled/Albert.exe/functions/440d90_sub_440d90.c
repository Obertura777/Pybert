// sub_440d90 @ 0x440d90
// hopper name: sub_440d90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_440d90() {
    ebp = ecx;
    ebx = 0x0;
    eax = sub_407720(&arg_4);
    esp = esp - 0x3c;
    esi = eax;
    eax = sub_407720(&arg_8);
    var_1C = eax;
    if (*(int16_t *)word_4c6c08 == esi[0x2]) {
            ebx = 0x1;
    }
    sub_4607f0(arg_4, arg_8, arg_c);
    esp = esp - 0x10;
    decomp_var_38 = esi;
    esi = arg_0;
    edi = ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4) + ((arg_4 << 0x4) - arg_4);
    edi[0x2ebb68] = 0x4;
    edi[0x2ebb69] = arg_8;
    edi[0x2ebb6a] = arg_c;
    var_14 = edi;
    edi[0x2ebb75] = 0x1;
    eax = sub_41c1e0(decomp_var_38);
    edi[0x2ebb6e] = *eax;
    edi[0x2ebb6f] = eax[0x1];
    if (ebx == 0x1) {
            edi[0x2ebb80] = 0x0;
            edi[0x2ebb81] = 0x0;
    }
    edi = arg_4;
    esp = esp - 0x8;
    sub_437510(esi, edi);
    ecx = var_1C[0x2];
    if (ecx != esi) {
            eax = esi * 0x15 + ecx;
            ecx = *(eax * 0x8 + 0x4d5528);
            eax = *(eax * 0x8 + 0x4d552c);
            if ((ecx | eax) == 0x0) {
                    ecx = arg_c;
                    *dword_633f14 = 0x1e;
                    *(ecx * 0x4 + 0xba3370) = 0x1;
            }
            else {
                    bool_8 = eax < 0x0;
                    if (eax <= 0x0) {
                            if (!bool_8) {
                                    if (ecx < 0x5) {
                                            ecx = arg_c;
                                            *dword_633f14 = 0xa;
                                            *(ecx * 0x4 + 0xba3370) = 0x1;
                                    }
                                    else {
                                            ecx = arg_c;
                                            *dword_633f14 = 0xfffffff6;
                                            *(ecx * 0x4 + 0xba3370) = 0x1;
                                    }
                            }
                            else {
                                    ecx = arg_c;
                                    *dword_633f14 = 0xa;
                                    *(ecx * 0x4 + 0xba3370) = 0x1;
                            }
                    }
                    else {
                            ecx = arg_c;
                            *dword_633f14 = 0xfffffff6;
                            *(ecx * 0x4 + 0xba3370) = 0x1;
                    }
            }
    }
    else {
            ecx = arg_c;
    }
    var_C = esi << 0x8;
    edx = *((esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + 0x5460e8);
    eax = (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi + (esi << 0x8) + edi;
    if (edx != eax[0x14d73a]) goto .l2;
    goto loc_440f1d;

.l2:
    esi = ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx);
    esi[0x2ebb76] = esi[0x2ebb76] + 0x1;
    goto loc_44128f;

loc_440f1d:
    if (eax[0x15183b] != eax[0x14d73b]) goto loc_44127b;
    goto loc_440f2f;

loc_44128f:
    if (esi[0x2ebb7c] == 0x1) {
            esi[0x2ebb7c] = 0x0;
            *(arg_2c * 0x4 + 0xba3770) = 0xffffffff;
    }
    return eax;

loc_44127b:
    esi = ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx) + ((ecx << 0x4) - ecx);
    esi[0x2ebb76] = esi[0x2ebb76] + 0x1;
    goto loc_44128f;

loc_440f2f:
    ebx = ebp;
    eax = ebx[0x2];
    edi = *eax[0x915];
    ebp = eax + 0x2450;
    var_11 = 0x1;
    arg_4 = ebp;
    goto loc_440f50;

loc_440f50:
    eax = ebx[0x2];
    esi = eax[0x915];
    eax = eax + 0x2450;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (edi == esi) goto .l24;
    goto loc_440f73;

.l24:
    break;

loc_440f73:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (edi == arg_0) {
            sub_47a948();
    }
    eax = edi[0x4];
    eax = eax + var_C;
    if (*(eax * 0x8 + 0x4f6ce8) != 0x1) goto .l5;
    goto loc_440f97;
    eax = arg_1c;
    esi = ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax);
    if (var_11 == 0x1) {
            esi[0x2ebb75] = esi[0x2ebb75] + 0x1;
            if (var_13 == 0x1) {
                    esp = esp - 0x4;
                    eax = sub_407720(&arg_1c);
                    eax = eax[0x2];
                    *(((eax << 0x8) + arg_18) * 0x4 + 0xba9770) = *(((eax << 0x8) + arg_18) * 0x4 + 0xba9770) + 0x2;
                    eax = ((eax << 0x8) + arg_18) * 0x4 + 0xba9770;
            }
    }
    else {
            esi[0x2ebb76] = esi[0x2ebb76] + 0x1;
    }
    goto loc_44128f;

.l5:
    if (edi == arg_0) {
            sub_47a948();
    }
    eax = edi[0x4];
    eax = eax + var_C;
    if (*(eax * 0x8 + 0x50bce8) != 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (edi == arg_0) {
            sub_47a948();
    }
    esi = edi + 0xc;
    esp = esp - 0x4;
    var_10 = sub_407720(esi);
    if (edi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    ebx = sub_4075b0(var_10 + 0x4, decomp_var_24);
    esi = *ebx[0x1];
    edi = ebx;
    arg_10 = 0x0;
    var_14 = 0x0;
    var_13 = 0x0;
    var_12 = 0x0;
    saved_fp = edi;
    arg_0 = esi;
    goto .l6;

loc_440f97:
    if (*(eax * 0x8 + 0x4f6cec) == 0x0) goto loc_440fce;
    goto loc_440fa1;

.l6:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_14) {
                    arg_10 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = arg_1c;
            if (esi[0x3] == eax || *var_10 == eax) {
                    var_14 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_18 && *var_10 == arg_1c) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = *(((var_10[0x2] << 0x8) + esi[0x3]) * 0x4 + 0xba4370);
                    eax = eax - *(((arg_1c << 0x4) - arg_1c) * 0x8 + 0xbaedd4);
                    if (eax == 0x1) {
                            var_13 = eax;
                    }
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_14) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = arg_1c;
            if (esi[0x3] == eax) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (*var_10 == eax) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + var_C;
            if (*(eax * 0x8 + 0x520ce8) != 0x1) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (*(eax * 0x8 + 0x520cec) != 0x0) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) == 0x4) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda8) == arg_1c) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi = esi[0x3];
                            if (*(((esi << 0x4) - esi) * 0x8 + 0xbaede0) == 0x1) {
                                    var_12 = 0x1;
                            }
                    }
            }
            sub_40f400();
            esi = arg_0;
            edi = saved_fp;
            continue;
    }
    break;

loc_440fce:
    if (edi == arg_0) {
            sub_47a948();
    }
    esi = edi + 0xc;
    esp = esp - 0x4;
    var_10 = sub_407720(esi);
    if (edi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    ebx = sub_4075b0(var_10 + 0x4, decomp_var_24);
    esi = *ebx[0x1];
    edi = ebx;
    arg_10 = 0x0;
    var_14 = 0x0;
    var_13 = 0x0;
    var_12 = 0x0;
    saved_fp = edi;
    arg_0 = esi;
    goto .l7;

loc_440fa1:
    if (edi == arg_0) {
            sub_47a948();
    }
    eax = edi[0x4];
    eax = eax + var_C;
    if (*(eax * 0x8 + 0x50bce8) != 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (edi == arg_0) {
            sub_47a948();
    }
    esi = edi + 0xc;
    esp = esp - 0x4;
    var_10 = sub_407720(esi);
    if (edi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    ebx = sub_4075b0(var_10 + 0x4, decomp_var_24);
    esi = *ebx[0x1];
    edi = ebx;
    arg_10 = 0x0;
    var_14 = 0x0;
    var_13 = 0x0;
    var_12 = 0x0;
    saved_fp = edi;
    arg_0 = esi;
    goto loc_441040;
    if (var_12 != 0x1) {
            if (arg_20 != 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    eax = var_4[0x2ebb78];
    if (eax == 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (eax != 0x2) {
            if (arg_20 != 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (arg_10 == 0x1) {
            if (var_14 == 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    sub_401390();
    edi = arg_18;
    ebp = arg_14;
    ebx = arg_4;
    continue;

.l7:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_14) {
                    arg_10 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = arg_1c;
            if (esi[0x3] == eax || *var_10 == eax) {
                    var_14 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_18 && *var_10 == arg_1c) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = *(((var_10[0x2] << 0x8) + esi[0x3]) * 0x4 + 0xba4370);
                    eax = eax - *(((arg_1c << 0x4) - arg_1c) * 0x8 + 0xbaedd4);
                    if (eax == 0x1) {
                            var_13 = eax;
                    }
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_14) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = arg_1c;
            if (esi[0x3] == eax) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (*var_10 == eax) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + var_C;
            if (*(eax * 0x8 + 0x520ce8) != 0x1) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (*(eax * 0x8 + 0x520cec) != 0x0) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) == 0x4) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda8) == arg_1c) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi = esi[0x3];
                            if (*(((esi << 0x4) - esi) * 0x8 + 0xbaede0) == 0x1) {
                                    var_12 = 0x1;
                            }
                    }
            }
            sub_40f400();
            esi = arg_0;
            edi = saved_fp;
            continue;
    }
    break;

loc_441040:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_14) {
                    arg_10 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = arg_1c;
            if (esi[0x3] == eax || *var_10 == eax) {
                    var_14 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_18 && *var_10 == arg_1c) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = *(((var_10[0x2] << 0x8) + esi[0x3]) * 0x4 + 0xba4370);
                    eax = eax - *(((arg_1c << 0x4) - arg_1c) * 0x8 + 0xbaedd4);
                    if (eax == 0x1) {
                            var_13 = eax;
                    }
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_14) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = arg_1c;
            if (esi[0x3] == eax) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (*var_10 == eax) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + var_C;
            if (*(eax * 0x8 + 0x520ce8) != 0x1) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (*(eax * 0x8 + 0x520cec) != 0x0) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) != 0x4) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda8) != arg_1c) {
                    sub_40f400();
                    esi = arg_0;
                    edi = saved_fp;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi[0x3];
            if (*(((esi << 0x4) - esi) * 0x8 + 0xbaede0) == 0x1) {
                    var_12 = 0x1;
            }
            sub_40f400();
            esi = arg_0;
            edi = saved_fp;
            continue;
    }
    break;
    if (var_12 != 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    eax = var_4[0x2ebb78];
    if (eax == 0x1) {
            if (arg_20 != 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (eax != 0x2) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (arg_10 == 0x1) {
            if (var_14 == 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            if (arg_20 != 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    sub_401390();
    edi = arg_18;
    ebp = arg_14;
    ebx = arg_4;
    continue;
    if (var_12 != 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    eax = var_4[0x2ebb78];
    if (eax == 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (eax != 0x2) {
            if (arg_20 != 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (arg_10 == 0x1) {
            if (var_14 == 0x1) {
                    sub_401390();
                    edi = arg_18;
                    ebp = arg_14;
                    ebx = arg_4;
                    continue;
            }
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    if (arg_20 != 0x1) {
            sub_401390();
            edi = arg_18;
            ebp = arg_14;
            ebx = arg_4;
            continue;
    }
    sub_401390();
    edi = arg_18;
    ebp = arg_14;
    ebx = arg_4;
    continue;
}
