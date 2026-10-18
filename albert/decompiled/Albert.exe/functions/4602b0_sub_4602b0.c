// sub_4602b0 @ 0x4602b0
// hopper name: sub_4602b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4602b0() {
    eax = sub_46dbce(0x2c);
    if (eax != 0x0) {
            *eax = 0x0;
    }
    ecx = eax + 0x4;
    if (ecx != 0x0) {
            *ecx = 0x0;
    }
    ecx = eax + 0x8;
    if (ecx != 0x0) {
            *ecx = 0x0;
    }
    eax[0x28] = 0x1;
    eax[0x29] = 0x0;
    return;
}
