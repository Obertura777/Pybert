// sub_468fa0 @ 0x468fa0
// hopper name: sub_468fa0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468fa0() {
    decomp_var_4 = esi;
    esi = ecx;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    eax = *(*esi + 0x4) + esi;
    edi = 0x0;
    if ((eax[0x8] & 0x6) == 0x0 && (*(*eax[0xa] + 0x30))() == 0xffffffff) {
            edi = 0x4;
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
    eax = esi;
    return eax;
}
