// sub_465790 @ 0x465790
// hopper name: sub_465790
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465790() {
    var_4 = ecx;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = *ecx;
    if (edi != 0x0) {
            esp = esp - 0x4;
            sub_4931ea(0x0);
            eax = edi[0x1];
            if (eax > 0x0 && eax < 0xffffffff) {
                    edi[0x1] = eax - 0x1;
            }
            esp = esp - 0x4;
            decomp_var_c = esi;
            esi = edi[0x1];
            esi = !(-esi - -esi + CARRY(EFLAGS(cf))) & edi;
            sub_49320b();
            if (esi != 0x0) {
                    esp = esp - 0x4;
                    (**esi)(0x1);
            }
            esp = esp + 0x4;
    }
    return;
}
