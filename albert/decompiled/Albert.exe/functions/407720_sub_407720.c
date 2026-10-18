// sub_407720 @ 0x407720
// hopper name: sub_407720
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_407720() {
    var_8 = 0x4944b3;
    var_C = *0x0;
    decomp_var_f4 = ebp;
    decomp_var_f8 = esi;
    decomp_var_fc = edi;
    esp = esp - 0x100;
    *0x0 = &var_C;
    esi = ecx;
    ecx = esi[0x1];
    eax = ecx[0x1];
    ebp = arg_0;
    if (eax[0x7d] == 0x0) {
            edx = *ebp;
            do {
                    if (eax[0x3] < edx) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0x7d] == 0x0);
    }
    edi = ecx;
    if (ecx != esi[0x1]) {
            if (*ebp < ecx[0x3]) {
                    eax = sub_4064f0();
                    var_E4 = *ebp;
                    sub_4065f0(eax);
                    esp = esp - 0x14;
                    eax = sub_407330(&var_EC, esi, edi, &var_E4);
                    esi = *eax;
                    edi = eax[0x1];
                    sub_406440();
                    sub_406440();
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
            eax = sub_4064f0();
            var_E4 = *ebp;
            sub_4065f0(eax);
            esp = esp - 0x14;
            eax = sub_407330(&var_EC, esi, edi, &var_E4);
            esi = *eax;
            edi = eax[0x1];
            sub_406440();
            sub_406440();
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
