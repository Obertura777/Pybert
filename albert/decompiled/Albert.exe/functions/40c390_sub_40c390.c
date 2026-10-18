// sub_40c390 @ 0x40c390
// hopper name: sub_40c390
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c390() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_8;
    esi = edi + arg_10;
    eax = *ebx;
    if ((0x1 - *((eax - 0x10) + 0xc) | *(eax - 0x8) - esi) < 0x0) {
            esp = esp - 0x4;
            sub_40b860(esi, decomp_var_c);
    }
    ebp = *ebx;
    sub_47a5af(ebp, edi, arg_4, edi);
    sub_47a5af(ebp + edi, arg_10, arg_c, arg_10);
    esp = (esp - 0x24) + 0x24;
    if (esi >= 0x0) {
            eax = *ebx;
            if (esi <= *(eax - 0x8)) {
                    *(eax - 0xc) = esi;
                    *(int8_t *)(esi + *ebx) = 0x0;
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
