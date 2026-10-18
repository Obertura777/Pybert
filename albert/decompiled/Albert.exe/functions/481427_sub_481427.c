// sub_481427 @ 0x481427
// hopper name: sub_481427
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481427() {
    ebp = &var_4A0;
    arg_494 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x52c;
    eax = GetCPInfo(esi[0x1], &decomp_var_7c);
    if (eax != 0x0) {
            eax = 0x0;
            do {
                    *(int8_t *)(ebp + eax + 0x398) = eax;
                    eax = eax + 0x1;
            } while (eax < 0x100);
            eax = decomp_var_76;
            arg_394 = 0x20;
            if (eax != 0x0) {
                    ebx = &decomp_var_75;
                    do {
                            ecx = eax & 0xff;
                            eax = *(int8_t *)ebx & 0xff;
                            if (ecx <= eax) {
                                    sub_47ba40(ebp + ecx + 0x398, 0x20, (eax - ecx) + 0x1);
                                    esp = (esp - 0xc) + 0xc;
                            }
                            eax = ebx[0x1];
                            ebx = ebx + 0x2;
                    } while (eax != 0x0);
            }
            sub_48ac1f(0x0, 0x1, &arg_394, 0x100, &decomp_var_68, esi[0x1], esi[0x3], 0x0);
            sub_482d50(0x0, esi[0x3], 0x100, &arg_394, 0x100, &arg_294, 0x100, esi[0x1], 0x0);
            esp = (esp - 0x44) + 0x44 - 0x18;
            sub_482d50(0x0, esi[0x3], 0x200, &arg_394, 0x100, &arg_194, 0x100, esi[0x1], 0x0);
            esp = (esp - 0xc) + 0x24;
            eax = 0x0;
            do {
                    ecx = *(int16_t *)(ebp + (eax * 0x2 - 0x68)) & 0xffff;
                    if ((ecx & 0x1) != 0x0) {
                            *(int8_t *)(esi + eax + 0x1d) = *(int8_t *)(esi + eax + 0x1d) | 0x10;
                            ecx = *(int8_t *)(ebp + eax + 0x298);
                            *(int8_t *)(esi + eax + 0x11d) = ecx;
                    }
                    else {
                            if ((ecx & 0x2) != 0x0) {
                                    *(int8_t *)(esi + eax + 0x1d) = *(int8_t *)(esi + eax + 0x1d) | 0x20;
                                    ecx = *(int8_t *)(ebp + eax + 0x198);
                                    *(int8_t *)(esi + eax + 0x11d) = ecx;
                            }
                            else {
                                    *(int8_t *)(esi + eax + 0x11d) = 0x0;
                            }
                    }
                    eax = eax + 0x1;
            } while (eax < 0x100);
    }
    else {
            ecx = 0x0;
            decomp_var_80 = 0xffffff9f - esi + 0x11d;
            do {
                    eax = esi + ecx + 0x11d;
                    edx = decomp_var_80 + eax;
                    if (edx <= 0xfffffff9) {
                            *(int8_t *)(esi + ecx + 0x1d) = *(int8_t *)(esi + ecx + 0x1d) | 0x10;
                            edx = ecx + 0x20;
                            *(int8_t *)eax = edx;
                    }
                    else {
                            if (edx <= 0x19) {
                                    *(int8_t *)(esi + ecx + 0x1d) = *(int8_t *)(esi + ecx + 0x1d) | 0x20;
                                    edx = ecx - 0x20;
                                    *(int8_t *)eax = edx;
                            }
                            else {
                                    *(int8_t *)eax = 0x0;
                            }
                    }
                    ecx = ecx + 0x1;
            } while (ecx < 0x100);
    }
    eax = sub_47ad69();
    return eax;
}
