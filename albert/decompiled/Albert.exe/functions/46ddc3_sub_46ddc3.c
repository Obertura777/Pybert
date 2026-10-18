// sub_46ddc3 @ 0x46ddc3
// hopper name: sub_46ddc3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ddc3() {
    decomp_var_4 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    edi = ecx;
    if (esi == 0x0) {
            eax = 0x0;
    }
    else {
            eax = sub_47d630(esi);
            esp = (esp - 0x4) + 0x4;
    }
    sub_46dd74(esi, eax);
    return;
}
