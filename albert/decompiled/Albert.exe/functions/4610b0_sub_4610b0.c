// sub_4610b0 @ 0x4610b0
// hopper name: sub_4610b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4610b0() {
    edi = ecx[0x1];
    ebx = sub_401b00(edi, edi[0x1], arg_0);
    eax = sub_403ec0(0x1);
    edi[0x1] = ebx;
    *ebx[0x1] = ebx;
    return eax;
}
