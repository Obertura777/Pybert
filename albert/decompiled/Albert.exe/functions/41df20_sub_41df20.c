// sub_41df20 @ 0x41df20
// hopper name: sub_41df20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41df20() {
    decomp_var_c = *0x0;
    decomp_var_60 = ebx;
    decomp_var_64 = ebp;
    decomp_var_68 = esi;
    decomp_var_6c = edi;
    decomp_var_70 = *dword_4c8db8 ^ &decomp_var_6c;
    *0x0 = &decomp_var_c;
    esi = ecx;
    esp = esp - 0x74;
    eax = sub_465f60(&arg_0);
    eax = sub_47020b();
    if (eax != 0x0) goto loc_41df7c;
    goto loc_41df72;

loc_41df7c:
    decomp_var_54 = (*(*eax + 0xc))() + 0x10;
    edx = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    decomp_var_59 = 0x0;
    decomp_var_44 = edx;
    eax = sub_466060(&decomp_var_38, 0x1);
    esp = esp - 0xc;
    sub_465ff0(eax);
    sub_465fa0();
    edi = sub_465930();
    esi = 0x0;
    decomp_var_40 = edi;
    if (edi > 0x0) {
            esp = esp - 0x8;
            eax = sub_465900(&decomp_var_58, esi);
            esi = esi + 0x1;
            if (esi < edi) {
                    continue;
            }
            break;
    }
    ebp = 0x0;
    decomp_var_4c = 0x0;
    if (edi <= 0x0) goto loc_41e266;
    goto loc_41e008;

loc_41df72:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_41e266:
    eax = decomp_var_54 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    eax = decomp_var_59;
    *0x0 = decomp_var_c;
    return eax;

loc_41e008:
    edx = &decomp_var_58;
    esp = esp - 0x8;
    esi = 0x0;
    decomp_var_48 = *(int8_t *)sub_465900(edx, ebp) & 0xff;
    decomp_var_50 = 0x0;
    goto loc_41e024;

loc_41e024:
    esp = esp - 0x8;
    eax = sub_465900(&decomp_var_56, esi);
    ebx = *(int8_t *)eax & 0xff;
    if (ebp != esi) {
            ecx = decomp_var_48;
            edx = ecx * 0x15 + ebx;
            bool_20 = *(edx * 0x8 + 0x4d552c) > 0x0;
            eax = edx * 0x8 + 0x4d5528;
            if (*(edx * 0x8 + 0x4d552c) >= 0x0 && (bool_20 || *eax > 0x0)) {
                    *eax = 0x0;
                    eax[0x1] = 0x0;
                    decomp_var_59 = 0x1;
            }
            if (ecx == decomp_var_44) {
                    ebx = ebx + ebx * 0x2 + ebx + ebx * 0x2 + ebx + ebx * 0x2 + ebx + ebx * 0x2;
                    if (ebx[0x2edbcc] > 0x0 || ebx[0x2edc0c] > 0x0) {
                            decomp_var_59 = 0x1;
                    }
                    ebp = *(ebx[0x2edbcb] + 0x4);
                    esi = ebx + 0xbb6f28;
                    edi = ebp;
                    if (arg_d == 0x0) {
                            sub_401950(edi[0x2]);
                            edi = *edi;
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            ebp = edi;
                            if (edi[0x11] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    eax = esi[0x1];
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    esi[0x2] = esi;
                    edx = ebx[0x2edc0b];
                    ebp = edx[0x1];
                    edi = ebx + 0xbb7028;
                    esi = ebp;
                    if (arg_d == 0x0) {
                            do {
                                    sub_401950(esi[0x2]);
                                    esi = *esi;
                                    sub_47c8f9();
                                    esp = (esp - 0x8) + 0x4;
                                    ebp = esi;
                            } while (esi[0x11] == 0x0);
                    }
                    eax = edi[0x1];
                    ebp = decomp_var_4c;
                    esi = decomp_var_50;
                    eax[0x1] = eax;
                    eax = edi[0x1];
                    edi[0x2] = 0x0;
                    *eax = eax;
                    edi = edi[0x1];
                    edi[0x2] = edi;
                    edi = decomp_var_40;
            }
    }
    esi = esi + 0x1;
    decomp_var_50 = esi;
    if (esi < edi) {
            continue;
    }
    break;
    ebp = &arg_fffffffffffffffd;
    decomp_var_4c = ebp;
    if (ebp < edi) {
            continue;
    }
    break;
    if (decomp_var_59 == 0x1) {
            esp = esp - 0x4;
            eax = sub_46b050(&decomp_var_38, decomp_var_70, decomp_var_6c);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_54, 0x4afaec, eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_20 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            edx = **(decomp_var_54 - 0x10);
            eax = edx[0x4];
            esi = decomp_var_54 - 0x10;
            decomp_var_40 = 0x66;
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
            sub_419e60(&decomp_var_38, &decomp_var_40, decomp_var_70);
            eax = edi + 0x10 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
    }
    goto loc_41e266;
}
