// sub_4418e0 @ 0x4418e0
// hopper name: sub_4418e0
// contains unmarked entry 0x441f73 (CommitMoveCandidatesPostPress)
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4418e0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_cc = ebx;
    decomp_var_d0 = ebp;
    decomp_var_d4 = esi;
    decomp_var_d8 = edi;
    decomp_var_dc = *dword_4c8db8 ^ &decomp_var_d8;
    *0x0 = &var_C;
    ebx = ecx;
    var_88 = ebx;
    eax = sub_4103b0();
    var_C0 = eax;
    eax[0x21] = 0x1;
    var_C0[0x1] = var_C0;
    *var_C0 = var_C0;
    var_C0[0x2] = var_C0;
    eax = sub_40ff50();
    var_AC = eax;
    eax[0x15] = 0x1;
    var_AC[0x1] = var_AC;
    *var_AC = var_AC;
    var_AC[0x2] = var_AC;
    var_A8 = 0x0;
    eax = ebx[0x2];
    eax = eax[0x2424] & 0xff;
    var_9C = eax;
    esp = esp - 0xe4;
    var_B1 = sub_40dda0(eax);
    sub_401950(*(*dword_bb7128 + 0x4));
    eax = *dword_bb7128;
    eax[0x1] = eax;
    eax = *dword_bb7128;
    *dword_bb712c = 0x0;
    *eax = eax;
    eax = *dword_bb7128;
    eax[0x2] = eax;
    var_B8 = 0x0;
    if (*(ebx[0x2] + 0x2404) <= 0x0) goto loc_441a82;
    goto loc_4419da;

loc_441a82:
    sub_41d270(ebx[0x2] + 0x24c0);
    edi = ebx + 0x4cfc;
    esp = esp - 0x8;
    var_A0 = *ebx[0x1340];
    sub_46db50();
    eax = sub_4273a0(decomp_var_e0);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    sub_45abe0();
    esp = (esp - 0x10) + 0x10;
    goto loc_441ae1;

loc_4419da:
    edi = 0xbb6f28;
    goto loc_4419e0;

loc_441ae1:
    esi = edi[0x1];
    if (edi == 0x0 || edi != edi) {
            sub_47a948();
    }
    if (var_A0 == esi) goto .l27;
    goto loc_441afb;

loc_4419e0:
    if (var_B8 == var_9C || (*(var_B8 * 0x8 + 0x4cf568) | *(var_B8 * 0x8 + 0x4cf56c)) != 0x0) goto loc_441a63;
    goto loc_4419fe;

.l27:
    break;

loc_441afb:
    eax = var_C0;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x21] == 0x0) {
            do {
                    sub_40faf0(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = var_C0;
    }
    eax[0x1] = eax;
    var_BC = 0x0;
    *var_C0 = var_C0;
    esi = ebx + 0x4cfc;
    var_C0[0x2] = var_C0;
    if (esi == 0x0) {
            sub_47a948();
    }
    edi = var_A0;
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esi = sub_407720(edi + 0x10);
    esp = esp - 0x8;
    sub_46db50();
    eax = sub_4273a0(decomp_var_e0);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    sub_45abe0();
    ebp = *esi[0x19];
    eax = esi + 0x60;
    edi = eax;
    esp = (esp - 0xc) + 0xc;
    var_B8 = eax;
    var_90 = edi;
    var_8C = ebp;
    goto loc_441bc4;

loc_441a63:
    edi = edi + 0xc;
    bool_64 = var_B8 + 0x1 < *(ebx[0x2] + 0x2404);
    var_B8 = var_B8 + 0x1;
    if (bool_64) {
            continue;
    }
    break;

loc_4419fe:
    esi = edi;
    ebp = *edi[0x1];
    var_A4 = esi;
    var_A0 = ebp;
    goto loc_441a10;
    sub_405190(&var_84, &var_B0, *var_AC, &var_B0, var_AC);
    sub_47c8f9();
    sub_4150e0(&var_84, &var_C4, *var_C0, &var_C4, var_C0);
    eax = sub_47c8f9();
    *0x0 = var_C;
    &decomp_var_c8 = decomp_var_d0;
    return eax;

loc_441bc4:
    esi = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebp != esi) {
            var_4C = *dword_bb7128;
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            esi = &arg_4;
            esp = esp - 0x8;
            eax = sub_401ff0(&var_48, esi, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != 0xbb7124) {
                    sub_47a948();
            }
            if (ebx[0x1] != var_4C) {
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                    }
                    var_68 = 0x0;
                    decomp_var_e0 = &var_68;
                    esp = esp - 0x8;
                    decomp_var_e4 = &var_1C;
            }
            else {
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                            if (ebp == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    var_78 = *sub_41c1e0(esi);
                    decomp_var_e0 = &var_78;
                    esp = esp - 0xc;
                    decomp_var_e4 = &var_28;
            }
            sub_41a010(decomp_var_e4, decomp_var_e0, decomp_var_dc);
            sub_40f400();
            ebp = var_8C;
            edi = var_90;
            ebx = var_88;
            eax = var_B8;
            continue;
    }
    break;

loc_441a10:
    var_8C = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (ebp != var_8C) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&var_84, &arg_4, decomp_var_dc);
            sub_401520();
            ebp = var_A0;
            esi = var_A4;
            continue;
    }
    break;
    esi = *var_C0;
    if (esi != var_C0) {
            esp = esp - 0x4;
            sub_46db50();
            eax = sub_4273a0(decomp_var_e0);
            if (eax[0x6] >= 0x10) {
                    edi = eax[0x1];
            }
            else {
                    edi = eax + 0x4;
            }
            if (esi == var_C0) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_46db50();
            eax = sub_4273a0(decomp_var_e0);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            sub_45abe0();
            esp = (esp - 0x10) + 0x10;
            var_98 = &var_C4;
            var_94 = esi;
            sub_40f6f0();
            ebp = var_98;
            edi = var_C0;
            if (ebp == 0x0 || ebp != &var_C4) {
                    sub_47a948();
            }
            if (var_94 != edi) {
                    if (esi == var_C0) {
                            sub_47a948();
                    }
                    if ((esi[0x4] | esi[0x5]) != 0x0) {
                            if (ebp == 0x0) {
                                    sub_47a948();
                            }
                            if (var_94 == ret_addr) {
                                    sub_47a948();
                            }
                            if (esi == var_C0) {
                                    sub_47a948();
                            }
                            if (var_94 == ret_addr) {
                                    sub_47a948();
                            }
                            if (esi == var_C0) {
                                    sub_47a948();
                            }
                            if (var_94 == ret_addr) {
                                    sub_47a948();
                            }
                    }
            }
            var_C5 = 0x1;
            if (esi == var_C0) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_402140(&var_30, esi + 0x18, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            ecx = *eax;
            edi = var_AC;
            *dword_bb65ac = ecx;
            *dword_bb65b0 = eax[0x1];
            if (ecx == 0x0 || ecx != &var_B0) {
                    sub_47a948();
            }
            if (*dword_bb65b0 != edi) {
                    sub_45abe0();
                    esp = (esp - 0x8) + 0x8 - 0xc;
                    var_C5 = 0x0;
                    eax = sub_412800(&var_38, &var_C4, esi, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, var_C4, var_C0, var_BC, var_B8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4);
            }
            if (var_B1 == 0x1) {
                    if (esi == var_C0) {
                            sub_47a948();
                    }
                    eax = esi[0x6];
                    bool_57 = *(eax * 0x8 + 0x4d2614) > 0x0;
                    bool_27 = *(eax * 0x8 + 0x4d2614) < 0x0;
                    ecx = *(eax * 0x8 + 0x4d2610);
                    if (!bool_27) {
                            if (!bool_57) {
                                    if (ecx >= 0x0) {
                                            bool_53 = *((var_9C * 0x15 + ecx) * 0x8 + 0x4d552c) < 0x0;
                                            bool_40 = *((var_9C * 0x15 + ecx) * 0x8 + 0x4d552c) > 0x0;
                                            ecx = *((var_9C * 0x15 + ecx) * 0x8 + 0x4d5528);
                                            if (!bool_53) {
                                                    if (bool_40) {
                                                            sub_45abe0();
                                                            esp = (esp - 0x8) + 0x8 - 0xc;
                                                            eax = sub_412800(&var_40, &var_C4, esi, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, var_C4, var_C0, var_BC, var_B8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4);
                                                            continue;
                                                    }
                                                    if (ecx > 0x0) {
                                                            sub_45abe0();
                                                            esp = (esp - 0x8) + 0x8 - 0xc;
                                                            eax = sub_412800(&var_40, &var_C4, esi, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, var_C4, var_C0, var_BC, var_B8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4);
                                                            continue;
                                                    }
                                                    if (var_C5 == 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    if (var_C5 == 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (var_C5 == 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                            else {
                                    bool_59 = *((var_9C * 0x15 + ecx) * 0x8 + 0x4d552c) > 0x0;
                                    bool_43 = *((var_9C * 0x15 + ecx) * 0x8 + 0x4d552c) < 0x0;
                                    ecx = *((var_9C * 0x15 + ecx) * 0x8 + 0x4d5528);
                                    if (!bool_43) {
                                            if (bool_59) {
                                                    sub_45abe0();
                                                    esp = (esp - 0x8) + 0x8 - 0xc;
                                                    eax = sub_412800(&var_40, &var_C4, esi, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, var_C4, var_C0, var_BC, var_B8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4);
                                                    continue;
                                            }
                                            if (ecx > 0x0) {
                                                    sub_45abe0();
                                                    esp = (esp - 0x8) + 0x8 - 0xc;
                                                    eax = sub_412800(&var_40, &var_C4, esi, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, var_C4, var_C0, var_BC, var_B8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4);
                                                    continue;
                                            }
                                            if (var_C5 == 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    else {
                                            if (var_C5 == 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                    }
                    else {
                            if (var_C5 == 0x0) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
            }
            else {
                    if (var_C5 == 0x0) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
    }
    else {
            temp_0 = 0x1;
            break;
    }
    goto .l2;

.l2:
    if (temp_0 != 0x0) {
            ebp = var_A0;
            edi = ebx + 0x4cfc;
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            sub_460910(arg_8);
            sub_45abe0();
            esp = (esp - 0xc) + 0x8;
    }
    else {
            decomp_var_e4 = ebx;
            sub_45abe0();
            esp = (esp - 0x8) + 0x8;
            if (esi == var_C0) {
                    sub_47a948();
            }
            ebp = var_A0;
            esp = esp - 0x8;
            decomp_var_e4 = esi[0x6];
            var_B8 = esi + 0x18;
            decomp_var_e0 = *(int16_t *)(esi + 0x1c);
            edi = ebx + 0x4cfc;
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_460980(arg_8, decomp_var_e4, decomp_var_e0);
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            if (esi == var_C0) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            *sub_41c340(var_B8) = arg_8;
    }
    esp = esp - 0xc;
    eax = sub_411cf0(&var_84, edi, ebp, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, var_C4, var_C0, var_BC, var_B8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4);
    *dword_baed34 = *dword_baed34 + 0x1;
    var_A0 = *edi[0x1];
    continue;
}
