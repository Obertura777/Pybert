// sub_48900d @ 0x48900d
// hopper name: sub_48900d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48900d() {
    decomp_var_10 = ebx;
    decomp_var_14 = esi;
    esp = esp - 0xc;
    decomp_var_18 = edi;
    if (*dword_bc837c == 0x0) {
            sub_481a14();
    }
    esp = esp - 0xc;
    *(int8_t *)byte_bc6e1c = 0x0;
    GetModuleFileNameA(0x0, 0xbc6d18, 0x104);
    eax = *dword_bc8384;
    *dword_bc64ec = 0xbc6d18;
    if (eax != 0x0) {
            eax = *dword_bc8384;
            var_4 = eax;
            if (*(int8_t *)eax == 0x0) {
                    var_4 = 0xbc6d18;
            }
    }
    else {
            var_4 = 0xbc6d18;
    }
    eax = sub_488e75(0x0, 0x0, &var_8);
    eax = var_8;
    esp = (esp - 0xc) + 0xc;
    if (eax < 0x3fffffff) {
            ecx = var_C;
            if (ecx < 0xffffffff) {
                    edi = eax << 0x2;
                    eax = edi + ecx;
                    if (eax >= ecx) {
                            eax = sub_481280(eax);
                            esi = eax;
                            esp = (esp - 0x4) + 0x4;
                            if (esi != 0x0) {
                                    sub_488e75(esi, edi + esi, &var_8);
                                    esp = (esp - 0xc) + 0xc;
                                    *dword_bc64d0 = var_8 - 0x1;
                                    *dword_bc64d4 = esi;
                                    eax = 0x0;
                            }
                            else {
                                    eax = eax | 0xffffffff;
                            }
                    }
                    else {
                            eax = eax | 0xffffffff;
                    }
            }
            else {
                    eax = eax | 0xffffffff;
            }
    }
    else {
            eax = eax | 0xffffffff;
    }
    return eax;
}
