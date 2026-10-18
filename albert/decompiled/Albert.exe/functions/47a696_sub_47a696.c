// sub_47a696 @ 0x47a696
// hopper name: sub_47a696
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a696() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    edi = ecx;
    *edi = 0x4b3940;
    eax = *ebx;
    if (eax != 0x0) {
            esi = sub_47d630(eax) + 0x1;
            eax = sub_47c836();
            esp = (esp - 0x8) + 0x8;
            edi[0x1] = eax;
            if (eax != 0x0) {
                    sub_47db5e(eax, esi, *ebx);
                    esp = (esp - 0xc) + 0xc;
            }
    }
    else {
            edi[0x1] = edi[0x1] & 0x0;
    }
    edi[0x2] = 0x1;
    eax = edi;
    return eax;
}
