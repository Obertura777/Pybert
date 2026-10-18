// sub_47dc4a @ 0x47dc4a
// hopper name: sub_47dc4a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47dc4a() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = ebp;
    if (ebx == 0x0) {
            eax = 0x0;
    }
    else {
            decomp_var_c = esi;
            decomp_var_10 = edi;
            esi = sub_47d630(ebx) + 0x1;
            edi = sub_47c836();
            esp = (esp - 0x10) + 0x8;
            if (edi != 0x0) {
                    esp = (esp - 0xc) + 0xc;
                    if (sub_47db5e(edi, esi, ebx) != 0x0) {
                            sub_47a828();
                            esp = (esp - 0x14) + 0x14;
                    }
                    eax = edi;
            }
            else {
                    eax = 0x0;
            }
            esp = esp + 0x8;
    }
    return eax;
}
