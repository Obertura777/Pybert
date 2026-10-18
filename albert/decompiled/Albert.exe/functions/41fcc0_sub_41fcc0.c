// sub_41fcc0 @ 0x41fcc0
// hopper name: sub_41fcc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41fcc0() {
    decomp_var_c = *0x0;
    decomp_var_98 = ebx;
    decomp_var_a4 = edi;
    esp = esp - 0xa8;
    decomp_var_a8 = *dword_4c8db8 ^ &decomp_var_a4;
    *0x0 = &decomp_var_c;
    esi = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    decomp_var_90 = 0x0;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_41fd4f;
    goto loc_41fd45;

loc_41fd4f:
    (*(*eax + 0xc))() + 0x10;
    edx = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    decomp_var_74 = edx;
    eax = sub_466060(&decomp_var_68, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    decomp_var_b0 = &decomp_var_68;
    esp = esp - 0x18;
    decomp_var_ac = sub_466060(decomp_var_b0, 0x3);
    sub_465ff0(decomp_var_ac);
    sub_465fa0();
    edi = sub_465930();
    decomp_var_80 = sub_465930();
    decomp_var_88 = 0x0;
    if (edi <= 0x0) goto loc_420066;
    goto loc_41fe0e;

loc_41fd45:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_420066:
    eax = decomp_var_94 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = decomp_var_a1;
    *0x0 = decomp_var_1c;
    return eax;

loc_41fe0e:
    ebp = 0x0;
    edx = decomp_var_88;
    decomp_var_ac = edx;
    esp = esp - 0x8;
    decomp_var_b0 = &decomp_var_6c;
    ebx = *(int8_t *)sub_465900(decomp_var_b0, decomp_var_ac) & 0xff;
    edi = 0x0;
    if (decomp_var_80 > 0x0) {
            decomp_var_ac = edi;
            esp = esp - 0x8;
            decomp_var_b0 = &decomp_var_6a;
            eax = sub_465900(decomp_var_b0, decomp_var_ac);
            ecx = decomp_var_74;
            eax = *(int8_t *)eax & 0xff;
            if (ebx != ecx) {
                    edx = ebx * 0x15;
                    eax = eax + edx;
                    if (*(eax * 0x4 + 0xba2888) <= ebp) {
                            *(eax * 0x4 + 0xba2888) = 0x1;
                    }
                    if (*(int8_t *)byte_baed5f == 0x1) {
                            bool_14 = *(eax * 0x8 + 0x4d552c) > ebp;
                            if (*(eax * 0x8 + 0x4d552c) >= ebp && (bool_14 || *(eax * 0x8 + 0x4d5528) >= ebp)) {
                                    *(eax * 0x8 + 0x4d5528) = ebp;
                                    *(eax * 0x8 + 0x4d552c) = ebp;
                                    *(eax * 0x4 + 0x634e90) = ebp;
                            }
                    }
                    if ((*((ecx * 0x15 + ebx) * 0x8 + 0x4d5528) | *((ecx * 0x15 + ebx) * 0x8 + 0x4d552c)) == 0x0) {
                            edx = *(ebx * 0x8 + 0x4cf568);
                            edx = edx | *(ebx * 0x8 + 0x4cf56c);
                            if (edx == 0x0) {
                                    decomp_var_90 = *(int16_t *)(esi[0x2] + 0x2424);
                                    decomp_var_8c = ebx & 0xff | 0x4100;
                                    eax = sub_466540(&decomp_var_28, &decomp_var_8c);
                                    edx = &decomp_var_68;
                                    decomp_var_b0 = edx;
                                    decomp_var_ac = sub_466f80(decomp_var_b0, eax);
                                    sub_465ff0(decomp_var_ac);
                                    sub_465fa0();
                                    sub_465fa0();
                                    esp = esp - 0x28;
                                    eax = sub_465f60(&decomp_var_38);
                                    sub_41daf0();
                                    decomp_var_a1 = 0x1;
                            }
                    }
            }
            edi = edi + 0x1;
            if (edi < decomp_var_90) {
                    continue;
            }
            break;
    }
    eax = decomp_var_98 + 0x1;
    decomp_var_98 = eax;
    if (eax < decomp_var_80) {
            continue;
    }
    break;
    if (decomp_var_a1 == 0x1) {
            esp = esp - 0x4;
            eax = sub_46b050(&decomp_var_38, decomp_var_b8, decomp_var_b4);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_94, 0x4afb20, eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_20 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_94 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            sub_419e60(&decomp_var_78, &decomp_var_8c, decomp_var_b8);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
    }
    goto loc_420066;
}
