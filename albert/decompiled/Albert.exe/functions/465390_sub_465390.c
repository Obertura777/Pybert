// sub_465390 @ 0x465390
// hopper name: sub_465390
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465390() {
    var_C = *0x0;
    decomp_var_30 = ebx;
    decomp_var_34 = ebp;
    decomp_var_38 = esi;
    decomp_var_3c = edi;
    esp = esp - 0x40;
    decomp_var_40 = *dword_4c8db8 ^ &decomp_var_3c;
    *0x0 = &var_C;
    ebx = ecx;
    esi = esi | 0xffffffff;
    sub_465870();
    ebp = arg_0;
    edi = 0x0;
    if (sub_465930() > 0x0) {
            while (true) {
                    if (esi != 0xffffffff) {
                            temp_0 = 0x0;
                            break;
                    }
                    eax = sub_466060(&var_1C, edi);
                    sub_465ff0(eax);
                    sub_465fa0();
                    esp = esp - 0x10;
                    eax = sub_463ea0(&var_2C);
                    esi = eax;
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
    sub_465fa0();
    eax = esi;
    *0x0 = var_C;
    return eax;
}
