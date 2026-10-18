// sub_465800 @ 0x465800
// hopper name: sub_465800
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465800() {
    decomp_var_8 = esi;
    esi = *ecx[0x9];
    decomp_var_c = edi;
    edi = arg_0;
    esp = esp - 0x10;
    var_4 = 0x0;
    *edi = esi;
    sub_4931ea(0x0);
    eax = esi[0x1];
    if (eax < 0xffffffff) {
            esi[0x1] = eax + 0x1;
    }
    sub_49320b();
    eax = edi;
    return eax;
}
