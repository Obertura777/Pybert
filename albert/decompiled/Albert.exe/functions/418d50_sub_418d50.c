// sub_418d50 @ 0x418d50
// hopper name: sub_418d50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_418d50() {
    *ecx = arg_0;
    ecx[0x1] = arg_4;
    ecx[0x2] = arg_8;
    ecx[0x6] = *(int16_t *)arg_c;
    *(ecx + 0x28) = 0xf;
    *(ecx + 0x24) = 0x0;
    *(int8_t *)(ecx + 0x14) = 0x0;
    sub_4024f0(arg_c + 0x4, 0x0, 0xffffffff, esi);
    ecx[0x2c] = arg_4;
    ecx[0x2d] = 0x0;
    eax = ecx;
    return eax;
}
