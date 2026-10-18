// sub_45cb30 @ 0x45cb30
// hopper name: sub_45cb30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45cb30() {
    decomp_var_c = ebx;
    ebx = arg_4;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esi = arg_8;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    edi = ecx;
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1 = esi == edi[0x1];
    ebp = *esi;
    if (!bool_1) {
            *esi[0x1] = ebp;
            *(*esi + 0x4) = esi[0x1];
            sub_45b740();
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            edi[0x2] = edi[0x2] - 0x1;
    }
    eax = arg_0;
    eax[0x1] = ebp;
    *eax = ebx;
    return eax;
}
