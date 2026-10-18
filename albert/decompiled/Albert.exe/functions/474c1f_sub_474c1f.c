// sub_474c1f @ 0x474c1f
// hopper name: sub_474c1f
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474c1f() {
    decomp_var_34 = ebx;
    decomp_var_38 = esi;
    esp = esp - 0xc;
    decomp_var_3c = edi;
    edi = arg_4 & 0xffff;
    esi = ecx;
    arg_4 = arg_4 >> 0x10;
    if (arg_8 == 0x0) {
            if (edi == 0x0) {
                    eax = 0x0;
            }
            else {
                    sub_4720b7();
                    esp = esp - 0x10;
                    (*(*esi + 0xc))(edi, 0xffffffff, &decomp_var_2c, 0x0);
                    if (decomp_var_4 == 0x0) {
                            eax = 0x1;
                    }
                    else {
                            ebx = 0x0;
                            arg_4 = 0x0;
                            eax = *esi;
                            esp = esp - 0x10;
                            eax = (eax[0x3])(edi, arg_4, ebx, ebx);
                    }
            }
    }
    else {
            esp = esp - 0x4;
            eax = sub_477aab();
            if (eax == 0x0) {
                    sub_46dedc();
            }
            if (eax[0x37] != esi[0x8]) {
                    ebx = 0x0;
                    esp = esp - 0x8;
                    if (sub_474459() == 0x0) {
                            if (edi != ebx) {
                                    eax = *esi;
                                    esp = esp - 0x10;
                                    eax = (eax[0x3])(edi, arg_4, 0x0, 0x0);
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x1;
            }
    }
    return eax;
}
