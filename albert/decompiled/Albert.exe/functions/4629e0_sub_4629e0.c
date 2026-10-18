// sub_4629e0 @ 0x4629e0
// hopper name: sub_4629e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4629e0() {
    var_C = *0x0;
    decomp_var_50 = ebx;
    decomp_var_58 = esi;
    *0x0 = &var_C;
    var_48 = 0xffffffff;
    sub_465870();
    edi = arg_4;
    var_40 = 0x0;
    eax = sub_466060(&var_3C, 0x0);
    esp = esp - 0x6c;
    sub_465ff0(eax);
    sub_465fa0();
    esi = arg_0;
    if (sub_4658e0() != 0x0) {
            esp = esp - 0x4;
            eax = sub_4658f0(&arg_4);
            eax = *(int16_t *)eax;
            arg_4 = eax;
            arg_0 = eax;
            if (*(int16_t *)word_4c7670 == eax) {
                    esi[0x4] = 0x1;
            }
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&arg_4, 0x1);
            arg_4 = *(int16_t *)eax;
            arg_0 = *(int16_t *)word_4c7674;
    }
    esp = esp - 0x4;
    eax = sub_4075b0(&arg_c, decomp_var_58);
    ebp = eax;
    if (arg_4 != 0x0) {
            var_40 = 0x0;
    }
    else {
            esi = 0x1;
            if (sub_465930() > 0x1) {
                    do {
                            eax = sub_466060(&var_14, esi);
                            esp = esp - 0xc;
                            sub_465ff0(eax);
                            arg_0 = 0x0;
                            sub_465fa0();
                            if (sub_4658e0() != 0x0) {
                                    esp = esp - 0x4;
                                    eax = sub_4658f0(&arg_c);
                                    eax = arg_8;
                            }
                            else {
                                    eax = sub_465900(&var_44, 0x0);
                                    esp = esp - 0x10;
                                    eax = sub_465900(&var_42, 0x1);
                                    eax = *(int16_t *)eax;
                            }
                            esp = esp - 0x8;
                            eax = sub_404e10(&var_2C, &var_34);
                            esi = esi + 0x1;
                    } while (esi < sub_465930());
            }
    }
    sub_465fa0();
    eax = var_38;
    *0x0 = arg_0;
    return eax;
}
