// sub_40b760 @ 0x40b760
// hopper name: sub_40b760
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b760() {
    edx = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    eax = *esi;
    ecx = *(eax - 0x10);
    eax = eax - 0x10;
    if (eax[0x2] < edx) {
            if (edx > 0x0) {
                    decomp_var_14 = eax;
                    eax = *(*ecx + 0x8);
                    eax = (eax)(decomp_var_14, edx, 0x1, edi);
                    esp = (esp - 0x10) + 0x4;
                    if (eax == 0x0) {
                            eax = sub_40b6d0();
                    }
                    eax = eax + 0x10;
                    *esi = eax;
            }
            else {
                    eax = sub_40b6d0();
                    eax = eax + 0x10;
                    *esi = eax;
            }
    }
    else {
            eax = sub_40b6d0();
            eax = eax + 0x10;
            *esi = eax;
    }
    return eax;
}
