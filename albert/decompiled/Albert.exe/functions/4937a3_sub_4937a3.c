// sub_4937a3 @ 0x4937a3
// hopper name: sub_4937a3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4937a3() {
    if (*dword_4ca4bc == 0x0) {
            eax = *dword_4ca4bc;
            sub_48a6f5();
    }
    eax = *dword_4ca4bc;
    eax = eax - 0x1;
    *dword_4ca4bc = eax;
    *(eax * 0x4 + 0xbc7160) = arg_0;
    return eax;
}
