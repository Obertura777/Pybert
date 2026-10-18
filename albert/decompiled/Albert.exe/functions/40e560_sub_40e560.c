// sub_40e560 @ 0x40e560
// hopper name: sub_40e560
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40e560() {
    esp = esp - 0x4;
    var_4 = esi;
    esi = ecx;
    if (*esi == 0x0) {
            sub_47a948();
    }
    eax = esi[0x1];
    if (eax[0x29] != 0x0) {
            eax = eax[0x2];
            esi[0x1] = eax;
            if (eax[0x29] != 0x0) {
                    eax = sub_47a948();
            }
    }
    else {
            ecx = *eax;
            if (ecx[0x29] == 0x0) {
                    eax = ecx[0x2];
                    if (eax[0x29] == 0x0) {
                            &var_4 = &var_4;
                            do {
                                    ecx = eax;
                                    eax = ecx[0x2];
                            } while (eax[0x29] == 0x0);
                    }
                    esi[0x1] = ecx;
            }
            else {
                    eax = eax[0x1];
                    if (eax[0x29] == 0x0) {
                            &var_4 = &var_4;
                            while (true) {
                                    if (esi[0x1] != *eax) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    esi[0x1] = eax;
                                    eax = eax[0x1];
                                    if (eax[0x29] == 0x0) {
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                    }
                    if (*(int8_t *)(esi[0x1] + 0x29) != 0x0) {
                            eax = sub_47a948();
                    }
                    else {
                            esi[0x1] = eax;
                    }
            }
    }
    return eax;
}
