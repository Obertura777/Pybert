// sub_45be00 @ 0x45be00
// hopper name: sub_45be00
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45be00() {
    var_C = *0x0;
    decomp_var_b4 = esi;
    decomp_var_b8 = edi;
    *0x0 = &var_C;
    var_68 = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    edi = arg_0;
    ebx = 0x0;
    eax = sub_466060(&var_98, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    sub_466060(&var_A8, 0x0);
    eax = sub_4661a0(&var_98);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&var_A8, 0x2);
    esp = esp - 0xe4;
    eax = sub_4658f0(&var_6A);
    esi = *(int16_t *)eax;
    sub_465fa0();
    if (*(int16_t *)word_4c6fe4 != esi) {
            if (*(int16_t *)word_4c700c != esi) {
                    if (*(int16_t *)word_4c7010 != esi) {
                            if (*(int16_t *)word_4c6fec != esi) {
                                    if (*(int16_t *)word_4c7008 != esi) {
                                            if (*(int16_t *)word_4c7000 == esi) {
                                                    eax = sub_466480(&var_A8, 0x4c6fb0);
                                                    esp = esp - 0xc;
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    ebx = 0x1;
                                            }
                                    }
                                    else {
                                            eax = sub_466480(&var_A8, 0x4c6fb0);
                                            esp = esp - 0xc;
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            ebx = 0x1;
                                    }
                            }
                            else {
                                    eax = sub_466480(&var_A8, 0x4c6fb0);
                                    esp = esp - 0xc;
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    ebx = 0x1;
                            }
                    }
                    else {
                            eax = sub_466480(&var_A8, 0x4c6fb0);
                            esp = esp - 0xc;
                            sub_465ff0(eax);
                            sub_465fa0();
                            ebx = 0x1;
                    }
            }
            else {
                    eax = sub_466480(&var_A8, 0x4c6fb0);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
                    sub_465fa0();
                    ebx = 0x1;
            }
    }
    else {
            eax = sub_466480(&var_A8, 0x4c6fb0);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = 0x1;
    }
    if (*(int16_t *)word_4c7014 == esi) {
            eax = sub_466480(&var_A8, 0x4c6fc0);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = 0x1;
    }
    if (*(int16_t *)word_4c701c != esi) {
            if (*(int16_t *)word_4c6fe0 != esi) {
                    if (*(int16_t *)word_4c6fe8 != esi) {
                            if (*(int16_t *)word_4c7004 != esi) {
                                    if (*(int16_t *)word_4c6fdc == esi) {
                                            eax = sub_466060(&var_98, 0x0);
                                            eax = sub_466480(&var_A8, 0x4c6fd0);
                                            esp = esp - 0x14;
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                            sub_465fa0();
                                            esp = esp - 0x4;
                                            eax = sub_465df0(&var_60);
                                            if (eax != 0x0) {
                                                    eax = sub_46b050(&var_24, decomp_var_b8, decomp_var_b4);
                                                    esi = eax;
                                                    eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                                    eax = sub_466060(&var_A4, 0x2);
                                                    esp = esp - 0x14;
                                                    eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                                    saved_fp = 0xe;
                                                    if (esi[0x6] >= 0x10) {
                                                            esi = esi[0x1];
                                                    }
                                                    else {
                                                            esi = esi + 0x4;
                                                    }
                                                    if (arg_14 >= 0x10) {
                                                            ebp = arg_0;
                                                    }
                                                    else {
                                                            ebp = &arg_0;
                                                    }
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_45f930("THX returned %s for order '%s'. Replacing with '%s'", eax);
                                                    esp = (esp - 0x10) + 0x10;
                                                    if (var_70 >= 0x10) {
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    sub_465fa0();
                                                    if (var_2C >= 0x10) {
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    if (saved_fp >= 0x10) {
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    esp = esp - 0x4;
                                                    sub_45a9b0(&var_6C);
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = arg_4;
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c6fd4 != esi) {
                                                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                                            esi = eax;
                                                            eax = sub_466060(&var_A4, 0x2);
                                                            esp = esp - 0x10;
                                                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                                            if (esi[0x6] >= 0x10) {
                                                                    esi = esi[0x1];
                                                            }
                                                            else {
                                                                    esi = esi + 0x4;
                                                            }
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (var_30 >= 0x10) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            arg_4 = 0xf;
                                                            sub_465fa0();
                                                            if (var_74 >= 0x10) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = arg_4;
                                            }
                                    }
                                    else {
                                            if (ebx != 0x0) {
                                                    esp = esp - 0x4;
                                                    eax = sub_465df0(&var_60);
                                                    if (eax != 0x0) {
                                                            eax = sub_46b050(&var_24, decomp_var_b8, decomp_var_b4);
                                                            esi = eax;
                                                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                                            eax = sub_466060(&var_A4, 0x2);
                                                            esp = esp - 0x14;
                                                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                                            saved_fp = 0xe;
                                                            if (esi[0x6] >= 0x10) {
                                                                    esi = esi[0x1];
                                                            }
                                                            else {
                                                                    esi = esi + 0x4;
                                                            }
                                                            if (arg_14 >= 0x10) {
                                                                    ebp = arg_0;
                                                            }
                                                            else {
                                                                    ebp = &arg_0;
                                                            }
                                                            ebx = 0x10;
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_45f930("THX returned %s for order '%s'. Replacing with '%s'", eax);
                                                            esp = (esp - 0x10) + 0x10;
                                                            if (var_70 >= ebx) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            sub_465fa0();
                                                            if (var_2C >= 0x10) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            if (saved_fp >= 0x10) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            esp = esp - 0x4;
                                                            sub_45a9b0(&var_6C);
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = arg_4;
                                                    }
                                                    else {
                                                            if (*(int16_t *)word_4c6fd4 != esi) {
                                                                    eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                                                    esi = eax;
                                                                    eax = sub_466060(&var_A4, 0x2);
                                                                    esp = esp - 0x10;
                                                                    eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                                                    if (esi[0x6] >= 0x10) {
                                                                            esi = esi[0x1];
                                                                    }
                                                                    else {
                                                                            esi = esi + 0x4;
                                                                    }
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    ebx = 0x10;
                                                                    sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (var_30 >= 0x10) {
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                                    arg_4 = 0xf;
                                                                    sub_465fa0();
                                                                    if (var_74 >= ebx) {
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                    }
                                                            }
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_465fa0();
                                                            *0x0 = arg_4;
                                                    }
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c6fd4 != esi) {
                                                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                                            esi = eax;
                                                            eax = sub_466060(&var_A4, 0x2);
                                                            esp = esp - 0x10;
                                                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                                            if (esi[0x6] >= 0x10) {
                                                                    esi = esi[0x1];
                                                            }
                                                            else {
                                                                    esi = esi + 0x4;
                                                            }
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (var_30 >= 0x10) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            arg_4 = 0xf;
                                                            sub_465fa0();
                                                            if (var_74 >= 0x10) {
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                    }
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = sub_465fa0();
                                                    *0x0 = arg_4;
                                            }
                                    }
                            }
                            else {
                                    eax = sub_466060(&var_98, 0x0);
                                    eax = sub_466480(&var_A8, 0x4c6fd0);
                                    esp = esp - 0x14;
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    sub_465fa0();
                                    esp = esp - 0x4;
                                    eax = sub_465df0(&var_60);
                                    if (eax != 0x0) {
                                            eax = sub_46b050(&var_24, decomp_var_b8, decomp_var_b4);
                                            esi = eax;
                                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                            eax = sub_466060(&var_A4, 0x2);
                                            esp = esp - 0x14;
                                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                            saved_fp = 0xe;
                                            if (esi[0x6] >= 0x10) {
                                                    esi = esi[0x1];
                                            }
                                            else {
                                                    esi = esi + 0x4;
                                            }
                                            if (arg_14 >= 0x10) {
                                                    ebp = arg_0;
                                            }
                                            else {
                                                    ebp = &arg_0;
                                            }
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            sub_45f930("THX returned %s for order '%s'. Replacing with '%s'", eax);
                                            esp = (esp - 0x10) + 0x10;
                                            if (var_70 >= 0x10) {
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            sub_465fa0();
                                            if (var_2C >= 0x10) {
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            if (saved_fp >= 0x10) {
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            esp = esp - 0x4;
                                            sub_45a9b0(&var_6C);
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = arg_4;
                                    }
                                    else {
                                            if (*(int16_t *)word_4c6fd4 != esi) {
                                                    eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                                    esi = eax;
                                                    eax = sub_466060(&var_A4, 0x2);
                                                    esp = esp - 0x10;
                                                    eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                                    if (esi[0x6] >= 0x10) {
                                                            esi = esi[0x1];
                                                    }
                                                    else {
                                                            esi = esi + 0x4;
                                                    }
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    ebx = 0x10;
                                                    sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (var_30 >= 0x10) {
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    ebp = 0x0;
                                                    arg_4 = 0xf;
                                                    sub_465fa0();
                                                    if (var_74 >= ebx) {
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = sub_465fa0();
                                            *0x0 = arg_4;
                                    }
                            }
                    }
                    else {
                            eax = sub_466060(&var_98, 0x0);
                            eax = sub_466480(&var_A8, 0x4c6fd0);
                            esp = esp - 0x14;
                            sub_465ff0(eax);
                            sub_465fa0();
                            sub_465fa0();
                            esp = esp - 0x4;
                            eax = sub_465df0(&var_60);
                            if (eax != 0x0) {
                                    eax = sub_46b050(&var_24, decomp_var_b8, decomp_var_b4);
                                    esi = eax;
                                    eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                    eax = sub_466060(&var_A4, 0x2);
                                    esp = esp - 0x14;
                                    eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                    saved_fp = 0xe;
                                    if (esi[0x6] >= 0x10) {
                                            esi = esi[0x1];
                                    }
                                    else {
                                            esi = esi + 0x4;
                                    }
                                    if (arg_14 >= 0x10) {
                                            ebp = arg_0;
                                    }
                                    else {
                                            ebp = &arg_0;
                                    }
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    sub_45f930("THX returned %s for order '%s'. Replacing with '%s'", eax);
                                    esp = (esp - 0x10) + 0x10;
                                    if (var_70 >= 0x10) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    sub_465fa0();
                                    if (var_2C >= 0x10) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    if (saved_fp >= 0x10) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    esp = esp - 0x4;
                                    sub_45a9b0(&var_6C);
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = arg_4;
                            }
                            else {
                                    if (*(int16_t *)word_4c6fd4 != esi) {
                                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                            esi = eax;
                                            eax = sub_466060(&var_A4, 0x2);
                                            esp = esp - 0x10;
                                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                            if (esi[0x6] >= 0x10) {
                                                    esi = esi[0x1];
                                            }
                                            else {
                                                    esi = esi + 0x4;
                                            }
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            ebx = 0x10;
                                            sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                                            esp = (esp - 0xc) + 0xc;
                                            if (var_30 >= 0x10) {
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            arg_4 = 0xf;
                                            sub_465fa0();
                                            if (var_74 >= ebx) {
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = arg_4;
                            }
                    }
            }
            else {
                    eax = sub_466060(&var_98, 0x0);
                    eax = sub_466480(&var_A8, 0x4c6fd0);
                    esp = esp - 0x14;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    esp = esp - 0x4;
                    eax = sub_465df0(&var_60);
                    if (eax != 0x0) {
                            eax = sub_46b050(&var_24, decomp_var_b8, decomp_var_b4);
                            esi = eax;
                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                            eax = sub_466060(&var_A4, 0x2);
                            esp = esp - 0x14;
                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                            saved_fp = 0xe;
                            if (esi[0x6] >= 0x10) {
                                    esi = esi[0x1];
                            }
                            else {
                                    esi = esi + 0x4;
                            }
                            if (arg_14 >= 0x10) {
                                    ebp = arg_0;
                            }
                            else {
                                    ebp = &arg_0;
                            }
                            if (eax[0x6] >= 0x10) {
                                    eax = eax[0x1];
                            }
                            else {
                                    eax = eax + 0x4;
                            }
                            sub_45f930("THX returned %s for order '%s'. Replacing with '%s'", eax);
                            esp = (esp - 0x10) + 0x10;
                            if (var_70 >= 0x10) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            ebx = 0x10;
                            sub_465fa0();
                            if (var_2C >= 0x10) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            if (saved_fp >= ebx) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            esp = esp - 0x4;
                            sub_45a9b0(&var_6C);
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = arg_4;
                    }
                    else {
                            if (*(int16_t *)word_4c6fd4 != esi) {
                                    eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                                    esi = eax;
                                    eax = sub_466060(&var_A4, 0x2);
                                    esp = esp - 0x10;
                                    eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                                    if (esi[0x6] >= 0x10) {
                                            esi = esi[0x1];
                                    }
                                    else {
                                            esi = esi + 0x4;
                                    }
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    ebx = 0x10;
                                    sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                                    esp = (esp - 0xc) + 0xc;
                                    if (var_30 >= 0x10) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    arg_4 = 0xf;
                                    sub_465fa0();
                                    if (var_74 >= ebx) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                            sub_465fa0();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = arg_4;
                    }
            }
    }
    else {
            eax = sub_466060(&var_98, 0x0);
            eax = sub_466480(&var_A8, 0x4c6fd0);
            esp = esp - 0x14;
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            esp = esp - 0x4;
            eax = sub_465df0(&var_60);
            if (eax != 0x0) {
                    eax = sub_46b050(&var_24, decomp_var_b8, decomp_var_b4);
                    esi = eax;
                    eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                    eax = sub_466060(&var_A4, 0x2);
                    esp = esp - 0x14;
                    eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                    saved_fp = 0xe;
                    if (esi[0x6] >= 0x10) {
                            esi = esi[0x1];
                    }
                    else {
                            esi = esi + 0x4;
                    }
                    if (arg_14 >= 0x10) {
                            ebp = arg_0;
                    }
                    else {
                            ebp = &arg_0;
                    }
                    if (eax[0x6] >= 0x10) {
                            eax = eax[0x1];
                    }
                    else {
                            eax = eax + 0x4;
                    }
                    sub_45f930("THX returned %s for order '%s'. Replacing with '%s'", eax);
                    esp = (esp - 0x10) + 0x10;
                    if (var_70 >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    ebx = 0x10;
                    sub_465fa0();
                    if (var_2C >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (saved_fp >= ebx) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    esp = esp - 0x4;
                    sub_45a9b0(&var_6C);
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_465fa0();
                    *0x0 = arg_4;
            }
            else {
                    if (*(int16_t *)word_4c6fd4 != esi) {
                            eax = sub_46b050(&var_94, decomp_var_b8, decomp_var_b4);
                            esi = eax;
                            eax = sub_466060(&var_A4, 0x2);
                            esp = esp - 0x10;
                            eax = sub_46b050(&var_50, decomp_var_b8, decomp_var_b4);
                            if (esi[0x6] >= 0x10) {
                                    esi = esi[0x1];
                            }
                            else {
                                    esi = esi + 0x4;
                            }
                            if (eax[0x6] >= 0x10) {
                                    eax = eax[0x1];
                            }
                            else {
                                    eax = eax + 0x4;
                            }
                            ebx = 0x10;
                            sub_45f930("THX returned %s for order '%s'. No replacement order sent.", eax);
                            esp = (esp - 0xc) + 0xc;
                            if (var_30 >= 0x10) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            arg_4 = 0xf;
                            sub_465fa0();
                            if (var_74 >= ebx) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_465fa0();
                    *0x0 = arg_4;
            }
    }
    return eax;
}
