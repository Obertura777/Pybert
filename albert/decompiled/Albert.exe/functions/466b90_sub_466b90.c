// sub_466b90 @ 0x466b90
// hopper name: sub_466b90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466b90() {
    var_C = *0x0;
    decomp_var_18 = ebx;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    decomp_var_24 = *dword_4c8db8 ^ &decomp_var_20;
    *0x0 = &var_C;
    ebx = ecx;
    *ebx = 0x4b1c54;
    sub_4935ce();
    esi = sub_46dbce(0x4);
    esp = (esp - 0x28) + 0x4;
    if (esi != 0x0) {
            *esi = sub_493444();
            esp = esp - 0x4;
            edi = sub_493278();
            sub_4931ea(0x0);
            eax = edi[0x1];
            if (eax < 0xffffffff) {
                    edi[0x1] = eax + 0x1;
            }
            sub_49320b();
    }
    else {
            esi = 0x0;
    }
    ebx[0xe] = esi;
    sub_465ed0();
    eax = ebx;
    *0x0 = var_C;
    return eax;
}
