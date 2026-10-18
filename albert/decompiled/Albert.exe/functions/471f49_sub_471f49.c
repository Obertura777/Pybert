// sub_471f49 @ 0x471f49
// hopper name: sub_471f49
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_471f49() {
    bool_0 = ecx[0x8] == 0x0;
    eax = *ecx;
    if (!bool_0) {
            (eax[0x18])();
    }
    else {
            (eax[0x45])();
    }
    return;
}
