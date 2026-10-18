// sub_465e10 @ 0x465e10
// hopper name: sub_465e10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465e10() {
    eax = *(ecx - 0x4);
    *(eax[0x1] + (ecx - 0x4)) = 0x4b1c44;
    return eax;
}
