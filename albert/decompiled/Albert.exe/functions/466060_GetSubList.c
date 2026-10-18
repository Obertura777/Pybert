// GetSubList @ 0x466060
// hopper name: sub_466060
// pybert name: GetSubList
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

GetSubList() {
    var_C = *0x0;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    esp = esp - 0x1c;
    decomp_var_1c = *dword_4c8db8 ^ &decomp_var_18;
    *0x0 = &var_C;
    esi = ecx;
    edi = arg_0;
    *edi = 0x0;
    edi[0x1] = ecx | 0xffffffff;
    edi[0x2] = 0x0;
    edi[0x3] = ecx | 0xffffffff;
    var_4 = 0x0;
    var_10 = 0x1;
    if (*esi != 0x0) {
            if (esi[0x2] == 0x0) {
                    sub_465c70();
            }
            edx = arg_4;
            if (edx < esi[0x3]) {
                    ecx = esi[0x2] + edx * 0x4;
                    eax = ecx[0x1];
                    eax = eax - *ecx;
                    if (eax == 0x1) {
                            esp = esp - 0x8;
                    }
                    else {
                            esp = esp - 0x8;
                    }
                    sub_465940(decomp_var_1c, decomp_var_18, decomp_var_14);
            }
    }
    eax = edi;
    *0x0 = var_4;
    return eax;
}
