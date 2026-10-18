// sub_45d120 @ 0x45d120
// hopper name: sub_45d120
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d120() {
    *(int8_t *)ecx = *(int8_t *)arg_0 & 0xff;
    ecx[0x1] = arg_0[0x1] & 0xff;
    sub_40c410(arg_0 + 0x4);
    ecx[0x8] = arg_0[0x8] & 0xff;
    ecx[0x5] = arg_0[0x5];
    ecx[0xc] = arg_0[0xc];
    ecx[0x4] = arg_0[0x4];
    ecx[0x14] = arg_0[0x14] & 0xff;
    sub_40c410(arg_0 + 0x18);
    ecx[0x7] = arg_0[0x7];
    eax = ecx;
    return eax;
}
