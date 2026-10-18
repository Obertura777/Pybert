// sub_46a740 @ 0x46a740
// hopper name: sub_46a740
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46a740() {
    var_C = *0x0;
    decomp_var_38 = ebx;
    decomp_var_3c = esi;
    decomp_var_40 = edi;
    decomp_var_44 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = ecx;
    edi = 0x0;
    esp = esp - 0x48;
    var_18 = 0x0;
    sub_468ff0(esi);
    if (var_24 != 0x0) {
            ecx = *esi;
            eax = sub_465800(&var_1C);
            edi = sub_4690e0(eax);
            sub_465790();
            ecx = *esi;
            edx = ecx[0x1];
            ecx = edx + esi;
            decomp_var_5c = 0x0;
            esp = (esp - 0x8) + 0x4 - 0x1c;
            (*(*edi + 0x1c))(&var_34);
            edi = 0x4;
            if (0x0 == 0x0) {
                    edi = var_18;
            }
    }
    ecx = *esi;
    ecx = ecx[0x1];
    ecx = ecx + esi;
    if (edi != 0x0) {
            eax = ecx[0x2];
            eax = eax | edi;
            if (ecx[0xa] == 0x0) {
                    eax = eax | 0x4;
            }
            esp = esp - 0x8;
            sub_467d70(eax, 0x0);
    }
    sub_469340();
    eax = esi;
    *0x0 = var_C;
    &var_34 = ebp;
    return eax;
}
