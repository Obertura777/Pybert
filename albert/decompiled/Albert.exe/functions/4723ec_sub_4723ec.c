// sub_4723ec @ 0x4723ec
// hopper name: sub_4723ec
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4723ec() {
    edx = arg_0;
    eax = edx[0x1];
    if (eax >= 0x100) {
            if (eax > 0x109) {
                    if (eax >= 0x200 && eax <= 0x209) {
                            loc_476713();
                    }
            }
            else {
                    loc_476713();
            }
    }
    else {
            if (eax >= 0x200 && eax <= 0x209) {
                    loc_476713();
            }
    }
    return;
}
