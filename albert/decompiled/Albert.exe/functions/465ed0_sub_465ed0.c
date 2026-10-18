// sub_465ed0 @ 0x465ed0
// hopper name: sub_465ed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465ed0() {
    ecx[0x8] = ecx + 0x18;
    ecx[0x9] = ecx + 0x1c;
    ecx[0x4] = ecx + 0x8;
    ecx[0xc] = ecx + 0x28;
    ecx[0x5] = ecx + 0xc;
    ecx[0xd] = ecx + 0x2c;
    ecx[0x3] = 0x0;
    *ecx[0x9] = 0x0;
    *ecx[0xd] = 0x0;
    *ecx[0x4] = 0x0;
    *ecx[0x8] = 0x0;
    eax = ecx[0xc];
    *eax = 0x0;
    return eax;
}
