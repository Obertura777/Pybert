// sub_47d630 @ 0x47d630
// hopper name: sub_47d630
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d630() {
    ecx = arg_0;
    if ((ecx & 0x3) != 0x0) {
            while (true) {
                    eax = *(int8_t *)ecx;
                    ecx = ecx + 0x1;
                    if (eax == 0x0) {
                            temp_1 = 0x1;
                            break;
                    }
                    if ((ecx & 0x3) != 0x0) {
                            continue;
                    }
                    &saved_fp = &saved_fp;
                    &saved_fp = &saved_fp;
                    eax = *ecx;
                    ecx = ecx + 0x4;
                    if (((eax ^ 0xffffffff ^ 0x7efefeff + eax) & 0x81010100) != 0x0) {
                            eax = *(ecx - 0x4);
                            if (eax != 0x0) {
                                    if (HIBYTE(eax) != 0x0) {
                                            if ((eax & 0xff0000) != 0x0) {
                                                    if ((eax & 0xff000000) != 0x0) {
                                                            temp_1 = 0x0;
                                                    }
                                                    else {
                                                            temp_1 = 0x1;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x2;
                                            }
                                    }
                                    else {
                                            temp_1 = 0x3;
                                    }
                            }
                            else {
                                    temp_1 = 0x4;
                            }
                    }
                    else {
                            temp_1 = 0x0;
                    }
                    break;
            }
            if (temp_1 != 0x0) {
                    switch (temp_1) {
                        case 1:
                            eax = ecx - 0x1 - arg_0;
                            break;
                        case 2:
                            eax = ecx - 0x2 - arg_0;
                            break;
                        case 3:
                            eax = ecx - 0x3 - arg_0;
                            break;
                        default:
                            eax = ecx - 0x4 - arg_0;
                            break;
                    }
            }
            else {
                    while (true) {
                            eax = *ecx;
                            ecx = ecx + 0x4;
                            if (((eax ^ 0xffffffff ^ 0x7efefeff + eax) & 0x81010100) == 0x0) {
                                    continue;
                            }
                            eax = *(ecx - 0x4);
                            if (eax == 0x0) {
                                    temp_0 = 0x3;
                                    break;
                            }
                            if (HIBYTE(eax) == 0x0) {
                                    temp_0 = 0x2;
                                    break;
                            }
                            if ((eax & 0xff0000) == 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            if ((eax & 0xff000000) != 0x0) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    switch (temp_0) {
                        case 0:
                            eax = ecx - 0x1 - arg_0;
                            break;
                        case 1:
                            eax = ecx - 0x2 - arg_0;
                            break;
                        case 2:
                            eax = ecx - 0x3 - arg_0;
                            break;
                        default:
                            eax = ecx - 0x4 - arg_0;
                            break;
                    }
            }
    }
    else {
            while (true) {
                    eax = *ecx;
                    ecx = ecx + 0x4;
                    if (((eax ^ 0xffffffff ^ 0x7efefeff + eax) & 0x81010100) == 0x0) {
                            continue;
                    }
                    eax = *(ecx - 0x4);
                    if (eax == 0x0) {
                            temp_0 = 0x3;
                            break;
                    }
                    if (HIBYTE(eax) == 0x0) {
                            temp_0 = 0x2;
                            break;
                    }
                    if ((eax & 0xff0000) == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    if ((eax & 0xff000000) != 0x0) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            switch (temp_0) {
                case 0:
                    eax = ecx - 0x1 - arg_0;
                    break;
                case 1:
                    eax = ecx - 0x2 - arg_0;
                    break;
                case 2:
                    eax = ecx - 0x3 - arg_0;
                    break;
                default:
                    eax = ecx - 0x4 - arg_0;
                    break;
            }
    }
    return eax;
}
