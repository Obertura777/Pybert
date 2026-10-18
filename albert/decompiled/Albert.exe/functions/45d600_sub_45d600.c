// sub_45d600 @ 0x45d600
// hopper name: sub_45d600
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d600() {
    var_8 = sub_498b80;
    var_C = *0x0;
    decomp_var_30 = ebx;
    decomp_var_34 = esi;
    decomp_var_38 = edi;
    *0x0 = &var_C;
    esi = ecx;
    edi = arg_0;
    eax = sub_466060(&var_2C, 0x1);
    esp = esp - 0x4c;
    eax = sub_465900(&arg_0, 0x0);
    if (*(int16_t *)word_4c70a0 != *(int16_t *)eax) {
            eax = sub_466060(&var_1C, 0x1);
            esp = esp - 0x10;
            (*(*esi + 0x54))(edi, eax);
            sub_465fa0();
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&arg_0, 0x0);
            if (*(int16_t *)word_4c708c != *(int16_t *)eax) {
                    eax = sub_466060(&var_1C, 0x1);
                    esp = esp - 0x10;
                    (*(*esi + 0x5c))(edi, eax);
                    sub_465fa0();
            }
            else {
                    ebx = 0x0;
                    esp = esp - 0x8;
                    eax = sub_465900(&arg_0, 0x0);
                    if (*(int16_t *)word_4c7080 != *(int16_t *)eax) {
                            eax = sub_466060(&var_1C, 0x1);
                            esp = esp - 0x10;
                            (*(*esi + 0x60))(edi, eax);
                            sub_465fa0();
                    }
                    else {
                            esp = esp - 0x8;
                            eax = sub_465900(&arg_0, ebx);
                            if (*(int16_t *)word_4c70a8 != *(int16_t *)eax) {
                                    eax = sub_466060(&var_1C, 0x1);
                                    esp = esp - 0x10;
                                    (*(*esi + 0x64))(edi, eax);
                                    sub_465fa0();
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&arg_0, ebx);
                                    if (*(int16_t *)word_4c70c4 != *(int16_t *)eax) {
                                            eax = sub_466060(&var_1C, 0x1);
                                            esp = esp - 0x10;
                                            (*(*esi + 0x68))(edi, eax);
                                            sub_465fa0();
                                    }
                                    else {
                                            esp = esp - 0x8;
                                            eax = sub_465900(&arg_0, ebx);
                                            if (*(int16_t *)word_4c7084 != *(int16_t *)eax) {
                                                    eax = sub_466060(&var_1C, 0x1);
                                                    esp = esp - 0x10;
                                                    (*(*esi + 0x6c))(edi, eax);
                                                    sub_465fa0();
                                            }
                                            else {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&arg_0, ebx);
                                                    if (*(int16_t *)word_4c70d0 != *(int16_t *)eax) {
                                                            eax = sub_466060(&var_1C, 0x1);
                                                            esp = esp - 0x10;
                                                            (*(*esi + 0x70))(edi, eax);
                                                            sub_465fa0();
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&arg_0, ebx);
                                                            if (*(int16_t *)word_4c70a4 != *(int16_t *)eax) {
                                                                    eax = sub_466060(&var_1C, 0x1);
                                                                    esp = esp - 0x10;
                                                                    sub_45af40(edi, eax);
                                                                    sub_465fa0();
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&arg_0, ebx);
                                                                    if (*(int16_t *)word_4c707c != *(int16_t *)eax) {
                                                                            eax = sub_466060(&var_1C, 0x1);
                                                                            esp = esp - 0x10;
                                                                            (*(*esi + 0x74))(edi, eax);
                                                                            sub_465fa0();
                                                                    }
                                                                    else {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&arg_0, ebx);
                                                                            if (*(int16_t *)word_4c70b4 != *(int16_t *)eax) {
                                                                                    eax = sub_466060(&var_1C, 0x1);
                                                                                    esp = esp - 0x10;
                                                                                    (*(*esi + 0x78))(edi, eax);
                                                                                    sub_465fa0();
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x8;
                                                                                    eax = sub_465900(&arg_0, ebx);
                                                                                    if (*(int16_t *)word_4c70dc != *(int16_t *)eax) {
                                                                                            eax = sub_466060(&var_1C, 0x1);
                                                                                            esp = esp - 0x10;
                                                                                            (*(*esi + 0x7c))(edi, eax);
                                                                                            sub_465fa0();
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x8;
                                                                                            eax = sub_465900(&arg_0, ebx);
                                                                                            if (*(int16_t *)word_4c7074 != *(int16_t *)eax) {
                                                                                                    eax = sub_466060(&var_1C, 0x1);
                                                                                                    esp = esp - 0x10;
                                                                                                    (*(*esi + 0x80))(edi, eax);
                                                                                                    sub_465fa0();
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x8;
                                                                                                    eax = sub_465900(&arg_0, ebx);
                                                                                                    if (*(int16_t *)word_4c70cc != *(int16_t *)eax) {
                                                                                                            eax = sub_466060(&var_1C, 0x1);
                                                                                                            esp = esp - 0x10;
                                                                                                            sub_45d2c0(edi, eax);
                                                                                                            sub_465fa0();
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x8;
                                                                                                            eax = sub_465900(&arg_0, ebx);
                                                                                                            if (*(int16_t *)word_4c70e4 != *(int16_t *)eax) {
                                                                                                                    eax = sub_466060(&var_1C, 0x1);
                                                                                                                    esp = esp - 0x10;
                                                                                                                    (*(*esi + 0x88))(edi, eax);
                                                                                                                    sub_465fa0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x8;
                                                                                                                    eax = sub_465900(&arg_0, ebx);
                                                                                                                    if (*(int16_t *)word_4c709c != *(int16_t *)eax) {
                                                                                                                            eax = sub_466060(&var_1C, 0x1);
                                                                                                                            esp = esp - 0x10;
                                                                                                                            (*(*esi + 0x8c))(edi, eax);
                                                                                                                            sub_465fa0();
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            (*(*esi + 0xc4))(edi);
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
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
