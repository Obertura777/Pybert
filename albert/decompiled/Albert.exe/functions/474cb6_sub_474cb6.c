// sub_474cb6 @ 0x474cb6
// hopper name: sub_474cb6
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474cb6() {
    esi = arg_8;
    ebx = *esi;
    edi = ecx;
    GetDlgCtrlID(ebx) & 0xffff;
    esp = esp - 0x14;
    decomp_var_4 = 0x46def6;
    arg_8 = esi[0x2];
    eax = sub_477aab();
    if (eax == 0x0) {
            sub_46dedc();
    }
    if (eax[0x37] == edi[0x8]) {
            eax = 0x1;
    }
    else {
            esp = esp - 0x8;
            decomp_var_c = ebx;
            if (sub_474459() == 0x0) {
                    esp = esp - 0x10;
                    eax = *edi;
                    eax = (eax[0x3])(decomp_var_4, arg_8 & 0xffff | 0x4e0000, arg_c, esi);
            }
            else {
                    eax = 0x1;
            }
    }
    return eax;
}
