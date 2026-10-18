// InboundDAIDEDispatcher @ 0x45f1f0
// hopper name: sub_45f1f0
// pybert name: InboundDAIDEDispatcher
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

InboundDAIDEDispatcher() {
    var_C = *0x0;
    decomp_var_3c = esi;
    esp = esp - 0x40;
    decomp_var_40 = *dword_4c8db8 ^ &decomp_var_3c;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    ecx = arg_0;
    eax = arg_4;
    var_4 = 0x0;
    if (*(int16_t *)word_4c70bc == *(int16_t *)ecx) {
            esp = esp - 0x8;
            (*(*esi + 0x34))(ecx, eax);
            eax = sub_465fa0();
            *0x0 = var_4;
    }
    else {
            sub_465940(ecx, SAR(eax - (eax & 0x80000000 ? 0xffffffff : 0x0), 0x1), decomp_var_40);
            eax = sub_45fa10(0x1, &var_38);
            esp = (esp - 0x10) + 0x8 - 0x4;
            if (sub_466160(0x0) != 0x0) {
                    esp = esp - 0x8;
                    eax = sub_465900(&arg_4, 0x0);
                    eax = *(int16_t *)eax;
                    if (*(int16_t *)word_4c7080 == eax) {
                            esp = esp - 0x4;
                            eax = sub_45abf0(&var_38);
                            eax = sub_465fa0();
                            *0x0 = var_4;
                    }
                    else {
                            if (*(int16_t *)word_4c7094 == eax) {
                                    esp = esp - 0x4;
                                    eax = sub_45e310(&var_38);
                                    eax = sub_465fa0();
                                    *0x0 = var_4;
                            }
                            else {
                                    if (*(int16_t *)word_4c7098 == eax) {
                                            esp = esp - 0x4;
                                            eax = sub_45ad50(&var_38);
                                            eax = sub_465fa0();
                                            *0x0 = var_4;
                                    }
                                    else {
                                            if (*(int16_t *)word_4c70a8 == eax) {
                                                    esp = esp - 0x4;
                                                    eax = sub_45aeb0(&var_38);
                                                    eax = sub_465fa0();
                                                    *0x0 = var_4;
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c70b4 == eax) {
                                                            esp = esp - 0x4;
                                                            eax = sub_45aee0(&var_38);
                                                            eax = sub_465fa0();
                                                            *0x0 = var_4;
                                                    }
                                                    else {
                                                            if (*(int16_t *)word_4c70c4 == eax) {
                                                                    esp = esp - 0x4;
                                                                    eax = sub_45af10(&var_38);
                                                                    eax = sub_465fa0();
                                                                    *0x0 = var_4;
                                                            }
                                                            else {
                                                                    if (*(int16_t *)word_4c70a4 == eax) {
                                                                            esp = esp - 0x4;
                                                                            eax = sub_45eed0(&var_38);
                                                                    }
                                                                    else {
                                                                            if (*(int16_t *)word_4c70c0 == eax) {
                                                                                    esp = esp - 0x4;
                                                                                    eax = sub_45d600(&var_38);
                                                                            }
                                                                            else {
                                                                                    if (*(int16_t *)word_4c70e0 == eax) {
                                                                                            esp = esp - 0x4;
                                                                                            eax = sub_45db40(&var_38);
                                                                                    }
                                                                                    else {
                                                                                            if (*(int16_t *)word_4c7070 == eax) {
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_45e470();
                                                                                            }
                                                                                            else {
                                                                                                    if (*(int16_t *)word_4c7074 == eax) {
                                                                                                            *(int8_t *)(esi[0x2] + 0x2449) = 0x1;
                                                                                                            esp = esp - 0x4;
                                                                                                            eax = (*(*esi + 0x18))(&var_38);
                                                                                                    }
                                                                                                    else {
                                                                                                            if (*(int16_t *)word_4c7078 == eax) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    eax = (*(*esi + 0x1c))(&var_38);
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (*(int16_t *)word_4c7088 == eax) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            eax = (*(*esi + 0x20))(&var_38);
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (*(int16_t *)word_4c7090 == eax) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    eax = (*(*esi + 0x24))(&var_38);
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    if (*(int16_t *)word_4c709c == eax) {
                                                                                                                                            esp = esp - 0x4;
                                                                                                                                            eax = (*(*esi + 0x28))(&var_38);
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            if (*(int16_t *)word_4c70b0 == eax) {
                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                    eax = (*(*esi + 0x2c))(&var_38);
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (*(int16_t *)word_4c70b8 == eax) {
                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                            eax = sub_45d180(&var_38);
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (*(int16_t *)word_4c70c8 == eax) {
                                                                                                                                                                    *(int8_t *)(esi[0x2] + 0x2449) = 0x1;
                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                    eax = (*(*esi + 0xec))(&var_38);
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    ecx = &var_38;
                                                                                                                                                                    if (*(int16_t *)word_4c70e8 == eax) {
                                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                                            (*(*esi + 0x38))(ecx);
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            if (*(int16_t *)word_4c70d4 == eax) {
                                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                                    (*(*esi + 0x3c))(ecx);
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (*(int16_t *)word_4c70d8 == eax) {
                                                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                                                            (*(*esi + 0x40))(ecx);
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            if (*(int16_t *)word_4c70dc == eax) {
                                                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                                                    (*(*esi + 0x44))(ecx);
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    if (*(int16_t *)word_4c70e4 == eax) {
                                                                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                                                                            (*(*esi + 0x48))(ecx);
                                                                                                                                                                                                    }
                                                                                                                                                                                                    else {
                                                                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                                                                            eax = sub_46b050(&var_28, decomp_var_40, decomp_var_3c);
                                                                                                                                                                                                            var_4 = 0x1;
                                                                                                                                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                                                                                                                                    eax = eax[0x1];
                                                                                                                                                                                                            }
                                                                                                                                                                                                            else {
                                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            sub_45f930("Unexpected first token in message : %s", eax);
                                                                                                                                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                                                                                                                                            sub_45bb70();
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
                                                                            }
                                                                    }
                                                                    eax = sub_465fa0();
                                                                    *0x0 = var_4;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    sub_45f930("Illegal message received", decomp_var_40);
                    esp = (esp - 0x4) + 0x4;
                    eax = sub_465fa0();
                    *0x0 = var_4;
            }
    }
    return eax;
}
