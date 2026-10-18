// sub_4603d0 @ 0x4603d0
// hopper name: sub_4603d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4603d0() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = ecx;
    eax = (eax | 0xffffffff) - esi[0x5];
    if (eax <= ebx) {
            sub_492f96();
    }
    if (ebx > 0x0) {
            esp = esp - 0x4;
            decomp_var_c = edi;
            edi = esi[0x5];
            edi = edi + ebx;
            if (edi > 0xfffffffe) {
                    sub_492f96();
            }
            eax = esi[0x6];
            bool_9 = eax <= edi;
            if (eax < edi) {
                    esp = esp - 0x8;
                    sub_401c20(edi, esi[0x5]);
                    if (!bool_9) {
                            esp = esp - 0xc;
                            sub_4600b0(esi[0x5], ebx, arg_4, decomp_var_c, decomp_var_8, decomp_var_4);
                            bool_4 = esi[0x6] < 0x10;
                            esi[0x5] = edi;
                            if (!bool_4) {
                                    *(int8_t *)(esi[0x1] + edi) = 0x0;
                                    eax = esi;
                            }
                            else {
                                    *(int8_t *)(esi + 0x4 + edi) = 0x0;
                                    esp = esp + 0x4;
                                    eax = esi;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                            eax = esi;
                    }
            }
            else {
                    bool_3 = edi <= 0x0;
                    if (edi == 0x0) {
                            esi[0x5] = edi;
                            if (eax >= 0x10) {
                                    *(int8_t *)esi[0x1] = 0x0;
                                    eax = esi;
                            }
                            else {
                                    esi[0x4] = 0x0;
                                    eax = esi;
                            }
                    }
                    else {
                            if (!bool_3) {
                                    esp = esp - 0xc;
                                    sub_4600b0(esi[0x5], ebx, arg_4, decomp_var_c, decomp_var_8, decomp_var_4);
                                    bool_2 = esi[0x6] < 0x10;
                                    esi[0x5] = edi;
                                    if (!bool_2) {
                                            *(int8_t *)(esi[0x1] + edi) = 0x0;
                                            eax = esi;
                                    }
                                    else {
                                            *(int8_t *)(esi + 0x4 + edi) = 0x0;
                                            esp = esp + 0x4;
                                            eax = esi;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                                    eax = esi;
                            }
                    }
            }
    }
    else {
            eax = esi;
    }
    return eax;
}
