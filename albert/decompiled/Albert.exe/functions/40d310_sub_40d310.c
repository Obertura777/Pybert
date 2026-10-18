// sub_40d310 @ 0x40d310
// hopper name: sub_40d310
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40d310() {
    var_C = *0x0;
    decomp_var_24 = edi;
    esp = esp - 0x28;
    decomp_var_28 = *dword_4c8db8 ^ &decomp_var_24;
    *0x0 = &var_C;
    esi = ecx;
    ebp = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    ebx = 0x0;
    *(int16_t *)arg_0 = 0x0;
    edi = sub_465930();
    if (edi <= 0x2) {
            var_10 = &decomp_var_38;
            esp = esp - 0x14;
            eax = sub_465f60(&arg_4);
            sub_40d0a0(decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28) == 0x1;
    }
    esi = 0x0;
    if (edi > 0x0) {
            do {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_10, esi);
                    eax = *(int8_t *)eax & 0xff;
                    if (eax == ebp) {
                            ebx = 0x1;
                    }
                    else {
                    }
                    esi = esi + 0x1;
            } while (esi < edi);
            if (ebx == 0x0) {
                    *(int16_t *)arg_50 = *(int16_t *)word_4c6d48;
            }
            else {
                    if (arg_13 == 0x1) {
                            if (arg_12 == 0x1) {
                                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d48;
                            }
                            else {
                                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                            }
                    }
                    else {
                            *(int16_t *)arg_50 = *(int16_t *)word_4c6d90;
                    }
            }
    }
    else {
            *(int16_t *)arg_50 = *(int16_t *)word_4c6d48;
    }
    sub_465fa0();
    sub_465fa0();
    eax = arg_50;
    *0x0 = arg_40;
    return eax;
}
