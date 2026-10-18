// sub_47875e @ 0x47875e
// hopper name: sub_47875e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47875e() {
    esi = ecx;
    esp = esp - 0x4;
    if ((esi[0x18] & 0x1) == 0x0) {
            sub_478ca7();
    }
    edx = esi[0xa];
    ebx = esi + 0x2c;
    ecx = *ebx;
    edi = ecx - edx;
    decomp_var_8 = arg_4 + edi;
    if (esi[0x2] == 0x0) {
            eax = esi[0xc];
            if (edx > eax) {
                    if (edi > 0x0) {
                            sub_478599(eax, ecx - eax, edx, edi);
                            eax = esi[0xc];
                            esp = (esp - 0x10) + 0x10;
                            esi[0xa] = eax;
                            *ebx = eax + edi;
                    }
                    ecx = arg_4;
                    decomp_var_4 = edi;
                    if (esi[0x3] == 0x0) {
                            ecx = esi[0x8];
                    }
                    arg_4 = ecx - edi;
                    edi = edi + eax;
                    while (true) {
                            eax = *esi[0x9];
                            esp = esp - 0x8;
                            eax = (eax[0xd])(edi, arg_4);
                            decomp_var_4 = decomp_var_4 + eax;
                            arg_4 = arg_4 - eax;
                            edi = edi + eax;
                            if (eax <= 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (arg_4 <= 0x0) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (decomp_var_4 < decomp_var_8) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    eax = esi[0xc];
                    esi[0xa] = eax;
                    *ebx = eax + decomp_var_4;
            }
    }
    else {
            if (edi != 0x0) {
                    esp = esp - 0xc;
                    (*(*esi[0x9] + 0x28))(-edi, -edi & 0x80000000 ? 0xffffffff : 0x0, 0x1);
            }
            esp = esp - 0x10;
            (*(*esi[0x9] + 0x50))(0x0, esi[0x8], esi + 0x30, ebx);
            esi[0xa] = esi[0xc];
    }
    esp = esp + 0xc;
    if (*ebx - esi[0xa] < decomp_var_8) {
            sub_478ca7();
    }
    return;
}
