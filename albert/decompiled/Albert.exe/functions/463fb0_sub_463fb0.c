// sub_463fb0 @ 0x463fb0
// hopper name: sub_463fb0
// contains unmarked entry 0x464100
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_463fb0() {
    var_8 = sub_4996e0;
    var_C = *0x0;
    decomp_var_78 = ebx;
    decomp_var_7c = ebp;
    decomp_var_80 = esi;
    decomp_var_84 = edi;
    esp = esp - 0x88;
    decomp_var_88 = *dword_4c8db8 ^ &decomp_var_84;
    *0x0 = &var_C;
    esi = ecx;
    var_70 = edi | 0xffffffff;
    sub_465870();
    sub_465870();
    sub_465870();
    if (esi[0x900] == (edi | 0xffffffff)) goto loc_464403;
    goto loc_464024;

loc_464403:
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = var_6C;
    *0x0 = var_8;
    return eax;

loc_464024:
    edi = arg_0;
    eax = sub_466060(&var_4C, 0x0);
    esp = esp - 0xc;
    sub_465ff0(eax);
    sub_465fa0();
    if (sub_4658e0() == 0x0) goto loc_464403;
    goto loc_464068;

loc_464068:
    esp = esp - 0x4;
    eax = sub_4658f0(&var_74);
    if (*(int16_t *)word_4c7778 == *(int16_t *)eax) goto loc_46408b;
    goto loc_464403;

loc_46408b:
    ebp = 0x0;
    eax = sub_466060(&var_4C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_465900(&var_74, 0x0);
    esp = esp - 0x1c;
    esi[0x1225] = *(int16_t *)eax;
    eax = sub_465900(&var_74, 0x1);
    eax = *(int16_t *)eax & 0xffff;
    bool_3 = (eax & 0x2000) == 0x0;
    eax = eax & 0xffff;
    if (!bool_3) {
            eax = eax | 0xffffe000;
    }
    esi[0x913] = eax;
    ebx = esi + 0x2450;
    sub_407b00(*(esi[0x915] + 0x4));
    eax = ebx[0x1];
    eax[0x1] = eax;
    eax = ebx[0x1];
    ebx[0x2] = ebp;
    *eax = eax;
    eax = ebx[0x1];
    eax[0x2] = eax;
    sub_407b00(*(esi[0x918] + 0x4));
    eax = *(esi + 0x2460);
    eax[0x1] = eax;
    eax = *(esi + 0x2460);
    *(esi + 0x2464) = ebp;
    *eax = eax;
    edi = *(esi + 0x2460);
    edi[0x2] = edi;
    sub_401950(*(esi[0x92e] + 0x4));
    eax = *(esi + 0x24b8);
    eax[0x1] = eax;
    eax = *(esi + 0x24b8);
    *(esi + 0x24bc) = ebp;
    *eax = eax;
    edi = *(esi + 0x24b8);
    edi[0x2] = edi;
    sub_401950(*(esi[0x931] + 0x4));
    eax = *(esi + 0x24c4);
    eax[0x1] = eax;
    eax = *(esi + 0x24c4);
    *(esi + 0x24c8) = ebp;
    *eax = eax;
    edi = *(esi + 0x24c4);
    edi[0x2] = edi;
    edi = esi + 0x24cc;
    decomp_var_8c = *(esi[0x934] + 0x4);
    sub_401950(decomp_var_8c);
    eax = edi[0x1];
    eax[0x1] = eax;
    eax = edi[0x1];
    edi[0x2] = ebp;
    *eax = eax;
    eax = edi[0x1];
    eax[0x2] = eax;
    esp = esp - 0x18;
    sub_40fb70(*(esi[0x91e] + 0x4));
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    esi[0x920] = 0x0;
    ebp = 0x2;
    if (sub_465930() > 0x2) {
            if (var_70 == 0xffffffff) {
                    eax = sub_466060(&var_4C, ebp);
                    sub_465ff0(eax);
                    sub_465fa0();
                    esp = esp - 0x20;
                    eax = sub_465f60(&var_1C);
                    eax = sub_462bc0(decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88);
                    var_70 = eax;
                    if (eax != 0xffffffff) {
                            esp = esp - 0x4;
                            var_70 = var_70 + sub_466110(ebp);
                    }
                    ebp = &ret_addr;
                    if (ebp < sub_465930()) {
                            continue;
                    }
                    break;
            }
            else {
                    break;
            }
    }
    if (*(int16_t *)word_4c773c == esi[0x1225]) {
            sub_40ab10(decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, var_74, var_70);
    }
    if (esi[0x1212] == 0x0) goto loc_464403;

loc_4642d4:
    esp = esp - 0x4;
    sub_401950(*(edi[0x1] + 0x4));
    eax = edi[0x1];
    eax[0x1] = eax;
    eax = edi[0x1];
    edi[0x2] = 0x0;
    *eax = eax;
    eax = edi[0x1];
    ebp = esi + 0x243c;
    eax[0x2] = eax;
    var_6C = ebp;
    var_68 = *arg_0;
    goto loc_464310;

loc_464310:
    eax = esi + 0x243c;
    var_60 = esi[0x910];
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (var_68 != var_60) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (var_68 == arg_0) {
                    sub_47a948();
            }
            eax = var_68[0x3];
            ecx = var_68 + 0xc;
            arg_0 = ecx;
            if (esi[0x1212] == *(int16_t *)(esi + (eax + eax * 0x8) * 0x4 + 0x20)) {
                    var_58 = ebx[0x1];
                    if (var_68 == arg_0) {
                            sub_47a948();
                            ecx = arg_0;
                    }
                    esp = esp - 0x8;
                    eax = sub_402060(&var_54, ecx, decomp_var_88, decomp_var_84, decomp_var_80);
                    ecx = *eax;
                    var_74 = eax;
                    if (ecx == 0x0 || ecx != ebx) {
                            sub_47a948();
                            eax = var_74;
                    }
                    if (eax[0x1] == var_58) {
                            if (var_68 == arg_0) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&var_4C, arg_0, decomp_var_88);
                    }
            }
            sub_401520();
            ebp = var_6C;
            continue;
    }
    break;
    esi[0x939] = esi[0x92f] - esi[0x938];
    goto loc_464403;
}
