// sub_4089d0 @ 0x4089d0
// hopper name: sub_4089d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4089d0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_64 = ebx;
    decomp_var_68 = ebp;
    decomp_var_6c = esi;
    esp = esp - 0x70;
    var_70 = edi;
    var_5C = ecx;
    esi = ecx + 0x2518;
    goto loc_4089e7;

loc_4089e7:
    eax = esi[0x1];
    edi = *eax;
    ebp = esi;
    ebx = eax;
    if (ebp == 0x0 || ebp != esi) {
            eax = sub_47a948();
    }
    if (edi == ebx) goto .l42;
    goto loc_408a05;

.l42:
    break;

loc_408a05:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (edi == ret_addr) {
            sub_47a948();
    }
    var_54 = edi[0x3];
    var_5D = 0x0;
    do {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (edi == ret_addr) {
                    sub_47a948();
            }
            if (edi[0x6] == 0x4) {
                    var_5D = 0x1;
            }
            if (edi == ret_addr) {
                    sub_47a948();
            }
            ebx = edi[0x4];
            esp = esp - 0x8;
            var_58 = ebx;
            eax = sub_4020d0(&var_28, &var_58, var_70, decomp_var_6c, decomp_var_68);
            ebp = *eax;
            edi = eax[0x1];
    } while (ebx != var_54);
    if (var_5D == 0x0) goto loc_408d66;
    goto loc_408a7a;
    &decomp_var_60 = decomp_var_68;
    return eax;

loc_408d66:
    edi = esi;
    ebp = *esi[0x1];
    var_50 = edi;
    var_4C = ebp;
    goto loc_408d77;

loc_408a7a:
    ebx = var_5C;
    ebp = *esi[0x1];
    var_50 = esi;
    var_4C = ebp;
    goto loc_408a94;

loc_408d77:
    ebx = esi[0x1];
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebp == ebx) goto .l35;
    goto loc_408d8f;

loc_408a94:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_407720(&arg_4);
    ecx = eax + 0x24;
    var_58 = ecx;
    esi = ecx;
    var_44 = *ecx[0x1];
    goto loc_408ac8;

.l35:
    break;

loc_408d8f:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    ebx = var_5C + 0x2450;
    esp = esp - 0x4;
    sub_407720(var_4C + 0xc);
    edi = *arg_20;
    esi = &arg_1c;
    goto loc_408dc5;

loc_408ac8:
    edi = ecx[0x1];
    if (esi == 0x0 || esi != ecx) {
            sub_47a948();
    }
    if (var_44 == edi) goto .l23;
    goto loc_408ae2;
    continue;

loc_408dc5:
    var_2C = esi[0x1];
    if (esi == 0x0 || esi != esi) {
            sub_47a948();
    }
    if (edi != var_2C) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            *(sub_407720(edi + 0x8) + 0x30) = 0x1;
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            edi = *edi;
            continue;
    }
    break;

.l23:
    break;

loc_408ae2:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (var_44 == esi[0x1]) {
            sub_47a948();
    }
    ecx = ebx[0x93b];
    eax = ecx[0x1];
    if (eax[0x15] == 0x0) {
            edx = var_44[0x2];
            do {
                    if (eax[0x3] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x15] == 0x0);
    }
    ebp = ebx + 0x24e8;
    esi = ecx;
    var_40 = ebp;
    var_3C = esi;
    goto loc_408b40;
    ebx = arg_30[0x1];
    esi = &arg_2c;
    edi = ebx;
    if (ebx[0x11] != 0x0) {
            eax = esi[0x1];
            edi = var_50;
            eax[0x1] = eax;
            eax = esi[0x1];
            esi[0x2] = 0x0;
            *eax = eax;
            esi = esi[0x1];
            esi[0x2] = esi;
            esi = var_4C;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = esi[0x4];
            decomp_var_74 = esi;
            esi = var_5C + 0x2518;
            eax = sub_403170(&var_10, edi, decomp_var_74, var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, var_5C, edx, var_54, var_50, var_4C, decomp_var_48, var_44, var_40, var_3C, var_38);
            esp = esp - 0x14;
            eax = sub_4020d0(&var_8, &var_58, var_70, decomp_var_6c, decomp_var_68);
            ecx = *eax;
            edx = eax[0x1];
            var_50 = ecx;
            var_4C = edx;
            ebp = edx;
            edi = ecx;
            continue;
    }
    do {
            sub_401950(edi[0x2]);
            edi = *edi;
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            ebx = edi;
    } while (edi[0x11] == 0x0);
    eax = esi[0x1];
    edi = var_50;
    eax[0x1] = eax;
    eax = esi[0x1];
    esi[0x2] = 0x0;
    *eax = eax;
    esi = esi[0x1];
    esi[0x2] = esi;
    esi = var_4C;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    edx = esi[0x4];
    decomp_var_74 = esi;
    esi = var_5C + 0x2518;
    eax = sub_403170(&var_10, edi, decomp_var_74, var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, var_5C, edx, var_54, var_50, var_4C, decomp_var_48, var_44, var_40, var_3C, var_38);
    esp = esp - 0x14;
    eax = sub_4020d0(&var_8, &var_58, var_70, decomp_var_6c, decomp_var_68);
    ecx = *eax;
    edx = eax[0x1];
    var_50 = ecx;
    var_4C = edx;
    ebp = edx;
    edi = ecx;
    continue;
    if (ebp == var_50[0x1]) {
            sub_47a948();
    }
    esi = ebx + 0x2518;
    esp = esp - 0x8;
    var_58 = arg_8;
    eax = sub_4020d0(&var_18, &var_58, var_70, decomp_var_6c, decomp_var_68);
    ecx = *eax;
    ebp = eax[0x1];
    edi = *esi[0x1];
    var_50 = ecx;
    var_4C = ebp;
    if (ecx == 0x0 || ecx != esi) {
            sub_47a948();
    }
    if (ebp != edi) {
            esi = var_50;
            continue;
    }
    break;

loc_408b40:
    if (var_44 == var_58[0x1]) {
            sub_47a948();
    }
    ecx = ebx[0x93b];
    eax = ecx[0x1];
    edi = ecx;
    if (eax[0x15] == 0x0) {
            ecx = var_44[0x2];
            do {
                    if (ecx < eax[0x3]) {
                            edi = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x15] == 0x0);
    }
    if (ebp == 0x0 || ebp != ebx + 0x24e8) {
            sub_47a948();
    }
    if (esi != edi) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (esi == ret_addr) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            ebx = sub_407720(esi + 0x10);
            ebx[0xc] = 0x9;
            ebp = *(ebx[0xe] + 0x4);
            esi = ebx + 0x34;
            edi = ebp;
            if (arg_9 != 0x0) {
                    eax = esi[0x1];
                    eax[0x1] = eax;
                    eax = esi[0x1];
                    esi[0x2] = 0x0;
                    *eax = eax;
                    esi = esi[0x1];
                    esi[0x2] = esi;
                    ebx[0x10] = 0x0;
                    ebx[0x59] = 0x1;
                    sub_40f400();
                    esi = var_3C;
                    ebp = var_40;
                    ebx = var_5C;
                    continue;
            }
            do {
                    sub_401950(edi[0x2]);
                    edi = *edi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = edi;
            } while (edi[0x11] == 0x0);
            eax = esi[0x1];
            eax[0x1] = eax;
            eax = esi[0x1];
            esi[0x2] = 0x0;
            *eax = eax;
            esi = esi[0x1];
            esi[0x2] = esi;
            ebx[0x10] = 0x0;
            ebx[0x59] = 0x1;
            sub_40f400();
            esi = var_3C;
            ebp = var_40;
            ebx = var_5C;
            continue;
    }
    break;
    if (var_44 == var_58[0x1]) {
            sub_47a948();
    }
    ecx = ebx[0x93b];
    eax = ecx[0x1];
    esi = ecx;
    if (eax[0x15] == 0x0) {
            ecx = var_44[0x2];
            do {
                    if (ecx < eax[0x3]) {
                            esi = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x15] == 0x0);
    }
    ecx = ebx[0x93b];
    eax = ecx[0x1];
    edi = ecx;
    if (eax[0x15] == 0x0) {
            ecx = var_44[0x2];
            &var_70 = &var_70;
            do {
                    if (eax[0x3] < ecx) {
                            eax = eax[0x2];
                    }
                    else {
                            edi = eax;
                            eax = *eax;
                    }
            } while (eax[0x15] == 0x0);
    }
    eax = ebx + 0x24e8;
    var_38 = eax;
    var_34 = edi;
    goto loc_408cb2;

loc_408cb2:
    if (eax == 0x0 || eax != ebx + 0x24e8) {
            sub_47a948();
    }
    if (var_34 != esi) {
            sub_40f400();
            eax = var_38;
            continue;
    }
    break;
    esp = esp - 0x14;
    eax = sub_403b00(&var_20, ebx + 0x24e8, edi, ebx + 0x24e8, esi);
    esi = var_58;
    edi = var_44;
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    ebp = var_4C;
    var_44 = *edi;
    ecx = var_58;
    continue;
}
