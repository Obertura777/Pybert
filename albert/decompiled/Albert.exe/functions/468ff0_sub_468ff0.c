// sub_468ff0 @ 0x468ff0
// hopper name: sub_468ff0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468ff0() {
    var_C = *0x0;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    esp = esp - 0x1c;
    decomp_var_1c = *dword_4c8db8 ^ &decomp_var_18;
    *0x0 = &var_C;
    edi = ecx;
    esi = arg_0;
    *edi = esi;
    eax = *(*(*esi + 0x4) + esi + 0x28);
    if (eax != 0x0) {
            sub_4935fb();
    }
    eax = *(*esi + 0x4);
    eax = eax + esi;
    if (eax[0x2] == 0x0) {
            eax = eax[0xb];
            if (eax != 0x0) {
                    sub_468fa0();
            }
    }
    edi[0x4] = *(*(*esi + 0x4) + esi + 0x8) == 0x0 ? 0x1 : 0x0;
    eax = edi;
    *0x0 = var_C;
    return eax;
}
