// sub_4661a0 @ 0x4661a0
// hopper name: sub_4661a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4661a0() {
    var_C = *0x0;
    decomp_var_18 = ebx;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    esp = esp - 0x28;
    *0x0 = &var_C;
    edi = ecx;
    esi = arg_0;
    *esi = 0x0;
    esi[0x1] = &var_C | 0xffffffff;
    esi[0x2] = 0x0;
    esi[0x3] = &var_C | 0xffffffff;
    var_14 = 0x1;
    if (*edi == 0x0) {
            eax = sub_46dbce(0xa);
            esp = (esp - 0x4) + 0x4;
            var_10 = eax;
            var_4 = 0x1;
            if (eax != 0x0) {
                    esp = esp - 0x14;
                    *eax = 0x3;
                    sub_47bba4();
                    eax = eax + 0x4;
            }
            else {
                    eax = 0x0;
            }
            *esi = eax;
            *(int16_t *)eax = *(int16_t *)word_4c79b4;
            *(int16_t *)(*esi + 0x2) = *(int16_t *)word_4c79b8;
            *(int16_t *)(*esi + 0x4) = *(int16_t *)word_4c7d14;
            esi[0x1] = 0x2;
            esi[0x3] = 0x1;
    }
    else {
            ebp = &arg_ffffffffffffffff;
            eax = sub_46dbce(-((-(OVERFLOW(ebp * 0x2) ? 0x1 : 0x0) | ebp * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(ebp * 0x2) ? 0x1 : 0x0) | ebp * 0x2) + 0x4);
            esp = (esp - 0x4) + 0x4;
            var_10 = eax;
            var_4 = 0x2;
            if (eax != 0x0) {
                    esp = esp - 0x14;
                    *eax = ebp;
                    sub_47bba4();
                    eax = eax + 0x4;
            }
            else {
                    eax = 0x0;
            }
            *esi = eax;
            ecx = edi[0x1];
            sub_47c000(eax + 0x2, *edi, ecx + ecx);
            *(int16_t *)*esi = *(int16_t *)word_4c79b4 & 0xffff;
            *(int16_t *)(*esi + edi[0x1] * 0x2 + 0x2) = *(int16_t *)word_4c79b8 & 0xffff;
            *(int16_t *)(*esi + edi[0x1] * 0x2 + 0x4) = *(int16_t *)word_4c7d14 & 0xffff;
            esp = (esp - 0xc) + 0xc;
            esi[0x1] = edi[0x1] + 0x2;
            esi[0x3] = 0x1;
    }
    eax = esi;
    *0x0 = var_4;
    return eax;
}
