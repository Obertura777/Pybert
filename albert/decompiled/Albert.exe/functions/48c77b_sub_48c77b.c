// sub_48c77b @ 0x48c77b
// hopper name: sub_48c77b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c77b() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_2c = ebx;
    decomp_var_30 = esi;
    decomp_var_34 = edi;
    sub_47aea2(arg_8);
    eax = sub_4909a9(&var_10, &var_28, arg_4, 0x0, 0x0, 0x0, 0x0, &var_24);
    var_14 = eax;
    eax = sub_490467(&var_10, arg_0);
    esp = (esp - 0x38) + 0x28;
    if ((var_14 & 0x3) == 0x0) {
            if (eax == 0x1) {
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    esp = esp - 0x4;
                    decomp_var_38 = 0x3;
                    esp = esp + 0x4;
            }
            else {
                    if (eax == 0x2) {
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            esp = esp - 0x4;
                            decomp_var_38 = 0x4;
                            esp = esp + 0x4;
                    }
                    else {
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                    }
            }
            eax = sub_47ad69();
    }
    else {
            if ((var_14 & 0x1) == 0x0) {
                    if ((var_14 & 0x2) == 0x0) {
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                    }
                    else {
                            if (var_18 != 0x0) {
                                    var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                            }
                            esp = esp - 0x4;
                            decomp_var_38 = 0x3;
                            esp = esp + 0x4;
                    }
                    eax = sub_47ad69();
            }
            else {
                    if (var_18 != 0x0) {
                            var_1C[0x1c] = var_1C[0x1c] & 0xfffffffd;
                    }
                    esp = esp - 0x4;
                    decomp_var_38 = 0x4;
                    esp = esp + 0x4;
                    eax = sub_47ad69();
            }
    }
    return eax;
}
