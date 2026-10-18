// sub_468e00 @ 0x468e00
// hopper name: sub_468e00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468e00() {
    var_C = *0x0;
    decomp_var_18 = ebx;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    decomp_var_24 = *dword_4c8db8 ^ &decomp_var_20;
    *0x0 = &var_C;
    eax = sub_465800(&var_14);
    edi = var_14;
    esp = (esp - 0x2c) + 0x4;
    ebx = sub_4684e0(eax);
    if (edi != 0x0) {
            esp = esp - 0x4;
            sub_4931ea(0x0);
            eax = edi[0x1];
            if (eax > 0x0 && eax < 0xffffffff) {
                    edi[0x1] = eax - 0x1;
            }
            esi = edi[0x1];
            esi = !(-esi - -esi + CARRY(EFLAGS(cf))) & edi;
            sub_49320b();
            if (esi != 0x0) {
                    esp = esp - 0x4;
                    (**esi)(0x1);
            }
    }
    eax = (*(*ebx + 0x18))(arg_0);
    *0x0 = var_C;
    return eax;
}
