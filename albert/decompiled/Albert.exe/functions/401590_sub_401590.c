// sub_401590 @ 0x401590
// hopper name: sub_401590
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_401590() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (*esi == 0x0) {
            sub_47a948();
    }
    eax = esi[0x1];
    if (eax[0x1d] != 0x0) {
            eax = sub_47a948();
    }
    else {
            ecx = eax[0x2];
            if (ecx[0x1d] == 0x0) {
                    eax = *ecx;
                    if (eax[0x1d] == 0x0) {
                            do {
                                    ecx = eax;
                                    eax = *ecx;
                            } while (eax[0x1d] == 0x0);
                    }
                    esi[0x1] = ecx;
            }
            else {
                    eax = eax[0x1];
                    if (eax[0x1d] == 0x0) {
                            while (true) {
                                    if (esi[0x1] != eax[0x2]) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    esi[0x1] = eax;
                                    eax = eax[0x1];
                                    if (eax[0x1d] == 0x0) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
                    esi[0x1] = eax;
            }
    }
    return eax;
}
