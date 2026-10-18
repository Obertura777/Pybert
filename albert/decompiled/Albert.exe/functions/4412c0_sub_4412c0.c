// sub_4412c0 @ 0x4412c0
// hopper name: sub_4412c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4412c0() {
    var_2C = ecx;
    decomp_var_40 = edi;
    esp = esp - 0x44;
    ebx = 0x0;
    eax = sub_407720(&arg_4);
    var_28 = arg_0 << 0x8;
    var_24 = eax;
    if (arg_535ce4 != 0x1 || arg_535ce8 != 0x0) goto loc_4413d2;
    goto loc_441315;

loc_4413d2:
    eax = arg_535ce4;
    edx = arg_535ce8;
    if (eax != 0x1 || edx != 0x0) goto loc_441409;
    goto loc_4413e7;

loc_441315:
    eax = arg_8 + var_28;
    if (*(eax * 0x8 + 0x4f6ce8) != 0x1 || *(eax * 0x8 + 0x4f6cec) != 0x0) goto loc_4413d2;
    goto loc_44133b;

loc_441409:
    esi = arg_8;
    goto loc_44140d;

loc_4413e7:
    esi = arg_8;
    ecx = var_28 + esi;
    if (*(ecx * 0x8 + 0x4f6ce8) != eax || *(ecx * 0x8 + 0x4f6cec) != edx || ebx != eax) goto loc_44140d;
    goto loc_441415;

loc_44133b:
    eax = sub_407720(&arg_8);
    esp = esp - 0x8;
    esi = sub_4075b0(eax + 0x4, decomp_var_40);
    var_2D = 0x0;
    edi = esi;
    ebx = *esi[0x1];
    var_18 = edi;
    var_14 = ebx;
    goto loc_441380;

loc_44140d:
    if ((eax | edx) != 0x0) goto loc_44150f;

loc_441415:
    ecx = var_18[0x2];
    eax = ecx + (arg_18 + arg_18 * 0x8) * 0x4;
    if (*(int8_t *)(ecx + (arg_18 + arg_18 * 0x8) * 0x4 + 0x3) != 0x0) {
            eax = eax[0x10];
            bool_10 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_10) {
                    eax = 0x14;
            }
            edx = arg_14;
            if (eax != edx) {
                    eax = ecx + (esi + esi * 0x8) * 0x4;
                    ecx = eax[0x3];
                    if (ecx != 0x0) {
                            if (ecx == 0x1) {
                                    eax = eax[0x10];
                                    bool_13 = HIBYTE(eax) == 0x41;
                                    eax = eax & 0xff;
                                    if (!bool_13) {
                                            eax = 0x14;
                                    }
                                    if (eax != edx) {
                                            edi = var_18 + (arg_14 + arg_14 * 0x2) * 0x4 + 0x4000;
                                            esp = esp - 0x4;
                                            eax = sub_41c1e0(&arg_1c);
                                            asm { fild       qword [eax] };
                                            ebx = var_10;
                                            esp = esp - 0x4;
                                            decomp_var_30 = ebx;
                                            asm { fstp       qword [esp+0x30+var_C] };
                                            eax = sub_41c1e0(decomp_var_30);
                                            asm { fild       qword [eax] };
                                            asm { fmul       qword [qword_value_4605831338911806259] };
                                            asm { fcomp      qword [esp+0x2c+var_C] };
                                            asm { fnstsw     ax };
                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                    bool_16 = arg_6040e8 > 0x0;
                                                    if (arg_6040e8 >= 0x0) {
                                                            if (!bool_16) {
                                                                    if (arg_6040e4 > 0x0) {
                                                                            eax = sub_41c1e0(ebx);
                                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                                                            esp = esp - 0x8;
                                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                                                            eax = sub_41c1e0(ebx);
                                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_41c1e0(ebx);
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                                                    esp = esp - 0x8;
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                                                    eax = sub_41c1e0(ebx);
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = sub_41c1e0(ebx);
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                                    esp = esp - 0x8;
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                                    eax = sub_41c1e0(ebx);
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                            }
                                    }
                            }
                            else {
                                    edi = var_18 + (arg_14 + arg_14 * 0x2) * 0x4 + 0x4000;
                                    esp = esp - 0x4;
                                    eax = sub_41c1e0(&arg_1c);
                                    asm { fild       qword [eax] };
                                    ebx = var_10;
                                    esp = esp - 0x4;
                                    decomp_var_30 = ebx;
                                    asm { fstp       qword [esp+0x30+var_C] };
                                    eax = sub_41c1e0(decomp_var_30);
                                    asm { fild       qword [eax] };
                                    asm { fmul       qword [qword_value_4605831338911806259] };
                                    asm { fcomp      qword [esp+0x2c+var_C] };
                                    asm { fnstsw     ax };
                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                            bool_60 = arg_6040e8 > 0x0;
                                            if (arg_6040e8 >= 0x0) {
                                                    if (!bool_60) {
                                                            if (arg_6040e4 > 0x0) {
                                                                    eax = sub_41c1e0(ebx);
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                                                    esp = esp - 0x8;
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                                                    eax = sub_41c1e0(ebx);
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_41c1e0(ebx);
                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                                            esp = esp - 0x8;
                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                                            eax = sub_41c1e0(ebx);
                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                                    }
                                            }
                                    }
                                    else {
                                            eax = sub_41c1e0(ebx);
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                            esp = esp - 0x8;
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                            eax = sub_41c1e0(ebx);
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                    }
                            }
                    }
            }
            else {
                    edi = var_18 + (arg_14 + arg_14 * 0x2) * 0x4 + 0x4000;
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&arg_1c);
                    asm { fild       qword [eax] };
                    ebx = var_10;
                    esp = esp - 0x4;
                    decomp_var_30 = ebx;
                    asm { fstp       qword [esp+0x30+var_C] };
                    eax = sub_41c1e0(decomp_var_30);
                    asm { fild       qword [eax] };
                    asm { fmul       qword [qword_value_4605831338911806259] };
                    asm { fcomp      qword [esp+0x2c+var_C] };
                    asm { fnstsw     ax };
                    if (PARITY(HIBYTE(eax) & 0x5)) {
                            bool_64 = arg_6040e8 > 0x0;
                            if (arg_6040e8 >= 0x0) {
                                    if (!bool_64) {
                                            if (arg_6040e4 > 0x0) {
                                                    eax = sub_41c1e0(ebx);
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                                    esp = esp - 0x8;
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                                    eax = sub_41c1e0(ebx);
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                            }
                                    }
                                    else {
                                            eax = sub_41c1e0(ebx);
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                            esp = esp - 0x8;
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                            eax = sub_41c1e0(ebx);
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                    }
                            }
                    }
                    else {
                            eax = sub_41c1e0(ebx);
                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                            esp = esp - 0x8;
                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                            eax = sub_41c1e0(ebx);
                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                    }
            }
    }
    else {
            edi = var_18 + (arg_14 + arg_14 * 0x2) * 0x4 + 0x4000;
            esp = esp - 0x4;
            eax = sub_41c1e0(&arg_1c);
            asm { fild       qword [eax] };
            ebx = var_10;
            esp = esp - 0x4;
            decomp_var_30 = ebx;
            asm { fstp       qword [esp+0x30+var_C] };
            eax = sub_41c1e0(decomp_var_30);
            asm { fild       qword [eax] };
            asm { fmul       qword [qword_value_4605831338911806259] };
            asm { fcomp      qword [esp+0x2c+var_C] };
            asm { fnstsw     ax };
            if (PARITY(HIBYTE(eax) & 0x5)) {
                    bool_68 = arg_6040e8 > 0x0;
                    if (arg_6040e8 >= 0x0) {
                            if (!bool_68) {
                                    if (arg_6040e4 > 0x0) {
                                            eax = sub_41c1e0(ebx);
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                            esp = esp - 0x8;
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                            eax = sub_41c1e0(ebx);
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                            *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                                    }
                            }
                            else {
                                    eax = sub_41c1e0(ebx);
                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                                    esp = esp - 0x8;
                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                                    eax = sub_41c1e0(ebx);
                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
                            }
                    }
            }
            else {
                    eax = sub_41c1e0(ebx);
                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaede8) = *eax;
                    esp = esp - 0x8;
                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedec) = eax[0x1];
                    eax = sub_41c1e0(ebx);
                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedb8) = *eax;
                    *(((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + ((arg_18 << 0x4) - arg_18) + 0xbaedbc) = eax[0x1];
            }
    }
    goto loc_44150f;

loc_441380:
    var_1C = esi[0x1];
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebx != var_1C) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x3] == arg_4) {
                    var_2D = 0x1;
            }
            sub_40f400();
            ebx = var_14;
            edi = var_18;
            continue;
    }
    break;

loc_44150f:
    eax = arg_1c;
    ebx = ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax) + ((eax << 0x4) - eax);
    if (ebx[0x2ebb77] != 0x1) goto loc_441685;
    goto loc_441531;
    ebx = var_2D;
    goto loc_4413d2;

loc_441685:
    ebx = arg_4[0x92e];
    esi = arg_4 + 0x24b4;
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_8, &arg_1c, var_2C, var_28, var_24);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] != ebx) {
            if (*dword_bb65b4 == 0x0) {
                    sub_47a948();
            }
            if (*dword_bb65b8 == *(*dword_bb65b4 + 0x4)) {
                    sub_47a948();
            }
            if (*(*dword_bb65b8 + 0x20) == 0x2) {
                    if (*dword_bb65b4 == 0x0) {
                            sub_47a948();
                    }
                    if (*dword_bb65b8 == *(*dword_bb65b4 + 0x4)) {
                            sub_47a948();
                    }
                    eax = *dword_bb65b8;
                    eax = eax[0x9];
                    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaedf0) == 0x1) {
                            if (*dword_bb65b4 == 0x0) {
                                    sub_47a948();
                            }
                            if (*dword_bb65b8 == *(*dword_bb65b4 + 0x4)) {
                                    sub_47a948();
                            }
                            eax = *(*dword_bb65b8 + 0x24);
                            bool_42 = *dword_bb65b4 != 0x0;
                            *(((eax << 0x4) - eax) * 0x8 + 0xbaedf0) = 0x0;
                            if (!bool_42) {
                                    sub_47a948();
                            }
                            if (*dword_bb65b8 == *(*dword_bb65b4 + 0x4)) {
                                    sub_47a948();
                            }
                            *(*(*dword_bb65b8 + 0x24) * 0x4 + 0xba3770) = 0xffffffff;
                    }
            }
    }
    esi = arg_1c;
    eax = var_14 + esi;
    if (*(eax * 0x8 + 0x4f6ce8) != 0x1 || *(eax * 0x8 + 0x4f6cec) != 0x0) goto .l1;
    goto loc_4417cf;

loc_441531:
    edx = *(eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + 0x6190e8);
    eax = eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14 + eax + var_14;
    var_C = eax;
    if ((edx | eax[0x18643b]) != 0x0) goto loc_441685;
    goto loc_441554;

.l1:
    return eax;

loc_4417cf:
    eax = sub_407720(&arg_1c);
    ebx = eax;
    esp = esp - 0x8;
    eax = sub_4075b0(ebx + 0x4, var_2C);
    esi = *eax[0x1];
    edi = eax;
    arg_24 = eax;
    var_4 = edi;
    saved_fp = esi;
    goto loc_441810;

loc_441554:
    ecx = eax[0x163e3b];
    bool_20 = ecx > 0x0;
    edx = eax[0x163e3a];
    if (ecx < 0x0) goto loc_441685;
    goto loc_441568;

loc_441810:
    eax = arg_24;
    ebp = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            eax = sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] != arg_18) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = ebx[0x2];
                    eax = (eax << 0x8) + esi[0x3];
                    *(eax * 0x4 + 0xba9770) = *(eax * 0x4 + 0xba9770) + 0x1;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] != arg_18) {
                    sub_40f400();
                    esi = saved_fp;
                    edi = var_4;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (*(((ebx[0x2] << 0x8) + esi[0x3]) * 0x4 + 0xba4370) == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = ebx[0x2];
                    eax = (eax << 0x8) + esi[0x3];
                    *(eax * 0x4 + 0xba9770) = *(eax * 0x4 + 0xba9770) + 0x2;
            }
            sub_40f400();
            esi = saved_fp;
            edi = var_4;
            continue;
    }
    break;

loc_441568:
    if (bool_20) goto .l5;
    goto loc_44156a;

.l5:
    if ((eax[0x14833a] | eax[0x14833b]) == 0x0) goto .l13;
    goto .l6;

loc_44156a:
    if (edx <= 0x1) goto .l2;
    goto loc_44156e;

.l13:
    var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
    if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) != 0x1) {
            ecx = var_18[0x2];
            esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
            edi = esi + ecx + 0x14;
            esp = esp - 0x8;
            arg_4 = *(esi + ecx + 0x18);
            eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
            eax = *eax;
            if (eax != 0x0) {
                    if (eax != edi) {
                            sub_47a948();
                    }
                    if (arg_0 != arg_4) {
                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                            bool_241 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_241) {
                                    eax = 0x14;
                            }
                            if (eax == arg_14 && *var_10 == 0x0) {
                                    eax = var_C;
                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                    ebx[0x2ebb7c] = 0x1;
                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                            }
                                    }
                            }
                    }
            }
            else {
                    sub_47a948();
                    if (arg_0 != arg_4) {
                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                            bool_249 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_249) {
                                    eax = 0x14;
                            }
                            if (eax == arg_14 && *var_10 == 0x0) {
                                    eax = var_C;
                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                    ebx[0x2ebb7c] = 0x1;
                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                            ebx[0x2ebb7c] = 0x1;
                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                    }
            }
    }
    goto loc_441685;

.l6:
    bool_193 = ecx > 0x0;
    if (ecx < 0x0) goto loc_441685;
    goto .l7;

.l2:
    bool_71 = ecx > 0x0;
    if (ecx >= 0x0) {
            if (!bool_71) {
                    if (edx > 0x2) {
                            esi = 0x1;
                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                    var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
                                    if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) != esi) {
                                            ecx = var_18[0x2];
                                            esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
                                            edi = esi + ecx + 0x14;
                                            esp = esp - 0x8;
                                            arg_4 = *(esi + ecx + 0x18);
                                            eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
                                            eax = *eax;
                                            if (eax != 0x0) {
                                                    if (eax != edi) {
                                                            sub_47a948();
                                                            if (arg_0 != arg_4) {
                                                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                                                    bool_87 = HIBYTE(eax) == 0x41;
                                                                    eax = eax & 0xff;
                                                                    if (!bool_87) {
                                                                            eax = 0x14;
                                                                    }
                                                                    if (eax == arg_14 && *var_10 == 0x0) {
                                                                            eax = var_C;
                                                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0) {
                                                                                            if (arg_24 == 0x0) {
                                                                                                    ebx[0x2ebb7c] = 0x1;
                                                                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (arg_0 != arg_4) {
                                                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                                                    bool_79 = HIBYTE(eax) == 0x41;
                                                                    eax = eax & 0xff;
                                                                    if (!bool_79) {
                                                                            eax = 0x14;
                                                                    }
                                                                    if (eax == arg_14 && *var_10 == 0x0) {
                                                                            eax = var_C;
                                                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0) {
                                                                                            if (arg_24 == 0x0) {
                                                                                                    ebx[0x2ebb7c] = 0x1;
                                                                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (arg_0 != arg_4) {
                                                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                                            bool_151 = HIBYTE(eax) == 0x41;
                                                            eax = eax & 0xff;
                                                            if (!bool_151) {
                                                                    eax = 0x14;
                                                            }
                                                            if (eax == arg_14 && *var_10 == 0x0) {
                                                                    eax = var_C;
                                                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                                                    ebx[0x2ebb7c] = 0x1;
                                                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                            ebx[0x2ebb7c] = 0x1;
                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    esi = 0x1;
                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                            var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
                            if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) != esi) {
                                    ecx = var_18[0x2];
                                    esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
                                    edi = esi + ecx + 0x14;
                                    esp = esp - 0x8;
                                    arg_4 = *(esi + ecx + 0x18);
                                    eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
                                    eax = *eax;
                                    if (eax != 0x0) {
                                            if (eax != edi) {
                                                    sub_47a948();
                                                    if (arg_0 != arg_4) {
                                                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                                            bool_164 = HIBYTE(eax) == 0x41;
                                                            eax = eax & 0xff;
                                                            if (!bool_164) {
                                                                    eax = 0x14;
                                                            }
                                                            if (eax == arg_14 && *var_10 == 0x0) {
                                                                    eax = var_C;
                                                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                                                    ebx[0x2ebb7c] = 0x1;
                                                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (arg_0 != arg_4) {
                                                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                                            bool_172 = HIBYTE(eax) == 0x41;
                                                            eax = eax & 0xff;
                                                            if (!bool_172) {
                                                                    eax = 0x14;
                                                            }
                                                            if (eax == arg_14 && *var_10 == 0x0) {
                                                                    eax = var_C;
                                                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                                                    ebx[0x2ebb7c] = 0x1;
                                                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (arg_0 != arg_4) {
                                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                                    bool_180 = HIBYTE(eax) == 0x41;
                                                    eax = eax & 0xff;
                                                    if (!bool_180) {
                                                            eax = 0x14;
                                                    }
                                                    if (eax == arg_14 && *var_10 == 0x0) {
                                                            eax = var_C;
                                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                                            ebx[0x2ebb7c] = 0x1;
                                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                    ebx[0x2ebb7c] = 0x1;
                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                            }
                                    }
                            }
                    }
            }
    }
    goto loc_441685;

loc_44156e:
    if ((eax[0x14833a] | eax[0x14833b]) == 0x0) goto .l3;
    goto loc_44157c;

.l7:
    if (bool_193) goto .l12;
    goto .l8;

.l3:
    var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
    if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) != 0x1) {
            ecx = var_18[0x2];
            esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
            edi = esi + ecx + 0x14;
            esp = esp - 0x8;
            arg_4 = *(esi + ecx + 0x18);
            eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
            eax = *eax;
            if (eax != 0x0) {
                    if (eax != edi) {
                            sub_47a948();
                    }
                    if (arg_0 != arg_4) {
                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                            bool_102 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_102) {
                                    eax = 0x14;
                            }
                            if (eax == arg_14 && *var_10 == 0x0) {
                                    eax = var_C;
                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                    ebx[0x2ebb7c] = 0x1;
                                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                            }
                                    }
                            }
                    }
            }
            else {
                    sub_47a948();
                    if (arg_0 != arg_4) {
                            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                            bool_31 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_31) {
                                    eax = 0x14;
                            }
                            if (eax == arg_14 && *var_10 == 0x0) {
                                    eax = var_C;
                                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0) {
                                                    if (arg_24 == 0x0) {
                                                            ebx[0x2ebb7c] = 0x1;
                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                            ebx[0x2ebb7c] = 0x1;
                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                    }
            }
    }
    goto loc_441685;

loc_44157c:
    bool_24 = ecx > 0x0;
    if (ecx < 0x0) goto loc_441685;
    goto loc_441584;

.l12:
    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
            var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
            if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) != 0x1) {
                    ecx = var_18[0x2];
                    esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
                    edi = esi + ecx + 0x14;
                    esp = esp - 0x8;
                    arg_4 = *(esi + ecx + 0x18);
                    eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
                    eax = *eax;
                    if (eax != 0x0) {
                            if (eax != edi) {
                                    sub_47a948();
                            }
                            if (arg_0 != arg_4) {
                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                    bool_218 = HIBYTE(eax) == 0x41;
                                    eax = eax & 0xff;
                                    if (!bool_218) {
                                            eax = 0x14;
                                    }
                                    if (eax == arg_14 && *var_10 == 0x0) {
                                            eax = var_C;
                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                            ebx[0x2ebb7c] = 0x1;
                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            sub_47a948();
                            if (arg_0 != arg_4) {
                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                    bool_226 = HIBYTE(eax) == 0x41;
                                    eax = eax & 0xff;
                                    if (!bool_226) {
                                            eax = 0x14;
                                    }
                                    if (eax == arg_14 && *var_10 == 0x0) {
                                            eax = var_C;
                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                            ebx[0x2ebb7c] = 0x1;
                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                    ebx[0x2ebb7c] = 0x1;
                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                            }
                    }
            }
    }
    goto loc_441685;

.l8:
    if (edx <= 0x2 || eax[0x14833a] != 0x1 || eax[0x14833b] != 0x0) goto loc_441685;
    goto .l9;

loc_441584:
    if (bool_24) goto .l4;
    goto loc_441586;

.l9:
    var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
    if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) == 0x1) goto .l11;
    goto .l10;

.l4:
    esi = 0x1;
    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
            var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
            if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) != esi) {
                    ecx = var_18[0x2];
                    esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
                    edi = esi + ecx + 0x14;
                    esp = esp - 0x8;
                    arg_4 = *(esi + ecx + 0x18);
                    eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
                    eax = *eax;
                    if (eax != 0x0) {
                            if (eax != edi) {
                                    sub_47a948();
                            }
                            if (arg_0 != arg_4) {
                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                    bool_127 = HIBYTE(eax) == 0x41;
                                    eax = eax & 0xff;
                                    if (!bool_127) {
                                            eax = 0x14;
                                    }
                                    if (eax == arg_14 && *var_10 == 0x0) {
                                            eax = var_C;
                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                            ebx[0x2ebb7c] = 0x1;
                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            sub_47a948();
                            if (arg_0 != arg_4) {
                                    eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
                                    bool_114 = HIBYTE(eax) == 0x41;
                                    eax = eax & 0xff;
                                    if (!bool_114) {
                                            eax = 0x14;
                                    }
                                    if (eax == arg_14 && *var_10 == 0x0) {
                                            eax = var_C;
                                            if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                                                    if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                                            ebx[0x2ebb7c] = 0x1;
                                                            *(arg_1c * 0x4 + 0xba3770) = arg_18;
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                    ebx[0x2ebb7c] = 0x1;
                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                            }
                    }
            }
    }
    goto loc_441685;

loc_441586:
    if (edx <= 0x2) goto loc_441685;
    goto loc_44158f;

.l11:
    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                    ebx[0x2ebb7c] = 0x1;
                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
            }
    }
    goto loc_441685;

.l10:
    ecx = var_18[0x2];
    esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
    edi = esi + ecx + 0x14;
    esp = esp - 0x8;
    arg_4 = *(esi + ecx + 0x18);
    eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
    eax = *eax;
    if (eax == 0x0) goto loc_441603;
    goto loc_4415ff;

loc_44158f:
    esi = 0x1;
    if (eax[0x14833a] != 0x1 || eax[0x14833b] != 0x0) goto loc_441685;
    goto loc_4415a8;

loc_441603:
    sub_47a948();
    goto loc_441608;

loc_4415ff:
    if (eax != edi) {
            sub_47a948();
    }
    if (arg_0 != arg_4) {
            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
            bool_201 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_201) {
                    eax = 0x14;
            }
            if (eax == arg_14 && *var_10 == 0x0) {
                    eax = var_C;
                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                    ebx[0x2ebb7c] = 0x1;
                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                            }
                    }
            }
    }
    goto loc_441685;

loc_4415a8:
    var_10 = ((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc;
    if (*(((arg_18 << 0x4) - arg_18) * 0x8 + 0xbaeddc) == esi) goto loc_44163d;
    goto loc_4415c7;

loc_441608:
    if (arg_0 != arg_4) {
            eax = *(int16_t *)(esi + var_18[0x2] + 0x20);
            bool_139 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_139) {
                    eax = 0x14;
            }
            if (eax == arg_14 && *var_10 == 0x0) {
                    eax = var_C;
                    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
                            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                                    ebx[0x2ebb7c] = 0x1;
                                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
                            }
                    }
            }
    }
    goto loc_441685;

loc_44163d:
    if (ebx[0x2ebb7c] == 0x0 && (ebx[0x2ebb7a] & ebx[0x2ebb7b]) == 0xffffffff) {
            if ((eax[0x13db3a] | eax[0x13db3b]) == 0x0 && arg_24 == 0x0) {
                    ebx[0x2ebb7c] = 0x1;
                    *(arg_1c * 0x4 + 0xba3770) = arg_18;
            }
    }
    goto loc_441685;

loc_4415c7:
    ecx = var_18[0x2];
    esi = arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8 + arg_1c + arg_1c * 0x8;
    edi = esi + ecx + 0x14;
    esp = esp - 0x8;
    arg_4 = *(esi + ecx + 0x18);
    eax = sub_401ff0(&arg_8, &arg_14, var_2C, var_28, var_24);
    eax = *eax;
    if (eax == 0x0 || eax != edi) {
            sub_47a948();
    }
    goto loc_441608;
}
