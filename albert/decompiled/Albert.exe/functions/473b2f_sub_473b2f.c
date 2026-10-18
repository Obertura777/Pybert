// sub_473b2f @ 0x473b2f
// hopper name: sub_473b2f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473b2f() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    esp = esp - 0x8;
    esi = ecx;
    if (ebx == 0x0) {
            eax = 0x0;
    }
    else {
            edi = sub_473a7a();
            esi[0x8] = ebx;
            *sub_47939c(ebx) = esi;
            sub_476858(edi);
            eax = 0x1;
            esp = (esp - 0x10) + 0x4;
    }
    return eax;
}
