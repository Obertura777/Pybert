// sub_472897 @ 0x472897
// hopper name: sub_472897
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_472897() {
    eax = arg_10;
    esp = esp - 0xc;
    if (eax == 0x0) {
            edi = 0x0;
    }
    else {
            edi = eax[0x8];
    }
    edx = arg_c[0x1];
    esi = *arg_c;
    ebx = *ecx;
    arg_fffffffffffffffc = edi;
    edi = arg_c[0x3];
    eax = arg_c[0x2];
    eax = (ebx[0x17])(0x0, arg_14, arg_18, arg_8 | 0x40000000, esi, edx, eax - esi, edi - edx, arg_fffffffffffffffc, arg_14, arg_18);
    return eax;
}
