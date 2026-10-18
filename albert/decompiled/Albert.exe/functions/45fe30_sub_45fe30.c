// sub_45fe30 @ 0x45fe30
// hopper name: sub_45fe30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45fe30() {
    decomp_var_8 = 0x498f98;
    var_C = *0x0;
    esp = esp - 0x1c;
    *0x0 = &var_C;
    esi = arg_0;
    var_4 = 0x0;
    esi[0x54] = 0x0;
    esi[0x55] = 0x0;
    esi[0x56] = 0x0;
    esi[0x57] = 0x0;
    esi[0x58] = 0x0;
    esi[0x59] = 0x0;
    esi[0x5a] = 0x0;
    esi[0x5b] = 0x0;
    esi[0x5c] = 0x0;
    edi = 0x0;
    if (sub_4658d0() <= 0x0) goto loc_45ff4b;
    goto loc_45fe8b;

loc_45ff4b:
    eax = sub_465fa0();
    *0x0 = arg_4;
    return eax;

loc_45fe8b:
    goto loc_45fe90;

loc_45fe90:
    esp = esp - 0x8;
    eax = sub_465900(&arg_0, edi);
    eax = *(int16_t *)eax;
    if (HIBYTE(eax) == 0x44) {
            esi[0x5c] = 0x1;
            esi[0x2f] = eax;
    }
    else {
            if (*(int16_t *)word_4c76f0 == eax) {
                    eax = esi[0x4];
                    switch (eax) {
                        case 2:
                            esi[0x5b] = 0x1;
                            break;
                        case 6:
                            esi[0x5b] = 0x1;
                            break;
                        default:
                            if (eax == 0x7) {
                                    esi[0x5b] = 0x1;
                            }
                            break;
                    }
            }
            else {
                    if (*(int16_t *)word_4c76f4 == eax) {
                            esi[0x59] = 0x1;
                    }
                    else {
                            if (*(int16_t *)word_4c76f8 == eax) {
                                    esi[0x58] = 0x1;
                            }
                            else {
                                    if (*(int16_t *)word_4c76fc == eax) {
                                            esi[0x56] = 0x1;
                                    }
                                    else {
                                            if (*(int16_t *)word_4c7704 == eax) {
                                                    eax = esi[0x4];
                                                    if (eax != 0x3 && eax != 0x4) {
                                                            if (eax == 0x5) {
                                                                    esi[0x55] = 0x1;
                                                            }
                                                            else {
                                                                    if (eax == 0x6) {
                                                                            esi[0x54] = 0x1;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi[0x57] = 0x1;
                                                    }
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c7708 == eax) {
                                                            esi[0x5a] = 0x1;
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    edi = edi + 0x1;
    if (edi < sub_4658d0()) {
            continue;
    }
    break;
}
