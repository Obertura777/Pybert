// sub_420630 @ 0x420630
// hopper name: sub_420630
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_420630() {
    decomp_var_c = *0x0;
    decomp_var_98 = ebx;
    decomp_var_9c = ebp;
    decomp_var_a0 = esi;
    decomp_var_a4 = edi;
    esp = esp - 0xa8;
    decomp_var_a8 = *dword_4c8db8 ^ &decomp_var_a4;
    *0x0 = &decomp_var_c;
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_401e30();
    decomp_var_74 = eax;
    eax[0x11] = 0x1;
    decomp_var_74[0x1] = decomp_var_74;
    *decomp_var_74 = decomp_var_74;
    decomp_var_74[0x2] = decomp_var_74;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_4206ed;
    goto loc_4206e3;

loc_4206ed:
    decomp_var_30 = (*(*eax + 0xc))() + 0x10;
    eax = sub_466060(&decomp_var_6c, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    sub_466060(&decomp_var_6c, 0x0);
    eax = sub_465900(&decomp_var_92, 0x0);
    sub_465fa0();
    edi = sub_465930();
    eax = sub_419300(&decomp_var_50, &decomp_var_40, decomp_var_a8);
    sub_466060(&decomp_var_6c, 0x0);
    sub_465900(&decomp_var_92, 0x2);
    sub_465fa0();
    sub_404ce0(&decomp_var_50, &decomp_var_80, decomp_var_a8);
    eax = sub_404ce0(&decomp_var_50, &decomp_var_80, decomp_var_a8);
    eax = sub_466060(&decomp_var_6c, 0x1);
    esp = esp - 0x54;
    eax = sub_465900(&decomp_var_92, 0x0);
    esi = *(int16_t *)eax;
    sub_465fa0();
    if (*(int16_t *)word_4c6c1c == esi) goto .l2;
    goto loc_420847;

loc_4206e3:
    eax = sub_40b5a0(0x80004005);
    return eax;

.l2:
    eax = sub_466060(&decomp_var_6c, 0x2);
    esp = esp - 0x10;
    eax = sub_465900(&decomp_var_92, 0x0);
    decomp_var_7c = *(int8_t *)eax & 0xff;
    sub_465fa0();
    esi = &arg_10;
    edi = *arg_14;
    decomp_var_90 = esi;
    decomp_var_8c = edi;
    goto loc_420ba2;

loc_420847:
    if (*(int16_t *)word_4c6c10 == esi) goto loc_420b4b;
    goto loc_420854;

loc_420ba2:
    ebp = arg_14;
    if (esi == 0x0 || esi != &arg_10) {
            sub_47a948();
    }
    if (edi != ebp) {
            decomp_var_88 = decomp_var_80;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404fd0(&decomp_var_6c, &decomp_var_88, decomp_var_a8);
            sub_401520();
            edi = decomp_var_8c;
            esi = decomp_var_90;
            continue;
    }
    break;

loc_420b4b:
    eax = sub_466060(&decomp_var_6c, 0x2);
    esp = esp - 0x10;
    eax = sub_465900(&decomp_var_92, 0x0);
    decomp_var_7c = *(int8_t *)eax & 0xff;
    sub_465fa0();
    esi = &arg_10;
    edi = *arg_14;
    decomp_var_90 = esi;
    decomp_var_8c = edi;
    goto .l3;

loc_420854:
    if (*(int16_t *)word_4c6c20 != esi) goto loc_420c13;
    goto loc_420861;

loc_420c13:
    esp = esp - 0x4;
    eax = sub_46b050(&decomp_var_6c, decomp_var_a8, decomp_var_a4);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_30, "Recalculating: Because we have applied a XDO: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    if (decomp_var_54 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = decomp_var_30 - 0x10;
    edi = sub_40bfa0(esi) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_6c, &decomp_var_88, decomp_var_a8);
    eax = edi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    if (ecx <= 0x1) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_403430(&decomp_var_88, &decomp_var_78, *decomp_var_74, &decomp_var_78, decomp_var_74);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_403430(&decomp_var_88, &arg_10, *arg_14, &arg_10, arg_14);
    sub_47c8f9();
    eax = 0x1;
    *0x0 = decomp_var_c;
    return eax;

.l3:
    ebp = arg_14;
    if (esi == 0x0 || esi != &arg_10) {
            sub_47a948();
    }
    if (edi != ebp) {
            decomp_var_88 = decomp_var_80;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404fd0(&decomp_var_6c, &decomp_var_88, decomp_var_a8);
            sub_401520();
            edi = decomp_var_8c;
            esi = decomp_var_90;
            continue;
    }
    break;

loc_420861:
    eax = sub_466060(&decomp_var_6c, 0x2);
    sub_465ff0(eax);
    sub_465fa0();
    sub_466060(&decomp_var_6c, 0x1);
    sub_465900(&decomp_var_92, 0x0);
    sub_465fa0();
    sub_466060(&decomp_var_6c, 0x2);
    eax = sub_465900(&decomp_var_92, 0x0);
    ebp = *(int8_t *)eax & 0xff;
    sub_465fa0();
    sub_466060(&decomp_var_50, 0x2);
    eax = sub_466060(&decomp_var_6c, 0x0);
    eax = sub_465900(&decomp_var_92, 0x0);
    esi = *(int8_t *)eax & 0xff;
    sub_465fa0();
    sub_465fa0();
    esp = esp - 0x4c;
    eax = sub_404ce0(&decomp_var_50, &decomp_var_7c, decomp_var_a8);
    if (edi != 0x5) goto loc_420a96;
    goto loc_42098c;

loc_420a96:
    esp = esp - 0x8;
    eax = sub_404ce0(&decomp_var_6c, &decomp_var_7c, decomp_var_a8);
    edi = *arg_14;
    esi = &arg_10;
    decomp_var_90 = esi;
    decomp_var_8c = edi;
    goto loc_420ad0;

loc_42098c:
    sub_465aa0();
    eax = sub_466060(&decomp_var_6c, 0x4);
    eax = sub_465900(&decomp_var_92, 0x0);
    edi = *(int8_t *)eax & 0xff;
    sub_465fa0();
    esp = esp - 0x18;
    decomp_var_90 = ebp;
    sub_404fd0(&decomp_var_50, &decomp_var_90, decomp_var_a8);
    esi = &arg_10;
    decomp_var_90 = esi;
    decomp_var_8c = *arg_14;
    goto loc_420a10;

loc_420ad0:
    decomp_var_84 = arg_14;
    if (esi == 0x0 || esi != &arg_10) {
            sub_47a948();
    }
    if (edi != decomp_var_84) {
            decomp_var_50 = decomp_var_80;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_4193f0(&decomp_var_6c, &decomp_var_50, decomp_var_a8);
            sub_401520();
            edi = decomp_var_8c;
            esi = decomp_var_90;
            continue;
    }
    break;

loc_420a10:
    decomp_var_84 = arg_14;
    if (esi == 0x0 || esi != &arg_10) {
            sub_47a948();
    }
    if (decomp_var_8c != decomp_var_84) {
            decomp_var_50 = decomp_var_80;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (decomp_var_8c == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_4193f0(&decomp_var_6c, &decomp_var_50, decomp_var_a8);
            sub_401520();
            esi = decomp_var_90;
            continue;
    }
    break;
}
