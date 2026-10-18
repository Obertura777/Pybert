// sub_40bba0 @ 0x40bba0
// hopper name: sub_40bba0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40bba0() {
    decomp_var_c = *0x0;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    esp = esp - 0x1c;
    decomp_var_1c = *dword_4c8db8 ^ &decomp_var_18;
    *0x0 = &decomp_var_c;
    edi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            *edi = (*(*eax + 0xc))() + 0x10;
            edx = arg_0;
            if (edx != 0x0) {
                    if ((edx & 0xffff0000) == 0x0) {
                            esi = edx & 0xffff;
                            esp = esp - 0x4;
                            decomp_var_20 = esi;
                            eax = sub_4701df();
                            if (eax != 0x0) {
                                    decomp_var_20 = esi;
                                    esp = esp - 0x8;
                                    decomp_var_24 = eax;
                                    sub_40b990();
                            }
                    }
                    else {
                            eax = edx;
                            esi = eax + 0x1;
                            do {
                                    ecx = *(int8_t *)eax;
                                    eax = eax + 0x1;
                            } while (ecx != 0x0);
                            eax = eax - esi;
                            decomp_var_20 = eax;
                            esp = esp - 0x8;
                            decomp_var_24 = edx;
                            sub_40ba60();
                    }
            }
            else {
                    decomp_var_20 = 0x0;
                    esp = esp - 0x8;
                    decomp_var_24 = edx;
                    sub_40ba60();
            }
            eax = edi;
            *0x0 = decomp_var_14;
    }
    return eax;
}
