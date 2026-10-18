// sub_45fac0 @ 0x45fac0
// hopper name: sub_45fac0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45fac0() {
    decomp_var_110 = ebx;
    decomp_var_114 = ebp;
    ebp = arg_0;
    decomp_var_118 = esi;
    esp = esp - 0x11c;
    decomp_var_11c = edi;
    edi = ecx;
    var_10C = 0xffffffff;
    eax = sub_4658d0();
    ebx = eax;
    edi[0x901] = ebx;
    if (ebx > 0x0) {
            sub_47ba40(&var_104, 0x0, eax);
            esp = (esp - 0xc) + 0xc;
    }
    esi = 0x0;
    if (ebx > 0x0) {
            ebx = var_10C;
            if (ebx == 0xffffffff) {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_106, esi);
                    eax = *(int8_t *)eax & 0xff;
                    if (eax < edi[0x901]) {
                            bool_2 = *(int8_t *)(&decomp_var_11c + eax + 0x18) != 0x0;
                            eax = &decomp_var_11c + eax + 0x18;
                            if (!bool_2) {
                                    *(int8_t *)eax = 0x1;
                            }
                            else {
                                    var_10C = esi;
                                    ebx = esi;
                            }
                    }
                    else {
                            var_10C = esi;
                            ebx = esi;
                    }
                    esi = esi + 0x1;
                    if (esi < edi[0x901]) {
                            continue;
                    }
                    break;
            }
            else {
                    break;
            }
    }
    eax = sub_47ad69();
    return eax;
}
