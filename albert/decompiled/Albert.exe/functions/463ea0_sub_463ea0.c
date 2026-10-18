// sub_463ea0 @ 0x463ea0
// hopper name: sub_463ea0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_463ea0() {
    var_8 = sub_499690;
    var_C = *0x0;
    decomp_var_34 = ebx;
    decomp_var_38 = ebp;
    decomp_var_3c = esi;
    decomp_var_40 = edi;
    var_44 = *dword_4c8db8 ^ &decomp_var_40;
    *0x0 = &var_C;
    var_30 = ecx;
    esi = esi | 0xffffffff;
    sub_465870();
    edi = arg_0;
    esp = esp - 0x4c;
    eax = sub_465900(&arg_0, 0x0);
    eax = *(int8_t *)eax & 0xff;
    ebx = ecx + (eax + eax * 0x8) * 0x4;
    if (*(int8_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x2) != 0x0 && ebx[0x4] == 0x0) {
            ebp = 0x1;
            if (sub_465930() > 0x1) {
                    &var_44 = &var_44;
                    while (true) {
                            if (esi != 0xffffffff) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            eax = sub_466060(&var_1C, ebp);
                            sub_465ff0(eax);
                            sub_465fa0();
                            esp = esp - 0x14;
                            eax = sub_4629e0(ebx, &var_2C, var_44, decomp_var_40);
                            esi = eax;
                            if (esi != 0xffffffff) {
                                    esp = esp - 0x4;
                                    esi = esi + sub_466110(ebp);
                            }
                            ebp = &ret_addr;
                            if (ebp < sub_465930()) {
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            esi = 0x0;
    }
    sub_465fa0();
    eax = esi;
    *0x0 = var_8;
    return eax;
}
