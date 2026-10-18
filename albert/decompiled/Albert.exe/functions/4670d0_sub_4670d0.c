// sub_4670d0 @ 0x4670d0
// hopper name: sub_4670d0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4670d0() {
    decomp_var_8 = ebp;
    ebp = arg_4;
    decomp_var_c = esi;
    esi = 0x0;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = ecx;
    var_4 = 0x0;
    if (ebp > 0x0) {
            esp = esp - 0x4;
            var_14 = ebx;
            ebx = arg_0;
            &var_14 = &var_14;
            while (true) {
                    eax = sub_465e30();
                    if (eax > 0x0) {
                            esi = eax;
                            if (ebp < eax) {
                                    esi = ebp;
                            }
                            sub_47a5af(*edi[0x9], eax, ebx, esi);
                            eax = edi[0xd];
                            *eax = *eax - esi;
                            var_4 = var_4 + esi;
                            eax = edi[0x9];
                            ebx = ebx + esi;
                            ebp = ebp - esi;
                            esp = (esp - 0x10) + 0x10;
                            *eax = *eax + esi;
                            esi = var_4;
                            if (ebp > 0x0) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            esp = esp - 0x4;
                            if ((*(*edi + 0x4))(*(int8_t *)ebx & 0xff) != 0xffffffff) {
                                    esi = esi + 0x1;
                                    ebx = ebx + 0x1;
                                    var_4 = esi;
                                    ebp = &var_4;
                                    if (ebp > 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    break;
                            }
                    }
            }
            eax = esi;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
