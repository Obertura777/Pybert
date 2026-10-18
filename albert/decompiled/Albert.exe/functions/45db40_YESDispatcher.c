// YESDispatcher @ 0x45db40
// hopper name: sub_45db40
// pybert name: YESDispatcher
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

YESDispatcher() {
    var_8 = 0x498be8;
    var_C = *0x0;
    decomp_var_30 = ebx;
    decomp_var_34 = esi;
    decomp_var_38 = edi;
    decomp_var_3c = *dword_4c8db8 ^ &decomp_var_38;
    *0x0 = &var_C;
    esi = ecx;
    edi = arg_0;
    eax = sub_466060(&var_2C, 0x1);
    esp = esp - 0x4c;
    eax = sub_465900(&arg_0, 0x0);
    if (*(int16_t *)word_4c70a0 != *(int16_t *)eax) {
            eax = sub_466060(&var_1C, 0x1);
            esp = esp - 0x10;
            (*(*esi + 0x98))(edi, eax);
            sub_465fa0();
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&arg_0, 0x0);
            if (*(int16_t *)word_4c70ac != *(int16_t *)eax) {
                    eax = sub_466060(&var_1C, 0x1);
                    esp = esp - 0x10;
                    (*(*esi + 0x9c))(edi, eax);
                    sub_465fa0();
            }
            else {
                    ebx = 0x0;
                    esp = esp - 0x8;
                    eax = sub_465900(&arg_0, 0x0);
                    if (*(int16_t *)word_4c708c != *(int16_t *)eax) {
                            eax = sub_466060(&var_1C, 0x1);
                            esp = esp - 0x10;
                            (*(*esi + 0xa0))(edi, eax);
                            sub_465fa0();
                    }
                    else {
                            esp = esp - 0x8;
                            eax = sub_465900(&arg_0, ebx);
                            if (*(int16_t *)word_4c70a4 != *(int16_t *)eax) {
                                    eax = sub_466060(&var_1C, 0x1);
                                    esp = esp - 0x10;
                                    sub_45b070(edi, eax, decomp_var_3c);
                                    sub_465fa0();
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&arg_0, ebx);
                                    if (*(int16_t *)word_4c707c != *(int16_t *)eax) {
                                            eax = sub_466060(&var_1C, 0x1);
                                            esp = esp - 0x10;
                                            (*(*esi + 0xa4))(edi, eax);
                                            sub_465fa0();
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&arg_0, ebx);
                                            if (*(int16_t *)word_4c70dc != *(int16_t *)eax) {
                                                    eax = sub_466060(&var_1C, 0x1);
                                                    esp = esp - 0x10;
                                                    (*(*esi + 0xa8))(edi, eax);
                                                    sub_465fa0();
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&arg_0, ebx);
                                                    if (*(int16_t *)word_4c7074 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_1C, 0x1);
                                                            esp = esp - 0x10;
                                                            (*(*esi + 0xac))(edi, eax);
                                                            sub_465fa0();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&arg_0, ebx);
                                                            if (*(int16_t *)word_4c70cc != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_1C, 0x1);
                                                                    esp = esp - 0x10;
                                                                    sub_45d210(edi, eax);
                                                                    sub_465fa0();
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    (*(*esi + 0xcc))(edi);
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    eax = sub_465fa0();
    *0x0 = var_8;
    return eax;
}
