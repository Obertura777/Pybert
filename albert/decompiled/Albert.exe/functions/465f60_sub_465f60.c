// sub_465f60 @ 0x465f60
// hopper name: sub_465f60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465f60() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    ecx = arg_0;
    *esi = 0x0;
    esi[0x2] = 0x0;
    eax = *ecx;
    if (eax != 0x0) {
            sub_465940(eax, ecx[0x1], decomp_var_4);
            eax = esi;
    }
    else {
            esi[0x1] = eax | 0xffffffff;
            esi[0x3] = eax | 0xffffffff;
            *esi = 0x0;
            esi[0x2] = 0x0;
            eax = esi;
    }
    return eax;
}
