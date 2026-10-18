// sub_46be30 @ 0x46be30
// hopper name: sub_46be30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46be30() {
    var_C = *0x0;
    *0x0 = &var_C;
    eax = ecx[0x4];
    sub_46bab0(&var_14, ecx + 0xc, *eax, ecx + 0xc, eax);
    sub_47c8f9();
    *(ecx + 0x10) = 0x0;
    *(ecx + 0x14) = 0x0;
    eax = ecx[0x1];
    sub_46b9e0(&var_14, ecx, *eax, ecx, eax);
    eax = sub_47c8f9();
    ecx[0x1] = 0x0;
    ecx[0x2] = 0x0;
    *0x0 = var_C;
    return eax;
}
