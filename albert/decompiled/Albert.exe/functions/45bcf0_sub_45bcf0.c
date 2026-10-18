// sub_45bcf0 @ 0x45bcf0
// hopper name: sub_45bcf0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bcf0() {
    eax = ecx[0x1];
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = eax[0x1];
    var_4 = eax;
    if (esi[0x2d] == 0x0) {
            eax = arg_0;
            ecx = eax[0x6];
            ebx = eax[0x5];
            esp = esp - 0xc;
            arg_0 = ecx;
            ebp = eax + 0x4;
            while (true) {
                    if (arg_0 >= 0x10) {
                            edx = *ebp;
                    }
                    else {
                            edx = ebp;
                    }
                    edi = esi[0x8];
                    if (edi >= edi) {
                            eax = (null)();
                            temp_0 = 0x0;
                            break;
                    }
                    ecx = edi;
                    if (edi >= ebx) {
                            ecx = ebx;
                    }
                    if (esi[0x9] >= 0x10) {
                            eax = esi[0x4];
                    }
                    else {
                            eax = esi + 0x10;
                    }
                    eax = sub_40cd30(eax, edx, ecx);
                    esp = (esp - 0xc) + 0xc;
                    bool_2 = eax >= 0x0;
                    if (eax == 0x0) {
                            if (edi >= ebx) {
                                    bool_8 = edi >= ebx;
                                    if (!bool_8) {
                                            esi = esi[0x2];
                                    }
                                    else {
                                            arg_0 = esi;
                                            esi = *esi;
                                    }
                            }
                            else {
                                    esi = esi[0x2];
                            }
                    }
                    else {
                            if (!bool_2) {
                                    esi = esi[0x2];
                            }
                            else {
                                    arg_0 = esi;
                                    esi = *esi;
                            }
                    }
                    if (esi[0x2d] == 0x0) {
                            continue;
                    }
                    eax = arg_4;
                    esp = esp + 0xc;
                    temp_0 = 0x1;
                    break;
            }
    }
    return eax;
}
