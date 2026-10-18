// sub_48d716 @ 0x48d716
// hopper name: sub_48d716
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48d716() {
    decomp_var_4 = eax;
    decomp_var_8 = ebx;
    esp = esp - 0xc;
    decomp_var_c = ecx;
    eax = arg_6 ^ 0x700;
    if ((eax & 0x700) == 0x0) {
            if (*(int8_t *)((eax >> 0xb & 0xf) + 0x4c9e0c) != 0x0) {
                    if ((arg_6 & 0x7fff0000) != 0x7fff0000) {
                            eax = arg_1E & 0x7fff0000;
                            switch (eax) {
                                case 0:
                                    asm { fld        tword [esp+0xc+arg_0] };
                                    asm { fld        tword [esp+0xc+arg_18] };
                                    asm { fprem };
                                    break;
                                case 2147418112:
                                    asm { fld        tword [esp+0xc+arg_0] };
                                    asm { fld        tword [esp+0xc+arg_18] };
                                    asm { fprem };
                                    break;
                                default:
                                    if (arg_1c + arg_1c == 0x0) {
                                            if (arg_4 + arg_4 == 0x0) {
                                                    if ((arg_20 & 0x7fff) <= (arg_8 & 0x7fff) + 0x3f) {
                                                            while ((arg_20 & 0x7fff) >= (arg_8 & 0x7fff) + 0xa) {
                                                                    asm { fld        tword [esp+0xc+arg_18] };
                                                                    eax = arg_8;
                                                                    asm { fld        tword [esp+0xc+arg_0] };
                                                                    arg_8 = eax;
                                                                    asm { fxch       st0, st1 };
                                                                    asm { fprem };
                                                                    asm { fstp       tword [esp+0xc+arg_18] };
                                                                    asm { fstp       st0 };
                                                            }
                                                            asm { fld        tword [esp+0xc+arg_0] };
                                                            asm { fld        tword [esp+0xc+arg_18] };
                                                            asm { fprem };
                                                    }
                                                    else {
                                                            if ((edx & 0x2) == 0x0) {
                                                                    asm { fld        tword [esp+0xc+arg_0] };
                                                                    asm { fstp       tword [esp+0xc+arg_C] };
                                                            }
                                                            asm { fnstcw     word [esp+0xc+arg_24] };
                                                            asm { fldcw      word [esp+0xc+arg_28] };
                                                            ecx = ((arg_20 & 0x7fff) - (arg_8 & 0x7fff) & 0x3f | 0x20) + 0x1;
                                                            eax = arg_8 & 0x8000;
                                                            asm { fld        tword [esp+0xc+arg_0] };
                                                            asm { fabs };
                                                            asm { fld        tword [esp+0xc+arg_18] };
                                                            asm { fabs };
                                                            do {
                                                                    asm { fcom       st1 };
                                                                    asm { fnstsw     ax };
                                                                    eax = eax & 0x100;
                                                                    if (eax == 0x0) {
                                                                            asm { fsub       st1 };
                                                                    }
                                                                    asm { fxch       st0, st1 };
                                                                    asm { fmul       qword [qword_4c9e3c] };
                                                                    asm { fxch       st0, st1 };
                                                                    ecx = ecx - 0x1;
                                                            } while (ecx != 0x0);
                                                            ebx = arg_20;
                                                            asm { fstp       tword [esp+0xc+arg_18] };
                                                            asm { fstp       st0 };
                                                            asm { fld        tword [esp+0xc+arg_C] };
                                                            asm { fld        tword [qword_4c9e3c+8] };
                                                            asm { fprem };
                                                            asm { fstp       st0 };
                                                            asm { fld        tword [esp+0xc+arg_18] };
                                                            asm { fldcw      word [esp+0xc+arg_24] };
                                                            if ((ebx & 0x8000) != 0x0) {
                                                                    asm { fchs };
                                                            }
                                                    }
                                            }
                                            else {
                                                    asm { fld        tword [esp+0xc+arg_0] };
                                                    asm { fld        tword [esp+0xc+arg_18] };
                                                    asm { fprem };
                                            }
                                    }
                                    else {
                                            asm { fld        tword [esp+0xc+arg_0] };
                                            asm { fld        tword [esp+0xc+arg_18] };
                                            asm { fprem };
                                    }
                                    break;
                            }
                    }
                    else {
                            asm { fld        tword [esp+0xc+arg_0] };
                            asm { fld        tword [esp+0xc+arg_18] };
                            asm { fprem };
                    }
            }
            else {
                    asm { fld        tword [esp+0xc+arg_0] };
                    asm { fld        tword [esp+0xc+arg_18] };
                    asm { fprem };
            }
    }
    else {
            asm { fld        tword [esp+0xc+arg_0] };
            asm { fld        tword [esp+0xc+arg_18] };
            asm { fprem };
    }
    if ((edx & 0x3) != 0x0) {
            asm { fnstsw     word [esp+0xc+arg_2C] };
            if ((edx & 0x1) != 0x0) {
                    asm { fnstcw     word [esp+0xc+arg_24] };
                    asm { fldcw      word [esp+0xc+arg_28] };
                    asm { fmul       qword [qword_4c9e2c] };
                    asm { fldcw      word [esp+0xc+arg_24] };
            }
            eax = arg_2c;
            asm { fxch       st0, st1 };
            asm { fstp       st0 };
            asm { fld        tword [esp+0xc+arg_C] };
            asm { fxch       st0, st1 };
            asm { fnstenv    esp+0x28+var_28 };
            asm { fldenv     esp+0x28+var_28 };
            eax = decomp_var_4;
    }
    else {
            eax = (null)();
    }
    return eax;
}
