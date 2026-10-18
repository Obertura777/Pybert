// sub_40c2e0 @ 0x40c2e0
// hopper name: sub_40c2e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c2e0() {
    decomp_var_8 = ebx;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = arg_4;
    ebx = ecx;
    decomp_var_4 = 0x0;
    if (edi < 0x0) {
            edi = 0x0;
    }
    esi = arg_8;
    if (esi < 0x0) {
            esi = 0x0;
    }
    if (0x7fffffff - edi >= esi) {
            ecx = *ebx;
            eax = *(ecx - 0xc);
            if (edi + esi > eax) {
                    esi = eax - edi;
            }
            if (edi > eax) {
                    esi = 0x0;
            }
            if (edi == 0x0) {
                    if (esi == eax) {
                            ecx = sub_40bfa0(ecx - 0x10);
                            eax = arg_0;
                            *eax = ecx + 0x10;
                    }
                    else {
                            ecx = *(ecx - 0x10);
                            if (ecx != 0x0) {
                                    eax = *(*ecx + 0x10);
                                    eax = (eax)();
                                    if (eax == 0x0) {
                                            eax = sub_47020b();
                                            eax = *(*eax + 0x10);
                                            eax = (eax)();
                                    }
                            }
                            else {
                                    eax = sub_47020b();
                                    eax = *(*eax + 0x10);
                                    eax = (eax)();
                            }
                            sub_40bf30();
                            eax = arg_0;
                    }
            }
            else {
                    ecx = *(ecx - 0x10);
                    if (ecx != 0x0) {
                            eax = *(*ecx + 0x10);
                            eax = (eax)();
                            if (eax == 0x0) {
                                    eax = sub_47020b();
                                    eax = *(*eax + 0x10);
                                    eax = (eax)();
                            }
                    }
                    else {
                            eax = sub_47020b();
                            eax = *(*eax + 0x10);
                            eax = (eax)();
                    }
                    sub_40bf30();
                    eax = arg_0;
            }
    }
    else {
            eax = sub_40b5a0(0x80070057);
    }
    return eax;
}
