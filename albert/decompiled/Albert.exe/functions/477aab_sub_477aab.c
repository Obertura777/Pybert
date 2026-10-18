// sub_477aab @ 0x477aab
// hopper name: sub_477aab
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477aab() {
    esp = esp - 0x4;
    decomp_var_4 = 0x4;
    eax = sub_47d6bb(0x4);
    esi = ecx;
    if (arg_4 == 0x0) {
            sub_46dedc();
    }
    if (*esi == 0x0) {
            if (*dword_bc6240 == 0x0) {
                    eax = sub_4777d0(decomp_var_4 & 0x0);
                    decomp_var_4 = decomp_var_4 | 0xffffffff;
                    *dword_bc6240 = eax;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    eax = sub_4776c0();
                    *esi = eax;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    esp = esp - 0x4;
                    edi = sub_47754d(*esi, decomp_var_4);
                    if (edi == 0x0) {
                            edi = (arg_4)();
                            sub_477872(*esi, edi);
                    }
                    eax = sub_47d75a();
            }
            else {
                    eax = sub_4776c0();
                    *esi = eax;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    esp = esp - 0x4;
                    edi = sub_47754d(*esi, decomp_var_4);
                    if (edi == 0x0) {
                            edi = (arg_4)();
                            sub_477872(*esi, edi);
                    }
                    eax = sub_47d75a();
            }
    }
    else {
            esp = esp - 0x4;
            edi = sub_47754d(*esi, decomp_var_4);
            if (edi == 0x0) {
                    edi = (arg_4)();
                    sub_477872(*esi, edi);
            }
            eax = sub_47d75a();
    }
    return eax;
}
