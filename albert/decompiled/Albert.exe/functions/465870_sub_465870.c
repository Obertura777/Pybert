// sub_465870 @ 0x465870
// hopper name: sub_465870
// referenced by: called,immediate
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465870() {
    eax = ecx;
    *eax = 0x0;
    eax[0x1] = ecx | 0xffffffff;
    eax[0x2] = 0x0;
    eax[0x3] = ecx | 0xffffffff;
    return eax;
}
