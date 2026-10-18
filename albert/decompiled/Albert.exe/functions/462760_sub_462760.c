// sub_462760 @ 0x462760
// hopper name: sub_462760
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_462760() {
    var_C = *0x0;
    decomp_var_48 = ebx;
    decomp_var_4c = ebp;
    decomp_var_50 = esi;
    decomp_var_54 = edi;
    esp = esp - 0x58;
    decomp_var_58 = *dword_4c8db8 ^ &decomp_var_54;
    *0x0 = &var_C;
    var_40 = ecx;
    sub_465870();
    sub_465870();
    esi = ecx + 0xc;
    var_44 = 0x100;
    do {
            *(int8_t *)(esi - 0xa) = 0x0;
            *(int8_t *)(esi - 0x9) = 0x0;
            *(int8_t *)(esi - 0x8) = 0x0;
            esp = esp - 0x4;
            sub_461ed0(*(*esi + 0x4));
            eax = *esi;
            eax[0x1] = eax;
            eax = *esi;
            esi[0x1] = 0x0;
            *eax = eax;
            eax = *esi;
            eax[0x2] = eax;
            ebx = *(esi[0x3] + 0x4);
            edi = esi + 0x8;
            ebp = ebx;
            if (ebx[0x11] == 0x0) {
                    do {
                            sub_401950(arg_4);
                            ebp = *ebp;
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            ebx = ebp;
                    } while (arg_d == 0x0);
            }
            eax = edi[0x1];
            eax[0x1] = eax;
            eax = edi[0x1];
            edi[0x2] = 0x0;
            *eax = eax;
            edi = edi[0x1];
            esi = esi + 0x24;
            var_44 = var_44 - 0x1;
            edi[0x2] = edi;
    } while (var_44 != 0x0);
    ebx = arg_0;
    eax = sub_466060(&var_1C, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_1C, 0x1);
    sub_465ff0(eax);
    var_4 = 0x1;
    sub_465fa0();
    edi = var_40;
    esp = esp - 0x1c;
    eax = sub_461e20(&var_2C);
    esi = eax;
    if (esi != 0xffffffff) {
            esp = esp - 0x4;
            esi = esi + sub_466110(decomp_var_58);
            if (esi == 0xffffffff) {
                    edi[0x900] = 0xffffffff;
                    ebx = 0x0;
                    ebp = edi + 0x2;
                    do {
                            if (*(int8_t *)ebp == 0x0) {
                                    if (edi[0x900] == 0xffffffff) {
                                            edi[0x900] = ebx;
                                    }
                            }
                            else {
                                    if (edi[0x900] != 0xffffffff) {
                                            esp = esp - 0x4;
                                            esi = sub_466110(0x1) - 0x1;
                                    }
                            }
                            ebx = ebx + 0x1;
                            ebp = &arg_20;
                    } while (ebx < 0x100);
            }
            sub_465fa0();
            sub_465fa0();
            eax = esi;
            *0x0 = var_4;
    }
    else {
            esp = esp - 0x4;
            eax = sub_45fb80(&var_3C);
            esi = eax;
            if (esi != 0xffffffff) {
                    esp = esp - 0x4;
                    esi = esi + sub_466110(decomp_var_58);
                    if (esi == 0xffffffff) {
                            edi[0x900] = 0xffffffff;
                            ebx = 0x0;
                            ebp = edi + 0x2;
                            do {
                                    if (*(int8_t *)ebp == 0x0) {
                                            if (edi[0x900] == 0xffffffff) {
                                                    edi[0x900] = ebx;
                                            }
                                    }
                                    else {
                                            if (edi[0x900] != 0xffffffff) {
                                                    esp = esp - 0x4;
                                                    esi = sub_466110(0x1) - 0x1;
                                            }
                                    }
                                    ebx = ebx + 0x1;
                                    ebp = &arg_20;
                            } while (ebx < 0x100);
                    }
                    sub_465fa0();
                    sub_465fa0();
                    eax = esi;
                    *0x0 = var_4;
            }
            else {
                    edi[0x900] = 0xffffffff;
                    ebx = 0x0;
                    ebp = edi + 0x2;
                    do {
                            if (*(int8_t *)ebp == 0x0) {
                                    if (edi[0x900] == 0xffffffff) {
                                            edi[0x900] = ebx;
                                    }
                            }
                            else {
                                    if (edi[0x900] != 0xffffffff) {
                                            esp = esp - 0x4;
                                            esi = sub_466110(0x1) - 0x1;
                                    }
                            }
                            ebx = ebx + 0x1;
                            ebp = &arg_20;
                    } while (ebx < 0x100);
                    sub_465fa0();
                    sub_465fa0();
                    eax = esi;
                    *0x0 = var_4;
            }
    }
    return eax;
}
