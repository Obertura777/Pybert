// sub_41c1e0 @ 0x41c1e0
// hopper name: sub_41c1e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41c1e0() {
    decomp_var_1c = ebx;
    ebx = arg_0;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    esp = esp - 0x28;
    edi = ecx;
    esi = sub_40ead0(ebx);
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi != edi[0x1]) {
            eax = *ebx;
            ecx = esi[0x4];
            bool_9 = eax != ecx;
            if (eax >= ecx) {
                    if (!bool_9) {
                            if (ebx[0x2] < esi[0xa]) {
                                    var_10 = *ebx;
                                    esp = esp - 0x10;
                                    eax = sub_419590(&var_18, edi, esi, &var_10);
                                    edi = *eax;
                                    esi = eax[0x1];
                            }
                            if (edi == 0x0) {
                                    sub_47a948();
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi + 0x18;
                    }
                    else {
                            if (edi == 0x0) {
                                    sub_47a948();
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi + 0x18;
                    }
            }
            else {
                    var_10 = *ebx;
                    esp = esp - 0x10;
                    eax = sub_419590(&var_18, edi, esi, &var_10);
                    edi = *eax;
                    esi = eax[0x1];
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi + 0x18;
            }
    }
    else {
            var_10 = *ebx;
            esp = esp - 0x10;
            eax = sub_419590(&var_18, edi, esi, &var_10);
            edi = *eax;
            esi = eax[0x1];
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi + 0x18;
    }
    return eax;
}
