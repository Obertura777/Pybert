// sub_4273a0 @ 0x4273a0
// hopper name: sub_4273a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4273a0() {
    var_C = *0x0;
    var_58 = ebp;
    decomp_var_5c = esi;
    decomp_var_60 = edi;
    esp = esp - 0x64;
    decomp_var_64 = *dword_4c8db8 ^ &decomp_var_60;
    *0x0 = &var_C;
    esi = ecx;
    ecx = esi[0x1];
    eax = ecx[0x1];
    edx = arg_0;
    if (eax[0x2d] == 0x0) {
            edi = *(int16_t *)edx & 0xffff;
            do {
                    if (eax[0x6] < edi) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x2d] == 0x0);
    }
    edi = ecx;
    if (ecx != esi[0x1]) {
            if (*(int16_t *)edx < ecx[0x6]) {
                    var_2C = 0xf;
                    decomp_var_64 = 0xffffffff;
                    decomp_var_68 = 0x0;
                    decomp_var_6c = &var_44;
                    sub_4024f0(decomp_var_6c, 0x0, 0xffffffff);
                    esp = esp - 0x1c;
                    eax = sub_425ae0(&var_58, esi, edi, &var_34);
                    esi = *eax;
                    edi = eax[0x1];
                    if (var_18 >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    ebx = 0x0;
                    if (var_38 >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi + 0x10;
                    *0x0 = var_14;
            }
            else {
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi + 0x10;
                    *0x0 = var_14;
            }
    }
    else {
            var_2C = 0xf;
            decomp_var_64 = 0xffffffff;
            decomp_var_68 = 0x0;
            decomp_var_6c = &var_44;
            sub_4024f0(decomp_var_6c, 0x0, 0xffffffff);
            esp = esp - 0x1c;
            eax = sub_425ae0(&var_58, esi, edi, &var_34);
            esi = *eax;
            edi = eax[0x1];
            if (var_18 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            if (var_38 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            ebx = 0x0;
            if (esi == ebx) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi + 0x10;
            *0x0 = var_14;
    }
    return eax;
}
