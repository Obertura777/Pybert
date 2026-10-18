// sub_405c60 @ 0x405c60
// hopper name: sub_405c60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_405c60() {
    edx = ecx[0x1];
    eax = edx[0x1];
    decomp_var_1c = ebx;
    ebx = arg_0;
    decomp_var_20 = esi;
    esp = esp - 0x24;
    if (eax[0x1d] == 0x0) {
            esi = *ebx;
            do {
                    if (eax[0x3] < esi) {
                            eax = eax[0x2];
                    }
                    else {
                            edx = eax;
                            eax = *eax;
                    }
            } while (eax[0x1d] == 0x0);
    }
    edi = edx;
    esi = ecx;
    if (edx == ecx[0x1] || *ebx < edx[0x3]) {
            var_C = *ebx;
            esp = esp - 0x10;
            eax = sub_4056d0(&var_14, esi, edi, &var_C);
            esi = *eax;
            edi = eax[0x1];
    }
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi + 0x10;
    return eax;
}
