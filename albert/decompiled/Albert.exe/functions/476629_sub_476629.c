// sub_476629 @ 0x476629
// hopper name: sub_476629
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476629() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    ebp = ecx;
    if (arg_0 != 0x0) {
            esi = *(sub_4715ba() + 0xc);
            esp = esp - 0xc;
            eax = FindResourceA(esi, arg_0, 0xf0);
            if (eax != 0x0) {
                    esp = esp - 0x8;
                    edi = LoadResource(esi, eax);
                    if (edi != 0x0) {
                            esp = esp - 0x4;
                            ebx = LockResource(edi);
                            esp = esp - 0x4;
                            esi = sub_4761e0(ebx);
                            if (ebx != 0x0 && edi != 0x0) {
                                    esp = esp - 0x4;
                                    FreeResource(edi);
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    esi = sub_4761e0(0x0);
                    if (0x0 != 0x0 && 0x0 != 0x0) {
                            esp = esp - 0x4;
                            FreeResource(0x0);
                    }
            }
    }
    else {
            esp = esp - 0x4;
            esi = sub_4761e0(0x0);
            if (0x0 != 0x0 && 0x0 != 0x0) {
                    esp = esp - 0x4;
                    FreeResource(0x0);
            }
    }
    return;
}
