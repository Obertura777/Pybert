// sub_40bfa0 @ 0x40bfa0
// hopper name: sub_40bfa0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bfa0() {
    decomp_var_4 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    eax = (*(**esi + 0x10))(edi, decomp_var_4);
    ecx = esi + 0xc;
    if (esi[0x3] >= 0x0) {
            if (eax == *esi) {
                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                    eax = esi;
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            eax = sub_40b6d0();
                    }
                    else {
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            eax = edi;
                    }
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    eax = sub_40b6d0();
            }
            else {
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                    eax = edi;
            }
    }
    return eax;
}
