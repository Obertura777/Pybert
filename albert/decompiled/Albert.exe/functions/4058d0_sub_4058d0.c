// sub_4058d0 @ 0x4058d0
// hopper name: sub_4058d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4058d0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_64 = ebx;
    decomp_var_68 = ebp;
    decomp_var_6c = esi;
    ebp = ecx + 0x24e8;
    decomp_var_70 = edi;
    sub_4019f0(*(ecx[0x93b] + 0x4));
    ret_addr[0x1] = ret_addr;
    *ret_addr = ret_addr;
    ret_addr[0x2] = ret_addr;
    var_58 = ecx + 0x24f4;
    sub_401950(*(*(ecx + 0x24f8) + 0x4));
    eax = *(ecx + 0x24f8);
    eax[0x1] = eax;
    eax = *(ecx + 0x24f8);
    *(ecx + 0x24fc) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x24f8);
    edi[0x2] = edi;
    var_54 = ecx + 0x2500;
    sub_401950(*(ecx[0x941] + 0x4));
    eax = *(ecx + 0x2504);
    eax[0x1] = eax;
    eax = *(ecx + 0x2504);
    *(ecx + 0x2508) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x2504);
    edi[0x2] = edi;
    var_50 = ecx + 0x250c;
    sub_401950(*(ecx[0x944] + 0x4));
    eax = *(ecx + 0x2510);
    eax[0x1] = eax;
    eax = *(ecx + 0x2510);
    *(ecx + 0x2514) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x2510);
    edi[0x2] = edi;
    sub_401a30(*(ecx[0x947] + 0x4));
    eax = *(ecx + 0x251c);
    eax[0x1] = eax;
    eax = *(ecx + 0x251c);
    *(ecx + 0x2520) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x251c);
    edi[0x2] = edi;
    sub_401950(*(ecx[0x94a] + 0x4));
    eax = *(ecx + 0x2528);
    eax[0x1] = eax;
    eax = *(ecx + 0x2528);
    *(ecx + 0x252c) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x2528);
    edi[0x2] = edi;
    sub_401950(*(ecx[0x94d] + 0x4));
    eax = *(ecx + 0x2534);
    eax[0x1] = eax;
    eax = *(ecx + 0x2534);
    *(ecx + 0x2538) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x2534);
    edi[0x2] = edi;
    sub_401950(*(ecx[0x950] + 0x4));
    eax = *(ecx + 0x2540);
    eax[0x1] = eax;
    eax = *(ecx + 0x2540);
    *(ecx + 0x2544) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x2540);
    edi[0x2] = edi;
    esp = esp - 0x94;
    sub_401950(*(ecx[0x953] + 0x4));
    eax = *(ecx + 0x254c);
    eax[0x1] = eax;
    eax = *(ecx + 0x254c);
    *(ecx + 0x2550) = 0x0;
    *eax = eax;
    edi = *(ecx + 0x254c);
    eax = ecx + 0x2450;
    edi[0x2] = edi;
    esi = *eax[0x1];
    edi = eax;
    var_4C = eax;
    var_48 = edi;
    var_44 = esi;
    goto loc_405a86;

loc_405a86:
    var_34 = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            eax = sub_47a948();
    }
    if (esi != var_34) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x10] = esi[0x8];
            eax = *(esi[0x12] + 0x4);
            edi = esi + 0x44;
            var_5C = eax;
            var_60 = eax;
            if (eax[0x11] == 0x0) {
                    do {
                            sub_401950(var_60[0x2]);
                            var_60 = *var_60;
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            var_5C = var_60;
                    } while (var_60[0x11] == 0x0);
            }
            eax = edi[0x1];
            eax[0x1] = eax;
            eax = edi[0x1];
            edi[0x2] = 0x0;
            *eax = eax;
            edi = edi[0x1];
            edi[0x2] = edi;
            eax = esi[0x8];
            eax = eax - 0x2;
            esi[0x14] = 0x0;
            esi[0x54] = 0x0;
            esi[0x64] = 0x0;
            esi[0x65] = 0x0;
            esi[0x66] = 0x0;
            esi[0x67] = 0x0;
            esi[0x68] = 0x0;
            esi[0x69] = 0x0;
            esi[0x6a] = 0x0;
            esi[0x6b] = 0x0;
            esi[0x16] = 0xffffffff;
            esi[0x6c] = 0x0;
            if (eax > 0x4) {
                    sub_401390();
                    esi = var_44;
                    eax = var_4C;
                    edi = var_48;
                    continue;
            }
            if (*(eax * 0x4 + switch_table) != 0x0) {
                    switch (*(eax * 0x4 + switch_table)) {
                        case 1:
                            if (esi == var_48[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_74 = esi + 0xc;
                            esp = esp - 0x8;
                            decomp_var_78 = &var_24;
                            break;
                        case 2:
                            if (esi == var_48[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_74 = esi + 0xc;
                            esp = esp - 0x8;
                            decomp_var_78 = &var_18;
                            break;
                        default:
                            if (esi == var_48[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_74 = esi + 0xc;
                            esp = esp - 0x8;
                            decomp_var_78 = &var_C;
                            break;
                    }
                    sub_404ce0(decomp_var_78, decomp_var_74, decomp_var_70);
            }
            else {
                    if (esi == var_48[0x1]) {
                            sub_47a948();
                    }
                    var_40 = esi[0x9];
                    esp = esp - 0x8;
                    eax = sub_405120(&var_30, &var_40, decomp_var_70);
            }
            sub_401390();
            esi = var_44;
            eax = var_4C;
            edi = var_48;
            continue;
    }
    break;
    &var_60 = decomp_var_68;
    return eax;
}
