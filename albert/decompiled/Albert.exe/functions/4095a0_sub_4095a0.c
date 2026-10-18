// sub_4095a0 @ 0x4095a0
// hopper name: sub_4095a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4095a0() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    esi = ecx + 0x2450;
    esp = esp - 0x20;
    eax = sub_402060(&var_8, &arg_0, decomp_var_18, decomp_var_14, decomp_var_10);
    edi = *eax;
    ebx = eax[0x1];
    ebp = esi[0x1];
    if (edi == 0x0 || edi != esi) {
            eax = sub_47a948();
    }
    if (ebx != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x10];
            edi = ebx + 0x10;
            if (eax != 0x3) {
                    if (eax == 0x4) {
                            esp = esp - 0x4;
                            eax = sub_407720(edi + 0x1c);
                            esi = eax;
                            if (esi != 0x0) {
                                    esp = esp - 0x4;
                                    sub_404da0(edi);
                                    if (edi[0x44] != 0x0) {
                                            esi[0x10] = esi[0x10] - 0x1;
                                    }
                                    eax = 0x1;
                                    edi[0xc] = 0x1;
                                    edi[0x58] = 0x1;
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    eax = sub_407720(edi + 0x1c);
                    esi = eax;
                    if (esi != 0x0) {
                            esp = esp - 0x4;
                            sub_404da0(edi);
                            if (edi[0x44] != 0x0) {
                                    esi[0x10] = esi[0x10] - 0x1;
                            }
                            eax = 0x1;
                            edi[0xc] = 0x1;
                            edi[0x58] = 0x1;
                    }
            }
    }
    return eax;
}
