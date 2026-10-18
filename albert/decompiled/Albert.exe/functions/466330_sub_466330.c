// sub_466330 @ 0x466330
// hopper name: sub_466330
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466330() {
    var_C = *0x0;
    decomp_var_18 = ebx;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    esp = esp - 0x28;
    *0x0 = &var_C;
    edi = ecx;
    esi = arg_0;
    *esi = 0x0;
    esi[0x1] = ecx | 0xffffffff;
    esi[0x2] = 0x0;
    esi[0x3] = ecx | 0xffffffff;
    var_4 = 0x0;
    var_14 = 0x1;
    if (*edi == 0x0) {
            esp = esp - 0x4;
            sub_465ff0(arg_4);
    }
    else {
            ebp = arg_4;
            if (*ebp == 0x0) {
                    esp = esp - 0x4;
                    sub_465ff0(edi);
            }
            else {
                    ebx = edi[0x1] + arg_0 + 0x1;
                    eax = sub_46dbce(-((-(OVERFLOW(ebx * 0x2) ? 0x1 : 0x0) | ebx * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(ebx * 0x2) ? 0x1 : 0x0) | ebx * 0x2) + 0x4);
                    esp = (esp - 0x4) + 0x4;
                    var_10 = eax;
                    var_4 = 0x1;
                    if (eax != 0x0) {
                            *eax = ebx;
                            esp = esp - 0x14;
                            sub_47bba4();
                            eax = eax + 0x4;
                    }
                    else {
                            eax = 0x0;
                    }
                    *esi = eax;
                    ecx = edi[0x1];
                    sub_47c000(eax, *edi, ecx + ecx);
                    sub_47c000(*esi + edi[0x1] * 0x2, *ebp, arg_0 + arg_0);
                    *(int16_t *)(*esi + (edi[0x1] + arg_0) * 0x2) = *(int16_t *)word_4c7d14;
                    esp = (esp - 0x18) + 0x18;
                    esi[0x1] = edi[0x1] + arg_0;
                    esi[0x3] = arg_8 + edi[0x3];
            }
    }
    eax = esi;
    *0x0 = var_4;
    return eax;
}
