// sub_4714e0 @ 0x4714e0
// hopper name: sub_4714e0
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4714e0() {
    esi = decomp_var_14;
    esp = esp - 0x4;
    esi[0xc] = 0x1;
    esi[0x11] = 0x18;
    esi[0x1e] = sub_46dbce(saved_fp);
    if (sub_477525() != 0x0) {
            eax = sub_47119c();
    }
    else {
            eax = 0x0;
    }
    *esi[0x1e] = eax;
    if (sub_477525() != 0x0) {
            eax = sub_4713c0();
    }
    else {
            eax = 0x0;
    }
    *(esi[0x1e] + 0x4) = eax;
    esi[0x1f] = 0x1;
    esi[0x20] = 0x0;
    sub_47d75a();
    return;
}
