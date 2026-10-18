// sub_421040 @ 0x421040
// hopper name: sub_421040
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_421040() {
    decomp_var_c = *0x0;
    decomp_var_9c = ebx;
    decomp_var_a0 = ebp;
    decomp_var_a4 = esi;
    decomp_var_a8 = edi;
    esp = esp - 0xac;
    decomp_var_ac = *dword_4c8db8 ^ &decomp_var_a8;
    *0x0 = &decomp_var_c;
    esi = ecx;
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax != 0x0) goto loc_4210b4;
    goto loc_4210aa;

loc_4210b4:
    ebp = 0x0;
    decomp_var_8c = (*(*eax + 0xc))() + 0x10;
    edx = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    decomp_var_95 = 0x0;
    decomp_var_74 = edx;
    eax = sub_466060(&decomp_var_50, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&decomp_var_50, 0x2);
    esp = esp - 0x18;
    sub_465ff0(eax);
    sub_465fa0();
    esi = sub_465930();
    decomp_var_90 = esi;
    decomp_var_84 = sub_465930();
    decomp_var_7c = 0x0;
    if (esi <= 0x0) goto loc_42137e;
    goto loc_421173;

loc_4210aa:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_42137e:
    eax = decomp_var_8c - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = decomp_var_95;
    *0x0 = decomp_var_c;
    return eax;

loc_421173:
    edx = &decomp_var_64;
    esp = esp - 0x8;
    esi = *(int8_t *)sub_465900(edx, ebp) & 0xff;
    ebx = 0x0;
    decomp_var_88 = esi;
    decomp_var_78 = 0x0;
    goto loc_421190;

loc_421190:
    esp = esp - 0x8;
    eax = sub_465900(&decomp_var_62, ebx);
    edi = *(int8_t *)eax & 0xff;
    decomp_var_6c = edi;
    if (ebx != ebp) goto .l6;
    goto loc_4211aa;

.l6:
    decomp_var_94 = 0x0;
    if (decomp_var_84 <= 0x0) goto .l4;
    goto .l2;

loc_4211aa:
    if (decomp_var_90 != 0x1) goto .l5;
    goto loc_4211b5;

.l4:
    ebx = ebx + 0x1;
    decomp_var_78 = ebx;
    if (ebx < decomp_var_90) {
            continue;
    }
    break;

.l2:
    goto loc_4211d4;

.l5:
    ebx = ebx + 0x1;
    decomp_var_78 = ebx;
    if (ebx < decomp_var_90) {
            continue;
    }
    break;

loc_4211b5:
    decomp_var_94 = 0x0;
    if (decomp_var_84 <= 0x0) goto loc_42129d;
    goto loc_4211c8;
    ebp = &arg_fffffffffffffffd;
    decomp_var_7c = ebp;
    if (ebp < decomp_var_90) {
            continue;
    }
    break;

loc_4211d4:
    eax = sub_465900(&decomp_var_66, decomp_var_94);
    decomp_var_80 = *(int8_t *)eax & 0xff;
    esp = esp - 0xc;
    decomp_var_b0 = &decomp_var_80;
    if (esi == decomp_var_74) {
            esi = (edi + edi * 0x2) * 0x4 + 0xbb6f28;
            edx = &decomp_var_14;
            esp = esp - 0x4;
            eax = sub_401ff0(edx, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
            edi = *eax;
            ebp = eax[0x1];
            ebx = esi[0x1];
            if (edi == 0x0 || edi != esi) {
                    sub_47a948();
            }
            if (ebp != ebx) {
                    eax = &decomp_var_24;
                    esp = esp - 0xc;
                    sub_402b70(eax, edi, ebp, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                    decomp_var_95 = 0x1;
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
            else {
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
    }
    else {
            esi = (esi + esi * 0x2) * 0x4 + 0xbb7028;
            edx = &decomp_var_1c;
            esp = esp - 0x4;
            eax = sub_401ff0(edx, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
            edi = *eax;
            ebp = eax[0x1];
            ebx = esi[0x1];
            if (edi == 0x0 || edi != esi) {
                    sub_47a948();
            }
            if (ebp != ebx) {
                    eax = &decomp_var_50;
                    esp = esp - 0xc;
                    sub_402b70(eax, edi, ebp, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                    decomp_var_95 = 0x1;
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
            else {
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
    }
    goto .l7;

loc_42129d:
    ebx = ebx + 0x1;
    decomp_var_78 = ebx;
    if (ebx < decomp_var_90) {
            continue;
    }
    break;

loc_4211c8:
    goto .l8;
    bool_5 = true;
    if (decomp_var_95 == 0x1) {
            eax = sub_46b050(&decomp_var_50, decomp_var_ac, decomp_var_a8);
            decomp_var_c8 = *eax;
            eax = sub_410c10(&decomp_var_8c, "Recalculating: Because we removed a DMZ: %s", decomp_var_c8);
            esp = (esp - 0x28) + 0x24;
            if (decomp_var_38 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_8c - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            sub_419e60(&decomp_var_50, &decomp_var_74, decomp_var_ac);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
    }
    goto loc_42137e;

.l7:
    ebx = decomp_var_78;
    ebp = decomp_var_7c;
    goto .l4;

.l8:
    eax = sub_465900(&decomp_var_66, decomp_var_94);
    decomp_var_80 = *(int8_t *)eax & 0xff;
    esp = esp - 0xc;
    decomp_var_b0 = &decomp_var_80;
    if (esi == decomp_var_74) {
            esi = (edi + edi * 0x2) * 0x4 + 0xbb6f28;
            edx = &decomp_var_14;
            esp = esp - 0x4;
            eax = sub_401ff0(edx, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
            edi = *eax;
            ebp = eax[0x1];
            ebx = esi[0x1];
            if (edi == 0x0 || edi != esi) {
                    sub_47a948();
            }
            if (ebp != ebx) {
                    eax = &decomp_var_24;
                    esp = esp - 0xc;
                    sub_402b70(eax, edi, ebp, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                    decomp_var_95 = 0x1;
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
            else {
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
    }
    else {
            esi = (esi + esi * 0x2) * 0x4 + 0xbb7028;
            edx = &decomp_var_1c;
            esp = esp - 0x4;
            eax = sub_401ff0(edx, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
            edi = *eax;
            ebp = eax[0x1];
            ebx = esi[0x1];
            if (edi == 0x0 || edi != esi) {
                    sub_47a948();
            }
            if (ebp != ebx) {
                    eax = &decomp_var_50;
                    esp = esp - 0xc;
                    sub_402b70(eax, edi, ebp, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                    decomp_var_95 = 0x1;
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
            else {
                    esi = decomp_var_88;
                    eax = decomp_var_94 + 0x1;
                    decomp_var_94 = eax;
                    if (eax < decomp_var_84) {
                            edi = decomp_var_6c;
                            continue;
                    }
                    break;
            }
    }
    goto .l9;

.l9:
    ebx = decomp_var_78;
    ebp = decomp_var_7c;
    goto loc_42129d;
}
