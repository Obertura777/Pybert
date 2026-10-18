// sub_47d1ba @ 0x47d1ba
// hopper name: sub_47d1ba
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d1ba() {
    decomp_var_1c = ebx;
    esp = esp - 0x8;
    sub_47aea2(arg_4);
    ebx = arg_0;
    if (ebx < 0x100) {
            ecx = var_18;
            if (ecx[0x2b] > 0x1) {
                    eax = sub_487c7b(ebx, 0x2, &var_18);
                    ecx = var_18;
                    esp = (esp - 0xc) + 0xc;
            }
            else {
                    eax = ecx[0x32];
                    eax = *(int8_t *)(eax + ebx * 0x2) & 0xff;
                    eax = eax & 0x2;
            }
            if (eax != 0x0) {
                    eax = ecx[0x34];
                    eax = *(int8_t *)(eax + ebx) & 0xff;
                    if (var_C != 0x0) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
            }
            else {
                    if (var_C != 0x0) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
                    eax = ebx;
            }
    }
    else {
            if (var_18[0x2b] > 0x1) {
                    arg_0 = SAR(ebx, 0x8);
                    eax = sub_487c37(arg_0 & 0xff, &var_18);
                    esp = (esp - 0x8) + 0x8;
                    if (eax != 0x0) {
                            var_4 = arg_0;
                            ecx = 0x2;
                            esp = (esp - 0x4) + 0x4;
                    }
                    else {
                            *sub_47d812() = 0x2a;
                            var_4 = ebx;
                            ecx = 0x1;
                    }
            }
            else {
                    *sub_47d812() = 0x2a;
                    var_4 = ebx;
                    ecx = 0x1;
            }
            eax = sub_482d50(&var_18, var_18[0x5], 0x200, &var_4, ecx, &var_8, 0x3, var_18[0x1], 0x1);
            esp = (esp - 0x24) + 0x24;
            if (eax != 0x0) {
                    if (eax == 0x1) {
                            eax = var_8 & 0xff;
                    }
                    else {
                            HIBYTE(eax) = var_8;
                            eax = eax | var_7 & 0xff;
                    }
                    if (var_C != 0x0) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
            }
            else {
                    if (var_C != 0x0) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
                    eax = ebx;
            }
    }
    return eax;
}
