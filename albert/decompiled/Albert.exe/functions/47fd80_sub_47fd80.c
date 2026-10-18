// sub_47fd80 @ 0x47fd80
// hopper name: sub_47fd80
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47fd80() {
    edx = arg_0;
    ecx = arg_4;
    if ((edx & 0x3) == 0x0) {
            while (true) {
                    eax = *edx;
                    if (eax != *(int8_t *)ecx) {
                            temp_0 = 0x2;
                            break;
                    }
                    eax = eax | eax;
                    bool_29 = true;
                    bool_28 = true;
                    bool_27 = true;
                    if (eax == 0x0) {
                            temp_0 = 0x5;
                            break;
                    }
                    if (HIBYTE(eax) != ecx[0x1]) {
                            temp_0 = 0x2;
                            break;
                    }
                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                    if (HIBYTE(eax) == 0x0) {
                            temp_0 = 0x5;
                            break;
                    }
                    eax = eax >> 0x10;
                    if (eax != ecx[0x2]) {
                            temp_0 = 0x3;
                            break;
                    }
                    eax = eax | eax;
                    if (eax == 0x0) {
                            temp_0 = 0x0;
                            break;
                    }
                    if (HIBYTE(eax) != ecx[0x3]) {
                            temp_0 = 0x4;
                            break;
                    }
                    ecx = ecx + 0x4;
                    edx = edx + 0x4;
                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                    if (HIBYTE(eax) != 0x0) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
            switch (temp_0) {
                case 0:
                    eax = 0x0;
                    break;
                case 1:
                    eax = 0x0;
                    break;
                case 2:
                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                    break;
                case 3:
                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                    break;
                case 4:
                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                    break;
                default:
                    eax = 0x0;
                    break;
            }
    }
    else {
            if ((edx & 0x1) != 0x0) {
                    eax = *(int8_t *)edx;
                    edx = edx + 0x1;
                    bool_17 = true;
                    if (eax == *(int8_t *)ecx) {
                            ecx = ecx + 0x1;
                            if ((eax | eax) != 0x0) {
                                    if ((edx & 0x2) != 0x0) {
                                            eax = *(int16_t *)edx;
                                            edx = edx + 0x2;
                                            bool_20 = true;
                                            if (eax == *(int8_t *)ecx) {
                                                    eax = eax | eax;
                                                    if (eax != 0x0) {
                                                            bool_19 = true;
                                                            if (HIBYTE(eax) == ecx[0x1]) {
                                                                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                                    if (HIBYTE(eax) != 0x0) {
                                                                            ecx = ecx + 0x2;
                                                                            while (true) {
                                                                                    eax = *edx;
                                                                                    bool_23 = true;
                                                                                    bool_22 = true;
                                                                                    bool_21 = true;
                                                                                    if (eax != *(int8_t *)ecx) {
                                                                                            temp_0 = 0x2;
                                                                                            break;
                                                                                    }
                                                                                    eax = eax | eax;
                                                                                    if (eax == 0x0) {
                                                                                            temp_0 = 0x5;
                                                                                            break;
                                                                                    }
                                                                                    if (HIBYTE(eax) != ecx[0x1]) {
                                                                                            temp_0 = 0x2;
                                                                                            break;
                                                                                    }
                                                                                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                                                    if (HIBYTE(eax) == 0x0) {
                                                                                            temp_0 = 0x5;
                                                                                            break;
                                                                                    }
                                                                                    eax = eax >> 0x10;
                                                                                    if (eax != ecx[0x2]) {
                                                                                            temp_0 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    eax = eax | eax;
                                                                                    if (eax == 0x0) {
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    if (HIBYTE(eax) != ecx[0x3]) {
                                                                                            temp_0 = 0x4;
                                                                                            break;
                                                                                    }
                                                                                    ecx = ecx + 0x4;
                                                                                    edx = edx + 0x4;
                                                                                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                                                    if (HIBYTE(eax) != 0x0) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            switch (temp_0) {
                                                                                case 0:
                                                                                    eax = 0x0;
                                                                                    break;
                                                                                case 1:
                                                                                    eax = 0x0;
                                                                                    break;
                                                                                case 2:
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                                                    break;
                                                                                case 3:
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                                                    break;
                                                                                case 4:
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                                                    break;
                                                                                default:
                                                                                    eax = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                            }
                                    }
                                    else {
                                            while (true) {
                                                    eax = *edx;
                                                    if (eax != *(int8_t *)ecx) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    eax = eax | eax;
                                                    if (eax == 0x0) {
                                                            temp_0 = 0x5;
                                                            break;
                                                    }
                                                    if (HIBYTE(eax) != ecx[0x1]) {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                    if (HIBYTE(eax) == 0x0) {
                                                            temp_0 = 0x5;
                                                            break;
                                                    }
                                                    eax = eax >> 0x10;
                                                    if (eax != ecx[0x2]) {
                                                            temp_0 = 0x3;
                                                            break;
                                                    }
                                                    eax = eax | eax;
                                                    if (eax == 0x0) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    bool_18 = true;
                                                    bool_16 = true;
                                                    bool_15 = true;
                                                    if (HIBYTE(eax) != ecx[0x3]) {
                                                            temp_0 = 0x4;
                                                            break;
                                                    }
                                                    ecx = ecx + 0x4;
                                                    edx = edx + 0x4;
                                                    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                    if (HIBYTE(eax) != 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            switch (temp_0) {
                                                case 0:
                                                    eax = 0x0;
                                                    break;
                                                case 1:
                                                    eax = 0x0;
                                                    break;
                                                case 2:
                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                    break;
                                                case 3:
                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                    break;
                                                case 4:
                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                    break;
                                                default:
                                                    eax = 0x0;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                    }
            }
            else {
                    eax = *(int16_t *)edx;
                    edx = edx + 0x2;
                    bool_7 = true;
                    if (eax == *(int8_t *)ecx) {
                            eax = eax | eax;
                            if (eax != 0x0) {
                                    bool_6 = true;
                                    if (HIBYTE(eax) == ecx[0x1]) {
                                            HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                            if (HIBYTE(eax) != 0x0) {
                                                    ecx = ecx + 0x2;
                                                    while (true) {
                                                            eax = *edx;
                                                            bool_26 = true;
                                                            bool_25 = true;
                                                            bool_24 = true;
                                                            if (eax != *(int8_t *)ecx) {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            eax = eax | eax;
                                                            if (eax == 0x0) {
                                                                    temp_0 = 0x5;
                                                                    break;
                                                            }
                                                            if (HIBYTE(eax) != ecx[0x1]) {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                            if (HIBYTE(eax) == 0x0) {
                                                                    temp_0 = 0x5;
                                                                    break;
                                                            }
                                                            eax = eax >> 0x10;
                                                            if (eax != ecx[0x2]) {
                                                                    temp_0 = 0x3;
                                                                    break;
                                                            }
                                                            eax = eax | eax;
                                                            if (eax == 0x0) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            if (HIBYTE(eax) != ecx[0x3]) {
                                                                    temp_0 = 0x4;
                                                                    break;
                                                            }
                                                            ecx = ecx + 0x4;
                                                            edx = edx + 0x4;
                                                            HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
                                                            if (HIBYTE(eax) != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    switch (temp_0) {
                                                        case 0:
                                                            eax = 0x0;
                                                            break;
                                                        case 1:
                                                            eax = 0x0;
                                                            break;
                                                        case 2:
                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                            break;
                                                        case 3:
                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                            break;
                                                        case 4:
                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                                            break;
                                                        default:
                                                            eax = 0x0;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = (eax - eax + CARRY(EFLAGS(cf)) << 0x1) + 0x1;
                    }
            }
    }
    return eax;
}
