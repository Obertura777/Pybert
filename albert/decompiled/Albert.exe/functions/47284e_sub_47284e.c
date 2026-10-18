// sub_47284e @ 0x47284e
// hopper name: sub_47284e
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47284e() {
    eax = arg_14;
    esp = esp - 0xc;
    if (eax == 0x0) {
            edi = 0x0;
    }
    else {
            edi = eax[0x8];
    }
    edx = arg_10[0x1];
    esi = *arg_10;
    arg_0 = edi;
    edi = arg_10[0x3];
    eax = arg_10[0x2];
    eax = (*(*ecx + 0x5c))(arg_0, arg_18, arg_1c, arg_c, esi, edx, eax - esi, edi - edx, arg_0, arg_18, arg_1c);
    return eax;
}
