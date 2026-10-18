// sub_4080f0 @ 0x4080f0
// hopper name: sub_4080f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4080f0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_3c = ebx;
    decomp_var_40 = ebp;
    decomp_var_44 = esi;
    esi = ecx;
    ebx = *esi[0x944];
    esp = esp - 0x48;
    var_48 = edi;
    edi = esi + 0x250c;
    var_30 = esi;
    var_28 = edi;
    var_24 = ebx;
    &var_48 = &var_48;
    goto loc_408120;

loc_408120:
    ebp = esi[0x944];
    eax = esi + 0x250c;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx == ebp) goto .l12;
    goto loc_408141;

.l12:
    break;

loc_408141:
    var_31 = 0x1;
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    ebp = esi + 0x2450;
    esp = esp - 0x4;
    edi = sub_407720(ebx + 0xc);
    eax = *edi[0xa];
    var_2C = edi;
    goto loc_408175;
    ebx = *esi[0x941];
    edi = esi + 0x2500;
    var_28 = edi;
    var_24 = ebx;
    goto loc_4082b0;

loc_408175:
    var_1C = eax;
    eax = edi + 0x24;
    ebx = eax;
    var_14 = edi[0xa];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (var_1C != var_14) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_1C == ebx[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_402060(&var_10, var_1C + 0x8, var_48, decomp_var_44, decomp_var_40);
            esi = *eax;
            edi = eax[0x1];
            ebx = ret_addr;
            if (esi == 0x0 || esi != ebp) {
                    sub_47a948();
            }
            if (edi != ebx) {
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x10] == 0x5) {
                            eax = var_2C;
                            if (edi[0xb] == *eax) {
                                    if (edi[0xc] != eax[0x5]) {
                                            var_31 = 0x0;
                                    }
                            }
                            else {
                                    var_31 = 0x0;
                            }
                    }
                    else {
                            var_31 = 0x0;
                    }
            }
            else {
                    var_31 = 0x0;
            }
            esi = var_1C;
            if (esi == *(var_2C + 0x28)) {
                    sub_47a948();
            }
            eax = *esi;
            esi = var_30;
            edi = var_2C;
            continue;
    }
    break;

loc_4082b0:
    ebp = esi[0x941];
    eax = esi + 0x2500;
    if (edi == 0x0 || edi != eax) {
            eax = sub_47a948();
    }
    if (ebx != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi + 0x2450;
            edi = sub_407720(ebx + 0xc);
            esp = esp - 0xc;
            eax = sub_402060(&var_8, edi + 0x1c, var_48, decomp_var_44, decomp_var_40);
            ebp = *eax;
            edx = esi[0x1];
            ebx = eax[0x1];
            var_14 = edx;
            if (ebp == 0x0 || ebp != esi) {
                    sub_47a948();
            }
            if (ebx == var_14) {
                    edi[0x55] = 0x1;
                    esp = esp - 0xc;
                    edi[0x55] = 0x1;
                    edi[0xc] = 0x1;
                    eax = sub_402b70(&var_10, var_28, var_24, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, var_30, var_2C, var_28, var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10);
                    ecx = *eax;
                    edx = eax[0x1];
                    esi = var_30;
                    var_28 = ecx;
                    var_24 = edx;
                    edi = ecx;
                    ebx = edx;
                    continue;
            }
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == ret_addr) {
                    sub_47a948();
            }
            if (ebx[0x8] != 0x6) {
                    edi[0x55] = 0x1;
                    esp = esp - 0xc;
                    edi[0x55] = 0x1;
                    edi[0xc] = 0x1;
                    eax = sub_402b70(&var_10, var_28, var_24, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, var_30, var_2C, var_28, var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10);
                    ecx = *eax;
                    edx = eax[0x1];
                    esi = var_30;
                    var_28 = ecx;
                    var_24 = edx;
                    edi = ecx;
                    ebx = edx;
                    continue;
            }
            if (ebx[0x4] != edi[0x7]) {
                    edi[0x55] = 0x1;
                    esp = esp - 0xc;
                    edi[0x55] = 0x1;
                    edi[0xc] = 0x1;
                    eax = sub_402b70(&var_10, var_28, var_24, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, var_30, var_2C, var_28, var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10);
                    ecx = *eax;
                    edx = eax[0x1];
                    esi = var_30;
                    var_28 = ecx;
                    var_24 = edx;
                    edi = ecx;
                    ebx = edx;
                    continue;
            }
            if (ebx[0x9] != edi[0x8]) {
                    edi[0x55] = 0x1;
                    esp = esp - 0xc;
                    edi[0x55] = 0x1;
                    edi[0xc] = 0x1;
                    eax = sub_402b70(&var_10, var_28, var_24, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, var_30, var_2C, var_28, var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10);
                    ecx = *eax;
                    edx = eax[0x1];
                    esi = var_30;
                    var_28 = ecx;
                    var_24 = edx;
                    edi = ecx;
                    ebx = edx;
                    continue;
            }
            if (ebx[0x10] == 0x6) {
                    sub_401520();
                    edi = var_28;
                    ebx = var_24;
                    esi = var_30;
                    continue;
            }
            esp = esp - 0xc;
            edi[0x55] = 0x1;
            edi[0xc] = 0x1;
            eax = sub_402b70(&var_10, var_28, var_24, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, var_30, var_2C, var_28, var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10);
            ecx = *eax;
            edx = eax[0x1];
            esi = var_30;
            var_28 = ecx;
            var_24 = edx;
            edi = ecx;
            ebx = edx;
            continue;
    }
    break;
    if (var_31 == 0x0) {
            esp = esp - 0xc;
            edi[0xc] = 0x9;
            edi[0x54] = 0x1;
            eax = sub_402b70(&var_8, var_28, var_24, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, var_30, var_2C, var_28, var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10);
            ecx = *eax;
            edx = eax[0x1];
            var_28 = ecx;
            var_24 = edx;
            ebx = edx;
            edi = ecx;
    }
    else {
            sub_401520();
            ebx = var_24;
            edi = var_28;
    }
    continue;
    &decomp_var_38 = decomp_var_40;
    return eax;
}
