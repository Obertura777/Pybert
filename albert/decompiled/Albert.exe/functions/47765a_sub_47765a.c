// sub_47765a @ 0x47765a
// hopper name: sub_47765a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47765a() {
    decomp_var_4 = esi;
    esi = ecx;
    esp = esp - 0x8;
    edi = *esi;
    if (edi == 0x0) {
            eax = 0x0;
    }
    else {
            decomp_var_c = ebx;
            ebx = arg_0;
            esp = esp - 0x8;
            decomp_var_10 = ebp;
            ebp = 0x0;
            if (edi == ebx) {
                    esp = esp - 0x4;
                    *esi = *sub_47762b();
                    ebp = &arg_fffffffffffffffd;
            }
            else {
                    do {
                            esp = esp - 0x4;
                            if (*sub_47762b() == ebx) {
                                    break;
                            }
                            esp = esp - 0x4;
                            edi = *sub_47762b();
                    } while (edi != 0x0);
                    if (edi != 0x0) {
                            esp = esp - 0x8;
                            *sub_47762b() = *sub_47762b();
                            ebp = &arg_fffffffffffffffd;
                    }
            }
            eax = ebp;
            esp = esp + 0x8;
    }
    return eax;
}
