// sub_402360 @ 0x402360
// hopper name: sub_402360
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402360() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_34 = ebx;
    decomp_var_38 = ebp;
    ebx = ecx;
    decomp_var_3c = esi;
    esi = ebx + 0x245c;
    esp = esp - 0x40;
    var_40 = edi;
    edi = *ebx[0x918];
    var_30 = ebx;
    var_28 = esi;
    var_24 = edi;
    &var_40 = &var_40;
    goto loc_402390;

loc_402390:
    ebp = ebx[0x918];
    eax = ebx + 0x245c;
    if (esi == 0x0 || esi != eax) {
            eax = sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            edi = edi + 0x10;
            esi = edi + 0x14;
            decomp_var_48 = edi[0x5];
            esp = esp - 0xc;
            if (sub_460b30(edi, decomp_var_48) == 0x0) {
                    edi[0xc] = 0x1;
                    edi[0x5c] = 0x1;
                    edi[0x2f] = *(int16_t *)word_4c606c;
                    sub_401390();
                    edi = var_24;
                    esi = var_28;
                    continue;
            }
            ebp = ebx + 0x2548;
            var_1C = ebx[0x953];
            esp = esp - 0x8;
            decomp_var_48 = &var_10;
            ecx = sub_401ff0(decomp_var_48, esi, var_40, decomp_var_3c, decomp_var_38);
            eax = *ecx;
            var_2C = ecx;
            if (eax == 0x0 || eax != ebp) {
                    sub_47a948();
                    ecx = var_2C;
            }
            if (ecx[0x1] != var_1C) {
                    edi[0xc] = 0x1;
                    edi[0x5c] = 0x1;
                    edi[0x2f] = *(int16_t *)word_4c609c;
                    sub_401390();
                    edi = var_24;
                    esi = var_28;
                    continue;
            }
            ebp = ebx + 0x2450;
            var_14 = ebx[0x915];
            esp = esp - 0x8;
            decomp_var_48 = &var_8;
            ebx = sub_402060(decomp_var_48, esi, var_40, decomp_var_3c, decomp_var_38);
            eax = *ebx;
            if (eax == 0x0 || eax != ebp) {
                    sub_47a948();
            }
            if (ebx[0x1] != var_14) {
                    ebx = var_30;
                    edi[0xc] = 0x1;
                    edi[0x5c] = 0x1;
                    edi[0x2f] = *(int16_t *)word_4c609c;
                    sub_401390();
                    edi = var_24;
                    esi = var_28;
                    continue;
            }
            if (edi[0x14] == *esi) {
                    ebx = var_30;
                    edi[0xc] = 0x1;
                    edi[0x5c] = 0x1;
                    edi[0x2f] = *(int16_t *)word_4c609c;
                    sub_401390();
                    edi = var_24;
                    esi = var_28;
                    continue;
            }
            ebx = var_30;
            sub_401390();
            edi = var_24;
            esi = var_28;
            continue;
    }
    break;
    &var_30 = decomp_var_38;
    return eax;
}
