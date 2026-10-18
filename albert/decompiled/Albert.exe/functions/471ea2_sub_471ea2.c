// sub_471ea2 @ 0x471ea2
// hopper name: sub_471ea2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471ea2() {
    ebx = 0x0;
    decomp_var_c = esi;
    esp = esp - 0x8;
    decomp_var_10 = edi;
    if (arg_8 > 0x0) {
            while (true) {
                    var_1 = 0x0;
                    edi = arg_4 + ebx * 0x4;
                    esi = 0x0;
                    do {
                            esp = esp - 0x8;
                            eax = lstrcmpW(*edi, esi[0x132244]);
                            if (eax == 0x0) {
                                    eax = esi[0x132230];
                                    var_1 = 0x1;
                                    *(arg_10 + ebx * 0x4) = eax;
                            }
                            esi = esi + 0x4;
                    } while (esi < 0x4c);
                    if (var_1 == 0x0) {
                            eax = 0x80020006;
                            temp_0 = 0x1;
                            break;
                    }
                    ebx = ebx + 0x1;
                    if (ebx < arg_8) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 == 0x0) {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
