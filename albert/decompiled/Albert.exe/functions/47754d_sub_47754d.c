// sub_47754d @ 0x47754d
// hopper name: sub_47754d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47754d() {
    decomp_var_4 = ebx;
    esi = ecx;
    ebx = esi + 0x1c;
    esp = esp - 0x10;
    EnterCriticalSection(ebx);
    edi = arg_4;
    if (edi > 0x0) {
            if (edi < esi[0x3]) {
                    esp = esp - 0x4;
                    eax = TlsGetValue(*esi);
                    if (eax != 0x0) {
                            if (edi < eax[0x2]) {
                                    edi = *(eax[0x3] + edi * 0x4);
                                    esp = esp - 0x4;
                                    LeaveCriticalSection(ebx);
                                    eax = edi;
                            }
                            else {
                                    esp = esp - 0x4;
                                    LeaveCriticalSection(ebx);
                                    eax = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            LeaveCriticalSection(ebx);
                            eax = 0x0;
                    }
            }
            else {
                    esp = esp - 0x4;
                    LeaveCriticalSection(ebx);
                    eax = 0x0;
            }
    }
    else {
            esp = esp - 0x4;
            LeaveCriticalSection(ebx);
            eax = 0x0;
    }
    return eax;
}
