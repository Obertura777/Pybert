// sub_466c40 @ 0x466c40
// hopper name: sub_466c40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466c40() {
    var_C = *0x0;
    decomp_var_38 = ebx;
    decomp_var_3c = ebp;
    decomp_var_40 = esi;
    esp = esp - 0x48;
    *0x0 = &var_C;
    edi = ecx;
    esi = arg_0;
    *esi = 0x0;
    esi[0x1] = ecx | 0xffffffff;
    esi[0x2] = 0x0;
    esi[0x3] = ecx | 0xffffffff;
    var_34 = 0x1;
    if (*edi == 0x0) {
            eax = sub_4661a0(&var_2C);
            esp = esp - 0x8;
            sub_465ff0(eax);
            var_4 = 0x0;
            sub_465fa0();
    }
    else {
            ebp = arg_4;
            if (*ebp == 0x0) {
                    eax = sub_4661a0(&var_1C);
                    eax = sub_466330(&var_2C, eax);
                    esp = esp - 0x10;
                    sub_465ff0(eax);
                    sub_465fa0();
                    var_4 = 0x0;
                    sub_465fa0();
            }
            else {
                    ebx = edi[0x1] + arg_0 + 0x3;
                    eax = sub_46dbce(-((-(OVERFLOW(ebx * 0x2) ? 0x1 : 0x0) | ebx * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(ebx * 0x2) ? 0x1 : 0x0) | ebx * 0x2) + 0x4);
                    esp = (esp - 0x4) + 0x4;
                    var_30 = eax;
                    var_4 = 0x4;
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
                    sub_47c000(*esi + edi[0x1] * 0x2 + 0x2, *ebp, arg_0 + arg_0);
                    *(int16_t *)(*esi + edi[0x1] * 0x2) = *(int16_t *)word_4c79b4 & 0xffff;
                    *(int16_t *)(*esi + (edi[0x1] + arg_0) * 0x2 + 0x2) = *(int16_t *)word_4c79b8 & 0xffff;
                    *(int16_t *)(*esi + (edi[0x1] + arg_0) * 0x2 + 0x4) = *(int16_t *)word_4c7d14 & 0xffff;
                    esi[0x1] = edi[0x1] + arg_0 + 0x2;
                    esp = (esp - 0x18) + 0x18;
                    esi[0x3] = edi[0x3] + 0x1;
            }
    }
    eax = esi;
    *0x0 = var_4;
    return eax;
}
