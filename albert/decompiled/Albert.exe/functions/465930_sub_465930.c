// sub_465930 @ 0x465930
// hopper name: sub_465930
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465930() {
    ecx = ecx[0x3];
    eax = -(ecx - 0xffffffff) - -(ecx - 0xffffffff) + CARRY(EFLAGS(cf)) & ecx;
    return eax;
}
