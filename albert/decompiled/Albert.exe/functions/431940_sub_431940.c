// sub_431940 @ 0x431940
// hopper name: sub_431940
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_431940() {
    decomp_var_c = *0x0;
    decomp_var_108 = ebp;
    decomp_var_10c = esi;
    decomp_var_110 = edi;
    esp = esp - 0x114;
    decomp_var_114 = *dword_4c8db8 ^ &decomp_var_110;
    *0x0 = &decomp_var_c;
    edi = ecx;
    decomp_var_9c = edi;
    sub_465870();
    eax = sub_47020b();
    if (eax == 0x0) {
            esp = esp - 0x4;
            decomp_var_118 = 0x80004005;
            eax = sub_40b5a0(0x80004005);
    }
    decomp_var_f8 = (*(*eax + 0xc))() + 0x10;
    sub_4243a0();
    edi = sub_465930();
    decomp_var_e0 = 0x0;
    decomp_var_e4 = edi;
    sub_401950(decomp_var_c0[0x1]);
    decomp_var_c0[0x1] = decomp_var_c0;
    *decomp_var_c0 = decomp_var_c0;
    decomp_var_c0[0x2] = decomp_var_c0;
    sub_401950(decomp_var_cc[0x1]);
    decomp_var_cc[0x1] = decomp_var_cc;
    decomp_var_c8 = 0x0;
    *decomp_var_cc = decomp_var_cc;
    decomp_var_cc[0x2] = decomp_var_cc;
    sub_401950(decomp_var_b4[0x1]);
    decomp_var_b4[0x1] = decomp_var_b4;
    *decomp_var_b4 = decomp_var_b4;
    decomp_var_b4[0x2] = decomp_var_b4;
    sub_404ce0(&decomp_var_9c, &decomp_var_104, decomp_var_118);
    eax = sub_404ce0(&decomp_var_9c, &decomp_var_104, decomp_var_118);
    eax = sub_466060(&decomp_var_80, 0x1);
    edx = &decomp_var_9c;
    esp = esp - 0x2c;
    sub_419300(edx, eax, decomp_var_118);
    sub_465fa0();
    if (edi > 0x0) {
            sub_431af0(decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec, decomp_var_e8, decomp_var_e4, decomp_var_e0, decomp_var_dc, decomp_var_d8, decomp_var_d4);
    }
    esi = 0xbb65c8;
    ebx = **dword_bb65cc;
    decomp_var_104 = 0x0;
    decomp_var_100 = 0xbb65c8;
    decomp_var_fc = **dword_bb65cc;
    goto loc_431b44;

loc_431b44:
    if (esi == 0x0 || esi != 0xbb65c8) {
            sub_47a948();
    }
    if (ebx != *dword_bb65cc) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            edx = &saved_fp;
            esp = esp - 0x4;
            if (sub_465d90(edx) != 0x0) {
                    if (ebx == esi[0x1]) {
                            sub_47a948();
                    }
                    if (ebx[0x20] == 0x0) {
                            edi = &decomp_var_d0;
                            decomp_var_104 = 0x1;
                            decomp_var_f4 = edi;
                            sub_431bc0(decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, 0x1, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, *decomp_var_cc, decomp_var_ec, decomp_var_e8, decomp_var_e4, decomp_var_e0, decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0);
                            temp_0 = 0x0;
                            break;
                    }
                    else {
                            if (decomp_var_104 != 0x1) {
                                    sub_40f860();
                                    ebx = decomp_var_fc;
                                    esi = decomp_var_100;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (decomp_var_104 != 0x1) {
                            sub_40f860();
                            ebx = decomp_var_fc;
                            esi = decomp_var_100;
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            temp_0 = 0x1;
            break;
    }
    goto .l2;

.l2:
    if (temp_0 != 0x0) {
            if (decomp_var_104 == 0x0) {
                    sub_466f80(&decomp_var_f4, 0xbc1e0c);
                    eax = sub_466c40(&decomp_var_80, &arg_c);
                    eax = sub_466c40(&decomp_var_9c, &saved_fp);
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_47b26f(0x0);
                    esp = (esp - 0x20) + 0x4;
                    eax = eax - *dword_ba2880;
                    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
                    esi = 0x0;
                    *dword_ba2858 = eax;
                    *dword_ba285c = edx;
                    if (edi > 0x0) {
                            do {
                                    edx = &decomp_var_104;
                                    esp = esp - 0x8;
                                    sub_465900(edx, esi);
                                    esi = esi + 0x1;
                            } while (esi < edi);
                    }
                    eax = sub_47b26f(0x0);
                    eax = eax - *dword_ba2880;
                    bool_5 = eax < 0x0;
                    decomp_var_d8 = eax;
                    sub_465f60(&saved_fp);
                    sub_4223c0(&decomp_var_e0);
                    sub_430370(&decomp_var_9c, &decomp_var_60, decomp_var_118);
                    sub_421400();
                    sub_465fa0();
                    sub_40e8e0();
                    sub_45a9b0(&decomp_var_70);
                    esp = ((esp - 0x4) + 0x4 - 0x18) + 0x4 - 0x4;
                    esi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
                    eax = sub_46b050(&decomp_var_9c, decomp_var_118, decomp_var_114);
                    if (!bool_5) {
                            eax = eax[0x1];
                    }
                    else {
                            eax = eax + 0x4;
                    }
                    eax = sub_410c10(&decomp_var_d8, "We are proposing: %s", eax);
                    esp = (esp - 0xc) + 0xc;
                    if (decomp_var_64 >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    decomp_var_d4 = esi;
                    edx = **(decomp_var_d8 - 0x10);
                    eax = edx[0x4];
                    esi = decomp_var_d8 - 0x10;
                    eax = (eax)();
                    ecx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                            }
                            else {
                                    ecx = esi[0x1];
                                    edx = *eax;
                                    edx = *edx;
                                    esp = esp - 0x8;
                                    edi = (edx)(ecx, 0x1);
                                    if (edi == 0x0) {
                                            sub_40b6d0();
                                    }
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                    }
                    else {
                            ecx = esi[0x1];
                            edx = *eax;
                            edx = *edx;
                            esp = esp - 0x8;
                            edi = (edx)(ecx, 0x1);
                            if (edi == 0x0) {
                                    sub_40b6d0();
                            }
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                    }
                    esp = esp - 0x8;
                    sub_419e60(&decomp_var_5c, &decomp_var_b4, decomp_var_d8);
                    eax = edi + 0x10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    edx = edx - 0x1;
                    if (edx <= 0x0) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
            }
            sub_421400();
            eax = decomp_var_b8 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            *0x0 = arg_2c;
    }
    return;
}
