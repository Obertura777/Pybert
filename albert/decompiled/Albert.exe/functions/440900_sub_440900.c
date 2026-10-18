// sub_440900 @ 0x440900
// hopper name: sub_440900
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_440900() {
    decomp_var_24 = ebx;
    ebx = ecx;
    var_18 = ebx;
    var_1F = 0x0;
    eax = sub_407720(&arg_4);
    esp = esp - 0x38;
    esi = eax;
    eax = sub_407720(&arg_8);
    var_1C = eax;
    if (*(int16_t *)word_4c6c08 == esi[0x2]) {
            var_1F = 0x1;
    }
    ebp = arg_4;
    sub_460770(ebp, arg_8);
    edi = ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp);
    esp = esp - 0xc;
    decomp_var_34 = esi;
    esi = arg_0;
    edi[0x2ebb68] = 0x3;
    edi[0x2ebb6a] = arg_8;
    var_14 = edi;
    edi[0x2ebb75] = 0x1;
    eax = sub_41c1e0(decomp_var_34);
    edi[0x2ebb6e] = *eax;
    edi[0x2ebb6f] = eax[0x1];
    if (var_1F == 0x1) {
            edi[0x2ebb80] = 0x0;
            edi[0x2ebb81] = 0x0;
    }
    esp = esp - 0x8;
    sub_437510(esi, ebp);
    ecx = var_1C[0x2];
    if (ecx != esi) {
            eax = esi * 0x15 + ecx;
            ecx = *(eax * 0x8 + 0x4d5528);
            eax = *(eax * 0x8 + 0x4d552c);
            if ((ecx | eax) == 0x0) {
                    edx = arg_8;
                    *dword_633f14 = 0x1e;
                    *(edx * 0x4 + 0xba3370) = 0x1;
            }
            else {
                    bool_7 = eax < 0x0;
                    if (eax <= 0x0) {
                            if (!bool_7) {
                                    if (ecx < 0x5) {
                                            edx = arg_8;
                                            *dword_633f14 = 0xa;
                                            *(edx * 0x4 + 0xba3370) = 0x1;
                                    }
                                    else {
                                            edx = arg_8;
                                            *dword_633f14 = 0xfffffff6;
                                            *(edx * 0x4 + 0xba3370) = 0x1;
                                    }
                            }
                            else {
                                    edx = arg_8;
                                    *dword_633f14 = 0xa;
                                    *(edx * 0x4 + 0xba3370) = 0x1;
                            }
                    }
                    else {
                            edx = arg_8;
                            *dword_633f14 = 0xfffffff6;
                            *(edx * 0x4 + 0xba3370) = 0x1;
                    }
            }
    }
    else {
            edx = arg_8;
    }
    var_10 = esi << 0x8;
    eax = (esi << 0x8) + ebp + (esi << 0x8) + ebp + (esi << 0x8) + ebp + (esi << 0x8) + ebp;
    ecx = *(eax + eax + 0x5460e8);
    esi = *(eax + eax + 0x5460ec);
    eax = eax + eax;
    if ((ecx | esi) != 0x0) goto loc_440a9f;
    goto loc_440a7f;

loc_440a9f:
    if (ecx != eax[0x14d73a] || esi != eax[0x14d73b]) goto loc_440d6c;
    goto loc_440ab7;

loc_440a7f:
    *(((edx << 0x4) - edx) * 0x8 + 0xbaedd4) = *(((edx << 0x4) - edx) * 0x8 + 0xbaedd4) + 0x1;
    eax = ((edx << 0x4) - edx) * 0x8 + 0xbaedd4;
    return eax;

loc_440d6c:
    *(((edx << 0x4) - edx) * 0x8 + 0xbaedd8) = *(((edx << 0x4) - edx) * 0x8 + 0xbaedd8) + 0x1;
    eax = ((edx << 0x4) - edx) * 0x8 + 0xbaedd8;
    return eax;

loc_440ab7:
    eax = ebx[0x2];
    esi = *eax[0x915];
    ebp = eax + 0x2450;
    arg_0 = ebp;
    goto loc_440ae0;
    return eax;

loc_440ae0:
    eax = ebx[0x2];
    edi = eax[0x915];
    eax = eax + 0x2450;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
            edx = arg_20;
    }
    if (esi == edi) goto .l20;
    goto loc_440b07;

.l20:
    break;

loc_440b07:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    eax = esi[0x4];
    eax = eax + var_4;
    if (*(eax * 0x8 + 0x4f6ce8) != 0x1) goto loc_440b35;
    goto loc_440b2b;
    if (var_5 != 0x1) {
            *(((edx << 0x4) - edx) * 0x8 + 0xbaedd8) = *(((edx << 0x4) - edx) * 0x8 + 0xbaedd8) + 0x1;
            eax = ((edx << 0x4) - edx) * 0x8 + 0xbaedd8;
    }
    else {
            *(((edx << 0x4) - edx) * 0x8 + 0xbaedd4) = *(((edx << 0x4) - edx) * 0x8 + 0xbaedd4) + 0x1;
            eax = ((edx << 0x4) - edx) * 0x8 + 0xbaedd4;
    }
    return eax;

loc_440b35:
    if (esi == arg_0) {
            sub_47a948();
    }
    eax = esi[0x4];
    eax = eax + var_4;
    if (*(eax * 0x8 + 0x50bce8) != 0x1) {
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0xc;
    esp = esp - 0x4;
    ebx = sub_407720(edi);
    if (esi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    var_1C = ebx + 0x4;
    ebx = sub_4075b0(var_1C, var_18);
    esi = *ebx[0x1];
    edi = ebx;
    arg_18 = 0x0;
    var_7 = 0x0;
    var_6 = 0x0;
    arg_4 = edi;
    arg_8 = esi;
    goto loc_440bc3;

loc_440b2b:
    if (*(eax * 0x8 + 0x4f6cec) == 0x0) goto loc_440b62;
    goto .l3;

loc_440bc3:
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
            ebp = arg_1c;
            if (esi[0x3] == ebp) {
                    arg_18 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_20) {
                    var_7 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == ebp) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_20) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + var_4;
            if (*(eax * 0x8 + 0x520ce8) != 0x1) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (*(eax * 0x8 + 0x520cec) != 0x0) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) != 0x3) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda8) != arg_20) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi[0x3];
            if (*(((esi << 0x4) - esi) * 0x8 + 0xbaede0) == 0x1) {
                    var_6 = 0x1;
            }
            sub_40f400();
            esi = arg_8;
            edi = arg_4;
            continue;
    }
    break;

loc_440b62:
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0xc;
    esp = esp - 0x4;
    ebx = sub_407720(edi);
    if (esi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    var_1C = ebx + 0x4;
    ebx = sub_4075b0(var_1C, var_18);
    esi = *ebx[0x1];
    edi = ebx;
    arg_18 = 0x0;
    var_7 = 0x0;
    var_6 = 0x0;
    arg_4 = edi;
    arg_8 = esi;
    goto .l6;

.l3:
    if (esi == arg_0) {
            sub_47a948();
    }
    eax = esi[0x4];
    eax = eax + var_4;
    if (*(eax * 0x8 + 0x50bce8) != 0x1) {
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0xc;
    esp = esp - 0x4;
    ebx = sub_407720(edi);
    if (esi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    var_1C = ebx + 0x4;
    ebx = sub_4075b0(var_1C, var_18);
    esi = *ebx[0x1];
    edi = ebx;
    arg_18 = 0x0;
    var_7 = 0x0;
    var_6 = 0x0;
    arg_4 = edi;
    arg_8 = esi;
    goto .l5;
    if (var_6 != 0x1) {
            if (arg_24 != 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    eax = arg_0[0x2ebb78];
    if (eax == 0x1) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (eax != 0x2) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (arg_18 == 0x1) {
            if (var_7 == 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
            if (arg_24 != 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
    }
    else {
            if (arg_24 == 0x1 && arg_1 == 0x0) {
                    if (0x0 == 0x0) {
                            ebx = arg_8;
                            sub_401390();
                            esi = arg_1c;
                            ebp = arg_18;
                            edx = arg_2c;
                            continue;
                    }
            }
    }
    ebx = arg_8;
    sub_401390();
    esi = arg_1c;
    ebp = arg_18;
    edx = arg_2c;
    continue;

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
            ebp = arg_1c;
            if (esi[0x3] == ebp) {
                    arg_18 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_20) {
                    var_7 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == ebp) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_20) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + var_4;
            if (*(eax * 0x8 + 0x520ce8) != 0x1) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (*(eax * 0x8 + 0x520cec) != 0x0) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) != 0x3) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda8) != arg_20) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi[0x3];
            if (*(((esi << 0x4) - esi) * 0x8 + 0xbaede0) == 0x1) {
                    var_6 = 0x1;
            }
            sub_40f400();
            esi = arg_8;
            edi = arg_4;
            continue;
    }
    break;

.l5:
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
            ebp = arg_1c;
            if (esi[0x3] == ebp) {
                    arg_18 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_20) {
                    var_7 = 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == ebp) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] == arg_20) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + var_4;
            if (*(eax * 0x8 + 0x520ce8) != 0x1) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (*(eax * 0x8 + 0x520cec) != 0x0) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda0) != 0x3) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(((eax << 0x4) - eax) * 0x8 + 0xbaeda8) != arg_20) {
                    sub_40f400();
                    esi = arg_8;
                    edi = arg_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi[0x3];
            if (*(((esi << 0x4) - esi) * 0x8 + 0xbaede0) == 0x1) {
                    var_6 = 0x1;
            }
            sub_40f400();
            esi = arg_8;
            edi = arg_4;
            continue;
    }
    break;
    if (var_6 != 0x1) {
            if (arg_24 != 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    eax = arg_0[0x2ebb78];
    if (eax == 0x1) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (eax != 0x2) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (arg_18 == 0x1) {
            if (var_7 == 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
    }
    else {
            if (arg_24 == 0x1 && arg_1 == 0x0) {
                    if (0x0 == 0x0) {
                            ebx = arg_8;
                            sub_401390();
                            esi = arg_1c;
                            ebp = arg_18;
                            edx = arg_2c;
                            continue;
                    }
            }
    }
    ebx = arg_8;
    sub_401390();
    esi = arg_1c;
    ebp = arg_18;
    edx = arg_2c;
    continue;
    if (var_6 != 0x1) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    eax = arg_0[0x2ebb78];
    if (eax == 0x1) {
            if (arg_24 != 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (eax != 0x2) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (arg_18 == 0x1) {
            if (var_7 == 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
            if (arg_24 != 0x1) {
                    ebx = arg_8;
                    sub_401390();
                    esi = arg_1c;
                    ebp = arg_18;
                    edx = arg_2c;
                    continue;
            }
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (arg_24 != 0x1) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (arg_1 != 0x0) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    if (0x0 == 0x0) {
            ebx = arg_8;
            sub_401390();
            esi = arg_1c;
            ebp = arg_18;
            edx = arg_2c;
            continue;
    }
    goto ;
}
