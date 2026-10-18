// exp_g_tsck_func_table @ 0x10009128
// hopper name: exp_g_tsck_func_table
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_g_tsck_func_table() {
    esp = esp + 0x1;
    bool_6 = true;
    if (!OVERFLOW(esp)) {
            *(int8_t *)esi = *(int8_t *)esi + HIBYTE(ebx) + CARRY(EFLAGS(cf));
            bool_4 = true;
            if (!OVERFLOW(*(int8_t *)esi)) {
                    *(int8_t *)eax = *(int8_t *)eax + HIBYTE(ebx) + CARRY(EFLAGS(cf));
                    bool_22 = true;
                    if (!OVERFLOW(*(int8_t *)eax)) {
                            *(int8_t *)edx = *(int8_t *)edx + HIBYTE(edx) + CARRY(EFLAGS(cf));
                            bool_2 = true;
                            if (!OVERFLOW(*(int8_t *)edx)) {
                                    *(int8_t *)(eax + esi * 0x2) = *(int8_t *)(eax + esi * 0x2) + HIBYTE(ecx) + CARRY(EFLAGS(cf));
                                    *(int8_t *)eax = *(int8_t *)eax + edx;
                                    bool_20 = true;
                                    if (!OVERFLOW(*(int8_t *)eax)) {
                                            *(int8_t *)eax = *(int8_t *)eax + HIBYTE(eax) + CARRY(EFLAGS(cf));
                                            bool_18 = true;
                                            if (!OVERFLOW(*(int8_t *)eax)) {
                                                    *(int8_t *)edx = *(int8_t *)edx + ebx + CARRY(EFLAGS(cf));
                                                    bool_16 = true;
                                                    if (!OVERFLOW(*(int8_t *)edx)) {
                                                            *(int8_t *)(eax + esi * 0x2) = *(int8_t *)(eax + esi * 0x2) + edx + CARRY(EFLAGS(cf));
                                                            *(int8_t *)eax = *(int8_t *)eax + edx;
                                                            bool_14 = true;
                                                            if (!OVERFLOW(*(int8_t *)eax)) {
                                                                    *(int8_t *)eax = *(int8_t *)eax + ecx + CARRY(EFLAGS(cf));
                                                                    bool_12 = true;
                                                                    if (!OVERFLOW(*(int8_t *)eax)) {
                                                                            *(int8_t *)edx = *(int8_t *)edx + eax + CARRY(EFLAGS(cf));
                                                                            bool_10 = true;
                                                                            bool_9 = true;
                                                                            bool_7 = true;
                                                                            if (!OVERFLOW(*(int8_t *)edx)) {
                                                                                    HIBYTE(eax) = HIBYTE(eax) + HIBYTE(ebx) + CARRY(EFLAGS(cf));
                                                                                    asm { outsd      dx, dword [esi] };
                                                                                    *(int8_t *)eax = *(int8_t *)eax + edx;
                                                                                    eax = eax * *(int8_t *)edi;
                                                                                    eax = eax + eax + CARRY(EFLAGS(cf));
                                                                                    asm { outsd      dx, dword [esi] };
                                                                                    *(int8_t *)eax = *(int8_t *)eax + edx;
                                                                                    eax = loc_10009164();
                                                                            }
                                                                            else {
                                                                                    eax = (null)();
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = (null)();
                                                                    }
                                                            }
                                                            else {
                                                                    eax = (null)();
                                                            }
                                                    }
                                                    else {
                                                            eax = (null)();
                                                    }
                                            }
                                            else {
                                                    eax = (null)();
                                            }
                                    }
                                    else {
                                            eax = (null)();
                                    }
                            }
                            else {
                                    eax = (null)();
                            }
                    }
                    else {
                            eax = (null)();
                    }
            }
            else {
                    eax = (null)();
            }
    }
    else {
            eax = (null)();
    }
    return eax;
}
