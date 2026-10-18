// sub_4675e0 @ 0x4675e0
// hopper name: sub_4675e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4675e0() {
    decomp_var_14 = ebx;
    ebx = arg_4;
    var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    esi = ecx;
    edi = sub_45bcf0(ebx, decomp_var_1c);
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi != esi[0x1]) {
            bool_1 = edi[0x9] < 0x10;
            eax = edi[0x8];
            if (!bool_1) {
                    edi = edi[0x4];
            }
            else {
                    edi = edi + 0x10;
            }
            var_18 = eax;
            decomp_var_1c = edi;
            esp = esp - 0x10;
            if (sub_40e9b0() >= 0x0) {
                    ecx = &var_18;
            }
            else {
                    var_10 = esi;
                    ecx = &var_10;
            }
    }
    else {
            var_10 = esi;
            ecx = &var_10;
    }
    edx = *ecx;
    eax = arg_0;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    return eax;
}
