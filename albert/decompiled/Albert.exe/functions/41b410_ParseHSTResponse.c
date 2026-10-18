// ParseHSTResponse @ 0x41b410
// hopper name: sub_41b410
// pybert name: ParseHSTResponse
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ParseHSTResponse() {
    decomp_var_c = *0x0;
    decomp_var_148 = ebx;
    decomp_var_14c = ebp;
    decomp_var_150 = esi;
    decomp_var_154 = edi;
    esp = esp - 0x158;
    decomp_var_158 = *dword_4c8db8 ^ &decomp_var_154;
    *0x0 = &decomp_var_c;
    decomp_var_124 = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    edi = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    esi = 0x0;
    decomp_var_13c = 0x0;
    decomp_var_138 = edi;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_110 = (*(*eax + 0xc))() + 0x10;
            sub_465870();
            eax = sub_466060(&decomp_var_134, 0x3);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&decomp_var_134, 0x0);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&decomp_var_134, 0x1);
            sub_465ff0(eax);
            sub_465fa0();
            esp = esp - 0x2c;
            eax = sub_465900(&decomp_var_142, 0x0);
            if (*(int16_t *)word_4c6d60 != *(int16_t *)eax) {
                    esp = esp - 0x8;
                    eax = sub_465900(&decomp_var_142, 0x1);
                    eax = *(int16_t *)eax;
                    esi = eax & 0xffff;
                    if ((eax & 0x2000) != 0x0) {
                            esi = esi | 0xffffe000;
                    }
            }
            bool_14 = *(int8_t *)byte_baed40 != 0x1;
            *dword_62a9dc = esi;
            if (!bool_14) {
                    *dword_62a9dc = 0x0;
            }
            eax = sub_466540(&decomp_var_10c, word_4c6d28);
            eax = sub_466480(&decomp_var_dc, word_4c6d90);
            eax = sub_466480(&decomp_var_fc, word_4c6d0c);
            eax = sub_466480(&decomp_var_120, word_4c6e14);
            eax = sub_466480(&decomp_var_ec, word_4c6d30);
            eax = sub_466480(&decomp_var_134, word_4c6cdc);
            esp = esp - 0x34;
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            if (*dword_62a9dc >= 0xa) {
                    eax = sub_466540(&decomp_var_9c, word_4c6d28);
                    eax = sub_466480(&decomp_var_bc, word_4c6d90);
                    eax = sub_466480(&decomp_var_8c, word_4c6d0c);
                    eax = sub_466480(&decomp_var_ac, word_4c6e14);
                    eax = sub_466480(&decomp_var_cc, word_4c6d30);
                    eax = sub_466480(&decomp_var_134, word_4c6cdc);
                    eax = sub_466480(&decomp_var_ec, word_4c6dcc);
                    eax = sub_466480(&decomp_var_120, word_4c6dc4);
                    eax = sub_466480(&decomp_var_fc, word_4c6d94);
                    eax = sub_466480(&decomp_var_dc, word_4c6d88);
                    eax = sub_466480(&decomp_var_10c, 0x4c6dec);
                    esp = esp - 0x5c;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
            }
            if (*dword_62a9dc >= 0x14) {
                    eax = sub_466540(&decomp_var_4c, word_4c6d28);
                    eax = sub_466480(&decomp_var_134, word_4c6d90);
                    eax = sub_466480(&decomp_var_ec, word_4c6d0c);
                    eax = sub_466480(&decomp_var_120, word_4c6e14);
                    eax = sub_466480(&decomp_var_fc, word_4c6d30);
                    eax = sub_466480(&decomp_var_dc, word_4c6cdc);
                    eax = sub_466480(&decomp_var_10c, word_4c6dcc);
                    eax = sub_466480(&decomp_var_cc, word_4c6dc4);
                    eax = sub_466480(&decomp_var_ac, word_4c6d94);
                    eax = sub_466480(&decomp_var_8c, word_4c6d88);
                    eax = sub_466480(&decomp_var_bc, 0x4c6dec);
                    esp = esp - 0x60;
                    eax = sub_466480(&decomp_var_9c, word_4c6df8);
                    esp = esp - 0x4;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
            }
            if (*dword_62a9dc >= 0x1e) {
                    eax = sub_466540(&decomp_var_3c, word_4c6d28);
                    eax = sub_466480(&decomp_var_2c, word_4c6d90);
                    eax = sub_466480(&decomp_var_134, word_4c6d0c);
                    sub_466480(&decomp_var_ec, word_4c6e14);
                    sub_466480(&decomp_var_120, word_4c6d30);
                    sub_466480(&decomp_var_fc, word_4c6cdc);
                    sub_466480(&decomp_var_dc, word_4c6dcc);
                    sub_466480(&decomp_var_10c, word_4c6dc4);
                    sub_466480(&decomp_var_cc, word_4c6d94);
                    sub_466480(&decomp_var_ac, word_4c6d88);
                    sub_466480(&decomp_var_8c, 0x4c6dec);
                    esp = esp - 0x60;
                    sub_466480(&decomp_var_bc, word_4c6df8);
                    sub_466480(&decomp_var_9c, word_4c6d8c);
                    eax = sub_466480(&decomp_var_4c, word_4c6dc0);
                    esp = esp - 0x14;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
            }
            if (*(int8_t *)byte_baed40 == 0x1) {
                    sub_466540(&decomp_var_2c, word_4c6d28);
                    eax = sub_466480(&decomp_var_3c, word_4c6d90);
                    esp = esp - 0x14;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
            }
            ebp = sub_465930();
            decomp_var_140 = 0x0;
            if (*(decomp_var_124[0x2] + 0x2404) > 0x0) {
                    esi = 0xbb6e10;
                    do {
                            ebx = *(esi[0x1] + 0x4);
                            edi = ebx;
                            if (ebx[0xf] == 0x0) {
                                    sub_410c30(edi[0x2]);
                                    edi = *edi;
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x4;
                                    ebx = edi;
                                    if (edi[0xf] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            eax = esi[0x1];
                            eax[0x1] = eax;
                            eax = esi[0x1];
                            edi = 0x0;
                            esi[0x2] = 0x0;
                            *eax = eax;
                            eax = esi[0x1];
                            eax[0x2] = eax;
                            if (ebp > 0x0) {
                                    do {
                                            eax = sub_465900(&decomp_var_142, edi);
                                            esp = esp - 0x10;
                                            eax = sub_418ed0(&decomp_var_134, eax, decomp_var_158);
                                            edi = edi + 0x1;
                                    } while (edi < ebp);
                            }
                            esi = esi + 0xc;
                            bool_15 = decomp_var_140 + 0x1 < *(decomp_var_124[0x2] + 0x2404);
                            decomp_var_140 = decomp_var_140 + 0x1;
                    } while (bool_15);
                    edi = decomp_var_138;
            }
            esp = esp - 0x8;
            *(int8_t *)byte_baed41 = 0x1;
            eax = sub_465900(&decomp_var_142, 0x0);
            if (*(int16_t *)word_4c6d68 != *(int16_t *)eax) {
                    esp = esp - 0x8;
                    eax = sub_465900(&decomp_var_142, 0x1);
                    eax = *(int16_t *)eax;
                    bool_5 = (eax & 0x2000) == 0x0;
                    eax = eax & 0xffff;
                    if (!bool_5) {
                            eax = eax | 0xffffe000;
                    }
                    decomp_var_13c = eax;
            }
            *dword_624ef4 = decomp_var_13c;
            sub_47b66b(sub_47b26f(0x0) + edi * 0x3e8);
            esp = (esp - 0x8) + 0x8;
            ecx = sub_47b678();
            esi = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x32;
            ecx = sub_47b678();
            edx = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x32;
            eax = *(int16_t *)word_4c6c1c & 0xffff;
            ecx = *(int16_t *)word_4c6c10;
            *(int16_t *)word_bbf686 = eax;
            eax = *(int16_t *)word_4c6c20 & 0xffff;
            *(int16_t *)word_bbf688 = ecx;
            *(int16_t *)word_bbf68c = eax;
            esi = esi + edx;
            *(int16_t *)word_bbf684 = *(int16_t *)word_4c6c18 & 0xffff;
            edx = *(int16_t *)word_4c6c14 & 0xffff;
            *dword_4c6bd4 = esi;
            *(int16_t *)word_bbf68a = edx;
            sub_465fa0();
            eax = decomp_var_110 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            sub_465fa0();
            sub_465fa0();
            eax = sub_465fa0();
            *0x0 = decomp_var_c;
    }
    return eax;
}
