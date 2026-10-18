// sub_40c200 @ 0x40c200
// hopper name: sub_40c200
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c200() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = ecx;
    eax = *edi;
    esi = *(eax - 0xc);
    if ((0x1 - *(eax - 0x4) | *(eax - 0x8) - esi) < 0x0) {
            esp = esp - 0x4;
            sub_40b860(esi, decomp_var_8);
    }
    sub_47b027(*edi, esi + 0x1);
    sub_40bd00();
    esp = (esp - 0xc) + 0xc;
    if (esi >= 0x0) {
            eax = *edi;
            if (esi <= *(eax - 0x8)) {
                    *(eax - 0xc) = esi;
                    eax = edi;
                    *(int8_t *)(esi + *edi) = 0x0;
            }
            else {
                    eax = sub_40b5a0(0x80070057);
            }
    }
    else {
            eax = sub_40b5a0(0x80070057);
    }
    return eax;
}
