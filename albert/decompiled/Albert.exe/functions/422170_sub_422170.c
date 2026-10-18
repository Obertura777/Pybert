// sub_422170 @ 0x422170
// hopper name: sub_422170
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_422170() {
    decomp_var_18 = ebx;
    ebx = arg_0;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    esp = esp - 0x24;
    edi = ecx;
    esi = sub_40ef70(ebx);
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi != edi[0x1]) {
            eax = *ebx;
            ecx = esi[0x3];
            bool_2 = eax != ecx;
            if (eax >= ecx) {
                    if (!bool_2 && ebx[0x2] < esi[0x8]) {
                            var_C = *ebx;
                            esp = esp - 0x10;
                            eax = sub_41c580(&var_14, edi, esi, &var_C);
                            edi = *eax;
                            esi = eax[0x1];
                    }
            }
            else {
                    var_C = *ebx;
                    esp = esp - 0x10;
                    eax = sub_41c580(&var_14, edi, esi, &var_C);
                    edi = *eax;
                    esi = eax[0x1];
            }
    }
    else {
            var_C = *ebx;
            esp = esp - 0x10;
            eax = sub_41c580(&var_14, edi, esi, &var_C);
            edi = *eax;
            esi = eax[0x1];
    }
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi + 0x14;
    return eax;
}
