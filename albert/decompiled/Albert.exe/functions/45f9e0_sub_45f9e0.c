// sub_45f9e0 @ 0x45f9e0
// hopper name: sub_45f9e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f9e0() {
    if (*dword_bc2128 != 0x0) {
            sub_47bc7c();
            esp = (esp - 0x4) + 0x4;
    }
    eax = *dword_bc212c;
    if (*dword_bc212c != 0x0) {
            eax = sub_47bc7c();
    }
    return eax;
}
