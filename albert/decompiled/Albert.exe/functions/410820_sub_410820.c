// sub_410820 @ 0x410820
// hopper name: sub_410820
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_410820() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = ecx;
    if (ebx == 0x0) {
            sub_40b5a0(0x80070057);
    }
    else {
            decomp_var_c = ebp;
            ebp = arg_4;
            decomp_var_10 = esi;
            esi = sub_47b7b0(ebx, ebp);
            eax = *edi;
            esp = (esp - 0x10) + 0x8;
            if ((0x1 - *((eax - 0x10) + 0xc) | *(eax - 0x8) - esi) < 0x0) {
                    esp = esp - 0x4;
                    sub_40b860(esi, decomp_var_10);
            }
            sub_47b918(*edi, esi + 0x1, ebx, ebp);
            esp = (esp - 0x10) + 0x10;
            if (esi >= 0x0) {
                    eax = *edi;
                    if (esi <= *(eax - 0x8)) {
                            *(eax - 0xc) = esi;
                            *(int8_t *)(esi + *edi) = 0x0;
                    }
                    else {
                            sub_40b5a0(0x80070057);
                    }
            }
            else {
                    sub_40b5a0(0x80070057);
            }
    }
    return;
}
