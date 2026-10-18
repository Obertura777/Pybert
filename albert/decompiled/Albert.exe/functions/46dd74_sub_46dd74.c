// sub_46dd74 @ 0x46dd74
// hopper name: sub_46dd74
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46dd74() {
    ebx = ecx;
    eax = *ebx;
    edi = *(eax - 0xc);
    esi = arg_0 - eax;
    esp = esp - 0x8;
    var_4 = arg_4 + edi;
    eax = sub_40b8d0(arg_4 + edi);
    if (esi <= edi) {
            esi = esi + eax;
    }
    else {
            esi = arg_0;
    }
    sub_47a5af(eax + edi, arg_4, esi, arg_4);
    eax = sub_40b6a0();
    return eax;
}
