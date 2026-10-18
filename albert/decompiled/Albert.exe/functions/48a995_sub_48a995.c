// sub_48a995 @ 0x48a995
// hopper name: sub_48a995
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48a995() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    decomp_var_c = edi;
    var_20 = *0x0;
    esp = esp - 0x24;
    *0x0 = &var_20;
    while (true) {
            eax = arg_0;
            ebx = eax[0x2];
            esi = eax[0x3];
            if (esi == 0xffffffff) {
                    break;
            }
            if (arg_4 == 0xffffffff) {
                    esi = esi + esi * 0x2;
                    eax[0x3] = *(ebx + esi * 0x4);
                    if (*(ebx + esi * 0x4 + 0x4) == 0x0) {
                            esp = esp - 0x4;
                            sub_48aa45(0x101);
                            sub_48aa64();
                    }
                    continue;
            }
            if (esi <= arg_4) {
                    break;
            }
            esi = esi + esi * 0x2;
            eax[0x3] = *(ebx + esi * 0x4);
            if (*(ebx + esi * 0x4 + 0x4) == 0x0) {
                    esp = esp - 0x4;
                    sub_48aa45(0x101);
                    sub_48aa64();
            }
    }
    *0x0 = var_20;
    return eax;
}
