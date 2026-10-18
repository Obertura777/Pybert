// sub_4689b0 @ 0x4689b0
// hopper name: sub_4689b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4689b0() {
    decomp_var_1c = ebx;
    ebx = arg_c;
    decomp_var_20 = ebp;
    ebp = arg_8;
    decomp_var_24 = esi;
    esp = esp - 0x28;
    decomp_var_28 = edi;
    edi = arg_14;
    while (true) {
            esi = arg_18;
            eax = sub_47bf50(edi, 0x0, esi);
            esp = (esp - 0xc) + 0xc;
            if (eax != 0x0) {
                    esi = eax - edi;
            }
            decomp_var_3c = ebp;
            eax = sub_4688b0(arg_0, &var_18, decomp_var_3c, decomp_var_38, decomp_var_34, edi, esi);
            ecx = eax[0x2];
            ebp = *eax;
            ebx = eax[0x1];
            esp = (esp - 0x1c) + 0x1c;
            edi = edi + esi;
            arg_18 = arg_18 - esi;
            arg_10 = ecx;
            if (arg_18 == 0x0) {
                    break;
            }
            ecx = arg_1c;
            if (ecx != 0x0) {
                    eax = eax[0x2];
                    decomp_var_3c = ebp;
                    eax = sub_468930(arg_0, &var_C, decomp_var_3c, ebx, eax, ecx, 0x1);
                    ebp = *eax;
                    ebx = eax[0x1];
                    esp = (esp - 0x1c) + 0x1c;
                    arg_10 = eax[0x2];
            }
            edi = edi + 0x1;
            arg_18 = arg_18 - 0x1;
    }
    eax = eax[0x2];
    *arg_4 = ebp;
    arg_4[0x1] = ebx;
    arg_4[0x2] = eax;
    eax = arg_4;
    return eax;
}
