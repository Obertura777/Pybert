// sub_4831d8 @ 0x4831d8
// hopper name: sub_4831d8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4831d8() {
    decomp_var_14 = esi;
    sub_47aea2(arg_4);
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_18 = sign_extend_32(*(int8_t *)esi);
    while (true) {
            esp = esp + 0x4;
            if (!CPU_FLAGS & NE) {
                    break;
            }
            esi = esi + 0x1;
            esp = esp - 0x4;
            decomp_var_18 = *(int8_t *)esi & 0xff;
            sub_47d09a(decomp_var_18);
    }
    esp = (esp - 0x4) + 0x4;
    if (sub_47c7c0(sign_extend_32(*(int8_t *)esi)) == 0x78) {
            esi = esi + 0x2;
    }
    ecx = var_10[0x2f];
    ecx = *ecx;
    eax = *(int8_t *)esi;
    *(int8_t *)esi = *(int8_t *)ecx;
    esi = esi + 0x1;
    do {
            ecx = *(int8_t *)esi;
            *(int8_t *)esi = eax;
            eax = ecx;
            ecx = *(int8_t *)esi;
            esi = esi + 0x1;
    } while (ecx != 0x0);
    if (var_4 != ecx) {
            eax = var_8;
            eax[0x1c] = eax[0x1c] & 0xfffffffd;
    }
    return eax;
}
