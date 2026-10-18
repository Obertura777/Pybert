// ExecuteThennAction @ 0x439c30
// hopper name: sub_439c30
// pybert name: ExecuteThennAction
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ExecuteThennAction() {
    decomp_var_20 = esi;
    esi = arg_0;
    decomp_var_24 = edi;
    edi = ecx;
    ebp = *(int8_t *)(edi[0x2] + 0x2424) & 0xff;
    esp = esp - 0x28;
    decomp_var_28 = esi;
    var_14 = edi;
    eax = sub_4117d0(decomp_var_28);
    if (eax != 0x0) goto .l1;
    goto loc_439c61;

.l1:
    return eax;

loc_439c61:
    esp = esp - 0x4;
    decomp_var_28 = ebx;
    if (*dword_62a9dc < 0xa) goto loc_439cc2;
    goto loc_439c6b;

loc_439cc2:
    bool_24 = *((ebp * 0x15 + esi) * 0x8 + 0x4d552c) < 0x0;
    bool_5 = *((ebp * 0x15 + esi) * 0x8 + 0x4d552c) > 0x0;
    ebx = (ebp * 0x15 + esi) * 0x8 + 0x4d5528;
    if (bool_24 || !bool_5 && *ebx < 0x3) goto loc_439cfe;
    goto loc_439ce1;

loc_439c6b:
    ebx = *((esi + esi * 0x2) * 0x4 + dword_bb6e14);
    edi = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
    decomp_var_2c = word_4c6dc4;
    esp = esp - 0x8;
    eax = sub_4108a0(&var_8, word_4c6dc4, decomp_var_28, decomp_var_24, decomp_var_20);
    eax = *eax;
    if (eax == 0x0 || eax != edi) {
            eax = sub_47a948();
    }
    if (arg_0 == ebx) goto loc_439cba;
    goto loc_439ca4;

loc_439cfe:
    if (*(int8_t *)byte_baed68 == 0x1) {
            if (*dword_62a9dc >= 0xa) {
                    edi = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                    esp = esp - 0xc;
                    var_14 = edi;
                    eax = sub_4108a0(&var_C, word_4c6d88, &var_14, decomp_var_2c, decomp_var_28);
                    eax = sub_401050(decomp_var_30);
                    if (eax != 0x0) {
                            esp = esp - 0xc;
                            var_14 = edi;
                            eax = sub_4108a0(&var_C, 0x4c6dec, &var_14, decomp_var_2c, decomp_var_28);
                            eax = sub_401050(decomp_var_30);
                            if (eax != 0x0) {
                                    esp = esp - 0x4;
                                    eax = sub_4325a0(esi);
                                    var_19 = eax;
                            }
                    }
                    edi = var_18;
            }
            if (*dword_62a9dc >= 0x14) {
                    if (var_19 == 0x0) {
                            asm { fld        dword [dword_value_1077936128] };
                            asm { fcomp      dword [byte_4c6bdc+4] };
                            asm { fnstsw     ax };
                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                    esp = esp - 0xc;
                                    var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                                    eax = sub_4108a0(&var_C, word_4c6d94, &var_14, decomp_var_2c, decomp_var_28);
                                    eax = sub_401050(decomp_var_30);
                                    if (eax != 0x0) {
                                            if (*(int8_t *)byte_baed68 != 0x0) {
                                                    bool_18 = *(esi * 0x8 + 0x4d5484) > 0x0;
                                                    if (*(esi * 0x8 + 0x4d5484) >= 0x0) {
                                                            if (!bool_18) {
                                                                    if (*(esi * 0x8 + 0x4d5480) > 0x1) {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_432960(esi);
                                                                            var_19 = eax;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_432960(esi);
                                                                    var_19 = eax;
                                                            }
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    eax = sub_432960(esi);
                                                    var_19 = eax;
                                            }
                                    }
                            }
                    }
                    if (*dword_62a9dc >= 0x14) {
                            if (var_19 == 0x0) {
                                    esp = esp - 0xc;
                                    var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                                    sub_4108a0(&var_C, word_4c6df8, &var_14, decomp_var_2c, decomp_var_28);
                                    eax = sub_401050(decomp_var_30);
                                    if (eax != 0x0) {
                                            bool_56 = ebx[0x1] < 0x0;
                                            bool_41 = ebx[0x1] > 0x0;
                                            if (!bool_56) {
                                                    if (!bool_41) {
                                                            if (*ebx >= 0x3) {
                                                                    eax = esi * 0x15 + ebp;
                                                                    bool_38 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                    bool_26 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                    if (!bool_38) {
                                                                            if (!bool_26) {
                                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                                    eax = esi * 0x15 + ebp;
                                                                                                    bool_40 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                                    bool_31 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                                    if (!bool_40) {
                                                                                                            if (!bool_31) {
                                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                            eax = esi * 0x15 + ebp;
                                                                                            bool_45 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                            bool_37 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                            if (!bool_45) {
                                                                                                    if (!bool_37) {
                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                            eax = esi * 0x15 + ebp;
                                                                            bool_39 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                                    if (!bool_39) {
                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                    }
                                                                            }
                                                                    }
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            eax = esi * 0x15 + ebp;
                                                            bool_53 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                            bool_33 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                            if (!bool_53) {
                                                                    if (!bool_33) {
                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                            eax = esi * 0x15 + ebp;
                                                                                            bool_51 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                            bool_50 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                            if (!bool_51) {
                                                                                                    if (!bool_50) {
                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                    eax = esi * 0x15 + ebp;
                                                                                    bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                    bool_28 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                    if (!bool_32) {
                                                                                            if (!bool_28) {
                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                            eax = esi * 0x15 + ebp;
                                                            bool_55 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                    if (!bool_55) {
                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                    }
                                                            }
                                                    }
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                    }
            }
            else {
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp + 0x4;
    }
    return eax;

loc_439ce1:
    eax = esi * 0x15 + ebp;
    bool_8 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (*(eax * 0x8 + 0x4d552c) > 0x0) goto .l4;
    goto loc_439cf2;

loc_439cba:
    ebp = var_14;
    edi = var_18;
    goto loc_439cc2;

loc_439ca4:
    esp = esp - 0x4;
    decomp_var_2c = esi;
    eax = sub_438b30();
    var_19 = eax;
    if (eax != 0x0) goto .l11;
    goto loc_439cba;

.l4:
    if (*dword_62a9dc >= 0xa) {
            edi = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
            esp = esp - 0xc;
            var_14 = edi;
            eax = sub_4108a0(&var_C, word_4c6d88, &var_14, decomp_var_2c, decomp_var_28);
            eax = sub_401050(decomp_var_30);
            if (eax != 0x0) {
                    esp = esp - 0xc;
                    var_14 = edi;
                    eax = sub_4108a0(&var_C, 0x4c6dec, &var_14, decomp_var_2c, decomp_var_28);
                    eax = sub_401050(decomp_var_30);
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            eax = sub_4325a0(esi);
                            var_19 = eax;
                    }
            }
            edi = var_18;
    }
    if (*dword_62a9dc >= 0x14) {
            if (var_19 == 0x0) {
                    asm { fld        dword [dword_value_1077936128] };
                    asm { fcomp      dword [byte_4c6bdc+4] };
                    asm { fnstsw     ax };
                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                            esp = esp - 0xc;
                            var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                            eax = sub_4108a0(&var_C, word_4c6d94, &var_14, decomp_var_2c, decomp_var_28);
                            eax = sub_401050(decomp_var_30);
                            if (eax != 0x0) {
                                    if (*(int8_t *)byte_baed68 != 0x0) {
                                            bool_167 = *(esi * 0x8 + 0x4d5484) > 0x0;
                                            if (*(esi * 0x8 + 0x4d5484) >= 0x0) {
                                                    if (!bool_167) {
                                                            if (*(esi * 0x8 + 0x4d5480) > 0x1) {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_432960(esi);
                                                                    var_19 = eax;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            eax = sub_432960(esi);
                                                            var_19 = eax;
                                                    }
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            eax = sub_432960(esi);
                                            var_19 = eax;
                                    }
                            }
                    }
            }
            if (*dword_62a9dc >= 0x14) {
                    if (var_19 == 0x0) {
                            esp = esp - 0xc;
                            var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                            sub_4108a0(&var_C, word_4c6df8, &var_14, decomp_var_2c, decomp_var_28);
                            eax = sub_401050(decomp_var_30);
                            if (eax != 0x0) {
                                    bool_199 = ebx[0x1] < 0x0;
                                    bool_184 = ebx[0x1] > 0x0;
                                    if (!bool_199) {
                                            if (!bool_184) {
                                                    if (*ebx >= 0x3) {
                                                            eax = esi * 0x15 + ebp;
                                                            bool_181 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                            bool_156 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                            if (!bool_181) {
                                                                    if (!bool_156) {
                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                            eax = esi * 0x15 + ebp;
                                                                                            bool_183 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                            bool_174 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                            if (!bool_183) {
                                                                                                    if (!bool_174) {
                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                    eax = esi * 0x15 + ebp;
                                                                                    bool_188 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                    bool_180 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                    if (!bool_188) {
                                                                                            if (!bool_180) {
                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                    eax = esi * 0x15 + ebp;
                                                                    bool_182 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                    if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                            if (!bool_182) {
                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                            }
                                                                    }
                                                            }
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    eax = esi * 0x15 + ebp;
                                                    bool_196 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                    bool_176 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                    if (!bool_196) {
                                                            if (!bool_176) {
                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                    eax = esi * 0x15 + ebp;
                                                                                    bool_194 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                    bool_193 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                    if (!bool_194) {
                                                                                            if (!bool_193) {
                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                            eax = esi * 0x15 + ebp;
                                                                            bool_175 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                            bool_155 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                            if (!bool_175) {
                                                                                    if (!bool_155) {
                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                    }
                                                                            }
                                                                    }
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            eax = sub_433510(esi, decomp_var_2c);
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                    }
                                    else {
                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                    eax = esi * 0x15 + ebp;
                                                    bool_198 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                    if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                            if (!bool_198) {
                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                            }
                                                    }
                                            }
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                    }
            }
            else {
                    esp = esp + 0x4;
            }
    }
    else {
            esp = esp + 0x4;
    }
    return eax;

loc_439cf2:
    if (bool_8) goto loc_439cfe;
    goto loc_439cf4;

.l11:
    esp = esp + 0x4;
    return eax;

loc_439cf4:
    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    if (*dword_62a9dc >= 0xa) {
                            edi = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                            esp = esp - 0xc;
                            var_14 = edi;
                            eax = sub_4108a0(&var_C, word_4c6d88, &var_14, decomp_var_2c, decomp_var_28);
                            eax = sub_401050(decomp_var_30);
                            if (eax != 0x0) {
                                    esp = esp - 0xc;
                                    var_14 = edi;
                                    eax = sub_4108a0(&var_C, 0x4c6dec, &var_14, decomp_var_2c, decomp_var_28);
                                    eax = sub_401050(decomp_var_30);
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            eax = sub_4325a0(esi);
                                            var_19 = eax;
                                    }
                            }
                            edi = var_18;
                    }
                    if (*dword_62a9dc >= 0x14) {
                            if (var_19 == 0x0) {
                                    asm { fld        dword [dword_value_1077936128] };
                                    asm { fcomp      dword [byte_4c6bdc+4] };
                                    asm { fnstsw     ax };
                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                            esp = esp - 0xc;
                                            var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                                            eax = sub_4108a0(&var_C, word_4c6d94, &var_14, decomp_var_2c, decomp_var_28);
                                            eax = sub_401050(decomp_var_30);
                                            if (eax != 0x0) {
                                                    if (*(int8_t *)byte_baed68 != 0x0) {
                                                            bool_71 = *(esi * 0x8 + 0x4d5484) > 0x0;
                                                            if (*(esi * 0x8 + 0x4d5484) >= 0x0) {
                                                                    if (!bool_71) {
                                                                            if (*(esi * 0x8 + 0x4d5480) > 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_432960(esi);
                                                                                    var_19 = eax;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_432960(esi);
                                                                            var_19 = eax;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            eax = sub_432960(esi);
                                                            var_19 = eax;
                                                    }
                                            }
                                    }
                            }
                            if (*dword_62a9dc >= 0x14) {
                                    if (var_19 == 0x0) {
                                            esp = esp - 0xc;
                                            var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                                            sub_4108a0(&var_C, word_4c6df8, &var_14, decomp_var_2c, decomp_var_28);
                                            eax = sub_401050(decomp_var_30);
                                            if (eax != 0x0) {
                                                    bool_152 = ebx[0x1] < 0x0;
                                                    bool_137 = ebx[0x1] > 0x0;
                                                    if (!bool_152) {
                                                            if (!bool_137) {
                                                                    if (*ebx >= 0x3) {
                                                                            eax = esi * 0x15 + ebp;
                                                                            bool_134 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                            bool_60 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                            if (!bool_134) {
                                                                                    if (!bool_60) {
                                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                                            eax = esi * 0x15 + ebp;
                                                                                                            bool_136 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                                            bool_127 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                                            if (!bool_136) {
                                                                                                                    if (!bool_127) {
                                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                                    eax = esi * 0x15 + ebp;
                                                                                                    bool_141 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                                    bool_133 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                                    if (!bool_141) {
                                                                                                            if (!bool_133) {
                                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                    eax = esi * 0x15 + ebp;
                                                                                    bool_135 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                    if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                                            if (!bool_135) {
                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = esi * 0x15 + ebp;
                                                                    bool_149 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                    bool_129 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                    if (!bool_149) {
                                                                            if (!bool_129) {
                                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                                    eax = esi * 0x15 + ebp;
                                                                                                    bool_147 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                                    bool_146 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                                    if (!bool_147) {
                                                                                                            if (!bool_146) {
                                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                            eax = esi * 0x15 + ebp;
                                                                                            bool_128 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                            bool_59 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                            if (!bool_128) {
                                                                                                    if (!bool_59) {
                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                    eax = esi * 0x15 + ebp;
                                                                    bool_151 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                    if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                            if (!bool_151) {
                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                            }
                                                                    }
                                                            }
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                    }
            }
            else {
                    esp = esp + 0x4;
            }
    }
    else {
            if (*dword_62a9dc >= 0xa) {
                    edi = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                    esp = esp - 0xc;
                    var_14 = edi;
                    eax = sub_4108a0(&var_C, word_4c6d88, &var_14, decomp_var_2c, decomp_var_28);
                    eax = sub_401050(decomp_var_30);
                    if (eax != 0x0) {
                            esp = esp - 0xc;
                            var_14 = edi;
                            eax = sub_4108a0(&var_C, 0x4c6dec, &var_14, decomp_var_2c, decomp_var_28);
                            eax = sub_401050(decomp_var_30);
                            if (eax != 0x0) {
                                    esp = esp - 0x4;
                                    eax = sub_4325a0(esi);
                                    var_19 = eax;
                            }
                    }
                    edi = var_18;
            }
            if (*dword_62a9dc >= 0x14) {
                    if (var_19 == 0x0) {
                            asm { fld        dword [dword_value_1077936128] };
                            asm { fcomp      dword [byte_4c6bdc+4] };
                            asm { fnstsw     ax };
                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                    esp = esp - 0xc;
                                    var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                                    eax = sub_4108a0(&var_C, word_4c6d94, &var_14, decomp_var_2c, decomp_var_28);
                                    eax = sub_401050(decomp_var_30);
                                    if (eax != 0x0) {
                                            if (*(int8_t *)byte_baed68 != 0x0) {
                                                    bool_106 = *(esi * 0x8 + 0x4d5484) > 0x0;
                                                    if (*(esi * 0x8 + 0x4d5484) >= 0x0) {
                                                            if (!bool_106) {
                                                                    if (*(esi * 0x8 + 0x4d5480) > 0x1) {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_432960(esi);
                                                                            var_19 = eax;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_432960(esi);
                                                                    var_19 = eax;
                                                            }
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    eax = sub_432960(esi);
                                                    var_19 = eax;
                                            }
                                    }
                            }
                    }
                    if (*dword_62a9dc >= 0x14) {
                            if (var_19 == 0x0) {
                                    esp = esp - 0xc;
                                    var_14 = (esi + esi * 0x2) * 0x4 + 0xbb6e10;
                                    sub_4108a0(&var_C, word_4c6df8, &var_14, decomp_var_2c, decomp_var_28);
                                    eax = sub_401050(decomp_var_30);
                                    if (eax != 0x0) {
                                            bool_123 = ebx[0x1] > 0x0;
                                            if (ebx[0x1] >= 0x0) {
                                                    if (!bool_123) {
                                                            if (*ebx >= 0x3) {
                                                                    eax = esi * 0x15 + ebp;
                                                                    bool_120 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                    bool_95 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                    if (!bool_120) {
                                                                            if (!bool_95) {
                                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                                    eax = esi * 0x15 + ebp;
                                                                                                    bool_122 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                                    bool_113 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                                    if (!bool_122) {
                                                                                                            if (!bool_113) {
                                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                            eax = esi * 0x15 + ebp;
                                                                                            bool_119 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                                                    if (!bool_119) {
                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                            eax = esi * 0x15 + ebp;
                                                                            bool_121 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                                    if (!bool_121) {
                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                    }
                                                                            }
                                                                    }
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            eax = esi * 0x15 + ebp;
                                                            bool_115 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                                    if (!bool_115) {
                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                            eax = esi * 0x15 + ebp;
                                                                                            bool_86 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                            bool_85 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                            if (!bool_86) {
                                                                                                    if (!bool_85) {
                                                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                                                    eax = esi * 0x15 + ebp;
                                                                                    bool_114 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                                    bool_94 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                                                    if (!bool_114) {
                                                                                            if (!bool_94) {
                                                                                                    if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x4;
                                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                                            }
                                                                                    }
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*(ebp * 0x4 + dword_623990) == 0x1) {
                                                            eax = esi * 0x15 + ebp;
                                                            bool_90 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                                            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                                                                    if (!bool_90) {
                                                                            if (*(eax * 0x8 + 0x4d5528) > 0x0) {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_433510(esi, decomp_var_2c);
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_433510(esi, decomp_var_2c);
                                                                    }
                                                            }
                                                    }
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                    }
            }
            else {
                    esp = esp + 0x4;
            }
    }
    return eax;
}
