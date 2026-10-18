// sub_47068a @ 0x47068a
// hopper name: sub_47068a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47068a() {
    if (*(sub_4715ba() + 0x4) == 0x0) {
            eax = 0x0;
    }
    else {
            esp = esp - 0x4;
            decomp_var_10 = esi;
            eax = sub_46e5d5();
            if (eax != 0x0) {
                    esp = esp - 0x10;
                    eax = (*(*eax + 0xc))(0xe146, 0x0, 0x0, &var_8);
                    if (eax != 0x0) {
                            eax = 0x1;
                            esp = esp + 0x4;
                    }
                    else {
                            eax = sub_4715ba();
                            eax = eax[0x1];
                            esp = esp - 0x10;
                            eax = (*(*eax + 0xc))(0xe146, 0x0, 0x0, &var_8);
                            esp = esp + 0x4;
                    }
            }
            else {
                    eax = sub_4715ba();
                    eax = eax[0x1];
                    esp = esp - 0x10;
                    eax = (*(*eax + 0xc))(0xe146, 0x0, 0x0, &var_8);
                    esp = esp + 0x4;
            }
    }
    return eax;
}
