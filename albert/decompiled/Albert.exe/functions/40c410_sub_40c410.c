// sub_40c410 @ 0x40c410
// hopper name: sub_40c410
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c410() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = ecx;
    ecx = *arg_0;
    esi = *edi;
    eax = ecx - 0x10;
    esi = esi - 0x10;
    if (eax != esi) {
            esp = esp - 0x4;
            decomp_var_c = ebx;
            ebx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (*eax == *esi) {
                            decomp_var_10 = ebp;
                            esp = (esp - 0x8) + 0x4;
                            *ebx = lock intrinsic_xadd(*ebx, sub_40bfa0(eax) | 0xffffffff);
                            if (eax <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**esi + 0x4))(esi);
                            }
                            *edi = &arg_c;
                            eax = edi;
                    }
                    else {
                            sub_40ba60();
                            eax = edi;
                    }
            }
            else {
                    sub_40ba60();
                    eax = edi;
            }
    }
    else {
            eax = edi;
    }
    return eax;
}
