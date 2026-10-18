// sub_46a890 @ 0x46a890
// hopper name: sub_46a890
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46a890() {
    var_C = *0x0;
    decomp_var_18 = ebx;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    esp = esp - 0x28;
    decomp_var_28 = *dword_4c8db8 ^ &decomp_var_24;
    *0x0 = &var_C;
    edi = ecx;
    if (arg_4 != 0x0) {
            *edi = 0x4b1ddc;
            edi[0x13] = 0x4b1c4c;
    }
    *(edi + *(*edi + 0x4)) = 0x4b1c44;
    esi = *(*edi + 0x4);
    esi = esi + edi;
    sub_467ec0();
    ebx = edi + 0x4;
    esp = esp - 0x4;
    esi[0xa] = ebx;
    esi[0xb] = 0x0;
    eax = sub_468e00(0x20);
    bool_1 = esi[0xa] != 0x0;
    esi[0x30] = eax;
    if (!bool_1) {
            esp = esp - 0x8;
            sub_467d70(esi[0x2] | 0x4 | 0x4, 0x0);
    }
    esi[0x1] = 0x0;
    *(edi + *(*edi + 0x4)) = 0x4b1ccc;
    sub_467400(arg_0 | 0x2);
    eax = edi;
    *0x0 = var_C;
    return eax;
}
