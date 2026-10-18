// sub_481e48 @ 0x481e48
// hopper name: sub_481e48
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481e48() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_8;
    if (edi > 0x0) {
            esp = esp - 0x4;
            decomp_var_c = esi;
            esi = &arg_8;
            do {
                    esi = esi + 0x4;
                    esp = (esp - 0xc) + 0xc;
                    if (sub_47f557(arg_0, arg_4, *esi) != 0x0) {
                            sub_47a828();
                            esp = (esp - 0x14) + 0x14;
                    }
                    edi = edi - 0x1;
            } while (edi != 0x0);
            esp = esp + 0x4;
    }
    return;
}
