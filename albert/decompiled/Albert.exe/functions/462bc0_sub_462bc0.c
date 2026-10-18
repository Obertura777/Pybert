// sub_462bc0 @ 0x462bc0
// hopper name: sub_462bc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_462bc0() {
    var_C = *0x0;
    decomp_var_d8 = ebx;
    *0x0 = &var_C;
    edi = ecx;
    var_C8 = 0xffffffff;
    sub_465870();
    sub_4064f0();
    sub_465870();
    esp = esp - 0xf0;
    eax = sub_465900(&var_D4, 0x0);
    eax = *(int8_t *)eax & 0xff;
    var_D0 = eax;
    if (eax >= edi[0x901]) {
            var_C8 = 0x0;
            sub_465fa0();
            sub_406440();
            sub_465fa0();
            sub_465fa0();
            eax = var_B8;
            *0x0 = arg_0;
    }
    else {
            eax = sub_465900(&var_D4, 0x1);
            ebp = *(int16_t *)eax;
            eax = sub_466060(&var_C4, 0x2);
            esp = esp - 0x14;
            sub_465ff0(eax);
            sub_465fa0();
            if (sub_4658e0() != 0x0) {
                    esp = esp - 0x4;
                    eax = sub_4658f0(&var_CC);
                    ebx = *(int16_t *)eax;
                    var_D4 = ebp;
                    ebx = ebx & 0xff;
                    if (ebx >= edi[0x900]) {
                            var_B8 = 0x2;
                    }
                    else {
                            esi = edi + (ebx + ebx * 0x8) * 0x4 + 0x8;
                            esp = esp - 0x8;
                            var_80 = *(edi + (ebx + ebx * 0x8) * 0x4 + 0xc);
                            eax = sub_4602f0(&var_B4, &var_C4, decomp_var_d8, var_D4, var_D0);
                            ecx = eax;
                            eax = *ecx;
                            var_BC = ecx;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                                    ecx = var_BC;
                            }
                            if (ecx[0x1] == var_80) {
                                    var_B8 = 0x2;
                            }
                            else {
                                    esi = var_C0;
                                    var_78 = ebx;
                                    var_68 = 0x0;
                                    if (sub_465930() == 0x5) {
                                            eax = sub_466060(&var_B4, 0x3);
                                            esp = esp - 0xc;
                                            eax = sub_4658f0(&var_BC);
                                            bool_15 = *(int16_t *)word_4c77cc == *(int16_t *)eax;
                                            sub_465fa0();
                                            if (!bool_15) {
                                                    esp = esp - 0x4;
                                                    var_B8 = sub_466110(0x3);
                                            }
                                            else {
                                                    eax = sub_466060(&var_B4, 0x4);
                                                    esp = esp - 0xc;
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    sub_4028a0();
                                                    ecx = &var_94;
                                                    esi = 0x0;
                                                    if (sub_465930() > 0x0) {
                                                            decomp_var_dc = ecx;
                                                            var_BC = &decomp_var_dc;
                                                            decomp_var_dc = ebp;
                                                            eax = sub_466060(&var_C, esi);
                                                            eax = sub_45fc30(&var_B4, eax, decomp_var_dc);
                                                            esp = esp - 0x1c;
                                                            eax = sub_404e10(&var_84, eax);
                                                            sub_465fa0();
                                                            ecx = &var_94;
                                                            esi = esi + 0x1;
                                                            if (esi < sub_465930()) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            var_CC = &var_68;
                                            esp = esp - 0x8;
                                            var_D0 = &var_AC;
                                            sub_407720(var_D0);
                                            sub_42e120(var_CC);
                                            if (var_B0 == (edi[0x2424] & 0xff)) {
                                                    var_CC = &var_B0;
                                                    esp = esp - 0x8;
                                                    var_D0 = &var_A4;
                                                    sub_404ce0(var_C0, var_BC, var_B8);
                                            }
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            var_C0 = ebx;
                                            eax = sub_407720(&var_C0);
                                            sub_42e120(decomp_var_dc);
                                            if (esi == (edi[0x2424] & 0xff)) {
                                                    esp = esp - 0x8;
                                                    sub_404ce0(var_C0, var_BC, var_B8);
                                            }
                                    }
                            }
                    }
                    sub_465fa0();
                    sub_406440();
                    sub_465fa0();
                    sub_465fa0();
                    eax = var_B8;
                    *0x0 = arg_0;
            }
            else {
                    if (*(int16_t *)word_4c7674 == ebp) {
                            eax = sub_465900(&var_CC, 0x0);
                            ebx = *(int16_t *)eax;
                            esp = esp - 0x10;
                            eax = sub_465900(&var_D4, 0x1);
                            var_D4 = *(int16_t *)eax;
                            ebx = ebx & 0xff;
                            if (ebx >= edi[0x900]) {
                                    var_B8 = 0x2;
                            }
                            else {
                                    esi = edi + (ebx + ebx * 0x8) * 0x4 + 0x8;
                                    esp = esp - 0x8;
                                    var_80 = *(edi + (ebx + ebx * 0x8) * 0x4 + 0xc);
                                    eax = sub_4602f0(&var_B4, &var_C4, decomp_var_d8, var_D4, var_D0);
                                    ecx = eax;
                                    eax = *ecx;
                                    var_BC = ecx;
                                    if (eax == 0x0 || eax != esi) {
                                            sub_47a948();
                                            ecx = var_BC;
                                    }
                                    if (ecx[0x1] == var_80) {
                                            var_B8 = 0x2;
                                    }
                                    else {
                                            esi = var_C0;
                                            var_78 = ebx;
                                            var_68 = 0x0;
                                            if (sub_465930() == 0x5) {
                                                    eax = sub_466060(&var_B4, 0x3);
                                                    esp = esp - 0xc;
                                                    eax = sub_4658f0(&var_BC);
                                                    bool_6 = *(int16_t *)word_4c77cc == *(int16_t *)eax;
                                                    sub_465fa0();
                                                    if (!bool_6) {
                                                            esp = esp - 0x4;
                                                            var_B8 = sub_466110(0x3);
                                                    }
                                                    else {
                                                            eax = sub_466060(&var_B4, 0x4);
                                                            esp = esp - 0xc;
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            sub_4028a0();
                                                            ecx = &var_94;
                                                            esi = 0x0;
                                                            if (sub_465930() > 0x0) {
                                                                    do {
                                                                            decomp_var_dc = ecx;
                                                                            var_BC = &decomp_var_dc;
                                                                            decomp_var_dc = ebp;
                                                                            eax = sub_466060(&var_C, esi);
                                                                            eax = sub_45fc30(&var_B4, eax, decomp_var_dc);
                                                                            esp = esp - 0x1c;
                                                                            eax = sub_404e10(&var_84, eax);
                                                                            sub_465fa0();
                                                                            ecx = &var_94;
                                                                            esi = esi + 0x1;
                                                                    } while (esi < sub_465930());
                                                            }
                                                    }
                                                    var_CC = &var_68;
                                                    esp = esp - 0x8;
                                                    var_D0 = &var_AC;
                                                    sub_407720(var_D0);
                                                    sub_42e120(var_CC);
                                                    if (var_B0 == (edi[0x2424] & 0xff)) {
                                                            var_CC = &var_B0;
                                                            esp = esp - 0x8;
                                                            var_D0 = &var_A4;
                                                            sub_404ce0(var_C0, var_BC, var_B8);
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    var_C0 = ebx;
                                                    eax = sub_407720(&var_C0);
                                                    sub_42e120(decomp_var_dc);
                                                    if (esi == (edi[0x2424] & 0xff)) {
                                                            esp = esp - 0x8;
                                                            sub_404ce0(var_C0, var_BC, var_B8);
                                                    }
                                            }
                                    }
                            }
                            sub_465fa0();
                            sub_406440();
                            sub_465fa0();
                            sub_465fa0();
                            eax = var_B8;
                            *0x0 = arg_0;
                    }
                    else {
                            var_B8 = 0x2;
                            sub_465fa0();
                            sub_406440();
                            sub_465fa0();
                            sub_465fa0();
                            eax = var_B8;
                            *0x0 = arg_0;
                    }
            }
    }
    return eax;
}
