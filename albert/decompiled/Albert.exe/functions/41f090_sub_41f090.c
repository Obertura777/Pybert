// sub_41f090 @ 0x41f090
// hopper name: sub_41f090
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41f090() {
    var_8 = 0x4959e8;
    var_C = *0x0;
    decomp_var_90 = esi;
    decomp_var_94 = edi;
    decomp_var_98 = *dword_4c8db8 ^ &decomp_var_94;
    *0x0 = &var_C;
    edi = 0x0;
    *(int16_t *)arg_0 = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_401e30();
    var_44 = eax;
    eax[0x11] = 0x1;
    var_44[0x1] = var_44;
    *var_44 = var_44;
    var_44[0x2] = var_44;
    ebp = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    var_64 = ebp;
    var_81 = 0x0;
    var_82 = 0x1;
    eax = sub_466480(&var_58, &arg_14);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_58, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_58, 0x2);
    sub_465ff0(eax);
    sub_465fa0();
    var_6C = sub_465930();
    esi = sub_465930();
    var_74 = sub_465930();
    esp = esp - 0xc0;
    sub_401950(var_44[0x1]);
    var_44[0x1] = var_44;
    var_40 = 0x0;
    *var_44 = var_44;
    var_44[0x2] = var_44;
    if (esi > 0x0) {
            do {
                    eax = sub_465900(&var_80, edi);
                    ebx = *(int8_t *)eax & 0xff;
                    esp = esp - 0x10;
                    var_70 = ebx;
                    eax = sub_404ce0(&var_58, &var_70, decomp_var_98);
                    if (ebx == ebp) {
                            var_81 = 0x1;
                    }
                    edi = edi + 0x1;
            } while (edi < esi);
    }
    esi = 0x0;
    var_70 = 0x0;
    if (var_6C <= 0x0) goto loc_41f4b4;
    goto loc_41f29c;

loc_41f4b4:
    *(int16_t *)arg_28 = *(int16_t *)word_4c6d48;
    goto loc_41f4d8;

loc_41f29c:
    esp = esp - 0x8;
    eax = sub_465900(&var_80, esi);
    edx = *(int8_t *)eax & 0xff;
    var_78 = edx;
    if (edx == ebp) goto .l49;
    goto loc_41f2ba;

loc_41f4d8:
    sub_403430(&var_8, &arg_4, *arg_8, &arg_4, arg_8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = arg_50;
    *0x0 = arg_40;
    return eax;

.l49:
    if (var_82 != 0x1 || edx == ebp) goto .l61;
    goto .l39;

loc_41f2ba:
    ecx = ebp * 0x15 + edx;
    bool_94 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    bool_70 = *(ecx * 0x8 + 0x4d552c) > 0x0;
    if (bool_94 || !bool_70 && *(ecx * 0x8 + 0x4d5528) < 0x3) goto .l3;
    goto loc_41f2d8;

.l61:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l39:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l61;
    goto .l95;

.l3:
    var_82 = 0x0;
    goto .l61;

loc_41f2d8:
    eax = edx * 0x15 + ebp;
    bool_95 = *(eax * 0x8 + 0x4d552c) > 0x0;
    if (*(eax * 0x8 + 0x4d552c) < 0x0) goto .l3;
    goto loc_41f2e9;
    if (var_5A == 0x1) {
            *(int16_t *)arg_28 = *(int16_t *)word_4c6d48;
    }
    else {
            *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
    }
    goto loc_41f4d8;

.l95:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l96;

loc_41f2e9:
    if (bool_95) goto .l70;
    goto loc_41f2eb;

.l96:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l97;

.l70:
    if (*(edx * 0x8 + 0x4cf568) != 0x1) goto .l72;
    goto .l57;

loc_41f2eb:
    if (*(eax * 0x8 + 0x4d5528) < 0x1) goto .l4;
    goto loc_41f2f5;

.l97:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l72:
    if (*(ecx * 0x4 + 0x634e90) < 0x0) goto .l30;
    goto .l8;

.l57:
    if (*(edx * 0x8 + 0x4cf56c) == 0x0) goto .l5;
    goto .l71;

.l4:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

loc_41f2f5:
    if (*(edx * 0x8 + 0x4cf568) != 0x1) goto loc_41f30d;
    goto loc_41f303;
    ebp = var_64;
    esi = var_70;
    goto .l61;

.l30:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l8:
    if (*(int8_t *)byte_baed68 == 0x0) goto .l49;
    goto .l19;

.l5:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l71:
    if (*(ecx * 0x4 + 0x634e90) < 0x0) goto .l6;
    goto loc_41f317;

loc_41f30d:
    if (*(ecx * 0x4 + 0x634e90) < 0x0) goto .l38;
    goto .l22;

loc_41f303:
    if (*(edx * 0x8 + 0x4cf56c) == 0x0) goto .l65;
    goto .l18;

.l19:
    bool_62 = *(edx * 0x8 + 0x4d5484) < 0x0;
    if (*(edx * 0x8 + 0x4d5484) > 0x0) goto .l51;
    goto .l56;

.l6:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

loc_41f317:
    if (*(int8_t *)byte_baed68 == 0x0) goto .l11;
    goto .l75;

.l38:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l22:
    if (*(int8_t *)byte_baed68 == 0x0) goto .l55;
    goto loc_41f320;

.l65:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l18:
    if (*(ecx * 0x4 + 0x634e90) < 0x0) goto .l64;
    goto .l42;

.l51:
    if (var_82 != 0x1 || edx == ebp) goto .l44;
    goto .l21;

.l56:
    if (bool_62) goto .l27;
    goto .l29;

.l11:
    if (var_82 != 0x1 || edx == ebp) goto .l31;
    goto loc_41f352;

.l75:
    bool_96 = *(edx * 0x8 + 0x4d5484) > 0x0;
    bool_52 = *(edx * 0x8 + 0x4d5484) < 0x0;
    if (bool_96) goto .l12;
    goto loc_41f32a;

.l55:
    if (var_82 != 0x1 || edx == ebp) goto .l50;
    goto .l25;

loc_41f320:
    bool_68 = *(edx * 0x8 + 0x4d5484) < 0x0;
    if (*(edx * 0x8 + 0x4d5484) > 0x0) goto .l48;
    goto .l63;

.l64:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l42:
    if (*(int8_t *)byte_baed68 == 0x0) goto .l69;
    goto .l23;

.l44:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l21:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l44;
    goto .l101;

.l27:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l29:
    if (*(edx * 0x8 + 0x4d5480) > 0x1) goto .l2;
    goto loc_41f335;

.l31:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

loc_41f352:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l31;
    goto loc_41f365;

.l12:
    if (var_82 != 0x1 || edx == ebp) goto loc_41f49c;
    goto .l76;

loc_41f32a:
    if (bool_52) goto .l7;
    goto loc_41f32c;

.l50:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l25:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l50;
    goto .l92;

.l48:
    if (var_82 != 0x1 || edx == ebp) goto .l43;
    goto .l20;

.l63:
    if (bool_68) goto .l36;
    goto .l37;

.l69:
    if (var_82 != 0x1 || edx == ebp) goto .l67;
    goto .l45;

.l23:
    bool_93 = *(edx * 0x8 + 0x4d5484) < 0x0;
    if (*(edx * 0x8 + 0x4d5484) > 0x0) goto .l58;
    goto .l73;

.l101:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l102;

.l2:
    if (var_82 != 0x1 || edx == ebp) goto .l26;
    goto .l15;

loc_41f335:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

loc_41f365:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto loc_41f396;

loc_41f49c:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l76:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto loc_41f49c;
    goto .l104;

.l7:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

loc_41f32c:
    if (*(edx * 0x8 + 0x4d5480) > 0x1) goto .l66;
    goto .l78;

.l92:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l93;

.l43:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l20:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l43;
    goto .l83;

.l36:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l37:
    if (*(edx * 0x8 + 0x4d5480) > 0x1) goto loc_41f33f;
    goto .l9;

.l67:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l45:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l67;
    goto .l89;

.l58:
    if (var_82 != 0x1 || edx == ebp) goto .l52;
    goto .l28;

.l73:
    if (bool_93) goto .l59;
    goto .l62;

.l102:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l103;

.l26:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l15:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l26;
    goto .l86;

loc_41f396:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l79;

.l104:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l106;

.l66:
    if (var_82 != 0x1 || edx == ebp) goto .l77;
    goto .l41;

.l78:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l93:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l94;

.l83:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l84;

loc_41f33f:
    if (var_82 != 0x1 || edx == ebp) goto .l24;
    goto .l14;

.l9:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l89:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l90;

.l52:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l28:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l52;
    goto .l98;

.l59:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l62:
    if (*(edx * 0x8 + 0x4d5480) > 0x1) goto .l33;
    goto .l34;

.l103:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l86:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l87;

.l79:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l106:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l105;

.l77:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l41:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l77;
    goto .l80;

.l94:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l84:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l85;

.l24:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l14:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l24;
    goto .l110;

.l90:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l91;

.l98:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l100;

.l33:
    if (var_82 != 0x1 || edx == ebp) goto .l32;
    goto .l60;

.l34:
    var_82 = 0x0;
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;
    ebp = var_64;
    esi = var_70;
    goto .l44;

.l87:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l88;
    ebp = var_64;
    esi = var_70;
    goto .l31;

.l105:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l80:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l82;
    ebp = var_64;
    esi = var_70;
    goto .l50;

.l85:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l110:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l112;

.l91:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l100:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l99;

.l32:
    esi = esi + 0x1;
    var_48 = esi;
    if (esi < var_44) {
            continue;
    }
    break;

.l60:
    var_7C = 0x0;
    if (var_74 <= 0x0) goto .l32;
    goto .l107;

.l88:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;
    ebp = var_64;
    esi = var_70;
    goto loc_41f49c;

.l82:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l81;
    ebp = var_64;
    esi = var_70;
    goto .l43;

.l112:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l111;
    ebp = var_64;
    esi = var_70;
    goto .l67;

.l99:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l107:
    esp = esp - 0x8;
    eax = sub_465900(&var_7E, var_7C);
    eax = *(int8_t *)eax & 0xff;
    esi = **dword_bb6f20;
    edi = 0xbb6f1c;
    var_68 = eax;
    ebx = 0x0;
    var_60 = 0xbb6f1c;
    var_5C = **dword_bb6f20;
    goto .l109;
    ebp = var_64;
    esi = var_70;
    goto .l26;

.l81:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;

.l111:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;
    ebp = var_64;
    esi = var_70;
    goto .l52;

.l109:
    if (edi == 0x0 || edi != 0xbb6f1c) {
            sub_47a948();
    }
    if (esi != *dword_bb6f20) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] == var_68) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x5] == var_78) {
                            ebx = 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] == 0x0 && var_81 == 0x1) {
                                    ebx = 0x0;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] == 0x1) {
                                    edi = var_44;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&var_58, &var_78, decomp_var_98, decomp_var_94, decomp_var_90);
                                    esi = eax;
                                    eax = *esi;
                                    if (eax == 0x0 || eax != &var_48) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1] == edi) {
                                            ebx = 0x0;
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            sub_40f6f0();
                                            esi = var_5C;
                                            edi = var_60;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (ebx != 0x1) {
                                    sub_40f6f0();
                                    esi = var_5C;
                                    edi = var_60;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (ebx != 0x1) {
                            sub_40f6f0();
                            esi = var_5C;
                            edi = var_60;
                            continue;
                    }
                    break;
            }
    }
    else {
            break;
    }
    goto .l108;
    ebp = var_64;
    esi = var_70;
    goto .l77;
    ebp = var_64;
    esi = var_70;
    goto .l24;

.l108:
    if (ebx == 0x0) {
            var_82 = ebx;
    }
    eax = var_7C + 0x1;
    var_7C = eax;
    if (eax < var_74) {
            continue;
    }
    break;
    ebp = var_64;
    esi = var_70;
    goto .l32;
}
