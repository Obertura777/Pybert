// RECEIVE_PROPOSAL @ 0x431fe0
// hopper name: sub_431fe0
// pybert name: RECEIVE_PROPOSAL
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

RECEIVE_PROPOSAL() {
    decomp_var_c = *0x0;
    decomp_var_108 = ebx;
    decomp_var_10c = ebp;
    decomp_var_110 = esi;
    decomp_var_114 = edi;
    esp = esp - 0x118;
    decomp_var_118 = *dword_4c8db8 ^ &decomp_var_114;
    *0x0 = &decomp_var_c;
    decomp_var_9c = ecx;
    sub_465870();
    eax = sub_47020b();
    if (eax != 0x0) goto loc_43204c;
    goto loc_432042;

loc_43204c:
    decomp_var_ec = (*(*eax + 0xc))() + 0x10;
    sub_4243a0();
    esi = sub_465930();
    decomp_var_dc = 0x0;
    eax = sub_47b26f(0x0);
    sub_401950(decomp_var_bc[0x1]);
    decomp_var_bc[0x1] = decomp_var_bc;
    *decomp_var_bc = decomp_var_bc;
    decomp_var_bc[0x2] = decomp_var_bc;
    sub_401950(decomp_var_c8[0x1]);
    decomp_var_c8[0x1] = decomp_var_c8;
    decomp_var_c4 = 0x0;
    *decomp_var_c8 = decomp_var_c8;
    decomp_var_c8[0x2] = decomp_var_c8;
    sub_401950(decomp_var_b0[0x1]);
    decomp_var_b0[0x1] = decomp_var_b0;
    *decomp_var_b0 = decomp_var_b0;
    decomp_var_b0[0x2] = decomp_var_b0;
    sub_404ce0(&decomp_var_e8, &decomp_var_f8, decomp_var_118);
    eax = sub_404ce0(&decomp_var_e8, &decomp_var_f8, decomp_var_118);
    sub_419cb0(&decomp_var_98, &decomp_var_a8, *decomp_var_a4, &decomp_var_a8, decomp_var_a4);
    esp = (esp - 0x4) + 0x4 - 0x34;
    sub_411a80(0xbb65d4);
    edi = 0x0;
    if (esi > 0x0) {
            do {
                    eax = sub_465900(&decomp_var_102, edi);
                    esp = esp - 0x10;
                    decomp_var_100 = *(int8_t *)eax & 0xff;
                    eax = sub_404ce0(&decomp_var_e8, &decomp_var_100, decomp_var_118);
                    edi = edi + 0x1;
            } while (edi < esi);
    }
    ebp = **dword_bb65cc;
    esi = 0xbb65c8;
    decomp_var_102 = 0x0;
    decomp_var_100 = 0xbb65c8;
    decomp_var_fc = **dword_bb65cc;
    goto loc_4321d0;

loc_432042:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_4321d0:
    if (esi == 0x0 || esi != 0xbb65c8) {
            sub_47a948();
    }
    if (ebp == *dword_bb65cc) goto .l8;
    goto loc_4321ef;

.l8:
    break;

loc_4321ef:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&arg_0);
    if (eax == 0x0) goto loc_43232b;
    goto loc_43221a;
    if (decomp_var_102 == 0x0) {
            eax = sub_465f60(&arg_0);
            eax = sub_4223c0(&decomp_var_dc);
            eax = sub_430370(&decomp_var_e8, &decomp_var_5c, decomp_var_118);
            sub_421400();
            sub_465fa0();
            sub_47b26f(0x0);
            esi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
            esp = (esp - 0x18) + 0x8 - 0x4;
            eax = sub_46b050(&decomp_var_78, decomp_var_118, decomp_var_114);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_ec, "We have received the proposal: %s", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_60 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            decomp_var_f4 = esi;
            edx = *(**(decomp_var_ec - 0x10) + 0x10);
            esi = decomp_var_ec - 0x10;
            eax = (edx)();
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
            sub_419e60(&decomp_var_e8, &decomp_var_f4, decomp_var_118);
            eax = edi + 0x10 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            esp = esp - 0x4;
            sub_418db0(decomp_var_f8);
    }
    sub_421400();
    eax = decomp_var_ec - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

loc_43232b:
    if (decomp_var_102 != 0x1) {
            sub_40f860();
            ebp = decomp_var_fc;
            esi = decomp_var_100;
            continue;
    }
    break;

loc_43221a:
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    if (arg_1c != 0x0) goto .l3;
    goto loc_43222e;

.l3:
    if (decomp_var_102 != 0x1) {
            sub_40f860();
            ebp = decomp_var_fc;
            esi = decomp_var_100;
            continue;
    }
    break;

loc_43222e:
    edi = &decomp_var_cc;
    ebx = *decomp_var_c8;
    decomp_var_102 = 0x1;
    decomp_var_f4 = edi;
    decomp_var_f0 = ebx;
    goto loc_432250;

loc_432250:
    decomp_var_8c = decomp_var_c8;
    if (edi == 0x0 || edi != &decomp_var_cc) {
            sub_47a948();
    }
    if (ebx != decomp_var_8c) {
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            esi = &arg_2c;
            decomp_var_94 = arg_30;
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            edi = ebx + 0xc;
            if (ebp == decomp_var_100[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_e8, edi, decomp_var_118, decomp_var_114, decomp_var_110);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] == decomp_var_94) {
                    decomp_var_102 = 0x0;
            }
            sub_401520();
            ebx = decomp_var_f0;
            edi = decomp_var_f4;
            esi = decomp_var_100;
            continue;
    }
    break;
    edi = decomp_var_c4;
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    if (edi != arg_34) {
            decomp_var_102 = 0x0;
            sub_40f860();
            ebp = decomp_var_fc;
            esi = decomp_var_100;
            continue;
    }
    if (decomp_var_102 != 0x1) {
            sub_40f860();
            ebp = decomp_var_fc;
            esi = decomp_var_100;
            continue;
    }
    break;
}
