// sub_45d450 @ 0x45d450
// hopper name: sub_45d450
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d450() {
    ecx[0x1] = arg_4;
    *ecx = arg_0;
    ecx[0x2] = arg_8;
    *(ecx + 0x24) = 0xf;
    *(ecx + 0x20) = 0x0;
    *(int8_t *)(ecx + 0x10) = 0x0;
    sub_4024f0(arg_c, 0x0, 0xffffffff, edi, esi, ebp);
    *(int16_t *)(ecx + 0x28) = arg_18;
    ecx[0x2c] = arg_4;
    ecx[0x2d] = 0x0;
    eax = ecx;
    return eax;
}
