// sub_4656f0 @ 0x4656f0
// hopper name: sub_4656f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4656f0() {
    eax = arg_0 * arg_4;
    if (HIDWORD(arg_0 * arg_4) > 0x0 || eax > 0xffffffff) {
            sub_40b5a0(0x80070057);
    }
    return;
}
