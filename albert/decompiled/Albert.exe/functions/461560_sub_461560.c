// sub_461560 @ 0x461560
// hopper name: sub_461560
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_461560() {
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    esi = ecx + 0x2450;
    esp = esp - 0x28;
    eax = sub_402060(&var_8, &arg_0, decomp_var_20, decomp_var_1c, decomp_var_18);
    ebp = *eax;
    edi = eax[0x1];
    ebx = esi[0x1];
    var_10 = ebp;
    var_C = edi;
    if (ebp == 0x0 || ebp != esi) {
            sub_47a948();
    }
    if (edi == ebx) {
            eax = 0x0;
    }
    else {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (edi == arg_0) {
                    sub_47a948();
            }
            edi[0x8] = 0x6;
            if (edi == arg_0) {
                    sub_47a948();
            }
            edi[0x9] = arg_4;
            if (edi == arg_0) {
                    sub_47a948();
            }
            edi[0x14] = *(int16_t *)word_4c7670;
            if (edi == arg_0) {
                    sub_47a948();
            }
            ebp = edi + 0x34;
            sub_401850();
            eax = arg_8;
            if (eax > 0x0) {
                    ebx = arg_c;
                    arg_0 = eax;
                    while (true) {
                            if (edi == saved_fp[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x10;
                            edi = sub_401b00(arg_0, arg_0[0x1], ebx);
                            sub_403ec0(0x1);
                            arg_0[0x1] = edi;
                            ebx = ebx + 0x4;
                            arg_10 = arg_10 - 0x1;
                            *edi[0x1] = edi;
                            if (arg_10 == 0x0) {
                                    break;
                            }
                            edi = arg_0;
                    }
            }
            eax = 0x1;
    }
    return eax;
}
