// sub_46a1f0 @ 0x46a1f0
// hopper name: sub_46a1f0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46a1f0() {
    eax = *(*arg_4 + 0x4);
    eax = eax + arg_4;
    ecx = eax[0x2];
    ecx = ecx | 0x4;
    if (eax[0xa] == 0x0) {
            ecx = ecx | 0x4;
    }
    eax[0x2] = ecx & 0x17;
    if ((ecx & 0x17) == 0x0) {
            eax = 0x46a21a;
    }
    else {
            eax = sub_47a958(0x0, 0x0);
    }
    return eax;
}
