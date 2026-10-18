// sub_422200 @ 0x422200
// hopper name: sub_422200
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_422200() {
    edx = ecx[0x1];
    eax = edx[0x1];
    decomp_var_28 = ebx;
    ebx = arg_0;
    decomp_var_2c = esi;
    esp = esp - 0x30;
    if (eax[0x29] == 0x0) {
            esi = *ebx;
            do {
                    if (eax[0x3] < esi) {
                            eax = eax[0x2];
                    }
                    else {
                            edx = eax;
                            eax = *eax;
                    }
            } while (eax[0x29] == 0x0);
    }
    edi = edx;
    esi = ecx;
    if (edx != ecx[0x1]) {
            if (*ebx < edx[0x3]) {
                    var_18 = *ebx;
                    esp = esp - 0x10;
                    eax = sub_41c780(&var_20, esi, edi, &var_18);
                    esi = *eax;
                    edi = eax[0x1];
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi + 0x10;
            }
            else {
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi + 0x10;
            }
    }
    else {
            var_18 = *ebx;
            esp = esp - 0x10;
            eax = sub_41c780(&var_20, esi, edi, &var_18);
            esi = *eax;
            edi = eax[0x1];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi + 0x10;
    }
    return eax;
}
