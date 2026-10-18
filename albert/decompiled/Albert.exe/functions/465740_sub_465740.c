// sub_465740 @ 0x465740
// hopper name: sub_465740
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465740() {
    var_4 = ecx;
    decomp_var_8 = esi;
    decomp_var_c = edi;
    edi = ecx;
    esp = esp - 0x10;
    sub_4931ea(0x0);
    eax = edi[0x1];
    if (eax > 0x0 && eax < 0xffffffff) {
            edi[0x1] = eax - 0x1;
    }
    esi = edi[0x1];
    sub_49320b();
    eax = !(--esi - --esi + CARRY(EFLAGS(cf))) & edi;
    return eax;
}
