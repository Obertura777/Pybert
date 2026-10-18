// sub_487c7b @ 0x487c7b
// hopper name: sub_487c7b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487c7b() {
    decomp_var_1c = ebx;
    esp = esp - 0x8;
    sub_47aea2(arg_8);
    ebx = arg_0;
    if (ebx <= 0xff) {
            eax = var_18[0x32];
            eax = *(int16_t *)(eax + ebx * 0x2) & 0xffff;
            eax = eax & arg_4;
            if (var_C != 0x0) {
                    var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
            }
    }
    else {
            arg_0 = SAR(ebx, 0x8);
            eax = sub_487c37(arg_0 & 0xff, &var_18);
            esp = (esp - 0x8) + 0x8;
            if (eax != 0x0) {
                    var_8 = arg_0;
                    ecx = 0x2;
                    esp = (esp - 0x4) + 0x4;
            }
            else {
                    var_8 = ebx;
                    ecx = 0x1;
            }
            eax = sub_48ac1f(&var_18, 0x1, &var_8, ecx, &var_4, var_18[0x1], var_18[0x5], 0x1);
            esp = (esp - 0x20) + 0x20;
            if (eax == 0x0) {
                    if (var_C != eax) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
            }
            else {
                    eax = var_4 & 0xffff;
                    eax = eax & arg_4;
                    if (var_C != 0x0) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
            }
    }
    return eax;
}
