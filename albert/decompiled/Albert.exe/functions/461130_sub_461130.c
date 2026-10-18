// sub_461130 @ 0x461130
// hopper name: sub_461130
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_461130() {
    decomp_var_c = *0x0;
    decomp_var_68 = ebx;
    decomp_var_6c = ebp;
    decomp_var_70 = esi;
    decomp_var_74 = edi;
    esp = esp - 0x78;
    *0x0 = &decomp_var_c;
    edi = ecx;
    esi = esi | 0xffffffff;
    eax = sub_401e30();
    decomp_var_4c = eax;
    eax[0x11] = 0x1;
    decomp_var_4c[0x1] = decomp_var_4c;
    *decomp_var_4c = decomp_var_4c;
    ebp = 0x0;
    decomp_var_4c[0x2] = decomp_var_4c;
    decomp_var_48 = 0x0;
    decomp_var_64 = *(int16_t *)word_4c77e8;
    sub_465870();
    ebx = arg_0;
    decomp_var_4 = 0x1;
    if (sub_465930() > 0x0) {
            while (true) {
                    if (esi != 0xffffffff) {
                            temp_0 = 0x1;
                            break;
                    }
                    eax = sub_466060(&decomp_var_18, ebp);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
                    sub_465fa0();
                    if (sub_4658e0() == 0x0) {
                            if (sub_4658d0() > 0x0) {
                                    sub_4612d0(decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            ebp = &arg_fffffffffffffffd;
                            if (ebp < sub_465930()) {
                                    edi = decomp_var_50;
                                    continue;
                            }
                            temp_0 = 0x2;
                            break;
                    }
                    esp = esp - 0x4;
                    eax = sub_4658f0(&decomp_var_5c);
                    ecx = *(int16_t *)eax;
                    decomp_var_58 = ecx;
                    if (decomp_var_57 == 0x41) {
                            eax = decomp_var_58 & 0xff;
                            if (eax < edi[0x901]) {
                                    decomp_var_60 = eax;
                                    esp = esp - 0x8;
                                    eax = sub_404ce0(&decomp_var_40, &decomp_var_60, decomp_var_74);
                                    decomp_var_60 = decomp_var_58;
                            }
                            else {
                                    esp = esp - 0x4;
                                    esi = sub_466110(ebp);
                            }
                    }
                    else {
                            if ((decomp_var_58 & 0xf800) == 0x5000) {
                                    bool_6 = *(int8_t *)(edi + ((decomp_var_58 & 0xff) + (decomp_var_58 & 0xff) * 0x8) * 0x4 + 0x2) != 0x0;
                                    edi = edi + ((decomp_var_58 & 0xff) + (decomp_var_58 & 0xff) * 0x8) * 0x4;
                                    if (!bool_6) {
                                            *(int16_t *)edi = ecx;
                                            esp = esp - 0x4;
                                            edi[0x2] = 0x1;
                                            eax = sub_41c0b0(&decomp_var_4c);
                                            edi[0x3] = 0x1;
                                            edi[0x10] = decomp_var_60;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            esi = sub_466110(ebp);
                                    }
                            }
                            else {
                                    if (*(int16_t *)word_4c77e8 != ecx) {
                                            esp = esp - 0x4;
                                            esi = sub_466110(ebp);
                                    }
                            }
                    }
                    ebp = &arg_fffffffffffffffd;
                    if (ebp < sub_465930()) {
                            edi = decomp_var_50;
                            continue;
                    }
                    temp_0 = 0x2;
                    break;
            }
            if (temp_0 != 0x0) {
                    sub_465fa0();
                    sub_403430(&decomp_var_50, &decomp_var_48, *decomp_var_44, &decomp_var_48, decomp_var_44);
                    sub_47c8f9();
                    *0x0 = decomp_var_4;
            }
    }
    else {
            sub_465fa0();
            sub_403430(&decomp_var_50, &decomp_var_48, *decomp_var_44, &decomp_var_48, decomp_var_44);
            sub_47c8f9();
            *0x0 = decomp_var_4;
    }
    return;
}
