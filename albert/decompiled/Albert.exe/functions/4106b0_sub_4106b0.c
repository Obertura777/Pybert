// sub_4106b0 @ 0x4106b0
// hopper name: sub_4106b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4106b0() {
    eax = ecx[0x1];
    eax = eax - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            decomp_var_4 = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_4);
    }
    return eax;
}
