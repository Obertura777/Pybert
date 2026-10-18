// sub_40a030 @ 0x40a030
// hopper name: sub_40a030
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40a030() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_6c = ebx;
    decomp_var_70 = ebp;
    ebp = *ecx[0x947];
    ebx = ecx + 0x2518;
    decomp_var_74 = esi;
    esp = esp - 0x78;
    decomp_var_78 = edi;
    var_5C = ecx;
    var_65 = 0x0;
    var_48 = ebp;
    goto loc_40a058;

loc_40a058:
    edi = ebx[0x1];
    esi = ebx;
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (ebp == edi) goto .l15;
    goto loc_40a072;

.l15:
    break;

loc_40a072:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    var_54 = arg_4;
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    if (arg_8 == 0xffffffff) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    edi = var_5C + 0x2450;
    eax = sub_407720(&var_54);
    esp = esp - 0x8;
    esi = sub_407720(eax + 0x14);
    eax = esi[0xc];
    if (eax != 0x3) goto loc_40a0d9;
    goto loc_40a0cb;
    eax = var_65;
    &decomp_var_68 = decomp_var_70;
    return eax;

loc_40a0d9:
    if (eax != 0x4) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    var_64 = esi[0x8];
    esp = esp - 0x4;
    decomp_var_7c = esi + 0x1c;
    var_60 = sub_407720(decomp_var_7c);
    if (var_64 == 0xffffffff) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    if (ebp == ebx[0x1]) {
            sub_47a948();
    }
    var_58 = arg_8;
    eax = sub_407720(&var_58);
    edi = eax;
    esp = esp - 0xc;
    eax = sub_4020d0(&var_24, &var_58, decomp_var_78, decomp_var_74, decomp_var_70);
    ebp = *eax;
    var_40 = eax[0x1];
    var_30 = ebx[0x1];
    if (ebp == 0x0 || ebp != ebx) {
            sub_47a948();
    }
    if (var_40 == var_30) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (var_40 == ret_addr) {
            sub_47a948();
    }
    ebp = &arg_2c;
    esp = esp - 0xc;
    var_50 = sub_409640(var_64, 0x0, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c);
    sub_404da0(esi);
    if (esi[0x44] != 0x0) {
            var_60[0x10] = var_60[0x10] - 0x1;
    }
    esp = esp - 0x10;
    var_64 = sub_409640(var_64, 0x0, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c);
    eax = sub_404ce0(&var_C, esi, decomp_var_78);
    if (esi[0x44] != 0x0) {
            eax = var_60;
            eax[0x10] = eax[0x10] + 0x1;
    }
    eax = eax | 0xffffffff;
    if (var_50 == eax) goto .l3;
    goto loc_40a1e4;

loc_40a0cb:
    var_64 = esi[0x7];
    esp = esp - 0x4;
    decomp_var_7c = &var_64;
    var_60 = sub_407720(decomp_var_7c);
    if (var_64 == 0xffffffff) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    if (ebp == ebx[0x1]) {
            sub_47a948();
    }
    var_58 = arg_8;
    eax = sub_407720(&var_58);
    edi = eax;
    esp = esp - 0xc;
    eax = sub_4020d0(&var_24, &var_58, decomp_var_78, decomp_var_74, decomp_var_70);
    ebp = *eax;
    var_40 = eax[0x1];
    var_30 = ebx[0x1];
    if (ebp == 0x0 || ebp != ebx) {
            sub_47a948();
    }
    if (var_40 == var_30) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (var_40 == ret_addr) {
            sub_47a948();
    }
    ebp = &arg_2c;
    esp = esp - 0xc;
    var_50 = sub_409640(var_64, 0x0, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c);
    sub_404da0(esi);
    if (esi[0x44] != 0x0) {
            var_60[0x10] = var_60[0x10] - 0x1;
    }
    esp = esp - 0x10;
    var_64 = sub_409640(var_64, 0x0, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c);
    eax = sub_404ce0(&var_C, esi, decomp_var_78);
    if (esi[0x44] != 0x0) {
            eax = var_60;
            eax[0x10] = eax[0x10] + 0x1;
    }
    eax = eax | 0xffffffff;
    if (var_50 == eax) goto loc_40a2cb;
    goto .l2;

.l3:
    if (var_64 != eax) {
            var_40[0x6] = 0x4;
    }
    else {
            esp = esp - 0x8;
            eax = sub_4020d0(&var_14, &var_58, decomp_var_78, decomp_var_74, decomp_var_70);
            ecx = *eax;
            esi = eax[0x1];
            edi = ebx[0x1];
            var_3C = ecx;
            if (ecx == 0x0 || ecx != ebx) {
                    sub_47a948();
            }
            if (esi != edi) {
                    eax = sub_410b70();
                    *(eax + 0x8) = 0x0;
                    *(eax + 0xc) = 0x0;
            }
            esi = var_48;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            var_65 = 0x1;
            esi[0x4] = 0xffffffff;
    }
    goto .l5;

loc_40a1e4:
    if (var_64 == eax) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    ebp = *edi[0xa];
    esi = edi + 0x24;
    goto loc_40a1f6;

loc_40a2cb:
    if (var_64 != eax) {
            var_40[0x6] = 0x4;
    }
    else {
            esp = esp - 0x8;
            eax = sub_4020d0(&var_14, &var_58, decomp_var_78, decomp_var_74, decomp_var_70);
            ecx = *eax;
            esi = eax[0x1];
            edi = ebx[0x1];
            var_3C = ecx;
            if (ecx == 0x0 || ecx != ebx) {
                    sub_47a948();
            }
            if (esi != edi) {
                    eax = sub_410b70();
                    *(eax + 0x8) = 0x0;
                    *(eax + 0xc) = 0x0;
            }
            esi = var_48;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            var_65 = 0x1;
            esi[0x4] = 0xffffffff;
    }
    goto .l7;

.l2:
    if (var_64 == eax) {
            ecx = ebx[0x1];
            eax = ecx[0x1];
            if (eax[0x1d] != 0x0) {
                    var_48 = ecx;
                    ebp = ecx;
                    continue;
            }
            edx = var_54;
            do {
                    if (edx < eax[0x3]) {
                            ecx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x1d] == 0x0);
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    ebp = *edi[0xa];
    esi = edi + 0x24;
    goto .l6;

.l5:
    ecx = ebx[0x1];
    eax = ecx[0x1];
    if (eax[0x1d] != 0x0) {
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    edx = var_54;
    do {
            if (edx < eax[0x3]) {
                    ecx = eax;
                    eax = *eax;
            }
            else {
                    eax = eax[0x2];
            }
    } while (eax[0x1d] == 0x0);
    var_48 = ecx;
    ebp = ecx;
    continue;

loc_40a1f6:
    eax = edi + 0x24;
    var_28 = edi[0xa];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp != var_28) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_407720(&arg_0);
            eax[0xc] = 0x1;
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebp = *ebp;
            continue;
    }
    break;

.l7:
    ecx = ebx[0x1];
    eax = ecx[0x1];
    if (eax[0x1d] != 0x0) {
            var_48 = ecx;
            ebp = ecx;
            continue;
    }
    edx = var_54;
    do {
            if (edx < eax[0x3]) {
                    ecx = eax;
                    eax = *eax;
            }
            else {
                    eax = eax[0x2];
            }
    } while (eax[0x1d] == 0x0);
    var_48 = ecx;
    ebp = ecx;
    continue;

.l6:
    eax = edi + 0x24;
    var_28 = edi[0xa];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp != var_28) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_407720(&arg_0);
            eax[0xc] = 0x1;
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebp = *ebp;
            continue;
    }
    break;
    edi[0xc] = 0x9;
    edi[0x56] = 0x1;
    sub_401950(*(edi[0xe] + 0x4));
    eax = *(edi + 0x38);
    eax[0x1] = eax;
    eax = *(edi + 0x38);
    *(edi + 0x3c) = 0x0;
    *eax = eax;
    esi = *(edi + 0x38);
    esi[0x2] = esi;
    edi[0x10] = 0x0;
    esp = esp - 0xc;
    eax = sub_4020d0(&var_1C, &var_58, decomp_var_78, decomp_var_74, decomp_var_70);
    esi = *eax;
    edi = eax[0x1];
    ebp = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            edi[0x5] = 0x0;
            edi[0x6] = 0x0;
    }
    esi = var_48;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    var_65 = 0x1;
    esi[0x4] = 0xffffffff;
    goto .l5;
    edi[0xc] = 0x9;
    edi[0x56] = 0x1;
    sub_401950(*(edi[0xe] + 0x4));
    eax = *(edi + 0x38);
    eax[0x1] = eax;
    eax = *(edi + 0x38);
    *(edi + 0x3c) = 0x0;
    *eax = eax;
    esi = *(edi + 0x38);
    esi[0x2] = esi;
    edi[0x10] = 0x0;
    esp = esp - 0xc;
    eax = sub_4020d0(&var_1C, &var_58, decomp_var_78, decomp_var_74, decomp_var_70);
    esi = *eax;
    edi = eax[0x1];
    ebp = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            edi[0x5] = 0x0;
            edi[0x6] = 0x0;
    }
    esi = var_48;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    var_65 = 0x1;
    esi[0x4] = 0xffffffff;
    goto .l7;
}
