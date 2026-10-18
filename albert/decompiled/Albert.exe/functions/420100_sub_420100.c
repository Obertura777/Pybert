// sub_420100 @ 0x420100
// hopper name: sub_420100
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_420100() {
    decomp_var_c = *0x0;
    decomp_var_b8 = ebx;
    decomp_var_bc = ebp;
    decomp_var_c0 = esi;
    decomp_var_c4 = edi;
    esp = esp - 0xc8;
    decomp_var_c8 = *dword_4c8db8 ^ &decomp_var_c4;
    *0x0 = &decomp_var_c;
    esi = ecx;
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax != 0x0) goto loc_420177;
    goto loc_42016d;

loc_420177:
    ebp = 0x0;
    decomp_var_a8 = (*(*eax + 0xc))() + 0x10;
    edx = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    decomp_var_b1 = 0x0;
    decomp_var_88 = edx;
    eax = sub_466060(&decomp_var_64, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&decomp_var_64, 0x2);
    esp = esp - 0x18;
    sub_465ff0(eax);
    sub_465fa0();
    ebx = sub_465930();
    decomp_var_80 = ebx;
    decomp_var_8c = sub_465930();
    decomp_var_90 = 0x0;
    if (ebx <= 0x0) goto loc_4205aa;
    goto loc_42023c;

loc_42016d:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_4205aa:
    eax = decomp_var_a8 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = decomp_var_b1;
    *0x0 = decomp_var_c;
    return eax;

loc_42023c:
    edx = &decomp_var_7a;
    esp = esp - 0x8;
    esi = *(int8_t *)sub_465900(edx, ebp) & 0xff;
    edi = 0x0;
    decomp_var_ac = esi;
    decomp_var_84 = 0x0;
    goto loc_420258;

loc_420258:
    esp = esp - 0x8;
    eax = sub_465900(&decomp_var_78, edi);
    if (ebp != edi) goto .l3;
    goto loc_42026b;

.l3:
    decomp_var_a4 = 0x0;
    if (decomp_var_8c <= 0x0) goto .l5;
    goto .l9;

loc_42026b:
    if (ebx != 0x1) goto .l6;
    goto loc_420274;

.l5:
    edi = edi + 0x1;
    decomp_var_84 = edi;
    if (edi < ebx) {
            continue;
    }
    break;

.l9:
    edx = &decomp_var_76;
    esp = esp - 0x8;
    ebp = *(int8_t *)sub_465900(edx, decomp_var_a4) & 0xff;
    decomp_var_b0 = ebp;
    if (esi != decomp_var_88) goto .l7;
    goto .l8;

.l6:
    edi = edi + 0x1;
    decomp_var_84 = edi;
    if (edi < ebx) {
            continue;
    }
    break;

loc_420274:
    decomp_var_a4 = 0x0;
    if (decomp_var_8c <= 0x0) goto loc_4204c9;
    goto loc_420287;
    ebp = &arg_fffffffffffffffd;
    decomp_var_90 = ebp;
    if (ebp < ebx) {
            continue;
    }
    break;

.l7:
    ebx = *((esi + esi * 0x2) * 0x4 + 0xbb702c);
    esi = (esi + esi * 0x2) * 0x4 + 0xbb7028;
    edx = &decomp_var_b0;
    esp = esp - 0x8;
    eax = sub_401ff0(&decomp_var_28, edx, decomp_var_c8, decomp_var_c4, decomp_var_c0);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == ebx) {
            edx = &decomp_var_64;
            esp = esp - 0x8;
            decomp_var_b1 = 0x1;
            eax = sub_404ce0(edx, &decomp_var_b0, decomp_var_c8);
    }
    eax = *dword_bb7134;
    edi = *eax;
    esi = 0xbb7130;
    decomp_var_98 = 0xbb7130;
    decomp_var_94 = edi;
    if (edi != eax) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] == decomp_var_ac) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x4] == ebp) {
                            esp = esp - 0xc;
                            eax = sub_412280(&decomp_var_20, esi, edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90);
                            edx = *dword_bb7134;
                            edi = **dword_bb7134;
                            esi = 0xbb7130;
                            decomp_var_98 = 0xbb7130;
                            decomp_var_94 = **dword_bb7134;
                    }
                    else {
                            sub_40e680();
                            edi = decomp_var_94;
                            esi = decomp_var_98;
                    }
            }
            else {
                    sub_40e680();
                    edi = decomp_var_94;
                    esi = decomp_var_98;
            }
            if (esi != 0x0) {
                    if (esi != 0xbb7130) {
                            sub_47a948();
                            if (edi != *dword_bb7134) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            if (edi != *dword_bb7134) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    sub_47a948();
                    if (edi != *dword_bb7134) {
                            continue;
                    }
                    break;
            }
    }
    goto .l10;

.l8:
    esi = **dword_bb65e4;
    edi = 0xbb65e0;
    decomp_var_a0 = 0xbb65e0;
    decomp_var_9c = **dword_bb65e4;
    goto .l11;

loc_4204c9:
    edi = edi + 0x1;
    decomp_var_84 = edi;
    if (edi < ebx) {
            continue;
    }
    break;

loc_420287:
    edx = &decomp_var_76;
    esp = esp - 0x8;
    ebp = *(int8_t *)sub_465900(edx, decomp_var_a4) & 0xff;
    decomp_var_b0 = ebp;
    if (esi != decomp_var_88) goto loc_4203b1;
    goto loc_4202ae;
    if (decomp_var_b1 == 0x1) {
            esp = esp - 0x4;
            eax = sub_46b050(&decomp_var_64, decomp_var_c8, decomp_var_c4);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_a8, "Recalculating: Because we have applied a DMZ: (%s)", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_4c >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_a8 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            sub_419e60(&decomp_var_64, &decomp_var_a0, decomp_var_c8);
            eax = esi - 0x10;
            edx = eax + 0xc;
            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
    }
    goto loc_4205aa;

.l10:
    esi = decomp_var_ac;
    eax = decomp_var_a4 + 0x1;
    decomp_var_a4 = eax;
    if (eax < decomp_var_8c) {
            continue;
    }
    break;

.l11:
    if (edi == 0x0 || edi != 0xbb65e0) {
            sub_47a948();
    }
    if (esi != *dword_bb65e4) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] != decomp_var_88) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_69 = esi != edi[0x1];
                    eax = esi[0x3];
                    ebx = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                    decomp_var_34 = *((eax + eax * 0x2) * 0x4 + 0xbb6f2c);
                    if (!bool_69) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_30, &decomp_var_b0, decomp_var_c8, decomp_var_c4, decomp_var_c0);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    edx = decomp_var_34;
                    if (arg_0 == edx) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_18, &decomp_var_b0, decomp_var_c8);
                            decomp_var_b1 = 0x1;
                    }
            }
            sub_401520();
            esi = decomp_var_9c;
            edi = decomp_var_a0;
            continue;
    }
    break;

loc_4203b1:
    ebx = *((esi + esi * 0x2) * 0x4 + 0xbb702c);
    esi = (esi + esi * 0x2) * 0x4 + 0xbb7028;
    edx = &decomp_var_b0;
    esp = esp - 0x8;
    eax = sub_401ff0(&decomp_var_28, edx, decomp_var_c8, decomp_var_c4, decomp_var_c0);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == ebx) {
            edx = &decomp_var_64;
            esp = esp - 0x8;
            decomp_var_b1 = 0x1;
            eax = sub_404ce0(edx, &decomp_var_b0, decomp_var_c8);
    }
    eax = *dword_bb7134;
    edi = *eax;
    esi = 0xbb7130;
    decomp_var_98 = 0xbb7130;
    decomp_var_94 = edi;
    if (edi != eax) {
            do {
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x3] == decomp_var_ac) {
                            if (edi == esi[0x1]) {
                                    sub_47a948();
                            }
                            if (edi[0x4] == ebp) {
                                    esp = esp - 0xc;
                                    eax = sub_412280(&decomp_var_20, esi, edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90);
                                    edx = *dword_bb7134;
                                    edi = **dword_bb7134;
                                    esi = 0xbb7130;
                                    decomp_var_98 = 0xbb7130;
                                    decomp_var_94 = **dword_bb7134;
                            }
                            else {
                                    sub_40e680();
                                    edi = decomp_var_94;
                                    esi = decomp_var_98;
                            }
                    }
                    else {
                            sub_40e680();
                            edi = decomp_var_94;
                            esi = decomp_var_98;
                    }
                    if (esi == 0x0) {
                            sub_47a948();
                            if (edi != *dword_bb7134) {
                                    continue;
                            }
                            break;
                    }
                    if (esi == 0xbb7130) {
                            if (edi != *dword_bb7134) {
                                    continue;
                            }
                            break;
                    }
                    sub_47a948();
            } while (edi != *dword_bb7134);
    }
    goto loc_4204a4;

loc_4202ae:
    esi = **dword_bb65e4;
    edi = 0xbb65e0;
    decomp_var_a0 = 0xbb65e0;
    decomp_var_9c = **dword_bb65e4;
    goto loc_4202c2;
    edi = decomp_var_84;
    ebx = decomp_var_80;
    ebp = decomp_var_90;
    goto .l5;

loc_4204a4:
    esi = decomp_var_ac;
    eax = decomp_var_a4 + 0x1;
    decomp_var_a4 = eax;
    if (eax < decomp_var_8c) {
            continue;
    }
    break;

loc_4202c2:
    if (edi == 0x0 || edi != 0xbb65e0) {
            sub_47a948();
    }
    if (esi != *dword_bb65e4) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] != decomp_var_88) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_32 = esi != edi[0x1];
                    eax = esi[0x3];
                    ebx = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                    decomp_var_34 = *((eax + eax * 0x2) * 0x4 + 0xbb6f2c);
                    if (!bool_32) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_30, &decomp_var_b0, decomp_var_c8, decomp_var_c4, decomp_var_c0);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    edx = decomp_var_34;
                    if (arg_0 == edx) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_18, &decomp_var_b0, decomp_var_c8);
                            decomp_var_b1 = 0x1;
                    }
            }
            sub_401520();
            esi = decomp_var_9c;
            edi = decomp_var_a0;
            continue;
    }
    break;
    edi = decomp_var_84;
    ebx = decomp_var_80;
    ebp = decomp_var_90;
    goto loc_4204c9;
}
