// sub_466160 @ 0x466160
// hopper name: sub_466160
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466160() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    esi = ecx;
    if (edi < esi[0x3] && edi >= 0x0) {
            if (esi[0x2] == 0x0) {
                    sub_465c70();
            }
            eax = esi[0x2];
            eax = *(eax + edi * 0x4 + 0x4) - *(eax + edi * 0x4) == 0x1 ? 0x1 : 0x0;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
