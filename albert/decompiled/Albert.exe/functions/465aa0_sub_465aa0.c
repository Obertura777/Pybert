// sub_465aa0 @ 0x465aa0
// hopper name: sub_465aa0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465aa0() {
    var_C = *0x0;
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ &decomp_var_1c;
    *0x0 = &var_C;
    esi = ecx;
    if (*esi == 0x0) {
            eax = sub_46dbce(0xa);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    esp = esp - 0x14;
                    *eax = 0x3;
                    sub_47bba4();
                    eax = eax + 0x4;
            }
            else {
                    eax = 0x0;
            }
            *(int16_t *)eax = *(int16_t *)word_4c79b4 & 0xffff;
            eax[0x1] = *(int16_t *)word_4c79b8;
            eax[0x2] = *(int16_t *)word_4c7d14 & 0xffff;
            *esi = eax;
            eax = esi[0x2];
            esi[0x1] = 0x2;
            esi[0x3] = 0x1;
            if (eax != 0x0) {
                    *eax = 0x0;
                    *(esi[0x2] + 0x4) = 0x2;
                    *0x0 = var_C;
            }
            else {
                    *0x0 = var_C;
            }
    }
    else {
            edi = esi[0x1];
            edi = edi + 0x3;
            eax = sub_46dbce(-((-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(edi * 0x2) ? 0x1 : 0x0) | edi * 0x2) + 0x4);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    esp = esp - 0x14;
                    *eax = edi;
                    sub_47bba4();
                    edi = eax + 0x4;
            }
            else {
                    edi = 0x0;
            }
            ecx = esi[0x1];
            sub_47c000(edi + 0x2, *esi, ecx + ecx);
            *(int16_t *)edi = *(int16_t *)word_4c79b4;
            *(int16_t *)(edi + esi[0x1] * 0x2 + 0x2) = *(int16_t *)word_4c79b8;
            *(int16_t *)(edi + esi[0x1] * 0x2 + 0x4) = *(int16_t *)word_4c7d14;
            eax = *esi;
            esp = (esp - 0xc) + 0xc;
            if (eax != 0x0) {
                    sub_47b6f8();
                    sub_47c8f9();
                    esp = (esp - 0x14) + 0x4;
            }
            eax = esi[0x2];
            esi[0x1] = esi[0x1] + 0x2;
            *esi = edi;
            esi[0x3] = 0x1;
            if (eax != 0x0) {
                    *eax = 0x0;
                    edx = esi[0x2];
                    eax = esi[0x1];
                    edx[0x1] = eax;
            }
            *0x0 = var_C;
    }
    return eax;
}
