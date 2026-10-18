// sub_407d00 @ 0x407d00
// hopper name: sub_407d00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_407d00() {
    &saved_fp = &saved_fp & 0xfffffff8;
    eax = ecx[0x915];
    decomp_var_2c = ebx;
    ebx = ecx + 0x2450;
    decomp_var_30 = ebp;
    decomp_var_34 = esi;
    esi = *eax;
    esp = esp - 0x38;
    decomp_var_38 = edi;
    var_28 = ecx;
    var_18 = ebx;
    var_14 = esi;
    goto loc_407d30;

loc_407d30:
    ebp = var_28[0x915];
    edi = var_28 + 0x2450;
    if (ebx == 0x0 || ebx != edi) {
            eax = sub_47a948();
    }
    if (esi == ebp) goto .l22;
    goto loc_407d55;

.l22:
    break;

loc_407d55:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x8];
    esi = esi + 0x10;
    eax = eax - 0x1;
    if (eax > 0x5) {
            esi[0xc] = 0x1;
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    if (*(eax * 0x4 + 0x4080d0) == 0x0) {
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    if (*(eax * 0x4 + 0x4080d0) == 0x1) {
            decomp_var_40 = esi[0x5];
            esp = esp - 0xc;
            if (sub_460b30(esi, decomp_var_40) == 0x0) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c606c;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    if (*(eax * 0x4 + 0x4080d0) == 0x2) {
            edi = sub_407720(esi + 0x1c);
            esp = esp - 0xc;
            decomp_var_40 = esi;
            var_20 = edi;
            if (sub_460a10(decomp_var_40, *edi) == 0x0) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c606c;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            if (*edi == *esi) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c606c;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    if (*(eax * 0x4 + 0x4080d0) == 0x3) {
            esp = esp - 0x8;
            decomp_var_40 = esi;
            if (sub_460a10(decomp_var_40, esi[0x8]) == 0x0) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c606c;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            eax = *var_20;
            if (eax == *esi) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c606c;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    if (*(eax * 0x4 + 0x4080d0) == 0x4) {
            esp = esp - 0x4;
            eax = sub_407720(esi + 0x1c);
            if (*(int16_t *)word_4c602c != esi[0x6]) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c6090;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            ecx = *esi;
            if (*(int8_t *)(var_28 + (ecx + ecx * 0x8) * 0x4 + 0x4) != 0x0) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c6074;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            if (*(int16_t *)word_4c6028 != eax[0x6]) {
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c6088;
                    eax = sub_401390();
                    esi = var_14;
                    ebx = var_18;
                    continue;
            }
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    if (*(int16_t *)word_4c6028 == esi[0x6]) goto loc_407f89;
    goto loc_407f2b;
    &var_28 = decomp_var_30;
    return eax;

loc_407f89:
    eax = esi[0xa];
    edx = *esi;
    ebx = *eax;
    var_1C = edx;
    var_C = ebx;
    goto loc_407f98;

loc_407f2b:
    esi[0xc] = 0x1;
    esi[0x5c] = 0x1;
    esi[0x2f] = *(int16_t *)word_4c6088;
    goto loc_407f41;

loc_407f98:
    ebp = esi[0xa];
    eax = esi + 0x24;
    edi = eax;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            decomp_var_40 = &var_8;
            eax = sub_402060(decomp_var_40, ebx + 0x8, decomp_var_38, decomp_var_34, decomp_var_30);
            edi = *eax;
            ebp = eax[0x1];
            ebx = *(var_28 + 0x2454);
            if (edi == 0x0 || edi != var_28 + 0x2450) {
                    sub_47a948();
            }
            if (ebp == ebx) {
                    var_24 = 0x0;
                    esi[0xc] = 0x1;
                    esi[0x5c] = 0x1;
                    esi[0x2f] = *(int16_t *)word_4c6090;
            }
            else {
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                    }
                    var_24 = &arg_8;
                    if (&arg_8 == 0x0) {
                            esi[0xc] = 0x1;
                            esi[0x5c] = 0x1;
                            esi[0x2f] = *(int16_t *)word_4c6090;
                    }
                    else {
                            edx = var_24;
                            eax = *edx;
                            if (*(int8_t *)(var_28 + (eax + eax * 0x8) * 0x4 + 0x4) != 0x0) {
                                    esi[0xc] = 0x1;
                                    esi[0x5c] = 0x1;
                                    esi[0x2f] = *(int16_t *)word_4c6074;
                            }
                            else {
                                    esp = esp - 0x8;
                                    decomp_var_40 = edx;
                                    if (sub_460a10(decomp_var_40, var_1C) == 0x0) {
                                            esi[0xc] = 0x1;
                                            esi[0x5c] = 0x1;
                                            esi[0x2f] = *(int16_t *)word_4c606c;
                                    }
                            }
                    }
            }
            edi = var_C;
            if (edi == esi[0xa]) {
                    sub_47a948();
            }
            edx = *edi;
            var_C = edx;
            ebx = edx;
            continue;
    }
    break;

loc_407f41:
    if (esi[0x5c] != 0x0) {
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    esp = esp - 0x8;
    decomp_var_40 = var_24;
    if (sub_460a10(decomp_var_40, esi[0x8]) == 0x0) {
            esi[0xc] = 0x1;
            esi[0x5c] = 0x1;
            esi[0x2f] = *(int16_t *)word_4c606c;
    }
    if (esi[0x5c] != 0x0) {
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    eax = esi[0x5];
    if (eax == *esi) {
            esi[0xc] = 0x1;
            esi[0x5c] = 0x1;
            esi[0x2f] = *(int16_t *)word_4c606c;
            eax = sub_401390();
            esi = var_14;
            ebx = var_18;
            continue;
    }
    eax = sub_401390();
    esi = var_14;
    ebx = var_18;
    continue;
}
