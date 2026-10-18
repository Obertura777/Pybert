// sub_480003 @ 0x480003
// hopper name: sub_480003
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480003() {
    edi = GetLastError();
    sub_47fee8();
    decomp_var_4 = *dword_4c8fc0;
    esp = esp - 0x10;
    decomp_var_8 = *dword_4c8fc4;
    esi = (TlsGetValue(*dword_4c8fc4))(saved_fp);
    if (esi == 0x0) {
            esi = sub_4812c0(0x1, 0x214);
            esp = (esp - 0x8) + 0x8;
            if (esi != 0x0) {
                    esp = (esp - 0xc) + 0x4;
                    if ((sub_47fe7c(*dword_bc6510))() != 0x0) {
                            decomp_var_10 = 0x0;
                            decomp_var_14 = esi;
                            sub_47ff4f();
                            esp = (esp - 0x8) + 0x8;
                            eax = GetCurrentThreadId();
                            esi[0x1] = esi[0x1] | 0xffffffff;
                            *esi = eax;
                    }
                    else {
                            decomp_var_10 = esi;
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                            esi = 0x0;
                    }
            }
    }
    SetLastError(edi);
    eax = esi;
    return eax;
}
