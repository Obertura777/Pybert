// sub_485b16 @ 0x485b16
// hopper name: sub_485b16
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_485b16() {
    if ((ecx[0xc] & 0x40) != 0x0) {
            if (ecx[0x2] != 0x0) {
                    ecx[0x1] = ecx[0x1] - 0x1;
                    if (ecx[0x1] >= 0x0) {
                            *(int8_t *)*ecx = eax;
                            *ecx = *ecx + 0x1;
                            eax = eax & 0xff;
                    }
                    else {
                            eax = sub_48501e(sign_extend_32(eax), ecx);
                    }
                    if (eax == 0xffffffff) {
                            *esi = *esi | eax;
                    }
                    else {
                            *esi = *esi + 0x1;
                    }
            }
            else {
                    *esi = *esi + 0x1;
            }
    }
    else {
            ecx[0x1] = ecx[0x1] - 0x1;
            if (ecx[0x1] >= 0x0) {
                    *(int8_t *)*ecx = eax;
                    *ecx = *ecx + 0x1;
                    eax = eax & 0xff;
            }
            else {
                    eax = sub_48501e(sign_extend_32(eax), ecx);
            }
            if (eax == 0xffffffff) {
                    *esi = *esi | eax;
            }
            else {
                    *esi = *esi + 0x1;
            }
    }
    return;
}
