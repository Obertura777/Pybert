// sub_4075b0 @ 0x4075b0
// hopper name: sub_4075b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4075b0() {
    var_8 = sub_494480;
    var_C = *0x0;
    decomp_var_3c = ebx;
    decomp_var_40 = ebp;
    decomp_var_44 = esi;
    decomp_var_48 = edi;
    esp = esp - 0x4c;
    *0x0 = &var_C;
    esi = ecx;
    ecx = esi[0x1];
    eax = ecx[0x1];
    ebp = arg_0;
    if (eax[0x1d] == 0x0) {
            edx = *(int16_t *)ebp & 0xffff;
            do {
                    if (eax[0x6] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x1d] == 0x0);
    }
    edi = ecx;
    if (ecx != esi[0x1]) {
            if (*(int16_t *)ebp < ecx[0x6]) {
                    eax = sub_40ff50();
                    var_20 = eax;
                    eax[0x15] = 0x1;
                    var_20[0x1] = var_20;
                    *var_20 = var_20;
                    var_20[0x2] = var_20;
                    var_18 = *(int16_t *)arg_4;
                    sub_405db0(&var_24);
                    eax = sub_407160(&var_34, esi, edi, &var_18);
                    esi = *eax;
                    edi = eax[0x1];
                    sub_405260(&var_2C, &var_14, *var_10, &var_14, var_10);
                    sub_47c8f9();
                    sub_405260(&var_2C, &var_24, *var_20, &var_24, var_20);
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
            eax = sub_40ff50();
            var_20 = eax;
            eax[0x15] = 0x1;
            var_20[0x1] = var_20;
            *var_20 = var_20;
            var_20[0x2] = var_20;
            var_18 = *(int16_t *)arg_4;
            sub_405db0(&var_24);
            eax = sub_407160(&var_34, esi, edi, &var_18);
            esi = *eax;
            edi = eax[0x1];
            sub_405260(&var_2C, &var_14, *var_10, &var_14, var_10);
            sub_47c8f9();
            sub_405260(&var_2C, &var_24, *var_20, &var_24, var_20);
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
