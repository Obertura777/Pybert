// sub_47780f @ 0x47780f
// hopper name: sub_47780f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47780f() {
    ebx = ecx;
    decomp_var_c = edi;
    esp = esp - 0x8;
    decomp_var_10 = ebx + 0x1c;
    var_4 = ebx + 0x1c;
    eax = EnterCriticalSection(decomp_var_10);
    edi = arg_0;
    if (edi > 0x0 && edi < ebx[0x3]) {
            esp = esp - 0x4;
            for (esi = ebx[0x5]; esi != 0x0; esi = esi[0x1]) {
                    if (edi < esi[0x2]) {
                            ecx = *(esi[0x3] + edi * 0x4);
                            if (ecx != 0x0) {
                                    esp = esp - 0x4;
                                    (**ecx)(0x1);
                            }
                            eax = esi[0x3];
                            *(eax + edi * 0x4) = *(eax + edi * 0x4) & 0x0;
                    }
            }
            eax = ebx[0x4];
            *(eax + edi * 0x8) = *(eax + edi * 0x8) & 0xfffffffe;
            eax = LeaveCriticalSection(var_4);
            esp = (esp - 0x4) + 0x4;
    }
    return eax;
}
