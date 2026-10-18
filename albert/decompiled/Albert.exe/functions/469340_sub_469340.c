// sub_469340 @ 0x469340
// hopper name: sub_469340
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_469340() {
    var_C = *0x0;
    decomp_var_14 = esi;
    esp = esp - 0x18;
    decomp_var_18 = *dword_4c8db8 ^ &decomp_var_14;
    *0x0 = &var_C;
    esi = ecx;
    if (sub_493721() == 0x0) {
            sub_469080();
    }
    eax = *esi;
    eax = *(*(*eax + 0x4) + eax + 0x28);
    if (eax != 0x0) {
            eax = sub_493604();
    }
    *0x0 = var_C;
    return eax;
}
