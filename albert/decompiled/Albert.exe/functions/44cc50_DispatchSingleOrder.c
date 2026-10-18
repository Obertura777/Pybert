// DispatchSingleOrder @ 0x44cc50
// hopper name: sub_44cc50
// pybert name: DispatchSingleOrder
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

DispatchSingleOrder() {
    decomp_var_c = *0x0;
    decomp_var_80 = ebx;
    decomp_var_84 = ebp;
    decomp_var_88 = esi;
    decomp_var_8c = edi;
    esp = esp - 0x90;
    decomp_var_90 = *dword_4c8db8 ^ &decomp_var_8c;
    *0x0 = &decomp_var_c;
    esi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_50 = (*(*eax + 0xc))() + 0x10;
            sub_465870();
            sub_465870();
            sub_466060(&decomp_var_60, 0x0);
            sub_465900(&decomp_var_74, 0x0);
            sub_465fa0();
            sub_466060(&decomp_var_60, 0x0);
            eax = sub_465900(&decomp_var_7c, 0x1);
            ebp = *(int16_t *)eax;
            decomp_var_74 = ebp;
            sub_465fa0();
            eax = sub_466060(&decomp_var_70, 0x0);
            eax = sub_465900(&decomp_var_7c, 0x2);
            edi = *(int8_t *)eax & 0xff;
            sub_465fa0();
            esp = esp - 0x34;
            eax = sub_407720(&decomp_var_60);
            if (eax[0x4] == 0x0) {
                    decomp_var_60 = sub_465930();
                    eax = sub_466060(&decomp_var_2c, 0x1);
                    esp = esp - 0x10;
                    eax = sub_465900(&decomp_var_70, 0x0);
                    ecx = &decomp_var_2c;
                    decomp_var_7c = *(int16_t *)eax;
                    sub_465fa0();
                    eax = decomp_var_7c;
                    if (*(int16_t *)word_4c6c18 == eax) {
                            esp = esp - 0x8;
                            sub_440840(arg_0, edi);
                    }
                    else {
                            if (*(int16_t *)word_4c6c1c == eax) {
                                    decomp_var_94 = ecx;
                                    decomp_var_94 = ebp;
                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                    eax = sub_45fc30(&decomp_var_70, eax, decomp_var_94);
                                    ebp = *eax;
                                    sub_465fa0();
                                    eax = sub_402060(&decomp_var_60, &decomp_var_4c, decomp_var_90, decomp_var_8c, decomp_var_88);
                                    *dword_bb65b4 = *eax;
                                    *dword_bb65b8 = eax[0x1];
                                    decomp_var_98 = ebp;
                                    esp = esp - 0x2c;
                                    sub_44bbe0(arg_0, edi, decomp_var_98, decomp_var_48);
                            }
                            else {
                                    if (*(int16_t *)word_4c6c20 == eax) {
                                            ebx = 0x3;
                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            sub_466060(&decomp_var_4c, 0x2);
                                            sub_466060(&decomp_var_2c, 0x0);
                                            eax = sub_465900(&decomp_var_70, 0x0);
                                            sub_465fa0();
                                            sub_465fa0();
                                            esp = esp - 0x2c;
                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                            if (decomp_var_60 == 0x5) {
                                                    eax = sub_465900(&decomp_var_70, 0x2);
                                                    ebp = *(int8_t *)eax & 0xff;
                                                    sub_465fa0();
                                                    sub_466060(&decomp_var_2c, 0x4);
                                                    sub_465900(&decomp_var_70, 0x0);
                                                    sub_465fa0();
                                                    esp = esp - 0x28;
                                                    sub_440d90(arg_0, edi, ebp, decomp_var_60, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                                            }
                                            else {
                                                    eax = sub_465900(&decomp_var_70, 0x2);
                                                    ebp = *(int8_t *)eax & 0xff;
                                                    sub_465fa0();
                                                    esp = esp - 0x14;
                                                    sub_440900(arg_0, edi, ebp, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70);
                                            }
                                    }
                                    else {
                                            if (*(int16_t *)word_4c6c10 == eax) {
                                                    ebx = 0x3;
                                                    esi[0xa84] = eax | 0xffffffff;
                                                    esi[0xa85] = eax | 0xffffffff;
                                                    esi[0xa86] = eax | 0xffffffff;
                                                    sub_45abe0();
                                                    esp = (esp - 0x8) + 0x8 - 0x8;
                                                    eax = sub_466060(&decomp_var_2c, 0x4);
                                                    ebp = sub_465930();
                                                    ecx = &decomp_var_2c;
                                                    decomp_var_60 = ebp;
                                                    sub_465fa0();
                                                    if (ebp <= 0x3) {
                                                            ebp = 0x0;
                                                            if (decomp_var_60 > 0x0) {
                                                                    decomp_var_7c = esi + 0x2a10;
                                                                    do {
                                                                            eax = sub_466060(&decomp_var_2c, 0x4);
                                                                            esp = esp - 0x10;
                                                                            eax = sub_465900(&decomp_var_70, ebp);
                                                                            *decomp_var_7c = *(int8_t *)eax & 0xff;
                                                                            ecx = &decomp_var_2c;
                                                                            sub_465fa0();
                                                                            decomp_var_7c = decomp_var_7c + 0x4;
                                                                            ebp = &arg_fffffffffffffffd;
                                                                    } while (ebp < decomp_var_60);
                                                            }
                                                            decomp_var_94 = ecx;
                                                            decomp_var_94 = decomp_var_74;
                                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                                            eax = sub_45fc30(&decomp_var_7c, eax, decomp_var_94);
                                                            ebp = *eax;
                                                            sub_465fa0();
                                                            sub_461560(edi, ebp, decomp_var_60, esi + 0x2a10, decomp_var_90);
                                                            eax = sub_41c340(&decomp_var_4c);
                                                            *eax = edi;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaeda0) = 0x6;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaeda8) = ebp;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaedac) = decomp_var_48;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaedfc) = *(esi + (ebp + ebp * 0x4) * 0x4 + 0x214);
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaee08) = esi[0xa84];
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaee0c) = esi[0xa85];
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaee10) = esi[0xa86];
                                                            esp = esp - 0x2c;
                                                            *(((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + 0xbaedd4) = 0x1;
                                                            eax = sub_41c1e0(&decomp_var_4c);
                                                            *(((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + 0xbaedb8) = *eax;
                                                            *(((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + ((ebp << 0x4) - ebp) + 0xbaedbc) = eax[0x1];
                                                    }
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c6c14 == eax) {
                                                            sub_466060(&decomp_var_2c, 0x2);
                                                            eax = sub_465900(&decomp_var_70, 0x2);
                                                            ebp = *(int8_t *)eax & 0xff;
                                                            sub_465fa0();
                                                            sub_466060(&decomp_var_2c, 0x4);
                                                            sub_465900(&decomp_var_70, 0x0);
                                                            sub_465fa0();
                                                            sub_460880(edi, ebp, decomp_var_4c);
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaeda0) = 0x5;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaeda4) = ebp;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaeda8) = decomp_var_4c;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaedac) = decomp_var_48;
                                                            ebx = *(((arg_0 << 0x8) + edi) * 0x8 + 0x55b0e8);
                                                            ecx = *(((arg_0 << 0x8) + edi) * 0x8 + 0x55b0ec);
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaedd4) = 0x1;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaedb8) = ebx;
                                                            *(((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + ((edi << 0x4) - edi) + 0xbaedbc) = ecx;
                                                            esp = esp - 0x34;
                                                            sub_437510(arg_0, edi);
                                                    }
                                            }
                                    }
                            }
                    }
            }
            sub_465fa0();
            sub_465fa0();
            eax = decomp_var_50 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            eax = sub_465fa0();
            *0x0 = decomp_var_c;
    }
    return eax;
}
