// sub_461e20 @ 0x461e20
// hopper name: sub_461e20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_461e20() {
    var_C = *0x0;
    decomp_var_20 = ebx;
    decomp_var_24 = ebp;
    decomp_var_28 = esi;
    decomp_var_2c = edi;
    esp = esp - 0x30;
    decomp_var_30 = *dword_4c8db8 ^ &decomp_var_2c;
    *0x0 = &var_C;
    ebp = ecx;
    ebx = arg_0;
    esi = esi | 0xffffffff;
    edi = 0x0;
    if (sub_465930() > 0x0) {
            while (true) {
                    if (esi != 0xffffffff) {
                            temp_0 = 0x0;
                            break;
                    }
                    eax = sub_466060(&var_1C, edi);
                    esp = esp - 0xc;
                    esi = sub_461130(eax);
                    sub_465fa0();
                    if (esi != 0xffffffff) {
                            esp = esp - 0x4;
                            esi = esi + sub_466110(edi);
                    }
                    edi = edi + 0x1;
                    if (edi < sub_465930()) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
    }
    eax = esi;
    *0x0 = var_C;
    return eax;
}
