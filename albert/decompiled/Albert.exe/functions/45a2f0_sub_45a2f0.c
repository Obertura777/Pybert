// sub_45a2f0 @ 0x45a2f0
// hopper name: sub_45a2f0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45a2f0() {
    var_C = *0x0;
    var_88 = ebx;
    var_90 = esi;
    var_94 = edi;
    var_98 = *dword_4c8db8 ^ &var_94;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    edi = arg_0;
    var_74 = sub_47b26f(0x0);
    eax = sub_466060(&var_3C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_4658f0(&var_84);
    ebx = *(int16_t *)eax;
    eax = sub_466060(&var_3C, 0x2);
    sub_465ff0(eax);
    sub_465fa0();
    edx = &var_3C;
    esp = (esp - 0x9c) + 0x4 - 0x28;
    sub_465ff0(sub_466060(edx, 0x3));
    sub_465fa0();
    sub_40e8e0();
    if (*dword_624ef4 == 0x0) goto .l4;
    goto loc_45a44f;

.l4:
    esp = esp - 0x8;
    eax = sub_465900(&var_80, 0x0);
    if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) {
            if (*dword_62a9dc > 0x0) {
                    sub_465f60(&var_5C);
                    var_AC = ecx;
                    var_AC = ebx;
                    var_80 = &var_BC;
                    esp = esp - 0x2c;
                    sub_465f60(&var_6C);
                    if (sub_438e60() == 0x0) {
                            sub_465f60(&var_80);
                            var_D0 = ecx;
                            var_D0 = ebx;
                            sub_465f60(&var_90);
                            ebp = *(int16_t *)sub_42fc40();
                            eax = sub_465f60(&var_A8);
                            decomp_var_f8 = ecx;
                            var_C8 = &decomp_var_f8;
                            decomp_var_f8 = ebx;
                            sub_465f60(&var_B8);
                            sub_431fe0();
                            decomp_var_10c = var_E0;
                            decomp_var_110 = var_E4;
                            decomp_var_114 = var_E0;
                            var_E8 = &decomp_var_114;
                            esp = esp - 0x6c;
                            decomp_var_114 = ebp;
                            sub_4216f0();
                    }
                    else {
                            eax = esi[0x2];
                            eax = eax[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cc4 != eax) {
                                    if (*(int16_t *)word_4c6ccc != eax) {
                                            var_C8 = var_94;
                                            var_C8 = *(int16_t *)word_4c6d28;
                                            esp = esp - 0x10;
                                            sub_4216f0();
                                    }
                            }
                    }
                    sub_457520();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_465fa0();
                    *0x0 = var_88;
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_80, 0x0);
                    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_84, 0x0);
                            if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_7C, 0x0);
                                    if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    esp = esp - 0x24;
                                                    sub_465f60(&var_6C);
                                                    sub_42cd70();
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x24;
                                                            sub_465f60(&var_6C);
                                                            sub_41c0f0();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_80, 0x0);
                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                            esp = esp - 0x4;
                                                                            sub_40d4d0(edi);
                                                                    }
                                                            }
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                            else {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
                    else {
                            eax = sub_465900(&var_7C, 0x0);
                            edi = *(int16_t *)eax;
                            eax = sub_466060(&var_3C, 0x1);
                            sub_465ff0(eax);
                            sub_465fa0();
                            var_9C = ecx;
                            var_9C = edi;
                            esp = esp - 0x30;
                            sub_465f60(&var_6C);
                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                    var_98 = &var_C0;
                                    sub_465f60(&var_74);
                                    var_C4 = ecx;
                                    var_9C = &var_C4;
                                    var_C4 = ebx;
                                    sub_465f60(&var_84);
                                    esp = esp - 0x30;
                                    var_D8 = &var_94;
                                    edi = *(int16_t *)sub_42fc40();
                                    if (*(int16_t *)word_4c6d48 == edi) {
                                            sub_465f60(&var_9C);
                                            decomp_var_ec = ecx;
                                            decomp_var_ec = ebx;
                                            sub_465f60(&var_AC);
                                            sub_431fe0();
                                            decomp_var_100 = ecx;
                                            var_D8 = &decomp_var_100;
                                            decomp_var_100 = edi;
                                            decomp_var_104 = var_DC;
                                            esp = esp - 0x48;
                                            sub_465f60(&var_D0);
                                            sub_42c970();
                                    }
                            }
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
            }
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&var_80, 0x0);
            if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_84, 0x0);
                    if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_7C, 0x0);
                            if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_7C, 0x0);
                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            esp = esp - 0x24;
                                            sub_465f60(&var_6C);
                                            sub_42cd70();
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    esp = esp - 0x24;
                                                    sub_465f60(&var_6C);
                                                    sub_41c0f0();
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_80, 0x0);
                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                    esp = esp - 0x4;
                                                                    sub_40d4d0(edi);
                                                            }
                                                    }
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
                    else {
                            eax = sub_465900(&var_7C, 0x0);
                            edi = *(int16_t *)eax;
                            eax = sub_466060(&var_3C, 0x1);
                            sub_465ff0(eax);
                            sub_465fa0();
                            var_9C = ecx;
                            var_9C = edi;
                            esp = esp - 0x30;
                            sub_465f60(&var_6C);
                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                    var_98 = &var_C0;
                                    sub_465f60(&var_74);
                                    var_C4 = ecx;
                                    var_9C = &var_C4;
                                    var_C4 = ebx;
                                    sub_465f60(&var_84);
                                    esp = esp - 0x30;
                                    var_D8 = &var_94;
                                    edi = *(int16_t *)sub_42fc40();
                                    if (*(int16_t *)word_4c6d48 == edi) {
                                            sub_465f60(&var_9C);
                                            decomp_var_ec = ecx;
                                            decomp_var_ec = ebx;
                                            sub_465f60(&var_AC);
                                            sub_431fe0();
                                            decomp_var_100 = ecx;
                                            var_D8 = &decomp_var_100;
                                            decomp_var_100 = edi;
                                            decomp_var_104 = var_DC;
                                            esp = esp - 0x48;
                                            sub_465f60(&var_D0);
                                            sub_42c970();
                                    }
                            }
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
            }
            else {
                    eax = sub_465900(&var_7C, 0x0);
                    edi = *(int16_t *)eax;
                    eax = sub_466060(&var_3C, 0x1);
                    sub_465ff0(eax);
                    sub_465fa0();
                    var_9C = ecx;
                    var_9C = edi;
                    esp = esp - 0x30;
                    sub_465f60(&var_6C);
                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                            var_98 = &var_C0;
                            sub_465f60(&var_74);
                            var_C4 = ecx;
                            var_9C = &var_C4;
                            var_C4 = ebx;
                            sub_465f60(&var_84);
                            esp = esp - 0x30;
                            var_D8 = &var_94;
                            edi = *(int16_t *)sub_42fc40();
                            if (*(int16_t *)word_4c6d48 == edi) {
                                    sub_465f60(&var_9C);
                                    decomp_var_ec = ecx;
                                    decomp_var_ec = ebx;
                                    sub_465f60(&var_AC);
                                    sub_431fe0();
                                    decomp_var_100 = ecx;
                                    var_D8 = &decomp_var_100;
                                    decomp_var_100 = edi;
                                    decomp_var_104 = var_DC;
                                    esp = esp - 0x48;
                                    sub_465f60(&var_D0);
                                    sub_42c970();
                            }
                    }
                    sub_457520();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_465fa0();
                    *0x0 = var_88;
            }
    }
    return eax;

loc_45a44f:
    ecx = sub_47b26f(0x0);
    eax = *dword_624ef4;
    esp = (esp - 0x4) + 0x4;
    ecx = ecx - *dword_ba2880;
    ebp = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    eax = eax - 0xf;
    bool_3 = ebp < (eax & 0x80000000 ? 0xffffffff : 0x0);
    if (ebp > (eax & 0x80000000 ? 0xffffffff : 0x0)) goto .l4;
    goto loc_45a475;

loc_45a475:
    if (bool_3) goto loc_45a47b;
    goto loc_45a477;

loc_45a47b:
    esp = esp - 0x8;
    eax = sub_465900(&var_84, 0x0);
    if (*(int16_t *)word_4c6dcc != *(int16_t *)eax) goto .l4;
    goto loc_45a497;

loc_45a477:
    if (ecx < eax) {
            esp = esp - 0x8;
            eax = sub_465900(&var_84, 0x0);
            if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_80, 0x0);
                    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_80, 0x0);
                            if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) {
                                    if (*dword_62a9dc > 0x0) {
                                            sub_465f60(&var_5C);
                                            var_AC = ecx;
                                            var_AC = ebx;
                                            var_80 = &var_BC;
                                            esp = esp - 0x2c;
                                            sub_465f60(&var_6C);
                                            if (sub_438e60() == 0x0) {
                                                    sub_465f60(&var_80);
                                                    var_D0 = ecx;
                                                    var_D0 = ebx;
                                                    sub_465f60(&var_90);
                                                    ebp = *(int16_t *)sub_42fc40();
                                                    eax = sub_465f60(&var_A8);
                                                    decomp_var_f8 = ecx;
                                                    var_C8 = &decomp_var_f8;
                                                    decomp_var_f8 = ebx;
                                                    sub_465f60(&var_B8);
                                                    sub_431fe0();
                                                    decomp_var_10c = var_E0;
                                                    decomp_var_110 = var_E4;
                                                    decomp_var_114 = var_E0;
                                                    var_E8 = &decomp_var_114;
                                                    esp = esp - 0x6c;
                                                    decomp_var_114 = ebp;
                                                    sub_4216f0();
                                            }
                                            else {
                                                    eax = esi[0x2];
                                                    eax = eax[0x1225] & 0xffff;
                                                    if (*(int16_t *)word_4c6cc4 != eax) {
                                                            if (*(int16_t *)word_4c6ccc != eax) {
                                                                    var_C8 = var_94;
                                                                    var_C8 = *(int16_t *)word_4c6d28;
                                                                    esp = esp - 0x10;
                                                                    sub_4216f0();
                                                            }
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_80, 0x0);
                                            if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_84, 0x0);
                                                    if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    edi = *(int16_t *)eax;
                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    var_9C = ecx;
                                                                    var_9C = edi;
                                                                    esp = esp - 0x30;
                                                                    sub_465f60(&var_6C);
                                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                                            var_98 = &var_C0;
                                                                            sub_465f60(&var_74);
                                                                            var_C4 = ecx;
                                                                            var_9C = &var_C4;
                                                                            var_C4 = ebx;
                                                                            sub_465f60(&var_84);
                                                                            esp = esp - 0x30;
                                                                            var_D8 = &var_94;
                                                                            edi = *(int16_t *)sub_42fc40();
                                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                                    sub_465f60(&var_9C);
                                                                                    decomp_var_ec = ecx;
                                                                                    decomp_var_ec = ebx;
                                                                                    sub_465f60(&var_AC);
                                                                                    sub_431fe0();
                                                                                    decomp_var_100 = ecx;
                                                                                    var_D8 = &decomp_var_100;
                                                                                    decomp_var_100 = edi;
                                                                                    decomp_var_104 = var_DC;
                                                                                    esp = esp - 0x48;
                                                                                    sub_465f60(&var_D0);
                                                                                    sub_42c970();
                                                                            }
                                                                    }
                                                                    sub_457520();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = sub_465fa0();
                                                                    *0x0 = var_88;
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                            eax = sub_466060(&var_3C, 0x1);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            esp = esp - 0x24;
                                                                            sub_465f60(&var_6C);
                                                                            sub_42cd70();
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&var_7C, 0x0);
                                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    esp = esp - 0x24;
                                                                                    sub_465f60(&var_6C);
                                                                                    sub_41c0f0();
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x8;
                                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                                            esp = esp - 0x8;
                                                                                            eax = sub_465900(&var_80, 0x0);
                                                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_40d4d0(edi);
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    sub_457520();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = sub_465fa0();
                                                                    *0x0 = var_88;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            edi = *(int16_t *)eax;
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            var_9C = ecx;
                                                            var_9C = edi;
                                                            esp = esp - 0x30;
                                                            sub_465f60(&var_6C);
                                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                                    var_98 = &var_C0;
                                                                    sub_465f60(&var_74);
                                                                    var_C4 = ecx;
                                                                    var_9C = &var_C4;
                                                                    var_C4 = ebx;
                                                                    sub_465f60(&var_84);
                                                                    esp = esp - 0x30;
                                                                    var_D8 = &var_94;
                                                                    edi = *(int16_t *)sub_42fc40();
                                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                                            sub_465f60(&var_9C);
                                                                            decomp_var_ec = ecx;
                                                                            decomp_var_ec = ebx;
                                                                            sub_465f60(&var_AC);
                                                                            sub_431fe0();
                                                                            decomp_var_100 = ecx;
                                                                            var_D8 = &decomp_var_100;
                                                                            decomp_var_100 = edi;
                                                                            decomp_var_104 = var_DC;
                                                                            esp = esp - 0x48;
                                                                            sub_465f60(&var_D0);
                                                                            sub_42c970();
                                                                    }
                                                            }
                                                            sub_457520();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = var_88;
                                                    }
                                            }
                                            else {
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    edi = *(int16_t *)eax;
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    var_9C = ecx;
                                                    var_9C = edi;
                                                    esp = esp - 0x30;
                                                    sub_465f60(&var_6C);
                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                            var_98 = &var_C0;
                                                            sub_465f60(&var_74);
                                                            var_C4 = ecx;
                                                            var_9C = &var_C4;
                                                            var_C4 = ebx;
                                                            sub_465f60(&var_84);
                                                            esp = esp - 0x30;
                                                            var_D8 = &var_94;
                                                            edi = *(int16_t *)sub_42fc40();
                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                    sub_465f60(&var_9C);
                                                                    decomp_var_ec = ecx;
                                                                    decomp_var_ec = ebx;
                                                                    sub_465f60(&var_AC);
                                                                    sub_431fe0();
                                                                    decomp_var_100 = ecx;
                                                                    var_D8 = &decomp_var_100;
                                                                    decomp_var_100 = edi;
                                                                    decomp_var_104 = var_DC;
                                                                    esp = esp - 0x48;
                                                                    sub_465f60(&var_D0);
                                                                    sub_42c970();
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                    }
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_80, 0x0);
                                    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_84, 0x0);
                                            if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            edi = *(int16_t *)eax;
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            var_9C = ecx;
                                                            var_9C = edi;
                                                            esp = esp - 0x30;
                                                            sub_465f60(&var_6C);
                                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                                    var_98 = &var_C0;
                                                                    sub_465f60(&var_74);
                                                                    var_C4 = ecx;
                                                                    var_9C = &var_C4;
                                                                    var_C4 = ebx;
                                                                    sub_465f60(&var_84);
                                                                    esp = esp - 0x30;
                                                                    var_D8 = &var_94;
                                                                    edi = *(int16_t *)sub_42fc40();
                                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                                            sub_465f60(&var_9C);
                                                                            decomp_var_ec = ecx;
                                                                            decomp_var_ec = ebx;
                                                                            sub_465f60(&var_AC);
                                                                            sub_431fe0();
                                                                            decomp_var_100 = ecx;
                                                                            var_D8 = &decomp_var_100;
                                                                            decomp_var_100 = edi;
                                                                            decomp_var_104 = var_DC;
                                                                            esp = esp - 0x48;
                                                                            sub_465f60(&var_D0);
                                                                            sub_42c970();
                                                                    }
                                                            }
                                                            sub_457520();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = var_88;
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x24;
                                                                    sub_465f60(&var_6C);
                                                                    sub_42cd70();
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                            eax = sub_466060(&var_3C, 0x1);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            esp = esp - 0x24;
                                                                            sub_465f60(&var_6C);
                                                                            sub_41c0f0();
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&var_7C, 0x0);
                                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = sub_465900(&var_80, 0x0);
                                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                            esp = esp - 0x4;
                                                                                            sub_40d4d0(edi);
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            sub_457520();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = var_88;
                                                    }
                                            }
                                            else {
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    edi = *(int16_t *)eax;
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    var_9C = ecx;
                                                    var_9C = edi;
                                                    esp = esp - 0x30;
                                                    sub_465f60(&var_6C);
                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                            var_98 = &var_C0;
                                                            sub_465f60(&var_74);
                                                            var_C4 = ecx;
                                                            var_9C = &var_C4;
                                                            var_C4 = ebx;
                                                            sub_465f60(&var_84);
                                                            esp = esp - 0x30;
                                                            var_D8 = &var_94;
                                                            edi = *(int16_t *)sub_42fc40();
                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                    sub_465f60(&var_9C);
                                                                    decomp_var_ec = ecx;
                                                                    decomp_var_ec = ebx;
                                                                    sub_465f60(&var_AC);
                                                                    sub_431fe0();
                                                                    decomp_var_100 = ecx;
                                                                    var_D8 = &decomp_var_100;
                                                                    decomp_var_100 = edi;
                                                                    decomp_var_104 = var_DC;
                                                                    esp = esp - 0x48;
                                                                    sub_465f60(&var_D0);
                                                                    sub_42c970();
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                    }
                                    else {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                    }
                    else {
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_80, 0x0);
                    if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) {
                            if (*dword_62a9dc > 0x0) {
                                    sub_465f60(&var_5C);
                                    var_AC = ecx;
                                    var_AC = ebx;
                                    var_80 = &var_BC;
                                    esp = esp - 0x2c;
                                    sub_465f60(&var_6C);
                                    if (sub_438e60() == 0x0) {
                                            sub_465f60(&var_80);
                                            var_D0 = ecx;
                                            var_D0 = ebx;
                                            sub_465f60(&var_90);
                                            ebp = *(int16_t *)sub_42fc40();
                                            eax = sub_465f60(&var_A8);
                                            decomp_var_f8 = ecx;
                                            var_C8 = &decomp_var_f8;
                                            decomp_var_f8 = ebx;
                                            sub_465f60(&var_B8);
                                            sub_431fe0();
                                            decomp_var_10c = var_E0;
                                            decomp_var_110 = var_E4;
                                            decomp_var_114 = var_E0;
                                            var_E8 = &decomp_var_114;
                                            esp = esp - 0x6c;
                                            decomp_var_114 = ebp;
                                            sub_4216f0();
                                    }
                                    else {
                                            eax = esi[0x2];
                                            eax = eax[0x1225] & 0xffff;
                                            if (*(int16_t *)word_4c6cc4 != eax) {
                                                    if (*(int16_t *)word_4c6ccc != eax) {
                                                            var_C8 = var_94;
                                                            var_C8 = *(int16_t *)word_4c6d28;
                                                            esp = esp - 0x10;
                                                            sub_4216f0();
                                                    }
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_80, 0x0);
                                    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_84, 0x0);
                                            if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            edi = *(int16_t *)eax;
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            var_9C = ecx;
                                                            var_9C = edi;
                                                            esp = esp - 0x30;
                                                            sub_465f60(&var_6C);
                                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                                    var_98 = &var_C0;
                                                                    sub_465f60(&var_74);
                                                                    var_C4 = ecx;
                                                                    var_9C = &var_C4;
                                                                    var_C4 = ebx;
                                                                    sub_465f60(&var_84);
                                                                    esp = esp - 0x30;
                                                                    var_D8 = &var_94;
                                                                    edi = *(int16_t *)sub_42fc40();
                                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                                            sub_465f60(&var_9C);
                                                                            decomp_var_ec = ecx;
                                                                            decomp_var_ec = ebx;
                                                                            sub_465f60(&var_AC);
                                                                            sub_431fe0();
                                                                            decomp_var_100 = ecx;
                                                                            var_D8 = &decomp_var_100;
                                                                            decomp_var_100 = edi;
                                                                            decomp_var_104 = var_DC;
                                                                            esp = esp - 0x48;
                                                                            sub_465f60(&var_D0);
                                                                            sub_42c970();
                                                                    }
                                                            }
                                                            sub_457520();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = var_88;
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x24;
                                                                    sub_465f60(&var_6C);
                                                                    sub_42cd70();
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                            eax = sub_466060(&var_3C, 0x1);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            esp = esp - 0x24;
                                                                            sub_465f60(&var_6C);
                                                                            sub_41c0f0();
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&var_7C, 0x0);
                                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = sub_465900(&var_80, 0x0);
                                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                            esp = esp - 0x4;
                                                                                            sub_40d4d0(edi);
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            sub_457520();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = var_88;
                                                    }
                                            }
                                            else {
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    edi = *(int16_t *)eax;
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    var_9C = ecx;
                                                    var_9C = edi;
                                                    esp = esp - 0x30;
                                                    sub_465f60(&var_6C);
                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                            var_98 = &var_C0;
                                                            sub_465f60(&var_74);
                                                            var_C4 = ecx;
                                                            var_9C = &var_C4;
                                                            var_C4 = ebx;
                                                            sub_465f60(&var_84);
                                                            esp = esp - 0x30;
                                                            var_D8 = &var_94;
                                                            edi = *(int16_t *)sub_42fc40();
                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                    sub_465f60(&var_9C);
                                                                    decomp_var_ec = ecx;
                                                                    decomp_var_ec = ebx;
                                                                    sub_465f60(&var_AC);
                                                                    sub_431fe0();
                                                                    decomp_var_100 = ecx;
                                                                    var_D8 = &decomp_var_100;
                                                                    decomp_var_100 = edi;
                                                                    decomp_var_104 = var_DC;
                                                                    esp = esp - 0x48;
                                                                    sub_465f60(&var_D0);
                                                                    sub_42c970();
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                    }
                                    else {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_80, 0x0);
                            if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_84, 0x0);
                                    if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    edi = *(int16_t *)eax;
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    var_9C = ecx;
                                                    var_9C = edi;
                                                    esp = esp - 0x30;
                                                    sub_465f60(&var_6C);
                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                            var_98 = &var_C0;
                                                            sub_465f60(&var_74);
                                                            var_C4 = ecx;
                                                            var_9C = &var_C4;
                                                            var_C4 = ebx;
                                                            sub_465f60(&var_84);
                                                            esp = esp - 0x30;
                                                            var_D8 = &var_94;
                                                            edi = *(int16_t *)sub_42fc40();
                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                    sub_465f60(&var_9C);
                                                                    decomp_var_ec = ecx;
                                                                    decomp_var_ec = ebx;
                                                                    sub_465f60(&var_AC);
                                                                    sub_431fe0();
                                                                    decomp_var_100 = ecx;
                                                                    var_D8 = &decomp_var_100;
                                                                    decomp_var_100 = edi;
                                                                    decomp_var_104 = var_DC;
                                                                    esp = esp - 0x48;
                                                                    sub_465f60(&var_D0);
                                                                    sub_42c970();
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x24;
                                                            sub_465f60(&var_6C);
                                                            sub_42cd70();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x24;
                                                                    sub_465f60(&var_6C);
                                                                    sub_41c0f0();
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&var_80, 0x0);
                                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                    esp = esp - 0x4;
                                                                                    sub_40d4d0(edi);
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                    }
                                    else {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                            else {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
            }
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&var_80, 0x0);
            if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) {
                    if (*dword_62a9dc > 0x0) {
                            sub_465f60(&var_5C);
                            var_AC = ecx;
                            var_AC = ebx;
                            var_80 = &var_BC;
                            esp = esp - 0x2c;
                            sub_465f60(&var_6C);
                            if (sub_438e60() == 0x0) {
                                    sub_465f60(&var_80);
                                    var_D0 = ecx;
                                    var_D0 = ebx;
                                    sub_465f60(&var_90);
                                    ebp = *(int16_t *)sub_42fc40();
                                    eax = sub_465f60(&var_A8);
                                    decomp_var_f8 = ecx;
                                    var_C8 = &decomp_var_f8;
                                    decomp_var_f8 = ebx;
                                    sub_465f60(&var_B8);
                                    sub_431fe0();
                                    decomp_var_10c = var_E0;
                                    decomp_var_110 = var_E4;
                                    decomp_var_114 = var_E0;
                                    var_E8 = &decomp_var_114;
                                    esp = esp - 0x6c;
                                    decomp_var_114 = ebp;
                                    sub_4216f0();
                            }
                            else {
                                    eax = esi[0x2];
                                    eax = eax[0x1225] & 0xffff;
                                    if (*(int16_t *)word_4c6cc4 != eax) {
                                            if (*(int16_t *)word_4c6ccc != eax) {
                                                    var_C8 = var_94;
                                                    var_C8 = *(int16_t *)word_4c6d28;
                                                    esp = esp - 0x10;
                                                    sub_4216f0();
                                            }
                                    }
                            }
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
                    else {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_80, 0x0);
                            if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_84, 0x0);
                                    if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    edi = *(int16_t *)eax;
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    var_9C = ecx;
                                                    var_9C = edi;
                                                    esp = esp - 0x30;
                                                    sub_465f60(&var_6C);
                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                            var_98 = &var_C0;
                                                            sub_465f60(&var_74);
                                                            var_C4 = ecx;
                                                            var_9C = &var_C4;
                                                            var_C4 = ebx;
                                                            sub_465f60(&var_84);
                                                            esp = esp - 0x30;
                                                            var_D8 = &var_94;
                                                            edi = *(int16_t *)sub_42fc40();
                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                    sub_465f60(&var_9C);
                                                                    decomp_var_ec = ecx;
                                                                    decomp_var_ec = ebx;
                                                                    sub_465f60(&var_AC);
                                                                    sub_431fe0();
                                                                    decomp_var_100 = ecx;
                                                                    var_D8 = &decomp_var_100;
                                                                    decomp_var_100 = edi;
                                                                    decomp_var_104 = var_DC;
                                                                    esp = esp - 0x48;
                                                                    sub_465f60(&var_D0);
                                                                    sub_42c970();
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x24;
                                                            sub_465f60(&var_6C);
                                                            sub_42cd70();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x24;
                                                                    sub_465f60(&var_6C);
                                                                    sub_41c0f0();
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&var_80, 0x0);
                                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                    esp = esp - 0x4;
                                                                                    sub_40d4d0(edi);
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                    }
                                    else {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                            else {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_80, 0x0);
                    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_84, 0x0);
                            if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_7C, 0x0);
                                    if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    esp = esp - 0x24;
                                                    sub_465f60(&var_6C);
                                                    sub_42cd70();
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x24;
                                                            sub_465f60(&var_6C);
                                                            sub_41c0f0();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_80, 0x0);
                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                            esp = esp - 0x4;
                                                                            sub_40d4d0(edi);
                                                                    }
                                                            }
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                            else {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
                    else {
                            eax = sub_465900(&var_7C, 0x0);
                            edi = *(int16_t *)eax;
                            eax = sub_466060(&var_3C, 0x1);
                            sub_465ff0(eax);
                            sub_465fa0();
                            var_9C = ecx;
                            var_9C = edi;
                            esp = esp - 0x30;
                            sub_465f60(&var_6C);
                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                    var_98 = &var_C0;
                                    sub_465f60(&var_74);
                                    var_C4 = ecx;
                                    var_9C = &var_C4;
                                    var_C4 = ebx;
                                    sub_465f60(&var_84);
                                    esp = esp - 0x30;
                                    var_D8 = &var_94;
                                    edi = *(int16_t *)sub_42fc40();
                                    if (*(int16_t *)word_4c6d48 == edi) {
                                            sub_465f60(&var_9C);
                                            decomp_var_ec = ecx;
                                            decomp_var_ec = ebx;
                                            sub_465f60(&var_AC);
                                            sub_431fe0();
                                            decomp_var_100 = ecx;
                                            var_D8 = &decomp_var_100;
                                            decomp_var_100 = edi;
                                            decomp_var_104 = var_DC;
                                            esp = esp - 0x48;
                                            sub_465f60(&var_D0);
                                            sub_42c970();
                                    }
                            }
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
            }
    }
    return eax;

loc_45a497:
    esp = esp - 0x8;
    eax = sub_465900(&var_80, 0x0);
    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
            esp = esp - 0x8;
            eax = sub_465900(&var_80, 0x0);
            if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) {
                    if (*dword_62a9dc > 0x0) {
                            sub_465f60(&var_5C);
                            var_AC = ecx;
                            var_AC = ebx;
                            var_80 = &var_BC;
                            esp = esp - 0x2c;
                            sub_465f60(&var_6C);
                            if (sub_438e60() == 0x0) {
                                    sub_465f60(&var_80);
                                    var_D0 = ecx;
                                    var_D0 = ebx;
                                    sub_465f60(&var_90);
                                    ebp = *(int16_t *)sub_42fc40();
                                    eax = sub_465f60(&var_A8);
                                    decomp_var_f8 = ecx;
                                    var_C8 = &decomp_var_f8;
                                    decomp_var_f8 = ebx;
                                    sub_465f60(&var_B8);
                                    sub_431fe0();
                                    decomp_var_10c = var_E0;
                                    decomp_var_110 = var_E4;
                                    decomp_var_114 = var_E0;
                                    var_E8 = &decomp_var_114;
                                    esp = esp - 0x6c;
                                    decomp_var_114 = ebp;
                                    sub_4216f0();
                            }
                            else {
                                    eax = esi[0x2];
                                    eax = eax[0x1225] & 0xffff;
                                    if (*(int16_t *)word_4c6cc4 != eax) {
                                            if (*(int16_t *)word_4c6ccc != eax) {
                                                    var_C8 = var_94;
                                                    var_C8 = *(int16_t *)word_4c6d28;
                                                    esp = esp - 0x10;
                                                    sub_4216f0();
                                            }
                                    }
                            }
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
                    else {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_80, 0x0);
                            if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_84, 0x0);
                                    if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    edi = *(int16_t *)eax;
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    var_9C = ecx;
                                                    var_9C = edi;
                                                    esp = esp - 0x30;
                                                    sub_465f60(&var_6C);
                                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                            var_98 = &var_C0;
                                                            sub_465f60(&var_74);
                                                            var_C4 = ecx;
                                                            var_9C = &var_C4;
                                                            var_C4 = ebx;
                                                            sub_465f60(&var_84);
                                                            esp = esp - 0x30;
                                                            var_D8 = &var_94;
                                                            edi = *(int16_t *)sub_42fc40();
                                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                                    sub_465f60(&var_9C);
                                                                    decomp_var_ec = ecx;
                                                                    decomp_var_ec = ebx;
                                                                    sub_465f60(&var_AC);
                                                                    sub_431fe0();
                                                                    decomp_var_100 = ecx;
                                                                    var_D8 = &decomp_var_100;
                                                                    decomp_var_100 = edi;
                                                                    decomp_var_104 = var_DC;
                                                                    esp = esp - 0x48;
                                                                    sub_465f60(&var_D0);
                                                                    sub_42c970();
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x24;
                                                            sub_465f60(&var_6C);
                                                            sub_42cd70();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_3C, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x24;
                                                                    sub_465f60(&var_6C);
                                                                    sub_41c0f0();
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_7C, 0x0);
                                                                    if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&var_80, 0x0);
                                                                            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                                    esp = esp - 0x4;
                                                                                    sub_40d4d0(edi);
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    sub_457520();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = var_88;
                                            }
                                    }
                                    else {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                            else {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_80, 0x0);
                    if (*(int16_t *)word_4c6d48 != *(int16_t *)eax) {
                            esp = esp - 0x8;
                            eax = sub_465900(&var_84, 0x0);
                            if (*(int16_t *)word_4c6d28 != *(int16_t *)eax) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_7C, 0x0);
                                    if (*(int16_t *)word_4c6d90 == *(int16_t *)eax) {
                                            eax = sub_465900(&var_7C, 0x0);
                                            edi = *(int16_t *)eax;
                                            eax = sub_466060(&var_3C, 0x1);
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            var_9C = ecx;
                                            var_9C = edi;
                                            esp = esp - 0x30;
                                            sub_465f60(&var_6C);
                                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                                    var_98 = &var_C0;
                                                    sub_465f60(&var_74);
                                                    var_C4 = ecx;
                                                    var_9C = &var_C4;
                                                    var_C4 = ebx;
                                                    sub_465f60(&var_84);
                                                    esp = esp - 0x30;
                                                    var_D8 = &var_94;
                                                    edi = *(int16_t *)sub_42fc40();
                                                    if (*(int16_t *)word_4c6d48 == edi) {
                                                            sub_465f60(&var_9C);
                                                            decomp_var_ec = ecx;
                                                            decomp_var_ec = ebx;
                                                            sub_465f60(&var_AC);
                                                            sub_431fe0();
                                                            decomp_var_100 = ecx;
                                                            var_D8 = &decomp_var_100;
                                                            decomp_var_100 = edi;
                                                            decomp_var_104 = var_DC;
                                                            esp = esp - 0x48;
                                                            sub_465f60(&var_D0);
                                                            sub_42c970();
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&var_7C, 0x0);
                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                    eax = sub_466060(&var_3C, 0x1);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    esp = esp - 0x24;
                                                    sub_465f60(&var_6C);
                                                    sub_42cd70();
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&var_7C, 0x0);
                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_3C, 0x1);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x24;
                                                            sub_465f60(&var_6C);
                                                            sub_41c0f0();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&var_7C, 0x0);
                                                            if (*(int16_t *)word_4c6cf0 != *(int16_t *)eax) {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&var_80, 0x0);
                                                                    if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                                                                            esp = esp - 0x4;
                                                                            sub_40d4d0(edi);
                                                                    }
                                                            }
                                                    }
                                            }
                                            sub_457520();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = var_88;
                                    }
                            }
                            else {
                                    eax = sub_465900(&var_7C, 0x0);
                                    edi = *(int16_t *)eax;
                                    eax = sub_466060(&var_3C, 0x1);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    var_9C = ecx;
                                    var_9C = edi;
                                    esp = esp - 0x30;
                                    sub_465f60(&var_6C);
                                    if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                            var_98 = &var_C0;
                                            sub_465f60(&var_74);
                                            var_C4 = ecx;
                                            var_9C = &var_C4;
                                            var_C4 = ebx;
                                            sub_465f60(&var_84);
                                            esp = esp - 0x30;
                                            var_D8 = &var_94;
                                            edi = *(int16_t *)sub_42fc40();
                                            if (*(int16_t *)word_4c6d48 == edi) {
                                                    sub_465f60(&var_9C);
                                                    decomp_var_ec = ecx;
                                                    decomp_var_ec = ebx;
                                                    sub_465f60(&var_AC);
                                                    sub_431fe0();
                                                    decomp_var_100 = ecx;
                                                    var_D8 = &decomp_var_100;
                                                    decomp_var_100 = edi;
                                                    decomp_var_104 = var_DC;
                                                    esp = esp - 0x48;
                                                    sub_465f60(&var_D0);
                                                    sub_42c970();
                                            }
                                    }
                                    sub_457520();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = var_88;
                            }
                    }
                    else {
                            eax = sub_465900(&var_7C, 0x0);
                            edi = *(int16_t *)eax;
                            eax = sub_466060(&var_3C, 0x1);
                            sub_465ff0(eax);
                            sub_465fa0();
                            var_9C = ecx;
                            var_9C = edi;
                            esp = esp - 0x30;
                            sub_465f60(&var_6C);
                            if (sub_42c970() == 0x0 && *(int16_t *)word_4c6d48 == edi) {
                                    var_98 = &var_C0;
                                    sub_465f60(&var_74);
                                    var_C4 = ecx;
                                    var_9C = &var_C4;
                                    var_C4 = ebx;
                                    sub_465f60(&var_84);
                                    esp = esp - 0x30;
                                    var_D8 = &var_94;
                                    edi = *(int16_t *)sub_42fc40();
                                    if (*(int16_t *)word_4c6d48 == edi) {
                                            sub_465f60(&var_9C);
                                            decomp_var_ec = ecx;
                                            decomp_var_ec = ebx;
                                            sub_465f60(&var_AC);
                                            sub_431fe0();
                                            decomp_var_100 = ecx;
                                            var_D8 = &decomp_var_100;
                                            decomp_var_100 = edi;
                                            decomp_var_104 = var_DC;
                                            esp = esp - 0x48;
                                            sub_465f60(&var_D0);
                                            sub_42c970();
                                    }
                            }
                            sub_457520();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = var_88;
                    }
            }
    }
    else {
            sub_457520();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            eax = sub_465fa0();
            *0x0 = var_88;
    }
    return eax;
}
