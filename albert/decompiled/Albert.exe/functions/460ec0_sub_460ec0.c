// sub_460ec0 @ 0x460ec0
// hopper name: sub_460ec0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460ec0() {
    decomp_var_18 = ebx;
    ebx = arg_0;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    edi = ecx;
    esp = esp - 0x2c;
    ebp = ebp | 0xffffffff;
    eax = sub_465900(&arg_0, 0x0);
    arg_0 = *(int16_t *)eax;
    esi = 0x1;
    if (sub_4658d0() > 0x1) {
            while (true) {
                    if (ebp != 0xffffffff) {
                            temp_0 = 0x0;
                            break;
                    }
                    esp = esp - 0x8;
                    eax = sub_465900(&var_12, esi);
                    eax = *(int8_t *)eax & 0xff;
                    if (eax >= edi[0x900]) {
                            ebp = esi;
                    }
                    else {
                            *(int16_t *)(edi + (eax + eax * 0x8) * 0x4 + 0x20) = arg_0;
                            if (edi[0x1212] == arg_0) {
                                    var_10 = eax;
                                    esp = esp - 0x8;
                                    eax = sub_404ce0(&var_C, &var_10, decomp_var_24);
                            }
                    }
                    esi = esi + 0x1;
                    if (esi < sub_4658d0()) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
    }
    eax = ebp;
    return eax;
}
