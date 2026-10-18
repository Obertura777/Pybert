// sub_4772ee @ 0x4772ee
// hopper name: sub_4772ee
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4772ee() {
    esp = esp - 0x8;
    var_8 = ecx;
    edi = (*(*ecx + 0x38))(edi, esi, var_8);
    while (true) {
            eax = edi[0x1];
            while (*eax != 0x0) {
                    eax = eax + 0x8;
            }
            esi = eax + 0x4;
            while (true) {
                    if (*esi != 0xffffffff) {
                            eax = *esi;
                            eax = *(var_8 + eax);
                            if (eax == 0x0) {
                                    esi = esi + 0x8;
                                    continue;
                            }
                            var_4 = var_4 & 0x0;
                            esp = esp - 0xc;
                            eax = (**eax)(eax, arg_0, &var_4);
                            if (eax != 0x0) {
                                    esi = esi + 0x8;
                                    continue;
                            }
                            eax = var_4;
                            if (eax == 0x0) {
                                    esi = esi + 0x8;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    break;
            }
            edi = *edi;
            if (edi != 0x0) {
                    continue;
            }
            eax = 0x0;
            break;
    }
    return eax;
}
