// sub_41f5a0 @ 0x41f5a0
// hopper name: sub_41f5a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41f5a0() {
    var_C = *0x0;
    decomp_var_e0 = esi;
    decomp_var_e4 = edi;
    var_E8 = *dword_4c8db8 ^ &decomp_var_e4;
    *0x0 = &var_C;
    edi = ecx;
    var_A8 = edi;
    esi = 0x0;
    *(int16_t *)arg_0 = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_401e30();
    var_C8 = eax;
    eax[0x11] = 0x1;
    var_C8[0x1] = var_C8;
    *var_C8 = var_C8;
    var_C8[0x2] = var_C8;
    var_D1 = 0x1;
    var_BC = *(int8_t *)(edi[0x2] + 0x2424) & 0xff;
    eax = sub_466480(&var_A0, &arg_14);
    sub_465ff0(eax);
    sub_465fa0();
    var_D2 = 0x1;
    eax = sub_466480(&var_A0, &arg_14);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_A0, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_A0, 0x2);
    esp = esp - 0x118;
    sub_465ff0(eax);
    sub_465fa0();
    ebp = sub_465930();
    var_A4 = ebp;
    ebx = sub_465930();
    var_90 = ebx;
    var_AC = sub_465930();
    if (ebx > 0x0) {
            do {
                    eax = sub_465900(&var_B2, esi);
                    var_B0 = *(int8_t *)eax & 0xff;
                    esp = esp - 0x10;
                    eax = sub_404ce0(&var_A0, &var_B0, var_E8);
                    esi = esi + 0x1;
            } while (esi < ebx);
    }
    var_C0 = 0x0;
    if (*(edi[0x2] + 0x2404) <= 0x0) goto loc_41f88e;
    goto loc_41f7ca;

loc_41f88e:
    esi = 0x0;
    var_B0 = 0x0;
    if (ebp <= 0x0) goto loc_41fafa;
    goto loc_41f89c;

loc_41f7ca:
    var_B8 = 0x0;
    goto loc_41f7ce;

loc_41fafa:
    ecx = arg_14 & 0xff;
    eax = var_BC * 0x15 + ecx;
    bool_16 = *(eax * 0x8 + 0x4d552c) > 0x0;
    bool_2 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (!bool_16) {
            if (!bool_2) {
                    if (*(eax * 0x8 + 0x4d5528) < 0x2 && ebp > 0x2) {
                            var_D2 = 0x0;
                    }
            }
            else {
                    if (ebp > 0x2) {
                            var_D2 = 0x0;
                    }
            }
    }
    if (var_D1 == 0x0) {
            if (ebp > 0x2) {
                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d90;
            }
            else {
                    bool_20 = ebx != 0x1;
                    if (ebx > 0x1) {
                            edi = var_C8;
                            var_BC = ecx;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&var_A0, &var_BC, var_E8, decomp_var_e4, decomp_var_e0);
                            esi = eax;
                            eax = *esi;
                            if (eax == 0x0 || eax != &var_CC) {
                                    sub_47a948();
                            }
                            bool_14 = esi[0x1] != edi;
                            if (esi[0x1] != edi) {
                                    if (!bool_14) {
                                            edi = var_C8;
                                            var_BC = arg_14 & 0xff;
                                            esp = esp - 0x8;
                                            eax = sub_401ff0(&var_A0, &var_BC, var_E8, decomp_var_e4, decomp_var_e0);
                                            esi = eax;
                                            eax = *esi;
                                            if (eax == 0x0 || eax != &var_CC) {
                                                    sub_47a948();
                                            }
                                            if (esi[0x1] == edi) {
                                                    *(int16_t *)arg_0 = *(int16_t *)word_4c6d90;
                                            }
                                            else {
                                                    if (var_D2 == 0x1) {
                                                            *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
                                                    }
                                                    else {
                                                            *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                                                    }
                                            }
                                    }
                                    else {
                                            if (var_D2 == 0x1) {
                                                    *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
                                            }
                                            else {
                                                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                                            }
                                    }
                            }
                            else {
                                    *(int16_t *)arg_0 = *(int16_t *)word_4c6d90;
                            }
                    }
                    else {
                            if (!bool_20) {
                                    edi = var_C8;
                                    var_BC = arg_14 & 0xff;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_A0, &var_BC, var_E8, decomp_var_e4, decomp_var_e0);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax != 0x0) {
                                            if (eax != &var_CC) {
                                                    sub_47a948();
                                            }
                                            if (esi[0x1] == edi) {
                                                    *(int16_t *)arg_0 = *(int16_t *)word_4c6d90;
                                            }
                                            else {
                                                    if (var_D2 == 0x1) {
                                                            *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
                                                    }
                                                    else {
                                                            *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (esi[0x1] == edi) {
                                                    *(int16_t *)arg_0 = *(int16_t *)word_4c6d90;
                                            }
                                            else {
                                                    if (var_D2 == 0x1) {
                                                            *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
                                                    }
                                                    else {
                                                            *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (var_D2 == 0x1) {
                                            *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
                                    }
                                    else {
                                            *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                                    }
                            }
                    }
            }
    }
    else {
            if (var_D2 == 0x1) {
                    *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
            }
            else {
                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
            }
    }
    sub_403430(&var_78, &var_A4, *var_A0, &var_A4, var_A0);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = arg_28;
    *0x0 = arg_18;
    return eax;

loc_41f89c:
    &var_E8 = &var_E8;
    goto loc_41f8a0;

loc_41f7ce:
    ebp = 0x0;
    if (var_AC <= 0x0) goto loc_41f86b;
    goto loc_41f7da;

loc_41f8a0:
    esp = esp - 0x8;
    eax = sub_465900(&var_B2, esi);
    ebx = *(int8_t *)eax & 0xff;
    eax = 0x0;
    var_C0 = ebx;
    var_A8 = 0x0;
    if (var_AC <= 0x0) goto loc_41fae1;
    goto loc_41f8c6;

loc_41f86b:
    var_B8 = var_B8 + 0xc;
    bool_29 = var_C0 + 0x1 < *(edi[0x2] + 0x2404);
    var_C0 = var_C0 + 0x1;
    if (bool_29) {
            continue;
    }
    break;

loc_41f7da:
    edi = var_B8 + 0xbb7028;
    goto loc_41f7e4;

loc_41fae1:
    esi = esi + 0x1;
    var_B0 = esi;
    if (esi < var_A4) {
            continue;
    }
    break;

loc_41f8c6:
    esp = esp - 0x8;
    eax = sub_465900(&var_B8, eax);
    var_D0 = *(int8_t *)eax & 0xff;
    if (ebx != var_BC) {
            if (ebx == (arg_14 & 0xff)) {
                    esi = ebx + ebx * 0x2 + ebx + ebx * 0x2 + ebx + ebx * 0x2 + ebx + ebx * 0x2;
                    edi = esi + 0xbb7028;
                    var_40 = esi[0x2edc0b];
                    esp = esp - 0x8;
                    eax = sub_401ff0(&var_3C, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
                    eax = *eax;
                    if (eax == 0x0 || eax != edi) {
                            sub_47a948();
                    }
                    if (arg_0 == var_40) {
                            ebp = esi[0x2edbcb];
                            esi = esi + 0xbb6f28;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&var_34, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
                            edi = eax;
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] == ebp) {
                                    var_D1 = 0x0;
                            }
                    }
            }
            esi = ebx + ebx * 0x2 + ebx + ebx * 0x2 + ebx + ebx * 0x2 + ebx + ebx * 0x2;
            edi = esi + 0xbb7028;
            var_48 = esi[0x2edc0b];
            esp = esp - 0x8;
            eax = sub_401ff0(&var_24, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
            eax = *eax;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (arg_0 != var_48) {
                    ebp = esi + 0xbb6f28;
                    esp = esp - 0x8;
                    var_88 = esi[0x2edbcb];
                    eax = sub_401ff0(&var_14, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
                    ebx = eax;
                    eax = *ebx;
                    if (eax == 0x0 || eax != ebp) {
                            sub_47a948();
                    }
                    if (ebx[0x1] != var_88) {
                            ebp = var_C8;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&var_1C, &var_C0, var_E8, decomp_var_e4, decomp_var_e0);
                            ebx = eax;
                            eax = *ebx;
                            if (eax == 0x0 || eax != &var_CC) {
                                    sub_47a948();
                            }
                            if (ebx[0x1] == ebp) {
                                    var_D2 = 0x0;
                            }
                    }
                    ebx = var_C0;
            }
            esp = esp - 0x8;
            var_80 = edi[0x1];
            eax = sub_401ff0(&var_2C, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
            eax = *eax;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (arg_0 != var_80) {
                    ebp = esi[0x2edbcb];
                    esi = esi + 0xbb6f28;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&var_A0, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            eax = sub_47a948();
                    }
                    if (edi[0x1] == ebp) {
                            asm { fld        dword [dword_value_1077936128] };
                            asm { fcomp      dword [byte_4c6bdc+4] };
                            asm { fnstsw     ax };
                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                    var_D2 = 0x0;
                            }
                    }
            }
    }
    eax = var_A8 + 0x1;
    var_A8 = eax;
    if (eax < var_AC) {
            continue;
    }
    break;
    ebp = var_A4;
    goto loc_41f88e;

loc_41f7e4:
    eax = sub_465900(&var_B2, ebp);
    eax = *(int8_t *)eax & 0xff;
    ebx = edi[0x1];
    esp = esp - 0x10;
    var_D0 = eax;
    eax = sub_401ff0(&var_84, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != edi) {
            sub_47a948();
    }
    if (esi[0x1] == ebx) {
            esi = var_B8 + 0xbb6f28;
            if (esi == 0x0) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_8C, &var_D0, var_E8, decomp_var_e4, decomp_var_e0);
            eax = *eax;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
    }
    ebp = &arg_fffffffffffffffd;
    if (ebp < var_AC) {
            continue;
    }
    break;
    ebx = var_90;
    ebp = var_A4;
    goto loc_41fafa;
    esi = var_B0;
    goto loc_41fae1;
    edi = var_A8;
    ebx = var_90;
    goto loc_41f86b;
}
