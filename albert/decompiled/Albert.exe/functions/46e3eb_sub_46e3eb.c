// sub_46e3eb @ 0x46e3eb
// hopper name: sub_46e3eb
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e3eb() {
    eax = sub_46f313();
    if (eax != 0x0) {
            eax = eax[0xf];
            if (eax != 0x0) {
                    (eax)(0x1, 0x1);
            }
    }
    PostQuitMessage(saved_fp);
    return;
}
