// sub_48bbda @ 0x48bbda
// hopper name: sub_48bbda
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48bbda() {
    esp = esp - 0x4;
    decomp_var_4 = ebx;
    ebx = 0x0;
    eax = 0x1;
    if (arg_4 >= 0x0) {
            decomp_var_8 = esi;
            esp = esp - 0x8;
            decomp_var_c = edi;
            while (eax != 0x0) {
                    esi = SAR(arg_4 + ebx - (arg_4 + ebx & 0x80000000 ? 0xffffffff : 0x0), 0x1);
                    edi = arg_0 + esi * 0x8;
                    eax = sub_48fc86(*arg_8, *edi);
                    bool_5 = eax >= 0x0;
                    esp = (esp - 0x8) + 0x8;
                    if (eax == 0x0) {
                            *arg_8 = edi + 0x4;
                    }
                    else {
                            if (!bool_5) {
                                    arg_4 = esi - 0x1;
                            }
                            else {
                                    ebx = esi + 0x1;
                            }
                    }
                    if (ebx > arg_4) {
                            break;
                    }
            }
            esp = esp + 0x8;
    }
    eax = eax == 0x0 ? 0x1 : 0x0;
    return eax;
}
