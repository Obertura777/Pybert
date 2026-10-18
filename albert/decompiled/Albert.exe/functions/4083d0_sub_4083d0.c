// sub_4083d0 @ 0x4083d0
// hopper name: sub_4083d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4083d0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_2c = ebx;
    decomp_var_30 = ebp;
    decomp_var_34 = esi;
    esi = ecx;
    ebx = *esi[0x93e];
    esp = esp - 0x38;
    var_38 = edi;
    edi = esi + 0x24f4;
    var_24 = esi;
    var_20 = edi;
    var_1C = ebx;
    &var_38 = &var_38;
    goto loc_408400;

loc_408400:
    ebp = esi[0x93e];
    eax = esi + 0x24f4;
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
            sub_407720(ebx + 0xc);
            esp = esp - 0xc;
            eax = sub_402060(&var_10, &arg_14, var_38, decomp_var_34, decomp_var_30);
            edi = *eax;
            ebx = eax[0x1];
            var_14 = esi[0x1];
            if (edi == 0x0 || edi != esi) {
                    sub_47a948();
            }
            if (ebx == var_14) {
                    esp = esp - 0xc;
                    arg_28 = 0x1;
                    eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                    edx = *eax;
                    eax = eax[0x1];
                    esi = var_24;
                    var_20 = edx;
                    var_1C = eax;
                    edi = edx;
                    ebx = eax;
                    continue;
            }
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            if (arg_28 == 0x3) {
                    ebx = ebx[0x10];
                    if (ebx == 0x2) {
                            esp = esp - 0xc;
                            arg_28 = 0x1;
                            eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                            edx = *eax;
                            eax = eax[0x1];
                            esi = var_24;
                            var_20 = edx;
                            var_1C = eax;
                            edi = edx;
                            ebx = eax;
                            continue;
                    }
                    if (ebx == 0x6) {
                            esp = esp - 0xc;
                            arg_28 = 0x1;
                            eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                            edx = *eax;
                            eax = eax[0x1];
                            esi = var_24;
                            var_20 = edx;
                            var_1C = eax;
                            edi = edx;
                            ebx = eax;
                            continue;
                    }
                    if (ebx == 0x9) {
                            esp = esp - 0xc;
                            arg_28 = 0x1;
                            eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                            edx = *eax;
                            eax = eax[0x1];
                            esi = var_24;
                            var_20 = edx;
                            var_1C = eax;
                            edi = edx;
                            ebx = eax;
                            continue;
                    }
                    sub_401520();
                    edi = var_20;
                    ebx = var_1C;
                    esi = var_24;
                    continue;
            }
            eax = ebx[0x8];
            if (eax != 0x2) {
                    if (eax != 0x6) {
                            esp = esp - 0xc;
                            arg_28 = 0x1;
                            eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                            edx = *eax;
                            eax = eax[0x1];
                            esi = var_24;
                            var_20 = edx;
                            var_1C = eax;
                            edi = edx;
                            ebx = eax;
                            continue;
                    }
                    if (ebx[0x9] != arg_18) {
                            esp = esp - 0xc;
                            arg_28 = 0x1;
                            eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                            edx = *eax;
                            eax = eax[0x1];
                            esi = var_24;
                            var_20 = edx;
                            var_1C = eax;
                            edi = edx;
                            ebx = eax;
                            continue;
                    }
                    ebx = ebx[0x10];
                    if (ebx == 0x2) {
                            sub_401520();
                            edi = var_20;
                            ebx = var_1C;
                            esi = var_24;
                            continue;
                    }
                    if (ebx != 0x6) {
                            esp = esp - 0xc;
                            arg_28 = 0x1;
                            eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                            edx = *eax;
                            eax = eax[0x1];
                            esi = var_24;
                            var_20 = edx;
                            var_1C = eax;
                            edi = edx;
                            ebx = eax;
                            continue;
                    }
                    sub_401520();
                    edi = var_20;
                    ebx = var_1C;
                    esi = var_24;
                    continue;
            }
            if (ebx[0x9] != arg_18) {
                    esp = esp - 0xc;
                    arg_28 = 0x1;
                    eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                    edx = *eax;
                    eax = eax[0x1];
                    esi = var_24;
                    var_20 = edx;
                    var_1C = eax;
                    edi = edx;
                    ebx = eax;
                    continue;
            }
            ebx = ebx[0x10];
            if (ebx == 0x2) {
                    sub_401520();
                    edi = var_20;
                    ebx = var_1C;
                    esi = var_24;
                    continue;
            }
            if (ebx != 0x6) {
                    esp = esp - 0xc;
                    arg_28 = 0x1;
                    eax = sub_402b70(&var_8, var_20, var_1C, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, var_24, var_20, var_1C, decomp_var_18, var_14, var_10, decomp_var_c, var_8, decomp_var_4, saved_fp);
                    edx = *eax;
                    eax = eax[0x1];
                    esi = var_24;
                    var_20 = edx;
                    var_1C = eax;
                    edi = edx;
                    ebx = eax;
                    continue;
            }
            sub_401520();
            edi = var_20;
            ebx = var_1C;
            esi = var_24;
            continue;
    }
    break;
    &decomp_var_28 = decomp_var_30;
    return eax;
}
