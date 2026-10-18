// sub_40bf30 @ 0x40bf30
// hopper name: sub_40bf30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bf30() {
    esp = esp - 0x4;
    decomp_var_4 = edi;
    edi = ecx;
    ecx = arg_8;
    if (ecx == 0x0) {
            sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_8 = ebx;
            ebx = arg_0;
            esp = esp - 0x8;
            decomp_var_c = esi;
            esi = arg_4;
            if (ebx == 0x0) {
                    if (esi != 0x0) {
                            sub_40b5a0(0x80070057);
                    }
                    else {
                            esp = esp - 0x8;
                            eax = (**ecx)(esi, 0x1);
                            if (eax == 0x0) {
                                    eax = sub_40b6d0();
                            }
                            eax = eax + 0x10;
                            *edi = eax;
                            if (esi >= 0x0) {
                                    if (esi <= *(eax - 0x8)) {
                                            *(eax - 0xc) = esi;
                                            *(int8_t *)(esi + *edi) = 0x0;
                                            sub_47a5af(*edi, esi, ebx, esi);
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
            else {
                    esp = esp - 0x8;
                    eax = (**ecx)(esi, 0x1);
                    if (eax == 0x0) {
                            eax = sub_40b6d0();
                    }
                    eax = eax + 0x10;
                    *edi = eax;
                    if (esi >= 0x0) {
                            if (esi <= *(eax - 0x8)) {
                                    *(eax - 0xc) = esi;
                                    *(int8_t *)(esi + *edi) = 0x0;
                                    sub_47a5af(*edi, esi, ebx, esi);
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
