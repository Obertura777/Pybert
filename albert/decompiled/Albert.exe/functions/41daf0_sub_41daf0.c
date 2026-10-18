// sub_41daf0 @ 0x41daf0
// hopper name: sub_41daf0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41daf0() {
    decomp_var_c = *0x0;
    decomp_var_60 = esi;
    decomp_var_64 = edi;
    esp = esp - 0x68;
    decomp_var_68 = *dword_4c8db8 ^ &decomp_var_64;
    *0x0 = &decomp_var_c;
    esi = ecx;
    decomp_var_48 = esi;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_41db3d;
    goto loc_41db33;

loc_41db3d:
    ebp = 0x0;
    decomp_var_4c = (*(*eax + 0xc))() + 0x10;
    eax = sub_465f60(&arg_0);
    ebx = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    decomp_var_70 = &decomp_var_38;
    decomp_var_51 = 0x0;
    decomp_var_52 = 0x0;
    decomp_var_44 = ebx;
    esp = esp - 0x10;
    decomp_var_6c = sub_466060(decomp_var_70, 0x1);
    sub_465ff0(decomp_var_6c);
    decomp_var_4 = 0x2;
    sub_465fa0();
    eax = sub_465930();
    decomp_var_40 = eax;
    if (eax <= 0x0) goto loc_41dd31;
    goto loc_41dbbf;

loc_41db33:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_41dd31:
    if (*(int8_t *)byte_baed68 != 0x1) goto loc_41deab;
    goto loc_41dd3e;

loc_41dbbf:
    esp = esp - 0x8;
    eax = sub_465900(&decomp_var_50, ebp);
    esi = *(int8_t *)eax & 0xff;
    edi = 0x0;
    goto loc_41dbd3;

loc_41deab:
    if (decomp_var_52 == 0x1) {
            sub_4113d0();
    }
    sub_465fa0();
    eax = decomp_var_54 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    eax = decomp_var_5a;
    *0x0 = decomp_var_14;
    return eax;

loc_41dd3e:
    edx = *(decomp_var_48[0x2] + 0x2404);
    ecx = 0x0;
    if (edx <= 0x0) goto loc_41dda3;
    goto loc_41dd51;

loc_41dbd3:
    decomp_var_6c = edi;
    esp = esp - 0x8;
    decomp_var_70 = &decomp_var_4e;
    eax = sub_465900(decomp_var_70, decomp_var_6c);
    ecx = *(int8_t *)eax & 0xff;
    if (ebp != edi) {
            if (esi == ebx) {
                    *(ecx * 0x8 + 0x4d53d8) = 0x2;
                    *(ecx * 0x8 + 0x4d53dc) = 0x0;
            }
            asm { fld        dword [aRecalculatingB_4afab0+56] };
            asm { fcomp      dword [byte_4c6bdc+4] };
            asm { fnstsw     ax };
            bool_37 = (HIBYTE(eax) & 0x41) != 0x0;
            eax = 0x3;
            if (!bool_37) {
                    eax = 0x3 - *((esi * 0x15 + ecx) * 0x4 + 0x62a2f8);
                    if (eax < 0x1) {
                            eax = 0x1;
                    }
            }
            ebx = *((esi * 0x15 + ecx) * 0x8 + 0x4d552c);
            ecx = (esi * 0x15 + ecx) * 0x8 + 0x4d5528;
            edx = eax & 0x80000000 ? 0xffffffff : 0x0;
            bool_38 = ebx < edx;
            if (ebx <= edx && (bool_38 || *ecx < eax)) {
                    *ecx = eax;
                    ecx[0x1] = edx;
                    decomp_var_52 = 0x1;
            }
            ebx = decomp_var_44;
    }
    edi = edi + 0x1;
    if (edi < decomp_var_40) {
            continue;
    }
    break;

loc_41dda3:
    decomp_var_6c = 0x4afa78;
    decomp_var_70 = &decomp_var_4c;
    sub_410c10(decomp_var_70, 0x4afa78, decomp_var_68);
    edx = **(decomp_var_4c - 0x10);
    eax = edx[0x4];
    esi = decomp_var_4c - 0x10;
    esp = (esp - 0x8) + 0x8;
    decomp_var_40 = 0x65;
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
    sub_419e60(&decomp_var_40, &decomp_var_48, decomp_var_70);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    edx = decomp_var_50;
    eax = 0x0;
    if (*(edx[0x2] + 0x2404) > 0x0) {
            ecx = ebx * 0xa8 + 0x4d5528;
            do {
                    *ecx = *(eax * 0x8 + 0x4d5480);
                    ecx[0x1] = *(eax * 0x8 + 0x4d5484);
                    eax = eax + 0x1;
                    ecx = ecx + 0x8;
            } while (eax < *(edx[0x2] + 0x2404));
    }
    decomp_var_5a = 0x1;
    sub_4113d0();
    sub_465fa0();
    eax = decomp_var_54 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    eax = decomp_var_5a;
    *0x0 = decomp_var_14;
    return eax;

loc_41dd51:
    if (*(ecx * 0x8 + 0x4d53d8) == 0x1) {
            if (*(ecx * 0x8 + 0x4d53dc) != 0x0) {
                    if ((*((ebx * 0x15 + ecx) * 0x8 + 0x4d5528) | *((ebx * 0x15 + ecx) * 0x8 + 0x4d552c)) == 0x0 && (*(ecx * 0x8 + 0x4d5480) | *(ecx * 0x8 + 0x4d5484)) != 0x0) {
                            decomp_var_51 = 0x1;
                    }
                    ecx = ecx + 0x1;
                    if (ecx < edx) {
                            continue;
                    }
                    break;
            }
            else {
                    decomp_var_51 = 0x1;
                    ecx = ecx + 0x1;
                    if (ecx < edx) {
                            continue;
                    }
                    break;
            }
    }
    else {
            if ((*((ebx * 0x15 + ecx) * 0x8 + 0x4d5528) | *((ebx * 0x15 + ecx) * 0x8 + 0x4d552c)) == 0x0 && (*(ecx * 0x8 + 0x4d5480) | *(ecx * 0x8 + 0x4d5484)) != 0x0) {
                    decomp_var_51 = 0x1;
            }
            ecx = ecx + 0x1;
            if (ecx < edx) {
                    continue;
            }
            break;
    }
    goto .l2;
    ebp = &arg_fffffffffffffffd;
    if (ebp < decomp_var_40) {
            continue;
    }
    break;

.l2:
    if (decomp_var_51 == 0x0) {
            decomp_var_6c = 0x4afa78;
            decomp_var_70 = &decomp_var_4c;
            sub_410c10(decomp_var_70, 0x4afa78, decomp_var_68);
            edx = **(decomp_var_4c - 0x10);
            eax = edx[0x4];
            esi = decomp_var_4c - 0x10;
            esp = (esp - 0x8) + 0x8;
            decomp_var_40 = 0x65;
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
            sub_419e60(&decomp_var_40, &decomp_var_48, decomp_var_70);
            eax = edi + 0x10 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            edx = decomp_var_50;
            eax = 0x0;
            if (*(edx[0x2] + 0x2404) > 0x0) {
                    ecx = ebx * 0xa8 + 0x4d5528;
                    do {
                            *ecx = *(eax * 0x8 + 0x4d5480);
                            ecx[0x1] = *(eax * 0x8 + 0x4d5484);
                            eax = eax + 0x1;
                            ecx = ecx + 0x8;
                    } while (eax < *(edx[0x2] + 0x2404));
            }
            decomp_var_5a = 0x1;
            sub_4113d0();
            sub_465fa0();
            eax = decomp_var_54 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            sub_465fa0();
            eax = decomp_var_5a;
            *0x0 = decomp_var_14;
    }
    else {
            if (decomp_var_52 == 0x1) {
                    sub_4113d0();
            }
            sub_465fa0();
            eax = decomp_var_54 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            sub_465fa0();
            eax = decomp_var_5a;
            *0x0 = decomp_var_14;
    }
    return eax;
    if (decomp_var_52 == 0x1) {
            esp = esp - 0x4;
            eax = sub_46b050(&decomp_var_38, decomp_var_68, decomp_var_64);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_4c, "Recalculating: Because we have applied a peace deal %s", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_20 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_4c - 0x10) + 0x10;
            decomp_var_6c = &decomp_var_40;
            esp = (esp - 0x4) + 0x4 - 0x8;
            decomp_var_70 = &decomp_var_38;
            sub_419e60(decomp_var_70, decomp_var_6c, decomp_var_68);
            eax = esi - 0x10;
            decomp_var_4 = 0x2;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    decomp_var_6c = eax;
                    (*(**eax + 0x4))(decomp_var_6c);
            }
    }
    goto loc_41dd31;
}
