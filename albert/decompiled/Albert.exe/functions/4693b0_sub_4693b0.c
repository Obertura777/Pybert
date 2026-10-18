// sub_4693b0 @ 0x4693b0
// hopper name: sub_4693b0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4693b0() {
    var_8 = sub_49a3e0;
    var_C = *0x0;
    esp = esp - 0x70;
    *0x0 = &var_C;
    ebx = arg_10;
    edi = arg_0;
    esi = ecx;
    var_58 = edi;
    if ((ebx[0x4] & 0x4000) == 0x0) {
            edx = *esi;
            edx = edx[0x7];
            decomp_var_88 = arg_4;
            esp = esp - 0x1c;
            (edx)(edi);
    }
    else {
            eax = sub_465800(&var_5C);
            esp = (esp - 0x8) + 0x4;
            ebp = sub_469210(eax);
            sub_465790();
            var_28 = 0x0;
            if (arg_18 != 0x0) {
                    eax = sub_468aa0(&var_54);
                    decomp_var_74 = 0xffffffff;
                    esp = esp - 0x10;
                    sub_4024f0(eax, 0x0, 0xffffffff);
                    if (var_48 >= 0x10) {
                            esp = esp - 0x4;
                            sub_47c8f9();
                            esp = esp + 0x4;
                    }
            }
            else {
                    eax = sub_468a80(&var_54);
                    decomp_var_74 = 0xffffffff;
                    esp = esp - 0x10;
                    sub_4024f0(eax, 0x0, 0xffffffff);
                    if (var_48 >= 0x10) {
                            esp = esp - 0x4;
                            sub_47c8f9();
                            esp = esp + 0x4;
                    }
            }
            edi = 0x0;
            eax = ebx[0x6];
            ecx = var_8;
            if (eax > 0x0 && eax > ecx) {
                    edi = eax - ecx;
            }
            edx = arg_18;
            if ((ebx[0x4] & 0x1c0) != 0x40) {
                    decomp_var_74 = arg_14;
                    eax = sub_468930(esi, &var_28, decomp_var_74, edx, arg_1c, arg_24, edi);
                    ebp = *eax;
                    edx = eax[0x1];
                    ecx = eax[0x2];
                    esp = (esp - 0x1c) + 0x1c;
                    edi = 0x0;
            }
            else {
                    ecx = arg_1c;
                    ebp = arg_14;
            }
            eax = arg_0;
            if (arg_14 < 0x10) {
                    eax = &arg_0;
            }
            var_58 = ebp;
            eax = sub_4688b0(esi, &var_C, var_58, edx, ecx, eax, arg_10);
            edx = *eax;
            ebp = eax[0x1];
            eax = eax[0x2];
            var_48 = edi;
            edi = var_2C;
            decomp_var_4c = arg_40;
            var_58 = edx;
            var_54 = ebp;
            ebx[0x6] = 0x0;
            var_50 = eax;
            sub_468930(esi, edi, var_58, var_54, var_50, decomp_var_4c, var_48);
            esp = ((esp - 0x1c) + 0x1c - 0x1c) + 0x1c;
            if (arg_14 >= 0x10) {
                    var_48 = arg_0;
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    *0x0 = arg_c;
    eax = sub_47ad69();
    return eax;
}
