// sub_40d1a0 @ 0x40d1a0
// hopper name: sub_40d1a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40d1a0() {
    var_C = *0x0;
    *0x0 = &var_C;
    ebp = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    *(int16_t *)arg_0 = 0x0;
    eax = sub_466060(&var_1C, 0x1);
    esp = esp - 0x44;
    sub_465ff0(eax);
    sub_465fa0();
    edi = sub_465930();
    esi = 0x0;
    if (edi > 0x0) {
            while (true) {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_1E, esi);
                    eax = *(int8_t *)eax & 0xff;
                    if (eax == ebp) {
                            esi = esi + 0x1;
                            if (esi < edi) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            ecx = arg_14 & 0xff;
                            if (edi == 0x2) {
                                    if (ecx[0x633768] != 0x1) {
                                            ebx = 0x1;
                                            if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                    if (*(eax * 0x8 + 0x4cf56c) != 0x0) {
                                                            esi = esi + 0x1;
                                                            if (esi < edi) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            esi = esi + ebx;
                                                            if (esi < edi) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esi = esi + ebx;
                                                    if (esi < edi) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            esi = esi + 0x1;
                                            if (esi < edi) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                            if (*(eax * 0x8 + 0x4cf56c) != 0x0) {
                                                    esi = esi + 0x1;
                                                    if (esi < edi) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    esi = esi + 0x1;
                                                    if (esi < edi) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            esi = esi + 0x1;
                                            if (esi < edi) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
            if (arg_3 == 0x1) {
                    ebx = 0x1;
                    if (arg_4 == 0x1) {
                            if (arg_5 == ebx) {
                                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d48;
                            }
                            else {
                                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d28;
                            }
                    }
                    else {
                            *(int16_t *)arg_28 = *(int16_t *)word_4c6d90;
                    }
            }
            else {
                    *(int16_t *)arg_28 = *(int16_t *)word_4c6d90;
            }
    }
    else {
            *(int16_t *)arg_28 = *(int16_t *)word_4c6d90;
    }
    sub_465fa0();
    sub_465fa0();
    eax = arg_50;
    *0x0 = arg_40;
    return eax;
}
