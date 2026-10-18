// sub_468db0 @ 0x468db0
// hopper name: sub_468db0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468db0() {
    ecx = ecx[0x5];
    esi = arg_0;
    eax = ecx;
    esp = esp - 0xc;
    var_C = edi;
    esi[0x6] = 0xf;
    esi[0x5] = 0x0;
    esi[0x4] = 0x0;
    edi = eax + 0x1;
    &var_C = &var_C;
    do {
            edx = *(int8_t *)eax;
            eax = eax + 0x1;
    } while (edx != 0x0);
    sub_402650(ecx, eax - edi);
    eax = esi;
    return eax;
}
