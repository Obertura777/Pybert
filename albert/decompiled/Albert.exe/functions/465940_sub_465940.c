// sub_465940 @ 0x465940
// hopper name: sub_465940
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465940() {
    var_4 = 0xffffffff;
    var_8 = 0x499b7b;
    var_C = *0x0;
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    esp = esp - 0x24;
    *0x0 = &var_C;
    esi = ecx;
    eax = *esi;
    var_10 = 0xffffffff;
    if (eax != 0x0) {
            edi = eax - 0x4;
            sub_47b6f8();
            sub_47c8f9();
            esp = (esp - 0x14) + 0x4;
            *esi = 0x0;
    }
    eax = esi[0x2];
    if (eax != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            esi[0x2] = 0x0;
    }
    ebx = 0x0;
    ebp = arg_4;
    eax = 0x0;
    esi[0x1] = 0xffffffff;
    esi[0x3] = 0x0;
    if (ebp > 0x0) {
            do {
                    edi = edi | 0xffffffff;
                    if (var_10 != edi) {
                            break;
                    }
                    if (ebx == 0x0) {
                            esi[0x3] = esi[0x3] + 0x1;
                    }
                    ecx = *(int16_t *)(arg_0 + eax * 0x2) & 0xffff;
                    if (*(int16_t *)word_4c79b4 == ecx) {
                            ebx = ebx + 0x1;
                    }
                    if (*(int16_t *)word_4c79b8 == ecx) {
                            ebx = ebx - 0x1;
                            if (ebx < 0x0) {
                                    var_10 = eax;
                            }
                    }
                    eax = eax + 0x1;
            } while (eax < ebp);
            if (ebx != 0x0) {
                    esi[0x3] = edi;
                    *0x0 = var_4;
            }
            else {
                    edi = &arg_fffffffffffffffd;
                    eax = sub_46dbce(-((-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) + 0x4);
                    esp = (esp - 0x4) + 0x4;
                    var_4 = 0x0;
                    if (eax != 0x0) {
                            esp = esp - 0x14;
                            *eax = edi;
                            sub_47bba4();
                            eax = eax + 0x4;
                    }
                    else {
                            eax = 0x0;
                    }
                    *esi = eax;
                    sub_47c000(eax, arg_8, ebp + ebp);
                    *(int16_t *)(ebp + ebp + *esi) = *(int16_t *)word_4c7d14;
                    eax = var_8;
                    esp = (esp - 0xc) + 0xc;
                    esi[0x1] = ebp;
                    *0x0 = var_4;
            }
    }
    else {
            edi = &arg_fffffffffffffffd;
            eax = sub_46dbce(-((-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) + 0x4);
            esp = (esp - 0x4) + 0x4;
            var_4 = 0x0;
            if (eax != 0x0) {
                    esp = esp - 0x14;
                    *eax = edi;
                    sub_47bba4();
                    eax = eax + 0x4;
            }
            else {
                    eax = 0x0;
            }
            *esi = eax;
            sub_47c000(eax, arg_8, ebp + ebp);
            *(int16_t *)(ebp + ebp + *esi) = *(int16_t *)word_4c7d14;
            eax = var_8;
            esp = (esp - 0xc) + 0xc;
            esi[0x1] = ebp;
            *0x0 = var_4;
    }
    return eax;
}
