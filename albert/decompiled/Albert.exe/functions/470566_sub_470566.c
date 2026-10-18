// sub_470566 @ 0x470566
// hopper name: sub_470566
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470566() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    esi = ecx;
    eax = sub_4715ba(decomp_var_8, decomp_var_4);
    eax = eax[0x1];
    if (eax != 0x0) {
            esp = esp - 0x4;
            sub_46ff82(0x0);
    }
    eax = esi[0x1a];
    if (eax != 0x0) {
            eax = eax[0x8];
    }
    edi = sub_46fee4(eax, esi + 0x6c, decomp_var_8, decomp_var_4);
    sub_47550c();
    eax = edi;
    return eax;
}
