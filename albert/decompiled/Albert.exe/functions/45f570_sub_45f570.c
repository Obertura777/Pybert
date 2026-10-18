// sub_45f570 @ 0x45f570
// hopper name: sub_45f570
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f570() {
    var_C = *0x0;
    var_38 = ebx;
    var_40 = esi;
    var_44 = edi;
    eax = *dword_4c8db8;
    *0x0 = &var_C;
    edi = ecx;
    ebp = arg_0;
    esp = esp - 0x4c;
    var_4C = ebp;
    esi = sub_45bcf0(var_4C, eax ^ &var_44);
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi != edi[0x1]) {
            bool_6 = esi[0x9] < 0x10;
            ecx = esi[0x8];
            if (!bool_6) {
                    eax = esi[0x4];
            }
            else {
                    eax = esi + 0x10;
            }
            var_4C = eax;
            decomp_var_50 = arg_10;
            esp = esp - 0x10;
            decomp_var_54 = 0x0;
            if (sub_40e9b0() < 0x0) {
                    decomp_var_58 = 0xffffffff;
                    decomp_var_5c = 0x0;
                    decomp_var_60 = ebp;
                    var_24 = 0x0;
                    sub_4024f0(decomp_var_60, 0x0, 0xffffffff);
                    esp = esp - 0x1c;
                    eax = sub_45eff0(&var_4C, edi, esi, &var_44);
                    edi = *eax;
                    esi = eax[0x1];
                    if (var_2C >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi + 0x28;
                    *0x0 = var_24;
            }
            else {
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi + 0x28;
                    *0x0 = var_24;
            }
    }
    else {
            decomp_var_58 = 0xffffffff;
            decomp_var_5c = 0x0;
            decomp_var_60 = ebp;
            var_24 = 0x0;
            sub_4024f0(decomp_var_60, 0x0, 0xffffffff);
            esp = esp - 0x1c;
            eax = sub_45eff0(&var_4C, edi, esi, &var_44);
            edi = *eax;
            esi = eax[0x1];
            if (var_2C >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            ebx = 0x0;
            if (edi == ebx) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi + 0x28;
            *0x0 = var_24;
    }
    return eax;
}
