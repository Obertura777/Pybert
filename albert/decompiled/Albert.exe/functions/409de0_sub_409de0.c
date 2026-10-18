// sub_409de0 @ 0x409de0
// hopper name: sub_409de0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_409de0() {
    var_8 = sub_494580;
    var_C = *0x0;
    decomp_var_54 = ebx;
    decomp_var_58 = ebp;
    decomp_var_5c = esi;
    decomp_var_60 = edi;
    esp = esp - 0x64;
    *0x0 = &var_C;
    esi = ecx;
    ecx = esi[0x1];
    eax = ecx[0x1];
    ebp = arg_0;
    if (eax[0x29] == 0x0) {
            edx = *ebp;
            do {
                    if (eax[0x3] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x29] == 0x0);
    }
    edi = ecx;
    if (ecx != esi[0x1]) {
            if (*ebp < ecx[0x3]) {
                    eax = sub_410330();
                    var_38 = eax;
                    eax[0x19] = 0x1;
                    var_38[0x1] = var_38;
                    *var_38 = var_38;
                    var_38[0x2] = var_38;
                    var_24 = *arg_4;
                    sub_405e40(&var_3C);
                    eax = sub_407b40(&var_4C, esi, edi, &var_24);
                    esi = *eax;
                    edi = eax[0x1];
                    sub_4053f0(&var_44, &var_20, *var_1C, &var_20, var_1C);
                    sub_47c8f9();
                    sub_4053f0(&var_44, &var_3C, *var_38, &var_3C, var_38);
                    sub_47c8f9();
                    esp = ((esp - 0x2c) + 0x4 - 0x18) + 0x4;
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi + 0x10;
                    *0x0 = var_8;
            }
            else {
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi + 0x10;
                    *0x0 = var_8;
            }
    }
    else {
            eax = sub_410330();
            var_38 = eax;
            eax[0x19] = 0x1;
            var_38[0x1] = var_38;
            *var_38 = var_38;
            var_38[0x2] = var_38;
            var_24 = *arg_4;
            sub_405e40(&var_3C);
            eax = sub_407b40(&var_4C, esi, edi, &var_24);
            esi = *eax;
            edi = eax[0x1];
            sub_4053f0(&var_44, &var_20, *var_1C, &var_20, var_1C);
            sub_47c8f9();
            sub_4053f0(&var_44, &var_3C, *var_38, &var_3C, var_38);
            sub_47c8f9();
            esp = ((esp - 0x2c) + 0x4 - 0x18) + 0x4;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi + 0x10;
            *0x0 = var_8;
    }
    return eax;
}
