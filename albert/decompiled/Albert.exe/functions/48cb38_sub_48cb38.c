// sub_48cb38 @ 0x48cb38
// hopper name: sub_48cb38
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48cb38() {
    eax = arg_8 & 0xfff7ffff;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if ((arg_4 & eax & 0xfcf0fce0) != 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            edi = arg_0;
            if (edi != 0x0) {
                    esp = (esp - 0x8) + 0x8;
                    *edi = sub_491a63(0x0, 0x0);
            }
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = 0x16;
            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x18;
    }
    else {
            esi = arg_0;
            decomp_var_8 = eax;
            esp = esp - 0x8;
            decomp_var_c = arg_4;
            if (esi != 0x0) {
                    *esi = sub_491a63(decomp_var_c, decomp_var_8);
            }
            else {
                    sub_491a63(decomp_var_c, decomp_var_8);
            }
            esp = esp + 0x8;
            eax = 0x0;
    }
    return eax;
}
