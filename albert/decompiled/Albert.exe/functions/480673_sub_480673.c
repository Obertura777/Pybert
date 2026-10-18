// sub_480673 @ 0x480673
// hopper name: sub_480673
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480673() {
    if (edi == 0x0) {
            sub_4810dd();
            loc_481091();
    }
    else {
            var_8 = var_8 & 0x0;
            var_1 = 0x0;
            if (*edi > 0x0) {
                    decomp_var_10 = ebx;
                    esp = esp - 0x8;
                    decomp_var_14 = esi;
                    do {
                            eax = arg_0[0x7];
                            eax = eax[0x3];
                            ebx = *eax;
                            esi = eax + 0x4;
                            if (ebx > 0x0) {
                                    var_C = var_8 << 0x4;
                                    while (true) {
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_480421(edi[0x1] + var_C, *esi, arg_0[0x7]) != 0x0) {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            ebx = ebx - 0x1;
                                            esi = esi + 0x4;
                                            if (ebx > 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (temp_0 != 0x0) {
                                            var_1 = 0x1;
                                    }
                            }
                            var_8 = var_8 + 0x1;
                    } while (var_8 < *edi);
            }
    }
    return;
}
