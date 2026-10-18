// sub_465ff0 @ 0x465ff0
// hopper name: sub_465ff0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465ff0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = *esi;
    if (eax != 0x0) {
            sub_47b6f8();
            sub_47c8f9();
            *esi = 0x0;
            esp = (esp - 0x18) + 0x8;
    }
    eax = esi[0x2];
    if (eax != 0x0) {
            eax = sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            esi[0x2] = 0x0;
    }
    ecx = arg_0;
    esi[0x1] = eax | 0xffffffff;
    esi[0x3] = eax | 0xffffffff;
    eax = *ecx;
    if (eax != 0x0) {
            esp = esp - 0x8;
            sub_465940(eax, ecx[0x1], decomp_var_4);
    }
    eax = esi;
    return eax;
}
