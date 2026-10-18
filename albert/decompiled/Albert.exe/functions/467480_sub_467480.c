// sub_467480 @ 0x467480
// hopper name: sub_467480
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467480() {
    if (ecx[0x9] >= 0x10) {
            eax = ecx[0x4];
    }
    else {
            eax = ecx + 0x10;
    }
    return eax;
}
