// sub_478104 @ 0x478104
// hopper name: sub_478104
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478104() {
    esp = esp - 0x4;
    decomp_var_4 = edi;
    edi = arg_0;
    if (edi >= 0x11) {
            sub_46dedc();
    }
    if (*dword_bc627c == 0x0) {
            sub_47809b();
    }
    decomp_var_8 = ebx;
    decomp_var_c = ebp;
    esp = esp - 0xc;
    decomp_var_10 = esi;
    esi = edi * 0x4 + 0xbc6430;
    if (*esi == 0x0) {
            esp = esp - 0x4;
            EnterCriticalSection(0xbc6418);
            if (*esi == 0x0) {
                    esp = esp - 0x4;
                    InitializeCriticalSection(edi * 0x18 + 0xbc6280);
                    *esi = *esi + 0x1;
            }
            esp = esp - 0x4;
            LeaveCriticalSection(0xbc6418);
    }
    EnterCriticalSection(edi * 0x18 + 0xbc6280, decomp_var_10, decomp_var_c, decomp_var_8);
    return;
}
