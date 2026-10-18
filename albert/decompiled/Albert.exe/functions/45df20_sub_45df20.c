// sub_45df20 @ 0x45df20
// hopper name: sub_45df20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45df20() {
    decomp_var_c = *0x0;
    decomp_var_74 = ebx;
    decomp_var_78 = ebp;
    decomp_var_7c = esi;
    decomp_var_80 = edi;
    esp = esp - 0x84;
    decomp_var_84 = *dword_4c8db8 ^ &decomp_var_80;
    *0x0 = &decomp_var_c;
    sub_465870();
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_70 = (*(*eax + 0xc))() + 0x10;
            eax = sub_47020b();
            if (eax == 0x0) {
                    eax = sub_40b5a0(0x80004005);
            }
            else {
                    decomp_var_6c = (*(*eax + 0xc))() + 0x10;
                    sub_465870();
                    sub_465870();
                    decomp_var_88 = arg_0;
                    decomp_var_4 = 0x4;
                    sub_40bba0();
                    sub_40c4c0();
                    esp = (esp - 0x1c) + 0x18 - 0x4;
                    sub_40c410(sub_45d020());
                    eax = saved_fp - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = decomp_var_6c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = decomp_var_68 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    decomp_var_8c = arg_0;
                    sub_40bba0();
                    decomp_var_98 = &saved_fp;
                    eax = sub_40c4c0();
                    decomp_var_9c = 0x4b1974;
                    decomp_var_a0 = eax;
                    esp = (esp - 0x1c) + 0x18 - 0x4;
                    sub_40c410(sub_45d020());
                    eax = decomp_var_4 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = saved_fp - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = decomp_var_6c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    ebp = decomp_var_78;
                    esp = esp - 0x1c;
                    eax = ebp;
                    decomp_var_90 = 0xf;
                    decomp_var_94 = 0x0;
                    decomp_var_a4 = 0x0;
                    esi = eax + 0x1;
                    do {
                            edx = *(int8_t *)eax;
                            eax = eax + 0x1;
                    } while (edx != 0x0);
                    decomp_var_b0 = ebp;
                    sub_402650(decomp_var_b0, eax - esi);
                    sub_467f40(decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c);
                    esi = decomp_var_7c;
                    esp = esp - 0x24;
                    decomp_var_9c = 0x0;
                    eax = esi;
                    decomp_var_98 = 0xf;
                    decomp_var_ac = 0x0;
                    edi = eax + 0x1;
                    do {
                            edx = *(int8_t *)eax;
                            eax = eax + 0x1;
                    } while (edx != 0x0);
                    sub_402650(esi, eax - edi);
                    sub_467f40(decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                    sub_466f80(&decomp_var_34, &decomp_var_64);
                    eax = sub_466c40(&decomp_var_44, &decomp_var_74);
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    esp = esp - 0x20;
                    eax = sub_45a9b0(&decomp_var_54);
                    sub_465fa0();
                    sub_465fa0();
                    eax = esi - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = &decomp_var_10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    eax = sub_465fa0();
                    *0x0 = decomp_var_24;
            }
    }
    return eax;
}
