// sub_470188 @ 0x470188
// hopper name: sub_470188
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470188() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_4;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (esi == 0x0) {
            sub_46dedc();
    }
    edi = arg_8;
    if (edi == 0x0) {
            sub_46dedc();
    }
    eax = sub_4715ba();
    eax = eax[0x3];
    eax = sub_40b630(eax, arg_0);
    esp = (esp - 0x8) + 0x8;
    if (eax == 0x0) {
            *(int8_t *)esi = 0x0;
    }
    else {
            esp = esp - 0x20;
            *(int8_t *)(WideCharToMultiByte(0x0, 0x0, eax + 0x2, *(int16_t *)eax & 0xffff, esi, edi - 0x1, 0x0, 0x0) + esi) = 0x0;
    }
    return;
}
