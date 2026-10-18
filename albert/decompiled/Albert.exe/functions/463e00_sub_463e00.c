// sub_463e00 @ 0x463e00
// hopper name: sub_463e00
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_463e00() {
    var_C = *0x0;
    decomp_var_1c = edi;
    *0x0 = &var_C;
    *(int16_t *)ecx = 0x0;
    eax = sub_40fd90();
    *(ecx + 0xc) = eax;
    eax[0x1d] = 0x1;
    eax = *(ecx + 0xc);
    eax[0x1] = eax;
    eax = *(ecx + 0xc);
    *eax = eax;
    eax = *(ecx + 0xc);
    eax[0x2] = eax;
    *(ecx + 0x10) = 0x0;
    eax = sub_401e30();
    *(ecx + 0x18) = eax;
    eax[0x11] = 0x1;
    eax = *(ecx + 0x18);
    eax[0x1] = eax;
    eax = *(ecx + 0x18);
    *eax = eax;
    eax = *(ecx + 0x18);
    eax[0x2] = eax;
    *(ecx + 0x1c) = 0x0;
    ecx[0x10] = 0x0;
    eax = ecx;
    *0x0 = var_C;
    return eax;
}
