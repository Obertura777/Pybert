// sub_492d50 @ 0x492d50
// hopper name: sub_492d50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492d50() {
    ecx = arg_8 | arg_8;
    if (ecx == 0x0) goto loc_492daa;
    goto loc_492d5d;

loc_492daa:
    eax = ecx;
    return eax;

loc_492d5d:
    esi = arg_0;
    edi = arg_4;
    goto loc_492d6c;

loc_492d6c:
    HIBYTE(eax) = *(int8_t *)esi;
    HIBYTE(eax) = HIBYTE(eax) | HIBYTE(eax);
    bool_12 = HIBYTE(eax) == 0x0;
    eax = *(int8_t *)edi;
    if (!bool_12) {
            eax = eax | eax;
            if (eax != 0x0) {
                    esi = esi + 0x1;
                    edi = edi + 0x1;
                    if (HIBYTE(eax) >= HIBYTE(0x5a) && HIBYTE(eax) <= 0x5a) {
                            HIBYTE(edx) = 0x20;
                            HIBYTE(eax) = HIBYTE(eax) + HIBYTE(edx);
                    }
                    if (eax >= HIBYTE(0x5a) && eax <= 0x5a) {
                            HIBYTE(edx) = 0x20;
                            eax = eax + HIBYTE(edx);
                    }
                    if (HIBYTE(eax) == eax) {
                            ecx = ecx - 0x1;
                            bool_3 = ecx < 0x0;
                            if (ecx != 0x0) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    else {
                            temp_0 = 0x2;
                            break;
                    }
            }
            else {
                    temp_0 = 0x0;
                    break;
            }
    }
    else {
            temp_0 = 0x1;
            break;
    }
    goto .l2;

.l2:
    switch (temp_0) {
        case 0:
            ecx = 0x0;
            bool_5 = HIBYTE(eax) < eax;
            if (HIBYTE(eax) != eax) {
                    ecx = 0xffffffff;
                    if (!bool_5) {
                            ecx = -0xffffffff;
                    }
            }
            break;
        case 1:
            ecx = 0x0;
            bool_2 = HIBYTE(eax) < eax;
            if (HIBYTE(eax) != eax) {
                    ecx = 0xffffffff;
                    if (!bool_2) {
                            ecx = -0xffffffff;
                    }
            }
            break;
        default:
            ecx = 0xffffffff;
            if (!bool_3) {
                    ecx = -0xffffffff;
            }
            break;
    }
    goto loc_492daa;
}
