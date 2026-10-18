// sub_4667a0 @ 0x4667a0
// hopper name: sub_4667a0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4667a0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = (*(*esi + 0x10))(decomp_var_4);
    if (eax == 0xffffffff) {
            eax = eax | eax;
    }
    else {
            eax = esi[0xc];
            *eax = *eax - 0x1;
            eax = esi[0x8];
            ecx = *eax;
            *eax = ecx + 0x1;
            eax = *(int8_t *)ecx & 0xff;
    }
    return eax;
}
