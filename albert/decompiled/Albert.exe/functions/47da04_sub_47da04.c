// sub_47da04 @ 0x47da04
// hopper name: sub_47da04
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47da04() {
    sub_47f31c(0x4c3510, 0xc);
    sub_487c06(0x8);
    esp = (esp - 0xc) + 0x4;
    if (*dword_bc64fc != 0x1) {
            *dword_bc64f8 = 0x1;
            *(int8_t *)byte_bc64f4 = arg_c;
            if (arg_8 == 0x0) {
                    decomp_var_c = *dword_bc8378;
                    edi = sub_47fe7c(*dword_bc8378);
                    esp = (esp - 0x8) + 0x8;
                    decomp_var_1c = sub_47fe7c(*dword_bc8374);
                    if (edi != 0x0) {
                            while (true) {
                                    decomp_var_1c = decomp_var_1c - 0x4;
                                    if (decomp_var_1c < edi) {
                                            break;
                                    }
                                    eax = *decomp_var_1c;
                                    if (eax != 0x0) {
                                            (eax)();
                                    }
                            }
                    }
                    sub_47d8c7(0x4af438);
                    esp = (esp - 0x4) + 0x4;
            }
            sub_47d8c7(0x4af444);
            esp = (esp - 0x4) + 0x4;
    }
    loc_47dabd();
    if (arg_c == 0x0) {
            *dword_bc64fc = 0x1;
            sub_487b2e(0x8);
            sub_47d8a0(arg_4);
    }
    sub_47f361();
    return;
}
