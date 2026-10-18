// sub_40ba60 @ 0x40ba60
// hopper name: sub_40ba60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40ba60() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = arg_4;
    ebx = ecx;
    if (esi == 0x0) {
            sub_40b800();
    }
    else {
            ecx = arg_0;
            if (ecx == 0x0) {
                    sub_40b5a0(0x80070057);
            }
            else {
                    eax = *ebx;
                    decomp_var_c = ebp;
                    ebp = *(eax - 0xc);
                    esp = esp - 0x8;
                    decomp_var_10 = edi;
                    edi = ecx - eax;
                    if ((0x1 - *(eax - 0x4) | *(eax - 0x8) - esi) < 0x0) {
                            esp = esp - 0x4;
                            sub_40b860(esi, decomp_var_10);
                            ecx = arg_0;
                    }
                    eax = *ebx;
                    esp = esp - 0x4;
                    decomp_var_14 = esi;
                    if (edi <= ebp) {
                            esp = esp - 0xc;
                            sub_47a62a(eax, esi, eax + edi, decomp_var_14);
                    }
                    else {
                            esp = esp - 0xc;
                            sub_47a5af(eax, esi, ecx, decomp_var_14);
                    }
                    esp = esp + 0x18;
                    if (esi >= 0x0) {
                            eax = *ebx;
                            if (esi <= *(eax - 0x8)) {
                                    *(eax - 0xc) = esi;
                                    *(int8_t *)(esi + *ebx) = 0x0;
                            }
                            else {
                                    sub_40b5a0(0x80070057);
                            }
                    }
                    else {
                            sub_40b5a0(0x80070057);
                    }
            }
    }
    return;
}
