// sub_40b350 @ 0x40b350
// hopper name: sub_40b350
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b350() {
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    ebp = ecx;
    esi = &arg_244c;
    esp = esp - 0x28;
    eax = sub_402060(&var_8, &arg_0, decomp_var_20, decomp_var_1c, decomp_var_18);
    edi = *eax;
    edx = esi[0x1];
    ebx = eax[0x1];
    var_C = edx;
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebx != var_C) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x10];
            if (eax != 0x2) {
                    if (eax == 0x6) {
                            if (ebx[0x6b] == 0x0) {
                                    esp = esp - 0x4;
                                    sub_40b350(ebx[0x9]);
                                    if (ebx[0x6b] != 0x0) {
                                            ebx = esi[0x1];
                                            edi = esi;
                                    }
                            }
                            else {
                                    ebx = esi[0x1];
                                    edi = esi;
                            }
                    }
                    else {
                            if (ebx[0x6b] != 0x0) {
                                    ebx = esi[0x1];
                                    edi = esi;
                            }
                    }
            }
            else {
                    if (ebx[0x6b] == 0x0) {
                            esp = esp - 0x4;
                            sub_40b350(ebx[0x9]);
                            if (ebx[0x6b] != 0x0) {
                                    ebx = esi[0x1];
                                    edi = esi;
                            }
                    }
                    else {
                            ebx = esi[0x1];
                            edi = esi;
                    }
            }
    }
    var_C = esi[0x1];
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebx != var_C) {
            eax = sub_40a990(arg_0);
    }
    else {
            esi = arg_0;
            esp = esp - 0x4;
            eax = sub_409790(esi, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14);
            if (eax == 0xffffffff) {
                    eax = sub_4093f0(esi, decomp_var_20, decomp_var_1c, decomp_var_18);
            }
            else {
                    eax = sub_409250(eax);
            }
    }
    return eax;
}
