// sub_484dd9 @ 0x484dd9
// hopper name: sub_484dd9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484dd9() {
    esp = esp - 0x8;
    asm { fst        qword [esp+0x8+var_8] };
    esp = esp + 0x8;
    eax = var_4 & 0x7ff00000;
    switch (eax) {
        case 0:
            asm { fld        qword [qword_value_4654470214887407616] };
            asm { fxch       st0, st1 };
            asm { fscale };
            asm { fstp       st1 };
            asm { fld        st0 };
            asm { fabs };
            asm { fcomp      qword [qword_value_4503599627370496] };
            asm { wait };
            asm { fnstsw     ax };
            asm { sahf };
            if (!asm { sahf }) {
                    asm { fmul       qword [qword_value_9218868437227405312+8] };
            }
            if (edx != 0x1d) {
                    eax = sub_484ca7(saved_fp, arg_0, arg_4, arg_8);
            }
            else {
                    eax = sub_484c90(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10);
            }
            break;
        case 2146435072:
            asm { fld        qword [qword_value_13877842251742183424] };
            asm { fxch       st0, st1 };
            asm { fscale };
            asm { fstp       st1 };
            asm { fld        st0 };
            asm { fabs };
            asm { fcomp      qword [qword_value_9218868437227405311] };
            asm { wait };
            asm { fnstsw     ax };
            asm { sahf };
            if (!asm { sahf }) {
                    asm { fmul       qword [qword_value_9218868437227405312] };
            }
            if (edx != 0x1d) {
                    eax = sub_484ca7(saved_fp, arg_0, arg_4, arg_8);
            }
            else {
                    eax = sub_484c90(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10);
            }
            break;
        default:
            eax = saved_fp;
            if (eax != 0x27f) {
                    eax = eax & 0x20;
                    if (eax == 0x0) {
                            asm { wait };
                            asm { fnstsw     ax };
                            eax = eax & 0x20;
                            if (eax != 0x0) {
                                    if (edx != 0x1d) {
                                            eax = sub_484ca7(saved_fp, arg_0, arg_4, arg_8);
                                    }
                                    else {
                                            eax = sub_484c90(saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10);
                                    }
                            }
                            else {
                                    asm { fldcw      word [esp+ret_addr] };
                            }
                    }
                    else {
                            asm { fldcw      word [esp+ret_addr] };
                    }
            }
            break;
    }
    return eax;
}
