// sub_47ff12 @ 0x47ff12
// hopper name: sub_47ff12
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ff12() {
    if (*dword_4c8fc0 != 0xffffffff) {
            esp = (esp - 0x8) + 0x4;
            (sub_47fe7c(*dword_bc6514))();
            *dword_4c8fc0 = *dword_4c8fc0 | 0xffffffff;
    }
    if (*dword_4c8fc4 != 0xffffffff) {
            esp = esp - 0x4;
            TlsFree(*dword_4c8fc4);
            *dword_4c8fc4 = *dword_4c8fc4 | 0xffffffff;
    }
    decomp_var_c = ebx;
    decomp_var_10 = esi;
    esi = 0x4c9980;
    esp = esp - 0xc;
    decomp_var_14 = edi;
    do {
            edi = *esi;
            if (edi != 0x0 && esi[0x1] != 0x1) {
                    DeleteCriticalSection(edi);
                    sub_47c8f9();
                    *esi = *esi & 0x0;
                    esp = (esp - 0x8) + 0x4;
            }
            esi = esi + 0x8;
    } while (esi < 0x4c9aa0);
    esi = 0x4c9980;
    esp = esp + 0x4;
    do {
            eax = *esi;
            if (eax != 0x0 && esi[0x1] == 0x1) {
                    esp = esp - 0x4;
                    eax = DeleteCriticalSection(eax);
            }
            esi = esi + 0x8;
    } while (esi < 0x4c9aa0);
    return eax;
}
