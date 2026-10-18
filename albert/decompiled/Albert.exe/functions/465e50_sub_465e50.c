// sub_465e50 @ 0x465e50
// hopper name: sub_465e50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465e50() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if ((esi[0x40] & 0x1) != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    *esi[0x4] = 0x0;
    *esi[0x8] = 0x0;
    *esi[0xc] = 0x0;
    *esi[0x5] = 0x0;
    eax = esi[0x9];
    *eax = 0x0;
    *esi[0xd] = 0x0;
    esi[0x10] = esi[0x10] & 0xfffffffe;
    esi[0xf] = 0x0;
    return eax;
}
