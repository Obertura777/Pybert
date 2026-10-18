// PostProcessOrders @ 0x411120
// hopper name: sub_411120
// pybert name: PostProcessOrders
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

PostProcessOrders() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    ebx = ecx;
    eax = ebx[0x2];
    decomp_var_14 = esi;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    if (eax[0x901] > 0x0) {
            edi = 0x0;
            do {
                    eax = eax[0x900];
                    esi = 0x0;
                    if (eax > 0x0) {
                            &decomp_var_18 = &decomp_var_18;
                            do {
                                    edx = 0x0;
                                    if (eax > 0x0) {
                                            eax = (edi + esi << 0xa) + 0x635578;
                                            do {
                                                    ecx = *eax;
                                                    if (ecx >= 0x3) {
                                                            *eax = ecx - 0x3;
                                                    }
                                                    else {
                                                            *eax = 0x0;
                                                    }
                                                    edx = edx + 0x1;
                                                    eax = eax + 0x4;
                                            } while (edx < *(ebx[0x2] + 0x2400));
                                    }
                                    eax = *(ebx[0x2] + 0x2400);
                                    esi = esi + 0x1;
                            } while (esi < eax);
                    }
                    eax = ebx[0x2];
                    edi = edi + 0x100;
            } while (&arg_fffffffffffffffd < eax[0x901]);
    }
    edi = ebx[0x2];
    esi = *edi[0x924];
    edi = edi + 0x248c;
    decomp_var_8 = edi;
    decomp_var_4 = esi;
    goto loc_4111d0;

loc_4111d0:
    eax = ebx[0x2];
    ebp = eax[0x924];
    eax = eax + 0x248c;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x6a] == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                    }
                            }
                            if (*((((esi[0x6] << 0x8) + esi[0x4] << 0x8) + esi[0x9]) * 0x4 + 0x635578) <= 0xc8) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                            }
                                    }
                                    eax = esi[0x6];
                                    eax = (eax << 0x8) + esi[0x4];
                                    eax = (eax << 0x8) + esi[0x9];
                                    *(eax * 0x4 + 0x635578) = *(eax * 0x4 + 0x635578) + 0xa;
                            }
                    }
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6b] == 0x1) {
                    if (*(ebx[0x2] + 0x2400) > 0x0) {
                            sub_4112c0();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x6a] == 0x1) {
                            ebp = 0x0;
                            if (*(ebx[0x2] + 0x2400) > 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                    }
                                    *((((esi[0x6] << 0x8) + esi[0x4] << 0x8) + ebp) * 0x4 + 0x635578) = 0x0;
                                    ebp = &arg_fffffffffffffffd;
                                    if (ebp < *(ebx[0x2] + 0x2400)) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    sub_401390();
                    esi = decomp_var_4;
                    edi = decomp_var_8;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6a] != 0x1) {
                    sub_401390();
                    esi = decomp_var_4;
                    edi = decomp_var_8;
                    continue;
            }
            ebp = 0x0;
            if (*(ebx[0x2] + 0x2400) > 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    *((((esi[0x6] << 0x8) + esi[0x4] << 0x8) + ebp) * 0x4 + 0x635578) = 0x0;
                    ebp = &arg_fffffffffffffffd;
                    if (ebp < *(ebx[0x2] + 0x2400)) {
                            continue;
                    }
                    break;
            }
            sub_401390();
            esi = decomp_var_4;
            edi = decomp_var_8;
            continue;
    }
    break;
    return;
}
