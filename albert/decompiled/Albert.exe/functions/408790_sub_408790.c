// sub_408790 @ 0x408790
// hopper name: sub_408790
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_408790() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_3c = ebx;
    decomp_var_40 = ebp;
    decomp_var_44 = esi;
    esi = ecx;
    ebx = *esi[0x944];
    esp = esp - 0x48;
    var_48 = edi;
    edi = esi + 0x250c;
    var_34 = esi;
    var_2C = edi;
    var_28 = ebx;
    &var_48 = &var_48;
    goto loc_4087c0;

loc_4087c0:
    ebp = esi[0x944];
    eax = esi + 0x250c;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx != ebp) {
            var_C = 0xffffffff;
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi + 0x2450;
            var_30 = ebx + 0xc;
            sub_407720(ebx + 0xc);
            esp = esp - 0xc;
            eax = sub_402060(&var_1C, &arg_c, var_48, decomp_var_44, decomp_var_40);
            ebx = *eax;
            edi = eax[0x1];
            var_20 = esi[0x1];
            if (ebx == 0x0 || ebx != esi) {
                    sub_47a948();
            }
            if (edi == var_20) {
                    if (var_28 == var_2C[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_405c60(var_30);
                    *eax = var_C;
                    eax[0x1] = 0x0;
                    eax[0x2] = 0x0;
                    sub_401520();
                    ebx = var_28;
                    edi = var_2C;
                    esi = var_34;
                    continue;
            }
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] == arg_0) {
                    if (var_28 == var_2C[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_405c60(var_30);
                    *eax = var_C;
                    eax[0x1] = 0x0;
                    eax[0x2] = 0x0;
                    sub_401520();
                    ebx = var_28;
                    edi = var_2C;
                    esi = var_34;
                    continue;
            }
            eax = edi[0x10];
            if (eax == 0x3) {
                    esp = esp - 0x4;
                    eax = sub_407720(edi + 0x2c);
                    if (eax[0xc] == 0x5) {
                            var_C = eax[0x7];
                    }
            }
            else {
                    if (eax == 0x4) {
                            esp = esp - 0x8;
                            eax = sub_402060(&var_14, edi + 0x30, var_48, decomp_var_44, decomp_var_40);
                            edi = *eax;
                            ebx = eax[0x1];
                            ebp = esi[0x1];
                            if (edi == 0x0 || edi != esi) {
                                    sub_47a948();
                            }
                            if (ebx != ebp) {
                                    if (edi == 0x0) {
                                            sub_47a948();
                                    }
                                    if (ebx == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (ebx[0x10] == 0x5) {
                                            var_C = ebx[0xb];
                                    }
                            }
                    }
            }
            if (var_28 == var_2C[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_405c60(var_30);
            *eax = var_C;
            eax[0x1] = 0x0;
            eax[0x2] = 0x0;
            sub_401520();
            ebx = var_28;
            edi = var_2C;
            esi = var_34;
            continue;
    }
    break;
    ebx = esi + 0x2518;
    esi = *esi[0x947];
    edi = ebx;
    var_2C = edi;
    var_28 = esi;
    goto loc_408937;

loc_408937:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] != 0xffffffff) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_4020d0(&var_14, esi + 0x10, var_48, decomp_var_44, decomp_var_40);
                    edi = *eax;
                    esi = eax[0x1];
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x6] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x5] = esi[0x5] + 0x1;
            }
            sub_401590();
            esi = var_28;
            edi = var_2C;
            continue;
    }
    break;
    &decomp_var_38 = decomp_var_40;
    return;
}
